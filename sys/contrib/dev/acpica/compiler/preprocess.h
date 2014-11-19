begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: preprocess.h - header for iASL Preprocessor  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
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
name|void
name|PrOpenIncludeFile
parameter_list|(
name|char
modifier|*
name|Filename
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

