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
comment|/**   Rotates a 32-bit integer left between 0 and 31 bits, filling the low bits   with the high bits that were rotated.    This function rotates the 32-bit value Operand to the left by Count bits. The   low Count bits are fill with the high Count bits of Operand. The rotated   value is returned.    If Count is greater than 31, then ASSERT().    @param  Operand The 32-bit operand to rotate left.   @param  Count   The number of bits to rotate left.    @return Operand<< Count  **/
end_comment

begin_function
name|UINT32
name|EFIAPI
name|LRotU32
parameter_list|(
name|IN
name|UINT32
name|Operand
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|Count
operator|<
literal|32
argument_list|)
expr_stmt|;
return|return
operator|(
name|Operand
operator|<<
name|Count
operator|)
operator||
operator|(
name|Operand
operator|>>
operator|(
literal|32
operator|-
name|Count
operator|)
operator|)
return|;
block|}
end_function

end_unit

