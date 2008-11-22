begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2000-2005, LSI Logic Corporation and its contributors.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon including  *    a substantially similar Disclaimer requirement for further binary  *    redistribution.  * 3. Neither the name of the LSI Logic Corporation nor the names of its  *    contributors may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF THE COPYRIGHT  * OWNER OR CONTRIBUTOR IS ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *  *           Name:  mpi_tool.h  *          Title:  MPI Toolbox structures and definitions  *  Creation Date:  July 30, 2001  *  *    mpi_tool.h Version:  01.05.03  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  08-08-01  01.02.01  Original release.  *  08-29-01  01.02.02  Added DIAG_DATA_UPLOAD_HEADER and related defines.  *  01-16-04  01.02.03  Added defines and structures for new tools  *.                     MPI_TOOLBOX_ISTWI_READ_WRITE_TOOL and  *                      MPI_TOOLBOX_FC_MANAGEMENT_TOOL.  *  04-29-04  01.02.04  Added message structures for Diagnostic Buffer Post and  *                      Diagnostic Release requests and replies.  *  05-11-04  01.03.01  Original release for MPI v1.3.  *  08-19-04  01.05.01  Original release for MPI v1.5.  *  10-06-04  01.05.02  Added define for MPI_DIAG_BUF_TYPE_COUNT.  *  02-09-05  01.05.03  Added frame size option to FC management tool.  *                      Added Beacon tool to the Toolbox.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_TOOL_H
end_ifndef

begin_define
define|#
directive|define
name|MPI_TOOL_H
end_define

begin_define
define|#
directive|define
name|MPI_TOOLBOX_CLEAN_TOOL
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_TOOLBOX_MEMORY_MOVE_TOOL
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_TOOLBOX_DIAG_DATA_UPLOAD_TOOL
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_TOOLBOX_ISTWI_READ_WRITE_TOOL
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_TOOLBOX_FC_MANAGEMENT_TOOL
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_TOOLBOX_BEACON_TOOL
value|(0x05)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Toolbox reply                                                            */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_TOOLBOX_REPLY
block|{
name|U8
name|Tool
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
name|MSG_TOOLBOX_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_TOOLBOX_REPLY
operator|,
name|ToolboxReply_t
operator|,
name|MPI_POINTER
name|pToolboxReply_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Toolbox Clean Tool request                                               */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_TOOLBOX_CLEAN_REQUEST
block|{
name|U8
name|Tool
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
name|Flags
decl_stmt|;
comment|/* 0Ch */
block|}
name|MSG_TOOLBOX_CLEAN_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_TOOLBOX_CLEAN_REQUEST
operator|,
name|ToolboxCleanRequest_t
operator|,
name|MPI_POINTER
name|pToolboxCleanRequest_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_TOOLBOX_CLEAN_NVSRAM
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_TOOLBOX_CLEAN_SEEPROM
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_TOOLBOX_CLEAN_FLASH
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_TOOLBOX_CLEAN_BOOTLOADER
value|(0x04000000)
end_define

begin_define
define|#
directive|define
name|MPI_TOOLBOX_CLEAN_FW_BACKUP
value|(0x08000000)
end_define

begin_define
define|#
directive|define
name|MPI_TOOLBOX_CLEAN_FW_CURRENT
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|MPI_TOOLBOX_CLEAN_OTHER_PERSIST_PAGES
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|MPI_TOOLBOX_CLEAN_PERSIST_MANUFACT_PAGES
value|(0x40000000)
end_define

begin_define
define|#
directive|define
name|MPI_TOOLBOX_CLEAN_BOOT_SERVICES
value|(0x80000000)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Toolbox Memory Move request                                              */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_TOOLBOX_MEM_MOVE_REQUEST
block|{
name|U8
name|Tool
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
name|SGE_SIMPLE_UNION
name|SGL
decl_stmt|;
comment|/* 0Ch */
block|}
name|MSG_TOOLBOX_MEM_MOVE_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_TOOLBOX_MEM_MOVE_REQUEST
operator|,
name|ToolboxMemMoveRequest_t
operator|,
name|MPI_POINTER
name|pToolboxMemMoveRequest_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Toolbox Diagnostic Data Upload request                                   */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_TOOLBOX_DIAG_DATA_UPLOAD_REQUEST
block|{
name|U8
name|Tool
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
name|Flags
decl_stmt|;
comment|/* 0Ch */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 10h */
name|SGE_SIMPLE_UNION
name|SGL
decl_stmt|;
comment|/* 14h */
block|}
name|MSG_TOOLBOX_DIAG_DATA_UPLOAD_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_TOOLBOX_DIAG_DATA_UPLOAD_REQUEST
operator|,
name|ToolboxDiagDataUploadRequest_t
operator|,
name|MPI_POINTER
name|pToolboxDiagDataUploadRequest_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_DIAG_DATA_UPLOAD_HEADER
block|{
name|U32
name|DiagDataLength
decl_stmt|;
comment|/* 00h */
name|U8
name|FormatCode
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 05h */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 06h */
block|}
name|DIAG_DATA_UPLOAD_HEADER
operator|,
name|MPI_POINTER
name|PTR_DIAG_DATA_UPLOAD_HEADER
operator|,
name|DiagDataUploadHeader_t
operator|,
name|MPI_POINTER
name|pDiagDataUploadHeader_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_TB_DIAG_FORMAT_SCSI_PRINTF_1
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_TB_DIAG_FORMAT_SCSI_2
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_TB_DIAG_FORMAT_SCSI_3
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_TB_DIAG_FORMAT_FC_TRACE_1
value|(0x04)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Toolbox ISTWI Read Write request                                         */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_TOOLBOX_ISTWI_READ_WRITE_REQUEST
block|{
name|U8
name|Tool
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
name|Flags
decl_stmt|;
comment|/* 0Ch */
name|U8
name|BusNum
decl_stmt|;
comment|/* 0Dh */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0Eh */
name|U8
name|NumAddressBytes
decl_stmt|;
comment|/* 10h */
name|U8
name|Reserved4
decl_stmt|;
comment|/* 11h */
name|U16
name|DataLength
decl_stmt|;
comment|/* 12h */
name|U8
name|DeviceAddr
decl_stmt|;
comment|/* 14h */
name|U8
name|Addr1
decl_stmt|;
comment|/* 15h */
name|U8
name|Addr2
decl_stmt|;
comment|/* 16h */
name|U8
name|Addr3
decl_stmt|;
comment|/* 17h */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 18h */
name|SGE_SIMPLE_UNION
name|SGL
decl_stmt|;
comment|/* 1Ch */
block|}
name|MSG_TOOLBOX_ISTWI_READ_WRITE_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_TOOLBOX_ISTWI_READ_WRITE_REQUEST
operator|,
name|ToolboxIstwiReadWriteRequest_t
operator|,
name|MPI_POINTER
name|pToolboxIstwiReadWriteRequest_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_TB_ISTWI_FLAGS_WRITE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_TB_ISTWI_FLAGS_READ
value|(0x01)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Toolbox FC Management request                                            */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ActionInfo for Bus and TargetId */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI_TB_FC_MANAGE_BUS_TID_AI
block|{
name|U16
name|Reserved
decl_stmt|;
comment|/* 00h */
name|U8
name|Bus
decl_stmt|;
comment|/* 02h */
name|U8
name|TargetId
decl_stmt|;
comment|/* 03h */
block|}
name|MPI_TB_FC_MANAGE_BUS_TID_AI
operator|,
name|MPI_POINTER
name|PTR_MPI_TB_FC_MANAGE_BUS_TID_AI
operator|,
name|MpiTbFcManageBusTidAi_t
operator|,
name|MPI_POINTER
name|pMpiTbFcManageBusTidAi_t
typedef|;
end_typedef

begin_comment
comment|/* ActionInfo for port identifier */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI_TB_FC_MANAGE_PID_AI
block|{
name|U32
name|PortIdentifier
decl_stmt|;
comment|/* 00h */
block|}
name|MPI_TB_FC_MANAGE_PID_AI
operator|,
name|MPI_POINTER
name|PTR_MPI_TB_FC_MANAGE_PID_AI
operator|,
name|MpiTbFcManagePidAi_t
operator|,
name|MPI_POINTER
name|pMpiTbFcManagePidAi_t
typedef|;
end_typedef

begin_comment
comment|/* ActionInfo for set max frame size */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI_TB_FC_MANAGE_FRAME_SIZE_AI
block|{
name|U16
name|FrameSize
decl_stmt|;
comment|/* 00h */
name|U8
name|PortNum
decl_stmt|;
comment|/* 02h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 03h */
block|}
name|MPI_TB_FC_MANAGE_FRAME_SIZE_AI
operator|,
name|MPI_POINTER
name|PTR_MPI_TB_FC_MANAGE_FRAME_SIZE_AI
operator|,
name|MpiTbFcManageFrameSizeAi_t
operator|,
name|MPI_POINTER
name|pMpiTbFcManageFrameSizeAi_t
typedef|;
end_typedef

begin_comment
comment|/* union of ActionInfo */
end_comment

begin_typedef
typedef|typedef
union|union
name|_MPI_TB_FC_MANAGE_AI_UNION
block|{
name|MPI_TB_FC_MANAGE_BUS_TID_AI
name|BusTid
decl_stmt|;
name|MPI_TB_FC_MANAGE_PID_AI
name|Port
decl_stmt|;
name|MPI_TB_FC_MANAGE_FRAME_SIZE_AI
name|FrameSize
decl_stmt|;
block|}
name|MPI_TB_FC_MANAGE_AI_UNION
operator|,
name|MPI_POINTER
name|PTR_MPI_TB_FC_MANAGE_AI_UNION
operator|,
name|MpiTbFcManageAiUnion_t
operator|,
name|MPI_POINTER
name|pMpiTbFcManageAiUnion_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MSG_TOOLBOX_FC_MANAGE_REQUEST
block|{
name|U8
name|Tool
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
name|Action
decl_stmt|;
comment|/* 0Ch */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 0Dh */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 0Eh */
name|MPI_TB_FC_MANAGE_AI_UNION
name|ActionInfo
decl_stmt|;
comment|/* 10h */
block|}
name|MSG_TOOLBOX_FC_MANAGE_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_TOOLBOX_FC_MANAGE_REQUEST
operator|,
name|ToolboxFcManageRequest_t
operator|,
name|MPI_POINTER
name|pToolboxFcManageRequest_t
typedef|;
end_typedef

begin_comment
comment|/* defines for the Action field */
end_comment

begin_define
define|#
directive|define
name|MPI_TB_FC_MANAGE_ACTION_DISC_ALL
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_TB_FC_MANAGE_ACTION_DISC_PID
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_TB_FC_MANAGE_ACTION_DISC_BUS_TID
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_TB_FC_MANAGE_ACTION_SET_MAX_FRAME_SIZE
value|(0x03)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Toolbox Beacon Tool request                                               */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_TOOLBOX_BEACON_REQUEST
block|{
name|U8
name|Tool
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
name|ConnectNum
decl_stmt|;
comment|/* 0Ch */
name|U8
name|PortNum
decl_stmt|;
comment|/* 0Dh */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 0Eh */
name|U8
name|Flags
decl_stmt|;
comment|/* 0Fh */
block|}
name|MSG_TOOLBOX_BEACON_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_TOOLBOX_BEACON_REQUEST
operator|,
name|ToolboxBeaconRequest_t
operator|,
name|MPI_POINTER
name|pToolboxBeaconRequest_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_TOOLBOX_FLAGS_BEACON_MODE_OFF
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_TOOLBOX_FLAGS_BEACON_MODE_ON
value|(0x01)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Diagnostic Buffer Post request                                           */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_DIAG_BUFFER_POST_REQUEST
block|{
name|U8
name|TraceLevel
decl_stmt|;
comment|/* 00h */
name|U8
name|BufferType
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
name|ExtendedType
decl_stmt|;
comment|/* 0Ch */
name|U32
name|BufferLength
decl_stmt|;
comment|/* 10h */
name|U32
name|ProductSpecific
index|[
literal|4
index|]
decl_stmt|;
comment|/* 14h */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 24h */
name|U64
name|BufferAddress
decl_stmt|;
comment|/* 28h */
block|}
name|MSG_DIAG_BUFFER_POST_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_DIAG_BUFFER_POST_REQUEST
operator|,
name|DiagBufferPostRequest_t
operator|,
name|MPI_POINTER
name|pDiagBufferPostRequest_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_DIAG_BUF_TYPE_TRACE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_DIAG_BUF_TYPE_SNAPSHOT
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_DIAG_BUF_TYPE_EXTENDED
value|(0x02)
end_define

begin_comment
comment|/* count of the number of buffer types */
end_comment

begin_define
define|#
directive|define
name|MPI_DIAG_BUF_TYPE_COUNT
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_DIAG_EXTENDED_QTAG
value|(0x00000001)
end_define

begin_comment
comment|/* Diagnostic Buffer Post reply */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_DIAG_BUFFER_POST_REPLY
block|{
name|U8
name|Reserved1
decl_stmt|;
comment|/* 00h */
name|U8
name|BufferType
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
name|U32
name|TransferLength
decl_stmt|;
comment|/* 14h */
block|}
name|MSG_DIAG_BUFFER_POST_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_DIAG_BUFFER_POST_REPLY
operator|,
name|DiagBufferPostReply_t
operator|,
name|MPI_POINTER
name|pDiagBufferPostReply_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Diagnostic Release request                                               */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_DIAG_RELEASE_REQUEST
block|{
name|U8
name|Reserved1
decl_stmt|;
comment|/* 00h */
name|U8
name|BufferType
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
block|}
name|MSG_DIAG_RELEASE_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_DIAG_RELEASE_REQUEST
operator|,
name|DiagReleaseRequest_t
operator|,
name|MPI_POINTER
name|pDiagReleaseRequest_t
typedef|;
end_typedef

begin_comment
comment|/* Diagnostic Release reply */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_DIAG_RELEASE_REPLY
block|{
name|U8
name|Reserved1
decl_stmt|;
comment|/* 00h */
name|U8
name|BufferType
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
name|MSG_DIAG_RELEASE_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_DIAG_RELEASE_REPLY
operator|,
name|DiagReleaseReply_t
operator|,
name|MPI_POINTER
name|pDiagReleaseReply_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

