begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012-2015 LSI Corp.  * Copyright (c) 2013-2016 Avago Technologies  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Avago Technologies (LSI) MPT-Fusion Host Adapter FreeBSD  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  Copyright (c) 2000-2015 LSI Corporation.  *  Copyright (c) 2013-2016 Avago Technologies  *  All rights reserved.  *  *  *           Name:  mpi2_tool.h  *          Title:  MPI diagnostic tool structures and definitions  *  Creation Date:  March 26, 2007  *  *    mpi2_tool.h Version:  02.00.14  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  04-30-07  02.00.00  Corresponds to Fusion-MPT MPI Specification Rev A.  *  12-18-07  02.00.01  Added Diagnostic Buffer Post and Diagnostic Release  *                      structures and defines.  *  02-29-08  02.00.02  Modified various names to make them 32-character unique.  *  05-06-09  02.00.03  Added ISTWI Read Write Tool and Diagnostic CLI Tool.  *  07-30-09  02.00.04  Added ExtendedType field to DiagnosticBufferPost request  *                      and reply messages.  *                      Added MPI2_DIAG_BUF_TYPE_EXTENDED.  *                      Incremented MPI2_DIAG_BUF_TYPE_COUNT.  *  05-12-10  02.00.05  Added Diagnostic Data Upload tool.  *  08-11-10  02.00.06  Added defines that were missing for Diagnostic Buffer  *                      Post Request.  *  05-25-11  02.00.07  Added Flags field and related defines to  *                      MPI2_TOOLBOX_ISTWI_READ_WRITE_REQUEST.  *  11-18-11  02.00.08  Incorporating additions for MPI v2.5.  *  07-10-12  02.00.09  Add MPI v2.5 Toolbox Diagnostic CLI Tool Request  *                      message.  *  07-26-12  02.00.10  Modified MPI2_TOOLBOX_DIAGNOSTIC_CLI_REQUEST so that  *                      it uses MPI Chain SGE as well as MPI Simple SGE.  *  08-19-13  02.00.11  Added MPI2_TOOLBOX_TEXT_DISPLAY_TOOL and related info.  *  01-08-14  02.00.12  Added MPI2_TOOLBOX_CLEAN_BIT26_PRODUCT_SPECIFIC.  *  11-18-14  02.00.13  Updated copyright information.  *  08-25-16  02.00.14  Added new values for the Flags field of Toolbox Clean  *                      Tool Request Message.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_TOOL_H
end_ifndef

begin_define
define|#
directive|define
name|MPI2_TOOL_H
end_define

begin_comment
comment|/***************************************************************************** * *               Toolbox Messages * *****************************************************************************/
end_comment

begin_comment
comment|/* defines for the Tools */
end_comment

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CLEAN_TOOL
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_MEMORY_MOVE_TOOL
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_DIAG_DATA_UPLOAD_TOOL
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_ISTWI_READ_WRITE_TOOL
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_BEACON_TOOL
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_DIAGNOSTIC_CLI_TOOL
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_TEXT_DISPLAY_TOOL
value|(0x07)
end_define

begin_comment
comment|/**************************************************************************** *  Toolbox reply ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TOOLBOX_REPLY
block|{
name|U8
name|Tool
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
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
name|Reserved5
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
block|}
name|MPI2_TOOLBOX_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TOOLBOX_REPLY
operator|,
name|Mpi2ToolboxReply_t
operator|,
name|MPI2_POINTER
name|pMpi2ToolboxReply_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  Toolbox Clean Tool request ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TOOLBOX_CLEAN_REQUEST
block|{
name|U8
name|Tool
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
name|U32
name|Flags
decl_stmt|;
comment|/* 0x0C */
block|}
name|MPI2_TOOLBOX_CLEAN_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TOOLBOX_CLEAN_REQUEST
operator|,
name|Mpi2ToolboxCleanRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2ToolboxCleanRequest_t
typedef|;
end_typedef

begin_comment
comment|/* values for the Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CLEAN_BOOT_SERVICES
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CLEAN_PERSIST_MANUFACT_PAGES
value|(0x40000000)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CLEAN_OTHER_PERSIST_PAGES
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CLEAN_FW_CURRENT
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CLEAN_FW_BACKUP
value|(0x08000000)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CLEAN_BIT26_PRODUCT_SPECIFIC
value|(0x04000000)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CLEAN_MEGARAID
value|(0x02000000)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CLEAN_INITIALIZATION
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CLEAN_SBR
value|(0x00800000)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CLEAN_SBR_BACKUP
value|(0x00400000)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CLEAN_HIIM
value|(0x00200000)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CLEAN_HIIA
value|(0x00100000)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CLEAN_CTLR
value|(0x00080000)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CLEAN_IMR_FIRMWARE
value|(0x00040000)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CLEAN_MR_NVDATA
value|(0x00020000)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CLEAN_RESERVED_5_16
value|(0x0001FFE0)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CLEAN_ALL_BUT_MPB
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CLEAN_ENTIRE_FLASH
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CLEAN_FLASH
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CLEAN_SEEPROM
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CLEAN_NVSRAM
value|(0x00000001)
end_define

begin_comment
comment|/**************************************************************************** *  Toolbox Memory Move request ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TOOLBOX_MEM_MOVE_REQUEST
block|{
name|U8
name|Tool
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
name|MPI2_SGE_SIMPLE_UNION
name|SGL
decl_stmt|;
comment|/* 0x0C */
block|}
name|MPI2_TOOLBOX_MEM_MOVE_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TOOLBOX_MEM_MOVE_REQUEST
operator|,
name|Mpi2ToolboxMemMoveRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2ToolboxMemMoveRequest_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  Toolbox Diagnostic Data Upload request ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TOOLBOX_DIAG_DATA_UPLOAD_REQUEST
block|{
name|U8
name|Tool
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
name|U8
name|SGLFlags
decl_stmt|;
comment|/* 0x0C */
name|U8
name|Reserved5
decl_stmt|;
comment|/* 0x0D */
name|U16
name|Reserved6
decl_stmt|;
comment|/* 0x0E */
name|U32
name|Flags
decl_stmt|;
comment|/* 0x10 */
name|U32
name|DataLength
decl_stmt|;
comment|/* 0x14 */
name|MPI2_SGE_SIMPLE_UNION
name|SGL
decl_stmt|;
comment|/* 0x18 */
block|}
name|MPI2_TOOLBOX_DIAG_DATA_UPLOAD_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TOOLBOX_DIAG_DATA_UPLOAD_REQUEST
operator|,
name|Mpi2ToolboxDiagDataUploadRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2ToolboxDiagDataUploadRequest_t
typedef|;
end_typedef

begin_comment
comment|/* use MPI2_SGLFLAGS_ defines from mpi2.h for the SGLFlags field */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_DIAG_DATA_UPLOAD_HEADER
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
name|Reserved1
decl_stmt|;
comment|/* 05h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 06h */
block|}
name|MPI2_DIAG_DATA_UPLOAD_HEADER
operator|,
name|MPI2_POINTER
name|PTR_MPI2_DIAG_DATA_UPLOAD_HEADER
operator|,
name|Mpi2DiagDataUploadHeader_t
operator|,
name|MPI2_POINTER
name|pMpi2DiagDataUploadHeader_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  Toolbox ISTWI Read Write Tool ****************************************************************************/
end_comment

begin_comment
comment|/* Toolbox ISTWI Read Write Tool request message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TOOLBOX_ISTWI_READ_WRITE_REQUEST
block|{
name|U8
name|Tool
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
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x0C */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 0x10 */
name|U8
name|DevIndex
decl_stmt|;
comment|/* 0x14 */
name|U8
name|Action
decl_stmt|;
comment|/* 0x15 */
name|U8
name|SGLFlags
decl_stmt|;
comment|/* 0x16 */
name|U8
name|Flags
decl_stmt|;
comment|/* 0x17 */
name|U16
name|TxDataLength
decl_stmt|;
comment|/* 0x18 */
name|U16
name|RxDataLength
decl_stmt|;
comment|/* 0x1A */
name|U32
name|Reserved8
decl_stmt|;
comment|/* 0x1C */
name|U32
name|Reserved9
decl_stmt|;
comment|/* 0x20 */
name|U32
name|Reserved10
decl_stmt|;
comment|/* 0x24 */
name|U32
name|Reserved11
decl_stmt|;
comment|/* 0x28 */
name|U32
name|Reserved12
decl_stmt|;
comment|/* 0x2C */
name|MPI2_SGE_SIMPLE_UNION
name|SGL
decl_stmt|;
comment|/* 0x30 */
block|}
name|MPI2_TOOLBOX_ISTWI_READ_WRITE_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TOOLBOX_ISTWI_READ_WRITE_REQUEST
operator|,
name|Mpi2ToolboxIstwiReadWriteRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2ToolboxIstwiReadWriteRequest_t
typedef|;
end_typedef

begin_comment
comment|/* values for the Action field */
end_comment

begin_define
define|#
directive|define
name|MPI2_TOOL_ISTWI_ACTION_READ_DATA
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOL_ISTWI_ACTION_WRITE_DATA
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOL_ISTWI_ACTION_SEQUENCE
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOL_ISTWI_ACTION_RESERVE_BUS
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOL_ISTWI_ACTION_RELEASE_BUS
value|(0x11)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOL_ISTWI_ACTION_RESET
value|(0x12)
end_define

begin_comment
comment|/* use MPI2_SGLFLAGS_ defines from mpi2.h for the SGLFlags field */
end_comment

begin_comment
comment|/* values for the Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_TOOL_ISTWI_FLAG_AUTO_RESERVE_RELEASE
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOL_ISTWI_FLAG_PAGE_ADDR_MASK
value|(0x07)
end_define

begin_comment
comment|/* Toolbox ISTWI Read Write Tool reply message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TOOLBOX_ISTWI_REPLY
block|{
name|U8
name|Tool
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
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
name|Reserved5
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
name|U8
name|DevIndex
decl_stmt|;
comment|/* 0x14 */
name|U8
name|Action
decl_stmt|;
comment|/* 0x15 */
name|U8
name|IstwiStatus
decl_stmt|;
comment|/* 0x16 */
name|U8
name|Reserved6
decl_stmt|;
comment|/* 0x17 */
name|U16
name|TxDataCount
decl_stmt|;
comment|/* 0x18 */
name|U16
name|RxDataCount
decl_stmt|;
comment|/* 0x1A */
block|}
name|MPI2_TOOLBOX_ISTWI_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TOOLBOX_ISTWI_REPLY
operator|,
name|Mpi2ToolboxIstwiReply_t
operator|,
name|MPI2_POINTER
name|pMpi2ToolboxIstwiReply_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  Toolbox Beacon Tool request ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TOOLBOX_BEACON_REQUEST
block|{
name|U8
name|Tool
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
name|U8
name|Reserved5
decl_stmt|;
comment|/* 0x0C */
name|U8
name|PhysicalPort
decl_stmt|;
comment|/* 0x0D */
name|U8
name|Reserved6
decl_stmt|;
comment|/* 0x0E */
name|U8
name|Flags
decl_stmt|;
comment|/* 0x0F */
block|}
name|MPI2_TOOLBOX_BEACON_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TOOLBOX_BEACON_REQUEST
operator|,
name|Mpi2ToolboxBeaconRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2ToolboxBeaconRequest_t
typedef|;
end_typedef

begin_comment
comment|/* values for the Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_FLAGS_BEACONMODE_OFF
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_FLAGS_BEACONMODE_ON
value|(0x01)
end_define

begin_comment
comment|/**************************************************************************** *  Toolbox Diagnostic CLI Tool ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_DIAG_CLI_CMD_LENGTH
value|(0x5C)
end_define

begin_comment
comment|/* MPI v2.0 Toolbox Diagnostic CLI Tool request message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TOOLBOX_DIAGNOSTIC_CLI_REQUEST
block|{
name|U8
name|Tool
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
name|U8
name|SGLFlags
decl_stmt|;
comment|/* 0x0C */
name|U8
name|Reserved5
decl_stmt|;
comment|/* 0x0D */
name|U16
name|Reserved6
decl_stmt|;
comment|/* 0x0E */
name|U32
name|DataLength
decl_stmt|;
comment|/* 0x10 */
name|U8
name|DiagnosticCliCommand
index|[
name|MPI2_TOOLBOX_DIAG_CLI_CMD_LENGTH
index|]
decl_stmt|;
comment|/* 0x14 */
name|MPI2_MPI_SGE_IO_UNION
name|SGL
decl_stmt|;
comment|/* 0x70 */
block|}
name|MPI2_TOOLBOX_DIAGNOSTIC_CLI_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TOOLBOX_DIAGNOSTIC_CLI_REQUEST
operator|,
name|Mpi2ToolboxDiagnosticCliRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2ToolboxDiagnosticCliRequest_t
typedef|;
end_typedef

begin_comment
comment|/* use MPI2_SGLFLAGS_ defines from mpi2.h for the SGLFlags field */
end_comment

begin_comment
comment|/* MPI v2.5 Toolbox Diagnostic CLI Tool request message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI25_TOOLBOX_DIAGNOSTIC_CLI_REQUEST
block|{
name|U8
name|Tool
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
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x0C */
name|U32
name|DataLength
decl_stmt|;
comment|/* 0x10 */
name|U8
name|DiagnosticCliCommand
index|[
name|MPI2_TOOLBOX_DIAG_CLI_CMD_LENGTH
index|]
decl_stmt|;
comment|/* 0x14 */
name|MPI25_SGE_IO_UNION
name|SGL
decl_stmt|;
comment|/* 0x70 */
block|}
name|MPI25_TOOLBOX_DIAGNOSTIC_CLI_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI25_TOOLBOX_DIAGNOSTIC_CLI_REQUEST
operator|,
name|Mpi25ToolboxDiagnosticCliRequest_t
operator|,
name|MPI2_POINTER
name|pMpi25ToolboxDiagnosticCliRequest_t
typedef|;
end_typedef

begin_comment
comment|/* Toolbox Diagnostic CLI Tool reply message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TOOLBOX_DIAGNOSTIC_CLI_REPLY
block|{
name|U8
name|Tool
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
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
name|Reserved5
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
name|ReturnedDataLength
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_TOOLBOX_DIAGNOSTIC_CLI_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TOOLBOX_DIAG_CLI_REPLY
operator|,
name|Mpi2ToolboxDiagnosticCliReply_t
operator|,
name|MPI2_POINTER
name|pMpi2ToolboxDiagnosticCliReply_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  Toolbox Console Text Display Tool ****************************************************************************/
end_comment

begin_comment
comment|/* Toolbox Console Text Display Tool request message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TOOLBOX_TEXT_DISPLAY_REQUEST
block|{
name|U8
name|Tool
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
name|U8
name|Console
decl_stmt|;
comment|/* 0x0C */
name|U8
name|Flags
decl_stmt|;
comment|/* 0x0D */
name|U16
name|Reserved6
decl_stmt|;
comment|/* 0x0E */
name|U8
name|TextToDisplay
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x10 */
comment|/* actual length determined at runtime based on frame size */
block|}
name|MPI2_TOOLBOX_TEXT_DISPLAY_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TOOLBOX_TEXT_DISPLAY_REQUEST
operator|,
name|Mpi2ToolboxTextDisplayRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2ToolboxTextDisplayRequest_t
typedef|;
end_typedef

begin_comment
comment|/* defines for the Console field */
end_comment

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CONSOLE_TYPE_MASK
value|(0xF0)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CONSOLE_TYPE_DEFAULT
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CONSOLE_TYPE_UART
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CONSOLE_TYPE_ETHERNET
value|(0x20)
end_define

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CONSOLE_NUMBER_MASK
value|(0x0F)
end_define

begin_comment
comment|/* defines for the Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_TOOLBOX_CONSOLE_FLAG_TIMESTAMP
value|(0x01)
end_define

begin_comment
comment|/***************************************************************************** * *       Diagnostic Buffer Messages * *****************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************** *  Diagnostic Buffer Post request ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_DIAG_BUFFER_POST_REQUEST
block|{
name|U8
name|ExtendedType
decl_stmt|;
comment|/* 0x00 */
name|U8
name|BufferType
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
name|U64
name|BufferAddress
decl_stmt|;
comment|/* 0x0C */
name|U32
name|BufferLength
decl_stmt|;
comment|/* 0x14 */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x18 */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 0x1C */
name|U32
name|Flags
decl_stmt|;
comment|/* 0x20 */
name|U32
name|ProductSpecific
index|[
literal|23
index|]
decl_stmt|;
comment|/* 0x24 */
block|}
name|MPI2_DIAG_BUFFER_POST_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_DIAG_BUFFER_POST_REQUEST
operator|,
name|Mpi2DiagBufferPostRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2DiagBufferPostRequest_t
typedef|;
end_typedef

begin_comment
comment|/* values for the ExtendedType field */
end_comment

begin_define
define|#
directive|define
name|MPI2_DIAG_EXTENDED_TYPE_UTILIZATION
value|(0x02)
end_define

begin_comment
comment|/* values for the BufferType field */
end_comment

begin_define
define|#
directive|define
name|MPI2_DIAG_BUF_TYPE_TRACE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_DIAG_BUF_TYPE_SNAPSHOT
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_DIAG_BUF_TYPE_EXTENDED
value|(0x02)
end_define

begin_comment
comment|/* count of the number of buffer types */
end_comment

begin_define
define|#
directive|define
name|MPI2_DIAG_BUF_TYPE_COUNT
value|(0x03)
end_define

begin_comment
comment|/* values for the Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_DIAG_BUF_FLAG_RELEASE_ON_FULL
value|(0x00000002)
end_define

begin_comment
comment|/* for MPI v2.0 products only */
end_comment

begin_define
define|#
directive|define
name|MPI2_DIAG_BUF_FLAG_IMMEDIATE_RELEASE
value|(0x00000001)
end_define

begin_comment
comment|/**************************************************************************** *  Diagnostic Buffer Post reply ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_DIAG_BUFFER_POST_REPLY
block|{
name|U8
name|ExtendedType
decl_stmt|;
comment|/* 0x00 */
name|U8
name|BufferType
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
name|Reserved5
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
name|TransferLength
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_DIAG_BUFFER_POST_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_DIAG_BUFFER_POST_REPLY
operator|,
name|Mpi2DiagBufferPostReply_t
operator|,
name|MPI2_POINTER
name|pMpi2DiagBufferPostReply_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  Diagnostic Release request ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_DIAG_RELEASE_REQUEST
block|{
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x00 */
name|U8
name|BufferType
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
block|}
name|MPI2_DIAG_RELEASE_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_DIAG_RELEASE_REQUEST
operator|,
name|Mpi2DiagReleaseRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2DiagReleaseRequest_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  Diagnostic Buffer Post reply ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_DIAG_RELEASE_REPLY
block|{
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x00 */
name|U8
name|BufferType
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
name|Reserved5
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
block|}
name|MPI2_DIAG_RELEASE_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_DIAG_RELEASE_REPLY
operator|,
name|Mpi2DiagReleaseReply_t
operator|,
name|MPI2_POINTER
name|pMpi2DiagReleaseReply_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

