begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- GRWorkList.h - Worklist class used by GRCoreEngine -----------*- C++ -*-//
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
comment|//  This file defines GRWorkList, a pure virtual class that represents an opaque
end_comment

begin_comment
comment|//  worklist used by GRCoreEngine to explore the reachability state space.
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
name|LLVM_CLANG_ANALYSIS_GRWORKLIST
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_GRWORKLIST
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/GRBlockCounter.h"
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CFGBlock
decl_stmt|;
name|class
name|ExplodedNode
decl_stmt|;
name|class
name|ExplodedNodeImpl
decl_stmt|;
name|class
name|GRWorkListUnit
block|{
name|ExplodedNode
modifier|*
name|Node
decl_stmt|;
name|GRBlockCounter
name|Counter
decl_stmt|;
name|CFGBlock
modifier|*
name|Block
decl_stmt|;
name|unsigned
name|BlockIdx
decl_stmt|;
comment|// This is the index of the next statement.
name|public
label|:
name|GRWorkListUnit
argument_list|(
argument|ExplodedNode* N
argument_list|,
argument|GRBlockCounter C
argument_list|,
argument|CFGBlock* B
argument_list|,
argument|unsigned idx
argument_list|)
block|:
name|Node
argument_list|(
name|N
argument_list|)
operator|,
name|Counter
argument_list|(
name|C
argument_list|)
operator|,
name|Block
argument_list|(
name|B
argument_list|)
operator|,
name|BlockIdx
argument_list|(
argument|idx
argument_list|)
block|{}
name|explicit
name|GRWorkListUnit
argument_list|(
argument|ExplodedNode* N
argument_list|,
argument|GRBlockCounter C
argument_list|)
operator|:
name|Node
argument_list|(
name|N
argument_list|)
operator|,
name|Counter
argument_list|(
name|C
argument_list|)
operator|,
name|Block
argument_list|(
name|NULL
argument_list|)
operator|,
name|BlockIdx
argument_list|(
literal|0
argument_list|)
block|{}
name|ExplodedNode
operator|*
name|getNode
argument_list|()
specifier|const
block|{
return|return
name|Node
return|;
block|}
name|GRBlockCounter
name|getBlockCounter
argument_list|()
specifier|const
block|{
return|return
name|Counter
return|;
block|}
name|CFGBlock
operator|*
name|getBlock
argument_list|()
specifier|const
block|{
return|return
name|Block
return|;
block|}
name|unsigned
name|getIndex
argument_list|()
specifier|const
block|{
return|return
name|BlockIdx
return|;
block|}
block|}
empty_stmt|;
name|class
name|GRWorkList
block|{
name|GRBlockCounter
name|CurrentCounter
decl_stmt|;
name|public
label|:
name|virtual
operator|~
name|GRWorkList
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
name|Enqueue
parameter_list|(
specifier|const
name|GRWorkListUnit
modifier|&
name|U
parameter_list|)
init|=
literal|0
function_decl|;
name|void
name|Enqueue
parameter_list|(
name|ExplodedNode
modifier|*
name|N
parameter_list|,
name|CFGBlock
modifier|&
name|B
parameter_list|,
name|unsigned
name|idx
parameter_list|)
block|{
name|Enqueue
argument_list|(
name|GRWorkListUnit
argument_list|(
name|N
argument_list|,
name|CurrentCounter
argument_list|,
operator|&
name|B
argument_list|,
name|idx
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|void
name|Enqueue
parameter_list|(
name|ExplodedNode
modifier|*
name|N
parameter_list|)
block|{
name|Enqueue
argument_list|(
name|GRWorkListUnit
argument_list|(
name|N
argument_list|,
name|CurrentCounter
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|virtual
name|GRWorkListUnit
name|Dequeue
parameter_list|()
init|=
literal|0
function_decl|;
name|void
name|setBlockCounter
parameter_list|(
name|GRBlockCounter
name|C
parameter_list|)
block|{
name|CurrentCounter
operator|=
name|C
expr_stmt|;
block|}
name|GRBlockCounter
name|getBlockCounter
argument_list|()
specifier|const
block|{
return|return
name|CurrentCounter
return|;
block|}
specifier|static
name|GRWorkList
modifier|*
name|MakeDFS
parameter_list|()
function_decl|;
specifier|static
name|GRWorkList
modifier|*
name|MakeBFS
parameter_list|()
function_decl|;
specifier|static
name|GRWorkList
modifier|*
name|MakeBFSBlockDFSContents
parameter_list|()
function_decl|;
block|}
empty_stmt|;
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

