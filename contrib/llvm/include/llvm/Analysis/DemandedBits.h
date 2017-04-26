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

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
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
struct_decl|struct
name|KnownBits
struct_decl|;
name|class
name|DemandedBits
block|{
name|public
label|:
name|DemandedBits
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|AssumptionCache
operator|&
name|AC
argument_list|,
name|DominatorTree
operator|&
name|DT
argument_list|)
operator|:
name|F
argument_list|(
name|F
argument_list|)
operator|,
name|AC
argument_list|(
name|AC
argument_list|)
operator|,
name|DT
argument_list|(
name|DT
argument_list|)
operator|,
name|Analyzed
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// Return the bits demanded from instruction I.
name|APInt
name|getDemandedBits
argument_list|(
name|Instruction
operator|*
name|I
argument_list|)
expr_stmt|;
comment|/// Return true if, during analysis, I could not be reached.
name|bool
name|isInstructionDead
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|)
function_decl|;
name|void
name|print
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|private
label|:
name|Function
modifier|&
name|F
decl_stmt|;
name|AssumptionCache
modifier|&
name|AC
decl_stmt|;
name|DominatorTree
modifier|&
name|DT
decl_stmt|;
name|void
name|performAnalysis
parameter_list|()
function_decl|;
name|void
name|determineLiveOperandBits
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|UserI
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|,
name|unsigned
name|OperandNo
parameter_list|,
specifier|const
name|APInt
modifier|&
name|AOut
parameter_list|,
name|APInt
modifier|&
name|AB
parameter_list|,
name|KnownBits
modifier|&
name|Known
parameter_list|,
name|KnownBits
modifier|&
name|Known2
parameter_list|)
function_decl|;
name|bool
name|Analyzed
decl_stmt|;
comment|// The set of visited instructions (non-integer-typed only).
name|SmallPtrSet
operator|<
name|Instruction
operator|*
operator|,
literal|32
operator|>
name|Visited
expr_stmt|;
name|DenseMap
operator|<
name|Instruction
operator|*
operator|,
name|APInt
operator|>
name|AliveBits
expr_stmt|;
block|}
empty_stmt|;
name|class
name|DemandedBitsWrapperPass
range|:
name|public
name|FunctionPass
block|{
name|private
operator|:
name|mutable
name|Optional
operator|<
name|DemandedBits
operator|>
name|DB
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeid
name|DemandedBitsWrapperPass
argument_list|()
block|;
name|bool
name|runOnFunction
argument_list|(
argument|Function&F
argument_list|)
name|override
block|;
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
comment|/// Clean up memory in between runs
name|void
name|releaseMemory
argument_list|()
name|override
block|;
name|DemandedBits
operator|&
name|getDemandedBits
argument_list|()
block|{
return|return
operator|*
name|DB
return|;
block|}
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const Module *M
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
comment|/// An analysis that produces \c DemandedBits for a function.
name|class
name|DemandedBitsAnalysis
range|:
name|public
name|AnalysisInfoMixin
operator|<
name|DemandedBitsAnalysis
operator|>
block|{
name|friend
name|AnalysisInfoMixin
operator|<
name|DemandedBitsAnalysis
operator|>
block|;
specifier|static
name|AnalysisKey
name|Key
block|;
name|public
operator|:
comment|/// \brief Provide the result typedef for this analysis pass.
typedef|typedef
name|DemandedBits
name|Result
typedef|;
comment|/// \brief Run the analysis pass over a function and produce demanded bits
comment|/// information.
name|DemandedBits
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
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Printer pass for DemandedBits
end_comment

begin_decl_stmt
name|class
name|DemandedBitsPrinterPass
range|:
name|public
name|PassInfoMixin
operator|<
name|DemandedBitsPrinterPass
operator|>
block|{
name|raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
name|explicit
name|DemandedBitsPrinterPass
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
operator|:
name|OS
argument_list|(
argument|OS
argument_list|)
block|{}
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
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Create a demanded bits analysis pass.
end_comment

begin_function_decl
name|FunctionPass
modifier|*
name|createDemandedBitsWrapperPass
parameter_list|()
function_decl|;
end_function_decl

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

