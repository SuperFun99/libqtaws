// S3Request_p.h
// By Mike Kuta
// August 20, 2015
//
// The private parts of the S3Request class.
//
// libqtaws is licensed under the GNU Lesser General Public License.
//
// https://github.com/pcolby/libqtaws
//
// Copyright © 2015 Kuta Software LLC.  All rights reserved.


#ifndef S3REQUEST_P_H
#define S3REQUEST_P_H

#include "awsabstractrequest_p.h"
#include "s3request.h"

QTAWS_BEGIN_NAMESPACE

class QTAWS_EXPORT S3RequestPrivate : public AwsAbstractRequestPrivate
{
public:
    S3Request::Action action;
    S3Request::RequestStyle requestStyle;
    QString apiVersion;
    QString bucketName;

    S3RequestPrivate(const S3Request::Action action, const QString & bucketName, S3Request * const q);
    S3RequestPrivate(const S3RequestPrivate & other, S3Request * const q);

    static QString toString(const S3Request::Action & action);

private:
    Q_DECLARE_PUBLIC(S3Request)
    Q_DISABLE_COPY(S3RequestPrivate)
};

QTAWS_END_NAMESPACE

#endif // S3REQUEST_P_H
