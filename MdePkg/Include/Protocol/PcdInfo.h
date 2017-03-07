begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Native Platform Configuration Database (PCD) INFO PROTOCOL.    The protocol that provides additional information about items that reside in the PCD database.    Different with the EFI_GET_PCD_INFO_PROTOCOL defined in PI 1.2.1 specification,   the native PCD INFO PROTOCOL provide interfaces for dynamic and dynamic-ex type PCD.    The interfaces for dynamic type PCD do not require the token space guid as parameter,   but interfaces for dynamic-ex type PCD require token space guid as parameter.    Copyright (c) 2013, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PCD_INFO_H__
end_ifndef

begin_define
define|#
directive|define
name|__PCD_INFO_H__
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gGetPcdInfoProtocolGuid
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_PCD_INFO_PROTOCOL_GUID
define|\
value|{ 0x5be40f57, 0xfa68, 0x4610, { 0xbb, 0xbf, 0xe9, 0xc5, 0xfc, 0xda, 0xd3, 0x65 } }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The forward declaration for GET_PCD_INFO_PROTOCOL.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_GET_PCD_INFO_PROTOCOL
name|GET_PCD_INFO_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Retrieve additional information associated with a PCD token.    This includes information such as the type of value the TokenNumber is associated with as well as possible   human readable name that is associated with the token.    @param[in]    TokenNumber The PCD token number.   @param[out]   PcdInfo     The returned information associated with the requested TokenNumber.    @retval  EFI_SUCCESS      The PCD information was returned successfully   @retval  EFI_NOT_FOUND    The PCD service could not find the requested token number. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|GET_PCD_INFO_PROTOCOL_GET_INFO
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|TokenNumber
parameter_list|,
name|OUT
name|EFI_PCD_INFO
modifier|*
name|PcdInfo
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieve additional information associated with a PCD token.    This includes information such as the type of value the TokenNumber is associated with as well as possible   human readable name that is associated with the token.    @param[in]    Guid        The 128-bit unique value that designates the namespace from which to extract the value.   @param[in]    TokenNumber The PCD token number.   @param[out]   PcdInfo     The returned information associated with the requested TokenNumber.    @retval  EFI_SUCCESS      The PCD information was returned successfully   @retval  EFI_NOT_FOUND    The PCD service could not find the requested token number. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|GET_PCD_INFO_PROTOCOL_GET_INFO_EX
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|IN
name|UINTN
name|TokenNumber
parameter_list|,
name|OUT
name|EFI_PCD_INFO
modifier|*
name|PcdInfo
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieve the currently set SKU Id.    @return   The currently set SKU Id. If the platform has not set at a SKU Id, then the             default SKU Id value of 0 is returned. If the platform has set a SKU Id, then the currently set SKU             Id is returned. **/
end_comment

begin_typedef
typedef|typedef
name|UINTN
function_decl|(
name|EFIAPI
modifier|*
name|GET_PCD_INFO_PROTOCOL_GET_SKU
function_decl|)
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is the PCD service to use when querying for some additional data that can be contained in the
end_comment

begin_comment
comment|/// PCD database.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_GET_PCD_INFO_PROTOCOL
block|{
comment|///
comment|/// Retrieve additional information associated with a PCD.
comment|///
name|GET_PCD_INFO_PROTOCOL_GET_INFO
name|GetInfo
decl_stmt|;
name|GET_PCD_INFO_PROTOCOL_GET_INFO_EX
name|GetInfoEx
decl_stmt|;
comment|///
comment|/// Retrieve the currently set SKU Id.
comment|///
name|GET_PCD_INFO_PROTOCOL_GET_SKU
name|GetSku
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

