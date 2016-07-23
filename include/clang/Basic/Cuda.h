begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Cuda.h - Utilities for compiling CUDA code  ------------*- C++ -*-===//
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
name|LLVM_CLANG_BASIC_CUDA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_CUDA_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_decl_stmt
name|namespace
name|clang
block|{
name|enum
name|class
name|CudaVersion
block|{
name|UNKNOWN
operator|,
name|CUDA_70
operator|,
name|CUDA_75
operator|,
name|CUDA_80
operator|,
block|}
empty_stmt|;
specifier|const
name|char
modifier|*
name|CudaVersionToString
parameter_list|(
name|CudaVersion
name|V
parameter_list|)
function_decl|;
comment|// No string -> CudaVersion conversion function because there's no canonical
comment|// spelling of the various CUDA versions.
name|enum
name|class
name|CudaArch
block|{
name|UNKNOWN
operator|,
name|SM_20
operator|,
name|SM_21
operator|,
name|SM_30
operator|,
name|SM_32
operator|,
name|SM_35
operator|,
name|SM_37
operator|,
name|SM_50
operator|,
name|SM_52
operator|,
name|SM_53
operator|,
name|SM_60
operator|,
name|SM_61
operator|,
name|SM_62
operator|,
block|}
empty_stmt|;
specifier|const
name|char
modifier|*
name|CudaArchToString
parameter_list|(
name|CudaArch
name|A
parameter_list|)
function_decl|;
comment|// The input should have the form "sm_20".
name|CudaArch
name|StringToCudaArch
argument_list|(
name|llvm
operator|::
name|StringRef
name|S
argument_list|)
decl_stmt|;
name|enum
name|class
name|CudaVirtualArch
block|{
name|UNKNOWN
operator|,
name|COMPUTE_20
operator|,
name|COMPUTE_30
operator|,
name|COMPUTE_32
operator|,
name|COMPUTE_35
operator|,
name|COMPUTE_37
operator|,
name|COMPUTE_50
operator|,
name|COMPUTE_52
operator|,
name|COMPUTE_53
operator|,
name|COMPUTE_60
operator|,
name|COMPUTE_61
operator|,
name|COMPUTE_62
operator|,
block|}
empty_stmt|;
specifier|const
name|char
modifier|*
name|CudaVirtualArchToString
parameter_list|(
name|CudaVirtualArch
name|A
parameter_list|)
function_decl|;
comment|// The input should have the form "compute_20".
name|CudaVirtualArch
name|StringToCudaVirtualArch
argument_list|(
name|llvm
operator|::
name|StringRef
name|S
argument_list|)
decl_stmt|;
comment|/// Get the compute_xx corresponding to an sm_yy.
name|CudaVirtualArch
name|VirtualArchForCudaArch
parameter_list|(
name|CudaArch
name|A
parameter_list|)
function_decl|;
comment|/// Get the earliest CudaVersion that supports the given CudaArch.
name|CudaVersion
name|MinVersionForCudaArch
parameter_list|(
name|CudaArch
name|A
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

