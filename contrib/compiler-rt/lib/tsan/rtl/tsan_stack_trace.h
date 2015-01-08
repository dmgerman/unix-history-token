begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- tsan_stack_trace.h --------------------------------------*- C++ -*-===//
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
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TSAN_STACK_TRACE_H
end_ifndef

begin_define
define|#
directive|define
name|TSAN_STACK_TRACE_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_stacktrace.h"
end_include

begin_include
include|#
directive|include
file|"tsan_defs.h"
end_include

begin_decl_stmt
name|namespace
name|__tsan
block|{
comment|// StackTrace which calls malloc/free to allocate the buffer for
comment|// addresses in stack traces.
name|struct
name|VarSizeStackTrace
range|:
name|public
name|StackTrace
block|{
name|uptr
operator|*
name|trace_buffer
block|;
comment|// Owned.
name|VarSizeStackTrace
argument_list|()
block|;
operator|~
name|VarSizeStackTrace
argument_list|()
block|;
name|void
name|Init
argument_list|(
argument|const uptr *pcs
argument_list|,
argument|uptr cnt
argument_list|,
argument|uptr extra_top_pc =
literal|0
argument_list|)
block|;
name|private
operator|:
name|void
name|ResizeBuffer
argument_list|(
argument|uptr new_size
argument_list|)
block|;
name|VarSizeStackTrace
argument_list|(
specifier|const
name|VarSizeStackTrace
operator|&
argument_list|)
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|VarSizeStackTrace
operator|&
operator|)
block|; }
decl_stmt|;
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
comment|// TSAN_STACK_TRACE_H
end_comment

end_unit

