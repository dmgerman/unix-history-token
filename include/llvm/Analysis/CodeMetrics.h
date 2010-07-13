begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CodeMetrics.h - Measures the weight of a function---------*- C++ -*-===//
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
comment|// This file implements various weight measurements for a function, helping
end_comment

begin_comment
comment|// the Inliner and PartialSpecialization decide whether to duplicate its
end_comment

begin_comment
comment|// contents.
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

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// CodeMetrics - Calculate size and a few similar metrics for a set of
comment|// basic blocks.
struct|struct
name|CodeMetrics
block|{
comment|/// NeverInline - True if this callee should never be inlined into a
comment|/// caller.
comment|// bool NeverInline;
comment|// True if this function contains a call to setjmp or _setjmp
name|bool
name|callsSetJmp
decl_stmt|;
comment|// True if this function calls itself
name|bool
name|isRecursive
decl_stmt|;
comment|// True if this function contains one or more indirect branches
name|bool
name|containsIndirectBr
decl_stmt|;
comment|/// usesDynamicAlloca - True if this function calls alloca (in the C sense).
name|bool
name|usesDynamicAlloca
decl_stmt|;
comment|/// NumInsts, NumBlocks - Keep track of how large each function is, which
comment|/// is used to estimate the code size cost of inlining it.
name|unsigned
name|NumInsts
decl_stmt|,
name|NumBlocks
decl_stmt|;
comment|/// NumBBInsts - Keeps track of basic block code size estimates.
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
comment|/// NumCalls - Keep track of the number of calls to 'big' functions.
name|unsigned
name|NumCalls
decl_stmt|;
comment|/// NumVectorInsts - Keep track of how many instructions produce vector
comment|/// values.  The inliner is being more aggressive with inlining vector
comment|/// kernels.
name|unsigned
name|NumVectorInsts
decl_stmt|;
comment|/// NumRets - Keep track of how many Ret instructions the block contains.
name|unsigned
name|NumRets
decl_stmt|;
name|CodeMetrics
argument_list|()
operator|:
name|callsSetJmp
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
comment|/// analyzeBasicBlock - Add information about the specified basic block
comment|/// to the current structure.
name|void
name|analyzeBasicBlock
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
expr_stmt|;
comment|/// analyzeFunction - Add information about the specified function
comment|/// to the current structure.
name|void
name|analyzeFunction
parameter_list|(
name|Function
modifier|*
name|F
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

