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


#ifndef S3REQUEST_P_H
#define S3REQUEST_P_H

#include "core/awsabstractrequest_p.h"
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
