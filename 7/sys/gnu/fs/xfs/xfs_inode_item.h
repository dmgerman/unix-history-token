begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_INODE_ITEM_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_INODE_ITEM_H__
end_define

begin_comment
comment|/*  * This is the structure used to lay out an inode log item in the  * log.  The size of the inline data/extents/b-tree root to be logged  * (if any) is indicated in the ilf_dsize field.  Changes to this structure  * must be added on to the end.  *  * Convention for naming inode log item versions :  The current version  * is always named XFS_LI_INODE.  When an inode log item gets superseded,  * add the latest version of IRIX that will generate logs with that item  * to the version name.  *  * -Version 1 of this structure (XFS_LI_5_3_INODE) included up to the first  *	union (ilf_u) field.  This was released with IRIX 5.3-XFS.  * -Version 2 of this structure (XFS_LI_6_1_INODE) is currently the entire  *	structure.  This was released with IRIX 6.0.1-XFS and IRIX 6.1.  * -Version 3 of this structure (XFS_LI_INODE) is the same as version 2  *	so a new structure definition wasn't necessary.  However, we had  *	to add a new type because the inode cluster size changed from 4K  *	to 8K and the version number had to be rev'ved to keep older kernels  *	from trying to recover logs with the 8K buffers in them.  The logging  *	code can handle recovery on different-sized clusters now so hopefully  *	this'll be the last time we need to change the inode log item just  *	for a change in the inode cluster size.  This new version was  *	released with IRIX 6.2.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_inode_log_format
block|{
name|unsigned
name|short
name|ilf_type
decl_stmt|;
comment|/* inode log item type */
name|unsigned
name|short
name|ilf_size
decl_stmt|;
comment|/* size of this item */
name|uint
name|ilf_fields
decl_stmt|;
comment|/* flags for fields logged */
name|ushort
name|ilf_asize
decl_stmt|;
comment|/* size of attr d/ext/root */
name|ushort
name|ilf_dsize
decl_stmt|;
comment|/* size of data/ext/root */
name|xfs_ino_t
name|ilf_ino
decl_stmt|;
comment|/* inode number */
union|union
block|{
name|xfs_dev_t
name|ilfu_rdev
decl_stmt|;
comment|/* rdev value for dev inode*/
name|uuid_t
name|ilfu_uuid
decl_stmt|;
comment|/* mount point value */
block|}
name|ilf_u
union|;
name|__int64_t
name|ilf_blkno
decl_stmt|;
comment|/* blkno of inode buffer */
name|int
name|ilf_len
decl_stmt|;
comment|/* len of inode buffer */
name|int
name|ilf_boffset
decl_stmt|;
comment|/* off of inode in buffer */
block|}
name|xfs_inode_log_format_t
typedef|;
end_typedef

begin_comment
comment|/* Initial version shipped with IRIX 5.3-XFS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_inode_log_format_v1
block|{
name|unsigned
name|short
name|ilf_type
decl_stmt|;
comment|/* inode log item type */
name|unsigned
name|short
name|ilf_size
decl_stmt|;
comment|/* size of this item */
name|uint
name|ilf_fields
decl_stmt|;
comment|/* flags for fields logged */
name|uint
name|ilf_dsize
decl_stmt|;
comment|/* size of data/ext/root */
name|xfs_ino_t
name|ilf_ino
decl_stmt|;
comment|/* inode number */
union|union
block|{
name|xfs_dev_t
name|ilfu_rdev
decl_stmt|;
comment|/* rdev value for dev inode*/
name|uuid_t
name|ilfu_uuid
decl_stmt|;
comment|/* mount point value */
block|}
name|ilf_u
union|;
block|}
name|xfs_inode_log_format_t_v1
typedef|;
end_typedef

begin_comment
comment|/*  * Flags for xfs_trans_log_inode flags field.  */
end_comment

begin_define
define|#
directive|define
name|XFS_ILOG_CORE
value|0x001
end_define

begin_comment
comment|/* log standard inode fields */
end_comment

begin_define
define|#
directive|define
name|XFS_ILOG_DDATA
value|0x002
end_define

begin_comment
comment|/* log i_df.if_data */
end_comment

begin_define
define|#
directive|define
name|XFS_ILOG_DEXT
value|0x004
end_define

begin_comment
comment|/* log i_df.if_extents */
end_comment

begin_define
define|#
directive|define
name|XFS_ILOG_DBROOT
value|0x008
end_define

begin_comment
comment|/* log i_df.i_broot */
end_comment

begin_define
define|#
directive|define
name|XFS_ILOG_DEV
value|0x010
end_define

begin_comment
comment|/* log the dev field */
end_comment

begin_define
define|#
directive|define
name|XFS_ILOG_UUID
value|0x020
end_define

begin_comment
comment|/* log the uuid field */
end_comment

begin_define
define|#
directive|define
name|XFS_ILOG_ADATA
value|0x040
end_define

begin_comment
comment|/* log i_af.if_data */
end_comment

begin_define
define|#
directive|define
name|XFS_ILOG_AEXT
value|0x080
end_define

begin_comment
comment|/* log i_af.if_extents */
end_comment

begin_define
define|#
directive|define
name|XFS_ILOG_ABROOT
value|0x100
end_define

begin_comment
comment|/* log i_af.i_broot */
end_comment

begin_define
define|#
directive|define
name|XFS_ILOG_NONCORE
value|(XFS_ILOG_DDATA | XFS_ILOG_DEXT | \ 				 XFS_ILOG_DBROOT | XFS_ILOG_DEV | \ 				 XFS_ILOG_UUID | XFS_ILOG_ADATA | \ 				 XFS_ILOG_AEXT | XFS_ILOG_ABROOT)
end_define

begin_define
define|#
directive|define
name|XFS_ILOG_DFORK
value|(XFS_ILOG_DDATA | XFS_ILOG_DEXT | \ 				 XFS_ILOG_DBROOT)
end_define

begin_define
define|#
directive|define
name|XFS_ILOG_AFORK
value|(XFS_ILOG_ADATA | XFS_ILOG_AEXT | \ 				 XFS_ILOG_ABROOT)
end_define

begin_define
define|#
directive|define
name|XFS_ILOG_ALL
value|(XFS_ILOG_CORE | XFS_ILOG_DDATA | \ 				 XFS_ILOG_DEXT | XFS_ILOG_DBROOT | \ 				 XFS_ILOG_DEV | XFS_ILOG_UUID | \ 				 XFS_ILOG_ADATA | XFS_ILOG_AEXT | \ 				 XFS_ILOG_ABROOT)
end_define

begin_define
define|#
directive|define
name|XFS_ILI_HOLD
value|0x1
end_define

begin_define
define|#
directive|define
name|XFS_ILI_IOLOCKED_EXCL
value|0x2
end_define

begin_define
define|#
directive|define
name|XFS_ILI_IOLOCKED_SHARED
value|0x4
end_define

begin_define
define|#
directive|define
name|XFS_ILI_IOLOCKED_ANY
value|(XFS_ILI_IOLOCKED_EXCL | XFS_ILI_IOLOCKED_SHARED)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_struct_decl
struct_decl|struct
name|xfs_buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_bmbt_rec_64
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_inode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_mount
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|xfs_inode_log_item
block|{
name|xfs_log_item_t
name|ili_item
decl_stmt|;
comment|/* common portion */
name|struct
name|xfs_inode
modifier|*
name|ili_inode
decl_stmt|;
comment|/* inode ptr */
name|xfs_lsn_t
name|ili_flush_lsn
decl_stmt|;
comment|/* lsn at last flush */
name|xfs_lsn_t
name|ili_last_lsn
decl_stmt|;
comment|/* lsn at last transaction */
name|unsigned
name|short
name|ili_ilock_recur
decl_stmt|;
comment|/* lock recursion count */
name|unsigned
name|short
name|ili_iolock_recur
decl_stmt|;
comment|/* lock recursion count */
name|unsigned
name|short
name|ili_flags
decl_stmt|;
comment|/* misc flags */
name|unsigned
name|short
name|ili_logged
decl_stmt|;
comment|/* flushed logged data */
name|unsigned
name|int
name|ili_last_fields
decl_stmt|;
comment|/* fields when flushed */
name|struct
name|xfs_bmbt_rec_64
modifier|*
name|ili_extents_buf
decl_stmt|;
comment|/* array of logged 						      data exts */
name|struct
name|xfs_bmbt_rec_64
modifier|*
name|ili_aextents_buf
decl_stmt|;
comment|/* array of logged 						      attr exts */
name|unsigned
name|int
name|ili_pushbuf_flag
decl_stmt|;
comment|/* one bit used in push_ail */
ifdef|#
directive|ifdef
name|DEBUG
name|uint64_t
name|ili_push_owner
decl_stmt|;
comment|/* one who sets pushbuf_flag 						      above gets to push the buf */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|XFS_TRANS_DEBUG
name|int
name|ili_root_size
decl_stmt|;
name|char
modifier|*
name|ili_orig_root
decl_stmt|;
endif|#
directive|endif
name|xfs_inode_log_format_t
name|ili_format
decl_stmt|;
comment|/* logged structure */
block|}
name|xfs_inode_log_item_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_ILOG_FDATA
parameter_list|(
name|w
parameter_list|)
value|xfs_ilog_fdata(w)
end_define

begin_function
specifier|static
specifier|inline
name|int
name|xfs_ilog_fdata
parameter_list|(
name|int
name|w
parameter_list|)
block|{
return|return
operator|(
name|w
operator|==
name|XFS_DATA_FORK
condition|?
name|XFS_ILOG_DDATA
else|:
name|XFS_ILOG_ADATA
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_define
define|#
directive|define
name|XFS_ILOG_FBROOT
parameter_list|(
name|w
parameter_list|)
value|xfs_ilog_fbroot(w)
end_define

begin_function
specifier|static
specifier|inline
name|int
name|xfs_ilog_fbroot
parameter_list|(
name|int
name|w
parameter_list|)
block|{
return|return
operator|(
name|w
operator|==
name|XFS_DATA_FORK
condition|?
name|XFS_ILOG_DBROOT
else|:
name|XFS_ILOG_ABROOT
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_ILOG_FEXT
parameter_list|(
name|w
parameter_list|)
value|xfs_ilog_fext(w)
end_define

begin_function
specifier|static
specifier|inline
name|int
name|xfs_ilog_fext
parameter_list|(
name|int
name|w
parameter_list|)
block|{
return|return
operator|(
name|w
operator|==
name|XFS_DATA_FORK
condition|?
name|XFS_ILOG_DEXT
else|:
name|XFS_ILOG_AEXT
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_function_decl
specifier|extern
name|void
name|xfs_inode_item_init
parameter_list|(
name|struct
name|xfs_inode
modifier|*
parameter_list|,
name|struct
name|xfs_mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_inode_item_destroy
parameter_list|(
name|struct
name|xfs_inode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_iflush_done
parameter_list|(
name|struct
name|xfs_buf
modifier|*
parameter_list|,
name|xfs_inode_log_item_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_istale_done
parameter_list|(
name|struct
name|xfs_buf
modifier|*
parameter_list|,
name|xfs_inode_log_item_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_iflush_abort
parameter_list|(
name|struct
name|xfs_inode
modifier|*
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
comment|/* __XFS_INODE_ITEM_H__ */
end_comment

end_unit

