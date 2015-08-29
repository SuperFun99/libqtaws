// S3Client.h
// By Mike Kuta
// August 20, 2015
//
// My attempt to extend the libqtaws by Paul Colby to implement the Amazon S3 functions
// that I need.
//
// libqtaws is licensed under the GNU Lesser General Public License.
//
// https://github.com/pcolby/libqtaws
//
// Copyright © 2015 Kuta Software LLC.  All rights reserved.


#ifndef S3CLIENT_H
#define S3CLIENT_H

#include "awsabstractclient.h"
#include <QObject>

class QNetworkReply;
class QFile;

QTAWS_BEGIN_NAMESPACE

class AwsAbstractClient;
class AwsAbstractCredentials;
class S3ClientPrivate;
class S3PutObjectRequest;
class S3PutObjectResponse;

class QTAWS_EXPORT S3Client : public AwsAbstractClient
{
    Q_OBJECT

public:
    S3Client(const AwsRegion::Region region = AwsRegion::InvalidRegion,
             AwsAbstractCredentials * credentials = NULL,
             QNetworkAccessManager * const manager = NULL,
             QObject * const parent = 0);

public slots:
    S3PutObjectResponse * putObject(const QString & bucketName, const QString & fileName, const QString & s3ObjectName);
    S3PutObjectResponse * putObject(const S3PutObjectRequest & request);

private:
    Q_DECLARE_PRIVATE(S3Client)
    Q_DISABLE_COPY(S3Client)
};

QTAWS_END_NAMESPACE

#endif // S3CLIENT_H
