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
comment|/*  * SWB_NPAGES must be a power of 2.  It may be set to 1, 2, 4, 8, or 16  * pages per allocation.  We recommend you stick with the default of 8.  * The 16-page limit is due to the radix code (kern/subr_blist.c).  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SWB_NPAGES
argument_list|)
end_if

begin_define
define|#
directive|define
name|SWB_NPAGES
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Piecemeal swap metadata structure.  Swap is stored in a radix tree.  *  * If SWB_NPAGES is 8 and sizeof(char *) == sizeof(daddr_t), our radix  * is basically 8.  Assuming PAGE_SIZE == 4096, one tree level represents  * 32K worth of data, two levels represent 256K, three levels represent  * 2 MBytes.   This is acceptable.  *  * Overall memory utilization is about the same as the old swap structure.  */
end_comment

begin_define
define|#
directive|define
name|SWCORRECT
parameter_list|(
name|n
parameter_list|)
value|(sizeof(void *) * (n) / sizeof(daddr_t))
end_define

begin_define
define|#
directive|define
name|SWAP_META_PAGES
value|(SWB_NPAGES * 2)
end_define

begin_define
define|#
directive|define
name|SWAP_META_MASK
value|(SWAP_META_PAGES - 1)
end_define

begin_struct
struct|struct
name|swblock
block|{
name|struct
name|swblock
modifier|*
name|swb_hnext
decl_stmt|;
name|vm_object_t
name|swb_object
decl_stmt|;
name|vm_pindex_t
name|swb_index
decl_stmt|;
name|int
name|swb_count
decl_stmt|;
name|daddr_t
name|swb_pages
index|[
name|SWAP_META_PAGES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|pagerlst
name|swap_pager_un_object_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|swap_pager_full
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|blist
modifier|*
name|swapblist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uma_zone_t
name|swap_zone
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|swap_pager_putpages
parameter_list|(
name|vm_object_t
parameter_list|,
name|vm_page_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|boolean_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|swap_pager_haspage
parameter_list|(
name|vm_object_t
name|object
parameter_list|,
name|vm_pindex_t
name|pindex
parameter_list|,
name|int
modifier|*
name|before
parameter_list|,
name|int
modifier|*
name|after
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|swap_pager_swp_alloc
parameter_list|(
name|vm_object_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|swap_pager_copy
parameter_list|(
name|vm_object_t
parameter_list|,
name|vm_object_t
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|swap_pager_freespace
parameter_list|(
name|vm_object_t
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|swap_pager_dmzspace
parameter_list|(
name|vm_object_t
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|swap_pager_swap_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|swap_pager_reserve
parameter_list|(
name|vm_object_t
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * newswap functions  */
end_comment

begin_function_decl
name|void
name|swap_pager_page_removed
parameter_list|(
name|vm_page_t
parameter_list|,
name|vm_object_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* choose underlying swap device and queue up I/O */
end_comment

begin_struct_decl
struct_decl|struct
name|buf
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|swstrategy
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* probably needs to move elsewhere */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SWAP_PAGER_ */
end_comment

end_unit

