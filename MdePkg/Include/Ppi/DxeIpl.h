begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file declares DXE Initial Program Load PPI.   When the PEI core is done it calls the DXE IPL PPI to load the DXE Foundation.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This PPI is introduced in PI Version 1.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DXE_IPL_H__
end_ifndef

begin_define
define|#
directive|define
name|__DXE_IPL_H__
end_define

begin_define
define|#
directive|define
name|EFI_DXE_IPL_PPI_GUID
define|\
value|{ \     0xae8ce5d, 0xe448, 0x4437, {0xa8, 0xd7, 0xeb, 0xf5, 0xf1, 0x94, 0xf7, 0x31 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_DXE_IPL_PPI
name|EFI_DXE_IPL_PPI
typedef|;
end_typedef

begin_comment
comment|/**   The architectural PPI that the PEI Foundation invokes when    there are no additional PEIMs to invoke.    This function is invoked by the PEI Foundation.   The PEI Foundation will invoke this service when there are   no additional PEIMs to invoke in the system.   If this PPI does not exist, it is an error condition and   an ill-formed firmware set. The DXE IPL PPI should never   return after having been invoked by the PEI Foundation.   The DXE IPL PPI can do many things internally, including the following:     - Invoke the DXE entry point from a firmware volume     - Invoke the recovery processing modules     - Invoke the S3 resume modules    @param  This           Pointer to the DXE IPL PPI instance   @param  PeiServices    Pointer to the PEI Services Table.   @param  HobList        Pointer to the list of Hand-Off Block (HOB) entries.    @retval EFI_SUCCESS    Upon this return code, the PEI Foundation should enter                          some exception handling.Under normal circumstances,                           the DXE IPL PPI should not return.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DXE_IPL_ENTRY
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_DXE_IPL_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|EFI_PEI_HOB_POINTERS
name|HobList
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Final service to be invoked by the PEI Foundation.
end_comment

begin_comment
comment|/// The DXE IPL PPI is responsible for locating and loading the DXE Foundation.
end_comment

begin_comment
comment|/// The DXE IPL PPI may use PEI services to locate and load the DXE Foundation.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_DXE_IPL_PPI
block|{
name|EFI_DXE_IPL_ENTRY
name|Entry
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDxeIplPpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

