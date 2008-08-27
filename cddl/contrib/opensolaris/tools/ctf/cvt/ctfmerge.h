begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2002-2003 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CTFMERGE_H
end_ifndef

begin_define
define|#
directive|define
name|_CTFMERGE_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_comment
comment|/*  * Merging structures used in ctfmerge.  See ctfmerge.c for locking semantics.  */
end_comment

begin_include
include|#
directive|include
file|<pthread.h>
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
include|#
directive|include
file|"ctftools.h"
include|#
directive|include
file|"barrier.h"
include|#
directive|include
file|"fifo.h"
typedef|typedef
struct|struct
name|wip
block|{
name|pthread_mutex_t
name|wip_lock
decl_stmt|;
name|pthread_cond_t
name|wip_cv
decl_stmt|;
name|tdata_t
modifier|*
name|wip_td
decl_stmt|;
name|int
name|wip_nmerged
decl_stmt|;
name|int
name|wip_batchid
decl_stmt|;
block|}
name|wip_t
typedef|;
typedef|typedef
struct|struct
name|workqueue
block|{
name|int
name|wq_next_batchid
decl_stmt|;
name|int
name|wq_maxbatchsz
decl_stmt|;
name|wip_t
modifier|*
name|wq_wip
decl_stmt|;
name|int
name|wq_nwipslots
decl_stmt|;
name|int
name|wq_nthreads
decl_stmt|;
name|int
name|wq_ithrottle
decl_stmt|;
name|pthread_mutex_t
name|wq_queue_lock
decl_stmt|;
name|fifo_t
modifier|*
name|wq_queue
decl_stmt|;
name|pthread_cond_t
name|wq_work_avail
decl_stmt|;
name|pthread_cond_t
name|wq_work_removed
decl_stmt|;
name|int
name|wq_ninqueue
decl_stmt|;
name|int
name|wq_nextpownum
decl_stmt|;
name|pthread_mutex_t
name|wq_donequeue_lock
decl_stmt|;
name|fifo_t
modifier|*
name|wq_donequeue
decl_stmt|;
name|int
name|wq_lastdonebatch
decl_stmt|;
name|pthread_cond_t
name|wq_done_cv
decl_stmt|;
name|pthread_cond_t
name|wq_alldone_cv
decl_stmt|;
comment|/* protected by queue_lock */
name|int
name|wq_alldone
decl_stmt|;
name|int
name|wq_nomorefiles
decl_stmt|;
name|barrier_t
name|wq_bar1
decl_stmt|;
name|barrier_t
name|wq_bar2
decl_stmt|;
block|}
name|workqueue_t
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
comment|/* _CTFMERGE_H */
end_comment

end_unit

