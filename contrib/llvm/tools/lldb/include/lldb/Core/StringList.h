begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- StringList.h --------------------------------------------*- C++ -*-===//
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
name|liblldb_StringList_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_StringList_h_
end_define

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|"lldb/Core/STLUtils.h"
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
name|StringList
block|{
name|public
label|:
name|StringList
argument_list|()
expr_stmt|;
name|StringList
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|)
expr_stmt|;
name|StringList
argument_list|(
argument|const char **strv
argument_list|,
argument|int strc
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|StringList
argument_list|()
expr_stmt|;
name|void
name|AppendString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|s
argument_list|)
decl_stmt|;
name|void
name|AppendString
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
name|void
name|AppendString
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|str_len
parameter_list|)
function_decl|;
name|void
name|AppendList
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|strv
parameter_list|,
name|int
name|strc
parameter_list|)
function_decl|;
name|void
name|AppendList
parameter_list|(
name|StringList
name|strings
parameter_list|)
function_decl|;
name|bool
name|ReadFileLines
parameter_list|(
name|FileSpec
modifier|&
name|input_file
parameter_list|)
function_decl|;
name|size_t
name|GetSize
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
modifier|*
name|GetStringAtIndex
argument_list|(
name|size_t
name|idx
argument_list|)
decl|const
decl_stmt|;
name|void
name|Join
parameter_list|(
specifier|const
name|char
modifier|*
name|separator
parameter_list|,
name|Stream
modifier|&
name|strm
parameter_list|)
function_decl|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|void
name|LongestCommonPrefix
argument_list|(
name|std
operator|::
name|string
operator|&
name|common_prefix
argument_list|)
decl_stmt|;
name|void
name|InsertStringAtIndex
parameter_list|(
name|size_t
name|id
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
name|void
name|DeleteStringAtIndex
parameter_list|(
name|size_t
name|id
parameter_list|)
function_decl|;
name|void
name|RemoveBlankLines
parameter_list|()
function_decl|;
name|size_t
name|SplitIntoLines
parameter_list|(
specifier|const
name|char
modifier|*
name|lines
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
name|std
operator|::
name|string
name|CopyList
argument_list|(
specifier|const
name|char
operator|*
name|item_preamble
operator|=
name|NULL
argument_list|,
specifier|const
name|char
operator|*
name|items_sep
operator|=
literal|"\n"
argument_list|)
expr_stmt|;
name|StringList
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|char
operator|*
name|str
operator|)
expr_stmt|;
name|StringList
operator|&
name|operator
operator|<<
operator|(
name|StringList
name|strings
operator|)
expr_stmt|;
comment|// This string list contains a list of valid auto completion
comment|// strings, and the "s" is passed in. "matches" is filled in
comment|// with zero or more string values that start with "s", and
comment|// the first string to exactly match one of the string
comment|// values in this collection, will have "exact_matches_idx"
comment|// filled in to match the index, or "exact_matches_idx" will
comment|// have SIZE_MAX
name|size_t
name|AutoComplete
argument_list|(
specifier|const
name|char
operator|*
name|s
argument_list|,
name|StringList
operator|&
name|matches
argument_list|,
name|size_t
operator|&
name|exact_matches_idx
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|STLStringArray
name|m_strings
decl_stmt|;
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
comment|// liblldb_StringList_h_
end_comment

end_unit

