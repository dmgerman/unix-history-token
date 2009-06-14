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
comment|// catagorize scalar expressions in loops.  It specializes in recognizing
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
file|"llvm/Analysis/LoopInfo.h"
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
file|<iosfwd>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|APInt
decl_stmt|;
name|class
name|ConstantInt
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|SCEVHandle
decl_stmt|;
name|class
name|ScalarEvolution
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
comment|/// SCEV - This class represents an analyzed expression in the program.  These
comment|/// are reference-counted opaque objects that the client is not allowed to
comment|/// do much with directly.
comment|///
name|class
name|SCEV
block|{
specifier|const
name|unsigned
name|SCEVType
decl_stmt|;
comment|// The SCEV baseclass this node corresponds to
name|mutable
name|unsigned
name|RefCount
decl_stmt|;
name|friend
name|class
name|SCEVHandle
decl_stmt|;
name|void
name|addRef
argument_list|()
specifier|const
block|{
operator|++
name|RefCount
block|; }
name|void
name|dropRef
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|--
name|RefCount
operator|==
literal|0
condition|)
name|delete
name|this
decl_stmt|;
block|}
name|SCEV
argument_list|(
specifier|const
name|SCEV
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|SCEV
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|protected
label|:
name|virtual
operator|~
name|SCEV
argument_list|()
expr_stmt|;
name|public
label|:
name|explicit
name|SCEV
argument_list|(
argument|unsigned SCEVTy
argument_list|)
block|:
name|SCEVType
argument_list|(
name|SCEVTy
argument_list|)
operator|,
name|RefCount
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
comment|/// isLoopInvariant - Return true if the value of this SCEV is unchanging in
comment|/// the specified loop.
name|virtual
name|bool
name|isLoopInvariant
argument_list|(
specifier|const
name|Loop
operator|*
name|L
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// hasComputableLoopEvolution - Return true if this SCEV changes value in a
comment|/// known way in the specified loop.  This property being true implies that
comment|/// the value is variant in the loop AND that we can emit an expression to
comment|/// compute the value of the expression at any particular loop iteration.
name|virtual
name|bool
name|hasComputableLoopEvolution
argument_list|(
specifier|const
name|Loop
operator|*
name|L
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// getType - Return the LLVM type of this SCEV expression.
comment|///
name|virtual
specifier|const
name|Type
operator|*
name|getType
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// isZero - Return true if the expression is a constant zero.
comment|///
name|bool
name|isZero
argument_list|()
specifier|const
expr_stmt|;
comment|/// isOne - Return true if the expression is a constant one.
comment|///
name|bool
name|isOne
argument_list|()
specifier|const
expr_stmt|;
comment|/// replaceSymbolicValuesWithConcrete - If this SCEV internally references
comment|/// the symbolic value "Sym", construct and return a new SCEV that produces
comment|/// the same value, but which uses the concrete value Conc instead of the
comment|/// symbolic value.  If this SCEV does not use the symbolic value, it
comment|/// returns itself.
name|virtual
name|SCEVHandle
name|replaceSymbolicValuesWithConcrete
argument_list|(
specifier|const
name|SCEVHandle
operator|&
name|Sym
argument_list|,
specifier|const
name|SCEVHandle
operator|&
name|Conc
argument_list|,
name|ScalarEvolution
operator|&
name|SE
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// dominates - Return true if elements that makes up this SCEV dominates
comment|/// the specified basic block.
name|virtual
name|bool
name|dominates
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|,
name|DominatorTree
operator|*
name|DT
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// print - Print out the internal representation of this scalar to the
comment|/// specified stream.  This should really only be used for debugging
comment|/// purposes.
name|virtual
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|void
name|print
argument_list|(
name|std
operator|::
name|ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|void
name|print
argument_list|(
name|std
operator|::
name|ostream
operator|*
name|OS
argument_list|)
decl|const
block|{
if|if
condition|(
name|OS
condition|)
name|print
argument_list|(
operator|*
name|OS
argument_list|)
expr_stmt|;
block|}
comment|/// dump - This method is used for debugging.
comment|///
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
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
specifier|inline
name|std
operator|::
name|ostream
operator|&
name|operator
operator|<<
operator|(
name|std
operator|::
name|ostream
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
name|struct
name|SCEVCouldNotCompute
range|:
name|public
name|SCEV
block|{
name|SCEVCouldNotCompute
argument_list|()
block|;
operator|~
name|SCEVCouldNotCompute
argument_list|()
block|;
comment|// None of these methods are valid for this object.
name|virtual
name|bool
name|isLoopInvariant
argument_list|(
argument|const Loop *L
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|Type
operator|*
name|getType
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|hasComputableLoopEvolution
argument_list|(
argument|const Loop *L
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;
name|virtual
name|SCEVHandle
name|replaceSymbolicValuesWithConcrete
argument_list|(
argument|const SCEVHandle&Sym
argument_list|,
argument|const SCEVHandle&Conc
argument_list|,
argument|ScalarEvolution&SE
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|dominates
argument_list|(
argument|BasicBlock *BB
argument_list|,
argument|DominatorTree *DT
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
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
decl_stmt|;
comment|/// SCEVHandle - This class is used to maintain the SCEV object's refcounts,
comment|/// freeing the objects when the last reference is dropped.
name|class
name|SCEVHandle
block|{
specifier|const
name|SCEV
modifier|*
name|S
decl_stmt|;
name|SCEVHandle
argument_list|()
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
name|SCEVHandle
argument_list|(
specifier|const
name|SCEV
operator|*
name|s
argument_list|)
operator|:
name|S
argument_list|(
argument|s
argument_list|)
block|{
name|assert
argument_list|(
name|S
operator|&&
literal|"Cannot create a handle to a null SCEV!"
argument_list|)
block|;
name|S
operator|->
name|addRef
argument_list|()
block|;     }
name|SCEVHandle
argument_list|(
specifier|const
name|SCEVHandle
operator|&
name|RHS
argument_list|)
operator|:
name|S
argument_list|(
argument|RHS.S
argument_list|)
block|{
name|S
operator|->
name|addRef
argument_list|()
block|;     }
operator|~
name|SCEVHandle
argument_list|()
block|{
name|S
operator|->
name|dropRef
argument_list|()
block|; }
name|operator
specifier|const
name|SCEV
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|S
return|;
block|}
specifier|const
name|SCEV
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|S
return|;
block|}
specifier|const
name|SCEV
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|S
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SCEV
operator|*
name|RHS
operator|)
specifier|const
block|{
return|return
name|S
operator|==
name|RHS
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|SCEV
operator|*
name|RHS
operator|)
specifier|const
block|{
return|return
name|S
operator|!=
name|RHS
return|;
block|}
specifier|const
name|SCEVHandle
modifier|&
name|operator
init|=
operator|(
name|SCEV
operator|*
name|RHS
operator|)
block|{
if|if
condition|(
name|S
operator|!=
name|RHS
condition|)
block|{
name|S
operator|->
name|dropRef
argument_list|()
expr_stmt|;
name|S
operator|=
name|RHS
expr_stmt|;
name|S
operator|->
name|addRef
argument_list|()
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
specifier|const
name|SCEVHandle
modifier|&
name|operator
init|=
operator|(
specifier|const
name|SCEVHandle
operator|&
name|RHS
operator|)
block|{
if|if
condition|(
name|S
operator|!=
name|RHS
operator|.
name|S
condition|)
block|{
name|S
operator|->
name|dropRef
argument_list|()
expr_stmt|;
name|S
operator|=
name|RHS
operator|.
name|S
expr_stmt|;
name|S
operator|->
name|addRef
argument_list|()
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|From
operator|>
expr|struct
name|simplify_type
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
specifier|const
name|SCEVHandle
operator|>
block|{
typedef|typedef
specifier|const
name|SCEV
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|const SCEVHandle&Node
argument_list|)
block|{
return|return
name|Node
return|;
block|}
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
name|SCEVHandle
operator|>
operator|:
name|public
name|simplify_type
operator|<
specifier|const
name|SCEVHandle
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// ScalarEvolution - This class is the main scalar evolution driver.  Because
end_comment

begin_comment
comment|/// client code (intentionally) can't do much with the SCEV objects directly,
end_comment

begin_comment
comment|/// they must ask this class for services.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|ScalarEvolution
range|:
name|public
name|FunctionPass
block|{
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
comment|/// TD - The target data information for the target we are targetting.
comment|///
name|TargetData
operator|*
name|TD
block|;
comment|/// CouldNotCompute - This SCEV is used to represent unknown trip
comment|/// counts and things.
name|SCEVHandle
name|CouldNotCompute
block|;
comment|/// Scalars - This is a cache of the scalars we have analyzed so far.
comment|///
name|std
operator|::
name|map
operator|<
name|SCEVCallbackVH
block|,
name|SCEVHandle
operator|>
name|Scalars
block|;
comment|/// BackedgeTakenInfo - Information about the backedge-taken count
comment|/// of a loop. This currently inclues an exact count and a maximum count.
comment|///
block|struct
name|BackedgeTakenInfo
block|{
comment|/// Exact - An expression indicating the exact backedge-taken count of
comment|/// the loop if it is known, or a SCEVCouldNotCompute otherwise.
name|SCEVHandle
name|Exact
block|;
comment|/// Exact - An expression indicating the least maximum backedge-taken
comment|/// count of the loop that is known, or a SCEVCouldNotCompute.
name|SCEVHandle
name|Max
block|;
comment|/*implicit*/
name|BackedgeTakenInfo
argument_list|(
argument|SCEVHandle exact
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
argument|SCEVHandle exact
argument_list|,
argument|SCEVHandle max
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
comment|/// ValuesAtScopes - This map contains entries for all the instructions
comment|/// that we attempt to compute getSCEVAtScope information for without
comment|/// using SCEV techniques, which can be expensive.
name|std
operator|::
name|map
operator|<
name|Instruction
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
name|Constant
operator|*
operator|>
expr|>
name|ValuesAtScopes
block|;
comment|/// createSCEV - We know that there is no SCEV for the specified value.
comment|/// Analyze the expression.
name|SCEVHandle
name|createSCEV
argument_list|(
name|Value
operator|*
name|V
argument_list|)
block|;
comment|/// createNodeForPHI - Provide the special handling we need to analyze PHI
comment|/// SCEVs.
name|SCEVHandle
name|createNodeForPHI
argument_list|(
name|PHINode
operator|*
name|PN
argument_list|)
block|;
comment|/// createNodeForGEP - Provide the special handling we need to analyze GEP
comment|/// SCEVs.
name|SCEVHandle
name|createNodeForGEP
argument_list|(
name|User
operator|*
name|GEP
argument_list|)
block|;
comment|/// ReplaceSymbolicValueWithConcrete - This looks up the computed SCEV value
comment|/// for the specified instruction and replaces any references to the
comment|/// symbolic value SymName with the specified value.  This is used during
comment|/// PHI resolution.
name|void
name|ReplaceSymbolicValueWithConcrete
argument_list|(
name|Instruction
operator|*
name|I
argument_list|,
specifier|const
name|SCEVHandle
operator|&
name|SymName
argument_list|,
specifier|const
name|SCEVHandle
operator|&
name|NewVal
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
comment|/// ComputeLoadConstantCompareBackedgeTakenCount - Given an exit condition
comment|/// of 'icmp op load X, cst', try to see if we can compute the trip count.
name|SCEVHandle
name|ComputeLoadConstantCompareBackedgeTakenCount
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
comment|/// ComputeBackedgeTakenCountExhaustively - If the trip is known to execute
comment|/// a constant number of times (the condition evolves only from constants),
comment|/// try to evaluate a few iterations of the loop until we get the exit
comment|/// condition gets a value of ExitWhen (true or false).  If we cannot
comment|/// evaluate the trip count of the loop, return CouldNotCompute.
name|SCEVHandle
name|ComputeBackedgeTakenCountExhaustively
argument_list|(
argument|const Loop *L
argument_list|,
argument|Value *Cond
argument_list|,
argument|bool ExitWhen
argument_list|)
block|;
comment|/// HowFarToZero - Return the number of times a backedge comparing the
comment|/// specified value to zero will execute.  If not computable, return
comment|/// CouldNotCompute.
name|SCEVHandle
name|HowFarToZero
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
comment|/// HowFarToNonZero - Return the number of times a backedge checking the
comment|/// specified value for nonzero will execute.  If not computable, return
comment|/// CouldNotCompute.
name|SCEVHandle
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
comment|/// HowManyLessThans - Return the number of times a backedge containing the
comment|/// specified less-than comparison will execute.  If not computable, return
comment|/// CouldNotCompute. isSigned specifies whether the less-than is signed.
name|BackedgeTakenInfo
name|HowManyLessThans
argument_list|(
argument|const SCEV *LHS
argument_list|,
argument|const SCEV *RHS
argument_list|,
argument|const Loop *L
argument_list|,
argument|bool isSigned
argument_list|)
block|;
comment|/// getLoopPredecessor - If the given loop's header has exactly one unique
comment|/// predecessor outside the loop, return it. Otherwise return null.
name|BasicBlock
operator|*
name|getLoopPredecessor
argument_list|(
specifier|const
name|Loop
operator|*
name|L
argument_list|)
block|;
comment|/// getPredecessorWithUniqueSuccessorForBB - Return a predecessor of BB
comment|/// (which may not be an immediate predecessor) which has exactly one
comment|/// successor from which BB is reachable, or null if no such block is
comment|/// found.
name|BasicBlock
operator|*
name|getPredecessorWithUniqueSuccessorForBB
argument_list|(
name|BasicBlock
operator|*
name|BB
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
comment|/// forgetLoopPHIs - Delete the memoized SCEVs associated with the
comment|/// PHI nodes in the given loop. This is used when the trip count of
comment|/// the loop may have changed.
name|void
name|forgetLoopPHIs
argument_list|(
specifier|const
name|Loop
operator|*
name|L
argument_list|)
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
comment|/// isSCEVable - Test if values of the given type are analyzable within
comment|/// the SCEV framework. This primarily includes integer types, and it
comment|/// can optionally include pointer types if the ScalarEvolution class
comment|/// has access to target-specific information.
name|bool
name|isSCEVable
argument_list|(
argument|const Type *Ty
argument_list|)
specifier|const
block|;
comment|/// getTypeSizeInBits - Return the size in bits of the specified type,
comment|/// for which isSCEVable must return true.
name|uint64_t
name|getTypeSizeInBits
argument_list|(
argument|const Type *Ty
argument_list|)
specifier|const
block|;
comment|/// getEffectiveSCEVType - Return a type with the same bitwidth as
comment|/// the given type and which represents how SCEV will treat the given
comment|/// type, for which isSCEVable must return true. For pointer types,
comment|/// this is the pointer-sized integer type.
specifier|const
name|Type
operator|*
name|getEffectiveSCEVType
argument_list|(
argument|const Type *Ty
argument_list|)
specifier|const
block|;
comment|/// getSCEV - Return a SCEV expression handle for the full generality of the
comment|/// specified expression.
name|SCEVHandle
name|getSCEV
argument_list|(
name|Value
operator|*
name|V
argument_list|)
block|;
name|SCEVHandle
name|getConstant
argument_list|(
name|ConstantInt
operator|*
name|V
argument_list|)
block|;
name|SCEVHandle
name|getConstant
argument_list|(
specifier|const
name|APInt
operator|&
name|Val
argument_list|)
block|;
name|SCEVHandle
name|getTruncateExpr
argument_list|(
specifier|const
name|SCEVHandle
operator|&
name|Op
argument_list|,
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
block|;
name|SCEVHandle
name|getZeroExtendExpr
argument_list|(
specifier|const
name|SCEVHandle
operator|&
name|Op
argument_list|,
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
block|;
name|SCEVHandle
name|getSignExtendExpr
argument_list|(
specifier|const
name|SCEVHandle
operator|&
name|Op
argument_list|,
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
block|;
name|SCEVHandle
name|getAnyExtendExpr
argument_list|(
specifier|const
name|SCEVHandle
operator|&
name|Op
argument_list|,
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
block|;
name|SCEVHandle
name|getAddExpr
argument_list|(
name|std
operator|::
name|vector
operator|<
name|SCEVHandle
operator|>
operator|&
name|Ops
argument_list|)
block|;
name|SCEVHandle
name|getAddExpr
argument_list|(
argument|const SCEVHandle&LHS
argument_list|,
argument|const SCEVHandle&RHS
argument_list|)
block|{
name|std
operator|::
name|vector
operator|<
name|SCEVHandle
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
argument_list|)
return|;
block|}
name|SCEVHandle
name|getAddExpr
argument_list|(
argument|const SCEVHandle&Op0
argument_list|,
argument|const SCEVHandle&Op1
argument_list|,
argument|const SCEVHandle&Op2
argument_list|)
block|{
name|std
operator|::
name|vector
operator|<
name|SCEVHandle
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
argument_list|)
return|;
block|}
name|SCEVHandle
name|getMulExpr
argument_list|(
name|std
operator|::
name|vector
operator|<
name|SCEVHandle
operator|>
operator|&
name|Ops
argument_list|)
block|;
name|SCEVHandle
name|getMulExpr
argument_list|(
argument|const SCEVHandle&LHS
argument_list|,
argument|const SCEVHandle&RHS
argument_list|)
block|{
name|std
operator|::
name|vector
operator|<
name|SCEVHandle
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
argument_list|)
return|;
block|}
name|SCEVHandle
name|getUDivExpr
argument_list|(
specifier|const
name|SCEVHandle
operator|&
name|LHS
argument_list|,
specifier|const
name|SCEVHandle
operator|&
name|RHS
argument_list|)
block|;
name|SCEVHandle
name|getAddRecExpr
argument_list|(
specifier|const
name|SCEVHandle
operator|&
name|Start
argument_list|,
specifier|const
name|SCEVHandle
operator|&
name|Step
argument_list|,
specifier|const
name|Loop
operator|*
name|L
argument_list|)
block|;
name|SCEVHandle
name|getAddRecExpr
argument_list|(
name|std
operator|::
name|vector
operator|<
name|SCEVHandle
operator|>
operator|&
name|Operands
argument_list|,
specifier|const
name|Loop
operator|*
name|L
argument_list|)
block|;
name|SCEVHandle
name|getAddRecExpr
argument_list|(
argument|const std::vector<SCEVHandle>&Operands
argument_list|,
argument|const Loop *L
argument_list|)
block|{
name|std
operator|::
name|vector
operator|<
name|SCEVHandle
operator|>
name|NewOp
argument_list|(
name|Operands
argument_list|)
block|;
return|return
name|getAddRecExpr
argument_list|(
name|NewOp
argument_list|,
name|L
argument_list|)
return|;
block|}
name|SCEVHandle
name|getSMaxExpr
argument_list|(
specifier|const
name|SCEVHandle
operator|&
name|LHS
argument_list|,
specifier|const
name|SCEVHandle
operator|&
name|RHS
argument_list|)
block|;
name|SCEVHandle
name|getSMaxExpr
argument_list|(
name|std
operator|::
name|vector
operator|<
name|SCEVHandle
operator|>
name|Operands
argument_list|)
block|;
name|SCEVHandle
name|getUMaxExpr
argument_list|(
specifier|const
name|SCEVHandle
operator|&
name|LHS
argument_list|,
specifier|const
name|SCEVHandle
operator|&
name|RHS
argument_list|)
block|;
name|SCEVHandle
name|getUMaxExpr
argument_list|(
name|std
operator|::
name|vector
operator|<
name|SCEVHandle
operator|>
name|Operands
argument_list|)
block|;
name|SCEVHandle
name|getUnknown
argument_list|(
name|Value
operator|*
name|V
argument_list|)
block|;
name|SCEVHandle
name|getCouldNotCompute
argument_list|()
block|;
comment|/// getNegativeSCEV - Return the SCEV object corresponding to -V.
comment|///
name|SCEVHandle
name|getNegativeSCEV
argument_list|(
specifier|const
name|SCEVHandle
operator|&
name|V
argument_list|)
block|;
comment|/// getNotSCEV - Return the SCEV object corresponding to ~V.
comment|///
name|SCEVHandle
name|getNotSCEV
argument_list|(
specifier|const
name|SCEVHandle
operator|&
name|V
argument_list|)
block|;
comment|/// getMinusSCEV - Return LHS-RHS.
comment|///
name|SCEVHandle
name|getMinusSCEV
argument_list|(
specifier|const
name|SCEVHandle
operator|&
name|LHS
argument_list|,
specifier|const
name|SCEVHandle
operator|&
name|RHS
argument_list|)
block|;
comment|/// getTruncateOrZeroExtend - Return a SCEV corresponding to a conversion
comment|/// of the input value to the specified type.  If the type must be
comment|/// extended, it is zero extended.
name|SCEVHandle
name|getTruncateOrZeroExtend
argument_list|(
specifier|const
name|SCEVHandle
operator|&
name|V
argument_list|,
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// getTruncateOrSignExtend - Return a SCEV corresponding to a conversion
comment|/// of the input value to the specified type.  If the type must be
comment|/// extended, it is sign extended.
name|SCEVHandle
name|getTruncateOrSignExtend
argument_list|(
specifier|const
name|SCEVHandle
operator|&
name|V
argument_list|,
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// getNoopOrZeroExtend - Return a SCEV corresponding to a conversion of
comment|/// the input value to the specified type.  If the type must be extended,
comment|/// it is zero extended.  The conversion must not be narrowing.
name|SCEVHandle
name|getNoopOrZeroExtend
argument_list|(
specifier|const
name|SCEVHandle
operator|&
name|V
argument_list|,
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// getNoopOrSignExtend - Return a SCEV corresponding to a conversion of
comment|/// the input value to the specified type.  If the type must be extended,
comment|/// it is sign extended.  The conversion must not be narrowing.
name|SCEVHandle
name|getNoopOrSignExtend
argument_list|(
specifier|const
name|SCEVHandle
operator|&
name|V
argument_list|,
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// getNoopOrAnyExtend - Return a SCEV corresponding to a conversion of
comment|/// the input value to the specified type. If the type must be extended,
comment|/// it is extended with unspecified bits. The conversion must not be
comment|/// narrowing.
name|SCEVHandle
name|getNoopOrAnyExtend
argument_list|(
specifier|const
name|SCEVHandle
operator|&
name|V
argument_list|,
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// getTruncateOrNoop - Return a SCEV corresponding to a conversion of the
comment|/// input value to the specified type.  The conversion must not be
comment|/// widening.
name|SCEVHandle
name|getTruncateOrNoop
argument_list|(
specifier|const
name|SCEVHandle
operator|&
name|V
argument_list|,
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// getIntegerSCEV - Given an integer or FP type, create a constant for the
comment|/// specified signed integer value and return a SCEV for the constant.
name|SCEVHandle
name|getIntegerSCEV
argument_list|(
argument|int Val
argument_list|,
argument|const Type *Ty
argument_list|)
block|;
comment|/// hasSCEV - Return true if the SCEV for this value has already been
comment|/// computed.
name|bool
name|hasSCEV
argument_list|(
argument|Value *V
argument_list|)
specifier|const
block|;
comment|/// setSCEV - Insert the specified SCEV into the map of current SCEVs for
comment|/// the specified value.
name|void
name|setSCEV
argument_list|(
name|Value
operator|*
name|V
argument_list|,
specifier|const
name|SCEVHandle
operator|&
name|H
argument_list|)
block|;
comment|/// getSCEVAtScope - Return a SCEV expression handle for the specified value
comment|/// at the specified scope in the program.  The L value specifies a loop
comment|/// nest to evaluate the expression at, where null is the top-level or a
comment|/// specified loop is immediately inside of the loop.
comment|///
comment|/// This method can be used to compute the exit value for a variable defined
comment|/// in a loop by querying what the value will hold in the parent loop.
comment|///
comment|/// In the case that a relevant loop exit value cannot be computed, the
comment|/// original value V is returned.
name|SCEVHandle
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
name|SCEVHandle
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
comment|/// isLoopGuardedByCond - Test whether entry to the loop is protected by
comment|/// a conditional between LHS and RHS.  This is used to help avoid max
comment|/// expressions in loop trip counts.
name|bool
name|isLoopGuardedByCond
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
name|SCEVHandle
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
name|SCEVHandle
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
comment|/// forgetLoopBackedgeTakenCount - This method should be called by the
comment|/// client when it has changed a loop in a way that may effect
comment|/// ScalarEvolution's ability to compute a trip count, or if the loop
comment|/// is deleted.
name|void
name|forgetLoopBackedgeTakenCount
argument_list|(
specifier|const
name|Loop
operator|*
name|L
argument_list|)
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
name|print
argument_list|(
argument|std::ostream&OS
argument_list|,
argument|const Module* =
literal|0
argument_list|)
specifier|const
block|;
name|void
name|print
argument_list|(
argument|std::ostream *OS
argument_list|,
argument|const Module* M =
literal|0
argument_list|)
specifier|const
block|{
if|if
condition|(
name|OS
condition|)
name|print
argument_list|(
operator|*
name|OS
argument_list|,
name|M
argument_list|)
expr_stmt|;
block|}
expr|}
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

