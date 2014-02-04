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
block|{
name|public
operator|:
name|class
name|CommandOptions
operator|:
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
block|;
name|CommandObjectExpression
argument_list|(
name|CommandInterpreter
operator|&
name|interpreter
argument_list|)
block|;
name|virtual
operator|~
name|CommandObjectExpression
argument_list|()
block|;
name|virtual
name|Options
operator|*
name|GetOptions
argument_list|()
block|;
name|protected
operator|:
name|virtual
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
block|;
specifier|static
name|size_t
name|MultiLineExpressionCallback
argument_list|(
argument|void *baton
argument_list|,
argument|InputReader&reader
argument_list|,
argument|lldb::InputReaderAction notification
argument_list|,
argument|const char *bytes
argument_list|,
argument|size_t bytes_len
argument_list|)
block|;
name|bool
name|EvaluateExpression
argument_list|(
specifier|const
name|char
operator|*
name|expr
argument_list|,
name|Stream
operator|*
name|output_stream
argument_list|,
name|Stream
operator|*
name|error_stream
argument_list|,
name|CommandReturnObject
operator|*
name|result
operator|=
name|NULL
argument_list|)
block|;
name|OptionGroupOptions
name|m_option_group
block|;
name|OptionGroupFormat
name|m_format_options
block|;
name|OptionGroupValueObjectDisplay
name|m_varobj_options
block|;
name|CommandOptions
name|m_command_options
block|;
name|uint32_t
name|m_expr_line_count
block|;
name|std
operator|::
name|string
name|m_expr_lines
block|;
comment|// Multi-line expression support
block|}
decl_stmt|;
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

