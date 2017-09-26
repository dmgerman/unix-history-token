begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- StringMatcher.h - Generate a matcher for input strings ---*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file implements the StringMatcher class.
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
name|LLVM_TABLEGEN_STRINGMATCHER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TABLEGEN_STRINGMATCHER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
comment|/// StringMatcher - Given a list of strings and code to execute when they match,
comment|/// output a simple switch tree to classify the input string.
comment|///
comment|/// If a match is found, the code in Vals[i].second is executed; control must
comment|/// not exit this code fragment.  If nothing matches, execution falls through.
comment|///
name|class
name|StringMatcher
block|{
name|public
label|:
name|using
name|StringPair
init|=
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
decl_stmt|,
name|std
decl|::
name|string
decl|>
decl_stmt|;
name|private
label|:
name|StringRef
name|StrVariableName
decl_stmt|;
specifier|const
name|std
operator|::
name|vector
operator|<
name|StringPair
operator|>
operator|&
name|Matches
expr_stmt|;
name|raw_ostream
modifier|&
name|OS
decl_stmt|;
name|public
label|:
name|StringMatcher
argument_list|(
argument|StringRef strVariableName
argument_list|,
argument|const std::vector<StringPair>&matches
argument_list|,
argument|raw_ostream&os
argument_list|)
block|:
name|StrVariableName
argument_list|(
name|strVariableName
argument_list|)
operator|,
name|Matches
argument_list|(
name|matches
argument_list|)
operator|,
name|OS
argument_list|(
argument|os
argument_list|)
block|{}
name|void
name|Emit
argument_list|(
argument|unsigned Indent =
literal|0
argument_list|)
specifier|const
expr_stmt|;
name|private
label|:
name|bool
name|EmitStringMatcherForChar
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
specifier|const
name|StringPair
operator|*
operator|>
operator|&
name|Matches
argument_list|,
name|unsigned
name|CharNo
argument_list|,
name|unsigned
name|IndentCount
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TABLEGEN_STRINGMATCHER_H
end_comment

end_unit

