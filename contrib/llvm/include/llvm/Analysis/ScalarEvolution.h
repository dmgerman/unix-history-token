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
file|"llvm/Analysis/LoopInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ConstantRange.h"
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
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
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
file|"llvm/Support/DataTypes.h"
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
name|AssumptionCache
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
name|Operator
decl_stmt|;
name|class
name|SCEV
decl_stmt|;
name|class
name|SCEVAddRecExpr
decl_stmt|;
name|class
name|SCEVConstant
decl_stmt|;
name|class
name|SCEVExpander
decl_stmt|;
name|class
name|SCEVPredicate
decl_stmt|;
name|class
name|SCEVUnknown
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
name|template
operator|<
operator|>
expr|struct
name|FoldingSetTrait
operator|<
name|SCEVPredicate
operator|>
expr_stmt|;
comment|/// This class represents an analyzed expression in the program.  These are
comment|/// opaque objects that the client is not allowed to do much with directly.
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
comment|/// A reference to an Interned FoldingSetNodeID for this node.  The
comment|/// ScalarEvolution's BumpPtrAllocator holds the data.
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
comment|/// This field is initialized to zero and may be used in subclasses to store
comment|/// miscellaneous information.
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
operator|=
name|delete
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|SCEV
operator|&
operator|)
operator|=
name|delete
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
comment|/// AddRec expressions may have a no-self-wraparound<NW> property if, in
comment|/// the integer domain, abs(step) * max-iteration(loop)<=
comment|/// unsigned-max(bitwidth).  This means that the recurrence will never reach
comment|/// its start value if the step is non-zero.  Computing the same value on
comment|/// each iteration is not considered wrapping, and recurrences with step = 0
comment|/// are trivially<NW>.<NW> is independent of the sign of step and the
comment|/// value the add recurrence starts with.
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
comment|/// Return the LLVM type of this SCEV expression.
comment|///
name|Type
operator|*
name|getType
argument_list|()
specifier|const
block|;
comment|/// Return true if the expression is a constant zero.
comment|///
name|bool
name|isZero
argument_list|()
specifier|const
block|;
comment|/// Return true if the expression is a constant one.
comment|///
name|bool
name|isOne
argument_list|()
specifier|const
block|;
comment|/// Return true if the expression is a constant all-ones value.
comment|///
name|bool
name|isAllOnesValue
argument_list|()
specifier|const
block|;
comment|/// Return true if the specified scev is negated, but not a constant.
name|bool
name|isNonConstantNegative
argument_list|()
specifier|const
block|;
comment|/// Print out the internal representation of this scalar to the specified
comment|/// stream.  This should really only be used for debugging purposes.
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;
comment|/// This method is used for debugging.
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
comment|/// An object of this class is returned by queries that could not be answered.
comment|/// For example, if you ask for the number of iterations of a linked-list
comment|/// traversal loop, you will get one of these.  None of the standard SCEV
comment|/// operations are valid on this class, it is just a marker.
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
comment|/// SCEVPredicate - This class represents an assumption made using SCEV
comment|/// expressions which can be checked at run-time.
name|class
name|SCEVPredicate
operator|:
name|public
name|FoldingSetNode
block|{
name|friend
expr|struct
name|FoldingSetTrait
operator|<
name|SCEVPredicate
operator|>
block|;
comment|/// A reference to an Interned FoldingSetNodeID for this node.  The
comment|/// ScalarEvolution's BumpPtrAllocator holds the data.
name|FoldingSetNodeIDRef
name|FastID
block|;
name|public
operator|:
expr|enum
name|SCEVPredicateKind
block|{
name|P_Union
block|,
name|P_Equal
block|}
block|;
name|protected
operator|:
name|SCEVPredicateKind
name|Kind
block|;
operator|~
name|SCEVPredicate
argument_list|()
operator|=
expr|default
block|;
name|SCEVPredicate
argument_list|(
specifier|const
name|SCEVPredicate
operator|&
argument_list|)
operator|=
expr|default
block|;
name|SCEVPredicate
operator|&
name|operator
operator|=
operator|(
specifier|const
name|SCEVPredicate
operator|&
operator|)
operator|=
expr|default
block|;
name|public
operator|:
name|SCEVPredicate
argument_list|(
argument|const FoldingSetNodeIDRef ID
argument_list|,
argument|SCEVPredicateKind Kind
argument_list|)
block|;
name|SCEVPredicateKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
comment|/// \brief Returns the estimated complexity of this predicate.
comment|/// This is roughly measured in the number of run-time checks required.
name|virtual
name|unsigned
name|getComplexity
argument_list|()
specifier|const
block|{
return|return
literal|1
return|;
block|}
comment|/// \brief Returns true if the predicate is always true. This means that no
comment|/// assumptions were made and nothing needs to be checked at run-time.
name|virtual
name|bool
name|isAlwaysTrue
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// \brief Returns true if this predicate implies \p N.
name|virtual
name|bool
name|implies
argument_list|(
argument|const SCEVPredicate *N
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// \brief Prints a textual representation of this predicate with an
comment|/// indentation of \p Depth.
name|virtual
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|unsigned Depth =
literal|0
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// \brief Returns the SCEV to which this predicate applies, or nullptr
comment|/// if this is a SCEVUnionPredicate.
name|virtual
specifier|const
name|SCEV
operator|*
name|getExpr
argument_list|()
specifier|const
operator|=
literal|0
block|;   }
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
name|SCEVPredicate
operator|&
name|P
operator|)
block|{
name|P
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
comment|// Specialize FoldingSetTrait for SCEVPredicate to avoid needing to compute
comment|// temporary FoldingSetNodeID values.
name|template
operator|<
operator|>
expr|struct
name|FoldingSetTrait
operator|<
name|SCEVPredicate
operator|>
operator|:
name|DefaultFoldingSetTrait
operator|<
name|SCEVPredicate
operator|>
block|{
specifier|static
name|void
name|Profile
argument_list|(
argument|const SCEVPredicate&X
argument_list|,
argument|FoldingSetNodeID&ID
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
argument|const SCEVPredicate&X
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
argument|const SCEVPredicate&X
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
comment|/// SCEVEqualPredicate - This class represents an assumption that two SCEV
comment|/// expressions are equal, and this can be checked at run-time. We assume
comment|/// that the left hand side is a SCEVUnknown and the right hand side a
comment|/// constant.
name|class
name|SCEVEqualPredicate
name|final
operator|:
name|public
name|SCEVPredicate
block|{
comment|/// We assume that LHS == RHS, where LHS is a SCEVUnknown and RHS a
comment|/// constant.
specifier|const
name|SCEVUnknown
operator|*
name|LHS
block|;
specifier|const
name|SCEVConstant
operator|*
name|RHS
block|;
name|public
operator|:
name|SCEVEqualPredicate
argument_list|(
argument|const FoldingSetNodeIDRef ID
argument_list|,
argument|const SCEVUnknown *LHS
argument_list|,
argument|const SCEVConstant *RHS
argument_list|)
block|;
comment|/// Implementation of the SCEVPredicate interface
name|bool
name|implies
argument_list|(
argument|const SCEVPredicate *N
argument_list|)
specifier|const
name|override
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|unsigned Depth =
literal|0
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isAlwaysTrue
argument_list|()
specifier|const
name|override
block|;
specifier|const
name|SCEV
operator|*
name|getExpr
argument_list|()
specifier|const
name|override
block|;
comment|/// \brief Returns the left hand side of the equality.
specifier|const
name|SCEVUnknown
operator|*
name|getLHS
argument_list|()
specifier|const
block|{
return|return
name|LHS
return|;
block|}
comment|/// \brief Returns the right hand side of the equality.
specifier|const
name|SCEVConstant
operator|*
name|getRHS
argument_list|()
specifier|const
block|{
return|return
name|RHS
return|;
block|}
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const SCEVPredicate *P
argument_list|)
block|{
return|return
name|P
operator|->
name|getKind
argument_list|()
operator|==
name|P_Equal
return|;
block|}
expr|}
block|;
comment|/// SCEVUnionPredicate - This class represents a composition of other
comment|/// SCEV predicates, and is the class that most clients will interact with.
comment|/// This is equivalent to a logical "AND" of all the predicates in the union.
name|class
name|SCEVUnionPredicate
name|final
operator|:
name|public
name|SCEVPredicate
block|{
name|private
operator|:
typedef|typedef
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
operator|,
name|SmallVector
operator|<
specifier|const
name|SCEVPredicate
operator|*
operator|,
literal|4
operator|>>
name|PredicateMap
expr_stmt|;
comment|/// Vector with references to all predicates in this union.
name|SmallVector
operator|<
specifier|const
name|SCEVPredicate
operator|*
operator|,
literal|16
operator|>
name|Preds
block|;
comment|/// Maps SCEVs to predicates for quick look-ups.
name|PredicateMap
name|SCEVToPreds
block|;
name|public
operator|:
name|SCEVUnionPredicate
argument_list|()
block|;
specifier|const
name|SmallVectorImpl
operator|<
specifier|const
name|SCEVPredicate
operator|*
operator|>
operator|&
name|getPredicates
argument_list|()
specifier|const
block|{
return|return
name|Preds
return|;
block|}
comment|/// \brief Adds a predicate to this union.
name|void
name|add
argument_list|(
specifier|const
name|SCEVPredicate
operator|*
name|N
argument_list|)
block|;
comment|/// \brief Returns a reference to a vector containing all predicates
comment|/// which apply to \p Expr.
name|ArrayRef
operator|<
specifier|const
name|SCEVPredicate
operator|*
operator|>
name|getPredicatesForExpr
argument_list|(
specifier|const
name|SCEV
operator|*
name|Expr
argument_list|)
block|;
comment|/// Implementation of the SCEVPredicate interface
name|bool
name|isAlwaysTrue
argument_list|()
specifier|const
name|override
block|;
name|bool
name|implies
argument_list|(
argument|const SCEVPredicate *N
argument_list|)
specifier|const
name|override
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|unsigned Depth
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|SCEV
operator|*
name|getExpr
argument_list|()
specifier|const
name|override
block|;
comment|/// \brief We estimate the complexity of a union predicate as the size
comment|/// number of predicates in the union.
name|unsigned
name|getComplexity
argument_list|()
specifier|const
name|override
block|{
return|return
name|Preds
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const SCEVPredicate *P
argument_list|)
block|{
return|return
name|P
operator|->
name|getKind
argument_list|()
operator|==
name|P_Union
return|;
block|}
expr|}
block|;
comment|/// The main scalar evolution driver. Because client code (intentionally)
comment|/// can't do much with the SCEV objects directly, they must ask this class
comment|/// for services.
name|class
name|ScalarEvolution
block|{
name|public
operator|:
comment|/// An enum describing the relationship between a SCEV and a loop.
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
comment|/// An enum describing the relationship between a SCEV and a basic block.
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
comment|/// A CallbackVH to arrange for ScalarEvolution to be notified whenever a
comment|/// Value is deleted.
name|class
name|SCEVCallbackVH
name|final
operator|:
name|public
name|CallbackVH
block|{
name|ScalarEvolution
operator|*
name|SE
block|;
name|void
name|deleted
argument_list|()
name|override
block|;
name|void
name|allUsesReplacedWith
argument_list|(
argument|Value *New
argument_list|)
name|override
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
name|nullptr
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
comment|/// The function we are analyzing.
comment|///
name|Function
operator|&
name|F
block|;
comment|/// The target library information for the target we are targeting.
comment|///
name|TargetLibraryInfo
operator|&
name|TLI
block|;
comment|/// The tracker for @llvm.assume intrinsics in this function.
name|AssumptionCache
operator|&
name|AC
block|;
comment|/// The dominator tree.
comment|///
name|DominatorTree
operator|&
name|DT
block|;
comment|/// The loop information for the function we are currently analyzing.
comment|///
name|LoopInfo
operator|&
name|LI
block|;
comment|/// This SCEV is used to represent unknown trip counts and things.
name|std
operator|::
name|unique_ptr
operator|<
name|SCEVCouldNotCompute
operator|>
name|CouldNotCompute
block|;
comment|/// The typedef for ValueExprMap.
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
comment|/// This is a cache of the values we have analyzed so far.
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
comment|/// Set to true by isLoopBackedgeGuardedByCond when we're walking the set of
comment|/// conditions dominating the backedge of a loop.
name|bool
name|WalkingBEDominatingConds
block|;
comment|/// Set to true by isKnownPredicateViaSplitting when we're trying to prove a
comment|/// predicate by splitting it into a set of independent predicates.
name|bool
name|ProvingSplitPredicate
block|;
comment|/// Information about the number of loop iterations for which a loop exit's
comment|/// branch condition evaluates to the not-taken path.  This is a temporary
comment|/// pair of exact and max expressions that are eventually summarized in
comment|/// ExitNotTakenInfo and BackedgeTakenInfo.
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
block|{
name|assert
argument_list|(
operator|(
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
operator|)
operator|&&
literal|"Exact is not allowed to be less precise than Max"
argument_list|)
block|;       }
comment|/// Test whether this ExitLimit contains any computed information, or
comment|/// whether it's all SCEVCouldNotCompute values.
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
comment|/// Information about the number of times a particular loop exit may be
comment|/// reached before exiting the loop.
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
name|nullptr
argument_list|)
block|,
name|ExactNotTaken
argument_list|(
argument|nullptr
argument_list|)
block|{}
comment|/// Return true if all loop exits are computable.
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
comment|/// Return a pointer to the next exit's not-taken info.
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
comment|/// Information about the backedge-taken count of a loop. This currently
comment|/// includes an exact count and a maximum count.
comment|///
name|class
name|BackedgeTakenInfo
block|{
comment|/// A list of computable exits and their not-taken counts.  Loops almost
comment|/// never have more than one computable exit.
name|ExitNotTakenInfo
name|ExitNotTaken
block|;
comment|/// An expression indicating the least maximum backedge-taken count of the
comment|/// loop that is known, or a SCEVCouldNotCompute.
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
argument|nullptr
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
comment|/// Test whether this BackedgeTakenInfo contains any computed information,
comment|/// or whether it's all SCEVCouldNotCompute values.
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
comment|/// Return an expression indicating the exact backedge-taken count of the
comment|/// loop if it is known, or SCEVCouldNotCompute otherwise. This is the
comment|/// number of times the loop header can be guaranteed to execute, minus
comment|/// one.
specifier|const
name|SCEV
operator|*
name|getExact
argument_list|(
argument|ScalarEvolution *SE
argument_list|)
specifier|const
block|;
comment|/// Return the number of times this loop exit may fall through to the back
comment|/// edge, or SCEVCouldNotCompute. The loop is guaranteed not to exit via
comment|/// this block before this number of iterations, but may exit via another
comment|/// block.
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
comment|/// Get the max backedge taken count for the loop.
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
comment|/// Invalidate this result and free associated memory.
name|void
name|clear
argument_list|()
block|;     }
block|;
comment|/// Cache the backedge-taken count of the loops for this function as they
comment|/// are computed.
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
comment|/// This map contains entries for all of the PHI instructions that we
comment|/// attempt to compute constant evolutions for.  This allows us to avoid
comment|/// potentially expensive recomputation of these properties.  An instruction
comment|/// maps to null if we are unable to compute its exit value.
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
comment|/// This map contains entries for all the expressions that we attempt to
comment|/// compute getSCEVAtScope information for, which can be expensive in
comment|/// extreme cases.
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
comment|/// Memoized computeLoopDisposition results.
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
block|,
name|SmallVector
operator|<
name|PointerIntPair
operator|<
specifier|const
name|Loop
operator|*
block|,
literal|2
block|,
name|LoopDisposition
operator|>
block|,
literal|2
operator|>>
name|LoopDispositions
block|;
comment|/// Compute a LoopDisposition value.
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
comment|/// Memoized computeBlockDisposition results.
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
block|,
name|SmallVector
operator|<
name|PointerIntPair
operator|<
specifier|const
name|BasicBlock
operator|*
block|,
literal|2
block|,
name|BlockDisposition
operator|>
block|,
literal|2
operator|>>
name|BlockDispositions
block|;
comment|/// Compute a BlockDisposition value.
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
comment|/// Memoized results from getRange
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
comment|/// Memoized results from getRange
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
comment|/// Used to parameterize getRange
block|enum
name|RangeSignHint
block|{
name|HINT_RANGE_UNSIGNED
block|,
name|HINT_RANGE_SIGNED
block|}
block|;
comment|/// Set the memoized range for the given SCEV.
specifier|const
name|ConstantRange
operator|&
name|setRange
argument_list|(
argument|const SCEV *S
argument_list|,
argument|RangeSignHint Hint
argument_list|,
argument|const ConstantRange&CR
argument_list|)
block|{
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
block|,
name|ConstantRange
operator|>
operator|&
name|Cache
operator|=
name|Hint
operator|==
name|HINT_RANGE_UNSIGNED
operator|?
name|UnsignedRanges
operator|:
name|SignedRanges
block|;
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
name|Cache
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
comment|/// Determine the range for a particular SCEV.
name|ConstantRange
name|getRange
argument_list|(
argument|const SCEV *S
argument_list|,
argument|RangeSignHint Hint
argument_list|)
block|;
comment|/// We know that there is no SCEV for the specified value.  Analyze the
comment|/// expression.
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
comment|/// Provide the special handling we need to analyze PHI SCEVs.
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
comment|/// Helper function called from createNodeForPHI.
specifier|const
name|SCEV
operator|*
name|createAddRecFromPHI
argument_list|(
name|PHINode
operator|*
name|PN
argument_list|)
block|;
comment|/// Helper function called from createNodeForPHI.
specifier|const
name|SCEV
operator|*
name|createNodeFromSelectLikePHI
argument_list|(
name|PHINode
operator|*
name|PN
argument_list|)
block|;
comment|/// Provide special handling for a select-like instruction (currently this
comment|/// is either a select instruction or a phi node).  \p I is the instruction
comment|/// being processed, and it is assumed equivalent to "Cond ? TrueVal :
comment|/// FalseVal".
specifier|const
name|SCEV
operator|*
name|createNodeForSelectOrPHI
argument_list|(
name|Instruction
operator|*
name|I
argument_list|,
name|Value
operator|*
name|Cond
argument_list|,
name|Value
operator|*
name|TrueVal
argument_list|,
name|Value
operator|*
name|FalseVal
argument_list|)
block|;
comment|/// Provide the special handling we need to analyze GEP SCEVs.
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
comment|/// Implementation code for getSCEVAtScope; called at most once for each
comment|/// SCEV+Loop pair.
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
comment|/// This looks up computed SCEV values for all instructions that depend on
comment|/// the given instruction and removes them from the ValueExprMap map if they
comment|/// reference SymName. This is used during PHI resolution.
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
comment|/// Return the BackedgeTakenInfo for the given loop, lazily computing new
comment|/// values if the loop hasn't been analyzed yet.
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
comment|/// Compute the number of times the specified loop will iterate.
name|BackedgeTakenInfo
name|computeBackedgeTakenCount
argument_list|(
specifier|const
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|/// Compute the number of times the backedge of the specified loop will
comment|/// execute if it exits via the specified block.
name|ExitLimit
name|computeExitLimit
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
comment|/// Compute the number of times the backedge of the specified loop will
comment|/// execute if its exit condition were a conditional branch of ExitCond,
comment|/// TBB, and FBB.
name|ExitLimit
name|computeExitLimitFromCond
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
comment|/// Compute the number of times the backedge of the specified loop will
comment|/// execute if its exit condition were a conditional branch of the ICmpInst
comment|/// ExitCond, TBB, and FBB.
name|ExitLimit
name|computeExitLimitFromICmp
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
comment|/// Compute the number of times the backedge of the specified loop will
comment|/// execute if its exit condition were a switch with a single exiting case
comment|/// to ExitingBB.
name|ExitLimit
name|computeExitLimitFromSingleExitSwitch
argument_list|(
argument|const Loop *L
argument_list|,
argument|SwitchInst *Switch
argument_list|,
argument|BasicBlock *ExitingBB
argument_list|,
argument|bool IsSubExpr
argument_list|)
block|;
comment|/// Given an exit condition of 'icmp op load X, cst', try to see if we can
comment|/// compute the backedge-taken count.
name|ExitLimit
name|computeLoadConstantCompareExitLimit
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
comment|/// Compute the exit limit of a loop that is controlled by a
comment|/// "(IV>> 1) != 0" type comparison.  We cannot compute the exact trip
comment|/// count in these cases (since SCEV has no way of expressing them), but we
comment|/// can still sometimes compute an upper bound.
comment|///
comment|/// Return an ExitLimit for a loop whose backedge is guarded by `LHS Pred
comment|/// RHS`.
name|ExitLimit
name|computeShiftCompareExitLimit
argument_list|(
argument|Value *LHS
argument_list|,
argument|Value *RHS
argument_list|,
argument|const Loop *L
argument_list|,
argument|ICmpInst::Predicate Pred
argument_list|)
block|;
comment|/// If the loop is known to execute a constant number of times (the
comment|/// condition evolves only from constants), try to evaluate a few iterations
comment|/// of the loop until we get the exit condition gets a value of ExitWhen
comment|/// (true or false).  If we cannot evaluate the exit count of the loop,
comment|/// return CouldNotCompute.
specifier|const
name|SCEV
operator|*
name|computeExitCountExhaustively
argument_list|(
argument|const Loop *L
argument_list|,
argument|Value *Cond
argument_list|,
argument|bool ExitWhen
argument_list|)
block|;
comment|/// Return the number of times an exit condition comparing the specified
comment|/// value to zero will execute.  If not computable, return CouldNotCompute.
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
comment|/// Return the number of times an exit condition checking the specified
comment|/// value for nonzero will execute.  If not computable, return
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
comment|/// Return the number of times an exit condition containing the specified
comment|/// less-than comparison will execute.  If not computable, return
comment|/// CouldNotCompute. isSigned specifies whether the less-than is signed.
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
comment|/// Return a predecessor of BB (which may not be an immediate predecessor)
comment|/// which has exactly one successor from which BB is reachable, or null if
comment|/// no such block is found.
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
comment|/// Test whether the condition described by Pred, LHS, and RHS is true
comment|/// whenever the given FoundCondValue value evaluates to true.
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
comment|/// Test whether the condition described by Pred, LHS, and RHS is true
comment|/// whenever the condition described by FoundPred, FoundLHS, FoundRHS is
comment|/// true.
name|bool
name|isImpliedCond
argument_list|(
argument|ICmpInst::Predicate Pred
argument_list|,
argument|const SCEV *LHS
argument_list|,
argument|const SCEV *RHS
argument_list|,
argument|ICmpInst::Predicate FoundPred
argument_list|,
argument|const SCEV *FoundLHS
argument_list|,
argument|const SCEV *FoundRHS
argument_list|)
block|;
comment|/// Test whether the condition described by Pred, LHS, and RHS is true
comment|/// whenever the condition described by Pred, FoundLHS, and FoundRHS is
comment|/// true.
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
comment|/// Test whether the condition described by Pred, LHS, and RHS is true
comment|/// whenever the condition described by Pred, FoundLHS, and FoundRHS is
comment|/// true.
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
comment|/// Test whether the condition described by Pred, LHS, and RHS is true
comment|/// whenever the condition described by Pred, FoundLHS, and FoundRHS is
comment|/// true.  Utility function used by isImpliedCondOperands.
name|bool
name|isImpliedCondOperandsViaRanges
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
comment|/// Test whether the condition described by Pred, LHS, and RHS is true
comment|/// whenever the condition described by Pred, FoundLHS, and FoundRHS is
comment|/// true.
comment|///
comment|/// This routine tries to rule out certain kinds of integer overflow, and
comment|/// then tries to reason about arithmetic properties of the predicates.
name|bool
name|isImpliedCondOperandsViaNoOverflow
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
comment|/// If we know that the specified Phi is in the header of its containing
comment|/// loop, we know the loop executes a constant number of times, and the PHI
comment|/// node is just a recurrence involving constants, fold it.
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
comment|/// Test if the given expression is known to satisfy the condition described
comment|/// by Pred and the known constant ranges of LHS and RHS.
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
comment|/// Try to prove the condition described by "LHS Pred RHS" by ruling out
comment|/// integer overflow.
comment|///
comment|/// For instance, this will return true for "A s< (A + C)<nsw>" if C is
comment|/// positive.
name|bool
name|isKnownPredicateViaNoOverflow
argument_list|(
argument|ICmpInst::Predicate Pred
argument_list|,
argument|const SCEV *LHS
argument_list|,
argument|const SCEV *RHS
argument_list|)
block|;
comment|/// Try to split Pred LHS RHS into logical conjunctions (and's) and try to
comment|/// prove them individually.
name|bool
name|isKnownPredicateViaSplitting
argument_list|(
argument|ICmpInst::Predicate Pred
argument_list|,
argument|const SCEV *LHS
argument_list|,
argument|const SCEV *RHS
argument_list|)
block|;
comment|/// Try to match the Expr as "(L + R)<Flags>".
name|bool
name|splitBinaryAdd
argument_list|(
specifier|const
name|SCEV
operator|*
name|Expr
argument_list|,
specifier|const
name|SCEV
operator|*
operator|&
name|L
argument_list|,
specifier|const
name|SCEV
operator|*
operator|&
name|R
argument_list|,
name|SCEV
operator|::
name|NoWrapFlags
operator|&
name|Flags
argument_list|)
block|;
comment|/// Return true if More == (Less + C), where C is a constant.  This is
comment|/// intended to be used as a cheaper substitute for full SCEV subtraction.
name|bool
name|computeConstantDifference
argument_list|(
specifier|const
name|SCEV
operator|*
name|Less
argument_list|,
specifier|const
name|SCEV
operator|*
name|More
argument_list|,
name|APInt
operator|&
name|C
argument_list|)
block|;
comment|/// Drop memoized information computed for S.
name|void
name|forgetMemoizedResults
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|)
block|;
comment|/// Return an existing SCEV for V if there is one, otherwise return nullptr.
specifier|const
name|SCEV
operator|*
name|getExistingSCEV
argument_list|(
name|Value
operator|*
name|V
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
comment|/// Return true if `ExtendOpTy`({`Start`,+,`Step`}) can be proved to be
comment|/// equal to {`ExtendOpTy`(`Start`),+,`ExtendOpTy`(`Step`)}.  This is
comment|/// equivalent to proving no signed (resp. unsigned) wrap in
comment|/// {`Start`,+,`Step`} if `ExtendOpTy` is `SCEVSignExtendExpr`
comment|/// (resp. `SCEVZeroExtendExpr`).
comment|///
name|template
operator|<
name|typename
name|ExtendOpTy
operator|>
name|bool
name|proveNoWrapByVaryingStart
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
argument_list|)
block|;
name|bool
name|isMonotonicPredicateImpl
argument_list|(
argument|const SCEVAddRecExpr *LHS
argument_list|,
argument|ICmpInst::Predicate Pred
argument_list|,
argument|bool&Increasing
argument_list|)
block|;
comment|/// Return true if, for all loop invariant X, the predicate "LHS `Pred` X"
comment|/// is monotonically increasing or decreasing.  In the former case set
comment|/// `Increasing` to true and in the latter case set `Increasing` to false.
comment|///
comment|/// A predicate is said to be monotonically increasing if may go from being
comment|/// false to being true as the loop iterates, but never the other way
comment|/// around.  A predicate is said to be monotonically decreasing if may go
comment|/// from being true to being false as the loop iterates, but never the other
comment|/// way around.
name|bool
name|isMonotonicPredicate
argument_list|(
argument|const SCEVAddRecExpr *LHS
argument_list|,
argument|ICmpInst::Predicate Pred
argument_list|,
argument|bool&Increasing
argument_list|)
block|;
comment|// Return SCEV no-wrap flags that can be proven based on reasoning
comment|// about how poison produced from no-wrap flags on this value
comment|// (e.g. a nuw add) would trigger undefined behavior on overflow.
name|SCEV
operator|::
name|NoWrapFlags
name|getNoWrapFlagsFromUB
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
block|;
name|public
operator|:
name|ScalarEvolution
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|TargetLibraryInfo
operator|&
name|TLI
argument_list|,
name|AssumptionCache
operator|&
name|AC
argument_list|,
name|DominatorTree
operator|&
name|DT
argument_list|,
name|LoopInfo
operator|&
name|LI
argument_list|)
block|;
operator|~
name|ScalarEvolution
argument_list|()
block|;
name|ScalarEvolution
argument_list|(
name|ScalarEvolution
operator|&&
name|Arg
argument_list|)
block|;
name|LLVMContext
operator|&
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|F
operator|.
name|getContext
argument_list|()
return|;
block|}
comment|/// Test if values of the given type are analyzable within the SCEV
comment|/// framework. This primarily includes integer types, and it can optionally
comment|/// include pointer types if the ScalarEvolution class has access to
comment|/// target-specific information.
name|bool
name|isSCEVable
argument_list|(
argument|Type *Ty
argument_list|)
specifier|const
block|;
comment|/// Return the size in bits of the specified type, for which isSCEVable must
comment|/// return true.
name|uint64_t
name|getTypeSizeInBits
argument_list|(
argument|Type *Ty
argument_list|)
specifier|const
block|;
comment|/// Return a type with the same bitwidth as the given type and which
comment|/// represents how SCEV will treat the given type, for which isSCEVable must
comment|/// return true. For pointer types, this is the pointer-sized integer type.
name|Type
operator|*
name|getEffectiveSCEVType
argument_list|(
argument|Type *Ty
argument_list|)
specifier|const
block|;
comment|/// Return a SCEV expression for the full generality of the specified
comment|/// expression.
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
operator|=
block|{
name|LHS
block|,
name|RHS
block|}
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
operator|=
block|{
name|Op0
block|,
name|Op1
block|,
name|Op2
block|}
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
operator|=
block|{
name|LHS
block|,
name|RHS
block|}
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
operator|=
block|{
name|Op0
block|,
name|Op1
block|,
name|Op2
block|}
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
name|getUDivExactExpr
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
comment|/// \brief Returns an expression for a GEP
comment|///
comment|/// \p PointeeType The type used as the basis for the pointer arithmetics
comment|/// \p BaseExpr The expression for the pointer operand.
comment|/// \p IndexExprs The expressions for the indices.
comment|/// \p InBounds Whether the GEP is in bounds.
specifier|const
name|SCEV
operator|*
name|getGEPExpr
argument_list|(
argument|Type *PointeeType
argument_list|,
argument|const SCEV *BaseExpr
argument_list|,
argument|const SmallVectorImpl<const SCEV *>&IndexExprs
argument_list|,
argument|bool InBounds = false
argument_list|)
block|;
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
comment|/// \brief Return a SCEV for the constant 0 of a specific type.
specifier|const
name|SCEV
operator|*
name|getZero
argument_list|(
argument|Type *Ty
argument_list|)
block|{
return|return
name|getConstant
argument_list|(
name|Ty
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|/// \brief Return a SCEV for the constant 1 of a specific type.
specifier|const
name|SCEV
operator|*
name|getOne
argument_list|(
argument|Type *Ty
argument_list|)
block|{
return|return
name|getConstant
argument_list|(
name|Ty
argument_list|,
literal|1
argument_list|)
return|;
block|}
comment|/// Return an expression for sizeof AllocTy that is type IntTy
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
comment|/// Return an expression for offsetof on the given field with type IntTy
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
comment|/// Return the SCEV object corresponding to -V.
comment|///
specifier|const
name|SCEV
operator|*
name|getNegativeSCEV
argument_list|(
argument|const SCEV *V
argument_list|,
argument|SCEV::NoWrapFlags Flags = SCEV::FlagAnyWrap
argument_list|)
block|;
comment|/// Return the SCEV object corresponding to ~V.
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
comment|/// Return LHS-RHS.  Minus is represented in SCEV as A+B*-1.
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
comment|/// Return a SCEV corresponding to a conversion of the input value to the
comment|/// specified type.  If the type must be extended, it is zero extended.
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
comment|/// Return a SCEV corresponding to a conversion of the input value to the
comment|/// specified type.  If the type must be extended, it is sign extended.
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
comment|/// Return a SCEV corresponding to a conversion of the input value to the
comment|/// specified type.  If the type must be extended, it is zero extended.  The
comment|/// conversion must not be narrowing.
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
comment|/// Return a SCEV corresponding to a conversion of the input value to the
comment|/// specified type.  If the type must be extended, it is sign extended.  The
comment|/// conversion must not be narrowing.
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
comment|/// Return a SCEV corresponding to a conversion of the input value to the
comment|/// specified type. If the type must be extended, it is extended with
comment|/// unspecified bits. The conversion must not be narrowing.
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
comment|/// Return a SCEV corresponding to a conversion of the input value to the
comment|/// specified type.  The conversion must not be widening.
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
comment|/// Promote the operands to the wider of the types using zero-extension, and
comment|/// then perform a umax operation with them.
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
comment|/// Promote the operands to the wider of the types using zero-extension, and
comment|/// then perform a umin operation with them.
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
comment|/// Transitively follow the chain of pointer-type operands until reaching a
comment|/// SCEV that does not have a single pointer operand. This returns a
comment|/// SCEVUnknown pointer for well-formed pointer-type expressions, but corner
comment|/// cases do exist.
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
comment|/// Return a SCEV expression for the specified value at the specified scope
comment|/// in the program.  The L value specifies a loop nest to evaluate the
comment|/// expression at, where null is the top-level or a specified loop is
comment|/// immediately inside of the loop.
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
comment|/// This is a convenience function which does getSCEVAtScope(getSCEV(V), L).
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
comment|/// Test whether entry to the loop is protected by a conditional between LHS
comment|/// and RHS.  This is used to help avoid max expressions in loop trip
comment|/// counts, and to eliminate casts.
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
comment|/// Test whether the backedge of the loop is protected by a conditional
comment|/// between LHS and RHS.  This is used to to eliminate casts.
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
comment|/// \brief Returns the maximum trip count of the loop if it is a single-exit
comment|/// loop and we can compute a small maximum for that loop.
comment|///
comment|/// Implemented in terms of the \c getSmallConstantTripCount overload with
comment|/// the single exiting block passed to it. See that routine for details.
name|unsigned
name|getSmallConstantTripCount
argument_list|(
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|/// Returns the maximum trip count of this loop as a normal unsigned
comment|/// value. Returns 0 if the trip count is unknown or not constant. This
comment|/// "trip count" assumes that control exits via ExitingBlock. More
comment|/// precisely, it is the number of times that control may reach ExitingBlock
comment|/// before taking the branch. For loops with multiple exits, it may not be
comment|/// the number times that the loop header executes if the loop exits
comment|/// prematurely via another branch.
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
comment|/// \brief Returns the largest constant divisor of the trip count of the
comment|/// loop if it is a single-exit loop and we can compute a small maximum for
comment|/// that loop.
comment|///
comment|/// Implemented in terms of the \c getSmallConstantTripMultiple overload with
comment|/// the single exiting block passed to it. See that routine for details.
name|unsigned
name|getSmallConstantTripMultiple
argument_list|(
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|/// Returns the largest constant divisor of the trip count of this loop as a
comment|/// normal unsigned value, if possible. This means that the actual trip
comment|/// count is always a multiple of the returned value (don't forget the trip
comment|/// count could very well be zero as well!). As explained in the comments
comment|/// for getSmallConstantTripCount, this assumes that control exits the loop
comment|/// via ExitingBlock.
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
comment|/// Get the expression for the number of loop iterations for which this loop
comment|/// is guaranteed not to exit via ExitingBlock. Otherwise return
comment|/// SCEVCouldNotCompute.
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
comment|/// If the specified loop has a predictable backedge-taken count, return it,
comment|/// otherwise return a SCEVCouldNotCompute object. The backedge-taken count
comment|/// is the number of times the loop header will be branched to from within
comment|/// the loop. This is one less than the trip count of the loop, since it
comment|/// doesn't count the first iteration, when the header is branched to from
comment|/// outside the loop.
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
comment|/// Similar to getBackedgeTakenCount, except return the least SCEV value
comment|/// that is known never to be less than the actual backedge taken count.
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
comment|/// Return true if the specified loop has an analyzable loop-invariant
comment|/// backedge-taken count.
name|bool
name|hasLoopInvariantBackedgeTakenCount
argument_list|(
specifier|const
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|/// This method should be called by the client when it has changed a loop in
comment|/// a way that may effect ScalarEvolution's ability to compute a trip count,
comment|/// or if the loop is deleted.  This call is potentially expensive for large
comment|/// loop bodies.
name|void
name|forgetLoop
argument_list|(
specifier|const
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|/// This method should be called by the client when it has changed a value
comment|/// in a way that may effect its value, or which may disconnect it from a
comment|/// def-use chain linking it to a loop.
name|void
name|forgetValue
argument_list|(
name|Value
operator|*
name|V
argument_list|)
block|;
comment|/// \brief Called when the client has changed the disposition of values in
comment|/// this loop.
comment|///
comment|/// We don't have a way to invalidate per-loop dispositions. Clear and
comment|/// recompute is simpler.
name|void
name|forgetLoopDispositions
argument_list|(
argument|const Loop *L
argument_list|)
block|{
name|LoopDispositions
operator|.
name|clear
argument_list|()
block|; }
comment|/// Determine the minimum number of zero bits that S is guaranteed to end in
comment|/// (at every loop iteration).  It is, at the same time, the minimum number
comment|/// of times S is divisible by 2.  For example, given {4,+,8} it returns 2.
comment|/// If S is guaranteed to be 0, it returns the bitwidth of S.
name|uint32_t
name|GetMinTrailingZeros
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|)
block|;
comment|/// Determine the unsigned range for a particular SCEV.
comment|///
name|ConstantRange
name|getUnsignedRange
argument_list|(
argument|const SCEV *S
argument_list|)
block|{
return|return
name|getRange
argument_list|(
name|S
argument_list|,
name|HINT_RANGE_UNSIGNED
argument_list|)
return|;
block|}
comment|/// Determine the signed range for a particular SCEV.
comment|///
name|ConstantRange
name|getSignedRange
argument_list|(
argument|const SCEV *S
argument_list|)
block|{
return|return
name|getRange
argument_list|(
name|S
argument_list|,
name|HINT_RANGE_SIGNED
argument_list|)
return|;
block|}
comment|/// Test if the given expression is known to be negative.
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
comment|/// Test if the given expression is known to be positive.
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
comment|/// Test if the given expression is known to be non-negative.
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
comment|/// Test if the given expression is known to be non-positive.
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
comment|/// Test if the given expression is known to be non-zero.
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
comment|/// Test if the given expression is known to satisfy the condition described
comment|/// by Pred, LHS, and RHS.
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
comment|/// Return true if the result of the predicate LHS `Pred` RHS is loop
comment|/// invariant with respect to L.  Set InvariantPred, InvariantLHS and
comment|/// InvariantLHS so that InvariantLHS `InvariantPred` InvariantRHS is the
comment|/// loop invariant form of LHS `Pred` RHS.
name|bool
name|isLoopInvariantPredicate
argument_list|(
argument|ICmpInst::Predicate Pred
argument_list|,
argument|const SCEV *LHS
argument_list|,
argument|const SCEV *RHS
argument_list|,
argument|const Loop *L
argument_list|,
argument|ICmpInst::Predicate&InvariantPred
argument_list|,
argument|const SCEV *&InvariantLHS
argument_list|,
argument|const SCEV *&InvariantRHS
argument_list|)
block|;
comment|/// Simplify LHS and RHS in a comparison with predicate Pred. Return true
comment|/// iff any changes were made. If the operands are provably equal or
comment|/// unequal, LHS and RHS are set to the same value and Pred is set to either
comment|/// ICMP_EQ or ICMP_NE.
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
comment|/// Return the "disposition" of the given SCEV with respect to the given
comment|/// loop.
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
comment|/// Return true if the value of the given SCEV is unchanging in the
comment|/// specified loop.
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
comment|/// Return true if the given SCEV changes value in a known way in the
comment|/// specified loop.  This property being true implies that the value is
comment|/// variant in the loop AND that we can emit an expression to compute the
comment|/// value of the expression at any particular loop iteration.
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
comment|/// Return the "disposition" of the given SCEV with respect to the given
comment|/// block.
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
comment|/// Return true if elements that makes up the given SCEV dominate the
comment|/// specified basic block.
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
comment|/// Return true if elements that makes up the given SCEV properly dominate
comment|/// the specified basic block.
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
comment|/// Test whether the given SCEV has Op as a direct or indirect operand.
name|bool
name|hasOperand
argument_list|(
argument|const SCEV *S
argument_list|,
argument|const SCEV *Op
argument_list|)
specifier|const
block|;
comment|/// Return the size of an element read or written by Inst.
specifier|const
name|SCEV
operator|*
name|getElementSize
argument_list|(
name|Instruction
operator|*
name|Inst
argument_list|)
block|;
comment|/// Compute the array dimensions Sizes from the set of Terms extracted from
comment|/// the memory access function of this SCEVAddRecExpr.
name|void
name|findArrayDimensions
argument_list|(
argument|SmallVectorImpl<const SCEV *>&Terms
argument_list|,
argument|SmallVectorImpl<const SCEV *>&Sizes
argument_list|,
argument|const SCEV *ElementSize
argument_list|)
specifier|const
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;
name|void
name|verify
argument_list|()
specifier|const
block|;
comment|/// Collect parametric terms occurring in step expressions.
name|void
name|collectParametricTerms
argument_list|(
specifier|const
name|SCEV
operator|*
name|Expr
argument_list|,
name|SmallVectorImpl
operator|<
specifier|const
name|SCEV
operator|*
operator|>
operator|&
name|Terms
argument_list|)
block|;
comment|/// Return in Subscripts the access functions for each dimension in Sizes.
name|void
name|computeAccessFunctions
argument_list|(
specifier|const
name|SCEV
operator|*
name|Expr
argument_list|,
name|SmallVectorImpl
operator|<
specifier|const
name|SCEV
operator|*
operator|>
operator|&
name|Subscripts
argument_list|,
name|SmallVectorImpl
operator|<
specifier|const
name|SCEV
operator|*
operator|>
operator|&
name|Sizes
argument_list|)
block|;
comment|/// Split this SCEVAddRecExpr into two vectors of SCEVs representing the
comment|/// subscripts and sizes of an array access.
comment|///
comment|/// The delinearization is a 3 step process: the first two steps compute the
comment|/// sizes of each subscript and the third step computes the access functions
comment|/// for the delinearized array:
comment|///
comment|/// 1. Find the terms in the step functions
comment|/// 2. Compute the array size
comment|/// 3. Compute the access function: divide the SCEV by the array size
comment|///    starting with the innermost dimensions found in step 2. The Quotient
comment|///    is the SCEV to be divided in the next step of the recursion. The
comment|///    Remainder is the subscript of the innermost dimension. Loop over all
comment|///    array dimensions computed in step 2.
comment|///
comment|/// To compute a uniform array size for several memory accesses to the same
comment|/// object, one can collect in step 1 all the step terms for all the memory
comment|/// accesses, and compute in step 2 a unique array shape. This guarantees
comment|/// that the array shape will be the same across all memory accesses.
comment|///
comment|/// FIXME: We could derive the result of steps 1 and 2 from a description of
comment|/// the array shape given in metadata.
comment|///
comment|/// Example:
comment|///
comment|/// A[][n][m]
comment|///
comment|/// for i
comment|///   for j
comment|///     for k
comment|///       A[j+k][2i][5i] =
comment|///
comment|/// The initial SCEV:
comment|///
comment|/// A[{{{0,+,2*m+5}_i, +, n*m}_j, +, n*m}_k]
comment|///
comment|/// 1. Find the different terms in the step functions:
comment|/// -> [2*m, 5, n*m, n*m]
comment|///
comment|/// 2. Compute the array size: sort and unique them
comment|/// -> [n*m, 2*m, 5]
comment|/// find the GCD of all the terms = 1
comment|/// divide by the GCD and erase constant terms
comment|/// -> [n*m, 2*m]
comment|/// GCD = m
comment|/// divide by GCD -> [n, 2]
comment|/// remove constant terms
comment|/// -> [n]
comment|/// size of the array is A[unknown][n][m]
comment|///
comment|/// 3. Compute the access function
comment|/// a. Divide {{{0,+,2*m+5}_i, +, n*m}_j, +, n*m}_k by the innermost size m
comment|/// Quotient: {{{0,+,2}_i, +, n}_j, +, n}_k
comment|/// Remainder: {{{0,+,5}_i, +, 0}_j, +, 0}_k
comment|/// The remainder is the subscript of the innermost array dimension: [5i].
comment|///
comment|/// b. Divide Quotient: {{{0,+,2}_i, +, n}_j, +, n}_k by next outer size n
comment|/// Quotient: {{{0,+,0}_i, +, 1}_j, +, 1}_k
comment|/// Remainder: {{{0,+,2}_i, +, 0}_j, +, 0}_k
comment|/// The Remainder is the subscript of the next array dimension: [2i].
comment|///
comment|/// The subscript of the outermost dimension is the Quotient: [j+k].
comment|///
comment|/// Overall, we have: A[][n][m], and the access function: A[j+k][2i][5i].
name|void
name|delinearize
argument_list|(
specifier|const
name|SCEV
operator|*
name|Expr
argument_list|,
name|SmallVectorImpl
operator|<
specifier|const
name|SCEV
operator|*
operator|>
operator|&
name|Subscripts
argument_list|,
name|SmallVectorImpl
operator|<
specifier|const
name|SCEV
operator|*
operator|>
operator|&
name|Sizes
argument_list|,
specifier|const
name|SCEV
operator|*
name|ElementSize
argument_list|)
block|;
comment|/// Return the DataLayout associated with the module this SCEV instance is
comment|/// operating on.
specifier|const
name|DataLayout
operator|&
name|getDataLayout
argument_list|()
specifier|const
block|{
return|return
name|F
operator|.
name|getParent
argument_list|()
operator|->
name|getDataLayout
argument_list|()
return|;
block|}
specifier|const
name|SCEVPredicate
operator|*
name|getEqualPredicate
argument_list|(
specifier|const
name|SCEVUnknown
operator|*
name|LHS
argument_list|,
specifier|const
name|SCEVConstant
operator|*
name|RHS
argument_list|)
block|;
comment|/// Re-writes the SCEV according to the Predicates in \p Preds.
specifier|const
name|SCEV
operator|*
name|rewriteUsingPredicate
argument_list|(
specifier|const
name|SCEV
operator|*
name|Scev
argument_list|,
name|SCEVUnionPredicate
operator|&
name|A
argument_list|)
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
name|FoldingSet
operator|<
name|SCEVPredicate
operator|>
name|UniquePreds
block|;
name|BumpPtrAllocator
name|SCEVAllocator
block|;
comment|/// The head of a linked list of all SCEVUnknown values that have been
comment|/// allocated. This is used by releaseMemory to locate them all and call
comment|/// their destructors.
name|SCEVUnknown
operator|*
name|FirstUnknown
block|;   }
block|;
comment|/// \brief Analysis pass that exposes the \c ScalarEvolution for a function.
name|class
name|ScalarEvolutionAnalysis
block|{
specifier|static
name|char
name|PassID
block|;
name|public
operator|:
typedef|typedef
name|ScalarEvolution
name|Result
typedef|;
comment|/// \brief Opaque, unique identifier for this analysis pass.
specifier|static
name|void
operator|*
name|ID
argument_list|()
block|{
return|return
operator|(
name|void
operator|*
operator|)
operator|&
name|PassID
return|;
block|}
comment|/// \brief Provide a name for the analysis for debugging and logging.
specifier|static
name|StringRef
name|name
argument_list|()
block|{
return|return
literal|"ScalarEvolutionAnalysis"
return|;
block|}
name|ScalarEvolution
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|AnalysisManager
operator|<
name|Function
operator|>
operator|*
name|AM
argument_list|)
block|;   }
block|;
comment|/// \brief Printer pass for the \c ScalarEvolutionAnalysis results.
name|class
name|ScalarEvolutionPrinterPass
block|{
name|raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
name|explicit
name|ScalarEvolutionPrinterPass
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
operator|:
name|OS
argument_list|(
argument|OS
argument_list|)
block|{}
name|PreservedAnalyses
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|AnalysisManager
operator|<
name|Function
operator|>
operator|*
name|AM
argument_list|)
block|;
specifier|static
name|StringRef
name|name
argument_list|()
block|{
return|return
literal|"ScalarEvolutionPrinterPass"
return|;
block|}
expr|}
block|;
name|class
name|ScalarEvolutionWrapperPass
operator|:
name|public
name|FunctionPass
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|ScalarEvolution
operator|>
name|SE
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|ScalarEvolutionWrapperPass
argument_list|()
block|;
name|ScalarEvolution
operator|&
name|getSE
argument_list|()
block|{
return|return
operator|*
name|SE
return|;
block|}
specifier|const
name|ScalarEvolution
operator|&
name|getSE
argument_list|()
specifier|const
block|{
return|return
operator|*
name|SE
return|;
block|}
name|bool
name|runOnFunction
argument_list|(
argument|Function&F
argument_list|)
name|override
block|;
name|void
name|releaseMemory
argument_list|()
name|override
block|;
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const Module * = nullptr
argument_list|)
specifier|const
name|override
block|;
name|void
name|verifyAnalysis
argument_list|()
specifier|const
name|override
block|;   }
block|;
comment|/// An interface layer with SCEV used to manage how we see SCEV expressions
comment|/// for values in the context of existing predicates. We can add new
comment|/// predicates, but we cannot remove them.
comment|///
comment|/// This layer has multiple purposes:
comment|///   - provides a simple interface for SCEV versioning.
comment|///   - guarantees that the order of transformations applied on a SCEV
comment|///     expression for a single Value is consistent across two different
comment|///     getSCEV calls. This means that, for example, once we've obtained
comment|///     an AddRec expression for a certain value through expression
comment|///     rewriting, we will continue to get an AddRec expression for that
comment|///     Value.
comment|///   - lowers the number of expression rewrites.
name|class
name|PredicatedScalarEvolution
block|{
name|public
operator|:
name|PredicatedScalarEvolution
argument_list|(
name|ScalarEvolution
operator|&
name|SE
argument_list|)
block|;
specifier|const
name|SCEVUnionPredicate
operator|&
name|getUnionPredicate
argument_list|()
specifier|const
block|;
comment|/// \brief Returns the SCEV expression of V, in the context of the current
comment|/// SCEV predicate.
comment|/// The order of transformations applied on the expression of V returned
comment|/// by ScalarEvolution is guaranteed to be preserved, even when adding new
comment|/// predicates.
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
comment|/// \brief Adds a new predicate.
name|void
name|addPredicate
argument_list|(
specifier|const
name|SCEVPredicate
operator|&
name|Pred
argument_list|)
block|;
comment|/// \brief Returns the ScalarEvolution analysis used.
name|ScalarEvolution
operator|*
name|getSE
argument_list|()
specifier|const
block|{
return|return
operator|&
name|SE
return|;
block|}
name|private
operator|:
comment|/// \brief Increments the version number of the predicate.
comment|/// This needs to be called every time the SCEV predicate changes.
name|void
name|updateGeneration
argument_list|()
block|;
comment|/// Holds a SCEV and the version number of the SCEV predicate used to
comment|/// perform the rewrite of the expression.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
specifier|const
name|SCEV
operator|*
operator|>
name|RewriteEntry
expr_stmt|;
comment|/// Maps a SCEV to the rewrite result of that SCEV at a certain version
comment|/// number. If this number doesn't match the current Generation, we will
comment|/// need to do a rewrite. To preserve the transformation order of previous
comment|/// rewrites, we will rewrite the previous result instead of the original
comment|/// SCEV.
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
operator|,
name|RewriteEntry
operator|>
name|RewriteMap
block|;
comment|/// The ScalarEvolution analysis.
name|ScalarEvolution
operator|&
name|SE
block|;
comment|/// The SCEVPredicate that forms our context. We will rewrite all
comment|/// expressions assuming that this predicate true.
name|SCEVUnionPredicate
name|Preds
block|;
comment|/// Marks the version of the SCEV predicate used. When rewriting a SCEV
comment|/// expression we mark it with the version of the predicate. We use this to
comment|/// figure out if the predicate has changed from the last rewrite of the
comment|/// SCEV. If so, we need to perform a new rewrite.
name|unsigned
name|Generation
block|;   }
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

