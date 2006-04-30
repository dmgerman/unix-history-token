begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2000-2005, LSI Logic Corporation and its contributors.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon including  *    a substantially similar Disclaimer requirement for further binary  *    redistribution.  * 3. Neither the name of the LSI Logic Corporation nor the names of its  *    contributors may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF THE COPYRIGHT  * OWNER OR CONTRIBUTOR IS ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *  *           Name:  MPI_LAN.H  *          Title:  MPI LAN messages and structures  *  Creation Date:  June 30, 2000  *  *    MPI_LAN.H Version:  01.02.01  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  05-08-00  00.10.01  Original release for 0.10 spec dated 4/26/2000.  *  05-24-00  00.10.02  Added LANStatus field to _MSG_LAN_SEND_REPLY.  *                      Added LANStatus field to _MSG_LAN_RECEIVE_POST_REPLY.  *                      Moved ListCount field in _MSG_LAN_RECEIVE_POST_REPLY.  *  06-06-00  01.00.01  Update version number for 1.0 release.  *  06-12-00  01.00.02  Added MPI_ to BUCKETSTATUS_ definitions.  *  06-22-00  01.00.03  Major changes to match new LAN definition in 1.0 spec.  *  06-30-00  01.00.04  Added Context Reply definitions per revised proposal.  *                      Changed transaction context usage to bucket/buffer.  *  07-05-00  01.00.05  Removed LAN_RECEIVE_POST_BUCKET_CONTEXT_MASK definition  *                      to lan private header file  *  11-02-00  01.01.01  Original release for post 1.0 work  *  02-20-01  01.01.02  Started using MPI_POINTER.  *  03-27-01  01.01.03  Added structure offset comments.  *  08-08-01  01.02.01  Original release for v1.2 work.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_LAN_H
end_ifndef

begin_define
define|#
directive|define
name|MPI_LAN_H
end_define

begin_comment
comment|/****************************************************************************** * *               L A N    M e s s a g e s * *******************************************************************************/
end_comment

begin_comment
comment|/* LANSend messages */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_LAN_SEND_REQUEST
block|{
name|U16
name|Reserved
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
name|SGE_MPI_UNION
name|SG_List
index|[
literal|1
index|]
decl_stmt|;
comment|/* 0Ch */
block|}
name|MSG_LAN_SEND_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_LAN_SEND_REQUEST
operator|,
name|LANSendRequest_t
operator|,
name|MPI_POINTER
name|pLANSendRequest_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MSG_LAN_SEND_REPLY
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
name|U8
name|Reserved2
decl_stmt|;
comment|/* 04h */
name|U8
name|NumberOfContexts
decl_stmt|;
comment|/* 05h */
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
name|BufferContext
decl_stmt|;
comment|/* 14h */
block|}
name|MSG_LAN_SEND_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_LAN_SEND_REPLY
operator|,
name|LANSendReply_t
operator|,
name|MPI_POINTER
name|pLANSendReply_t
typedef|;
end_typedef

begin_comment
comment|/* LANReceivePost */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_LAN_RECEIVE_POST_REQUEST
block|{
name|U16
name|Reserved
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
name|U32
name|BucketCount
decl_stmt|;
comment|/* 0Ch */
name|SGE_MPI_UNION
name|SG_List
index|[
literal|1
index|]
decl_stmt|;
comment|/* 10h */
block|}
name|MSG_LAN_RECEIVE_POST_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_LAN_RECEIVE_POST_REQUEST
operator|,
name|LANReceivePostRequest_t
operator|,
name|MPI_POINTER
name|pLANReceivePostRequest_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MSG_LAN_RECEIVE_POST_REPLY
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
name|U8
name|Reserved2
decl_stmt|;
comment|/* 04h */
name|U8
name|NumberOfContexts
decl_stmt|;
comment|/* 05h */
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
name|BucketsRemaining
decl_stmt|;
comment|/* 14h */
name|U32
name|PacketOffset
decl_stmt|;
comment|/* 18h */
name|U32
name|PacketLength
decl_stmt|;
comment|/* 1Ch */
name|U32
name|BucketContext
index|[
literal|1
index|]
decl_stmt|;
comment|/* 20h */
block|}
name|MSG_LAN_RECEIVE_POST_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_LAN_RECEIVE_POST_REPLY
operator|,
name|LANReceivePostReply_t
operator|,
name|MPI_POINTER
name|pLANReceivePostReply_t
typedef|;
end_typedef

begin_comment
comment|/* LANReset */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_LAN_RESET_REQUEST
block|{
name|U16
name|Reserved
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
name|PortNumber
decl_stmt|;
comment|/* 05h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
block|}
name|MSG_LAN_RESET_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_LAN_RESET_REQUEST
operator|,
name|LANResetRequest_t
operator|,
name|MPI_POINTER
name|pLANResetRequest_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MSG_LAN_RESET_REPLY
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
name|Reserved2
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
name|MSG_LAN_RESET_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_LAN_RESET_REPLY
operator|,
name|LANResetReply_t
operator|,
name|MPI_POINTER
name|pLANResetReply_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* LAN Context Reply defines and macros                                     */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|LAN_REPLY_PACKET_LENGTH_MASK
value|(0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|LAN_REPLY_PACKET_LENGTH_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|LAN_REPLY_BUCKET_CONTEXT_MASK
value|(0x07FF0000)
end_define

begin_define
define|#
directive|define
name|LAN_REPLY_BUCKET_CONTEXT_SHIFT
value|(16)
end_define

begin_define
define|#
directive|define
name|LAN_REPLY_BUFFER_CONTEXT_MASK
value|(0x07FFFFFF)
end_define

begin_define
define|#
directive|define
name|LAN_REPLY_BUFFER_CONTEXT_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|LAN_REPLY_FORM_MASK
value|(0x18000000)
end_define

begin_define
define|#
directive|define
name|LAN_REPLY_FORM_RECEIVE_SINGLE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|LAN_REPLY_FORM_RECEIVE_MULTIPLE
value|(0x01)
end_define

begin_define
define|#
directive|define
name|LAN_REPLY_FORM_SEND_SINGLE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|LAN_REPLY_FORM_MESSAGE_CONTEXT
value|(0x03)
end_define

begin_define
define|#
directive|define
name|LAN_REPLY_FORM_SHIFT
value|(27)
end_define

begin_define
define|#
directive|define
name|GET_LAN_PACKET_LENGTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& LAN_REPLY_PACKET_LENGTH_MASK)   \>> LAN_REPLY_PACKET_LENGTH_SHIFT)
end_define

begin_define
define|#
directive|define
name|SET_LAN_PACKET_LENGTH
parameter_list|(
name|x
parameter_list|,
name|lth
parameter_list|)
define|\
value|((x) = ((x)& ~LAN_REPLY_PACKET_LENGTH_MASK) |                  \                             (((lth)<< LAN_REPLY_PACKET_LENGTH_SHIFT)&     \                                         LAN_REPLY_PACKET_LENGTH_MASK))
end_define

begin_define
define|#
directive|define
name|GET_LAN_BUCKET_CONTEXT
parameter_list|(
name|x
parameter_list|)
value|(((x)& LAN_REPLY_BUCKET_CONTEXT_MASK)  \>> LAN_REPLY_BUCKET_CONTEXT_SHIFT)
end_define

begin_define
define|#
directive|define
name|SET_LAN_BUCKET_CONTEXT
parameter_list|(
name|x
parameter_list|,
name|ctx
parameter_list|)
define|\
value|((x) = ((x)& ~LAN_REPLY_BUCKET_CONTEXT_MASK) |                 \                             (((ctx)<< LAN_REPLY_BUCKET_CONTEXT_SHIFT)&    \                                         LAN_REPLY_BUCKET_CONTEXT_MASK))
end_define

begin_define
define|#
directive|define
name|GET_LAN_BUFFER_CONTEXT
parameter_list|(
name|x
parameter_list|)
value|(((x)& LAN_REPLY_BUFFER_CONTEXT_MASK)  \>> LAN_REPLY_BUFFER_CONTEXT_SHIFT)
end_define

begin_define
define|#
directive|define
name|SET_LAN_BUFFER_CONTEXT
parameter_list|(
name|x
parameter_list|,
name|ctx
parameter_list|)
define|\
value|((x) = ((x)& ~LAN_REPLY_BUFFER_CONTEXT_MASK) |                 \                             (((ctx)<< LAN_REPLY_BUFFER_CONTEXT_SHIFT)&    \                                         LAN_REPLY_BUFFER_CONTEXT_MASK))
end_define

begin_define
define|#
directive|define
name|GET_LAN_FORM
parameter_list|(
name|x
parameter_list|)
value|(((x)& LAN_REPLY_FORM_MASK)            \>> LAN_REPLY_FORM_SHIFT)
end_define

begin_define
define|#
directive|define
name|SET_LAN_FORM
parameter_list|(
name|x
parameter_list|,
name|frm
parameter_list|)
define|\
value|((x) = ((x)& ~LAN_REPLY_FORM_MASK) |                           \                             (((frm)<< LAN_REPLY_FORM_SHIFT)&              \                                         LAN_REPLY_FORM_MASK))
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* LAN Current Device State defines                                         */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI_LAN_DEVICE_STATE_RESET
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_LAN_DEVICE_STATE_OPERATIONAL
value|(0x01)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* LAN Loopback defines                                                     */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI_LAN_TX_MODES_ENABLE_LOOPBACK_SUPPRESSION
value|(0x01)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

