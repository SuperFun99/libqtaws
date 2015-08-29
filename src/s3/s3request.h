// S3Request.h
// By Mike Kuta
// Thursday, August 20, 2015
//
// Base class for Amazon S3 requests.
//
// Extension of libqtaws.  libqtaws is licensed under the GNU Lesser General Public License.
//
// https://github.com/pcolby/libqtaws
//
// Copyright © 2015 Kuta Software LLC.  All rights reserved.


#ifndef S3REQUEST_H
#define S3REQUEST_H

#include "core/awsabstractrequest.h"
#include <QFlags>
#include <QObject>

class QNetworkRequest;

QTAWS_BEGIN_NAMESPACE

class AwsAbstractClient;
class S3RequestPrivate;

class QTAWS_EXPORT S3Request : public AwsAbstractRequest
{
public:
    /// Actions supported by S3
    enum Action {
        PutObjectAction           = 0x000001
    };
    Q_DECLARE_FLAGS(Actions, Action)


    /// S3 request styles
    enum RequestStyle {
        VirtualHostedStyle,
        PathStyle
    };


    S3Request(const Action action, const QString & bucketName);
    S3Request(const S3Request & other);
    S3Request & operator=(const S3Request & other);

    virtual bool isValid() const;

    Action action() const;
    QString actionString() const;
    QString apiVersion() const;
    QString bucketName() const;
    RequestStyle requestStyle() const;

    void setAction(const Action action);
    void setApiVersion(const QString & version);
    void setBucketName(const QString & bucketName);
    void setRequestStyle(RequestStyle requestStyle);

    virtual bool operator==(const S3Request & other) const;

protected:
    /// @cond internal
    S3Request(S3RequestPrivate * const d);
    /// @endcond

    virtual QNetworkRequest unsignedRequest(const QUrl & endpoint) const;

private:
    Q_DECLARE_PRIVATE(S3Request)
};

Q_DECLARE_OPERATORS_FOR_FLAGS(S3Request::Actions)

QTAWS_END_NAMESPACE

#endif // S3REQUEST_H
