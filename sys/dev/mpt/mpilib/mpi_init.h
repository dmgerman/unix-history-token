begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000, 2001 by LSI Logic Corporation  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  *           Name:  MPI_INIT.H  *          Title:  MPI initiator mode messages and structures  *  Creation Date:  June 8, 2000  *  *    MPI_INIT.H Version:  01.02.06  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  05-08-00  00.10.01  Original release for 0.10 spec dated 4/26/2000.  *  05-24-00  00.10.02  Added SenseBufferLength to _MSG_SCSI_IO_REPLY.  *  06-06-00  01.00.01  Update version number for 1.0 release.  *  06-08-00  01.00.02  Added MPI_SCSI_RSP_INFO_ definitions.  *  11-02-00  01.01.01  Original release for post 1.0 work.  *  12-04-00  01.01.02  Added MPI_SCSIIO_CONTROL_NO_DISCONNECT.  *  02-20-01  01.01.03  Started using MPI_POINTER.  *  03-27-01  01.01.04  Added structure offset comments.  *  04-10-01  01.01.05  Added new MsgFlag for MSG_SCSI_TASK_MGMT.  *  08-08-01  01.02.01  Original release for v1.2 work.  *  08-29-01  01.02.02  Added MPI_SCSITASKMGMT_TASKTYPE_LOGICAL_UNIT_RESET.  *                      Added MPI_SCSI_STATE_QUEUE_TAG_REJECTED for  *                      MSG_SCSI_IO_REPLY.  *  09-28-01  01.02.03  Added structures and defines for SCSI Enclosure  *                      Processor messages.  *  10-04-01  01.02.04  Added defines for SEP request Action field.  *  05-31-02  01.02.05  Added MPI_SCSIIO_MSGFLGS_CMD_DETERMINES_DATA_DIR define  *                      for SCSI IO requests.  *  11-15-02  01.02.06  Added special extended SCSI Status defines for FCP.  *  --------------------------------------------------------------------------  */
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
comment|/*  SCSI IO messages and assocaited structures                              */
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
name|U32
name|SlotStatus
decl_stmt|;
comment|/* 0Ch */
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

