begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SparcRegisterInfo.h - Sparc Register Information Impl ----*- C++ -*-===//
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
comment|// This file contains the Sparc implementation of the TargetRegisterInfo class.
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
name|SPARCREGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|SPARCREGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"SparcGenRegisterInfo.h.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|SparcSubtarget
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|struct
name|SparcRegisterInfo
range|:
name|public
name|SparcGenRegisterInfo
block|{
name|SparcSubtarget
operator|&
name|Subtarget
block|;
specifier|const
name|TargetInstrInfo
operator|&
name|TII
block|;
name|SparcRegisterInfo
argument_list|(
name|SparcSubtarget
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
name|bool
name|hasFP
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
argument|FrameIndexValue *Value = NULL
argument_list|,
argument|RegScavenger *RS = NULL
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
comment|// Debug information queries.
name|unsigned
name|getRARegister
argument_list|()
specifier|const
block|;
name|unsigned
name|getFrameRegister
argument_list|(
argument|const MachineFunction&MF
argument_list|)
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
block|; }
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

