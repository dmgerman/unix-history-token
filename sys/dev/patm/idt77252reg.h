begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $FreeBSD$  *  * Register definitions for the IDT77252 chip.  */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_IDT
value|0x111D
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_IDT77252
value|3
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_IDT77v252
value|4
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_IDT77v222
value|5
end_define

begin_define
define|#
directive|define
name|IDT_PCI_REG_MEMBASE
value|0x14
end_define

begin_define
define|#
directive|define
name|IDT_NOR_D0
value|0x00
end_define

begin_comment
comment|/* R/W Data register 0 */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_D1
value|0x04
end_define

begin_comment
comment|/* R/W Data register 1 */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_D2
value|0x08
end_define

begin_comment
comment|/* R/W Data register 2 */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_D3
value|0x0C
end_define

begin_comment
comment|/* R/W Data register 3 */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_CMD
value|0x10
end_define

begin_comment
comment|/* R/W Command */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_CFG
value|0x14
end_define

begin_comment
comment|/* R/W Configuration */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_STAT
value|0x18
end_define

begin_comment
comment|/* R/W Status */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_RSQB
value|0x1C
end_define

begin_comment
comment|/* R/W Receive status queue base */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_RSQT
value|0x20
end_define

begin_comment
comment|/* R   Receive status queue tail */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_RSQH
value|0x24
end_define

begin_comment
comment|/* R/W Receive status queue tail */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_CDC
value|0x28
end_define

begin_comment
comment|/* R/W Cell drop counter */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_VPEC
value|0x2C
end_define

begin_comment
comment|/* R/W VPI/VCI Lookup error counter */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_ICC
value|0x30
end_define

begin_comment
comment|/* R/W Invalid cell counter */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_RAWCT
value|0x34
end_define

begin_comment
comment|/* R   Raw cell tail */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_TMR
value|0x38
end_define

begin_comment
comment|/* R   Timer */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_TSTB
value|0x3C
end_define

begin_comment
comment|/* R/W Transmit schedule table base */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_TSQB
value|0x40
end_define

begin_comment
comment|/* R/W Transmit Status queue base */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_TSQT
value|0x44
end_define

begin_comment
comment|/* R/W Transmit Status queue tail */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_TSQH
value|0x48
end_define

begin_comment
comment|/* R/W Transmit Status queue head */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_GP
value|0x4C
end_define

begin_comment
comment|/* R/W General purpose */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_VPM
value|0x50
end_define

begin_comment
comment|/* R/W VPI/VCI mask */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_RXFD
value|0x54
end_define

begin_comment
comment|/* R/W Receive FIFO descriptor */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_RXFT
value|0x58
end_define

begin_comment
comment|/* R/W Receive FIFO tail */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_RXFH
value|0x5C
end_define

begin_comment
comment|/* R/W Receive FIFO head */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_RAWHND
value|0x60
end_define

begin_comment
comment|/* R/W Raw cell handle */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_RXSTAT
value|0x64
end_define

begin_comment
comment|/* R   Receive connection state */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_ABRSTD
value|0x68
end_define

begin_comment
comment|/* R/W ABR& VBR Schedule table descriptor */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_ABRRQ
value|0x6C
end_define

begin_comment
comment|/* R/W ABR Ready queue pointer */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_VBRRQ
value|0x70
end_define

begin_comment
comment|/* R/W VBR Ready queue pointer */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_RTBL
value|0x74
end_define

begin_comment
comment|/* R/W Rate table descriptor */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_MXDFCT
value|0x78
end_define

begin_comment
comment|/* R/W Maximum deficit counter */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_TXSTAT
value|0x7C
end_define

begin_comment
comment|/* R/W Transmit connection state */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_TCMDQ
value|0x80
end_define

begin_comment
comment|/*   W Transmit command queue */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_IRCP
value|0x84
end_define

begin_comment
comment|/* R/W Inactive receive connection pointer */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_FBQP0
value|0x88
end_define

begin_comment
comment|/* R/W Free buffer queue 0 pointer */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_FBQP1
value|0x8C
end_define

begin_comment
comment|/* R/W Free buffer queue 1 pointer */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_FBQP2
value|0x90
end_define

begin_comment
comment|/* R/W Free buffer queue 2 pointer */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_FBQP3
value|0x94
end_define

begin_comment
comment|/* R/W Free buffer queue 3 pointer */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_FBQS0
value|0x98
end_define

begin_comment
comment|/* R/W Free buffer queue 0 size */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_FBQS1
value|0x9C
end_define

begin_comment
comment|/* R/W Free buffer queue 1 size */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_FBQS2
value|0xA0
end_define

begin_comment
comment|/* R/W Free buffer queue 2 size */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_FBQS3
value|0xA4
end_define

begin_comment
comment|/* R/W Free buffer queue 3 size */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_FBQWP0
value|0xA8
end_define

begin_comment
comment|/* R/W Free buffer queue 0 write pointer */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_FBQWP1
value|0xAC
end_define

begin_comment
comment|/* R/W Free buffer queue 1 write pointer */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_FBQWP2
value|0xB0
end_define

begin_comment
comment|/* R/W Free buffer queue 2 write pointer */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_FBQWP3
value|0xB4
end_define

begin_comment
comment|/* R/W Free buffer queue 3 write pointer */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_NOW
value|0xB8
end_define

begin_comment
comment|/* R   Current transmit schedule table addr */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_DNOW
value|0xBC
end_define

begin_comment
comment|/* R   Dynamic Now register */
end_comment

begin_define
define|#
directive|define
name|IDT_NOR_END
value|0xC0
end_define

begin_comment
comment|/*  * Command (IDT_NOR_CMD)  */
end_comment

begin_define
define|#
directive|define
name|IDT_CMD_NOP
value|0x00000000
end_define

begin_comment
comment|/* No operation */
end_comment

begin_define
define|#
directive|define
name|IDT_CMD_OPCL
value|0x20000000
end_define

begin_comment
comment|/* Open/Close connection */
end_comment

begin_define
define|#
directive|define
name|IDT_CMD_WSRAM
value|0x40000000
end_define

begin_comment
comment|/* Write SRAM */
end_comment

begin_define
define|#
directive|define
name|IDT_CMD_RSRAM
value|0x50000000
end_define

begin_comment
comment|/* Read SRAM */
end_comment

begin_define
define|#
directive|define
name|IDT_CMD_WFBQ
value|0x60000000
end_define

begin_comment
comment|/* Write free buffer queue */
end_comment

begin_define
define|#
directive|define
name|IDT_CMD_RUTIL
value|0x80000000
end_define

begin_comment
comment|/* Read utility bus */
end_comment

begin_define
define|#
directive|define
name|IDT_CMD_WUTIL
value|0x90000000
end_define

begin_comment
comment|/* Write utility bus */
end_comment

begin_define
define|#
directive|define
name|IDT_MKCMD_OPEN
parameter_list|(
name|VC
parameter_list|)
value|(IDT_CMD_OPCL | (1<< 19) | ((V)<< 4))
end_define

begin_define
define|#
directive|define
name|IDT_MKCMD_CLOSE
parameter_list|(
name|VC
parameter_list|)
value|(IDT_CMD_OPCL | (0<< 19) | ((V)<< 4))
end_define

begin_define
define|#
directive|define
name|IDT_MKCMD_WSRAM
parameter_list|(
name|A
parameter_list|,
name|S
parameter_list|)
value|(IDT_CMD_WSRAM | ((A)<< 2) | (S))
end_define

begin_define
define|#
directive|define
name|IDT_MKCMD_RSRAM
parameter_list|(
name|A
parameter_list|)
value|(IDT_CMD_RSRAM | ((A)<< 2))
end_define

begin_define
define|#
directive|define
name|IDT_MKCMD_WFBQ
parameter_list|(
name|Q
parameter_list|)
value|(IDT_CMD_WFBQ | (Q))
end_define

begin_define
define|#
directive|define
name|IDT_MKCMD_RUTIL
parameter_list|(
name|S0
parameter_list|,
name|S1
parameter_list|,
name|A
parameter_list|)
define|\
value|(IDT_CMD_RUTIL | ((S1)<< 9) | ((S0)<< 8) | (A))
end_define

begin_define
define|#
directive|define
name|IDT_MKCMD_WUTIL
parameter_list|(
name|S0
parameter_list|,
name|S1
parameter_list|,
name|A
parameter_list|)
define|\
value|(IDT_CMD_WUTIL | ((S1)<< 9) | ((S0)<< 8) | (A))
end_define

begin_comment
comment|/*  * Configuration register (CFG)  */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_SWRST
value|0x80000000
end_define

begin_comment
comment|/* software reset */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_LOOP
value|0x40000000
end_define

begin_comment
comment|/* internal loopback enable */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_RXPTH
value|0x20000000
end_define

begin_comment
comment|/* receive path enable */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_IDLECLP
value|0x10000000
end_define

begin_comment
comment|/* set CLP in null cells */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_TXFIFO9
value|0x00000000
end_define

begin_comment
comment|/* Tx FIFO 9 cells */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_TXFIFO1
value|0x04000000
end_define

begin_comment
comment|/* Tx FIFO 1 cells */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_TXFIFO2
value|0x08000000
end_define

begin_comment
comment|/* Tx FIFO 2 cells */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_TXFIFO4
value|0x0C000000
end_define

begin_comment
comment|/* Tx FIFO 4 cells */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_NOIDLE
value|0x02000000
end_define

begin_comment
comment|/* don't send idle cells */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_RXQ128
value|0x00000000
end_define

begin_comment
comment|/* Rx Status Queue 128 entries */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_RXQ256
value|0x00400000
end_define

begin_comment
comment|/* Rx Status Queue 256 entries */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_RXQ512
value|0x00800000
end_define

begin_comment
comment|/* Rx Status Queue 512 entries */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_ICAPT
value|0x00200000
end_define

begin_comment
comment|/* Invalid cell accept */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_IGGFC
value|0x00100000
end_define

begin_comment
comment|/* Ignore GFC field */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_VP0
value|0x00000000
end_define

begin_comment
comment|/* 0 VPI bits */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_VP1
value|0x00040000
end_define

begin_comment
comment|/* 1 VPI bit */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_VP2
value|0x00080000
end_define

begin_comment
comment|/* 2 VPI bits */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_VP8
value|0x000C0000
end_define

begin_comment
comment|/* 8 VPI bits */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_CTS1K
value|0x00000000
end_define

begin_comment
comment|/* Rx Connection table 1024 entries */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_CTS4K
value|0x00010000
end_define

begin_comment
comment|/* Rx Connection table 4096 entries */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_CTS16K
value|0x00020000
end_define

begin_comment
comment|/* Rx Connection table 16384 entries */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_CTS512
value|0x00030000
end_define

begin_comment
comment|/* Rx Connection table 512 entries */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_VPECA
value|0x00008000
end_define

begin_comment
comment|/* VPI/VCI error cell accept */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_RXINONE
value|0x00000000
end_define

begin_comment
comment|/* No interrupt on receive */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_RXIIMM
value|0x00001000
end_define

begin_comment
comment|/* immediate interrupt */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_RXI28
value|0x00002000
end_define

begin_comment
comment|/* every 0x2800 clocks */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_RXI4F
value|0x00003000
end_define

begin_comment
comment|/* every 0x4F00 clocks */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_RXI74
value|0x00004000
end_define

begin_comment
comment|/* every 0x7400 clocks */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_RAWIE
value|0x00000800
end_define

begin_comment
comment|/* raw cell queue interrupt enable */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_RQFIE
value|0x00000400
end_define

begin_comment
comment|/* Rx status queue almost full IE */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_CACHE
value|0x00000100
end_define

begin_comment
comment|/* begin DMA on cache line */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_TIMOIE
value|0x00000080
end_define

begin_comment
comment|/* timer roll over interrupt enable */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_FBIE
value|0x00000040
end_define

begin_comment
comment|/* free buffer queue interrupt enable */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_TXENB
value|0x00000020
end_define

begin_comment
comment|/* Tx enable */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_TXINT
value|0x00000010
end_define

begin_comment
comment|/* Tx status interrupt enable */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_TXUIE
value|0x00000008
end_define

begin_comment
comment|/* Tx underrun interrupt enable */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_UMODE
value|0x00000004
end_define

begin_comment
comment|/* utopia byte mode */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_TXSFI
value|0x00000002
end_define

begin_comment
comment|/* Tx status full interrupt enable */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_PHYIE
value|0x00000001
end_define

begin_comment
comment|/* PHY interrupt enable */
end_comment

begin_comment
comment|/*  * Status register (STAT)  */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_FRAC3
parameter_list|(
name|S
parameter_list|)
value|(((S)>> 28)& 0xf)
end_define

begin_comment
comment|/* FBQ3 valid */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_FRAC2
parameter_list|(
name|S
parameter_list|)
value|(((S)>> 24)& 0xf)
end_define

begin_comment
comment|/* FBQ2 valid */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_FRAC1
parameter_list|(
name|S
parameter_list|)
value|(((S)>> 20)& 0xf)
end_define

begin_comment
comment|/* FBQ1 valid */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_FRAC0
parameter_list|(
name|S
parameter_list|)
value|(((S)>> 16)& 0xf)
end_define

begin_comment
comment|/* FBQ0 valid */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_TSIF
value|0x00008000
end_define

begin_comment
comment|/* Tx status indicator flag */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_TXICP
value|0x00004000
end_define

begin_comment
comment|/* Tx incomplete PDU */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_TSQF
value|0x00001000
end_define

begin_comment
comment|/* Tx status queue full */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_TMROF
value|0x00000800
end_define

begin_comment
comment|/* Timer overflow */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_PHYI
value|0x00000400
end_define

begin_comment
comment|/* PHY interrupt */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_CMDBZ
value|0x00000200
end_define

begin_comment
comment|/* command busy */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_FBQ3A
value|0x00000100
end_define

begin_comment
comment|/* FBQ 3 attention flag */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_FBQ2A
value|0x00000080
end_define

begin_comment
comment|/* FBQ 2 attention flag */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_RSQF
value|0x00000040
end_define

begin_comment
comment|/* Rx status queue full */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_EPDU
value|0x00000020
end_define

begin_comment
comment|/* end of CS-PDU */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_RAWCF
value|0x00000010
end_define

begin_comment
comment|/* raw cell flag */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_FBQ1A
value|0x00000008
end_define

begin_comment
comment|/* FBQ 1 attention flag */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_FBQ0A
value|0x00000004
end_define

begin_comment
comment|/* FBQ 0 attention flag */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_RSQAF
value|0x00000002
end_define

begin_comment
comment|/* Rx status queue almost full */
end_comment

begin_comment
comment|/*  * Cell drop count (CDC)  */
end_comment

begin_define
define|#
directive|define
name|IDT_CDC_RMID
value|0x00400000
end_define

begin_comment
comment|/* RM cell ID error */
end_comment

begin_define
define|#
directive|define
name|IDT_CDC_CTE
value|0x00200000
end_define

begin_comment
comment|/* Rx connection table error */
end_comment

begin_define
define|#
directive|define
name|IDT_CDC_NFB
value|0x00100000
end_define

begin_comment
comment|/* No free buffers */
end_comment

begin_define
define|#
directive|define
name|IDT_CDC_OAMCRC
value|0x00080000
end_define

begin_comment
comment|/* bad OAM CRC */
end_comment

begin_define
define|#
directive|define
name|IDT_CDC_RMCRC
value|0x00040000
end_define

begin_comment
comment|/* bad RM CRC */
end_comment

begin_define
define|#
directive|define
name|IDT_CDC_RMFIFO
value|0x00020000
end_define

begin_comment
comment|/* RM FIFO full */
end_comment

begin_define
define|#
directive|define
name|IDT_CDC_RXFIFO
value|0x00010000
end_define

begin_comment
comment|/* Rx FIFO full */
end_comment

begin_define
define|#
directive|define
name|IDT_CDC
parameter_list|(
name|S
parameter_list|)
value|((S)& 0xffff)
end_define

begin_comment
comment|/* cell drop counter */
end_comment

begin_comment
comment|/*  * VPI/VCI lookup error count (VPEC)  */
end_comment

begin_define
define|#
directive|define
name|IDT_VPEC
parameter_list|(
name|S
parameter_list|)
value|((S)& 0xffff)
end_define

begin_comment
comment|/*  * Invalid cell count (ICC)  */
end_comment

begin_define
define|#
directive|define
name|IDT_ICC
parameter_list|(
name|S
parameter_list|)
value|((S)& 0xffff)
end_define

begin_comment
comment|/*  * General purpose register  */
end_comment

begin_define
define|#
directive|define
name|IDT_GP_TXNCC
parameter_list|(
name|S
parameter_list|)
value|(((S)>> 24)& 0xff)
end_define

begin_comment
comment|/* Tx negative cell count */
end_comment

begin_define
define|#
directive|define
name|IDT_GP_EEDI
value|0x00010000
end_define

begin_comment
comment|/* EEPROM data in */
end_comment

begin_define
define|#
directive|define
name|IDT_GP_BIGE
value|0x00008000
end_define

begin_comment
comment|/* big endian enable */
end_comment

begin_define
define|#
directive|define
name|IDT_GP_RM
value|0x00000000
end_define

begin_comment
comment|/* process RM cells */
end_comment

begin_define
define|#
directive|define
name|IDT_GP_RM_TEE
value|0x00002000
end_define

begin_comment
comment|/* process RM cells and put in RawQ */
end_comment

begin_define
define|#
directive|define
name|IDT_GP_RM_RAW
value|0x00006000
end_define

begin_comment
comment|/* put RM cells in RawQ */
end_comment

begin_define
define|#
directive|define
name|IDT_GP_DLOOP
value|0x00001000
end_define

begin_comment
comment|/* double loopback */
end_comment

begin_define
define|#
directive|define
name|IDT_GP_PCIPAR
value|0x00000010
end_define

begin_comment
comment|/* force PCI parity error */
end_comment

begin_define
define|#
directive|define
name|IDT_GP_PCIPERR
value|0x00000020
end_define

begin_comment
comment|/* force PERR */
end_comment

begin_define
define|#
directive|define
name|IDT_GP_PCISERR
value|0x00000040
end_define

begin_comment
comment|/* force SERR */
end_comment

begin_define
define|#
directive|define
name|IDT_GP_PHY_RST
value|0x00000008
end_define

begin_comment
comment|/* PHY reset */
end_comment

begin_define
define|#
directive|define
name|IDT_GP_EESCLK
value|0x00000004
end_define

begin_comment
comment|/* EEPROM clock */
end_comment

begin_define
define|#
directive|define
name|IDT_GP_EECS
value|0x00000002
end_define

begin_comment
comment|/* EEPROM chip select */
end_comment

begin_define
define|#
directive|define
name|IDT_GP_EEDO
value|0x00000001
end_define

begin_comment
comment|/* EEPROM data out */
end_comment

begin_comment
comment|/*  * Receive FIFO descriptor register (RXFD)  */
end_comment

begin_define
define|#
directive|define
name|IDT_RXFD
parameter_list|(
name|A
parameter_list|,
name|S
parameter_list|)
value|(((S)<< 24) | ((A)<< 2))
end_define

begin_define
define|#
directive|define
name|IDT_RXFDS
parameter_list|(
name|V
parameter_list|)
value|(((V)>> 24)& 0xf)
end_define

begin_define
define|#
directive|define
name|IDT_RXFDA
parameter_list|(
name|V
parameter_list|)
value|(((V)& 0x1ffffc)>> 2)
end_define

begin_comment
comment|/*  * ABR& VBR schedule table descriptor register  */
end_comment

begin_define
define|#
directive|define
name|IDT_ABRSTD
parameter_list|(
name|A
parameter_list|,
name|S
parameter_list|)
value|(((S)<< 24) | ((A)<< 2))
end_define

begin_define
define|#
directive|define
name|IDT_ABRSTDS
parameter_list|(
name|V
parameter_list|)
value|(((V)>> 24)& 0x7)
end_define

begin_define
define|#
directive|define
name|IDT_ABRSTDA
parameter_list|(
name|V
parameter_list|)
value|(((V)& 0x1ffffc)>> 2)
end_define

begin_comment
comment|/*  * ABR/VBR ready queue register  */
end_comment

begin_define
define|#
directive|define
name|IDT_ABRRQH
parameter_list|(
name|V
parameter_list|)
value|(((V)>> 16)& 0x3fff)
end_define

begin_define
define|#
directive|define
name|IDT_ABRRQT
parameter_list|(
name|V
parameter_list|)
value|(((V)>>  0)& 0x3fff)
end_define

begin_define
define|#
directive|define
name|IDT_VBRRQH
parameter_list|(
name|V
parameter_list|)
value|(((V)>> 16)& 0x3fff)
end_define

begin_define
define|#
directive|define
name|IDT_VBRRQT
parameter_list|(
name|V
parameter_list|)
value|(((V)>>  0)& 0x3fff)
end_define

begin_comment
comment|/*  * Maximum deficit limit register  */
end_comment

begin_define
define|#
directive|define
name|IDT_MDFCT_LCI
value|0x00020000
end_define

begin_comment
comment|/* local congestion indicator enable */
end_comment

begin_define
define|#
directive|define
name|IDT_MDFCT_LNI
value|0x00010000
end_define

begin_comment
comment|/* local no incread enable */
end_comment

begin_comment
comment|/*  * Transmit command queue register  */
end_comment

begin_define
define|#
directive|define
name|IDT_TCMDQ_NOP
parameter_list|()
value|((0x0<< 24))
end_define

begin_comment
comment|/* no operation */
end_comment

begin_define
define|#
directive|define
name|IDT_TCMDQ_START
parameter_list|(
name|C
parameter_list|)
value|((0x1<< 24) | (C))
end_define

begin_comment
comment|/* start connection */
end_comment

begin_define
define|#
directive|define
name|IDT_TCMDQ_ULACR
parameter_list|(
name|C
parameter_list|,
name|L
parameter_list|)
value|((0x2<< 24) | (C) | ((L)<< 16))
end_define

begin_comment
comment|/* update LACR */
end_comment

begin_define
define|#
directive|define
name|IDT_TCMDQ_SLACR
parameter_list|(
name|C
parameter_list|,
name|L
parameter_list|)
value|((0x3<< 24) | (C) | ((L)<< 16))
end_define

begin_comment
comment|/* start and update LACR */
end_comment

begin_define
define|#
directive|define
name|IDT_TCMDQ_UIER
parameter_list|(
name|C
parameter_list|,
name|L
parameter_list|)
value|((0x4<< 24) | (C) | ((L)<< 16))
end_define

begin_comment
comment|/* update Int ER */
end_comment

begin_define
define|#
directive|define
name|IDT_TCMDQ_HALT
parameter_list|(
name|C
parameter_list|)
value|((0x5<< 24) | (C))
end_define

begin_comment
comment|/* halt connection */
end_comment

begin_comment
comment|/*  * Free buffer queue size registers  */
end_comment

begin_define
define|#
directive|define
name|IDT_FBQS
parameter_list|(
name|T
parameter_list|,
name|N
parameter_list|,
name|C
parameter_list|,
name|S
parameter_list|)
value|(((T)<< 28) | ((N)<< 24) | ((C)<< 20) | (S))
end_define

begin_comment
comment|/*  * Receive status queue  */
end_comment

begin_struct
struct|struct
name|idt_rsqe
block|{
name|uint32_t
name|cid
decl_stmt|;
comment|/* VPI/VCI */
name|uint32_t
name|handle
decl_stmt|;
comment|/* buffer handle */
name|uint32_t
name|crc
decl_stmt|;
comment|/* AAL-5 CRC */
name|uint32_t
name|stat
decl_stmt|;
comment|/* div. flags */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IDT_RSQE_SIZE
value|16
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|IDT_RSQE_VPI
parameter_list|(
name|CID
parameter_list|)
value|(((CID)>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_VCI
parameter_list|(
name|CID
parameter_list|)
value|((CID)& 0xffff)
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_TYPE
parameter_list|(
name|S
parameter_list|)
value|(((S)>> 30)& 0x3)
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_DATA
value|0x2
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_IDLE
value|0x3
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_VALID
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_POOL
parameter_list|(
name|S
parameter_list|)
value|(((S)>> 16)& 0x3)
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_BUF
value|0x8000
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_NZGFC
value|0x4000
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_EPDU
value|0x2000
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_CBUF
value|0x1000
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_EFCIE
value|0x0800
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_CLP
value|0x0400
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_CRC
value|0x0200
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_CNT
parameter_list|(
name|S
parameter_list|)
value|((S)& 0x1ff)
end_define

begin_define
define|#
directive|define
name|IDT_RSQH
parameter_list|(
name|R
parameter_list|)
value|(((R)& 0x1ffc)>> 2)
end_define

begin_define
define|#
directive|define
name|IDT_RSQT
parameter_list|(
name|R
parameter_list|)
value|(((R)& 0x1ffc)>> 2)
end_define

begin_comment
comment|/*  * Transmit status queue  */
end_comment

begin_define
define|#
directive|define
name|IDT_TSQ_SIZE
value|1024
end_define

begin_comment
comment|/* no. of entries */
end_comment

begin_define
define|#
directive|define
name|IDT_TSQE_SIZE
value|8
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|IDT_TSQE_SHIFT
value|3
end_define

begin_struct
struct|struct
name|idt_tsqe
block|{
name|uint32_t
name|stat
decl_stmt|;
name|uint32_t
name|stamp
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IDT_TSQE_EMPTY
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IDT_TSQE_TYPE
parameter_list|(
name|E
parameter_list|)
value|(((E)>> 29)& 0x3)
end_define

begin_define
define|#
directive|define
name|IDT_TSQE_TIMER
value|0x0
end_define

begin_define
define|#
directive|define
name|IDT_TSQE_TSR
value|0x1
end_define

begin_define
define|#
directive|define
name|IDT_TSQE_IDLE
value|0x2
end_define

begin_define
define|#
directive|define
name|IDT_TSQE_TBD
value|0x3
end_define

begin_define
define|#
directive|define
name|IDT_TSQE_TAG
parameter_list|(
name|E
parameter_list|)
value|(((E)>> 24)& 0x1f)
end_define

begin_define
define|#
directive|define
name|IDT_TSQE_HALTED
value|0x10
end_define

begin_define
define|#
directive|define
name|IDT_TSQE_STAMP
parameter_list|(
name|E
parameter_list|)
value|((E)& 0xffffff)
end_define

begin_define
define|#
directive|define
name|IDT_TSQE_TAG_SPACE
value|32
end_define

begin_comment
comment|/*  * Raw cell handle  */
end_comment

begin_struct
struct|struct
name|idt_rawhnd
block|{
name|uint32_t
name|tail
decl_stmt|;
name|uint32_t
name|handle
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IDT_RAWHND_SIZE
value|8
end_define

begin_comment
comment|/*  * TST  */
end_comment

begin_define
define|#
directive|define
name|IDT_TST_NULL
value|(0<< 29)
end_define

begin_comment
comment|/* transmit NULL cell */
end_comment

begin_define
define|#
directive|define
name|IDT_TST_CBR
value|(1<< 29)
end_define

begin_comment
comment|/* transmit CBR cell */
end_comment

begin_define
define|#
directive|define
name|IDT_TST_VBR
value|(2<< 29)
end_define

begin_comment
comment|/* transmit [AVU]BR cell */
end_comment

begin_define
define|#
directive|define
name|IDT_TST_BR
value|(3<< 29)
end_define

begin_comment
comment|/* branch */
end_comment

begin_define
define|#
directive|define
name|IDT_TST_MASK
value|0x7ffff
end_define

begin_comment
comment|/*  * Free buffer queue  */
end_comment

begin_define
define|#
directive|define
name|IDT_FBQ_SIZE
value|512
end_define

begin_comment
comment|/* entries */
end_comment

begin_comment
comment|/*  * Receive connection table  */
end_comment

begin_define
define|#
directive|define
name|IDT_RCT_FBP2
value|0x00400000
end_define

begin_comment
comment|/* use FBQ 2 */
end_comment

begin_define
define|#
directive|define
name|IDT_RCT_OPEN
value|0x00080000
end_define

begin_comment
comment|/* connection open */
end_comment

begin_define
define|#
directive|define
name|IDT_RCT_AAL0
value|0x00000000
end_define

begin_comment
comment|/* AAL 0 */
end_comment

begin_define
define|#
directive|define
name|IDT_RCT_AAL34
value|0x00010000
end_define

begin_comment
comment|/* AAL 3/4 */
end_comment

begin_define
define|#
directive|define
name|IDT_RCT_AAL5
value|0x00020000
end_define

begin_comment
comment|/* AAL 5 */
end_comment

begin_define
define|#
directive|define
name|IDT_RCT_AALRAW
value|0x00030000
end_define

begin_comment
comment|/* raw cells */
end_comment

begin_define
define|#
directive|define
name|IDT_RCT_AALOAM
value|0x00040000
end_define

begin_comment
comment|/* OAM cells */
end_comment

begin_define
define|#
directive|define
name|IDT_RCT_RCI
value|0x00008000
end_define

begin_comment
comment|/* raw cell interrupt enable */
end_comment

begin_define
define|#
directive|define
name|IDT_RCT_IACT_CNT_MASK
value|0x1c000000
end_define

begin_define
define|#
directive|define
name|IDT_RCT_IACT_CNT_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|IDT_RCT_ENTRY_SIZE
value|4
end_define

begin_comment
comment|/* words */
end_comment

begin_comment
comment|/*  * Transmit connection table  */
end_comment

begin_define
define|#
directive|define
name|IDT_TCT_CBR
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IDT_TCT_VBR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IDT_TCT_ABR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IDT_TCT_UBR
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IDT_TCT_UBR_FLG
value|0x80000000
end_define

begin_comment
comment|/* word8 flag */
end_comment

begin_define
define|#
directive|define
name|IDT_TCT_HALT
value|0x80000000
end_define

begin_comment
comment|/* connection halted */
end_comment

begin_define
define|#
directive|define
name|IDT_TCT_IDLE
value|0x40000000
end_define

begin_comment
comment|/* connection idle */
end_comment

begin_define
define|#
directive|define
name|IDT_TCT_TSIF
value|0x00004000
end_define

begin_define
define|#
directive|define
name|IDT_TCT_MAXIDLE
value|0x7f000000
end_define

begin_define
define|#
directive|define
name|IDT_TCT_MBS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IDT_TCT_CRM_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|IDT_TCT_NAGE_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|IDT_TCT_LMCR_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|IDT_TCT_CDF_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|IDT_TCT_RDF_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|IDT_TCT_AIR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|IDT_TCT_ACRI_SHIFT
value|16
end_define

begin_comment
comment|/*  * Segmentation channel queue  */
end_comment

begin_define
define|#
directive|define
name|IDT_SCQ_SIZE
value|64
end_define

begin_comment
comment|/* number of entries */
end_comment

begin_struct
struct|struct
name|idt_tbd
block|{
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|aal5
decl_stmt|;
name|uint32_t
name|hdr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IDT_TBD_SIZE
value|16
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|IDT_TBD_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|IDT_TBD_TSR
value|0x80000000
end_define

begin_comment
comment|/* TSR entry */
end_comment

begin_define
define|#
directive|define
name|IDT_TBD_EPDU
value|0x40000000
end_define

begin_comment
comment|/* end of AAL PDU */
end_comment

begin_define
define|#
directive|define
name|IDT_TBD_TSIF
value|0x20000000
end_define

begin_comment
comment|/* generate status */
end_comment

begin_define
define|#
directive|define
name|IDT_TBD_AAL0
value|0x00000000
end_define

begin_comment
comment|/* AAL0 */
end_comment

begin_define
define|#
directive|define
name|IDT_TBD_AAL34
value|0x04000000
end_define

begin_comment
comment|/* AAL3/4 */
end_comment

begin_define
define|#
directive|define
name|IDT_TBD_AAL5
value|0x08000000
end_define

begin_comment
comment|/* AAL5 */
end_comment

begin_define
define|#
directive|define
name|IDT_TBD_AALOAM
value|0x10000000
end_define

begin_comment
comment|/* OAM cells */
end_comment

begin_define
define|#
directive|define
name|IDT_TBD_GTSI
value|0x02000000
end_define

begin_comment
comment|/* generate transmit status entry */
end_comment

begin_define
define|#
directive|define
name|IDT_TBD_TAG_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|IDT_TBD_HDR
parameter_list|(
name|VPI
parameter_list|,
name|VCI
parameter_list|,
name|PTI
parameter_list|,
name|CLP
parameter_list|)
define|\
value|(((VPI)<< 20) | ((VCI)<< 4) | ((PTI)<< 1) | (CLP))
end_define

begin_define
define|#
directive|define
name|IDT_TBD_VPI
parameter_list|(
name|H
parameter_list|)
value|(((H)>> 20)& 0xff)
end_define

begin_define
define|#
directive|define
name|IDT_TBD_VCI
parameter_list|(
name|H
parameter_list|)
value|(((H)>> 4)& 0xffff)
end_define

begin_comment
comment|/*  * Segmentation channel descriptor  */
end_comment

begin_define
define|#
directive|define
name|IDT_SCD_SIZE
value|12
end_define

begin_comment
comment|/* words */
end_comment

begin_comment
comment|/*  * Memory map for the different RAM sizes  *  *		16k		32k		128k		512k  *  * TxCT		0x00000/4k	0x00000/8x	0x00000/32k	0x00000/128k  * RxCT		0x01000/2k	0x02000/4k	0x08000/16k	0x20000/64k  * FBQ0		0x01800/1k	0x03000/1k	0x0c000/1k	0x30000/1k  * FBQ1		0x01c00/1k	0x03400/1k	0x0c400/1k	0x30400/1k  * FBQ2		0x02000/1k	0x03800/1k	0x0c800/1k	0x30800/1k  * FBQ3		-		-		-		-  * RT		0x02400/4.5k	0x03c00/4.5k	0x0cc00/4.5k	0x30c00/4.5k  * SCD		0x03600/597	0x04e00/1621	0x0de00/9358	0x31e00/43036  * TST		0x06000/2x2k	0x0c000/2x4k	0x37000/2x8k	0xef000/2x16k  * ABR ST	0x07000/2x1k	0x0e000/2x2k	0x3b000/2x8k	0xf7000/2x16k  * RxFIFO	0x07800/2k	0x0f000/4k	0x3f000/4k	0xff000/4k  * End		0x08000		0x10000		0x40000		0x100000  */
end_comment

begin_struct
struct|struct
name|idt_mmap
block|{
name|u_int
name|sram
decl_stmt|;
comment|/* K SRAM */
name|u_int
name|max_conn
decl_stmt|;
comment|/* connections */
name|u_int
name|vcbits
decl_stmt|;
comment|/* VPI + VCI bits */
name|u_int
name|rxtab
decl_stmt|;
comment|/* CFG word for CNTBL field */
name|u_int
name|rct
decl_stmt|;
comment|/* RCT base */
name|u_int
name|rtables
decl_stmt|;
comment|/* rate table address */
name|u_int
name|scd_base
decl_stmt|;
comment|/* SCD area base address */
name|u_int
name|scd_num
decl_stmt|;
comment|/* number of SCDs */
name|u_int
name|tst1base
decl_stmt|;
comment|/* base address of TST 1 */
name|u_int
name|tst_size
decl_stmt|;
comment|/* TST size in words */
name|u_int
name|abrstd_addr
decl_stmt|;
comment|/* schedule table address */
name|u_int
name|abrstd_size
decl_stmt|;
comment|/* schedule table size */
name|u_int
name|abrstd_code
decl_stmt|;
comment|/* schedule table size */
name|u_int
name|rxfifo_addr
decl_stmt|;
comment|/* address */
name|u_int
name|rxfifo_size
decl_stmt|;
comment|/* in words */
name|u_int
name|rxfifo_code
decl_stmt|;
comment|/* size */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IDT_MMAP
value|{							\ 	{
comment|/* 16k x 32, 512 connections */
value|\ 	  16, 512, 9, IDT_CFG_CTS512,
comment|/* RAM, connections, VC bits */
value|\ 	  0x01000,
comment|/* RCT base */
value|\ 	  0x02400,
comment|/* rate table address */
value|\ 	  0x03600, 597,
comment|/* SCD base and num */
value|\ 	  0x06000, 2048,
comment|/* TST/words, base */
value|\ 	  0x07000, 2048, 0x1,
comment|/* ABR schedule table */
value|\ 	  0x07800, 2048, 0x2
comment|/* RxFIFO size in words */
value|\ 	},								\ 	{
comment|/* 32k x 32, 1024 connections */
value|\ 	  32, 1024, 10, IDT_CFG_CTS1K,
comment|/* RAM, connections, VC bits */
value|\ 	  0x02000,
comment|/* RCT base */
value|\ 	  0x03c00,
comment|/* rate table address */
value|\ 	  0x04e00, 1621,
comment|/* SCD base and num */
value|\ 	  0x0c000, 4096,
comment|/* TST/words, base */
value|\ 	  0x0e000, 4096, 0x2,
comment|/* ABR schedule table */
value|\ 	  0x0f000, 4096, 0x3
comment|/* RxFIFO size in words */
value|\ 	},								\ 	{
comment|/* 128k x 32, 4096 connections */
value|\ 	  128, 4096, 12, IDT_CFG_CTS4K,
comment|/* RAM, connections, VC bits */
value|\ 	  0x08000,
comment|/* RCT base */
value|\ 	  0x0cc00,
comment|/* rate table address */
value|\ 	  0x0de00, 9358,
comment|/* SCD base and num */
value|\ 	  0x37000, 8192,
comment|/* TST/words, base */
value|\ 	  0x3b000, 16384, 0x4,
comment|/* ABR schedule table */
value|\ 	  0x3f000, 4096, 0x3
comment|/* RxFIFO size in words */
value|\ 	},								\ 	{
comment|/* 512k x 32, 512 connections */
value|\ 	  512, 16384, 14, IDT_CFG_CTS16K,
comment|/* RAM, connections, VC bits */
value|\ 	  0x20000,
comment|/* RCT base */
value|\ 	  0x30c00,
comment|/* rate table address */
value|\ 	  0x31e00, 43036,
comment|/* SCD base and num */
value|\ 	  0xef000, 16384,
comment|/* TST/words, base */
value|\ 	  0xf7000, 16384, 0x5,
comment|/* ABR schedule table */
value|\ 	  0xff000,  4096, 0x3
comment|/* RxFIFO size in words */
value|\ 	},								\ }
end_define

end_unit

