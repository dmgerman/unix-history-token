begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- IA64TargetMachine.h - Define TargetMachine for IA64 ---*- C++ -*---===//
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
comment|// This file declares the IA64 specific subclass of TargetMachine.
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
name|LLVM_TARGET_IA64TARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_IA64TARGETMACHINE_H
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
file|"llvm/Target/TargetFrameInfo.h"
end_include

begin_include
include|#
directive|include
file|"IA64InstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"IA64ISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"IA64Subtarget.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|IA64TargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|IA64Subtarget
name|Subtarget
block|;
specifier|const
name|TargetData
name|DataLayout
block|;
comment|// Calculates type size& alignment
name|IA64InstrInfo
name|InstrInfo
block|;
name|TargetFrameInfo
name|FrameInfo
block|;
comment|//IA64JITInfo      JITInfo;
name|IA64TargetLowering
name|TLInfo
block|;
name|protected
operator|:
name|virtual
specifier|const
name|TargetAsmInfo
operator|*
name|createTargetAsmInfo
argument_list|()
specifier|const
block|;
name|public
operator|:
name|IA64TargetMachine
argument_list|(
specifier|const
name|Module
operator|&
name|M
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
name|IA64InstrInfo
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
name|IA64Subtarget
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
name|IA64TargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|IA64TargetLowering
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
name|IA64RegisterInfo
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
specifier|static
name|unsigned
name|getModuleMatchQuality
argument_list|(
specifier|const
name|Module
operator|&
name|M
argument_list|)
block|;
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
block|;
name|virtual
name|bool
name|addAssemblyEmitter
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|,
argument|bool Verbose
argument_list|,
argument|raw_ostream&Out
argument_list|)
block|; }
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

