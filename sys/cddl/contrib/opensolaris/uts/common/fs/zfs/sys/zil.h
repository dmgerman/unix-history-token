begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ZIL_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ZIL_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/spa.h>
end_include

begin_include
include|#
directive|include
file|<sys/zio.h>
end_include

begin_include
include|#
directive|include
file|<sys/dmu.h>
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
comment|/*  * Intent log format:  *  * Each objset has its own intent log.  The log header (zil_header_t)  * for objset N's intent log is kept in the Nth object of the SPA's  * intent_log objset.  The log header points to a chain of log blocks,  * each of which contains log records (i.e., transactions) followed by  * a log block trailer (zil_trailer_t).  The format of a log record  * depends on the record (or transaction) type, but all records begin  * with a common structure that defines the type, length, and txg.  */
comment|/*  * Intent log header - this on disk structure holds fields to manage  * the log.  All fields are 64 bit to easily handle cross architectures.  */
typedef|typedef
struct|struct
name|zil_header
block|{
name|uint64_t
name|zh_claim_txg
decl_stmt|;
comment|/* txg in which log blocks were claimed */
name|uint64_t
name|zh_replay_seq
decl_stmt|;
comment|/* highest replayed sequence number */
name|blkptr_t
name|zh_log
decl_stmt|;
comment|/* log chain */
name|uint64_t
name|zh_claim_seq
decl_stmt|;
comment|/* highest claimed sequence number */
name|uint64_t
name|zh_pad
index|[
literal|5
index|]
decl_stmt|;
block|}
name|zil_header_t
typedef|;
comment|/*  * Log block trailer - structure at the end of the header and each log block  *  * The zit_bt contains a zbt_cksum which for the intent log is  * the sequence number of this log block. A seq of 0 is invalid.  * The zbt_cksum is checked by the SPA against the sequence  * number passed in the blk_cksum field of the blkptr_t  */
typedef|typedef
struct|struct
name|zil_trailer
block|{
name|uint64_t
name|zit_pad
decl_stmt|;
name|blkptr_t
name|zit_next_blk
decl_stmt|;
comment|/* next block in chain */
name|uint64_t
name|zit_nused
decl_stmt|;
comment|/* bytes in log block used */
name|zio_block_tail_t
name|zit_bt
decl_stmt|;
comment|/* block trailer */
block|}
name|zil_trailer_t
typedef|;
define|#
directive|define
name|ZIL_MIN_BLKSZ
value|4096ULL
define|#
directive|define
name|ZIL_MAX_BLKSZ
value|SPA_MAXBLOCKSIZE
define|#
directive|define
name|ZIL_BLK_DATA_SZ
parameter_list|(
name|lwb
parameter_list|)
value|((lwb)->lwb_sz - sizeof (zil_trailer_t))
comment|/*  * The words of a log block checksum.  */
define|#
directive|define
name|ZIL_ZC_GUID_0
value|0
define|#
directive|define
name|ZIL_ZC_GUID_1
value|1
define|#
directive|define
name|ZIL_ZC_OBJSET
value|2
define|#
directive|define
name|ZIL_ZC_SEQ
value|3
comment|/*  * Intent log transaction types and record structures  */
define|#
directive|define
name|TX_CREATE
value|1
comment|/* Create file */
define|#
directive|define
name|TX_MKDIR
value|2
comment|/* Make directory */
define|#
directive|define
name|TX_MKXATTR
value|3
comment|/* Make XATTR directory */
define|#
directive|define
name|TX_SYMLINK
value|4
comment|/* Create symbolic link to a file */
define|#
directive|define
name|TX_REMOVE
value|5
comment|/* Remove file */
define|#
directive|define
name|TX_RMDIR
value|6
comment|/* Remove directory */
define|#
directive|define
name|TX_LINK
value|7
comment|/* Create hard link to a file */
define|#
directive|define
name|TX_RENAME
value|8
comment|/* Rename a file */
define|#
directive|define
name|TX_WRITE
value|9
comment|/* File write */
define|#
directive|define
name|TX_TRUNCATE
value|10
comment|/* Truncate a file */
define|#
directive|define
name|TX_SETATTR
value|11
comment|/* Set file attributes */
define|#
directive|define
name|TX_ACL
value|12
comment|/* Set acl */
define|#
directive|define
name|TX_MAX_TYPE
value|13
comment|/* Max transaction type */
comment|/*  * Format of log records.  * The fields are carefully defined to allow them to be aligned  * and sized the same on sparc& intel architectures.  * Each log record has a common structure at the beginning.  *  * Note, lrc_seq holds two different sequence numbers. Whilst in memory  * it contains the transaction sequence number.  The log record on  * disk holds the sequence number of all log records which is used to  * ensure we don't replay the same record.  The two sequence numbers are  * different because the transactions can now be pushed out of order.  */
typedef|typedef
struct|struct
block|{
comment|/* common log record header */
name|uint64_t
name|lrc_txtype
decl_stmt|;
comment|/* intent log transaction type */
name|uint64_t
name|lrc_reclen
decl_stmt|;
comment|/* transaction record length */
name|uint64_t
name|lrc_txg
decl_stmt|;
comment|/* dmu transaction group number */
name|uint64_t
name|lrc_seq
decl_stmt|;
comment|/* see comment above */
block|}
name|lr_t
typedef|;
typedef|typedef
struct|struct
block|{
name|lr_t
name|lr_common
decl_stmt|;
comment|/* common portion of log record */
name|uint64_t
name|lr_doid
decl_stmt|;
comment|/* object id of directory */
name|uint64_t
name|lr_foid
decl_stmt|;
comment|/* object id of created file object */
name|uint64_t
name|lr_mode
decl_stmt|;
comment|/* mode of object */
name|uint64_t
name|lr_uid
decl_stmt|;
comment|/* uid of object */
name|uint64_t
name|lr_gid
decl_stmt|;
comment|/* gid of object */
name|uint64_t
name|lr_gen
decl_stmt|;
comment|/* generation (txg of creation) */
name|uint64_t
name|lr_crtime
index|[
literal|2
index|]
decl_stmt|;
comment|/* creation time */
name|uint64_t
name|lr_rdev
decl_stmt|;
comment|/* rdev of object to create */
comment|/* name of object to create follows this */
comment|/* for symlinks, link content follows name */
block|}
name|lr_create_t
typedef|;
typedef|typedef
struct|struct
block|{
name|lr_t
name|lr_common
decl_stmt|;
comment|/* common portion of log record */
name|uint64_t
name|lr_doid
decl_stmt|;
comment|/* obj id of directory */
comment|/* name of object to remove follows this */
block|}
name|lr_remove_t
typedef|;
typedef|typedef
struct|struct
block|{
name|lr_t
name|lr_common
decl_stmt|;
comment|/* common portion of log record */
name|uint64_t
name|lr_doid
decl_stmt|;
comment|/* obj id of directory */
name|uint64_t
name|lr_link_obj
decl_stmt|;
comment|/* obj id of link */
comment|/* name of object to link follows this */
block|}
name|lr_link_t
typedef|;
typedef|typedef
struct|struct
block|{
name|lr_t
name|lr_common
decl_stmt|;
comment|/* common portion of log record */
name|uint64_t
name|lr_sdoid
decl_stmt|;
comment|/* obj id of source directory */
name|uint64_t
name|lr_tdoid
decl_stmt|;
comment|/* obj id of target directory */
comment|/* 2 strings: names of source and destination follow this */
block|}
name|lr_rename_t
typedef|;
typedef|typedef
struct|struct
block|{
name|lr_t
name|lr_common
decl_stmt|;
comment|/* common portion of log record */
name|uint64_t
name|lr_foid
decl_stmt|;
comment|/* file object to write */
name|uint64_t
name|lr_offset
decl_stmt|;
comment|/* offset to write to */
name|uint64_t
name|lr_length
decl_stmt|;
comment|/* user data length to write */
name|uint64_t
name|lr_blkoff
decl_stmt|;
comment|/* offset represented by lr_blkptr */
name|blkptr_t
name|lr_blkptr
decl_stmt|;
comment|/* spa block pointer for replay */
comment|/* write data will follow for small writes */
block|}
name|lr_write_t
typedef|;
typedef|typedef
struct|struct
block|{
name|lr_t
name|lr_common
decl_stmt|;
comment|/* common portion of log record */
name|uint64_t
name|lr_foid
decl_stmt|;
comment|/* object id of file to truncate */
name|uint64_t
name|lr_offset
decl_stmt|;
comment|/* offset to truncate from */
name|uint64_t
name|lr_length
decl_stmt|;
comment|/* length to truncate */
block|}
name|lr_truncate_t
typedef|;
typedef|typedef
struct|struct
block|{
name|lr_t
name|lr_common
decl_stmt|;
comment|/* common portion of log record */
name|uint64_t
name|lr_foid
decl_stmt|;
comment|/* file object to change attributes */
name|uint64_t
name|lr_mask
decl_stmt|;
comment|/* mask of attributes to set */
name|uint64_t
name|lr_mode
decl_stmt|;
comment|/* mode to set */
name|uint64_t
name|lr_uid
decl_stmt|;
comment|/* uid to set */
name|uint64_t
name|lr_gid
decl_stmt|;
comment|/* gid to set */
name|uint64_t
name|lr_size
decl_stmt|;
comment|/* size to set */
name|uint64_t
name|lr_atime
index|[
literal|2
index|]
decl_stmt|;
comment|/* access time */
name|uint64_t
name|lr_mtime
index|[
literal|2
index|]
decl_stmt|;
comment|/* modification time */
block|}
name|lr_setattr_t
typedef|;
typedef|typedef
struct|struct
block|{
name|lr_t
name|lr_common
decl_stmt|;
comment|/* common portion of log record */
name|uint64_t
name|lr_foid
decl_stmt|;
comment|/* obj id of file */
name|uint64_t
name|lr_aclcnt
decl_stmt|;
comment|/* number of acl entries */
comment|/* lr_aclcnt number of ace_t entries follow this */
block|}
name|lr_acl_t
typedef|;
comment|/*  * ZIL structure definitions, interface function prototype and globals.  */
comment|/*  * ZFS intent log transaction structure  */
typedef|typedef
enum|enum
block|{
name|WR_INDIRECT
block|,
comment|/* indirect - a large write (dmu_sync() data */
comment|/* and put blkptr in log, rather than actual data) */
name|WR_COPIED
block|,
comment|/* immediate - data is copied into lr_write_t */
name|WR_NEED_COPY
block|,
comment|/* immediate - data needs to be copied if pushed */
block|}
name|itx_wr_state_t
typedef|;
typedef|typedef
struct|struct
name|itx
block|{
name|list_node_t
name|itx_node
decl_stmt|;
comment|/* linkage on zl_itx_list */
name|void
modifier|*
name|itx_private
decl_stmt|;
comment|/* type-specific opaque data */
name|itx_wr_state_t
name|itx_wr_state
decl_stmt|;
comment|/* write state */
name|uint8_t
name|itx_sync
decl_stmt|;
comment|/* synchronous transaction */
name|lr_t
name|itx_lr
decl_stmt|;
comment|/* common part of log record */
comment|/* followed by type-specific part of lr_xx_t and its immediate data */
block|}
name|itx_t
typedef|;
comment|/*  * zgd_t is passed through dmu_sync() to the callback routine zfs_get_done()  * to handle the cleanup of the dmu_sync() buffer write  */
typedef|typedef
struct|struct
block|{
name|zilog_t
modifier|*
name|zgd_zilog
decl_stmt|;
comment|/* zilog */
name|blkptr_t
modifier|*
name|zgd_bp
decl_stmt|;
comment|/* block pointer */
name|struct
name|rl
modifier|*
name|zgd_rl
decl_stmt|;
comment|/* range lock */
block|}
name|zgd_t
typedef|;
typedef|typedef
name|void
name|zil_parse_blk_func_t
parameter_list|(
name|zilog_t
modifier|*
name|zilog
parameter_list|,
name|blkptr_t
modifier|*
name|bp
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|uint64_t
name|txg
parameter_list|)
function_decl|;
typedef|typedef
name|void
name|zil_parse_lr_func_t
parameter_list|(
name|zilog_t
modifier|*
name|zilog
parameter_list|,
name|lr_t
modifier|*
name|lr
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|uint64_t
name|txg
parameter_list|)
function_decl|;
typedef|typedef
name|int
name|zil_replay_func_t
parameter_list|()
function_decl|;
typedef|typedef
name|int
name|zil_get_data_t
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|lr_write_t
modifier|*
name|lr
parameter_list|,
name|char
modifier|*
name|dbuf
parameter_list|,
name|zio_t
modifier|*
name|zio
parameter_list|)
function_decl|;
specifier|extern
name|uint64_t
name|zil_parse
parameter_list|(
name|zilog_t
modifier|*
name|zilog
parameter_list|,
name|zil_parse_blk_func_t
modifier|*
name|parse_blk_func
parameter_list|,
name|zil_parse_lr_func_t
modifier|*
name|parse_lr_func
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|uint64_t
name|txg
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zil_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zil_fini
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|zilog_t
modifier|*
name|zil_alloc
parameter_list|(
name|objset_t
modifier|*
name|os
parameter_list|,
name|zil_header_t
modifier|*
name|zh_phys
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zil_free
parameter_list|(
name|zilog_t
modifier|*
name|zilog
parameter_list|)
function_decl|;
specifier|extern
name|zilog_t
modifier|*
name|zil_open
parameter_list|(
name|objset_t
modifier|*
name|os
parameter_list|,
name|zil_get_data_t
modifier|*
name|get_data
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zil_close
parameter_list|(
name|zilog_t
modifier|*
name|zilog
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zil_replay
parameter_list|(
name|objset_t
modifier|*
name|os
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|uint64_t
modifier|*
name|txgp
parameter_list|,
name|zil_replay_func_t
modifier|*
name|replay_func
index|[
name|TX_MAX_TYPE
index|]
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zil_destroy
parameter_list|(
name|zilog_t
modifier|*
name|zilog
parameter_list|,
name|boolean_t
name|keep_first
parameter_list|)
function_decl|;
specifier|extern
name|itx_t
modifier|*
name|zil_itx_create
parameter_list|(
name|int
name|txtype
parameter_list|,
name|size_t
name|lrsize
parameter_list|)
function_decl|;
specifier|extern
name|uint64_t
name|zil_itx_assign
parameter_list|(
name|zilog_t
modifier|*
name|zilog
parameter_list|,
name|itx_t
modifier|*
name|itx
parameter_list|,
name|dmu_tx_t
modifier|*
name|tx
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zil_commit
parameter_list|(
name|zilog_t
modifier|*
name|zilog
parameter_list|,
name|uint64_t
name|seq
parameter_list|,
name|uint64_t
name|oid
parameter_list|)
function_decl|;
specifier|extern
name|int
name|zil_claim
parameter_list|(
name|char
modifier|*
name|osname
parameter_list|,
name|void
modifier|*
name|txarg
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zil_sync
parameter_list|(
name|zilog_t
modifier|*
name|zilog
parameter_list|,
name|dmu_tx_t
modifier|*
name|tx
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zil_clean
parameter_list|(
name|zilog_t
modifier|*
name|zilog
parameter_list|)
function_decl|;
specifier|extern
name|int
name|zil_is_committed
parameter_list|(
name|zilog_t
modifier|*
name|zilog
parameter_list|)
function_decl|;
specifier|extern
name|int
name|zil_suspend
parameter_list|(
name|zilog_t
modifier|*
name|zilog
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zil_resume
parameter_list|(
name|zilog_t
modifier|*
name|zilog
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zil_add_vdev
parameter_list|(
name|zilog_t
modifier|*
name|zilog
parameter_list|,
name|uint64_t
name|vdev
parameter_list|)
function_decl|;
specifier|extern
name|int
name|zil_disable
decl_stmt|;
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
comment|/* _SYS_ZIL_H */
end_comment

end_unit

