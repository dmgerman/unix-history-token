begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARM.h - Top-level interface for ARM representation---- --*- C++ -*-===//
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
comment|// ARM back-end.
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
name|TARGET_ARM_H
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ARM_H
end_define

begin_include
include|#
directive|include
file|"ARMBaseInfo.h"
end_include

begin_include
include|#
directive|include
file|"MCTargetDesc/ARMMCTargetDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ARMAsmPrinter
decl_stmt|;
name|class
name|ARMBaseTargetMachine
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|class
name|JITCodeEmitter
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MCCodeEmitter
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|MCInstrInfo
decl_stmt|;
name|class
name|MCObjectWriter
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|class
name|TargetAsmBackend
decl_stmt|;
name|class
name|formatted_raw_ostream
decl_stmt|;
name|MCCodeEmitter
modifier|*
name|createARMMCCodeEmitter
parameter_list|(
specifier|const
name|MCInstrInfo
modifier|&
name|MCII
parameter_list|,
specifier|const
name|MCSubtargetInfo
modifier|&
name|STI
parameter_list|,
name|MCContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
name|TargetAsmBackend
modifier|*
name|createARMAsmBackend
argument_list|(
specifier|const
name|Target
operator|&
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
argument_list|)
decl_stmt|;
name|FunctionPass
modifier|*
name|createARMISelDag
argument_list|(
name|ARMBaseTargetMachine
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
name|createARMJITCodeEmitterPass
parameter_list|(
name|ARMBaseTargetMachine
modifier|&
name|TM
parameter_list|,
name|JITCodeEmitter
modifier|&
name|JCE
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createARMLoadStoreOptimizationPass
parameter_list|(
name|bool
name|PreAlloc
init|=
name|false
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createARMExpandPseudoPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createARMGlobalMergePass
parameter_list|(
specifier|const
name|TargetLowering
modifier|*
name|tli
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createARMConstantIslandPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createNEONMoveFixPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createMLxExpansionPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createThumb2ITBlockPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createThumb2SizeReductionPass
parameter_list|()
function_decl|;
name|void
name|LowerARMMachineInstrToMCInst
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
name|ARMAsmPrinter
modifier|&
name|AP
parameter_list|)
function_decl|;
comment|/// createARMMachObjectWriter - Construct an ARM Mach-O object writer.
name|MCObjectWriter
modifier|*
name|createARMMachObjectWriter
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|bool
name|Is64Bit
parameter_list|,
name|uint32_t
name|CPUType
parameter_list|,
name|uint32_t
name|CPUSubtype
parameter_list|)
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

