begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   AsmFlushCacheLine function    Copyright (c) 2006 - 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_comment
comment|/**   Flushes a cache line from all the instruction and data caches within the   coherency domain of the CPU.    Flushed the cache line specified by LinearAddress, and returns LinearAddress.   This function is only available on IA-32 and x64.    @param  LinearAddress The address of the cache line to flush. If the CPU is                         in a physical addressing mode, then LinearAddress is a                         physical address. If the CPU is in a virtual                         addressing mode, then LinearAddress is a virtual                         address.    @return LinearAddress **/
end_comment

begin_function
name|VOID
modifier|*
name|EFIAPI
name|AsmFlushCacheLine
parameter_list|(
name|IN
name|VOID
modifier|*
name|LinearAddress
parameter_list|)
block|{
comment|//
comment|// If the CPU does not support CLFLUSH instruction,
comment|// then promote flush range to flush entire cache.
comment|//
name|_asm
block|{
name|mov
name|eax
decl_stmt|, 1
name|cpuid
name|test
name|edx
decl_stmt|,
name|BIT19
name|jz
name|NoClflush
name|mov
name|eax
decl_stmt|,
name|dword
name|ptr
index|[
name|LinearAddress
index|]
name|clflush
index|[
name|eax
index|]
name|jmp
name|Done
name|NoClflush
range|:
name|wbinvd
name|Done
operator|:
block|}
return|return
name|LinearAddress
return|;
block|}
end_function

end_unit

