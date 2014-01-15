begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: acparser.h - AML Parser subcomponent prototypes and defines  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACPARSER_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACPARSER_H__
end_define

begin_define
define|#
directive|define
name|OP_HAS_RETURN_VALUE
value|1
end_define

begin_comment
comment|/* Variable number of arguments. This field must be 32 bits */
end_comment

begin_define
define|#
directive|define
name|ACPI_VAR_ARGS
value|ACPI_UINT32_MAX
end_define

begin_define
define|#
directive|define
name|ACPI_PARSE_DELETE_TREE
value|0x0001
end_define

begin_define
define|#
directive|define
name|ACPI_PARSE_NO_TREE_DELETE
value|0x0000
end_define

begin_define
define|#
directive|define
name|ACPI_PARSE_TREE_MASK
value|0x0001
end_define

begin_define
define|#
directive|define
name|ACPI_PARSE_LOAD_PASS1
value|0x0010
end_define

begin_define
define|#
directive|define
name|ACPI_PARSE_LOAD_PASS2
value|0x0020
end_define

begin_define
define|#
directive|define
name|ACPI_PARSE_EXECUTE
value|0x0030
end_define

begin_define
define|#
directive|define
name|ACPI_PARSE_MODE_MASK
value|0x0030
end_define

begin_define
define|#
directive|define
name|ACPI_PARSE_DEFERRED_OP
value|0x0100
end_define

begin_define
define|#
directive|define
name|ACPI_PARSE_DISASSEMBLE
value|0x0200
end_define

begin_define
define|#
directive|define
name|ACPI_PARSE_MODULE_LEVEL
value|0x0400
end_define

begin_comment
comment|/******************************************************************************  *  * Parser interfaces  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * psxface - Parser external interfaces  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiPsExecuteMethod
parameter_list|(
name|ACPI_EVALUATE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * psargs - Parse AML opcode arguments  */
end_comment

begin_function_decl
name|UINT8
modifier|*
name|AcpiPsGetNextPackageEnd
parameter_list|(
name|ACPI_PARSE_STATE
modifier|*
name|ParserState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|AcpiPsGetNextNamestring
parameter_list|(
name|ACPI_PARSE_STATE
modifier|*
name|ParserState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiPsGetNextSimpleArg
parameter_list|(
name|ACPI_PARSE_STATE
modifier|*
name|ParserState
parameter_list|,
name|UINT32
name|ArgType
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiPsGetNextNamepath
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|ACPI_PARSE_STATE
modifier|*
name|ParserState
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Arg
parameter_list|,
name|BOOLEAN
name|MethodCall
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiPsGetNextArg
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|ACPI_PARSE_STATE
modifier|*
name|ParserState
parameter_list|,
name|UINT32
name|ArgType
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
modifier|*
name|ReturnArg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * psfind  */
end_comment

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|AcpiPsFindName
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Scope
parameter_list|,
name|UINT32
name|Name
parameter_list|,
name|UINT32
name|Opcode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|AcpiPsGetParent
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * psobject - support for parse object processing  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiPsBuildNamedOp
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|UINT8
modifier|*
name|AmlOpStart
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|UnnamedOp
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiPsCreateOp
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|UINT8
modifier|*
name|AmlOpStart
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
modifier|*
name|NewOp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiPsCompleteOp
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
modifier|*
name|Op
parameter_list|,
name|ACPI_STATUS
name|Status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiPsCompleteFinalOp
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|ACPI_STATUS
name|Status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * psopinfo - AML Opcode information  */
end_comment

begin_function_decl
specifier|const
name|ACPI_OPCODE_INFO
modifier|*
name|AcpiPsGetOpcodeInfo
parameter_list|(
name|UINT16
name|Opcode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|AcpiPsGetOpcodeName
parameter_list|(
name|UINT16
name|Opcode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT8
name|AcpiPsGetArgumentCount
parameter_list|(
name|UINT32
name|OpType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * psparse - top level parsing routines  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiPsParseAml
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiPsGetOpcodeSize
parameter_list|(
name|UINT32
name|Opcode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT16
name|AcpiPsPeekOpcode
parameter_list|(
name|ACPI_PARSE_STATE
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiPsCompleteThisOp
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
name|ACPI_STATUS
name|AcpiPsNextParseState
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|ACPI_STATUS
name|CallbackStatus
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * psloop - main parse loop  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiPsParseLoop
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * psscope - Scope stack management routines  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiPsInitScope
parameter_list|(
name|ACPI_PARSE_STATE
modifier|*
name|ParserState
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Root
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|AcpiPsGetParentScope
parameter_list|(
name|ACPI_PARSE_STATE
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiPsHasCompletedScope
parameter_list|(
name|ACPI_PARSE_STATE
modifier|*
name|ParserState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiPsPopScope
parameter_list|(
name|ACPI_PARSE_STATE
modifier|*
name|ParserState
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
modifier|*
name|Op
parameter_list|,
name|UINT32
modifier|*
name|ArgList
parameter_list|,
name|UINT32
modifier|*
name|ArgCount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiPsPushScope
parameter_list|(
name|ACPI_PARSE_STATE
modifier|*
name|ParserState
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|RemainingArgs
parameter_list|,
name|UINT32
name|ArgCount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiPsCleanupScope
parameter_list|(
name|ACPI_PARSE_STATE
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * pstree - parse tree manipulation routines  */
end_comment

begin_function_decl
name|void
name|AcpiPsAppendArg
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|op
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|AcpiPsFind
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Scope
parameter_list|,
name|char
modifier|*
name|Path
parameter_list|,
name|UINT16
name|Opcode
parameter_list|,
name|UINT32
name|Create
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|AcpiPsGetArg
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|op
parameter_list|,
name|UINT32
name|argn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|AcpiPsGetDepthNext
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Origin
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * pswalk - parse tree walk routines  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiPsWalkParsedAml
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|StartOp
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|EndOp
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|MthDesc
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|StartNode
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|Params
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|CallerReturnDesc
parameter_list|,
name|ACPI_OWNER_ID
name|OwnerId
parameter_list|,
name|ACPI_PARSE_DOWNWARDS
name|DescendingCallback
parameter_list|,
name|ACPI_PARSE_UPWARDS
name|AscendingCallback
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiPsGetNextWalkOp
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|ACPI_PARSE_UPWARDS
name|AscendingCallback
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiPsDeleteCompletedOp
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiPsDeleteParseTree
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|root
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * psutils - parser utilities  */
end_comment

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|AcpiPsCreateScopeOp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiPsInitOp
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|op
parameter_list|,
name|UINT16
name|opcode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_PARSE_OBJECT
modifier|*
name|AcpiPsAllocOp
parameter_list|(
name|UINT16
name|opcode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiPsFreeOp
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiPsIsLeadingChar
parameter_list|(
name|UINT32
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiPsGetName
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiPsSetName
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|op
parameter_list|,
name|UINT32
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * psdump - display parser tree  */
end_comment

begin_function_decl
name|UINT32
name|AcpiPsSprintPath
parameter_list|(
name|char
modifier|*
name|BufferStart
parameter_list|,
name|UINT32
name|BufferSize
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiPsSprintOp
parameter_list|(
name|char
modifier|*
name|BufferStart
parameter_list|,
name|UINT32
name|BufferSize
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiPsShow
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|op
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACPARSER_H__ */
end_comment

end_unit

