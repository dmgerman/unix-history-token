begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: acpixtract.h - Include for acpixtract utility  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2016, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

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

begin_include
include|#
directive|include
file|"acapps.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_undef
undef|#
directive|undef
name|ACPI_GLOBAL
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|DEFINE_ACPIXTRACT_GLOBALS
end_ifdef

begin_define
define|#
directive|define
name|ACPI_GLOBAL
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|)
define|\
value|extern type name; \     type name
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_GLOBAL
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|)
define|\
value|extern type name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Options */
end_comment

begin_define
define|#
directive|define
name|AX_EXTRACT_ALL
value|0
end_define

begin_define
define|#
directive|define
name|AX_LIST_ALL
value|1
end_define

begin_define
define|#
directive|define
name|AX_EXTRACT_SIGNATURE
value|2
end_define

begin_define
define|#
directive|define
name|AX_EXTRACT_AML_TABLES
value|3
end_define

begin_define
define|#
directive|define
name|AX_EXTRACT_MULTI_TABLE
value|4
end_define

begin_define
define|#
directive|define
name|AX_OPTIONAL_TABLES
value|0
end_define

begin_define
define|#
directive|define
name|AX_REQUIRED_TABLE
value|1
end_define

begin_define
define|#
directive|define
name|AX_UTILITY_NAME
value|"ACPI Binary Table Extraction Utility"
end_define

begin_define
define|#
directive|define
name|AX_SUPPORTED_OPTIONS
value|"ahlms:v"
end_define

begin_define
define|#
directive|define
name|AX_MULTI_TABLE_FILENAME
value|"amltables.dat"
end_define

begin_define
define|#
directive|define
name|AX_TABLE_INFO_FORMAT
value|"Acpi table [%4.4s] - %7u bytes written to %s\n"
end_define

begin_comment
comment|/* Extraction states */
end_comment

begin_define
define|#
directive|define
name|AX_STATE_FIND_HEADER
value|0
end_define

begin_define
define|#
directive|define
name|AX_STATE_EXTRACT_DATA
value|1
end_define

begin_comment
comment|/* Miscellaneous constants */
end_comment

begin_define
define|#
directive|define
name|AX_LINE_BUFFER_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|AX_MIN_BLOCK_HEADER_LENGTH
value|6
end_define

begin_comment
comment|/* strlen ("DSDT @") */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AxTableInfo
block|{
name|UINT32
name|Signature
decl_stmt|;
name|unsigned
name|int
name|Instances
decl_stmt|;
name|unsigned
name|int
name|NextInstance
decl_stmt|;
name|struct
name|AxTableInfo
modifier|*
name|Next
decl_stmt|;
block|}
name|AX_TABLE_INFO
typedef|;
end_typedef

begin_comment
comment|/* Globals */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|char
argument_list|,
name|Gbl_LineBuffer
index|[
name|AX_LINE_BUFFER_SIZE
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|char
argument_list|,
name|Gbl_HeaderBuffer
index|[
name|AX_LINE_BUFFER_SIZE
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|char
argument_list|,
name|Gbl_InstanceBuffer
index|[
name|AX_LINE_BUFFER_SIZE
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|AX_TABLE_INFO
argument_list|,
operator|*
name|Gbl_TableListHead
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|char
argument_list|,
name|Gbl_OutputFilename
index|[
literal|32
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ACPI_GLOBAL
argument_list|(
argument|unsigned char
argument_list|,
argument|Gbl_BinaryData[
literal|16
argument|]
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|ACPI_GLOBAL
argument_list|(
argument|unsigned int
argument_list|,
argument|Gbl_TableCount
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * acpixtract.c  */
end_comment

begin_function_decl
name|int
name|AxExtractTables
parameter_list|(
name|char
modifier|*
name|InputPathname
parameter_list|,
name|char
modifier|*
name|Signature
parameter_list|,
name|unsigned
name|int
name|MinimumInstances
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|AxExtractToMultiAmlFile
parameter_list|(
name|char
modifier|*
name|InputPathname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|AxListTables
parameter_list|(
name|char
modifier|*
name|InputPathname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * axutils.c  */
end_comment

begin_function_decl
name|size_t
name|AxGetTableHeader
parameter_list|(
name|FILE
modifier|*
name|InputFile
parameter_list|,
name|unsigned
name|char
modifier|*
name|OutputData
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|AxCountTableInstances
parameter_list|(
name|char
modifier|*
name|InputPathname
parameter_list|,
name|char
modifier|*
name|Signature
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|AxGetNextInstance
parameter_list|(
name|char
modifier|*
name|InputPathname
parameter_list|,
name|char
modifier|*
name|Signature
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AxNormalizeSignature
parameter_list|(
name|char
modifier|*
name|Signature
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AxCheckAscii
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|,
name|int
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|AxIsEmptyLine
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|AxIsDataBlockHeader
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|AxProcessOneTextLine
parameter_list|(
name|FILE
modifier|*
name|OutputFile
parameter_list|,
name|char
modifier|*
name|ThisSignature
parameter_list|,
name|unsigned
name|int
name|ThisTableBytesWritten
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|AxConvertLine
parameter_list|(
name|char
modifier|*
name|InputLine
parameter_list|,
name|unsigned
name|char
modifier|*
name|OutputData
parameter_list|)
function_decl|;
end_function_decl

end_unit

