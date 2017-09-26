begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- MemCpyOptimizer.h - memcpy optimization ---------------*- C++ -*-===//
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
comment|// This pass performs various transformations related to eliminating memcpy
end_comment

begin_comment
comment|// calls, or transforming sets of stores into memset's.
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
name|LLVM_TRANSFORMS_SCALAR_MEMCPYOPTIMIZER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_MEMCPYOPTIMIZER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/AssumptionCache.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/MemoryDependenceAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/TargetLibraryInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/BasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Dominators.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instructions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/IntrinsicInst.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MemCpyOptPass
range|:
name|public
name|PassInfoMixin
operator|<
name|MemCpyOptPass
operator|>
block|{
name|MemoryDependenceResults
operator|*
name|MD
operator|=
name|nullptr
block|;
name|TargetLibraryInfo
operator|*
name|TLI
operator|=
name|nullptr
block|;
name|std
operator|::
name|function
operator|<
name|AliasAnalysis
operator|&
operator|(
operator|)
operator|>
name|LookupAliasAnalysis
block|;
name|std
operator|::
name|function
operator|<
name|AssumptionCache
operator|&
operator|(
operator|)
operator|>
name|LookupAssumptionCache
block|;
name|std
operator|::
name|function
operator|<
name|DominatorTree
operator|&
operator|(
operator|)
operator|>
name|LookupDomTree
block|;
name|public
operator|:
name|MemCpyOptPass
argument_list|()
operator|=
expr|default
block|;
name|PreservedAnalyses
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
name|AM
argument_list|)
block|;
comment|// Glue for the old PM.
name|bool
name|runImpl
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|MemoryDependenceResults
operator|*
name|MD_
argument_list|,
name|TargetLibraryInfo
operator|*
name|TLI_
argument_list|,
name|std
operator|::
name|function
operator|<
name|AliasAnalysis
operator|&
operator|(
operator|)
operator|>
name|LookupAliasAnalysis_
argument_list|,
name|std
operator|::
name|function
operator|<
name|AssumptionCache
operator|&
operator|(
operator|)
operator|>
name|LookupAssumptionCache_
argument_list|,
name|std
operator|::
name|function
operator|<
name|DominatorTree
operator|&
operator|(
operator|)
operator|>
name|LookupDomTree_
argument_list|)
block|;
name|private
operator|:
comment|// Helper functions
name|bool
name|processStore
argument_list|(
name|StoreInst
operator|*
name|SI
argument_list|,
name|BasicBlock
operator|::
name|iterator
operator|&
name|BBI
argument_list|)
block|;
name|bool
name|processMemSet
argument_list|(
name|MemSetInst
operator|*
name|SI
argument_list|,
name|BasicBlock
operator|::
name|iterator
operator|&
name|BBI
argument_list|)
block|;
name|bool
name|processMemCpy
argument_list|(
name|MemCpyInst
operator|*
name|M
argument_list|)
block|;
name|bool
name|processMemMove
argument_list|(
name|MemMoveInst
operator|*
name|M
argument_list|)
block|;
name|bool
name|performCallSlotOptzn
argument_list|(
argument|Instruction *cpy
argument_list|,
argument|Value *cpyDst
argument_list|,
argument|Value *cpySrc
argument_list|,
argument|uint64_t cpyLen
argument_list|,
argument|unsigned cpyAlign
argument_list|,
argument|CallInst *C
argument_list|)
block|;
name|bool
name|processMemCpyMemCpyDependence
argument_list|(
name|MemCpyInst
operator|*
name|M
argument_list|,
name|MemCpyInst
operator|*
name|MDep
argument_list|)
block|;
name|bool
name|processMemSetMemCpyDependence
argument_list|(
name|MemCpyInst
operator|*
name|M
argument_list|,
name|MemSetInst
operator|*
name|MDep
argument_list|)
block|;
name|bool
name|performMemCpyToMemSetOptzn
argument_list|(
name|MemCpyInst
operator|*
name|M
argument_list|,
name|MemSetInst
operator|*
name|MDep
argument_list|)
block|;
name|bool
name|processByValArgument
argument_list|(
argument|CallSite CS
argument_list|,
argument|unsigned ArgNo
argument_list|)
block|;
name|Instruction
operator|*
name|tryMergingIntoMemset
argument_list|(
name|Instruction
operator|*
name|I
argument_list|,
name|Value
operator|*
name|StartPtr
argument_list|,
name|Value
operator|*
name|ByteVal
argument_list|)
block|;
name|bool
name|iterateOnFunction
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

begin_comment
comment|// LLVM_TRANSFORMS_SCALAR_MEMCPYOPTIMIZER_H
end_comment

end_unit

