begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/****************************************************************  *  * File:  mm.h  *  *  * Description:  *  MM (Memory Management) object definitions.  *  It also includes definitions of the Free Block, Busy Block  *  and Memory Block structures used by the MM object.  *  ****************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MM_H
end_ifndef

begin_define
define|#
directive|define
name|__MM_H
end_define

begin_include
include|#
directive|include
file|"mm_ext.h"
end_include

begin_define
define|#
directive|define
name|__ERR_MODULE__
value|MODULE_MM
end_define

begin_define
define|#
directive|define
name|MAKE_ALIGNED
parameter_list|(
name|addr
parameter_list|,
name|align
parameter_list|)
define|\
value|(((uint64_t)(addr) + ((align) - 1))& (~(((uint64_t)align) - 1)))
end_define

begin_comment
comment|/* t_MemBlock data structure defines parameters of the Memory Block */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_MemBlock
block|{
name|struct
name|t_MemBlock
modifier|*
name|p_Next
decl_stmt|;
comment|/* Pointer to the next memory block */
name|uint64_t
name|base
decl_stmt|;
comment|/* Base address of the memory block */
name|uint64_t
name|end
decl_stmt|;
comment|/* End address of the memory block */
block|}
name|t_MemBlock
typedef|;
end_typedef

begin_comment
comment|/* t_FreeBlock data structure defines parameters of the Free Block */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FreeBlock
block|{
name|struct
name|t_FreeBlock
modifier|*
name|p_Next
decl_stmt|;
comment|/* Pointer to the next free block */
name|uint64_t
name|base
decl_stmt|;
comment|/* Base address of the block */
name|uint64_t
name|end
decl_stmt|;
comment|/* End address of the block */
block|}
name|t_FreeBlock
typedef|;
end_typedef

begin_comment
comment|/* t_BusyBlock data structure defines parameters of the Busy Block  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_BusyBlock
block|{
name|struct
name|t_BusyBlock
modifier|*
name|p_Next
decl_stmt|;
comment|/* Pointer to the next free block */
name|uint64_t
name|base
decl_stmt|;
comment|/* Base address of the block */
name|uint64_t
name|end
decl_stmt|;
comment|/* End address of the block */
name|char
name|name
index|[
name|MM_MAX_NAME_LEN
index|]
decl_stmt|;
comment|/* That block of memory was allocated for                                            something specified by the Name */
block|}
name|t_BusyBlock
typedef|;
end_typedef

begin_comment
comment|/* t_MM data structure defines parameters of the MM object */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_MM
block|{
name|t_Handle
name|h_Spinlock
decl_stmt|;
name|t_MemBlock
modifier|*
name|memBlocks
decl_stmt|;
comment|/* List of memory blocks (Memory list) */
name|t_BusyBlock
modifier|*
name|busyBlocks
decl_stmt|;
comment|/* List of busy blocks (Busy list) */
name|t_FreeBlock
modifier|*
name|freeBlocks
index|[
name|MM_MAX_ALIGNMENT
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Alignment lists of free blocks (Free lists) */
name|uint64_t
name|freeMemSize
decl_stmt|;
comment|/* Total size of free memory (in bytes) */
block|}
name|t_MM
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MM_H */
end_comment

end_unit

