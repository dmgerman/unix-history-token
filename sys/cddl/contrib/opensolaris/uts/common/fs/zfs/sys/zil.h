begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2005, 2010, Oracle and/or its affiliates. All rights reserved.  * Copyright (c) 2012, 2017 by Delphix. All rights reserved.  * Copyright (c) 2014 Integros [integros.com]  */
end_comment

begin_comment
comment|/* Portions Copyright 2010 Robert Milkowski */
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
struct_decl|struct
name|dsl_pool
struct_decl|;
struct_decl|struct
name|dsl_dataset
struct_decl|;
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
name|zh_claim_blk_seq
decl_stmt|;
comment|/* highest claimed block sequence number */
name|uint64_t
name|zh_flags
decl_stmt|;
comment|/* header flags */
name|uint64_t
name|zh_claim_lr_seq
decl_stmt|;
comment|/* highest claimed lr sequence number */
name|uint64_t
name|zh_pad
index|[
literal|3
index|]
decl_stmt|;
block|}
name|zil_header_t
typedef|;
comment|/*  * zh_flags bit settings  */
define|#
directive|define
name|ZIL_REPLAY_NEEDED
value|0x1
comment|/* replay needed - internal only */
define|#
directive|define
name|ZIL_CLAIM_LR_SEQ_VALID
value|0x2
comment|/* zh_claim_lr_seq field is valid */
comment|/*  * Log block chaining.  *  * Log blocks are chained together. Originally they were chained at the  * end of the block. For performance reasons the chain was moved to the  * beginning of the block which allows writes for only the data being used.  * The older position is supported for backwards compatability.  *  * The zio_eck_t contains a zec_cksum which for the intent log is  * the sequence number of this log block. A seq of 0 is invalid.  * The zec_cksum is checked by the SPA against the sequence  * number passed in the blk_cksum field of the blkptr_t  */
typedef|typedef
struct|struct
name|zil_chain
block|{
name|uint64_t
name|zc_pad
decl_stmt|;
name|blkptr_t
name|zc_next_blk
decl_stmt|;
comment|/* next block in chain */
name|uint64_t
name|zc_nused
decl_stmt|;
comment|/* bytes in log block used */
name|zio_eck_t
name|zc_eck
decl_stmt|;
comment|/* block trailer */
block|}
name|zil_chain_t
typedef|;
define|#
directive|define
name|ZIL_MIN_BLKSZ
value|4096ULL
comment|/*  * ziltest is by and large an ugly hack, but very useful in  * checking replay without tedious work.  * When running ziltest we want to keep all itx's and so maintain  * a single list in the zl_itxg[] that uses a high txg: ZILTEST_TXG  * We subtract TXG_CONCURRENT_STATES to allow for common code.  */
define|#
directive|define
name|ZILTEST_TXG
value|(UINT64_MAX - TXG_CONCURRENT_STATES)
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
typedef|typedef
enum|enum
name|zil_create
block|{
name|Z_FILE
block|,
name|Z_DIR
block|,
name|Z_XATTRDIR
block|, }
name|zil_create_t
typedef|;
comment|/*  * size of xvattr log section.  * its composed of lr_attr_t + xvattr bitmap + 2 64 bit timestamps  * for create time and a single 64 bit integer for all of the attributes,  * and 4 64 bit integers (32 bytes) for the scanstamp.  *  */
define|#
directive|define
name|ZIL_XVAT_SIZE
parameter_list|(
name|mapsize
parameter_list|)
define|\
value|sizeof (lr_attr_t) + (sizeof (uint32_t) * (mapsize - 1)) + \ 	(sizeof (uint64_t) * 7)
comment|/*  * Size of ACL in log.  The ACE data is padded out to properly align  * on 8 byte boundary.  */
define|#
directive|define
name|ZIL_ACE_LENGTH
parameter_list|(
name|x
parameter_list|)
value|(roundup(x, sizeof (uint64_t)))
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
name|TX_ACL_V0
value|12
comment|/* Set old formatted ACL */
define|#
directive|define
name|TX_ACL
value|13
comment|/* Set ACL */
define|#
directive|define
name|TX_CREATE_ACL
value|14
comment|/* create with ACL */
define|#
directive|define
name|TX_CREATE_ATTR
value|15
comment|/* create + attrs */
define|#
directive|define
name|TX_CREATE_ACL_ATTR
value|16
comment|/* create with ACL + attrs */
define|#
directive|define
name|TX_MKDIR_ACL
value|17
comment|/* mkdir with ACL */
define|#
directive|define
name|TX_MKDIR_ATTR
value|18
comment|/* mkdir with attr */
define|#
directive|define
name|TX_MKDIR_ACL_ATTR
value|19
comment|/* mkdir with ACL + attrs */
define|#
directive|define
name|TX_WRITE2
value|20
comment|/* dmu_sync EALREADY write */
define|#
directive|define
name|TX_MAX_TYPE
value|21
comment|/* Max transaction type */
comment|/*  * The transactions for mkdir, symlink, remove, rmdir, link, and rename  * may have the following bit set, indicating the original request  * specified case-insensitive handling of names.  */
define|#
directive|define
name|TX_CI
value|((uint64_t)0x1<< 63)
comment|/* case-insensitive behavior requested */
comment|/*  * Transactions for write, truncate, setattr, acl_v0, and acl can be logged  * out of order.  For convenience in the code, all such records must have  * lr_foid at the same offset.  */
define|#
directive|define
name|TX_OOO
parameter_list|(
name|txtype
parameter_list|)
define|\
value|((txtype) == TX_WRITE ||	\ 	(txtype) == TX_TRUNCATE ||	\ 	(txtype) == TX_SETATTR ||	\ 	(txtype) == TX_ACL_V0 ||	\ 	(txtype) == TX_ACL ||		\ 	(txtype) == TX_WRITE2)
comment|/*  * Format of log records.  * The fields are carefully defined to allow them to be aligned  * and sized the same on sparc& intel architectures.  * Each log record has a common structure at the beginning.  *  * The log record on disk (lrc_seq) holds the sequence number of all log  * records which is used to ensure we don't replay the same record.  */
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
comment|/*  * Common start of all out-of-order record types (TX_OOO() above).  */
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
comment|/* object id */
block|}
name|lr_ooo_t
typedef|;
comment|/*  * Handle option extended vattr attributes.  *  * Whenever new attributes are added the version number  * will need to be updated as will code in  * zfs_log.c and zfs_replay.c  */
typedef|typedef
struct|struct
block|{
name|uint32_t
name|lr_attr_masksize
decl_stmt|;
comment|/* number of elements in array */
name|uint32_t
name|lr_attr_bitmap
decl_stmt|;
comment|/* First entry of array */
comment|/* remainder of array and any additional fields */
block|}
name|lr_attr_t
typedef|;
comment|/*  * log record for creates without optional ACL.  * This log record does support optional xvattr_t attributes.  */
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
comment|/* for creates with xvattr data, the name follows the xvattr info */
block|}
name|lr_create_t
typedef|;
comment|/*  * FUID ACL record will be an array of ACEs from the original ACL.  * If this array includes ephemeral IDs, the record will also include  * an array of log-specific FUIDs to replace the ephemeral IDs.  * Only one copy of each unique domain will be present, so the log-specific  * FUIDs will use an index into a compressed domain table.  On replay this  * information will be used to construct real FUIDs (and bypass idmap,  * since it may not be available).  */
comment|/*  * Log record for creates with optional ACL  * This log record is also used for recording any FUID  * information needed for replaying the create.  If the  * file doesn't have any actual ACEs then the lr_aclcnt  * would be zero.  *  * After lr_acl_flags, there are a lr_acl_bytes number of variable sized ace's.  * If create is also setting xvattr's, then acl data follows xvattr.  * If ACE FUIDs are needed then they will follow the xvattr_t.  Following  * the FUIDs will be the domain table information.  The FUIDs for the owner  * and group will be in lr_create.  Name follows ACL data.  */
typedef|typedef
struct|struct
block|{
name|lr_create_t
name|lr_create
decl_stmt|;
comment|/* common create portion */
name|uint64_t
name|lr_aclcnt
decl_stmt|;
comment|/* number of ACEs in ACL */
name|uint64_t
name|lr_domcnt
decl_stmt|;
comment|/* number of unique domains */
name|uint64_t
name|lr_fuidcnt
decl_stmt|;
comment|/* number of real fuids */
name|uint64_t
name|lr_acl_bytes
decl_stmt|;
comment|/* number of bytes in ACL */
name|uint64_t
name|lr_acl_flags
decl_stmt|;
comment|/* ACL flags */
block|}
name|lr_acl_create_t
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
comment|/* no longer used */
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
comment|/* optional attribute lr_attr_t may be here */
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
name|lr_acl_v0_t
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
comment|/* number of ACEs in ACL */
name|uint64_t
name|lr_domcnt
decl_stmt|;
comment|/* number of unique domains */
name|uint64_t
name|lr_fuidcnt
decl_stmt|;
comment|/* number of real fuids */
name|uint64_t
name|lr_acl_bytes
decl_stmt|;
comment|/* number of bytes in ACL */
name|uint64_t
name|lr_acl_flags
decl_stmt|;
comment|/* ACL flags */
comment|/* lr_acl_bytes number of variable sized ace's follows */
block|}
name|lr_acl_t
typedef|;
comment|/*  * ZIL structure definitions, interface function prototype and globals.  */
comment|/*  * Writes are handled in three different ways:  *  * WR_INDIRECT:  *    In this mode, if we need to commit the write later, then the block  *    is immediately written into the file system (using dmu_sync),  *    and a pointer to the block is put into the log record.  *    When the txg commits the block is linked in.  *    This saves additionally writing the data into the log record.  *    There are a few requirements for this to occur:  *	- write is greater than zfs/zvol_immediate_write_sz  *	- not using slogs (as slogs are assumed to always be faster  *	  than writing into the main pool)  *	- the write occupies only one block  * WR_COPIED:  *    If we know we'll immediately be committing the  *    transaction (FSYNC or FDSYNC), the we allocate a larger  *    log record here for the data and copy the data in.  * WR_NEED_COPY:  *    Otherwise we don't allocate a buffer, and *if* we need to  *    flush the write later then a buffer is allocated and  *    we retrieve the data using the dmu.  */
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
name|WR_NUM_STATES
comment|/* number of states */
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
name|uint64_t
name|itx_oid
decl_stmt|;
comment|/* object id */
name|lr_t
name|itx_lr
decl_stmt|;
comment|/* common part of log record */
comment|/* followed by type-specific part of lr_xx_t and its immediate data */
block|}
name|itx_t
typedef|;
typedef|typedef
name|int
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
name|int
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
name|int
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
name|zil_replay_func_t
modifier|*
name|replay_func
index|[
name|TX_MAX_TYPE
index|]
parameter_list|)
function_decl|;
specifier|extern
name|boolean_t
name|zil_replaying
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
name|void
name|zil_destroy_sync
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
name|zil_rollback_destroy
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
name|itx_t
modifier|*
name|zil_itx_create
parameter_list|(
name|uint64_t
name|txtype
parameter_list|,
name|size_t
name|lrsize
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zil_itx_destroy
parameter_list|(
name|itx_t
modifier|*
name|itx
parameter_list|)
function_decl|;
specifier|extern
name|void
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
name|zil_async_to_sync
parameter_list|(
name|zilog_t
modifier|*
name|zilog
parameter_list|,
name|uint64_t
name|oid
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
name|oid
parameter_list|)
function_decl|;
specifier|extern
name|int
name|zil_vdev_offline
parameter_list|(
specifier|const
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
name|int
name|zil_claim
parameter_list|(
name|struct
name|dsl_pool
modifier|*
name|dp
parameter_list|,
name|struct
name|dsl_dataset
modifier|*
name|ds
parameter_list|,
name|void
modifier|*
name|txarg
parameter_list|)
function_decl|;
specifier|extern
name|int
name|zil_check_log_chain
parameter_list|(
name|struct
name|dsl_pool
modifier|*
name|dp
parameter_list|,
name|struct
name|dsl_dataset
modifier|*
name|ds
parameter_list|,
name|void
modifier|*
name|tx
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
parameter_list|,
name|uint64_t
name|synced_txg
parameter_list|)
function_decl|;
specifier|extern
name|int
name|zil_suspend
parameter_list|(
specifier|const
name|char
modifier|*
name|osname
parameter_list|,
name|void
modifier|*
modifier|*
name|cookiep
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zil_resume
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zil_add_block
parameter_list|(
name|zilog_t
modifier|*
name|zilog
parameter_list|,
specifier|const
name|blkptr_t
modifier|*
name|bp
parameter_list|)
function_decl|;
specifier|extern
name|int
name|zil_bp_tree_add
parameter_list|(
name|zilog_t
modifier|*
name|zilog
parameter_list|,
specifier|const
name|blkptr_t
modifier|*
name|bp
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zil_set_sync
parameter_list|(
name|zilog_t
modifier|*
name|zilog
parameter_list|,
name|uint64_t
name|syncval
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zil_set_logbias
parameter_list|(
name|zilog_t
modifier|*
name|zilog
parameter_list|,
name|uint64_t
name|slogval
parameter_list|)
function_decl|;
specifier|extern
name|int
name|zil_replay_disable
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

