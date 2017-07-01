begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=====-- AArch64MCAsmInfo.h - AArch64 asm properties ---------*- C++ -*--====//
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
name|LLVM_LIB_TARGET_AARCH64_MCTARGETDESC_AARCH64MCASMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AARCH64_MCTARGETDESC_AARCH64MCASMINFO_H
end_define

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
name|MCStreamer
decl_stmt|;
name|class
name|Target
decl_stmt|;
name|class
name|Triple
decl_stmt|;
name|struct
name|AArch64MCAsmInfoDarwin
range|:
name|public
name|MCAsmInfoDarwin
block|{
name|explicit
name|AArch64MCAsmInfoDarwin
argument_list|()
block|;
specifier|const
name|MCExpr
operator|*
name|getExprForPersonalitySymbol
argument_list|(
argument|const MCSymbol *Sym
argument_list|,
argument|unsigned Encoding
argument_list|,
argument|MCStreamer&Streamer
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
name|struct
name|AArch64MCAsmInfoELF
range|:
name|public
name|MCAsmInfoELF
block|{
name|explicit
name|AArch64MCAsmInfoELF
argument_list|(
specifier|const
name|Triple
operator|&
name|T
argument_list|)
block|; }
decl_stmt|;
name|struct
name|AArch64MCAsmInfoCOFF
range|:
name|public
name|MCAsmInfoCOFF
block|{
name|explicit
name|AArch64MCAsmInfoCOFF
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

