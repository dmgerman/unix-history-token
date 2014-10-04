begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: aslcompiler.h - common include file for iASL  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASLCOMPILER_H
end_ifndef

begin_define
define|#
directive|define
name|__ASLCOMPILER_H
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

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/amlresrc.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acdebug.h>
end_include

begin_comment
comment|/* Microsoft-specific */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
name|WIN32
operator|||
name|defined
name|WIN64
operator|)
end_if

begin_comment
comment|/* warn : used #pragma pack */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4103
name|)
end_pragma

begin_comment
comment|/* warn : named type definition in parentheses */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4115
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_comment
comment|/* Compiler headers */
end_comment

begin_include
include|#
directive|include
file|<contrib/dev/acpica/compiler/asldefine.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/compiler/asltypes.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/compiler/aslmessages.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/compiler/aslglobal.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/compiler/preprocess.h>
end_include

begin_comment
comment|/*******************************************************************************  *  * Compiler prototypes  *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * Main ASL parser - generated from flex/bison, lex/yacc, etc.  */
end_comment

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|AslDoError
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|AslCompilerlex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AslResetCurrentLineBuffer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AslInsertLineBuffer
parameter_list|(
name|int
name|SourceChar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|AslPopInputFileStack
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AslPushInputFileStack
parameter_list|(
name|FILE
modifier|*
name|InputFile
parameter_list|,
name|char
modifier|*
name|Filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AslParserCleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslstartup - entered from main()  */
end_comment

begin_function_decl
name|void
name|AslInitializeGlobals
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|ACPI_STATUS
function_decl|(
modifier|*
name|ASL_PATHNAME_CALLBACK
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|ACPI_STATUS
name|AslDoOneFile
parameter_list|(
name|char
modifier|*
name|Filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AslCheckForErrorExit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslcompile - compile mainline  */
end_comment

begin_function_decl
name|void
name|AslCompilerSignon
parameter_list|(
name|UINT32
name|FileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AslCompilerFileHeader
parameter_list|(
name|UINT32
name|FileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|CmDoCompile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CmDoOutputFiles
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CmCleanupAndExit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CmDeleteCaches
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslascii - ascii support  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|FlCheckForAcpiTable
parameter_list|(
name|FILE
modifier|*
name|Handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|FlCheckForAscii
parameter_list|(
name|FILE
modifier|*
name|Handle
parameter_list|,
name|char
modifier|*
name|Filename
parameter_list|,
name|BOOLEAN
name|DisplayErrors
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslwalks - semantic analysis and parse tree walks  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AnOtherSemanticAnalysisWalkBegin
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Level
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AnOtherSemanticAnalysisWalkEnd
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Level
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AnOperandTypecheckWalkEnd
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Level
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AnMethodTypingWalkEnd
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Level
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslmethod - Control method analysis walk  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|MtMethodAnalysisWalkBegin
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Level
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|MtMethodAnalysisWalkEnd
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Level
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslbtypes - bitfield data types  */
end_comment

begin_function_decl
name|UINT32
name|AnMapObjTypeToBtype
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AnMapArgTypeToBtype
parameter_list|(
name|UINT32
name|ArgType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AnGetBtype
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AnFormatBtype
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|UINT32
name|Btype
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslanalyze - Support functions for parse tree walks  */
end_comment

begin_function_decl
name|void
name|AnCheckId
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|ACPI_NAME
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Values for Type argument above */
end_comment

begin_define
define|#
directive|define
name|ASL_TYPE_HID
value|0
end_define

begin_define
define|#
directive|define
name|ASL_TYPE_CID
value|1
end_define

begin_function_decl
name|BOOLEAN
name|AnIsInternalMethod
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AnGetInternalMethodReturnType
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AnLastStatementIsReturn
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AnCheckMethodReturnValue
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
specifier|const
name|ACPI_OPCODE_INFO
modifier|*
name|OpInfo
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|ArgOp
parameter_list|,
name|UINT32
name|RequiredBtypes
parameter_list|,
name|UINT32
name|ThisNodeBtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AnIsResultUsed
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ApCheckForGpeNameConflict
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ApCheckRegMethod
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|ApFindNameInScope
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslerror - error handling/reporting  */
end_comment

begin_function_decl
name|void
name|AslAbort
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AslError
parameter_list|(
name|UINT8
name|Level
parameter_list|,
name|UINT16
name|MessageId
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|char
modifier|*
name|ExtraMessage
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AslDisableException
parameter_list|(
name|char
modifier|*
name|MessageIdString
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AslIsExceptionDisabled
parameter_list|(
name|UINT8
name|Level
parameter_list|,
name|UINT16
name|MessageId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AslCoreSubsystemError
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|ACPI_STATUS
name|Status
parameter_list|,
name|char
modifier|*
name|ExtraMessage
parameter_list|,
name|BOOLEAN
name|Abort
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|AslCompilererror
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AslCommonError
parameter_list|(
name|UINT8
name|Level
parameter_list|,
name|UINT16
name|MessageId
parameter_list|,
name|UINT32
name|CurrentLineNumber
parameter_list|,
name|UINT32
name|LogicalLineNumber
parameter_list|,
name|UINT32
name|LogicalByteOffset
parameter_list|,
name|UINT32
name|Column
parameter_list|,
name|char
modifier|*
name|Filename
parameter_list|,
name|char
modifier|*
name|ExtraMessage
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AslCommonError2
parameter_list|(
name|UINT8
name|Level
parameter_list|,
name|UINT16
name|MessageId
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|UINT32
name|Column
parameter_list|,
name|char
modifier|*
name|SourceLine
parameter_list|,
name|char
modifier|*
name|Filename
parameter_list|,
name|char
modifier|*
name|ExtraMessage
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AePrintException
parameter_list|(
name|UINT32
name|FileId
parameter_list|,
name|ASL_ERROR_MSG
modifier|*
name|Enode
parameter_list|,
name|char
modifier|*
name|Header
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AePrintErrorLog
parameter_list|(
name|UINT32
name|FileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AeClearErrorLog
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * asllisting - generate all "listing" type files  */
end_comment

begin_function_decl
name|void
name|LsDoListings
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|LsWriteNodeToAsmListing
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|LsWriteNode
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|FileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|LsDumpParseTree
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * asllistsup - Listing file support utilities  */
end_comment

begin_function_decl
name|void
name|LsDumpAscii
parameter_list|(
name|UINT32
name|FileId
parameter_list|,
name|UINT32
name|Count
parameter_list|,
name|UINT8
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|LsDumpAsciiInComment
parameter_list|(
name|UINT32
name|FileId
parameter_list|,
name|UINT32
name|Count
parameter_list|,
name|UINT8
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|LsCheckException
parameter_list|(
name|UINT32
name|LineNumber
parameter_list|,
name|UINT32
name|FileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|LsFlushListingBuffer
parameter_list|(
name|UINT32
name|FileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|LsWriteListingHexBytes
parameter_list|(
name|UINT8
modifier|*
name|Buffer
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|FileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|LsWriteSourceLines
parameter_list|(
name|UINT32
name|ToLineNumber
parameter_list|,
name|UINT32
name|ToLogicalLineNumber
parameter_list|,
name|UINT32
name|FileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|LsWriteOneSourceLine
parameter_list|(
name|UINT32
name|FileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|LsPushNode
parameter_list|(
name|char
modifier|*
name|Filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_LISTING_NODE
modifier|*
name|LsPopNode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslhex - generate all "hex" output files (C, ASM, ASL)  */
end_comment

begin_function_decl
name|void
name|HxDoHexOutput
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslfold - constant folding  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|OpcAmlConstantWalk
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Level
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslmessages - exception strings  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|AeDecodeMessageId
parameter_list|(
name|UINT16
name|MessageId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|AeDecodeExceptionLevel
parameter_list|(
name|UINT8
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT16
name|AeBuildFullExceptionCode
parameter_list|(
name|UINT8
name|Level
parameter_list|,
name|UINT16
name|MessageId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * asloffset - generate C offset file for BIOS support  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|LsAmlOffsetWalk
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Level
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|LsDoOffsetTableHeader
parameter_list|(
name|UINT32
name|FileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|LsDoOffsetTableFooter
parameter_list|(
name|UINT32
name|FileId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslopcodes - generate AML opcodes  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|OpcAmlOpcodeWalk
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Level
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|OpcAmlOpcodeUpdateWalk
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Level
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|OpcGenerateAmlOpcode
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|OpcSetOptimalIntegerSize
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|OpcGetIntegerWidth
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * asloperands - generate AML operands for the AML opcodes  */
end_comment

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|UtGetArg
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Argn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|OpnGenerateAmlOperands
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|OpnDoPackage
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslopt - optmization  */
end_comment

begin_function_decl
name|void
name|OptOptimizeNamePath
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Flags
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|char
modifier|*
name|AmlNameString
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|TargetNode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslcodegen - code generation  */
end_comment

begin_function_decl
name|void
name|CgGenerateAmlOutput
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslfile  */
end_comment

begin_function_decl
name|void
name|FlOpenFile
parameter_list|(
name|UINT32
name|FileId
parameter_list|,
name|char
modifier|*
name|Filename
parameter_list|,
name|char
modifier|*
name|Mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * asllength - calculate/adjust AML package lengths  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|LnPackageLengthWalk
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Level
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|LnInitLengthsWalk
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Level
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CgGenerateAmlLengths
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslmap - opcode mappings and reserved method names  */
end_comment

begin_function_decl
name|ACPI_OBJECT_TYPE
name|AslMapNamedOpcodeToDataType
parameter_list|(
name|UINT16
name|Opcode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslpredef - ACPI predefined names support  */
end_comment

begin_function_decl
name|BOOLEAN
name|ApCheckForPredefinedMethod
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|ASL_METHOD_INFO
modifier|*
name|MethodInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ApCheckPredefinedReturnValue
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|ASL_METHOD_INFO
modifier|*
name|MethodInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|ApCheckForPredefinedName
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ApCheckForPredefinedObject
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|ApCheckObjectType
parameter_list|(
specifier|const
name|char
modifier|*
name|PredefinedName
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|ExpectedBtypes
parameter_list|,
name|UINT32
name|PackageIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ApDisplayReservedNames
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslprepkg - ACPI predefined names support for packages  */
end_comment

begin_function_decl
name|void
name|ApCheckPackage
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|ParentOp
parameter_list|,
specifier|const
name|ACPI_PREDEFINED_INFO
modifier|*
name|Predefined
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * asltransform - parse tree transformations  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|TrAmlTransformWalk
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Level
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * asltree - parse tree support  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|TrWalkParseTree
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Visitation
parameter_list|,
name|ASL_WALK_CALLBACK
name|DescendingCallback
parameter_list|,
name|ASL_WALK_CALLBACK
name|AscendingCallback
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Values for "Visitation" parameter above */
end_comment

begin_define
define|#
directive|define
name|ASL_WALK_VISIT_DOWNWARD
value|0x01
end_define

begin_define
define|#
directive|define
name|ASL_WALK_VISIT_UPWARD
value|0x02
end_define

begin_define
define|#
directive|define
name|ASL_WALK_VISIT_TWICE
value|(ASL_WALK_VISIT_DOWNWARD | ASL_WALK_VISIT_UPWARD)
end_define

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|TrAllocateNode
parameter_list|(
name|UINT32
name|ParseOpcode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|TrReleaseNode
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|TrUpdateNode
parameter_list|(
name|UINT32
name|ParseOpcode
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|TrCreateNode
parameter_list|(
name|UINT32
name|ParseOpcode
parameter_list|,
name|UINT32
name|NumChildren
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|TrCreateLeafNode
parameter_list|(
name|UINT32
name|ParseOpcode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|TrCreateValuedLeafNode
parameter_list|(
name|UINT32
name|ParseOpcode
parameter_list|,
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|TrCreateConstantLeafNode
parameter_list|(
name|UINT32
name|ParseOpcode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|TrLinkChildren
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|NumChildren
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|TrSetEndLineNumber
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|TrWalkTree
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|TrLinkPeerNode
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op1
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|TrLinkChildNode
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op1
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|TrSetNodeFlags
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|TrSetNodeAmlLength
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|TrLinkPeerNodes
parameter_list|(
name|UINT32
name|NumPeers
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslfiles - File I/O support  */
end_comment

begin_function_decl
name|void
name|FlAddIncludeDirectory
parameter_list|(
name|char
modifier|*
name|Dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|FlMergePathnames
parameter_list|(
name|char
modifier|*
name|PrefixDir
parameter_list|,
name|char
modifier|*
name|FilePathname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FlOpenIncludeFile
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FlFileError
parameter_list|(
name|UINT32
name|FileId
parameter_list|,
name|UINT8
name|ErrorId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|FlGetFileSize
parameter_list|(
name|UINT32
name|FileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|FlReadFile
parameter_list|(
name|UINT32
name|FileId
parameter_list|,
name|void
modifier|*
name|Buffer
parameter_list|,
name|UINT32
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FlWriteFile
parameter_list|(
name|UINT32
name|FileId
parameter_list|,
name|void
modifier|*
name|Buffer
parameter_list|,
name|UINT32
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FlSeekFile
parameter_list|(
name|UINT32
name|FileId
parameter_list|,
name|long
name|Offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FlCloseFile
parameter_list|(
name|UINT32
name|FileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FlPrintFile
parameter_list|(
name|UINT32
name|FileId
parameter_list|,
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FlDeleteFile
parameter_list|(
name|UINT32
name|FileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FlSetLineNumber
parameter_list|(
name|UINT32
name|LineNumber
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FlSetFilename
parameter_list|(
name|char
modifier|*
name|Filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|FlOpenInputFile
parameter_list|(
name|char
modifier|*
name|InputFilename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|FlOpenAmlOutputFile
parameter_list|(
name|char
modifier|*
name|InputFilename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|FlOpenMiscOutputFiles
parameter_list|(
name|char
modifier|*
name|InputFilename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslhwmap - hardware map summary  */
end_comment

begin_function_decl
name|void
name|MpEmitMappingInfo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * asload - load namespace in prep for cross reference  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|LdLoadNamespace
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|RootOp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * asllookup - namespace lookup functions  */
end_comment

begin_function_decl
name|void
name|LkFindUnreferencedObjects
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslmain - startup  */
end_comment

begin_function_decl
name|void
name|Usage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AslFilenameHelp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslnamesp - namespace output file generation  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|NsDisplayNamespace
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|NsSetupNamespaceListing
parameter_list|(
name|void
modifier|*
name|Handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * asloptions - command line processing  */
end_comment

begin_function_decl
name|int
name|AslCommandLine
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

begin_comment
comment|/*  * aslxref - namespace cross reference  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|XfCrossReferenceNamespace
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslutils - common compiler utilites  */
end_comment

begin_function_decl
name|void
name|DbgPrint
parameter_list|(
name|UINT32
name|Type
parameter_list|,
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Type values for above */
end_comment

begin_define
define|#
directive|define
name|ASL_DEBUG_OUTPUT
value|0
end_define

begin_define
define|#
directive|define
name|ASL_PARSE_OUTPUT
value|1
end_define

begin_define
define|#
directive|define
name|ASL_TREE_OUTPUT
value|2
end_define

begin_function_decl
name|void
name|UtDisplaySupportedTables
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UtDisplayConstantOpcodes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT8
name|UtBeginEvent
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UtEndEvent
parameter_list|(
name|UINT8
name|Event
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|UtLocalCalloc
parameter_list|(
name|UINT32
name|Size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UtPrintFormattedName
parameter_list|(
name|UINT16
name|ParseOpcode
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UtDisplaySummary
parameter_list|(
name|UINT32
name|FileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UtConvertByteToHex
parameter_list|(
name|UINT8
name|RawByte
parameter_list|,
name|UINT8
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UtConvertByteToAsmHex
parameter_list|(
name|UINT8
name|RawByte
parameter_list|,
name|UINT8
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|UtGetOpName
parameter_list|(
name|UINT32
name|ParseOpcode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UtSetParseOpName
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|UtStringCacheCalloc
parameter_list|(
name|UINT32
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UtExpandLineBuffers
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UtFreeLineBuffers
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|UtInternalizeName
parameter_list|(
name|char
modifier|*
name|ExternalName
parameter_list|,
name|char
modifier|*
modifier|*
name|ConvertedName
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UtAttachNamepathToOwner
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|NameNode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|UtCheckIntegerRange
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|LowValue
parameter_list|,
name|UINT32
name|HighValue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT64
name|UtDoConstant
parameter_list|(
name|char
modifier|*
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|UtStrtoul64
parameter_list|(
name|char
modifier|*
name|String
parameter_list|,
name|UINT32
name|Base
parameter_list|,
name|UINT64
modifier|*
name|RetInteger
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * asluuid - UUID support  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AuValidateUuid
parameter_list|(
name|char
modifier|*
name|InString
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AuConvertUuidToString
parameter_list|(
name|char
modifier|*
name|UuIdBuffer
parameter_list|,
name|char
modifier|*
name|OutString
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslresource - Resource template generation utilities  */
end_comment

begin_function_decl
name|void
name|RsSmallAddressCheck
parameter_list|(
name|UINT8
name|Type
parameter_list|,
name|UINT32
name|Minimum
parameter_list|,
name|UINT32
name|Maximum
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|Alignment
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|MinOp
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|MaxOp
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|LengthOp
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|AlignOp
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RsLargeAddressCheck
parameter_list|(
name|UINT64
name|Minimum
parameter_list|,
name|UINT64
name|Maximum
parameter_list|,
name|UINT64
name|Length
parameter_list|,
name|UINT64
name|Granularity
parameter_list|,
name|UINT8
name|Flags
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|MinOp
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|MaxOp
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|LengthOp
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|GranOp
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT16
name|RsGetStringDataLength
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|InitializerOp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsAllocateResourceNode
parameter_list|(
name|UINT32
name|Size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RsCreateResourceField
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|char
modifier|*
name|Name
parameter_list|,
name|UINT32
name|ByteOffset
parameter_list|,
name|UINT32
name|BitOffset
parameter_list|,
name|UINT32
name|BitLength
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RsSetFlagBits
parameter_list|(
name|UINT8
modifier|*
name|Flags
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT8
name|Position
parameter_list|,
name|UINT8
name|DefaultBit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RsSetFlagBits16
parameter_list|(
name|UINT16
modifier|*
name|Flags
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT8
name|Position
parameter_list|,
name|UINT8
name|DefaultBit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|RsCompleteNodeAndGetNext
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RsCheckListForDuplicates
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoOneResourceDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|,
name|UINT8
modifier|*
name|State
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Values for State above */
end_comment

begin_define
define|#
directive|define
name|ACPI_RSTATE_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_RSTATE_START_DEPENDENT
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_RSTATE_DEPENDENT_LIST
value|2
end_define

begin_function_decl
name|UINT32
name|RsLinkDescriptorChain
parameter_list|(
name|ASL_RESOURCE_NODE
modifier|*
modifier|*
name|PreviousRnode
parameter_list|,
name|ASL_RESOURCE_NODE
modifier|*
name|Rnode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RsDoResourceTemplate
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslrestype1 - Miscellaneous Small descriptors  */
end_comment

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoEndTagDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoEndDependentDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoMemory24Descriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoMemory32Descriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoMemory32FixedDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoStartDependentDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoStartDependentNoPriDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoVendorSmallDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslrestype1i - I/O-related Small descriptors  */
end_comment

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoDmaDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoFixedDmaDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoFixedIoDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoIoDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoIrqDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoIrqNoFlagsDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslrestype2 - Large resource descriptors  */
end_comment

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoInterruptDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoVendorLargeDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoGeneralRegisterDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoGpioIntDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoGpioIoDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoI2cSerialBusDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoSpiSerialBusDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoUartSerialBusDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslrestype2d - DWord address descriptors  */
end_comment

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoDwordIoDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoDwordMemoryDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoDwordSpaceDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslrestype2e - Extended address descriptors  */
end_comment

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoExtendedIoDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoExtendedMemoryDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoExtendedSpaceDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslrestype2q - QWord address descriptors  */
end_comment

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoQwordIoDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoQwordMemoryDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoQwordSpaceDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * aslrestype2w - Word address descriptors  */
end_comment

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoWordIoDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoWordSpaceDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_RESOURCE_NODE
modifier|*
name|RsDoWordBusNumberDescriptor
parameter_list|(
name|ASL_RESOURCE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Entry to data table compiler subsystem  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|DtDoCompile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCreateTemplates
parameter_list|(
name|char
modifier|*
name|Signature
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  __ASLCOMPILER_H */
end_comment

end_unit

