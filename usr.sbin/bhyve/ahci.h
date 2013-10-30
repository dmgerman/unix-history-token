begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 - 2008 SÃ¸ren Schmidt<sos@FreeBSD.org>  * Copyright (c) 2009-2012 Alexander Motin<mav@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AHCI_H_
end_ifndef

begin_define
define|#
directive|define
name|_AHCI_H_
end_define

begin_comment
comment|/* ATA register defines */
end_comment

begin_define
define|#
directive|define
name|ATA_DATA
value|0
end_define

begin_comment
comment|/* (RW) data */
end_comment

begin_define
define|#
directive|define
name|ATA_FEATURE
value|1
end_define

begin_comment
comment|/* (W) feature */
end_comment

begin_define
define|#
directive|define
name|ATA_F_DMA
value|0x01
end_define

begin_comment
comment|/* enable DMA */
end_comment

begin_define
define|#
directive|define
name|ATA_F_OVL
value|0x02
end_define

begin_comment
comment|/* enable overlap */
end_comment

begin_define
define|#
directive|define
name|ATA_COUNT
value|2
end_define

begin_comment
comment|/* (W) sector count */
end_comment

begin_define
define|#
directive|define
name|ATA_SECTOR
value|3
end_define

begin_comment
comment|/* (RW) sector # */
end_comment

begin_define
define|#
directive|define
name|ATA_CYL_LSB
value|4
end_define

begin_comment
comment|/* (RW) cylinder# LSB */
end_comment

begin_define
define|#
directive|define
name|ATA_CYL_MSB
value|5
end_define

begin_comment
comment|/* (RW) cylinder# MSB */
end_comment

begin_define
define|#
directive|define
name|ATA_DRIVE
value|6
end_define

begin_comment
comment|/* (W) Sector/Drive/Head */
end_comment

begin_define
define|#
directive|define
name|ATA_D_LBA
value|0x40
end_define

begin_comment
comment|/* use LBA addressing */
end_comment

begin_define
define|#
directive|define
name|ATA_D_IBM
value|0xa0
end_define

begin_comment
comment|/* 512 byte sectors, ECC */
end_comment

begin_define
define|#
directive|define
name|ATA_COMMAND
value|7
end_define

begin_comment
comment|/* (W) command */
end_comment

begin_define
define|#
directive|define
name|ATA_ERROR
value|8
end_define

begin_comment
comment|/* (R) error */
end_comment

begin_define
define|#
directive|define
name|ATA_E_ILI
value|0x01
end_define

begin_comment
comment|/* illegal length */
end_comment

begin_define
define|#
directive|define
name|ATA_E_NM
value|0x02
end_define

begin_comment
comment|/* no media */
end_comment

begin_define
define|#
directive|define
name|ATA_E_ABORT
value|0x04
end_define

begin_comment
comment|/* command aborted */
end_comment

begin_define
define|#
directive|define
name|ATA_E_MCR
value|0x08
end_define

begin_comment
comment|/* media change request */
end_comment

begin_define
define|#
directive|define
name|ATA_E_IDNF
value|0x10
end_define

begin_comment
comment|/* ID not found */
end_comment

begin_define
define|#
directive|define
name|ATA_E_MC
value|0x20
end_define

begin_comment
comment|/* media changed */
end_comment

begin_define
define|#
directive|define
name|ATA_E_UNC
value|0x40
end_define

begin_comment
comment|/* uncorrectable data */
end_comment

begin_define
define|#
directive|define
name|ATA_E_ICRC
value|0x80
end_define

begin_comment
comment|/* UDMA crc error */
end_comment

begin_define
define|#
directive|define
name|ATA_E_ATAPI_SENSE_MASK
value|0xf0
end_define

begin_comment
comment|/* ATAPI sense key mask */
end_comment

begin_define
define|#
directive|define
name|ATA_IREASON
value|9
end_define

begin_comment
comment|/* (R) interrupt reason */
end_comment

begin_define
define|#
directive|define
name|ATA_I_CMD
value|0x01
end_define

begin_comment
comment|/* cmd (1) | data (0) */
end_comment

begin_define
define|#
directive|define
name|ATA_I_IN
value|0x02
end_define

begin_comment
comment|/* read (1) | write (0) */
end_comment

begin_define
define|#
directive|define
name|ATA_I_RELEASE
value|0x04
end_define

begin_comment
comment|/* released bus (1) */
end_comment

begin_define
define|#
directive|define
name|ATA_I_TAGMASK
value|0xf8
end_define

begin_comment
comment|/* tag mask */
end_comment

begin_define
define|#
directive|define
name|ATA_STATUS
value|10
end_define

begin_comment
comment|/* (R) status */
end_comment

begin_define
define|#
directive|define
name|ATA_ALTSTAT
value|11
end_define

begin_comment
comment|/* (R) alternate status */
end_comment

begin_define
define|#
directive|define
name|ATA_S_ERROR
value|0x01
end_define

begin_comment
comment|/* error */
end_comment

begin_define
define|#
directive|define
name|ATA_S_INDEX
value|0x02
end_define

begin_comment
comment|/* index */
end_comment

begin_define
define|#
directive|define
name|ATA_S_CORR
value|0x04
end_define

begin_comment
comment|/* data corrected */
end_comment

begin_define
define|#
directive|define
name|ATA_S_DRQ
value|0x08
end_define

begin_comment
comment|/* data request */
end_comment

begin_define
define|#
directive|define
name|ATA_S_DSC
value|0x10
end_define

begin_comment
comment|/* drive seek completed */
end_comment

begin_define
define|#
directive|define
name|ATA_S_SERVICE
value|0x10
end_define

begin_comment
comment|/* drive needs service */
end_comment

begin_define
define|#
directive|define
name|ATA_S_DWF
value|0x20
end_define

begin_comment
comment|/* drive write fault */
end_comment

begin_define
define|#
directive|define
name|ATA_S_DMA
value|0x20
end_define

begin_comment
comment|/* DMA ready */
end_comment

begin_define
define|#
directive|define
name|ATA_S_READY
value|0x40
end_define

begin_comment
comment|/* drive ready */
end_comment

begin_define
define|#
directive|define
name|ATA_S_BUSY
value|0x80
end_define

begin_comment
comment|/* busy */
end_comment

begin_define
define|#
directive|define
name|ATA_CONTROL
value|12
end_define

begin_comment
comment|/* (W) control */
end_comment

begin_define
define|#
directive|define
name|ATA_A_IDS
value|0x02
end_define

begin_comment
comment|/* disable interrupts */
end_comment

begin_define
define|#
directive|define
name|ATA_A_RESET
value|0x04
end_define

begin_comment
comment|/* RESET controller */
end_comment

begin_define
define|#
directive|define
name|ATA_A_4BIT
value|0x08
end_define

begin_comment
comment|/* 4 head bits */
end_comment

begin_define
define|#
directive|define
name|ATA_A_HOB
value|0x80
end_define

begin_comment
comment|/* High Order Byte enable */
end_comment

begin_comment
comment|/* SATA register defines */
end_comment

begin_define
define|#
directive|define
name|ATA_SSTATUS
value|13
end_define

begin_define
define|#
directive|define
name|ATA_SS_DET_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|ATA_SS_DET_NO_DEVICE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ATA_SS_DET_DEV_PRESENT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ATA_SS_DET_PHY_ONLINE
value|0x00000003
end_define

begin_define
define|#
directive|define
name|ATA_SS_DET_PHY_OFFLINE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ATA_SS_SPD_MASK
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|ATA_SS_SPD_NO_SPEED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ATA_SS_SPD_GEN1
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ATA_SS_SPD_GEN2
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ATA_SS_SPD_GEN3
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ATA_SS_IPM_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|ATA_SS_IPM_NO_DEVICE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ATA_SS_IPM_ACTIVE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|ATA_SS_IPM_PARTIAL
value|0x00000200
end_define

begin_define
define|#
directive|define
name|ATA_SS_IPM_SLUMBER
value|0x00000600
end_define

begin_define
define|#
directive|define
name|ATA_SERROR
value|14
end_define

begin_define
define|#
directive|define
name|ATA_SE_DATA_CORRECTED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ATA_SE_COMM_CORRECTED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ATA_SE_DATA_ERR
value|0x00000100
end_define

begin_define
define|#
directive|define
name|ATA_SE_COMM_ERR
value|0x00000200
end_define

begin_define
define|#
directive|define
name|ATA_SE_PROT_ERR
value|0x00000400
end_define

begin_define
define|#
directive|define
name|ATA_SE_HOST_ERR
value|0x00000800
end_define

begin_define
define|#
directive|define
name|ATA_SE_PHY_CHANGED
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ATA_SE_PHY_IERROR
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ATA_SE_COMM_WAKE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|ATA_SE_DECODE_ERR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|ATA_SE_PARITY_ERR
value|0x00100000
end_define

begin_define
define|#
directive|define
name|ATA_SE_CRC_ERR
value|0x00200000
end_define

begin_define
define|#
directive|define
name|ATA_SE_HANDSHAKE_ERR
value|0x00400000
end_define

begin_define
define|#
directive|define
name|ATA_SE_LINKSEQ_ERR
value|0x00800000
end_define

begin_define
define|#
directive|define
name|ATA_SE_TRANSPORT_ERR
value|0x01000000
end_define

begin_define
define|#
directive|define
name|ATA_SE_UNKNOWN_FIS
value|0x02000000
end_define

begin_define
define|#
directive|define
name|ATA_SE_EXCHANGED
value|0x04000000
end_define

begin_define
define|#
directive|define
name|ATA_SCONTROL
value|15
end_define

begin_define
define|#
directive|define
name|ATA_SC_DET_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|ATA_SC_DET_IDLE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ATA_SC_DET_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ATA_SC_DET_DISABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ATA_SC_SPD_MASK
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|ATA_SC_SPD_NO_SPEED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ATA_SC_SPD_SPEED_GEN1
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ATA_SC_SPD_SPEED_GEN2
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ATA_SC_SPD_SPEED_GEN3
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ATA_SC_IPM_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|ATA_SC_IPM_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ATA_SC_IPM_DIS_PARTIAL
value|0x00000100
end_define

begin_define
define|#
directive|define
name|ATA_SC_IPM_DIS_SLUMBER
value|0x00000200
end_define

begin_define
define|#
directive|define
name|ATA_SACTIVE
value|16
end_define

begin_define
define|#
directive|define
name|AHCI_MAX_PORTS
value|32
end_define

begin_define
define|#
directive|define
name|AHCI_MAX_SLOTS
value|32
end_define

begin_comment
comment|/* SATA AHCI v1.0 register defines */
end_comment

begin_define
define|#
directive|define
name|AHCI_CAP
value|0x00
end_define

begin_define
define|#
directive|define
name|AHCI_CAP_NPMASK
value|0x0000001f
end_define

begin_define
define|#
directive|define
name|AHCI_CAP_SXS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AHCI_CAP_EMS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AHCI_CAP_CCCS
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AHCI_CAP_NCS
value|0x00001F00
end_define

begin_define
define|#
directive|define
name|AHCI_CAP_NCS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|AHCI_CAP_PSC
value|0x00002000
end_define

begin_define
define|#
directive|define
name|AHCI_CAP_SSC
value|0x00004000
end_define

begin_define
define|#
directive|define
name|AHCI_CAP_PMD
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AHCI_CAP_FBSS
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AHCI_CAP_SPM
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AHCI_CAP_SAM
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AHCI_CAP_ISS
value|0x00F00000
end_define

begin_define
define|#
directive|define
name|AHCI_CAP_ISS_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|AHCI_CAP_SCLO
value|0x01000000
end_define

begin_define
define|#
directive|define
name|AHCI_CAP_SAL
value|0x02000000
end_define

begin_define
define|#
directive|define
name|AHCI_CAP_SALP
value|0x04000000
end_define

begin_define
define|#
directive|define
name|AHCI_CAP_SSS
value|0x08000000
end_define

begin_define
define|#
directive|define
name|AHCI_CAP_SMPS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|AHCI_CAP_SSNTF
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AHCI_CAP_SNCQ
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AHCI_CAP_64BIT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AHCI_GHC
value|0x04
end_define

begin_define
define|#
directive|define
name|AHCI_GHC_AE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AHCI_GHC_MRSM
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AHCI_GHC_IE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AHCI_GHC_HR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AHCI_IS
value|0x08
end_define

begin_define
define|#
directive|define
name|AHCI_PI
value|0x0c
end_define

begin_define
define|#
directive|define
name|AHCI_VS
value|0x10
end_define

begin_define
define|#
directive|define
name|AHCI_CCCC
value|0x14
end_define

begin_define
define|#
directive|define
name|AHCI_CCCC_TV_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|AHCI_CCCC_TV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AHCI_CCCC_CC_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|AHCI_CCCC_CC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|AHCI_CCCC_INT_MASK
value|0x000000f8
end_define

begin_define
define|#
directive|define
name|AHCI_CCCC_INT_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|AHCI_CCCC_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AHCI_CCCP
value|0x18
end_define

begin_define
define|#
directive|define
name|AHCI_EM_LOC
value|0x1C
end_define

begin_define
define|#
directive|define
name|AHCI_EM_CTL
value|0x20
end_define

begin_define
define|#
directive|define
name|AHCI_EM_MR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AHCI_EM_TM
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AHCI_EM_RST
value|0x00000200
end_define

begin_define
define|#
directive|define
name|AHCI_EM_LED
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AHCI_EM_SAFTE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AHCI_EM_SES2
value|0x00040000
end_define

begin_define
define|#
directive|define
name|AHCI_EM_SGPIO
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AHCI_EM_SMB
value|0x01000000
end_define

begin_define
define|#
directive|define
name|AHCI_EM_XMT
value|0x02000000
end_define

begin_define
define|#
directive|define
name|AHCI_EM_ALHD
value|0x04000000
end_define

begin_define
define|#
directive|define
name|AHCI_EM_PM
value|0x08000000
end_define

begin_define
define|#
directive|define
name|AHCI_CAP2
value|0x24
end_define

begin_define
define|#
directive|define
name|AHCI_CAP2_BOH
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AHCI_CAP2_NVMP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AHCI_CAP2_APST
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AHCI_OFFSET
value|0x100
end_define

begin_define
define|#
directive|define
name|AHCI_STEP
value|0x80
end_define

begin_define
define|#
directive|define
name|AHCI_P_CLB
value|0x00
end_define

begin_define
define|#
directive|define
name|AHCI_P_CLBU
value|0x04
end_define

begin_define
define|#
directive|define
name|AHCI_P_FB
value|0x08
end_define

begin_define
define|#
directive|define
name|AHCI_P_FBU
value|0x0c
end_define

begin_define
define|#
directive|define
name|AHCI_P_IS
value|0x10
end_define

begin_define
define|#
directive|define
name|AHCI_P_IE
value|0x14
end_define

begin_define
define|#
directive|define
name|AHCI_P_IX_DHR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AHCI_P_IX_PS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AHCI_P_IX_DS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AHCI_P_IX_SDB
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AHCI_P_IX_UF
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AHCI_P_IX_DP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AHCI_P_IX_PC
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AHCI_P_IX_MP
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AHCI_P_IX_PRC
value|0x00400000
end_define

begin_define
define|#
directive|define
name|AHCI_P_IX_IPM
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AHCI_P_IX_OF
value|0x01000000
end_define

begin_define
define|#
directive|define
name|AHCI_P_IX_INF
value|0x04000000
end_define

begin_define
define|#
directive|define
name|AHCI_P_IX_IF
value|0x08000000
end_define

begin_define
define|#
directive|define
name|AHCI_P_IX_HBD
value|0x10000000
end_define

begin_define
define|#
directive|define
name|AHCI_P_IX_HBF
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AHCI_P_IX_TFE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AHCI_P_IX_CPD
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD
value|0x18
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_ST
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_SUD
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_POD
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_CLO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_FRE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_CCS_MASK
value|0x00001f00
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_CCS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_ISS
value|0x00002000
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_FR
value|0x00004000
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_CR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_CPS
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_PMA
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_HPCP
value|0x00040000
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_MPSP
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_CPD
value|0x00100000
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_ESP
value|0x00200000
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_FBSCP
value|0x00400000
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_APSTE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_ATAPI
value|0x01000000
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_DLAE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_ALPE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_ASP
value|0x08000000
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_ICC_MASK
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_NOOP
value|0x00000000
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_ACTIVE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_PARTIAL
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AHCI_P_CMD_SLUMBER
value|0x60000000
end_define

begin_define
define|#
directive|define
name|AHCI_P_TFD
value|0x20
end_define

begin_define
define|#
directive|define
name|AHCI_P_SIG
value|0x24
end_define

begin_define
define|#
directive|define
name|AHCI_P_SSTS
value|0x28
end_define

begin_define
define|#
directive|define
name|AHCI_P_SCTL
value|0x2c
end_define

begin_define
define|#
directive|define
name|AHCI_P_SERR
value|0x30
end_define

begin_define
define|#
directive|define
name|AHCI_P_SACT
value|0x34
end_define

begin_define
define|#
directive|define
name|AHCI_P_CI
value|0x38
end_define

begin_define
define|#
directive|define
name|AHCI_P_SNTF
value|0x3C
end_define

begin_define
define|#
directive|define
name|AHCI_P_FBS
value|0x40
end_define

begin_define
define|#
directive|define
name|AHCI_P_FBS_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AHCI_P_FBS_DEC
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AHCI_P_FBS_SDE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AHCI_P_FBS_DEV
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|AHCI_P_FBS_DEV_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|AHCI_P_FBS_ADO
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|AHCI_P_FBS_ADO_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|AHCI_P_FBS_DWE
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|AHCI_P_FBS_DWE_SHIFT
value|16
end_define

begin_comment
comment|/* Just to be sure, if building as module. */
end_comment

begin_if
if|#
directive|if
name|MAXPHYS
operator|<
literal|512
operator|*
literal|1024
end_if

begin_undef
undef|#
directive|undef
name|MAXPHYS
end_undef

begin_define
define|#
directive|define
name|MAXPHYS
value|512 * 1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Pessimistic prognosis on number of required S/G entries */
end_comment

begin_define
define|#
directive|define
name|AHCI_SG_ENTRIES
value|(roundup(btoc(MAXPHYS) + 1, 8))
end_define

begin_comment
comment|/* Command list. 32 commands. First, 1Kbyte aligned. */
end_comment

begin_define
define|#
directive|define
name|AHCI_CL_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|AHCI_CL_SIZE
value|32
end_define

begin_comment
comment|/* Command tables. Up to 32 commands, Each, 128byte aligned. */
end_comment

begin_define
define|#
directive|define
name|AHCI_CT_OFFSET
value|(AHCI_CL_OFFSET + AHCI_CL_SIZE * AHCI_MAX_SLOTS)
end_define

begin_define
define|#
directive|define
name|AHCI_CT_SIZE
value|(128 + AHCI_SG_ENTRIES * 16)
end_define

begin_comment
comment|/* Total main work area. */
end_comment

begin_define
define|#
directive|define
name|AHCI_WORK_SIZE
value|(AHCI_CT_OFFSET + AHCI_CT_SIZE * ch->numslots)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AHCI_H_ */
end_comment

end_unit

