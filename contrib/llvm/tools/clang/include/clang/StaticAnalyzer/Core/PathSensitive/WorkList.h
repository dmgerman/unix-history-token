begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- WorkList.h - Worklist class used by CoreEngine ---------------*- C++ -*-//
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
comment|//  This file defines WorkList, a pure virtual class that represents an opaque
end_comment

begin_comment
comment|//  worklist used by CoreEngine to explore the reachability state space.
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
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_WORKLIST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_WORKLIST_H
end_define

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/BlockCounter.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/ExplodedGraph.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CFGBlock
decl_stmt|;
name|namespace
name|ento
block|{
name|class
name|WorkListUnit
block|{
name|ExplodedNode
modifier|*
name|node
decl_stmt|;
name|BlockCounter
name|counter
decl_stmt|;
specifier|const
name|CFGBlock
modifier|*
name|block
decl_stmt|;
name|unsigned
name|blockIdx
decl_stmt|;
comment|// This is the index of the next statement.
name|public
label|:
name|WorkListUnit
argument_list|(
argument|ExplodedNode *N
argument_list|,
argument|BlockCounter C
argument_list|,
argument|const CFGBlock *B
argument_list|,
argument|unsigned idx
argument_list|)
block|:
name|node
argument_list|(
name|N
argument_list|)
operator|,
name|counter
argument_list|(
name|C
argument_list|)
operator|,
name|block
argument_list|(
name|B
argument_list|)
operator|,
name|blockIdx
argument_list|(
argument|idx
argument_list|)
block|{}
name|explicit
name|WorkListUnit
argument_list|(
argument|ExplodedNode *N
argument_list|,
argument|BlockCounter C
argument_list|)
operator|:
name|node
argument_list|(
name|N
argument_list|)
operator|,
name|counter
argument_list|(
name|C
argument_list|)
operator|,
name|block
argument_list|(
name|nullptr
argument_list|)
operator|,
name|blockIdx
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// Returns the node associated with the worklist unit.
name|ExplodedNode
operator|*
name|getNode
argument_list|()
specifier|const
block|{
return|return
name|node
return|;
block|}
comment|/// Returns the block counter map associated with the worklist unit.
name|BlockCounter
name|getBlockCounter
argument_list|()
specifier|const
block|{
return|return
name|counter
return|;
block|}
comment|/// Returns the CFGblock associated with the worklist unit.
specifier|const
name|CFGBlock
operator|*
name|getBlock
argument_list|()
specifier|const
block|{
return|return
name|block
return|;
block|}
comment|/// Return the index within the CFGBlock for the worklist unit.
name|unsigned
name|getIndex
argument_list|()
specifier|const
block|{
return|return
name|blockIdx
return|;
block|}
block|}
empty_stmt|;
name|class
name|WorkList
block|{
name|BlockCounter
name|CurrentCounter
decl_stmt|;
name|public
label|:
name|virtual
operator|~
name|WorkList
argument_list|()
expr_stmt|;
name|virtual
name|bool
name|hasWork
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|enqueue
parameter_list|(
specifier|const
name|WorkListUnit
modifier|&
name|U
parameter_list|)
init|=
literal|0
function_decl|;
name|void
name|enqueue
parameter_list|(
name|ExplodedNode
modifier|*
name|N
parameter_list|,
specifier|const
name|CFGBlock
modifier|*
name|B
parameter_list|,
name|unsigned
name|idx
parameter_list|)
block|{
name|enqueue
argument_list|(
name|WorkListUnit
argument_list|(
name|N
argument_list|,
name|CurrentCounter
argument_list|,
name|B
argument_list|,
name|idx
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|void
name|enqueue
parameter_list|(
name|ExplodedNode
modifier|*
name|N
parameter_list|)
block|{
name|assert
argument_list|(
name|N
operator|->
name|getLocation
argument_list|()
operator|.
name|getKind
argument_list|()
operator|!=
name|ProgramPoint
operator|::
name|PostStmtKind
argument_list|)
expr_stmt|;
name|enqueue
argument_list|(
name|WorkListUnit
argument_list|(
name|N
argument_list|,
name|CurrentCounter
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|virtual
name|WorkListUnit
name|dequeue
parameter_list|()
init|=
literal|0
function_decl|;
name|void
name|setBlockCounter
parameter_list|(
name|BlockCounter
name|C
parameter_list|)
block|{
name|CurrentCounter
operator|=
name|C
expr_stmt|;
block|}
name|BlockCounter
name|getBlockCounter
argument_list|()
specifier|const
block|{
return|return
name|CurrentCounter
return|;
block|}
name|class
name|Visitor
block|{
name|public
label|:
name|Visitor
argument_list|()
block|{}
name|virtual
operator|~
name|Visitor
argument_list|()
expr_stmt|;
name|virtual
name|bool
name|visit
parameter_list|(
specifier|const
name|WorkListUnit
modifier|&
name|U
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
name|virtual
name|bool
name|visitItemsInWorkList
parameter_list|(
name|Visitor
modifier|&
name|V
parameter_list|)
init|=
literal|0
function_decl|;
specifier|static
name|WorkList
modifier|*
name|makeDFS
parameter_list|()
function_decl|;
specifier|static
name|WorkList
modifier|*
name|makeBFS
parameter_list|()
function_decl|;
specifier|static
name|WorkList
modifier|*
name|makeBFSBlockDFSContents
parameter_list|()
function_decl|;
block|}
empty_stmt|;
block|}
comment|// end GR namespace
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

