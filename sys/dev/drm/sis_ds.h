begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sis_ds.h -- Private header for Direct Rendering Manager -*- linux-c -*-  * Created: Mon Jan  4 10:05:05 1999 by sclin@sis.com.tw  *  * Copyright 2000 Silicon Integrated Systems Corp, Inc., HsinChu, Taiwan.  * All rights reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *   * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *   * Authors:  *    Sung-Ching Lin<sclin@sis.com.tw>  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SIS_DS_H__
end_ifndef

begin_define
define|#
directive|define
name|__SIS_DS_H__
end_define

begin_comment
comment|/* Set Data Structure */
end_comment

begin_define
define|#
directive|define
name|SET_SIZE
value|5000
end_define

begin_typedef
typedef|typedef
name|unsigned
name|int
name|ITEM_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|ITEM_TYPE
name|val
decl_stmt|;
name|int
name|alloc_next
decl_stmt|,
name|free_next
decl_stmt|;
block|}
name|list_item_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|alloc
decl_stmt|;
name|int
name|free
decl_stmt|;
name|int
name|trace
decl_stmt|;
name|list_item_t
name|list
index|[
name|SET_SIZE
index|]
decl_stmt|;
block|}
name|set_t
typedef|;
end_typedef

begin_function_decl
name|set_t
modifier|*
name|setInit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setAdd
parameter_list|(
name|set_t
modifier|*
name|set
parameter_list|,
name|ITEM_TYPE
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setDel
parameter_list|(
name|set_t
modifier|*
name|set
parameter_list|,
name|ITEM_TYPE
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setFirst
parameter_list|(
name|set_t
modifier|*
name|set
parameter_list|,
name|ITEM_TYPE
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setNext
parameter_list|(
name|set_t
modifier|*
name|set
parameter_list|,
name|ITEM_TYPE
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setDestroy
parameter_list|(
name|set_t
modifier|*
name|set
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * GLX Hardware Device Driver common code  * Copyright (C) 1999 Keith Whitwell  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included  * in all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * KEITH WHITWELL, OR ANY OTHER CONTRIBUTORS BE LIABLE FOR ANY CLAIM,   * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR   * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE   * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  *  */
end_comment

begin_struct
struct|struct
name|mem_block_t
block|{
name|struct
name|mem_block_t
modifier|*
name|next
decl_stmt|;
name|struct
name|mem_block_t
modifier|*
name|heap
decl_stmt|;
name|int
name|ofs
decl_stmt|,
name|size
decl_stmt|;
name|int
name|align
decl_stmt|;
name|int
name|free
range|:
literal|1
decl_stmt|;
name|int
name|reserved
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mem_block_t
name|TMemBlock
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|mem_block_t
modifier|*
name|PMemBlock
typedef|;
end_typedef

begin_comment
comment|/* a heap is just the first block in a chain */
end_comment

begin_typedef
typedef|typedef
name|struct
name|mem_block_t
name|memHeap_t
typedef|;
end_typedef

begin_function
specifier|static
name|__inline__
name|int
name|mmBlockSize
parameter_list|(
name|PMemBlock
name|b
parameter_list|)
block|{
return|return
name|b
operator|->
name|size
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|mmOffset
parameter_list|(
name|PMemBlock
name|b
parameter_list|)
block|{
return|return
name|b
operator|->
name|ofs
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|mmMarkReserved
parameter_list|(
name|PMemBlock
name|b
parameter_list|)
block|{
name|b
operator|->
name|reserved
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_comment
comment|/*   * input: total size in bytes  * return: a heap pointer if OK, NULL if error  */
end_comment

begin_function_decl
name|memHeap_t
modifier|*
name|mmInit
parameter_list|(
name|int
name|ofs
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|memHeap_t
modifier|*
name|mmAddRange
parameter_list|(
name|memHeap_t
modifier|*
name|heap
parameter_list|,
name|int
name|ofs
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Allocate 'size' bytes with 2^align2 bytes alignment,  * restrict the search to free memory after 'startSearch'  * depth and back buffers should be in different 4mb banks  * to get better page hits if possible  * input:	size = size of block  *       	align2 = 2^align2 bytes alignment  *		startSearch = linear offset from start of heap to begin search  * return: pointer to the allocated block, 0 if error  */
end_comment

begin_function_decl
name|PMemBlock
name|mmAllocMem
parameter_list|(
name|memHeap_t
modifier|*
name|heap
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|align2
parameter_list|,
name|int
name|startSearch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns 1 if the block 'b' is part of the heap 'heap'  */
end_comment

begin_function_decl
name|int
name|mmBlockInHeap
parameter_list|(
name|PMemBlock
name|heap
parameter_list|,
name|PMemBlock
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Free block starts at offset  * input: pointer to a block  * return: 0 if OK, -1 if error  */
end_comment

begin_function_decl
name|int
name|mmFreeMem
parameter_list|(
name|PMemBlock
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Reserve 'size' bytes block start at offset  * This is used to prevent allocation of memory already used  * by the X server for the front buffer, pixmaps, and cursor  * input: size, offset  * output: 0 if OK, -1 if error  */
end_comment

begin_function_decl
name|int
name|mmReserveMem
parameter_list|(
name|memHeap_t
modifier|*
name|heap
parameter_list|,
name|int
name|offset
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mmFreeReserved
parameter_list|(
name|memHeap_t
modifier|*
name|heap
parameter_list|,
name|int
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * destroy MM  */
end_comment

begin_function_decl
name|void
name|mmDestroy
parameter_list|(
name|memHeap_t
modifier|*
name|mmInit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* For debuging purpose. */
end_comment

begin_function_decl
name|void
name|mmDumpMemInfo
parameter_list|(
name|memHeap_t
modifier|*
name|mmInit
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SIS_DS_H__ */
end_comment

end_unit

