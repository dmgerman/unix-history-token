begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   PEI Services Table Pointer Library.      This library is used for PEIM which does executed from flash device directly but   executed in memory.    Copyright (c) 2006 - 2014, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|<PiPei.h>
end_include

begin_include
include|#
directive|include
file|<Library/PeiServicesTablePointerLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_decl_stmt
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|gPeiServices
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**   Caches a pointer PEI Services Table.      Caches the pointer to the PEI Services Table specified by PeiServicesTablePointer    in a CPU specific manner as specified in the CPU binding section of the Platform Initialization    Pre-EFI Initialization Core Interface Specification.       If PeiServicesTablePointer is NULL, then ASSERT().      @param    PeiServicesTablePointer   The address of PeiServices pointer. **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|SetPeiServicesTablePointer
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServicesTablePointer
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|PeiServicesTablePointer
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|gPeiServices
operator|=
name|PeiServicesTablePointer
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Retrieves the cached value of the PEI Services Table pointer.    Returns the cached value of the PEI Services Table pointer in a CPU specific manner    as specified in the CPU binding section of the Platform Initialization Pre-EFI    Initialization Core Interface Specification.      If the cached PEI Services Table pointer is NULL, then ASSERT().    @return  The pointer to PeiServices.  **/
end_comment

begin_function
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|EFIAPI
name|GetPeiServicesTablePointer
parameter_list|(
name|VOID
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|gPeiServices
operator|!=
name|NULL
argument_list|)
expr_stmt|;
return|return
name|gPeiServices
return|;
block|}
end_function

begin_comment
comment|/**   The constructor function caches the pointer to PEI services.      The constructor function caches the pointer to PEI services.   It will always return EFI_SUCCESS.    @param  FileHandle   The handle of FFS header the loaded driver.   @param  PeiServices  The pointer to the PEI services.    @retval EFI_SUCCESS  The constructor always returns EFI_SUCCESS.  **/
end_comment

begin_function
name|EFI_STATUS
name|EFIAPI
name|PeiServicesTablePointerLibConstructor
parameter_list|(
name|IN
name|EFI_PEI_FILE_HANDLE
name|FileHandle
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|)
block|{
name|gPeiServices
operator|=
name|PeiServices
expr_stmt|;
return|return
name|EFI_SUCCESS
return|;
block|}
end_function

begin_comment
comment|/**   Perform CPU specific actions required to migrate the PEI Services Table    pointer from temporary RAM to permanent RAM.    For IA32 CPUs, the PEI Services Table pointer is stored in the 4 bytes    immediately preceding the Interrupt Descriptor Table (IDT) in memory.   For X64 CPUs, the PEI Services Table pointer is stored in the 8 bytes    immediately preceding the Interrupt Descriptor Table (IDT) in memory.   For Itanium and ARM CPUs, a the PEI Services Table Pointer is stored in   a dedicated CPU register.  This means that there is no memory storage    associated with storing the PEI Services Table pointer, so no additional    migration actions are required for Itanium or ARM CPUs.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|MigratePeiServicesTablePointer
parameter_list|(
name|VOID
parameter_list|)
block|{
comment|//
comment|//  PEI Services Table pointer is cached in the global variable. No additional
comment|//  migration actions are required.
comment|//
return|return;
block|}
end_function

end_unit

