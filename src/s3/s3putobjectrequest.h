// S3PutObjectRequest.h
// By Mike Kuta
// Thursday, August 20, 2015
//
// Class for putting objects to Amazon S3.
//
// Extension of libqtaws.  libqtaws is licensed under the GNU Lesser General Public License.
//
// https://github.com/pcolby/libqtaws
//
// Copyright © 2015 Kuta Software LLC.  All rights reserved.


#ifndef S3PUTOBJECTREQUEST_H
#define S3PUTOBJECTREQUEST_H

#include "s3objectrequest.h"
#include "s3cannedacl.h"
#include "s3storageclass.h"

class QNetworkRequest;
class QFile;

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
