begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)stat.h	8.12 (Berkeley) 6/16/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_STAT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_STAT_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_timespec.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_BLKSIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__blksize_t
name|blksize_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_BLKSIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_BLKCNT_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__blkcnt_t
name|blkcnt_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_BLKCNT_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__dev_t
name|dev_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_DEV_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_FFLAGS_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__fflags_t
name|fflags_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_FFLAGS_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_GID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__gid_t
name|gid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_GID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_INO_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__ino_t
name|ino_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_INO_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_MODE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__mode_t
name|mode_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_MODE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_NLINK_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__nlink_t
name|nlink_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_NLINK_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_OFF_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__off_t
name|off_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_OFF_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_UID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__uid_t
name|uid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_UID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
name|__BSD_VISIBLE
end_if

begin_comment
comment|/*  * XXX We get miscellaneous namespace pollution with this.  */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|ostat
block|{
name|__uint16_t
name|st_dev
decl_stmt|;
comment|/* inode's device */
name|__uint32_t
name|st_ino
decl_stmt|;
comment|/* inode's number */
name|mode_t
name|st_mode
decl_stmt|;
comment|/* inode protection mode */
name|__uint16_t
name|st_nlink
decl_stmt|;
comment|/* number of hard links */
name|__uint16_t
name|st_uid
decl_stmt|;
comment|/* user ID of the file's owner */
name|__uint16_t
name|st_gid
decl_stmt|;
comment|/* group ID of the file's group */
name|__uint16_t
name|st_rdev
decl_stmt|;
comment|/* device type */
name|__int32_t
name|st_size
decl_stmt|;
comment|/* file size, in bytes */
name|struct
name|timespec
name|st_atim
decl_stmt|;
comment|/* time of last access */
name|struct
name|timespec
name|st_mtim
decl_stmt|;
comment|/* time of last data modification */
name|struct
name|timespec
name|st_ctim
decl_stmt|;
comment|/* time of last file status change */
name|__int32_t
name|st_blksize
decl_stmt|;
comment|/* optimal blocksize for I/O */
name|__int32_t
name|st_blocks
decl_stmt|;
comment|/* blocks allocated for file */
name|fflags_t
name|st_flags
decl_stmt|;
comment|/* user defined flags for file */
name|__uint32_t
name|st_gen
decl_stmt|;
comment|/* file generation number */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WANT_FREEBSD11_STAT
argument_list|)
operator|||
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_struct
struct|struct
name|freebsd11_stat
block|{
name|__uint32_t
name|st_dev
decl_stmt|;
comment|/* inode's device */
name|__uint32_t
name|st_ino
decl_stmt|;
comment|/* inode's number */
name|mode_t
name|st_mode
decl_stmt|;
comment|/* inode protection mode */
name|__uint16_t
name|st_nlink
decl_stmt|;
comment|/* number of hard links */
name|uid_t
name|st_uid
decl_stmt|;
comment|/* user ID of the file's owner */
name|gid_t
name|st_gid
decl_stmt|;
comment|/* group ID of the file's group */
name|__uint32_t
name|st_rdev
decl_stmt|;
comment|/* device type */
name|struct
name|timespec
name|st_atim
decl_stmt|;
comment|/* time of last access */
name|struct
name|timespec
name|st_mtim
decl_stmt|;
comment|/* time of last data modification */
name|struct
name|timespec
name|st_ctim
decl_stmt|;
comment|/* time of last file status change */
name|off_t
name|st_size
decl_stmt|;
comment|/* file size, in bytes */
name|blkcnt_t
name|st_blocks
decl_stmt|;
comment|/* blocks allocated for file */
name|blksize_t
name|st_blksize
decl_stmt|;
comment|/* optimal blocksize for I/O */
name|fflags_t
name|st_flags
decl_stmt|;
comment|/* user defined flags for file */
name|__uint32_t
name|st_gen
decl_stmt|;
comment|/* file generation number */
name|__int32_t
name|st_lspare
decl_stmt|;
name|struct
name|timespec
name|st_birthtim
decl_stmt|;
comment|/* time of file creation */
comment|/* 	 * Explicitly pad st_birthtim to 16 bytes so that the size of 	 * struct stat is backwards compatible.  We use bitfields instead 	 * of an array of chars so that this doesn't require a C99 compiler 	 * to compile if the size of the padding is 0.  We use 2 bitfields 	 * to cover up to 64 bits on 32-bit machines.  We assume that 	 * CHAR_BIT is 8... 	 */
name|unsigned
name|int
range|:
operator|(
literal|8
operator|/
literal|2
operator|)
operator|*
operator|(
literal|16
operator|-
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|timespec
argument_list|)
operator|)
decl_stmt|;
name|unsigned
name|int
range|:
operator|(
literal|8
operator|/
literal|2
operator|)
operator|*
operator|(
literal|16
operator|-
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|timespec
argument_list|)
operator|)
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _WANT_FREEBSD11_STAT || _KERNEL */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STAT_TIME_T_EXT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|stat
block|{
name|dev_t
name|st_dev
decl_stmt|;
comment|/* inode's device */
name|ino_t
name|st_ino
decl_stmt|;
comment|/* inode's number */
name|nlink_t
name|st_nlink
decl_stmt|;
comment|/* number of hard links */
name|mode_t
name|st_mode
decl_stmt|;
comment|/* inode protection mode */
name|__int16_t
name|st_padding0
decl_stmt|;
name|uid_t
name|st_uid
decl_stmt|;
comment|/* user ID of the file's owner */
name|gid_t
name|st_gid
decl_stmt|;
comment|/* group ID of the file's group */
name|__int32_t
name|st_padding1
decl_stmt|;
name|dev_t
name|st_rdev
decl_stmt|;
comment|/* device type */
ifdef|#
directive|ifdef
name|__STAT_TIME_T_EXT
name|__int32_t
name|st_atim_ext
decl_stmt|;
endif|#
directive|endif
name|struct
name|timespec
name|st_atim
decl_stmt|;
comment|/* time of last access */
ifdef|#
directive|ifdef
name|__STAT_TIME_T_EXT
name|__int32_t
name|st_mtim_ext
decl_stmt|;
endif|#
directive|endif
name|struct
name|timespec
name|st_mtim
decl_stmt|;
comment|/* time of last data modification */
ifdef|#
directive|ifdef
name|__STAT_TIME_T_EXT
name|__int32_t
name|st_ctim_ext
decl_stmt|;
endif|#
directive|endif
name|struct
name|timespec
name|st_ctim
decl_stmt|;
comment|/* time of last file status change */
ifdef|#
directive|ifdef
name|__STAT_TIME_T_EXT
name|__int32_t
name|st_btim_ext
decl_stmt|;
endif|#
directive|endif
name|struct
name|timespec
name|st_birthtim
decl_stmt|;
comment|/* time of file creation */
name|off_t
name|st_size
decl_stmt|;
comment|/* file size, in bytes */
name|blkcnt_t
name|st_blocks
decl_stmt|;
comment|/* blocks allocated for file */
name|blksize_t
name|st_blksize
decl_stmt|;
comment|/* optimal blocksize for I/O */
name|fflags_t
name|st_flags
decl_stmt|;
comment|/* user defined flags for file */
name|__uint64_t
name|st_gen
decl_stmt|;
comment|/* file generation number */
name|__uint64_t
name|st_spare
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|nstat
block|{
name|__uint32_t
name|st_dev
decl_stmt|;
comment|/* inode's device */
name|__uint32_t
name|st_ino
decl_stmt|;
comment|/* inode's number */
name|__uint32_t
name|st_mode
decl_stmt|;
comment|/* inode protection mode */
name|__uint32_t
name|st_nlink
decl_stmt|;
comment|/* number of hard links */
name|uid_t
name|st_uid
decl_stmt|;
comment|/* user ID of the file's owner */
name|gid_t
name|st_gid
decl_stmt|;
comment|/* group ID of the file's group */
name|__uint32_t
name|st_rdev
decl_stmt|;
comment|/* device type */
name|struct
name|timespec
name|st_atim
decl_stmt|;
comment|/* time of last access */
name|struct
name|timespec
name|st_mtim
decl_stmt|;
comment|/* time of last data modification */
name|struct
name|timespec
name|st_ctim
decl_stmt|;
comment|/* time of last file status change */
name|off_t
name|st_size
decl_stmt|;
comment|/* file size, in bytes */
name|blkcnt_t
name|st_blocks
decl_stmt|;
comment|/* blocks allocated for file */
name|blksize_t
name|st_blksize
decl_stmt|;
comment|/* optimal blocksize for I/O */
name|fflags_t
name|st_flags
decl_stmt|;
comment|/* user defined flags for file */
name|__uint32_t
name|st_gen
decl_stmt|;
comment|/* file generation number */
name|struct
name|timespec
name|st_birthtim
decl_stmt|;
comment|/* time of file creation */
comment|/* 	 * See comment in the definition of struct freebsd11_stat 	 * above about the following padding. 	 */
name|unsigned
name|int
range|:
operator|(
literal|8
operator|/
literal|2
operator|)
operator|*
operator|(
literal|16
operator|-
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|timespec
argument_list|)
operator|)
decl_stmt|;
name|unsigned
name|int
range|:
operator|(
literal|8
operator|/
literal|2
operator|)
operator|*
operator|(
literal|16
operator|-
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|timespec
argument_list|)
operator|)
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_define
define|#
directive|define
name|st_atime
value|st_atim.tv_sec
end_define

begin_define
define|#
directive|define
name|st_mtime
value|st_mtim.tv_sec
end_define

begin_define
define|#
directive|define
name|st_ctime
value|st_ctim.tv_sec
end_define

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|st_birthtime
value|st_birthtim.tv_sec
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For compatibility. */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|st_atimespec
value|st_atim
end_define

begin_define
define|#
directive|define
name|st_mtimespec
value|st_mtim
end_define

begin_define
define|#
directive|define
name|st_ctimespec
value|st_ctim
end_define

begin_define
define|#
directive|define
name|st_birthtimespec
value|st_birthtim
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
comment|/* !_KERNEL */
end_comment

begin_define
define|#
directive|define
name|S_ISUID
value|0004000
end_define

begin_comment
comment|/* set user id on execution */
end_comment

begin_define
define|#
directive|define
name|S_ISGID
value|0002000
end_define

begin_comment
comment|/* set group id on execution */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|S_ISTXT
value|0001000
end_define

begin_comment
comment|/* sticky bit */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|S_IRWXU
value|0000700
end_define

begin_comment
comment|/* RWX mask for owner */
end_comment

begin_define
define|#
directive|define
name|S_IRUSR
value|0000400
end_define

begin_comment
comment|/* R for owner */
end_comment

begin_define
define|#
directive|define
name|S_IWUSR
value|0000200
end_define

begin_comment
comment|/* W for owner */
end_comment

begin_define
define|#
directive|define
name|S_IXUSR
value|0000100
end_define

begin_comment
comment|/* X for owner */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|S_IREAD
value|S_IRUSR
end_define

begin_define
define|#
directive|define
name|S_IWRITE
value|S_IWUSR
end_define

begin_define
define|#
directive|define
name|S_IEXEC
value|S_IXUSR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|S_IRWXG
value|0000070
end_define

begin_comment
comment|/* RWX mask for group */
end_comment

begin_define
define|#
directive|define
name|S_IRGRP
value|0000040
end_define

begin_comment
comment|/* R for group */
end_comment

begin_define
define|#
directive|define
name|S_IWGRP
value|0000020
end_define

begin_comment
comment|/* W for group */
end_comment

begin_define
define|#
directive|define
name|S_IXGRP
value|0000010
end_define

begin_comment
comment|/* X for group */
end_comment

begin_define
define|#
directive|define
name|S_IRWXO
value|0000007
end_define

begin_comment
comment|/* RWX mask for other */
end_comment

begin_define
define|#
directive|define
name|S_IROTH
value|0000004
end_define

begin_comment
comment|/* R for other */
end_comment

begin_define
define|#
directive|define
name|S_IWOTH
value|0000002
end_define

begin_comment
comment|/* W for other */
end_comment

begin_define
define|#
directive|define
name|S_IXOTH
value|0000001
end_define

begin_comment
comment|/* X for other */
end_comment

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

begin_define
define|#
directive|define
name|S_IFMT
value|0170000
end_define

begin_comment
comment|/* type of file mask */
end_comment

begin_define
define|#
directive|define
name|S_IFIFO
value|0010000
end_define

begin_comment
comment|/* named pipe (fifo) */
end_comment

begin_define
define|#
directive|define
name|S_IFCHR
value|0020000
end_define

begin_comment
comment|/* character special */
end_comment

begin_define
define|#
directive|define
name|S_IFDIR
value|0040000
end_define

begin_comment
comment|/* directory */
end_comment

begin_define
define|#
directive|define
name|S_IFBLK
value|0060000
end_define

begin_comment
comment|/* block special */
end_comment

begin_define
define|#
directive|define
name|S_IFREG
value|0100000
end_define

begin_comment
comment|/* regular */
end_comment

begin_define
define|#
directive|define
name|S_IFLNK
value|0120000
end_define

begin_comment
comment|/* symbolic link */
end_comment

begin_define
define|#
directive|define
name|S_IFSOCK
value|0140000
end_define

begin_comment
comment|/* socket */
end_comment

begin_define
define|#
directive|define
name|S_ISVTX
value|0001000
end_define

begin_comment
comment|/* save swapped text even after use */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|S_IFWHT
value|0160000
end_define

begin_comment
comment|/* whiteout */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|(((m)& 0170000) == 0040000)
end_define

begin_comment
comment|/* directory */
end_comment

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|m
parameter_list|)
value|(((m)& 0170000) == 0020000)
end_define

begin_comment
comment|/* char special */
end_comment

begin_define
define|#
directive|define
name|S_ISBLK
parameter_list|(
name|m
parameter_list|)
value|(((m)& 0170000) == 0060000)
end_define

begin_comment
comment|/* block special */
end_comment

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|m
parameter_list|)
value|(((m)& 0170000) == 0100000)
end_define

begin_comment
comment|/* regular file */
end_comment

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|m
parameter_list|)
value|(((m)& 0170000) == 0010000)
end_define

begin_comment
comment|/* fifo or socket */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
end_if

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|m
parameter_list|)
value|(((m)& 0170000) == 0120000)
end_define

begin_comment
comment|/* symbolic link */
end_comment

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|m
parameter_list|)
value|(((m)& 0170000) == 0140000)
end_define

begin_comment
comment|/* socket */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|S_ISWHT
parameter_list|(
name|m
parameter_list|)
value|(((m)& 0170000) == 0160000)
end_define

begin_comment
comment|/* whiteout */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|ACCESSPERMS
value|(S_IRWXU|S_IRWXG|S_IRWXO)
end_define

begin_comment
comment|/* 0777 */
end_comment

begin_comment
comment|/* 7777 */
end_comment

begin_define
define|#
directive|define
name|ALLPERMS
value|(S_ISUID|S_ISGID|S_ISTXT|S_IRWXU|S_IRWXG|S_IRWXO)
end_define

begin_comment
comment|/* 0666 */
end_comment

begin_define
define|#
directive|define
name|DEFFILEMODE
value|(S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
end_define

begin_define
define|#
directive|define
name|S_BLKSIZE
value|512
end_define

begin_comment
comment|/* block size used in the stat struct */
end_comment

begin_comment
comment|/*  * Definitions of flags stored in file flags word.  *  * Super-user and owner changeable flags.  */
end_comment

begin_define
define|#
directive|define
name|UF_SETTABLE
value|0x0000ffff
end_define

begin_comment
comment|/* mask of owner changeable flags */
end_comment

begin_define
define|#
directive|define
name|UF_NODUMP
value|0x00000001
end_define

begin_comment
comment|/* do not dump file */
end_comment

begin_define
define|#
directive|define
name|UF_IMMUTABLE
value|0x00000002
end_define

begin_comment
comment|/* file may not be changed */
end_comment

begin_define
define|#
directive|define
name|UF_APPEND
value|0x00000004
end_define

begin_comment
comment|/* writes to file may only append */
end_comment

begin_define
define|#
directive|define
name|UF_OPAQUE
value|0x00000008
end_define

begin_comment
comment|/* directory is opaque wrt. union */
end_comment

begin_define
define|#
directive|define
name|UF_NOUNLINK
value|0x00000010
end_define

begin_comment
comment|/* file may not be removed or renamed */
end_comment

begin_comment
comment|/*  * These two bits are defined in MacOS X.  They are not currently used in  * FreeBSD.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|UF_COMPRESSED
value|0x00000020
end_define

begin_comment
comment|/* file is compressed */
end_comment

begin_define
define|#
directive|define
name|UF_TRACKED
value|0x00000040
end_define

begin_comment
comment|/* renames and deletes are tracked */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|UF_SYSTEM
value|0x00000080
end_define

begin_comment
comment|/* Windows system file bit */
end_comment

begin_define
define|#
directive|define
name|UF_SPARSE
value|0x00000100
end_define

begin_comment
comment|/* sparse file */
end_comment

begin_define
define|#
directive|define
name|UF_OFFLINE
value|0x00000200
end_define

begin_comment
comment|/* file is offline */
end_comment

begin_define
define|#
directive|define
name|UF_REPARSE
value|0x00000400
end_define

begin_comment
comment|/* Windows reparse point file bit */
end_comment

begin_define
define|#
directive|define
name|UF_ARCHIVE
value|0x00000800
end_define

begin_comment
comment|/* file needs to be archived */
end_comment

begin_define
define|#
directive|define
name|UF_READONLY
value|0x00001000
end_define

begin_comment
comment|/* Windows readonly file bit */
end_comment

begin_comment
comment|/* This is the same as the MacOS X definition of UF_HIDDEN. */
end_comment

begin_define
define|#
directive|define
name|UF_HIDDEN
value|0x00008000
end_define

begin_comment
comment|/* file is hidden */
end_comment

begin_comment
comment|/*  * Super-user changeable flags.  */
end_comment

begin_define
define|#
directive|define
name|SF_SETTABLE
value|0xffff0000
end_define

begin_comment
comment|/* mask of superuser changeable flags */
end_comment

begin_define
define|#
directive|define
name|SF_ARCHIVED
value|0x00010000
end_define

begin_comment
comment|/* file is archived */
end_comment

begin_define
define|#
directive|define
name|SF_IMMUTABLE
value|0x00020000
end_define

begin_comment
comment|/* file may not be changed */
end_comment

begin_define
define|#
directive|define
name|SF_APPEND
value|0x00040000
end_define

begin_comment
comment|/* writes to file may only append */
end_comment

begin_define
define|#
directive|define
name|SF_NOUNLINK
value|0x00100000
end_define

begin_comment
comment|/* file may not be removed or renamed */
end_comment

begin_define
define|#
directive|define
name|SF_SNAPSHOT
value|0x00200000
end_define

begin_comment
comment|/* snapshot inode */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Shorthand abbreviations of above.  */
end_comment

begin_define
define|#
directive|define
name|OPAQUE
value|(UF_OPAQUE)
end_define

begin_define
define|#
directive|define
name|APPEND
value|(UF_APPEND | SF_APPEND)
end_define

begin_define
define|#
directive|define
name|IMMUTABLE
value|(UF_IMMUTABLE | SF_IMMUTABLE)
end_define

begin_define
define|#
directive|define
name|NOUNLINK
value|(UF_NOUNLINK | SF_NOUNLINK)
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
comment|/* __BSD_VISIBLE */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200809
end_if

begin_define
define|#
directive|define
name|UTIME_NOW
value|-1
end_define

begin_define
define|#
directive|define
name|UTIME_OMIT
value|-2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
name|__BEGIN_DECLS
if|#
directive|if
name|__BSD_VISIBLE
name|int
name|chflags
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chflagsat
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|chmod
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
name|int
name|fchflags
parameter_list|(
name|int
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
end_if

begin_function_decl
name|int
name|fchmod
parameter_list|(
name|int
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200809
end_if

begin_function_decl
name|int
name|fchmodat
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|mode_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|futimens
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|struct
name|timespec
name|times
index|[
literal|2
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|utimensat
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|struct
name|timespec
name|times
index|[
literal|2
index|]
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|fstat
parameter_list|(
name|int
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
name|int
name|lchflags
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lchmod
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
end_if

begin_function_decl
name|int
name|lstat
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|struct
name|stat
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|mkdir
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mkfifo
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MKNOD_DECLARED
argument_list|)
operator|&&
name|__XSI_VISIBLE
end_if

begin_function_decl
name|int
name|mknod
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|mode_t
parameter_list|,
name|dev_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_MKNOD_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|stat
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|struct
name|stat
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mode_t
name|umask
parameter_list|(
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200809
end_if

begin_function_decl
name|int
name|fstatat
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mkdirat
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mkfifoat
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__XSI_VISIBLE
operator|>=
literal|700
end_if

begin_function_decl
name|int
name|mknodat
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|mode_t
parameter_list|,
name|dev_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_STAT_H_ */
end_comment

end_unit

