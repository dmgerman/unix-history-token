begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Analysis/Passes.h - Constructors for analyses ------*- C++ -*-===//
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
comment|// in the analysis libraries.
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
name|LLVM_ANALYSIS_PASSES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_PASSES_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FunctionPass
decl_stmt|;
name|class
name|ImmutablePass
decl_stmt|;
name|class
name|LoopPass
decl_stmt|;
name|class
name|ModulePass
decl_stmt|;
name|class
name|Pass
decl_stmt|;
name|class
name|PassInfo
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|//
comment|// createAAEvalPass - This pass implements a simple N^2 alias analysis
comment|// accuracy evaluator.
comment|//
name|FunctionPass
modifier|*
name|createAAEvalPass
parameter_list|()
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|//
comment|// createObjCARCAAWrapperPass - This pass implements ObjC-ARC-based
comment|// alias analysis.
comment|//
name|ImmutablePass
modifier|*
name|createObjCARCAAWrapperPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createPAEvalPass
parameter_list|()
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|//
comment|/// createLazyValueInfoPass - This creates an instance of the LazyValueInfo
comment|/// pass.
name|FunctionPass
modifier|*
name|createLazyValueInfoPass
parameter_list|()
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|//
comment|// createDependenceAnalysisPass - This creates an instance of the
comment|// DependenceAnalysis pass.
comment|//
name|FunctionPass
modifier|*
name|createDependenceAnalysisPass
parameter_list|()
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|//
comment|// createCostModelAnalysisPass - This creates an instance of the
comment|// CostModelAnalysis pass.
comment|//
name|FunctionPass
modifier|*
name|createCostModelAnalysisPass
parameter_list|()
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|//
comment|// createDelinearizationPass - This pass implements attempts to restore
comment|// multidimensional array indices from linearized expressions.
comment|//
name|FunctionPass
modifier|*
name|createDelinearizationPass
parameter_list|()
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|//
comment|// createDivergenceAnalysisPass - This pass determines which branches in a GPU
comment|// program are divergent.
comment|//
name|FunctionPass
modifier|*
name|createDivergenceAnalysisPass
parameter_list|()
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|//
comment|// Minor pass prototypes, allowing us to expose them through bugpoint and
comment|// analyze.
name|FunctionPass
modifier|*
name|createInstCountPass
parameter_list|()
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|//
comment|// createRegionInfoPass - This pass finds all single entry single exit regions
comment|// in a function and builds the region hierarchy.
comment|//
name|FunctionPass
modifier|*
name|createRegionInfoPass
parameter_list|()
function_decl|;
comment|// Print module-level debug info metadata in human-readable form.
name|ModulePass
modifier|*
name|createModuleDebugInfoPrinterPass
parameter_list|()
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|//
comment|// createMemDepPrinter - This pass exhaustively collects all memdep
comment|// information and prints it with -analyze.
comment|//
name|FunctionPass
modifier|*
name|createMemDepPrinter
parameter_list|()
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|//
comment|// createMemDerefPrinter - This pass collects memory dereferenceability
comment|// information and prints it with -analyze.
comment|//
name|FunctionPass
modifier|*
name|createMemDerefPrinter
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

