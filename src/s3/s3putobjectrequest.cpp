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


#include "s3putobjectrequest.h"
#include "s3putobjectrequest_p.h"
#include "s3putobjectresponse.h"

#include <QFile>
#include <QDebug>
#include <QMimeDatabase>

QTAWS_BEGIN_NAMESPACE




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
S3PutObjectRequest::S3PutObjectRequest(const QString & bucketName, const QString & fileName, const QString & s3ObjectName)
    : S3ObjectRequest(new S3PutObjectRequestPrivate(bucketName, s3ObjectName, this))
{
    setOperation(QNetworkAccessManager::PutOperation);

    QMimeDatabase mimeDatabase;
    QString mimeType = mimeDatabase.mimeTypeForFile(fileName).name();
    setMimeType(mimeType);

    QFile file(fileName);
    bool ret = file.open(QIODevice::ReadOnly);
    if (ret)
    {
        setData(file.readAll());
    }
    else
    {
        qWarning() << "S3PutObjectRequest() : Unable to open file " << fileName;
    }
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
S3PutObjectRequest::S3PutObjectRequest(const S3PutObjectRequest & other)
    : S3ObjectRequest(new S3PutObjectRequestPrivate(*other.d_func(), this))
{

}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
S3PutObjectRequest::S3PutObjectRequest()
    : S3ObjectRequest(new S3PutObjectRequestPrivate(QLatin1String(""), QLatin1String(""), this))
{

}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
S3CannedACL S3PutObjectRequest::cannedACL() const
{
    Q_D(const S3PutObjectRequest);
    return d->cannedACL;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
S3StorageClass S3PutObjectRequest::storageClass() const
{
    Q_D(const S3PutObjectRequest);
    return d->storageClass;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void S3PutObjectRequest::setCannedACL(const S3CannedACL & cannedACL)
{
    Q_D(S3PutObjectRequest);
    d->cannedACL = cannedACL;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool S3PutObjectRequest::setStorageClass(const S3StorageClass & storageClass)
{
    if (isValidStorageClass())
    {
        Q_D(S3PutObjectRequest);
        d->storageClass = storageClass;
        return true;
    }

    return false;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool S3PutObjectRequest::isValidStorageClass(const S3StorageClass & storageClass)
{
    // Only Standard and Reduced Redundancy are valid for PUT requests.
    return ((storageClass == S3StorageClass::Standard) || (storageClass == S3StorageClass::ReducedRedundancy));
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool S3PutObjectRequest::isValidStorageClass() const
{
    Q_D(const S3PutObjectRequest);
    return isValidStorageClass(d->storageClass);
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QNetworkRequest S3PutObjectRequest::unsignedRequest(const QUrl & endpoint) const
{
    // Base classes set the host name and path
    QNetworkRequest req = S3ObjectRequest::unsignedRequest(endpoint);

    // Set the MD5 hash of the contents
    QByteArray md5 = QCryptographicHash::hash(data(), QCryptographicHash::Md5);
    req.setRawHeader("Content-MD5", md5.toBase64());

    // Set the SHA-256 hash of the contents
    QByteArray sha256 = QCryptographicHash::hash(data(), QCryptographicHash::Sha256);
    req.setRawHeader("x-amz-content-sha256", sha256.toHex());

    // Set the content-type
    req.setHeader(QNetworkRequest::ContentTypeHeader, mimeType());

    // Set the content-length
    req.setHeader(QNetworkRequest::ContentLengthHeader, data().length());

    // Possibly set the canned ACL
    Q_D(const S3PutObjectRequest);
    if ((!d->cannedACL.isDefault()) && (d->cannedACL.isValidForObjects()))
        req.setRawHeader("x-amz-acl", d->cannedACL.toString().toLatin1());

    // Possibly set the storage class
    if (isValidStorageClass())
        req.setRawHeader("x-amz-storage-class", d->storageClass.toString().toLatin1());

    return req;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
AwsAbstractResponse * S3PutObjectRequest::response(QNetworkReply * const reply) const
{
    return new S3PutObjectResponse(*this, reply);
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
S3PutObjectRequestPrivate::S3PutObjectRequestPrivate(const QString & bucketName, const QString & s3ObjectName, S3PutObjectRequest * const q)
    : S3ObjectRequestPrivate(S3Request::PutObjectAction, bucketName, s3ObjectName, q)
{

}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
S3PutObjectRequestPrivate::S3PutObjectRequestPrivate(const S3PutObjectRequestPrivate & other, S3PutObjectRequest * const q)
    : S3ObjectRequestPrivate(other, q)
    , cannedACL(other.cannedACL)
    , storageClass(other.storageClass)
{

}


QTAWS_END_NAMESPACE
