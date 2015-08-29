// S3PutObjectResponse_p.h
// By Mike Kuta
// Thursday, August 20, 2015
//
// The private parts of S3PutObjectResponse.
//
// Extension of libqtaws.  libqtaws is licensed under the GNU Lesser General Public License.
//
// https://github.com/pcolby/libqtaws
//
// Copyright © 2015 Kuta Software LLC.  All rights reserved.


#ifndef S3PUTOBJECTRESPONSE_P_H
#define S3PUTOBJECTRESPONSE_P_H

#include "s3response_p.h"

QTAWS_BEGIN_NAMESPACE

class S3PutObjectResponse;

class QTAWS_EXPORT S3PutObjectResponsePrivate : public S3ResponsePrivate
{
public:
    S3PutObjectResponsePrivate(S3PutObjectResponse * const q);

private:
    Q_DECLARE_PUBLIC(S3PutObjectResponse)
    Q_DISABLE_COPY(S3PutObjectResponsePrivate)
};

QTAWS_END_NAMESPACE

#endif // S3PUTOBJECTRESPONSE_P_H
