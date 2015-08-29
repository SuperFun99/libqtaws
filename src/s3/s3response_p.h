// S3Response_p.h
// By Mike Kuta
// August 20, 2015
//
// The private parts of the S3Response class.
//
// libqtaws is licensed under the GNU Lesser General Public License.
//
// https://github.com/pcolby/libqtaws
//
// Copyright © 2015 Kuta Software LLC.  All rights reserved.


#ifndef S3RESPONSE_P_H
#define S3RESPONSE_P_H

#include "awsabstractresponse_p.h"
#include <QXmlStreamReader>

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

