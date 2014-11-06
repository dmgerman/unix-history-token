begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_stacktrace.h ----------------------------------*- C++ -*-===//
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
comment|// This file is shared between AddressSanitizer and ThreadSanitizer
end_comment

begin_comment
comment|// run-time libraries.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_STACKTRACE_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_STACKTRACE_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
specifier|static
specifier|const
name|uptr
name|kStackTraceMax
init|=
literal|256
decl_stmt|;
if|#
directive|if
name|SANITIZER_LINUX
operator|&&
operator|(
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__powerpc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__sparc__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__mips__
argument_list|)
operator|)
define|#
directive|define
name|SANITIZER_CAN_FAST_UNWIND
value|0
elif|#
directive|elif
name|SANITIZER_WINDOWS
define|#
directive|define
name|SANITIZER_CAN_FAST_UNWIND
value|0
else|#
directive|else
define|#
directive|define
name|SANITIZER_CAN_FAST_UNWIND
value|1
endif|#
directive|endif
struct|struct
name|StackTrace
block|{
typedef|typedef
name|bool
function_decl|(
modifier|*
name|SymbolizeCallback
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
name|pc
parameter_list|,
name|char
modifier|*
name|out_buffer
parameter_list|,
name|int
name|out_size
parameter_list|)
function_decl|;
name|uptr
name|top_frame_bp
decl_stmt|;
name|uptr
name|size
decl_stmt|;
name|uptr
name|trace
index|[
name|kStackTraceMax
index|]
decl_stmt|;
comment|// Prints a symbolized stacktrace, followed by an empty line.
specifier|static
name|void
name|PrintStack
parameter_list|(
specifier|const
name|uptr
modifier|*
name|addr
parameter_list|,
name|uptr
name|size
parameter_list|,
name|SymbolizeCallback
name|symbolize_callback
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|CopyFrom
parameter_list|(
specifier|const
name|uptr
modifier|*
name|src
parameter_list|,
name|uptr
name|src_size
parameter_list|)
block|{
name|top_frame_bp
operator|=
literal|0
expr_stmt|;
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
specifier|static
name|bool
name|WillUseFastUnwind
parameter_list|(
name|bool
name|request_fast_unwind
parameter_list|)
block|{
comment|// Check if fast unwind is available. Fast unwind is the only option on Mac.
if|if
condition|(
operator|!
name|SANITIZER_CAN_FAST_UNWIND
condition|)
return|return
name|false
return|;
elseif|else
if|if
condition|(
name|SANITIZER_MAC
condition|)
return|return
name|true
return|;
return|return
name|request_fast_unwind
return|;
block|}
name|void
name|Unwind
parameter_list|(
name|uptr
name|max_depth
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|uptr
name|bp
parameter_list|,
name|uptr
name|stack_top
parameter_list|,
name|uptr
name|stack_bottom
parameter_list|,
name|bool
name|request_fast_unwind
parameter_list|)
function_decl|;
specifier|static
name|uptr
name|GetCurrentPc
parameter_list|()
function_decl|;
specifier|static
name|uptr
name|GetPreviousInstructionPc
parameter_list|(
name|uptr
name|pc
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|FastUnwindStack
parameter_list|(
name|uptr
name|pc
parameter_list|,
name|uptr
name|bp
parameter_list|,
name|uptr
name|stack_top
parameter_list|,
name|uptr
name|stack_bottom
parameter_list|,
name|uptr
name|max_depth
parameter_list|)
function_decl|;
name|void
name|SlowUnwindStack
parameter_list|(
name|uptr
name|pc
parameter_list|,
name|uptr
name|max_depth
parameter_list|)
function_decl|;
name|void
name|PopStackFrames
parameter_list|(
name|uptr
name|count
parameter_list|)
function_decl|;
name|uptr
name|LocatePcInTrace
parameter_list|(
name|uptr
name|pc
parameter_list|)
function_decl|;
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
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
value|uptr bp = GET_CURRENT_FRAME();              \   uptr pc = StackTrace::GetCurrentPc();   \   uptr local_stack;                           \   uptr sp = (uptr)&local_stack
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_STACKTRACE_H
end_comment

end_unit

