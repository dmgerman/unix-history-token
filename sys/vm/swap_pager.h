begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 University of Utah.  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)swap_pager.h	7.1 (Berkeley) 12/5/90  * $FreeBSD$  */
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
name|vm_size_t
name|sw_osize
decl_stmt|;
comment|/* size of object we are backing (bytes) */
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
name|sw_flags
decl_stmt|;
comment|/* flags */
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

begin_define
define|#
directive|define
name|SW_WANTED
value|0x01
end_define

begin_define
define|#
directive|define
name|SW_NAMED
value|0x02
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|void
name|swap_pager_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_pager_t
name|swap_pager_alloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|vm_size_t
parameter_list|,
name|vm_prot_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|swap_pager_dealloc
parameter_list|(
name|vm_pager_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|swap_pager_getpage
parameter_list|(
name|vm_pager_t
parameter_list|,
name|vm_page_t
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|swap_pager_putpage
parameter_list|(
name|vm_pager_t
parameter_list|,
name|vm_page_t
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|swap_pager_getmulti
parameter_list|(
name|vm_pager_t
parameter_list|,
name|vm_page_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|swap_pager_haspage
parameter_list|(
name|vm_pager_t
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|swap_pager_io
parameter_list|(
name|sw_pager_t
parameter_list|,
name|vm_page_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|swap_pager_iodone
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|swap_pager_clean
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|swap_pager_copy
name|__P
argument_list|(
operator|(
name|vm_pager_t
operator|,
name|vm_offset_t
operator|,
name|vm_pager_t
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
name|vm_pager_t
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pagerops
name|swappagerops
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

