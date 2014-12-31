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
name|LLVM_ANALYSIS_CALLGRAPHSCCPASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_CALLGRAPHSCCPASS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/CallGraph.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
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
name|class
name|CallGraphSCC
decl_stmt|;
name|class
name|CallGraphSCCPass
range|:
name|public
name|Pass
block|{
name|public
operator|:
name|explicit
name|CallGraphSCCPass
argument_list|(
name|char
operator|&
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
comment|/// createPrinterPass - Get a pass that prints the Module
comment|/// corresponding to a CallGraph.
name|Pass
operator|*
name|createPrinterPass
argument_list|(
argument|raw_ostream&O
argument_list|,
argument|const std::string&Banner
argument_list|)
specifier|const
name|override
block|;
name|using
name|llvm
operator|::
name|Pass
operator|::
name|doInitialization
block|;
name|using
name|llvm
operator|::
name|Pass
operator|::
name|doFinalization
block|;
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
name|CallGraphSCC
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
name|void
name|assignPassManager
argument_list|(
argument|PMStack&PMS
argument_list|,
argument|PassManagerType PMT
argument_list|)
name|override
block|;
comment|///  Return what kind of Pass Manager can manage this pass.
name|PassManagerType
name|getPotentialPassManagerType
argument_list|()
specifier|const
name|override
block|{
return|return
name|PMT_CallGraphPassManager
return|;
block|}
comment|/// getAnalysisUsage - For this class, we declare that we require and preserve
comment|/// the call graph.  If the derived class implements this method, it should
comment|/// always explicitly call the implementation here.
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&Info
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
comment|/// CallGraphSCC - This is a single SCC that a CallGraphSCCPass is run on.
name|class
name|CallGraphSCC
block|{
name|void
modifier|*
name|Context
decl_stmt|;
comment|// The CGPassManager object that is vending this.
name|std
operator|::
name|vector
operator|<
name|CallGraphNode
operator|*
operator|>
name|Nodes
expr_stmt|;
name|public
label|:
name|CallGraphSCC
argument_list|(
name|void
operator|*
name|context
argument_list|)
operator|:
name|Context
argument_list|(
argument|context
argument_list|)
block|{}
name|void
name|initialize
argument_list|(
argument|CallGraphNode*const*I
argument_list|,
argument|CallGraphNode*const*E
argument_list|)
block|{
name|Nodes
operator|.
name|assign
argument_list|(
name|I
argument_list|,
name|E
argument_list|)
block|;   }
name|bool
name|isSingular
argument_list|()
specifier|const
block|{
return|return
name|Nodes
operator|.
name|size
argument_list|()
operator|==
literal|1
return|;
block|}
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|Nodes
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// ReplaceNode - This informs the SCC and the pass manager that the specified
comment|/// Old node has been deleted, and New is to be used in its place.
name|void
name|ReplaceNode
parameter_list|(
name|CallGraphNode
modifier|*
name|Old
parameter_list|,
name|CallGraphNode
modifier|*
name|New
parameter_list|)
function_decl|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|CallGraphNode
operator|*
operator|>
operator|::
name|const_iterator
name|iterator
expr_stmt|;
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Nodes
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Nodes
operator|.
name|end
argument_list|()
return|;
block|}
block|}
empty_stmt|;
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

