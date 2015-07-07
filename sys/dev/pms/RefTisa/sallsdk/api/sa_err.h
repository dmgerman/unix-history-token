begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/*! \file sa_err.h  *  \brief The file defines the error code constants, defined by LL API  *  *  */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SA_ERR_H__
end_ifndef

begin_define
define|#
directive|define
name|__SA_ERR_H__
end_define

begin_comment
comment|/************************************************************************************  *                                                                                  *  *               Error Code Constants defined for LL Layer starts                   *  *                                                                                  *  ************************************************************************************/
end_comment

begin_comment
comment|/***********************************************************************************  *                    SSP/SMP/SATA IO Completion Status values  ***********************************************************************************/
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_SUCCESS
value|0x00
end_define

begin_comment
comment|/**< IO completes successfully */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_ABORTED
value|0x01
end_define

begin_comment
comment|/**< IO aborted */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_OVERFLOW
value|0x02
end_define

begin_comment
comment|/**< IO overflowed (SSP) */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_UNDERFLOW
value|0x03
end_define

begin_comment
comment|/**< IO underflowed (SSP) */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_FAILED
value|0x04
end_define

begin_comment
comment|/**< IO failed */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_ABORT_RESET
value|0x05
end_define

begin_comment
comment|/**< IO abort because of reset */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_NOT_VALID
value|0x06
end_define

begin_comment
comment|/**< IO not valid */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_NO_DEVICE
value|0x07
end_define

begin_comment
comment|/**< IO is for non-existing device */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_ILLEGAL_PARAMETER
value|0x08
end_define

begin_comment
comment|/**< IO is not supported (SSP) */
end_comment

begin_comment
comment|/* The following two error codes 0x09 and 0x0A are not using */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_LINK_FAILURE
value|0x09
end_define

begin_comment
comment|/**< IO failed because of link failure (SMP) */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_PROG_ERROR
value|0x0A
end_define

begin_comment
comment|/**< IO failed because of program error (SMP) */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_DIF_IN_ERROR
value|0x0B
end_define

begin_comment
comment|/**< IO failed inbound DIF error (SSP) */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_DIF_OUT_ERROR
value|0x0C
end_define

begin_comment
comment|/**< IO failed outbound DIF error (SSP) */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_ERROR_HW_TIMEOUT
value|0x0D
end_define

begin_comment
comment|/**< SMP request/response failed due to HW timeout  (SMP) */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_BREAK
value|0x0E
end_define

begin_comment
comment|/**< IO aborted due to BREAK during connection */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_PHY_NOT_READY
value|0x0F
end_define

begin_comment
comment|/**< IO aborted due to PHY NOT READY during connection*/
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_OPEN_CNX_ERROR_PROTOCOL_NOT_SUPPORTED
value|0x10
end_define

begin_comment
comment|/**< Open connection error */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_OPEN_CNX_ERROR_ZONE_VIOLATION
value|0x11
end_define

begin_comment
comment|/**< Open connection error */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_OPEN_CNX_ERROR_BREAK
value|0x12
end_define

begin_comment
comment|/**< Open connection error */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_OPEN_CNX_ERROR_IT_NEXUS_LOSS
value|0x13
end_define

begin_comment
comment|/**< Open connection error */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_OPEN_CNX_ERROR_BAD_DESTINATION
value|0x14
end_define

begin_comment
comment|/**< Open connection error */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_OPEN_CNX_ERROR_CONNECTION_RATE_NOT_SUPPORTED
value|0x15
end_define

begin_comment
comment|/**< Open connection error */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_OPEN_CNX_ERROR_STP_RESOURCES_BUSY
value|0x16
end_define

begin_comment
comment|/**< Open connection error */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_OPEN_CNX_ERROR_WRONG_DESTINATION
value|0x17
end_define

begin_comment
comment|/**< Open connection error */
end_comment

begin_comment
comment|/* This error code 0x18 is not used on SPCv */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_OPEN_CNX_ERROR_UNKNOWN_ERROR
value|0x18
end_define

begin_comment
comment|/**< Open connection error */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_NAK_RECEIVED
value|0x19
end_define

begin_comment
comment|/**< IO aborted due to transfer error with data NAK received*/
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_ACK_NAK_TIMEOUT
value|0x1A
end_define

begin_comment
comment|/**< IO aborted due to transfer error with data ACK/NAK timeout*/
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_PEER_ABORTED
value|0x1B
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_RX_FRAME
value|0x1C
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_DMA
value|0x1D
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_CREDIT_TIMEOUT
value|0x1E
end_define

begin_comment
comment|/**< IO aborted due to CREDIT TIMEOUT during data transfer*/
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_SATA_LINK_TIMEOUT
value|0x1F
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_SATA
value|0x20
end_define

begin_comment
comment|/* This error code 0x22 is not used on SPCv */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_ABORTED_DUE_TO_SRST
value|0x22
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_REJECTED_NCQ_MODE
value|0x21
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_ABORTED_NCQ_MODE
value|0x23
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFER_OPEN_RETRY_TIMEOUT
value|0x24
end_define

begin_comment
comment|/**< IO OPEN_RETRY_TIMEOUT */
end_comment

begin_comment
comment|/* This error code 0x25 is not used on SPCv */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_XFER_SMP_RESP_CONNECTION_ERROR
value|0x25
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_UNEXPECTED_PHASE
value|0x26
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_XFER_RDY_OVERRUN
value|0x27
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_XFER_RDY_NOT_EXPECTED
value|0x28
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_CMD_ISSUE_ACK_NAK_TIMEOUT
value|0x30
end_define

begin_comment
comment|/* The following error code 0x31 and 0x32 are not using (obsolete) */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_CMD_ISSUE_BREAK_BEFORE_ACK_NAK
value|0x31
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_CMD_ISSUE_PHY_DOWN_BEFORE_ACK_NAK
value|0x32
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_OFFSET_MISMATCH
value|0x34
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_XFER_ZERO_DATA_LEN
value|0x35
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFER_CMD_FRAME_ISSUED
value|0x36
end_define

begin_define
define|#
directive|define
name|OSSA_IO_ERROR_INTERNAL_SMP_RESOURCE
value|0x37
end_define

begin_define
define|#
directive|define
name|OSSA_IO_PORT_IN_RESET
value|0x38
end_define

begin_define
define|#
directive|define
name|OSSA_IO_DS_NON_OPERATIONAL
value|0x39
end_define

begin_define
define|#
directive|define
name|OSSA_IO_DS_IN_RECOVERY
value|0x3A
end_define

begin_define
define|#
directive|define
name|OSSA_IO_TM_TAG_NOT_FOUND
value|0x3B
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFER_PIO_SETUP_ERROR
value|0x3C
end_define

begin_define
define|#
directive|define
name|OSSA_IO_SSP_EXT_IU_ZERO_LEN_ERROR
value|0x3D
end_define

begin_define
define|#
directive|define
name|OSSA_IO_DS_IN_ERROR
value|0x3E
end_define

begin_define
define|#
directive|define
name|OSSA_IO_OPEN_CNX_ERROR_HW_RESOURCE_BUSY
value|0x3F
end_define

begin_define
define|#
directive|define
name|OSSA_IO_ABORT_IN_PROGRESS
value|0x40
end_define

begin_define
define|#
directive|define
name|OSSA_IO_ABORT_DELAYED
value|0x41
end_define

begin_define
define|#
directive|define
name|OSSA_IO_INVALID_LENGTH
value|0x42
end_define

begin_define
define|#
directive|define
name|OSSA_IO_OPEN_CNX_ERROR_HW_RESOURCE_BUSY_ALT
value|0x43
end_define

begin_define
define|#
directive|define
name|OSSA_IO_OPEN_CNX_ERROR_IT_NEXUS_LOSS_OPEN_RETRY_BACKOFF_THRESHOLD_REACHED
value|0x44
end_define

begin_define
define|#
directive|define
name|OSSA_IO_OPEN_CNX_ERROR_IT_NEXUS_LOSS_OPEN_TMO
value|0x45
end_define

begin_define
define|#
directive|define
name|OSSA_IO_OPEN_CNX_ERROR_IT_NEXUS_LOSS_NO_DEST
value|0x46
end_define

begin_define
define|#
directive|define
name|OSSA_IO_OPEN_CNX_ERROR_IT_NEXUS_LOSS_OPEN_COLLIDE
value|0x47
end_define

begin_define
define|#
directive|define
name|OSSA_IO_OPEN_CNX_ERROR_IT_NEXUS_LOSS_PATHWAY_BLOCKED
value|0x48
end_define

begin_define
define|#
directive|define
name|OSSA_IO_DS_INVALID
value|0x49
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFER_READ_COMPL_ERR
value|0x0050
end_define

begin_comment
comment|/* WARNING: the value is not contiguous from here */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERR_LAST_PIO_DATAIN_CRC_ERR
value|0x0052
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_DMA_ACTIVATE_TIMEOUT
value|0x0053
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFR_ERROR_INTERNAL_CRC_ERROR
value|0x0054
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_IO_RQE_BUSY_FULL
value|0x0055
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERR_EOB_DATA_OVERRUN
value|0x0056
end_define

begin_comment
comment|/* This status is only for Hitach FW */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_XFR_ERROR_INVALID_SSP_RSP_FRAME
value|0x0057
end_define

begin_define
define|#
directive|define
name|OSSA_IO_OPEN_CNX_ERROR_OPEN_PREEMPTED
value|0x0058
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_IO_RESOURCE_UNAVAILABLE
value|0x1004
end_define

begin_comment
comment|/*encrypt saSetOperator() response status */
end_comment

begin_define
define|#
directive|define
name|OSSA_MPI_ENC_ERR_CONTROLLER_NOT_IDLE
value|0x1005
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ENC_NVM_MEM_ACCESS_ERR
value|0x100B
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SA_TESTBASE_EXTRA
end_ifdef

begin_comment
comment|/* TestBase */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_HOST_BST_INVALID
value|0x1005
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  SA_TESTBASE_EXTRA */
end_comment

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_OFFLOAD_RESOURCE_UNAVAILABLE
value|0x1012
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_OFFLOAD_DIF_OR_ENC_NOT_ENABLED
value|0x1013
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_ATAPI_DEVICE_BUSY
value|0x1024
end_define

begin_comment
comment|/* Specifies the status of the PHY_START command */
end_comment

begin_define
define|#
directive|define
name|OSSA_MPI_IO_SUCCESS
value|0x00000000
end_define

begin_comment
comment|/* PhyStart operation completed successfully */
end_comment

begin_comment
comment|/* Specifies the status of the PHY_STOP command */
end_comment

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_DEVICES_ATTACHED
value|0x00001046
end_define

begin_comment
comment|/* All the devices in a port need to be deregistered if the PHY_STOP is for the last phy. */
end_comment

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_INVALID_PHY_ID
value|0x00001061
end_define

begin_comment
comment|/* identifier specified in the PHY_START command is invalid i.e out of supported range for this product. */
end_comment

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_PHY_ALREADY_STARTED
value|0x00001063
end_define

begin_comment
comment|/* An attempt to start a phy which is already started.  */
end_comment

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_PHY_NOT_STARTED
value|0x00001064
end_define

begin_comment
comment|/* An attempt to stop a phy which is not started */
end_comment

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_PHY_SUBOP_NOT_SUPPORTED
value|0x00001065
end_define

begin_comment
comment|/* An attempt to use a sub operation that is not supported */
end_comment

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_INVALID_ANALOG_TBL_IDX
value|0x00001067
end_define

begin_comment
comment|/* The Analog Setup Table Index used in the PHY_START command in invalid. */
end_comment

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_PHY_PROFILE_PAGE_NOT_SUPPORTED
value|0x00001068
end_define

begin_comment
comment|/* Unsupported profile page code specified in the GET_PHY_PROFILE Command */
end_comment

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_PHY_PROFILE_PAGE_NOT_FOUND
value|0x00001069
end_define

begin_comment
comment|/* Unsupported profile page code specified in the GET_PHY_PROFILE Command */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_XFR_ERROR_DEK_KEY_CACHE_MISS
value|0x2040
end_define

begin_comment
comment|/*    An encryption IO request failed due to DEK Key Tag mismatch.    The key tag supplied in the encryption IOMB does not match with the Key Tag in the referenced DEK Entry. */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_XFR_ERROR_DEK_KEY_TAG_MISMATCH
value|0x2041
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFR_ERROR_CIPHER_MODE_INVALID
value|0x2042
end_define

begin_comment
comment|/*     An encryption I/O request failed     because the initial value (IV) in the unwrapped DEK blob didn't match the IV used to unwrap it. */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_XFR_ERROR_DEK_IV_MISMATCH
value|0x2043
end_define

begin_comment
comment|/* An encryption I/O request failed due to an internal RAM ECC or interface error while unwrapping the DEK. */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_XFR_ERROR_DEK_RAM_INTERFACE_ERROR
value|0x2044
end_define

begin_comment
comment|/* An encryption I/O request failed due to an internal RAM ECC or interface error while unwrapping the DEK. */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_XFR_ERROR_INTERNAL_RAM
value|0x2045
end_define

begin_comment
comment|/*     An encryption I/O request failed     because the DEK index specified in the I/O was outside the bounds of thetotal number of entries in the host DEK table. */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_XFR_ERROR_DEK_INDEX_OUT_OF_BOUNDS
value|0x2046
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFR_ERROR_DEK_ILLEGAL_TABLE
value|0x2047
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ENC_ERR_UNSUPPORTED_OPTION
value|0x2080
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ENC_ERR_ID_TRANSFER_FAILURE
value|0x2081
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ENC_OPERATOR_AUTH_FAILURE
value|0x2090
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ENC_OPERATOR_OPERATOR_ALREADY_LOGGED_IN
value|0x2091
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ENC_OPERATOR_ILLEGAL_PARAMETER
value|0x2092
end_define

begin_comment
comment|/* define DIF IO response error status code */
end_comment

begin_define
define|#
directive|define
name|OSSA_IO_XFR_ERROR_DIF_MISMATCH
value|0x3000
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFR_ERROR_DIF_APPLICATION_TAG_MISMATCH
value|0x3001
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFR_ERROR_DIF_REFERENCE_TAG_MISMATCH
value|0x3002
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFR_ERROR_DIF_CRC_MISMATCH
value|0x3003
end_define

begin_define
define|#
directive|define
name|OSSA_IO_XFER_ERROR_DIF_INTERNAL_ERROR
value|0x3004
end_define

begin_define
define|#
directive|define
name|OSSA_MPI_ERR_DIF_IS_NOT_ENABLED
end_define

begin_comment
comment|/* Indicates that saPCIeDiagExecute() is                                                                           *  called with DIF but DIF is not enabled.                                                                           */
end_comment

begin_comment
comment|/* define operator management response status and error qualifier code */
end_comment

begin_define
define|#
directive|define
name|OPR_MGMT_OP_NOT_SUPPORTED
value|0x2060
end_define

begin_define
define|#
directive|define
name|OPR_MGMT_MPI_ENC_ERR_OPR_PARAM_ILLEGAL
value|0x2061
end_define

begin_define
define|#
directive|define
name|OPR_MGMT_MPI_ENC_ERR_OPR_ID_NOT_FOUND
value|0x2062
end_define

begin_define
define|#
directive|define
name|OPR_MGMT_MPI_ENC_ERR_OPR_ROLE_NOT_MATCH
value|0x2063
end_define

begin_define
define|#
directive|define
name|OPR_MGMT_MPI_ENC_ERR_OPR_MAX_NUM_EXCEEDED
value|0x2064
end_define

begin_define
define|#
directive|define
name|OPR_MGMT_MPI_ENC_ERR_KEK_UNWRAP_FAIL
value|0x2022
end_define

begin_define
define|#
directive|define
name|OPR_MGMT_MPI_ENC_ERR_NVRAM_OPERATION_FAILURE
value|0x2023
end_define

begin_comment
comment|/* When Status is 0x2061 */
end_comment

begin_define
define|#
directive|define
name|OPR_MGMT_ERR_QLFR_ILLEGAL_AUTHENTICATIONKEK_INDEX
value|0x1
end_define

begin_define
define|#
directive|define
name|OPR_MGMT_ERR_QLFR_ILLEGAL_OPERATOR
value|0x2
end_define

begin_define
define|#
directive|define
name|OPR_MGMT_ERR_QLFR_ILLEGAL_KEK_FORMAT
value|0x3
end_define

begin_define
define|#
directive|define
name|OPR_MGMT_ERR_QLFR_WRONG_ROLE
value|0x4
end_define

begin_comment
comment|/* When status is 0x2090 */
end_comment

begin_comment
comment|/* invalid certificate: the certificate can not be unwrapped successfully by existing operators's KEKs */
end_comment

begin_define
define|#
directive|define
name|OPR_SET_ERR_QLFR_INVALID_CERT
value|0x01
end_define

begin_comment
comment|/* role mismatch: the role from the certificate doesn't match the one inside the controller. */
end_comment

begin_define
define|#
directive|define
name|OPR_SET_ERR_QLFR_ROLE_MISMATCH
value|0x02
end_define

begin_comment
comment|/* ID mismatch: the ID string from the certificate doesn't match the one inside the controller. */
end_comment

begin_define
define|#
directive|define
name|OPR_SET_ERR_QLFR_ID_MISMATCH
value|0x03
end_define

begin_comment
comment|/* When status is 0x2092 */
end_comment

begin_comment
comment|/* invalid OPRIDX */
end_comment

begin_define
define|#
directive|define
name|OPR_SET_ERR_QLFR_INVALID_OPRIDX
value|0x04
end_define

begin_comment
comment|/* invalid access type */
end_comment

begin_define
define|#
directive|define
name|OPR_SET_ERR_QLFR_INVALID_ACCESS_TYPE
value|0x05
end_define

begin_comment
comment|/* WARNING: This error code must always be the last number.  *          If you add error code, modify this code also  *          It is used as an index  */
end_comment

begin_comment
comment|/* SAS Reconfiguration error */
end_comment

begin_define
define|#
directive|define
name|OSSA_CONTROLLER_NOT_IDLE
value|0x1
end_define

begin_define
define|#
directive|define
name|OSSA_INVALID_CONFIG_PARAM
value|0x2
end_define

begin_comment
comment|/************************************************************************************  *                                                                                  *  *               Constants defined for OS Layer ends                                *  *                                                                                  *  ************************************************************************************/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__SA_ERR_H__ */
end_comment

end_unit

