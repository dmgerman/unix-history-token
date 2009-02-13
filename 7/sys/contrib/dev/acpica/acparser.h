begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: acparser.h - AML Parser subcomponent prototypes and defines  *       $Revision: 1.83 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
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
comment|/*  * psopcode - AML Opcode information  */
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
name|BOOLEAN
name|AcpiPsIsPrefixChar
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

