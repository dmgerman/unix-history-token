begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Inode structure as it appears on a disk block. */
end_comment

begin_struct
struct|struct
name|dinode
block|{
name|unsigned
name|short
name|di_mode
decl_stmt|;
comment|/* mode and type of file */
name|short
name|di_nlink
decl_stmt|;
comment|/* number of links to file */
name|short
name|di_uid
decl_stmt|;
comment|/* owner's user id */
name|short
name|di_gid
decl_stmt|;
comment|/* owner's group id */
name|off_t
name|di_size
decl_stmt|;
comment|/* number of bytes in file */
name|char
name|di_addr
index|[
literal|40
index|]
decl_stmt|;
comment|/* disk block addresses */
name|time_t
name|di_atime
decl_stmt|;
comment|/* time last accessed */
name|time_t
name|di_mtime
decl_stmt|;
comment|/* time last modified */
name|time_t
name|di_ctime
decl_stmt|;
comment|/* time created */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|INOPB
value|8
end_define

begin_comment
comment|/* 8 inodes per block */
end_comment

begin_comment
comment|/*  * the 40 address bytes:  *	39 used; 13 addresses  *	of 3 bytes each.  */
end_comment

end_unit

