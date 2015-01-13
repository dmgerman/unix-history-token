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
name|AMDGPU_TARGET_MACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|AMDGPU_TARGET_MACHINE_H
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
name|class
name|AMDGPUTargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|AMDGPUSubtarget
name|Subtarget
block|;
specifier|const
name|DataLayout
name|Layout
block|;
name|AMDGPUFrameLowering
name|FrameLowering
block|;
name|AMDGPUIntrinsicInfo
name|IntrinsicInfo
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|AMDGPUTargetLowering
operator|>
name|TLInfo
block|;
specifier|const
name|InstrItineraryData
operator|*
name|InstrItins
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
name|AMDGPUFrameLowering
operator|*
name|getFrameLowering
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|FrameLowering
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
specifier|const
name|AMDGPUInstrInfo
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
name|AMDGPURegisterInfo
operator|*
name|getRegisterInfo
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|getInstrInfo
argument_list|()
operator|->
name|getRegisterInfo
argument_list|()
return|;
block|}
name|AMDGPUTargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
name|override
block|{
return|return
name|TLInfo
operator|.
name|get
argument_list|()
return|;
block|}
specifier|const
name|InstrItineraryData
operator|*
name|getInstrItineraryData
argument_list|()
specifier|const
name|override
block|{
return|return
name|InstrItins
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
operator|&
name|Layout
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
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// AMDGPU_TARGET_MACHINE_H
end_comment

end_unit

