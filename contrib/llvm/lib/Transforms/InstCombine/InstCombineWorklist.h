begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- InstCombineWorklist.h - Worklist for InstCombine pass ----*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TRANSFORMS_INSTCOMBINE_INSTCOMBINEWORKLIST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TRANSFORMS_INSTCOMBINE_INSTCOMBINEWORKLIST_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instruction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_define
define|#
directive|define
name|DEBUG_TYPE
value|"instcombine"
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// InstCombineWorklist - This is the worklist management logic for
comment|/// InstCombine.
name|class
name|LLVM_LIBRARY_VISIBILITY
name|InstCombineWorklist
block|{
name|SmallVector
operator|<
name|Instruction
operator|*
operator|,
literal|256
operator|>
name|Worklist
expr_stmt|;
name|DenseMap
operator|<
name|Instruction
operator|*
operator|,
name|unsigned
operator|>
name|WorklistMap
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|InstCombineWorklist
operator|&
name|RHS
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|InstCombineWorklist
argument_list|(
argument|const InstCombineWorklist&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|public
label|:
name|InstCombineWorklist
argument_list|()
block|{}
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|Worklist
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// Add - Add the specified instruction to the worklist if it isn't already
comment|/// in it.
name|void
name|Add
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|)
block|{
if|if
condition|(
name|WorklistMap
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|I
argument_list|,
name|Worklist
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
operator|.
name|second
condition|)
block|{
name|DEBUG
argument_list|(
name|dbgs
argument_list|()
operator|<<
literal|"IC: ADD: "
operator|<<
operator|*
name|I
operator|<<
literal|'\n'
argument_list|)
expr_stmt|;
name|Worklist
operator|.
name|push_back
argument_list|(
name|I
argument_list|)
expr_stmt|;
block|}
block|}
name|void
name|AddValue
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
block|{
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
name|V
operator|)
condition|)
name|Add
argument_list|(
name|I
argument_list|)
expr_stmt|;
block|}
comment|/// AddInitialGroup - Add the specified batch of stuff in reverse order.
comment|/// which should only be done when the worklist is empty and when the group
comment|/// has no duplicates.
name|void
name|AddInitialGroup
parameter_list|(
name|Instruction
modifier|*
specifier|const
modifier|*
name|List
parameter_list|,
name|unsigned
name|NumEntries
parameter_list|)
block|{
name|assert
argument_list|(
name|Worklist
operator|.
name|empty
argument_list|()
operator|&&
literal|"Worklist must be empty to add initial group"
argument_list|)
expr_stmt|;
name|Worklist
operator|.
name|reserve
argument_list|(
name|NumEntries
operator|+
literal|16
argument_list|)
expr_stmt|;
name|WorklistMap
operator|.
name|resize
argument_list|(
name|NumEntries
argument_list|)
expr_stmt|;
name|DEBUG
argument_list|(
name|dbgs
argument_list|()
operator|<<
literal|"IC: ADDING: "
operator|<<
name|NumEntries
operator|<<
literal|" instrs to worklist\n"
argument_list|)
expr_stmt|;
for|for
control|(
name|unsigned
name|Idx
init|=
literal|0
init|;
name|NumEntries
condition|;
operator|--
name|NumEntries
control|)
block|{
name|Instruction
modifier|*
name|I
init|=
name|List
index|[
name|NumEntries
operator|-
literal|1
index|]
decl_stmt|;
name|WorklistMap
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|I
argument_list|,
name|Idx
operator|++
argument_list|)
argument_list|)
expr_stmt|;
name|Worklist
operator|.
name|push_back
argument_list|(
name|I
argument_list|)
expr_stmt|;
block|}
block|}
comment|// Remove - remove I from the worklist if it exists.
name|void
name|Remove
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|)
block|{
name|DenseMap
operator|<
name|Instruction
operator|*
operator|,
name|unsigned
operator|>
operator|::
name|iterator
name|It
operator|=
name|WorklistMap
operator|.
name|find
argument_list|(
name|I
argument_list|)
expr_stmt|;
if|if
condition|(
name|It
operator|==
name|WorklistMap
operator|.
name|end
argument_list|()
condition|)
return|return;
comment|// Not in worklist.
comment|// Don't bother moving everything down, just null out the slot.
name|Worklist
index|[
name|It
operator|->
name|second
index|]
operator|=
name|nullptr
expr_stmt|;
name|WorklistMap
operator|.
name|erase
argument_list|(
name|It
argument_list|)
expr_stmt|;
block|}
name|Instruction
modifier|*
name|RemoveOne
parameter_list|()
block|{
name|Instruction
modifier|*
name|I
init|=
name|Worklist
operator|.
name|pop_back_val
argument_list|()
decl_stmt|;
name|WorklistMap
operator|.
name|erase
argument_list|(
name|I
argument_list|)
expr_stmt|;
return|return
name|I
return|;
block|}
comment|/// AddUsersToWorkList - When an instruction is simplified, add all users of
comment|/// the instruction to the work lists because they might get more simplified
comment|/// now.
comment|///
name|void
name|AddUsersToWorkList
parameter_list|(
name|Instruction
modifier|&
name|I
parameter_list|)
block|{
for|for
control|(
name|User
modifier|*
name|U
range|:
name|I
operator|.
name|users
argument_list|()
control|)
name|Add
argument_list|(
name|cast
operator|<
name|Instruction
operator|>
operator|(
name|U
operator|)
argument_list|)
expr_stmt|;
block|}
comment|/// Zap - check that the worklist is empty and nuke the backing store for
comment|/// the map if it is large.
name|void
name|Zap
parameter_list|()
block|{
name|assert
argument_list|(
name|WorklistMap
operator|.
name|empty
argument_list|()
operator|&&
literal|"Worklist empty, but map not?"
argument_list|)
expr_stmt|;
comment|// Do an explicit clear, this shrinks the map if needed.
name|WorklistMap
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm.
end_comment

begin_undef
undef|#
directive|undef
name|DEBUG_TYPE
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

