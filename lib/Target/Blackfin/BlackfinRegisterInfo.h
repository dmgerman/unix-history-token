begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- BlackfinRegisterInfo.h - Blackfin Register Information ..-*- C++ -*-===//
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
comment|// This file contains the Blackfin implementation of the TargetRegisterInfo
end_comment

begin_comment
comment|// class.
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
name|BLACKFINREGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|BLACKFINREGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"BlackfinGenRegisterInfo.h.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BlackfinSubtarget
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|Type
decl_stmt|;
comment|// Subregister indices, keep in sync with BlackfinRegisterInfo.td
enum|enum
name|BfinSubregIdx
block|{
name|bfin_subreg_lo16
init|=
literal|1
block|,
name|bfin_subreg_hi16
init|=
literal|2
block|,
name|bfin_subreg_lo32
init|=
literal|3
block|}
enum|;
name|struct
name|BlackfinRegisterInfo
range|:
name|public
name|BlackfinGenRegisterInfo
block|{
name|BlackfinSubtarget
operator|&
name|Subtarget
block|;
specifier|const
name|TargetInstrInfo
operator|&
name|TII
block|;
name|BlackfinRegisterInfo
argument_list|(
name|BlackfinSubtarget
operator|&
name|st
argument_list|,
specifier|const
name|TargetInstrInfo
operator|&
name|tii
argument_list|)
block|;
comment|/// Code Generation virtual methods...
specifier|const
name|unsigned
operator|*
name|getCalleeSavedRegs
argument_list|(
argument|const MachineFunction *MF =
literal|0
argument_list|)
specifier|const
block|;
specifier|const
name|TargetRegisterClass
operator|*
specifier|const
operator|*
name|getCalleeSavedRegClasses
argument_list|(
argument|const MachineFunction *MF =
literal|0
argument_list|)
specifier|const
block|;
name|BitVector
name|getReservedRegs
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|// getSubReg implemented by tablegen
specifier|const
name|TargetRegisterClass
operator|*
name|getPointerRegClass
argument_list|(
argument|unsigned Kind =
literal|0
argument_list|)
specifier|const
block|{
return|return
operator|&
name|BF
operator|::
name|PRegClass
return|;
block|}
specifier|const
name|TargetRegisterClass
operator|*
name|getPhysicalRegisterRegClass
argument_list|(
argument|unsigned reg
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
block|;
name|bool
name|hasFP
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|// bool hasReservedCallFrame(MachineFunction&MF) const;
name|bool
name|requiresRegisterScavenging
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|void
name|eliminateCallFramePseudoInstr
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|)
specifier|const
block|;
name|unsigned
name|eliminateFrameIndex
argument_list|(
argument|MachineBasicBlock::iterator II
argument_list|,
argument|int SPAdj
argument_list|,
argument|int *Value = NULL
argument_list|,
argument|RegScavenger *RS = NULL
argument_list|)
specifier|const
block|;
name|void
name|processFunctionBeforeCalleeSavedScan
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|RegScavenger *RS
argument_list|)
specifier|const
block|;
name|void
name|processFunctionBeforeFrameFinalized
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
name|void
name|emitPrologue
argument_list|(
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
name|void
name|emitEpilogue
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|)
specifier|const
block|;
name|unsigned
name|getFrameRegister
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|unsigned
name|getRARegister
argument_list|()
specifier|const
block|;
comment|// Exception handling queries.
name|unsigned
name|getEHExceptionRegister
argument_list|()
specifier|const
block|;
name|unsigned
name|getEHHandlerRegister
argument_list|()
specifier|const
block|;
name|int
name|getDwarfRegNum
argument_list|(
argument|unsigned RegNum
argument_list|,
argument|bool isEH
argument_list|)
specifier|const
block|;
comment|// Utility functions
name|void
name|adjustRegister
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|DebugLoc DL
argument_list|,
argument|unsigned Reg
argument_list|,
argument|unsigned ScratchReg
argument_list|,
argument|int delta
argument_list|)
specifier|const
block|;
name|void
name|loadConstant
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|,
argument|DebugLoc DL
argument_list|,
argument|unsigned Reg
argument_list|,
argument|int value
argument_list|)
specifier|const
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

