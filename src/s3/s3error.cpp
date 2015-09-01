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

#include "s3error.h"
#include "s3error_p.h"
#include "core/awsabstractresponse.h"

#include <QDebug>
#include <QVariantMap>
#include <QXmlStreamReader>

QTAWS_BEGIN_NAMESPACE

/**
 * @class  S3Error
 *
 * @brief  Encapsulation of an Error element from an S3 ErrorResponse response.
 *
 * @see    http://docs.aws.amazon.com/AmazonS3/latest/API/ErrorResponses.html
 */

/**
 * @brief  Constructs a new S3Error object.
 *
 * @param  xml     XML stream to parse an S3 Error from.
 */
S3Error::S3Error(QXmlStreamReader &xml) : d_ptr(new S3ErrorPrivate(this))
{
    Q_D(S3Error);
    d->parse(xml);
}

/**
 * @internal
 *
 * @brief  Default constructor.
 *
 * Constructs an invalid S3Error object, useful only for assignment via the
 * assignment operator defined below.
 *
 * @note  This function exists solely for compatability with Qt's container
 *        classes, such as QList, which require "assignable data types" - ie
 *        ones that "provide a default constructor, a copy constructor, and an
 *        assignment operator".
 *
 * @see   http://doc.qt.io/qt-5/containers.html
 */
S3Error::S3Error() : d_ptr(new S3ErrorPrivate(this))
{

}

/**
 * @internal
 *
 * @brief  Constructs a new S3Error object.
 *
 * This overload allows derived classes to provide their own private class
 * implementation that inherits from S3ErrorPrivate.
 *
 * @param  d  Pointer to private data (aka D-Pointer).
 */
S3Error::S3Error(S3ErrorPrivate * const d) : d_ptr(d)
{

}

/**
 * @internal
 *
 * @brief  Copy constructor.
 *
 * Constructs an S3Error object by copying \a other.
 *
 * @note  This function exists solely for compatability with Qt's container
 *        classes, such as QList, which require "assignable data types" - ie
 *        ones that "provide a default constructor, a copy constructor, and an
 *        assignment operator".
 *
 * @param  other  Instance to copy.
 *
 * @see    http://doc.qt.io/qt-5/containers.html
 */
S3Error::S3Error(const S3Error & other)
    : d_ptr(new S3ErrorPrivate(other.d_func(), this))
{

}

/**
 * @internal
 *
 * @brief  Assignment operator.
 *
 * Assigns \a other to \c this.
 *
 * @note  This function exists solely for compatability with Qt's container
 *        classes, such as QList, which require "assignable data types" - ie
 *        ones that "provide a default constructor, a copy constructor, and an
 *        assignment operator".
 *
 * @param  other  Instance to copy.
 *
 * @return A reference to this object.
 *
 * @see   http://doc.qt.io/qt-5/containers.html
 */
S3Error & S3Error::operator=(const S3Error & other)
{
    Q_D(S3Error);
    d->code = other.code();
    d->detail = other.detail();
    d->message = other.message();
    d->rawCode = other.rawCode();
    return *this;
}

/**
 * @brief S3Error destructor.
 */
S3Error::~S3Error()
{
    delete d_ptr;
}

/**
 * @brief  Get the parsed S3 error code.
 *
 * @return An S3 error code, or S3Error::OtherError if not found or not recognized.
 *
 * @see rawCode
 */
S3Error::ErrorCode S3Error::code() const
{
    Q_D(const S3Error);
    return d->code;
}

/**
 * @brief  Get the S3 error detail, if any.
 *
 * @return S3 error detail, or an empty QVariantMap if not found.
 */
QVariantMap S3Error::detail() const
{
    Q_D(const S3Error);
    return d->detail;
}

/**
 * @brief  Get the parsed S3 error message.
 *
 * @return S3 error message, or a null QString if not found.
 */
QString S3Error::message() const
{
    Q_D(const S3Error);
    return d->message;
}

/**
 * @brief  Get the raw S3 error code string.
 *
 * That may be useful if code returned S3Error::OtherError due to the error
 * code being found, but not recognizable.
 *
 * @return The raw S3 error code string, or a null QString is not found.
 *
 * @see code
 */
QString S3Error::rawCode() const
{
    Q_D(const S3Error);
    return d->rawCode;
}

/**
 * @brief  Equality operator
 *
 * @param  other  Instance to compare \c this to.
 *
 * @return \c true if \c this and \a other are considered equal
 */
bool S3Error::operator==(const S3Error & other) const
{
    return ((rawCode() == other.rawCode()) &&
            (detail() == other.detail()) &&
            (message() == other.message()));
}

/**
 * @internal
 *
 * @class  S3ErrorPrivate
 *
 * @brief  Private implementation for S3Error.
 */

/**
 * @internal
 *
 * @brief  Constructs a new S3ErrorPrivate object.
 *
 * @param  q  Pointer to this object's public S3Error instance.
 */
S3ErrorPrivate::S3ErrorPrivate(S3Error * const q)
    : code(S3Error::NoError), q_ptr(q)
{

}

/**
 * @internal
 *
 * @brief Construc an S3ErrorPrivate object by copying another.
 *
 * This is a lot like a copy constructor, and exists only to support the
 * S3Error class' copy constructor.
 *
 * @param  other  Instance to copy.
 * @param  q      Pointer to this object's public S3Error instance.
 */
S3ErrorPrivate::S3ErrorPrivate(const S3ErrorPrivate * const other, S3Error * const q)
    : code(other->code)
    , detail(other->detail)
    , message(other->message)
    , rawCode(other->rawCode)
    , q_ptr(q)
{

}

/**
 * @brief S3ErrorPrivate destructor.
 *
 * This virtual destructor does nothing (yet) - its here to allow for safe
 * polymorphic destruction.
 */
S3ErrorPrivate::~S3ErrorPrivate()
{

}

/**
 * @brief  Parse an S3 Error element.
 *
 * This function parses Error XML elements.
 *
 * For example:
 *
 * @code{xml}
 * <Error>
 *   <Code>NoSuchKey</Code>
 *   <Message>The resource you requested does not exist</Message>
 *   <Resource>/mybucket/myfoto.jpg</Resource>
 *   <RequestId>4442587FB7D0A2F9</RequestId>
 * </Error>
 * @endcode
 *
 * @param  xml  XML stream to parse.
 */
void S3ErrorPrivate::parse(QXmlStreamReader & xml)
{
    if ((xml.tokenType() == QXmlStreamReader::NoToken) && (!xml.readNextStartElement())) {
        return;
    }
    Q_ASSERT(xml.name() == QLatin1String("Error"));
    while (xml.readNextStartElement()) {
        if (xml.name() == QLatin1String("Code")) {
            code = codeFromString(rawCode = xml.readElementText());
        } else if (xml.name() == QLatin1String("Message")) {
            message = xml.readElementText();
        } else {
            detail.insert(xml.name().toString(), xml.readElementText());
        }
    }
}

/**
 * @brief  Convert an S3 error code string to an ErrorCode enum value.
 *
 * @param  code  S3 error code.
 *
 * @return ErrorCode equivalent to \a code, or S3Error::OtherError if not recognised.
 */
S3Error::ErrorCode S3ErrorPrivate::codeFromString(const QString &code)
{
    #define IfStringReturnErrorResponse(str) \
        if (code == QLatin1String(#str)) return S3Error::str
    IfStringReturnErrorResponse(AccessDenied);
    IfStringReturnErrorResponse(AccountProblem);
    IfStringReturnErrorResponse(AmbiguousGrantByEmailAddress);
    IfStringReturnErrorResponse(BadDigest);
    IfStringReturnErrorResponse(BucketAlreadyExists);
    IfStringReturnErrorResponse(BucketAlreadyOwnedByYou);
    IfStringReturnErrorResponse(BucketNotEmpty);
    IfStringReturnErrorResponse(CredentialsNotSupported);
    IfStringReturnErrorResponse(CrossLocationLoggingProhibited);
    IfStringReturnErrorResponse(EntityTooSmall);
    IfStringReturnErrorResponse(EntityTooLarge);
    IfStringReturnErrorResponse(ExpiredToken);
    IfStringReturnErrorResponse(IllegalVersioningConfigurationException);
    IfStringReturnErrorResponse(IncompleteBody);
    IfStringReturnErrorResponse(IncorrectNumberOfFilesInPostRequest);
    IfStringReturnErrorResponse(InlineDataTooLarge);
    IfStringReturnErrorResponse(InternalError);
    IfStringReturnErrorResponse(InvalidAccessKeyId);
    IfStringReturnErrorResponse(InvalidAddressingHeader);
    IfStringReturnErrorResponse(InvalidArgument);
    IfStringReturnErrorResponse(InvalidBucketName);
    IfStringReturnErrorResponse(InvalidBucketState);
    IfStringReturnErrorResponse(InvalidDigest);
    IfStringReturnErrorResponse(InvalidEncryptionAlgorithmError);
    IfStringReturnErrorResponse(InvalidLocationConstraint);
    IfStringReturnErrorResponse(InvalidObjectState);
    IfStringReturnErrorResponse(InvalidPart);
    IfStringReturnErrorResponse(InvalidPartOrder);
    IfStringReturnErrorResponse(InvalidPayer);
    IfStringReturnErrorResponse(InvalidPolicyDocument);
    IfStringReturnErrorResponse(InvalidRange);
    IfStringReturnErrorResponse(InvalidRequest);
    IfStringReturnErrorResponse(InvalidSecurity);
    IfStringReturnErrorResponse(InvalidSOAPRequest);
    IfStringReturnErrorResponse(InvalidStorageClass);
    IfStringReturnErrorResponse(InvalidTargetBucketForLogging);
    IfStringReturnErrorResponse(InvalidToken);
    IfStringReturnErrorResponse(InvalidURI);
    IfStringReturnErrorResponse(KeyTooLong);
    IfStringReturnErrorResponse(MalformedACLError);
    IfStringReturnErrorResponse(MalformedPOSTRequest);
    IfStringReturnErrorResponse(MalformedXML);
    IfStringReturnErrorResponse(MaxMessageLengthExceeded);
    IfStringReturnErrorResponse(MaxPostPreDataLengthExceededError);
    IfStringReturnErrorResponse(MetadataTooLarge);
    IfStringReturnErrorResponse(MethodNotAllowed);
    IfStringReturnErrorResponse(MissingAttachment);
    IfStringReturnErrorResponse(MissingContentLength);
    IfStringReturnErrorResponse(MissingRequestBodyError);
    IfStringReturnErrorResponse(MissingSecurityElement);
    IfStringReturnErrorResponse(MissingSecurityHeader);
    IfStringReturnErrorResponse(NoLoggingStatusForKey);
    IfStringReturnErrorResponse(NoSuchBucket);
    IfStringReturnErrorResponse(NoSuchKey);
    IfStringReturnErrorResponse(NoSuchLifecycleConfiguration);
    IfStringReturnErrorResponse(NoSuchUpload);
    IfStringReturnErrorResponse(NoSuchVersion);
    IfStringReturnErrorResponse(NotImplemented);
    IfStringReturnErrorResponse(NotSignedUp);
    IfStringReturnErrorResponse(NoSuchBucketPolicy);
    IfStringReturnErrorResponse(OperationAborted);
    IfStringReturnErrorResponse(PermanentRedirect);
    IfStringReturnErrorResponse(PreconditionFailed);
    IfStringReturnErrorResponse(Redirect);
    IfStringReturnErrorResponse(RestoreAlreadyInProgress);
    IfStringReturnErrorResponse(RequestIsNotMultiPartContent);
    IfStringReturnErrorResponse(RequestTimeout);
    IfStringReturnErrorResponse(RequestTimeTooSkewed);
    IfStringReturnErrorResponse(RequestTorrentOfBucketError);
    IfStringReturnErrorResponse(SignatureDoesNotMatch);
    IfStringReturnErrorResponse(ServiceUnavailable);
    IfStringReturnErrorResponse(SlowDown);
    IfStringReturnErrorResponse(TemporaryRedirect);
    IfStringReturnErrorResponse(TokenRefreshRequired);
    IfStringReturnErrorResponse(TooManyBuckets);
    IfStringReturnErrorResponse(UnexpectedContent);
    IfStringReturnErrorResponse(UnresolvableGrantByEmailAddress);
    IfStringReturnErrorResponse(UserKeyMustBeSpecified);
    #undef IfStringReturnErrorResponse
    qWarning() << "unknown S3 error code" << code;
    return S3Error::OtherError;
}

QTAWS_END_NAMESPACE
