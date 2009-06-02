begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- XCoreFrameInfo.h - Frame info for XCore Target -----------*- C++ -*-==//
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
comment|// This file contains XCore frame information that doesn't fit anywhere else
end_comment

begin_comment
comment|// cleanly...
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
name|XCOREFRAMEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|XCOREFRAMEINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetFrameInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|XCoreFrameInfo
range|:
name|public
name|TargetFrameInfo
block|{
name|public
operator|:
name|XCoreFrameInfo
argument_list|(
specifier|const
name|TargetMachine
operator|&
name|tm
argument_list|)
block|;
comment|//! Stack slot size (4 bytes)
specifier|static
name|int
name|stackSlotSize
argument_list|()
block|{
return|return
literal|4
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// XCOREFRAMEINFO_H
end_comment

end_unit

