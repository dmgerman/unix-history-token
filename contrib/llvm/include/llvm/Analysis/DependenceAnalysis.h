begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Analysis/DependenceAnalysis.h -------------------- -*- C++ -*-===//
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
comment|// DependenceAnalysis is an LLVM pass that analyses dependences between memory
end_comment

begin_comment
comment|// accesses. Currently, it is an implementation of the approach described in
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//            Practical Dependence Testing
end_comment

begin_comment
comment|//            Goff, Kennedy, Tseng
end_comment

begin_comment
comment|//            PLDI 1991
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// There's a single entry point that analyzes the dependence between a pair
end_comment

begin_comment
comment|// of memory references in a function, returning either NULL, for no dependence,
end_comment

begin_comment
comment|// or a more-or-less detailed description of the dependence between them.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This pass exists to support the DependenceGraph pass. There are two separate
end_comment

begin_comment
comment|// passes because there's a useful separation of concerns. A dependence exists
end_comment

begin_comment
comment|// if two conditions are met:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    1) Two instructions reference the same memory location, and
end_comment

begin_comment
comment|//    2) There is a flow of control leading from one instruction to the other.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// DependenceAnalysis attacks the first condition; DependenceGraph will attack
end_comment

begin_comment
comment|// the second (it's not yet ready).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Please note that this is work in progress and the interface is subject to
end_comment

begin_comment
comment|// change.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Plausible changes:
end_comment

begin_comment
comment|//    Return a set of more precise dependences instead of just one dependence
end_comment

begin_comment
comment|//    summarizing all.
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
name|LLVM_ANALYSIS_DEPENDENCEANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_DEPENDENCEANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallBitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instructions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AliasAnalysis
decl_stmt|;
name|class
name|Loop
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
name|class
name|ScalarEvolution
decl_stmt|;
name|class
name|SCEV
decl_stmt|;
name|class
name|SCEVConstant
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// Dependence - This class represents a dependence between two memory
comment|/// memory references in a function. It contains minimal information and
comment|/// is used in the very common situation where the compiler is unable to
comment|/// determine anything beyond the existence of a dependence; that is, it
comment|/// represents a confused dependence (see also FullDependence). In most
comment|/// cases (for output, flow, and anti dependences), the dependence implies
comment|/// an ordering, where the source must precede the destination; in contrast,
comment|/// input dependences are unordered.
comment|///
comment|/// When a dependence graph is built, each Dependence will be a member of
comment|/// the set of predecessor edges for its destination instruction and a set
comment|/// if successor edges for its source instruction. These sets are represented
comment|/// as singly-linked lists, with the "next" fields stored in the dependence
comment|/// itelf.
name|class
name|Dependence
block|{
name|public
label|:
name|Dependence
argument_list|(
name|Instruction
operator|*
name|Source
argument_list|,
name|Instruction
operator|*
name|Destination
argument_list|)
operator|:
name|Src
argument_list|(
name|Source
argument_list|)
operator|,
name|Dst
argument_list|(
name|Destination
argument_list|)
operator|,
name|NextPredecessor
argument_list|(
name|NULL
argument_list|)
operator|,
name|NextSuccessor
argument_list|(
argument|NULL
argument_list|)
block|{}
name|virtual
operator|~
name|Dependence
argument_list|()
block|{}
comment|/// Dependence::DVEntry - Each level in the distance/direction vector
comment|/// has a direction (or perhaps a union of several directions), and
comment|/// perhaps a distance.
expr|struct
name|DVEntry
block|{       enum
block|{
name|NONE
operator|=
literal|0
block|,
name|LT
operator|=
literal|1
block|,
name|EQ
operator|=
literal|2
block|,
name|LE
operator|=
literal|3
block|,
name|GT
operator|=
literal|4
block|,
name|NE
operator|=
literal|5
block|,
name|GE
operator|=
literal|6
block|,
name|ALL
operator|=
literal|7
block|}
block|;
name|unsigned
name|char
name|Direction
operator|:
literal|3
block|;
comment|// Init to ALL, then refine.
name|bool
name|Scalar
operator|:
literal|1
block|;
comment|// Init to true.
name|bool
name|PeelFirst
operator|:
literal|1
block|;
comment|// Peeling the first iteration will break dependence.
name|bool
name|PeelLast
operator|:
literal|1
block|;
comment|// Peeling the last iteration will break the dependence.
name|bool
name|Splitable
operator|:
literal|1
block|;
comment|// Splitting the loop will break dependence.
specifier|const
name|SCEV
operator|*
name|Distance
block|;
comment|// NULL implies no distance available.
name|DVEntry
argument_list|()
operator|:
name|Direction
argument_list|(
name|ALL
argument_list|)
block|,
name|Scalar
argument_list|(
name|true
argument_list|)
block|,
name|PeelFirst
argument_list|(
name|false
argument_list|)
block|,
name|PeelLast
argument_list|(
name|false
argument_list|)
block|,
name|Splitable
argument_list|(
name|false
argument_list|)
block|,
name|Distance
argument_list|(
argument|NULL
argument_list|)
block|{ }
block|}
expr_stmt|;
comment|/// getSrc - Returns the source instruction for this dependence.
comment|///
name|Instruction
operator|*
name|getSrc
argument_list|()
specifier|const
block|{
return|return
name|Src
return|;
block|}
comment|/// getDst - Returns the destination instruction for this dependence.
comment|///
name|Instruction
operator|*
name|getDst
argument_list|()
specifier|const
block|{
return|return
name|Dst
return|;
block|}
comment|/// isInput - Returns true if this is an input dependence.
comment|///
name|bool
name|isInput
argument_list|()
specifier|const
expr_stmt|;
comment|/// isOutput - Returns true if this is an output dependence.
comment|///
name|bool
name|isOutput
argument_list|()
specifier|const
expr_stmt|;
comment|/// isFlow - Returns true if this is a flow (aka true) dependence.
comment|///
name|bool
name|isFlow
argument_list|()
specifier|const
expr_stmt|;
comment|/// isAnti - Returns true if this is an anti dependence.
comment|///
name|bool
name|isAnti
argument_list|()
specifier|const
expr_stmt|;
comment|/// isOrdered - Returns true if dependence is Output, Flow, or Anti
comment|///
name|bool
name|isOrdered
argument_list|()
specifier|const
block|{
return|return
name|isOutput
argument_list|()
operator|||
name|isFlow
argument_list|()
operator|||
name|isAnti
argument_list|()
return|;
block|}
comment|/// isUnordered - Returns true if dependence is Input
comment|///
name|bool
name|isUnordered
argument_list|()
specifier|const
block|{
return|return
name|isInput
argument_list|()
return|;
block|}
comment|/// isLoopIndependent - Returns true if this is a loop-independent
comment|/// dependence.
name|virtual
name|bool
name|isLoopIndependent
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// isConfused - Returns true if this dependence is confused
comment|/// (the compiler understands nothing and makes worst-case
comment|/// assumptions).
name|virtual
name|bool
name|isConfused
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// isConsistent - Returns true if this dependence is consistent
comment|/// (occurs every time the source and destination are executed).
name|virtual
name|bool
name|isConsistent
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// getLevels - Returns the number of common loops surrounding the
comment|/// source and destination of the dependence.
name|virtual
name|unsigned
name|getLevels
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// getDirection - Returns the direction associated with a particular
comment|/// level.
name|virtual
name|unsigned
name|getDirection
argument_list|(
name|unsigned
name|Level
argument_list|)
decl|const
block|{
return|return
name|DVEntry
operator|::
name|ALL
return|;
block|}
comment|/// getDistance - Returns the distance (or NULL) associated with a
comment|/// particular level.
name|virtual
specifier|const
name|SCEV
modifier|*
name|getDistance
argument_list|(
name|unsigned
name|Level
argument_list|)
decl|const
block|{
return|return
name|NULL
return|;
block|}
comment|/// isPeelFirst - Returns true if peeling the first iteration from
comment|/// this loop will break this dependence.
name|virtual
name|bool
name|isPeelFirst
argument_list|(
name|unsigned
name|Level
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// isPeelLast - Returns true if peeling the last iteration from
comment|/// this loop will break this dependence.
name|virtual
name|bool
name|isPeelLast
argument_list|(
name|unsigned
name|Level
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// isSplitable - Returns true if splitting this loop will break
comment|/// the dependence.
name|virtual
name|bool
name|isSplitable
argument_list|(
name|unsigned
name|Level
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// isScalar - Returns true if a particular level is scalar; that is,
comment|/// if no subscript in the source or destination mention the induction
comment|/// variable associated with the loop at this level.
name|virtual
name|bool
name|isScalar
argument_list|(
name|unsigned
name|Level
argument_list|)
decl|const
decl_stmt|;
comment|/// getNextPredecessor - Returns the value of the NextPredecessor
comment|/// field.
specifier|const
name|Dependence
operator|*
name|getNextPredecessor
argument_list|()
specifier|const
block|{
return|return
name|NextPredecessor
return|;
block|}
comment|/// getNextSuccessor - Returns the value of the NextSuccessor
comment|/// field.
specifier|const
name|Dependence
operator|*
name|getNextSuccessor
argument_list|()
specifier|const
block|{
return|return
name|NextSuccessor
return|;
block|}
comment|/// setNextPredecessor - Sets the value of the NextPredecessor
comment|/// field.
name|void
name|setNextPredecessor
parameter_list|(
specifier|const
name|Dependence
modifier|*
name|pred
parameter_list|)
block|{
name|NextPredecessor
operator|=
name|pred
expr_stmt|;
block|}
comment|/// setNextSuccessor - Sets the value of the NextSuccessor
comment|/// field.
name|void
name|setNextSuccessor
parameter_list|(
specifier|const
name|Dependence
modifier|*
name|succ
parameter_list|)
block|{
name|NextSuccessor
operator|=
name|succ
expr_stmt|;
block|}
comment|/// dump - For debugging purposes, dumps a dependence to OS.
comment|///
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|Instruction
modifier|*
name|Src
decl_stmt|,
modifier|*
name|Dst
decl_stmt|;
specifier|const
name|Dependence
modifier|*
name|NextPredecessor
decl_stmt|,
modifier|*
name|NextSuccessor
decl_stmt|;
name|friend
name|class
name|DependenceAnalysis
decl_stmt|;
block|}
empty_stmt|;
comment|/// FullDependence - This class represents a dependence between two memory
comment|/// references in a function. It contains detailed information about the
comment|/// dependence (direction vectors, etc.) and is used when the compiler is
comment|/// able to accurately analyze the interaction of the references; that is,
comment|/// it is not a confused dependence (see Dependence). In most cases
comment|/// (for output, flow, and anti dependences), the dependence implies an
comment|/// ordering, where the source must precede the destination; in contrast,
comment|/// input dependences are unordered.
name|class
name|FullDependence
range|:
name|public
name|Dependence
block|{
name|public
operator|:
name|FullDependence
argument_list|(
argument|Instruction *Src
argument_list|,
argument|Instruction *Dst
argument_list|,
argument|bool LoopIndependent
argument_list|,
argument|unsigned Levels
argument_list|)
block|;
operator|~
name|FullDependence
argument_list|()
block|{
name|delete
index|[]
name|DV
block|;     }
comment|/// isLoopIndependent - Returns true if this is a loop-independent
comment|/// dependence.
name|bool
name|isLoopIndependent
argument_list|()
specifier|const
block|{
return|return
name|LoopIndependent
return|;
block|}
comment|/// isConfused - Returns true if this dependence is confused
comment|/// (the compiler understands nothing and makes worst-case
comment|/// assumptions).
name|bool
name|isConfused
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// isConsistent - Returns true if this dependence is consistent
comment|/// (occurs every time the source and destination are executed).
name|bool
name|isConsistent
argument_list|()
specifier|const
block|{
return|return
name|Consistent
return|;
block|}
comment|/// getLevels - Returns the number of common loops surrounding the
comment|/// source and destination of the dependence.
name|unsigned
name|getLevels
argument_list|()
specifier|const
block|{
return|return
name|Levels
return|;
block|}
comment|/// getDirection - Returns the direction associated with a particular
comment|/// level.
name|unsigned
name|getDirection
argument_list|(
argument|unsigned Level
argument_list|)
specifier|const
block|;
comment|/// getDistance - Returns the distance (or NULL) associated with a
comment|/// particular level.
specifier|const
name|SCEV
operator|*
name|getDistance
argument_list|(
argument|unsigned Level
argument_list|)
specifier|const
block|;
comment|/// isPeelFirst - Returns true if peeling the first iteration from
comment|/// this loop will break this dependence.
name|bool
name|isPeelFirst
argument_list|(
argument|unsigned Level
argument_list|)
specifier|const
block|;
comment|/// isPeelLast - Returns true if peeling the last iteration from
comment|/// this loop will break this dependence.
name|bool
name|isPeelLast
argument_list|(
argument|unsigned Level
argument_list|)
specifier|const
block|;
comment|/// isSplitable - Returns true if splitting the loop will break
comment|/// the dependence.
name|bool
name|isSplitable
argument_list|(
argument|unsigned Level
argument_list|)
specifier|const
block|;
comment|/// isScalar - Returns true if a particular level is scalar; that is,
comment|/// if no subscript in the source or destination mention the induction
comment|/// variable associated with the loop at this level.
name|bool
name|isScalar
argument_list|(
argument|unsigned Level
argument_list|)
specifier|const
block|;
name|private
operator|:
name|unsigned
name|short
name|Levels
block|;
name|bool
name|LoopIndependent
block|;
name|bool
name|Consistent
block|;
comment|// Init to true, then refine.
name|DVEntry
operator|*
name|DV
block|;
name|friend
name|class
name|DependenceAnalysis
block|;   }
decl_stmt|;
comment|/// DependenceAnalysis - This class is the main dependence-analysis driver.
comment|///
name|class
name|DependenceAnalysis
range|:
name|public
name|FunctionPass
block|{
name|void
name|operator
operator|=
operator|(
specifier|const
name|DependenceAnalysis
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
block|;
name|DependenceAnalysis
argument_list|(
argument|const DependenceAnalysis&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|public
operator|:
comment|/// depends - Tests for a dependence between the Src and Dst instructions.
comment|/// Returns NULL if no dependence; otherwise, returns a Dependence (or a
comment|/// FullDependence) with as much information as can be gleaned.
comment|/// The flag PossiblyLoopIndependent should be set by the caller
comment|/// if it appears that control flow can reach from Src to Dst
comment|/// without traversing a loop back edge.
name|Dependence
operator|*
name|depends
argument_list|(
argument|Instruction *Src
argument_list|,
argument|Instruction *Dst
argument_list|,
argument|bool PossiblyLoopIndependent
argument_list|)
block|;
comment|/// getSplitIteration - Give a dependence that's splittable at some
comment|/// particular level, return the iteration that should be used to split
comment|/// the loop.
comment|///
comment|/// Generally, the dependence analyzer will be used to build
comment|/// a dependence graph for a function (basically a map from instructions
comment|/// to dependences). Looking for cycles in the graph shows us loops
comment|/// that cannot be trivially vectorized/parallelized.
comment|///
comment|/// We can try to improve the situation by examining all the dependences
comment|/// that make up the cycle, looking for ones we can break.
comment|/// Sometimes, peeling the first or last iteration of a loop will break
comment|/// dependences, and there are flags for those possibilities.
comment|/// Sometimes, splitting a loop at some other iteration will do the trick,
comment|/// and we've got a flag for that case. Rather than waste the space to
comment|/// record the exact iteration (since we rarely know), we provide
comment|/// a method that calculates the iteration. It's a drag that it must work
comment|/// from scratch, but wonderful in that it's possible.
comment|///
comment|/// Here's an example:
comment|///
comment|///    for (i = 0; i< 10; i++)
comment|///        A[i] = ...
comment|///        ... = A[11 - i]
comment|///
comment|/// There's a loop-carried flow dependence from the store to the load,
comment|/// found by the weak-crossing SIV test. The dependence will have a flag,
comment|/// indicating that the dependence can be broken by splitting the loop.
comment|/// Calling getSplitIteration will return 5.
comment|/// Splitting the loop breaks the dependence, like so:
comment|///
comment|///    for (i = 0; i<= 5; i++)
comment|///        A[i] = ...
comment|///        ... = A[11 - i]
comment|///    for (i = 6; i< 10; i++)
comment|///        A[i] = ...
comment|///        ... = A[11 - i]
comment|///
comment|/// breaks the dependence and allows us to vectorize/parallelize
comment|/// both loops.
specifier|const
name|SCEV
operator|*
name|getSplitIteration
argument_list|(
argument|const Dependence *Dep
argument_list|,
argument|unsigned Level
argument_list|)
block|;
name|private
operator|:
name|AliasAnalysis
operator|*
name|AA
block|;
name|ScalarEvolution
operator|*
name|SE
block|;
name|LoopInfo
operator|*
name|LI
block|;
name|Function
operator|*
name|F
block|;
comment|/// Subscript - This private struct represents a pair of subscripts from
comment|/// a pair of potentially multi-dimensional array references. We use a
comment|/// vector of them to guide subscript partitioning.
block|struct
name|Subscript
block|{
specifier|const
name|SCEV
operator|*
name|Src
block|;
specifier|const
name|SCEV
operator|*
name|Dst
block|;       enum
name|ClassificationKind
block|{
name|ZIV
block|,
name|SIV
block|,
name|RDIV
block|,
name|MIV
block|,
name|NonLinear
block|}
name|Classification
block|;
name|SmallBitVector
name|Loops
block|;
name|SmallBitVector
name|GroupLoops
block|;
name|SmallBitVector
name|Group
block|;     }
block|;      struct
name|CoefficientInfo
block|{
specifier|const
name|SCEV
operator|*
name|Coeff
block|;
specifier|const
name|SCEV
operator|*
name|PosPart
block|;
specifier|const
name|SCEV
operator|*
name|NegPart
block|;
specifier|const
name|SCEV
operator|*
name|Iterations
block|;     }
block|;      struct
name|BoundInfo
block|{
specifier|const
name|SCEV
operator|*
name|Iterations
block|;
specifier|const
name|SCEV
operator|*
name|Upper
index|[
literal|8
index|]
block|;
specifier|const
name|SCEV
operator|*
name|Lower
index|[
literal|8
index|]
block|;
name|unsigned
name|char
name|Direction
block|;
name|unsigned
name|char
name|DirSet
block|;     }
block|;
comment|/// Constraint - This private class represents a constraint, as defined
comment|/// in the paper
comment|///
comment|///           Practical Dependence Testing
comment|///           Goff, Kennedy, Tseng
comment|///           PLDI 1991
comment|///
comment|/// There are 5 kinds of constraint, in a hierarchy.
comment|///   1) Any - indicates no constraint, any dependence is possible.
comment|///   2) Line - A line ax + by = c, where a, b, and c are parameters,
comment|///             representing the dependence equation.
comment|///   3) Distance - The value d of the dependence distance;
comment|///   4) Point - A point<x, y> representing the dependence from
comment|///              iteration x to iteration y.
comment|///   5) Empty - No dependence is possible.
name|class
name|Constraint
block|{
name|private
operator|:
expr|enum
name|ConstraintKind
block|{
name|Empty
block|,
name|Point
block|,
name|Distance
block|,
name|Line
block|,
name|Any
block|}
name|Kind
block|;
name|ScalarEvolution
operator|*
name|SE
block|;
specifier|const
name|SCEV
operator|*
name|A
block|;
specifier|const
name|SCEV
operator|*
name|B
block|;
specifier|const
name|SCEV
operator|*
name|C
block|;
specifier|const
name|Loop
operator|*
name|AssociatedLoop
block|;
name|public
operator|:
comment|/// isEmpty - Return true if the constraint is of kind Empty.
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|Empty
return|;
block|}
comment|/// isPoint - Return true if the constraint is of kind Point.
name|bool
name|isPoint
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|Point
return|;
block|}
comment|/// isDistance - Return true if the constraint is of kind Distance.
name|bool
name|isDistance
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|Distance
return|;
block|}
comment|/// isLine - Return true if the constraint is of kind Line.
comment|/// Since Distance's can also be represented as Lines, we also return
comment|/// true if the constraint is of kind Distance.
name|bool
name|isLine
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|Line
operator|||
name|Kind
operator|==
name|Distance
return|;
block|}
comment|/// isAny - Return true if the constraint is of kind Any;
name|bool
name|isAny
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|Any
return|;
block|}
comment|/// getX - If constraint is a point<X, Y>, returns X.
comment|/// Otherwise assert.
specifier|const
name|SCEV
operator|*
name|getX
argument_list|()
specifier|const
block|;
comment|/// getY - If constraint is a point<X, Y>, returns Y.
comment|/// Otherwise assert.
specifier|const
name|SCEV
operator|*
name|getY
argument_list|()
specifier|const
block|;
comment|/// getA - If constraint is a line AX + BY = C, returns A.
comment|/// Otherwise assert.
specifier|const
name|SCEV
operator|*
name|getA
argument_list|()
specifier|const
block|;
comment|/// getB - If constraint is a line AX + BY = C, returns B.
comment|/// Otherwise assert.
specifier|const
name|SCEV
operator|*
name|getB
argument_list|()
specifier|const
block|;
comment|/// getC - If constraint is a line AX + BY = C, returns C.
comment|/// Otherwise assert.
specifier|const
name|SCEV
operator|*
name|getC
argument_list|()
specifier|const
block|;
comment|/// getD - If constraint is a distance, returns D.
comment|/// Otherwise assert.
specifier|const
name|SCEV
operator|*
name|getD
argument_list|()
specifier|const
block|;
comment|/// getAssociatedLoop - Returns the loop associated with this constraint.
specifier|const
name|Loop
operator|*
name|getAssociatedLoop
argument_list|()
specifier|const
block|;
comment|/// setPoint - Change a constraint to Point.
name|void
name|setPoint
argument_list|(
specifier|const
name|SCEV
operator|*
name|X
argument_list|,
specifier|const
name|SCEV
operator|*
name|Y
argument_list|,
specifier|const
name|Loop
operator|*
name|CurrentLoop
argument_list|)
block|;
comment|/// setLine - Change a constraint to Line.
name|void
name|setLine
argument_list|(
specifier|const
name|SCEV
operator|*
name|A
argument_list|,
specifier|const
name|SCEV
operator|*
name|B
argument_list|,
specifier|const
name|SCEV
operator|*
name|C
argument_list|,
specifier|const
name|Loop
operator|*
name|CurrentLoop
argument_list|)
block|;
comment|/// setDistance - Change a constraint to Distance.
name|void
name|setDistance
argument_list|(
specifier|const
name|SCEV
operator|*
name|D
argument_list|,
specifier|const
name|Loop
operator|*
name|CurrentLoop
argument_list|)
block|;
comment|/// setEmpty - Change a constraint to Empty.
name|void
name|setEmpty
argument_list|()
block|;
comment|/// setAny - Change a constraint to Any.
name|void
name|setAny
argument_list|(
name|ScalarEvolution
operator|*
name|SE
argument_list|)
block|;
comment|/// dump - For debugging purposes. Dumps the constraint
comment|/// out to OS.
name|void
name|dump
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;     }
block|;
comment|/// establishNestingLevels - Examines the loop nesting of the Src and Dst
comment|/// instructions and establishes their shared loops. Sets the variables
comment|/// CommonLevels, SrcLevels, and MaxLevels.
comment|/// The source and destination instructions needn't be contained in the same
comment|/// loop. The routine establishNestingLevels finds the level of most deeply
comment|/// nested loop that contains them both, CommonLevels. An instruction that's
comment|/// not contained in a loop is at level = 0. MaxLevels is equal to the level
comment|/// of the source plus the level of the destination, minus CommonLevels.
comment|/// This lets us allocate vectors MaxLevels in length, with room for every
comment|/// distinct loop referenced in both the source and destination subscripts.
comment|/// The variable SrcLevels is the nesting depth of the source instruction.
comment|/// It's used to help calculate distinct loops referenced by the destination.
comment|/// Here's the map from loops to levels:
comment|///            0 - unused
comment|///            1 - outermost common loop
comment|///          ... - other common loops
comment|/// CommonLevels - innermost common loop
comment|///          ... - loops containing Src but not Dst
comment|///    SrcLevels - innermost loop containing Src but not Dst
comment|///          ... - loops containing Dst but not Src
comment|///    MaxLevels - innermost loop containing Dst but not Src
comment|/// Consider the follow code fragment:
comment|///    for (a = ...) {
comment|///      for (b = ...) {
comment|///        for (c = ...) {
comment|///          for (d = ...) {
comment|///            A[] = ...;
comment|///          }
comment|///        }
comment|///        for (e = ...) {
comment|///          for (f = ...) {
comment|///            for (g = ...) {
comment|///              ... = A[];
comment|///            }
comment|///          }
comment|///        }
comment|///      }
comment|///    }
comment|/// If we're looking at the possibility of a dependence between the store
comment|/// to A (the Src) and the load from A (the Dst), we'll note that they
comment|/// have 2 loops in common, so CommonLevels will equal 2 and the direction
comment|/// vector for Result will have 2 entries. SrcLevels = 4 and MaxLevels = 7.
comment|/// A map from loop names to level indices would look like
comment|///     a - 1
comment|///     b - 2 = CommonLevels
comment|///     c - 3
comment|///     d - 4 = SrcLevels
comment|///     e - 5
comment|///     f - 6
comment|///     g - 7 = MaxLevels
name|void
name|establishNestingLevels
argument_list|(
specifier|const
name|Instruction
operator|*
name|Src
argument_list|,
specifier|const
name|Instruction
operator|*
name|Dst
argument_list|)
block|;
name|unsigned
name|CommonLevels
block|,
name|SrcLevels
block|,
name|MaxLevels
block|;
comment|/// mapSrcLoop - Given one of the loops containing the source, return
comment|/// its level index in our numbering scheme.
name|unsigned
name|mapSrcLoop
argument_list|(
argument|const Loop *SrcLoop
argument_list|)
specifier|const
block|;
comment|/// mapDstLoop - Given one of the loops containing the destination,
comment|/// return its level index in our numbering scheme.
name|unsigned
name|mapDstLoop
argument_list|(
argument|const Loop *DstLoop
argument_list|)
specifier|const
block|;
comment|/// isLoopInvariant - Returns true if Expression is loop invariant
comment|/// in LoopNest.
name|bool
name|isLoopInvariant
argument_list|(
argument|const SCEV *Expression
argument_list|,
argument|const Loop *LoopNest
argument_list|)
specifier|const
block|;
comment|/// removeMatchingExtensions - Examines a subscript pair.
comment|/// If the source and destination are identically sign (or zero)
comment|/// extended, it strips off the extension in an effort to
comment|/// simplify the actual analysis.
name|void
name|removeMatchingExtensions
argument_list|(
name|Subscript
operator|*
name|Pair
argument_list|)
block|;
comment|/// collectCommonLoops - Finds the set of loops from the LoopNest that
comment|/// have a level<= CommonLevels and are referred to by the SCEV Expression.
name|void
name|collectCommonLoops
argument_list|(
argument|const SCEV *Expression
argument_list|,
argument|const Loop *LoopNest
argument_list|,
argument|SmallBitVector&Loops
argument_list|)
specifier|const
block|;
comment|/// checkSrcSubscript - Examines the SCEV Src, returning true iff it's
comment|/// linear. Collect the set of loops mentioned by Src.
name|bool
name|checkSrcSubscript
argument_list|(
specifier|const
name|SCEV
operator|*
name|Src
argument_list|,
specifier|const
name|Loop
operator|*
name|LoopNest
argument_list|,
name|SmallBitVector
operator|&
name|Loops
argument_list|)
block|;
comment|/// checkDstSubscript - Examines the SCEV Dst, returning true iff it's
comment|/// linear. Collect the set of loops mentioned by Dst.
name|bool
name|checkDstSubscript
argument_list|(
specifier|const
name|SCEV
operator|*
name|Dst
argument_list|,
specifier|const
name|Loop
operator|*
name|LoopNest
argument_list|,
name|SmallBitVector
operator|&
name|Loops
argument_list|)
block|;
comment|/// isKnownPredicate - Compare X and Y using the predicate Pred.
comment|/// Basically a wrapper for SCEV::isKnownPredicate,
comment|/// but tries harder, especially in the presence of sign and zero
comment|/// extensions and symbolics.
name|bool
name|isKnownPredicate
argument_list|(
argument|ICmpInst::Predicate Pred
argument_list|,
argument|const SCEV *X
argument_list|,
argument|const SCEV *Y
argument_list|)
specifier|const
block|;
comment|/// collectUpperBound - All subscripts are the same type (on my machine,
comment|/// an i64). The loop bound may be a smaller type. collectUpperBound
comment|/// find the bound, if available, and zero extends it to the Type T.
comment|/// (I zero extend since the bound should always be>= 0.)
comment|/// If no upper bound is available, return NULL.
specifier|const
name|SCEV
operator|*
name|collectUpperBound
argument_list|(
argument|const Loop *l
argument_list|,
argument|Type *T
argument_list|)
specifier|const
block|;
comment|/// collectConstantUpperBound - Calls collectUpperBound(), then
comment|/// attempts to cast it to SCEVConstant. If the cast fails,
comment|/// returns NULL.
specifier|const
name|SCEVConstant
operator|*
name|collectConstantUpperBound
argument_list|(
argument|const Loop *l
argument_list|,
argument|Type *T
argument_list|)
specifier|const
block|;
comment|/// classifyPair - Examines the subscript pair (the Src and Dst SCEVs)
comment|/// and classifies it as either ZIV, SIV, RDIV, MIV, or Nonlinear.
comment|/// Collects the associated loops in a set.
name|Subscript
operator|::
name|ClassificationKind
name|classifyPair
argument_list|(
specifier|const
name|SCEV
operator|*
name|Src
argument_list|,
specifier|const
name|Loop
operator|*
name|SrcLoopNest
argument_list|,
specifier|const
name|SCEV
operator|*
name|Dst
argument_list|,
specifier|const
name|Loop
operator|*
name|DstLoopNest
argument_list|,
name|SmallBitVector
operator|&
name|Loops
argument_list|)
block|;
comment|/// testZIV - Tests the ZIV subscript pair (Src and Dst) for dependence.
comment|/// Returns true if any possible dependence is disproved.
comment|/// If there might be a dependence, returns false.
comment|/// If the dependence isn't proven to exist,
comment|/// marks the Result as inconsistent.
name|bool
name|testZIV
argument_list|(
argument|const SCEV *Src
argument_list|,
argument|const SCEV *Dst
argument_list|,
argument|FullDependence&Result
argument_list|)
specifier|const
block|;
comment|/// testSIV - Tests the SIV subscript pair (Src and Dst) for dependence.
comment|/// Things of the form [c1 + a1*i] and [c2 + a2*j], where
comment|/// i and j are induction variables, c1 and c2 are loop invariant,
comment|/// and a1 and a2 are constant.
comment|/// Returns true if any possible dependence is disproved.
comment|/// If there might be a dependence, returns false.
comment|/// Sets appropriate direction vector entry and, when possible,
comment|/// the distance vector entry.
comment|/// If the dependence isn't proven to exist,
comment|/// marks the Result as inconsistent.
name|bool
name|testSIV
argument_list|(
argument|const SCEV *Src
argument_list|,
argument|const SCEV *Dst
argument_list|,
argument|unsigned&Level
argument_list|,
argument|FullDependence&Result
argument_list|,
argument|Constraint&NewConstraint
argument_list|,
argument|const SCEV *&SplitIter
argument_list|)
specifier|const
block|;
comment|/// testRDIV - Tests the RDIV subscript pair (Src and Dst) for dependence.
comment|/// Things of the form [c1 + a1*i] and [c2 + a2*j]
comment|/// where i and j are induction variables, c1 and c2 are loop invariant,
comment|/// and a1 and a2 are constant.
comment|/// With minor algebra, this test can also be used for things like
comment|/// [c1 + a1*i + a2*j][c2].
comment|/// Returns true if any possible dependence is disproved.
comment|/// If there might be a dependence, returns false.
comment|/// Marks the Result as inconsistent.
name|bool
name|testRDIV
argument_list|(
argument|const SCEV *Src
argument_list|,
argument|const SCEV *Dst
argument_list|,
argument|FullDependence&Result
argument_list|)
specifier|const
block|;
comment|/// testMIV - Tests the MIV subscript pair (Src and Dst) for dependence.
comment|/// Returns true if dependence disproved.
comment|/// Can sometimes refine direction vectors.
name|bool
name|testMIV
argument_list|(
argument|const SCEV *Src
argument_list|,
argument|const SCEV *Dst
argument_list|,
argument|const SmallBitVector&Loops
argument_list|,
argument|FullDependence&Result
argument_list|)
specifier|const
block|;
comment|/// strongSIVtest - Tests the strong SIV subscript pair (Src and Dst)
comment|/// for dependence.
comment|/// Things of the form [c1 + a*i] and [c2 + a*i],
comment|/// where i is an induction variable, c1 and c2 are loop invariant,
comment|/// and a is a constant
comment|/// Returns true if any possible dependence is disproved.
comment|/// If there might be a dependence, returns false.
comment|/// Sets appropriate direction and distance.
name|bool
name|strongSIVtest
argument_list|(
argument|const SCEV *Coeff
argument_list|,
argument|const SCEV *SrcConst
argument_list|,
argument|const SCEV *DstConst
argument_list|,
argument|const Loop *CurrentLoop
argument_list|,
argument|unsigned Level
argument_list|,
argument|FullDependence&Result
argument_list|,
argument|Constraint&NewConstraint
argument_list|)
specifier|const
block|;
comment|/// weakCrossingSIVtest - Tests the weak-crossing SIV subscript pair
comment|/// (Src and Dst) for dependence.
comment|/// Things of the form [c1 + a*i] and [c2 - a*i],
comment|/// where i is an induction variable, c1 and c2 are loop invariant,
comment|/// and a is a constant.
comment|/// Returns true if any possible dependence is disproved.
comment|/// If there might be a dependence, returns false.
comment|/// Sets appropriate direction entry.
comment|/// Set consistent to false.
comment|/// Marks the dependence as splitable.
name|bool
name|weakCrossingSIVtest
argument_list|(
argument|const SCEV *SrcCoeff
argument_list|,
argument|const SCEV *SrcConst
argument_list|,
argument|const SCEV *DstConst
argument_list|,
argument|const Loop *CurrentLoop
argument_list|,
argument|unsigned Level
argument_list|,
argument|FullDependence&Result
argument_list|,
argument|Constraint&NewConstraint
argument_list|,
argument|const SCEV *&SplitIter
argument_list|)
specifier|const
block|;
comment|/// ExactSIVtest - Tests the SIV subscript pair
comment|/// (Src and Dst) for dependence.
comment|/// Things of the form [c1 + a1*i] and [c2 + a2*i],
comment|/// where i is an induction variable, c1 and c2 are loop invariant,
comment|/// and a1 and a2 are constant.
comment|/// Returns true if any possible dependence is disproved.
comment|/// If there might be a dependence, returns false.
comment|/// Sets appropriate direction entry.
comment|/// Set consistent to false.
name|bool
name|exactSIVtest
argument_list|(
argument|const SCEV *SrcCoeff
argument_list|,
argument|const SCEV *DstCoeff
argument_list|,
argument|const SCEV *SrcConst
argument_list|,
argument|const SCEV *DstConst
argument_list|,
argument|const Loop *CurrentLoop
argument_list|,
argument|unsigned Level
argument_list|,
argument|FullDependence&Result
argument_list|,
argument|Constraint&NewConstraint
argument_list|)
specifier|const
block|;
comment|/// weakZeroSrcSIVtest - Tests the weak-zero SIV subscript pair
comment|/// (Src and Dst) for dependence.
comment|/// Things of the form [c1] and [c2 + a*i],
comment|/// where i is an induction variable, c1 and c2 are loop invariant,
comment|/// and a is a constant. See also weakZeroDstSIVtest.
comment|/// Returns true if any possible dependence is disproved.
comment|/// If there might be a dependence, returns false.
comment|/// Sets appropriate direction entry.
comment|/// Set consistent to false.
comment|/// If loop peeling will break the dependence, mark appropriately.
name|bool
name|weakZeroSrcSIVtest
argument_list|(
argument|const SCEV *DstCoeff
argument_list|,
argument|const SCEV *SrcConst
argument_list|,
argument|const SCEV *DstConst
argument_list|,
argument|const Loop *CurrentLoop
argument_list|,
argument|unsigned Level
argument_list|,
argument|FullDependence&Result
argument_list|,
argument|Constraint&NewConstraint
argument_list|)
specifier|const
block|;
comment|/// weakZeroDstSIVtest - Tests the weak-zero SIV subscript pair
comment|/// (Src and Dst) for dependence.
comment|/// Things of the form [c1 + a*i] and [c2],
comment|/// where i is an induction variable, c1 and c2 are loop invariant,
comment|/// and a is a constant. See also weakZeroSrcSIVtest.
comment|/// Returns true if any possible dependence is disproved.
comment|/// If there might be a dependence, returns false.
comment|/// Sets appropriate direction entry.
comment|/// Set consistent to false.
comment|/// If loop peeling will break the dependence, mark appropriately.
name|bool
name|weakZeroDstSIVtest
argument_list|(
argument|const SCEV *SrcCoeff
argument_list|,
argument|const SCEV *SrcConst
argument_list|,
argument|const SCEV *DstConst
argument_list|,
argument|const Loop *CurrentLoop
argument_list|,
argument|unsigned Level
argument_list|,
argument|FullDependence&Result
argument_list|,
argument|Constraint&NewConstraint
argument_list|)
specifier|const
block|;
comment|/// exactRDIVtest - Tests the RDIV subscript pair for dependence.
comment|/// Things of the form [c1 + a*i] and [c2 + b*j],
comment|/// where i and j are induction variable, c1 and c2 are loop invariant,
comment|/// and a and b are constants.
comment|/// Returns true if any possible dependence is disproved.
comment|/// Marks the result as inconsistent.
comment|/// Works in some cases that symbolicRDIVtest doesn't,
comment|/// and vice versa.
name|bool
name|exactRDIVtest
argument_list|(
argument|const SCEV *SrcCoeff
argument_list|,
argument|const SCEV *DstCoeff
argument_list|,
argument|const SCEV *SrcConst
argument_list|,
argument|const SCEV *DstConst
argument_list|,
argument|const Loop *SrcLoop
argument_list|,
argument|const Loop *DstLoop
argument_list|,
argument|FullDependence&Result
argument_list|)
specifier|const
block|;
comment|/// symbolicRDIVtest - Tests the RDIV subscript pair for dependence.
comment|/// Things of the form [c1 + a*i] and [c2 + b*j],
comment|/// where i and j are induction variable, c1 and c2 are loop invariant,
comment|/// and a and b are constants.
comment|/// Returns true if any possible dependence is disproved.
comment|/// Marks the result as inconsistent.
comment|/// Works in some cases that exactRDIVtest doesn't,
comment|/// and vice versa. Can also be used as a backup for
comment|/// ordinary SIV tests.
name|bool
name|symbolicRDIVtest
argument_list|(
argument|const SCEV *SrcCoeff
argument_list|,
argument|const SCEV *DstCoeff
argument_list|,
argument|const SCEV *SrcConst
argument_list|,
argument|const SCEV *DstConst
argument_list|,
argument|const Loop *SrcLoop
argument_list|,
argument|const Loop *DstLoop
argument_list|)
specifier|const
block|;
comment|/// gcdMIVtest - Tests an MIV subscript pair for dependence.
comment|/// Returns true if any possible dependence is disproved.
comment|/// Marks the result as inconsistent.
comment|/// Can sometimes disprove the equal direction for 1 or more loops.
comment|//  Can handle some symbolics that even the SIV tests don't get,
comment|/// so we use it as a backup for everything.
name|bool
name|gcdMIVtest
argument_list|(
argument|const SCEV *Src
argument_list|,
argument|const SCEV *Dst
argument_list|,
argument|FullDependence&Result
argument_list|)
specifier|const
block|;
comment|/// banerjeeMIVtest - Tests an MIV subscript pair for dependence.
comment|/// Returns true if any possible dependence is disproved.
comment|/// Marks the result as inconsistent.
comment|/// Computes directions.
name|bool
name|banerjeeMIVtest
argument_list|(
argument|const SCEV *Src
argument_list|,
argument|const SCEV *Dst
argument_list|,
argument|const SmallBitVector&Loops
argument_list|,
argument|FullDependence&Result
argument_list|)
specifier|const
block|;
comment|/// collectCoefficientInfo - Walks through the subscript,
comment|/// collecting each coefficient, the associated loop bounds,
comment|/// and recording its positive and negative parts for later use.
name|CoefficientInfo
operator|*
name|collectCoeffInfo
argument_list|(
argument|const SCEV *Subscript
argument_list|,
argument|bool SrcFlag
argument_list|,
argument|const SCEV *&Constant
argument_list|)
specifier|const
block|;
comment|/// getPositivePart - X^+ = max(X, 0).
comment|///
specifier|const
name|SCEV
operator|*
name|getPositivePart
argument_list|(
argument|const SCEV *X
argument_list|)
specifier|const
block|;
comment|/// getNegativePart - X^- = min(X, 0).
comment|///
specifier|const
name|SCEV
operator|*
name|getNegativePart
argument_list|(
argument|const SCEV *X
argument_list|)
specifier|const
block|;
comment|/// getLowerBound - Looks through all the bounds info and
comment|/// computes the lower bound given the current direction settings
comment|/// at each level.
specifier|const
name|SCEV
operator|*
name|getLowerBound
argument_list|(
argument|BoundInfo *Bound
argument_list|)
specifier|const
block|;
comment|/// getUpperBound - Looks through all the bounds info and
comment|/// computes the upper bound given the current direction settings
comment|/// at each level.
specifier|const
name|SCEV
operator|*
name|getUpperBound
argument_list|(
argument|BoundInfo *Bound
argument_list|)
specifier|const
block|;
comment|/// exploreDirections - Hierarchically expands the direction vector
comment|/// search space, combining the directions of discovered dependences
comment|/// in the DirSet field of Bound. Returns the number of distinct
comment|/// dependences discovered. If the dependence is disproved,
comment|/// it will return 0.
name|unsigned
name|exploreDirections
argument_list|(
argument|unsigned Level
argument_list|,
argument|CoefficientInfo *A
argument_list|,
argument|CoefficientInfo *B
argument_list|,
argument|BoundInfo *Bound
argument_list|,
argument|const SmallBitVector&Loops
argument_list|,
argument|unsigned&DepthExpanded
argument_list|,
argument|const SCEV *Delta
argument_list|)
specifier|const
block|;
comment|/// testBounds - Returns true iff the current bounds are plausible.
comment|///
name|bool
name|testBounds
argument_list|(
argument|unsigned char DirKind
argument_list|,
argument|unsigned Level
argument_list|,
argument|BoundInfo *Bound
argument_list|,
argument|const SCEV *Delta
argument_list|)
specifier|const
block|;
comment|/// findBoundsALL - Computes the upper and lower bounds for level K
comment|/// using the * direction. Records them in Bound.
name|void
name|findBoundsALL
argument_list|(
argument|CoefficientInfo *A
argument_list|,
argument|CoefficientInfo *B
argument_list|,
argument|BoundInfo *Bound
argument_list|,
argument|unsigned K
argument_list|)
specifier|const
block|;
comment|/// findBoundsLT - Computes the upper and lower bounds for level K
comment|/// using the< direction. Records them in Bound.
name|void
name|findBoundsLT
argument_list|(
argument|CoefficientInfo *A
argument_list|,
argument|CoefficientInfo *B
argument_list|,
argument|BoundInfo *Bound
argument_list|,
argument|unsigned K
argument_list|)
specifier|const
block|;
comment|/// findBoundsGT - Computes the upper and lower bounds for level K
comment|/// using the> direction. Records them in Bound.
name|void
name|findBoundsGT
argument_list|(
argument|CoefficientInfo *A
argument_list|,
argument|CoefficientInfo *B
argument_list|,
argument|BoundInfo *Bound
argument_list|,
argument|unsigned K
argument_list|)
specifier|const
block|;
comment|/// findBoundsEQ - Computes the upper and lower bounds for level K
comment|/// using the = direction. Records them in Bound.
name|void
name|findBoundsEQ
argument_list|(
argument|CoefficientInfo *A
argument_list|,
argument|CoefficientInfo *B
argument_list|,
argument|BoundInfo *Bound
argument_list|,
argument|unsigned K
argument_list|)
specifier|const
block|;
comment|/// intersectConstraints - Updates X with the intersection
comment|/// of the Constraints X and Y. Returns true if X has changed.
name|bool
name|intersectConstraints
argument_list|(
name|Constraint
operator|*
name|X
argument_list|,
specifier|const
name|Constraint
operator|*
name|Y
argument_list|)
block|;
comment|/// propagate - Review the constraints, looking for opportunities
comment|/// to simplify a subscript pair (Src and Dst).
comment|/// Return true if some simplification occurs.
comment|/// If the simplification isn't exact (that is, if it is conservative
comment|/// in terms of dependence), set consistent to false.
name|bool
name|propagate
argument_list|(
specifier|const
name|SCEV
operator|*
operator|&
name|Src
argument_list|,
specifier|const
name|SCEV
operator|*
operator|&
name|Dst
argument_list|,
name|SmallBitVector
operator|&
name|Loops
argument_list|,
name|SmallVectorImpl
operator|<
name|Constraint
operator|>
operator|&
name|Constraints
argument_list|,
name|bool
operator|&
name|Consistent
argument_list|)
block|;
comment|/// propagateDistance - Attempt to propagate a distance
comment|/// constraint into a subscript pair (Src and Dst).
comment|/// Return true if some simplification occurs.
comment|/// If the simplification isn't exact (that is, if it is conservative
comment|/// in terms of dependence), set consistent to false.
name|bool
name|propagateDistance
argument_list|(
specifier|const
name|SCEV
operator|*
operator|&
name|Src
argument_list|,
specifier|const
name|SCEV
operator|*
operator|&
name|Dst
argument_list|,
name|Constraint
operator|&
name|CurConstraint
argument_list|,
name|bool
operator|&
name|Consistent
argument_list|)
block|;
comment|/// propagatePoint - Attempt to propagate a point
comment|/// constraint into a subscript pair (Src and Dst).
comment|/// Return true if some simplification occurs.
name|bool
name|propagatePoint
argument_list|(
specifier|const
name|SCEV
operator|*
operator|&
name|Src
argument_list|,
specifier|const
name|SCEV
operator|*
operator|&
name|Dst
argument_list|,
name|Constraint
operator|&
name|CurConstraint
argument_list|)
block|;
comment|/// propagateLine - Attempt to propagate a line
comment|/// constraint into a subscript pair (Src and Dst).
comment|/// Return true if some simplification occurs.
comment|/// If the simplification isn't exact (that is, if it is conservative
comment|/// in terms of dependence), set consistent to false.
name|bool
name|propagateLine
argument_list|(
specifier|const
name|SCEV
operator|*
operator|&
name|Src
argument_list|,
specifier|const
name|SCEV
operator|*
operator|&
name|Dst
argument_list|,
name|Constraint
operator|&
name|CurConstraint
argument_list|,
name|bool
operator|&
name|Consistent
argument_list|)
block|;
comment|/// findCoefficient - Given a linear SCEV,
comment|/// return the coefficient corresponding to specified loop.
comment|/// If there isn't one, return the SCEV constant 0.
comment|/// For example, given a*i + b*j + c*k, returning the coefficient
comment|/// corresponding to the j loop would yield b.
specifier|const
name|SCEV
operator|*
name|findCoefficient
argument_list|(
argument|const SCEV *Expr
argument_list|,
argument|const Loop *TargetLoop
argument_list|)
specifier|const
block|;
comment|/// zeroCoefficient - Given a linear SCEV,
comment|/// return the SCEV given by zeroing out the coefficient
comment|/// corresponding to the specified loop.
comment|/// For example, given a*i + b*j + c*k, zeroing the coefficient
comment|/// corresponding to the j loop would yield a*i + c*k.
specifier|const
name|SCEV
operator|*
name|zeroCoefficient
argument_list|(
argument|const SCEV *Expr
argument_list|,
argument|const Loop *TargetLoop
argument_list|)
specifier|const
block|;
comment|/// addToCoefficient - Given a linear SCEV Expr,
comment|/// return the SCEV given by adding some Value to the
comment|/// coefficient corresponding to the specified TargetLoop.
comment|/// For example, given a*i + b*j + c*k, adding 1 to the coefficient
comment|/// corresponding to the j loop would yield a*i + (b+1)*j + c*k.
specifier|const
name|SCEV
operator|*
name|addToCoefficient
argument_list|(
argument|const SCEV *Expr
argument_list|,
argument|const Loop *TargetLoop
argument_list|,
argument|const SCEV *Value
argument_list|)
specifier|const
block|;
comment|/// updateDirection - Update direction vector entry
comment|/// based on the current constraint.
name|void
name|updateDirection
argument_list|(
argument|Dependence::DVEntry&Level
argument_list|,
argument|const Constraint&CurConstraint
argument_list|)
specifier|const
block|;
name|bool
name|tryDelinearize
argument_list|(
argument|const SCEV *SrcSCEV
argument_list|,
argument|const SCEV *DstSCEV
argument_list|,
argument|SmallVectorImpl<Subscript>&Pair
argument_list|)
specifier|const
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Class identification, replacement for typeinfo
name|DependenceAnalysis
argument_list|()
operator|:
name|FunctionPass
argument_list|(
argument|ID
argument_list|)
block|{
name|initializeDependenceAnalysisPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;     }
name|bool
name|runOnFunction
argument_list|(
name|Function
operator|&
name|F
argument_list|)
block|;
name|void
name|releaseMemory
argument_list|()
block|;
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&
argument_list|)
specifier|const
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&
argument_list|,
argument|const Module * =
literal|0
argument_list|)
specifier|const
block|;   }
decl_stmt|;
comment|// class DependenceAnalysis
comment|/// createDependenceAnalysisPass - This creates an instance of the
comment|/// DependenceAnalysis pass.
name|FunctionPass
modifier|*
name|createDependenceAnalysisPass
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

