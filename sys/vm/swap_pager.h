begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 University of Utah.  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)swap_pager.h	8.1 (Berkeley) 6/11/93  */
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
comment|/*  * In the swap pager, the backing store for an object is organized as an  * array of some number of "swap blocks".  A swap block consists of a bitmask  * and some number of contiguous DEV_BSIZE disk blocks.  The minimum size  * of a swap block is:  *  *	max(PAGE_SIZE, dmmin*DEV_BSIZE)			[ 32k currently ]  *  * bytes (since the pager interface is page oriented), the maximum size is:  *  *	min(#bits(swb_mask)*PAGE_SIZE, dmmax*DEV_BSIZE)	[ 128k currently ]  *  * where dmmin and dmmax are left over from the old VM interface.  The bitmask  * (swb_mask) is used by swap_pager_haspage() to determine if a particular  * page has actually been written; i.e. the pager copy of the page is valid.  * All swap blocks in the backing store of an object will be the same size.  *  * The reason for variable sized swap blocks is to reduce fragmentation of  * swap resources.  Whenever possible we allocate smaller swap blocks to  * smaller objects.  The swap block size is determined from a table of  * object-size vs. swap-block-size computed at boot time.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|sw_bm_t
typedef|;
end_typedef

begin_comment
comment|/* pager bitmask */
end_comment

begin_struct
struct|struct
name|swblock
block|{
name|sw_bm_t
name|swb_mask
decl_stmt|;
comment|/* bitmask of valid pages in this block */
name|daddr_t
name|swb_block
decl_stmt|;
comment|/* starting disk block for this block */
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
name|sw_bsize
decl_stmt|;
comment|/* size of swap blocks (DEV_BSIZE units) */
name|int
name|sw_nblocks
decl_stmt|;
comment|/* number of blocks in list (sw_blk_t units) */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SWAP_PAGER_ */
end_comment

end_unit

