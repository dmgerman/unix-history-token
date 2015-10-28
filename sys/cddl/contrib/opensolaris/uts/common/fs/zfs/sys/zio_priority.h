begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * This file and its contents are supplied under the terms of the  * Common Development and Distribution License ("CDDL"), version 1.0.  * You may only use this file in accordance with the terms of version  * 1.0 of the CDDL.  *  * A full copy of the text of the CDDL should have accompanied this  * source.  A copy of the CDDL is also available via the Internet at  * http://www.illumos.org/license/CDDL.  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2014 by Delphix. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ZIO_PRIORITY_H
end_ifndef

begin_define
define|#
directive|define
name|_ZIO_PRIORITY_H
end_define

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
enum|enum
name|zio_priority
block|{
name|ZIO_PRIORITY_SYNC_READ
block|,
name|ZIO_PRIORITY_SYNC_WRITE
block|,
comment|/* ZIL */
name|ZIO_PRIORITY_ASYNC_READ
block|,
comment|/* prefetch */
name|ZIO_PRIORITY_ASYNC_WRITE
block|,
comment|/* spa_sync() */
name|ZIO_PRIORITY_SCRUB
block|,
comment|/* asynchronous scrub/resilver reads */
name|ZIO_PRIORITY_TRIM
block|,
comment|/* free requests used for TRIM */
name|ZIO_PRIORITY_NUM_QUEUEABLE
block|,
name|ZIO_PRIORITY_NOW
comment|/* non-queued i/os (e.g. free) */
block|}
name|zio_priority_t
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
comment|/* _ZIO_PRIORITY_H */
end_comment

end_unit

