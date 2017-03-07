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
comment|/**   Switches the endianess of a 32-bit integer.    This function swaps the bytes in a 32-bit unsigned value to switch the value   from little endian to big endian or vice versa. The byte swapped value is   returned.    @param  Value A 32-bit unsigned value.    @return The byte swapped Value.  **/
end_comment

begin_function
name|UINT32
name|EFIAPI
name|SwapBytes32
parameter_list|(
name|IN
name|UINT32
name|Value
parameter_list|)
block|{
name|UINT32
name|LowerBytes
decl_stmt|;
name|UINT32
name|HigherBytes
decl_stmt|;
name|LowerBytes
operator|=
operator|(
name|UINT32
operator|)
name|SwapBytes16
argument_list|(
operator|(
name|UINT16
operator|)
name|Value
argument_list|)
expr_stmt|;
name|HigherBytes
operator|=
operator|(
name|UINT32
operator|)
name|SwapBytes16
argument_list|(
call|(
name|UINT16
call|)
argument_list|(
name|Value
operator|>>
literal|16
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|LowerBytes
operator|<<
literal|16
operator||
name|HigherBytes
operator|)
return|;
block|}
end_function

end_unit

