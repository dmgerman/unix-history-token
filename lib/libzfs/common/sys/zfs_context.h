begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * This file and its contents are supplied under the terms of the  * Common Development and Distribution License ("CDDL"), version 1.0.  * You may only use this file in accordance with the terms of version  * 1.0 of the CDDL.  *  * A full copy of the text of the CDDL should have accompanied this  * source.  A copy of the CDDL is also available via the Internet at  * http://www.illumos.org/license/CDDL.  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2014 Spectra Logic Corporation.  All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ZFS_CONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ZFS_CONTEXT_H
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
include|#
directive|include
file|<sys/stat.h>
include|#
directive|include
file|<sys/taskq.h>
include|#
directive|include
file|<sys/taskq_impl.h>
include|#
directive|include
file|<sys/debug.h>
include|#
directive|include
file|<sys/list.h>
include|#
directive|include
file|<sys/zfs_debug.h>
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
comment|/* _SYS_ZFS_CONTEXT_H */
end_comment

end_unit

