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


#ifndef S3RESPONSE_P_H
#define S3RESPONSE_P_H

#include "core/awsabstractresponse_p.h"

class QXmlStreamReader;

QTAWS_BEGIN_NAMESPACE

class S3Response;

class QTAWS_EXPORT S3ResponsePrivate : public AwsAbstractResponsePrivate
{
public:
    QString amzId2;
    QString requestId;
    QVariantMap xmlValues;

    S3ResponsePrivate(S3Response * const q);

    void parseErrorResponse(QXmlStreamReader & xml);

private:
    Q_DECLARE_PUBLIC(S3Response)
    Q_DISABLE_COPY(S3ResponsePrivate)
};

QTAWS_END_NAMESPACE

#endif // S3RESPONSE_P_H

