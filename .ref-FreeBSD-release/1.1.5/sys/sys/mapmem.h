begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: Utah $Hdr: mmap.h 1.4 89/08/14$  *	from: @(#)mapmem.h	7.2 (Berkeley) 6/6/90  *	$Id: mapmem.h,v 1.2 1993/10/16 17:17:06 rgrimes Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_MAPMEM_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_MAPMEM_H_
value|1
end_define

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
value|(mp) = (struct mapmem *)malloc((u_long)sizeof(struct mapmem), \ 	    M_MAPMEM, M_WAITOK)
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_MAPMEM_H_ */
end_comment

end_unit

