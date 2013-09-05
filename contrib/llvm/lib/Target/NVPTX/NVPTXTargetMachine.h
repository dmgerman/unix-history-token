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
file|"ManagedStringPool.h"
end_include

begin_include
include|#
directive|include
file|"NVPTXFrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"NVPTXISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"NVPTXInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"NVPTXRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"NVPTXSubtarget.h"
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
specifier|const
name|DataLayout
name|DL
block|;
comment|// Calculates type size& alignment
name|NVPTXInstrInfo
name|InstrInfo
block|;
name|NVPTXTargetLowering
name|TLInfo
block|;
name|TargetSelectionDAGInfo
name|TSInfo
block|;
comment|// NVPTX does not have any call stack frame, but need a NVPTX specific
comment|// FrameLowering class because TargetFrameLowering is abstract.
name|NVPTXFrameLowering
name|FrameLowering
block|;
comment|// Hold Strings that can be free'd all together with NVPTXTargetMachine
name|ManagedStringPool
name|ManagedStrPool
block|;
comment|//bool addCommonCodeGenPasses(PassManagerBase&, CodeGenOpt::Level,
comment|//                            bool DisableVerify, MCContext *&OutCtx);
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
name|NVPTXInstrInfo
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
name|NVPTXSubtarget
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
name|NVPTXRegisterInfo
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
name|NVPTXTargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|NVPTXTargetLowering
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
name|TargetSelectionDAGInfo
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
comment|//virtual bool addInstSelector(PassManagerBase&PM,
comment|//                             CodeGenOpt::Level OptLevel);
comment|//virtual bool addPreRegAlloc(PassManagerBase&, CodeGenOpt::Level);
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
comment|// Emission of machine code through JITCodeEmitter is not supported.
name|virtual
name|bool
name|addPassesToEmitMachineCode
argument_list|(
argument|PassManagerBase&
argument_list|,
argument|JITCodeEmitter&
argument_list|,
argument|bool = true
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Emission of machine code through MCJIT is not supported.
name|virtual
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

