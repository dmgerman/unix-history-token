begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MBlazeTargetMachine.h - Define TargetMachine for MBlaze --- C++ ---===//
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
file|"MBlazeSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"MBlazeInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"MBlazeISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"MBlazeIntrinsicInfo.h"
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
file|"llvm/Target/TargetFrameInfo.h"
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
name|TargetData
name|DataLayout
block|;
comment|// Calculates type size& alignment
name|MBlazeInstrInfo
name|InstrInfo
block|;
name|TargetFrameInfo
name|FrameInfo
block|;
name|MBlazeTargetLowering
name|TLInfo
block|;
name|MBlazeIntrinsicInfo
name|IntrinsicInfo
block|;
name|public
operator|:
name|MBlazeTargetMachine
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
name|TargetFrameInfo
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
name|MBlazeTargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|MBlazeTargetLowering
operator|*
operator|>
operator|(
operator|&
name|TLInfo
operator|)
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
name|addPreEmitPass
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|CodeGenOpt::Level OptLevel
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

