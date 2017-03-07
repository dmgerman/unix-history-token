begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Base Library CPU Functions for all architectures.    Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"BaseLibInternals.h"
end_include

begin_comment
comment|/**   Disables CPU interrupts and returns the interrupt state prior to the disable   operation.    @retval TRUE  CPU interrupts were enabled on entry to this call.   @retval FALSE CPU interrupts were disabled on entry to this call.  **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|SaveAndDisableInterrupts
parameter_list|(
name|VOID
parameter_list|)
block|{
name|BOOLEAN
name|InterruptState
decl_stmt|;
name|InterruptState
operator|=
name|GetInterruptState
argument_list|()
expr_stmt|;
name|DisableInterrupts
argument_list|()
expr_stmt|;
return|return
name|InterruptState
return|;
block|}
end_function

begin_comment
comment|/**   Set the current CPU interrupt state.    Sets the current CPU interrupt state to the state specified by   InterruptState. If InterruptState is TRUE, then interrupts are enabled. If   InterruptState is FALSE, then interrupts are disabled. InterruptState is   returned.    @param  InterruptState  TRUE if interrupts should be enabled. FALSE if                           interrupts should be disabled.    @return InterruptState  **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|SetInterruptState
parameter_list|(
name|IN
name|BOOLEAN
name|InterruptState
parameter_list|)
block|{
if|if
condition|(
name|InterruptState
condition|)
block|{
name|EnableInterrupts
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|DisableInterrupts
argument_list|()
expr_stmt|;
block|}
return|return
name|InterruptState
return|;
block|}
end_function

end_unit

