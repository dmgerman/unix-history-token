begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CommandHistory.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_CommandHistory_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CommandHistory_h_
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
file|<mutex>
end_include

begin_include
include|#
directive|include
file|<string>
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
file|"lldb/Utility/Stream.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|CommandHistory
block|{
name|public
label|:
name|CommandHistory
argument_list|()
expr_stmt|;
operator|~
name|CommandHistory
argument_list|()
expr_stmt|;
name|size_t
name|GetSize
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsEmpty
argument_list|()
specifier|const
expr_stmt|;
name|llvm
operator|::
name|Optional
operator|<
name|llvm
operator|::
name|StringRef
operator|>
name|FindString
argument_list|(
argument|llvm::StringRef input_str
argument_list|)
specifier|const
expr_stmt|;
name|llvm
operator|::
name|StringRef
name|GetStringAtIndex
argument_list|(
argument|size_t idx
argument_list|)
specifier|const
expr_stmt|;
name|llvm
operator|::
name|StringRef
name|operator
index|[]
operator|(
name|size_t
name|idx
operator|)
specifier|const
expr_stmt|;
name|llvm
operator|::
name|StringRef
name|GetRecentmostString
argument_list|()
specifier|const
expr_stmt|;
name|void
name|AppendString
argument_list|(
name|llvm
operator|::
name|StringRef
name|str
argument_list|,
name|bool
name|reject_if_dupe
operator|=
name|true
argument_list|)
decl_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|void
name|Dump
argument_list|(
name|Stream
operator|&
name|stream
argument_list|,
name|size_t
name|start_idx
operator|=
literal|0
argument_list|,
name|size_t
name|stop_idx
operator|=
name|SIZE_MAX
argument_list|)
decl|const
decl_stmt|;
specifier|static
specifier|const
name|char
name|g_repeat_char
init|=
literal|'!'
decl_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|CommandHistory
argument_list|)
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|History
expr_stmt|;
name|mutable
name|std
operator|::
name|recursive_mutex
name|m_mutex
expr_stmt|;
name|History
name|m_history
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
comment|// liblldb_CommandHistory_h_
end_comment

end_unit

