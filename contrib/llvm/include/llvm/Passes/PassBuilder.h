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
comment|/// \brief A struct to capture parsed pass pipeline names.
comment|///
comment|/// A pipeline is defined as a series of names, each of which may in itself
comment|/// recursively contain a nested pipeline. A name is either the name of a pass
comment|/// (e.g. "instcombine") or the name of a pipeline type (e.g. "cgscc"). If the
comment|/// name is the name of a pass, the InnerPipeline is empty, since passes
comment|/// cannot contain inner pipelines. See parsePassPipeline() for a more
comment|/// detailed description of the textual pipeline format.
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
comment|///
comment|/// \p PrepareForThinLTO indicates whether this is invoked in
comment|/// PrepareForThinLTO phase. Special handling is needed for sample PGO to
comment|/// ensure profile accurate in the backend profile annotation phase.
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
parameter_list|,
name|bool
name|PrepareForThinLTO
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
comment|///
comment|/// \p PrepareForThinLTO indicates whether this is invoked in
comment|/// PrepareForThinLTO phase. Special handling is needed for sample PGO to
comment|/// ensure profile accurate in the backend profile annotation phase.
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
parameter_list|,
name|bool
name|PrepareForThinLTO
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
comment|/// \brief Parse a textual pass pipeline description into a \c
comment|/// ModulePassManager.
comment|///
comment|/// The format of the textual pass pipeline description looks something like:
comment|///
comment|///   module(function(instcombine,sroa),dce,cgscc(inliner,function(...)),...)
comment|///
comment|/// Pass managers have ()s describing the nest structure of passes. All passes
comment|/// are comma separated. As a special shortcut, if the very first pass is not
comment|/// a module pass (as a module pass manager is), this will automatically form
comment|/// the shortest stack of pass managers that allow inserting that first pass.
comment|/// So, assuming function passes 'fpassN', CGSCC passes 'cgpassN', and loop
comment|/// passes 'lpassN', all of these are valid:
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
comment|/// combinations. Note that these shortcuts don't introduce any other magic.
comment|/// If the sequence of passes aren't all the exact same kind of pass, it will
comment|/// be an error. You cannot mix different levels implicitly, you must
comment|/// explicitly form a pass manager in which to nest passes.
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
comment|/// {{@ Parse a textual pass pipeline description into a specific PassManager
comment|///
comment|/// Automatic deduction of an appropriate pass manager stack is not supported.
comment|/// For example, to insert a loop pass 'lpass' into a FunctinoPassManager,
comment|/// this is the valid pipeline text:
comment|///
comment|///   function(lpass)
name|bool
name|parsePassPipeline
parameter_list|(
name|CGSCCPassManager
modifier|&
name|CGPM
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
name|bool
name|parsePassPipeline
parameter_list|(
name|FunctionPassManager
modifier|&
name|FPM
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
name|bool
name|parsePassPipeline
parameter_list|(
name|LoopPassManager
modifier|&
name|LPM
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
comment|/// @}}
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
comment|/// \brief Register a callback for a default optimizer pipeline extension
comment|/// point
comment|///
comment|/// This extension point allows adding passes that perform peephole
comment|/// optimizations similar to the instruction combiner. These passes will be
comment|/// inserted after each instance of the instruction combiner pass.
name|void
name|registerPeepholeEPCallback
argument_list|(
specifier|const
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|FunctionPassManager
operator|&
argument_list|,
name|OptimizationLevel
argument_list|)
operator|>
operator|&
name|C
argument_list|)
block|{
name|PeepholeEPCallbacks
operator|.
name|push_back
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Register a callback for a default optimizer pipeline extension
comment|/// point
comment|///
comment|/// This extension point allows adding late loop canonicalization and
comment|/// simplification passes. This is the last point in the loop optimization
comment|/// pipeline before loop deletion. Each pass added
comment|/// here must be an instance of LoopPass.
comment|/// This is the place to add passes that can remove loops, such as target-
comment|/// specific loop idiom recognition.
name|void
name|registerLateLoopOptimizationsEPCallback
argument_list|(
specifier|const
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|LoopPassManager
operator|&
argument_list|,
name|OptimizationLevel
argument_list|)
operator|>
operator|&
name|C
argument_list|)
block|{
name|LateLoopOptimizationsEPCallbacks
operator|.
name|push_back
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Register a callback for a default optimizer pipeline extension
comment|/// point
comment|///
comment|/// This extension point allows adding loop passes to the end of the loop
comment|/// optimizer.
name|void
name|registerLoopOptimizerEndEPCallback
argument_list|(
specifier|const
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|LoopPassManager
operator|&
argument_list|,
name|OptimizationLevel
argument_list|)
operator|>
operator|&
name|C
argument_list|)
block|{
name|LoopOptimizerEndEPCallbacks
operator|.
name|push_back
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Register a callback for a default optimizer pipeline extension
comment|/// point
comment|///
comment|/// This extension point allows adding optimization passes after most of the
comment|/// main optimizations, but before the last cleanup-ish optimizations.
name|void
name|registerScalarOptimizerLateEPCallback
argument_list|(
specifier|const
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|FunctionPassManager
operator|&
argument_list|,
name|OptimizationLevel
argument_list|)
operator|>
operator|&
name|C
argument_list|)
block|{
name|ScalarOptimizerLateEPCallbacks
operator|.
name|push_back
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Register a callback for a default optimizer pipeline extension
comment|/// point
comment|///
comment|/// This extension point allows adding CallGraphSCC passes at the end of the
comment|/// main CallGraphSCC passes and before any function simplification passes run
comment|/// by CGPassManager.
name|void
name|registerCGSCCOptimizerLateEPCallback
argument_list|(
specifier|const
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|CGSCCPassManager
operator|&
argument_list|,
name|OptimizationLevel
argument_list|)
operator|>
operator|&
name|C
argument_list|)
block|{
name|CGSCCOptimizerLateEPCallbacks
operator|.
name|push_back
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Register a callback for a default optimizer pipeline extension
comment|/// point
comment|///
comment|/// This extension point allows adding optimization passes before the
comment|/// vectorizer and other highly target specific optimization passes are
comment|/// executed.
name|void
name|registerVectorizerStartEPCallback
argument_list|(
specifier|const
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|FunctionPassManager
operator|&
argument_list|,
name|OptimizationLevel
argument_list|)
operator|>
operator|&
name|C
argument_list|)
block|{
name|VectorizerStartEPCallbacks
operator|.
name|push_back
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Register a callback for parsing an AliasAnalysis Name to populate
comment|/// the given AAManager \p AA
name|void
name|registerParseAACallback
argument_list|(
specifier|const
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
argument|StringRef Name
argument_list|,
argument|AAManager&AA
argument_list|)
operator|>
operator|&
name|C
argument_list|)
block|{
name|AAParsingCallbacks
operator|.
name|push_back
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
comment|/// {{@ Register callbacks for analysis registration with this PassBuilder
comment|/// instance.
comment|/// Callees register their analyses with the given AnalysisManager objects.
name|void
name|registerAnalysisRegistrationCallback
argument_list|(
specifier|const
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|CGSCCAnalysisManager
operator|&
argument_list|)
operator|>
operator|&
name|C
argument_list|)
block|{
name|CGSCCAnalysisRegistrationCallbacks
operator|.
name|push_back
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
name|void
name|registerAnalysisRegistrationCallback
argument_list|(
specifier|const
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|FunctionAnalysisManager
operator|&
argument_list|)
operator|>
operator|&
name|C
argument_list|)
block|{
name|FunctionAnalysisRegistrationCallbacks
operator|.
name|push_back
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
name|void
name|registerAnalysisRegistrationCallback
argument_list|(
specifier|const
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|LoopAnalysisManager
operator|&
argument_list|)
operator|>
operator|&
name|C
argument_list|)
block|{
name|LoopAnalysisRegistrationCallbacks
operator|.
name|push_back
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
name|void
name|registerAnalysisRegistrationCallback
argument_list|(
specifier|const
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|ModuleAnalysisManager
operator|&
argument_list|)
operator|>
operator|&
name|C
argument_list|)
block|{
name|ModuleAnalysisRegistrationCallbacks
operator|.
name|push_back
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
comment|/// @}}
comment|/// {{@ Register pipeline parsing callbacks with this pass builder instance.
comment|/// Using these callbacks, callers can parse both a single pass name, as well
comment|/// as entire sub-pipelines, and populate the PassManager instance
comment|/// accordingly.
name|void
name|registerPipelineParsingCallback
argument_list|(
specifier|const
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
argument|StringRef Name
argument_list|,
argument|CGSCCPassManager&
argument_list|,
argument|ArrayRef<PipelineElement>
argument_list|)
operator|>
operator|&
name|C
argument_list|)
block|{
name|CGSCCPipelineParsingCallbacks
operator|.
name|push_back
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
name|void
name|registerPipelineParsingCallback
argument_list|(
specifier|const
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
argument|StringRef Name
argument_list|,
argument|FunctionPassManager&
argument_list|,
argument|ArrayRef<PipelineElement>
argument_list|)
operator|>
operator|&
name|C
argument_list|)
block|{
name|FunctionPipelineParsingCallbacks
operator|.
name|push_back
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
name|void
name|registerPipelineParsingCallback
argument_list|(
specifier|const
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
argument|StringRef Name
argument_list|,
argument|LoopPassManager&
argument_list|,
argument|ArrayRef<PipelineElement>
argument_list|)
operator|>
operator|&
name|C
argument_list|)
block|{
name|LoopPipelineParsingCallbacks
operator|.
name|push_back
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
name|void
name|registerPipelineParsingCallback
argument_list|(
specifier|const
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
argument|StringRef Name
argument_list|,
argument|ModulePassManager&
argument_list|,
argument|ArrayRef<PipelineElement>
argument_list|)
operator|>
operator|&
name|C
argument_list|)
block|{
name|ModulePipelineParsingCallbacks
operator|.
name|push_back
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
comment|/// @}}
comment|/// \brief Register a callback for a top-level pipeline entry.
comment|///
comment|/// If the PassManager type is not given at the top level of the pipeline
comment|/// text, this Callback should be used to determine the appropriate stack of
comment|/// PassManagers and populate the passed ModulePassManager.
name|void
name|registerParseTopLevelPipelineCallback
argument_list|(
specifier|const
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
argument|ModulePassManager&
argument_list|,
argument|ArrayRef<PipelineElement>
argument_list|,
argument|bool VerifyEachPass
argument_list|,
argument|bool DebugLogging
argument_list|)
operator|>
operator|&
name|C
argument_list|)
block|{
name|TopLevelPipelineParsingCallbacks
operator|.
name|push_back
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
name|private
label|:
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
name|void
name|addPGOInstrPasses
argument_list|(
name|ModulePassManager
operator|&
name|MPM
argument_list|,
name|bool
name|DebugLogging
argument_list|,
name|OptimizationLevel
name|Level
argument_list|,
name|bool
name|RunProfileGen
argument_list|,
name|std
operator|::
name|string
name|ProfileGenFile
argument_list|,
name|std
operator|::
name|string
name|ProfileUseFile
argument_list|)
decl_stmt|;
name|void
name|invokePeepholeEPCallbacks
parameter_list|(
name|FunctionPassManager
modifier|&
parameter_list|,
name|OptimizationLevel
parameter_list|)
function_decl|;
comment|// Extension Point callbacks
name|SmallVector
operator|<
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|FunctionPassManager
operator|&
argument_list|,
name|OptimizationLevel
argument_list|)
operator|>
operator|,
literal|2
operator|>
name|PeepholeEPCallbacks
expr_stmt|;
name|SmallVector
operator|<
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|LoopPassManager
operator|&
argument_list|,
name|OptimizationLevel
argument_list|)
operator|>
operator|,
literal|2
operator|>
name|LateLoopOptimizationsEPCallbacks
expr_stmt|;
name|SmallVector
operator|<
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|LoopPassManager
operator|&
argument_list|,
name|OptimizationLevel
argument_list|)
operator|>
operator|,
literal|2
operator|>
name|LoopOptimizerEndEPCallbacks
expr_stmt|;
name|SmallVector
operator|<
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|FunctionPassManager
operator|&
argument_list|,
name|OptimizationLevel
argument_list|)
operator|>
operator|,
literal|2
operator|>
name|ScalarOptimizerLateEPCallbacks
expr_stmt|;
name|SmallVector
operator|<
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|CGSCCPassManager
operator|&
argument_list|,
name|OptimizationLevel
argument_list|)
operator|>
operator|,
literal|2
operator|>
name|CGSCCOptimizerLateEPCallbacks
expr_stmt|;
name|SmallVector
operator|<
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|FunctionPassManager
operator|&
argument_list|,
name|OptimizationLevel
argument_list|)
operator|>
operator|,
literal|2
operator|>
name|VectorizerStartEPCallbacks
expr_stmt|;
comment|// Module callbacks
name|SmallVector
operator|<
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|ModuleAnalysisManager
operator|&
argument_list|)
operator|>
operator|,
literal|2
operator|>
name|ModuleAnalysisRegistrationCallbacks
expr_stmt|;
name|SmallVector
operator|<
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
name|StringRef
argument_list|,
name|ModulePassManager
operator|&
argument_list|,
name|ArrayRef
operator|<
name|PipelineElement
operator|>
argument_list|)
operator|>
operator|,
literal|2
operator|>
name|ModulePipelineParsingCallbacks
expr_stmt|;
name|SmallVector
operator|<
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
argument|ModulePassManager&
argument_list|,
argument|ArrayRef<PipelineElement>
argument_list|,
argument|bool VerifyEachPass
argument_list|,
argument|bool DebugLogging
argument_list|)
operator|>
operator|,
literal|2
operator|>
name|TopLevelPipelineParsingCallbacks
expr_stmt|;
comment|// CGSCC callbacks
name|SmallVector
operator|<
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|CGSCCAnalysisManager
operator|&
argument_list|)
operator|>
operator|,
literal|2
operator|>
name|CGSCCAnalysisRegistrationCallbacks
expr_stmt|;
name|SmallVector
operator|<
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
name|StringRef
argument_list|,
name|CGSCCPassManager
operator|&
argument_list|,
name|ArrayRef
operator|<
name|PipelineElement
operator|>
argument_list|)
operator|>
operator|,
literal|2
operator|>
name|CGSCCPipelineParsingCallbacks
expr_stmt|;
comment|// Function callbacks
name|SmallVector
operator|<
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|FunctionAnalysisManager
operator|&
argument_list|)
operator|>
operator|,
literal|2
operator|>
name|FunctionAnalysisRegistrationCallbacks
expr_stmt|;
name|SmallVector
operator|<
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
name|StringRef
argument_list|,
name|FunctionPassManager
operator|&
argument_list|,
name|ArrayRef
operator|<
name|PipelineElement
operator|>
argument_list|)
operator|>
operator|,
literal|2
operator|>
name|FunctionPipelineParsingCallbacks
expr_stmt|;
comment|// Loop callbacks
name|SmallVector
operator|<
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|LoopAnalysisManager
operator|&
argument_list|)
operator|>
operator|,
literal|2
operator|>
name|LoopAnalysisRegistrationCallbacks
expr_stmt|;
name|SmallVector
operator|<
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
name|StringRef
argument_list|,
name|LoopPassManager
operator|&
argument_list|,
name|ArrayRef
operator|<
name|PipelineElement
operator|>
argument_list|)
operator|>
operator|,
literal|2
operator|>
name|LoopPipelineParsingCallbacks
expr_stmt|;
comment|// AA callbacks
name|SmallVector
operator|<
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
argument|StringRef Name
argument_list|,
argument|AAManager&AA
argument_list|)
operator|>
operator|,
literal|2
operator|>
name|AAParsingCallbacks
expr_stmt|;
block|}
empty_stmt|;
comment|/// This utility template takes care of adding require<> and invalidate<>
comment|/// passes for an analysis to a given \c PassManager. It is intended to be used
comment|/// during parsing of a pass pipeline when parsing a single PipelineName.
comment|/// When registering a new function analysis FancyAnalysis with the pass
comment|/// pipeline name "fancy-analysis", a matching ParsePipelineCallback could look
comment|/// like this:
comment|///
comment|/// static bool parseFunctionPipeline(StringRef Name, FunctionPassManager&FPM,
comment|///                                   ArrayRef<PipelineElement> P) {
comment|///   if (parseAnalysisUtilityPasses<FancyAnalysis>("fancy-analysis", Name,
comment|///                                                 FPM))
comment|///     return true;
comment|///   return false;
comment|/// }
name|template
operator|<
name|typename
name|AnalysisT
operator|,
name|typename
name|IRUnitT
operator|,
name|typename
name|AnalysisManagerT
operator|,
name|typename
operator|...
name|ExtraArgTs
operator|>
name|bool
name|parseAnalysisUtilityPasses
argument_list|(
argument|StringRef AnalysisName
argument_list|,
argument|StringRef PipelineName
argument_list|,
argument|PassManager<IRUnitT
argument_list|,
argument|AnalysisManagerT
argument_list|,
argument|ExtraArgTs...>&PM
argument_list|)
block|{
if|if
condition|(
operator|!
name|PipelineName
operator|.
name|endswith
argument_list|(
literal|">"
argument_list|)
condition|)
return|return
name|false
return|;
comment|// See if this is an invalidate<> pass name
if|if
condition|(
name|PipelineName
operator|.
name|startswith
argument_list|(
literal|"invalidate<"
argument_list|)
condition|)
block|{
name|PipelineName
operator|=
name|PipelineName
operator|.
name|substr
argument_list|(
literal|11
argument_list|,
name|PipelineName
operator|.
name|size
argument_list|()
operator|-
literal|12
argument_list|)
expr_stmt|;
if|if
condition|(
name|PipelineName
operator|!=
name|AnalysisName
condition|)
return|return
name|false
return|;
name|PM
operator|.
name|addPass
argument_list|(
name|InvalidateAnalysisPass
operator|<
name|AnalysisT
operator|>
operator|(
operator|)
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
comment|// See if this is a require<> pass name
if|if
condition|(
name|PipelineName
operator|.
name|startswith
argument_list|(
literal|"require<"
argument_list|)
condition|)
block|{
name|PipelineName
operator|=
name|PipelineName
operator|.
name|substr
argument_list|(
literal|8
argument_list|,
name|PipelineName
operator|.
name|size
argument_list|()
operator|-
literal|9
argument_list|)
expr_stmt|;
if|if
condition|(
name|PipelineName
operator|!=
name|AnalysisName
condition|)
return|return
name|false
return|;
name|PM
operator|.
name|addPass
argument_list|(
name|RequireAnalysisPass
operator|<
name|AnalysisT
argument_list|,
name|IRUnitT
argument_list|,
name|AnalysisManagerT
argument_list|,
name|ExtraArgTs
operator|...
operator|>
operator|(
operator|)
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

