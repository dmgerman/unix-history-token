begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2000-2005, LSI Logic Corporation and its contributors.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon including  *    a substantially similar Disclaimer requirement for further binary  *    redistribution.  * 3. Neither the name of the LSI Logic Corporation nor the names of its  *    contributors may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF THE COPYRIGHT  * OWNER OR CONTRIBUTOR IS ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *  *           Name:  MPI_FC.H  *          Title:  MPI Fibre Channel messages and structures  *  Creation Date:  June 12, 2000  *  *    MPI_FC.H Version:  01.02.04  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  05-08-00  00.10.01  Original release for 0.10 spec dated 4/26/2000.  *  06-06-00  01.00.01  Update version number for 1.0 release.  *  06-12-00  01.00.02  Added _MSG_FC_ABORT_REPLY structure.  *  11-02-00  01.01.01  Original release for post 1.0 work  *  12-04-00  01.01.02  Added messages for Common Transport Send and  *                      Primitive Send.  *  01-09-01  01.01.03  Modifed some of the new flags to have an MPI prefix  *                      and modified the FcPrimitiveSend flags.  *  01-25-01  01.01.04  Move InitiatorIndex in LinkServiceRsp reply to a larger  *                      field.  *                      Added FC_ABORT_TYPE_CT_SEND_REQUEST and  *                      FC_ABORT_TYPE_EXLINKSEND_REQUEST for FcAbort request.  *                      Added MPI_FC_PRIM_SEND_FLAGS_STOP_SEND.  *  02-20-01  01.01.05  Started using MPI_POINTER.  *  03-27-01  01.01.06  Added Flags field to MSG_LINK_SERVICE_BUFFER_POST_REPLY  *                      and defined MPI_LS_BUF_POST_REPLY_FLAG_NO_RSP_NEEDED.  *                      Added MPI_FC_PRIM_SEND_FLAGS_RESET_LINK define.  *                      Added structure offset comments.  *  04-09-01  01.01.07  Added RspLength field to MSG_LINK_SERVICE_RSP_REQUEST.  *  08-08-01  01.02.01  Original release for v1.2 work.  *  09-28-01  01.02.02  Change name of reserved field in  *                      MSG_LINK_SERVICE_RSP_REPLY.  *  05-31-02  01.02.03  Adding AliasIndex to FC Direct Access requests.  *  01-16-04  01.02.04  Added define for MPI_FC_PRIM_SEND_FLAGS_ML_RESET_LINK.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_FC_H
end_ifndef

begin_define
define|#
directive|define
name|MPI_FC_H
end_define

begin_comment
comment|/***************************************************************************** * *        F C    T a r g e t    M o d e    M e s s a g e s * *****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Link Service Buffer Post messages                                        */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_LINK_SERVICE_BUFFER_POST_REQUEST
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
name|U16
name|Reserved
decl_stmt|;
comment|/* 04h */
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
name|SGE_TRANS_SIMPLE_UNION
name|SGL
decl_stmt|;
block|}
name|MSG_LINK_SERVICE_BUFFER_POST_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_LINK_SERVICE_BUFFER_POST_REQUEST
operator|,
name|LinkServiceBufferPostRequest_t
operator|,
name|MPI_POINTER
name|pLinkServiceBufferPostRequest_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LINK_SERVICE_BUFFER_POST_FLAGS_PORT_MASK
value|(0x01)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_WWNFORMAT
block|{
name|U32
name|PortNameHigh
decl_stmt|;
comment|/* 00h */
name|U32
name|PortNameLow
decl_stmt|;
comment|/* 04h */
name|U32
name|NodeNameHigh
decl_stmt|;
comment|/* 08h */
name|U32
name|NodeNameLow
decl_stmt|;
comment|/* 0Ch */
block|}
name|WWNFORMAT
operator|,
name|WwnFormat_t
typedef|;
end_typedef

begin_comment
comment|/* Link Service Buffer Post Reply */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_LINK_SERVICE_BUFFER_POST_REPLY
block|{
name|U8
name|Flags
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved
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
name|U16
name|Reserved1
decl_stmt|;
comment|/* 04h */
name|U8
name|PortNumber
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
name|U32
name|TransferLength
decl_stmt|;
comment|/* 14h */
name|U32
name|TransactionContext
decl_stmt|;
comment|/* 18h */
name|U32
name|Rctl_Did
decl_stmt|;
comment|/* 1Ch */
name|U32
name|Csctl_Sid
decl_stmt|;
comment|/* 20h */
name|U32
name|Type_Fctl
decl_stmt|;
comment|/* 24h */
name|U16
name|SeqCnt
decl_stmt|;
comment|/* 28h */
name|U8
name|Dfctl
decl_stmt|;
comment|/* 2Ah */
name|U8
name|SeqId
decl_stmt|;
comment|/* 2Bh */
name|U16
name|Rxid
decl_stmt|;
comment|/* 2Ch */
name|U16
name|Oxid
decl_stmt|;
comment|/* 2Eh */
name|U32
name|Parameter
decl_stmt|;
comment|/* 30h */
name|WWNFORMAT
name|Wwn
decl_stmt|;
comment|/* 34h */
block|}
name|MSG_LINK_SERVICE_BUFFER_POST_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_LINK_SERVICE_BUFFER_POST_REPLY
operator|,
name|LinkServiceBufferPostReply_t
operator|,
name|MPI_POINTER
name|pLinkServiceBufferPostReply_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_LS_BUF_POST_REPLY_FLAG_NO_RSP_NEEDED
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DID_MASK
value|(0x00FFFFFF)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DID_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_FC_RCTL_MASK
value|(0xFF000000)
end_define

begin_define
define|#
directive|define
name|MPI_FC_RCTL_SHIFT
value|(24)
end_define

begin_define
define|#
directive|define
name|MPI_FC_SID_MASK
value|(0x00FFFFFF)
end_define

begin_define
define|#
directive|define
name|MPI_FC_SID_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_FC_CSCTL_MASK
value|(0xFF000000)
end_define

begin_define
define|#
directive|define
name|MPI_FC_CSCTL_SHIFT
value|(24)
end_define

begin_define
define|#
directive|define
name|MPI_FC_FCTL_MASK
value|(0x00FFFFFF)
end_define

begin_define
define|#
directive|define
name|MPI_FC_FCTL_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_FC_TYPE_MASK
value|(0xFF000000)
end_define

begin_define
define|#
directive|define
name|MPI_FC_TYPE_SHIFT
value|(24)
end_define

begin_comment
comment|/* obsolete name for the above */
end_comment

begin_define
define|#
directive|define
name|FCP_TARGET_DID_MASK
value|(0x00FFFFFF)
end_define

begin_define
define|#
directive|define
name|FCP_TARGET_DID_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|FCP_TARGET_RCTL_MASK
value|(0xFF000000)
end_define

begin_define
define|#
directive|define
name|FCP_TARGET_RCTL_SHIFT
value|(24)
end_define

begin_define
define|#
directive|define
name|FCP_TARGET_SID_MASK
value|(0x00FFFFFF)
end_define

begin_define
define|#
directive|define
name|FCP_TARGET_SID_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|FCP_TARGET_CSCTL_MASK
value|(0xFF000000)
end_define

begin_define
define|#
directive|define
name|FCP_TARGET_CSCTL_SHIFT
value|(24)
end_define

begin_define
define|#
directive|define
name|FCP_TARGET_FCTL_MASK
value|(0x00FFFFFF)
end_define

begin_define
define|#
directive|define
name|FCP_TARGET_FCTL_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|FCP_TARGET_TYPE_MASK
value|(0xFF000000)
end_define

begin_define
define|#
directive|define
name|FCP_TARGET_TYPE_SHIFT
value|(24)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Link Service Response messages                                           */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_LINK_SERVICE_RSP_REQUEST
block|{
name|U8
name|RspFlags
decl_stmt|;
comment|/* 00h */
name|U8
name|RspLength
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
name|Rctl_Did
decl_stmt|;
comment|/* 0Ch */
name|U32
name|Csctl_Sid
decl_stmt|;
comment|/* 10h */
name|U32
name|Type_Fctl
decl_stmt|;
comment|/* 14h */
name|U16
name|SeqCnt
decl_stmt|;
comment|/* 18h */
name|U8
name|Dfctl
decl_stmt|;
comment|/* 1Ah */
name|U8
name|SeqId
decl_stmt|;
comment|/* 1Bh */
name|U16
name|Rxid
decl_stmt|;
comment|/* 1Ch */
name|U16
name|Oxid
decl_stmt|;
comment|/* 1Eh */
name|U32
name|Parameter
decl_stmt|;
comment|/* 20h */
name|SGE_SIMPLE_UNION
name|SGL
decl_stmt|;
comment|/* 24h */
block|}
name|MSG_LINK_SERVICE_RSP_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_LINK_SERVICE_RSP_REQUEST
operator|,
name|LinkServiceRspRequest_t
operator|,
name|MPI_POINTER
name|pLinkServiceRspRequest_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LINK_SERVICE_RSP_FLAGS_IMMEDIATE
value|(0x80)
end_define

begin_define
define|#
directive|define
name|LINK_SERVICE_RSP_FLAGS_PORT_MASK
value|(0x01)
end_define

begin_comment
comment|/* Link Service Response Reply  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_LINK_SERVICE_RSP_REPLY
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
name|Reserved_0100_InitiatorIndex
decl_stmt|;
comment|/* 06h */
comment|/* obsolete InitiatorIndex */
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
name|InitiatorIndex
decl_stmt|;
comment|/* 14h */
block|}
name|MSG_LINK_SERVICE_RSP_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_LINK_SERVICE_RSP_REPLY
operator|,
name|LinkServiceRspReply_t
operator|,
name|MPI_POINTER
name|pLinkServiceRspReply_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Extended Link Service Send messages                                      */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_EXLINK_SERVICE_SEND_REQUEST
block|{
name|U8
name|SendFlags
decl_stmt|;
comment|/* 00h */
name|U8
name|AliasIndex
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
name|U32
name|MsgFlags_Did
decl_stmt|;
comment|/* 04h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U32
name|ElsCommandCode
decl_stmt|;
comment|/* 0Ch */
name|SGE_SIMPLE_UNION
name|SGL
decl_stmt|;
comment|/* 10h */
block|}
name|MSG_EXLINK_SERVICE_SEND_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_EXLINK_SERVICE_SEND_REQUEST
operator|,
name|ExLinkServiceSendRequest_t
operator|,
name|MPI_POINTER
name|pExLinkServiceSendRequest_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EX_LINK_SERVICE_SEND_DID_MASK
value|(0x00FFFFFF)
end_define

begin_define
define|#
directive|define
name|EX_LINK_SERVICE_SEND_DID_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|EX_LINK_SERVICE_SEND_MSGFLAGS_MASK
value|(0xFF000000)
end_define

begin_define
define|#
directive|define
name|EX_LINK_SERVICE_SEND_MSGFLAGS_SHIFT
value|(24)
end_define

begin_comment
comment|/* Extended Link Service Send Reply */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_EXLINK_SERVICE_SEND_REPLY
block|{
name|U8
name|Reserved
decl_stmt|;
comment|/* 00h */
name|U8
name|AliasIndex
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
name|ResponseLength
decl_stmt|;
comment|/* 14h */
block|}
name|MSG_EXLINK_SERVICE_SEND_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_EXLINK_SERVICE_SEND_REPLY
operator|,
name|ExLinkServiceSendReply_t
operator|,
name|MPI_POINTER
name|pExLinkServiceSendReply_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* FC Abort messages                                                        */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_FC_ABORT_REQUEST
block|{
name|U8
name|AbortFlags
decl_stmt|;
comment|/* 00h */
name|U8
name|AbortType
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
name|TransactionContextToAbort
decl_stmt|;
comment|/* 0Ch */
block|}
name|MSG_FC_ABORT_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_FC_ABORT_REQUEST
operator|,
name|FcAbortRequest_t
operator|,
name|MPI_POINTER
name|pFcAbortRequest_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FC_ABORT_FLAG_PORT_MASK
value|(0x01)
end_define

begin_define
define|#
directive|define
name|FC_ABORT_TYPE_ALL_FC_BUFFERS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|FC_ABORT_TYPE_EXACT_FC_BUFFER
value|(0x01)
end_define

begin_define
define|#
directive|define
name|FC_ABORT_TYPE_CT_SEND_REQUEST
value|(0x02)
end_define

begin_define
define|#
directive|define
name|FC_ABORT_TYPE_EXLINKSEND_REQUEST
value|(0x03)
end_define

begin_comment
comment|/* FC Abort Reply */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_FC_ABORT_REPLY
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
block|}
name|MSG_FC_ABORT_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_FC_ABORT_REPLY
operator|,
name|FcAbortReply_t
operator|,
name|MPI_POINTER
name|pFcAbortReply_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* FC Common Transport Send messages                                        */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_FC_COMMON_TRANSPORT_SEND_REQUEST
block|{
name|U8
name|SendFlags
decl_stmt|;
comment|/* 00h */
name|U8
name|AliasIndex
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
name|U32
name|MsgFlags_Did
decl_stmt|;
comment|/* 04h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U16
name|CTCommandCode
decl_stmt|;
comment|/* 0Ch */
name|U8
name|FsType
decl_stmt|;
comment|/* 0Eh */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0Fh */
name|SGE_SIMPLE_UNION
name|SGL
decl_stmt|;
comment|/* 10h */
block|}
name|MSG_FC_COMMON_TRANSPORT_SEND_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_FC_COMMON_TRANSPORT_SEND_REQUEST
operator|,
name|FcCommonTransportSendRequest_t
operator|,
name|MPI_POINTER
name|pFcCommonTransportSendRequest_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_FC_CT_SEND_DID_MASK
value|(0x00FFFFFF)
end_define

begin_define
define|#
directive|define
name|MPI_FC_CT_SEND_DID_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_FC_CT_SEND_MSGFLAGS_MASK
value|(0xFF000000)
end_define

begin_define
define|#
directive|define
name|MPI_FC_CT_SEND_MSGFLAGS_SHIFT
value|(24)
end_define

begin_comment
comment|/* FC Common Transport Send Reply */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_FC_COMMON_TRANSPORT_SEND_REPLY
block|{
name|U8
name|Reserved
decl_stmt|;
comment|/* 00h */
name|U8
name|AliasIndex
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
name|ResponseLength
decl_stmt|;
comment|/* 14h */
block|}
name|MSG_FC_COMMON_TRANSPORT_SEND_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_FC_COMMON_TRANSPORT_SEND_REPLY
operator|,
name|FcCommonTransportSendReply_t
operator|,
name|MPI_POINTER
name|pFcCommonTransportSendReply_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* FC Primitive Send messages                                               */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_FC_PRIMITIVE_SEND_REQUEST
block|{
name|U8
name|SendFlags
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
name|U8
name|FcPrimitive
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0Ch */
block|}
name|MSG_FC_PRIMITIVE_SEND_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_FC_PRIMITIVE_SEND_REQUEST
operator|,
name|FcPrimitiveSendRequest_t
operator|,
name|MPI_POINTER
name|pFcPrimitiveSendRequest_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_FC_PRIM_SEND_FLAGS_PORT_MASK
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_FC_PRIM_SEND_FLAGS_ML_RESET_LINK
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_FC_PRIM_SEND_FLAGS_RESET_LINK
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_FC_PRIM_SEND_FLAGS_STOP_SEND
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_FC_PRIM_SEND_FLAGS_SEND_ONCE
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI_FC_PRIM_SEND_FLAGS_SEND_AROUND
value|(0x20)
end_define

begin_define
define|#
directive|define
name|MPI_FC_PRIM_SEND_FLAGS_UNTIL_FULL
value|(0x40)
end_define

begin_define
define|#
directive|define
name|MPI_FC_PRIM_SEND_FLAGS_FOREVER
value|(0x80)
end_define

begin_comment
comment|/* FC Primitive Send Reply */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_FC_PRIMITIVE_SEND_REPLY
block|{
name|U8
name|SendFlags
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved
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
block|}
name|MSG_FC_PRIMITIVE_SEND_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_FC_PRIMITIVE_SEND_REPLY
operator|,
name|FcPrimitiveSendReply_t
operator|,
name|MPI_POINTER
name|pFcPrimitiveSendReply_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

