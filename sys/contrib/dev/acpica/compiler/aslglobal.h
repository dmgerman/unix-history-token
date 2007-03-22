begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: aslglobal.h - Global variable definitions  *              $Revision: 1.56 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASLGLOBAL_H
end_ifndef

begin_define
define|#
directive|define
name|__ASLGLOBAL_H
end_define

begin_comment
comment|/*  * Global variables.  Defined in aslmain.c only, externed in all other files  */
end_comment

begin_undef
undef|#
directive|undef
name|ASL_EXTERN
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|_DECLARE_GLOBALS
end_ifdef

begin_define
define|#
directive|define
name|ASL_EXTERN
end_define

begin_define
define|#
directive|define
name|ASL_INIT_GLOBAL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a)=(b)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASL_EXTERN
value|extern
end_define

begin_define
define|#
directive|define
name|ASL_INIT_GLOBAL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Parser and other externals  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|yydebug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|AslCompilerin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|AslCompilerdebug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|ASL_MAPPING_ENTRY
name|AslKeywordMapping
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|AslCompilertext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|hex
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ASL_LINE_BUFFER_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|ASL_MSG_BUFFER_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|HEX_TABLE_LINE_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|HEX_LISTING_LINE_SIZE
value|16
end_define

begin_comment
comment|/* Source code buffers and pointers for error reporting */
end_comment

begin_decl_stmt
name|ASL_EXTERN
name|char
name|Gbl_CurrentLineBuffer
index|[
name|ASL_LINE_BUFFER_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_CurrentColumn
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_CurrentLineNumber
argument_list|,
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_LogicalLineNumber
argument_list|,
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_CurrentLineOffset
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_LineBufPtr
argument_list|,
name|Gbl_CurrentLineBuffer
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Exception reporting */
end_comment

begin_decl_stmt
name|ASL_EXTERN
name|ASL_ERROR_MSG
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_ErrorLog
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|ASL_ERROR_MSG
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_NextError
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|Gbl_ExceptionCount
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Option flags */
end_comment

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_Acpi2
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_UseDefaultAmlFilename
parameter_list|,
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_NsOutputFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_DebugFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_AsmOutputFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_C_OutputFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_AsmIncludeOutputFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_C_IncludeOutputFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_ListingFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_IgnoreErrors
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_SourceOutputFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_ParseOnlyFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_CompileTimesFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_FoldConstants
parameter_list|,
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_VerboseErrors
parameter_list|,
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_DisasmFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_GetAllTables
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_IntegerOptimizationFlag
parameter_list|,
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_ReferenceOptimizationFlag
parameter_list|,
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_DisplayRemarks
parameter_list|,
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_DisplayOptimizations
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|UINT8
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_WarningLevel
parameter_list|,
name|ASL_WARNING
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|HEX_OUTPUT_NONE
value|0
end_define

begin_define
define|#
directive|define
name|HEX_OUTPUT_C
value|1
end_define

begin_define
define|#
directive|define
name|HEX_OUTPUT_ASM
value|2
end_define

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_HexOutputFlag
parameter_list|,
name|HEX_OUTPUT_NONE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Files */
end_comment

begin_decl_stmt
name|ASL_EXTERN
name|ASL_FILE_INFO
name|Gbl_Files
index|[
name|ASL_NUM_FILES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
modifier|*
name|Gbl_DirectoryPath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_ExternalFilename
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_IncludeFilename
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_OutputFilenamePrefix
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
modifier|*
name|Gbl_CurrentInputFilename
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_HasIncludeFiles
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Statistics */
end_comment

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_InputByteCount
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_NsLookupCount
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|TotalKeywords
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|TotalNamedObjects
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|TotalExecutableOpcodes
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|TotalParseNodes
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|TotalMethods
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|TotalAllocations
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|TotalAllocated
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|TotalFolds
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Misc */
end_comment

begin_decl_stmt
name|ASL_EXTERN
name|UINT8
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_RevisionOverride
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT8
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_TempCount
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|ACPI_PARSE_OBJECT
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|RootNode
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_TableLength
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_SourceLine
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|ASL_LISTING_NODE
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_ListingNode
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|ACPI_PARSE_OBJECT
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_NodeCacheNext
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|ACPI_PARSE_OBJECT
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_NodeCacheLast
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_StringCacheNext
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_StringCacheLast
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|ACPI_PARSE_OBJECT
modifier|*
name|Gbl_FirstLevelInsertionNode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_CurrentHexColumn
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_CurrentAmlOffset
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_CurrentLine
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ASL_EXTERN
name|UINT8
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_HexBytesWereWritten
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_NumNamespaceObjects
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_ReservedMethods
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_TableSignature
argument_list|,
literal|"NO_SIG"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_TableId
argument_list|,
literal|"NO_ID"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|FILE
modifier|*
name|AcpiGbl_DebugFile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Placeholder for oswinxf only */
end_comment

begin_comment
comment|/* Static structures */
end_comment

begin_decl_stmt
name|ASL_EXTERN
name|ASL_ANALYSIS_WALK_INFO
name|AnalysisWalkInfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|ACPI_TABLE_HEADER
name|TableHeader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|ASL_RESERVED_INFO
name|ReservedMethods
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Event timing */
end_comment

begin_define
define|#
directive|define
name|ASL_NUM_EVENTS
value|19
end_define

begin_decl_stmt
name|ASL_EXTERN
name|ASL_EVENT_INFO
name|AslGbl_Events
index|[
name|ASL_NUM_EVENTS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT8
name|AslGbl_NextEvent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT8
name|AslGbl_NamespaceEvent
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Scratch buffers */
end_comment

begin_decl_stmt
name|ASL_EXTERN
name|UINT8
name|Gbl_AmlBuffer
index|[
name|HEX_LISTING_LINE_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|MsgBuffer
index|[
name|ASL_MSG_BUFFER_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|StringBuffer
index|[
name|ASL_MSG_BUFFER_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|StringBuffer2
index|[
name|ASL_MSG_BUFFER_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ASLGLOBAL_H */
end_comment

end_unit

