begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   IA-32/x64 GetInterruptState()    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"BaseLibInternals.h"
end_include

begin_comment
comment|/**   Retrieves the current CPU interrupt state.    Returns TRUE is interrupts are currently enabled. Otherwise   returns FALSE.    @retval TRUE  CPU interrupts are enabled.   @retval FALSE CPU interrupts are disabled.  **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|GetInterruptState
parameter_list|(
name|VOID
parameter_list|)
block|{
name|IA32_EFLAGS32
name|EFlags
decl_stmt|;
name|EFlags
operator|.
name|UintN
operator|=
name|AsmReadEflags
argument_list|()
expr_stmt|;
return|return
call|(
name|BOOLEAN
call|)
argument_list|(
literal|1
operator|==
name|EFlags
operator|.
name|Bits
operator|.
name|IF
argument_list|)
return|;
block|}
end_function

end_unit

