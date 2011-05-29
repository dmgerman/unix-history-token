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
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Instructions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Operator.h"
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
file|"llvm/ADT/FoldingSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
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
name|TargetData
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
specifier|const
name|SCEV
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
operator|=
operator|(
specifier|const
name|SCEV
operator|&
operator|)
block|;
comment|// DO NOT IMPLEMENT
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
specifier|const
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
specifier|inline
name|bool
name|classof
argument_list|(
argument|const SCEVCouldNotCompute *S
argument_list|)
block|{
return|return
name|true
return|;
block|}
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
name|TargetData
operator|*
name|TD
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
comment|/// BackedgeTakenInfo - Information about the backedge-taken count
comment|/// of a loop. This currently includes an exact count and a maximum count.
comment|///
block|struct
name|BackedgeTakenInfo
block|{
comment|/// Exact - An expression indicating the exact backedge-taken count of
comment|/// the loop if it is known, or a SCEVCouldNotCompute otherwise.
specifier|const
name|SCEV
operator|*
name|Exact
block|;
comment|/// Max - An expression indicating the least maximum backedge-taken
comment|/// count of the loop that is known, or a SCEVCouldNotCompute.
specifier|const
name|SCEV
operator|*
name|Max
block|;
comment|/*implicit*/
name|BackedgeTakenInfo
argument_list|(
specifier|const
name|SCEV
operator|*
name|exact
argument_list|)
operator|:
name|Exact
argument_list|(
name|exact
argument_list|)
block|,
name|Max
argument_list|(
argument|exact
argument_list|)
block|{}
name|BackedgeTakenInfo
argument_list|(
specifier|const
name|SCEV
operator|*
name|exact
argument_list|,
specifier|const
name|SCEV
operator|*
name|max
argument_list|)
operator|:
name|Exact
argument_list|(
name|exact
argument_list|)
block|,
name|Max
argument_list|(
argument|max
argument_list|)
block|{}
comment|/// hasAnyInfo - Test whether this BackedgeTakenInfo contains any
comment|/// computed information, or whether it's all SCEVCouldNotCompute
comment|/// values.
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
comment|/// BackedgeTakenCounts - Cache the backedge-taken count of the loops for
comment|/// this function as they are computed.
name|std
operator|::
name|map
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
name|std
operator|::
name|map
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
name|std
operator|::
name|map
operator|<
specifier|const
name|SCEV
operator|*
block|,
name|std
operator|::
name|map
operator|<
specifier|const
name|Loop
operator|*
block|,
specifier|const
name|SCEV
operator|*
operator|>
expr|>
name|ValuesAtScopes
block|;
comment|/// LoopDispositions - Memoized computeLoopDisposition results.
name|std
operator|::
name|map
operator|<
specifier|const
name|SCEV
operator|*
block|,
name|std
operator|::
name|map
operator|<
specifier|const
name|Loop
operator|*
block|,
name|LoopDisposition
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
name|std
operator|::
name|map
operator|<
specifier|const
name|SCEV
operator|*
block|,
name|std
operator|::
name|map
operator|<
specifier|const
name|BasicBlock
operator|*
block|,
name|BlockDisposition
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
modifier|*
name|createSCEV
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// createNodeForPHI - Provide the special handling we need to analyze PHI
comment|/// SCEVs.
specifier|const
name|SCEV
modifier|*
name|createNodeForPHI
parameter_list|(
name|PHINode
modifier|*
name|PN
parameter_list|)
function_decl|;
comment|/// createNodeForGEP - Provide the special handling we need to analyze GEP
comment|/// SCEVs.
specifier|const
name|SCEV
modifier|*
name|createNodeForGEP
parameter_list|(
name|GEPOperator
modifier|*
name|GEP
parameter_list|)
function_decl|;
comment|/// computeSCEVAtScope - Implementation code for getSCEVAtScope; called
comment|/// at most once for each SCEV+Loop pair.
comment|///
specifier|const
name|SCEV
modifier|*
name|computeSCEVAtScope
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|,
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// ForgetSymbolicValue - This looks up computed SCEV values for all
comment|/// instructions that depend on the given instruction and removes them from
comment|/// the ValueExprMap map if they reference SymName. This is used during PHI
comment|/// resolution.
name|void
name|ForgetSymbolicName
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|SymName
parameter_list|)
function_decl|;
comment|/// getBECount - Subtract the end and start values and divide by the step,
comment|/// rounding up, to get the number of times the backedge is executed. Return
comment|/// CouldNotCompute if an intermediate computation overflows.
specifier|const
name|SCEV
modifier|*
name|getBECount
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|Start
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|End
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|Step
parameter_list|,
name|bool
name|NoWrap
parameter_list|)
function_decl|;
comment|/// getBackedgeTakenInfo - Return the BackedgeTakenInfo for the given
comment|/// loop, lazily computing new values if the loop hasn't been analyzed
comment|/// yet.
specifier|const
name|BackedgeTakenInfo
modifier|&
name|getBackedgeTakenInfo
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// ComputeBackedgeTakenCount - Compute the number of times the specified
comment|/// loop will iterate.
name|BackedgeTakenInfo
name|ComputeBackedgeTakenCount
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// ComputeBackedgeTakenCountFromExit - Compute the number of times the
comment|/// backedge of the specified loop will execute if it exits via the
comment|/// specified block.
name|BackedgeTakenInfo
name|ComputeBackedgeTakenCountFromExit
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|,
name|BasicBlock
modifier|*
name|ExitingBlock
parameter_list|)
function_decl|;
comment|/// ComputeBackedgeTakenCountFromExitCond - Compute the number of times the
comment|/// backedge of the specified loop will execute if its exit condition
comment|/// were a conditional branch of ExitCond, TBB, and FBB.
name|BackedgeTakenInfo
name|ComputeBackedgeTakenCountFromExitCond
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|,
name|Value
modifier|*
name|ExitCond
parameter_list|,
name|BasicBlock
modifier|*
name|TBB
parameter_list|,
name|BasicBlock
modifier|*
name|FBB
parameter_list|)
function_decl|;
comment|/// ComputeBackedgeTakenCountFromExitCondICmp - Compute the number of
comment|/// times the backedge of the specified loop will execute if its exit
comment|/// condition were a conditional branch of the ICmpInst ExitCond, TBB,
comment|/// and FBB.
name|BackedgeTakenInfo
name|ComputeBackedgeTakenCountFromExitCondICmp
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|,
name|ICmpInst
modifier|*
name|ExitCond
parameter_list|,
name|BasicBlock
modifier|*
name|TBB
parameter_list|,
name|BasicBlock
modifier|*
name|FBB
parameter_list|)
function_decl|;
comment|/// ComputeLoadConstantCompareBackedgeTakenCount - Given an exit condition
comment|/// of 'icmp op load X, cst', try to see if we can compute the
comment|/// backedge-taken count.
name|BackedgeTakenInfo
name|ComputeLoadConstantCompareBackedgeTakenCount
argument_list|(
name|LoadInst
operator|*
name|LI
argument_list|,
name|Constant
operator|*
name|RHS
argument_list|,
specifier|const
name|Loop
operator|*
name|L
argument_list|,
name|ICmpInst
operator|::
name|Predicate
name|p
argument_list|)
decl_stmt|;
comment|/// ComputeBackedgeTakenCountExhaustively - If the loop is known to execute
comment|/// a constant number of times (the condition evolves only from constants),
comment|/// try to evaluate a few iterations of the loop until we get the exit
comment|/// condition gets a value of ExitWhen (true or false).  If we cannot
comment|/// evaluate the backedge-taken count of the loop, return CouldNotCompute.
specifier|const
name|SCEV
modifier|*
name|ComputeBackedgeTakenCountExhaustively
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|,
name|Value
modifier|*
name|Cond
parameter_list|,
name|bool
name|ExitWhen
parameter_list|)
function_decl|;
comment|/// HowFarToZero - Return the number of times a backedge comparing the
comment|/// specified value to zero will execute.  If not computable, return
comment|/// CouldNotCompute.
name|BackedgeTakenInfo
name|HowFarToZero
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|V
parameter_list|,
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// HowFarToNonZero - Return the number of times a backedge checking the
comment|/// specified value for nonzero will execute.  If not computable, return
comment|/// CouldNotCompute.
name|BackedgeTakenInfo
name|HowFarToNonZero
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|V
parameter_list|,
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// HowManyLessThans - Return the number of times a backedge containing the
comment|/// specified less-than comparison will execute.  If not computable, return
comment|/// CouldNotCompute. isSigned specifies whether the less-than is signed.
name|BackedgeTakenInfo
name|HowManyLessThans
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|LHS
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|RHS
parameter_list|,
specifier|const
name|Loop
modifier|*
name|L
parameter_list|,
name|bool
name|isSigned
parameter_list|)
function_decl|;
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
operator|,
name|BasicBlock
operator|*
operator|>
name|getPredecessorWithUniqueSuccessorForBB
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
expr_stmt|;
comment|/// isImpliedCond - Test whether the condition described by Pred, LHS, and
comment|/// RHS is true whenever the given FoundCondValue value evaluates to true.
name|bool
name|isImpliedCond
argument_list|(
name|ICmpInst
operator|::
name|Predicate
name|Pred
argument_list|,
specifier|const
name|SCEV
operator|*
name|LHS
argument_list|,
specifier|const
name|SCEV
operator|*
name|RHS
argument_list|,
name|Value
operator|*
name|FoundCondValue
argument_list|,
name|bool
name|Inverse
argument_list|)
decl_stmt|;
comment|/// isImpliedCondOperands - Test whether the condition described by Pred,
comment|/// LHS, and RHS is true whenever the condition described by Pred, FoundLHS,
comment|/// and FoundRHS is true.
name|bool
name|isImpliedCondOperands
argument_list|(
name|ICmpInst
operator|::
name|Predicate
name|Pred
argument_list|,
specifier|const
name|SCEV
operator|*
name|LHS
argument_list|,
specifier|const
name|SCEV
operator|*
name|RHS
argument_list|,
specifier|const
name|SCEV
operator|*
name|FoundLHS
argument_list|,
specifier|const
name|SCEV
operator|*
name|FoundRHS
argument_list|)
decl_stmt|;
comment|/// isImpliedCondOperandsHelper - Test whether the condition described by
comment|/// Pred, LHS, and RHS is true whenever the condition described by Pred,
comment|/// FoundLHS, and FoundRHS is true.
name|bool
name|isImpliedCondOperandsHelper
argument_list|(
name|ICmpInst
operator|::
name|Predicate
name|Pred
argument_list|,
specifier|const
name|SCEV
operator|*
name|LHS
argument_list|,
specifier|const
name|SCEV
operator|*
name|RHS
argument_list|,
specifier|const
name|SCEV
operator|*
name|FoundLHS
argument_list|,
specifier|const
name|SCEV
operator|*
name|FoundRHS
argument_list|)
decl_stmt|;
comment|/// getConstantEvolutionLoopExitValue - If we know that the specified Phi is
comment|/// in the header of its containing loop, we know the loop executes a
comment|/// constant number of times, and the PHI node is just a recurrence
comment|/// involving constants, fold it.
name|Constant
modifier|*
name|getConstantEvolutionLoopExitValue
parameter_list|(
name|PHINode
modifier|*
name|PN
parameter_list|,
specifier|const
name|APInt
modifier|&
name|BEs
parameter_list|,
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// isKnownPredicateWithRanges - Test if the given expression is known to
comment|/// satisfy the condition described by Pred and the known constant ranges
comment|/// of LHS and RHS.
comment|///
name|bool
name|isKnownPredicateWithRanges
argument_list|(
name|ICmpInst
operator|::
name|Predicate
name|Pred
argument_list|,
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
decl_stmt|;
comment|/// forgetMemoizedResults - Drop memoized information computed for S.
name|void
name|forgetMemoizedResults
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
function_decl|;
name|public
label|:
specifier|static
name|char
name|ID
decl_stmt|;
comment|// Pass identification, replacement for typeid
name|ScalarEvolution
argument_list|()
expr_stmt|;
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
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// getTypeSizeInBits - Return the size in bits of the specified type,
comment|/// for which isSCEVable must return true.
name|uint64_t
name|getTypeSizeInBits
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// getEffectiveSCEVType - Return a type with the same bitwidth as
comment|/// the given type and which represents how SCEV will treat the given
comment|/// type, for which isSCEVable must return true. For pointer types,
comment|/// this is the pointer-sized integer type.
specifier|const
name|Type
modifier|*
name|getEffectiveSCEVType
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// getSCEV - Return a SCEV expression for the full generality of the
comment|/// specified expression.
specifier|const
name|SCEV
modifier|*
name|getSCEV
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
specifier|const
name|SCEV
modifier|*
name|getConstant
parameter_list|(
name|ConstantInt
modifier|*
name|V
parameter_list|)
function_decl|;
specifier|const
name|SCEV
modifier|*
name|getConstant
parameter_list|(
specifier|const
name|APInt
modifier|&
name|Val
parameter_list|)
function_decl|;
specifier|const
name|SCEV
modifier|*
name|getConstant
parameter_list|(
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|,
name|uint64_t
name|V
parameter_list|,
name|bool
name|isSigned
init|=
name|false
parameter_list|)
function_decl|;
specifier|const
name|SCEV
modifier|*
name|getTruncateExpr
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|Op
parameter_list|,
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
specifier|const
name|SCEV
modifier|*
name|getZeroExtendExpr
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|Op
parameter_list|,
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
specifier|const
name|SCEV
modifier|*
name|getSignExtendExpr
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|Op
parameter_list|,
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
specifier|const
name|SCEV
modifier|*
name|getAnyExtendExpr
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|Op
parameter_list|,
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
specifier|const
name|SCEV
modifier|*
name|getAddExpr
argument_list|(
name|SmallVectorImpl
operator|<
specifier|const
name|SCEV
operator|*
operator|>
operator|&
name|Ops
argument_list|,
name|SCEV
operator|::
name|NoWrapFlags
name|Flags
operator|=
name|SCEV
operator|::
name|FlagAnyWrap
argument_list|)
decl_stmt|;
specifier|const
name|SCEV
modifier|*
name|getAddExpr
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
argument_list|,
name|SCEV
operator|::
name|NoWrapFlags
name|Flags
operator|=
name|SCEV
operator|::
name|FlagAnyWrap
argument_list|)
block|{
name|SmallVector
operator|<
specifier|const
name|SCEV
operator|*
operator|,
literal|2
operator|>
name|Ops
expr_stmt|;
name|Ops
operator|.
name|push_back
argument_list|(
name|LHS
argument_list|)
expr_stmt|;
name|Ops
operator|.
name|push_back
argument_list|(
name|RHS
argument_list|)
expr_stmt|;
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
modifier|*
name|getAddExpr
argument_list|(
specifier|const
name|SCEV
operator|*
name|Op0
argument_list|,
specifier|const
name|SCEV
operator|*
name|Op1
argument_list|,
specifier|const
name|SCEV
operator|*
name|Op2
argument_list|,
name|SCEV
operator|::
name|NoWrapFlags
name|Flags
operator|=
name|SCEV
operator|::
name|FlagAnyWrap
argument_list|)
block|{
name|SmallVector
operator|<
specifier|const
name|SCEV
operator|*
operator|,
literal|3
operator|>
name|Ops
expr_stmt|;
name|Ops
operator|.
name|push_back
argument_list|(
name|Op0
argument_list|)
expr_stmt|;
name|Ops
operator|.
name|push_back
argument_list|(
name|Op1
argument_list|)
expr_stmt|;
name|Ops
operator|.
name|push_back
argument_list|(
name|Op2
argument_list|)
expr_stmt|;
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
modifier|*
name|getMulExpr
argument_list|(
name|SmallVectorImpl
operator|<
specifier|const
name|SCEV
operator|*
operator|>
operator|&
name|Ops
argument_list|,
name|SCEV
operator|::
name|NoWrapFlags
name|Flags
operator|=
name|SCEV
operator|::
name|FlagAnyWrap
argument_list|)
decl_stmt|;
specifier|const
name|SCEV
modifier|*
name|getMulExpr
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
argument_list|,
name|SCEV
operator|::
name|NoWrapFlags
name|Flags
operator|=
name|SCEV
operator|::
name|FlagAnyWrap
argument_list|)
block|{
name|SmallVector
operator|<
specifier|const
name|SCEV
operator|*
operator|,
literal|2
operator|>
name|Ops
expr_stmt|;
name|Ops
operator|.
name|push_back
argument_list|(
name|LHS
argument_list|)
expr_stmt|;
name|Ops
operator|.
name|push_back
argument_list|(
name|RHS
argument_list|)
expr_stmt|;
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
modifier|*
name|getUDivExpr
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|LHS
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|RHS
parameter_list|)
function_decl|;
specifier|const
name|SCEV
modifier|*
name|getAddRecExpr
argument_list|(
specifier|const
name|SCEV
operator|*
name|Start
argument_list|,
specifier|const
name|SCEV
operator|*
name|Step
argument_list|,
specifier|const
name|Loop
operator|*
name|L
argument_list|,
name|SCEV
operator|::
name|NoWrapFlags
name|Flags
argument_list|)
decl_stmt|;
specifier|const
name|SCEV
modifier|*
name|getAddRecExpr
argument_list|(
name|SmallVectorImpl
operator|<
specifier|const
name|SCEV
operator|*
operator|>
operator|&
name|Operands
argument_list|,
specifier|const
name|Loop
operator|*
name|L
argument_list|,
name|SCEV
operator|::
name|NoWrapFlags
name|Flags
argument_list|)
decl_stmt|;
specifier|const
name|SCEV
modifier|*
name|getAddRecExpr
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
specifier|const
name|SCEV
operator|*
operator|>
operator|&
name|Operands
argument_list|,
specifier|const
name|Loop
operator|*
name|L
argument_list|,
name|SCEV
operator|::
name|NoWrapFlags
name|Flags
argument_list|)
block|{
name|SmallVector
operator|<
specifier|const
name|SCEV
operator|*
operator|,
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
expr_stmt|;
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
modifier|*
name|getSMaxExpr
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|LHS
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|RHS
parameter_list|)
function_decl|;
specifier|const
name|SCEV
modifier|*
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
decl_stmt|;
specifier|const
name|SCEV
modifier|*
name|getUMaxExpr
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|LHS
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|RHS
parameter_list|)
function_decl|;
specifier|const
name|SCEV
modifier|*
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
decl_stmt|;
specifier|const
name|SCEV
modifier|*
name|getSMinExpr
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|LHS
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|RHS
parameter_list|)
function_decl|;
specifier|const
name|SCEV
modifier|*
name|getUMinExpr
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|LHS
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|RHS
parameter_list|)
function_decl|;
specifier|const
name|SCEV
modifier|*
name|getUnknown
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
specifier|const
name|SCEV
modifier|*
name|getCouldNotCompute
parameter_list|()
function_decl|;
comment|/// getSizeOfExpr - Return an expression for sizeof on the given type.
comment|///
specifier|const
name|SCEV
modifier|*
name|getSizeOfExpr
parameter_list|(
specifier|const
name|Type
modifier|*
name|AllocTy
parameter_list|)
function_decl|;
comment|/// getAlignOfExpr - Return an expression for alignof on the given type.
comment|///
specifier|const
name|SCEV
modifier|*
name|getAlignOfExpr
parameter_list|(
specifier|const
name|Type
modifier|*
name|AllocTy
parameter_list|)
function_decl|;
comment|/// getOffsetOfExpr - Return an expression for offsetof on the given field.
comment|///
specifier|const
name|SCEV
modifier|*
name|getOffsetOfExpr
parameter_list|(
specifier|const
name|StructType
modifier|*
name|STy
parameter_list|,
name|unsigned
name|FieldNo
parameter_list|)
function_decl|;
comment|/// getOffsetOfExpr - Return an expression for offsetof on the given field.
comment|///
specifier|const
name|SCEV
modifier|*
name|getOffsetOfExpr
parameter_list|(
specifier|const
name|Type
modifier|*
name|CTy
parameter_list|,
name|Constant
modifier|*
name|FieldNo
parameter_list|)
function_decl|;
comment|/// getNegativeSCEV - Return the SCEV object corresponding to -V.
comment|///
specifier|const
name|SCEV
modifier|*
name|getNegativeSCEV
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// getNotSCEV - Return the SCEV object corresponding to ~V.
comment|///
specifier|const
name|SCEV
modifier|*
name|getNotSCEV
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// getMinusSCEV - Return LHS-RHS.  Minus is represented in SCEV as A+B*-1.
specifier|const
name|SCEV
modifier|*
name|getMinusSCEV
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
argument_list|,
name|SCEV
operator|::
name|NoWrapFlags
name|Flags
operator|=
name|SCEV
operator|::
name|FlagAnyWrap
argument_list|)
decl_stmt|;
comment|/// getTruncateOrZeroExtend - Return a SCEV corresponding to a conversion
comment|/// of the input value to the specified type.  If the type must be
comment|/// extended, it is zero extended.
specifier|const
name|SCEV
modifier|*
name|getTruncateOrZeroExtend
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|V
parameter_list|,
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|/// getTruncateOrSignExtend - Return a SCEV corresponding to a conversion
comment|/// of the input value to the specified type.  If the type must be
comment|/// extended, it is sign extended.
specifier|const
name|SCEV
modifier|*
name|getTruncateOrSignExtend
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|V
parameter_list|,
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|/// getNoopOrZeroExtend - Return a SCEV corresponding to a conversion of
comment|/// the input value to the specified type.  If the type must be extended,
comment|/// it is zero extended.  The conversion must not be narrowing.
specifier|const
name|SCEV
modifier|*
name|getNoopOrZeroExtend
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|V
parameter_list|,
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|/// getNoopOrSignExtend - Return a SCEV corresponding to a conversion of
comment|/// the input value to the specified type.  If the type must be extended,
comment|/// it is sign extended.  The conversion must not be narrowing.
specifier|const
name|SCEV
modifier|*
name|getNoopOrSignExtend
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|V
parameter_list|,
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|/// getNoopOrAnyExtend - Return a SCEV corresponding to a conversion of
comment|/// the input value to the specified type. If the type must be extended,
comment|/// it is extended with unspecified bits. The conversion must not be
comment|/// narrowing.
specifier|const
name|SCEV
modifier|*
name|getNoopOrAnyExtend
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|V
parameter_list|,
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|/// getTruncateOrNoop - Return a SCEV corresponding to a conversion of the
comment|/// input value to the specified type.  The conversion must not be
comment|/// widening.
specifier|const
name|SCEV
modifier|*
name|getTruncateOrNoop
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|V
parameter_list|,
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|/// getUMaxFromMismatchedTypes - Promote the operands to the wider of
comment|/// the types using zero-extension, and then perform a umax operation
comment|/// with them.
specifier|const
name|SCEV
modifier|*
name|getUMaxFromMismatchedTypes
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|LHS
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|RHS
parameter_list|)
function_decl|;
comment|/// getUMinFromMismatchedTypes - Promote the operands to the wider of
comment|/// the types using zero-extension, and then perform a umin operation
comment|/// with them.
specifier|const
name|SCEV
modifier|*
name|getUMinFromMismatchedTypes
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|LHS
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|RHS
parameter_list|)
function_decl|;
comment|/// getPointerBase - Transitively follow the chain of pointer-type operands
comment|/// until reaching a SCEV that does not have a single pointer operand. This
comment|/// returns a SCEVUnknown pointer for well-formed pointer-type expressions,
comment|/// but corner cases do exist.
specifier|const
name|SCEV
modifier|*
name|getPointerBase
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|V
parameter_list|)
function_decl|;
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
modifier|*
name|getSCEVAtScope
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|,
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// getSCEVAtScope - This is a convenience function which does
comment|/// getSCEVAtScope(getSCEV(V), L).
specifier|const
name|SCEV
modifier|*
name|getSCEVAtScope
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// isLoopEntryGuardedByCond - Test whether entry to the loop is protected
comment|/// by a conditional between LHS and RHS.  This is used to help avoid max
comment|/// expressions in loop trip counts, and to eliminate casts.
name|bool
name|isLoopEntryGuardedByCond
argument_list|(
specifier|const
name|Loop
operator|*
name|L
argument_list|,
name|ICmpInst
operator|::
name|Predicate
name|Pred
argument_list|,
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
decl_stmt|;
comment|/// isLoopBackedgeGuardedByCond - Test whether the backedge of the loop is
comment|/// protected by a conditional between LHS and RHS.  This is used to
comment|/// to eliminate casts.
name|bool
name|isLoopBackedgeGuardedByCond
argument_list|(
specifier|const
name|Loop
operator|*
name|L
argument_list|,
name|ICmpInst
operator|::
name|Predicate
name|Pred
argument_list|,
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
decl_stmt|;
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
modifier|*
name|getBackedgeTakenCount
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// getMaxBackedgeTakenCount - Similar to getBackedgeTakenCount, except
comment|/// return the least SCEV value that is known never to be less than the
comment|/// actual backedge taken count.
specifier|const
name|SCEV
modifier|*
name|getMaxBackedgeTakenCount
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// hasLoopInvariantBackedgeTakenCount - Return true if the specified loop
comment|/// has an analyzable loop-invariant backedge-taken count.
name|bool
name|hasLoopInvariantBackedgeTakenCount
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// forgetLoop - This method should be called by the client when it has
comment|/// changed a loop in a way that may effect ScalarEvolution's ability to
comment|/// compute a trip count, or if the loop is deleted.
name|void
name|forgetLoop
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// forgetValue - This method should be called by the client when it has
comment|/// changed a value in a way that may effect its value, or which may
comment|/// disconnect it from a def-use chain linking it to a loop.
name|void
name|forgetValue
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// GetMinTrailingZeros - Determine the minimum number of zero bits that S
comment|/// is guaranteed to end in (at every loop iteration).  It is, at the same
comment|/// time, the minimum number of times S is divisible by 2.  For example,
comment|/// given {4,+,8} it returns 2.  If S is guaranteed to be 0, it returns the
comment|/// bitwidth of S.
name|uint32_t
name|GetMinTrailingZeros
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
function_decl|;
comment|/// getUnsignedRange - Determine the unsigned range for a particular SCEV.
comment|///
name|ConstantRange
name|getUnsignedRange
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
function_decl|;
comment|/// getSignedRange - Determine the signed range for a particular SCEV.
comment|///
name|ConstantRange
name|getSignedRange
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
function_decl|;
comment|/// isKnownNegative - Test if the given expression is known to be negative.
comment|///
name|bool
name|isKnownNegative
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
function_decl|;
comment|/// isKnownPositive - Test if the given expression is known to be positive.
comment|///
name|bool
name|isKnownPositive
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
function_decl|;
comment|/// isKnownNonNegative - Test if the given expression is known to be
comment|/// non-negative.
comment|///
name|bool
name|isKnownNonNegative
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
function_decl|;
comment|/// isKnownNonPositive - Test if the given expression is known to be
comment|/// non-positive.
comment|///
name|bool
name|isKnownNonPositive
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
function_decl|;
comment|/// isKnownNonZero - Test if the given expression is known to be
comment|/// non-zero.
comment|///
name|bool
name|isKnownNonZero
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
function_decl|;
comment|/// isKnownPredicate - Test if the given expression is known to satisfy
comment|/// the condition described by Pred, LHS, and RHS.
comment|///
name|bool
name|isKnownPredicate
argument_list|(
name|ICmpInst
operator|::
name|Predicate
name|Pred
argument_list|,
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
decl_stmt|;
comment|/// SimplifyICmpOperands - Simplify LHS and RHS in a comparison with
comment|/// predicate Pred. Return true iff any changes were made. If the
comment|/// operands are provably equal or inequal, LHS and RHS are set to
comment|/// the same value and Pred is set to either ICMP_EQ or ICMP_NE.
comment|///
name|bool
name|SimplifyICmpOperands
argument_list|(
name|ICmpInst
operator|::
name|Predicate
operator|&
name|Pred
argument_list|,
specifier|const
name|SCEV
operator|*
operator|&
name|LHS
argument_list|,
specifier|const
name|SCEV
operator|*
operator|&
name|RHS
argument_list|)
decl_stmt|;
comment|/// getLoopDisposition - Return the "disposition" of the given SCEV with
comment|/// respect to the given loop.
name|LoopDisposition
name|getLoopDisposition
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|,
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// isLoopInvariant - Return true if the value of the given SCEV is
comment|/// unchanging in the specified loop.
name|bool
name|isLoopInvariant
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|,
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// hasComputableLoopEvolution - Return true if the given SCEV changes value
comment|/// in a known way in the specified loop.  This property being true implies
comment|/// that the value is variant in the loop AND that we can emit an expression
comment|/// to compute the value of the expression at any particular loop iteration.
name|bool
name|hasComputableLoopEvolution
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|,
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// getLoopDisposition - Return the "disposition" of the given SCEV with
comment|/// respect to the given block.
name|BlockDisposition
name|getBlockDisposition
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|,
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// dominates - Return true if elements that makes up the given SCEV
comment|/// dominate the specified basic block.
name|bool
name|dominates
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|,
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// properlyDominates - Return true if elements that makes up the given SCEV
comment|/// properly dominate the specified basic block.
name|bool
name|properlyDominates
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|,
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// hasOperand - Test whether the given SCEV has Op as a direct or
comment|/// indirect operand.
name|bool
name|hasOperand
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|,
specifier|const
name|SCEV
operator|*
name|Op
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|bool
name|runOnFunction
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
name|virtual
name|void
name|releaseMemory
parameter_list|()
function_decl|;
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|AU
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|Module
operator|*
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|FoldingSet
operator|<
name|SCEV
operator|>
name|UniqueSCEVs
expr_stmt|;
name|BumpPtrAllocator
name|SCEVAllocator
decl_stmt|;
comment|/// FirstUnknown - The head of a linked list of all SCEVUnknown
comment|/// values that have been allocated. This is used by releaseMemory
comment|/// to locate them all and call their destructors.
name|SCEVUnknown
modifier|*
name|FirstUnknown
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

