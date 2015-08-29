// S3CannedACL_p.h
// By Mike Kuta
// Thursday, August 27, 2015
//
// The private parts of the Canned ACL class.
//
// Extension of libqtaws.  libqtaws is licensed under the GNU Lesser General Public License.
//
// https://github.com/pcolby/libqtaws
//
// Copyright © 2015 Kuta Software LLC.  All rights reserved.


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

