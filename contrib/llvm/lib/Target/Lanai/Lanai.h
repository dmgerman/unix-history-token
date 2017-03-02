begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Lanai.h - Top-level interface for Lanai representation --*- C++ -*-===//
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
comment|// This file contains the entry points for global functions defined in the LLVM
end_comment

begin_comment
comment|// Lanai back-end.
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
name|LLVM_LIB_TARGET_LANAI_LANAI_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_LANAI_LANAI_H
end_define

begin_include
include|#
directive|include
file|"LanaiAluCode.h"
end_include

begin_include
include|#
directive|include
file|"LanaiCondCode.h"
end_include

begin_include
include|#
directive|include
file|"MCTargetDesc/LanaiBaseInfo.h"
end_include

begin_include
include|#
directive|include
file|"MCTargetDesc/LanaiMCTargetDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ISDOpcodes.h"
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
name|FunctionPass
decl_stmt|;
name|class
name|LanaiTargetMachine
decl_stmt|;
name|class
name|MachineFunctionPass
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|formatted_raw_ostream
decl_stmt|;
comment|// createLanaiISelDag - This pass converts a legalized DAG into a
comment|// Lanai-specific DAG, ready for instruction scheduling.
name|FunctionPass
modifier|*
name|createLanaiISelDag
parameter_list|(
name|LanaiTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
comment|// createLanaiDelaySlotFillerPass - This pass fills delay slots
comment|// with useful instructions or nop's
name|FunctionPass
modifier|*
name|createLanaiDelaySlotFillerPass
parameter_list|(
specifier|const
name|LanaiTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
comment|// createLanaiMemAluCombinerPass - This pass combines loads/stores and
comment|// arithmetic operations.
name|FunctionPass
modifier|*
name|createLanaiMemAluCombinerPass
parameter_list|()
function_decl|;
comment|// createLanaiSetflagAluCombinerPass - This pass combines SET_FLAG and ALU
comment|// operations.
name|FunctionPass
modifier|*
name|createLanaiSetflagAluCombinerPass
parameter_list|()
function_decl|;
name|Target
modifier|&
name|getTheLanaiTarget
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_LANAI_LANAI_H
end_comment

end_unit

