begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Imitation sys/stat.h. */
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

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_struct
struct|struct
name|stat
block|{
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
name|off_t
name|st_size
decl_stmt|;
name|off_t
name|st_rsize
decl_stmt|;
name|time_t
name|st_atime
decl_stmt|;
name|int
name|st_spare1
decl_stmt|;
name|time_t
name|st_mtime
decl_stmt|;
name|int
name|st_spare2
decl_stmt|;
name|time_t
name|st_ctime
decl_stmt|;
name|int
name|st_spare3
decl_stmt|;
name|long
name|st_blksize
decl_stmt|;
name|long
name|st_blocks
decl_stmt|;
name|long
name|st_spare4
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
name|S_IFMT
value|0170000L
end_define

begin_define
define|#
directive|define
name|S_IFDIR
value|0040000L
end_define

begin_define
define|#
directive|define
name|S_IFREG
value|0100000L
end_define

begin_define
define|#
directive|define
name|S_IREAD
value|0400
end_define

begin_define
define|#
directive|define
name|S_IWRITE
value|0200
end_define

begin_define
define|#
directive|define
name|S_IEXEC
value|0100
end_define

begin_define
define|#
directive|define
name|S_IFIFO
value|010000
end_define

begin_comment
comment|/* FIFO special */
end_comment

begin_define
define|#
directive|define
name|S_IFCHR
value|020000
end_define

begin_comment
comment|/* character special */
end_comment

begin_define
define|#
directive|define
name|S_IFBLK
value|030000
end_define

begin_comment
comment|/* block special */
end_comment

begin_function_decl
name|int
name|stat
parameter_list|(
name|char
modifier|*
name|path
parameter_list|,
name|struct
name|stat
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fstat
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|stat
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SYS_STAT_H___ */
end_comment

end_unit

