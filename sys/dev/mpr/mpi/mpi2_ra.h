begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 LSI Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * LSI MPT-Fusion Host Adapter FreeBSD  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  Copyright (c) 2009 LSI Corporation.  *  *  *           Name:  mpi2_ra.h  *          Title:  MPI RAID Accelerator messages and structures  *  Creation Date:  April 13, 2009  *  *  mpi2_ra.h Version:  02.00.00  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  05-06-09  02.00.00  Initial version.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_RA_H
end_ifndef

begin_define
define|#
directive|define
name|MPI2_RA_H
end_define

begin_comment
comment|/* generic structure for RAID Accelerator Control Block */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAID_ACCELERATOR_CONTROL_BLOCK
block|{
name|U32
name|Reserved
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x00 */
name|U32
name|RaidAcceleratorCDB
index|[
literal|1
index|]
decl_stmt|;
comment|/* 0x20 */
block|}
name|MPI2_RAID_ACCELERATOR_CONTROL_BLOCK
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAID_ACCELERATOR_CONTROL_BLOCK
operator|,
name|Mpi2RAIDAcceleratorControlBlock_t
operator|,
name|MPI2_POINTER
name|pMpi2RAIDAcceleratorControlBlock_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************** * *        RAID Accelerator Messages * *******************************************************************************/
end_comment

begin_comment
comment|/* RAID Accelerator Request Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAID_ACCELERATOR_REQUEST
block|{
name|U16
name|Reserved0
decl_stmt|;
comment|/* 0x00 */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x06 */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 0x07 */
name|U8
name|VP_ID
decl_stmt|;
comment|/* 0x08 */
name|U8
name|VF_ID
decl_stmt|;
comment|/* 0x09 */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x0A */
name|U64
name|RaidAcceleratorControlBlockAddress
decl_stmt|;
comment|/* 0x0C */
name|U8
name|DmaEngineNumber
decl_stmt|;
comment|/* 0x14 */
name|U8
name|Reserved4
decl_stmt|;
comment|/* 0x15 */
name|U16
name|Reserved5
decl_stmt|;
comment|/* 0x16 */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 0x18 */
name|U32
name|Reserved7
decl_stmt|;
comment|/* 0x1C */
name|U32
name|Reserved8
decl_stmt|;
comment|/* 0x20 */
block|}
name|MPI2_RAID_ACCELERATOR_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAID_ACCELERATOR_REQUEST
operator|,
name|Mpi2RAIDAcceleratorRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2RAIDAcceleratorRequest_t
typedef|;
end_typedef

begin_comment
comment|/* RAID Accelerator Error Reply Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAID_ACCELERATOR_REPLY
block|{
name|U16
name|Reserved0
decl_stmt|;
comment|/* 0x00 */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x06 */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 0x07 */
name|U8
name|VP_ID
decl_stmt|;
comment|/* 0x08 */
name|U8
name|VF_ID
decl_stmt|;
comment|/* 0x09 */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x0A */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 0x0C */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0x0E */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 0x10 */
name|U32
name|ProductSpecificData
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_RAID_ACCELERATOR_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAID_ACCELERATOR_REPLY
operator|,
name|Mpi2RAIDAcceleratorReply_t
operator|,
name|MPI2_POINTER
name|pMpi2RAIDAcceleratorReply_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

