begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/DivergenceAnalysis.h - Divergence Analysis -*- C++ -*-===//
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
comment|// The divergence analysis is an LLVM pass which can be used to find out
end_comment

begin_comment
comment|// if a branch instruction in a GPU program is divergent or not. It can help
end_comment

begin_comment
comment|// branch optimizations such as jump threading and loop unswitching to make
end_comment

begin_comment
comment|// better decisions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

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
name|Value
decl_stmt|;
name|class
name|DivergenceAnalysis
range|:
name|public
name|FunctionPass
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|DivergenceAnalysis
argument_list|()
operator|:
name|FunctionPass
argument_list|(
argument|ID
argument_list|)
block|{
name|initializeDivergenceAnalysisPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;   }
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
name|bool
name|runOnFunction
argument_list|(
argument|Function&F
argument_list|)
name|override
block|;
comment|// Print all divergent branches in the function.
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const Module *
argument_list|)
specifier|const
name|override
block|;
comment|// Returns true if V is divergent.
name|bool
name|isDivergent
argument_list|(
argument|const Value *V
argument_list|)
specifier|const
block|{
return|return
name|DivergentValues
operator|.
name|count
argument_list|(
name|V
argument_list|)
return|;
block|}
comment|// Returns true if V is uniform/non-divergent.
name|bool
name|isUniform
argument_list|(
argument|const Value *V
argument_list|)
specifier|const
block|{
return|return
operator|!
name|isDivergent
argument_list|(
name|V
argument_list|)
return|;
block|}
name|private
operator|:
comment|// Stores all divergent values.
name|DenseSet
operator|<
specifier|const
name|Value
operator|*
operator|>
name|DivergentValues
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

end_unit

