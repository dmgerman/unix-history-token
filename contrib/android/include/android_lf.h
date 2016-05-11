begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Macros for file64 functions  *  * Android does not support the macro _FILE_OFFSET_BITS=64  * As of android-21 it does however support many file64 functions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARCHIVE_ANDROID_LF_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_ANDROID_LF_H_INCLUDED
end_define

begin_if
if|#
directive|if
name|__ANDROID_API__
operator|>
literal|20
end_if

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/statvfs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/vfs.h>
end_include

begin_comment
comment|//dirent.h
end_comment

begin_define
define|#
directive|define
name|readdir_r
value|readdir64_r
end_define

begin_define
define|#
directive|define
name|readdir
value|readdir64
end_define

begin_define
define|#
directive|define
name|dirent
value|dirent64
end_define

begin_comment
comment|//fcntl.h
end_comment

begin_define
define|#
directive|define
name|openat
value|openat64
end_define

begin_define
define|#
directive|define
name|open
value|open64
end_define

begin_define
define|#
directive|define
name|mkstemp
value|mkstemp64
end_define

begin_comment
comment|//unistd.h
end_comment

begin_define
define|#
directive|define
name|lseek
value|lseek64
end_define

begin_define
define|#
directive|define
name|ftruncate
value|ftruncate64
end_define

begin_comment
comment|//sys/stat.h
end_comment

begin_define
define|#
directive|define
name|fstatat
value|fstatat64
end_define

begin_define
define|#
directive|define
name|fstat
value|fstat64
end_define

begin_define
define|#
directive|define
name|lstat
value|lstat64
end_define

begin_define
define|#
directive|define
name|stat
value|stat64
end_define

begin_comment
comment|//sys/statvfs.h
end_comment

begin_define
define|#
directive|define
name|fstatvfs
value|fstatvfs64
end_define

begin_define
define|#
directive|define
name|statvfs
value|statvfs64
end_define

begin_comment
comment|//sys/types.h
end_comment

begin_define
define|#
directive|define
name|off_t
value|off64_t
end_define

begin_comment
comment|//sys/vfs.h
end_comment

begin_define
define|#
directive|define
name|fstatfs
value|fstatfs64
end_define

begin_define
define|#
directive|define
name|statfs
value|statfs64
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
comment|/* ARCHIVE_ANDROID_LF_H_INCLUDED */
end_comment

end_unit

