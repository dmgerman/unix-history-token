begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)cmap.h	7.5 (Berkeley) 6/28/90  */
end_comment

begin_comment
comment|/*  * core map entry  *  * Limits imposed by this structure:  *  *		limit		     cur. size		fields  *	Physical memory*		64K/256K*CLSIZE	c_next, c_prev, c_hlink  *	Mounted filesystems		255		c_mdev  *	size of a process segment	1 Gb		c_page  *	filesystem size			8 Gb		c_blkno  *	proc, text table size		64K/16K		c_ndx  *  *	* memory is configured for up to 64K clusters (64Mb with 1K clusters)  *	using u_short cmap indices, or up to 256K clusters (256Mb) if MAXMEM  *	is defined in the configuration file to a value larger than  *	64K*CLSIZE.  This definition reduces the max proc/text table size  *	to 16K entries.  *  *	UNTESTED with MAXMEM> 64Mb  */
end_comment

begin_define
define|#
directive|define
name|MAXMEM_SHORT
value|64*1024*CLSIZE
end_define

begin_comment
comment|/* maximum memory for short indices */
end_comment

begin_define
define|#
directive|define
name|MAXMEM_18
value|256*1024*CLSIZE
end_define

begin_comment
comment|/* maximum memory for 18-bit indices */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXMEM
end_ifndef

begin_define
define|#
directive|define
name|MAXMEM
value|MAXMEM_SHORT
end_define

begin_comment
comment|/* maximum memory, in pages */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|MAXMEM
operator|>
name|MAXMEM_18
end_if

begin_undef
undef|#
directive|undef
name|MAXMEM
end_undef

begin_define
define|#
directive|define
name|MAXMEM
value|MAXMEM_18
end_define

begin_comment
comment|/* maximum memory, in pages */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_struct
struct|struct
name|cmap
block|{
if|#
directive|if
name|MAXMEM
operator|<=
name|MAXMEM_SHORT
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
else|#
directive|else
comment|/* MAXMEM */
name|unsigned
name|long
name|c_hlink
decl_stmt|,
comment|/* hash link for<blkno,mdev> */
name|c_next
decl_stmt|;
comment|/* index of next free list entry */
name|unsigned
name|int
name|c_prev
range|:
literal|18
decl_stmt|,
comment|/* index of previous free list entry */
name|c_ndx
range|:
literal|14
decl_stmt|;
comment|/* index of owner proc or text */
endif|#
directive|endif
comment|/* MAXMEM */
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
decl_stmt|;
comment|/* to longword boundary */
name|daddr_t
name|c_blkno
decl_stmt|;
comment|/* disk block this is a copy of */
name|struct
name|vnode
modifier|*
name|c_vp
decl_stmt|;
comment|/* vnode to which c_blkno refers */
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

begin_if
if|#
directive|if
name|MAXMEM
operator|<=
name|MAXMEM_SHORT
end_if

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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|C_INTRANS
value|119
end_define

begin_define
define|#
directive|define
name|C_FREE
value|120
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*  * Shared text pages are not totally abandoned when a process  * exits, but are remembered while in the free list hashed by<vp,blkno>  * off the cmhash structure so that they can be reattached  * if another instance of the program runs again soon.  */
end_comment

begin_if
if|#
directive|if
name|MAXMEM
operator|<=
name|MAXMEM_SHORT
end_if

begin_define
define|#
directive|define
name|CMHSIZ
value|2048
end_define

begin_comment
comment|/* SHOULD BE DYNAMIC */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CMHSIZ
value|(16*1024)
end_define

begin_comment
comment|/* SHOULD BE DYNAMIC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
name|u_long
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

