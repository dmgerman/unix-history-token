begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AMDGPURuntimeMD.h - Generate runtime metadata ---------------*- C++ -*-//
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
comment|// This file declares functions for generating runtime metadata.
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
name|LLVM_LIB_TARGET_AMDGPU_MCTARGETDESC_AMDGPURUNTIMEMD_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_MCTARGETDESC_AMDGPURUNTIMEMD_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
comment|// Get runtime metadata as YAML string.
name|std
operator|::
name|string
name|getRuntimeMDYAMLString
argument_list|(
name|Module
operator|&
name|M
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

