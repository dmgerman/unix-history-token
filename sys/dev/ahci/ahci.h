begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 - 2008 SÃ¸ren Schmidt<sos@FreeBSD.org>  * Copyright (c) 2009-2012 Alexander Motin<mav@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

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
value|0x00000030
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
name|ATA_SS_IPM_DEVSLEEP
value|0x00000800
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
value|0x00000030
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
name|ATA_SC_IPM_DIS_DEVSLEEP
value|0x00000400
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

begin_define
define|#
directive|define
name|AHCI_MAX_IRQS
value|16
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
name|AHCI_CAP2_SDS
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AHCI_CAP2_SADM
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AHCI_CAP2_DESO
value|0x00000020
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
name|AHCI_P_CMD_DEVSLEEP
value|0x80000000
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

begin_define
define|#
directive|define
name|AHCI_P_DEVSLP
value|0x44
end_define

begin_define
define|#
directive|define
name|AHCI_P_DEVSLP_ADSE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AHCI_P_DEVSLP_DSP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AHCI_P_DEVSLP_DETO
value|0x000003fc
end_define

begin_define
define|#
directive|define
name|AHCI_P_DEVSLP_DETO_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|AHCI_P_DEVSLP_MDAT
value|0x00007c00
end_define

begin_define
define|#
directive|define
name|AHCI_P_DEVSLP_MDAT_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|AHCI_P_DEVSLP_DITO
value|0x01ff8000
end_define

begin_define
define|#
directive|define
name|AHCI_P_DEVSLP_DITO_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|AHCI_P_DEVSLP_DM
value|0x0e000000
end_define

begin_define
define|#
directive|define
name|AHCI_P_DEVSLP_DM_SHIFT
value|25
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

begin_struct
struct|struct
name|ahci_dma_prd
block|{
name|u_int64_t
name|dba
decl_stmt|;
name|u_int32_t
name|reserved
decl_stmt|;
name|u_int32_t
name|dbc
decl_stmt|;
comment|/* 0 based */
define|#
directive|define
name|AHCI_PRD_MASK
value|0x003fffff
comment|/* max 4MB */
define|#
directive|define
name|AHCI_PRD_MAX
value|(AHCI_PRD_MASK + 1)
define|#
directive|define
name|AHCI_PRD_IPC
value|(1U<< 31)
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ahci_cmd_tab
block|{
name|u_int8_t
name|cfis
index|[
literal|64
index|]
decl_stmt|;
name|u_int8_t
name|acmd
index|[
literal|32
index|]
decl_stmt|;
name|u_int8_t
name|reserved
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|ahci_dma_prd
name|prd_tab
index|[
name|AHCI_SG_ENTRIES
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ahci_cmd_list
block|{
name|u_int16_t
name|cmd_flags
decl_stmt|;
define|#
directive|define
name|AHCI_CMD_ATAPI
value|0x0020
define|#
directive|define
name|AHCI_CMD_WRITE
value|0x0040
define|#
directive|define
name|AHCI_CMD_PREFETCH
value|0x0080
define|#
directive|define
name|AHCI_CMD_RESET
value|0x0100
define|#
directive|define
name|AHCI_CMD_BIST
value|0x0200
define|#
directive|define
name|AHCI_CMD_CLR_BUSY
value|0x0400
name|u_int16_t
name|prd_length
decl_stmt|;
comment|/* PRD entries */
name|u_int32_t
name|bytecount
decl_stmt|;
name|u_int64_t
name|cmd_table_phys
decl_stmt|;
comment|/* 128byte aligned */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* misc defines */
end_comment

begin_define
define|#
directive|define
name|ATA_IRQ_RID
value|0
end_define

begin_define
define|#
directive|define
name|ATA_INTR_FLAGS
value|(INTR_MPSAFE|INTR_TYPE_BIO|INTR_ENTROPY)
end_define

begin_struct
struct|struct
name|ata_dmaslot
block|{
name|bus_dmamap_t
name|data_map
decl_stmt|;
comment|/* data DMA map */
name|int
name|nsegs
decl_stmt|;
comment|/* Number of segs loaded */
block|}
struct|;
end_struct

begin_comment
comment|/* structure holding DMA related information */
end_comment

begin_struct
struct|struct
name|ata_dma
block|{
name|bus_dma_tag_t
name|work_tag
decl_stmt|;
comment|/* workspace DMA tag */
name|bus_dmamap_t
name|work_map
decl_stmt|;
comment|/* workspace DMA map */
name|uint8_t
modifier|*
name|work
decl_stmt|;
comment|/* workspace */
name|bus_addr_t
name|work_bus
decl_stmt|;
comment|/* bus address of work */
name|bus_dma_tag_t
name|rfis_tag
decl_stmt|;
comment|/* RFIS list DMA tag */
name|bus_dmamap_t
name|rfis_map
decl_stmt|;
comment|/* RFIS list DMA map */
name|uint8_t
modifier|*
name|rfis
decl_stmt|;
comment|/* FIS receive area */
name|bus_addr_t
name|rfis_bus
decl_stmt|;
comment|/* bus address of rfis */
name|bus_dma_tag_t
name|data_tag
decl_stmt|;
comment|/* data DMA tag */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|ahci_slot_states
block|{
name|AHCI_SLOT_EMPTY
block|,
name|AHCI_SLOT_LOADING
block|,
name|AHCI_SLOT_RUNNING
block|,
name|AHCI_SLOT_EXECUTING
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ahci_slot
block|{
name|struct
name|ahci_channel
modifier|*
name|ch
decl_stmt|;
comment|/* Channel */
name|u_int8_t
name|slot
decl_stmt|;
comment|/* Number of this slot */
name|enum
name|ahci_slot_states
name|state
decl_stmt|;
comment|/* Slot state */
name|union
name|ccb
modifier|*
name|ccb
decl_stmt|;
comment|/* CCB occupying slot */
name|struct
name|ata_dmaslot
name|dma
decl_stmt|;
comment|/* DMA data of this slot */
name|struct
name|callout
name|timeout
decl_stmt|;
comment|/* Execution timeout */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ahci_device
block|{
name|int
name|revision
decl_stmt|;
name|int
name|mode
decl_stmt|;
name|u_int
name|bytecount
decl_stmt|;
name|u_int
name|atapi
decl_stmt|;
name|u_int
name|tags
decl_stmt|;
name|u_int
name|caps
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ahci_led
block|{
name|device_t
name|dev
decl_stmt|;
comment|/* Device handle */
name|struct
name|cdev
modifier|*
name|led
decl_stmt|;
name|uint8_t
name|num
decl_stmt|;
comment|/* Number of this led */
name|uint8_t
name|state
decl_stmt|;
comment|/* State of this led */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AHCI_NUM_LEDS
value|3
end_define

begin_comment
comment|/* structure describing an ATA channel */
end_comment

begin_struct
struct|struct
name|ahci_channel
block|{
name|device_t
name|dev
decl_stmt|;
comment|/* Device handle */
name|int
name|unit
decl_stmt|;
comment|/* Physical channel */
name|struct
name|resource
modifier|*
name|r_mem
decl_stmt|;
comment|/* Memory of this channel */
name|struct
name|resource
modifier|*
name|r_irq
decl_stmt|;
comment|/* Interrupt of this channel */
name|void
modifier|*
name|ih
decl_stmt|;
comment|/* Interrupt handle */
name|struct
name|ata_dma
name|dma
decl_stmt|;
comment|/* DMA data */
name|struct
name|cam_sim
modifier|*
name|sim
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
name|uint32_t
name|caps
decl_stmt|;
comment|/* Controller capabilities */
name|uint32_t
name|caps2
decl_stmt|;
comment|/* Controller capabilities */
name|uint32_t
name|chcaps
decl_stmt|;
comment|/* Channel capabilities */
name|uint32_t
name|chscaps
decl_stmt|;
comment|/* Channel sleep capabilities */
name|uint16_t
name|vendorid
decl_stmt|;
comment|/* Vendor ID from the bus */
name|uint16_t
name|deviceid
decl_stmt|;
comment|/* Device ID from the bus */
name|uint16_t
name|subvendorid
decl_stmt|;
comment|/* Subvendor ID from the bus */
name|uint16_t
name|subdeviceid
decl_stmt|;
comment|/* Subdevice ID from the bus */
name|int
name|quirks
decl_stmt|;
name|int
name|numslots
decl_stmt|;
comment|/* Number of present slots */
name|int
name|pm_level
decl_stmt|;
comment|/* power management level */
name|int
name|devices
decl_stmt|;
comment|/* What is present */
name|int
name|pm_present
decl_stmt|;
comment|/* PM presence reported */
name|int
name|fbs_enabled
decl_stmt|;
comment|/* FIS-based switching enabled */
name|void
function_decl|(
modifier|*
name|start
function_decl|)
parameter_list|(
name|struct
name|ahci_channel
modifier|*
parameter_list|)
function_decl|;
name|union
name|ccb
modifier|*
name|hold
index|[
name|AHCI_MAX_SLOTS
index|]
decl_stmt|;
name|struct
name|ahci_slot
name|slot
index|[
name|AHCI_MAX_SLOTS
index|]
decl_stmt|;
name|uint32_t
name|oslots
decl_stmt|;
comment|/* Occupied slots */
name|uint32_t
name|rslots
decl_stmt|;
comment|/* Running slots */
name|uint32_t
name|aslots
decl_stmt|;
comment|/* Slots with atomic commands  */
name|uint32_t
name|eslots
decl_stmt|;
comment|/* Slots in error */
name|uint32_t
name|toslots
decl_stmt|;
comment|/* Slots in timeout */
name|int
name|lastslot
decl_stmt|;
comment|/* Last used slot */
name|int
name|taggedtarget
decl_stmt|;
comment|/* Last tagged target */
name|int
name|numrslots
decl_stmt|;
comment|/* Number of running slots */
name|int
name|numrslotspd
index|[
literal|16
index|]
decl_stmt|;
comment|/* Number of running slots per dev */
name|int
name|numtslots
decl_stmt|;
comment|/* Number of tagged slots */
name|int
name|numtslotspd
index|[
literal|16
index|]
decl_stmt|;
comment|/* Number of tagged slots per dev */
name|int
name|numhslots
decl_stmt|;
comment|/* Number of held slots */
name|int
name|recoverycmd
decl_stmt|;
comment|/* Our READ LOG active */
name|int
name|fatalerr
decl_stmt|;
comment|/* Fatal error happened */
name|int
name|resetting
decl_stmt|;
comment|/* Hard-reset in progress. */
name|int
name|resetpolldiv
decl_stmt|;
comment|/* Hard-reset poll divider. */
name|int
name|listening
decl_stmt|;
comment|/* SUD bit is cleared. */
name|int
name|wrongccs
decl_stmt|;
comment|/* CCS field in CMD was wrong */
name|union
name|ccb
modifier|*
name|frozen
decl_stmt|;
comment|/* Frozen command */
name|struct
name|callout
name|pm_timer
decl_stmt|;
comment|/* Power management events */
name|struct
name|callout
name|reset_timer
decl_stmt|;
comment|/* Hard-reset timeout */
name|struct
name|ahci_device
name|user
index|[
literal|16
index|]
decl_stmt|;
comment|/* User-specified settings */
name|struct
name|ahci_device
name|curr
index|[
literal|16
index|]
decl_stmt|;
comment|/* Current settings */
name|struct
name|mtx_padalign
name|mtx
decl_stmt|;
comment|/* state lock */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|ccb_hdr
argument_list|)
name|doneq
expr_stmt|;
comment|/* queue of completed CCBs */
name|int
name|batch
decl_stmt|;
comment|/* doneq is in use */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ahci_enclosure
block|{
name|device_t
name|dev
decl_stmt|;
comment|/* Device handle */
name|struct
name|resource
modifier|*
name|r_memc
decl_stmt|;
comment|/* Control register */
name|struct
name|resource
modifier|*
name|r_memt
decl_stmt|;
comment|/* Transmit buffer */
name|struct
name|resource
modifier|*
name|r_memr
decl_stmt|;
comment|/* Receive buffer */
name|struct
name|cam_sim
modifier|*
name|sim
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
name|struct
name|mtx
name|mtx
decl_stmt|;
comment|/* state lock */
name|struct
name|ahci_led
name|leds
index|[
name|AHCI_MAX_PORTS
operator|*
literal|3
index|]
decl_stmt|;
name|uint32_t
name|capsem
decl_stmt|;
comment|/* Controller capabilities */
name|uint8_t
name|status
index|[
name|AHCI_MAX_PORTS
index|]
index|[
literal|4
index|]
decl_stmt|;
comment|/* ArrayDev statuses */
name|int
name|quirks
decl_stmt|;
name|int
name|channels
decl_stmt|;
name|uint32_t
name|ichannels
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* structure describing a AHCI controller */
end_comment

begin_struct
struct|struct
name|ahci_controller
block|{
name|device_t
name|dev
decl_stmt|;
name|bus_dma_tag_t
name|dma_tag
decl_stmt|;
name|int
name|r_rid
decl_stmt|;
name|int
name|r_msix_tab_rid
decl_stmt|;
name|int
name|r_msix_pba_rid
decl_stmt|;
name|uint16_t
name|vendorid
decl_stmt|;
comment|/* Vendor ID from the bus */
name|uint16_t
name|deviceid
decl_stmt|;
comment|/* Device ID from the bus */
name|uint16_t
name|subvendorid
decl_stmt|;
comment|/* Subvendor ID from the bus */
name|uint16_t
name|subdeviceid
decl_stmt|;
comment|/* Subdevice ID from the bus */
name|struct
name|resource
modifier|*
name|r_mem
decl_stmt|;
name|struct
name|resource
modifier|*
name|r_msix_table
decl_stmt|;
name|struct
name|resource
modifier|*
name|r_msix_pba
decl_stmt|;
name|struct
name|rman
name|sc_iomem
decl_stmt|;
struct|struct
name|ahci_controller_irq
block|{
name|struct
name|ahci_controller
modifier|*
name|ctlr
decl_stmt|;
name|struct
name|resource
modifier|*
name|r_irq
decl_stmt|;
name|void
modifier|*
name|handle
decl_stmt|;
name|int
name|r_irq_rid
decl_stmt|;
name|int
name|mode
decl_stmt|;
define|#
directive|define
name|AHCI_IRQ_MODE_ALL
value|0
define|#
directive|define
name|AHCI_IRQ_MODE_AFTER
value|1
define|#
directive|define
name|AHCI_IRQ_MODE_ONE
value|2
block|}
name|irqs
index|[
name|AHCI_MAX_IRQS
index|]
struct|;
name|uint32_t
name|caps
decl_stmt|;
comment|/* Controller capabilities */
name|uint32_t
name|caps2
decl_stmt|;
comment|/* Controller capabilities */
name|uint32_t
name|capsem
decl_stmt|;
comment|/* Controller capabilities */
name|uint32_t
name|emloc
decl_stmt|;
comment|/* EM buffer location */
name|int
name|quirks
decl_stmt|;
name|int
name|numirqs
decl_stmt|;
name|int
name|channels
decl_stmt|;
name|uint32_t
name|ichannels
decl_stmt|;
name|int
name|ccc
decl_stmt|;
comment|/* CCC timeout */
name|int
name|cccv
decl_stmt|;
comment|/* CCC vector */
name|int
name|direct
decl_stmt|;
comment|/* Direct command completion */
name|int
name|msi
decl_stmt|;
comment|/* MSI interupts */
struct|struct
block|{
name|void
function_decl|(
modifier|*
name|function
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|argument
decl_stmt|;
block|}
name|interrupt
index|[
name|AHCI_MAX_PORTS
index|]
struct|;
name|void
function_decl|(
modifier|*
name|ch_start
function_decl|)
parameter_list|(
name|struct
name|ahci_channel
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|ahci_err_type
block|{
name|AHCI_ERR_NONE
block|,
comment|/* No error */
name|AHCI_ERR_INVALID
block|,
comment|/* Error detected by us before submitting. */
name|AHCI_ERR_INNOCENT
block|,
comment|/* Innocent victim. */
name|AHCI_ERR_TFE
block|,
comment|/* Task File Error. */
name|AHCI_ERR_SATA
block|,
comment|/* SATA error. */
name|AHCI_ERR_TIMEOUT
block|,
comment|/* Command execution timeout. */
name|AHCI_ERR_NCQ
block|,
comment|/* NCQ command error. CCB should be put on hold 				 * until READ LOG executed to reveal error. */
block|}
enum|;
end_enum

begin_comment
comment|/* macros to hide busspace uglyness */
end_comment

begin_define
define|#
directive|define
name|ATA_INB
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_read_1((res), (offset))
end_define

begin_define
define|#
directive|define
name|ATA_INW
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_read_2((res), (offset))
end_define

begin_define
define|#
directive|define
name|ATA_INL
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_read_4((res), (offset))
end_define

begin_define
define|#
directive|define
name|ATA_INSW
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_read_multi_2((res), (offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_INSW_STRM
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_read_multi_stream_2((res), (offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_INSL
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_read_multi_4((res), (offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_INSL_STRM
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_read_multi_stream_4((res), (offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_OUTB
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_write_1((res), (offset), (value))
end_define

begin_define
define|#
directive|define
name|ATA_OUTW
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_write_2((res), (offset), (value))
end_define

begin_define
define|#
directive|define
name|ATA_OUTL
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_write_4((res), (offset), (value))
end_define

begin_define
define|#
directive|define
name|ATA_OUTSW
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_write_multi_2((res), (offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_OUTSW_STRM
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_write_multi_stream_2((res), (offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_OUTSL
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_write_multi_4((res), (offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_OUTSL_STRM
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_write_multi_stream_4((res), (offset), (addr), (count))
end_define

begin_comment
comment|/*  * On some platforms, we must ensure proper interdevice write ordering.  * The AHCI interrupt status register must be updated in HW before  * registers in interrupt controller.  * Unfortunately, only way how we can do it is readback.  *  * Currently, only ARM is known to have this issue.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arm__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATA_RBL
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_read_4((res), (offset))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATA_RBL
parameter_list|(
name|res
parameter_list|,
name|offset
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AHCI_Q_NOFORCE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AHCI_Q_NOPMP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AHCI_Q_NONCQ
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AHCI_Q_1CH
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AHCI_Q_2CH
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AHCI_Q_4CH
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AHCI_Q_EDGEIS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AHCI_Q_SATA2
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AHCI_Q_NOBSYRES
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AHCI_Q_NOAA
value|0x00000200
end_define

begin_define
define|#
directive|define
name|AHCI_Q_NOCOUNT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|AHCI_Q_ALTSIG
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AHCI_Q_NOMSI
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AHCI_Q_ATI_PMP_BUG
value|0x00002000
end_define

begin_define
define|#
directive|define
name|AHCI_Q_MAXIO_64K
value|0x00004000
end_define

begin_define
define|#
directive|define
name|AHCI_Q_SATA1_UNIT0
value|0x00008000
end_define

begin_comment
comment|/* need better method for this */
end_comment

begin_define
define|#
directive|define
name|AHCI_Q_ABAR0
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AHCI_Q_1MSI
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AHCI_Q_FORCE_PI
value|0x00040000
end_define

begin_define
define|#
directive|define
name|AHCI_Q_RESTORE_CAP
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AHCI_Q_NOMSIX
value|0x00100000
end_define

begin_define
define|#
directive|define
name|AHCI_Q_NOCCS
value|0x00400000
end_define

begin_define
define|#
directive|define
name|AHCI_Q_NOAUX
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AHCI_Q_BIT_STRING
define|\
value|"\020"			\ 	"\001NOFORCE"		\ 	"\002NOPMP"		\ 	"\003NONCQ"		\ 	"\0041CH"		\ 	"\0052CH"		\ 	"\0064CH"		\ 	"\007EDGEIS"		\ 	"\010SATA2"		\ 	"\011NOBSYRES"		\ 	"\012NOAA"		\ 	"\013NOCOUNT"		\ 	"\014ALTSIG"		\ 	"\015NOMSI"		\ 	"\016ATI_PMP_BUG"	\ 	"\017MAXIO_64K"		\ 	"\020SATA1_UNIT0"	\ 	"\021ABAR0"		\ 	"\0221MSI"              \ 	"\023FORCE_PI"          \ 	"\024RESTORE_CAP"	\ 	"\025NOMSIX"		\ 	"\027NOCCS"		\ 	"\030NOAUX"
end_define

begin_function_decl
name|int
name|ahci_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahci_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahci_setup_interrupt
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahci_print_child
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|resource
modifier|*
name|ahci_alloc_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|type
parameter_list|,
name|int
modifier|*
name|rid
parameter_list|,
name|rman_res_t
name|start
parameter_list|,
name|rman_res_t
name|end
parameter_list|,
name|rman_res_t
name|count
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahci_release_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|,
name|struct
name|resource
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahci_setup_intr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|struct
name|resource
modifier|*
name|irq
parameter_list|,
name|int
name|flags
parameter_list|,
name|driver_filter_t
modifier|*
name|filter
parameter_list|,
name|driver_intr_t
modifier|*
name|function
parameter_list|,
name|void
modifier|*
name|argument
parameter_list|,
name|void
modifier|*
modifier|*
name|cookiep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahci_teardown_intr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|struct
name|resource
modifier|*
name|irq
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahci_child_location_str
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bus_dma_tag_t
name|ahci_get_dma_tag
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahci_ctlr_reset
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahci_ctlr_setup
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahci_free_mem
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

end_unit

