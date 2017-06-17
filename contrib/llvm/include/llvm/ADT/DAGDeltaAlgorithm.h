begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DAGDeltaAlgorithm.h - A DAG Minimization Algorithm ------*- C++ -*--===//
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
name|LLVM_ADT_DAGDELTAALGORITHM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_DAGDELTAALGORITHM_H
end_define

begin_include
include|#
directive|include
file|<set>
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
comment|/// DAGDeltaAlgorithm - Implements a "delta debugging" algorithm for minimizing
comment|/// directed acyclic graphs using a predicate function.
comment|///
comment|/// The result of the algorithm is a subset of the input change set which is
comment|/// guaranteed to satisfy the predicate, assuming that the input set did. For
comment|/// well formed predicates, the result set is guaranteed to be such that
comment|/// removing any single element not required by the dependencies on the other
comment|/// elements would falsify the predicate.
comment|///
comment|/// The DAG should be used to represent dependencies in the changes which are
comment|/// likely to hold across the predicate function. That is, for a particular
comment|/// changeset S and predicate P:
comment|///
comment|///   P(S) => P(S union pred(S))
comment|///
comment|/// The minization algorithm uses this dependency information to attempt to
comment|/// eagerly prune large subsets of changes. As with \see DeltaAlgorithm, the DAG
comment|/// is not required to satisfy this property, but the algorithm will run
comment|/// substantially fewer tests with appropriate dependencies. \see DeltaAlgorithm
comment|/// for more information on the properties which the predicate function itself
comment|/// should satisfy.
name|class
name|DAGDeltaAlgorithm
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
name|using
name|change_ty
init|=
name|unsigned
decl_stmt|;
name|using
name|edge_ty
init|=
name|std
operator|::
name|pair
operator|<
name|change_ty
decl_stmt|,
name|change_ty
decl|>
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
name|public
label|:
name|virtual
operator|~
name|DAGDeltaAlgorithm
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Run - Minimize the DAG formed by the \p Changes vertices and the
comment|/// \p Dependencies edges by executing \see ExecuteOneTest() on subsets of
comment|/// changes and returning the smallest set which still satisfies the test
comment|/// predicate and the input \p Dependencies.
comment|///
comment|/// \param Changes The list of changes.
comment|///
comment|/// \param Dependencies The list of dependencies amongst changes. For each
comment|/// (x,y) in \p Dependencies, both x and y must be in \p Changes. The
comment|/// minimization algorithm guarantees that for each tested changed set S,
comment|/// \f$ x \in S \f$ implies \f$ y \in S \f$. It is an error to have cyclic
comment|/// dependencies.
name|changeset_ty
name|Run
argument_list|(
specifier|const
name|changeset_ty
operator|&
name|Changes
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|edge_ty
operator|>
operator|&
name|Dependencies
argument_list|)
decl_stmt|;
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
parameter_list|,
specifier|const
name|changeset_ty
modifier|&
name|Required
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
comment|// LLVM_ADT_DAGDELTAALGORITHM_H
end_comment

end_unit

