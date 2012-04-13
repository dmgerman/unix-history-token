begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PTXTargetMachine.h - Define TargetMachine for PTX -------*- C++ -*-===//
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
comment|// This file declares the PTX specific subclass of TargetMachine.
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
name|PTX_TARGET_MACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|PTX_TARGET_MACHINE_H
end_define

begin_include
include|#
directive|include
file|"PTXISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"PTXInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"PTXFrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"PTXSelectionDAGInfo.h"
end_include

begin_include
include|#
directive|include
file|"PTXSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetData.h"
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
name|PTXTargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|private
operator|:
specifier|const
name|TargetData
name|DataLayout
block|;
name|PTXSubtarget
name|Subtarget
block|;
comment|// has to be initialized before FrameLowering
name|PTXFrameLowering
name|FrameLowering
block|;
name|PTXInstrInfo
name|InstrInfo
block|;
name|PTXSelectionDAGInfo
name|TSInfo
block|;
name|PTXTargetLowering
name|TLInfo
block|;
name|public
operator|:
name|PTXTargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|StringRef TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|Reloc::Model RM
argument_list|,
argument|CodeModel::Model CM
argument_list|,
argument|bool is64Bit
argument_list|)
block|;
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
name|PTXInstrInfo
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
specifier|const
name|PTXTargetLowering
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
name|PTXSelectionDAGInfo
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
specifier|const
name|PTXSubtarget
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
name|addPostRegAlloc
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|)
block|;
comment|// We override this method to supply our own set of codegen passes.
name|virtual
name|bool
name|addPassesToEmitFile
argument_list|(
name|PassManagerBase
operator|&
argument_list|,
name|formatted_raw_ostream
operator|&
argument_list|,
name|CodeGenFileType
argument_list|,
name|CodeGenOpt
operator|::
name|Level
argument_list|,
name|bool
operator|=
name|true
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
argument|CodeGenOpt::Level
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
argument|CodeGenOpt::Level
argument_list|,
argument|bool = true
argument_list|)
block|{
return|return
name|true
return|;
block|}
name|private
operator|:
name|bool
name|addCommonCodeGenPasses
argument_list|(
argument|PassManagerBase&
argument_list|,
argument|CodeGenOpt::Level
argument_list|,
argument|bool DisableVerify
argument_list|,
argument|MCContext *&OutCtx
argument_list|)
block|; }
decl_stmt|;
comment|// class PTXTargetMachine
name|class
name|PTX32TargetMachine
range|:
name|public
name|PTXTargetMachine
block|{
name|public
operator|:
name|PTX32TargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|StringRef TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|Reloc::Model RM
argument_list|,
argument|CodeModel::Model CM
argument_list|)
block|; }
decl_stmt|;
comment|// class PTX32TargetMachine
name|class
name|PTX64TargetMachine
range|:
name|public
name|PTXTargetMachine
block|{
name|public
operator|:
name|PTX64TargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|StringRef TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|Reloc::Model RM
argument_list|,
argument|CodeModel::Model CM
argument_list|)
block|; }
decl_stmt|;
comment|// class PTX32TargetMachine
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// PTX_TARGET_MACHINE_H
end_comment

end_unit

