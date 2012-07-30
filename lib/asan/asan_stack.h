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
name|uptr
name|kStackTraceMax
init|=
literal|64
decl_stmt|;
struct|struct
name|AsanStackTrace
block|{
name|uptr
name|size
decl_stmt|;
name|uptr
name|max_size
decl_stmt|;
name|uptr
name|trace
index|[
name|kStackTraceMax
index|]
decl_stmt|;
specifier|static
name|void
name|PrintStack
parameter_list|(
name|uptr
modifier|*
name|addr
parameter_list|,
name|uptr
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
name|uptr
modifier|*
name|dst
parameter_list|,
name|uptr
name|dst_size
parameter_list|)
block|{
for|for
control|(
name|uptr
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
name|uptr
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
name|uptr
modifier|*
name|src
parameter_list|,
name|uptr
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
name|uptr
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
name|GetStackTrace
parameter_list|(
name|uptr
name|max_s
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|uptr
name|bp
parameter_list|)
function_decl|;
name|void
name|FastUnwindStack
parameter_list|(
name|uptr
name|pc
parameter_list|,
name|uptr
name|bp
parameter_list|)
function_decl|;
specifier|static
name|uptr
name|GetCurrentPc
parameter_list|()
function_decl|;
specifier|static
name|uptr
name|CompressStack
parameter_list|(
name|AsanStackTrace
modifier|*
name|stack
parameter_list|,
name|u32
modifier|*
name|compressed
parameter_list|,
name|uptr
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
name|u32
modifier|*
name|compressed
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __asan
end_comment

begin_comment
comment|// Use this macro if you want to print stack trace with the caller
end_comment

begin_comment
comment|// of the current function in the top frame.
end_comment

begin_define
define|#
directive|define
name|GET_CALLER_PC_BP_SP
define|\
value|uptr bp = GET_CURRENT_FRAME();              \   uptr pc = GET_CALLER_PC();                  \   uptr local_stack;                           \   uptr sp = (uptr)&local_stack
end_define

begin_comment
comment|// Use this macro if you want to print stack trace with the current
end_comment

begin_comment
comment|// function in the top frame.
end_comment

begin_define
define|#
directive|define
name|GET_CURRENT_PC_BP_SP
define|\
value|uptr bp = GET_CURRENT_FRAME();              \   uptr pc = AsanStackTrace::GetCurrentPc();   \   uptr local_stack;                           \   uptr sp = (uptr)&local_stack
end_define

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
parameter_list|)
define|\
value|AsanStackTrace stack;                                             \   stack.GetStackTrace(max_s, pc, bp)
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
name|GET_STACK_TRACE_HERE
parameter_list|(
name|max_size
parameter_list|)
define|\
value|GET_STACK_TRACE_WITH_PC_AND_BP(max_size,                    \       AsanStackTrace::GetCurrentPc(), GET_CURRENT_FRAME())
end_define

begin_define
define|#
directive|define
name|GET_STACK_TRACE_HERE_FOR_MALLOC
define|\
value|GET_STACK_TRACE_HERE(flags()->malloc_context_size)
end_define

begin_define
define|#
directive|define
name|GET_STACK_TRACE_HERE_FOR_FREE
parameter_list|(
name|ptr
parameter_list|)
define|\
value|GET_STACK_TRACE_HERE(flags()->malloc_context_size)
end_define

begin_define
define|#
directive|define
name|PRINT_CURRENT_STACK
parameter_list|()
define|\
value|{                                              \     GET_STACK_TRACE_HERE(kStackTraceMax);        \     stack.PrintStack();                          \   }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_STACK_H
end_comment

end_unit

