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
comment|/**   Multiplies a 64-bit signed integer by a 64-bit signed integer and generates a   64-bit signed result.    This function multiplies the 64-bit signed value Multiplicand by the 64-bit   signed value Multiplier and generates a 64-bit signed result. This 64-bit   signed result is returned.    @param  Multiplicand  A 64-bit signed value.   @param  Multiplier    A 64-bit signed value.    @return Multiplicand * Multiplier.  **/
end_comment

begin_function
name|INT64
name|EFIAPI
name|MultS64x64
parameter_list|(
name|IN
name|INT64
name|Multiplicand
parameter_list|,
name|IN
name|INT64
name|Multiplier
parameter_list|)
block|{
return|return
operator|(
name|INT64
operator|)
name|MultU64x64
argument_list|(
operator|(
name|UINT64
operator|)
name|Multiplicand
argument_list|,
operator|(
name|UINT64
operator|)
name|Multiplier
argument_list|)
return|;
block|}
end_function

end_unit

