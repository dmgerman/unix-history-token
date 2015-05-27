begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDGPUTargetMachine.h - AMDGPU TargetMachine Interface --*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// \brief The AMDGPU TargetMachine interface definition for hw codgen targets.
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
name|LLVM_LIB_TARGET_R600_AMDGPUTARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_R600_AMDGPUTARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"AMDGPUFrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"AMDGPUInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"AMDGPUIntrinsicInfo.h"
end_include

begin_include
include|#
directive|include
file|"AMDGPUSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"R600ISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DataLayout.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|//===----------------------------------------------------------------------===//
comment|// AMDGPU Target Machine (R600+)
comment|//===----------------------------------------------------------------------===//
name|class
name|AMDGPUTargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|protected
operator|:
name|TargetLoweringObjectFile
operator|*
name|TLOF
block|;
name|AMDGPUSubtarget
name|Subtarget
block|;
name|AMDGPUIntrinsicInfo
name|IntrinsicInfo
block|;
name|public
operator|:
name|AMDGPUTargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|StringRef TT
argument_list|,
argument|StringRef FS
argument_list|,
argument|StringRef CPU
argument_list|,
argument|TargetOptions Options
argument_list|,
argument|Reloc::Model RM
argument_list|,
argument|CodeModel::Model CM
argument_list|,
argument|CodeGenOpt::Level OL
argument_list|)
block|;
operator|~
name|AMDGPUTargetMachine
argument_list|()
block|;
specifier|const
name|AMDGPUSubtarget
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
name|AMDGPUIntrinsicInfo
operator|*
name|getIntrinsicInfo
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|IntrinsicInfo
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
comment|/// \brief Register R600 analysis passes with a pass manager.
name|void
name|addAnalysisPasses
argument_list|(
argument|PassManagerBase&PM
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
return|;
block|}
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|// GCN Target Machine (SI+)
comment|//===----------------------------------------------------------------------===//
name|class
name|GCNTargetMachine
operator|:
name|public
name|AMDGPUTargetMachine
block|{
name|public
operator|:
name|GCNTargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|StringRef TT
argument_list|,
argument|StringRef FS
argument_list|,
argument|StringRef CPU
argument_list|,
argument|TargetOptions Options
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
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

