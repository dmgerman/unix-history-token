begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2008, 2010, Oracle and/or its affiliates. All rights reserved.  * Copyright (c) 2012 by Delphix. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ZFS_COMUTIL_H
end_ifndef

begin_define
define|#
directive|define
name|_ZFS_COMUTIL_H
end_define

begin_include
include|#
directive|include
file|<sys/fs/zfs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
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
specifier|extern
name|boolean_t
name|zfs_allocatable_devs
parameter_list|(
name|nvlist_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zpool_get_rewind_policy
parameter_list|(
name|nvlist_t
modifier|*
parameter_list|,
name|zpool_rewind_policy_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|zfs_zpl_version_map
parameter_list|(
name|int
name|spa_version
parameter_list|)
function_decl|;
specifier|extern
name|int
name|zfs_spa_version_map
parameter_list|(
name|int
name|zpl_version
parameter_list|)
function_decl|;
define|#
directive|define
name|ZFS_NUM_LEGACY_HISTORY_EVENTS
value|41
specifier|extern
specifier|const
name|char
modifier|*
name|zfs_history_event_names
index|[
name|ZFS_NUM_LEGACY_HISTORY_EVENTS
index|]
decl_stmt|;
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
comment|/* _ZFS_COMUTIL_H */
end_comment

end_unit

