begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ClangUserExpression.h -----------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_ClangUserExpression_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ClangUserExpression_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Address.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ClangForward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/ClangExpression.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/ClangExpressionVariable.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/IRForTarget.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/Materializer.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/TaggedASTType.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ExecutionContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/JITMemoryManager.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class ClangUserExpression ClangUserExpression.h "lldb/Expression/ClangUserExpression.h"
comment|/// @brief Encapsulates a single expression for use with Clang
comment|///
comment|/// LLDB uses expressions for various purposes, notably to call functions
comment|/// and as a backend for the expr command.  ClangUserExpression encapsulates
comment|/// the objects needed to parse and interpret or JIT an expression.  It
comment|/// uses the Clang parser to produce LLVM IR from the expression.
comment|//----------------------------------------------------------------------
name|class
name|ClangUserExpression
range|:
name|public
name|ClangExpression
block|{
name|public
operator|:
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|ClangUserExpression
operator|>
name|ClangUserExpressionSP
expr_stmt|;
block|enum
block|{
name|kDefaultTimeout
operator|=
literal|500000u
block|}
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Constructor
comment|///
comment|/// @param[in] expr
comment|///     The expression to parse.
comment|///
comment|/// @param[in] expr_prefix
comment|///     If non-NULL, a C string containing translation-unit level
comment|///     definitions to be included when the expression is parsed.
comment|///
comment|/// @param[in] language
comment|///     If not eLanguageTypeUnknown, a language to use when parsing
comment|///     the expression.  Currently restricted to those languages
comment|///     supported by Clang.
comment|///
comment|/// @param[in] desired_type
comment|///     If not eResultTypeAny, the type to use for the expression
comment|///     result.
comment|//------------------------------------------------------------------
name|ClangUserExpression
argument_list|(
argument|const char *expr
argument_list|,
argument|const char *expr_prefix
argument_list|,
argument|lldb::LanguageType language
argument_list|,
argument|ResultType desired_type
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|//------------------------------------------------------------------
name|virtual
operator|~
name|ClangUserExpression
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Parse the expression
comment|///
comment|/// @param[in] error_stream
comment|///     A stream to print parse errors and warnings to.
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to use when looking up entities that
comment|///     are needed for parsing (locations of functions, types of
comment|///     variables, persistent variables, etc.)
comment|///
comment|/// @param[in] execution_policy
comment|///     Determines whether interpretation is possible or mandatory.
comment|///
comment|/// @param[in] keep_result_in_memory
comment|///     True if the resulting persistent variable should reside in
comment|///     target memory, if applicable.
comment|///
comment|/// @return
comment|///     True on success (no errors); false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|Parse
argument_list|(
name|Stream
operator|&
name|error_stream
argument_list|,
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|,
name|lldb_private
operator|::
name|ExecutionPolicy
name|execution_policy
argument_list|,
name|bool
name|keep_result_in_memory
argument_list|)
decl_stmt|;
name|bool
name|CanInterpret
parameter_list|()
block|{
return|return
name|m_can_interpret
return|;
block|}
name|bool
name|MatchesContext
parameter_list|(
name|ExecutionContext
modifier|&
name|exe_ctx
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Execute the parsed expression
comment|///
comment|/// @param[in] error_stream
comment|///     A stream to print errors to.
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to use when looking up entities that
comment|///     are needed for parsing (locations of variables, etc.)
comment|///
comment|/// @param[in] options
comment|///     Expression evaluation options.
comment|///
comment|/// @param[in] shared_ptr_to_me
comment|///     This is a shared pointer to this ClangUserExpression.  This is
comment|///     needed because Execute can push a thread plan that will hold onto
comment|///     the ClangUserExpression for an unbounded period of time.  So you
comment|///     need to give the thread plan a reference to this object that can
comment|///     keep it alive.
comment|///
comment|/// @param[in] result
comment|///     A pointer to direct at the persistent variable in which the
comment|///     expression's result is stored.
comment|///
comment|/// @return
comment|///     A Process::Execution results value.
comment|//------------------------------------------------------------------
name|ExecutionResults
name|Execute
argument_list|(
name|Stream
operator|&
name|error_stream
argument_list|,
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|,
specifier|const
name|EvaluateExpressionOptions
operator|&
name|options
argument_list|,
name|ClangUserExpressionSP
operator|&
name|shared_ptr_to_me
argument_list|,
name|lldb
operator|::
name|ClangExpressionVariableSP
operator|&
name|result
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Apply the side effects of the function to program state.
comment|///
comment|/// @param[in] error_stream
comment|///     A stream to print errors to.
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to use when looking up entities that
comment|///     are needed for parsing (locations of variables, etc.)
comment|///
comment|/// @param[in] result
comment|///     A pointer to direct at the persistent variable in which the
comment|///     expression's result is stored.
comment|///
comment|/// @param[in] function_stack_pointer
comment|///     A pointer to the base of the function's stack frame.  This
comment|///     is used to determine whether the expession result resides in
comment|///     memory that will still be valid, or whether it needs to be
comment|///     treated as homeless for the purpose of future expressions.
comment|///
comment|/// @return
comment|///     A Process::Execution results value.
comment|//------------------------------------------------------------------
name|bool
name|FinalizeJITExecution
argument_list|(
name|Stream
operator|&
name|error_stream
argument_list|,
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|,
name|lldb
operator|::
name|ClangExpressionVariableSP
operator|&
name|result
argument_list|,
name|lldb
operator|::
name|addr_t
name|function_stack_bottom
operator|=
name|LLDB_INVALID_ADDRESS
argument_list|,
name|lldb
operator|::
name|addr_t
name|function_stack_top
operator|=
name|LLDB_INVALID_ADDRESS
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return the string that the parser should parse.  Must be a full
comment|/// translation unit.
comment|//------------------------------------------------------------------
specifier|const
name|char
modifier|*
name|Text
parameter_list|()
block|{
return|return
name|m_transformed_text
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the string that the user typed.
comment|//------------------------------------------------------------------
specifier|const
name|char
modifier|*
name|GetUserText
parameter_list|()
block|{
return|return
name|m_expr_text
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the function name that should be used for executing the
comment|/// expression.  Text() should contain the definition of this
comment|/// function.
comment|//------------------------------------------------------------------
specifier|const
name|char
modifier|*
name|FunctionName
parameter_list|()
block|{
return|return
literal|"$__lldb_expr"
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the language that should be used when parsing.  To use
comment|/// the default, return eLanguageTypeUnknown.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|LanguageType
name|Language
argument_list|()
block|{
return|return
name|m_language
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the object that the parser should use when resolving external
comment|/// values.  May be NULL if everything should be self-contained.
comment|//------------------------------------------------------------------
name|ClangExpressionDeclMap
modifier|*
name|DeclMap
parameter_list|()
block|{
return|return
name|m_expr_decl_map
operator|.
name|get
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the object that the parser should allow to access ASTs.
comment|/// May be NULL if the ASTs do not need to be transformed.
comment|///
comment|/// @param[in] passthrough
comment|///     The ASTConsumer that the returned transformer should send
comment|///     the ASTs to after transformation.
comment|//------------------------------------------------------------------
name|clang
operator|::
name|ASTConsumer
operator|*
name|ASTTransformer
argument_list|(
name|clang
operator|::
name|ASTConsumer
operator|*
name|passthrough
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return the desired result type of the function, or
comment|/// eResultTypeAny if indifferent.
comment|//------------------------------------------------------------------
name|virtual
name|ResultType
name|DesiredResultType
parameter_list|()
block|{
return|return
name|m_desired_type
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return true if validation code should be inserted into the
comment|/// expression.
comment|//------------------------------------------------------------------
name|bool
name|NeedsValidation
parameter_list|()
block|{
return|return
name|true
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return true if external variables in the expression should be
comment|/// resolved.
comment|//------------------------------------------------------------------
name|bool
name|NeedsVariableResolution
parameter_list|()
block|{
return|return
name|true
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Evaluate one expression and return its result.
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to use when evaluating the expression.
comment|///
comment|/// @param[in] options
comment|///     Expression evaluation options.
comment|///
comment|/// @param[in] expr_cstr
comment|///     A C string containing the expression to be evaluated.
comment|///
comment|/// @param[in] expr_prefix
comment|///     If non-NULL, a C string containing translation-unit level
comment|///     definitions to be included when the expression is parsed.
comment|///
comment|/// @param[in/out] result_valobj_sp
comment|///      If execution is successful, the result valobj is placed here.
comment|///
comment|/// @param[out]
comment|///     Filled in with an error in case the expression evaluation
comment|///     fails to parse, run, or evaluated.
comment|///
comment|/// @result
comment|///      A Process::ExecutionResults value.  eExecutionCompleted for success.
comment|//------------------------------------------------------------------
specifier|static
name|ExecutionResults
name|Evaluate
argument_list|(
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|,
specifier|const
name|EvaluateExpressionOptions
operator|&
name|options
argument_list|,
specifier|const
name|char
operator|*
name|expr_cstr
argument_list|,
specifier|const
name|char
operator|*
name|expr_prefix
argument_list|,
name|lldb
operator|::
name|ValueObjectSP
operator|&
name|result_valobj_sp
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|Error
operator|::
name|ValueType
name|kNoResult
operator|=
literal|0x1001
expr_stmt|;
comment|///< ValueObject::GetError() returns this if there is no result from the expression.
name|private
label|:
comment|//------------------------------------------------------------------
comment|/// Populate m_cplusplus and m_objetivec based on the environment.
comment|//------------------------------------------------------------------
name|void
name|ScanContext
argument_list|(
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|,
name|lldb_private
operator|::
name|Error
operator|&
name|err
argument_list|)
decl_stmt|;
name|bool
name|PrepareToExecuteJITExpression
argument_list|(
name|Stream
operator|&
name|error_stream
argument_list|,
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|struct_address
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|object_ptr
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|cmd_ptr
argument_list|)
decl_stmt|;
name|void
name|InstallContext
parameter_list|(
name|ExecutionContext
modifier|&
name|exe_ctx
parameter_list|)
function_decl|;
name|bool
name|LockAndCheckContext
argument_list|(
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|,
name|lldb
operator|::
name|TargetSP
operator|&
name|target_sp
argument_list|,
name|lldb
operator|::
name|ProcessSP
operator|&
name|process_sp
argument_list|,
name|lldb
operator|::
name|StackFrameSP
operator|&
name|frame_sp
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|ProcessWP
name|m_process_wp
expr_stmt|;
comment|///< The process used as the context for the expression.
name|Address
name|m_address
decl_stmt|;
comment|///< The address the process is stopped in.
name|lldb
operator|::
name|addr_t
name|m_stack_frame_bottom
expr_stmt|;
comment|///< The bottom of the allocated stack frame.
name|lldb
operator|::
name|addr_t
name|m_stack_frame_top
expr_stmt|;
comment|///< The top of the allocated stack frame.
name|std
operator|::
name|string
name|m_expr_text
expr_stmt|;
comment|///< The text of the expression, as typed by the user
name|std
operator|::
name|string
name|m_expr_prefix
expr_stmt|;
comment|///< The text of the translation-level definitions, as provided by the user
name|lldb
operator|::
name|LanguageType
name|m_language
expr_stmt|;
comment|///< The language to use when parsing (eLanguageTypeUnknown means use defaults)
name|bool
name|m_allow_cxx
decl_stmt|;
comment|///< True if the language allows C++.
name|bool
name|m_allow_objc
decl_stmt|;
comment|///< True if the language allows Objective-C.
name|std
operator|::
name|string
name|m_transformed_text
expr_stmt|;
comment|///< The text of the expression, as send to the parser
name|ResultType
name|m_desired_type
decl_stmt|;
comment|///< The type to coerce the expression's result to.  If eResultTypeAny, inferred from the expression.
name|std
operator|::
name|unique_ptr
operator|<
name|ClangExpressionDeclMap
operator|>
name|m_expr_decl_map
expr_stmt|;
comment|///< The map to use when parsing the expression.
name|std
operator|::
name|unique_ptr
operator|<
name|IRExecutionUnit
operator|>
name|m_execution_unit_ap
expr_stmt|;
comment|///< The execution unit the expression is stored in.
name|std
operator|::
name|unique_ptr
operator|<
name|Materializer
operator|>
name|m_materializer_ap
expr_stmt|;
comment|///< The materializer to use when running the expression.
name|std
operator|::
name|unique_ptr
operator|<
name|ASTResultSynthesizer
operator|>
name|m_result_synthesizer
expr_stmt|;
comment|///< The result synthesizer, if one is needed.
name|bool
name|m_enforce_valid_object
decl_stmt|;
comment|///< True if the expression parser should enforce the presence of a valid class pointer in order to generate the expression as a method.
name|bool
name|m_cplusplus
decl_stmt|;
comment|///< True if the expression is compiled as a C++ member function (true if it was parsed when exe_ctx was in a C++ method).
name|bool
name|m_objectivec
decl_stmt|;
comment|///< True if the expression is compiled as an Objective-C method (true if it was parsed when exe_ctx was in an Objective-C method).
name|bool
name|m_static_method
decl_stmt|;
comment|///< True if the expression is compiled as a static (or class) method (currently true if it was parsed when exe_ctx was in an Objective-C class method).
name|bool
name|m_needs_object_ptr
decl_stmt|;
comment|///< True if "this" or "self" must be looked up and passed in.  False if the expression doesn't really use them and they can be NULL.
name|bool
name|m_const_object
decl_stmt|;
comment|///< True if "this" is const.
name|Target
modifier|*
name|m_target
decl_stmt|;
comment|///< The target for storing persistent data like types and variables.
name|bool
name|m_can_interpret
decl_stmt|;
comment|///< True if the expression could be evaluated statically; false otherwise.
name|lldb
operator|::
name|addr_t
name|m_materialized_address
expr_stmt|;
comment|///< The address at which the arguments to the expression have been materialized.
name|Materializer
operator|::
name|DematerializerSP
name|m_dematerializer_sp
expr_stmt|;
comment|///< The dematerializer.
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ClangUserExpression_h_
end_comment

end_unit

