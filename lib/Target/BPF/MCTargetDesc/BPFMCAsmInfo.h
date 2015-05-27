begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BPFMCAsmInfo.h - BPF asm properties -------------------*- C++ -*--====//
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
comment|// This file contains the declaration of the BPFMCAsmInfo class.
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
name|LLVM_LIB_TARGET_BPF_MCTARGETDESC_BPFMCASMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_BPF_MCTARGETDESC_BPFMCASMINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCAsmInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Target
decl_stmt|;
name|class
name|BPFMCAsmInfo
range|:
name|public
name|MCAsmInfo
block|{
name|public
operator|:
name|explicit
name|BPFMCAsmInfo
argument_list|(
argument|StringRef TT
argument_list|)
block|{
name|PrivateGlobalPrefix
operator|=
literal|".L"
block|;
name|WeakRefDirective
operator|=
literal|"\t.weak\t"
block|;
name|UsesELFSectionDirectiveForBSS
operator|=
name|true
block|;
name|HasSingleParameterDotFile
operator|=
name|false
block|;
name|HasDotTypeDotSizeDirective
operator|=
name|false
block|;   }
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

