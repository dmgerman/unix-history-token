begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CALLB_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CALLB_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"@(#)callb.h	1.29	05/06/23 SMI"
end_pragma

begin_include
include|#
directive|include
file|<sys/kcondvar.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/*  * definitions of callback classes (c_class)  *  * Callbacks belong in the same class if (1) their callback routines  * do the same kind of processing (ideally, using the same callback function)  * and (2) they can/should be executed at the same time in a cpr  * suspend/resume operation.  *  * Note: The DAEMON class, in particular, is for stopping kernel threads  * and nothing else.  The CALLB_* macros below should be used to deal  * with kernel threads, and the callback function should be callb_generic_cpr.  * Another idiosyncrasy of the DAEMON class is that if a suspend operation  * fails, some of the callback functions may be called with the RESUME  * code which were never called with SUSPEND.  Not a problem currently,  * but see bug 4201851.  */
define|#
directive|define
name|CB_CL_CPR_DAEMON
value|0
define|#
directive|define
name|CB_CL_CPR_VM
value|1
define|#
directive|define
name|CB_CL_CPR_CALLOUT
value|2
define|#
directive|define
name|CB_CL_CPR_OBP
value|3
define|#
directive|define
name|CB_CL_CPR_FB
value|4
define|#
directive|define
name|CB_CL_PANIC
value|5
define|#
directive|define
name|CB_CL_CPR_RPC
value|6
define|#
directive|define
name|CB_CL_CPR_PROMPRINTF
value|7
define|#
directive|define
name|CB_CL_UADMIN
value|8
define|#
directive|define
name|CB_CL_CPR_PM
value|9
define|#
directive|define
name|CB_CL_HALT
value|10
define|#
directive|define
name|CB_CL_CPR_DMA
value|11
define|#
directive|define
name|CB_CL_CPR_POST_USER
value|12
define|#
directive|define
name|CB_CL_UADMIN_PRE_VFS
value|13
define|#
directive|define
name|CB_CL_MDBOOT
value|CB_CL_UADMIN
define|#
directive|define
name|CB_CL_ENTER_DEBUGGER
value|14
define|#
directive|define
name|CB_CL_CPR_POST_KERNEL
value|15
define|#
directive|define
name|NCBCLASS
value|16
comment|/* CHANGE ME if classes are added/removed */
comment|/*  * CB_CL_CPR_DAEMON class specific definitions are given below:  */
comment|/*  * code for CPR callb_execute_class  */
define|#
directive|define
name|CB_CODE_CPR_CHKPT
value|0
define|#
directive|define
name|CB_CODE_CPR_RESUME
value|1
typedef|typedef
name|void
modifier|*
name|callb_id_t
typedef|;
comment|/*  * Per kernel thread structure for CPR daemon callbacks.  * Must be protected by either a existing lock in the daemon or  * a new lock created for such a purpose.  */
typedef|typedef
struct|struct
name|callb_cpr
block|{
name|kmutex_t
modifier|*
name|cc_lockp
decl_stmt|;
comment|/* lock to protect this struct */
name|char
name|cc_events
decl_stmt|;
comment|/* various events for CPR */
name|callb_id_t
name|cc_id
decl_stmt|;
comment|/* callb id address */
name|kcondvar_t
name|cc_callb_cv
decl_stmt|;
comment|/* cv for callback waiting */
name|kcondvar_t
name|cc_stop_cv
decl_stmt|;
comment|/* cv to checkpoint block */
block|}
name|callb_cpr_t
typedef|;
comment|/*  * cc_events definitions  */
define|#
directive|define
name|CALLB_CPR_START
value|1
comment|/* a checkpoint request's started */
define|#
directive|define
name|CALLB_CPR_SAFE
value|2
comment|/* thread is safe for CPR */
define|#
directive|define
name|CALLB_CPR_ALWAYS_SAFE
value|4
comment|/* thread is ALWAYS safe for CPR */
comment|/*  * Used when checking that all kernel threads are stopped.  */
define|#
directive|define
name|CALLB_MAX_RETRY
value|3
comment|/* when waiting for kthread to sleep */
define|#
directive|define
name|CALLB_THREAD_DELAY
value|10
comment|/* ticks allowed to reach sleep */
define|#
directive|define
name|CPR_KTHREAD_TIMEOUT_SEC
value|90
comment|/* secs before callback times out -- */
comment|/* due to pwr mgmt of disks, make -- */
comment|/* big enough for worst spinup time */
ifdef|#
directive|ifdef
name|_KERNEL
comment|/*  *  * CALLB_CPR_INIT macro is used by kernel threads to add their entry to  * the callback table and perform other initialization.  It automatically  * adds the thread as being in the callback class CB_CL_CPR_DAEMON.  *  *	cp    - ptr to the callb_cpr_t structure for this kernel thread  *  *	lockp - pointer to mutex protecting the callb_cpr_t stuct  *  *	func  - pointer to the callback function for this kernel thread.  *		It has the prototype boolean_t<func>(void *arg, int code)  *		where: arg	- ptr to the callb_cpr_t structure  *		       code	- not used for this type of callback  *		returns: B_TRUE if successful; B_FALSE if unsuccessful.  *  *	name  - a string giving the name of the kernel thread  *  * Note: lockp is the lock to protect the callb_cpr_t (cp) structure  * later on.  No lock held is needed for this initialization.  */
define|#
directive|define
name|CALLB_CPR_INIT
parameter_list|(
name|cp
parameter_list|,
name|lockp
parameter_list|,
name|func
parameter_list|,
name|name
parameter_list|)
value|{			\ 		strlcpy(curthread->td_name, (name),			\ 		    sizeof(curthread->td_name));			\ 		strlcpy(curthread->td_proc->p_comm, (name),		\ 		    sizeof(curthread->td_proc->p_comm));		\ 		bzero((caddr_t)(cp), sizeof (callb_cpr_t));		\ 		(cp)->cc_lockp = lockp;					\ 		(cp)->cc_id = callb_add(func, (void *)(cp),		\ 			CB_CL_CPR_DAEMON, name);			\ 	}
ifndef|#
directive|ifndef
name|__lock_lint
define|#
directive|define
name|CALLB_CPR_ASSERT
parameter_list|(
name|cp
parameter_list|)
value|ASSERT(MUTEX_HELD((cp)->cc_lockp));
else|#
directive|else
define|#
directive|define
name|CALLB_CPR_ASSERT
parameter_list|(
name|cp
parameter_list|)
endif|#
directive|endif
comment|/*  * Some threads (like the idle threads) do not adhere to the callback  * protocol and are always considered safe.  Such threads must never exit.  * They register their presence by calling this macro during their  * initialization.  *  * Args:  *	t	- thread pointer of the client kernel thread  *	name	- a string giving the name of the kernel thread  */
define|#
directive|define
name|CALLB_CPR_INIT_SAFE
parameter_list|(
name|t
parameter_list|,
name|name
parameter_list|)
value|{					\ 		(void) callb_add_thread(callb_generic_cpr_safe,		\ 		(void *)&callb_cprinfo_safe, CB_CL_CPR_DAEMON,		\ 		    name, t);						\ 	}
comment|/*  * The lock to protect cp's content must be held before  * calling the following two macros.  *  * Any code region between CALLB_CPR_SAFE_BEGIN and CALLB_CPR_SAFE_END  * is safe for checkpoint/resume.  */
define|#
directive|define
name|CALLB_CPR_SAFE_BEGIN
parameter_list|(
name|cp
parameter_list|)
value|{ 			\ 		CALLB_CPR_ASSERT(cp)			\ 		(cp)->cc_events |= CALLB_CPR_SAFE;	\ 		if ((cp)->cc_events& CALLB_CPR_START)	\ 			cv_signal(&(cp)->cc_callb_cv);	\ 	}
define|#
directive|define
name|CALLB_CPR_SAFE_END
parameter_list|(
name|cp
parameter_list|,
name|lockp
parameter_list|)
value|{				\ 		CALLB_CPR_ASSERT(cp)				\ 		while ((cp)->cc_events& CALLB_CPR_START)	\ 			cv_wait(&(cp)->cc_stop_cv, lockp);	\ 		(cp)->cc_events&= ~CALLB_CPR_SAFE;		\ 	}
comment|/*  * cv_destroy is nop right now but may be needed in the future.  */
define|#
directive|define
name|CALLB_CPR_EXIT
parameter_list|(
name|cp
parameter_list|)
value|{				\ 		CALLB_CPR_ASSERT(cp)			\ 		(cp)->cc_events |= CALLB_CPR_SAFE;	\ 		if ((cp)->cc_events& CALLB_CPR_START)	\ 			cv_signal(&(cp)->cc_callb_cv);	\ 		mutex_exit((cp)->cc_lockp);		\ 		(void) callb_delete((cp)->cc_id);	\ 		cv_destroy(&(cp)->cc_callb_cv);		\ 		cv_destroy(&(cp)->cc_stop_cv);		\ 	}
specifier|extern
name|callb_cpr_t
name|callb_cprinfo_safe
decl_stmt|;
specifier|extern
name|callb_id_t
name|callb_add
parameter_list|(
name|boolean_t
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|callb_id_t
name|callb_add_thread
parameter_list|(
name|boolean_t
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|kthread_id_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|callb_delete
parameter_list|(
name|callb_id_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|callb_execute
parameter_list|(
name|callb_id_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|void
modifier|*
name|callb_execute_class
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|boolean_t
name|callb_generic_cpr
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|boolean_t
name|callb_generic_cpr_safe
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|boolean_t
name|callb_is_stopped
parameter_list|(
name|kthread_id_t
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|callb_lock_table
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|callb_unlock_table
parameter_list|(
name|void
parameter_list|)
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_CALLB_H */
end_comment

end_unit

