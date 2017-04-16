begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Scalar.h - Scalar Transformations -----------------------*- C++ -*-===//
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
comment|// This header file defines prototypes for accessor functions that expose passes
end_comment

begin_comment
comment|// in the Scalar transformations library.
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
name|LLVM_TRANSFORMS_SCALAR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_SCALAR_H
end_define

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
name|BasicBlockPass
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|class
name|ModulePass
decl_stmt|;
name|class
name|Pass
decl_stmt|;
name|class
name|GetElementPtrInst
decl_stmt|;
name|class
name|PassInfo
decl_stmt|;
name|class
name|TerminatorInst
decl_stmt|;
name|class
name|TargetLowering
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// ConstantPropagation - A worklist driven constant propagation pass
comment|//
name|FunctionPass
modifier|*
name|createConstantPropagationPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// AlignmentFromAssumptions - Use assume intrinsics to set load/store
comment|// alignments.
comment|//
name|FunctionPass
modifier|*
name|createAlignmentFromAssumptionsPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// SCCP - Sparse conditional constant propagation.
comment|//
name|FunctionPass
modifier|*
name|createSCCPPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// DeadInstElimination - This pass quickly removes trivially dead instructions
comment|// without modifying the CFG of the function.  It is a BasicBlockPass, so it
comment|// runs efficiently when queued next to other BasicBlockPass's.
comment|//
name|Pass
modifier|*
name|createDeadInstEliminationPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// DeadCodeElimination - This pass is more powerful than DeadInstElimination,
comment|// because it is worklist driven that can potentially revisit instructions when
comment|// their other instructions become dead, to eliminate chains of dead
comment|// computations.
comment|//
name|FunctionPass
modifier|*
name|createDeadCodeEliminationPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// DeadStoreElimination - This pass deletes stores that are post-dominated by
comment|// must-aliased stores and are not loaded used between the stores.
comment|//
name|FunctionPass
modifier|*
name|createDeadStoreEliminationPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// AggressiveDCE - This pass uses the SSA based Aggressive DCE algorithm.  This
comment|// algorithm assumes instructions are dead until proven otherwise, which makes
comment|// it more successful are removing non-obviously dead instructions.
comment|//
name|FunctionPass
modifier|*
name|createAggressiveDCEPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// GuardWidening - An optimization over the @llvm.experimental.guard intrinsic
comment|// that (optimistically) combines multiple guards into one to have fewer checks
comment|// at runtime.
comment|//
name|FunctionPass
modifier|*
name|createGuardWideningPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// BitTrackingDCE - This pass uses a bit-tracking DCE algorithm in order to
comment|// remove computations of dead bits.
comment|//
name|FunctionPass
modifier|*
name|createBitTrackingDCEPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// SROA - Replace aggregates or pieces of aggregates with scalar SSA values.
comment|//
name|FunctionPass
modifier|*
name|createSROAPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// InductiveRangeCheckElimination - Transform loops to elide range checks on
comment|// linear functions of the induction variable.
comment|//
name|Pass
modifier|*
name|createInductiveRangeCheckEliminationPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// InductionVariableSimplify - Transform induction variables in a program to all
comment|// use a single canonical induction variable per loop.
comment|//
name|Pass
modifier|*
name|createIndVarSimplifyPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// InstructionCombining - Combine instructions to form fewer, simple
comment|// instructions. This pass does not modify the CFG, and has a tendency to make
comment|// instructions dead, so a subsequent DCE pass is useful.
comment|//
comment|// This pass combines things like:
comment|//    %Y = add int 1, %X
comment|//    %Z = add int 1, %Y
comment|// into:
comment|//    %Z = add int 2, %X
comment|//
name|FunctionPass
modifier|*
name|createInstructionCombiningPass
parameter_list|(
name|bool
name|ExpensiveCombines
init|=
name|true
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LICM - This pass is a loop invariant code motion and memory promotion pass.
comment|//
name|Pass
modifier|*
name|createLICMPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoopSink - This pass sinks invariants from preheader to loop body where
comment|// frequency is lower than loop preheader.
comment|//
name|Pass
modifier|*
name|createLoopSinkPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoopPredication - This pass does loop predication on guards.
comment|//
name|Pass
modifier|*
name|createLoopPredicationPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoopInterchange - This pass interchanges loops to provide a more
comment|// cache-friendly memory access patterns.
comment|//
name|Pass
modifier|*
name|createLoopInterchangePass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoopStrengthReduce - This pass is strength reduces GEP instructions that use
comment|// a loop's canonical induction variable as one of their indices.
comment|//
name|Pass
modifier|*
name|createLoopStrengthReducePass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoopUnswitch - This pass is a simple loop unswitching pass.
comment|//
name|Pass
modifier|*
name|createLoopUnswitchPass
parameter_list|(
name|bool
name|OptimizeForSize
init|=
name|false
parameter_list|,
name|bool
name|hasBranchDivergence
init|=
name|false
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoopInstSimplify - This pass simplifies instructions in a loop's body.
comment|//
name|Pass
modifier|*
name|createLoopInstSimplifyPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoopUnroll - This pass is a simple loop unrolling pass.
comment|//
name|Pass
modifier|*
name|createLoopUnrollPass
parameter_list|(
name|int
name|OptLevel
init|=
literal|2
parameter_list|,
name|int
name|Threshold
init|=
operator|-
literal|1
parameter_list|,
name|int
name|Count
init|=
operator|-
literal|1
parameter_list|,
name|int
name|AllowPartial
init|=
operator|-
literal|1
parameter_list|,
name|int
name|Runtime
init|=
operator|-
literal|1
parameter_list|,
name|int
name|UpperBound
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
comment|// Create an unrolling pass for full unrolling that uses exact trip count only.
name|Pass
modifier|*
name|createSimpleLoopUnrollPass
parameter_list|(
name|int
name|OptLevel
init|=
literal|2
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoopReroll - This pass is a simple loop rerolling pass.
comment|//
name|Pass
modifier|*
name|createLoopRerollPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoopRotate - This pass is a simple loop rotating pass.
comment|//
name|Pass
modifier|*
name|createLoopRotatePass
parameter_list|(
name|int
name|MaxHeaderSize
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoopIdiom - This pass recognizes and replaces idioms in loops.
comment|//
name|Pass
modifier|*
name|createLoopIdiomPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoopVersioningLICM - This pass is a loop versioning pass for LICM.
comment|//
name|Pass
modifier|*
name|createLoopVersioningLICMPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// PromoteMemoryToRegister - This pass is used to promote memory references to
comment|// be register references. A simple example of the transformation performed by
comment|// this pass is:
comment|//
comment|//        FROM CODE                           TO CODE
comment|//   %X = alloca i32, i32 1                 ret i32 42
comment|//   store i32 42, i32 *%X
comment|//   %Y = load i32* %X
comment|//   ret i32 %Y
comment|//
name|FunctionPass
modifier|*
name|createPromoteMemoryToRegisterPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// DemoteRegisterToMemoryPass - This pass is used to demote registers to memory
comment|// references. In basically undoes the PromoteMemoryToRegister pass to make cfg
comment|// hacking easier.
comment|//
name|FunctionPass
modifier|*
name|createDemoteRegisterToMemoryPass
parameter_list|()
function_decl|;
specifier|extern
name|char
modifier|&
name|DemoteRegisterToMemoryID
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// Reassociate - This pass reassociates commutative expressions in an order that
comment|// is designed to promote better constant propagation, GCSE, LICM, PRE...
comment|//
comment|// For example:  4 + (x + 5)  ->  x + (4 + 5)
comment|//
name|FunctionPass
modifier|*
name|createReassociatePass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// JumpThreading - Thread control through mult-pred/multi-succ blocks where some
comment|// preds always go to some succ. Thresholds other than minus one override the
comment|// internal BB duplication default threshold.
comment|//
name|FunctionPass
modifier|*
name|createJumpThreadingPass
parameter_list|(
name|int
name|Threshold
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// CFGSimplification - Merge basic blocks, eliminate unreachable blocks,
comment|// simplify terminator instructions, etc...
comment|//
name|FunctionPass
modifier|*
name|createCFGSimplificationPass
argument_list|(
name|int
name|Threshold
operator|=
operator|-
literal|1
argument_list|,
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
specifier|const
name|Function
operator|&
argument_list|)
operator|>
name|Ftor
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LateCFGSimplification - Like CFGSimplification, but may also
comment|// convert switches to lookup tables.
comment|//
name|FunctionPass
modifier|*
name|createLateCFGSimplificationPass
argument_list|(
name|int
name|Threshold
operator|=
operator|-
literal|1
argument_list|,
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
specifier|const
name|Function
operator|&
argument_list|)
operator|>
name|Ftor
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// FlattenCFG - flatten CFG, reduce number of conditional branches by using
comment|// parallel-and and parallel-or mode, etc...
comment|//
name|FunctionPass
modifier|*
name|createFlattenCFGPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// CFG Structurization - Remove irreducible control flow
comment|//
comment|///
comment|/// When \p SkipUniformRegions is true the structizer will not structurize
comment|/// regions that only contain uniform branches.
name|Pass
modifier|*
name|createStructurizeCFGPass
parameter_list|(
name|bool
name|SkipUniformRegions
init|=
name|false
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// BreakCriticalEdges - Break all of the critical edges in the CFG by inserting
comment|// a dummy basic block. This pass may be "required" by passes that cannot deal
comment|// with critical edges. For this usage, a pass must call:
comment|//
comment|//   AU.addRequiredID(BreakCriticalEdgesID);
comment|//
comment|// This pass obviously invalidates the CFG, but can update forward dominator
comment|// (set, immediate dominators, tree, and frontier) information.
comment|//
name|FunctionPass
modifier|*
name|createBreakCriticalEdgesPass
parameter_list|()
function_decl|;
specifier|extern
name|char
modifier|&
name|BreakCriticalEdgesID
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoopSimplify - Insert Pre-header blocks into the CFG for every function in
comment|// the module.  This pass updates dominator information, loop information, and
comment|// does not add critical edges to the CFG.
comment|//
comment|//   AU.addRequiredID(LoopSimplifyID);
comment|//
name|Pass
modifier|*
name|createLoopSimplifyPass
parameter_list|()
function_decl|;
specifier|extern
name|char
modifier|&
name|LoopSimplifyID
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// TailCallElimination - This pass eliminates call instructions to the current
comment|// function which occur immediately before return instructions.
comment|//
name|FunctionPass
modifier|*
name|createTailCallEliminationPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LowerSwitch - This pass converts SwitchInst instructions into a sequence of
comment|// chained binary branch instructions.
comment|//
name|FunctionPass
modifier|*
name|createLowerSwitchPass
parameter_list|()
function_decl|;
specifier|extern
name|char
modifier|&
name|LowerSwitchID
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LowerInvoke - This pass removes invoke instructions, converting them to call
comment|// instructions.
comment|//
name|FunctionPass
modifier|*
name|createLowerInvokePass
parameter_list|()
function_decl|;
specifier|extern
name|char
modifier|&
name|LowerInvokePassID
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LCSSA - This pass inserts phi nodes at loop boundaries to simplify other loop
comment|// optimizations.
comment|//
name|Pass
modifier|*
name|createLCSSAPass
parameter_list|()
function_decl|;
specifier|extern
name|char
modifier|&
name|LCSSAID
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// EarlyCSE - This pass performs a simple and fast CSE pass over the dominator
comment|// tree.
comment|//
name|FunctionPass
modifier|*
name|createEarlyCSEPass
parameter_list|(
name|bool
name|UseMemorySSA
init|=
name|false
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// GVNHoist - This pass performs a simple and fast GVN pass over the dominator
comment|// tree to hoist common expressions from sibling branches.
comment|//
name|FunctionPass
modifier|*
name|createGVNHoistPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// MergedLoadStoreMotion - This pass merges loads and stores in diamonds. Loads
comment|// are hoisted into the header, while stores sink into the footer.
comment|//
name|FunctionPass
modifier|*
name|createMergedLoadStoreMotionPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// GVN - This pass performs global value numbering and redundant load
comment|// elimination cotemporaneously.
comment|//
name|FunctionPass
modifier|*
name|createNewGVNPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// MemCpyOpt - This pass performs optimizations related to eliminating memcpy
comment|// calls and/or combining multiple stores into memset's.
comment|//
name|FunctionPass
modifier|*
name|createMemCpyOptPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoopDeletion - This pass performs DCE of non-infinite loops that it
comment|// can prove are dead.
comment|//
name|Pass
modifier|*
name|createLoopDeletionPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// ConstantHoisting - This pass prepares a function for expensive constants.
comment|//
name|FunctionPass
modifier|*
name|createConstantHoistingPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// InstructionNamer - Give any unnamed non-void instructions "tmp" names.
comment|//
name|FunctionPass
modifier|*
name|createInstructionNamerPass
parameter_list|()
function_decl|;
specifier|extern
name|char
modifier|&
name|InstructionNamerID
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// Sink - Code Sinking
comment|//
name|FunctionPass
modifier|*
name|createSinkingPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LowerAtomic - Lower atomic intrinsics to non-atomic form
comment|//
name|Pass
modifier|*
name|createLowerAtomicPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LowerGuardIntrinsic - Lower guard intrinsics to normal control flow.
comment|//
name|Pass
modifier|*
name|createLowerGuardIntrinsicPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// ValuePropagation - Propagate CFG-derived value information
comment|//
name|Pass
modifier|*
name|createCorrelatedValuePropagationPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// InferAddressSpaces - Modify users of addrspacecast instructions with values
comment|// in the source address space if using the destination address space is slower
comment|// on the target.
comment|//
name|FunctionPass
modifier|*
name|createInferAddressSpacesPass
parameter_list|()
function_decl|;
specifier|extern
name|char
modifier|&
name|InferAddressSpacesID
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// InstructionSimplifier - Remove redundant instructions.
comment|//
name|FunctionPass
modifier|*
name|createInstructionSimplifierPass
parameter_list|()
function_decl|;
specifier|extern
name|char
modifier|&
name|InstructionSimplifierID
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LowerExpectIntrinsics - Removes llvm.expect intrinsics and creates
comment|// "block_weights" metadata.
name|FunctionPass
modifier|*
name|createLowerExpectIntrinsicPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// PartiallyInlineLibCalls - Tries to inline the fast path of library
comment|// calls such as sqrt.
comment|//
name|FunctionPass
modifier|*
name|createPartiallyInlineLibCallsPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// ScalarizerPass - Converts vector operations into scalar operations
comment|//
name|FunctionPass
modifier|*
name|createScalarizerPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// AddDiscriminators - Add DWARF path discriminators to the IR.
name|FunctionPass
modifier|*
name|createAddDiscriminatorsPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// SeparateConstOffsetFromGEP - Split GEPs for better CSE
comment|//
name|FunctionPass
modifier|*
name|createSeparateConstOffsetFromGEPPass
parameter_list|(
specifier|const
name|TargetMachine
modifier|*
name|TM
init|=
name|nullptr
parameter_list|,
name|bool
name|LowerGEP
init|=
name|false
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// SpeculativeExecution - Aggressively hoist instructions to enable
comment|// speculative execution on targets where branches are expensive.
comment|//
name|FunctionPass
modifier|*
name|createSpeculativeExecutionPass
parameter_list|()
function_decl|;
comment|// Same as createSpeculativeExecutionPass, but does nothing unless
comment|// TargetTransformInfo::hasBranchDivergence() is true.
name|FunctionPass
modifier|*
name|createSpeculativeExecutionIfHasBranchDivergencePass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoadCombine - Combine loads into bigger loads.
comment|//
name|BasicBlockPass
modifier|*
name|createLoadCombinePass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// StraightLineStrengthReduce - This pass strength-reduces some certain
comment|// instruction patterns in straight-line code.
comment|//
name|FunctionPass
modifier|*
name|createStraightLineStrengthReducePass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// PlaceSafepoints - Rewrite any IR calls to gc.statepoints and insert any
comment|// safepoint polls (method entry, backedge) that might be required.  This pass
comment|// does not generate explicit relocation sequences - that's handled by
comment|// RewriteStatepointsForGC which can be run at an arbitrary point in the pass
comment|// order following this pass.
comment|//
name|FunctionPass
modifier|*
name|createPlaceSafepointsPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// RewriteStatepointsForGC - Rewrite any gc.statepoints which do not yet have
comment|// explicit relocations to include explicit relocations.
comment|//
name|ModulePass
modifier|*
name|createRewriteStatepointsForGCPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// StripGCRelocates - Remove GC relocates that have been inserted by
comment|// RewriteStatepointsForGC. The resulting IR is incorrect, but this is useful
comment|// for manual inspection.
name|FunctionPass
modifier|*
name|createStripGCRelocatesPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// Float2Int - Demote floats to ints where possible.
comment|//
name|FunctionPass
modifier|*
name|createFloat2IntPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// NaryReassociate - Simplify n-ary operations by reassociation.
comment|//
name|FunctionPass
modifier|*
name|createNaryReassociatePass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoopDistribute - Distribute loops.
comment|//
name|FunctionPass
modifier|*
name|createLoopDistributePass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoopLoadElimination - Perform loop-aware load elimination.
comment|//
name|FunctionPass
modifier|*
name|createLoopLoadEliminationPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoopSimplifyCFG - This pass performs basic CFG simplification on loops,
comment|// primarily to help other loop passes.
comment|//
name|Pass
modifier|*
name|createLoopSimplifyCFGPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoopVersioning - Perform loop multi-versioning.
comment|//
name|FunctionPass
modifier|*
name|createLoopVersioningPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoopDataPrefetch - Perform data prefetching in loops.
comment|//
name|FunctionPass
modifier|*
name|createLoopDataPrefetchPass
parameter_list|()
function_decl|;
comment|///===---------------------------------------------------------------------===//
name|ModulePass
modifier|*
name|createNameAnonGlobalPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LibCallsShrinkWrap - Shrink-wraps a call to function if the result is not
comment|// used.
comment|//
name|FunctionPass
modifier|*
name|createLibCallsShrinkWrapPass
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

