begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- WebAssembly.h - Top-level interface for WebAssembly  ----*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file contains the entry points for global functions defined in
end_comment

begin_comment
comment|/// the LLVM WebAssembly back-end.
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
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLY_H
end_define

begin_include
include|#
directive|include
file|"llvm/PassRegistry.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CodeGen.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|WebAssemblyTargetMachine
decl_stmt|;
name|class
name|ModulePass
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
comment|// LLVM IR passes.
name|ModulePass
modifier|*
name|createWebAssemblyLowerEmscriptenEHSjLj
parameter_list|(
name|bool
name|DoEH
parameter_list|,
name|bool
name|DoSjLj
parameter_list|)
function_decl|;
name|void
name|initializeWebAssemblyLowerEmscriptenEHSjLjPass
parameter_list|(
name|PassRegistry
modifier|&
parameter_list|)
function_decl|;
name|ModulePass
modifier|*
name|createWebAssemblyFixFunctionBitcasts
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createWebAssemblyOptimizeReturned
parameter_list|()
function_decl|;
comment|// ISel and immediate followup passes.
name|FunctionPass
modifier|*
name|createWebAssemblyISelDag
argument_list|(
name|WebAssemblyTargetMachine
operator|&
name|TM
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|)
decl_stmt|;
name|FunctionPass
modifier|*
name|createWebAssemblyArgumentMove
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createWebAssemblySetP2AlignOperands
parameter_list|()
function_decl|;
comment|// Late passes.
name|FunctionPass
modifier|*
name|createWebAssemblyReplacePhysRegs
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createWebAssemblyPrepareForLiveIntervals
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createWebAssemblyOptimizeLiveIntervals
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createWebAssemblyStoreResults
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createWebAssemblyRegStackify
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createWebAssemblyRegColoring
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createWebAssemblyExplicitLocals
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createWebAssemblyFixIrreducibleControlFlow
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createWebAssemblyCFGSort
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createWebAssemblyCFGStackify
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createWebAssemblyLowerBrUnless
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createWebAssemblyRegNumbering
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createWebAssemblyPeephole
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createWebAssemblyCallIndirectFixup
parameter_list|()
function_decl|;
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

