begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)cmap.h	7.1 (Berkeley) 6/4/86  */
end_comment

begin_comment
comment|/*  * core map entry  *  * Limits imposed by this structure:  *  *		limit		     cur. size		fields  *	Physical memory*		64 Mb	c_next, c_prev, c_hlink  *	Mounted filesystems		255	c_mdev  *	size of a process segment	1 Gb	c_page  *	filesystem size			8 Gb	c_blkno  *	proc, text table size		64K	c_ndx  *  *	* memory can be expanded by converting first three entries  *	to bit fields of larger than 16 bits, shrinking c_ndx accordingly,  *	and increasing MAXMEM below.  Also, the type of cmhash  *	(below) must be changed to long.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_struct
struct|struct
name|cmap
block|{
name|unsigned
name|short
name|c_next
decl_stmt|,
comment|/* index of next free list entry */
name|c_prev
decl_stmt|,
comment|/* index of previous free list entry */
name|c_hlink
decl_stmt|;
comment|/* hash link for<blkno,mdev> */
name|unsigned
name|short
name|c_ndx
decl_stmt|;
comment|/* index of owner proc or text */
name|unsigned
name|int
name|c_page
range|:
literal|21
decl_stmt|,
comment|/* virtual page number in segment */
name|c_lock
range|:
literal|1
decl_stmt|,
comment|/* locked for raw i/o or pagein */
name|c_want
range|:
literal|1
decl_stmt|,
comment|/* wanted */
name|c_intrans
range|:
literal|1
decl_stmt|,
comment|/* intransit bit */
name|c_free
range|:
literal|1
decl_stmt|,
comment|/* on the free list */
name|c_gone
range|:
literal|1
decl_stmt|,
comment|/* associated page has been released */
name|c_type
range|:
literal|2
decl_stmt|,
comment|/* type CSYS or CTEXT or CSTACK or CDATA */
range|:
literal|4
decl_stmt|,
comment|/* to longword boundary */
name|c_blkno
range|:
literal|24
decl_stmt|,
comment|/* disk block this is a copy of */
name|c_mdev
range|:
literal|8
decl_stmt|;
comment|/* which mounted dev this is from */
block|}
struct|;
end_struct

begin_else
else|#
directive|else
else|LOCORE
end_else

begin_comment
comment|/*  * bit offsets of elements in cmap  */
end_comment

begin_define
define|#
directive|define
name|C_INTRANS
value|87
end_define

begin_define
define|#
directive|define
name|C_FREE
value|88
end_define

begin_define
define|#
directive|define
name|SZ_CMAP
value|16
end_define

begin_comment
comment|/* sizeof(struct cmap) */
end_comment

begin_define
define|#
directive|define
name|MAXMEM
value|64*1024
end_define

begin_comment
comment|/* maximum memory, in Kbytes */
end_comment

begin_endif
endif|#
directive|endif
endif|LOCORE
end_endif

begin_define
define|#
directive|define
name|CMHEAD
value|0
end_define

begin_comment
comment|/*  * Shared text pages are not totally abandoned when a process  * exits, but are remembered while in the free list hashed by<mdev,blkno>  * off the cmhash structure so that they can be reattached  * if another instance of the program runs again soon.  */
end_comment

begin_define
define|#
directive|define
name|CMHSIZ
value|2048
end_define

begin_comment
comment|/* SHOULD BE DYNAMIC */
end_comment

begin_define
define|#
directive|define
name|CMHASH
parameter_list|(
name|bn
parameter_list|)
value|((bn)&(CMHSIZ-1))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|cmap
modifier|*
name|cmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cmap
modifier|*
name|ecmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ncmap
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|cmap
modifier|*
name|mfind
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|firstfree
decl_stmt|,
name|maxfree
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ecmx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cmap index of ecmap */
end_comment

begin_decl_stmt
name|u_short
name|cmhash
index|[
name|CMHSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* bits defined in c_type */
end_comment

begin_define
define|#
directive|define
name|CSYS
value|0
end_define

begin_comment
comment|/* none of below */
end_comment

begin_define
define|#
directive|define
name|CTEXT
value|1
end_define

begin_comment
comment|/* belongs to shared text segment */
end_comment

begin_define
define|#
directive|define
name|CDATA
value|2
end_define

begin_comment
comment|/* belongs to data segment */
end_comment

begin_define
define|#
directive|define
name|CSTACK
value|3
end_define

begin_comment
comment|/* belongs to stack segment */
end_comment

begin_define
define|#
directive|define
name|pgtocm
parameter_list|(
name|x
parameter_list|)
value|(((int) ((x)-firstfree) / CLSIZE) + 1)
end_define

begin_define
define|#
directive|define
name|cmtopg
parameter_list|(
name|x
parameter_list|)
value|((((x)-1) * CLSIZE) + firstfree)
end_define

begin_endif
endif|#
directive|endif
endif|LOCORE
end_endif

end_unit

