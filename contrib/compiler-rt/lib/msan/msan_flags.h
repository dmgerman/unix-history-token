begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- msan_flags.h --------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of MemorySanitizer.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MemorySanitizer allocator.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MSAN_FLAGS_H
end_ifndef

begin_define
define|#
directive|define
name|MSAN_FLAGS_H
end_define

begin_decl_stmt
name|namespace
name|__msan
block|{
comment|// Flags.
struct|struct
name|Flags
block|{
name|int
name|exit_code
decl_stmt|;
name|int
name|origin_history_size
decl_stmt|;
name|int
name|origin_history_per_stack_limit
decl_stmt|;
name|bool
name|poison_heap_with_zeroes
decl_stmt|;
comment|// default: false
name|bool
name|poison_stack_with_zeroes
decl_stmt|;
comment|// default: false
name|bool
name|poison_in_malloc
decl_stmt|;
comment|// default: true
name|bool
name|poison_in_free
decl_stmt|;
comment|// default: true
name|bool
name|report_umrs
decl_stmt|;
name|bool
name|wrap_signals
decl_stmt|;
name|bool
name|print_stats
decl_stmt|;
name|bool
name|halt_on_error
decl_stmt|;
name|bool
name|atexit
decl_stmt|;
name|int
name|store_context_size
decl_stmt|;
comment|// like malloc_context_size, but for uninit stores
block|}
struct|;
name|Flags
modifier|*
name|flags
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __msan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// MSAN_FLAGS_H
end_comment

end_unit

