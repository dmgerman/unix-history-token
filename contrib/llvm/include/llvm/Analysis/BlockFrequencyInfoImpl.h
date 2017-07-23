begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- BlockFrequencyInfoImpl.h - Block Frequency Implementation -*- C++ -*-===//
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
comment|// Shared implementation of BlockFrequency for IR and Machine Instructions.
end_comment

begin_comment
comment|// See the documentation below for BlockFrequencyInfoImpl for details.
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
name|LLVM_ANALYSIS_BLOCKFREQUENCYINFOIMPL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_BLOCKFREQUENCYINFOIMPL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/GraphTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PostOrderIterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/BasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BlockFrequency.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BranchProbability.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DOTGraphTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Format.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ScaledNumber.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<deque>
end_include

begin_include
include|#
directive|include
file|<list>
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

begin_define
define|#
directive|define
name|DEBUG_TYPE
value|"block-freq"
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BasicBlock
decl_stmt|;
name|class
name|BranchProbabilityInfo
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Loop
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineBranchProbabilityInfo
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineLoop
decl_stmt|;
name|class
name|MachineLoopInfo
decl_stmt|;
name|namespace
name|bfi_detail
block|{
struct_decl|struct
name|IrreducibleGraph
struct_decl|;
comment|// This is part of a workaround for a GCC 4.7 crash on lambdas.
name|template
operator|<
name|class
name|BT
operator|>
expr|struct
name|BlockEdgesAdder
expr_stmt|;
comment|/// \brief Mass of a block.
comment|///
comment|/// This class implements a sort of fixed-point fraction always between 0.0 and
comment|/// 1.0.  getMass() == UINT64_MAX indicates a value of 1.0.
comment|///
comment|/// Masses can be added and subtracted.  Simple saturation arithmetic is used,
comment|/// so arithmetic operations never overflow or underflow.
comment|///
comment|/// Masses can be multiplied.  Multiplication treats full mass as 1.0 and uses
comment|/// an inexpensive floating-point algorithm that's off-by-one (almost, but not
comment|/// quite, maximum precision).
comment|///
comment|/// Masses can be scaled by \a BranchProbability at maximum precision.
name|class
name|BlockMass
block|{
name|uint64_t
name|Mass
decl_stmt|;
name|public
label|:
name|BlockMass
argument_list|()
operator|:
name|Mass
argument_list|(
literal|0
argument_list|)
block|{}
name|explicit
name|BlockMass
argument_list|(
argument|uint64_t Mass
argument_list|)
operator|:
name|Mass
argument_list|(
argument|Mass
argument_list|)
block|{}
specifier|static
name|BlockMass
name|getEmpty
argument_list|()
block|{
return|return
name|BlockMass
argument_list|()
return|;
block|}
specifier|static
name|BlockMass
name|getFull
parameter_list|()
block|{
return|return
name|BlockMass
argument_list|(
name|UINT64_MAX
argument_list|)
return|;
block|}
name|uint64_t
name|getMass
argument_list|()
specifier|const
block|{
return|return
name|Mass
return|;
block|}
name|bool
name|isFull
argument_list|()
specifier|const
block|{
return|return
name|Mass
operator|==
name|UINT64_MAX
return|;
block|}
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Mass
return|;
block|}
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
block|{
return|return
name|isEmpty
argument_list|()
return|;
block|}
comment|/// \brief Add another mass.
comment|///
comment|/// Adds another mass, saturating at \a isFull() rather than overflowing.
name|BlockMass
operator|&
name|operator
operator|+=
operator|(
name|BlockMass
name|X
operator|)
block|{
name|uint64_t
name|Sum
operator|=
name|Mass
operator|+
name|X
operator|.
name|Mass
block|;
name|Mass
operator|=
name|Sum
operator|<
name|Mass
condition|?
name|UINT64_MAX
else|:
name|Sum
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Subtract another mass.
comment|///
comment|/// Subtracts another mass, saturating at \a isEmpty() rather than
comment|/// undeflowing.
name|BlockMass
operator|&
name|operator
operator|-=
operator|(
name|BlockMass
name|X
operator|)
block|{
name|uint64_t
name|Diff
operator|=
name|Mass
operator|-
name|X
operator|.
name|Mass
block|;
name|Mass
operator|=
name|Diff
operator|>
name|Mass
condition|?
literal|0
else|:
name|Diff
block|;
return|return
operator|*
name|this
return|;
block|}
name|BlockMass
operator|&
name|operator
operator|*=
operator|(
name|BranchProbability
name|P
operator|)
block|{
name|Mass
operator|=
name|P
operator|.
name|scale
argument_list|(
name|Mass
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|bool
name|operator
operator|==
operator|(
name|BlockMass
name|X
operator|)
specifier|const
block|{
return|return
name|Mass
operator|==
name|X
operator|.
name|Mass
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
name|BlockMass
name|X
operator|)
specifier|const
block|{
return|return
name|Mass
operator|!=
name|X
operator|.
name|Mass
return|;
block|}
name|bool
name|operator
operator|<=
operator|(
name|BlockMass
name|X
operator|)
specifier|const
block|{
return|return
name|Mass
operator|<=
name|X
operator|.
name|Mass
return|;
block|}
name|bool
name|operator
operator|>=
operator|(
name|BlockMass
name|X
operator|)
specifier|const
block|{
return|return
name|Mass
operator|>=
name|X
operator|.
name|Mass
return|;
block|}
name|bool
name|operator
operator|<
operator|(
name|BlockMass
name|X
operator|)
specifier|const
block|{
return|return
name|Mass
operator|<
name|X
operator|.
name|Mass
return|;
block|}
name|bool
name|operator
operator|>
operator|(
name|BlockMass
name|X
operator|)
specifier|const
block|{
return|return
name|Mass
operator|>
name|X
operator|.
name|Mass
return|;
block|}
comment|/// \brief Convert to scaled number.
comment|///
comment|/// Convert to \a ScaledNumber.  \a isFull() gives 1.0, while \a isEmpty()
comment|/// gives slightly above 0.0.
name|ScaledNumber
operator|<
name|uint64_t
operator|>
name|toScaled
argument_list|()
specifier|const
expr_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
name|raw_ostream
modifier|&
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
specifier|inline
name|BlockMass
name|operator
operator|+
operator|(
name|BlockMass
name|L
operator|,
name|BlockMass
name|R
operator|)
block|{
return|return
name|BlockMass
argument_list|(
name|L
argument_list|)
operator|+=
name|R
return|;
block|}
specifier|inline
name|BlockMass
name|operator
operator|-
operator|(
name|BlockMass
name|L
operator|,
name|BlockMass
name|R
operator|)
block|{
return|return
name|BlockMass
argument_list|(
name|L
argument_list|)
operator|-=
name|R
return|;
block|}
specifier|inline
name|BlockMass
name|operator
modifier|*
parameter_list|(
name|BlockMass
name|L
parameter_list|,
name|BranchProbability
name|R
parameter_list|)
block|{
return|return
name|BlockMass
argument_list|(
name|L
argument_list|)
operator|*=
name|R
return|;
block|}
specifier|inline
name|BlockMass
name|operator
modifier|*
parameter_list|(
name|BranchProbability
name|L
parameter_list|,
name|BlockMass
name|R
parameter_list|)
block|{
return|return
name|BlockMass
argument_list|(
name|R
argument_list|)
operator|*=
name|L
return|;
block|}
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
name|BlockMass
name|X
operator|)
block|{
return|return
name|X
operator|.
name|print
argument_list|(
name|OS
argument_list|)
return|;
block|}
block|}
comment|// end namespace bfi_detail
name|template
operator|<
operator|>
expr|struct
name|isPodLike
operator|<
name|bfi_detail
operator|::
name|BlockMass
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|; }
expr_stmt|;
comment|/// \brief Base class for BlockFrequencyInfoImpl
comment|///
comment|/// BlockFrequencyInfoImplBase has supporting data structures and some
comment|/// algorithms for BlockFrequencyInfoImplBase.  Only algorithms that depend on
comment|/// the block type (or that call such algorithms) are skipped here.
comment|///
comment|/// Nevertheless, the majority of the overall algorithm documention lives with
comment|/// BlockFrequencyInfoImpl.  See there for details.
name|class
name|BlockFrequencyInfoImplBase
block|{
name|public
label|:
typedef|typedef
name|ScaledNumber
operator|<
name|uint64_t
operator|>
name|Scaled64
expr_stmt|;
typedef|typedef
name|bfi_detail
operator|::
name|BlockMass
name|BlockMass
expr_stmt|;
comment|/// \brief Representative of a block.
comment|///
comment|/// This is a simple wrapper around an index into the reverse-post-order
comment|/// traversal of the blocks.
comment|///
comment|/// Unlike a block pointer, its order has meaning (location in the
comment|/// topological sort) and it's class is the same regardless of block type.
struct|struct
name|BlockNode
block|{
typedef|typedef
name|uint32_t
name|IndexType
typedef|;
name|IndexType
name|Index
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|BlockNode
operator|&
name|X
operator|)
specifier|const
block|{
return|return
name|Index
operator|==
name|X
operator|.
name|Index
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|BlockNode
operator|&
name|X
operator|)
specifier|const
block|{
return|return
name|Index
operator|!=
name|X
operator|.
name|Index
return|;
block|}
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|BlockNode
operator|&
name|X
operator|)
specifier|const
block|{
return|return
name|Index
operator|<=
name|X
operator|.
name|Index
return|;
block|}
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|BlockNode
operator|&
name|X
operator|)
specifier|const
block|{
return|return
name|Index
operator|>=
name|X
operator|.
name|Index
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|BlockNode
operator|&
name|X
operator|)
specifier|const
block|{
return|return
name|Index
operator|<
name|X
operator|.
name|Index
return|;
block|}
name|bool
name|operator
operator|>
operator|(
specifier|const
name|BlockNode
operator|&
name|X
operator|)
specifier|const
block|{
return|return
name|Index
operator|>
name|X
operator|.
name|Index
return|;
block|}
name|BlockNode
argument_list|()
operator|:
name|Index
argument_list|(
argument|UINT32_MAX
argument_list|)
block|{}
name|BlockNode
argument_list|(
argument|IndexType Index
argument_list|)
operator|:
name|Index
argument_list|(
argument|Index
argument_list|)
block|{}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|Index
operator|<=
name|getMaxIndex
argument_list|()
return|;
block|}
specifier|static
name|size_t
name|getMaxIndex
parameter_list|()
block|{
return|return
name|UINT32_MAX
operator|-
literal|1
return|;
block|}
block|}
struct|;
comment|/// \brief Stats about a block itself.
struct|struct
name|FrequencyData
block|{
name|Scaled64
name|Scaled
decl_stmt|;
name|uint64_t
name|Integer
decl_stmt|;
block|}
struct|;
comment|/// \brief Data about a loop.
comment|///
comment|/// Contains the data necessary to represent a loop as a pseudo-node once it's
comment|/// packaged.
struct|struct
name|LoopData
block|{
typedef|typedef
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|BlockNode
operator|,
name|BlockMass
operator|>
operator|,
literal|4
operator|>
name|ExitMap
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|BlockNode
operator|,
literal|4
operator|>
name|NodeList
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|BlockMass
operator|,
literal|1
operator|>
name|HeaderMassList
expr_stmt|;
name|LoopData
modifier|*
name|Parent
decl_stmt|;
comment|///< The parent loop.
name|bool
name|IsPackaged
decl_stmt|;
comment|///< Whether this has been packaged.
name|uint32_t
name|NumHeaders
decl_stmt|;
comment|///< Number of headers.
name|ExitMap
name|Exits
decl_stmt|;
comment|///< Successor edges (and weights).
name|NodeList
name|Nodes
decl_stmt|;
comment|///< Header and the members of the loop.
name|HeaderMassList
name|BackedgeMass
decl_stmt|;
comment|///< Mass returned to each loop header.
name|BlockMass
name|Mass
decl_stmt|;
name|Scaled64
name|Scale
decl_stmt|;
name|LoopData
argument_list|(
name|LoopData
operator|*
name|Parent
argument_list|,
specifier|const
name|BlockNode
operator|&
name|Header
argument_list|)
operator|:
name|Parent
argument_list|(
name|Parent
argument_list|)
operator|,
name|IsPackaged
argument_list|(
name|false
argument_list|)
operator|,
name|NumHeaders
argument_list|(
literal|1
argument_list|)
operator|,
name|Nodes
argument_list|(
literal|1
argument_list|,
name|Header
argument_list|)
operator|,
name|BackedgeMass
argument_list|(
literal|1
argument_list|)
block|{}
name|template
operator|<
name|class
name|It1
operator|,
name|class
name|It2
operator|>
name|LoopData
argument_list|(
argument|LoopData *Parent
argument_list|,
argument|It1 FirstHeader
argument_list|,
argument|It1 LastHeader
argument_list|,
argument|It2 FirstOther
argument_list|,
argument|It2 LastOther
argument_list|)
operator|:
name|Parent
argument_list|(
name|Parent
argument_list|)
operator|,
name|IsPackaged
argument_list|(
name|false
argument_list|)
operator|,
name|Nodes
argument_list|(
argument|FirstHeader
argument_list|,
argument|LastHeader
argument_list|)
block|{
name|NumHeaders
operator|=
name|Nodes
operator|.
name|size
argument_list|()
block|;
name|Nodes
operator|.
name|insert
argument_list|(
name|Nodes
operator|.
name|end
argument_list|()
argument_list|,
name|FirstOther
argument_list|,
name|LastOther
argument_list|)
block|;
name|BackedgeMass
operator|.
name|resize
argument_list|(
name|NumHeaders
argument_list|)
block|;     }
name|bool
name|isHeader
argument_list|(
argument|const BlockNode&Node
argument_list|)
specifier|const
block|{
if|if
condition|(
name|isIrreducible
argument_list|()
condition|)
return|return
name|std
operator|::
name|binary_search
argument_list|(
name|Nodes
operator|.
name|begin
argument_list|()
argument_list|,
name|Nodes
operator|.
name|begin
argument_list|()
operator|+
name|NumHeaders
argument_list|,
name|Node
argument_list|)
return|;
return|return
name|Node
operator|==
name|Nodes
index|[
literal|0
index|]
return|;
block|}
name|BlockNode
name|getHeader
argument_list|()
decl|const
block|{
return|return
name|Nodes
index|[
literal|0
index|]
return|;
block|}
name|bool
name|isIrreducible
argument_list|()
decl|const
block|{
return|return
name|NumHeaders
operator|>
literal|1
return|;
block|}
name|HeaderMassList
decl|::
name|difference_type
name|getHeaderIndex
argument_list|(
specifier|const
name|BlockNode
operator|&
name|B
argument_list|)
block|{
name|assert
argument_list|(
name|isHeader
argument_list|(
name|B
argument_list|)
operator|&&
literal|"this is only valid on loop header blocks"
argument_list|)
expr_stmt|;
if|if
condition|(
name|isIrreducible
argument_list|()
condition|)
return|return
name|std
operator|::
name|lower_bound
argument_list|(
name|Nodes
operator|.
name|begin
argument_list|()
argument_list|,
name|Nodes
operator|.
name|begin
argument_list|()
operator|+
name|NumHeaders
argument_list|,
name|B
argument_list|)
operator|-
name|Nodes
operator|.
name|begin
argument_list|()
return|;
return|return
literal|0
return|;
block|}
name|NodeList
decl|::
name|const_iterator
name|members_begin
argument_list|()
decl|const
block|{
return|return
name|Nodes
operator|.
name|begin
argument_list|()
operator|+
name|NumHeaders
return|;
block|}
name|NodeList
decl|::
name|const_iterator
name|members_end
argument_list|()
decl|const
block|{
return|return
name|Nodes
operator|.
name|end
argument_list|()
return|;
block|}
name|iterator_range
decl|<
name|NodeList
decl|::
name|const_iterator
decl|>
name|members
argument_list|()
decl|const
block|{
return|return
name|make_range
argument_list|(
name|members_begin
argument_list|()
argument_list|,
name|members_end
argument_list|()
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Index of loop information.
struct|struct
name|WorkingData
block|{
name|BlockNode
name|Node
decl_stmt|;
comment|///< This node.
name|LoopData
modifier|*
name|Loop
decl_stmt|;
comment|///< The loop this block is inside.
name|BlockMass
name|Mass
decl_stmt|;
comment|///< Mass distribution from the entry block.
name|WorkingData
argument_list|(
specifier|const
name|BlockNode
operator|&
name|Node
argument_list|)
operator|:
name|Node
argument_list|(
name|Node
argument_list|)
operator|,
name|Loop
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|bool
name|isLoopHeader
argument_list|()
specifier|const
block|{
return|return
name|Loop
operator|&&
name|Loop
operator|->
name|isHeader
argument_list|(
name|Node
argument_list|)
return|;
block|}
name|bool
name|isDoubleLoopHeader
argument_list|()
specifier|const
block|{
return|return
name|isLoopHeader
argument_list|()
operator|&&
name|Loop
operator|->
name|Parent
operator|&&
name|Loop
operator|->
name|Parent
operator|->
name|isIrreducible
argument_list|()
operator|&&
name|Loop
operator|->
name|Parent
operator|->
name|isHeader
argument_list|(
name|Node
argument_list|)
return|;
block|}
name|LoopData
operator|*
name|getContainingLoop
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isLoopHeader
argument_list|()
condition|)
return|return
name|Loop
return|;
if|if
condition|(
operator|!
name|isDoubleLoopHeader
argument_list|()
condition|)
return|return
name|Loop
operator|->
name|Parent
return|;
return|return
name|Loop
operator|->
name|Parent
operator|->
name|Parent
return|;
block|}
comment|/// \brief Resolve a node to its representative.
comment|///
comment|/// Get the node currently representing Node, which could be a containing
comment|/// loop.
comment|///
comment|/// This function should only be called when distributing mass.  As long as
comment|/// there are no irreducible edges to Node, then it will have complexity
comment|/// O(1) in this context.
comment|///
comment|/// In general, the complexity is O(L), where L is the number of loop
comment|/// headers Node has been packaged into.  Since this method is called in
comment|/// the context of distributing mass, L will be the number of loop headers
comment|/// an early exit edge jumps out of.
name|BlockNode
name|getResolvedNode
argument_list|()
decl|const
block|{
name|auto
name|L
init|=
name|getPackagedLoop
argument_list|()
decl_stmt|;
return|return
name|L
condition|?
name|L
operator|->
name|getHeader
argument_list|()
else|:
name|Node
return|;
block|}
name|LoopData
modifier|*
name|getPackagedLoop
argument_list|()
decl|const
block|{
if|if
condition|(
operator|!
name|Loop
operator|||
operator|!
name|Loop
operator|->
name|IsPackaged
condition|)
return|return
name|nullptr
return|;
name|auto
name|L
init|=
name|Loop
decl_stmt|;
while|while
condition|(
name|L
operator|->
name|Parent
operator|&&
name|L
operator|->
name|Parent
operator|->
name|IsPackaged
condition|)
name|L
operator|=
name|L
operator|->
name|Parent
expr_stmt|;
return|return
name|L
return|;
block|}
comment|/// \brief Get the appropriate mass for a node.
comment|///
comment|/// Get appropriate mass for Node.  If Node is a loop-header (whose loop
comment|/// has been packaged), returns the mass of its pseudo-node.  If it's a
comment|/// node inside a packaged loop, it returns the loop's mass.
name|BlockMass
modifier|&
name|getMass
argument_list|()
block|{
if|if
condition|(
operator|!
name|isAPackage
argument_list|()
condition|)
return|return
name|Mass
return|;
if|if
condition|(
operator|!
name|isADoublePackage
argument_list|()
condition|)
return|return
name|Loop
operator|->
name|Mass
return|;
return|return
name|Loop
operator|->
name|Parent
operator|->
name|Mass
return|;
block|}
comment|/// \brief Has ContainingLoop been packaged up?
name|bool
name|isPackaged
argument_list|()
decl|const
block|{
return|return
name|getResolvedNode
argument_list|()
operator|!=
name|Node
return|;
block|}
comment|/// \brief Has Loop been packaged up?
name|bool
name|isAPackage
argument_list|()
decl|const
block|{
return|return
name|isLoopHeader
argument_list|()
operator|&&
name|Loop
operator|->
name|IsPackaged
return|;
block|}
comment|/// \brief Has Loop been packaged up twice?
name|bool
name|isADoublePackage
argument_list|()
decl|const
block|{
return|return
name|isDoubleLoopHeader
argument_list|()
operator|&&
name|Loop
operator|->
name|Parent
operator|->
name|IsPackaged
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Unscaled probability weight.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Probability weight for an edge in the graph (including the
end_comment

begin_comment
comment|/// successor/target node).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// All edges in the original function are 32-bit.  However, exit edges from
end_comment

begin_comment
comment|/// loop packages are taken from 64-bit exit masses, so we need 64-bits of
end_comment

begin_comment
comment|/// space in general.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In addition to the raw weight amount, Weight stores the type of the edge
end_comment

begin_comment
comment|/// in the current context (i.e., the context of the loop being processed).
end_comment

begin_comment
comment|/// Is this a local edge within the loop, an exit from the loop, or a
end_comment

begin_comment
comment|/// backedge to the loop header?
end_comment

begin_struct
struct|struct
name|Weight
block|{
enum|enum
name|DistType
block|{
name|Local
block|,
name|Exit
block|,
name|Backedge
block|}
enum|;
name|DistType
name|Type
decl_stmt|;
name|BlockNode
name|TargetNode
decl_stmt|;
name|uint64_t
name|Amount
decl_stmt|;
name|Weight
argument_list|()
operator|:
name|Type
argument_list|(
name|Local
argument_list|)
operator|,
name|Amount
argument_list|(
literal|0
argument_list|)
block|{}
name|Weight
argument_list|(
argument|DistType Type
argument_list|,
argument|BlockNode TargetNode
argument_list|,
argument|uint64_t Amount
argument_list|)
operator|:
name|Type
argument_list|(
name|Type
argument_list|)
operator|,
name|TargetNode
argument_list|(
name|TargetNode
argument_list|)
operator|,
name|Amount
argument_list|(
argument|Amount
argument_list|)
block|{}
block|}
struct|;
end_struct

begin_comment
comment|/// \brief Distribution of unscaled probability weight.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Distribution of unscaled probability weight to a set of successors.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This class collates the successor edge weights for later processing.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \a DidOverflow indicates whether \a Total did overflow while adding to
end_comment

begin_comment
comment|/// the distribution.  It should never overflow twice.
end_comment

begin_struct
struct|struct
name|Distribution
block|{
typedef|typedef
name|SmallVector
operator|<
name|Weight
operator|,
literal|4
operator|>
name|WeightList
expr_stmt|;
name|WeightList
name|Weights
decl_stmt|;
comment|///< Individual successor weights.
name|uint64_t
name|Total
decl_stmt|;
comment|///< Sum of all weights.
name|bool
name|DidOverflow
decl_stmt|;
comment|///< Whether \a Total did overflow.
name|Distribution
argument_list|()
operator|:
name|Total
argument_list|(
literal|0
argument_list|)
operator|,
name|DidOverflow
argument_list|(
argument|false
argument_list|)
block|{}
name|void
name|addLocal
argument_list|(
argument|const BlockNode&Node
argument_list|,
argument|uint64_t Amount
argument_list|)
block|{
name|add
argument_list|(
name|Node
argument_list|,
name|Amount
argument_list|,
name|Weight
operator|::
name|Local
argument_list|)
block|;     }
name|void
name|addExit
argument_list|(
argument|const BlockNode&Node
argument_list|,
argument|uint64_t Amount
argument_list|)
block|{
name|add
argument_list|(
name|Node
argument_list|,
name|Amount
argument_list|,
name|Weight
operator|::
name|Exit
argument_list|)
block|;     }
name|void
name|addBackedge
argument_list|(
argument|const BlockNode&Node
argument_list|,
argument|uint64_t Amount
argument_list|)
block|{
name|add
argument_list|(
name|Node
argument_list|,
name|Amount
argument_list|,
name|Weight
operator|::
name|Backedge
argument_list|)
block|;     }
comment|/// \brief Normalize the distribution.
comment|///
comment|/// Combines multiple edges to the same \a Weight::TargetNode and scales
comment|/// down so that \a Total fits into 32-bits.
comment|///
comment|/// This is linear in the size of \a Weights.  For the vast majority of
comment|/// cases, adjacent edge weights are combined by sorting WeightList and
comment|/// combining adjacent weights.  However, for very large edge lists an
comment|/// auxiliary hash table is used.
name|void
name|normalize
argument_list|()
expr_stmt|;
name|private
label|:
name|void
name|add
argument_list|(
specifier|const
name|BlockNode
operator|&
name|Node
argument_list|,
name|uint64_t
name|Amount
argument_list|,
name|Weight
operator|::
name|DistType
name|Type
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// \brief Data about each block.  This is used downstream.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|FrequencyData
operator|>
name|Freqs
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Loop data: see initializeLoops().
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|WorkingData
operator|>
name|Working
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Indexed information about loops.
end_comment

begin_expr_stmt
name|std
operator|::
name|list
operator|<
name|LoopData
operator|>
name|Loops
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Add all edges out of a packaged loop to the distribution.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Adds all edges from LocalLoopHead to Dist.  Calls addToDist() to add each
end_comment

begin_comment
comment|/// successor edge.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return \c true unless there's an irreducible backedge.
end_comment

begin_function_decl
name|bool
name|addLoopSuccessorsToDist
parameter_list|(
specifier|const
name|LoopData
modifier|*
name|OuterLoop
parameter_list|,
name|LoopData
modifier|&
name|Loop
parameter_list|,
name|Distribution
modifier|&
name|Dist
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Add an edge to the distribution.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Adds an edge to Succ to Dist.  If \c LoopHead.isValid(), then whether the
end_comment

begin_comment
comment|/// edge is local/exit/backedge is in the context of LoopHead.  Otherwise,
end_comment

begin_comment
comment|/// every edge should be a local edge (since all the loops are packaged up).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return \c true unless aborted due to an irreducible backedge.
end_comment

begin_function_decl
name|bool
name|addToDist
parameter_list|(
name|Distribution
modifier|&
name|Dist
parameter_list|,
specifier|const
name|LoopData
modifier|*
name|OuterLoop
parameter_list|,
specifier|const
name|BlockNode
modifier|&
name|Pred
parameter_list|,
specifier|const
name|BlockNode
modifier|&
name|Succ
parameter_list|,
name|uint64_t
name|Weight
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|LoopData
modifier|&
name|getLoopPackage
parameter_list|(
specifier|const
name|BlockNode
modifier|&
name|Head
parameter_list|)
block|{
name|assert
argument_list|(
name|Head
operator|.
name|Index
operator|<
name|Working
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|Working
index|[
name|Head
operator|.
name|Index
index|]
operator|.
name|isLoopHeader
argument_list|()
argument_list|)
expr_stmt|;
return|return
operator|*
name|Working
index|[
name|Head
operator|.
name|Index
index|]
operator|.
name|Loop
return|;
block|}
end_function

begin_comment
comment|/// \brief Analyze irreducible SCCs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Separate irreducible SCCs from \c G, which is an explict graph of \c
end_comment

begin_comment
comment|/// OuterLoop (or the top-level function, if \c OuterLoop is \c nullptr).
end_comment

begin_comment
comment|/// Insert them into \a Loops before \c Insert.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return the \c LoopData nodes representing the irreducible SCCs.
end_comment

begin_expr_stmt
name|iterator_range
operator|<
name|std
operator|::
name|list
operator|<
name|LoopData
operator|>
operator|::
name|iterator
operator|>
name|analyzeIrreducible
argument_list|(
argument|const bfi_detail::IrreducibleGraph&G
argument_list|,
argument|LoopData *OuterLoop
argument_list|,
argument|std::list<LoopData>::iterator Insert
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Update a loop after packaging irreducible SCCs inside of it.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Update \c OuterLoop.  Before finding irreducible control flow, it was
end_comment

begin_comment
comment|/// partway through \a computeMassInLoop(), so \a LoopData::Exits and \a
end_comment

begin_comment
comment|/// LoopData::BackedgeMass need to be reset.  Also, nodes that were packaged
end_comment

begin_comment
comment|/// up need to be removed from \a OuterLoop::Nodes.
end_comment

begin_function_decl
name|void
name|updateLoopWithIrreducible
parameter_list|(
name|LoopData
modifier|&
name|OuterLoop
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Distribute mass according to a distribution.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Distributes the mass in Source according to Dist.  If LoopHead.isValid(),
end_comment

begin_comment
comment|/// backedges and exits are stored in its entry in Loops.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Mass is distributed in parallel from two copies of the source mass.
end_comment

begin_function_decl
name|void
name|distributeMass
parameter_list|(
specifier|const
name|BlockNode
modifier|&
name|Source
parameter_list|,
name|LoopData
modifier|*
name|OuterLoop
parameter_list|,
name|Distribution
modifier|&
name|Dist
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Compute the loop scale for a loop.
end_comment

begin_function_decl
name|void
name|computeLoopScale
parameter_list|(
name|LoopData
modifier|&
name|Loop
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Adjust the mass of all headers in an irreducible loop.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Initially, irreducible loops are assumed to distribute their mass
end_comment

begin_comment
comment|/// equally among its headers. This can lead to wrong frequency estimates
end_comment

begin_comment
comment|/// since some headers may be executed more frequently than others.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This adjusts header mass distribution so it matches the weights of
end_comment

begin_comment
comment|/// the backedges going into each of the loop headers.
end_comment

begin_function_decl
name|void
name|adjustLoopHeaderMass
parameter_list|(
name|LoopData
modifier|&
name|Loop
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Package up a loop.
end_comment

begin_function_decl
name|void
name|packageLoop
parameter_list|(
name|LoopData
modifier|&
name|Loop
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Unwrap loops.
end_comment

begin_function_decl
name|void
name|unwrapLoops
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Finalize frequency metrics.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Calculates final frequencies and cleans up no-longer-needed data
end_comment

begin_comment
comment|/// structures.
end_comment

begin_function_decl
name|void
name|finalizeMetrics
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Clear all memory.
end_comment

begin_function_decl
name|void
name|clear
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|virtual
name|std
operator|::
name|string
name|getBlockName
argument_list|(
argument|const BlockNode&Node
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|getLoopName
argument_list|(
argument|const LoopData&Loop
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
name|raw_ostream
modifier|&
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
block|{
return|return
name|OS
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
block|{
name|print
argument_list|(
name|dbgs
argument_list|()
argument_list|)
block|; }
name|Scaled64
name|getFloatingBlockFreq
argument_list|(
argument|const BlockNode&Node
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|BlockFrequency
name|getBlockFreq
argument_list|(
specifier|const
name|BlockNode
operator|&
name|Node
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|Optional
operator|<
name|uint64_t
operator|>
name|getBlockProfileCount
argument_list|(
argument|const Function&F
argument_list|,
argument|const BlockNode&Node
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Optional
operator|<
name|uint64_t
operator|>
name|getProfileCountFromFreq
argument_list|(
argument|const Function&F
argument_list|,
argument|uint64_t Freq
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|setBlockFreq
parameter_list|(
specifier|const
name|BlockNode
modifier|&
name|Node
parameter_list|,
name|uint64_t
name|Freq
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|raw_ostream
modifier|&
name|printBlockFreq
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|BlockNode
operator|&
name|Node
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|raw_ostream
modifier|&
name|printBlockFreq
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|BlockFrequency
operator|&
name|Freq
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|uint64_t
name|getEntryFreq
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|Freqs
operator|.
name|empty
argument_list|()
argument_list|)
block|;
return|return
name|Freqs
index|[
literal|0
index|]
operator|.
name|Integer
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Virtual destructor.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Need a virtual destructor to mask the compiler warning about
end_comment

begin_comment
comment|/// getBlockName().
end_comment

begin_expr_stmt
name|virtual
operator|~
name|BlockFrequencyInfoImplBase
argument_list|()
block|{}
end_expr_stmt

begin_decl_stmt
unit|};
name|namespace
name|bfi_detail
block|{
name|template
operator|<
name|class
name|BlockT
operator|>
expr|struct
name|TypeMap
block|{}
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|TypeMap
operator|<
name|BasicBlock
operator|>
block|{
typedef|typedef
name|BasicBlock
name|BlockT
typedef|;
typedef|typedef
name|Function
name|FunctionT
typedef|;
typedef|typedef
name|BranchProbabilityInfo
name|BranchProbabilityInfoT
typedef|;
typedef|typedef
name|Loop
name|LoopT
typedef|;
typedef|typedef
name|LoopInfo
name|LoopInfoT
typedef|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|TypeMap
operator|<
name|MachineBasicBlock
operator|>
block|{
typedef|typedef
name|MachineBasicBlock
name|BlockT
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|MachineFunction
name|FunctionT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|MachineBranchProbabilityInfo
name|BranchProbabilityInfoT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|MachineLoop
name|LoopT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|MachineLoopInfo
name|LoopInfoT
typedef|;
end_typedef

begin_comment
unit|};
comment|/// \brief Get the name of a MachineBasicBlock.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Get the name of a MachineBasicBlock.  It's templated so that including from
end_comment

begin_comment
comment|/// CodeGen is unnecessary (that would be a layering issue).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is used mainly for debug output.  The name is similar to
end_comment

begin_comment
comment|/// MachineBasicBlock::getFullName(), but skips the name of the function.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|BlockT
operator|>
name|std
operator|::
name|string
name|getBlockName
argument_list|(
argument|const BlockT *BB
argument_list|)
block|{
name|assert
argument_list|(
name|BB
operator|&&
literal|"Unexpected nullptr"
argument_list|)
block|;
name|auto
name|MachineName
operator|=
literal|"BB"
operator|+
name|Twine
argument_list|(
name|BB
operator|->
name|getNumber
argument_list|()
argument_list|)
block|;
if|if
condition|(
name|BB
operator|->
name|getBasicBlock
argument_list|()
condition|)
return|return
operator|(
name|MachineName
operator|+
literal|"["
operator|+
name|BB
operator|->
name|getName
argument_list|()
operator|+
literal|"]"
operator|)
operator|.
name|str
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|MachineName
operator|.
name|str
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// \brief Get the name of a BasicBlock.
end_comment

begin_expr_stmt
unit|template
operator|<
operator|>
specifier|inline
name|std
operator|::
name|string
name|getBlockName
argument_list|(
argument|const BasicBlock *BB
argument_list|)
block|{
name|assert
argument_list|(
name|BB
operator|&&
literal|"Unexpected nullptr"
argument_list|)
block|;
return|return
name|BB
operator|->
name|getName
argument_list|()
operator|.
name|str
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Graph of irreducible control flow.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This graph is used for determining the SCCs in a loop (or top-level
end_comment

begin_comment
comment|/// function) that has irreducible control flow.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// During the block frequency algorithm, the local graphs are defined in a
end_comment

begin_comment
comment|/// light-weight way, deferring to the \a BasicBlock or \a MachineBasicBlock
end_comment

begin_comment
comment|/// graphs for most edges, but getting others from \a LoopData::ExitMap.  The
end_comment

begin_comment
comment|/// latter only has successor information.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \a IrreducibleGraph makes this graph explicit.  It's in a form that can use
end_comment

begin_comment
comment|/// \a GraphTraits (so that \a analyzeIrreducible() can use \a scc_iterator),
end_comment

begin_comment
comment|/// and it explicitly lists predecessors and successors.  The initialization
end_comment

begin_comment
comment|/// that relies on \c MachineBasicBlock is defined in the header.
end_comment

begin_struct
struct|struct
name|IrreducibleGraph
block|{
typedef|typedef
name|BlockFrequencyInfoImplBase
name|BFIBase
typedef|;
name|BFIBase
modifier|&
name|BFI
decl_stmt|;
typedef|typedef
name|BFIBase
operator|::
name|BlockNode
name|BlockNode
expr_stmt|;
struct|struct
name|IrrNode
block|{
name|BlockNode
name|Node
decl_stmt|;
name|unsigned
name|NumIn
decl_stmt|;
name|std
operator|::
name|deque
operator|<
specifier|const
name|IrrNode
operator|*
operator|>
name|Edges
expr_stmt|;
name|IrrNode
argument_list|(
specifier|const
name|BlockNode
operator|&
name|Node
argument_list|)
operator|:
name|Node
argument_list|(
name|Node
argument_list|)
operator|,
name|NumIn
argument_list|(
literal|0
argument_list|)
block|{}
typedef|typedef
name|std
operator|::
name|deque
operator|<
specifier|const
name|IrrNode
operator|*
operator|>
operator|::
name|const_iterator
name|iterator
expr_stmt|;
name|iterator
name|pred_begin
argument_list|()
specifier|const
block|{
return|return
name|Edges
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|succ_begin
argument_list|()
specifier|const
block|{
return|return
name|Edges
operator|.
name|begin
argument_list|()
operator|+
name|NumIn
return|;
block|}
name|iterator
name|pred_end
argument_list|()
specifier|const
block|{
return|return
name|succ_begin
argument_list|()
return|;
block|}
name|iterator
name|succ_end
argument_list|()
specifier|const
block|{
return|return
name|Edges
operator|.
name|end
argument_list|()
return|;
block|}
block|}
struct|;
name|BlockNode
name|Start
decl_stmt|;
specifier|const
name|IrrNode
modifier|*
name|StartIrr
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|IrrNode
operator|>
name|Nodes
expr_stmt|;
name|SmallDenseMap
operator|<
name|uint32_t
operator|,
name|IrrNode
operator|*
operator|,
literal|4
operator|>
name|Lookup
expr_stmt|;
comment|/// \brief Construct an explicit graph containing irreducible control flow.
comment|///
comment|/// Construct an explicit graph of the control flow in \c OuterLoop (or the
comment|/// top-level function, if \c OuterLoop is \c nullptr).  Uses \c
comment|/// addBlockEdges to add block successors that have not been packaged into
comment|/// loops.
comment|///
comment|/// \a BlockFrequencyInfoImpl::computeIrreducibleMass() is the only expected
comment|/// user of this.
name|template
operator|<
name|class
name|BlockEdgesAdder
operator|>
name|IrreducibleGraph
argument_list|(
argument|BFIBase&BFI
argument_list|,
argument|const BFIBase::LoopData *OuterLoop
argument_list|,
argument|BlockEdgesAdder addBlockEdges
argument_list|)
operator|:
name|BFI
argument_list|(
name|BFI
argument_list|)
operator|,
name|StartIrr
argument_list|(
argument|nullptr
argument_list|)
block|{
name|initialize
argument_list|(
name|OuterLoop
argument_list|,
name|addBlockEdges
argument_list|)
block|;   }
name|template
operator|<
name|class
name|BlockEdgesAdder
operator|>
name|void
name|initialize
argument_list|(
argument|const BFIBase::LoopData *OuterLoop
argument_list|,
argument|BlockEdgesAdder addBlockEdges
argument_list|)
expr_stmt|;
name|void
name|addNodesInLoop
argument_list|(
specifier|const
name|BFIBase
operator|::
name|LoopData
operator|&
name|OuterLoop
argument_list|)
decl_stmt|;
name|void
name|addNodesInFunction
parameter_list|()
function_decl|;
name|void
name|addNode
parameter_list|(
specifier|const
name|BlockNode
modifier|&
name|Node
parameter_list|)
block|{
name|Nodes
operator|.
name|emplace_back
argument_list|(
name|Node
argument_list|)
expr_stmt|;
name|BFI
operator|.
name|Working
index|[
name|Node
operator|.
name|Index
index|]
operator|.
name|getMass
argument_list|()
operator|=
name|BlockMass
operator|::
name|getEmpty
argument_list|()
expr_stmt|;
block|}
name|void
name|indexNodes
parameter_list|()
function_decl|;
name|template
operator|<
name|class
name|BlockEdgesAdder
operator|>
name|void
name|addEdges
argument_list|(
argument|const BlockNode&Node
argument_list|,
argument|const BFIBase::LoopData *OuterLoop
argument_list|,
argument|BlockEdgesAdder addBlockEdges
argument_list|)
expr_stmt|;
name|void
name|addEdge
argument_list|(
name|IrrNode
operator|&
name|Irr
argument_list|,
specifier|const
name|BlockNode
operator|&
name|Succ
argument_list|,
specifier|const
name|BFIBase
operator|::
name|LoopData
operator|*
name|OuterLoop
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|template
operator|<
name|class
name|BlockEdgesAdder
operator|>
name|void
name|IrreducibleGraph
operator|::
name|initialize
argument_list|(
argument|const BFIBase::LoopData *OuterLoop
argument_list|,
argument|BlockEdgesAdder addBlockEdges
argument_list|)
block|{
if|if
condition|(
name|OuterLoop
condition|)
block|{
name|addNodesInLoop
argument_list|(
operator|*
name|OuterLoop
argument_list|)
expr_stmt|;
for|for
control|(
name|auto
name|N
range|:
name|OuterLoop
operator|->
name|Nodes
control|)
name|addEdges
argument_list|(
name|N
argument_list|,
name|OuterLoop
argument_list|,
name|addBlockEdges
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_else
else|else
block|{
name|addNodesInFunction
argument_list|()
expr_stmt|;
for|for
control|(
name|uint32_t
name|Index
init|=
literal|0
init|;
name|Index
operator|<
name|BFI
operator|.
name|Working
operator|.
name|size
argument_list|()
condition|;
operator|++
name|Index
control|)
name|addEdges
argument_list|(
name|Index
argument_list|,
name|OuterLoop
argument_list|,
name|addBlockEdges
argument_list|)
expr_stmt|;
block|}
end_else

begin_expr_stmt
name|StartIrr
operator|=
name|Lookup
index|[
name|Start
operator|.
name|Index
index|]
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|} template
operator|<
name|class
name|BlockEdgesAdder
operator|>
name|void
name|IrreducibleGraph
operator|::
name|addEdges
argument_list|(
argument|const BlockNode&Node
argument_list|,
argument|const BFIBase::LoopData *OuterLoop
argument_list|,
argument|BlockEdgesAdder addBlockEdges
argument_list|)
block|{
name|auto
name|L
operator|=
name|Lookup
operator|.
name|find
argument_list|(
name|Node
operator|.
name|Index
argument_list|)
block|;
if|if
condition|(
name|L
operator|==
name|Lookup
operator|.
name|end
argument_list|()
condition|)
return|return;
name|IrrNode
operator|&
name|Irr
operator|=
operator|*
name|L
operator|->
name|second
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
specifier|auto
modifier|&
name|Working
init|=
name|BFI
operator|.
name|Working
index|[
name|Node
operator|.
name|Index
index|]
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|Working
operator|.
name|isAPackage
argument_list|()
condition|)
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|I
range|:
name|Working
operator|.
name|Loop
operator|->
name|Exits
control|)
name|addEdge
argument_list|(
name|Irr
argument_list|,
name|I
operator|.
name|first
argument_list|,
name|OuterLoop
argument_list|)
expr_stmt|;
else|else
name|addBlockEdges
argument_list|(
operator|*
name|this
argument_list|,
name|Irr
argument_list|,
name|OuterLoop
argument_list|)
expr_stmt|;
end_if

begin_comment
unit|} }
comment|/// \brief Shared implementation for block frequency analysis.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is a shared implementation of BlockFrequencyInfo and
end_comment

begin_comment
comment|/// MachineBlockFrequencyInfo, and calculates the relative frequencies of
end_comment

begin_comment
comment|/// blocks.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// LoopInfo defines a loop as a "non-trivial" SCC dominated by a single block,
end_comment

begin_comment
comment|/// which is called the header.  A given loop, L, can have sub-loops, which are
end_comment

begin_comment
comment|/// loops within the subgraph of L that exclude its header.  (A "trivial" SCC
end_comment

begin_comment
comment|/// consists of a single block that does not have a self-edge.)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In addition to loops, this algorithm has limited support for irreducible
end_comment

begin_comment
comment|/// SCCs, which are SCCs with multiple entry blocks.  Irreducible SCCs are
end_comment

begin_comment
comment|/// discovered on they fly, and modelled as loops with multiple headers.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The headers of irreducible sub-SCCs consist of its entry blocks and all
end_comment

begin_comment
comment|/// nodes that are targets of a backedge within it (excluding backedges within
end_comment

begin_comment
comment|/// true sub-loops).  Block frequency calculations act as if a block is
end_comment

begin_comment
comment|/// inserted that intercepts all the edges to the headers.  All backedges and
end_comment

begin_comment
comment|/// entries point to this block.  Its successors are the headers, which split
end_comment

begin_comment
comment|/// the frequency evenly.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This algorithm leverages BlockMass and ScaledNumber to maintain precision,
end_comment

begin_comment
comment|/// separates mass distribution from loop scaling, and dithers to eliminate
end_comment

begin_comment
comment|/// probability mass loss.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The implementation is split between BlockFrequencyInfoImpl, which knows the
end_comment

begin_comment
comment|/// type of graph being modelled (BasicBlock vs. MachineBasicBlock), and
end_comment

begin_comment
comment|/// BlockFrequencyInfoImplBase, which doesn't.  The base class uses \a
end_comment

begin_comment
comment|/// BlockNode, a wrapper around a uint32_t.  BlockNode is numbered from 0 in
end_comment

begin_comment
comment|/// reverse-post order.  This gives two advantages:  it's easy to compare the
end_comment

begin_comment
comment|/// relative ordering of two nodes, and maps keyed on BlockT can be represented
end_comment

begin_comment
comment|/// by vectors.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This algorithm is O(V+E), unless there is irreducible control flow, in
end_comment

begin_comment
comment|/// which case it's O(V*E) in the worst case.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These are the main stages:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///  0. Reverse post-order traversal (\a initializeRPOT()).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     Run a single post-order traversal and save it (in reverse) in RPOT.
end_comment

begin_comment
comment|///     All other stages make use of this ordering.  Save a lookup from BlockT
end_comment

begin_comment
comment|///     to BlockNode (the index into RPOT) in Nodes.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///  1. Loop initialization (\a initializeLoops()).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     Translate LoopInfo/MachineLoopInfo into a form suitable for the rest of
end_comment

begin_comment
comment|///     the algorithm.  In particular, store the immediate members of each loop
end_comment

begin_comment
comment|///     in reverse post-order.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///  2. Calculate mass and scale in loops (\a computeMassInLoops()).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     For each loop (bottom-up), distribute mass through the DAG resulting
end_comment

begin_comment
comment|///     from ignoring backedges and treating sub-loops as a single pseudo-node.
end_comment

begin_comment
comment|///     Track the backedge mass distributed to the loop header, and use it to
end_comment

begin_comment
comment|///     calculate the loop scale (number of loop iterations).  Immediate
end_comment

begin_comment
comment|///     members that represent sub-loops will already have been visited and
end_comment

begin_comment
comment|///     packaged into a pseudo-node.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     Distributing mass in a loop is a reverse-post-order traversal through
end_comment

begin_comment
comment|///     the loop.  Start by assigning full mass to the Loop header.  For each
end_comment

begin_comment
comment|///     node in the loop:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///         - Fetch and categorize the weight distribution for its successors.
end_comment

begin_comment
comment|///           If this is a packaged-subloop, the weight distribution is stored
end_comment

begin_comment
comment|///           in \a LoopData::Exits.  Otherwise, fetch it from
end_comment

begin_comment
comment|///           BranchProbabilityInfo.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///         - Each successor is categorized as \a Weight::Local, a local edge
end_comment

begin_comment
comment|///           within the current loop, \a Weight::Backedge, a backedge to the
end_comment

begin_comment
comment|///           loop header, or \a Weight::Exit, any successor outside the loop.
end_comment

begin_comment
comment|///           The weight, the successor, and its category are stored in \a
end_comment

begin_comment
comment|///           Distribution.  There can be multiple edges to each successor.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///         - If there's a backedge to a non-header, there's an irreducible SCC.
end_comment

begin_comment
comment|///           The usual flow is temporarily aborted.  \a
end_comment

begin_comment
comment|///           computeIrreducibleMass() finds the irreducible SCCs within the
end_comment

begin_comment
comment|///           loop, packages them up, and restarts the flow.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///         - Normalize the distribution:  scale weights down so that their sum
end_comment

begin_comment
comment|///           is 32-bits, and coalesce multiple edges to the same node.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///         - Distribute the mass accordingly, dithering to minimize mass loss,
end_comment

begin_comment
comment|///           as described in \a distributeMass().
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     In the case of irreducible loops, instead of a single loop header,
end_comment

begin_comment
comment|///     there will be several. The computation of backedge masses is similar
end_comment

begin_comment
comment|///     but instead of having a single backedge mass, there will be one
end_comment

begin_comment
comment|///     backedge per loop header. In these cases, each backedge will carry
end_comment

begin_comment
comment|///     a mass proportional to the edge weights along the corresponding
end_comment

begin_comment
comment|///     path.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     At the end of propagation, the full mass assigned to the loop will be
end_comment

begin_comment
comment|///     distributed among the loop headers proportionally according to the
end_comment

begin_comment
comment|///     mass flowing through their backedges.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     Finally, calculate the loop scale from the accumulated backedge mass.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///  3. Distribute mass in the function (\a computeMassInFunction()).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     Finally, distribute mass through the DAG resulting from packaging all
end_comment

begin_comment
comment|///     loops in the function.  This uses the same algorithm as distributing
end_comment

begin_comment
comment|///     mass in a loop, except that there are no exit or backedge edges.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///  4. Unpackage loops (\a unwrapLoops()).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     Initialize each block's frequency to a floating point representation of
end_comment

begin_comment
comment|///     its mass.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     Visit loops top-down, scaling the frequencies of its immediate members
end_comment

begin_comment
comment|///     by the loop's pseudo-node's frequency.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///  5. Convert frequencies to a 64-bit range (\a finalizeMetrics()).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     Using the min and max frequencies as a guide, translate floating point
end_comment

begin_comment
comment|///     frequencies to an appropriate range in uint64_t.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// It has some known flaws.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   - The model of irreducible control flow is a rough approximation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     Modelling irreducible control flow exactly involves setting up and
end_comment

begin_comment
comment|///     solving a group of infinite geometric series.  Such precision is
end_comment

begin_comment
comment|///     unlikely to be worthwhile, since most of our algorithms give up on
end_comment

begin_comment
comment|///     irreducible control flow anyway.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     Nevertheless, we might find that we need to get closer.  Here's a sort
end_comment

begin_comment
comment|///     of TODO list for the model with diminishing returns, to be completed as
end_comment

begin_comment
comment|///     necessary.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///       - The headers for the \a LoopData representing an irreducible SCC
end_comment

begin_comment
comment|///         include non-entry blocks.  When these extra blocks exist, they
end_comment

begin_comment
comment|///         indicate a self-contained irreducible sub-SCC.  We could treat them
end_comment

begin_comment
comment|///         as sub-loops, rather than arbitrarily shoving the problematic
end_comment

begin_comment
comment|///         blocks into the headers of the main irreducible SCC.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///       - Entry frequencies are assumed to be evenly split between the
end_comment

begin_comment
comment|///         headers of a given irreducible SCC, which is the only option if we
end_comment

begin_comment
comment|///         need to compute mass in the SCC before its parent loop.  Instead,
end_comment

begin_comment
comment|///         we could partially compute mass in the parent loop, and stop when
end_comment

begin_comment
comment|///         we get to the SCC.  Here, we have the correct ratio of entry
end_comment

begin_comment
comment|///         masses, which we can use to adjust their relative frequencies.
end_comment

begin_comment
comment|///         Compute mass in the SCC, and then continue propagation in the
end_comment

begin_comment
comment|///         parent.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///       - We can propagate mass iteratively through the SCC, for some fixed
end_comment

begin_comment
comment|///         number of iterations.  Each iteration starts by assigning the entry
end_comment

begin_comment
comment|///         blocks their backedge mass from the prior iteration.  The final
end_comment

begin_comment
comment|///         mass for each block (and each exit, and the total backedge mass
end_comment

begin_comment
comment|///         used for computing loop scale) is the sum of all iterations.
end_comment

begin_comment
comment|///         (Running this until fixed point would "solve" the geometric
end_comment

begin_comment
comment|///         series by simulation.)
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|BT
operator|>
name|class
name|BlockFrequencyInfoImpl
operator|:
name|BlockFrequencyInfoImplBase
block|{
typedef|typedef
name|typename
name|bfi_detail
operator|::
name|TypeMap
operator|<
name|BT
operator|>
operator|::
name|BlockT
name|BlockT
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|bfi_detail
operator|::
name|TypeMap
operator|<
name|BT
operator|>
operator|::
name|FunctionT
name|FunctionT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|bfi_detail
operator|::
name|TypeMap
operator|<
name|BT
operator|>
operator|::
name|BranchProbabilityInfoT
name|BranchProbabilityInfoT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|bfi_detail
operator|::
name|TypeMap
operator|<
name|BT
operator|>
operator|::
name|LoopT
name|LoopT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|bfi_detail
operator|::
name|TypeMap
operator|<
name|BT
operator|>
operator|::
name|LoopInfoT
name|LoopInfoT
expr_stmt|;
end_typedef

begin_comment
comment|// This is part of a workaround for a GCC 4.7 crash on lambdas.
end_comment

begin_macro
name|friend
end_macro

begin_expr_stmt
unit|struct
name|bfi_detail
operator|::
name|BlockEdgesAdder
operator|<
name|BT
operator|>
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|GraphTraits
operator|<
specifier|const
name|BlockT
operator|*
operator|>
name|Successor
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|GraphTraits
operator|<
name|Inverse
operator|<
specifier|const
name|BlockT
operator|*
operator|>>
name|Predecessor
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|const
name|BranchProbabilityInfoT
modifier|*
name|BPI
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|LoopInfoT
modifier|*
name|LI
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|FunctionT
modifier|*
name|F
decl_stmt|;
end_decl_stmt

begin_comment
comment|// All blocks in reverse postorder.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
specifier|const
name|BlockT
operator|*
operator|>
name|RPOT
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DenseMap
operator|<
specifier|const
name|BlockT
operator|*
operator|,
name|BlockNode
operator|>
name|Nodes
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|std
operator|::
name|vector
operator|<
specifier|const
name|BlockT
operator|*
operator|>
operator|::
name|const_iterator
name|rpot_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|rpot_iterator
name|rpot_begin
argument_list|()
specifier|const
block|{
return|return
name|RPOT
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|rpot_iterator
name|rpot_end
argument_list|()
specifier|const
block|{
return|return
name|RPOT
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|size_t
name|getIndex
argument_list|(
specifier|const
name|rpot_iterator
operator|&
name|I
argument_list|)
decl|const
block|{
return|return
name|I
operator|-
name|rpot_begin
argument_list|()
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|BlockNode
name|getNode
argument_list|(
specifier|const
name|rpot_iterator
operator|&
name|I
argument_list|)
decl|const
block|{
return|return
name|BlockNode
argument_list|(
name|getIndex
argument_list|(
name|I
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|BlockNode
name|getNode
argument_list|(
specifier|const
name|BlockT
operator|*
name|BB
argument_list|)
decl|const
block|{
return|return
name|Nodes
operator|.
name|lookup
argument_list|(
name|BB
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|const
name|BlockT
modifier|*
name|getBlock
argument_list|(
specifier|const
name|BlockNode
operator|&
name|Node
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Node
operator|.
name|Index
operator|<
name|RPOT
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|RPOT
index|[
name|Node
operator|.
name|Index
index|]
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Run (and save) a post-order traversal.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Saves a reverse post-order traversal of all the nodes in \a F.
end_comment

begin_function_decl
name|void
name|initializeRPOT
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Initialize loop data.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Build up \a Loops using \a LoopInfo.  \a LoopInfo gives us a mapping from
end_comment

begin_comment
comment|/// each block to the deepest loop it's in, but we need the inverse.  For each
end_comment

begin_comment
comment|/// loop, we store in reverse post-order its "immediate" members, defined as
end_comment

begin_comment
comment|/// the header, the headers of immediate sub-loops, and all other blocks in
end_comment

begin_comment
comment|/// the loop that are not in sub-loops.
end_comment

begin_function_decl
name|void
name|initializeLoops
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Propagate to a block's successors.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In the context of distributing mass through \c OuterLoop, divide the mass
end_comment

begin_comment
comment|/// currently assigned to \c Node between its successors.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return \c true unless there's an irreducible backedge.
end_comment

begin_function_decl
name|bool
name|propagateMassToSuccessors
parameter_list|(
name|LoopData
modifier|*
name|OuterLoop
parameter_list|,
specifier|const
name|BlockNode
modifier|&
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Compute mass in a particular loop.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Assign mass to \c Loop's header, and then for each block in \c Loop in
end_comment

begin_comment
comment|/// reverse post-order, distribute mass to its successors.  Only visits nodes
end_comment

begin_comment
comment|/// that have not been packaged into sub-loops.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \pre \a computeMassInLoop() has been called for each subloop of \c Loop.
end_comment

begin_comment
comment|/// \return \c true unless there's an irreducible backedge.
end_comment

begin_function_decl
name|bool
name|computeMassInLoop
parameter_list|(
name|LoopData
modifier|&
name|Loop
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Try to compute mass in the top-level function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Assign mass to the entry block, and then for each block in reverse
end_comment

begin_comment
comment|/// post-order, distribute mass to its successors.  Skips nodes that have
end_comment

begin_comment
comment|/// been packaged into loops.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \pre \a computeMassInLoops() has been called.
end_comment

begin_comment
comment|/// \return \c true unless there's an irreducible backedge.
end_comment

begin_function_decl
name|bool
name|tryToComputeMassInFunction
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Compute mass in (and package up) irreducible SCCs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Find the irreducible SCCs in \c OuterLoop, add them to \a Loops (in front
end_comment

begin_comment
comment|/// of \c Insert), and call \a computeMassInLoop() on each of them.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If \c OuterLoop is \c nullptr, it refers to the top-level function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \pre \a computeMassInLoop() has been called for each subloop of \c
end_comment

begin_comment
comment|/// OuterLoop.
end_comment

begin_comment
comment|/// \pre \c Insert points at the last loop successfully processed by \a
end_comment

begin_comment
comment|/// computeMassInLoop().
end_comment

begin_comment
comment|/// \pre \c OuterLoop has irreducible SCCs.
end_comment

begin_decl_stmt
name|void
name|computeIrreducibleMass
argument_list|(
name|LoopData
operator|*
name|OuterLoop
argument_list|,
name|std
operator|::
name|list
operator|<
name|LoopData
operator|>
operator|::
name|iterator
name|Insert
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Compute mass in all loops.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For each loop bottom-up, call \a computeMassInLoop().
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \a computeMassInLoop() aborts (and returns \c false) on loops that
end_comment

begin_comment
comment|/// contain a irreducible sub-SCCs.  Use \a computeIrreducibleMass() and then
end_comment

begin_comment
comment|/// re-enter \a computeMassInLoop().
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \post \a computeMassInLoop() has returned \c true for every loop.
end_comment

begin_function_decl
name|void
name|computeMassInLoops
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Compute mass in the top-level function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Uses \a tryToComputeMassInFunction() and \a computeIrreducibleMass() to
end_comment

begin_comment
comment|/// compute mass in the top-level function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \post \a tryToComputeMassInFunction() has returned \c true.
end_comment

begin_function_decl
name|void
name|computeMassInFunction
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|std
operator|::
name|string
name|getBlockName
argument_list|(
argument|const BlockNode&Node
argument_list|)
specifier|const
name|override
block|{
return|return
name|bfi_detail
operator|::
name|getBlockName
argument_list|(
name|getBlock
argument_list|(
name|Node
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_expr_stmt
specifier|const
name|FunctionT
operator|*
name|getFunction
argument_list|()
specifier|const
block|{
return|return
name|F
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|calculate
parameter_list|(
specifier|const
name|FunctionT
modifier|&
name|F
parameter_list|,
specifier|const
name|BranchProbabilityInfoT
modifier|&
name|BPI
parameter_list|,
specifier|const
name|LoopInfoT
modifier|&
name|LI
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|BlockFrequencyInfoImpl
argument_list|()
operator|:
name|BPI
argument_list|(
name|nullptr
argument_list|)
operator|,
name|LI
argument_list|(
name|nullptr
argument_list|)
operator|,
name|F
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|using
name|BlockFrequencyInfoImplBase
operator|::
name|getEntryFreq
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|BlockFrequency
name|getBlockFreq
argument_list|(
specifier|const
name|BlockT
operator|*
name|BB
argument_list|)
decl|const
block|{
return|return
name|BlockFrequencyInfoImplBase
operator|::
name|getBlockFreq
argument_list|(
name|getNode
argument_list|(
name|BB
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|Optional
operator|<
name|uint64_t
operator|>
name|getBlockProfileCount
argument_list|(
argument|const Function&F
argument_list|,
argument|const BlockT *BB
argument_list|)
specifier|const
block|{
return|return
name|BlockFrequencyInfoImplBase
operator|::
name|getBlockProfileCount
argument_list|(
name|F
argument_list|,
name|getNode
argument_list|(
name|BB
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|Optional
operator|<
name|uint64_t
operator|>
name|getProfileCountFromFreq
argument_list|(
argument|const Function&F
argument_list|,
argument|uint64_t Freq
argument_list|)
specifier|const
block|{
return|return
name|BlockFrequencyInfoImplBase
operator|::
name|getProfileCountFromFreq
argument_list|(
name|F
argument_list|,
name|Freq
argument_list|)
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|setBlockFreq
parameter_list|(
specifier|const
name|BlockT
modifier|*
name|BB
parameter_list|,
name|uint64_t
name|Freq
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|Scaled64
name|getFloatingBlockFreq
argument_list|(
specifier|const
name|BlockT
operator|*
name|BB
argument_list|)
decl|const
block|{
return|return
name|BlockFrequencyInfoImplBase
operator|::
name|getFloatingBlockFreq
argument_list|(
name|getNode
argument_list|(
name|BB
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
specifier|const
name|BranchProbabilityInfoT
operator|&
name|getBPI
argument_list|()
specifier|const
block|{
return|return
operator|*
name|BPI
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Print the frequencies for the current function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Prints the frequencies for the blocks in the current function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Blocks are printed in the natural iteration order of the function, rather
end_comment

begin_comment
comment|/// than reverse post-order.  This provides two advantages:  writing -analyze
end_comment

begin_comment
comment|/// tests is easier (since blocks come out in source order), and even
end_comment

begin_comment
comment|/// unreachable blocks are printed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \a BlockFrequencyInfoImplBase::print() only knows reverse post-order, so
end_comment

begin_comment
comment|/// we need to override it here.
end_comment

begin_decl_stmt
name|raw_ostream
modifier|&
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|using
name|BlockFrequencyInfoImplBase
operator|::
name|dump
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|BlockFrequencyInfoImplBase
operator|::
name|printBlockFreq
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|raw_ostream
modifier|&
name|printBlockFreq
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|BlockT
operator|*
name|BB
argument_list|)
decl|const
block|{
return|return
name|BlockFrequencyInfoImplBase
operator|::
name|printBlockFreq
argument_list|(
name|OS
argument_list|,
name|getNode
argument_list|(
name|BB
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|BT
operator|>
name|void
name|BlockFrequencyInfoImpl
operator|<
name|BT
operator|>
operator|::
name|calculate
argument_list|(
argument|const FunctionT&F
argument_list|,
argument|const BranchProbabilityInfoT&BPI
argument_list|,
argument|const LoopInfoT&LI
argument_list|)
block|{
comment|// Save the parameters.
name|this
operator|->
name|BPI
operator|=
operator|&
name|BPI
block|;
name|this
operator|->
name|LI
operator|=
operator|&
name|LI
block|;
name|this
operator|->
name|F
operator|=
operator|&
name|F
block|;
comment|// Clean up left-over data structures.
name|BlockFrequencyInfoImplBase
operator|::
name|clear
argument_list|()
block|;
name|RPOT
operator|.
name|clear
argument_list|()
block|;
name|Nodes
operator|.
name|clear
argument_list|()
block|;
comment|// Initialize.
name|DEBUG
argument_list|(
name|dbgs
argument_list|()
operator|<<
literal|"\nblock-frequency: "
operator|<<
name|F
operator|.
name|getName
argument_list|()
operator|<<
literal|"\n================="
operator|<<
name|std
operator|::
name|string
argument_list|(
name|F
operator|.
name|getName
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|'='
argument_list|)
operator|<<
literal|"\n"
argument_list|)
block|;
name|initializeRPOT
argument_list|()
block|;
name|initializeLoops
argument_list|()
block|;
comment|// Visit loops in post-order to find the local mass distribution, and then do
comment|// the full function.
name|computeMassInLoops
argument_list|()
block|;
name|computeMassInFunction
argument_list|()
block|;
name|unwrapLoops
argument_list|()
block|;
name|finalizeMetrics
argument_list|()
block|; }
name|template
operator|<
name|class
name|BT
operator|>
name|void
name|BlockFrequencyInfoImpl
operator|<
name|BT
operator|>
operator|::
name|setBlockFreq
argument_list|(
argument|const BlockT *BB
argument_list|,
argument|uint64_t Freq
argument_list|)
block|{
if|if
condition|(
name|Nodes
operator|.
name|count
argument_list|(
name|BB
argument_list|)
condition|)
name|BlockFrequencyInfoImplBase
operator|::
name|setBlockFreq
argument_list|(
name|getNode
argument_list|(
name|BB
argument_list|)
argument_list|,
name|Freq
argument_list|)
expr_stmt|;
else|else
block|{
comment|// If BB is a newly added block after BFI is done, we need to create a new
comment|// BlockNode for it assigned with a new index. The index can be determined
comment|// by the size of Freqs.
name|BlockNode
name|NewNode
argument_list|(
name|Freqs
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|Nodes
index|[
name|BB
index|]
operator|=
name|NewNode
expr_stmt|;
name|Freqs
operator|.
name|emplace_back
argument_list|()
expr_stmt|;
name|BlockFrequencyInfoImplBase
operator|::
name|setBlockFreq
argument_list|(
name|NewNode
argument_list|,
name|Freq
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|BT
operator|>
name|void
name|BlockFrequencyInfoImpl
operator|<
name|BT
operator|>
operator|::
name|initializeRPOT
argument_list|()
block|{
specifier|const
name|BlockT
operator|*
name|Entry
operator|=
operator|&
name|F
operator|->
name|front
argument_list|()
block|;
name|RPOT
operator|.
name|reserve
argument_list|(
name|F
operator|->
name|size
argument_list|()
argument_list|)
block|;
name|std
operator|::
name|copy
argument_list|(
name|po_begin
argument_list|(
name|Entry
argument_list|)
argument_list|,
name|po_end
argument_list|(
name|Entry
argument_list|)
argument_list|,
name|std
operator|::
name|back_inserter
argument_list|(
name|RPOT
argument_list|)
argument_list|)
block|;
name|std
operator|::
name|reverse
argument_list|(
name|RPOT
operator|.
name|begin
argument_list|()
argument_list|,
name|RPOT
operator|.
name|end
argument_list|()
argument_list|)
block|;
name|assert
argument_list|(
name|RPOT
operator|.
name|size
argument_list|()
operator|-
literal|1
operator|<=
name|BlockNode
operator|::
name|getMaxIndex
argument_list|()
operator|&&
literal|"More nodes in function than Block Frequency Info supports"
argument_list|)
block|;
name|DEBUG
argument_list|(
name|dbgs
argument_list|()
operator|<<
literal|"reverse-post-order-traversal\n"
argument_list|)
block|;
for|for
control|(
name|rpot_iterator
name|I
init|=
name|rpot_begin
argument_list|()
init|,
name|E
init|=
name|rpot_end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
name|BlockNode
name|Node
init|=
name|getNode
argument_list|(
name|I
argument_list|)
decl_stmt|;
name|DEBUG
argument_list|(
name|dbgs
argument_list|()
operator|<<
literal|" - "
operator|<<
name|getIndex
argument_list|(
name|I
argument_list|)
operator|<<
literal|": "
operator|<<
name|getBlockName
argument_list|(
name|Node
argument_list|)
operator|<<
literal|"\n"
argument_list|)
expr_stmt|;
name|Nodes
index|[
operator|*
name|I
index|]
operator|=
name|Node
expr_stmt|;
block|}
name|Working
operator|.
name|reserve
argument_list|(
name|RPOT
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|size_t
name|Index
init|=
literal|0
init|;
name|Index
operator|<
name|RPOT
operator|.
name|size
argument_list|()
condition|;
operator|++
name|Index
control|)
name|Working
operator|.
name|emplace_back
argument_list|(
name|Index
argument_list|)
expr_stmt|;
end_for

begin_expr_stmt
name|Freqs
operator|.
name|resize
argument_list|(
name|RPOT
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|BT
operator|>
name|void
name|BlockFrequencyInfoImpl
operator|<
name|BT
operator|>
operator|::
name|initializeLoops
argument_list|()
block|{
name|DEBUG
argument_list|(
name|dbgs
argument_list|()
operator|<<
literal|"loop-detection\n"
argument_list|)
block|;
if|if
condition|(
name|LI
operator|->
name|empty
argument_list|()
condition|)
return|return;
comment|// Visit loops top down and assign them an index.
name|std
operator|::
name|deque
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|LoopT
operator|*
operator|,
name|LoopData
operator|*
operator|>>
name|Q
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
specifier|const
name|LoopT
modifier|*
name|L
range|:
operator|*
name|LI
control|)
name|Q
operator|.
name|emplace_back
argument_list|(
name|L
argument_list|,
name|nullptr
argument_list|)
expr_stmt|;
end_for

begin_while
while|while
condition|(
operator|!
name|Q
operator|.
name|empty
argument_list|()
condition|)
block|{
specifier|const
name|LoopT
modifier|*
name|Loop
init|=
name|Q
operator|.
name|front
argument_list|()
operator|.
name|first
decl_stmt|;
name|LoopData
modifier|*
name|Parent
init|=
name|Q
operator|.
name|front
argument_list|()
operator|.
name|second
decl_stmt|;
name|Q
operator|.
name|pop_front
argument_list|()
expr_stmt|;
name|BlockNode
name|Header
init|=
name|getNode
argument_list|(
name|Loop
operator|->
name|getHeader
argument_list|()
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|Header
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|Loops
operator|.
name|emplace_back
argument_list|(
name|Parent
argument_list|,
name|Header
argument_list|)
expr_stmt|;
name|Working
index|[
name|Header
operator|.
name|Index
index|]
operator|.
name|Loop
operator|=
operator|&
name|Loops
operator|.
name|back
argument_list|()
expr_stmt|;
name|DEBUG
argument_list|(
name|dbgs
argument_list|()
operator|<<
literal|" - loop = "
operator|<<
name|getBlockName
argument_list|(
name|Header
argument_list|)
operator|<<
literal|"\n"
argument_list|)
expr_stmt|;
for|for
control|(
specifier|const
name|LoopT
modifier|*
name|L
range|:
operator|*
name|Loop
control|)
name|Q
operator|.
name|emplace_back
argument_list|(
name|L
argument_list|,
operator|&
name|Loops
operator|.
name|back
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_while

begin_comment
comment|// Visit nodes in reverse post-order and add them to their deepest containing
end_comment

begin_comment
comment|// loop.
end_comment

begin_for
for|for
control|(
name|size_t
name|Index
init|=
literal|0
init|;
name|Index
operator|<
name|RPOT
operator|.
name|size
argument_list|()
condition|;
operator|++
name|Index
control|)
block|{
comment|// Loop headers have already been mostly mapped.
if|if
condition|(
name|Working
index|[
name|Index
index|]
operator|.
name|isLoopHeader
argument_list|()
condition|)
block|{
name|LoopData
modifier|*
name|ContainingLoop
init|=
name|Working
index|[
name|Index
index|]
operator|.
name|getContainingLoop
argument_list|()
decl_stmt|;
if|if
condition|(
name|ContainingLoop
condition|)
name|ContainingLoop
operator|->
name|Nodes
operator|.
name|push_back
argument_list|(
name|Index
argument_list|)
expr_stmt|;
continue|continue;
block|}
specifier|const
name|LoopT
modifier|*
name|Loop
init|=
name|LI
operator|->
name|getLoopFor
argument_list|(
name|RPOT
index|[
name|Index
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|Loop
condition|)
continue|continue;
comment|// Add this node to its containing loop's member list.
name|BlockNode
name|Header
init|=
name|getNode
argument_list|(
name|Loop
operator|->
name|getHeader
argument_list|()
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|Header
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
specifier|auto
modifier|&
name|HeaderData
init|=
name|Working
index|[
name|Header
operator|.
name|Index
index|]
decl_stmt|;
name|assert
argument_list|(
name|HeaderData
operator|.
name|isLoopHeader
argument_list|()
argument_list|)
expr_stmt|;
name|Working
index|[
name|Index
index|]
operator|.
name|Loop
operator|=
name|HeaderData
operator|.
name|Loop
expr_stmt|;
name|HeaderData
operator|.
name|Loop
operator|->
name|Nodes
operator|.
name|push_back
argument_list|(
name|Index
argument_list|)
expr_stmt|;
name|DEBUG
argument_list|(
name|dbgs
argument_list|()
operator|<<
literal|" - loop = "
operator|<<
name|getBlockName
argument_list|(
name|Header
argument_list|)
operator|<<
literal|": member = "
operator|<<
name|getBlockName
argument_list|(
name|Index
argument_list|)
operator|<<
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_for

begin_expr_stmt
unit|}  template
operator|<
name|class
name|BT
operator|>
name|void
name|BlockFrequencyInfoImpl
operator|<
name|BT
operator|>
operator|::
name|computeMassInLoops
argument_list|()
block|{
comment|// Visit loops with the deepest first, and the top-level loops last.
for|for
control|(
name|auto
name|L
init|=
name|Loops
operator|.
name|rbegin
argument_list|()
init|,
name|E
init|=
name|Loops
operator|.
name|rend
argument_list|()
init|;
name|L
operator|!=
name|E
condition|;
operator|++
name|L
control|)
block|{
if|if
condition|(
name|computeMassInLoop
argument_list|(
operator|*
name|L
argument_list|)
condition|)
continue|continue;
name|auto
name|Next
init|=
name|std
operator|::
name|next
argument_list|(
name|L
argument_list|)
decl_stmt|;
name|computeIrreducibleMass
argument_list|(
operator|&
operator|*
name|L
argument_list|,
name|L
operator|.
name|base
argument_list|()
argument_list|)
expr_stmt|;
name|L
operator|=
name|std
operator|::
name|prev
argument_list|(
name|Next
argument_list|)
expr_stmt|;
if|if
condition|(
name|computeMassInLoop
argument_list|(
operator|*
name|L
argument_list|)
condition|)
continue|continue;
name|llvm_unreachable
argument_list|(
literal|"unhandled irreducible control flow"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|BT
operator|>
name|bool
name|BlockFrequencyInfoImpl
operator|<
name|BT
operator|>
operator|::
name|computeMassInLoop
argument_list|(
argument|LoopData&Loop
argument_list|)
block|{
comment|// Compute mass in loop.
name|DEBUG
argument_list|(
name|dbgs
argument_list|()
operator|<<
literal|"compute-mass-in-loop: "
operator|<<
name|getLoopName
argument_list|(
name|Loop
argument_list|)
operator|<<
literal|"\n"
argument_list|)
block|;
if|if
condition|(
name|Loop
operator|.
name|isIrreducible
argument_list|()
condition|)
block|{
name|BlockMass
name|Remaining
init|=
name|BlockMass
operator|::
name|getFull
argument_list|()
decl_stmt|;
for|for
control|(
name|uint32_t
name|H
init|=
literal|0
init|;
name|H
operator|<
name|Loop
operator|.
name|NumHeaders
condition|;
operator|++
name|H
control|)
block|{
name|auto
operator|&
name|Mass
operator|=
name|Working
index|[
name|Loop
operator|.
name|Nodes
index|[
name|H
index|]
operator|.
name|Index
index|]
operator|.
name|getMass
argument_list|()
expr_stmt|;
name|Mass
operator|=
name|Remaining
operator|*
name|BranchProbability
argument_list|(
literal|1
argument_list|,
name|Loop
operator|.
name|NumHeaders
operator|-
name|H
argument_list|)
expr_stmt|;
name|Remaining
operator|-=
name|Mass
expr_stmt|;
block|}
end_expr_stmt

begin_for
for|for
control|(
specifier|const
name|BlockNode
modifier|&
name|M
range|:
name|Loop
operator|.
name|Nodes
control|)
if|if
condition|(
operator|!
name|propagateMassToSuccessors
argument_list|(
operator|&
name|Loop
argument_list|,
name|M
argument_list|)
condition|)
name|llvm_unreachable
argument_list|(
literal|"unhandled irreducible control flow"
argument_list|)
expr_stmt|;
end_for

begin_expr_stmt
name|adjustLoopHeaderMass
argument_list|(
name|Loop
argument_list|)
expr_stmt|;
end_expr_stmt

begin_block
unit|} else
block|{
name|Working
index|[
name|Loop
operator|.
name|getHeader
argument_list|()
operator|.
name|Index
index|]
operator|.
name|getMass
argument_list|()
operator|=
name|BlockMass
operator|::
name|getFull
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|propagateMassToSuccessors
argument_list|(
operator|&
name|Loop
argument_list|,
name|Loop
operator|.
name|getHeader
argument_list|()
argument_list|)
condition|)
name|llvm_unreachable
argument_list|(
literal|"irreducible control flow to loop header!?"
argument_list|)
expr_stmt|;
for|for
control|(
specifier|const
name|BlockNode
modifier|&
name|M
range|:
name|Loop
operator|.
name|members
argument_list|()
control|)
if|if
condition|(
operator|!
name|propagateMassToSuccessors
argument_list|(
operator|&
name|Loop
argument_list|,
name|M
argument_list|)
condition|)
comment|// Irreducible backedge.
return|return
name|false
return|;
block|}
end_block

begin_expr_stmt
name|computeLoopScale
argument_list|(
name|Loop
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|packageLoop
argument_list|(
name|Loop
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|BT
operator|>
name|bool
name|BlockFrequencyInfoImpl
operator|<
name|BT
operator|>
operator|::
name|tryToComputeMassInFunction
argument_list|()
block|{
comment|// Compute mass in function.
name|DEBUG
argument_list|(
name|dbgs
argument_list|()
operator|<<
literal|"compute-mass-in-function\n"
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|Working
operator|.
name|empty
argument_list|()
operator|&&
literal|"no blocks in function"
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|Working
index|[
literal|0
index|]
operator|.
name|isLoopHeader
argument_list|()
operator|&&
literal|"entry block is a loop header"
argument_list|)
block|;
name|Working
index|[
literal|0
index|]
operator|.
name|getMass
argument_list|()
operator|=
name|BlockMass
operator|::
name|getFull
argument_list|()
block|;
for|for
control|(
name|rpot_iterator
name|I
init|=
name|rpot_begin
argument_list|()
init|,
name|IE
init|=
name|rpot_end
argument_list|()
init|;
name|I
operator|!=
name|IE
condition|;
operator|++
name|I
control|)
block|{
comment|// Check for nodes that have been packaged.
name|BlockNode
name|Node
init|=
name|getNode
argument_list|(
name|I
argument_list|)
decl_stmt|;
if|if
condition|(
name|Working
index|[
name|Node
operator|.
name|Index
index|]
operator|.
name|isPackaged
argument_list|()
condition|)
continue|continue;
if|if
condition|(
operator|!
name|propagateMassToSuccessors
argument_list|(
name|nullptr
argument_list|,
name|Node
argument_list|)
condition|)
return|return
name|false
return|;
block|}
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|BT
operator|>
name|void
name|BlockFrequencyInfoImpl
operator|<
name|BT
operator|>
operator|::
name|computeMassInFunction
argument_list|()
block|{
if|if
condition|(
name|tryToComputeMassInFunction
argument_list|()
condition|)
return|return;
name|computeIrreducibleMass
argument_list|(
name|nullptr
argument_list|,
name|Loops
operator|.
name|begin
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|tryToComputeMassInFunction
argument_list|()
condition|)
return|return;
end_if

begin_expr_stmt
name|llvm_unreachable
argument_list|(
literal|"unhandled irreducible control flow"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/// \note This should be a lambda, but that crashes GCC 4.7.
end_comment

begin_macro
unit|namespace
name|bfi_detail
end_macro

begin_block
block|{
name|template
operator|<
name|class
name|BT
operator|>
expr|struct
name|BlockEdgesAdder
block|{
typedef|typedef
name|BT
name|BlockT
typedef|;
typedef|typedef
name|BlockFrequencyInfoImplBase
operator|::
name|LoopData
name|LoopData
expr_stmt|;
typedef|typedef
name|GraphTraits
operator|<
specifier|const
name|BlockT
operator|*
operator|>
name|Successor
expr_stmt|;
specifier|const
name|BlockFrequencyInfoImpl
operator|<
name|BT
operator|>
operator|&
name|BFI
expr_stmt|;
name|explicit
name|BlockEdgesAdder
argument_list|(
specifier|const
name|BlockFrequencyInfoImpl
operator|<
name|BT
operator|>
operator|&
name|BFI
argument_list|)
range|:
name|BFI
argument_list|(
argument|BFI
argument_list|)
block|{}
name|void
name|operator
argument_list|()
operator|(
name|IrreducibleGraph
operator|&
name|G
expr|,
name|IrreducibleGraph
operator|::
name|IrrNode
operator|&
name|Irr
expr|,
specifier|const
name|LoopData
operator|*
name|OuterLoop
operator|)
block|{
specifier|const
name|BlockT
operator|*
name|BB
operator|=
name|BFI
operator|.
name|RPOT
index|[
name|Irr
operator|.
name|Node
operator|.
name|Index
index|]
block|;
for|for
control|(
specifier|const
specifier|auto
name|Succ
range|:
name|children
operator|<
specifier|const
name|BlockT
operator|*
operator|>
operator|(
name|BB
operator|)
control|)
name|G
operator|.
name|addEdge
argument_list|(
name|Irr
argument_list|,
name|BFI
operator|.
name|getNode
argument_list|(
name|Succ
argument_list|)
argument_list|,
name|OuterLoop
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
unit|} template
operator|<
name|class
name|BT
operator|>
name|void
name|BlockFrequencyInfoImpl
operator|<
name|BT
operator|>
operator|::
name|computeIrreducibleMass
argument_list|(
argument|LoopData *OuterLoop
argument_list|,
argument|std::list<LoopData>::iterator Insert
argument_list|)
block|{
name|DEBUG
argument_list|(
argument|dbgs()<<
literal|"analyze-irreducible-in-"
argument|;         if (OuterLoop) dbgs()<<
literal|"loop: "
argument|<< getLoopName(*OuterLoop)<<
literal|"\n"
argument|;         else dbgs()<<
literal|"function\n"
argument_list|)
block|;
name|using
name|namespace
name|bfi_detail
block|;
comment|// Ideally, addBlockEdges() would be declared here as a lambda, but that
comment|// crashes GCC 4.7.
name|BlockEdgesAdder
operator|<
name|BT
operator|>
name|addBlockEdges
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|IrreducibleGraph
name|G
argument_list|(
operator|*
name|this
argument_list|,
name|OuterLoop
argument_list|,
name|addBlockEdges
argument_list|)
block|;
for|for
control|(
name|auto
operator|&
name|L
operator|:
name|analyzeIrreducible
argument_list|(
name|G
argument_list|,
name|OuterLoop
argument_list|,
name|Insert
argument_list|)
control|)
name|computeMassInLoop
argument_list|(
name|L
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|OuterLoop
condition|)
return|return;
end_if

begin_expr_stmt
name|updateLoopWithIrreducible
argument_list|(
operator|*
name|OuterLoop
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// A helper function that converts a branch probability into weight.
end_comment

begin_function
unit|inline
name|uint32_t
name|getWeightFromBranchProb
parameter_list|(
specifier|const
name|BranchProbability
name|Prob
parameter_list|)
block|{
return|return
name|Prob
operator|.
name|getNumerator
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|class
name|BT
operator|>
name|bool
name|BlockFrequencyInfoImpl
operator|<
name|BT
operator|>
operator|::
name|propagateMassToSuccessors
argument_list|(
argument|LoopData *OuterLoop
argument_list|,
argument|const BlockNode&Node
argument_list|)
block|{
name|DEBUG
argument_list|(
name|dbgs
argument_list|()
operator|<<
literal|" - node: "
operator|<<
name|getBlockName
argument_list|(
name|Node
argument_list|)
operator|<<
literal|"\n"
argument_list|)
block|;
comment|// Calculate probability for successors.
name|Distribution
name|Dist
block|;
if|if
condition|(
name|auto
operator|*
name|Loop
operator|=
name|Working
index|[
name|Node
operator|.
name|Index
index|]
operator|.
name|getPackagedLoop
argument_list|()
condition|)
block|{
name|assert
argument_list|(
name|Loop
operator|!=
name|OuterLoop
operator|&&
literal|"Cannot propagate mass in a packaged loop"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|addLoopSuccessorsToDist
argument_list|(
name|OuterLoop
argument_list|,
operator|*
name|Loop
argument_list|,
name|Dist
argument_list|)
condition|)
comment|// Irreducible backedge.
return|return
name|false
return|;
block|}
end_expr_stmt

begin_else
else|else
block|{
specifier|const
name|BlockT
modifier|*
name|BB
init|=
name|getBlock
argument_list|(
name|Node
argument_list|)
decl_stmt|;
for|for
control|(
specifier|const
specifier|auto
name|Succ
range|:
name|children
operator|<
specifier|const
name|BlockT
operator|*
operator|>
operator|(
name|BB
operator|)
control|)
if|if
condition|(
operator|!
name|addToDist
argument_list|(
name|Dist
argument_list|,
name|OuterLoop
argument_list|,
name|Node
argument_list|,
name|getNode
argument_list|(
name|Succ
argument_list|)
argument_list|,
name|getWeightFromBranchProb
argument_list|(
name|BPI
operator|->
name|getEdgeProbability
argument_list|(
name|BB
argument_list|,
name|Succ
argument_list|)
argument_list|)
argument_list|)
condition|)
comment|// Irreducible backedge.
return|return
name|false
return|;
block|}
end_else

begin_comment
comment|// Distribute mass to successors, saving exit and backedge data in the
end_comment

begin_comment
comment|// loop header.
end_comment

begin_expr_stmt
name|distributeMass
argument_list|(
name|Node
argument_list|,
name|OuterLoop
argument_list|,
name|Dist
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|BT
operator|>
name|raw_ostream
operator|&
name|BlockFrequencyInfoImpl
operator|<
name|BT
operator|>
operator|::
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|F
condition|)
return|return
name|OS
return|;
name|OS
operator|<<
literal|"block-frequency-info: "
operator|<<
name|F
operator|->
name|getName
argument_list|()
operator|<<
literal|"\n"
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
specifier|const
name|BlockT
modifier|&
name|BB
range|:
operator|*
name|F
control|)
block|{
name|OS
operator|<<
literal|" - "
operator|<<
name|bfi_detail
operator|::
name|getBlockName
argument_list|(
operator|&
name|BB
argument_list|)
operator|<<
literal|": float = "
expr_stmt|;
name|getFloatingBlockFreq
argument_list|(
operator|&
name|BB
argument_list|)
operator|.
name|print
argument_list|(
name|OS
argument_list|,
literal|5
argument_list|)
operator|<<
literal|", int = "
operator|<<
name|getBlockFreq
argument_list|(
operator|&
name|BB
argument_list|)
operator|.
name|getFrequency
argument_list|()
operator|<<
literal|"\n"
expr_stmt|;
block|}
end_for

begin_comment
comment|// Add an extra newline for readability.
end_comment

begin_expr_stmt
name|OS
operator|<<
literal|"\n"
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|OS
return|;
end_return

begin_comment
unit|}
comment|// Graph trait base class for block frequency information graph
end_comment

begin_comment
comment|// viewer.
end_comment

begin_macro
unit|enum
name|GVDAGType
end_macro

begin_block
block|{
name|GVDT_None
operator|,
name|GVDT_Fraction
operator|,
name|GVDT_Integer
operator|,
name|GVDT_Count
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|BlockFrequencyInfoT
operator|,
name|class
name|BranchProbabilityInfoT
operator|>
expr|struct
name|BFIDOTGraphTraitsBase
operator|:
name|public
name|DefaultDOTGraphTraits
block|{
name|explicit
name|BFIDOTGraphTraitsBase
argument_list|(
argument|bool isSimple = false
argument_list|)
operator|:
name|DefaultDOTGraphTraits
argument_list|(
argument|isSimple
argument_list|)
block|{}
typedef|typedef
name|GraphTraits
operator|<
name|BlockFrequencyInfoT
operator|*
operator|>
name|GTraits
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|GTraits
operator|::
name|NodeRef
name|NodeRef
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|GTraits
operator|::
name|ChildIteratorType
name|EdgeIter
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|GTraits
operator|::
name|nodes_iterator
name|NodeIter
expr_stmt|;
end_typedef

begin_decl_stmt
name|uint64_t
name|MaxFrequency
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|std
operator|::
name|string
name|getGraphName
argument_list|(
argument|const BlockFrequencyInfoT *G
argument_list|)
block|{
return|return
name|G
operator|->
name|getFunction
argument_list|()
operator|->
name|getName
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|getNodeAttributes
argument_list|(
argument|NodeRef Node
argument_list|,
argument|const BlockFrequencyInfoT *Graph
argument_list|,
argument|unsigned HotPercentThreshold =
literal|0
argument_list|)
block|{
name|std
operator|::
name|string
name|Result
block|;
if|if
condition|(
operator|!
name|HotPercentThreshold
condition|)
return|return
name|Result
return|;
end_expr_stmt

begin_comment
comment|// Compute MaxFrequency on the fly:
end_comment

begin_if
if|if
condition|(
operator|!
name|MaxFrequency
condition|)
block|{
for|for
control|(
name|NodeIter
name|I
init|=
name|GTraits
operator|::
name|nodes_begin
argument_list|(
name|Graph
argument_list|)
init|,
name|E
init|=
name|GTraits
operator|::
name|nodes_end
argument_list|(
name|Graph
argument_list|)
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
name|NodeRef
name|N
init|=
operator|*
name|I
decl_stmt|;
name|MaxFrequency
operator|=
name|std
operator|::
name|max
argument_list|(
name|MaxFrequency
argument_list|,
name|Graph
operator|->
name|getBlockFreq
argument_list|(
name|N
argument_list|)
operator|.
name|getFrequency
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_if

begin_decl_stmt
name|BlockFrequency
name|Freq
init|=
name|Graph
operator|->
name|getBlockFreq
argument_list|(
name|Node
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|BlockFrequency
name|HotFreq
init|=
operator|(
name|BlockFrequency
argument_list|(
name|MaxFrequency
argument_list|)
operator|*
name|BranchProbability
operator|::
name|getBranchProbability
argument_list|(
name|HotPercentThreshold
argument_list|,
literal|100
argument_list|)
operator|)
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|Freq
operator|<
name|HotFreq
condition|)
return|return
name|Result
return|;
end_if

begin_function_decl
name|raw_string_ostream
name|OS
parameter_list|(
name|Result
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|OS
operator|<<
literal|"color=\"red\""
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|OS
operator|.
name|flush
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Result
return|;
end_return

begin_expr_stmt
unit|}    std
operator|::
name|string
name|getNodeLabel
argument_list|(
argument|NodeRef Node
argument_list|,
argument|const BlockFrequencyInfoT *Graph
argument_list|,
argument|GVDAGType GType
argument_list|,
argument|int layout_order = -
literal|1
argument_list|)
block|{
name|std
operator|::
name|string
name|Result
block|;
name|raw_string_ostream
name|OS
argument_list|(
name|Result
argument_list|)
block|;
if|if
condition|(
name|layout_order
operator|!=
operator|-
literal|1
condition|)
name|OS
operator|<<
name|Node
operator|->
name|getName
argument_list|()
operator|<<
literal|"["
operator|<<
name|layout_order
operator|<<
literal|"] : "
expr_stmt|;
else|else
name|OS
operator|<<
name|Node
operator|->
name|getName
argument_list|()
operator|<<
literal|" : "
expr_stmt|;
end_expr_stmt

begin_switch
switch|switch
condition|(
name|GType
condition|)
block|{
case|case
name|GVDT_Fraction
case|:
name|Graph
operator|->
name|printBlockFreq
argument_list|(
name|OS
argument_list|,
name|Node
argument_list|)
expr_stmt|;
break|break;
case|case
name|GVDT_Integer
case|:
name|OS
operator|<<
name|Graph
operator|->
name|getBlockFreq
argument_list|(
name|Node
argument_list|)
operator|.
name|getFrequency
argument_list|()
expr_stmt|;
break|break;
case|case
name|GVDT_Count
case|:
block|{
name|auto
name|Count
init|=
name|Graph
operator|->
name|getBlockProfileCount
argument_list|(
name|Node
argument_list|)
decl_stmt|;
if|if
condition|(
name|Count
condition|)
name|OS
operator|<<
name|Count
operator|.
name|getValue
argument_list|()
expr_stmt|;
else|else
name|OS
operator|<<
literal|"Unknown"
expr_stmt|;
break|break;
block|}
case|case
name|GVDT_None
case|:
name|llvm_unreachable
argument_list|(
literal|"If we are not supposed to render a graph we should "
literal|"never reach this point."
argument_list|)
expr_stmt|;
block|}
end_switch

begin_return
return|return
name|Result
return|;
end_return

begin_expr_stmt
unit|}    std
operator|::
name|string
name|getEdgeAttributes
argument_list|(
argument|NodeRef Node
argument_list|,
argument|EdgeIter EI
argument_list|,
argument|const BlockFrequencyInfoT *BFI
argument_list|,
argument|const BranchProbabilityInfoT *BPI
argument_list|,
argument|unsigned HotPercentThreshold =
literal|0
argument_list|)
block|{
name|std
operator|::
name|string
name|Str
block|;
if|if
condition|(
operator|!
name|BPI
condition|)
return|return
name|Str
return|;
name|BranchProbability
name|BP
operator|=
name|BPI
operator|->
name|getEdgeProbability
argument_list|(
name|Node
argument_list|,
name|EI
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|uint32_t
name|N
init|=
name|BP
operator|.
name|getNumerator
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|D
init|=
name|BP
operator|.
name|getDenominator
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|Percent
init|=
literal|100.0
operator|*
name|N
operator|/
name|D
decl_stmt|;
end_decl_stmt

begin_function_decl
name|raw_string_ostream
name|OS
parameter_list|(
name|Str
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|OS
operator|<<
name|format
argument_list|(
literal|"label=\"%.1f%%\""
argument_list|,
name|Percent
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|HotPercentThreshold
condition|)
block|{
name|BlockFrequency
name|EFreq
init|=
name|BFI
operator|->
name|getBlockFreq
argument_list|(
name|Node
argument_list|)
operator|*
name|BP
decl_stmt|;
name|BlockFrequency
name|HotFreq
init|=
name|BlockFrequency
argument_list|(
name|MaxFrequency
argument_list|)
operator|*
name|BranchProbability
argument_list|(
name|HotPercentThreshold
argument_list|,
literal|100
argument_list|)
decl_stmt|;
if|if
condition|(
name|EFreq
operator|>=
name|HotFreq
condition|)
block|{
name|OS
operator|<<
literal|",color=\"red\""
expr_stmt|;
block|}
block|}
end_if

begin_expr_stmt
name|OS
operator|.
name|flush
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Str
return|;
end_return

begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
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

begin_comment
comment|// LLVM_ANALYSIS_BLOCKFREQUENCYINFOIMPL_H
end_comment

end_unit

