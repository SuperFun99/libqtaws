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


#include "s3putobjectresponse.h"
#include "s3putobjectresponse_p.h"

#include <QDebug>
#include <QByteArray>
#include <QNetworkReply>
#include <QXmlStreamReader>

QTAWS_BEGIN_NAMESPACE




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
S3PutObjectResponse::S3PutObjectResponse(const S3PutObjectRequest & request, QNetworkReply * const reply, QObject * const parent)
    : S3Response(new S3PutObjectResponsePrivate(this), parent)
{
    setRequest(new S3PutObjectRequest(request));
    setReply(reply);
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const S3PutObjectRequest * S3PutObjectResponse::request() const
{
    Q_D(const S3PutObjectResponse);
    return static_cast<const S3PutObjectRequest *>(d->request);
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void S3PutObjectResponse::parseSuccess(QIODevice & response)
{
    QNetworkReply * pReply = qobject_cast<QNetworkReply *>(&response);
    Q_ASSERT(pReply);
    QLatin1String result(pReply->readAll());
    qDebug() << "Response\n====================\n" << result << "\n====================\n";
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
S3PutObjectResponsePrivate::S3PutObjectResponsePrivate(S3PutObjectResponse * const q)
    : S3ResponsePrivate(q)
{

}

QTAWS_END_NAMESPACE
