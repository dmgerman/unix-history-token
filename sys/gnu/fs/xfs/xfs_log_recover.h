begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_LOG_RECOVER_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_LOG_RECOVER_H__
end_define

begin_comment
comment|/*  * Macros, structures, prototypes for internal log manager use.  */
end_comment

begin_define
define|#
directive|define
name|XLOG_RHASH_BITS
value|4
end_define

begin_define
define|#
directive|define
name|XLOG_RHASH_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|XLOG_RHASH_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|XLOG_RHASH
parameter_list|(
name|tid
parameter_list|)
define|\
value|((((__uint32_t)tid)>>XLOG_RHASH_SHIFT)& (XLOG_RHASH_SIZE-1))
end_define

begin_define
define|#
directive|define
name|XLOG_MAX_REGIONS_IN_ITEM
value|(XFS_MAX_BLOCKSIZE / XFS_BLI_CHUNK / 2 + 1)
end_define

begin_comment
comment|/*  * item headers are in ri_buf[0].  Additional buffers follow.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xlog_recover_item
block|{
name|struct
name|xlog_recover_item
modifier|*
name|ri_next
decl_stmt|;
name|struct
name|xlog_recover_item
modifier|*
name|ri_prev
decl_stmt|;
name|int
name|ri_type
decl_stmt|;
name|int
name|ri_cnt
decl_stmt|;
comment|/* count of regions found */
name|int
name|ri_total
decl_stmt|;
comment|/* total regions */
name|xfs_log_iovec_t
modifier|*
name|ri_buf
decl_stmt|;
comment|/* ptr to regions buffer */
block|}
name|xlog_recover_item_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|xlog_tid
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|xlog_recover
block|{
name|struct
name|xlog_recover
modifier|*
name|r_next
decl_stmt|;
name|xlog_tid_t
name|r_log_tid
decl_stmt|;
comment|/* log's transaction id */
name|xfs_trans_header_t
name|r_theader
decl_stmt|;
comment|/* trans header for partial */
name|int
name|r_state
decl_stmt|;
comment|/* not needed */
name|xfs_lsn_t
name|r_lsn
decl_stmt|;
comment|/* xact lsn */
name|xlog_recover_item_t
modifier|*
name|r_itemq
decl_stmt|;
comment|/* q for items */
block|}
name|xlog_recover_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ITEM_TYPE
parameter_list|(
name|i
parameter_list|)
value|(*(ushort *)(i)->ri_buf[0].i_addr)
end_define

begin_comment
comment|/*  * This is the number of entries in the l_buf_cancel_table used during  * recovery.  */
end_comment

begin_define
define|#
directive|define
name|XLOG_BC_TABLE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|XLOG_RECOVER_PASS1
value|1
end_define

begin_define
define|#
directive|define
name|XLOG_RECOVER_PASS2
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_LOG_RECOVER_H__ */
end_comment

end_unit

