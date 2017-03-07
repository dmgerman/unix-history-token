begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   CpuBreakpoint function.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Microsoft Visual Studio 7.1 Function Prototypes for I/O Intrinsics. **/
end_comment

begin_function_decl
name|void
name|__debugbreak
parameter_list|()
function_decl|;
end_function_decl

begin_pragma
pragma|#
directive|pragma
name|intrinsic
name|(
name|__debugbreak
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
name|__debugbreak
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

