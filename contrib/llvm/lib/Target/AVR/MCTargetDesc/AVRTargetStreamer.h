begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AVRTargetStreamer.h - AVR Target Streamer --------------*- C++ -*--===//
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
name|LLVM_AVR_TARGET_STREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AVR_TARGET_STREAMER_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCELFStreamer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCStreamer
decl_stmt|;
comment|/// A generic AVR target output stream.
name|class
name|AVRTargetStreamer
range|:
name|public
name|MCTargetStreamer
block|{
name|public
operator|:
name|explicit
name|AVRTargetStreamer
argument_list|(
name|MCStreamer
operator|&
name|S
argument_list|)
block|; }
decl_stmt|;
comment|/// A target streamer for textual AVR assembly code.
name|class
name|AVRTargetAsmStreamer
range|:
name|public
name|AVRTargetStreamer
block|{
name|public
operator|:
name|explicit
name|AVRTargetAsmStreamer
argument_list|(
name|MCStreamer
operator|&
name|S
argument_list|)
block|; }
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
comment|// LLVM_AVR_TARGET_STREAMER_H
end_comment

end_unit

