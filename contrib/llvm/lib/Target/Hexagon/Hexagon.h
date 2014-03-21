begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=-- Hexagon.h - Top-level interface for Hexagon representation --*- C++ -*-=//
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
comment|// Hexagon back-end.
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
name|TARGET_Hexagon_H
end_ifndef

begin_define
define|#
directive|define
name|TARGET_Hexagon_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/HexagonMCTargetDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetLowering.h"
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
name|ModulePass
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|HexagonMCInst
decl_stmt|;
name|class
name|HexagonAsmPrinter
decl_stmt|;
name|class
name|HexagonTargetMachine
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|FunctionPass
modifier|*
name|createHexagonISelDag
argument_list|(
name|HexagonTargetMachine
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
name|createHexagonDelaySlotFillerPass
parameter_list|(
specifier|const
name|TargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createHexagonFPMoverPass
parameter_list|(
specifier|const
name|TargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createHexagonRemoveExtendArgs
parameter_list|(
specifier|const
name|HexagonTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createHexagonCFGOptimizer
parameter_list|(
specifier|const
name|HexagonTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createHexagonSplitTFRCondSets
parameter_list|(
specifier|const
name|HexagonTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createHexagonSplitConst32AndConst64
parameter_list|(
specifier|const
name|HexagonTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createHexagonExpandPredSpillCode
parameter_list|(
specifier|const
name|HexagonTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createHexagonHardwareLoops
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createHexagonPeephole
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createHexagonFixupHwLoops
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createHexagonNewValueJump
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createHexagonCopyToCombine
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createHexagonPacketizer
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createHexagonNewValueJump
parameter_list|()
function_decl|;
comment|/* TODO: object output.   MCCodeEmitter *createHexagonMCCodeEmitter(const Target&,                                             const TargetMachine&TM,                                             MCContext&Ctx); */
comment|/* TODO: assembler input.   TargetAsmBackend *createHexagonAsmBackend(const Target&,                                                   const std::string&); */
name|void
name|HexagonLowerToMC
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|,
name|HexagonMCInst
modifier|&
name|MCI
parameter_list|,
name|HexagonAsmPrinter
modifier|&
name|AP
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm;
end_comment

begin_define
define|#
directive|define
name|Hexagon_POINTER_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|Hexagon_PointerSize
value|(Hexagon_POINTER_SIZE)
end_define

begin_define
define|#
directive|define
name|Hexagon_PointerSize_Bits
value|(Hexagon_POINTER_SIZE * 8)
end_define

begin_define
define|#
directive|define
name|Hexagon_WordSize
value|Hexagon_PointerSize
end_define

begin_define
define|#
directive|define
name|Hexagon_WordSize_Bits
value|Hexagon_PointerSize_Bits
end_define

begin_comment
comment|// allocframe saves LR and FP on stack before allocating
end_comment

begin_comment
comment|// a new stack frame. This takes 8 bytes.
end_comment

begin_define
define|#
directive|define
name|HEXAGON_LRFP_SIZE
value|8
end_define

begin_comment
comment|// Normal instruction size (in bytes).
end_comment

begin_define
define|#
directive|define
name|HEXAGON_INSTR_SIZE
value|4
end_define

begin_comment
comment|// Maximum number of words and instructions in a packet.
end_comment

begin_define
define|#
directive|define
name|HEXAGON_PACKET_SIZE
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

