begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acdebug.h - ACPI/AML debugger  *       $Revision: 1.84 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
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
value|4196
end_define

begin_typedef
typedef|typedef
struct|struct
name|CommandInfo
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
name|COMMAND_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ArgumentInfo
block|{
name|char
modifier|*
name|Name
decl_stmt|;
comment|/* Argument Name */
block|}
name|ARGUMENT_INFO
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
name|AcpiDbUnloadAcpiTable
parameter_list|(
name|char
modifier|*
name|TableArg
parameter_list|,
name|char
modifier|*
name|InstanceArg
parameter_list|)
function_decl|;
end_function_decl

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
name|AcpiDbGetBusInfo
parameter_list|(
name|void
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
name|AcpiDbSetScope
parameter_list|(
name|char
modifier|*
name|Name
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

begin_function_decl
name|void
name|AcpiDbDisplayGpes
parameter_list|(
name|void
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
name|AcpiDbGenerateGpe
parameter_list|(
name|char
modifier|*
name|GpeArg
parameter_list|,
name|char
modifier|*
name|BlockArg
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
name|ARGUMENT_INFO
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

begin_function_decl
name|ACPI_STATUS
name|AcpiDbReadTableFromFile
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
name|AcpiDbUInt32ToHexString
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

