begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file defines the EFI REST Protocol interface.    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution. The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is introduced in UEFI Specification 2.5  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_REST_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_REST_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/Http.h>
end_include

begin_define
define|#
directive|define
name|EFI_REST_PROTOCOL_GUID
define|\
value|{ \     0x0db48a36, 0x4e54, 0xea9c, {0x9b, 0x09, 0x1e, 0xa5, 0xbe, 0x3a, 0x66, 0x0b } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_REST_PROTOCOL
name|EFI_REST_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Provides a simple HTTP-like interface to send and receive resources from a REST   service.    The SendReceive() function sends an HTTP request to this REST service, and returns a   response when the data is retrieved from the service. RequestMessage contains the HTTP   request to the REST resource identified by RequestMessage.Request.Url. The   ResponseMessage is the returned HTTP response for that request, including any HTTP   status.    @param[in]  This                Pointer to EFI_REST_PROTOCOL instance for a particular                                   REST service.   @param[in]  RequestMessage      Pointer to the HTTP request data for this resource.   @param[out] ResponseMessage     Pointer to the HTTP response data obtained for this                                   requested.    @retval EFI_SUCCESS             Operation succeeded.   @retval EFI_INVALID_PARAMETER   This, RequestMessage, or ResponseMessage are NULL.   @retval EFI_DEVICE_ERROR        An unexpected system or network error occurred. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_REST_SEND_RECEIVE
function_decl|)
parameter_list|(
name|IN
name|EFI_REST_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HTTP_MESSAGE
modifier|*
name|RequestMessage
parameter_list|,
name|OUT
name|EFI_HTTP_MESSAGE
modifier|*
name|ResponseMessage
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The GetServiceTime() function is an optional interface to obtain the current time from   this REST service instance. If this REST service does not support retrieving the time,   this function returns EFI_UNSUPPORTED.    @param[in]  This                Pointer to EFI_REST_PROTOCOL instance.   @param[out] Time                A pointer to storage to receive a snapshot of the                                   current time of the REST service.    @retval EFI_SUCCESS             Operation succeeded   @retval EFI_INVALID_PARAMETER   This or Time are NULL.   @retval EFI_UNSUPPORTED         The RESTful service does not support returning the                                   time.   @retval EFI_DEVICE_ERROR        An unexpected system or network error occurred. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_REST_GET_TIME
function_decl|)
parameter_list|(
name|IN
name|EFI_REST_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_TIME
modifier|*
name|Time
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI REST protocol is designed to be used by EFI drivers and applications to send
end_comment

begin_comment
comment|/// and receive resources from a RESTful service. This protocol abstracts REST
end_comment

begin_comment
comment|/// (Representational State Transfer) client functionality. This EFI protocol could be
end_comment

begin_comment
comment|/// implemented to use an underlying EFI HTTP protocol, or it could rely on other
end_comment

begin_comment
comment|/// interfaces that abstract HTTP access to the resources.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_REST_PROTOCOL
block|{
name|EFI_REST_SEND_RECEIVE
name|SendReceive
decl_stmt|;
name|EFI_REST_GET_TIME
name|GetServiceTime
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiRestProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

