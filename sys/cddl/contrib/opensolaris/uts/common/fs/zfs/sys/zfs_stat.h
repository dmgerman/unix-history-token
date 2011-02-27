begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2010, Oracle and/or its affiliates. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_FS_ZFS_STAT_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_FS_ZFS_STAT_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/isa_defs.h>
end_include

begin_include
include|#
directive|include
file|<sys/dmu.h>
end_include

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
comment|/*  * A limited number of zpl level stats are retrievable  * with an ioctl.  zfs diff is the current consumer.  */
typedef|typedef
struct|struct
name|zfs_stat
block|{
name|uint64_t
name|zs_gen
decl_stmt|;
name|uint64_t
name|zs_mode
decl_stmt|;
name|uint64_t
name|zs_links
decl_stmt|;
name|uint64_t
name|zs_ctime
index|[
literal|2
index|]
decl_stmt|;
block|}
name|zfs_stat_t
typedef|;
specifier|extern
name|int
name|zfs_obj_to_stats
parameter_list|(
name|objset_t
modifier|*
name|osp
parameter_list|,
name|uint64_t
name|obj
parameter_list|,
name|zfs_stat_t
modifier|*
name|sb
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|len
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
comment|/* _SYS_FS_ZFS_STAT_H */
end_comment

end_unit

