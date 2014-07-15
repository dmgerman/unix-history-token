begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2014 Xin Li<delphij@FreeBSD.org>.  All rights reserved.  * Copyright 2013 Martin Matuska<mm@FreeBSD.org>.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ZFS_IOCTL_COMPAT_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ZFS_IOCTL_COMPAT_H
end_define

begin_include
include|#
directive|include
file|<sys/cred.h>
end_include

begin_include
include|#
directive|include
file|<sys/dmu.h>
end_include

begin_include
include|#
directive|include
file|<sys/zio.h>
end_include

begin_include
include|#
directive|include
file|<sys/dsl_deleg.h>
end_include

begin_include
include|#
directive|include
file|<sys/zfs_ioctl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/nvpair.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

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
comment|/*  * Backwards ioctl compatibility  */
comment|/* ioctl versions for vfs.zfs.version.ioctl */
define|#
directive|define
name|ZFS_IOCVER_UNDEF
value|-1
define|#
directive|define
name|ZFS_IOCVER_NONE
value|0
define|#
directive|define
name|ZFS_IOCVER_DEADMAN
value|1
define|#
directive|define
name|ZFS_IOCVER_LZC
value|2
define|#
directive|define
name|ZFS_IOCVER_ZCMD
value|3
define|#
directive|define
name|ZFS_IOCVER_EDBP
value|4
define|#
directive|define
name|ZFS_IOCVER_CURRENT
value|ZFS_IOCVER_EDBP
comment|/* compatibility conversion flag */
define|#
directive|define
name|ZFS_CMD_COMPAT_NONE
value|0
define|#
directive|define
name|ZFS_CMD_COMPAT_V15
value|1
define|#
directive|define
name|ZFS_CMD_COMPAT_V28
value|2
define|#
directive|define
name|ZFS_CMD_COMPAT_DEADMAN
value|3
define|#
directive|define
name|ZFS_CMD_COMPAT_LZC
value|4
define|#
directive|define
name|ZFS_CMD_COMPAT_ZCMD
value|5
define|#
directive|define
name|ZFS_IOC_COMPAT_PASS
value|254
define|#
directive|define
name|ZFS_IOC_COMPAT_FAIL
value|255
define|#
directive|define
name|ZFS_IOCREQ
parameter_list|(
name|ioreq
parameter_list|)
value|((ioreq)& 0xff)
typedef|typedef
struct|struct
name|zfs_iocparm
block|{
name|uint32_t
name|zfs_ioctl_version
decl_stmt|;
name|uint64_t
name|zfs_cmd
decl_stmt|;
name|uint64_t
name|zfs_cmd_size
decl_stmt|;
block|}
name|zfs_iocparm_t
typedef|;
typedef|typedef
struct|struct
name|zinject_record_v15
block|{
name|uint64_t
name|zi_objset
decl_stmt|;
name|uint64_t
name|zi_object
decl_stmt|;
name|uint64_t
name|zi_start
decl_stmt|;
name|uint64_t
name|zi_end
decl_stmt|;
name|uint64_t
name|zi_guid
decl_stmt|;
name|uint32_t
name|zi_level
decl_stmt|;
name|uint32_t
name|zi_error
decl_stmt|;
name|uint64_t
name|zi_type
decl_stmt|;
name|uint32_t
name|zi_freq
decl_stmt|;
name|uint32_t
name|zi_failfast
decl_stmt|;
block|}
name|zinject_record_v15_t
typedef|;
typedef|typedef
struct|struct
name|zfs_cmd_v15
block|{
name|char
name|zc_name
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|char
name|zc_value
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|char
name|zc_string
index|[
name|MAXNAMELEN
index|]
decl_stmt|;
name|uint64_t
name|zc_guid
decl_stmt|;
name|uint64_t
name|zc_nvlist_conf
decl_stmt|;
comment|/* really (char *) */
name|uint64_t
name|zc_nvlist_conf_size
decl_stmt|;
name|uint64_t
name|zc_nvlist_src
decl_stmt|;
comment|/* really (char *) */
name|uint64_t
name|zc_nvlist_src_size
decl_stmt|;
name|uint64_t
name|zc_nvlist_dst
decl_stmt|;
comment|/* really (char *) */
name|uint64_t
name|zc_nvlist_dst_size
decl_stmt|;
name|uint64_t
name|zc_cookie
decl_stmt|;
name|uint64_t
name|zc_objset_type
decl_stmt|;
name|uint64_t
name|zc_perm_action
decl_stmt|;
name|uint64_t
name|zc_history
decl_stmt|;
comment|/* really (char *) */
name|uint64_t
name|zc_history_len
decl_stmt|;
name|uint64_t
name|zc_history_offset
decl_stmt|;
name|uint64_t
name|zc_obj
decl_stmt|;
name|zfs_share_t
name|zc_share
decl_stmt|;
name|uint64_t
name|zc_jailid
decl_stmt|;
name|dmu_objset_stats_t
name|zc_objset_stats
decl_stmt|;
name|struct
name|drr_begin
name|zc_begin_record
decl_stmt|;
name|zinject_record_v15_t
name|zc_inject_record
decl_stmt|;
block|}
name|zfs_cmd_v15_t
typedef|;
typedef|typedef
struct|struct
name|zinject_record_v28
block|{
name|uint64_t
name|zi_objset
decl_stmt|;
name|uint64_t
name|zi_object
decl_stmt|;
name|uint64_t
name|zi_start
decl_stmt|;
name|uint64_t
name|zi_end
decl_stmt|;
name|uint64_t
name|zi_guid
decl_stmt|;
name|uint32_t
name|zi_level
decl_stmt|;
name|uint32_t
name|zi_error
decl_stmt|;
name|uint64_t
name|zi_type
decl_stmt|;
name|uint32_t
name|zi_freq
decl_stmt|;
name|uint32_t
name|zi_failfast
decl_stmt|;
name|char
name|zi_func
index|[
name|MAXNAMELEN
index|]
decl_stmt|;
name|uint32_t
name|zi_iotype
decl_stmt|;
name|int32_t
name|zi_duration
decl_stmt|;
name|uint64_t
name|zi_timer
decl_stmt|;
block|}
name|zinject_record_v28_t
typedef|;
typedef|typedef
struct|struct
name|zfs_cmd_v28
block|{
name|char
name|zc_name
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|char
name|zc_value
index|[
name|MAXPATHLEN
operator|*
literal|2
index|]
decl_stmt|;
name|char
name|zc_string
index|[
name|MAXNAMELEN
index|]
decl_stmt|;
name|char
name|zc_top_ds
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|uint64_t
name|zc_guid
decl_stmt|;
name|uint64_t
name|zc_nvlist_conf
decl_stmt|;
comment|/* really (char *) */
name|uint64_t
name|zc_nvlist_conf_size
decl_stmt|;
name|uint64_t
name|zc_nvlist_src
decl_stmt|;
comment|/* really (char *) */
name|uint64_t
name|zc_nvlist_src_size
decl_stmt|;
name|uint64_t
name|zc_nvlist_dst
decl_stmt|;
comment|/* really (char *) */
name|uint64_t
name|zc_nvlist_dst_size
decl_stmt|;
name|uint64_t
name|zc_cookie
decl_stmt|;
name|uint64_t
name|zc_objset_type
decl_stmt|;
name|uint64_t
name|zc_perm_action
decl_stmt|;
name|uint64_t
name|zc_history
decl_stmt|;
comment|/* really (char *) */
name|uint64_t
name|zc_history_len
decl_stmt|;
name|uint64_t
name|zc_history_offset
decl_stmt|;
name|uint64_t
name|zc_obj
decl_stmt|;
name|uint64_t
name|zc_iflags
decl_stmt|;
comment|/* internal to zfs(7fs) */
name|zfs_share_t
name|zc_share
decl_stmt|;
name|uint64_t
name|zc_jailid
decl_stmt|;
name|dmu_objset_stats_t
name|zc_objset_stats
decl_stmt|;
name|struct
name|drr_begin
name|zc_begin_record
decl_stmt|;
name|zinject_record_v28_t
name|zc_inject_record
decl_stmt|;
name|boolean_t
name|zc_defer_destroy
decl_stmt|;
name|boolean_t
name|zc_temphold
decl_stmt|;
name|uint64_t
name|zc_action_handle
decl_stmt|;
name|int
name|zc_cleanup_fd
decl_stmt|;
name|uint8_t
name|zc_simple
decl_stmt|;
name|uint8_t
name|zc_pad
index|[
literal|3
index|]
decl_stmt|;
comment|/* alignment */
name|uint64_t
name|zc_sendobj
decl_stmt|;
name|uint64_t
name|zc_fromobj
decl_stmt|;
name|uint64_t
name|zc_createtxg
decl_stmt|;
name|zfs_stat_t
name|zc_stat
decl_stmt|;
block|}
name|zfs_cmd_v28_t
typedef|;
typedef|typedef
struct|struct
name|zfs_cmd_deadman
block|{
name|char
name|zc_name
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|char
name|zc_value
index|[
name|MAXPATHLEN
operator|*
literal|2
index|]
decl_stmt|;
name|char
name|zc_string
index|[
name|MAXNAMELEN
index|]
decl_stmt|;
name|char
name|zc_top_ds
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|uint64_t
name|zc_guid
decl_stmt|;
name|uint64_t
name|zc_nvlist_conf
decl_stmt|;
comment|/* really (char *) */
name|uint64_t
name|zc_nvlist_conf_size
decl_stmt|;
name|uint64_t
name|zc_nvlist_src
decl_stmt|;
comment|/* really (char *) */
name|uint64_t
name|zc_nvlist_src_size
decl_stmt|;
name|uint64_t
name|zc_nvlist_dst
decl_stmt|;
comment|/* really (char *) */
name|uint64_t
name|zc_nvlist_dst_size
decl_stmt|;
name|uint64_t
name|zc_cookie
decl_stmt|;
name|uint64_t
name|zc_objset_type
decl_stmt|;
name|uint64_t
name|zc_perm_action
decl_stmt|;
name|uint64_t
name|zc_history
decl_stmt|;
comment|/* really (char *) */
name|uint64_t
name|zc_history_len
decl_stmt|;
name|uint64_t
name|zc_history_offset
decl_stmt|;
name|uint64_t
name|zc_obj
decl_stmt|;
name|uint64_t
name|zc_iflags
decl_stmt|;
comment|/* internal to zfs(7fs) */
name|zfs_share_t
name|zc_share
decl_stmt|;
name|uint64_t
name|zc_jailid
decl_stmt|;
name|dmu_objset_stats_t
name|zc_objset_stats
decl_stmt|;
name|struct
name|drr_begin
name|zc_begin_record
decl_stmt|;
comment|/* zc_inject_record doesn't change in libzfs_core */
name|zinject_record_t
name|zc_inject_record
decl_stmt|;
name|boolean_t
name|zc_defer_destroy
decl_stmt|;
name|boolean_t
name|zc_temphold
decl_stmt|;
name|uint64_t
name|zc_action_handle
decl_stmt|;
name|int
name|zc_cleanup_fd
decl_stmt|;
name|uint8_t
name|zc_simple
decl_stmt|;
name|uint8_t
name|zc_pad
index|[
literal|3
index|]
decl_stmt|;
comment|/* alignment */
name|uint64_t
name|zc_sendobj
decl_stmt|;
name|uint64_t
name|zc_fromobj
decl_stmt|;
name|uint64_t
name|zc_createtxg
decl_stmt|;
name|zfs_stat_t
name|zc_stat
decl_stmt|;
block|}
name|zfs_cmd_deadman_t
typedef|;
typedef|typedef
struct|struct
name|zfs_cmd_zcmd
block|{
name|char
name|zc_name
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
comment|/* name of pool or dataset */
name|uint64_t
name|zc_nvlist_src
decl_stmt|;
comment|/* really (char *) */
name|uint64_t
name|zc_nvlist_src_size
decl_stmt|;
name|uint64_t
name|zc_nvlist_dst
decl_stmt|;
comment|/* really (char *) */
name|uint64_t
name|zc_nvlist_dst_size
decl_stmt|;
name|boolean_t
name|zc_nvlist_dst_filled
decl_stmt|;
comment|/* put an nvlist in dst? */
name|int
name|zc_pad2
decl_stmt|;
comment|/* 	 * The following members are for legacy ioctls which haven't been 	 * converted to the new method. 	 */
name|uint64_t
name|zc_history
decl_stmt|;
comment|/* really (char *) */
name|char
name|zc_value
index|[
name|MAXPATHLEN
operator|*
literal|2
index|]
decl_stmt|;
name|char
name|zc_string
index|[
name|MAXNAMELEN
index|]
decl_stmt|;
name|uint64_t
name|zc_guid
decl_stmt|;
name|uint64_t
name|zc_nvlist_conf
decl_stmt|;
comment|/* really (char *) */
name|uint64_t
name|zc_nvlist_conf_size
decl_stmt|;
name|uint64_t
name|zc_cookie
decl_stmt|;
name|uint64_t
name|zc_objset_type
decl_stmt|;
name|uint64_t
name|zc_perm_action
decl_stmt|;
name|uint64_t
name|zc_history_len
decl_stmt|;
name|uint64_t
name|zc_history_offset
decl_stmt|;
name|uint64_t
name|zc_obj
decl_stmt|;
name|uint64_t
name|zc_iflags
decl_stmt|;
comment|/* internal to zfs(7fs) */
name|zfs_share_t
name|zc_share
decl_stmt|;
name|uint64_t
name|zc_jailid
decl_stmt|;
name|dmu_objset_stats_t
name|zc_objset_stats
decl_stmt|;
name|struct
name|drr_begin
name|zc_begin_record
decl_stmt|;
name|zinject_record_t
name|zc_inject_record
decl_stmt|;
name|boolean_t
name|zc_defer_destroy
decl_stmt|;
name|boolean_t
name|zc_temphold
decl_stmt|;
name|uint64_t
name|zc_action_handle
decl_stmt|;
name|int
name|zc_cleanup_fd
decl_stmt|;
name|uint8_t
name|zc_simple
decl_stmt|;
name|uint8_t
name|zc_pad
index|[
literal|3
index|]
decl_stmt|;
comment|/* alignment */
name|uint64_t
name|zc_sendobj
decl_stmt|;
name|uint64_t
name|zc_fromobj
decl_stmt|;
name|uint64_t
name|zc_createtxg
decl_stmt|;
name|zfs_stat_t
name|zc_stat
decl_stmt|;
block|}
name|zfs_cmd_zcmd_t
typedef|;
ifdef|#
directive|ifdef
name|_KERNEL
name|unsigned
specifier|static
name|long
name|zfs_ioctl_v15_to_v28
index|[]
init|=
block|{
literal|0
block|,
comment|/*  0 ZFS_IOC_POOL_CREATE */
literal|1
block|,
comment|/*  1 ZFS_IOC_POOL_DESTROY */
literal|2
block|,
comment|/*  2 ZFS_IOC_POOL_IMPORT */
literal|3
block|,
comment|/*  3 ZFS_IOC_POOL_EXPORT */
literal|4
block|,
comment|/*  4 ZFS_IOC_POOL_CONFIGS */
literal|5
block|,
comment|/*  5 ZFS_IOC_POOL_STATS */
literal|6
block|,
comment|/*  6 ZFS_IOC_POOL_TRYIMPORT */
literal|7
block|,
comment|/*  7 ZFS_IOC_POOL_SCRUB */
literal|8
block|,
comment|/*  8 ZFS_IOC_POOL_FREEZE */
literal|9
block|,
comment|/*  9 ZFS_IOC_POOL_UPGRADE */
literal|10
block|,
comment|/* 10 ZFS_IOC_POOL_GET_HISTORY */
literal|11
block|,
comment|/* 11 ZFS_IOC_VDEV_ADD */
literal|12
block|,
comment|/* 12 ZFS_IOC_VDEV_REMOVE */
literal|13
block|,
comment|/* 13 ZFS_IOC_VDEV_SET_STATE */
literal|14
block|,
comment|/* 14 ZFS_IOC_VDEV_ATTACH */
literal|15
block|,
comment|/* 15 ZFS_IOC_VDEV_DETACH */
literal|16
block|,
comment|/* 16 ZFS_IOC_VDEV_SETPATH */
literal|18
block|,
comment|/* 17 ZFS_IOC_OBJSET_STATS */
literal|19
block|,
comment|/* 18 ZFS_IOC_OBJSET_ZPLPROPS */
literal|20
block|,
comment|/* 19 ZFS_IOC_DATASET_LIST_NEXT */
literal|21
block|,
comment|/* 20 ZFS_IOC_SNAPSHOT_LIST_NEXT */
literal|22
block|,
comment|/* 21 ZFS_IOC_SET_PROP */
name|ZFS_IOC_COMPAT_PASS
block|,
comment|/* 22 ZFS_IOC_CREATE_MINOR */
name|ZFS_IOC_COMPAT_PASS
block|,
comment|/* 23 ZFS_IOC_REMOVE_MINOR */
literal|23
block|,
comment|/* 24 ZFS_IOC_CREATE */
literal|24
block|,
comment|/* 25 ZFS_IOC_DESTROY */
literal|25
block|,
comment|/* 26 ZFS_IOC_ROLLBACK */
literal|26
block|,
comment|/* 27 ZFS_IOC_RENAME */
literal|27
block|,
comment|/* 28 ZFS_IOC_RECV */
literal|28
block|,
comment|/* 29 ZFS_IOC_SEND */
literal|29
block|,
comment|/* 30 ZFS_IOC_INJECT_FAULT */
literal|30
block|,
comment|/* 31 ZFS_IOC_CLEAR_FAULT */
literal|31
block|,
comment|/* 32 ZFS_IOC_INJECT_LIST_NEXT */
literal|32
block|,
comment|/* 33 ZFS_IOC_ERROR_LOG */
literal|33
block|,
comment|/* 34 ZFS_IOC_CLEAR */
literal|34
block|,
comment|/* 35 ZFS_IOC_PROMOTE */
literal|35
block|,
comment|/* 36 ZFS_IOC_DESTROY_SNAPS */
literal|36
block|,
comment|/* 37 ZFS_IOC_SNAPSHOT */
literal|37
block|,
comment|/* 38 ZFS_IOC_DSOBJ_TO_DSNAME */
literal|38
block|,
comment|/* 39 ZFS_IOC_OBJ_TO_PATH */
literal|39
block|,
comment|/* 40 ZFS_IOC_POOL_SET_PROPS */
literal|40
block|,
comment|/* 41 ZFS_IOC_POOL_GET_PROPS */
literal|41
block|,
comment|/* 42 ZFS_IOC_SET_FSACL */
literal|42
block|,
comment|/* 43 ZFS_IOC_GET_FSACL */
name|ZFS_IOC_COMPAT_PASS
block|,
comment|/* 44 ZFS_IOC_ISCSI_PERM_CHECK */
literal|43
block|,
comment|/* 45 ZFS_IOC_SHARE */
literal|44
block|,
comment|/* 46 ZFS_IOC_IHNERIT_PROP */
literal|58
block|,
comment|/* 47 ZFS_IOC_JAIL */
literal|59
block|,
comment|/* 48 ZFS_IOC_UNJAIL */
literal|45
block|,
comment|/* 49 ZFS_IOC_SMB_ACL */
literal|46
block|,
comment|/* 50 ZFS_IOC_USERSPACE_ONE */
literal|47
block|,
comment|/* 51 ZFS_IOC_USERSPACE_MANY */
literal|48
block|,
comment|/* 52 ZFS_IOC_USERSPACE_UPGRADE */
literal|17
block|,
comment|/* 53 ZFS_IOC_SETFRU */
block|}
decl_stmt|;
else|#
directive|else
comment|/* KERNEL */
name|unsigned
specifier|static
name|long
name|zfs_ioctl_v28_to_v15
index|[]
init|=
block|{
literal|0
block|,
comment|/*  0 ZFS_IOC_POOL_CREATE */
literal|1
block|,
comment|/*  1 ZFS_IOC_POOL_DESTROY */
literal|2
block|,
comment|/*  2 ZFS_IOC_POOL_IMPORT */
literal|3
block|,
comment|/*  3 ZFS_IOC_POOL_EXPORT */
literal|4
block|,
comment|/*  4 ZFS_IOC_POOL_CONFIGS */
literal|5
block|,
comment|/*  5 ZFS_IOC_POOL_STATS */
literal|6
block|,
comment|/*  6 ZFS_IOC_POOL_TRYIMPORT */
literal|7
block|,
comment|/*  7 ZFS_IOC_POOL_SCAN */
literal|8
block|,
comment|/*  8 ZFS_IOC_POOL_FREEZE */
literal|9
block|,
comment|/*  9 ZFS_IOC_POOL_UPGRADE */
literal|10
block|,
comment|/* 10 ZFS_IOC_POOL_GET_HISTORY */
literal|11
block|,
comment|/* 11 ZFS_IOC_VDEV_ADD */
literal|12
block|,
comment|/* 12 ZFS_IOC_VDEV_REMOVE */
literal|13
block|,
comment|/* 13 ZFS_IOC_VDEV_SET_STATE */
literal|14
block|,
comment|/* 14 ZFS_IOC_VDEV_ATTACH */
literal|15
block|,
comment|/* 15 ZFS_IOC_VDEV_DETACH */
literal|16
block|,
comment|/* 16 ZFS_IOC_VDEV_SETPATH */
literal|53
block|,
comment|/* 17 ZFS_IOC_VDEV_SETFRU */
literal|17
block|,
comment|/* 18 ZFS_IOC_OBJSET_STATS */
literal|18
block|,
comment|/* 19 ZFS_IOC_OBJSET_ZPLPROPS */
literal|19
block|,
comment|/* 20 ZFS_IOC_DATASET_LIST_NEXT */
literal|20
block|,
comment|/* 21 ZFS_IOC_SNAPSHOT_LIST_NEXT */
literal|21
block|,
comment|/* 22 ZFS_IOC_SET_PROP */
literal|24
block|,
comment|/* 23 ZFS_IOC_CREATE */
literal|25
block|,
comment|/* 24 ZFS_IOC_DESTROY */
literal|26
block|,
comment|/* 25 ZFS_IOC_ROLLBACK */
literal|27
block|,
comment|/* 26 ZFS_IOC_RENAME */
literal|28
block|,
comment|/* 27 ZFS_IOC_RECV */
literal|29
block|,
comment|/* 28 ZFS_IOC_SEND */
literal|30
block|,
comment|/* 39 ZFS_IOC_INJECT_FAULT */
literal|31
block|,
comment|/* 30 ZFS_IOC_CLEAR_FAULT */
literal|32
block|,
comment|/* 31 ZFS_IOC_INJECT_LIST_NEXT */
literal|33
block|,
comment|/* 32 ZFS_IOC_ERROR_LOG */
literal|34
block|,
comment|/* 33 ZFS_IOC_CLEAR */
literal|35
block|,
comment|/* 34 ZFS_IOC_PROMOTE */
literal|36
block|,
comment|/* 35 ZFS_IOC_DESTROY_SNAPS */
literal|37
block|,
comment|/* 36 ZFS_IOC_SNAPSHOT */
literal|38
block|,
comment|/* 37 ZFS_IOC_DSOBJ_TO_DSNAME */
literal|39
block|,
comment|/* 38 ZFS_IOC_OBJ_TO_PATH */
literal|40
block|,
comment|/* 39 ZFS_IOC_POOL_SET_PROPS */
literal|41
block|,
comment|/* 40 ZFS_IOC_POOL_GET_PROPS */
literal|42
block|,
comment|/* 41 ZFS_IOC_SET_FSACL */
literal|43
block|,
comment|/* 42 ZFS_IOC_GET_FSACL */
literal|45
block|,
comment|/* 43 ZFS_IOC_SHARE */
literal|46
block|,
comment|/* 44 ZFS_IOC_IHNERIT_PROP */
literal|49
block|,
comment|/* 45 ZFS_IOC_SMB_ACL */
literal|50
block|,
comment|/* 46 ZFS_IOC_USERSPACE_ONE */
literal|51
block|,
comment|/* 47 ZFS_IOC_USERSPACE_MANY */
literal|52
block|,
comment|/* 48 ZFS_IOC_USERSPACE_UPGRADE */
name|ZFS_IOC_COMPAT_FAIL
block|,
comment|/* 49 ZFS_IOC_HOLD */
name|ZFS_IOC_COMPAT_FAIL
block|,
comment|/* 50 ZFS_IOC_RELEASE */
name|ZFS_IOC_COMPAT_FAIL
block|,
comment|/* 51 ZFS_IOC_GET_HOLDS */
name|ZFS_IOC_COMPAT_FAIL
block|,
comment|/* 52 ZFS_IOC_OBJSET_RECVD_PROPS */
name|ZFS_IOC_COMPAT_FAIL
block|,
comment|/* 53 ZFS_IOC_VDEV_SPLIT */
name|ZFS_IOC_COMPAT_FAIL
block|,
comment|/* 54 ZFS_IOC_NEXT_OBJ */
name|ZFS_IOC_COMPAT_FAIL
block|,
comment|/* 55 ZFS_IOC_DIFF */
name|ZFS_IOC_COMPAT_FAIL
block|,
comment|/* 56 ZFS_IOC_TMP_SNAPSHOT */
name|ZFS_IOC_COMPAT_FAIL
block|,
comment|/* 57 ZFS_IOC_OBJ_TO_STATS */
literal|47
block|,
comment|/* 58 ZFS_IOC_JAIL */
literal|48
block|,
comment|/* 59 ZFS_IOC_UNJAIL */
block|}
decl_stmt|;
endif|#
directive|endif
comment|/* ! _KERNEL */
ifdef|#
directive|ifdef
name|_KERNEL
name|int
name|zfs_ioctl_compat_pre
parameter_list|(
name|zfs_cmd_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
specifier|const
name|int
parameter_list|)
function_decl|;
name|void
name|zfs_ioctl_compat_post
parameter_list|(
name|zfs_cmd_t
modifier|*
parameter_list|,
specifier|const
name|int
parameter_list|,
specifier|const
name|int
parameter_list|)
function_decl|;
name|nvlist_t
modifier|*
name|zfs_ioctl_compat_innvl
parameter_list|(
name|zfs_cmd_t
modifier|*
parameter_list|,
name|nvlist_t
modifier|*
parameter_list|,
specifier|const
name|int
parameter_list|,
specifier|const
name|int
parameter_list|)
function_decl|;
name|nvlist_t
modifier|*
name|zfs_ioctl_compat_outnvl
parameter_list|(
name|zfs_cmd_t
modifier|*
parameter_list|,
name|nvlist_t
modifier|*
parameter_list|,
specifier|const
name|int
parameter_list|,
specifier|const
name|int
parameter_list|)
function_decl|;
else|#
directive|else
name|int
name|zcmd_ioctl_compat
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|zfs_cmd_t
modifier|*
parameter_list|,
specifier|const
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* _KERNEL */
name|void
name|zfs_cmd_compat_get
parameter_list|(
name|zfs_cmd_t
modifier|*
parameter_list|,
name|caddr_t
parameter_list|,
specifier|const
name|int
parameter_list|)
function_decl|;
name|void
name|zfs_cmd_compat_put
parameter_list|(
name|zfs_cmd_t
modifier|*
parameter_list|,
name|caddr_t
parameter_list|,
specifier|const
name|int
parameter_list|,
specifier|const
name|int
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
comment|/* _SYS_ZFS_IOCTL_COMPAT_H */
end_comment

end_unit

