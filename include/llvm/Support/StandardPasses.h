begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/StandardPasses.h - Standard pass lists -----*- C++ -*-===//
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
comment|// This file defines utility functions for creating a "standard" set of
end_comment

begin_comment
comment|// optimization passes, so that compilers and tools which use optimization
end_comment

begin_comment
comment|// passes use the same set of standard passes.
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
name|LLVM_SUPPORT_STANDARDPASSES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_STANDARDPASSES_H
end_define

begin_include
include|#
directive|include
file|"llvm/PassManager.h"
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
comment|/// createStandardFunctionPasses - Add the standard list of function passes to
comment|/// the provided pass manager.
comment|///
comment|/// \arg OptimizationLevel - The optimization level, corresponding to -O0,
comment|/// -O1, etc.
specifier|static
specifier|inline
name|void
name|createStandardFunctionPasses
parameter_list|(
name|FunctionPassManager
modifier|*
name|PM
parameter_list|,
name|unsigned
name|OptimizationLevel
parameter_list|)
function_decl|;
comment|/// createStandardModulePasses - Add the standard list of module passes to the
comment|/// provided pass manager.
comment|///
comment|/// \arg OptimizationLevel - The optimization level, corresponding to -O0,
comment|/// -O1, etc.
comment|/// \arg OptimizeSize - Whether the transformations should optimize for size.
comment|/// \arg UnitAtATime - Allow passes which may make global module changes.
comment|/// \arg UnrollLoops - Allow loop unrolling.
comment|/// \arg SimplifyLibCalls - Allow library calls to be simplified.
comment|/// \arg HaveExceptions - Whether the module may have code using exceptions.
comment|/// \arg InliningPass - The inlining pass to use, if any, or null. This will
comment|/// always be added, even at -O0.a
specifier|static
specifier|inline
name|void
name|createStandardModulePasses
parameter_list|(
name|PassManager
modifier|*
name|PM
parameter_list|,
name|unsigned
name|OptimizationLevel
parameter_list|,
name|bool
name|OptimizeSize
parameter_list|,
name|bool
name|UnitAtATime
parameter_list|,
name|bool
name|UnrollLoops
parameter_list|,
name|bool
name|SimplifyLibCalls
parameter_list|,
name|bool
name|HaveExceptions
parameter_list|,
name|Pass
modifier|*
name|InliningPass
parameter_list|)
function_decl|;
comment|/// createStandardLTOPasses - Add the standard list of module passes suitable
comment|/// for link time optimization.
comment|///
comment|/// Internalize - Run the internalize pass.
comment|/// RunInliner - Use a function inlining pass.
comment|/// VerifyEach - Run the verifier after each pass.
specifier|static
specifier|inline
name|void
name|createStandardLTOPasses
parameter_list|(
name|PassManager
modifier|*
name|PM
parameter_list|,
name|bool
name|Internalize
parameter_list|,
name|bool
name|RunInliner
parameter_list|,
name|bool
name|VerifyEach
parameter_list|)
function_decl|;
comment|// Implementations
specifier|static
specifier|inline
name|void
name|createStandardFunctionPasses
parameter_list|(
name|FunctionPassManager
modifier|*
name|PM
parameter_list|,
name|unsigned
name|OptimizationLevel
parameter_list|)
block|{
if|if
condition|(
name|OptimizationLevel
operator|>
literal|0
condition|)
block|{
name|PM
operator|->
name|add
argument_list|(
name|createCFGSimplificationPass
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|OptimizationLevel
operator|==
literal|1
condition|)
name|PM
operator|->
name|add
argument_list|(
name|createPromoteMemoryToRegisterPass
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|PM
operator|->
name|add
argument_list|(
name|createScalarReplAggregatesPass
argument_list|()
argument_list|)
expr_stmt|;
name|PM
operator|->
name|add
argument_list|(
name|createInstructionCombiningPass
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
comment|/// createStandardModulePasses - Add the standard module passes.  This is
comment|/// expected to be run after the standard function passes.
specifier|static
specifier|inline
name|void
name|createStandardModulePasses
parameter_list|(
name|PassManager
modifier|*
name|PM
parameter_list|,
name|unsigned
name|OptimizationLevel
parameter_list|,
name|bool
name|OptimizeSize
parameter_list|,
name|bool
name|UnitAtATime
parameter_list|,
name|bool
name|UnrollLoops
parameter_list|,
name|bool
name|SimplifyLibCalls
parameter_list|,
name|bool
name|HaveExceptions
parameter_list|,
name|Pass
modifier|*
name|InliningPass
parameter_list|)
block|{
if|if
condition|(
name|OptimizationLevel
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|InliningPass
condition|)
name|PM
operator|->
name|add
argument_list|(
name|InliningPass
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|UnitAtATime
condition|)
block|{
name|PM
operator|->
name|add
argument_list|(
name|createGlobalOptimizerPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Optimize out global vars
name|PM
operator|->
name|add
argument_list|(
name|createIPSCCPPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// IP SCCP
name|PM
operator|->
name|add
argument_list|(
name|createDeadArgEliminationPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Dead argument elimination
block|}
name|PM
operator|->
name|add
argument_list|(
name|createInstructionCombiningPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Clean up after IPCP& DAE
name|PM
operator|->
name|add
argument_list|(
name|createCFGSimplificationPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Clean up after IPCP& DAE
comment|// Start of CallGraph SCC passes.
if|if
condition|(
name|UnitAtATime
operator|&&
name|HaveExceptions
condition|)
name|PM
operator|->
name|add
argument_list|(
name|createPruneEHPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Remove dead EH info
if|if
condition|(
name|InliningPass
condition|)
name|PM
operator|->
name|add
argument_list|(
name|InliningPass
argument_list|)
expr_stmt|;
if|if
condition|(
name|UnitAtATime
condition|)
name|PM
operator|->
name|add
argument_list|(
name|createFunctionAttrsPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Set readonly/readnone attrs
if|if
condition|(
name|OptimizationLevel
operator|>
literal|2
condition|)
name|PM
operator|->
name|add
argument_list|(
name|createArgumentPromotionPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Scalarize uninlined fn args
comment|// Start of function pass.
name|PM
operator|->
name|add
argument_list|(
name|createScalarReplAggregatesPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Break up aggregate allocas
if|if
condition|(
name|SimplifyLibCalls
condition|)
name|PM
operator|->
name|add
argument_list|(
name|createSimplifyLibCallsPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Library Call Optimizations
name|PM
operator|->
name|add
argument_list|(
name|createInstructionCombiningPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Cleanup for scalarrepl.
name|PM
operator|->
name|add
argument_list|(
name|createJumpThreadingPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Thread jumps.
name|PM
operator|->
name|add
argument_list|(
name|createCFGSimplificationPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Merge& remove BBs
name|PM
operator|->
name|add
argument_list|(
name|createInstructionCombiningPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Combine silly seq's
name|PM
operator|->
name|add
argument_list|(
name|createTailCallEliminationPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Eliminate tail calls
name|PM
operator|->
name|add
argument_list|(
name|createCFGSimplificationPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Merge& remove BBs
name|PM
operator|->
name|add
argument_list|(
name|createReassociatePass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Reassociate expressions
name|PM
operator|->
name|add
argument_list|(
name|createLoopRotatePass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Rotate Loop
name|PM
operator|->
name|add
argument_list|(
name|createLICMPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Hoist loop invariants
name|PM
operator|->
name|add
argument_list|(
name|createLoopUnswitchPass
argument_list|(
name|OptimizeSize
operator|||
name|OptimizationLevel
operator|<
literal|3
argument_list|)
argument_list|)
expr_stmt|;
name|PM
operator|->
name|add
argument_list|(
name|createInstructionCombiningPass
argument_list|()
argument_list|)
expr_stmt|;
name|PM
operator|->
name|add
argument_list|(
name|createIndVarSimplifyPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Canonicalize indvars
name|PM
operator|->
name|add
argument_list|(
name|createLoopDeletionPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Delete dead loops
if|if
condition|(
name|UnrollLoops
condition|)
name|PM
operator|->
name|add
argument_list|(
name|createLoopUnrollPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Unroll small loops
name|PM
operator|->
name|add
argument_list|(
name|createInstructionCombiningPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Clean up after the unroller
if|if
condition|(
name|OptimizationLevel
operator|>
literal|1
condition|)
name|PM
operator|->
name|add
argument_list|(
name|createGVNPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Remove redundancies
name|PM
operator|->
name|add
argument_list|(
name|createMemCpyOptPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Remove memcpy / form memset
name|PM
operator|->
name|add
argument_list|(
name|createSCCPPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Constant prop with SCCP
comment|// Run instcombine after redundancy elimination to exploit opportunities
comment|// opened up by them.
name|PM
operator|->
name|add
argument_list|(
name|createInstructionCombiningPass
argument_list|()
argument_list|)
expr_stmt|;
name|PM
operator|->
name|add
argument_list|(
name|createJumpThreadingPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Thread jumps
name|PM
operator|->
name|add
argument_list|(
name|createDeadStoreEliminationPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Delete dead stores
name|PM
operator|->
name|add
argument_list|(
name|createAggressiveDCEPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Delete dead instructions
name|PM
operator|->
name|add
argument_list|(
name|createCFGSimplificationPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Merge& remove BBs
if|if
condition|(
name|UnitAtATime
condition|)
block|{
name|PM
operator|->
name|add
argument_list|(
name|createStripDeadPrototypesPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Get rid of dead prototypes
name|PM
operator|->
name|add
argument_list|(
name|createDeadTypeEliminationPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Eliminate dead types
comment|// GlobalOpt already deletes dead functions and globals, at -O3 try a
comment|// late pass of GlobalDCE.  It is capable of deleting dead cycles.
if|if
condition|(
name|OptimizationLevel
operator|>
literal|2
condition|)
name|PM
operator|->
name|add
argument_list|(
name|createGlobalDCEPass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Remove dead fns and globals.
if|if
condition|(
name|OptimizationLevel
operator|>
literal|1
condition|)
name|PM
operator|->
name|add
argument_list|(
name|createConstantMergePass
argument_list|()
argument_list|)
expr_stmt|;
comment|// Merge dup global constants
block|}
block|}
specifier|static
specifier|inline
name|void
name|addOnePass
parameter_list|(
name|PassManager
modifier|*
name|PM
parameter_list|,
name|Pass
modifier|*
name|P
parameter_list|,
name|bool
name|AndVerify
parameter_list|)
block|{
name|PM
operator|->
name|add
argument_list|(
name|P
argument_list|)
expr_stmt|;
if|if
condition|(
name|AndVerify
condition|)
name|PM
operator|->
name|add
argument_list|(
name|createVerifierPass
argument_list|()
argument_list|)
expr_stmt|;
block|}
specifier|static
specifier|inline
name|void
name|createStandardLTOPasses
parameter_list|(
name|PassManager
modifier|*
name|PM
parameter_list|,
name|bool
name|Internalize
parameter_list|,
name|bool
name|RunInliner
parameter_list|,
name|bool
name|VerifyEach
parameter_list|)
block|{
comment|// Now that composite has been compiled, scan through the module, looking
comment|// for a main function.  If main is defined, mark all other functions
comment|// internal.
if|if
condition|(
name|Internalize
condition|)
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createInternalizePass
argument_list|(
name|true
argument_list|)
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
comment|// Propagate constants at call sites into the functions they call.  This
comment|// opens opportunities for globalopt (and inlining) by substituting function
comment|// pointers passed as arguments to direct uses of functions.
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createIPSCCPPass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
comment|// Now that we internalized some globals, see if we can hack on them!
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createGlobalOptimizerPass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
comment|// Linking modules together can lead to duplicated global constants, only
comment|// keep one copy of each constant...
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createConstantMergePass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
comment|// Remove unused arguments from functions...
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createDeadArgEliminationPass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
comment|// Reduce the code after globalopt and ipsccp.  Both can open up significant
comment|// simplification opportunities, and both can propagate functions through
comment|// function pointers.  When this happens, we often have to resolve varargs
comment|// calls, etc, so let instcombine do this.
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createInstructionCombiningPass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
comment|// Inline small functions
if|if
condition|(
name|RunInliner
condition|)
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createFunctionInliningPass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createPruneEHPass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
comment|// Remove dead EH info.
comment|// Optimize globals again if we ran the inliner.
if|if
condition|(
name|RunInliner
condition|)
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createGlobalOptimizerPass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createGlobalDCEPass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
comment|// Remove dead functions.
comment|// If we didn't decide to inline a function, check to see if we can
comment|// transform it to pass arguments by value instead of by reference.
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createArgumentPromotionPass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
comment|// The IPO passes may leave cruft around.  Clean up after them.
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createInstructionCombiningPass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createJumpThreadingPass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
comment|// Break up allocas
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createScalarReplAggregatesPass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
comment|// Run a few AA driven optimizations here and now, to cleanup the code.
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createFunctionAttrsPass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
comment|// Add nocapture.
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createGlobalsModRefPass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
comment|// IP alias analysis.
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createLICMPass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
comment|// Hoist loop invariants.
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createGVNPass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
comment|// Remove redundancies.
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createMemCpyOptPass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
comment|// Remove dead memcpys.
comment|// Nuke dead stores.
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createDeadStoreEliminationPass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
comment|// Cleanup and simplify the code after the scalar optimizations.
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createInstructionCombiningPass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createJumpThreadingPass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
comment|// Delete basic blocks, which optimization passes may have killed.
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createCFGSimplificationPass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
comment|// Now that we have optimized the program, discard unreachable functions.
name|addOnePass
argument_list|(
name|PM
argument_list|,
name|createGlobalDCEPass
argument_list|()
argument_list|,
name|VerifyEach
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

