begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DeltaAlgorithm.h - A Set Minimization Algorithm ---------*- C++ -*--===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ADT_DELTAALGORITHM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_DELTAALGORITHM_H
end_define

begin_include
include|#
directive|include
file|<set>
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
comment|/// DeltaAlgorithm - Implements the delta debugging algorithm (A. Zeller '99)
comment|/// for minimizing arbitrary sets using a predicate function.
comment|///
comment|/// The result of the algorithm is a subset of the input change set which is
comment|/// guaranteed to satisfy the predicate, assuming that the input set did. For
comment|/// well formed predicates, the result set is guaranteed to be such that
comment|/// removing any single element would falsify the predicate.
comment|///
comment|/// For best results the predicate function *should* (but need not) satisfy
comment|/// certain properties, in particular:
comment|///  (1) The predicate should return false on an empty set and true on the full
comment|///  set.
comment|///  (2) If the predicate returns true for a set of changes, it should return
comment|///  true for all supersets of that set.
comment|///
comment|/// It is not an error to provide a predicate that does not satisfy these
comment|/// requirements, and the algorithm will generally produce reasonable
comment|/// results. However, it may run substantially more tests than with a good
comment|/// predicate.
name|class
name|DeltaAlgorithm
block|{
name|public
label|:
name|using
name|change_ty
init|=
name|unsigned
decl_stmt|;
comment|// FIXME: Use a decent data structure.
name|using
name|changeset_ty
init|=
name|std
operator|::
name|set
operator|<
name|change_ty
operator|>
decl_stmt|;
name|using
name|changesetlist_ty
init|=
name|std
operator|::
name|vector
operator|<
name|changeset_ty
operator|>
decl_stmt|;
name|private
label|:
comment|/// Cache of failed test results. Successful test results are never cached
comment|/// since we always reduce following a success.
name|std
operator|::
name|set
operator|<
name|changeset_ty
operator|>
name|FailedTestsCache
expr_stmt|;
comment|/// GetTestResult - Get the test result for the \p Changes from the
comment|/// cache, executing the test if necessary.
comment|///
comment|/// \param Changes - The change set to test.
comment|/// \return - The test result.
name|bool
name|GetTestResult
parameter_list|(
specifier|const
name|changeset_ty
modifier|&
name|Changes
parameter_list|)
function_decl|;
comment|/// Split - Partition a set of changes \p S into one or two subsets.
name|void
name|Split
parameter_list|(
specifier|const
name|changeset_ty
modifier|&
name|S
parameter_list|,
name|changesetlist_ty
modifier|&
name|Res
parameter_list|)
function_decl|;
comment|/// Delta - Minimize a set of \p Changes which has been partioned into
comment|/// smaller sets, by attempting to remove individual subsets.
name|changeset_ty
name|Delta
parameter_list|(
specifier|const
name|changeset_ty
modifier|&
name|Changes
parameter_list|,
specifier|const
name|changesetlist_ty
modifier|&
name|Sets
parameter_list|)
function_decl|;
comment|/// Search - Search for a subset (or subsets) in \p Sets which can be
comment|/// removed from \p Changes while still satisfying the predicate.
comment|///
comment|/// \param Res - On success, a subset of Changes which satisfies the
comment|/// predicate.
comment|/// \return - True on success.
name|bool
name|Search
parameter_list|(
specifier|const
name|changeset_ty
modifier|&
name|Changes
parameter_list|,
specifier|const
name|changesetlist_ty
modifier|&
name|Sets
parameter_list|,
name|changeset_ty
modifier|&
name|Res
parameter_list|)
function_decl|;
name|protected
label|:
comment|/// UpdatedSearchState - Callback used when the search state changes.
name|virtual
name|void
name|UpdatedSearchState
parameter_list|(
specifier|const
name|changeset_ty
modifier|&
name|Changes
parameter_list|,
specifier|const
name|changesetlist_ty
modifier|&
name|Sets
parameter_list|)
block|{}
comment|/// ExecuteOneTest - Execute a single test predicate on the change set \p S.
name|virtual
name|bool
name|ExecuteOneTest
parameter_list|(
specifier|const
name|changeset_ty
modifier|&
name|S
parameter_list|)
init|=
literal|0
function_decl|;
name|DeltaAlgorithm
modifier|&
name|operator
init|=
operator|(
specifier|const
name|DeltaAlgorithm
operator|&
operator|)
operator|=
expr|default
decl_stmt|;
name|public
label|:
name|virtual
operator|~
name|DeltaAlgorithm
argument_list|()
expr_stmt|;
comment|/// Run - Minimize the set \p Changes by executing \see ExecuteOneTest() on
comment|/// subsets of changes and returning the smallest set which still satisfies
comment|/// the test predicate.
name|changeset_ty
name|Run
parameter_list|(
specifier|const
name|changeset_ty
modifier|&
name|Changes
parameter_list|)
function_decl|;
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
comment|// LLVM_ADT_DELTAALGORITHM_H
end_comment

end_unit

