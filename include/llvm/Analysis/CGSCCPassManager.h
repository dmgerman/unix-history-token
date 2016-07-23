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
comment|/// traverse the graph in post order, they can effectively do pair-wise
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
file|"llvm/Analysis/LazyCallGraph.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
extern|extern template class PassManager<LazyCallGraph::SCC>;
comment|/// \brief The CGSCC pass manager.
comment|///
comment|/// See the documentation for the PassManager template for details. It runs
comment|/// a sequency of SCC passes over each SCC that the manager is run over. This
comment|/// typedef serves as a convenient way to refer to this construct.
typedef|typedef
name|PassManager
operator|<
name|LazyCallGraph
operator|::
name|SCC
operator|>
name|CGSCCPassManager
expr_stmt|;
extern|extern template class AnalysisManager<LazyCallGraph::SCC>;
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
operator|>
name|CGSCCAnalysisManager
expr_stmt|;
extern|extern template class InnerAnalysisManagerProxy<CGSCCAnalysisManager
operator|,
extern|Module>;
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
extern|extern template class OuterAnalysisManagerProxy<ModuleAnalysisManager
operator|,
extern|LazyCallGraph::SCC>;
comment|/// A proxy from a \c ModuleAnalysisManager to an \c SCC.
typedef|typedef
name|OuterAnalysisManagerProxy
operator|<
name|ModuleAnalysisManager
operator|,
name|LazyCallGraph
operator|::
name|SCC
operator|>
name|ModuleAnalysisManagerCGSCCProxy
expr_stmt|;
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
name|RefSCC
operator|&
name|RC
operator|:
name|CG
operator|.
name|postorder_ref_sccs
argument_list|()
control|)
block|{
if|if
condition|(
name|DebugLogging
condition|)
name|dbgs
argument_list|()
operator|<<
literal|"Running an SCC pass across the RefSCC: "
operator|<<
name|RC
operator|<<
literal|"\n"
expr_stmt|;
for|for
control|(
name|LazyCallGraph
operator|::
name|SCC
operator|&
name|C
operator|:
name|RC
control|)
block|{
name|PreservedAnalyses
name|PassPA
init|=
name|Pass
operator|.
name|run
argument_list|(
name|C
argument_list|,
name|CGAM
argument_list|)
decl_stmt|;
comment|// We know that the CGSCC pass couldn't have invalidated any other
comment|// SCC's analyses (that's the contract of a CGSCC pass), so
comment|// directly handle the CGSCC analysis manager's invalidation here. We
comment|// also update the preserved set of analyses to reflect that invalidated
comment|// analyses are now safe to preserve.
comment|// FIXME: This isn't quite correct. We need to handle the case where the
comment|// pass updated the CG, particularly some child of the current SCC, and
comment|// invalidate its analyses.
name|PassPA
operator|=
name|CGAM
operator|.
name|invalidate
argument_list|(
name|C
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|PassPA
argument_list|)
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

begin_extern
extern|extern template class InnerAnalysisManagerProxy<FunctionAnalysisManager
operator|,
extern|LazyCallGraph::SCC>;
end_extern

begin_comment
comment|/// A proxy from a \c FunctionAnalysisManager to an \c SCC.
end_comment

begin_typedef
typedef|typedef
name|InnerAnalysisManagerProxy
operator|<
name|FunctionAnalysisManager
operator|,
name|LazyCallGraph
operator|::
name|SCC
operator|>
name|FunctionAnalysisManagerCGSCCProxy
expr_stmt|;
end_typedef

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
operator|)
operator|.
name|getManager
argument_list|()
block|;
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
operator|&
name|N
operator|:
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
name|N
operator|.
name|getFunction
argument_list|()
argument_list|,
name|FAM
argument_list|)
decl_stmt|;
comment|// We know that the function pass couldn't have invalidated any other
comment|// function's analyses (that's the contract of a function pass), so
comment|// directly handle the function analysis manager's invalidation here.
comment|// Also, update the preserved analyses to reflect that once invalidated
comment|// these can again be preserved.
name|PassPA
operator|=
name|FAM
operator|.
name|invalidate
argument_list|(
name|N
operator|.
name|getFunction
argument_list|()
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|PassPA
argument_list|)
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

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

