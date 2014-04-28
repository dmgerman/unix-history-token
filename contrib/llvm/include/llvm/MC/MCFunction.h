begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCFunction.h ------------------------------------*- C++ -*-===//
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
comment|// This file defines the data structures to hold a CFG reconstructed from
end_comment

begin_comment
comment|// machine code.
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
name|LLVM_MC_MCFUNCTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCFUNCTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCInst.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCFunction
decl_stmt|;
name|class
name|MCModule
decl_stmt|;
name|class
name|MCTextAtom
decl_stmt|;
comment|/// \brief Basic block containing a sequence of disassembled instructions.
comment|/// The basic block is backed by an MCTextAtom, which holds the instructions,
comment|/// and the address range it covers.
comment|/// Create a basic block using MCFunction::createBlock.
name|class
name|MCBasicBlock
block|{
specifier|const
name|MCTextAtom
modifier|*
name|Insts
decl_stmt|;
comment|// MCFunction owns the basic block.
name|MCFunction
modifier|*
name|Parent
decl_stmt|;
name|friend
name|class
name|MCFunction
decl_stmt|;
name|MCBasicBlock
argument_list|(
specifier|const
name|MCTextAtom
operator|&
name|Insts
argument_list|,
name|MCFunction
operator|*
name|Parent
argument_list|)
expr_stmt|;
comment|/// \name Predecessors/Successors, to represent the CFG.
comment|/// @{
typedef|typedef
name|std
operator|::
name|vector
operator|<
specifier|const
name|MCBasicBlock
operator|*
operator|>
name|BasicBlockListTy
expr_stmt|;
name|BasicBlockListTy
name|Successors
decl_stmt|;
name|BasicBlockListTy
name|Predecessors
decl_stmt|;
comment|/// @}
name|public
label|:
comment|/// \brief Get the backing MCTextAtom, containing the instruction sequence.
specifier|const
name|MCTextAtom
operator|*
name|getInsts
argument_list|()
specifier|const
block|{
return|return
name|Insts
return|;
block|}
comment|/// \name Get the owning MCFunction.
comment|/// @{
specifier|const
name|MCFunction
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|Parent
return|;
block|}
name|MCFunction
modifier|*
name|getParent
parameter_list|()
block|{
return|return
name|Parent
return|;
block|}
comment|/// @}
comment|/// MC CFG access: Predecessors/Successors.
comment|/// @{
typedef|typedef
name|BasicBlockListTy
operator|::
name|const_iterator
name|succ_const_iterator
expr_stmt|;
name|succ_const_iterator
name|succ_begin
argument_list|()
specifier|const
block|{
return|return
name|Successors
operator|.
name|begin
argument_list|()
return|;
block|}
name|succ_const_iterator
name|succ_end
argument_list|()
specifier|const
block|{
return|return
name|Successors
operator|.
name|end
argument_list|()
return|;
block|}
typedef|typedef
name|BasicBlockListTy
operator|::
name|const_iterator
name|pred_const_iterator
expr_stmt|;
name|pred_const_iterator
name|pred_begin
argument_list|()
specifier|const
block|{
return|return
name|Predecessors
operator|.
name|begin
argument_list|()
return|;
block|}
name|pred_const_iterator
name|pred_end
argument_list|()
specifier|const
block|{
return|return
name|Predecessors
operator|.
name|end
argument_list|()
return|;
block|}
name|void
name|addSuccessor
parameter_list|(
specifier|const
name|MCBasicBlock
modifier|*
name|MCBB
parameter_list|)
function_decl|;
name|bool
name|isSuccessor
argument_list|(
specifier|const
name|MCBasicBlock
operator|*
name|MCBB
argument_list|)
decl|const
decl_stmt|;
name|void
name|addPredecessor
parameter_list|(
specifier|const
name|MCBasicBlock
modifier|*
name|MCBB
parameter_list|)
function_decl|;
name|bool
name|isPredecessor
argument_list|(
specifier|const
name|MCBasicBlock
operator|*
name|MCBB
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Split block, mirrorring NewAtom = Insts->split(..).
comment|/// This moves all successors to \p SplitBB, and
comment|/// adds a fallthrough to it.
comment|/// \p SplitBB The result of splitting Insts, a basic block directly following
comment|/// this basic block.
name|void
name|splitBasicBlock
parameter_list|(
name|MCBasicBlock
modifier|*
name|SplitBB
parameter_list|)
function_decl|;
comment|/// @}
block|}
empty_stmt|;
comment|/// \brief Represents a function in machine code, containing MCBasicBlocks.
comment|/// MCFunctions are created by MCModule.
name|class
name|MCFunction
block|{
name|MCFunction
argument_list|(
argument|const MCFunction&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|MCFunction
modifier|&
name|operator
init|=
operator|(
specifier|const
name|MCFunction
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|std
operator|::
name|string
name|Name
expr_stmt|;
name|MCModule
modifier|*
name|ParentModule
decl_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|MCBasicBlock
operator|*
operator|>
name|BasicBlockListTy
expr_stmt|;
name|BasicBlockListTy
name|Blocks
decl_stmt|;
comment|// MCModule owns the function.
name|friend
name|class
name|MCModule
decl_stmt|;
name|MCFunction
argument_list|(
argument|StringRef Name
argument_list|,
argument|MCModule *Parent
argument_list|)
empty_stmt|;
operator|~
name|MCFunction
argument_list|()
expr_stmt|;
name|public
label|:
comment|/// \brief Create an MCBasicBlock backed by Insts and add it to this function.
comment|/// \param Insts Sequence of straight-line code backing the basic block.
comment|/// \returns The newly created basic block.
name|MCBasicBlock
modifier|&
name|createBlock
parameter_list|(
specifier|const
name|MCTextAtom
modifier|&
name|Insts
parameter_list|)
function_decl|;
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
comment|/// \name Get the owning MC Module.
comment|/// @{
specifier|const
name|MCModule
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|ParentModule
return|;
block|}
name|MCModule
modifier|*
name|getParent
parameter_list|()
block|{
return|return
name|ParentModule
return|;
block|}
comment|/// @}
comment|/// \name Access to the function's basic blocks. No ordering is enforced,
comment|/// except that the first block is the entry block.
comment|/// @{
comment|/// \brief Get the entry point basic block.
specifier|const
name|MCBasicBlock
operator|*
name|getEntryBlock
argument_list|()
specifier|const
block|{
return|return
name|front
argument_list|()
return|;
block|}
name|MCBasicBlock
modifier|*
name|getEntryBlock
parameter_list|()
block|{
return|return
name|front
argument_list|()
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Blocks
operator|.
name|empty
argument_list|()
return|;
block|}
typedef|typedef
name|BasicBlockListTy
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
typedef|typedef
name|BasicBlockListTy
operator|::
name|iterator
name|iterator
expr_stmt|;
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Blocks
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|Blocks
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
name|Blocks
operator|.
name|end
argument_list|()
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
return|return
name|Blocks
operator|.
name|end
argument_list|()
return|;
block|}
specifier|const
name|MCBasicBlock
operator|*
name|front
argument_list|()
specifier|const
block|{
return|return
name|Blocks
operator|.
name|front
argument_list|()
return|;
block|}
name|MCBasicBlock
modifier|*
name|front
parameter_list|()
block|{
return|return
name|Blocks
operator|.
name|front
argument_list|()
return|;
block|}
specifier|const
name|MCBasicBlock
operator|*
name|back
argument_list|()
specifier|const
block|{
return|return
name|Blocks
operator|.
name|back
argument_list|()
return|;
block|}
name|MCBasicBlock
modifier|*
name|back
parameter_list|()
block|{
return|return
name|Blocks
operator|.
name|back
argument_list|()
return|;
block|}
comment|/// \brief Find the basic block, if any, that starts at \p StartAddr.
specifier|const
name|MCBasicBlock
modifier|*
name|find
argument_list|(
name|uint64_t
name|StartAddr
argument_list|)
decl|const
decl_stmt|;
name|MCBasicBlock
modifier|*
name|find
parameter_list|(
name|uint64_t
name|StartAddr
parameter_list|)
function_decl|;
comment|/// @}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

