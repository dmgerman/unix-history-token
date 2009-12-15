begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PHITransAddr.h - PHI Translation for Addresses -----------*- C++ -*-===//
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
comment|// This file declares the PHITransAddr class.
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
name|LLVM_ANALYSIS_PHITRANSADDR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_PHITRANSADDR_H
end_define

begin_include
include|#
directive|include
file|"llvm/Instruction.h"
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
name|TargetData
decl_stmt|;
comment|/// PHITransAddr - An address value which tracks and handles phi translation.
comment|/// As we walk "up" the CFG through predecessors, we need to ensure that the
comment|/// address we're tracking is kept up to date.  For example, if we're analyzing
comment|/// an address of "&A[i]" and walk through the definition of 'i' which is a PHI
comment|/// node, we *must* phi translate i to get "&A[j]" or else we will analyze an
comment|/// incorrect pointer in the predecessor block.
comment|///
comment|/// This is designed to be a relatively small object that lives on the stack and
comment|/// is copyable.
comment|///
name|class
name|PHITransAddr
block|{
comment|/// Addr - The actual address we're analyzing.
name|Value
modifier|*
name|Addr
decl_stmt|;
comment|/// TD - The target data we are playing with if known, otherwise null.
specifier|const
name|TargetData
modifier|*
name|TD
decl_stmt|;
comment|/// InstInputs - The inputs for our symbolic address.
name|SmallVector
operator|<
name|Instruction
operator|*
operator|,
literal|4
operator|>
name|InstInputs
expr_stmt|;
name|public
label|:
name|PHITransAddr
argument_list|(
name|Value
operator|*
name|addr
argument_list|,
specifier|const
name|TargetData
operator|*
name|td
argument_list|)
operator|:
name|Addr
argument_list|(
name|addr
argument_list|)
operator|,
name|TD
argument_list|(
argument|td
argument_list|)
block|{
comment|// If the address is an instruction, the whole thing is considered an input.
if|if
condition|(
name|Instruction
modifier|*
name|I
init|=
name|dyn_cast
operator|<
name|Instruction
operator|>
operator|(
name|Addr
operator|)
condition|)
name|InstInputs
operator|.
name|push_back
argument_list|(
name|I
argument_list|)
expr_stmt|;
block|}
name|Value
operator|*
name|getAddr
argument_list|()
specifier|const
block|{
return|return
name|Addr
return|;
block|}
comment|/// NeedsPHITranslationFromBlock - Return true if moving from the specified
comment|/// BasicBlock to its predecessors requires PHI translation.
name|bool
name|NeedsPHITranslationFromBlock
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
block|{
comment|// We do need translation if one of our input instructions is defined in
comment|// this block.
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|InstInputs
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|InstInputs
index|[
name|i
index|]
operator|->
name|getParent
argument_list|()
operator|==
name|BB
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
comment|/// IsPotentiallyPHITranslatable - If this needs PHI translation, return true
comment|/// if we have some hope of doing it.  This should be used as a filter to
comment|/// avoid calling PHITranslateValue in hopeless situations.
name|bool
name|IsPotentiallyPHITranslatable
argument_list|()
specifier|const
expr_stmt|;
comment|/// PHITranslateValue - PHI translate the current address up the CFG from
comment|/// CurBB to Pred, updating our state the reflect any needed changes.  This
comment|/// returns true on failure and sets Addr to null.
name|bool
name|PHITranslateValue
parameter_list|(
name|BasicBlock
modifier|*
name|CurBB
parameter_list|,
name|BasicBlock
modifier|*
name|PredBB
parameter_list|)
function_decl|;
comment|/// PHITranslateWithInsertion - PHI translate this value into the specified
comment|/// predecessor block, inserting a computation of the value if it is
comment|/// unavailable.
comment|///
comment|/// All newly created instructions are added to the NewInsts list.  This
comment|/// returns null on failure.
comment|///
name|Value
modifier|*
name|PHITranslateWithInsertion
argument_list|(
name|BasicBlock
operator|*
name|CurBB
argument_list|,
name|BasicBlock
operator|*
name|PredBB
argument_list|,
specifier|const
name|DominatorTree
operator|&
name|DT
argument_list|,
name|SmallVectorImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|NewInsts
argument_list|)
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|/// Verify - Check internal consistency of this data structure.  If the
comment|/// structure is valid, it returns true.  If invalid, it prints errors and
comment|/// returns false.
name|bool
name|Verify
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|Value
modifier|*
name|PHITranslateSubExpr
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
name|BasicBlock
modifier|*
name|CurBB
parameter_list|,
name|BasicBlock
modifier|*
name|PredBB
parameter_list|)
function_decl|;
comment|/// GetAvailablePHITranslatedSubExpr - Return the value computed by
comment|/// PHITranslateSubExpr if it dominates PredBB, otherwise return null.
name|Value
modifier|*
name|GetAvailablePHITranslatedSubExpr
argument_list|(
name|Value
operator|*
name|V
argument_list|,
name|BasicBlock
operator|*
name|CurBB
argument_list|,
name|BasicBlock
operator|*
name|PredBB
argument_list|,
specifier|const
name|DominatorTree
operator|&
name|DT
argument_list|)
decl|const
decl_stmt|;
comment|/// InsertPHITranslatedSubExpr - Insert a computation of the PHI translated
comment|/// version of 'V' for the edge PredBB->CurBB into the end of the PredBB
comment|/// block.  All newly created instructions are added to the NewInsts list.
comment|/// This returns null on failure.
comment|///
name|Value
modifier|*
name|InsertPHITranslatedSubExpr
argument_list|(
name|Value
operator|*
name|InVal
argument_list|,
name|BasicBlock
operator|*
name|CurBB
argument_list|,
name|BasicBlock
operator|*
name|PredBB
argument_list|,
specifier|const
name|DominatorTree
operator|&
name|DT
argument_list|,
name|SmallVectorImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|NewInsts
argument_list|)
decl_stmt|;
comment|/// AddAsInput - If the specified value is an instruction, add it as an input.
name|Value
modifier|*
name|AddAsInput
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
block|{
comment|// If V is an instruction, it is now an input.
if|if
condition|(
name|Instruction
modifier|*
name|VI
init|=
name|dyn_cast
operator|<
name|Instruction
operator|>
operator|(
name|V
operator|)
condition|)
name|InstInputs
operator|.
name|push_back
argument_list|(
name|VI
argument_list|)
expr_stmt|;
return|return
name|V
return|;
block|}
block|}
empty_stmt|;
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

