begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	ufsmount.h	4.1	%G%	*/
end_comment

begin_comment
comment|/*  * Mount structure.  * One allocated on every mount.  * Used to find the super block.  */
end_comment

begin_struct
struct|struct
name|mount
block|{
name|dev_t
name|m_dev
decl_stmt|;
comment|/* device mounted */
name|struct
name|buf
modifier|*
name|m_bufp
decl_stmt|;
comment|/* pointer to superblock */
name|struct
name|inode
modifier|*
name|m_inodp
decl_stmt|;
comment|/* pointer to mounted on inode */
block|}
name|mount
index|[
name|NMOUNT
index|]
struct|;
end_struct

end_unit

