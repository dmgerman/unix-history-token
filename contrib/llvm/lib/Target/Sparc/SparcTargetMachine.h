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
file|"SparcFrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"SparcISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"SparcInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"SparcJITInfo.h"
end_include

begin_include
include|#
directive|include
file|"SparcSelectionDAGInfo.h"
end_include

begin_include
include|#
directive|include
file|"SparcSubtarget.h"
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
name|SparcTargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|SparcSubtarget
name|Subtarget
block|;
specifier|const
name|DataLayout
name|DL
block|;
comment|// Calculates type size& alignment
name|SparcInstrInfo
name|InstrInfo
block|;
name|SparcTargetLowering
name|TLInfo
block|;
name|SparcSelectionDAGInfo
name|TSInfo
block|;
name|SparcFrameLowering
name|FrameLowering
block|;
name|SparcJITInfo
name|JITInfo
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
name|virtual
specifier|const
name|SparcInstrInfo
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
name|SparcSubtarget
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
name|SparcRegisterInfo
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
name|SparcTargetLowering
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
name|SparcSelectionDAGInfo
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
name|SparcJITInfo
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
block|;
name|virtual
name|bool
name|addCodeEmitter
argument_list|(
name|PassManagerBase
operator|&
name|PM
argument_list|,
name|JITCodeEmitter
operator|&
name|JCE
argument_list|)
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

