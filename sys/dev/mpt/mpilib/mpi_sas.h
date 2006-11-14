begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2000-2005, LSI Logic Corporation and its contributors.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon including  *    a substantially similar Disclaimer requirement for further binary  *    redistribution.  * 3. Neither the name of the LSI Logic Corporation nor the names of its  *    contributors may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF THE COPYRIGHT  * OWNER OR CONTRIBUTOR IS ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *  *           Name:  mpi_sas.h  *          Title:  MPI Serial Attached SCSI structures and definitions  *  Creation Date:  August 19, 2004  *  *    mpi_sas.h Version:  01.05.02  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  08-19-04  01.05.01  Original release.  *  08-30-05  01.05.02  Added DeviceInfo bit for SEP.  *                      Added PrimFlags and Primitive field to SAS IO Unit  *                      Control request, and added a new operation code.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_SAS_H
end_ifndef

begin_define
define|#
directive|define
name|MPI_SAS_H
end_define

begin_comment
comment|/*  * Values for SASStatus.  */
end_comment

begin_define
define|#
directive|define
name|MPI_SASSTATUS_SUCCESS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SASSTATUS_UNKNOWN_ERROR
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_SASSTATUS_INVALID_FRAME
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SASSTATUS_UTC_BAD_DEST
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_SASSTATUS_UTC_BREAK_RECEIVED
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_SASSTATUS_UTC_CONNECT_RATE_NOT_SUPPORTED
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI_SASSTATUS_UTC_PORT_LAYER_REQUEST
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI_SASSTATUS_UTC_PROTOCOL_NOT_SUPPORTED
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI_SASSTATUS_UTC_STP_RESOURCES_BUSY
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_SASSTATUS_UTC_WRONG_DESTINATION
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI_SASSTATUS_SHORT_INFORMATION_UNIT
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI_SASSTATUS_LONG_INFORMATION_UNIT
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI_SASSTATUS_XFER_RDY_INCORRECT_WRITE_DATA
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI_SASSTATUS_XFER_RDY_REQUEST_OFFSET_ERROR
value|(0x0D)
end_define

begin_define
define|#
directive|define
name|MPI_SASSTATUS_XFER_RDY_NOT_EXPECTED
value|(0x0E)
end_define

begin_define
define|#
directive|define
name|MPI_SASSTATUS_DATA_INCORRECT_DATA_LENGTH
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI_SASSTATUS_DATA_TOO_MUCH_READ_DATA
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI_SASSTATUS_DATA_OFFSET_ERROR
value|(0x11)
end_define

begin_define
define|#
directive|define
name|MPI_SASSTATUS_SDSF_NAK_RECEIVED
value|(0x12)
end_define

begin_define
define|#
directive|define
name|MPI_SASSTATUS_SDSF_CONNECTION_FAILED
value|(0x13)
end_define

begin_define
define|#
directive|define
name|MPI_SASSTATUS_INITIATOR_RESPONSE_TIMEOUT
value|(0x14)
end_define

begin_comment
comment|/*  * Values for the SAS DeviceInfo field used in SAS Device Status Change Event  * data and SAS IO Unit Configuration pages.  */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_INFO_SEP
value|(0x00004000)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_INFO_ATAPI_DEVICE
value|(0x00002000)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_INFO_LSI_DEVICE
value|(0x00001000)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_INFO_DIRECT_ATTACH
value|(0x00000800)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_INFO_SSP_TARGET
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_INFO_STP_TARGET
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_INFO_SMP_TARGET
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_INFO_SATA_DEVICE
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_INFO_SSP_INITIATOR
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_INFO_STP_INITIATOR
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_INFO_SMP_INITIATOR
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_INFO_SATA_HOST
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_INFO_MASK_DEVICE_TYPE
value|(0x00000007)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_INFO_NO_DEVICE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_INFO_END_DEVICE
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_INFO_EDGE_EXPANDER
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_INFO_FANOUT_EXPANDER
value|(0x00000003)
end_define

begin_comment
comment|/***************************************************************************** * *        S e r i a l    A t t a c h e d    S C S I     M e s s a g e s * *****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Serial Management Protocol Passthrough Request                           */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_SMP_PASSTHROUGH_REQUEST
block|{
name|U8
name|PassthroughFlags
decl_stmt|;
comment|/* 00h */
name|U8
name|PhysicalPort
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
name|RequestDataLength
decl_stmt|;
comment|/* 04h */
name|U8
name|ConnectionRate
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
name|Reserved1
decl_stmt|;
comment|/* 0Ch */
name|U64
name|SASAddress
decl_stmt|;
comment|/* 10h */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 18h */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 1Ch */
name|SGE_SIMPLE_UNION
name|SGL
decl_stmt|;
comment|/* 20h */
block|}
name|MSG_SMP_PASSTHROUGH_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_SMP_PASSTHROUGH_REQUEST
operator|,
name|SmpPassthroughRequest_t
operator|,
name|MPI_POINTER
name|pSmpPassthroughRequest_t
typedef|;
end_typedef

begin_comment
comment|/* values for PassthroughFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI_SMP_PT_REQ_PT_FLAGS_IMMEDIATE
value|(0x80)
end_define

begin_comment
comment|/* values for ConnectionRate field */
end_comment

begin_define
define|#
directive|define
name|MPI_SMP_PT_REQ_CONNECT_RATE_NEGOTIATED
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SMP_PT_REQ_CONNECT_RATE_1_5
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_SMP_PT_REQ_CONNECT_RATE_3_0
value|(0x09)
end_define

begin_comment
comment|/* Serial Management Protocol Passthrough Reply */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_SMP_PASSTHROUGH_REPLY
block|{
name|U8
name|PassthroughFlags
decl_stmt|;
comment|/* 00h */
name|U8
name|PhysicalPort
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
name|ResponseDataLength
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
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0Ch */
name|U8
name|SASStatus
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
name|Reserved3
decl_stmt|;
comment|/* 14h */
name|U8
name|ResponseData
index|[
literal|4
index|]
decl_stmt|;
comment|/* 18h */
block|}
name|MSG_SMP_PASSTHROUGH_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_SMP_PASSTHROUGH_REPLY
operator|,
name|SmpPassthroughReply_t
operator|,
name|MPI_POINTER
name|pSmpPassthroughReply_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_SMP_PT_REPLY_PT_FLAGS_IMMEDIATE
value|(0x80)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* SATA Passthrough Request                                                 */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_SATA_PASSTHROUGH_REQUEST
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
name|U16
name|PassthroughFlags
decl_stmt|;
comment|/* 04h */
name|U8
name|ConnectionRate
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
name|Reserved1
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
name|DataLength
decl_stmt|;
comment|/* 18h */
name|U8
name|CommandFIS
index|[
literal|20
index|]
decl_stmt|;
comment|/* 1Ch */
name|SGE_SIMPLE_UNION
name|SGL
decl_stmt|;
comment|/* 30h */
block|}
name|MSG_SATA_PASSTHROUGH_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_SATA_PASSTHROUGH_REQUEST
operator|,
name|SataPassthroughRequest_t
operator|,
name|MPI_POINTER
name|pSataPassthroughRequest_t
typedef|;
end_typedef

begin_comment
comment|/* values for PassthroughFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI_SATA_PT_REQ_PT_FLAGS_RESET_DEVICE
value|(0x0200)
end_define

begin_define
define|#
directive|define
name|MPI_SATA_PT_REQ_PT_FLAGS_EXECUTE_DIAG
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|MPI_SATA_PT_REQ_PT_FLAGS_DMA_QUEUED
value|(0x0080)
end_define

begin_define
define|#
directive|define
name|MPI_SATA_PT_REQ_PT_FLAGS_PACKET_COMMAND
value|(0x0040)
end_define

begin_define
define|#
directive|define
name|MPI_SATA_PT_REQ_PT_FLAGS_DMA
value|(0x0020)
end_define

begin_define
define|#
directive|define
name|MPI_SATA_PT_REQ_PT_FLAGS_PIO
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|MPI_SATA_PT_REQ_PT_FLAGS_UNSPECIFIED_VU
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI_SATA_PT_REQ_PT_FLAGS_WRITE
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI_SATA_PT_REQ_PT_FLAGS_READ
value|(0x0001)
end_define

begin_comment
comment|/* values for ConnectionRate field */
end_comment

begin_define
define|#
directive|define
name|MPI_SATA_PT_REQ_CONNECT_RATE_NEGOTIATED
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SATA_PT_REQ_CONNECT_RATE_1_5
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_SATA_PT_REQ_CONNECT_RATE_3_0
value|(0x09)
end_define

begin_comment
comment|/* SATA Passthrough Reply */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_SATA_PASSTHROUGH_REPLY
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
name|U16
name|PassthroughFlags
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
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0Ch */
name|U8
name|SASStatus
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
name|U8
name|StatusFIS
index|[
literal|20
index|]
decl_stmt|;
comment|/* 14h */
name|U32
name|StatusControlRegisters
decl_stmt|;
comment|/* 28h */
name|U32
name|TransferCount
decl_stmt|;
comment|/* 2Ch */
block|}
name|MSG_SATA_PASSTHROUGH_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_SATA_PASSTHROUGH_REPLY
operator|,
name|SataPassthroughReply_t
operator|,
name|MPI_POINTER
name|pSataPassthroughReply_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* SAS IO Unit Control Request                                              */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_SAS_IOUNIT_CONTROL_REQUEST
block|{
name|U8
name|Operation
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
name|U8
name|TargetID
decl_stmt|;
comment|/* 0Ch */
name|U8
name|Bus
decl_stmt|;
comment|/* 0Dh */
name|U8
name|PhyNum
decl_stmt|;
comment|/* 0Eh */
name|U8
name|PrimFlags
decl_stmt|;
comment|/* 0Fh */
name|U32
name|Primitive
decl_stmt|;
comment|/* 10h */
name|U64
name|SASAddress
decl_stmt|;
comment|/* 14h */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 1Ch */
block|}
name|MSG_SAS_IOUNIT_CONTROL_REQUEST
operator|,
name|MPI_POINTER
name|PTR_MSG_SAS_IOUNIT_CONTROL_REQUEST
operator|,
name|SasIoUnitControlRequest_t
operator|,
name|MPI_POINTER
name|pSasIoUnitControlRequest_t
typedef|;
end_typedef

begin_comment
comment|/* values for the Operation field */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_OP_CLEAR_NOT_PRESENT
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_OP_CLEAR_ALL_PERSISTENT
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_OP_PHY_LINK_RESET
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_OP_PHY_HARD_RESET
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_OP_PHY_CLEAR_ERROR_LOG
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_OP_MAP_CURRENT
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_OP_SEND_PRIMITIVE
value|(0x0A)
end_define

begin_comment
comment|/* values for the PrimFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_PRIMFLAGS_SINGLE
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PRIMFLAGS_TRIPLE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PRIMFLAGS_REDUNDANT
value|(0x01)
end_define

begin_comment
comment|/* SAS IO Unit Control Reply */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_SAS_IOUNIT_CONTROL_REPLY
block|{
name|U8
name|Operation
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
name|MSG_SAS_IOUNIT_CONTROL_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_SAS_IOUNIT_CONTROL_REPLY
operator|,
name|SasIoUnitControlReply_t
operator|,
name|MPI_POINTER
name|pSasIoUnitControlReply_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

