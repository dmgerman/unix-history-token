begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   CpuBreakpoint function.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Microsoft Visual Studio 7.1 Function Prototypes for I/O Intrinsics. **/
end_comment

begin_function_decl
name|unsigned
name|__int64
name|__readmsr
parameter_list|(
name|int
specifier|register
parameter_list|)
function_decl|;
end_function_decl

begin_pragma
pragma|#
directive|pragma
name|intrinsic
name|(
name|__readmsr
name|)
end_pragma

begin_comment
comment|/**   Read data to MSR.    @param  Index                Register index of MSR.    @return Value read from MSR.  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|AsmReadMsr64
parameter_list|(
name|IN
name|UINT32
name|Index
parameter_list|)
block|{
return|return
name|__readmsr
argument_list|(
name|Index
argument_list|)
return|;
block|}
end_function

end_unit

