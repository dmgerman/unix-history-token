begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Parsing, selection, and construction of pass pipelines --*- C++ -*--===//
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
comment|/// \file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Interfaces for registering analysis passes, producing common pass manager
end_comment

begin_comment
comment|/// configurations, and parsing of pass pipelines.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_PASSES_PASSBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_PASSES_PASSBUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/CGSCCPassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/Scalar/LoopPassManager.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
name|class
name|AAManager
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
comment|/// A struct capturing PGO tunables.
struct|struct
name|PGOOptions
block|{
name|std
operator|::
name|string
name|ProfileGenFile
operator|=
literal|""
expr_stmt|;
name|std
operator|::
name|string
name|ProfileUseFile
operator|=
literal|""
expr_stmt|;
name|std
operator|::
name|string
name|SampleProfileFile
operator|=
literal|""
expr_stmt|;
name|bool
name|RunProfileGen
init|=
name|false
decl_stmt|;
block|}
struct|;
comment|/// \brief This class provides access to building LLVM's passes.
comment|///
comment|/// It's members provide the baseline state available to passes during their
comment|/// construction. The \c PassRegistry.def file specifies how to construct all
comment|/// of the built-in passes, and those may reference these members during
comment|/// construction.
name|class
name|PassBuilder
block|{
name|TargetMachine
modifier|*
name|TM
decl_stmt|;
name|Optional
operator|<
name|PGOOptions
operator|>
name|PGOOpt
expr_stmt|;
name|public
label|:
comment|/// \brief LLVM-provided high-level optimization levels.
comment|///
comment|/// This enumerates the LLVM-provided high-level optimization levels. Each
comment|/// level has a specific goal and rationale.
enum|enum
name|OptimizationLevel
block|{
comment|/// Disable as many optimizations as possible. This doesn't completely
comment|/// disable the optimizer in all cases, for example always_inline functions
comment|/// can be required to be inlined for correctness.
name|O0
block|,
comment|/// Optimize quickly without destroying debuggability.
comment|///
comment|/// FIXME: The current and historical behavior of this level does *not*
comment|/// agree with this goal, but we would like to move toward this goal in the
comment|/// future.
comment|///
comment|/// This level is tuned to produce a result from the optimizer as quickly
comment|/// as possible and to avoid destroying debuggability. This tends to result
comment|/// in a very good development mode where the compiled code will be
comment|/// immediately executed as part of testing. As a consequence, where
comment|/// possible, we would like to produce efficient-to-execute code, but not
comment|/// if it significantly slows down compilation or would prevent even basic
comment|/// debugging of the resulting binary.
comment|///
comment|/// As an example, complex loop transformations such as versioning,
comment|/// vectorization, or fusion might not make sense here due to the degree to
comment|/// which the executed code would differ from the source code, and the
comment|/// potential compile time cost.
name|O1
block|,
comment|/// Optimize for fast execution as much as possible without triggering
comment|/// significant incremental compile time or code size growth.
comment|///
comment|/// The key idea is that optimizations at this level should "pay for
comment|/// themselves". So if an optimization increases compile time by 5% or
comment|/// increases code size by 5% for a particular benchmark, that benchmark
comment|/// should also be one which sees a 5% runtime improvement. If the compile
comment|/// time or code size penalties happen on average across a diverse range of
comment|/// LLVM users' benchmarks, then the improvements should as well.
comment|///
comment|/// And no matter what, the compile time needs to not grow superlinearly
comment|/// with the size of input to LLVM so that users can control the runtime of
comment|/// the optimizer in this mode.
comment|///
comment|/// This is expected to be a good default optimization level for the vast
comment|/// majority of users.
name|O2
block|,
comment|/// Optimize for fast execution as much as possible.
comment|///
comment|/// This mode is significantly more aggressive in trading off compile time
comment|/// and code size to get execution time improvements. The core idea is that
comment|/// this mode should include any optimization that helps execution time on
comment|/// balance across a diverse collection of benchmarks, even if it increases
comment|/// code size or compile time for some benchmarks without corresponding
comment|/// improvements to execution time.
comment|///
comment|/// Despite being willing to trade more compile time off to get improved
comment|/// execution time, this mode still tries to avoid superlinear growth in
comment|/// order to make even significantly slower compile times at least scale
comment|/// reasonably. This does not preclude very substantial constant factor
comment|/// costs though.
name|O3
block|,
comment|/// Similar to \c O2 but tries to optimize for small code size instead of
comment|/// fast execution without triggering significant incremental execution
comment|/// time slowdowns.
comment|///
comment|/// The logic here is exactly the same as \c O2, but with code size and
comment|/// execution time metrics swapped.
comment|///
comment|/// A consequence of the different core goal is that this should in general
comment|/// produce substantially smaller executables that still run in
comment|/// a reasonable amount of time.
name|Os
block|,
comment|/// A very specialized mode that will optimize for code size at any and all
comment|/// costs.
comment|///
comment|/// This is useful primarily when there are absolute size limitations and
comment|/// any effort taken to reduce the size is worth it regardless of the
comment|/// execution time impact. You should expect this level to produce rather
comment|/// slow, but very small, code.
name|Oz
block|}
enum|;
name|explicit
name|PassBuilder
argument_list|(
name|TargetMachine
operator|*
name|TM
operator|=
name|nullptr
argument_list|,
name|Optional
operator|<
name|PGOOptions
operator|>
name|PGOOpt
operator|=
name|None
argument_list|)
range|:
name|TM
argument_list|(
name|TM
argument_list|)
decl_stmt|,
name|PGOOpt
argument_list|(
name|PGOOpt
argument_list|)
block|{}
comment|/// \brief Cross register the analysis managers through their proxies.
comment|///
comment|/// This is an interface that can be used to cross register each
comment|// AnalysisManager with all the others analysis managers.
name|void
name|crossRegisterProxies
parameter_list|(
name|LoopAnalysisManager
modifier|&
name|LAM
parameter_list|,
name|FunctionAnalysisManager
modifier|&
name|FAM
parameter_list|,
name|CGSCCAnalysisManager
modifier|&
name|CGAM
parameter_list|,
name|ModuleAnalysisManager
modifier|&
name|MAM
parameter_list|)
function_decl|;
comment|/// \brief Registers all available module analysis passes.
comment|///
comment|/// This is an interface that can be used to populate a \c
comment|/// ModuleAnalysisManager with all registered module analyses. Callers can
comment|/// still manually register any additional analyses. Callers can also
comment|/// pre-register analyses and this will not override those.
name|void
name|registerModuleAnalyses
parameter_list|(
name|ModuleAnalysisManager
modifier|&
name|MAM
parameter_list|)
function_decl|;
comment|/// \brief Registers all available CGSCC analysis passes.
comment|///
comment|/// This is an interface that can be used to populate a \c CGSCCAnalysisManager
comment|/// with all registered CGSCC analyses. Callers can still manually register any
comment|/// additional analyses. Callers can also pre-register analyses and this will
comment|/// not override those.
name|void
name|registerCGSCCAnalyses
parameter_list|(
name|CGSCCAnalysisManager
modifier|&
name|CGAM
parameter_list|)
function_decl|;
comment|/// \brief Registers all available function analysis passes.
comment|///
comment|/// This is an interface that can be used to populate a \c
comment|/// FunctionAnalysisManager with all registered function analyses. Callers can
comment|/// still manually register any additional analyses. Callers can also
comment|/// pre-register analyses and this will not override those.
name|void
name|registerFunctionAnalyses
parameter_list|(
name|FunctionAnalysisManager
modifier|&
name|FAM
parameter_list|)
function_decl|;
comment|/// \brief Registers all available loop analysis passes.
comment|///
comment|/// This is an interface that can be used to populate a \c LoopAnalysisManager
comment|/// with all registered loop analyses. Callers can still manually register any
comment|/// additional analyses.
name|void
name|registerLoopAnalyses
parameter_list|(
name|LoopAnalysisManager
modifier|&
name|LAM
parameter_list|)
function_decl|;
comment|/// Construct the core LLVM function canonicalization and simplification
comment|/// pipeline.
comment|///
comment|/// This is a long pipeline and uses most of the per-function optimization
comment|/// passes in LLVM to canonicalize and simplify the IR. It is suitable to run
comment|/// repeatedly over the IR and is not expected to destroy important
comment|/// information about the semantics of the IR.
comment|///
comment|/// Note that \p Level cannot be `O0` here. The pipelines produced are
comment|/// only intended for use when attempting to optimize code. If frontends
comment|/// require some transformations for semantic reasons, they should explicitly
comment|/// build them.
name|FunctionPassManager
name|buildFunctionSimplificationPipeline
parameter_list|(
name|OptimizationLevel
name|Level
parameter_list|,
name|bool
name|DebugLogging
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Construct the core LLVM module canonicalization and simplification
comment|/// pipeline.
comment|///
comment|/// This pipeline focuses on canonicalizing and simplifying the entire module
comment|/// of IR. Much like the function simplification pipeline above, it is
comment|/// suitable to run repeatedly over the IR and is not expected to destroy
comment|/// important information. It does, however, perform inlining and other
comment|/// heuristic based simplifications that are not strictly reversible.
comment|///
comment|/// Note that \p Level cannot be `O0` here. The pipelines produced are
comment|/// only intended for use when attempting to optimize code. If frontends
comment|/// require some transformations for semantic reasons, they should explicitly
comment|/// build them.
name|ModulePassManager
name|buildModuleSimplificationPipeline
parameter_list|(
name|OptimizationLevel
name|Level
parameter_list|,
name|bool
name|DebugLogging
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Construct the core LLVM module optimization pipeline.
comment|///
comment|/// This pipeline focuses on optimizing the execution speed of the IR. It
comment|/// uses cost modeling and thresholds to balance code growth against runtime
comment|/// improvements. It includes vectorization and other information destroying
comment|/// transformations. It also cannot generally be run repeatedly on a module
comment|/// without potentially seriously regressing either runtime performance of
comment|/// the code or serious code size growth.
comment|///
comment|/// Note that \p Level cannot be `O0` here. The pipelines produced are
comment|/// only intended for use when attempting to optimize code. If frontends
comment|/// require some transformations for semantic reasons, they should explicitly
comment|/// build them.
name|ModulePassManager
name|buildModuleOptimizationPipeline
parameter_list|(
name|OptimizationLevel
name|Level
parameter_list|,
name|bool
name|DebugLogging
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Build a per-module default optimization pipeline.
comment|///
comment|/// This provides a good default optimization pipeline for per-module
comment|/// optimization and code generation without any link-time optimization. It
comment|/// typically correspond to frontend "-O[123]" options for optimization
comment|/// levels \c O1, \c O2 and \c O3 resp.
comment|///
comment|/// Note that \p Level cannot be `O0` here. The pipelines produced are
comment|/// only intended for use when attempting to optimize code. If frontends
comment|/// require some transformations for semantic reasons, they should explicitly
comment|/// build them.
name|ModulePassManager
name|buildPerModuleDefaultPipeline
parameter_list|(
name|OptimizationLevel
name|Level
parameter_list|,
name|bool
name|DebugLogging
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Build a pre-link, ThinLTO-targeting default optimization pipeline to
comment|/// a pass manager.
comment|///
comment|/// This adds the pre-link optimizations tuned to prepare a module for
comment|/// a ThinLTO run. It works to minimize the IR which needs to be analyzed
comment|/// without making irreversible decisions which could be made better during
comment|/// the LTO run.
comment|///
comment|/// Note that \p Level cannot be `O0` here. The pipelines produced are
comment|/// only intended for use when attempting to optimize code. If frontends
comment|/// require some transformations for semantic reasons, they should explicitly
comment|/// build them.
name|ModulePassManager
name|buildThinLTOPreLinkDefaultPipeline
parameter_list|(
name|OptimizationLevel
name|Level
parameter_list|,
name|bool
name|DebugLogging
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Build an ThinLTO default optimization pipeline to a pass manager.
comment|///
comment|/// This provides a good default optimization pipeline for link-time
comment|/// optimization and code generation. It is particularly tuned to fit well
comment|/// when IR coming into the LTO phase was first run through \c
comment|/// addPreLinkLTODefaultPipeline, and the two coordinate closely.
comment|///
comment|/// Note that \p Level cannot be `O0` here. The pipelines produced are
comment|/// only intended for use when attempting to optimize code. If frontends
comment|/// require some transformations for semantic reasons, they should explicitly
comment|/// build them.
name|ModulePassManager
name|buildThinLTODefaultPipeline
parameter_list|(
name|OptimizationLevel
name|Level
parameter_list|,
name|bool
name|DebugLogging
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Build a pre-link, LTO-targeting default optimization pipeline to a pass
comment|/// manager.
comment|///
comment|/// This adds the pre-link optimizations tuned to work well with a later LTO
comment|/// run. It works to minimize the IR which needs to be analyzed without
comment|/// making irreversible decisions which could be made better during the LTO
comment|/// run.
comment|///
comment|/// Note that \p Level cannot be `O0` here. The pipelines produced are
comment|/// only intended for use when attempting to optimize code. If frontends
comment|/// require some transformations for semantic reasons, they should explicitly
comment|/// build them.
name|ModulePassManager
name|buildLTOPreLinkDefaultPipeline
parameter_list|(
name|OptimizationLevel
name|Level
parameter_list|,
name|bool
name|DebugLogging
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Build an LTO default optimization pipeline to a pass manager.
comment|///
comment|/// This provides a good default optimization pipeline for link-time
comment|/// optimization and code generation. It is particularly tuned to fit well
comment|/// when IR coming into the LTO phase was first run through \c
comment|/// addPreLinkLTODefaultPipeline, and the two coordinate closely.
comment|///
comment|/// Note that \p Level cannot be `O0` here. The pipelines produced are
comment|/// only intended for use when attempting to optimize code. If frontends
comment|/// require some transformations for semantic reasons, they should explicitly
comment|/// build them.
name|ModulePassManager
name|buildLTODefaultPipeline
parameter_list|(
name|OptimizationLevel
name|Level
parameter_list|,
name|bool
name|DebugLogging
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Build the default `AAManager` with the default alias analysis pipeline
comment|/// registered.
name|AAManager
name|buildDefaultAAPipeline
parameter_list|()
function_decl|;
comment|/// \brief Parse a textual pass pipeline description into a \c ModulePassManager.
comment|///
comment|/// The format of the textual pass pipeline description looks something like:
comment|///
comment|///   module(function(instcombine,sroa),dce,cgscc(inliner,function(...)),...)
comment|///
comment|/// Pass managers have ()s describing the nest structure of passes. All passes
comment|/// are comma separated. As a special shortcut, if the very first pass is not
comment|/// a module pass (as a module pass manager is), this will automatically form
comment|/// the shortest stack of pass managers that allow inserting that first pass.
comment|/// So, assuming function passes 'fpassN', CGSCC passes 'cgpassN', and loop passes
comment|/// 'lpassN', all of these are valid:
comment|///
comment|///   fpass1,fpass2,fpass3
comment|///   cgpass1,cgpass2,cgpass3
comment|///   lpass1,lpass2,lpass3
comment|///
comment|/// And they are equivalent to the following (resp.):
comment|///
comment|///   module(function(fpass1,fpass2,fpass3))
comment|///   module(cgscc(cgpass1,cgpass2,cgpass3))
comment|///   module(function(loop(lpass1,lpass2,lpass3)))
comment|///
comment|/// This shortcut is especially useful for debugging and testing small pass
comment|/// combinations. Note that these shortcuts don't introduce any other magic. If
comment|/// the sequence of passes aren't all the exact same kind of pass, it will be
comment|/// an error. You cannot mix different levels implicitly, you must explicitly
comment|/// form a pass manager in which to nest passes.
name|bool
name|parsePassPipeline
parameter_list|(
name|ModulePassManager
modifier|&
name|MPM
parameter_list|,
name|StringRef
name|PipelineText
parameter_list|,
name|bool
name|VerifyEachPass
init|=
name|true
parameter_list|,
name|bool
name|DebugLogging
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Parse a textual alias analysis pipeline into the provided AA manager.
comment|///
comment|/// The format of the textual AA pipeline is a comma separated list of AA
comment|/// pass names:
comment|///
comment|///   basic-aa,globals-aa,...
comment|///
comment|/// The AA manager is set up such that the provided alias analyses are tried
comment|/// in the order specified. See the \c AAManaager documentation for details
comment|/// about the logic used. This routine just provides the textual mapping
comment|/// between AA names and the analyses to register with the manager.
comment|///
comment|/// Returns false if the text cannot be parsed cleanly. The specific state of
comment|/// the \p AA manager is unspecified if such an error is encountered and this
comment|/// returns false.
name|bool
name|parseAAPipeline
parameter_list|(
name|AAManager
modifier|&
name|AA
parameter_list|,
name|StringRef
name|PipelineText
parameter_list|)
function_decl|;
name|private
label|:
comment|/// A struct to capture parsed pass pipeline names.
struct|struct
name|PipelineElement
block|{
name|StringRef
name|Name
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|PipelineElement
operator|>
name|InnerPipeline
expr_stmt|;
block|}
struct|;
specifier|static
name|Optional
operator|<
name|std
operator|::
name|vector
operator|<
name|PipelineElement
operator|>>
name|parsePipelineText
argument_list|(
argument|StringRef Text
argument_list|)
expr_stmt|;
name|bool
name|parseModulePass
parameter_list|(
name|ModulePassManager
modifier|&
name|MPM
parameter_list|,
specifier|const
name|PipelineElement
modifier|&
name|E
parameter_list|,
name|bool
name|VerifyEachPass
parameter_list|,
name|bool
name|DebugLogging
parameter_list|)
function_decl|;
name|bool
name|parseCGSCCPass
parameter_list|(
name|CGSCCPassManager
modifier|&
name|CGPM
parameter_list|,
specifier|const
name|PipelineElement
modifier|&
name|E
parameter_list|,
name|bool
name|VerifyEachPass
parameter_list|,
name|bool
name|DebugLogging
parameter_list|)
function_decl|;
name|bool
name|parseFunctionPass
parameter_list|(
name|FunctionPassManager
modifier|&
name|FPM
parameter_list|,
specifier|const
name|PipelineElement
modifier|&
name|E
parameter_list|,
name|bool
name|VerifyEachPass
parameter_list|,
name|bool
name|DebugLogging
parameter_list|)
function_decl|;
name|bool
name|parseLoopPass
parameter_list|(
name|LoopPassManager
modifier|&
name|LPM
parameter_list|,
specifier|const
name|PipelineElement
modifier|&
name|E
parameter_list|,
name|bool
name|VerifyEachPass
parameter_list|,
name|bool
name|DebugLogging
parameter_list|)
function_decl|;
name|bool
name|parseAAPassName
parameter_list|(
name|AAManager
modifier|&
name|AA
parameter_list|,
name|StringRef
name|Name
parameter_list|)
function_decl|;
name|bool
name|parseLoopPassPipeline
argument_list|(
name|LoopPassManager
operator|&
name|LPM
argument_list|,
name|ArrayRef
operator|<
name|PipelineElement
operator|>
name|Pipeline
argument_list|,
name|bool
name|VerifyEachPass
argument_list|,
name|bool
name|DebugLogging
argument_list|)
decl_stmt|;
name|bool
name|parseFunctionPassPipeline
argument_list|(
name|FunctionPassManager
operator|&
name|FPM
argument_list|,
name|ArrayRef
operator|<
name|PipelineElement
operator|>
name|Pipeline
argument_list|,
name|bool
name|VerifyEachPass
argument_list|,
name|bool
name|DebugLogging
argument_list|)
decl_stmt|;
name|bool
name|parseCGSCCPassPipeline
argument_list|(
name|CGSCCPassManager
operator|&
name|CGPM
argument_list|,
name|ArrayRef
operator|<
name|PipelineElement
operator|>
name|Pipeline
argument_list|,
name|bool
name|VerifyEachPass
argument_list|,
name|bool
name|DebugLogging
argument_list|)
decl_stmt|;
name|bool
name|parseModulePassPipeline
argument_list|(
name|ModulePassManager
operator|&
name|MPM
argument_list|,
name|ArrayRef
operator|<
name|PipelineElement
operator|>
name|Pipeline
argument_list|,
name|bool
name|VerifyEachPass
argument_list|,
name|bool
name|DebugLogging
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

