begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MBlazeTargetMachine.h - Define TargetMachine for MBlaze -*- C++ -*-===//
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
comment|// This file declares the MBlaze specific subclass of TargetMachine.
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
name|MBLAZE_TARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|MBLAZE_TARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"MBlazeFrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"MBlazeISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"MBlazeInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"MBlazeIntrinsicInfo.h"
end_include

begin_include
include|#
directive|include
file|"MBlazeSelectionDAGInfo.h"
end_include

begin_include
include|#
directive|include
file|"MBlazeSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DataLayout.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCStreamer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetFrameLowering.h"
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
name|formatted_raw_ostream
decl_stmt|;
name|class
name|MBlazeTargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|MBlazeSubtarget
name|Subtarget
block|;
specifier|const
name|DataLayout
name|DL
block|;
comment|// Calculates type size& alignment
name|MBlazeInstrInfo
name|InstrInfo
block|;
name|MBlazeFrameLowering
name|FrameLowering
block|;
name|MBlazeTargetLowering
name|TLInfo
block|;
name|MBlazeSelectionDAGInfo
name|TSInfo
block|;
name|MBlazeIntrinsicInfo
name|IntrinsicInfo
block|;
name|InstrItineraryData
name|InstrItins
block|;
name|public
operator|:
name|MBlazeTargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|StringRef TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|const TargetOptions&Options
argument_list|,
argument|Reloc::Model RM
argument_list|,
argument|CodeModel::Model CM
argument_list|,
argument|CodeGenOpt::Level OL
argument_list|)
block|;
name|virtual
specifier|const
name|MBlazeInstrInfo
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
name|virtual
specifier|const
name|TargetFrameLowering
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
name|MBlazeSubtarget
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
name|DataLayout
operator|*
name|getDataLayout
argument_list|()
specifier|const
block|{
return|return
operator|&
name|DL
return|;
block|}
name|virtual
specifier|const
name|MBlazeRegisterInfo
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
name|MBlazeTargetLowering
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
name|MBlazeSelectionDAGInfo
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
specifier|const
name|TargetIntrinsicInfo
operator|*
name|getIntrinsicInfo
argument_list|()
specifier|const
block|{
return|return
operator|&
name|IntrinsicInfo
return|;
block|}
comment|// Pass Pipeline Configuration
name|virtual
name|TargetPassConfig
operator|*
name|createPassConfig
argument_list|(
name|PassManagerBase
operator|&
name|PM
argument_list|)
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

