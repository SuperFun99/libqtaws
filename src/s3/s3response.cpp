/*
    Copyright 2015 Mike Kuta

    This file is part of libqtaws.

    Libqtaws is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Libqtaws is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with libqtaws.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "s3response.h"
#include "s3response_p.h"

#include <QDebug>
#include <QXmlStreamReader>

QTAWS_BEGIN_NAMESPACE



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
S3Response::S3Response(QObject * const parent)
    : AwsAbstractResponse(new S3ResponsePrivate(this), parent)
{

}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
S3Response::S3Response(S3ResponsePrivate * const d, QObject * const parent)
    : AwsAbstractResponse(d, parent)
{

}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QString S3Response::errorString() const
{
    // Handle errors in a basic way.
    // To do: Create S3Error class and then add S3ErrorList to private part of this class.

    if (!errorCode().isEmpty())
    {
        return QString::fromLatin1("%1 - %2").arg(errorCode()).arg(message());
    }
    else
    {
        return AwsAbstractResponse::errorString();
    }
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool S3Response::hasError() const
{
    // true if request did not reach Amazon or we were unable to interpret the response.
    return ((networkError() != QNetworkReply::NoError) || (xmlParseError() != QXmlStreamReader::NoError));
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool S3Response::isValid() const
{
    // true if there were no network and we were able to interpret the response
    return ((networkError() == QNetworkReply::NoError) && (xmlParseError() == QXmlStreamReader::NoError));
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QNetworkReply::NetworkError S3Response::networkError() const
{
    // S3 Responses can be valid without returning HTTP code 200.  Examples:
    //
    // InvalidBucketState   The request is not valid with the current state of the bucket.   409 Conflict
    // InvalidDigest        The Content-MD5 you specified is not valid.                      400 Bad Request
    //
    // As long as the response is from Amazon this function will return QNetworkReply::NoError.

    Q_D(const AwsAbstractResponse);

    if ((!d->reply) ||
        (d->reply->header(QNetworkRequest::ServerHeader) == QLatin1String("AmazonS3")) ||
        (d->reply->hasRawHeader("x-amz-request-id")))
    {
        return QNetworkReply::NoError;
    }

    return d->reply->error();
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void S3Response::parse(QNetworkReply * const reply)
{
    // DEBUGGING
    // Dump reply headers
    QList<QByteArray> headers = reply->rawHeaderList();
    qDebug() <<  "========= Reply Headers ========\n";
    foreach (QByteArray header, headers)
    {
        qDebug() << QString::fromLatin1("%1: %2\n").arg(QString::fromLatin1(header)).arg(QString::fromLatin1(reply->rawHeader(header)));
    }

    // Dump the reply body
    qDebug() <<  "========= Reply Body ========\n";
    qDebug() << reply->readAll().constData();
    qDebug() << "\n";



    // Extract common response values from headers
    Q_D(S3Response);
    d->amzId2    = QString::fromLatin1(reply->rawHeader("x-amz-id-2"));
    d->requestId = QString::fromLatin1(reply->rawHeader("x-amz-request-id"));


    // Parse the body
    if (isSuccess(reply))
        parseSuccess(*reply);
    else
        parseFailure(*reply);
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QString S3Response::errorCode() const
{
    Q_D(const S3Response);
    return d->xmlValues.value(QLatin1String("Code")).toString();
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QString S3Response::message() const
{
    Q_D(const S3Response);
    return d->xmlValues.value(QLatin1String("Message")).toString();
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QString S3Response::requestId() const
{
    Q_D(const S3Response);
    return d->requestId;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QString S3Response::amzId2() const
{
    Q_D(const S3Response);
    return d->amzId2;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QNetworkReply * S3Response::networkReply() const
{
    Q_D(const S3Response);
    return d->reply;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// <?xml version="1.0" encoding="UTF-8"?>
/// <Error>
///   <Code>NoSuchKey</Code>
///   <Message>The resource you requested does not exist</Message>
///   <Resource>/mybucket/myfoto.jpg</Resource>
///   <RequestId>4442587FB7D0A2F9</RequestId>
/// </Error>
void S3Response::parseFailure(QIODevice & response)
{
    Q_D(S3Response);
    QXmlStreamReader xml(&response);
    if (xml.readNextStartElement())
    {
        if (xml.name() == QLatin1String("Error"))
        {
            d->parseErrorResponse(xml);
        }
        else
        {
            qWarning() << "ignoring" << xml.name();
            xml.skipCurrentElement();
        }
    }

    setXmlError(xml);
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void S3Response::parseSuccess(QIODevice & /*response*/)
{

}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
S3ResponsePrivate::S3ResponsePrivate(S3Response * const q)
    : AwsAbstractResponsePrivate(q)
{

}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// <?xml version="1.0" encoding="UTF-8"?>
/// <Error>
///   <Code>NoSuchKey</Code>
///   <Message>The resource you requested does not exist</Message>
///   <Resource>/mybucket/myfoto.jpg</Resource>
///   <RequestId>4442587FB7D0A2F9</RequestId>
/// </Error>
///
void S3ResponsePrivate::parseErrorResponse(QXmlStreamReader & xml)
{
    Q_ASSERT(xml.name() == QLatin1String("Error"));
    while (xml.readNextStartElement())
    {
        // Add element and value to map
        xmlValues.insert(xml.name().toString(), xml.readElementText());
    }
}


QTAWS_END_NAMESPACE
