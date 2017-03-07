begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   CpuFlushTlb function for Ia32/X64 GCC.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   Portions copyright (c) 2008 - 2009, Apple Inc. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|<Library/BaseLib.h>
end_include

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
name|AsmWriteCr3
argument_list|(
name|AsmReadCr3
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

