begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	dmap.h	4.1	11/9/80	*/
end_comment

begin_comment
comment|/*  * Definitions for the mapping of vitual swap  * space to the physical swap area - the disk map.  */
end_comment

begin_define
define|#
directive|define
name|NDMAP
value|16
end_define

begin_comment
comment|/* size of the swap area map */
end_comment

begin_define
define|#
directive|define
name|DMMIN
value|16
end_define

begin_comment
comment|/* the initial block size in clicks */
end_comment

begin_define
define|#
directive|define
name|DMMAX
value|1024
end_define

begin_comment
comment|/* max block size alloc on drum = .5M byte */
end_comment

begin_define
define|#
directive|define
name|DMTEXT
value|1024
end_define

begin_comment
comment|/* size of blocks of pure text = .5M byte */
end_comment

begin_struct
struct|struct
name|dmap
block|{
name|swblk_t
name|dm_size
decl_stmt|;
comment|/* current size used by process */
name|swblk_t
name|dm_alloc
decl_stmt|;
comment|/* amount of physical swap space allocated */
name|swblk_t
name|dm_map
index|[
name|NDMAP
index|]
decl_stmt|;
comment|/* first disk block number in each chunk */
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
name|dmap
name|zdmap
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The following structure is that ``returned''  * from a call to vstodb().  */
end_comment

begin_struct
struct|struct
name|dblock
block|{
name|swblk_t
name|db_base
decl_stmt|;
comment|/* base of physical contig drum block */
name|swblk_t
name|db_size
decl_stmt|;
comment|/* size of block */
block|}
struct|;
end_struct

end_unit

