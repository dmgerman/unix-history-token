begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: utuuid -- UUID support functions  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_define
define|#
directive|define
name|__UTUUID_C__
end_define

begin_include
include|#
directive|include
file|"acpi.h"
end_include

begin_include
include|#
directive|include
file|"accommon.h"
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
literal|"utuuid"
argument_list|)
end_macro

begin_comment
comment|/*  * UUID support functions.  *  * This table is used to convert an input UUID ascii string to a 16 byte  * buffer and the reverse. The table maps a UUID buffer index 0-15 to  * the index within the 36-byte UUID string where the associated 2-byte  * hex value can be found.  *  * 36-byte UUID strings are of the form:  *     aabbccdd-eeff-gghh-iijj-kkllmmnnoopp  * Where aa-pp are one byte hex numbers, made up of two hex digits  *  * Note: This table is basically the inverse of the string-to-offset table  * found in the ACPI spec in the description of the ToUUID macro.  */
end_comment

begin_decl_stmt
specifier|const
name|UINT8
name|AcpiGbl_MapToUuidOffset
index|[
name|UUID_BUFFER_LENGTH
index|]
init|=
block|{
literal|6
block|,
literal|4
block|,
literal|2
block|,
literal|0
block|,
literal|11
block|,
literal|9
block|,
literal|16
block|,
literal|14
block|,
literal|19
block|,
literal|21
block|,
literal|24
block|,
literal|26
block|,
literal|28
block|,
literal|30
block|,
literal|32
block|,
literal|34
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtConvertStringToUuid  *  * PARAMETERS:  InString            - 36-byte formatted UUID string  *              UuidBuffer          - Where the 16-byte UUID buffer is returned  *  * RETURN:      None. Output data is returned in the UuidBuffer  *  * DESCRIPTION: Convert a 36-byte formatted UUID string to 16-byte UUID buffer  *  ******************************************************************************/
end_comment

begin_function
name|void
name|AcpiUtConvertStringToUuid
parameter_list|(
name|char
modifier|*
name|InString
parameter_list|,
name|UINT8
modifier|*
name|UuidBuffer
parameter_list|)
block|{
name|UINT32
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|UUID_BUFFER_LENGTH
condition|;
name|i
operator|++
control|)
block|{
name|UuidBuffer
index|[
name|i
index|]
operator|=
operator|(
name|AcpiUtAsciiCharToHex
argument_list|(
name|InString
index|[
name|AcpiGbl_MapToUuidOffset
index|[
name|i
index|]
index|]
argument_list|)
operator|<<
literal|4
operator|)
expr_stmt|;
name|UuidBuffer
index|[
name|i
index|]
operator||=
name|AcpiUtAsciiCharToHex
argument_list|(
name|InString
index|[
name|AcpiGbl_MapToUuidOffset
index|[
name|i
index|]
operator|+
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

