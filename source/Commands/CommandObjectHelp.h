begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CommandObjectHelp.h -------------------------------------*- C++ -*-===//
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
name|liblldb_CommandObjectHelp_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CommandObjectHelp_h_
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
file|"lldb/Host/OptionParser.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/CommandObject.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/Options.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//-------------------------------------------------------------------------
comment|// CommandObjectHelp
comment|//-------------------------------------------------------------------------
name|class
name|CommandObjectHelp
range|:
name|public
name|CommandObjectParsed
block|{
name|public
operator|:
name|CommandObjectHelp
argument_list|(
name|CommandInterpreter
operator|&
name|interpreter
argument_list|)
block|;
operator|~
name|CommandObjectHelp
argument_list|()
name|override
block|;
name|int
name|HandleCompletion
argument_list|(
argument|Args&input
argument_list|,
argument|int&cursor_index
argument_list|,
argument|int&cursor_char_position
argument_list|,
argument|int match_start_point
argument_list|,
argument|int max_return_elements
argument_list|,
argument|bool&word_complete
argument_list|,
argument|StringList&matches
argument_list|)
name|override
block|;
specifier|static
name|void
name|GenerateAdditionalHelpAvenuesMessage
argument_list|(
argument|Stream *s
argument_list|,
argument|llvm::StringRef command
argument_list|,
argument|llvm::StringRef prefix
argument_list|,
argument|llvm::StringRef subcommand
argument_list|,
argument|bool include_apropos = true
argument_list|,
argument|bool include_type_lookup = true
argument_list|)
block|;
name|class
name|CommandOptions
operator|:
name|public
name|Options
block|{
name|public
operator|:
name|CommandOptions
argument_list|()
operator|:
name|Options
argument_list|()
block|{}
operator|~
name|CommandOptions
argument_list|()
name|override
block|{}
name|Error
name|SetOptionValue
argument_list|(
argument|uint32_t option_idx
argument_list|,
argument|llvm::StringRef option_arg
argument_list|,
argument|ExecutionContext *execution_context
argument_list|)
name|override
block|{
name|Error
name|error
block|;
specifier|const
name|int
name|short_option
operator|=
name|m_getopt_table
index|[
name|option_idx
index|]
operator|.
name|val
block|;
switch|switch
condition|(
name|short_option
condition|)
block|{
case|case
literal|'a'
case|:
name|m_show_aliases
operator|=
name|false
expr_stmt|;
break|break;
case|case
literal|'u'
case|:
name|m_show_user_defined
operator|=
name|false
expr_stmt|;
break|break;
case|case
literal|'h'
case|:
name|m_show_hidden
operator|=
name|true
expr_stmt|;
break|break;
default|default:
name|error
operator|.
name|SetErrorStringWithFormat
argument_list|(
literal|"unrecognized option '%c'"
argument_list|,
name|short_option
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
name|error
return|;
block|}
name|void
name|OptionParsingStarting
argument_list|(
argument|ExecutionContext *execution_context
argument_list|)
name|override
block|{
name|m_show_aliases
operator|=
name|true
block|;
name|m_show_user_defined
operator|=
name|true
block|;
name|m_show_hidden
operator|=
name|false
block|;     }
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
comment|// Instance variables to hold the values for command options.
name|bool
name|m_show_aliases
block|;
name|bool
name|m_show_user_defined
block|;
name|bool
name|m_show_hidden
block|;   }
block|;
name|Options
operator|*
name|GetOptions
argument_list|()
name|override
block|{
return|return
operator|&
name|m_options
return|;
block|}
name|protected
operator|:
name|bool
name|DoExecute
argument_list|(
argument|Args&command
argument_list|,
argument|CommandReturnObject&result
argument_list|)
name|override
block|;
name|private
operator|:
name|CommandOptions
name|m_options
block|; }
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
comment|// liblldb_CommandObjectHelp_h_
end_comment

end_unit

