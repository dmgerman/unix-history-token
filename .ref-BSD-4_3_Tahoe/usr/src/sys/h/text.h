begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)text.h	7.2 (Berkeley) 10/13/86  */
end_comment

begin_comment
comment|/*  * Text structure.  * One allocated per pure  * procedure on swap device.  * Manipulated by text.c  */
end_comment

begin_define
define|#
directive|define
name|NXDAD
value|12
end_define

begin_comment
comment|/* param.h:MAXTSIZ / vmparam.h:DMTEXT */
end_comment

begin_struct
struct|struct
name|text
block|{
name|struct
name|text
modifier|*
name|x_forw
decl_stmt|;
comment|/* forward link in free list */
name|struct
name|text
modifier|*
modifier|*
name|x_back
decl_stmt|;
comment|/* backward link in free list */
name|swblk_t
name|x_daddr
index|[
name|NXDAD
index|]
decl_stmt|;
comment|/* disk addresses of dmtext-page segments */
name|swblk_t
name|x_ptdaddr
decl_stmt|;
comment|/* disk address of page table */
name|size_t
name|x_size
decl_stmt|;
comment|/* size (clicks) */
name|struct
name|proc
modifier|*
name|x_caddr
decl_stmt|;
comment|/* ptr to linked proc, if loaded */
name|struct
name|inode
modifier|*
name|x_iptr
decl_stmt|;
comment|/* inode of prototype */
name|short
name|x_rssize
decl_stmt|;
name|short
name|x_swrss
decl_stmt|;
name|short
name|x_count
decl_stmt|;
comment|/* reference count */
name|short
name|x_ccount
decl_stmt|;
comment|/* number of loaded references */
name|char
name|x_flag
decl_stmt|;
comment|/* traced, written flags */
name|char
name|x_slptime
decl_stmt|;
name|short
name|x_poip
decl_stmt|;
comment|/* page out in progress count */
if|#
directive|if
name|defined
argument_list|(
name|tahoe
argument_list|)
name|short
name|x_ckey
decl_stmt|;
comment|/* code cache key */
endif|#
directive|endif
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
name|text
modifier|*
name|text
decl_stmt|,
modifier|*
name|textNTEXT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ntext
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XTRC
value|0x01
end_define

begin_comment
comment|/* Text may be written, exclusive use */
end_comment

begin_define
define|#
directive|define
name|XWRIT
value|0x02
end_define

begin_comment
comment|/* Text written into, must swap out */
end_comment

begin_define
define|#
directive|define
name|XLOAD
value|0x04
end_define

begin_comment
comment|/* Currently being read from file */
end_comment

begin_define
define|#
directive|define
name|XLOCK
value|0x08
end_define

begin_comment
comment|/* Being swapped in or out */
end_comment

begin_define
define|#
directive|define
name|XWANT
value|0x10
end_define

begin_comment
comment|/* Wanted for swapping */
end_comment

begin_define
define|#
directive|define
name|XPAGI
value|0x20
end_define

begin_comment
comment|/* Page in on demand from inode */
end_comment

begin_define
define|#
directive|define
name|XUNUSED
value|0x40
end_define

begin_comment
comment|/* unused since swapped out for cache */
end_comment

begin_comment
comment|/*  * Text table statistics  */
end_comment

begin_struct
struct|struct
name|xstats
block|{
name|u_long
name|alloc
decl_stmt|;
comment|/* calls to xalloc */
name|u_long
name|alloc_inuse
decl_stmt|;
comment|/*	found in use/sticky */
name|u_long
name|alloc_cachehit
decl_stmt|;
comment|/*	found in cache */
name|u_long
name|alloc_cacheflush
decl_stmt|;
comment|/*	flushed cached text */
name|u_long
name|alloc_unused
decl_stmt|;
comment|/*	flushed unused cached text */
name|u_long
name|free
decl_stmt|;
comment|/* calls to xfree */
name|u_long
name|free_inuse
decl_stmt|;
comment|/*	still in use/sticky */
name|u_long
name|free_cache
decl_stmt|;
comment|/*	placed in cache */
name|u_long
name|free_cacheswap
decl_stmt|;
comment|/*	swapped out to place in cache */
block|}
struct|;
end_struct

end_unit

