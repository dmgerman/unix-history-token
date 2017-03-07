begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   CpuFlushTlb function.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Flushes all the Translation Lookaside Buffers(TLB) entries in a CPU.    Flushes all the Translation Lookaside Buffers(TLB) entries in a CPU.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|CpuFlushTlb
parameter_list|(
name|VOID
parameter_list|)
block|{
name|_asm
block|{
name|mov
name|eax
decl_stmt|,
name|cr3
name|mov
name|cr3
decl_stmt|,
name|eax
block|}
block|}
end_function

end_unit

