begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Mips.h - Top-level interface for Mips representation ----*- C++ -*-===//
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
comment|// This file contains the entry points for global functions defined in
end_comment

begin_comment
comment|// the LLVM Mips back-end.
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
name|LLVM_LIB_TARGET_MIPS_MIPS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MIPS_MIPS_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/MipsMCTargetDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MipsTargetMachine
decl_stmt|;
name|class
name|ModulePass
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|ModulePass
modifier|*
name|createMipsOs16Pass
parameter_list|()
function_decl|;
name|ModulePass
modifier|*
name|createMips16HardFloatPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createMipsModuleISelDagPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createMipsOptimizePICCallPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createMipsDelaySlotFillerPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createMipsHazardSchedule
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createMipsLongBranchPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createMipsConstantIslandPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createMicroMipsSizeReductionPass
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm;
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

