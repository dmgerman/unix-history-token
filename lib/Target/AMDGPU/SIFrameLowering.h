begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--------------------- SIFrameLowering.h --------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_AMDGPU_SIFRAMELOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_SIFRAMELOWERING_H
end_define

begin_include
include|#
directive|include
file|"AMDGPUFrameLowering.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|SIInstrInfo
decl_stmt|;
name|class
name|SIMachineFunctionInfo
decl_stmt|;
name|class
name|SIRegisterInfo
decl_stmt|;
name|class
name|SISubtarget
decl_stmt|;
name|class
name|SIFrameLowering
name|final
range|:
name|public
name|AMDGPUFrameLowering
block|{
name|public
operator|:
name|SIFrameLowering
argument_list|(
argument|StackDirection D
argument_list|,
argument|unsigned StackAl
argument_list|,
argument|int LAO
argument_list|,
argument|unsigned TransAl =
literal|1
argument_list|)
operator|:
name|AMDGPUFrameLowering
argument_list|(
argument|D
argument_list|,
argument|StackAl
argument_list|,
argument|LAO
argument_list|,
argument|TransAl
argument_list|)
block|{}
operator|~
name|SIFrameLowering
argument_list|()
name|override
operator|=
expr|default
block|;
name|void
name|emitPrologue
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|)
specifier|const
name|override
block|;
name|void
name|emitEpilogue
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|)
specifier|const
name|override
block|;
name|int
name|getFrameIndexReference
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|int FI
argument_list|,
argument|unsigned&FrameReg
argument_list|)
specifier|const
name|override
block|;
name|void
name|processFunctionBeforeFrameFinalized
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|RegScavenger *RS = nullptr
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|void
name|emitFlatScratchInit
argument_list|(
argument|const SISubtarget&ST
argument_list|,
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|)
specifier|const
block|;
name|unsigned
name|getReservedPrivateSegmentBufferReg
argument_list|(
argument|const SISubtarget&ST
argument_list|,
argument|const SIInstrInfo *TII
argument_list|,
argument|const SIRegisterInfo *TRI
argument_list|,
argument|SIMachineFunctionInfo *MFI
argument_list|,
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
name|unsigned
name|getReservedPrivateSegmentWaveByteOffsetReg
argument_list|(
argument|const SISubtarget&ST
argument_list|,
argument|const SIInstrInfo *TII
argument_list|,
argument|const SIRegisterInfo *TRI
argument_list|,
argument|SIMachineFunctionInfo *MFI
argument_list|,
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|/// \brief Emits debugger prologue.
name|void
name|emitDebuggerPrologue
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineBasicBlock&MBB
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

begin_comment
comment|// LLVM_LIB_TARGET_AMDGPU_SIFRAMELOWERING_H
end_comment

end_unit

