begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=-- lsan.h --------------------------------------------------------------===//
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
comment|// This file is a part of LeakSanitizer.
end_comment

begin_comment
comment|// Private header for standalone LSan RTL.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

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
value|BufferedStackTrace stack;                                                    \   {                                                                            \     uptr stack_top = 0, stack_bottom = 0;                                      \     ThreadContext *t;                                                          \     if (fast&& (t = CurrentThreadContext())) {                                \       stack_top = t->stack_end();                                              \       stack_bottom = t->stack_begin();                                         \     }                                                                          \     if (!SANITIZER_MIPS ||                                                     \         IsValidFrame(GET_CURRENT_FRAME(), stack_top, stack_bottom)) {          \       stack.Unwind(max_size, StackTrace::GetCurrentPc(), GET_CURRENT_FRAME(),  \
comment|/* context */
value|0, stack_top, stack_bottom, fast);            \     }                                                                          \   }
end_define

begin_define
define|#
directive|define
name|GET_STACK_TRACE_FATAL
define|\
value|GET_STACK_TRACE(kStackTraceMax, common_flags()->fast_unwind_on_fatal)
end_define

begin_define
define|#
directive|define
name|GET_STACK_TRACE_MALLOC
define|\
value|GET_STACK_TRACE(__sanitizer::common_flags()->malloc_context_size, \                   common_flags()->fast_unwind_on_malloc)
end_define

begin_define
define|#
directive|define
name|GET_STACK_TRACE_THREAD
value|GET_STACK_TRACE(kStackTraceMax, true)
end_define

begin_decl_stmt
name|namespace
name|__lsan
block|{
name|void
name|InitializeInterceptors
parameter_list|()
function_decl|;
name|void
name|ReplaceSystemMalloc
parameter_list|()
function_decl|;
define|#
directive|define
name|ENSURE_LSAN_INITED
value|do {   \   CHECK(!lsan_init_is_running);   \   if (!lsan_inited)               \     __lsan_init();                \ } while (0)
block|}
end_decl_stmt

begin_comment
comment|// namespace __lsan
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|lsan_inited
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|lsan_init_is_running
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern
literal|"C"
name|void
name|__lsan_init
parameter_list|()
function_decl|;
end_extern

end_unit

