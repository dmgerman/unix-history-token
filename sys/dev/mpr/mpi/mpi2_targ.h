begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 LSI Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * LSI MPT-Fusion Host Adapter FreeBSD  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  Copyright (c) 2000-2012 LSI Corporation.  *  *  *           Name:  mpi2_targ.h  *          Title:  MPI Target mode messages and structures  *  Creation Date:  September 8, 2006  *  *  mpi2_targ.h Version: 02.00.06  *  *  NOTE: Names (typedefs, defines, etc.) beginning with an MPI25 or Mpi25  *        prefix are for use only on MPI v2.5 products, and must not be used  *        with MPI v2.0 products. Unless otherwise noted, names beginning with  *        MPI2 or Mpi2 are for use with both MPI v2.0 and MPI v2.5 products.  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  04-30-07  02.00.00  Corresponds to Fusion-MPT MPI Specification Rev A.  *  08-31-07  02.00.01  Added Command Buffer Data Location Address Space bits to  *                      BufferPostFlags field of CommandBufferPostBase Request.  *  02-29-08  02.00.02  Modified various names to make them 32-character unique.  *  10-02-08  02.00.03  Removed NextCmdBufferOffset from  *                      MPI2_TARGET_CMD_BUF_POST_BASE_REQUEST.  *                      Target Status Send Request only takes a single SGE for  *                      response data.  *  02-10-10  02.00.04  Added comment to MPI2_TARGET_SSP_RSP_IU structure.  *  11-18-11  02.00.05  Incorporating additions for MPI v2.5.  *  11-27-12  02.00.06  Added InitiatorDevHandle field to MPI2_TARGET_MODE_ABORT  *                      request message structure.  *                      Added AbortType MPI2_TARGET_MODE_ABORT_DEVHANDLE and  *                      MPI2_TARGET_MODE_ABORT_ALL_COMMANDS.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_TARG_H
end_ifndef

begin_define
define|#
directive|define
name|MPI2_TARG_H
end_define

begin_comment
comment|/****************************************************************************** * *        SCSI Target Messages * *******************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************** *  Target Command Buffer Post Base Request ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TARGET_CMD_BUF_POST_BASE_REQUEST
block|{
name|U8
name|BufferPostFlags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|TotalCmdBuffers
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved
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
name|Reserved2
decl_stmt|;
comment|/* 0x0A */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x0C */
name|U16
name|CmdBufferLength
decl_stmt|;
comment|/* 0x10 */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 0x12 */
name|U32
name|BaseAddressLow
decl_stmt|;
comment|/* 0x14 */
name|U32
name|BaseAddressHigh
decl_stmt|;
comment|/* 0x18 */
block|}
name|MPI2_TARGET_CMD_BUF_POST_BASE_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TARGET_CMD_BUF_POST_BASE_REQUEST
operator|,
name|Mpi2TargetCmdBufferPostBaseRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2TargetCmdBufferPostBaseRequest_t
typedef|;
end_typedef

begin_comment
comment|/* values for the BufferPostflags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_CMD_BUF_POST_BASE_ADDRESS_SPACE_MASK
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI2_CMD_BUF_POST_BASE_SYSTEM_ADDRESS_SPACE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_CMD_BUF_POST_BASE_IOCDDR_ADDRESS_SPACE
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_CMD_BUF_POST_BASE_IOCPLB_ADDRESS_SPACE
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_CMD_BUF_POST_BASE_IOCPLBNTA_ADDRESS_SPACE
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI2_CMD_BUF_POST_BASE_FLAGS_AUTO_POST_ALL
value|(0x01)
end_define

begin_comment
comment|/**************************************************************************** *  Target Command Buffer Post List Request ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TARGET_CMD_BUF_POST_LIST_REQUEST
block|{
name|U16
name|Reserved
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
name|CmdBufferCount
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved1
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
name|Reserved2
decl_stmt|;
comment|/* 0x0A */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x0C */
name|U16
name|IoIndex
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0x10 */
block|}
name|MPI2_TARGET_CMD_BUF_POST_LIST_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TARGET_CMD_BUF_POST_LIST_REQUEST
operator|,
name|Mpi2TargetCmdBufferPostListRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2TargetCmdBufferPostListRequest_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  Target Command Buffer Post Base List Reply ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TARGET_BUF_POST_BASE_LIST_REPLY
block|{
name|U8
name|Flags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved
decl_stmt|;
comment|/* 0x01 */
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
name|U16
name|IoIndex
decl_stmt|;
comment|/* 0x14 */
name|U16
name|Reserved5
decl_stmt|;
comment|/* 0x16 */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 0x18 */
block|}
name|MPI2_TARGET_BUF_POST_BASE_LIST_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TARGET_BUF_POST_BASE_LIST_REPLY
operator|,
name|Mpi2TargetCmdBufferPostBaseListReply_t
operator|,
name|MPI2_POINTER
name|pMpi2TargetCmdBufferPostBaseListReply_t
typedef|;
end_typedef

begin_comment
comment|/* Flags defines */
end_comment

begin_define
define|#
directive|define
name|MPI2_CMD_BUF_POST_REPLY_IOINDEX_VALID
value|(0x01)
end_define

begin_comment
comment|/**************************************************************************** *  Command Buffer Formats (with 16 byte CDB) ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TARGET_SSP_CMD_BUFFER
block|{
name|U8
name|FrameType
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U16
name|InitiatorConnectionTag
decl_stmt|;
comment|/* 0x02 */
name|U32
name|HashedSourceSASAddress
decl_stmt|;
comment|/* 0x04 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x08 */
name|U16
name|Flags
decl_stmt|;
comment|/* 0x0A */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x0C */
name|U16
name|Tag
decl_stmt|;
comment|/* 0x10 */
name|U16
name|TargetPortTransferTag
decl_stmt|;
comment|/* 0x12 */
name|U32
name|DataOffset
decl_stmt|;
comment|/* 0x14 */
comment|/* COMMAND information unit starts here */
name|U8
name|LogicalUnitNumber
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x18 */
name|U8
name|Reserved4
decl_stmt|;
comment|/* 0x20 */
name|U8
name|TaskAttribute
decl_stmt|;
comment|/* lower 3 bits */
comment|/* 0x21 */
name|U8
name|Reserved5
decl_stmt|;
comment|/* 0x22 */
name|U8
name|AdditionalCDBLength
decl_stmt|;
comment|/* upper 5 bits */
comment|/* 0x23 */
name|U8
name|CDB
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0x24 */
comment|/* Additional CDB bytes extend past the CDB field */
block|}
name|MPI2_TARGET_SSP_CMD_BUFFER
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TARGET_SSP_CMD_BUFFER
operator|,
name|Mpi2TargetSspCmdBuffer
operator|,
name|MPI2_POINTER
name|pMp2iTargetSspCmdBuffer
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TARGET_SSP_TASK_BUFFER
block|{
name|U8
name|FrameType
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U16
name|InitiatorConnectionTag
decl_stmt|;
comment|/* 0x02 */
name|U32
name|HashedSourceSASAddress
decl_stmt|;
comment|/* 0x04 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x08 */
name|U16
name|Flags
decl_stmt|;
comment|/* 0x0A */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x0C */
name|U16
name|Tag
decl_stmt|;
comment|/* 0x10 */
name|U16
name|TargetPortTransferTag
decl_stmt|;
comment|/* 0x12 */
name|U32
name|DataOffset
decl_stmt|;
comment|/* 0x14 */
comment|/* TASK information unit starts here */
name|U8
name|LogicalUnitNumber
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x18 */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 0x20 */
name|U8
name|TaskManagementFunction
decl_stmt|;
comment|/* 0x22 */
name|U8
name|Reserved5
decl_stmt|;
comment|/* 0x23 */
name|U16
name|ManagedTaskTag
decl_stmt|;
comment|/* 0x24 */
name|U16
name|Reserved6
decl_stmt|;
comment|/* 0x26 */
name|U32
name|Reserved7
decl_stmt|;
comment|/* 0x28 */
name|U32
name|Reserved8
decl_stmt|;
comment|/* 0x2C */
name|U32
name|Reserved9
decl_stmt|;
comment|/* 0x30 */
block|}
name|MPI2_TARGET_SSP_TASK_BUFFER
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TARGET_SSP_TASK_BUFFER
operator|,
name|Mpi2TargetSspTaskBuffer
operator|,
name|MPI2_POINTER
name|pMpi2TargetSspTaskBuffer
typedef|;
end_typedef

begin_comment
comment|/* mask and shift for HashedSourceSASAddress field */
end_comment

begin_define
define|#
directive|define
name|MPI2_TARGET_HASHED_SAS_ADDRESS_MASK
value|(0xFFFFFF00)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_HASHED_SAS_ADDRESS_SHIFT
value|(8)
end_define

begin_comment
comment|/**************************************************************************** *   MPI v2.0 Target Assist Request ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TARGET_ASSIST_REQUEST
block|{
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x00 */
name|U8
name|TargetAssistFlags
decl_stmt|;
comment|/* 0x01 */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|QueueTag
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
name|IoIndex
decl_stmt|;
comment|/* 0x0C */
name|U16
name|InitiatorConnectionTag
decl_stmt|;
comment|/* 0x0E */
name|U16
name|SGLFlags
decl_stmt|;
comment|/* 0x10 */
name|U8
name|SequenceNumber
decl_stmt|;
comment|/* 0x12 */
name|U8
name|Reserved4
decl_stmt|;
comment|/* 0x13 */
name|U8
name|SGLOffset0
decl_stmt|;
comment|/* 0x14 */
name|U8
name|SGLOffset1
decl_stmt|;
comment|/* 0x15 */
name|U8
name|SGLOffset2
decl_stmt|;
comment|/* 0x16 */
name|U8
name|SGLOffset3
decl_stmt|;
comment|/* 0x17 */
name|U32
name|SkipCount
decl_stmt|;
comment|/* 0x18 */
name|U32
name|DataLength
decl_stmt|;
comment|/* 0x1C */
name|U32
name|BidirectionalDataLength
decl_stmt|;
comment|/* 0x20 */
name|U16
name|IoFlags
decl_stmt|;
comment|/* 0x24 */
name|U16
name|EEDPFlags
decl_stmt|;
comment|/* 0x26 */
name|U32
name|EEDPBlockSize
decl_stmt|;
comment|/* 0x28 */
name|U32
name|SecondaryReferenceTag
decl_stmt|;
comment|/* 0x2C */
name|U16
name|SecondaryApplicationTag
decl_stmt|;
comment|/* 0x30 */
name|U16
name|ApplicationTagTranslationMask
decl_stmt|;
comment|/* 0x32 */
name|U32
name|PrimaryReferenceTag
decl_stmt|;
comment|/* 0x34 */
name|U16
name|PrimaryApplicationTag
decl_stmt|;
comment|/* 0x38 */
name|U16
name|PrimaryApplicationTagMask
decl_stmt|;
comment|/* 0x3A */
name|U32
name|RelativeOffset
decl_stmt|;
comment|/* 0x3C */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x40 */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 0x44 */
name|U32
name|Reserved7
decl_stmt|;
comment|/* 0x48 */
name|U32
name|Reserved8
decl_stmt|;
comment|/* 0x4C */
name|MPI2_SGE_IO_UNION
name|SGL
index|[
literal|1
index|]
decl_stmt|;
comment|/* 0x50 */
block|}
name|MPI2_TARGET_ASSIST_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TARGET_ASSIST_REQUEST
operator|,
name|Mpi2TargetAssistRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2TargetAssistRequest_t
typedef|;
end_typedef

begin_comment
comment|/* Target Assist TargetAssistFlags bits */
end_comment

begin_define
define|#
directive|define
name|MPI2_TARGET_ASSIST_FLAGS_REPOST_CMD_BUFFER
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_ASSIST_FLAGS_TLR
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_ASSIST_FLAGS_RETRANSMIT
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_ASSIST_FLAGS_AUTO_STATUS
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_ASSIST_FLAGS_DATA_DIRECTION
value|(0x01)
end_define

begin_comment
comment|/* Target Assist SGLFlags bits */
end_comment

begin_comment
comment|/* base values for Data Location Address Space */
end_comment

begin_define
define|#
directive|define
name|MPI2_TARGET_ASSIST_SGLFLAGS_ADDR_MASK
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_ASSIST_SGLFLAGS_SYSTEM_ADDR
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_ASSIST_SGLFLAGS_IOCDDR_ADDR
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_ASSIST_SGLFLAGS_IOCPLB_ADDR
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_ASSIST_SGLFLAGS_PLBNTA_ADDR
value|(0x0C)
end_define

begin_comment
comment|/* base values for Type */
end_comment

begin_define
define|#
directive|define
name|MPI2_TARGET_ASSIST_SGLFLAGS_TYPE_MASK
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_ASSIST_SGLFLAGS_MPI_TYPE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_ASSIST_SGLFLAGS_32IEEE_TYPE
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_ASSIST_SGLFLAGS_64IEEE_TYPE
value|(0x02)
end_define

begin_comment
comment|/* shift values for each sub-field */
end_comment

begin_define
define|#
directive|define
name|MPI2_TARGET_ASSIST_SGLFLAGS_SGL3_SHIFT
value|(12)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_ASSIST_SGLFLAGS_SGL2_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_ASSIST_SGLFLAGS_SGL1_SHIFT
value|(4)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_ASSIST_SGLFLAGS_SGL0_SHIFT
value|(0)
end_define

begin_comment
comment|/* Target Assist IoFlags bits */
end_comment

begin_define
define|#
directive|define
name|MPI2_TARGET_ASSIST_IOFLAGS_BIDIRECTIONAL
value|(0x0800)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_ASSIST_IOFLAGS_MULTICAST
value|(0x0400)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_ASSIST_IOFLAGS_RECEIVE_FIRST
value|(0x0200)
end_define

begin_comment
comment|/* Target Assist EEDPFlags bits */
end_comment

begin_define
define|#
directive|define
name|MPI2_TA_EEDPFLAGS_INC_PRI_REFTAG
value|(0x8000)
end_define

begin_define
define|#
directive|define
name|MPI2_TA_EEDPFLAGS_INC_SEC_REFTAG
value|(0x4000)
end_define

begin_define
define|#
directive|define
name|MPI2_TA_EEDPFLAGS_INC_PRI_APPTAG
value|(0x2000)
end_define

begin_define
define|#
directive|define
name|MPI2_TA_EEDPFLAGS_INC_SEC_APPTAG
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|MPI2_TA_EEDPFLAGS_CHECK_REFTAG
value|(0x0400)
end_define

begin_define
define|#
directive|define
name|MPI2_TA_EEDPFLAGS_CHECK_APPTAG
value|(0x0200)
end_define

begin_define
define|#
directive|define
name|MPI2_TA_EEDPFLAGS_CHECK_GUARD
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|MPI2_TA_EEDPFLAGS_PASSTHRU_REFTAG
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|MPI2_TA_EEDPFLAGS_MASK_OP
value|(0x0007)
end_define

begin_define
define|#
directive|define
name|MPI2_TA_EEDPFLAGS_NOOP_OP
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI2_TA_EEDPFLAGS_CHECK_OP
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI2_TA_EEDPFLAGS_STRIP_OP
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI2_TA_EEDPFLAGS_CHECK_REMOVE_OP
value|(0x0003)
end_define

begin_define
define|#
directive|define
name|MPI2_TA_EEDPFLAGS_INSERT_OP
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI2_TA_EEDPFLAGS_REPLACE_OP
value|(0x0006)
end_define

begin_define
define|#
directive|define
name|MPI2_TA_EEDPFLAGS_CHECK_REGEN_OP
value|(0x0007)
end_define

begin_comment
comment|/**************************************************************************** *   MPI v2.5 Target Assist Request ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI25_TARGET_ASSIST_REQUEST
block|{
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x00 */
name|U8
name|TargetAssistFlags
decl_stmt|;
comment|/* 0x01 */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|QueueTag
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
name|IoIndex
decl_stmt|;
comment|/* 0x0C */
name|U16
name|InitiatorConnectionTag
decl_stmt|;
comment|/* 0x0E */
name|U8
name|DMAFlags
decl_stmt|;
comment|/* 0x10 */
name|U8
name|Reserved9
decl_stmt|;
comment|/* 0x11 */
name|U8
name|SequenceNumber
decl_stmt|;
comment|/* 0x12 */
name|U8
name|Reserved4
decl_stmt|;
comment|/* 0x13 */
name|U8
name|SGLOffset0
decl_stmt|;
comment|/* 0x14 */
name|U8
name|SGLOffset1
decl_stmt|;
comment|/* 0x15 */
name|U8
name|SGLOffset2
decl_stmt|;
comment|/* 0x16 */
name|U8
name|SGLOffset3
decl_stmt|;
comment|/* 0x17 */
name|U32
name|SkipCount
decl_stmt|;
comment|/* 0x18 */
name|U32
name|DataLength
decl_stmt|;
comment|/* 0x1C */
name|U32
name|BidirectionalDataLength
decl_stmt|;
comment|/* 0x20 */
name|U16
name|IoFlags
decl_stmt|;
comment|/* 0x24 */
name|U16
name|EEDPFlags
decl_stmt|;
comment|/* 0x26 */
name|U16
name|EEDPBlockSize
decl_stmt|;
comment|/* 0x28 */
name|U16
name|Reserved10
decl_stmt|;
comment|/* 0x2A */
name|U32
name|SecondaryReferenceTag
decl_stmt|;
comment|/* 0x2C */
name|U16
name|SecondaryApplicationTag
decl_stmt|;
comment|/* 0x30 */
name|U16
name|ApplicationTagTranslationMask
decl_stmt|;
comment|/* 0x32 */
name|U32
name|PrimaryReferenceTag
decl_stmt|;
comment|/* 0x34 */
name|U16
name|PrimaryApplicationTag
decl_stmt|;
comment|/* 0x38 */
name|U16
name|PrimaryApplicationTagMask
decl_stmt|;
comment|/* 0x3A */
name|U32
name|RelativeOffset
decl_stmt|;
comment|/* 0x3C */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x40 */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 0x44 */
name|U32
name|Reserved7
decl_stmt|;
comment|/* 0x48 */
name|U32
name|Reserved8
decl_stmt|;
comment|/* 0x4C */
name|MPI25_SGE_IO_UNION
name|SGL
decl_stmt|;
comment|/* 0x50 */
block|}
name|MPI25_TARGET_ASSIST_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI25_TARGET_ASSIST_REQUEST
operator|,
name|Mpi25TargetAssistRequest_t
operator|,
name|MPI2_POINTER
name|pMpi25TargetAssistRequest_t
typedef|;
end_typedef

begin_comment
comment|/* use MPI2_TARGET_ASSIST_FLAGS_ defines for the Flags field */
end_comment

begin_comment
comment|/* Defines for the DMAFlags field  *  Each setting affects 4 SGLS, from SGL0 to SGL3.  *      D = Data  *      C = Cache DIF  *      I = Interleaved  *      H = Host DIF  */
end_comment

begin_define
define|#
directive|define
name|MPI25_TA_DMAFLAGS_OP_MASK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_DMAFLAGS_OP_D_D_D_D
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_DMAFLAGS_OP_D_D_D_C
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_DMAFLAGS_OP_D_D_D_I
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_DMAFLAGS_OP_D_D_C_C
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_DMAFLAGS_OP_D_D_C_I
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_DMAFLAGS_OP_D_D_I_I
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_DMAFLAGS_OP_D_C_C_C
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_DMAFLAGS_OP_D_C_C_I
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_DMAFLAGS_OP_D_C_I_I
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_DMAFLAGS_OP_D_I_I_I
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_DMAFLAGS_OP_D_H_D_D
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_DMAFLAGS_OP_D_H_D_C
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_DMAFLAGS_OP_D_H_D_I
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_DMAFLAGS_OP_D_H_C_C
value|(0x0D)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_DMAFLAGS_OP_D_H_C_I
value|(0x0E)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_DMAFLAGS_OP_D_H_I_I
value|(0x0F)
end_define

begin_comment
comment|/* defines for the IoFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI25_TARGET_ASSIST_IOFLAGS_BIDIRECTIONAL
value|(0x0800)
end_define

begin_define
define|#
directive|define
name|MPI25_TARGET_ASSIST_IOFLAGS_RECEIVE_FIRST
value|(0x0200)
end_define

begin_comment
comment|/* defines for the EEDPFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_INC_PRI_REFTAG
value|(0x8000)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_INC_SEC_REFTAG
value|(0x4000)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_INC_PRI_APPTAG
value|(0x2000)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_INC_SEC_APPTAG
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_CHECK_REFTAG
value|(0x0400)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_CHECK_APPTAG
value|(0x0200)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_CHECK_GUARD
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_ESCAPE_MODE_MASK
value|(0x00C0)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_COMPATIBLE_MODE
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_DO_NOT_DISABLE_MODE
value|(0x0040)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_APPTAG_DISABLE_MODE
value|(0x0080)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_APPTAG_REFTAG_DISABLE_MODE
value|(0x00C0)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_HOST_GUARD_METHOD_MASK
value|(0x0030)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_T10_CRC_HOST_GUARD
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_IP_CHKSUM_HOST_GUARD
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_PASSTHRU_REFTAG
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_MASK_OP
value|(0x0007)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_NOOP_OP
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_CHECK_OP
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_STRIP_OP
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_CHECK_REMOVE_OP
value|(0x0003)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_INSERT_OP
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_REPLACE_OP
value|(0x0006)
end_define

begin_define
define|#
directive|define
name|MPI25_TA_EEDPFLAGS_CHECK_REGEN_OP
value|(0x0007)
end_define

begin_comment
comment|/**************************************************************************** *  Target Status Send Request ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TARGET_STATUS_SEND_REQUEST
block|{
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x00 */
name|U8
name|StatusFlags
decl_stmt|;
comment|/* 0x01 */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|QueueTag
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
name|IoIndex
decl_stmt|;
comment|/* 0x0C */
name|U16
name|InitiatorConnectionTag
decl_stmt|;
comment|/* 0x0E */
name|U16
name|SGLFlags
decl_stmt|;
comment|/* 0x10 */
comment|/* MPI v2.0 only. Reserved on MPI v2.5. */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 0x12 */
name|U8
name|SGLOffset0
decl_stmt|;
comment|/* 0x14 */
name|U8
name|Reserved5
decl_stmt|;
comment|/* 0x15 */
name|U16
name|Reserved6
decl_stmt|;
comment|/* 0x16 */
name|U32
name|Reserved7
decl_stmt|;
comment|/* 0x18 */
name|U32
name|Reserved8
decl_stmt|;
comment|/* 0x1C */
name|MPI2_SIMPLE_SGE_UNION
name|StatusDataSGE
decl_stmt|;
comment|/* 0x20 */
comment|/* MPI v2.5: This must be an IEEE Simple Element 64. */
block|}
name|MPI2_TARGET_STATUS_SEND_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TARGET_STATUS_SEND_REQUEST
operator|,
name|Mpi2TargetStatusSendRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2TargetStatusSendRequest_t
typedef|;
end_typedef

begin_comment
comment|/* Target Status Send StatusFlags bits */
end_comment

begin_define
define|#
directive|define
name|MPI2_TSS_FLAGS_REPOST_CMD_BUFFER
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI2_TSS_FLAGS_RETRANSMIT
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_TSS_FLAGS_AUTO_GOOD_STATUS
value|(0x01)
end_define

begin_comment
comment|/* Target Status Send SGLFlags bits - MPI v2.0 only */
end_comment

begin_comment
comment|/* Data Location Address Space */
end_comment

begin_define
define|#
directive|define
name|MPI2_TSS_SGLFLAGS_ADDR_MASK
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI2_TSS_SGLFLAGS_SYSTEM_ADDR
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_TSS_SGLFLAGS_IOCDDR_ADDR
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_TSS_SGLFLAGS_IOCPLB_ADDR
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_TSS_SGLFLAGS_IOCPLBNTA_ADDR
value|(0x0C)
end_define

begin_comment
comment|/* Type */
end_comment

begin_define
define|#
directive|define
name|MPI2_TSS_SGLFLAGS_TYPE_MASK
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_TSS_SGLFLAGS_MPI_TYPE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_TSS_SGLFLAGS_IEEE32_TYPE
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_TSS_SGLFLAGS_IEEE64_TYPE
value|(0x02)
end_define

begin_comment
comment|/*  * NOTE: The SSP status IU is big-endian. When used on a little-endian system,  * this structure properly orders the bytes.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TARGET_SSP_RSP_IU
block|{
name|U32
name|Reserved0
index|[
literal|6
index|]
decl_stmt|;
comment|/* reserved for SSP header */
comment|/* 0x00 */
comment|/* start of RESPONSE information unit */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x18 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x1C */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x20 */
name|U8
name|DataPres
decl_stmt|;
comment|/* lower 2 bits */
comment|/* 0x22 */
name|U8
name|Status
decl_stmt|;
comment|/* 0x23 */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x24 */
name|U32
name|SenseDataLength
decl_stmt|;
comment|/* 0x28 */
name|U32
name|ResponseDataLength
decl_stmt|;
comment|/* 0x2C */
comment|/* start of Response or Sense Data (size may vary dynamically) */
name|U8
name|ResponseSenseData
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x30 */
block|}
name|MPI2_TARGET_SSP_RSP_IU
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TARGET_SSP_RSP_IU
operator|,
name|Mpi2TargetSspRspIu_t
operator|,
name|MPI2_POINTER
name|pMpi2TargetSspRspIu_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  Target Standard Reply - used with Target Assist or Target Status Send ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TARGET_STANDARD_REPLY
block|{
name|U16
name|Reserved
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
name|U16
name|IoIndex
decl_stmt|;
comment|/* 0x14 */
name|U16
name|Reserved5
decl_stmt|;
comment|/* 0x16 */
name|U32
name|TransferCount
decl_stmt|;
comment|/* 0x18 */
name|U32
name|BidirectionalTransferCount
decl_stmt|;
comment|/* 0x1C */
block|}
name|MPI2_TARGET_STANDARD_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TARGET_STANDARD_REPLY
operator|,
name|Mpi2TargetErrorReply_t
operator|,
name|MPI2_POINTER
name|pMpi2TargetErrorReply_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  Target Mode Abort Request ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TARGET_MODE_ABORT_REQUEST
block|{
name|U8
name|AbortType
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved3
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
name|Reserved4
decl_stmt|;
comment|/* 0x0A */
name|U16
name|IoIndexToAbort
decl_stmt|;
comment|/* 0x0C */
name|U16
name|InitiatorDevHandle
decl_stmt|;
comment|/* 0x0E */
name|U32
name|MidToAbort
decl_stmt|;
comment|/* 0x10 */
block|}
name|MPI2_TARGET_MODE_ABORT
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TARGET_MODE_ABORT
operator|,
name|Mpi2TargetModeAbort_t
operator|,
name|MPI2_POINTER
name|pMpi2TargetModeAbort_t
typedef|;
end_typedef

begin_comment
comment|/* Target Mode Abort AbortType values */
end_comment

begin_define
define|#
directive|define
name|MPI2_TARGET_MODE_ABORT_ALL_CMD_BUFFERS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_MODE_ABORT_ALL_IO
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_MODE_ABORT_EXACT_IO
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_MODE_ABORT_EXACT_IO_REQUEST
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_MODE_ABORT_IO_REQUEST_AND_IO
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_MODE_ABORT_DEVHANDLE
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_TARGET_MODE_ABORT_ALL_COMMANDS
value|(0x06)
end_define

begin_comment
comment|/**************************************************************************** *  Target Mode Abort Reply ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TARGET_MODE_ABORT_REPLY
block|{
name|U16
name|Reserved
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
name|AbortCount
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_TARGET_MODE_ABORT_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TARGET_MODE_ABORT_REPLY
operator|,
name|Mpi2TargetModeAbortReply_t
operator|,
name|MPI2_POINTER
name|pMpi2TargetModeAbortReply_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

