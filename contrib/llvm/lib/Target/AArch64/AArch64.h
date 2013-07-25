begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- AArch64.h - Top-level interface for AArch64 representation -*- C++ -*-=//
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
comment|// AArch64 back-end.
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
name|LLVM_TARGET_AARCH64_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_AARCH64_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/AArch64MCTargetDesc.h"
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
name|AArch64AsmPrinter
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|class
name|AArch64TargetMachine
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|FunctionPass
modifier|*
name|createAArch64ISelDAG
argument_list|(
name|AArch64TargetMachine
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
name|createAArch64CleanupLocalDynamicTLSPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createAArch64BranchFixupPass
parameter_list|()
function_decl|;
name|void
name|LowerAArch64MachineInstrToMCInst
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|,
name|MCInst
modifier|&
name|OutMI
parameter_list|,
name|AArch64AsmPrinter
modifier|&
name|AP
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

