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


#ifndef S3CANNEDACL_P_H
#define S3CANNEDACL_P_H

#include "qtawsglobal.h"
#include <QtGlobal>

QTAWS_BEGIN_NAMESPACE

class S3CannedACL;

class QTAWS_EXPORT S3CannedACLPrivate
{
public:
    S3CannedACLPrivate(const int cannedACL, S3CannedACL * const q);
    S3CannedACLPrivate(const S3CannedACLPrivate & other, S3CannedACL * const q);

protected:
    int cannedACL;  ///< S3CannedACL::Value represented by this object

private:
    Q_DECLARE_PUBLIC(S3CannedACL)
    Q_DISABLE_COPY(S3CannedACLPrivate)
    S3CannedACL * const q_ptr;  ///< Internal q-pointer.
};

QTAWS_END_NAMESPACE

#endif // S3CANNEDACL_P_H

