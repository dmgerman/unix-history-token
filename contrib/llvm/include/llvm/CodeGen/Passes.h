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
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
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
name|MachineFunctionPass
decl_stmt|;
name|class
name|PassInfo
decl_stmt|;
name|class
name|TargetLowering
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
specifier|extern
name|char
modifier|&
name|NoPassID
decl_stmt|;
comment|// Allow targets to choose not to run a pass.
name|class
name|PassConfigImpl
decl_stmt|;
comment|/// Target-Independent Code Generator Pass Configuration Options.
comment|///
comment|/// This is an ImmutablePass solely for the purpose of exposing CodeGen options
comment|/// to the internals of other CodeGen passes.
name|class
name|TargetPassConfig
range|:
name|public
name|ImmutablePass
block|{
name|public
operator|:
comment|/// Pseudo Pass IDs. These are defined within TargetPassConfig because they
comment|/// are unregistered pass IDs. They are only useful for use with
comment|/// TargetPassConfig APIs to identify multiple occurrences of the same pass.
comment|///
comment|/// EarlyTailDuplicate - A clone of the TailDuplicate pass that runs early
comment|/// during codegen, on SSA form.
specifier|static
name|char
name|EarlyTailDuplicateID
block|;
comment|/// PostRAMachineLICM - A clone of the LICM pass that runs during late machine
comment|/// optimization after regalloc.
specifier|static
name|char
name|PostRAMachineLICMID
block|;
name|protected
operator|:
name|TargetMachine
operator|*
name|TM
block|;
name|PassManagerBase
operator|*
name|PM
block|;
name|PassConfigImpl
operator|*
name|Impl
block|;
comment|// Internal data structures
name|bool
name|Initialized
block|;
comment|// Flagged after all passes are configured.
comment|// Target Pass Options
comment|// Targets provide a default setting, user flags override.
comment|//
name|bool
name|DisableVerify
block|;
comment|/// Default setting for -enable-tail-merge on this target.
name|bool
name|EnableTailMerge
block|;
name|public
operator|:
name|TargetPassConfig
argument_list|(
name|TargetMachine
operator|*
name|tm
argument_list|,
name|PassManagerBase
operator|&
name|pm
argument_list|)
block|;
comment|// Dummy constructor.
name|TargetPassConfig
argument_list|()
block|;
name|virtual
operator|~
name|TargetPassConfig
argument_list|()
block|;
specifier|static
name|char
name|ID
block|;
comment|/// Get the right type of TargetMachine for this target.
name|template
operator|<
name|typename
name|TMC
operator|>
name|TMC
operator|&
name|getTM
argument_list|()
specifier|const
block|{
return|return
operator|*
name|static_cast
operator|<
name|TMC
operator|*
operator|>
operator|(
name|TM
operator|)
return|;
block|}
specifier|const
name|TargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
block|{
return|return
name|TM
operator|->
name|getTargetLowering
argument_list|()
return|;
block|}
comment|//
name|void
name|setInitialized
argument_list|()
block|{
name|Initialized
operator|=
name|true
block|; }
name|CodeGenOpt
operator|::
name|Level
name|getOptLevel
argument_list|()
specifier|const
block|{
return|return
name|TM
operator|->
name|getOptLevel
argument_list|()
return|;
block|}
name|void
name|setDisableVerify
argument_list|(
argument|bool Disable
argument_list|)
block|{
name|setOpt
argument_list|(
name|DisableVerify
argument_list|,
name|Disable
argument_list|)
block|; }
name|bool
name|getEnableTailMerge
argument_list|()
specifier|const
block|{
return|return
name|EnableTailMerge
return|;
block|}
name|void
name|setEnableTailMerge
argument_list|(
argument|bool Enable
argument_list|)
block|{
name|setOpt
argument_list|(
name|EnableTailMerge
argument_list|,
name|Enable
argument_list|)
block|; }
comment|/// Allow the target to override a specific pass without overriding the pass
comment|/// pipeline. When passes are added to the standard pipeline at the
comment|/// point where StadardID is expected, add TargetID in its place.
name|void
name|substitutePass
argument_list|(
name|char
operator|&
name|StandardID
argument_list|,
name|char
operator|&
name|TargetID
argument_list|)
block|;
comment|/// Allow the target to enable a specific standard pass by default.
name|void
name|enablePass
argument_list|(
argument|char&ID
argument_list|)
block|{
name|substitutePass
argument_list|(
name|ID
argument_list|,
name|ID
argument_list|)
block|; }
comment|/// Allow the target to disable a specific standard pass by default.
name|void
name|disablePass
argument_list|(
argument|char&ID
argument_list|)
block|{
name|substitutePass
argument_list|(
name|ID
argument_list|,
name|NoPassID
argument_list|)
block|; }
comment|/// Return the pass ssubtituted for StandardID by the target.
comment|/// If no substitution exists, return StandardID.
name|AnalysisID
name|getPassSubstitution
argument_list|(
argument|AnalysisID StandardID
argument_list|)
specifier|const
block|;
comment|/// Return true if the optimized regalloc pipeline is enabled.
name|bool
name|getOptimizeRegAlloc
argument_list|()
specifier|const
block|;
comment|/// Add common target configurable passes that perform LLVM IR to IR
comment|/// transforms following machine independent optimization.
name|virtual
name|void
name|addIRPasses
argument_list|()
block|;
comment|/// Add common passes that perform LLVM IR to IR transforms in preparation for
comment|/// instruction selection.
name|virtual
name|void
name|addISelPrepare
argument_list|()
block|;
comment|/// addInstSelector - This method should install an instruction selector pass,
comment|/// which converts from LLVM code to machine instructions.
name|virtual
name|bool
name|addInstSelector
argument_list|()
block|{
return|return
name|true
return|;
block|}
comment|/// Add the complete, standard set of LLVM CodeGen passes.
comment|/// Fully developed targets will not generally override this.
name|virtual
name|void
name|addMachinePasses
argument_list|()
block|;
name|protected
operator|:
comment|// Helper to verify the analysis is really immutable.
name|void
name|setOpt
argument_list|(
argument|bool&Opt
argument_list|,
argument|bool Val
argument_list|)
block|;
comment|/// Methods with trivial inline returns are convenient points in the common
comment|/// codegen pass pipeline where targets may insert passes. Methods with
comment|/// out-of-line standard implementations are major CodeGen stages called by
comment|/// addMachinePasses. Some targets may override major stages when inserting
comment|/// passes is insufficient, but maintaining overriden stages is more work.
comment|///
comment|/// addPreISelPasses - This method should add any "last minute" LLVM->LLVM
comment|/// passes (which are run just before instruction selector).
name|virtual
name|bool
name|addPreISel
argument_list|()
block|{
return|return
name|true
return|;
block|}
comment|/// addMachineSSAOptimization - Add standard passes that optimize machine
comment|/// instructions in SSA form.
name|virtual
name|void
name|addMachineSSAOptimization
argument_list|()
block|;
comment|/// addPreRegAlloc - This method may be implemented by targets that want to
comment|/// run passes immediately before register allocation. This should return
comment|/// true if -print-machineinstrs should print after these passes.
name|virtual
name|bool
name|addPreRegAlloc
argument_list|()
block|{
return|return
name|false
return|;
block|}
comment|/// createTargetRegisterAllocator - Create the register allocator pass for
comment|/// this target at the current optimization level.
name|virtual
name|FunctionPass
operator|*
name|createTargetRegisterAllocator
argument_list|(
argument|bool Optimized
argument_list|)
block|;
comment|/// addFastRegAlloc - Add the minimum set of target-independent passes that
comment|/// are required for fast register allocation.
name|virtual
name|void
name|addFastRegAlloc
argument_list|(
name|FunctionPass
operator|*
name|RegAllocPass
argument_list|)
block|;
comment|/// addOptimizedRegAlloc - Add passes related to register allocation.
comment|/// LLVMTargetMachine provides standard regalloc passes for most targets.
name|virtual
name|void
name|addOptimizedRegAlloc
argument_list|(
name|FunctionPass
operator|*
name|RegAllocPass
argument_list|)
block|;
comment|/// addFinalizeRegAlloc - This method may be implemented by targets that want
comment|/// to run passes within the regalloc pipeline, immediately after the register
comment|/// allocation pass itself. These passes run as soon as virtual regisiters
comment|/// have been rewritten to physical registers but before and other postRA
comment|/// optimization happens. Targets that have marked instructions for bundling
comment|/// must have finalized those bundles by the time these passes have run,
comment|/// because subsequent passes are not guaranteed to be bundle-aware.
name|virtual
name|bool
name|addFinalizeRegAlloc
argument_list|()
block|{
return|return
name|false
return|;
block|}
comment|/// addPostRegAlloc - This method may be implemented by targets that want to
comment|/// run passes after register allocation pass pipeline but before
comment|/// prolog-epilog insertion.  This should return true if -print-machineinstrs
comment|/// should print after these passes.
name|virtual
name|bool
name|addPostRegAlloc
argument_list|()
block|{
return|return
name|false
return|;
block|}
comment|/// Add passes that optimize machine instructions after register allocation.
name|virtual
name|void
name|addMachineLateOptimization
argument_list|()
block|;
comment|/// addPreSched2 - This method may be implemented by targets that want to
comment|/// run passes after prolog-epilog insertion and before the second instruction
comment|/// scheduling pass.  This should return true if -print-machineinstrs should
comment|/// print after these passes.
name|virtual
name|bool
name|addPreSched2
argument_list|()
block|{
return|return
name|false
return|;
block|}
comment|/// Add standard basic block placement passes.
name|virtual
name|void
name|addBlockPlacement
argument_list|()
block|;
comment|/// addPreEmitPass - This pass may be implemented by targets that want to run
comment|/// passes immediately before machine code is emitted.  This should return
comment|/// true if -print-machineinstrs should print out the code after the passes.
name|virtual
name|bool
name|addPreEmitPass
argument_list|()
block|{
return|return
name|false
return|;
block|}
comment|/// Utilities for targets to add passes to the pass manager.
comment|///
comment|/// Add a CodeGen pass at this point in the pipeline after checking overrides.
comment|/// Return the pass that was added, or NoPassID.
name|AnalysisID
name|addPass
argument_list|(
name|char
operator|&
name|ID
argument_list|)
block|;
comment|/// addMachinePasses helper to create the target-selected or overriden
comment|/// regalloc pass.
name|FunctionPass
operator|*
name|createRegAllocPass
argument_list|(
argument|bool Optimized
argument_list|)
block|;
comment|/// printAndVerify - Add a pass to dump then verify the machine function, if
comment|/// those steps are enabled.
comment|///
name|void
name|printAndVerify
argument_list|(
argument|const char *Banner
argument_list|)
specifier|const
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_comment
comment|/// List of target independent CodeGen pass IDs.
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
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
comment|/// MachineLoopInfo - This pass is a loop analysis pass.
specifier|extern
name|char
modifier|&
name|MachineLoopInfoID
decl_stmt|;
comment|/// MachineLoopRanges - This pass is an on-demand loop coverage analysis.
specifier|extern
name|char
modifier|&
name|MachineLoopRangesID
decl_stmt|;
comment|/// MachineDominators - This pass is a machine dominators analysis pass.
specifier|extern
name|char
modifier|&
name|MachineDominatorsID
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
comment|/// StrongPHIElimination - This pass eliminates machine instruction PHI
comment|/// nodes by inserting copy instructions.  This destroys SSA information, but
comment|/// is the desired input for some register allocators.  This pass is
comment|/// "required" by these register allocator like this:
comment|///    AU.addRequiredID(PHIEliminationID);
comment|///  This pass is still in development
specifier|extern
name|char
modifier|&
name|StrongPHIEliminationID
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
comment|/// SpillPlacement analysis. Suggest optimal placement of spill code between
comment|/// basic blocks.
specifier|extern
name|char
modifier|&
name|SpillPlacementID
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
comment|/// ExpandPostRAPseudos - This pass expands pseudo instructions after
comment|/// register allocation.
specifier|extern
name|char
modifier|&
name|ExpandPostRAPseudosID
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
comment|/// TailDuplicate - Duplicate blocks with unconditional branches
comment|/// into tails of their predecessors.
specifier|extern
name|char
modifier|&
name|TailDuplicateID
decl_stmt|;
comment|/// IfConverter - This pass performs machine code if conversion.
specifier|extern
name|char
modifier|&
name|IfConverterID
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
comment|/// Code Placement - This pass optimize code placement and aligns loop
comment|/// headers to target specific alignment boundary.
specifier|extern
name|char
modifier|&
name|CodePlacementOptID
decl_stmt|;
comment|/// GCLowering Pass - Performs target-independent LLVM IR transformations for
comment|/// highly portable strategies.
comment|///
name|FunctionPass
modifier|*
name|createGCLoweringPass
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
comment|/// Deleter Pass - Releases GC metadata.
comment|///
name|FunctionPass
modifier|*
name|createGCInfoDeleter
parameter_list|()
function_decl|;
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
comment|/// createStackProtectorPass - This pass adds stack protectors to functions.
comment|///
name|FunctionPass
modifier|*
name|createStackProtectorPass
parameter_list|(
specifier|const
name|TargetLowering
modifier|*
name|tli
parameter_list|)
function_decl|;
comment|/// createMachineVerifierPass - This pass verifies cenerated machine code
comment|/// instructions for correctness.
comment|///
name|FunctionPass
modifier|*
name|createMachineVerifierPass
parameter_list|(
specifier|const
name|char
modifier|*
name|Banner
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// createDwarfEHPass - This pass mulches exception handling code into a form
comment|/// adapted to code generation.  Required if using dwarf exception handling.
name|FunctionPass
modifier|*
name|createDwarfEHPass
parameter_list|(
specifier|const
name|TargetMachine
modifier|*
name|tm
parameter_list|)
function_decl|;
comment|/// createSjLjEHPreparePass - This pass adapts exception handling code to use
comment|/// the GCC-style builtin setjmp/longjmp (sjlj) to handling EH control flow.
comment|///
name|FunctionPass
modifier|*
name|createSjLjEHPreparePass
parameter_list|(
specifier|const
name|TargetLowering
modifier|*
name|tli
parameter_list|)
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
comment|/// createExecutionDependencyFixPass - This pass fixes execution time
comment|/// problems with dependent instructions, such as switching execution
comment|/// domains to match.
comment|///
comment|/// The pass will examine instructions using and defining registers in RC.
comment|///
name|FunctionPass
modifier|*
name|createExecutionDependencyFixPass
parameter_list|(
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
parameter_list|)
function_decl|;
comment|/// UnpackMachineBundles - This pass unpack machine instruction bundles.
specifier|extern
name|char
modifier|&
name|UnpackMachineBundlesID
decl_stmt|;
comment|/// FinalizeMachineBundles - This pass finalize machine instruction
comment|/// bundles (created earlier, e.g. during pre-RA scheduling).
specifier|extern
name|char
modifier|&
name|FinalizeMachineBundlesID
decl_stmt|;
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

