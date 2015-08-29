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


#ifndef S3STORAGECLASS_H
#define S3STORAGECLASS_H

#include "qtawsglobal.h"
#include <QString>

QTAWS_BEGIN_NAMESPACE

class S3StorageClassPrivate;

class QTAWS_EXPORT S3StorageClass
{
public:
    /// S3 storage classes
    enum Value {
        Standard,           ///< (Default) Provides 99.999999999% durability and 99.99% availability of objects over a given year. It is designed to sustain the concurrent loss of data in two facilities.
        ReducedRedundancy,  ///< Reduces costs by storing noncritical, reproducible data at lower levels of redundancy than the Standard storage class. It provides 99.99% durability and 99.99% availability of objects over a given year.
        Glacier,            ///< Suitable for archiving data, where data access is infrequent and a retrieval time of several hours is acceptable.
        OtherClass = 0xFF   ///< Used when the storage class is unknown.
    };

    S3StorageClass(const Value & storageClass = Standard);
    S3StorageClass(const S3StorageClass & other);
    ~S3StorageClass();

    S3StorageClass & operator=(const S3StorageClass & other);

    QString toString() const;
    bool isDefault() const;

    bool operator==(const S3StorageClass & other) const;

    static S3StorageClass fromString(const QString & storageClass);

private:
    Q_DECLARE_PRIVATE(S3StorageClass)
    S3StorageClassPrivate * const d_ptr; ///< Internal d-pointer
};

QTAWS_END_NAMESPACE

#endif // S3STORAGECLASS_H
