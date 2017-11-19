begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-4-Clause  *  * Copyright (c) 1997, 1998  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Rhine register definitions.  */
end_comment

begin_define
define|#
directive|define
name|VR_PAR0
value|0x00
end_define

begin_comment
comment|/* node address 0 to 4 */
end_comment

begin_define
define|#
directive|define
name|VR_PAR1
value|0x04
end_define

begin_comment
comment|/* node address 2 to 6 */
end_comment

begin_define
define|#
directive|define
name|VR_RXCFG
value|0x06
end_define

begin_comment
comment|/* receiver config register */
end_comment

begin_define
define|#
directive|define
name|VR_TXCFG
value|0x07
end_define

begin_comment
comment|/* transmit config register */
end_comment

begin_define
define|#
directive|define
name|VR_CR0
value|0x08
end_define

begin_comment
comment|/* command register 0 */
end_comment

begin_define
define|#
directive|define
name|VR_CR1
value|0x09
end_define

begin_comment
comment|/* command register 1 */
end_comment

begin_define
define|#
directive|define
name|VR_TQW
value|0x0A
end_define

begin_comment
comment|/* tx queue wake 6105M, 8bits */
end_comment

begin_define
define|#
directive|define
name|VR_ISR
value|0x0C
end_define

begin_comment
comment|/* interrupt/status register */
end_comment

begin_define
define|#
directive|define
name|VR_IMR
value|0x0E
end_define

begin_comment
comment|/* interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|VR_MAR0
value|0x10
end_define

begin_comment
comment|/* multicast hash 0 */
end_comment

begin_define
define|#
directive|define
name|VR_MAR1
value|0x14
end_define

begin_comment
comment|/* multicast hash 1 */
end_comment

begin_define
define|#
directive|define
name|VR_MCAM0
value|0x10
end_define

begin_define
define|#
directive|define
name|VR_MCAM1
value|0x11
end_define

begin_define
define|#
directive|define
name|VR_MCAM2
value|0x12
end_define

begin_define
define|#
directive|define
name|VR_MCAM3
value|0x13
end_define

begin_define
define|#
directive|define
name|VR_MCAM4
value|0x14
end_define

begin_define
define|#
directive|define
name|VR_MCAM5
value|0x15
end_define

begin_define
define|#
directive|define
name|VR_VCAM0
value|0x16
end_define

begin_define
define|#
directive|define
name|VR_VCAM1
value|0x17
end_define

begin_define
define|#
directive|define
name|VR_RXADDR
value|0x18
end_define

begin_comment
comment|/* rx descriptor list start addr */
end_comment

begin_define
define|#
directive|define
name|VR_TXADDR
value|0x1C
end_define

begin_comment
comment|/* tx descriptor list start addr */
end_comment

begin_define
define|#
directive|define
name|VR_CURRXDESC0
value|0x20
end_define

begin_define
define|#
directive|define
name|VR_CURRXDESC1
value|0x24
end_define

begin_define
define|#
directive|define
name|VR_CURRXDESC2
value|0x28
end_define

begin_define
define|#
directive|define
name|VR_CURRXDESC3
value|0x2C
end_define

begin_define
define|#
directive|define
name|VR_NEXTRXDESC0
value|0x30
end_define

begin_define
define|#
directive|define
name|VR_NEXTRXDESC1
value|0x34
end_define

begin_define
define|#
directive|define
name|VR_NEXTRXDESC2
value|0x38
end_define

begin_define
define|#
directive|define
name|VR_NEXTRXDESC3
value|0x3C
end_define

begin_define
define|#
directive|define
name|VR_CURTXDESC0
value|0x40
end_define

begin_define
define|#
directive|define
name|VR_CURTXDESC1
value|0x44
end_define

begin_define
define|#
directive|define
name|VR_CURTXDESC2
value|0x48
end_define

begin_define
define|#
directive|define
name|VR_CURTXDESC3
value|0x4C
end_define

begin_define
define|#
directive|define
name|VR_NEXTTXDESC0
value|0x50
end_define

begin_define
define|#
directive|define
name|VR_NEXTTXDESC1
value|0x54
end_define

begin_define
define|#
directive|define
name|VR_NEXTTXDESC2
value|0x58
end_define

begin_define
define|#
directive|define
name|VR_NEXTTXDESC3
value|0x5C
end_define

begin_define
define|#
directive|define
name|VR_CURRXDMA
value|0x60
end_define

begin_comment
comment|/* current RX DMA address */
end_comment

begin_define
define|#
directive|define
name|VR_CURTXDMA
value|0x64
end_define

begin_comment
comment|/* current TX DMA address */
end_comment

begin_define
define|#
directive|define
name|VR_TALLYCNT
value|0x68
end_define

begin_comment
comment|/* tally counter test register */
end_comment

begin_define
define|#
directive|define
name|VR_PHYADDR
value|0x6C
end_define

begin_define
define|#
directive|define
name|VR_MIISTAT
value|0x6D
end_define

begin_define
define|#
directive|define
name|VR_BCR0
value|0x6E
end_define

begin_define
define|#
directive|define
name|VR_BCR1
value|0x6F
end_define

begin_define
define|#
directive|define
name|VR_MIICMD
value|0x70
end_define

begin_define
define|#
directive|define
name|VR_MIIADDR
value|0x71
end_define

begin_define
define|#
directive|define
name|VR_MIIDATA
value|0x72
end_define

begin_define
define|#
directive|define
name|VR_EECSR
value|0x74
end_define

begin_define
define|#
directive|define
name|VR_TEST
value|0x75
end_define

begin_define
define|#
directive|define
name|VR_GPIO
value|0x76
end_define

begin_define
define|#
directive|define
name|VR_CFGA
value|0x78
end_define

begin_define
define|#
directive|define
name|VR_CFGB
value|0x79
end_define

begin_define
define|#
directive|define
name|VR_CFGC
value|0x7A
end_define

begin_define
define|#
directive|define
name|VR_CFGD
value|0x7B
end_define

begin_define
define|#
directive|define
name|VR_MPA_CNT
value|0x7C
end_define

begin_define
define|#
directive|define
name|VR_CRC_CNT
value|0x7E
end_define

begin_define
define|#
directive|define
name|VR_MISC_CR0
value|0x80
end_define

begin_comment
comment|/* VT6102, 8bits */
end_comment

begin_define
define|#
directive|define
name|VR_MISC_CR1
value|0x81
end_define

begin_define
define|#
directive|define
name|VR_STICKHW
value|0x83
end_define

begin_define
define|#
directive|define
name|VR_MII_ISR
value|0x84
end_define

begin_define
define|#
directive|define
name|VR_MII_IMR
value|0x86
end_define

begin_define
define|#
directive|define
name|VR_CAMMASK
value|0x88
end_define

begin_comment
comment|/* VT6105M, 32bits */
end_comment

begin_define
define|#
directive|define
name|VR_CAMCTL
value|0x92
end_define

begin_comment
comment|/* VT6105M, 8bits */
end_comment

begin_define
define|#
directive|define
name|VR_CAMADDR
value|0x93
end_define

begin_comment
comment|/* VT6105M, 8bits */
end_comment

begin_define
define|#
directive|define
name|VR_FLOWCR0
value|0x98
end_define

begin_define
define|#
directive|define
name|VR_FLOWCR1
value|0x99
end_define

begin_define
define|#
directive|define
name|VR_PAUSETIMER
value|0x9A
end_define

begin_comment
comment|/* 16bit */
end_comment

begin_define
define|#
directive|define
name|VR_WOLCR_SET
value|0xA0
end_define

begin_define
define|#
directive|define
name|VR_PWRCFG_SET
value|0xA1
end_define

begin_define
define|#
directive|define
name|VR_TESTREG_SET
value|0xA2
end_define

begin_define
define|#
directive|define
name|VR_WOLCFG_SET
value|0xA3
end_define

begin_define
define|#
directive|define
name|VR_WOLCR_CLR
value|0xA4
end_define

begin_define
define|#
directive|define
name|VR_PWRCFG_CLR
value|0xA5
end_define

begin_define
define|#
directive|define
name|VR_TESTREG_CLR
value|0xA6
end_define

begin_define
define|#
directive|define
name|VR_WOLCFG_CLR
value|0xA7
end_define

begin_define
define|#
directive|define
name|VR_PWRCSR_SET
value|0xA8
end_define

begin_define
define|#
directive|define
name|VR_PWRCSR1_SET
value|0xA9
end_define

begin_define
define|#
directive|define
name|VR_PWRCSR_CLR
value|0xAC
end_define

begin_define
define|#
directive|define
name|VR_PWRCSR1_CLR
value|0xAD
end_define

begin_comment
comment|/* Misc Registers */
end_comment

begin_define
define|#
directive|define
name|VR_MISCCR0_RXPAUSE
value|0x08
end_define

begin_define
define|#
directive|define
name|VR_MISCCR1_FORSRST
value|0x40
end_define

begin_comment
comment|/*  * RX config bits.  */
end_comment

begin_define
define|#
directive|define
name|VR_RXCFG_RX_ERRPKTS
value|0x01
end_define

begin_define
define|#
directive|define
name|VR_RXCFG_RX_RUNT
value|0x02
end_define

begin_define
define|#
directive|define
name|VR_RXCFG_RX_MULTI
value|0x04
end_define

begin_define
define|#
directive|define
name|VR_RXCFG_RX_BROAD
value|0x08
end_define

begin_define
define|#
directive|define
name|VR_RXCFG_RX_PROMISC
value|0x10
end_define

begin_define
define|#
directive|define
name|VR_RXCFG_RX_THRESH
value|0xE0
end_define

begin_define
define|#
directive|define
name|VR_RXTHRESH_32BYTES
value|0x00
end_define

begin_define
define|#
directive|define
name|VR_RXTHRESH_64BYTES
value|0x20
end_define

begin_define
define|#
directive|define
name|VR_RXTHRESH_128BYTES
value|0x40
end_define

begin_define
define|#
directive|define
name|VR_RXTHRESH_256BYTES
value|0x60
end_define

begin_define
define|#
directive|define
name|VR_RXTHRESH_512BYTES
value|0x80
end_define

begin_define
define|#
directive|define
name|VR_RXTHRESH_768BYTES
value|0xA0
end_define

begin_define
define|#
directive|define
name|VR_RXTHRESH_1024BYTES
value|0xC0
end_define

begin_define
define|#
directive|define
name|VR_RXTHRESH_STORENFWD
value|0xE0
end_define

begin_comment
comment|/*  * TX config bits.  */
end_comment

begin_define
define|#
directive|define
name|VR_TXCFG_TXTAGEN
value|0x01
end_define

begin_comment
comment|/* 6105M */
end_comment

begin_define
define|#
directive|define
name|VR_TXCFG_LOOPBKMODE
value|0x06
end_define

begin_define
define|#
directive|define
name|VR_TXCFG_BACKOFF
value|0x08
end_define

begin_define
define|#
directive|define
name|VR_TXCFG_RXTAGCTL
value|0x10
end_define

begin_comment
comment|/* 6105M */
end_comment

begin_define
define|#
directive|define
name|VR_TXCFG_TX_THRESH
value|0xE0
end_define

begin_define
define|#
directive|define
name|VR_TXTHRESH_32BYTES
value|0x00
end_define

begin_define
define|#
directive|define
name|VR_TXTHRESH_64BYTES
value|0x20
end_define

begin_define
define|#
directive|define
name|VR_TXTHRESH_128BYTES
value|0x40
end_define

begin_define
define|#
directive|define
name|VR_TXTHRESH_256BYTES
value|0x60
end_define

begin_define
define|#
directive|define
name|VR_TXTHRESH_512BYTES
value|0x80
end_define

begin_define
define|#
directive|define
name|VR_TXTHRESH_768BYTES
value|0xA0
end_define

begin_define
define|#
directive|define
name|VR_TXTHRESH_1024BYTES
value|0xC0
end_define

begin_define
define|#
directive|define
name|VR_TXTHRESH_STORENFWD
value|0xE0
end_define

begin_define
define|#
directive|define
name|VR_TXTHRESH_MIN
value|1
end_define

begin_comment
comment|/* 64 bytes */
end_comment

begin_define
define|#
directive|define
name|VR_TXTHRESH_MAX
value|5
end_define

begin_comment
comment|/* store and forward */
end_comment

begin_comment
comment|/*  * Command register bits.  */
end_comment

begin_define
define|#
directive|define
name|VR_CR0_INIT
value|0x01
end_define

begin_define
define|#
directive|define
name|VR_CR0_START
value|0x02
end_define

begin_define
define|#
directive|define
name|VR_CR0_STOP
value|0x04
end_define

begin_define
define|#
directive|define
name|VR_CR0_RX_ON
value|0x08
end_define

begin_define
define|#
directive|define
name|VR_CR0_TX_ON
value|0x10
end_define

begin_define
define|#
directive|define
name|VR_CR0_TX_GO
value|0x20
end_define

begin_define
define|#
directive|define
name|VR_CR0_RX_GO
value|0x40
end_define

begin_define
define|#
directive|define
name|VR_CR0_RSVD
value|0x80
end_define

begin_define
define|#
directive|define
name|VR_CR1_RX_EARLY
value|0x01
end_define

begin_define
define|#
directive|define
name|VR_CR1_TX_EARLY
value|0x02
end_define

begin_define
define|#
directive|define
name|VR_CR1_FULLDUPLEX
value|0x04
end_define

begin_define
define|#
directive|define
name|VR_CR1_TX_NOPOLL
value|0x08
end_define

begin_define
define|#
directive|define
name|VR_CR1_RESET
value|0x80
end_define

begin_comment
comment|/*  * Interrupt status bits.  */
end_comment

begin_define
define|#
directive|define
name|VR_ISR_RX_OK
value|0x0001
end_define

begin_comment
comment|/* packet rx ok */
end_comment

begin_define
define|#
directive|define
name|VR_ISR_TX_OK
value|0x0002
end_define

begin_comment
comment|/* packet tx ok */
end_comment

begin_define
define|#
directive|define
name|VR_ISR_RX_ERR
value|0x0004
end_define

begin_comment
comment|/* packet rx with err */
end_comment

begin_define
define|#
directive|define
name|VR_ISR_TX_ABRT
value|0x0008
end_define

begin_comment
comment|/* tx aborted due to excess colls */
end_comment

begin_define
define|#
directive|define
name|VR_ISR_TX_UNDERRUN
value|0x0010
end_define

begin_comment
comment|/* tx buffer underflow */
end_comment

begin_define
define|#
directive|define
name|VR_ISR_RX_NOBUF
value|0x0020
end_define

begin_comment
comment|/* no rx buffer available */
end_comment

begin_define
define|#
directive|define
name|VR_ISR_BUSERR
value|0x0040
end_define

begin_comment
comment|/* PCI bus error */
end_comment

begin_define
define|#
directive|define
name|VR_ISR_STATSOFLOW
value|0x0080
end_define

begin_comment
comment|/* stats counter oflow */
end_comment

begin_define
define|#
directive|define
name|VR_ISR_RX_EARLY
value|0x0100
end_define

begin_comment
comment|/* rx early */
end_comment

begin_define
define|#
directive|define
name|VR_ISR_LINKSTAT
value|0x0200
end_define

begin_comment
comment|/* MII status change */
end_comment

begin_define
define|#
directive|define
name|VR_ISR_ETI
value|0x0200
end_define

begin_comment
comment|/* Tx early (3043/3071) */
end_comment

begin_define
define|#
directive|define
name|VR_ISR_UDFI
value|0x0200
end_define

begin_comment
comment|/* Tx FIFO underflow (6102) */
end_comment

begin_define
define|#
directive|define
name|VR_ISR_RX_OFLOW
value|0x0400
end_define

begin_comment
comment|/* rx FIFO overflow */
end_comment

begin_define
define|#
directive|define
name|VR_ISR_RX_DROPPED
value|0x0800
end_define

begin_define
define|#
directive|define
name|VR_ISR_RX_NOBUF2
value|0x1000
end_define

begin_comment
comment|/* Rx descriptor running up */
end_comment

begin_define
define|#
directive|define
name|VR_ISR_TX_ABRT2
value|0x2000
end_define

begin_define
define|#
directive|define
name|VR_ISR_LINKSTAT2
value|0x4000
end_define

begin_define
define|#
directive|define
name|VR_ISR_MAGICPACKET
value|0x8000
end_define

begin_define
define|#
directive|define
name|VR_ISR_ERR_BITS
value|"\20"					\ 				"\3RXERR\4TXABRT\5TXUNDERRUN"		\ 				"\6RXNOBUF\7BUSERR\10STATSOFLOW"	\ 				"\12TXUDF\13RXOFLOW\14RXDROPPED"	\ 				"\15RXNOBUF2\16TXABRT2"
end_define

begin_comment
comment|/*  * Interrupt mask bits.  */
end_comment

begin_define
define|#
directive|define
name|VR_IMR_RX_OK
value|0x0001
end_define

begin_comment
comment|/* packet rx ok */
end_comment

begin_define
define|#
directive|define
name|VR_IMR_TX_OK
value|0x0002
end_define

begin_comment
comment|/* packet tx ok */
end_comment

begin_define
define|#
directive|define
name|VR_IMR_RX_ERR
value|0x0004
end_define

begin_comment
comment|/* packet rx with err */
end_comment

begin_define
define|#
directive|define
name|VR_IMR_TX_ABRT
value|0x0008
end_define

begin_comment
comment|/* tx aborted due to excess colls */
end_comment

begin_define
define|#
directive|define
name|VR_IMR_TX_UNDERRUN
value|0x0010
end_define

begin_comment
comment|/* tx buffer underflow */
end_comment

begin_define
define|#
directive|define
name|VR_IMR_RX_NOBUF
value|0x0020
end_define

begin_comment
comment|/* no rx buffer available */
end_comment

begin_define
define|#
directive|define
name|VR_IMR_BUSERR
value|0x0040
end_define

begin_comment
comment|/* PCI bus error */
end_comment

begin_define
define|#
directive|define
name|VR_IMR_STATSOFLOW
value|0x0080
end_define

begin_comment
comment|/* stats counter oflow */
end_comment

begin_define
define|#
directive|define
name|VR_IMR_RX_EARLY
value|0x0100
end_define

begin_comment
comment|/* rx early */
end_comment

begin_define
define|#
directive|define
name|VR_IMR_LINKSTAT
value|0x0200
end_define

begin_comment
comment|/* MII status change */
end_comment

begin_define
define|#
directive|define
name|VR_IMR_RX_OFLOW
value|0x0400
end_define

begin_comment
comment|/* rx FIFO overflow */
end_comment

begin_define
define|#
directive|define
name|VR_IMR_RX_DROPPED
value|0x0800
end_define

begin_define
define|#
directive|define
name|VR_IMR_RX_NOBUF2
value|0x1000
end_define

begin_define
define|#
directive|define
name|VR_IMR_TX_ABRT2
value|0x2000
end_define

begin_define
define|#
directive|define
name|VR_IMR_LINKSTAT2
value|0x4000
end_define

begin_define
define|#
directive|define
name|VR_IMR_MAGICPACKET
value|0x8000
end_define

begin_define
define|#
directive|define
name|VR_INTRS
define|\
value|(VR_IMR_RX_OK|VR_IMR_TX_OK|VR_IMR_RX_NOBUF|			\ 	VR_IMR_TX_ABRT|VR_IMR_TX_UNDERRUN|VR_IMR_BUSERR|		\ 	VR_IMR_RX_ERR|VR_ISR_RX_DROPPED)
end_define

begin_comment
comment|/*  * MII status register.  */
end_comment

begin_define
define|#
directive|define
name|VR_MIISTAT_SPEED
value|0x01
end_define

begin_define
define|#
directive|define
name|VR_MIISTAT_LINKFAULT
value|0x02
end_define

begin_define
define|#
directive|define
name|VR_MIISTAT_MGTREADERR
value|0x04
end_define

begin_define
define|#
directive|define
name|VR_MIISTAT_MIIERR
value|0x08
end_define

begin_define
define|#
directive|define
name|VR_MIISTAT_PHYOPT
value|0x10
end_define

begin_define
define|#
directive|define
name|VR_MIISTAT_MDC_SPEED
value|0x20
end_define

begin_define
define|#
directive|define
name|VR_MIISTAT_RSVD
value|0x40
end_define

begin_define
define|#
directive|define
name|VR_MIISTAT_GPIO1POLL
value|0x80
end_define

begin_comment
comment|/*  * MII command register bits.  */
end_comment

begin_define
define|#
directive|define
name|VR_MIICMD_CLK
value|0x01
end_define

begin_define
define|#
directive|define
name|VR_MIICMD_DATAOUT
value|0x02
end_define

begin_define
define|#
directive|define
name|VR_MIICMD_DATAIN
value|0x04
end_define

begin_define
define|#
directive|define
name|VR_MIICMD_DIR
value|0x08
end_define

begin_define
define|#
directive|define
name|VR_MIICMD_DIRECTPGM
value|0x10
end_define

begin_define
define|#
directive|define
name|VR_MIICMD_WRITE_ENB
value|0x20
end_define

begin_define
define|#
directive|define
name|VR_MIICMD_READ_ENB
value|0x40
end_define

begin_define
define|#
directive|define
name|VR_MIICMD_AUTOPOLL
value|0x80
end_define

begin_comment
comment|/*  * EEPROM control bits.  */
end_comment

begin_define
define|#
directive|define
name|VR_EECSR_DATAIN
value|0x01
end_define

begin_comment
comment|/* data out */
end_comment

begin_define
define|#
directive|define
name|VR_EECSR_DATAOUT
value|0x02
end_define

begin_comment
comment|/* data in */
end_comment

begin_define
define|#
directive|define
name|VR_EECSR_CLK
value|0x04
end_define

begin_comment
comment|/* clock */
end_comment

begin_define
define|#
directive|define
name|VR_EECSR_CS
value|0x08
end_define

begin_comment
comment|/* chip select */
end_comment

begin_define
define|#
directive|define
name|VR_EECSR_DPM
value|0x10
end_define

begin_define
define|#
directive|define
name|VR_EECSR_LOAD
value|0x20
end_define

begin_define
define|#
directive|define
name|VR_EECSR_EMBP
value|0x40
end_define

begin_define
define|#
directive|define
name|VR_EECSR_EEPR
value|0x80
end_define

begin_define
define|#
directive|define
name|VR_EECMD_WRITE
value|0x140
end_define

begin_define
define|#
directive|define
name|VR_EECMD_READ
value|0x180
end_define

begin_define
define|#
directive|define
name|VR_EECMD_ERASE
value|0x1c0
end_define

begin_comment
comment|/*  * Test register bits.  */
end_comment

begin_define
define|#
directive|define
name|VR_TEST_TEST0
value|0x01
end_define

begin_define
define|#
directive|define
name|VR_TEST_TEST1
value|0x02
end_define

begin_define
define|#
directive|define
name|VR_TEST_TEST2
value|0x04
end_define

begin_define
define|#
directive|define
name|VR_TEST_TSTUD
value|0x08
end_define

begin_define
define|#
directive|define
name|VR_TEST_TSTOV
value|0x10
end_define

begin_define
define|#
directive|define
name|VR_TEST_BKOFF
value|0x20
end_define

begin_define
define|#
directive|define
name|VR_TEST_FCOL
value|0x40
end_define

begin_define
define|#
directive|define
name|VR_TEST_HBDES
value|0x80
end_define

begin_comment
comment|/*  * Config A register bits.  */
end_comment

begin_define
define|#
directive|define
name|VR_CFG_GPIO2OUTENB
value|0x01
end_define

begin_define
define|#
directive|define
name|VR_CFG_GPIO2OUT
value|0x02
end_define

begin_comment
comment|/* gen. purp. pin */
end_comment

begin_define
define|#
directive|define
name|VR_CFG_GPIO2IN
value|0x04
end_define

begin_comment
comment|/* gen. purp. pin */
end_comment

begin_define
define|#
directive|define
name|VR_CFG_AUTOOPT
value|0x08
end_define

begin_comment
comment|/* enable rx/tx autopoll */
end_comment

begin_define
define|#
directive|define
name|VR_CFG_MIIOPT
value|0x10
end_define

begin_define
define|#
directive|define
name|VR_CFG_MMIENB
value|0x20
end_define

begin_comment
comment|/* memory mapped mode enb */
end_comment

begin_define
define|#
directive|define
name|VR_CFG_JUMPER
value|0x40
end_define

begin_comment
comment|/* PHY and oper. mode select */
end_comment

begin_define
define|#
directive|define
name|VR_CFG_EELOAD
value|0x80
end_define

begin_comment
comment|/* enable EEPROM programming */
end_comment

begin_comment
comment|/*  * Config B register bits.  */
end_comment

begin_define
define|#
directive|define
name|VR_CFG_LATMENB
value|0x01
end_define

begin_comment
comment|/* larency timer effect enb. */
end_comment

begin_define
define|#
directive|define
name|VR_CFG_MRREADWAIT
value|0x02
end_define

begin_define
define|#
directive|define
name|VR_CFG_MRWRITEWAIT
value|0x04
end_define

begin_define
define|#
directive|define
name|VR_CFG_RX_ARB
value|0x08
end_define

begin_define
define|#
directive|define
name|VR_CFG_TX_ARB
value|0x10
end_define

begin_define
define|#
directive|define
name|VR_CFG_READMULTI
value|0x20
end_define

begin_define
define|#
directive|define
name|VR_CFG_TX_PACE
value|0x40
end_define

begin_define
define|#
directive|define
name|VR_CFG_TX_QDIS
value|0x80
end_define

begin_comment
comment|/*  * Config C register bits.  */
end_comment

begin_define
define|#
directive|define
name|VR_CFG_ROMSEL0
value|0x01
end_define

begin_define
define|#
directive|define
name|VR_CFG_ROMSEL1
value|0x02
end_define

begin_define
define|#
directive|define
name|VR_CFG_ROMSEL2
value|0x04
end_define

begin_define
define|#
directive|define
name|VR_CFG_ROMTIMESEL
value|0x08
end_define

begin_define
define|#
directive|define
name|VR_CFG_RSVD0
value|0x10
end_define

begin_define
define|#
directive|define
name|VR_CFG_ROMDLY
value|0x20
end_define

begin_define
define|#
directive|define
name|VR_CFG_ROMOPT
value|0x40
end_define

begin_define
define|#
directive|define
name|VR_CFG_RSVD1
value|0x80
end_define

begin_comment
comment|/*  * Config D register bits.  */
end_comment

begin_define
define|#
directive|define
name|VR_CFG_BACKOFFOPT
value|0x01
end_define

begin_define
define|#
directive|define
name|VR_CFG_BACKOFFMOD
value|0x02
end_define

begin_define
define|#
directive|define
name|VR_CFG_CAPEFFECT
value|0x04
end_define

begin_define
define|#
directive|define
name|VR_CFG_BACKOFFRAND
value|0x08
end_define

begin_define
define|#
directive|define
name|VR_CFG_MAGICKPACKET
value|0x10
end_define

begin_define
define|#
directive|define
name|VR_CFG_PCIREADLINE
value|0x20
end_define

begin_define
define|#
directive|define
name|VR_CFG_DIAG
value|0x40
end_define

begin_define
define|#
directive|define
name|VR_CFG_GPIOEN
value|0x80
end_define

begin_comment
comment|/* Sticky HW bits */
end_comment

begin_define
define|#
directive|define
name|VR_STICKHW_DS0
value|0x01
end_define

begin_define
define|#
directive|define
name|VR_STICKHW_DS1
value|0x02
end_define

begin_define
define|#
directive|define
name|VR_STICKHW_WOL_ENB
value|0x04
end_define

begin_define
define|#
directive|define
name|VR_STICKHW_WOL_STS
value|0x08
end_define

begin_define
define|#
directive|define
name|VR_STICKHW_LEGWOL_ENB
value|0x80
end_define

begin_comment
comment|/*  * BCR0 register bits. (At least for the VT6102 chip.)  */
end_comment

begin_define
define|#
directive|define
name|VR_BCR0_DMA_LENGTH
value|0x07
end_define

begin_define
define|#
directive|define
name|VR_BCR0_DMA_32BYTES
value|0x00
end_define

begin_define
define|#
directive|define
name|VR_BCR0_DMA_64BYTES
value|0x01
end_define

begin_define
define|#
directive|define
name|VR_BCR0_DMA_128BYTES
value|0x02
end_define

begin_define
define|#
directive|define
name|VR_BCR0_DMA_256BYTES
value|0x03
end_define

begin_define
define|#
directive|define
name|VR_BCR0_DMA_512BYTES
value|0x04
end_define

begin_define
define|#
directive|define
name|VR_BCR0_DMA_1024BYTES
value|0x05
end_define

begin_define
define|#
directive|define
name|VR_BCR0_DMA_STORENFWD
value|0x07
end_define

begin_define
define|#
directive|define
name|VR_BCR0_RX_THRESH
value|0x38
end_define

begin_define
define|#
directive|define
name|VR_BCR0_RXTHRESHCFG
value|0x00
end_define

begin_define
define|#
directive|define
name|VR_BCR0_RXTHRESH64BYTES
value|0x08
end_define

begin_define
define|#
directive|define
name|VR_BCR0_RXTHRESH128BYTES
value|0x10
end_define

begin_define
define|#
directive|define
name|VR_BCR0_RXTHRESH256BYTES
value|0x18
end_define

begin_define
define|#
directive|define
name|VR_BCR0_RXTHRESH512BYTES
value|0x20
end_define

begin_define
define|#
directive|define
name|VR_BCR0_RXTHRESH1024BYTES
value|0x28
end_define

begin_define
define|#
directive|define
name|VR_BCR0_RXTHRESHSTORENFWD
value|0x38
end_define

begin_define
define|#
directive|define
name|VR_BCR0_EXTLED
value|0x40
end_define

begin_define
define|#
directive|define
name|VR_BCR0_MED2
value|0x80
end_define

begin_comment
comment|/*  * BCR1 register bits. (At least for the VT6102 chip.)  */
end_comment

begin_define
define|#
directive|define
name|VR_BCR1_POT0
value|0x01
end_define

begin_define
define|#
directive|define
name|VR_BCR1_POT1
value|0x02
end_define

begin_define
define|#
directive|define
name|VR_BCR1_POT2
value|0x04
end_define

begin_define
define|#
directive|define
name|VR_BCR1_TX_THRESH
value|0x38
end_define

begin_define
define|#
directive|define
name|VR_BCR1_TXTHRESHCFG
value|0x00
end_define

begin_define
define|#
directive|define
name|VR_BCR1_TXTHRESH64BYTES
value|0x08
end_define

begin_define
define|#
directive|define
name|VR_BCR1_TXTHRESH128BYTES
value|0x10
end_define

begin_define
define|#
directive|define
name|VR_BCR1_TXTHRESH256BYTES
value|0x18
end_define

begin_define
define|#
directive|define
name|VR_BCR1_TXTHRESH512BYTES
value|0x20
end_define

begin_define
define|#
directive|define
name|VR_BCR1_TXTHRESH1024BYTES
value|0x28
end_define

begin_define
define|#
directive|define
name|VR_BCR1_TXTHRESHSTORENFWD
value|0x38
end_define

begin_define
define|#
directive|define
name|VR_BCR1_VLANFILT_ENB
value|0x80
end_define

begin_comment
comment|/* VT6105M */
end_comment

begin_comment
comment|/*  * CAMCTL register bits. (VT6105M only)  */
end_comment

begin_define
define|#
directive|define
name|VR_CAMCTL_ENA
value|0x01
end_define

begin_define
define|#
directive|define
name|VR_CAMCTL_VLAN
value|0x02
end_define

begin_define
define|#
directive|define
name|VR_CAMCTL_MCAST
value|0x00
end_define

begin_define
define|#
directive|define
name|VR_CAMCTL_WRITE
value|0x04
end_define

begin_define
define|#
directive|define
name|VR_CAMCTL_READ
value|0x08
end_define

begin_define
define|#
directive|define
name|VR_CAM_MCAST_CNT
value|32
end_define

begin_define
define|#
directive|define
name|VR_CAM_VLAN_CNT
value|32
end_define

begin_comment
comment|/*  * FLOWCR1 register bits. (VT6105LOM, VT6105M only)  */
end_comment

begin_define
define|#
directive|define
name|VR_FLOWCR1_TXLO4
value|0x00
end_define

begin_define
define|#
directive|define
name|VR_FLOWCR1_TXLO8
value|0x40
end_define

begin_define
define|#
directive|define
name|VR_FLOWCR1_TXLO16
value|0x80
end_define

begin_define
define|#
directive|define
name|VR_FLOWCR1_TXLO24
value|0xC0
end_define

begin_define
define|#
directive|define
name|VR_FLOWCR1_TXHI24
value|0x00
end_define

begin_define
define|#
directive|define
name|VR_FLOWCR1_TXHI32
value|0x10
end_define

begin_define
define|#
directive|define
name|VR_FLOWCR1_TXHI48
value|0x20
end_define

begin_define
define|#
directive|define
name|VR_FLOWCR1_TXHI64
value|0x30
end_define

begin_define
define|#
directive|define
name|VR_FLOWCR1_XONXOFF
value|0x08
end_define

begin_define
define|#
directive|define
name|VR_FLOWCR1_TXPAUSE
value|0x04
end_define

begin_define
define|#
directive|define
name|VR_FLOWCR1_RXPAUSE
value|0x02
end_define

begin_define
define|#
directive|define
name|VR_FLOWCR1_HDX
value|0x01
end_define

begin_comment
comment|/*  * WOLCR register bits. (VT6102 or higher only)  */
end_comment

begin_define
define|#
directive|define
name|VR_WOLCR_PATTERN0
value|0x01
end_define

begin_define
define|#
directive|define
name|VR_WOLCR_PATTERN1
value|0x02
end_define

begin_define
define|#
directive|define
name|VR_WOLCR_PATTERN2
value|0x04
end_define

begin_define
define|#
directive|define
name|VR_WOLCR_PATTERN3
value|0x08
end_define

begin_define
define|#
directive|define
name|VR_WOLCR_UCAST
value|0x10
end_define

begin_define
define|#
directive|define
name|VR_WOLCR_MAGIC
value|0x20
end_define

begin_define
define|#
directive|define
name|VR_WOLCR_LINKON
value|0x40
end_define

begin_define
define|#
directive|define
name|VR_WOLCR_LINKOFF
value|0x80
end_define

begin_comment
comment|/*  * PWRCFG register bits. (VT6102 or higher only)  */
end_comment

begin_define
define|#
directive|define
name|VR_PWRCFG_WOLEN
value|0x01
end_define

begin_define
define|#
directive|define
name|VR_PWRCFG_WOLSR
value|0x02
end_define

begin_define
define|#
directive|define
name|VR_PWRCFG_LEGACY_WOL
value|0x10
end_define

begin_define
define|#
directive|define
name|VR_PWRCFG_WOLTYPE_PULSE
value|0x20
end_define

begin_define
define|#
directive|define
name|VR_PWRCFG_SMIITIME
value|0x80
end_define

begin_comment
comment|/*  * WOLCFG register bits. (VT6102 or higher only)  */
end_comment

begin_define
define|#
directive|define
name|VR_WOLCFG_PATTERN_PAGE
value|0x04
end_define

begin_comment
comment|/* VT6505 B0 */
end_comment

begin_define
define|#
directive|define
name|VR_WOLCFG_SMIIOPT
value|0x04
end_define

begin_define
define|#
directive|define
name|VR_WOLCFG_SMIIACC
value|0x08
end_define

begin_define
define|#
directive|define
name|VR_WOLCFG_SAB
value|0x10
end_define

begin_define
define|#
directive|define
name|VR_WOLCFG_SAM
value|0x20
end_define

begin_define
define|#
directive|define
name|VR_WOLCFG_SFDX
value|0x40
end_define

begin_define
define|#
directive|define
name|VR_WOLCFG_PMEOVR
value|0x80
end_define

begin_comment
comment|/*  * Rhine TX/RX list structure.  */
end_comment

begin_struct
struct|struct
name|vr_desc
block|{
name|uint32_t
name|vr_status
decl_stmt|;
name|uint32_t
name|vr_ctl
decl_stmt|;
name|uint32_t
name|vr_data
decl_stmt|;
name|uint32_t
name|vr_nextphys
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VR_RXSTAT_RXERR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|VR_RXSTAT_CRCERR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|VR_RXSTAT_FRAMEALIGNERR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|VR_RXSTAT_FIFOOFLOW
value|0x00000008
end_define

begin_define
define|#
directive|define
name|VR_RXSTAT_GIANT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|VR_RXSTAT_RUNT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|VR_RXSTAT_BUSERR
value|0x00000040
end_define

begin_define
define|#
directive|define
name|VR_RXSTAT_FRAG
value|0x00000040
end_define

begin_comment
comment|/* 6105M */
end_comment

begin_define
define|#
directive|define
name|VR_RXSTAT_BUFFERR
value|0x00000080
end_define

begin_define
define|#
directive|define
name|VR_RXSTAT_LASTFRAG
value|0x00000100
end_define

begin_define
define|#
directive|define
name|VR_RXSTAT_FIRSTFRAG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|VR_RXSTAT_RLINK
value|0x00000400
end_define

begin_define
define|#
directive|define
name|VR_RXSTAT_RX_PHYS
value|0x00000800
end_define

begin_define
define|#
directive|define
name|VR_RXSTAT_RX_BROAD
value|0x00001000
end_define

begin_define
define|#
directive|define
name|VR_RXSTAT_RX_MULTI
value|0x00002000
end_define

begin_define
define|#
directive|define
name|VR_RXSTAT_RX_VIDHIT
value|0x00004000
end_define

begin_comment
comment|/* 6105M */
end_comment

begin_define
define|#
directive|define
name|VR_RXSTAT_RX_OK
value|0x00008000
end_define

begin_define
define|#
directive|define
name|VR_RXSTAT_RXLEN
value|0x07FF0000
end_define

begin_define
define|#
directive|define
name|VR_RXSTAT_RXLEN_EXT
value|0x78000000
end_define

begin_define
define|#
directive|define
name|VR_RXSTAT_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|VR_RXBYTES
parameter_list|(
name|x
parameter_list|)
value|((x& VR_RXSTAT_RXLEN)>> 16)
end_define

begin_define
define|#
directive|define
name|VR_RXSTAT_ERR_BITS
value|"\20"				\ 				"\1RXERR\2CRCERR\3FRAMEALIGN"	\ 				"\4FIFOOFLOW\5GIANT\6RUNT"	\ 				"\10BUFERR"
end_define

begin_define
define|#
directive|define
name|VR_RXCTL_BUFLEN
value|0x000007FF
end_define

begin_define
define|#
directive|define
name|VR_RXCTL_BUFLEN_EXT
value|0x00007800
end_define

begin_define
define|#
directive|define
name|VR_RXCTL_CHAIN
value|0x00008000
end_define

begin_define
define|#
directive|define
name|VR_RXCTL_TAG
value|0x00010000
end_define

begin_define
define|#
directive|define
name|VR_RXCTL_UDP
value|0x00020000
end_define

begin_define
define|#
directive|define
name|VR_RXCTL_TCP
value|0x00040000
end_define

begin_define
define|#
directive|define
name|VR_RXCTL_IP
value|0x00080000
end_define

begin_define
define|#
directive|define
name|VR_RXCTL_TCPUDPOK
value|0x00100000
end_define

begin_define
define|#
directive|define
name|VR_RXCTL_IPOK
value|0x00200000
end_define

begin_define
define|#
directive|define
name|VR_RXCTL_SNAPTAG
value|0x00400000
end_define

begin_define
define|#
directive|define
name|VR_RXCTL_RXLERR
value|0x00800000
end_define

begin_comment
comment|/* 6105M */
end_comment

begin_define
define|#
directive|define
name|VR_RXCTL_RX_INTR
value|0x00800000
end_define

begin_define
define|#
directive|define
name|VR_RXCTL
value|(VR_RXCTL_CHAIN|VR_RXCTL_RX_INTR)
end_define

begin_define
define|#
directive|define
name|VR_TXSTAT_DEFER
value|0x00000001
end_define

begin_define
define|#
directive|define
name|VR_TXSTAT_UNDERRUN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|VR_TXSTAT_COLLCNT
value|0x00000078
end_define

begin_define
define|#
directive|define
name|VR_TXSTAT_SQE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|VR_TXSTAT_ABRT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|VR_TXSTAT_LATECOLL
value|0x00000200
end_define

begin_define
define|#
directive|define
name|VR_TXSTAT_CARRLOST
value|0x00000400
end_define

begin_define
define|#
directive|define
name|VR_TXSTAT_UDF
value|0x00000800
end_define

begin_define
define|#
directive|define
name|VR_TXSTAT_TBUFF
value|0x00001000
end_define

begin_define
define|#
directive|define
name|VR_TXSTAT_BUSERR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|VR_TXSTAT_JABTIMEO
value|0x00004000
end_define

begin_define
define|#
directive|define
name|VR_TXSTAT_ERRSUM
value|0x00008000
end_define

begin_define
define|#
directive|define
name|VR_TXSTAT_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|VR_TXCTL_BUFLEN
value|0x000007FF
end_define

begin_define
define|#
directive|define
name|VR_TXCTL_BUFLEN_EXT
value|0x00007800
end_define

begin_define
define|#
directive|define
name|VR_TXCTL_TLINK
value|0x00008000
end_define

begin_define
define|#
directive|define
name|VR_TXCTL_NOCRC
value|0x00010000
end_define

begin_define
define|#
directive|define
name|VR_TXCTL_INSERTTAG
value|0x00020000
end_define

begin_define
define|#
directive|define
name|VR_TXCTL_IPCSUM
value|0x00040000
end_define

begin_define
define|#
directive|define
name|VR_TXCTL_UDPCSUM
value|0x00080000
end_define

begin_define
define|#
directive|define
name|VR_TXCTL_TCPCSUM
value|0x00100000
end_define

begin_define
define|#
directive|define
name|VR_TXCTL_FIRSTFRAG
value|0x00200000
end_define

begin_define
define|#
directive|define
name|VR_TXCTL_LASTFRAG
value|0x00400000
end_define

begin_define
define|#
directive|define
name|VR_TXCTL_FINT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|VR_MIN_FRAMELEN
value|60
end_define

begin_define
define|#
directive|define
name|VR_FLAG_FORCEDELAY
value|1
end_define

begin_define
define|#
directive|define
name|VR_FLAG_SCHEDDELAY
value|2
end_define

begin_define
define|#
directive|define
name|VR_FLAG_DELAYTIMEO
value|3
end_define

begin_define
define|#
directive|define
name|VR_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|VR_MII_TIMEOUT
value|10000
end_define

begin_define
define|#
directive|define
name|VR_PHYADDR_MASK
value|0x1f
end_define

begin_comment
comment|/*  * General constants that are fun to know.  *  * VIA vendor ID  */
end_comment

begin_define
define|#
directive|define
name|VIA_VENDORID
value|0x1106
end_define

begin_comment
comment|/*  * VIA Rhine device IDs.  */
end_comment

begin_define
define|#
directive|define
name|VIA_DEVICEID_RHINE
value|0x3043
end_define

begin_define
define|#
directive|define
name|VIA_DEVICEID_RHINE_II
value|0x6100
end_define

begin_define
define|#
directive|define
name|VIA_DEVICEID_RHINE_II_2
value|0x3065
end_define

begin_define
define|#
directive|define
name|VIA_DEVICEID_RHINE_III
value|0x3106
end_define

begin_define
define|#
directive|define
name|VIA_DEVICEID_RHINE_III_M
value|0x3053
end_define

begin_comment
comment|/*  * Delta Electronics device ID.  */
end_comment

begin_define
define|#
directive|define
name|DELTA_VENDORID
value|0x1500
end_define

begin_comment
comment|/*  * Delta device IDs.  */
end_comment

begin_define
define|#
directive|define
name|DELTA_DEVICEID_RHINE_II
value|0x1320
end_define

begin_comment
comment|/*  * Addtron vendor ID.  */
end_comment

begin_define
define|#
directive|define
name|ADDTRON_VENDORID
value|0x4033
end_define

begin_comment
comment|/*  * Addtron device IDs.  */
end_comment

begin_define
define|#
directive|define
name|ADDTRON_DEVICEID_RHINE_II
value|0x1320
end_define

begin_comment
comment|/*  * VIA Rhine revision IDs  */
end_comment

begin_define
define|#
directive|define
name|REV_ID_VT3043_E
value|0x04
end_define

begin_define
define|#
directive|define
name|REV_ID_VT3071_A
value|0x20
end_define

begin_define
define|#
directive|define
name|REV_ID_VT3071_B
value|0x21
end_define

begin_define
define|#
directive|define
name|REV_ID_VT6102_A
value|0x40
end_define

begin_define
define|#
directive|define
name|REV_ID_VT6102_B
value|0x41
end_define

begin_define
define|#
directive|define
name|REV_ID_VT6102_C
value|0x42
end_define

begin_define
define|#
directive|define
name|REV_ID_VT6102_APOLLO
value|0x74
end_define

begin_define
define|#
directive|define
name|REV_ID_VT6105_A0
value|0x80
end_define

begin_define
define|#
directive|define
name|REV_ID_VT6105_B0
value|0x83
end_define

begin_define
define|#
directive|define
name|REV_ID_VT6105_LOM
value|0x8A
end_define

begin_define
define|#
directive|define
name|REV_ID_VT6107_A0
value|0x8C
end_define

begin_define
define|#
directive|define
name|REV_ID_VT6107_A1
value|0x8D
end_define

begin_define
define|#
directive|define
name|REV_ID_VT6105M_A0
value|0x90
end_define

begin_define
define|#
directive|define
name|REV_ID_VT6105M_B1
value|0x94
end_define

begin_comment
comment|/*  * PCI low memory base and low I/O base register, and  * other PCI registers.  */
end_comment

begin_define
define|#
directive|define
name|VR_PCI_VENDOR_ID
value|0x00
end_define

begin_define
define|#
directive|define
name|VR_PCI_DEVICE_ID
value|0x02
end_define

begin_define
define|#
directive|define
name|VR_PCI_COMMAND
value|0x04
end_define

begin_define
define|#
directive|define
name|VR_PCI_STATUS
value|0x06
end_define

begin_define
define|#
directive|define
name|VR_PCI_REVID
value|0x08
end_define

begin_define
define|#
directive|define
name|VR_PCI_CLASSCODE
value|0x09
end_define

begin_define
define|#
directive|define
name|VR_PCI_LATENCY_TIMER
value|0x0D
end_define

begin_define
define|#
directive|define
name|VR_PCI_HEADER_TYPE
value|0x0E
end_define

begin_define
define|#
directive|define
name|VR_PCI_LOIO
value|0x10
end_define

begin_define
define|#
directive|define
name|VR_PCI_LOMEM
value|0x14
end_define

begin_define
define|#
directive|define
name|VR_PCI_BIOSROM
value|0x30
end_define

begin_define
define|#
directive|define
name|VR_PCI_INTLINE
value|0x3C
end_define

begin_define
define|#
directive|define
name|VR_PCI_INTPIN
value|0x3D
end_define

begin_define
define|#
directive|define
name|VR_PCI_MINGNT
value|0x3E
end_define

begin_define
define|#
directive|define
name|VR_PCI_MINLAT
value|0x0F
end_define

begin_define
define|#
directive|define
name|VR_PCI_RESETOPT
value|0x48
end_define

begin_define
define|#
directive|define
name|VR_PCI_EEPROM_DATA
value|0x4C
end_define

begin_define
define|#
directive|define
name|VR_PCI_MODE0
value|0x50
end_define

begin_define
define|#
directive|define
name|VR_PCI_MODE2
value|0x52
end_define

begin_define
define|#
directive|define
name|VR_PCI_MODE3
value|0x53
end_define

begin_define
define|#
directive|define
name|VR_MODE2_PCEROPT
value|0x80
end_define

begin_comment
comment|/* VT6102 only */
end_comment

begin_define
define|#
directive|define
name|VR_MODE2_DISABT
value|0x40
end_define

begin_define
define|#
directive|define
name|VR_MODE2_MRDPL
value|0x08
end_define

begin_comment
comment|/* VT6107A1 and above */
end_comment

begin_define
define|#
directive|define
name|VR_MODE2_MODE10T
value|0x02
end_define

begin_define
define|#
directive|define
name|VR_MODE3_XONOPT
value|0x80
end_define

begin_define
define|#
directive|define
name|VR_MODE3_TPACEN
value|0x40
end_define

begin_define
define|#
directive|define
name|VR_MODE3_BACKOPT
value|0x20
end_define

begin_define
define|#
directive|define
name|VR_MODE3_DLTSEL
value|0x10
end_define

begin_define
define|#
directive|define
name|VR_MODE3_MIIDMY
value|0x08
end_define

begin_define
define|#
directive|define
name|VR_MODE3_MIION
value|0x04
end_define

begin_comment
comment|/* power management registers */
end_comment

begin_define
define|#
directive|define
name|VR_PCI_CAPID
value|0xDC
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|VR_PCI_NEXTPTR
value|0xDD
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|VR_PCI_PWRMGMTCAP
value|0xDE
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|VR_PCI_PWRMGMTCTRL
value|0xE0
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|VR_PSTATE_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|VR_PSTATE_D0
value|0x0000
end_define

begin_define
define|#
directive|define
name|VR_PSTATE_D1
value|0x0002
end_define

begin_define
define|#
directive|define
name|VR_PSTATE_D2
value|0x0002
end_define

begin_define
define|#
directive|define
name|VR_PSTATE_D3
value|0x0003
end_define

begin_define
define|#
directive|define
name|VR_PME_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|VR_PME_STATUS
value|0x8000
end_define

begin_define
define|#
directive|define
name|VR_RX_RING_CNT
value|128
end_define

begin_define
define|#
directive|define
name|VR_TX_RING_CNT
value|128
end_define

begin_define
define|#
directive|define
name|VR_TX_RING_SIZE
value|sizeof(struct vr_desc) * VR_TX_RING_CNT
end_define

begin_define
define|#
directive|define
name|VR_RX_RING_SIZE
value|sizeof(struct vr_desc) * VR_RX_RING_CNT
end_define

begin_define
define|#
directive|define
name|VR_RING_ALIGN
value|sizeof(struct vr_desc)
end_define

begin_define
define|#
directive|define
name|VR_RX_ALIGN
value|sizeof(uint32_t)
end_define

begin_define
define|#
directive|define
name|VR_MAXFRAGS
value|8
end_define

begin_define
define|#
directive|define
name|VR_TX_INTR_THRESH
value|8
end_define

begin_define
define|#
directive|define
name|VR_ADDR_LO
parameter_list|(
name|x
parameter_list|)
value|((uint64_t)(x)& 0xffffffff)
end_define

begin_define
define|#
directive|define
name|VR_ADDR_HI
parameter_list|(
name|x
parameter_list|)
value|((uint64_t)(x)>> 32)
end_define

begin_define
define|#
directive|define
name|VR_TX_RING_ADDR
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|((sc)->vr_rdata.vr_tx_ring_paddr + sizeof(struct vr_desc) * (i))
end_define

begin_define
define|#
directive|define
name|VR_RX_RING_ADDR
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|((sc)->vr_rdata.vr_rx_ring_paddr + sizeof(struct vr_desc) * (i))
end_define

begin_define
define|#
directive|define
name|VR_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = (((x) + 1) % y)
end_define

begin_struct
struct|struct
name|vr_txdesc
block|{
name|struct
name|mbuf
modifier|*
name|tx_m
decl_stmt|;
name|bus_dmamap_t
name|tx_dmamap
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vr_rxdesc
block|{
name|struct
name|mbuf
modifier|*
name|rx_m
decl_stmt|;
name|bus_dmamap_t
name|rx_dmamap
decl_stmt|;
name|struct
name|vr_desc
modifier|*
name|desc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vr_chain_data
block|{
name|bus_dma_tag_t
name|vr_parent_tag
decl_stmt|;
name|bus_dma_tag_t
name|vr_tx_tag
decl_stmt|;
name|struct
name|vr_txdesc
name|vr_txdesc
index|[
name|VR_TX_RING_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|vr_rx_tag
decl_stmt|;
name|struct
name|vr_rxdesc
name|vr_rxdesc
index|[
name|VR_RX_RING_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|vr_tx_ring_tag
decl_stmt|;
name|bus_dma_tag_t
name|vr_rx_ring_tag
decl_stmt|;
name|bus_dmamap_t
name|vr_tx_ring_map
decl_stmt|;
name|bus_dmamap_t
name|vr_rx_ring_map
decl_stmt|;
name|bus_dmamap_t
name|vr_rx_sparemap
decl_stmt|;
name|int
name|vr_tx_pkts
decl_stmt|;
name|int
name|vr_tx_prod
decl_stmt|;
name|int
name|vr_tx_cons
decl_stmt|;
name|int
name|vr_tx_cnt
decl_stmt|;
name|int
name|vr_rx_cons
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vr_ring_data
block|{
name|struct
name|vr_desc
modifier|*
name|vr_rx_ring
decl_stmt|;
name|struct
name|vr_desc
modifier|*
name|vr_tx_ring
decl_stmt|;
name|bus_addr_t
name|vr_rx_ring_paddr
decl_stmt|;
name|bus_addr_t
name|vr_tx_ring_paddr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vr_statistics
block|{
name|uint64_t
name|tx_ok
decl_stmt|;
name|uint64_t
name|rx_ok
decl_stmt|;
name|uint32_t
name|tx_errors
decl_stmt|;
name|uint32_t
name|rx_errors
decl_stmt|;
name|uint32_t
name|rx_no_buffers
decl_stmt|;
name|uint32_t
name|rx_no_mbufs
decl_stmt|;
name|uint32_t
name|rx_crc_errors
decl_stmt|;
name|uint32_t
name|rx_alignment
decl_stmt|;
name|uint32_t
name|rx_fifo_overflows
decl_stmt|;
name|uint32_t
name|rx_giants
decl_stmt|;
name|uint32_t
name|rx_runts
decl_stmt|;
name|uint32_t
name|tx_abort
decl_stmt|;
name|uint32_t
name|tx_collisions
decl_stmt|;
name|uint32_t
name|tx_late_collisions
decl_stmt|;
name|uint32_t
name|tx_underrun
decl_stmt|;
name|uint32_t
name|bus_errors
decl_stmt|;
name|uint32_t
name|num_restart
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vr_softc
block|{
name|struct
name|ifnet
modifier|*
name|vr_ifp
decl_stmt|;
comment|/* interface info */
name|device_t
name|vr_dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|vr_res
decl_stmt|;
name|int
name|vr_res_id
decl_stmt|;
name|int
name|vr_res_type
decl_stmt|;
name|struct
name|resource
modifier|*
name|vr_irq
decl_stmt|;
name|void
modifier|*
name|vr_intrhand
decl_stmt|;
name|device_t
name|vr_miibus
decl_stmt|;
name|uint8_t
name|vr_revid
decl_stmt|;
comment|/* Rhine chip revision */
name|int
name|vr_flags
decl_stmt|;
comment|/* See VR_F_* below */
define|#
directive|define
name|VR_F_RESTART
value|0x0001
comment|/* Restart unit on next tick */
define|#
directive|define
name|VR_F_TXPAUSE
value|0x0010
define|#
directive|define
name|VR_F_SUSPENDED
value|0x2000
define|#
directive|define
name|VR_F_DETACHED
value|0x4000
define|#
directive|define
name|VR_F_LINK
value|0x8000
name|int
name|vr_if_flags
decl_stmt|;
name|struct
name|vr_chain_data
name|vr_cdata
decl_stmt|;
name|struct
name|vr_ring_data
name|vr_rdata
decl_stmt|;
name|struct
name|vr_statistics
name|vr_stat
decl_stmt|;
name|struct
name|callout
name|vr_stat_callout
decl_stmt|;
name|struct
name|mtx
name|vr_mtx
decl_stmt|;
name|int
name|vr_quirks
decl_stmt|;
name|int
name|vr_watchdog_timer
decl_stmt|;
name|int
name|vr_txthresh
decl_stmt|;
ifdef|#
directive|ifdef
name|DEVICE_POLLING
name|int
name|rxcycles
decl_stmt|;
endif|#
directive|endif
name|struct
name|task
name|vr_inttask
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VR_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->vr_mtx)
end_define

begin_define
define|#
directive|define
name|VR_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->vr_mtx)
end_define

begin_define
define|#
directive|define
name|VR_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->vr_mtx, MA_OWNED)
end_define

begin_comment
comment|/*  * register space access macros  */
end_comment

begin_define
define|#
directive|define
name|CSR_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|bus_write_4(sc->vr_res, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|bus_write_2(sc->vr_res, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|bus_write_1(sc->vr_res, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_READ_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
value|bus_read_2(sc->vr_res, reg)
end_define

begin_define
define|#
directive|define
name|CSR_READ_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
value|bus_read_1(sc->vr_res, reg)
end_define

begin_define
define|#
directive|define
name|VR_SETBIT
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
value|CSR_WRITE_1(sc, reg, CSR_READ_1(sc, reg) | (x))
end_define

begin_define
define|#
directive|define
name|VR_CLRBIT
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
value|CSR_WRITE_1(sc, reg, CSR_READ_1(sc, reg)& ~(x))
end_define

begin_define
define|#
directive|define
name|VR_SETBIT16
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
value|CSR_WRITE_2(sc, reg, CSR_READ_2(sc, reg) | (x))
end_define

begin_define
define|#
directive|define
name|VR_CLRBIT16
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
value|CSR_WRITE_2(sc, reg, CSR_READ_2(sc, reg)& ~(x))
end_define

begin_define
define|#
directive|define
name|VR_MCAST_CAM
value|0
end_define

begin_define
define|#
directive|define
name|VR_VLAN_CAM
value|1
end_define

end_unit

