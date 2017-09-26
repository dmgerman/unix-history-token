begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Transforms/IPO.h - Interprocedural Transformations --*- C++ -*-===//
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
comment|// in the IPO transformations library.
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
name|LLVM_TRANSFORMS_IPO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_IPO_H
end_define

begin_include
include|#
directive|include
file|<functional>
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
struct_decl|struct
name|InlineParams
struct_decl|;
name|class
name|StringRef
decl_stmt|;
name|class
name|ModuleSummaryIndex
decl_stmt|;
name|class
name|ModulePass
decl_stmt|;
name|class
name|Pass
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// These functions removes symbols from functions and modules.  If OnlyDebugInfo
comment|// is true, only debugging information is removed from the module.
comment|//
name|ModulePass
modifier|*
name|createStripSymbolsPass
parameter_list|(
name|bool
name|OnlyDebugInfo
init|=
name|false
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// These functions strips symbols from functions and modules.
comment|// Only debugging information is not stripped.
comment|//
name|ModulePass
modifier|*
name|createStripNonDebugSymbolsPass
parameter_list|()
function_decl|;
comment|/// This function returns a new pass that downgrades the debug info in the
comment|/// module to line tables only.
name|ModulePass
modifier|*
name|createStripNonLineTableDebugInfoPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// This pass removes llvm.dbg.declare intrinsics.
name|ModulePass
modifier|*
name|createStripDebugDeclarePass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// This pass removes unused symbols' debug info.
name|ModulePass
modifier|*
name|createStripDeadDebugInfoPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|/// createConstantMergePass - This function returns a new pass that merges
comment|/// duplicate global constants together into a single constant that is shared.
comment|/// This is useful because some passes (ie TraceValues) insert a lot of string
comment|/// constants into the program, regardless of whether or not they duplicate an
comment|/// existing string.
comment|///
name|ModulePass
modifier|*
name|createConstantMergePass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|/// createGlobalOptimizerPass - This function returns a new pass that optimizes
comment|/// non-address taken internal globals.
comment|///
name|ModulePass
modifier|*
name|createGlobalOptimizerPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|/// createGlobalDCEPass - This transform is designed to eliminate unreachable
comment|/// internal globals (functions or global variables)
comment|///
name|ModulePass
modifier|*
name|createGlobalDCEPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|/// This transform is designed to eliminate available external globals
comment|/// (functions or global variables)
comment|///
name|ModulePass
modifier|*
name|createEliminateAvailableExternallyPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|/// createGVExtractionPass - If deleteFn is true, this pass deletes
comment|/// the specified global values. Otherwise, it deletes as much of the module as
comment|/// possible, except for the global values specified.
comment|///
name|ModulePass
modifier|*
name|createGVExtractionPass
argument_list|(
name|std
operator|::
name|vector
operator|<
name|GlobalValue
operator|*
operator|>
operator|&
name|GVs
argument_list|,
name|bool
name|deleteFn
operator|=
name|false
argument_list|)
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// This pass performs iterative function importing from other modules.
name|Pass
modifier|*
name|createFunctionImportPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|/// createFunctionInliningPass - Return a new pass object that uses a heuristic
comment|/// to inline direct function calls to small functions.
comment|///
comment|/// The Threshold can be passed directly, or asked to be computed from the
comment|/// given optimization and size optimization arguments.
comment|///
comment|/// The -inline-threshold command line option takes precedence over the
comment|/// threshold given here.
name|Pass
modifier|*
name|createFunctionInliningPass
parameter_list|()
function_decl|;
name|Pass
modifier|*
name|createFunctionInliningPass
parameter_list|(
name|int
name|Threshold
parameter_list|)
function_decl|;
name|Pass
modifier|*
name|createFunctionInliningPass
parameter_list|(
name|unsigned
name|OptLevel
parameter_list|,
name|unsigned
name|SizeOptLevel
parameter_list|,
name|bool
name|DisableInlineHotCallSite
parameter_list|)
function_decl|;
name|Pass
modifier|*
name|createFunctionInliningPass
parameter_list|(
name|InlineParams
modifier|&
name|Params
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|/// createPruneEHPass - Return a new pass object which transforms invoke
comment|/// instructions into calls, if the callee can _not_ unwind the stack.
comment|///
name|Pass
modifier|*
name|createPruneEHPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|/// createInternalizePass - This pass loops over all of the functions in the
comment|/// input module, internalizing all globals (functions and variables) it can.
comment|////
comment|/// Before internalizing a symbol, the callback \p MustPreserveGV is invoked and
comment|/// gives to the client the ability to prevent internalizing specific symbols.
comment|///
comment|/// The symbol in DSOList are internalized if it is safe to drop them from
comment|/// the symbol table.
comment|///
comment|/// Note that commandline options that are used with the above function are not
comment|/// used now!
name|ModulePass
modifier|*
name|createInternalizePass
argument_list|(
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
specifier|const
name|GlobalValue
operator|&
argument_list|)
operator|>
name|MustPreserveGV
argument_list|)
decl_stmt|;
comment|/// createInternalizePass - Same as above, but with an empty exportList.
name|ModulePass
modifier|*
name|createInternalizePass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|/// createDeadArgEliminationPass - This pass removes arguments from functions
comment|/// which are not used by the body of the function.
comment|///
name|ModulePass
modifier|*
name|createDeadArgEliminationPass
parameter_list|()
function_decl|;
comment|/// DeadArgHacking pass - Same as DAE, but delete arguments of external
comment|/// functions as well.  This is definitely not safe, and should only be used by
comment|/// bugpoint.
name|ModulePass
modifier|*
name|createDeadArgHackingPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|/// createArgumentPromotionPass - This pass promotes "by reference" arguments to
comment|/// be passed by value if the number of elements passed is smaller or
comment|/// equal to maxElements (maxElements == 0 means always promote).
comment|///
name|Pass
modifier|*
name|createArgumentPromotionPass
parameter_list|(
name|unsigned
name|maxElements
init|=
literal|3
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|/// createIPConstantPropagationPass - This pass propagates constants from call
comment|/// sites into the bodies of functions.
comment|///
name|ModulePass
modifier|*
name|createIPConstantPropagationPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|/// createIPSCCPPass - This pass propagates constants from call sites into the
comment|/// bodies of functions, and keeps track of whether basic blocks are executable
comment|/// in the process.
comment|///
name|ModulePass
modifier|*
name|createIPSCCPPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|/// createLoopExtractorPass - This pass extracts all natural loops from the
comment|/// program into a function if it can.
comment|///
name|Pass
modifier|*
name|createLoopExtractorPass
parameter_list|()
function_decl|;
comment|/// createSingleLoopExtractorPass - This pass extracts one natural loop from the
comment|/// program into a function if it can.  This is used by bugpoint.
comment|///
name|Pass
modifier|*
name|createSingleLoopExtractorPass
parameter_list|()
function_decl|;
comment|/// createBlockExtractorPass - This pass extracts all blocks (except those
comment|/// specified in the argument list) from the functions in the module.
comment|///
name|ModulePass
modifier|*
name|createBlockExtractorPass
parameter_list|()
function_decl|;
comment|/// createStripDeadPrototypesPass - This pass removes any function declarations
comment|/// (prototypes) that are not used.
name|ModulePass
modifier|*
name|createStripDeadPrototypesPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|/// createReversePostOrderFunctionAttrsPass - This pass walks SCCs of the call
comment|/// graph in RPO to deduce and propagate function attributes. Currently it
comment|/// only handles synthesizing norecurse attributes.
comment|///
name|Pass
modifier|*
name|createReversePostOrderFunctionAttrsPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|/// createMergeFunctionsPass - This pass discovers identical functions and
comment|/// collapses them.
comment|///
name|ModulePass
modifier|*
name|createMergeFunctionsPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|/// createPartialInliningPass - This pass inlines parts of functions.
comment|///
name|ModulePass
modifier|*
name|createPartialInliningPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|// createMetaRenamerPass - Rename everything with metasyntatic names.
comment|//
name|ModulePass
modifier|*
name|createMetaRenamerPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|/// createBarrierNoopPass - This pass is purely a module pass barrier in a pass
comment|/// manager.
name|ModulePass
modifier|*
name|createBarrierNoopPass
parameter_list|()
function_decl|;
comment|/// What to do with the summary when running passes that operate on it.
name|enum
name|class
name|PassSummaryAction
block|{
name|None
operator|,
comment|///< Do nothing.
name|Import
operator|,
comment|///< Import information from summary.
name|Export
operator|,
comment|///< Export information to summary.
block|}
empty_stmt|;
comment|/// \brief This pass lowers type metadata and the llvm.type.test intrinsic to
comment|/// bitsets.
comment|///
comment|/// The behavior depends on the summary arguments:
comment|/// - If ExportSummary is non-null, this pass will export type identifiers to
comment|///   the given summary.
comment|/// - Otherwise, if ImportSummary is non-null, this pass will import type
comment|///   identifiers from the given summary.
comment|/// - Otherwise it does neither.
comment|/// It is invalid for both ExportSummary and ImportSummary to be non-null.
name|ModulePass
modifier|*
name|createLowerTypeTestsPass
parameter_list|(
name|ModuleSummaryIndex
modifier|*
name|ExportSummary
parameter_list|,
specifier|const
name|ModuleSummaryIndex
modifier|*
name|ImportSummary
parameter_list|)
function_decl|;
comment|/// \brief This pass export CFI checks for use by external modules.
name|ModulePass
modifier|*
name|createCrossDSOCFIPass
parameter_list|()
function_decl|;
comment|/// \brief This pass implements whole-program devirtualization using type
comment|/// metadata.
comment|///
comment|/// The behavior depends on the summary arguments:
comment|/// - If ExportSummary is non-null, this pass will export type identifiers to
comment|///   the given summary.
comment|/// - Otherwise, if ImportSummary is non-null, this pass will import type
comment|///   identifiers from the given summary.
comment|/// - Otherwise it does neither.
comment|/// It is invalid for both ExportSummary and ImportSummary to be non-null.
name|ModulePass
modifier|*
name|createWholeProgramDevirtPass
parameter_list|(
name|ModuleSummaryIndex
modifier|*
name|ExportSummary
parameter_list|,
specifier|const
name|ModuleSummaryIndex
modifier|*
name|ImportSummary
parameter_list|)
function_decl|;
comment|/// This pass splits globals into pieces for the benefit of whole-program
comment|/// devirtualization and control-flow integrity.
name|ModulePass
modifier|*
name|createGlobalSplitPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|// SampleProfilePass - Loads sample profile data from disk and generates
comment|// IR metadata to reflect the profile.
name|ModulePass
modifier|*
name|createSampleProfileLoaderPass
parameter_list|()
function_decl|;
name|ModulePass
modifier|*
name|createSampleProfileLoaderPass
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
comment|/// Write ThinLTO-ready bitcode to Str.
name|ModulePass
modifier|*
name|createWriteThinLTOBitcodePass
parameter_list|(
name|raw_ostream
modifier|&
name|Str
parameter_list|,
name|raw_ostream
modifier|*
name|ThinLinkOS
init|=
name|nullptr
parameter_list|)
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

