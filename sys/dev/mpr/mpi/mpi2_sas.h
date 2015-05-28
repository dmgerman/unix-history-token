begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 LSI Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * LSI MPT-Fusion Host Adapter FreeBSD  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  Copyright (c) 2000-2013 LSI Corporation.  *  *  *           Name:  mpi2_sas.h  *          Title:  MPI Serial Attached SCSI structures and definitions  *  Creation Date:  February 9, 2007  *  *  mpi2_sas.h Version:  02.00.08  *  *  NOTE: Names (typedefs, defines, etc.) beginning with an MPI25 or Mpi25  *        prefix are for use only on MPI v2.5 products, and must not be used  *        with MPI v2.0 products. Unless otherwise noted, names beginning with  *        MPI2 or Mpi2 are for use with both MPI v2.0 and MPI v2.5 products.  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  04-30-07  02.00.00  Corresponds to Fusion-MPT MPI Specification Rev A.  *  06-26-07  02.00.01  Added Clear All Persistent Operation to SAS IO Unit  *                      Control Request.  *  10-02-08  02.00.02  Added Set IOC Parameter Operation to SAS IO Unit Control  *                      Request.  *  10-28-09  02.00.03  Changed the type of SGL in MPI2_SATA_PASSTHROUGH_REQUEST  *                      to MPI2_SGE_IO_UNION since it supports chained SGLs.  *  05-12-10  02.00.04  Modified some comments.  *  08-11-10  02.00.05  Added NCQ operations to SAS IO Unit Control.  *  11-18-11  02.00.06  Incorporating additions for MPI v2.5.  *  07-10-12  02.00.07  Added MPI2_SATA_PT_SGE_UNION for use in the SATA  *                      Passthrough Request message.  *  08-19-13  02.00.08  Made MPI2_SAS_OP_TRANSMIT_PORT_SELECT_SIGNAL obsolete  *                      for anything newer than MPI v2.0.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_SAS_H
end_ifndef

begin_define
define|#
directive|define
name|MPI2_SAS_H
end_define

begin_comment
comment|/*  * Values for SASStatus.  */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASSTATUS_SUCCESS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SASSTATUS_UNKNOWN_ERROR
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_SASSTATUS_INVALID_FRAME
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_SASSTATUS_UTC_BAD_DEST
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_SASSTATUS_UTC_BREAK_RECEIVED
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_SASSTATUS_UTC_CONNECT_RATE_NOT_SUPPORTED
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_SASSTATUS_UTC_PORT_LAYER_REQUEST
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_SASSTATUS_UTC_PROTOCOL_NOT_SUPPORTED
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI2_SASSTATUS_UTC_STP_RESOURCES_BUSY
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_SASSTATUS_UTC_WRONG_DESTINATION
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI2_SASSTATUS_SHORT_INFORMATION_UNIT
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI2_SASSTATUS_LONG_INFORMATION_UNIT
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI2_SASSTATUS_XFER_RDY_INCORRECT_WRITE_DATA
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI2_SASSTATUS_XFER_RDY_REQUEST_OFFSET_ERROR
value|(0x0D)
end_define

begin_define
define|#
directive|define
name|MPI2_SASSTATUS_XFER_RDY_NOT_EXPECTED
value|(0x0E)
end_define

begin_define
define|#
directive|define
name|MPI2_SASSTATUS_DATA_INCORRECT_DATA_LENGTH
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI2_SASSTATUS_DATA_TOO_MUCH_READ_DATA
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_SASSTATUS_DATA_OFFSET_ERROR
value|(0x11)
end_define

begin_define
define|#
directive|define
name|MPI2_SASSTATUS_SDSF_NAK_RECEIVED
value|(0x12)
end_define

begin_define
define|#
directive|define
name|MPI2_SASSTATUS_SDSF_CONNECTION_FAILED
value|(0x13)
end_define

begin_define
define|#
directive|define
name|MPI2_SASSTATUS_INITIATOR_RESPONSE_TIMEOUT
value|(0x14)
end_define

begin_comment
comment|/*  * Values for the SAS DeviceInfo field used in SAS Device Status Change Event  * data and SAS Configuration pages.  */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE_INFO_SEP
value|(0x00004000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE_INFO_ATAPI_DEVICE
value|(0x00002000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE_INFO_LSI_DEVICE
value|(0x00001000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE_INFO_DIRECT_ATTACH
value|(0x00000800)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE_INFO_SSP_TARGET
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE_INFO_STP_TARGET
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE_INFO_SMP_TARGET
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE_INFO_SATA_DEVICE
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE_INFO_SSP_INITIATOR
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE_INFO_STP_INITIATOR
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE_INFO_SMP_INITIATOR
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE_INFO_SATA_HOST
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE_INFO_MASK_DEVICE_TYPE
value|(0x00000007)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE_INFO_NO_DEVICE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE_INFO_END_DEVICE
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE_INFO_EDGE_EXPANDER
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE_INFO_FANOUT_EXPANDER
value|(0x00000003)
end_define

begin_comment
comment|/***************************************************************************** * *        SAS Messages * *****************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************** *  SMP Passthrough messages ****************************************************************************/
end_comment

begin_comment
comment|/* SMP Passthrough Request Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SMP_PASSTHROUGH_REQUEST
block|{
name|U8
name|PassthroughFlags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|PhysicalPort
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
name|RequestDataLength
decl_stmt|;
comment|/* 0x04 */
name|U8
name|SGLFlags
decl_stmt|;
comment|/* 0x06 */
comment|/* MPI v2.0 only. Reserved on MPI v2.5. */
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
name|Reserved1
decl_stmt|;
comment|/* 0x0A */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x0C */
name|U64
name|SASAddress
decl_stmt|;
comment|/* 0x10 */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x18 */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x1C */
name|MPI2_SIMPLE_SGE_UNION
name|SGL
decl_stmt|;
comment|/* 0x20 */
comment|/* MPI v2.5: IEEE Simple 64 elements only */
block|}
name|MPI2_SMP_PASSTHROUGH_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SMP_PASSTHROUGH_REQUEST
operator|,
name|Mpi2SmpPassthroughRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2SmpPassthroughRequest_t
typedef|;
end_typedef

begin_comment
comment|/* values for PassthroughFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SMP_PT_REQ_PT_FLAGS_IMMEDIATE
value|(0x80)
end_define

begin_comment
comment|/* MPI v2.0: use MPI2_SGLFLAGS_ defines from mpi2.h for the SGLFlags field */
end_comment

begin_comment
comment|/* SMP Passthrough Reply Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SMP_PASSTHROUGH_REPLY
block|{
name|U8
name|PassthroughFlags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|PhysicalPort
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
name|ResponseDataLength
decl_stmt|;
comment|/* 0x04 */
name|U8
name|SGLFlags
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
name|Reserved1
decl_stmt|;
comment|/* 0x0A */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x0C */
name|U8
name|SASStatus
decl_stmt|;
comment|/* 0x0D */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0x0E */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 0x10 */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x14 */
name|U8
name|ResponseData
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x18 */
block|}
name|MPI2_SMP_PASSTHROUGH_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SMP_PASSTHROUGH_REPLY
operator|,
name|Mpi2SmpPassthroughReply_t
operator|,
name|MPI2_POINTER
name|pMpi2SmpPassthroughReply_t
typedef|;
end_typedef

begin_comment
comment|/* values for PassthroughFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SMP_PT_REPLY_PT_FLAGS_IMMEDIATE
value|(0x80)
end_define

begin_comment
comment|/* values for SASStatus field are at the top of this file */
end_comment

begin_comment
comment|/**************************************************************************** *  SATA Passthrough messages ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
union|union
name|_MPI2_SATA_PT_SGE_UNION
block|{
name|MPI2_SGE_SIMPLE_UNION
name|MpiSimple
decl_stmt|;
comment|/* MPI v2.0 only */
name|MPI2_SGE_CHAIN_UNION
name|MpiChain
decl_stmt|;
comment|/* MPI v2.0 only */
name|MPI2_IEEE_SGE_SIMPLE_UNION
name|IeeeSimple
decl_stmt|;
name|MPI2_IEEE_SGE_CHAIN_UNION
name|IeeeChain
decl_stmt|;
comment|/* MPI v2.0 only */
name|MPI25_IEEE_SGE_CHAIN64
name|IeeeChain64
decl_stmt|;
comment|/* MPI v2.5 only */
block|}
name|MPI2_SATA_PT_SGE_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SATA_PT_SGE_UNION
operator|,
name|Mpi2SataPTSGEUnion_t
operator|,
name|MPI2_POINTER
name|pMpi2SataPTSGEUnion_t
typedef|;
end_typedef

begin_comment
comment|/* SATA Passthrough Request Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SATA_PASSTHROUGH_REQUEST
block|{
name|U16
name|DevHandle
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
name|PassthroughFlags
decl_stmt|;
comment|/* 0x04 */
name|U8
name|SGLFlags
decl_stmt|;
comment|/* 0x06 */
comment|/* MPI v2.0 only. Reserved on MPI v2.5. */
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
name|Reserved1
decl_stmt|;
comment|/* 0x0A */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x0C */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x10 */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x14 */
name|U32
name|DataLength
decl_stmt|;
comment|/* 0x18 */
name|U8
name|CommandFIS
index|[
literal|20
index|]
decl_stmt|;
comment|/* 0x1C */
name|MPI2_SATA_PT_SGE_UNION
name|SGL
decl_stmt|;
comment|/* 0x30 */
comment|/* MPI v2.5: IEEE 64 elements only */
block|}
name|MPI2_SATA_PASSTHROUGH_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SATA_PASSTHROUGH_REQUEST
operator|,
name|Mpi2SataPassthroughRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2SataPassthroughRequest_t
typedef|;
end_typedef

begin_comment
comment|/* values for PassthroughFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SATA_PT_REQ_PT_FLAGS_EXECUTE_DIAG
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|MPI2_SATA_PT_REQ_PT_FLAGS_DMA
value|(0x0020)
end_define

begin_define
define|#
directive|define
name|MPI2_SATA_PT_REQ_PT_FLAGS_PIO
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|MPI2_SATA_PT_REQ_PT_FLAGS_UNSPECIFIED_VU
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI2_SATA_PT_REQ_PT_FLAGS_WRITE
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI2_SATA_PT_REQ_PT_FLAGS_READ
value|(0x0001)
end_define

begin_comment
comment|/* MPI v2.0: use MPI2_SGLFLAGS_ defines from mpi2.h for the SGLFlags field */
end_comment

begin_comment
comment|/* SATA Passthrough Reply Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SATA_PASSTHROUGH_REPLY
block|{
name|U16
name|DevHandle
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
name|PassthroughFlags
decl_stmt|;
comment|/* 0x04 */
name|U8
name|SGLFlags
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
name|Reserved1
decl_stmt|;
comment|/* 0x0A */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x0C */
name|U8
name|SASStatus
decl_stmt|;
comment|/* 0x0D */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0x0E */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 0x10 */
name|U8
name|StatusFIS
index|[
literal|20
index|]
decl_stmt|;
comment|/* 0x14 */
name|U32
name|StatusControlRegisters
decl_stmt|;
comment|/* 0x28 */
name|U32
name|TransferCount
decl_stmt|;
comment|/* 0x2C */
block|}
name|MPI2_SATA_PASSTHROUGH_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SATA_PASSTHROUGH_REPLY
operator|,
name|Mpi2SataPassthroughReply_t
operator|,
name|MPI2_POINTER
name|pMpi2SataPassthroughReply_t
typedef|;
end_typedef

begin_comment
comment|/* values for SASStatus field are at the top of this file */
end_comment

begin_comment
comment|/**************************************************************************** *  SAS IO Unit Control messages ****************************************************************************/
end_comment

begin_comment
comment|/* SAS IO Unit Control Request Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SAS_IOUNIT_CONTROL_REQUEST
block|{
name|U8
name|Operation
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
name|DevHandle
decl_stmt|;
comment|/* 0x04 */
name|U8
name|IOCParameter
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
name|U8
name|PhyNum
decl_stmt|;
comment|/* 0x0E */
name|U8
name|PrimFlags
decl_stmt|;
comment|/* 0x0F */
name|U32
name|Primitive
decl_stmt|;
comment|/* 0x10 */
name|U8
name|LookupMethod
decl_stmt|;
comment|/* 0x14 */
name|U8
name|Reserved5
decl_stmt|;
comment|/* 0x15 */
name|U16
name|SlotNumber
decl_stmt|;
comment|/* 0x16 */
name|U64
name|LookupAddress
decl_stmt|;
comment|/* 0x18 */
name|U32
name|IOCParameterValue
decl_stmt|;
comment|/* 0x20 */
name|U32
name|Reserved7
decl_stmt|;
comment|/* 0x24 */
name|U32
name|Reserved8
decl_stmt|;
comment|/* 0x28 */
block|}
name|MPI2_SAS_IOUNIT_CONTROL_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SAS_IOUNIT_CONTROL_REQUEST
operator|,
name|Mpi2SasIoUnitControlRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2SasIoUnitControlRequest_t
typedef|;
end_typedef

begin_comment
comment|/* values for the Operation field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_OP_CLEAR_ALL_PERSISTENT
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_OP_PHY_LINK_RESET
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_OP_PHY_HARD_RESET
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_OP_PHY_CLEAR_ERROR_LOG
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_OP_SEND_PRIMITIVE
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_OP_FORCE_FULL_DISCOVERY
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_OP_TRANSMIT_PORT_SELECT_SIGNAL
value|(0x0C)
end_define

begin_comment
comment|/* MPI v2.0 only */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_OP_REMOVE_DEVICE
value|(0x0D)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_OP_LOOKUP_MAPPING
value|(0x0E)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_OP_SET_IOC_PARAMETER
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI25_SAS_OP_ENABLE_FP_DEVICE
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI25_SAS_OP_DISABLE_FP_DEVICE
value|(0x11)
end_define

begin_define
define|#
directive|define
name|MPI25_SAS_OP_ENABLE_FP_ALL
value|(0x12)
end_define

begin_define
define|#
directive|define
name|MPI25_SAS_OP_DISABLE_FP_ALL
value|(0x13)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_OP_DEV_ENABLE_NCQ
value|(0x14)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_OP_DEV_DISABLE_NCQ
value|(0x15)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_OP_PRODUCT_SPECIFIC_MIN
value|(0x80)
end_define

begin_comment
comment|/* values for the PrimFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_PRIMFLAGS_SINGLE
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PRIMFLAGS_TRIPLE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PRIMFLAGS_REDUNDANT
value|(0x01)
end_define

begin_comment
comment|/* values for the LookupMethod field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_LOOKUP_METHOD_SAS_ADDRESS
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_LOOKUP_METHOD_SAS_ENCLOSURE_SLOT
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_LOOKUP_METHOD_SAS_DEVICE_NAME
value|(0x03)
end_define

begin_comment
comment|/* SAS IO Unit Control Reply Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SAS_IOUNIT_CONTROL_REPLY
block|{
name|U8
name|Operation
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
name|DevHandle
decl_stmt|;
comment|/* 0x04 */
name|U8
name|IOCParameter
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
block|}
name|MPI2_SAS_IOUNIT_CONTROL_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SAS_IOUNIT_CONTROL_REPLY
operator|,
name|Mpi2SasIoUnitControlReply_t
operator|,
name|MPI2_POINTER
name|pMpi2SasIoUnitControlReply_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

