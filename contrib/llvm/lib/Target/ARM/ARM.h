begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARM.h - Top-level interface for ARM representation ------*- C++ -*-===//
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
name|LLVM_LIB_TARGET_ARM_ARM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_ARM_ARM_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/CodeGen.h"
end_include

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
name|class
name|ARMAsmPrinter
decl_stmt|;
name|class
name|ARMBaseTargetMachine
decl_stmt|;
name|class
name|ARMRegisterBankInfo
decl_stmt|;
name|class
name|ARMSubtarget
decl_stmt|;
struct_decl|struct
name|BasicBlockInfo
struct_decl|;
name|class
name|Function
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|class
name|InstructionSelector
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|PassRegistry
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
name|createA15SDOptimizerPass
parameter_list|()
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
name|createARMConstantIslandPass
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
name|createARMOptimizeBarriersPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createThumb2SizeReductionPass
argument_list|(
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
specifier|const
name|Function
operator|&
argument_list|)
operator|>
name|Ftor
operator|=
name|nullptr
argument_list|)
decl_stmt|;
name|InstructionSelector
modifier|*
name|createARMInstructionSelector
parameter_list|(
specifier|const
name|ARMBaseTargetMachine
modifier|&
name|TM
parameter_list|,
specifier|const
name|ARMSubtarget
modifier|&
name|STI
parameter_list|,
specifier|const
name|ARMRegisterBankInfo
modifier|&
name|RBI
parameter_list|)
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
name|void
name|computeBlockSize
parameter_list|(
name|MachineFunction
modifier|*
name|MF
parameter_list|,
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|,
name|BasicBlockInfo
modifier|&
name|BBI
parameter_list|)
function_decl|;
name|std
operator|::
name|vector
operator|<
name|BasicBlockInfo
operator|>
name|computeAllBlockSizes
argument_list|(
name|MachineFunction
operator|*
name|MF
argument_list|)
expr_stmt|;
name|void
name|initializeARMLoadStoreOptPass
parameter_list|(
name|PassRegistry
modifier|&
parameter_list|)
function_decl|;
name|void
name|initializeARMPreAllocLoadStoreOptPass
parameter_list|(
name|PassRegistry
modifier|&
parameter_list|)
function_decl|;
name|void
name|initializeARMConstantIslandsPass
parameter_list|(
name|PassRegistry
modifier|&
parameter_list|)
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

begin_comment
comment|// LLVM_LIB_TARGET_ARM_ARM_H
end_comment

end_unit

