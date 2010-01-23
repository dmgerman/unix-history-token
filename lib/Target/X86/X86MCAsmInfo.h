begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=====-- X86MCAsmInfo.h - X86 asm properties -----------------*- C++ -*--====//
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
comment|// This file contains the declaration of the X86MCAsmInfo class.
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
name|X86TARGETASMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|X86TARGETASMINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCAsmInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCAsmInfoCOFF.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCAsmInfoDarwin.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Triple
decl_stmt|;
name|struct
name|X86MCAsmInfoDarwin
range|:
name|public
name|MCAsmInfoDarwin
block|{
name|explicit
name|X86MCAsmInfoDarwin
argument_list|(
specifier|const
name|Triple
operator|&
name|Triple
argument_list|)
block|;   }
decl_stmt|;
name|struct
name|X86ELFMCAsmInfo
range|:
name|public
name|MCAsmInfo
block|{
name|explicit
name|X86ELFMCAsmInfo
argument_list|(
specifier|const
name|Triple
operator|&
name|Triple
argument_list|)
block|;
name|virtual
name|MCSection
operator|*
name|getNonexecutableStackSection
argument_list|(
argument|MCContext&Ctx
argument_list|)
specifier|const
block|;   }
decl_stmt|;
name|struct
name|X86MCAsmInfoCOFF
range|:
name|public
name|MCAsmInfoCOFF
block|{
name|explicit
name|X86MCAsmInfoCOFF
argument_list|(
specifier|const
name|Triple
operator|&
name|Triple
argument_list|)
block|;   }
decl_stmt|;
name|struct
name|X86WinMCAsmInfo
range|:
name|public
name|MCAsmInfo
block|{
name|explicit
name|X86WinMCAsmInfo
argument_list|(
specifier|const
name|Triple
operator|&
name|Triple
argument_list|)
block|;   }
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

