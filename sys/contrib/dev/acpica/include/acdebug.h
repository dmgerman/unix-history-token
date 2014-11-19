begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acdebug.h - ACPI/AML debugger  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACDEBUG_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACDEBUG_H__
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUG_BUFFER_SIZE
value|0x4000
end_define

begin_comment
comment|/* 16K buffer for return objects */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_db_command_info
block|{
name|char
modifier|*
name|Name
decl_stmt|;
comment|/* Command Name */
name|UINT8
name|MinArgs
decl_stmt|;
comment|/* Minimum arguments required */
block|}
name|ACPI_DB_COMMAND_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_db_command_help
block|{
name|UINT8
name|LineCount
decl_stmt|;
comment|/* Number of help lines */
name|char
modifier|*
name|Invocation
decl_stmt|;
comment|/* Command Invocation */
name|char
modifier|*
name|Description
decl_stmt|;
comment|/* Command Description */
block|}
name|ACPI_DB_COMMAND_HELP
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_db_argument_info
block|{
name|char
modifier|*
name|Name
decl_stmt|;
comment|/* Argument Name */
block|}
name|ACPI_DB_ARGUMENT_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_db_execute_walk
block|{
name|UINT32
name|Count
decl_stmt|;
name|UINT32
name|MaxCount
decl_stmt|;
block|}
name|ACPI_DB_EXECUTE_WALK
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PARAM_LIST
parameter_list|(
name|pl
parameter_list|)
value|pl
end_define

begin_define
define|#
directive|define
name|DBTEST_OUTPUT_LEVEL
parameter_list|(
name|lvl
parameter_list|)
value|if (AcpiGbl_DbOpt_verbose)
end_define

begin_define
define|#
directive|define
name|VERBOSE_PRINT
parameter_list|(
name|fp
parameter_list|)
value|DBTEST_OUTPUT_LEVEL(lvl) {\                                             AcpiOsPrintf PARAM_LIST(fp);}
end_define

begin_define
define|#
directive|define
name|EX_NO_SINGLE_STEP
value|1
end_define

begin_define
define|#
directive|define
name|EX_SINGLE_STEP
value|2
end_define

begin_comment
comment|/*  * dbxface - external debugger interfaces  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiDbInitialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbTerminate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiDbSingleStep
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|OpType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dbcmds - debug commands and output routines  */
end_comment

begin_function_decl
name|ACPI_NAMESPACE_NODE
modifier|*
name|AcpiDbConvertToNode
parameter_list|(
name|char
modifier|*
name|InString
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDisplayTableInfo
parameter_list|(
name|char
modifier|*
name|TableArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDisplayTemplate
parameter_list|(
name|char
modifier|*
name|BufferArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbUnloadAcpiTable
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbSendNotify
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|,
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDisplayInterfaces
parameter_list|(
name|char
modifier|*
name|ActionArg
parameter_list|,
name|char
modifier|*
name|InterfaceNameArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiDbSleep
parameter_list|(
name|char
modifier|*
name|ObjectArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDisplayLocks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDisplayResources
parameter_list|(
name|char
modifier|*
name|ObjectArg
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_VOID
argument_list|(
argument|void AcpiDbDisplayGpes (     void)
argument_list|)
end_macro

begin_function_decl
name|void
name|AcpiDbDisplayHandlers
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_VOID
argument_list|(
argument|void AcpiDbGenerateGpe (     char                    *GpeArg,     char                    *BlockArg)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_VOID
argument_list|(
argument|void AcpiDbGenerateSci (     void)
argument_list|)
end_macro

begin_function_decl
name|void
name|AcpiDbExecuteTest
parameter_list|(
name|char
modifier|*
name|TypeArg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dbconvert - miscellaneous conversion routines  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiDbHexCharToValue
parameter_list|(
name|int
name|HexChar
parameter_list|,
name|UINT8
modifier|*
name|ReturnValue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiDbConvertToPackage
parameter_list|(
name|char
modifier|*
name|String
parameter_list|,
name|ACPI_OBJECT
modifier|*
name|Object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiDbConvertToObject
parameter_list|(
name|ACPI_OBJECT_TYPE
name|Type
parameter_list|,
name|char
modifier|*
name|String
parameter_list|,
name|ACPI_OBJECT
modifier|*
name|Object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT8
modifier|*
name|AcpiDbEncodePldBuffer
parameter_list|(
name|ACPI_PLD_INFO
modifier|*
name|PldInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDumpPldBuffer
parameter_list|(
name|ACPI_OBJECT
modifier|*
name|ObjDesc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dbmethod - control method commands  */
end_comment

begin_function_decl
name|void
name|AcpiDbSetMethodBreakpoint
parameter_list|(
name|char
modifier|*
name|Location
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbSetMethodCallBreakpoint
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbSetMethodData
parameter_list|(
name|char
modifier|*
name|TypeArg
parameter_list|,
name|char
modifier|*
name|IndexArg
parameter_list|,
name|char
modifier|*
name|ValueArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiDbDisassembleMethod
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDisassembleAml
parameter_list|(
name|char
modifier|*
name|Statements
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbBatchExecute
parameter_list|(
name|char
modifier|*
name|CountArg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dbnames - namespace commands  */
end_comment

begin_function_decl
name|void
name|AcpiDbSetScope
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDumpNamespace
parameter_list|(
name|char
modifier|*
name|StartArg
parameter_list|,
name|char
modifier|*
name|DepthArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDumpNamespacePaths
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDumpNamespaceByOwner
parameter_list|(
name|char
modifier|*
name|OwnerArg
parameter_list|,
name|char
modifier|*
name|DepthArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiDbFindNameInNamespace
parameter_list|(
name|char
modifier|*
name|NameArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbCheckPredefinedNames
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiDbDisplayObjects
parameter_list|(
name|char
modifier|*
name|ObjTypeArg
parameter_list|,
name|char
modifier|*
name|DisplayCountArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbCheckIntegrity
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbFindReferences
parameter_list|(
name|char
modifier|*
name|ObjectArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbGetBusInfo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dbdisply - debug display commands  */
end_comment

begin_function_decl
name|void
name|AcpiDbDisplayMethodInfo
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDecodeAndDisplayObject
parameter_list|(
name|char
modifier|*
name|Target
parameter_list|,
name|char
modifier|*
name|OutputType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDisplayResultObject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiDbDisplayAllMethods
parameter_list|(
name|char
modifier|*
name|DisplayCountArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDisplayArguments
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDisplayLocals
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDisplayResults
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDisplayCallingTree
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDisplayObjectType
parameter_list|(
name|char
modifier|*
name|ObjectArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDisplayArgumentObject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dbexec - debugger control method execution  */
end_comment

begin_function_decl
name|void
name|AcpiDbExecute
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|,
name|char
modifier|*
modifier|*
name|Args
parameter_list|,
name|ACPI_OBJECT_TYPE
modifier|*
name|Types
parameter_list|,
name|UINT32
name|Flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbCreateExecutionThreads
parameter_list|(
name|char
modifier|*
name|NumThreadsArg
parameter_list|,
name|char
modifier|*
name|NumLoopsArg
parameter_list|,
name|char
modifier|*
name|MethodNameArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDeleteObjects
parameter_list|(
name|UINT32
name|Count
parameter_list|,
name|ACPI_OBJECT
modifier|*
name|Objects
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DBG_TRACK_ALLOCATIONS
end_ifdef

begin_function_decl
name|UINT32
name|AcpiDbGetCacheInfo
parameter_list|(
name|ACPI_MEMORY_LIST
modifier|*
name|Cache
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * dbfileio - Debugger file I/O commands  */
end_comment

begin_function_decl
name|ACPI_OBJECT_TYPE
name|AcpiDbMatchArgument
parameter_list|(
name|char
modifier|*
name|UserArgument
parameter_list|,
name|ACPI_DB_ARGUMENT_INFO
modifier|*
name|Arguments
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbCloseDebugFile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbOpenDebugFile
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiDbLoadAcpiTable
parameter_list|(
name|char
modifier|*
name|Filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiDbGetTableFromFile
parameter_list|(
name|char
modifier|*
name|Filename
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dbhistry - debugger HISTORY command  */
end_comment

begin_function_decl
name|void
name|AcpiDbAddToHistory
parameter_list|(
name|char
modifier|*
name|CommandLine
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDisplayHistory
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|AcpiDbGetFromHistory
parameter_list|(
name|char
modifier|*
name|CommandNumArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|AcpiDbGetHistoryByIndex
parameter_list|(
name|UINT32
name|CommanddNum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dbinput - user front-end to the AML debugger  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiDbCommandDispatch
parameter_list|(
name|char
modifier|*
name|InputBuffer
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ACPI_SYSTEM_XFACE
name|AcpiDbExecuteThread
parameter_list|(
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiDbUserCommands
parameter_list|(
name|char
name|Prompt
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|AcpiDbGetNextToken
parameter_list|(
name|char
modifier|*
name|String
parameter_list|,
name|char
modifier|*
modifier|*
name|Next
parameter_list|,
name|ACPI_OBJECT_TYPE
modifier|*
name|ReturnType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dbstats - Generation and display of ACPI table statistics  */
end_comment

begin_function_decl
name|void
name|AcpiDbGenerateStatistics
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Root
parameter_list|,
name|BOOLEAN
name|IsMethod
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiDbDisplayStatistics
parameter_list|(
name|char
modifier|*
name|TypeArg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dbutils - AML debugger utilities  */
end_comment

begin_function_decl
name|void
name|AcpiDbSetOutputDestination
parameter_list|(
name|UINT32
name|Where
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDumpExternalObject
parameter_list|(
name|ACPI_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbPrepNamestring
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_NAMESPACE_NODE
modifier|*
name|AcpiDbLocalNsLookup
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbUint32ToHexString
parameter_list|(
name|UINT32
name|Value
parameter_list|,
name|char
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACDEBUG_H__ */
end_comment

end_unit

