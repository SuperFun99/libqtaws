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

