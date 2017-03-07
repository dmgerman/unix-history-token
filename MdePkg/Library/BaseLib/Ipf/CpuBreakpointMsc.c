begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Base Library CPU functions for Itanium    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"BaseLibInternals.h"
end_include

begin_pragma
pragma|#
directive|pragma
name|intrinsic
name|(
name|_enable
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|intrinsic
name|(
name|_disable
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|intrinsic
name|(
name|__break
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|intrinsic
name|(
name|__mfa
name|)
end_pragma

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
name|__break
argument_list|(
literal|0
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
block|{
name|__mfa
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Disables CPU interrupts.    Disables CPU interrupts.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|DisableInterrupts
parameter_list|(
name|VOID
parameter_list|)
block|{
name|_disable
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Enables CPU interrupts.    Enables CPU interrupts.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|EnableInterrupts
parameter_list|(
name|VOID
parameter_list|)
block|{
name|_enable
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Enables CPU interrupts for the smallest window required to capture any   pending interrupts.    Enables CPU interrupts for the smallest window required to capture any   pending interrupts.  **/
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

end_unit

