begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)text.h	7.7 (Berkeley) 6/28/90  */
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
name|segsz_t
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
name|vnode
modifier|*
name|x_vptr
decl_stmt|;
comment|/* vnode of prototype */
name|time_t
name|x_mtime
decl_stmt|;
comment|/* last time modified */
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
name|XPAGV
value|0x20
end_define

begin_comment
comment|/* Page in on demand from vnode */
end_comment

begin_define
define|#
directive|define
name|XUNUSED
value|0x40
end_define

begin_comment
comment|/* Unused since swapped out for cache */
end_comment

begin_define
define|#
directive|define
name|XCACHED
value|0x80
end_define

begin_comment
comment|/* Cached but not sticky */
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
name|u_long
name|purge
decl_stmt|;
comment|/* calls to xpurge */
block|}
struct|;
end_struct

end_unit

