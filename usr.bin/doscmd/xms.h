begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Helmut Wirth<hfwirth@ping.at>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, witout modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT   * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XMS_H
end_ifndef

begin_define
define|#
directive|define
name|XMS_H
end_define

begin_define
define|#
directive|define
name|XMS_VERSION
value|0x0300
end_define

begin_comment
comment|/* version 3.00 */
end_comment

begin_define
define|#
directive|define
name|XMS_REVISION
value|0x0100
end_define

begin_comment
comment|/* driver revision 1.0 */
end_comment

begin_define
define|#
directive|define
name|NUM_HANDLES
value|64
end_define

begin_comment
comment|/* number of available handles */
end_comment

begin_define
define|#
directive|define
name|FIRST_HANDLE
value|1
end_define

begin_comment
comment|/* number of firts valid handle */
end_comment

begin_define
define|#
directive|define
name|PARAGRAPH
value|16
end_define

begin_comment
comment|/* bytes in a paragraph */
end_comment

begin_define
define|#
directive|define
name|MAX_BLOCK_LOCKS
value|256
end_define

begin_comment
comment|/* number of locks on a block */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_EMM_SIZE
value|512 * 1024
end_define

begin_comment
comment|/* default EMM size */
end_comment

begin_comment
comment|/* Register AH codes for XMS functions */
end_comment

begin_define
define|#
directive|define
name|XMS_GET_VERSION
value|0x00
end_define

begin_define
define|#
directive|define
name|XMS_ALLOCATE_HIGH_MEMORY
value|0x01
end_define

begin_define
define|#
directive|define
name|XMS_FREE_HIGH_MEMORY
value|0x02
end_define

begin_define
define|#
directive|define
name|XMS_GLOBAL_ENABLE_A20
value|0x03
end_define

begin_define
define|#
directive|define
name|XMS_GLOBAL_DISABLE_A20
value|0x04
end_define

begin_define
define|#
directive|define
name|XMS_LOCAL_ENABLE_A20
value|0x05
end_define

begin_define
define|#
directive|define
name|XMS_LOCAL_DISABLE_A20
value|0x06
end_define

begin_define
define|#
directive|define
name|XMS_QUERY_A20
value|0x07
end_define

begin_define
define|#
directive|define
name|XMS_QUERY_FREE_EXTENDED_MEMORY
value|0x08
end_define

begin_define
define|#
directive|define
name|XMS_ALLOCATE_EXTENDED_MEMORY
value|0x09
end_define

begin_define
define|#
directive|define
name|XMS_FREE_EXTENDED_MEMORY
value|0x0a
end_define

begin_define
define|#
directive|define
name|XMS_MOVE_EXTENDED_MEMORY_BLOCK
value|0x0b
end_define

begin_define
define|#
directive|define
name|XMS_LOCK_EXTENDED_MEMORY_BLOCK
value|0x0c
end_define

begin_define
define|#
directive|define
name|XMS_UNLOCK_EXTENDED_MEMORY_BLOCK
value|0x0d
end_define

begin_define
define|#
directive|define
name|XMS_GET_EMB_HANDLE_INFORMATION
value|0x0e
end_define

begin_define
define|#
directive|define
name|XMS_RESIZE_EXTENDED_MEMORY_BLOCK
value|0x0f
end_define

begin_define
define|#
directive|define
name|XMS_ALLOCATE_UMB
value|0x10
end_define

begin_define
define|#
directive|define
name|XMS_DEALLOCATE_UMB
value|0x11
end_define

begin_define
define|#
directive|define
name|XMS_REALLOCATE_UMB
value|0x12
end_define

begin_comment
comment|/* New functions for values bigger than 65MB, not implented yet */
end_comment

begin_define
define|#
directive|define
name|XMS_QUERY_FREE_EXTENDED_MEMORY_LARGE
value|0x88
end_define

begin_define
define|#
directive|define
name|XMS_ALLOCATE_EXTENDED_MEMORY_LARGE
value|0x89
end_define

begin_define
define|#
directive|define
name|XMS_FREE_EXTENDED_MEMORY_LARGE
value|0x8a
end_define

begin_comment
comment|/* XMS error return codes */
end_comment

begin_define
define|#
directive|define
name|XMS_SUCCESS
value|0x0
end_define

begin_define
define|#
directive|define
name|XMS_NOT_IMPLEMENTED
value|0x80
end_define

begin_define
define|#
directive|define
name|XMS_VDISK
value|0x81
end_define

begin_comment
comment|/* If vdisk.sys is present */
end_comment

begin_define
define|#
directive|define
name|XMS_A20_ERROR
value|0x82
end_define

begin_define
define|#
directive|define
name|XMS_GENERAL_ERROR
value|0x8e
end_define

begin_define
define|#
directive|define
name|XMS_HMA_NOT_MANAGED
value|0x90
end_define

begin_define
define|#
directive|define
name|XMS_HMA_ALREADY_USED
value|0x91
end_define

begin_define
define|#
directive|define
name|XMS_HMA_NOT_ALLOCATED
value|0x93
end_define

begin_define
define|#
directive|define
name|XMS_A20_STILL_ENABLED
value|0x94
end_define

begin_define
define|#
directive|define
name|XMS_FULL
value|0xa0
end_define

begin_define
define|#
directive|define
name|XMS_OUT_OF_HANDLES
value|0xa1
end_define

begin_define
define|#
directive|define
name|XMS_INVALID_HANDLE
value|0xa2
end_define

begin_define
define|#
directive|define
name|XMS_INVALID_SOURCE_HANDLE
value|0xa3
end_define

begin_define
define|#
directive|define
name|XMS_INVALID_SOURCE_OFFSET
value|0xa4
end_define

begin_define
define|#
directive|define
name|XMS_INVALID_DESTINATION_HANDLE
value|0xa5
end_define

begin_define
define|#
directive|define
name|XMS_INVALID_DESTINATION_OFFSET
value|0xa6
end_define

begin_define
define|#
directive|define
name|XMS_INVALID_LENGTH
value|0xa7
end_define

begin_define
define|#
directive|define
name|XMS_BLOCK_NOT_LOCKED
value|0xaa
end_define

begin_define
define|#
directive|define
name|XMS_BLOCK_IS_LOCKED
value|0xab
end_define

begin_define
define|#
directive|define
name|XMS_BLOCK_LOCKCOUNT_OVERFLOW
value|0xac
end_define

begin_define
define|#
directive|define
name|XMS_REQUESTED_UMB_TOO_BIG
value|0xb0
end_define

begin_define
define|#
directive|define
name|XMS_NO_UMBS_AVAILABLE
value|0xb1
end_define

begin_define
define|#
directive|define
name|XMS_INVALID_UMB_SEGMENT
value|0xb2
end_define

begin_comment
comment|/*  * EMM structure for data exchange with DOS caller, hence the  * packed format  */
end_comment

begin_struct
struct|struct
name|EMM
block|{
name|u_long
name|nbytes
decl_stmt|;
name|u_short
name|src_handle
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
name|u_long
name|src_offset
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
name|u_short
name|dst_handle
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
name|u_long
name|dst_offset
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * XMS info structure, only used to pass information to and from  * DOS   */
end_comment

begin_struct
struct|struct
name|XMSinfo
block|{
name|u_char
name|handle
decl_stmt|;
comment|/* the handle */
name|u_char
name|num_locks
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
comment|/* number of locks */
name|u_long
name|size
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
comment|/* size of memory */
name|u_long
name|phys_addr
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
comment|/* "physical" address */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Handle management inside the emulator for extendend memory pages,   * invisible to DOS  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_long
name|addr
decl_stmt|;
comment|/* address inside emulator, from malloc() */
name|u_long
name|size
decl_stmt|;
comment|/* size in bytes */
name|u_char
name|num_locks
decl_stmt|;
comment|/* lock count for this handle */
block|}
name|XMS_handle
typedef|;
end_typedef

begin_comment
comment|/*  * Managment of UMB memory paragraphs (16 bytes). UMB blocks are  * directly accessible by VM86 applications and lie between 0xd0000 and  * 0xefff0 in VM86 memory space.   */
end_comment

begin_struct
struct|struct
name|_UMB_block
block|{
name|u_long
name|addr
decl_stmt|;
comment|/* Start address of block */
name|u_long
name|size
decl_stmt|;
comment|/* Size in bytes */
name|struct
name|_UMB_block
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_UMB_block
name|UMB_block
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XMS_H */
end_comment

end_unit

