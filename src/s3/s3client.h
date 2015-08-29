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


#ifndef S3CLIENT_H
#define S3CLIENT_H

#include "core/awsabstractclient.h"
#include <QObject>

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
