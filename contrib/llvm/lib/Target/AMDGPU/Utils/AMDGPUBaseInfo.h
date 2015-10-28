begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDGPUBaseInfo.h - Top level definitions for AMDGPU -----*- C++ -*-===//
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
name|LLVM_LIB_TARGET_AMDGPU_UTILS_AMDGPUBASEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_UTILS_AMDGPUBASEINFO_H
end_define

begin_include
include|#
directive|include
file|"AMDKernelCodeT.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FeatureBitset
decl_stmt|;
name|namespace
name|AMDGPU
block|{
struct|struct
name|IsaVersion
block|{
name|unsigned
name|Major
decl_stmt|;
name|unsigned
name|Minor
decl_stmt|;
name|unsigned
name|Stepping
decl_stmt|;
block|}
struct|;
name|IsaVersion
name|getIsaVersion
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|)
function_decl|;
name|void
name|initDefaultAMDKernelCodeT
parameter_list|(
name|amd_kernel_code_t
modifier|&
name|Header
parameter_list|,
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|)
function_decl|;
block|}
comment|// end namespace AMDGPU
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

