begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acdebug.h - ACPI/AML debugger  *       $Revision: 38 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999, 2000, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
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
name|DB_MAX_ARGS
value|8
end_define

begin_comment
comment|/* Must be max method args + 1 */
end_comment

begin_define
define|#
directive|define
name|DB_COMMAND_PROMPT
value|'-'
end_define

begin_define
define|#
directive|define
name|DB_EXECUTE_PROMPT
value|'%'
end_define

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NATIVE_CHAR
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT8
modifier|*
name|AmlPtr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|AcpiAmlLength
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|opt_tables
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|opt_disasm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|opt_stats
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|opt_parse_jit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|opt_verbose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NATIVE_CHAR
modifier|*
name|Args
index|[
name|DB_MAX_ARGS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NATIVE_CHAR
name|LineBuf
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NATIVE_CHAR
name|ScopeBuf
index|[
literal|40
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NATIVE_CHAR
name|DebugFilename
index|[
literal|40
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|OutputToFile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NATIVE_CHAR
modifier|*
name|Buffer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NATIVE_CHAR
modifier|*
name|Filename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|NATIVE_CHAR
modifier|*
name|INDENT_STRING
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT8
name|AcpiGbl_DbOutputFlags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|AcpiGbl_DbDebugLevel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|AcpiGbl_DbConsoleDebugLevel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|NumNames
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|NumMethods
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|NumRegions
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|NumPackages
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|NumAliases
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|NumDevices
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|NumFieldDefs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|NumThermalZones
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|NumNodes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|NumGrammarElements
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|NumMethodElements
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|NumMutexes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|NumPowerResources
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|NumBankFields
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|NumIndexFields
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|NumEvents
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|SizeOfParseTree
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|SizeOfMethodTrees
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|SizeOfNTEs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|SizeOfAcpiObjects
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BUFFER_SIZE
value|4196
end_define

begin_define
define|#
directive|define
name|DB_REDIRECTABLE_OUTPUT
value|0x01
end_define

begin_define
define|#
directive|define
name|DB_CONSOLE_OUTPUT
value|0x02
end_define

begin_define
define|#
directive|define
name|DB_DUPLICATE_OUTPUT
value|0x03
end_define

begin_typedef
typedef|typedef
struct|struct
name|CommandInfo
block|{
name|NATIVE_CHAR
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
name|NATIVE_CHAR
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
value|if (opt_verbose)
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
comment|/* Prototypes */
end_comment

begin_comment
comment|/*  * dbapi - external debugger interfaces  */
end_comment

begin_function_decl
name|int
name|AcpiDbInitialize
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
name|UINT8
name|OpType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dbcmds - debug commands and output routines  */
end_comment

begin_function_decl
name|void
name|AcpiDbDisplayTableInfo
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|TableArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbUnloadAcpiTable
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|TableArg
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|InstanceArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbSetMethodBreakpoint
parameter_list|(
name|NATIVE_CHAR
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
name|AcpiDbDisassembleAml
parameter_list|(
name|NATIVE_CHAR
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
name|NATIVE_CHAR
modifier|*
name|StartArg
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|DepthArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDumpNamespaceByOwner
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|OwnerArg
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|DepthArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbSendNotify
parameter_list|(
name|NATIVE_CHAR
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
name|NATIVE_CHAR
modifier|*
name|TypeArg
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|IndexArg
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|ValueArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiDbDisplayObjects
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|ObjTypeArg
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|DisplayCountArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiDbFindNameInNamespace
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|NameArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbSetScope
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbFindReferences
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|ObjectArg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dbdisasm - AML disassembler  */
end_comment

begin_function_decl
name|void
name|AcpiDbDisplayOp
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Origin
parameter_list|,
name|UINT32
name|NumOpcodes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDisplayNamestring
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDisplayPath
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDisplayOpcode
parameter_list|(
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
name|AcpiDbDecodeInternalObject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
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
name|NATIVE_CHAR
modifier|*
name|Target
parameter_list|,
name|NATIVE_CHAR
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
name|NATIVE_CHAR
modifier|*
name|DisplayCountArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDisplayInternalObject
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
name|NATIVE_CHAR
modifier|*
name|Name
parameter_list|,
name|NATIVE_CHAR
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
name|NATIVE_CHAR
modifier|*
name|NumThreadsArg
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|NumLoopsArg
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|MethodNameArg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dbfileio - Debugger file I/O commands  */
end_comment

begin_function_decl
name|OBJECT_TYPE_INTERNAL
name|AcpiDbMatchArgument
parameter_list|(
name|NATIVE_CHAR
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
name|NATIVE_CHAR
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiDbLoadAcpiTable
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|Filename
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
name|NATIVE_CHAR
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
name|NATIVE_CHAR
modifier|*
name|AcpiDbGetFromHistory
parameter_list|(
name|NATIVE_CHAR
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
name|NATIVE_CHAR
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
name|NATIVE_CHAR
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
name|NATIVE_CHAR
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
name|AcpiDbDumpBuffer
parameter_list|(
name|UINT32
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDbDumpObject
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
name|NATIVE_CHAR
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiDbSecondPassParse
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Root
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_NAMESPACE_NODE
modifier|*
name|AcpiDbLocalNsLookup
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|Name
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

