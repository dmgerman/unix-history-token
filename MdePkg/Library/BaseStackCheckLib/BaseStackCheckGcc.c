begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file  Base Stack Check library for GCC/clang.   Use -fstack-protector-all compiler flag to make the compiler insert the  __stack_chk_guard "canary" value into the stack and check the value prior  to exiting the function. If the "canary" is overwritten __stack_chk_fail()  is called. This is GCC specific code.   Copyright (c) 2012, Apple Inc. All rights reserved.<BR>  This program and the accompanying materials  are licensed and made available under the terms and conditions of the BSD License  which accompanies this distribution.  The full text of the license may be found at  http://opensource.org/licenses/bsd-license.php.   THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|<Base.h>
end_include

begin_include
include|#
directive|include
file|<Library/BaseLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/PcdLib.h>
end_include

begin_comment
comment|/// "canary" value that is inserted by the compiler into the stack frame.
end_comment

begin_decl_stmt
name|VOID
modifier|*
name|__stack_chk_guard
init|=
operator|(
name|VOID
operator|*
operator|)
literal|0x0AFF
decl_stmt|;
end_decl_stmt

begin_comment
comment|// If ASLR was enabled we could use
end_comment

begin_comment
comment|//void (*__stack_chk_guard)(void) = __stack_chk_fail;
end_comment

begin_comment
comment|/**  Error path for compiler generated stack "canary" value check code. If the  stack canary has been overwritten this function gets called on exit of the  function. **/
end_comment

begin_function
name|VOID
name|__stack_chk_fail
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINT8
name|DebugPropertyMask
decl_stmt|;
name|DEBUG
argument_list|(
operator|(
name|DEBUG_ERROR
operator|,
literal|"STACK FAULT: Buffer Overflow in function %a.\n"
operator|,
name|__builtin_return_address
argument_list|(
literal|0
argument_list|)
operator|)
argument_list|)
expr_stmt|;
comment|//
comment|// Generate a Breakpoint, DeadLoop, or NOP based on PCD settings even if
comment|// BaseDebugLibNull is in use.
comment|//
name|DebugPropertyMask
operator|=
name|PcdGet8
argument_list|(
name|PcdDebugPropertyMask
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|DebugPropertyMask
operator|&
name|DEBUG_PROPERTY_ASSERT_BREAKPOINT_ENABLED
operator|)
operator|!=
literal|0
condition|)
block|{
name|CpuBreakpoint
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|DebugPropertyMask
operator|&
name|DEBUG_PROPERTY_ASSERT_DEADLOOP_ENABLED
operator|)
operator|!=
literal|0
condition|)
block|{
name|CpuDeadLoop
argument_list|()
expr_stmt|;
block|}
block|}
end_function

end_unit

