begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: acapps - common include for ACPI applications/tools  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2017, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ACAPPS
end_ifndef

begin_define
define|#
directive|define
name|_ACAPPS
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_USE_STANDARD_HEADERS
end_ifdef

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_USE_STANDARD_HEADERS */
end_comment

begin_comment
comment|/* Common info for tool signons */
end_comment

begin_define
define|#
directive|define
name|ACPICA_NAME
value|"Intel ACPI Component Architecture"
end_define

begin_define
define|#
directive|define
name|ACPICA_COPYRIGHT
value|"Copyright (c) 2000 - 2017 Intel Corporation"
end_define

begin_if
if|#
directive|if
name|ACPI_MACHINE_WIDTH
operator|==
literal|64
end_if

begin_define
define|#
directive|define
name|ACPI_WIDTH
value|" (64-bit version)"
end_define

begin_elif
elif|#
directive|elif
name|ACPI_MACHINE_WIDTH
operator|==
literal|32
end_elif

begin_define
define|#
directive|define
name|ACPI_WIDTH
value|" (32-bit version)"
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|unknown ACPI_MACHINE_WIDTH
end_error

begin_define
define|#
directive|define
name|ACPI_WIDTH
value|" (unknown bit width, not 32 or 64)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Macros for signons and file headers */
end_comment

begin_define
define|#
directive|define
name|ACPI_COMMON_SIGNON
parameter_list|(
name|UtilityName
parameter_list|)
define|\
value|"\n%s\n%s version %8.8X\n%s\n\n", \     ACPICA_NAME, \     UtilityName, ((UINT32) ACPI_CA_VERSION), \     ACPICA_COPYRIGHT
end_define

begin_define
define|#
directive|define
name|ACPI_COMMON_HEADER
parameter_list|(
name|UtilityName
parameter_list|,
name|Prefix
parameter_list|)
define|\
value|"%s%s\n%s%s version %8.8X%s\n%s%s\n%s\n", \     Prefix, ACPICA_NAME, \     Prefix, UtilityName, ((UINT32) ACPI_CA_VERSION), ACPI_WIDTH, \     Prefix, ACPICA_COPYRIGHT, \     Prefix
end_define

begin_comment
comment|/* Macros for usage messages */
end_comment

begin_define
define|#
directive|define
name|ACPI_USAGE_HEADER
parameter_list|(
name|Usage
parameter_list|)
define|\
value|printf ("Usage: %s\nOptions:\n", Usage);
end_define

begin_define
define|#
directive|define
name|ACPI_USAGE_TEXT
parameter_list|(
name|Description
parameter_list|)
define|\
value|printf (Description);
end_define

begin_define
define|#
directive|define
name|ACPI_OPTION
parameter_list|(
name|Name
parameter_list|,
name|Description
parameter_list|)
define|\
value|printf ("  %-20s%s\n", Name, Description);
end_define

begin_comment
comment|/* Check for unexpected exceptions */
end_comment

begin_define
define|#
directive|define
name|ACPI_CHECK_STATUS
parameter_list|(
name|Name
parameter_list|,
name|Status
parameter_list|,
name|Expected
parameter_list|)
define|\
value|if (Status != Expected) \     { \         AcpiOsPrintf ("Unexpected %s from %s (%s-%d)\n", \             AcpiFormatException (Status), #Name, _AcpiModuleName, __LINE__); \     }
end_define

begin_comment
comment|/* Check for unexpected non-AE_OK errors */
end_comment

begin_define
define|#
directive|define
name|ACPI_CHECK_OK
parameter_list|(
name|Name
parameter_list|,
name|Status
parameter_list|)
value|ACPI_CHECK_STATUS (Name, Status, AE_OK);
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_DISASSEMBLY
value|"dsl"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_BINARY_TABLE
value|".dat"
end_define

begin_comment
comment|/* Needs the dot */
end_comment

begin_comment
comment|/* acfileio */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcGetAllTablesFromFile
parameter_list|(
name|char
modifier|*
name|Filename
parameter_list|,
name|UINT8
name|GetOnlyAmlTables
parameter_list|,
name|ACPI_NEW_TABLE_DESC
modifier|*
modifier|*
name|ReturnListHead
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcIsFileBinary
parameter_list|(
name|FILE
modifier|*
name|File
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcValidateTableHeader
parameter_list|(
name|FILE
modifier|*
name|File
parameter_list|,
name|long
name|TableOffset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Values for GetOnlyAmlTables */
end_comment

begin_define
define|#
directive|define
name|ACPI_GET_ONLY_AML_TABLES
value|TRUE
end_define

begin_define
define|#
directive|define
name|ACPI_GET_ALL_TABLES
value|FALSE
end_define

begin_comment
comment|/*  * getopt  */
end_comment

begin_function_decl
name|int
name|AcpiGetopt
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|char
modifier|*
name|opts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|AcpiGetoptArgument
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|AcpiGbl_Optind
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|AcpiGbl_Opterr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|AcpiGbl_SubOptChar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|AcpiGbl_Optarg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * cmfsize - Common get file size function  */
end_comment

begin_function_decl
name|UINT32
name|CmGetFileSize
parameter_list|(
name|ACPI_FILE
name|File
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * adwalk  */
end_comment

begin_function_decl
name|void
name|AcpiDmCrossReferenceNamespace
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|ParseTreeRoot
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|NamespaceRoot
parameter_list|,
name|ACPI_OWNER_ID
name|OwnerId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpTree
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Origin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmFindOrphanMethods
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Origin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmFinishNamespaceLoad
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|ParseTreeRoot
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|NamespaceRoot
parameter_list|,
name|ACPI_OWNER_ID
name|OwnerId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmConvertResourceIndexes
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|ParseTreeRoot
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|NamespaceRoot
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * adfile  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AdInitialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|FlGenerateFilename
parameter_list|(
name|char
modifier|*
name|InputFilename
parameter_list|,
name|char
modifier|*
name|Suffix
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|FlSplitInputPathname
parameter_list|(
name|char
modifier|*
name|InputPath
parameter_list|,
name|char
modifier|*
modifier|*
name|OutDirectoryPath
parameter_list|,
name|char
modifier|*
modifier|*
name|OutFilename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|AdGenerateFilename
parameter_list|(
name|char
modifier|*
name|Prefix
parameter_list|,
name|char
modifier|*
name|TableId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AdWriteTable
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|char
modifier|*
name|TableName
parameter_list|,
name|char
modifier|*
name|OemTableId
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ACAPPS */
end_comment

end_unit

