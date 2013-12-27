begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * fsif.h  *   * Interface to FS level split device drivers.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2007, Grzegorz Milos,<gm281@cam.ac.uk>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_IO_FSIF_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_IO_FSIF_H__
end_define

begin_include
include|#
directive|include
file|"ring.h"
end_include

begin_include
include|#
directive|include
file|"../grant_table.h"
end_include

begin_define
define|#
directive|define
name|REQ_FILE_OPEN
value|1
end_define

begin_define
define|#
directive|define
name|REQ_FILE_CLOSE
value|2
end_define

begin_define
define|#
directive|define
name|REQ_FILE_READ
value|3
end_define

begin_define
define|#
directive|define
name|REQ_FILE_WRITE
value|4
end_define

begin_define
define|#
directive|define
name|REQ_STAT
value|5
end_define

begin_define
define|#
directive|define
name|REQ_FILE_TRUNCATE
value|6
end_define

begin_define
define|#
directive|define
name|REQ_REMOVE
value|7
end_define

begin_define
define|#
directive|define
name|REQ_RENAME
value|8
end_define

begin_define
define|#
directive|define
name|REQ_CREATE
value|9
end_define

begin_define
define|#
directive|define
name|REQ_DIR_LIST
value|10
end_define

begin_define
define|#
directive|define
name|REQ_CHMOD
value|11
end_define

begin_define
define|#
directive|define
name|REQ_FS_SPACE
value|12
end_define

begin_define
define|#
directive|define
name|REQ_FILE_SYNC
value|13
end_define

begin_struct
struct|struct
name|fsif_open_request
block|{
name|grant_ref_t
name|gref
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fsif_close_request
block|{
name|uint32_t
name|fd
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fsif_read_request
block|{
name|uint32_t
name|fd
decl_stmt|;
name|int32_t
name|pad
decl_stmt|;
name|uint64_t
name|len
decl_stmt|;
name|uint64_t
name|offset
decl_stmt|;
name|grant_ref_t
name|grefs
index|[
literal|1
index|]
decl_stmt|;
comment|/* Variable length */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fsif_write_request
block|{
name|uint32_t
name|fd
decl_stmt|;
name|int32_t
name|pad
decl_stmt|;
name|uint64_t
name|len
decl_stmt|;
name|uint64_t
name|offset
decl_stmt|;
name|grant_ref_t
name|grefs
index|[
literal|1
index|]
decl_stmt|;
comment|/* Variable length */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fsif_stat_request
block|{
name|uint32_t
name|fd
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This structure is a copy of some fields from stat structure, returned  * via the ring. */
end_comment

begin_struct
struct|struct
name|fsif_stat_response
block|{
name|int32_t
name|stat_mode
decl_stmt|;
name|uint32_t
name|stat_uid
decl_stmt|;
name|uint32_t
name|stat_gid
decl_stmt|;
name|int32_t
name|stat_ret
decl_stmt|;
name|int64_t
name|stat_size
decl_stmt|;
name|int64_t
name|stat_atime
decl_stmt|;
name|int64_t
name|stat_mtime
decl_stmt|;
name|int64_t
name|stat_ctime
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fsif_truncate_request
block|{
name|uint32_t
name|fd
decl_stmt|;
name|int32_t
name|pad
decl_stmt|;
name|int64_t
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fsif_remove_request
block|{
name|grant_ref_t
name|gref
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fsif_rename_request
block|{
name|uint16_t
name|old_name_offset
decl_stmt|;
name|uint16_t
name|new_name_offset
decl_stmt|;
name|grant_ref_t
name|gref
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fsif_create_request
block|{
name|int8_t
name|directory
decl_stmt|;
name|int8_t
name|pad
decl_stmt|;
name|int16_t
name|pad2
decl_stmt|;
name|int32_t
name|mode
decl_stmt|;
name|grant_ref_t
name|gref
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fsif_list_request
block|{
name|uint32_t
name|offset
decl_stmt|;
name|grant_ref_t
name|gref
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NR_FILES_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|NR_FILES_SIZE
value|16
end_define

begin_comment
comment|/* 16 bits for the number of files mask */
end_comment

begin_define
define|#
directive|define
name|NR_FILES_MASK
value|(((1ULL<< NR_FILES_SIZE) - 1)<< NR_FILES_SHIFT)
end_define

begin_define
define|#
directive|define
name|ERROR_SIZE
value|32
end_define

begin_comment
comment|/* 32 bits for the error mask */
end_comment

begin_define
define|#
directive|define
name|ERROR_SHIFT
value|(NR_FILES_SIZE + NR_FILES_SHIFT)
end_define

begin_define
define|#
directive|define
name|ERROR_MASK
value|(((1ULL<< ERROR_SIZE) - 1)<< ERROR_SHIFT)
end_define

begin_define
define|#
directive|define
name|HAS_MORE_SHIFT
value|(ERROR_SHIFT + ERROR_SIZE)
end_define

begin_define
define|#
directive|define
name|HAS_MORE_FLAG
value|(1ULL<< HAS_MORE_SHIFT)
end_define

begin_struct
struct|struct
name|fsif_chmod_request
block|{
name|uint32_t
name|fd
decl_stmt|;
name|int32_t
name|mode
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fsif_space_request
block|{
name|grant_ref_t
name|gref
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fsif_sync_request
block|{
name|uint32_t
name|fd
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* FS operation request */
end_comment

begin_struct
struct|struct
name|fsif_request
block|{
name|uint8_t
name|type
decl_stmt|;
comment|/* Type of the request                  */
name|uint8_t
name|pad
decl_stmt|;
name|uint16_t
name|id
decl_stmt|;
comment|/* Request ID, copied to the response   */
name|uint32_t
name|pad2
decl_stmt|;
union|union
block|{
name|struct
name|fsif_open_request
name|fopen
decl_stmt|;
name|struct
name|fsif_close_request
name|fclose
decl_stmt|;
name|struct
name|fsif_read_request
name|fread
decl_stmt|;
name|struct
name|fsif_write_request
name|fwrite
decl_stmt|;
name|struct
name|fsif_stat_request
name|fstat
decl_stmt|;
name|struct
name|fsif_truncate_request
name|ftruncate
decl_stmt|;
name|struct
name|fsif_remove_request
name|fremove
decl_stmt|;
name|struct
name|fsif_rename_request
name|frename
decl_stmt|;
name|struct
name|fsif_create_request
name|fcreate
decl_stmt|;
name|struct
name|fsif_list_request
name|flist
decl_stmt|;
name|struct
name|fsif_chmod_request
name|fchmod
decl_stmt|;
name|struct
name|fsif_space_request
name|fspace
decl_stmt|;
name|struct
name|fsif_sync_request
name|fsync
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fsif_request
name|fsif_request_t
typedef|;
end_typedef

begin_comment
comment|/* FS operation response */
end_comment

begin_struct
struct|struct
name|fsif_response
block|{
name|uint16_t
name|id
decl_stmt|;
name|uint16_t
name|pad1
decl_stmt|;
name|uint32_t
name|pad2
decl_stmt|;
union|union
block|{
name|uint64_t
name|ret_val
decl_stmt|;
name|struct
name|fsif_stat_response
name|fstat
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fsif_response
name|fsif_response_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FSIF_RING_ENTRY_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|FSIF_NR_READ_GNTS
value|((FSIF_RING_ENTRY_SIZE - sizeof(struct fsif_read_request)) /  \                                 sizeof(grant_ref_t) + 1)
end_define

begin_define
define|#
directive|define
name|FSIF_NR_WRITE_GNTS
value|((FSIF_RING_ENTRY_SIZE - sizeof(struct fsif_write_request)) / \                                 sizeof(grant_ref_t) + 1)
end_define

begin_expr_stmt
name|DEFINE_RING_TYPES
argument_list|(
name|fsif
argument_list|,
expr|struct
name|fsif_request
argument_list|,
expr|struct
name|fsif_response
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|STATE_INITIALISED
value|"init"
end_define

begin_define
define|#
directive|define
name|STATE_READY
value|"ready"
end_define

begin_define
define|#
directive|define
name|STATE_CLOSING
value|"closing"
end_define

begin_define
define|#
directive|define
name|STATE_CLOSED
value|"closed"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

