begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Ex - a text editor  * Bill Joy UCB June 1977  */
end_comment

begin_define
define|#
directive|define
name|FILETYP
value|060000
end_define

begin_define
define|#
directive|define
name|FPLAIN
value|000000
end_define

begin_define
define|#
directive|define
name|FDIRECT
value|040000
end_define

begin_define
define|#
directive|define
name|FCHSPEC
value|020000
end_define

begin_define
define|#
directive|define
name|FBLSPEC
value|060000
end_define

begin_struct
struct|struct
name|stb
block|{
name|char
name|minor
decl_stmt|;
name|char
name|major
decl_stmt|;
name|int
name|inumber
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|char
name|nlinks
decl_stmt|;
name|char
name|uid
decl_stmt|;
name|char
name|gid
decl_stmt|;
name|char
name|size0
decl_stmt|;
name|int
name|size1
decl_stmt|;
name|char
name|dminor
decl_stmt|;
name|char
name|dmajor
decl_stmt|;
name|int
name|addr2
index|[
literal|7
index|]
decl_stmt|;
name|long
name|actime
decl_stmt|;
name|long
name|modtime
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ENOENT
value|2
end_define

begin_define
define|#
directive|define
name|EIO
value|5
end_define

begin_define
define|#
directive|define
name|EACCESS
value|13
end_define

begin_define
define|#
directive|define
name|ENOTDIR
value|20
end_define

begin_define
define|#
directive|define
name|EISDIR
value|21
end_define

begin_define
define|#
directive|define
name|ENFILE
value|23
end_define

begin_define
define|#
directive|define
name|ENOSPC
value|28
end_define

begin_define
define|#
directive|define
name|EROFS
value|30
end_define

begin_define
define|#
directive|define
name|EQUOT
value|33
end_define

begin_decl_stmt
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DTTYMAJ
value|3
end_define

begin_define
define|#
directive|define
name|DTTYMIN
value|0
end_define

begin_define
define|#
directive|define
name|DVNLMAJ
value|8
end_define

begin_define
define|#
directive|define
name|DVNLMIN
value|2
end_define

end_unit

