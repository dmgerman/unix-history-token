begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acstruct.h - Internal structs  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
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

begin_comment
comment|/* Flags for iASL compiler only */
end_comment

begin_define
define|#
directive|define
name|ACPI_WALK_CONST_REQUIRED
value|0x10
end_define

begin_define
define|#
directive|define
name|ACPI_WALK_CONST_OPTIONAL
value|0x20
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
name|UINT8
name|ResultSize
decl_stmt|;
comment|/* Total elements for the result stack */
name|UINT8
name|ResultCount
decl_stmt|;
comment|/* Current number of occupied elements of result stack */
name|UINT32
name|AmlOffset
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

