begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SparcMCAsmInfo.h - Sparc asm properties -----------------*- C++ -*--===//
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
comment|// This file contains the declaration of the SparcMCAsmInfo class.
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
name|LLVM_LIB_TARGET_SPARC_MCTARGETDESC_SPARCMCASMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_SPARC_MCTARGETDESC_SPARCMCASMINFO_H
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
name|Triple
decl_stmt|;
name|class
name|SparcELFMCAsmInfo
range|:
name|public
name|MCAsmInfoELF
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|explicit
name|SparcELFMCAsmInfo
argument_list|(
specifier|const
name|Triple
operator|&
name|TheTriple
argument_list|)
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
block|;
specifier|const
name|MCExpr
operator|*
name|getExprForFDESymbol
argument_list|(
argument|const MCSymbol *Sym
argument_list|,
argument|unsigned Encoding
argument_list|,
argument|MCStreamer&Streamer
argument_list|)
specifier|const
name|override
block|;  }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_SPARC_MCTARGETDESC_SPARCMCASMINFO_H
end_comment

end_unit

