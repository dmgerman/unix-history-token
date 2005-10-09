begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2000-2005, LSI Logic Corporation and its contributors.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon including  *    a substantially similar Disclaimer requirement for further binary  *    redistribution.  * 3. Neither the name of the LSI Logic Corporation nor the names of its  *    contributors may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF THE COPYRIGHT  * OWNER OR CONTRIBUTOR IS ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *  *           Name:  MPI_TARG.H  *          Title:  MPI Target mode messages and structures  *  Creation Date:  June 22, 2000  *  *    MPI_TARG.H Version:  01.02.09  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  05-08-00  00.10.01  Original release for 0.10 spec dated 4/26/2000.  *  06-06-00  01.00.01  Update version number for 1.0 release.  *  06-22-00  01.00.02  Added _MSG_TARGET_CMD_BUFFER_POST_REPLY structure.  *                      Corrected DECSRIPTOR typo to DESCRIPTOR.  *  11-02-00  01.01.01  Original release for post 1.0 work  *                      Modified target mode to use IoIndex instead of  *                      HostIndex and IocIndex. Added Alias.  *  01-09-01  01.01.02  Added defines for TARGET_ASSIST_FLAGS_REPOST_CMD_BUFFER  *                      and TARGET_STATUS_SEND_FLAGS_REPOST_CMD_BUFFER.  *  02-20-01  01.01.03  Started using MPI_POINTER.  *                      Added structures for MPI_TARGET_SCSI_SPI_CMD_BUFFER and  *                      MPI_TARGET_FCP_CMD_BUFFER.  *  03-27-01  01.01.04  Added structure offset comments.  *  08-08-01  01.02.01  Original release for v1.2 work.  *  09-28-01  01.02.02  Added structure for MPI_TARGET_SCSI_SPI_STATUS_IU.  *                      Added PriorityReason field to some replies and  *                      defined more PriorityReason codes.  *                      Added some defines for to support previous version  *                      of MPI.  *  10-04-01  01.02.03  Added PriorityReason to MSG_TARGET_ERROR_REPLY.  *  11-01-01  01.02.04  Added define for TARGET_STATUS_SEND_FLAGS_HIGH_PRIORITY.  *  03-14-02  01.02.05  Modified MPI_TARGET_FCP_RSP_BUFFER to get the proper  *                      byte ordering.  *  05-31-02  01.02.06  Modified TARGET_MODE_REPLY_ALIAS_MASK to only include  *                      one bit.  *                      Added AliasIndex field to MPI_TARGET_FCP_CMD_BUFFER.  *  09-16-02  01.02.07  Added flags for confirmed completion.  *                      Added PRIORITY_REASON_TARGET_BUSY.  *  11-15-02  01.02.08  Added AliasID field to MPI_TARGET_SCSI_SPI_CMD_BUFFER.  *  04-01-03  01.02.09  Added OptionalOxid field to MPI_TARGET_FCP_CMD_BUFFER.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_TARG_H
end_ifndef

begin_define
define|#
directive|define
name|MPI_TARG_H
end_define

begin_comment
comment|/****************************************************************************** * *        S C S I    T a r g e t    M e s s a g e s * *******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CMD_BUFFER_DESCRIPTOR
block|{
name|U16
name|IoIndex
decl_stmt|;
comment|/* 00h */
name|U16
name|Reserved
decl_stmt|;
comment|/* 02h */
union|union
comment|/* 04h */
block|{
name|U32
name|PhysicalAddress32
decl_stmt|;
name|U64
name|PhysicalAddress64
decl_stmt|;
block|}
name|u
union|;
block|}
name|CMD_BUFFER_DESCRIPTOR
operator|,
name|MPI_POINTER
name|PTR_CMD_BUFFER_DESCRIPTOR
operator|,
name|CmdBufferDescriptor_t
operator|,
name|MPI_POINTER
name|pCmdBufferDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Target Command Buffer Post Request                                       */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_TARGET_CMD_BUFFER_POST_REQUEST
block|{
name|U8
name|BufferPostFlags
decl_stmt|;
comment|/* 00h */
name|U8
name|BufferCount
decl_stmt|;
comment|/* 01h */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U8
name|BufferLength
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 05h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|CMD_BUFFER_DESCRIPTOR
name|Buffer
index|[
literal|1
index|]
decl_stmt|;
comment|/* 0Ch */
block|}
name|MSG_TARGET_CMD_BUFFER_POST_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_TARGET_CMD_BUFFER_POST_REQUEST
operator|,
name|TargetCmdBufferPostRequest_t
operator|,
name|MPI_POINTER
name|pTargetCmdBufferPostRequest_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CMD_BUFFER_POST_FLAGS_PORT_MASK
value|(0x01)
end_define

begin_define
define|#
directive|define
name|CMD_BUFFER_POST_FLAGS_ADDR_MODE_MASK
value|(0x80)
end_define

begin_define
define|#
directive|define
name|CMD_BUFFER_POST_FLAGS_ADDR_MODE_32
value|(0)
end_define

begin_define
define|#
directive|define
name|CMD_BUFFER_POST_FLAGS_ADDR_MODE_64
value|(1)
end_define

begin_define
define|#
directive|define
name|CMD_BUFFER_POST_FLAGS_64_BIT_ADDR
value|(0x80)
end_define

begin_define
define|#
directive|define
name|CMD_BUFFER_POST_IO_INDEX_MASK
value|(0x00003FFF)
end_define

begin_define
define|#
directive|define
name|CMD_BUFFER_POST_IO_INDEX_MASK_0100
value|(0x000003FF)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_TARGET_CMD_BUFFER_POST_REPLY
block|{
name|U8
name|BufferPostFlags
decl_stmt|;
comment|/* 00h */
name|U8
name|BufferCount
decl_stmt|;
comment|/* 01h */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U8
name|BufferLength
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 05h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0Ch */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0Eh */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 10h */
block|}
name|MSG_TARGET_CMD_BUFFER_POST_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_TARGET_CMD_BUFFER_POST_REPLY
operator|,
name|TargetCmdBufferPostReply_t
operator|,
name|MPI_POINTER
name|pTargetCmdBufferPostReply_t
typedef|;
end_typedef

begin_comment
comment|/* the following structure is obsolete as of MPI v1.2 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_PRIORITY_CMD_RECEIVED_REPLY
block|{
name|U16
name|Reserved
decl_stmt|;
comment|/* 00h */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U8
name|PriorityReason
decl_stmt|;
comment|/* 0Ch */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 0Dh */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0Eh */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 10h */
name|U32
name|ReplyWord
decl_stmt|;
comment|/* 14h */
block|}
name|MSG_PRIORITY_CMD_RECEIVED_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_PRIORITY_CMD_RECEIVED_REPLY
operator|,
name|PriorityCommandReceivedReply_t
operator|,
name|MPI_POINTER
name|pPriorityCommandReceivedReply_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PRIORITY_REASON_NO_DISCONNECT
value|(0x00)
end_define

begin_define
define|#
directive|define
name|PRIORITY_REASON_SCSI_TASK_MANAGEMENT
value|(0x01)
end_define

begin_define
define|#
directive|define
name|PRIORITY_REASON_CMD_PARITY_ERR
value|(0x02)
end_define

begin_define
define|#
directive|define
name|PRIORITY_REASON_MSG_OUT_PARITY_ERR
value|(0x03)
end_define

begin_define
define|#
directive|define
name|PRIORITY_REASON_LQ_CRC_ERR
value|(0x04)
end_define

begin_define
define|#
directive|define
name|PRIORITY_REASON_CMD_CRC_ERR
value|(0x05)
end_define

begin_define
define|#
directive|define
name|PRIORITY_REASON_PROTOCOL_ERR
value|(0x06)
end_define

begin_define
define|#
directive|define
name|PRIORITY_REASON_DATA_OUT_PARITY_ERR
value|(0x07)
end_define

begin_define
define|#
directive|define
name|PRIORITY_REASON_DATA_OUT_CRC_ERR
value|(0x08)
end_define

begin_define
define|#
directive|define
name|PRIORITY_REASON_TARGET_BUSY
value|(0x09)
end_define

begin_define
define|#
directive|define
name|PRIORITY_REASON_UNKNOWN
value|(0xFF)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MSG_TARGET_CMD_BUFFER_POST_ERROR_REPLY
block|{
name|U16
name|Reserved
decl_stmt|;
comment|/* 00h */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U8
name|PriorityReason
decl_stmt|;
comment|/* 0Ch */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 0Dh */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0Eh */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 10h */
name|U32
name|ReplyWord
decl_stmt|;
comment|/* 14h */
block|}
name|MSG_TARGET_CMD_BUFFER_POST_ERROR_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_TARGET_CMD_BUFFER_POST_ERROR_REPLY
operator|,
name|TargetCmdBufferPostErrorReply_t
operator|,
name|MPI_POINTER
name|pTargetCmdBufferPostErrorReply_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI_TARGET_FCP_CMD_BUFFER
block|{
name|U8
name|FcpLun
index|[
literal|8
index|]
decl_stmt|;
comment|/* 00h */
name|U8
name|FcpCntl
index|[
literal|4
index|]
decl_stmt|;
comment|/* 08h */
name|U8
name|FcpCdb
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0Ch */
name|U32
name|FcpDl
decl_stmt|;
comment|/* 1Ch */
name|U8
name|AliasIndex
decl_stmt|;
comment|/* 20h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 21h */
name|U16
name|OptionalOxid
decl_stmt|;
comment|/* 22h */
block|}
name|MPI_TARGET_FCP_CMD_BUFFER
operator|,
name|MPI_POINTER
name|PTR_MPI_TARGET_FCP_CMD_BUFFER
operator|,
name|MpiTargetFcpCmdBuffer
operator|,
name|MPI_POINTER
name|pMpiTargetFcpCmdBuffer
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI_TARGET_SCSI_SPI_CMD_BUFFER
block|{
comment|/* SPI L_Q information unit */
name|U8
name|L_QType
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 01h */
name|U16
name|Tag
decl_stmt|;
comment|/* 02h */
name|U8
name|LogicalUnitNumber
index|[
literal|8
index|]
decl_stmt|;
comment|/* 04h */
name|U32
name|DataLength
decl_stmt|;
comment|/* 0Ch */
comment|/* SPI command information unit */
name|U8
name|ReservedFirstByteOfCommandIU
decl_stmt|;
comment|/* 10h */
name|U8
name|TaskAttribute
decl_stmt|;
comment|/* 11h */
name|U8
name|TaskManagementFlags
decl_stmt|;
comment|/* 12h */
name|U8
name|AdditionalCDBLength
decl_stmt|;
comment|/* 13h */
name|U8
name|CDB
index|[
literal|16
index|]
decl_stmt|;
comment|/* 14h */
comment|/* Alias ID */
name|U8
name|AliasID
decl_stmt|;
comment|/* 24h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 25h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 26h */
block|}
name|MPI_TARGET_SCSI_SPI_CMD_BUFFER
operator|,
name|MPI_POINTER
name|PTR_MPI_TARGET_SCSI_SPI_CMD_BUFFER
operator|,
name|MpiTargetScsiSpiCmdBuffer
operator|,
name|MPI_POINTER
name|pMpiTargetScsiSpiCmdBuffer
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Target Assist Request                                                    */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_TARGET_ASSIST_REQUEST
block|{
name|U8
name|StatusCode
decl_stmt|;
comment|/* 00h */
name|U8
name|TargetAssistFlags
decl_stmt|;
comment|/* 01h */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U16
name|QueueTag
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U32
name|ReplyWord
decl_stmt|;
comment|/* 0Ch */
name|U8
name|LUN
index|[
literal|8
index|]
decl_stmt|;
comment|/* 10h */
name|U32
name|RelativeOffset
decl_stmt|;
comment|/* 18h */
name|U32
name|DataLength
decl_stmt|;
comment|/* 1Ch */
name|SGE_IO_UNION
name|SGL
index|[
literal|1
index|]
decl_stmt|;
comment|/* 20h */
block|}
name|MSG_TARGET_ASSIST_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_TARGET_ASSIST_REQUEST
operator|,
name|TargetAssistRequest_t
operator|,
name|MPI_POINTER
name|pTargetAssistRequest_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TARGET_ASSIST_FLAGS_DATA_DIRECTION
value|(0x01)
end_define

begin_define
define|#
directive|define
name|TARGET_ASSIST_FLAGS_AUTO_STATUS
value|(0x02)
end_define

begin_define
define|#
directive|define
name|TARGET_ASSIST_FLAGS_HIGH_PRIORITY
value|(0x04)
end_define

begin_define
define|#
directive|define
name|TARGET_ASSIST_FLAGS_CONFIRMED
value|(0x08)
end_define

begin_define
define|#
directive|define
name|TARGET_ASSIST_FLAGS_REPOST_CMD_BUFFER
value|(0x80)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MSG_TARGET_ERROR_REPLY
block|{
name|U16
name|Reserved
decl_stmt|;
comment|/* 00h */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U8
name|PriorityReason
decl_stmt|;
comment|/* 0Ch */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 0Dh */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0Eh */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 10h */
name|U32
name|ReplyWord
decl_stmt|;
comment|/* 14h */
name|U32
name|TransferCount
decl_stmt|;
comment|/* 18h */
block|}
name|MSG_TARGET_ERROR_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_TARGET_ERROR_REPLY
operator|,
name|TargetErrorReply_t
operator|,
name|MPI_POINTER
name|pTargetErrorReply_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Target Status Send Request                                               */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_TARGET_STATUS_SEND_REQUEST
block|{
name|U8
name|StatusCode
decl_stmt|;
comment|/* 00h */
name|U8
name|StatusFlags
decl_stmt|;
comment|/* 01h */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U16
name|QueueTag
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U32
name|ReplyWord
decl_stmt|;
comment|/* 0Ch */
name|U8
name|LUN
index|[
literal|8
index|]
decl_stmt|;
comment|/* 10h */
name|SGE_SIMPLE_UNION
name|StatusDataSGE
decl_stmt|;
comment|/* 18h */
block|}
name|MSG_TARGET_STATUS_SEND_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_TARGET_STATUS_SEND_REQUEST
operator|,
name|TargetStatusSendRequest_t
operator|,
name|MPI_POINTER
name|pTargetStatusSendRequest_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TARGET_STATUS_SEND_FLAGS_AUTO_GOOD_STATUS
value|(0x01)
end_define

begin_define
define|#
directive|define
name|TARGET_STATUS_SEND_FLAGS_HIGH_PRIORITY
value|(0x04)
end_define

begin_define
define|#
directive|define
name|TARGET_STATUS_SEND_FLAGS_CONFIRMED
value|(0x08)
end_define

begin_define
define|#
directive|define
name|TARGET_STATUS_SEND_FLAGS_REPOST_CMD_BUFFER
value|(0x80)
end_define

begin_comment
comment|/*  * NOTE: FCP_RSP data is big-endian. When used on a little-endian system, this  * structure properly orders the bytes.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI_TARGET_FCP_RSP_BUFFER
block|{
name|U8
name|Reserved0
index|[
literal|8
index|]
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved1
index|[
literal|2
index|]
decl_stmt|;
comment|/* 08h */
name|U8
name|FcpFlags
decl_stmt|;
comment|/* 0Ah */
name|U8
name|FcpStatus
decl_stmt|;
comment|/* 0Bh */
name|U32
name|FcpResid
decl_stmt|;
comment|/* 0Ch */
name|U32
name|FcpSenseLength
decl_stmt|;
comment|/* 10h */
name|U32
name|FcpResponseLength
decl_stmt|;
comment|/* 14h */
name|U8
name|FcpResponseData
index|[
literal|8
index|]
decl_stmt|;
comment|/* 18h */
name|U8
name|FcpSenseData
index|[
literal|32
index|]
decl_stmt|;
comment|/* Pad to 64 bytes */
comment|/* 20h */
block|}
name|MPI_TARGET_FCP_RSP_BUFFER
operator|,
name|MPI_POINTER
name|PTR_MPI_TARGET_FCP_RSP_BUFFER
operator|,
name|MpiTargetFcpRspBuffer
operator|,
name|MPI_POINTER
name|pMpiTargetFcpRspBuffer
typedef|;
end_typedef

begin_comment
comment|/*  * NOTE: The SPI status IU is big-endian. When used on a little-endian system,  * this structure properly orders the bytes.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI_TARGET_SCSI_SPI_STATUS_IU
block|{
name|U8
name|Reserved0
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 01h */
name|U8
name|Valid
decl_stmt|;
comment|/* 02h */
name|U8
name|Status
decl_stmt|;
comment|/* 03h */
name|U32
name|SenseDataListLength
decl_stmt|;
comment|/* 04h */
name|U32
name|PktFailuresListLength
decl_stmt|;
comment|/* 08h */
name|U8
name|SenseData
index|[
literal|52
index|]
decl_stmt|;
comment|/* Pad the IU to 64 bytes */
comment|/* 0Ch */
block|}
name|MPI_TARGET_SCSI_SPI_STATUS_IU
operator|,
name|MPI_POINTER
name|PTR_MPI_TARGET_SCSI_SPI_STATUS_IU
operator|,
name|TargetScsiSpiStatusIU_t
operator|,
name|MPI_POINTER
name|pTargetScsiSpiStatusIU_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Target Mode Abort Request                                                */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_TARGET_MODE_ABORT_REQUEST
block|{
name|U8
name|AbortType
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 01h */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U32
name|ReplyWord
decl_stmt|;
comment|/* 0Ch */
name|U32
name|MsgContextToAbort
decl_stmt|;
comment|/* 10h */
block|}
name|MSG_TARGET_MODE_ABORT
operator|,
name|MPI_POINTER
name|PTR_MSG_TARGET_MODE_ABORT
operator|,
name|TargetModeAbort_t
operator|,
name|MPI_POINTER
name|pTargetModeAbort_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TARGET_MODE_ABORT_TYPE_ALL_CMD_BUFFERS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|TARGET_MODE_ABORT_TYPE_ALL_IO
value|(0x01)
end_define

begin_define
define|#
directive|define
name|TARGET_MODE_ABORT_TYPE_EXACT_IO
value|(0x02)
end_define

begin_define
define|#
directive|define
name|TARGET_MODE_ABORT_TYPE_EXACT_IO_REQUEST
value|(0x03)
end_define

begin_comment
comment|/* Target Mode Abort Reply */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_TARGET_MODE_ABORT_REPLY
block|{
name|U16
name|Reserved
decl_stmt|;
comment|/* 00h */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0Ch */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0Eh */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 10h */
name|U32
name|AbortCount
decl_stmt|;
comment|/* 14h */
block|}
name|MSG_TARGET_MODE_ABORT_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_TARGET_MODE_ABORT_REPLY
operator|,
name|TargetModeAbortReply_t
operator|,
name|MPI_POINTER
name|pTargetModeAbortReply_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Target Mode Context Reply                                                */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|TARGET_MODE_REPLY_IO_INDEX_MASK
value|(0x00003FFF)
end_define

begin_define
define|#
directive|define
name|TARGET_MODE_REPLY_IO_INDEX_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|TARGET_MODE_REPLY_INITIATOR_INDEX_MASK
value|(0x03FFC000)
end_define

begin_define
define|#
directive|define
name|TARGET_MODE_REPLY_INITIATOR_INDEX_SHIFT
value|(14)
end_define

begin_define
define|#
directive|define
name|TARGET_MODE_REPLY_ALIAS_MASK
value|(0x04000000)
end_define

begin_define
define|#
directive|define
name|TARGET_MODE_REPLY_ALIAS_SHIFT
value|(26)
end_define

begin_define
define|#
directive|define
name|TARGET_MODE_REPLY_PORT_MASK
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|TARGET_MODE_REPLY_PORT_SHIFT
value|(28)
end_define

begin_define
define|#
directive|define
name|GET_IO_INDEX
parameter_list|(
name|x
parameter_list|)
value|(((x)& TARGET_MODE_REPLY_IO_INDEX_MASK)           \>> TARGET_MODE_REPLY_IO_INDEX_SHIFT)
end_define

begin_define
define|#
directive|define
name|SET_IO_INDEX
parameter_list|(
name|t
parameter_list|,
name|i
parameter_list|)
define|\
value|((t) = ((t)& ~TARGET_MODE_REPLY_IO_INDEX_MASK) |                  \                               (((i)<< TARGET_MODE_REPLY_IO_INDEX_SHIFT)&     \                                              TARGET_MODE_REPLY_IO_INDEX_MASK))
end_define

begin_define
define|#
directive|define
name|GET_INITIATOR_INDEX
parameter_list|(
name|x
parameter_list|)
value|(((x)& TARGET_MODE_REPLY_INITIATOR_INDEX_MASK) \>> TARGET_MODE_REPLY_INITIATOR_INDEX_SHIFT)
end_define

begin_define
define|#
directive|define
name|SET_INITIATOR_INDEX
parameter_list|(
name|t
parameter_list|,
name|ii
parameter_list|)
define|\
value|((t) = ((t)& ~TARGET_MODE_REPLY_INITIATOR_INDEX_MASK) |               \                         (((ii)<< TARGET_MODE_REPLY_INITIATOR_INDEX_SHIFT)&   \                                       TARGET_MODE_REPLY_INITIATOR_INDEX_MASK))
end_define

begin_define
define|#
directive|define
name|GET_ALIAS
parameter_list|(
name|x
parameter_list|)
value|(((x)& TARGET_MODE_REPLY_ALIAS_MASK)                     \>> TARGET_MODE_REPLY_ALIAS_SHIFT)
end_define

begin_define
define|#
directive|define
name|SET_ALIAS
parameter_list|(
name|t
parameter_list|,
name|a
parameter_list|)
value|((t) = ((t)& ~TARGET_MODE_REPLY_ALIAS_MASK) |        \                                     (((a)<< TARGET_MODE_REPLY_ALIAS_SHIFT)&  \                                                  TARGET_MODE_REPLY_ALIAS_MASK))
end_define

begin_define
define|#
directive|define
name|GET_PORT
parameter_list|(
name|x
parameter_list|)
value|(((x)& TARGET_MODE_REPLY_PORT_MASK)                       \>> TARGET_MODE_REPLY_PORT_SHIFT)
end_define

begin_define
define|#
directive|define
name|SET_PORT
parameter_list|(
name|t
parameter_list|,
name|p
parameter_list|)
value|((t) = ((t)& ~TARGET_MODE_REPLY_PORT_MASK) |          \                                     (((p)<< TARGET_MODE_REPLY_PORT_SHIFT)&   \                                                   TARGET_MODE_REPLY_PORT_MASK))
end_define

begin_comment
comment|/* the following obsolete values are for MPI v1.0 support */
end_comment

begin_define
define|#
directive|define
name|TARGET_MODE_REPLY_0100_MASK_HOST_INDEX
value|(0x000003FF)
end_define

begin_define
define|#
directive|define
name|TARGET_MODE_REPLY_0100_SHIFT_HOST_INDEX
value|(0)
end_define

begin_define
define|#
directive|define
name|TARGET_MODE_REPLY_0100_MASK_IOC_INDEX
value|(0x001FF800)
end_define

begin_define
define|#
directive|define
name|TARGET_MODE_REPLY_0100_SHIFT_IOC_INDEX
value|(11)
end_define

begin_define
define|#
directive|define
name|TARGET_MODE_REPLY_0100_PORT_MASK
value|(0x00400000)
end_define

begin_define
define|#
directive|define
name|TARGET_MODE_REPLY_0100_PORT_SHIFT
value|(22)
end_define

begin_define
define|#
directive|define
name|TARGET_MODE_REPLY_0100_MASK_INITIATOR_INDEX
value|(0x1F800000)
end_define

begin_define
define|#
directive|define
name|TARGET_MODE_REPLY_0100_SHIFT_INITIATOR_INDEX
value|(23)
end_define

begin_define
define|#
directive|define
name|GET_HOST_INDEX_0100
parameter_list|(
name|x
parameter_list|)
value|(((x)& TARGET_MODE_REPLY_0100_MASK_HOST_INDEX) \>> TARGET_MODE_REPLY_0100_SHIFT_HOST_INDEX)
end_define

begin_define
define|#
directive|define
name|SET_HOST_INDEX_0100
parameter_list|(
name|t
parameter_list|,
name|hi
parameter_list|)
define|\
value|((t) = ((t)& ~TARGET_MODE_REPLY_0100_MASK_HOST_INDEX) |           \                          (((hi)<< TARGET_MODE_REPLY_0100_SHIFT_HOST_INDEX)&  \                                       TARGET_MODE_REPLY_0100_MASK_HOST_INDEX))
end_define

begin_define
define|#
directive|define
name|GET_IOC_INDEX_0100
parameter_list|(
name|x
parameter_list|)
value|(((x)& TARGET_MODE_REPLY_0100_MASK_IOC_INDEX) \>> TARGET_MODE_REPLY_0100_SHIFT_IOC_INDEX)
end_define

begin_define
define|#
directive|define
name|SET_IOC_INDEX_0100
parameter_list|(
name|t
parameter_list|,
name|ii
parameter_list|)
define|\
value|((t) = ((t)& ~TARGET_MODE_REPLY_0100_MASK_IOC_INDEX) |            \                         (((ii)<< TARGET_MODE_REPLY_0100_SHIFT_IOC_INDEX)&    \                                      TARGET_MODE_REPLY_0100_MASK_IOC_INDEX))
end_define

begin_define
define|#
directive|define
name|GET_INITIATOR_INDEX_0100
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& TARGET_MODE_REPLY_0100_MASK_INITIATOR_INDEX)               \>> TARGET_MODE_REPLY_0100_SHIFT_INITIATOR_INDEX)
end_define

begin_define
define|#
directive|define
name|SET_INITIATOR_INDEX_0100
parameter_list|(
name|t
parameter_list|,
name|ii
parameter_list|)
define|\
value|((t) = ((t)& ~TARGET_MODE_REPLY_0100_MASK_INITIATOR_INDEX) |          \                    (((ii)<< TARGET_MODE_REPLY_0100_SHIFT_INITIATOR_INDEX)&   \                                 TARGET_MODE_REPLY_0100_MASK_INITIATOR_INDEX))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

