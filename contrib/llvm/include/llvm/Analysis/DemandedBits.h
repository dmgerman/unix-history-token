begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Analysis/DemandedBits.h - Determine demanded bits --*- C++ -*-===//
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
comment|// This pass implements a demanded bits analysis. A demanded bit is one that
end_comment

begin_comment
comment|// contributes to a result; bits that are not demanded can be either zero or
end_comment

begin_comment
comment|// one without affecting control or data flow. For example in this sequence:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   %1 = add i32 %x, %y
end_comment

begin_comment
comment|//   %2 = trunc i32 %1 to i16
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Only the lowest 16 bits of %1 are demanded; the rest are removed by the
end_comment

begin_comment
comment|// trunc.
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
name|LLVM_ANALYSIS_DEMANDED_BITS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_DEMANDED_BITS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/APInt.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FunctionPass
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|DominatorTree
decl_stmt|;
name|class
name|AssumptionCache
decl_stmt|;
name|struct
name|DemandedBits
range|:
name|public
name|FunctionPass
block|{
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeid
name|DemandedBits
argument_list|()
block|;
name|bool
name|runOnFunction
argument_list|(
argument|Function& F
argument_list|)
name|override
block|;
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage& AU
argument_list|)
specifier|const
name|override
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const Module *M
argument_list|)
specifier|const
name|override
block|;
comment|/// Return the bits demanded from instruction I.
name|APInt
name|getDemandedBits
argument_list|(
name|Instruction
operator|*
name|I
argument_list|)
block|;
comment|/// Return true if, during analysis, I could not be reached.
name|bool
name|isInstructionDead
argument_list|(
name|Instruction
operator|*
name|I
argument_list|)
block|;
name|private
operator|:
name|void
name|performAnalysis
argument_list|()
block|;
name|void
name|determineLiveOperandBits
argument_list|(
argument|const Instruction *UserI
argument_list|,
argument|const Instruction *I
argument_list|,
argument|unsigned OperandNo
argument_list|,
argument|const APInt&AOut
argument_list|,
argument|APInt&AB
argument_list|,
argument|APInt&KnownZero
argument_list|,
argument|APInt&KnownOne
argument_list|,
argument|APInt&KnownZero2
argument_list|,
argument|APInt&KnownOne2
argument_list|)
block|;
name|AssumptionCache
operator|*
name|AC
block|;
name|DominatorTree
operator|*
name|DT
block|;
name|Function
operator|*
name|F
block|;
name|bool
name|Analyzed
block|;
comment|// The set of visited instructions (non-integer-typed only).
name|SmallPtrSet
operator|<
name|Instruction
operator|*
block|,
literal|128
operator|>
name|Visited
block|;
name|DenseMap
operator|<
name|Instruction
operator|*
block|,
name|APInt
operator|>
name|AliveBits
block|; }
decl_stmt|;
comment|/// Create a demanded bits analysis pass.
name|FunctionPass
modifier|*
name|createDemandedBitsPass
parameter_list|()
function_decl|;
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

