begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- InlinerPass.h - Code common to all inliners --------------*- C++ -*-===//
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
comment|// This file defines a simple policy-based bottom-up inliner.  This file
end_comment

begin_comment
comment|// implements all of the boring mechanics of the bottom-up inlining, while the
end_comment

begin_comment
comment|// subclass determines WHAT to inline, which is the much more interesting
end_comment

begin_comment
comment|// component.
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
name|LLVM_TRANSFORMS_IPO_INLINERPASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_IPO_INLINERPASS_H
end_define

begin_include
include|#
directive|include
file|"llvm/CallGraphSCCPass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CallSite
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
name|class
name|InlineCost
decl_stmt|;
name|template
operator|<
name|class
name|PtrType
operator|,
name|unsigned
name|SmallSize
operator|>
name|class
name|SmallPtrSet
expr_stmt|;
comment|/// Inliner - This class contains all of the helper code which is used to
comment|/// perform the inlining operations that do not depend on the policy.
comment|///
name|struct
name|Inliner
range|:
name|public
name|CallGraphSCCPass
block|{
name|explicit
name|Inliner
argument_list|(
name|void
operator|*
name|ID
argument_list|)
block|;
name|explicit
name|Inliner
argument_list|(
argument|void *ID
argument_list|,
argument|int Threshold
argument_list|)
block|;
comment|/// getAnalysisUsage - For this class, we declare that we require and preserve
comment|/// the call graph.  If the derived class implements this method, it should
comment|/// always explicitly call the implementation here.
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&Info
argument_list|)
specifier|const
block|;
comment|// Main run interface method, this implements the interface required by the
comment|// Pass class.
name|virtual
name|bool
name|runOnSCC
argument_list|(
name|std
operator|::
name|vector
operator|<
name|CallGraphNode
operator|*
operator|>
operator|&
name|SCC
argument_list|)
block|;
comment|// doFinalization - Remove now-dead linkonce functions at the end of
comment|// processing to avoid breaking the SCC traversal.
name|virtual
name|bool
name|doFinalization
argument_list|(
name|CallGraph
operator|&
name|CG
argument_list|)
block|;
comment|/// This method returns the value specified by the -inline-threshold value,
comment|/// specified on the command line.  This is typically not directly needed.
comment|///
name|unsigned
name|getInlineThreshold
argument_list|()
specifier|const
block|{
return|return
name|InlineThreshold
return|;
block|}
comment|/// Calculate the inline threshold for given Caller. This threshold is lower
comment|/// if Caller is marked with OptimizeForSize and -inline-threshold is not
comment|/// given on the comand line.
comment|///
name|unsigned
name|getInlineThreshold
argument_list|(
argument|Function* Caller
argument_list|)
specifier|const
block|;
comment|/// getInlineCost - This method must be implemented by the subclass to
comment|/// determine the cost of inlining the specified call site.  If the cost
comment|/// returned is greater than the current inline threshold, the call site is
comment|/// not inlined.
comment|///
name|virtual
name|InlineCost
name|getInlineCost
argument_list|(
argument|CallSite CS
argument_list|)
operator|=
literal|0
block|;
comment|// getInlineFudgeFactor - Return a> 1.0 factor if the inliner should use a
comment|// higher threshold to determine if the function call should be inlined.
comment|///
name|virtual
name|float
name|getInlineFudgeFactor
argument_list|(
argument|CallSite CS
argument_list|)
operator|=
literal|0
block|;
comment|/// resetCachedCostInfo - erase any cached cost data from the derived class.
comment|/// If the derived class has no such data this can be empty.
comment|///
name|virtual
name|void
name|resetCachedCostInfo
argument_list|(
name|Function
operator|*
name|Caller
argument_list|)
operator|=
literal|0
block|;
comment|/// removeDeadFunctions - Remove dead functions that are not included in
comment|/// DNR (Do Not Remove) list.
name|bool
name|removeDeadFunctions
argument_list|(
name|CallGraph
operator|&
name|CG
argument_list|,
name|SmallPtrSet
operator|<
specifier|const
name|Function
operator|*
argument_list|,
literal|16
operator|>
operator|*
name|DNR
operator|=
name|NULL
argument_list|)
block|;
name|private
operator|:
comment|// InlineThreshold - Cache the value here for easy access.
name|unsigned
name|InlineThreshold
block|;
comment|/// shouldInline - Return true if the inliner should attempt to
comment|/// inline at the given CallSite.
name|bool
name|shouldInline
argument_list|(
argument|CallSite CS
argument_list|)
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

