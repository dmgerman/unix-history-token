begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Defines the APIs that enable PEI services to work with    the underlying capsule capabilities of the platform.  Copyright (c) 2015, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.        THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This PPI is introduced in PI Version 1.4.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PEI_CAPSULE_PPI_H_
end_ifndef

begin_define
define|#
directive|define
name|_PEI_CAPSULE_PPI_H_
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the EFI_PEI_CAPSULE_PPI.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PEI_CAPSULE_PPI_GUID
define|\
value|{ \     0x3acf33ee, 0xd892, 0x40f4, {0xa2, 0xfc, 0x38, 0x54, 0xd2, 0xe1, 0x32, 0x3d } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Forward declaration for the EFI_PEI_CAPSULE_PPI.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_PEI_CAPSULE_PPI
name|EFI_PEI_CAPSULE_PPI
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Keep name backwards compatible before PI Version 1.4
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_PEI_CAPSULE_PPI
name|PEI_CAPSULE_PPI
typedef|;
end_typedef

begin_comment
comment|/**   Upon determining that there is a capsule to operate on, this service    will use a series of EFI_CAPSULE_BLOCK_DESCRIPTOR entries to determine    the current location of the various capsule fragments and coalesce them    into a contiguous region of system memory.       @param[in]  PeiServices   Pointer to the PEI Services Table.   @param[out] MemoryBase    Pointer to the base of a block of memory into which the buffers will be coalesced.                             On output, this variable will hold the base address                              of a coalesced capsule.   @param[out] MemorySize    Size of the memory region pointed to by MemoryBase.                             On output, this variable will contain the size of the                             coalesced capsule.    @retval EFI_NOT_FOUND          If: boot modecould not be determined, or the                                   boot mode is not flash-update, or the capsule descriptors were not found.    @retval EFI_BUFFER_TOO_SMALL   The capsule could not be coalesced in the provided memory region.    @retval EFI_SUCCESS            There was no capsule, or the capsule was processed successfully.   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_CAPSULE_COALESCE
function_decl|)
parameter_list|(
name|IN
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
modifier|*
name|MemoryBase
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|MemSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Determine if a capsule needs to be processed.    The means by which the presence of a capsule is determined is platform   specific. For example, an implementation could be driven by the presence    of a Capsule EFI Variable containing a list of EFI_CAPSULE_BLOCK_DESCRIPTOR    entries. If present, return EFI_SUCCESS, otherwise return EFI_NOT_FOUND.        @param[in] PeiServices   Pointer to the PEI Services Table.    @retval EFI_SUCCESS     If a capsule is available.   @retval EFI_NOT_FOUND   No capsule detected.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_CAPSULE_CHECK_CAPSULE_UPDATE
function_decl|)
parameter_list|(
name|IN
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The Capsule PPI service that gets called after memory is available. The   capsule coalesce function, which must be called first, returns a base   address and size. Once the memory init PEIM has discovered memory,    it should call this function and pass in the base address and size    returned by the Coalesce() function. Then this function can create a    capsule HOB and return.    @par Notes:     This function assumes it will not be called until the     actual capsule update.    @param[in] PeiServices   Pointer to the PEI Services Table.   @param[in] CapsuleBase   Address returned by the capsule coalesce function.    @param[in] CapsuleSize   Value returned by the capsule coalesce function.    @retval EFI_VOLUME_CORRUPTED   CapsuleBase does not appear to point to a                                  coalesced capsule.   @retval EFI_SUCCESS            Capsule HOB was created successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_CAPSULE_CREATE_STATE
function_decl|)
parameter_list|(
name|IN
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|VOID
modifier|*
name|CapsuleBase
parameter_list|,
name|IN
name|UINTN
name|CapsuleSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This PPI provides several services in PEI to work with the underlying
end_comment

begin_comment
comment|/// capsule capabilities of the platform.  These services include the ability
end_comment

begin_comment
comment|/// for PEI to coalesce a capsule from a scattered set of memory locations
end_comment

begin_comment
comment|/// into a contiguous space in memory, detect if a capsule is present for
end_comment

begin_comment
comment|/// processing, and once memory is available, create a HOB for the capsule.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PEI_CAPSULE_PPI
block|{
name|EFI_PEI_CAPSULE_COALESCE
name|Coalesce
decl_stmt|;
name|EFI_PEI_CAPSULE_CHECK_CAPSULE_UPDATE
name|CheckCapsuleUpdate
decl_stmt|;
name|EFI_PEI_CAPSULE_CREATE_STATE
name|CreateState
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|///
end_comment

begin_comment
comment|/// Keep name backwards compatible before PI Version 1.4
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gPeiCapsulePpiGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPeiCapsulePpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef _PEI_CAPSULE_PPI_H_
end_comment

end_unit

