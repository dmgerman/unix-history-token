begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_THREAD_H
end_ifndef

begin_define
define|#
directive|define
name|_THREAD_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_comment
comment|/*  * Compatibility thread stuff needed for Solaris -> Linux port  */
end_comment

begin_typedef
typedef|typedef
name|pthread_t
name|thread_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|pthread_mutex_t
name|mutex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|pthread_cond_t
name|cond_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|pthread_rwlock_t
name|rwlock_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|USYNC_THREAD
value|0
end_define

begin_define
define|#
directive|define
name|thr_self
parameter_list|()
value|(unsigned long)pthread_self()
end_define

begin_define
define|#
directive|define
name|thr_equal
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|pthread_equal(a,b)
end_define

begin_define
define|#
directive|define
name|thr_join
parameter_list|(
name|t
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|pthread_join(t,s)
end_define

begin_define
define|#
directive|define
name|thr_exit
parameter_list|(
name|r
parameter_list|)
value|pthread_exit(r)
end_define

begin_define
define|#
directive|define
name|_mutex_init
parameter_list|(
name|l
parameter_list|,
name|f
parameter_list|,
name|a
parameter_list|)
value|pthread_mutex_init(l,NULL)
end_define

begin_define
define|#
directive|define
name|_mutex_destroy
parameter_list|(
name|l
parameter_list|)
value|pthread_mutex_destroy(l)
end_define

begin_define
define|#
directive|define
name|mutex_lock
parameter_list|(
name|l
parameter_list|)
value|pthread_mutex_lock(l)
end_define

begin_define
define|#
directive|define
name|mutex_trylock
parameter_list|(
name|l
parameter_list|)
value|pthread_mutex_trylock(l)
end_define

begin_define
define|#
directive|define
name|mutex_unlock
parameter_list|(
name|l
parameter_list|)
value|pthread_mutex_unlock(l)
end_define

begin_define
define|#
directive|define
name|rwlock_init
parameter_list|(
name|l
parameter_list|,
name|f
parameter_list|,
name|a
parameter_list|)
value|pthread_rwlock_init(l,NULL)
end_define

begin_define
define|#
directive|define
name|rwlock_destroy
parameter_list|(
name|l
parameter_list|)
value|pthread_rwlock_destroy(l)
end_define

begin_define
define|#
directive|define
name|rw_rdlock
parameter_list|(
name|l
parameter_list|)
value|pthread_rwlock_rdlock(l)
end_define

begin_define
define|#
directive|define
name|rw_wrlock
parameter_list|(
name|l
parameter_list|)
value|pthread_rwlock_wrlock(l)
end_define

begin_define
define|#
directive|define
name|rw_tryrdlock
parameter_list|(
name|l
parameter_list|)
value|pthread_rwlock_tryrdlock(l)
end_define

begin_define
define|#
directive|define
name|rw_trywrlock
parameter_list|(
name|l
parameter_list|)
value|pthread_rwlock_trywrlock(l)
end_define

begin_define
define|#
directive|define
name|rw_unlock
parameter_list|(
name|l
parameter_list|)
value|pthread_rwlock_unlock(l)
end_define

begin_define
define|#
directive|define
name|cond_init
parameter_list|(
name|l
parameter_list|,
name|f
parameter_list|,
name|a
parameter_list|)
value|pthread_cond_init(l,NULL)
end_define

begin_define
define|#
directive|define
name|cond_destroy
parameter_list|(
name|l
parameter_list|)
value|pthread_cond_destroy(l)
end_define

begin_define
define|#
directive|define
name|cond_wait
parameter_list|(
name|l
parameter_list|,
name|m
parameter_list|)
value|pthread_cond_wait(l,m)
end_define

begin_define
define|#
directive|define
name|cond_signal
parameter_list|(
name|l
parameter_list|)
value|pthread_cond_signal(l)
end_define

begin_define
define|#
directive|define
name|cond_broadcast
parameter_list|(
name|l
parameter_list|)
value|pthread_cond_broadcast(l)
end_define

begin_define
define|#
directive|define
name|THR_BOUND
value|0x00000001
end_define

begin_comment
comment|/* = PTHREAD_SCOPE_SYSTEM */
end_comment

begin_define
define|#
directive|define
name|THR_NEW_LWP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|THR_DETACHED
value|0x00000040
end_define

begin_comment
comment|/* = PTHREAD_CREATE_DETACHED */
end_comment

begin_define
define|#
directive|define
name|THR_SUSPENDED
value|0x00000080
end_define

begin_define
define|#
directive|define
name|THR_DAEMON
value|0x00000100
end_define

begin_function
specifier|static
name|__inline
name|int
name|thr_create
parameter_list|(
name|void
modifier|*
name|stack_base
parameter_list|,
name|size_t
name|stack_size
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
name|start_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|long
name|flags
parameter_list|,
name|thread_t
modifier|*
name|new_thread_ID
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
name|assert
argument_list|(
name|stack_base
operator|==
name|NULL
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|stack_size
operator|==
literal|0
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|flags
operator|&
operator|~
name|THR_BOUND
operator|&
operator|~
name|THR_DETACHED
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
name|pthread_attr_t
name|attr
decl_stmt|;
name|pthread_attr_init
argument_list|(
operator|&
name|attr
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|THR_DETACHED
condition|)
name|pthread_attr_setdetachstate
argument_list|(
operator|&
name|attr
argument_list|,
name|PTHREAD_CREATE_DETACHED
argument_list|)
expr_stmt|;
comment|/* This function ignores the THR_BOUND flag, since NPTL doesn't seem to support PTHREAD_SCOPE_PROCESS */
name|ret
operator|=
name|pthread_create
argument_list|(
name|new_thread_ID
argument_list|,
operator|&
name|attr
argument_list|,
name|start_func
argument_list|,
name|arg
argument_list|)
expr_stmt|;
name|pthread_attr_destroy
argument_list|(
operator|&
name|attr
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _THREAD_H */
end_comment

end_unit

