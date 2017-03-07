begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Base Library CPU Functions for EBC    Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"BaseLibInternals.h"
end_include

begin_function_decl
specifier|extern
name|UINT64
name|_break
parameter_list|(
name|CHAR8
name|BreakCode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Generates a breakpoint on the CPU.    Generates a breakpoint on the CPU. The breakpoint must be implemented such   that code can resume normal execution after the breakpoint.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|CpuBreakpoint
parameter_list|(
name|VOID
parameter_list|)
block|{
name|_break
argument_list|(
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Used to serialize load and store operations.    All loads and stores that proceed calls to this function are guaranteed to be   globally visible when this function returns.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|MemoryFence
parameter_list|(
name|VOID
parameter_list|)
block|{ }
end_function

begin_comment
comment|/**   Disables CPU interrupts.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|DisableInterrupts
parameter_list|(
name|VOID
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Enables CPU interrupts.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|EnableInterrupts
parameter_list|(
name|VOID
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Retrieves the current CPU interrupt state.    Returns TRUE means interrupts are currently enabled. Otherwise,   returns FALSE.    @retval TRUE  CPU interrupts are enabled.   @retval FALSE CPU interrupts are disabled.  **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|GetInterruptState
parameter_list|(
name|VOID
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
return|return
name|FALSE
return|;
block|}
end_function

begin_comment
comment|/**   Enables CPU interrupts for the smallest window required to capture any   pending interrupts.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|EnableDisableInterrupts
parameter_list|(
name|VOID
parameter_list|)
block|{
name|EnableInterrupts
argument_list|()
expr_stmt|;
name|DisableInterrupts
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Requests CPU to pause for a short period of time.    Requests CPU to pause for a short period of time. Typically used in MP   systems to prevent memory starvation while waiting for a spin lock.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|CpuPause
parameter_list|(
name|VOID
parameter_list|)
block|{ }
end_function

end_unit

