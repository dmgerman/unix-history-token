begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- UnifyFunctionExitNodes.h - Ensure fn's have one return --*- C++ -*-===//
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
comment|// This pass is used to ensure that functions have at most one return and one
end_comment

begin_comment
comment|// unwind instruction in them.  Additionally, it keeps track of which node is
end_comment

begin_comment
comment|// the new exit node of the CFG.  If there are no return or unwind instructions
end_comment

begin_comment
comment|// in the function, the getReturnBlock/getUnwindBlock methods will return a null
end_comment

begin_comment
comment|// pointer.
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
name|LLVM_TRANSFORMS_UTILS_UNIFYFUNCTIONEXITNODES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_UNIFYFUNCTIONEXITNODES_H
end_define

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/PassRegistry.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|struct
name|UnifyFunctionExitNodes
range|:
name|public
name|FunctionPass
block|{
name|BasicBlock
operator|*
name|ReturnBlock
operator|=
name|nullptr
block|;
name|BasicBlock
operator|*
name|UnwindBlock
operator|=
name|nullptr
block|;
name|BasicBlock
operator|*
name|UnreachableBlock
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeid
name|UnifyFunctionExitNodes
argument_list|()
operator|:
name|FunctionPass
argument_list|(
argument|ID
argument_list|)
block|{
name|initializeUnifyFunctionExitNodesPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;   }
comment|// We can preserve non-critical-edgeness when we unify function exit nodes
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
comment|// getReturn|Unwind|UnreachableBlock - Return the new single (or nonexistent)
comment|// return, unwind, or unreachable  basic blocks in the CFG.
comment|//
name|BasicBlock
operator|*
name|getReturnBlock
argument_list|()
specifier|const
block|{
return|return
name|ReturnBlock
return|;
block|}
name|BasicBlock
operator|*
name|getUnwindBlock
argument_list|()
specifier|const
block|{
return|return
name|UnwindBlock
return|;
block|}
name|BasicBlock
operator|*
name|getUnreachableBlock
argument_list|()
specifier|const
block|{
return|return
name|UnreachableBlock
return|;
block|}
name|bool
name|runOnFunction
argument_list|(
argument|Function&F
argument_list|)
name|override
block|; }
decl_stmt|;
name|Pass
modifier|*
name|createUnifyFunctionExitNodesPass
parameter_list|()
function_decl|;
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
comment|// LLVM_TRANSFORMS_UTILS_UNIFYFUNCTIONEXITNODES_H
end_comment

end_unit

