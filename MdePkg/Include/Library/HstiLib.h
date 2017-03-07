begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides services to create, get and update HSTI table in AIP protocol.    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HSTI_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__HSTI_LIB_H__
end_define

begin_comment
comment|/**   Publish HSTI table in AIP protocol.    One system should have only one PLATFORM_SECURITY_ROLE_PLATFORM_REFERENCE.    If the Role is NOT PLATFORM_SECURITY_ROLE_PLATFORM_REFERENCE,   SecurityFeaturesRequired field will be ignored.    @param Hsti      HSTI data   @param HstiSize  HSTI size    @retval EFI_SUCCESS          The HSTI data is published in AIP protocol.   @retval EFI_ALREADY_STARTED  There is already HSTI table with Role and ImplementationID published in system.   @retval EFI_VOLUME_CORRUPTED The input HSTI data does not follow HSTI specification.   @retval EFI_OUT_OF_RESOURCES There is not enough system resource to publish HSTI data in AIP protocol. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|HstiLibSetTable
parameter_list|(
name|IN
name|VOID
modifier|*
name|Hsti
parameter_list|,
name|IN
name|UINTN
name|HstiSize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Search HSTI table in AIP protocol, and return the data.   This API will return the HSTI table with indicated Role and ImplementationID,   NULL ImplementationID means to find the first HSTI table with indicated Role.    @param Role             Role of HSTI data.   @param ImplementationID ImplementationID of HSTI data.                           NULL means find the first one match Role.   @param Hsti             HSTI data. This buffer is allocated by callee, and it                           is the responsibility of the caller to free it after                           using it.   @param HstiSize         HSTI size    @retval EFI_SUCCESS          The HSTI data in AIP protocol is returned.   @retval EFI_NOT_FOUND        There is not HSTI table with the Role and ImplementationID published in system. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|HstiLibGetTable
parameter_list|(
name|IN
name|UINT32
name|Role
parameter_list|,
name|IN
name|CHAR16
modifier|*
name|ImplementationID
name|OPTIONAL
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Hsti
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|HstiSize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Set FeaturesVerified in published HSTI table.   This API will update the HSTI table with indicated Role and ImplementationID,   NULL ImplementationID means to find the first HSTI table with indicated Role.    @param Role             Role of HSTI data.   @param ImplementationID ImplementationID of HSTI data.                           NULL means find the first one match Role.   @param ByteIndex        Byte index of FeaturesVerified of HSTI data.   @param BitMask          Bit mask of FeaturesVerified of HSTI data.    @retval EFI_SUCCESS          The FeaturesVerified of HSTI data updated in AIP protocol.   @retval EFI_NOT_STARTED      There is not HSTI table with the Role and ImplementationID published in system.   @retval EFI_UNSUPPORTED      The ByteIndex is invalid. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|HstiLibSetFeaturesVerified
parameter_list|(
name|IN
name|UINT32
name|Role
parameter_list|,
name|IN
name|CHAR16
modifier|*
name|ImplementationID
parameter_list|,
name|OPTIONAL
name|IN
name|UINT32
name|ByteIndex
parameter_list|,
name|IN
name|UINT8
name|BitMask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Clear FeaturesVerified in published HSTI table.   This API will update the HSTI table with indicated Role and ImplementationID,   NULL ImplementationID means to find the first HSTI table with indicated Role.    @param Role             Role of HSTI data.   @param ImplementationID ImplementationID of HSTI data.                           NULL means find the first one match Role.   @param ByteIndex        Byte index of FeaturesVerified of HSTI data.   @param BitMask          Bit mask of FeaturesVerified of HSTI data.    @retval EFI_SUCCESS          The FeaturesVerified of HSTI data updated in AIP protocol.   @retval EFI_NOT_STARTED      There is not HSTI table with the Role and ImplementationID published in system.   @retval EFI_UNSUPPORTED      The ByteIndex is invalid. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|HstiLibClearFeaturesVerified
parameter_list|(
name|IN
name|UINT32
name|Role
parameter_list|,
name|IN
name|CHAR16
modifier|*
name|ImplementationID
parameter_list|,
name|OPTIONAL
name|IN
name|UINT32
name|ByteIndex
parameter_list|,
name|IN
name|UINT8
name|BitMask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Append ErrorString in published HSTI table.   This API will update the HSTI table with indicated Role and ImplementationID,   NULL ImplementationID means to find the first HSTI table with indicated Role.    @param Role             Role of HSTI data.   @param ImplementationID ImplementationID of HSTI data.                           NULL means find the first one match Role.   @param ErrorString      ErrorString of HSTI data.    @retval EFI_SUCCESS          The ErrorString of HSTI data is updated in AIP protocol.   @retval EFI_NOT_STARTED      There is not HSTI table with the Role and ImplementationID published in system.   @retval EFI_OUT_OF_RESOURCES There is not enough system resource to update ErrorString. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|HstiLibAppendErrorString
parameter_list|(
name|IN
name|UINT32
name|Role
parameter_list|,
name|IN
name|CHAR16
modifier|*
name|ImplementationID
parameter_list|,
name|OPTIONAL
name|IN
name|CHAR16
modifier|*
name|ErrorString
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Set a new ErrorString in published HSTI table.   This API will update the HSTI table with indicated Role and ImplementationID,   NULL ImplementationID means to find the first HSTI table with indicated Role.    @param Role             Role of HSTI data.   @param ImplementationID ImplementationID of HSTI data.                           NULL means find the first one match Role.   @param ErrorString      ErrorString of HSTI data.    @retval EFI_SUCCESS          The ErrorString of HSTI data is updated in AIP protocol.   @retval EFI_NOT_STARTED      There is not HSTI table with the Role and ImplementationID published in system.   @retval EFI_OUT_OF_RESOURCES There is not enough system resource to update ErrorString. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|HstiLibSetErrorString
parameter_list|(
name|IN
name|UINT32
name|Role
parameter_list|,
name|IN
name|CHAR16
modifier|*
name|ImplementationID
parameter_list|,
name|OPTIONAL
name|IN
name|CHAR16
modifier|*
name|ErrorString
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

