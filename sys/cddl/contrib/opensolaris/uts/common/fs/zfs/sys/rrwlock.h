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
name|_SYS_RR_RW_LOCK_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_RR_RW_LOCK_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

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
file|<sys/zfs_context.h>
include|#
directive|include
file|<sys/refcount.h>
comment|/*  * A reader-writer lock implementation that allows re-entrant reads, but  * still gives writers priority on "new" reads.  *  * See rrwlock.c for more details about the implementation.  *  * Fields of the rrwlock_t structure:  * - rr_lock: protects modification and reading of rrwlock_t fields  * - rr_cv: cv for waking up readers or waiting writers  * - rr_writer: thread id of the current writer  * - rr_anon_rount: number of active anonymous readers  * - rr_linked_rcount: total number of non-anonymous active readers  * - rr_writer_wanted: a writer wants the lock  */
typedef|typedef
struct|struct
name|rrwlock
block|{
name|kmutex_t
name|rr_lock
decl_stmt|;
name|kcondvar_t
name|rr_cv
decl_stmt|;
name|kthread_t
modifier|*
name|rr_writer
decl_stmt|;
name|refcount_t
name|rr_anon_rcount
decl_stmt|;
name|refcount_t
name|rr_linked_rcount
decl_stmt|;
name|boolean_t
name|rr_writer_wanted
decl_stmt|;
block|}
name|rrwlock_t
typedef|;
comment|/*  * 'tag' is used in reference counting tracking.  The  * 'tag' must be the same in a rrw_enter() as in its  * corresponding rrw_exit().  */
name|void
name|rrw_init
parameter_list|(
name|rrwlock_t
modifier|*
name|rrl
parameter_list|)
function_decl|;
name|void
name|rrw_destroy
parameter_list|(
name|rrwlock_t
modifier|*
name|rrl
parameter_list|)
function_decl|;
name|void
name|rrw_enter
parameter_list|(
name|rrwlock_t
modifier|*
name|rrl
parameter_list|,
name|krw_t
name|rw
parameter_list|,
name|void
modifier|*
name|tag
parameter_list|)
function_decl|;
name|void
name|rrw_exit
parameter_list|(
name|rrwlock_t
modifier|*
name|rrl
parameter_list|,
name|void
modifier|*
name|tag
parameter_list|)
function_decl|;
name|boolean_t
name|rrw_held
parameter_list|(
name|rrwlock_t
modifier|*
name|rrl
parameter_list|,
name|krw_t
name|rw
parameter_list|)
function_decl|;
define|#
directive|define
name|RRW_READ_HELD
parameter_list|(
name|x
parameter_list|)
value|rrw_held(x, RW_READER)
define|#
directive|define
name|RRW_WRITE_HELD
parameter_list|(
name|x
parameter_list|)
value|rrw_held(x, RW_WRITER)
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
comment|/* _SYS_RR_RW_LOCK_H */
end_comment

end_unit

