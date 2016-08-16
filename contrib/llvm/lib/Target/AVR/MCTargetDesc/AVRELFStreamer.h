begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- AVRELFStreamer.h - AVR Target Streamer --------------*- C++ -*--===//
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
name|LLVM_AVR_ELF_STREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AVR_ELF_STREAMER_H
end_define

begin_include
include|#
directive|include
file|"AVRTargetStreamer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// A target streamer for an AVR ELF object file.
name|class
name|AVRELFStreamer
range|:
name|public
name|AVRTargetStreamer
block|{
name|public
operator|:
name|AVRELFStreamer
argument_list|(
name|MCStreamer
operator|&
name|S
argument_list|,
specifier|const
name|MCSubtargetInfo
operator|&
name|STI
argument_list|)
block|;
name|MCELFStreamer
operator|&
name|getStreamer
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|MCELFStreamer
operator|&
operator|>
operator|(
name|Streamer
operator|)
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

