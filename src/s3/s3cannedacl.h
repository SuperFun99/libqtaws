// S3CannedACL.h
// By Mike Kuta
// Thursday, August 27, 2015
//
// Canned ACLs for Amazon S3 (preset permissions).
//
// Extension of libqtaws.  libqtaws is licensed under the GNU Lesser General Public License.
//
// https://github.com/pcolby/libqtaws
//
// Copyright © 2015 Kuta Software LLC.  All rights reserved.


#ifndef S3CANNEDACL_H
#define S3CANNEDACL_H

#include "qtawsglobal.h"
#include <QString>

QTAWS_BEGIN_NAMESPACE

class S3CannedACLPrivate;

class QTAWS_EXPORT S3CannedACL
{
public:
    /// Canned ACL values
    enum Value {
        Private,                    ///< Owner gets FULL_CONTROL. No one else has access rights (default).
        PublicRead,                 ///< Owner gets FULL_CONTROL. The AllUsers group gets READ access.
        PublicReadWrite,            ///< Owner gets FULL_CONTROL. The AllUsers group gets READ and WRITE access. Granting this on a bucket is generally not recommended.
        AuthenticatedRead,          ///< Owner gets FULL_CONTROL. The AuthenticatedUsers group gets READ access.
        BucketOwnerRead,            ///< Object owner gets FULL_CONTROL. Bucket owner gets READ access. If you specify this canned ACL when creating a bucket, Amazon S3 ignores it.
        BucketOwnerFullControl,     ///< Both the object owner and the bucket owner get FULL_CONTROL over the object. If you specify this canned ACL when creating a bucket, Amazon S3 ignores it.
        LogDeliveryWrite,           ///< The LogDelivery group gets WRITE and READ_ACP permissions on the bucket.  This value is only valid for buckets.
        Other = 0xFF                ///< Used when the canned ACL value is unknown.
    };

    S3CannedACL(const Value & cannedACL = Private);
    S3CannedACL(const S3CannedACL & other);
    ~S3CannedACL();

    S3CannedACL & operator=(const S3CannedACL & other);

    QString toString() const;
    static S3CannedACL fromString(const QString & cannedACL);

    bool isDefault() const;
    bool isValidForObjects() const;
    bool isValidForBuckets() const;

    bool operator==(const S3CannedACL & other) const;


private:
    Q_DECLARE_PRIVATE(S3CannedACL)
    S3CannedACLPrivate * const d_ptr; ///< Internal d-pointer
};

QTAWS_END_NAMESPACE

#endif // S3CANNEDACL_H
