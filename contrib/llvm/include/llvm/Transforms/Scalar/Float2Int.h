begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Float2Int.h - Demote floating point ops to work on integers -------===//
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
comment|// This file provides the Float2Int pass, which aims to demote floating
end_comment

begin_comment
comment|// point operations to work on integers, where that is losslessly possible.
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
name|LLVM_TRANSFORMS_SCALAR_FLOAT2INT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_FLOAT2INT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/EquivalenceClasses.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/MapVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ConstantRange.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
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
name|Float2IntPass
range|:
name|public
name|PassInfoMixin
operator|<
name|Float2IntPass
operator|>
block|{
name|public
operator|:
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
comment|// Glue for old PM.
name|bool
name|runImpl
argument_list|(
name|Function
operator|&
name|F
argument_list|)
block|;
name|private
operator|:
name|void
name|findRoots
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|SmallPtrSet
operator|<
name|Instruction
operator|*
argument_list|,
literal|8
operator|>
operator|&
name|Roots
argument_list|)
block|;
name|void
name|seen
argument_list|(
argument|Instruction *I
argument_list|,
argument|ConstantRange R
argument_list|)
block|;
name|ConstantRange
name|badRange
argument_list|()
block|;
name|ConstantRange
name|unknownRange
argument_list|()
block|;
name|ConstantRange
name|validateRange
argument_list|(
argument|ConstantRange R
argument_list|)
block|;
name|void
name|walkBackwards
argument_list|(
specifier|const
name|SmallPtrSetImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|Roots
argument_list|)
block|;
name|void
name|walkForwards
argument_list|()
block|;
name|bool
name|validateAndTransform
argument_list|()
block|;
name|Value
operator|*
name|convert
argument_list|(
name|Instruction
operator|*
name|I
argument_list|,
name|Type
operator|*
name|ToTy
argument_list|)
block|;
name|void
name|cleanup
argument_list|()
block|;
name|MapVector
operator|<
name|Instruction
operator|*
block|,
name|ConstantRange
operator|>
name|SeenInsts
block|;
name|SmallPtrSet
operator|<
name|Instruction
operator|*
block|,
literal|8
operator|>
name|Roots
block|;
name|EquivalenceClasses
operator|<
name|Instruction
operator|*
operator|>
name|ECs
block|;
name|MapVector
operator|<
name|Instruction
operator|*
block|,
name|Value
operator|*
operator|>
name|ConvertedInsts
block|;
name|LLVMContext
operator|*
name|Ctx
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_SCALAR_FLOAT2INT_H
end_comment

end_unit

