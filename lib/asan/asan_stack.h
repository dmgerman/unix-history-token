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
file|"asan_flags.h"
end_include

begin_include
include|#
directive|include
file|"asan_thread.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_flags.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_stacktrace.h"
end_include

begin_decl_stmt
name|namespace
name|__asan
block|{
comment|// Get the stack trace with the given pc and bp.
comment|// The pc will be in the position 0 of the resulting stack trace.
comment|// The bp may refer to the current frame or to the caller's frame.
name|ALWAYS_INLINE
name|void
name|GetStackTraceWithPcBpAndContext
parameter_list|(
name|BufferedStackTrace
modifier|*
name|stack
parameter_list|,
name|uptr
name|max_depth
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|uptr
name|bp
parameter_list|,
name|void
modifier|*
name|context
parameter_list|,
name|bool
name|fast
parameter_list|)
block|{
if|#
directive|if
name|SANITIZER_WINDOWS
name|stack
operator|->
name|Unwind
argument_list|(
name|max_depth
argument_list|,
name|pc
argument_list|,
name|bp
argument_list|,
name|context
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|fast
argument_list|)
expr_stmt|;
else|#
directive|else
name|AsanThread
modifier|*
name|t
decl_stmt|;
name|stack
operator|->
name|size
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|LIKELY
argument_list|(
name|asan_inited
argument_list|)
condition|)
block|{
if|if
condition|(
operator|(
name|t
operator|=
name|GetCurrentThread
argument_list|()
operator|)
operator|&&
operator|!
name|t
operator|->
name|isUnwinding
argument_list|()
condition|)
block|{
comment|// On FreeBSD the slow unwinding that leverages _Unwind_Backtrace()
comment|// yields the call stack of the signal's handler and not of the code
comment|// that raised the signal (as it does on Linux).
if|if
condition|(
name|SANITIZER_FREEBSD
operator|&&
name|t
operator|->
name|isInDeadlySignal
argument_list|()
condition|)
name|fast
operator|=
name|true
expr_stmt|;
name|uptr
name|stack_top
init|=
name|t
operator|->
name|stack_top
argument_list|()
decl_stmt|;
name|uptr
name|stack_bottom
init|=
name|t
operator|->
name|stack_bottom
argument_list|()
decl_stmt|;
name|ScopedUnwinding
name|unwind_scope
argument_list|(
name|t
argument_list|)
decl_stmt|;
name|stack
operator|->
name|Unwind
argument_list|(
name|max_depth
argument_list|,
name|pc
argument_list|,
name|bp
argument_list|,
name|context
argument_list|,
name|stack_top
argument_list|,
name|stack_bottom
argument_list|,
name|fast
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|t
operator|==
literal|0
operator|&&
operator|!
name|fast
condition|)
block|{
comment|/* If GetCurrentThread() has failed, try to do slow unwind anyways. */
name|stack
operator|->
name|Unwind
argument_list|(
name|max_depth
argument_list|,
name|pc
argument_list|,
name|bp
argument_list|,
name|context
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|false
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|// SANITIZER_WINDOWS
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace __asan
end_comment

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
value|BufferedStackTrace stack;                                                    \   if (max_size<= 2) {                                                         \     stack.size = max_size;                                                     \     if (max_size> 0) {                                                        \       stack.top_frame_bp = GET_CURRENT_FRAME();                                \       stack.trace_buffer[0] = StackTrace::GetCurrentPc();                      \       if (max_size> 1)                                                        \         stack.trace_buffer[1] = GET_CALLER_PC();                               \     }                                                                          \   } else {                                                                     \     GetStackTraceWithPcBpAndContext(&stack, max_size,                          \                                     StackTrace::GetCurrentPc(),                \                                     GET_CURRENT_FRAME(), 0, fast);             \   }
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
value|BufferedStackTrace stack;                                                    \   GetStackTraceWithPcBpAndContext(&stack, kStackTraceMax, pc, bp, 0,           \                                   common_flags()->fast_unwind_on_fatal)
end_define

begin_define
define|#
directive|define
name|GET_STACK_TRACE_SIGNAL
parameter_list|(
name|sig
parameter_list|)
define|\
value|BufferedStackTrace stack;                                                    \   GetStackTraceWithPcBpAndContext(&stack, kStackTraceMax,                      \                                   (sig).pc, (sig).bp, (sig).context,           \                                   common_flags()->fast_unwind_on_fatal)
end_define

begin_define
define|#
directive|define
name|GET_STACK_TRACE_FATAL_HERE
define|\
value|GET_STACK_TRACE(kStackTraceMax, common_flags()->fast_unwind_on_fatal)
end_define

begin_define
define|#
directive|define
name|GET_STACK_TRACE_CHECK_HERE
define|\
value|GET_STACK_TRACE(kStackTraceMax, common_flags()->fast_unwind_on_check)
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
value|GET_STACK_TRACE(common_flags()->malloc_context_size,            \                   common_flags()->fast_unwind_on_malloc)
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
value|{                             \     GET_STACK_TRACE_FATAL_HERE; \     stack.Print();              \   }
end_define

begin_define
define|#
directive|define
name|PRINT_CURRENT_STACK_CHECK
parameter_list|()
define|\
value|{                                 \     GET_STACK_TRACE_CHECK_HERE;     \     stack.Print();                  \   }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_STACK_H
end_comment

end_unit

