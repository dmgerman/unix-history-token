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
comment|/**   Returns the bit position of the lowest bit set in a 32-bit value.    This function computes the bit position of the lowest bit set in the 32-bit   value specified by Operand. If Operand is zero, then -1 is returned.   Otherwise, a value between 0 and 31 is returned.    @param  Operand The 32-bit operand to evaluate.    @retval 0..31  The lowest bit set in Operand was found.   @retval -1     Operand is zero.  **/
end_comment

begin_function
name|INTN
name|EFIAPI
name|LowBitSet32
parameter_list|(
name|IN
name|UINT32
name|Operand
parameter_list|)
block|{
name|INTN
name|BitIndex
decl_stmt|;
if|if
condition|(
name|Operand
operator|==
literal|0
condition|)
block|{
return|return
operator|-
literal|1
return|;
block|}
for|for
control|(
name|BitIndex
operator|=
literal|0
init|;
literal|0
operator|==
operator|(
name|Operand
operator|&
literal|1
operator|)
condition|;
name|BitIndex
operator|++
operator|,
name|Operand
operator|>>=
literal|1
control|)
empty_stmt|;
return|return
name|BitIndex
return|;
block|}
end_function

end_unit

