begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CommandAlias.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_CommandAlias_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CommandAlias_h_
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
file|<memory>
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
file|"lldb/Interpreter/Args.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/CommandObject.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|CommandAlias
range|:
name|public
name|CommandObject
block|{
name|public
operator|:
typedef|typedef
name|std
operator|::
name|unique_ptr
operator|<
name|CommandAlias
operator|>
name|UniquePointer
expr_stmt|;
name|CommandAlias
argument_list|(
argument|CommandInterpreter&interpreter
argument_list|,
argument|lldb::CommandObjectSP cmd_sp
argument_list|,
argument|llvm::StringRef options_args
argument_list|,
argument|llvm::StringRef name
argument_list|,
argument|llvm::StringRef help = llvm::StringRef()
argument_list|,
argument|llvm::StringRef syntax = llvm::StringRef()
argument_list|,
argument|uint32_t flags =
literal|0
argument_list|)
decl_stmt|;
name|void
name|GetAliasExpansion
argument_list|(
name|StreamString
operator|&
name|help_string
argument_list|)
decl|const
decl_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
block|{
return|return
name|m_underlying_command_sp
operator|&&
name|m_option_args_sp
return|;
block|}
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|IsValid
argument_list|()
return|;
block|}
name|bool
name|WantsRawCommandString
argument_list|()
name|override
expr_stmt|;
name|bool
name|WantsCompletion
argument_list|()
name|override
expr_stmt|;
name|int
name|HandleCompletion
argument_list|(
name|Args
operator|&
name|input
argument_list|,
name|int
operator|&
name|cursor_index
argument_list|,
name|int
operator|&
name|cursor_char_position
argument_list|,
name|int
name|match_start_point
argument_list|,
name|int
name|max_return_elements
argument_list|,
name|bool
operator|&
name|word_complete
argument_list|,
name|StringList
operator|&
name|matches
argument_list|)
name|override
decl_stmt|;
name|int
name|HandleArgumentCompletion
argument_list|(
name|Args
operator|&
name|input
argument_list|,
name|int
operator|&
name|cursor_index
argument_list|,
name|int
operator|&
name|cursor_char_position
argument_list|,
name|OptionElementVector
operator|&
name|opt_element_vector
argument_list|,
name|int
name|match_start_point
argument_list|,
name|int
name|max_return_elements
argument_list|,
name|bool
operator|&
name|word_complete
argument_list|,
name|StringList
operator|&
name|matches
argument_list|)
name|override
decl_stmt|;
name|Options
operator|*
name|GetOptions
argument_list|()
name|override
expr_stmt|;
name|bool
name|IsAlias
parameter_list|()
function|override
block|{
return|return
name|true
return|;
block|}
name|bool
name|IsDashDashCommand
argument_list|()
name|override
expr_stmt|;
name|llvm
operator|::
name|StringRef
name|GetHelp
argument_list|()
name|override
expr_stmt|;
name|llvm
operator|::
name|StringRef
name|GetHelpLong
argument_list|()
name|override
expr_stmt|;
name|void
name|SetHelp
argument_list|(
name|llvm
operator|::
name|StringRef
name|str
argument_list|)
name|override
decl_stmt|;
name|void
name|SetHelpLong
argument_list|(
name|llvm
operator|::
name|StringRef
name|str
argument_list|)
name|override
decl_stmt|;
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
name|override
decl_stmt|;
name|lldb
operator|::
name|CommandObjectSP
name|GetUnderlyingCommand
argument_list|()
block|{
return|return
name|m_underlying_command_sp
return|;
block|}
name|OptionArgVectorSP
name|GetOptionArguments
argument_list|()
specifier|const
block|{
return|return
name|m_option_args_sp
return|;
block|}
specifier|const
name|char
modifier|*
name|GetOptionString
parameter_list|()
block|{
return|return
name|m_option_string
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|// this takes an alias - potentially nested (i.e. an alias to an alias)
comment|// and expands it all the way to a non-alias command
name|std
operator|::
name|pair
operator|<
name|lldb
operator|::
name|CommandObjectSP
operator|,
name|OptionArgVectorSP
operator|>
name|Desugar
argument_list|()
expr_stmt|;
name|protected
label|:
name|bool
name|IsNestedAlias
parameter_list|()
function_decl|;
name|private
label|:
name|lldb
operator|::
name|CommandObjectSP
name|m_underlying_command_sp
expr_stmt|;
name|std
operator|::
name|string
name|m_option_string
expr_stmt|;
name|OptionArgVectorSP
name|m_option_args_sp
decl_stmt|;
name|LazyBool
name|m_is_dashdash_alias
decl_stmt|;
name|bool
name|m_did_set_help
range|:
literal|1
decl_stmt|;
name|bool
name|m_did_set_help_long
range|:
literal|1
decl_stmt|;
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
comment|// liblldb_CommandAlias_h_
end_comment

end_unit

