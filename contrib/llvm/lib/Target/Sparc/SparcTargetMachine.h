begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SparcTargetMachine.h - Define TargetMachine for Sparc ---*- C++ -*-===//
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
comment|// This file declares the Sparc specific subclass of TargetMachine.
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
name|SPARCTARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|SPARCTARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"SparcInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"SparcSubtarget.h"
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
name|SparcTargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|SparcSubtarget
name|Subtarget
block|;
name|public
operator|:
name|SparcTargetMachine
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
argument_list|,
argument|bool is64bit
argument_list|)
block|;
specifier|const
name|SparcInstrInfo
operator|*
name|getInstrInfo
argument_list|()
specifier|const
name|override
block|{
return|return
name|getSubtargetImpl
argument_list|()
operator|->
name|getInstrInfo
argument_list|()
return|;
block|}
specifier|const
name|TargetFrameLowering
operator|*
name|getFrameLowering
argument_list|()
specifier|const
name|override
block|{
return|return
name|getSubtargetImpl
argument_list|()
operator|->
name|getFrameLowering
argument_list|()
return|;
block|}
specifier|const
name|SparcSubtarget
operator|*
name|getSubtargetImpl
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|Subtarget
return|;
block|}
specifier|const
name|SparcRegisterInfo
operator|*
name|getRegisterInfo
argument_list|()
specifier|const
name|override
block|{
return|return
name|getSubtargetImpl
argument_list|()
operator|->
name|getRegisterInfo
argument_list|()
return|;
block|}
specifier|const
name|SparcTargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
name|override
block|{
return|return
name|getSubtargetImpl
argument_list|()
operator|->
name|getTargetLowering
argument_list|()
return|;
block|}
specifier|const
name|SparcSelectionDAGInfo
operator|*
name|getSelectionDAGInfo
argument_list|()
specifier|const
name|override
block|{
return|return
name|getSubtargetImpl
argument_list|()
operator|->
name|getSelectionDAGInfo
argument_list|()
return|;
block|}
name|SparcJITInfo
operator|*
name|getJITInfo
argument_list|()
name|override
block|{
return|return
name|Subtarget
operator|.
name|getJITInfo
argument_list|()
return|;
block|}
specifier|const
name|DataLayout
operator|*
name|getDataLayout
argument_list|()
specifier|const
name|override
block|{
return|return
name|getSubtargetImpl
argument_list|()
operator|->
name|getDataLayout
argument_list|()
return|;
block|}
comment|// Pass Pipeline Configuration
name|TargetPassConfig
operator|*
name|createPassConfig
argument_list|(
argument|PassManagerBase&PM
argument_list|)
name|override
block|;
name|bool
name|addCodeEmitter
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|JITCodeEmitter&JCE
argument_list|)
name|override
block|; }
decl_stmt|;
comment|/// SparcV8TargetMachine - Sparc 32-bit target machine
comment|///
name|class
name|SparcV8TargetMachine
range|:
name|public
name|SparcTargetMachine
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|SparcV8TargetMachine
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
block|; }
decl_stmt|;
comment|/// SparcV9TargetMachine - Sparc 64-bit target machine
comment|///
name|class
name|SparcV9TargetMachine
range|:
name|public
name|SparcTargetMachine
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|SparcV9TargetMachine
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

