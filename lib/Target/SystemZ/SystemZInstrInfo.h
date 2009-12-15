begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SystemZInstrInfo.h - SystemZ Instruction Information -------*- C++ -*-===//
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
comment|// This file contains the SystemZ implementation of the TargetInstrInfo class.
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
name|LLVM_TARGET_SYSTEMZINSTRINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_SYSTEMZINSTRINFO_H
end_define

begin_include
include|#
directive|include
file|"SystemZ.h"
end_include

begin_include
include|#
directive|include
file|"SystemZRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IndexedMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|SystemZTargetMachine
decl_stmt|;
comment|/// SystemZII - This namespace holds all of the target specific flags that
comment|/// instruction info tracks.
comment|///
name|namespace
name|SystemZII
block|{
enum|enum
block|{
comment|//===------------------------------------------------------------------===//
comment|// SystemZ Specific MachineOperand flags.
name|MO_NO_FLAG
init|=
literal|0
block|,
comment|/// MO_GOTENT - On a symbol operand this indicates that the immediate is
comment|/// the offset to the location of the symbol name from the base of the GOT.
comment|///
comment|///    SYMBOL_LABEL @GOTENT
name|MO_GOTENT
init|=
literal|1
block|,
comment|/// MO_PLT - On a symbol operand this indicates that the immediate is
comment|/// offset to the PLT entry of symbol name from the current code location.
comment|///
comment|///    SYMBOL_LABEL @PLT
name|MO_PLT
init|=
literal|2
block|}
enum|;
block|}
name|class
name|SystemZInstrInfo
range|:
name|public
name|TargetInstrInfoImpl
block|{
specifier|const
name|SystemZRegisterInfo
name|RI
block|;
name|SystemZTargetMachine
operator|&
name|TM
block|;
name|IndexedMap
operator|<
name|unsigned
operator|>
name|RegSpillOffsets
block|;
name|public
operator|:
name|explicit
name|SystemZInstrInfo
argument_list|(
name|SystemZTargetMachine
operator|&
name|TM
argument_list|)
block|;
comment|/// getRegisterInfo - TargetInstrInfo is a superset of MRegister info.  As
comment|/// such, whenever a client has an instance of instruction info, it should
comment|/// always be able to get register info as well (through this method).
comment|///
name|virtual
specifier|const
name|SystemZRegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|RI
return|;
block|}
name|bool
name|copyRegToReg
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|const TargetRegisterClass *DestRC
argument_list|,
argument|const TargetRegisterClass *SrcRC
argument_list|)
specifier|const
block|;
name|bool
name|isMoveInstr
argument_list|(
argument|const MachineInstr& MI
argument_list|,
argument|unsigned&SrcReg
argument_list|,
argument|unsigned&DstReg
argument_list|,
argument|unsigned&SrcSubIdx
argument_list|,
argument|unsigned&DstSubIdx
argument_list|)
specifier|const
block|;
name|unsigned
name|isLoadFromStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
block|;
name|unsigned
name|isStoreToStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|storeRegToStackSlot
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
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|loadRegFromStackSlot
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|int FrameIdx
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|spillCalleeSavedRegisters
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|const std::vector<CalleeSavedInfo>&CSI
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|restoreCalleeSavedRegisters
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|const std::vector<CalleeSavedInfo>&CSI
argument_list|)
specifier|const
block|;
name|bool
name|ReverseBranchCondition
argument_list|(
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isUnpredicatedTerminator
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
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
name|InsertBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock *TBB
argument_list|,
argument|MachineBasicBlock *FBB
argument_list|,
argument|const SmallVectorImpl<MachineOperand>&Cond
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
name|SystemZCC
operator|::
name|CondCodes
name|getOppositeCondition
argument_list|(
argument|SystemZCC::CondCodes CC
argument_list|)
specifier|const
block|;
name|SystemZCC
operator|::
name|CondCodes
name|getCondFromBranchOpc
argument_list|(
argument|unsigned Opc
argument_list|)
specifier|const
block|;
specifier|const
name|TargetInstrDesc
operator|&
name|getBrCond
argument_list|(
argument|SystemZCC::CondCodes CC
argument_list|)
specifier|const
block|;
specifier|const
name|TargetInstrDesc
operator|&
name|getLongDispOpc
argument_list|(
argument|unsigned Opc
argument_list|)
specifier|const
block|;
specifier|const
name|TargetInstrDesc
operator|&
name|getMemoryInstr
argument_list|(
argument|unsigned Opc
argument_list|,
argument|int64_t Offset =
literal|0
argument_list|)
specifier|const
block|{
if|if
condition|(
name|Offset
operator|<
literal|0
operator|||
name|Offset
operator|>=
literal|4096
condition|)
return|return
name|getLongDispOpc
argument_list|(
name|Opc
argument_list|)
return|;
else|else
return|return
name|get
argument_list|(
name|Opc
argument_list|)
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

