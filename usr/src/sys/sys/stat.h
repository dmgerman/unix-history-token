begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)stat.h	8.8 (Berkeley) %G%  */
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
file|<sys/time.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_struct
struct|struct
name|ostat
block|{
name|u_int16_t
name|st_dev
decl_stmt|;
comment|/* inode's device */
name|ino_t
name|st_ino
decl_stmt|;
comment|/* inode's number */
name|mode_t
name|st_mode
decl_stmt|;
comment|/* inode protection mode */
name|nlink_t
name|st_nlink
decl_stmt|;
comment|/* number of hard links */
name|u_int16_t
name|st_uid
decl_stmt|;
comment|/* user ID of the file's owner */
name|u_int16_t
name|st_gid
decl_stmt|;
comment|/* group ID of the file's group */
name|u_int16_t
name|st_rdev
decl_stmt|;
comment|/* device type */
name|int32_t
name|st_size
decl_stmt|;
comment|/* file size, in bytes */
name|struct
name|timespec
name|st_atimespec
decl_stmt|;
comment|/* time of last access */
name|struct
name|timespec
name|st_mtimespec
decl_stmt|;
comment|/* time of last data modification */
name|struct
name|timespec
name|st_ctimespec
decl_stmt|;
comment|/* time of last file status change */
name|int32_t
name|st_blksize
decl_stmt|;
comment|/* optimal blocksize for I/O */
name|int32_t
name|st_blocks
decl_stmt|;
comment|/* blocks allocated for file */
name|u_int32_t
name|st_flags
decl_stmt|;
comment|/* user defined flags for file */
name|u_int32_t
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

begin_comment
comment|/* !_POSIX_SOURCE */
end_comment

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
name|mode_t
name|st_mode
decl_stmt|;
comment|/* inode protection mode */
name|nlink_t
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
name|dev_t
name|st_rdev
decl_stmt|;
comment|/* device type */
name|struct
name|timespec
name|st_atimespec
decl_stmt|;
comment|/* time of last access */
name|struct
name|timespec
name|st_mtimespec
decl_stmt|;
comment|/* time of last data modification */
name|struct
name|timespec
name|st_ctimespec
decl_stmt|;
comment|/* time of last file status change */
name|off_t
name|st_size
decl_stmt|;
comment|/* file size, in bytes */
name|quad_t
name|st_blocks
decl_stmt|;
comment|/* blocks allocated for file */
name|u_int32_t
name|st_blksize
decl_stmt|;
comment|/* optimal blocksize for I/O */
name|u_int32_t
name|st_flags
decl_stmt|;
comment|/* user defined flags for file */
name|u_int32_t
name|st_gen
decl_stmt|;
comment|/* file generation number */
name|int32_t
name|st_lspare
decl_stmt|;
name|quad_t
name|st_qspare
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|st_atime
value|st_atimespec.ts_sec
end_define

begin_define
define|#
directive|define
name|st_mtime
value|st_mtimespec.ts_sec
end_define

begin_define
define|#
directive|define
name|st_ctime
value|st_ctimespec.ts_sec
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

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

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

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

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

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
name|S_IFWHT
value|0160000
end_define

begin_comment
comment|/* whiteout */
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

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|((m& 0170000) == 0040000)
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
value|((m& 0170000) == 0020000)
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
value|((m& 0170000) == 0060000)
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
value|((m& 0170000) == 0100000)
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
value|((m& 0170000) == 0100000 || \ 			 (m& 0170000) == 0140000)
end_define

begin_comment
comment|/* fifo or socket */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|m
parameter_list|)
value|((m& 0170000) == 0120000)
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
value|((m& 0170000) == 0100000 || \ 			 (m& 0170000) == 0140000)
end_define

begin_comment
comment|/* fifo or socket */
end_comment

begin_define
define|#
directive|define
name|S_ISWHT
parameter_list|(
name|m
parameter_list|)
value|((m& 0170000) == 0160000)
end_define

begin_comment
comment|/* whiteout */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
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

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|chmod
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|mode_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fstat
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|stat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mkdir
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|mode_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mkfifo
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|mode_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|stat
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
expr|struct
name|stat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|mode_t
name|umask
name|__P
argument_list|(
operator|(
name|mode_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_decl_stmt
name|int
name|chflags
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fchflags
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fchmod
name|__P
argument_list|(
operator|(
name|int
operator|,
name|mode_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lstat
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
expr|struct
name|stat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_STAT_H_ */
end_comment

end_unit

