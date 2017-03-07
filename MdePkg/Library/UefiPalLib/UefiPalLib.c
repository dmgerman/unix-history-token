begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   PAL Library implementation retrieving the PAL Entry Point from the SAL System Table   register in the EFI System Confguration Table.    Copyright (c) 2007 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials are   licensed and made available under the terms and conditions of   the BSD License which accompanies this distribution.  The full   text of the license may be found at   http://opensource.org/licenses/bsd-license.php.      THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|<PiDxe.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/Sal.h>
end_include

begin_include
include|#
directive|include
file|<Library/UefiLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/BaseLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_include
include|#
directive|include
file|<Guid/SalSystemTable.h>
end_include

begin_decl_stmt
name|UINT64
name|mPalProcEntry
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**   Makes a PAL procedure call.    This is a wrapper function to make a PAL procedure call.  Based on the Index value,   this API will make static or stacked PAL call. Architected procedures may be designated   as required or optional.  If a PAL procedure is specified as optional, a unique return   code of 0xFFFFFFFFFFFFFFFF is returned in the Status field of the PAL_CALL_RETURN structure.   This indicates that the procedure is not present in this PAL implementation.  It is the   caller's responsibility to check for this return code after calling any optional PAL   procedure. No parameter checking is performed on the 4 input parameters, but there are   some common rules that the caller should follow when making a PAL call.  Any address   passed to PAL as buffers for return parameters must be 8-byte aligned.  Unaligned addresses   may cause undefined results.  For those parameters defined as reserved or some fields   defined as reserved must be zero filled or the invalid argument return value may be   returned or undefined result may occur during the execution of the procedure.   This function is only available on IPF.    @param Index  The PAL procedure Index number.   @param Arg2   The 2nd parameter for PAL procedure calls.   @param Arg3   The 3rd parameter for PAL procedure calls.   @param Arg4   The 4th parameter for PAL procedure calls.    @return Structure returned from the PAL Call procedure, including the status and return value.  **/
end_comment

begin_function
name|PAL_CALL_RETURN
name|EFIAPI
name|PalCall
parameter_list|(
name|IN
name|UINT64
name|Index
parameter_list|,
name|IN
name|UINT64
name|Arg2
parameter_list|,
name|IN
name|UINT64
name|Arg3
parameter_list|,
name|IN
name|UINT64
name|Arg4
parameter_list|)
block|{
comment|//
comment|// mPalProcEntry is initialized in library constructor as PAL entry.
comment|//
return|return
name|AsmPalCall
argument_list|(
name|mPalProcEntry
argument_list|,
name|Index
argument_list|,
name|Arg2
argument_list|,
name|Arg3
argument_list|,
name|Arg4
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**   The constructor function of UEFI Pal Lib.    The constructor function looks up the SAL System Table in the EFI System Configuration   Table. Once the SAL System Table is found, the PAL Entry Point in the SAL System Table   will be derived and stored into a global variable for library usage.   It will ASSERT() if the SAL System Table cannot be found or the data in the SAL System   Table is not the valid data.    @param  ImageHandle   The firmware allocated handle for the EFI image.   @param  SystemTable   A pointer to the EFI System Table.    @retval EFI_SUCCESS   The constructor always returns EFI_SUCCESS.  **/
end_comment

begin_function
name|EFI_STATUS
name|EFIAPI
name|UefiPalLibConstructor
parameter_list|(
name|IN
name|EFI_HANDLE
name|ImageHandle
parameter_list|,
name|IN
name|EFI_SYSTEM_TABLE
modifier|*
name|SystemTable
parameter_list|)
block|{
name|EFI_STATUS
name|Status
decl_stmt|;
name|SAL_ST_ENTRY_POINT_DESCRIPTOR
modifier|*
name|SalStEntryDes
decl_stmt|;
name|SAL_SYSTEM_TABLE_HEADER
modifier|*
name|SalSystemTable
decl_stmt|;
name|Status
operator|=
name|EfiGetSystemConfigurationTable
argument_list|(
operator|&
name|gEfiSalSystemTableGuid
argument_list|,
operator|(
name|VOID
operator|*
operator|*
operator|)
operator|&
name|SalSystemTable
argument_list|)
expr_stmt|;
name|ASSERT_EFI_ERROR
argument_list|(
name|Status
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|SalSystemTable
operator|!=
name|NULL
argument_list|)
expr_stmt|;
comment|//
comment|// Check the first entry of SAL System Table,
comment|// because the SAL entry is in ascending order with the entry type,
comment|// the type 0 entry should be the first if exist.
comment|//
name|SalStEntryDes
operator|=
operator|(
name|SAL_ST_ENTRY_POINT_DESCRIPTOR
operator|*
operator|)
operator|(
name|SalSystemTable
operator|+
literal|1
operator|)
expr_stmt|;
comment|//
comment|// Assure the SAL ENTRY Type is 0
comment|//
name|ASSERT
argument_list|(
name|SalStEntryDes
operator|->
name|Type
operator|==
name|EFI_SAL_ST_ENTRY_POINT
argument_list|)
expr_stmt|;
name|mPalProcEntry
operator|=
name|SalStEntryDes
operator|->
name|PalProcEntry
expr_stmt|;
comment|//
comment|// Make sure the PalCallAddress has the valid value
comment|//
name|ASSERT
argument_list|(
name|mPalProcEntry
operator|!=
literal|0
argument_list|)
expr_stmt|;
return|return
name|EFI_SUCCESS
return|;
block|}
end_function

end_unit

