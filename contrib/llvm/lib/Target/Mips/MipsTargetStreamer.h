begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsTargetStreamer.h - Mips Target Streamer ------------*- C++ -*--===//
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
name|MIPSTARGETSTREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|MIPSTARGETSTREAMER_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCELFStreamer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCStreamer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MipsTargetStreamer
range|:
name|public
name|MCTargetStreamer
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|virtual
name|void
name|emitMipsHackELFFlags
argument_list|(
argument|unsigned Flags
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|emitMipsHackSTOCG
argument_list|(
argument|MCSymbol *Sym
argument_list|,
argument|unsigned Val
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
comment|// This part is for ascii assembly output
name|class
name|MipsTargetAsmStreamer
range|:
name|public
name|MipsTargetStreamer
block|{
name|formatted_raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
name|MipsTargetAsmStreamer
argument_list|(
name|formatted_raw_ostream
operator|&
name|OS
argument_list|)
block|;
name|virtual
name|void
name|emitMipsHackELFFlags
argument_list|(
argument|unsigned Flags
argument_list|)
block|;
name|virtual
name|void
name|emitMipsHackSTOCG
argument_list|(
argument|MCSymbol *Sym
argument_list|,
argument|unsigned Val
argument_list|)
block|; }
decl_stmt|;
comment|// This part is for ELF object output
name|class
name|MipsTargetELFStreamer
range|:
name|public
name|MipsTargetStreamer
block|{
name|public
operator|:
name|MCELFStreamer
operator|&
name|getStreamer
argument_list|()
block|;
name|virtual
name|void
name|emitMipsHackELFFlags
argument_list|(
argument|unsigned Flags
argument_list|)
block|;
name|virtual
name|void
name|emitMipsHackSTOCG
argument_list|(
argument|MCSymbol *Sym
argument_list|,
argument|unsigned Val
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

