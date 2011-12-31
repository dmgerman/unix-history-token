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
file|"asan_internal.h"
end_include

begin_decl_stmt
name|namespace
name|__asan
block|{
specifier|static
specifier|const
name|size_t
name|kStackTraceMax
init|=
literal|64
decl_stmt|;
struct|struct
name|AsanStackTrace
block|{
name|size_t
name|size
decl_stmt|;
name|size_t
name|max_size
decl_stmt|;
name|uintptr_t
name|trace
index|[
name|kStackTraceMax
index|]
decl_stmt|;
specifier|static
name|void
name|PrintStack
parameter_list|(
name|uintptr_t
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
name|void
name|PrintStack
parameter_list|()
block|{
name|PrintStack
argument_list|(
name|this
operator|->
name|trace
argument_list|,
name|this
operator|->
name|size
argument_list|)
expr_stmt|;
block|}
name|void
name|CopyTo
parameter_list|(
name|uintptr_t
modifier|*
name|dst
parameter_list|,
name|size_t
name|dst_size
parameter_list|)
block|{
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size
operator|&&
name|i
operator|<
name|dst_size
condition|;
name|i
operator|++
control|)
name|dst
index|[
name|i
index|]
operator|=
name|trace
index|[
name|i
index|]
expr_stmt|;
for|for
control|(
name|size_t
name|i
init|=
name|size
init|;
name|i
operator|<
name|dst_size
condition|;
name|i
operator|++
control|)
name|dst
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
name|void
name|CopyFrom
parameter_list|(
name|uintptr_t
modifier|*
name|src
parameter_list|,
name|size_t
name|src_size
parameter_list|)
block|{
name|size
operator|=
name|src_size
expr_stmt|;
if|if
condition|(
name|size
operator|>
name|kStackTraceMax
condition|)
name|size
operator|=
name|kStackTraceMax
expr_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size
condition|;
name|i
operator|++
control|)
block|{
name|trace
index|[
name|i
index|]
operator|=
name|src
index|[
name|i
index|]
expr_stmt|;
block|}
block|}
name|void
name|FastUnwindStack
parameter_list|(
name|uintptr_t
name|pc
parameter_list|,
name|uintptr_t
name|bp
parameter_list|)
function_decl|;
comment|//  static _Unwind_Reason_Code Unwind_Trace(
comment|//      struct _Unwind_Context *ctx, void *param);
specifier|static
name|uintptr_t
name|GetCurrentPc
parameter_list|()
function_decl|;
specifier|static
name|size_t
name|CompressStack
parameter_list|(
name|AsanStackTrace
modifier|*
name|stack
parameter_list|,
name|uint32_t
modifier|*
name|compressed
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
specifier|static
name|void
name|UncompressStack
parameter_list|(
name|AsanStackTrace
modifier|*
name|stack
parameter_list|,
name|uint32_t
modifier|*
name|compressed
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
name|size_t
name|full_frame_count
decl_stmt|;
block|}
struct|;
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
name|fast_unwind
parameter_list|,
name|pc
parameter_list|,
name|bp
parameter_list|)
define|\
value|AsanStackTrace stack;                             \   {                                                 \     uintptr_t saved_pc = pc;                        \     uintptr_t saved_bp = bp;                        \     stack.size = 0;                                 \     stack.full_frame_count = 0;                     \     stack.trace[0] = saved_pc;                      \     if ((max_s)> 1) {                              \       stack.max_size = max_s;                       \       stack.FastUnwindStack(saved_pc, saved_bp);    \     }                                               \   }                                                 \  #define GET_STACK_TRACE_HERE(max_size, fast_unwind)         \   GET_STACK_TRACE_WITH_PC_AND_BP(max_size, fast_unwind,     \      AsanStackTrace::GetCurrentPc(), GET_CURRENT_FRAME())   \  #define GET_STACK_TRACE_HERE_FOR_MALLOC         \   GET_STACK_TRACE_HERE(FLAG_malloc_context_size, FLAG_fast_unwind)
end_define

begin_define
define|#
directive|define
name|GET_STACK_TRACE_HERE_FOR_FREE
parameter_list|(
name|ptr
parameter_list|)
define|\
value|GET_STACK_TRACE_HERE(FLAG_malloc_context_size, FLAG_fast_unwind)
end_define

begin_define
define|#
directive|define
name|PRINT_CURRENT_STACK
parameter_list|()
define|\
value|{                                              \     GET_STACK_TRACE_HERE(kStackTraceMax, false); \     stack.PrintStack();                          \   }                                              \  #endif
end_define

begin_comment
comment|// ASAN_STACK_H
end_comment

end_unit

