begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   AsmReadMsr64 function    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Returns a 64-bit Machine Specific Register(MSR).    Reads and returns the 64-bit MSR specified by Index. No parameter checking is   performed on Index, and some Index values may cause CPU exceptions. The   caller must either guarantee that Index is valid, or the caller must set up   exception handlers to catch the exceptions. This function is only available   on IA-32 and x64.    @param  Index The 32-bit MSR index to read.    @return The value of the MSR identified by Index.  **/
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
name|_asm
block|{
name|mov
name|ecx
decl_stmt|,
name|Index
name|rdmsr
block|}
block|}
end_function

end_unit

