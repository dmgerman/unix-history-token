begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   AsmFlushCacheRange() function for IPF.    Copyright (c) 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"BaseLibInternals.h"
end_include

begin_comment
comment|/**   Flush a range of  cache lines in the cache coherency domain of the calling   CPU.    Flushes the cache lines specified by Address and Length.  If Address is not aligned    on a cache line boundary, then entire cache line containing Address is flushed.     If Address + Length is not aligned on a cache line boundary, then the entire cache    line containing Address + Length - 1 is flushed.  This function may choose to flush    the entire cache if that is more efficient than flushing the specified range.  If    Length is 0, the no cache lines are flushed.  Address is returned.      This function is only available on IPF.    If Length is greater than (MAX_ADDRESS - Address + 1), then ASSERT().    @param  Address The base address of the instruction lines to invalidate. If                   the CPU is in a physical addressing mode, then Address is a                   physical address. If the CPU is in a virtual addressing mode,                   then Address is a virtual address.    @param  Length  The number of bytes to invalidate from the instruction cache.    @return Address.  **/
end_comment

begin_function
name|VOID
modifier|*
name|EFIAPI
name|AsmFlushCacheRange
parameter_list|(
name|IN
name|VOID
modifier|*
name|Address
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|Length
operator|<=
name|MAX_ADDRESS
operator|-
operator|(
name|UINTN
operator|)
name|Address
operator|+
literal|1
argument_list|)
expr_stmt|;
return|return
name|InternalFlushCacheRange
argument_list|(
name|Address
argument_list|,
name|Length
argument_list|)
return|;
block|}
end_function

end_unit

