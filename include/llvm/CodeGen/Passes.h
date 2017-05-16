begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Passes.h - Target independent code generation passes ----*- C++ -*-===//
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
comment|// This file defines interfaces to access the target independent code generation
end_comment

begin_comment
comment|// passes provided by the LLVM backend.
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
name|LLVM_CODEGEN_PASSES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_PASSES_H
end_define

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FunctionPass
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineFunctionPass
decl_stmt|;
name|class
name|ModulePass
decl_stmt|;
name|class
name|Pass
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_comment
comment|/// List of target independent CodeGen pass IDs.
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|FunctionPass
modifier|*
name|createAtomicExpandPass
parameter_list|(
specifier|const
name|TargetMachine
modifier|*
name|TM
parameter_list|)
function_decl|;
comment|/// createUnreachableBlockEliminationPass - The LLVM code generator does not
comment|/// work well with unreachable basic blocks (what live ranges make sense for a
comment|/// block that cannot be reached?).  As such, a code generator should either
comment|/// not instruction select unreachable blocks, or run this pass as its
comment|/// last LLVM modifying pass to clean up blocks that are not reachable from
comment|/// the entry block.
name|FunctionPass
modifier|*
name|createUnreachableBlockEliminationPass
parameter_list|()
function_decl|;
comment|/// Insert mcount-like function calls.
name|FunctionPass
modifier|*
name|createCountingFunctionInserterPass
parameter_list|()
function_decl|;
comment|/// MachineFunctionPrinter pass - This pass prints out the machine function to
comment|/// the given stream as a debugging tool.
name|MachineFunctionPass
modifier|*
name|createMachineFunctionPrinterPass
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Banner
operator|=
literal|""
argument_list|)
decl_stmt|;
comment|/// MIRPrinting pass - this pass prints out the LLVM IR into the given stream
comment|/// using the MIR serialization format.
name|MachineFunctionPass
modifier|*
name|createPrintMIRPass
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
comment|/// This pass resets a MachineFunction when it has the FailedISel property
comment|/// as if it was just created.
comment|/// If EmitFallbackDiag is true, the pass will emit a
comment|/// DiagnosticInfoISelFallback for every MachineFunction it resets.
comment|/// If AbortOnFailedISel is true, abort compilation instead of resetting.
name|MachineFunctionPass
modifier|*
name|createResetMachineFunctionPass
parameter_list|(
name|bool
name|EmitFallbackDiag
parameter_list|,
name|bool
name|AbortOnFailedISel
parameter_list|)
function_decl|;
comment|/// createCodeGenPreparePass - Transform the code to expose more pattern
comment|/// matching during instruction selection.
name|FunctionPass
modifier|*
name|createCodeGenPreparePass
parameter_list|(
specifier|const
name|TargetMachine
modifier|*
name|TM
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// createScalarizeMaskedMemIntrinPass - Replace masked load, store, gather
comment|/// and scatter intrinsics with scalar code when target doesn't support them.
name|FunctionPass
modifier|*
name|createScalarizeMaskedMemIntrinPass
parameter_list|()
function_decl|;
comment|/// AtomicExpandID -- Lowers atomic operations in terms of either cmpxchg
comment|/// load-linked/store-conditional loops.
specifier|extern
name|char
modifier|&
name|AtomicExpandID
decl_stmt|;
comment|/// MachineLoopInfo - This pass is a loop analysis pass.
specifier|extern
name|char
modifier|&
name|MachineLoopInfoID
decl_stmt|;
comment|/// MachineDominators - This pass is a machine dominators analysis pass.
specifier|extern
name|char
modifier|&
name|MachineDominatorsID
decl_stmt|;
comment|/// MachineDominanaceFrontier - This pass is a machine dominators analysis pass.
specifier|extern
name|char
modifier|&
name|MachineDominanceFrontierID
decl_stmt|;
comment|/// MachineRegionInfo - This pass computes SESE regions for machine functions.
specifier|extern
name|char
modifier|&
name|MachineRegionInfoPassID
decl_stmt|;
comment|/// EdgeBundles analysis - Bundle machine CFG edges.
specifier|extern
name|char
modifier|&
name|EdgeBundlesID
decl_stmt|;
comment|/// LiveVariables pass - This pass computes the set of blocks in which each
comment|/// variable is life and sets machine operand kill flags.
specifier|extern
name|char
modifier|&
name|LiveVariablesID
decl_stmt|;
comment|/// PHIElimination - This pass eliminates machine instruction PHI nodes
comment|/// by inserting copy instructions.  This destroys SSA information, but is the
comment|/// desired input for some register allocators.  This pass is "required" by
comment|/// these register allocator like this: AU.addRequiredID(PHIEliminationID);
specifier|extern
name|char
modifier|&
name|PHIEliminationID
decl_stmt|;
comment|/// LiveIntervals - This analysis keeps track of the live ranges of virtual
comment|/// and physical registers.
specifier|extern
name|char
modifier|&
name|LiveIntervalsID
decl_stmt|;
comment|/// LiveStacks pass. An analysis keeping track of the liveness of stack slots.
specifier|extern
name|char
modifier|&
name|LiveStacksID
decl_stmt|;
comment|/// TwoAddressInstruction - This pass reduces two-address instructions to
comment|/// use two operands. This destroys SSA information but it is desired by
comment|/// register allocators.
specifier|extern
name|char
modifier|&
name|TwoAddressInstructionPassID
decl_stmt|;
comment|/// ProcessImpicitDefs pass - This pass removes IMPLICIT_DEFs.
specifier|extern
name|char
modifier|&
name|ProcessImplicitDefsID
decl_stmt|;
comment|/// RegisterCoalescer - This pass merges live ranges to eliminate copies.
specifier|extern
name|char
modifier|&
name|RegisterCoalescerID
decl_stmt|;
comment|/// MachineScheduler - This pass schedules machine instructions.
specifier|extern
name|char
modifier|&
name|MachineSchedulerID
decl_stmt|;
comment|/// PostMachineScheduler - This pass schedules machine instructions postRA.
specifier|extern
name|char
modifier|&
name|PostMachineSchedulerID
decl_stmt|;
comment|/// SpillPlacement analysis. Suggest optimal placement of spill code between
comment|/// basic blocks.
specifier|extern
name|char
modifier|&
name|SpillPlacementID
decl_stmt|;
comment|/// ShrinkWrap pass. Look for the best place to insert save and restore
comment|// instruction and update the MachineFunctionInfo with that information.
specifier|extern
name|char
modifier|&
name|ShrinkWrapID
decl_stmt|;
comment|/// LiveRangeShrink pass. Move instruction close to its definition to shrink
comment|/// the definition's live range.
specifier|extern
name|char
modifier|&
name|LiveRangeShrinkID
decl_stmt|;
comment|/// Greedy register allocator.
specifier|extern
name|char
modifier|&
name|RAGreedyID
decl_stmt|;
comment|/// VirtRegRewriter pass. Rewrite virtual registers to physical registers as
comment|/// assigned in VirtRegMap.
specifier|extern
name|char
modifier|&
name|VirtRegRewriterID
decl_stmt|;
comment|/// UnreachableMachineBlockElimination - This pass removes unreachable
comment|/// machine basic blocks.
specifier|extern
name|char
modifier|&
name|UnreachableMachineBlockElimID
decl_stmt|;
comment|/// DeadMachineInstructionElim - This pass removes dead machine instructions.
specifier|extern
name|char
modifier|&
name|DeadMachineInstructionElimID
decl_stmt|;
comment|/// This pass adds dead/undef flags after analyzing subregister lanes.
specifier|extern
name|char
modifier|&
name|DetectDeadLanesID
decl_stmt|;
comment|/// FastRegisterAllocation Pass - This pass register allocates as fast as
comment|/// possible. It is best suited for debug code where live ranges are short.
comment|///
name|FunctionPass
modifier|*
name|createFastRegisterAllocator
parameter_list|()
function_decl|;
comment|/// BasicRegisterAllocation Pass - This pass implements a degenerate global
comment|/// register allocator using the basic regalloc framework.
comment|///
name|FunctionPass
modifier|*
name|createBasicRegisterAllocator
parameter_list|()
function_decl|;
comment|/// Greedy register allocation pass - This pass implements a global register
comment|/// allocator for optimized builds.
comment|///
name|FunctionPass
modifier|*
name|createGreedyRegisterAllocator
parameter_list|()
function_decl|;
comment|/// PBQPRegisterAllocation Pass - This pass implements the Partitioned Boolean
comment|/// Quadratic Prograaming (PBQP) based register allocator.
comment|///
name|FunctionPass
modifier|*
name|createDefaultPBQPRegisterAllocator
parameter_list|()
function_decl|;
comment|/// PrologEpilogCodeInserter - This pass inserts prolog and epilog code,
comment|/// and eliminates abstract frame references.
specifier|extern
name|char
modifier|&
name|PrologEpilogCodeInserterID
decl_stmt|;
name|MachineFunctionPass
modifier|*
name|createPrologEpilogInserterPass
parameter_list|(
specifier|const
name|TargetMachine
modifier|*
name|TM
parameter_list|)
function_decl|;
comment|/// ExpandPostRAPseudos - This pass expands pseudo instructions after
comment|/// register allocation.
specifier|extern
name|char
modifier|&
name|ExpandPostRAPseudosID
decl_stmt|;
comment|/// createPostRAHazardRecognizer - This pass runs the post-ra hazard
comment|/// recognizer.
specifier|extern
name|char
modifier|&
name|PostRAHazardRecognizerID
decl_stmt|;
comment|/// createPostRAScheduler - This pass performs post register allocation
comment|/// scheduling.
specifier|extern
name|char
modifier|&
name|PostRASchedulerID
decl_stmt|;
comment|/// BranchFolding - This pass performs machine code CFG based
comment|/// optimizations to delete branches to branches, eliminate branches to
comment|/// successor blocks (creating fall throughs), and eliminating branches over
comment|/// branches.
specifier|extern
name|char
modifier|&
name|BranchFolderPassID
decl_stmt|;
comment|/// BranchRelaxation - This pass replaces branches that need to jump further
comment|/// than is supported by a branch instruction.
specifier|extern
name|char
modifier|&
name|BranchRelaxationPassID
decl_stmt|;
comment|/// MachineFunctionPrinterPass - This pass prints out MachineInstr's.
specifier|extern
name|char
modifier|&
name|MachineFunctionPrinterPassID
decl_stmt|;
comment|/// MIRPrintingPass - this pass prints out the LLVM IR using the MIR
comment|/// serialization format.
specifier|extern
name|char
modifier|&
name|MIRPrintingPassID
decl_stmt|;
comment|/// TailDuplicate - Duplicate blocks with unconditional branches
comment|/// into tails of their predecessors.
specifier|extern
name|char
modifier|&
name|TailDuplicateID
decl_stmt|;
comment|/// MachineTraceMetrics - This pass computes critical path and CPU resource
comment|/// usage in an ensemble of traces.
specifier|extern
name|char
modifier|&
name|MachineTraceMetricsID
decl_stmt|;
comment|/// EarlyIfConverter - This pass performs if-conversion on SSA form by
comment|/// inserting cmov instructions.
specifier|extern
name|char
modifier|&
name|EarlyIfConverterID
decl_stmt|;
comment|/// This pass performs instruction combining using trace metrics to estimate
comment|/// critical-path and resource depth.
specifier|extern
name|char
modifier|&
name|MachineCombinerID
decl_stmt|;
comment|/// StackSlotColoring - This pass performs stack coloring and merging.
comment|/// It merges disjoint allocas to reduce the stack size.
specifier|extern
name|char
modifier|&
name|StackColoringID
decl_stmt|;
comment|/// IfConverter - This pass performs machine code if conversion.
specifier|extern
name|char
modifier|&
name|IfConverterID
decl_stmt|;
name|FunctionPass
modifier|*
name|createIfConverter
argument_list|(
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
specifier|const
name|MachineFunction
operator|&
argument_list|)
operator|>
name|Ftor
argument_list|)
decl_stmt|;
comment|/// MachineBlockPlacement - This pass places basic blocks based on branch
comment|/// probabilities.
specifier|extern
name|char
modifier|&
name|MachineBlockPlacementID
decl_stmt|;
comment|/// MachineBlockPlacementStats - This pass collects statistics about the
comment|/// basic block placement using branch probabilities and block frequency
comment|/// information.
specifier|extern
name|char
modifier|&
name|MachineBlockPlacementStatsID
decl_stmt|;
comment|/// GCLowering Pass - Used by gc.root to perform its default lowering
comment|/// operations.
name|FunctionPass
modifier|*
name|createGCLoweringPass
parameter_list|()
function_decl|;
comment|/// ShadowStackGCLowering - Implements the custom lowering mechanism
comment|/// used by the shadow stack GC.  Only runs on functions which opt in to
comment|/// the shadow stack collector.
name|FunctionPass
modifier|*
name|createShadowStackGCLoweringPass
parameter_list|()
function_decl|;
comment|/// GCMachineCodeAnalysis - Target-independent pass to mark safe points
comment|/// in machine code. Must be added very late during code generation, just
comment|/// prior to output, and importantly after all CFG transformations (such as
comment|/// branch folding).
specifier|extern
name|char
modifier|&
name|GCMachineCodeAnalysisID
decl_stmt|;
comment|/// Creates a pass to print GC metadata.
comment|///
name|FunctionPass
modifier|*
name|createGCInfoPrinter
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
comment|/// MachineCSE - This pass performs global CSE on machine instructions.
specifier|extern
name|char
modifier|&
name|MachineCSEID
decl_stmt|;
comment|/// ImplicitNullChecks - This pass folds null pointer checks into nearby
comment|/// memory operations.
specifier|extern
name|char
modifier|&
name|ImplicitNullChecksID
decl_stmt|;
comment|/// MachineLICM - This pass performs LICM on machine instructions.
specifier|extern
name|char
modifier|&
name|MachineLICMID
decl_stmt|;
comment|/// MachineSinking - This pass performs sinking on machine instructions.
specifier|extern
name|char
modifier|&
name|MachineSinkingID
decl_stmt|;
comment|/// MachineCopyPropagation - This pass performs copy propagation on
comment|/// machine instructions.
specifier|extern
name|char
modifier|&
name|MachineCopyPropagationID
decl_stmt|;
comment|/// PeepholeOptimizer - This pass performs peephole optimizations -
comment|/// like extension and comparison eliminations.
specifier|extern
name|char
modifier|&
name|PeepholeOptimizerID
decl_stmt|;
comment|/// OptimizePHIs - This pass optimizes machine instruction PHIs
comment|/// to take advantage of opportunities created during DAG legalization.
specifier|extern
name|char
modifier|&
name|OptimizePHIsID
decl_stmt|;
comment|/// StackSlotColoring - This pass performs stack slot coloring.
specifier|extern
name|char
modifier|&
name|StackSlotColoringID
decl_stmt|;
comment|/// \brief This pass lays out funclets contiguously.
specifier|extern
name|char
modifier|&
name|FuncletLayoutID
decl_stmt|;
comment|/// This pass inserts the XRay instrumentation sleds if they are supported by
comment|/// the target platform.
specifier|extern
name|char
modifier|&
name|XRayInstrumentationID
decl_stmt|;
comment|/// This pass inserts FEntry calls
specifier|extern
name|char
modifier|&
name|FEntryInserterID
decl_stmt|;
comment|/// \brief This pass implements the "patchable-function" attribute.
specifier|extern
name|char
modifier|&
name|PatchableFunctionID
decl_stmt|;
comment|/// createStackProtectorPass - This pass adds stack protectors to functions.
comment|///
name|FunctionPass
modifier|*
name|createStackProtectorPass
parameter_list|(
specifier|const
name|TargetMachine
modifier|*
name|TM
parameter_list|)
function_decl|;
comment|/// createMachineVerifierPass - This pass verifies cenerated machine code
comment|/// instructions for correctness.
comment|///
name|FunctionPass
modifier|*
name|createMachineVerifierPass
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Banner
argument_list|)
decl_stmt|;
comment|/// createDwarfEHPass - This pass mulches exception handling code into a form
comment|/// adapted to code generation.  Required if using dwarf exception handling.
name|FunctionPass
modifier|*
name|createDwarfEHPass
parameter_list|(
specifier|const
name|TargetMachine
modifier|*
name|TM
parameter_list|)
function_decl|;
comment|/// createWinEHPass - Prepares personality functions used by MSVC on Windows,
comment|/// in addition to the Itanium LSDA based personalities.
name|FunctionPass
modifier|*
name|createWinEHPass
parameter_list|(
specifier|const
name|TargetMachine
modifier|*
name|TM
parameter_list|)
function_decl|;
comment|/// createSjLjEHPreparePass - This pass adapts exception handling code to use
comment|/// the GCC-style builtin setjmp/longjmp (sjlj) to handling EH control flow.
comment|///
name|FunctionPass
modifier|*
name|createSjLjEHPreparePass
parameter_list|()
function_decl|;
comment|/// LocalStackSlotAllocation - This pass assigns local frame indices to stack
comment|/// slots relative to one another and allocates base registers to access them
comment|/// when it is estimated by the target to be out of range of normal frame
comment|/// pointer or stack pointer index addressing.
specifier|extern
name|char
modifier|&
name|LocalStackSlotAllocationID
decl_stmt|;
comment|/// ExpandISelPseudos - This pass expands pseudo-instructions.
specifier|extern
name|char
modifier|&
name|ExpandISelPseudosID
decl_stmt|;
comment|/// UnpackMachineBundles - This pass unpack machine instruction bundles.
specifier|extern
name|char
modifier|&
name|UnpackMachineBundlesID
decl_stmt|;
name|FunctionPass
modifier|*
name|createUnpackMachineBundles
argument_list|(
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
specifier|const
name|MachineFunction
operator|&
argument_list|)
operator|>
name|Ftor
argument_list|)
decl_stmt|;
comment|/// FinalizeMachineBundles - This pass finalize machine instruction
comment|/// bundles (created earlier, e.g. during pre-RA scheduling).
specifier|extern
name|char
modifier|&
name|FinalizeMachineBundlesID
decl_stmt|;
comment|/// StackMapLiveness - This pass analyses the register live-out set of
comment|/// stackmap/patchpoint intrinsics and attaches the calculated information to
comment|/// the intrinsic for later emission to the StackMap.
specifier|extern
name|char
modifier|&
name|StackMapLivenessID
decl_stmt|;
comment|/// LiveDebugValues pass
specifier|extern
name|char
modifier|&
name|LiveDebugValuesID
decl_stmt|;
comment|/// createJumpInstrTables - This pass creates jump-instruction tables.
name|ModulePass
modifier|*
name|createJumpInstrTablesPass
parameter_list|()
function_decl|;
comment|/// createForwardControlFlowIntegrityPass - This pass adds control-flow
comment|/// integrity.
name|ModulePass
modifier|*
name|createForwardControlFlowIntegrityPass
parameter_list|()
function_decl|;
comment|/// InterleavedAccess Pass - This pass identifies and matches interleaved
comment|/// memory accesses to target specific intrinsics.
comment|///
name|FunctionPass
modifier|*
name|createInterleavedAccessPass
parameter_list|(
specifier|const
name|TargetMachine
modifier|*
name|TM
parameter_list|)
function_decl|;
comment|/// LowerEmuTLS - This pass generates __emutls_[vt].xyz variables for all
comment|/// TLS variables for the emulated TLS model.
comment|///
name|ModulePass
modifier|*
name|createLowerEmuTLSPass
parameter_list|(
specifier|const
name|TargetMachine
modifier|*
name|TM
parameter_list|)
function_decl|;
comment|/// This pass lowers the @llvm.load.relative intrinsic to instructions.
comment|/// This is unsafe to do earlier because a pass may combine the constant
comment|/// initializer into the load, which may result in an overflowing evaluation.
name|ModulePass
modifier|*
name|createPreISelIntrinsicLoweringPass
parameter_list|()
function_decl|;
comment|/// GlobalMerge - This pass merges internal (by default) globals into structs
comment|/// to enable reuse of a base pointer by indexed addressing modes.
comment|/// It can also be configured to focus on size optimizations only.
comment|///
name|Pass
modifier|*
name|createGlobalMergePass
parameter_list|(
specifier|const
name|TargetMachine
modifier|*
name|TM
parameter_list|,
name|unsigned
name|MaximalOffset
parameter_list|,
name|bool
name|OnlyOptimizeForSize
init|=
name|false
parameter_list|,
name|bool
name|MergeExternalByDefault
init|=
name|false
parameter_list|)
function_decl|;
comment|/// This pass splits the stack into a safe stack and an unsafe stack to
comment|/// protect against stack-based overflow vulnerabilities.
name|FunctionPass
modifier|*
name|createSafeStackPass
parameter_list|(
specifier|const
name|TargetMachine
modifier|*
name|TM
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// This pass detects subregister lanes in a virtual register that are used
comment|/// independently of other lanes and splits them into separate virtual
comment|/// registers.
specifier|extern
name|char
modifier|&
name|RenameIndependentSubregsID
decl_stmt|;
comment|/// This pass is executed POST-RA to collect which physical registers are
comment|/// preserved by given machine function.
name|FunctionPass
modifier|*
name|createRegUsageInfoCollector
parameter_list|()
function_decl|;
comment|/// Return a MachineFunction pass that identifies call sites
comment|/// and propagates register usage information of callee to caller
comment|/// if available with PysicalRegisterUsageInfo pass.
name|FunctionPass
modifier|*
name|createRegUsageInfoPropPass
parameter_list|()
function_decl|;
comment|/// This pass performs software pipelining on machine instructions.
specifier|extern
name|char
modifier|&
name|MachinePipelinerID
decl_stmt|;
comment|/// This pass frees the memory occupied by the MachineFunction.
name|FunctionPass
modifier|*
name|createFreeMachineFunctionPass
parameter_list|()
function_decl|;
comment|/// This pass combine basic blocks guarded by the same branch.
specifier|extern
name|char
modifier|&
name|BranchCoalescingID
decl_stmt|;
comment|/// This pass performs outlining on machine instructions directly before
comment|/// printing assembly.
name|ModulePass
modifier|*
name|createMachineOutlinerPass
parameter_list|()
function_decl|;
comment|/// This pass expands the experimental reduction intrinsics into sequences of
comment|/// shuffles.
name|FunctionPass
modifier|*
name|createExpandReductionsPass
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_comment
comment|/// Target machine pass initializer for passes with dependencies. Use with
end_comment

begin_comment
comment|/// INITIALIZE_TM_PASS_END.
end_comment

begin_define
define|#
directive|define
name|INITIALIZE_TM_PASS_BEGIN
value|INITIALIZE_PASS_BEGIN
end_define

begin_comment
comment|/// Target machine pass initializer for passes with dependencies. Use with
end_comment

begin_comment
comment|/// INITIALIZE_TM_PASS_BEGIN.
end_comment

begin_define
define|#
directive|define
name|INITIALIZE_TM_PASS_END
parameter_list|(
name|passName
parameter_list|,
name|arg
parameter_list|,
name|name
parameter_list|,
name|cfg
parameter_list|,
name|analysis
parameter_list|)
define|\
value|PassInfo *PI = new PassInfo(                                                 \       name, arg,&passName::ID,                                                \       PassInfo::NormalCtor_t(callDefaultCtor<passName>), cfg, analysis,        \       PassInfo::TargetMachineCtor_t(callTargetMachineCtor<passName>));         \   Registry.registerPass(*PI, true);                                            \   return PI;                                                                   \   }                                                                            \   static llvm::once_flag Initialize##passName##PassFlag;                       \   void llvm::initialize##passName##Pass(PassRegistry&Registry) {              \     llvm::call_once(Initialize##passName##PassFlag,                            \                     initialize##passName##PassOnce, std::ref(Registry));       \   }
end_define

begin_comment
comment|/// This initializer registers TargetMachine constructor, so the pass being
end_comment

begin_comment
comment|/// initialized can use target dependent interfaces. Please do not move this
end_comment

begin_comment
comment|/// macro to be together with INITIALIZE_PASS, which is a complete target
end_comment

begin_comment
comment|/// independent initializer, and we don't want to make libScalarOpts depend
end_comment

begin_comment
comment|/// on libCodeGen.
end_comment

begin_define
define|#
directive|define
name|INITIALIZE_TM_PASS
parameter_list|(
name|passName
parameter_list|,
name|arg
parameter_list|,
name|name
parameter_list|,
name|cfg
parameter_list|,
name|analysis
parameter_list|)
define|\
value|INITIALIZE_TM_PASS_BEGIN(passName, arg, name, cfg, analysis)                 \   INITIALIZE_TM_PASS_END(passName, arg, name, cfg, analysis)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

