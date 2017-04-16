begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CommandObjectRegexCommand.h -----------------------------*- C++ -*-===//
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
name|liblldb_CommandObjectRegexCommand_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CommandObjectRegexCommand_h_
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
file|<list>
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

begin_include
include|#
directive|include
file|"lldb/Utility/RegularExpression.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//-------------------------------------------------------------------------
comment|// CommandObjectRegexCommand
comment|//-------------------------------------------------------------------------
name|class
name|CommandObjectRegexCommand
range|:
name|public
name|CommandObjectRaw
block|{
name|public
operator|:
name|CommandObjectRegexCommand
argument_list|(
argument|CommandInterpreter&interpreter
argument_list|,
argument|llvm::StringRef name
argument_list|,
argument|llvm::StringRef help
argument_list|,
argument|llvm::StringRef syntax
argument_list|,
argument|uint32_t max_matches
argument_list|,
argument|uint32_t completion_type_mask
argument_list|,
argument|bool is_removable
argument_list|)
block|;
operator|~
name|CommandObjectRegexCommand
argument_list|()
name|override
block|;
name|bool
name|IsRemovable
argument_list|()
specifier|const
name|override
block|{
return|return
name|m_is_removable
return|;
block|}
name|bool
name|AddRegexCommand
argument_list|(
specifier|const
name|char
operator|*
name|re_cstr
argument_list|,
specifier|const
name|char
operator|*
name|command_cstr
argument_list|)
block|;
name|bool
name|HasRegexEntries
argument_list|()
specifier|const
block|{
return|return
operator|!
name|m_entries
operator|.
name|empty
argument_list|()
return|;
block|}
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
name|protected
operator|:
name|bool
name|DoExecute
argument_list|(
argument|const char *command
argument_list|,
argument|CommandReturnObject&result
argument_list|)
name|override
block|;    struct
name|Entry
block|{
name|RegularExpression
name|regex
block|;
name|std
operator|::
name|string
name|command
block|;   }
block|;
typedef|typedef
name|std
operator|::
name|list
operator|<
name|Entry
operator|>
name|EntryCollection
expr_stmt|;
specifier|const
name|uint32_t
name|m_max_matches
decl_stmt|;
specifier|const
name|uint32_t
name|m_completion_type_mask
decl_stmt|;
name|EntryCollection
name|m_entries
decl_stmt|;
name|bool
name|m_is_removable
decl_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|CommandObjectRegexCommand
argument_list|)
expr_stmt|;
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
comment|// liblldb_CommandObjectRegexCommand_h_
end_comment

end_unit

