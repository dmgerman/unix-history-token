begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2009 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2013 by Delphix. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TXG_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TXG_IMPL_H
end_define

begin_include
include|#
directive|include
file|<sys/spa.h>
end_include

begin_include
include|#
directive|include
file|<sys/txg.h>
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
comment|/*  * The tx_cpu structure is a per-cpu structure that is used to track  * the number of active transaction holds (tc_count). As transactions  * are assigned into a transaction group the appropriate tc_count is  * incremented to indicate that there are pending changes that have yet  * to quiesce. Consumers evenutally call txg_rele_to_sync() to decrement  * the tc_count. A transaction group is not considered quiesced until all  * tx_cpu structures have reached a tc_count of zero.  *  * This structure is a per-cpu structure by design. Updates to this structure  * are frequent and concurrent. Having a single structure would result in  * heavy lock contention so a per-cpu design was implemented. With the fanned  * out mutex design, consumers only need to lock the mutex associated with  * thread's cpu.  *  * The tx_cpu contains two locks, the tc_lock and tc_open_lock.  * The tc_lock is used to protect all members of the tx_cpu structure with  * the exception of the tc_open_lock. This lock should only be held for a  * short period of time, typically when updating the value of tc_count.  *  * The tc_open_lock protects the tx_open_txg member of the tx_state structure.  * This lock is used to ensure that transactions are only assigned into  * the current open transaction group. In order to move the current open  * transaction group to the quiesce phase, the txg_quiesce thread must  * grab all tc_open_locks, increment the tx_open_txg, and drop the locks.  * The tc_open_lock is held until the transaction is assigned into the  * transaction group. Typically, this is a short operation but if throttling  * is occuring it may be held for longer periods of time.  */
struct|struct
name|tx_cpu
block|{
name|kmutex_t
name|tc_open_lock
decl_stmt|;
comment|/* protects tx_open_txg */
name|kmutex_t
name|tc_lock
decl_stmt|;
comment|/* protects the rest of this struct */
name|kcondvar_t
name|tc_cv
index|[
name|TXG_SIZE
index|]
decl_stmt|;
name|uint64_t
name|tc_count
index|[
name|TXG_SIZE
index|]
decl_stmt|;
comment|/* tx hold count on each txg */
name|list_t
name|tc_callbacks
index|[
name|TXG_SIZE
index|]
decl_stmt|;
comment|/* commit cb list */
name|char
name|tc_pad
index|[
literal|8
index|]
decl_stmt|;
comment|/* pad to fill 3 cache lines */
block|}
struct|;
comment|/*  * The tx_state structure maintains the state information about the different  * stages of the pool's transcation groups. A per pool tx_state structure  * is used to track this information. The tx_state structure also points to  * an array of tx_cpu structures (described above). Although the tx_sync_lock  * is used to protect the members of this structure, it is not used to  * protect the tx_open_txg. Instead a special lock in the tx_cpu structure  * is used. Readers of tx_open_txg must grab the per-cpu tc_open_lock.  * Any thread wishing to update tx_open_txg must grab the tc_open_lock on  * every cpu (see txg_quiesce()).  */
typedef|typedef
struct|struct
name|tx_state
block|{
name|tx_cpu_t
modifier|*
name|tx_cpu
decl_stmt|;
comment|/* protects access to tx_open_txg */
name|kmutex_t
name|tx_sync_lock
decl_stmt|;
comment|/* protects the rest of this struct */
name|uint64_t
name|tx_open_txg
decl_stmt|;
comment|/* currently open txg id */
name|uint64_t
name|tx_quiesced_txg
decl_stmt|;
comment|/* quiesced txg waiting for sync */
name|uint64_t
name|tx_syncing_txg
decl_stmt|;
comment|/* currently syncing txg id */
name|uint64_t
name|tx_synced_txg
decl_stmt|;
comment|/* last synced txg id */
name|hrtime_t
name|tx_open_time
decl_stmt|;
comment|/* start time of tx_open_txg */
name|uint64_t
name|tx_sync_txg_waiting
decl_stmt|;
comment|/* txg we're waiting to sync */
name|uint64_t
name|tx_quiesce_txg_waiting
decl_stmt|;
comment|/* txg we're waiting to open */
name|kcondvar_t
name|tx_sync_more_cv
decl_stmt|;
name|kcondvar_t
name|tx_sync_done_cv
decl_stmt|;
name|kcondvar_t
name|tx_quiesce_more_cv
decl_stmt|;
name|kcondvar_t
name|tx_quiesce_done_cv
decl_stmt|;
name|kcondvar_t
name|tx_timeout_cv
decl_stmt|;
name|kcondvar_t
name|tx_exit_cv
decl_stmt|;
comment|/* wait for all threads to exit */
name|uint8_t
name|tx_threads
decl_stmt|;
comment|/* number of threads */
name|uint8_t
name|tx_exiting
decl_stmt|;
comment|/* set when we're exiting */
name|kthread_t
modifier|*
name|tx_sync_thread
decl_stmt|;
name|kthread_t
modifier|*
name|tx_quiesce_thread
decl_stmt|;
name|taskq_t
modifier|*
name|tx_commit_cb_taskq
decl_stmt|;
comment|/* commit callback taskq */
block|}
name|tx_state_t
typedef|;
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
comment|/* _SYS_TXG_IMPL_H */
end_comment

end_unit

