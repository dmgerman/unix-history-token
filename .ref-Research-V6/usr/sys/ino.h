begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Inode structure as it appears on  * the disk. Not used by the system,  * but by things like check, df, dump.  */
end_comment

begin_struct
struct|struct
name|inode
block|{
name|int
name|i_mode
decl_stmt|;
name|char
name|i_nlink
decl_stmt|;
name|char
name|i_uid
decl_stmt|;
name|char
name|i_gid
decl_stmt|;
name|char
name|i_size0
decl_stmt|;
name|char
modifier|*
name|i_size1
decl_stmt|;
name|int
name|i_addr
index|[
literal|8
index|]
decl_stmt|;
name|int
name|i_atime
index|[
literal|2
index|]
decl_stmt|;
name|int
name|i_mtime
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* modes */
end_comment

begin_define
define|#
directive|define
name|IALLOC
value|0100000
end_define

begin_define
define|#
directive|define
name|IFMT
value|060000
end_define

begin_define
define|#
directive|define
name|IFDIR
value|040000
end_define

begin_define
define|#
directive|define
name|IFCHR
value|020000
end_define

begin_define
define|#
directive|define
name|IFBLK
value|060000
end_define

begin_define
define|#
directive|define
name|ILARG
value|010000
end_define

begin_define
define|#
directive|define
name|ISUID
value|04000
end_define

begin_define
define|#
directive|define
name|ISGID
value|02000
end_define

begin_define
define|#
directive|define
name|ISVTX
value|01000
end_define

begin_define
define|#
directive|define
name|IREAD
value|0400
end_define

begin_define
define|#
directive|define
name|IWRITE
value|0200
end_define

begin_define
define|#
directive|define
name|IEXEC
value|0100
end_define

end_unit

