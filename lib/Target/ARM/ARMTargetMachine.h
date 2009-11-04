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
file|"ARMInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"ARMFrameInfo.h"
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
file|"Thumb1InstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"Thumb2InstrInfo.h"
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
name|ARMFrameInfo
name|FrameInfo
block|;
name|ARMJITInfo
name|JITInfo
block|;
name|InstrItineraryData
name|InstrItins
block|;
name|Reloc
operator|::
name|Model
name|DefRelocModel
block|;
comment|// Reloc model before it's overridden.
name|public
operator|:
name|ARMBaseTargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|const std::string&TT
argument_list|,
argument|const std::string&FS
argument_list|,
argument|bool isThumb
argument_list|)
block|;
name|virtual
specifier|const
name|ARMFrameInfo
operator|*
name|getFrameInfo
argument_list|()
specifier|const
block|{
return|return
operator|&
name|FrameInfo
return|;
block|}
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
name|getInstrItineraryData
argument_list|()
specifier|const
block|{
return|return
name|InstrItins
return|;
block|}
comment|// Pass Pipeline Configuration
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
argument|MachineCodeEmitter&MCE
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
block|;
name|virtual
name|bool
name|addCodeEmitter
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|,
argument|ObjectCodeEmitter&OCE
argument_list|)
block|;
name|virtual
name|bool
name|addSimpleCodeEmitter
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|,
argument|MachineCodeEmitter&MCE
argument_list|)
block|;
name|virtual
name|bool
name|addSimpleCodeEmitter
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|,
argument|JITCodeEmitter&MCE
argument_list|)
block|;
name|virtual
name|bool
name|addSimpleCodeEmitter
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|,
argument|ObjectCodeEmitter&OCE
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
name|ARMTargetLowering
name|TLInfo
block|;
name|public
operator|:
name|ARMTargetMachine
argument_list|(
specifier|const
name|Target
operator|&
name|T
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|TT
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|FS
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
name|ARMTargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|ARMTargetLowering
operator|*
operator|>
operator|(
operator|&
name|TLInfo
operator|)
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
name|ARMBaseInstrInfo
operator|*
name|InstrInfo
block|;
comment|// either Thumb1InstrInfo or Thumb2InstrInfo
specifier|const
name|TargetData
name|DataLayout
block|;
comment|// Calculates type size& alignment
name|ARMTargetLowering
name|TLInfo
block|;
name|public
operator|:
name|ThumbTargetMachine
argument_list|(
specifier|const
name|Target
operator|&
name|T
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|TT
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|FS
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
name|ARMTargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|ARMTargetLowering
operator|*
operator|>
operator|(
operator|&
name|TLInfo
operator|)
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

