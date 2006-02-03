begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2000-2005, LSI Logic Corporation and its contributors.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon including  *    a substantially similar Disclaimer requirement for further binary  *    redistribution.  * 3. Neither the name of the LSI Logic Corporation nor the names of its  *    contributors may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF THE COPYRIGHT  * OWNER OR CONTRIBUTOR IS ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *                                                                         *  ***************************************************************************  *  *           Name:  iopiIocLogInfo.h  *          Title:  SAS Firmware IOP Interface IOC Log Info Definitions  *     Programmer:  Guy Kendall  *  Creation Date:  September 24, 2003  *  *  Version History  *  ---------------  *  *  Last Updated  *  -------------  *  Version         %version: 22 %  *  Date Updated    %date_modified: %  *  Programmer      %created_by: nperucca %  *  *  Date      Who   Description  *  --------  ---   -------------------------------------------------------  *  09/24/03  GWK   Initial version  *  *  * Description  * ------------  * This include file contains SAS firmware interface IOC Log Info codes  *  *-------------------------------------------------------------------------  */
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
name|IOP_LOGINFO_CODE_TASK_TERMINATED
value|(0x00050000)
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

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_ABORT
value|(0x00120000)
end_define

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
name|PL_LOGINFO_SUB_CODE_OPEN_FAILURE
value|(0x00000100)
end_define

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
name|PL_LOGINFO_SUB_CODE_DSCVRY_SATA_INIT_TIMEOUT
value|(0x00001000)
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
value|(0x00200001)
end_define

begin_comment
comment|/* Error occured on SMP Read */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_ENCL_MGMT_SMP_WRITE_ERROR
value|(0x00200002)
end_define

begin_comment
comment|/* Error occured on SMP Write */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_ENCL_MGMT_NOT_SUPPORTED_ON_ENCL
value|(0x00200004)
end_define

begin_comment
comment|/* Encl Mgmt services not available for this WWID */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_ENCL_MGMT_ADDR_MODE_NOT_SUPPORTED
value|(0x00200005)
end_define

begin_comment
comment|/* Address Mode not suppored */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_ENCL_MGMT_BAD_SLOT_NUM
value|(0x00200006)
end_define

begin_comment
comment|/* Invalid Slot Number in SEP Msg */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_CODE_ENCL_MGMT_SGPIO_NOT_PRESENT
value|(0x00200007)
end_define

begin_comment
comment|/* SGPIO not present/enabled */
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
name|PL_LOGINFO_DA_SEP_BAD_STATUS_HDR_CHKSUM
value|(0x00200104)
end_define

begin_comment
comment|/* SEP stopped or sent bad chksum in Hdr */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_DA_SEP_UNSUPPORTED_SCSI_STATUS_1
value|(0x00200105)
end_define

begin_comment
comment|/* SEP returned unknown scsi status */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_DA_SEP_UNSUPPORTED_SCSI_STATUS_2
value|(0x00200106)
end_define

begin_comment
comment|/* SEP returned unknown scsi status */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_DA_SEP_CHKSUM_ERROR_AFTER_STOP
value|(0x00200107)
end_define

begin_comment
comment|/* SEP returned bad chksum after STOP */
end_comment

begin_define
define|#
directive|define
name|PL_LOGINFO_DA_SEP_CHKSUM_ERROR_AFTER_STOP_GETDATA
value|(0x00200108)
end_define

begin_comment
comment|/* SEP returned bad chksum after STOP while gettin data*/
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
name|IR_LOGINFO_CODE_UNUSED1
value|(0x00010000)
end_define

begin_define
define|#
directive|define
name|IR_LOGINFO_CODE_UNUSED2
value|(0x00020000)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Defines for convienence                                                  */
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

