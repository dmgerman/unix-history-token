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
comment|/**   Switches the endianess of a 64-bit integer.    This function swaps the bytes in a 64-bit unsigned value to switch the value   from little endian to big endian or vice versa. The byte swapped value is   returned.    @param  Value A 64-bit unsigned value.    @return The byte swapped Value.  **/
end_comment

begin_function
name|UINT64
name|EFIAPI
name|SwapBytes64
parameter_list|(
name|IN
name|UINT64
name|Value
parameter_list|)
block|{
return|return
name|InternalMathSwapBytes64
argument_list|(
name|Value
argument_list|)
return|;
block|}
end_function

end_unit

