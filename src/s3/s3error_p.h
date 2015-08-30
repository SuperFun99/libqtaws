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

#ifndef S3ERROR_P_H
#define S3ERROR_P_H

#include "s3error.h"

QTAWS_BEGIN_NAMESPACE

class QTAWS_EXPORT S3ErrorPrivate {

public:
    S3Error::ErrorCode code;  ///< S3 error code.
    QVariantMap detail;       ///< S3 error detail.
    QString message;          ///< S3 error message.
    QString rawCode;          ///< Raw S3 error code.

    S3ErrorPrivate(S3Error * const q);
    S3ErrorPrivate(const S3ErrorPrivate * const other, S3Error * const q);

    virtual ~S3ErrorPrivate();

    void parse(QXmlStreamReader &xml);

    static S3Error::ErrorCode codeFromString(const QString &code);

private:
    Q_DECLARE_PUBLIC(S3Error)
    Q_DISABLE_COPY(S3ErrorPrivate)
    S3Error * const q_ptr; ///< Internal q-pointer.

};

QTAWS_END_NAMESPACE

#endif // S3ERROR_P_H
