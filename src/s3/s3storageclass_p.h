// S3StorageClass_p.h
// By Mike Kuta
// Friday, August 28, 2015
//
// The private parts of S3StorageClass.
//
// Extension of libqtaws.  libqtaws is licensed under the GNU Lesser General Public License.
//
// https://github.com/pcolby/libqtaws
//
// Copyright © 2015 Kuta Software LLC.  All rights reserved.


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

