begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)cache.h	7.4 (Berkeley) %G%  *  * from: $Header: cache.h,v 1.7 93/04/27 14:31:16 torek Exp $  */
end_comment

begin_comment
comment|/*  * Sun-4 and Sun-4c virtual address cache.  *  * Sun-4 virtual caches come in two flavors, write-through (Sun-4c)  * and write-back (Sun-4).  The write-back caches are much faster  * but require a bit more care.  *  * VAC_NONE is not actually used now, but if someone builds a physical  * cache Sun-4 (or, more likely, a virtual index/physical tag cache)  * everything will work (after pulling out the #ifdef notdef's: grep  * for VAC_NONE to find them).  */
end_comment

begin_enum
enum|enum
name|vactype
block|{
name|VAC_NONE
block|,
name|VAC_WRITETHROUGH
block|,
name|VAC_WRITEBACK
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|vactype
name|vactype
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX  move into cacheinfo struct */
end_comment

begin_comment
comment|/*  * Cache tags can be written in control space, and must be set to 0  * (or invalid anyway) before turning on the cache.  The tags are  * addressed as an array of 32-bit structures of the form:  *  *	struct cache_tag {  *		u_int	:7,		(unused; must be zero)  *			ct_cid:3,	(context ID)  *			ct_w:1,		(write flag from PTE)  *			ct_s:1,		(supervisor flag from PTE)  *			ct_v:1,		(set => cache entry is valid)  *			:3,		(unused; must be zero)  *			ct_tid:14,	(cache tag ID)  *			:2;		(unused; must be zero)  *	};  *  * The SPARCstation 1 cache sees virtual addresses as:  *  *	struct cache_va {  *		u_int	:2,		(unused; probably copies of va_tid<13>)  *			cva_tid:14,	(tag ID)  *			cva_line:12,	(cache line number)  *			cva_byte:4;	(byte in cache line)  *	};  *  * (The SS2 cache is similar but has half as many lines, each twice as long.)  *  * Note that, because the 12-bit line ID is `wider' than the page offset,  * it is possible to have one page map to two different cache lines.  * This can happen whenever two different physical pages have the same bits  * in the part of the virtual address that overlaps the cache line ID, i.e.,  * bits<15:12>.  In order to prevent cache duplication, we have to  * make sure that no one page has more than one virtual address where  * (va1& 0xf000) != (va2& 0xf000).  (The cache hardware turns off ct_v  * when a cache miss occurs on a write, i.e., if va1 is in the cache and  * va2 is not, and you write to va2, va1 goes out of the cache.  If va1  * is in the cache and va2 is not, reading va2 also causes va1 to become  * uncached, and the [same] data is then read from main memory into the  * cache.)  *  * The other alternative, of course, is to disable caching of aliased  * pages.  (In a few cases this might be faster anyway, but we do it  * only when forced.)  *  * THE CURRENT VM CODE DOES NOT ALLOW US TO SPECIFY PREFERRED VIRTUAL  * ADDRESSES ... THIS MUST BE FIXED!  */
end_comment

begin_define
define|#
directive|define
name|CACHE_ALIAS_DISTANCE
value|(256 * 1024)
end_define

begin_comment
comment|/* 256 kbytes */
end_comment

begin_comment
comment|/*  * True iff a1 and a2 are `bad' aliases (will cause cache duplication).  */
end_comment

begin_define
define|#
directive|define
name|BADALIAS
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|(((int)(a1) ^ (int)(a2))& 0xf000)
end_define

begin_comment
comment|/*  * Routines for dealing with the cache.  */
end_comment

begin_decl_stmt
name|void
name|cache_enable
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* turn it on */
end_comment

begin_decl_stmt
name|void
name|cache_flush_context
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flush current context */
end_comment

begin_decl_stmt
name|void
name|cache_flush_segment
name|__P
argument_list|(
operator|(
name|int
name|vseg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flush seg in cur ctx */
end_comment

begin_decl_stmt
name|void
name|cache_flush_page
name|__P
argument_list|(
operator|(
name|int
name|va
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flush page in cur ctx */
end_comment

begin_decl_stmt
name|void
name|cache_flush
name|__P
argument_list|(
operator|(
name|caddr_t
name|base
operator|,
name|u_int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flush region */
end_comment

begin_comment
comment|/*  * Cache control information.  */
end_comment

begin_struct
struct|struct
name|cacheinfo
block|{
name|int
name|c_totalsize
decl_stmt|;
comment|/* total size, in bytes */
name|int
name|c_enabled
decl_stmt|;
comment|/* true => cache is enabled */
name|int
name|c_hwflush
decl_stmt|;
comment|/* true => have hardware flush */
name|int
name|c_linesize
decl_stmt|;
comment|/* line size, in bytes */
name|int
name|c_l2linesize
decl_stmt|;
comment|/* log2(linesize) */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|cacheinfo
name|cacheinfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Cache control statistics.  */
end_comment

begin_struct
struct|struct
name|cachestats
block|{
name|int
name|cs_npgflush
decl_stmt|;
comment|/* # page flushes */
name|int
name|cs_nsgflush
decl_stmt|;
comment|/* # seg flushes */
name|int
name|cs_ncxflush
decl_stmt|;
comment|/* # context flushes */
name|int
name|cs_nraflush
decl_stmt|;
comment|/* # range flushes */
ifdef|#
directive|ifdef
name|notyet
name|int
name|cs_ra
index|[
literal|65
index|]
decl_stmt|;
comment|/* pages/range */
endif|#
directive|endif
block|}
struct|;
end_struct

end_unit

