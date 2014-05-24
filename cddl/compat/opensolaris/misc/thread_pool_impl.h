begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_THREAD_POOL_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|_THREAD_POOL_IMPL_H
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
file|<thread_pool.h>
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
comment|/*  * Thread pool implementation definitions.  * See<thread_pool.h> for interface declarations.  */
comment|/*  * FIFO queued job  */
typedef|typedef
name|struct
name|tpool_job
name|tpool_job_t
typedef|;
struct|struct
name|tpool_job
block|{
name|tpool_job_t
modifier|*
name|tpj_next
decl_stmt|;
comment|/* list of jobs */
name|void
function_decl|(
modifier|*
name|tpj_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* function to call */
name|void
modifier|*
name|tpj_arg
decl_stmt|;
comment|/* its argument */
block|}
struct|;
comment|/*  * List of active threads, linked through their stacks.  */
typedef|typedef
name|struct
name|tpool_active
name|tpool_active_t
typedef|;
struct|struct
name|tpool_active
block|{
name|tpool_active_t
modifier|*
name|tpa_next
decl_stmt|;
comment|/* list of active threads */
name|pthread_t
name|tpa_tid
decl_stmt|;
comment|/* active thread id */
block|}
struct|;
comment|/*  * The thread pool.  */
struct|struct
name|tpool
block|{
name|tpool_t
modifier|*
name|tp_forw
decl_stmt|;
comment|/* circular list of all thread pools */
name|tpool_t
modifier|*
name|tp_back
decl_stmt|;
name|mutex_t
name|tp_mutex
decl_stmt|;
comment|/* protects the pool data */
name|cond_t
name|tp_busycv
decl_stmt|;
comment|/* synchronization in tpool_dispatch */
name|cond_t
name|tp_workcv
decl_stmt|;
comment|/* synchronization with workers */
name|cond_t
name|tp_waitcv
decl_stmt|;
comment|/* synchronization in tpool_wait() */
name|tpool_active_t
modifier|*
name|tp_active
decl_stmt|;
comment|/* threads performing work */
name|tpool_job_t
modifier|*
name|tp_head
decl_stmt|;
comment|/* FIFO job queue */
name|tpool_job_t
modifier|*
name|tp_tail
decl_stmt|;
name|pthread_attr_t
name|tp_attr
decl_stmt|;
comment|/* attributes of the workers */
name|int
name|tp_flags
decl_stmt|;
comment|/* see below */
name|uint_t
name|tp_linger
decl_stmt|;
comment|/* seconds before idle workers exit */
name|int
name|tp_njobs
decl_stmt|;
comment|/* number of jobs in job queue */
name|int
name|tp_minimum
decl_stmt|;
comment|/* minimum number of worker threads */
name|int
name|tp_maximum
decl_stmt|;
comment|/* maximum number of worker threads */
name|int
name|tp_current
decl_stmt|;
comment|/* current number of worker threads */
name|int
name|tp_idle
decl_stmt|;
comment|/* number of idle workers */
block|}
struct|;
comment|/* tp_flags */
define|#
directive|define
name|TP_WAIT
value|0x01
comment|/* waiting in tpool_wait() */
define|#
directive|define
name|TP_SUSPEND
value|0x02
comment|/* pool is being suspended */
define|#
directive|define
name|TP_DESTROY
value|0x04
comment|/* pool is being destroyed */
define|#
directive|define
name|TP_ABANDON
value|0x08
comment|/* pool is abandoned (auto-destroy) */
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
comment|/* _THREAD_POOL_IMPL_H */
end_comment

end_unit

