begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- SystemZTargetMachine.h - Define TargetMachine for SystemZ ---*- C++ -*-=//
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
comment|// This file declares the SystemZ specific subclass of TargetMachine.
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
name|SYSTEMZTARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|SYSTEMZTARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"SystemZFrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"SystemZISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"SystemZInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"SystemZRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"SystemZSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"SystemZSelectionDAGInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DataLayout.h"
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
name|SystemZTargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|SystemZSubtarget
name|Subtarget
block|;
specifier|const
name|DataLayout
name|DL
block|;
name|SystemZInstrInfo
name|InstrInfo
block|;
name|SystemZTargetLowering
name|TLInfo
block|;
name|SystemZSelectionDAGInfo
name|TSInfo
block|;
name|SystemZFrameLowering
name|FrameLowering
block|;
name|public
operator|:
name|SystemZTargetMachine
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
comment|// Override TargetMachine.
name|virtual
specifier|const
name|TargetFrameLowering
operator|*
name|getFrameLowering
argument_list|()
specifier|const
name|LLVM_OVERRIDE
block|{
return|return
operator|&
name|FrameLowering
return|;
block|}
name|virtual
specifier|const
name|SystemZInstrInfo
operator|*
name|getInstrInfo
argument_list|()
specifier|const
name|LLVM_OVERRIDE
block|{
return|return
operator|&
name|InstrInfo
return|;
block|}
name|virtual
specifier|const
name|SystemZSubtarget
operator|*
name|getSubtargetImpl
argument_list|()
specifier|const
name|LLVM_OVERRIDE
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
name|LLVM_OVERRIDE
block|{
return|return
operator|&
name|DL
return|;
block|}
name|virtual
specifier|const
name|SystemZRegisterInfo
operator|*
name|getRegisterInfo
argument_list|()
specifier|const
name|LLVM_OVERRIDE
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
name|SystemZTargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
name|LLVM_OVERRIDE
block|{
return|return
operator|&
name|TLInfo
return|;
block|}
name|virtual
specifier|const
name|TargetSelectionDAGInfo
operator|*
name|getSelectionDAGInfo
argument_list|()
specifier|const
name|LLVM_OVERRIDE
block|{
return|return
operator|&
name|TSInfo
return|;
block|}
comment|// Override LLVMTargetMachine
name|virtual
name|TargetPassConfig
operator|*
name|createPassConfig
argument_list|(
argument|PassManagerBase&PM
argument_list|)
name|LLVM_OVERRIDE
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

