begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)dmap.h	8.2 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DMAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DMAP_H_
end_define

begin_comment
comment|/*  * Definitions for the mapping of vitual swap space to the physical swap  * area - the disk map.  */
end_comment

begin_define
define|#
directive|define
name|NDMAP
value|38
end_define

begin_comment
comment|/* size of the swap area map */
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

begin_decl_stmt
name|int
name|dmmin
decl_stmt|,
name|dmmax
decl_stmt|,
name|dmtext
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The following structure is that ``returned'' from a call to vstodb(). */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_DMAP_H_ */
end_comment

end_unit

