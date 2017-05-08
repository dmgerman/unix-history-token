begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/BasicBlock.h - Represent a basic block in the VM ---*- C++ -*-===//
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
comment|// This file contains the declaration of the BasicBlock class.
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
name|LLVM_IR_BASICBLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_BASICBLOCK_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ilist.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instruction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/SymbolTableListTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CBindingWrapping.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/Types.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CallInst
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|LandingPadInst
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|TerminatorInst
decl_stmt|;
name|class
name|ValueSymbolTable
decl_stmt|;
comment|/// \brief LLVM Basic Block Representation
comment|///
comment|/// This represents a single basic block in LLVM. A basic block is simply a
comment|/// container of instructions that execute sequentially. Basic blocks are Values
comment|/// because they are referenced by instructions such as branches and switch
comment|/// tables. The type of a BasicBlock is "Type::LabelTy" because the basic block
comment|/// represents a label to which a branch can jump.
comment|///
comment|/// A well formed basic block is formed of a list of non-terminating
comment|/// instructions followed by a single TerminatorInst instruction.
comment|/// TerminatorInst's may not occur in the middle of basic blocks, and must
comment|/// terminate the blocks. The BasicBlock class allows malformed basic blocks to
comment|/// occur because it may be useful in the intermediate stage of constructing or
comment|/// modifying a program. However, the verifier will ensure that basic blocks
comment|/// are "well formed".
name|class
name|BasicBlock
range|:
name|public
name|Value
decl_stmt|,
comment|// Basic blocks are data objects also
name|public
name|ilist_node_with_parent
decl|<
name|BasicBlock
decl_stmt|,
name|Function
decl|>
block|{
name|public
label|:
name|using
name|InstListType
init|=
name|SymbolTableList
operator|<
name|Instruction
operator|>
decl_stmt|;
name|private
label|:
name|friend
name|class
name|BlockAddress
decl_stmt|;
name|friend
name|class
name|SymbolTableListTraits
operator|<
name|BasicBlock
operator|>
expr_stmt|;
name|InstListType
name|InstList
decl_stmt|;
name|Function
modifier|*
name|Parent
decl_stmt|;
name|void
name|setParent
parameter_list|(
name|Function
modifier|*
name|parent
parameter_list|)
function_decl|;
comment|/// \brief Constructor.
comment|///
comment|/// If the function parameter is specified, the basic block is automatically
comment|/// inserted at either the end of the function (if InsertBefore is null), or
comment|/// before the specified basic block.
name|explicit
name|BasicBlock
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Name
init|=
literal|""
parameter_list|,
name|Function
modifier|*
name|Parent
init|=
name|nullptr
parameter_list|,
name|BasicBlock
modifier|*
name|InsertBefore
init|=
name|nullptr
parameter_list|)
function_decl|;
name|public
label|:
name|BasicBlock
argument_list|(
specifier|const
name|BasicBlock
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|BasicBlock
modifier|&
name|operator
init|=
operator|(
specifier|const
name|BasicBlock
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
operator|~
name|BasicBlock
argument_list|()
name|override
expr_stmt|;
comment|/// \brief Get the context in which this basic block lives.
name|LLVMContext
operator|&
name|getContext
argument_list|()
specifier|const
expr_stmt|;
comment|/// Instruction iterators...
name|using
name|iterator
init|=
name|InstListType
operator|::
name|iterator
decl_stmt|;
name|using
name|const_iterator
init|=
name|InstListType
operator|::
name|const_iterator
decl_stmt|;
name|using
name|reverse_iterator
init|=
name|InstListType
operator|::
name|reverse_iterator
decl_stmt|;
name|using
name|const_reverse_iterator
init|=
name|InstListType
operator|::
name|const_reverse_iterator
decl_stmt|;
comment|/// \brief Creates a new BasicBlock.
comment|///
comment|/// If the Parent parameter is specified, the basic block is automatically
comment|/// inserted at either the end of the function (if InsertBefore is 0), or
comment|/// before the specified basic block.
specifier|static
name|BasicBlock
modifier|*
name|Create
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Name
init|=
literal|""
parameter_list|,
name|Function
modifier|*
name|Parent
init|=
name|nullptr
parameter_list|,
name|BasicBlock
modifier|*
name|InsertBefore
init|=
name|nullptr
parameter_list|)
block|{
return|return
name|new
name|BasicBlock
argument_list|(
name|Context
argument_list|,
name|Name
argument_list|,
name|Parent
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
comment|/// \brief Return the enclosing method, or null if none.
specifier|const
name|Function
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|Parent
return|;
block|}
name|Function
modifier|*
name|getParent
parameter_list|()
block|{
return|return
name|Parent
return|;
block|}
comment|/// \brief Return the module owning the function this basic block belongs to,
comment|/// or nullptr it the function does not have a module.
comment|///
comment|/// Note: this is undefined behavior if the block does not have a parent.
specifier|const
name|Module
operator|*
name|getModule
argument_list|()
specifier|const
expr_stmt|;
name|Module
modifier|*
name|getModule
parameter_list|()
block|{
return|return
name|const_cast
operator|<
name|Module
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|BasicBlock
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getModule
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Returns the terminator instruction if the block is well formed or
comment|/// null if the block is not well formed.
specifier|const
name|TerminatorInst
operator|*
name|getTerminator
argument_list|()
specifier|const
name|LLVM_READONLY
expr_stmt|;
name|TerminatorInst
modifier|*
name|getTerminator
parameter_list|()
block|{
return|return
name|const_cast
operator|<
name|TerminatorInst
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|BasicBlock
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getTerminator
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Returns the call instruction calling @llvm.experimental.deoptimize
comment|/// prior to the terminating return instruction of this basic block, if such a
comment|/// call is present.  Otherwise, returns null.
specifier|const
name|CallInst
operator|*
name|getTerminatingDeoptimizeCall
argument_list|()
specifier|const
expr_stmt|;
name|CallInst
modifier|*
name|getTerminatingDeoptimizeCall
parameter_list|()
block|{
return|return
name|const_cast
operator|<
name|CallInst
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|BasicBlock
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getTerminatingDeoptimizeCall
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Returns the call instruction marked 'musttail' prior to the
comment|/// terminating return instruction of this basic block, if such a call is
comment|/// present.  Otherwise, returns null.
specifier|const
name|CallInst
operator|*
name|getTerminatingMustTailCall
argument_list|()
specifier|const
expr_stmt|;
name|CallInst
modifier|*
name|getTerminatingMustTailCall
parameter_list|()
block|{
return|return
name|const_cast
operator|<
name|CallInst
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|BasicBlock
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getTerminatingMustTailCall
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Returns a pointer to the first instruction in this block that is
comment|/// not a PHINode instruction.
comment|///
comment|/// When adding instructions to the beginning of the basic block, they should
comment|/// be added before the returned value, not before the first instruction,
comment|/// which might be PHI. Returns 0 is there's no non-PHI instruction.
specifier|const
name|Instruction
operator|*
name|getFirstNonPHI
argument_list|()
specifier|const
expr_stmt|;
name|Instruction
modifier|*
name|getFirstNonPHI
parameter_list|()
block|{
return|return
name|const_cast
operator|<
name|Instruction
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|BasicBlock
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getFirstNonPHI
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Returns a pointer to the first instruction in this block that is not
comment|/// a PHINode or a debug intrinsic.
specifier|const
name|Instruction
operator|*
name|getFirstNonPHIOrDbg
argument_list|()
specifier|const
expr_stmt|;
name|Instruction
modifier|*
name|getFirstNonPHIOrDbg
parameter_list|()
block|{
return|return
name|const_cast
operator|<
name|Instruction
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|BasicBlock
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getFirstNonPHIOrDbg
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Returns a pointer to the first instruction in this block that is not
comment|/// a PHINode, a debug intrinsic, or a lifetime intrinsic.
specifier|const
name|Instruction
operator|*
name|getFirstNonPHIOrDbgOrLifetime
argument_list|()
specifier|const
expr_stmt|;
name|Instruction
modifier|*
name|getFirstNonPHIOrDbgOrLifetime
parameter_list|()
block|{
return|return
name|const_cast
operator|<
name|Instruction
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|BasicBlock
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getFirstNonPHIOrDbgOrLifetime
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Returns an iterator to the first instruction in this block that is
comment|/// suitable for inserting a non-PHI instruction.
comment|///
comment|/// In particular, it skips all PHIs and LandingPad instructions.
name|const_iterator
name|getFirstInsertionPt
argument_list|()
specifier|const
expr_stmt|;
name|iterator
name|getFirstInsertionPt
parameter_list|()
block|{
return|return
name|static_cast
operator|<
specifier|const
name|BasicBlock
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getFirstInsertionPt
argument_list|()
operator|.
name|getNonConst
argument_list|()
return|;
block|}
comment|/// \brief Unlink 'this' from the containing function, but do not delete it.
name|void
name|removeFromParent
parameter_list|()
function_decl|;
comment|/// \brief Unlink 'this' from the containing function and delete it.
comment|///
comment|// \returns an iterator pointing to the element after the erased one.
name|SymbolTableList
operator|<
name|BasicBlock
operator|>
operator|::
name|iterator
name|eraseFromParent
argument_list|()
expr_stmt|;
comment|/// \brief Unlink this basic block from its current function and insert it
comment|/// into the function that \p MovePos lives in, right before \p MovePos.
name|void
name|moveBefore
parameter_list|(
name|BasicBlock
modifier|*
name|MovePos
parameter_list|)
function_decl|;
comment|/// \brief Unlink this basic block from its current function and insert it
comment|/// right after \p MovePos in the function \p MovePos lives in.
name|void
name|moveAfter
parameter_list|(
name|BasicBlock
modifier|*
name|MovePos
parameter_list|)
function_decl|;
comment|/// \brief Insert unlinked basic block into a function.
comment|///
comment|/// Inserts an unlinked basic block into \c Parent.  If \c InsertBefore is
comment|/// provided, inserts before that basic block, otherwise inserts at the end.
comment|///
comment|/// \pre \a getParent() is \c nullptr.
name|void
name|insertInto
parameter_list|(
name|Function
modifier|*
name|Parent
parameter_list|,
name|BasicBlock
modifier|*
name|InsertBefore
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// \brief Return the predecessor of this block if it has a single predecessor
comment|/// block. Otherwise return a null pointer.
specifier|const
name|BasicBlock
operator|*
name|getSinglePredecessor
argument_list|()
specifier|const
expr_stmt|;
name|BasicBlock
modifier|*
name|getSinglePredecessor
parameter_list|()
block|{
return|return
name|const_cast
operator|<
name|BasicBlock
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|BasicBlock
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getSinglePredecessor
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Return the predecessor of this block if it has a unique predecessor
comment|/// block. Otherwise return a null pointer.
comment|///
comment|/// Note that unique predecessor doesn't mean single edge, there can be
comment|/// multiple edges from the unique predecessor to this block (for example a
comment|/// switch statement with multiple cases having the same destination).
specifier|const
name|BasicBlock
operator|*
name|getUniquePredecessor
argument_list|()
specifier|const
expr_stmt|;
name|BasicBlock
modifier|*
name|getUniquePredecessor
parameter_list|()
block|{
return|return
name|const_cast
operator|<
name|BasicBlock
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|BasicBlock
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getUniquePredecessor
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Return the successor of this block if it has a single successor.
comment|/// Otherwise return a null pointer.
comment|///
comment|/// This method is analogous to getSinglePredecessor above.
specifier|const
name|BasicBlock
operator|*
name|getSingleSuccessor
argument_list|()
specifier|const
expr_stmt|;
name|BasicBlock
modifier|*
name|getSingleSuccessor
parameter_list|()
block|{
return|return
name|const_cast
operator|<
name|BasicBlock
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|BasicBlock
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getSingleSuccessor
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Return the successor of this block if it has a unique successor.
comment|/// Otherwise return a null pointer.
comment|///
comment|/// This method is analogous to getUniquePredecessor above.
specifier|const
name|BasicBlock
operator|*
name|getUniqueSuccessor
argument_list|()
specifier|const
expr_stmt|;
name|BasicBlock
modifier|*
name|getUniqueSuccessor
parameter_list|()
block|{
return|return
name|const_cast
operator|<
name|BasicBlock
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|BasicBlock
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getUniqueSuccessor
argument_list|()
operator|)
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|/// Instruction iterator methods
comment|///
specifier|inline
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|InstList
operator|.
name|begin
argument_list|()
return|;
block|}
specifier|inline
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|InstList
operator|.
name|begin
argument_list|()
return|;
block|}
specifier|inline
name|iterator
name|end
parameter_list|()
block|{
return|return
name|InstList
operator|.
name|end
argument_list|()
return|;
block|}
specifier|inline
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|InstList
operator|.
name|end
argument_list|()
return|;
block|}
specifier|inline
name|reverse_iterator
name|rbegin
parameter_list|()
block|{
return|return
name|InstList
operator|.
name|rbegin
argument_list|()
return|;
block|}
specifier|inline
name|const_reverse_iterator
name|rbegin
argument_list|()
specifier|const
block|{
return|return
name|InstList
operator|.
name|rbegin
argument_list|()
return|;
block|}
specifier|inline
name|reverse_iterator
name|rend
parameter_list|()
block|{
return|return
name|InstList
operator|.
name|rend
argument_list|()
return|;
block|}
specifier|inline
name|const_reverse_iterator
name|rend
argument_list|()
specifier|const
block|{
return|return
name|InstList
operator|.
name|rend
argument_list|()
return|;
block|}
specifier|inline
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|InstList
operator|.
name|size
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|InstList
operator|.
name|empty
argument_list|()
return|;
block|}
specifier|inline
specifier|const
name|Instruction
operator|&
name|front
argument_list|()
specifier|const
block|{
return|return
name|InstList
operator|.
name|front
argument_list|()
return|;
block|}
specifier|inline
name|Instruction
modifier|&
name|front
parameter_list|()
block|{
return|return
name|InstList
operator|.
name|front
argument_list|()
return|;
block|}
specifier|inline
specifier|const
name|Instruction
operator|&
name|back
argument_list|()
specifier|const
block|{
return|return
name|InstList
operator|.
name|back
argument_list|()
return|;
block|}
specifier|inline
name|Instruction
modifier|&
name|back
parameter_list|()
block|{
return|return
name|InstList
operator|.
name|back
argument_list|()
return|;
block|}
comment|/// \brief Return the underlying instruction list container.
comment|///
comment|/// Currently you need to access the underlying instruction list container
comment|/// directly if you want to modify it.
specifier|const
name|InstListType
operator|&
name|getInstList
argument_list|()
specifier|const
block|{
return|return
name|InstList
return|;
block|}
name|InstListType
modifier|&
name|getInstList
parameter_list|()
block|{
return|return
name|InstList
return|;
block|}
comment|/// \brief Returns a pointer to a member of the instruction list.
specifier|static
name|InstListType
name|BasicBlock
operator|::
operator|*
name|getSublistAccess
argument_list|(
argument|Instruction*
argument_list|)
block|{
return|return
operator|&
name|BasicBlock
operator|::
name|InstList
return|;
block|}
comment|/// \brief Returns a pointer to the symbol table if one exists.
name|ValueSymbolTable
modifier|*
name|getValueSymbolTable
parameter_list|()
function_decl|;
comment|/// \brief Methods for support type inquiry through isa, cast, and dyn_cast.
specifier|static
specifier|inline
name|bool
name|classof
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|Value
operator|::
name|BasicBlockVal
return|;
block|}
comment|/// \brief Cause all subinstructions to "let go" of all the references that
comment|/// said subinstructions are maintaining.
comment|///
comment|/// This allows one to 'delete' a whole class at a time, even though there may
comment|/// be circular references... first all references are dropped, and all use
comment|/// counts go to zero.  Then everything is delete'd for real.  Note that no
comment|/// operations are valid on an object that has "dropped all references",
comment|/// except operator delete.
name|void
name|dropAllReferences
parameter_list|()
function_decl|;
comment|/// \brief Notify the BasicBlock that the predecessor \p Pred is no longer
comment|/// able to reach it.
comment|///
comment|/// This is actually not used to update the Predecessor list, but is actually
comment|/// used to update the PHI nodes that reside in the block.  Note that this
comment|/// should be called while the predecessor still refers to this block.
name|void
name|removePredecessor
parameter_list|(
name|BasicBlock
modifier|*
name|Pred
parameter_list|,
name|bool
name|DontDeleteUselessPHIs
init|=
name|false
parameter_list|)
function_decl|;
name|bool
name|canSplitPredecessors
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Split the basic block into two basic blocks at the specified
comment|/// instruction.
comment|///
comment|/// Note that all instructions BEFORE the specified iterator stay as part of
comment|/// the original basic block, an unconditional branch is added to the original
comment|/// BB, and the rest of the instructions in the BB are moved to the new BB,
comment|/// including the old terminator.  The newly formed BasicBlock is returned.
comment|/// This function invalidates the specified iterator.
comment|///
comment|/// Note that this only works on well formed basic blocks (must have a
comment|/// terminator), and 'I' must not be the end of instruction list (which would
comment|/// cause a degenerate basic block to be formed, having a terminator inside of
comment|/// the basic block).
comment|///
comment|/// Also note that this doesn't preserve any passes. To split blocks while
comment|/// keeping loop information consistent, use the SplitBlock utility function.
name|BasicBlock
modifier|*
name|splitBasicBlock
parameter_list|(
name|iterator
name|I
parameter_list|,
specifier|const
name|Twine
modifier|&
name|BBName
init|=
literal|""
parameter_list|)
function_decl|;
name|BasicBlock
modifier|*
name|splitBasicBlock
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|,
specifier|const
name|Twine
modifier|&
name|BBName
init|=
literal|""
parameter_list|)
block|{
return|return
name|splitBasicBlock
argument_list|(
name|I
operator|->
name|getIterator
argument_list|()
argument_list|,
name|BBName
argument_list|)
return|;
block|}
comment|/// \brief Returns true if there are any uses of this basic block other than
comment|/// direct branches, switches, etc. to it.
name|bool
name|hasAddressTaken
argument_list|()
specifier|const
block|{
return|return
name|getSubclassDataFromValue
argument_list|()
operator|!=
literal|0
return|;
block|}
comment|/// \brief Update all phi nodes in this basic block's successors to refer to
comment|/// basic block \p New instead of to it.
name|void
name|replaceSuccessorsPhiUsesWith
parameter_list|(
name|BasicBlock
modifier|*
name|New
parameter_list|)
function_decl|;
comment|/// \brief Return true if this basic block is an exception handling block.
name|bool
name|isEHPad
argument_list|()
specifier|const
block|{
return|return
name|getFirstNonPHI
argument_list|()
operator|->
name|isEHPad
argument_list|()
return|;
block|}
comment|/// \brief Return true if this basic block is a landing pad.
comment|///
comment|/// Being a ``landing pad'' means that the basic block is the destination of
comment|/// the 'unwind' edge of an invoke instruction.
name|bool
name|isLandingPad
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return the landingpad instruction associated with the landing pad.
specifier|const
name|LandingPadInst
operator|*
name|getLandingPadInst
argument_list|()
specifier|const
expr_stmt|;
name|LandingPadInst
modifier|*
name|getLandingPadInst
parameter_list|()
block|{
return|return
name|const_cast
operator|<
name|LandingPadInst
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|BasicBlock
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getLandingPadInst
argument_list|()
operator|)
return|;
block|}
name|private
label|:
comment|/// \brief Increment the internal refcount of the number of BlockAddresses
comment|/// referencing this BasicBlock by \p Amt.
comment|///
comment|/// This is almost always 0, sometimes one possibly, but almost never 2, and
comment|/// inconceivably 3 or more.
name|void
name|AdjustBlockAddressRefCount
parameter_list|(
name|int
name|Amt
parameter_list|)
block|{
name|setValueSubclassData
argument_list|(
name|getSubclassDataFromValue
argument_list|()
operator|+
name|Amt
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|int
operator|)
operator|(
name|signed
name|char
operator|)
name|getSubclassDataFromValue
argument_list|()
operator|>=
literal|0
operator|&&
literal|"Refcount wrap-around"
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Shadow Value::setValueSubclassData with a private forwarding method
comment|/// so that any future subclasses cannot accidentally use it.
name|void
name|setValueSubclassData
parameter_list|(
name|unsigned
name|short
name|D
parameter_list|)
block|{
name|Value
operator|::
name|setValueSubclassData
argument_list|(
name|D
argument_list|)
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|// Create wrappers for C Binding types (see CBindingWrapping.h).
name|DEFINE_SIMPLE_CONVERSION_FUNCTIONS
argument_list|(
argument|BasicBlock
argument_list|,
argument|LLVMBasicBlockRef
argument_list|)
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_BASICBLOCK_H
end_comment

end_unit

