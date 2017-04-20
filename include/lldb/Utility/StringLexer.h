begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--------------------- StringLexer.h -------------------------*- C++
end_comment

begin_comment
comment|//-*-===//
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
name|utility_StringLexer_h_
end_ifndef

begin_define
define|#
directive|define
name|utility_StringLexer_h_
end_define

begin_include
include|#
directive|include
file|<initializer_list>
end_include

begin_comment
comment|// for initializer_list
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|// for string
end_comment

begin_include
include|#
directive|include
file|<utility>
end_include

begin_comment
comment|// for pair
end_comment

begin_decl_stmt
name|namespace
name|lldb_utility
block|{
name|class
name|StringLexer
block|{
name|public
label|:
typedef|typedef
name|std
operator|::
name|string
operator|::
name|size_type
name|Position
expr_stmt|;
typedef|typedef
name|std
operator|::
name|string
operator|::
name|size_type
name|Size
expr_stmt|;
typedef|typedef
name|std
operator|::
name|string
operator|::
name|value_type
name|Character
expr_stmt|;
name|StringLexer
argument_list|(
argument|std::string s
argument_list|)
empty_stmt|;
name|StringLexer
argument_list|(
specifier|const
name|StringLexer
operator|&
name|rhs
argument_list|)
expr_stmt|;
comment|// These APIs are not bounds-checked.  Use HasAtLeast() if you're not sure.
name|Character
name|Peek
parameter_list|()
function_decl|;
name|bool
name|NextIf
parameter_list|(
name|Character
name|c
parameter_list|)
function_decl|;
name|std
operator|::
name|pair
operator|<
name|bool
operator|,
name|Character
operator|>
name|NextIf
argument_list|(
name|std
operator|::
name|initializer_list
operator|<
name|Character
operator|>
name|cs
argument_list|)
expr_stmt|;
name|bool
name|AdvanceIf
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|token
argument_list|)
decl_stmt|;
name|Character
name|Next
parameter_list|()
function_decl|;
name|bool
name|HasAtLeast
parameter_list|(
name|Size
name|s
parameter_list|)
function_decl|;
name|std
operator|::
name|string
name|GetUnlexed
argument_list|()
expr_stmt|;
comment|// This will assert if there are less than s characters preceding the cursor.
name|void
name|PutBack
parameter_list|(
name|Size
name|s
parameter_list|)
function_decl|;
name|StringLexer
modifier|&
name|operator
init|=
operator|(
specifier|const
name|StringLexer
operator|&
name|rhs
operator|)
decl_stmt|;
name|private
label|:
name|std
operator|::
name|string
name|m_data
expr_stmt|;
name|Position
name|m_position
decl_stmt|;
name|void
name|Consume
parameter_list|()
function_decl|;
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
comment|// #ifndef utility_StringLexer_h_
end_comment

end_unit

