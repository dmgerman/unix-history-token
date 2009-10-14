begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PIC16TargetMachine.h - Define TargetMachine for PIC16 ---*- C++ -*-===//
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
comment|// This file declares the PIC16 specific subclass of TargetMachine.
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
name|PIC16_TARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|PIC16_TARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"PIC16InstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"PIC16ISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"PIC16RegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"PIC16Subtarget.h"
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
comment|/// PIC16TargetMachine
comment|///
name|class
name|PIC16TargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|PIC16Subtarget
name|Subtarget
block|;
specifier|const
name|TargetData
name|DataLayout
block|;
comment|// Calculates type size& alignment
name|PIC16InstrInfo
name|InstrInfo
block|;
name|PIC16TargetLowering
name|TLInfo
block|;
comment|// PIC16 does not have any call stack frame, therefore not having
comment|// any PIC16 specific FrameInfo class.
name|TargetFrameInfo
name|FrameInfo
block|;
name|public
operator|:
name|PIC16TargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|const std::string&TT
argument_list|,
argument|const std::string&FS
argument_list|,
argument|bool Cooper = false
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
name|PIC16InstrInfo
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
name|PIC16Subtarget
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
name|PIC16RegisterInfo
operator|*
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
operator|&
operator|(
name|InstrInfo
operator|.
name|getRegisterInfo
argument_list|()
operator|)
return|;
block|}
name|virtual
name|PIC16TargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|PIC16TargetLowering
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
comment|// PIC16TargetMachine.
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

