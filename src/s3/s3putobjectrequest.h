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


#ifndef S3PUTOBJECTREQUEST_H
#define S3PUTOBJECTREQUEST_H

#include "s3objectrequest.h"
#include "s3cannedacl.h"
#include "s3storageclass.h"

QTAWS_BEGIN_NAMESPACE

class S3PutObjectRequestPrivate;

class QTAWS_EXPORT S3PutObjectRequest : public S3ObjectRequest
{
public:
    S3PutObjectRequest(const QString & bucketName, const QString & fileName, const QString & s3ObjectName);
    S3PutObjectRequest(const S3PutObjectRequest & other);
    S3PutObjectRequest();

    S3CannedACL cannedACL() const;
    S3StorageClass storageClass() const;

    void setCannedACL(const S3CannedACL & cannedACL);
    bool setStorageClass(const S3StorageClass & storageClass);

    bool isValidStorageClass() const;
    static bool isValidStorageClass(const S3StorageClass & storageClass);

protected:
    virtual QNetworkRequest unsignedRequest(const QUrl & endpoint) const;
    virtual AwsAbstractResponse * response(QNetworkReply * const reply) const;

private:
    Q_DECLARE_PRIVATE(S3PutObjectRequest)
};

QTAWS_END_NAMESPACE

#endif // S3PUTOBJECTREQUEST_H
