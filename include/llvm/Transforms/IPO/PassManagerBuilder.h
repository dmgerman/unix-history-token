begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// llvm/Transforms/IPO/PassManagerBuilder.h - Build Standard Pass -*- C++ -*-=//
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
comment|// This file defines the PassManagerBuilder class, which is used to set up a
end_comment

begin_comment
comment|// "standard" optimization sequence suitable for languages like C and C++.
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
name|LLVM_TRANSFORMS_IPO_PASSMANAGERBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_IPO_PASSMANAGERBUILDER_H
end_define

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
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
name|ModuleSummaryIndex
decl_stmt|;
name|class
name|Pass
decl_stmt|;
name|class
name|TargetLibraryInfoImpl
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
comment|// The old pass manager infrastructure is hidden in a legacy namespace now.
name|namespace
name|legacy
block|{
name|class
name|FunctionPassManager
decl_stmt|;
name|class
name|PassManagerBase
decl_stmt|;
block|}
comment|/// PassManagerBuilder - This class is used to set up a standard optimization
comment|/// sequence for languages like C and C++, allowing some APIs to customize the
comment|/// pass sequence in various ways. A simple example of using it would be:
comment|///
comment|///  PassManagerBuilder Builder;
comment|///  Builder.OptLevel = 2;
comment|///  Builder.populateFunctionPassManager(FPM);
comment|///  Builder.populateModulePassManager(MPM);
comment|///
comment|/// In addition to setting up the basic passes, PassManagerBuilder allows
comment|/// frontends to vend a plugin API, where plugins are allowed to add extensions
comment|/// to the default pass manager.  They do this by specifying where in the pass
comment|/// pipeline they want to be added, along with a callback function that adds
comment|/// the pass(es).  For example, a plugin that wanted to add a loop optimization
comment|/// could do something like this:
comment|///
comment|/// static void addMyLoopPass(const PMBuilder&Builder, PassManagerBase&PM) {
comment|///   if (Builder.getOptLevel()> 2&& Builder.getOptSizeLevel() == 0)
comment|///     PM.add(createMyAwesomePass());
comment|/// }
comment|///   ...
comment|///   Builder.addExtension(PassManagerBuilder::EP_LoopOptimizerEnd,
comment|///                        addMyLoopPass);
comment|///   ...
name|class
name|PassManagerBuilder
block|{
name|public
label|:
comment|/// Extensions are passed the builder itself (so they can see how it is
comment|/// configured) as well as the pass manager to add stuff to.
typedef|typedef
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
specifier|const
name|PassManagerBuilder
operator|&
name|Builder
argument_list|,
name|legacy
operator|::
name|PassManagerBase
operator|&
name|PM
argument_list|)
operator|>
name|ExtensionFn
expr_stmt|;
enum|enum
name|ExtensionPointTy
block|{
comment|/// EP_EarlyAsPossible - This extension point allows adding passes before
comment|/// any other transformations, allowing them to see the code as it is coming
comment|/// out of the frontend.
name|EP_EarlyAsPossible
block|,
comment|/// EP_ModuleOptimizerEarly - This extension point allows adding passes
comment|/// just before the main module-level optimization passes.
name|EP_ModuleOptimizerEarly
block|,
comment|/// EP_LoopOptimizerEnd - This extension point allows adding loop passes to
comment|/// the end of the loop optimizer.
name|EP_LoopOptimizerEnd
block|,
comment|/// EP_ScalarOptimizerLate - This extension point allows adding optimization
comment|/// passes after most of the main optimizations, but before the last
comment|/// cleanup-ish optimizations.
name|EP_ScalarOptimizerLate
block|,
comment|/// EP_OptimizerLast -- This extension point allows adding passes that
comment|/// run after everything else.
name|EP_OptimizerLast
block|,
comment|/// EP_VectorizerStart - This extension point allows adding optimization
comment|/// passes before the vectorizer and other highly target specific
comment|/// optimization passes are executed.
name|EP_VectorizerStart
block|,
comment|/// EP_EnabledOnOptLevel0 - This extension point allows adding passes that
comment|/// should not be disabled by O0 optimization level. The passes will be
comment|/// inserted after the inlining pass.
name|EP_EnabledOnOptLevel0
block|,
comment|/// EP_Peephole - This extension point allows adding passes that perform
comment|/// peephole optimizations similar to the instruction combiner. These passes
comment|/// will be inserted after each instance of the instruction combiner pass.
name|EP_Peephole
block|,
comment|/// EP_LateLoopOptimizations - This extension point allows adding late loop
comment|/// canonicalization and simplification passes. This is the last point in
comment|/// the loop optimization pipeline before loop deletion. Each pass added
comment|/// here must be an instance of LoopPass.
comment|/// This is the place to add passes that can remove loops, such as target-
comment|/// specific loop idiom recognition.
name|EP_LateLoopOptimizations
block|,
comment|/// EP_CGSCCOptimizerLate - This extension point allows adding CallGraphSCC
comment|/// passes at the end of the main CallGraphSCC passes and before any
comment|/// function simplification passes run by CGPassManager.
name|EP_CGSCCOptimizerLate
block|,   }
enum|;
comment|/// The Optimization Level - Specify the basic optimization level.
comment|///    0 = -O0, 1 = -O1, 2 = -O2, 3 = -O3
name|unsigned
name|OptLevel
decl_stmt|;
comment|/// SizeLevel - How much we're optimizing for size.
comment|///    0 = none, 1 = -Os, 2 = -Oz
name|unsigned
name|SizeLevel
decl_stmt|;
comment|/// LibraryInfo - Specifies information about the runtime library for the
comment|/// optimizer.  If this is non-null, it is added to both the function and
comment|/// per-module pass pipeline.
name|TargetLibraryInfoImpl
modifier|*
name|LibraryInfo
decl_stmt|;
comment|/// Inliner - Specifies the inliner to use.  If this is non-null, it is
comment|/// added to the per-module passes.
name|Pass
modifier|*
name|Inliner
decl_stmt|;
comment|/// The module summary index to use for exporting information from the
comment|/// regular LTO phase, for example for the CFI and devirtualization type
comment|/// tests.
name|ModuleSummaryIndex
modifier|*
name|ExportSummary
init|=
name|nullptr
decl_stmt|;
comment|/// The module summary index to use for importing information to the
comment|/// thin LTO backends, for example for the CFI and devirtualization type
comment|/// tests.
specifier|const
name|ModuleSummaryIndex
modifier|*
name|ImportSummary
init|=
name|nullptr
decl_stmt|;
name|bool
name|DisableTailCalls
decl_stmt|;
name|bool
name|DisableUnitAtATime
decl_stmt|;
name|bool
name|DisableUnrollLoops
decl_stmt|;
name|bool
name|BBVectorize
decl_stmt|;
name|bool
name|SLPVectorize
decl_stmt|;
name|bool
name|LoopVectorize
decl_stmt|;
name|bool
name|RerollLoops
decl_stmt|;
name|bool
name|NewGVN
decl_stmt|;
name|bool
name|DisableGVNLoadPRE
decl_stmt|;
name|bool
name|VerifyInput
decl_stmt|;
name|bool
name|VerifyOutput
decl_stmt|;
name|bool
name|MergeFunctions
decl_stmt|;
name|bool
name|PrepareForLTO
decl_stmt|;
name|bool
name|PrepareForThinLTO
decl_stmt|;
name|bool
name|PerformThinLTO
decl_stmt|;
name|bool
name|DivergentTarget
decl_stmt|;
comment|/// Enable profile instrumentation pass.
name|bool
name|EnablePGOInstrGen
decl_stmt|;
comment|/// Profile data file name that the instrumentation will be written to.
name|std
operator|::
name|string
name|PGOInstrGen
expr_stmt|;
comment|/// Path of the profile data file.
name|std
operator|::
name|string
name|PGOInstrUse
expr_stmt|;
comment|/// Path of the sample Profile data file.
name|std
operator|::
name|string
name|PGOSampleUse
expr_stmt|;
name|private
label|:
comment|/// ExtensionList - This is list of all of the extensions that are registered.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|ExtensionPointTy
operator|,
name|ExtensionFn
operator|>>
name|Extensions
expr_stmt|;
name|public
label|:
name|PassManagerBuilder
argument_list|()
expr_stmt|;
operator|~
name|PassManagerBuilder
argument_list|()
expr_stmt|;
comment|/// Adds an extension that will be used by all PassManagerBuilder instances.
comment|/// This is intended to be used by plugins, to register a set of
comment|/// optimisations to run automatically.
specifier|static
name|void
name|addGlobalExtension
parameter_list|(
name|ExtensionPointTy
name|Ty
parameter_list|,
name|ExtensionFn
name|Fn
parameter_list|)
function_decl|;
name|void
name|addExtension
parameter_list|(
name|ExtensionPointTy
name|Ty
parameter_list|,
name|ExtensionFn
name|Fn
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|addExtensionsToPM
argument_list|(
name|ExtensionPointTy
name|ETy
argument_list|,
name|legacy
operator|::
name|PassManagerBase
operator|&
name|PM
argument_list|)
decl|const
decl_stmt|;
name|void
name|addInitialAliasAnalysisPasses
argument_list|(
name|legacy
operator|::
name|PassManagerBase
operator|&
name|PM
argument_list|)
decl|const
decl_stmt|;
name|void
name|addLTOOptimizationPasses
argument_list|(
name|legacy
operator|::
name|PassManagerBase
operator|&
name|PM
argument_list|)
decl_stmt|;
name|void
name|addLateLTOOptimizationPasses
argument_list|(
name|legacy
operator|::
name|PassManagerBase
operator|&
name|PM
argument_list|)
decl_stmt|;
name|void
name|addPGOInstrPasses
argument_list|(
name|legacy
operator|::
name|PassManagerBase
operator|&
name|MPM
argument_list|)
decl_stmt|;
name|void
name|addFunctionSimplificationPasses
argument_list|(
name|legacy
operator|::
name|PassManagerBase
operator|&
name|MPM
argument_list|)
decl_stmt|;
name|void
name|addInstructionCombiningPass
argument_list|(
name|legacy
operator|::
name|PassManagerBase
operator|&
name|MPM
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
comment|/// populateFunctionPassManager - This fills in the function pass manager,
comment|/// which is expected to be run on each function immediately as it is
comment|/// generated.  The idea is to reduce the size of the IR in memory.
name|void
name|populateFunctionPassManager
argument_list|(
name|legacy
operator|::
name|FunctionPassManager
operator|&
name|FPM
argument_list|)
decl_stmt|;
comment|/// populateModulePassManager - This sets up the primary pass manager.
name|void
name|populateModulePassManager
argument_list|(
name|legacy
operator|::
name|PassManagerBase
operator|&
name|MPM
argument_list|)
decl_stmt|;
name|void
name|populateLTOPassManager
argument_list|(
name|legacy
operator|::
name|PassManagerBase
operator|&
name|PM
argument_list|)
decl_stmt|;
name|void
name|populateThinLTOPassManager
argument_list|(
name|legacy
operator|::
name|PassManagerBase
operator|&
name|PM
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
comment|/// Registers a function for adding a standard set of passes.  This should be
comment|/// used by optimizer plugins to allow all front ends to transparently use
comment|/// them.  Create a static instance of this class in your plugin, providing a
comment|/// private function that the PassManagerBuilder can use to add your passes.
struct|struct
name|RegisterStandardPasses
block|{
name|RegisterStandardPasses
argument_list|(
argument|PassManagerBuilder::ExtensionPointTy Ty
argument_list|,
argument|PassManagerBuilder::ExtensionFn Fn
argument_list|)
block|{
name|PassManagerBuilder
operator|::
name|addGlobalExtension
argument_list|(
name|Ty
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|Fn
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
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

