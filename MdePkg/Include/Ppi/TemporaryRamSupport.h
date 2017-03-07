begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file declares Temporary RAM Support PPI.   This Ppi provides the service that migrates temporary RAM into permanent memory.    Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This PPI is introduced in PI Version 1.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TEMPORARY_RAM_SUPPORT_H__
end_ifndef

begin_define
define|#
directive|define
name|__TEMPORARY_RAM_SUPPORT_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note: The GUID name EFI_PEI_TEMPORARY_RAM_SUPPORT_PPI_GUID is different from the current
end_comment

begin_comment
comment|///       PI 1.2 spec.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PEI_TEMPORARY_RAM_SUPPORT_PPI_GUID
define|\
value|{ 0xdbe23aa9, 0xa345, 0x4b97, {0x85, 0xb6, 0xb2, 0x26, 0xf1, 0x61, 0x73, 0x89} }
end_define

begin_comment
comment|/**   This service of the EFI_PEI_TEMPORARY_RAM_SUPPORT_PPI that migrates temporary RAM into   permanent memory.    @param PeiServices            Pointer to the PEI Services Table.   @param TemporaryMemoryBase    Source Address in temporary memory from which the SEC or PEIM will copy the                                 Temporary RAM contents.   @param PermanentMemoryBase    Destination Address in permanent memory into which the SEC or PEIM will copy the                                 Temporary RAM contents.   @param CopySize               Amount of memory to migrate from temporary to permanent memory.    @retval EFI_SUCCESS           The data was successfully returned.   @retval EFI_INVALID_PARAMETER PermanentMemoryBase + CopySize> TemporaryMemoryBase when                                 TemporaryMemoryBase> PermanentMemoryBase.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|TEMPORARY_RAM_MIGRATION
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|EFI_PHYSICAL_ADDRESS
name|TemporaryMemoryBase
parameter_list|,
name|IN
name|EFI_PHYSICAL_ADDRESS
name|PermanentMemoryBase
parameter_list|,
name|IN
name|UINTN
name|CopySize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This service abstracts the ability to migrate contents of the platform early memory store.
end_comment

begin_comment
comment|/// Note: The name EFI_PEI_TEMPORARY_RAM_SUPPORT_PPI is different from the current PI 1.2 spec.
end_comment

begin_comment
comment|///       This PPI was optional.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|TEMPORARY_RAM_MIGRATION
name|TemporaryRamMigration
decl_stmt|;
block|}
name|EFI_PEI_TEMPORARY_RAM_SUPPORT_PPI
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiTemporaryRamSupportPpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

