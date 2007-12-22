begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_SYSCTL_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_SYSCTL_H__
end_define

begin_comment
comment|/*  * Tunable xfs parameters  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_sysctl_val
block|{
name|int
name|min
decl_stmt|;
name|int
name|val
decl_stmt|;
name|int
name|max
decl_stmt|;
block|}
name|xfs_sysctl_val_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_param
block|{
name|xfs_sysctl_val_t
name|refcache_size
decl_stmt|;
comment|/* Size of NFS reference cache.      */
name|xfs_sysctl_val_t
name|refcache_purge
decl_stmt|;
comment|/* # of entries to purge each time.  */
name|xfs_sysctl_val_t
name|restrict_chown
decl_stmt|;
comment|/* Root/non-root can give away files.*/
name|xfs_sysctl_val_t
name|sgid_inherit
decl_stmt|;
comment|/* Inherit S_ISGID if process' GID is 					 * not a member of parent dir GID. */
name|xfs_sysctl_val_t
name|symlink_mode
decl_stmt|;
comment|/* Link creat mode affected by umask */
name|xfs_sysctl_val_t
name|panic_mask
decl_stmt|;
comment|/* bitmask to cause panic on errors. */
name|xfs_sysctl_val_t
name|error_level
decl_stmt|;
comment|/* Degree of reporting for problems  */
name|xfs_sysctl_val_t
name|syncd_timer
decl_stmt|;
comment|/* Interval between xfssyncd wakeups */
name|xfs_sysctl_val_t
name|stats_clear
decl_stmt|;
comment|/* Reset all XFS statistics to zero. */
name|xfs_sysctl_val_t
name|probe_dmapi
decl_stmt|;
comment|/* probe for DMAPI module on mount. */
name|xfs_sysctl_val_t
name|probe_ioops
decl_stmt|;
comment|/* probe for an IO module on mount. */
name|xfs_sysctl_val_t
name|probe_quota
decl_stmt|;
comment|/* probe for quota module on mount. */
name|xfs_sysctl_val_t
name|inherit_sync
decl_stmt|;
comment|/* Inherit the "sync" inode flag. */
name|xfs_sysctl_val_t
name|inherit_nodump
decl_stmt|;
comment|/* Inherit the "nodump" inode flag. */
name|xfs_sysctl_val_t
name|inherit_noatim
decl_stmt|;
comment|/* Inherit the "noatime" inode flag. */
name|xfs_sysctl_val_t
name|xfs_buf_timer
decl_stmt|;
comment|/* Interval between xfsbufd wakeups. */
name|xfs_sysctl_val_t
name|xfs_buf_age
decl_stmt|;
comment|/* Metadata buffer age before flush. */
name|xfs_sysctl_val_t
name|inherit_nosym
decl_stmt|;
comment|/* Inherit the "nosymlinks" flag. */
name|xfs_sysctl_val_t
name|rotorstep
decl_stmt|;
comment|/* inode32 AG rotoring control knob */
block|}
name|xfs_param_t
typedef|;
end_typedef

begin_comment
comment|/*  * xfs_error_level:  *  * How much error reporting will be done when internal problems are  * encountered.  These problems normally return an EFSCORRUPTED to their  * caller, with no other information reported.  *  * 0	No error reports  * 1	Report EFSCORRUPTED errors that will cause a filesystem shutdown  * 5	Report all EFSCORRUPTED errors (all of the above errors, plus any  *	additional errors that are known to not cause shutdowns)  *  * xfs_panic_mask bit 0x8 turns the error reports into panics  */
end_comment

begin_enum
enum|enum
block|{
comment|/* XFS_REFCACHE_SIZE = 1 */
comment|/* XFS_REFCACHE_PURGE = 2 */
name|XFS_RESTRICT_CHOWN
init|=
literal|3
block|,
name|XFS_SGID_INHERIT
init|=
literal|4
block|,
name|XFS_SYMLINK_MODE
init|=
literal|5
block|,
name|XFS_PANIC_MASK
init|=
literal|6
block|,
name|XFS_ERRLEVEL
init|=
literal|7
block|,
name|XFS_SYNCD_TIMER
init|=
literal|8
block|,
name|XFS_PROBE_DMAPI
init|=
literal|9
block|,
name|XFS_PROBE_IOOPS
init|=
literal|10
block|,
name|XFS_PROBE_QUOTA
init|=
literal|11
block|,
name|XFS_STATS_CLEAR
init|=
literal|12
block|,
name|XFS_INHERIT_SYNC
init|=
literal|13
block|,
name|XFS_INHERIT_NODUMP
init|=
literal|14
block|,
name|XFS_INHERIT_NOATIME
init|=
literal|15
block|,
name|XFS_BUF_TIMER
init|=
literal|16
block|,
name|XFS_BUF_AGE
init|=
literal|17
block|,
comment|/* XFS_IO_BYPASS = 18 */
name|XFS_INHERIT_NOSYM
init|=
literal|19
block|,
name|XFS_ROTORSTEP
init|=
literal|20
block|, }
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|xfs_param_t
name|xfs_params
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_SYSCTL
end_ifdef

begin_function_decl
specifier|extern
name|void
name|xfs_sysctl_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_sysctl_unregister
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|xfs_sysctl_register
parameter_list|()
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|xfs_sysctl_unregister
parameter_list|()
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_SYSCTL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_SYSCTL_H__ */
end_comment

end_unit

