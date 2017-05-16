begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CommandObjectExpression.h -------------------------------*- C++ -*-===//
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
name|liblldb_CommandObjectExpression_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CommandObjectExpression_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/IOHandler.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/CommandObject.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/OptionGroupBoolean.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/OptionGroupFormat.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/OptionGroupValueObjectDisplay.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ExecutionContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private-enumerations.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|CommandObjectExpression
range|:
name|public
name|CommandObjectRaw
decl_stmt|,
name|public
name|IOHandlerDelegate
block|{
name|public
label|:
name|class
name|CommandOptions
range|:
name|public
name|OptionGroup
block|{
name|public
operator|:
name|CommandOptions
argument_list|()
block|;
operator|~
name|CommandOptions
argument_list|()
name|override
block|;
name|llvm
operator|::
name|ArrayRef
operator|<
name|OptionDefinition
operator|>
name|GetDefinitions
argument_list|()
name|override
block|;
name|Status
name|SetOptionValue
argument_list|(
argument|uint32_t option_idx
argument_list|,
argument|llvm::StringRef option_value
argument_list|,
argument|ExecutionContext *execution_context
argument_list|)
name|override
block|;
name|void
name|OptionParsingStarting
argument_list|(
argument|ExecutionContext *execution_context
argument_list|)
name|override
block|;
comment|// Options table: Required for subclasses of Options.
specifier|static
name|OptionDefinition
name|g_option_table
index|[]
block|;
name|bool
name|top_level
block|;
name|bool
name|unwind_on_error
block|;
name|bool
name|ignore_breakpoints
block|;
name|bool
name|allow_jit
block|;
name|bool
name|show_types
block|;
name|bool
name|show_summary
block|;
name|bool
name|debug
block|;
name|uint32_t
name|timeout
block|;
name|bool
name|try_all_threads
block|;
name|lldb
operator|::
name|LanguageType
name|language
block|;
name|LanguageRuntimeDescriptionDisplayVerbosity
name|m_verbosity
block|;
name|LazyBool
name|auto_apply_fixits
block|;   }
decl_stmt|;
name|CommandObjectExpression
argument_list|(
name|CommandInterpreter
operator|&
name|interpreter
argument_list|)
expr_stmt|;
operator|~
name|CommandObjectExpression
argument_list|()
name|override
expr_stmt|;
name|Options
operator|*
name|GetOptions
argument_list|()
name|override
expr_stmt|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// IOHandler::Delegate functions
comment|//------------------------------------------------------------------
name|void
name|IOHandlerInputComplete
argument_list|(
name|IOHandler
operator|&
name|io_handler
argument_list|,
name|std
operator|::
name|string
operator|&
name|line
argument_list|)
name|override
decl_stmt|;
name|bool
name|IOHandlerIsInputComplete
argument_list|(
name|IOHandler
operator|&
name|io_handler
argument_list|,
name|StringList
operator|&
name|lines
argument_list|)
name|override
decl_stmt|;
name|bool
name|DoExecute
argument_list|(
specifier|const
name|char
operator|*
name|command
argument_list|,
name|CommandReturnObject
operator|&
name|result
argument_list|)
name|override
decl_stmt|;
name|bool
name|EvaluateExpression
parameter_list|(
specifier|const
name|char
modifier|*
name|expr
parameter_list|,
name|Stream
modifier|*
name|output_stream
parameter_list|,
name|Stream
modifier|*
name|error_stream
parameter_list|,
name|CommandReturnObject
modifier|*
name|result
init|=
name|NULL
parameter_list|)
function_decl|;
name|void
name|GetMultilineExpression
parameter_list|()
function_decl|;
name|OptionGroupOptions
name|m_option_group
decl_stmt|;
name|OptionGroupFormat
name|m_format_options
decl_stmt|;
name|OptionGroupValueObjectDisplay
name|m_varobj_options
decl_stmt|;
name|OptionGroupBoolean
name|m_repl_option
decl_stmt|;
name|CommandOptions
name|m_command_options
decl_stmt|;
name|uint32_t
name|m_expr_line_count
decl_stmt|;
name|std
operator|::
name|string
name|m_expr_lines
expr_stmt|;
comment|// Multi-line expression support
name|std
operator|::
name|string
name|m_fixed_expression
expr_stmt|;
comment|// Holds the current expression's fixed text.
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_CommandObjectExpression_h_
end_comment

end_unit

