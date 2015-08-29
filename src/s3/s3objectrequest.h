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


#ifndef S3OBJECTREQUEST_H
#define S3OBJECTREQUEST_H

#include "s3request.h"

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
