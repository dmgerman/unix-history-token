begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Structure of the super-block  */
end_comment

begin_struct
struct|struct
name|filsys
block|{
name|unsigned
name|short
name|s_isize
decl_stmt|;
comment|/* size in blocks of i-list */
name|daddr_t
name|s_fsize
decl_stmt|;
comment|/* size in blocks of entire volume */
name|short
name|s_nfree
decl_stmt|;
comment|/* number of addresses in s_free */
name|daddr_t
name|s_free
index|[
name|NICFREE
index|]
decl_stmt|;
comment|/* free block list */
name|short
name|s_ninode
decl_stmt|;
comment|/* number of i-nodes in s_inode */
name|ino_t
name|s_inode
index|[
name|NICINOD
index|]
decl_stmt|;
comment|/* free i-node list */
name|char
name|s_flock
decl_stmt|;
comment|/* lock during free list manipulation */
name|char
name|s_ilock
decl_stmt|;
comment|/* lock during i-list manipulation */
name|char
name|s_fmod
decl_stmt|;
comment|/* super block modified flag */
name|char
name|s_ronly
decl_stmt|;
comment|/* mounted read-only flag */
name|time_t
name|s_time
decl_stmt|;
comment|/* last super block update */
comment|/* remainder not maintained by this version of the system */
name|daddr_t
name|s_tfree
decl_stmt|;
comment|/* total free blocks*/
name|ino_t
name|s_tinode
decl_stmt|;
comment|/* total free inodes */
name|short
name|s_m
decl_stmt|;
comment|/* interleave factor */
name|short
name|s_n
decl_stmt|;
comment|/* " " */
name|char
name|s_fname
index|[
literal|6
index|]
decl_stmt|;
comment|/* file system name */
name|char
name|s_fpack
index|[
literal|6
index|]
decl_stmt|;
comment|/* file system pack name */
block|}
struct|;
end_struct

end_unit

