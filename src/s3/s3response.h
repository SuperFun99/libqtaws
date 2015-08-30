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


#ifndef S3RESPONSE_H
#define S3RESPONSE_H

#include "core/awsabstractresponse.h"
#include "s3error.h"

QTAWS_BEGIN_NAMESPACE

class S3ResponsePrivate;

class QTAWS_EXPORT S3Response : public AwsAbstractResponse
{
    Q_OBJECT

public:
    S3Response(QObject * const parent = 0);

    virtual QString errorString() const;
    virtual bool hasError() const;
    virtual bool isValid() const;

    QString requestId() const;
    QString amzId2() const;

    S3ErrorList serviceErrors() const;

    QNetworkReply * networkReply() const;

protected:
    /// @cond internal
    S3Response(S3ResponsePrivate * const d, QObject * const parent);
    /// @endcond

    virtual void parse(QNetworkReply * const reply);
    virtual void parseFailure(QIODevice & response);
    virtual void parseSuccess(QIODevice & response);

private:
    Q_DECLARE_PRIVATE(S3Response)
    Q_DISABLE_COPY(S3Response)
};

QTAWS_END_NAMESPACE

#endif // S3RESPONSE_H
