begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_threadstuff.h,v 1.10 2001/01/27 20:42:21 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland, Daniel Stodolsky, Jim Zelenka  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * threadstuff.h -- definitions for threads, locks, and synchronization  *  * The purpose of this file is provide some illusion of portability.  * If the functions below can be implemented with the same semantics on  * some new system, then at least the synchronization and thread control  * part of the code should not require modification to port to a new machine.  * the only other place where the pthread package is explicitly used is  * threadid.h  *  * this file should be included above stdio.h to get some necessary defines.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_THREADSTUFF_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_THREADSTUFF_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kthread.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|rf_create_managed_mutex
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|_rf_create_managed_mutex(a,b,__FILE__,__LINE__)
end_define

begin_define
define|#
directive|define
name|rf_create_managed_cond
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|_rf_create_managed_cond(a,b,__FILE__,__LINE__)
end_define

begin_define
define|#
directive|define
name|rf_init_managed_threadgroup
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|_rf_init_managed_threadgroup(a,b,__FILE__,__LINE__)
end_define

begin_define
define|#
directive|define
name|rf_init_threadgroup
parameter_list|(
name|a
parameter_list|)
value|_rf_init_threadgroup(a,__FILE__,__LINE__)
end_define

begin_define
define|#
directive|define
name|rf_destroy_threadgroup
parameter_list|(
name|a
parameter_list|)
value|_rf_destroy_threadgroup(a,__FILE__,__LINE__)
end_define

begin_function_decl
name|int
name|_rf_init_threadgroup
parameter_list|(
name|RF_ThreadGroup_t
modifier|*
name|g
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_rf_destroy_threadgroup
parameter_list|(
name|RF_ThreadGroup_t
modifier|*
name|g
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_rf_init_managed_threadgroup
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|,
name|RF_ThreadGroup_t
modifier|*
name|g
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|__FreeBSD_version
operator|>
literal|500005
end_if

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_define
define|#
directive|define
name|decl_simple_lock_data
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a struct mtx b;
end_define

begin_define
define|#
directive|define
name|simple_lock_addr
parameter_list|(
name|a
parameter_list|)
value|((struct mtx *)&(a))
end_define

begin_typedef
typedef|typedef
name|struct
name|thread
modifier|*
name|RF_Thread_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|RF_ThreadArg_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|ucred
operator|*
name|rf_getucred
argument_list|(
argument|RF_Thread_t td
argument_list|)
block|{
return|return
operator|(
operator|(
operator|(
expr|struct
name|thread
operator|*
operator|)
name|td
operator|)
operator|->
name|td_proc
operator|->
name|p_ucred
operator|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RF_LOCK_MUTEX
parameter_list|(
name|_m_
parameter_list|)
value|mtx_lock(&(_m_))
end_define

begin_define
define|#
directive|define
name|RF_UNLOCK_MUTEX
parameter_list|(
name|_m_
parameter_list|)
value|mtx_unlock(&(_m_))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|decl_simple_lock_data
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a struct simplelock b;
end_define

begin_define
define|#
directive|define
name|simple_lock_addr
parameter_list|(
name|a
parameter_list|)
value|((struct simplelock *)&(a))
end_define

begin_typedef
typedef|typedef
name|struct
name|proc
modifier|*
name|RF_Thread_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|RF_ThreadArg_t
typedef|;
end_typedef

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|ucred
operator|*
name|rf_getucred
argument_list|(
argument|RF_Thread_t td
argument_list|)
block|{
return|return
operator|(
operator|(
operator|(
expr|struct
name|proc
operator|*
operator|)
name|td
operator|)
operator|->
name|p_ucred
operator|)
return|;
block|}
end_expr_stmt

begin_define
define|#
directive|define
name|RF_LOCK_MUTEX
parameter_list|(
name|_m_
parameter_list|)
value|simple_lock(&(_m_))
end_define

begin_define
define|#
directive|define
name|RF_UNLOCK_MUTEX
parameter_list|(
name|_m_
parameter_list|)
value|simple_unlock(&(_m_))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RF_DECLARE_MUTEX
parameter_list|(
name|_m_
parameter_list|)
value|decl_simple_lock_data(,(_m_))
end_define

begin_define
define|#
directive|define
name|RF_DECLARE_STATIC_MUTEX
parameter_list|(
name|_m_
parameter_list|)
value|decl_simple_lock_data(static,(_m_))
end_define

begin_define
define|#
directive|define
name|RF_DECLARE_EXTERN_MUTEX
parameter_list|(
name|_m_
parameter_list|)
value|decl_simple_lock_data(extern,(_m_))
end_define

begin_define
define|#
directive|define
name|RF_DECLARE_COND
parameter_list|(
name|_c_
parameter_list|)
value|int _c_;
end_define

begin_define
define|#
directive|define
name|RF_DECLARE_STATIC_COND
parameter_list|(
name|_c_
parameter_list|)
value|static int _c_;
end_define

begin_define
define|#
directive|define
name|RF_DECLARE_EXTERN_COND
parameter_list|(
name|_c_
parameter_list|)
value|extern int _c_;
end_define

begin_comment
comment|/*  * In NetBSD, kernel threads are simply processes which share several  * substructures and never run in userspace.  */
end_comment

begin_define
define|#
directive|define
name|RF_WAIT_COND
parameter_list|(
name|_c_
parameter_list|,
name|_m_
parameter_list|)
define|\
value|RF_LTSLEEP(&(_c_), PRIBIO, "rfwcond", 0,&(_m_))
end_define

begin_define
define|#
directive|define
name|RF_SIGNAL_COND
parameter_list|(
name|_c_
parameter_list|)
value|wakeup_one(&(_c_))
end_define

begin_define
define|#
directive|define
name|RF_BROADCAST_COND
parameter_list|(
name|_c_
parameter_list|)
value|wakeup(&(_c_))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|RF_CREATE_THREAD
parameter_list|(
name|_handle_
parameter_list|,
name|_func_
parameter_list|,
name|_arg_
parameter_list|,
name|_name_
parameter_list|)
define|\
value|kthread_create1((void (*)(void *))(_func_), (void *)(_arg_), \ 	    (struct proc **)&(_handle_), _name_)
end_define

begin_define
define|#
directive|define
name|RF_THREAD_EXIT
parameter_list|(
name|ret
parameter_list|)
define|\
value|kthread_exit(ret)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>
literal|500005
end_if

begin_define
define|#
directive|define
name|RF_CREATE_THREAD
parameter_list|(
name|_handle_
parameter_list|,
name|_func_
parameter_list|,
name|_arg_
parameter_list|,
name|_name_
parameter_list|)
define|\
value|kthread_create((void (*)(void *))(_func_), (void *)(_arg_), \ 	    (struct proc **)&(_handle_), 0, 4, _name_)
end_define

begin_define
define|#
directive|define
name|RF_THREAD_EXIT
parameter_list|(
name|ret
parameter_list|)
define|\
value|kthread_exit(ret)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RF_CREATE_THREAD
parameter_list|(
name|_handle_
parameter_list|,
name|_func_
parameter_list|,
name|_arg_
parameter_list|,
name|_name_
parameter_list|)
define|\
value|kthread_create((void (*)(void *))(_func_), (void *)(_arg_), \ 	    (struct proc **)&(_handle_), _name_)
end_define

begin_define
define|#
directive|define
name|RF_THREAD_EXIT
parameter_list|(
name|ret
parameter_list|)
define|\
value|kthread_exit(ret);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|RF_ThreadGroup_s
block|{
name|int
name|created
decl_stmt|;
name|int
name|running
decl_stmt|;
name|int
name|shutdown
decl_stmt|;
name|RF_DECLARE_MUTEX
argument_list|(
argument|mutex
argument_list|)
name|RF_DECLARE_COND
argument_list|(
argument|cond
argument_list|)
block|}
struct|;
end_struct

begin_comment
comment|/*  * Someone has started a thread in the group  */
end_comment

begin_define
define|#
directive|define
name|RF_THREADGROUP_STARTED
parameter_list|(
name|_g_
parameter_list|)
value|{ \ 	RF_LOCK_MUTEX((_g_)->mutex); \ 	(_g_)->created++; \ 	RF_UNLOCK_MUTEX((_g_)->mutex); \ }
end_define

begin_comment
comment|/*  * Thread announcing that it is now running  */
end_comment

begin_define
define|#
directive|define
name|RF_THREADGROUP_RUNNING
parameter_list|(
name|_g_
parameter_list|)
value|{ \ 	RF_LOCK_MUTEX((_g_)->mutex); \ 	(_g_)->running++; \ 	RF_UNLOCK_MUTEX((_g_)->mutex); \ 	RF_SIGNAL_COND((_g_)->cond); \ }
end_define

begin_comment
comment|/*  * Thread announcing that it is now done  */
end_comment

begin_define
define|#
directive|define
name|RF_THREADGROUP_DONE
parameter_list|(
name|_g_
parameter_list|)
value|{ \ 	RF_LOCK_MUTEX((_g_)->mutex); \ 	(_g_)->shutdown++; \ 	RF_UNLOCK_MUTEX((_g_)->mutex); \ 	RF_SIGNAL_COND((_g_)->cond); \ }
end_define

begin_comment
comment|/*  * Wait for all threads to start running  */
end_comment

begin_define
define|#
directive|define
name|RF_THREADGROUP_WAIT_START
parameter_list|(
name|_g_
parameter_list|)
value|{ \ 	RF_LOCK_MUTEX((_g_)->mutex); \ 	while((_g_)->running< (_g_)->created) { \ 		RF_WAIT_COND((_g_)->cond, (_g_)->mutex); \ 	} \ 	RF_UNLOCK_MUTEX((_g_)->mutex); \ }
end_define

begin_comment
comment|/*  * Wait for all threads to stop running  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NetBSD__
end_ifndef

begin_define
define|#
directive|define
name|RF_THREADGROUP_WAIT_STOP
parameter_list|(
name|_g_
parameter_list|)
value|{ \ 	RF_LOCK_MUTEX((_g_)->mutex); \ 	RF_ASSERT((_g_)->running == (_g_)->created); \ 	while((_g_)->shutdown< (_g_)->running) { \ 		RF_WAIT_COND((_g_)->cond, (_g_)->mutex); \ 	} \ 	RF_UNLOCK_MUTEX((_g_)->mutex); \ }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* XXX Note that we've removed the assert.  That should get put back in once   * we actually get something like a kernel thread running */
end_comment

begin_define
define|#
directive|define
name|RF_THREADGROUP_WAIT_STOP
parameter_list|(
name|_g_
parameter_list|)
value|{ \ 	RF_LOCK_MUTEX((_g_)->mutex); \ 	while((_g_)->shutdown< (_g_)->running) { \ 		RF_WAIT_COND((_g_)->cond, (_g_)->mutex); \ 	} \ 	RF_UNLOCK_MUTEX((_g_)->mutex); \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|__FreeBSD_version
operator|>
literal|500005
end_if

begin_function_decl
name|int
name|rf_mutex_init
parameter_list|(
name|struct
name|mtx
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_mutex_destroy
parameter_list|(
name|struct
name|mtx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_rf_create_managed_mutex
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
parameter_list|,
name|struct
name|mtx
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|rf_mutex_init
parameter_list|(
name|struct
name|simplelock
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_mutex_destroy
parameter_list|(
name|struct
name|simplelock
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_rf_create_managed_mutex
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
parameter_list|,
name|struct
name|simplelock
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|_rf_create_managed_cond
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|,
name|int
modifier|*
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_cond_init
parameter_list|(
name|int
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_cond_destroy
parameter_list|(
name|int
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_THREADSTUFF_H_ */
end_comment

end_unit

