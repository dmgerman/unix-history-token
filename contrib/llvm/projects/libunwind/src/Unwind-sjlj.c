begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--------------------------- Unwind-sjlj.c ----------------------------===//
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
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Implements setjump-longjump based C++ exceptions
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
file|<unwind.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"unwind_ext.h"
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|// 32-bit iOS uses setjump/longjump based C++ exceptions.
end_comment

begin_comment
comment|// Other architectures use "zero cost" exceptions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// With SJLJ based exceptions, any function that has a catch clause or needs to
end_comment

begin_comment
comment|// do any clean up when an exception propagates through it, needs to call
end_comment

begin_comment
comment|// _Unwind_SjLj_Register() at the start of the function and
end_comment

begin_comment
comment|// _Unwind_SjLj_Unregister() at the end.  The register function is called with
end_comment

begin_comment
comment|// the address of a block of memory in the function's stack frame.  The runtime
end_comment

begin_comment
comment|// keeps a linked list (stack) of these blocks - one per thread.  The calling
end_comment

begin_comment
comment|// function also sets the personality and lsda fields of the block.
end_comment

begin_comment
comment|//
end_comment

begin_if
if|#
directive|if
name|_LIBUNWIND_BUILD_SJLJ_APIS
end_if

begin_struct
struct|struct
name|_Unwind_FunctionContext
block|{
comment|// next function in stack of handlers
name|struct
name|_Unwind_FunctionContext
modifier|*
name|prev
decl_stmt|;
comment|// set by calling function before registering to be the landing pad
name|uintptr_t
name|resumeLocation
decl_stmt|;
comment|// set by personality handler to be parameters passed to landing pad function
name|uintptr_t
name|resumeParameters
index|[
literal|4
index|]
decl_stmt|;
comment|// set by calling function before registering
name|__personality_routine
name|personality
decl_stmt|;
comment|// arm offset=24
name|uintptr_t
name|lsda
decl_stmt|;
comment|// arm offset=28
comment|// variable length array, contains registers to restore
comment|// 0 = r7, 1 = pc, 2 = sp
name|void
modifier|*
name|jbuf
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// Called at start of each function that catches exceptions
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|void
name|_Unwind_SjLj_Register
parameter_list|(
name|struct
name|_Unwind_FunctionContext
modifier|*
name|fc
parameter_list|)
block|{
name|fc
operator|->
name|prev
operator|=
name|__Unwind_SjLj_GetTopOfFunctionStack
argument_list|()
expr_stmt|;
name|__Unwind_SjLj_SetTopOfFunctionStack
argument_list|(
name|fc
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Called at end of each function that catches exceptions
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|void
name|_Unwind_SjLj_Unregister
parameter_list|(
name|struct
name|_Unwind_FunctionContext
modifier|*
name|fc
parameter_list|)
block|{
name|__Unwind_SjLj_SetTopOfFunctionStack
argument_list|(
name|fc
operator|->
name|prev
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|_Unwind_Reason_Code
name|unwind_phase1
parameter_list|(
name|struct
name|_Unwind_Exception
modifier|*
name|exception_object
parameter_list|)
block|{
name|_Unwind_FunctionContext_t
name|c
init|=
name|__Unwind_SjLj_GetTopOfFunctionStack
argument_list|()
decl_stmt|;
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|"unwind_phase1: initial function-context=%p"
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|// walk each frame looking for a place to stop
for|for
control|(
name|bool
name|handlerNotFound
init|=
name|true
init|;
name|handlerNotFound
condition|;
name|c
operator|=
name|c
operator|->
name|prev
control|)
block|{
comment|// check for no more frames
if|if
condition|(
name|c
operator|==
name|NULL
condition|)
block|{
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|"unwind_phase1(ex_ojb=%p): reached "
literal|"bottom => _URC_END_OF_STACK"
argument_list|,
name|exception_object
argument_list|)
expr_stmt|;
return|return
name|_URC_END_OF_STACK
return|;
block|}
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|"unwind_phase1: function-context=%p"
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|// if there is a personality routine, ask it if it will want to stop at this
comment|// frame
if|if
condition|(
name|c
operator|->
name|personality
operator|!=
name|NULL
condition|)
block|{
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|"unwind_phase1(ex_ojb=%p): calling "
literal|"personality function %p"
argument_list|,
name|exception_object
argument_list|,
name|c
operator|->
name|personality
argument_list|)
expr_stmt|;
name|_Unwind_Reason_Code
name|personalityResult
init|=
call|(
modifier|*
name|c
operator|->
name|personality
call|)
argument_list|(
literal|1
argument_list|,
name|_UA_SEARCH_PHASE
argument_list|,
name|exception_object
operator|->
name|exception_class
argument_list|,
name|exception_object
argument_list|,
operator|(
expr|struct
name|_Unwind_Context
operator|*
operator|)
name|c
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|personalityResult
condition|)
block|{
case|case
name|_URC_HANDLER_FOUND
case|:
comment|// found a catch clause or locals that need destructing in this frame
comment|// stop search and remember function context
name|handlerNotFound
operator|=
name|false
expr_stmt|;
name|exception_object
operator|->
name|private_2
operator|=
operator|(
name|uintptr_t
operator|)
name|c
expr_stmt|;
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|"unwind_phase1(ex_ojb=%p): "
literal|"_URC_HANDLER_FOUND"
argument_list|,
name|exception_object
argument_list|)
expr_stmt|;
return|return
name|_URC_NO_REASON
return|;
case|case
name|_URC_CONTINUE_UNWIND
case|:
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|"unwind_phase1(ex_ojb=%p): "
literal|"_URC_CONTINUE_UNWIND"
argument_list|,
name|exception_object
argument_list|)
expr_stmt|;
comment|// continue unwinding
break|break;
default|default:
comment|// something went wrong
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|"unwind_phase1(ex_ojb=%p): _URC_FATAL_PHASE1_ERROR"
argument_list|,
name|exception_object
argument_list|)
expr_stmt|;
return|return
name|_URC_FATAL_PHASE1_ERROR
return|;
block|}
block|}
block|}
return|return
name|_URC_NO_REASON
return|;
block|}
end_function

begin_function
specifier|static
name|_Unwind_Reason_Code
name|unwind_phase2
parameter_list|(
name|struct
name|_Unwind_Exception
modifier|*
name|exception_object
parameter_list|)
block|{
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|"unwind_phase2(ex_ojb=%p)"
argument_list|,
name|exception_object
argument_list|)
expr_stmt|;
comment|// walk each frame until we reach where search phase said to stop
name|_Unwind_FunctionContext_t
name|c
init|=
name|__Unwind_SjLj_GetTopOfFunctionStack
argument_list|()
decl_stmt|;
while|while
condition|(
name|true
condition|)
block|{
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|"unwind_phase2s(ex_ojb=%p): context=%p"
argument_list|,
name|exception_object
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|// check for no more frames
if|if
condition|(
name|c
operator|==
name|NULL
condition|)
block|{
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|"unwind_phase2(ex_ojb=%p): unw_step() reached "
literal|"bottom => _URC_END_OF_STACK"
argument_list|,
name|exception_object
argument_list|)
expr_stmt|;
return|return
name|_URC_END_OF_STACK
return|;
block|}
comment|// if there is a personality routine, tell it we are unwinding
if|if
condition|(
name|c
operator|->
name|personality
operator|!=
name|NULL
condition|)
block|{
name|_Unwind_Action
name|action
init|=
name|_UA_CLEANUP_PHASE
decl_stmt|;
if|if
condition|(
operator|(
name|uintptr_t
operator|)
name|c
operator|==
name|exception_object
operator|->
name|private_2
condition|)
name|action
operator|=
call|(
name|_Unwind_Action
call|)
argument_list|(
name|_UA_CLEANUP_PHASE
operator||
name|_UA_HANDLER_FRAME
argument_list|)
expr_stmt|;
comment|// tell personality this was the frame it marked
comment|// in phase 1
name|_Unwind_Reason_Code
name|personalityResult
init|=
call|(
modifier|*
name|c
operator|->
name|personality
call|)
argument_list|(
literal|1
argument_list|,
name|action
argument_list|,
name|exception_object
operator|->
name|exception_class
argument_list|,
name|exception_object
argument_list|,
operator|(
expr|struct
name|_Unwind_Context
operator|*
operator|)
name|c
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|personalityResult
condition|)
block|{
case|case
name|_URC_CONTINUE_UNWIND
case|:
comment|// continue unwinding
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|"unwind_phase2(ex_ojb=%p): _URC_CONTINUE_UNWIND"
argument_list|,
name|exception_object
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|uintptr_t
operator|)
name|c
operator|==
name|exception_object
operator|->
name|private_2
condition|)
block|{
comment|// phase 1 said we would stop at this frame, but we did not...
name|_LIBUNWIND_ABORT
argument_list|(
literal|"during phase1 personality function said it would "
literal|"stop here, but now if phase2 it did not stop here"
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|_URC_INSTALL_CONTEXT
case|:
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|"unwind_phase2(ex_ojb=%p): "
literal|"_URC_INSTALL_CONTEXT, will resume at "
literal|"landing pad %p"
argument_list|,
name|exception_object
argument_list|,
name|c
operator|->
name|jbuf
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// personality routine says to transfer control to landing pad
comment|// we may get control back if landing pad calls _Unwind_Resume()
name|__Unwind_SjLj_SetTopOfFunctionStack
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|__builtin_longjmp
argument_list|(
name|c
operator|->
name|jbuf
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// unw_resume() only returns if there was an error
return|return
name|_URC_FATAL_PHASE2_ERROR
return|;
default|default:
comment|// something went wrong
name|_LIBUNWIND_DEBUG_LOG
argument_list|(
literal|"personality function returned unknown result %d"
argument_list|,
name|personalityResult
argument_list|)
expr_stmt|;
return|return
name|_URC_FATAL_PHASE2_ERROR
return|;
block|}
block|}
name|c
operator|=
name|c
operator|->
name|prev
expr_stmt|;
block|}
comment|// clean up phase did not resume at the frame that the search phase said it
comment|// would
return|return
name|_URC_FATAL_PHASE2_ERROR
return|;
block|}
end_function

begin_function
specifier|static
name|_Unwind_Reason_Code
name|unwind_phase2_forced
parameter_list|(
name|struct
name|_Unwind_Exception
modifier|*
name|exception_object
parameter_list|,
name|_Unwind_Stop_Fn
name|stop
parameter_list|,
name|void
modifier|*
name|stop_parameter
parameter_list|)
block|{
comment|// walk each frame until we reach where search phase said to stop
name|_Unwind_FunctionContext_t
name|c
init|=
name|__Unwind_SjLj_GetTopOfFunctionStack
argument_list|()
decl_stmt|;
while|while
condition|(
name|true
condition|)
block|{
comment|// get next frame (skip over first which is _Unwind_RaiseException)
if|if
condition|(
name|c
operator|==
name|NULL
condition|)
block|{
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|"unwind_phase2(ex_ojb=%p): unw_step() reached "
literal|"bottom => _URC_END_OF_STACK"
argument_list|,
name|exception_object
argument_list|)
expr_stmt|;
return|return
name|_URC_END_OF_STACK
return|;
block|}
comment|// call stop function at each frame
name|_Unwind_Action
name|action
init|=
call|(
name|_Unwind_Action
call|)
argument_list|(
name|_UA_FORCE_UNWIND
operator||
name|_UA_CLEANUP_PHASE
argument_list|)
decl_stmt|;
name|_Unwind_Reason_Code
name|stopResult
init|=
call|(
modifier|*
name|stop
call|)
argument_list|(
literal|1
argument_list|,
name|action
argument_list|,
name|exception_object
operator|->
name|exception_class
argument_list|,
name|exception_object
argument_list|,
operator|(
expr|struct
name|_Unwind_Context
operator|*
operator|)
name|c
argument_list|,
name|stop_parameter
argument_list|)
decl_stmt|;
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|"unwind_phase2_forced(ex_ojb=%p): "
literal|"stop function returned %d"
argument_list|,
name|exception_object
argument_list|,
name|stopResult
argument_list|)
expr_stmt|;
if|if
condition|(
name|stopResult
operator|!=
name|_URC_NO_REASON
condition|)
block|{
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|"unwind_phase2_forced(ex_ojb=%p): "
literal|"stopped by stop function"
argument_list|,
name|exception_object
argument_list|)
expr_stmt|;
return|return
name|_URC_FATAL_PHASE2_ERROR
return|;
block|}
comment|// if there is a personality routine, tell it we are unwinding
if|if
condition|(
name|c
operator|->
name|personality
operator|!=
name|NULL
condition|)
block|{
name|__personality_routine
name|p
init|=
operator|(
name|__personality_routine
operator|)
name|c
operator|->
name|personality
decl_stmt|;
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|"unwind_phase2_forced(ex_ojb=%p): "
literal|"calling personality function %p"
argument_list|,
name|exception_object
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|_Unwind_Reason_Code
name|personalityResult
init|=
call|(
modifier|*
name|p
call|)
argument_list|(
literal|1
argument_list|,
name|action
argument_list|,
name|exception_object
operator|->
name|exception_class
argument_list|,
name|exception_object
argument_list|,
operator|(
expr|struct
name|_Unwind_Context
operator|*
operator|)
name|c
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|personalityResult
condition|)
block|{
case|case
name|_URC_CONTINUE_UNWIND
case|:
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|"unwind_phase2_forced(ex_ojb=%p):  "
literal|"personality returned _URC_CONTINUE_UNWIND"
argument_list|,
name|exception_object
argument_list|)
expr_stmt|;
comment|// destructors called, continue unwinding
break|break;
case|case
name|_URC_INSTALL_CONTEXT
case|:
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|"unwind_phase2_forced(ex_ojb=%p): "
literal|"personality returned _URC_INSTALL_CONTEXT"
argument_list|,
name|exception_object
argument_list|)
expr_stmt|;
comment|// we may get control back if landing pad calls _Unwind_Resume()
name|__Unwind_SjLj_SetTopOfFunctionStack
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|__builtin_longjmp
argument_list|(
name|c
operator|->
name|jbuf
argument_list|,
literal|1
argument_list|)
expr_stmt|;
break|break;
default|default:
comment|// something went wrong
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|"unwind_phase2_forced(ex_ojb=%p): "
literal|"personality returned %d, "
literal|"_URC_FATAL_PHASE2_ERROR"
argument_list|,
name|exception_object
argument_list|,
name|personalityResult
argument_list|)
expr_stmt|;
return|return
name|_URC_FATAL_PHASE2_ERROR
return|;
block|}
block|}
name|c
operator|=
name|c
operator|->
name|prev
expr_stmt|;
block|}
comment|// call stop function one last time and tell it we've reached the end of the
comment|// stack
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|"unwind_phase2_forced(ex_ojb=%p): calling stop "
literal|"function with _UA_END_OF_STACK"
argument_list|,
name|exception_object
argument_list|)
expr_stmt|;
name|_Unwind_Action
name|lastAction
init|=
call|(
name|_Unwind_Action
call|)
argument_list|(
name|_UA_FORCE_UNWIND
operator||
name|_UA_CLEANUP_PHASE
operator||
name|_UA_END_OF_STACK
argument_list|)
decl_stmt|;
call|(
modifier|*
name|stop
call|)
argument_list|(
literal|1
argument_list|,
name|lastAction
argument_list|,
name|exception_object
operator|->
name|exception_class
argument_list|,
name|exception_object
argument_list|,
operator|(
expr|struct
name|_Unwind_Context
operator|*
operator|)
name|c
argument_list|,
name|stop_parameter
argument_list|)
expr_stmt|;
comment|// clean up phase did not resume at the frame that the search phase said it
comment|// would
return|return
name|_URC_FATAL_PHASE2_ERROR
return|;
block|}
end_function

begin_comment
comment|/// Called by __cxa_throw.  Only returns if there is a fatal error
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|_Unwind_Reason_Code
name|_Unwind_SjLj_RaiseException
parameter_list|(
name|struct
name|_Unwind_Exception
modifier|*
name|exception_object
parameter_list|)
block|{
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"_Unwind_SjLj_RaiseException(ex_obj=%p)"
argument_list|,
name|exception_object
argument_list|)
expr_stmt|;
comment|// mark that this is a non-forced unwind, so _Unwind_Resume() can do the right
comment|// thing
name|exception_object
operator|->
name|private_1
operator|=
literal|0
expr_stmt|;
name|exception_object
operator|->
name|private_2
operator|=
literal|0
expr_stmt|;
comment|// phase 1: the search phase
name|_Unwind_Reason_Code
name|phase1
init|=
name|unwind_phase1
argument_list|(
name|exception_object
argument_list|)
decl_stmt|;
if|if
condition|(
name|phase1
operator|!=
name|_URC_NO_REASON
condition|)
return|return
name|phase1
return|;
comment|// phase 2: the clean up phase
return|return
name|unwind_phase2
argument_list|(
name|exception_object
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// When _Unwind_RaiseException() is in phase2, it hands control
end_comment

begin_comment
comment|/// to the personality function at each frame.  The personality
end_comment

begin_comment
comment|/// may force a jump to a landing pad in that function, the landing
end_comment

begin_comment
comment|/// pad code may then call _Unwind_Resume() to continue with the
end_comment

begin_comment
comment|/// unwinding.  Note: the call to _Unwind_Resume() is from compiler
end_comment

begin_comment
comment|/// geneated user code.  All other _Unwind_* routines are called
end_comment

begin_comment
comment|/// by the C++ runtime __cxa_* routines.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Re-throwing an exception is implemented by having the code call
end_comment

begin_comment
comment|/// __cxa_rethrow() which in turn calls _Unwind_Resume_or_Rethrow()
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|void
name|_Unwind_SjLj_Resume
parameter_list|(
name|struct
name|_Unwind_Exception
modifier|*
name|exception_object
parameter_list|)
block|{
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"_Unwind_SjLj_Resume(ex_obj=%p)"
argument_list|,
name|exception_object
argument_list|)
expr_stmt|;
if|if
condition|(
name|exception_object
operator|->
name|private_1
operator|!=
literal|0
condition|)
name|unwind_phase2_forced
argument_list|(
name|exception_object
argument_list|,
operator|(
name|_Unwind_Stop_Fn
operator|)
name|exception_object
operator|->
name|private_1
argument_list|,
operator|(
name|void
operator|*
operator|)
name|exception_object
operator|->
name|private_2
argument_list|)
expr_stmt|;
else|else
name|unwind_phase2
argument_list|(
name|exception_object
argument_list|)
expr_stmt|;
comment|// clients assume _Unwind_Resume() does not return, so all we can do is abort.
name|_LIBUNWIND_ABORT
argument_list|(
literal|"_Unwind_SjLj_Resume() can't return"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|///  Called by __cxa_rethrow().
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|_Unwind_Reason_Code
name|_Unwind_SjLj_Resume_or_Rethrow
parameter_list|(
name|struct
name|_Unwind_Exception
modifier|*
name|exception_object
parameter_list|)
block|{
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"__Unwind_SjLj_Resume_or_Rethrow(ex_obj=%p), "
literal|"private_1=%ld"
argument_list|,
name|exception_object
argument_list|,
name|exception_object
operator|->
name|private_1
argument_list|)
expr_stmt|;
comment|// If this is non-forced and a stopping place was found, then this is a
comment|// re-throw.
comment|// Call _Unwind_RaiseException() as if this was a new exception.
if|if
condition|(
name|exception_object
operator|->
name|private_1
operator|==
literal|0
condition|)
block|{
return|return
name|_Unwind_SjLj_RaiseException
argument_list|(
name|exception_object
argument_list|)
return|;
comment|// should return if there is no catch clause, so that __cxa_rethrow can call
comment|// std::terminate()
block|}
comment|// Call through to _Unwind_Resume() which distiguishes between forced and
comment|// regular exceptions.
name|_Unwind_SjLj_Resume
argument_list|(
name|exception_object
argument_list|)
expr_stmt|;
name|_LIBUNWIND_ABORT
argument_list|(
literal|"__Unwind_SjLj_Resume_or_Rethrow() called "
literal|"_Unwind_SjLj_Resume() which unexpectedly returned"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Called by personality handler during phase 2 to get LSDA for current frame.
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|uintptr_t
name|_Unwind_GetLanguageSpecificData
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
name|context
parameter_list|)
block|{
name|_Unwind_FunctionContext_t
name|ufc
init|=
operator|(
name|_Unwind_FunctionContext_t
operator|)
name|context
decl_stmt|;
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"_Unwind_GetLanguageSpecificData(context=%p) "
literal|"=> 0x%0lX"
argument_list|,
name|context
argument_list|,
name|ufc
operator|->
name|lsda
argument_list|)
expr_stmt|;
return|return
name|ufc
operator|->
name|lsda
return|;
block|}
end_function

begin_comment
comment|/// Called by personality handler during phase 2 to get register values.
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|uintptr_t
name|_Unwind_GetGR
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
name|context
parameter_list|,
name|int
name|index
parameter_list|)
block|{
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"_Unwind_GetGR(context=%p, reg=%d)"
argument_list|,
name|context
argument_list|,
name|index
argument_list|)
expr_stmt|;
name|_Unwind_FunctionContext_t
name|ufc
init|=
operator|(
name|_Unwind_FunctionContext_t
operator|)
name|context
decl_stmt|;
return|return
name|ufc
operator|->
name|resumeParameters
index|[
name|index
index|]
return|;
block|}
end_function

begin_comment
comment|/// Called by personality handler during phase 2 to alter register values.
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|void
name|_Unwind_SetGR
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
name|context
parameter_list|,
name|int
name|index
parameter_list|,
name|uintptr_t
name|new_value
parameter_list|)
block|{
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"_Unwind_SetGR(context=%p, reg=%d, value=0x%0lX)"
argument_list|,
name|context
argument_list|,
name|index
argument_list|,
name|new_value
argument_list|)
expr_stmt|;
name|_Unwind_FunctionContext_t
name|ufc
init|=
operator|(
name|_Unwind_FunctionContext_t
operator|)
name|context
decl_stmt|;
name|ufc
operator|->
name|resumeParameters
index|[
name|index
index|]
operator|=
name|new_value
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Called by personality handler during phase 2 to get instruction pointer.
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|uintptr_t
name|_Unwind_GetIP
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
name|context
parameter_list|)
block|{
name|_Unwind_FunctionContext_t
name|ufc
init|=
operator|(
name|_Unwind_FunctionContext_t
operator|)
name|context
decl_stmt|;
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"_Unwind_GetIP(context=%p) => 0x%lX"
argument_list|,
name|context
argument_list|,
name|ufc
operator|->
name|resumeLocation
operator|+
literal|1
argument_list|)
expr_stmt|;
return|return
name|ufc
operator|->
name|resumeLocation
operator|+
literal|1
return|;
block|}
end_function

begin_comment
comment|/// Called by personality handler during phase 2 to get instruction pointer.
end_comment

begin_comment
comment|/// ipBefore is a boolean that says if IP is already adjusted to be the call
end_comment

begin_comment
comment|/// site address.  Normally IP is the return address.
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|uintptr_t
name|_Unwind_GetIPInfo
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
name|context
parameter_list|,
name|int
modifier|*
name|ipBefore
parameter_list|)
block|{
name|_Unwind_FunctionContext_t
name|ufc
init|=
operator|(
name|_Unwind_FunctionContext_t
operator|)
name|context
decl_stmt|;
operator|*
name|ipBefore
operator|=
literal|0
expr_stmt|;
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"_Unwind_GetIPInfo(context=%p, %p) => 0x%lX"
argument_list|,
name|context
argument_list|,
name|ipBefore
argument_list|,
name|ufc
operator|->
name|resumeLocation
operator|+
literal|1
argument_list|)
expr_stmt|;
return|return
name|ufc
operator|->
name|resumeLocation
operator|+
literal|1
return|;
block|}
end_function

begin_comment
comment|/// Called by personality handler during phase 2 to alter instruction pointer.
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|void
name|_Unwind_SetIP
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
name|context
parameter_list|,
name|uintptr_t
name|new_value
parameter_list|)
block|{
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"_Unwind_SetIP(context=%p, value=0x%0lX)"
argument_list|,
name|context
argument_list|,
name|new_value
argument_list|)
expr_stmt|;
name|_Unwind_FunctionContext_t
name|ufc
init|=
operator|(
name|_Unwind_FunctionContext_t
operator|)
name|context
decl_stmt|;
name|ufc
operator|->
name|resumeLocation
operator|=
name|new_value
operator|-
literal|1
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Called by personality handler during phase 2 to find the start of the
end_comment

begin_comment
comment|/// function.
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|uintptr_t
name|_Unwind_GetRegionStart
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
name|context
parameter_list|)
block|{
comment|// Not supported or needed for sjlj based unwinding
operator|(
name|void
operator|)
name|context
expr_stmt|;
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"_Unwind_GetRegionStart(context=%p)"
argument_list|,
name|context
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/// Called by personality handler during phase 2 if a foreign exception
end_comment

begin_comment
comment|/// is caught.
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|void
name|_Unwind_DeleteException
parameter_list|(
name|struct
name|_Unwind_Exception
modifier|*
name|exception_object
parameter_list|)
block|{
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"_Unwind_DeleteException(ex_obj=%p)"
argument_list|,
name|exception_object
argument_list|)
expr_stmt|;
if|if
condition|(
name|exception_object
operator|->
name|exception_cleanup
operator|!=
name|NULL
condition|)
call|(
modifier|*
name|exception_object
operator|->
name|exception_cleanup
call|)
argument_list|(
name|_URC_FOREIGN_EXCEPTION_CAUGHT
argument_list|,
name|exception_object
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Called by personality handler during phase 2 to get base address for data
end_comment

begin_comment
comment|/// relative encodings.
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|uintptr_t
name|_Unwind_GetDataRelBase
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
name|context
parameter_list|)
block|{
comment|// Not supported or needed for sjlj based unwinding
operator|(
name|void
operator|)
name|context
expr_stmt|;
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"_Unwind_GetDataRelBase(context=%p)"
argument_list|,
name|context
argument_list|)
expr_stmt|;
name|_LIBUNWIND_ABORT
argument_list|(
literal|"_Unwind_GetDataRelBase() not implemented"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Called by personality handler during phase 2 to get base address for text
end_comment

begin_comment
comment|/// relative encodings.
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|uintptr_t
name|_Unwind_GetTextRelBase
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
name|context
parameter_list|)
block|{
comment|// Not supported or needed for sjlj based unwinding
operator|(
name|void
operator|)
name|context
expr_stmt|;
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"_Unwind_GetTextRelBase(context=%p)"
argument_list|,
name|context
argument_list|)
expr_stmt|;
name|_LIBUNWIND_ABORT
argument_list|(
literal|"_Unwind_GetTextRelBase() not implemented"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Called by personality handler to get "Call Frame Area" for current frame.
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|uintptr_t
name|_Unwind_GetCFA
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
name|context
parameter_list|)
block|{
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"_Unwind_GetCFA(context=%p)"
argument_list|,
name|context
argument_list|)
expr_stmt|;
if|if
condition|(
name|context
operator|!=
name|NULL
condition|)
block|{
name|_Unwind_FunctionContext_t
name|ufc
init|=
operator|(
name|_Unwind_FunctionContext_t
operator|)
name|context
decl_stmt|;
comment|// Setjmp/longjmp based exceptions don't have a true CFA.
comment|// Instead, the SP in the jmpbuf is the closest approximation.
return|return
operator|(
name|uintptr_t
operator|)
name|ufc
operator|->
name|jbuf
index|[
literal|2
index|]
return|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBUNWIND_BUILD_SJLJ_APIS
end_comment

end_unit

