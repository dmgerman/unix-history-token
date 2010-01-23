begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- MSP430TargetMachine.h - Define TargetMachine for MSP430 ---*- C++ -*-==//
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
comment|// This file declares the MSP430 specific subclass of TargetMachine.
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
name|LLVM_TARGET_MSP430_TARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_MSP430_TARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"MSP430InstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"MSP430ISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"MSP430RegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"MSP430Subtarget.h"
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

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// MSP430TargetMachine
comment|///
name|class
name|MSP430TargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|MSP430Subtarget
name|Subtarget
block|;
specifier|const
name|TargetData
name|DataLayout
block|;
comment|// Calculates type size& alignment
name|MSP430InstrInfo
name|InstrInfo
block|;
name|MSP430TargetLowering
name|TLInfo
block|;
comment|// MSP430 does not have any call stack frame, therefore not having
comment|// any MSP430 specific FrameInfo class.
name|TargetFrameInfo
name|FrameInfo
block|;
name|public
operator|:
name|MSP430TargetMachine
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
name|MSP430InstrInfo
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
name|MSP430Subtarget
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
name|TargetRegisterInfo
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
name|MSP430TargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|MSP430TargetLowering
operator|*
operator|>
operator|(
operator|&
name|TLInfo
operator|)
return|;
block|}
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
block|; }
decl_stmt|;
comment|// MSP430TargetMachine.
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
comment|// LLVM_TARGET_MSP430_TARGETMACHINE_H
end_comment

end_unit

