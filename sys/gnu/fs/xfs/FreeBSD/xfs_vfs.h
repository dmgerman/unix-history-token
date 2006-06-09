begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_VFS_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_VFS_H__
end_define

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|"xfs_fs.h"
end_include

begin_struct_decl
struct_decl|struct
name|fid
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|cred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_vnode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|statfs
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_mount_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mount
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|statfs
name|xfs_statfs_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_vfs
block|{
name|u_int
name|vfs_flag
decl_stmt|;
comment|/* flags */
name|xfs_fsid_t
name|vfs_fsid
decl_stmt|;
comment|/* file system ID */
name|xfs_fsid_t
modifier|*
name|vfs_altfsid
decl_stmt|;
comment|/* An ID fixed for life of FS */
name|bhv_head_t
name|vfs_bh
decl_stmt|;
comment|/* head of vfs behavior chain */
name|struct
name|mount
modifier|*
name|vfs_mp
decl_stmt|;
comment|/* FreeBSD mount struct */
block|}
name|xfs_vfs_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MNTTOXVFS
parameter_list|(
name|mp
parameter_list|)
value|((struct xfs_vfs*)(mp)->mnt_data)
end_define

begin_define
define|#
directive|define
name|XVFSTOMNT
parameter_list|(
name|vfs
parameter_list|)
value|((vfs)->vfs_mp)
end_define

begin_define
define|#
directive|define
name|vfs_fbhv
value|vfs_bh.bh_first
end_define

begin_comment
comment|/* 1st on vfs behavior chain */
end_comment

begin_define
define|#
directive|define
name|bhvtovfs
parameter_list|(
name|bdp
parameter_list|)
value|( (struct xfs_vfs *)BHV_VOBJ(bdp) )
end_define

begin_define
define|#
directive|define
name|bhvtovfsops
parameter_list|(
name|bdp
parameter_list|)
value|( (struct xvfsops *)BHV_OPS(bdp) )
end_define

begin_define
define|#
directive|define
name|VFS_BHVHEAD
parameter_list|(
name|vfs
parameter_list|)
value|(&(vfs)->vfs_bh )
end_define

begin_define
define|#
directive|define
name|VFS_REMOVEBHV
parameter_list|(
name|vfs
parameter_list|,
name|bdp
parameter_list|)
value|( bhv_remove(VFS_BHVHEAD(vfs), bdp) )
end_define

begin_define
define|#
directive|define
name|VFS_POSITION_BASE
value|BHV_POSITION_BASE
end_define

begin_comment
comment|/* chain bottom */
end_comment

begin_define
define|#
directive|define
name|VFS_POSITION_TOP
value|BHV_POSITION_TOP
end_define

begin_comment
comment|/* chain top */
end_comment

begin_define
define|#
directive|define
name|VFS_POSITION_INVALID
value|BHV_POSITION_INVALID
end_define

begin_comment
comment|/* invalid pos. num */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|VFS_BHV_UNKNOWN
block|,
comment|/* not specified */
name|VFS_BHV_XFS
block|,
comment|/* xfs */
name|VFS_BHV_DM
block|,
comment|/* data migration */
name|VFS_BHV_QM
block|,
comment|/* quota manager */
name|VFS_BHV_IO
block|,
comment|/* IO path */
name|VFS_BHV_END
comment|/* housekeeping end-of-range */
block|}
name|vfs_bhv_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VFS_POSITION_XFS
value|(BHV_POSITION_BASE)
end_define

begin_define
define|#
directive|define
name|VFS_POSITION_DM
value|(VFS_POSITION_BASE+10)
end_define

begin_define
define|#
directive|define
name|VFS_POSITION_QM
value|(VFS_POSITION_BASE+20)
end_define

begin_define
define|#
directive|define
name|VFS_POSITION_IO
value|(VFS_POSITION_BASE+30)
end_define

begin_define
define|#
directive|define
name|VFS_RDONLY
value|0x0001
end_define

begin_comment
comment|/* read-only vfs */
end_comment

begin_define
define|#
directive|define
name|VFS_GRPID
value|0x0002
end_define

begin_comment
comment|/* group-ID assigned from directory */
end_comment

begin_define
define|#
directive|define
name|VFS_DMI
value|0x0004
end_define

begin_comment
comment|/* filesystem has the DMI enabled */
end_comment

begin_define
define|#
directive|define
name|VFS_32BITINODES
value|0x0008
end_define

begin_comment
comment|/* do not use inums above 32 bits */
end_comment

begin_define
define|#
directive|define
name|VFS_END
value|0x0008
end_define

begin_comment
comment|/* max flag */
end_comment

begin_define
define|#
directive|define
name|SYNC_ATTR
value|0x0001
end_define

begin_comment
comment|/* sync attributes */
end_comment

begin_define
define|#
directive|define
name|SYNC_CLOSE
value|0x0002
end_define

begin_comment
comment|/* close file system down */
end_comment

begin_define
define|#
directive|define
name|SYNC_DELWRI
value|0x0004
end_define

begin_comment
comment|/* look at delayed writes */
end_comment

begin_define
define|#
directive|define
name|SYNC_WAIT
value|0x0008
end_define

begin_comment
comment|/* wait for i/o to complete */
end_comment

begin_define
define|#
directive|define
name|SYNC_BDFLUSH
value|0x0010
end_define

begin_comment
comment|/* BDFLUSH is calling -- don't block */
end_comment

begin_define
define|#
directive|define
name|SYNC_FSDATA
value|0x0020
end_define

begin_comment
comment|/* flush fs data (e.g. superblocks) */
end_comment

begin_define
define|#
directive|define
name|SYNC_REFCACHE
value|0x0040
end_define

begin_comment
comment|/* prune some of the nfs ref cache */
end_comment

begin_define
define|#
directive|define
name|SYNC_REMOUNT
value|0x0080
end_define

begin_comment
comment|/* remount readonly, no dummy LRs */
end_comment

begin_define
define|#
directive|define
name|SYNC_QUIESCE
value|0x0100
end_define

begin_comment
comment|/* quiesce filesystem for a snapshot */
end_comment

begin_define
define|#
directive|define
name|IGET_NOALLOC
value|0x0001
end_define

begin_comment
comment|/* vfs_get_inode may return NULL */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xvfs_mount_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|struct
name|xfs_mount_args
modifier|*
parameter_list|,
name|struct
name|cred
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xvfs_parseargs_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|xfs_mount_args
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xvfs_showargs_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|struct
name|sbuf
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xvfs_unmount_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|cred
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xvfs_mntupdate_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|struct
name|xfs_mount_args
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xvfs_root_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|struct
name|xfs_vnode
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xvfs_statvfs_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|xfs_statfs_t
modifier|*
parameter_list|,
name|struct
name|xfs_vnode
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xvfs_sync_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|cred
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xvfs_vget_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|struct
name|xfs_vnode
modifier|*
modifier|*
parameter_list|,
name|struct
name|fid
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xvfs_dmapiops_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xvfs_quotactl_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xvfs_init_vnode_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|struct
name|xfs_vnode
modifier|*
parameter_list|,
name|bhv_desc_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xvfs_force_shutdown_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|inode
modifier|*
function_decl|(
modifier|*
name|xvfs_get_inode_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|xfs_ino_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xvfs_freeze_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xvfsops
block|{
name|bhv_position_t
name|xvfs_position
decl_stmt|;
comment|/* behavior chain position */
name|xvfs_mount_t
name|xvfs_mount
decl_stmt|;
comment|/* mount file system */
name|xvfs_parseargs_t
name|xvfs_parseargs
decl_stmt|;
comment|/* parse mount options */
name|xvfs_showargs_t
name|xvfs_showargs
decl_stmt|;
comment|/* unparse mount options */
name|xvfs_unmount_t
name|xvfs_unmount
decl_stmt|;
comment|/* unmount file system */
name|xvfs_mntupdate_t
name|xvfs_mntupdate
decl_stmt|;
comment|/* update file system options */
name|xvfs_root_t
name|xvfs_root
decl_stmt|;
comment|/* get root vnode */
name|xvfs_statvfs_t
name|xvfs_statvfs
decl_stmt|;
comment|/* file system statistics */
name|xvfs_sync_t
name|xvfs_sync
decl_stmt|;
comment|/* flush files */
name|xvfs_vget_t
name|xvfs_vget
decl_stmt|;
comment|/* get vnode from fid */
name|xvfs_dmapiops_t
name|xvfs_dmapiops
decl_stmt|;
comment|/* data migration */
name|xvfs_quotactl_t
name|xvfs_quotactl
decl_stmt|;
comment|/* disk quota */
name|xvfs_get_inode_t
name|xvfs_get_inode
decl_stmt|;
comment|/* bhv specific iget */
name|xvfs_init_vnode_t
name|xvfs_init_vnode
decl_stmt|;
comment|/* initialize a new vnode */
name|xvfs_force_shutdown_t
name|xvfs_force_shutdown
decl_stmt|;
comment|/* crash and burn */
name|xvfs_freeze_t
name|xvfs_freeze
decl_stmt|;
comment|/* freeze fs for snapshot */
block|}
name|xvfsops_t
typedef|;
end_typedef

begin_comment
comment|/*  * VFS's.  Operates on vfs structure pointers (starts at bhv head).  */
end_comment

begin_define
define|#
directive|define
name|VHEAD
parameter_list|(
name|v
parameter_list|)
value|((v)->vfs_fbhv)
end_define

begin_define
define|#
directive|define
name|XVFS_MOUNT
parameter_list|(
name|v
parameter_list|,
name|ma
parameter_list|,
name|cr
parameter_list|,
name|rv
parameter_list|)
value|((rv) = xvfs_mount(VHEAD(v), ma,cr))
end_define

begin_define
define|#
directive|define
name|XVFS_PARSEARGS
parameter_list|(
name|v
parameter_list|,
name|o
parameter_list|,
name|ma
parameter_list|,
name|f
parameter_list|,
name|rv
parameter_list|)
value|((rv) = xvfs_parseargs(VHEAD(v), o,ma,f))
end_define

begin_define
define|#
directive|define
name|XVFS_SHOWARGS
parameter_list|(
name|v
parameter_list|,
name|m
parameter_list|,
name|rv
parameter_list|)
value|((rv) = xvfs_showargs(VHEAD(v), m))
end_define

begin_define
define|#
directive|define
name|XVFS_UNMOUNT
parameter_list|(
name|v
parameter_list|,
name|f
parameter_list|,
name|cr
parameter_list|,
name|rv
parameter_list|)
value|((rv) = xvfs_unmount(VHEAD(v), f,cr))
end_define

begin_define
define|#
directive|define
name|XVFS_MNTUPDATE
parameter_list|(
name|v
parameter_list|,
name|fl
parameter_list|,
name|args
parameter_list|,
name|rv
parameter_list|)
value|((rv) = xvfs_mntupdate(VHEAD(v), fl, args))
end_define

begin_define
define|#
directive|define
name|XVFS_ROOT
parameter_list|(
name|v
parameter_list|,
name|vpp
parameter_list|,
name|rv
parameter_list|)
value|((rv) = xvfs_root(VHEAD(v), vpp))
end_define

begin_define
define|#
directive|define
name|XVFS_STATVFS
parameter_list|(
name|v
parameter_list|,
name|sp
parameter_list|,
name|vp
parameter_list|,
name|rv
parameter_list|)
value|((rv) = xvfs_statvfs(VHEAD(v), sp,vp))
end_define

begin_define
define|#
directive|define
name|XVFS_SYNC
parameter_list|(
name|v
parameter_list|,
name|flag
parameter_list|,
name|cr
parameter_list|,
name|rv
parameter_list|)
value|((rv) = xvfs_sync(VHEAD(v), flag,cr))
end_define

begin_define
define|#
directive|define
name|XVFS_VGET
parameter_list|(
name|v
parameter_list|,
name|vpp
parameter_list|,
name|fidp
parameter_list|,
name|rv
parameter_list|)
value|((rv) = xvfs_vget(VHEAD(v), vpp,fidp))
end_define

begin_define
define|#
directive|define
name|XVFS_DMAPIOPS
parameter_list|(
name|v
parameter_list|,
name|p
parameter_list|,
name|rv
parameter_list|)
value|((rv) = xvfs_dmapiops(VHEAD(v), p))
end_define

begin_define
define|#
directive|define
name|XVFS_QUOTACTL
parameter_list|(
name|v
parameter_list|,
name|c
parameter_list|,
name|id
parameter_list|,
name|p
parameter_list|,
name|rv
parameter_list|)
value|((rv) = xvfs_quotactl(VHEAD(v), c,id,p))
end_define

begin_define
define|#
directive|define
name|XVFS_GET_INODE
parameter_list|(
name|v
parameter_list|,
name|ino
parameter_list|,
name|fl
parameter_list|)
value|( xvfs_get_inode(VHEAD(v), ino,fl) )
end_define

begin_define
define|#
directive|define
name|XVFS_INIT_VNODE
parameter_list|(
name|v
parameter_list|,
name|vp
parameter_list|,
name|b
parameter_list|,
name|ul
parameter_list|)
value|( xvfs_init_vnode(VHEAD(v), vp,b,ul) )
end_define

begin_define
define|#
directive|define
name|XVFS_FORCE_SHUTDOWN
parameter_list|(
name|v
parameter_list|,
name|fl
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
value|( xvfs_force_shutdown(VHEAD(v), fl,f,l) )
end_define

begin_comment
comment|/*  * PVFS's.  Operates on behavior descriptor pointers.  */
end_comment

begin_define
define|#
directive|define
name|PVFS_MOUNT
parameter_list|(
name|b
parameter_list|,
name|ma
parameter_list|,
name|cr
parameter_list|,
name|rv
parameter_list|)
value|((rv) = xvfs_mount(b, ma,cr))
end_define

begin_define
define|#
directive|define
name|PVFS_PARSEARGS
parameter_list|(
name|b
parameter_list|,
name|o
parameter_list|,
name|ma
parameter_list|,
name|f
parameter_list|,
name|rv
parameter_list|)
value|((rv) = xvfs_parseargs(b, o,ma,f))
end_define

begin_define
define|#
directive|define
name|PVFS_SHOWARGS
parameter_list|(
name|b
parameter_list|,
name|m
parameter_list|,
name|rv
parameter_list|)
value|((rv) = xvfs_showargs(b, m))
end_define

begin_define
define|#
directive|define
name|PVFS_UNMOUNT
parameter_list|(
name|b
parameter_list|,
name|f
parameter_list|,
name|cr
parameter_list|,
name|rv
parameter_list|)
value|((rv) = xvfs_unmount(b, f,cr))
end_define

begin_define
define|#
directive|define
name|PVFS_MNTUPDATE
parameter_list|(
name|b
parameter_list|,
name|fl
parameter_list|,
name|args
parameter_list|,
name|rv
parameter_list|)
value|((rv) = xvfs_mntupdate(b, fl, args))
end_define

begin_define
define|#
directive|define
name|PVFS_ROOT
parameter_list|(
name|b
parameter_list|,
name|vpp
parameter_list|,
name|rv
parameter_list|)
value|((rv) = xvfs_root(b, vpp))
end_define

begin_define
define|#
directive|define
name|PVFS_STATVFS
parameter_list|(
name|b
parameter_list|,
name|sp
parameter_list|,
name|vp
parameter_list|,
name|rv
parameter_list|)
value|((rv) = xvfs_statvfs(b, sp,vp))
end_define

begin_define
define|#
directive|define
name|PVFS_SYNC
parameter_list|(
name|b
parameter_list|,
name|flag
parameter_list|,
name|cr
parameter_list|,
name|rv
parameter_list|)
value|((rv) = xvfs_sync(b, flag,cr))
end_define

begin_define
define|#
directive|define
name|PVFS_VGET
parameter_list|(
name|b
parameter_list|,
name|vpp
parameter_list|,
name|fidp
parameter_list|,
name|rv
parameter_list|)
value|((rv) = xvfs_vget(b, vpp,fidp))
end_define

begin_define
define|#
directive|define
name|PVFS_DMAPIOPS
parameter_list|(
name|b
parameter_list|,
name|p
parameter_list|,
name|rv
parameter_list|)
value|((rv) = xvfs_dmapiops(b, p))
end_define

begin_define
define|#
directive|define
name|PVFS_QUOTACTL
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|,
name|id
parameter_list|,
name|p
parameter_list|,
name|rv
parameter_list|)
value|((rv) = xvfs_quotactl(b, c,id,p))
end_define

begin_define
define|#
directive|define
name|PVFS_GET_INODE
parameter_list|(
name|b
parameter_list|,
name|ino
parameter_list|,
name|fl
parameter_list|)
value|( xvfs_get_inode(b, ino,fl) )
end_define

begin_define
define|#
directive|define
name|PVFS_INIT_VNODE
parameter_list|(
name|b
parameter_list|,
name|vp
parameter_list|,
name|b2
parameter_list|,
name|ul
parameter_list|)
value|( xvfs_init_vnode(b, vp,b2,ul) )
end_define

begin_define
define|#
directive|define
name|PVFS_FORCE_SHUTDOWN
parameter_list|(
name|b
parameter_list|,
name|fl
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
value|( xvfs_force_shutdown(b, fl,f,l) )
end_define

begin_function_decl
specifier|extern
name|int
name|xvfs_mount
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|struct
name|xfs_mount_args
modifier|*
parameter_list|,
name|struct
name|cred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xvfs_parseargs
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|xfs_mount_args
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xvfs_showargs
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|struct
name|sbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xvfs_unmount
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|cred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xvfs_mntupdate
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|struct
name|xfs_mount_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xvfs_root
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|struct
name|xfs_vnode
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xvfs_statvfs
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|xfs_statfs_t
modifier|*
parameter_list|,
name|struct
name|xfs_vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xvfs_sync
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|cred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xvfs_vget
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|struct
name|xfs_vnode
modifier|*
modifier|*
parameter_list|,
name|struct
name|fid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xvfs_dmapiops
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xvfs_quotactl
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|inode
modifier|*
name|xvfs_get_inode
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|xfs_ino_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xvfs_init_vnode
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|struct
name|xfs_vnode
modifier|*
parameter_list|,
name|bhv_desc_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xvfs_force_shutdown
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|XFS_DMOPS
value|"xfs_dm_operations"
end_define

begin_comment
comment|/* Data Migration */
end_comment

begin_define
define|#
directive|define
name|XFS_QMOPS
value|"xfs_qm_operations"
end_define

begin_comment
comment|/* Quota Manager  */
end_comment

begin_define
define|#
directive|define
name|XFS_IOOPS
value|"xfs_io_operations"
end_define

begin_comment
comment|/* I/O subsystem  */
end_comment

begin_define
define|#
directive|define
name|XFS_DM_MODULE
value|"xfs_dmapi"
end_define

begin_define
define|#
directive|define
name|XFS_QM_MODULE
value|"xfs_quota"
end_define

begin_define
define|#
directive|define
name|XFS_IO_MODULE
value|"xfs_ioops"
end_define

begin_typedef
typedef|typedef
struct|struct
name|bhv_vfsops
block|{
name|struct
name|xvfsops
name|bhv_common
decl_stmt|;
name|void
modifier|*
name|bhv_custom
decl_stmt|;
block|}
name|bhv_vfsops_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|bhv_module
block|{
name|bhv_desc_t
name|bm_desc
decl_stmt|;
specifier|const
name|char
modifier|*
name|bm_name
decl_stmt|;
name|bhv_vfsops_t
modifier|*
name|bm_ops
decl_stmt|;
block|}
name|bhv_module_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|vfs_bhv_lookup
parameter_list|(
name|v
parameter_list|,
name|id
parameter_list|)
value|( bhv_lookup_range(&(v)->vfs_bh, (id), (id)) )
end_define

begin_define
define|#
directive|define
name|vfs_bhv_custom
parameter_list|(
name|b
parameter_list|)
value|( ((bhv_vfsops_t *)BHV_OPS(b))->bhv_custom )
end_define

begin_define
define|#
directive|define
name|vfs_bhv_set_custom
parameter_list|(
name|b
parameter_list|,
name|o
parameter_list|)
value|( (b)->bhv_custom = (void *)(o))
end_define

begin_define
define|#
directive|define
name|vfs_bhv_clr_custom
parameter_list|(
name|b
parameter_list|)
value|( (b)->bhv_custom = NULL )
end_define

begin_function_decl
specifier|extern
name|xfs_vfs_t
modifier|*
name|vfs_allocate
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vfs_deallocate
parameter_list|(
name|xfs_vfs_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vfs_insertops
parameter_list|(
name|xfs_vfs_t
modifier|*
parameter_list|,
name|bhv_vfsops_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vfs_insertbhv
parameter_list|(
name|xfs_vfs_t
modifier|*
parameter_list|,
name|bhv_desc_t
modifier|*
parameter_list|,
name|xvfsops_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|bhv_lookup_module
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|)
value|( (m) ? \ 				inter_module_get_request(n, m) : \ 				inter_module_get(n) )
end_define

begin_define
define|#
directive|define
name|bhv_remove_module
parameter_list|(
name|n
parameter_list|)
value|inter_module_put(n)
end_define

begin_define
define|#
directive|define
name|bhv_module_init
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|,
name|op
parameter_list|)
value|inter_module_register(n,m,op)
end_define

begin_define
define|#
directive|define
name|bhv_module_exit
parameter_list|(
name|n
parameter_list|)
value|inter_module_unregister(n)
end_define

begin_function_decl
specifier|extern
name|void
name|bhv_insert_all_vfsops
parameter_list|(
name|struct
name|xfs_vfs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bhv_remove_all_vfsops
parameter_list|(
name|struct
name|xfs_vfs
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bhv_remove_vfsops
parameter_list|(
name|struct
name|xfs_vfs
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_VFS_H__ */
end_comment

end_unit

