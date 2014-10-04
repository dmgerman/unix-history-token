begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: uthex -- Hex/ASCII support functions  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_define
define|#
directive|define
name|__UTHEX_C__
end_define

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acpi.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/accommon.h>
end_include

begin_define
define|#
directive|define
name|_COMPONENT
value|ACPI_COMPILER
end_define

begin_macro
name|ACPI_MODULE_NAME
argument_list|(
literal|"uthex"
argument_list|)
end_macro

begin_comment
comment|/* Hex to ASCII conversion table */
end_comment

begin_decl_stmt
specifier|static
name|char
name|AcpiGbl_HexToAscii
index|[]
init|=
block|{
literal|'0'
block|,
literal|'1'
block|,
literal|'2'
block|,
literal|'3'
block|,
literal|'4'
block|,
literal|'5'
block|,
literal|'6'
block|,
literal|'7'
block|,
literal|'8'
block|,
literal|'9'
block|,
literal|'A'
block|,
literal|'B'
block|,
literal|'C'
block|,
literal|'D'
block|,
literal|'E'
block|,
literal|'F'
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtHexToAsciiChar  *  * PARAMETERS:  Integer             - Contains the hex digit  *              Position            - bit position of the digit within the  *                                    integer (multiple of 4)  *  * RETURN:      The converted Ascii character  *  * DESCRIPTION: Convert a hex digit to an Ascii character  *  ******************************************************************************/
end_comment

begin_function
name|char
name|AcpiUtHexToAsciiChar
parameter_list|(
name|UINT64
name|Integer
parameter_list|,
name|UINT32
name|Position
parameter_list|)
block|{
return|return
operator|(
name|AcpiGbl_HexToAscii
index|[
operator|(
name|Integer
operator|>>
name|Position
operator|)
operator|&
literal|0xF
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtHexCharToValue  *  * PARAMETERS:  AsciiChar             - Hex character in Ascii  *  * RETURN:      The binary value of the ascii/hex character  *  * DESCRIPTION: Perform ascii-to-hex translation  *  ******************************************************************************/
end_comment

begin_function
name|UINT8
name|AcpiUtAsciiCharToHex
parameter_list|(
name|int
name|HexChar
parameter_list|)
block|{
if|if
condition|(
name|HexChar
operator|<=
literal|0x39
condition|)
block|{
return|return
operator|(
call|(
name|UINT8
call|)
argument_list|(
name|HexChar
operator|-
literal|0x30
argument_list|)
operator|)
return|;
block|}
if|if
condition|(
name|HexChar
operator|<=
literal|0x46
condition|)
block|{
return|return
operator|(
call|(
name|UINT8
call|)
argument_list|(
name|HexChar
operator|-
literal|0x37
argument_list|)
operator|)
return|;
block|}
return|return
operator|(
call|(
name|UINT8
call|)
argument_list|(
name|HexChar
operator|-
literal|0x57
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

