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


#include "s3client.h"
#include "s3client_p.h"
#include "core/awssignaturev4.h"

#include "s3putobjectrequest.h"
#include "s3putobjectresponse.h"


#define S3_SERVICE_NAME QLatin1String("s3")


QTAWS_BEGIN_NAMESPACE



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
S3Client::S3Client(const AwsRegion::Region region, AwsAbstractCredentials * credentials, QNetworkAccessManager * const manager, QObject * const parent)
    : AwsAbstractClient(new S3ClientPrivate(this), parent)
{
    Q_D(S3Client);
    d->region = region;
    d->credentials = credentials;
    d->networkAccessManager = manager;
    d->serviceName = S3_SERVICE_NAME;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
S3PutObjectResponse * S3Client::putObject(const QString & bucketName, const QString & fileName, const QString & s3ObjectName)
{
    S3PutObjectRequest request(bucketName, fileName, s3ObjectName);
    return putObject(request);
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
S3PutObjectResponse * S3Client::putObject(const S3PutObjectRequest & request)
{
    return qobject_cast<S3PutObjectResponse *>(send(request));
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
S3ClientPrivate::S3ClientPrivate(S3Client * const q)
    : AwsAbstractClientPrivate(q)
{
    signature = new AwsSignatureV4();
}


QTAWS_END_NAMESPACE
