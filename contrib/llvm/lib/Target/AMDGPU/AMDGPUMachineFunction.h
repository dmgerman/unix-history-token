begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDGPUMachineFunctionInfo.h -------------------------------*- C++ -*-=//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_AMDGPU_AMDGPUMACHINEFUNCTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_AMDGPUMACHINEFUNCTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AMDGPUMachineFunction
range|:
name|public
name|MachineFunctionInfo
block|{
comment|/// A map to keep track of local memory objects and their offsets within the
comment|/// local memory space.
name|SmallDenseMap
operator|<
specifier|const
name|GlobalValue
operator|*
block|,
name|unsigned
block|,
literal|4
operator|>
name|LocalMemoryObjects
block|;
name|uint64_t
name|KernArgSize
block|;
name|unsigned
name|MaxKernArgAlign
block|;
comment|/// Number of bytes in the LDS that are being used.
name|unsigned
name|LDSSize
block|;
comment|// FIXME: This should probably be removed.
comment|/// Start of implicit kernel args
name|unsigned
name|ABIArgOffset
block|;
comment|// Kernels + shaders. i.e. functions called by the driver and not not called
comment|// by other functions.
name|bool
name|IsEntryFunction
block|;
name|bool
name|NoSignedZerosFPMath
block|;
name|public
operator|:
name|AMDGPUMachineFunction
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|uint64_t
name|allocateKernArg
argument_list|(
argument|uint64_t Size
argument_list|,
argument|unsigned Align
argument_list|)
block|{
name|assert
argument_list|(
name|isPowerOf2_32
argument_list|(
name|Align
argument_list|)
argument_list|)
block|;
name|KernArgSize
operator|=
name|alignTo
argument_list|(
name|KernArgSize
argument_list|,
name|Align
argument_list|)
block|;
name|uint64_t
name|Result
operator|=
name|KernArgSize
block|;
name|KernArgSize
operator|+=
name|Size
block|;
name|MaxKernArgAlign
operator|=
name|std
operator|::
name|max
argument_list|(
name|Align
argument_list|,
name|MaxKernArgAlign
argument_list|)
block|;
return|return
name|Result
return|;
block|}
name|uint64_t
name|getKernArgSize
argument_list|()
specifier|const
block|{
return|return
name|KernArgSize
return|;
block|}
name|unsigned
name|getMaxKernArgAlign
argument_list|()
specifier|const
block|{
return|return
name|MaxKernArgAlign
return|;
block|}
name|void
name|setABIArgOffset
argument_list|(
argument|unsigned NewOffset
argument_list|)
block|{
name|ABIArgOffset
operator|=
name|NewOffset
block|;   }
name|unsigned
name|getABIArgOffset
argument_list|()
specifier|const
block|{
return|return
name|ABIArgOffset
return|;
block|}
name|unsigned
name|getLDSSize
argument_list|()
specifier|const
block|{
return|return
name|LDSSize
return|;
block|}
name|bool
name|isEntryFunction
argument_list|()
specifier|const
block|{
return|return
name|IsEntryFunction
return|;
block|}
name|bool
name|hasNoSignedZerosFPMath
argument_list|()
specifier|const
block|{
return|return
name|NoSignedZerosFPMath
return|;
block|}
name|unsigned
name|allocateLDSGlobal
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
specifier|const
name|GlobalValue
operator|&
name|GV
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

