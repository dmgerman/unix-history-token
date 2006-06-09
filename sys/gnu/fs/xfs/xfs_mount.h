begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_MOUNT_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_MOUNT_H__
end_define

begin_typedef
typedef|typedef
struct|struct
name|xfs_trans_reservations
block|{
name|uint
name|tr_write
decl_stmt|;
comment|/* extent alloc trans */
name|uint
name|tr_itruncate
decl_stmt|;
comment|/* truncate trans */
name|uint
name|tr_rename
decl_stmt|;
comment|/* rename trans */
name|uint
name|tr_link
decl_stmt|;
comment|/* link trans */
name|uint
name|tr_remove
decl_stmt|;
comment|/* unlink trans */
name|uint
name|tr_symlink
decl_stmt|;
comment|/* symlink trans */
name|uint
name|tr_create
decl_stmt|;
comment|/* create trans */
name|uint
name|tr_mkdir
decl_stmt|;
comment|/* mkdir trans */
name|uint
name|tr_ifree
decl_stmt|;
comment|/* inode free trans */
name|uint
name|tr_ichange
decl_stmt|;
comment|/* inode update trans */
name|uint
name|tr_growdata
decl_stmt|;
comment|/* fs data section grow trans */
name|uint
name|tr_swrite
decl_stmt|;
comment|/* sync write inode trans */
name|uint
name|tr_addafork
decl_stmt|;
comment|/* cvt inode to attributed trans */
name|uint
name|tr_writeid
decl_stmt|;
comment|/* write setuid/setgid file */
name|uint
name|tr_attrinval
decl_stmt|;
comment|/* attr fork buffer invalidation */
name|uint
name|tr_attrset
decl_stmt|;
comment|/* set/create an attribute */
name|uint
name|tr_attrrm
decl_stmt|;
comment|/* remove an attribute */
name|uint
name|tr_clearagi
decl_stmt|;
comment|/* clear bad agi unlinked ino bucket */
name|uint
name|tr_growrtalloc
decl_stmt|;
comment|/* grow realtime allocations */
name|uint
name|tr_growrtzero
decl_stmt|;
comment|/* grow realtime zeroing */
name|uint
name|tr_growrtfree
decl_stmt|;
comment|/* grow realtime freeing */
block|}
name|xfs_trans_reservations_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|__KERNEL__
end_ifndef

begin_comment
comment|/*  * Moved here from xfs_ag.h to avoid reordering header files  */
end_comment

begin_define
define|#
directive|define
name|XFS_DADDR_TO_AGNO
parameter_list|(
name|mp
parameter_list|,
name|d
parameter_list|)
define|\
value|((xfs_agnumber_t)(XFS_BB_TO_FSBT(mp, d) / (mp)->m_sb.sb_agblocks))
end_define

begin_define
define|#
directive|define
name|XFS_DADDR_TO_AGBNO
parameter_list|(
name|mp
parameter_list|,
name|d
parameter_list|)
define|\
value|((xfs_agblock_t)(XFS_BB_TO_FSBT(mp, d) % (mp)->m_sb.sb_agblocks))
end_define

begin_else
else|#
directive|else
end_else

begin_struct_decl
struct_decl|struct
name|cred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|log
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_vfs
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_vnode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_mount_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_ihash
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_chash
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_inode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_perag
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_iocore
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_bmbt_irec
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_bmap_free
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_extdelta
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_swapext
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|xvfsops
name|xfs_vfsops
decl_stmt|;
end_decl_stmt

begin_comment
comment|//extern struct xvnodeops xfs_vnodeops;
end_comment

begin_define
define|#
directive|define
name|AIL_LOCK_T
value|lock_t
end_define

begin_define
define|#
directive|define
name|AIL_LOCKINIT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|spinlock_init(x,y)
end_define

begin_define
define|#
directive|define
name|AIL_LOCK_DESTROY
parameter_list|(
name|x
parameter_list|)
value|spinlock_destroy(x)
end_define

begin_define
define|#
directive|define
name|AIL_LOCK
parameter_list|(
name|mp
parameter_list|,
name|s
parameter_list|)
value|s=mutex_spinlock(&(mp)->m_ail_lock)
end_define

begin_define
define|#
directive|define
name|AIL_UNLOCK
parameter_list|(
name|mp
parameter_list|,
name|s
parameter_list|)
value|mutex_spinunlock(&(mp)->m_ail_lock, s)
end_define

begin_comment
comment|/*  * Prototypes and functions for the Data Migration subsystem.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_send_data_t
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|struct
name|xfs_vnode
modifier|*
parameter_list|,
name|xfs_off_t
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
name|vrwlock_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_send_mmap_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_send_destroy_t
function_decl|)
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|,
name|dm_right_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_send_namesp_t
function_decl|)
parameter_list|(
name|dm_eventtype_t
parameter_list|,
name|struct
name|xfs_vfs
modifier|*
parameter_list|,
name|struct
name|xfs_vnode
modifier|*
parameter_list|,
name|dm_right_t
parameter_list|,
name|struct
name|xfs_vnode
modifier|*
parameter_list|,
name|dm_right_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|mode_t
parameter_list|,
name|int
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
name|xfs_send_unmount_t
function_decl|)
parameter_list|(
name|struct
name|xfs_vfs
modifier|*
parameter_list|,
name|struct
name|xfs_vnode
modifier|*
parameter_list|,
name|dm_right_t
parameter_list|,
name|mode_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_dmops
block|{
name|xfs_send_data_t
name|xfs_send_data
decl_stmt|;
name|xfs_send_mmap_t
name|xfs_send_mmap
decl_stmt|;
name|xfs_send_destroy_t
name|xfs_send_destroy
decl_stmt|;
name|xfs_send_namesp_t
name|xfs_send_namesp
decl_stmt|;
name|xfs_send_unmount_t
name|xfs_send_unmount
decl_stmt|;
block|}
name|xfs_dmops_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_SEND_DATA
parameter_list|(
name|mp
parameter_list|,
name|ev
parameter_list|,
name|vp
parameter_list|,
name|off
parameter_list|,
name|len
parameter_list|,
name|fl
parameter_list|,
name|lock
parameter_list|)
define|\
value|(*(mp)->m_dm_ops.xfs_send_data)(ev,vp,off,len,fl,lock)
end_define

begin_define
define|#
directive|define
name|XFS_SEND_MMAP
parameter_list|(
name|mp
parameter_list|,
name|vma
parameter_list|,
name|fl
parameter_list|)
define|\
value|(*(mp)->m_dm_ops.xfs_send_mmap)(vma,fl)
end_define

begin_define
define|#
directive|define
name|XFS_SEND_DESTROY
parameter_list|(
name|mp
parameter_list|,
name|vp
parameter_list|,
name|right
parameter_list|)
define|\
value|(*(mp)->m_dm_ops.xfs_send_destroy)(vp,right)
end_define

begin_define
define|#
directive|define
name|XFS_SEND_NAMESP
parameter_list|(
name|mp
parameter_list|,
name|ev
parameter_list|,
name|b1
parameter_list|,
name|r1
parameter_list|,
name|b2
parameter_list|,
name|r2
parameter_list|,
name|n1
parameter_list|,
name|n2
parameter_list|,
name|mode
parameter_list|,
name|rval
parameter_list|,
name|fl
parameter_list|)
define|\
value|(*(mp)->m_dm_ops.xfs_send_namesp)(ev,NULL,b1,r1,b2,r2,n1,n2,mode,rval,fl)
end_define

begin_define
define|#
directive|define
name|XFS_SEND_PREUNMOUNT
parameter_list|(
name|mp
parameter_list|,
name|vfs
parameter_list|,
name|b1
parameter_list|,
name|r1
parameter_list|,
name|b2
parameter_list|,
name|r2
parameter_list|,
name|n1
parameter_list|,
name|n2
parameter_list|,
name|mode
parameter_list|,
name|rval
parameter_list|,
name|fl
parameter_list|)
define|\
value|(*(mp)->m_dm_ops.xfs_send_namesp)(DM_EVENT_PREUNMOUNT,vfs,b1,r1,b2,r2,n1,n2,mode,rval,fl)
end_define

begin_define
define|#
directive|define
name|XFS_SEND_UNMOUNT
parameter_list|(
name|mp
parameter_list|,
name|vfsp
parameter_list|,
name|vp
parameter_list|,
name|right
parameter_list|,
name|mode
parameter_list|,
name|rval
parameter_list|,
name|fl
parameter_list|)
define|\
value|(*(mp)->m_dm_ops.xfs_send_unmount)(vfsp,vp,right,mode,rval,fl)
end_define

begin_comment
comment|/*  * Prototypes and functions for the Quota Management subsystem.  */
end_comment

begin_struct_decl
struct_decl|struct
name|xfs_dquot
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_dqtrxops
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_quotainfo
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_qminit_t
function_decl|)
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|uint
modifier|*
parameter_list|,
name|uint
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_qmmount_t
function_decl|)
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|uint
parameter_list|,
name|uint
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
name|xfs_qmunmount_t
function_decl|)
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xfs_qmdone_t
function_decl|)
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xfs_dqrele_t
function_decl|)
parameter_list|(
name|struct
name|xfs_dquot
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_dqattach_t
function_decl|)
parameter_list|(
name|struct
name|xfs_inode
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xfs_dqdetach_t
function_decl|)
parameter_list|(
name|struct
name|xfs_inode
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_dqpurgeall_t
function_decl|)
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_dqvopalloc_t
function_decl|)
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|struct
name|xfs_inode
modifier|*
parameter_list|,
name|uid_t
parameter_list|,
name|gid_t
parameter_list|,
name|prid_t
parameter_list|,
name|uint
parameter_list|,
name|struct
name|xfs_dquot
modifier|*
modifier|*
parameter_list|,
name|struct
name|xfs_dquot
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xfs_dqvopcreate_t
function_decl|)
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|struct
name|xfs_inode
modifier|*
parameter_list|,
name|struct
name|xfs_dquot
modifier|*
parameter_list|,
name|struct
name|xfs_dquot
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_dqvoprename_t
function_decl|)
parameter_list|(
name|struct
name|xfs_inode
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xfs_dquot
modifier|*
function_decl|(
modifier|*
name|xfs_dqvopchown_t
function_decl|)
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|struct
name|xfs_inode
modifier|*
parameter_list|,
name|struct
name|xfs_dquot
modifier|*
modifier|*
parameter_list|,
name|struct
name|xfs_dquot
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_dqvopchownresv_t
function_decl|)
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|struct
name|xfs_inode
modifier|*
parameter_list|,
name|struct
name|xfs_dquot
modifier|*
parameter_list|,
name|struct
name|xfs_dquot
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_qmops
block|{
name|xfs_qminit_t
name|xfs_qminit
decl_stmt|;
name|xfs_qmdone_t
name|xfs_qmdone
decl_stmt|;
name|xfs_qmmount_t
name|xfs_qmmount
decl_stmt|;
name|xfs_qmunmount_t
name|xfs_qmunmount
decl_stmt|;
name|xfs_dqrele_t
name|xfs_dqrele
decl_stmt|;
name|xfs_dqattach_t
name|xfs_dqattach
decl_stmt|;
name|xfs_dqdetach_t
name|xfs_dqdetach
decl_stmt|;
name|xfs_dqpurgeall_t
name|xfs_dqpurgeall
decl_stmt|;
name|xfs_dqvopalloc_t
name|xfs_dqvopalloc
decl_stmt|;
name|xfs_dqvopcreate_t
name|xfs_dqvopcreate
decl_stmt|;
name|xfs_dqvoprename_t
name|xfs_dqvoprename
decl_stmt|;
name|xfs_dqvopchown_t
name|xfs_dqvopchown
decl_stmt|;
name|xfs_dqvopchownresv_t
name|xfs_dqvopchownresv
decl_stmt|;
name|struct
name|xfs_dqtrxops
modifier|*
name|xfs_dqtrxops
decl_stmt|;
block|}
name|xfs_qmops_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_QM_INIT
parameter_list|(
name|mp
parameter_list|,
name|mnt
parameter_list|,
name|fl
parameter_list|)
define|\
value|(*(mp)->m_qm_ops.xfs_qminit)(mp, mnt, fl)
end_define

begin_define
define|#
directive|define
name|XFS_QM_MOUNT
parameter_list|(
name|mp
parameter_list|,
name|mnt
parameter_list|,
name|fl
parameter_list|,
name|mfsi_flags
parameter_list|)
define|\
value|(*(mp)->m_qm_ops.xfs_qmmount)(mp, mnt, fl, mfsi_flags)
end_define

begin_define
define|#
directive|define
name|XFS_QM_UNMOUNT
parameter_list|(
name|mp
parameter_list|)
define|\
value|(*(mp)->m_qm_ops.xfs_qmunmount)(mp)
end_define

begin_define
define|#
directive|define
name|XFS_QM_DONE
parameter_list|(
name|mp
parameter_list|)
define|\
value|(*(mp)->m_qm_ops.xfs_qmdone)(mp)
end_define

begin_define
define|#
directive|define
name|XFS_QM_DQRELE
parameter_list|(
name|mp
parameter_list|,
name|dq
parameter_list|)
define|\
value|(*(mp)->m_qm_ops.xfs_dqrele)(dq)
end_define

begin_define
define|#
directive|define
name|XFS_QM_DQATTACH
parameter_list|(
name|mp
parameter_list|,
name|ip
parameter_list|,
name|fl
parameter_list|)
define|\
value|(*(mp)->m_qm_ops.xfs_dqattach)(ip, fl)
end_define

begin_define
define|#
directive|define
name|XFS_QM_DQDETACH
parameter_list|(
name|mp
parameter_list|,
name|ip
parameter_list|)
define|\
value|(*(mp)->m_qm_ops.xfs_dqdetach)(ip)
end_define

begin_define
define|#
directive|define
name|XFS_QM_DQPURGEALL
parameter_list|(
name|mp
parameter_list|,
name|fl
parameter_list|)
define|\
value|(*(mp)->m_qm_ops.xfs_dqpurgeall)(mp, fl)
end_define

begin_define
define|#
directive|define
name|XFS_QM_DQVOPALLOC
parameter_list|(
name|mp
parameter_list|,
name|ip
parameter_list|,
name|uid
parameter_list|,
name|gid
parameter_list|,
name|prid
parameter_list|,
name|fl
parameter_list|,
name|dq1
parameter_list|,
name|dq2
parameter_list|)
define|\
value|(*(mp)->m_qm_ops.xfs_dqvopalloc)(mp, ip, uid, gid, prid, fl, dq1, dq2)
end_define

begin_define
define|#
directive|define
name|XFS_QM_DQVOPCREATE
parameter_list|(
name|mp
parameter_list|,
name|tp
parameter_list|,
name|ip
parameter_list|,
name|dq1
parameter_list|,
name|dq2
parameter_list|)
define|\
value|(*(mp)->m_qm_ops.xfs_dqvopcreate)(tp, ip, dq1, dq2)
end_define

begin_define
define|#
directive|define
name|XFS_QM_DQVOPRENAME
parameter_list|(
name|mp
parameter_list|,
name|ip
parameter_list|)
define|\
value|(*(mp)->m_qm_ops.xfs_dqvoprename)(ip)
end_define

begin_define
define|#
directive|define
name|XFS_QM_DQVOPCHOWN
parameter_list|(
name|mp
parameter_list|,
name|tp
parameter_list|,
name|ip
parameter_list|,
name|dqp
parameter_list|,
name|dq
parameter_list|)
define|\
value|(*(mp)->m_qm_ops.xfs_dqvopchown)(tp, ip, dqp, dq)
end_define

begin_define
define|#
directive|define
name|XFS_QM_DQVOPCHOWNRESV
parameter_list|(
name|mp
parameter_list|,
name|tp
parameter_list|,
name|ip
parameter_list|,
name|dq1
parameter_list|,
name|dq2
parameter_list|,
name|fl
parameter_list|)
define|\
value|(*(mp)->m_qm_ops.xfs_dqvopchownresv)(tp, ip, dq1, dq2, fl)
end_define

begin_comment
comment|/*  * Prototypes and functions for I/O core modularization.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_ioinit_t
function_decl|)
parameter_list|(
name|struct
name|xfs_vfs
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
name|xfs_bmapi_t
function_decl|)
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|xfs_fileoff_t
parameter_list|,
name|xfs_filblks_t
parameter_list|,
name|int
parameter_list|,
name|xfs_fsblock_t
modifier|*
parameter_list|,
name|xfs_extlen_t
parameter_list|,
name|struct
name|xfs_bmbt_irec
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|struct
name|xfs_bmap_free
modifier|*
parameter_list|,
name|struct
name|xfs_extdelta
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_bunmapi_t
function_decl|)
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|xfs_fileoff_t
parameter_list|,
name|xfs_filblks_t
parameter_list|,
name|int
parameter_list|,
name|xfs_extnum_t
parameter_list|,
name|xfs_fsblock_t
modifier|*
parameter_list|,
name|struct
name|xfs_bmap_free
modifier|*
parameter_list|,
name|struct
name|xfs_extdelta
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
name|xfs_bmap_eof_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|xfs_fileoff_t
parameter_list|,
name|int
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
name|xfs_iomap_write_direct_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|xfs_off_t
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|xfs_bmbt_irec
modifier|*
parameter_list|,
name|int
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
name|xfs_iomap_write_delay_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|xfs_off_t
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|xfs_bmbt_irec
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
name|xfs_iomap_write_allocate_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|xfs_off_t
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|xfs_bmbt_irec
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
name|xfs_iomap_write_unwritten_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|xfs_off_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|uint
function_decl|(
modifier|*
name|xfs_lck_map_shared_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xfs_lock_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xfs_lock_demote_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_lock_nowait_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xfs_unlk_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|xfs_fsize_t
function_decl|(
modifier|*
name|xfs_size_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|xfs_fsize_t
function_decl|(
modifier|*
name|xfs_iodone_t
function_decl|)
parameter_list|(
name|struct
name|xfs_vfs
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_swap_extents_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|xfs_swapext
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_ioops
block|{
name|xfs_ioinit_t
name|xfs_ioinit
decl_stmt|;
name|xfs_bmapi_t
name|xfs_bmapi_func
decl_stmt|;
name|xfs_bunmapi_t
name|xfs_bunmapi_func
decl_stmt|;
name|xfs_bmap_eof_t
name|xfs_bmap_eof_func
decl_stmt|;
name|xfs_iomap_write_direct_t
name|xfs_iomap_write_direct
decl_stmt|;
name|xfs_iomap_write_delay_t
name|xfs_iomap_write_delay
decl_stmt|;
name|xfs_iomap_write_allocate_t
name|xfs_iomap_write_allocate
decl_stmt|;
name|xfs_iomap_write_unwritten_t
name|xfs_iomap_write_unwritten
decl_stmt|;
name|xfs_lock_t
name|xfs_ilock
decl_stmt|;
name|xfs_lck_map_shared_t
name|xfs_lck_map_shared
decl_stmt|;
name|xfs_lock_demote_t
name|xfs_ilock_demote
decl_stmt|;
name|xfs_lock_nowait_t
name|xfs_ilock_nowait
decl_stmt|;
name|xfs_unlk_t
name|xfs_unlock
decl_stmt|;
name|xfs_size_t
name|xfs_size_func
decl_stmt|;
name|xfs_iodone_t
name|xfs_iodone
decl_stmt|;
name|xfs_swap_extents_t
name|xfs_swap_extents_func
decl_stmt|;
block|}
name|xfs_ioops_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_IOINIT
parameter_list|(
name|vfsp
parameter_list|,
name|args
parameter_list|,
name|flags
parameter_list|)
define|\
value|(*(mp)->m_io_ops.xfs_ioinit)(vfsp, args, flags)
end_define

begin_define
define|#
directive|define
name|XFS_BMAPI
parameter_list|(
name|mp
parameter_list|,
name|trans
parameter_list|,
name|io
parameter_list|,
name|bno
parameter_list|,
name|len
parameter_list|,
name|f
parameter_list|,
name|first
parameter_list|,
name|tot
parameter_list|,
name|mval
parameter_list|,
name|nmap
parameter_list|,
name|flist
parameter_list|,
name|delta
parameter_list|)
define|\
value|(*(mp)->m_io_ops.xfs_bmapi_func) \ 		(trans,(io)->io_obj,bno,len,f,first,tot,mval,nmap,flist,delta)
end_define

begin_define
define|#
directive|define
name|XFS_BUNMAPI
parameter_list|(
name|mp
parameter_list|,
name|trans
parameter_list|,
name|io
parameter_list|,
name|bno
parameter_list|,
name|len
parameter_list|,
name|f
parameter_list|,
name|nexts
parameter_list|,
name|first
parameter_list|,
name|flist
parameter_list|,
name|delta
parameter_list|,
name|done
parameter_list|)
define|\
value|(*(mp)->m_io_ops.xfs_bunmapi_func) \ 		(trans,(io)->io_obj,bno,len,f,nexts,first,flist,delta,done)
end_define

begin_define
define|#
directive|define
name|XFS_BMAP_EOF
parameter_list|(
name|mp
parameter_list|,
name|io
parameter_list|,
name|endoff
parameter_list|,
name|whichfork
parameter_list|,
name|eof
parameter_list|)
define|\
value|(*(mp)->m_io_ops.xfs_bmap_eof_func) \ 		((io)->io_obj, endoff, whichfork, eof)
end_define

begin_define
define|#
directive|define
name|XFS_IOMAP_WRITE_DIRECT
parameter_list|(
name|mp
parameter_list|,
name|io
parameter_list|,
name|offset
parameter_list|,
name|count
parameter_list|,
name|flags
parameter_list|,
name|mval
parameter_list|,
name|nmap
parameter_list|,
name|found
parameter_list|)
define|\
value|(*(mp)->m_io_ops.xfs_iomap_write_direct) \ 		((io)->io_obj, offset, count, flags, mval, nmap, found)
end_define

begin_define
define|#
directive|define
name|XFS_IOMAP_WRITE_DELAY
parameter_list|(
name|mp
parameter_list|,
name|io
parameter_list|,
name|offset
parameter_list|,
name|count
parameter_list|,
name|flags
parameter_list|,
name|mval
parameter_list|,
name|nmap
parameter_list|)
define|\
value|(*(mp)->m_io_ops.xfs_iomap_write_delay) \ 		((io)->io_obj, offset, count, flags, mval, nmap)
end_define

begin_define
define|#
directive|define
name|XFS_IOMAP_WRITE_ALLOCATE
parameter_list|(
name|mp
parameter_list|,
name|io
parameter_list|,
name|offset
parameter_list|,
name|count
parameter_list|,
name|mval
parameter_list|,
name|nmap
parameter_list|)
define|\
value|(*(mp)->m_io_ops.xfs_iomap_write_allocate) \ 		((io)->io_obj, offset, count, mval, nmap)
end_define

begin_define
define|#
directive|define
name|XFS_IOMAP_WRITE_UNWRITTEN
parameter_list|(
name|mp
parameter_list|,
name|io
parameter_list|,
name|offset
parameter_list|,
name|count
parameter_list|)
define|\
value|(*(mp)->m_io_ops.xfs_iomap_write_unwritten) \ 		((io)->io_obj, offset, count)
end_define

begin_define
define|#
directive|define
name|XFS_LCK_MAP_SHARED
parameter_list|(
name|mp
parameter_list|,
name|io
parameter_list|)
define|\
value|(*(mp)->m_io_ops.xfs_lck_map_shared)((io)->io_obj)
end_define

begin_define
define|#
directive|define
name|XFS_ILOCK
parameter_list|(
name|mp
parameter_list|,
name|io
parameter_list|,
name|mode
parameter_list|)
define|\
value|(*(mp)->m_io_ops.xfs_ilock)((io)->io_obj, mode)
end_define

begin_define
define|#
directive|define
name|XFS_ILOCK_NOWAIT
parameter_list|(
name|mp
parameter_list|,
name|io
parameter_list|,
name|mode
parameter_list|)
define|\
value|(*(mp)->m_io_ops.xfs_ilock_nowait)((io)->io_obj, mode)
end_define

begin_define
define|#
directive|define
name|XFS_IUNLOCK
parameter_list|(
name|mp
parameter_list|,
name|io
parameter_list|,
name|mode
parameter_list|)
define|\
value|(*(mp)->m_io_ops.xfs_unlock)((io)->io_obj, mode)
end_define

begin_define
define|#
directive|define
name|XFS_ILOCK_DEMOTE
parameter_list|(
name|mp
parameter_list|,
name|io
parameter_list|,
name|mode
parameter_list|)
define|\
value|(*(mp)->m_io_ops.xfs_ilock_demote)((io)->io_obj, mode)
end_define

begin_define
define|#
directive|define
name|XFS_SIZE
parameter_list|(
name|mp
parameter_list|,
name|io
parameter_list|)
define|\
value|(*(mp)->m_io_ops.xfs_size_func)((io)->io_obj)
end_define

begin_define
define|#
directive|define
name|XFS_IODONE
parameter_list|(
name|vfsp
parameter_list|)
define|\
value|(*(mp)->m_io_ops.xfs_iodone)(vfsp)
end_define

begin_define
define|#
directive|define
name|XFS_SWAP_EXTENTS
parameter_list|(
name|mp
parameter_list|,
name|io
parameter_list|,
name|tio
parameter_list|,
name|sxp
parameter_list|)
define|\
value|(*(mp)->m_io_ops.xfs_swap_extents_func) \ 		((io)->io_obj, (tio)->io_obj, sxp)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PERCPU_SB
end_ifdef

begin_comment
comment|/*  * Valid per-cpu incore superblock counters. Note that if you add new counters,  * you may need to define new counter disabled bit field descriptors as there  * are more possible fields in the superblock that can fit in a bitfield on a  * 32 bit platform. The XFS_SBS_* values for the current current counters just  * fit.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_icsb_cnts
block|{
name|uint64_t
name|icsb_fdblocks
decl_stmt|;
name|uint64_t
name|icsb_ifree
decl_stmt|;
name|uint64_t
name|icsb_icount
decl_stmt|;
name|unsigned
name|long
name|icsb_flags
decl_stmt|;
block|}
name|xfs_icsb_cnts_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_ICSB_FLAG_LOCK
value|(1<< 0)
end_define

begin_comment
comment|/* counter lock bit */
end_comment

begin_define
define|#
directive|define
name|XFS_ICSB_SB_LOCKED
value|(1<< 0)
end_define

begin_comment
comment|/* sb already locked */
end_comment

begin_define
define|#
directive|define
name|XFS_ICSB_LAZY_COUNT
value|(1<< 1)
end_define

begin_comment
comment|/* accuracy not needed */
end_comment

begin_function_decl
specifier|extern
name|int
name|xfs_icsb_init_counters
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_icsb_sync_counters_lazy
parameter_list|(
name|struct
name|xfs_mount
modifier|*
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
name|xfs_icsb_init_counters
parameter_list|(
name|mp
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|xfs_icsb_sync_counters_lazy
parameter_list|(
name|mp
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|xfs_mount
block|{
name|bhv_desc_t
name|m_bhv
decl_stmt|;
comment|/* vfs xfs behavior */
name|xfs_tid_t
name|m_tid
decl_stmt|;
comment|/* next unused tid for fs */
name|AIL_LOCK_T
name|m_ail_lock
decl_stmt|;
comment|/* fs AIL mutex */
name|xfs_ail_entry_t
name|m_ail
decl_stmt|;
comment|/* fs active log item list */
name|uint
name|m_ail_gen
decl_stmt|;
comment|/* fs AIL generation count */
name|xfs_sb_t
name|m_sb
decl_stmt|;
comment|/* copy of fs superblock */
name|lock_t
name|m_sb_lock
decl_stmt|;
comment|/* sb counter mutex */
name|struct
name|xfs_buf
modifier|*
name|m_sb_bp
decl_stmt|;
comment|/* buffer for superblock */
name|char
modifier|*
name|m_fsname
decl_stmt|;
comment|/* filesystem name */
name|int
name|m_fsname_len
decl_stmt|;
comment|/* strlen of fs name */
name|char
modifier|*
name|m_rtname
decl_stmt|;
comment|/* realtime device name */
name|char
modifier|*
name|m_logname
decl_stmt|;
comment|/* external log device name */
name|int
name|m_bsize
decl_stmt|;
comment|/* fs logical block size */
name|xfs_agnumber_t
name|m_agfrotor
decl_stmt|;
comment|/* last ag where space found */
name|xfs_agnumber_t
name|m_agirotor
decl_stmt|;
comment|/* last ag dir inode alloced */
name|lock_t
name|m_agirotor_lock
decl_stmt|;
comment|/* .. and lock protecting it */
name|xfs_agnumber_t
name|m_maxagi
decl_stmt|;
comment|/* highest inode alloc group */
name|uint
name|m_ihsize
decl_stmt|;
comment|/* size of next field */
name|struct
name|xfs_ihash
modifier|*
name|m_ihash
decl_stmt|;
comment|/* fs private inode hash table*/
name|struct
name|xfs_inode
modifier|*
name|m_inodes
decl_stmt|;
comment|/* active inode list */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|xfs_inode
argument_list|)
name|m_del_inodes
expr_stmt|;
comment|/* inodes to reclaim */
comment|//	xfs_mutex_t		m_ilock;	/* inode list mutex */
comment|/* FreeBSD specfic */
name|struct
name|sx
name|m_ilock
decl_stmt|;
comment|/* inode list mutex */
name|uint
name|m_ireclaims
decl_stmt|;
comment|/* count of calls to reclaim*/
name|uint
name|m_readio_log
decl_stmt|;
comment|/* min read size log bytes */
name|uint
name|m_readio_blocks
decl_stmt|;
comment|/* min read size blocks */
name|uint
name|m_writeio_log
decl_stmt|;
comment|/* min write size log bytes */
name|uint
name|m_writeio_blocks
decl_stmt|;
comment|/* min write size blocks */
name|struct
name|log
modifier|*
name|m_log
decl_stmt|;
comment|/* log specific stuff */
name|int
name|m_logbufs
decl_stmt|;
comment|/* number of log buffers */
name|int
name|m_logbsize
decl_stmt|;
comment|/* size of each log buffer */
name|uint
name|m_rsumlevels
decl_stmt|;
comment|/* rt summary levels */
name|uint
name|m_rsumsize
decl_stmt|;
comment|/* size of rt summary, bytes */
name|struct
name|xfs_inode
modifier|*
name|m_rbmip
decl_stmt|;
comment|/* pointer to bitmap inode */
name|struct
name|xfs_inode
modifier|*
name|m_rsumip
decl_stmt|;
comment|/* pointer to summary inode */
name|struct
name|xfs_inode
modifier|*
name|m_rootip
decl_stmt|;
comment|/* pointer to root directory */
name|struct
name|xfs_quotainfo
modifier|*
name|m_quotainfo
decl_stmt|;
comment|/* disk quota information */
name|xfs_buftarg_t
modifier|*
name|m_ddev_targp
decl_stmt|;
comment|/* saves taking the address */
name|xfs_buftarg_t
modifier|*
name|m_logdev_targp
decl_stmt|;
comment|/* ptr to log device */
name|xfs_buftarg_t
modifier|*
name|m_rtdev_targp
decl_stmt|;
comment|/* ptr to rt device */
name|__uint8_t
name|m_dircook_elog
decl_stmt|;
comment|/* log d-cookie entry bits */
name|__uint8_t
name|m_blkbit_log
decl_stmt|;
comment|/* blocklog + NBBY */
name|__uint8_t
name|m_blkbb_log
decl_stmt|;
comment|/* blocklog - BBSHIFT */
name|__uint8_t
name|m_agno_log
decl_stmt|;
comment|/* log #ag's */
name|__uint8_t
name|m_agino_log
decl_stmt|;
comment|/* #bits for agino in inum */
name|__uint8_t
name|m_nreadaheads
decl_stmt|;
comment|/* #readahead buffers */
name|__uint16_t
name|m_inode_cluster_size
decl_stmt|;
comment|/* min inode buf size */
name|uint
name|m_blockmask
decl_stmt|;
comment|/* sb_blocksize-1 */
name|uint
name|m_blockwsize
decl_stmt|;
comment|/* sb_blocksize in words */
name|uint
name|m_blockwmask
decl_stmt|;
comment|/* blockwsize-1 */
name|uint
name|m_alloc_mxr
index|[
literal|2
index|]
decl_stmt|;
comment|/* XFS_ALLOC_BLOCK_MAXRECS */
name|uint
name|m_alloc_mnr
index|[
literal|2
index|]
decl_stmt|;
comment|/* XFS_ALLOC_BLOCK_MINRECS */
name|uint
name|m_bmap_dmxr
index|[
literal|2
index|]
decl_stmt|;
comment|/* XFS_BMAP_BLOCK_DMAXRECS */
name|uint
name|m_bmap_dmnr
index|[
literal|2
index|]
decl_stmt|;
comment|/* XFS_BMAP_BLOCK_DMINRECS */
name|uint
name|m_inobt_mxr
index|[
literal|2
index|]
decl_stmt|;
comment|/* XFS_INOBT_BLOCK_MAXRECS */
name|uint
name|m_inobt_mnr
index|[
literal|2
index|]
decl_stmt|;
comment|/* XFS_INOBT_BLOCK_MINRECS */
name|uint
name|m_ag_maxlevels
decl_stmt|;
comment|/* XFS_AG_MAXLEVELS */
name|uint
name|m_bm_maxlevels
index|[
literal|2
index|]
decl_stmt|;
comment|/* XFS_BM_MAXLEVELS */
name|uint
name|m_in_maxlevels
decl_stmt|;
comment|/* XFS_IN_MAXLEVELS */
name|struct
name|xfs_perag
modifier|*
name|m_perag
decl_stmt|;
comment|/* per-ag accounting info */
name|struct
name|rw_semaphore
name|m_peraglock
decl_stmt|;
comment|/* lock for m_perag (pointer) */
name|sema_t
name|m_growlock
decl_stmt|;
comment|/* growfs mutex */
name|int
name|m_fixedfsid
index|[
literal|2
index|]
decl_stmt|;
comment|/* unchanged for life of FS */
name|uint
name|m_dmevmask
decl_stmt|;
comment|/* DMI events for this FS */
name|__uint64_t
name|m_flags
decl_stmt|;
comment|/* global mount flags */
name|uint
name|m_attroffset
decl_stmt|;
comment|/* inode attribute offset */
name|uint
name|m_dir_node_ents
decl_stmt|;
comment|/* #entries in a dir danode */
name|uint
name|m_attr_node_ents
decl_stmt|;
comment|/* #entries in attr danode */
name|int
name|m_ialloc_inos
decl_stmt|;
comment|/* inodes in inode allocation */
name|int
name|m_ialloc_blks
decl_stmt|;
comment|/* blocks in inode allocation */
name|int
name|m_litino
decl_stmt|;
comment|/* size of inode union area */
name|int
name|m_inoalign_mask
decl_stmt|;
comment|/* mask sb_inoalignmt if used */
name|uint
name|m_qflags
decl_stmt|;
comment|/* quota status flags */
name|xfs_trans_reservations_t
name|m_reservations
decl_stmt|;
comment|/* precomputed res values */
name|__uint64_t
name|m_maxicount
decl_stmt|;
comment|/* maximum inode count */
name|__uint64_t
name|m_maxioffset
decl_stmt|;
comment|/* maximum inode offset */
name|__uint64_t
name|m_resblks
decl_stmt|;
comment|/* total reserved blocks */
name|__uint64_t
name|m_resblks_avail
decl_stmt|;
comment|/* available reserved blocks */
if|#
directive|if
name|XFS_BIG_INUMS
name|xfs_ino_t
name|m_inoadd
decl_stmt|;
comment|/* add value for ino64_offset */
endif|#
directive|endif
name|int
name|m_dalign
decl_stmt|;
comment|/* stripe unit */
name|int
name|m_swidth
decl_stmt|;
comment|/* stripe width */
name|int
name|m_sinoalign
decl_stmt|;
comment|/* stripe unit inode alignment */
name|int
name|m_attr_magicpct
decl_stmt|;
comment|/* 37% of the blocksize */
name|int
name|m_dir_magicpct
decl_stmt|;
comment|/* 37% of the dir blocksize */
name|__uint8_t
name|m_mk_sharedro
decl_stmt|;
comment|/* mark shared ro on unmount */
name|__uint8_t
name|m_inode_quiesce
decl_stmt|;
comment|/* call quiesce on new inodes. 						   field governed by m_ilock */
name|__uint8_t
name|m_sectbb_log
decl_stmt|;
comment|/* sectlog - BBSHIFT */
name|__uint8_t
name|m_dirversion
decl_stmt|;
comment|/* 1 or 2 */
name|xfs_dirops_t
name|m_dirops
decl_stmt|;
comment|/* table of dir funcs */
name|int
name|m_dirblksize
decl_stmt|;
comment|/* directory block sz--bytes */
name|int
name|m_dirblkfsbs
decl_stmt|;
comment|/* directory block sz--fsbs */
name|xfs_dablk_t
name|m_dirdatablk
decl_stmt|;
comment|/* blockno of dir data v2 */
name|xfs_dablk_t
name|m_dirleafblk
decl_stmt|;
comment|/* blockno of dir non-data v2 */
name|xfs_dablk_t
name|m_dirfreeblk
decl_stmt|;
comment|/* blockno of dirfreeindex v2 */
name|uint
name|m_chsize
decl_stmt|;
comment|/* size of next field */
name|struct
name|xfs_chash
modifier|*
name|m_chash
decl_stmt|;
comment|/* fs private inode per-cluster 						 * hash table */
name|struct
name|xfs_dmops
name|m_dm_ops
decl_stmt|;
comment|/* vector of DMI ops */
name|struct
name|xfs_qmops
name|m_qm_ops
decl_stmt|;
comment|/* vector of XQM ops */
name|struct
name|xfs_ioops
name|m_io_ops
decl_stmt|;
comment|/* vector of I/O ops */
name|atomic_t
name|m_active_trans
decl_stmt|;
comment|/* number trans frozen */
ifdef|#
directive|ifdef
name|HAVE_PERCPU_SB
name|xfs_icsb_cnts_t
modifier|*
name|m_sb_cnts
decl_stmt|;
comment|/* per-cpu superblock counters */
name|unsigned
name|long
name|m_icsb_counters
decl_stmt|;
comment|/* disabled per-cpu counters */
name|struct
name|notifier_block
name|m_icsb_notifier
decl_stmt|;
comment|/* hotplug cpu notifier */
endif|#
directive|endif
block|}
name|xfs_mount_t
typedef|;
end_typedef

begin_comment
comment|/*  * Flags for m_flags.  */
end_comment

begin_define
define|#
directive|define
name|XFS_MOUNT_WSYNC
value|(1ULL<< 0)
end_define

begin_comment
comment|/* for nfs - all metadata ops 						   must be synchronous except 						   for space allocations */
end_comment

begin_define
define|#
directive|define
name|XFS_MOUNT_INO64
value|(1ULL<< 1)
end_define

begin_comment
comment|/* (1ULL<< 2)	-- currently unused */
end_comment

begin_comment
comment|/* (1ULL<< 3)	-- currently unused */
end_comment

begin_define
define|#
directive|define
name|XFS_MOUNT_FS_SHUTDOWN
value|(1ULL<< 4)
end_define

begin_comment
comment|/* atomic stop of all filesystem 						   operations, typically for 						   disk errors in metadata */
end_comment

begin_define
define|#
directive|define
name|XFS_MOUNT_RETERR
value|(1ULL<< 6)
end_define

begin_comment
comment|/* return alignment errors to 						   user */
end_comment

begin_define
define|#
directive|define
name|XFS_MOUNT_NOALIGN
value|(1ULL<< 7)
end_define

begin_comment
comment|/* turn off stripe alignment 						   allocations */
end_comment

begin_define
define|#
directive|define
name|XFS_MOUNT_ATTR2
value|(1ULL<< 8)
end_define

begin_comment
comment|/* allow use of attr2 format */
end_comment

begin_comment
comment|/*	(1ULL<< 9)	-- currently unused */
end_comment

begin_define
define|#
directive|define
name|XFS_MOUNT_NORECOVERY
value|(1ULL<< 10)
end_define

begin_comment
comment|/* no recovery - dirty fs */
end_comment

begin_define
define|#
directive|define
name|XFS_MOUNT_SHARED
value|(1ULL<< 11)
end_define

begin_comment
comment|/* shared mount */
end_comment

begin_define
define|#
directive|define
name|XFS_MOUNT_DFLT_IOSIZE
value|(1ULL<< 12)
end_define

begin_comment
comment|/* set default i/o size */
end_comment

begin_define
define|#
directive|define
name|XFS_MOUNT_OSYNCISOSYNC
value|(1ULL<< 13)
end_define

begin_comment
comment|/* o_sync is REALLY o_sync */
end_comment

begin_comment
comment|/* osyncisdsync is now default*/
end_comment

begin_define
define|#
directive|define
name|XFS_MOUNT_32BITINODES
value|(1ULL<< 14)
end_define

begin_comment
comment|/* do not create inodes above 						 * 32 bits in size */
end_comment

begin_comment
comment|/* (1ULL<< 15)	-- currently unused */
end_comment

begin_define
define|#
directive|define
name|XFS_MOUNT_NOUUID
value|(1ULL<< 16)
end_define

begin_comment
comment|/* ignore uuid during mount */
end_comment

begin_define
define|#
directive|define
name|XFS_MOUNT_BARRIER
value|(1ULL<< 17)
end_define

begin_define
define|#
directive|define
name|XFS_MOUNT_IDELETE
value|(1ULL<< 18)
end_define

begin_comment
comment|/* delete empty inode clusters*/
end_comment

begin_define
define|#
directive|define
name|XFS_MOUNT_SWALLOC
value|(1ULL<< 19)
end_define

begin_comment
comment|/* turn on stripe width 						 * allocation */
end_comment

begin_define
define|#
directive|define
name|XFS_MOUNT_IHASHSIZE
value|(1ULL<< 20)
end_define

begin_comment
comment|/* inode hash table size */
end_comment

begin_define
define|#
directive|define
name|XFS_MOUNT_DIRSYNC
value|(1ULL<< 21)
end_define

begin_comment
comment|/* synchronous directory ops */
end_comment

begin_define
define|#
directive|define
name|XFS_MOUNT_COMPAT_IOSIZE
value|(1ULL<< 22)
end_define

begin_comment
comment|/* don't report large preferred 						 * I/O size in stat() */
end_comment

begin_define
define|#
directive|define
name|XFS_MOUNT_NO_PERCPU_SB
value|(1ULL<< 23)
end_define

begin_comment
comment|/* don't use per-cpu superblock 						   counters */
end_comment

begin_comment
comment|/*  * Default minimum read and write sizes.  */
end_comment

begin_define
define|#
directive|define
name|XFS_READIO_LOG_LARGE
value|16
end_define

begin_define
define|#
directive|define
name|XFS_WRITEIO_LOG_LARGE
value|16
end_define

begin_comment
comment|/*  * Max and min values for mount-option defined I/O  * preallocation sizes.  */
end_comment

begin_define
define|#
directive|define
name|XFS_MAX_IO_LOG
value|30
end_define

begin_comment
comment|/* 1G */
end_comment

begin_define
define|#
directive|define
name|XFS_MIN_IO_LOG
value|PAGE_SHIFT
end_define

begin_comment
comment|/*  * Synchronous read and write sizes.  This should be  * better for NFSv2 wsync filesystems.  */
end_comment

begin_define
define|#
directive|define
name|XFS_WSYNC_READIO_LOG
value|15
end_define

begin_comment
comment|/* 32K */
end_comment

begin_define
define|#
directive|define
name|XFS_WSYNC_WRITEIO_LOG
value|14
end_define

begin_comment
comment|/* 16K */
end_comment

begin_comment
comment|/*  * Allow large block sizes to be reported to userspace programs if the  * "largeio" mount option is used.   *  * If compatibility mode is specified, simply return the basic unit of caching  * so that we don't get inefficient read/modify/write I/O from user apps.  * Otherwise....  *  * If the underlying volume is a stripe, then return the stripe width in bytes  * as the recommended I/O size. It is not a stripe and we've set a default  * buffered I/O size, return that, otherwise return the compat default.  */
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|xfs_preferred_iosize
parameter_list|(
name|xfs_mount_t
modifier|*
name|mp
parameter_list|)
block|{
if|if
condition|(
name|mp
operator|->
name|m_flags
operator|&
name|XFS_MOUNT_COMPAT_IOSIZE
condition|)
return|return
name|PAGE_CACHE_SIZE
return|;
return|return
operator|(
name|mp
operator|->
name|m_swidth
condition|?
operator|(
name|mp
operator|->
name|m_swidth
operator|<<
name|mp
operator|->
name|m_sb
operator|.
name|sb_blocklog
operator|)
else|:
operator|(
operator|(
name|mp
operator|->
name|m_flags
operator|&
name|XFS_MOUNT_DFLT_IOSIZE
operator|)
condition|?
operator|(
literal|1
operator|<<
operator|(
name|int
operator|)
name|MAX
argument_list|(
name|mp
operator|->
name|m_readio_log
argument_list|,
name|mp
operator|->
name|m_writeio_log
argument_list|)
operator|)
else|:
name|PAGE_CACHE_SIZE
operator|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_MAXIOFFSET
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_maxioffset)
end_define

begin_define
define|#
directive|define
name|XFS_FORCED_SHUTDOWN
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_flags& XFS_MOUNT_FS_SHUTDOWN)
end_define

begin_define
define|#
directive|define
name|xfs_force_shutdown
parameter_list|(
name|m
parameter_list|,
name|f
parameter_list|)
define|\
value|XVFS_FORCE_SHUTDOWN((XFS_MTOVFS(m)), f, __FILE__, __LINE__)
end_define

begin_comment
comment|/*  * Flags sent to xfs_force_shutdown.  */
end_comment

begin_define
define|#
directive|define
name|XFS_METADATA_IO_ERROR
value|0x1
end_define

begin_define
define|#
directive|define
name|XFS_LOG_IO_ERROR
value|0x2
end_define

begin_define
define|#
directive|define
name|XFS_FORCE_UMOUNT
value|0x4
end_define

begin_define
define|#
directive|define
name|XFS_CORRUPT_INCORE
value|0x8
end_define

begin_comment
comment|/* Corrupt in-memory data structures */
end_comment

begin_define
define|#
directive|define
name|XFS_SHUTDOWN_REMOTE_REQ
value|0x10
end_define

begin_comment
comment|/* Shutdown came from remote cell */
end_comment

begin_comment
comment|/*  * Flags for xfs_mountfs  */
end_comment

begin_define
define|#
directive|define
name|XFS_MFSI_SECOND
value|0x01
end_define

begin_comment
comment|/* Secondary mount -- skip stuff */
end_comment

begin_define
define|#
directive|define
name|XFS_MFSI_CLIENT
value|0x02
end_define

begin_comment
comment|/* Is a client -- skip lots of stuff */
end_comment

begin_comment
comment|/*	XFS_MFSI_RRINODES	*/
end_comment

begin_define
define|#
directive|define
name|XFS_MFSI_NOUNLINK
value|0x08
end_define

begin_comment
comment|/* Skip unlinked inode processing in */
end_comment

begin_comment
comment|/* log recovery */
end_comment

begin_define
define|#
directive|define
name|XFS_MFSI_NO_QUOTACHECK
value|0x10
end_define

begin_comment
comment|/* Skip quotacheck processing */
end_comment

begin_comment
comment|/*	XFS_MFSI_CONVERT_SUNIT	*/
end_comment

begin_define
define|#
directive|define
name|XFS_MFSI_QUIET
value|0x40
end_define

begin_comment
comment|/* Be silent if mount errors found */
end_comment

begin_comment
comment|/*  * Macros for getting from mount to vfs and back.  */
end_comment

begin_define
define|#
directive|define
name|XFS_MTOVFS
parameter_list|(
name|mp
parameter_list|)
value|xfs_mtovfs(mp)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_vfs_t
modifier|*
name|xfs_mtovfs
parameter_list|(
name|xfs_mount_t
modifier|*
name|mp
parameter_list|)
block|{
return|return
name|bhvtovfs
argument_list|(
operator|&
name|mp
operator|->
name|m_bhv
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_BHVTOM
parameter_list|(
name|bdp
parameter_list|)
value|xfs_bhvtom(bdp)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_mount_t
modifier|*
name|xfs_bhvtom
parameter_list|(
name|bhv_desc_t
modifier|*
name|bdp
parameter_list|)
block|{
return|return
operator|(
name|xfs_mount_t
operator|*
operator|)
name|BHV_PDATA
argument_list|(
name|bdp
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_VFSTOM
parameter_list|(
name|vfs
parameter_list|)
value|xfs_vfstom(vfs)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_mount_t
modifier|*
name|xfs_vfstom
parameter_list|(
name|xfs_vfs_t
modifier|*
name|vfs
parameter_list|)
block|{
return|return
name|XFS_BHVTOM
argument_list|(
name|bhv_lookup
argument_list|(
name|VFS_BHVHEAD
argument_list|(
name|vfs
argument_list|)
argument_list|,
operator|&
name|xfs_vfsops
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_DADDR_TO_AGNO
parameter_list|(
name|mp
parameter_list|,
name|d
parameter_list|)
value|xfs_daddr_to_agno(mp,d)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_agnumber_t
name|xfs_daddr_to_agno
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_daddr_t
name|d
parameter_list|)
block|{
name|xfs_daddr_t
name|ld
init|=
name|XFS_BB_TO_FSBT
argument_list|(
name|mp
argument_list|,
name|d
argument_list|)
decl_stmt|;
name|do_div
argument_list|(
name|ld
argument_list|,
name|mp
operator|->
name|m_sb
operator|.
name|sb_agblocks
argument_list|)
expr_stmt|;
return|return
operator|(
name|xfs_agnumber_t
operator|)
name|ld
return|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_DADDR_TO_AGBNO
parameter_list|(
name|mp
parameter_list|,
name|d
parameter_list|)
value|xfs_daddr_to_agbno(mp,d)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_agblock_t
name|xfs_daddr_to_agbno
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_daddr_t
name|d
parameter_list|)
block|{
name|xfs_daddr_t
name|ld
init|=
name|XFS_BB_TO_FSBT
argument_list|(
name|mp
argument_list|,
name|d
argument_list|)
decl_stmt|;
return|return
operator|(
name|xfs_agblock_t
operator|)
name|do_div
argument_list|(
name|ld
argument_list|,
name|mp
operator|->
name|m_sb
operator|.
name|sb_agblocks
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * This structure is for use by the xfs_mod_incore_sb_batch() routine.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_mod_sb
block|{
name|xfs_sb_field_t
name|msb_field
decl_stmt|;
comment|/* Field to modify, see below */
name|int
name|msb_delta
decl_stmt|;
comment|/* Change to make to specified field */
block|}
name|xfs_mod_sb_t
typedef|;
end_typedef

begin_comment
comment|/* FreeBSD specfic */
end_comment

begin_define
define|#
directive|define
name|XFS_MOUNT_ILOCK
parameter_list|(
name|mp
parameter_list|)
value|sx_xlock(&((mp)->m_ilock))
end_define

begin_define
define|#
directive|define
name|XFS_MOUNT_IUNLOCK
parameter_list|(
name|mp
parameter_list|)
value|sx_xunlock(&((mp)->m_ilock))
end_define

begin_define
define|#
directive|define
name|XFS_SB_LOCK
parameter_list|(
name|mp
parameter_list|)
value|mutex_spinlock(&(mp)->m_sb_lock)
end_define

begin_define
define|#
directive|define
name|XFS_SB_UNLOCK
parameter_list|(
name|mp
parameter_list|,
name|s
parameter_list|)
value|mutex_spinunlock(&(mp)->m_sb_lock,(s))
end_define

begin_function_decl
specifier|extern
name|xfs_mount_t
modifier|*
name|xfs_mount_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_mod_sb
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|__int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_mount_free
parameter_list|(
name|xfs_mount_t
modifier|*
name|mp
parameter_list|,
name|int
name|remove_bhv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_mountfs
parameter_list|(
name|struct
name|xfs_vfs
modifier|*
parameter_list|,
name|xfs_mount_t
modifier|*
name|mp
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_mountfs_check_barriers
parameter_list|(
name|xfs_mount_t
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_unmountfs
parameter_list|(
name|xfs_mount_t
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
name|void
name|xfs_unmountfs_close
parameter_list|(
name|xfs_mount_t
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
name|xfs_unmountfs_writesb
parameter_list|(
name|xfs_mount_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_unmount_flush
parameter_list|(
name|xfs_mount_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_mod_incore_sb
parameter_list|(
name|xfs_mount_t
modifier|*
parameter_list|,
name|xfs_sb_field_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_mod_incore_sb_unlocked
parameter_list|(
name|xfs_mount_t
modifier|*
parameter_list|,
name|xfs_sb_field_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_mod_incore_sb_batch
parameter_list|(
name|xfs_mount_t
modifier|*
parameter_list|,
name|xfs_mod_sb_t
modifier|*
parameter_list|,
name|uint
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|xfs_buf
modifier|*
name|xfs_getsb
parameter_list|(
name|xfs_mount_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_readsb
parameter_list|(
name|xfs_mount_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_freesb
parameter_list|(
name|xfs_mount_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_do_force_shutdown
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

begin_function_decl
specifier|extern
name|int
name|xfs_syncsub
parameter_list|(
name|xfs_mount_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_sync_inodes
parameter_list|(
name|xfs_mount_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|xfs_agnumber_t
name|xfs_initialize_perag
parameter_list|(
name|struct
name|xfs_vfs
modifier|*
parameter_list|,
name|xfs_mount_t
modifier|*
parameter_list|,
name|xfs_agnumber_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_xlatesb
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|xfs_sb
modifier|*
parameter_list|,
name|int
parameter_list|,
name|__int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|xfs_dmops
name|xfs_dmcore_stub
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|xfs_qmops
name|xfs_qmcore_stub
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|xfs_ioops
name|xfs_iocore_xfs
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|xfs_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_MOUNT_H__ */
end_comment

end_unit

