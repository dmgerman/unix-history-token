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
name|virtual
operator|~
name|CommandOptions
argument_list|()
block|;
name|virtual
name|uint32_t
name|GetNumDefinitions
argument_list|()
block|;
name|virtual
specifier|const
name|OptionDefinition
operator|*
name|GetDefinitions
argument_list|()
block|;
name|virtual
name|Error
name|SetOptionValue
argument_list|(
argument|CommandInterpreter&interpreter
argument_list|,
argument|uint32_t option_idx
argument_list|,
argument|const char *option_value
argument_list|)
block|;
name|virtual
name|void
name|OptionParsingStarting
argument_list|(
name|CommandInterpreter
operator|&
name|interpreter
argument_list|)
block|;
comment|// Options table: Required for subclasses of Options.
specifier|static
name|OptionDefinition
name|g_option_table
index|[]
block|;
name|bool
name|unwind_on_error
block|;
name|bool
name|ignore_breakpoints
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
name|LanguageRuntimeDescriptionDisplayVerbosity
name|m_verbosity
block|;     }
decl_stmt|;
name|CommandObjectExpression
argument_list|(
name|CommandInterpreter
operator|&
name|interpreter
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|CommandObjectExpression
argument_list|()
expr_stmt|;
name|virtual
name|Options
modifier|*
name|GetOptions
parameter_list|()
function_decl|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// IOHandler::Delegate functions
comment|//------------------------------------------------------------------
name|virtual
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
decl_stmt|;
name|virtual
name|LineStatus
name|IOHandlerLinesUpdated
parameter_list|(
name|IOHandler
modifier|&
name|io_handler
parameter_list|,
name|StringList
modifier|&
name|lines
parameter_list|,
name|uint32_t
name|line_idx
parameter_list|,
name|Error
modifier|&
name|error
parameter_list|)
function_decl|;
name|virtual
name|bool
name|DoExecute
parameter_list|(
specifier|const
name|char
modifier|*
name|command
parameter_list|,
name|CommandReturnObject
modifier|&
name|result
parameter_list|)
function_decl|;
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
name|OptionGroupOptions
name|m_option_group
decl_stmt|;
name|OptionGroupFormat
name|m_format_options
decl_stmt|;
name|OptionGroupValueObjectDisplay
name|m_varobj_options
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

