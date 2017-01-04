begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsSEISelDAGToDAG.h - A Dag to Dag Inst Selector for MipsSE -----===//
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
comment|// Subclass of MipsDAGToDAGISel specialized for mips32/64.
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
name|LLVM_LIB_TARGET_MIPS_MIPSSEISELDAGTODAG_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MIPS_MIPSSEISELDAGTODAG_H
end_define

begin_include
include|#
directive|include
file|"MipsISelDAGToDAG.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MipsSEDAGToDAGISel
range|:
name|public
name|MipsDAGToDAGISel
block|{
name|public
operator|:
name|explicit
name|MipsSEDAGToDAGISel
argument_list|(
argument|MipsTargetMachine&TM
argument_list|,
argument|CodeGenOpt::Level OL
argument_list|)
operator|:
name|MipsDAGToDAGISel
argument_list|(
argument|TM
argument_list|,
argument|OL
argument_list|)
block|{}
name|private
operator|:
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
block|;
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
name|void
name|addDSPCtrlRegOperands
argument_list|(
argument|bool IsDef
argument_list|,
argument|MachineInstr&MI
argument_list|,
argument|MachineFunction&MF
argument_list|)
block|;
name|unsigned
name|getMSACtrlReg
argument_list|(
argument|const SDValue RegIdx
argument_list|)
specifier|const
block|;
name|bool
name|replaceUsesWithZeroReg
argument_list|(
name|MachineRegisterInfo
operator|*
name|MRI
argument_list|,
specifier|const
name|MachineInstr
operator|&
argument_list|)
block|;
name|std
operator|::
name|pair
operator|<
name|SDNode
operator|*
block|,
name|SDNode
operator|*
operator|>
name|selectMULT
argument_list|(
argument|SDNode *N
argument_list|,
argument|unsigned Opc
argument_list|,
argument|const SDLoc&dl
argument_list|,
argument|EVT Ty
argument_list|,
argument|bool HasLo
argument_list|,
argument|bool HasHi
argument_list|)
block|;
name|void
name|selectAddESubE
argument_list|(
argument|unsigned MOp
argument_list|,
argument|SDValue InFlag
argument_list|,
argument|SDValue CmpLHS
argument_list|,
argument|const SDLoc&DL
argument_list|,
argument|SDNode *Node
argument_list|)
specifier|const
block|;
name|bool
name|selectAddrFrameIndex
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|)
specifier|const
block|;
name|bool
name|selectAddrFrameIndexOffset
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|,
argument|unsigned OffsetBits
argument_list|,
argument|unsigned ShiftAmount
argument_list|)
specifier|const
block|;
name|bool
name|selectAddrRegImm
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|)
specifier|const
name|override
block|;
name|bool
name|selectAddrDefault
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|)
specifier|const
name|override
block|;
name|bool
name|selectIntAddr
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|)
specifier|const
name|override
block|;
name|bool
name|selectAddrRegImm9
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|)
specifier|const
block|;
name|bool
name|selectAddrRegImm11
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|)
specifier|const
block|;
name|bool
name|selectAddrRegImm12
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|)
specifier|const
block|;
name|bool
name|selectAddrRegImm16
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|)
specifier|const
block|;
name|bool
name|selectIntAddr11MM
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|)
specifier|const
name|override
block|;
name|bool
name|selectIntAddr12MM
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|)
specifier|const
name|override
block|;
name|bool
name|selectIntAddr16MM
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|)
specifier|const
name|override
block|;
name|bool
name|selectIntAddrLSL2MM
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|)
specifier|const
name|override
block|;
name|bool
name|selectIntAddrSImm10
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|)
specifier|const
name|override
block|;
name|bool
name|selectIntAddrSImm10Lsl1
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|)
specifier|const
name|override
block|;
name|bool
name|selectIntAddrSImm10Lsl2
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|)
specifier|const
name|override
block|;
name|bool
name|selectIntAddrSImm10Lsl3
argument_list|(
argument|SDValue Addr
argument_list|,
argument|SDValue&Base
argument_list|,
argument|SDValue&Offset
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Select constant vector splats.
name|bool
name|selectVSplat
argument_list|(
argument|SDNode *N
argument_list|,
argument|APInt&Imm
argument_list|,
argument|unsigned MinSizeInBits
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Select constant vector splats whose value fits in a given integer.
name|bool
name|selectVSplatCommon
argument_list|(
argument|SDValue N
argument_list|,
argument|SDValue&Imm
argument_list|,
argument|bool Signed
argument_list|,
argument|unsigned ImmBitSize
argument_list|)
specifier|const
block|;
comment|/// \brief Select constant vector splats whose value fits in a uimm1.
name|bool
name|selectVSplatUimm1
argument_list|(
argument|SDValue N
argument_list|,
argument|SDValue&Imm
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Select constant vector splats whose value fits in a uimm2.
name|bool
name|selectVSplatUimm2
argument_list|(
argument|SDValue N
argument_list|,
argument|SDValue&Imm
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Select constant vector splats whose value fits in a uimm3.
name|bool
name|selectVSplatUimm3
argument_list|(
argument|SDValue N
argument_list|,
argument|SDValue&Imm
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Select constant vector splats whose value fits in a uimm4.
name|bool
name|selectVSplatUimm4
argument_list|(
argument|SDValue N
argument_list|,
argument|SDValue&Imm
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Select constant vector splats whose value fits in a uimm5.
name|bool
name|selectVSplatUimm5
argument_list|(
argument|SDValue N
argument_list|,
argument|SDValue&Imm
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Select constant vector splats whose value fits in a uimm6.
name|bool
name|selectVSplatUimm6
argument_list|(
argument|SDValue N
argument_list|,
argument|SDValue&Imm
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Select constant vector splats whose value fits in a uimm8.
name|bool
name|selectVSplatUimm8
argument_list|(
argument|SDValue N
argument_list|,
argument|SDValue&Imm
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Select constant vector splats whose value fits in a simm5.
name|bool
name|selectVSplatSimm5
argument_list|(
argument|SDValue N
argument_list|,
argument|SDValue&Imm
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Select constant vector splats whose value is a power of 2.
name|bool
name|selectVSplatUimmPow2
argument_list|(
argument|SDValue N
argument_list|,
argument|SDValue&Imm
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Select constant vector splats whose value is the inverse of a
comment|/// power of 2.
name|bool
name|selectVSplatUimmInvPow2
argument_list|(
argument|SDValue N
argument_list|,
argument|SDValue&Imm
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Select constant vector splats whose value is a run of set bits
comment|/// ending at the most significant bit
name|bool
name|selectVSplatMaskL
argument_list|(
argument|SDValue N
argument_list|,
argument|SDValue&Imm
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Select constant vector splats whose value is a run of set bits
comment|/// starting at bit zero.
name|bool
name|selectVSplatMaskR
argument_list|(
argument|SDValue N
argument_list|,
argument|SDValue&Imm
argument_list|)
specifier|const
name|override
block|;
name|bool
name|trySelect
argument_list|(
argument|SDNode *Node
argument_list|)
name|override
block|;
name|void
name|processFunctionAfterISel
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
block|;
comment|// Insert instructions to initialize the global base register in the
comment|// first MBB of the function.
name|void
name|initGlobalBaseReg
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|bool
name|SelectInlineAsmMemoryOperand
argument_list|(
argument|const SDValue&Op
argument_list|,
argument|unsigned ConstraintID
argument_list|,
argument|std::vector<SDValue>&OutOps
argument_list|)
name|override
block|; }
decl_stmt|;
name|FunctionPass
modifier|*
name|createMipsSEISelDag
argument_list|(
name|MipsTargetMachine
operator|&
name|TM
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

