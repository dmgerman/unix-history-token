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
name|LLVM_BASICBLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_BASICBLOCK_H
end_define

begin_include
include|#
directive|include
file|"llvm/Instruction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/SymbolTableListTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|TerminatorInst
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|BlockAddress
decl_stmt|;
name|template
operator|<
operator|>
expr|struct
name|ilist_traits
operator|<
name|Instruction
operator|>
operator|:
name|public
name|SymbolTableListTraits
operator|<
name|Instruction
operator|,
name|BasicBlock
operator|>
block|{
comment|// createSentinel is used to get hold of a node that marks the end of
comment|// the list...
comment|// The sentinel is relative to this instance, so we use a non-static
comment|// method.
name|Instruction
operator|*
name|createSentinel
argument_list|()
specifier|const
block|{
comment|// since i(p)lists always publicly derive from the corresponding
comment|// traits, placing a data member in this class will augment i(p)list.
comment|// But since the NodeTy is expected to publicly derive from
comment|// ilist_node<NodeTy>, there is a legal viable downcast from it
comment|// to NodeTy. We use this trick to superpose i(p)list with a "ghostly"
comment|// NodeTy, which becomes the sentinel. Dereferencing the sentinel is
comment|// forbidden (save the ilist_node<NodeTy>) so no one will ever notice
comment|// the superposition.
return|return
name|static_cast
operator|<
name|Instruction
operator|*
operator|>
operator|(
operator|&
name|Sentinel
operator|)
return|;
block|}
specifier|static
name|void
name|destroySentinel
argument_list|(
argument|Instruction*
argument_list|)
block|{}
name|Instruction
operator|*
name|provideInitialHead
argument_list|()
specifier|const
block|{
return|return
name|createSentinel
argument_list|()
return|;
block|}
name|Instruction
operator|*
name|ensureHead
argument_list|(
argument|Instruction*
argument_list|)
specifier|const
block|{
return|return
name|createSentinel
argument_list|()
return|;
block|}
specifier|static
name|void
name|noteHead
argument_list|(
argument|Instruction*
argument_list|,
argument|Instruction*
argument_list|)
block|{}
name|private
operator|:
name|mutable
name|ilist_half_node
operator|<
name|Instruction
operator|>
name|Sentinel
block|; }
expr_stmt|;
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
comment|/// @brief LLVM Basic Block Representation
name|class
name|BasicBlock
range|:
name|public
name|Value
decl_stmt|,
comment|// Basic blocks are data objects also
name|public
name|ilist_node
decl|<
name|BasicBlock
decl|>
block|{
name|friend
name|class
name|BlockAddress
decl_stmt|;
name|public
label|:
typedef|typedef
name|iplist
operator|<
name|Instruction
operator|>
name|InstListType
expr_stmt|;
name|private
label|:
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
name|friend
name|class
name|SymbolTableListTraits
operator|<
name|BasicBlock
operator|,
name|Function
operator|>
expr_stmt|;
name|BasicBlock
argument_list|(
specifier|const
name|BasicBlock
operator|&
argument_list|)
expr_stmt|;
comment|// Do not implement
name|void
name|operator
init|=
operator|(
specifier|const
name|BasicBlock
operator|&
operator|)
decl_stmt|;
comment|// Do not implement
comment|/// BasicBlock ctor - If the function parameter is specified, the basic block
comment|/// is automatically inserted at either the end of the function (if
comment|/// InsertBefore is null), or before the specified basic block.
comment|///
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
literal|0
parameter_list|,
name|BasicBlock
modifier|*
name|InsertBefore
init|=
literal|0
parameter_list|)
function_decl|;
name|public
label|:
comment|/// getContext - Get the context in which this basic block lives.
name|LLVMContext
operator|&
name|getContext
argument_list|()
specifier|const
expr_stmt|;
comment|/// Instruction iterators...
typedef|typedef
name|InstListType
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|InstListType
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
comment|/// Create - Creates a new BasicBlock. If the Parent parameter is specified,
comment|/// the basic block is automatically inserted at either the end of the
comment|/// function (if InsertBefore is 0), or before the specified basic block.
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
literal|0
parameter_list|,
name|BasicBlock
modifier|*
name|InsertBefore
init|=
literal|0
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
operator|~
name|BasicBlock
argument_list|()
expr_stmt|;
comment|/// getParent - Return the enclosing method, or null if none
comment|///
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
comment|/// use_back - Specialize the methods defined in Value, as we know that an
comment|/// BasicBlock can only be used by Users (specifically PHI nodes, terminators,
comment|/// and BlockAddress's).
name|User
modifier|*
name|use_back
parameter_list|()
block|{
return|return
name|cast
operator|<
name|User
operator|>
operator|(
operator|*
name|use_begin
argument_list|()
operator|)
return|;
block|}
specifier|const
name|User
operator|*
name|use_back
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|User
operator|>
operator|(
operator|*
name|use_begin
argument_list|()
operator|)
return|;
block|}
comment|/// getTerminator() - If this is a well formed basic block, then this returns
comment|/// a pointer to the terminator instruction.  If it is not, then you get a
comment|/// null pointer back.
comment|///
name|TerminatorInst
modifier|*
name|getTerminator
parameter_list|()
function_decl|;
specifier|const
name|TerminatorInst
operator|*
name|getTerminator
argument_list|()
specifier|const
expr_stmt|;
comment|/// Returns a pointer to the first instructon in this block that is not a
comment|/// PHINode instruction. When adding instruction to the beginning of the
comment|/// basic block, they should be added before the returned value, not before
comment|/// the first instruction, which might be PHI.
comment|/// Returns 0 is there's no non-PHI instruction.
name|Instruction
modifier|*
name|getFirstNonPHI
parameter_list|()
function_decl|;
specifier|const
name|Instruction
operator|*
name|getFirstNonPHI
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|BasicBlock
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getFirstNonPHI
argument_list|()
return|;
block|}
comment|/// removeFromParent - This method unlinks 'this' from the containing
comment|/// function, but does not delete it.
comment|///
name|void
name|removeFromParent
parameter_list|()
function_decl|;
comment|/// eraseFromParent - This method unlinks 'this' from the containing function
comment|/// and deletes it.
comment|///
name|void
name|eraseFromParent
parameter_list|()
function_decl|;
comment|/// moveBefore - Unlink this basic block from its current function and
comment|/// insert it into the function that MovePos lives in, right before MovePos.
name|void
name|moveBefore
parameter_list|(
name|BasicBlock
modifier|*
name|MovePos
parameter_list|)
function_decl|;
comment|/// moveAfter - Unlink this basic block from its current function and
comment|/// insert it into the function that MovePos lives in, right after MovePos.
name|void
name|moveAfter
parameter_list|(
name|BasicBlock
modifier|*
name|MovePos
parameter_list|)
function_decl|;
comment|/// getSinglePredecessor - If this basic block has a single predecessor block,
comment|/// return the block, otherwise return a null pointer.
name|BasicBlock
modifier|*
name|getSinglePredecessor
parameter_list|()
function_decl|;
specifier|const
name|BasicBlock
operator|*
name|getSinglePredecessor
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|BasicBlock
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getSinglePredecessor
argument_list|()
return|;
block|}
comment|/// getUniquePredecessor - If this basic block has a unique predecessor block,
comment|/// return the block, otherwise return a null pointer.
comment|/// Note that unique predecessor doesn't mean single edge, there can be
comment|/// multiple edges from the unique predecessor to this block (for example
comment|/// a switch statement with multiple cases having the same destination).
name|BasicBlock
modifier|*
name|getUniquePredecessor
parameter_list|()
function_decl|;
specifier|const
name|BasicBlock
operator|*
name|getUniquePredecessor
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|BasicBlock
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getUniquePredecessor
argument_list|()
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
comment|/// getInstList() - Return the underlying instruction list container.  You
comment|/// need to access it directly if you want to modify it currently.
comment|///
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
comment|/// getSublistAccess() - returns pointer to member of instruction list
specifier|static
name|iplist
operator|<
name|Instruction
operator|>
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
comment|/// getValueSymbolTable() - returns pointer to symbol table (if any)
name|ValueSymbolTable
modifier|*
name|getValueSymbolTable
parameter_list|()
function_decl|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
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
comment|/// dropAllReferences() - This function causes all the subinstructions to "let
comment|/// go" of all references that they are maintaining.  This allows one to
comment|/// 'delete' a whole class at a time, even though there may be circular
comment|/// references... first all references are dropped, and all use counts go to
comment|/// zero.  Then everything is delete'd for real.  Note that no operations are
comment|/// valid on an object that has "dropped all references", except operator
comment|/// delete.
comment|///
name|void
name|dropAllReferences
parameter_list|()
function_decl|;
comment|/// removePredecessor - This method is used to notify a BasicBlock that the
comment|/// specified Predecessor of the block is no longer able to reach it.  This is
comment|/// actually not used to update the Predecessor list, but is actually used to
comment|/// update the PHI nodes that reside in the block.  Note that this should be
comment|/// called while the predecessor still refers to this block.
comment|///
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
comment|/// splitBasicBlock - This splits a basic block into two at the specified
comment|/// instruction.  Note that all instructions BEFORE the specified iterator
comment|/// stay as part of the original basic block, an unconditional branch is added
comment|/// to the original BB, and the rest of the instructions in the BB are moved
comment|/// to the new BB, including the old terminator.  The newly formed BasicBlock
comment|/// is returned.  This function invalidates the specified iterator.
comment|///
comment|/// Note that this only works on well formed basic blocks (must have a
comment|/// terminator), and 'I' must not be the end of instruction list (which would
comment|/// cause a degenerate basic block to be formed, having a terminator inside of
comment|/// the basic block).
comment|///
comment|/// Also note that this doesn't preserve any passes. To split blocks while
comment|/// keeping loop information consistent, use the SplitBlock utility function.
comment|///
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
comment|/// hasAddressTaken - returns true if there are any uses of this basic block
comment|/// other than direct branches, switches, etc. to it.
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
name|private
label|:
comment|/// AdjustBlockAddressRefCount - BasicBlock stores the number of BlockAddress
comment|/// objects using it.  This is almost always 0, sometimes one, possibly but
comment|/// almost never 2, and inconceivably 3 or more.
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
comment|// Shadow Value::setValueSubclassData with a private forwarding method so that
comment|// any future subclasses cannot accidentally use it.
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
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

