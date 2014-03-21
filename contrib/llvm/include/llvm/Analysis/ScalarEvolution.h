begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/ScalarEvolution.h - Scalar Evolution -------*- C++ -*-===//
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
comment|// The ScalarEvolution class is an LLVM pass which can be used to analyze and
end_comment

begin_comment
comment|// categorize scalar expressions in loops.  It specializes in recognizing
end_comment

begin_comment
comment|// general induction variables, representing them with the abstract and opaque
end_comment

begin_comment
comment|// SCEV class.  Given this analysis, trip counts of loops and other important
end_comment

begin_comment
comment|// properties can be obtained.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This analysis is primarily useful for induction variable substitution and
end_comment

begin_comment
comment|// strength reduction.
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
name|LLVM_ANALYSIS_SCALAREVOLUTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_SCALAREVOLUTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instructions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Operator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ConstantRange.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|APInt
decl_stmt|;
name|class
name|Constant
decl_stmt|;
name|class
name|ConstantInt
decl_stmt|;
name|class
name|DominatorTree
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|ScalarEvolution
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|TargetLibraryInfo
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|Loop
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
name|class
name|Operator
decl_stmt|;
name|class
name|SCEVUnknown
decl_stmt|;
name|class
name|SCEV
decl_stmt|;
name|template
operator|<
operator|>
expr|struct
name|FoldingSetTrait
operator|<
name|SCEV
operator|>
expr_stmt|;
comment|/// SCEV - This class represents an analyzed expression in the program.  These
comment|/// are opaque objects that the client is not allowed to do much with
comment|/// directly.
comment|///
name|class
name|SCEV
range|:
name|public
name|FoldingSetNode
block|{
name|friend
expr|struct
name|FoldingSetTrait
operator|<
name|SCEV
operator|>
block|;
comment|/// FastID - A reference to an Interned FoldingSetNodeID for this node.
comment|/// The ScalarEvolution's BumpPtrAllocator holds the data.
name|FoldingSetNodeIDRef
name|FastID
block|;
comment|// The SCEV baseclass this node corresponds to
specifier|const
name|unsigned
name|short
name|SCEVType
block|;
name|protected
operator|:
comment|/// SubclassData - This field is initialized to zero and may be used in
comment|/// subclasses to store miscellaneous information.
name|unsigned
name|short
name|SubclassData
block|;
name|private
operator|:
name|SCEV
argument_list|(
argument|const SCEV&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|SCEV
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
block|;
name|public
operator|:
comment|/// NoWrapFlags are bitfield indices into SubclassData.
comment|///
comment|/// Add and Mul expressions may have no-unsigned-wrap<NUW> or
comment|/// no-signed-wrap<NSW> properties, which are derived from the IR
comment|/// operator. NSW is a misnomer that we use to mean no signed overflow or
comment|/// underflow.
comment|///
comment|/// AddRec expression may have a no-self-wraparound<NW> property if the
comment|/// result can never reach the start value. This property is independent of
comment|/// the actual start value and step direction. Self-wraparound is defined
comment|/// purely in terms of the recurrence's loop, step size, and
comment|/// bitwidth. Formally, a recurrence with no self-wraparound satisfies:
comment|/// abs(step) * max-iteration(loop)<= unsigned-max(bitwidth).
comment|///
comment|/// Note that NUW and NSW are also valid properties of a recurrence, and
comment|/// either implies NW. For convenience, NW will be set for a recurrence
comment|/// whenever either NUW or NSW are set.
expr|enum
name|NoWrapFlags
block|{
name|FlagAnyWrap
operator|=
literal|0
block|,
comment|// No guarantee.
name|FlagNW
operator|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
comment|// No self-wrap.
name|FlagNUW
operator|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
comment|// No unsigned wrap.
name|FlagNSW
operator|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
comment|// No signed wrap.
name|NoWrapMask
operator|=
operator|(
literal|1
operator|<<
literal|3
operator|)
operator|-
literal|1
block|}
block|;
name|explicit
name|SCEV
argument_list|(
argument|const FoldingSetNodeIDRef ID
argument_list|,
argument|unsigned SCEVTy
argument_list|)
operator|:
name|FastID
argument_list|(
name|ID
argument_list|)
block|,
name|SCEVType
argument_list|(
name|SCEVTy
argument_list|)
block|,
name|SubclassData
argument_list|(
literal|0
argument_list|)
block|{}
name|unsigned
name|getSCEVType
argument_list|()
specifier|const
block|{
return|return
name|SCEVType
return|;
block|}
comment|/// getType - Return the LLVM type of this SCEV expression.
comment|///
name|Type
operator|*
name|getType
argument_list|()
specifier|const
block|;
comment|/// isZero - Return true if the expression is a constant zero.
comment|///
name|bool
name|isZero
argument_list|()
specifier|const
block|;
comment|/// isOne - Return true if the expression is a constant one.
comment|///
name|bool
name|isOne
argument_list|()
specifier|const
block|;
comment|/// isAllOnesValue - Return true if the expression is a constant
comment|/// all-ones value.
comment|///
name|bool
name|isAllOnesValue
argument_list|()
specifier|const
block|;
comment|/// isNonConstantNegative - Return true if the specified scev is negated,
comment|/// but not a constant.
name|bool
name|isNonConstantNegative
argument_list|()
specifier|const
block|;
comment|/// print - Print out the internal representation of this scalar to the
comment|/// specified stream.  This should really only be used for debugging
comment|/// purposes.
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;
comment|/// dump - This method is used for debugging.
comment|///
name|void
name|dump
argument_list|()
specifier|const
block|;   }
decl_stmt|;
comment|// Specialize FoldingSetTrait for SCEV to avoid needing to compute
comment|// temporary FoldingSetNodeID values.
name|template
operator|<
operator|>
expr|struct
name|FoldingSetTrait
operator|<
name|SCEV
operator|>
operator|:
name|DefaultFoldingSetTrait
operator|<
name|SCEV
operator|>
block|{
specifier|static
name|void
name|Profile
argument_list|(
argument|const SCEV&X
argument_list|,
argument|FoldingSetNodeID& ID
argument_list|)
block|{
name|ID
operator|=
name|X
operator|.
name|FastID
block|;     }
specifier|static
name|bool
name|Equals
argument_list|(
argument|const SCEV&X
argument_list|,
argument|const FoldingSetNodeID&ID
argument_list|,
argument|unsigned IDHash
argument_list|,
argument|FoldingSetNodeID&TempID
argument_list|)
block|{
return|return
name|ID
operator|==
name|X
operator|.
name|FastID
return|;
block|}
specifier|static
name|unsigned
name|ComputeHash
argument_list|(
argument|const SCEV&X
argument_list|,
argument|FoldingSetNodeID&TempID
argument_list|)
block|{
return|return
name|X
operator|.
name|FastID
operator|.
name|ComputeHash
argument_list|()
return|;
block|}
expr|}
block|;
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
specifier|const
name|SCEV
operator|&
name|S
operator|)
block|{
name|S
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
comment|/// SCEVCouldNotCompute - An object of this class is returned by queries that
comment|/// could not be answered.  For example, if you ask for the number of
comment|/// iterations of a linked-list traversal loop, you will get one of these.
comment|/// None of the standard SCEV operations are valid on this class, it is just a
comment|/// marker.
expr|struct
name|SCEVCouldNotCompute
operator|:
name|public
name|SCEV
block|{
name|SCEVCouldNotCompute
argument_list|()
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
name|bool
name|classof
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|)
block|;   }
block|;
comment|/// ScalarEvolution - This class is the main scalar evolution driver.  Because
comment|/// client code (intentionally) can't do much with the SCEV objects directly,
comment|/// they must ask this class for services.
comment|///
name|class
name|ScalarEvolution
operator|:
name|public
name|FunctionPass
block|{
name|public
operator|:
comment|/// LoopDisposition - An enum describing the relationship between a
comment|/// SCEV and a loop.
expr|enum
name|LoopDisposition
block|{
name|LoopVariant
block|,
comment|///< The SCEV is loop-variant (unknown).
name|LoopInvariant
block|,
comment|///< The SCEV is loop-invariant.
name|LoopComputable
comment|///< The SCEV varies predictably with the loop.
block|}
block|;
comment|/// BlockDisposition - An enum describing the relationship between a
comment|/// SCEV and a basic block.
block|enum
name|BlockDisposition
block|{
name|DoesNotDominateBlock
block|,
comment|///< The SCEV does not dominate the block.
name|DominatesBlock
block|,
comment|///< The SCEV dominates the block.
name|ProperlyDominatesBlock
comment|///< The SCEV properly dominates the block.
block|}
block|;
comment|/// Convenient NoWrapFlags manipulation that hides enum casts and is
comment|/// visible in the ScalarEvolution name space.
specifier|static
name|SCEV
operator|::
name|NoWrapFlags
name|LLVM_ATTRIBUTE_UNUSED_RESULT
name|maskFlags
argument_list|(
argument|SCEV::NoWrapFlags Flags
argument_list|,
argument|int Mask
argument_list|)
block|{
return|return
operator|(
name|SCEV
operator|::
name|NoWrapFlags
operator|)
operator|(
name|Flags
operator|&
name|Mask
operator|)
return|;
block|}
specifier|static
name|SCEV
operator|::
name|NoWrapFlags
name|LLVM_ATTRIBUTE_UNUSED_RESULT
name|setFlags
argument_list|(
argument|SCEV::NoWrapFlags Flags
argument_list|,
argument|SCEV::NoWrapFlags OnFlags
argument_list|)
block|{
return|return
operator|(
name|SCEV
operator|::
name|NoWrapFlags
operator|)
operator|(
name|Flags
operator||
name|OnFlags
operator|)
return|;
block|}
specifier|static
name|SCEV
operator|::
name|NoWrapFlags
name|LLVM_ATTRIBUTE_UNUSED_RESULT
name|clearFlags
argument_list|(
argument|SCEV::NoWrapFlags Flags
argument_list|,
argument|SCEV::NoWrapFlags OffFlags
argument_list|)
block|{
return|return
operator|(
name|SCEV
operator|::
name|NoWrapFlags
operator|)
operator|(
name|Flags
operator|&
operator|~
name|OffFlags
operator|)
return|;
block|}
name|private
operator|:
comment|/// SCEVCallbackVH - A CallbackVH to arrange for ScalarEvolution to be
comment|/// notified whenever a Value is deleted.
name|class
name|SCEVCallbackVH
operator|:
name|public
name|CallbackVH
block|{
name|ScalarEvolution
operator|*
name|SE
block|;
name|virtual
name|void
name|deleted
argument_list|()
block|;
name|virtual
name|void
name|allUsesReplacedWith
argument_list|(
name|Value
operator|*
name|New
argument_list|)
block|;
name|public
operator|:
name|SCEVCallbackVH
argument_list|(
name|Value
operator|*
name|V
argument_list|,
name|ScalarEvolution
operator|*
name|SE
operator|=
literal|0
argument_list|)
block|;     }
block|;
name|friend
name|class
name|SCEVCallbackVH
block|;
name|friend
name|class
name|SCEVExpander
block|;
name|friend
name|class
name|SCEVUnknown
block|;
comment|/// F - The function we are analyzing.
comment|///
name|Function
operator|*
name|F
block|;
comment|/// LI - The loop information for the function we are currently analyzing.
comment|///
name|LoopInfo
operator|*
name|LI
block|;
comment|/// TD - The target data information for the target we are targeting.
comment|///
name|DataLayout
operator|*
name|TD
block|;
comment|/// TLI - The target library information for the target we are targeting.
comment|///
name|TargetLibraryInfo
operator|*
name|TLI
block|;
comment|/// DT - The dominator tree.
comment|///
name|DominatorTree
operator|*
name|DT
block|;
comment|/// CouldNotCompute - This SCEV is used to represent unknown trip
comment|/// counts and things.
name|SCEVCouldNotCompute
name|CouldNotCompute
block|;
comment|/// ValueExprMapType - The typedef for ValueExprMap.
comment|///
typedef|typedef
name|DenseMap
operator|<
name|SCEVCallbackVH
operator|,
specifier|const
name|SCEV
operator|*
operator|,
name|DenseMapInfo
operator|<
name|Value
operator|*
operator|>
expr|>
name|ValueExprMapType
expr_stmt|;
comment|/// ValueExprMap - This is a cache of the values we have analyzed so far.
comment|///
name|ValueExprMapType
name|ValueExprMap
block|;
comment|/// Mark predicate values currently being processed by isImpliedCond.
name|DenseSet
operator|<
name|Value
operator|*
operator|>
name|PendingLoopPredicates
block|;
comment|/// ExitLimit - Information about the number of loop iterations for
comment|/// which a loop exit's branch condition evaluates to the not-taken path.
comment|/// This is a temporary pair of exact and max expressions that are
comment|/// eventually summarized in ExitNotTakenInfo and BackedgeTakenInfo.
block|struct
name|ExitLimit
block|{
specifier|const
name|SCEV
operator|*
name|Exact
block|;
specifier|const
name|SCEV
operator|*
name|Max
block|;
comment|/*implicit*/
name|ExitLimit
argument_list|(
specifier|const
name|SCEV
operator|*
name|E
argument_list|)
operator|:
name|Exact
argument_list|(
name|E
argument_list|)
block|,
name|Max
argument_list|(
argument|E
argument_list|)
block|{}
name|ExitLimit
argument_list|(
specifier|const
name|SCEV
operator|*
name|E
argument_list|,
specifier|const
name|SCEV
operator|*
name|M
argument_list|)
operator|:
name|Exact
argument_list|(
name|E
argument_list|)
block|,
name|Max
argument_list|(
argument|M
argument_list|)
block|{}
comment|/// hasAnyInfo - Test whether this ExitLimit contains any computed
comment|/// information, or whether it's all SCEVCouldNotCompute values.
name|bool
name|hasAnyInfo
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isa
operator|<
name|SCEVCouldNotCompute
operator|>
operator|(
name|Exact
operator|)
operator|||
operator|!
name|isa
operator|<
name|SCEVCouldNotCompute
operator|>
operator|(
name|Max
operator|)
return|;
block|}
expr|}
block|;
comment|/// ExitNotTakenInfo - Information about the number of times a particular
comment|/// loop exit may be reached before exiting the loop.
block|struct
name|ExitNotTakenInfo
block|{
name|AssertingVH
operator|<
name|BasicBlock
operator|>
name|ExitingBlock
block|;
specifier|const
name|SCEV
operator|*
name|ExactNotTaken
block|;
name|PointerIntPair
operator|<
name|ExitNotTakenInfo
operator|*
block|,
literal|1
operator|>
name|NextExit
block|;
name|ExitNotTakenInfo
argument_list|()
operator|:
name|ExitingBlock
argument_list|(
literal|0
argument_list|)
block|,
name|ExactNotTaken
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// isCompleteList - Return true if all loop exits are computable.
name|bool
name|isCompleteList
argument_list|()
specifier|const
block|{
return|return
name|NextExit
operator|.
name|getInt
argument_list|()
operator|==
literal|0
return|;
block|}
name|void
name|setIncomplete
argument_list|()
block|{
name|NextExit
operator|.
name|setInt
argument_list|(
literal|1
argument_list|)
block|; }
comment|/// getNextExit - Return a pointer to the next exit's not-taken info.
name|ExitNotTakenInfo
operator|*
name|getNextExit
argument_list|()
specifier|const
block|{
return|return
name|NextExit
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|void
name|setNextExit
argument_list|(
argument|ExitNotTakenInfo *ENT
argument_list|)
block|{
name|NextExit
operator|.
name|setPointer
argument_list|(
name|ENT
argument_list|)
block|; }
expr|}
block|;
comment|/// BackedgeTakenInfo - Information about the backedge-taken count
comment|/// of a loop. This currently includes an exact count and a maximum count.
comment|///
name|class
name|BackedgeTakenInfo
block|{
comment|/// ExitNotTaken - A list of computable exits and their not-taken counts.
comment|/// Loops almost never have more than one computable exit.
name|ExitNotTakenInfo
name|ExitNotTaken
block|;
comment|/// Max - An expression indicating the least maximum backedge-taken
comment|/// count of the loop that is known, or a SCEVCouldNotCompute.
specifier|const
name|SCEV
operator|*
name|Max
block|;
name|public
operator|:
name|BackedgeTakenInfo
argument_list|()
operator|:
name|Max
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// Initialize BackedgeTakenInfo from a list of exact exit counts.
name|BackedgeTakenInfo
argument_list|(
argument|SmallVectorImpl< std::pair<BasicBlock *
argument_list|,
argument|const SCEV *>>&ExitCounts
argument_list|,
argument|bool Complete
argument_list|,
argument|const SCEV *MaxCount
argument_list|)
block|;
comment|/// hasAnyInfo - Test whether this BackedgeTakenInfo contains any
comment|/// computed information, or whether it's all SCEVCouldNotCompute
comment|/// values.
name|bool
name|hasAnyInfo
argument_list|()
specifier|const
block|{
return|return
name|ExitNotTaken
operator|.
name|ExitingBlock
operator|||
operator|!
name|isa
operator|<
name|SCEVCouldNotCompute
operator|>
operator|(
name|Max
operator|)
return|;
block|}
comment|/// getExact - Return an expression indicating the exact backedge-taken
comment|/// count of the loop if it is known, or SCEVCouldNotCompute
comment|/// otherwise. This is the number of times the loop header can be
comment|/// guaranteed to execute, minus one.
specifier|const
name|SCEV
operator|*
name|getExact
argument_list|(
argument|ScalarEvolution *SE
argument_list|)
specifier|const
block|;
comment|/// getExact - Return the number of times this loop exit may fall through
comment|/// to the back edge, or SCEVCouldNotCompute. The loop is guaranteed not
comment|/// to exit via this block before this number of iterations, but may exit
comment|/// via another block.
specifier|const
name|SCEV
operator|*
name|getExact
argument_list|(
argument|BasicBlock *ExitingBlock
argument_list|,
argument|ScalarEvolution *SE
argument_list|)
specifier|const
block|;
comment|/// getMax - Get the max backedge taken count for the loop.
specifier|const
name|SCEV
operator|*
name|getMax
argument_list|(
argument|ScalarEvolution *SE
argument_list|)
specifier|const
block|;
comment|/// Return true if any backedge taken count expressions refer to the given
comment|/// subexpression.
name|bool
name|hasOperand
argument_list|(
argument|const SCEV *S
argument_list|,
argument|ScalarEvolution *SE
argument_list|)
specifier|const
block|;
comment|/// clear - Invalidate this result and free associated memory.
name|void
name|clear
argument_list|()
block|;     }
block|;
comment|/// BackedgeTakenCounts - Cache the backedge-taken count of the loops for
comment|/// this function as they are computed.
name|DenseMap
operator|<
specifier|const
name|Loop
operator|*
block|,
name|BackedgeTakenInfo
operator|>
name|BackedgeTakenCounts
block|;
comment|/// ConstantEvolutionLoopExitValue - This map contains entries for all of
comment|/// the PHI instructions that we attempt to compute constant evolutions for.
comment|/// This allows us to avoid potentially expensive recomputation of these
comment|/// properties.  An instruction maps to null if we are unable to compute its
comment|/// exit value.
name|DenseMap
operator|<
name|PHINode
operator|*
block|,
name|Constant
operator|*
operator|>
name|ConstantEvolutionLoopExitValue
block|;
comment|/// ValuesAtScopes - This map contains entries for all the expressions
comment|/// that we attempt to compute getSCEVAtScope information for, which can
comment|/// be expensive in extreme cases.
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
block|,
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|Loop
operator|*
block|,
specifier|const
name|SCEV
operator|*
operator|>
block|,
literal|2
operator|>
expr|>
name|ValuesAtScopes
block|;
comment|/// LoopDispositions - Memoized computeLoopDisposition results.
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
block|,
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|Loop
operator|*
block|,
name|LoopDisposition
operator|>
block|,
literal|2
operator|>
expr|>
name|LoopDispositions
block|;
comment|/// computeLoopDisposition - Compute a LoopDisposition value.
name|LoopDisposition
name|computeLoopDisposition
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|,
specifier|const
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|/// BlockDispositions - Memoized computeBlockDisposition results.
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
block|,
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|BasicBlock
operator|*
block|,
name|BlockDisposition
operator|>
block|,
literal|2
operator|>
expr|>
name|BlockDispositions
block|;
comment|/// computeBlockDisposition - Compute a BlockDisposition value.
name|BlockDisposition
name|computeBlockDisposition
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|,
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
block|;
comment|/// UnsignedRanges - Memoized results from getUnsignedRange
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
block|,
name|ConstantRange
operator|>
name|UnsignedRanges
block|;
comment|/// SignedRanges - Memoized results from getSignedRange
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
block|,
name|ConstantRange
operator|>
name|SignedRanges
block|;
comment|/// setUnsignedRange - Set the memoized unsigned range for the given SCEV.
specifier|const
name|ConstantRange
operator|&
name|setUnsignedRange
argument_list|(
argument|const SCEV *S
argument_list|,
argument|const ConstantRange&CR
argument_list|)
block|{
name|std
operator|::
name|pair
operator|<
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
block|,
name|ConstantRange
operator|>
operator|::
name|iterator
block|,
name|bool
operator|>
name|Pair
operator|=
name|UnsignedRanges
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|S
argument_list|,
name|CR
argument_list|)
argument_list|)
block|;
if|if
condition|(
operator|!
name|Pair
operator|.
name|second
condition|)
name|Pair
operator|.
name|first
operator|->
name|second
operator|=
name|CR
expr_stmt|;
return|return
name|Pair
operator|.
name|first
operator|->
name|second
return|;
block|}
comment|/// setUnsignedRange - Set the memoized signed range for the given SCEV.
specifier|const
name|ConstantRange
operator|&
name|setSignedRange
argument_list|(
argument|const SCEV *S
argument_list|,
argument|const ConstantRange&CR
argument_list|)
block|{
name|std
operator|::
name|pair
operator|<
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
block|,
name|ConstantRange
operator|>
operator|::
name|iterator
block|,
name|bool
operator|>
name|Pair
operator|=
name|SignedRanges
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|S
argument_list|,
name|CR
argument_list|)
argument_list|)
block|;
if|if
condition|(
operator|!
name|Pair
operator|.
name|second
condition|)
name|Pair
operator|.
name|first
operator|->
name|second
operator|=
name|CR
expr_stmt|;
return|return
name|Pair
operator|.
name|first
operator|->
name|second
return|;
block|}
comment|/// createSCEV - We know that there is no SCEV for the specified value.
comment|/// Analyze the expression.
specifier|const
name|SCEV
operator|*
name|createSCEV
argument_list|(
name|Value
operator|*
name|V
argument_list|)
block|;
comment|/// createNodeForPHI - Provide the special handling we need to analyze PHI
comment|/// SCEVs.
specifier|const
name|SCEV
operator|*
name|createNodeForPHI
argument_list|(
name|PHINode
operator|*
name|PN
argument_list|)
block|;
comment|/// createNodeForGEP - Provide the special handling we need to analyze GEP
comment|/// SCEVs.
specifier|const
name|SCEV
operator|*
name|createNodeForGEP
argument_list|(
name|GEPOperator
operator|*
name|GEP
argument_list|)
block|;
comment|/// computeSCEVAtScope - Implementation code for getSCEVAtScope; called
comment|/// at most once for each SCEV+Loop pair.
comment|///
specifier|const
name|SCEV
operator|*
name|computeSCEVAtScope
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|,
specifier|const
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|/// ForgetSymbolicValue - This looks up computed SCEV values for all
comment|/// instructions that depend on the given instruction and removes them from
comment|/// the ValueExprMap map if they reference SymName. This is used during PHI
comment|/// resolution.
name|void
name|ForgetSymbolicName
argument_list|(
name|Instruction
operator|*
name|I
argument_list|,
specifier|const
name|SCEV
operator|*
name|SymName
argument_list|)
block|;
comment|/// getBackedgeTakenInfo - Return the BackedgeTakenInfo for the given
comment|/// loop, lazily computing new values if the loop hasn't been analyzed
comment|/// yet.
specifier|const
name|BackedgeTakenInfo
operator|&
name|getBackedgeTakenInfo
argument_list|(
specifier|const
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|/// ComputeBackedgeTakenCount - Compute the number of times the specified
comment|/// loop will iterate.
name|BackedgeTakenInfo
name|ComputeBackedgeTakenCount
argument_list|(
specifier|const
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|/// ComputeExitLimit - Compute the number of times the backedge of the
comment|/// specified loop will execute if it exits via the specified block.
name|ExitLimit
name|ComputeExitLimit
argument_list|(
specifier|const
name|Loop
operator|*
name|L
argument_list|,
name|BasicBlock
operator|*
name|ExitingBlock
argument_list|)
block|;
comment|/// ComputeExitLimitFromCond - Compute the number of times the backedge of
comment|/// the specified loop will execute if its exit condition were a conditional
comment|/// branch of ExitCond, TBB, and FBB.
name|ExitLimit
name|ComputeExitLimitFromCond
argument_list|(
argument|const Loop *L
argument_list|,
argument|Value *ExitCond
argument_list|,
argument|BasicBlock *TBB
argument_list|,
argument|BasicBlock *FBB
argument_list|,
argument|bool IsSubExpr
argument_list|)
block|;
comment|/// ComputeExitLimitFromICmp - Compute the number of times the backedge of
comment|/// the specified loop will execute if its exit condition were a conditional
comment|/// branch of the ICmpInst ExitCond, TBB, and FBB.
name|ExitLimit
name|ComputeExitLimitFromICmp
argument_list|(
argument|const Loop *L
argument_list|,
argument|ICmpInst *ExitCond
argument_list|,
argument|BasicBlock *TBB
argument_list|,
argument|BasicBlock *FBB
argument_list|,
argument|bool IsSubExpr
argument_list|)
block|;
comment|/// ComputeLoadConstantCompareExitLimit - Given an exit condition
comment|/// of 'icmp op load X, cst', try to see if we can compute the
comment|/// backedge-taken count.
name|ExitLimit
name|ComputeLoadConstantCompareExitLimit
argument_list|(
argument|LoadInst *LI
argument_list|,
argument|Constant *RHS
argument_list|,
argument|const Loop *L
argument_list|,
argument|ICmpInst::Predicate p
argument_list|)
block|;
comment|/// ComputeExitCountExhaustively - If the loop is known to execute a
comment|/// constant number of times (the condition evolves only from constants),
comment|/// try to evaluate a few iterations of the loop until we get the exit
comment|/// condition gets a value of ExitWhen (true or false).  If we cannot
comment|/// evaluate the exit count of the loop, return CouldNotCompute.
specifier|const
name|SCEV
operator|*
name|ComputeExitCountExhaustively
argument_list|(
argument|const Loop *L
argument_list|,
argument|Value *Cond
argument_list|,
argument|bool ExitWhen
argument_list|)
block|;
comment|/// HowFarToZero - Return the number of times an exit condition comparing
comment|/// the specified value to zero will execute.  If not computable, return
comment|/// CouldNotCompute.
name|ExitLimit
name|HowFarToZero
argument_list|(
argument|const SCEV *V
argument_list|,
argument|const Loop *L
argument_list|,
argument|bool IsSubExpr
argument_list|)
block|;
comment|/// HowFarToNonZero - Return the number of times an exit condition checking
comment|/// the specified value for nonzero will execute.  If not computable, return
comment|/// CouldNotCompute.
name|ExitLimit
name|HowFarToNonZero
argument_list|(
specifier|const
name|SCEV
operator|*
name|V
argument_list|,
specifier|const
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|/// HowManyLessThans - Return the number of times an exit condition
comment|/// containing the specified less-than comparison will execute.  If not
comment|/// computable, return CouldNotCompute. isSigned specifies whether the
comment|/// less-than is signed.
name|ExitLimit
name|HowManyLessThans
argument_list|(
argument|const SCEV *LHS
argument_list|,
argument|const SCEV *RHS
argument_list|,
argument|const Loop *L
argument_list|,
argument|bool isSigned
argument_list|,
argument|bool IsSubExpr
argument_list|)
block|;
name|ExitLimit
name|HowManyGreaterThans
argument_list|(
argument|const SCEV *LHS
argument_list|,
argument|const SCEV *RHS
argument_list|,
argument|const Loop *L
argument_list|,
argument|bool isSigned
argument_list|,
argument|bool IsSubExpr
argument_list|)
block|;
comment|/// getPredecessorWithUniqueSuccessorForBB - Return a predecessor of BB
comment|/// (which may not be an immediate predecessor) which has exactly one
comment|/// successor from which BB is reachable, or null if no such block is
comment|/// found.
name|std
operator|::
name|pair
operator|<
name|BasicBlock
operator|*
block|,
name|BasicBlock
operator|*
operator|>
name|getPredecessorWithUniqueSuccessorForBB
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
block|;
comment|/// isImpliedCond - Test whether the condition described by Pred, LHS, and
comment|/// RHS is true whenever the given FoundCondValue value evaluates to true.
name|bool
name|isImpliedCond
argument_list|(
argument|ICmpInst::Predicate Pred
argument_list|,
argument|const SCEV *LHS
argument_list|,
argument|const SCEV *RHS
argument_list|,
argument|Value *FoundCondValue
argument_list|,
argument|bool Inverse
argument_list|)
block|;
comment|/// isImpliedCondOperands - Test whether the condition described by Pred,
comment|/// LHS, and RHS is true whenever the condition described by Pred, FoundLHS,
comment|/// and FoundRHS is true.
name|bool
name|isImpliedCondOperands
argument_list|(
argument|ICmpInst::Predicate Pred
argument_list|,
argument|const SCEV *LHS
argument_list|,
argument|const SCEV *RHS
argument_list|,
argument|const SCEV *FoundLHS
argument_list|,
argument|const SCEV *FoundRHS
argument_list|)
block|;
comment|/// isImpliedCondOperandsHelper - Test whether the condition described by
comment|/// Pred, LHS, and RHS is true whenever the condition described by Pred,
comment|/// FoundLHS, and FoundRHS is true.
name|bool
name|isImpliedCondOperandsHelper
argument_list|(
argument|ICmpInst::Predicate Pred
argument_list|,
argument|const SCEV *LHS
argument_list|,
argument|const SCEV *RHS
argument_list|,
argument|const SCEV *FoundLHS
argument_list|,
argument|const SCEV *FoundRHS
argument_list|)
block|;
comment|/// getConstantEvolutionLoopExitValue - If we know that the specified Phi is
comment|/// in the header of its containing loop, we know the loop executes a
comment|/// constant number of times, and the PHI node is just a recurrence
comment|/// involving constants, fold it.
name|Constant
operator|*
name|getConstantEvolutionLoopExitValue
argument_list|(
name|PHINode
operator|*
name|PN
argument_list|,
specifier|const
name|APInt
operator|&
name|BEs
argument_list|,
specifier|const
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|/// isKnownPredicateWithRanges - Test if the given expression is known to
comment|/// satisfy the condition described by Pred and the known constant ranges
comment|/// of LHS and RHS.
comment|///
name|bool
name|isKnownPredicateWithRanges
argument_list|(
argument|ICmpInst::Predicate Pred
argument_list|,
argument|const SCEV *LHS
argument_list|,
argument|const SCEV *RHS
argument_list|)
block|;
comment|/// forgetMemoizedResults - Drop memoized information computed for S.
name|void
name|forgetMemoizedResults
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|)
block|;
comment|/// Return false iff given SCEV contains a SCEVUnknown with NULL value-
comment|/// pointer.
name|bool
name|checkValidity
argument_list|(
argument|const SCEV *S
argument_list|)
specifier|const
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeid
name|ScalarEvolution
argument_list|()
block|;
name|LLVMContext
operator|&
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|F
operator|->
name|getContext
argument_list|()
return|;
block|}
comment|/// isSCEVable - Test if values of the given type are analyzable within
comment|/// the SCEV framework. This primarily includes integer types, and it
comment|/// can optionally include pointer types if the ScalarEvolution class
comment|/// has access to target-specific information.
name|bool
name|isSCEVable
argument_list|(
argument|Type *Ty
argument_list|)
specifier|const
block|;
comment|/// getTypeSizeInBits - Return the size in bits of the specified type,
comment|/// for which isSCEVable must return true.
name|uint64_t
name|getTypeSizeInBits
argument_list|(
argument|Type *Ty
argument_list|)
specifier|const
block|;
comment|/// getEffectiveSCEVType - Return a type with the same bitwidth as
comment|/// the given type and which represents how SCEV will treat the given
comment|/// type, for which isSCEVable must return true. For pointer types,
comment|/// this is the pointer-sized integer type.
name|Type
operator|*
name|getEffectiveSCEVType
argument_list|(
argument|Type *Ty
argument_list|)
specifier|const
block|;
comment|/// getSCEV - Return a SCEV expression for the full generality of the
comment|/// specified expression.
specifier|const
name|SCEV
operator|*
name|getSCEV
argument_list|(
name|Value
operator|*
name|V
argument_list|)
block|;
specifier|const
name|SCEV
operator|*
name|getConstant
argument_list|(
name|ConstantInt
operator|*
name|V
argument_list|)
block|;
specifier|const
name|SCEV
operator|*
name|getConstant
argument_list|(
specifier|const
name|APInt
operator|&
name|Val
argument_list|)
block|;
specifier|const
name|SCEV
operator|*
name|getConstant
argument_list|(
argument|Type *Ty
argument_list|,
argument|uint64_t V
argument_list|,
argument|bool isSigned = false
argument_list|)
block|;
specifier|const
name|SCEV
operator|*
name|getTruncateExpr
argument_list|(
specifier|const
name|SCEV
operator|*
name|Op
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
specifier|const
name|SCEV
operator|*
name|getZeroExtendExpr
argument_list|(
specifier|const
name|SCEV
operator|*
name|Op
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
specifier|const
name|SCEV
operator|*
name|getSignExtendExpr
argument_list|(
specifier|const
name|SCEV
operator|*
name|Op
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
specifier|const
name|SCEV
operator|*
name|getAnyExtendExpr
argument_list|(
specifier|const
name|SCEV
operator|*
name|Op
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
specifier|const
name|SCEV
operator|*
name|getAddExpr
argument_list|(
argument|SmallVectorImpl<const SCEV *>&Ops
argument_list|,
argument|SCEV::NoWrapFlags Flags = SCEV::FlagAnyWrap
argument_list|)
block|;
specifier|const
name|SCEV
operator|*
name|getAddExpr
argument_list|(
argument|const SCEV *LHS
argument_list|,
argument|const SCEV *RHS
argument_list|,
argument|SCEV::NoWrapFlags Flags = SCEV::FlagAnyWrap
argument_list|)
block|{
name|SmallVector
operator|<
specifier|const
name|SCEV
operator|*
block|,
literal|2
operator|>
name|Ops
block|;
name|Ops
operator|.
name|push_back
argument_list|(
name|LHS
argument_list|)
block|;
name|Ops
operator|.
name|push_back
argument_list|(
name|RHS
argument_list|)
block|;
return|return
name|getAddExpr
argument_list|(
name|Ops
argument_list|,
name|Flags
argument_list|)
return|;
block|}
specifier|const
name|SCEV
operator|*
name|getAddExpr
argument_list|(
argument|const SCEV *Op0
argument_list|,
argument|const SCEV *Op1
argument_list|,
argument|const SCEV *Op2
argument_list|,
argument|SCEV::NoWrapFlags Flags = SCEV::FlagAnyWrap
argument_list|)
block|{
name|SmallVector
operator|<
specifier|const
name|SCEV
operator|*
block|,
literal|3
operator|>
name|Ops
block|;
name|Ops
operator|.
name|push_back
argument_list|(
name|Op0
argument_list|)
block|;
name|Ops
operator|.
name|push_back
argument_list|(
name|Op1
argument_list|)
block|;
name|Ops
operator|.
name|push_back
argument_list|(
name|Op2
argument_list|)
block|;
return|return
name|getAddExpr
argument_list|(
name|Ops
argument_list|,
name|Flags
argument_list|)
return|;
block|}
specifier|const
name|SCEV
operator|*
name|getMulExpr
argument_list|(
argument|SmallVectorImpl<const SCEV *>&Ops
argument_list|,
argument|SCEV::NoWrapFlags Flags = SCEV::FlagAnyWrap
argument_list|)
block|;
specifier|const
name|SCEV
operator|*
name|getMulExpr
argument_list|(
argument|const SCEV *LHS
argument_list|,
argument|const SCEV *RHS
argument_list|,
argument|SCEV::NoWrapFlags Flags = SCEV::FlagAnyWrap
argument_list|)
block|{
name|SmallVector
operator|<
specifier|const
name|SCEV
operator|*
block|,
literal|2
operator|>
name|Ops
block|;
name|Ops
operator|.
name|push_back
argument_list|(
name|LHS
argument_list|)
block|;
name|Ops
operator|.
name|push_back
argument_list|(
name|RHS
argument_list|)
block|;
return|return
name|getMulExpr
argument_list|(
name|Ops
argument_list|,
name|Flags
argument_list|)
return|;
block|}
specifier|const
name|SCEV
operator|*
name|getMulExpr
argument_list|(
argument|const SCEV *Op0
argument_list|,
argument|const SCEV *Op1
argument_list|,
argument|const SCEV *Op2
argument_list|,
argument|SCEV::NoWrapFlags Flags = SCEV::FlagAnyWrap
argument_list|)
block|{
name|SmallVector
operator|<
specifier|const
name|SCEV
operator|*
block|,
literal|3
operator|>
name|Ops
block|;
name|Ops
operator|.
name|push_back
argument_list|(
name|Op0
argument_list|)
block|;
name|Ops
operator|.
name|push_back
argument_list|(
name|Op1
argument_list|)
block|;
name|Ops
operator|.
name|push_back
argument_list|(
name|Op2
argument_list|)
block|;
return|return
name|getMulExpr
argument_list|(
name|Ops
argument_list|,
name|Flags
argument_list|)
return|;
block|}
specifier|const
name|SCEV
operator|*
name|getUDivExpr
argument_list|(
specifier|const
name|SCEV
operator|*
name|LHS
argument_list|,
specifier|const
name|SCEV
operator|*
name|RHS
argument_list|)
block|;
specifier|const
name|SCEV
operator|*
name|getAddRecExpr
argument_list|(
argument|const SCEV *Start
argument_list|,
argument|const SCEV *Step
argument_list|,
argument|const Loop *L
argument_list|,
argument|SCEV::NoWrapFlags Flags
argument_list|)
block|;
specifier|const
name|SCEV
operator|*
name|getAddRecExpr
argument_list|(
argument|SmallVectorImpl<const SCEV *>&Operands
argument_list|,
argument|const Loop *L
argument_list|,
argument|SCEV::NoWrapFlags Flags
argument_list|)
block|;
specifier|const
name|SCEV
operator|*
name|getAddRecExpr
argument_list|(
argument|const SmallVectorImpl<const SCEV *>&Operands
argument_list|,
argument|const Loop *L
argument_list|,
argument|SCEV::NoWrapFlags Flags
argument_list|)
block|{
name|SmallVector
operator|<
specifier|const
name|SCEV
operator|*
block|,
literal|4
operator|>
name|NewOp
argument_list|(
name|Operands
operator|.
name|begin
argument_list|()
argument_list|,
name|Operands
operator|.
name|end
argument_list|()
argument_list|)
block|;
return|return
name|getAddRecExpr
argument_list|(
name|NewOp
argument_list|,
name|L
argument_list|,
name|Flags
argument_list|)
return|;
block|}
specifier|const
name|SCEV
operator|*
name|getSMaxExpr
argument_list|(
specifier|const
name|SCEV
operator|*
name|LHS
argument_list|,
specifier|const
name|SCEV
operator|*
name|RHS
argument_list|)
block|;
specifier|const
name|SCEV
operator|*
name|getSMaxExpr
argument_list|(
name|SmallVectorImpl
operator|<
specifier|const
name|SCEV
operator|*
operator|>
operator|&
name|Operands
argument_list|)
block|;
specifier|const
name|SCEV
operator|*
name|getUMaxExpr
argument_list|(
specifier|const
name|SCEV
operator|*
name|LHS
argument_list|,
specifier|const
name|SCEV
operator|*
name|RHS
argument_list|)
block|;
specifier|const
name|SCEV
operator|*
name|getUMaxExpr
argument_list|(
name|SmallVectorImpl
operator|<
specifier|const
name|SCEV
operator|*
operator|>
operator|&
name|Operands
argument_list|)
block|;
specifier|const
name|SCEV
operator|*
name|getSMinExpr
argument_list|(
specifier|const
name|SCEV
operator|*
name|LHS
argument_list|,
specifier|const
name|SCEV
operator|*
name|RHS
argument_list|)
block|;
specifier|const
name|SCEV
operator|*
name|getUMinExpr
argument_list|(
specifier|const
name|SCEV
operator|*
name|LHS
argument_list|,
specifier|const
name|SCEV
operator|*
name|RHS
argument_list|)
block|;
specifier|const
name|SCEV
operator|*
name|getUnknown
argument_list|(
name|Value
operator|*
name|V
argument_list|)
block|;
specifier|const
name|SCEV
operator|*
name|getCouldNotCompute
argument_list|()
block|;
comment|/// getSizeOfExpr - Return an expression for sizeof AllocTy that is type
comment|/// IntTy
comment|///
specifier|const
name|SCEV
operator|*
name|getSizeOfExpr
argument_list|(
name|Type
operator|*
name|IntTy
argument_list|,
name|Type
operator|*
name|AllocTy
argument_list|)
block|;
comment|/// getOffsetOfExpr - Return an expression for offsetof on the given field
comment|/// with type IntTy
comment|///
specifier|const
name|SCEV
operator|*
name|getOffsetOfExpr
argument_list|(
argument|Type *IntTy
argument_list|,
argument|StructType *STy
argument_list|,
argument|unsigned FieldNo
argument_list|)
block|;
comment|/// getNegativeSCEV - Return the SCEV object corresponding to -V.
comment|///
specifier|const
name|SCEV
operator|*
name|getNegativeSCEV
argument_list|(
specifier|const
name|SCEV
operator|*
name|V
argument_list|)
block|;
comment|/// getNotSCEV - Return the SCEV object corresponding to ~V.
comment|///
specifier|const
name|SCEV
operator|*
name|getNotSCEV
argument_list|(
specifier|const
name|SCEV
operator|*
name|V
argument_list|)
block|;
comment|/// getMinusSCEV - Return LHS-RHS.  Minus is represented in SCEV as A+B*-1.
specifier|const
name|SCEV
operator|*
name|getMinusSCEV
argument_list|(
argument|const SCEV *LHS
argument_list|,
argument|const SCEV *RHS
argument_list|,
argument|SCEV::NoWrapFlags Flags = SCEV::FlagAnyWrap
argument_list|)
block|;
comment|/// getTruncateOrZeroExtend - Return a SCEV corresponding to a conversion
comment|/// of the input value to the specified type.  If the type must be
comment|/// extended, it is zero extended.
specifier|const
name|SCEV
operator|*
name|getTruncateOrZeroExtend
argument_list|(
specifier|const
name|SCEV
operator|*
name|V
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// getTruncateOrSignExtend - Return a SCEV corresponding to a conversion
comment|/// of the input value to the specified type.  If the type must be
comment|/// extended, it is sign extended.
specifier|const
name|SCEV
operator|*
name|getTruncateOrSignExtend
argument_list|(
specifier|const
name|SCEV
operator|*
name|V
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// getNoopOrZeroExtend - Return a SCEV corresponding to a conversion of
comment|/// the input value to the specified type.  If the type must be extended,
comment|/// it is zero extended.  The conversion must not be narrowing.
specifier|const
name|SCEV
operator|*
name|getNoopOrZeroExtend
argument_list|(
specifier|const
name|SCEV
operator|*
name|V
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// getNoopOrSignExtend - Return a SCEV corresponding to a conversion of
comment|/// the input value to the specified type.  If the type must be extended,
comment|/// it is sign extended.  The conversion must not be narrowing.
specifier|const
name|SCEV
operator|*
name|getNoopOrSignExtend
argument_list|(
specifier|const
name|SCEV
operator|*
name|V
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// getNoopOrAnyExtend - Return a SCEV corresponding to a conversion of
comment|/// the input value to the specified type. If the type must be extended,
comment|/// it is extended with unspecified bits. The conversion must not be
comment|/// narrowing.
specifier|const
name|SCEV
operator|*
name|getNoopOrAnyExtend
argument_list|(
specifier|const
name|SCEV
operator|*
name|V
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// getTruncateOrNoop - Return a SCEV corresponding to a conversion of the
comment|/// input value to the specified type.  The conversion must not be
comment|/// widening.
specifier|const
name|SCEV
operator|*
name|getTruncateOrNoop
argument_list|(
specifier|const
name|SCEV
operator|*
name|V
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// getUMaxFromMismatchedTypes - Promote the operands to the wider of
comment|/// the types using zero-extension, and then perform a umax operation
comment|/// with them.
specifier|const
name|SCEV
operator|*
name|getUMaxFromMismatchedTypes
argument_list|(
specifier|const
name|SCEV
operator|*
name|LHS
argument_list|,
specifier|const
name|SCEV
operator|*
name|RHS
argument_list|)
block|;
comment|/// getUMinFromMismatchedTypes - Promote the operands to the wider of
comment|/// the types using zero-extension, and then perform a umin operation
comment|/// with them.
specifier|const
name|SCEV
operator|*
name|getUMinFromMismatchedTypes
argument_list|(
specifier|const
name|SCEV
operator|*
name|LHS
argument_list|,
specifier|const
name|SCEV
operator|*
name|RHS
argument_list|)
block|;
comment|/// getPointerBase - Transitively follow the chain of pointer-type operands
comment|/// until reaching a SCEV that does not have a single pointer operand. This
comment|/// returns a SCEVUnknown pointer for well-formed pointer-type expressions,
comment|/// but corner cases do exist.
specifier|const
name|SCEV
operator|*
name|getPointerBase
argument_list|(
specifier|const
name|SCEV
operator|*
name|V
argument_list|)
block|;
comment|/// getSCEVAtScope - Return a SCEV expression for the specified value
comment|/// at the specified scope in the program.  The L value specifies a loop
comment|/// nest to evaluate the expression at, where null is the top-level or a
comment|/// specified loop is immediately inside of the loop.
comment|///
comment|/// This method can be used to compute the exit value for a variable defined
comment|/// in a loop by querying what the value will hold in the parent loop.
comment|///
comment|/// In the case that a relevant loop exit value cannot be computed, the
comment|/// original value V is returned.
specifier|const
name|SCEV
operator|*
name|getSCEVAtScope
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|,
specifier|const
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|/// getSCEVAtScope - This is a convenience function which does
comment|/// getSCEVAtScope(getSCEV(V), L).
specifier|const
name|SCEV
operator|*
name|getSCEVAtScope
argument_list|(
name|Value
operator|*
name|V
argument_list|,
specifier|const
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|/// isLoopEntryGuardedByCond - Test whether entry to the loop is protected
comment|/// by a conditional between LHS and RHS.  This is used to help avoid max
comment|/// expressions in loop trip counts, and to eliminate casts.
name|bool
name|isLoopEntryGuardedByCond
argument_list|(
argument|const Loop *L
argument_list|,
argument|ICmpInst::Predicate Pred
argument_list|,
argument|const SCEV *LHS
argument_list|,
argument|const SCEV *RHS
argument_list|)
block|;
comment|/// isLoopBackedgeGuardedByCond - Test whether the backedge of the loop is
comment|/// protected by a conditional between LHS and RHS.  This is used to
comment|/// to eliminate casts.
name|bool
name|isLoopBackedgeGuardedByCond
argument_list|(
argument|const Loop *L
argument_list|,
argument|ICmpInst::Predicate Pred
argument_list|,
argument|const SCEV *LHS
argument_list|,
argument|const SCEV *RHS
argument_list|)
block|;
comment|/// getSmallConstantTripCount - Returns the maximum trip count of this loop
comment|/// as a normal unsigned value. Returns 0 if the trip count is unknown or
comment|/// not constant. This "trip count" assumes that control exits via
comment|/// ExitingBlock. More precisely, it is the number of times that control may
comment|/// reach ExitingBlock before taking the branch. For loops with multiple
comment|/// exits, it may not be the number times that the loop header executes if
comment|/// the loop exits prematurely via another branch.
name|unsigned
name|getSmallConstantTripCount
argument_list|(
name|Loop
operator|*
name|L
argument_list|,
name|BasicBlock
operator|*
name|ExitingBlock
argument_list|)
block|;
comment|/// getSmallConstantTripMultiple - Returns the largest constant divisor of
comment|/// the trip count of this loop as a normal unsigned value, if
comment|/// possible. This means that the actual trip count is always a multiple of
comment|/// the returned value (don't forget the trip count could very well be zero
comment|/// as well!). As explained in the comments for getSmallConstantTripCount,
comment|/// this assumes that control exits the loop via ExitingBlock.
name|unsigned
name|getSmallConstantTripMultiple
argument_list|(
name|Loop
operator|*
name|L
argument_list|,
name|BasicBlock
operator|*
name|ExitingBlock
argument_list|)
block|;
comment|// getExitCount - Get the expression for the number of loop iterations for
comment|// which this loop is guaranteed not to exit via ExitingBlock. Otherwise
comment|// return SCEVCouldNotCompute.
specifier|const
name|SCEV
operator|*
name|getExitCount
argument_list|(
name|Loop
operator|*
name|L
argument_list|,
name|BasicBlock
operator|*
name|ExitingBlock
argument_list|)
block|;
comment|/// getBackedgeTakenCount - If the specified loop has a predictable
comment|/// backedge-taken count, return it, otherwise return a SCEVCouldNotCompute
comment|/// object. The backedge-taken count is the number of times the loop header
comment|/// will be branched to from within the loop. This is one less than the
comment|/// trip count of the loop, since it doesn't count the first iteration,
comment|/// when the header is branched to from outside the loop.
comment|///
comment|/// Note that it is not valid to call this method on a loop without a
comment|/// loop-invariant backedge-taken count (see
comment|/// hasLoopInvariantBackedgeTakenCount).
comment|///
specifier|const
name|SCEV
operator|*
name|getBackedgeTakenCount
argument_list|(
specifier|const
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|/// getMaxBackedgeTakenCount - Similar to getBackedgeTakenCount, except
comment|/// return the least SCEV value that is known never to be less than the
comment|/// actual backedge taken count.
specifier|const
name|SCEV
operator|*
name|getMaxBackedgeTakenCount
argument_list|(
specifier|const
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|/// hasLoopInvariantBackedgeTakenCount - Return true if the specified loop
comment|/// has an analyzable loop-invariant backedge-taken count.
name|bool
name|hasLoopInvariantBackedgeTakenCount
argument_list|(
specifier|const
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|/// forgetLoop - This method should be called by the client when it has
comment|/// changed a loop in a way that may effect ScalarEvolution's ability to
comment|/// compute a trip count, or if the loop is deleted.
name|void
name|forgetLoop
argument_list|(
specifier|const
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|/// forgetValue - This method should be called by the client when it has
comment|/// changed a value in a way that may effect its value, or which may
comment|/// disconnect it from a def-use chain linking it to a loop.
name|void
name|forgetValue
argument_list|(
name|Value
operator|*
name|V
argument_list|)
block|;
comment|/// GetMinTrailingZeros - Determine the minimum number of zero bits that S
comment|/// is guaranteed to end in (at every loop iteration).  It is, at the same
comment|/// time, the minimum number of times S is divisible by 2.  For example,
comment|/// given {4,+,8} it returns 2.  If S is guaranteed to be 0, it returns the
comment|/// bitwidth of S.
name|uint32_t
name|GetMinTrailingZeros
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|)
block|;
comment|/// getUnsignedRange - Determine the unsigned range for a particular SCEV.
comment|///
name|ConstantRange
name|getUnsignedRange
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|)
block|;
comment|/// getSignedRange - Determine the signed range for a particular SCEV.
comment|///
name|ConstantRange
name|getSignedRange
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|)
block|;
comment|/// isKnownNegative - Test if the given expression is known to be negative.
comment|///
name|bool
name|isKnownNegative
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|)
block|;
comment|/// isKnownPositive - Test if the given expression is known to be positive.
comment|///
name|bool
name|isKnownPositive
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|)
block|;
comment|/// isKnownNonNegative - Test if the given expression is known to be
comment|/// non-negative.
comment|///
name|bool
name|isKnownNonNegative
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|)
block|;
comment|/// isKnownNonPositive - Test if the given expression is known to be
comment|/// non-positive.
comment|///
name|bool
name|isKnownNonPositive
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|)
block|;
comment|/// isKnownNonZero - Test if the given expression is known to be
comment|/// non-zero.
comment|///
name|bool
name|isKnownNonZero
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|)
block|;
comment|/// isKnownPredicate - Test if the given expression is known to satisfy
comment|/// the condition described by Pred, LHS, and RHS.
comment|///
name|bool
name|isKnownPredicate
argument_list|(
argument|ICmpInst::Predicate Pred
argument_list|,
argument|const SCEV *LHS
argument_list|,
argument|const SCEV *RHS
argument_list|)
block|;
comment|/// SimplifyICmpOperands - Simplify LHS and RHS in a comparison with
comment|/// predicate Pred. Return true iff any changes were made. If the
comment|/// operands are provably equal or unequal, LHS and RHS are set to
comment|/// the same value and Pred is set to either ICMP_EQ or ICMP_NE.
comment|///
name|bool
name|SimplifyICmpOperands
argument_list|(
argument|ICmpInst::Predicate&Pred
argument_list|,
argument|const SCEV *&LHS
argument_list|,
argument|const SCEV *&RHS
argument_list|,
argument|unsigned Depth =
literal|0
argument_list|)
block|;
comment|/// getLoopDisposition - Return the "disposition" of the given SCEV with
comment|/// respect to the given loop.
name|LoopDisposition
name|getLoopDisposition
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|,
specifier|const
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|/// isLoopInvariant - Return true if the value of the given SCEV is
comment|/// unchanging in the specified loop.
name|bool
name|isLoopInvariant
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|,
specifier|const
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|/// hasComputableLoopEvolution - Return true if the given SCEV changes value
comment|/// in a known way in the specified loop.  This property being true implies
comment|/// that the value is variant in the loop AND that we can emit an expression
comment|/// to compute the value of the expression at any particular loop iteration.
name|bool
name|hasComputableLoopEvolution
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|,
specifier|const
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|/// getLoopDisposition - Return the "disposition" of the given SCEV with
comment|/// respect to the given block.
name|BlockDisposition
name|getBlockDisposition
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|,
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
block|;
comment|/// dominates - Return true if elements that makes up the given SCEV
comment|/// dominate the specified basic block.
name|bool
name|dominates
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|,
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
block|;
comment|/// properlyDominates - Return true if elements that makes up the given SCEV
comment|/// properly dominate the specified basic block.
name|bool
name|properlyDominates
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|,
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
block|;
comment|/// hasOperand - Test whether the given SCEV has Op as a direct or
comment|/// indirect operand.
name|bool
name|hasOperand
argument_list|(
argument|const SCEV *S
argument_list|,
argument|const SCEV *Op
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|runOnFunction
argument_list|(
name|Function
operator|&
name|F
argument_list|)
block|;
name|virtual
name|void
name|releaseMemory
argument_list|()
block|;
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const Module* =
literal|0
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|verifyAnalysis
argument_list|()
specifier|const
block|;
name|private
operator|:
comment|/// Compute the backedge taken count knowing the interval difference, the
comment|/// stride and presence of the equality in the comparison.
specifier|const
name|SCEV
operator|*
name|computeBECount
argument_list|(
argument|const SCEV *Delta
argument_list|,
argument|const SCEV *Stride
argument_list|,
argument|bool Equality
argument_list|)
block|;
comment|/// Verify if an linear IV with positive stride can overflow when in a
comment|/// less-than comparison, knowing the invariant term of the comparison,
comment|/// the stride and the knowledge of NSW/NUW flags on the recurrence.
name|bool
name|doesIVOverflowOnLT
argument_list|(
argument|const SCEV *RHS
argument_list|,
argument|const SCEV *Stride
argument_list|,
argument|bool IsSigned
argument_list|,
argument|bool NoWrap
argument_list|)
block|;
comment|/// Verify if an linear IV with negative stride can overflow when in a
comment|/// greater-than comparison, knowing the invariant term of the comparison,
comment|/// the stride and the knowledge of NSW/NUW flags on the recurrence.
name|bool
name|doesIVOverflowOnGT
argument_list|(
argument|const SCEV *RHS
argument_list|,
argument|const SCEV *Stride
argument_list|,
argument|bool IsSigned
argument_list|,
argument|bool NoWrap
argument_list|)
block|;
name|private
operator|:
name|FoldingSet
operator|<
name|SCEV
operator|>
name|UniqueSCEVs
block|;
name|BumpPtrAllocator
name|SCEVAllocator
block|;
comment|/// FirstUnknown - The head of a linked list of all SCEVUnknown
comment|/// values that have been allocated. This is used by releaseMemory
comment|/// to locate them all and call their destructors.
name|SCEVUnknown
operator|*
name|FirstUnknown
block|;   }
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

