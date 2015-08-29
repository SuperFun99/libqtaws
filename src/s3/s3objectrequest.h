// S3ObjectRequest.h
// By Mike Kuta
// Friday, August 21, 2015
//
// Base class for Amazon S3 requests involving objects.
//
// Extension of libqtaws.  libqtaws is licensed under the GNU Lesser General Public License.
//
// https://github.com/pcolby/libqtaws
//
// Copyright © 2015 Kuta Software LLC.  All rights reserved.


#ifndef S3OBJECTREQUEST_H
#define S3OBJECTREQUEST_H

#include "s3request.h"

class QNetworkRequest;

QTAWS_BEGIN_NAMESPACE

class S3ObjectRequestPrivate;

class QTAWS_EXPORT S3ObjectRequest : public S3Request
{
public:
    S3ObjectRequest(const S3Request::Action action, const QString & bucketName, const QString & s3ObjectName);
    S3ObjectRequest(const S3ObjectRequest & other);
    S3ObjectRequest & operator=(const S3ObjectRequest & other);

    virtual bool isValid() const;

    QString s3ObjectName() const;
    QString mimeType() const;

    void setS3ObjectName(const QString & s3ObjectName);
    void setMimeType(const QString & mimeType);

    bool operator==(const S3ObjectRequest & other) const;

protected:
    /// @cond internal
    S3ObjectRequest(S3ObjectRequestPrivate * const d);
    /// @endcond

    virtual QNetworkRequest unsignedRequest(const QUrl & endpoint) const;

private:
    Q_DECLARE_PRIVATE(S3ObjectRequest)
};

QTAWS_END_NAMESPACE

#endif // S3OBJECTREQUEST_H
