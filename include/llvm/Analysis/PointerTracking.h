begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PointerTracking.h - Pointer Bounds Tracking --------------*- C++ -*-===//
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
comment|// This file implements tracking of pointer bounds.
end_comment

begin_comment
comment|// It knows that the libc functions "calloc" and "realloc" allocate memory, thus
end_comment

begin_comment
comment|// you should avoid using this pass if they mean something else for your
end_comment

begin_comment
comment|// language.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// All methods assume that the pointer is not NULL, if it is then the returned
end_comment

begin_comment
comment|// allocation size is wrong, and the result from checkLimits is wrong too.
end_comment

begin_comment
comment|// It also assumes that pointers are valid, and that it is not analyzing a
end_comment

begin_comment
comment|// use-after-free scenario.
end_comment

begin_comment
comment|// Due to these limitations the "size" returned by these methods should be
end_comment

begin_comment
comment|// considered as either 0 or the returned size.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Another analysis pass should be used to find use-after-free/NULL dereference
end_comment

begin_comment
comment|// bugs.
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
name|LLVM_ANALYSIS_POINTERTRACKING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_POINTERTRACKING_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/Dominators.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Instructions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/PredIteratorCache.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DominatorTree
decl_stmt|;
name|class
name|ScalarEvolution
decl_stmt|;
name|class
name|SCEV
decl_stmt|;
name|class
name|Loop
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
comment|// Result from solver, assuming pointer is not NULL,
comment|// and it is not a use-after-free situation.
enum|enum
name|SolverResult
block|{
name|AlwaysFalse
block|,
comment|// always false with above constraints
name|AlwaysTrue
block|,
comment|// always true with above constraints
name|Unknown
comment|// it can sometimes be true, sometimes false, or it is undecided
block|}
enum|;
name|class
name|PointerTracking
range|:
name|public
name|FunctionPass
block|{
name|public
operator|:
typedef|typedef
name|ICmpInst
operator|::
name|Predicate
name|Predicate
expr_stmt|;
specifier|static
name|char
name|ID
decl_stmt|;
name|PointerTracking
argument_list|()
expr_stmt|;
name|virtual
name|bool
name|doInitialization
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
comment|// If this pointer directly points to an allocation, return
comment|// the number of elements of type Ty allocated.
comment|// Otherwise return CouldNotCompute.
comment|// Since allocations can fail by returning NULL, the real element count
comment|// for every allocation is either 0 or the value returned by this function.
specifier|const
name|SCEV
modifier|*
name|getAllocationElementCount
argument_list|(
name|Value
operator|*
name|P
argument_list|)
decl|const
decl_stmt|;
comment|// Same as getAllocationSize() but returns size in bytes.
comment|// We consider one byte as 8 bits.
specifier|const
name|SCEV
modifier|*
name|getAllocationSizeInBytes
argument_list|(
name|Value
operator|*
name|V
argument_list|)
decl|const
decl_stmt|;
comment|// Given a Pointer, determine a base pointer of known size, and an offset
comment|// therefrom.
comment|// When unable to determine, sets Base to NULL, and Limit/Offset to
comment|// CouldNotCompute.
comment|// BaseSize, and Offset are in bytes: Pointer == Base + Offset
name|void
name|getPointerOffset
argument_list|(
name|Value
operator|*
name|Pointer
argument_list|,
name|Value
operator|*
operator|&
name|Base
argument_list|,
specifier|const
name|SCEV
operator|*
operator|&
name|BaseSize
argument_list|,
specifier|const
name|SCEV
operator|*
operator|&
name|Offset
argument_list|)
decl|const
decl_stmt|;
comment|// Compares the 2 scalar evolution expressions according to predicate,
comment|// and if it can prove that the result is always true or always false
comment|// return AlwaysTrue/AlwaysFalse. Otherwise it returns Unknown.
name|enum
name|SolverResult
name|compareSCEV
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|A
parameter_list|,
name|Predicate
name|Pred
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|B
parameter_list|,
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|// Determines whether the condition LHS<Pred> RHS is sufficient
comment|// for the condition A<Pred> B to hold.
comment|// Currently only ULT/ULE is supported.
comment|// This errs on the side of returning false.
name|bool
name|conditionSufficient
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|LHS
parameter_list|,
name|Predicate
name|Pred1
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|RHS
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|A
parameter_list|,
name|Predicate
name|Pred2
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|B
parameter_list|,
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|// Determines whether Offset is known to be always in [0, Limit) bounds.
comment|// This errs on the side of returning Unknown.
name|enum
name|SolverResult
name|checkLimits
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|Offset
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|Limit
parameter_list|,
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
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
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|AU
argument_list|)
decl|const
decl_stmt|;
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
name|Function
modifier|*
name|FF
decl_stmt|;
name|TargetData
modifier|*
name|TD
decl_stmt|;
name|ScalarEvolution
modifier|*
name|SE
decl_stmt|;
name|LoopInfo
modifier|*
name|LI
decl_stmt|;
name|DominatorTree
modifier|*
name|DT
decl_stmt|;
name|Function
modifier|*
name|callocFunc
decl_stmt|;
name|Function
modifier|*
name|reallocFunc
decl_stmt|;
name|PredIteratorCache
name|predCache
decl_stmt|;
name|SmallPtrSet
operator|<
specifier|const
name|SCEV
operator|*
operator|,
literal|1
operator|>
name|analyzing
expr_stmt|;
name|enum
name|SolverResult
name|isLoopGuardedBy
argument_list|(
specifier|const
name|Loop
operator|*
name|L
argument_list|,
name|Predicate
name|Pred
argument_list|,
specifier|const
name|SCEV
operator|*
name|A
argument_list|,
specifier|const
name|SCEV
operator|*
name|B
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|bool
name|isMonotonic
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|)
function_decl|;
name|bool
name|scevPositive
argument_list|(
specifier|const
name|SCEV
operator|*
name|A
argument_list|,
specifier|const
name|Loop
operator|*
name|L
argument_list|,
name|bool
name|strict
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
name|bool
name|conditionSufficient
parameter_list|(
name|Value
modifier|*
name|Cond
parameter_list|,
name|bool
name|negated
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|A
parameter_list|,
name|Predicate
name|Pred
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|B
parameter_list|)
function_decl|;
name|Value
modifier|*
name|getConditionToReach
argument_list|(
name|BasicBlock
operator|*
name|A
argument_list|,
name|DomTreeNodeBase
operator|<
name|BasicBlock
operator|>
operator|*
name|B
argument_list|,
name|bool
operator|&
name|negated
argument_list|)
decl_stmt|;
name|Value
modifier|*
name|getConditionToReach
parameter_list|(
name|BasicBlock
modifier|*
name|A
parameter_list|,
name|BasicBlock
modifier|*
name|B
parameter_list|,
name|bool
modifier|&
name|negated
parameter_list|)
function_decl|;
specifier|const
name|SCEV
modifier|*
name|computeAllocationCount
argument_list|(
name|Value
operator|*
name|P
argument_list|,
specifier|const
name|Type
operator|*
operator|&
name|Ty
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|SCEV
modifier|*
name|computeAllocationCountForType
argument_list|(
name|Value
operator|*
name|P
argument_list|,
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
decl|const
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

