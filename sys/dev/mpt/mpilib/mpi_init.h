begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2000-2005, LSI Logic Corporation and its contributors.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon including  *    a substantially similar Disclaimer requirement for further binary  *    redistribution.  * 3. Neither the name of the LSI Logic Corporation nor the names of its  *    contributors may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF THE COPYRIGHT  * OWNER OR CONTRIBUTOR IS ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   *           Name:  mpi_init.h  *          Title:  MPI initiator mode messages and structures  *  Creation Date:  June 8, 2000  *  *    mpi_init.h Version:  01.05.06  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  05-08-00  00.10.01  Original release for 0.10 spec dated 4/26/2000.  *  05-24-00  00.10.02  Added SenseBufferLength to _MSG_SCSI_IO_REPLY.  *  06-06-00  01.00.01  Update version number for 1.0 release.  *  06-08-00  01.00.02  Added MPI_SCSI_RSP_INFO_ definitions.  *  11-02-00  01.01.01  Original release for post 1.0 work.  *  12-04-00  01.01.02  Added MPI_SCSIIO_CONTROL_NO_DISCONNECT.  *  02-20-01  01.01.03  Started using MPI_POINTER.  *  03-27-01  01.01.04  Added structure offset comments.  *  04-10-01  01.01.05  Added new MsgFlag for MSG_SCSI_TASK_MGMT.  *  08-08-01  01.02.01  Original release for v1.2 work.  *  08-29-01  01.02.02  Added MPI_SCSITASKMGMT_TASKTYPE_LOGICAL_UNIT_RESET.  *                      Added MPI_SCSI_STATE_QUEUE_TAG_REJECTED for  *                      MSG_SCSI_IO_REPLY.  *  09-28-01  01.02.03  Added structures and defines for SCSI Enclosure  *                      Processor messages.  *  10-04-01  01.02.04  Added defines for SEP request Action field.  *  05-31-02  01.02.05  Added MPI_SCSIIO_MSGFLGS_CMD_DETERMINES_DATA_DIR define  *                      for SCSI IO requests.  *  11-15-02  01.02.06  Added special extended SCSI Status defines for FCP.  *  06-26-03  01.02.07  Added MPI_SCSI_STATUS_FCPEXT_UNASSIGNED define.  *  05-11-04  01.03.01  Original release for MPI v1.3.  *  08-19-04  01.05.01  Added MsgFlags defines for EEDP to SCSI IO request.  *                      Added new word to MSG_SCSI_IO_REPLY to add TaskTag field  *                      and a reserved U16.  *                      Added new MSG_SCSI_IO32_REQUEST structure.  *                      Added a TaskType of Clear Task Set to SCSI  *                      Task Management request.  *  12-07-04  01.05.02  Added support for Task Management Query Task.  *  01-15-05  01.05.03  Modified SCSI Enclosure Processor Request to support  *                      WWID addressing.  *  03-11-05  01.05.04  Removed EEDP flags from SCSI IO Request.  *                      Removed SCSI IO 32 Request.  *                      Modified SCSI Enclosure Processor Request and Reply to  *                      support Enclosure/Slot addressing rather than WWID  *                      addressing.  *  06-24-05  01.05.05  Added SCSI IO 32 structures and defines.  *                      Added four new defines for SEP SlotStatus.  *  08-03-05  01.05.06  Fixed some MPI_SCSIIO32_MSGFLGS_ defines to make them  *                      unique in the first 32 characters.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_INIT_H
end_ifndef

begin_define
define|#
directive|define
name|MPI_INIT_H
end_define

begin_comment
comment|/***************************************************************************** * *               S C S I    I n i t i a t o r    M e s s a g e s * *****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  SCSI IO messages and associated structures                              */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_SCSI_IO_REQUEST
block|{
name|U8
name|TargetID
decl_stmt|;
comment|/* 00h */
name|U8
name|Bus
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
name|CDBLength
decl_stmt|;
comment|/* 04h */
name|U8
name|SenseBufferLength
decl_stmt|;
comment|/* 05h */
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
name|U8
name|LUN
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0Ch */
name|U32
name|Control
decl_stmt|;
comment|/* 14h */
name|U8
name|CDB
index|[
literal|16
index|]
decl_stmt|;
comment|/* 18h */
name|U32
name|DataLength
decl_stmt|;
comment|/* 28h */
name|U32
name|SenseBufferLowAddr
decl_stmt|;
comment|/* 2Ch */
name|SGE_IO_UNION
name|SGL
decl_stmt|;
comment|/* 30h */
block|}
name|MSG_SCSI_IO_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_SCSI_IO_REQUEST
operator|,
name|SCSIIORequest_t
operator|,
name|MPI_POINTER
name|pSCSIIORequest_t
typedef|;
end_typedef

begin_comment
comment|/* SCSI IO MsgFlags bits */
end_comment

begin_define
define|#
directive|define
name|MPI_SCSIIO_MSGFLGS_SENSE_WIDTH
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_MSGFLGS_SENSE_WIDTH_32
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_MSGFLGS_SENSE_WIDTH_64
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_MSGFLGS_SENSE_LOCATION
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_MSGFLGS_SENSE_LOC_HOST
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_MSGFLGS_SENSE_LOC_IOC
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_MSGFLGS_CMD_DETERMINES_DATA_DIR
value|(0x04)
end_define

begin_comment
comment|/* SCSI IO LUN fields */
end_comment

begin_define
define|#
directive|define
name|MPI_SCSIIO_LUN_FIRST_LEVEL_ADDRESSING
value|(0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_LUN_SECOND_LEVEL_ADDRESSING
value|(0xFFFF0000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_LUN_THIRD_LEVEL_ADDRESSING
value|(0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_LUN_FOURTH_LEVEL_ADDRESSING
value|(0xFFFF0000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_LUN_LEVEL_1_WORD
value|(0xFF00)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_LUN_LEVEL_1_DWORD
value|(0x0000FF00)
end_define

begin_comment
comment|/* SCSI IO Control bits */
end_comment

begin_define
define|#
directive|define
name|MPI_SCSIIO_CONTROL_DATADIRECTION_MASK
value|(0x03000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_CONTROL_NODATATRANSFER
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_CONTROL_WRITE
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_CONTROL_READ
value|(0x02000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_CONTROL_ADDCDBLEN_MASK
value|(0x3C000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_CONTROL_ADDCDBLEN_SHIFT
value|(26)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_CONTROL_TASKATTRIBUTE_MASK
value|(0x00000700)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_CONTROL_SIMPLEQ
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_CONTROL_HEADOFQ
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_CONTROL_ORDEREDQ
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_CONTROL_ACAQ
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_CONTROL_UNTAGGED
value|(0x00000500)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_CONTROL_NO_DISCONNECT
value|(0x00000700)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_CONTROL_TASKMANAGE_MASK
value|(0x00FF0000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_CONTROL_OBSOLETE
value|(0x00800000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_CONTROL_CLEAR_ACA_RSV
value|(0x00400000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_CONTROL_TARGET_RESET
value|(0x00200000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_CONTROL_LUN_RESET_RSV
value|(0x00100000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_CONTROL_RESERVED
value|(0x00080000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_CONTROL_CLR_TASK_SET_RSV
value|(0x00040000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_CONTROL_ABORT_TASK_SET
value|(0x00020000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO_CONTROL_RESERVED2
value|(0x00010000)
end_define

begin_comment
comment|/* SCSI IO reply structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_SCSI_IO_REPLY
block|{
name|U8
name|TargetID
decl_stmt|;
comment|/* 00h */
name|U8
name|Bus
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
name|CDBLength
decl_stmt|;
comment|/* 04h */
name|U8
name|SenseBufferLength
decl_stmt|;
comment|/* 05h */
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
name|U8
name|SCSIStatus
decl_stmt|;
comment|/* 0Ch */
name|U8
name|SCSIState
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
name|TransferCount
decl_stmt|;
comment|/* 14h */
name|U32
name|SenseCount
decl_stmt|;
comment|/* 18h */
name|U32
name|ResponseInfo
decl_stmt|;
comment|/* 1Ch */
name|U16
name|TaskTag
decl_stmt|;
comment|/* 20h */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 22h */
block|}
name|MSG_SCSI_IO_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_SCSI_IO_REPLY
operator|,
name|SCSIIOReply_t
operator|,
name|MPI_POINTER
name|pSCSIIOReply_t
typedef|;
end_typedef

begin_comment
comment|/* SCSI IO Reply SCSIStatus values (SAM-2 status codes) */
end_comment

begin_define
define|#
directive|define
name|MPI_SCSI_STATUS_SUCCESS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_STATUS_CHECK_CONDITION
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_STATUS_CONDITION_MET
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_STATUS_BUSY
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_STATUS_INTERMEDIATE
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_STATUS_INTERMEDIATE_CONDMET
value|(0x14)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_STATUS_RESERVATION_CONFLICT
value|(0x18)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_STATUS_COMMAND_TERMINATED
value|(0x22)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_STATUS_TASK_SET_FULL
value|(0x28)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_STATUS_ACA_ACTIVE
value|(0x30)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_STATUS_FCPEXT_DEVICE_LOGGED_OUT
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_STATUS_FCPEXT_NO_LINK
value|(0x81)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_STATUS_FCPEXT_UNASSIGNED
value|(0x82)
end_define

begin_comment
comment|/* SCSI IO Reply SCSIState values */
end_comment

begin_define
define|#
directive|define
name|MPI_SCSI_STATE_AUTOSENSE_VALID
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_STATE_AUTOSENSE_FAILED
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_STATE_NO_SCSI_STATUS
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_STATE_TERMINATED
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_STATE_RESPONSE_INFO_VALID
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_STATE_QUEUE_TAG_REJECTED
value|(0x20)
end_define

begin_comment
comment|/* SCSI IO Reply ResponseInfo values */
end_comment

begin_comment
comment|/* (FCP-1 RSP_CODE values and SPI-3 Packetized Failure codes) */
end_comment

begin_define
define|#
directive|define
name|MPI_SCSI_RSP_INFO_FUNCTION_COMPLETE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_RSP_INFO_FCP_BURST_LEN_ERROR
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_RSP_INFO_CMND_FIELDS_INVALID
value|(0x02000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_RSP_INFO_FCP_DATA_RO_ERROR
value|(0x03000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_RSP_INFO_TASK_MGMT_UNSUPPORTED
value|(0x04000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_RSP_INFO_TASK_MGMT_FAILED
value|(0x05000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_RSP_INFO_SPI_LQ_INVALID_TYPE
value|(0x06000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_TASKTAG_UNKNOWN
value|(0xFFFF)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  SCSI IO 32 messages and associated structures                           */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|U8
name|CDB
index|[
literal|20
index|]
decl_stmt|;
comment|/* 00h */
name|U32
name|PrimaryReferenceTag
decl_stmt|;
comment|/* 14h */
name|U16
name|PrimaryApplicationTag
decl_stmt|;
comment|/* 18h */
name|U16
name|PrimaryApplicationTagMask
decl_stmt|;
comment|/* 1Ah */
name|U32
name|TransferLength
decl_stmt|;
comment|/* 1Ch */
block|}
name|MPI_SCSI_IO32_CDB_EEDP32
operator|,
name|MPI_POINTER
name|PTR_MPI_SCSI_IO32_CDB_EEDP32
operator|,
name|MpiScsiIo32CdbEedp32_t
operator|,
name|MPI_POINTER
name|pMpiScsiIo32CdbEedp32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|U8
name|CDB
index|[
literal|16
index|]
decl_stmt|;
comment|/* 00h */
name|U32
name|DataLength
decl_stmt|;
comment|/* 10h */
name|U32
name|PrimaryReferenceTag
decl_stmt|;
comment|/* 14h */
name|U16
name|PrimaryApplicationTag
decl_stmt|;
comment|/* 18h */
name|U16
name|PrimaryApplicationTagMask
decl_stmt|;
comment|/* 1Ah */
name|U32
name|TransferLength
decl_stmt|;
comment|/* 1Ch */
block|}
name|MPI_SCSI_IO32_CDB_EEDP16
operator|,
name|MPI_POINTER
name|PTR_MPI_SCSI_IO32_CDB_EEDP16
operator|,
name|MpiScsiIo32CdbEedp16_t
operator|,
name|MPI_POINTER
name|pMpiScsiIo32CdbEedp16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|U8
name|CDB32
index|[
literal|32
index|]
decl_stmt|;
name|MPI_SCSI_IO32_CDB_EEDP32
name|EEDP32
decl_stmt|;
name|MPI_SCSI_IO32_CDB_EEDP16
name|EEDP16
decl_stmt|;
name|SGE_SIMPLE_UNION
name|SGE
decl_stmt|;
block|}
name|MPI_SCSI_IO32_CDB_UNION
operator|,
name|MPI_POINTER
name|PTR_MPI_SCSI_IO32_CDB_UNION
operator|,
name|MpiScsiIo32Cdb_t
operator|,
name|MPI_POINTER
name|pMpiScsiIo32Cdb_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|U8
name|TargetID
decl_stmt|;
comment|/* 00h */
name|U8
name|Bus
decl_stmt|;
comment|/* 01h */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 02h */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 04h */
block|}
name|MPI_SCSI_IO32_BUS_TARGET_ID_FORM
operator|,
name|MPI_POINTER
name|PTR_MPI_SCSI_IO32_BUS_TARGET_ID_FORM
operator|,
name|MpiScsiIo32BusTargetIdForm_t
operator|,
name|MPI_POINTER
name|pMpiScsiIo32BusTargetIdForm_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|MPI_SCSI_IO32_BUS_TARGET_ID_FORM
name|SCSIID
decl_stmt|;
name|U64
name|WWID
decl_stmt|;
block|}
name|MPI_SCSI_IO32_ADDRESS
operator|,
name|MPI_POINTER
name|PTR_MPI_SCSI_IO32_ADDRESS
operator|,
name|MpiScsiIo32Address_t
operator|,
name|MPI_POINTER
name|pMpiScsiIo32Address_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MSG_SCSI_IO32_REQUEST
block|{
name|U8
name|Port
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved1
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
name|CDBLength
decl_stmt|;
comment|/* 04h */
name|U8
name|SenseBufferLength
decl_stmt|;
comment|/* 05h */
name|U8
name|Flags
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
name|LUN
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0Ch */
name|U32
name|Control
decl_stmt|;
comment|/* 14h */
name|MPI_SCSI_IO32_CDB_UNION
name|CDB
decl_stmt|;
comment|/* 18h */
name|U32
name|DataLength
decl_stmt|;
comment|/* 38h */
name|U32
name|BidirectionalDataLength
decl_stmt|;
comment|/* 3Ch */
name|U32
name|SecondaryReferenceTag
decl_stmt|;
comment|/* 40h */
name|U16
name|SecondaryApplicationTag
decl_stmt|;
comment|/* 44h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 46h */
name|U16
name|EEDPFlags
decl_stmt|;
comment|/* 48h */
name|U16
name|ApplicationTagTranslationMask
decl_stmt|;
comment|/* 4Ah */
name|U32
name|EEDPBlockSize
decl_stmt|;
comment|/* 4Ch */
name|MPI_SCSI_IO32_ADDRESS
name|DeviceAddress
decl_stmt|;
comment|/* 50h */
name|U8
name|SGLOffset0
decl_stmt|;
comment|/* 58h */
name|U8
name|SGLOffset1
decl_stmt|;
comment|/* 59h */
name|U8
name|SGLOffset2
decl_stmt|;
comment|/* 5Ah */
name|U8
name|SGLOffset3
decl_stmt|;
comment|/* 5Bh */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 5Ch */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 60h */
name|U32
name|SenseBufferLowAddr
decl_stmt|;
comment|/* 64h */
name|SGE_IO_UNION
name|SGL
decl_stmt|;
comment|/* 68h */
block|}
name|MSG_SCSI_IO32_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_SCSI_IO32_REQUEST
operator|,
name|SCSIIO32Request_t
operator|,
name|MPI_POINTER
name|pSCSIIO32Request_t
typedef|;
end_typedef

begin_comment
comment|/* SCSI IO 32 MsgFlags bits */
end_comment

begin_define
define|#
directive|define
name|MPI_SCSIIO32_MSGFLGS_SENSE_WIDTH
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_MSGFLGS_32_SENSE_WIDTH
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_MSGFLGS_64_SENSE_WIDTH
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_MSGFLGS_SENSE_LOCATION
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_MSGFLGS_SENSE_LOC_HOST
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_MSGFLGS_SENSE_LOC_IOC
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_MSGFLGS_CMD_DETERMINES_DATA_DIR
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_MSGFLGS_SGL_OFFSETS_CHAINS
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_MSGFLGS_MULTICAST
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_MSGFLGS_BIDIRECTIONAL
value|(0x20)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_MSGFLGS_LARGE_CDB
value|(0x40)
end_define

begin_comment
comment|/* SCSI IO 32 Flags bits */
end_comment

begin_define
define|#
directive|define
name|MPI_SCSIIO32_FLAGS_FORM_MASK
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_FLAGS_FORM_SCSIID
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_FLAGS_FORM_WWID
value|(0x01)
end_define

begin_comment
comment|/* SCSI IO 32 LUN fields */
end_comment

begin_define
define|#
directive|define
name|MPI_SCSIIO32_LUN_FIRST_LEVEL_ADDRESSING
value|(0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_LUN_SECOND_LEVEL_ADDRESSING
value|(0xFFFF0000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_LUN_THIRD_LEVEL_ADDRESSING
value|(0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_LUN_FOURTH_LEVEL_ADDRESSING
value|(0xFFFF0000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_LUN_LEVEL_1_WORD
value|(0xFF00)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_LUN_LEVEL_1_DWORD
value|(0x0000FF00)
end_define

begin_comment
comment|/* SCSI IO 32 Control bits */
end_comment

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_DATADIRECTION_MASK
value|(0x03000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_NODATATRANSFER
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_WRITE
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_READ
value|(0x02000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_BIDIRECTIONAL
value|(0x03000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_ADDCDBLEN_MASK
value|(0xFC000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_ADDCDBLEN_SHIFT
value|(26)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_TASKATTRIBUTE_MASK
value|(0x00000700)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_SIMPLEQ
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_HEADOFQ
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_ORDEREDQ
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_ACAQ
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_UNTAGGED
value|(0x00000500)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_NO_DISCONNECT
value|(0x00000700)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_TASKMANAGE_MASK
value|(0x00FF0000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_OBSOLETE
value|(0x00800000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_CLEAR_ACA_RSV
value|(0x00400000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_TARGET_RESET
value|(0x00200000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_LUN_RESET_RSV
value|(0x00100000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_RESERVED
value|(0x00080000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_CLR_TASK_SET_RSV
value|(0x00040000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_ABORT_TASK_SET
value|(0x00020000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_CONTROL_RESERVED2
value|(0x00010000)
end_define

begin_comment
comment|/* SCSI IO 32 EEDPFlags */
end_comment

begin_define
define|#
directive|define
name|MPI_SCSIIO32_EEDPFLAGS_MASK_OP
value|(0x0007)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_EEDPFLAGS_NOOP_OP
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_EEDPFLAGS_CHK_OP
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_EEDPFLAGS_STRIP_OP
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_EEDPFLAGS_CHKRM_OP
value|(0x0003)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_EEDPFLAGS_INSERT_OP
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_EEDPFLAGS_REPLACE_OP
value|(0x0006)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_EEDPFLAGS_CHKREGEN_OP
value|(0x0007)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_EEDPFLAGS_PASS_REF_TAG
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_EEDPFLAGS_8_9THS_MODE
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_EEDPFLAGS_T10_CHK_MASK
value|(0x0700)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_EEDPFLAGS_T10_CHK_GUARD
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_EEDPFLAGS_T10_CHK_REFTAG
value|(0x0200)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_EEDPFLAGS_T10_CHK_LBATAG
value|(0x0400)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_EEDPFLAGS_T10_CHK_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_EEDPFLAGS_INC_SEC_APPTAG
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_EEDPFLAGS_INC_PRI_APPTAG
value|(0x2000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_EEDPFLAGS_INC_SEC_REFTAG
value|(0x4000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIIO32_EEDPFLAGS_INC_PRI_REFTAG
value|(0x8000)
end_define

begin_comment
comment|/* SCSIIO32 IO reply structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_SCSIIO32_IO_REPLY
block|{
name|U8
name|Port
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved1
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
name|CDBLength
decl_stmt|;
comment|/* 04h */
name|U8
name|SenseBufferLength
decl_stmt|;
comment|/* 05h */
name|U8
name|Flags
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
name|SCSIStatus
decl_stmt|;
comment|/* 0Ch */
name|U8
name|SCSIState
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
name|TransferCount
decl_stmt|;
comment|/* 14h */
name|U32
name|SenseCount
decl_stmt|;
comment|/* 18h */
name|U32
name|ResponseInfo
decl_stmt|;
comment|/* 1Ch */
name|U16
name|TaskTag
decl_stmt|;
comment|/* 20h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 22h */
name|U32
name|BidirectionalTransferCount
decl_stmt|;
comment|/* 24h */
block|}
name|MSG_SCSIIO32_IO_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_SCSIIO32_IO_REPLY
operator|,
name|SCSIIO32Reply_t
operator|,
name|MPI_POINTER
name|pSCSIIO32Reply_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  SCSI Task Management messages                                           */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_SCSI_TASK_MGMT
block|{
name|U8
name|TargetID
decl_stmt|;
comment|/* 00h */
name|U8
name|Bus
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
name|Reserved
decl_stmt|;
comment|/* 04h */
name|U8
name|TaskType
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
name|U8
name|LUN
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0Ch */
name|U32
name|Reserved2
index|[
literal|7
index|]
decl_stmt|;
comment|/* 14h */
name|U32
name|TaskMsgContext
decl_stmt|;
comment|/* 30h */
block|}
name|MSG_SCSI_TASK_MGMT
operator|,
name|MPI_POINTER
name|PTR_SCSI_TASK_MGMT
operator|,
name|SCSITaskMgmt_t
operator|,
name|MPI_POINTER
name|pSCSITaskMgmt_t
typedef|;
end_typedef

begin_comment
comment|/* TaskType values */
end_comment

begin_define
define|#
directive|define
name|MPI_SCSITASKMGMT_TASKTYPE_ABORT_TASK
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_SCSITASKMGMT_TASKTYPE_ABRT_TASK_SET
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SCSITASKMGMT_TASKTYPE_TARGET_RESET
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_SCSITASKMGMT_TASKTYPE_RESET_BUS
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_SCSITASKMGMT_TASKTYPE_LOGICAL_UNIT_RESET
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI_SCSITASKMGMT_TASKTYPE_CLEAR_TASK_SET
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI_SCSITASKMGMT_TASKTYPE_QUERY_TASK
value|(0x07)
end_define

begin_comment
comment|/* MsgFlags bits */
end_comment

begin_define
define|#
directive|define
name|MPI_SCSITASKMGMT_MSGFLAGS_TARGET_RESET_OPTION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SCSITASKMGMT_MSGFLAGS_LIP_RESET_OPTION
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SCSITASKMGMT_MSGFLAGS_LIPRESET_RESET_OPTION
value|(0x04)
end_define

begin_comment
comment|/* SCSI Task Management Reply */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_SCSI_TASK_MGMT_REPLY
block|{
name|U8
name|TargetID
decl_stmt|;
comment|/* 00h */
name|U8
name|Bus
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
name|ResponseCode
decl_stmt|;
comment|/* 04h */
name|U8
name|TaskType
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
name|U8
name|Reserved2
index|[
literal|2
index|]
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
name|TerminationCount
decl_stmt|;
comment|/* 14h */
block|}
name|MSG_SCSI_TASK_MGMT_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_SCSI_TASK_MGMT_REPLY
operator|,
name|SCSITaskMgmtReply_t
operator|,
name|MPI_POINTER
name|pSCSITaskMgmtReply_t
typedef|;
end_typedef

begin_comment
comment|/* ResponseCode values */
end_comment

begin_define
define|#
directive|define
name|MPI_SCSITASKMGMT_RSP_TM_COMPLETE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SCSITASKMGMT_RSP_INVALID_FRAME
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SCSITASKMGMT_RSP_TM_NOT_SUPPORTED
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_SCSITASKMGMT_RSP_TM_FAILED
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI_SCSITASKMGMT_RSP_TM_SUCCEEDED
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_SCSITASKMGMT_RSP_TM_INVALID_LUN
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI_SCSITASKMGMT_RSP_IO_QUEUED_ON_IOC
value|(0x80)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  SCSI Enclosure Processor messages                                       */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_SEP_REQUEST
block|{
name|U8
name|TargetID
decl_stmt|;
comment|/* 00h */
name|U8
name|Bus
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
name|Action
decl_stmt|;
comment|/* 04h */
name|U8
name|Flags
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
name|U32
name|SlotStatus
decl_stmt|;
comment|/* 0Ch */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 10h */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 14h */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 18h */
name|U16
name|Slot
decl_stmt|;
comment|/* 1Ch */
name|U16
name|EnclosureHandle
decl_stmt|;
comment|/* 1Eh */
block|}
name|MSG_SEP_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_SEP_REQUEST
operator|,
name|SEPRequest_t
operator|,
name|MPI_POINTER
name|pSEPRequest_t
typedef|;
end_typedef

begin_comment
comment|/* Action defines */
end_comment

begin_define
define|#
directive|define
name|MPI_SEP_REQ_ACTION_WRITE_STATUS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_ACTION_READ_STATUS
value|(0x01)
end_define

begin_comment
comment|/* Flags defines */
end_comment

begin_define
define|#
directive|define
name|MPI_SEP_REQ_FLAGS_ENCLOSURE_SLOT_ADDRESS
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_FLAGS_BUS_TARGETID_ADDRESS
value|(0x00)
end_define

begin_comment
comment|/* SlotStatus bits for MSG_SEP_REQUEST */
end_comment

begin_define
define|#
directive|define
name|MPI_SEP_REQ_SLOTSTATUS_NO_ERROR
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_SLOTSTATUS_DEV_FAULTY
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_SLOTSTATUS_DEV_REBUILDING
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_SLOTSTATUS_IN_FAILED_ARRAY
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_SLOTSTATUS_IN_CRITICAL_ARRAY
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_SLOTSTATUS_PARITY_CHECK
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_SLOTSTATUS_PREDICTED_FAULT
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_SLOTSTATUS_UNCONFIGURED
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_SLOTSTATUS_HOT_SPARE
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_SLOTSTATUS_REBUILD_STOPPED
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_SLOTSTATUS_REQ_CONSISTENCY_CHECK
value|(0x00001000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_SLOTSTATUS_DISABLE
value|(0x00002000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_SLOTSTATUS_REQ_RESERVED_DEVICE
value|(0x00004000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_SLOTSTATUS_IDENTIFY_REQUEST
value|(0x00020000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_SLOTSTATUS_REQUEST_REMOVE
value|(0x00040000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_SLOTSTATUS_REQUEST_INSERT
value|(0x00080000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_SLOTSTATUS_DO_NOT_MOVE
value|(0x00400000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_SLOTSTATUS_ACTIVE
value|(0x00800000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_SLOTSTATUS_B_ENABLE_BYPASS
value|(0x04000000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_SLOTSTATUS_A_ENABLE_BYPASS
value|(0x08000000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_SLOTSTATUS_DEV_OFF
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REQ_SLOTSTATUS_SWAP_RESET
value|(0x80000000)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MSG_SEP_REPLY
block|{
name|U8
name|TargetID
decl_stmt|;
comment|/* 00h */
name|U8
name|Bus
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
name|Action
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 05h */
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
name|SlotStatus
decl_stmt|;
comment|/* 14h */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 18h */
name|U16
name|Slot
decl_stmt|;
comment|/* 1Ch */
name|U16
name|EnclosureHandle
decl_stmt|;
comment|/* 1Eh */
block|}
name|MSG_SEP_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_SEP_REPLY
operator|,
name|SEPReply_t
operator|,
name|MPI_POINTER
name|pSEPReply_t
typedef|;
end_typedef

begin_comment
comment|/* SlotStatus bits for MSG_SEP_REPLY */
end_comment

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_NO_ERROR
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_DEV_FAULTY
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_DEV_REBUILDING
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_IN_FAILED_ARRAY
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_IN_CRITICAL_ARRAY
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_PARITY_CHECK
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_PREDICTED_FAULT
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_UNCONFIGURED
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_HOT_SPARE
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_REBUILD_STOPPED
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_CONSISTENCY_CHECK
value|(0x00001000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_DISABLE
value|(0x00002000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_RESERVED_DEVICE
value|(0x00004000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_REPORT
value|(0x00010000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_IDENTIFY_REQUEST
value|(0x00020000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_REMOVE_READY
value|(0x00040000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_INSERT_READY
value|(0x00080000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_DO_NOT_REMOVE
value|(0x00400000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_ACTIVE
value|(0x00800000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_B_BYPASS_ENABLED
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_A_BYPASS_ENABLED
value|(0x02000000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_B_ENABLE_BYPASS
value|(0x04000000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_A_ENABLE_BYPASS
value|(0x08000000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_DEV_OFF
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_FAULT_SENSED
value|(0x40000000)
end_define

begin_define
define|#
directive|define
name|MPI_SEP_REPLY_SLOTSTATUS_SWAPPED
value|(0x80000000)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

