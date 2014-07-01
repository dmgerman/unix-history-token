begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2013 by Delphix. All rights reserved.  * Copyright (c) 2013 by Saso Kiselkov. All rights reserved.  * Copyright (c) 2013, Joyent, Inc. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ZFEATURE_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|_ZFEATURE_COMMON_H
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
struct_decl|struct
name|zfeature_info
struct_decl|;
typedef|typedef
enum|enum
name|spa_feature
block|{
name|SPA_FEATURE_NONE
init|=
operator|-
literal|1
block|,
name|SPA_FEATURE_ASYNC_DESTROY
block|,
name|SPA_FEATURE_EMPTY_BPOBJ
block|,
name|SPA_FEATURE_LZ4_COMPRESS
block|,
name|SPA_FEATURE_MULTI_VDEV_CRASH_DUMP
block|,
name|SPA_FEATURE_SPACEMAP_HISTOGRAM
block|,
name|SPA_FEATURE_ENABLED_TXG
block|,
name|SPA_FEATURE_HOLE_BIRTH
block|,
name|SPA_FEATURE_EXTENSIBLE_DATASET
block|,
name|SPA_FEATURE_EMBEDDED_DATA
block|,
name|SPA_FEATURE_BOOKMARKS
block|,
name|SPA_FEATURE_FS_SS_LIMIT
block|,
name|SPA_FEATURES
block|}
name|spa_feature_t
typedef|;
define|#
directive|define
name|SPA_FEATURE_DISABLED
value|(-1ULL)
typedef|typedef
struct|struct
name|zfeature_info
block|{
name|spa_feature_t
name|fi_feature
decl_stmt|;
specifier|const
name|char
modifier|*
name|fi_uname
decl_stmt|;
comment|/* User-facing feature name */
specifier|const
name|char
modifier|*
name|fi_guid
decl_stmt|;
comment|/* On-disk feature identifier */
specifier|const
name|char
modifier|*
name|fi_desc
decl_stmt|;
comment|/* Feature description */
name|boolean_t
name|fi_can_readonly
decl_stmt|;
comment|/* Can open pool readonly w/o support? */
name|boolean_t
name|fi_mos
decl_stmt|;
comment|/* Is the feature necessary to read the MOS? */
comment|/* Activate this feature at the same time it is enabled */
name|boolean_t
name|fi_activate_on_enable
decl_stmt|;
comment|/* array of dependencies, terminated by SPA_FEATURE_NONE */
specifier|const
name|spa_feature_t
modifier|*
name|fi_depends
decl_stmt|;
block|}
name|zfeature_info_t
typedef|;
typedef|typedef
name|int
function_decl|(
name|zfeature_func_t
function_decl|)
parameter_list|(
name|zfeature_info_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
define|#
directive|define
name|ZFS_FEATURE_DEBUG
specifier|extern
name|zfeature_info_t
name|spa_feature_table
index|[
name|SPA_FEATURES
index|]
decl_stmt|;
specifier|extern
name|boolean_t
name|zfeature_is_valid_guid
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|boolean_t
name|zfeature_is_supported
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|zfeature_lookup_name
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|spa_feature_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|boolean_t
name|zfeature_depends_on
parameter_list|(
name|spa_feature_t
parameter_list|,
name|spa_feature_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zpool_feature_init
parameter_list|(
name|void
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
comment|/* _ZFEATURE_COMMON_H */
end_comment

end_unit

