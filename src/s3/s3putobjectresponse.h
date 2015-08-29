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


#ifndef S3PUTOBJECTRESPONSE_H
#define S3PUTOBJECTRESPONSE_H

#include "s3putobjectrequest.h"
#include "s3response.h"

QTAWS_BEGIN_NAMESPACE

class S3PutObjectResponsePrivate;

class QTAWS_EXPORT S3PutObjectResponse : public S3Response
{
    Q_OBJECT

public:
    S3PutObjectResponse(const S3PutObjectRequest & request, QNetworkReply * const reply, QObject * const parent = 0);

    virtual bool isValid() const;
    virtual const S3PutObjectRequest * request() const;

protected slots:
    virtual void parseSuccess(QIODevice & response);

private:
    Q_DECLARE_PRIVATE(S3PutObjectResponse)
    Q_DISABLE_COPY(S3PutObjectResponse)
};

QTAWS_END_NAMESPACE

#endif // S3PUTOBJECTRESPONSE_H
