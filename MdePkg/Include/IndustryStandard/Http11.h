begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Hypertext Transfer Protocol -- HTTP/1.1 Standard definitions, from RFC 2616        This file contains common HTTP 1.1 definitions from RFC 2616        (C) Copyright 2015-2016 Hewlett Packard Enterprise Development LP<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED. **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HTTP_11_H__
end_ifndef

begin_define
define|#
directive|define
name|__HTTP_11_H__
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|///
end_comment

begin_comment
comment|/// HTTP Version (currently HTTP 1.1)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The version of an HTTP message is indicated by an HTTP-Version field
end_comment

begin_comment
comment|/// in the first line of the message.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_VERSION
value|"HTTP/1.1"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// HTTP Request Method definitions
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The Method  token indicates the method to be performed on the
end_comment

begin_comment
comment|/// resource identified by the Request-URI. The method is case-sensitive.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_METHOD_OPTIONS
value|"OPTIONS"
end_define

begin_define
define|#
directive|define
name|HTTP_METHOD_GET
value|"GET"
end_define

begin_define
define|#
directive|define
name|HTTP_METHOD_HEAD
value|"HEAD"
end_define

begin_define
define|#
directive|define
name|HTTP_METHOD_POST
value|"POST"
end_define

begin_define
define|#
directive|define
name|HTTP_METHOD_PUT
value|"PUT"
end_define

begin_define
define|#
directive|define
name|HTTP_METHOD_DELETE
value|"DELETE"
end_define

begin_define
define|#
directive|define
name|HTTP_METHOD_TRACE
value|"TRACE"
end_define

begin_define
define|#
directive|define
name|HTTP_METHOD_CONNECT
value|"CONNECT"
end_define

begin_define
define|#
directive|define
name|HTTP_METHOD_PATCH
value|"PATCH"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Connect method has maximum length according to EFI_HTTP_METHOD defined in
end_comment

begin_comment
comment|/// UEFI2.5 spec so use this.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_METHOD_MAXIMUM_LEN
value|sizeof (HTTP_METHOD_CONNECT)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Accept Request Header
end_comment

begin_comment
comment|/// The Accept request-header field can be used to specify certain media types which are
end_comment

begin_comment
comment|/// acceptable for the response. Accept headers can be used to indicate that the request
end_comment

begin_comment
comment|/// is specifically limited to a small set of desired types, as in the case of a request
end_comment

begin_comment
comment|/// for an in-line image.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_HEADER_ACCEPT
value|"Accept"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Accept-Charset Request Header
end_comment

begin_comment
comment|/// The Accept-Charset request-header field can be used to indicate what character sets
end_comment

begin_comment
comment|/// are acceptable for the response. This field allows clients capable of understanding
end_comment

begin_comment
comment|/// more comprehensive or special-purpose character sets to signal that capability to a
end_comment

begin_comment
comment|/// server which is capable of representing documents in those character sets.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_HEADER_ACCEPT_CHARSET
value|"Accept-Charset"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Accept-Language Request Header
end_comment

begin_comment
comment|/// The Accept-Language request-header field is similar to Accept,
end_comment

begin_comment
comment|/// but restricts the set of natural languages that are preferred
end_comment

begin_comment
comment|/// as a response to the request.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_HEADER_ACCEPT_LANGUAGE
value|"Accept-Language"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Accept-Ranges Request Header
end_comment

begin_comment
comment|/// The Accept-Ranges response-header field allows the server to
end_comment

begin_comment
comment|/// indicate its acceptance of range requests for a resource:
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_HEADER_ACCEPT_RANGES
value|"Accept-Ranges"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Accept-Encoding Request Header
end_comment

begin_comment
comment|/// The Accept-Encoding request-header field is similar to Accept,
end_comment

begin_comment
comment|/// but restricts the content-codings that are acceptable in the response.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_HEADER_ACCEPT_ENCODING
value|"Accept-Encoding"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Content-Encoding Header
end_comment

begin_comment
comment|/// The Content-Encoding entity-header field is used as a modifier to the media-type.
end_comment

begin_comment
comment|/// When present, its value indicates what additional content codings have been applied
end_comment

begin_comment
comment|/// to the entity-body, and thus what decoding mechanisms must be applied in order to
end_comment

begin_comment
comment|/// obtain the media-type referenced by the Content-Type header field. Content-Encoding
end_comment

begin_comment
comment|/// is primarily used to allow a document to be compressed without losing the identity
end_comment

begin_comment
comment|/// of its underlying media type.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_HEADER_CONTENT_ENCODING
value|"Content-Encoding"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// HTTP Content-Encoding Compression types
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_CONTENT_ENCODING_IDENTITY
value|"identity"
end_define

begin_comment
comment|/// No transformation is used. This is the default value for content coding.
end_comment

begin_define
define|#
directive|define
name|HTTP_CONTENT_ENCODING_GZIP
value|"gzip"
end_define

begin_comment
comment|/// Content-Encoding: GNU zip format (described in RFC 1952).
end_comment

begin_define
define|#
directive|define
name|HTTP_CONTENT_ENCODING_COMPRESS
value|"compress"
end_define

begin_comment
comment|/// encoding format produced by the common UNIX file compression program "compress".
end_comment

begin_define
define|#
directive|define
name|HTTP_CONTENT_ENCODING_DEFLATE
value|"deflate"
end_define

begin_comment
comment|/// The "zlib" format defined in RFC 1950 in combination with the "deflate"
end_comment

begin_comment
comment|/// compression mechanism described in RFC 1951.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Content-Type Header
end_comment

begin_comment
comment|/// The Content-Type entity-header field indicates the media type of the entity-body sent to
end_comment

begin_comment
comment|/// the recipient or, in the case of the HEAD method, the media type that would have been sent
end_comment

begin_comment
comment|/// had the request been a GET.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_HEADER_CONTENT_TYPE
value|"Content-Type"
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Common Media Types defined in http://www.iana.org/assignments/media-types/media-types.xhtml
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|HTTP_CONTENT_TYPE_APP_JSON
value|"application/json"
end_define

begin_define
define|#
directive|define
name|HTTP_CONTENT_TYPE_APP_OCTET_STREAM
value|"application/octet-stream"
end_define

begin_define
define|#
directive|define
name|HTTP_CONTENT_TYPE_TEXT_HTML
value|"text/html"
end_define

begin_define
define|#
directive|define
name|HTTP_CONTENT_TYPE_TEXT_PLAIN
value|"text/plain"
end_define

begin_define
define|#
directive|define
name|HTTP_CONTENT_TYPE_TEXT_CSS
value|"text/css"
end_define

begin_define
define|#
directive|define
name|HTTP_CONTENT_TYPE_TEXT_XML
value|"text/xml"
end_define

begin_define
define|#
directive|define
name|HTTP_CONTENT_TYPE_IMAGE_GIF
value|"image/gif"
end_define

begin_define
define|#
directive|define
name|HTTP_CONTENT_TYPE_IMAGE_JPEG
value|"image/jpeg"
end_define

begin_define
define|#
directive|define
name|HTTP_CONTENT_TYPE_IMAGE_PNG
value|"image/png"
end_define

begin_define
define|#
directive|define
name|HTTP_CONTENT_TYPE_IMAGE_SVG_XML
value|"image/svg+xml"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Content-Length Header
end_comment

begin_comment
comment|/// The Content-Length entity-header field indicates the size of the entity-body,
end_comment

begin_comment
comment|/// in decimal number of OCTETs, sent to the recipient or, in the case of the HEAD
end_comment

begin_comment
comment|/// method, the size of the entity-body that would have been sent had the request been a GET.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_HEADER_CONTENT_LENGTH
value|"Content-Length"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Transfer-Encoding Header
end_comment

begin_comment
comment|/// The Transfer-Encoding general-header field indicates what (if any) type of transformation
end_comment

begin_comment
comment|/// has been applied to the message body in order to safely transfer it between the sender
end_comment

begin_comment
comment|/// and the recipient. This differs from the content-coding in that the transfer-coding
end_comment

begin_comment
comment|/// is a property of the message, not of the entity.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_HEADER_TRANSFER_ENCODING
value|"Transfer-Encoding"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// User Agent Request Header
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The User-Agent request-header field contains information about the user agent originating
end_comment

begin_comment
comment|/// the request. This is for statistical purposes, the tracing of protocol violations, and
end_comment

begin_comment
comment|/// automated recognition of user agents for the sake of tailoring responses to avoid
end_comment

begin_comment
comment|/// particular user agent limitations. User agents SHOULD include this field with requests.
end_comment

begin_comment
comment|/// The field can contain multiple product tokens and comments identifying the agent and any
end_comment

begin_comment
comment|/// subproducts which form a significant part of the user agent.
end_comment

begin_comment
comment|/// By convention, the product tokens are listed in order of their significance for
end_comment

begin_comment
comment|/// identifying the application.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_HEADER_USER_AGENT
value|"User-Agent"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Host Request Header
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The Host request-header field specifies the Internet host and port number of the resource
end_comment

begin_comment
comment|/// being requested, as obtained from the original URI given by the user or referring resource
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_HEADER_HOST
value|"Host"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Location Response Header
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The Location response-header field is used to redirect the recipient to a location other than
end_comment

begin_comment
comment|/// the Request-URI for completion of the request or identification of a new resource.
end_comment

begin_comment
comment|/// For 201 (Created) responses, the Location is that of the new resource which was created by
end_comment

begin_comment
comment|/// the request. For 3xx responses, the location SHOULD indicate the server's preferred URI for
end_comment

begin_comment
comment|/// automatic redirection to the resource. The field value consists of a single absolute URI.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_HEADER_LOCATION
value|"Location"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The If-Match request-header field is used with a method to make it conditional.
end_comment

begin_comment
comment|/// A client that has one or more entities previously obtained from the resource
end_comment

begin_comment
comment|/// can verify that one of those entities is current by including a list of their
end_comment

begin_comment
comment|/// associated entity tags in the If-Match header field.
end_comment

begin_comment
comment|/// The purpose of this feature is to allow efficient updates of cached information
end_comment

begin_comment
comment|/// with a minimum amount of transaction overhead. It is also used, on updating requests,
end_comment

begin_comment
comment|/// to prevent inadvertent modification of the wrong version of a resource.
end_comment

begin_comment
comment|/// As a special case, the value "*" matches any current entity of the resource.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_HEADER_IF_MATCH
value|"If-Match"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The If-None-Match request-header field is used with a method to make it conditional.
end_comment

begin_comment
comment|/// A client that has one or more entities previously obtained from the resource can verify
end_comment

begin_comment
comment|/// that none of those entities is current by including a list of their associated entity
end_comment

begin_comment
comment|/// tags in the If-None-Match header field. The purpose of this feature is to allow efficient
end_comment

begin_comment
comment|/// updates of cached information with a minimum amount of transaction overhead. It is also used
end_comment

begin_comment
comment|/// to prevent a method (e.g. PUT) from inadvertently modifying an existing resource when the
end_comment

begin_comment
comment|/// client believes that the resource does not exist.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_HEADER_IF_NONE_MATCH
value|"If-None-Match"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Authorization Request Header
end_comment

begin_comment
comment|/// The Authorization field value consists of credentials
end_comment

begin_comment
comment|/// containing the authentication information of the user agent for
end_comment

begin_comment
comment|/// the realm of the resource being requested.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_HEADER_AUTHORIZATION
value|"Authorization"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// ETAG Response Header
end_comment

begin_comment
comment|/// The ETag response-header field provides the current value of the entity tag
end_comment

begin_comment
comment|/// for the requested variant.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_HEADER_ETAG
value|"ETag"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Custom header field checked by the iLO web server to
end_comment

begin_comment
comment|/// specify a client session key.
end_comment

begin_comment
comment|/// Example:     X-Auth-Token: 24de6b1f8fa147ad59f6452def628798
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_HEADER_X_AUTH_TOKEN
value|"X-Auth-Token"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Expect Header
end_comment

begin_comment
comment|/// The "Expect" header field in a request indicates a certain set of
end_comment

begin_comment
comment|/// behaviors (expectations) that need to be supported by the server in
end_comment

begin_comment
comment|/// order to properly handle this request. The only such expectation
end_comment

begin_comment
comment|/// defined by this specification is 100-continue.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_HEADER_EXPECT
value|"Expect"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Expect Header Value
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HTTP_EXPECT_100_CONTINUE
value|"100-continue"
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

