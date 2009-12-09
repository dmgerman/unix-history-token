begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Alexander Motin<mav@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_comment
comment|/*  * Global registers  */
end_comment

begin_define
define|#
directive|define
name|SIIS_GCTL
value|0x0040
end_define

begin_comment
comment|/* Global Control	*/
end_comment

begin_define
define|#
directive|define
name|SIIS_GCTL_GRESET
value|0x80000000
end_define

begin_comment
comment|/* Global Reset		*/
end_comment

begin_define
define|#
directive|define
name|SIIS_GCTL_MSIACK
value|0x40000000
end_define

begin_comment
comment|/* MSI Ack		*/
end_comment

begin_define
define|#
directive|define
name|SIIS_GCTL_I2C_IE
value|0x20000000
end_define

begin_comment
comment|/* I2C int enable	*/
end_comment

begin_define
define|#
directive|define
name|SIIS_GCTL_300CAP
value|0x01000000
end_define

begin_comment
comment|/* 3Gb/s capable (R)	*/
end_comment

begin_define
define|#
directive|define
name|SIIS_GCTL_PIE
parameter_list|(
name|n
parameter_list|)
value|(1<< (n))
end_define

begin_comment
comment|/* Port int enable	*/
end_comment

begin_define
define|#
directive|define
name|SIIS_IS
value|0x0044
end_define

begin_comment
comment|/* Interrupt Status	*/
end_comment

begin_define
define|#
directive|define
name|SIIS_IS_I2C
value|0x20000000
end_define

begin_comment
comment|/* I2C Int Status	*/
end_comment

begin_define
define|#
directive|define
name|SIIS_IS_PORT
parameter_list|(
name|n
parameter_list|)
value|(1<< (n))
end_define

begin_comment
comment|/* Port interrupt stat	*/
end_comment

begin_define
define|#
directive|define
name|SIIS_PHYCONF
value|0x0048
end_define

begin_comment
comment|/* PHY Configuration */
end_comment

begin_define
define|#
directive|define
name|SIIS_BIST_CTL
value|0x0050
end_define

begin_define
define|#
directive|define
name|SIIS_BIST_PATTERN
value|0x0054
end_define

begin_comment
comment|/* 32 bit pattern */
end_comment

begin_define
define|#
directive|define
name|SIIS_BIST_STATUS
value|0x0058
end_define

begin_define
define|#
directive|define
name|SIIS_I2C_CTL
value|0x0060
end_define

begin_define
define|#
directive|define
name|SIIS_I2C_STS
value|0x0064
end_define

begin_define
define|#
directive|define
name|SIIS_I2C_SADDR
value|0x0068
end_define

begin_define
define|#
directive|define
name|SIIS_I2C_DATA
value|0x006C
end_define

begin_define
define|#
directive|define
name|SIIS_FLASH_ADDR
value|0x0070
end_define

begin_define
define|#
directive|define
name|SIIS_GPIO
value|0x0074
end_define

begin_comment
comment|/*  * Port registers  */
end_comment

begin_define
define|#
directive|define
name|SIIS_P_LRAM
value|0x0000
end_define

begin_define
define|#
directive|define
name|SIIS_P_LRAM_SLOT
parameter_list|(
name|i
parameter_list|)
value|(SIIS_P_LRAM + i * 128)
end_define

begin_define
define|#
directive|define
name|SIIS_P_PMPSTS
parameter_list|(
name|i
parameter_list|)
value|(0x0F80 + i * 8)
end_define

begin_define
define|#
directive|define
name|SIIS_P_PMPQACT
parameter_list|(
name|i
parameter_list|)
value|(0x0F80 + i * 8 + 4)
end_define

begin_define
define|#
directive|define
name|SIIS_P_STS
value|0x1000
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTLSET
value|0x1000
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTLCLR
value|0x1004
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTL_READY
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTL_OOBB
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTL_ACT
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTL_ACT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTL_LED_ON
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTL_AIA
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTL_PME
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTL_IA
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTL_IR
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTL_32BIT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTL_SCR_DIS
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTL_CONT_DIS
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTL_TBIST
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTL_RESUME
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTL_PLENGTH
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTL_LED_DIS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTL_INT_NCOR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTL_PORT_INIT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTL_DEV_RESET
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTL_PORT_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SIIS_P_IS
value|0x1008
end_define

begin_define
define|#
directive|define
name|SIIS_P_IX_SDBN
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SIIS_P_IX_HS_ET
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SIIS_P_IX_CRC_ET
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SIIS_P_IX_8_10_ET
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SIIS_P_IX_DEX
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SIIS_P_IX_UNRECFIS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SIIS_P_IX_COMWAKE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SIIS_P_IX_PHYRDYCHG
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SIIS_P_IX_PMCHG
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SIIS_P_IX_READY
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SIIS_P_IX_COMMERR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SIIS_P_IX_COMMCOMP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SIIS_P_IX_ENABLED
value|SIIS_P_IX_COMMCOMP | SIIS_P_IX_COMMERR | \     SIIS_P_IX_PHYRDYCHG | SIIS_P_IX_SDBN
end_define

begin_define
define|#
directive|define
name|SIIS_P_IESET
value|0x1010
end_define

begin_define
define|#
directive|define
name|SIIS_P_IECLR
value|0x1014
end_define

begin_define
define|#
directive|define
name|SIIS_P_CACTU
value|0x101C
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDEFIFO
value|0x1020
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR
value|0x1024
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR_DEV
value|1
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR_SDB
value|2
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR_DATAFIS
value|3
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR_SENDFIS
value|4
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR_INCSTATE
value|5
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR_DIRECTION
value|6
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR_UNDERRUN
value|7
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR_OVERRUN
value|8
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR_LLOVERRUN
value|9
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR_PPE
value|11
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR_SGTALIGN
value|16
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR_PCITASGT
value|17
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR_OCIMASGT
value|18
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR_PCIPESGT
value|19
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR_PRBALIGN
value|24
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR_PCITAPRB
value|25
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR_PCIMAPRB
value|26
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR_PCIPEPRB
value|27
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR_PCITADATA
value|33
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR_PCIMADATA
value|34
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR_PCIPEDATA
value|35
end_define

begin_define
define|#
directive|define
name|SIIS_P_CMDERR_SERVICE
value|36
end_define

begin_define
define|#
directive|define
name|SIIS_P_FISCFG
value|0x1028
end_define

begin_define
define|#
directive|define
name|SIIS_P_PCIEFIFOTH
value|0x102C
end_define

begin_define
define|#
directive|define
name|SIIS_P_8_10_DEC_ERR
value|0x1040
end_define

begin_define
define|#
directive|define
name|SIIS_P_CRC_ERR
value|0x1044
end_define

begin_define
define|#
directive|define
name|SIIS_P_HS_ERR
value|0x1048
end_define

begin_define
define|#
directive|define
name|SIIS_P_PHYCFG
value|0x1050
end_define

begin_define
define|#
directive|define
name|SIIS_P_SS
value|0x1800
end_define

begin_define
define|#
directive|define
name|SIIS_P_SS_ATTN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SIIS_P_CACTL
parameter_list|(
name|i
parameter_list|)
value|(0x1C00 + i * 8)
end_define

begin_define
define|#
directive|define
name|SIIS_P_CACTH
parameter_list|(
name|i
parameter_list|)
value|(0x1C00 + i * 8 + 4)
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTX
value|0x1E04
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTX_SLOT
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTX_SLOT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTX_PMP
value|0x000001E0
end_define

begin_define
define|#
directive|define
name|SIIS_P_CTX_PMP_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|SIIS_P_SCTL
value|0x1F00
end_define

begin_define
define|#
directive|define
name|SIIS_P_SSTS
value|0x1F04
end_define

begin_define
define|#
directive|define
name|SIIS_P_SERR
value|0x1F08
end_define

begin_define
define|#
directive|define
name|SIIS_P_SACT
value|0x1F0C
end_define

begin_define
define|#
directive|define
name|SIIS_P_SNTF
value|0x1F10
end_define

begin_define
define|#
directive|define
name|SIIS_MAX_PORTS
value|4
end_define

begin_define
define|#
directive|define
name|SIIS_MAX_SLOTS
value|31
end_define

begin_define
define|#
directive|define
name|SIIS_OFFSET
value|0x100
end_define

begin_define
define|#
directive|define
name|SIIS_STEP
value|0x80
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
name|SIIS_SG_ENTRIES
value|(roundup(btoc(MAXPHYS), 4) + 1)
end_define

begin_comment
comment|/* Command tables. Up to 32 commands, Each, 128byte aligned. */
end_comment

begin_define
define|#
directive|define
name|SIIS_CT_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|SIIS_CT_SIZE
value|(32 + 16 + SIIS_SG_ENTRIES * 16)
end_define

begin_comment
comment|/* Total main work area. */
end_comment

begin_define
define|#
directive|define
name|SIIS_WORK_SIZE
value|(SIIS_CT_OFFSET + SIIS_CT_SIZE * SIIS_MAX_SLOTS)
end_define

begin_struct
struct|struct
name|siis_dma_prd
block|{
name|u_int64_t
name|dba
decl_stmt|;
name|u_int32_t
name|dbc
decl_stmt|;
name|u_int32_t
name|control
decl_stmt|;
define|#
directive|define
name|SIIS_PRD_TRM
value|0x80000000
define|#
directive|define
name|SIIS_PRD_LNK
value|0x40000000
define|#
directive|define
name|SIIS_PRD_DRD
value|0x20000000
define|#
directive|define
name|SIIS_PRD_XCF
value|0x10000000
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|siis_cmd_ata
block|{
name|struct
name|siis_dma_prd
name|prd
index|[
literal|1
operator|+
name|SIIS_SG_ENTRIES
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|siis_cmd_atapi
block|{
name|u_int8_t
name|ccb
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|siis_dma_prd
name|prd
index|[
name|SIIS_SG_ENTRIES
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|siis_cmd
block|{
name|u_int16_t
name|control
decl_stmt|;
define|#
directive|define
name|SIIS_PRB_PROTOCOL_OVERRIDE
value|0x0001
define|#
directive|define
name|SIIS_PRB_RETRANSMIT
value|0x0002
define|#
directive|define
name|SIIS_PRB_EXTERNAL_COMMAND
value|0x0004
define|#
directive|define
name|SIIS_PRB_RECEIVE
value|0x0008
define|#
directive|define
name|SIIS_PRB_PACKET_READ
value|0x0010
define|#
directive|define
name|SIIS_PRB_PACKET_WRITE
value|0x0020
define|#
directive|define
name|SIIS_PRB_INTERRUPT_MASK
value|0x0040
define|#
directive|define
name|SIIS_PRB_SOFT_RESET
value|0x0080
name|u_int16_t
name|protocol_override
decl_stmt|;
name|u_int32_t
name|transfer_count
decl_stmt|;
name|u_int8_t
name|fis
index|[
literal|24
index|]
decl_stmt|;
union|union
block|{
name|struct
name|siis_cmd_ata
name|ata
decl_stmt|;
name|struct
name|siis_cmd_atapi
name|atapi
decl_stmt|;
block|}
name|u
union|;
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
name|data_tag
decl_stmt|;
comment|/* data DMA tag */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|siis_slot_states
block|{
name|SIIS_SLOT_EMPTY
block|,
name|SIIS_SLOT_LOADING
block|,
name|SIIS_SLOT_RUNNING
block|,
name|SIIS_SLOT_WAITING
block|}
enum|;
end_enum

begin_struct
struct|struct
name|siis_slot
block|{
name|device_t
name|dev
decl_stmt|;
comment|/* Device handle */
name|u_int8_t
name|slot
decl_stmt|;
comment|/* Number of this slot */
name|enum
name|siis_slot_states
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
name|siis_device
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
name|tags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* structure describing an ATA channel */
end_comment

begin_struct
struct|struct
name|siis_channel
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
name|int
name|quirks
decl_stmt|;
name|int
name|pm_level
decl_stmt|;
comment|/* power management level */
name|struct
name|siis_slot
name|slot
index|[
name|SIIS_MAX_SLOTS
index|]
decl_stmt|;
name|union
name|ccb
modifier|*
name|hold
index|[
name|SIIS_MAX_SLOTS
index|]
decl_stmt|;
name|struct
name|mtx
name|mtx
decl_stmt|;
comment|/* state lock */
name|int
name|devices
decl_stmt|;
comment|/* What is present */
name|int
name|pm_present
decl_stmt|;
comment|/* PM presence reported */
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
comment|/* Slots with atomic commands */
name|uint32_t
name|eslots
decl_stmt|;
comment|/* Slots in error */
name|uint32_t
name|toslots
decl_stmt|;
comment|/* Slots in timeout */
name|int
name|numrslots
decl_stmt|;
comment|/* Number of running slots */
name|int
name|numtslots
index|[
name|SIIS_MAX_SLOTS
index|]
decl_stmt|;
comment|/* Number of tagged slots */
name|int
name|numhslots
decl_stmt|;
comment|/* Number of holden slots */
name|int
name|readlog
decl_stmt|;
comment|/* Our READ LOG active */
name|int
name|fatalerr
decl_stmt|;
comment|/* Fatal error happend */
name|int
name|recovery
decl_stmt|;
comment|/* Some slots are in error */
name|union
name|ccb
modifier|*
name|frozen
decl_stmt|;
comment|/* Frozen command */
name|struct
name|siis_device
name|user
index|[
literal|16
index|]
decl_stmt|;
comment|/* User-specified settings */
name|struct
name|siis_device
name|curr
index|[
literal|16
index|]
decl_stmt|;
comment|/* Current settings */
block|}
struct|;
end_struct

begin_comment
comment|/* structure describing a SIIS controller */
end_comment

begin_struct
struct|struct
name|siis_controller
block|{
name|device_t
name|dev
decl_stmt|;
name|int
name|r_grid
decl_stmt|;
name|struct
name|resource
modifier|*
name|r_gmem
decl_stmt|;
name|int
name|r_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|r_mem
decl_stmt|;
name|struct
name|rman
name|sc_iomem
decl_stmt|;
struct|struct
name|siis_controller_irq
block|{
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
block|}
name|irq
struct|;
name|int
name|quirks
decl_stmt|;
name|int
name|channels
decl_stmt|;
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
name|SIIS_MAX_PORTS
index|]
struct|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|siis_err_type
block|{
name|SIIS_ERR_NONE
block|,
comment|/* No error */
name|SIIS_ERR_INVALID
block|,
comment|/* Error detected by us before submitting. */
name|SIIS_ERR_INNOCENT
block|,
comment|/* Innocent victim. */
name|SIIS_ERR_TFE
block|,
comment|/* Task File Error. */
name|SIIS_ERR_SATA
block|,
comment|/* SATA error. */
name|SIIS_ERR_TIMEOUT
block|,
comment|/* Command execution timeout. */
name|SIIS_ERR_NCQ
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

end_unit

