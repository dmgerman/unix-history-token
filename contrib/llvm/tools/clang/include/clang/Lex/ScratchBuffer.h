begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ScratchBuffer.h - Scratch space for forming tokens -----*- C++ -*-===//
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
comment|//  This file defines the ScratchBuffer interface.
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
name|LLVM_CLANG_LEX_SCRATCHBUFFER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_SCRATCHBUFFER_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|SourceManager
decl_stmt|;
comment|/// ScratchBuffer - This class exposes a simple interface for the dynamic
comment|/// construction of tokens.  This is used for builtin macros (e.g. __LINE__) as
comment|/// well as token pasting, etc.
name|class
name|ScratchBuffer
block|{
name|SourceManager
modifier|&
name|SourceMgr
decl_stmt|;
name|char
modifier|*
name|CurBuffer
decl_stmt|;
name|SourceLocation
name|BufferStartLoc
decl_stmt|;
name|unsigned
name|BytesUsed
decl_stmt|;
name|public
label|:
name|ScratchBuffer
argument_list|(
name|SourceManager
operator|&
name|SM
argument_list|)
expr_stmt|;
comment|/// getToken - Splat the specified text into a temporary MemoryBuffer and
comment|/// return a SourceLocation that refers to the token.  This is just like the
comment|/// previous method, but returns a location that indicates the physloc of the
comment|/// token.
name|SourceLocation
name|getToken
parameter_list|(
specifier|const
name|char
modifier|*
name|Buf
parameter_list|,
name|unsigned
name|Len
parameter_list|,
specifier|const
name|char
modifier|*
modifier|&
name|DestPtr
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|AllocScratchBuffer
parameter_list|(
name|unsigned
name|RequestLen
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

