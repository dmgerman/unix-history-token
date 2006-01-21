begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2000-2005, LSI Logic Corporation and its contributors.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon including  *    a substantially similar Disclaimer requirement for further binary  *    redistribution.  * 3. Neither the name of the LSI Logic Corporation nor the names of its  *    contributors may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF THE COPYRIGHT  * OWNER OR CONTRIBUTOR IS ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. /*  *  Copyright (c) 2003-2004 LSI Logic Corporation.  *  *  *           Name:  mpi_inb.h  *          Title:  MPI Inband structures and definitions  *  Creation Date:  September 30, 2003  *  *    mpi_inb.h Version:  01.05.01  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  05-11-04  01.03.01  Original release.  *  08-19-04  01.05.01  Original release for MPI v1.5.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_INB_H
end_ifndef

begin_define
define|#
directive|define
name|MPI_INB_H
end_define

begin_comment
comment|/****************************************************************************** * *        I n b a n d    M e s s a g e s * *******************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Inband Buffer Post Request                                               */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_INBAND_BUFFER_POST_REQUEST
block|{
name|U8
name|Reserved1
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
name|Reserved2
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved3
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
name|Reserved4
decl_stmt|;
comment|/* 0Ch */
name|SGE_TRANS_SIMPLE_UNION
name|SGL
decl_stmt|;
comment|/* 10h */
block|}
name|MSG_INBAND_BUFFER_POST_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_INBAND_BUFFER_POST_REQUEST
operator|,
name|MpiInbandBufferPostRequest_t
operator|,
name|MPI_POINTER
name|pMpiInbandBufferPostRequest_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_WWN_FC_FORMAT
block|{
name|U64
name|NodeName
decl_stmt|;
comment|/* 00h */
name|U64
name|PortName
decl_stmt|;
comment|/* 08h */
block|}
name|WWN_FC_FORMAT
operator|,
name|MPI_POINTER
name|PTR_WWN_FC_FORMAT
operator|,
name|WwnFcFormat_t
operator|,
name|MPI_POINTER
name|pWwnFcFormat_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_WWN_SAS_FORMAT
block|{
name|U64
name|WorldWideID
decl_stmt|;
comment|/* 00h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 08h */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0Ch */
block|}
name|WWN_SAS_FORMAT
operator|,
name|MPI_POINTER
name|PTR_WWN_SAS_FORMAT
operator|,
name|WwnSasFormat_t
operator|,
name|MPI_POINTER
name|pWwnSasFormat_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_WWN_INBAND_FORMAT
block|{
name|WWN_FC_FORMAT
name|Fc
decl_stmt|;
name|WWN_SAS_FORMAT
name|Sas
decl_stmt|;
block|}
name|WWN_INBAND_FORMAT
operator|,
name|MPI_POINTER
name|PTR_WWN_INBAND_FORMAT
operator|,
name|WwnInbandFormat
operator|,
name|MPI_POINTER
name|pWwnInbandFormat
typedef|;
end_typedef

begin_comment
comment|/* Inband Buffer Post reply message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_INBAND_BUFFER_POST_REPLY
block|{
name|U16
name|Reserved1
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
name|Reserved2
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved3
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
name|Reserved4
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
name|WWN_INBAND_FORMAT
name|Wwn
decl_stmt|;
comment|/* 1Ch */
name|U32
name|IOCIdentifier
index|[
literal|4
index|]
decl_stmt|;
comment|/* 2Ch */
block|}
name|MSG_INBAND_BUFFER_POST_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_INBAND_BUFFER_POST_REPLY
operator|,
name|MpiInbandBufferPostReply_t
operator|,
name|MPI_POINTER
name|pMpiInbandBufferPostReply_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Inband Send Request                                                      */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_INBAND_SEND_REQUEST
block|{
name|U16
name|Reserved1
decl_stmt|;
comment|/* 00h */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved3
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
name|Reserved4
decl_stmt|;
comment|/* 0Ch */
name|WWN_INBAND_FORMAT
name|Wwn
decl_stmt|;
comment|/* 10h */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 20h */
name|SGE_IO_UNION
name|SGL
decl_stmt|;
comment|/* 24h */
block|}
name|MSG_INBAND_SEND_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_INBAND_SEND_REQUEST
operator|,
name|MpiInbandSendRequest_t
operator|,
name|MPI_POINTER
name|pMpiInbandSendRequest_t
typedef|;
end_typedef

begin_comment
comment|/* Inband Send reply message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_INBAND_SEND_REPLY
block|{
name|U16
name|Reserved1
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
name|Reserved2
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved3
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
name|Reserved4
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
name|MSG_INBAND_SEND_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_INBAND_SEND_REPLY
operator|,
name|MpiInbandSendReply_t
operator|,
name|MPI_POINTER
name|pMpiInbandSendReply_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Inband Response Request                                                  */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_INBAND_RSP_REQUEST
block|{
name|U16
name|Reserved1
decl_stmt|;
comment|/* 00h */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved3
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
name|Reserved4
decl_stmt|;
comment|/* 0Ch */
name|WWN_INBAND_FORMAT
name|Wwn
decl_stmt|;
comment|/* 10h */
name|U32
name|IOCIdentifier
index|[
literal|4
index|]
decl_stmt|;
comment|/* 20h */
name|U32
name|ResponseLength
decl_stmt|;
comment|/* 30h */
name|SGE_IO_UNION
name|SGL
decl_stmt|;
comment|/* 34h */
block|}
name|MSG_INBAND_RSP_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_INBAND_RSP_REQUEST
operator|,
name|MpiInbandRspRequest_t
operator|,
name|MPI_POINTER
name|pMpiInbandRspRequest_t
typedef|;
end_typedef

begin_comment
comment|/* Inband Response reply message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_INBAND_RSP_REPLY
block|{
name|U16
name|Reserved1
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
name|Reserved2
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved3
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
name|Reserved4
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
name|MSG_INBAND_RSP_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_INBAND_RSP_REPLY
operator|,
name|MpiInbandRspReply_t
operator|,
name|MPI_POINTER
name|pMpiInbandRspReply_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Inband Abort Request                                                     */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_INBAND_ABORT_REQUEST
block|{
name|U8
name|Reserved1
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
name|Reserved2
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved3
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
name|Reserved4
decl_stmt|;
comment|/* 0Ch */
name|U32
name|ContextToAbort
decl_stmt|;
comment|/* 10h */
block|}
name|MSG_INBAND_ABORT_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_INBAND_ABORT_REQUEST
operator|,
name|MpiInbandAbortRequest_t
operator|,
name|MPI_POINTER
name|pMpiInbandAbortRequest_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_INBAND_ABORT_TYPE_ALL_BUFFERS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_INBAND_ABORT_TYPE_EXACT_BUFFER
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_INBAND_ABORT_TYPE_SEND_REQUEST
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_INBAND_ABORT_TYPE_RESPONSE_REQUEST
value|(0x03)
end_define

begin_comment
comment|/* Inband Abort reply message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_INBAND_ABORT_REPLY
block|{
name|U8
name|Reserved1
decl_stmt|;
comment|/* 00h */
name|U8
name|AbortType
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
name|Reserved2
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved3
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
name|Reserved4
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
name|MSG_INBAND_ABORT_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_INBAND_ABORT_REPLY
operator|,
name|MpiInbandAbortReply_t
operator|,
name|MPI_POINTER
name|pMpiInbandAbortReply_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

