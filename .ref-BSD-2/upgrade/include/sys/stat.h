begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
name|int
name|st_mode
decl_stmt|;
name|int
name|st_nlink
decl_stmt|;
name|int
name|st_uid
decl_stmt|;
name|int
name|st_gid
decl_stmt|;
name|dev_t
name|st_rdev
decl_stmt|;
name|off_t
name|st_size
decl_stmt|;
name|time_t
name|st_atime
decl_stmt|;
name|time_t
name|st_mtime
decl_stmt|;
name|time_t
name|st_ctime
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_IFMT
value|0170000
end_define

begin_define
define|#
directive|define
name|S_IFDIR
value|0040000
end_define

begin_define
define|#
directive|define
name|S_IFCHR
value|0020000
end_define

begin_define
define|#
directive|define
name|S_IFBLK
value|0060000
end_define

begin_define
define|#
directive|define
name|S_IFREG
value|0100000
end_define

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

end_unit

