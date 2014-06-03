begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- AArch64MCAsmInfo.h - AArch64 asm properties -------------*- C++ -*--===//
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
comment|// This file contains the declaration of the AArch64MCAsmInfo class.
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
name|LLVM_AARCH64TARGETASMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AARCH64TARGETASMINFO_H
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
name|struct
name|AArch64ELFMCAsmInfo
range|:
name|public
name|MCAsmInfoELF
block|{
name|explicit
name|AArch64ELFMCAsmInfo
argument_list|()
block|;
name|private
operator|:
name|virtual
name|void
name|anchor
argument_list|()
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

