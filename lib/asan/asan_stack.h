begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_stack.h --------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of AddressSanitizer, an address sanity checker.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ASan-private header for asan_stack.cc.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_STACK_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_STACK_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_stacktrace.h"
end_include

begin_include
include|#
directive|include
file|"asan_flags.h"
end_include

begin_decl_stmt
name|namespace
name|__asan
block|{
name|void
name|GetStackTrace
parameter_list|(
name|StackTrace
modifier|*
name|stack
parameter_list|,
name|uptr
name|max_s
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|uptr
name|bp
parameter_list|,
name|bool
name|fast
parameter_list|)
function_decl|;
name|void
name|PrintStack
parameter_list|(
name|StackTrace
modifier|*
name|stack
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __asan
end_comment

begin_comment
comment|// Get the stack trace with the given pc and bp.
end_comment

begin_comment
comment|// The pc will be in the position 0 of the resulting stack trace.
end_comment

begin_comment
comment|// The bp may refer to the current frame or to the caller's frame.
end_comment

begin_comment
comment|// fast_unwind is currently unused.
end_comment

begin_define
define|#
directive|define
name|GET_STACK_TRACE_WITH_PC_AND_BP
parameter_list|(
name|max_s
parameter_list|,
name|pc
parameter_list|,
name|bp
parameter_list|,
name|fast
parameter_list|)
define|\
value|StackTrace stack;                                             \   GetStackTrace(&stack, max_s, pc, bp, fast)
end_define

begin_comment
comment|// NOTE: A Rule of thumb is to retrieve stack trace in the interceptors
end_comment

begin_comment
comment|// as early as possible (in functions exposed to the user), as we generally
end_comment

begin_comment
comment|// don't want stack trace to contain functions from ASan internals.
end_comment

begin_define
define|#
directive|define
name|GET_STACK_TRACE
parameter_list|(
name|max_size
parameter_list|,
name|fast
parameter_list|)
define|\
value|GET_STACK_TRACE_WITH_PC_AND_BP(max_size,                    \       StackTrace::GetCurrentPc(), GET_CURRENT_FRAME(), fast)
end_define

begin_define
define|#
directive|define
name|GET_STACK_TRACE_FATAL
parameter_list|(
name|pc
parameter_list|,
name|bp
parameter_list|)
define|\
value|GET_STACK_TRACE_WITH_PC_AND_BP(kStackTraceMax, pc, bp,              \                                  flags()->fast_unwind_on_fatal)
end_define

begin_define
define|#
directive|define
name|GET_STACK_TRACE_FATAL_HERE
define|\
value|GET_STACK_TRACE(kStackTraceMax, flags()->fast_unwind_on_fatal)
end_define

begin_define
define|#
directive|define
name|GET_STACK_TRACE_THREAD
define|\
value|GET_STACK_TRACE(kStackTraceMax, true)
end_define

begin_define
define|#
directive|define
name|GET_STACK_TRACE_MALLOC
define|\
value|GET_STACK_TRACE(flags()->malloc_context_size,            \                   flags()->fast_unwind_on_malloc)
end_define

begin_define
define|#
directive|define
name|GET_STACK_TRACE_FREE
value|GET_STACK_TRACE_MALLOC
end_define

begin_define
define|#
directive|define
name|PRINT_CURRENT_STACK
parameter_list|()
define|\
value|{                                              \     GET_STACK_TRACE(kStackTraceMax,              \       flags()->fast_unwind_on_fatal);            \     PrintStack(&stack);                          \   }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_STACK_H
end_comment

end_unit

