begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file declares Read-only Variable Service2 PPI.   This ppi permits read-only access to the UEFI variable store during the PEI phase.  Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                               THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This PPI is introduced in PI Version 1.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PEI_READ_ONLY_VARIABLE2_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__PEI_READ_ONLY_VARIABLE2_PPI_H__
end_define

begin_define
define|#
directive|define
name|EFI_PEI_READ_ONLY_VARIABLE2_PPI_GUID
define|\
value|{ 0x2ab86ef5, 0xecb5, 0x4134, { 0xb5, 0x56, 0x38, 0x54, 0xca, 0x1f, 0xe1, 0xb4 } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_PEI_READ_ONLY_VARIABLE2_PPI
name|EFI_PEI_READ_ONLY_VARIABLE2_PPI
typedef|;
end_typedef

begin_comment
comment|/**   This service retrieves a variable's value using its name and GUID.    Read the specified variable from the UEFI variable store. If the Data    buffer is too small to hold the contents of the variable,    the error EFI_BUFFER_TOO_SMALL is returned and DataSize is set to the   required buffer size to obtain the data.    @param  This                  A pointer to this instance of the EFI_PEI_READ_ONLY_VARIABLE2_PPI.   @param  VariableName          A pointer to a null-terminated string that is the variable's name.   @param  VariableGuid          A pointer to an EFI_GUID that is the variable's GUID. The combination of                                 VariableGuid and VariableName must be unique.   @param  Attributes            If non-NULL, on return, points to the variable's attributes.   @param  DataSize              On entry, points to the size in bytes of the Data buffer.                                 On return, points to the size of the data returned in Data.   @param  Data                  Points to the buffer which will hold the returned variable value.    @retval EFI_SUCCESS           The variable was read successfully.   @retval EFI_NOT_FOUND         The variable could not be found.   @retval EFI_BUFFER_TOO_SMALL  The DataSize is too small for the resulting data.                                  DataSize is updated with the size required for                                  the specified variable.   @retval EFI_INVALID_PARAMETER VariableName, VariableGuid, DataSize or Data is NULL.   @retval EFI_DEVICE_ERROR      The variable could not be retrieved because of a device error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_GET_VARIABLE2
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_READ_ONLY_VARIABLE2_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|CONST
name|CHAR16
modifier|*
name|VariableName
parameter_list|,
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|VariableGuid
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Attributes
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|DataSize
parameter_list|,
name|OUT
name|VOID
modifier|*
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Return the next variable name and GUID.    This function is called multiple times to retrieve the VariableName    and VariableGuid of all variables currently available in the system.    On each call, the previous results are passed into the interface,    and, on return, the interface returns the data for the next    interface. When the entire variable list has been returned,    EFI_NOT_FOUND is returned.    @param  This              A pointer to this instance of the EFI_PEI_READ_ONLY_VARIABLE2_PPI.    @param  VariableNameSize  On entry, points to the size of the buffer pointed to by VariableName.                             On return, the size of the variable name buffer.   @param  VariableName      On entry, a pointer to a null-terminated string that is the variable's name.                             On return, points to the next variable's null-terminated name string.    @param  VariableGuid      On entry, a pointer to an EFI_GUID that is the variable's GUID.                              On return, a pointer to the next variable's GUID.    @retval EFI_SUCCESS           The variable was read successfully.   @retval EFI_NOT_FOUND         The variable could not be found.   @retval EFI_BUFFER_TOO_SMALL  The VariableNameSize is too small for the resulting                                 data. VariableNameSize is updated with the size                                 required for the specified variable.   @retval EFI_INVALID_PARAMETER VariableName, VariableGuid or                                 VariableNameSize is NULL.   @retval EFI_DEVICE_ERROR      The variable could not be retrieved because of a device error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_GET_NEXT_VARIABLE_NAME2
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_READ_ONLY_VARIABLE2_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|VariableNameSize
parameter_list|,
name|IN
name|OUT
name|CHAR16
modifier|*
name|VariableName
parameter_list|,
name|IN
name|OUT
name|EFI_GUID
modifier|*
name|VariableGuid
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This PPI provides a lightweight, read-only variant of the full EFI
end_comment

begin_comment
comment|/// variable services.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PEI_READ_ONLY_VARIABLE2_PPI
block|{
name|EFI_PEI_GET_VARIABLE2
name|GetVariable
decl_stmt|;
name|EFI_PEI_GET_NEXT_VARIABLE_NAME2
name|NextVariableName
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPeiReadOnlyVariable2PpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

