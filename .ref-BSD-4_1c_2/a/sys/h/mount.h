begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	mount.h	4.4	82/07/19	*/
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
name|struct
name|inode
modifier|*
name|m_qinod
decl_stmt|;
comment|/* QUOTA: pointer to quota file */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|mount
name|mount
index|[
name|NMOUNT
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

