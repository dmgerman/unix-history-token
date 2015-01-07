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
name|__aarch64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
operator|||
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
comment|// Fast unwind is the only option on Mac for now; we will need to
comment|// revisit this macro when slow unwind works on Mac, see
comment|// https://code.google.com/p/address-sanitizer/issues/detail?id=137
if|#
directive|if
name|SANITIZER_MAC
define|#
directive|define
name|SANITIZER_CAN_SLOW_UNWIND
value|0
else|#
directive|else
define|#
directive|define
name|SANITIZER_CAN_SLOW_UNWIND
value|1
endif|#
directive|endif
struct|struct
name|StackTrace
block|{
specifier|const
name|uptr
modifier|*
name|trace
decl_stmt|;
name|uptr
name|size
decl_stmt|;
name|StackTrace
argument_list|()
operator|:
name|trace
argument_list|(
name|nullptr
argument_list|)
operator|,
name|size
argument_list|(
literal|0
argument_list|)
block|{}
name|StackTrace
argument_list|(
argument|const uptr *trace
argument_list|,
argument|uptr size
argument_list|)
operator|:
name|trace
argument_list|(
name|trace
argument_list|)
operator|,
name|size
argument_list|(
argument|size
argument_list|)
block|{}
comment|// Prints a symbolized stacktrace, followed by an empty line.
name|void
name|Print
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|bool
name|WillUseFastUnwind
parameter_list|(
name|bool
name|request_fast_unwind
parameter_list|)
block|{
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
operator|!
name|SANITIZER_CAN_SLOW_UNWIND
condition|)
return|return
name|true
return|;
return|return
name|request_fast_unwind
return|;
block|}
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
specifier|static
name|uptr
name|GetNextInstructionPc
parameter_list|(
name|uptr
name|pc
parameter_list|)
function_decl|;
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
block|}
struct|;
comment|// StackTrace that owns the buffer used to store the addresses.
name|struct
name|BufferedStackTrace
range|:
name|public
name|StackTrace
block|{
name|uptr
name|trace_buffer
index|[
name|kStackTraceMax
index|]
block|;
name|uptr
name|top_frame_bp
block|;
comment|// Optional bp of a top frame.
name|BufferedStackTrace
argument_list|()
operator|:
name|StackTrace
argument_list|(
name|trace_buffer
argument_list|,
literal|0
argument_list|)
block|,
name|top_frame_bp
argument_list|(
literal|0
argument_list|)
block|{}
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
name|void
name|Unwind
argument_list|(
argument|uptr max_depth
argument_list|,
argument|uptr pc
argument_list|,
argument|uptr bp
argument_list|,
argument|void *context
argument_list|,
argument|uptr stack_top
argument_list|,
argument|uptr stack_bottom
argument_list|,
argument|bool request_fast_unwind
argument_list|)
block|;
name|private
operator|:
name|void
name|FastUnwindStack
argument_list|(
argument|uptr pc
argument_list|,
argument|uptr bp
argument_list|,
argument|uptr stack_top
argument_list|,
argument|uptr stack_bottom
argument_list|,
argument|uptr max_depth
argument_list|)
block|;
name|void
name|SlowUnwindStack
argument_list|(
argument|uptr pc
argument_list|,
argument|uptr max_depth
argument_list|)
block|;
name|void
name|SlowUnwindStackWithContext
argument_list|(
argument|uptr pc
argument_list|,
argument|void *context
argument_list|,
argument|uptr max_depth
argument_list|)
block|;
name|void
name|PopStackFrames
argument_list|(
argument|uptr count
argument_list|)
block|;
name|uptr
name|LocatePcInTrace
argument_list|(
argument|uptr pc
argument_list|)
block|;
name|BufferedStackTrace
argument_list|(
specifier|const
name|BufferedStackTrace
operator|&
argument_list|)
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|BufferedStackTrace
operator|&
operator|)
block|; }
decl_stmt|;
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

begin_define
define|#
directive|define
name|GET_CALLER_PC_BP
define|\
value|uptr bp = GET_CURRENT_FRAME();              \   uptr pc = GET_CALLER_PC();
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

