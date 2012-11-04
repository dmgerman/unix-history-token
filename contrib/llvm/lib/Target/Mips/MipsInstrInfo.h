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
name|virtual
name|MachineInstr
operator|*
name|emitFrameIndexDebugValue
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|int FrameIx
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|const MDNode *MDPtr
argument_list|,
argument|DebugLoc DL
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
name|GetOppositeBranchOpc
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
name|GetAnalyzableBrOpc
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
name|namespace
name|Mips
block|{
comment|/// Emit a series of instructions to load an immediate. All instructions
comment|/// except for the last one are emitted. The function returns the number of
comment|/// MachineInstrs generated. The opcode-immediate pair of the last
comment|/// instruction is returned in LastInst, if it is not 0.
name|unsigned
name|loadImmediate
argument_list|(
name|int64_t
name|Imm
argument_list|,
name|bool
name|IsN64
argument_list|,
specifier|const
name|TargetInstrInfo
operator|&
name|TII
argument_list|,
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|II
argument_list|,
name|DebugLoc
name|DL
argument_list|,
name|bool
name|LastInstrIsADDiu
argument_list|,
name|MipsAnalyzeImmediate
operator|::
name|Inst
operator|*
name|LastInst
argument_list|)
decl_stmt|;
block|}
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

