begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)stat.h	7.3 (Berkeley) %G%  */
end_comment

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
name|unsigned
name|short
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
name|u_long
name|st_flags
decl_stmt|;
name|u_long
name|st_gen
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

begin_comment
comment|/* type of file */
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
name|S_IFCHR
value|0020000
end_define

begin_comment
comment|/* character special */
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
name|S_IREAD
value|0000400
end_define

begin_comment
comment|/* read permission, owner */
end_comment

begin_define
define|#
directive|define
name|S_IWRITE
value|0000200
end_define

begin_comment
comment|/* write permission, owner */
end_comment

begin_define
define|#
directive|define
name|S_IEXEC
value|0000100
end_define

begin_comment
comment|/* execute/search permission, owner */
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

end_unit

