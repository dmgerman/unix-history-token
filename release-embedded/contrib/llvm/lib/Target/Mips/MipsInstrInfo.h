begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsInstrInfo.h - Mips Instruction Information ----------*- C++ -*-===//
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
comment|// This file contains the Mips implementation of the TargetInstrInfo class.
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
name|MIPSINSTRUCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|MIPSINSTRUCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"Mips.h"
end_include

begin_include
include|#
directive|include
file|"MipsAnalyzeImmediate.h"
end_include

begin_include
include|#
directive|include
file|"MipsRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineInstrBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_define
define|#
directive|define
name|GET_INSTRINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"MipsGenInstrInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MipsInstrInfo
range|:
name|public
name|MipsGenInstrInfo
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|protected
operator|:
name|MipsTargetMachine
operator|&
name|TM
block|;
name|unsigned
name|UncondBrOpc
block|;
name|public
operator|:
expr|enum
name|BranchType
block|{
name|BT_None
block|,
comment|// Couldn't analyze branch.
name|BT_NoBranch
block|,
comment|// No branches found.
name|BT_Uncond
block|,
comment|// One unconditional branch.
name|BT_Cond
block|,
comment|// One conditional branch.
name|BT_CondUncond
block|,
comment|// A conditional branch followed by an unconditional branch.
name|BT_Indirect
comment|// One indirct branch.
block|}
block|;
name|explicit
name|MipsInstrInfo
argument_list|(
argument|MipsTargetMachine&TM
argument_list|,
argument|unsigned UncondBrOpc
argument_list|)
block|;
specifier|static
specifier|const
name|MipsInstrInfo
operator|*
name|create
argument_list|(
name|MipsTargetMachine
operator|&
name|TM
argument_list|)
block|;
comment|/// Branch Analysis
name|virtual
name|bool
name|AnalyzeBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock *&TBB
argument_list|,
argument|MachineBasicBlock *&FBB
argument_list|,
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|,
argument|bool AllowModify
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|RemoveBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|InsertBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock *TBB
argument_list|,
argument|MachineBasicBlock *FBB
argument_list|,
argument|const SmallVectorImpl<MachineOperand>&Cond
argument_list|,
argument|DebugLoc DL
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|ReverseBranchCondition
argument_list|(
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|)
specifier|const
block|;
name|BranchType
name|AnalyzeBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock *&TBB
argument_list|,
argument|MachineBasicBlock *&FBB
argument_list|,
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|,
argument|bool AllowModify
argument_list|,
argument|SmallVectorImpl<MachineInstr*>&BranchInstrs
argument_list|)
specifier|const
block|;
comment|/// Insert nop instruction when hazard condition is found
name|virtual
name|void
name|insertNoop
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|)
specifier|const
block|;
comment|/// getRegisterInfo - TargetInstrInfo is a superset of MRegister info.  As
comment|/// such, whenever a client has an instance of instruction info, it should
comment|/// always be able to get register info as well (through this method).
comment|///
name|virtual
specifier|const
name|MipsRegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getOppositeBranchOpc
argument_list|(
argument|unsigned Opc
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// Return the number of bytes of code the specified instruction may be.
name|unsigned
name|GetInstSizeInBytes
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|storeRegToStackSlot
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBI
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|bool isKill
argument_list|,
argument|int FrameIndex
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
block|{
name|storeRegToStack
argument_list|(
name|MBB
argument_list|,
name|MBBI
argument_list|,
name|SrcReg
argument_list|,
name|isKill
argument_list|,
name|FrameIndex
argument_list|,
name|RC
argument_list|,
name|TRI
argument_list|,
literal|0
argument_list|)
block|;   }
name|virtual
name|void
name|loadRegFromStackSlot
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBI
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|int FrameIndex
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|)
specifier|const
block|{
name|loadRegFromStack
argument_list|(
name|MBB
argument_list|,
name|MBBI
argument_list|,
name|DestReg
argument_list|,
name|FrameIndex
argument_list|,
name|RC
argument_list|,
name|TRI
argument_list|,
literal|0
argument_list|)
block|;   }
name|virtual
name|void
name|storeRegToStack
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|bool isKill
argument_list|,
argument|int FrameIndex
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|,
argument|int64_t Offset
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|loadRegFromStack
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|int FrameIndex
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|const TargetRegisterInfo *TRI
argument_list|,
argument|int64_t Offset
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// Create an instruction which has the same operands and memory operands
comment|/// as MI but has a new opcode.
name|MachineInstrBuilder
name|genInstrWithNewOpc
argument_list|(
argument|unsigned NewOpc
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|bool
name|isZeroImm
argument_list|(
argument|const MachineOperand&op
argument_list|)
specifier|const
block|;
name|MachineMemOperand
operator|*
name|GetMemOperand
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|int FI
argument_list|,
argument|unsigned Flag
argument_list|)
specifier|const
block|;
name|private
operator|:
name|virtual
name|unsigned
name|getAnalyzableBrOpc
argument_list|(
argument|unsigned Opc
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|void
name|AnalyzeCondBr
argument_list|(
argument|const MachineInstr *Inst
argument_list|,
argument|unsigned Opc
argument_list|,
argument|MachineBasicBlock *&BB
argument_list|,
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|)
specifier|const
block|;
name|void
name|BuildCondBr
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock *TBB
argument_list|,
argument|DebugLoc DL
argument_list|,
argument|const SmallVectorImpl<MachineOperand>& Cond
argument_list|)
specifier|const
block|; }
decl_stmt|;
comment|/// Create MipsInstrInfo objects.
specifier|const
name|MipsInstrInfo
modifier|*
name|createMips16InstrInfo
parameter_list|(
name|MipsTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
specifier|const
name|MipsInstrInfo
modifier|*
name|createMipsSEInstrInfo
parameter_list|(
name|MipsTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

