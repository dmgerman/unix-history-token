begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: preprocess.h - header for iASL Preprocessor  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|__PREPROCESS_H__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PREPROCESS
end_ifndef

begin_define
define|#
directive|define
name|_PREPROCESS
end_define

begin_undef
undef|#
directive|undef
name|PR_EXTERN
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|_DECLARE_PR_GLOBALS
end_ifdef

begin_define
define|#
directive|define
name|PR_EXTERN
end_define

begin_define
define|#
directive|define
name|PR_INIT_GLOBAL
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
name|PR_EXTERN
value|extern
end_define

begin_define
define|#
directive|define
name|PR_INIT_GLOBAL
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
comment|/*  * Configuration  */
end_comment

begin_define
define|#
directive|define
name|PR_MAX_MACRO_ARGS
value|32
end_define

begin_comment
comment|/* Max number of macro args */
end_comment

begin_define
define|#
directive|define
name|PR_MAX_ARG_INSTANCES
value|24
end_define

begin_comment
comment|/* Max instances of any one arg */
end_comment

begin_define
define|#
directive|define
name|PR_LINES_PER_BLOCK
value|4096
end_define

begin_comment
comment|/* Max input source lines per block */
end_comment

begin_comment
comment|/*  * Local defines and macros  */
end_comment

begin_define
define|#
directive|define
name|PR_TOKEN_SEPARATORS
value|" ,(){}\t\n"
end_define

begin_define
define|#
directive|define
name|PR_MACRO_SEPARATORS
value|" ,(){}~!*/%+-<>=&^|\"\t\n"
end_define

begin_define
define|#
directive|define
name|PR_MACRO_ARGUMENTS
value|" ,\t\n"
end_define

begin_define
define|#
directive|define
name|PR_EXPR_SEPARATORS
value|" ,(){}~!*/%+-<>=&^|\"\t\n"
end_define

begin_define
define|#
directive|define
name|PR_PREFIX_ID
value|"Pr(%.4u) - "
end_define

begin_comment
comment|/* Used for debug output */
end_comment

begin_define
define|#
directive|define
name|THIS_TOKEN_OFFSET
parameter_list|(
name|t
parameter_list|)
value|((t-Gbl_MainTokenBuffer) + 1)
end_define

begin_comment
comment|/*  * Preprocessor structures  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pr_macro_arg
block|{
name|char
modifier|*
name|Name
decl_stmt|;
name|UINT32
name|Offset
index|[
name|PR_MAX_ARG_INSTANCES
index|]
decl_stmt|;
name|UINT16
name|UseCount
decl_stmt|;
block|}
name|PR_MACRO_ARG
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|pr_define_info
block|{
name|struct
name|pr_define_info
modifier|*
name|Previous
decl_stmt|;
name|struct
name|pr_define_info
modifier|*
name|Next
decl_stmt|;
name|char
modifier|*
name|Identifier
decl_stmt|;
name|char
modifier|*
name|Replacement
decl_stmt|;
name|char
modifier|*
name|Body
decl_stmt|;
comment|/* Macro body */
name|PR_MACRO_ARG
modifier|*
name|Args
decl_stmt|;
comment|/* Macro arg list */
name|UINT16
name|ArgCount
decl_stmt|;
comment|/* Macro arg count */
name|BOOLEAN
name|Persist
decl_stmt|;
comment|/* Keep for entire compiler run */
block|}
name|PR_DEFINE_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|pr_directive_info
block|{
name|char
modifier|*
name|Name
decl_stmt|;
comment|/* Directive name */
name|UINT8
name|ArgCount
decl_stmt|;
comment|/* Required # of args */
block|}
name|PR_DIRECTIVE_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|pr_operator_info
block|{
name|char
modifier|*
name|Op
decl_stmt|;
block|}
name|PR_OPERATOR_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|pr_file_node
block|{
name|struct
name|pr_file_node
modifier|*
name|Next
decl_stmt|;
name|FILE
modifier|*
name|File
decl_stmt|;
name|char
modifier|*
name|Filename
decl_stmt|;
name|UINT32
name|CurrentLineNumber
decl_stmt|;
block|}
name|PR_FILE_NODE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_ARGUMENT_LENGTH
value|24
end_define

begin_typedef
typedef|typedef
struct|struct
name|directive_info
block|{
name|struct
name|directive_info
modifier|*
name|Next
decl_stmt|;
name|char
name|Argument
index|[
name|MAX_ARGUMENT_LENGTH
index|]
decl_stmt|;
name|int
name|Directive
decl_stmt|;
name|BOOLEAN
name|IgnoringThisCodeBlock
decl_stmt|;
block|}
name|DIRECTIVE_INFO
typedef|;
end_typedef

begin_comment
comment|/*  * Globals  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* TBD for macros */
end_comment

begin_comment
unit|PR_EXTERN char                  PR_INIT_GLOBAL (*XXXEvalBuffer, NULL);
comment|/* [ASL_LINE_BUFFER_SIZE]; */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|PR_EXTERN
name|char
name|PR_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_MainTokenBuffer
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* [ASL_LINE_BUFFER_SIZE]; */
end_comment

begin_decl_stmt
name|PR_EXTERN
name|char
name|PR_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_MacroTokenBuffer
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* [ASL_LINE_BUFFER_SIZE]; */
end_comment

begin_decl_stmt
name|PR_EXTERN
name|char
name|PR_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_ExpressionTokenBuffer
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* [ASL_LINE_BUFFER_SIZE]; */
end_comment

begin_decl_stmt
name|PR_EXTERN
name|UINT32
name|Gbl_PreprocessorLineNumber
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PR_EXTERN
name|int
name|Gbl_IfDepth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PR_EXTERN
name|PR_FILE_NODE
modifier|*
name|Gbl_InputFileList
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PR_EXTERN
name|PR_DEFINE_INFO
name|PR_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_DefineList
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|PR_EXTERN
name|BOOLEAN
name|PR_INIT_GLOBAL
parameter_list|(
name|Gbl_PreprocessorError
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PR_EXTERN
name|BOOLEAN
name|PR_INIT_GLOBAL
parameter_list|(
name|Gbl_IgnoringThisCodeBlock
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|PR_EXTERN
name|DIRECTIVE_INFO
name|PR_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_DirectiveStack
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * prscan - Preprocessor entry  */
end_comment

begin_function_decl
name|void
name|PrInitializePreprocessor
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrInitializeGlobals
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrTerminatePreprocessor
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrDoPreprocess
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT64
name|PrIsDefined
parameter_list|(
name|char
modifier|*
name|Identifier
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT64
name|PrResolveDefine
parameter_list|(
name|char
modifier|*
name|Identifier
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|PrInitLexer
parameter_list|(
name|char
modifier|*
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrTerminateLexer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * prmacros - Support for #defines and macros  */
end_comment

begin_function_decl
name|void
name|PrDumpPredefinedNames
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PR_DEFINE_INFO
modifier|*
name|PrAddDefine
parameter_list|(
name|char
modifier|*
name|Token
parameter_list|,
name|char
modifier|*
name|Token2
parameter_list|,
name|BOOLEAN
name|Persist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrRemoveDefine
parameter_list|(
name|char
modifier|*
name|DefineName
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PR_DEFINE_INFO
modifier|*
name|PrMatchDefine
parameter_list|(
name|char
modifier|*
name|MatchString
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrAddMacro
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|,
name|char
modifier|*
modifier|*
name|Next
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrDoMacroInvocation
parameter_list|(
name|char
modifier|*
name|TokenBuffer
parameter_list|,
name|char
modifier|*
name|MacroStart
parameter_list|,
name|PR_DEFINE_INFO
modifier|*
name|DefineInfo
parameter_list|,
name|char
modifier|*
modifier|*
name|Next
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * prexpress - #if expression support  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|PrResolveIntegerExpression
parameter_list|(
name|char
modifier|*
name|Line
parameter_list|,
name|UINT64
modifier|*
name|ReturnValue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|PrPrioritizeExpression
parameter_list|(
name|char
modifier|*
name|OriginalLine
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * prparser - lex/yacc expression parser  */
end_comment

begin_function_decl
name|UINT64
name|PrEvaluateExpression
parameter_list|(
name|char
modifier|*
name|ExprString
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * prutils - Preprocesor utilities  */
end_comment

begin_function_decl
name|char
modifier|*
name|PrGetNextToken
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|char
modifier|*
name|MatchString
parameter_list|,
name|char
modifier|*
modifier|*
name|Next
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrError
parameter_list|(
name|UINT8
name|Level
parameter_list|,
name|UINT16
name|MessageId
parameter_list|,
name|UINT32
name|Column
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrReplaceData
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|UINT32
name|LengthToRemove
parameter_list|,
name|char
modifier|*
name|BufferToAdd
parameter_list|,
name|UINT32
name|LengthToAdd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|PrOpenIncludeFile
parameter_list|(
name|char
modifier|*
name|Filename
parameter_list|,
name|char
modifier|*
name|OpenMode
parameter_list|,
name|char
modifier|*
modifier|*
name|FullPathname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|PrOpenIncludeWithPrefix
parameter_list|(
name|char
modifier|*
name|PrefixDir
parameter_list|,
name|char
modifier|*
name|Filename
parameter_list|,
name|char
modifier|*
name|OpenMode
parameter_list|,
name|char
modifier|*
modifier|*
name|FullPathname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrPushInputFileStack
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
name|BOOLEAN
name|PrPopInputFileStack
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

