begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: acapps - common include for ACPI applications/tools  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
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
name|_MSC_VER
end_ifdef

begin_comment
comment|/* disable some level-4 warnings */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4100
name|)
end_pragma

begin_comment
comment|/* warning C4100: unreferenced formal parameter */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
value|"Copyright (c) 2000 - 2014 Intel Corporation"
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
value|"-64"
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
value|"-32"
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
value|"-??"
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
value|"\n%s\n%s version %8.8X%s\n%s\n\n", \     ACPICA_NAME, \     UtilityName, ((UINT32) ACPI_CA_VERSION), ACPI_WIDTH, \     ACPICA_COPYRIGHT
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
value|AcpiOsPrintf ("Usage: %s\nOptions:\n", Usage);
end_define

begin_define
define|#
directive|define
name|ACPI_USAGE_TEXT
parameter_list|(
name|Description
parameter_list|)
define|\
value|AcpiOsPrintf (Description);
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
value|AcpiOsPrintf ("  %-18s%s\n", Name, Description);
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
name|ACPI_TABLE_FILE_SUFFIX
value|".dat"
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

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_DUMP_APP
end_ifndef

begin_comment
comment|/*  * adisasm  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AdAmlDisassemble
parameter_list|(
name|BOOLEAN
name|OutToFile
parameter_list|,
name|char
modifier|*
name|Filename
parameter_list|,
name|char
modifier|*
name|Prefix
parameter_list|,
name|char
modifier|*
modifier|*
name|OutFilename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AdPrintStatistics
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AdFindDsdt
parameter_list|(
name|UINT8
modifier|*
modifier|*
name|DsdtPtr
parameter_list|,
name|UINT32
modifier|*
name|DsdtLength
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AdDumpTables
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AdGetLocalTables
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AdParseTable
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|,
name|ACPI_OWNER_ID
modifier|*
name|OwnerId
parameter_list|,
name|BOOLEAN
name|LoadTable
parameter_list|,
name|BOOLEAN
name|External
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AdDisplayTables
parameter_list|(
name|char
modifier|*
name|Filename
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AdDisplayStatistics
parameter_list|(
name|void
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ACAPPS */
end_comment

end_unit

