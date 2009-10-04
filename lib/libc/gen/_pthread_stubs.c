begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Daniel Eischen<deischen@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY DANIEL EISCHEN AND CONTRIBUTORS ``AS IS''  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|"libc_private.h"
end_include

begin_comment
comment|/*  * Weak symbols: All libc internal usage of these functions should  * use the weak symbol versions (_pthread_XXX).  If libpthread is  * linked, it will override these functions with (non-weak) routines.  * The _pthread_XXX functions are provided solely for internal libc  * usage to avoid unwanted cancellation points and to differentiate  * between application locks and libc locks (threads holding the  * latter can't be allowed to exit/terminate).  */
end_comment

begin_comment
comment|/* Define a null pthread structure just to satisfy _pthread_self. */
end_comment

begin_struct
struct|struct
name|pthread
block|{ }
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|pthread
name|main_thread
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|stub_main
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
modifier|*
name|stub_null
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|struct
name|pthread
modifier|*
name|stub_self
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|stub_zero
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|PJT_DUAL_ENTRY
parameter_list|(
name|entry
parameter_list|)
define|\
value|(pthread_func_t)entry, (pthread_func_t)entry
end_define

begin_decl_stmt
name|pthread_func_entry_t
name|__thr_jtable
index|[
name|PJT_MAX
index|]
init|=
block|{
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_COND_BROADCAST */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_COND_DESTROY */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_COND_INIT */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_COND_SIGNAL */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_COND_WAIT */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_null
argument_list|)
block|}
block|,
comment|/* PJT_GETSPECIFIC */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_KEY_CREATE */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_KEY_DELETE */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_main
argument_list|)
block|}
block|,
comment|/* PJT_MAIN_NP */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_MUTEX_DESTROY */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_MUTEX_INIT */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_MUTEX_LOCK */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_MUTEX_TRYLOCK */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_MUTEX_UNLOCK */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_MUTEXATTR_DESTROY */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_MUTEXATTR_INIT */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_MUTEXATTR_SETTYPE */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_ONCE */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_RWLOCK_DESTROY */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_RWLOCK_INIT */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_RWLOCK_RDLOCK */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_RWLOCK_TRYRDLOCK */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_RWLOCK_TRYWRLOCK */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_RWLOCK_UNLOCK */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_RWLOCK_WRLOCK */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_self
argument_list|)
block|}
block|,
comment|/* PJT_SELF */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
block|,
comment|/* PJT_SETSPECIFIC */
block|{
name|PJT_DUAL_ENTRY
argument_list|(
argument|stub_zero
argument_list|)
block|}
comment|/* PJT_SIGMASK */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Weak aliases for exported (pthread_*) and internal (_pthread_*) routines.  */
end_comment

begin_define
define|#
directive|define
name|WEAK_REF
parameter_list|(
name|sym
parameter_list|,
name|alias
parameter_list|)
value|__weak_reference(sym, alias)
end_define

begin_define
define|#
directive|define
name|FUNC_TYPE
parameter_list|(
name|name
parameter_list|)
value|__CONCAT(name, _func_t)
end_define

begin_define
define|#
directive|define
name|FUNC_INT
parameter_list|(
name|name
parameter_list|)
value|__CONCAT(name, _int)
end_define

begin_define
define|#
directive|define
name|FUNC_EXP
parameter_list|(
name|name
parameter_list|)
value|__CONCAT(name, _exp)
end_define

begin_define
define|#
directive|define
name|STUB_FUNC
parameter_list|(
name|name
parameter_list|,
name|idx
parameter_list|,
name|ret
parameter_list|)
define|\
value|static ret FUNC_EXP(name)(void) __used;			\ 	static ret FUNC_INT(name)(void) __used;			\ 	WEAK_REF(FUNC_EXP(name), name);				\ 	WEAK_REF(FUNC_INT(name), __CONCAT(_, name));		\ 	typedef ret (*FUNC_TYPE(name))(void);			\ 	static ret FUNC_EXP(name)(void)				\ 	{							\ 		FUNC_TYPE(name) func;				\ 		func = (FUNC_TYPE(name))__thr_jtable[idx][0];	\ 		return (func());				\ 	}							\ 	static ret FUNC_INT(name)(void)				\ 	{							\ 		FUNC_TYPE(name) func;				\ 		func = (FUNC_TYPE(name))__thr_jtable[idx][1];	\ 		return (func());				\ 	}
end_define

begin_define
define|#
directive|define
name|STUB_FUNC1
parameter_list|(
name|name
parameter_list|,
name|idx
parameter_list|,
name|ret
parameter_list|,
name|p0_type
parameter_list|)
define|\
value|static ret FUNC_EXP(name)(p0_type) __used;		\ 	static ret FUNC_INT(name)(p0_type) __used;		\ 	WEAK_REF(FUNC_EXP(name), name);				\ 	WEAK_REF(FUNC_INT(name), __CONCAT(_, name));		\ 	typedef ret (*FUNC_TYPE(name))(p0_type);		\ 	static ret FUNC_EXP(name)(p0_type p0)			\ 	{							\ 		FUNC_TYPE(name) func;				\ 		func = (FUNC_TYPE(name))__thr_jtable[idx][0];	\ 		return (func(p0));				\ 	}							\ 	static ret FUNC_INT(name)(p0_type p0)			\ 	{							\ 		FUNC_TYPE(name) func;				\ 		func = (FUNC_TYPE(name))__thr_jtable[idx][1];	\ 		return (func(p0));				\ 	}
end_define

begin_define
define|#
directive|define
name|STUB_FUNC2
parameter_list|(
name|name
parameter_list|,
name|idx
parameter_list|,
name|ret
parameter_list|,
name|p0_type
parameter_list|,
name|p1_type
parameter_list|)
define|\
value|static ret FUNC_EXP(name)(p0_type, p1_type) __used;	\ 	static ret FUNC_INT(name)(p0_type, p1_type) __used;	\ 	WEAK_REF(FUNC_EXP(name), name);				\ 	WEAK_REF(FUNC_INT(name), __CONCAT(_, name));		\ 	typedef ret (*FUNC_TYPE(name))(p0_type, p1_type);	\ 	static ret FUNC_EXP(name)(p0_type p0, p1_type p1)	\ 	{							\ 		FUNC_TYPE(name) func;				\ 		func = (FUNC_TYPE(name))__thr_jtable[idx][0];	\ 		return (func(p0, p1));				\ 	}							\ 	static ret FUNC_INT(name)(p0_type p0, p1_type p1)	\ 	{							\ 		FUNC_TYPE(name) func;				\ 		func = (FUNC_TYPE(name))__thr_jtable[idx][1];	\ 		return (func(p0, p1));				\ 	}
end_define

begin_define
define|#
directive|define
name|STUB_FUNC3
parameter_list|(
name|name
parameter_list|,
name|idx
parameter_list|,
name|ret
parameter_list|,
name|p0_type
parameter_list|,
name|p1_type
parameter_list|,
name|p2_type
parameter_list|)
define|\
value|static ret FUNC_EXP(name)(p0_type, p1_type, p2_type) __used; \ 	static ret FUNC_INT(name)(p0_type, p1_type, p2_type) __used; \ 	WEAK_REF(FUNC_EXP(name), name);				\ 	WEAK_REF(FUNC_INT(name), __CONCAT(_, name));		\ 	typedef ret (*FUNC_TYPE(name))(p0_type, p1_type, p2_type); \ 	static ret FUNC_EXP(name)(p0_type p0, p1_type p1, p2_type p2) \ 	{							\ 		FUNC_TYPE(name) func;				\ 		func = (FUNC_TYPE(name))__thr_jtable[idx][0];	\ 		return (func(p0, p1, p2));			\ 	}							\ 	static ret FUNC_INT(name)(p0_type p0, p1_type p1, p2_type p2) \ 	{							\ 		FUNC_TYPE(name) func;				\ 		func = (FUNC_TYPE(name))__thr_jtable[idx][1];	\ 		return (func(p0, p1, p2));			\ 	}
end_define

begin_macro
name|STUB_FUNC1
argument_list|(
argument|pthread_cond_broadcast
argument_list|,
argument|PJT_COND_BROADCAST
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|STUB_FUNC1
argument_list|(
argument|pthread_cond_destroy
argument_list|,
argument|PJT_COND_DESTROY
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|STUB_FUNC2
argument_list|(
argument|pthread_cond_init
argument_list|,
argument|PJT_COND_INIT
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|STUB_FUNC1
argument_list|(
argument|pthread_cond_signal
argument_list|,
argument|PJT_COND_SIGNAL
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|STUB_FUNC2
argument_list|(
argument|pthread_cond_wait
argument_list|,
argument|PJT_COND_WAIT
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|STUB_FUNC1
argument_list|(
argument|pthread_getspecific
argument_list|,
argument|PJT_GETSPECIFIC
argument_list|,
argument|void *
argument_list|,
argument|pthread_key_t
argument_list|)
end_macro

begin_macro
name|STUB_FUNC2
argument_list|(
argument|pthread_key_create
argument_list|,
argument|PJT_KEY_CREATE
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|STUB_FUNC1
argument_list|(
argument|pthread_key_delete
argument_list|,
argument|PJT_KEY_DELETE
argument_list|,
argument|int
argument_list|,
argument|pthread_key_t
argument_list|)
end_macro

begin_macro
name|STUB_FUNC
argument_list|(
argument|pthread_main_np
argument_list|,
argument|PJT_MAIN_NP
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|STUB_FUNC1
argument_list|(
argument|pthread_mutex_destroy
argument_list|,
argument|PJT_MUTEX_DESTROY
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|STUB_FUNC2
argument_list|(
argument|pthread_mutex_init
argument_list|,
argument|PJT_MUTEX_INIT
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|STUB_FUNC1
argument_list|(
argument|pthread_mutex_lock
argument_list|,
argument|PJT_MUTEX_LOCK
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|STUB_FUNC1
argument_list|(
argument|pthread_mutex_trylock
argument_list|,
argument|PJT_MUTEX_TRYLOCK
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|STUB_FUNC1
argument_list|(
argument|pthread_mutex_unlock
argument_list|,
argument|PJT_MUTEX_UNLOCK
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|STUB_FUNC1
argument_list|(
argument|pthread_mutexattr_destroy
argument_list|,
argument|PJT_MUTEXATTR_DESTROY
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|STUB_FUNC1
argument_list|(
argument|pthread_mutexattr_init
argument_list|,
argument|PJT_MUTEXATTR_INIT
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|STUB_FUNC2
argument_list|(
argument|pthread_mutexattr_settype
argument_list|,
argument|PJT_MUTEXATTR_SETTYPE
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|STUB_FUNC2
argument_list|(
argument|pthread_once
argument_list|,
argument|PJT_ONCE
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|STUB_FUNC1
argument_list|(
argument|pthread_rwlock_destroy
argument_list|,
argument|PJT_RWLOCK_DESTROY
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|STUB_FUNC2
argument_list|(
argument|pthread_rwlock_init
argument_list|,
argument|PJT_RWLOCK_INIT
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|STUB_FUNC1
argument_list|(
argument|pthread_rwlock_rdlock
argument_list|,
argument|PJT_RWLOCK_RDLOCK
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|STUB_FUNC1
argument_list|(
argument|pthread_rwlock_tryrdlock
argument_list|,
argument|PJT_RWLOCK_TRYRDLOCK
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|STUB_FUNC1
argument_list|(
argument|pthread_rwlock_trywrlock
argument_list|,
argument|PJT_RWLOCK_TRYWRLOCK
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|STUB_FUNC1
argument_list|(
argument|pthread_rwlock_unlock
argument_list|,
argument|PJT_RWLOCK_UNLOCK
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|STUB_FUNC1
argument_list|(
argument|pthread_rwlock_wrlock
argument_list|,
argument|PJT_RWLOCK_WRLOCK
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|STUB_FUNC
argument_list|(
argument|pthread_self
argument_list|,
argument|PJT_SELF
argument_list|,
argument|pthread_t
argument_list|)
end_macro

begin_macro
name|STUB_FUNC2
argument_list|(
argument|pthread_setspecific
argument_list|,
argument|PJT_SETSPECIFIC
argument_list|,
argument|int
argument_list|,
argument|pthread_key_t
argument_list|,
argument|void *
argument_list|)
end_macro

begin_macro
name|STUB_FUNC3
argument_list|(
argument|pthread_sigmask
argument_list|,
argument|PJT_SIGMASK
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|,
argument|void *
argument_list|)
end_macro

begin_function
specifier|static
name|int
name|stub_zero
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
modifier|*
name|stub_null
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|struct
name|pthread
modifier|*
name|stub_self
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|&
name|main_thread
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|stub_main
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

end_unit

