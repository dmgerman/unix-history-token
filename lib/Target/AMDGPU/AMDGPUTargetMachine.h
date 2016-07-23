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
name|LLVM_LIB_TARGET_AMDGPU_AMDGPUTARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_AMDGPUTARGETMACHINE_H
end_define

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
name|std
operator|::
name|unique_ptr
operator|<
name|TargetLoweringObjectFile
operator|>
name|TLOF
block|;
name|AMDGPUIntrinsicInfo
name|IntrinsicInfo
block|;
name|StringRef
name|getGPUName
argument_list|(
argument|const Function&F
argument_list|)
specifier|const
block|;
name|StringRef
name|getFeatureString
argument_list|(
argument|const Function&F
argument_list|)
specifier|const
block|;
name|public
operator|:
name|AMDGPUTargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|const Triple&TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|TargetOptions Options
argument_list|,
argument|Optional<Reloc::Model> RM
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
block|;
specifier|const
name|AMDGPUSubtarget
operator|*
name|getSubtargetImpl
argument_list|(
argument|const Function&
argument_list|)
specifier|const
name|override
block|;
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
name|TargetIRAnalysis
name|getTargetIRAnalysis
argument_list|()
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
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|// R600 Target Machine (R600 -> Cayman)
comment|//===----------------------------------------------------------------------===//
name|class
name|R600TargetMachine
name|final
operator|:
name|public
name|AMDGPUTargetMachine
block|{
name|private
operator|:
name|mutable
name|StringMap
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|R600Subtarget
operator|>>
name|SubtargetMap
block|;
name|public
operator|:
name|R600TargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|const Triple&TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|TargetOptions Options
argument_list|,
argument|Optional<Reloc::Model> RM
argument_list|,
argument|CodeModel::Model CM
argument_list|,
argument|CodeGenOpt::Level OL
argument_list|)
block|;
name|TargetPassConfig
operator|*
name|createPassConfig
argument_list|(
argument|PassManagerBase&PM
argument_list|)
name|override
block|;
specifier|const
name|R600Subtarget
operator|*
name|getSubtargetImpl
argument_list|(
argument|const Function&
argument_list|)
specifier|const
name|override
block|; }
block|;
comment|//===----------------------------------------------------------------------===//
comment|// GCN Target Machine (SI+)
comment|//===----------------------------------------------------------------------===//
name|class
name|GCNTargetMachine
name|final
operator|:
name|public
name|AMDGPUTargetMachine
block|{
name|private
operator|:
name|mutable
name|StringMap
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|SISubtarget
operator|>>
name|SubtargetMap
block|;
name|public
operator|:
name|GCNTargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|const Triple&TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|TargetOptions Options
argument_list|,
argument|Optional<Reloc::Model> RM
argument_list|,
argument|CodeModel::Model CM
argument_list|,
argument|CodeGenOpt::Level OL
argument_list|)
block|;
name|TargetPassConfig
operator|*
name|createPassConfig
argument_list|(
argument|PassManagerBase&PM
argument_list|)
name|override
block|;
specifier|const
name|SISubtarget
operator|*
name|getSubtargetImpl
argument_list|(
argument|const Function&
argument_list|)
specifier|const
name|override
block|; }
block|;
specifier|inline
specifier|const
name|AMDGPUSubtarget
operator|*
name|AMDGPUTargetMachine
operator|::
name|getSubtargetImpl
argument_list|(
argument|const Function&F
argument_list|)
specifier|const
block|{
if|if
condition|(
name|getTargetTriple
argument_list|()
operator|.
name|getArch
argument_list|()
operator|==
name|Triple
operator|::
name|amdgcn
condition|)
return|return
name|static_cast
operator|<
specifier|const
name|GCNTargetMachine
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getSubtargetImpl
argument_list|(
name|F
argument_list|)
return|;
return|return
name|static_cast
operator|<
specifier|const
name|R600TargetMachine
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getSubtargetImpl
argument_list|(
name|F
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

