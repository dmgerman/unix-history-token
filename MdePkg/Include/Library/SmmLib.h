begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Library class name: SmmLib      SMM Library Services that abstracts both S/W SMI generation and detection.     Copyright (c) 2007 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.          **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SMM_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__SMM_LIB_H__
end_define

begin_comment
comment|/**   Triggers an SMI at boot time.      This function triggers a software SMM interrupt at boot time.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|TriggerBootServiceSoftwareSmi
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Triggers an SMI at run time.      This function triggers a software SMM interrupt at run time.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|TriggerRuntimeSoftwareSmi
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Test if a boot time software SMI happened.      This function tests if a software SMM interrupt happened. If a software SMM interrupt happened and   it was triggered at boot time, it returns TRUE. Otherwise, it returns FALSE.    @retval TRUE   A software SMI triggered at boot time happened.   @retval FLASE  No software SMI happened, or the software SMI was triggered at run time.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|IsBootServiceSoftwareSmi
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Test if a run time software SMI happened.      This function tests if a software SMM interrupt happened. If a software SMM interrupt happened and   it was triggered at run time, it returns TRUE. Otherwise, it returns FALSE.    @retval TRUE   A software SMI triggered at run time happened.   @retval FLASE  No software SMI happened or the software SMI was triggered at boot time.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|IsRuntimeSoftwareSmi
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Clear APM SMI Status Bit; Set the EOS bit.     **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|ClearSmi
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

