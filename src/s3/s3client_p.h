// S3Client_p.h
// By Mike Kuta
// August 20, 2015
//
// The private parts of the S3Client class.
//
// libqtaws is licensed under the GNU Lesser General Public License.
//
// https://github.com/pcolby/libqtaws
//
// Copyright © 2015 Kuta Software LLC.  All rights reserved.


#ifndef S3CLIENT_P_H
#define S3CLIENT_P_H

#include "awsabstractclient_p.h"

class QNetworkAccessManager;

QTAWS_BEGIN_NAMESPACE

class S3Client;

class QTAWS_EXPORT S3ClientPrivate : public AwsAbstractClientPrivate
{
public:
    S3ClientPrivate(S3Client * const q);

private:
    Q_DECLARE_PUBLIC(S3Client)
    Q_DISABLE_COPY(S3ClientPrivate)
};

QTAWS_END_NAMESPACE

#endif // S3CLIENT_P_H

