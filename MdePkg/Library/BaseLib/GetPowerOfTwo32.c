begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Math worker functions.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"BaseLibInternals.h"
end_include

begin_comment
comment|/**   Returns the value of the highest bit set in a 32-bit value. Equivalent to   1<< log2(x).    This function computes the value of the highest bit set in the 32-bit value   specified by Operand. If Operand is zero, then zero is returned.    @param  Operand The 32-bit operand to evaluate.    @return 1<< HighBitSet32(Operand)   @retval 0 Operand is zero.  **/
end_comment

begin_function
name|UINT32
name|EFIAPI
name|GetPowerOfTwo32
parameter_list|(
name|IN
name|UINT32
name|Operand
parameter_list|)
block|{
if|if
condition|(
literal|0
operator|==
name|Operand
condition|)
block|{
return|return
literal|0
return|;
block|}
return|return
literal|1ul
operator|<<
name|HighBitSet32
argument_list|(
name|Operand
argument_list|)
return|;
block|}
end_function

end_unit

