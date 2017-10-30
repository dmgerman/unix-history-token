begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2012 Freescale Semiconductor, Inc  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**   @File          mem_ext.h   @Description   External prototypes for the memory manager object */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MEM_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__MEM_EXT_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_include
include|#
directive|include
file|"part_ext.h"
end_include

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
comment|/**  @Group         mem_id   Slab Memory Manager   @Description   Slab Memory Manager module functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/* Each block is of the following structure:  *  *  *  +-----------+----------+---------------------------+-----------+-----------+  *  | Alignment |  Prefix  | Data                      | Postfix   | Alignment |  *  |  field    |   field  |  field                    |   field   | Padding   |  *  |           |          |                           |           |           |  *  +-----------+----------+---------------------------+-----------+-----------+  *  and at the beginning of all bytes, an additional optional padding might reside  *  to ensure that the first blocks data field is aligned as requested.  */
end_comment

begin_define
define|#
directive|define
name|MEM_MAX_NAME_LENGTH
value|8
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*  @Description   Memory Segment structure */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|name
index|[
name|MEM_MAX_NAME_LENGTH
index|]
decl_stmt|;
comment|/* The segment's name */
name|uint8_t
modifier|*
modifier|*
name|p_Bases
decl_stmt|;
comment|/* Base addresses of the segments */
name|uint8_t
modifier|*
modifier|*
name|p_BlocksStack
decl_stmt|;
comment|/* Array of pointers to blocks */
name|t_Handle
name|h_Spinlock
decl_stmt|;
name|uint16_t
name|dataSize
decl_stmt|;
comment|/* Size of each data block */
name|uint16_t
name|prefixSize
decl_stmt|;
comment|/* How many bytes to reserve before the data */
name|uint16_t
name|postfixSize
decl_stmt|;
comment|/* How many bytes to reserve after the data */
name|uint16_t
name|alignment
decl_stmt|;
comment|/* Requested alignment for the data field */
name|int
name|allocOwner
decl_stmt|;
comment|/* Memory allocation owner */
name|uint32_t
name|getFailures
decl_stmt|;
comment|/* Number of times get failed */
name|uint32_t
name|num
decl_stmt|;
comment|/* Number of blocks in segment */
name|uint32_t
name|current
decl_stmt|;
comment|/* Current block */
name|bool
name|consecutiveMem
decl_stmt|;
comment|/* Allocate consecutive data blocks memory */
ifdef|#
directive|ifdef
name|DEBUG_MEM_LEAKS
name|void
modifier|*
name|p_MemDbg
decl_stmt|;
comment|/* MEM debug database (MEM leaks detection) */
name|uint32_t
name|blockOffset
decl_stmt|;
name|uint32_t
name|blockSize
decl_stmt|;
endif|#
directive|endif
comment|/* DEBUG_MEM_LEAKS */
block|}
name|t_MemorySegment
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MEM_Init   @Description   Create a new memory segment.   @Param[in]     name        - Name of memory partition.  @Param[in]     p_Handle    - Handle to new segment is returned through here.  @Param[in]     num         - Number of blocks in new segment.  @Param[in]     dataSize    - Size of blocks in segment.  @Param[in]     prefixSize  - How many bytes to allocate before the data.  @Param[in]     postfixSize - How many bytes to allocate after the data.  @Param[in]     alignment   - Requested alignment for data field (in bytes).   @Return        E_OK - success, E_NO_MEMORY - out of memory. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|MEM_Init
parameter_list|(
name|char
name|name
index|[]
parameter_list|,
name|t_Handle
modifier|*
name|p_Handle
parameter_list|,
name|uint32_t
name|num
parameter_list|,
name|uint16_t
name|dataSize
parameter_list|,
name|uint16_t
name|prefixSize
parameter_list|,
name|uint16_t
name|postfixSize
parameter_list|,
name|uint16_t
name|alignment
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MEM_InitSmart   @Description   Create a new memory segment.   @Param[in]     name            - Name of memory partition.  @Param[in]     p_Handle        - Handle to new segment is returned through here.  @Param[in]     num             - Number of blocks in new segment.  @Param[in]     dataSize        - Size of blocks in segment.  @Param[in]     prefixSize      - How many bytes to allocate before the data.  @Param[in]     postfixSize     - How many bytes to allocate after the data.  @Param[in]     alignment       - Requested alignment for data field (in bytes).  @Param[in]     memPartitionId  - Memory partition ID for allocation.  @Param[in]     consecutiveMem  - Whether to allocate the memory blocks                                   continuously or not.   @Return        E_OK - success, E_NO_MEMORY - out of memory. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|MEM_InitSmart
parameter_list|(
name|char
name|name
index|[]
parameter_list|,
name|t_Handle
modifier|*
name|p_Handle
parameter_list|,
name|uint32_t
name|num
parameter_list|,
name|uint16_t
name|dataSize
parameter_list|,
name|uint16_t
name|prefixSize
parameter_list|,
name|uint16_t
name|postfixSize
parameter_list|,
name|uint16_t
name|alignment
parameter_list|,
name|uint8_t
name|memPartitionId
parameter_list|,
name|bool
name|consecutiveMem
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MEM_InitByAddress   @Description   Create a new memory segment with a specified base address.   @Param[in]     name        - Name of memory partition.  @Param[in]     p_Handle    - Handle to new segment is returned through here.  @Param[in]     num         - Number of blocks in new segment.  @Param[in]     dataSize    - Size of blocks in segment.  @Param[in]     prefixSize  - How many bytes to allocate before the data.  @Param[in]     postfixSize - How many bytes to allocate after the data.  @Param[in]     alignment   - Requested alignment for data field (in bytes).  @Param[in]     address     - The required base address.   @Return        E_OK - success, E_NO_MEMORY - out of memory.  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|MEM_InitByAddress
parameter_list|(
name|char
name|name
index|[]
parameter_list|,
name|t_Handle
modifier|*
name|p_Handle
parameter_list|,
name|uint32_t
name|num
parameter_list|,
name|uint16_t
name|dataSize
parameter_list|,
name|uint16_t
name|prefixSize
parameter_list|,
name|uint16_t
name|postfixSize
parameter_list|,
name|uint16_t
name|alignment
parameter_list|,
name|uint8_t
modifier|*
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MEM_Free   @Description   Free a specific memory segment.   @Param[in]     h_Mem - Handle to memory segment.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|MEM_Free
parameter_list|(
name|t_Handle
name|h_Mem
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MEM_Get   @Description   Get a block of memory from a segment.   @Param[in]     h_Mem - Handle to memory segment.   @Return        Pointer to new memory block on success,0 otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
modifier|*
name|MEM_Get
parameter_list|(
name|t_Handle
name|h_Mem
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MEM_GetN   @Description   Get up to N blocks of memory from a segment.                  The blocks are assumed to be of a fixed size (one size per segment).   @Param[in]     h_Mem   - Handle to memory segment.  @Param[in]     num     - Number of blocks to allocate.  @Param[out]    array   - Array of at least num pointers to which the addresses                           of the allocated blocks are written.   @Return        The number of blocks actually allocated.   @Cautions      Interrupts are disabled for all of the allocation loop.                 Although this loop is very short for each block (several machine                 instructions), you should not allocate a very large number                 of blocks via this routine. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint16_t
name|MEM_GetN
parameter_list|(
name|t_Handle
name|h_Mem
parameter_list|,
name|uint32_t
name|num
parameter_list|,
name|void
modifier|*
name|array
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MEM_Put   @Description   Put a block of memory back to a segment.   @Param[in]     h_Mem   - Handle to memory segment.  @Param[in]     p_Block - The block to return.   @Return        Pointer to new memory block on success,0 otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|MEM_Put
parameter_list|(
name|t_Handle
name|h_Mem
parameter_list|,
name|void
modifier|*
name|p_Block
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MEM_ComputePartitionSize   @Description   calculate a tight upper boundary of the size of a partition with                 given attributes.                  The returned value is suitable if one wants to use MEM_InitByAddress().   @Param[in]     num         - The number of blocks in the segment.  @Param[in]     dataSize    - Size of block to get.  @Param[in]     prefixSize  - The prefix size  @Param         postfixSize - The postfix size  @Param[in]     alignment   - The requested alignment value (in bytes)   @Return        The memory block size a segment with the given attributes needs. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|MEM_ComputePartitionSize
parameter_list|(
name|uint32_t
name|num
parameter_list|,
name|uint16_t
name|dataSize
parameter_list|,
name|uint16_t
name|prefixSize
parameter_list|,
name|uint16_t
name|postfixSize
parameter_list|,
name|uint16_t
name|alignment
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_MEM_LEAKS
end_ifdef

begin_if
if|#
directive|if
operator|!
operator|(
operator|(
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|)
operator|&&
operator|(
name|__dest_os
operator|==
name|__ppc_eabi
operator|)
operator|)
end_if

begin_error
error|#
directive|error
literal|"Memory-Leaks-Debug option is supported only for freescale CodeWarrior"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !(defined(__MWERKS__)&& ... */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      MEM_CheckLeaks   @Description   Report MEM object leaks.                  This routine is automatically called by the MEM_Free() routine,                 but it can also be invoked while the MEM object is alive.   @Param[in]     h_Mem - Handle to memory segment.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|MEM_CheckLeaks
parameter_list|(
name|t_Handle
name|h_Mem
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not DEBUG_MEM_LEAKS */
end_comment

begin_define
define|#
directive|define
name|MEM_CheckLeaks
parameter_list|(
name|h_Mem
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not DEBUG_MEM_LEAKS */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Get base of MEM */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MEM_GetBase
parameter_list|(
name|h_Mem
parameter_list|)
value|((t_MemorySegment *)(h_Mem))->p_Bases[0]
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Get size of MEM block */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MEM_GetSize
parameter_list|(
name|h_Mem
parameter_list|)
value|((t_MemorySegment *)(h_Mem))->dataSize
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Get prefix size of MEM block */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MEM_GetPrefixSize
parameter_list|(
name|h_Mem
parameter_list|)
value|((t_MemorySegment *)(h_Mem))->prefixSize
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Get postfix size of MEM block */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MEM_GetPostfixSize
parameter_list|(
name|h_Mem
parameter_list|)
value|((t_MemorySegment *)(h_Mem))->postfixSize
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Get alignment of MEM block (in bytes) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MEM_GetAlignment
parameter_list|(
name|h_Mem
parameter_list|)
value|((t_MemorySegment *)(h_Mem))->alignment
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Get the number of blocks in the segment */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MEM_GetNumOfBlocks
parameter_list|(
name|h_Mem
parameter_list|)
value|((t_MemorySegment *)(h_Mem))->num
end_define

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of MEM group */
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
comment|/* __MEM_EXT_H */
end_comment

end_unit

