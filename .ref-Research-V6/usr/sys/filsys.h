begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Definition of the unix super block.  * The root super block is allocated and  * read in iinit/alloc.c. Subsequently  * a super block is allocated and read  * with each mount (smount/sys3.c) and  * released with unmount (sumount/sys3.c).  * A disk block is ripped off for storage.  * See alloc.c for general alloc/free  * routines for free list and I list.  */
end_comment

begin_struct
struct|struct
name|filsys
block|{
name|int
name|s_isize
decl_stmt|;
comment|/* size in blocks of I list */
name|int
name|s_fsize
decl_stmt|;
comment|/* size in blocks of entire volume */
name|int
name|s_nfree
decl_stmt|;
comment|/* number of in core free blocks (0-100) */
name|int
name|s_free
index|[
literal|100
index|]
decl_stmt|;
comment|/* in core free blocks */
name|int
name|s_ninode
decl_stmt|;
comment|/* number of in core I nodes (0-100) */
name|int
name|s_inode
index|[
literal|100
index|]
decl_stmt|;
comment|/* in core free I nodes */
name|char
name|s_flock
decl_stmt|;
comment|/* lock during free list manipulation */
name|char
name|s_ilock
decl_stmt|;
comment|/* lock during I list manipulation */
name|char
name|s_fmod
decl_stmt|;
comment|/* super block modified flag */
name|char
name|s_ronly
decl_stmt|;
comment|/* mounted read-only flag */
name|int
name|s_time
index|[
literal|2
index|]
decl_stmt|;
comment|/* current date of last update */
name|int
name|pad
index|[
literal|50
index|]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

