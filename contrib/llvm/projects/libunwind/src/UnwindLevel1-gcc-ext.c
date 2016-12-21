begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--------------------- UnwindLevel1-gcc-ext.c -------------------------===//
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
comment|//  Implements gcc extensions to the C++ ABI Exception Handling Level 1.
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
file|<inttypes.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"libunwind_ext.h"
end_include

begin_include
include|#
directive|include
file|"libunwind.h"
end_include

begin_include
include|#
directive|include
file|"Unwind-EHABI.h"
end_include

begin_include
include|#
directive|include
file|"unwind.h"
end_include

begin_if
if|#
directive|if
name|_LIBUNWIND_BUILD_ZERO_COST_APIS
end_if

begin_comment
comment|///  Called by __cxa_rethrow().
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|_Unwind_Reason_Code
name|_Unwind_Resume_or_Rethrow
parameter_list|(
name|_Unwind_Exception
modifier|*
name|exception_object
parameter_list|)
block|{
if|#
directive|if
name|_LIBUNWIND_ARM_EHABI
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"_Unwind_Resume_or_Rethrow(ex_obj=%p), private_1=%ld"
argument_list|,
operator|(
name|void
operator|*
operator|)
name|exception_object
argument_list|,
operator|(
name|long
operator|)
name|exception_object
operator|->
name|unwinder_cache
operator|.
name|reserved1
argument_list|)
expr_stmt|;
else|#
directive|else
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"_Unwind_Resume_or_Rethrow(ex_obj=%p), private_1=%ld"
argument_list|,
operator|(
name|void
operator|*
operator|)
name|exception_object
argument_list|,
operator|(
name|long
operator|)
name|exception_object
operator|->
name|private_1
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|_LIBUNWIND_ARM_EHABI
comment|// _Unwind_RaiseException on EHABI will always set the reserved1 field to 0,
comment|// which is in the same position as private_1 below.
return|return
name|_Unwind_RaiseException
argument_list|(
name|exception_object
argument_list|)
return|;
else|#
directive|else
comment|// If this is non-forced and a stopping place was found, then this is a
comment|// re-throw.
comment|// Call _Unwind_RaiseException() as if this was a new exception
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
name|_Unwind_RaiseException
argument_list|(
name|exception_object
argument_list|)
return|;
comment|// Will return if there is no catch clause, so that __cxa_rethrow can call
comment|// std::terminate().
block|}
comment|// Call through to _Unwind_Resume() which distiguishes between forced and
comment|// regular exceptions.
name|_Unwind_Resume
argument_list|(
name|exception_object
argument_list|)
expr_stmt|;
name|_LIBUNWIND_ABORT
argument_list|(
literal|"_Unwind_Resume_or_Rethrow() called _Unwind_RaiseException()"
literal|" which unexpectedly returned"
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
operator|(
name|void
operator|)
name|context
expr_stmt|;
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"_Unwind_GetDataRelBase(context=%p)"
argument_list|,
operator|(
name|void
operator|*
operator|)
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
operator|(
name|void
operator|)
name|context
expr_stmt|;
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"_Unwind_GetTextRelBase(context=%p)"
argument_list|,
operator|(
name|void
operator|*
operator|)
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
comment|/// Scans unwind information to find the function that contains the
end_comment

begin_comment
comment|/// specified code address "pc".
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|void
modifier|*
name|_Unwind_FindEnclosingFunction
parameter_list|(
name|void
modifier|*
name|pc
parameter_list|)
block|{
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"_Unwind_FindEnclosingFunction(pc=%p)"
argument_list|,
name|pc
argument_list|)
expr_stmt|;
comment|// This is slow, but works.
comment|// We create an unwind cursor then alter the IP to be pc
name|unw_cursor_t
name|cursor
decl_stmt|;
name|unw_context_t
name|uc
decl_stmt|;
name|unw_proc_info_t
name|info
decl_stmt|;
name|unw_getcontext
argument_list|(
operator|&
name|uc
argument_list|)
expr_stmt|;
name|unw_init_local
argument_list|(
operator|&
name|cursor
argument_list|,
operator|&
name|uc
argument_list|)
expr_stmt|;
name|unw_set_reg
argument_list|(
operator|&
name|cursor
argument_list|,
name|UNW_REG_IP
argument_list|,
operator|(
name|unw_word_t
operator|)
operator|(
name|long
operator|)
name|pc
argument_list|)
expr_stmt|;
if|if
condition|(
name|unw_get_proc_info
argument_list|(
operator|&
name|cursor
argument_list|,
operator|&
name|info
argument_list|)
operator|==
name|UNW_ESUCCESS
condition|)
return|return
operator|(
name|void
operator|*
operator|)
operator|(
name|long
operator|)
name|info
operator|.
name|start_ip
return|;
else|else
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/// Walk every frame and call trace function at each one.  If trace function
end_comment

begin_comment
comment|/// returns anything other than _URC_NO_REASON, then walk is terminated.
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|_Unwind_Reason_Code
name|_Unwind_Backtrace
parameter_list|(
name|_Unwind_Trace_Fn
name|callback
parameter_list|,
name|void
modifier|*
name|ref
parameter_list|)
block|{
name|unw_cursor_t
name|cursor
decl_stmt|;
name|unw_context_t
name|uc
decl_stmt|;
name|unw_getcontext
argument_list|(
operator|&
name|uc
argument_list|)
expr_stmt|;
name|unw_init_local
argument_list|(
operator|&
name|cursor
argument_list|,
operator|&
name|uc
argument_list|)
expr_stmt|;
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"_Unwind_Backtrace(callback=%p)"
argument_list|,
operator|(
name|void
operator|*
operator|)
operator|(
name|uintptr_t
operator|)
name|callback
argument_list|)
expr_stmt|;
if|#
directive|if
name|_LIBUNWIND_ARM_EHABI
comment|// Create a mock exception object for force unwinding.
name|_Unwind_Exception
name|ex
decl_stmt|;
name|memset
argument_list|(
operator|&
name|ex
argument_list|,
literal|'\0'
argument_list|,
sizeof|sizeof
argument_list|(
name|ex
argument_list|)
argument_list|)
expr_stmt|;
name|ex
operator|.
name|exception_class
operator|=
literal|0x434C4E47554E5700
expr_stmt|;
comment|// CLNGUNW\0
endif|#
directive|endif
comment|// walk each frame
while|while
condition|(
name|true
condition|)
block|{
name|_Unwind_Reason_Code
name|result
decl_stmt|;
if|#
directive|if
operator|!
name|_LIBUNWIND_ARM_EHABI
comment|// ask libunwind to get next frame (skip over first frame which is
comment|// _Unwind_Backtrace())
if|if
condition|(
name|unw_step
argument_list|(
operator|&
name|cursor
argument_list|)
operator|<=
literal|0
condition|)
block|{
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|" _backtrace: ended because cursor reached "
literal|"bottom of stack, returning %d"
argument_list|,
name|_URC_END_OF_STACK
argument_list|)
expr_stmt|;
return|return
name|_URC_END_OF_STACK
return|;
block|}
else|#
directive|else
comment|// Get the information for this frame.
name|unw_proc_info_t
name|frameInfo
decl_stmt|;
if|if
condition|(
name|unw_get_proc_info
argument_list|(
operator|&
name|cursor
argument_list|,
operator|&
name|frameInfo
argument_list|)
operator|!=
name|UNW_ESUCCESS
condition|)
block|{
return|return
name|_URC_END_OF_STACK
return|;
block|}
comment|// Update the pr_cache in the mock exception object.
specifier|const
name|uint32_t
modifier|*
name|unwindInfo
init|=
operator|(
name|uint32_t
operator|*
operator|)
name|frameInfo
operator|.
name|unwind_info
decl_stmt|;
name|ex
operator|.
name|pr_cache
operator|.
name|fnstart
operator|=
name|frameInfo
operator|.
name|start_ip
expr_stmt|;
name|ex
operator|.
name|pr_cache
operator|.
name|ehtp
operator|=
operator|(
name|_Unwind_EHT_Header
operator|*
operator|)
name|unwindInfo
expr_stmt|;
name|ex
operator|.
name|pr_cache
operator|.
name|additional
operator|=
name|frameInfo
operator|.
name|flags
expr_stmt|;
name|struct
name|_Unwind_Context
modifier|*
name|context
init|=
operator|(
expr|struct
name|_Unwind_Context
operator|*
operator|)
operator|&
name|cursor
decl_stmt|;
comment|// Get and call the personality function to unwind the frame.
name|__personality_routine
name|handler
init|=
operator|(
name|__personality_routine
operator|)
name|frameInfo
operator|.
name|handler
decl_stmt|;
if|if
condition|(
name|handler
operator|==
name|NULL
condition|)
block|{
return|return
name|_URC_END_OF_STACK
return|;
block|}
if|if
condition|(
name|handler
argument_list|(
name|_US_VIRTUAL_UNWIND_FRAME
operator||
name|_US_FORCE_UNWIND
argument_list|,
operator|&
name|ex
argument_list|,
name|context
argument_list|)
operator|!=
name|_URC_CONTINUE_UNWIND
condition|)
block|{
return|return
name|_URC_END_OF_STACK
return|;
block|}
endif|#
directive|endif
comment|// _LIBUNWIND_ARM_EHABI
comment|// debugging
if|if
condition|(
name|_LIBUNWIND_TRACING_UNWINDING
condition|)
block|{
name|char
name|functionName
index|[
literal|512
index|]
decl_stmt|;
name|unw_proc_info_t
name|frame
decl_stmt|;
name|unw_word_t
name|offset
decl_stmt|;
name|unw_get_proc_name
argument_list|(
operator|&
name|cursor
argument_list|,
name|functionName
argument_list|,
literal|512
argument_list|,
operator|&
name|offset
argument_list|)
expr_stmt|;
name|unw_get_proc_info
argument_list|(
operator|&
name|cursor
argument_list|,
operator|&
name|frame
argument_list|)
expr_stmt|;
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|" _backtrace: start_ip=0x%llX, func=%s, lsda=0x%llX, context=%p"
argument_list|,
operator|(
name|long
name|long
operator|)
name|frame
operator|.
name|start_ip
argument_list|,
name|functionName
argument_list|,
operator|(
name|long
name|long
operator|)
name|frame
operator|.
name|lsda
argument_list|,
operator|(
name|void
operator|*
operator|)
operator|&
name|cursor
argument_list|)
expr_stmt|;
block|}
comment|// call trace function with this frame
name|result
operator|=
call|(
modifier|*
name|callback
call|)
argument_list|(
operator|(
expr|struct
name|_Unwind_Context
operator|*
operator|)
operator|(
operator|&
name|cursor
operator|)
argument_list|,
name|ref
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|!=
name|_URC_NO_REASON
condition|)
block|{
name|_LIBUNWIND_TRACE_UNWINDING
argument_list|(
literal|" _backtrace: ended because callback returned %d"
argument_list|,
name|result
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
block|}
block|}
end_function

begin_comment
comment|/// Find dwarf unwind info for an address 'pc' in some function.
end_comment

begin_function
name|_LIBUNWIND_EXPORT
specifier|const
name|void
modifier|*
name|_Unwind_Find_FDE
parameter_list|(
specifier|const
name|void
modifier|*
name|pc
parameter_list|,
name|struct
name|dwarf_eh_bases
modifier|*
name|bases
parameter_list|)
block|{
comment|// This is slow, but works.
comment|// We create an unwind cursor then alter the IP to be pc
name|unw_cursor_t
name|cursor
decl_stmt|;
name|unw_context_t
name|uc
decl_stmt|;
name|unw_proc_info_t
name|info
decl_stmt|;
name|unw_getcontext
argument_list|(
operator|&
name|uc
argument_list|)
expr_stmt|;
name|unw_init_local
argument_list|(
operator|&
name|cursor
argument_list|,
operator|&
name|uc
argument_list|)
expr_stmt|;
name|unw_set_reg
argument_list|(
operator|&
name|cursor
argument_list|,
name|UNW_REG_IP
argument_list|,
operator|(
name|unw_word_t
operator|)
operator|(
name|long
operator|)
name|pc
argument_list|)
expr_stmt|;
name|unw_get_proc_info
argument_list|(
operator|&
name|cursor
argument_list|,
operator|&
name|info
argument_list|)
expr_stmt|;
name|bases
operator|->
name|tbase
operator|=
operator|(
name|uintptr_t
operator|)
name|info
operator|.
name|extra
expr_stmt|;
name|bases
operator|->
name|dbase
operator|=
literal|0
expr_stmt|;
comment|// dbase not used on Mac OS X
name|bases
operator|->
name|func
operator|=
operator|(
name|uintptr_t
operator|)
name|info
operator|.
name|start_ip
expr_stmt|;
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"_Unwind_Find_FDE(pc=%p) => %p"
argument_list|,
name|pc
argument_list|,
operator|(
name|void
operator|*
operator|)
operator|(
name|long
operator|)
name|info
operator|.
name|unwind_info
argument_list|)
expr_stmt|;
return|return
operator|(
name|void
operator|*
operator|)
operator|(
name|long
operator|)
name|info
operator|.
name|unwind_info
return|;
block|}
end_function

begin_comment
comment|/// Returns the CFA (call frame area, or stack pointer at start of function)
end_comment

begin_comment
comment|/// for the current context.
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
name|unw_cursor_t
modifier|*
name|cursor
init|=
operator|(
name|unw_cursor_t
operator|*
operator|)
name|context
decl_stmt|;
name|unw_word_t
name|result
decl_stmt|;
name|unw_get_reg
argument_list|(
name|cursor
argument_list|,
name|UNW_REG_SP
argument_list|,
operator|&
name|result
argument_list|)
expr_stmt|;
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"_Unwind_GetCFA(context=%p) => 0x%"
name|PRIx64
argument_list|,
operator|(
name|void
operator|*
operator|)
name|context
argument_list|,
operator|(
name|uint64_t
operator|)
name|result
argument_list|)
expr_stmt|;
return|return
operator|(
name|uintptr_t
operator|)
name|result
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
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"_Unwind_GetIPInfo(context=%p)"
argument_list|,
operator|(
name|void
operator|*
operator|)
name|context
argument_list|)
expr_stmt|;
operator|*
name|ipBefore
operator|=
literal|0
expr_stmt|;
return|return
name|_Unwind_GetIP
argument_list|(
name|context
argument_list|)
return|;
block|}
end_function

begin_if
if|#
directive|if
name|_LIBUNWIND_SUPPORT_DWARF_UNWIND
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_comment
comment|// Based on LLVM's lib/ExecutionEngine/RuntimeDyld/RTDyldMemoryManager.cpp
end_comment

begin_comment
comment|// and XXX should be fixed to be alignment-safe.
end_comment

begin_function
specifier|static
name|void
name|processFDE
parameter_list|(
specifier|const
name|char
modifier|*
name|addr
parameter_list|,
name|bool
name|isDeregister
parameter_list|)
block|{
name|uint64_t
name|length
decl_stmt|;
while|while
condition|(
operator|(
name|length
operator|=
operator|*
operator|(
operator|(
specifier|const
name|uint32_t
operator|*
operator|)
name|addr
operator|)
operator|)
operator|!=
literal|0
condition|)
block|{
specifier|const
name|char
modifier|*
name|p
init|=
name|addr
operator|+
literal|4
decl_stmt|;
if|if
condition|(
name|length
operator|==
literal|0xffffffff
condition|)
block|{
name|length
operator|=
operator|*
operator|(
operator|(
specifier|const
name|uint64_t
operator|*
operator|)
name|p
operator|)
expr_stmt|;
name|p
operator|+=
literal|8
expr_stmt|;
block|}
name|uint32_t
name|offset
init|=
operator|*
operator|(
operator|(
specifier|const
name|uint32_t
operator|*
operator|)
name|p
operator|)
decl_stmt|;
if|if
condition|(
name|offset
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|isDeregister
condition|)
name|_unw_remove_dynamic_fde
argument_list|(
operator|(
name|unw_word_t
operator|)
operator|(
name|uintptr_t
operator|)
name|addr
argument_list|)
expr_stmt|;
else|else
name|_unw_add_dynamic_fde
argument_list|(
operator|(
name|unw_word_t
operator|)
operator|(
name|uintptr_t
operator|)
name|addr
argument_list|)
expr_stmt|;
block|}
name|addr
operator|=
name|p
operator|+
name|length
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/// Called by programs with dynamic code generators that want to register
end_comment

begin_comment
comment|/// dynamically generated FDEs, with a libgcc-compatible API.
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|void
name|__register_frame
parameter_list|(
specifier|const
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"__register_frame(%p)"
argument_list|,
name|addr
argument_list|)
expr_stmt|;
name|processFDE
argument_list|(
name|addr
argument_list|,
name|false
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Called by programs with dynamic code generators that want to unregister
end_comment

begin_comment
comment|/// dynamically generated FDEs, with a libgcc-compatible API.
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|void
name|__deregister_frame
parameter_list|(
specifier|const
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"__deregister_frame(%p)"
argument_list|,
name|addr
argument_list|)
expr_stmt|;
name|processFDE
argument_list|(
name|addr
argument_list|,
name|true
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/// Called by programs with dynamic code generators that want
end_comment

begin_comment
comment|/// to register a dynamically generated FDE.
end_comment

begin_comment
comment|/// This function has existed on Mac OS X since 10.4, but
end_comment

begin_comment
comment|/// was broken until 10.6.
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|void
name|__register_frame
parameter_list|(
specifier|const
name|void
modifier|*
name|fde
parameter_list|)
block|{
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"__register_frame(%p)"
argument_list|,
name|fde
argument_list|)
expr_stmt|;
name|_unw_add_dynamic_fde
argument_list|(
operator|(
name|unw_word_t
operator|)
operator|(
name|uintptr_t
operator|)
name|fde
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Called by programs with dynamic code generators that want
end_comment

begin_comment
comment|/// to unregister a dynamically generated FDE.
end_comment

begin_comment
comment|/// This function has existed on Mac OS X since 10.4, but
end_comment

begin_comment
comment|/// was broken until 10.6.
end_comment

begin_function
name|_LIBUNWIND_EXPORT
name|void
name|__deregister_frame
parameter_list|(
specifier|const
name|void
modifier|*
name|fde
parameter_list|)
block|{
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"__deregister_frame(%p)"
argument_list|,
name|fde
argument_list|)
expr_stmt|;
name|_unw_remove_dynamic_fde
argument_list|(
operator|(
name|unw_word_t
operator|)
operator|(
name|uintptr_t
operator|)
name|fde
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// The following register/deregister functions are gcc extensions.
end_comment

begin_comment
comment|// They have existed on Mac OS X, but have never worked because Mac OS X
end_comment

begin_comment
comment|// before 10.6 used keymgr to track known FDEs, but these functions
end_comment

begin_comment
comment|// never got updated to use keymgr.
end_comment

begin_comment
comment|// For now, we implement these as do-nothing functions to keep any existing
end_comment

begin_comment
comment|// applications working.  We also add the not in 10.6 symbol so that nwe
end_comment

begin_comment
comment|// application won't be able to use them.
end_comment

begin_if
if|#
directive|if
name|_LIBUNWIND_SUPPORT_FRAME_APIS
end_if

begin_function
name|_LIBUNWIND_EXPORT
name|void
name|__register_frame_info_bases
parameter_list|(
specifier|const
name|void
modifier|*
name|fde
parameter_list|,
name|void
modifier|*
name|ob
parameter_list|,
name|void
modifier|*
name|tb
parameter_list|,
name|void
modifier|*
name|db
parameter_list|)
block|{
operator|(
name|void
operator|)
name|fde
expr_stmt|;
operator|(
name|void
operator|)
name|ob
expr_stmt|;
operator|(
name|void
operator|)
name|tb
expr_stmt|;
operator|(
name|void
operator|)
name|db
expr_stmt|;
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"__register_frame_info_bases(%p,%p, %p, %p)"
argument_list|,
name|fde
argument_list|,
name|ob
argument_list|,
name|tb
argument_list|,
name|db
argument_list|)
expr_stmt|;
comment|// do nothing, this function never worked in Mac OS X
block|}
end_function

begin_function
name|_LIBUNWIND_EXPORT
name|void
name|__register_frame_info
parameter_list|(
specifier|const
name|void
modifier|*
name|fde
parameter_list|,
name|void
modifier|*
name|ob
parameter_list|)
block|{
operator|(
name|void
operator|)
name|fde
expr_stmt|;
operator|(
name|void
operator|)
name|ob
expr_stmt|;
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"__register_frame_info(%p, %p)"
argument_list|,
name|fde
argument_list|,
name|ob
argument_list|)
expr_stmt|;
comment|// do nothing, this function never worked in Mac OS X
block|}
end_function

begin_function
name|_LIBUNWIND_EXPORT
name|void
name|__register_frame_info_table_bases
parameter_list|(
specifier|const
name|void
modifier|*
name|fde
parameter_list|,
name|void
modifier|*
name|ob
parameter_list|,
name|void
modifier|*
name|tb
parameter_list|,
name|void
modifier|*
name|db
parameter_list|)
block|{
operator|(
name|void
operator|)
name|fde
expr_stmt|;
operator|(
name|void
operator|)
name|ob
expr_stmt|;
operator|(
name|void
operator|)
name|tb
expr_stmt|;
operator|(
name|void
operator|)
name|db
expr_stmt|;
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"__register_frame_info_table_bases"
literal|"(%p,%p, %p, %p)"
argument_list|,
name|fde
argument_list|,
name|ob
argument_list|,
name|tb
argument_list|,
name|db
argument_list|)
expr_stmt|;
comment|// do nothing, this function never worked in Mac OS X
block|}
end_function

begin_function
name|_LIBUNWIND_EXPORT
name|void
name|__register_frame_info_table
parameter_list|(
specifier|const
name|void
modifier|*
name|fde
parameter_list|,
name|void
modifier|*
name|ob
parameter_list|)
block|{
operator|(
name|void
operator|)
name|fde
expr_stmt|;
operator|(
name|void
operator|)
name|ob
expr_stmt|;
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"__register_frame_info_table(%p, %p)"
argument_list|,
name|fde
argument_list|,
name|ob
argument_list|)
expr_stmt|;
comment|// do nothing, this function never worked in Mac OS X
block|}
end_function

begin_function
name|_LIBUNWIND_EXPORT
name|void
name|__register_frame_table
parameter_list|(
specifier|const
name|void
modifier|*
name|fde
parameter_list|)
block|{
operator|(
name|void
operator|)
name|fde
expr_stmt|;
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"__register_frame_table(%p)"
argument_list|,
name|fde
argument_list|)
expr_stmt|;
comment|// do nothing, this function never worked in Mac OS X
block|}
end_function

begin_function
name|_LIBUNWIND_EXPORT
name|void
modifier|*
name|__deregister_frame_info
parameter_list|(
specifier|const
name|void
modifier|*
name|fde
parameter_list|)
block|{
operator|(
name|void
operator|)
name|fde
expr_stmt|;
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"__deregister_frame_info(%p)"
argument_list|,
name|fde
argument_list|)
expr_stmt|;
comment|// do nothing, this function never worked in Mac OS X
return|return
name|NULL
return|;
block|}
end_function

begin_function
name|_LIBUNWIND_EXPORT
name|void
modifier|*
name|__deregister_frame_info_bases
parameter_list|(
specifier|const
name|void
modifier|*
name|fde
parameter_list|)
block|{
operator|(
name|void
operator|)
name|fde
expr_stmt|;
name|_LIBUNWIND_TRACE_API
argument_list|(
literal|"__deregister_frame_info_bases(%p)"
argument_list|,
name|fde
argument_list|)
expr_stmt|;
comment|// do nothing, this function never worked in Mac OS X
return|return
name|NULL
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBUNWIND_SUPPORT_FRAME_APIS
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBUNWIND_SUPPORT_DWARF_UNWIND
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBUNWIND_BUILD_ZERO_COST_APIS
end_comment

end_unit

