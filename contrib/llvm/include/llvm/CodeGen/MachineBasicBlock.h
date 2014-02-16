begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/MachineBasicBlock.h ------------------------*- C++ -*-===//
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
comment|// Collect the sequence of machine instructions for a basic block.
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
name|LLVM_CODEGEN_MACHINEBASICBLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINEBASICBLOCK_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/GraphTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineInstr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Pass
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|SlotIndexes
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|MachineBranchProbabilityInfo
decl_stmt|;
name|template
operator|<
operator|>
expr|struct
name|ilist_traits
operator|<
name|MachineInstr
operator|>
operator|:
name|public
name|ilist_default_traits
operator|<
name|MachineInstr
operator|>
block|{
name|private
operator|:
name|mutable
name|ilist_half_node
operator|<
name|MachineInstr
operator|>
name|Sentinel
block|;
comment|// this is only set by the MachineBasicBlock owning the LiveList
name|friend
name|class
name|MachineBasicBlock
block|;
name|MachineBasicBlock
operator|*
name|Parent
block|;
name|public
operator|:
name|MachineInstr
operator|*
name|createSentinel
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|MachineInstr
operator|*
operator|>
operator|(
operator|&
name|Sentinel
operator|)
return|;
block|}
name|void
name|destroySentinel
argument_list|(
argument|MachineInstr *
argument_list|)
specifier|const
block|{}
name|MachineInstr
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
name|MachineInstr
operator|*
name|ensureHead
argument_list|(
argument|MachineInstr*
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
argument|MachineInstr*
argument_list|,
argument|MachineInstr*
argument_list|)
block|{}
name|void
name|addNodeToList
argument_list|(
name|MachineInstr
operator|*
name|N
argument_list|)
block|;
name|void
name|removeNodeFromList
argument_list|(
name|MachineInstr
operator|*
name|N
argument_list|)
block|;
name|void
name|transferNodesFromList
argument_list|(
name|ilist_traits
operator|&
name|SrcTraits
argument_list|,
name|ilist_iterator
operator|<
name|MachineInstr
operator|>
name|first
argument_list|,
name|ilist_iterator
operator|<
name|MachineInstr
operator|>
name|last
argument_list|)
block|;
name|void
name|deleteNode
argument_list|(
name|MachineInstr
operator|*
name|N
argument_list|)
block|;
name|private
operator|:
name|void
name|createNode
argument_list|(
specifier|const
name|MachineInstr
operator|&
argument_list|)
block|; }
expr_stmt|;
name|class
name|MachineBasicBlock
range|:
name|public
name|ilist_node
operator|<
name|MachineBasicBlock
operator|>
block|{
typedef|typedef
name|ilist
operator|<
name|MachineInstr
operator|>
name|Instructions
expr_stmt|;
name|Instructions
name|Insts
decl_stmt|;
specifier|const
name|BasicBlock
modifier|*
name|BB
decl_stmt|;
name|int
name|Number
decl_stmt|;
name|MachineFunction
modifier|*
name|xParent
decl_stmt|;
comment|/// Predecessors/Successors - Keep track of the predecessor / successor
comment|/// basicblocks.
name|std
operator|::
name|vector
operator|<
name|MachineBasicBlock
operator|*
operator|>
name|Predecessors
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|MachineBasicBlock
operator|*
operator|>
name|Successors
expr_stmt|;
comment|/// Weights - Keep track of the weights to the successors. This vector
comment|/// has the same order as Successors, or it is empty if we don't use it
comment|/// (disable optimization).
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|Weights
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
operator|::
name|iterator
name|weight_iterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
operator|::
name|const_iterator
name|const_weight_iterator
expr_stmt|;
comment|/// LiveIns - Keep track of the physical registers that are livein of
comment|/// the basicblock.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|LiveIns
expr_stmt|;
comment|/// Alignment - Alignment of the basic block. Zero if the basic block does
comment|/// not need to be aligned.
comment|/// The alignment is specified as log2(bytes).
name|unsigned
name|Alignment
decl_stmt|;
comment|/// IsLandingPad - Indicate that this basic block is entered via an
comment|/// exception handler.
name|bool
name|IsLandingPad
decl_stmt|;
comment|/// AddressTaken - Indicate that this basic block is potentially the
comment|/// target of an indirect branch.
name|bool
name|AddressTaken
decl_stmt|;
comment|/// \brief since getSymbol is a relatively heavy-weight operation, the symbol
comment|/// is only computed once and is cached.
name|mutable
name|MCSymbol
modifier|*
name|CachedMCSymbol
decl_stmt|;
comment|// Intrusive list support
name|MachineBasicBlock
argument_list|()
block|{}
name|explicit
name|MachineBasicBlock
parameter_list|(
name|MachineFunction
modifier|&
name|mf
parameter_list|,
specifier|const
name|BasicBlock
modifier|*
name|bb
parameter_list|)
function_decl|;
operator|~
name|MachineBasicBlock
argument_list|()
expr_stmt|;
comment|// MachineBasicBlocks are allocated and owned by MachineFunction.
name|friend
name|class
name|MachineFunction
decl_stmt|;
name|public
label|:
comment|/// getBasicBlock - Return the LLVM basic block that this instance
comment|/// corresponded to originally. Note that this may be NULL if this instance
comment|/// does not correspond directly to an LLVM basic block.
comment|///
specifier|const
name|BasicBlock
operator|*
name|getBasicBlock
argument_list|()
specifier|const
block|{
return|return
name|BB
return|;
block|}
comment|/// getName - Return the name of the corresponding LLVM basic block, or
comment|/// "(null)".
name|StringRef
name|getName
argument_list|()
specifier|const
expr_stmt|;
comment|/// getFullName - Return a formatted string to identify this block and its
comment|/// parent function.
name|std
operator|::
name|string
name|getFullName
argument_list|()
specifier|const
expr_stmt|;
comment|/// hasAddressTaken - Test whether this block is potentially the target
comment|/// of an indirect branch.
name|bool
name|hasAddressTaken
argument_list|()
specifier|const
block|{
return|return
name|AddressTaken
return|;
block|}
comment|/// setHasAddressTaken - Set this block to reflect that it potentially
comment|/// is the target of an indirect branch.
name|void
name|setHasAddressTaken
parameter_list|()
block|{
name|AddressTaken
operator|=
name|true
expr_stmt|;
block|}
comment|/// getParent - Return the MachineFunction containing this basic block.
comment|///
specifier|const
name|MachineFunction
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|xParent
return|;
block|}
name|MachineFunction
modifier|*
name|getParent
parameter_list|()
block|{
return|return
name|xParent
return|;
block|}
comment|/// bundle_iterator - MachineBasicBlock iterator that automatically skips over
comment|/// MIs that are inside bundles (i.e. walk top level MIs only).
name|template
operator|<
name|typename
name|Ty
operator|,
name|typename
name|IterTy
operator|>
name|class
name|bundle_iterator
operator|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|bidirectional_iterator_tag
operator|,
name|Ty
operator|,
name|ptrdiff_t
operator|>
block|{
name|IterTy
name|MII
block|;
name|public
operator|:
name|bundle_iterator
argument_list|(
argument|IterTy mii
argument_list|)
operator|:
name|MII
argument_list|(
argument|mii
argument_list|)
block|{}
name|bundle_iterator
argument_list|(
name|Ty
operator|&
name|mi
argument_list|)
operator|:
name|MII
argument_list|(
argument|mi
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|mi
operator|.
name|isBundledWithPred
argument_list|()
operator|&&
literal|"It's not legal to initialize bundle_iterator with a bundled MI"
argument_list|)
block|;     }
name|bundle_iterator
argument_list|(
name|Ty
operator|*
name|mi
argument_list|)
operator|:
name|MII
argument_list|(
argument|mi
argument_list|)
block|{
name|assert
argument_list|(
operator|(
operator|!
name|mi
operator|||
operator|!
name|mi
operator|->
name|isBundledWithPred
argument_list|()
operator|)
operator|&&
literal|"It's not legal to initialize bundle_iterator with a bundled MI"
argument_list|)
block|;     }
comment|// Template allows conversion from const to nonconst.
name|template
operator|<
name|class
name|OtherTy
block|,
name|class
name|OtherIterTy
operator|>
name|bundle_iterator
argument_list|(
specifier|const
name|bundle_iterator
operator|<
name|OtherTy
argument_list|,
name|OtherIterTy
operator|>
operator|&
name|I
argument_list|)
operator|:
name|MII
argument_list|(
argument|I.getInstrIterator()
argument_list|)
block|{}
name|bundle_iterator
argument_list|()
operator|:
name|MII
argument_list|(
literal|0
argument_list|)
block|{}
name|Ty
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|MII
return|;
block|}
name|Ty
operator|*
name|operator
operator|->
expr|(
block|)
specifier|const
block|{
return|return
operator|&
name|operator
operator|*
operator|(
operator|)
return|;
block|}
name|operator
name|Ty
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|MII
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|bundle_iterator
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|MII
operator|==
name|x
operator|.
name|MII
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|bundle_iterator
operator|&
name|x
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|x
operator|)
return|;
block|}
comment|// Increment and decrement operators...
name|bundle_iterator
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
comment|// predecrement - Back up
do|do
operator|--
name|MII
expr_stmt|;
do|while
condition|(
name|MII
operator|->
name|isBundledWithPred
argument_list|()
condition|)
do|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|bundle_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// preincrement - Advance
while|while
condition|(
name|MII
operator|->
name|isBundledWithSucc
argument_list|()
condition|)
operator|++
name|MII
expr_stmt|;
operator|++
name|MII
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_expr_stmt
unit|}     bundle_iterator
name|operator
operator|--
operator|(
name|int
operator|)
block|{
comment|// postdecrement operators...
name|bundle_iterator
name|tmp
operator|=
operator|*
name|this
block|;
operator|--
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bundle_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// postincrement operators...
name|bundle_iterator
name|tmp
operator|=
operator|*
name|this
block|;
operator|++
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|IterTy
name|getInstrIterator
argument_list|()
specifier|const
block|{
return|return
name|MII
return|;
block|}
end_expr_stmt

begin_typedef
unit|};
typedef|typedef
name|Instructions
operator|::
name|iterator
name|instr_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|Instructions
operator|::
name|const_iterator
name|const_instr_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|instr_iterator
operator|>
name|reverse_instr_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|const_instr_iterator
operator|>
name|const_reverse_instr_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|bundle_iterator
operator|<
name|MachineInstr
operator|,
name|instr_iterator
operator|>
name|iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|bundle_iterator
operator|<
specifier|const
name|MachineInstr
operator|,
name|const_instr_iterator
operator|>
name|const_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|const_iterator
operator|>
name|const_reverse_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|iterator
operator|>
name|reverse_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
operator|(
name|unsigned
operator|)
name|Insts
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Insts
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|MachineInstr
modifier|&
name|front
parameter_list|()
block|{
return|return
name|Insts
operator|.
name|front
argument_list|()
return|;
block|}
end_function

begin_function
name|MachineInstr
modifier|&
name|back
parameter_list|()
block|{
return|return
name|Insts
operator|.
name|back
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|MachineInstr
operator|&
name|front
argument_list|()
specifier|const
block|{
return|return
name|Insts
operator|.
name|front
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|MachineInstr
operator|&
name|back
argument_list|()
specifier|const
block|{
return|return
name|Insts
operator|.
name|back
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|instr_iterator
name|instr_begin
parameter_list|()
block|{
return|return
name|Insts
operator|.
name|begin
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_instr_iterator
name|instr_begin
argument_list|()
specifier|const
block|{
return|return
name|Insts
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|instr_iterator
name|instr_end
parameter_list|()
block|{
return|return
name|Insts
operator|.
name|end
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_instr_iterator
name|instr_end
argument_list|()
specifier|const
block|{
return|return
name|Insts
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|reverse_instr_iterator
name|instr_rbegin
parameter_list|()
block|{
return|return
name|Insts
operator|.
name|rbegin
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_reverse_instr_iterator
name|instr_rbegin
argument_list|()
specifier|const
block|{
return|return
name|Insts
operator|.
name|rbegin
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|reverse_instr_iterator
name|instr_rend
parameter_list|()
block|{
return|return
name|Insts
operator|.
name|rend
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_reverse_instr_iterator
name|instr_rend
argument_list|()
specifier|const
block|{
return|return
name|Insts
operator|.
name|rend
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|instr_begin
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|instr_begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|iterator
name|end
parameter_list|()
block|{
return|return
name|instr_end
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|instr_end
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|reverse_iterator
name|rbegin
parameter_list|()
block|{
return|return
name|instr_rbegin
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_reverse_iterator
name|rbegin
argument_list|()
specifier|const
block|{
return|return
name|instr_rbegin
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|reverse_iterator
name|rend
parameter_list|()
block|{
return|return
name|instr_rend
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_reverse_iterator
name|rend
argument_list|()
specifier|const
block|{
return|return
name|instr_rend
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// Machine-CFG iterators
end_comment

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|MachineBasicBlock
operator|*
operator|>
operator|::
name|iterator
name|pred_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|MachineBasicBlock
operator|*
operator|>
operator|::
name|const_iterator
name|const_pred_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|MachineBasicBlock
operator|*
operator|>
operator|::
name|iterator
name|succ_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|MachineBasicBlock
operator|*
operator|>
operator|::
name|const_iterator
name|const_succ_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|MachineBasicBlock
operator|*
operator|>
operator|::
name|reverse_iterator
name|pred_reverse_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|MachineBasicBlock
operator|*
operator|>
operator|::
name|const_reverse_iterator
name|const_pred_reverse_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|MachineBasicBlock
operator|*
operator|>
operator|::
name|reverse_iterator
name|succ_reverse_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|MachineBasicBlock
operator|*
operator|>
operator|::
name|const_reverse_iterator
name|const_succ_reverse_iterator
expr_stmt|;
end_typedef

begin_function
name|pred_iterator
name|pred_begin
parameter_list|()
block|{
return|return
name|Predecessors
operator|.
name|begin
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_pred_iterator
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
end_expr_stmt

begin_function
name|pred_iterator
name|pred_end
parameter_list|()
block|{
return|return
name|Predecessors
operator|.
name|end
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_pred_iterator
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
end_expr_stmt

begin_function
name|pred_reverse_iterator
name|pred_rbegin
parameter_list|()
block|{
return|return
name|Predecessors
operator|.
name|rbegin
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_pred_reverse_iterator
name|pred_rbegin
argument_list|()
specifier|const
block|{
return|return
name|Predecessors
operator|.
name|rbegin
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|pred_reverse_iterator
name|pred_rend
parameter_list|()
block|{
return|return
name|Predecessors
operator|.
name|rend
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_pred_reverse_iterator
name|pred_rend
argument_list|()
specifier|const
block|{
return|return
name|Predecessors
operator|.
name|rend
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|pred_size
argument_list|()
specifier|const
block|{
return|return
operator|(
name|unsigned
operator|)
name|Predecessors
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|pred_empty
argument_list|()
specifier|const
block|{
return|return
name|Predecessors
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|succ_iterator
name|succ_begin
parameter_list|()
block|{
return|return
name|Successors
operator|.
name|begin
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_succ_iterator
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
end_expr_stmt

begin_function
name|succ_iterator
name|succ_end
parameter_list|()
block|{
return|return
name|Successors
operator|.
name|end
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_succ_iterator
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
end_expr_stmt

begin_function
name|succ_reverse_iterator
name|succ_rbegin
parameter_list|()
block|{
return|return
name|Successors
operator|.
name|rbegin
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_succ_reverse_iterator
name|succ_rbegin
argument_list|()
specifier|const
block|{
return|return
name|Successors
operator|.
name|rbegin
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|succ_reverse_iterator
name|succ_rend
parameter_list|()
block|{
return|return
name|Successors
operator|.
name|rend
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_succ_reverse_iterator
name|succ_rend
argument_list|()
specifier|const
block|{
return|return
name|Successors
operator|.
name|rend
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|succ_size
argument_list|()
specifier|const
block|{
return|return
operator|(
name|unsigned
operator|)
name|Successors
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|succ_empty
argument_list|()
specifier|const
block|{
return|return
name|Successors
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// LiveIn management methods.
end_comment

begin_comment
comment|/// addLiveIn - Add the specified register as a live in.  Note that it
end_comment

begin_comment
comment|/// is an error to add the same register to the same set more than once.
end_comment

begin_function
name|void
name|addLiveIn
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
name|LiveIns
operator|.
name|push_back
argument_list|(
name|Reg
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Add PhysReg as live in to this block, and ensure that there is a copy of
end_comment

begin_comment
comment|/// PhysReg to a virtual register of class RC. Return the virtual register
end_comment

begin_comment
comment|/// that is a copy of the live in PhysReg.
end_comment

begin_function_decl
name|unsigned
name|addLiveIn
parameter_list|(
name|unsigned
name|PhysReg
parameter_list|,
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// removeLiveIn - Remove the specified register from the live in set.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|void
name|removeLiveIn
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// isLiveIn - Return true if the specified register is in the live in set.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|bool
name|isLiveIn
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Iteration support for live in sets.  These sets are kept in sorted
end_comment

begin_comment
comment|// order by their register number.
end_comment

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|::
name|const_iterator
name|livein_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|livein_iterator
name|livein_begin
argument_list|()
specifier|const
block|{
return|return
name|LiveIns
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|livein_iterator
name|livein_end
argument_list|()
specifier|const
block|{
return|return
name|LiveIns
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|livein_empty
argument_list|()
specifier|const
block|{
return|return
name|LiveIns
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getAlignment - Return alignment of the basic block.
end_comment

begin_comment
comment|/// The alignment is specified as log2(bytes).
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|unsigned
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
name|Alignment
return|;
block|}
end_expr_stmt

begin_comment
comment|/// setAlignment - Set alignment of the basic block.
end_comment

begin_comment
comment|/// The alignment is specified as log2(bytes).
end_comment

begin_comment
comment|///
end_comment

begin_function
name|void
name|setAlignment
parameter_list|(
name|unsigned
name|Align
parameter_list|)
block|{
name|Alignment
operator|=
name|Align
expr_stmt|;
block|}
end_function

begin_comment
comment|/// isLandingPad - Returns true if the block is a landing pad. That is
end_comment

begin_comment
comment|/// this basic block is entered via an exception handler.
end_comment

begin_expr_stmt
name|bool
name|isLandingPad
argument_list|()
specifier|const
block|{
return|return
name|IsLandingPad
return|;
block|}
end_expr_stmt

begin_comment
comment|/// setIsLandingPad - Indicates the block is a landing pad.  That is
end_comment

begin_comment
comment|/// this basic block is entered via an exception handler.
end_comment

begin_function
name|void
name|setIsLandingPad
parameter_list|(
name|bool
name|V
init|=
name|true
parameter_list|)
block|{
name|IsLandingPad
operator|=
name|V
expr_stmt|;
block|}
end_function

begin_comment
comment|/// getLandingPadSuccessor - If this block has a successor that is a landing
end_comment

begin_comment
comment|/// pad, return it. Otherwise return NULL.
end_comment

begin_expr_stmt
specifier|const
name|MachineBasicBlock
operator|*
name|getLandingPadSuccessor
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Code Layout methods.
end_comment

begin_comment
comment|/// moveBefore/moveAfter - move 'this' block before or after the specified
end_comment

begin_comment
comment|/// block.  This only moves the block, it does not modify the CFG or adjust
end_comment

begin_comment
comment|/// potential fall-throughs at the end of the block.
end_comment

begin_function_decl
name|void
name|moveBefore
parameter_list|(
name|MachineBasicBlock
modifier|*
name|NewAfter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|moveAfter
parameter_list|(
name|MachineBasicBlock
modifier|*
name|NewBefore
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// updateTerminator - Update the terminator instructions in block to account
end_comment

begin_comment
comment|/// for changes to the layout. If the block previously used a fallthrough,
end_comment

begin_comment
comment|/// it may now need a branch, and if it previously used branching it may now
end_comment

begin_comment
comment|/// be able to use a fallthrough.
end_comment

begin_function_decl
name|void
name|updateTerminator
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Machine-CFG mutators
end_comment

begin_comment
comment|/// addSuccessor - Add succ as a successor of this MachineBasicBlock.
end_comment

begin_comment
comment|/// The Predecessors list of succ is automatically updated. WEIGHT
end_comment

begin_comment
comment|/// parameter is stored in Weights list and it may be used by
end_comment

begin_comment
comment|/// MachineBranchProbabilityInfo analysis to calculate branch probability.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that duplicate Machine CFG edges are not allowed.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|void
name|addSuccessor
parameter_list|(
name|MachineBasicBlock
modifier|*
name|succ
parameter_list|,
name|uint32_t
name|weight
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// removeSuccessor - Remove successor from the successors list of this
end_comment

begin_comment
comment|/// MachineBasicBlock. The Predecessors list of succ is automatically updated.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|void
name|removeSuccessor
parameter_list|(
name|MachineBasicBlock
modifier|*
name|succ
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// removeSuccessor - Remove specified successor from the successors list of
end_comment

begin_comment
comment|/// this MachineBasicBlock. The Predecessors list of succ is automatically
end_comment

begin_comment
comment|/// updated.  Return the iterator to the element after the one removed.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|succ_iterator
name|removeSuccessor
parameter_list|(
name|succ_iterator
name|I
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// replaceSuccessor - Replace successor OLD with NEW and update weight info.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|void
name|replaceSuccessor
parameter_list|(
name|MachineBasicBlock
modifier|*
name|Old
parameter_list|,
name|MachineBasicBlock
modifier|*
name|New
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// transferSuccessors - Transfers all the successors from MBB to this
end_comment

begin_comment
comment|/// machine basic block (i.e., copies all the successors fromMBB and
end_comment

begin_comment
comment|/// remove all the successors from fromMBB).
end_comment

begin_function_decl
name|void
name|transferSuccessors
parameter_list|(
name|MachineBasicBlock
modifier|*
name|fromMBB
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// transferSuccessorsAndUpdatePHIs - Transfers all the successors, as
end_comment

begin_comment
comment|/// in transferSuccessors, and update PHI operands in the successor blocks
end_comment

begin_comment
comment|/// which refer to fromMBB to refer to this.
end_comment

begin_function_decl
name|void
name|transferSuccessorsAndUpdatePHIs
parameter_list|(
name|MachineBasicBlock
modifier|*
name|fromMBB
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// isPredecessor - Return true if the specified MBB is a predecessor of this
end_comment

begin_comment
comment|/// block.
end_comment

begin_decl_stmt
name|bool
name|isPredecessor
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// isSuccessor - Return true if the specified MBB is a successor of this
end_comment

begin_comment
comment|/// block.
end_comment

begin_decl_stmt
name|bool
name|isSuccessor
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// isLayoutSuccessor - Return true if the specified MBB will be emitted
end_comment

begin_comment
comment|/// immediately after this block, such that if this block exits by
end_comment

begin_comment
comment|/// falling through, control will transfer to the specified MBB. Note
end_comment

begin_comment
comment|/// that MBB need not be a successor at all, for example if this block
end_comment

begin_comment
comment|/// ends with an unconditional branch to some other block.
end_comment

begin_decl_stmt
name|bool
name|isLayoutSuccessor
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// canFallThrough - Return true if the block can implicitly transfer
end_comment

begin_comment
comment|/// control to the block after it by falling off the end of it.  This should
end_comment

begin_comment
comment|/// return false if it can reach the block after it, but it uses an explicit
end_comment

begin_comment
comment|/// branch to do so (e.g., a table jump).  True is a conservative answer.
end_comment

begin_function_decl
name|bool
name|canFallThrough
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Returns a pointer to the first instruction in this block that is not a
end_comment

begin_comment
comment|/// PHINode instruction. When adding instructions to the beginning of the
end_comment

begin_comment
comment|/// basic block, they should be added before the returned value, not before
end_comment

begin_comment
comment|/// the first instruction, which might be PHI.
end_comment

begin_comment
comment|/// Returns end() is there's no non-PHI instruction.
end_comment

begin_function_decl
name|iterator
name|getFirstNonPHI
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// SkipPHIsAndLabels - Return the first instruction in MBB after I that is
end_comment

begin_comment
comment|/// not a PHI or a label. This is the correct point to insert copies at the
end_comment

begin_comment
comment|/// beginning of a basic block.
end_comment

begin_function_decl
name|iterator
name|SkipPHIsAndLabels
parameter_list|(
name|iterator
name|I
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getFirstTerminator - returns an iterator to the first terminator
end_comment

begin_comment
comment|/// instruction of this basic block. If a terminator does not exist,
end_comment

begin_comment
comment|/// it returns end()
end_comment

begin_function_decl
name|iterator
name|getFirstTerminator
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|const_iterator
name|getFirstTerminator
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getFirstInstrTerminator - Same getFirstTerminator but it ignores bundles
end_comment

begin_comment
comment|/// and return an instr_iterator instead.
end_comment

begin_function_decl
name|instr_iterator
name|getFirstInstrTerminator
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// getLastNonDebugInstr - returns an iterator to the last non-debug
end_comment

begin_comment
comment|/// instruction in the basic block, or end()
end_comment

begin_function_decl
name|iterator
name|getLastNonDebugInstr
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|const_iterator
name|getLastNonDebugInstr
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// SplitCriticalEdge - Split the critical edge from this block to the
end_comment

begin_comment
comment|/// given successor block, and return the newly created block, or null
end_comment

begin_comment
comment|/// if splitting is not possible.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function updates LiveVariables, MachineDominatorTree, and
end_comment

begin_comment
comment|/// MachineLoopInfo, as applicable.
end_comment

begin_function_decl
name|MachineBasicBlock
modifier|*
name|SplitCriticalEdge
parameter_list|(
name|MachineBasicBlock
modifier|*
name|Succ
parameter_list|,
name|Pass
modifier|*
name|P
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|pop_front
parameter_list|()
block|{
name|Insts
operator|.
name|pop_front
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|pop_back
parameter_list|()
block|{
name|Insts
operator|.
name|pop_back
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|push_back
parameter_list|(
name|MachineInstr
modifier|*
name|MI
parameter_list|)
block|{
name|Insts
operator|.
name|push_back
argument_list|(
name|MI
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Insert MI into the instruction list before I, possibly inside a bundle.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If the insertion point is inside a bundle, MI will be added to the bundle,
end_comment

begin_comment
comment|/// otherwise MI will not be added to any bundle. That means this function
end_comment

begin_comment
comment|/// alone can't be used to prepend or append instructions to bundles. See
end_comment

begin_comment
comment|/// MIBundleBuilder::insert() for a more reliable way of doing that.
end_comment

begin_function_decl
name|instr_iterator
name|insert
parameter_list|(
name|instr_iterator
name|I
parameter_list|,
name|MachineInstr
modifier|*
name|M
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Insert a range of instructions into the instruction list before I.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|IT
operator|>
name|void
name|insert
argument_list|(
argument|iterator I
argument_list|,
argument|IT S
argument_list|,
argument|IT E
argument_list|)
block|{
name|Insts
operator|.
name|insert
argument_list|(
name|I
operator|.
name|getInstrIterator
argument_list|()
argument_list|,
name|S
argument_list|,
name|E
argument_list|)
block|;   }
comment|/// Insert MI into the instruction list before I.
name|iterator
name|insert
argument_list|(
argument|iterator I
argument_list|,
argument|MachineInstr *MI
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|MI
operator|->
name|isBundledWithPred
argument_list|()
operator|&&
operator|!
name|MI
operator|->
name|isBundledWithSucc
argument_list|()
operator|&&
literal|"Cannot insert instruction with bundle flags"
argument_list|)
block|;
return|return
name|Insts
operator|.
name|insert
argument_list|(
name|I
operator|.
name|getInstrIterator
argument_list|()
argument_list|,
name|MI
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Insert MI into the instruction list after I.
end_comment

begin_function
name|iterator
name|insertAfter
parameter_list|(
name|iterator
name|I
parameter_list|,
name|MachineInstr
modifier|*
name|MI
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|MI
operator|->
name|isBundledWithPred
argument_list|()
operator|&&
operator|!
name|MI
operator|->
name|isBundledWithSucc
argument_list|()
operator|&&
literal|"Cannot insert instruction with bundle flags"
argument_list|)
expr_stmt|;
return|return
name|Insts
operator|.
name|insertAfter
argument_list|(
name|I
operator|.
name|getInstrIterator
argument_list|()
argument_list|,
name|MI
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Remove an instruction from the instruction list and delete it.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If the instruction is part of a bundle, the other instructions in the
end_comment

begin_comment
comment|/// bundle will still be bundled after removing the single instruction.
end_comment

begin_function_decl
name|instr_iterator
name|erase
parameter_list|(
name|instr_iterator
name|I
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Remove an instruction from the instruction list and delete it.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If the instruction is part of a bundle, the other instructions in the
end_comment

begin_comment
comment|/// bundle will still be bundled after removing the single instruction.
end_comment

begin_function
name|instr_iterator
name|erase_instr
parameter_list|(
name|MachineInstr
modifier|*
name|I
parameter_list|)
block|{
return|return
name|erase
argument_list|(
name|instr_iterator
argument_list|(
name|I
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Remove a range of instructions from the instruction list and delete them.
end_comment

begin_function
name|iterator
name|erase
parameter_list|(
name|iterator
name|I
parameter_list|,
name|iterator
name|E
parameter_list|)
block|{
return|return
name|Insts
operator|.
name|erase
argument_list|(
name|I
operator|.
name|getInstrIterator
argument_list|()
argument_list|,
name|E
operator|.
name|getInstrIterator
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Remove an instruction or bundle from the instruction list and delete it.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If I points to a bundle of instructions, they are all erased.
end_comment

begin_function
name|iterator
name|erase
parameter_list|(
name|iterator
name|I
parameter_list|)
block|{
return|return
name|erase
argument_list|(
name|I
argument_list|,
name|llvm
operator|::
name|next
argument_list|(
name|I
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Remove an instruction from the instruction list and delete it.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If I is the head of a bundle of instructions, the whole bundle will be
end_comment

begin_comment
comment|/// erased.
end_comment

begin_function
name|iterator
name|erase
parameter_list|(
name|MachineInstr
modifier|*
name|I
parameter_list|)
block|{
return|return
name|erase
argument_list|(
name|iterator
argument_list|(
name|I
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Remove the unbundled instruction from the instruction list without
end_comment

begin_comment
comment|/// deleting it.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function can not be used to remove bundled instructions, use
end_comment

begin_comment
comment|/// remove_instr to remove individual instructions from a bundle.
end_comment

begin_function
name|MachineInstr
modifier|*
name|remove
parameter_list|(
name|MachineInstr
modifier|*
name|I
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|I
operator|->
name|isBundled
argument_list|()
operator|&&
literal|"Cannot remove bundled instructions"
argument_list|)
expr_stmt|;
return|return
name|Insts
operator|.
name|remove
argument_list|(
name|I
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Remove the possibly bundled instruction from the instruction list
end_comment

begin_comment
comment|/// without deleting it.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If the instruction is part of a bundle, the other instructions in the
end_comment

begin_comment
comment|/// bundle will still be bundled after removing the single instruction.
end_comment

begin_function_decl
name|MachineInstr
modifier|*
name|remove_instr
parameter_list|(
name|MachineInstr
modifier|*
name|I
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|clear
parameter_list|()
block|{
name|Insts
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Take an instruction from MBB 'Other' at the position From, and insert it
end_comment

begin_comment
comment|/// into this MBB right before 'Where'.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If From points to a bundle of instructions, the whole bundle is moved.
end_comment

begin_function
name|void
name|splice
parameter_list|(
name|iterator
name|Where
parameter_list|,
name|MachineBasicBlock
modifier|*
name|Other
parameter_list|,
name|iterator
name|From
parameter_list|)
block|{
comment|// The range splice() doesn't allow noop moves, but this one does.
if|if
condition|(
name|Where
operator|!=
name|From
condition|)
name|splice
argument_list|(
name|Where
argument_list|,
name|Other
argument_list|,
name|From
argument_list|,
name|llvm
operator|::
name|next
argument_list|(
name|From
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Take a block of instructions from MBB 'Other' in the range [From, To),
end_comment

begin_comment
comment|/// and insert them into this MBB right before 'Where'.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The instruction at 'Where' must not be included in the range of
end_comment

begin_comment
comment|/// instructions to move.
end_comment

begin_function
name|void
name|splice
parameter_list|(
name|iterator
name|Where
parameter_list|,
name|MachineBasicBlock
modifier|*
name|Other
parameter_list|,
name|iterator
name|From
parameter_list|,
name|iterator
name|To
parameter_list|)
block|{
name|Insts
operator|.
name|splice
argument_list|(
name|Where
operator|.
name|getInstrIterator
argument_list|()
argument_list|,
name|Other
operator|->
name|Insts
argument_list|,
name|From
operator|.
name|getInstrIterator
argument_list|()
argument_list|,
name|To
operator|.
name|getInstrIterator
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// removeFromParent - This method unlinks 'this' from the containing
end_comment

begin_comment
comment|/// function, and returns it, but does not delete it.
end_comment

begin_function_decl
name|MachineBasicBlock
modifier|*
name|removeFromParent
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// eraseFromParent - This method unlinks 'this' from the containing
end_comment

begin_comment
comment|/// function and deletes it.
end_comment

begin_function_decl
name|void
name|eraseFromParent
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// ReplaceUsesOfBlockWith - Given a machine basic block that branched to
end_comment

begin_comment
comment|/// 'Old', change the code and CFG so that it branches to 'New' instead.
end_comment

begin_function_decl
name|void
name|ReplaceUsesOfBlockWith
parameter_list|(
name|MachineBasicBlock
modifier|*
name|Old
parameter_list|,
name|MachineBasicBlock
modifier|*
name|New
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// CorrectExtraCFGEdges - Various pieces of code can cause excess edges in
end_comment

begin_comment
comment|/// the CFG to be inserted.  If we have proven that MBB can only branch to
end_comment

begin_comment
comment|/// DestA and DestB, remove any other MBB successors from the CFG. DestA and
end_comment

begin_comment
comment|/// DestB can be null. Besides DestA and DestB, retain other edges leading
end_comment

begin_comment
comment|/// to LandingPads (currently there can be only one; we don't check or require
end_comment

begin_comment
comment|/// that here). Note it is possible that DestA and/or DestB are LandingPads.
end_comment

begin_function_decl
name|bool
name|CorrectExtraCFGEdges
parameter_list|(
name|MachineBasicBlock
modifier|*
name|DestA
parameter_list|,
name|MachineBasicBlock
modifier|*
name|DestB
parameter_list|,
name|bool
name|isCond
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// findDebugLoc - find the next valid DebugLoc starting at MBBI, skipping
end_comment

begin_comment
comment|/// any DBG_VALUE instructions.  Return UnknownLoc if there is none.
end_comment

begin_function_decl
name|DebugLoc
name|findDebugLoc
parameter_list|(
name|instr_iterator
name|MBBI
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|DebugLoc
name|findDebugLoc
parameter_list|(
name|iterator
name|MBBI
parameter_list|)
block|{
return|return
name|findDebugLoc
argument_list|(
name|MBBI
operator|.
name|getInstrIterator
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Possible outcome of a register liveness query to computeRegisterLiveness()
end_comment

begin_enum
enum|enum
name|LivenessQueryResult
block|{
name|LQR_Live
block|,
comment|///< Register is known to be live.
name|LQR_OverlappingLive
block|,
comment|///< Register itself is not live, but some overlapping
comment|///< register is.
name|LQR_Dead
block|,
comment|///< Register is known to be dead.
name|LQR_Unknown
comment|///< Register liveness not decidable from local
comment|///< neighborhood.
block|}
enum|;
end_enum

begin_comment
comment|/// computeRegisterLiveness - Return whether (physical) register \c Reg
end_comment

begin_comment
comment|/// has been<def>ined and not<kill>ed as of just before \c MI.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Search is localised to a neighborhood of
end_comment

begin_comment
comment|/// \c Neighborhood instructions before (searching for defs or kills) and
end_comment

begin_comment
comment|/// Neighborhood instructions after (searching just for defs) MI.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \c Reg must be a physical register.
end_comment

begin_function_decl
name|LivenessQueryResult
name|computeRegisterLiveness
parameter_list|(
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
parameter_list|,
name|unsigned
name|Reg
parameter_list|,
name|MachineInstr
modifier|*
name|MI
parameter_list|,
name|unsigned
name|Neighborhood
init|=
literal|10
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Debugging methods.
end_comment

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|SlotIndexes
operator|*
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getNumber - MachineBasicBlocks are uniquely numbered at the function
end_comment

begin_comment
comment|/// level, unless they're not in a MachineFunction yet, in which case this
end_comment

begin_comment
comment|/// will return -1.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|int
name|getNumber
argument_list|()
specifier|const
block|{
return|return
name|Number
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setNumber
parameter_list|(
name|int
name|N
parameter_list|)
block|{
name|Number
operator|=
name|N
expr_stmt|;
block|}
end_function

begin_comment
comment|/// getSymbol - Return the MCSymbol for this basic block.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|MCSymbol
operator|*
name|getSymbol
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// getWeightIterator - Return weight iterator corresponding to the I
end_comment

begin_comment
comment|/// successor iterator.
end_comment

begin_function_decl
name|weight_iterator
name|getWeightIterator
parameter_list|(
name|succ_iterator
name|I
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|const_weight_iterator
name|getWeightIterator
argument_list|(
name|const_succ_iterator
name|I
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|MachineBranchProbabilityInfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getSuccWeight - Return weight of the edge from this block to MBB. This
end_comment

begin_comment
comment|/// method should NOT be called directly, but by using getEdgeWeight method
end_comment

begin_comment
comment|/// from MachineBranchProbabilityInfo class.
end_comment

begin_decl_stmt
name|uint32_t
name|getSuccWeight
argument_list|(
name|const_succ_iterator
name|Succ
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Methods used to maintain doubly linked list of blocks...
end_comment

begin_macro
name|friend
end_macro

begin_expr_stmt
unit|struct
name|ilist_traits
operator|<
name|MachineBasicBlock
operator|>
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Machine-CFG mutators
end_comment

begin_comment
comment|/// addPredecessor - Remove pred as a predecessor of this MachineBasicBlock.
end_comment

begin_comment
comment|/// Don't do this unless you know what you're doing, because it doesn't
end_comment

begin_comment
comment|/// update pred's successors list. Use pred->addSuccessor instead.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|void
name|addPredecessor
parameter_list|(
name|MachineBasicBlock
modifier|*
name|pred
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// removePredecessor - Remove pred as a predecessor of this
end_comment

begin_comment
comment|/// MachineBasicBlock. Don't do this unless you know what you're
end_comment

begin_comment
comment|/// doing, because it doesn't update pred's successors list. Use
end_comment

begin_comment
comment|/// pred->removeSuccessor instead.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|void
name|removePredecessor
parameter_list|(
name|MachineBasicBlock
modifier|*
name|pred
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
unit|};
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|MachineBasicBlock
operator|&
name|MBB
operator|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|WriteAsOperand
parameter_list|(
name|raw_ostream
modifier|&
parameter_list|,
specifier|const
name|MachineBasicBlock
modifier|*
parameter_list|,
name|bool
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// This is useful when building IndexedMaps keyed on basic block pointers.
end_comment

begin_decl_stmt
name|struct
name|MBB2NumberFunctor
range|:
name|public
name|std
operator|::
name|unary_function
operator|<
specifier|const
name|MachineBasicBlock
operator|*
decl_stmt|,
name|unsigned
decl|>
block|{
name|unsigned
name|operator
argument_list|()
operator|(
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
operator|)
specifier|const
block|{
return|return
name|MBB
operator|->
name|getNumber
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// GraphTraits specializations for machine basic block graphs (machine-CFGs)
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Provide specializations of GraphTraits to be able to treat a
end_comment

begin_comment
comment|// MachineFunction as a graph of MachineBasicBlocks...
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|MachineBasicBlock
operator|*
operator|>
block|{
typedef|typedef
name|MachineBasicBlock
name|NodeType
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|MachineBasicBlock
operator|::
name|succ_iterator
name|ChildIteratorType
expr_stmt|;
end_typedef

begin_function
specifier|static
name|NodeType
modifier|*
name|getEntryNode
parameter_list|(
name|MachineBasicBlock
modifier|*
name|BB
parameter_list|)
block|{
return|return
name|BB
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|ChildIteratorType
name|child_begin
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|N
operator|->
name|succ_begin
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|ChildIteratorType
name|child_end
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|N
operator|->
name|succ_end
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
specifier|const
name|MachineBasicBlock
operator|*
operator|>
block|{
typedef|typedef
specifier|const
name|MachineBasicBlock
name|NodeType
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|MachineBasicBlock
operator|::
name|const_succ_iterator
name|ChildIteratorType
expr_stmt|;
end_typedef

begin_function
specifier|static
name|NodeType
modifier|*
name|getEntryNode
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|*
name|BB
parameter_list|)
block|{
return|return
name|BB
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|ChildIteratorType
name|child_begin
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|N
operator|->
name|succ_begin
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|ChildIteratorType
name|child_end
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|N
operator|->
name|succ_end
argument_list|()
return|;
block|}
end_function

begin_comment
unit|};
comment|// Provide specializations of GraphTraits to be able to treat a
end_comment

begin_comment
comment|// MachineFunction as a graph of MachineBasicBlocks... and to walk it
end_comment

begin_comment
comment|// in inverse order.  Inverse order for a function is considered
end_comment

begin_comment
comment|// to be when traversing the predecessor edges of a MBB
end_comment

begin_comment
comment|// instead of the successor edges.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|Inverse
operator|<
name|MachineBasicBlock
operator|*
operator|>
expr|>
block|{
typedef|typedef
name|MachineBasicBlock
name|NodeType
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|MachineBasicBlock
operator|::
name|pred_iterator
name|ChildIteratorType
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|static
name|NodeType
modifier|*
name|getEntryNode
argument_list|(
name|Inverse
operator|<
name|MachineBasicBlock
operator|*
operator|>
name|G
argument_list|)
block|{
return|return
name|G
operator|.
name|Graph
return|;
block|}
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|ChildIteratorType
name|child_begin
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|N
operator|->
name|pred_begin
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|ChildIteratorType
name|child_end
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|N
operator|->
name|pred_end
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|Inverse
operator|<
specifier|const
name|MachineBasicBlock
operator|*
operator|>
expr|>
block|{
typedef|typedef
specifier|const
name|MachineBasicBlock
name|NodeType
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|MachineBasicBlock
operator|::
name|const_pred_iterator
name|ChildIteratorType
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|static
name|NodeType
modifier|*
name|getEntryNode
argument_list|(
name|Inverse
operator|<
specifier|const
name|MachineBasicBlock
operator|*
operator|>
name|G
argument_list|)
block|{
return|return
name|G
operator|.
name|Graph
return|;
block|}
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|ChildIteratorType
name|child_begin
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|N
operator|->
name|pred_begin
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|ChildIteratorType
name|child_end
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|N
operator|->
name|pred_end
argument_list|()
return|;
block|}
end_function

begin_comment
unit|};
comment|/// MachineInstrSpan provides an interface to get an iteration range
end_comment

begin_comment
comment|/// containing the instruction it was initialized with, along with all
end_comment

begin_comment
comment|/// those instructions inserted prior to or following that instruction
end_comment

begin_comment
comment|/// at some point after the MachineInstrSpan is constructed.
end_comment

begin_decl_stmt
name|class
name|MachineInstrSpan
block|{
name|MachineBasicBlock
modifier|&
name|MBB
decl_stmt|;
name|MachineBasicBlock
operator|::
name|iterator
name|I
operator|,
name|B
operator|,
name|E
expr_stmt|;
name|public
label|:
name|MachineInstrSpan
argument_list|(
argument|MachineBasicBlock::iterator I
argument_list|)
block|:
name|MBB
argument_list|(
operator|*
name|I
operator|->
name|getParent
argument_list|()
argument_list|)
operator|,
name|I
argument_list|(
name|I
argument_list|)
operator|,
name|B
argument_list|(
name|I
operator|==
name|MBB
operator|.
name|begin
argument_list|()
condition|?
name|MBB
operator|.
name|end
argument_list|()
else|:
name|llvm
operator|::
name|prior
argument_list|(
name|I
argument_list|)
argument_list|)
operator|,
name|E
argument_list|(
argument|llvm::next(I)
argument_list|)
block|{}
name|MachineBasicBlock
operator|::
name|iterator
name|begin
argument_list|()
block|{
return|return
name|B
operator|==
name|MBB
operator|.
name|end
argument_list|()
condition|?
name|MBB
operator|.
name|begin
argument_list|()
else|:
name|llvm
operator|::
name|next
argument_list|(
name|B
argument_list|)
return|;
block|}
name|MachineBasicBlock
operator|::
name|iterator
name|end
argument_list|()
block|{
return|return
name|E
return|;
block|}
name|bool
name|empty
parameter_list|()
block|{
return|return
name|begin
argument_list|()
operator|==
name|end
argument_list|()
return|;
block|}
name|MachineBasicBlock
operator|::
name|iterator
name|getInitial
argument_list|()
block|{
return|return
name|I
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

