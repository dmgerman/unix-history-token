begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NVPTXTargetMachine.h - Define TargetMachine for NVPTX ---*- C++ -*-===//
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
comment|// This file declares the NVPTX specific subclass of TargetMachine.
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
name|NVPTX_TARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|NVPTX_TARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"NVPTXSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"ManagedStringPool.h"
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

begin_include
include|#
directive|include
file|"llvm/Target/TargetSelectionDAGInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// NVPTXTargetMachine
comment|///
name|class
name|NVPTXTargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|NVPTXSubtarget
name|Subtarget
block|;
comment|// Hold Strings that can be free'd all together with NVPTXTargetMachine
name|ManagedStringPool
name|ManagedStrPool
block|;
name|public
operator|:
name|NVPTXTargetMachine
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
argument|CodeGenOpt::Level OP
argument_list|,
argument|bool is64bit
argument_list|)
block|;
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
name|NVPTXInstrInfo
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
specifier|const
name|NVPTXSubtarget
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
name|NVPTXRegisterInfo
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
name|NVPTXTargetLowering
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
name|TargetSelectionDAGInfo
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
name|ManagedStringPool
operator|*
name|getManagedStrPool
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|ManagedStringPool
operator|*
operator|>
operator|(
operator|&
name|ManagedStrPool
operator|)
return|;
block|}
name|TargetPassConfig
operator|*
name|createPassConfig
argument_list|(
argument|PassManagerBase&PM
argument_list|)
name|override
block|;
comment|// Emission of machine code through JITCodeEmitter is not supported.
name|bool
name|addPassesToEmitMachineCode
argument_list|(
argument|PassManagerBase&
argument_list|,
argument|JITCodeEmitter&
argument_list|,
argument|bool = true
argument_list|)
name|override
block|{
return|return
name|true
return|;
block|}
comment|// Emission of machine code through MCJIT is not supported.
name|bool
name|addPassesToEmitMC
argument_list|(
argument|PassManagerBase&
argument_list|,
argument|MCContext *&
argument_list|,
argument|raw_ostream&
argument_list|,
argument|bool = true
argument_list|)
name|override
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|// NVPTXTargetMachine.
name|class
name|NVPTXTargetMachine32
operator|:
name|public
name|NVPTXTargetMachine
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|NVPTXTargetMachine32
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
block|;
name|class
name|NVPTXTargetMachine64
operator|:
name|public
name|NVPTXTargetMachine
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|NVPTXTargetMachine64
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

