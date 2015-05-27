begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- tsan_ignoreset.h ----------------------------------------*- C++ -*-===//
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
comment|// This file is a part of ThreadSanitizer (TSan), a race detector.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IgnoreSet holds a set of stack traces where ignores were enabled.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TSAN_IGNORESET_H
end_ifndef

begin_define
define|#
directive|define
name|TSAN_IGNORESET_H
end_define

begin_include
include|#
directive|include
file|"tsan_defs.h"
end_include

begin_decl_stmt
name|namespace
name|__tsan
block|{
name|class
name|IgnoreSet
block|{
name|public
label|:
specifier|static
specifier|const
name|uptr
name|kMaxSize
init|=
literal|16
decl_stmt|;
name|IgnoreSet
argument_list|()
expr_stmt|;
name|void
name|Add
parameter_list|(
name|u32
name|stack_id
parameter_list|)
function_decl|;
name|void
name|Reset
parameter_list|()
function_decl|;
name|uptr
name|Size
argument_list|()
specifier|const
expr_stmt|;
name|u32
name|At
argument_list|(
name|uptr
name|i
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|uptr
name|size_
decl_stmt|;
name|u32
name|stacks_
index|[
name|kMaxSize
index|]
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __tsan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TSAN_IGNORESET_H
end_comment

end_unit

