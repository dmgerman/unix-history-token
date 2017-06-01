begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012-2015 LSI Corp.  * Copyright (c) 2013-2016 Avago Technologies  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Avago Technologies (LSI) MPT-Fusion Host Adapter FreeBSD  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  Copyright (c) 2000-2015 LSI Corporation.  *  Copyright (c) 2013-2016 Avago Technologies  *  All rights reserved.  *  *  *           Name:  mpi2_init.h  *          Title:  MPI SCSI initiator mode messages and structures  *  Creation Date:  June 23, 2006  *  *  mpi2_init.h Version:  02.00.21  *  *  NOTE: Names (typedefs, defines, etc.) beginning with an MPI25 or Mpi25  *        prefix are for use only on MPI v2.5 products, and must not be used  *        with MPI v2.0 products. Unless otherwise noted, names beginning with  *        MPI2 or Mpi2 are for use with both MPI v2.0 and MPI v2.5 products.  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  04-30-07  02.00.00  Corresponds to Fusion-MPT MPI Specification Rev A.  *  10-31-07  02.00.01  Fixed name for pMpi2SCSITaskManagementRequest_t.  *  12-18-07  02.00.02  Modified Task Management Target Reset Method defines.  *  02-29-08  02.00.03  Added Query Task Set and Query Unit Attention.  *  03-03-08  02.00.04  Fixed name of struct _MPI2_SCSI_TASK_MANAGE_REPLY.  *  05-21-08  02.00.05  Fixed typo in name of Mpi2SepRequest_t.  *  10-02-08  02.00.06  Removed Untagged and No Disconnect values from SCSI IO  *                      Control field Task Attribute flags.  *                      Moved LUN field defines to mpi2.h because they are  *                      common to many structures.  *  05-06-09  02.00.07  Changed task management type of Query Unit Attention to  *                      Query Asynchronous Event.  *                      Defined two new bits in the SlotStatus field of the SCSI  *                      Enclosure Processor Request and Reply.  *  10-28-09  02.00.08  Added defines for decoding the ResponseInfo bytes for  *                      both SCSI IO Error Reply and SCSI Task Management Reply.  *                      Added ResponseInfo field to MPI2_SCSI_TASK_MANAGE_REPLY.  *                      Added MPI2_SCSITASKMGMT_RSP_TM_OVERLAPPED_TAG define.  *  02-10-10  02.00.09  Removed unused structure that had "#if 0" around it.  *  05-12-10  02.00.10  Added optional vendor-unique region to SCSI IO Request.  *  11-10-10  02.00.11  Added MPI2_SCSIIO_NUM_SGLOFFSETS define.  *  11-18-11  02.00.12  Incorporating additions for MPI v2.5.  *  02-06-12  02.00.13  Added alternate defines for Task Priority / Command  *                      Priority to match SAM-4.  *                      Added EEDPErrorOffset to MPI2_SCSI_IO_REPLY.  *  07-10-12  02.00.14  Added MPI2_SCSIIO_CONTROL_SHIFT_DATADIRECTION.  *  04-09-13  02.00.15  Added SCSIStatusQualifier field to MPI2_SCSI_IO_REPLY,  *                      replacing the Reserved4 field.  *  11-18-14  02.00.16  Updated copyright information.  *  03-16-15  02.00.17  Updated for MPI v2.6.  *                      Added MPI26_SCSIIO_IOFLAGS_ESCAPE_PASSTHROUGH.  *                      Added MPI2_SEP_REQ_SLOTSTATUS_DEV_OFF and  *                      MPI2_SEP_REPLY_SLOTSTATUS_DEV_OFF.  *  08-26-15  02.00.18  Added SCSITASKMGMT_MSGFLAGS for Target Reset.  *  12-18-15  02.00.19  Added EEDPObservedValue added to SCSI IO Reply message.  *  01-04-16  02.00.20  Modified EEDP reported values in SCSI IO Reply message.  *  01-21-16  02.00.21  Modified MPI26_SCSITASKMGMT_MSGFLAGS_PCIE* defines to  *                      be unique within first 32 characters.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_INIT_H
end_ifndef

begin_define
define|#
directive|define
name|MPI2_INIT_H
end_define

begin_comment
comment|/***************************************************************************** * *               SCSI Initiator Messages * *****************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************** *  SCSI IO messages and associated structures ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SCSI_IO_CDB_EEDP32
block|{
name|U8
name|CDB
index|[
literal|20
index|]
decl_stmt|;
comment|/* 0x00 */
name|U32
name|PrimaryReferenceTag
decl_stmt|;
comment|/* 0x14 */
name|U16
name|PrimaryApplicationTag
decl_stmt|;
comment|/* 0x18 */
name|U16
name|PrimaryApplicationTagMask
decl_stmt|;
comment|/* 0x1A */
name|U32
name|TransferLength
decl_stmt|;
comment|/* 0x1C */
block|}
name|MPI2_SCSI_IO_CDB_EEDP32
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SCSI_IO_CDB_EEDP32
operator|,
name|Mpi2ScsiIoCdbEedp32_t
operator|,
name|MPI2_POINTER
name|pMpi2ScsiIoCdbEedp32_t
typedef|;
end_typedef

begin_comment
comment|/* MPI v2.0 CDB field */
end_comment

begin_typedef
typedef|typedef
union|union
name|_MPI2_SCSI_IO_CDB_UNION
block|{
name|U8
name|CDB32
index|[
literal|32
index|]
decl_stmt|;
name|MPI2_SCSI_IO_CDB_EEDP32
name|EEDP32
decl_stmt|;
name|MPI2_SGE_SIMPLE_UNION
name|SGE
decl_stmt|;
block|}
name|MPI2_SCSI_IO_CDB_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SCSI_IO_CDB_UNION
operator|,
name|Mpi2ScsiIoCdb_t
operator|,
name|MPI2_POINTER
name|pMpi2ScsiIoCdb_t
typedef|;
end_typedef

begin_comment
comment|/* MPI v2.0 SCSI IO Request Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SCSI_IO_REQUEST
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
name|Reserved1
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved2
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
name|U32
name|SenseBufferLowAddress
decl_stmt|;
comment|/* 0x0C */
name|U16
name|SGLFlags
decl_stmt|;
comment|/* 0x10 */
name|U8
name|SenseBufferLength
decl_stmt|;
comment|/* 0x12 */
name|U8
name|Reserved4
decl_stmt|;
comment|/* 0x13 */
name|U8
name|SGLOffset0
decl_stmt|;
comment|/* 0x14 */
name|U8
name|SGLOffset1
decl_stmt|;
comment|/* 0x15 */
name|U8
name|SGLOffset2
decl_stmt|;
comment|/* 0x16 */
name|U8
name|SGLOffset3
decl_stmt|;
comment|/* 0x17 */
name|U32
name|SkipCount
decl_stmt|;
comment|/* 0x18 */
name|U32
name|DataLength
decl_stmt|;
comment|/* 0x1C */
name|U32
name|BidirectionalDataLength
decl_stmt|;
comment|/* 0x20 */
name|U16
name|IoFlags
decl_stmt|;
comment|/* 0x24 */
name|U16
name|EEDPFlags
decl_stmt|;
comment|/* 0x26 */
name|U32
name|EEDPBlockSize
decl_stmt|;
comment|/* 0x28 */
name|U32
name|SecondaryReferenceTag
decl_stmt|;
comment|/* 0x2C */
name|U16
name|SecondaryApplicationTag
decl_stmt|;
comment|/* 0x30 */
name|U16
name|ApplicationTagTranslationMask
decl_stmt|;
comment|/* 0x32 */
name|U8
name|LUN
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x34 */
name|U32
name|Control
decl_stmt|;
comment|/* 0x3C */
name|MPI2_SCSI_IO_CDB_UNION
name|CDB
decl_stmt|;
comment|/* 0x40 */
ifdef|#
directive|ifdef
name|MPI2_SCSI_IO_VENDOR_UNIQUE_REGION
comment|/* typically this is left undefined */
name|MPI2_SCSI_IO_VENDOR_UNIQUE
name|VendorRegion
decl_stmt|;
endif|#
directive|endif
name|MPI2_SGE_IO_UNION
name|SGL
decl_stmt|;
comment|/* 0x60 */
block|}
name|MPI2_SCSI_IO_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SCSI_IO_REQUEST
operator|,
name|Mpi2SCSIIORequest_t
operator|,
name|MPI2_POINTER
name|pMpi2SCSIIORequest_t
typedef|;
end_typedef

begin_comment
comment|/* SCSI IO MsgFlags bits */
end_comment

begin_comment
comment|/* MsgFlags for SenseBufferAddressSpace */
end_comment

begin_define
define|#
directive|define
name|MPI2_SCSIIO_MSGFLAGS_MASK_SENSE_ADDR
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_MSGFLAGS_SYSTEM_SENSE_ADDR
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_MSGFLAGS_IOCDDR_SENSE_ADDR
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_MSGFLAGS_IOCPLB_SENSE_ADDR
value|(0x08)
end_define

begin_comment
comment|/* for MPI v2.5 and earlier only */
end_comment

begin_define
define|#
directive|define
name|MPI2_SCSIIO_MSGFLAGS_IOCPLBNTA_SENSE_ADDR
value|(0x0C)
end_define

begin_comment
comment|/* for MPI v2.5 and earlier only */
end_comment

begin_define
define|#
directive|define
name|MPI26_SCSIIO_MSGFLAGS_IOCCTL_SENSE_ADDR
value|(0x08)
end_define

begin_comment
comment|/* for MPI v2.6 only */
end_comment

begin_comment
comment|/* SCSI IO SGLFlags bits */
end_comment

begin_comment
comment|/* base values for Data Location Address Space */
end_comment

begin_define
define|#
directive|define
name|MPI2_SCSIIO_SGLFLAGS_ADDR_MASK
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_SGLFLAGS_SYSTEM_ADDR
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_SGLFLAGS_IOCDDR_ADDR
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_SGLFLAGS_IOCPLB_ADDR
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_SGLFLAGS_IOCPLBNTA_ADDR
value|(0x0C)
end_define

begin_comment
comment|/* base values for Type */
end_comment

begin_define
define|#
directive|define
name|MPI2_SCSIIO_SGLFLAGS_TYPE_MASK
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_SGLFLAGS_TYPE_MPI
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_SGLFLAGS_TYPE_IEEE32
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_SGLFLAGS_TYPE_IEEE64
value|(0x02)
end_define

begin_comment
comment|/* shift values for each sub-field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SCSIIO_SGLFLAGS_SGL3_SHIFT
value|(12)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_SGLFLAGS_SGL2_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_SGLFLAGS_SGL1_SHIFT
value|(4)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_SGLFLAGS_SGL0_SHIFT
value|(0)
end_define

begin_comment
comment|/* number of SGLOffset fields */
end_comment

begin_define
define|#
directive|define
name|MPI2_SCSIIO_NUM_SGLOFFSETS
value|(4)
end_define

begin_comment
comment|/* SCSI IO IoFlags bits */
end_comment

begin_comment
comment|/* Large CDB Address Space */
end_comment

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CDB_ADDR_MASK
value|(0x6000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CDB_ADDR_SYSTEM
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CDB_ADDR_IOCDDR
value|(0x2000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CDB_ADDR_IOCPLB
value|(0x4000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CDB_ADDR_IOCPLBNTA
value|(0x6000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_IOFLAGS_LARGE_CDB
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_IOFLAGS_BIDIRECTIONAL
value|(0x0800)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_IOFLAGS_MULTICAST
value|(0x0400)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_IOFLAGS_CMD_DETERMINES_DATA_DIR
value|(0x0200)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_IOFLAGS_CDBLENGTH_MASK
value|(0x01FF)
end_define

begin_comment
comment|/* SCSI IO EEDPFlags bits */
end_comment

begin_define
define|#
directive|define
name|MPI2_SCSIIO_EEDPFLAGS_INC_PRI_REFTAG
value|(0x8000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_EEDPFLAGS_INC_SEC_REFTAG
value|(0x4000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_EEDPFLAGS_INC_PRI_APPTAG
value|(0x2000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_EEDPFLAGS_INC_SEC_APPTAG
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_EEDPFLAGS_CHECK_REFTAG
value|(0x0400)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_EEDPFLAGS_CHECK_APPTAG
value|(0x0200)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_EEDPFLAGS_CHECK_GUARD
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_EEDPFLAGS_PASSTHRU_REFTAG
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_EEDPFLAGS_MASK_OP
value|(0x0007)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_EEDPFLAGS_NOOP_OP
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_EEDPFLAGS_CHECK_OP
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_EEDPFLAGS_STRIP_OP
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_EEDPFLAGS_CHECK_REMOVE_OP
value|(0x0003)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_EEDPFLAGS_INSERT_OP
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_EEDPFLAGS_REPLACE_OP
value|(0x0006)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_EEDPFLAGS_CHECK_REGEN_OP
value|(0x0007)
end_define

begin_comment
comment|/* SCSI IO LUN fields: use MPI2_LUN_ from mpi2.h */
end_comment

begin_comment
comment|/* SCSI IO Control bits */
end_comment

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_ADDCDBLEN_MASK
value|(0xFC000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_ADDCDBLEN_SHIFT
value|(26)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_DATADIRECTION_MASK
value|(0x03000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_SHIFT_DATADIRECTION
value|(24)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_NODATATRANSFER
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_WRITE
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_READ
value|(0x02000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_BIDIRECTIONAL
value|(0x03000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_TASKPRI_MASK
value|(0x00007800)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_TASKPRI_SHIFT
value|(11)
end_define

begin_comment
comment|/* alternate name for the previous field; called Command Priority in SAM-4 */
end_comment

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_CMDPRI_MASK
value|(0x00007800)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_CMDPRI_SHIFT
value|(11)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_TASKATTRIBUTE_MASK
value|(0x00000700)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_SIMPLEQ
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_HEADOFQ
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_ORDEREDQ
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_ACAQ
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_TLR_MASK
value|(0x000000C0)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_NO_TLR
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_TLR_ON
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_TLR_OFF
value|(0x00000080)
end_define

begin_comment
comment|/* MPI v2.5 CDB field */
end_comment

begin_typedef
typedef|typedef
union|union
name|_MPI25_SCSI_IO_CDB_UNION
block|{
name|U8
name|CDB32
index|[
literal|32
index|]
decl_stmt|;
name|MPI2_SCSI_IO_CDB_EEDP32
name|EEDP32
decl_stmt|;
name|MPI2_IEEE_SGE_SIMPLE64
name|SGE
decl_stmt|;
block|}
name|MPI25_SCSI_IO_CDB_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI25_SCSI_IO_CDB_UNION
operator|,
name|Mpi25ScsiIoCdb_t
operator|,
name|MPI2_POINTER
name|pMpi25ScsiIoCdb_t
typedef|;
end_typedef

begin_comment
comment|/* MPI v2.5/2.6 SCSI IO Request Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI25_SCSI_IO_REQUEST
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
name|Reserved1
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved2
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
name|U32
name|SenseBufferLowAddress
decl_stmt|;
comment|/* 0x0C */
name|U8
name|DMAFlags
decl_stmt|;
comment|/* 0x10 */
name|U8
name|Reserved5
decl_stmt|;
comment|/* 0x11 */
name|U8
name|SenseBufferLength
decl_stmt|;
comment|/* 0x12 */
name|U8
name|Reserved4
decl_stmt|;
comment|/* 0x13 */
name|U8
name|SGLOffset0
decl_stmt|;
comment|/* 0x14 */
name|U8
name|SGLOffset1
decl_stmt|;
comment|/* 0x15 */
name|U8
name|SGLOffset2
decl_stmt|;
comment|/* 0x16 */
name|U8
name|SGLOffset3
decl_stmt|;
comment|/* 0x17 */
name|U32
name|SkipCount
decl_stmt|;
comment|/* 0x18 */
name|U32
name|DataLength
decl_stmt|;
comment|/* 0x1C */
name|U32
name|BidirectionalDataLength
decl_stmt|;
comment|/* 0x20 */
name|U16
name|IoFlags
decl_stmt|;
comment|/* 0x24 */
name|U16
name|EEDPFlags
decl_stmt|;
comment|/* 0x26 */
name|U16
name|EEDPBlockSize
decl_stmt|;
comment|/* 0x28 */
name|U16
name|Reserved6
decl_stmt|;
comment|/* 0x2A */
name|U32
name|SecondaryReferenceTag
decl_stmt|;
comment|/* 0x2C */
name|U16
name|SecondaryApplicationTag
decl_stmt|;
comment|/* 0x30 */
name|U16
name|ApplicationTagTranslationMask
decl_stmt|;
comment|/* 0x32 */
name|U8
name|LUN
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x34 */
name|U32
name|Control
decl_stmt|;
comment|/* 0x3C */
name|MPI25_SCSI_IO_CDB_UNION
name|CDB
decl_stmt|;
comment|/* 0x40 */
ifdef|#
directive|ifdef
name|MPI25_SCSI_IO_VENDOR_UNIQUE_REGION
comment|/* typically this is left undefined */
name|MPI25_SCSI_IO_VENDOR_UNIQUE
name|VendorRegion
decl_stmt|;
endif|#
directive|endif
name|MPI25_SGE_IO_UNION
name|SGL
decl_stmt|;
comment|/* 0x60 */
block|}
name|MPI25_SCSI_IO_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI25_SCSI_IO_REQUEST
operator|,
name|Mpi25SCSIIORequest_t
operator|,
name|MPI2_POINTER
name|pMpi25SCSIIORequest_t
typedef|;
end_typedef

begin_comment
comment|/* use MPI2_SCSIIO_MSGFLAGS_ defines for the MsgFlags field */
end_comment

begin_comment
comment|/* Defines for the DMAFlags field  *  Each setting affects 4 SGLS, from SGL0 to SGL3.  *      D = Data  *      C = Cache DIF  *      I = Interleaved  *      H = Host DIF  */
end_comment

begin_define
define|#
directive|define
name|MPI25_SCSIIO_DMAFLAGS_OP_MASK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_DMAFLAGS_OP_D_D_D_D
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_DMAFLAGS_OP_D_D_D_C
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_DMAFLAGS_OP_D_D_D_I
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_DMAFLAGS_OP_D_D_C_C
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_DMAFLAGS_OP_D_D_C_I
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_DMAFLAGS_OP_D_D_I_I
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_DMAFLAGS_OP_D_C_C_C
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_DMAFLAGS_OP_D_C_C_I
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_DMAFLAGS_OP_D_C_I_I
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_DMAFLAGS_OP_D_I_I_I
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_DMAFLAGS_OP_D_H_D_D
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_DMAFLAGS_OP_D_H_D_C
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_DMAFLAGS_OP_D_H_D_I
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_DMAFLAGS_OP_D_H_C_C
value|(0x0D)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_DMAFLAGS_OP_D_H_C_I
value|(0x0E)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_DMAFLAGS_OP_D_H_I_I
value|(0x0F)
end_define

begin_comment
comment|/* number of SGLOffset fields */
end_comment

begin_define
define|#
directive|define
name|MPI25_SCSIIO_NUM_SGLOFFSETS
value|(4)
end_define

begin_comment
comment|/* defines for the IoFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI25_SCSIIO_IOFLAGS_IO_PATH_MASK
value|(0xC000)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_IOFLAGS_NORMAL_PATH
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_IOFLAGS_FAST_PATH
value|(0x4000)
end_define

begin_define
define|#
directive|define
name|MPI26_SCSIIO_IOFLAGS_ESCAPE_PASSTHROUGH
value|(0x2000)
end_define

begin_comment
comment|/* MPI v2.6 and later */
end_comment

begin_define
define|#
directive|define
name|MPI25_SCSIIO_IOFLAGS_LARGE_CDB
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_IOFLAGS_BIDIRECTIONAL
value|(0x0800)
end_define

begin_define
define|#
directive|define
name|MPI26_SCSIIO_IOFLAGS_PORT_REQUEST
value|(0x0400)
end_define

begin_comment
comment|/* MPI v2.6 and later; IOC use only */
end_comment

begin_define
define|#
directive|define
name|MPI25_SCSIIO_IOFLAGS_CDBLENGTH_MASK
value|(0x01FF)
end_define

begin_comment
comment|/* MPI v2.5 defines for the EEDPFlags bits */
end_comment

begin_comment
comment|/* use MPI2_SCSIIO_EEDPFLAGS_ defines for the other EEDPFlags bits */
end_comment

begin_define
define|#
directive|define
name|MPI25_SCSIIO_EEDPFLAGS_ESCAPE_MODE_MASK
value|(0x00C0)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_EEDPFLAGS_COMPATIBLE_MODE
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_EEDPFLAGS_DO_NOT_DISABLE_MODE
value|(0x0040)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_EEDPFLAGS_APPTAG_DISABLE_MODE
value|(0x0080)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_EEDPFLAGS_APPTAG_REFTAG_DISABLE_MODE
value|(0x00C0)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_EEDPFLAGS_HOST_GUARD_METHOD_MASK
value|(0x0030)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_EEDPFLAGS_T10_CRC_HOST_GUARD
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI25_SCSIIO_EEDPFLAGS_IP_CHKSUM_HOST_GUARD
value|(0x0010)
end_define

begin_comment
comment|/* use MPI2_LUN_ defines from mpi2.h for the LUN field */
end_comment

begin_comment
comment|/* use MPI2_SCSIIO_CONTROL_ defines for the Control field */
end_comment

begin_comment
comment|/* NOTE: The SCSI IO Reply is nearly the same for MPI 2.0 and MPI 2.5, so  *       MPI2_SCSI_IO_REPLY is used for both.  */
end_comment

begin_comment
comment|/* SCSI IO Error Reply Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SCSI_IO_REPLY
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
name|Reserved1
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved2
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
name|U8
name|SCSIStatus
decl_stmt|;
comment|/* 0x0C */
name|U8
name|SCSIState
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
name|TransferCount
decl_stmt|;
comment|/* 0x14 */
name|U32
name|SenseCount
decl_stmt|;
comment|/* 0x18 */
name|U32
name|ResponseInfo
decl_stmt|;
comment|/* 0x1C */
name|U16
name|TaskTag
decl_stmt|;
comment|/* 0x20 */
name|U16
name|SCSIStatusQualifier
decl_stmt|;
comment|/* 0x22 */
name|U32
name|BidirectionalTransferCount
decl_stmt|;
comment|/* 0x24 */
name|U32
name|EEDPErrorOffset
decl_stmt|;
comment|/* 0x28 */
comment|/* MPI 2.5+ only; Reserved in MPI 2.0 */
name|U16
name|EEDPObservedAppTag
decl_stmt|;
comment|/* 0x2C */
comment|/* MPI 2.5+ only; Reserved in MPI 2.0 */
name|U16
name|EEDPObservedGuard
decl_stmt|;
comment|/* 0x2E */
comment|/* MPI 2.5+ only; Reserved in MPI 2.0 */
name|U32
name|EEDPObservedRefTag
decl_stmt|;
comment|/* 0x30 */
comment|/* MPI 2.5+ only; Reserved in MPI 2.0 */
block|}
name|MPI2_SCSI_IO_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SCSI_IO_REPLY
operator|,
name|Mpi2SCSIIOReply_t
operator|,
name|MPI2_POINTER
name|pMpi2SCSIIOReply_t
typedef|;
end_typedef

begin_comment
comment|/* SCSI IO Reply MsgFlags bits */
end_comment

begin_define
define|#
directive|define
name|MPI26_SCSIIO_REPLY_MSGFLAGS_REFTAG_OBSERVED_VALID
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI26_SCSIIO_REPLY_MSGFLAGS_GUARD_OBSERVED_VALID
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI26_SCSIIO_REPLY_MSGFLAGS_APPTAG_OBSERVED_VALID
value|(0x04)
end_define

begin_comment
comment|/* SCSI IO Reply SCSIStatus values (SAM-4 status codes) */
end_comment

begin_define
define|#
directive|define
name|MPI2_SCSI_STATUS_GOOD
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSI_STATUS_CHECK_CONDITION
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSI_STATUS_CONDITION_MET
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSI_STATUS_BUSY
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSI_STATUS_INTERMEDIATE
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSI_STATUS_INTERMEDIATE_CONDMET
value|(0x14)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSI_STATUS_RESERVATION_CONFLICT
value|(0x18)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSI_STATUS_COMMAND_TERMINATED
value|(0x22)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|MPI2_SCSI_STATUS_TASK_SET_FULL
value|(0x28)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSI_STATUS_ACA_ACTIVE
value|(0x30)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSI_STATUS_TASK_ABORTED
value|(0x40)
end_define

begin_comment
comment|/* SCSI IO Reply SCSIState flags */
end_comment

begin_define
define|#
directive|define
name|MPI2_SCSI_STATE_RESPONSE_INFO_VALID
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSI_STATE_TERMINATED
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSI_STATE_NO_SCSI_STATUS
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSI_STATE_AUTOSENSE_FAILED
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSI_STATE_AUTOSENSE_VALID
value|(0x01)
end_define

begin_comment
comment|/* masks and shifts for the ResponseInfo field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SCSI_RI_MASK_REASONCODE
value|(0x000000FF)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSI_RI_SHIFT_REASONCODE
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSI_TASKTAG_UNKNOWN
value|(0xFFFF)
end_define

begin_comment
comment|/**************************************************************************** *  SCSI Task Management messages ****************************************************************************/
end_comment

begin_comment
comment|/* SCSI Task Management Request Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SCSI_TASK_MANAGE_REQUEST
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
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x04 */
name|U8
name|TaskType
decl_stmt|;
comment|/* 0x05 */
name|U8
name|Reserved2
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
name|U8
name|LUN
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x0C */
name|U32
name|Reserved4
index|[
literal|7
index|]
decl_stmt|;
comment|/* 0x14 */
name|U16
name|TaskMID
decl_stmt|;
comment|/* 0x30 */
name|U16
name|Reserved5
decl_stmt|;
comment|/* 0x32 */
block|}
name|MPI2_SCSI_TASK_MANAGE_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SCSI_TASK_MANAGE_REQUEST
operator|,
name|Mpi2SCSITaskManagementRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2SCSITaskManagementRequest_t
typedef|;
end_typedef

begin_comment
comment|/* TaskType values */
end_comment

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_TASKTYPE_ABORT_TASK
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_TASKTYPE_ABRT_TASK_SET
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_TASKTYPE_TARGET_RESET
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_TASKTYPE_LOGICAL_UNIT_RESET
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_TASKTYPE_CLEAR_TASK_SET
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_TASKTYPE_QUERY_TASK
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_TASKTYPE_CLR_ACA
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_TASKTYPE_QRY_TASK_SET
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_TASKTYPE_QRY_ASYNC_EVENT
value|(0x0A)
end_define

begin_comment
comment|/* obsolete TaskType name */
end_comment

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_TASKTYPE_QRY_UNIT_ATTENTION
value|(MPI2_SCSITASKMGMT_TASKTYPE_QRY_ASYNC_EVENT)
end_define

begin_comment
comment|/* MsgFlags bits */
end_comment

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_MSGFLAGS_MASK_TARGET_RESET
value|(0x18)
end_define

begin_define
define|#
directive|define
name|MPI26_SCSITASKMGMT_MSGFLAGS_HOT_RESET_PCIE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_MSGFLAGS_LINK_RESET
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_MSGFLAGS_DO_NOT_SEND_TASK_IU
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_MSGFLAGS_NEXUS_RESET_SRST
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_MSGFLAGS_SAS_HARD_LINK_RESET
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI26_SCSITASKMGMT_MSGFLAGS_PROTOCOL_LVL_RST_PCIE
value|(0x18)
end_define

begin_comment
comment|/* SCSI Task Management Reply Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SCSI_TASK_MANAGE_REPLY
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
name|U8
name|ResponseCode
decl_stmt|;
comment|/* 0x04 */
name|U8
name|TaskType
decl_stmt|;
comment|/* 0x05 */
name|U8
name|Reserved1
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
name|Reserved2
decl_stmt|;
comment|/* 0x0A */
name|U16
name|Reserved3
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
name|TerminationCount
decl_stmt|;
comment|/* 0x14 */
name|U32
name|ResponseInfo
decl_stmt|;
comment|/* 0x18 */
block|}
name|MPI2_SCSI_TASK_MANAGE_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SCSI_TASK_MANAGE_REPLY
operator|,
name|Mpi2SCSITaskManagementReply_t
operator|,
name|MPI2_POINTER
name|pMpi2SCSIManagementReply_t
typedef|;
end_typedef

begin_comment
comment|/* ResponseCode values */
end_comment

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_RSP_TM_COMPLETE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_RSP_INVALID_FRAME
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_RSP_TM_NOT_SUPPORTED
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_RSP_TM_FAILED
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_RSP_TM_SUCCEEDED
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_RSP_TM_INVALID_LUN
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_RSP_TM_OVERLAPPED_TAG
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_RSP_IO_QUEUED_ON_IOC
value|(0x80)
end_define

begin_comment
comment|/* masks and shifts for the ResponseInfo field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_RI_MASK_REASONCODE
value|(0x000000FF)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_RI_SHIFT_REASONCODE
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_RI_MASK_ARI2
value|(0x0000FF00)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_RI_SHIFT_ARI2
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_RI_MASK_ARI1
value|(0x00FF0000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_RI_SHIFT_ARI1
value|(16)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_RI_MASK_ARI0
value|(0xFF000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSITASKMGMT_RI_SHIFT_ARI0
value|(24)
end_define

begin_comment
comment|/**************************************************************************** *  SCSI Enclosure Processor messages ****************************************************************************/
end_comment

begin_comment
comment|/* SCSI Enclosure Processor Request Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SEP_REQUEST
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
name|U8
name|Action
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Flags
decl_stmt|;
comment|/* 0x05 */
name|U8
name|Reserved1
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
name|Reserved2
decl_stmt|;
comment|/* 0x0A */
name|U32
name|SlotStatus
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
name|Reserved5
decl_stmt|;
comment|/* 0x18 */
name|U16
name|Slot
decl_stmt|;
comment|/* 0x1C */
name|U16
name|EnclosureHandle
decl_stmt|;
comment|/* 0x1E */
block|}
name|MPI2_SEP_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SEP_REQUEST
operator|,
name|Mpi2SepRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2SepRequest_t
typedef|;
end_typedef

begin_comment
comment|/* Action defines */
end_comment

begin_define
define|#
directive|define
name|MPI2_SEP_REQ_ACTION_WRITE_STATUS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SEP_REQ_ACTION_READ_STATUS
value|(0x01)
end_define

begin_comment
comment|/* Flags defines */
end_comment

begin_define
define|#
directive|define
name|MPI2_SEP_REQ_FLAGS_DEVHANDLE_ADDRESS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SEP_REQ_FLAGS_ENCLOSURE_SLOT_ADDRESS
value|(0x01)
end_define

begin_comment
comment|/* SlotStatus defines */
end_comment

begin_define
define|#
directive|define
name|MPI2_SEP_REQ_SLOTSTATUS_DEV_OFF
value|(0x00080000)
end_define

begin_comment
comment|/* MPI v2.6 and newer */
end_comment

begin_define
define|#
directive|define
name|MPI2_SEP_REQ_SLOTSTATUS_REQUEST_REMOVE
value|(0x00040000)
end_define

begin_define
define|#
directive|define
name|MPI2_SEP_REQ_SLOTSTATUS_IDENTIFY_REQUEST
value|(0x00020000)
end_define

begin_define
define|#
directive|define
name|MPI2_SEP_REQ_SLOTSTATUS_REBUILD_STOPPED
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI2_SEP_REQ_SLOTSTATUS_HOT_SPARE
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI2_SEP_REQ_SLOTSTATUS_UNCONFIGURED
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI2_SEP_REQ_SLOTSTATUS_PREDICTED_FAULT
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI2_SEP_REQ_SLOTSTATUS_IN_CRITICAL_ARRAY
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_SEP_REQ_SLOTSTATUS_IN_FAILED_ARRAY
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI2_SEP_REQ_SLOTSTATUS_DEV_REBUILDING
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI2_SEP_REQ_SLOTSTATUS_DEV_FAULTY
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_SEP_REQ_SLOTSTATUS_NO_ERROR
value|(0x00000001)
end_define

begin_comment
comment|/* SCSI Enclosure Processor Reply Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SEP_REPLY
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
name|U8
name|Action
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Flags
decl_stmt|;
comment|/* 0x05 */
name|U8
name|Reserved1
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
name|Reserved2
decl_stmt|;
comment|/* 0x0A */
name|U16
name|Reserved3
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
name|SlotStatus
decl_stmt|;
comment|/* 0x14 */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x18 */
name|U16
name|Slot
decl_stmt|;
comment|/* 0x1C */
name|U16
name|EnclosureHandle
decl_stmt|;
comment|/* 0x1E */
block|}
name|MPI2_SEP_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SEP_REPLY
operator|,
name|Mpi2SepReply_t
operator|,
name|MPI2_POINTER
name|pMpi2SepReply_t
typedef|;
end_typedef

begin_comment
comment|/* SlotStatus defines */
end_comment

begin_define
define|#
directive|define
name|MPI2_SEP_REPLY_SLOTSTATUS_DEV_OFF
value|(0x00080000)
end_define

begin_comment
comment|/* MPI v2.6 and newer */
end_comment

begin_define
define|#
directive|define
name|MPI2_SEP_REPLY_SLOTSTATUS_REMOVE_READY
value|(0x00040000)
end_define

begin_define
define|#
directive|define
name|MPI2_SEP_REPLY_SLOTSTATUS_IDENTIFY_REQUEST
value|(0x00020000)
end_define

begin_define
define|#
directive|define
name|MPI2_SEP_REPLY_SLOTSTATUS_REBUILD_STOPPED
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI2_SEP_REPLY_SLOTSTATUS_HOT_SPARE
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI2_SEP_REPLY_SLOTSTATUS_UNCONFIGURED
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI2_SEP_REPLY_SLOTSTATUS_PREDICTED_FAULT
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI2_SEP_REPLY_SLOTSTATUS_IN_CRITICAL_ARRAY
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_SEP_REPLY_SLOTSTATUS_IN_FAILED_ARRAY
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI2_SEP_REPLY_SLOTSTATUS_DEV_REBUILDING
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI2_SEP_REPLY_SLOTSTATUS_DEV_FAULTY
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_SEP_REPLY_SLOTSTATUS_NO_ERROR
value|(0x00000001)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

