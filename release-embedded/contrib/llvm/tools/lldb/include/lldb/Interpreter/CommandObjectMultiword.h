begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CommandObjectMultiword.h --------------------------------*- C++ -*-===//
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
name|liblldb_CommandObjectMultiword_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CommandObjectMultiword_h_
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
file|<map>
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
file|"lldb/Interpreter/CommandObject.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//-------------------------------------------------------------------------
comment|// CommandObjectMultiword
comment|//-------------------------------------------------------------------------
name|class
name|CommandObjectMultiword
range|:
name|public
name|CommandObject
block|{
comment|// These two want to iterate over the subcommand dictionary.
name|friend
name|class
name|CommandInterpreter
block|;
name|friend
name|class
name|CommandObjectSyntax
block|;
name|public
operator|:
name|CommandObjectMultiword
argument_list|(
argument|CommandInterpreter&interpreter
argument_list|,
argument|const char *name
argument_list|,
argument|const char *help = NULL
argument_list|,
argument|const char *syntax = NULL
argument_list|,
argument|uint32_t flags =
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|CommandObjectMultiword
argument_list|()
block|;
name|virtual
name|bool
name|IsMultiwordObject
argument_list|()
block|{
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|LoadSubCommand
argument_list|(
specifier|const
name|char
operator|*
name|cmd_name
argument_list|,
specifier|const
name|lldb
operator|::
name|CommandObjectSP
operator|&
name|command_obj
argument_list|)
block|;
name|virtual
name|void
name|GenerateHelpText
argument_list|(
name|Stream
operator|&
name|output_stream
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|CommandObjectSP
name|GetSubcommandSP
argument_list|(
specifier|const
name|char
operator|*
name|sub_cmd
argument_list|,
name|StringList
operator|*
name|matches
operator|=
name|NULL
argument_list|)
block|;
name|virtual
name|CommandObject
operator|*
name|GetSubcommandObject
argument_list|(
specifier|const
name|char
operator|*
name|sub_cmd
argument_list|,
name|StringList
operator|*
name|matches
operator|=
name|NULL
argument_list|)
block|;
name|virtual
name|void
name|AproposAllSubCommands
argument_list|(
specifier|const
name|char
operator|*
name|prefix
argument_list|,
specifier|const
name|char
operator|*
name|search_word
argument_list|,
name|StringList
operator|&
name|commands_found
argument_list|,
name|StringList
operator|&
name|commands_help
argument_list|)
block|;
name|virtual
name|bool
name|WantsRawCommandString
argument_list|()
block|{
return|return
name|false
return|;
block|}
block|;
name|virtual
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
block|;
name|virtual
specifier|const
name|char
operator|*
name|GetRepeatCommand
argument_list|(
argument|Args&current_command_args
argument_list|,
argument|uint32_t index
argument_list|)
block|;
name|virtual
name|bool
name|Execute
argument_list|(
specifier|const
name|char
operator|*
name|args_string
argument_list|,
name|CommandReturnObject
operator|&
name|result
argument_list|)
block|;
name|virtual
name|bool
name|IsRemovable
argument_list|()
specifier|const
block|{
return|return
name|m_can_be_removed
return|;
block|}
name|void
name|SetRemovable
argument_list|(
argument|bool removable
argument_list|)
block|{
name|m_can_be_removed
operator|=
name|removable
block|;     }
name|protected
operator|:
name|CommandObject
operator|::
name|CommandMap
name|m_subcommand_dict
block|;
name|bool
name|m_can_be_removed
block|; }
decl_stmt|;
name|class
name|CommandObjectProxy
range|:
name|public
name|CommandObject
block|{
name|public
operator|:
name|CommandObjectProxy
argument_list|(
argument|CommandInterpreter&interpreter
argument_list|,
argument|const char *name
argument_list|,
argument|const char *help = NULL
argument_list|,
argument|const char *syntax = NULL
argument_list|,
argument|uint32_t flags =
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|CommandObjectProxy
argument_list|()
block|;
comment|// Subclasses must provide a command object that will be transparently
comment|// used for this object.
name|virtual
name|CommandObject
operator|*
name|GetProxyCommandObject
argument_list|()
operator|=
literal|0
block|;
name|virtual
specifier|const
name|char
operator|*
name|GetHelpLong
argument_list|()
block|;
name|virtual
name|bool
name|IsRemovable
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|IsMultiwordObject
argument_list|()
block|;
name|virtual
name|lldb
operator|::
name|CommandObjectSP
name|GetSubcommandSP
argument_list|(
specifier|const
name|char
operator|*
name|sub_cmd
argument_list|,
name|StringList
operator|*
name|matches
operator|=
name|NULL
argument_list|)
block|;
name|virtual
name|CommandObject
operator|*
name|GetSubcommandObject
argument_list|(
specifier|const
name|char
operator|*
name|sub_cmd
argument_list|,
name|StringList
operator|*
name|matches
operator|=
name|NULL
argument_list|)
block|;
name|virtual
name|void
name|AproposAllSubCommands
argument_list|(
specifier|const
name|char
operator|*
name|prefix
argument_list|,
specifier|const
name|char
operator|*
name|search_word
argument_list|,
name|StringList
operator|&
name|commands_found
argument_list|,
name|StringList
operator|&
name|commands_help
argument_list|)
block|;
name|virtual
name|bool
name|LoadSubCommand
argument_list|(
specifier|const
name|char
operator|*
name|cmd_name
argument_list|,
specifier|const
name|lldb
operator|::
name|CommandObjectSP
operator|&
name|command_obj
argument_list|)
block|;
name|virtual
name|bool
name|WantsRawCommandString
argument_list|()
block|;
name|virtual
name|bool
name|WantsCompletion
argument_list|()
block|;
name|virtual
name|Options
operator|*
name|GetOptions
argument_list|()
block|;
name|virtual
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
block|;
name|virtual
name|int
name|HandleArgumentCompletion
argument_list|(
argument|Args&input
argument_list|,
argument|int&cursor_index
argument_list|,
argument|int&cursor_char_position
argument_list|,
argument|OptionElementVector&opt_element_vector
argument_list|,
argument|int match_start_point
argument_list|,
argument|int max_return_elements
argument_list|,
argument|bool&word_complete
argument_list|,
argument|StringList&matches
argument_list|)
block|;
name|virtual
specifier|const
name|char
operator|*
name|GetRepeatCommand
argument_list|(
argument|Args&current_command_args
argument_list|,
argument|uint32_t index
argument_list|)
block|;
name|virtual
name|bool
name|Execute
argument_list|(
specifier|const
name|char
operator|*
name|args_string
argument_list|,
name|CommandReturnObject
operator|&
name|result
argument_list|)
block|;
name|protected
operator|:
comment|// These two want to iterate over the subcommand dictionary.
name|friend
name|class
name|CommandInterpreter
block|;
name|friend
name|class
name|CommandObjectSyntax
block|;  }
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
comment|// liblldb_CommandObjectMultiword_h_
end_comment

end_unit

