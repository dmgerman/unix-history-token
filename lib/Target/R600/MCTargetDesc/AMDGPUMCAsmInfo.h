begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MCTargetDesc/AMDGPUMCAsmInfo.h - AMDGPU MCAsm Interface -*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_R600_MCTARGETDESC_AMDGPUMCASMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_R600_MCTARGETDESC_AMDGPUMCASMINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCAsmInfoELF.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
comment|// If you need to create another MCAsmInfo class, which inherits from MCAsmInfo,
comment|// you will need to make sure your new class sets PrivateGlobalPrefix to
comment|// a prefix that won't appeary in a fuction name.  The default value
comment|// for PrivateGlobalPrefix is 'L', so it will consider any function starting
comment|// with 'L' as a local symbol.
name|class
name|AMDGPUMCAsmInfo
range|:
name|public
name|MCAsmInfoELF
block|{
name|public
operator|:
name|explicit
name|AMDGPUMCAsmInfo
argument_list|(
name|StringRef
operator|&
name|TT
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

