begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2000-2010, LSI Logic Corporation and its contributors.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon including  *    a substantially similar Disclaimer requirement for further binary  *    redistribution.  * 3. Neither the name of the LSI Logic Corporation nor the names of its  *    contributors may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF THE COPYRIGHT  * OWNER OR CONTRIBUTOR IS ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/***************************************************************************  *                                                                         *  * Description                                                             *  * ------------                                                            *  * This include file contains SAS firmware interface IOC Log Info codes    *  *                                                                         *  *-------------------------------------------------------------------------*  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IOPI_IOCLOGINFO_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|IOPI_IOCLOGINFO_H_INCLUDED
end_define

begin_define
define|#
directive|define
name|SAS_LOGINFO_NEXUS_LOSS
value|0x31170000
end_define

begin_define
define|#
directive|define
name|SAS_LOGINFO_MASK
value|0xFFFF0000
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  IOC LOGINFO defines, 0x00000000 - 0x0FFFFFFF                            */
end_comment

begin_comment
comment|/*  Format:                                                                 */
end_comment

begin_comment
comment|/*      Bits 31-28: MPI_IOCLOGINFO_TYPE_SAS (3)                             */
end_comment

begin_comment
comment|/*      Bits 27-24: IOC_LOGINFO_ORIGINATOR: 0=IOP, 1=PL, 2=IR               */
end_comment

begin_comment
comment|/*      Bits 23-16: LOGINFO_CODE                                            */
end_comment

begin_comment
comment|/*      Bits 15-0:  LOGINFO_CODE Specific                                   */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* IOC_LOGINFO_ORIGINATOR defines                                           */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|IOC_LOGINFO_ORIGINATOR_IOP
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|IOC_LOGINFO_ORIGINATOR_PL
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|IOC_LOGINFO_ORIGINATOR_IR
value|(0x02000000)
end_define

begin_define
define|#
directive|define
name|IOC_LOGINFO_ORIGINATOR_MASK
value|(0x0F000000)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* LOGINFO_CODE defines                                                     */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|IOC_LOGINFO_CODE_MASK
value|(0x00FF0000)
end_define

begin_define
define|#
directive|define
name|IOC_LOGINFO_CODE_SHIFT
value|(16)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* IOP LOGINFO_CODE defines, valid if IOC_LOGINFO_ORIGINATOR = IOP          */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_INVALID_SAS_ADDRESS
value|(0x00010000)
end_define

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_UNUSED2
value|(0x00020000)
end_define

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_CONFIG_INVALID_PAGE
value|(0x00030000)
end_define

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_CONFIG_INVALID_PAGE_RT
value|(0x00030100)
end_define

begin_comment
comment|/* Route Table Entry not found */
end_comment

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_CONFIG_INVALID_PAGE_PN
value|(0x00030200)
end_define

begin_comment
comment|/* Invalid Page Number */
end_comment

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_CONFIG_INVALID_PAGE_FORM
value|(0x00030300)
end_define

begin_comment
comment|/* Invalid FORM */
end_comment

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_CONFIG_INVALID_PAGE_PT
value|(0x00030400)
end_define

begin_comment
comment|/* Invalid Page Type */
end_comment

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_CONFIG_INVALID_PAGE_DNM
value|(0x00030500)
end_define

begin_comment
comment|/* Device Not Mapped */
end_comment

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_CONFIG_INVALID_PAGE_PERSIST
value|(0x00030600)
end_define

begin_comment
comment|/* Persistent Page not found */
end_comment

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_CONFIG_INVALID_PAGE_DEFAULT
value|(0x00030700)
end_define

begin_comment
comment|/* Default Page not found */
end_comment

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_FWUPLOAD_NO_FLASH_AVAILABLE
value|(0x0003E000)
end_define

begin_comment
comment|/* Tried to upload from flash, but there is none */
end_comment

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_FWUPLOAD_UNKNOWN_IMAGE_TYPE
value|(0x0003E001)
end_define

begin_comment
comment|/* ImageType field contents were invalid */
end_comment

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_FWUPLOAD_WRONG_IMAGE_SIZE
value|(0x0003E002)
end_define

begin_comment
comment|/* ImageSize field in TCSGE was bad/offset in MfgPg 4 was wrong */
end_comment

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_FWUPLOAD_ENTIRE_FLASH_UPLOAD_FAILED
value|(0x0003E003)
end_define

begin_comment
comment|/* Error occurred while attempting to upload the entire flash */
end_comment

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_FWUPLOAD_REGION_UPLOAD_FAILED
value|(0x0003E004)
end_define

begin_comment
comment|/* Error occurred while attempting to upload single flash region */
end_comment

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_FWUPLOAD_DMA_FAILURE
value|(0x0003E005)
end_define

begin_comment
comment|/* Problem occurred while DMAing FW to host memory */
end_comment

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_DIAG_MSG_ERROR
value|(0x00040000)
end_define

begin_comment
comment|/* Error handling diag msg - or'd with diag status */
end_comment

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_TASK_TERMINATED
value|(0x00050000)
end_define

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_ENCL_MGMT_READ_ACTION_ERR0R
value|(0x00060001)
end_define

begin_comment
comment|/* Read Action not supported for SEP msg */
end_comment

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_ENCL_MGMT_INVALID_BUS_ID_ERR0R
value|(0x00060002)
end_define

begin_comment
comment|/* Invalid Bus/ID in SEP msg */
end_comment

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_TARGET_ASSIST_TERMINATED
value|(0x00070001)
end_define

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_TARGET_STATUS_SEND_TERMINATED
value|(0x00070002)
end_define

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_TARGET_MODE_ABORT_ALL_IO
value|(0x00070003)
end_define

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_TARGET_MODE_ABORT_EXACT_IO
value|(0x00070004)
end_define

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_TARGET_MODE_ABORT_EXACT_IO_REQ
value|(0x00070005)
end_define

begin_define
define|#
directive|define
name|IOP_LOGINFO_CODE_LOG_TIMESTAMP_EVENT
value|(0x00080000)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* PL LOGINFO_CODE defines, valid if IOC_LOGINFO_ORIGINATOR = PL            */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_OPEN_FAILURE
value|(0x00010000)
end_define

begin_comment
comment|/* see SUB_CODE_OPEN_FAIL_ below */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_NO_DEST_TIME_OUT
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_PATHWAY_BLOCKED
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_RES_CONTINUE0
value|(0x00000003)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_RES_CONTINUE1
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_RES_INITIALIZE0
value|(0x00000005)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_RES_INITIALIZE1
value|(0x00000006)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_RES_STOP0
value|(0x00000007)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_RES_STOP1
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_RETRY
value|(0x00000009)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_BREAK
value|(0x0000000A)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_UNUSED_0B
value|(0x0000000B)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_OPEN_TIMEOUT_EXP
value|(0x0000000C)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_UNUSED_0D
value|(0x0000000D)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_DVTBLE_ACCSS_FAIL
value|(0x0000000E)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_BAD_DEST
value|(0x00000011)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_RATE_NOT_SUPP
value|(0x00000012)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_PROT_NOT_SUPP
value|(0x00000013)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_RESERVED_ABANDON0
value|(0x00000014)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_RESERVED_ABANDON1
value|(0x00000015)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_RESERVED_ABANDON2
value|(0x00000016)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_RESERVED_ABANDON3
value|(0x00000017)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_STP_RESOURCES_BSY
value|(0x00000018)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_WRONG_DESTINATION
value|(0x00000019)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_PATH_BLOCKED
value|(0x0000001B)
end_define

begin_comment
comment|/* Retry Timeout */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAIL_AWT_MAXED
value|(0x0000001C)
end_define

begin_comment
comment|/* Retry Timeout */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_INVALID_SGL
value|(0x00020000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_WRONG_REL_OFF_OR_FRAME_LENGTH
value|(0x00030000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_FRAME_XFER_ERROR
value|(0x00040000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_TX_FM_CONNECTED_LOW
value|(0x00050000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_SATA_NON_NCQ_RW_ERR_BIT_SET
value|(0x00060000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_SATA_READ_LOG_RECEIVE_DATA_ERR
value|(0x00070000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_SATA_NCQ_FAIL_ALL_CMDS_AFTR_ERR
value|(0x00080000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_SATA_ERR_IN_RCV_SET_DEV_BIT_FIS
value|(0x00090000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_RX_FM_INVALID_MESSAGE
value|(0x000A0000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_RX_CTX_MESSAGE_VALID_ERROR
value|(0x000B0000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_RX_FM_CURRENT_FRAME_ERROR
value|(0x000C0000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_SATA_LINK_DOWN
value|(0x000D0000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_DISCOVERY_SATA_INIT_W_IOS
value|(0x000E0000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_CONFIG_INVALID_PAGE
value|(0x000F0000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_CONFIG_PL_NOT_INITIALIZED
value|(0x000F0001)
end_define

begin_comment
comment|/* PL not yet initialized, can't do config page req. */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_CONFIG_INVALID_PAGE_PT
value|(0x000F0100)
end_define

begin_comment
comment|/* Invalid Page Type */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_CONFIG_INVALID_PAGE_NUM_PHYS
value|(0x000F0200)
end_define

begin_comment
comment|/* Invalid Number of Phys */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_CONFIG_INVALID_PAGE_NOT_IMP
value|(0x000F0300)
end_define

begin_comment
comment|/* Case Not Handled */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_CONFIG_INVALID_PAGE_NO_DEV
value|(0x000F0400)
end_define

begin_comment
comment|/* No Device Found */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_CONFIG_INVALID_PAGE_FORM
value|(0x000F0500)
end_define

begin_comment
comment|/* Invalid FORM */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_CONFIG_INVALID_PAGE_PHY
value|(0x000F0600)
end_define

begin_comment
comment|/* Invalid Phy */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_CONFIG_INVALID_PAGE_NO_OWNER
value|(0x000F0700)
end_define

begin_comment
comment|/* No Owner Found */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_DSCVRY_SATA_INIT_TIMEOUT
value|(0x00100000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_RESET
value|(0x00110000)
end_define

begin_comment
comment|/* See Sub-Codes below (PL_LOGINFO_SUB_CODE) */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_ABORT
value|(0x00120000)
end_define

begin_comment
comment|/* See Sub-Codes below  (PL_LOGINFO_SUB_CODE)*/
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_IO_NOT_YET_EXECUTED
value|(0x00130000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_IO_EXECUTED
value|(0x00140000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_PERS_RESV_OUT_NOT_AFFIL_OWNER
value|(0x00150000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_OPEN_TXDMA_ABORT
value|(0x00160000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_IO_DEVICE_MISSING_DELAY_RETRY
value|(0x00170000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_IO_CANCELLED_DUE_TO_R_ERR
value|(0x00180000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAILURE
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAILURE_NO_DEST_TIMEOUT
value|(0x00000101)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAILURE_SATA_NEG_RATE_2HI
value|(0x00000102)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAILURE_RATE_NOT_SUPPORTED
value|(0x00000103)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAILURE_BREAK
value|(0x00000104)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAILURE_ZONE_VIOLATION
value|(0x00000114)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAILURE_ABANDON0
value|(0x00000114)
end_define

begin_comment
comment|/* Open Reject (Zone Violation) - available on SAS-2 devices */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAILURE_ABANDON1
value|(0x00000115)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAILURE_ABANDON2
value|(0x00000116)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAILURE_ABANDON3
value|(0x00000117)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAILURE_ORR_TIMEOUT
value|(0x0000011A)
end_define

begin_comment
comment|/* Open Reject (Retry) Timeout */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAILURE_PATH_BLOCKED
value|(0x0000011B)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_OPEN_FAILURE_AWT_MAXED
value|(0x0000011C)
end_define

begin_comment
comment|/* Arbitration Wait Timer Maxed */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_TARGET_BUS_RESET
value|(0x00000120)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_TRANSPORT_LAYER
value|(0x00000130)
end_define

begin_comment
comment|/* Leave lower nibble (1-f) reserved. */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_PORT_LAYER
value|(0x00000140)
end_define

begin_comment
comment|/* Leave lower nibble (1-f) reserved. */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_INVALID_SGL
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_WRONG_REL_OFF_OR_FRAME_LENGTH
value|(0x00000300)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_FRAME_XFER_ERROR
value|(0x00000400)
end_define

begin_comment
comment|/* Bits 0-3 encode Transport Status Register (offset 0x08) */
end_comment

begin_comment
comment|/* Bit 0 is Status Bit 0: FrameXferErr */
end_comment

begin_comment
comment|/* Bit 1& 2 are Status Bits 16 and 17: FrameXmitErrStatus */
end_comment

begin_comment
comment|/* Bit 3 is Status Bit 18 WriteDataLenghtGTDataLengthErr */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_TX_FM_CONNECTED_LOW
value|(0x00000500)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_SATA_NON_NCQ_RW_ERR_BIT_SET
value|(0x00000600)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_SATA_READ_LOG_RECEIVE_DATA_ERR
value|(0x00000700)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_SATA_NCQ_FAIL_ALL_CMDS_AFTR_ERR
value|(0x00000800)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_SATA_ERR_IN_RCV_SET_DEV_BIT_FIS
value|(0x00000900)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_RX_FM_INVALID_MESSAGE
value|(0x00000A00)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_RX_CTX_MESSAGE_VALID_ERROR
value|(0x00000B00)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_RX_FM_CURRENT_FRAME_ERROR
value|(0x00000C00)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_SATA_LINK_DOWN
value|(0x00000D00)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_DISCOVERY_SATA_INIT_W_IOS
value|(0x00000E00)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_DISCOVERY_REMOTE_SEP_RESET
value|(0x00000E01)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_SECOND_OPEN
value|(0x00000F00)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_DSCVRY_SATA_INIT_TIMEOUT
value|(0x00001000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_BREAK_ON_SATA_CONNECTION
value|(0x00002000)
end_define

begin_comment
comment|/* not currently used in mainline */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_BREAK_ON_STUCK_LINK
value|(0x00003000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_BREAK_ON_STUCK_LINK_AIP
value|(0x00004000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_SUB_CODE_BREAK_ON_INCOMPLETE_BREAK_RCVD
value|(0x00005000)
end_define

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_ENCL_MGMT_SMP_FRAME_FAILURE
value|(0x00200000)
end_define

begin_comment
comment|/* Can't get SMP Frame */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_ENCL_MGMT_SMP_READ_ERROR
value|(0x00200010)
end_define

begin_comment
comment|/* Error occurred on SMP Read */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_ENCL_MGMT_SMP_WRITE_ERROR
value|(0x00200020)
end_define

begin_comment
comment|/* Error occurred on SMP Write */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_ENCL_MGMT_NOT_SUPPORTED_ON_ENCL
value|(0x00200040)
end_define

begin_comment
comment|/* Encl Mgmt services not available for this WWID */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_ENCL_MGMT_ADDR_MODE_NOT_SUPPORTED
value|(0x00200050)
end_define

begin_comment
comment|/* Address Mode not suppored */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_ENCL_MGMT_BAD_SLOT_NUM
value|(0x00200060)
end_define

begin_comment
comment|/* Invalid Slot Number in SEP Msg */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_ENCL_MGMT_SGPIO_NOT_PRESENT
value|(0x00200070)
end_define

begin_comment
comment|/* SGPIO not present/enabled */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_ENCL_MGMT_GPIO_NOT_CONFIGURED
value|(0x00200080)
end_define

begin_comment
comment|/* GPIO not configured */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_ENCL_MGMT_GPIO_FRAME_ERROR
value|(0x00200090)
end_define

begin_comment
comment|/* GPIO can't allocate a frame */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_ENCL_MGMT_GPIO_CONFIG_PAGE_ERROR
value|(0x002000A0)
end_define

begin_comment
comment|/* GPIO failed config page request */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_ENCL_MGMT_SES_FRAME_ALLOC_ERROR
value|(0x002000B0)
end_define

begin_comment
comment|/* Can't get frame for SES command */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_ENCL_MGMT_SES_IO_ERROR
value|(0x002000C0)
end_define

begin_comment
comment|/* I/O execution error */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_ENCL_MGMT_SES_RETRIES_EXHAUSTED
value|(0x002000D0)
end_define

begin_comment
comment|/* SEP I/O retries exhausted */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_ENCL_MGMT_SMP_FRAME_ALLOC_ERROR
value|(0x002000E0)
end_define

begin_comment
comment|/* Can't get frame for SMP command */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_DA_SEP_NOT_PRESENT
value|(0x00200100)
end_define

begin_comment
comment|/* SEP not present when msg received */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_DA_SEP_SINGLE_THREAD_ERROR
value|(0x00200101)
end_define

begin_comment
comment|/* Can only accept 1 msg at a time */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_DA_SEP_ISTWI_INTR_IN_IDLE_STATE
value|(0x00200102)
end_define

begin_comment
comment|/* ISTWI interrupt recvd. while IDLE */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_DA_SEP_RECEIVED_NACK_FROM_SLAVE
value|(0x00200103)
end_define

begin_comment
comment|/* SEP NACK'd, it is busy */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_DA_SEP_DID_NOT_RECEIVE_ACK
value|(0x00200104)
end_define

begin_comment
comment|/* SEP didn't rcv. ACK (Last Rcvd Bit = 1) */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_DA_SEP_BAD_STATUS_HDR_CHKSUM
value|(0x00200105)
end_define

begin_comment
comment|/* SEP stopped or sent bad chksum in Hdr */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_DA_SEP_STOP_ON_DATA
value|(0x00200106)
end_define

begin_comment
comment|/* SEP stopped while transferring data */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_DA_SEP_STOP_ON_SENSE_DATA
value|(0x00200107)
end_define

begin_comment
comment|/* SEP stopped while transferring sense data */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_DA_SEP_UNSUPPORTED_SCSI_STATUS_1
value|(0x00200108)
end_define

begin_comment
comment|/* SEP returned unknown scsi status */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_DA_SEP_UNSUPPORTED_SCSI_STATUS_2
value|(0x00200109)
end_define

begin_comment
comment|/* SEP returned unknown scsi status */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_DA_SEP_CHKSUM_ERROR_AFTER_STOP
value|(0x0020010A)
end_define

begin_comment
comment|/* SEP returned bad chksum after STOP */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_DA_SEP_CHKSUM_ERROR_AFTER_STOP_GETDATA
value|(0x0020010B)
end_define

begin_comment
comment|/* SEP returned bad chksum after STOP while gettin data*/
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_DA_SEP_UNSUPPORTED_COMMAND
value|(0x0020010C)
end_define

begin_comment
comment|/* SEP doesn't support CDB opcode f/w location 1 */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_DA_SEP_UNSUPPORTED_COMMAND_2
value|(0x0020010D)
end_define

begin_comment
comment|/* SEP doesn't support CDB opcode f/w location 2 */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_DA_SEP_UNSUPPORTED_COMMAND_3
value|(0x0020010E)
end_define

begin_comment
comment|/* SEP doesn't support CDB opcode f/w location 3 */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* IR LOGINFO_CODE defines, valid if IOC_LOGINFO_ORIGINATOR = IR            */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_RAID_ACTION_ERROR
value|(0x00010000)
end_define

begin_define
define|#
directive|define
name|IR_LOGINFO_CODE_UNUSED2
value|(0x00020000)
end_define

begin_comment
comment|/* Amount of information passed down for Create Volume is too large */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_VOLUME_CREATE_INVALID_LENGTH
value|(0x00010001)
end_define

begin_comment
comment|/* Creation of duplicate volume attempted (Bus/Target ID checked) */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_VOLUME_CREATE_DUPLICATE
value|(0x00010002)
end_define

begin_comment
comment|/* Creation failed due to maximum number of supported volumes exceeded */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_VOLUME_CREATE_NO_SLOTS
value|(0x00010003)
end_define

begin_comment
comment|/* Creation failed due to DMA error in trying to read from host */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_VOLUME_CREATE_DMA_ERROR
value|(0x00010004)
end_define

begin_comment
comment|/* Creation failed due to invalid volume type passed down */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_VOLUME_CREATE_INVALID_VOLUME_TYPE
value|(0x00010005)
end_define

begin_comment
comment|/* Creation failed due to error reading MFG Page 4 */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_VOLUME_MFG_PAGE4_ERROR
value|(0x00010006)
end_define

begin_comment
comment|/* Creation failed when trying to create internal structures */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_VOLUME_INTERNAL_CONFIG_STRUCTURE_ERROR
value|(0x00010007)
end_define

begin_comment
comment|/* Activation failed due to trying to activate an already active volume */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_VOLUME_ACTIVATING_AN_ACTIVE_VOLUME
value|(0x00010010)
end_define

begin_comment
comment|/* Activation failed due to trying to active unsupported volume type  */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_VOLUME_ACTIVATING_INVALID_VOLUME_TYPE
value|(0x00010011)
end_define

begin_comment
comment|/* Activation failed due to trying to active too many volumes  */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_VOLUME_ACTIVATING_TOO_MANY_VOLUMES
value|(0x00010012)
end_define

begin_comment
comment|/* Activation failed due to Volume ID in use already */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_VOLUME_ACTIVATING_VOLUME_ID_IN_USE
value|(0x00010013)
end_define

begin_comment
comment|/* Activation failed call to activateVolume returned failure */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_VOLUME_ACTIVATE_VOLUME_FAILED
value|(0x00010014)
end_define

begin_comment
comment|/* Activation failed trying to import the volume */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_VOLUME_ACTIVATING_IMPORT_VOLUME_FAILED
value|(0x00010015)
end_define

begin_comment
comment|/* Activation failed trying to import the volume */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_VOLUME_ACTIVATING_TOO_MANY_PHYS_DISKS
value|(0x00010016)
end_define

begin_comment
comment|/* Phys Disk failed, too many phys disks */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_PHYSDISK_CREATE_TOO_MANY_DISKS
value|(0x00010020)
end_define

begin_comment
comment|/* Amount of information passed down for Create Pnysdisk is too large */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_PHYSDISK_CREATE_INVALID_LENGTH
value|(0x00010021)
end_define

begin_comment
comment|/* Creation failed due to DMA error in trying to read from host */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_PHYSDISK_CREATE_DMA_ERROR
value|(0x00010022)
end_define

begin_comment
comment|/* Creation failed due to invalid Bus TargetID passed down */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_PHYSDISK_CREATE_BUS_TID_INVALID
value|(0x00010023)
end_define

begin_comment
comment|/* Creation failed due to error in creating RAID Phys Disk Config Page */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_PHYSDISK_CREATE_CONFIG_PAGE_ERROR
value|(0x00010024)
end_define

begin_comment
comment|/* Compatibility Error : IR Disabled */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_COMPAT_ERROR_RAID_DISABLED
value|(0x00010030)
end_define

begin_comment
comment|/* Compatibility Error : Inquiry Comand failed */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_COMPAT_ERROR_INQUIRY_FAILED
value|(0x00010031)
end_define

begin_comment
comment|/* Compatibility Error : Device not direct access device */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_COMPAT_ERROR_NOT_DIRECT_ACCESS
value|(0x00010032)
end_define

begin_comment
comment|/* Compatibility Error : Removable device found */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_COMPAT_ERROR_REMOVABLE_FOUND
value|(0x00010033)
end_define

begin_comment
comment|/* Compatibility Error : Device SCSI Version not 2 or higher */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_COMPAT_ERROR_NEED_SCSI_2_OR_HIGHER
value|(0x00010034)
end_define

begin_comment
comment|/* Compatibility Error : SATA device, 48 BIT LBA not supported */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_COMPAT_ERROR_SATA_48BIT_LBA_NOT_SUPPORTED
value|(0x00010035)
end_define

begin_comment
comment|/* Compatibility Error : Device does not have 512 byte block sizes */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_COMPAT_ERROR_DEVICE_NOT_512_BYTE_BLOCK
value|(0x00010036)
end_define

begin_comment
comment|/* Compatibility Error : Volume Type check failed */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_COMPAT_ERROR_VOLUME_TYPE_CHECK_FAILED
value|(0x00010037)
end_define

begin_comment
comment|/* Compatibility Error : Volume Type is unsupported by FW */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_COMPAT_ERROR_UNSUPPORTED_VOLUME_TYPE
value|(0x00010038)
end_define

begin_comment
comment|/* Compatibility Error : Disk drive too small for use in volume */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_COMPAT_ERROR_DISK_TOO_SMALL
value|(0x00010039)
end_define

begin_comment
comment|/* Compatibility Error : Phys disk for Create Volume not found */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_COMPAT_ERROR_PHYS_DISK_NOT_FOUND
value|(0x0001003A)
end_define

begin_comment
comment|/* Compatibility Error : membership count error, too many or too few disks for volume type */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_COMPAT_ERROR_MEMBERSHIP_COUNT
value|(0x0001003B)
end_define

begin_comment
comment|/* Compatibility Error : Disk stripe sizes must be 64KB */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_COMPAT_ERROR_NON_64K_STRIPE_SIZE
value|(0x0001003C)
end_define

begin_comment
comment|/* Compatibility Error : IME size limited to< 2TB */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_COMPAT_ERROR_IME_VOL_NOT_CURRENTLY_SUPPORTED
value|(0x0001003D)
end_define

begin_comment
comment|/* Device Firmware Update: DFU can only be started once */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_DEV_FW_UPDATE_ERR_DFU_IN_PROGRESS
value|(0x00010050)
end_define

begin_comment
comment|/* Device Firmware Update: Volume must be Optimal/Active/non-Quiesced */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_DEV_FW_UPDATE_ERR_DEVICE_IN_INVALID_STATE
value|(0x00010051)
end_define

begin_comment
comment|/* Device Firmware Update: DFU Timeout cannot be zero */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_DEV_FW_UPDATE_ERR_INVALID_TIMEOUT
value|(0x00010052)
end_define

begin_comment
comment|/* Device Firmware Update: CREATE TIMER FAILED */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_DEV_FW_UPDATE_ERR_NO_TIMERS
value|(0x00010053)
end_define

begin_comment
comment|/* Device Firmware Update: Failed to read SAS_IO_UNIT_PG_1 */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_DEV_FW_UPDATE_ERR_READING_CFG_PAGE
value|(0x00010054)
end_define

begin_comment
comment|/* Device Firmware Update: Invalid SAS_IO_UNIT_PG_1 value(s) */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_DEV_FW_UPDATE_ERR_PORT_IO_TIMEOUTS_REQUIRED
value|(0x00010055)
end_define

begin_comment
comment|/* Device Firmware Update: Unable to allocate memory for page */
end_comment

begin_define
define|#
directive|define
name|IR_LOGINFO_DEV_FW_UPDATE_ERR_ALLOC_CFG_PAGE
value|(0x00010056)
end_define

begin_comment
comment|/* Device Firmware Update:  */
end_comment

begin_comment
comment|//#define IR_LOGINFO_DEV_FW_UPDATE_ERR_                         (0x00010054)
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Defines for convenience                                                  */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|IOC_LOGINFO_PREFIX_IOP
value|((MPI_IOCLOGINFO_TYPE_SAS<< MPI_IOCLOGINFO_TYPE_SHIFT) | IOC_LOGINFO_ORIGINATOR_IOP)
end_define

begin_define
define|#
directive|define
name|IOC_LOGINFO_PREFIX_PL
value|((MPI_IOCLOGINFO_TYPE_SAS<< MPI_IOCLOGINFO_TYPE_SHIFT) | IOC_LOGINFO_ORIGINATOR_PL)
end_define

begin_define
define|#
directive|define
name|IOC_LOGINFO_PREFIX_IR
value|((MPI_IOCLOGINFO_TYPE_SAS<< MPI_IOCLOGINFO_TYPE_SHIFT) | IOC_LOGINFO_ORIGINATOR_IR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* end of file */
end_comment

end_unit

