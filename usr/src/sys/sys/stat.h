begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)stat.h	7.6 (Berkeley) %G%  */
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
name|off_t
name|st_size
decl_stmt|;
comment|/* file size, in bytes */
name|time_t
name|st_atime
decl_stmt|;
comment|/* time of last access */
name|long
name|st_spare1
decl_stmt|;
name|time_t
name|st_mtime
decl_stmt|;
comment|/* time of last data modification */
name|long
name|st_spare2
decl_stmt|;
name|time_t
name|st_ctime
decl_stmt|;
comment|/* time of last file status change */
name|long
name|st_spare3
decl_stmt|;
name|long
name|st_blksize
decl_stmt|;
comment|/* optimal blocksize for I/O */
name|long
name|st_blocks
decl_stmt|;
comment|/* blocks allocated for file */
name|u_long
name|st_flags
decl_stmt|;
comment|/* user defined flags for file */
name|u_long
name|st_gen
decl_stmt|;
comment|/* file generation number */
block|}
struct|;
end_struct

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
comment|/* type of file */
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

begin_define
define|#
directive|define
name|S_BLKSIZE
value|512
end_define

begin_comment
comment|/* block size used in the stat struct */
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
value|((m& 0170000) == 0010000)
end_define

begin_comment
comment|/* fifo */
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
value|((m& 0170000) == 0140000)
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
name|__STDC__
operator|||
name|c_plusplus
end_if

begin_function_decl
name|mode_t
name|umask
parameter_list|(
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|int
name|stat
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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

begin_else
else|#
directive|else
end_else

begin_function_decl
name|mode_t
name|umask
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mkdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mkfifo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fstat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chmod
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

