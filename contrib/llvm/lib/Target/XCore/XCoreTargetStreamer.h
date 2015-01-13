begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- XCoreTargetStreamer.h - XCore Target Streamer ----------*- C++ -*--===//
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
name|XCORETARGETSTREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|XCORETARGETSTREAMER_H
end_define

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
name|XCoreTargetStreamer
range|:
name|public
name|MCTargetStreamer
block|{
name|public
operator|:
name|XCoreTargetStreamer
argument_list|(
name|MCStreamer
operator|&
name|S
argument_list|)
block|;
name|virtual
operator|~
name|XCoreTargetStreamer
argument_list|()
block|;
name|virtual
name|void
name|emitCCTopData
argument_list|(
argument|StringRef Name
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|emitCCTopFunction
argument_list|(
argument|StringRef Name
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|emitCCBottomData
argument_list|(
argument|StringRef Name
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|emitCCBottomFunction
argument_list|(
argument|StringRef Name
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

