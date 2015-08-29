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


#ifndef S3STORAGECLASS_P_H
#define S3STORAGECLASS_P_H

#include "qtawsglobal.h"
#include <QtGlobal>

QTAWS_BEGIN_NAMESPACE

class S3StorageClass;

class QTAWS_EXPORT S3StorageClassPrivate
{
public:
    S3StorageClassPrivate(const int storageClass, S3StorageClass * const q);
    S3StorageClassPrivate(const S3StorageClassPrivate & other, S3StorageClass * const q);

protected:
    int storageClass;  ///< S3StorageClass::Value represented by this object

private:
    Q_DECLARE_PUBLIC(S3StorageClass)
    Q_DISABLE_COPY(S3StorageClassPrivate)
    S3StorageClass * const q_ptr;  ///< Internal q-pointer.
};

QTAWS_END_NAMESPACE

#endif // S3STORAGECLASS_P_H

