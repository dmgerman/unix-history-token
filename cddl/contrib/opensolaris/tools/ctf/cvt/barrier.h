begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2002 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BARRIER_H
end_ifndef

begin_define
define|#
directive|define
name|_BARRIER_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_comment
comment|/*  * APIs for the barrier synchronization primitive.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|illumos
end_ifdef

begin_include
include|#
directive|include
file|<synch.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<semaphore.h>
end_include

begin_typedef
typedef|typedef
name|sem_t
name|sema_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

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
struct|struct
name|barrier
block|{
name|pthread_mutex_t
name|bar_lock
decl_stmt|;
comment|/* protects bar_numin */
name|int
name|bar_numin
decl_stmt|;
comment|/* current number of waiters */
name|sema_t
name|bar_sem
decl_stmt|;
comment|/* where everyone waits */
name|int
name|bar_nthr
decl_stmt|;
comment|/* # of waiters to trigger release */
block|}
name|barrier_t
typedef|;
specifier|extern
name|void
name|barrier_init
parameter_list|(
name|barrier_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|barrier_wait
parameter_list|(
name|barrier_t
modifier|*
parameter_list|)
function_decl|;
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
comment|/* _BARRIER_H */
end_comment

end_unit

