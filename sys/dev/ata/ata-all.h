begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 - 2007 Søren Schmidt<sos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|ATA_CTLOFFSET
value|0x206
end_define

begin_comment
comment|/* control register offset */
end_comment

begin_define
define|#
directive|define
name|ATA_PCCARD_CTLOFFSET
value|0x0e
end_define

begin_comment
comment|/* do for PCCARD devices */
end_comment

begin_define
define|#
directive|define
name|ATA_PC98_CTLOFFSET
value|0x10c
end_define

begin_comment
comment|/* do for PC98 devices */
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
name|ATA_SS_CONWELL_MASK
define|\
value|(ATA_SS_DET_MASK|ATA_SS_SPD_MASK|ATA_SS_IPM_MASK)
end_define

begin_define
define|#
directive|define
name|ATA_SS_CONWELL_GEN1
define|\
value|(ATA_SS_DET_PHY_ONLINE|ATA_SS_SPD_GEN1|ATA_SS_IPM_ACTIVE)
end_define

begin_define
define|#
directive|define
name|ATA_SS_CONWELL_GEN2
define|\
value|(ATA_SS_DET_PHY_ONLINE|ATA_SS_SPD_GEN2|ATA_SS_IPM_ACTIVE)
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

begin_comment
comment|/* SATA AHCI v1.0 register defines */
end_comment

begin_define
define|#
directive|define
name|ATA_AHCI_CAP
value|0x00
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_NPMASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_CAP_CLO
value|0x01000000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_CAP_64BIT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_GHC
value|0x04
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_GHC_AE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_GHC_IE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_GHC_HR
value|0x80000001
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_IS
value|0x08
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_PI
value|0x0c
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_VS
value|0x10
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_OFFSET
value|0x80
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CLB
value|0x100
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CLBU
value|0x104
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_FB
value|0x108
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_FBU
value|0x10c
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_IS
value|0x110
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_IE
value|0x114
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_IX_DHR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_IX_PS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_IX_DS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_IX_SDB
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_IX_UF
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_IX_DP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_IX_PC
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_IX_DI
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_IX_PRC
value|0x00400000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_IX_IPM
value|0x00800000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_IX_OF
value|0x01000000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_IX_INF
value|0x04000000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_IX_IF
value|0x08000000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_IX_HBD
value|0x10000000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_IX_HBF
value|0x20000000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_IX_TFE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_IX_CPD
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD
value|0x118
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_ST
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_SUD
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_POD
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_CLO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_FRE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_CCS_MASK
value|0x00001f00
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_ISS
value|0x00002000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_FR
value|0x00004000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_CR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_CPS
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_PMA
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_HPCP
value|0x00040000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_ISP
value|0x00080000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_CPD
value|0x00100000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_ATAPI
value|0x01000000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_DLAE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_ALPE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_ASP
value|0x08000000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_ICC_MASK
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_NOOP
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_ACTIVE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_PARTIAL
value|0x20000000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CMD_SLUMPER
value|0x60000000
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_TFD
value|0x120
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_SIG
value|0x124
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_SSTS
value|0x128
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_SCTL
value|0x12c
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_SERR
value|0x130
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_SACT
value|0x134
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_P_CI
value|0x138
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_CL_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_CL_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_FB_OFFSET
value|1024
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_CT_OFFSET
value|1024+256
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_CT_SG_OFFSET
value|128
end_define

begin_define
define|#
directive|define
name|ATA_AHCI_CT_SIZE
value|256
end_define

begin_struct
struct|struct
name|ata_ahci_dma_prd
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
name|ATA_AHCI_PRD_MASK
value|0x003fffff
comment|/* max 4MB */
define|#
directive|define
name|ATA_AHCI_PRD_IPC
value|(1<<31)
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ata_ahci_cmd_tab
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
name|ata_ahci_dma_prd
name|prd_tab
index|[
literal|16
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ata_ahci_cmd_list
block|{
name|u_int16_t
name|cmd_flags
decl_stmt|;
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
comment|/* DMA register defines */
end_comment

begin_define
define|#
directive|define
name|ATA_DMA_ENTRIES
value|256
end_define

begin_define
define|#
directive|define
name|ATA_DMA_EOT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ATA_BMCMD_PORT
value|17
end_define

begin_define
define|#
directive|define
name|ATA_BMCMD_START_STOP
value|0x01
end_define

begin_define
define|#
directive|define
name|ATA_BMCMD_WRITE_READ
value|0x08
end_define

begin_define
define|#
directive|define
name|ATA_BMDEVSPEC_0
value|18
end_define

begin_define
define|#
directive|define
name|ATA_BMSTAT_PORT
value|19
end_define

begin_define
define|#
directive|define
name|ATA_BMSTAT_ACTIVE
value|0x01
end_define

begin_define
define|#
directive|define
name|ATA_BMSTAT_ERROR
value|0x02
end_define

begin_define
define|#
directive|define
name|ATA_BMSTAT_INTERRUPT
value|0x04
end_define

begin_define
define|#
directive|define
name|ATA_BMSTAT_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|ATA_BMSTAT_DMA_MASTER
value|0x20
end_define

begin_define
define|#
directive|define
name|ATA_BMSTAT_DMA_SLAVE
value|0x40
end_define

begin_define
define|#
directive|define
name|ATA_BMSTAT_DMA_SIMPLEX
value|0x80
end_define

begin_define
define|#
directive|define
name|ATA_BMDEVSPEC_1
value|20
end_define

begin_define
define|#
directive|define
name|ATA_BMDTP_PORT
value|21
end_define

begin_define
define|#
directive|define
name|ATA_IDX_ADDR
value|22
end_define

begin_define
define|#
directive|define
name|ATA_IDX_DATA
value|23
end_define

begin_define
define|#
directive|define
name|ATA_MAX_RES
value|24
end_define

begin_comment
comment|/* misc defines */
end_comment

begin_define
define|#
directive|define
name|ATA_PRIMARY
value|0x1f0
end_define

begin_define
define|#
directive|define
name|ATA_SECONDARY
value|0x170
end_define

begin_define
define|#
directive|define
name|ATA_PC98_BANK
value|0x432
end_define

begin_define
define|#
directive|define
name|ATA_IOSIZE
value|0x08
end_define

begin_define
define|#
directive|define
name|ATA_PC98_IOSIZE
value|0x10
end_define

begin_define
define|#
directive|define
name|ATA_CTLIOSIZE
value|0x01
end_define

begin_define
define|#
directive|define
name|ATA_BMIOSIZE
value|0x08
end_define

begin_define
define|#
directive|define
name|ATA_PC98_BANKIOSIZE
value|0x01
end_define

begin_define
define|#
directive|define
name|ATA_IOADDR_RID
value|0
end_define

begin_define
define|#
directive|define
name|ATA_CTLADDR_RID
value|1
end_define

begin_define
define|#
directive|define
name|ATA_BMADDR_RID
value|0x20
end_define

begin_define
define|#
directive|define
name|ATA_PC98_CTLADDR_RID
value|8
end_define

begin_define
define|#
directive|define
name|ATA_PC98_BANKADDR_RID
value|9
end_define

begin_define
define|#
directive|define
name|ATA_IRQ_RID
value|0
end_define

begin_define
define|#
directive|define
name|ATA_DEV
parameter_list|(
name|device
parameter_list|)
value|((device == ATA_MASTER) ? 0 : 1)
end_define

begin_define
define|#
directive|define
name|ATA_CFA_MAGIC1
value|0x844A
end_define

begin_define
define|#
directive|define
name|ATA_CFA_MAGIC2
value|0x848A
end_define

begin_define
define|#
directive|define
name|ATAPI_MAGIC_LSB
value|0x14
end_define

begin_define
define|#
directive|define
name|ATAPI_MAGIC_MSB
value|0xeb
end_define

begin_define
define|#
directive|define
name|ATAPI_P_READ
value|(ATA_S_DRQ | ATA_I_IN)
end_define

begin_define
define|#
directive|define
name|ATAPI_P_WRITE
value|(ATA_S_DRQ)
end_define

begin_define
define|#
directive|define
name|ATAPI_P_CMDOUT
value|(ATA_S_DRQ | ATA_I_CMD)
end_define

begin_define
define|#
directive|define
name|ATAPI_P_DONEDRQ
value|(ATA_S_DRQ | ATA_I_CMD | ATA_I_IN)
end_define

begin_define
define|#
directive|define
name|ATAPI_P_DONE
value|(ATA_I_CMD | ATA_I_IN)
end_define

begin_define
define|#
directive|define
name|ATAPI_P_ABORT
value|0
end_define

begin_define
define|#
directive|define
name|ATA_INTR_FLAGS
value|(INTR_MPSAFE|INTR_TYPE_BIO|INTR_ENTROPY)
end_define

begin_define
define|#
directive|define
name|ATA_OP_CONTINUES
value|0
end_define

begin_define
define|#
directive|define
name|ATA_OP_FINISHED
value|1
end_define

begin_define
define|#
directive|define
name|ATA_MAX_28BIT_LBA
value|268435455UL
end_define

begin_comment
comment|/* structure used for composite atomic operations */
end_comment

begin_define
define|#
directive|define
name|MAX_COMPOSITES
value|32
end_define

begin_comment
comment|/* u_int32_t bits */
end_comment

begin_struct
struct|struct
name|ata_composite
block|{
name|struct
name|mtx
name|lock
decl_stmt|;
comment|/* control lock */
name|u_int32_t
name|rd_needed
decl_stmt|;
comment|/* needed read subdisks */
name|u_int32_t
name|rd_done
decl_stmt|;
comment|/* done read subdisks */
name|u_int32_t
name|wr_needed
decl_stmt|;
comment|/* needed write subdisks */
name|u_int32_t
name|wr_depend
decl_stmt|;
comment|/* write depends on subdisks */
name|u_int32_t
name|wr_done
decl_stmt|;
comment|/* done write subdisks */
name|struct
name|ata_request
modifier|*
name|request
index|[
name|MAX_COMPOSITES
index|]
decl_stmt|;
name|u_int32_t
name|residual
decl_stmt|;
comment|/* bytes still to transfer */
name|caddr_t
name|data_1
decl_stmt|;
name|caddr_t
name|data_2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* structure used to queue an ATA/ATAPI request */
end_comment

begin_struct
struct|struct
name|ata_request
block|{
name|device_t
name|dev
decl_stmt|;
comment|/* device handle */
name|device_t
name|parent
decl_stmt|;
comment|/* channel handle */
union|union
block|{
struct|struct
block|{
name|u_int8_t
name|command
decl_stmt|;
comment|/* command reg */
name|u_int16_t
name|feature
decl_stmt|;
comment|/* feature reg */
name|u_int16_t
name|count
decl_stmt|;
comment|/* count reg */
name|u_int64_t
name|lba
decl_stmt|;
comment|/* lba reg */
block|}
name|ata
struct|;
struct|struct
block|{
name|u_int8_t
name|ccb
index|[
literal|16
index|]
decl_stmt|;
comment|/* ATAPI command block */
name|struct
name|atapi_sense
name|sense
decl_stmt|;
comment|/* ATAPI request sense data */
name|u_int8_t
name|saved_cmd
decl_stmt|;
comment|/* ATAPI saved command */
block|}
name|atapi
struct|;
block|}
name|u
union|;
name|u_int32_t
name|bytecount
decl_stmt|;
comment|/* bytes to transfer */
name|u_int32_t
name|transfersize
decl_stmt|;
comment|/* bytes pr transfer */
name|caddr_t
name|data
decl_stmt|;
comment|/* pointer to data buf */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|ATA_R_CONTROL
value|0x00000001
define|#
directive|define
name|ATA_R_READ
value|0x00000002
define|#
directive|define
name|ATA_R_WRITE
value|0x00000004
define|#
directive|define
name|ATA_R_ATAPI
value|0x00000008
define|#
directive|define
name|ATA_R_DMA
value|0x00000010
define|#
directive|define
name|ATA_R_QUIET
value|0x00000020
define|#
directive|define
name|ATA_R_TIMEOUT
value|0x00000040
define|#
directive|define
name|ATA_R_ORDERED
value|0x00000100
define|#
directive|define
name|ATA_R_AT_HEAD
value|0x00000200
define|#
directive|define
name|ATA_R_REQUEUE
value|0x00000400
define|#
directive|define
name|ATA_R_THREAD
value|0x00000800
define|#
directive|define
name|ATA_R_DIRECT
value|0x00001000
define|#
directive|define
name|ATA_R_DEBUG
value|0x10000000
define|#
directive|define
name|ATA_R_DANGER1
value|0x20000000
define|#
directive|define
name|ATA_R_DANGER2
value|0x40000000
name|u_int8_t
name|status
decl_stmt|;
comment|/* ATA status */
name|u_int8_t
name|error
decl_stmt|;
comment|/* ATA error */
name|u_int8_t
name|dmastat
decl_stmt|;
comment|/* DMA status */
name|u_int32_t
name|donecount
decl_stmt|;
comment|/* bytes transferred */
name|int
name|result
decl_stmt|;
comment|/* result error code */
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|struct
name|ata_request
modifier|*
name|request
parameter_list|)
function_decl|;
name|struct
name|sema
name|done
decl_stmt|;
comment|/* request done sema */
name|int
name|retries
decl_stmt|;
comment|/* retry count */
name|int
name|timeout
decl_stmt|;
comment|/* timeout for this cmd */
name|struct
name|callout
name|callout
decl_stmt|;
comment|/* callout management */
name|struct
name|task
name|task
decl_stmt|;
comment|/* task management */
name|struct
name|bio
modifier|*
name|bio
decl_stmt|;
comment|/* bio for this request */
name|int
name|this
decl_stmt|;
comment|/* this request ID */
name|struct
name|ata_composite
modifier|*
name|composite
decl_stmt|;
comment|/* for composite atomic ops */
name|void
modifier|*
name|driver
decl_stmt|;
comment|/* driver specific */
name|TAILQ_ENTRY
argument_list|(
argument|ata_request
argument_list|)
name|chain
expr_stmt|;
comment|/* list management */
block|}
struct|;
end_struct

begin_comment
comment|/* define this for debugging request processing */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|ATA_DEBUG_RQ
parameter_list|(
name|request
parameter_list|,
name|string
parameter_list|)
define|\
value|{ \     if (request->flags& ATA_R_DEBUG) \ 	device_printf(request->dev, "req=%p %s " string "\n", \ 		      request, ata_cmd2str(request)); \     }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATA_DEBUG_RQ
parameter_list|(
name|request
parameter_list|,
name|string
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* structure describing an ATA/ATAPI device */
end_comment

begin_struct
struct|struct
name|ata_device
block|{
name|device_t
name|dev
decl_stmt|;
comment|/* device handle */
name|int
name|unit
decl_stmt|;
comment|/* physical unit */
define|#
directive|define
name|ATA_MASTER
value|0x00
define|#
directive|define
name|ATA_SLAVE
value|0x10
name|struct
name|ata_params
name|param
decl_stmt|;
comment|/* ata param structure */
name|int
name|mode
decl_stmt|;
comment|/* current transfermode */
name|u_int32_t
name|max_iosize
decl_stmt|;
comment|/* max IO size */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|ATA_D_USE_CHS
value|0x0001
define|#
directive|define
name|ATA_D_MEDIA_CHANGED
value|0x0002
define|#
directive|define
name|ATA_D_ENC_PRESENT
value|0x0004
define|#
directive|define
name|ATA_D_48BIT_ACTIVE
value|0x0008
block|}
struct|;
end_struct

begin_comment
comment|/* structure for holding DMA Physical Region Descriptors (PRD) entries */
end_comment

begin_struct
struct|struct
name|ata_dma_prdentry
block|{
name|u_int32_t
name|addr
decl_stmt|;
name|u_int32_t
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* structure used by the setprd function */
end_comment

begin_struct
struct|struct
name|ata_dmasetprd_args
block|{
name|void
modifier|*
name|dmatab
decl_stmt|;
name|int
name|nsegs
decl_stmt|;
name|int
name|error
decl_stmt|;
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
name|dmatag
decl_stmt|;
comment|/* parent DMA tag */
name|bus_dma_tag_t
name|sg_tag
decl_stmt|;
comment|/* SG list DMA tag */
name|bus_dmamap_t
name|sg_map
decl_stmt|;
comment|/* SG list DMA map */
name|void
modifier|*
name|sg
decl_stmt|;
comment|/* DMA transfer table */
name|bus_addr_t
name|sg_bus
decl_stmt|;
comment|/* bus address of dmatab */
name|bus_dma_tag_t
name|data_tag
decl_stmt|;
comment|/* data DMA tag */
name|bus_dmamap_t
name|data_map
decl_stmt|;
comment|/* data DMA map */
name|bus_dma_tag_t
name|work_tag
decl_stmt|;
comment|/* workspace DMA tag */
name|bus_dmamap_t
name|work_map
decl_stmt|;
comment|/* workspace DMA map */
name|u_int8_t
modifier|*
name|work
decl_stmt|;
comment|/* workspace */
name|bus_addr_t
name|work_bus
decl_stmt|;
comment|/* bus address of dmatab */
name|u_int32_t
name|alignment
decl_stmt|;
comment|/* DMA SG list alignment */
name|u_int32_t
name|boundary
decl_stmt|;
comment|/* DMA SG list boundary */
name|u_int32_t
name|segsize
decl_stmt|;
comment|/* DMA SG list segment size */
name|u_int32_t
name|max_iosize
decl_stmt|;
comment|/* DMA data max IO size */
name|u_int32_t
name|cur_iosize
decl_stmt|;
comment|/* DMA data current IO size */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|ATA_DMA_READ
value|0x01
comment|/* transaction is a read */
define|#
directive|define
name|ATA_DMA_LOADED
value|0x02
comment|/* DMA tables etc loaded */
define|#
directive|define
name|ATA_DMA_ACTIVE
value|0x04
comment|/* DMA transfer in progress */
name|void
function_decl|(
modifier|*
name|alloc
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|free
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|setprd
function_decl|)
parameter_list|(
name|void
modifier|*
name|xsc
parameter_list|,
name|bus_dma_segment_t
modifier|*
name|segs
parameter_list|,
name|int
name|nsegs
parameter_list|,
name|int
name|error
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|load
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int32_t
name|count
parameter_list|,
name|int
name|dir
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|int
modifier|*
name|nsegs
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|unload
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|start
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|stop
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|reset
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* structure holding lowlevel functions */
end_comment

begin_struct
struct|struct
name|ata_lowlevel
block|{
name|int
function_decl|(
modifier|*
name|status
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|begin_transaction
function_decl|)
parameter_list|(
name|struct
name|ata_request
modifier|*
name|request
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|end_transaction
function_decl|)
parameter_list|(
name|struct
name|ata_request
modifier|*
name|request
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|command
function_decl|)
parameter_list|(
name|struct
name|ata_request
modifier|*
name|request
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* structure holding resources for an ATA channel */
end_comment

begin_struct
struct|struct
name|ata_resource
block|{
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|int
name|offset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* structure describing an ATA channel */
end_comment

begin_struct
struct|struct
name|ata_channel
block|{
name|device_t
name|dev
decl_stmt|;
comment|/* device handle */
name|int
name|unit
decl_stmt|;
comment|/* physical channel */
name|struct
name|ata_resource
name|r_io
index|[
name|ATA_MAX_RES
index|]
decl_stmt|;
comment|/* I/O resources */
name|struct
name|resource
modifier|*
name|r_irq
decl_stmt|;
comment|/* interrupt of this channel */
name|void
modifier|*
name|ih
decl_stmt|;
comment|/* interrupt handle */
name|struct
name|ata_lowlevel
name|hw
decl_stmt|;
comment|/* lowlevel HW functions */
name|struct
name|ata_dma
modifier|*
name|dma
decl_stmt|;
comment|/* DMA data / functions */
name|int
name|flags
decl_stmt|;
comment|/* channel flags */
define|#
directive|define
name|ATA_NO_SLAVE
value|0x01
define|#
directive|define
name|ATA_USE_16BIT
value|0x02
define|#
directive|define
name|ATA_ATAPI_DMA_RO
value|0x04
define|#
directive|define
name|ATA_NO_48BIT_DMA
value|0x08
define|#
directive|define
name|ATA_ALWAYS_DMASTAT
value|0x10
name|int
name|devices
decl_stmt|;
comment|/* what is present */
define|#
directive|define
name|ATA_ATA_MASTER
value|0x01
define|#
directive|define
name|ATA_ATA_SLAVE
value|0x02
define|#
directive|define
name|ATA_ATAPI_MASTER
value|0x04
define|#
directive|define
name|ATA_ATAPI_SLAVE
value|0x08
define|#
directive|define
name|ATA_PORTMULTIPLIER
value|0x10
name|struct
name|mtx
name|state_mtx
decl_stmt|;
comment|/* state lock */
name|int
name|state
decl_stmt|;
comment|/* ATA channel state */
define|#
directive|define
name|ATA_IDLE
value|0x0000
define|#
directive|define
name|ATA_ACTIVE
value|0x0001
define|#
directive|define
name|ATA_STALL_QUEUE
value|0x0002
name|struct
name|mtx
name|queue_mtx
decl_stmt|;
comment|/* queue lock */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ata_request
argument_list|)
name|ata_queue
expr_stmt|;
comment|/* head of ATA queue */
name|struct
name|ata_request
modifier|*
name|freezepoint
decl_stmt|;
comment|/* composite freezepoint */
name|struct
name|ata_request
modifier|*
name|running
decl_stmt|;
comment|/* currently running request */
block|}
struct|;
end_struct

begin_comment
comment|/* disk bay/enclosure related */
end_comment

begin_define
define|#
directive|define
name|ATA_LED_OFF
value|0x00
end_define

begin_define
define|#
directive|define
name|ATA_LED_RED
value|0x01
end_define

begin_define
define|#
directive|define
name|ATA_LED_GREEN
value|0x02
end_define

begin_define
define|#
directive|define
name|ATA_LED_ORANGE
value|0x03
end_define

begin_define
define|#
directive|define
name|ATA_LED_MASK
value|0x03
end_define

begin_comment
comment|/* externs */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|ata_raid_ioctl_func
function_decl|)
parameter_list|(
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|intr_config_hook
modifier|*
name|ata_delayed_attach
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|ata_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ata_wc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* public prototypes */
end_comment

begin_comment
comment|/* ata-all.c: */
end_comment

begin_function_decl
name|int
name|ata_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_reinit
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_suspend
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_resume
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_interrupt
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_device_ioctl
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_identify
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_default_registers
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_modify_if_48bit
parameter_list|(
name|struct
name|ata_request
modifier|*
name|request
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_udelay
parameter_list|(
name|int
name|interval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ata_mode2str
parameter_list|(
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_pmode
parameter_list|(
name|struct
name|ata_params
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_wmode
parameter_list|(
name|struct
name|ata_params
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_umode
parameter_list|(
name|struct
name|ata_params
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_limit_mode
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|mode
parameter_list|,
name|int
name|maxmode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ata-queue.c: */
end_comment

begin_function_decl
name|int
name|ata_controlcmd
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int8_t
name|command
parameter_list|,
name|u_int16_t
name|feature
parameter_list|,
name|u_int64_t
name|lba
parameter_list|,
name|u_int16_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_atapicmd
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int8_t
modifier|*
name|ccb
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|count
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_queue_request
parameter_list|(
name|struct
name|ata_request
modifier|*
name|request
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_start
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_finish
parameter_list|(
name|struct
name|ata_request
modifier|*
name|request
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_timeout
parameter_list|(
name|struct
name|ata_request
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_catch_inflight
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_fail_requests
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ata_cmd2str
parameter_list|(
name|struct
name|ata_request
modifier|*
name|request
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ata-lowlevel.c: */
end_comment

begin_function_decl
name|void
name|ata_generic_hw
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_begin_transaction
parameter_list|(
name|struct
name|ata_request
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_end_transaction
parameter_list|(
name|struct
name|ata_request
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_generic_reset
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_generic_command
parameter_list|(
name|struct
name|ata_request
modifier|*
name|request
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* macros for alloc/free of struct ata_request */
end_comment

begin_decl_stmt
specifier|extern
name|uma_zone_t
name|ata_request_zone
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ata_alloc_request
parameter_list|()
value|uma_zalloc(ata_request_zone, M_NOWAIT | M_ZERO)
end_define

begin_define
define|#
directive|define
name|ata_free_request
parameter_list|(
name|request
parameter_list|)
value|{ \ 	if (!(request->flags& ATA_R_DANGER2)) \ 	    uma_zfree(ata_request_zone, request); \ 	}
end_define

begin_comment
comment|/* macros for alloc/free of struct ata_composite */
end_comment

begin_decl_stmt
specifier|extern
name|uma_zone_t
name|ata_composite_zone
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ata_alloc_composite
parameter_list|()
value|uma_zalloc(ata_composite_zone, M_NOWAIT | M_ZERO)
end_define

begin_define
define|#
directive|define
name|ata_free_composite
parameter_list|(
name|composite
parameter_list|)
value|uma_zfree(ata_composite_zone, composite)
end_define

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_ATA
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* misc newbus defines */
end_comment

begin_define
define|#
directive|define
name|GRANDPARENT
parameter_list|(
name|dev
parameter_list|)
value|device_get_parent(device_get_parent(dev))
end_define

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
value|bus_space_read_1(rman_get_bustag((res)), \ 			 rman_get_bushandle((res)), (offset))
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
value|bus_space_read_2(rman_get_bustag((res)), \ 			 rman_get_bushandle((res)), (offset))
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
value|bus_space_read_4(rman_get_bustag((res)), \ 			 rman_get_bushandle((res)), (offset))
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
value|bus_space_read_multi_2(rman_get_bustag((res)), \ 			       rman_get_bushandle((res)), \ 			       (offset), (addr), (count))
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
value|bus_space_read_multi_stream_2(rman_get_bustag((res)), \ 				      rman_get_bushandle((res)), \ 				      (offset), (addr), (count))
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
value|bus_space_read_multi_4(rman_get_bustag((res)), \ 			       rman_get_bushandle((res)), \ 			       (offset), (addr), (count))
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
value|bus_space_read_multi_stream_4(rman_get_bustag((res)), \ 				      rman_get_bushandle((res)), \ 				      (offset), (addr), (count))
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
value|bus_space_write_1(rman_get_bustag((res)), \ 			  rman_get_bushandle((res)), (offset), (value))
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
value|bus_space_write_2(rman_get_bustag((res)), \ 			  rman_get_bushandle((res)), (offset), (value))
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
value|bus_space_write_4(rman_get_bustag((res)), \ 			  rman_get_bushandle((res)), (offset), (value))
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
value|bus_space_write_multi_2(rman_get_bustag((res)), \ 				rman_get_bushandle((res)), \ 				(offset), (addr), (count))
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
value|bus_space_write_multi_stream_2(rman_get_bustag((res)), \ 				       rman_get_bushandle((res)), \ 				       (offset), (addr), (count))
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
value|bus_space_write_multi_4(rman_get_bustag((res)), \ 				rman_get_bushandle((res)), \ 				(offset), (addr), (count))
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
value|bus_space_write_multi_stream_4(rman_get_bustag((res)), \ 				       rman_get_bushandle((res)), \ 				       (offset), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ATA_IDX_INB
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|)
define|\
value|ATA_INB(ch->r_io[idx].res, ch->r_io[idx].offset)
end_define

begin_define
define|#
directive|define
name|ATA_IDX_INW
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|)
define|\
value|ATA_INW(ch->r_io[idx].res, ch->r_io[idx].offset)
end_define

begin_define
define|#
directive|define
name|ATA_IDX_INL
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|)
define|\
value|ATA_INL(ch->r_io[idx].res, ch->r_io[idx].offset)
end_define

begin_define
define|#
directive|define
name|ATA_IDX_INSW
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|ATA_INSW(ch->r_io[idx].res, ch->r_io[idx].offset, addr, count)
end_define

begin_define
define|#
directive|define
name|ATA_IDX_INSW_STRM
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|ATA_INSW_STRM(ch->r_io[idx].res, ch->r_io[idx].offset, addr, count)
end_define

begin_define
define|#
directive|define
name|ATA_IDX_INSL
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|ATA_INSL(ch->r_io[idx].res, ch->r_io[idx].offset, addr, count)
end_define

begin_define
define|#
directive|define
name|ATA_IDX_INSL_STRM
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|ATA_INSL_STRM(ch->r_io[idx].res, ch->r_io[idx].offset, addr, count)
end_define

begin_define
define|#
directive|define
name|ATA_IDX_OUTB
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|,
name|value
parameter_list|)
define|\
value|ATA_OUTB(ch->r_io[idx].res, ch->r_io[idx].offset, value)
end_define

begin_define
define|#
directive|define
name|ATA_IDX_OUTW
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|,
name|value
parameter_list|)
define|\
value|ATA_OUTW(ch->r_io[idx].res, ch->r_io[idx].offset, value)
end_define

begin_define
define|#
directive|define
name|ATA_IDX_OUTL
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|,
name|value
parameter_list|)
define|\
value|ATA_OUTL(ch->r_io[idx].res, ch->r_io[idx].offset, value)
end_define

begin_define
define|#
directive|define
name|ATA_IDX_OUTSW
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|ATA_OUTSW(ch->r_io[idx].res, ch->r_io[idx].offset, addr, count)
end_define

begin_define
define|#
directive|define
name|ATA_IDX_OUTSW_STRM
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|ATA_OUTSW_STRM(ch->r_io[idx].res, ch->r_io[idx].offset, addr, count)
end_define

begin_define
define|#
directive|define
name|ATA_IDX_OUTSL
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|ATA_OUTSL(ch->r_io[idx].res, ch->r_io[idx].offset, addr, count)
end_define

begin_define
define|#
directive|define
name|ATA_IDX_OUTSL_STRM
parameter_list|(
name|ch
parameter_list|,
name|idx
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|ATA_OUTSL_STRM(ch->r_io[idx].res, ch->r_io[idx].offset, addr, count)
end_define

end_unit

