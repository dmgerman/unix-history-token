begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2013 by Martin Matuska<mm@FreeBSD.org>. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBZFS_CORE_COMPAT_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBZFS_CORE_COMPAT_H
end_define

begin_include
include|#
directive|include
file|<libnvpair.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/fs/zfs.h>
end_include

begin_include
include|#
directive|include
file|<sys/zfs_ioctl.h>
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
name|int
name|lzc_compat_pre
parameter_list|(
name|zfs_cmd_t
modifier|*
parameter_list|,
name|zfs_ioc_t
modifier|*
parameter_list|,
name|nvlist_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|void
name|lzc_compat_post
parameter_list|(
name|zfs_cmd_t
modifier|*
parameter_list|,
specifier|const
name|zfs_ioc_t
parameter_list|)
function_decl|;
name|int
name|lzc_compat_outnvl
parameter_list|(
name|zfs_cmd_t
modifier|*
parameter_list|,
specifier|const
name|zfs_ioc_t
parameter_list|,
name|nvlist_t
modifier|*
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
comment|/* _LIBZFS_CORE_COMPAT_H */
end_comment

end_unit

