// S3Response.h
// By Mike Kuta
// Thursday, August 20, 2015
//
// Base class for Amazon S3 responses.
//
// Extension of libqtaws.  libqtaws is licensed under the GNU Lesser General Public License.
//
// https://github.com/pcolby/libqtaws
//
// Copyright © 2015 Kuta Software LLC.  All rights reserved.


#ifndef S3RESPONSE_H
#define S3RESPONSE_H

#include "core/awsabstractresponse.h"

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
    virtual QNetworkReply::NetworkError networkError() const;

    QString errorCode() const;
    QString message() const;
    QString requestId() const;
    QString amzId2() const;

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
