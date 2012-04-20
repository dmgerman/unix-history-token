begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CodeMetrics.h - Code cost measurements -------------------*- C++ -*-===//
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
comment|// This file implements various weight measurements for code, helping
end_comment

begin_comment
comment|// the Inliner and other passes decide whether to duplicate its contents.
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
name|LLVM_ANALYSIS_CODEMETRICS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_CODEMETRICS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BasicBlock
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|/// \brief Check whether an instruction is likely to be "free" when lowered.
name|bool
name|isInstructionFree
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// \brief Check whether a call will lower to something small.
comment|///
comment|/// This tests checks whether calls to this function will lower to something
comment|/// significantly cheaper than a traditional call, often a single
comment|/// instruction.
name|bool
name|callIsSmall
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
comment|/// \brief Utility to calculate the size and a few similar metrics for a set
comment|/// of basic blocks.
struct|struct
name|CodeMetrics
block|{
comment|/// \brief True if this function contains a call to setjmp or other functions
comment|/// with attribute "returns twice" without having the attribute itself.
name|bool
name|exposesReturnsTwice
decl_stmt|;
comment|/// \brief True if this function calls itself.
name|bool
name|isRecursive
decl_stmt|;
comment|/// \brief True if this function contains one or more indirect branches.
name|bool
name|containsIndirectBr
decl_stmt|;
comment|/// \brief True if this function calls alloca (in the C sense).
name|bool
name|usesDynamicAlloca
decl_stmt|;
comment|/// \brief Number of instructions in the analyzed blocks.
name|unsigned
name|NumInsts
decl_stmt|;
comment|/// \brief Number of analyzed blocks.
name|unsigned
name|NumBlocks
decl_stmt|;
comment|/// \brief Keeps track of basic block code size estimates.
name|DenseMap
operator|<
specifier|const
name|BasicBlock
operator|*
operator|,
name|unsigned
operator|>
name|NumBBInsts
expr_stmt|;
comment|/// \brief Keep track of the number of calls to 'big' functions.
name|unsigned
name|NumCalls
decl_stmt|;
comment|/// \brief The number of calls to internal functions with a single caller.
comment|///
comment|/// These are likely targets for future inlining, likely exposed by
comment|/// interleaved devirtualization.
name|unsigned
name|NumInlineCandidates
decl_stmt|;
comment|/// \brief How many instructions produce vector values.
comment|///
comment|/// The inliner is more aggressive with inlining vector kernels.
name|unsigned
name|NumVectorInsts
decl_stmt|;
comment|/// \brief How many 'ret' instructions the blocks contain.
name|unsigned
name|NumRets
decl_stmt|;
name|CodeMetrics
argument_list|()
operator|:
name|exposesReturnsTwice
argument_list|(
name|false
argument_list|)
operator|,
name|isRecursive
argument_list|(
name|false
argument_list|)
operator|,
name|containsIndirectBr
argument_list|(
name|false
argument_list|)
operator|,
name|usesDynamicAlloca
argument_list|(
name|false
argument_list|)
operator|,
name|NumInsts
argument_list|(
literal|0
argument_list|)
operator|,
name|NumBlocks
argument_list|(
literal|0
argument_list|)
operator|,
name|NumCalls
argument_list|(
literal|0
argument_list|)
operator|,
name|NumInlineCandidates
argument_list|(
literal|0
argument_list|)
operator|,
name|NumVectorInsts
argument_list|(
literal|0
argument_list|)
operator|,
name|NumRets
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// \brief Add information about a block to the current state.
name|void
name|analyzeBasicBlock
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|,
specifier|const
name|TargetData
operator|*
name|TD
operator|=
literal|0
argument_list|)
expr_stmt|;
comment|/// \brief Add information about a function to the current state.
name|void
name|analyzeFunction
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|,
specifier|const
name|TargetData
modifier|*
name|TD
init|=
literal|0
parameter_list|)
function_decl|;
block|}
struct|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

