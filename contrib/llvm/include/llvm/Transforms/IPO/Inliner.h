begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Inliner.h - Inliner pass and infrastructure --------------*- C++ -*-===//
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
name|LLVM_TRANSFORMS_IPO_INLINER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_IPO_INLINER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/CGSCCPassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/CallGraphSCCPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/InlineCost.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/LazyCallGraph.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/TargetTransformInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/Utils/ImportedFunctionsInliningStatistics.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AssumptionCacheTracker
decl_stmt|;
name|class
name|CallSite
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|InlineCost
decl_stmt|;
name|class
name|OptimizationRemarkEmitter
decl_stmt|;
name|class
name|ProfileSummaryInfo
decl_stmt|;
comment|/// This class contains all of the helper code which is used to perform the
comment|/// inlining operations that do not depend on the policy. It contains the core
comment|/// bottom-up inlining infrastructure that specific inliner passes use.
name|struct
name|LegacyInlinerBase
range|:
name|public
name|CallGraphSCCPass
block|{
name|explicit
name|LegacyInlinerBase
argument_list|(
name|char
operator|&
name|ID
argument_list|)
block|;
name|explicit
name|LegacyInlinerBase
argument_list|(
argument|char&ID
argument_list|,
argument|bool InsertLifetime
argument_list|)
block|;
comment|/// For this class, we declare that we require and preserve the call graph.
comment|/// If the derived class implements this method, it should always explicitly
comment|/// call the implementation here.
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&Info
argument_list|)
specifier|const
name|override
block|;
name|bool
name|doInitialization
argument_list|(
argument|CallGraph&CG
argument_list|)
name|override
block|;
comment|/// Main run interface method, this implements the interface required by the
comment|/// Pass class.
name|bool
name|runOnSCC
argument_list|(
argument|CallGraphSCC&SCC
argument_list|)
name|override
block|;
name|using
name|llvm
operator|::
name|Pass
operator|::
name|doFinalization
block|;
comment|/// Remove now-dead linkonce functions at the end of processing to avoid
comment|/// breaking the SCC traversal.
name|bool
name|doFinalization
argument_list|(
argument|CallGraph&CG
argument_list|)
name|override
block|;
comment|/// This method must be implemented by the subclass to determine the cost of
comment|/// inlining the specified call site.  If the cost returned is greater than
comment|/// the current inline threshold, the call site is not inlined.
name|virtual
name|InlineCost
name|getInlineCost
argument_list|(
argument|CallSite CS
argument_list|)
operator|=
literal|0
block|;
comment|/// Remove dead functions.
comment|///
comment|/// This also includes a hack in the form of the 'AlwaysInlineOnly' flag
comment|/// which restricts it to deleting functions with an 'AlwaysInline'
comment|/// attribute. This is useful for the InlineAlways pass that only wants to
comment|/// deal with that subset of the functions.
name|bool
name|removeDeadFunctions
argument_list|(
argument|CallGraph&CG
argument_list|,
argument|bool AlwaysInlineOnly = false
argument_list|)
block|;
comment|/// This function performs the main work of the pass.  The default of
comment|/// Inlinter::runOnSCC() calls skipSCC() before calling this method, but
comment|/// derived classes which cannot be skipped can override that method and call
comment|/// this function unconditionally.
name|bool
name|inlineCalls
argument_list|(
name|CallGraphSCC
operator|&
name|SCC
argument_list|)
block|;
name|private
operator|:
comment|// Insert @llvm.lifetime intrinsics.
name|bool
name|InsertLifetime
block|;
name|protected
operator|:
name|AssumptionCacheTracker
operator|*
name|ACT
block|;
name|ProfileSummaryInfo
operator|*
name|PSI
block|;
name|ImportedFunctionsInliningStatistics
name|ImportedFunctionsStats
block|; }
decl_stmt|;
comment|/// The inliner pass for the new pass manager.
comment|///
comment|/// This pass wires together the inlining utilities and the inline cost
comment|/// analysis into a CGSCC pass. It considers every call in every function in
comment|/// the SCC and tries to inline if profitable. It can be tuned with a number of
comment|/// parameters to control what cost model is used and what tradeoffs are made
comment|/// when making the decision.
comment|///
comment|/// It should be noted that the legacy inliners do considerably more than this
comment|/// inliner pass does. They provide logic for manually merging allocas, and
comment|/// doing considerable DCE including the DCE of dead functions. This pass makes
comment|/// every attempt to be simpler. DCE of functions requires complex reasoning
comment|/// about comdat groups, etc. Instead, it is expected that other more focused
comment|/// passes be composed to achieve the same end result.
name|class
name|InlinerPass
range|:
name|public
name|PassInfoMixin
operator|<
name|InlinerPass
operator|>
block|{
name|public
operator|:
name|InlinerPass
argument_list|(
argument|InlineParams Params = getInlineParams()
argument_list|)
operator|:
name|Params
argument_list|(
argument|std::move(Params)
argument_list|)
block|{}
name|PreservedAnalyses
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
name|CG
argument_list|,
name|CGSCCUpdateResult
operator|&
name|UR
argument_list|)
block|;
name|private
operator|:
name|InlineParams
name|Params
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

