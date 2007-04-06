begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TASKQ_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TASKQ_IMPL_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"@(#)taskq_impl.h	1.6	05/06/08 SMI"
end_pragma

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/rwlock.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskq.h>
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
typedef|typedef
name|struct
name|taskq_bucket
name|taskq_bucket_t
typedef|;
typedef|typedef
struct|struct
name|taskq_ent
block|{
name|struct
name|taskq_ent
modifier|*
name|tqent_next
decl_stmt|;
name|struct
name|taskq_ent
modifier|*
name|tqent_prev
decl_stmt|;
name|task_func_t
modifier|*
name|tqent_func
decl_stmt|;
name|void
modifier|*
name|tqent_arg
decl_stmt|;
name|taskq_bucket_t
modifier|*
name|tqent_bucket
decl_stmt|;
name|kthread_t
modifier|*
name|tqent_thread
decl_stmt|;
name|kcondvar_t
name|tqent_cv
decl_stmt|;
block|}
name|taskq_ent_t
typedef|;
comment|/*  * Taskq Statistics fields are not protected by any locks.  */
typedef|typedef
struct|struct
name|tqstat
block|{
name|uint_t
name|tqs_hits
decl_stmt|;
name|uint_t
name|tqs_misses
decl_stmt|;
name|uint_t
name|tqs_overflow
decl_stmt|;
comment|/* no threads to allocate   */
name|uint_t
name|tqs_tcreates
decl_stmt|;
comment|/* threads created 	*/
name|uint_t
name|tqs_tdeaths
decl_stmt|;
comment|/* threads died		*/
name|uint_t
name|tqs_maxthreads
decl_stmt|;
comment|/* max # of alive threads */
name|uint_t
name|tqs_nomem
decl_stmt|;
comment|/* # of times there were no memory */
name|uint_t
name|tqs_disptcreates
decl_stmt|;
block|}
name|tqstat_t
typedef|;
comment|/*  * Per-CPU hash bucket manages taskq_bent_t structures using freelist.  */
struct|struct
name|taskq_bucket
block|{
name|kmutex_t
name|tqbucket_lock
decl_stmt|;
name|taskq_t
modifier|*
name|tqbucket_taskq
decl_stmt|;
comment|/* Enclosing taskq */
name|taskq_ent_t
name|tqbucket_freelist
decl_stmt|;
name|uint_t
name|tqbucket_nalloc
decl_stmt|;
comment|/* # of allocated entries */
name|uint_t
name|tqbucket_nfree
decl_stmt|;
comment|/* # of free entries */
name|kcondvar_t
name|tqbucket_cv
decl_stmt|;
name|ushort_t
name|tqbucket_flags
decl_stmt|;
name|hrtime_t
name|tqbucket_totaltime
decl_stmt|;
name|tqstat_t
name|tqbucket_stat
decl_stmt|;
block|}
struct|;
comment|/*  * Bucket flags.  */
define|#
directive|define
name|TQBUCKET_CLOSE
value|0x01
define|#
directive|define
name|TQBUCKET_SUSPEND
value|0x02
comment|/*  * taskq implementation flags: bit range 16-31  */
define|#
directive|define
name|TASKQ_ACTIVE
value|0x00010000
define|#
directive|define
name|TASKQ_SUSPENDED
value|0x00020000
define|#
directive|define
name|TASKQ_NOINSTANCE
value|0x00040000
struct|struct
name|taskq
block|{
name|char
name|tq_name
index|[
name|TASKQ_NAMELEN
operator|+
literal|1
index|]
decl_stmt|;
name|kmutex_t
name|tq_lock
decl_stmt|;
name|krwlock_t
name|tq_threadlock
decl_stmt|;
name|kcondvar_t
name|tq_dispatch_cv
decl_stmt|;
name|kcondvar_t
name|tq_wait_cv
decl_stmt|;
name|uint_t
name|tq_flags
decl_stmt|;
name|int
name|tq_active
decl_stmt|;
name|int
name|tq_nthreads
decl_stmt|;
name|int
name|tq_nalloc
decl_stmt|;
name|int
name|tq_minalloc
decl_stmt|;
name|int
name|tq_maxalloc
decl_stmt|;
name|taskq_ent_t
modifier|*
name|tq_freelist
decl_stmt|;
name|taskq_ent_t
name|tq_task
decl_stmt|;
name|int
name|tq_maxsize
decl_stmt|;
name|pri_t
name|tq_pri
decl_stmt|;
comment|/* Scheduling priority	    */
name|taskq_bucket_t
modifier|*
name|tq_buckets
decl_stmt|;
comment|/* Per-cpu array of buckets */
name|uint_t
name|tq_nbuckets
decl_stmt|;
comment|/* # of buckets	(2^n)	    */
union|union
block|{
name|kthread_t
modifier|*
name|_tq_thread
decl_stmt|;
name|kthread_t
modifier|*
modifier|*
name|_tq_threadlist
decl_stmt|;
block|}
name|tq_thr
union|;
comment|/* 	 * Statistics. 	 */
name|hrtime_t
name|tq_totaltime
decl_stmt|;
comment|/* Time spent processing tasks */
name|int
name|tq_tasks
decl_stmt|;
comment|/* Total # of tasks posted */
name|int
name|tq_executed
decl_stmt|;
comment|/* Total # of tasks executed */
name|int
name|tq_maxtasks
decl_stmt|;
comment|/* Max number of tasks in the queue */
name|int
name|tq_tcreates
decl_stmt|;
name|int
name|tq_tdeaths
decl_stmt|;
block|}
struct|;
define|#
directive|define
name|tq_thread
value|tq_thr._tq_thread
define|#
directive|define
name|tq_threadlist
value|tq_thr._tq_threadlist
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
comment|/* _SYS_TASKQ_IMPL_H */
end_comment

end_unit

