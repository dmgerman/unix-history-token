begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------------------- SSI.h - Creates SSI Representation -----*- C++ -*-===//
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
comment|// This pass converts a list of variables to the Static Single Information
end_comment

begin_comment
comment|// form. This is a program representation described by Scott Ananian in his
end_comment

begin_comment
comment|// Master Thesis: "The Static Single Information Form (1999)".
end_comment

begin_comment
comment|// We are building an on-demand representation, that is, we do not convert
end_comment

begin_comment
comment|// every single variable in the target function to SSI form. Rather, we receive
end_comment

begin_comment
comment|// a list of target variables that must be converted. We also do not
end_comment

begin_comment
comment|// completely convert a target variable to the SSI format. Instead, we only
end_comment

begin_comment
comment|// change the variable in the points where new information can be attached
end_comment

begin_comment
comment|// to its live range, that is, at branch points.
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
name|LLVM_TRANSFORMS_UTILS_SSI_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_SSI_H
end_define

begin_include
include|#
directive|include
file|"llvm/Pass.h"
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
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DominatorTree
decl_stmt|;
name|class
name|PHINode
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|CmpInst
decl_stmt|;
name|class
name|SSI
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
comment|// Pass identification, replacement for typeid.
name|SSI
argument_list|()
operator|:
name|FunctionPass
argument_list|(
argument|&ID
argument_list|)
block|{       }
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
block|;
name|bool
name|runOnFunction
argument_list|(
name|Function
operator|&
argument_list|)
block|;
name|void
name|createSSI
argument_list|(
name|SmallVectorImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|value
argument_list|)
block|;
name|private
operator|:
comment|// Variables always live
name|DominatorTree
operator|*
name|DT_
block|;
comment|// Stores variables created by SSI
name|SmallPtrSet
operator|<
name|Instruction
operator|*
block|,
literal|16
operator|>
name|created
block|;
comment|// Phis created by SSI
name|DenseMap
operator|<
name|PHINode
operator|*
block|,
name|Instruction
operator|*
operator|>
name|phis
block|;
comment|// Sigmas created by SSI
name|DenseMap
operator|<
name|PHINode
operator|*
block|,
name|Instruction
operator|*
operator|>
name|sigmas
block|;
comment|// Phi nodes that have a phi as operand and has to be fixed
name|SmallPtrSet
operator|<
name|PHINode
operator|*
block|,
literal|1
operator|>
name|phisToFix
block|;
comment|// List of definition points for every variable
name|DenseMap
operator|<
name|Instruction
operator|*
block|,
name|SmallVector
operator|<
name|BasicBlock
operator|*
block|,
literal|4
operator|>
expr|>
name|defsites
block|;
comment|// Basic Block of the original definition of each variable
name|DenseMap
operator|<
name|Instruction
operator|*
block|,
name|BasicBlock
operator|*
operator|>
name|value_original
block|;
comment|// Stack of last seen definition of a variable
name|DenseMap
operator|<
name|Instruction
operator|*
block|,
name|SmallVector
operator|<
name|Instruction
operator|*
block|,
literal|1
operator|>
expr|>
name|value_stack
block|;
name|void
name|insertSigmaFunctions
argument_list|(
name|SmallPtrSet
operator|<
name|Instruction
operator|*
argument_list|,
literal|4
operator|>
operator|&
name|value
argument_list|)
block|;
name|void
name|insertSigma
argument_list|(
name|TerminatorInst
operator|*
name|TI
argument_list|,
name|Instruction
operator|*
name|I
argument_list|)
block|;
name|void
name|insertPhiFunctions
argument_list|(
name|SmallPtrSet
operator|<
name|Instruction
operator|*
argument_list|,
literal|4
operator|>
operator|&
name|value
argument_list|)
block|;
name|void
name|renameInit
argument_list|(
name|SmallPtrSet
operator|<
name|Instruction
operator|*
argument_list|,
literal|4
operator|>
operator|&
name|value
argument_list|)
block|;
name|void
name|rename
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
block|;
name|void
name|substituteUse
argument_list|(
name|Instruction
operator|*
name|I
argument_list|)
block|;
name|bool
name|dominateAny
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|,
name|Instruction
operator|*
name|value
argument_list|)
block|;
name|void
name|fixPhis
argument_list|()
block|;
name|Instruction
operator|*
name|getPositionPhi
argument_list|(
name|PHINode
operator|*
name|PN
argument_list|)
block|;
name|Instruction
operator|*
name|getPositionSigma
argument_list|(
name|PHINode
operator|*
name|PN
argument_list|)
block|;
name|void
name|init
argument_list|(
name|SmallVectorImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|value
argument_list|)
block|;
name|void
name|clean
argument_list|()
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

