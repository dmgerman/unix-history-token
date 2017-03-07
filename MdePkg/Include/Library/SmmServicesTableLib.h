begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides a service to retrieve a pointer to the SMM Services Table.   Only available to SMM module types.  Copyright (c) 2009, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SMM_SERVICES_TABLE_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__SMM_SERVICES_TABLE_LIB_H__
end_define

begin_include
include|#
directive|include
file|<PiSmm.h>
end_include

begin_comment
comment|///
end_comment

begin_comment
comment|/// Cache pointer to the SMM Services Table
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
specifier|extern
name|EFI_SMM_SYSTEM_TABLE2
modifier|*
name|gSmst
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**   This function allows the caller to determine if the driver is executing in    System Management Mode(SMM).    This function returns TRUE if the driver is executing in SMM and FALSE if the    driver is not executing in SMM.    @retval  TRUE  The driver is executing in System Management Mode (SMM).   @retval  FALSE The driver is not executing in System Management Mode (SMM).   **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|InSmm
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

