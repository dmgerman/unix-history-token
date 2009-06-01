begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: acapps - common include for ACPI applications/tools  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
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

begin_decl_stmt
specifier|extern
name|UINT8
modifier|*
name|DsdtPtr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|AcpiDsdtLength
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT8
modifier|*
name|AmlStart
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|AmlLength
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|AcpiGbl_Optind
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|AcpiGbl_Optarg
decl_stmt|;
end_decl_stmt

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
parameter_list|,
name|BOOLEAN
name|GetAllTables
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
name|char
modifier|*
name|Filename
parameter_list|,
name|BOOLEAN
name|GetAllTables
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

