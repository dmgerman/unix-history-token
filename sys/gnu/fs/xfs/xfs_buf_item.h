begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_BUF_ITEM_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_BUF_ITEM_H__
end_define

begin_comment
comment|/*  * This is the structure used to lay out a buf log item in the  * log.  The data map describes which 128 byte chunks of the buffer  * have been logged.  This structure works only on buffers that  * reside up to the first TB in the filesystem.  These buffers are  * generated only by pre-6.2 systems and are known as XFS_LI_6_1_BUF.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_buf_log_format_v1
block|{
name|unsigned
name|short
name|blf_type
decl_stmt|;
comment|/* buf log item type indicator */
name|unsigned
name|short
name|blf_size
decl_stmt|;
comment|/* size of this item */
name|__int32_t
name|blf_blkno
decl_stmt|;
comment|/* starting blkno of this buf */
name|ushort
name|blf_flags
decl_stmt|;
comment|/* misc state */
name|ushort
name|blf_len
decl_stmt|;
comment|/* number of blocks in this buf */
name|unsigned
name|int
name|blf_map_size
decl_stmt|;
comment|/* size of data bitmap in words */
name|unsigned
name|int
name|blf_data_map
index|[
literal|1
index|]
decl_stmt|;
comment|/* variable size bitmap of */
comment|/*   regions of buffer in this item */
block|}
name|xfs_buf_log_format_v1_t
typedef|;
end_typedef

begin_comment
comment|/*  * This is a form of the above structure with a 64 bit blkno field.  * For 6.2 and beyond, this is XFS_LI_BUF.  We use this to log everything.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_buf_log_format_t
block|{
name|unsigned
name|short
name|blf_type
decl_stmt|;
comment|/* buf log item type indicator */
name|unsigned
name|short
name|blf_size
decl_stmt|;
comment|/* size of this item */
name|ushort
name|blf_flags
decl_stmt|;
comment|/* misc state */
name|ushort
name|blf_len
decl_stmt|;
comment|/* number of blocks in this buf */
name|__int64_t
name|blf_blkno
decl_stmt|;
comment|/* starting blkno of this buf */
name|unsigned
name|int
name|blf_map_size
decl_stmt|;
comment|/* size of data bitmap in words */
name|unsigned
name|int
name|blf_data_map
index|[
literal|1
index|]
decl_stmt|;
comment|/* variable size bitmap of */
comment|/*   regions of buffer in this item */
block|}
name|xfs_buf_log_format_t
typedef|;
end_typedef

begin_comment
comment|/*  * This flag indicates that the buffer contains on disk inodes  * and requires special recovery handling.  */
end_comment

begin_define
define|#
directive|define
name|XFS_BLI_INODE_BUF
value|0x1
end_define

begin_comment
comment|/*  * This flag indicates that the buffer should not be replayed  * during recovery because its blocks are being freed.  */
end_comment

begin_define
define|#
directive|define
name|XFS_BLI_CANCEL
value|0x2
end_define

begin_comment
comment|/*  * This flag indicates that the buffer contains on disk  * user or group dquots and may require special recovery handling.  */
end_comment

begin_define
define|#
directive|define
name|XFS_BLI_UDQUOT_BUF
value|0x4
end_define

begin_define
define|#
directive|define
name|XFS_BLI_PDQUOT_BUF
value|0x8
end_define

begin_define
define|#
directive|define
name|XFS_BLI_GDQUOT_BUF
value|0x10
end_define

begin_define
define|#
directive|define
name|XFS_BLI_CHUNK
value|128
end_define

begin_define
define|#
directive|define
name|XFS_BLI_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|BIT_TO_WORD_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|NBWORD
value|(NBBY * sizeof(unsigned int))
end_define

begin_comment
comment|/*  * buf log item flags  */
end_comment

begin_define
define|#
directive|define
name|XFS_BLI_HOLD
value|0x01
end_define

begin_define
define|#
directive|define
name|XFS_BLI_DIRTY
value|0x02
end_define

begin_define
define|#
directive|define
name|XFS_BLI_STALE
value|0x04
end_define

begin_define
define|#
directive|define
name|XFS_BLI_LOGGED
value|0x08
end_define

begin_define
define|#
directive|define
name|XFS_BLI_INODE_ALLOC_BUF
value|0x10
end_define

begin_define
define|#
directive|define
name|XFS_BLI_STALE_INODE
value|0x20
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
name|ktrace
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_mount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_buf_log_item
struct_decl|;
end_struct_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XFS_BLI_TRACE
argument_list|)
end_if

begin_define
define|#
directive|define
name|XFS_BLI_TRACE_SIZE
value|32
end_define

begin_function_decl
name|void
name|xfs_buf_item_trace
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|xfs_buf_log_item
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
name|xfs_buf_item_trace
parameter_list|(
name|id
parameter_list|,
name|bip
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This is the in core log item structure used to track information  * needed to log buffers.  It tracks how many times the lock has been  * locked, and which 128 byte chunks of the buffer are dirty.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_buf_log_item
block|{
name|xfs_log_item_t
name|bli_item
decl_stmt|;
comment|/* common item structure */
name|struct
name|xfs_buf
modifier|*
name|bli_buf
decl_stmt|;
comment|/* real buffer pointer */
name|unsigned
name|int
name|bli_flags
decl_stmt|;
comment|/* misc flags */
name|unsigned
name|int
name|bli_recur
decl_stmt|;
comment|/* lock recursion count */
name|atomic_t
name|bli_refcount
decl_stmt|;
comment|/* cnt of tp refs */
ifdef|#
directive|ifdef
name|XFS_BLI_TRACE
name|struct
name|ktrace
modifier|*
name|bli_trace
decl_stmt|;
comment|/* event trace buf */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|XFS_TRANS_DEBUG
name|char
modifier|*
name|bli_orig
decl_stmt|;
comment|/* original buffer copy */
name|char
modifier|*
name|bli_logged
decl_stmt|;
comment|/* bytes logged (bitmap) */
endif|#
directive|endif
name|xfs_buf_log_format_t
name|bli_format
decl_stmt|;
comment|/* in-log header */
block|}
name|xfs_buf_log_item_t
typedef|;
end_typedef

begin_comment
comment|/*  * This structure is used during recovery to record the buf log  * items which have been canceled and should not be replayed.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_buf_cancel
block|{
name|xfs_daddr_t
name|bc_blkno
decl_stmt|;
name|uint
name|bc_len
decl_stmt|;
name|int
name|bc_refcount
decl_stmt|;
name|struct
name|xfs_buf_cancel
modifier|*
name|bc_next
decl_stmt|;
block|}
name|xfs_buf_cancel_t
typedef|;
end_typedef

begin_function_decl
name|void
name|xfs_buf_item_init
parameter_list|(
name|struct
name|xfs_buf
modifier|*
parameter_list|,
name|struct
name|xfs_mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_buf_item_relse
parameter_list|(
name|struct
name|xfs_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_buf_item_log
parameter_list|(
name|xfs_buf_log_item_t
modifier|*
parameter_list|,
name|uint
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint
name|xfs_buf_item_dirty
parameter_list|(
name|xfs_buf_log_item_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_buf_attach_iodone
parameter_list|(
name|struct
name|xfs_buf
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|xfs_buf
modifier|*
parameter_list|,
name|xfs_log_item_t
modifier|*
parameter_list|)
parameter_list|,
name|xfs_log_item_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_buf_iodone_callbacks
parameter_list|(
name|struct
name|xfs_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_buf_iodone
parameter_list|(
name|struct
name|xfs_buf
modifier|*
parameter_list|,
name|xfs_buf_log_item_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|XFS_TRANS_DEBUG
end_ifdef

begin_function_decl
name|void
name|xfs_buf_item_flush_log_debug
parameter_list|(
name|struct
name|xfs_buf
modifier|*
name|bp
parameter_list|,
name|uint
name|first
parameter_list|,
name|uint
name|last
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
name|xfs_buf_item_flush_log_debug
parameter_list|(
name|bp
parameter_list|,
name|first
parameter_list|,
name|last
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
comment|/* __KERNEL__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_BUF_ITEM_H__ */
end_comment

end_unit

