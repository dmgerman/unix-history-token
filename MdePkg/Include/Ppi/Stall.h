begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file declares Stall PPI.    This ppi abstracts the blocking stall service to other agents.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This PPI is introduced in PI Version 1.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STALL_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__STALL_PPI_H__
end_define

begin_define
define|#
directive|define
name|EFI_PEI_STALL_PPI_GUID
define|\
value|{ 0x1f4c6f90, 0xb06b, 0x48d8, {0xa2, 0x01, 0xba, 0xe5, 0xf1, 0xcd, 0x7d, 0x56 } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_PEI_STALL_PPI
name|EFI_PEI_STALL_PPI
typedef|;
end_typedef

begin_comment
comment|/**   The Stall() function provides a blocking stall for at least the number    of microseconds stipulated in the final argument of the API.    @param  PeiServices    An indirect pointer to the PEI Services Table                          published by the PEI Foundation.   @param  This           Pointer to the local data for the interface.   @param  Microseconds   Number of microseconds for which to stall.    @retval EFI_SUCCESS    The service provided at least the required delay.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_STALL
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
name|CONST
name|EFI_PEI_STALL_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|Microseconds
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This service provides a simple, blocking stall with platform-specific resolution.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PEI_STALL_PPI
block|{
comment|///
comment|/// The resolution in microseconds of the stall services.
comment|///
name|UINTN
name|Resolution
decl_stmt|;
name|EFI_PEI_STALL
name|Stall
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPeiStallPpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

