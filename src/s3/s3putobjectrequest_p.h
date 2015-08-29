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

