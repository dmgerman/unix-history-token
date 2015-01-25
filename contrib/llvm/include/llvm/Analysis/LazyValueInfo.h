begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LazyValueInfo.h - Value constraint analysis --------------*- C++ -*-===//
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
comment|// This file defines the interface for lazy computation of value constraint
end_comment

begin_comment
comment|// information.
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
name|LLVM_ANALYSIS_LAZYVALUEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LAZYVALUEINFO_H
end_define

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
name|AssumptionCache
decl_stmt|;
name|class
name|Constant
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|DominatorTree
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|TargetLibraryInfo
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|/// This pass computes, caches, and vends lazy value constraint information.
name|class
name|LazyValueInfo
range|:
name|public
name|FunctionPass
block|{
name|AssumptionCache
operator|*
name|AC
block|;
specifier|const
name|DataLayout
operator|*
name|DL
block|;
name|class
name|TargetLibraryInfo
operator|*
name|TLI
block|;
name|DominatorTree
operator|*
name|DT
block|;
name|void
operator|*
name|PImpl
block|;
name|LazyValueInfo
argument_list|(
argument|const LazyValueInfo&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|LazyValueInfo
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|LazyValueInfo
argument_list|()
operator|:
name|FunctionPass
argument_list|(
name|ID
argument_list|)
block|,
name|PImpl
argument_list|(
argument|nullptr
argument_list|)
block|{
name|initializeLazyValueInfoPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;   }
operator|~
name|LazyValueInfo
argument_list|()
block|{
name|assert
argument_list|(
operator|!
name|PImpl
operator|&&
literal|"releaseMemory not called"
argument_list|)
block|; }
comment|/// This is used to return true/false/dunno results.
expr|enum
name|Tristate
block|{
name|Unknown
operator|=
operator|-
literal|1
block|,
name|False
operator|=
literal|0
block|,
name|True
operator|=
literal|1
block|}
block|;
comment|// Public query interface.
comment|/// Determine whether the specified value comparison with a constant is known
comment|/// to be true or false on the specified CFG edge.
comment|/// Pred is a CmpInst predicate.
name|Tristate
name|getPredicateOnEdge
argument_list|(
argument|unsigned Pred
argument_list|,
argument|Value *V
argument_list|,
argument|Constant *C
argument_list|,
argument|BasicBlock *FromBB
argument_list|,
argument|BasicBlock *ToBB
argument_list|,
argument|Instruction *CxtI = nullptr
argument_list|)
block|;
comment|/// Determine whether the specified value comparison with a constant is known
comment|/// to be true or false at the specified instruction
comment|/// (from an assume intrinsic). Pred is a CmpInst predicate.
name|Tristate
name|getPredicateAt
argument_list|(
argument|unsigned Pred
argument_list|,
argument|Value *V
argument_list|,
argument|Constant *C
argument_list|,
argument|Instruction *CxtI
argument_list|)
block|;
comment|/// Determine whether the specified value is known to be a
comment|/// constant at the end of the specified block.  Return null if not.
name|Constant
operator|*
name|getConstant
argument_list|(
name|Value
operator|*
name|V
argument_list|,
name|BasicBlock
operator|*
name|BB
argument_list|,
name|Instruction
operator|*
name|CxtI
operator|=
name|nullptr
argument_list|)
block|;
comment|/// Determine whether the specified value is known to be a
comment|/// constant on the specified edge.  Return null if not.
name|Constant
operator|*
name|getConstantOnEdge
argument_list|(
name|Value
operator|*
name|V
argument_list|,
name|BasicBlock
operator|*
name|FromBB
argument_list|,
name|BasicBlock
operator|*
name|ToBB
argument_list|,
name|Instruction
operator|*
name|CxtI
operator|=
name|nullptr
argument_list|)
block|;
comment|/// Inform the analysis cache that we have threaded an edge from
comment|/// PredBB to OldSucc to be from PredBB to NewSucc instead.
name|void
name|threadEdge
argument_list|(
name|BasicBlock
operator|*
name|PredBB
argument_list|,
name|BasicBlock
operator|*
name|OldSucc
argument_list|,
name|BasicBlock
operator|*
name|NewSucc
argument_list|)
block|;
comment|/// Inform the analysis cache that we have erased a block.
name|void
name|eraseBlock
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
block|;
comment|// Implementation boilerplate.
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
name|void
name|releaseMemory
argument_list|()
name|override
block|;
name|bool
name|runOnFunction
argument_list|(
argument|Function&F
argument_list|)
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

