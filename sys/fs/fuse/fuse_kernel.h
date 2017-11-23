begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*--  * This file defines the kernel interface of FUSE  * Copyright (C) 2001-2007  Miklos Szeredi<miklos@szeredi.hu>  *  * This program can be distributed under the terms of the GNU GPL.  * See the file COPYING.  *  * This -- and only this -- header file may also be distributed under  * the terms of the BSD Licence as follows:  *  * Copyright (C) 2001-2007 Miklos Szeredi. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|linux
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|__u64
value|uint64_t
end_define

begin_define
define|#
directive|define
name|__u32
value|uint32_t
end_define

begin_define
define|#
directive|define
name|__s32
value|int32_t
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<asm/types.h>
end_include

begin_include
include|#
directive|include
file|<linux/major.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** Version number of this interface */
end_comment

begin_define
define|#
directive|define
name|FUSE_KERNEL_VERSION
value|7
end_define

begin_comment
comment|/** Minor version number of this interface */
end_comment

begin_define
define|#
directive|define
name|FUSE_KERNEL_MINOR_VERSION
value|8
end_define

begin_comment
comment|/** The node ID of the root inode */
end_comment

begin_define
define|#
directive|define
name|FUSE_ROOT_ID
value|1
end_define

begin_comment
comment|/** The major number of the fuse character device */
end_comment

begin_define
define|#
directive|define
name|FUSE_MAJOR
value|MISC_MAJOR
end_define

begin_comment
comment|/** The minor number of the fuse character device */
end_comment

begin_define
define|#
directive|define
name|FUSE_MINOR
value|229
end_define

begin_comment
comment|/* Make sure all structures are padded to 64bit boundary, so 32bit    userspace works under 64bit kernels */
end_comment

begin_struct
struct|struct
name|fuse_attr
block|{
name|__u64
name|ino
decl_stmt|;
name|__u64
name|size
decl_stmt|;
name|__u64
name|blocks
decl_stmt|;
name|__u64
name|atime
decl_stmt|;
name|__u64
name|mtime
decl_stmt|;
name|__u64
name|ctime
decl_stmt|;
name|__u32
name|atimensec
decl_stmt|;
name|__u32
name|mtimensec
decl_stmt|;
name|__u32
name|ctimensec
decl_stmt|;
name|__u32
name|mode
decl_stmt|;
name|__u32
name|nlink
decl_stmt|;
name|__u32
name|uid
decl_stmt|;
name|__u32
name|gid
decl_stmt|;
name|__u32
name|rdev
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_kstatfs
block|{
name|__u64
name|blocks
decl_stmt|;
name|__u64
name|bfree
decl_stmt|;
name|__u64
name|bavail
decl_stmt|;
name|__u64
name|files
decl_stmt|;
name|__u64
name|ffree
decl_stmt|;
name|__u32
name|bsize
decl_stmt|;
name|__u32
name|namelen
decl_stmt|;
name|__u32
name|frsize
decl_stmt|;
name|__u32
name|padding
decl_stmt|;
name|__u32
name|spare
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_file_lock
block|{
name|__u64
name|start
decl_stmt|;
name|__u64
name|end
decl_stmt|;
name|__u32
name|type
decl_stmt|;
name|__u32
name|pid
decl_stmt|;
comment|/* tgid */
block|}
struct|;
end_struct

begin_comment
comment|/**  * Bitmasks for fuse_setattr_in.valid  */
end_comment

begin_define
define|#
directive|define
name|FATTR_MODE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|FATTR_UID
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|FATTR_GID
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|FATTR_SIZE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|FATTR_ATIME
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|FATTR_MTIME
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|FATTR_FH
value|(1<< 6)
end_define

begin_comment
comment|/**  * Flags returned by the OPEN request  *  * FOPEN_DIRECT_IO: bypass page cache for this open file  * FOPEN_KEEP_CACHE: don't invalidate the data cache on open  */
end_comment

begin_define
define|#
directive|define
name|FOPEN_DIRECT_IO
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|FOPEN_KEEP_CACHE
value|(1<< 1)
end_define

begin_comment
comment|/**  * INIT request/reply flags  */
end_comment

begin_define
define|#
directive|define
name|FUSE_ASYNC_READ
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|FUSE_POSIX_LOCKS
value|(1<< 1)
end_define

begin_comment
comment|/**  * Release flags  */
end_comment

begin_define
define|#
directive|define
name|FUSE_RELEASE_FLUSH
value|(1<< 0)
end_define

begin_enum
enum|enum
name|fuse_opcode
block|{
name|FUSE_LOOKUP
init|=
literal|1
block|,
name|FUSE_FORGET
init|=
literal|2
block|,
comment|/* no reply */
name|FUSE_GETATTR
init|=
literal|3
block|,
name|FUSE_SETATTR
init|=
literal|4
block|,
name|FUSE_READLINK
init|=
literal|5
block|,
name|FUSE_SYMLINK
init|=
literal|6
block|,
name|FUSE_MKNOD
init|=
literal|8
block|,
name|FUSE_MKDIR
init|=
literal|9
block|,
name|FUSE_UNLINK
init|=
literal|10
block|,
name|FUSE_RMDIR
init|=
literal|11
block|,
name|FUSE_RENAME
init|=
literal|12
block|,
name|FUSE_LINK
init|=
literal|13
block|,
name|FUSE_OPEN
init|=
literal|14
block|,
name|FUSE_READ
init|=
literal|15
block|,
name|FUSE_WRITE
init|=
literal|16
block|,
name|FUSE_STATFS
init|=
literal|17
block|,
name|FUSE_RELEASE
init|=
literal|18
block|,
name|FUSE_FSYNC
init|=
literal|20
block|,
name|FUSE_SETXATTR
init|=
literal|21
block|,
name|FUSE_GETXATTR
init|=
literal|22
block|,
name|FUSE_LISTXATTR
init|=
literal|23
block|,
name|FUSE_REMOVEXATTR
init|=
literal|24
block|,
name|FUSE_FLUSH
init|=
literal|25
block|,
name|FUSE_INIT
init|=
literal|26
block|,
name|FUSE_OPENDIR
init|=
literal|27
block|,
name|FUSE_READDIR
init|=
literal|28
block|,
name|FUSE_RELEASEDIR
init|=
literal|29
block|,
name|FUSE_FSYNCDIR
init|=
literal|30
block|,
name|FUSE_GETLK
init|=
literal|31
block|,
name|FUSE_SETLK
init|=
literal|32
block|,
name|FUSE_SETLKW
init|=
literal|33
block|,
name|FUSE_ACCESS
init|=
literal|34
block|,
name|FUSE_CREATE
init|=
literal|35
block|,
name|FUSE_INTERRUPT
init|=
literal|36
block|,
name|FUSE_BMAP
init|=
literal|37
block|,
name|FUSE_DESTROY
init|=
literal|38
block|, }
enum|;
end_enum

begin_comment
comment|/* The read buffer is required to be at least 8k, but may be much larger */
end_comment

begin_define
define|#
directive|define
name|FUSE_MIN_READ_BUFFER
value|8192
end_define

begin_struct
struct|struct
name|fuse_entry_out
block|{
name|__u64
name|nodeid
decl_stmt|;
comment|/* Inode ID */
name|__u64
name|generation
decl_stmt|;
comment|/* Inode generation: nodeid:gen must 				   be unique for the fs's lifetime */
name|__u64
name|entry_valid
decl_stmt|;
comment|/* Cache timeout for the name */
name|__u64
name|attr_valid
decl_stmt|;
comment|/* Cache timeout for the attributes */
name|__u32
name|entry_valid_nsec
decl_stmt|;
name|__u32
name|attr_valid_nsec
decl_stmt|;
name|struct
name|fuse_attr
name|attr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_forget_in
block|{
name|__u64
name|nlookup
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_attr_out
block|{
name|__u64
name|attr_valid
decl_stmt|;
comment|/* Cache timeout for the attributes */
name|__u32
name|attr_valid_nsec
decl_stmt|;
name|__u32
name|dummy
decl_stmt|;
name|struct
name|fuse_attr
name|attr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_mkdir_in
block|{
name|__u32
name|mode
decl_stmt|;
name|__u32
name|padding
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_rename_in
block|{
name|__u64
name|newdir
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_link_in
block|{
name|__u64
name|oldnodeid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_setattr_in
block|{
name|__u32
name|valid
decl_stmt|;
name|__u32
name|padding
decl_stmt|;
name|__u64
name|fh
decl_stmt|;
name|__u64
name|size
decl_stmt|;
name|__u64
name|unused1
decl_stmt|;
name|__u64
name|atime
decl_stmt|;
name|__u64
name|mtime
decl_stmt|;
name|__u64
name|unused2
decl_stmt|;
name|__u32
name|atimensec
decl_stmt|;
name|__u32
name|mtimensec
decl_stmt|;
name|__u32
name|unused3
decl_stmt|;
name|__u32
name|mode
decl_stmt|;
name|__u32
name|unused4
decl_stmt|;
name|__u32
name|uid
decl_stmt|;
name|__u32
name|gid
decl_stmt|;
name|__u32
name|unused5
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_open_in
block|{
name|__u32
name|flags
decl_stmt|;
name|__u32
name|mode
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_open_out
block|{
name|__u64
name|fh
decl_stmt|;
name|__u32
name|open_flags
decl_stmt|;
name|__u32
name|padding
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_release_in
block|{
name|__u64
name|fh
decl_stmt|;
name|__u32
name|flags
decl_stmt|;
name|__u32
name|release_flags
decl_stmt|;
name|__u64
name|lock_owner
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_flush_in
block|{
name|__u64
name|fh
decl_stmt|;
name|__u32
name|unused
decl_stmt|;
name|__u32
name|padding
decl_stmt|;
name|__u64
name|lock_owner
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_read_in
block|{
name|__u64
name|fh
decl_stmt|;
name|__u64
name|offset
decl_stmt|;
name|__u32
name|size
decl_stmt|;
name|__u32
name|padding
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_write_in
block|{
name|__u64
name|fh
decl_stmt|;
name|__u64
name|offset
decl_stmt|;
name|__u32
name|size
decl_stmt|;
name|__u32
name|write_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_write_out
block|{
name|__u32
name|size
decl_stmt|;
name|__u32
name|padding
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FUSE_COMPAT_STATFS_SIZE
value|48
end_define

begin_struct
struct|struct
name|fuse_statfs_out
block|{
name|struct
name|fuse_kstatfs
name|st
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_fsync_in
block|{
name|__u64
name|fh
decl_stmt|;
name|__u32
name|fsync_flags
decl_stmt|;
name|__u32
name|padding
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_setxattr_in
block|{
name|__u32
name|size
decl_stmt|;
name|__u32
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_getxattr_in
block|{
name|__u32
name|size
decl_stmt|;
name|__u32
name|padding
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_getxattr_out
block|{
name|__u32
name|size
decl_stmt|;
name|__u32
name|padding
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_lk_in
block|{
name|__u64
name|fh
decl_stmt|;
name|__u64
name|owner
decl_stmt|;
name|struct
name|fuse_file_lock
name|lk
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_lk_out
block|{
name|struct
name|fuse_file_lock
name|lk
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_access_in
block|{
name|__u32
name|mask
decl_stmt|;
name|__u32
name|padding
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_init_in
block|{
name|__u32
name|major
decl_stmt|;
name|__u32
name|minor
decl_stmt|;
name|__u32
name|max_readahead
decl_stmt|;
name|__u32
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_init_out
block|{
name|__u32
name|major
decl_stmt|;
name|__u32
name|minor
decl_stmt|;
name|__u32
name|max_readahead
decl_stmt|;
name|__u32
name|flags
decl_stmt|;
name|__u32
name|unused
decl_stmt|;
name|__u32
name|max_write
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_interrupt_in
block|{
name|__u64
name|unique
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_bmap_in
block|{
name|__u64
name|block
decl_stmt|;
name|__u32
name|blocksize
decl_stmt|;
name|__u32
name|padding
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_bmap_out
block|{
name|__u64
name|block
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_in_header
block|{
name|__u32
name|len
decl_stmt|;
name|__u32
name|opcode
decl_stmt|;
name|__u64
name|unique
decl_stmt|;
name|__u64
name|nodeid
decl_stmt|;
name|__u32
name|uid
decl_stmt|;
name|__u32
name|gid
decl_stmt|;
name|__u32
name|pid
decl_stmt|;
name|__u32
name|padding
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_out_header
block|{
name|__u32
name|len
decl_stmt|;
name|__s32
name|error
decl_stmt|;
name|__u64
name|unique
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fuse_dirent
block|{
name|__u64
name|ino
decl_stmt|;
name|__u64
name|off
decl_stmt|;
name|__u32
name|namelen
decl_stmt|;
name|__u32
name|type
decl_stmt|;
name|char
name|name
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FUSE_NAME_OFFSET
value|offsetof(struct fuse_dirent, name)
end_define

begin_define
define|#
directive|define
name|FUSE_DIRENT_ALIGN
parameter_list|(
name|x
parameter_list|)
value|(((x) + sizeof(__u64) - 1)& ~(sizeof(__u64) - 1))
end_define

begin_define
define|#
directive|define
name|FUSE_DIRENT_SIZE
parameter_list|(
name|d
parameter_list|)
define|\
value|FUSE_DIRENT_ALIGN(FUSE_NAME_OFFSET + (d)->namelen)
end_define

end_unit

