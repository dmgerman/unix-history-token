begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PTX.h - Top-level interface for PTX representation ------*- C++ -*-===//
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
comment|// PTX back-end.
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
name|PTX_H
end_ifndef

begin_define
define|#
directive|define
name|PTX_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/PTXBaseInfo.h"
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
name|MachineInstr
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|PTXAsmPrinter
decl_stmt|;
name|class
name|PTXTargetMachine
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|FunctionPass
modifier|*
name|createPTXISelDag
argument_list|(
name|PTXTargetMachine
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
name|createPTXMFInfoExtract
argument_list|(
name|PTXTargetMachine
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
name|createPTXFPRoundingModePass
argument_list|(
name|PTXTargetMachine
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
name|createPTXRegisterAllocator
parameter_list|()
function_decl|;
name|void
name|LowerPTXMachineInstrToMCInst
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
name|PTXAsmPrinter
modifier|&
name|AP
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm;
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// PTX_H
end_comment

end_unit

