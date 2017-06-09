begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Matthew Dillon.  All Rights Reserved.  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Implements bitmap resource lists.  *  *	Usage:  *		blist = blist_create(blocks, flags)  *		(void)  blist_destroy(blist)  *		blkno = blist_alloc(blist, count)  *		(void)  blist_free(blist, blkno, count)  *		nblks = blist_fill(blist, blkno, count)  *		(void)  blist_resize(&blist, count, freeextra, flags)  *		  *  *	Notes:  *		on creation, the entire list is marked reserved.  You should  *		first blist_free() the sections you want to make available  *		for allocation before doing general blist_alloc()/free()  *		ops.  *  *		SWAPBLK_NONE is returned on failure.  This module is typically  *		capable of managing up to (2^63) blocks per blist, though  *		the memory utilization would be insane if you actually did  *		that.  Managing something like 512MB worth of 4K blocks   *		eats around 32 KBytes of memory.   *  * $FreeBSD$   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_BLIST_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_BLIST_H_
end_define

begin_typedef
typedef|typedef
name|uint64_t
name|u_daddr_t
typedef|;
end_typedef

begin_comment
comment|/* unsigned disk address */
end_comment

begin_comment
comment|/*  * note: currently use SWAPBLK_NONE as an absolute value rather then   * a flag bit.  */
end_comment

begin_define
define|#
directive|define
name|SWAPBLK_MASK
value|((daddr_t)((u_daddr_t)-1>> 1))
end_define

begin_comment
comment|/* mask */
end_comment

begin_define
define|#
directive|define
name|SWAPBLK_NONE
value|((daddr_t)((u_daddr_t)SWAPBLK_MASK + 1))
end_define

begin_comment
comment|/* flag */
end_comment

begin_comment
comment|/*  * Both blmeta and bmu_bitmap MUST be a power of 2 in size.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|blmeta
block|{
union|union
block|{
name|daddr_t
name|bmu_avail
decl_stmt|;
comment|/* space available under us	*/
name|u_daddr_t
name|bmu_bitmap
decl_stmt|;
comment|/* bitmap if we are a leaf	*/
block|}
name|u
union|;
name|daddr_t
name|bm_bighint
decl_stmt|;
comment|/* biggest contiguous block hint*/
block|}
name|blmeta_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|blist
block|{
name|daddr_t
name|bl_blocks
decl_stmt|;
comment|/* area of coverage		*/
name|daddr_t
name|bl_radix
decl_stmt|;
comment|/* coverage radix		*/
name|daddr_t
name|bl_skip
decl_stmt|;
comment|/* starting skip		*/
name|daddr_t
name|bl_free
decl_stmt|;
comment|/* number of free blocks	*/
name|blmeta_t
modifier|*
name|bl_root
decl_stmt|;
comment|/* root of radix tree		*/
name|daddr_t
name|bl_rootblks
decl_stmt|;
comment|/* daddr_t blks allocated for tree */
block|}
typedef|*
name|blist_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BLIST_META_RADIX
value|16
end_define

begin_define
define|#
directive|define
name|BLIST_BMAP_RADIX
value|(sizeof(u_daddr_t)*8)
end_define

begin_define
define|#
directive|define
name|BLIST_MAX_ALLOC
value|BLIST_BMAP_RADIX
end_define

begin_function_decl
name|daddr_t
name|blist_alloc
parameter_list|(
name|blist_t
name|blist
parameter_list|,
name|daddr_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|blist_t
name|blist_create
parameter_list|(
name|daddr_t
name|blocks
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|blist_destroy
parameter_list|(
name|blist_t
name|blist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|daddr_t
name|blist_fill
parameter_list|(
name|blist_t
name|bl
parameter_list|,
name|daddr_t
name|blkno
parameter_list|,
name|daddr_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|blist_free
parameter_list|(
name|blist_t
name|blist
parameter_list|,
name|daddr_t
name|blkno
parameter_list|,
name|daddr_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|blist_print
parameter_list|(
name|blist_t
name|blist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|blist_resize
parameter_list|(
name|blist_t
modifier|*
name|pblist
parameter_list|,
name|daddr_t
name|count
parameter_list|,
name|int
name|freenew
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_BLIST_H_ */
end_comment

end_unit

