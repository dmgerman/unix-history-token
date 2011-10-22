begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMTargetMachine.h - Define TargetMachine for ARM -------*- C++ -*-===//
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
comment|// This file declares the ARM specific subclass of TargetMachine.
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
name|ARMTARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|ARMTARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"ARMInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"ARMELFWriterInfo.h"
end_include

begin_include
include|#
directive|include
file|"ARMFrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"ARMJITInfo.h"
end_include

begin_include
include|#
directive|include
file|"ARMSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"ARMISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"ARMSelectionDAGInfo.h"
end_include

begin_include
include|#
directive|include
file|"Thumb1InstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"Thumb1FrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"Thumb2InstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetData.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCStreamer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ARMBaseTargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|protected
operator|:
name|ARMSubtarget
name|Subtarget
block|;
name|private
operator|:
name|ARMJITInfo
name|JITInfo
block|;
name|InstrItineraryData
name|InstrItins
block|;
name|public
operator|:
name|ARMBaseTargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|StringRef TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|Reloc::Model RM
argument_list|,
argument|CodeModel::Model CM
argument_list|)
block|;
name|virtual
name|ARMJITInfo
operator|*
name|getJITInfo
argument_list|()
block|{
return|return
operator|&
name|JITInfo
return|;
block|}
name|virtual
specifier|const
name|ARMSubtarget
operator|*
name|getSubtargetImpl
argument_list|()
specifier|const
block|{
return|return
operator|&
name|Subtarget
return|;
block|}
name|virtual
specifier|const
name|InstrItineraryData
operator|*
name|getInstrItineraryData
argument_list|()
specifier|const
block|{
return|return
operator|&
name|InstrItins
return|;
block|}
comment|// Pass Pipeline Configuration
name|virtual
name|bool
name|addPreISel
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|)
block|;
name|virtual
name|bool
name|addInstSelector
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|)
block|;
name|virtual
name|bool
name|addPreRegAlloc
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|)
block|;
name|virtual
name|bool
name|addPreSched2
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|)
block|;
name|virtual
name|bool
name|addPreEmitPass
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|)
block|;
name|virtual
name|bool
name|addCodeEmitter
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|,
argument|JITCodeEmitter&MCE
argument_list|)
block|; }
decl_stmt|;
comment|/// ARMTargetMachine - ARM target machine.
comment|///
name|class
name|ARMTargetMachine
range|:
name|public
name|ARMBaseTargetMachine
block|{
name|ARMInstrInfo
name|InstrInfo
block|;
specifier|const
name|TargetData
name|DataLayout
block|;
comment|// Calculates type size& alignment
name|ARMELFWriterInfo
name|ELFWriterInfo
block|;
name|ARMTargetLowering
name|TLInfo
block|;
name|ARMSelectionDAGInfo
name|TSInfo
block|;
name|ARMFrameLowering
name|FrameLowering
block|;
name|public
operator|:
name|ARMTargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|StringRef TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|Reloc::Model RM
argument_list|,
argument|CodeModel::Model CM
argument_list|)
block|;
name|virtual
specifier|const
name|ARMRegisterInfo
operator|*
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
operator|&
name|InstrInfo
operator|.
name|getRegisterInfo
argument_list|()
return|;
block|}
name|virtual
specifier|const
name|ARMTargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
block|{
return|return
operator|&
name|TLInfo
return|;
block|}
name|virtual
specifier|const
name|ARMSelectionDAGInfo
operator|*
name|getSelectionDAGInfo
argument_list|()
specifier|const
block|{
return|return
operator|&
name|TSInfo
return|;
block|}
name|virtual
specifier|const
name|ARMFrameLowering
operator|*
name|getFrameLowering
argument_list|()
specifier|const
block|{
return|return
operator|&
name|FrameLowering
return|;
block|}
name|virtual
specifier|const
name|ARMInstrInfo
operator|*
name|getInstrInfo
argument_list|()
specifier|const
block|{
return|return
operator|&
name|InstrInfo
return|;
block|}
name|virtual
specifier|const
name|TargetData
operator|*
name|getTargetData
argument_list|()
specifier|const
block|{
return|return
operator|&
name|DataLayout
return|;
block|}
name|virtual
specifier|const
name|ARMELFWriterInfo
operator|*
name|getELFWriterInfo
argument_list|()
specifier|const
block|{
return|return
name|Subtarget
operator|.
name|isTargetELF
argument_list|()
operator|?
operator|&
name|ELFWriterInfo
operator|:
literal|0
return|;
block|}
expr|}
block|;
comment|/// ThumbTargetMachine - Thumb target machine.
comment|/// Due to the way architectures are handled, this represents both
comment|///   Thumb-1 and Thumb-2.
comment|///
name|class
name|ThumbTargetMachine
operator|:
name|public
name|ARMBaseTargetMachine
block|{
comment|// Either Thumb1InstrInfo or Thumb2InstrInfo.
name|OwningPtr
operator|<
name|ARMBaseInstrInfo
operator|>
name|InstrInfo
block|;
specifier|const
name|TargetData
name|DataLayout
block|;
comment|// Calculates type size& alignment
name|ARMELFWriterInfo
name|ELFWriterInfo
block|;
name|ARMTargetLowering
name|TLInfo
block|;
name|ARMSelectionDAGInfo
name|TSInfo
block|;
comment|// Either Thumb1FrameLowering or ARMFrameLowering.
name|OwningPtr
operator|<
name|ARMFrameLowering
operator|>
name|FrameLowering
block|;
name|public
operator|:
name|ThumbTargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|StringRef TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|Reloc::Model RM
argument_list|,
argument|CodeModel::Model CM
argument_list|)
block|;
comment|/// returns either Thumb1RegisterInfo or Thumb2RegisterInfo
name|virtual
specifier|const
name|ARMBaseRegisterInfo
operator|*
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
operator|&
name|InstrInfo
operator|->
name|getRegisterInfo
argument_list|()
return|;
block|}
name|virtual
specifier|const
name|ARMTargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
block|{
return|return
operator|&
name|TLInfo
return|;
block|}
name|virtual
specifier|const
name|ARMSelectionDAGInfo
operator|*
name|getSelectionDAGInfo
argument_list|()
specifier|const
block|{
return|return
operator|&
name|TSInfo
return|;
block|}
comment|/// returns either Thumb1InstrInfo or Thumb2InstrInfo
name|virtual
specifier|const
name|ARMBaseInstrInfo
operator|*
name|getInstrInfo
argument_list|()
specifier|const
block|{
return|return
name|InstrInfo
operator|.
name|get
argument_list|()
return|;
block|}
comment|/// returns either Thumb1FrameLowering or ARMFrameLowering
name|virtual
specifier|const
name|ARMFrameLowering
operator|*
name|getFrameLowering
argument_list|()
specifier|const
block|{
return|return
name|FrameLowering
operator|.
name|get
argument_list|()
return|;
block|}
name|virtual
specifier|const
name|TargetData
operator|*
name|getTargetData
argument_list|()
specifier|const
block|{
return|return
operator|&
name|DataLayout
return|;
block|}
name|virtual
specifier|const
name|ARMELFWriterInfo
operator|*
name|getELFWriterInfo
argument_list|()
specifier|const
block|{
return|return
name|Subtarget
operator|.
name|isTargetELF
argument_list|()
condition|?
operator|&
name|ELFWriterInfo
else|:
literal|0
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

