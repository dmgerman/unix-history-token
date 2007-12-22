begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  *  * Portions Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_VNODE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_VNODE_H__
end_define

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/namei.h>
end_include

begin_struct_decl
struct_decl|struct
name|xfs_iomap
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|componentname
name|vname_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|bhv_head_t
name|vn_bhv_head_t
typedef|;
end_typedef

begin_comment
comment|/*  * MP locking protocols:  *	v_flag, v_vfsp				VN_LOCK/VN_UNLOCK  *	v_type					read-only or fs-dependent  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_vnode
block|{
name|__u32
name|v_flag
decl_stmt|;
comment|/* vnode flags (see below) */
name|struct
name|xfs_vfs
modifier|*
name|v_vfsp
decl_stmt|;
comment|/* ptr to containing VFS */
name|xfs_ino_t
name|v_number
decl_stmt|;
comment|/* in-core vnode number */
name|vn_bhv_head_t
name|v_bh
decl_stmt|;
comment|/* behavior head */
name|struct
name|vnode
modifier|*
name|v_vnode
decl_stmt|;
comment|/* FreeBSD vnode */
name|struct
name|xfs_inode
modifier|*
name|v_inode
decl_stmt|;
comment|/* XFS inode */
ifdef|#
directive|ifdef
name|XFS_VNODE_TRACE
name|struct
name|ktrace
modifier|*
name|v_trace
decl_stmt|;
comment|/* trace header structure    */
endif|#
directive|endif
block|}
name|xfs_vnode_t
typedef|;
end_typedef

begin_comment
comment|/* vnode types */
end_comment

begin_define
define|#
directive|define
name|VN_ISLNK
parameter_list|(
name|vp
parameter_list|)
value|((vp)->v_vnode->v_type& VLNK)
end_define

begin_define
define|#
directive|define
name|VN_ISREG
parameter_list|(
name|vp
parameter_list|)
value|((vp)->v_vnode->v_type& VREG)
end_define

begin_define
define|#
directive|define
name|VN_ISDIR
parameter_list|(
name|vp
parameter_list|)
value|((vp)->v_vnode->v_type& VDIR)
end_define

begin_define
define|#
directive|define
name|VN_ISCHR
parameter_list|(
name|vp
parameter_list|)
value|((vp)->v_vnode->v_type& VCHR)
end_define

begin_define
define|#
directive|define
name|VN_ISBLK
parameter_list|(
name|vp
parameter_list|)
value|((vp)->v_vnode->v_type& VBLK)
end_define

begin_define
define|#
directive|define
name|VN_BAD
parameter_list|(
name|vp
parameter_list|)
value|((vp)->v_vnode->v_type& VBAD)
end_define

begin_define
define|#
directive|define
name|v_fbhv
value|v_bh.bh_first
end_define

begin_comment
comment|/* first behavior */
end_comment

begin_define
define|#
directive|define
name|v_fops
value|v_bh.bh_first->bd_ops
end_define

begin_comment
comment|/* first behavior ops */
end_comment

begin_define
define|#
directive|define
name|VNODE_POSITION_BASE
value|BHV_POSITION_BASE
end_define

begin_comment
comment|/* chain bottom */
end_comment

begin_define
define|#
directive|define
name|VNODE_POSITION_TOP
value|BHV_POSITION_TOP
end_define

begin_comment
comment|/* chain top */
end_comment

begin_define
define|#
directive|define
name|VNODE_POSITION_INVALID
value|BHV_POSITION_INVALID
end_define

begin_comment
comment|/* invalid pos. num */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|VN_BHV_UNKNOWN
block|,
comment|/* not specified */
name|VN_BHV_XFS
block|,
comment|/* xfs */
name|VN_BHV_DM
block|,
comment|/* data migration */
name|VN_BHV_QM
block|,
comment|/* quota manager */
name|VN_BHV_IO
block|,
comment|/* IO path */
name|VN_BHV_END
comment|/* housekeeping end-of-range */
block|}
name|vn_bhv_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VNODE_POSITION_XFS
value|(VNODE_POSITION_BASE)
end_define

begin_define
define|#
directive|define
name|VNODE_POSITION_DM
value|(VNODE_POSITION_BASE+10)
end_define

begin_define
define|#
directive|define
name|VNODE_POSITION_QM
value|(VNODE_POSITION_BASE+20)
end_define

begin_define
define|#
directive|define
name|VNODE_POSITION_IO
value|(VNODE_POSITION_BASE+30)
end_define

begin_define
define|#
directive|define
name|VPTOXFSVP
parameter_list|(
name|vp
parameter_list|)
value|((struct xfs_vnode *)(vp)->v_data)
end_define

begin_comment
comment|/*  * Macros for dealing with the behavior descriptor inside of the vnode.  */
end_comment

begin_define
define|#
directive|define
name|BHV_TO_VNODE
parameter_list|(
name|bdp
parameter_list|)
value|((xfs_vnode_t *)BHV_VOBJ(bdp))
end_define

begin_define
define|#
directive|define
name|BHV_TO_VNODE_NULL
parameter_list|(
name|bdp
parameter_list|)
value|((xfs_vnode_t *)BHV_VOBJNULL(bdp))
end_define

begin_define
define|#
directive|define
name|VN_BHV_HEAD
parameter_list|(
name|vp
parameter_list|)
value|((bhv_head_t *)(&((vp)->v_bh)))
end_define

begin_define
define|#
directive|define
name|vn_bhv_head_init
parameter_list|(
name|bhp
parameter_list|,
name|name
parameter_list|)
value|bhv_head_init(bhp,name)
end_define

begin_define
define|#
directive|define
name|vn_bhv_remove
parameter_list|(
name|bhp
parameter_list|,
name|bdp
parameter_list|)
value|bhv_remove(bhp,bdp)
end_define

begin_define
define|#
directive|define
name|vn_bhv_lookup
parameter_list|(
name|bhp
parameter_list|,
name|ops
parameter_list|)
value|bhv_lookup(bhp,ops)
end_define

begin_define
define|#
directive|define
name|vn_bhv_lookup_unlocked
parameter_list|(
name|bhp
parameter_list|,
name|ops
parameter_list|)
value|bhv_lookup_unlocked(bhp,ops)
end_define

begin_comment
comment|/*  * Vnode to Linux inode mapping.  */
end_comment

begin_define
define|#
directive|define
name|LINVFS_GET_VP
parameter_list|(
name|inode
parameter_list|)
value|((xfs_vnode_t *)NULL)
end_define

begin_define
define|#
directive|define
name|LINVFS_GET_IP
parameter_list|(
name|vp
parameter_list|)
value|((xfs_inode_t *)NULL)
end_define

begin_comment
comment|/*  * Vnode flags.  */
end_comment

begin_define
define|#
directive|define
name|VINACT
value|0x1
end_define

begin_comment
comment|/* vnode is being inactivated	*/
end_comment

begin_define
define|#
directive|define
name|VRECLM
value|0x2
end_define

begin_comment
comment|/* vnode is being reclaimed	*/
end_comment

begin_define
define|#
directive|define
name|VWAIT
value|0x4
end_define

begin_comment
comment|/* waiting for VINACT/VRECLM to end */
end_comment

begin_define
define|#
directive|define
name|VMODIFIED
value|0x8
end_define

begin_comment
comment|/* XFS inode state possibly differs */
end_comment

begin_comment
comment|/* to the Linux inode state.	*/
end_comment

begin_comment
comment|/*  * Values for the VOP_RWLOCK and VOP_RWUNLOCK flags parameter.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|vrwlock
block|{
name|VRWLOCK_NONE
block|,
name|VRWLOCK_READ
block|,
name|VRWLOCK_WRITE
block|,
name|VRWLOCK_WRITE_DIRECT
block|,
name|VRWLOCK_TRY_READ
block|,
name|VRWLOCK_TRY_WRITE
block|}
name|vrwlock_t
typedef|;
end_typedef

begin_comment
comment|/*  * Return values for VOP_INACTIVE.  A return value of  * VN_INACTIVE_NOCACHE implies that the file system behavior  * has disassociated its state and bhv_desc_t from the vnode.  */
end_comment

begin_define
define|#
directive|define
name|VN_INACTIVE_CACHE
value|0
end_define

begin_define
define|#
directive|define
name|VN_INACTIVE_NOCACHE
value|1
end_define

begin_comment
comment|/*  * Values for the cmd code given to VOP_VNODE_CHANGE.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|vchange
block|{
name|VCHANGE_FLAGS_FRLOCKS
init|=
literal|0
block|,
name|VCHANGE_FLAGS_ENF_LOCKING
init|=
literal|1
block|,
name|VCHANGE_FLAGS_TRUNCATED
init|=
literal|2
block|,
name|VCHANGE_FLAGS_PAGE_DIRTY
init|=
literal|3
block|,
name|VCHANGE_FLAGS_IOEXCL_COUNT
init|=
literal|4
block|}
name|vchange_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|file_lock
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_iomap_s
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_vattr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|attrlist_cursor_kern
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_vop_open_t
function_decl|)
parameter_list|(
name|bhv_desc_t
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
name|ssize_t
function_decl|(
modifier|*
name|xfs_vop_read_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|uio_t
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
name|ssize_t
function_decl|(
modifier|*
name|xfs_vop_write_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|uio_t
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
name|xfs_vop_ioctl_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|struct
name|inode
modifier|*
parameter_list|,
name|struct
name|file
modifier|*
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_vop_getattr_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|struct
name|xfs_vattr
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
name|xfs_vop_setattr_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|struct
name|xfs_vattr
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
name|xfs_vop_access_t
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
name|xfs_vop_lookup_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|vname_t
modifier|*
parameter_list|,
name|xfs_vnode_t
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|xfs_vnode_t
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
name|xfs_vop_create_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|vname_t
modifier|*
parameter_list|,
name|struct
name|xfs_vattr
modifier|*
parameter_list|,
name|xfs_vnode_t
modifier|*
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
name|xfs_vop_remove_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|bhv_desc_t
modifier|*
parameter_list|,
name|vname_t
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
name|xfs_vop_link_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|xfs_vnode_t
modifier|*
parameter_list|,
name|vname_t
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
name|xfs_vop_rename_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|vname_t
modifier|*
parameter_list|,
name|xfs_vnode_t
modifier|*
parameter_list|,
name|vname_t
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
name|xfs_vop_mkdir_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|vname_t
modifier|*
parameter_list|,
name|struct
name|xfs_vattr
modifier|*
parameter_list|,
name|xfs_vnode_t
modifier|*
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
name|xfs_vop_rmdir_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|vname_t
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
name|xfs_vop_readdir_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|struct
name|cred
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_vop_symlink_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|vname_t
modifier|*
parameter_list|,
name|struct
name|xfs_vattr
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|xfs_vnode_t
modifier|*
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
name|xfs_vop_readlink_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|struct
name|uio
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
name|xfs_vop_fsync_t
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
parameter_list|,
name|xfs_off_t
parameter_list|,
name|xfs_off_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_vop_inactive_t
function_decl|)
parameter_list|(
name|bhv_desc_t
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
name|xfs_vop_fid2_t
function_decl|)
parameter_list|(
name|bhv_desc_t
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
name|xfs_vop_release_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_vop_rwlock_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|vrwlock_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xfs_vop_rwunlock_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|vrwlock_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_vop_frlock_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|file_lock
modifier|*
parameter_list|,
name|int
parameter_list|,
name|xfs_off_t
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
name|xfs_vop_bmap_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|xfs_off_t
parameter_list|,
name|ssize_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|xfs_iomap
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_vop_reclaim_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_vop_attr_get_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
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
name|xfs_vop_attr_set_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
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
name|xfs_vop_attr_remove_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
specifier|const
name|char
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
name|xfs_vop_attr_list_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|attrlist_cursor_kern
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
name|void
function_decl|(
modifier|*
name|xfs_vop_link_removed_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|xfs_vnode_t
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
name|xfs_vop_vnode_change_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|vchange_t
parameter_list|,
name|__psint_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xfs_vop_ptossvp_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|xfs_off_t
parameter_list|,
name|xfs_off_t
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
name|xfs_vop_pflushinvalvp_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|xfs_off_t
parameter_list|,
name|xfs_off_t
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
name|xfs_vop_pflushvp_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|xfs_off_t
parameter_list|,
name|xfs_off_t
parameter_list|,
name|uint64_t
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
name|xfs_vop_iflush_t
function_decl|)
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_vnodeops
block|{
name|bhv_position_t
name|vn_position
decl_stmt|;
comment|/* position within behavior chain */
name|xfs_vop_open_t
name|vop_open
decl_stmt|;
name|xfs_vop_read_t
name|vop_read
decl_stmt|;
name|xfs_vop_write_t
name|vop_write
decl_stmt|;
name|xfs_vop_ioctl_t
name|vop_ioctl
decl_stmt|;
name|xfs_vop_getattr_t
name|vop_getattr
decl_stmt|;
name|xfs_vop_setattr_t
name|vop_setattr
decl_stmt|;
name|xfs_vop_access_t
name|vop_access
decl_stmt|;
name|xfs_vop_lookup_t
name|vop_lookup
decl_stmt|;
name|xfs_vop_create_t
name|vop_create
decl_stmt|;
name|xfs_vop_remove_t
name|vop_remove
decl_stmt|;
name|xfs_vop_link_t
name|vop_link
decl_stmt|;
name|xfs_vop_rename_t
name|vop_rename
decl_stmt|;
name|xfs_vop_mkdir_t
name|vop_mkdir
decl_stmt|;
name|xfs_vop_rmdir_t
name|vop_rmdir
decl_stmt|;
name|xfs_vop_readdir_t
name|vop_readdir
decl_stmt|;
name|xfs_vop_symlink_t
name|vop_symlink
decl_stmt|;
name|xfs_vop_readlink_t
name|vop_readlink
decl_stmt|;
name|xfs_vop_fsync_t
name|vop_fsync
decl_stmt|;
name|xfs_vop_inactive_t
name|vop_inactive
decl_stmt|;
name|xfs_vop_fid2_t
name|vop_fid2
decl_stmt|;
name|xfs_vop_rwlock_t
name|vop_rwlock
decl_stmt|;
name|xfs_vop_rwunlock_t
name|vop_rwunlock
decl_stmt|;
name|xfs_vop_frlock_t
name|vop_frlock
decl_stmt|;
name|xfs_vop_bmap_t
name|vop_bmap
decl_stmt|;
name|xfs_vop_reclaim_t
name|vop_reclaim
decl_stmt|;
name|xfs_vop_attr_get_t
name|vop_attr_get
decl_stmt|;
name|xfs_vop_attr_set_t
name|vop_attr_set
decl_stmt|;
name|xfs_vop_attr_remove_t
name|vop_attr_remove
decl_stmt|;
name|xfs_vop_attr_list_t
name|vop_attr_list
decl_stmt|;
name|xfs_vop_link_removed_t
name|vop_link_removed
decl_stmt|;
name|xfs_vop_vnode_change_t
name|vop_vnode_change
decl_stmt|;
name|xfs_vop_ptossvp_t
name|vop_tosspages
decl_stmt|;
name|xfs_vop_pflushinvalvp_t
name|vop_flushinval_pages
decl_stmt|;
name|xfs_vop_pflushvp_t
name|vop_flush_pages
decl_stmt|;
name|xfs_vop_release_t
name|vop_release
decl_stmt|;
name|xfs_vop_iflush_t
name|vop_iflush
decl_stmt|;
block|}
name|xfs_vnodeops_t
typedef|;
end_typedef

begin_comment
comment|/*  * VOP's.  */
end_comment

begin_define
define|#
directive|define
name|_VOP_
parameter_list|(
name|op
parameter_list|,
name|vp
parameter_list|)
value|(*((xfs_vnodeops_t *)(vp)->v_fops)->op)
end_define

begin_define
define|#
directive|define
name|XVOP_READ
parameter_list|(
name|vp
parameter_list|,
name|uio
parameter_list|,
name|ioflags
parameter_list|,
name|cr
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_read, vp)((vp)->v_fbhv,uio,ioflags,cr)
end_define

begin_define
define|#
directive|define
name|XVOP_WRITE
parameter_list|(
name|vp
parameter_list|,
name|file
parameter_list|,
name|uio
parameter_list|,
name|ioflags
parameter_list|,
name|cr
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_write, vp)((vp)->v_fbhv,uio,ioflags,cr)
end_define

begin_define
define|#
directive|define
name|XVOP_BMAP
parameter_list|(
name|vp
parameter_list|,
name|of
parameter_list|,
name|sz
parameter_list|,
name|rw
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_bmap, vp)((vp)->v_fbhv,of,sz,rw,b,n)
end_define

begin_define
define|#
directive|define
name|XVOP_OPEN
parameter_list|(
name|vp
parameter_list|,
name|cr
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_open, vp)((vp)->v_fbhv, cr)
end_define

begin_define
define|#
directive|define
name|XVOP_GETATTR
parameter_list|(
name|vp
parameter_list|,
name|vap
parameter_list|,
name|f
parameter_list|,
name|cr
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_getattr, vp)((vp)->v_fbhv, vap, f, cr)
end_define

begin_define
define|#
directive|define
name|XVOP_SETATTR
parameter_list|(
name|vp
parameter_list|,
name|vap
parameter_list|,
name|f
parameter_list|,
name|cr
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_setattr, vp)((vp)->v_fbhv, vap, f, cr)
end_define

begin_define
define|#
directive|define
name|XVOP_ACCESS
parameter_list|(
name|vp
parameter_list|,
name|mode
parameter_list|,
name|cr
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_access, vp)((vp)->v_fbhv, mode, cr)
end_define

begin_define
define|#
directive|define
name|XVOP_LOOKUP
parameter_list|(
name|vp
parameter_list|,
name|d
parameter_list|,
name|vpp
parameter_list|,
name|f
parameter_list|,
name|rdir
parameter_list|,
name|cr
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_lookup, vp)((vp)->v_fbhv,d,vpp,f,rdir,cr)
end_define

begin_define
define|#
directive|define
name|XVOP_CREATE
parameter_list|(
name|dvp
parameter_list|,
name|d
parameter_list|,
name|vap
parameter_list|,
name|vpp
parameter_list|,
name|cr
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_create, dvp)((dvp)->v_fbhv,d,vap,vpp,cr)
end_define

begin_define
define|#
directive|define
name|XVOP_REMOVE
parameter_list|(
name|dvp
parameter_list|,
name|d
parameter_list|,
name|cr
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_remove, dvp)((dvp)->v_fbhv,d,cr)
end_define

begin_define
define|#
directive|define
name|XVOP_LINK
parameter_list|(
name|tdvp
parameter_list|,
name|fvp
parameter_list|,
name|d
parameter_list|,
name|cr
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_link, tdvp)((tdvp)->v_fbhv,fvp,d,cr)
end_define

begin_define
define|#
directive|define
name|XVOP_RENAME
parameter_list|(
name|fvp
parameter_list|,
name|fnm
parameter_list|,
name|tdvp
parameter_list|,
name|tnm
parameter_list|,
name|cr
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_rename, fvp)((fvp)->v_fbhv,fnm,tdvp,tnm,cr)
end_define

begin_define
define|#
directive|define
name|XVOP_MKDIR
parameter_list|(
name|dp
parameter_list|,
name|d
parameter_list|,
name|vap
parameter_list|,
name|vpp
parameter_list|,
name|cr
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_mkdir, dp)((dp)->v_fbhv,d,vap,vpp,cr)
end_define

begin_define
define|#
directive|define
name|XVOP_RMDIR
parameter_list|(
name|dp
parameter_list|,
name|d
parameter_list|,
name|cr
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_rmdir, dp)((dp)->v_fbhv,d,cr)
end_define

begin_define
define|#
directive|define
name|XVOP_READDIR
parameter_list|(
name|vp
parameter_list|,
name|uiop
parameter_list|,
name|cr
parameter_list|,
name|eofp
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_readdir, vp)((vp)->v_fbhv,uiop,cr,eofp)
end_define

begin_define
define|#
directive|define
name|XVOP_SYMLINK
parameter_list|(
name|dvp
parameter_list|,
name|d
parameter_list|,
name|vap
parameter_list|,
name|tnm
parameter_list|,
name|vpp
parameter_list|,
name|cr
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_symlink, dvp) ((dvp)->v_fbhv,d,vap,tnm,vpp,cr)
end_define

begin_define
define|#
directive|define
name|XVOP_READLINK
parameter_list|(
name|vp
parameter_list|,
name|uiop
parameter_list|,
name|fl
parameter_list|,
name|cr
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_readlink, vp)((vp)->v_fbhv,uiop,fl,cr)
end_define

begin_define
define|#
directive|define
name|XVOP_FSYNC
parameter_list|(
name|vp
parameter_list|,
name|f
parameter_list|,
name|cr
parameter_list|,
name|b
parameter_list|,
name|e
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_fsync, vp)((vp)->v_fbhv,f,cr,b,e)
end_define

begin_define
define|#
directive|define
name|XVOP_INACTIVE
parameter_list|(
name|vp
parameter_list|,
name|cr
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_inactive, vp)((vp)->v_fbhv, cr)
end_define

begin_define
define|#
directive|define
name|XVOP_RELEASE
parameter_list|(
name|vp
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_release, vp)((vp)->v_fbhv)
end_define

begin_define
define|#
directive|define
name|XVOP_FID2
parameter_list|(
name|vp
parameter_list|,
name|fidp
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_fid2, vp)((vp)->v_fbhv, fidp)
end_define

begin_define
define|#
directive|define
name|XVOP_RWLOCK
parameter_list|(
name|vp
parameter_list|,
name|i
parameter_list|)
define|\
value|(void)_VOP_(vop_rwlock, vp)((vp)->v_fbhv, i)
end_define

begin_define
define|#
directive|define
name|XVOP_RWLOCK_TRY
parameter_list|(
name|vp
parameter_list|,
name|i
parameter_list|)
define|\
value|_VOP_(vop_rwlock, vp)((vp)->v_fbhv, i)
end_define

begin_define
define|#
directive|define
name|XVOP_RWUNLOCK
parameter_list|(
name|vp
parameter_list|,
name|i
parameter_list|)
define|\
value|(void)_VOP_(vop_rwunlock, vp)((vp)->v_fbhv, i)
end_define

begin_define
define|#
directive|define
name|XVOP_FRLOCK
parameter_list|(
name|vp
parameter_list|,
name|c
parameter_list|,
name|fl
parameter_list|,
name|flags
parameter_list|,
name|offset
parameter_list|,
name|fr
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_frlock, vp)((vp)->v_fbhv,c,fl,flags,offset,fr)
end_define

begin_define
define|#
directive|define
name|XVOP_RECLAIM
parameter_list|(
name|vp
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_reclaim, vp)((vp)->v_fbhv)
end_define

begin_define
define|#
directive|define
name|XVOP_ATTR_GET
parameter_list|(
name|vp
parameter_list|,
name|name
parameter_list|,
name|val
parameter_list|,
name|vallenp
parameter_list|,
name|fl
parameter_list|,
name|cred
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_attr_get, vp)((vp)->v_fbhv,name,val,vallenp,fl,cred)
end_define

begin_define
define|#
directive|define
name|XVOP_ATTR_SET
parameter_list|(
name|vp
parameter_list|,
name|name
parameter_list|,
name|val
parameter_list|,
name|vallen
parameter_list|,
name|fl
parameter_list|,
name|cred
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_attr_set, vp)((vp)->v_fbhv,name,val,vallen,fl,cred)
end_define

begin_define
define|#
directive|define
name|XVOP_ATTR_REMOVE
parameter_list|(
name|vp
parameter_list|,
name|name
parameter_list|,
name|flags
parameter_list|,
name|cred
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_attr_remove, vp)((vp)->v_fbhv,name,flags,cred)
end_define

begin_define
define|#
directive|define
name|XVOP_ATTR_LIST
parameter_list|(
name|vp
parameter_list|,
name|buf
parameter_list|,
name|buflen
parameter_list|,
name|fl
parameter_list|,
name|cursor
parameter_list|,
name|cred
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_attr_list, vp)((vp)->v_fbhv,buf,buflen,fl,cursor,cred)
end_define

begin_define
define|#
directive|define
name|XVOP_LINK_REMOVED
parameter_list|(
name|vp
parameter_list|,
name|dvp
parameter_list|,
name|linkzero
parameter_list|)
define|\
value|(void)_VOP_(vop_link_removed, vp)((vp)->v_fbhv, dvp, linkzero)
end_define

begin_define
define|#
directive|define
name|XVOP_VNODE_CHANGE
parameter_list|(
name|vp
parameter_list|,
name|cmd
parameter_list|,
name|val
parameter_list|)
define|\
value|(void)_VOP_(vop_vnode_change, vp)((vp)->v_fbhv,cmd,val)
end_define

begin_comment
comment|/*  * These are page cache functions that now go thru VOPs.  * 'last' parameter is unused and left in for IRIX compatibility  */
end_comment

begin_define
define|#
directive|define
name|XVOP_TOSS_PAGES
parameter_list|(
name|vp
parameter_list|,
name|first
parameter_list|,
name|last
parameter_list|,
name|fiopt
parameter_list|)
define|\
value|_VOP_(vop_tosspages, vp)((vp)->v_fbhv,first, last, fiopt)
end_define

begin_comment
comment|/*  * 'last' parameter is unused and left in for IRIX compatibility  */
end_comment

begin_define
define|#
directive|define
name|XVOP_FLUSHINVAL_PAGES
parameter_list|(
name|vp
parameter_list|,
name|first
parameter_list|,
name|last
parameter_list|,
name|fiopt
parameter_list|)
define|\
value|_VOP_(vop_flushinval_pages, vp)((vp)->v_fbhv,first,last,fiopt)
end_define

begin_comment
comment|/*  * 'last' parameter is unused and left in for IRIX compatibility  */
end_comment

begin_define
define|#
directive|define
name|XVOP_FLUSH_PAGES
parameter_list|(
name|vp
parameter_list|,
name|first
parameter_list|,
name|last
parameter_list|,
name|flags
parameter_list|,
name|fiopt
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_flush_pages, vp)((vp)->v_fbhv,first,last,flags,fiopt)
end_define

begin_define
define|#
directive|define
name|XVOP_IOCTL
parameter_list|(
name|vp
parameter_list|,
name|inode
parameter_list|,
name|filp
parameter_list|,
name|fl
parameter_list|,
name|cmd
parameter_list|,
name|arg
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_ioctl, vp)((vp)->v_fbhv,inode,filp,fl,cmd,arg)
end_define

begin_define
define|#
directive|define
name|XVOP_IFLUSH
parameter_list|(
name|vp
parameter_list|,
name|flags
parameter_list|,
name|rv
parameter_list|)
define|\
value|rv = _VOP_(vop_iflush, vp)((vp)->v_fbhv, flags)
end_define

begin_comment
comment|/*  * Flags for read/write calls - select values from FreeBSD IO_ flags  * or non-conflicting bits.  */
end_comment

begin_define
define|#
directive|define
name|IO_ISDIRECT
value|IO_DIRECT
end_define

begin_comment
comment|/* bypass page cache */
end_comment

begin_define
define|#
directive|define
name|IO_INVIS
value|0x02000
end_define

begin_comment
comment|/* don't update inode timestamps */
end_comment

begin_comment
comment|/* #define IO_ISLOCKED	0x04000		don't do inode locking, strictly a CXFS thing */
end_comment

begin_comment
comment|/*  * Flags for VOP_IFLUSH call  */
end_comment

begin_define
define|#
directive|define
name|FLUSH_SYNC
value|1
end_define

begin_comment
comment|/* wait for flush to complete	*/
end_comment

begin_define
define|#
directive|define
name|FLUSH_INODE
value|2
end_define

begin_comment
comment|/* flush the inode itself	*/
end_comment

begin_define
define|#
directive|define
name|FLUSH_LOG
value|4
end_define

begin_comment
comment|/* force the last log entry for 					 * this inode out to disk	*/
end_comment

begin_comment
comment|/*  * Flush/Invalidate options for VOP_TOSS_PAGES, VOP_FLUSHINVAL_PAGES and  *	VOP_FLUSH_PAGES.  */
end_comment

begin_define
define|#
directive|define
name|FI_NONE
value|0
end_define

begin_comment
comment|/* none */
end_comment

begin_define
define|#
directive|define
name|FI_REMAPF
value|1
end_define

begin_comment
comment|/* Do a remapf prior to the operation */
end_comment

begin_define
define|#
directive|define
name|FI_REMAPF_LOCKED
value|2
end_define

begin_comment
comment|/* Do a remapf prior to the operation. 					   Prevent VM access to the pages until 					   the operation completes. */
end_comment

begin_comment
comment|/*  * Vnode attributes.  va_mask indicates those attributes the caller  * wants to set or extract.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_vattr
block|{
name|int
name|va_mask
decl_stmt|;
comment|/* bit-mask of attributes present */
name|mode_t
name|va_mode
decl_stmt|;
comment|/* file access mode and type */
name|nlink_t
name|va_nlink
decl_stmt|;
comment|/* number of references to file */
name|uid_t
name|va_uid
decl_stmt|;
comment|/* owner user id */
name|gid_t
name|va_gid
decl_stmt|;
comment|/* owner group id */
name|xfs_ino_t
name|va_nodeid
decl_stmt|;
comment|/* file id */
name|xfs_off_t
name|va_size
decl_stmt|;
comment|/* file size in bytes */
name|u_long
name|va_blocksize
decl_stmt|;
comment|/* blocksize preferred for i/o */
name|struct
name|timespec
name|va_atime
decl_stmt|;
comment|/* time of last access */
name|struct
name|timespec
name|va_mtime
decl_stmt|;
comment|/* time of last modification */
name|struct
name|timespec
name|va_ctime
decl_stmt|;
comment|/* time file changed */
name|u_int
name|va_gen
decl_stmt|;
comment|/* generation number of file */
name|xfs_dev_t
name|va_rdev
decl_stmt|;
comment|/* device the special file represents */
name|__int64_t
name|va_nblocks
decl_stmt|;
comment|/* number of blocks allocated */
name|u_long
name|va_xflags
decl_stmt|;
comment|/* random extended file flags */
name|u_long
name|va_extsize
decl_stmt|;
comment|/* file extent size */
name|u_long
name|va_nextents
decl_stmt|;
comment|/* number of extents in file */
name|u_long
name|va_anextents
decl_stmt|;
comment|/* number of attr extents in file */
name|int
name|va_projid
decl_stmt|;
comment|/* project id */
block|}
name|xfs_vattr_t
typedef|;
end_typedef

begin_comment
comment|/*  * setattr or getattr attributes  */
end_comment

begin_define
define|#
directive|define
name|XFS_AT_TYPE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|XFS_AT_MODE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|XFS_AT_UID
value|0x00000004
end_define

begin_define
define|#
directive|define
name|XFS_AT_GID
value|0x00000008
end_define

begin_define
define|#
directive|define
name|XFS_AT_FSID
value|0x00000010
end_define

begin_define
define|#
directive|define
name|XFS_AT_NODEID
value|0x00000020
end_define

begin_define
define|#
directive|define
name|XFS_AT_NLINK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|XFS_AT_SIZE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|XFS_AT_ATIME
value|0x00000100
end_define

begin_define
define|#
directive|define
name|XFS_AT_MTIME
value|0x00000200
end_define

begin_define
define|#
directive|define
name|XFS_AT_CTIME
value|0x00000400
end_define

begin_define
define|#
directive|define
name|XFS_AT_RDEV
value|0x00000800
end_define

begin_define
define|#
directive|define
name|XFS_AT_BLKSIZE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|XFS_AT_NBLOCKS
value|0x00002000
end_define

begin_define
define|#
directive|define
name|XFS_AT_VCODE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|XFS_AT_MAC
value|0x00008000
end_define

begin_define
define|#
directive|define
name|XFS_AT_UPDATIME
value|0x00010000
end_define

begin_define
define|#
directive|define
name|XFS_AT_UPDMTIME
value|0x00020000
end_define

begin_define
define|#
directive|define
name|XFS_AT_UPDCTIME
value|0x00040000
end_define

begin_define
define|#
directive|define
name|XFS_AT_ACL
value|0x00080000
end_define

begin_define
define|#
directive|define
name|XFS_AT_CAP
value|0x00100000
end_define

begin_define
define|#
directive|define
name|XFS_AT_INF
value|0x00200000
end_define

begin_define
define|#
directive|define
name|XFS_AT_XFLAGS
value|0x00400000
end_define

begin_define
define|#
directive|define
name|XFS_AT_EXTSIZE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|XFS_AT_NEXTENTS
value|0x01000000
end_define

begin_define
define|#
directive|define
name|XFS_AT_ANEXTENTS
value|0x02000000
end_define

begin_define
define|#
directive|define
name|XFS_AT_PROJID
value|0x04000000
end_define

begin_define
define|#
directive|define
name|XFS_AT_SIZE_NOPERM
value|0x08000000
end_define

begin_define
define|#
directive|define
name|XFS_AT_GENCOUNT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|XFS_AT_ALL
value|(XFS_AT_TYPE|XFS_AT_MODE|XFS_AT_UID|XFS_AT_GID|\ 		XFS_AT_FSID|XFS_AT_NODEID|XFS_AT_NLINK|XFS_AT_SIZE|\ 		XFS_AT_ATIME|XFS_AT_MTIME|XFS_AT_CTIME|XFS_AT_RDEV|\ 		XFS_AT_BLKSIZE|XFS_AT_NBLOCKS|XFS_AT_VCODE|XFS_AT_MAC|\ 		XFS_AT_ACL|XFS_AT_CAP|XFS_AT_INF|XFS_AT_XFLAGS|XFS_AT_EXTSIZE|\ 		XFS_AT_NEXTENTS|XFS_AT_ANEXTENTS|XFS_AT_PROJID|XFS_AT_GENCOUNT)
end_define

begin_define
define|#
directive|define
name|XFS_AT_STAT
value|(XFS_AT_TYPE|XFS_AT_MODE|XFS_AT_UID|XFS_AT_GID|\ 		XFS_AT_FSID|XFS_AT_NODEID|XFS_AT_NLINK|XFS_AT_SIZE|\ 		XFS_AT_ATIME|XFS_AT_MTIME|XFS_AT_CTIME|XFS_AT_RDEV|\ 		XFS_AT_BLKSIZE|XFS_AT_NBLOCKS|XFS_AT_PROJID)
end_define

begin_define
define|#
directive|define
name|XFS_AT_TIMES
value|(XFS_AT_ATIME|XFS_AT_MTIME|XFS_AT_CTIME)
end_define

begin_define
define|#
directive|define
name|XFS_AT_UPDTIMES
value|(XFS_AT_UPDATIME|XFS_AT_UPDMTIME|XFS_AT_UPDCTIME)
end_define

begin_define
define|#
directive|define
name|XFS_AT_NOSET
value|(XFS_AT_NLINK|XFS_AT_RDEV|XFS_AT_FSID|XFS_AT_NODEID|\ 		XFS_AT_TYPE|XFS_AT_BLKSIZE|XFS_AT_NBLOCKS|XFS_AT_VCODE|\ 		XFS_AT_NEXTENTS|XFS_AT_ANEXTENTS|XFS_AT_GENCOUNT)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__FreeBSD__
end_ifndef

begin_comment
comment|/*  *  Modes.  */
end_comment

begin_define
define|#
directive|define
name|VSUID
value|S_ISUID
end_define

begin_comment
comment|/* set user id on execution */
end_comment

begin_define
define|#
directive|define
name|VSGID
value|S_ISGID
end_define

begin_comment
comment|/* set group id on execution */
end_comment

begin_define
define|#
directive|define
name|VSVTX
value|S_ISVTX
end_define

begin_comment
comment|/* save swapped text even after use */
end_comment

begin_define
define|#
directive|define
name|VREAD
value|S_IRUSR
end_define

begin_comment
comment|/* read, write, execute permissions */
end_comment

begin_define
define|#
directive|define
name|VWRITE
value|S_IWUSR
end_define

begin_define
define|#
directive|define
name|VEXEC
value|S_IXUSR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_define
define|#
directive|define
name|MODEMASK
value|ALLPERMS
end_define

begin_comment
comment|/* mode bits plus permission bits */
end_comment

begin_comment
comment|/*  * Check whether mandatory file locking is enabled.  */
end_comment

begin_define
define|#
directive|define
name|MANDLOCK
parameter_list|(
name|vp
parameter_list|,
name|mode
parameter_list|)
define|\
value|((vp)->v_vnode->v_type == VREG&& ((mode)& (VSGID|(VEXEC>>3))) == VSGID)
end_define

begin_function_decl
specifier|extern
name|void
name|vn_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vn_wait
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vn_iowait
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|xfs_vnode_t
modifier|*
name|vn_initialize
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Acquiring and invalidating vnodes:  *  *	if (vn_get(vp, version, 0))  *		...;  *	vn_purge(vp, version);  *  * vn_get and vn_purge must be called with vmap_t arguments, sampled  * while a lock that the vnode's VOP_RECLAIM function acquires is  * held, to ensure that the vnode sampled with the lock held isn't  * recycled (VOP_RECLAIMed) or deallocated between the release of the lock  * and the subsequent vn_get or vn_purge.  */
end_comment

begin_comment
comment|/*  * vnode_map structures _must_ match vn_epoch and vnode structure sizes.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vnode_map
block|{
name|xfs_vfs_t
modifier|*
name|v_vfsp
decl_stmt|;
name|xfs_ino_t
name|v_ino
decl_stmt|;
name|struct
name|vnode
modifier|*
name|v_vp
decl_stmt|;
block|}
name|vmap_t
typedef|;
end_typedef

begin_if
if|#
directive|if
literal|1
end_if

begin_define
define|#
directive|define
name|VMAP
parameter_list|(
name|vp
parameter_list|,
name|vmap
parameter_list|)
value|{(vmap).v_vfsp	 = (vp)->v_vfsp;	\ 			 (vmap).v_vp     = (vp)->v_vnode;	\ 			 (vmap).v_ino	 = (vp)->v_inode->i_ino;\ 			 vhold((vp)->v_vnode);			\ 			}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|vn_purge
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|xfs_vnode_t
modifier|*
name|vn_get
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|,
name|vmap_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vn_revalidate
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|int
name|vn_count
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
name|vp
parameter_list|)
block|{
return|return
name|vp
operator|->
name|v_vnode
operator|->
name|v_usecount
return|;
block|}
end_function

begin_comment
comment|/*  * Vnode reference counting functions (and macros for compatibility).  */
end_comment

begin_function_decl
specifier|extern
name|xfs_vnode_t
modifier|*
name|vn_hold
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vn_rele
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XFS_VNODE_TRACE
argument_list|)
end_if

begin_define
define|#
directive|define
name|VN_HOLD
parameter_list|(
name|vp
parameter_list|)
define|\
value|((void)vref((vp)->v_vnode), \ 	  vn_trace_hold(vp, __FILE__, __LINE__, (inst_t *)__return_address))
end_define

begin_define
define|#
directive|define
name|VN_RELE
parameter_list|(
name|vp
parameter_list|)
define|\
value|(vn_trace_rele(vp, __FILE__, __LINE__, (inst_t *)__return_address), \ 	   vrele((vp)->v_vnode))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VN_HOLD
parameter_list|(
name|vp
parameter_list|)
value|vref((vp)->v_vnode)
end_define

begin_define
define|#
directive|define
name|VN_RELE
parameter_list|(
name|vp
parameter_list|)
value|vrele((vp)->v_vnode)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Vname handling macros.  */
end_comment

begin_define
define|#
directive|define
name|VNAME
parameter_list|(
name|cnp
parameter_list|)
value|((cnp)->cn_nameptr)
end_define

begin_define
define|#
directive|define
name|VNAMELEN
parameter_list|(
name|cnp
parameter_list|)
value|((cnp)->cn_namelen)
end_define

begin_define
define|#
directive|define
name|VNAME_TO_VNODE
parameter_list|(
name|dentry
parameter_list|)
value|(printf("VNAME_TO_VNODE NI"), (xfs_vnode_t *)0)
end_define

begin_comment
comment|/*  * Vnode spinlock manipulation.  */
end_comment

begin_define
define|#
directive|define
name|VN_LOCK
parameter_list|(
name|vp
parameter_list|)
value|VI_LOCK(vp->v_vnode)
end_define

begin_define
define|#
directive|define
name|VN_UNLOCK
parameter_list|(
name|vp
parameter_list|,
name|s
parameter_list|)
value|VI_UNLOCK(vp->v_vnode)
end_define

begin_define
define|#
directive|define
name|VN_FLAGSET
parameter_list|(
name|vp
parameter_list|,
name|b
parameter_list|)
value|vn_flagset(vp,b)
end_define

begin_define
define|#
directive|define
name|VN_FLAGCLR
parameter_list|(
name|vp
parameter_list|,
name|b
parameter_list|)
value|vn_flagclr(vp,b)
end_define

begin_function
specifier|static
name|__inline__
name|void
name|vn_flagset
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
name|vp
parameter_list|,
name|__u32
name|flag
parameter_list|)
block|{
name|VN_LOCK
argument_list|(
name|vp
argument_list|)
expr_stmt|;
name|vp
operator|->
name|v_flag
operator||=
name|flag
expr_stmt|;
name|VN_UNLOCK
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|vn_flagclr
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
name|vp
parameter_list|,
name|__u32
name|flag
parameter_list|)
block|{
name|VN_LOCK
argument_list|(
name|vp
argument_list|)
expr_stmt|;
name|vp
operator|->
name|v_flag
operator|&=
operator|~
name|flag
expr_stmt|;
name|VN_UNLOCK
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Update modify/access/change times on the vnode  */
end_comment

begin_define
define|#
directive|define
name|VN_MTIMESET
parameter_list|(
name|vp
parameter_list|,
name|tvp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|VN_ATIMESET
parameter_list|(
name|vp
parameter_list|,
name|tvp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|VN_CTIMESET
parameter_list|(
name|vp
parameter_list|,
name|tvp
parameter_list|)
end_define

begin_comment
comment|/*  * Some useful predicates.  */
end_comment

begin_define
define|#
directive|define
name|VN_MAPPED
parameter_list|(
name|vp
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|VN_CACHED
parameter_list|(
name|vp
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|VN_DIRTY
parameter_list|(
name|vp
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|VMODIFY
parameter_list|(
name|vp
parameter_list|)
value|VN_FLAGSET(vp, VMODIFIED)
end_define

begin_define
define|#
directive|define
name|VUNMODIFY
parameter_list|(
name|vp
parameter_list|)
value|VN_FLAGCLR(vp, VMODIFIED)
end_define

begin_comment
comment|/*  * Flags to VOP_SETATTR/VOP_GETATTR.  */
end_comment

begin_define
define|#
directive|define
name|ATTR_UTIME
value|0x01
end_define

begin_comment
comment|/* non-default utime(2) request */
end_comment

begin_define
define|#
directive|define
name|ATTR_DMI
value|0x08
end_define

begin_comment
comment|/* invocation from a DMI function */
end_comment

begin_define
define|#
directive|define
name|ATTR_LAZY
value|0x80
end_define

begin_comment
comment|/* set/get attributes lazily */
end_comment

begin_define
define|#
directive|define
name|ATTR_NONBLOCK
value|0x100
end_define

begin_comment
comment|/* return EAGAIN if operation would block */
end_comment

begin_define
define|#
directive|define
name|ATTR_NOLOCK
value|0x200
end_define

begin_comment
comment|/* Don't grab any conflicting locks */
end_comment

begin_define
define|#
directive|define
name|ATTR_NOSIZETOK
value|0x400
end_define

begin_comment
comment|/* Don't get the SIZE token */
end_comment

begin_comment
comment|/*  * Flags to VOP_FSYNC and VOP_RECLAIM.  */
end_comment

begin_define
define|#
directive|define
name|FSYNC_NOWAIT
value|0
end_define

begin_comment
comment|/* asynchronous flush */
end_comment

begin_define
define|#
directive|define
name|FSYNC_WAIT
value|0x1
end_define

begin_comment
comment|/* synchronous fsync or forced reclaim */
end_comment

begin_define
define|#
directive|define
name|FSYNC_INVAL
value|0x2
end_define

begin_comment
comment|/* flush and invalidate cached data */
end_comment

begin_define
define|#
directive|define
name|FSYNC_DATA
value|0x4
end_define

begin_comment
comment|/* synchronous fsync of data only */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|xfs_vnode
modifier|*
name|vn_grab
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
name|vp
parameter_list|)
block|{
name|printf
argument_list|(
literal|"vn_grab NI\n"
argument_list|)
expr_stmt|;
comment|//	struct inode *inode = igrab(vn_to_inode(vp));
comment|//	return inode ? vn_from_inode(inode) : NULL;
return|return
name|NULL
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|vn_atime_to_bstime
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
name|vp
parameter_list|,
name|xfs_bstime_t
modifier|*
name|bs_atime
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%s NI\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
comment|//        bs_atime->tv_sec = vp->v_inode.i_atime.tv_sec;
comment|//        bs_atime->tv_nsec = vp->v_inode.i_atime.tv_nsec;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|vn_atime_to_timespec
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|timespec
modifier|*
name|ts
parameter_list|)
block|{
comment|//	*ts = vp->v_vnode->va_atime;
block|}
end_function

begin_comment
comment|/*  * Tracking vnode activity.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XFS_VNODE_TRACE
argument_list|)
end_if

begin_define
define|#
directive|define
name|VNODE_TRACE_SIZE
value|16
end_define

begin_comment
comment|/* number of trace entries */
end_comment

begin_define
define|#
directive|define
name|VNODE_KTRACE_ENTRY
value|1
end_define

begin_define
define|#
directive|define
name|VNODE_KTRACE_EXIT
value|2
end_define

begin_define
define|#
directive|define
name|VNODE_KTRACE_HOLD
value|3
end_define

begin_define
define|#
directive|define
name|VNODE_KTRACE_REF
value|4
end_define

begin_define
define|#
directive|define
name|VNODE_KTRACE_RELE
value|5
end_define

begin_function_decl
specifier|extern
name|void
name|vn_trace_entry
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|inst_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vn_trace_exit
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|inst_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vn_trace_hold
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|inst_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vn_trace_ref
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|inst_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vn_trace_rele
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|inst_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|VN_TRACE
parameter_list|(
name|vp
parameter_list|)
define|\
value|vn_trace_ref(vp, __FILE__, __LINE__, (inst_t *)__return_address)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vn_trace_entry
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|vn_trace_exit
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|vn_trace_hold
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|vn_trace_ref
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|vn_trace_rele
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|VN_TRACE
parameter_list|(
name|vp
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_VNODE_H__ */
end_comment

end_unit

