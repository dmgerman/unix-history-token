begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SparcTargetStreamer.h - Sparc Target Streamer ----------*- C++ -*--===//
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
name|SPARCTARGETSTREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|SPARCTARGETSTREAMER_H
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
name|SparcTargetStreamer
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
comment|/// Emit ".register<reg>, #ignore".
name|virtual
name|void
name|emitSparcRegisterIgnore
argument_list|(
argument|unsigned reg
argument_list|)
operator|=
literal|0
block|;
comment|/// Emit ".register<reg>, #scratch".
name|virtual
name|void
name|emitSparcRegisterScratch
argument_list|(
argument|unsigned reg
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
comment|// This part is for ascii assembly output
name|class
name|SparcTargetAsmStreamer
range|:
name|public
name|SparcTargetStreamer
block|{
name|formatted_raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
name|SparcTargetAsmStreamer
argument_list|(
name|formatted_raw_ostream
operator|&
name|OS
argument_list|)
block|;
name|virtual
name|void
name|emitSparcRegisterIgnore
argument_list|(
argument|unsigned reg
argument_list|)
block|;
name|virtual
name|void
name|emitSparcRegisterScratch
argument_list|(
argument|unsigned reg
argument_list|)
block|;  }
decl_stmt|;
comment|// This part is for ELF object output
name|class
name|SparcTargetELFStreamer
range|:
name|public
name|SparcTargetStreamer
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
name|emitSparcRegisterIgnore
argument_list|(
argument|unsigned reg
argument_list|)
block|{}
name|virtual
name|void
name|emitSparcRegisterScratch
argument_list|(
argument|unsigned reg
argument_list|)
block|{}
block|}
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

end_unit

