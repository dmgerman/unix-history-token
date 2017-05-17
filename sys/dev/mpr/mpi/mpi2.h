begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012-2015 LSI Corp.  * Copyright (c) 2013-2016 Avago Technologies  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Avago Technologies (LSI) MPT-Fusion Host Adapter FreeBSD  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  Copyright (c) 2000-2015 LSI Corporation.  *  Copyright (c) 2013-2016 Avago Technologies  *  All rights reserved.  *  *  *           Name:  mpi2.h  *          Title:  MPI Message independent structures and definitions  *                  including System Interface Register Set and  *                  scatter/gather formats.  *  Creation Date:  June 21, 2006  *  *  mpi2.h Version:  02.00.46  *  *  NOTE: Names (typedefs, defines, etc.) beginning with an MPI25 or Mpi25  *        prefix are for use only on MPI v2.5 products, and must not be used  *        with MPI v2.0 products. Unless otherwise noted, names beginning with  *        MPI2 or Mpi2 are for use with both MPI v2.0 and MPI v2.5 products.  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  04-30-07  02.00.00  Corresponds to Fusion-MPT MPI Specification Rev A.  *  06-04-07  02.00.01  Bumped MPI2_HEADER_VERSION_UNIT.  *  06-26-07  02.00.02  Bumped MPI2_HEADER_VERSION_UNIT.  *  08-31-07  02.00.03  Bumped MPI2_HEADER_VERSION_UNIT.  *                      Moved ReplyPostHostIndex register to offset 0x6C of the  *                      MPI2_SYSTEM_INTERFACE_REGS and modified the define for  *                      MPI2_REPLY_POST_HOST_INDEX_OFFSET.  *                      Added union of request descriptors.  *                      Added union of reply descriptors.  *  10-31-07  02.00.04  Bumped MPI2_HEADER_VERSION_UNIT.  *                      Added define for MPI2_VERSION_02_00.  *                      Fixed the size of the FunctionDependent5 field in the  *                      MPI2_DEFAULT_REPLY structure.  *  12-18-07  02.00.05  Bumped MPI2_HEADER_VERSION_UNIT.  *                      Removed the MPI-defined Fault Codes and extended the  *                      product specific codes up to 0xEFFF.  *                      Added a sixth key value for the WriteSequence register  *                      and changed the flush value to 0x0.  *                      Added message function codes for Diagnostic Buffer Post  *                      and Diagnsotic Release.  *                      New IOCStatus define: MPI2_IOCSTATUS_DIAGNOSTIC_RELEASED  *                      Moved MPI2_VERSION_UNION from mpi2_ioc.h.  *  02-29-08  02.00.06  Bumped MPI2_HEADER_VERSION_UNIT.  *  03-03-08  02.00.07  Bumped MPI2_HEADER_VERSION_UNIT.  *  05-21-08  02.00.08  Bumped MPI2_HEADER_VERSION_UNIT.  *                      Added #defines for marking a reply descriptor as unused.  *  06-27-08  02.00.09  Bumped MPI2_HEADER_VERSION_UNIT.  *  10-02-08  02.00.10  Bumped MPI2_HEADER_VERSION_UNIT.  *                      Moved LUN field defines from mpi2_init.h.  *  01-19-09  02.00.11  Bumped MPI2_HEADER_VERSION_UNIT.  *  05-06-09  02.00.12  Bumped MPI2_HEADER_VERSION_UNIT.  *                      In all request and reply descriptors, replaced VF_ID  *                      field with MSIxIndex field.  *                      Removed DevHandle field from  *                      MPI2_SCSI_IO_SUCCESS_REPLY_DESCRIPTOR and made those  *                      bytes reserved.  *                      Added RAID Accelerator functionality.  *  07-30-09  02.00.13  Bumped MPI2_HEADER_VERSION_UNIT.  *  10-28-09  02.00.14  Bumped MPI2_HEADER_VERSION_UNIT.  *                      Added MSI-x index mask and shift for Reply Post Host  *                      Index register.  *                      Added function code for Host Based Discovery Action.  *  02-10-10  02.00.15  Bumped MPI2_HEADER_VERSION_UNIT.  *                      Added define for MPI2_FUNCTION_PWR_MGMT_CONTROL.  *                      Added defines for product-specific range of message  *                      function codes, 0xF0 to 0xFF.  *  05-12-10  02.00.16  Bumped MPI2_HEADER_VERSION_UNIT.  *                      Added alternative defines for the SGE Direction bit.  *  08-11-10  02.00.17  Bumped MPI2_HEADER_VERSION_UNIT.  *  11-10-10  02.00.18  Bumped MPI2_HEADER_VERSION_UNIT.  *                      Added MPI2_IEEE_SGE_FLAGS_SYSTEMPLBCPI_ADDR define.  *  02-23-11  02.00.19  Bumped MPI2_HEADER_VERSION_UNIT.  *                      Added MPI2_FUNCTION_SEND_HOST_MESSAGE.  *  03-09-11  02.00.20  Bumped MPI2_HEADER_VERSION_UNIT.  *  05-25-11  02.00.21  Bumped MPI2_HEADER_VERSION_UNIT.  *  08-24-11  02.00.22  Bumped MPI2_HEADER_VERSION_UNIT.  *  11-18-11  02.00.23  Bumped MPI2_HEADER_VERSION_UNIT.  *                      Incorporating additions for MPI v2.5.  *  02-06-12  02.00.24  Bumped MPI2_HEADER_VERSION_UNIT.  *  03-29-12  02.00.25  Bumped MPI2_HEADER_VERSION_UNIT.  *                      Added Hard Reset delay timings.  *  07-10-12  02.00.26  Bumped MPI2_HEADER_VERSION_UNIT.  *  07-26-12  02.00.27  Bumped MPI2_HEADER_VERSION_UNIT.  *  11-27-12  02.00.28  Bumped MPI2_HEADER_VERSION_UNIT.  *  12-20-12  02.00.29  Bumped MPI2_HEADER_VERSION_UNIT.  *                      Added MPI25_SUP_REPLY_POST_HOST_INDEX_OFFSET.  *  04-09-13  02.00.30  Bumped MPI2_HEADER_VERSION_UNIT.  *  04-17-13  02.00.31  Bumped MPI2_HEADER_VERSION_UNIT.  *  08-19-13  02.00.32  Bumped MPI2_HEADER_VERSION_UNIT.  *  12-05-13  02.00.33  Bumped MPI2_HEADER_VERSION_UNIT.  *  01-08-14  02.00.34  Bumped MPI2_HEADER_VERSION_UNIT.  *  06-13-14  02.00.35  Bumped MPI2_HEADER_VERSION_UNIT.  *  11-18-14  02.00.36  Updated copyright information.  *                      Bumped MPI2_HEADER_VERSION_UNIT.  *  03-16-15  02.00.37  Updated for MPI v2.6.  *                      Bumped MPI2_HEADER_VERSION_UNIT.  *                      Added Scratchpad registers and  *                      AtomicRequestDescriptorPost register to  *                      MPI2_SYSTEM_INTERFACE_REGS.  *                      Added MPI2_DIAG_SBR_RELOAD.  *                      Added MPI2_IOCSTATUS_INSUFFICIENT_POWER.  *  03-19-15  02.00.38  Bumped MPI2_HEADER_VERSION_UNIT.  *  05-25-15  02.00.39  Bumped MPI2_HEADER_VERSION_UNIT  *  08-25-15  02.00.40  Bumped MPI2_HEADER_VERSION_UNIT.  *                      Added V7 HostDiagnostic register defines  *  12-15-15  02.00.41  Bumped MPI_HEADER_VERSION_UNIT  *  01-01-16  02.00.42  Bumped MPI_HEADER_VERSION_UNIT  *  04-05-16  02.00.43  Modified  MPI26_DIAG_BOOT_DEVICE_SELECT defines  *                      to be unique within first 32 characters.  *                      Removed AHCI support.  *                      Removed SOP support.  *                      Bumped MPI2_HEADER_VERSION_UNIT.  *  04-10-16  02.00.44  Bumped MPI2_HEADER_VERSION_UNIT.  *  07-06-16  02.00.45  Bumped MPI2_HEADER_VERSION_UNIT.  *  09-02-16  02.00.46  Bumped MPI2_HEADER_VERSION_UNIT.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_H
end_ifndef

begin_define
define|#
directive|define
name|MPI2_H
end_define

begin_comment
comment|/***************************************************************************** * *        MPI Version Definitions * *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI2_VERSION_MAJOR_MASK
value|(0xFF00)
end_define

begin_define
define|#
directive|define
name|MPI2_VERSION_MAJOR_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI2_VERSION_MINOR_MASK
value|(0x00FF)
end_define

begin_define
define|#
directive|define
name|MPI2_VERSION_MINOR_SHIFT
value|(0)
end_define

begin_comment
comment|/* major version for all MPI v2.x */
end_comment

begin_define
define|#
directive|define
name|MPI2_VERSION_MAJOR
value|(0x02)
end_define

begin_comment
comment|/* minor version for MPI v2.0 compatible products */
end_comment

begin_define
define|#
directive|define
name|MPI2_VERSION_MINOR
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_VERSION
value|((MPI2_VERSION_MAJOR<< MPI2_VERSION_MAJOR_SHIFT) |   \                                       MPI2_VERSION_MINOR)
end_define

begin_define
define|#
directive|define
name|MPI2_VERSION_02_00
value|(0x0200)
end_define

begin_comment
comment|/* minor version for MPI v2.5 compatible products */
end_comment

begin_define
define|#
directive|define
name|MPI25_VERSION_MINOR
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI25_VERSION
value|((MPI2_VERSION_MAJOR<< MPI2_VERSION_MAJOR_SHIFT) |   \                                       MPI25_VERSION_MINOR)
end_define

begin_define
define|#
directive|define
name|MPI2_VERSION_02_05
value|(0x0205)
end_define

begin_comment
comment|/* minor version for MPI v2.6 compatible products */
end_comment

begin_define
define|#
directive|define
name|MPI26_VERSION_MINOR
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI26_VERSION
value|((MPI2_VERSION_MAJOR<< MPI2_VERSION_MAJOR_SHIFT) |   \                                       MPI26_VERSION_MINOR)
end_define

begin_define
define|#
directive|define
name|MPI2_VERSION_02_06
value|(0x0206)
end_define

begin_comment
comment|/* Unit and Dev versioning for this MPI header set */
end_comment

begin_define
define|#
directive|define
name|MPI2_HEADER_VERSION_UNIT
value|(0x2E)
end_define

begin_define
define|#
directive|define
name|MPI2_HEADER_VERSION_DEV
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_HEADER_VERSION_UNIT_MASK
value|(0xFF00)
end_define

begin_define
define|#
directive|define
name|MPI2_HEADER_VERSION_UNIT_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI2_HEADER_VERSION_DEV_MASK
value|(0x00FF)
end_define

begin_define
define|#
directive|define
name|MPI2_HEADER_VERSION_DEV_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI2_HEADER_VERSION
value|((MPI2_HEADER_VERSION_UNIT<< 8) | MPI2_HEADER_VERSION_DEV)
end_define

begin_comment
comment|/***************************************************************************** * *        IOC State Definitions * *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI2_IOC_STATE_RESET
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_IOC_STATE_READY
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|MPI2_IOC_STATE_OPERATIONAL
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|MPI2_IOC_STATE_FAULT
value|(0x40000000)
end_define

begin_define
define|#
directive|define
name|MPI2_IOC_STATE_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI2_IOC_STATE_SHIFT
value|(28)
end_define

begin_comment
comment|/* Fault state range for prodcut specific codes */
end_comment

begin_define
define|#
directive|define
name|MPI2_FAULT_PRODUCT_SPECIFIC_MIN
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI2_FAULT_PRODUCT_SPECIFIC_MAX
value|(0xEFFF)
end_define

begin_comment
comment|/***************************************************************************** * *        System Interface Register Definitions * *****************************************************************************/
end_comment

begin_typedef
typedef|typedef
specifier|volatile
struct|struct
name|_MPI2_SYSTEM_INTERFACE_REGS
block|{
name|U32
name|Doorbell
decl_stmt|;
comment|/* 0x00 */
name|U32
name|WriteSequence
decl_stmt|;
comment|/* 0x04 */
name|U32
name|HostDiagnostic
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x0C */
name|U32
name|DiagRWData
decl_stmt|;
comment|/* 0x10 */
name|U32
name|DiagRWAddressLow
decl_stmt|;
comment|/* 0x14 */
name|U32
name|DiagRWAddressHigh
decl_stmt|;
comment|/* 0x18 */
name|U32
name|Reserved2
index|[
literal|5
index|]
decl_stmt|;
comment|/* 0x1C */
name|U32
name|HostInterruptStatus
decl_stmt|;
comment|/* 0x30 */
name|U32
name|HostInterruptMask
decl_stmt|;
comment|/* 0x34 */
name|U32
name|DCRData
decl_stmt|;
comment|/* 0x38 */
name|U32
name|DCRAddress
decl_stmt|;
comment|/* 0x3C */
name|U32
name|Reserved3
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0x40 */
name|U32
name|ReplyFreeHostIndex
decl_stmt|;
comment|/* 0x48 */
name|U32
name|Reserved4
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x4C */
name|U32
name|ReplyPostHostIndex
decl_stmt|;
comment|/* 0x6C */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x70 */
name|U32
name|HCBSize
decl_stmt|;
comment|/* 0x74 */
name|U32
name|HCBAddressLow
decl_stmt|;
comment|/* 0x78 */
name|U32
name|HCBAddressHigh
decl_stmt|;
comment|/* 0x7C */
name|U32
name|Reserved6
index|[
literal|12
index|]
decl_stmt|;
comment|/* 0x80 */
name|U32
name|Scratchpad
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0xB0 */
name|U32
name|RequestDescriptorPostLow
decl_stmt|;
comment|/* 0xC0 */
name|U32
name|RequestDescriptorPostHigh
decl_stmt|;
comment|/* 0xC4 */
name|U32
name|AtomicRequestDescriptorPost
decl_stmt|;
comment|/* 0xC8 */
comment|/* MPI v2.6 and later; reserved in earlier versions */
name|U32
name|Reserved7
index|[
literal|13
index|]
decl_stmt|;
comment|/* 0xCC */
block|}
name|MPI2_SYSTEM_INTERFACE_REGS
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SYSTEM_INTERFACE_REGS
operator|,
name|Mpi2SystemInterfaceRegs_t
operator|,
name|MPI2_POINTER
name|pMpi2SystemInterfaceRegs_t
typedef|;
end_typedef

begin_comment
comment|/*  * Defines for working with the Doorbell register.  */
end_comment

begin_define
define|#
directive|define
name|MPI2_DOORBELL_OFFSET
value|(0x00000000)
end_define

begin_comment
comment|/* IOC --> System values */
end_comment

begin_define
define|#
directive|define
name|MPI2_DOORBELL_USED
value|(0x08000000)
end_define

begin_define
define|#
directive|define
name|MPI2_DOORBELL_WHO_INIT_MASK
value|(0x07000000)
end_define

begin_define
define|#
directive|define
name|MPI2_DOORBELL_WHO_INIT_SHIFT
value|(24)
end_define

begin_define
define|#
directive|define
name|MPI2_DOORBELL_FAULT_CODE_MASK
value|(0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|MPI2_DOORBELL_DATA_MASK
value|(0x0000FFFF)
end_define

begin_comment
comment|/* System --> IOC values */
end_comment

begin_define
define|#
directive|define
name|MPI2_DOORBELL_FUNCTION_MASK
value|(0xFF000000)
end_define

begin_define
define|#
directive|define
name|MPI2_DOORBELL_FUNCTION_SHIFT
value|(24)
end_define

begin_define
define|#
directive|define
name|MPI2_DOORBELL_ADD_DWORDS_MASK
value|(0x00FF0000)
end_define

begin_define
define|#
directive|define
name|MPI2_DOORBELL_ADD_DWORDS_SHIFT
value|(16)
end_define

begin_comment
comment|/*  * Defines for the WriteSequence register  */
end_comment

begin_define
define|#
directive|define
name|MPI2_WRITE_SEQUENCE_OFFSET
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI2_WRSEQ_KEY_VALUE_MASK
value|(0x0000000F)
end_define

begin_define
define|#
directive|define
name|MPI2_WRSEQ_FLUSH_KEY_VALUE
value|(0x0)
end_define

begin_define
define|#
directive|define
name|MPI2_WRSEQ_1ST_KEY_VALUE
value|(0xF)
end_define

begin_define
define|#
directive|define
name|MPI2_WRSEQ_2ND_KEY_VALUE
value|(0x4)
end_define

begin_define
define|#
directive|define
name|MPI2_WRSEQ_3RD_KEY_VALUE
value|(0xB)
end_define

begin_define
define|#
directive|define
name|MPI2_WRSEQ_4TH_KEY_VALUE
value|(0x2)
end_define

begin_define
define|#
directive|define
name|MPI2_WRSEQ_5TH_KEY_VALUE
value|(0x7)
end_define

begin_define
define|#
directive|define
name|MPI2_WRSEQ_6TH_KEY_VALUE
value|(0xD)
end_define

begin_comment
comment|/*  * Defines for the HostDiagnostic register  */
end_comment

begin_define
define|#
directive|define
name|MPI2_HOST_DIAGNOSTIC_OFFSET
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI2_DIAG_SBR_RELOAD
value|(0x00002000)
end_define

begin_define
define|#
directive|define
name|MPI2_DIAG_BOOT_DEVICE_SELECT_MASK
value|(0x00001800)
end_define

begin_define
define|#
directive|define
name|MPI2_DIAG_BOOT_DEVICE_SELECT_DEFAULT
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_DIAG_BOOT_DEVICE_SELECT_HCDW
value|(0x00000800)
end_define

begin_comment
comment|/* Defines for V7A/V7R HostDiagnostic Register */
end_comment

begin_define
define|#
directive|define
name|MPI26_DIAG_BOOT_DEVICE_SEL_64FLASH
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI26_DIAG_BOOT_DEVICE_SEL_64HCDW
value|(0x00000800)
end_define

begin_define
define|#
directive|define
name|MPI26_DIAG_BOOT_DEVICE_SEL_32FLASH
value|(0x00001000)
end_define

begin_define
define|#
directive|define
name|MPI26_DIAG_BOOT_DEVICE_SEL_32HCDW
value|(0x00001800)
end_define

begin_define
define|#
directive|define
name|MPI2_DIAG_CLEAR_FLASH_BAD_SIG
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI2_DIAG_FORCE_HCB_ON_RESET
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI2_DIAG_HCB_MODE
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI2_DIAG_DIAG_WRITE_ENABLE
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI2_DIAG_FLASH_BAD_SIG
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI2_DIAG_RESET_HISTORY
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI2_DIAG_DIAG_RW_ENABLE
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_DIAG_RESET_ADAPTER
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI2_DIAG_HOLD_IOC_RESET
value|(0x00000002)
end_define

begin_comment
comment|/*  * Offsets for DiagRWData and address  */
end_comment

begin_define
define|#
directive|define
name|MPI2_DIAG_RW_DATA_OFFSET
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_DIAG_RW_ADDRESS_LOW_OFFSET
value|(0x00000014)
end_define

begin_define
define|#
directive|define
name|MPI2_DIAG_RW_ADDRESS_HIGH_OFFSET
value|(0x00000018)
end_define

begin_comment
comment|/*  * Defines for the HostInterruptStatus register  */
end_comment

begin_define
define|#
directive|define
name|MPI2_HOST_INTERRUPT_STATUS_OFFSET
value|(0x00000030)
end_define

begin_define
define|#
directive|define
name|MPI2_HIS_SYS2IOC_DB_STATUS
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|MPI2_HIS_IOP_DOORBELL_STATUS
value|MPI2_HIS_SYS2IOC_DB_STATUS
end_define

begin_define
define|#
directive|define
name|MPI2_HIS_RESET_IRQ_STATUS
value|(0x40000000)
end_define

begin_define
define|#
directive|define
name|MPI2_HIS_REPLY_DESCRIPTOR_INTERRUPT
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI2_HIS_IOC2SYS_DB_STATUS
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI2_HIS_DOORBELL_INTERRUPT
value|MPI2_HIS_IOC2SYS_DB_STATUS
end_define

begin_comment
comment|/*  * Defines for the HostInterruptMask register  */
end_comment

begin_define
define|#
directive|define
name|MPI2_HOST_INTERRUPT_MASK_OFFSET
value|(0x00000034)
end_define

begin_define
define|#
directive|define
name|MPI2_HIM_RESET_IRQ_MASK
value|(0x40000000)
end_define

begin_define
define|#
directive|define
name|MPI2_HIM_REPLY_INT_MASK
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI2_HIM_RIM
value|MPI2_HIM_REPLY_INT_MASK
end_define

begin_define
define|#
directive|define
name|MPI2_HIM_IOC2SYS_DB_MASK
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI2_HIM_DIM
value|MPI2_HIM_IOC2SYS_DB_MASK
end_define

begin_comment
comment|/*  * Offsets for DCRData and address  */
end_comment

begin_define
define|#
directive|define
name|MPI2_DCR_DATA_OFFSET
value|(0x00000038)
end_define

begin_define
define|#
directive|define
name|MPI2_DCR_ADDRESS_OFFSET
value|(0x0000003C)
end_define

begin_comment
comment|/*  * Offset for the Reply Free Queue  */
end_comment

begin_define
define|#
directive|define
name|MPI2_REPLY_FREE_HOST_INDEX_OFFSET
value|(0x00000048)
end_define

begin_comment
comment|/*  * Defines for the Reply Descriptor Post Queue  */
end_comment

begin_define
define|#
directive|define
name|MPI2_REPLY_POST_HOST_INDEX_OFFSET
value|(0x0000006C)
end_define

begin_define
define|#
directive|define
name|MPI2_REPLY_POST_HOST_INDEX_MASK
value|(0x00FFFFFF)
end_define

begin_define
define|#
directive|define
name|MPI2_RPHI_MSIX_INDEX_MASK
value|(0xFF000000)
end_define

begin_define
define|#
directive|define
name|MPI2_RPHI_MSIX_INDEX_SHIFT
value|(24)
end_define

begin_define
define|#
directive|define
name|MPI25_SUP_REPLY_POST_HOST_INDEX_OFFSET
value|(0x0000030C)
end_define

begin_comment
comment|/* MPI v2.5 only */
end_comment

begin_comment
comment|/*  * Defines for the HCBSize and address  */
end_comment

begin_define
define|#
directive|define
name|MPI2_HCB_SIZE_OFFSET
value|(0x00000074)
end_define

begin_define
define|#
directive|define
name|MPI2_HCB_SIZE_SIZE_MASK
value|(0xFFFFF000)
end_define

begin_define
define|#
directive|define
name|MPI2_HCB_SIZE_HCB_ENABLE
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI2_HCB_ADDRESS_LOW_OFFSET
value|(0x00000078)
end_define

begin_define
define|#
directive|define
name|MPI2_HCB_ADDRESS_HIGH_OFFSET
value|(0x0000007C)
end_define

begin_comment
comment|/*  * Offsets for the Scratchpad registers  */
end_comment

begin_define
define|#
directive|define
name|MPI26_SCRATCHPAD0_OFFSET
value|(0x000000B0)
end_define

begin_define
define|#
directive|define
name|MPI26_SCRATCHPAD1_OFFSET
value|(0x000000B4)
end_define

begin_define
define|#
directive|define
name|MPI26_SCRATCHPAD2_OFFSET
value|(0x000000B8)
end_define

begin_define
define|#
directive|define
name|MPI26_SCRATCHPAD3_OFFSET
value|(0x000000BC)
end_define

begin_comment
comment|/*  * Offsets for the Request Descriptor Post Queue  */
end_comment

begin_define
define|#
directive|define
name|MPI2_REQUEST_DESCRIPTOR_POST_LOW_OFFSET
value|(0x000000C0)
end_define

begin_define
define|#
directive|define
name|MPI2_REQUEST_DESCRIPTOR_POST_HIGH_OFFSET
value|(0x000000C4)
end_define

begin_define
define|#
directive|define
name|MPI26_ATOMIC_REQUEST_DESCRIPTOR_POST_OFFSET
value|(0x000000C8)
end_define

begin_comment
comment|/* Hard Reset delay timings */
end_comment

begin_define
define|#
directive|define
name|MPI2_HARD_RESET_PCIE_FIRST_READ_DELAY_MICRO_SEC
value|(50000)
end_define

begin_define
define|#
directive|define
name|MPI2_HARD_RESET_PCIE_RESET_READ_WINDOW_MICRO_SEC
value|(255000)
end_define

begin_define
define|#
directive|define
name|MPI2_HARD_RESET_PCIE_SECOND_READ_DELAY_MICRO_SEC
value|(256000)
end_define

begin_comment
comment|/***************************************************************************** * *        Message Descriptors * *****************************************************************************/
end_comment

begin_comment
comment|/* Request Descriptors */
end_comment

begin_comment
comment|/* Default Request Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_DEFAULT_REQUEST_DESCRIPTOR
block|{
name|U8
name|RequestFlags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|U16
name|SMID
decl_stmt|;
comment|/* 0x02 */
name|U16
name|LMID
decl_stmt|;
comment|/* 0x04 */
name|U16
name|DescriptorTypeDependent
decl_stmt|;
comment|/* 0x06 */
block|}
name|MPI2_DEFAULT_REQUEST_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_DEFAULT_REQUEST_DESCRIPTOR
operator|,
name|Mpi2DefaultRequestDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2DefaultRequestDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* defines for the RequestFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_REQ_DESCRIPT_FLAGS_TYPE_MASK
value|(0x1E)
end_define

begin_define
define|#
directive|define
name|MPI2_REQ_DESCRIPT_FLAGS_TYPE_RSHIFT
value|(1)
end_define

begin_comment
comment|/* use carefully; values below are pre-shifted left */
end_comment

begin_define
define|#
directive|define
name|MPI2_REQ_DESCRIPT_FLAGS_SCSI_IO
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_REQ_DESCRIPT_FLAGS_SCSI_TARGET
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_REQ_DESCRIPT_FLAGS_HIGH_PRIORITY
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_REQ_DESCRIPT_FLAGS_DEFAULT_TYPE
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_REQ_DESCRIPT_FLAGS_RAID_ACCELERATOR
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI25_REQ_DESCRIPT_FLAGS_FAST_PATH_SCSI_IO
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI26_REQ_DESCRIPT_FLAGS_PCIE_ENCAPSULATED
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_REQ_DESCRIPT_FLAGS_IOC_FIFO_MARKER
value|(0x01)
end_define

begin_comment
comment|/* High Priority Request Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_HIGH_PRIORITY_REQUEST_DESCRIPTOR
block|{
name|U8
name|RequestFlags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|U16
name|SMID
decl_stmt|;
comment|/* 0x02 */
name|U16
name|LMID
decl_stmt|;
comment|/* 0x04 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x06 */
block|}
name|MPI2_HIGH_PRIORITY_REQUEST_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_HIGH_PRIORITY_REQUEST_DESCRIPTOR
operator|,
name|Mpi2HighPriorityRequestDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2HighPriorityRequestDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* SCSI IO Request Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SCSI_IO_REQUEST_DESCRIPTOR
block|{
name|U8
name|RequestFlags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|U16
name|SMID
decl_stmt|;
comment|/* 0x02 */
name|U16
name|LMID
decl_stmt|;
comment|/* 0x04 */
name|U16
name|DevHandle
decl_stmt|;
comment|/* 0x06 */
block|}
name|MPI2_SCSI_IO_REQUEST_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SCSI_IO_REQUEST_DESCRIPTOR
operator|,
name|Mpi2SCSIIORequestDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2SCSIIORequestDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* SCSI Target Request Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SCSI_TARGET_REQUEST_DESCRIPTOR
block|{
name|U8
name|RequestFlags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|U16
name|SMID
decl_stmt|;
comment|/* 0x02 */
name|U16
name|LMID
decl_stmt|;
comment|/* 0x04 */
name|U16
name|IoIndex
decl_stmt|;
comment|/* 0x06 */
block|}
name|MPI2_SCSI_TARGET_REQUEST_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SCSI_TARGET_REQUEST_DESCRIPTOR
operator|,
name|Mpi2SCSITargetRequestDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2SCSITargetRequestDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* RAID Accelerator Request Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAID_ACCEL_REQUEST_DESCRIPTOR
block|{
name|U8
name|RequestFlags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|U16
name|SMID
decl_stmt|;
comment|/* 0x02 */
name|U16
name|LMID
decl_stmt|;
comment|/* 0x04 */
name|U16
name|Reserved
decl_stmt|;
comment|/* 0x06 */
block|}
name|MPI2_RAID_ACCEL_REQUEST_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAID_ACCEL_REQUEST_DESCRIPTOR
operator|,
name|Mpi2RAIDAcceleratorRequestDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2RAIDAcceleratorRequestDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* Fast Path SCSI IO Request Descriptor */
end_comment

begin_typedef
typedef|typedef
name|MPI2_SCSI_IO_REQUEST_DESCRIPTOR
name|MPI25_FP_SCSI_IO_REQUEST_DESCRIPTOR
typedef|,
name|MPI2_POINTER
name|PTR_MPI25_FP_SCSI_IO_REQUEST_DESCRIPTOR
typedef|,
name|Mpi25FastPathSCSIIORequestDescriptor_t
typedef|,
name|MPI2_POINTER
name|pMpi25FastPathSCSIIORequestDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* PCIe Encapsulated Request Descriptor */
end_comment

begin_typedef
typedef|typedef
name|MPI2_SCSI_IO_REQUEST_DESCRIPTOR
name|MPI26_PCIE_ENCAPSULATED_REQUEST_DESCRIPTOR
typedef|,
name|MPI2_POINTER
name|PTR_MPI26_PCIE_ENCAPSULATED_REQUEST_DESCRIPTOR
typedef|,
name|Mpi26PCIeEncapsulatedRequestDescriptor_t
typedef|,
name|MPI2_POINTER
name|pMpi26PCIeEncapsulatedRequestDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* union of Request Descriptors */
end_comment

begin_typedef
typedef|typedef
union|union
name|_MPI2_REQUEST_DESCRIPTOR_UNION
block|{
name|MPI2_DEFAULT_REQUEST_DESCRIPTOR
name|Default
decl_stmt|;
name|MPI2_HIGH_PRIORITY_REQUEST_DESCRIPTOR
name|HighPriority
decl_stmt|;
name|MPI2_SCSI_IO_REQUEST_DESCRIPTOR
name|SCSIIO
decl_stmt|;
name|MPI2_SCSI_TARGET_REQUEST_DESCRIPTOR
name|SCSITarget
decl_stmt|;
name|MPI2_RAID_ACCEL_REQUEST_DESCRIPTOR
name|RAIDAccelerator
decl_stmt|;
name|MPI25_FP_SCSI_IO_REQUEST_DESCRIPTOR
name|FastPathSCSIIO
decl_stmt|;
name|MPI26_PCIE_ENCAPSULATED_REQUEST_DESCRIPTOR
name|PCIeEncapsulated
decl_stmt|;
name|U64
name|Words
decl_stmt|;
block|}
name|MPI2_REQUEST_DESCRIPTOR_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_REQUEST_DESCRIPTOR_UNION
operator|,
name|Mpi2RequestDescriptorUnion_t
operator|,
name|MPI2_POINTER
name|pMpi2RequestDescriptorUnion_t
typedef|;
end_typedef

begin_comment
comment|/* Atomic Request Descriptors */
end_comment

begin_comment
comment|/*  * All Atomic Request Descriptors have the same format, so the following  * structure is used for all Atomic Request Descriptors:  *      Atomic Default Request Descriptor  *      Atomic High Priority Request Descriptor  *      Atomic SCSI IO Request Descriptor  *      Atomic SCSI Target Request Descriptor  *      Atomic RAID Accelerator Request Descriptor  *      Atomic Fast Path SCSI IO Request Descriptor  *      Atomic PCIe Encapsulated Request Descriptor  */
end_comment

begin_comment
comment|/* Atomic Request Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_ATOMIC_REQUEST_DESCRIPTOR
block|{
name|U8
name|RequestFlags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|U16
name|SMID
decl_stmt|;
comment|/* 0x02 */
block|}
name|MPI26_ATOMIC_REQUEST_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI26_ATOMIC_REQUEST_DESCRIPTOR
operator|,
name|Mpi26AtomicRequestDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi26AtomicRequestDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* for the RequestFlags field, use the same defines as MPI2_DEFAULT_REQUEST_DESCRIPTOR */
end_comment

begin_comment
comment|/* Reply Descriptors */
end_comment

begin_comment
comment|/* Default Reply Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_DEFAULT_REPLY_DESCRIPTOR
block|{
name|U8
name|ReplyFlags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|U16
name|DescriptorTypeDependent1
decl_stmt|;
comment|/* 0x02 */
name|U32
name|DescriptorTypeDependent2
decl_stmt|;
comment|/* 0x04 */
block|}
name|MPI2_DEFAULT_REPLY_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_DEFAULT_REPLY_DESCRIPTOR
operator|,
name|Mpi2DefaultReplyDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2DefaultReplyDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* defines for the ReplyFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_RPY_DESCRIPT_FLAGS_TYPE_MASK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI2_RPY_DESCRIPT_FLAGS_SCSI_IO_SUCCESS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_RPY_DESCRIPT_FLAGS_ADDRESS_REPLY
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_RPY_DESCRIPT_FLAGS_TARGETASSIST_SUCCESS
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_RPY_DESCRIPT_FLAGS_TARGET_COMMAND_BUFFER
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_RPY_DESCRIPT_FLAGS_RAID_ACCELERATOR_SUCCESS
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI25_RPY_DESCRIPT_FLAGS_FAST_PATH_SCSI_IO_SUCCESS
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI26_RPY_DESCRIPT_FLAGS_PCIE_ENCAPSULATED_SUCCESS
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_RPY_DESCRIPT_FLAGS_UNUSED
value|(0x0F)
end_define

begin_comment
comment|/* values for marking a reply descriptor as unused */
end_comment

begin_define
define|#
directive|define
name|MPI2_RPY_DESCRIPT_UNUSED_WORD0_MARK
value|(0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|MPI2_RPY_DESCRIPT_UNUSED_WORD1_MARK
value|(0xFFFFFFFF)
end_define

begin_comment
comment|/* Address Reply Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_ADDRESS_REPLY_DESCRIPTOR
block|{
name|U8
name|ReplyFlags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|U16
name|SMID
decl_stmt|;
comment|/* 0x02 */
name|U32
name|ReplyFrameAddress
decl_stmt|;
comment|/* 0x04 */
block|}
name|MPI2_ADDRESS_REPLY_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_ADDRESS_REPLY_DESCRIPTOR
operator|,
name|Mpi2AddressReplyDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2AddressReplyDescriptor_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_ADDRESS_REPLY_SMID_INVALID
value|(0x00)
end_define

begin_comment
comment|/* SCSI IO Success Reply Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SCSI_IO_SUCCESS_REPLY_DESCRIPTOR
block|{
name|U8
name|ReplyFlags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|U16
name|SMID
decl_stmt|;
comment|/* 0x02 */
name|U16
name|TaskTag
decl_stmt|;
comment|/* 0x04 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x06 */
block|}
name|MPI2_SCSI_IO_SUCCESS_REPLY_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SCSI_IO_SUCCESS_REPLY_DESCRIPTOR
operator|,
name|Mpi2SCSIIOSuccessReplyDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2SCSIIOSuccessReplyDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* TargetAssist Success Reply Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TARGETASSIST_SUCCESS_REPLY_DESCRIPTOR
block|{
name|U8
name|ReplyFlags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|U16
name|SMID
decl_stmt|;
comment|/* 0x02 */
name|U8
name|SequenceNumber
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x05 */
name|U16
name|IoIndex
decl_stmt|;
comment|/* 0x06 */
block|}
name|MPI2_TARGETASSIST_SUCCESS_REPLY_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TARGETASSIST_SUCCESS_REPLY_DESCRIPTOR
operator|,
name|Mpi2TargetAssistSuccessReplyDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2TargetAssistSuccessReplyDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* Target Command Buffer Reply Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_TARGET_COMMAND_BUFFER_REPLY_DESCRIPTOR
block|{
name|U8
name|ReplyFlags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|U8
name|VP_ID
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Flags
decl_stmt|;
comment|/* 0x03 */
name|U16
name|InitiatorDevHandle
decl_stmt|;
comment|/* 0x04 */
name|U16
name|IoIndex
decl_stmt|;
comment|/* 0x06 */
block|}
name|MPI2_TARGET_COMMAND_BUFFER_REPLY_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_TARGET_COMMAND_BUFFER_REPLY_DESCRIPTOR
operator|,
name|Mpi2TargetCommandBufferReplyDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2TargetCommandBufferReplyDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* defines for Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_RPY_DESCRIPT_TCB_FLAGS_PHYNUM_MASK
value|(0x3F)
end_define

begin_comment
comment|/* RAID Accelerator Success Reply Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAID_ACCELERATOR_SUCCESS_REPLY_DESCRIPTOR
block|{
name|U8
name|ReplyFlags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|U16
name|SMID
decl_stmt|;
comment|/* 0x02 */
name|U32
name|Reserved
decl_stmt|;
comment|/* 0x04 */
block|}
name|MPI2_RAID_ACCELERATOR_SUCCESS_REPLY_DESCRIPTOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAID_ACCELERATOR_SUCCESS_REPLY_DESCRIPTOR
operator|,
name|Mpi2RAIDAcceleratorSuccessReplyDescriptor_t
operator|,
name|MPI2_POINTER
name|pMpi2RAIDAcceleratorSuccessReplyDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* Fast Path SCSI IO Success Reply Descriptor */
end_comment

begin_typedef
typedef|typedef
name|MPI2_SCSI_IO_SUCCESS_REPLY_DESCRIPTOR
name|MPI25_FP_SCSI_IO_SUCCESS_REPLY_DESCRIPTOR
typedef|,
name|MPI2_POINTER
name|PTR_MPI25_FP_SCSI_IO_SUCCESS_REPLY_DESCRIPTOR
typedef|,
name|Mpi25FastPathSCSIIOSuccessReplyDescriptor_t
typedef|,
name|MPI2_POINTER
name|pMpi25FastPathSCSIIOSuccessReplyDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* PCIe Encapsulated Success Reply Descriptor */
end_comment

begin_typedef
typedef|typedef
name|MPI2_RAID_ACCELERATOR_SUCCESS_REPLY_DESCRIPTOR
name|MPI26_PCIE_ENCAPSULATED_SUCCESS_REPLY_DESCRIPTOR
typedef|,
name|MPI2_POINTER
name|PTR_MPI26_PCIE_ENCAPSULATED_SUCCESS_REPLY_DESCRIPTOR
typedef|,
name|Mpi26PCIeEncapsulatedSuccessReplyDescriptor_t
typedef|,
name|MPI2_POINTER
name|pMpi26PCIeEncapsulatedSuccessReplyDescriptor_t
typedef|;
end_typedef

begin_comment
comment|/* union of Reply Descriptors */
end_comment

begin_typedef
typedef|typedef
union|union
name|_MPI2_REPLY_DESCRIPTORS_UNION
block|{
name|MPI2_DEFAULT_REPLY_DESCRIPTOR
name|Default
decl_stmt|;
name|MPI2_ADDRESS_REPLY_DESCRIPTOR
name|AddressReply
decl_stmt|;
name|MPI2_SCSI_IO_SUCCESS_REPLY_DESCRIPTOR
name|SCSIIOSuccess
decl_stmt|;
name|MPI2_TARGETASSIST_SUCCESS_REPLY_DESCRIPTOR
name|TargetAssistSuccess
decl_stmt|;
name|MPI2_TARGET_COMMAND_BUFFER_REPLY_DESCRIPTOR
name|TargetCommandBuffer
decl_stmt|;
name|MPI2_RAID_ACCELERATOR_SUCCESS_REPLY_DESCRIPTOR
name|RAIDAcceleratorSuccess
decl_stmt|;
name|MPI25_FP_SCSI_IO_SUCCESS_REPLY_DESCRIPTOR
name|FastPathSCSIIOSuccess
decl_stmt|;
name|MPI26_PCIE_ENCAPSULATED_SUCCESS_REPLY_DESCRIPTOR
name|PCIeEncapsulatedSuccess
decl_stmt|;
name|U64
name|Words
decl_stmt|;
block|}
name|MPI2_REPLY_DESCRIPTORS_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_REPLY_DESCRIPTORS_UNION
operator|,
name|Mpi2ReplyDescriptorsUnion_t
operator|,
name|MPI2_POINTER
name|pMpi2ReplyDescriptorsUnion_t
typedef|;
end_typedef

begin_comment
comment|/***************************************************************************** * *        Message Functions * *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_SCSI_IO_REQUEST
value|(0x00)
end_define

begin_comment
comment|/* SCSI IO */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_SCSI_TASK_MGMT
value|(0x01)
end_define

begin_comment
comment|/* SCSI Task Management */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_IOC_INIT
value|(0x02)
end_define

begin_comment
comment|/* IOC Init */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_IOC_FACTS
value|(0x03)
end_define

begin_comment
comment|/* IOC Facts */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_CONFIG
value|(0x04)
end_define

begin_comment
comment|/* Configuration */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_PORT_FACTS
value|(0x05)
end_define

begin_comment
comment|/* Port Facts */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_PORT_ENABLE
value|(0x06)
end_define

begin_comment
comment|/* Port Enable */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_EVENT_NOTIFICATION
value|(0x07)
end_define

begin_comment
comment|/* Event Notification */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_EVENT_ACK
value|(0x08)
end_define

begin_comment
comment|/* Event Acknowledge */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_FW_DOWNLOAD
value|(0x09)
end_define

begin_comment
comment|/* FW Download */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_TARGET_ASSIST
value|(0x0B)
end_define

begin_comment
comment|/* Target Assist */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_TARGET_STATUS_SEND
value|(0x0C)
end_define

begin_comment
comment|/* Target Status Send */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_TARGET_MODE_ABORT
value|(0x0D)
end_define

begin_comment
comment|/* Target Mode Abort */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_FW_UPLOAD
value|(0x12)
end_define

begin_comment
comment|/* FW Upload */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_RAID_ACTION
value|(0x15)
end_define

begin_comment
comment|/* RAID Action */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_RAID_SCSI_IO_PASSTHROUGH
value|(0x16)
end_define

begin_comment
comment|/* SCSI IO RAID Passthrough */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_TOOLBOX
value|(0x17)
end_define

begin_comment
comment|/* Toolbox */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_SCSI_ENCLOSURE_PROCESSOR
value|(0x18)
end_define

begin_comment
comment|/* SCSI Enclosure Processor */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_SMP_PASSTHROUGH
value|(0x1A)
end_define

begin_comment
comment|/* SMP Passthrough */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_SAS_IO_UNIT_CONTROL
value|(0x1B)
end_define

begin_comment
comment|/* SAS IO Unit Control */
end_comment

begin_comment
comment|/* for MPI v2.5 and earlier */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_IO_UNIT_CONTROL
value|(0x1B)
end_define

begin_comment
comment|/* IO Unit Control */
end_comment

begin_comment
comment|/* for MPI v2.6 and later */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_SATA_PASSTHROUGH
value|(0x1C)
end_define

begin_comment
comment|/* SATA Passthrough */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_DIAG_BUFFER_POST
value|(0x1D)
end_define

begin_comment
comment|/* Diagnostic Buffer Post */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_DIAG_RELEASE
value|(0x1E)
end_define

begin_comment
comment|/* Diagnostic Release */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_TARGET_CMD_BUF_BASE_POST
value|(0x24)
end_define

begin_comment
comment|/* Target Command Buffer Post Base */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_TARGET_CMD_BUF_LIST_POST
value|(0x25)
end_define

begin_comment
comment|/* Target Command Buffer Post List */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_RAID_ACCELERATOR
value|(0x2C)
end_define

begin_comment
comment|/* RAID Accelerator */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_HOST_BASED_DISCOVERY_ACTION
value|(0x2F)
end_define

begin_comment
comment|/* Host Based Discovery Action */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_PWR_MGMT_CONTROL
value|(0x30)
end_define

begin_comment
comment|/* Power Management Control */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_SEND_HOST_MESSAGE
value|(0x31)
end_define

begin_comment
comment|/* Send Host Message */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_NVME_ENCAPSULATED
value|(0x33)
end_define

begin_comment
comment|/* NVMe Encapsulated (MPI v2.6) */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_MIN_PRODUCT_SPECIFIC
value|(0xF0)
end_define

begin_comment
comment|/* beginning of product-specific range */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_MAX_PRODUCT_SPECIFIC
value|(0xFF)
end_define

begin_comment
comment|/* end of product-specific range */
end_comment

begin_comment
comment|/* Doorbell functions */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_IOC_MESSAGE_UNIT_RESET
value|(0x40)
end_define

begin_define
define|#
directive|define
name|MPI2_FUNCTION_HANDSHAKE
value|(0x42)
end_define

begin_comment
comment|/***************************************************************************** * *        IOC Status Values * *****************************************************************************/
end_comment

begin_comment
comment|/* mask for IOCStatus status value */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_MASK
value|(0x7FFF)
end_define

begin_comment
comment|/**************************************************************************** *  Common IOCStatus values for all replies ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_SUCCESS
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_INVALID_FUNCTION
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_BUSY
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_INVALID_SGL
value|(0x0003)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_INTERNAL_ERROR
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_INVALID_VPID
value|(0x0005)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_INSUFFICIENT_RESOURCES
value|(0x0006)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_INVALID_FIELD
value|(0x0007)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_INVALID_STATE
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_OP_STATE_NOT_SUPPORTED
value|(0x0009)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_INSUFFICIENT_POWER
value|(0x000A)
end_define

begin_comment
comment|/* MPI v2.6 and later */
end_comment

begin_comment
comment|/**************************************************************************** *  Config IOCStatus values ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_CONFIG_INVALID_ACTION
value|(0x0020)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_CONFIG_INVALID_TYPE
value|(0x0021)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_CONFIG_INVALID_PAGE
value|(0x0022)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_CONFIG_INVALID_DATA
value|(0x0023)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_CONFIG_NO_DEFAULTS
value|(0x0024)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_CONFIG_CANT_COMMIT
value|(0x0025)
end_define

begin_comment
comment|/**************************************************************************** *  SCSI IO Reply ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_SCSI_RECOVERED_ERROR
value|(0x0040)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_SCSI_INVALID_DEVHANDLE
value|(0x0042)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_SCSI_DEVICE_NOT_THERE
value|(0x0043)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_SCSI_DATA_OVERRUN
value|(0x0044)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_SCSI_DATA_UNDERRUN
value|(0x0045)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_SCSI_IO_DATA_ERROR
value|(0x0046)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_SCSI_PROTOCOL_ERROR
value|(0x0047)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_SCSI_TASK_TERMINATED
value|(0x0048)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_SCSI_RESIDUAL_MISMATCH
value|(0x0049)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_SCSI_TASK_MGMT_FAILED
value|(0x004A)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_SCSI_IOC_TERMINATED
value|(0x004B)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_SCSI_EXT_TERMINATED
value|(0x004C)
end_define

begin_comment
comment|/**************************************************************************** *  For use by SCSI Initiator and SCSI Target end-to-end data protection ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_EEDP_GUARD_ERROR
value|(0x004D)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_EEDP_REF_TAG_ERROR
value|(0x004E)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_EEDP_APP_TAG_ERROR
value|(0x004F)
end_define

begin_comment
comment|/**************************************************************************** *  SCSI Target values ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_TARGET_INVALID_IO_INDEX
value|(0x0062)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_TARGET_ABORTED
value|(0x0063)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_TARGET_NO_CONN_RETRYABLE
value|(0x0064)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_TARGET_NO_CONNECTION
value|(0x0065)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_TARGET_XFER_COUNT_MISMATCH
value|(0x006A)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_TARGET_DATA_OFFSET_ERROR
value|(0x006D)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_TARGET_TOO_MUCH_WRITE_DATA
value|(0x006E)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_TARGET_IU_TOO_SHORT
value|(0x006F)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_TARGET_ACK_NAK_TIMEOUT
value|(0x0070)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_TARGET_NAK_RECEIVED
value|(0x0071)
end_define

begin_comment
comment|/**************************************************************************** *  Serial Attached SCSI values ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_SAS_SMP_REQUEST_FAILED
value|(0x0090)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_SAS_SMP_DATA_OVERRUN
value|(0x0091)
end_define

begin_comment
comment|/**************************************************************************** *  Diagnostic Buffer Post / Diagnostic Release values ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_DIAGNOSTIC_RELEASED
value|(0x00A0)
end_define

begin_comment
comment|/**************************************************************************** *  RAID Accelerator values ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_RAID_ACCEL_ERROR
value|(0x00B0)
end_define

begin_comment
comment|/**************************************************************************** *  IOCStatus flag to indicate that log info is available ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCSTATUS_FLAG_LOG_INFO_AVAILABLE
value|(0x8000)
end_define

begin_comment
comment|/**************************************************************************** *  IOCLogInfo Types ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCLOGINFO_TYPE_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCLOGINFO_TYPE_SHIFT
value|(28)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCLOGINFO_TYPE_NONE
value|(0x0)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCLOGINFO_TYPE_SCSI
value|(0x1)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCLOGINFO_TYPE_FC
value|(0x2)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCLOGINFO_TYPE_SAS
value|(0x3)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCLOGINFO_TYPE_ISCSI
value|(0x4)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCLOGINFO_LOG_DATA_MASK
value|(0x0FFFFFFF)
end_define

begin_comment
comment|/***************************************************************************** * *        Standard Message Structures * *****************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************** * Request Message Header for all request messages ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_REQUEST_HEADER
block|{
name|U16
name|FunctionDependent1
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
name|FunctionDependent2
decl_stmt|;
comment|/* 0x04 */
name|U8
name|FunctionDependent3
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
block|}
name|MPI2_REQUEST_HEADER
operator|,
name|MPI2_POINTER
name|PTR_MPI2_REQUEST_HEADER
operator|,
name|MPI2RequestHeader_t
operator|,
name|MPI2_POINTER
name|pMPI2RequestHeader_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  Default Reply ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_DEFAULT_REPLY
block|{
name|U16
name|FunctionDependent1
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
name|FunctionDependent2
decl_stmt|;
comment|/* 0x04 */
name|U8
name|FunctionDependent3
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
name|U16
name|FunctionDependent5
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
name|MPI2_DEFAULT_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_DEFAULT_REPLY
operator|,
name|MPI2DefaultReply_t
operator|,
name|MPI2_POINTER
name|pMPI2DefaultReply_t
typedef|;
end_typedef

begin_comment
comment|/* common version structure/union used in messages and configuration pages */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_VERSION_STRUCT
block|{
name|U8
name|Dev
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Unit
decl_stmt|;
comment|/* 0x01 */
name|U8
name|Minor
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Major
decl_stmt|;
comment|/* 0x03 */
block|}
name|MPI2_VERSION_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_MPI2_VERSION_UNION
block|{
name|MPI2_VERSION_STRUCT
name|Struct
decl_stmt|;
name|U32
name|Word
decl_stmt|;
block|}
name|MPI2_VERSION_UNION
typedef|;
end_typedef

begin_comment
comment|/* LUN field defines, common to many structures */
end_comment

begin_define
define|#
directive|define
name|MPI2_LUN_FIRST_LEVEL_ADDRESSING
value|(0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|MPI2_LUN_SECOND_LEVEL_ADDRESSING
value|(0xFFFF0000)
end_define

begin_define
define|#
directive|define
name|MPI2_LUN_THIRD_LEVEL_ADDRESSING
value|(0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|MPI2_LUN_FOURTH_LEVEL_ADDRESSING
value|(0xFFFF0000)
end_define

begin_define
define|#
directive|define
name|MPI2_LUN_LEVEL_1_WORD
value|(0xFF00)
end_define

begin_define
define|#
directive|define
name|MPI2_LUN_LEVEL_1_DWORD
value|(0x0000FF00)
end_define

begin_comment
comment|/***************************************************************************** * *        Fusion-MPT MPI Scatter Gather Elements * *****************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************** *  MPI Simple Element structures ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SGE_SIMPLE32
block|{
name|U32
name|FlagsLength
decl_stmt|;
name|U32
name|Address
decl_stmt|;
block|}
name|MPI2_SGE_SIMPLE32
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SGE_SIMPLE32
operator|,
name|Mpi2SGESimple32_t
operator|,
name|MPI2_POINTER
name|pMpi2SGESimple32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SGE_SIMPLE64
block|{
name|U32
name|FlagsLength
decl_stmt|;
name|U64
name|Address
decl_stmt|;
block|}
name|MPI2_SGE_SIMPLE64
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SGE_SIMPLE64
operator|,
name|Mpi2SGESimple64_t
operator|,
name|MPI2_POINTER
name|pMpi2SGESimple64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SGE_SIMPLE_UNION
block|{
name|U32
name|FlagsLength
decl_stmt|;
union|union
block|{
name|U32
name|Address32
decl_stmt|;
name|U64
name|Address64
decl_stmt|;
block|}
name|u
union|;
block|}
name|MPI2_SGE_SIMPLE_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SGE_SIMPLE_UNION
operator|,
name|Mpi2SGESimpleUnion_t
operator|,
name|MPI2_POINTER
name|pMpi2SGESimpleUnion_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  MPI Chain Element structures - for MPI v2.0 products only ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SGE_CHAIN32
block|{
name|U16
name|Length
decl_stmt|;
name|U8
name|NextChainOffset
decl_stmt|;
name|U8
name|Flags
decl_stmt|;
name|U32
name|Address
decl_stmt|;
block|}
name|MPI2_SGE_CHAIN32
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SGE_CHAIN32
operator|,
name|Mpi2SGEChain32_t
operator|,
name|MPI2_POINTER
name|pMpi2SGEChain32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SGE_CHAIN64
block|{
name|U16
name|Length
decl_stmt|;
name|U8
name|NextChainOffset
decl_stmt|;
name|U8
name|Flags
decl_stmt|;
name|U64
name|Address
decl_stmt|;
block|}
name|MPI2_SGE_CHAIN64
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SGE_CHAIN64
operator|,
name|Mpi2SGEChain64_t
operator|,
name|MPI2_POINTER
name|pMpi2SGEChain64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SGE_CHAIN_UNION
block|{
name|U16
name|Length
decl_stmt|;
name|U8
name|NextChainOffset
decl_stmt|;
name|U8
name|Flags
decl_stmt|;
union|union
block|{
name|U32
name|Address32
decl_stmt|;
name|U64
name|Address64
decl_stmt|;
block|}
name|u
union|;
block|}
name|MPI2_SGE_CHAIN_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SGE_CHAIN_UNION
operator|,
name|Mpi2SGEChainUnion_t
operator|,
name|MPI2_POINTER
name|pMpi2SGEChainUnion_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  MPI Transaction Context Element structures - for MPI v2.0 products only ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SGE_TRANSACTION32
block|{
name|U8
name|Reserved
decl_stmt|;
name|U8
name|ContextSize
decl_stmt|;
name|U8
name|DetailsLength
decl_stmt|;
name|U8
name|Flags
decl_stmt|;
name|U32
name|TransactionContext
index|[
literal|1
index|]
decl_stmt|;
name|U32
name|TransactionDetails
index|[
literal|1
index|]
decl_stmt|;
block|}
name|MPI2_SGE_TRANSACTION32
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SGE_TRANSACTION32
operator|,
name|Mpi2SGETransaction32_t
operator|,
name|MPI2_POINTER
name|pMpi2SGETransaction32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SGE_TRANSACTION64
block|{
name|U8
name|Reserved
decl_stmt|;
name|U8
name|ContextSize
decl_stmt|;
name|U8
name|DetailsLength
decl_stmt|;
name|U8
name|Flags
decl_stmt|;
name|U32
name|TransactionContext
index|[
literal|2
index|]
decl_stmt|;
name|U32
name|TransactionDetails
index|[
literal|1
index|]
decl_stmt|;
block|}
name|MPI2_SGE_TRANSACTION64
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SGE_TRANSACTION64
operator|,
name|Mpi2SGETransaction64_t
operator|,
name|MPI2_POINTER
name|pMpi2SGETransaction64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SGE_TRANSACTION96
block|{
name|U8
name|Reserved
decl_stmt|;
name|U8
name|ContextSize
decl_stmt|;
name|U8
name|DetailsLength
decl_stmt|;
name|U8
name|Flags
decl_stmt|;
name|U32
name|TransactionContext
index|[
literal|3
index|]
decl_stmt|;
name|U32
name|TransactionDetails
index|[
literal|1
index|]
decl_stmt|;
block|}
name|MPI2_SGE_TRANSACTION96
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SGE_TRANSACTION96
operator|,
name|Mpi2SGETransaction96_t
operator|,
name|MPI2_POINTER
name|pMpi2SGETransaction96_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SGE_TRANSACTION128
block|{
name|U8
name|Reserved
decl_stmt|;
name|U8
name|ContextSize
decl_stmt|;
name|U8
name|DetailsLength
decl_stmt|;
name|U8
name|Flags
decl_stmt|;
name|U32
name|TransactionContext
index|[
literal|4
index|]
decl_stmt|;
name|U32
name|TransactionDetails
index|[
literal|1
index|]
decl_stmt|;
block|}
name|MPI2_SGE_TRANSACTION128
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SGE_TRANSACTION128
operator|,
name|Mpi2SGETransaction_t128
operator|,
name|MPI2_POINTER
name|pMpi2SGETransaction_t128
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SGE_TRANSACTION_UNION
block|{
name|U8
name|Reserved
decl_stmt|;
name|U8
name|ContextSize
decl_stmt|;
name|U8
name|DetailsLength
decl_stmt|;
name|U8
name|Flags
decl_stmt|;
union|union
block|{
name|U32
name|TransactionContext32
index|[
literal|1
index|]
decl_stmt|;
name|U32
name|TransactionContext64
index|[
literal|2
index|]
decl_stmt|;
name|U32
name|TransactionContext96
index|[
literal|3
index|]
decl_stmt|;
name|U32
name|TransactionContext128
index|[
literal|4
index|]
decl_stmt|;
block|}
name|u
union|;
name|U32
name|TransactionDetails
index|[
literal|1
index|]
decl_stmt|;
block|}
name|MPI2_SGE_TRANSACTION_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SGE_TRANSACTION_UNION
operator|,
name|Mpi2SGETransactionUnion_t
operator|,
name|MPI2_POINTER
name|pMpi2SGETransactionUnion_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  MPI SGE union for IO SGL's - for MPI v2.0 products only ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_MPI_SGE_IO_UNION
block|{
union|union
block|{
name|MPI2_SGE_SIMPLE_UNION
name|Simple
decl_stmt|;
name|MPI2_SGE_CHAIN_UNION
name|Chain
decl_stmt|;
block|}
name|u
union|;
block|}
name|MPI2_MPI_SGE_IO_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_MPI_SGE_IO_UNION
operator|,
name|Mpi2MpiSGEIOUnion_t
operator|,
name|MPI2_POINTER
name|pMpi2MpiSGEIOUnion_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  MPI SGE union for SGL's with Simple and Transaction elements - for MPI v2.0 products only ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SGE_TRANS_SIMPLE_UNION
block|{
union|union
block|{
name|MPI2_SGE_SIMPLE_UNION
name|Simple
decl_stmt|;
name|MPI2_SGE_TRANSACTION_UNION
name|Transaction
decl_stmt|;
block|}
name|u
union|;
block|}
name|MPI2_SGE_TRANS_SIMPLE_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SGE_TRANS_SIMPLE_UNION
operator|,
name|Mpi2SGETransSimpleUnion_t
operator|,
name|MPI2_POINTER
name|pMpi2SGETransSimpleUnion_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  All MPI SGE types union ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_MPI_SGE_UNION
block|{
union|union
block|{
name|MPI2_SGE_SIMPLE_UNION
name|Simple
decl_stmt|;
name|MPI2_SGE_CHAIN_UNION
name|Chain
decl_stmt|;
name|MPI2_SGE_TRANSACTION_UNION
name|Transaction
decl_stmt|;
block|}
name|u
union|;
block|}
name|MPI2_MPI_SGE_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_MPI_SGE_UNION
operator|,
name|Mpi2MpiSgeUnion_t
operator|,
name|MPI2_POINTER
name|pMpi2MpiSgeUnion_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  MPI SGE field definition and masks ****************************************************************************/
end_comment

begin_comment
comment|/* Flags field bit definitions */
end_comment

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_LAST_ELEMENT
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_END_OF_BUFFER
value|(0x40)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_ELEMENT_TYPE_MASK
value|(0x30)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_LOCAL_ADDRESS
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_DIRECTION
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_ADDRESS_SIZE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_END_OF_LIST
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_SHIFT
value|(24)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_LENGTH_MASK
value|(0x00FFFFFF)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_CHAIN_LENGTH_MASK
value|(0x0000FFFF)
end_define

begin_comment
comment|/* Element Type */
end_comment

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_TRANSACTION_ELEMENT
value|(0x00)
end_define

begin_comment
comment|/* for MPI v2.0 products only */
end_comment

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_SIMPLE_ELEMENT
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_CHAIN_ELEMENT
value|(0x30)
end_define

begin_comment
comment|/* for MPI v2.0 products only */
end_comment

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_ELEMENT_MASK
value|(0x30)
end_define

begin_comment
comment|/* Address location */
end_comment

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_SYSTEM_ADDRESS
value|(0x00)
end_define

begin_comment
comment|/* Direction */
end_comment

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_IOC_TO_HOST
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_HOST_TO_IOC
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_DEST
value|(MPI2_SGE_FLAGS_IOC_TO_HOST)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_SOURCE
value|(MPI2_SGE_FLAGS_HOST_TO_IOC)
end_define

begin_comment
comment|/* Address Size */
end_comment

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_32_BIT_ADDRESSING
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_64_BIT_ADDRESSING
value|(0x02)
end_define

begin_comment
comment|/* Context Size */
end_comment

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_32_BIT_CONTEXT
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_64_BIT_CONTEXT
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_96_BIT_CONTEXT
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_128_BIT_CONTEXT
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_CHAIN_OFFSET_MASK
value|(0x00FF0000)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_CHAIN_OFFSET_SHIFT
value|(16)
end_define

begin_comment
comment|/**************************************************************************** *  MPI SGE operation Macros ****************************************************************************/
end_comment

begin_comment
comment|/* SIMPLE FlagsLength manipulations... */
end_comment

begin_define
define|#
directive|define
name|MPI2_SGE_SET_FLAGS
parameter_list|(
name|f
parameter_list|)
value|((U32)(f)<< MPI2_SGE_FLAGS_SHIFT)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_GET_FLAGS
parameter_list|(
name|f
parameter_list|)
value|(((f)& ~MPI2_SGE_LENGTH_MASK)>> MPI2_SGE_FLAGS_SHIFT)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_LENGTH
parameter_list|(
name|f
parameter_list|)
value|((f)& MPI2_SGE_LENGTH_MASK)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_CHAIN_LENGTH
parameter_list|(
name|f
parameter_list|)
value|((f)& MPI2_SGE_CHAIN_LENGTH_MASK)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_SET_FLAGS_LENGTH
parameter_list|(
name|f
parameter_list|,
name|l
parameter_list|)
value|(MPI2_SGE_SET_FLAGS(f) | MPI2_SGE_LENGTH(l))
end_define

begin_define
define|#
directive|define
name|MPI2_pSGE_GET_FLAGS
parameter_list|(
name|psg
parameter_list|)
value|MPI2_SGE_GET_FLAGS((psg)->FlagsLength)
end_define

begin_define
define|#
directive|define
name|MPI2_pSGE_GET_LENGTH
parameter_list|(
name|psg
parameter_list|)
value|MPI2_SGE_LENGTH((psg)->FlagsLength)
end_define

begin_define
define|#
directive|define
name|MPI2_pSGE_SET_FLAGS_LENGTH
parameter_list|(
name|psg
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
value|(psg)->FlagsLength = MPI2_SGE_SET_FLAGS_LENGTH(f,l)
end_define

begin_comment
comment|/* CAUTION - The following are READ-MODIFY-WRITE! */
end_comment

begin_define
define|#
directive|define
name|MPI2_pSGE_SET_FLAGS
parameter_list|(
name|psg
parameter_list|,
name|f
parameter_list|)
value|(psg)->FlagsLength |= MPI2_SGE_SET_FLAGS(f)
end_define

begin_define
define|#
directive|define
name|MPI2_pSGE_SET_LENGTH
parameter_list|(
name|psg
parameter_list|,
name|l
parameter_list|)
value|(psg)->FlagsLength |= MPI2_SGE_LENGTH(l)
end_define

begin_define
define|#
directive|define
name|MPI2_GET_CHAIN_OFFSET
parameter_list|(
name|x
parameter_list|)
value|((x& MPI2_SGE_CHAIN_OFFSET_MASK)>> MPI2_SGE_CHAIN_OFFSET_SHIFT)
end_define

begin_comment
comment|/***************************************************************************** * *        Fusion-MPT IEEE Scatter Gather Elements * *****************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************** *  IEEE Simple Element structures ****************************************************************************/
end_comment

begin_comment
comment|/* MPI2_IEEE_SGE_SIMPLE32 is for MPI v2.0 products only */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_IEEE_SGE_SIMPLE32
block|{
name|U32
name|Address
decl_stmt|;
name|U32
name|FlagsLength
decl_stmt|;
block|}
name|MPI2_IEEE_SGE_SIMPLE32
operator|,
name|MPI2_POINTER
name|PTR_MPI2_IEEE_SGE_SIMPLE32
operator|,
name|Mpi2IeeeSgeSimple32_t
operator|,
name|MPI2_POINTER
name|pMpi2IeeeSgeSimple32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_IEEE_SGE_SIMPLE64
block|{
name|U64
name|Address
decl_stmt|;
name|U32
name|Length
decl_stmt|;
name|U16
name|Reserved1
decl_stmt|;
name|U8
name|Reserved2
decl_stmt|;
name|U8
name|Flags
decl_stmt|;
block|}
name|MPI2_IEEE_SGE_SIMPLE64
operator|,
name|MPI2_POINTER
name|PTR_MPI2_IEEE_SGE_SIMPLE64
operator|,
name|Mpi2IeeeSgeSimple64_t
operator|,
name|MPI2_POINTER
name|pMpi2IeeeSgeSimple64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_MPI2_IEEE_SGE_SIMPLE_UNION
block|{
name|MPI2_IEEE_SGE_SIMPLE32
name|Simple32
decl_stmt|;
name|MPI2_IEEE_SGE_SIMPLE64
name|Simple64
decl_stmt|;
block|}
name|MPI2_IEEE_SGE_SIMPLE_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_IEEE_SGE_SIMPLE_UNION
operator|,
name|Mpi2IeeeSgeSimpleUnion_t
operator|,
name|MPI2_POINTER
name|pMpi2IeeeSgeSimpleUnion_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  IEEE Chain Element structures ****************************************************************************/
end_comment

begin_comment
comment|/* MPI2_IEEE_SGE_CHAIN32 is for MPI v2.0 products only */
end_comment

begin_typedef
typedef|typedef
name|MPI2_IEEE_SGE_SIMPLE32
name|MPI2_IEEE_SGE_CHAIN32
typedef|;
end_typedef

begin_comment
comment|/* MPI2_IEEE_SGE_CHAIN64 is for MPI v2.0 products only */
end_comment

begin_typedef
typedef|typedef
name|MPI2_IEEE_SGE_SIMPLE64
name|MPI2_IEEE_SGE_CHAIN64
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_MPI2_IEEE_SGE_CHAIN_UNION
block|{
name|MPI2_IEEE_SGE_CHAIN32
name|Chain32
decl_stmt|;
name|MPI2_IEEE_SGE_CHAIN64
name|Chain64
decl_stmt|;
block|}
name|MPI2_IEEE_SGE_CHAIN_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_IEEE_SGE_CHAIN_UNION
operator|,
name|Mpi2IeeeSgeChainUnion_t
operator|,
name|MPI2_POINTER
name|pMpi2IeeeSgeChainUnion_t
typedef|;
end_typedef

begin_comment
comment|/* MPI25_IEEE_SGE_CHAIN64 is for MPI v2.5 and later */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI25_IEEE_SGE_CHAIN64
block|{
name|U64
name|Address
decl_stmt|;
name|U32
name|Length
decl_stmt|;
name|U16
name|Reserved1
decl_stmt|;
name|U8
name|NextChainOffset
decl_stmt|;
name|U8
name|Flags
decl_stmt|;
block|}
name|MPI25_IEEE_SGE_CHAIN64
operator|,
name|MPI2_POINTER
name|PTR_MPI25_IEEE_SGE_CHAIN64
operator|,
name|Mpi25IeeeSgeChain64_t
operator|,
name|MPI2_POINTER
name|pMpi25IeeeSgeChain64_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  All IEEE SGE types union ****************************************************************************/
end_comment

begin_comment
comment|/* MPI2_IEEE_SGE_UNION is for MPI v2.0 products only */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_IEEE_SGE_UNION
block|{
union|union
block|{
name|MPI2_IEEE_SGE_SIMPLE_UNION
name|Simple
decl_stmt|;
name|MPI2_IEEE_SGE_CHAIN_UNION
name|Chain
decl_stmt|;
block|}
name|u
union|;
block|}
name|MPI2_IEEE_SGE_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_IEEE_SGE_UNION
operator|,
name|Mpi2IeeeSgeUnion_t
operator|,
name|MPI2_POINTER
name|pMpi2IeeeSgeUnion_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  IEEE SGE union for IO SGL's ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
union|union
name|_MPI25_SGE_IO_UNION
block|{
name|MPI2_IEEE_SGE_SIMPLE64
name|IeeeSimple
decl_stmt|;
name|MPI25_IEEE_SGE_CHAIN64
name|IeeeChain
decl_stmt|;
block|}
name|MPI25_SGE_IO_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI25_SGE_IO_UNION
operator|,
name|Mpi25SGEIOUnion_t
operator|,
name|MPI2_POINTER
name|pMpi25SGEIOUnion_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  IEEE SGE field definitions and masks ****************************************************************************/
end_comment

begin_comment
comment|/* Flags field bit definitions */
end_comment

begin_define
define|#
directive|define
name|MPI2_IEEE_SGE_FLAGS_ELEMENT_TYPE_MASK
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI25_IEEE_SGE_FLAGS_END_OF_LIST
value|(0x40)
end_define

begin_define
define|#
directive|define
name|MPI2_IEEE32_SGE_FLAGS_SHIFT
value|(24)
end_define

begin_define
define|#
directive|define
name|MPI2_IEEE32_SGE_LENGTH_MASK
value|(0x00FFFFFF)
end_define

begin_comment
comment|/* Element Type */
end_comment

begin_define
define|#
directive|define
name|MPI2_IEEE_SGE_FLAGS_SIMPLE_ELEMENT
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_IEEE_SGE_FLAGS_CHAIN_ELEMENT
value|(0x80)
end_define

begin_comment
comment|/* Next Segment Format */
end_comment

begin_define
define|#
directive|define
name|MPI26_IEEE_SGE_FLAGS_NSF_MASK
value|(0x1C)
end_define

begin_define
define|#
directive|define
name|MPI26_IEEE_SGE_FLAGS_NSF_MPI_IEEE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI26_IEEE_SGE_FLAGS_NSF_NVME_PRP
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI26_IEEE_SGE_FLAGS_NSF_NVME_SGL
value|(0x10)
end_define

begin_comment
comment|/* Data Location Address Space */
end_comment

begin_define
define|#
directive|define
name|MPI2_IEEE_SGE_FLAGS_ADDR_MASK
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_IEEE_SGE_FLAGS_SYSTEM_ADDR
value|(0x00)
end_define

begin_comment
comment|/* for MPI v2.0, use in IEEE Simple Element only; for MPI v2.5 and later, use in IEEE Simple or Chain element */
end_comment

begin_define
define|#
directive|define
name|MPI2_IEEE_SGE_FLAGS_IOCDDR_ADDR
value|(0x01)
end_define

begin_comment
comment|/* use in IEEE Simple Element only */
end_comment

begin_define
define|#
directive|define
name|MPI2_IEEE_SGE_FLAGS_IOCPLB_ADDR
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_IEEE_SGE_FLAGS_IOCPLBNTA_ADDR
value|(0x03)
end_define

begin_comment
comment|/* for MPI v2.0, use in IEEE Simple Element only; for MPI v2.5, use in IEEE Simple or Chain element */
end_comment

begin_define
define|#
directive|define
name|MPI2_IEEE_SGE_FLAGS_SYSTEMPLBPCI_ADDR
value|(0x03)
end_define

begin_comment
comment|/* use in MPI v2.0 IEEE Chain Element only */
end_comment

begin_define
define|#
directive|define
name|MPI2_IEEE_SGE_FLAGS_SYSTEMPLBCPI_ADDR
value|(MPI2_IEEE_SGE_FLAGS_SYSTEMPLBPCI_ADDR)
end_define

begin_comment
comment|/* typo in name */
end_comment

begin_define
define|#
directive|define
name|MPI26_IEEE_SGE_FLAGS_IOCCTL_ADDR
value|(0x02)
end_define

begin_comment
comment|/* for MPI v2.6 only */
end_comment

begin_comment
comment|/**************************************************************************** *  IEEE SGE operation Macros ****************************************************************************/
end_comment

begin_comment
comment|/* SIMPLE FlagsLength manipulations... */
end_comment

begin_define
define|#
directive|define
name|MPI2_IEEE32_SGE_SET_FLAGS
parameter_list|(
name|f
parameter_list|)
value|((U32)(f)<< MPI2_IEEE32_SGE_FLAGS_SHIFT)
end_define

begin_define
define|#
directive|define
name|MPI2_IEEE32_SGE_GET_FLAGS
parameter_list|(
name|f
parameter_list|)
value|(((f)& ~MPI2_IEEE32_SGE_LENGTH_MASK)>> MPI2_IEEE32_SGE_FLAGS_SHIFT)
end_define

begin_define
define|#
directive|define
name|MPI2_IEEE32_SGE_LENGTH
parameter_list|(
name|f
parameter_list|)
value|((f)& MPI2_IEEE32_SGE_LENGTH_MASK)
end_define

begin_define
define|#
directive|define
name|MPI2_IEEE32_SGE_SET_FLAGS_LENGTH
parameter_list|(
name|f
parameter_list|,
name|l
parameter_list|)
value|(MPI2_IEEE32_SGE_SET_FLAGS(f) | MPI2_IEEE32_SGE_LENGTH(l))
end_define

begin_define
define|#
directive|define
name|MPI2_IEEE32_pSGE_GET_FLAGS
parameter_list|(
name|psg
parameter_list|)
value|MPI2_IEEE32_SGE_GET_FLAGS((psg)->FlagsLength)
end_define

begin_define
define|#
directive|define
name|MPI2_IEEE32_pSGE_GET_LENGTH
parameter_list|(
name|psg
parameter_list|)
value|MPI2_IEEE32_SGE_LENGTH((psg)->FlagsLength)
end_define

begin_define
define|#
directive|define
name|MPI2_IEEE32_pSGE_SET_FLAGS_LENGTH
parameter_list|(
name|psg
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
value|(psg)->FlagsLength = MPI2_IEEE32_SGE_SET_FLAGS_LENGTH(f,l)
end_define

begin_comment
comment|/* CAUTION - The following are READ-MODIFY-WRITE! */
end_comment

begin_define
define|#
directive|define
name|MPI2_IEEE32_pSGE_SET_FLAGS
parameter_list|(
name|psg
parameter_list|,
name|f
parameter_list|)
value|(psg)->FlagsLength |= MPI2_IEEE32_SGE_SET_FLAGS(f)
end_define

begin_define
define|#
directive|define
name|MPI2_IEEE32_pSGE_SET_LENGTH
parameter_list|(
name|psg
parameter_list|,
name|l
parameter_list|)
value|(psg)->FlagsLength |= MPI2_IEEE32_SGE_LENGTH(l)
end_define

begin_comment
comment|/***************************************************************************** * *        Fusion-MPT MPI/IEEE Scatter Gather Unions * *****************************************************************************/
end_comment

begin_typedef
typedef|typedef
union|union
name|_MPI2_SIMPLE_SGE_UNION
block|{
name|MPI2_SGE_SIMPLE_UNION
name|MpiSimple
decl_stmt|;
name|MPI2_IEEE_SGE_SIMPLE_UNION
name|IeeeSimple
decl_stmt|;
block|}
name|MPI2_SIMPLE_SGE_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SIMPLE_SGE_UNION
operator|,
name|Mpi2SimpleSgeUntion_t
operator|,
name|MPI2_POINTER
name|pMpi2SimpleSgeUntion_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_MPI2_SGE_IO_UNION
block|{
name|MPI2_SGE_SIMPLE_UNION
name|MpiSimple
decl_stmt|;
name|MPI2_SGE_CHAIN_UNION
name|MpiChain
decl_stmt|;
name|MPI2_IEEE_SGE_SIMPLE_UNION
name|IeeeSimple
decl_stmt|;
name|MPI2_IEEE_SGE_CHAIN_UNION
name|IeeeChain
decl_stmt|;
block|}
name|MPI2_SGE_IO_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SGE_IO_UNION
operator|,
name|Mpi2SGEIOUnion_t
operator|,
name|MPI2_POINTER
name|pMpi2SGEIOUnion_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** * *  Values for SGLFlags field, used in many request messages with an SGL * ****************************************************************************/
end_comment

begin_comment
comment|/* values for MPI SGL Data Location Address Space subfield */
end_comment

begin_define
define|#
directive|define
name|MPI2_SGLFLAGS_ADDRESS_SPACE_MASK
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI2_SGLFLAGS_SYSTEM_ADDRESS_SPACE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SGLFLAGS_IOCDDR_ADDRESS_SPACE
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_SGLFLAGS_IOCPLB_ADDRESS_SPACE
value|(0x08)
end_define

begin_comment
comment|/* only for MPI v2.5 and earlier */
end_comment

begin_define
define|#
directive|define
name|MPI26_SGLFLAGS_IOCPLB_ADDRESS_SPACE
value|(0x08)
end_define

begin_comment
comment|/* only for MPI v2.6 */
end_comment

begin_define
define|#
directive|define
name|MPI2_SGLFLAGS_IOCPLBNTA_ADDRESS_SPACE
value|(0x0C)
end_define

begin_comment
comment|/* only for MPI v2.5 and earlier */
end_comment

begin_comment
comment|/* values for SGL Type subfield */
end_comment

begin_define
define|#
directive|define
name|MPI2_SGLFLAGS_SGL_TYPE_MASK
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_SGLFLAGS_SGL_TYPE_MPI
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SGLFLAGS_SGL_TYPE_IEEE32
value|(0x01)
end_define

begin_comment
comment|/* MPI v2.0 products only */
end_comment

begin_define
define|#
directive|define
name|MPI2_SGLFLAGS_SGL_TYPE_IEEE64
value|(0x02)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

