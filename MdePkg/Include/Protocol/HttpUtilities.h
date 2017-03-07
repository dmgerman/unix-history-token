begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI HTTP Utilities protocol provides a platform independent abstraction for HTTP   message comprehension.    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution. The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is introduced in UEFI Specification 2.5  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_HTTP_UTILITIES_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_HTTP_UTILITIES_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/Http.h>
end_include

begin_define
define|#
directive|define
name|EFI_HTTP_UTILITIES_PROTOCOL_GUID
define|\
value|{ \     0x3e35c163, 0x4074, 0x45dd, {0x43, 0x1e, 0x23, 0x98, 0x9d, 0xd8, 0x6b, 0x32 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_HTTP_UTILITIES_PROTOCOL
name|EFI_HTTP_UTILITIES_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Create HTTP header based on a combination of seed header, fields   to delete, and fields to append.    The Build() function is used to manage the headers portion of an   HTTP message by providing the ability to add, remove, or replace   HTTP headers.    @param[in]  This                Pointer to EFI_HTTP_UTILITIES_PROTOCOL instance.   @param[in]  SeedMessageSize     Size of the initial HTTP header. This can be zero.   @param[in]  SeedMessage         Initial HTTP header to be used as a base for                                   building a new HTTP header. If NULL,                                   SeedMessageSize is ignored.   @param[in]  DeleteCount         Number of null-terminated HTTP header field names                                   in DeleteList.   @param[in]  DeleteList          List of null-terminated HTTP header field names to                                   remove from SeedMessage. Only the field names are                                   in this list because the field values are irrelevant                                   to this operation.   @param[in]  AppendCount         Number of header fields in AppendList.   @param[in]  AppendList          List of HTTP headers to populate NewMessage with.                                   If SeedMessage is not NULL, AppendList will be                                   appended to the existing list from SeedMessage in                                   NewMessage.   @param[out] NewMessageSize      Pointer to number of header fields in NewMessage.   @param[out] NewMessage          Pointer to a new list of HTTP headers based on.    @retval EFI_SUCCESS             Add, remove, and replace operations succeeded.   @retval EFI_OUT_OF_RESOURCES    Could not allocate memory for NewMessage.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   This is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HTTP_UTILS_BUILD
function_decl|)
parameter_list|(
name|IN
name|EFI_HTTP_UTILITIES_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|SeedMessageSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|SeedMessage
parameter_list|,
name|OPTIONAL
name|IN
name|UINTN
name|DeleteCount
parameter_list|,
name|IN
name|CHAR8
modifier|*
name|DeleteList
index|[]
parameter_list|,
name|OPTIONAL
name|IN
name|UINTN
name|AppendCount
parameter_list|,
name|IN
name|EFI_HTTP_HEADER
modifier|*
name|AppendList
index|[]
parameter_list|,
name|OPTIONAL
name|OUT
name|UINTN
modifier|*
name|NewMessageSize
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|NewMessage
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Parses HTTP header and produces an array of key/value pairs.    The Parse() function is used to transform data stored in HttpHeader   into a list of fields paired with their corresponding values.    @param[in]  This                Pointer to EFI_HTTP_UTILITIES_PROTOCOL instance.   @param[in]  HttpMessage         Contains raw unformatted HTTP header string.   @param[in]  HttpMessageSize     Size of HTTP header.   @param[out] HeaderFields        Array of key/value header pairs.   @param[out] FieldCount          Number of headers in HeaderFields.    @retval EFI_SUCCESS             Allocation succeeded.   @retval EFI_NOT_STARTED         This EFI HTTP Protocol instance has not been                                   initialized.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   This is NULL.                                   HttpMessage is NULL.                                   HeaderFields is NULL.                                   FieldCount is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HTTP_UTILS_PARSE
function_decl|)
parameter_list|(
name|IN
name|EFI_HTTP_UTILITIES_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CHAR8
modifier|*
name|HttpMessage
parameter_list|,
name|IN
name|UINTN
name|HttpMessageSize
parameter_list|,
name|OUT
name|EFI_HTTP_HEADER
modifier|*
modifier|*
name|HeaderFields
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|FieldCount
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_HTTP_UTILITIES_PROTOCOL
end_comment

begin_comment
comment|/// designed to be used by EFI drivers and applications to parse HTTP
end_comment

begin_comment
comment|/// headers from a byte stream. This driver is neither dependent on
end_comment

begin_comment
comment|/// network connectivity, nor the existence of an underlying network
end_comment

begin_comment
comment|/// infrastructure.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_HTTP_UTILITIES_PROTOCOL
block|{
name|EFI_HTTP_UTILS_BUILD
name|Build
decl_stmt|;
name|EFI_HTTP_UTILS_PARSE
name|Parse
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHttpUtilitiesProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

