begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2003 David Xu<davidxu@freebsd.org>  * Copyright (c) 2001 Daniel Eischen<deischen@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Neither the name of the author nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Machine-dependent thread prototypes/definitions for the thread kernel.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PTHREAD_MD_H_
end_ifndef

begin_define
define|#
directive|define
name|_PTHREAD_MD_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/kse.h>
end_include

begin_include
include|#
directive|include
file|<machine/sysarch.h>
end_include

begin_include
include|#
directive|include
file|<ucontext.h>
end_include

begin_comment
comment|/*<machine/sysarch.h> should define this, but doesn't. */
end_comment

begin_function_decl
specifier|extern
name|int
name|sysarch
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|THR_GETCONTEXT
parameter_list|(
name|ucp
parameter_list|)
define|\
value|(void)_amd64_save_context(&(ucp)->uc_mcontext)
end_define

begin_define
define|#
directive|define
name|THR_SETCONTEXT
parameter_list|(
name|ucp
parameter_list|)
define|\
value|(void)_amd64_restore_context(&(ucp)->uc_mcontext, 0, NULL)
end_define

begin_define
define|#
directive|define
name|PER_KSE
end_define

begin_undef
undef|#
directive|undef
name|PER_THREAD
end_undef

begin_struct_decl
struct_decl|struct
name|kse
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pthread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tdv
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * %fs points to a struct kcb.  */
end_comment

begin_struct
struct|struct
name|kcb
block|{
name|struct
name|tcb
modifier|*
name|kcb_curtcb
decl_stmt|;
name|struct
name|kcb
modifier|*
name|kcb_self
decl_stmt|;
comment|/* self reference */
name|struct
name|kse
modifier|*
name|kcb_kse
decl_stmt|;
name|struct
name|kse_mailbox
name|kcb_kmbx
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tcb
block|{
name|struct
name|tdv
modifier|*
name|tcb_tdv
decl_stmt|;
name|struct
name|pthread
modifier|*
name|tcb_thread
decl_stmt|;
name|void
modifier|*
name|tcb_spare
index|[
literal|2
index|]
decl_stmt|;
comment|/* align tcb_tmbx to 16 bytes */
name|struct
name|kse_thr_mailbox
name|tcb_tmbx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Evaluates to the byte offset of the per-kse variable name.  */
end_comment

begin_define
define|#
directive|define
name|__kcb_offset
parameter_list|(
name|name
parameter_list|)
value|__offsetof(struct kcb, name)
end_define

begin_comment
comment|/*  * Evaluates to the type of the per-kse variable name.  */
end_comment

begin_define
define|#
directive|define
name|__kcb_type
parameter_list|(
name|name
parameter_list|)
value|__typeof(((struct kcb *)0)->name)
end_define

begin_comment
comment|/*  * Evaluates to the value of the per-kse variable name.  */
end_comment

begin_define
define|#
directive|define
name|KCB_GET64
parameter_list|(
name|name
parameter_list|)
value|({					\ 	__kcb_type(name) __result;				\ 								\ 	u_long __i;						\ 	__asm __volatile("movq %%fs:%1, %0"			\ 	    : "=r" (__i)					\ 	    : "m" (*(u_long *)(__kcb_offset(name))));		\ 	__result = *(__kcb_type(name) *)&__i;			\ 								\ 	__result;						\ })
end_define

begin_comment
comment|/*  * Sets the value of the per-kse variable name to value val.  */
end_comment

begin_define
define|#
directive|define
name|KCB_SET64
parameter_list|(
name|name
parameter_list|,
name|val
parameter_list|)
value|({					\ 	__kcb_type(name) __val = (val);				\ 								\ 	u_long __i;						\ 	__i = *(u_long *)&__val;				\ 	__asm __volatile("movq %1,%%fs:%0"			\ 	    : "=m" (*(u_long *)(__kcb_offset(name)))		\ 	    : "r" (__i));					\ })
end_define

begin_function
specifier|static
name|__inline
name|u_long
name|__kcb_readandclear64
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|addr
parameter_list|)
block|{
name|u_long
name|result
decl_stmt|;
asm|__asm __volatile (
literal|"	xorq	%0, %0;"
literal|"	xchgq	%%fs:%1, %0;"
literal|"# __kcb_readandclear64"
operator|:
literal|"=&r"
operator|(
name|result
operator|)
operator|:
literal|"m"
operator|(
operator|*
name|addr
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|result
operator|)
return|;
end_return

begin_define
unit|}
define|#
directive|define
name|KCB_READANDCLEAR64
parameter_list|(
name|name
parameter_list|)
value|({				\ 	__kcb_type(name) __result;				\ 								\ 	__result = (__kcb_type(name))				\ 	    __kcb_readandclear64((u_long *)__kcb_offset(name)); \ 	__result;						\ })
end_define

begin_define
define|#
directive|define
name|_kcb_curkcb
parameter_list|()
value|KCB_GET64(kcb_self)
end_define

begin_define
define|#
directive|define
name|_kcb_curtcb
parameter_list|()
value|KCB_GET64(kcb_curtcb)
end_define

begin_define
define|#
directive|define
name|_kcb_curkse
parameter_list|()
value|((struct kse *)KCB_GET64(kcb_kmbx.km_udata))
end_define

begin_define
define|#
directive|define
name|_kcb_get_tmbx
parameter_list|()
value|KCB_GET64(kcb_kmbx.km_curthread)
end_define

begin_define
define|#
directive|define
name|_kcb_set_tmbx
parameter_list|(
name|value
parameter_list|)
value|KCB_SET64(kcb_kmbx.km_curthread, (void *)value)
end_define

begin_define
define|#
directive|define
name|_kcb_readandclear_tmbx
parameter_list|()
value|KCB_READANDCLEAR64(kcb_kmbx.km_curthread)
end_define

begin_comment
comment|/*  * The constructors.  */
end_comment

begin_function_decl
unit|struct
name|tcb
modifier|*
name|_tcb_ctor
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_tcb_dtor
parameter_list|(
name|struct
name|tcb
modifier|*
name|tcb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|kcb
modifier|*
name|_kcb_ctor
parameter_list|(
name|struct
name|kse
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_kcb_dtor
parameter_list|(
name|struct
name|kcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Called from the KSE to set its private data. */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|_kcb_set
parameter_list|(
name|struct
name|kcb
modifier|*
name|kcb
parameter_list|)
block|{
name|void
modifier|*
name|addr
init|=
name|kcb
decl_stmt|;
name|sysarch
argument_list|(
name|AMD64_SET_FSBASE
argument_list|,
operator|&
name|addr
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Get the current kcb. */
end_comment

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|kcb
operator|*
name|_kcb_get
argument_list|(
argument|void
argument_list|)
block|{
return|return
operator|(
name|_kcb_curkcb
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|kse_thr_mailbox
operator|*
name|_kcb_critical_enter
argument_list|(
argument|void
argument_list|)
block|{ 	struct
name|kse_thr_mailbox
operator|*
name|crit
block|;
name|crit
operator|=
name|_kcb_readandclear_tmbx
argument_list|()
block|;
return|return
operator|(
name|crit
operator|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|__inline
name|void
name|_kcb_critical_leave
parameter_list|(
name|struct
name|kse_thr_mailbox
modifier|*
name|crit
parameter_list|)
block|{
name|_kcb_set_tmbx
argument_list|(
name|crit
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|_kcb_in_critical
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|_kcb_get_tmbx
argument_list|()
operator|==
name|NULL
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|_tcb_set
parameter_list|(
name|struct
name|kcb
modifier|*
name|kcb
parameter_list|,
name|struct
name|tcb
modifier|*
name|tcb
parameter_list|)
block|{
name|kcb
operator|->
name|kcb_curtcb
operator|=
name|tcb
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|tcb
operator|*
name|_tcb_get
argument_list|(
argument|void
argument_list|)
block|{
return|return
operator|(
name|_kcb_curtcb
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|pthread
operator|*
name|_get_curthread
argument_list|(
argument|void
argument_list|)
block|{ 	struct
name|tcb
operator|*
name|tcb
block|;
name|tcb
operator|=
name|_kcb_curtcb
argument_list|()
block|;
if|if
condition|(
name|tcb
operator|!=
name|NULL
condition|)
return|return
operator|(
name|tcb
operator|->
name|tcb_thread
operator|)
return|;
else|else
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|kse
operator|*
name|_get_curkse
argument_list|(
argument|void
argument_list|)
block|{
return|return
operator|(
operator|(
expr|struct
name|kse
operator|*
operator|)
name|_kcb_curkse
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|_amd64_enter_uts
parameter_list|(
name|struct
name|kse_mailbox
modifier|*
name|km
parameter_list|,
name|kse_func_t
name|uts
parameter_list|,
name|void
modifier|*
name|stack
parameter_list|,
name|size_t
name|stacksz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_amd64_restore_context
parameter_list|(
name|mcontext_t
modifier|*
name|mc
parameter_list|,
name|intptr_t
name|val
parameter_list|,
name|intptr_t
modifier|*
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_amd64_save_context
parameter_list|(
name|mcontext_t
modifier|*
name|mc
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|int
name|_thread_enter_uts
parameter_list|(
name|struct
name|tcb
modifier|*
name|tcb
parameter_list|,
name|struct
name|kcb
modifier|*
name|kcb
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
name|ret
operator|=
name|_amd64_save_context
argument_list|(
operator|&
name|tcb
operator|->
name|tcb_tmbx
operator|.
name|tm_context
operator|.
name|uc_mcontext
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|==
literal|0
condition|)
block|{
name|_amd64_enter_uts
argument_list|(
operator|&
name|kcb
operator|->
name|kcb_kmbx
argument_list|,
name|kcb
operator|->
name|kcb_kmbx
operator|.
name|km_func
argument_list|,
name|kcb
operator|->
name|kcb_kmbx
operator|.
name|km_stack
operator|.
name|ss_sp
argument_list|,
name|kcb
operator|->
name|kcb_kmbx
operator|.
name|km_stack
operator|.
name|ss_size
argument_list|)
expr_stmt|;
comment|/* We should not reach here. */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|ret
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|_thread_switch
parameter_list|(
name|struct
name|kcb
modifier|*
name|kcb
parameter_list|,
name|struct
name|tcb
modifier|*
name|tcb
parameter_list|,
name|int
name|setmbox
parameter_list|)
block|{
if|if
condition|(
operator|(
name|kcb
operator|==
name|NULL
operator|)
operator|||
operator|(
name|tcb
operator|==
name|NULL
operator|)
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|kcb
operator|->
name|kcb_curtcb
operator|=
name|tcb
expr_stmt|;
if|if
condition|(
name|setmbox
operator|!=
literal|0
condition|)
name|_amd64_restore_context
argument_list|(
operator|&
name|tcb
operator|->
name|tcb_tmbx
operator|.
name|tm_context
operator|.
name|uc_mcontext
argument_list|,
operator|(
name|intptr_t
operator|)
operator|&
name|tcb
operator|->
name|tcb_tmbx
argument_list|,
operator|(
name|intptr_t
operator|*
operator|)
operator|&
name|kcb
operator|->
name|kcb_kmbx
operator|.
name|km_curthread
argument_list|)
expr_stmt|;
else|else
name|_amd64_restore_context
argument_list|(
operator|&
name|tcb
operator|->
name|tcb_tmbx
operator|.
name|tm_context
operator|.
name|uc_mcontext
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|/* We should not reach here. */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

