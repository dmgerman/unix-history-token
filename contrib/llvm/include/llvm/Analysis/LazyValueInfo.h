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
name|LLVM_ANALYSIS_LIVEVALUES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LIVEVALUES_H
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
name|Constant
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|/// LazyValueInfo - This pass computes, caches, and vends lazy value constraint
comment|/// information.
name|class
name|LazyValueInfo
range|:
name|public
name|FunctionPass
block|{
name|class
name|TargetData
operator|*
name|TD
block|;
name|void
operator|*
name|PImpl
block|;
name|LazyValueInfo
argument_list|(
specifier|const
name|LazyValueInfo
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT.
name|void
name|operator
operator|=
operator|(
specifier|const
name|LazyValueInfo
operator|&
operator|)
block|;
comment|// DO NOT IMPLEMENT.
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
operator|&
name|ID
argument_list|)
block|,
name|PImpl
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|LazyValueInfo
argument_list|()
block|{
name|assert
argument_list|(
name|PImpl
operator|==
literal|0
operator|&&
literal|"releaseMemory not called"
argument_list|)
block|; }
comment|/// Tristate - This is used to return true/false/dunno results.
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
comment|/// getPredicateOnEdge - Determine whether the specified value comparison
comment|/// with a constant is known to be true or false on the specified CFG edge.
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
argument_list|)
block|;
comment|/// getConstant - Determine whether the specified value is known to be a
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
argument_list|)
block|;
comment|/// getConstantOnEdge - Determine whether the specified value is known to be a
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
argument_list|)
block|;
comment|// Implementation boilerplate.
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
block|{
name|AU
operator|.
name|setPreservesAll
argument_list|()
block|;   }
name|virtual
name|void
name|releaseMemory
argument_list|()
block|;
name|virtual
name|bool
name|runOnFunction
argument_list|(
name|Function
operator|&
name|F
argument_list|)
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

