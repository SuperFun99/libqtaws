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


#ifndef S3CLIENT_P_H
#define S3CLIENT_P_H

#include "core/awsabstractclient_p.h"

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

