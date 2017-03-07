begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Math worker functions.    Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"BaseLibInternals.h"
end_include

begin_comment
comment|/**   Returns the value of the highest bit set in a 64-bit value. Equivalent to   1<< log2(x).    This function computes the value of the highest bit set in the 64-bit value   specified by Operand. If Operand is zero, then zero is returned.    @param  Operand The 64-bit operand to evaluate.    @return 1<< HighBitSet64(Operand)   @retval 0 Operand is zero.  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|GetPowerOfTwo64
parameter_list|(
name|IN
name|UINT64
name|Operand
parameter_list|)
block|{
if|if
condition|(
name|Operand
operator|==
literal|0
condition|)
block|{
return|return
literal|0
return|;
block|}
return|return
name|LShiftU64
argument_list|(
literal|1
argument_list|,
operator|(
name|UINTN
operator|)
name|HighBitSet64
argument_list|(
name|Operand
argument_list|)
argument_list|)
return|;
block|}
end_function

end_unit

