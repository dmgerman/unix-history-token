begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acstruct.h - Internal structs  *       $Revision: 5 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999, 2000, 2001, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACSTRUCT_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACSTRUCT_H__
end_define

begin_comment
comment|/*****************************************************************************  *  * Tree walking typedefs and structs  *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * Walk state - current state of a parse tree walk.  Used for both a leisurely stroll through  * the tree (for whatever reason), and for control method execution.  */
end_comment

begin_define
define|#
directive|define
name|NEXT_OP_DOWNWARD
value|1
end_define

begin_define
define|#
directive|define
name|NEXT_OP_UPWARD
value|2
end_define

begin_define
define|#
directive|define
name|WALK_NON_METHOD
value|0
end_define

begin_define
define|#
directive|define
name|WALK_METHOD
value|1
end_define

begin_define
define|#
directive|define
name|WALK_METHOD_RESTART
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_walk_state
block|{
name|UINT8
name|DataType
decl_stmt|;
comment|/* To differentiate various internal objs MUST BE FIRST!*/
block|\
name|ACPI_OWNER_ID
name|OwnerId
decl_stmt|;
comment|/* Owner of objects created during the walk */
name|BOOLEAN
name|LastPredicate
decl_stmt|;
comment|/* Result of last predicate */
name|UINT8
name|NextOpInfo
decl_stmt|;
comment|/* Info about NextOp */
name|UINT8
name|NumOperands
decl_stmt|;
comment|/* Stack pointer for Operands[] array */
name|UINT8
name|CurrentResult
decl_stmt|;
comment|/* */
name|struct
name|acpi_walk_state
modifier|*
name|Next
decl_stmt|;
comment|/* Next WalkState in list */
name|ACPI_PARSE_OBJECT
modifier|*
name|Origin
decl_stmt|;
comment|/* Start of walk [Obsolete] */
comment|/* TBD: Obsolete with removal of WALK procedure ? */
name|ACPI_PARSE_OBJECT
modifier|*
name|PrevOp
decl_stmt|;
comment|/* Last op that was processed */
name|ACPI_PARSE_OBJECT
modifier|*
name|NextOp
decl_stmt|;
comment|/* next op to be processed */
name|ACPI_GENERIC_STATE
modifier|*
name|Results
decl_stmt|;
comment|/* Stack of accumulated results */
name|ACPI_GENERIC_STATE
modifier|*
name|ControlState
decl_stmt|;
comment|/* List of control states (nested IFs) */
name|ACPI_GENERIC_STATE
modifier|*
name|ScopeInfo
decl_stmt|;
comment|/* Stack of nested scopes */
name|ACPI_PARSE_STATE
modifier|*
name|ParserState
decl_stmt|;
comment|/* Current state of parser */
name|UINT8
modifier|*
name|AmlLastWhile
decl_stmt|;
specifier|const
name|ACPI_OPCODE_INFO
modifier|*
name|OpInfo
decl_stmt|;
comment|/* Info on current opcode */
name|ACPI_PARSE_DOWNWARDS
name|DescendingCallback
decl_stmt|;
name|ACPI_PARSE_UPWARDS
name|AscendingCallback
decl_stmt|;
name|union
name|acpi_operand_obj
modifier|*
name|ReturnDesc
decl_stmt|;
comment|/* Return object, if any */
name|union
name|acpi_operand_obj
modifier|*
name|MethodDesc
decl_stmt|;
comment|/* Method descriptor if running a method */
name|struct
name|acpi_node
modifier|*
name|MethodNode
decl_stmt|;
comment|/* Method Node if running a method */
name|ACPI_PARSE_OBJECT
modifier|*
name|MethodCallOp
decl_stmt|;
comment|/* MethodCall Op if running a method */
name|struct
name|acpi_node
modifier|*
name|MethodCallNode
decl_stmt|;
comment|/* Called method Node*/
name|union
name|acpi_operand_obj
modifier|*
name|Operands
index|[
name|OBJ_NUM_OPERANDS
index|]
decl_stmt|;
comment|/* Operands passed to the interpreter */
name|struct
name|acpi_node
name|Arguments
index|[
name|MTH_NUM_ARGS
index|]
decl_stmt|;
comment|/* Control method arguments */
name|struct
name|acpi_node
name|LocalVariables
index|[
name|MTH_NUM_LOCALS
index|]
decl_stmt|;
comment|/* Control method locals */
name|struct
name|acpi_walk_list
modifier|*
name|WalkList
decl_stmt|;
name|UINT32
name|ParseFlags
decl_stmt|;
name|UINT8
name|WalkType
decl_stmt|;
name|UINT8
name|ReturnUsed
decl_stmt|;
name|UINT16
name|Opcode
decl_stmt|;
comment|/* Current AML opcode */
name|UINT32
name|PrevArgTypes
decl_stmt|;
name|UINT16
name|CurrentSyncLevel
decl_stmt|;
comment|/* Mutex Sync (nested acquire) level */
comment|/* Debug support */
name|UINT32
name|MethodBreakpoint
decl_stmt|;
block|}
name|ACPI_WALK_STATE
typedef|;
end_typedef

begin_comment
comment|/*  * Walk list - head of a tree of walk states.  Multiple walk states are created when there  * are nested control methods executing.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_walk_list
block|{
name|ACPI_WALK_STATE
modifier|*
name|WalkState
decl_stmt|;
name|ACPI_OBJECT_MUTEX
name|AcquiredMutexList
decl_stmt|;
comment|/* List of all currently acquired mutexes */
block|}
name|ACPI_WALK_LIST
typedef|;
end_typedef

begin_comment
comment|/* Info used by AcpiPsInitObjects */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_init_walk_info
block|{
name|UINT16
name|MethodCount
decl_stmt|;
name|UINT16
name|OpRegionCount
decl_stmt|;
name|UINT16
name|FieldCount
decl_stmt|;
name|UINT16
name|OpRegionInit
decl_stmt|;
name|UINT16
name|FieldInit
decl_stmt|;
name|UINT16
name|ObjectCount
decl_stmt|;
name|ACPI_TABLE_DESC
modifier|*
name|TableDesc
decl_stmt|;
block|}
name|ACPI_INIT_WALK_INFO
typedef|;
end_typedef

begin_comment
comment|/* Info used by TBD */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_device_walk_info
block|{
name|UINT16
name|DeviceCount
decl_stmt|;
name|UINT16
name|Num_STA
decl_stmt|;
name|UINT16
name|Num_INI
decl_stmt|;
name|ACPI_TABLE_DESC
modifier|*
name|TableDesc
decl_stmt|;
block|}
name|ACPI_DEVICE_WALK_INFO
typedef|;
end_typedef

begin_comment
comment|/* TBD: [Restructure] Merge with struct above */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_walk_info
block|{
name|UINT32
name|DebugLevel
decl_stmt|;
name|UINT32
name|OwnerId
decl_stmt|;
block|}
name|ACPI_WALK_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_get_devices_info
block|{
name|ACPI_WALK_CALLBACK
name|UserFunction
decl_stmt|;
name|void
modifier|*
name|Context
decl_stmt|;
name|NATIVE_CHAR
modifier|*
name|Hid
decl_stmt|;
block|}
name|ACPI_GET_DEVICES_INFO
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

