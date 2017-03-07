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
comment|/**   Shifts a 64-bit integer right between 0 and 63 bits. This high bits are   filled with zeros. The shifted value is returned.    This function shifts the 64-bit value Operand to the right by Count bits. The   high Count bits are set to zero. The shifted value is returned.    If Count is greater than 63, then ASSERT().    @param  Operand The 64-bit operand to shift right.   @param  Count   The number of bits to shift right.    @return Operand>> Count.  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|RShiftU64
parameter_list|(
name|IN
name|UINT64
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
literal|64
argument_list|)
expr_stmt|;
return|return
name|InternalMathRShiftU64
argument_list|(
name|Operand
argument_list|,
name|Count
argument_list|)
return|;
block|}
end_function

end_unit

