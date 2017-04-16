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
name|LLVM_LIB_TARGET_NVPTX_NVPTXTARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_NVPTX_NVPTXTARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"ManagedStringPool.h"
end_include

begin_include
include|#
directive|include
file|"NVPTXSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAGTargetInfo.h"
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
comment|/// NVPTXTargetMachine
comment|///
name|class
name|NVPTXTargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|bool
name|is64bit
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|TargetLoweringObjectFile
operator|>
name|TLOF
block|;
name|NVPTX
operator|::
name|DrvInterface
name|drvInterface
block|;
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
argument|const Triple&TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|const TargetOptions&Options
argument_list|,
argument|Optional<Reloc::Model> RM
argument_list|,
argument|CodeModel::Model CM
argument_list|,
argument|CodeGenOpt::Level OP
argument_list|,
argument|bool is64bit
argument_list|)
block|;
operator|~
name|NVPTXTargetMachine
argument_list|()
name|override
block|;
specifier|const
name|NVPTXSubtarget
operator|*
name|getSubtargetImpl
argument_list|(
argument|const Function&
argument_list|)
specifier|const
name|override
block|{
return|return
operator|&
name|Subtarget
return|;
block|}
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
name|bool
name|is64Bit
argument_list|()
specifier|const
block|{
return|return
name|is64bit
return|;
block|}
name|NVPTX
operator|::
name|DrvInterface
name|getDrvInterface
argument_list|()
specifier|const
block|{
return|return
name|drvInterface
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
comment|// Emission of machine code through MCJIT is not supported.
name|bool
name|addPassesToEmitMC
argument_list|(
argument|PassManagerBase&
argument_list|,
argument|MCContext *&
argument_list|,
argument|raw_pwrite_stream&
argument_list|,
argument|bool = true
argument_list|)
name|override
block|{
return|return
name|true
return|;
block|}
name|TargetLoweringObjectFile
operator|*
name|getObjFileLowering
argument_list|()
specifier|const
name|override
block|{
return|return
name|TLOF
operator|.
name|get
argument_list|()
return|;
block|}
name|void
name|adjustPassManager
argument_list|(
argument|PassManagerBuilder&
argument_list|)
name|override
block|;
name|TargetIRAnalysis
name|getTargetIRAnalysis
argument_list|()
name|override
block|;  }
decl_stmt|;
comment|// NVPTXTargetMachine.
name|class
name|NVPTXTargetMachine32
range|:
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
argument|const Triple&TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|const TargetOptions&Options
argument_list|,
argument|Optional<Reloc::Model> RM
argument_list|,
argument|CodeModel::Model CM
argument_list|,
argument|CodeGenOpt::Level OL
argument_list|)
block|; }
decl_stmt|;
name|class
name|NVPTXTargetMachine64
range|:
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
argument|const Triple&TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|const TargetOptions&Options
argument_list|,
argument|Optional<Reloc::Model> RM
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

