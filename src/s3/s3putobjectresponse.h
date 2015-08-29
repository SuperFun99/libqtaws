// S3PutObjectResponse.h
// By Mike Kuta
// Thursday, August 20, 2015
//
// Class for response to request to put object to Amazon S3.
//
// Extension of libqtaws.  libqtaws is licensed under the GNU Lesser General Public License.
//
// https://github.com/pcolby/libqtaws
//
// Copyright © 2015 Kuta Software LLC.  All rights reserved.


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
