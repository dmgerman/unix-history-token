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
comment|/**   Returns the bit position of the lowest bit set in a 64-bit value.    This function computes the bit position of the lowest bit set in the 64-bit   value specified by Operand. If Operand is zero, then -1 is returned.   Otherwise, a value between 0 and 63 is returned.    @param  Operand The 64-bit operand to evaluate.    @retval 0..63  The lowest bit set in Operand was found.   @retval -1     Operand is zero.   **/
end_comment

begin_function
name|INTN
name|EFIAPI
name|LowBitSet64
parameter_list|(
name|IN
name|UINT64
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
operator|(
name|Operand
operator|&
literal|1
operator|)
operator|==
literal|0
condition|;
name|BitIndex
operator|++
operator|,
name|Operand
operator|=
name|RShiftU64
argument_list|(
name|Operand
argument_list|,
literal|1
argument_list|)
control|)
empty_stmt|;
return|return
name|BitIndex
return|;
block|}
end_function

end_unit

