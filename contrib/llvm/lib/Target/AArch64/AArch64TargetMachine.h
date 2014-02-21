begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== AArch64TargetMachine.h - Define TargetMachine for AArch64 -*- C++ -*-===//
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
comment|// This file declares the AArch64 specific subclass of TargetMachine.
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
name|LLVM_AARCH64TARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AARCH64TARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"AArch64FrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"AArch64ISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"AArch64InstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"AArch64SelectionDAGInfo.h"
end_include

begin_include
include|#
directive|include
file|"AArch64Subtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DataLayout.h"
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
name|AArch64TargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|AArch64Subtarget
name|Subtarget
block|;
name|AArch64InstrInfo
name|InstrInfo
block|;
specifier|const
name|DataLayout
name|DL
block|;
name|AArch64TargetLowering
name|TLInfo
block|;
name|AArch64SelectionDAGInfo
name|TSInfo
block|;
name|AArch64FrameLowering
name|FrameLowering
block|;
name|public
operator|:
name|AArch64TargetMachine
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
specifier|const
name|AArch64InstrInfo
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
specifier|const
name|AArch64FrameLowering
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
specifier|const
name|AArch64TargetLowering
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
specifier|const
name|AArch64SelectionDAGInfo
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
name|AArch64Subtarget
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
name|TargetPassConfig
operator|*
name|createPassConfig
argument_list|(
name|PassManagerBase
operator|&
name|PM
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

