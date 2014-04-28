begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ian Lepore<ian@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IF_FFECREG_H
end_ifndef

begin_define
define|#
directive|define
name|IF_FFECREG_H
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Hardware defines for Freescale Fast Ethernet Controller.  */
end_comment

begin_comment
comment|/*  * MAC registers.  */
end_comment

begin_define
define|#
directive|define
name|FEC_IER_REG
value|0x0004
end_define

begin_define
define|#
directive|define
name|FEC_IEM_REG
value|0x0008
end_define

begin_define
define|#
directive|define
name|FEC_IER_HBERR
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|FEC_IER_BABR
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|FEC_IER_BABT
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|FEC_IER_GRA
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|FEC_IER_TXF
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|FEC_IER_TXB
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|FEC_IER_RXF
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|FEC_IER_RXB
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|FEC_IER_MII
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|FEC_IER_EBERR
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|FEC_IER_LC
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|FEC_IER_RL
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|FEC_IER_UN
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|FEC_IER_PLR
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|FEC_IER_WAKEUP
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|FEC_IER_AVAIL
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|FEC_IER_TIMER
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|FEC_RDAR_REG
value|0x0010
end_define

begin_define
define|#
directive|define
name|FEC_RDAR_RDAR
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|FEC_TDAR_REG
value|0x0014
end_define

begin_define
define|#
directive|define
name|FEC_TDAR_TDAR
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|FEC_ECR_REG
value|0x0024
end_define

begin_define
define|#
directive|define
name|FEC_ECR_DBSWP
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|FEC_ECR_STOPEN
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|FEC_ECR_DBGEN
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|FEC_ECR_SPEED
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|FEC_ECR_EN1588
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|FEC_ECR_SLEEP
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|FEC_ECR_MAGICEN
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|FEC_ECR_ETHEREN
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|FEC_ECR_RESET
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|FEC_MMFR_REG
value|0x0040
end_define

begin_define
define|#
directive|define
name|FEC_MMFR_ST_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|FEC_MMFR_ST_VALUE
value|(0x01<< FEC_MMFR_ST_SHIFT)
end_define

begin_define
define|#
directive|define
name|FEC_MMFR_OP_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|FEC_MMFR_OP_WRITE
value|(0x01<< FEC_MMFR_OP_SHIFT)
end_define

begin_define
define|#
directive|define
name|FEC_MMFR_OP_READ
value|(0x02<< FEC_MMFR_OP_SHIFT)
end_define

begin_define
define|#
directive|define
name|FEC_MMFR_PA_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|FEC_MMFR_PA_MASK
value|(0x1f<< FEC_MMFR_PA_SHIFT)
end_define

begin_define
define|#
directive|define
name|FEC_MMFR_RA_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|FEC_MMFR_RA_MASK
value|(0x1f<< FEC_MMFR_RA_SHIFT)
end_define

begin_define
define|#
directive|define
name|FEC_MMFR_TA_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FEC_MMFR_TA_VALUE
value|(0x02<< FEC_MMFR_TA_SHIFT)
end_define

begin_define
define|#
directive|define
name|FEC_MMFR_DATA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FEC_MMFR_DATA_MASK
value|(0xffff<< FEC_MMFR_DATA_SHIFT)
end_define

begin_define
define|#
directive|define
name|FEC_MSCR_REG
value|0x0044
end_define

begin_define
define|#
directive|define
name|FEC_MSCR_HOLDTIME_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|FEC_MSCR_HOLDTIME_MASK
value|(0x07<< FEC_MSCR_HOLDTIME_SHIFT)
end_define

begin_define
define|#
directive|define
name|FEC_MSCR_DIS_PRE
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|FEC_MSCR_MII_SPEED_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|FEC_MSCR_MII_SPEED_MASk
value|(0x3f<< FEC_MSCR_MII_SPEED_SHIFT)
end_define

begin_define
define|#
directive|define
name|FEC_MIBC_REG
value|0x0064
end_define

begin_define
define|#
directive|define
name|FEC_MIBC_DIS
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|FEC_MIBC_IDLE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|FEC_MIBC_CLEAR
value|(1<< 29)
end_define

begin_comment
comment|/* imx6 only */
end_comment

begin_define
define|#
directive|define
name|FEC_RCR_REG
value|0x0084
end_define

begin_define
define|#
directive|define
name|FEC_RCR_GRS
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|FEC_RCR_NLC
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|FEC_RCR_MAX_FL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FEC_RCR_MAX_FL_MASK
value|(0x3fff<< FEC_RCR_MAX_FL_SHIFT)
end_define

begin_define
define|#
directive|define
name|FEC_RCR_CFEN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|FEC_RCR_CRCFWD
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|FEC_RCR_PAUFWD
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|FEC_RCR_PADEN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|FEC_RCR_RMII_10T
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|FEC_RCR_RMII_MODE
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|FEC_RCR_RGMII_EN
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|FEC_RCR_FCE
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|FEC_RCR_BC_REJ
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|FEC_RCR_PROM
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|FEC_RCR_MII_MODE
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|FEC_RCR_DRT
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|FEC_RCR_LOOP
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|FEC_TCR_REG
value|0x00c4
end_define

begin_define
define|#
directive|define
name|FEC_TCR_ADDINS
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|FEC_TCR_ADDSEL_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|FEC_TCR_ADDSEL_MASK
value|(0x07<< FEC_TCR_ADDSEL_SHIFT)
end_define

begin_define
define|#
directive|define
name|FEC_TCR_RFC_PAUSE
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|FEC_TCR_TFC_PAUSE
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|FEC_TCR_FDEN
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|FEC_TCR_GTS
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|FEC_PALR_REG
value|0x00e4
end_define

begin_define
define|#
directive|define
name|FEC_PALR_PADDR1_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FEC_PALR_PADDR1_MASK
value|(0xffffffff<< FEC_PALR_PADDR1_SHIFT)
end_define

begin_define
define|#
directive|define
name|FEC_PAUR_REG
value|0x00e8
end_define

begin_define
define|#
directive|define
name|FEC_PAUR_PADDR2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FEC_PAUR_PADDR2_MASK
value|(0xffff<< FEC_PAUR_PADDR2_SHIFT)
end_define

begin_define
define|#
directive|define
name|FEC_PAUR_TYPE_VALUE
value|(0x8808)
end_define

begin_define
define|#
directive|define
name|FEC_OPD_REG
value|0x00ec
end_define

begin_define
define|#
directive|define
name|FEC_OPD_PAUSE_DUR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FEC_OPD_PAUSE_DUR_MASK
value|(0xffff<< FEC_OPD_PAUSE_DUR_SHIFT)
end_define

begin_define
define|#
directive|define
name|FEC_IAUR_REG
value|0x0118
end_define

begin_define
define|#
directive|define
name|FEC_IALR_REG
value|0x011c
end_define

begin_define
define|#
directive|define
name|FEC_GAUR_REG
value|0x0120
end_define

begin_define
define|#
directive|define
name|FEC_GALR_REG
value|0x0124
end_define

begin_define
define|#
directive|define
name|FEC_TFWR_REG
value|0x0144
end_define

begin_define
define|#
directive|define
name|FEC_TFWR_STRFWD
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|FEC_TFWR_TWFR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FEC_TFWR_TWFR_MASK
value|(0x3f<< FEC_TFWR_TWFR_SHIFT)
end_define

begin_define
define|#
directive|define
name|FEC_TFWR_TWFR_128BYTE
value|(0x02<< FEC_TFWR_TWFR_SHIFT)
end_define

begin_define
define|#
directive|define
name|FEC_RDSR_REG
value|0x0180
end_define

begin_define
define|#
directive|define
name|FEC_TDSR_REG
value|0x0184
end_define

begin_define
define|#
directive|define
name|FEC_MRBR_REG
value|0x0188
end_define

begin_define
define|#
directive|define
name|FEC_MRBR_R_BUF_SIZE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FEC_MRBR_R_BUF_SIZE_MASK
value|(0x3fff<< FEC_MRBR_R_BUF_SIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|FEC_RSFL_REG
value|0x0190
end_define

begin_define
define|#
directive|define
name|FEC_RSEM_REG
value|0x0194
end_define

begin_define
define|#
directive|define
name|FEC_RAEM_REG
value|0x0198
end_define

begin_define
define|#
directive|define
name|FEC_RAFL_REG
value|0x019c
end_define

begin_define
define|#
directive|define
name|FEC_TSEM_REG
value|0x01a0
end_define

begin_define
define|#
directive|define
name|FEC_TAEM_REG
value|0x01a4
end_define

begin_define
define|#
directive|define
name|FEC_TAFL_REG
value|0x01a8
end_define

begin_define
define|#
directive|define
name|FEC_TIPG_REG
value|0x01ac
end_define

begin_define
define|#
directive|define
name|FEC_FTRL_REG
value|0x01b0
end_define

begin_define
define|#
directive|define
name|FEC_TACC_REG
value|0x01c0
end_define

begin_define
define|#
directive|define
name|FEC_TACC_PROCHK
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|FEC_TACC_IPCHK
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|FEC_TACC_SHIFT16
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|FEC_RACC_REG
value|0x01c4
end_define

begin_define
define|#
directive|define
name|FEC_RACC_SHIFT16
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|FEC_RACC_LINEDIS
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|FEC_RACC_PRODIS
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|FEC_RACC_IPDIS
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|FEC_RACC_PADREM
value|(1<<  0)
end_define

begin_comment
comment|/*  * Statistics registers  */
end_comment

begin_define
define|#
directive|define
name|FEC_RMON_T_DROP
value|0x200
end_define

begin_define
define|#
directive|define
name|FEC_RMON_T_PACKETS
value|0x204
end_define

begin_define
define|#
directive|define
name|FEC_RMON_T_BC_PKT
value|0x208
end_define

begin_define
define|#
directive|define
name|FEC_RMON_T_MC_PKT
value|0x20C
end_define

begin_define
define|#
directive|define
name|FEC_RMON_T_CRC_ALIGN
value|0x210
end_define

begin_define
define|#
directive|define
name|FEC_RMON_T_UNDERSIZE
value|0x214
end_define

begin_define
define|#
directive|define
name|FEC_RMON_T_OVERSIZE
value|0x218
end_define

begin_define
define|#
directive|define
name|FEC_RMON_T_FRAG
value|0x21C
end_define

begin_define
define|#
directive|define
name|FEC_RMON_T_JAB
value|0x220
end_define

begin_define
define|#
directive|define
name|FEC_RMON_T_COL
value|0x224
end_define

begin_define
define|#
directive|define
name|FEC_RMON_T_P64
value|0x228
end_define

begin_define
define|#
directive|define
name|FEC_RMON_T_P65TO127
value|0x22C
end_define

begin_define
define|#
directive|define
name|FEC_RMON_T_P128TO255
value|0x230
end_define

begin_define
define|#
directive|define
name|FEC_RMON_T_P256TO511
value|0x234
end_define

begin_define
define|#
directive|define
name|FEC_RMON_T_P512TO1023
value|0x238
end_define

begin_define
define|#
directive|define
name|FEC_RMON_T_P1024TO2047
value|0x23C
end_define

begin_define
define|#
directive|define
name|FEC_RMON_T_P_GTE2048
value|0x240
end_define

begin_define
define|#
directive|define
name|FEC_RMON_T_OCTECTS
value|0x240
end_define

begin_define
define|#
directive|define
name|FEC_IEEE_T_DROP
value|0x248
end_define

begin_define
define|#
directive|define
name|FEC_IEEE_T_FRAME_OK
value|0x24C
end_define

begin_define
define|#
directive|define
name|FEC_IEEE_T_1COL
value|0x250
end_define

begin_define
define|#
directive|define
name|FEC_IEEE_T_MCOL
value|0x254
end_define

begin_define
define|#
directive|define
name|FEC_IEEE_T_DEF
value|0x258
end_define

begin_define
define|#
directive|define
name|FEC_IEEE_T_LCOL
value|0x25C
end_define

begin_define
define|#
directive|define
name|FEC_IEEE_T_EXCOL
value|0x260
end_define

begin_define
define|#
directive|define
name|FEC_IEEE_T_MACERR
value|0x264
end_define

begin_define
define|#
directive|define
name|FEC_IEEE_T_CSERR
value|0x268
end_define

begin_define
define|#
directive|define
name|FEC_IEEE_T_SQE
value|0x26C
end_define

begin_define
define|#
directive|define
name|FEC_IEEE_T_FDXFC
value|0x270
end_define

begin_define
define|#
directive|define
name|FEC_IEEE_T_OCTETS_OK
value|0x274
end_define

begin_define
define|#
directive|define
name|FEC_RMON_R_PACKETS
value|0x284
end_define

begin_define
define|#
directive|define
name|FEC_RMON_R_BC_PKT
value|0x288
end_define

begin_define
define|#
directive|define
name|FEC_RMON_R_MC_PKT
value|0x28C
end_define

begin_define
define|#
directive|define
name|FEC_RMON_R_CRC_ALIGN
value|0x290
end_define

begin_define
define|#
directive|define
name|FEC_RMON_R_UNDERSIZE
value|0x294
end_define

begin_define
define|#
directive|define
name|FEC_RMON_R_OVERSIZE
value|0x298
end_define

begin_define
define|#
directive|define
name|FEC_RMON_R_FRAG
value|0x29C
end_define

begin_define
define|#
directive|define
name|FEC_RMON_R_JAB
value|0x2A0
end_define

begin_define
define|#
directive|define
name|FEC_RMON_R_RESVD_0
value|0x2A4
end_define

begin_define
define|#
directive|define
name|FEC_RMON_R_P64
value|0x2A8
end_define

begin_define
define|#
directive|define
name|FEC_RMON_R_P65TO127
value|0x2AC
end_define

begin_define
define|#
directive|define
name|FEC_RMON_R_P128TO255
value|0x2B0
end_define

begin_define
define|#
directive|define
name|FEC_RMON_R_P256TO511
value|0x2B4
end_define

begin_define
define|#
directive|define
name|FEC_RMON_R_P512TO1023
value|0x2B8
end_define

begin_define
define|#
directive|define
name|FEC_RMON_R_P1024TO2047
value|0x2BC
end_define

begin_define
define|#
directive|define
name|FEC_RMON_R_P_GTE2048
value|0x2C0
end_define

begin_define
define|#
directive|define
name|FEC_RMON_R_OCTETS
value|0x2C4
end_define

begin_define
define|#
directive|define
name|FEC_IEEE_R_DROP
value|0x2C8
end_define

begin_define
define|#
directive|define
name|FEC_IEEE_R_FRAME_OK
value|0x2CC
end_define

begin_define
define|#
directive|define
name|FEC_IEEE_R_CRC
value|0x2D0
end_define

begin_define
define|#
directive|define
name|FEC_IEEE_R_ALIGN
value|0x2D4
end_define

begin_define
define|#
directive|define
name|FEC_IEEE_R_MACERR
value|0x2D8
end_define

begin_define
define|#
directive|define
name|FEC_IEEE_R_FDXFC
value|0x2DC
end_define

begin_define
define|#
directive|define
name|FEC_IEEE_R_OCTETS_OK
value|0x2E0
end_define

begin_define
define|#
directive|define
name|FEC_MIIGSK_CFGR
value|0x300
end_define

begin_define
define|#
directive|define
name|FEC_MIIGSK_CFGR_FRCONT
value|(1<< 6)
end_define

begin_comment
comment|/* Freq: 0=50MHz, 1=5MHz */
end_comment

begin_define
define|#
directive|define
name|FEC_MIIGSK_CFGR_LBMODE
value|(1<< 4)
end_define

begin_comment
comment|/* loopback mode */
end_comment

begin_define
define|#
directive|define
name|FEC_MIIGSK_CFGR_EMODE
value|(1<< 3)
end_define

begin_comment
comment|/* echo mode */
end_comment

begin_define
define|#
directive|define
name|FEC_MIIGSK_CFGR_IF_MODE_MASK
value|(0x3<< 0)
end_define

begin_define
define|#
directive|define
name|FEC_MIIGSK_CFGR_IF_MODE_MII
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|FEC_MIIGSK_CFGR_IF_MODE_RMII
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|FEC_MIIGSK_ENR
value|0x308
end_define

begin_define
define|#
directive|define
name|FEC_MIIGSK_ENR_READY
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|FEC_MIIGSK_ENR_EN
value|(1<< 1)
end_define

begin_comment
comment|/*  * A hardware buffer descriptor.  Rx and Tx buffers have the same descriptor  * layout, but the bits in the flags field have different meanings.  */
end_comment

begin_struct
struct|struct
name|ffec_hwdesc
block|{
name|uint32_t
name|flags_len
decl_stmt|;
name|uint32_t
name|buf_paddr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FEC_TXDESC_READY
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|FEC_TXDESC_T01
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|FEC_TXDESC_WRAP
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|FEC_TXDESC_T02
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|FEC_TXDESC_L
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|FEC_TXDESC_TC
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|FEC_TXDESC_ABC
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|FEC_TXDESC_LEN_MASK
value|(0xffff)
end_define

begin_define
define|#
directive|define
name|FEC_RXDESC_EMPTY
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|FEC_RXDESC_R01
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|FEC_RXDESC_WRAP
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|FEC_RXDESC_R02
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|FEC_RXDESC_L
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|FEC_RXDESC_M
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|FEC_RXDESC_BC
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|FEC_RXDESC_MC
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|FEC_RXDESC_LG
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|FEC_RXDESC_NO
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|FEC_RXDESC_CR
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|FEC_RXDESC_OV
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|FEC_RXDESC_TR
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|FEC_RXDESC_LEN_MASK
value|(0xffff)
end_define

begin_define
define|#
directive|define
name|FEC_RXDESC_ERROR_BITS
value|(FEC_RXDESC_LG | FEC_RXDESC_NO | \     FEC_RXDESC_OV | FEC_RXDESC_TR)
end_define

begin_comment
comment|/*  * The hardware imposes alignment restrictions on various objects involved in  * DMA transfers.  These values are expressed in bytes (not bits).  */
end_comment

begin_define
define|#
directive|define
name|FEC_DESC_RING_ALIGN
value|16
end_define

begin_define
define|#
directive|define
name|FEC_RXBUF_ALIGN
value|16
end_define

begin_define
define|#
directive|define
name|FEC_TXBUF_ALIGN
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IF_FFECREG_H */
end_comment

end_unit

