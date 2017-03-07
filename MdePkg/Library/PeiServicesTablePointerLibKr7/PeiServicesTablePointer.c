begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   PEI Services Table Pointer Library implementation for IPF that uses Kernel   Register 7 to store the pointer.    Copyright (c) 2006 - 2014, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|<PiPei.h>
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
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
decl_stmt|;
name|PeiServices
operator|=
operator|(
name|CONST
name|EFI_PEI_SERVICES
operator|*
operator|*
operator|)
operator|(
name|UINTN
operator|)
name|AsmReadKr7
argument_list|()
expr_stmt|;
name|ASSERT
argument_list|(
name|PeiServices
operator|!=
name|NULL
argument_list|)
expr_stmt|;
return|return
name|PeiServices
return|;
block|}
end_function

begin_comment
comment|/**   Caches a pointer PEI Services Table.      Caches the pointer to the PEI Services Table specified by PeiServicesTablePointer    in a CPU specific manner as specified in the CPU binding section of the Platform Initialization    Pre-EFI Initialization Core Interface Specification.    The function set the pointer of PEI services in KR7 register    according to PI specification.      If PeiServicesTablePointer is NULL, then ASSERT().      @param    PeiServicesTablePointer   The address of PeiServices pointer. **/
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
name|AsmWriteKr7
argument_list|(
operator|(
name|UINT64
operator|)
operator|(
name|UINTN
operator|)
name|PeiServicesTablePointer
argument_list|)
expr_stmt|;
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
return|return;
block|}
end_function

end_unit

