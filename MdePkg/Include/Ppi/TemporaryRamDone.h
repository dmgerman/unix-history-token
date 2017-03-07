begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file declares Temporary RAM Done PPI.   The PPI that provides a service to disable the use of Temporary RAM.    Copyright (c) 2013, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This PPI is introduced in PI Version 1.2.1.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TEMPORARY_RAM_DONE_H__
end_ifndef

begin_define
define|#
directive|define
name|__TEMPORARY_RAM_DONE_H__
end_define

begin_define
define|#
directive|define
name|EFI_PEI_TEMPORARY_RAM_DONE_PPI_GUID
define|\
value|{ 0xceab683c, 0xec56, 0x4a2d, { 0xa9, 0x6, 0x40, 0x53, 0xfa, 0x4e, 0x9c, 0x16 } }
end_define

begin_comment
comment|/**   TemporaryRamDone() disables the use of Temporary RAM. If present, this service is invoked   by the PEI Foundation after the EFI_PEI_PERMANANT_MEMORY_INSTALLED_PPI is installed.    @retval EFI_SUCCESS           Use of Temporary RAM was disabled.   @retval EFI_INVALID_PARAMETER Temporary RAM could not be disabled.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_TEMPORARY_RAM_DONE
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
comment|/// This is an optional PPI that may be produced by SEC or a PEIM. If present, it provide a service to
end_comment

begin_comment
comment|/// disable the use of Temporary RAM. This service may only be called by the PEI Foundation after the
end_comment

begin_comment
comment|/// transition from Temporary RAM to Permanent RAM is complete. This PPI provides an alternative
end_comment

begin_comment
comment|/// to the Temporary RAM Migration PPI for system architectures that allow Temporary RAM and
end_comment

begin_comment
comment|/// Permanent RAM to be enabled and accessed at the same time with no side effects.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_PEI_TEMPORARY_RAM_DONE_PPI
block|{
name|EFI_PEI_TEMPORARY_RAM_DONE
name|TemporaryRamDone
decl_stmt|;
block|}
name|EFI_PEI_TEMPORARY_RAM_DONE_PPI
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiTemporaryRamDonePpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

