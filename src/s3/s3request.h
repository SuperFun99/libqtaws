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


#ifndef S3REQUEST_H
#define S3REQUEST_H

#include "core/awsabstractrequest.h"
#include <QFlags>
#include <QObject>

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
