// S3PutObjectRequest_p.h
// By Mike Kuta
// Thursday, August 20, 2015
//
// Class private parts of S3PutObjectRequest.
//
// Extension of libqtaws.  libqtaws is licensed under the GNU Lesser General Public License.
//
// https://github.com/pcolby/libqtaws
//
// Copyright © 2015 Kuta Software LLC.  All rights reserved.


#ifndef S3PUTOBJECTREQUEST_P_H
#define S3PUTOBJECTREQUEST_P_H

#include "s3putobjectrequest.h"
#include "s3objectrequest_p.h"

QTAWS_BEGIN_NAMESPACE

class S3PutObjectRequest;

class QTAWS_EXPORT S3PutObjectRequestPrivate : public S3ObjectRequestPrivate
{
public:
    S3CannedACL cannedACL;         ///< The canned ACL to apply to the object.
    S3StorageClass storageClass;   ///< The Amazon S3 storage class of the object.

    S3PutObjectRequestPrivate(const QString & bucketName, const QString & s3ObjectName, S3PutObjectRequest * const q);
    S3PutObjectRequestPrivate(const S3PutObjectRequestPrivate & other, S3PutObjectRequest * const q);

private:
    Q_DECLARE_PUBLIC(S3PutObjectRequest)
};

QTAWS_END_NAMESPACE

#endif // S3PUTOBJECTREQUEST_P_H

