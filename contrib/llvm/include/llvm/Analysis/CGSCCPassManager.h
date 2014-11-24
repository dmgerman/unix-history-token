begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CGSCCPassManager.h - Call graph pass management ----------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This header provides classes for managing passes over SCCs of the call
end_comment

begin_comment
comment|/// graph. These passes form an important component of LLVM's interprocedural
end_comment

begin_comment
comment|/// optimizations. Because they operate on the SCCs of the call graph, and they
end_comment

begin_comment
comment|/// wtraverse the graph in post order, they can effectively do pair-wise
end_comment

begin_comment
comment|/// interprocedural optimizations for all call edges in the program. At each
end_comment

begin_comment
comment|/// call site edge, the callee has already been optimized as much as is
end_comment

begin_comment
comment|/// possible. This in turn allows very accurate analysis of it for IPO.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ANALYSIS_CGSCC_PASS_MANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_CGSCC_PASS_MANAGER_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/LazyCallGraph.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CGSCCAnalysisManager
decl_stmt|;
name|class
name|CGSCCPassManager
block|{
name|public
label|:
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|CGSCCPassManager
argument_list|()
block|{}
name|CGSCCPassManager
argument_list|(
name|CGSCCPassManager
operator|&&
name|Arg
argument_list|)
operator|:
name|Passes
argument_list|(
argument|std::move(Arg.Passes)
argument_list|)
block|{}
name|CGSCCPassManager
operator|&
name|operator
operator|=
operator|(
name|CGSCCPassManager
operator|&&
name|RHS
operator|)
block|{
name|Passes
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|Passes
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Run all of the CGSCC passes in this pass manager over a SCC.
name|PreservedAnalyses
name|run
argument_list|(
name|LazyCallGraph
operator|::
name|SCC
operator|*
name|C
argument_list|,
name|CGSCCAnalysisManager
operator|*
name|AM
operator|=
name|nullptr
argument_list|)
decl_stmt|;
name|template
operator|<
name|typename
name|CGSCCPassT
operator|>
name|void
name|addPass
argument_list|(
argument|CGSCCPassT Pass
argument_list|)
block|{
name|Passes
operator|.
name|emplace_back
argument_list|(
argument|new CGSCCPassModel<CGSCCPassT>(std::move(Pass))
argument_list|)
block|;   }
specifier|static
name|StringRef
name|name
argument_list|()
block|{
return|return
literal|"CGSCCPassManager"
return|;
block|}
name|private
label|:
comment|// Pull in the concept type and model template specialized for SCCs.
typedef|typedef
name|detail
operator|::
name|PassConcept
operator|<
name|LazyCallGraph
operator|::
name|SCC
operator|*
operator|,
name|CGSCCAnalysisManager
operator|>
name|CGSCCPassConcept
expr_stmt|;
name|template
operator|<
name|typename
name|PassT
operator|>
expr|struct
name|CGSCCPassModel
operator|:
name|detail
operator|::
name|PassModel
operator|<
name|LazyCallGraph
operator|::
name|SCC
operator|*
operator|,
name|CGSCCAnalysisManager
operator|,
name|PassT
operator|>
block|{
name|CGSCCPassModel
argument_list|(
argument|PassT Pass
argument_list|)
operator|:
name|detail
operator|::
name|PassModel
operator|<
name|LazyCallGraph
operator|::
name|SCC
operator|*
block|,
name|CGSCCAnalysisManager
block|,
name|PassT
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|Pass
argument_list|)
operator|)
block|{}
block|}
expr_stmt|;
name|CGSCCPassManager
argument_list|(
argument|const CGSCCPassManager&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|CGSCCPassManager
modifier|&
name|operator
init|=
operator|(
specifier|const
name|CGSCCPassManager
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|CGSCCPassConcept
operator|>>
name|Passes
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief A function analysis manager to coordinate and cache analyses run over
comment|/// a module.
name|class
name|CGSCCAnalysisManager
range|:
name|public
name|detail
operator|::
name|AnalysisManagerBase
operator|<
name|CGSCCAnalysisManager
decl_stmt|,
name|LazyCallGraph
decl|::
name|SCC
modifier|*
decl|>
block|{
name|friend
name|class
name|detail
operator|::
name|AnalysisManagerBase
operator|<
name|CGSCCAnalysisManager
operator|,
name|LazyCallGraph
operator|::
name|SCC
operator|*
operator|>
expr_stmt|;
typedef|typedef
name|detail
operator|::
name|AnalysisManagerBase
operator|<
name|CGSCCAnalysisManager
operator|,
name|LazyCallGraph
operator|::
name|SCC
operator|*
operator|>
name|BaseT
expr_stmt|;
typedef|typedef
name|BaseT
operator|::
name|ResultConceptT
name|ResultConceptT
expr_stmt|;
typedef|typedef
name|BaseT
operator|::
name|PassConceptT
name|PassConceptT
expr_stmt|;
name|public
label|:
comment|// Most public APIs are inherited from the CRTP base class.
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|CGSCCAnalysisManager
argument_list|()
block|{}
name|CGSCCAnalysisManager
argument_list|(
name|CGSCCAnalysisManager
operator|&&
name|Arg
argument_list|)
operator|:
name|BaseT
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|static_cast
operator|<
name|BaseT
operator|&
operator|>
operator|(
name|Arg
operator|)
argument_list|)
argument_list|)
operator|,
name|CGSCCAnalysisResults
argument_list|(
argument|std::move(Arg.CGSCCAnalysisResults)
argument_list|)
block|{}
name|CGSCCAnalysisManager
operator|&
name|operator
operator|=
operator|(
name|CGSCCAnalysisManager
operator|&&
name|RHS
operator|)
block|{
name|BaseT
operator|::
name|operator
operator|=
operator|(
name|std
operator|::
name|move
argument_list|(
name|static_cast
operator|<
name|BaseT
operator|&
operator|>
operator|(
name|RHS
operator|)
argument_list|)
operator|)
block|;
name|CGSCCAnalysisResults
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|CGSCCAnalysisResults
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Returns true if the analysis manager has an empty results cache.
name|bool
name|empty
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Clear the function analysis result cache.
comment|///
comment|/// This routine allows cleaning up when the set of functions itself has
comment|/// potentially changed, and thus we can't even look up a a result and
comment|/// invalidate it directly. Notably, this does *not* call invalidate
comment|/// functions as there is nothing to be done for them.
name|void
name|clear
parameter_list|()
function_decl|;
name|private
label|:
name|CGSCCAnalysisManager
argument_list|(
argument|const CGSCCAnalysisManager&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|CGSCCAnalysisManager
modifier|&
name|operator
init|=
operator|(
specifier|const
name|CGSCCAnalysisManager
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
comment|/// \brief Get a function pass result, running the pass if necessary.
name|ResultConceptT
modifier|&
name|getResultImpl
argument_list|(
name|void
operator|*
name|PassID
argument_list|,
name|LazyCallGraph
operator|::
name|SCC
operator|*
name|C
argument_list|)
decl_stmt|;
comment|/// \brief Get a cached function pass result or return null.
name|ResultConceptT
modifier|*
name|getCachedResultImpl
argument_list|(
name|void
operator|*
name|PassID
argument_list|,
name|LazyCallGraph
operator|::
name|SCC
operator|*
name|C
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Invalidate a function pass result.
name|void
name|invalidateImpl
argument_list|(
name|void
operator|*
name|PassID
argument_list|,
name|LazyCallGraph
operator|::
name|SCC
operator|*
name|C
argument_list|)
decl_stmt|;
comment|/// \brief Invalidate the results for a function..
name|void
name|invalidateImpl
argument_list|(
name|LazyCallGraph
operator|::
name|SCC
operator|*
name|C
argument_list|,
specifier|const
name|PreservedAnalyses
operator|&
name|PA
argument_list|)
decl_stmt|;
comment|/// \brief List of function analysis pass IDs and associated concept pointers.
comment|///
comment|/// Requires iterators to be valid across appending new entries and arbitrary
comment|/// erases. Provides both the pass ID and concept pointer such that it is
comment|/// half of a bijection and provides storage for the actual result concept.
typedef|typedef
name|std
operator|::
name|list
operator|<
name|std
operator|::
name|pair
operator|<
name|void
operator|*
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|detail
operator|::
name|AnalysisResultConcept
operator|<
name|LazyCallGraph
operator|::
name|SCC
operator|*
operator|>>>
operator|>
name|CGSCCAnalysisResultListT
expr_stmt|;
comment|/// \brief Map type from function pointer to our custom list type.
typedef|typedef
name|DenseMap
operator|<
name|LazyCallGraph
operator|::
name|SCC
operator|*
operator|,
name|CGSCCAnalysisResultListT
operator|>
name|CGSCCAnalysisResultListMapT
expr_stmt|;
comment|/// \brief Map from function to a list of function analysis results.
comment|///
comment|/// Provides linear time removal of all analysis results for a function and
comment|/// the ultimate storage for a particular cached analysis result.
name|CGSCCAnalysisResultListMapT
name|CGSCCAnalysisResultLists
decl_stmt|;
comment|/// \brief Map type from a pair of analysis ID and function pointer to an
comment|/// iterator into a particular result list.
typedef|typedef
name|DenseMap
operator|<
name|std
operator|::
name|pair
operator|<
name|void
operator|*
operator|,
name|LazyCallGraph
operator|::
name|SCC
operator|*
operator|>
operator|,
name|CGSCCAnalysisResultListT
operator|::
name|iterator
operator|>
name|CGSCCAnalysisResultMapT
expr_stmt|;
comment|/// \brief Map from an analysis ID and function to a particular cached
comment|/// analysis result.
name|CGSCCAnalysisResultMapT
name|CGSCCAnalysisResults
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief A module analysis which acts as a proxy for a CGSCC analysis
comment|/// manager.
comment|///
comment|/// This primarily proxies invalidation information from the module analysis
comment|/// manager and module pass manager to a CGSCC analysis manager. You should
comment|/// never use a CGSCC analysis manager from within (transitively) a module
comment|/// pass manager unless your parent module pass has received a proxy result
comment|/// object for it.
name|class
name|CGSCCAnalysisManagerModuleProxy
block|{
name|public
label|:
name|class
name|Result
block|{
name|public
label|:
name|explicit
name|Result
argument_list|(
name|CGSCCAnalysisManager
operator|&
name|CGAM
argument_list|)
operator|:
name|CGAM
argument_list|(
argument|&CGAM
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because
comment|// MSVC refuses to generate them.
name|Result
argument_list|(
specifier|const
name|Result
operator|&
name|Arg
argument_list|)
operator|:
name|CGAM
argument_list|(
argument|Arg.CGAM
argument_list|)
block|{}
name|Result
argument_list|(
name|Result
operator|&&
name|Arg
argument_list|)
operator|:
name|CGAM
argument_list|(
argument|std::move(Arg.CGAM)
argument_list|)
block|{}
name|Result
operator|&
name|operator
operator|=
operator|(
name|Result
name|RHS
operator|)
block|{
name|std
operator|::
name|swap
argument_list|(
name|CGAM
argument_list|,
name|RHS
operator|.
name|CGAM
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
operator|~
name|Result
argument_list|()
expr_stmt|;
comment|/// \brief Accessor for the \c CGSCCAnalysisManager.
name|CGSCCAnalysisManager
modifier|&
name|getManager
parameter_list|()
block|{
return|return
operator|*
name|CGAM
return|;
block|}
comment|/// \brief Handler for invalidation of the module.
comment|///
comment|/// If this analysis itself is preserved, then we assume that the call
comment|/// graph of the module hasn't changed and thus we don't need to invalidate
comment|/// *all* cached data associated with a \c SCC* in the \c
comment|/// CGSCCAnalysisManager.
comment|///
comment|/// Regardless of whether this analysis is marked as preserved, all of the
comment|/// analyses in the \c CGSCCAnalysisManager are potentially invalidated
comment|/// based on the set of preserved analyses.
name|bool
name|invalidate
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|,
specifier|const
name|PreservedAnalyses
modifier|&
name|PA
parameter_list|)
function_decl|;
name|private
label|:
name|CGSCCAnalysisManager
modifier|*
name|CGAM
decl_stmt|;
block|}
empty_stmt|;
specifier|static
name|void
modifier|*
name|ID
parameter_list|()
block|{
return|return
operator|(
name|void
operator|*
operator|)
operator|&
name|PassID
return|;
block|}
name|explicit
name|CGSCCAnalysisManagerModuleProxy
argument_list|(
name|CGSCCAnalysisManager
operator|&
name|CGAM
argument_list|)
operator|:
name|CGAM
argument_list|(
argument|&CGAM
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|CGSCCAnalysisManagerModuleProxy
argument_list|(
specifier|const
name|CGSCCAnalysisManagerModuleProxy
operator|&
name|Arg
argument_list|)
operator|:
name|CGAM
argument_list|(
argument|Arg.CGAM
argument_list|)
block|{}
name|CGSCCAnalysisManagerModuleProxy
argument_list|(
name|CGSCCAnalysisManagerModuleProxy
operator|&&
name|Arg
argument_list|)
operator|:
name|CGAM
argument_list|(
argument|std::move(Arg.CGAM)
argument_list|)
block|{}
name|CGSCCAnalysisManagerModuleProxy
operator|&
name|operator
operator|=
operator|(
name|CGSCCAnalysisManagerModuleProxy
name|RHS
operator|)
block|{
name|std
operator|::
name|swap
argument_list|(
name|CGAM
argument_list|,
name|RHS
operator|.
name|CGAM
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Run the analysis pass and create our proxy result object.
comment|///
comment|/// This doesn't do any interesting work, it is primarily used to insert our
comment|/// proxy result object into the module analysis cache so that we can proxy
comment|/// invalidation to the CGSCC analysis manager.
comment|///
comment|/// In debug builds, it will also assert that the analysis manager is empty
comment|/// as no queries should arrive at the CGSCC analysis manager prior to
comment|/// this analysis being requested.
name|Result
name|run
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
name|private
label|:
specifier|static
name|char
name|PassID
decl_stmt|;
name|CGSCCAnalysisManager
modifier|*
name|CGAM
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief A CGSCC analysis which acts as a proxy for a module analysis
comment|/// manager.
comment|///
comment|/// This primarily provides an accessor to a parent module analysis manager to
comment|/// CGSCC passes. Only the const interface of the module analysis manager is
comment|/// provided to indicate that once inside of a CGSCC analysis pass you
comment|/// cannot request a module analysis to actually run. Instead, the user must
comment|/// rely on the \c getCachedResult API.
comment|///
comment|/// This proxy *doesn't* manage the invalidation in any way. That is handled by
comment|/// the recursive return path of each layer of the pass manager and the
comment|/// returned PreservedAnalysis set.
name|class
name|ModuleAnalysisManagerCGSCCProxy
block|{
name|public
label|:
comment|/// \brief Result proxy object for \c ModuleAnalysisManagerCGSCCProxy.
name|class
name|Result
block|{
name|public
label|:
name|explicit
name|Result
argument_list|(
specifier|const
name|ModuleAnalysisManager
operator|&
name|MAM
argument_list|)
operator|:
name|MAM
argument_list|(
argument|&MAM
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because
comment|// MSVC refuses to generate them.
name|Result
argument_list|(
specifier|const
name|Result
operator|&
name|Arg
argument_list|)
operator|:
name|MAM
argument_list|(
argument|Arg.MAM
argument_list|)
block|{}
name|Result
argument_list|(
name|Result
operator|&&
name|Arg
argument_list|)
operator|:
name|MAM
argument_list|(
argument|std::move(Arg.MAM)
argument_list|)
block|{}
name|Result
operator|&
name|operator
operator|=
operator|(
name|Result
name|RHS
operator|)
block|{
name|std
operator|::
name|swap
argument_list|(
name|MAM
argument_list|,
name|RHS
operator|.
name|MAM
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|const
name|ModuleAnalysisManager
operator|&
name|getManager
argument_list|()
specifier|const
block|{
return|return
operator|*
name|MAM
return|;
block|}
comment|/// \brief Handle invalidation by ignoring it, this pass is immutable.
name|bool
name|invalidate
argument_list|(
name|LazyCallGraph
operator|::
name|SCC
operator|*
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|private
label|:
specifier|const
name|ModuleAnalysisManager
modifier|*
name|MAM
decl_stmt|;
block|}
empty_stmt|;
specifier|static
name|void
modifier|*
name|ID
parameter_list|()
block|{
return|return
operator|(
name|void
operator|*
operator|)
operator|&
name|PassID
return|;
block|}
name|ModuleAnalysisManagerCGSCCProxy
argument_list|(
specifier|const
name|ModuleAnalysisManager
operator|&
name|MAM
argument_list|)
operator|:
name|MAM
argument_list|(
argument|&MAM
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|ModuleAnalysisManagerCGSCCProxy
argument_list|(
specifier|const
name|ModuleAnalysisManagerCGSCCProxy
operator|&
name|Arg
argument_list|)
operator|:
name|MAM
argument_list|(
argument|Arg.MAM
argument_list|)
block|{}
name|ModuleAnalysisManagerCGSCCProxy
argument_list|(
name|ModuleAnalysisManagerCGSCCProxy
operator|&&
name|Arg
argument_list|)
operator|:
name|MAM
argument_list|(
argument|std::move(Arg.MAM)
argument_list|)
block|{}
name|ModuleAnalysisManagerCGSCCProxy
operator|&
name|operator
operator|=
operator|(
name|ModuleAnalysisManagerCGSCCProxy
name|RHS
operator|)
block|{
name|std
operator|::
name|swap
argument_list|(
name|MAM
argument_list|,
name|RHS
operator|.
name|MAM
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Run the analysis pass and create our proxy result object.
comment|/// Nothing to see here, it just forwards the \c MAM reference into the
comment|/// result.
name|Result
name|run
argument_list|(
name|LazyCallGraph
operator|::
name|SCC
operator|*
argument_list|)
block|{
return|return
name|Result
argument_list|(
operator|*
name|MAM
argument_list|)
return|;
block|}
name|private
label|:
specifier|static
name|char
name|PassID
decl_stmt|;
specifier|const
name|ModuleAnalysisManager
modifier|*
name|MAM
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief The core module pass which does a post-order walk of the SCCs and
comment|/// runs a CGSCC pass over each one.
comment|///
comment|/// Designed to allow composition of a CGSCCPass(Manager) and
comment|/// a ModulePassManager. Note that this pass must be run with a module analysis
comment|/// manager as it uses the LazyCallGraph analysis. It will also run the
comment|/// \c CGSCCAnalysisManagerModuleProxy analysis prior to running the CGSCC
comment|/// pass over the module to enable a \c FunctionAnalysisManager to be used
comment|/// within this run safely.
name|template
operator|<
name|typename
name|CGSCCPassT
operator|>
name|class
name|ModuleToPostOrderCGSCCPassAdaptor
block|{
name|public
operator|:
name|explicit
name|ModuleToPostOrderCGSCCPassAdaptor
argument_list|(
argument|CGSCCPassT Pass
argument_list|)
operator|:
name|Pass
argument_list|(
argument|std::move(Pass)
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|ModuleToPostOrderCGSCCPassAdaptor
argument_list|(
specifier|const
name|ModuleToPostOrderCGSCCPassAdaptor
operator|&
name|Arg
argument_list|)
operator|:
name|Pass
argument_list|(
argument|Arg.Pass
argument_list|)
block|{}
name|ModuleToPostOrderCGSCCPassAdaptor
argument_list|(
name|ModuleToPostOrderCGSCCPassAdaptor
operator|&&
name|Arg
argument_list|)
operator|:
name|Pass
argument_list|(
argument|std::move(Arg.Pass)
argument_list|)
block|{}
name|friend
name|void
name|swap
argument_list|(
argument|ModuleToPostOrderCGSCCPassAdaptor&LHS
argument_list|,
argument|ModuleToPostOrderCGSCCPassAdaptor&RHS
argument_list|)
block|{
name|using
name|std
operator|::
name|swap
block|;
name|swap
argument_list|(
name|LHS
operator|.
name|Pass
argument_list|,
name|RHS
operator|.
name|Pass
argument_list|)
block|;   }
name|ModuleToPostOrderCGSCCPassAdaptor
operator|&
name|operator
operator|=
operator|(
name|ModuleToPostOrderCGSCCPassAdaptor
name|RHS
operator|)
block|{
name|swap
argument_list|(
operator|*
name|this
argument_list|,
name|RHS
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Runs the CGSCC pass across every SCC in the module.
name|PreservedAnalyses
name|run
argument_list|(
argument|Module *M
argument_list|,
argument|ModuleAnalysisManager *AM
argument_list|)
block|{
name|assert
argument_list|(
name|AM
operator|&&
literal|"We need analyses to compute the call graph!"
argument_list|)
block|;
comment|// Setup the CGSCC analysis manager from its proxy.
name|CGSCCAnalysisManager
operator|&
name|CGAM
operator|=
name|AM
operator|->
name|getResult
operator|<
name|CGSCCAnalysisManagerModuleProxy
operator|>
operator|(
name|M
operator|)
operator|.
name|getManager
argument_list|()
block|;
comment|// Get the call graph for this module.
name|LazyCallGraph
operator|&
name|CG
operator|=
name|AM
operator|->
name|getResult
operator|<
name|LazyCallGraphAnalysis
operator|>
operator|(
name|M
operator|)
block|;
name|PreservedAnalyses
name|PA
operator|=
name|PreservedAnalyses
operator|::
name|all
argument_list|()
block|;
for|for
control|(
name|LazyCallGraph
operator|::
name|SCC
operator|&
name|C
operator|:
name|CG
operator|.
name|postorder_sccs
argument_list|()
control|)
block|{
name|PreservedAnalyses
name|PassPA
init|=
name|Pass
operator|.
name|run
argument_list|(
operator|&
name|C
argument_list|,
operator|&
name|CGAM
argument_list|)
decl_stmt|;
comment|// We know that the CGSCC pass couldn't have invalidated any other
comment|// SCC's analyses (that's the contract of a CGSCC pass), so
comment|// directly handle the CGSCC analysis manager's invalidation here.
comment|// FIXME: This isn't quite correct. We need to handle the case where the
comment|// pass updated the CG, particularly some child of the current SCC, and
comment|// invalidate its analyses.
name|CGAM
operator|.
name|invalidate
argument_list|(
operator|&
name|C
argument_list|,
name|PassPA
argument_list|)
expr_stmt|;
comment|// Then intersect the preserved set so that invalidation of module
comment|// analyses will eventually occur when the module pass completes.
name|PA
operator|.
name|intersect
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|PassPA
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// By definition we preserve the proxy. This precludes *any* invalidation
comment|// of CGSCC analyses by the proxy, but that's OK because we've taken
comment|// care to invalidate analyses in the CGSCC analysis manager
comment|// incrementally above.
name|PA
operator|.
name|preserve
operator|<
name|CGSCCAnalysisManagerModuleProxy
operator|>
operator|(
operator|)
expr_stmt|;
return|return
name|PA
return|;
block|}
specifier|static
name|StringRef
name|name
parameter_list|()
block|{
return|return
literal|"ModuleToPostOrderCGSCCPassAdaptor"
return|;
block|}
name|private
label|:
name|CGSCCPassT
name|Pass
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief A function to deduce a function pass type and wrap it in the
end_comment

begin_comment
comment|/// templated adaptor.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|CGSCCPassT
operator|>
name|ModuleToPostOrderCGSCCPassAdaptor
operator|<
name|CGSCCPassT
operator|>
name|createModuleToPostOrderCGSCCPassAdaptor
argument_list|(
argument|CGSCCPassT Pass
argument_list|)
block|{
return|return
name|std
operator|::
name|move
argument_list|(
name|ModuleToPostOrderCGSCCPassAdaptor
operator|<
name|CGSCCPassT
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|Pass
argument_list|)
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief A CGSCC analysis which acts as a proxy for a function analysis
end_comment

begin_comment
comment|/// manager.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This primarily proxies invalidation information from the CGSCC analysis
end_comment

begin_comment
comment|/// manager and CGSCC pass manager to a function analysis manager. You should
end_comment

begin_comment
comment|/// never use a function analysis manager from within (transitively) a CGSCC
end_comment

begin_comment
comment|/// pass manager unless your parent CGSCC pass has received a proxy result
end_comment

begin_comment
comment|/// object for it.
end_comment

begin_decl_stmt
name|class
name|FunctionAnalysisManagerCGSCCProxy
block|{
name|public
label|:
name|class
name|Result
block|{
name|public
label|:
name|explicit
name|Result
argument_list|(
name|FunctionAnalysisManager
operator|&
name|FAM
argument_list|)
operator|:
name|FAM
argument_list|(
argument|&FAM
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because
comment|// MSVC refuses to generate them.
name|Result
argument_list|(
specifier|const
name|Result
operator|&
name|Arg
argument_list|)
operator|:
name|FAM
argument_list|(
argument|Arg.FAM
argument_list|)
block|{}
name|Result
argument_list|(
name|Result
operator|&&
name|Arg
argument_list|)
operator|:
name|FAM
argument_list|(
argument|std::move(Arg.FAM)
argument_list|)
block|{}
name|Result
operator|&
name|operator
operator|=
operator|(
name|Result
name|RHS
operator|)
block|{
name|std
operator|::
name|swap
argument_list|(
name|FAM
argument_list|,
name|RHS
operator|.
name|FAM
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
operator|~
name|Result
argument_list|()
expr_stmt|;
comment|/// \brief Accessor for the \c FunctionAnalysisManager.
name|FunctionAnalysisManager
modifier|&
name|getManager
parameter_list|()
block|{
return|return
operator|*
name|FAM
return|;
block|}
comment|/// \brief Handler for invalidation of the SCC.
comment|///
comment|/// If this analysis itself is preserved, then we assume that the set of \c
comment|/// Function objects in the \c SCC hasn't changed and thus we don't need
comment|/// to invalidate *all* cached data associated with a \c Function* in the \c
comment|/// FunctionAnalysisManager.
comment|///
comment|/// Regardless of whether this analysis is marked as preserved, all of the
comment|/// analyses in the \c FunctionAnalysisManager are potentially invalidated
comment|/// based on the set of preserved analyses.
name|bool
name|invalidate
argument_list|(
name|LazyCallGraph
operator|::
name|SCC
operator|*
name|C
argument_list|,
specifier|const
name|PreservedAnalyses
operator|&
name|PA
argument_list|)
decl_stmt|;
name|private
label|:
name|FunctionAnalysisManager
modifier|*
name|FAM
decl_stmt|;
block|}
empty_stmt|;
specifier|static
name|void
modifier|*
name|ID
parameter_list|()
block|{
return|return
operator|(
name|void
operator|*
operator|)
operator|&
name|PassID
return|;
block|}
name|explicit
name|FunctionAnalysisManagerCGSCCProxy
argument_list|(
name|FunctionAnalysisManager
operator|&
name|FAM
argument_list|)
operator|:
name|FAM
argument_list|(
argument|&FAM
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|FunctionAnalysisManagerCGSCCProxy
argument_list|(
specifier|const
name|FunctionAnalysisManagerCGSCCProxy
operator|&
name|Arg
argument_list|)
operator|:
name|FAM
argument_list|(
argument|Arg.FAM
argument_list|)
block|{}
name|FunctionAnalysisManagerCGSCCProxy
argument_list|(
name|FunctionAnalysisManagerCGSCCProxy
operator|&&
name|Arg
argument_list|)
operator|:
name|FAM
argument_list|(
argument|std::move(Arg.FAM)
argument_list|)
block|{}
name|FunctionAnalysisManagerCGSCCProxy
operator|&
name|operator
operator|=
operator|(
name|FunctionAnalysisManagerCGSCCProxy
name|RHS
operator|)
block|{
name|std
operator|::
name|swap
argument_list|(
name|FAM
argument_list|,
name|RHS
operator|.
name|FAM
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Run the analysis pass and create our proxy result object.
comment|///
comment|/// This doesn't do any interesting work, it is primarily used to insert our
comment|/// proxy result object into the module analysis cache so that we can proxy
comment|/// invalidation to the function analysis manager.
comment|///
comment|/// In debug builds, it will also assert that the analysis manager is empty
comment|/// as no queries should arrive at the function analysis manager prior to
comment|/// this analysis being requested.
name|Result
name|run
argument_list|(
name|LazyCallGraph
operator|::
name|SCC
operator|*
name|C
argument_list|)
decl_stmt|;
name|private
label|:
specifier|static
name|char
name|PassID
decl_stmt|;
name|FunctionAnalysisManager
modifier|*
name|FAM
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief A function analysis which acts as a proxy for a CGSCC analysis
end_comment

begin_comment
comment|/// manager.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This primarily provides an accessor to a parent CGSCC analysis manager to
end_comment

begin_comment
comment|/// function passes. Only the const interface of the CGSCC analysis manager is
end_comment

begin_comment
comment|/// provided to indicate that once inside of a function analysis pass you
end_comment

begin_comment
comment|/// cannot request a CGSCC analysis to actually run. Instead, the user must
end_comment

begin_comment
comment|/// rely on the \c getCachedResult API.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This proxy *doesn't* manage the invalidation in any way. That is handled by
end_comment

begin_comment
comment|/// the recursive return path of each layer of the pass manager and the
end_comment

begin_comment
comment|/// returned PreservedAnalysis set.
end_comment

begin_decl_stmt
name|class
name|CGSCCAnalysisManagerFunctionProxy
block|{
name|public
label|:
comment|/// \brief Result proxy object for \c ModuleAnalysisManagerFunctionProxy.
name|class
name|Result
block|{
name|public
label|:
name|explicit
name|Result
argument_list|(
specifier|const
name|CGSCCAnalysisManager
operator|&
name|CGAM
argument_list|)
operator|:
name|CGAM
argument_list|(
argument|&CGAM
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because
comment|// MSVC refuses to generate them.
name|Result
argument_list|(
specifier|const
name|Result
operator|&
name|Arg
argument_list|)
operator|:
name|CGAM
argument_list|(
argument|Arg.CGAM
argument_list|)
block|{}
name|Result
argument_list|(
name|Result
operator|&&
name|Arg
argument_list|)
operator|:
name|CGAM
argument_list|(
argument|std::move(Arg.CGAM)
argument_list|)
block|{}
name|Result
operator|&
name|operator
operator|=
operator|(
name|Result
name|RHS
operator|)
block|{
name|std
operator|::
name|swap
argument_list|(
name|CGAM
argument_list|,
name|RHS
operator|.
name|CGAM
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|const
name|CGSCCAnalysisManager
operator|&
name|getManager
argument_list|()
specifier|const
block|{
return|return
operator|*
name|CGAM
return|;
block|}
comment|/// \brief Handle invalidation by ignoring it, this pass is immutable.
name|bool
name|invalidate
parameter_list|(
name|Function
modifier|*
parameter_list|)
block|{
return|return
name|false
return|;
block|}
name|private
label|:
specifier|const
name|CGSCCAnalysisManager
modifier|*
name|CGAM
decl_stmt|;
block|}
empty_stmt|;
specifier|static
name|void
modifier|*
name|ID
parameter_list|()
block|{
return|return
operator|(
name|void
operator|*
operator|)
operator|&
name|PassID
return|;
block|}
name|CGSCCAnalysisManagerFunctionProxy
argument_list|(
specifier|const
name|CGSCCAnalysisManager
operator|&
name|CGAM
argument_list|)
operator|:
name|CGAM
argument_list|(
argument|&CGAM
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|CGSCCAnalysisManagerFunctionProxy
argument_list|(
specifier|const
name|CGSCCAnalysisManagerFunctionProxy
operator|&
name|Arg
argument_list|)
operator|:
name|CGAM
argument_list|(
argument|Arg.CGAM
argument_list|)
block|{}
name|CGSCCAnalysisManagerFunctionProxy
argument_list|(
name|CGSCCAnalysisManagerFunctionProxy
operator|&&
name|Arg
argument_list|)
operator|:
name|CGAM
argument_list|(
argument|std::move(Arg.CGAM)
argument_list|)
block|{}
name|CGSCCAnalysisManagerFunctionProxy
operator|&
name|operator
operator|=
operator|(
name|CGSCCAnalysisManagerFunctionProxy
name|RHS
operator|)
block|{
name|std
operator|::
name|swap
argument_list|(
name|CGAM
argument_list|,
name|RHS
operator|.
name|CGAM
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Run the analysis pass and create our proxy result object.
comment|/// Nothing to see here, it just forwards the \c CGAM reference into the
comment|/// result.
name|Result
name|run
parameter_list|(
name|Function
modifier|*
parameter_list|)
block|{
return|return
name|Result
argument_list|(
operator|*
name|CGAM
argument_list|)
return|;
block|}
name|private
label|:
specifier|static
name|char
name|PassID
decl_stmt|;
specifier|const
name|CGSCCAnalysisManager
modifier|*
name|CGAM
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Adaptor that maps from a SCC to its functions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Designed to allow composition of a FunctionPass(Manager) and
end_comment

begin_comment
comment|/// a CGSCCPassManager. Note that if this pass is constructed with a pointer
end_comment

begin_comment
comment|/// to a \c CGSCCAnalysisManager it will run the
end_comment

begin_comment
comment|/// \c FunctionAnalysisManagerCGSCCProxy analysis prior to running the function
end_comment

begin_comment
comment|/// pass over the SCC to enable a \c FunctionAnalysisManager to be used
end_comment

begin_comment
comment|/// within this run safely.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|FunctionPassT
operator|>
name|class
name|CGSCCToFunctionPassAdaptor
block|{
name|public
operator|:
name|explicit
name|CGSCCToFunctionPassAdaptor
argument_list|(
argument|FunctionPassT Pass
argument_list|)
operator|:
name|Pass
argument_list|(
argument|std::move(Pass)
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|CGSCCToFunctionPassAdaptor
argument_list|(
specifier|const
name|CGSCCToFunctionPassAdaptor
operator|&
name|Arg
argument_list|)
operator|:
name|Pass
argument_list|(
argument|Arg.Pass
argument_list|)
block|{}
name|CGSCCToFunctionPassAdaptor
argument_list|(
name|CGSCCToFunctionPassAdaptor
operator|&&
name|Arg
argument_list|)
operator|:
name|Pass
argument_list|(
argument|std::move(Arg.Pass)
argument_list|)
block|{}
name|friend
name|void
name|swap
argument_list|(
argument|CGSCCToFunctionPassAdaptor&LHS
argument_list|,
argument|CGSCCToFunctionPassAdaptor&RHS
argument_list|)
block|{
name|using
name|std
operator|::
name|swap
block|;
name|swap
argument_list|(
name|LHS
operator|.
name|Pass
argument_list|,
name|RHS
operator|.
name|Pass
argument_list|)
block|;   }
name|CGSCCToFunctionPassAdaptor
operator|&
name|operator
operator|=
operator|(
name|CGSCCToFunctionPassAdaptor
name|RHS
operator|)
block|{
name|swap
argument_list|(
operator|*
name|this
argument_list|,
name|RHS
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Runs the function pass across every function in the module.
name|PreservedAnalyses
name|run
argument_list|(
argument|LazyCallGraph::SCC *C
argument_list|,
argument|CGSCCAnalysisManager *AM
argument_list|)
block|{
name|FunctionAnalysisManager
operator|*
name|FAM
operator|=
name|nullptr
block|;
if|if
condition|(
name|AM
condition|)
comment|// Setup the function analysis manager from its proxy.
name|FAM
operator|=
operator|&
name|AM
operator|->
name|getResult
operator|<
name|FunctionAnalysisManagerCGSCCProxy
operator|>
operator|(
name|C
operator|)
operator|.
name|getManager
argument_list|()
expr_stmt|;
name|PreservedAnalyses
name|PA
operator|=
name|PreservedAnalyses
operator|::
name|all
argument_list|()
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|LazyCallGraph
operator|::
name|Node
operator|*
name|N
operator|:
operator|*
name|C
control|)
block|{
name|PreservedAnalyses
name|PassPA
init|=
name|Pass
operator|.
name|run
argument_list|(
operator|&
name|N
operator|->
name|getFunction
argument_list|()
argument_list|,
name|FAM
argument_list|)
decl_stmt|;
comment|// We know that the function pass couldn't have invalidated any other
comment|// function's analyses (that's the contract of a function pass), so
comment|// directly handle the function analysis manager's invalidation here.
if|if
condition|(
name|FAM
condition|)
name|FAM
operator|->
name|invalidate
argument_list|(
operator|&
name|N
operator|->
name|getFunction
argument_list|()
argument_list|,
name|PassPA
argument_list|)
expr_stmt|;
comment|// Then intersect the preserved set so that invalidation of module
comment|// analyses will eventually occur when the module pass completes.
name|PA
operator|.
name|intersect
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|PassPA
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_for

begin_comment
comment|// By definition we preserve the proxy. This precludes *any* invalidation
end_comment

begin_comment
comment|// of function analyses by the proxy, but that's OK because we've taken
end_comment

begin_comment
comment|// care to invalidate analyses in the function analysis manager
end_comment

begin_comment
comment|// incrementally above.
end_comment

begin_comment
comment|// FIXME: We need to update the call graph here to account for any deleted
end_comment

begin_comment
comment|// edges!
end_comment

begin_expr_stmt
name|PA
operator|.
name|preserve
operator|<
name|FunctionAnalysisManagerCGSCCProxy
operator|>
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|PA
return|;
end_return

begin_function
unit|}    static
name|StringRef
name|name
parameter_list|()
block|{
return|return
literal|"CGSCCToFunctionPassAdaptor"
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|FunctionPassT
name|Pass
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief A function to deduce a function pass type and wrap it in the
end_comment

begin_comment
comment|/// templated adaptor.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|FunctionPassT
operator|>
name|CGSCCToFunctionPassAdaptor
operator|<
name|FunctionPassT
operator|>
name|createCGSCCToFunctionPassAdaptor
argument_list|(
argument|FunctionPassT Pass
argument_list|)
block|{
return|return
name|std
operator|::
name|move
argument_list|(
name|CGSCCToFunctionPassAdaptor
operator|<
name|FunctionPassT
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|Pass
argument_list|)
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

