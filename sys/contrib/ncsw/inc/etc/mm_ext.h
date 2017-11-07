begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2012 Freescale Semiconductor, Inc  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          mm_ext.h   @Description   Memory Manager Application Programming Interface */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MM_EXT
end_ifndef

begin_define
define|#
directive|define
name|__MM_EXT
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_define
define|#
directive|define
name|MM_MAX_ALIGNMENT
value|20
end_define

begin_comment
comment|/* Alignments from 2 to 128 are available                                    where maximum alignment defined as                                    MM_MAX_ALIGNMENT power of 2 */
end_comment

begin_define
define|#
directive|define
name|MM_MAX_NAME_LEN
value|32
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         etc_id   Utility Library Application Programming Interface   @Description   External routines.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         mm_grp Flexible Memory Manager   @Description   Flexible Memory Manager module functions,definitions and enums.                 (All of the following functions,definitions and enums can be found in mm_ext.h)   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MM_Init   @Description   Initializes a new MM object.                  It initializes a new memory block consisting of base address                 and size of the available memory by calling to MemBlock_Init                 routine. It is also initializes a new free block for each                 by calling FreeBlock_Init routine, which is pointed to                 the almost all memory started from the required alignment                 from the base address and to the end of the memory.                 The handle to the new MM object is returned via "MM"                 argument (passed by reference).   @Param[in]     h_MM    - Handle to the MM object.  @Param[in]     base    - Base address of the MM.  @Param[in]     size    - Size of the MM.   @Return        E_OK is returned on success. E_NOMEMORY is returned if the new MM object or a new free block can not be initialized. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|MM_Init
parameter_list|(
name|t_Handle
modifier|*
name|h_MM
parameter_list|,
name|uint64_t
name|base
parameter_list|,
name|uint64_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MM_Get   @Description   Allocates a block of memory according to the given size and the alignment.                  The Alignment argument tells from which                 free list allocate a block of memory. 2^alignment indicates                 the alignment that the base address of the allocated block                 should have. So, the only values 1, 2, 4, 8, 16, 32 and 64                 are available for the alignment argument.                 The routine passes through the specific free list of free                 blocks and seeks for a first block that have anough memory                 that  is required (best fit).                 After the block is found and data is allocated, it calls                 the internal MM_CutFree routine to update all free lists                 do not include a just allocated block. Of course, each                 free list contains a free blocks with the same alignment.                 It is also creates a busy block that holds                 information about an allocated block.   @Param[in]     h_MM        - Handle to the MM object.  @Param[in]     size        - Size of the MM.  @Param[in]     alignment   - Index as a power of two defines a required                               alignment (in bytes); Should be 1, 2, 4, 8, 16, 32 or 64  @Param[in]     name        - The name that specifies an allocated block.   @Return        base address of an allocated block ILLEGAL_BASE if can't allocate a block */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint64_t
name|MM_Get
parameter_list|(
name|t_Handle
name|h_MM
parameter_list|,
name|uint64_t
name|size
parameter_list|,
name|uint64_t
name|alignment
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MM_GetBase   @Description   Gets the base address of the required MM objects.   @Param[in]     h_MM - Handle to the MM object.   @Return        base address of the block. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint64_t
name|MM_GetBase
parameter_list|(
name|t_Handle
name|h_MM
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MM_GetForce   @Description   Force memory allocation.                  It means to allocate a block of memory of the given                 size from the given base address.                 The routine checks if the required block can be allocated                 (that is it is free) and then, calls the internal MM_CutFree                 routine to update all free lists do not include that block.   @Param[in]     h_MM    - Handle to the MM object.  @Param[in]     base    - Base address of the MM.  @Param[in]     size    - Size of the MM.  @Param[in]     name    - Name that specifies an allocated block.   @Return        base address of an allocated block, ILLEGAL_BASE if can't allocate a block. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint64_t
name|MM_GetForce
parameter_list|(
name|t_Handle
name|h_MM
parameter_list|,
name|uint64_t
name|base
parameter_list|,
name|uint64_t
name|size
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MM_GetForceMin   @Description   Allocates a block of memory according to the given size, the alignment and minimum base address.                  The Alignment argument tells from which                 free list allocate a block of memory. 2^alignment indicates                 the alignment that the base address of the allocated block                 should have. So, the only values 1, 2, 4, 8, 16, 32 and 64                 are available for the alignment argument.                 The minimum baser address forces the location of the block                 to be from a given address onward.                 The routine passes through the specific free list of free                 blocks and seeks for the first base address equal or smaller                 than the required minimum address and end address larger than                 than the required base + its size - i.e. that may contain                 the required block.                 After the block is found and data is allocated, it calls                 the internal MM_CutFree routine to update all free lists                 do not include a just allocated block. Of course, each                 free list contains a free blocks with the same alignment.                 It is also creates a busy block that holds                 information about an allocated block.   @Param[in]     h_MM        - Handle to the MM object.  @Param[in]     size        - Size of the MM.  @Param[in]     alignment   - Index as a power of two defines a required                               alignment (in bytes); Should be 1, 2, 4, 8, 16, 32 or 64  @Param[in]     min         - The minimum base address of the block.  @Param[in]     name        - Name that specifies an allocated block.   @Return        base address of an allocated block,ILLEGAL_BASE if can't allocate a block. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint64_t
name|MM_GetForceMin
parameter_list|(
name|t_Handle
name|h_MM
parameter_list|,
name|uint64_t
name|size
parameter_list|,
name|uint64_t
name|alignment
parameter_list|,
name|uint64_t
name|min
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MM_Put   @Description   Puts a block of memory of the given base address back to the memory.                  It checks if there is a busy block with the                 given base address. If not, it returns 0, that                 means can't free a block. Otherwise, it gets parameters of                 the busy block and after it updates lists of free blocks,                 removes that busy block from the list by calling to MM_CutBusy                 routine.                 After that it calls to MM_AddFree routine to add a new free                 block to the free lists.   @Param[in]     h_MM    - Handle to the MM object.  @Param[in]     base    - Base address of the MM.   @Return         The size of bytes released, 0 if failed. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint64_t
name|MM_Put
parameter_list|(
name|t_Handle
name|h_MM
parameter_list|,
name|uint64_t
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MM_PutForce   @Description   Releases a block of memory of the required size from the required base address.                  First, it calls to MM_CutBusy routine                 to cut a free block from the busy list. And then, calls to                 MM_AddFree routine to add the free block to the free lists.   @Param[in]     h_MM    - Handle to the MM object.  @Param[in]     base    - Base address of of a block to free.  @Param[in]     size    - Size of a block to free.   @Return        The number of bytes released, 0 on failure. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint64_t
name|MM_PutForce
parameter_list|(
name|t_Handle
name|h_MM
parameter_list|,
name|uint64_t
name|base
parameter_list|,
name|uint64_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MM_Add   @Description   Adds a new memory block for memory allocation.                  When a new memory block is initialized and added to the                 memory list, it calls to MM_AddFree routine to add the                 new free block to the free lists.   @Param[in]     h_MM    - Handle to the MM object.  @Param[in]     base    - Base address of the memory block.  @Param[in]     size    - Size of the memory block.   @Return        E_OK on success, otherwise returns an error code. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|MM_Add
parameter_list|(
name|t_Handle
name|h_MM
parameter_list|,
name|uint64_t
name|base
parameter_list|,
name|uint64_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MM_Dump   @Description   Prints results of free and busy lists.   @Param[in]     h_MM        - Handle to the MM object. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|MM_Dump
parameter_list|(
name|t_Handle
name|h_MM
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MM_Free   @Description   Releases memory allocated for MM object.   @Param[in]     h_MM - Handle of the MM object. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|MM_Free
parameter_list|(
name|t_Handle
name|h_MM
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MM_GetMemBlock   @Description   Returns base address of the memory block specified by the index.                  If index is 0, returns base address                 of the first memory block, 1 - returns base address                 of the second memory block, etc.                 Note, those memory blocks are allocated by the                 application before MM_Init or MM_Add and have to                 be released by the application before or after invoking                 the MM_Free routine.   @Param[in]     h_MM    - Handle to the MM object.  @Param[in]     index   - Index of the memory block.   @Return        valid base address or ILLEGAL_BASE if no memory block specified by the index. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint64_t
name|MM_GetMemBlock
parameter_list|(
name|t_Handle
name|h_MM
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MM_InRange   @Description   Checks if a specific address is in the memory range of the passed MM object.   @Param[in]     h_MM    - Handle to the MM object.  @Param[in]     addr    - The address to be checked.   @Return        TRUE if the address is in the address range of the block, FALSE otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|bool
name|MM_InRange
parameter_list|(
name|t_Handle
name|h_MM
parameter_list|,
name|uint64_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MM_GetFreeMemSize   @Description   Returns the size (in bytes) of free memory.   @Param[in]     h_MM    - Handle to the MM object.   @Return        Free memory size in bytes. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint64_t
name|MM_GetFreeMemSize
parameter_list|(
name|t_Handle
name|h_MM
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of mm_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of etc_id group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MM_EXT_H */
end_comment

end_unit

