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

#ifndef S3ERROR_H
#define S3ERROR_H

#include "core/qtawsglobal.h"

#include <QList>
#include <QVariantMap>

class QIODevice;
class QXmlStreamReader;

QTAWS_BEGIN_NAMESPACE

class S3ErrorPrivate;

class QTAWS_EXPORT S3Error {

public:
    /// S3 error codes.
    enum ErrorCode {
        NoError = 0,                                ///< No error has occurred
        AccessDenied,                               ///< Access Denied
        AccountProblem,                             ///< There is a problem with your AWS account that prevents the operation from completing successfully. Please use Contact Us.
        AmbiguousGrantByEmailAddress,               ///< The email address you provided is associated with more than one account.
        BadDigest,                                  ///< The Content-MD5 you specified did not match what we received.
        BucketAlreadyExists,                        ///< The requested bucket name is not available. The bucket namespace is shared by all users of the system. Please select a different name and try again.
        BucketAlreadyOwnedByYou,                    ///< Your previous request to create the named bucket succeeded and you already own it. You get this error in all AWS regions except US Standard, us-east-1. In us-east-1 region, you will get 200 OK, but it is no-op (if bucket exists it Amazon S3 will not do anything).
        BucketNotEmpty,                             ///< The bucket you tried to delete is not empty.
        CredentialsNotSupported,                    ///< This request does not support credentials.
        CrossLocationLoggingProhibited,             ///< Cross-location logging not allowed. Buckets in one geographic location cannot log information to a bucket in another location.
        EntityTooSmall,                             ///< Your proposed upload is smaller than the minimum allowed object size.
        EntityTooLarge,                             ///< Your proposed upload exceeds the maximum allowed object size.
        ExpiredToken,                               ///< The provided token has expired.
        IllegalVersioningConfigurationException,    ///< Indicates that the versioning configuration specified in the request is invalid.
        IncompleteBody,                             ///< You did not provide the number of bytes specified by the Content-Length HTTP header
        IncorrectNumberOfFilesInPostRequest,        ///< POST requires exactly one file upload per request.
        InlineDataTooLarge,                         ///< Inline data exceeds the maximum allowed size.
        InternalError,                              ///< We encountered an internal error. Please try again.
        InvalidAccessKeyId,                         ///< The AWS access key Id you provided does not exist in our records.
        InvalidAddressingHeader,                    ///< You must specify the Anonymous role.
        InvalidArgument,                            ///< Invalid Argument
        InvalidBucketName,                          ///< The specified bucket is not valid.
        InvalidBucketState,                         ///< The request is not valid with the current state of the bucket.
        InvalidDigest,                              ///< The Content-MD5 you specified is not valid.
        InvalidEncryptionAlgorithmError,            ///< The encryption request you specified is not valid. The valid value is AES256.
        InvalidLocationConstraint,                  ///< The specified location constraint is not valid. For more information about regions, see How to Select a Region for Your Buckets.
        InvalidObjectState,                         ///< The operation is not valid for the current state of the object.
        InvalidPart,                                ///< One or more of the specified parts could not be found. The part might not have been uploaded, or the specified entity tag might not have matched the part's entity tag.
        InvalidPartOrder,                           ///< The list of parts was not in ascending order.Parts list must specified in order by part number.
        InvalidPayer,                               ///< All access to this object has been disabled.
        InvalidPolicyDocument,                      ///< The content of the form does not meet the conditions specified in the policy document.
        InvalidRange,                               ///< The requested range cannot be satisfied.
        InvalidRequest,                             ///< SOAP requests must be made over an HTTPS connection.
        InvalidSecurity,                            ///< The provided security credentials are not valid.
        InvalidSOAPRequest,                         ///< The SOAP request body is invalid.
        InvalidStorageClass,                        ///< The storage class you specified is not valid.
        InvalidTargetBucketForLogging,              ///< The target bucket for logging does not exist, is not owned by you, or does not have the appropriate grants for the log-delivery group.
        InvalidToken,                               ///< The provided token is malformed or otherwise invalid.
        InvalidURI,                                 ///< Couldn't parse the specified URI.
        KeyTooLong,                                 ///< Your key is too long.
        MalformedACLError,                          ///< The XML you provided was not well-formed or did not validate against our published schema.
        MalformedPOSTRequest,                       ///< The body of your POST request is not well-formed multipart/form-data.
        MalformedXML,                               ///< This happens when the user sends malformed xml (xml that doesn't conform to the published xsd) for the configuration. The error message is, "The XML you provided was not well-formed or did not validate against our published schema."
        MaxMessageLengthExceeded,                   ///< Your request was too big.
        MaxPostPreDataLengthExceededError,          ///< Your POST request fields preceding the upload file were too large.
        MetadataTooLarge,                           ///< Your metadata headers exceed the maximum allowed metadata size.
        MethodNotAllowed,                           ///< The specified method is not allowed against this resource.
        MissingAttachment,                          ///< A SOAP attachment was expected, but none were found.
        MissingContentLength,                       ///< You must provide the Content-Length HTTP header.
        MissingRequestBodyError,                    ///< This happens when the user sends an empty xml document as a request. The error message is, "Request body is empty."
        MissingSecurityElement,                     ///< The SOAP 1.1 request is missing a security element.
        MissingSecurityHeader,                      ///< Your request is missing a required header.
        NoLoggingStatusForKey,                      ///< There is no such thing as a logging status subresource for a key.
        NoSuchBucket,                               ///< The specified bucket does not exist.
        NoSuchKey,                                  ///< The specified key does not exist.
        NoSuchLifecycleConfiguration,               ///< The lifecycle configuration does not exist.
        NoSuchUpload,                               ///< The specified multipart upload does not exist. The upload ID might be invalid, or the multipart upload might have been aborted or completed.
        NoSuchVersion,                              ///< Indicates that the version ID specified in the request does not match an existing version.
        NotImplemented,                             ///< A header you provided implies functionality that is not implemented.
        NotSignedUp,                                ///< Your account is not signed up for the Amazon S3 service. You must sign up before you can use Amazon S3. You can sign up at the following URL: http://aws.amazon.com/s3
        NoSuchBucketPolicy,                         ///< The specified bucket does not have a bucket policy.
        OperationAborted,                           ///< A conflicting conditional operation is currently in progress against this resource. Try again.
        PermanentRedirect,                          ///< The bucket you are attempting to access must be addressed using the specified endpoint. Send all future requests to this endpoint.
        PreconditionFailed,                         ///< At least one of the preconditions you specified did not hold.
        Redirect,                                   ///< Temporary redirect.
        RestoreAlreadyInProgress,                   ///< Object restore is already in progress.
        RequestIsNotMultiPartContent,               ///< Bucket POST must be of the enclosure-type multipart/form-data.
        RequestTimeout,                             ///< Your socket connection to the server was not read from or written to within the timeout period.
        RequestTimeTooSkewed,                       ///< The difference between the request time and the server's time is too large.
        RequestTorrentOfBucketError,                ///< Requesting the torrent file of a bucket is not permitted.
        SignatureDoesNotMatch,                      ///< The request signature we calculated does not match the signature you provided. Check your AWS secret access key and signing method. For more information, see REST Authentication and SOAP Authentication for details.
        ServiceUnavailable,                         ///< Reduce your request rate.
        SlowDown,                                   ///< Reduce your request rate.
        TemporaryRedirect,                          ///< You are being redirected to the bucket while DNS updates.
        TokenRefreshRequired,                       ///< The provided token must be refreshed.
        TooManyBuckets,                             ///< You have attempted to create more buckets than allowed.
        UnexpectedContent,                          ///< This request does not support content.
        UnresolvableGrantByEmailAddress,            ///< The email address you provided does not match any account on record.
        UserKeyMustBeSpecified,                     ///< The bucket POST must contain the specified field name. If it is specified, check the order of the fields.
        OtherError = 0xFF
    };

    S3Error(QXmlStreamReader & xml);

    // Qt container class support.
    /// @cond internal
    S3Error();
    S3Error(const S3Error & other);
    S3Error & operator=(const S3Error & other);
    /// @endcond

    virtual ~S3Error();

    ErrorCode code() const;
    QVariantMap detail() const;
    QString message() const;
    QString rawCode() const;

    bool operator==(const S3Error & other) const;

protected:
    /// @cond internal
    S3ErrorPrivate * const d_ptr; ///< Internal d-pointer.
    S3Error(S3ErrorPrivate * const d);
    /// @endcond

private:
    Q_DECLARE_PRIVATE(S3Error)
};

typedef QList<S3Error> S3ErrorList;

QTAWS_END_NAMESPACE

#endif // S3ERROR_H
