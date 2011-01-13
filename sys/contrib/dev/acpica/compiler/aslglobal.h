begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: aslglobal.h - Global variable definitions  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2011, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
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

begin_define
define|#
directive|define
name|ASL_LINE_BUFFER_SIZE
value|1024
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
value|8
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

begin_comment
comment|/* Option flags */
end_comment

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_DoCompile
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
name|Gbl_DoSignon
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
name|Gbl_DisassembleAll
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
name|Gbl_NoErrors
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
name|Gbl_NoResourceChecking
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

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_UseOriginalCompilerId
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
name|Gbl_VerboseTemplates
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
name|Gbl_DoTemplates
parameter_list|,
name|FALSE
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

begin_define
define|#
directive|define
name|HEX_OUTPUT_ASL
value|3
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
name|ASL_INCLUDE_DIR
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_IncludeDirList
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
name|Gbl_InputFieldCount
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
name|UINT8
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_FileType
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
name|Gbl_Signature
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
modifier|*
name|Gbl_TemplateSignature
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
name|char
name|AslHexLookup
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

begin_ifdef
ifdef|#
directive|ifdef
name|_DECLARE_GLOBALS
end_ifdef

begin_decl_stmt
name|UINT32
name|Gbl_ExceptionCount
index|[
name|ASL_NUM_REPORT_LEVELS
index|]
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|UINT32
name|Gbl_ExceptionCount
index|[
name|ASL_NUM_REPORT_LEVELS
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ASLGLOBAL_H */
end_comment

end_unit

