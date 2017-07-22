begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LanaiTargetMachine.h - Define TargetMachine for Lanai --- C++ ---===//
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
comment|// This file declares the Lanai specific subclass of TargetMachine.
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
name|LLVM_LIB_TARGET_LANAI_LANAITARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_LANAI_LANAITARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"LanaiFrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"LanaiISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"LanaiInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"LanaiSelectionDAGInfo.h"
end_include

begin_include
include|#
directive|include
file|"LanaiSubtarget.h"
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
name|formatted_raw_ostream
decl_stmt|;
name|class
name|LanaiTargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|LanaiSubtarget
name|Subtarget
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|TargetLoweringObjectFile
operator|>
name|TLOF
block|;
name|public
operator|:
name|LanaiTargetMachine
argument_list|(
argument|const Target&TheTarget
argument_list|,
argument|const Triple&TargetTriple
argument_list|,
argument|StringRef Cpu
argument_list|,
argument|StringRef FeatureString
argument_list|,
argument|const TargetOptions&Options
argument_list|,
argument|Optional<Reloc::Model> RelocationModel
argument_list|,
argument|CodeModel::Model CodeModel
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|)
block|;
specifier|const
name|LanaiSubtarget
operator|*
name|getSubtargetImpl
argument_list|(
argument|const llvm::Function&
comment|/*Fn*/
argument_list|)
specifier|const
name|override
block|{
return|return
operator|&
name|Subtarget
return|;
block|}
name|TargetIRAnalysis
name|getTargetIRAnalysis
argument_list|()
name|override
block|;
comment|// Pass Pipeline Configuration
name|TargetPassConfig
operator|*
name|createPassConfig
argument_list|(
argument|PassManagerBase&pass_manager
argument_list|)
name|override
block|;
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
name|bool
name|isMachineVerifierClean
argument_list|()
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_LANAI_LANAITARGETMACHINE_H
end_comment

end_unit

