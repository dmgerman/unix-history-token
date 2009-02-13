begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2002,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_TRANS_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_TRANS_H__
end_define

begin_comment
comment|/*  * This is the structure written in the log at the head of  * every transaction. It identifies the type and id of the  * transaction, and contains the number of items logged by  * the transaction so we know how many to expect during recovery.  *  * Do not change the below structure without redoing the code in  * xlog_recover_add_to_trans() and xlog_recover_add_to_cont_trans().  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_trans_header
block|{
name|uint
name|th_magic
decl_stmt|;
comment|/* magic number */
name|uint
name|th_type
decl_stmt|;
comment|/* transaction type */
name|__int32_t
name|th_tid
decl_stmt|;
comment|/* transaction id (unused) */
name|uint
name|th_num_items
decl_stmt|;
comment|/* num items logged by trans */
block|}
name|xfs_trans_header_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_TRANS_HEADER_MAGIC
value|0x5452414e
end_define

begin_comment
comment|/* TRAN */
end_comment

begin_comment
comment|/*  * Log item types.  */
end_comment

begin_define
define|#
directive|define
name|XFS_LI_5_3_BUF
value|0x1234
end_define

begin_comment
comment|/* v1 bufs, 1-block inode buffers */
end_comment

begin_define
define|#
directive|define
name|XFS_LI_5_3_INODE
value|0x1235
end_define

begin_comment
comment|/* 1-block inode buffers */
end_comment

begin_define
define|#
directive|define
name|XFS_LI_EFI
value|0x1236
end_define

begin_define
define|#
directive|define
name|XFS_LI_EFD
value|0x1237
end_define

begin_define
define|#
directive|define
name|XFS_LI_IUNLINK
value|0x1238
end_define

begin_define
define|#
directive|define
name|XFS_LI_6_1_INODE
value|0x1239
end_define

begin_comment
comment|/* 4K non-aligned inode bufs */
end_comment

begin_define
define|#
directive|define
name|XFS_LI_6_1_BUF
value|0x123a
end_define

begin_comment
comment|/* v1, 4K inode buffers */
end_comment

begin_define
define|#
directive|define
name|XFS_LI_INODE
value|0x123b
end_define

begin_comment
comment|/* aligned ino chunks, var-size ibufs */
end_comment

begin_define
define|#
directive|define
name|XFS_LI_BUF
value|0x123c
end_define

begin_comment
comment|/* v2 bufs, variable sized inode bufs */
end_comment

begin_define
define|#
directive|define
name|XFS_LI_DQUOT
value|0x123d
end_define

begin_define
define|#
directive|define
name|XFS_LI_QUOTAOFF
value|0x123e
end_define

begin_comment
comment|/*  * Transaction types.  Used to distinguish types of buffers.  */
end_comment

begin_define
define|#
directive|define
name|XFS_TRANS_SETATTR_NOT_SIZE
value|1
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_SETATTR_SIZE
value|2
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_INACTIVE
value|3
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_CREATE
value|4
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_CREATE_TRUNC
value|5
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_TRUNCATE_FILE
value|6
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_REMOVE
value|7
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_LINK
value|8
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_RENAME
value|9
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_MKDIR
value|10
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_RMDIR
value|11
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_SYMLINK
value|12
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_SET_DMATTRS
value|13
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_GROWFS
value|14
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_STRAT_WRITE
value|15
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_DIOSTRAT
value|16
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_WRITE_SYNC
value|17
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_WRITEID
value|18
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_ADDAFORK
value|19
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_ATTRINVAL
value|20
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_ATRUNCATE
value|21
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_ATTR_SET
value|22
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_ATTR_RM
value|23
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_ATTR_FLAG
value|24
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_CLEAR_AGI_BUCKET
value|25
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_QM_SBCHANGE
value|26
end_define

begin_comment
comment|/*  * Dummy entries since we use the transaction type to index into the  * trans_type[] in xlog_recover_print_trans_head()  */
end_comment

begin_define
define|#
directive|define
name|XFS_TRANS_DUMMY1
value|27
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_DUMMY2
value|28
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_QM_QUOTAOFF
value|29
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_QM_DQALLOC
value|30
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_QM_SETQLIM
value|31
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_QM_DQCLUSTER
value|32
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_QM_QINOCREATE
value|33
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_QM_QUOTAOFF_END
value|34
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_SB_UNIT
value|35
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_FSYNC_TS
value|36
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_GROWFSRT_ALLOC
value|37
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_GROWFSRT_ZERO
value|38
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_GROWFSRT_FREE
value|39
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_SWAPEXT
value|40
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_TYPE_MAX
value|40
end_define

begin_comment
comment|/* new transaction types need to be reflected in xfs_logprint(8) */
end_comment

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
name|xfs_buftarg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_efd_log_item
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_efi_log_item
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_inode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_item_ops
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_log_iovec
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_log_item
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_log_item_desc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_mount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_trans
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_dquot_acct
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|xfs_ail_entry
block|{
name|struct
name|xfs_log_item
modifier|*
name|ail_forw
decl_stmt|;
comment|/* AIL forw pointer */
name|struct
name|xfs_log_item
modifier|*
name|ail_back
decl_stmt|;
comment|/* AIL back pointer */
block|}
name|xfs_ail_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_log_item
block|{
name|xfs_ail_entry_t
name|li_ail
decl_stmt|;
comment|/* AIL pointers */
name|xfs_lsn_t
name|li_lsn
decl_stmt|;
comment|/* last on-disk lsn */
name|struct
name|xfs_log_item_desc
modifier|*
name|li_desc
decl_stmt|;
comment|/* ptr to current desc*/
name|struct
name|xfs_mount
modifier|*
name|li_mountp
decl_stmt|;
comment|/* ptr to fs mount */
name|uint
name|li_type
decl_stmt|;
comment|/* item type */
name|uint
name|li_flags
decl_stmt|;
comment|/* misc flags */
name|struct
name|xfs_log_item
modifier|*
name|li_bio_list
decl_stmt|;
comment|/* buffer item list */
name|void
function_decl|(
modifier|*
name|li_cb
function_decl|)
parameter_list|(
name|struct
name|xfs_buf
modifier|*
parameter_list|,
name|struct
name|xfs_log_item
modifier|*
parameter_list|)
function_decl|;
comment|/* buffer item iodone */
comment|/* callback func */
name|struct
name|xfs_item_ops
modifier|*
name|li_ops
decl_stmt|;
comment|/* function list */
block|}
name|xfs_log_item_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_LI_IN_AIL
value|0x1
end_define

begin_define
define|#
directive|define
name|XFS_LI_ABORTED
value|0x2
end_define

begin_typedef
typedef|typedef
struct|struct
name|xfs_item_ops
block|{
name|uint
function_decl|(
modifier|*
name|iop_size
function_decl|)
parameter_list|(
name|xfs_log_item_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|iop_format
function_decl|)
parameter_list|(
name|xfs_log_item_t
modifier|*
parameter_list|,
name|struct
name|xfs_log_iovec
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|iop_pin
function_decl|)
parameter_list|(
name|xfs_log_item_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|iop_unpin
function_decl|)
parameter_list|(
name|xfs_log_item_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|iop_unpin_remove
function_decl|)
parameter_list|(
name|xfs_log_item_t
modifier|*
parameter_list|,
name|struct
name|xfs_trans
modifier|*
parameter_list|)
function_decl|;
name|uint
function_decl|(
modifier|*
name|iop_trylock
function_decl|)
parameter_list|(
name|xfs_log_item_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|iop_unlock
function_decl|)
parameter_list|(
name|xfs_log_item_t
modifier|*
parameter_list|)
function_decl|;
name|xfs_lsn_t
function_decl|(
modifier|*
name|iop_committed
function_decl|)
parameter_list|(
name|xfs_log_item_t
modifier|*
parameter_list|,
name|xfs_lsn_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|iop_push
function_decl|)
parameter_list|(
name|xfs_log_item_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|iop_abort
function_decl|)
parameter_list|(
name|xfs_log_item_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|iop_pushbuf
function_decl|)
parameter_list|(
name|xfs_log_item_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|iop_committing
function_decl|)
parameter_list|(
name|xfs_log_item_t
modifier|*
parameter_list|,
name|xfs_lsn_t
parameter_list|)
function_decl|;
block|}
name|xfs_item_ops_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IOP_SIZE
parameter_list|(
name|ip
parameter_list|)
value|(*(ip)->li_ops->iop_size)(ip)
end_define

begin_define
define|#
directive|define
name|IOP_FORMAT
parameter_list|(
name|ip
parameter_list|,
name|vp
parameter_list|)
value|(*(ip)->li_ops->iop_format)(ip, vp)
end_define

begin_define
define|#
directive|define
name|IOP_PIN
parameter_list|(
name|ip
parameter_list|)
value|(*(ip)->li_ops->iop_pin)(ip)
end_define

begin_define
define|#
directive|define
name|IOP_UNPIN
parameter_list|(
name|ip
parameter_list|,
name|flags
parameter_list|)
value|(*(ip)->li_ops->iop_unpin)(ip, flags)
end_define

begin_define
define|#
directive|define
name|IOP_UNPIN_REMOVE
parameter_list|(
name|ip
parameter_list|,
name|tp
parameter_list|)
value|(*(ip)->li_ops->iop_unpin_remove)(ip, tp)
end_define

begin_define
define|#
directive|define
name|IOP_TRYLOCK
parameter_list|(
name|ip
parameter_list|)
value|(*(ip)->li_ops->iop_trylock)(ip)
end_define

begin_define
define|#
directive|define
name|IOP_UNLOCK
parameter_list|(
name|ip
parameter_list|)
value|(*(ip)->li_ops->iop_unlock)(ip)
end_define

begin_define
define|#
directive|define
name|IOP_COMMITTED
parameter_list|(
name|ip
parameter_list|,
name|lsn
parameter_list|)
value|(*(ip)->li_ops->iop_committed)(ip, lsn)
end_define

begin_define
define|#
directive|define
name|IOP_PUSH
parameter_list|(
name|ip
parameter_list|)
value|(*(ip)->li_ops->iop_push)(ip)
end_define

begin_define
define|#
directive|define
name|IOP_ABORT
parameter_list|(
name|ip
parameter_list|)
value|(*(ip)->li_ops->iop_abort)(ip)
end_define

begin_define
define|#
directive|define
name|IOP_PUSHBUF
parameter_list|(
name|ip
parameter_list|)
value|(*(ip)->li_ops->iop_pushbuf)(ip)
end_define

begin_define
define|#
directive|define
name|IOP_COMMITTING
parameter_list|(
name|ip
parameter_list|,
name|lsn
parameter_list|)
value|(*(ip)->li_ops->iop_committing)(ip, lsn)
end_define

begin_comment
comment|/*  * Return values for the IOP_TRYLOCK() routines.  */
end_comment

begin_define
define|#
directive|define
name|XFS_ITEM_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|XFS_ITEM_PINNED
value|1
end_define

begin_define
define|#
directive|define
name|XFS_ITEM_LOCKED
value|2
end_define

begin_define
define|#
directive|define
name|XFS_ITEM_FLUSHING
value|3
end_define

begin_define
define|#
directive|define
name|XFS_ITEM_PUSHBUF
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_comment
comment|/*  * This structure is used to track log items associated with  * a transaction.  It points to the log item and keeps some  * flags to track the state of the log item.  It also tracks  * the amount of space needed to log the item it describes  * once we get to commit processing (see xfs_trans_commit()).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_log_item_desc
block|{
name|xfs_log_item_t
modifier|*
name|lid_item
decl_stmt|;
name|ushort
name|lid_size
decl_stmt|;
name|unsigned
name|char
name|lid_flags
decl_stmt|;
name|unsigned
name|char
name|lid_index
decl_stmt|;
block|}
name|xfs_log_item_desc_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_LID_DIRTY
value|0x1
end_define

begin_define
define|#
directive|define
name|XFS_LID_PINNED
value|0x2
end_define

begin_define
define|#
directive|define
name|XFS_LID_BUF_STALE
value|0x8
end_define

begin_comment
comment|/*  * This structure is used to maintain a chunk list of log_item_desc  * structures. The free field is a bitmask indicating which descriptors  * in this chunk's array are free.  The unused field is the first value  * not used since this chunk was allocated.  */
end_comment

begin_define
define|#
directive|define
name|XFS_LIC_NUM_SLOTS
value|15
end_define

begin_typedef
typedef|typedef
struct|struct
name|xfs_log_item_chunk
block|{
name|struct
name|xfs_log_item_chunk
modifier|*
name|lic_next
decl_stmt|;
name|ushort
name|lic_free
decl_stmt|;
name|ushort
name|lic_unused
decl_stmt|;
name|xfs_log_item_desc_t
name|lic_descs
index|[
name|XFS_LIC_NUM_SLOTS
index|]
decl_stmt|;
block|}
name|xfs_log_item_chunk_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_LIC_MAX_SLOT
value|(XFS_LIC_NUM_SLOTS - 1)
end_define

begin_define
define|#
directive|define
name|XFS_LIC_FREEMASK
value|((1<< XFS_LIC_NUM_SLOTS) - 1)
end_define

begin_comment
comment|/*  * Initialize the given chunk.  Set the chunk's free descriptor mask  * to indicate that all descriptors are free.  The caller gets to set  * lic_unused to the right value (0 matches all free).  The  * lic_descs.lid_index values are set up as each desc is allocated.  */
end_comment

begin_define
define|#
directive|define
name|XFS_LIC_INIT
parameter_list|(
name|cp
parameter_list|)
value|xfs_lic_init(cp)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|xfs_lic_init
parameter_list|(
name|xfs_log_item_chunk_t
modifier|*
name|cp
parameter_list|)
block|{
name|cp
operator|->
name|lic_free
operator|=
name|XFS_LIC_FREEMASK
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_LIC_INIT_SLOT
parameter_list|(
name|cp
parameter_list|,
name|slot
parameter_list|)
value|xfs_lic_init_slot(cp, slot)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|xfs_lic_init_slot
parameter_list|(
name|xfs_log_item_chunk_t
modifier|*
name|cp
parameter_list|,
name|int
name|slot
parameter_list|)
block|{
name|cp
operator|->
name|lic_descs
index|[
name|slot
index|]
operator|.
name|lid_index
operator|=
call|(
name|unsigned
name|char
call|)
argument_list|(
name|slot
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_LIC_VACANCY
parameter_list|(
name|cp
parameter_list|)
value|xfs_lic_vacancy(cp)
end_define

begin_function
specifier|static
specifier|inline
name|int
name|xfs_lic_vacancy
parameter_list|(
name|xfs_log_item_chunk_t
modifier|*
name|cp
parameter_list|)
block|{
return|return
name|cp
operator|->
name|lic_free
operator|&
name|XFS_LIC_FREEMASK
return|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_LIC_ALL_FREE
parameter_list|(
name|cp
parameter_list|)
value|xfs_lic_all_free(cp)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|xfs_lic_all_free
parameter_list|(
name|xfs_log_item_chunk_t
modifier|*
name|cp
parameter_list|)
block|{
name|cp
operator|->
name|lic_free
operator|=
name|XFS_LIC_FREEMASK
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_LIC_ARE_ALL_FREE
parameter_list|(
name|cp
parameter_list|)
value|xfs_lic_are_all_free(cp)
end_define

begin_function
specifier|static
specifier|inline
name|int
name|xfs_lic_are_all_free
parameter_list|(
name|xfs_log_item_chunk_t
modifier|*
name|cp
parameter_list|)
block|{
return|return
operator|(
operator|(
name|cp
operator|->
name|lic_free
operator|&
name|XFS_LIC_FREEMASK
operator|)
operator|==
name|XFS_LIC_FREEMASK
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_LIC_ISFREE
parameter_list|(
name|cp
parameter_list|,
name|slot
parameter_list|)
value|xfs_lic_isfree(cp,slot)
end_define

begin_function
specifier|static
specifier|inline
name|int
name|xfs_lic_isfree
parameter_list|(
name|xfs_log_item_chunk_t
modifier|*
name|cp
parameter_list|,
name|int
name|slot
parameter_list|)
block|{
return|return
operator|(
name|cp
operator|->
name|lic_free
operator|&
operator|(
literal|1
operator|<<
name|slot
operator|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_LIC_CLAIM
parameter_list|(
name|cp
parameter_list|,
name|slot
parameter_list|)
value|xfs_lic_claim(cp,slot)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|xfs_lic_claim
parameter_list|(
name|xfs_log_item_chunk_t
modifier|*
name|cp
parameter_list|,
name|int
name|slot
parameter_list|)
block|{
name|cp
operator|->
name|lic_free
operator|&=
operator|~
operator|(
literal|1
operator|<<
name|slot
operator|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_LIC_RELSE
parameter_list|(
name|cp
parameter_list|,
name|slot
parameter_list|)
value|xfs_lic_relse(cp,slot)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|xfs_lic_relse
parameter_list|(
name|xfs_log_item_chunk_t
modifier|*
name|cp
parameter_list|,
name|int
name|slot
parameter_list|)
block|{
name|cp
operator|->
name|lic_free
operator||=
literal|1
operator|<<
name|slot
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_LIC_SLOT
parameter_list|(
name|cp
parameter_list|,
name|slot
parameter_list|)
value|xfs_lic_slot(cp,slot)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_log_item_desc_t
modifier|*
name|xfs_lic_slot
parameter_list|(
name|xfs_log_item_chunk_t
modifier|*
name|cp
parameter_list|,
name|int
name|slot
parameter_list|)
block|{
return|return
operator|&
operator|(
name|cp
operator|->
name|lic_descs
index|[
name|slot
index|]
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_LIC_DESC_TO_SLOT
parameter_list|(
name|dp
parameter_list|)
value|xfs_lic_desc_to_slot(dp)
end_define

begin_function
specifier|static
specifier|inline
name|int
name|xfs_lic_desc_to_slot
parameter_list|(
name|xfs_log_item_desc_t
modifier|*
name|dp
parameter_list|)
block|{
return|return
operator|(
name|uint
operator|)
name|dp
operator|->
name|lid_index
return|;
block|}
end_function

begin_comment
comment|/*  * Calculate the address of a chunk given a descriptor pointer:  * dp - dp->lid_index give the address of the start of the lic_descs array.  * From this we subtract the offset of the lic_descs field in a chunk.  * All of this yields the address of the chunk, which is  * cast to a chunk pointer.  */
end_comment

begin_define
define|#
directive|define
name|XFS_LIC_DESC_TO_CHUNK
parameter_list|(
name|dp
parameter_list|)
value|xfs_lic_desc_to_chunk(dp)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_log_item_chunk_t
modifier|*
name|xfs_lic_desc_to_chunk
parameter_list|(
name|xfs_log_item_desc_t
modifier|*
name|dp
parameter_list|)
block|{
return|return
operator|(
name|xfs_log_item_chunk_t
operator|*
operator|)
expr|\
operator|(
operator|(
call|(
name|xfs_caddr_t
call|)
argument_list|(
operator|(
name|dp
operator|)
operator|-
operator|(
name|dp
operator|)
operator|->
name|lid_index
argument_list|)
operator|)
operator|-
expr|\
call|(
name|xfs_caddr_t
call|)
argument_list|(
operator|(
operator|(
name|xfs_log_item_chunk_t
operator|*
operator|)
literal|0
operator|)
operator|->
name|lic_descs
argument_list|)
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_comment
comment|/*  * This structure is used to maintain a list of block ranges that have been  * freed in the transaction.  The ranges are listed in the perag[] busy list  * between when they're freed and the transaction is committed to disk.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_log_busy_slot
block|{
name|xfs_agnumber_t
name|lbc_ag
decl_stmt|;
name|ushort
name|lbc_idx
decl_stmt|;
comment|/* index in perag.busy[] */
block|}
name|xfs_log_busy_slot_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_LBC_NUM_SLOTS
value|31
end_define

begin_typedef
typedef|typedef
struct|struct
name|xfs_log_busy_chunk
block|{
name|struct
name|xfs_log_busy_chunk
modifier|*
name|lbc_next
decl_stmt|;
name|uint
name|lbc_free
decl_stmt|;
comment|/* free slots bitmask */
name|ushort
name|lbc_unused
decl_stmt|;
comment|/* first unused */
name|xfs_log_busy_slot_t
name|lbc_busy
index|[
name|XFS_LBC_NUM_SLOTS
index|]
decl_stmt|;
block|}
name|xfs_log_busy_chunk_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_LBC_MAX_SLOT
value|(XFS_LBC_NUM_SLOTS - 1)
end_define

begin_define
define|#
directive|define
name|XFS_LBC_FREEMASK
value|((1U<< XFS_LBC_NUM_SLOTS) - 1)
end_define

begin_define
define|#
directive|define
name|XFS_LBC_INIT
parameter_list|(
name|cp
parameter_list|)
value|((cp)->lbc_free = XFS_LBC_FREEMASK)
end_define

begin_define
define|#
directive|define
name|XFS_LBC_CLAIM
parameter_list|(
name|cp
parameter_list|,
name|slot
parameter_list|)
value|((cp)->lbc_free&= ~(1<< (slot)))
end_define

begin_define
define|#
directive|define
name|XFS_LBC_SLOT
parameter_list|(
name|cp
parameter_list|,
name|slot
parameter_list|)
value|(&((cp)->lbc_busy[(slot)]))
end_define

begin_define
define|#
directive|define
name|XFS_LBC_VACANCY
parameter_list|(
name|cp
parameter_list|)
value|(((cp)->lbc_free)& XFS_LBC_FREEMASK)
end_define

begin_define
define|#
directive|define
name|XFS_LBC_ISFREE
parameter_list|(
name|cp
parameter_list|,
name|slot
parameter_list|)
value|((cp)->lbc_free& (1<< (slot)))
end_define

begin_comment
comment|/*  * This is the type of function which can be given to xfs_trans_callback()  * to be called upon the transaction's commit to disk.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xfs_trans_callback_t
function_decl|)
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * This is the structure maintained for every active transaction.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_trans
block|{
name|unsigned
name|int
name|t_magic
decl_stmt|;
comment|/* magic number */
name|xfs_log_callback_t
name|t_logcb
decl_stmt|;
comment|/* log callback struct */
name|struct
name|xfs_trans
modifier|*
name|t_forw
decl_stmt|;
comment|/* async list pointers */
name|struct
name|xfs_trans
modifier|*
name|t_back
decl_stmt|;
comment|/* async list pointers */
name|unsigned
name|int
name|t_type
decl_stmt|;
comment|/* transaction type */
name|unsigned
name|int
name|t_log_res
decl_stmt|;
comment|/* amt of log space resvd */
name|unsigned
name|int
name|t_log_count
decl_stmt|;
comment|/* count for perm log res */
name|unsigned
name|int
name|t_blk_res
decl_stmt|;
comment|/* # of blocks resvd */
name|unsigned
name|int
name|t_blk_res_used
decl_stmt|;
comment|/* # of resvd blocks used */
name|unsigned
name|int
name|t_rtx_res
decl_stmt|;
comment|/* # of rt extents resvd */
name|unsigned
name|int
name|t_rtx_res_used
decl_stmt|;
comment|/* # of resvd rt extents used */
name|xfs_log_ticket_t
name|t_ticket
decl_stmt|;
comment|/* log mgr ticket */
name|sema_t
name|t_sema
decl_stmt|;
comment|/* sema for commit completion */
name|xfs_lsn_t
name|t_lsn
decl_stmt|;
comment|/* log seq num of start of 						 * transaction. */
name|xfs_lsn_t
name|t_commit_lsn
decl_stmt|;
comment|/* log seq num of end of 						 * transaction. */
name|struct
name|xfs_mount
modifier|*
name|t_mountp
decl_stmt|;
comment|/* ptr to fs mount struct */
name|struct
name|xfs_dquot_acct
modifier|*
name|t_dqinfo
decl_stmt|;
comment|/* acctg info for dquots */
name|xfs_trans_callback_t
name|t_callback
decl_stmt|;
comment|/* transaction callback */
name|void
modifier|*
name|t_callarg
decl_stmt|;
comment|/* callback arg */
name|unsigned
name|int
name|t_flags
decl_stmt|;
comment|/* misc flags */
name|long
name|t_icount_delta
decl_stmt|;
comment|/* superblock icount change */
name|long
name|t_ifree_delta
decl_stmt|;
comment|/* superblock ifree change */
name|long
name|t_fdblocks_delta
decl_stmt|;
comment|/* superblock fdblocks chg */
name|long
name|t_res_fdblocks_delta
decl_stmt|;
comment|/* on-disk only chg */
name|long
name|t_frextents_delta
decl_stmt|;
comment|/* superblock freextents chg*/
name|long
name|t_res_frextents_delta
decl_stmt|;
comment|/* on-disk only chg */
name|long
name|t_ag_freeblks_delta
decl_stmt|;
comment|/* debugging counter */
name|long
name|t_ag_flist_delta
decl_stmt|;
comment|/* debugging counter */
name|long
name|t_ag_btree_delta
decl_stmt|;
comment|/* debugging counter */
name|long
name|t_dblocks_delta
decl_stmt|;
comment|/* superblock dblocks change */
name|long
name|t_agcount_delta
decl_stmt|;
comment|/* superblock agcount change */
name|long
name|t_imaxpct_delta
decl_stmt|;
comment|/* superblock imaxpct change */
name|long
name|t_rextsize_delta
decl_stmt|;
comment|/* superblock rextsize chg */
name|long
name|t_rbmblocks_delta
decl_stmt|;
comment|/* superblock rbmblocks chg */
name|long
name|t_rblocks_delta
decl_stmt|;
comment|/* superblock rblocks change */
name|long
name|t_rextents_delta
decl_stmt|;
comment|/* superblocks rextents chg */
name|long
name|t_rextslog_delta
decl_stmt|;
comment|/* superblocks rextslog chg */
name|unsigned
name|int
name|t_items_free
decl_stmt|;
comment|/* log item descs free */
name|xfs_log_item_chunk_t
name|t_items
decl_stmt|;
comment|/* first log item desc chunk */
name|xfs_trans_header_t
name|t_header
decl_stmt|;
comment|/* header for in-log trans */
name|unsigned
name|int
name|t_busy_free
decl_stmt|;
comment|/* busy descs free */
name|xfs_log_busy_chunk_t
name|t_busy
decl_stmt|;
comment|/* busy/async free blocks */
name|unsigned
name|long
name|t_pflags
decl_stmt|;
comment|/* saved process flags state */
block|}
name|xfs_trans_t
typedef|;
end_typedef

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
name|XFS_TRANS_MAGIC
value|0x5452414E
end_define

begin_comment
comment|/* 'TRAN' */
end_comment

begin_comment
comment|/*  * Values for t_flags.  */
end_comment

begin_define
define|#
directive|define
name|XFS_TRANS_DIRTY
value|0x01
end_define

begin_comment
comment|/* something needs to be logged */
end_comment

begin_define
define|#
directive|define
name|XFS_TRANS_SB_DIRTY
value|0x02
end_define

begin_comment
comment|/* superblock is modified */
end_comment

begin_define
define|#
directive|define
name|XFS_TRANS_PERM_LOG_RES
value|0x04
end_define

begin_comment
comment|/* xact took a permanent log res */
end_comment

begin_define
define|#
directive|define
name|XFS_TRANS_SYNC
value|0x08
end_define

begin_comment
comment|/* make commit synchronous */
end_comment

begin_define
define|#
directive|define
name|XFS_TRANS_DQ_DIRTY
value|0x10
end_define

begin_comment
comment|/* at least one dquot in trx dirty */
end_comment

begin_define
define|#
directive|define
name|XFS_TRANS_RESERVE
value|0x20
end_define

begin_comment
comment|/* OK to use reserved data blocks */
end_comment

begin_comment
comment|/*  * Values for call flags parameter.  */
end_comment

begin_define
define|#
directive|define
name|XFS_TRANS_NOSLEEP
value|0x1
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_WAIT
value|0x2
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_RELEASE_LOG_RES
value|0x4
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_ABORT
value|0x8
end_define

begin_comment
comment|/*  * Field values for xfs_trans_mod_sb.  */
end_comment

begin_define
define|#
directive|define
name|XFS_TRANS_SB_ICOUNT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_SB_IFREE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_SB_FDBLOCKS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_SB_RES_FDBLOCKS
value|0x00000008
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_SB_FREXTENTS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_SB_RES_FREXTENTS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_SB_DBLOCKS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_SB_AGCOUNT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_SB_IMAXPCT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_SB_REXTSIZE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_SB_RBMBLOCKS
value|0x00000400
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_SB_RBLOCKS
value|0x00000800
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_SB_REXTENTS
value|0x00001000
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_SB_REXTSLOG
value|0x00002000
end_define

begin_comment
comment|/*  * Various log reservation values.  * These are based on the size of the file system block  * because that is what most transactions manipulate.  * Each adds in an additional 128 bytes per item logged to  * try to account for the overhead of the transaction mechanism.  *  * Note:  * Most of the reservations underestimate the number of allocation  * groups into which they could free extents in the xfs_bmap_finish()  * call.  This is because the number in the worst case is quite high  * and quite unusual.  In order to fix this we need to change  * xfs_bmap_finish() to free extents in only a single AG at a time.  * This will require changes to the EFI code as well, however, so that  * the EFI for the extents not freed is logged again in each transaction.  * See bug 261917.  */
end_comment

begin_comment
comment|/*  * Per-extent log reservation for the allocation btree changes  * involved in freeing or allocating an extent.  * 2 trees * (2 blocks/level * max depth - 1) * block size  */
end_comment

begin_define
define|#
directive|define
name|XFS_ALLOCFREE_LOG_RES
parameter_list|(
name|mp
parameter_list|,
name|nx
parameter_list|)
define|\
value|((nx) * (2 * XFS_FSB_TO_B((mp), 2 * XFS_AG_MAXLEVELS(mp) - 1)))
end_define

begin_define
define|#
directive|define
name|XFS_ALLOCFREE_LOG_COUNT
parameter_list|(
name|mp
parameter_list|,
name|nx
parameter_list|)
define|\
value|((nx) * (2 * (2 * XFS_AG_MAXLEVELS(mp) - 1)))
end_define

begin_comment
comment|/*  * Per-directory log reservation for any directory change.  * dir blocks: (1 btree block per level + data block + free block) * dblock size  * bmap btree: (levels + 2) * max depth * block size  * v2 directory blocks can be fragmented below the dirblksize down to the fsb  * size, so account for that in the DAENTER macros.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIROP_LOG_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|(XFS_FSB_TO_B(mp, XFS_DAENTER_BLOCKS(mp, XFS_DATA_FORK)) + \ 	 (XFS_FSB_TO_B(mp, XFS_DAENTER_BMAPS(mp, XFS_DATA_FORK) + 1)))
end_define

begin_define
define|#
directive|define
name|XFS_DIROP_LOG_COUNT
parameter_list|(
name|mp
parameter_list|)
define|\
value|(XFS_DAENTER_BLOCKS(mp, XFS_DATA_FORK) + \ 	 XFS_DAENTER_BMAPS(mp, XFS_DATA_FORK) + 1)
end_define

begin_comment
comment|/*  * In a write transaction we can allocate a maximum of 2  * extents.  This gives:  *    the inode getting the new extents: inode size  *    the inode\'s bmap btree: max depth * block size  *    the agfs of the ags from which the extents are allocated: 2 * sector  *    the superblock free block counter: sector size  *    the allocation btrees: 2 exts * 2 trees * (2 * max depth - 1) * block size  * And the bmap_finish transaction can free bmap blocks in a join:  *    the agfs of the ags containing the blocks: 2 * sector size  *    the agfls of the ags containing the blocks: 2 * sector size  *    the super block free block counter: sector size  *    the allocation btrees: 2 exts * 2 trees * (2 * max depth - 1) * block size  */
end_comment

begin_define
define|#
directive|define
name|XFS_CALC_WRITE_LOG_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|(MAX( \ 	 ((mp)->m_sb.sb_inodesize + \ 	  XFS_FSB_TO_B((mp), XFS_BM_MAXLEVELS(mp, XFS_DATA_FORK)) + \ 	  (2 * (mp)->m_sb.sb_sectsize) + \ 	  (mp)->m_sb.sb_sectsize + \ 	  XFS_ALLOCFREE_LOG_RES(mp, 2) + \ 	  (128 * (4 + XFS_BM_MAXLEVELS(mp, XFS_DATA_FORK) + XFS_ALLOCFREE_LOG_COUNT(mp, 2)))),\ 	 ((2 * (mp)->m_sb.sb_sectsize) + \ 	  (2 * (mp)->m_sb.sb_sectsize) + \ 	  (mp)->m_sb.sb_sectsize + \ 	  XFS_ALLOCFREE_LOG_RES(mp, 2) + \ 	  (128 * (5 + XFS_ALLOCFREE_LOG_COUNT(mp, 2))))))
end_define

begin_define
define|#
directive|define
name|XFS_WRITE_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_reservations.tr_write)
end_define

begin_comment
comment|/*  * In truncating a file we free up to two extents at once.  We can modify:  *    the inode being truncated: inode size  *    the inode\'s bmap btree: (max depth + 1) * block size  * And the bmap_finish transaction can free the blocks and bmap blocks:  *    the agf for each of the ags: 4 * sector size  *    the agfl for each of the ags: 4 * sector size  *    the super block to reflect the freed blocks: sector size  *    worst case split in allocation btrees per extent assuming 4 extents:  *		4 exts * 2 trees * (2 * max depth - 1) * block size  *    the inode btree: max depth * blocksize  *    the allocation btrees: 2 trees * (max depth - 1) * block size  */
end_comment

begin_define
define|#
directive|define
name|XFS_CALC_ITRUNCATE_LOG_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|(MAX( \ 	 ((mp)->m_sb.sb_inodesize + \ 	  XFS_FSB_TO_B((mp), XFS_BM_MAXLEVELS(mp, XFS_DATA_FORK) + 1) + \ 	  (128 * (2 + XFS_BM_MAXLEVELS(mp, XFS_DATA_FORK)))), \ 	 ((4 * (mp)->m_sb.sb_sectsize) + \ 	  (4 * (mp)->m_sb.sb_sectsize) + \ 	  (mp)->m_sb.sb_sectsize + \ 	  XFS_ALLOCFREE_LOG_RES(mp, 4) + \ 	  (128 * (9 + XFS_ALLOCFREE_LOG_COUNT(mp, 4))) + \ 	  (128 * 5) + \ 	  XFS_ALLOCFREE_LOG_RES(mp, 1) + \ 	   (128 * (2 + XFS_IALLOC_BLOCKS(mp) + XFS_IN_MAXLEVELS(mp) + \ 	    XFS_ALLOCFREE_LOG_COUNT(mp, 1))))))
end_define

begin_define
define|#
directive|define
name|XFS_ITRUNCATE_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_reservations.tr_itruncate)
end_define

begin_comment
comment|/*  * In renaming a files we can modify:  *    the four inodes involved: 4 * inode size  *    the two directory btrees: 2 * (max depth + v2) * dir block size  *    the two directory bmap btrees: 2 * max depth * block size  * And the bmap_finish transaction can free dir and bmap blocks (two sets  *	of bmap blocks) giving:  *    the agf for the ags in which the blocks live: 3 * sector size  *    the agfl for the ags in which the blocks live: 3 * sector size  *    the superblock for the free block count: sector size  *    the allocation btrees: 3 exts * 2 trees * (2 * max depth - 1) * block size  */
end_comment

begin_define
define|#
directive|define
name|XFS_CALC_RENAME_LOG_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|(MAX( \ 	 ((4 * (mp)->m_sb.sb_inodesize) + \ 	  (2 * XFS_DIROP_LOG_RES(mp)) + \ 	  (128 * (4 + 2 * XFS_DIROP_LOG_COUNT(mp)))), \ 	 ((3 * (mp)->m_sb.sb_sectsize) + \ 	  (3 * (mp)->m_sb.sb_sectsize) + \ 	  (mp)->m_sb.sb_sectsize + \ 	  XFS_ALLOCFREE_LOG_RES(mp, 3) + \ 	  (128 * (7 + XFS_ALLOCFREE_LOG_COUNT(mp, 3))))))
end_define

begin_define
define|#
directive|define
name|XFS_RENAME_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_reservations.tr_rename)
end_define

begin_comment
comment|/*  * For creating a link to an inode:  *    the parent directory inode: inode size  *    the linked inode: inode size  *    the directory btree could split: (max depth + v2) * dir block size  *    the directory bmap btree could join or split: (max depth + v2) * blocksize  * And the bmap_finish transaction can free some bmap blocks giving:  *    the agf for the ag in which the blocks live: sector size  *    the agfl for the ag in which the blocks live: sector size  *    the superblock for the free block count: sector size  *    the allocation btrees: 2 trees * (2 * max depth - 1) * block size  */
end_comment

begin_define
define|#
directive|define
name|XFS_CALC_LINK_LOG_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|(MAX( \ 	 ((mp)->m_sb.sb_inodesize + \ 	  (mp)->m_sb.sb_inodesize + \ 	  XFS_DIROP_LOG_RES(mp) + \ 	  (128 * (2 + XFS_DIROP_LOG_COUNT(mp)))), \ 	 ((mp)->m_sb.sb_sectsize + \ 	  (mp)->m_sb.sb_sectsize + \ 	  (mp)->m_sb.sb_sectsize + \ 	  XFS_ALLOCFREE_LOG_RES(mp, 1) + \ 	  (128 * (3 + XFS_ALLOCFREE_LOG_COUNT(mp, 1))))))
end_define

begin_define
define|#
directive|define
name|XFS_LINK_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_reservations.tr_link)
end_define

begin_comment
comment|/*  * For removing a directory entry we can modify:  *    the parent directory inode: inode size  *    the removed inode: inode size  *    the directory btree could join: (max depth + v2) * dir block size  *    the directory bmap btree could join or split: (max depth + v2) * blocksize  * And the bmap_finish transaction can free the dir and bmap blocks giving:  *    the agf for the ag in which the blocks live: 2 * sector size  *    the agfl for the ag in which the blocks live: 2 * sector size  *    the superblock for the free block count: sector size  *    the allocation btrees: 2 exts * 2 trees * (2 * max depth - 1) * block size  */
end_comment

begin_define
define|#
directive|define
name|XFS_CALC_REMOVE_LOG_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|(MAX( \ 	 ((mp)->m_sb.sb_inodesize + \ 	  (mp)->m_sb.sb_inodesize + \ 	  XFS_DIROP_LOG_RES(mp) + \ 	  (128 * (2 + XFS_DIROP_LOG_COUNT(mp)))), \ 	 ((2 * (mp)->m_sb.sb_sectsize) + \ 	  (2 * (mp)->m_sb.sb_sectsize) + \ 	  (mp)->m_sb.sb_sectsize + \ 	  XFS_ALLOCFREE_LOG_RES(mp, 2) + \ 	  (128 * (5 + XFS_ALLOCFREE_LOG_COUNT(mp, 2))))))
end_define

begin_define
define|#
directive|define
name|XFS_REMOVE_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_reservations.tr_remove)
end_define

begin_comment
comment|/*  * For symlink we can modify:  *    the parent directory inode: inode size  *    the new inode: inode size  *    the inode btree entry: 1 block  *    the directory btree: (max depth + v2) * dir block size  *    the directory inode\'s bmap btree: (max depth + v2) * block size  *    the blocks for the symlink: 1 KB  * Or in the first xact we allocate some inodes giving:  *    the agi and agf of the ag getting the new inodes: 2 * sectorsize  *    the inode blocks allocated: XFS_IALLOC_BLOCKS * blocksize  *    the inode btree: max depth * blocksize  *    the allocation btrees: 2 trees * (2 * max depth - 1) * block size  */
end_comment

begin_define
define|#
directive|define
name|XFS_CALC_SYMLINK_LOG_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|(MAX( \ 	 ((mp)->m_sb.sb_inodesize + \ 	  (mp)->m_sb.sb_inodesize + \ 	  XFS_FSB_TO_B(mp, 1) + \ 	  XFS_DIROP_LOG_RES(mp) + \ 	  1024 + \ 	  (128 * (4 + XFS_DIROP_LOG_COUNT(mp)))), \ 	 (2 * (mp)->m_sb.sb_sectsize + \ 	  XFS_FSB_TO_B((mp), XFS_IALLOC_BLOCKS((mp))) + \ 	  XFS_FSB_TO_B((mp), XFS_IN_MAXLEVELS(mp)) + \ 	  XFS_ALLOCFREE_LOG_RES(mp, 1) + \ 	  (128 * (2 + XFS_IALLOC_BLOCKS(mp) + XFS_IN_MAXLEVELS(mp) + \ 	   XFS_ALLOCFREE_LOG_COUNT(mp, 1))))))
end_define

begin_define
define|#
directive|define
name|XFS_SYMLINK_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_reservations.tr_symlink)
end_define

begin_comment
comment|/*  * For create we can modify:  *    the parent directory inode: inode size  *    the new inode: inode size  *    the inode btree entry: block size  *    the superblock for the nlink flag: sector size  *    the directory btree: (max depth + v2) * dir block size  *    the directory inode\'s bmap btree: (max depth + v2) * block size  * Or in the first xact we allocate some inodes giving:  *    the agi and agf of the ag getting the new inodes: 2 * sectorsize  *    the superblock for the nlink flag: sector size  *    the inode blocks allocated: XFS_IALLOC_BLOCKS * blocksize  *    the inode btree: max depth * blocksize  *    the allocation btrees: 2 trees * (max depth - 1) * block size  */
end_comment

begin_define
define|#
directive|define
name|XFS_CALC_CREATE_LOG_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|(MAX( \ 	 ((mp)->m_sb.sb_inodesize + \ 	  (mp)->m_sb.sb_inodesize + \ 	  (mp)->m_sb.sb_sectsize + \ 	  XFS_FSB_TO_B(mp, 1) + \ 	  XFS_DIROP_LOG_RES(mp) + \ 	  (128 * (3 + XFS_DIROP_LOG_COUNT(mp)))), \ 	 (3 * (mp)->m_sb.sb_sectsize + \ 	  XFS_FSB_TO_B((mp), XFS_IALLOC_BLOCKS((mp))) + \ 	  XFS_FSB_TO_B((mp), XFS_IN_MAXLEVELS(mp)) + \ 	  XFS_ALLOCFREE_LOG_RES(mp, 1) + \ 	  (128 * (2 + XFS_IALLOC_BLOCKS(mp) + XFS_IN_MAXLEVELS(mp) + \ 	   XFS_ALLOCFREE_LOG_COUNT(mp, 1))))))
end_define

begin_define
define|#
directive|define
name|XFS_CREATE_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_reservations.tr_create)
end_define

begin_comment
comment|/*  * Making a new directory is the same as creating a new file.  */
end_comment

begin_define
define|#
directive|define
name|XFS_CALC_MKDIR_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|XFS_CALC_CREATE_LOG_RES(mp)
end_define

begin_define
define|#
directive|define
name|XFS_MKDIR_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_reservations.tr_mkdir)
end_define

begin_comment
comment|/*  * In freeing an inode we can modify:  *    the inode being freed: inode size  *    the super block free inode counter: sector size  *    the agi hash list and counters: sector size  *    the inode btree entry: block size  *    the on disk inode before ours in the agi hash list: inode cluster size  *    the inode btree: max depth * blocksize  *    the allocation btrees: 2 trees * (max depth - 1) * block size  */
end_comment

begin_define
define|#
directive|define
name|XFS_CALC_IFREE_LOG_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|((mp)->m_sb.sb_inodesize + \ 	 (mp)->m_sb.sb_sectsize + \ 	 (mp)->m_sb.sb_sectsize + \ 	 XFS_FSB_TO_B((mp), 1) + \ 	 MAX((__uint16_t)XFS_FSB_TO_B((mp), 1), XFS_INODE_CLUSTER_SIZE(mp)) + \ 	 (128 * 5) + \ 	  XFS_ALLOCFREE_LOG_RES(mp, 1) + \ 	  (128 * (2 + XFS_IALLOC_BLOCKS(mp) + XFS_IN_MAXLEVELS(mp) + \ 	   XFS_ALLOCFREE_LOG_COUNT(mp, 1))))
end_define

begin_define
define|#
directive|define
name|XFS_IFREE_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_reservations.tr_ifree)
end_define

begin_comment
comment|/*  * When only changing the inode we log the inode and possibly the superblock  * We also add a bit of slop for the transaction stuff.  */
end_comment

begin_define
define|#
directive|define
name|XFS_CALC_ICHANGE_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_sb.sb_inodesize + \ 					 (mp)->m_sb.sb_sectsize + 512)
end_define

begin_define
define|#
directive|define
name|XFS_ICHANGE_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_reservations.tr_ichange)
end_define

begin_comment
comment|/*  * Growing the data section of the filesystem.  *	superblock  *	agi and agf  *	allocation btrees  */
end_comment

begin_define
define|#
directive|define
name|XFS_CALC_GROWDATA_LOG_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|((mp)->m_sb.sb_sectsize * 3 + \ 	 XFS_ALLOCFREE_LOG_RES(mp, 1) + \ 	 (128 * (3 + XFS_ALLOCFREE_LOG_COUNT(mp, 1))))
end_define

begin_define
define|#
directive|define
name|XFS_GROWDATA_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_reservations.tr_growdata)
end_define

begin_comment
comment|/*  * Growing the rt section of the filesystem.  * In the first set of transactions (ALLOC) we allocate space to the  * bitmap or summary files.  *	superblock: sector size  *	agf of the ag from which the extent is allocated: sector size  *	bmap btree for bitmap/summary inode: max depth * blocksize  *	bitmap/summary inode: inode size  *	allocation btrees for 1 block alloc: 2 * (2 * maxdepth - 1) * blocksize  */
end_comment

begin_define
define|#
directive|define
name|XFS_CALC_GROWRTALLOC_LOG_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|(2 * (mp)->m_sb.sb_sectsize + \ 	 XFS_FSB_TO_B((mp), XFS_BM_MAXLEVELS(mp, XFS_DATA_FORK)) + \ 	 (mp)->m_sb.sb_inodesize + \ 	 XFS_ALLOCFREE_LOG_RES(mp, 1) + \ 	 (128 * \ 	  (3 + XFS_BM_MAXLEVELS(mp, XFS_DATA_FORK) + \ 	   XFS_ALLOCFREE_LOG_COUNT(mp, 1))))
end_define

begin_define
define|#
directive|define
name|XFS_GROWRTALLOC_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_reservations.tr_growrtalloc)
end_define

begin_comment
comment|/*  * Growing the rt section of the filesystem.  * In the second set of transactions (ZERO) we zero the new metadata blocks.  *	one bitmap/summary block: blocksize  */
end_comment

begin_define
define|#
directive|define
name|XFS_CALC_GROWRTZERO_LOG_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|((mp)->m_sb.sb_blocksize + 128)
end_define

begin_define
define|#
directive|define
name|XFS_GROWRTZERO_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_reservations.tr_growrtzero)
end_define

begin_comment
comment|/*  * Growing the rt section of the filesystem.  * In the third set of transactions (FREE) we update metadata without  * allocating any new blocks.  *	superblock: sector size  *	bitmap inode: inode size  *	summary inode: inode size  *	one bitmap block: blocksize  *	summary blocks: new summary size  */
end_comment

begin_define
define|#
directive|define
name|XFS_CALC_GROWRTFREE_LOG_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|((mp)->m_sb.sb_sectsize + \ 	 2 * (mp)->m_sb.sb_inodesize + \ 	 (mp)->m_sb.sb_blocksize + \ 	 (mp)->m_rsumsize + \ 	 (128 * 5))
end_define

begin_define
define|#
directive|define
name|XFS_GROWRTFREE_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_reservations.tr_growrtfree)
end_define

begin_comment
comment|/*  * Logging the inode modification timestamp on a synchronous write.  *	inode  */
end_comment

begin_define
define|#
directive|define
name|XFS_CALC_SWRITE_LOG_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|((mp)->m_sb.sb_inodesize + 128)
end_define

begin_define
define|#
directive|define
name|XFS_SWRITE_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_reservations.tr_swrite)
end_define

begin_comment
comment|/*  * Logging the inode timestamps on an fsync -- same as SWRITE  * as long as SWRITE logs the entire inode core  */
end_comment

begin_define
define|#
directive|define
name|XFS_FSYNC_TS_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_reservations.tr_swrite)
end_define

begin_comment
comment|/*  * Logging the inode mode bits when writing a setuid/setgid file  *	inode  */
end_comment

begin_define
define|#
directive|define
name|XFS_CALC_WRITEID_LOG_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|((mp)->m_sb.sb_inodesize + 128)
end_define

begin_define
define|#
directive|define
name|XFS_WRITEID_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_reservations.tr_swrite)
end_define

begin_comment
comment|/*  * Converting the inode from non-attributed to attributed.  *	the inode being converted: inode size  *	agf block and superblock (for block allocation)  *	the new block (directory sized)  *	bmap blocks for the new directory block  *	allocation btrees  */
end_comment

begin_define
define|#
directive|define
name|XFS_CALC_ADDAFORK_LOG_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|((mp)->m_sb.sb_inodesize + \ 	 (mp)->m_sb.sb_sectsize * 2 + \ 	 (mp)->m_dirblksize + \ 	 (XFS_DIR_IS_V1(mp) ? 0 : \ 	    XFS_FSB_TO_B(mp, (XFS_DAENTER_BMAP1B(mp, XFS_DATA_FORK) + 1))) + \ 	 XFS_ALLOCFREE_LOG_RES(mp, 1) + \ 	 (128 * (4 + \ 		 (XFS_DIR_IS_V1(mp) ? 0 : \ 			 XFS_DAENTER_BMAP1B(mp, XFS_DATA_FORK) + 1) + \ 		 XFS_ALLOCFREE_LOG_COUNT(mp, 1))))
end_define

begin_define
define|#
directive|define
name|XFS_ADDAFORK_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_reservations.tr_addafork)
end_define

begin_comment
comment|/*  * Removing the attribute fork of a file  *    the inode being truncated: inode size  *    the inode\'s bmap btree: max depth * block size  * And the bmap_finish transaction can free the blocks and bmap blocks:  *    the agf for each of the ags: 4 * sector size  *    the agfl for each of the ags: 4 * sector size  *    the super block to reflect the freed blocks: sector size  *    worst case split in allocation btrees per extent assuming 4 extents:  *		4 exts * 2 trees * (2 * max depth - 1) * block size  */
end_comment

begin_define
define|#
directive|define
name|XFS_CALC_ATTRINVAL_LOG_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|(MAX( \ 	 ((mp)->m_sb.sb_inodesize + \ 	  XFS_FSB_TO_B((mp), XFS_BM_MAXLEVELS(mp, XFS_ATTR_FORK)) + \ 	  (128 * (1 + XFS_BM_MAXLEVELS(mp, XFS_ATTR_FORK)))), \ 	 ((4 * (mp)->m_sb.sb_sectsize) + \ 	  (4 * (mp)->m_sb.sb_sectsize) + \ 	  (mp)->m_sb.sb_sectsize + \ 	  XFS_ALLOCFREE_LOG_RES(mp, 4) + \ 	  (128 * (9 + XFS_ALLOCFREE_LOG_COUNT(mp, 4))))))
end_define

begin_define
define|#
directive|define
name|XFS_ATTRINVAL_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_reservations.tr_attrinval)
end_define

begin_comment
comment|/*  * Setting an attribute.  *	the inode getting the attribute  *	the superblock for allocations  *	the agfs extents are allocated from  *	the attribute btree * max depth  *	the inode allocation btree  * Since attribute transaction space is dependent on the size of the attribute,  * the calculation is done partially at mount time and partially at runtime.  */
end_comment

begin_define
define|#
directive|define
name|XFS_CALC_ATTRSET_LOG_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|((mp)->m_sb.sb_inodesize + \ 	 (mp)->m_sb.sb_sectsize + \ 	  XFS_FSB_TO_B((mp), XFS_DA_NODE_MAXDEPTH) + \ 	  (128 * (2 + XFS_DA_NODE_MAXDEPTH)))
end_define

begin_define
define|#
directive|define
name|XFS_ATTRSET_LOG_RES
parameter_list|(
name|mp
parameter_list|,
name|ext
parameter_list|)
define|\
value|((mp)->m_reservations.tr_attrset + \ 	 (ext * (mp)->m_sb.sb_sectsize) + \ 	 (ext * XFS_FSB_TO_B((mp), XFS_BM_MAXLEVELS(mp, XFS_ATTR_FORK))) + \ 	 (128 * (ext + (ext * XFS_BM_MAXLEVELS(mp, XFS_ATTR_FORK)))))
end_define

begin_comment
comment|/*  * Removing an attribute.  *    the inode: inode size  *    the attribute btree could join: max depth * block size  *    the inode bmap btree could join or split: max depth * block size  * And the bmap_finish transaction can free the attr blocks freed giving:  *    the agf for the ag in which the blocks live: 2 * sector size  *    the agfl for the ag in which the blocks live: 2 * sector size  *    the superblock for the free block count: sector size  *    the allocation btrees: 2 exts * 2 trees * (2 * max depth - 1) * block size  */
end_comment

begin_define
define|#
directive|define
name|XFS_CALC_ATTRRM_LOG_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|(MAX( \ 	  ((mp)->m_sb.sb_inodesize + \ 	  XFS_FSB_TO_B((mp), XFS_DA_NODE_MAXDEPTH) + \ 	  XFS_FSB_TO_B((mp), XFS_BM_MAXLEVELS(mp, XFS_ATTR_FORK)) + \ 	  (128 * (1 + XFS_DA_NODE_MAXDEPTH + XFS_BM_MAXLEVELS(mp, XFS_DATA_FORK)))), \ 	 ((2 * (mp)->m_sb.sb_sectsize) + \ 	  (2 * (mp)->m_sb.sb_sectsize) + \ 	  (mp)->m_sb.sb_sectsize + \ 	  XFS_ALLOCFREE_LOG_RES(mp, 2) + \ 	  (128 * (5 + XFS_ALLOCFREE_LOG_COUNT(mp, 2))))))
end_define

begin_define
define|#
directive|define
name|XFS_ATTRRM_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_reservations.tr_attrrm)
end_define

begin_comment
comment|/*  * Clearing a bad agino number in an agi hash bucket.  */
end_comment

begin_define
define|#
directive|define
name|XFS_CALC_CLEAR_AGI_BUCKET_LOG_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|((mp)->m_sb.sb_sectsize + 128)
end_define

begin_define
define|#
directive|define
name|XFS_CLEAR_AGI_BUCKET_LOG_RES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_reservations.tr_clearagi)
end_define

begin_comment
comment|/*  * Various log count values.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DEFAULT_LOG_COUNT
value|1
end_define

begin_define
define|#
directive|define
name|XFS_DEFAULT_PERM_LOG_COUNT
value|2
end_define

begin_define
define|#
directive|define
name|XFS_ITRUNCATE_LOG_COUNT
value|2
end_define

begin_define
define|#
directive|define
name|XFS_INACTIVE_LOG_COUNT
value|2
end_define

begin_define
define|#
directive|define
name|XFS_CREATE_LOG_COUNT
value|2
end_define

begin_define
define|#
directive|define
name|XFS_MKDIR_LOG_COUNT
value|3
end_define

begin_define
define|#
directive|define
name|XFS_SYMLINK_LOG_COUNT
value|3
end_define

begin_define
define|#
directive|define
name|XFS_REMOVE_LOG_COUNT
value|2
end_define

begin_define
define|#
directive|define
name|XFS_LINK_LOG_COUNT
value|2
end_define

begin_define
define|#
directive|define
name|XFS_RENAME_LOG_COUNT
value|2
end_define

begin_define
define|#
directive|define
name|XFS_WRITE_LOG_COUNT
value|2
end_define

begin_define
define|#
directive|define
name|XFS_ADDAFORK_LOG_COUNT
value|2
end_define

begin_define
define|#
directive|define
name|XFS_ATTRINVAL_LOG_COUNT
value|1
end_define

begin_define
define|#
directive|define
name|XFS_ATTRSET_LOG_COUNT
value|3
end_define

begin_define
define|#
directive|define
name|XFS_ATTRRM_LOG_COUNT
value|3
end_define

begin_comment
comment|/*  * Here we centralize the specification of XFS meta-data buffer  * reference count values.  This determine how hard the buffer  * cache tries to hold onto the buffer.  */
end_comment

begin_define
define|#
directive|define
name|XFS_AGF_REF
value|4
end_define

begin_define
define|#
directive|define
name|XFS_AGI_REF
value|4
end_define

begin_define
define|#
directive|define
name|XFS_AGFL_REF
value|3
end_define

begin_define
define|#
directive|define
name|XFS_INO_BTREE_REF
value|3
end_define

begin_define
define|#
directive|define
name|XFS_ALLOC_BTREE_REF
value|2
end_define

begin_define
define|#
directive|define
name|XFS_BMAP_BTREE_REF
value|2
end_define

begin_define
define|#
directive|define
name|XFS_DIR_BTREE_REF
value|2
end_define

begin_define
define|#
directive|define
name|XFS_ATTR_BTREE_REF
value|1
end_define

begin_define
define|#
directive|define
name|XFS_INO_REF
value|1
end_define

begin_define
define|#
directive|define
name|XFS_DQUOT_REF
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_comment
comment|/*  * XFS transaction mechanism exported interfaces that are  * actually macros.  */
end_comment

begin_define
define|#
directive|define
name|xfs_trans_get_log_res
parameter_list|(
name|tp
parameter_list|)
value|((tp)->t_log_res)
end_define

begin_define
define|#
directive|define
name|xfs_trans_get_log_count
parameter_list|(
name|tp
parameter_list|)
value|((tp)->t_log_count)
end_define

begin_define
define|#
directive|define
name|xfs_trans_get_block_res
parameter_list|(
name|tp
parameter_list|)
value|((tp)->t_blk_res)
end_define

begin_define
define|#
directive|define
name|xfs_trans_set_sync
parameter_list|(
name|tp
parameter_list|)
value|((tp)->t_flags |= XFS_TRANS_SYNC)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|xfs_trans_agblocks_delta
parameter_list|(
name|tp
parameter_list|,
name|d
parameter_list|)
value|((tp)->t_ag_freeblks_delta += (long)d)
end_define

begin_define
define|#
directive|define
name|xfs_trans_agflist_delta
parameter_list|(
name|tp
parameter_list|,
name|d
parameter_list|)
value|((tp)->t_ag_flist_delta += (long)d)
end_define

begin_define
define|#
directive|define
name|xfs_trans_agbtree_delta
parameter_list|(
name|tp
parameter_list|,
name|d
parameter_list|)
value|((tp)->t_ag_btree_delta += (long)d)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|xfs_trans_agblocks_delta
parameter_list|(
name|tp
parameter_list|,
name|d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xfs_trans_agflist_delta
parameter_list|(
name|tp
parameter_list|,
name|d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xfs_trans_agbtree_delta
parameter_list|(
name|tp
parameter_list|,
name|d
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XFS transaction mechanism exported interfaces.  */
end_comment

begin_function_decl
name|void
name|xfs_trans_init
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_trans_t
modifier|*
name|xfs_trans_alloc
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_trans_t
modifier|*
name|_xfs_trans_alloc
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_trans_t
modifier|*
name|xfs_trans_dup
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_trans_reserve
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|uint
parameter_list|,
name|uint
parameter_list|,
name|uint
parameter_list|,
name|uint
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_mod_sb
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|uint
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|xfs_buf
modifier|*
name|xfs_trans_get_buf
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|struct
name|xfs_buftarg
modifier|*
parameter_list|,
name|xfs_daddr_t
parameter_list|,
name|int
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_trans_read_buf
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|xfs_trans_t
modifier|*
parameter_list|,
name|struct
name|xfs_buftarg
modifier|*
parameter_list|,
name|xfs_daddr_t
parameter_list|,
name|int
parameter_list|,
name|uint
parameter_list|,
name|struct
name|xfs_buf
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|xfs_buf
modifier|*
name|xfs_trans_getsb
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_brelse
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|struct
name|xfs_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_bjoin
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|struct
name|xfs_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_bhold
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|struct
name|xfs_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_bhold_release
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|struct
name|xfs_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_binval
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|struct
name|xfs_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_inode_buf
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|struct
name|xfs_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_stale_inode_buf
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|struct
name|xfs_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_dquot_buf
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|struct
name|xfs_buf
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_inode_alloc_buf
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|struct
name|xfs_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_trans_iget
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|xfs_trans_t
modifier|*
parameter_list|,
name|xfs_ino_t
parameter_list|,
name|uint
parameter_list|,
name|uint
parameter_list|,
name|struct
name|xfs_inode
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_ijoin
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|struct
name|xfs_inode
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_ihold
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|struct
name|xfs_inode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_log_buf
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|struct
name|xfs_buf
modifier|*
parameter_list|,
name|uint
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_log_inode
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|struct
name|xfs_inode
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|xfs_efi_log_item
modifier|*
name|xfs_trans_get_efi
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_efi_release
parameter_list|(
name|struct
name|xfs_efi_log_item
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_log_efi_extent
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|struct
name|xfs_efi_log_item
modifier|*
parameter_list|,
name|xfs_fsblock_t
parameter_list|,
name|xfs_extlen_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|xfs_efd_log_item
modifier|*
name|xfs_trans_get_efd
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|struct
name|xfs_efi_log_item
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_log_efd_extent
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|struct
name|xfs_efd_log_item
modifier|*
parameter_list|,
name|xfs_fsblock_t
parameter_list|,
name|xfs_extlen_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_xfs_trans_commit
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|uint
name|flags
parameter_list|,
name|xfs_lsn_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|xfs_trans_commit
parameter_list|(
name|tp
parameter_list|,
name|flags
parameter_list|,
name|lsn
parameter_list|)
define|\
value|_xfs_trans_commit(tp, flags, lsn, NULL)
end_define

begin_function_decl
name|void
name|xfs_trans_cancel
parameter_list|(
name|xfs_trans_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_ail_init
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_lsn_t
name|xfs_trans_push_ail
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|xfs_lsn_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_lsn_t
name|xfs_trans_tail_ail
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_trans_unlocked_item
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|xfs_log_item_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_log_busy_slot_t
modifier|*
name|xfs_trans_add_busy
parameter_list|(
name|xfs_trans_t
modifier|*
name|tp
parameter_list|,
name|xfs_agnumber_t
name|ag
parameter_list|,
name|xfs_extlen_t
name|idx
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
comment|/* __XFS_TRANS_H__ */
end_comment

end_unit

