begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 University of Utah.  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)swap_pager.h	7.1 (Berkeley) 12/5/90  *	$Id: swap_pager.h,v 1.6 1995/05/10 18:56:04 davidg Exp $  */
end_comment

begin_comment
comment|/*  * Modifications to the block allocation data structure by John S. Dyson  * 18 Dec 93.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SWAP_PAGER_
end_ifndef

begin_define
define|#
directive|define
name|_SWAP_PAGER_
value|1
end_define

begin_comment
comment|/*  * SWB_NPAGES can be set to any value from 1 to 16 pages per allocation,  * however, due to the allocation spilling into non-swap pager backed memory,  * suggest keeping SWB_NPAGES small (1-4).  If high performance is manditory  * perhaps up to 8 pages might be in order????  * Above problem has been fixed, now we support 16 pages per block.  Unused  * space is recovered by the swap pager now...  */
end_comment

begin_define
define|#
directive|define
name|SWB_NPAGES
value|8
end_define

begin_struct
struct|struct
name|swblock
block|{
name|unsigned
name|short
name|swb_valid
decl_stmt|;
comment|/* bitmask for valid pages */
name|unsigned
name|short
name|swb_locked
decl_stmt|;
comment|/* block locked */
name|int
name|swb_block
index|[
name|SWB_NPAGES
index|]
decl_stmt|;
comment|/* unfortunately int instead of daddr_t */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|swblock
modifier|*
name|sw_blk_t
typedef|;
end_typedef

begin_comment
comment|/*  * Swap pager private data.  */
end_comment

begin_struct
struct|struct
name|swpager
block|{
name|int
name|sw_nblocks
decl_stmt|;
comment|/* number of blocks in list (sw_blk_t units) */
name|int
name|sw_allocsize
decl_stmt|;
comment|/* amount of space actually allocated */
name|sw_blk_t
name|sw_blocks
decl_stmt|;
comment|/* pointer to list of swap blocks */
name|short
name|sw_poip
decl_stmt|;
comment|/* pageouts in progress */
name|short
name|sw_piip
decl_stmt|;
comment|/* pageins in progress */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|swpager
modifier|*
name|sw_pager_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|void
name|swap_pager_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_object_t
name|swap_pager_alloc
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|vm_size_t
operator|,
name|vm_prot_t
operator|,
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swap_pager_dealloc
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|swap_pager_getpages
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|,
name|vm_page_t
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|swap_pager_putpages
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|,
name|vm_page_t
operator|*
operator|,
name|int
operator|,
name|boolean_t
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean_t
name|swap_pager_haspage
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|,
name|vm_offset_t
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swap_pager_sync
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swap_pager_iodone
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|swap_pager_swp_alloc
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swap_pager_copy
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|,
name|vm_offset_t
operator|,
name|vm_object_t
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swap_pager_freespace
name|__P
argument_list|(
operator|(
name|vm_object_t
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swap_pager_swap_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SWAP_PAGER_ */
end_comment

end_unit

