begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 - 2008 SÃ¸ren Schmidt<sos@FreeBSD.org>  * Copyright (c) 2009-2012 Alexander Motin<mav@FreeBSD.org>  * Copyright (c) 2015-2016 Justin Hibbits<jhibbits@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* ATA register defines */
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

end_unit

