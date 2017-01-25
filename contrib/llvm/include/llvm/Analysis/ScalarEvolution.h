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
file|"llvm/ADT/SetVector.h"
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
file|"llvm/IR/ValueMap.h"
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
name|class
name|Function
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
comment|/// This class represents an assumption made using SCEV expressions which can
comment|/// be checked at run-time.
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
block|,
name|P_Wrap
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
comment|/// Returns the estimated complexity of this predicate.  This is roughly
comment|/// measured in the number of run-time checks required.
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
comment|/// Returns true if the predicate is always true. This means that no
comment|/// assumptions were made and nothing needs to be checked at run-time.
name|virtual
name|bool
name|isAlwaysTrue
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// Returns true if this predicate implies \p N.
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
comment|/// Prints a textual representation of this predicate with an indentation of
comment|/// \p Depth.
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
comment|/// Returns the SCEV to which this predicate applies, or nullptr if this is
comment|/// a SCEVUnionPredicate.
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
comment|/// This class represents an assumption that two SCEV expressions are equal,
comment|/// and this can be checked at run-time. We assume that the left hand side is
comment|/// a SCEVUnknown and the right hand side a constant.
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
comment|/// Returns the left hand side of the equality.
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
comment|/// Returns the right hand side of the equality.
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
comment|/// This class represents an assumption made on an AddRec expression. Given an
comment|/// affine AddRec expression {a,+,b}, we assume that it has the nssw or nusw
comment|/// flags (defined below) in the first X iterations of the loop, where X is a
comment|/// SCEV expression returned by getPredicatedBackedgeTakenCount).
comment|///
comment|/// Note that this does not imply that X is equal to the backedge taken
comment|/// count. This means that if we have a nusw predicate for i32 {0,+,1} with a
comment|/// predicated backedge taken count of X, we only guarantee that {0,+,1} has
comment|/// nusw in the first X iterations. {0,+,1} may still wrap in the loop if we
comment|/// have more than X iterations.
name|class
name|SCEVWrapPredicate
name|final
operator|:
name|public
name|SCEVPredicate
block|{
name|public
operator|:
comment|/// Similar to SCEV::NoWrapFlags, but with slightly different semantics
comment|/// for FlagNUSW. The increment is considered to be signed, and a + b
comment|/// (where b is the increment) is considered to wrap if:
comment|///    zext(a + b) != zext(a) + sext(b)
comment|///
comment|/// If Signed is a function that takes an n-bit tuple and maps to the
comment|/// integer domain as the tuples value interpreted as twos complement,
comment|/// and Unsigned a function that takes an n-bit tuple and maps to the
comment|/// integer domain as as the base two value of input tuple, then a + b
comment|/// has IncrementNUSW iff:
comment|///
comment|/// 0<= Unsigned(a) + Signed(b)< 2^n
comment|///
comment|/// The IncrementNSSW flag has identical semantics with SCEV::FlagNSW.
comment|///
comment|/// Note that the IncrementNUSW flag is not commutative: if base + inc
comment|/// has IncrementNUSW, then inc + base doesn't neccessarily have this
comment|/// property. The reason for this is that this is used for sign/zero
comment|/// extending affine AddRec SCEV expressions when a SCEVWrapPredicate is
comment|/// assumed. A {base,+,inc} expression is already non-commutative with
comment|/// regards to base and inc, since it is interpreted as:
comment|///     (((base + inc) + inc) + inc) ...
expr|enum
name|IncrementWrapFlags
block|{
name|IncrementAnyWrap
operator|=
literal|0
block|,
comment|// No guarantee.
name|IncrementNUSW
operator|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
comment|// No unsigned with signed increment wrap.
name|IncrementNSSW
operator|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
comment|// No signed with signed increment wrap
comment|// (equivalent with SCEV::NSW)
name|IncrementNoWrapMask
operator|=
operator|(
literal|1
operator|<<
literal|2
operator|)
operator|-
literal|1
block|}
block|;
comment|/// Convenient IncrementWrapFlags manipulation methods.
specifier|static
name|SCEVWrapPredicate
operator|::
name|IncrementWrapFlags
name|LLVM_ATTRIBUTE_UNUSED_RESULT
name|clearFlags
argument_list|(
argument|SCEVWrapPredicate::IncrementWrapFlags Flags
argument_list|,
argument|SCEVWrapPredicate::IncrementWrapFlags OffFlags
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|Flags
operator|&
name|IncrementNoWrapMask
operator|)
operator|==
name|Flags
operator|&&
literal|"Invalid flags value!"
argument_list|)
block|;
name|assert
argument_list|(
operator|(
name|OffFlags
operator|&
name|IncrementNoWrapMask
operator|)
operator|==
name|OffFlags
operator|&&
literal|"Invalid flags value!"
argument_list|)
block|;
return|return
operator|(
name|SCEVWrapPredicate
operator|::
name|IncrementWrapFlags
operator|)
operator|(
name|Flags
operator|&
operator|~
name|OffFlags
operator|)
return|;
block|}
specifier|static
name|SCEVWrapPredicate
operator|::
name|IncrementWrapFlags
name|LLVM_ATTRIBUTE_UNUSED_RESULT
name|maskFlags
argument_list|(
argument|SCEVWrapPredicate::IncrementWrapFlags Flags
argument_list|,
argument|int Mask
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|Flags
operator|&
name|IncrementNoWrapMask
operator|)
operator|==
name|Flags
operator|&&
literal|"Invalid flags value!"
argument_list|)
block|;
name|assert
argument_list|(
operator|(
name|Mask
operator|&
name|IncrementNoWrapMask
operator|)
operator|==
name|Mask
operator|&&
literal|"Invalid mask value!"
argument_list|)
block|;
return|return
operator|(
name|SCEVWrapPredicate
operator|::
name|IncrementWrapFlags
operator|)
operator|(
name|Flags
operator|&
name|Mask
operator|)
return|;
block|}
specifier|static
name|SCEVWrapPredicate
operator|::
name|IncrementWrapFlags
name|LLVM_ATTRIBUTE_UNUSED_RESULT
name|setFlags
argument_list|(
argument|SCEVWrapPredicate::IncrementWrapFlags Flags
argument_list|,
argument|SCEVWrapPredicate::IncrementWrapFlags OnFlags
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|Flags
operator|&
name|IncrementNoWrapMask
operator|)
operator|==
name|Flags
operator|&&
literal|"Invalid flags value!"
argument_list|)
block|;
name|assert
argument_list|(
operator|(
name|OnFlags
operator|&
name|IncrementNoWrapMask
operator|)
operator|==
name|OnFlags
operator|&&
literal|"Invalid flags value!"
argument_list|)
block|;
return|return
operator|(
name|SCEVWrapPredicate
operator|::
name|IncrementWrapFlags
operator|)
operator|(
name|Flags
operator||
name|OnFlags
operator|)
return|;
block|}
comment|/// Returns the set of SCEVWrapPredicate no wrap flags implied by a
comment|/// SCEVAddRecExpr.
specifier|static
name|SCEVWrapPredicate
operator|::
name|IncrementWrapFlags
name|getImpliedFlags
argument_list|(
specifier|const
name|SCEVAddRecExpr
operator|*
name|AR
argument_list|,
name|ScalarEvolution
operator|&
name|SE
argument_list|)
block|;
name|private
operator|:
specifier|const
name|SCEVAddRecExpr
operator|*
name|AR
block|;
name|IncrementWrapFlags
name|Flags
block|;
name|public
operator|:
name|explicit
name|SCEVWrapPredicate
argument_list|(
argument|const FoldingSetNodeIDRef ID
argument_list|,
argument|const SCEVAddRecExpr *AR
argument_list|,
argument|IncrementWrapFlags Flags
argument_list|)
block|;
comment|/// Returns the set assumed no overflow flags.
name|IncrementWrapFlags
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|Flags
return|;
block|}
comment|/// Implementation of the SCEVPredicate interface
specifier|const
name|SCEV
operator|*
name|getExpr
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
name|P_Wrap
return|;
block|}
expr|}
block|;
comment|/// This class represents a composition of other SCEV predicates, and is the
comment|/// class that most clients will interact with.  This is equivalent to a
comment|/// logical "AND" of all the predicates in the union.
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
comment|/// Adds a predicate to this union.
name|void
name|add
argument_list|(
specifier|const
name|SCEVPredicate
operator|*
name|N
argument_list|)
block|;
comment|/// Returns a reference to a vector containing all predicates which apply to
comment|/// \p Expr.
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
comment|/// We estimate the complexity of a union predicate as the size number of
comment|/// predicates in the union.
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
comment|/// Does the module have any calls to the llvm.experimental.guard intrinsic
comment|/// at all?  If this is false, we avoid doing work that will only help if
comment|/// thare are guards present in the IR.
comment|///
name|bool
name|HasGuards
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
comment|/// The typedef for HasRecMap.
comment|///
typedef|typedef
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
operator|,
name|bool
operator|>
name|HasRecMapType
expr_stmt|;
comment|/// This is a cache to record whether a SCEV contains any scAddRecExpr.
name|HasRecMapType
name|HasRecMap
block|;
comment|/// The typedef for ExprValueMap.
comment|///
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|Value
operator|*
operator|,
name|ConstantInt
operator|*
operator|>
name|ValueOffsetPair
expr_stmt|;
typedef|typedef
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
operator|,
name|SetVector
operator|<
name|ValueOffsetPair
operator|>>
name|ExprValueMapType
expr_stmt|;
comment|/// ExprValueMap -- This map records the original values from which
comment|/// the SCEV expr is generated from.
comment|///
comment|/// We want to represent the mapping as SCEV -> ValueOffsetPair instead
comment|/// of SCEV -> Value:
comment|/// Suppose we know S1 expands to V1, and
comment|///  S1 = S2 + C_a
comment|///  S3 = S2 + C_b
comment|/// where C_a and C_b are different SCEVConstants. Then we'd like to
comment|/// expand S3 as V1 - C_a + C_b instead of expanding S2 literally.
comment|/// It is helpful when S2 is a complex SCEV expr.
comment|///
comment|/// In order to do that, we represent ExprValueMap as a mapping from
comment|/// SCEV to ValueOffsetPair. We will save both S1->{V1, 0} and
comment|/// S2->{V1, C_a} into the map when we create SCEV for V1. When S3
comment|/// is expanded, it will first expand S2 to V1 - C_a because of
comment|/// S2->{V1, C_a} in the map, then expand S3 to V1 - C_a + C_b.
comment|///
comment|/// Note: S->{V, Offset} in the ExprValueMap means S can be expanded
comment|/// to V - Offset.
name|ExprValueMapType
name|ExprValueMap
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
comment|/// A predicate union guard for this ExitLimit. The result is only
comment|/// valid if this predicate evaluates to 'true' at run-time.
name|SCEVUnionPredicate
name|Pred
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
argument_list|,
name|SCEVUnionPredicate
operator|&
name|P
argument_list|)
operator|:
name|Exact
argument_list|(
name|E
argument_list|)
block|,
name|Max
argument_list|(
name|M
argument_list|)
block|,
name|Pred
argument_list|(
argument|P
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
comment|/// Test whether this ExitLimit contains all information.
name|bool
name|hasFullInfo
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
return|;
block|}
expr|}
block|;
comment|/// Forward declaration of ExitNotTakenExtras
block|struct
name|ExitNotTakenExtras
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
name|ExitNotTakenExtras
operator|*
name|ExtraInfo
block|;
name|bool
name|Complete
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
name|nullptr
argument_list|)
block|,
name|ExtraInfo
argument_list|(
name|nullptr
argument_list|)
block|,
name|Complete
argument_list|(
argument|true
argument_list|)
block|{}
name|ExitNotTakenInfo
argument_list|(
name|BasicBlock
operator|*
name|ExitBlock
argument_list|,
specifier|const
name|SCEV
operator|*
name|Expr
argument_list|,
name|ExitNotTakenExtras
operator|*
name|Ptr
argument_list|)
operator|:
name|ExitingBlock
argument_list|(
name|ExitBlock
argument_list|)
block|,
name|ExactNotTaken
argument_list|(
name|Expr
argument_list|)
block|,
name|ExtraInfo
argument_list|(
name|Ptr
argument_list|)
block|,
name|Complete
argument_list|(
argument|true
argument_list|)
block|{}
comment|/// Return true if all loop exits are computable.
name|bool
name|isCompleteList
argument_list|()
specifier|const
block|{
return|return
name|Complete
return|;
block|}
comment|/// Sets the incomplete property, indicating that one of the loop exits
comment|/// doesn't have a corresponding ExitNotTakenInfo entry.
name|void
name|setIncomplete
argument_list|()
block|{
name|Complete
operator|=
name|false
block|; }
comment|/// Returns a pointer to the predicate associated with this information,
comment|/// or nullptr if this doesn't exist (meaning always true).
name|SCEVUnionPredicate
operator|*
name|getPred
argument_list|()
specifier|const
block|{
if|if
condition|(
name|ExtraInfo
condition|)
return|return
operator|&
name|ExtraInfo
operator|->
name|Pred
return|;
return|return
name|nullptr
return|;
block|}
comment|/// Return true if the SCEV predicate associated with this information
comment|/// is always true.
name|bool
name|hasAlwaysTruePred
argument_list|()
specifier|const
block|{
return|return
operator|!
name|getPred
argument_list|()
operator|||
name|getPred
argument_list|()
operator|->
name|isAlwaysTrue
argument_list|()
return|;
block|}
comment|/// Defines a simple forward iterator for ExitNotTakenInfo.
name|class
name|ExitNotTakenInfoIterator
operator|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
block|,
name|ExitNotTakenInfo
operator|>
block|{
specifier|const
name|ExitNotTakenInfo
operator|*
name|Start
block|;
name|unsigned
name|Position
block|;
name|public
operator|:
name|ExitNotTakenInfoIterator
argument_list|(
argument|const ExitNotTakenInfo *Start
argument_list|,
argument|unsigned Position
argument_list|)
operator|:
name|Start
argument_list|(
name|Start
argument_list|)
block|,
name|Position
argument_list|(
argument|Position
argument_list|)
block|{}
specifier|const
name|ExitNotTakenInfo
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
if|if
condition|(
name|Position
operator|==
literal|0
condition|)
return|return
operator|*
name|Start
return|;
return|return
name|Start
operator|->
name|ExtraInfo
operator|->
name|Exits
index|[
name|Position
operator|-
literal|1
index|]
return|;
block|}
specifier|const
name|ExitNotTakenInfo
operator|*
name|operator
operator|->
expr|(
block|)
specifier|const
block|{
if|if
condition|(
name|Position
operator|==
literal|0
condition|)
return|return
name|Start
return|;
return|return
operator|&
name|Start
operator|->
name|ExtraInfo
operator|->
name|Exits
index|[
name|Position
operator|-
literal|1
index|]
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ExitNotTakenInfoIterator
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Start
operator|==
name|RHS
operator|.
name|Start
operator|&&
name|Position
operator|==
name|RHS
operator|.
name|Position
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|ExitNotTakenInfoIterator
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Start
operator|!=
name|RHS
operator|.
name|Start
operator|||
name|Position
operator|!=
name|RHS
operator|.
name|Position
return|;
block|}
name|ExitNotTakenInfoIterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Preincrement
if|if
condition|(
operator|!
name|Start
condition|)
return|return
operator|*
name|this
return|;
name|unsigned
name|Elements
operator|=
name|Start
operator|->
name|ExtraInfo
condition|?
name|Start
operator|->
name|ExtraInfo
operator|->
name|Exits
operator|.
name|size
argument_list|()
operator|+
literal|1
else|:
literal|1
expr_stmt|;
operator|++
name|Position
expr_stmt|;
comment|// We've run out of elements.
if|if
condition|(
name|Position
operator|==
name|Elements
condition|)
block|{
name|Start
operator|=
name|nullptr
expr_stmt|;
name|Position
operator|=
literal|0
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|ExitNotTakenInfoIterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|ExitNotTakenInfoIterator
name|Tmp
operator|=
operator|*
name|this
block|;
operator|++
operator|*
name|this
block|;
return|return
name|Tmp
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// Iterators
end_comment

begin_expr_stmt
name|ExitNotTakenInfoIterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|ExitNotTakenInfoIterator
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ExitNotTakenInfoIterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|ExitNotTakenInfoIterator
argument_list|(
name|nullptr
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// Describes the extra information that a ExitNotTakenInfo can have.
end_comment

begin_struct
struct|struct
name|ExitNotTakenExtras
block|{
comment|/// The predicate associated with the ExitNotTakenInfo struct.
name|SCEVUnionPredicate
name|Pred
decl_stmt|;
comment|/// The extra exits in the loop. Only the ExitNotTakenExtras structure
comment|/// pointed to by the first ExitNotTakenInfo struct (associated with the
comment|/// first loop exit) will populate this vector to prevent having
comment|/// redundant information.
name|SmallVector
operator|<
name|ExitNotTakenInfo
operator|,
literal|4
operator|>
name|Exits
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// A struct containing the information attached to a backedge.
end_comment

begin_struct
struct|struct
name|EdgeInfo
block|{
name|EdgeInfo
argument_list|(
name|BasicBlock
operator|*
name|Block
argument_list|,
specifier|const
name|SCEV
operator|*
name|Taken
argument_list|,
name|SCEVUnionPredicate
operator|&
name|P
argument_list|)
operator|:
name|ExitBlock
argument_list|(
name|Block
argument_list|)
operator|,
name|Taken
argument_list|(
name|Taken
argument_list|)
operator|,
name|Pred
argument_list|(
argument|std::move(P)
argument_list|)
block|{}
comment|/// The exit basic block.
name|BasicBlock
operator|*
name|ExitBlock
expr_stmt|;
comment|/// The (exact) number of time we take the edge back.
specifier|const
name|SCEV
modifier|*
name|Taken
decl_stmt|;
comment|/// The SCEV predicated associated with Taken. If Pred doesn't evaluate
comment|/// to true, the information in Taken is not valid (or equivalent with
comment|/// a CouldNotCompute.
name|SCEVUnionPredicate
name|Pred
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// Information about the backedge-taken count of a loop. This currently
end_comment

begin_comment
comment|/// includes an exact count and a maximum count.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|BackedgeTakenInfo
block|{
comment|/// A list of computable exits and their not-taken counts.  Loops almost
comment|/// never have more than one computable exit.
name|ExitNotTakenInfo
name|ExitNotTaken
decl_stmt|;
comment|/// An expression indicating the least maximum backedge-taken count of the
comment|/// loop that is known, or a SCEVCouldNotCompute. This expression is only
comment|/// valid if the predicates associated with all loop exits are true.
specifier|const
name|SCEV
modifier|*
name|Max
decl_stmt|;
name|public
label|:
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
argument|SmallVectorImpl<EdgeInfo>&ExitCounts
argument_list|,
argument|bool Complete
argument_list|,
argument|const SCEV *MaxCount
argument_list|)
expr_stmt|;
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
comment|/// Test whether this BackedgeTakenInfo contains complete information.
name|bool
name|hasFullInfo
argument_list|()
specifier|const
block|{
return|return
name|ExitNotTaken
operator|.
name|isCompleteList
argument_list|()
return|;
block|}
comment|/// Return an expression indicating the exact backedge-taken count of the
comment|/// loop if it is known or SCEVCouldNotCompute otherwise. This is the
comment|/// number of times the loop header can be guaranteed to execute, minus
comment|/// one.
comment|///
comment|/// If the SCEV predicate associated with the answer can be different
comment|/// from AlwaysTrue, we must add a (non null) Predicates argument.
comment|/// The SCEV predicate associated with the answer will be added to
comment|/// Predicates. A run-time check needs to be emitted for the SCEV
comment|/// predicate in order for the answer to be valid.
comment|///
comment|/// Note that we should always know if we need to pass a predicate
comment|/// argument or not from the way the ExitCounts vector was computed.
comment|/// If we allowed SCEV predicates to be generated when populating this
comment|/// vector, this information can contain them and therefore a
comment|/// SCEVPredicate argument should be added to getExact.
specifier|const
name|SCEV
modifier|*
name|getExact
argument_list|(
name|ScalarEvolution
operator|*
name|SE
argument_list|,
name|SCEVUnionPredicate
operator|*
name|Predicates
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the number of times this loop exit may fall through to the back
comment|/// edge, or SCEVCouldNotCompute. The loop is guaranteed not to exit via
comment|/// this block before this number of iterations, but may exit via another
comment|/// block.
specifier|const
name|SCEV
modifier|*
name|getExact
argument_list|(
name|BasicBlock
operator|*
name|ExitingBlock
argument_list|,
name|ScalarEvolution
operator|*
name|SE
argument_list|)
decl|const
decl_stmt|;
comment|/// Get the max backedge taken count for the loop.
specifier|const
name|SCEV
modifier|*
name|getMax
argument_list|(
name|ScalarEvolution
operator|*
name|SE
argument_list|)
decl|const
decl_stmt|;
comment|/// Return true if any backedge taken count expressions refer to the given
comment|/// subexpression.
name|bool
name|hasOperand
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|,
name|ScalarEvolution
operator|*
name|SE
argument_list|)
decl|const
decl_stmt|;
comment|/// Invalidate this result and free associated memory.
name|void
name|clear
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Cache the backedge-taken count of the loops for this function as they
end_comment

begin_comment
comment|/// are computed.
end_comment

begin_expr_stmt
name|DenseMap
operator|<
specifier|const
name|Loop
operator|*
operator|,
name|BackedgeTakenInfo
operator|>
name|BackedgeTakenCounts
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Cache the predicated backedge-taken count of the loops for this
end_comment

begin_comment
comment|/// function as they are computed.
end_comment

begin_expr_stmt
name|DenseMap
operator|<
specifier|const
name|Loop
operator|*
operator|,
name|BackedgeTakenInfo
operator|>
name|PredicatedBackedgeTakenCounts
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// This map contains entries for all of the PHI instructions that we
end_comment

begin_comment
comment|/// attempt to compute constant evolutions for.  This allows us to avoid
end_comment

begin_comment
comment|/// potentially expensive recomputation of these properties.  An instruction
end_comment

begin_comment
comment|/// maps to null if we are unable to compute its exit value.
end_comment

begin_expr_stmt
name|DenseMap
operator|<
name|PHINode
operator|*
operator|,
name|Constant
operator|*
operator|>
name|ConstantEvolutionLoopExitValue
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// This map contains entries for all the expressions that we attempt to
end_comment

begin_comment
comment|/// compute getSCEVAtScope information for, which can be expensive in
end_comment

begin_comment
comment|/// extreme cases.
end_comment

begin_expr_stmt
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
operator|,
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|Loop
operator|*
operator|,
specifier|const
name|SCEV
operator|*
operator|>
operator|,
literal|2
operator|>
expr|>
name|ValuesAtScopes
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Memoized computeLoopDisposition results.
end_comment

begin_expr_stmt
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
operator|,
name|SmallVector
operator|<
name|PointerIntPair
operator|<
specifier|const
name|Loop
operator|*
operator|,
literal|2
operator|,
name|LoopDisposition
operator|>
operator|,
literal|2
operator|>>
name|LoopDispositions
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Cache for \c loopHasNoAbnormalExits.
end_comment

begin_expr_stmt
name|DenseMap
operator|<
specifier|const
name|Loop
operator|*
operator|,
name|bool
operator|>
name|LoopHasNoAbnormalExits
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Returns true if \p L contains no instruction that can abnormally exit
end_comment

begin_comment
comment|/// the loop (i.e. via throwing an exception, by terminating the thread
end_comment

begin_comment
comment|/// cleanly or by infinite looping in a called function).  Strictly
end_comment

begin_comment
comment|/// speaking, the last one is not leaving the loop, but is identical to
end_comment

begin_comment
comment|/// leaving the loop for reasoning about undefined behavior.
end_comment

begin_function_decl
name|bool
name|loopHasNoAbnormalExits
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Compute a LoopDisposition value.
end_comment

begin_function_decl
name|LoopDisposition
name|computeLoopDisposition
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
end_function_decl

begin_comment
comment|/// Memoized computeBlockDisposition results.
end_comment

begin_expr_stmt
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
operator|,
name|SmallVector
operator|<
name|PointerIntPair
operator|<
specifier|const
name|BasicBlock
operator|*
operator|,
literal|2
operator|,
name|BlockDisposition
operator|>
operator|,
literal|2
operator|>>
name|BlockDispositions
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Compute a BlockDisposition value.
end_comment

begin_function_decl
name|BlockDisposition
name|computeBlockDisposition
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
end_function_decl

begin_comment
comment|/// Memoized results from getRange
end_comment

begin_expr_stmt
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
operator|,
name|ConstantRange
operator|>
name|UnsignedRanges
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Memoized results from getRange
end_comment

begin_expr_stmt
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
operator|,
name|ConstantRange
operator|>
name|SignedRanges
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Used to parameterize getRange
end_comment

begin_enum
enum|enum
name|RangeSignHint
block|{
name|HINT_RANGE_UNSIGNED
block|,
name|HINT_RANGE_SIGNED
block|}
enum|;
end_enum

begin_comment
comment|/// Set the memoized range for the given SCEV.
end_comment

begin_function
specifier|const
name|ConstantRange
modifier|&
name|setRange
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|,
name|RangeSignHint
name|Hint
parameter_list|,
specifier|const
name|ConstantRange
modifier|&
name|CR
parameter_list|)
block|{
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
operator|,
name|ConstantRange
operator|>
operator|&
name|Cache
operator|=
name|Hint
operator|==
name|HINT_RANGE_UNSIGNED
condition|?
name|UnsignedRanges
else|:
name|SignedRanges
expr_stmt|;
name|auto
name|Pair
init|=
name|Cache
operator|.
name|insert
argument_list|(
block|{
name|S
block|,
name|CR
block|}
argument_list|)
decl_stmt|;
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
end_function

begin_comment
comment|/// Determine the range for a particular SCEV.
end_comment

begin_function_decl
name|ConstantRange
name|getRange
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|,
name|RangeSignHint
name|Hint
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Determines the range for the affine SCEVAddRecExpr {\p Start,+,\p Stop}.
end_comment

begin_comment
comment|/// Helper for \c getRange.
end_comment

begin_function_decl
name|ConstantRange
name|getRangeForAffineAR
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|Start
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|Stop
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|MaxBECount
parameter_list|,
name|unsigned
name|BitWidth
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Try to compute a range for the affine SCEVAddRecExpr {\p Start,+,\p
end_comment

begin_comment
comment|/// Stop} by "factoring out" a ternary expression from the add recurrence.
end_comment

begin_comment
comment|/// Helper called by \c getRange.
end_comment

begin_function_decl
name|ConstantRange
name|getRangeViaFactoring
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|Start
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|Stop
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|MaxBECount
parameter_list|,
name|unsigned
name|BitWidth
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// We know that there is no SCEV for the specified value.  Analyze the
end_comment

begin_comment
comment|/// expression.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// Provide the special handling we need to analyze PHI SCEVs.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// Helper function called from createNodeForPHI.
end_comment

begin_function_decl
specifier|const
name|SCEV
modifier|*
name|createAddRecFromPHI
parameter_list|(
name|PHINode
modifier|*
name|PN
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Helper function called from createNodeForPHI.
end_comment

begin_function_decl
specifier|const
name|SCEV
modifier|*
name|createNodeFromSelectLikePHI
parameter_list|(
name|PHINode
modifier|*
name|PN
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Provide special handling for a select-like instruction (currently this
end_comment

begin_comment
comment|/// is either a select instruction or a phi node).  \p I is the instruction
end_comment

begin_comment
comment|/// being processed, and it is assumed equivalent to "Cond ? TrueVal :
end_comment

begin_comment
comment|/// FalseVal".
end_comment

begin_function_decl
specifier|const
name|SCEV
modifier|*
name|createNodeForSelectOrPHI
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|,
name|Value
modifier|*
name|Cond
parameter_list|,
name|Value
modifier|*
name|TrueVal
parameter_list|,
name|Value
modifier|*
name|FalseVal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Provide the special handling we need to analyze GEP SCEVs.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// Implementation code for getSCEVAtScope; called at most once for each
end_comment

begin_comment
comment|/// SCEV+Loop pair.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// This looks up computed SCEV values for all instructions that depend on
end_comment

begin_comment
comment|/// the given instruction and removes them from the ValueExprMap map if they
end_comment

begin_comment
comment|/// reference SymName. This is used during PHI resolution.
end_comment

begin_function_decl
name|void
name|forgetSymbolicName
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
end_function_decl

begin_comment
comment|/// Return the BackedgeTakenInfo for the given loop, lazily computing new
end_comment

begin_comment
comment|/// values if the loop hasn't been analyzed yet. The returned result is
end_comment

begin_comment
comment|/// guaranteed not to be predicated.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// Similar to getBackedgeTakenInfo, but will add predicates as required
end_comment

begin_comment
comment|/// with the purpose of returning complete information.
end_comment

begin_function_decl
specifier|const
name|BackedgeTakenInfo
modifier|&
name|getPredicatedBackedgeTakenInfo
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Compute the number of times the specified loop will iterate.
end_comment

begin_comment
comment|/// If AllowPredicates is set, we will create new SCEV predicates as
end_comment

begin_comment
comment|/// necessary in order to return an exact answer.
end_comment

begin_function_decl
name|BackedgeTakenInfo
name|computeBackedgeTakenCount
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|,
name|bool
name|AllowPredicates
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Compute the number of times the backedge of the specified loop will
end_comment

begin_comment
comment|/// execute if it exits via the specified block. If AllowPredicates is set,
end_comment

begin_comment
comment|/// this call will try to use a minimal set of SCEV predicates in order to
end_comment

begin_comment
comment|/// return an exact answer.
end_comment

begin_function_decl
name|ExitLimit
name|computeExitLimit
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|,
name|BasicBlock
modifier|*
name|ExitingBlock
parameter_list|,
name|bool
name|AllowPredicates
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Compute the number of times the backedge of the specified loop will
end_comment

begin_comment
comment|/// execute if its exit condition were a conditional branch of ExitCond,
end_comment

begin_comment
comment|/// TBB, and FBB.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \p ControlsExit is true if ExitCond directly controls the exit
end_comment

begin_comment
comment|/// branch. In this case, we can assume that the loop exits only if the
end_comment

begin_comment
comment|/// condition is true and can infer that failing to meet the condition prior
end_comment

begin_comment
comment|/// to integer wraparound results in undefined behavior.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If \p AllowPredicates is set, this call will try to use a minimal set of
end_comment

begin_comment
comment|/// SCEV predicates in order to return an exact answer.
end_comment

begin_function_decl
name|ExitLimit
name|computeExitLimitFromCond
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
parameter_list|,
name|bool
name|ControlsExit
parameter_list|,
name|bool
name|AllowPredicates
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Compute the number of times the backedge of the specified loop will
end_comment

begin_comment
comment|/// execute if its exit condition were a conditional branch of the ICmpInst
end_comment

begin_comment
comment|/// ExitCond, TBB, and FBB. If AllowPredicates is set, this call will try
end_comment

begin_comment
comment|/// to use a minimal set of SCEV predicates in order to return an exact
end_comment

begin_comment
comment|/// answer.
end_comment

begin_function_decl
name|ExitLimit
name|computeExitLimitFromICmp
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
parameter_list|,
name|bool
name|IsSubExpr
parameter_list|,
name|bool
name|AllowPredicates
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Compute the number of times the backedge of the specified loop will
end_comment

begin_comment
comment|/// execute if its exit condition were a switch with a single exiting case
end_comment

begin_comment
comment|/// to ExitingBB.
end_comment

begin_function_decl
name|ExitLimit
name|computeExitLimitFromSingleExitSwitch
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|,
name|SwitchInst
modifier|*
name|Switch
parameter_list|,
name|BasicBlock
modifier|*
name|ExitingBB
parameter_list|,
name|bool
name|IsSubExpr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Given an exit condition of 'icmp op load X, cst', try to see if we can
end_comment

begin_comment
comment|/// compute the backedge-taken count.
end_comment

begin_decl_stmt
name|ExitLimit
name|computeLoadConstantCompareExitLimit
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
end_decl_stmt

begin_comment
comment|/// Compute the exit limit of a loop that is controlled by a
end_comment

begin_comment
comment|/// "(IV>> 1) != 0" type comparison.  We cannot compute the exact trip
end_comment

begin_comment
comment|/// count in these cases (since SCEV has no way of expressing them), but we
end_comment

begin_comment
comment|/// can still sometimes compute an upper bound.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Return an ExitLimit for a loop whose backedge is guarded by `LHS Pred
end_comment

begin_comment
comment|/// RHS`.
end_comment

begin_decl_stmt
name|ExitLimit
name|computeShiftCompareExitLimit
argument_list|(
name|Value
operator|*
name|LHS
argument_list|,
name|Value
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
name|Pred
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// If the loop is known to execute a constant number of times (the
end_comment

begin_comment
comment|/// condition evolves only from constants), try to evaluate a few iterations
end_comment

begin_comment
comment|/// of the loop until we get the exit condition gets a value of ExitWhen
end_comment

begin_comment
comment|/// (true or false).  If we cannot evaluate the exit count of the loop,
end_comment

begin_comment
comment|/// return CouldNotCompute.
end_comment

begin_function_decl
specifier|const
name|SCEV
modifier|*
name|computeExitCountExhaustively
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
end_function_decl

begin_comment
comment|/// Return the number of times an exit condition comparing the specified
end_comment

begin_comment
comment|/// value to zero will execute.  If not computable, return CouldNotCompute.
end_comment

begin_comment
comment|/// If AllowPredicates is set, this call will try to use a minimal set of
end_comment

begin_comment
comment|/// SCEV predicates in order to return an exact answer.
end_comment

begin_function_decl
name|ExitLimit
name|howFarToZero
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
parameter_list|,
name|bool
name|IsSubExpr
parameter_list|,
name|bool
name|AllowPredicates
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return the number of times an exit condition checking the specified
end_comment

begin_comment
comment|/// value for nonzero will execute.  If not computable, return
end_comment

begin_comment
comment|/// CouldNotCompute.
end_comment

begin_function_decl
name|ExitLimit
name|howFarToNonZero
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
end_function_decl

begin_comment
comment|/// Return the number of times an exit condition containing the specified
end_comment

begin_comment
comment|/// less-than comparison will execute.  If not computable, return
end_comment

begin_comment
comment|/// CouldNotCompute.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \p isSigned specifies whether the less-than is signed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \p ControlsExit is true when the LHS< RHS condition directly controls
end_comment

begin_comment
comment|/// the branch (loops exits only if condition is true). In this case, we can
end_comment

begin_comment
comment|/// use NoWrapFlags to skip overflow checks.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If \p AllowPredicates is set, this call will try to use a minimal set of
end_comment

begin_comment
comment|/// SCEV predicates in order to return an exact answer.
end_comment

begin_function_decl
name|ExitLimit
name|howManyLessThans
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
parameter_list|,
name|bool
name|ControlsExit
parameter_list|,
name|bool
name|AllowPredicates
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExitLimit
name|howManyGreaterThans
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
parameter_list|,
name|bool
name|IsSubExpr
parameter_list|,
name|bool
name|AllowPredicates
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return a predecessor of BB (which may not be an immediate predecessor)
end_comment

begin_comment
comment|/// which has exactly one successor from which BB is reachable, or null if
end_comment

begin_comment
comment|/// no such block is found.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// Test whether the condition described by Pred, LHS, and RHS is true
end_comment

begin_comment
comment|/// whenever the given FoundCondValue value evaluates to true.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// Test whether the condition described by Pred, LHS, and RHS is true
end_comment

begin_comment
comment|/// whenever the condition described by FoundPred, FoundLHS, FoundRHS is
end_comment

begin_comment
comment|/// true.
end_comment

begin_decl_stmt
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
name|ICmpInst
operator|::
name|Predicate
name|FoundPred
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
end_decl_stmt

begin_comment
comment|/// Test whether the condition described by Pred, LHS, and RHS is true
end_comment

begin_comment
comment|/// whenever the condition described by Pred, FoundLHS, and FoundRHS is
end_comment

begin_comment
comment|/// true.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// Test whether the condition described by Pred, LHS, and RHS is true
end_comment

begin_comment
comment|/// whenever the condition described by Pred, FoundLHS, and FoundRHS is
end_comment

begin_comment
comment|/// true.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// Test whether the condition described by Pred, LHS, and RHS is true
end_comment

begin_comment
comment|/// whenever the condition described by Pred, FoundLHS, and FoundRHS is
end_comment

begin_comment
comment|/// true.  Utility function used by isImpliedCondOperands.  Tries to get
end_comment

begin_comment
comment|/// cases like "X `sgt` 0 => X - 1 `sgt` -1".
end_comment

begin_decl_stmt
name|bool
name|isImpliedCondOperandsViaRanges
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
end_decl_stmt

begin_comment
comment|/// Return true if the condition denoted by \p LHS \p Pred \p RHS is implied
end_comment

begin_comment
comment|/// by a call to \c @llvm.experimental.guard in \p BB.
end_comment

begin_decl_stmt
name|bool
name|isImpliedViaGuard
argument_list|(
name|BasicBlock
operator|*
name|BB
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
end_decl_stmt

begin_comment
comment|/// Test whether the condition described by Pred, LHS, and RHS is true
end_comment

begin_comment
comment|/// whenever the condition described by Pred, FoundLHS, and FoundRHS is
end_comment

begin_comment
comment|/// true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine tries to rule out certain kinds of integer overflow, and
end_comment

begin_comment
comment|/// then tries to reason about arithmetic properties of the predicates.
end_comment

begin_decl_stmt
name|bool
name|isImpliedCondOperandsViaNoOverflow
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
end_decl_stmt

begin_comment
comment|/// If we know that the specified Phi is in the header of its containing
end_comment

begin_comment
comment|/// loop, we know the loop executes a constant number of times, and the PHI
end_comment

begin_comment
comment|/// node is just a recurrence involving constants, fold it.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// Test if the given expression is known to satisfy the condition described
end_comment

begin_comment
comment|/// by Pred and the known constant ranges of LHS and RHS.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|bool
name|isKnownPredicateViaConstantRanges
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
end_decl_stmt

begin_comment
comment|/// Try to prove the condition described by "LHS Pred RHS" by ruling out
end_comment

begin_comment
comment|/// integer overflow.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For instance, this will return true for "A s< (A + C)<nsw>" if C is
end_comment

begin_comment
comment|/// positive.
end_comment

begin_decl_stmt
name|bool
name|isKnownPredicateViaNoOverflow
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
end_decl_stmt

begin_comment
comment|/// Try to split Pred LHS RHS into logical conjunctions (and's) and try to
end_comment

begin_comment
comment|/// prove them individually.
end_comment

begin_decl_stmt
name|bool
name|isKnownPredicateViaSplitting
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
end_decl_stmt

begin_comment
comment|/// Try to match the Expr as "(L + R)<Flags>".
end_comment

begin_decl_stmt
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
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return true if More == (Less + C), where C is a constant.  This is
end_comment

begin_comment
comment|/// intended to be used as a cheaper substitute for full SCEV subtraction.
end_comment

begin_function_decl
name|bool
name|computeConstantDifference
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|Less
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|More
parameter_list|,
name|APInt
modifier|&
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Drop memoized information computed for S.
end_comment

begin_function_decl
name|void
name|forgetMemoizedResults
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return an existing SCEV for V if there is one, otherwise return nullptr.
end_comment

begin_function_decl
specifier|const
name|SCEV
modifier|*
name|getExistingSCEV
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return false iff given SCEV contains a SCEVUnknown with NULL value-
end_comment

begin_comment
comment|/// pointer.
end_comment

begin_decl_stmt
name|bool
name|checkValidity
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return true if `ExtendOpTy`({`Start`,+,`Step`}) can be proved to be
end_comment

begin_comment
comment|/// equal to {`ExtendOpTy`(`Start`),+,`ExtendOpTy`(`Step`)}.  This is
end_comment

begin_comment
comment|/// equivalent to proving no signed (resp. unsigned) wrap in
end_comment

begin_comment
comment|/// {`Start`,+,`Step`} if `ExtendOpTy` is `SCEVSignExtendExpr`
end_comment

begin_comment
comment|/// (resp. `SCEVZeroExtendExpr`).
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
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
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Try to prove NSW or NUW on \p AR relying on ConstantRange manipulation.
end_comment

begin_expr_stmt
name|SCEV
operator|::
name|NoWrapFlags
name|proveNoWrapViaConstantRanges
argument_list|(
specifier|const
name|SCEVAddRecExpr
operator|*
name|AR
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|isMonotonicPredicateImpl
argument_list|(
specifier|const
name|SCEVAddRecExpr
operator|*
name|LHS
argument_list|,
name|ICmpInst
operator|::
name|Predicate
name|Pred
argument_list|,
name|bool
operator|&
name|Increasing
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return true if, for all loop invariant X, the predicate "LHS `Pred` X"
end_comment

begin_comment
comment|/// is monotonically increasing or decreasing.  In the former case set
end_comment

begin_comment
comment|/// `Increasing` to true and in the latter case set `Increasing` to false.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A predicate is said to be monotonically increasing if may go from being
end_comment

begin_comment
comment|/// false to being true as the loop iterates, but never the other way
end_comment

begin_comment
comment|/// around.  A predicate is said to be monotonically decreasing if may go
end_comment

begin_comment
comment|/// from being true to being false as the loop iterates, but never the other
end_comment

begin_comment
comment|/// way around.
end_comment

begin_decl_stmt
name|bool
name|isMonotonicPredicate
argument_list|(
specifier|const
name|SCEVAddRecExpr
operator|*
name|LHS
argument_list|,
name|ICmpInst
operator|::
name|Predicate
name|Pred
argument_list|,
name|bool
operator|&
name|Increasing
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return SCEV no-wrap flags that can be proven based on reasoning about
end_comment

begin_comment
comment|/// how poison produced from no-wrap flags on this value (e.g. a nuw add)
end_comment

begin_comment
comment|/// would trigger undefined behavior on overflow.
end_comment

begin_expr_stmt
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
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return true if the SCEV corresponding to \p I is never poison.  Proving
end_comment

begin_comment
comment|/// this is more complex than proving that just \p I is never poison, since
end_comment

begin_comment
comment|/// SCEV commons expressions across control flow, and you can have cases
end_comment

begin_comment
comment|/// like:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   idx0 = a + b;
end_comment

begin_comment
comment|///   ptr[idx0] = 100;
end_comment

begin_comment
comment|///   if (<condition>) {
end_comment

begin_comment
comment|///     idx1 = a +nsw b;
end_comment

begin_comment
comment|///     ptr[idx1] = 200;
end_comment

begin_comment
comment|///   }
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// where the SCEV expression (+ a b) is guaranteed to not be poison (and
end_comment

begin_comment
comment|/// hence not sign-overflow) only if "<condition>" is true.  Since both
end_comment

begin_comment
comment|/// `idx0` and `idx1` will be mapped to the same SCEV expression, (+ a b),
end_comment

begin_comment
comment|/// it is not okay to annotate (+ a b) with<nsw> in the above example.
end_comment

begin_function_decl
name|bool
name|isSCEVExprNeverPoison
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// This is like \c isSCEVExprNeverPoison but it specifically works for
end_comment

begin_comment
comment|/// instructions that will get mapped to SCEV add recurrences.  Return true
end_comment

begin_comment
comment|/// if \p I will never generate poison under the assumption that \p I is an
end_comment

begin_comment
comment|/// add recurrence on the loop \p L.
end_comment

begin_function_decl
name|bool
name|isAddRecNeverPoison
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|,
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_expr_stmt
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
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|~
name|ScalarEvolution
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ScalarEvolution
argument_list|(
name|ScalarEvolution
operator|&&
name|Arg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// Test if values of the given type are analyzable within the SCEV
end_comment

begin_comment
comment|/// framework. This primarily includes integer types, and it can optionally
end_comment

begin_comment
comment|/// include pointer types if the ScalarEvolution class has access to
end_comment

begin_comment
comment|/// target-specific information.
end_comment

begin_decl_stmt
name|bool
name|isSCEVable
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return the size in bits of the specified type, for which isSCEVable must
end_comment

begin_comment
comment|/// return true.
end_comment

begin_decl_stmt
name|uint64_t
name|getTypeSizeInBits
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return a type with the same bitwidth as the given type and which
end_comment

begin_comment
comment|/// represents how SCEV will treat the given type, for which isSCEVable must
end_comment

begin_comment
comment|/// return true. For pointer types, this is the pointer-sized integer type.
end_comment

begin_decl_stmt
name|Type
modifier|*
name|getEffectiveSCEVType
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return true if the SCEV is a scAddRecExpr or it contains
end_comment

begin_comment
comment|/// scAddRecExpr. The result will be cached in HasRecMap.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|bool
name|containsAddRecurrence
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return the Value set from which the SCEV expr is generated.
end_comment

begin_expr_stmt
name|SetVector
operator|<
name|ValueOffsetPair
operator|>
operator|*
name|getSCEVValues
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Erase Value from ValueExprMap and ExprValueMap.
end_comment

begin_function_decl
name|void
name|eraseValueFromMap
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return a SCEV expression for the full generality of the specified
end_comment

begin_comment
comment|/// expression.
end_comment

begin_function_decl
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
end_function_decl

begin_function_decl
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
end_function_decl

begin_function_decl
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
end_function_decl

begin_function_decl
specifier|const
name|SCEV
modifier|*
name|getConstant
parameter_list|(
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
end_function_decl

begin_function_decl
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
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
operator|=
block|{
name|LHS
block|,
name|RHS
block|}
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
end_decl_stmt

begin_decl_stmt
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
operator|=
block|{
name|Op0
block|,
name|Op1
block|,
name|Op2
block|}
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
operator|=
block|{
name|LHS
block|,
name|RHS
block|}
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
end_decl_stmt

begin_decl_stmt
specifier|const
name|SCEV
modifier|*
name|getMulExpr
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
operator|=
block|{
name|Op0
block|,
name|Op1
block|,
name|Op2
block|}
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
end_decl_stmt

begin_function_decl
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
end_function_decl

begin_function_decl
specifier|const
name|SCEV
modifier|*
name|getUDivExactExpr
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
end_function_decl

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// Returns an expression for a GEP
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \p PointeeType The type used as the basis for the pointer arithmetics
end_comment

begin_comment
comment|/// \p BaseExpr The expression for the pointer operand.
end_comment

begin_comment
comment|/// \p IndexExprs The expressions for the indices.
end_comment

begin_comment
comment|/// \p InBounds Whether the GEP is in bounds.
end_comment

begin_decl_stmt
specifier|const
name|SCEV
modifier|*
name|getGEPExpr
argument_list|(
name|Type
operator|*
name|PointeeType
argument_list|,
specifier|const
name|SCEV
operator|*
name|BaseExpr
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
specifier|const
name|SCEV
operator|*
operator|>
operator|&
name|IndexExprs
argument_list|,
name|bool
name|InBounds
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
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
end_function_decl

begin_decl_stmt
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
end_decl_stmt

begin_function_decl
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
end_function_decl

begin_decl_stmt
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
end_decl_stmt

begin_function_decl
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
end_function_decl

begin_function_decl
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
end_function_decl

begin_function_decl
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
end_function_decl

begin_function_decl
specifier|const
name|SCEV
modifier|*
name|getCouldNotCompute
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Return a SCEV for the constant 0 of a specific type.
end_comment

begin_function
specifier|const
name|SCEV
modifier|*
name|getZero
parameter_list|(
name|Type
modifier|*
name|Ty
parameter_list|)
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
end_function

begin_comment
comment|/// Return a SCEV for the constant 1 of a specific type.
end_comment

begin_function
specifier|const
name|SCEV
modifier|*
name|getOne
parameter_list|(
name|Type
modifier|*
name|Ty
parameter_list|)
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
end_function

begin_comment
comment|/// Return an expression for sizeof AllocTy that is type IntTy
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
specifier|const
name|SCEV
modifier|*
name|getSizeOfExpr
parameter_list|(
name|Type
modifier|*
name|IntTy
parameter_list|,
name|Type
modifier|*
name|AllocTy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return an expression for offsetof on the given field with type IntTy
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
specifier|const
name|SCEV
modifier|*
name|getOffsetOfExpr
parameter_list|(
name|Type
modifier|*
name|IntTy
parameter_list|,
name|StructType
modifier|*
name|STy
parameter_list|,
name|unsigned
name|FieldNo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return the SCEV object corresponding to -V.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
specifier|const
name|SCEV
modifier|*
name|getNegativeSCEV
argument_list|(
specifier|const
name|SCEV
operator|*
name|V
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
end_decl_stmt

begin_comment
comment|/// Return the SCEV object corresponding to ~V.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// Return LHS-RHS.  Minus is represented in SCEV as A+B*-1.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// Return a SCEV corresponding to a conversion of the input value to the
end_comment

begin_comment
comment|/// specified type.  If the type must be extended, it is zero extended.
end_comment

begin_function_decl
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
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return a SCEV corresponding to a conversion of the input value to the
end_comment

begin_comment
comment|/// specified type.  If the type must be extended, it is sign extended.
end_comment

begin_function_decl
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
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return a SCEV corresponding to a conversion of the input value to the
end_comment

begin_comment
comment|/// specified type.  If the type must be extended, it is zero extended.  The
end_comment

begin_comment
comment|/// conversion must not be narrowing.
end_comment

begin_function_decl
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
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return a SCEV corresponding to a conversion of the input value to the
end_comment

begin_comment
comment|/// specified type.  If the type must be extended, it is sign extended.  The
end_comment

begin_comment
comment|/// conversion must not be narrowing.
end_comment

begin_function_decl
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
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return a SCEV corresponding to a conversion of the input value to the
end_comment

begin_comment
comment|/// specified type. If the type must be extended, it is extended with
end_comment

begin_comment
comment|/// unspecified bits. The conversion must not be narrowing.
end_comment

begin_function_decl
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
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return a SCEV corresponding to a conversion of the input value to the
end_comment

begin_comment
comment|/// specified type.  The conversion must not be widening.
end_comment

begin_function_decl
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
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Promote the operands to the wider of the types using zero-extension, and
end_comment

begin_comment
comment|/// then perform a umax operation with them.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// Promote the operands to the wider of the types using zero-extension, and
end_comment

begin_comment
comment|/// then perform a umin operation with them.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// Transitively follow the chain of pointer-type operands until reaching a
end_comment

begin_comment
comment|/// SCEV that does not have a single pointer operand. This returns a
end_comment

begin_comment
comment|/// SCEVUnknown pointer for well-formed pointer-type expressions, but corner
end_comment

begin_comment
comment|/// cases do exist.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// Return a SCEV expression for the specified value at the specified scope
end_comment

begin_comment
comment|/// in the program.  The L value specifies a loop nest to evaluate the
end_comment

begin_comment
comment|/// expression at, where null is the top-level or a specified loop is
end_comment

begin_comment
comment|/// immediately inside of the loop.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This method can be used to compute the exit value for a variable defined
end_comment

begin_comment
comment|/// in a loop by querying what the value will hold in the parent loop.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In the case that a relevant loop exit value cannot be computed, the
end_comment

begin_comment
comment|/// original value V is returned.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// This is a convenience function which does getSCEVAtScope(getSCEV(V), L).
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// Test whether entry to the loop is protected by a conditional between LHS
end_comment

begin_comment
comment|/// and RHS.  This is used to help avoid max expressions in loop trip
end_comment

begin_comment
comment|/// counts, and to eliminate casts.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// Test whether the backedge of the loop is protected by a conditional
end_comment

begin_comment
comment|/// between LHS and RHS.  This is used to to eliminate casts.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// Returns the maximum trip count of the loop if it is a single-exit
end_comment

begin_comment
comment|/// loop and we can compute a small maximum for that loop.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Implemented in terms of the \c getSmallConstantTripCount overload with
end_comment

begin_comment
comment|/// the single exiting block passed to it. See that routine for details.
end_comment

begin_function_decl
name|unsigned
name|getSmallConstantTripCount
parameter_list|(
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Returns the maximum trip count of this loop as a normal unsigned
end_comment

begin_comment
comment|/// value. Returns 0 if the trip count is unknown or not constant. This
end_comment

begin_comment
comment|/// "trip count" assumes that control exits via ExitingBlock. More
end_comment

begin_comment
comment|/// precisely, it is the number of times that control may reach ExitingBlock
end_comment

begin_comment
comment|/// before taking the branch. For loops with multiple exits, it may not be
end_comment

begin_comment
comment|/// the number times that the loop header executes if the loop exits
end_comment

begin_comment
comment|/// prematurely via another branch.
end_comment

begin_function_decl
name|unsigned
name|getSmallConstantTripCount
parameter_list|(
name|Loop
modifier|*
name|L
parameter_list|,
name|BasicBlock
modifier|*
name|ExitingBlock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Returns the largest constant divisor of the trip count of the
end_comment

begin_comment
comment|/// loop if it is a single-exit loop and we can compute a small maximum for
end_comment

begin_comment
comment|/// that loop.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Implemented in terms of the \c getSmallConstantTripMultiple overload with
end_comment

begin_comment
comment|/// the single exiting block passed to it. See that routine for details.
end_comment

begin_function_decl
name|unsigned
name|getSmallConstantTripMultiple
parameter_list|(
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Returns the largest constant divisor of the trip count of this loop as a
end_comment

begin_comment
comment|/// normal unsigned value, if possible. This means that the actual trip
end_comment

begin_comment
comment|/// count is always a multiple of the returned value (don't forget the trip
end_comment

begin_comment
comment|/// count could very well be zero as well!). As explained in the comments
end_comment

begin_comment
comment|/// for getSmallConstantTripCount, this assumes that control exits the loop
end_comment

begin_comment
comment|/// via ExitingBlock.
end_comment

begin_function_decl
name|unsigned
name|getSmallConstantTripMultiple
parameter_list|(
name|Loop
modifier|*
name|L
parameter_list|,
name|BasicBlock
modifier|*
name|ExitingBlock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Get the expression for the number of loop iterations for which this loop
end_comment

begin_comment
comment|/// is guaranteed not to exit via ExitingBlock. Otherwise return
end_comment

begin_comment
comment|/// SCEVCouldNotCompute.
end_comment

begin_function_decl
specifier|const
name|SCEV
modifier|*
name|getExitCount
parameter_list|(
name|Loop
modifier|*
name|L
parameter_list|,
name|BasicBlock
modifier|*
name|ExitingBlock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// If the specified loop has a predictable backedge-taken count, return it,
end_comment

begin_comment
comment|/// otherwise return a SCEVCouldNotCompute object. The backedge-taken count
end_comment

begin_comment
comment|/// is the number of times the loop header will be branched to from within
end_comment

begin_comment
comment|/// the loop. This is one less than the trip count of the loop, since it
end_comment

begin_comment
comment|/// doesn't count the first iteration, when the header is branched to from
end_comment

begin_comment
comment|/// outside the loop.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that it is not valid to call this method on a loop without a
end_comment

begin_comment
comment|/// loop-invariant backedge-taken count (see
end_comment

begin_comment
comment|/// hasLoopInvariantBackedgeTakenCount).
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// Similar to getBackedgeTakenCount, except it will add a set of
end_comment

begin_comment
comment|/// SCEV predicates to Predicates that are required to be true in order for
end_comment

begin_comment
comment|/// the answer to be correct. Predicates can be checked with run-time
end_comment

begin_comment
comment|/// checks and can be used to perform loop versioning.
end_comment

begin_function_decl
specifier|const
name|SCEV
modifier|*
name|getPredicatedBackedgeTakenCount
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|,
name|SCEVUnionPredicate
modifier|&
name|Predicates
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Similar to getBackedgeTakenCount, except return the least SCEV value
end_comment

begin_comment
comment|/// that is known never to be less than the actual backedge taken count.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// Return true if the specified loop has an analyzable loop-invariant
end_comment

begin_comment
comment|/// backedge-taken count.
end_comment

begin_function_decl
name|bool
name|hasLoopInvariantBackedgeTakenCount
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// This method should be called by the client when it has changed a loop in
end_comment

begin_comment
comment|/// a way that may effect ScalarEvolution's ability to compute a trip count,
end_comment

begin_comment
comment|/// or if the loop is deleted.  This call is potentially expensive for large
end_comment

begin_comment
comment|/// loop bodies.
end_comment

begin_function_decl
name|void
name|forgetLoop
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// This method should be called by the client when it has changed a value
end_comment

begin_comment
comment|/// in a way that may effect its value, or which may disconnect it from a
end_comment

begin_comment
comment|/// def-use chain linking it to a loop.
end_comment

begin_function_decl
name|void
name|forgetValue
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Called when the client has changed the disposition of values in
end_comment

begin_comment
comment|/// this loop.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// We don't have a way to invalidate per-loop dispositions. Clear and
end_comment

begin_comment
comment|/// recompute is simpler.
end_comment

begin_function
name|void
name|forgetLoopDispositions
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
block|{
name|LoopDispositions
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Determine the minimum number of zero bits that S is guaranteed to end in
end_comment

begin_comment
comment|/// (at every loop iteration).  It is, at the same time, the minimum number
end_comment

begin_comment
comment|/// of times S is divisible by 2.  For example, given {4,+,8} it returns 2.
end_comment

begin_comment
comment|/// If S is guaranteed to be 0, it returns the bitwidth of S.
end_comment

begin_function_decl
name|uint32_t
name|GetMinTrailingZeros
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Determine the unsigned range for a particular SCEV.
end_comment

begin_comment
comment|///
end_comment

begin_function
name|ConstantRange
name|getUnsignedRange
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
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
end_function

begin_comment
comment|/// Determine the signed range for a particular SCEV.
end_comment

begin_comment
comment|///
end_comment

begin_function
name|ConstantRange
name|getSignedRange
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
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
end_function

begin_comment
comment|/// Test if the given expression is known to be negative.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|bool
name|isKnownNegative
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Test if the given expression is known to be positive.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|bool
name|isKnownPositive
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Test if the given expression is known to be non-negative.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|bool
name|isKnownNonNegative
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Test if the given expression is known to be non-positive.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|bool
name|isKnownNonPositive
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Test if the given expression is known to be non-zero.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|bool
name|isKnownNonZero
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Test if the given expression is known to satisfy the condition described
end_comment

begin_comment
comment|/// by Pred, LHS, and RHS.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// Return true if the result of the predicate LHS `Pred` RHS is loop
end_comment

begin_comment
comment|/// invariant with respect to L.  Set InvariantPred, InvariantLHS and
end_comment

begin_comment
comment|/// InvariantLHS so that InvariantLHS `InvariantPred` InvariantRHS is the
end_comment

begin_comment
comment|/// loop invariant form of LHS `Pred` RHS.
end_comment

begin_decl_stmt
name|bool
name|isLoopInvariantPredicate
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
name|Loop
operator|*
name|L
argument_list|,
name|ICmpInst
operator|::
name|Predicate
operator|&
name|InvariantPred
argument_list|,
specifier|const
name|SCEV
operator|*
operator|&
name|InvariantLHS
argument_list|,
specifier|const
name|SCEV
operator|*
operator|&
name|InvariantRHS
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Simplify LHS and RHS in a comparison with predicate Pred. Return true
end_comment

begin_comment
comment|/// iff any changes were made. If the operands are provably equal or
end_comment

begin_comment
comment|/// unequal, LHS and RHS are set to the same value and Pred is set to either
end_comment

begin_comment
comment|/// ICMP_EQ or ICMP_NE.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
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
argument_list|,
name|unsigned
name|Depth
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return the "disposition" of the given SCEV with respect to the given
end_comment

begin_comment
comment|/// loop.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// Return true if the value of the given SCEV is unchanging in the
end_comment

begin_comment
comment|/// specified loop.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// Return true if the given SCEV changes value in a known way in the
end_comment

begin_comment
comment|/// specified loop.  This property being true implies that the value is
end_comment

begin_comment
comment|/// variant in the loop AND that we can emit an expression to compute the
end_comment

begin_comment
comment|/// value of the expression at any particular loop iteration.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// Return the "disposition" of the given SCEV with respect to the given
end_comment

begin_comment
comment|/// block.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// Return true if elements that makes up the given SCEV dominate the
end_comment

begin_comment
comment|/// specified basic block.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// Return true if elements that makes up the given SCEV properly dominate
end_comment

begin_comment
comment|/// the specified basic block.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// Test whether the given SCEV has Op as a direct or indirect operand.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// Return the size of an element read or written by Inst.
end_comment

begin_function_decl
specifier|const
name|SCEV
modifier|*
name|getElementSize
parameter_list|(
name|Instruction
modifier|*
name|Inst
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Compute the array dimensions Sizes from the set of Terms extracted from
end_comment

begin_comment
comment|/// the memory access function of this SCEVAddRecExpr (second step of
end_comment

begin_comment
comment|/// delinearization).
end_comment

begin_decl_stmt
name|void
name|findArrayDimensions
argument_list|(
name|SmallVectorImpl
operator|<
specifier|const
name|SCEV
operator|*
operator|>
operator|&
name|Terms
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
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|void
name|verify
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Collect parametric terms occurring in step expressions (first step of
end_comment

begin_comment
comment|/// delinearization).
end_comment

begin_decl_stmt
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
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return in Subscripts the access functions for each dimension in Sizes
end_comment

begin_comment
comment|/// (third step of delinearization).
end_comment

begin_decl_stmt
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
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Split this SCEVAddRecExpr into two vectors of SCEVs representing the
end_comment

begin_comment
comment|/// subscripts and sizes of an array access.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The delinearization is a 3 step process: the first two steps compute the
end_comment

begin_comment
comment|/// sizes of each subscript and the third step computes the access functions
end_comment

begin_comment
comment|/// for the delinearized array:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// 1. Find the terms in the step functions
end_comment

begin_comment
comment|/// 2. Compute the array size
end_comment

begin_comment
comment|/// 3. Compute the access function: divide the SCEV by the array size
end_comment

begin_comment
comment|///    starting with the innermost dimensions found in step 2. The Quotient
end_comment

begin_comment
comment|///    is the SCEV to be divided in the next step of the recursion. The
end_comment

begin_comment
comment|///    Remainder is the subscript of the innermost dimension. Loop over all
end_comment

begin_comment
comment|///    array dimensions computed in step 2.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// To compute a uniform array size for several memory accesses to the same
end_comment

begin_comment
comment|/// object, one can collect in step 1 all the step terms for all the memory
end_comment

begin_comment
comment|/// accesses, and compute in step 2 a unique array shape. This guarantees
end_comment

begin_comment
comment|/// that the array shape will be the same across all memory accesses.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// FIXME: We could derive the result of steps 1 and 2 from a description of
end_comment

begin_comment
comment|/// the array shape given in metadata.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Example:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A[][n][m]
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// for i
end_comment

begin_comment
comment|///   for j
end_comment

begin_comment
comment|///     for k
end_comment

begin_comment
comment|///       A[j+k][2i][5i] =
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The initial SCEV:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A[{{{0,+,2*m+5}_i, +, n*m}_j, +, n*m}_k]
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// 1. Find the different terms in the step functions:
end_comment

begin_comment
comment|/// -> [2*m, 5, n*m, n*m]
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// 2. Compute the array size: sort and unique them
end_comment

begin_comment
comment|/// -> [n*m, 2*m, 5]
end_comment

begin_comment
comment|/// find the GCD of all the terms = 1
end_comment

begin_comment
comment|/// divide by the GCD and erase constant terms
end_comment

begin_comment
comment|/// -> [n*m, 2*m]
end_comment

begin_comment
comment|/// GCD = m
end_comment

begin_comment
comment|/// divide by GCD -> [n, 2]
end_comment

begin_comment
comment|/// remove constant terms
end_comment

begin_comment
comment|/// -> [n]
end_comment

begin_comment
comment|/// size of the array is A[unknown][n][m]
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// 3. Compute the access function
end_comment

begin_comment
comment|/// a. Divide {{{0,+,2*m+5}_i, +, n*m}_j, +, n*m}_k by the innermost size m
end_comment

begin_comment
comment|/// Quotient: {{{0,+,2}_i, +, n}_j, +, n}_k
end_comment

begin_comment
comment|/// Remainder: {{{0,+,5}_i, +, 0}_j, +, 0}_k
end_comment

begin_comment
comment|/// The remainder is the subscript of the innermost array dimension: [5i].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// b. Divide Quotient: {{{0,+,2}_i, +, n}_j, +, n}_k by next outer size n
end_comment

begin_comment
comment|/// Quotient: {{{0,+,0}_i, +, 1}_j, +, 1}_k
end_comment

begin_comment
comment|/// Remainder: {{{0,+,2}_i, +, 0}_j, +, 0}_k
end_comment

begin_comment
comment|/// The Remainder is the subscript of the next array dimension: [2i].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The subscript of the outermost dimension is the Quotient: [j+k].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Overall, we have: A[][n][m], and the access function: A[j+k][2i][5i].
end_comment

begin_decl_stmt
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
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return the DataLayout associated with the module this SCEV instance is
end_comment

begin_comment
comment|/// operating on.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_function_decl
specifier|const
name|SCEVPredicate
modifier|*
name|getEqualPredicate
parameter_list|(
specifier|const
name|SCEVUnknown
modifier|*
name|LHS
parameter_list|,
specifier|const
name|SCEVConstant
modifier|*
name|RHS
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|const
name|SCEVPredicate
modifier|*
name|getWrapPredicate
argument_list|(
specifier|const
name|SCEVAddRecExpr
operator|*
name|AR
argument_list|,
name|SCEVWrapPredicate
operator|::
name|IncrementWrapFlags
name|AddedFlags
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Re-writes the SCEV according to the Predicates in \p A.
end_comment

begin_function_decl
specifier|const
name|SCEV
modifier|*
name|rewriteUsingPredicate
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
parameter_list|,
name|SCEVUnionPredicate
modifier|&
name|A
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Tries to convert the \p S expression to an AddRec expression,
end_comment

begin_comment
comment|/// adding additional predicates to \p Preds as required.
end_comment

begin_function_decl
specifier|const
name|SCEVAddRecExpr
modifier|*
name|convertSCEVToAddRecWithPredicates
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
parameter_list|,
name|SCEVUnionPredicate
modifier|&
name|Preds
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_comment
comment|/// Compute the backedge taken count knowing the interval difference, the
end_comment

begin_comment
comment|/// stride and presence of the equality in the comparison.
end_comment

begin_function_decl
specifier|const
name|SCEV
modifier|*
name|computeBECount
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|Delta
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|Stride
parameter_list|,
name|bool
name|Equality
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Verify if an linear IV with positive stride can overflow when in a
end_comment

begin_comment
comment|/// less-than comparison, knowing the invariant term of the comparison,
end_comment

begin_comment
comment|/// the stride and the knowledge of NSW/NUW flags on the recurrence.
end_comment

begin_function_decl
name|bool
name|doesIVOverflowOnLT
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|RHS
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|Stride
parameter_list|,
name|bool
name|IsSigned
parameter_list|,
name|bool
name|NoWrap
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Verify if an linear IV with negative stride can overflow when in a
end_comment

begin_comment
comment|/// greater-than comparison, knowing the invariant term of the comparison,
end_comment

begin_comment
comment|/// the stride and the knowledge of NSW/NUW flags on the recurrence.
end_comment

begin_function_decl
name|bool
name|doesIVOverflowOnGT
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|RHS
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|Stride
parameter_list|,
name|bool
name|IsSigned
parameter_list|,
name|bool
name|NoWrap
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|FoldingSet
operator|<
name|SCEV
operator|>
name|UniqueSCEVs
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|FoldingSet
operator|<
name|SCEVPredicate
operator|>
name|UniquePreds
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|BumpPtrAllocator
name|SCEVAllocator
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The head of a linked list of all SCEVUnknown values that have been
end_comment

begin_comment
comment|/// allocated. This is used by releaseMemory to locate them all and call
end_comment

begin_comment
comment|/// their destructors.
end_comment

begin_decl_stmt
name|SCEVUnknown
modifier|*
name|FirstUnknown
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// Analysis pass that exposes the \c ScalarEvolution for a function.
end_comment

begin_decl_stmt
name|class
name|ScalarEvolutionAnalysis
range|:
name|public
name|AnalysisInfoMixin
operator|<
name|ScalarEvolutionAnalysis
operator|>
block|{
name|friend
name|AnalysisInfoMixin
operator|<
name|ScalarEvolutionAnalysis
operator|>
block|;
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
operator|&
name|AM
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// Printer pass for the \c ScalarEvolutionAnalysis results.
end_comment

begin_decl_stmt
name|class
name|ScalarEvolutionPrinterPass
range|:
name|public
name|PassInfoMixin
operator|<
name|ScalarEvolutionPrinterPass
operator|>
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
operator|&
name|AM
argument_list|)
block|;   }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|ScalarEvolutionWrapperPass
range|:
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
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// An interface layer with SCEV used to manage how we see SCEV expressions
end_comment

begin_comment
comment|/// for values in the context of existing predicates. We can add new
end_comment

begin_comment
comment|/// predicates, but we cannot remove them.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This layer has multiple purposes:
end_comment

begin_comment
comment|///   - provides a simple interface for SCEV versioning.
end_comment

begin_comment
comment|///   - guarantees that the order of transformations applied on a SCEV
end_comment

begin_comment
comment|///     expression for a single Value is consistent across two different
end_comment

begin_comment
comment|///     getSCEV calls. This means that, for example, once we've obtained
end_comment

begin_comment
comment|///     an AddRec expression for a certain value through expression
end_comment

begin_comment
comment|///     rewriting, we will continue to get an AddRec expression for that
end_comment

begin_comment
comment|///     Value.
end_comment

begin_comment
comment|///   - lowers the number of expression rewrites.
end_comment

begin_decl_stmt
name|class
name|PredicatedScalarEvolution
block|{
name|public
label|:
name|PredicatedScalarEvolution
argument_list|(
name|ScalarEvolution
operator|&
name|SE
argument_list|,
name|Loop
operator|&
name|L
argument_list|)
expr_stmt|;
specifier|const
name|SCEVUnionPredicate
operator|&
name|getUnionPredicate
argument_list|()
specifier|const
expr_stmt|;
comment|/// Returns the SCEV expression of V, in the context of the current SCEV
comment|/// predicate.  The order of transformations applied on the expression of V
comment|/// returned by ScalarEvolution is guaranteed to be preserved, even when
comment|/// adding new predicates.
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
comment|/// Get the (predicated) backedge count for the analyzed loop.
specifier|const
name|SCEV
modifier|*
name|getBackedgeTakenCount
parameter_list|()
function_decl|;
comment|/// Adds a new predicate.
name|void
name|addPredicate
parameter_list|(
specifier|const
name|SCEVPredicate
modifier|&
name|Pred
parameter_list|)
function_decl|;
comment|/// Attempts to produce an AddRecExpr for V by adding additional SCEV
comment|/// predicates. If we can't transform the expression into an AddRecExpr we
comment|/// return nullptr and not add additional SCEV predicates to the current
comment|/// context.
specifier|const
name|SCEVAddRecExpr
modifier|*
name|getAsAddRec
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// Proves that V doesn't overflow by adding SCEV predicate.
name|void
name|setNoOverflow
argument_list|(
name|Value
operator|*
name|V
argument_list|,
name|SCEVWrapPredicate
operator|::
name|IncrementWrapFlags
name|Flags
argument_list|)
decl_stmt|;
comment|/// Returns true if we've proved that V doesn't wrap by means of a SCEV
comment|/// predicate.
name|bool
name|hasNoOverflow
argument_list|(
name|Value
operator|*
name|V
argument_list|,
name|SCEVWrapPredicate
operator|::
name|IncrementWrapFlags
name|Flags
argument_list|)
decl_stmt|;
comment|/// Returns the ScalarEvolution analysis used.
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
comment|/// We need to explicitly define the copy constructor because of FlagsMap.
name|PredicatedScalarEvolution
argument_list|(
specifier|const
name|PredicatedScalarEvolution
operator|&
argument_list|)
expr_stmt|;
comment|/// Print the SCEV mappings done by the Predicated Scalar Evolution.
comment|/// The printed text is indented by \p Depth.
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|unsigned
name|Depth
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
comment|/// Increments the version number of the predicate.  This needs to be called
comment|/// every time the SCEV predicate changes.
name|void
name|updateGeneration
parameter_list|()
function_decl|;
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
expr_stmt|;
comment|/// Records what NoWrap flags we've added to a Value *.
name|ValueMap
operator|<
name|Value
operator|*
operator|,
name|SCEVWrapPredicate
operator|::
name|IncrementWrapFlags
operator|>
name|FlagsMap
expr_stmt|;
comment|/// The ScalarEvolution analysis.
name|ScalarEvolution
modifier|&
name|SE
decl_stmt|;
comment|/// The analyzed Loop.
specifier|const
name|Loop
modifier|&
name|L
decl_stmt|;
comment|/// The SCEVPredicate that forms our context. We will rewrite all
comment|/// expressions assuming that this predicate true.
name|SCEVUnionPredicate
name|Preds
decl_stmt|;
comment|/// Marks the version of the SCEV predicate used. When rewriting a SCEV
comment|/// expression we mark it with the version of the predicate. We use this to
comment|/// figure out if the predicate has changed from the last rewrite of the
comment|/// SCEV. If so, we need to perform a new rewrite.
name|unsigned
name|Generation
decl_stmt|;
comment|/// The backedge taken count.
specifier|const
name|SCEV
modifier|*
name|BackedgeCount
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

