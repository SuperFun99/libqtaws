// S3ObjectRequest.h
// By Mike Kuta
// Friday, August 21, 2015
//
// Class for the private parts of the S3ObjectRequest class.
//
// Extension of libqtaws.  libqtaws is licensed under the GNU Lesser General Public License.
//
// https://github.com/pcolby/libqtaws
//
// Copyright © 2015 Kuta Software LLC.  All rights reserved.


#ifndef S3OBJECTREQUEST_P_H
#define S3OBJECTREQUEST_P_H

#include "s3request_p.h"
#include "s3objectrequest.h"

QTAWS_BEGIN_NAMESPACE

class QTAWS_EXPORT S3ObjectRequestPrivate : public S3RequestPrivate
{
public:
    QString s3ObjectName;
    QString mimeType;

    S3ObjectRequestPrivate(const S3Request::Action action, const QString & bucketName, const QString & s3ObjectName, S3ObjectRequest * const q);
    S3ObjectRequestPrivate(const S3ObjectRequestPrivate & other, S3ObjectRequest * const q);


private:
    Q_DECLARE_PUBLIC(S3ObjectRequest)
    Q_DISABLE_COPY(S3ObjectRequestPrivate)
};

QTAWS_END_NAMESPACE

#endif // S3OBJECTREQUEST_P_H

