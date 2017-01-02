begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- TrigramIndex.h - a heuristic for SpecialCaseList --------*- C++ -*-===//
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
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TrigramIndex implements a heuristic for SpecialCaseList that allows to
end_comment

begin_comment
comment|// filter out ~99% incoming queries when all regular expressions in the
end_comment

begin_comment
comment|// SpecialCaseList are simple wildcards with '*' and '.'. If rules are more
end_comment

begin_comment
comment|// complicated, the check is defeated and it will always pass the queries to a
end_comment

begin_comment
comment|// full regex.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The basic idea is that in order for a wildcard to match a query, the query
end_comment

begin_comment
comment|// needs to have all trigrams which occur in the wildcard. We create a trigram
end_comment

begin_comment
comment|// index (trigram -> list of rules with it) and then count trigrams in the query
end_comment

begin_comment
comment|// for each rule. If the count for one of the rules reaches the expected value,
end_comment

begin_comment
comment|// the check passes the query to a regex. If none of the rules got enough
end_comment

begin_comment
comment|// trigrams, the check tells that the query is definitely not matched by any
end_comment

begin_comment
comment|// of the rules, and no regex matching is needed.
end_comment

begin_comment
comment|// A similar idea was used in Google Code Search as described in the blog post:
end_comment

begin_comment
comment|// https://swtch.com/~rsc/regexp/regexp4.html
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
name|LLVM_SUPPORT_TRIGRAMINDEX_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_TRIGRAMINDEX_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<unordered_map>
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
name|StringRef
decl_stmt|;
name|class
name|TrigramIndex
block|{
name|public
label|:
comment|/// Inserts a new Regex into the index.
name|void
name|insert
argument_list|(
name|std
operator|::
name|string
name|Regex
argument_list|)
decl_stmt|;
comment|/// Returns true, if special case list definitely does not have a line
comment|/// that matches the query. Returns false, if it's not sure.
name|bool
name|isDefinitelyOut
argument_list|(
name|StringRef
name|Query
argument_list|)
decl|const
decl_stmt|;
comment|/// Returned true, iff the heuristic is defeated and not useful.
comment|/// In this case isDefinitelyOut always returns false.
name|bool
name|isDefeated
parameter_list|()
block|{
return|return
name|Defeated
return|;
block|}
name|private
label|:
comment|// If true, the rules are too complicated for the check to work, and full
comment|// regex matching is needed for every rule.
name|bool
name|Defeated
init|=
name|false
decl_stmt|;
comment|// The minimum number of trigrams which should match for a rule to have a
comment|// chance to match the query. The number of elements equals the number of
comment|// regex rules in the SpecialCaseList.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|Counts
expr_stmt|;
comment|// Index holds a list of rules indices for each trigram. The same indices
comment|// are used in Counts to store per-rule limits.
comment|// If a trigram is too common (>4 rules with it), we stop tracking it,
comment|// which increases the probability for a need to match using regex, but
comment|// decreases the costs in the regular case.
name|std
operator|::
name|unordered_map
operator|<
name|unsigned
operator|,
name|SmallVector
operator|<
name|size_t
operator|,
literal|4
operator|>>
name|Index
block|{
literal|256
block|}
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_TRIGRAMINDEX_H
end_comment

end_unit

