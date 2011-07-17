begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/PassManagerBuilder.h - Build Standard Pass -*- C++ -*-===//
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
comment|// These are implemented as inline functions so that we do not have to worry
end_comment

begin_comment
comment|// about link issues.
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
name|LLVM_SUPPORT_PASSMANAGERBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_PASSMANAGERBUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DefaultPasses.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/Passes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/Verifier.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetLibraryInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/Scalar.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/IPO.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
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
name|void
function_decl|(
modifier|*
name|ExtensionFn
function_decl|)
parameter_list|(
specifier|const
name|PassManagerBuilder
modifier|&
name|Builder
parameter_list|,
name|PassManagerBase
modifier|&
name|PM
parameter_list|)
function_decl|;
enum|enum
name|ExtensionPointTy
block|{
comment|/// EP_EarlyAsPossible - This extension point allows adding passes before
comment|/// any other transformations, allowing them to see the code as it is coming
comment|/// out of the frontend.
name|EP_EarlyAsPossible
block|,
comment|/// EP_LoopOptimizerEnd - This extension point allows adding loop passes to
comment|/// the end of the loop optimizer.
name|EP_LoopOptimizerEnd
block|,
comment|/// EP_ScalarOptimizerLate - This extension point allows adding optimization
comment|/// passes after most of the main optimizations, but before the last
comment|/// cleanup-ish optimizations.
name|EP_ScalarOptimizerLate
block|}
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
name|TargetLibraryInfo
modifier|*
name|LibraryInfo
decl_stmt|;
comment|/// Inliner - Specifies the inliner to use.  If this is non-null, it is
comment|/// added to the per-module passes.
name|Pass
modifier|*
name|Inliner
decl_stmt|;
name|bool
name|DisableSimplifyLibCalls
decl_stmt|;
name|bool
name|DisableUnitAtATime
decl_stmt|;
name|bool
name|DisableUnrollLoops
decl_stmt|;
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
operator|>
expr|>
name|Extensions
expr_stmt|;
name|public
label|:
name|PassManagerBuilder
argument_list|()
block|{
name|OptLevel
operator|=
literal|2
expr_stmt|;
name|SizeLevel
operator|=
literal|0
expr_stmt|;
name|LibraryInfo
operator|=
literal|0
expr_stmt|;
name|Inliner
operator|=
literal|0
expr_stmt|;
name|DisableSimplifyLibCalls
operator|=
name|false
expr_stmt|;
name|DisableUnitAtATime
operator|=
name|false
expr_stmt|;
name|DisableUnrollLoops
operator|=
name|false
expr_stmt|;
block|}
operator|~
name|PassManagerBuilder
argument_list|()
block|{
name|delete
name|LibraryInfo
block|;
name|delete
name|Inliner
block|;   }
name|void
name|addExtension
argument_list|(
argument|ExtensionPointTy Ty
argument_list|,
argument|ExtensionFn Fn
argument_list|)
block|{
name|Extensions
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|Ty
argument_list|,
name|Fn
argument_list|)
argument_list|)
block|;   }
name|private
operator|:
name|void
name|addExtensionsToPM
argument_list|(
argument|ExtensionPointTy ETy
argument_list|,
argument|PassManagerBase&PM
argument_list|)
specifier|const
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|Extensions
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|Extensions
index|[
name|i
index|]
operator|.
name|first
operator|==
name|ETy
condition|)
name|Extensions
index|[
name|i
index|]
operator|.
name|second
argument_list|(
operator|*
name|this
argument_list|,
name|PM
argument_list|)
expr_stmt|;
block|}
name|void
name|addInitialAliasAnalysisPasses
argument_list|(
name|PassManagerBase
operator|&
name|PM
argument_list|)
decl|const
block|{
comment|// Add TypeBasedAliasAnalysis before BasicAliasAnalysis so that
comment|// BasicAliasAnalysis wins if they disagree. This is intended to help
comment|// support "obvious" type-punning idioms.
name|PM
operator|.
name|add
argument_list|(
name|createTypeBasedAliasAnalysisPass
argument_list|()
argument_list|)
expr_stmt|;
name|PM
operator|.
name|add
argument_list|(
name|createBasicAliasAnalysisPass
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|public
label|:
comment|/// populateFunctionPassManager - This fills in the function pass manager,
comment|/// which is expected to be run on each function immediately as it is
comment|/// generated.  The idea is to reduce the size of the IR in memory.
name|void
name|populateFunctionPassManager
parameter_list|(
name|FunctionPassManager
modifier|&
name|FPM
parameter_list|)
block|{
name|addExtensionsToPM
argument_list|(
name|EP_EarlyAsPossible
argument_list|,
name|FPM
argument_list|)
expr_stmt|;
comment|// Add LibraryInfo if we have some.
if|if
condition|(
name|LibraryInfo
condition|)
name|FPM
operator|.
name|add
argument_list|(
argument|new TargetLibraryInfo(*LibraryInfo)
argument_list|)
expr_stmt|;
if|if
condition|(
name|OptLevel
operator|==
literal|0
condition|)
return|return;
name|addInitialAliasAnalysisPasses
argument_list|(
name|FPM
argument_list|)
expr_stmt|;
name|FPM
operator|.
name|add
argument_list|(
name|createCFGSimplificationPass
argument_list|()
argument_list|)
expr_stmt|;
name|FPM
operator|.
name|add
argument_list|(
name|createScalarReplAggregatesPass
argument_list|()
argument_list|)
expr_stmt|;
name|FPM
operator|.
name|add
argument_list|(
name|createEarlyCSEPass
argument_list|()
argument_list|)
expr_stmt|;
name|FPM
operator|.
name|add
argument_list|(
name|createLowerExpectIntrinsicPass
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|/// populateModulePassManager - This sets up the primary pass manager.
name|void
name|populateModulePassManager
parameter_list|(
name|PassManagerBase
modifier|&
name|MPM
parameter_list|)
block|{
comment|// If all optimizations are disabled, just run the always-inline pass.
if|if
condition|(
name|OptLevel
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|Inliner
condition|)
block|{
name|MPM
operator|.
name|add
argument_list|(
name|Inliner
argument_list|)
expr_stmt|;
name|Inliner
operator|=
literal|0
expr_stmt|;
block|}
return|return;
block|}
comment|// Add LibraryInfo if we have some.
if|if
condition|(
name|LibraryInfo
condition|)
name|MPM
operator|.
name|add
argument_list|(
argument|new TargetLibraryInfo(*LibraryInfo)
argument_list|)
expr_stmt|;
name|addInitialAliasAnalysisPasses
argument_list|(
name|MPM
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|DisableUnitAtATime
condition|)
block|{
name|MPM
operator|.
name|add
argument_list|(
name|createGlobalOptimizerPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Optimize out global vars
name|MPM
operator|.
name|add
argument_list|(
name|createIPSCCPPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// IP SCCP
name|MPM
operator|.
name|add
argument_list|(
name|createDeadArgEliminationPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Dead argument elimination
name|MPM
operator|.
name|add
argument_list|(
name|createInstructionCombiningPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Clean up after IPCP& DAE
name|MPM
operator|.
name|add
argument_list|(
name|createCFGSimplificationPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Clean up after IPCP& DAE
block|}
comment|// Start of CallGraph SCC passes.
if|if
condition|(
operator|!
name|DisableUnitAtATime
condition|)
name|MPM
operator|.
name|add
argument_list|(
name|createPruneEHPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Remove dead EH info
if|if
condition|(
name|Inliner
condition|)
block|{
name|MPM
operator|.
name|add
argument_list|(
name|Inliner
argument_list|)
expr_stmt|;
name|Inliner
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|DisableUnitAtATime
condition|)
name|MPM
operator|.
name|add
argument_list|(
name|createFunctionAttrsPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Set readonly/readnone attrs
if|if
condition|(
name|OptLevel
operator|>
literal|2
condition|)
name|MPM
operator|.
name|add
argument_list|(
name|createArgumentPromotionPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Scalarize uninlined fn args
comment|// Start of function pass.
comment|// Break up aggregate allocas, using SSAUpdater.
name|MPM
operator|.
name|add
argument_list|(
name|createScalarReplAggregatesPass
argument_list|(
operator|-
literal|1
argument_list|,
name|false
argument_list|)
argument_list|)
expr_stmt|;
name|MPM
operator|.
name|add
argument_list|(
name|createEarlyCSEPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Catch trivial redundancies
if|if
condition|(
operator|!
name|DisableSimplifyLibCalls
condition|)
name|MPM
operator|.
name|add
argument_list|(
name|createSimplifyLibCallsPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Library Call Optimizations
name|MPM
operator|.
name|add
argument_list|(
name|createJumpThreadingPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Thread jumps.
name|MPM
operator|.
name|add
argument_list|(
name|createCorrelatedValuePropagationPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Propagate conditionals
name|MPM
operator|.
name|add
argument_list|(
name|createCFGSimplificationPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Merge& remove BBs
name|MPM
operator|.
name|add
argument_list|(
name|createInstructionCombiningPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Combine silly seq's
name|MPM
operator|.
name|add
argument_list|(
name|createTailCallEliminationPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Eliminate tail calls
name|MPM
operator|.
name|add
argument_list|(
name|createCFGSimplificationPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Merge& remove BBs
name|MPM
operator|.
name|add
argument_list|(
name|createReassociatePass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Reassociate expressions
name|MPM
operator|.
name|add
argument_list|(
name|createLoopRotatePass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Rotate Loop
name|MPM
operator|.
name|add
argument_list|(
name|createLICMPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Hoist loop invariants
name|MPM
operator|.
name|add
argument_list|(
name|createLoopUnswitchPass
argument_list|(
name|SizeLevel
operator|||
name|OptLevel
operator|<
literal|3
argument_list|)
argument_list|)
expr_stmt|;
name|MPM
operator|.
name|add
argument_list|(
name|createInstructionCombiningPass
argument_list|()
argument_list|)
expr_stmt|;
name|MPM
operator|.
name|add
argument_list|(
name|createIndVarSimplifyPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Canonicalize indvars
name|MPM
operator|.
name|add
argument_list|(
name|createLoopIdiomPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Recognize idioms like memset.
name|MPM
operator|.
name|add
argument_list|(
name|createLoopDeletionPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Delete dead loops
if|if
condition|(
operator|!
name|DisableUnrollLoops
condition|)
name|MPM
operator|.
name|add
argument_list|(
name|createLoopUnrollPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Unroll small loops
name|addExtensionsToPM
argument_list|(
name|EP_LoopOptimizerEnd
argument_list|,
name|MPM
argument_list|)
expr_stmt|;
if|if
condition|(
name|OptLevel
operator|>
literal|1
condition|)
name|MPM
operator|.
name|add
argument_list|(
name|createGVNPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Remove redundancies
name|MPM
operator|.
name|add
argument_list|(
name|createMemCpyOptPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Remove memcpy / form memset
name|MPM
operator|.
name|add
argument_list|(
name|createSCCPPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Constant prop with SCCP
comment|// Run instcombine after redundancy elimination to exploit opportunities
comment|// opened up by them.
name|MPM
operator|.
name|add
argument_list|(
name|createInstructionCombiningPass
argument_list|()
argument_list|)
expr_stmt|;
name|MPM
operator|.
name|add
argument_list|(
name|createJumpThreadingPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Thread jumps
name|MPM
operator|.
name|add
argument_list|(
name|createCorrelatedValuePropagationPass
argument_list|()
argument_list|)
expr_stmt|;
name|MPM
operator|.
name|add
argument_list|(
name|createDeadStoreEliminationPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Delete dead stores
name|addExtensionsToPM
argument_list|(
name|EP_ScalarOptimizerLate
argument_list|,
name|MPM
argument_list|)
expr_stmt|;
name|MPM
operator|.
name|add
argument_list|(
name|createAggressiveDCEPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Delete dead instructions
name|MPM
operator|.
name|add
argument_list|(
name|createCFGSimplificationPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Merge& remove BBs
name|MPM
operator|.
name|add
argument_list|(
name|createInstructionCombiningPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Clean up after everything.
if|if
condition|(
operator|!
name|DisableUnitAtATime
condition|)
block|{
comment|// FIXME: We shouldn't bother with this anymore.
name|MPM
operator|.
name|add
argument_list|(
name|createStripDeadPrototypesPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Get rid of dead prototypes
comment|// GlobalOpt already deletes dead functions and globals, at -O3 try a
comment|// late pass of GlobalDCE.  It is capable of deleting dead cycles.
if|if
condition|(
name|OptLevel
operator|>
literal|2
condition|)
name|MPM
operator|.
name|add
argument_list|(
name|createGlobalDCEPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Remove dead fns and globals.
if|if
condition|(
name|OptLevel
operator|>
literal|1
condition|)
name|MPM
operator|.
name|add
argument_list|(
name|createConstantMergePass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Merge dup global constants
block|}
block|}
name|void
name|populateLTOPassManager
parameter_list|(
name|PassManagerBase
modifier|&
name|PM
parameter_list|,
name|bool
name|Internalize
parameter_list|,
name|bool
name|RunInliner
parameter_list|)
block|{
comment|// Provide AliasAnalysis services for optimizations.
name|addInitialAliasAnalysisPasses
argument_list|(
name|PM
argument_list|)
expr_stmt|;
comment|// Now that composite has been compiled, scan through the module, looking
comment|// for a main function.  If main is defined, mark all other functions
comment|// internal.
if|if
condition|(
name|Internalize
condition|)
name|PM
operator|.
name|add
argument_list|(
name|createInternalizePass
argument_list|(
name|true
argument_list|)
argument_list|)
expr_stmt|;
comment|// Propagate constants at call sites into the functions they call.  This
comment|// opens opportunities for globalopt (and inlining) by substituting function
comment|// pointers passed as arguments to direct uses of functions.
name|PM
operator|.
name|add
argument_list|(
name|createIPSCCPPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Now that we internalized some globals, see if we can hack on them!
name|PM
operator|.
name|add
argument_list|(
name|createGlobalOptimizerPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Linking modules together can lead to duplicated global constants, only
comment|// keep one copy of each constant.
name|PM
operator|.
name|add
argument_list|(
name|createConstantMergePass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Remove unused arguments from functions.
name|PM
operator|.
name|add
argument_list|(
name|createDeadArgEliminationPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Reduce the code after globalopt and ipsccp.  Both can open up significant
comment|// simplification opportunities, and both can propagate functions through
comment|// function pointers.  When this happens, we often have to resolve varargs
comment|// calls, etc, so let instcombine do this.
name|PM
operator|.
name|add
argument_list|(
name|createInstructionCombiningPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Inline small functions
if|if
condition|(
name|RunInliner
condition|)
name|PM
operator|.
name|add
argument_list|(
name|createFunctionInliningPass
argument_list|()
argument_list|)
expr_stmt|;
name|PM
operator|.
name|add
argument_list|(
name|createPruneEHPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Remove dead EH info.
comment|// Optimize globals again if we ran the inliner.
if|if
condition|(
name|RunInliner
condition|)
name|PM
operator|.
name|add
argument_list|(
name|createGlobalOptimizerPass
argument_list|()
argument_list|)
expr_stmt|;
name|PM
operator|.
name|add
argument_list|(
name|createGlobalDCEPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Remove dead functions.
comment|// If we didn't decide to inline a function, check to see if we can
comment|// transform it to pass arguments by value instead of by reference.
name|PM
operator|.
name|add
argument_list|(
name|createArgumentPromotionPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// The IPO passes may leave cruft around.  Clean up after them.
name|PM
operator|.
name|add
argument_list|(
name|createInstructionCombiningPass
argument_list|()
argument_list|)
expr_stmt|;
name|PM
operator|.
name|add
argument_list|(
name|createJumpThreadingPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Break up allocas
name|PM
operator|.
name|add
argument_list|(
name|createScalarReplAggregatesPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Run a few AA driven optimizations here and now, to cleanup the code.
name|PM
operator|.
name|add
argument_list|(
name|createFunctionAttrsPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Add nocapture.
name|PM
operator|.
name|add
argument_list|(
name|createGlobalsModRefPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// IP alias analysis.
name|PM
operator|.
name|add
argument_list|(
name|createLICMPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Hoist loop invariants.
name|PM
operator|.
name|add
argument_list|(
name|createGVNPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Remove redundancies.
name|PM
operator|.
name|add
argument_list|(
name|createMemCpyOptPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Remove dead memcpys.
comment|// Nuke dead stores.
name|PM
operator|.
name|add
argument_list|(
name|createDeadStoreEliminationPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Cleanup and simplify the code after the scalar optimizations.
name|PM
operator|.
name|add
argument_list|(
name|createInstructionCombiningPass
argument_list|()
argument_list|)
expr_stmt|;
name|PM
operator|.
name|add
argument_list|(
name|createJumpThreadingPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Delete basic blocks, which optimization passes may have killed.
name|PM
operator|.
name|add
argument_list|(
name|createCFGSimplificationPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Now that we have optimized the program, discard unreachable functions.
name|PM
operator|.
name|add
argument_list|(
name|createGlobalDCEPass
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
empty_stmt|;
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

