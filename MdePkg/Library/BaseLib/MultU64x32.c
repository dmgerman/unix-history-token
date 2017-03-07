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
comment|/**   Multiplies a 64-bit unsigned integer by a 32-bit unsigned integer and   generates a 64-bit unsigned result.    This function multiplies the 64-bit unsigned value Multiplicand by the 32-bit   unsigned value Multiplier and generates a 64-bit unsigned result. This 64-   bit unsigned result is returned.    @param  Multiplicand  A 64-bit unsigned value.   @param  Multiplier    A 32-bit unsigned value.    @return Multiplicand * Multiplier.  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|MultU64x32
parameter_list|(
name|IN
name|UINT64
name|Multiplicand
parameter_list|,
name|IN
name|UINT32
name|Multiplier
parameter_list|)
block|{
name|UINT64
name|Result
decl_stmt|;
name|Result
operator|=
name|InternalMathMultU64x32
argument_list|(
name|Multiplicand
argument_list|,
name|Multiplier
argument_list|)
expr_stmt|;
return|return
name|Result
return|;
block|}
end_function

end_unit

