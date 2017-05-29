begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LiveStackAnalysis.h - Live Stack Slot Analysis -----------*- C++ -*-===//
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
comment|// This file implements the live stack slot analysis pass. It is analogous to
end_comment

begin_comment
comment|// live interval analysis except it's analyzing liveness of stack slots rather
end_comment

begin_comment
comment|// than registers.
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
name|LLVM_CODEGEN_LIVESTACKANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_LIVESTACKANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/LiveInterval.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<unordered_map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|TargetRegisterClass
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|LiveStacks
range|:
name|public
name|MachineFunctionPass
block|{
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
block|;
comment|/// Special pool allocator for VNInfo's (LiveInterval val#).
comment|///
name|VNInfo
operator|::
name|Allocator
name|VNInfoAllocator
block|;
comment|/// S2IMap - Stack slot indices to live interval mapping.
name|using
name|SS2IntervalMap
operator|=
name|std
operator|::
name|unordered_map
operator|<
name|int
block|,
name|LiveInterval
operator|>
block|;
name|SS2IntervalMap
name|S2IMap
block|;
comment|/// S2RCMap - Stack slot indices to register class mapping.
name|std
operator|::
name|map
operator|<
name|int
block|,
specifier|const
name|TargetRegisterClass
operator|*
operator|>
name|S2RCMap
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeid
name|LiveStacks
argument_list|()
operator|:
name|MachineFunctionPass
argument_list|(
argument|ID
argument_list|)
block|{
name|initializeLiveStacksPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;   }
name|using
name|iterator
operator|=
name|SS2IntervalMap
operator|::
name|iterator
block|;
name|using
name|const_iterator
operator|=
name|SS2IntervalMap
operator|::
name|const_iterator
block|;
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|S2IMap
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|S2IMap
operator|.
name|end
argument_list|()
return|;
block|}
name|iterator
name|begin
argument_list|()
block|{
return|return
name|S2IMap
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
argument_list|()
block|{
return|return
name|S2IMap
operator|.
name|end
argument_list|()
return|;
block|}
name|unsigned
name|getNumIntervals
argument_list|()
specifier|const
block|{
return|return
operator|(
name|unsigned
operator|)
name|S2IMap
operator|.
name|size
argument_list|()
return|;
block|}
name|LiveInterval
operator|&
name|getOrCreateInterval
argument_list|(
argument|int Slot
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|)
block|;
name|LiveInterval
operator|&
name|getInterval
argument_list|(
argument|int Slot
argument_list|)
block|{
name|assert
argument_list|(
name|Slot
operator|>=
literal|0
operator|&&
literal|"Spill slot indice must be>= 0"
argument_list|)
block|;
name|SS2IntervalMap
operator|::
name|iterator
name|I
operator|=
name|S2IMap
operator|.
name|find
argument_list|(
name|Slot
argument_list|)
block|;
name|assert
argument_list|(
name|I
operator|!=
name|S2IMap
operator|.
name|end
argument_list|()
operator|&&
literal|"Interval does not exist for stack slot"
argument_list|)
block|;
return|return
name|I
operator|->
name|second
return|;
block|}
specifier|const
name|LiveInterval
operator|&
name|getInterval
argument_list|(
argument|int Slot
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|Slot
operator|>=
literal|0
operator|&&
literal|"Spill slot indice must be>= 0"
argument_list|)
block|;
name|SS2IntervalMap
operator|::
name|const_iterator
name|I
operator|=
name|S2IMap
operator|.
name|find
argument_list|(
name|Slot
argument_list|)
block|;
name|assert
argument_list|(
name|I
operator|!=
name|S2IMap
operator|.
name|end
argument_list|()
operator|&&
literal|"Interval does not exist for stack slot"
argument_list|)
block|;
return|return
name|I
operator|->
name|second
return|;
block|}
name|bool
name|hasInterval
argument_list|(
argument|int Slot
argument_list|)
specifier|const
block|{
return|return
name|S2IMap
operator|.
name|count
argument_list|(
name|Slot
argument_list|)
return|;
block|}
specifier|const
name|TargetRegisterClass
operator|*
name|getIntervalRegClass
argument_list|(
argument|int Slot
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|Slot
operator|>=
literal|0
operator|&&
literal|"Spill slot indice must be>= 0"
argument_list|)
block|;
name|std
operator|::
name|map
operator|<
name|int
block|,
specifier|const
name|TargetRegisterClass
operator|*
operator|>
operator|::
name|const_iterator
name|I
operator|=
name|S2RCMap
operator|.
name|find
argument_list|(
name|Slot
argument_list|)
block|;
name|assert
argument_list|(
name|I
operator|!=
name|S2RCMap
operator|.
name|end
argument_list|()
operator|&&
literal|"Register class info does not exist for stack slot"
argument_list|)
block|;
return|return
name|I
operator|->
name|second
return|;
block|}
name|VNInfo
operator|::
name|Allocator
operator|&
name|getVNInfoAllocator
argument_list|()
block|{
return|return
name|VNInfoAllocator
return|;
block|}
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
comment|/// runOnMachineFunction - pass entry point
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&
argument_list|)
name|override
block|;
comment|/// print - Implement the dump method.
name|void
name|print
argument_list|(
argument|raw_ostream&O
argument_list|,
argument|const Module * = nullptr
argument_list|)
specifier|const
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

begin_comment
comment|// LLVM_CODEGEN_LIVESTACK_ANALYSIS_H
end_comment

end_unit

