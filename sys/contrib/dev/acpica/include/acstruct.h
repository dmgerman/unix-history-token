begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acstruct.h - Internal structs  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
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
comment|/* acpisrc:StructDefs -- for acpisrc conversion */
end_comment

begin_comment
comment|/*****************************************************************************  *  * Tree walking typedefs and structs  *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * Walk state - current state of a parse tree walk. Used for both a leisurely  * stroll through the tree (for whatever reason), and for control method  * execution.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_NEXT_OP_DOWNWARD
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_NEXT_OP_UPWARD
value|2
end_define

begin_comment
comment|/*  * Groups of definitions for WalkType used for different implementations of  * walkers (never simultaneously) - flags for interpreter:  */
end_comment

begin_define
define|#
directive|define
name|ACPI_WALK_NON_METHOD
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_WALK_METHOD
value|0x01
end_define

begin_define
define|#
directive|define
name|ACPI_WALK_METHOD_RESTART
value|0x02
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_walk_state
block|{
name|struct
name|acpi_walk_state
modifier|*
name|Next
decl_stmt|;
comment|/* Next WalkState in list */
name|UINT8
name|DescriptorType
decl_stmt|;
comment|/* To differentiate various internal objs */
name|UINT8
name|WalkType
decl_stmt|;
name|UINT16
name|Opcode
decl_stmt|;
comment|/* Current AML opcode */
name|UINT8
name|NextOpInfo
decl_stmt|;
comment|/* Info about NextOp */
name|UINT8
name|NumOperands
decl_stmt|;
comment|/* Stack pointer for Operands[] array */
name|UINT8
name|OperandIndex
decl_stmt|;
comment|/* Index into operand stack, to be used by AcpiDsObjStackPush */
name|ACPI_OWNER_ID
name|OwnerId
decl_stmt|;
comment|/* Owner of objects created during the walk */
name|BOOLEAN
name|LastPredicate
decl_stmt|;
comment|/* Result of last predicate */
name|UINT8
name|CurrentResult
decl_stmt|;
name|UINT8
name|ReturnUsed
decl_stmt|;
name|UINT8
name|ScopeDepth
decl_stmt|;
name|UINT8
name|PassNumber
decl_stmt|;
comment|/* Parse pass during table load */
name|BOOLEAN
name|NamespaceOverride
decl_stmt|;
comment|/* Override existing objects */
name|UINT8
name|ResultSize
decl_stmt|;
comment|/* Total elements for the result stack */
name|UINT8
name|ResultCount
decl_stmt|;
comment|/* Current number of occupied elements of result stack */
name|UINT8
modifier|*
name|Aml
decl_stmt|;
name|UINT32
name|ArgTypes
decl_stmt|;
name|UINT32
name|MethodBreakpoint
decl_stmt|;
comment|/* For single stepping */
name|UINT32
name|UserBreakpoint
decl_stmt|;
comment|/* User AML breakpoint */
name|UINT32
name|ParseFlags
decl_stmt|;
name|ACPI_PARSE_STATE
name|ParserState
decl_stmt|;
comment|/* Current state of parser */
name|UINT32
name|PrevArgTypes
decl_stmt|;
name|UINT32
name|ArgCount
decl_stmt|;
comment|/* push for fixed or var args */
name|struct
name|acpi_namespace_node
name|Arguments
index|[
name|ACPI_METHOD_NUM_ARGS
index|]
decl_stmt|;
comment|/* Control method arguments */
name|struct
name|acpi_namespace_node
name|LocalVariables
index|[
name|ACPI_METHOD_NUM_LOCALS
index|]
decl_stmt|;
comment|/* Control method locals */
name|union
name|acpi_operand_object
modifier|*
name|Operands
index|[
name|ACPI_OBJ_NUM_OPERANDS
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Operands passed to the interpreter (+1 for NULL terminator) */
name|union
name|acpi_operand_object
modifier|*
modifier|*
name|Params
decl_stmt|;
name|UINT8
modifier|*
name|AmlLastWhile
decl_stmt|;
name|union
name|acpi_operand_object
modifier|*
modifier|*
name|CallerReturnDesc
decl_stmt|;
name|ACPI_GENERIC_STATE
modifier|*
name|ControlState
decl_stmt|;
comment|/* List of control states (nested IFs) */
name|struct
name|acpi_namespace_node
modifier|*
name|DeferredNode
decl_stmt|;
comment|/* Used when executing deferred opcodes */
name|union
name|acpi_operand_object
modifier|*
name|ImplicitReturnObj
decl_stmt|;
name|struct
name|acpi_namespace_node
modifier|*
name|MethodCallNode
decl_stmt|;
comment|/* Called method Node*/
name|ACPI_PARSE_OBJECT
modifier|*
name|MethodCallOp
decl_stmt|;
comment|/* MethodCall Op if running a method */
name|union
name|acpi_operand_object
modifier|*
name|MethodDesc
decl_stmt|;
comment|/* Method descriptor if running a method */
name|struct
name|acpi_namespace_node
modifier|*
name|MethodNode
decl_stmt|;
comment|/* Method node if running a method. */
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
decl_stmt|;
comment|/* Current parser op */
specifier|const
name|ACPI_OPCODE_INFO
modifier|*
name|OpInfo
decl_stmt|;
comment|/* Info on current opcode */
name|ACPI_PARSE_OBJECT
modifier|*
name|Origin
decl_stmt|;
comment|/* Start of walk [Obsolete] */
name|union
name|acpi_operand_object
modifier|*
name|ResultObj
decl_stmt|;
name|ACPI_GENERIC_STATE
modifier|*
name|Results
decl_stmt|;
comment|/* Stack of accumulated results */
name|union
name|acpi_operand_object
modifier|*
name|ReturnDesc
decl_stmt|;
comment|/* Return object, if any */
name|ACPI_GENERIC_STATE
modifier|*
name|ScopeInfo
decl_stmt|;
comment|/* Stack of nested scopes */
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
name|ACPI_THREAD_STATE
modifier|*
name|Thread
decl_stmt|;
name|ACPI_PARSE_DOWNWARDS
name|DescendingCallback
decl_stmt|;
name|ACPI_PARSE_UPWARDS
name|AscendingCallback
decl_stmt|;
block|}
name|ACPI_WALK_STATE
typedef|;
end_typedef

begin_comment
comment|/* Info used by AcpiNsInitializeObjects and AcpiDsInitializeObjects */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_init_walk_info
block|{
name|UINT32
name|TableIndex
decl_stmt|;
name|UINT32
name|ObjectCount
decl_stmt|;
name|UINT32
name|MethodCount
decl_stmt|;
name|UINT32
name|SerialMethodCount
decl_stmt|;
name|UINT32
name|NonSerialMethodCount
decl_stmt|;
name|UINT32
name|SerializedMethodCount
decl_stmt|;
name|UINT32
name|DeviceCount
decl_stmt|;
name|UINT32
name|OpRegionCount
decl_stmt|;
name|UINT32
name|FieldCount
decl_stmt|;
name|UINT32
name|BufferCount
decl_stmt|;
name|UINT32
name|PackageCount
decl_stmt|;
name|UINT32
name|OpRegionInit
decl_stmt|;
name|UINT32
name|FieldInit
decl_stmt|;
name|UINT32
name|BufferInit
decl_stmt|;
name|UINT32
name|PackageInit
decl_stmt|;
name|ACPI_OWNER_ID
name|OwnerId
decl_stmt|;
block|}
name|ACPI_INIT_WALK_INFO
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
name|char
modifier|*
name|Hid
decl_stmt|;
block|}
name|ACPI_GET_DEVICES_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|acpi_aml_operands
block|{
name|ACPI_OPERAND_OBJECT
modifier|*
name|Operands
index|[
literal|7
index|]
decl_stmt|;
struct|struct
block|{
name|ACPI_OBJECT_INTEGER
modifier|*
name|Type
decl_stmt|;
name|ACPI_OBJECT_INTEGER
modifier|*
name|Code
decl_stmt|;
name|ACPI_OBJECT_INTEGER
modifier|*
name|Argument
decl_stmt|;
block|}
name|Fatal
struct|;
struct|struct
block|{
name|ACPI_OPERAND_OBJECT
modifier|*
name|Source
decl_stmt|;
name|ACPI_OBJECT_INTEGER
modifier|*
name|Index
decl_stmt|;
name|ACPI_OPERAND_OBJECT
modifier|*
name|Target
decl_stmt|;
block|}
name|Index
struct|;
struct|struct
block|{
name|ACPI_OPERAND_OBJECT
modifier|*
name|Source
decl_stmt|;
name|ACPI_OBJECT_INTEGER
modifier|*
name|Index
decl_stmt|;
name|ACPI_OBJECT_INTEGER
modifier|*
name|Length
decl_stmt|;
name|ACPI_OPERAND_OBJECT
modifier|*
name|Target
decl_stmt|;
block|}
name|Mid
struct|;
block|}
name|ACPI_AML_OPERANDS
typedef|;
end_typedef

begin_comment
comment|/*  * Structure used to pass object evaluation information and parameters.  * Purpose is to reduce CPU stack use.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_evaluate_info
block|{
comment|/* The first 3 elements are passed by the caller to AcpiNsEvaluate */
name|ACPI_NAMESPACE_NODE
modifier|*
name|PrefixNode
decl_stmt|;
comment|/* Input: starting node */
specifier|const
name|char
modifier|*
name|RelativePathname
decl_stmt|;
comment|/* Input: path relative to PrefixNode */
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|Parameters
decl_stmt|;
comment|/* Input: argument list */
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
decl_stmt|;
comment|/* Resolved node (PrefixNode:RelativePathname) */
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
decl_stmt|;
comment|/* Object attached to the resolved node */
name|char
modifier|*
name|FullPathname
decl_stmt|;
comment|/* Full pathname of the resolved node */
specifier|const
name|ACPI_PREDEFINED_INFO
modifier|*
name|Predefined
decl_stmt|;
comment|/* Used if Node is a predefined name */
name|ACPI_OPERAND_OBJECT
modifier|*
name|ReturnObject
decl_stmt|;
comment|/* Object returned from the evaluation */
name|union
name|acpi_operand_object
modifier|*
name|ParentPackage
decl_stmt|;
comment|/* Used if return object is a Package */
name|UINT32
name|ReturnFlags
decl_stmt|;
comment|/* Used for return value analysis */
name|UINT32
name|ReturnBtype
decl_stmt|;
comment|/* Bitmapped type of the returned object */
name|UINT16
name|ParamCount
decl_stmt|;
comment|/* Count of the input argument list */
name|UINT8
name|PassNumber
decl_stmt|;
comment|/* Parser pass number */
name|UINT8
name|ReturnObjectType
decl_stmt|;
comment|/* Object type of the returned object */
name|UINT8
name|NodeFlags
decl_stmt|;
comment|/* Same as Node->Flags */
name|UINT8
name|Flags
decl_stmt|;
comment|/* General flags */
block|}
name|ACPI_EVALUATE_INFO
typedef|;
end_typedef

begin_comment
comment|/* Values for Flags above */
end_comment

begin_define
define|#
directive|define
name|ACPI_IGNORE_RETURN_VALUE
value|1
end_define

begin_comment
comment|/* Defines for ReturnFlags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_OBJECT_REPAIRED
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_OBJECT_WRAPPED
value|2
end_define

begin_comment
comment|/* Info used by AcpiNsInitializeDevices */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_device_walk_info
block|{
name|ACPI_TABLE_DESC
modifier|*
name|TableDesc
decl_stmt|;
name|ACPI_EVALUATE_INFO
modifier|*
name|EvaluateInfo
decl_stmt|;
name|UINT32
name|DeviceCount
decl_stmt|;
name|UINT32
name|Num_STA
decl_stmt|;
name|UINT32
name|Num_INI
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
name|Count
decl_stmt|;
name|ACPI_OWNER_ID
name|OwnerId
decl_stmt|;
name|UINT8
name|DisplayType
decl_stmt|;
block|}
name|ACPI_WALK_INFO
typedef|;
end_typedef

begin_comment
comment|/* Display Types */
end_comment

begin_define
define|#
directive|define
name|ACPI_DISPLAY_SUMMARY
value|(UINT8) 0
end_define

begin_define
define|#
directive|define
name|ACPI_DISPLAY_OBJECTS
value|(UINT8) 1
end_define

begin_define
define|#
directive|define
name|ACPI_DISPLAY_MASK
value|(UINT8) 1
end_define

begin_define
define|#
directive|define
name|ACPI_DISPLAY_SHORT
value|(UINT8) 2
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

