begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** sys/stat.h ** ** Emulation of the Unix sys/stat.h header file for PRIMOS ** ** Author: Peter Eriksson<pen@lysator.liu.se> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SYS_STAT_H__
end_ifndef

begin_define
define|#
directive|define
name|__SYS_STAT_H__
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_struct
struct|struct
name|stat
block|{
comment|/* First some PRIMOS standard entries */
name|off_t
name|st_size
decl_stmt|;
name|time_t
name|st_mtime
decl_stmt|;
name|short
name|st_type
decl_stmt|;
comment|/* Primos file type */
name|short
name|st_rwlock
decl_stmt|;
comment|/* Primos read/write lock */
comment|/* Begin Unix compatibility - don't believe these entries! */
name|dev_t
name|st_dev
decl_stmt|;
name|ino_t
name|st_ino
decl_stmt|;
name|mode_t
name|st_mode
decl_stmt|;
name|short
name|st_nlink
decl_stmt|;
name|uid_t
name|st_uid
decl_stmt|;
name|gid_t
name|st_gid
decl_stmt|;
name|dev_t
name|st_rdev
decl_stmt|;
name|time_t
name|st_atime
decl_stmt|;
name|time_t
name|st_ctime
decl_stmt|;
name|long
name|st_blksize
decl_stmt|;
name|long
name|st_blocks
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|_IFMT
value|0170000
end_define

begin_comment
comment|/* type of file */
end_comment

begin_define
define|#
directive|define
name|_IFREG
value|0100000
end_define

begin_comment
comment|/* regular */
end_comment

begin_define
define|#
directive|define
name|_IFDIR
value|0040000
end_define

begin_comment
comment|/* directory */
end_comment

begin_comment
comment|/* Some stupid programs check if these are defined and then    believe these are supported in the OS - not so in PRIMOS ... */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__50SERIES
end_ifndef

begin_define
define|#
directive|define
name|_IFCHR
value|0020000
end_define

begin_define
define|#
directive|define
name|_IFBLK
value|0060000
end_define

begin_define
define|#
directive|define
name|_IFLNK
value|0120000
end_define

begin_define
define|#
directive|define
name|_IFSOCK
value|0140000
end_define

begin_define
define|#
directive|define
name|_IFIFO
value|0010000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|S_ISUID
value|0004000
end_define

begin_define
define|#
directive|define
name|S_ISGID
value|0002000
end_define

begin_define
define|#
directive|define
name|S_ISVTX
value|0001000
end_define

begin_define
define|#
directive|define
name|S_IREAD
value|0000400
end_define

begin_define
define|#
directive|define
name|S_IWRITE
value|0000200
end_define

begin_define
define|#
directive|define
name|S_IEXEC
value|0000100
end_define

begin_define
define|#
directive|define
name|S_ENFMT
value|0002000
end_define

begin_define
define|#
directive|define
name|S_IFMT
value|_IFMT
end_define

begin_define
define|#
directive|define
name|S_IFREG
value|_IFREG
end_define

begin_define
define|#
directive|define
name|S_IFDIR
value|_IFDIR
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__50SERIES
end_ifndef

begin_define
define|#
directive|define
name|S_IFCHR
value|_IFCHR
end_define

begin_define
define|#
directive|define
name|S_IFBLK
value|_IFBLK
end_define

begin_define
define|#
directive|define
name|S_IFLNK
value|_IFLNK
end_define

begin_define
define|#
directive|define
name|S_IFSOCK
value|_IFSOCK
end_define

begin_define
define|#
directive|define
name|S_IFIFO
value|_IFIFO
end_define

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

begin_define
define|#
directive|define
name|S_IRUSR
value|0000400
end_define

begin_define
define|#
directive|define
name|S_IWUSR
value|0000200
end_define

begin_define
define|#
directive|define
name|S_IXUSR
value|0000100
end_define

begin_define
define|#
directive|define
name|S_IRWXG
value|0000070
end_define

begin_define
define|#
directive|define
name|S_IRGRP
value|0000040
end_define

begin_define
define|#
directive|define
name|S_IWGRP
value|0000020
end_define

begin_define
define|#
directive|define
name|S_IXGRP
value|0000010
end_define

begin_define
define|#
directive|define
name|S_IRWXO
value|0000007
end_define

begin_define
define|#
directive|define
name|S_IROTH
value|0000004
end_define

begin_define
define|#
directive|define
name|S_IWOTH
value|0000002
end_define

begin_define
define|#
directive|define
name|S_IXOTH
value|0000001
end_define

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|m
parameter_list|)
value|(((m)& _IFMT) == _IFREG)
end_define

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|(((m)& _IFMT) == _IFDIR)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__50SERIES
end_ifndef

begin_define
define|#
directive|define
name|S_ISBLK
parameter_list|(
name|m
parameter_list|)
value|(((m)& _IFMT) == _IFBLK)
end_define

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|m
parameter_list|)
value|(((m)& _IFMT) == _IFCHR)
end_define

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|m
parameter_list|)
value|(((m)& _IFMT) == _IFIFO)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

