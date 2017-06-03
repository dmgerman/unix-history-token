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
block|; }
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
argument|FoldingSetNodeID&ID
argument_list|)
block|{
name|ID
operator|=
name|X
operator|.
name|FastID
block|; }
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
block|; }
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
block|; }
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
block|;   }
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
name|LLVM_NODISCARD
specifier|static
name|SCEVWrapPredicate
operator|::
name|IncrementWrapFlags
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
name|LLVM_NODISCARD
specifier|static
name|SCEVWrapPredicate
operator|::
name|IncrementWrapFlags
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
name|LLVM_NODISCARD
specifier|static
name|SCEVWrapPredicate
operator|::
name|IncrementWrapFlags
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
name|LLVM_NODISCARD
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
comment|///
comment|/// NB! Unlike other SCEVPredicate sub-classes this class does not live in the
comment|/// ScalarEvolution::Preds folding set.  This is why the \c add function is sound.
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
name|LLVM_NODISCARD
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
name|LLVM_NODISCARD
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
name|LLVM_NODISCARD
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
block|;   }
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
operator|>>
name|ValueExprMapType
expr_stmt|;
comment|/// This is a cache of the values we have analyzed so far.
comment|///
name|ValueExprMapType
name|ValueExprMap
block|;
comment|/// Mark predicate values currently being processed by isImpliedCond.
name|SmallPtrSet
operator|<
name|Value
operator|*
block|,
literal|6
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
comment|/// Memoized values for the GetMinTrailingZeros
name|DenseMap
operator|<
specifier|const
name|SCEV
operator|*
block|,
name|uint32_t
operator|>
name|MinTrailingZerosCache
block|;
comment|/// Private helper method for the GetMinTrailingZeros method
name|uint32_t
name|GetMinTrailingZerosImpl
argument_list|(
specifier|const
name|SCEV
operator|*
name|S
argument_list|)
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
name|ExactNotTaken
block|;
comment|// The exit is not taken exactly this many times
specifier|const
name|SCEV
operator|*
name|MaxNotTaken
block|;
comment|// The exit is not taken at most this many times
name|bool
name|MaxOrZero
block|;
comment|// Not taken either exactly MaxNotTaken or zero times
comment|/// A set of predicate guards for this ExitLimit. The result is only valid
comment|/// if all of the predicates in \c Predicates evaluate to 'true' at
comment|/// run-time.
name|SmallPtrSet
operator|<
specifier|const
name|SCEVPredicate
operator|*
block|,
literal|4
operator|>
name|Predicates
block|;
name|void
name|addPredicate
argument_list|(
argument|const SCEVPredicate *P
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|isa
operator|<
name|SCEVUnionPredicate
operator|>
operator|(
name|P
operator|)
operator|&&
literal|"Only add leaf predicates here!"
argument_list|)
block|;
name|Predicates
operator|.
name|insert
argument_list|(
name|P
argument_list|)
block|;     }
comment|/*implicit*/
name|ExitLimit
argument_list|(
specifier|const
name|SCEV
operator|*
name|E
argument_list|)
block|;
name|ExitLimit
argument_list|(
argument|const SCEV *E
argument_list|,
argument|const SCEV *M
argument_list|,
argument|bool MaxOrZero
argument_list|,
argument|ArrayRef<const SmallPtrSetImpl<const SCEVPredicate *> *> PredSetList
argument_list|)
block|;
name|ExitLimit
argument_list|(
argument|const SCEV *E
argument_list|,
argument|const SCEV *M
argument_list|,
argument|bool MaxOrZero
argument_list|,
argument|const SmallPtrSetImpl<const SCEVPredicate *>&PredSet
argument_list|)
block|;
name|ExitLimit
argument_list|(
argument|const SCEV *E
argument_list|,
argument|const SCEV *M
argument_list|,
argument|bool MaxOrZero
argument_list|)
block|;
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
name|ExactNotTaken
operator|)
operator|||
operator|!
name|isa
operator|<
name|SCEVCouldNotCompute
operator|>
operator|(
name|MaxNotTaken
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
name|ExactNotTaken
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
name|PoisoningVH
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
name|std
operator|::
name|unique_ptr
operator|<
name|SCEVUnionPredicate
operator|>
name|Predicate
block|;
name|bool
name|hasAlwaysTruePredicate
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Predicate
operator|||
name|Predicate
operator|->
name|isAlwaysTrue
argument_list|()
return|;
block|}
name|explicit
name|ExitNotTakenInfo
argument_list|(
name|PoisoningVH
operator|<
name|BasicBlock
operator|>
name|ExitingBlock
argument_list|,
specifier|const
name|SCEV
operator|*
name|ExactNotTaken
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|SCEVUnionPredicate
operator|>
name|Predicate
argument_list|)
operator|:
name|ExitingBlock
argument_list|(
name|ExitingBlock
argument_list|)
block|,
name|ExactNotTaken
argument_list|(
name|ExactNotTaken
argument_list|)
block|,
name|Predicate
argument_list|(
argument|std::move(Predicate)
argument_list|)
block|{}
block|}
block|;
comment|/// Information about the backedge-taken count of a loop. This currently
comment|/// includes an exact count and a maximum count.
comment|///
name|class
name|BackedgeTakenInfo
block|{
comment|/// A list of computable exits and their not-taken counts.  Loops almost
comment|/// never have more than one computable exit.
name|SmallVector
operator|<
name|ExitNotTakenInfo
block|,
literal|1
operator|>
name|ExitNotTaken
block|;
comment|/// The pointer part of \c MaxAndComplete is an expression indicating the
comment|/// least maximum backedge-taken count of the loop that is known, or a
comment|/// SCEVCouldNotCompute. This expression is only valid if the predicates
comment|/// associated with all loop exits are true.
comment|///
comment|/// The integer part of \c MaxAndComplete is a boolean indicating if \c
comment|/// ExitNotTaken has an element for every exiting block in the loop.
name|PointerIntPair
operator|<
specifier|const
name|SCEV
operator|*
block|,
literal|1
operator|>
name|MaxAndComplete
block|;
comment|/// True iff the backedge is taken either exactly Max or zero times.
name|bool
name|MaxOrZero
block|;
comment|/// \name Helper projection functions on \c MaxAndComplete.
comment|/// @{
name|bool
name|isComplete
argument_list|()
specifier|const
block|{
return|return
name|MaxAndComplete
operator|.
name|getInt
argument_list|()
return|;
block|}
specifier|const
name|SCEV
operator|*
name|getMax
argument_list|()
specifier|const
block|{
return|return
name|MaxAndComplete
operator|.
name|getPointer
argument_list|()
return|;
block|}
comment|/// @}
name|public
operator|:
name|BackedgeTakenInfo
argument_list|()
operator|:
name|MaxAndComplete
argument_list|(
name|nullptr
argument_list|,
literal|0
argument_list|)
block|,
name|MaxOrZero
argument_list|(
argument|false
argument_list|)
block|{}
name|BackedgeTakenInfo
argument_list|(
name|BackedgeTakenInfo
operator|&&
argument_list|)
operator|=
expr|default
block|;
name|BackedgeTakenInfo
operator|&
name|operator
operator|=
operator|(
name|BackedgeTakenInfo
operator|&&
operator|)
operator|=
expr|default
block|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|BasicBlock
operator|*
operator|,
name|ExitLimit
operator|>
name|EdgeExitInfo
expr_stmt|;
comment|/// Initialize BackedgeTakenInfo from a list of exact exit counts.
name|BackedgeTakenInfo
argument_list|(
argument|SmallVectorImpl<EdgeExitInfo>&&ExitCounts
argument_list|,
argument|bool Complete
argument_list|,
argument|const SCEV *MaxCount
argument_list|,
argument|bool MaxOrZero
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
operator|!
name|ExitNotTaken
operator|.
name|empty
argument_list|()
operator|||
operator|!
name|isa
operator|<
name|SCEVCouldNotCompute
operator|>
operator|(
name|getMax
argument_list|()
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
name|isComplete
argument_list|()
return|;
block|}
comment|/// Return an expression indicating the exact *backedge-taken*
comment|/// count of the loop if it is known or SCEVCouldNotCompute
comment|/// otherwise.  If execution makes it to the backedge on every
comment|/// iteration (i.e. there are no abnormal exists like exception
comment|/// throws and thread exits) then this is the number of times the
comment|/// loop header will execute minus one.
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
operator|*
name|getExact
argument_list|(
argument|ScalarEvolution *SE
argument_list|,
argument|SCEVUnionPredicate *Predicates = nullptr
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
comment|/// Return true if the number of times this backedge is taken is either the
comment|/// value returned by getMax or zero.
name|bool
name|isMaxOrZero
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
block|;   }
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
comment|/// Cache the predicated backedge-taken count of the loops for this
comment|/// function as they are computed.
name|DenseMap
operator|<
specifier|const
name|Loop
operator|*
block|,
name|BackedgeTakenInfo
operator|>
name|PredicatedBackedgeTakenCounts
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
operator|>>
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
block|;    struct
name|LoopProperties
block|{
comment|/// Set to true if the loop contains no instruction that can have side
comment|/// effects (i.e. via throwing an exception, volatile or atomic access).
name|bool
name|HasNoAbnormalExits
block|;
comment|/// Set to true if the loop contains no instruction that can abnormally exit
comment|/// the loop (i.e. via throwing an exception, by terminating the thread
comment|/// cleanly or by infinite looping in a called function).  Strictly
comment|/// speaking, the last one is not leaving the loop, but is identical to
comment|/// leaving the loop for reasoning about undefined behavior.
name|bool
name|HasNoSideEffects
block|;   }
block|;
comment|/// Cache for \c getLoopProperties.
name|DenseMap
operator|<
specifier|const
name|Loop
operator|*
block|,
name|LoopProperties
operator|>
name|LoopPropertiesCache
block|;
comment|/// Return a \c LoopProperties instance for \p L, creating one if necessary.
name|LoopProperties
name|getLoopProperties
argument_list|(
specifier|const
name|Loop
operator|*
name|L
argument_list|)
block|;
name|bool
name|loopHasNoSideEffects
argument_list|(
argument|const Loop *L
argument_list|)
block|{
return|return
name|getLoopProperties
argument_list|(
name|L
argument_list|)
operator|.
name|HasNoSideEffects
return|;
block|}
name|bool
name|loopHasNoAbnormalExits
argument_list|(
argument|const Loop *L
argument_list|)
block|{
return|return
name|getLoopProperties
argument_list|(
name|L
argument_list|)
operator|.
name|HasNoAbnormalExits
return|;
block|}
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
argument|ConstantRange CR
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
name|auto
name|Pair
operator|=
name|Cache
operator|.
name|try_emplace
argument_list|(
name|S
argument_list|,
name|std
operator|::
name|move
argument_list|(
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
name|std
operator|::
name|move
argument_list|(
name|CR
argument_list|)
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
comment|/// Determines the range for the affine SCEVAddRecExpr {\p Start,+,\p Stop}.
comment|/// Helper for \c getRange.
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
comment|/// Try to compute a range for the affine SCEVAddRecExpr {\p Start,+,\p
comment|/// Stop} by "factoring out" a ternary expression from the add recurrence.
comment|/// Helper called by \c getRange.
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
comment|/// We know that there is no SCEV for the specified value.  Analyze the
comment|/// expression.
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
comment|/// Provide the special handling we need to analyze PHI SCEVs.
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
comment|/// Helper function called from createNodeForPHI.
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
comment|/// A helper function for createAddRecFromPHI to handle simple cases.
specifier|const
name|SCEV
modifier|*
name|createSimpleAffineAddRec
parameter_list|(
name|PHINode
modifier|*
name|PN
parameter_list|,
name|Value
modifier|*
name|BEValueV
parameter_list|,
name|Value
modifier|*
name|StartValueV
parameter_list|)
function_decl|;
comment|/// Helper function called from createNodeForPHI.
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
comment|/// Provide special handling for a select-like instruction (currently this
comment|/// is either a select instruction or a phi node).  \p I is the instruction
comment|/// being processed, and it is assumed equivalent to "Cond ? TrueVal :
comment|/// FalseVal".
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
comment|/// Provide the special handling we need to analyze GEP SCEVs.
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
comment|/// Implementation code for getSCEVAtScope; called at most once for each
comment|/// SCEV+Loop pair.
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
comment|/// This looks up computed SCEV values for all instructions that depend on
comment|/// the given instruction and removes them from the ValueExprMap map if they
comment|/// reference SymName. This is used during PHI resolution.
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
comment|/// Return the BackedgeTakenInfo for the given loop, lazily computing new
comment|/// values if the loop hasn't been analyzed yet. The returned result is
comment|/// guaranteed not to be predicated.
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
comment|/// Similar to getBackedgeTakenInfo, but will add predicates as required
comment|/// with the purpose of returning complete information.
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
comment|/// Compute the number of times the specified loop will iterate.
comment|/// If AllowPredicates is set, we will create new SCEV predicates as
comment|/// necessary in order to return an exact answer.
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
comment|/// Compute the number of times the backedge of the specified loop will
comment|/// execute if it exits via the specified block. If AllowPredicates is set,
comment|/// this call will try to use a minimal set of SCEV predicates in order to
comment|/// return an exact answer.
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
comment|/// Compute the number of times the backedge of the specified loop will
comment|/// execute if its exit condition were a conditional branch of ExitCond,
comment|/// TBB, and FBB.
comment|///
comment|/// \p ControlsExit is true if ExitCond directly controls the exit
comment|/// branch. In this case, we can assume that the loop exits only if the
comment|/// condition is true and can infer that failing to meet the condition prior
comment|/// to integer wraparound results in undefined behavior.
comment|///
comment|/// If \p AllowPredicates is set, this call will try to use a minimal set of
comment|/// SCEV predicates in order to return an exact answer.
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
comment|// Helper functions for computeExitLimitFromCond to avoid exponential time
comment|// complexity.
name|class
name|ExitLimitCache
block|{
comment|// It may look like we need key on the whole (L, TBB, FBB, ControlsExit,
comment|// AllowPredicates) tuple, but recursive calls to
comment|// computeExitLimitFromCondCached from computeExitLimitFromCondImpl only
comment|// vary the in \c ExitCond and \c ControlsExit parameters.  We remember the
comment|// initial values of the other values to assert our assumption.
name|SmallDenseMap
operator|<
name|PointerIntPair
operator|<
name|Value
operator|*
operator|,
literal|1
operator|>
operator|,
name|ExitLimit
operator|>
name|TripCountMap
expr_stmt|;
specifier|const
name|Loop
modifier|*
name|L
decl_stmt|;
name|BasicBlock
modifier|*
name|TBB
decl_stmt|;
name|BasicBlock
modifier|*
name|FBB
decl_stmt|;
name|bool
name|AllowPredicates
decl_stmt|;
name|public
label|:
name|ExitLimitCache
argument_list|(
argument|const Loop *L
argument_list|,
argument|BasicBlock *TBB
argument_list|,
argument|BasicBlock *FBB
argument_list|,
argument|bool AllowPredicates
argument_list|)
block|:
name|L
argument_list|(
name|L
argument_list|)
operator|,
name|TBB
argument_list|(
name|TBB
argument_list|)
operator|,
name|FBB
argument_list|(
name|FBB
argument_list|)
operator|,
name|AllowPredicates
argument_list|(
argument|AllowPredicates
argument_list|)
block|{}
name|Optional
operator|<
name|ExitLimit
operator|>
name|find
argument_list|(
argument|const Loop *L
argument_list|,
argument|Value *ExitCond
argument_list|,
argument|BasicBlock *TBB
argument_list|,
argument|BasicBlock *FBB
argument_list|,
argument|bool ControlsExit
argument_list|,
argument|bool AllowPredicates
argument_list|)
expr_stmt|;
name|void
name|insert
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
parameter_list|,
specifier|const
name|ExitLimit
modifier|&
name|EL
parameter_list|)
function_decl|;
block|}
empty_stmt|;
typedef|typedef
name|ExitLimitCache
name|ExitLimitCacheTy
typedef|;
name|ExitLimit
name|computeExitLimitFromCondCached
parameter_list|(
name|ExitLimitCacheTy
modifier|&
name|Cache
parameter_list|,
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
parameter_list|)
function_decl|;
name|ExitLimit
name|computeExitLimitFromCondImpl
parameter_list|(
name|ExitLimitCacheTy
modifier|&
name|Cache
parameter_list|,
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
parameter_list|)
function_decl|;
comment|/// Compute the number of times the backedge of the specified loop will
comment|/// execute if its exit condition were a conditional branch of the ICmpInst
comment|/// ExitCond, TBB, and FBB. If AllowPredicates is set, this call will try
comment|/// to use a minimal set of SCEV predicates in order to return an exact
comment|/// answer.
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
comment|/// Compute the number of times the backedge of the specified loop will
comment|/// execute if its exit condition were a switch with a single exiting case
comment|/// to ExitingBB.
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
comment|/// Given an exit condition of 'icmp op load X, cst', try to see if we can
comment|/// compute the backedge-taken count.
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
comment|/// If the loop is known to execute a constant number of times (the
comment|/// condition evolves only from constants), try to evaluate a few iterations
comment|/// of the loop until we get the exit condition gets a value of ExitWhen
comment|/// (true or false).  If we cannot evaluate the exit count of the loop,
comment|/// return CouldNotCompute.
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
comment|/// Return the number of times an exit condition comparing the specified
comment|/// value to zero will execute.  If not computable, return CouldNotCompute.
comment|/// If AllowPredicates is set, this call will try to use a minimal set of
comment|/// SCEV predicates in order to return an exact answer.
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
comment|/// Return the number of times an exit condition checking the specified
comment|/// value for nonzero will execute.  If not computable, return
comment|/// CouldNotCompute.
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
comment|/// Return the number of times an exit condition containing the specified
comment|/// less-than comparison will execute.  If not computable, return
comment|/// CouldNotCompute.
comment|///
comment|/// \p isSigned specifies whether the less-than is signed.
comment|///
comment|/// \p ControlsExit is true when the LHS< RHS condition directly controls
comment|/// the branch (loops exits only if condition is true). In this case, we can
comment|/// use NoWrapFlags to skip overflow checks.
comment|///
comment|/// If \p AllowPredicates is set, this call will try to use a minimal set of
comment|/// SCEV predicates in order to return an exact answer.
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
comment|/// Return a predecessor of BB (which may not be an immediate predecessor)
comment|/// which has exactly one successor from which BB is reachable, or null if
comment|/// no such block is found.
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
comment|/// Test whether the condition described by Pred, LHS, and RHS is true
comment|/// whenever the given FoundCondValue value evaluates to true.
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
comment|/// Test whether the condition described by Pred, LHS, and RHS is true
comment|/// whenever the condition described by FoundPred, FoundLHS, FoundRHS is
comment|/// true.
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
comment|/// Test whether the condition described by Pred, LHS, and RHS is true
comment|/// whenever the condition described by Pred, FoundLHS, and FoundRHS is
comment|/// true.
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
comment|/// Test whether the condition described by Pred, LHS, and RHS is true
comment|/// whenever the condition described by Pred, FoundLHS, and FoundRHS is
comment|/// true. Here LHS is an operation that includes FoundLHS as one of its
comment|/// arguments.
name|bool
name|isImpliedViaOperations
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
argument_list|,
name|unsigned
name|Depth
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// Test whether the condition described by Pred, LHS, and RHS is true.
comment|/// Use only simple non-recursive types of checks, such as range analysis etc.
name|bool
name|isKnownViaSimpleReasoning
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
comment|/// Test whether the condition described by Pred, LHS, and RHS is true
comment|/// whenever the condition described by Pred, FoundLHS, and FoundRHS is
comment|/// true.
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
comment|/// Test whether the condition described by Pred, LHS, and RHS is true
comment|/// whenever the condition described by Pred, FoundLHS, and FoundRHS is
comment|/// true.  Utility function used by isImpliedCondOperands.  Tries to get
comment|/// cases like "X `sgt` 0 => X - 1 `sgt` -1".
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
comment|/// Return true if the condition denoted by \p LHS \p Pred \p RHS is implied
comment|/// by a call to \c @llvm.experimental.guard in \p BB.
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
comment|/// Test whether the condition described by Pred, LHS, and RHS is true
comment|/// whenever the condition described by Pred, FoundLHS, and FoundRHS is
comment|/// true.
comment|///
comment|/// This routine tries to rule out certain kinds of integer overflow, and
comment|/// then tries to reason about arithmetic properties of the predicates.
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
comment|/// If we know that the specified Phi is in the header of its containing
comment|/// loop, we know the loop executes a constant number of times, and the PHI
comment|/// node is just a recurrence involving constants, fold it.
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
comment|/// Test if the given expression is known to satisfy the condition described
comment|/// by Pred and the known constant ranges of LHS and RHS.
comment|///
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
comment|/// Try to prove the condition described by "LHS Pred RHS" by ruling out
comment|/// integer overflow.
comment|///
comment|/// For instance, this will return true for "A s< (A + C)<nsw>" if C is
comment|/// positive.
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
comment|/// Try to split Pred LHS RHS into logical conjunctions (and's) and try to
comment|/// prove them individually.
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
decl_stmt|;
comment|/// Compute \p LHS - \p RHS and returns the result as an APInt if it is a
comment|/// constant, and None if it isn't.
comment|///
comment|/// This is intended to be a cheaper version of getMinusSCEV.  We can be
comment|/// frugal here since we just bail out of actually constructing and
comment|/// canonicalizing an expression in the cases where the result isn't going
comment|/// to be a constant.
name|Optional
operator|<
name|APInt
operator|>
name|computeConstantDifference
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
expr_stmt|;
comment|/// Drop memoized information computed for S.
name|void
name|forgetMemoizedResults
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
function_decl|;
comment|/// Return an existing SCEV for V if there is one, otherwise return nullptr.
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
comment|/// Return false iff given SCEV contains a SCEVUnknown with NULL value-
comment|/// pointer.
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
expr_stmt|;
comment|/// Try to prove NSW or NUW on \p AR relying on ConstantRange manipulation.
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
comment|/// Return SCEV no-wrap flags that can be proven based on reasoning about
comment|/// how poison produced from no-wrap flags on this value (e.g. a nuw add)
comment|/// would trigger undefined behavior on overflow.
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
comment|/// Return true if the SCEV corresponding to \p I is never poison.  Proving
comment|/// this is more complex than proving that just \p I is never poison, since
comment|/// SCEV commons expressions across control flow, and you can have cases
comment|/// like:
comment|///
comment|///   idx0 = a + b;
comment|///   ptr[idx0] = 100;
comment|///   if (<condition>) {
comment|///     idx1 = a +nsw b;
comment|///     ptr[idx1] = 200;
comment|///   }
comment|///
comment|/// where the SCEV expression (+ a b) is guaranteed to not be poison (and
comment|/// hence not sign-overflow) only if "<condition>" is true.  Since both
comment|/// `idx0` and `idx1` will be mapped to the same SCEV expression, (+ a b),
comment|/// it is not okay to annotate (+ a b) with<nsw> in the above example.
name|bool
name|isSCEVExprNeverPoison
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|)
function_decl|;
comment|/// This is like \c isSCEVExprNeverPoison but it specifically works for
comment|/// instructions that will get mapped to SCEV add recurrences.  Return true
comment|/// if \p I will never generate poison under the assumption that \p I is an
comment|/// add recurrence on the loop \p L.
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
name|public
label|:
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
operator|~
name|ScalarEvolution
argument_list|()
expr_stmt|;
name|ScalarEvolution
argument_list|(
name|ScalarEvolution
operator|&&
name|Arg
argument_list|)
expr_stmt|;
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
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the size in bits of the specified type, for which isSCEVable must
comment|/// return true.
name|uint64_t
name|getTypeSizeInBits
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// Return a type with the same bitwidth as the given type and which
comment|/// represents how SCEV will treat the given type, for which isSCEVable must
comment|/// return true. For pointer types, this is the pointer-sized integer type.
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
comment|// Returns a wider type among {Ty1, Ty2}.
name|Type
modifier|*
name|getWiderType
argument_list|(
name|Type
operator|*
name|Ty1
argument_list|,
name|Type
operator|*
name|Ty2
argument_list|)
decl|const
decl_stmt|;
comment|/// Return true if the SCEV is a scAddRecExpr or it contains
comment|/// scAddRecExpr. The result will be cached in HasRecMap.
comment|///
name|bool
name|containsAddRecurrence
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
function_decl|;
comment|/// Return the Value set from which the SCEV expr is generated.
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
comment|/// Erase Value from ValueExprMap and ExprValueMap.
name|void
name|eraseValueFromMap
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// Return a SCEV expression for the full generality of the specified
comment|/// expression.
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
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
typedef|typedef
name|SmallDenseMap
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|SCEV
operator|*
operator|,
name|Type
operator|*
operator|>
operator|,
specifier|const
name|SCEV
operator|*
operator|,
literal|8
operator|>
name|ExtendCacheTy
expr_stmt|;
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
specifier|const
name|SCEV
modifier|*
name|getZeroExtendExprCached
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|Op
parameter_list|,
name|Type
modifier|*
name|Ty
parameter_list|,
name|ExtendCacheTy
modifier|&
name|Cache
parameter_list|)
function_decl|;
specifier|const
name|SCEV
modifier|*
name|getZeroExtendExprImpl
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|Op
parameter_list|,
name|Type
modifier|*
name|Ty
parameter_list|,
name|ExtendCacheTy
modifier|&
name|Cache
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
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
specifier|const
name|SCEV
modifier|*
name|getSignExtendExprCached
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|Op
parameter_list|,
name|Type
modifier|*
name|Ty
parameter_list|,
name|ExtendCacheTy
modifier|&
name|Cache
parameter_list|)
function_decl|;
specifier|const
name|SCEV
modifier|*
name|getSignExtendExprImpl
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|Op
parameter_list|,
name|Type
modifier|*
name|Ty
parameter_list|,
name|ExtendCacheTy
modifier|&
name|Cache
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
argument_list|,
name|unsigned
name|Depth
operator|=
literal|0
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
comment|/// Returns an expression for a GEP
comment|///
comment|/// \p GEP The GEP. The indices contained in the GEP itself are ignored,
comment|/// instead we use IndexExprs.
comment|/// \p IndexExprs The expressions for the indices.
specifier|const
name|SCEV
modifier|*
name|getGEPExpr
argument_list|(
name|GEPOperator
operator|*
name|GEP
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
argument_list|)
decl_stmt|;
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
comment|/// Return a SCEV for the constant 0 of a specific type.
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
comment|/// Return a SCEV for the constant 1 of a specific type.
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
comment|/// Return an expression for sizeof AllocTy that is type IntTy
comment|///
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
comment|/// Return an expression for offsetof on the given field with type IntTy
comment|///
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
comment|/// Return the SCEV object corresponding to -V.
comment|///
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
comment|/// Return the SCEV object corresponding to ~V.
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
comment|/// Return LHS-RHS.  Minus is represented in SCEV as A+B*-1.
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
comment|/// Return a SCEV corresponding to a conversion of the input value to the
comment|/// specified type.  If the type must be extended, it is zero extended.
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
comment|/// Return a SCEV corresponding to a conversion of the input value to the
comment|/// specified type.  If the type must be extended, it is sign extended.
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
comment|/// Return a SCEV corresponding to a conversion of the input value to the
comment|/// specified type.  If the type must be extended, it is zero extended.  The
comment|/// conversion must not be narrowing.
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
comment|/// Return a SCEV corresponding to a conversion of the input value to the
comment|/// specified type.  If the type must be extended, it is sign extended.  The
comment|/// conversion must not be narrowing.
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
comment|/// Return a SCEV corresponding to a conversion of the input value to the
comment|/// specified type. If the type must be extended, it is extended with
comment|/// unspecified bits. The conversion must not be narrowing.
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
comment|/// Return a SCEV corresponding to a conversion of the input value to the
comment|/// specified type.  The conversion must not be widening.
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
comment|/// Promote the operands to the wider of the types using zero-extension, and
comment|/// then perform a umax operation with them.
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
comment|/// Promote the operands to the wider of the types using zero-extension, and
comment|/// then perform a umin operation with them.
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
comment|/// Transitively follow the chain of pointer-type operands until reaching a
comment|/// SCEV that does not have a single pointer operand. This returns a
comment|/// SCEVUnknown pointer for well-formed pointer-type expressions, but corner
comment|/// cases do exist.
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
comment|/// This is a convenience function which does getSCEVAtScope(getSCEV(V), L).
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
comment|/// Test whether entry to the loop is protected by a conditional between LHS
comment|/// and RHS.  This is used to help avoid max expressions in loop trip
comment|/// counts, and to eliminate casts.
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
comment|/// Test whether the backedge of the loop is protected by a conditional
comment|/// between LHS and RHS.  This is used to to eliminate casts.
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
comment|/// Returns the maximum trip count of the loop if it is a single-exit
comment|/// loop and we can compute a small maximum for that loop.
comment|///
comment|/// Implemented in terms of the \c getSmallConstantTripCount overload with
comment|/// the single exiting block passed to it. See that routine for details.
name|unsigned
name|getSmallConstantTripCount
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// Returns the maximum trip count of this loop as a normal unsigned
comment|/// value. Returns 0 if the trip count is unknown or not constant. This
comment|/// "trip count" assumes that control exits via ExitingBlock. More
comment|/// precisely, it is the number of times that control may reach ExitingBlock
comment|/// before taking the branch. For loops with multiple exits, it may not be
comment|/// the number times that the loop header executes if the loop exits
comment|/// prematurely via another branch.
name|unsigned
name|getSmallConstantTripCount
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
comment|/// Returns the upper bound of the loop trip count as a normal unsigned
comment|/// value.
comment|/// Returns 0 if the trip count is unknown or not constant.
name|unsigned
name|getSmallConstantMaxTripCount
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// Returns the largest constant divisor of the trip count of the
comment|/// loop if it is a single-exit loop and we can compute a small maximum for
comment|/// that loop.
comment|///
comment|/// Implemented in terms of the \c getSmallConstantTripMultiple overload with
comment|/// the single exiting block passed to it. See that routine for details.
name|unsigned
name|getSmallConstantTripMultiple
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// Returns the largest constant divisor of the trip count of this loop as a
comment|/// normal unsigned value, if possible. This means that the actual trip
comment|/// count is always a multiple of the returned value (don't forget the trip
comment|/// count could very well be zero as well!). As explained in the comments
comment|/// for getSmallConstantTripCount, this assumes that control exits the loop
comment|/// via ExitingBlock.
name|unsigned
name|getSmallConstantTripMultiple
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
comment|/// Get the expression for the number of loop iterations for which this loop
comment|/// is guaranteed not to exit via ExitingBlock. Otherwise return
comment|/// SCEVCouldNotCompute.
specifier|const
name|SCEV
modifier|*
name|getExitCount
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
comment|/// If the specified loop has a predictable backedge-taken count, return it,
comment|/// otherwise return a SCEVCouldNotCompute object. The backedge-taken count is
comment|/// the number of times the loop header will be branched to from within the
comment|/// loop, assuming there are no abnormal exists like exception throws. This is
comment|/// one less than the trip count of the loop, since it doesn't count the first
comment|/// iteration, when the header is branched to from outside the loop.
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
comment|/// Similar to getBackedgeTakenCount, except it will add a set of
comment|/// SCEV predicates to Predicates that are required to be true in order for
comment|/// the answer to be correct. Predicates can be checked with run-time
comment|/// checks and can be used to perform loop versioning.
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
comment|/// When successful, this returns a SCEVConstant that is greater than or equal
comment|/// to (i.e. a "conservative over-approximation") of the value returend by
comment|/// getBackedgeTakenCount.  If such a value cannot be computed, it returns the
comment|/// SCEVCouldNotCompute object.
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
comment|/// Return true if the backedge taken count is either the value returned by
comment|/// getMaxBackedgeTakenCount or zero.
name|bool
name|isBackedgeTakenCountMaxOrZero
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// Return true if the specified loop has an analyzable loop-invariant
comment|/// backedge-taken count.
name|bool
name|hasLoopInvariantBackedgeTakenCount
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// This method should be called by the client when it has changed a loop in
comment|/// a way that may effect ScalarEvolution's ability to compute a trip count,
comment|/// or if the loop is deleted.  This call is potentially expensive for large
comment|/// loop bodies.
name|void
name|forgetLoop
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// This method should be called by the client when it has changed a value
comment|/// in a way that may effect its value, or which may disconnect it from a
comment|/// def-use chain linking it to a loop.
name|void
name|forgetValue
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// Called when the client has changed the disposition of values in
comment|/// this loop.
comment|///
comment|/// We don't have a way to invalidate per-loop dispositions. Clear and
comment|/// recompute is simpler.
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
comment|/// Determine the minimum number of zero bits that S is guaranteed to end in
comment|/// (at every loop iteration).  It is, at the same time, the minimum number
comment|/// of times S is divisible by 2.  For example, given {4,+,8} it returns 2.
comment|/// If S is guaranteed to be 0, it returns the bitwidth of S.
name|uint32_t
name|GetMinTrailingZeros
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
function_decl|;
comment|/// Determine the unsigned range for a particular SCEV.
comment|///
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
comment|/// Determine the signed range for a particular SCEV.
comment|///
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
comment|/// Test if the given expression is known to be negative.
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
comment|/// Test if the given expression is known to be positive.
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
comment|/// Test if the given expression is known to be non-negative.
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
comment|/// Test if the given expression is known to be non-positive.
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
comment|/// Test if the given expression is known to be non-zero.
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
comment|/// Test if the given expression is known to satisfy the condition described
comment|/// by Pred, LHS, and RHS.
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
comment|/// Return true if the result of the predicate LHS `Pred` RHS is loop
comment|/// invariant with respect to L.  Set InvariantPred, InvariantLHS and
comment|/// InvariantLHS so that InvariantLHS `InvariantPred` InvariantRHS is the
comment|/// loop invariant form of LHS `Pred` RHS.
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
comment|/// Simplify LHS and RHS in a comparison with predicate Pred. Return true
comment|/// iff any changes were made. If the operands are provably equal or
comment|/// unequal, LHS and RHS are set to the same value and Pred is set to either
comment|/// ICMP_EQ or ICMP_NE.
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
argument_list|,
name|unsigned
name|Depth
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// Return the "disposition" of the given SCEV with respect to the given
comment|/// loop.
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
comment|/// Return true if the value of the given SCEV is unchanging in the
comment|/// specified loop.
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
comment|/// Determine if the SCEV can be evaluated at loop's entry. It is true if it
comment|/// doesn't depend on a SCEVUnknown of an instruction which is dominated by
comment|/// the header of loop L.
name|bool
name|isAvailableAtLoopEntry
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
comment|/// Return true if the given SCEV changes value in a known way in the
comment|/// specified loop.  This property being true implies that the value is
comment|/// variant in the loop AND that we can emit an expression to compute the
comment|/// value of the expression at any particular loop iteration.
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
comment|/// Return the "disposition" of the given SCEV with respect to the given
comment|/// block.
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
comment|/// Return true if elements that makes up the given SCEV dominate the
comment|/// specified basic block.
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
comment|/// Return true if elements that makes up the given SCEV properly dominate
comment|/// the specified basic block.
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
comment|/// Test whether the given SCEV has Op as a direct or indirect operand.
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
comment|/// Return the size of an element read or written by Inst.
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
comment|/// Compute the array dimensions Sizes from the set of Terms extracted from
comment|/// the memory access function of this SCEVAddRecExpr (second step of
comment|/// delinearization).
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
decl_stmt|;
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|void
name|verify
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|invalidate
argument_list|(
name|Function
operator|&
name|F
argument_list|,
specifier|const
name|PreservedAnalyses
operator|&
name|PA
argument_list|,
name|FunctionAnalysisManager
operator|::
name|Invalidator
operator|&
name|Inv
argument_list|)
decl_stmt|;
comment|/// Collect parametric terms occurring in step expressions (first step of
comment|/// delinearization).
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
comment|/// Return in Subscripts the access functions for each dimension in Sizes
comment|/// (third step of delinearization).
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
decl_stmt|;
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
comment|/// Re-writes the SCEV according to the Predicates in \p A.
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
comment|/// Tries to convert the \p S expression to an AddRec expression,
comment|/// adding additional predicates to \p Preds as required.
specifier|const
name|SCEVAddRecExpr
modifier|*
name|convertSCEVToAddRecWithPredicates
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
argument_list|,
name|SmallPtrSetImpl
operator|<
specifier|const
name|SCEVPredicate
operator|*
operator|>
operator|&
name|Preds
argument_list|)
decl_stmt|;
name|private
label|:
comment|/// Compute the backedge taken count knowing the interval difference, the
comment|/// stride and presence of the equality in the comparison.
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
comment|/// Verify if an linear IV with positive stride can overflow when in a
comment|/// less-than comparison, knowing the invariant term of the comparison,
comment|/// the stride and the knowledge of NSW/NUW flags on the recurrence.
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
comment|/// Verify if an linear IV with negative stride can overflow when in a
comment|/// greater-than comparison, knowing the invariant term of the comparison,
comment|/// the stride and the knowledge of NSW/NUW flags on the recurrence.
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
comment|/// Get add expr already created or create a new one
specifier|const
name|SCEV
modifier|*
name|getOrCreateAddExpr
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
argument_list|)
decl_stmt|;
name|private
label|:
name|FoldingSet
operator|<
name|SCEV
operator|>
name|UniqueSCEVs
expr_stmt|;
name|FoldingSet
operator|<
name|SCEVPredicate
operator|>
name|UniquePreds
expr_stmt|;
name|BumpPtrAllocator
name|SCEVAllocator
decl_stmt|;
comment|/// The head of a linked list of all SCEVUnknown values that have been
comment|/// allocated. This is used by releaseMemory to locate them all and call
comment|/// their destructors.
name|SCEVUnknown
modifier|*
name|FirstUnknown
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
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
name|AnalysisKey
name|Key
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
name|FunctionAnalysisManager
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
name|FunctionAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
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
block|; }
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

