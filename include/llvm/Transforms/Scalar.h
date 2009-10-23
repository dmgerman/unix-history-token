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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FunctionPass
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
comment|// ScalarReplAggregates - Break up alloca's of aggregates into multiple allocas
comment|// if possible.
comment|//
name|FunctionPass
modifier|*
name|createScalarReplAggregatesPass
parameter_list|(
name|signed
name|Threshold
init|=
operator|-
literal|1
parameter_list|)
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
parameter_list|()
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
comment|// LoopStrengthReduce - This pass is strength reduces GEP instructions that use
comment|// a loop's canonical induction variable as one of their indices.  It takes an
comment|// optional parameter used to consult the target machine whether certain
comment|// transformations are profitable.
comment|//
name|Pass
modifier|*
name|createLoopStrengthReducePass
parameter_list|(
specifier|const
name|TargetLowering
modifier|*
name|TLI
init|=
literal|0
parameter_list|)
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
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoopUnroll - This pass is a simple loop unrolling pass.
comment|//
name|Pass
modifier|*
name|createLoopUnrollPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoopRotate - This pass is a simple loop rotating pass.
comment|//
name|Pass
modifier|*
name|createLoopRotatePass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LoopIndexSplit - This pass divides loop's iteration range by spliting loop
comment|// such that each individual loop is executed efficiently.
comment|//
name|Pass
modifier|*
name|createLoopIndexSplitPass
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
specifier|extern
specifier|const
name|PassInfo
modifier|*
specifier|const
name|PromoteMemoryToRegisterID
decl_stmt|;
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
specifier|const
name|PassInfo
modifier|*
specifier|const
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
comment|// CondPropagationPass - This pass propagates information about conditional
comment|// expressions through the program, allowing it to eliminate conditional
comment|// branches in some cases.
comment|//
name|FunctionPass
modifier|*
name|createCondPropagationPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// TailDuplication - Eliminate unconditional branches through controlled code
comment|// duplication, creating simpler CFG structures.
comment|//
name|FunctionPass
modifier|*
name|createTailDuplicationPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// JumpThreading - Thread control through mult-pred/multi-succ blocks where some
comment|// preds always go to some succ.
comment|//
name|FunctionPass
modifier|*
name|createJumpThreadingPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// CFGSimplification - Merge basic blocks, eliminate unreachable blocks,
comment|// simplify terminator instructions, etc...
comment|//
name|FunctionPass
modifier|*
name|createCFGSimplificationPass
parameter_list|()
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
specifier|const
name|PassInfo
modifier|*
specifier|const
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
specifier|const
name|PassInfo
modifier|*
specifier|const
name|LoopSimplifyID
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LowerAllocations - Turn free instructions into @free calls.
comment|//
comment|//   AU.addRequiredID(LowerAllocationsID);
comment|//
name|Pass
modifier|*
name|createLowerAllocationsPass
parameter_list|()
function_decl|;
specifier|extern
specifier|const
name|PassInfo
modifier|*
specifier|const
name|LowerAllocationsID
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
specifier|const
name|PassInfo
modifier|*
specifier|const
name|LowerSwitchID
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// LowerInvoke - This pass converts invoke and unwind instructions to use sjlj
comment|// exception handling mechanisms.  Note that after this pass runs the CFG is not
comment|// entirely accurate (exceptional control flow edges are not correct anymore) so
comment|// only very simple things should be done after the lowerinvoke pass has run
comment|// (like generation of native code).  This should *NOT* be used as a general
comment|// purpose "my LLVM-to-LLVM pass doesn't support the invoke instruction yet"
comment|// lowering pass.
comment|//
name|FunctionPass
modifier|*
name|createLowerInvokePass
parameter_list|(
specifier|const
name|TargetLowering
modifier|*
name|TLI
init|=
literal|0
parameter_list|)
function_decl|;
specifier|extern
specifier|const
name|PassInfo
modifier|*
specifier|const
name|LowerInvokePassID
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// BlockPlacement - This pass reorders basic blocks in order to increase the
comment|// number of fall-through conditional branches.
comment|//
name|FunctionPass
modifier|*
name|createBlockPlacementPass
parameter_list|()
function_decl|;
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
specifier|const
name|PassInfo
modifier|*
specifier|const
name|LCSSAID
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// GVN - This pass performs global value numbering and redundant load
comment|// elimination cotemporaneously.
comment|//
name|FunctionPass
modifier|*
name|createGVNPass
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
comment|/// createSimplifyLibCallsPass - This pass optimizes specific calls to
comment|/// specific well-known (library) functions.
name|FunctionPass
modifier|*
name|createSimplifyLibCallsPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|/// createSimplifyHalfPowrLibCallsPass - This is an experimental pass that
comment|/// optimizes specific half_pow functions.
name|FunctionPass
modifier|*
name|createSimplifyHalfPowrLibCallsPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// CodeGenPrepare - This pass prepares a function for instruction selection.
comment|//
name|FunctionPass
modifier|*
name|createCodeGenPreparePass
parameter_list|(
specifier|const
name|TargetLowering
modifier|*
name|TLI
init|=
literal|0
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// CodeGenLICM - This pass performs late LICM; hoisting constants out of loops.
comment|//
name|Pass
modifier|*
name|createCodeGenLICMPass
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
specifier|const
name|PassInfo
modifier|*
specifier|const
name|InstructionNamerID
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// SSI - This pass converts instructions to Static Single Information form
comment|// on demand.
comment|//
name|FunctionPass
modifier|*
name|createSSIPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// SSI - This pass converts every non-void instuction to Static Single
comment|// Information form.
comment|//
name|FunctionPass
modifier|*
name|createSSIEverythingPass
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

