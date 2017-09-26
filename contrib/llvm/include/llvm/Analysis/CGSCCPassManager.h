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
comment|/// traverse the graph in post-order, they can effectively do pair-wise
end_comment

begin_comment
comment|/// interprocedural optimizations for all call edges in the program while
end_comment

begin_comment
comment|/// incrementally refining it and improving the context of these pair-wise
end_comment

begin_comment
comment|/// optimizations. At each call site edge, the callee has already been
end_comment

begin_comment
comment|/// optimized as much as is possible. This in turn allows very accurate
end_comment

begin_comment
comment|/// analysis of it for IPO.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A secondary more general goal is to be able to isolate optimization on
end_comment

begin_comment
comment|/// unrelated parts of the IR module. This is useful to ensure our
end_comment

begin_comment
comment|/// optimizations are principled and don't miss oportunities where refinement
end_comment

begin_comment
comment|/// of one part of the module influence transformations in another part of the
end_comment

begin_comment
comment|/// module. But this is also useful if we want to parallelize the optimizations
end_comment

begin_comment
comment|/// across common large module graph shapes which tend to be very wide and have
end_comment

begin_comment
comment|/// large regions of unrelated cliques.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// To satisfy these goals, we use the LazyCallGraph which provides two graphs
end_comment

begin_comment
comment|/// nested inside each other (and built lazily from the bottom-up): the call
end_comment

begin_comment
comment|/// graph proper, and a reference graph. The reference graph is super set of
end_comment

begin_comment
comment|/// the call graph and is a conservative approximation of what could through
end_comment

begin_comment
comment|/// scalar or CGSCC transforms *become* the call graph. Using this allows us to
end_comment

begin_comment
comment|/// ensure we optimize functions prior to them being introduced into the call
end_comment

begin_comment
comment|/// graph by devirtualization or other technique, and thus ensures that
end_comment

begin_comment
comment|/// subsequent pair-wise interprocedural optimizations observe the optimized
end_comment

begin_comment
comment|/// form of these functions. The (potentially transitive) reference
end_comment

begin_comment
comment|/// reachability used by the reference graph is a conservative approximation
end_comment

begin_comment
comment|/// that still allows us to have independent regions of the graph.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// FIXME: There is one major drawback of the reference graph: in its naive
end_comment

begin_comment
comment|/// form it is quadratic because it contains a distinct edge for each
end_comment

begin_comment
comment|/// (potentially indirect) reference, even if are all through some common
end_comment

begin_comment
comment|/// global table of function pointers. This can be fixed in a number of ways
end_comment

begin_comment
comment|/// that essentially preserve enough of the normalization. While it isn't
end_comment

begin_comment
comment|/// expected to completely preclude the usability of this, it will need to be
end_comment

begin_comment
comment|/// addressed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// All of these issues are made substantially more complex in the face of
end_comment

begin_comment
comment|/// mutations to the call graph while optimization passes are being run. When
end_comment

begin_comment
comment|/// mutations to the call graph occur we want to achieve two different things:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// - We need to update the call graph in-flight and invalidate analyses
end_comment

begin_comment
comment|///   cached on entities in the graph. Because of the cache-based analysis
end_comment

begin_comment
comment|///   design of the pass manager, it is essential to have stable identities for
end_comment

begin_comment
comment|///   the elements of the IR that passes traverse, and to invalidate any
end_comment

begin_comment
comment|///   analyses cached on these elements as the mutations take place.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// - We want to preserve the incremental and post-order traversal of the
end_comment

begin_comment
comment|///   graph even as it is refined and mutated. This means we want optimization
end_comment

begin_comment
comment|///   to observe the most refined form of the call graph and to do so in
end_comment

begin_comment
comment|///   post-order.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// To address this, the CGSCC manager uses both worklists that can be expanded
end_comment

begin_comment
comment|/// by passes which transform the IR, and provides invalidation tests to skip
end_comment

begin_comment
comment|/// entries that become dead. This extra data is provided to every SCC pass so
end_comment

begin_comment
comment|/// that it can carefully update the manager's traversal as the call graph
end_comment

begin_comment
comment|/// mutates.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// We also provide support for running function passes within the CGSCC walk,
end_comment

begin_comment
comment|/// and there we provide automatic update of the call graph including of the
end_comment

begin_comment
comment|/// pass manager to reflect call graph changes that fall out naturally as part
end_comment

begin_comment
comment|/// of scalar transformations.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The patterns used to ensure the goals of post-order visitation of the fully
end_comment

begin_comment
comment|/// refined graph:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// 1) Sink toward the "bottom" as the graph is refined. This means that any
end_comment

begin_comment
comment|///    iteration continues in some valid post-order sequence after the mutation
end_comment

begin_comment
comment|///    has altered the structure.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// 2) Enqueue in post-order, including the current entity. If the current
end_comment

begin_comment
comment|///    entity's shape changes, it and everything after it in post-order needs
end_comment

begin_comment
comment|///    to be visited to observe that shape.
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
name|LLVM_ANALYSIS_CGSCCPASSMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_CGSCCPASSMANAGER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/PriorityWorklist.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/LazyCallGraph.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallSite.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/InstIterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
struct_decl|struct
name|CGSCCUpdateResult
struct_decl|;
comment|/// Extern template declaration for the analysis set for this IR unit.
extern|extern template class AllAnalysesOn<LazyCallGraph::SCC>;
extern|extern template class AnalysisManager<LazyCallGraph::SCC
operator|,
extern|LazyCallGraph&>;
comment|/// \brief The CGSCC analysis manager.
comment|///
comment|/// See the documentation for the AnalysisManager template for detail
comment|/// documentation. This typedef serves as a convenient way to refer to this
comment|/// construct in the adaptors and proxies used to integrate this into the larger
comment|/// pass manager infrastructure.
typedef|typedef
name|AnalysisManager
operator|<
name|LazyCallGraph
operator|::
name|SCC
operator|,
name|LazyCallGraph
operator|&
operator|>
name|CGSCCAnalysisManager
expr_stmt|;
comment|// Explicit specialization and instantiation declarations for the pass manager.
comment|// See the comments on the definition of the specialization for details on how
comment|// it differs from the primary template.
name|template
operator|<
operator|>
name|PreservedAnalyses
name|PassManager
operator|<
name|LazyCallGraph
operator|::
name|SCC
operator|,
name|CGSCCAnalysisManager
operator|,
name|LazyCallGraph
operator|&
operator|,
name|CGSCCUpdateResult
operator|&
operator|>
operator|::
name|run
argument_list|(
name|LazyCallGraph
operator|::
name|SCC
operator|&
name|InitialC
argument_list|,
name|CGSCCAnalysisManager
operator|&
name|AM
argument_list|,
name|LazyCallGraph
operator|&
name|G
argument_list|,
name|CGSCCUpdateResult
operator|&
name|UR
argument_list|)
expr_stmt|;
extern|extern template class PassManager<LazyCallGraph::SCC
operator|,
extern|CGSCCAnalysisManager
operator|,
extern|LazyCallGraph&
operator|,
extern|CGSCCUpdateResult&>;
comment|/// \brief The CGSCC pass manager.
comment|///
comment|/// See the documentation for the PassManager template for details. It runs
comment|/// a sequence of SCC passes over each SCC that the manager is run over. This
comment|/// typedef serves as a convenient way to refer to this construct.
typedef|typedef
name|PassManager
operator|<
name|LazyCallGraph
operator|::
name|SCC
operator|,
name|CGSCCAnalysisManager
operator|,
name|LazyCallGraph
operator|&
operator|,
name|CGSCCUpdateResult
operator|&
operator|>
name|CGSCCPassManager
expr_stmt|;
comment|/// An explicit specialization of the require analysis template pass.
name|template
operator|<
name|typename
name|AnalysisT
operator|>
expr|struct
name|RequireAnalysisPass
operator|<
name|AnalysisT
operator|,
name|LazyCallGraph
operator|::
name|SCC
operator|,
name|CGSCCAnalysisManager
operator|,
name|LazyCallGraph
operator|&
operator|,
name|CGSCCUpdateResult
operator|&
operator|>
operator|:
name|PassInfoMixin
operator|<
name|RequireAnalysisPass
operator|<
name|AnalysisT
operator|,
name|LazyCallGraph
operator|::
name|SCC
operator|,
name|CGSCCAnalysisManager
operator|,
name|LazyCallGraph
operator|&
operator|,
name|CGSCCUpdateResult
operator|&
operator|>>
block|{
name|PreservedAnalyses
name|run
argument_list|(
argument|LazyCallGraph::SCC&C
argument_list|,
argument|CGSCCAnalysisManager&AM
argument_list|,
argument|LazyCallGraph&CG
argument_list|,
argument|CGSCCUpdateResult&
argument_list|)
block|{
operator|(
name|void
operator|)
name|AM
operator|.
name|template
name|getResult
operator|<
name|AnalysisT
operator|>
operator|(
name|C
operator|,
name|CG
operator|)
block|;
return|return
name|PreservedAnalyses
operator|::
name|all
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// A proxy from a \c CGSCCAnalysisManager to a \c Module.
typedef|typedef
name|InnerAnalysisManagerProxy
operator|<
name|CGSCCAnalysisManager
operator|,
name|Module
operator|>
name|CGSCCAnalysisManagerModuleProxy
expr_stmt|;
comment|/// We need a specialized result for the \c CGSCCAnalysisManagerModuleProxy so
comment|/// it can have access to the call graph in order to walk all the SCCs when
comment|/// invalidating things.
name|template
operator|<
operator|>
name|class
name|CGSCCAnalysisManagerModuleProxy
operator|::
name|Result
block|{
name|public
operator|:
name|explicit
name|Result
argument_list|(
name|CGSCCAnalysisManager
operator|&
name|InnerAM
argument_list|,
name|LazyCallGraph
operator|&
name|G
argument_list|)
operator|:
name|InnerAM
argument_list|(
operator|&
name|InnerAM
argument_list|)
block|,
name|G
argument_list|(
argument|&G
argument_list|)
block|{}
comment|/// \brief Accessor for the analysis manager.
name|CGSCCAnalysisManager
operator|&
name|getManager
argument_list|()
block|{
return|return
operator|*
name|InnerAM
return|;
block|}
comment|/// \brief Handler for invalidation of the Module.
comment|///
comment|/// If the proxy analysis itself is preserved, then we assume that the set of
comment|/// SCCs in the Module hasn't changed. Thus any pointers to SCCs in the
comment|/// CGSCCAnalysisManager are still valid, and we don't need to call \c clear
comment|/// on the CGSCCAnalysisManager.
comment|///
comment|/// Regardless of whether this analysis is marked as preserved, all of the
comment|/// analyses in the \c CGSCCAnalysisManager are potentially invalidated based
comment|/// on the set of preserved analyses.
name|bool
name|invalidate
argument_list|(
name|Module
operator|&
name|M
argument_list|,
specifier|const
name|PreservedAnalyses
operator|&
name|PA
argument_list|,
name|ModuleAnalysisManager
operator|::
name|Invalidator
operator|&
name|Inv
argument_list|)
block|;
name|private
operator|:
name|CGSCCAnalysisManager
operator|*
name|InnerAM
block|;
name|LazyCallGraph
operator|*
name|G
block|; }
expr_stmt|;
comment|/// Provide a specialized run method for the \c CGSCCAnalysisManagerModuleProxy
comment|/// so it can pass the lazy call graph to the result.
name|template
operator|<
operator|>
name|CGSCCAnalysisManagerModuleProxy
operator|::
name|Result
name|CGSCCAnalysisManagerModuleProxy
operator|::
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|ModuleAnalysisManager
operator|&
name|AM
argument_list|)
expr_stmt|;
comment|// Ensure the \c CGSCCAnalysisManagerModuleProxy is provided as an extern
comment|// template.
extern|extern template class InnerAnalysisManagerProxy<CGSCCAnalysisManager
operator|,
extern|Module>;
extern|extern template class OuterAnalysisManagerProxy<     ModuleAnalysisManager
operator|,
extern|LazyCallGraph::SCC
operator|,
extern|LazyCallGraph&>;
comment|/// A proxy from a \c ModuleAnalysisManager to an \c SCC.
typedef|typedef
name|OuterAnalysisManagerProxy
operator|<
name|ModuleAnalysisManager
operator|,
name|LazyCallGraph
operator|::
name|SCC
operator|,
name|LazyCallGraph
operator|&
operator|>
name|ModuleAnalysisManagerCGSCCProxy
expr_stmt|;
comment|/// Support structure for SCC passes to communicate updates the call graph back
comment|/// to the CGSCC pass manager infrsatructure.
comment|///
comment|/// The CGSCC pass manager runs SCC passes which are allowed to update the call
comment|/// graph and SCC structures. This means the structure the pass manager works
comment|/// on is mutating underneath it. In order to support that, there needs to be
comment|/// careful communication about the precise nature and ramifications of these
comment|/// updates to the pass management infrastructure.
comment|///
comment|/// All SCC passes will have to accept a reference to the management layer's
comment|/// update result struct and use it to reflect the results of any CG updates
comment|/// performed.
comment|///
comment|/// Passes which do not change the call graph structure in any way can just
comment|/// ignore this argument to their run method.
struct|struct
name|CGSCCUpdateResult
block|{
comment|/// Worklist of the RefSCCs queued for processing.
comment|///
comment|/// When a pass refines the graph and creates new RefSCCs or causes them to
comment|/// have a different shape or set of component SCCs it should add the RefSCCs
comment|/// to this worklist so that we visit them in the refined form.
comment|///
comment|/// This worklist is in reverse post-order, as we pop off the back in order
comment|/// to observe RefSCCs in post-order. When adding RefSCCs, clients should add
comment|/// them in reverse post-order.
name|SmallPriorityWorklist
operator|<
name|LazyCallGraph
operator|::
name|RefSCC
operator|*
operator|,
literal|1
operator|>
operator|&
name|RCWorklist
expr_stmt|;
comment|/// Worklist of the SCCs queued for processing.
comment|///
comment|/// When a pass refines the graph and creates new SCCs or causes them to have
comment|/// a different shape or set of component functions it should add the SCCs to
comment|/// this worklist so that we visit them in the refined form.
comment|///
comment|/// Note that if the SCCs are part of a RefSCC that is added to the \c
comment|/// RCWorklist, they don't need to be added here as visiting the RefSCC will
comment|/// be sufficient to re-visit the SCCs within it.
comment|///
comment|/// This worklist is in reverse post-order, as we pop off the back in order
comment|/// to observe SCCs in post-order. When adding SCCs, clients should add them
comment|/// in reverse post-order.
name|SmallPriorityWorklist
operator|<
name|LazyCallGraph
operator|::
name|SCC
operator|*
operator|,
literal|1
operator|>
operator|&
name|CWorklist
expr_stmt|;
comment|/// The set of invalidated RefSCCs which should be skipped if they are found
comment|/// in \c RCWorklist.
comment|///
comment|/// This is used to quickly prune out RefSCCs when they get deleted and
comment|/// happen to already be on the worklist. We use this primarily to avoid
comment|/// scanning the list and removing entries from it.
name|SmallPtrSetImpl
operator|<
name|LazyCallGraph
operator|::
name|RefSCC
operator|*
operator|>
operator|&
name|InvalidatedRefSCCs
expr_stmt|;
comment|/// The set of invalidated SCCs which should be skipped if they are found
comment|/// in \c CWorklist.
comment|///
comment|/// This is used to quickly prune out SCCs when they get deleted and happen
comment|/// to already be on the worklist. We use this primarily to avoid scanning
comment|/// the list and removing entries from it.
name|SmallPtrSetImpl
operator|<
name|LazyCallGraph
operator|::
name|SCC
operator|*
operator|>
operator|&
name|InvalidatedSCCs
expr_stmt|;
comment|/// If non-null, the updated current \c RefSCC being processed.
comment|///
comment|/// This is set when a graph refinement takes place an the "current" point in
comment|/// the graph moves "down" or earlier in the post-order walk. This will often
comment|/// cause the "current" RefSCC to be a newly created RefSCC object and the
comment|/// old one to be added to the above worklist. When that happens, this
comment|/// pointer is non-null and can be used to continue processing the "top" of
comment|/// the post-order walk.
name|LazyCallGraph
operator|::
name|RefSCC
operator|*
name|UpdatedRC
expr_stmt|;
comment|/// If non-null, the updated current \c SCC being processed.
comment|///
comment|/// This is set when a graph refinement takes place an the "current" point in
comment|/// the graph moves "down" or earlier in the post-order walk. This will often
comment|/// cause the "current" SCC to be a newly created SCC object and the old one
comment|/// to be added to the above worklist. When that happens, this pointer is
comment|/// non-null and can be used to continue processing the "top" of the
comment|/// post-order walk.
name|LazyCallGraph
operator|::
name|SCC
operator|*
name|UpdatedC
expr_stmt|;
block|}
struct|;
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
operator|:
name|public
name|PassInfoMixin
operator|<
name|ModuleToPostOrderCGSCCPassAdaptor
operator|<
name|CGSCCPassT
operator|>>
block|{
name|public
operator|:
name|explicit
name|ModuleToPostOrderCGSCCPassAdaptor
argument_list|(
argument|CGSCCPassT Pass
argument_list|,
argument|bool DebugLogging = false
argument_list|)
operator|:
name|Pass
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Pass
argument_list|)
argument_list|)
block|,
name|DebugLogging
argument_list|(
argument|DebugLogging
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
name|Arg
operator|.
name|Pass
argument_list|)
block|,
name|DebugLogging
argument_list|(
argument|Arg.DebugLogging
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
name|std
operator|::
name|move
argument_list|(
name|Arg
operator|.
name|Pass
argument_list|)
argument_list|)
block|,
name|DebugLogging
argument_list|(
argument|Arg.DebugLogging
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
block|;
name|swap
argument_list|(
name|LHS
operator|.
name|DebugLogging
argument_list|,
name|RHS
operator|.
name|DebugLogging
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
argument|Module&M
argument_list|,
argument|ModuleAnalysisManager&AM
argument_list|)
block|{
comment|// Setup the CGSCC analysis manager from its proxy.
name|CGSCCAnalysisManager
operator|&
name|CGAM
operator|=
name|AM
operator|.
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
operator|.
name|getResult
operator|<
name|LazyCallGraphAnalysis
operator|>
operator|(
name|M
operator|)
block|;
comment|// We keep worklists to allow us to push more work onto the pass manager as
comment|// the passes are run.
name|SmallPriorityWorklist
operator|<
name|LazyCallGraph
operator|::
name|RefSCC
operator|*
block|,
literal|1
operator|>
name|RCWorklist
block|;
name|SmallPriorityWorklist
operator|<
name|LazyCallGraph
operator|::
name|SCC
operator|*
block|,
literal|1
operator|>
name|CWorklist
block|;
comment|// Keep sets for invalidated SCCs and RefSCCs that should be skipped when
comment|// iterating off the worklists.
name|SmallPtrSet
operator|<
name|LazyCallGraph
operator|::
name|RefSCC
operator|*
block|,
literal|4
operator|>
name|InvalidRefSCCSet
block|;
name|SmallPtrSet
operator|<
name|LazyCallGraph
operator|::
name|SCC
operator|*
block|,
literal|4
operator|>
name|InvalidSCCSet
block|;
name|CGSCCUpdateResult
name|UR
operator|=
block|{
name|RCWorklist
block|,
name|CWorklist
block|,
name|InvalidRefSCCSet
block|,
name|InvalidSCCSet
block|,
name|nullptr
block|,
name|nullptr
block|}
block|;
name|PreservedAnalyses
name|PA
operator|=
name|PreservedAnalyses
operator|::
name|all
argument_list|()
block|;
name|CG
operator|.
name|buildRefSCCs
argument_list|()
block|;
for|for
control|(
name|auto
name|RCI
init|=
name|CG
operator|.
name|postorder_ref_scc_begin
argument_list|()
init|,
name|RCE
init|=
name|CG
operator|.
name|postorder_ref_scc_end
argument_list|()
init|;
name|RCI
operator|!=
name|RCE
condition|;
control|)
block|{
name|assert
argument_list|(
name|RCWorklist
operator|.
name|empty
argument_list|()
operator|&&
literal|"Should always start with an empty RefSCC worklist"
argument_list|)
expr_stmt|;
comment|// The postorder_ref_sccs range we are walking is lazily constructed, so
comment|// we only push the first one onto the worklist. The worklist allows us
comment|// to capture *new* RefSCCs created during transformations.
comment|//
comment|// We really want to form RefSCCs lazily because that makes them cheaper
comment|// to update as the program is simplified and allows us to have greater
comment|// cache locality as forming a RefSCC touches all the parts of all the
comment|// functions within that RefSCC.
comment|//
comment|// We also eagerly increment the iterator to the next position because
comment|// the CGSCC passes below may delete the current RefSCC.
name|RCWorklist
operator|.
name|insert
argument_list|(
operator|&
operator|*
name|RCI
operator|++
argument_list|)
expr_stmt|;
do|do
block|{
name|LazyCallGraph
operator|::
name|RefSCC
operator|*
name|RC
operator|=
name|RCWorklist
operator|.
name|pop_back_val
argument_list|()
expr_stmt|;
if|if
condition|(
name|InvalidRefSCCSet
operator|.
name|count
argument_list|(
name|RC
argument_list|)
condition|)
block|{
if|if
condition|(
name|DebugLogging
condition|)
name|dbgs
argument_list|()
operator|<<
literal|"Skipping an invalid RefSCC...\n"
expr_stmt|;
continue|continue;
block|}
name|assert
argument_list|(
name|CWorklist
operator|.
name|empty
argument_list|()
operator|&&
literal|"Should always start with an empty SCC worklist"
argument_list|)
expr_stmt|;
if|if
condition|(
name|DebugLogging
condition|)
name|dbgs
argument_list|()
operator|<<
literal|"Running an SCC pass across the RefSCC: "
operator|<<
operator|*
name|RC
operator|<<
literal|"\n"
expr_stmt|;
comment|// Push the initial SCCs in reverse post-order as we'll pop off the the
comment|// back and so see this in post-order.
for|for
control|(
name|LazyCallGraph
operator|::
name|SCC
operator|&
name|C
operator|:
name|reverse
argument_list|(
operator|*
name|RC
argument_list|)
control|)
name|CWorklist
operator|.
name|insert
argument_list|(
operator|&
name|C
argument_list|)
expr_stmt|;
do|do
block|{
name|LazyCallGraph
operator|::
name|SCC
operator|*
name|C
operator|=
name|CWorklist
operator|.
name|pop_back_val
argument_list|()
expr_stmt|;
comment|// Due to call graph mutations, we may have invalid SCCs or SCCs from
comment|// other RefSCCs in the worklist. The invalid ones are dead and the
comment|// other RefSCCs should be queued above, so we just need to skip both
comment|// scenarios here.
if|if
condition|(
name|InvalidSCCSet
operator|.
name|count
argument_list|(
name|C
argument_list|)
condition|)
block|{
if|if
condition|(
name|DebugLogging
condition|)
name|dbgs
argument_list|()
operator|<<
literal|"Skipping an invalid SCC...\n"
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
operator|&
name|C
operator|->
name|getOuterRefSCC
argument_list|()
operator|!=
name|RC
condition|)
block|{
if|if
condition|(
name|DebugLogging
condition|)
name|dbgs
argument_list|()
operator|<<
literal|"Skipping an SCC that is now part of some other "
literal|"RefSCC...\n"
expr_stmt|;
continue|continue;
block|}
do|do
block|{
comment|// Check that we didn't miss any update scenario.
name|assert
argument_list|(
operator|!
name|InvalidSCCSet
operator|.
name|count
argument_list|(
name|C
argument_list|)
operator|&&
literal|"Processing an invalid SCC!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|C
operator|->
name|begin
argument_list|()
operator|!=
name|C
operator|->
name|end
argument_list|()
operator|&&
literal|"Cannot have an empty SCC!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|&
name|C
operator|->
name|getOuterRefSCC
argument_list|()
operator|==
name|RC
operator|&&
literal|"Processing an SCC in a different RefSCC!"
argument_list|)
expr_stmt|;
name|UR
operator|.
name|UpdatedRC
operator|=
name|nullptr
expr_stmt|;
name|UR
operator|.
name|UpdatedC
operator|=
name|nullptr
expr_stmt|;
name|PreservedAnalyses
name|PassPA
init|=
name|Pass
operator|.
name|run
argument_list|(
operator|*
name|C
argument_list|,
name|CGAM
argument_list|,
name|CG
argument_list|,
name|UR
argument_list|)
decl_stmt|;
comment|// We handle invalidating the CGSCC analysis manager's information
comment|// for the (potentially updated) SCC here. Note that any other SCCs
comment|// whose structure has changed should have been invalidated by
comment|// whatever was updating the call graph. This SCC gets invalidated
comment|// late as it contains the nodes that were actively being
comment|// processed.
name|CGAM
operator|.
name|invalidate
argument_list|(
operator|*
operator|(
name|UR
operator|.
name|UpdatedC
condition|?
name|UR
operator|.
name|UpdatedC
else|:
name|C
operator|)
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
comment|// The pass may have restructured the call graph and refined the
comment|// current SCC and/or RefSCC. We need to update our current SCC and
comment|// RefSCC pointers to follow these. Also, when the current SCC is
comment|// refined, re-run the SCC pass over the newly refined SCC in order
comment|// to observe the most precise SCC model available. This inherently
comment|// cannot cycle excessively as it only happens when we split SCCs
comment|// apart, at most converging on a DAG of single nodes.
comment|// FIXME: If we ever start having RefSCC passes, we'll want to
comment|// iterate there too.
name|RC
operator|=
name|UR
operator|.
name|UpdatedRC
condition|?
name|UR
operator|.
name|UpdatedRC
else|:
name|RC
expr_stmt|;
name|C
operator|=
name|UR
operator|.
name|UpdatedC
condition|?
name|UR
operator|.
name|UpdatedC
else|:
name|C
expr_stmt|;
if|if
condition|(
name|DebugLogging
operator|&&
name|UR
operator|.
name|UpdatedC
condition|)
name|dbgs
argument_list|()
operator|<<
literal|"Re-running SCC passes after a refinement of the "
literal|"current SCC: "
operator|<<
operator|*
name|UR
operator|.
name|UpdatedC
operator|<<
literal|"\n"
expr_stmt|;
comment|// Note that both `C` and `RC` may at this point refer to deleted,
comment|// invalid SCC and RefSCCs respectively. But we will short circuit
comment|// the processing when we check them in the loop above.
block|}
while|while
condition|(
name|UR
operator|.
name|UpdatedC
condition|)
empty_stmt|;
do|} while
condition|(
operator|!
name|CWorklist
operator|.
name|empty
argument_list|()
condition|)
do|;
block|}
while|while
condition|(
operator|!
name|RCWorklist
operator|.
name|empty
argument_list|()
condition|)
empty_stmt|;
do|}
comment|// By definition we preserve the call garph, all SCC analyses, and the
comment|// analysis proxies by handling them above and in any nested pass managers.
do|PA.preserveSet<AllAnalysesOn<LazyCallGraph::SCC>>(
block|)
empty_stmt|;
do|PA.preserve<LazyCallGraphAnalysis>(
block|)
empty_stmt|;
name|PA
operator|.
name|preserve
operator|<
name|CGSCCAnalysisManagerModuleProxy
operator|>
operator|(
operator|)
block|;
name|PA
operator|.
name|preserve
operator|<
name|FunctionAnalysisManagerModuleProxy
operator|>
operator|(
operator|)
block|;
return|return
name|PA
return|;
block|}
name|private
label|:
name|CGSCCPassT
name|Pass
decl_stmt|;
name|bool
name|DebugLogging
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
argument_list|,
argument|bool DebugLogging = false
argument_list|)
block|{
return|return
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
operator|,
name|DebugLogging
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// A proxy from a \c FunctionAnalysisManager to an \c SCC.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// When a module pass runs and triggers invalidation, both the CGSCC and
end_comment

begin_comment
comment|/// Function analysis manager proxies on the module get an invalidation event.
end_comment

begin_comment
comment|/// We don't want to fully duplicate responsibility for most of the
end_comment

begin_comment
comment|/// invalidation logic. Instead, this layer is only responsible for SCC-local
end_comment

begin_comment
comment|/// invalidation events. We work with the module's FunctionAnalysisManager to
end_comment

begin_comment
comment|/// invalidate function analyses.
end_comment

begin_decl_stmt
name|class
name|FunctionAnalysisManagerCGSCCProxy
range|:
name|public
name|AnalysisInfoMixin
operator|<
name|FunctionAnalysisManagerCGSCCProxy
operator|>
block|{
name|public
operator|:
name|class
name|Result
block|{
name|public
operator|:
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
comment|/// \brief Accessor for the analysis manager.
name|FunctionAnalysisManager
operator|&
name|getManager
argument_list|()
block|{
return|return
operator|*
name|FAM
return|;
block|}
name|bool
name|invalidate
argument_list|(
name|LazyCallGraph
operator|::
name|SCC
operator|&
name|C
argument_list|,
specifier|const
name|PreservedAnalyses
operator|&
name|PA
argument_list|,
name|CGSCCAnalysisManager
operator|::
name|Invalidator
operator|&
name|Inv
argument_list|)
block|;
name|private
operator|:
name|FunctionAnalysisManager
operator|*
name|FAM
block|;   }
block|;
comment|/// Computes the \c FunctionAnalysisManager and stores it in the result proxy.
name|Result
name|run
argument_list|(
name|LazyCallGraph
operator|::
name|SCC
operator|&
name|C
argument_list|,
name|CGSCCAnalysisManager
operator|&
name|AM
argument_list|,
name|LazyCallGraph
operator|&
argument_list|)
block|;
name|private
operator|:
name|friend
name|AnalysisInfoMixin
operator|<
name|FunctionAnalysisManagerCGSCCProxy
operator|>
block|;
specifier|static
name|AnalysisKey
name|Key
block|; }
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern template class OuterAnalysisManagerProxy<CGSCCAnalysisManager
operator|,
extern|Function>;
end_extern

begin_comment
comment|/// A proxy from a \c CGSCCAnalysisManager to a \c Function.
end_comment

begin_typedef
typedef|typedef
name|OuterAnalysisManagerProxy
operator|<
name|CGSCCAnalysisManager
operator|,
name|Function
operator|>
name|CGSCCAnalysisManagerFunctionProxy
expr_stmt|;
end_typedef

begin_comment
comment|/// Helper to update the call graph after running a function pass.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Function passes can only mutate the call graph in specific ways. This
end_comment

begin_comment
comment|/// routine provides a helper that updates the call graph in those ways
end_comment

begin_comment
comment|/// including returning whether any changes were made and populating a CG
end_comment

begin_comment
comment|/// update result struct for the overall CGSCC walk.
end_comment

begin_expr_stmt
name|LazyCallGraph
operator|::
name|SCC
operator|&
name|updateCGAndAnalysisManagerForFunctionPass
argument_list|(
argument|LazyCallGraph&G
argument_list|,
argument|LazyCallGraph::SCC&C
argument_list|,
argument|LazyCallGraph::Node&N
argument_list|,
argument|CGSCCAnalysisManager&AM
argument_list|,
argument|CGSCCUpdateResult&UR
argument_list|,
argument|bool DebugLogging = false
argument_list|)
expr_stmt|;
end_expr_stmt

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
operator|:
name|public
name|PassInfoMixin
operator|<
name|CGSCCToFunctionPassAdaptor
operator|<
name|FunctionPassT
operator|>>
block|{
name|public
operator|:
name|explicit
name|CGSCCToFunctionPassAdaptor
argument_list|(
argument|FunctionPassT Pass
argument_list|,
argument|bool DebugLogging = false
argument_list|)
operator|:
name|Pass
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Pass
argument_list|)
argument_list|)
block|,
name|DebugLogging
argument_list|(
argument|DebugLogging
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
name|Arg
operator|.
name|Pass
argument_list|)
block|,
name|DebugLogging
argument_list|(
argument|Arg.DebugLogging
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
name|std
operator|::
name|move
argument_list|(
name|Arg
operator|.
name|Pass
argument_list|)
argument_list|)
block|,
name|DebugLogging
argument_list|(
argument|Arg.DebugLogging
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
block|;
name|swap
argument_list|(
name|LHS
operator|.
name|DebugLogging
argument_list|,
name|RHS
operator|.
name|DebugLogging
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
argument|LazyCallGraph::SCC&C
argument_list|,
argument|CGSCCAnalysisManager&AM
argument_list|,
argument|LazyCallGraph&CG
argument_list|,
argument|CGSCCUpdateResult&UR
argument_list|)
block|{
comment|// Setup the function analysis manager from its proxy.
name|FunctionAnalysisManager
operator|&
name|FAM
operator|=
name|AM
operator|.
name|getResult
operator|<
name|FunctionAnalysisManagerCGSCCProxy
operator|>
operator|(
name|C
operator|,
name|CG
operator|)
operator|.
name|getManager
argument_list|()
block|;
name|SmallVector
operator|<
name|LazyCallGraph
operator|::
name|Node
operator|*
block|,
literal|4
operator|>
name|Nodes
block|;
for|for
control|(
name|LazyCallGraph
operator|::
name|Node
operator|&
name|N
operator|:
name|C
control|)
name|Nodes
operator|.
name|push_back
argument_list|(
operator|&
name|N
argument_list|)
expr_stmt|;
comment|// The SCC may get split while we are optimizing functions due to deleting
comment|// edges. If this happens, the current SCC can shift, so keep track of
comment|// a pointer we can overwrite.
name|LazyCallGraph
operator|::
name|SCC
operator|*
name|CurrentC
operator|=
operator|&
name|C
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|DebugLogging
condition|)
name|dbgs
argument_list|()
operator|<<
literal|"Running function passes across an SCC: "
operator|<<
name|C
operator|<<
literal|"\n"
expr_stmt|;
end_if

begin_decl_stmt
name|PreservedAnalyses
name|PA
init|=
name|PreservedAnalyses
operator|::
name|all
argument_list|()
decl_stmt|;
end_decl_stmt

begin_for
for|for
control|(
name|LazyCallGraph
operator|::
name|Node
operator|*
name|N
operator|:
name|Nodes
control|)
block|{
comment|// Skip nodes from other SCCs. These may have been split out during
comment|// processing. We'll eventually visit those SCCs and pick up the nodes
comment|// there.
if|if
condition|(
name|CG
operator|.
name|lookupSCC
argument_list|(
operator|*
name|N
argument_list|)
operator|!=
name|CurrentC
condition|)
continue|continue;
name|PreservedAnalyses
name|PassPA
init|=
name|Pass
operator|.
name|run
argument_list|(
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
name|FAM
operator|.
name|invalidate
argument_list|(
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
comment|// If the call graph hasn't been preserved, update it based on this
comment|// function pass. This may also update the current SCC to point to
comment|// a smaller, more refined SCC.
name|auto
name|PAC
init|=
name|PA
operator|.
name|getChecker
operator|<
name|LazyCallGraphAnalysis
operator|>
operator|(
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|PAC
operator|.
name|preserved
argument_list|()
operator|&&
operator|!
name|PAC
operator|.
name|preservedSet
operator|<
name|AllAnalysesOn
operator|<
name|Module
operator|>>
operator|(
operator|)
condition|)
block|{
name|CurrentC
operator|=
operator|&
name|updateCGAndAnalysisManagerForFunctionPass
argument_list|(
name|CG
argument_list|,
operator|*
name|CurrentC
argument_list|,
operator|*
name|N
argument_list|,
name|AM
argument_list|,
name|UR
argument_list|,
name|DebugLogging
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|CG
operator|.
name|lookupSCC
argument_list|(
operator|*
name|N
argument_list|)
operator|==
name|CurrentC
operator|&&
literal|"Current SCC not updated to the SCC containing the current node!"
argument_list|)
expr_stmt|;
block|}
block|}
end_for

begin_comment
comment|// By definition we preserve the proxy. And we preserve all analyses on
end_comment

begin_comment
comment|// Functions. This precludes *any* invalidation of function analyses by the
end_comment

begin_comment
comment|// proxy, but that's OK because we've taken care to invalidate analyses in
end_comment

begin_comment
comment|// the function analysis manager incrementally above.
end_comment

begin_expr_stmt
name|PA
operator|.
name|preserveSet
operator|<
name|AllAnalysesOn
operator|<
name|Function
operator|>>
operator|(
operator|)
expr_stmt|;
end_expr_stmt

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

begin_comment
comment|// We've also ensured that we updated the call graph along the way.
end_comment

begin_expr_stmt
name|PA
operator|.
name|preserve
operator|<
name|LazyCallGraphAnalysis
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

begin_decl_stmt
unit|}  private:
name|FunctionPassT
name|Pass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|DebugLogging
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
argument_list|,
argument|bool DebugLogging = false
argument_list|)
block|{
return|return
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
operator|,
name|DebugLogging
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// A helper that repeats an SCC pass each time an indirect call is refined to
end_comment

begin_comment
comment|/// a direct call by that pass.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// While the CGSCC pass manager works to re-visit SCCs and RefSCCs as they
end_comment

begin_comment
comment|/// change shape, we may also want to repeat an SCC pass if it simply refines
end_comment

begin_comment
comment|/// an indirect call to a direct call, even if doing so does not alter the
end_comment

begin_comment
comment|/// shape of the graph. Note that this only pertains to direct calls to
end_comment

begin_comment
comment|/// functions where IPO across the SCC may be able to compute more precise
end_comment

begin_comment
comment|/// results. For intrinsics, we assume scalar optimizations already can fully
end_comment

begin_comment
comment|/// reason about them.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This repetition has the potential to be very large however, as each one
end_comment

begin_comment
comment|/// might refine a single call site. As a consequence, in practice we use an
end_comment

begin_comment
comment|/// upper bound on the number of repetitions to limit things.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|PassT
operator|>
name|class
name|DevirtSCCRepeatedPass
operator|:
name|public
name|PassInfoMixin
operator|<
name|DevirtSCCRepeatedPass
operator|<
name|PassT
operator|>>
block|{
name|public
operator|:
name|explicit
name|DevirtSCCRepeatedPass
argument_list|(
argument|PassT Pass
argument_list|,
argument|int MaxIterations
argument_list|,
argument|bool DebugLogging = false
argument_list|)
operator|:
name|Pass
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Pass
argument_list|)
argument_list|)
block|,
name|MaxIterations
argument_list|(
name|MaxIterations
argument_list|)
block|,
name|DebugLogging
argument_list|(
argument|DebugLogging
argument_list|)
block|{}
comment|/// Runs the wrapped pass up to \c MaxIterations on the SCC, iterating
comment|/// whenever an indirect call is refined.
name|PreservedAnalyses
name|run
argument_list|(
argument|LazyCallGraph::SCC&InitialC
argument_list|,
argument|CGSCCAnalysisManager&AM
argument_list|,
argument|LazyCallGraph&CG
argument_list|,
argument|CGSCCUpdateResult&UR
argument_list|)
block|{
name|PreservedAnalyses
name|PA
operator|=
name|PreservedAnalyses
operator|::
name|all
argument_list|()
block|;
comment|// The SCC may be refined while we are running passes over it, so set up
comment|// a pointer that we can update.
name|LazyCallGraph
operator|::
name|SCC
operator|*
name|C
operator|=
operator|&
name|InitialC
block|;
comment|// Collect value handles for all of the indirect call sites.
name|SmallVector
operator|<
name|WeakTrackingVH
block|,
literal|8
operator|>
name|CallHandles
block|;
comment|// Struct to track the counts of direct and indirect calls in each function
comment|// of the SCC.
block|struct
name|CallCount
block|{
name|int
name|Direct
block|;
name|int
name|Indirect
block|;     }
block|;
comment|// Put value handles on all of the indirect calls and return the number of
comment|// direct calls for each function in the SCC.
name|auto
name|ScanSCC
operator|=
index|[]
operator|(
name|LazyCallGraph
operator|::
name|SCC
operator|&
name|C
operator|,
name|SmallVectorImpl
operator|<
name|WeakTrackingVH
operator|>
operator|&
name|CallHandles
operator|)
block|{
name|assert
argument_list|(
name|CallHandles
operator|.
name|empty
argument_list|()
operator|&&
literal|"Must start with a clear set of handles."
argument_list|)
block|;
name|SmallVector
operator|<
name|CallCount
block|,
literal|4
operator|>
name|CallCounts
block|;
for|for
control|(
name|LazyCallGraph
operator|::
name|Node
operator|&
name|N
operator|:
name|C
control|)
block|{
name|CallCounts
operator|.
name|push_back
argument_list|(
block|{
literal|0
block|,
literal|0
block|}
argument_list|)
expr_stmt|;
name|CallCount
modifier|&
name|Count
init|=
name|CallCounts
operator|.
name|back
argument_list|()
decl_stmt|;
for|for
control|(
name|Instruction
modifier|&
name|I
range|:
name|instructions
argument_list|(
name|N
operator|.
name|getFunction
argument_list|()
argument_list|)
control|)
if|if
condition|(
name|auto
name|CS
init|=
name|CallSite
argument_list|(
operator|&
name|I
argument_list|)
condition|)
block|{
if|if
condition|(
name|CS
operator|.
name|getCalledFunction
argument_list|()
condition|)
block|{
operator|++
name|Count
operator|.
name|Direct
expr_stmt|;
block|}
else|else
block|{
operator|++
name|Count
operator|.
name|Indirect
expr_stmt|;
name|CallHandles
operator|.
name|push_back
argument_list|(
name|WeakTrackingVH
argument_list|(
operator|&
name|I
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_expr_stmt

begin_expr_stmt
unit|}        return
name|CallCounts
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Populate the initial call handles and get the initial call counts.
end_comment

begin_decl_stmt
name|auto
name|CallCounts
init|=
name|ScanSCC
argument_list|(
operator|*
name|C
argument_list|,
name|CallHandles
argument_list|)
decl_stmt|;
end_decl_stmt

begin_for
for|for
control|(
name|int
name|Iteration
init|=
literal|0
init|;
condition|;
operator|++
name|Iteration
control|)
block|{
name|PreservedAnalyses
name|PassPA
init|=
name|Pass
operator|.
name|run
argument_list|(
operator|*
name|C
argument_list|,
name|AM
argument_list|,
name|CG
argument_list|,
name|UR
argument_list|)
decl_stmt|;
comment|// If the SCC structure has changed, bail immediately and let the outer
comment|// CGSCC layer handle any iteration to reflect the refined structure.
if|if
condition|(
name|UR
operator|.
name|UpdatedC
operator|&&
name|UR
operator|.
name|UpdatedC
operator|!=
name|C
condition|)
block|{
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
break|break;
block|}
comment|// Check that we didn't miss any update scenario.
name|assert
argument_list|(
operator|!
name|UR
operator|.
name|InvalidatedSCCs
operator|.
name|count
argument_list|(
name|C
argument_list|)
operator|&&
literal|"Processing an invalid SCC!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|C
operator|->
name|begin
argument_list|()
operator|!=
name|C
operator|->
name|end
argument_list|()
operator|&&
literal|"Cannot have an empty SCC!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|int
operator|)
name|CallCounts
operator|.
name|size
argument_list|()
operator|==
name|C
operator|->
name|size
argument_list|()
operator|&&
literal|"Cannot have changed the size of the SCC!"
argument_list|)
expr_stmt|;
comment|// Check whether any of the handles were devirtualized.
name|auto
name|IsDevirtualizedHandle
init|=
index|[
operator|&
index|]
operator|(
name|WeakTrackingVH
operator|&
name|CallH
operator|)
block|{
if|if
condition|(
operator|!
name|CallH
condition|)
return|return
name|false
return|;
name|auto
name|CS
operator|=
name|CallSite
argument_list|(
name|CallH
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|CS
condition|)
return|return
name|false
return|;
comment|// If the call is still indirect, leave it alone.
name|Function
modifier|*
name|F
init|=
name|CS
operator|.
name|getCalledFunction
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|F
condition|)
return|return
name|false
return|;
if|if
condition|(
name|DebugLogging
condition|)
name|dbgs
argument_list|()
operator|<<
literal|"Found devirutalized call from "
operator|<<
name|CS
operator|.
name|getParent
argument_list|()
operator|->
name|getParent
argument_list|()
operator|->
name|getName
argument_list|()
operator|<<
literal|" to "
operator|<<
name|F
operator|->
name|getName
argument_list|()
operator|<<
literal|"\n"
expr_stmt|;
comment|// We now have a direct call where previously we had an indirect call,
comment|// so iterate to process this devirtualization site.
return|return
name|true
return|;
block|}
end_for

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|bool
name|Devirt
init|=
name|any_of
argument_list|(
name|CallHandles
argument_list|,
name|IsDevirtualizedHandle
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Rescan to build up a new set of handles and count how many direct
end_comment

begin_comment
comment|// calls remain. If we decide to iterate, this also sets up the input to
end_comment

begin_comment
comment|// the next iteration.
end_comment

begin_expr_stmt
name|CallHandles
operator|.
name|clear
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|auto
name|NewCallCounts
init|=
name|ScanSCC
argument_list|(
operator|*
name|C
argument_list|,
name|CallHandles
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// If we haven't found an explicit devirtualization already see if we
end_comment

begin_comment
comment|// have decreased the number of indirect calls and increased the number
end_comment

begin_comment
comment|// of direct calls for any function in the SCC. This can be fooled by all
end_comment

begin_comment
comment|// manner of transformations such as DCE and other things, but seems to
end_comment

begin_comment
comment|// work well in practice.
end_comment

begin_if
if|if
condition|(
operator|!
name|Devirt
condition|)
for|for
control|(
name|int
name|i
init|=
literal|0
init|,
name|Size
init|=
name|C
operator|->
name|size
argument_list|()
init|;
name|i
operator|<
name|Size
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|CallCounts
index|[
name|i
index|]
operator|.
name|Indirect
operator|>
name|NewCallCounts
index|[
name|i
index|]
operator|.
name|Indirect
operator|&&
name|CallCounts
index|[
name|i
index|]
operator|.
name|Direct
operator|<
name|NewCallCounts
index|[
name|i
index|]
operator|.
name|Direct
condition|)
block|{
name|Devirt
operator|=
name|true
expr_stmt|;
break|break;
block|}
end_if

begin_if
if|if
condition|(
operator|!
name|Devirt
condition|)
block|{
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
break|break;
block|}
end_if

begin_comment
comment|// Otherwise, if we've already hit our max, we're done.
end_comment

begin_if
if|if
condition|(
name|Iteration
operator|>=
name|MaxIterations
condition|)
block|{
if|if
condition|(
name|DebugLogging
condition|)
name|dbgs
argument_list|()
operator|<<
literal|"Found another devirtualization after hitting the max "
literal|"number of repetitions ("
operator|<<
name|MaxIterations
operator|<<
literal|") on SCC: "
operator|<<
operator|*
name|C
operator|<<
literal|"\n"
expr_stmt|;
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
break|break;
block|}
end_if

begin_if
if|if
condition|(
name|DebugLogging
condition|)
name|dbgs
argument_list|()
operator|<<
literal|"Repeating an SCC pass after finding a devirtualization in: "
operator|<<
operator|*
name|C
operator|<<
literal|"\n"
expr_stmt|;
end_if

begin_comment
comment|// Move over the new call counts in preparation for iterating.
end_comment

begin_expr_stmt
name|CallCounts
operator|=
name|std
operator|::
name|move
argument_list|(
name|NewCallCounts
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Update the analysis manager with each run and intersect the total set
end_comment

begin_comment
comment|// of preserved analyses so we're ready to iterate.
end_comment

begin_expr_stmt
name|AM
operator|.
name|invalidate
argument_list|(
operator|*
name|C
argument_list|,
name|PassPA
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
unit|}
comment|// Note that we don't add any preserved entries here unlike a more normal
end_comment

begin_comment
comment|// "pass manager" because we only handle invalidation *between* iterations,
end_comment

begin_comment
comment|// not after the last iteration.
end_comment

begin_expr_stmt
unit|return
name|PA
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|}  private:
name|PassT
name|Pass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|MaxIterations
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|DebugLogging
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
name|PassT
operator|>
name|DevirtSCCRepeatedPass
operator|<
name|PassT
operator|>
name|createDevirtSCCRepeatedPass
argument_list|(
argument|PassT Pass
argument_list|,
argument|int MaxIterations
argument_list|,
argument|bool DebugLogging = false
argument_list|)
block|{
return|return
name|DevirtSCCRepeatedPass
operator|<
name|PassT
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|Pass
argument_list|)
operator|,
name|MaxIterations
operator|,
name|DebugLogging
operator|)
return|;
block|}
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

