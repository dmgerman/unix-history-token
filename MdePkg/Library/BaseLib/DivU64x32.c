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
comment|/**   Divides a 64-bit unsigned integer by a 32-bit unsigned integer and generates   a 64-bit unsigned result.    This function divides the 64-bit unsigned value Dividend by the 32-bit   unsigned value Divisor and generates a 64-bit unsigned quotient. This   function returns the 64-bit unsigned quotient.    If Divisor is 0, then ASSERT().    @param  Dividend  A 64-bit unsigned value.   @param  Divisor   A 32-bit unsigned value.    @return Dividend / Divisor  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|DivU64x32
parameter_list|(
name|IN
name|UINT64
name|Dividend
parameter_list|,
name|IN
name|UINT32
name|Divisor
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|Divisor
operator|!=
literal|0
argument_list|)
expr_stmt|;
return|return
name|InternalMathDivU64x32
argument_list|(
name|Dividend
argument_list|,
name|Divisor
argument_list|)
return|;
block|}
end_function

end_unit

