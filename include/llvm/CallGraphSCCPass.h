begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CallGraphSCCPass.h - Pass that operates BU on call graph -*- C++ -*-===//
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
comment|// This file defines the CallGraphSCCPass class, which is used for passes which
end_comment

begin_comment
comment|// are implemented as bottom-up traversals on the call graph.  Because there may
end_comment

begin_comment
comment|// be cycles in the call graph, passes of this type operate on the call-graph in
end_comment

begin_comment
comment|// SCC order: that is, they process function bottom-up, except for recursive
end_comment

begin_comment
comment|// functions, which they process all at once.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// These passes are inherently interprocedural, and are required to keep the
end_comment

begin_comment
comment|// call graph up-to-date if they do anything which could modify it.
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
name|LLVM_CALL_GRAPH_SCC_PASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CALL_GRAPH_SCC_PASS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/CallGraph.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CallGraphNode
decl_stmt|;
name|class
name|CallGraph
decl_stmt|;
name|class
name|PMStack
decl_stmt|;
name|struct
name|CallGraphSCCPass
range|:
name|public
name|Pass
block|{
name|explicit
name|CallGraphSCCPass
argument_list|(
argument|intptr_t pid
argument_list|)
operator|:
name|Pass
argument_list|(
argument|PT_CallGraphSCC
argument_list|,
argument|pid
argument_list|)
block|{}
name|explicit
name|CallGraphSCCPass
argument_list|(
name|void
operator|*
name|pid
argument_list|)
operator|:
name|Pass
argument_list|(
argument|PT_CallGraphSCC
argument_list|,
argument|pid
argument_list|)
block|{}
comment|/// doInitialization - This method is called before the SCC's of the program
comment|/// has been processed, allowing the pass to do initialization as necessary.
name|virtual
name|bool
name|doInitialization
argument_list|(
argument|CallGraph&CG
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// runOnSCC - This method should be implemented by the subclass to perform
comment|/// whatever action is necessary for the specified SCC.  Note that
comment|/// non-recursive (or only self-recursive) functions will have an SCC size of
comment|/// 1, where recursive portions of the call graph will have SCC size> 1.
comment|///
comment|/// SCC passes that add or delete functions to the SCC are required to update
comment|/// the SCC list, otherwise stale pointers may be dereferenced.
comment|///
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
operator|=
literal|0
block|;
comment|/// doFinalization - This method is called after the SCC's of the program has
comment|/// been processed, allowing the pass to do final cleanup as necessary.
name|virtual
name|bool
name|doFinalization
argument_list|(
argument|CallGraph&CG
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// Assign pass manager to manager this pass
name|virtual
name|void
name|assignPassManager
argument_list|(
argument|PMStack&PMS
argument_list|,
argument|PassManagerType PMT = PMT_CallGraphPassManager
argument_list|)
block|;
comment|///  Return what kind of Pass Manager can manage this pass.
name|virtual
name|PassManagerType
name|getPotentialPassManagerType
argument_list|()
specifier|const
block|{
return|return
name|PMT_CallGraphPassManager
return|;
block|}
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

