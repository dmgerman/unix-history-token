begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: acapps - common include for ACPI applications/tools  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
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
name|AcpiDmConvertParseObjects
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

