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
name|_SYS_TXG_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TXG_IMPL_H
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
struct|struct
name|tx_cpu
block|{
name|kmutex_t
name|tc_lock
decl_stmt|;
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
name|char
name|tc_pad
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
typedef|typedef
struct|struct
name|tx_state
block|{
name|tx_cpu_t
modifier|*
name|tx_cpu
decl_stmt|;
comment|/* protects right to enter txg	*/
name|kmutex_t
name|tx_sync_lock
decl_stmt|;
comment|/* protects tx_state_t */
name|krwlock_t
name|tx_suspend
decl_stmt|;
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
name|tx_timeout_exit_cv
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
name|kthread_t
modifier|*
name|tx_timelimit_thread
decl_stmt|;
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

