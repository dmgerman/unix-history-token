begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * from: Utah $Hdr: mmap.h 1.4 89/08/14$  *  *	@(#)mapmem.h	7.2 (Berkeley) 6/6/90  */
end_comment

begin_comment
comment|/*  * Mapped memory descriptors.  *  * A process has one of these for every "mapped" memory region.  * Mapped memory is characterized by:  *	- Corresponding physical memory is neither paged nor swapped.  *	- User PTEs have both pg_v and pg_fod set.  *	- Has no backing swap space unless mapped over existing data.  *	- If mapped over existing data, original data is lost when  *	  segment is unmapped. (i.e. pages are reinitialized to ZFOD)  * Operations:  *	(*mm_fork)(mp, ischild) struct mapmem *mp; int ischild;  *		Called during fork in both parent and child.  Parent  *		call can be used for maintaining reference counts and  *		should NEVER destroy the region.  Child call should be  *		used for unmapping regions not inherited across forks.  *	(*mm_vfork)(mp, fup, tup) struct mapmem *mp; struct user *fup, *tup;  *		Called twice during vfork (always in parent context)  *		after exchanging resources (including u_mmap chains).  *		`fup' is the donor and `tup' the recipient of the  *		"parent" (full) context.  Needed for maintaining  *		reference counts or if the underlying object contains  *		references to owning process.  Routine should NEVER  *		destroy the region.  *	(*mm_exec)(mp) struct mapmem *mp;  *		Called during exec before releasing old address space.  *		Used for graceful cleanup of underlying object.  Resources  *		will be freed regardless of what this routine does.  *		Need to add a post-exec call to re-establish mappings  *		in the new address space for regions inherited across execs.  *	(*mm_exit)(mp) struct mapmem *mp;  *		Called during exit just before releasing address space.  *		Used for graceful cleanup of underlying object.  Resources  *		will be freed regardless of what this routine does.  * The default semantics for a region with routine addresses of zero are  * that it is inherited across forks, stays with the "active" process during  * vforks, and is destroyed by execs and exit.  */
end_comment

begin_struct
struct|struct
name|mapmem
block|{
name|struct
name|mapmem
modifier|*
name|mm_next
decl_stmt|;
comment|/* next descriptor */
name|int
name|mm_id
decl_stmt|;
comment|/* identifier (e.g. fd, shmid) */
name|caddr_t
name|mm_uva
decl_stmt|;
comment|/* user VA at which region is mapped */
name|int
name|mm_size
decl_stmt|;
comment|/* size of mapped region */
name|int
name|mm_prot
decl_stmt|;
comment|/* attributes of region */
struct|struct
name|mapmemops
block|{
comment|/* operations */
name|int
function_decl|(
modifier|*
name|mm_fork
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|mm_vfork
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|mm_exec
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|mm_exit
function_decl|)
parameter_list|()
function_decl|;
block|}
modifier|*
name|mm_ops
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MMNIL
value|((struct mapmem *)0)
end_define

begin_comment
comment|/* attributes */
end_comment

begin_define
define|#
directive|define
name|MM_RW
value|0x00
end_define

begin_comment
comment|/* region is read-write */
end_comment

begin_define
define|#
directive|define
name|MM_RO
value|0x01
end_define

begin_comment
comment|/* region is read-only */
end_comment

begin_define
define|#
directive|define
name|MM_CI
value|0x02
end_define

begin_comment
comment|/* caching is inhibited on region */
end_comment

begin_define
define|#
directive|define
name|MM_NOCORE
value|0x04
end_define

begin_comment
comment|/* cannot write region to core file; 				   e.g. mapped framebuffer hardware */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|MMALLOC
parameter_list|(
name|mp
parameter_list|)
define|\
value|(mp) = (struct mapmem *) malloc((u_long)sizeof(struct mapmem), M_MAPMEM, M_WAITOK)
end_define

begin_define
define|#
directive|define
name|MMFREE
parameter_list|(
name|mp
parameter_list|)
define|\
value|free((caddr_t)(mp), M_MAPMEM)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

