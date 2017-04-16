begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- TargetPassConfig.h - Code Generation pass options -------*- C++ -*-===//
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
comment|/// Target-Independent Code Generator Pass Configuration Options pass.
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
name|LLVM_CODEGEN_TARGETPASSCONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_TARGETPASSCONFIG_H
end_define

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CodeGen.h"
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
name|PassConfigImpl
decl_stmt|;
name|class
name|ScheduleDAGInstrs
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
struct_decl|struct
name|MachineSchedContext
struct_decl|;
comment|// The old pass manager infrastructure is hidden in a legacy namespace now.
name|namespace
name|legacy
block|{
name|class
name|PassManagerBase
decl_stmt|;
block|}
name|using
name|legacy
operator|::
name|PassManagerBase
expr_stmt|;
comment|/// Discriminated union of Pass ID types.
comment|///
comment|/// The PassConfig API prefers dealing with IDs because they are safer and more
comment|/// efficient. IDs decouple configuration from instantiation. This way, when a
comment|/// pass is overriden, it isn't unnecessarily instantiated. It is also unsafe to
comment|/// refer to a Pass pointer after adding it to a pass manager, which deletes
comment|/// redundant pass instances.
comment|///
comment|/// However, it is convient to directly instantiate target passes with
comment|/// non-default ctors. These often don't have a registered PassInfo. Rather than
comment|/// force all target passes to implement the pass registry boilerplate, allow
comment|/// the PassConfig API to handle either type.
comment|///
comment|/// AnalysisID is sadly char*, so PointerIntPair won't work.
name|class
name|IdentifyingPassPtr
block|{
union|union
block|{
name|AnalysisID
name|ID
decl_stmt|;
name|Pass
modifier|*
name|P
decl_stmt|;
block|}
union|;
name|bool
name|IsInstance
decl_stmt|;
name|public
label|:
name|IdentifyingPassPtr
argument_list|()
operator|:
name|P
argument_list|(
name|nullptr
argument_list|)
operator|,
name|IsInstance
argument_list|(
argument|false
argument_list|)
block|{}
name|IdentifyingPassPtr
argument_list|(
argument|AnalysisID IDPtr
argument_list|)
operator|:
name|ID
argument_list|(
name|IDPtr
argument_list|)
operator|,
name|IsInstance
argument_list|(
argument|false
argument_list|)
block|{}
name|IdentifyingPassPtr
argument_list|(
name|Pass
operator|*
name|InstancePtr
argument_list|)
operator|:
name|P
argument_list|(
name|InstancePtr
argument_list|)
operator|,
name|IsInstance
argument_list|(
argument|true
argument_list|)
block|{}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|P
return|;
block|}
name|bool
name|isInstance
argument_list|()
specifier|const
block|{
return|return
name|IsInstance
return|;
block|}
name|AnalysisID
name|getID
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|IsInstance
operator|&&
literal|"Not a Pass ID"
argument_list|)
block|;
return|return
name|ID
return|;
block|}
name|Pass
operator|*
name|getInstance
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|IsInstance
operator|&&
literal|"Not a Pass Instance"
argument_list|)
block|;
return|return
name|P
return|;
block|}
block|}
empty_stmt|;
name|template
operator|<
operator|>
expr|struct
name|isPodLike
operator|<
name|IdentifyingPassPtr
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|; }
expr_stmt|;
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
name|private
operator|:
name|PassManagerBase
operator|*
name|PM
block|;
name|AnalysisID
name|StartBefore
operator|=
name|nullptr
block|;
name|AnalysisID
name|StartAfter
operator|=
name|nullptr
block|;
name|AnalysisID
name|StopBefore
operator|=
name|nullptr
block|;
name|AnalysisID
name|StopAfter
operator|=
name|nullptr
block|;
name|bool
name|Started
block|;
name|bool
name|Stopped
block|;
name|bool
name|AddingMachinePasses
block|;
name|protected
operator|:
name|TargetMachine
operator|*
name|TM
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
comment|/// Require processing of functions such that callees are generated before
comment|/// callers.
name|bool
name|RequireCodeGenSCCOrder
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
operator|~
name|TargetPassConfig
argument_list|()
name|override
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
block|;
comment|/// Set the StartAfter, StartBefore and StopAfter passes to allow running only
comment|/// a portion of the normal code-gen pass sequence.
comment|///
comment|/// If the StartAfter and StartBefore pass ID is zero, then compilation will
comment|/// begin at the normal point; otherwise, clear the Started flag to indicate
comment|/// that passes should not be added until the starting pass is seen.  If the
comment|/// Stop pass ID is zero, then compilation will continue to the end.
comment|///
comment|/// This function expects that at least one of the StartAfter or the
comment|/// StartBefore pass IDs is null.
name|void
name|setStartStopPasses
argument_list|(
argument|AnalysisID StartBefore
argument_list|,
argument|AnalysisID StartAfter
argument_list|,
argument|AnalysisID StopBefore
argument_list|,
argument|AnalysisID StopAfter
argument_list|)
block|{
name|assert
argument_list|(
operator|!
operator|(
name|StartBefore
operator|&&
name|StartAfter
operator|)
operator|&&
literal|"Start after and start before passes are given"
argument_list|)
block|;
name|assert
argument_list|(
operator|!
operator|(
name|StopBefore
operator|&&
name|StopAfter
operator|)
operator|&&
literal|"Stop after and stop before passed are given"
argument_list|)
block|;
name|this
operator|->
name|StartBefore
operator|=
name|StartBefore
block|;
name|this
operator|->
name|StartAfter
operator|=
name|StartAfter
block|;
name|this
operator|->
name|StopBefore
operator|=
name|StopBefore
block|;
name|this
operator|->
name|StopAfter
operator|=
name|StopAfter
block|;
name|Started
operator|=
operator|(
name|StartAfter
operator|==
name|nullptr
operator|)
operator|&&
operator|(
name|StartBefore
operator|==
name|nullptr
operator|)
block|;   }
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
name|bool
name|requiresCodeGenSCCOrder
argument_list|()
specifier|const
block|{
return|return
name|RequireCodeGenSCCOrder
return|;
block|}
name|void
name|setRequiresCodeGenSCCOrder
argument_list|(
argument|bool Enable = true
argument_list|)
block|{
name|setOpt
argument_list|(
name|RequireCodeGenSCCOrder
argument_list|,
name|Enable
argument_list|)
block|;   }
comment|/// Allow the target to override a specific pass without overriding the pass
comment|/// pipeline. When passes are added to the standard pipeline at the
comment|/// point where StandardID is expected, add TargetID in its place.
name|void
name|substitutePass
argument_list|(
argument|AnalysisID StandardID
argument_list|,
argument|IdentifyingPassPtr TargetID
argument_list|)
block|;
comment|/// Insert InsertedPassID pass after TargetPassID pass.
name|void
name|insertPass
argument_list|(
argument|AnalysisID TargetPassID
argument_list|,
argument|IdentifyingPassPtr InsertedPassID
argument_list|,
argument|bool VerifyAfter = true
argument_list|,
argument|bool PrintAfter = true
argument_list|)
block|;
comment|/// Allow the target to enable a specific standard pass by default.
name|void
name|enablePass
argument_list|(
argument|AnalysisID PassID
argument_list|)
block|{
name|substitutePass
argument_list|(
name|PassID
argument_list|,
name|PassID
argument_list|)
block|; }
comment|/// Allow the target to disable a specific standard pass by default.
name|void
name|disablePass
argument_list|(
argument|AnalysisID PassID
argument_list|)
block|{
name|substitutePass
argument_list|(
name|PassID
argument_list|,
name|IdentifyingPassPtr
argument_list|()
argument_list|)
block|;   }
comment|/// Return the pass substituted for StandardID by the target.
comment|/// If no substitution exists, return StandardID.
name|IdentifyingPassPtr
name|getPassSubstitution
argument_list|(
argument|AnalysisID StandardID
argument_list|)
specifier|const
block|;
comment|/// Return true if the pass has been substituted by the target or
comment|/// overridden on the command line.
name|bool
name|isPassSubstitutedOrOverridden
argument_list|(
argument|AnalysisID ID
argument_list|)
specifier|const
block|;
comment|/// Return true if the optimized regalloc pipeline is enabled.
name|bool
name|getOptimizeRegAlloc
argument_list|()
specifier|const
block|;
comment|/// Return true if shrink wrapping is enabled.
name|bool
name|getEnableShrinkWrap
argument_list|()
specifier|const
block|;
comment|/// Return true if the default global register allocator is in use and
comment|/// has not be overriden on the command line with '-regalloc=...'
name|bool
name|usingDefaultRegAlloc
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
comment|/// Add passes to lower exception handling for the code generator.
name|void
name|addPassesToHandleExceptions
argument_list|()
block|;
comment|/// Add pass to prepare the LLVM IR for code generation. This should be done
comment|/// before exception handling preparation passes.
name|virtual
name|void
name|addCodeGenPrepare
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
comment|/// This method should install an IR translator pass, which converts from
comment|/// LLVM code to machine instructions with possibly generic opcodes.
name|virtual
name|bool
name|addIRTranslator
argument_list|()
block|{
return|return
name|true
return|;
block|}
comment|/// This method may be implemented by targets that want to run passes
comment|/// immediately before legalization.
name|virtual
name|void
name|addPreLegalizeMachineIR
argument_list|()
block|{}
comment|/// This method should install a legalize pass, which converts the instruction
comment|/// sequence into one that can be selected by the target.
name|virtual
name|bool
name|addLegalizeMachineIR
argument_list|()
block|{
return|return
name|true
return|;
block|}
comment|/// This method may be implemented by targets that want to run passes
comment|/// immediately before the register bank selection.
name|virtual
name|void
name|addPreRegBankSelect
argument_list|()
block|{}
comment|/// This method should install a register bank selector pass, which
comment|/// assigns register banks to virtual registers without a register
comment|/// class or register banks.
name|virtual
name|bool
name|addRegBankSelect
argument_list|()
block|{
return|return
name|true
return|;
block|}
comment|/// This method may be implemented by targets that want to run passes
comment|/// immediately before the (global) instruction selection.
name|virtual
name|void
name|addPreGlobalInstructionSelect
argument_list|()
block|{}
comment|/// This method should install a (global) instruction selector pass, which
comment|/// converts possibly generic instructions to fully target-specific
comment|/// instructions, thereby constraining all generic virtual registers to
comment|/// register classes.
name|virtual
name|bool
name|addGlobalInstructionSelect
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
comment|/// Create an instance of ScheduleDAGInstrs to be run within the standard
comment|/// MachineScheduler pass for this function and target at the current
comment|/// optimization level.
comment|///
comment|/// This can also be used to plug a new MachineSchedStrategy into an instance
comment|/// of the standard ScheduleDAGMI:
comment|///   return new ScheduleDAGMI(C, make_unique<MyStrategy>(C), /*RemoveKillFlags=*/false)
comment|///
comment|/// Return NULL to select the default (generic) machine scheduler.
name|virtual
name|ScheduleDAGInstrs
operator|*
name|createMachineScheduler
argument_list|(
argument|MachineSchedContext *C
argument_list|)
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
comment|/// Similar to createMachineScheduler but used when postRA machine scheduling
comment|/// is enabled.
name|virtual
name|ScheduleDAGInstrs
operator|*
name|createPostMachineScheduler
argument_list|(
argument|MachineSchedContext *C
argument_list|)
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
comment|/// printAndVerify - Add a pass to dump then verify the machine function, if
comment|/// those steps are enabled.
comment|///
name|void
name|printAndVerify
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Banner
argument_list|)
block|;
comment|/// Add a pass to print the machine function if printing is enabled.
name|void
name|addPrintPass
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Banner
argument_list|)
block|;
comment|/// Add a pass to perform basic verification of the machine function if
comment|/// verification is enabled.
name|void
name|addVerifyPass
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Banner
argument_list|)
block|;
comment|/// Check whether or not GlobalISel should be enabled by default.
comment|/// Fallback/abort behavior is controlled via other methods.
name|virtual
name|bool
name|isGlobalISelEnabled
argument_list|()
specifier|const
block|;
comment|/// Check whether or not GlobalISel should abort on error.
comment|/// When this is disable, GlobalISel will fall back on SDISel instead of
comment|/// erroring out.
name|virtual
name|bool
name|isGlobalISelAbortEnabled
argument_list|()
specifier|const
block|;
comment|/// Check whether or not a diagnostic should be emitted when GlobalISel
comment|/// uses the fallback path. In other words, it will emit a diagnostic
comment|/// when GlobalISel failed and isGlobalISelAbortEnabled is false.
name|virtual
name|bool
name|reportDiagnosticWhenGlobalISelFallback
argument_list|()
specifier|const
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
comment|/// Add passes that optimize instruction level parallelism for out-of-order
comment|/// targets. These passes are run while the machine code is still in SSA
comment|/// form, so they can use MachineTraceMetrics to control their heuristics.
comment|///
comment|/// All passes added here should preserve the MachineDominatorTree,
comment|/// MachineLoopInfo, and MachineTraceMetrics analyses.
name|virtual
name|bool
name|addILPOpts
argument_list|()
block|{
return|return
name|false
return|;
block|}
comment|/// This method may be implemented by targets that want to run passes
comment|/// immediately before register allocation.
name|virtual
name|void
name|addPreRegAlloc
argument_list|()
block|{ }
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
comment|/// addPreRewrite - Add passes to the optimized register allocation pipeline
comment|/// after register allocation is complete, but before virtual registers are
comment|/// rewritten to physical registers.
comment|///
comment|/// These passes must preserve VirtRegMap and LiveIntervals, and when running
comment|/// after RABasic or RAGreedy, they should take advantage of LiveRegMatrix.
comment|/// When these passes run, VirtRegMap contains legal physreg assignments for
comment|/// all virtual registers.
name|virtual
name|bool
name|addPreRewrite
argument_list|()
block|{
return|return
name|false
return|;
block|}
comment|/// This method may be implemented by targets that want to run passes after
comment|/// register allocation pass pipeline but before prolog-epilog insertion.
name|virtual
name|void
name|addPostRegAlloc
argument_list|()
block|{ }
comment|/// Add passes that optimize machine instructions after register allocation.
name|virtual
name|void
name|addMachineLateOptimization
argument_list|()
block|;
comment|/// This method may be implemented by targets that want to run passes after
comment|/// prolog-epilog insertion and before the second instruction scheduling pass.
name|virtual
name|void
name|addPreSched2
argument_list|()
block|{ }
comment|/// addGCPasses - Add late codegen passes that analyze code for garbage
comment|/// collection. This should return true if GC info should be printed after
comment|/// these passes.
name|virtual
name|bool
name|addGCPasses
argument_list|()
block|;
comment|/// Add standard basic block placement passes.
name|virtual
name|void
name|addBlockPlacement
argument_list|()
block|;
comment|/// This pass may be implemented by targets that want to run passes
comment|/// immediately before machine code is emitted.
name|virtual
name|void
name|addPreEmitPass
argument_list|()
block|{ }
comment|/// Utilities for targets to add passes to the pass manager.
comment|///
comment|/// Add a CodeGen pass at this point in the pipeline after checking overrides.
comment|/// Return the pass that was added, or zero if no pass was added.
comment|/// @p printAfter    if true and adding a machine function pass add an extra
comment|///                  machine printer pass afterwards
comment|/// @p verifyAfter   if true and adding a machine function pass add an extra
comment|///                  machine verification pass afterwards.
name|AnalysisID
name|addPass
argument_list|(
argument|AnalysisID PassID
argument_list|,
argument|bool verifyAfter = true
argument_list|,
argument|bool printAfter = true
argument_list|)
block|;
comment|/// Add a pass to the PassManager if that pass is supposed to be run, as
comment|/// determined by the StartAfter and StopAfter options. Takes ownership of the
comment|/// pass.
comment|/// @p printAfter    if true and adding a machine function pass add an extra
comment|///                  machine printer pass afterwards
comment|/// @p verifyAfter   if true and adding a machine function pass add an extra
comment|///                  machine verification pass afterwards.
name|void
name|addPass
argument_list|(
argument|Pass *P
argument_list|,
argument|bool verifyAfter = true
argument_list|,
argument|bool printAfter = true
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
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

