begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * RealTek 8129/8139 register offsets  */
end_comment

begin_define
define|#
directive|define
name|RL_IDR0
value|0x0000
end_define

begin_comment
comment|/* ID register 0 (station addr) */
end_comment

begin_define
define|#
directive|define
name|RL_IDR1
value|0x0001
end_define

begin_comment
comment|/* Must use 32-bit accesses (?) */
end_comment

begin_define
define|#
directive|define
name|RL_IDR2
value|0x0002
end_define

begin_define
define|#
directive|define
name|RL_IDR3
value|0x0003
end_define

begin_define
define|#
directive|define
name|RL_IDR4
value|0x0004
end_define

begin_define
define|#
directive|define
name|RL_IDR5
value|0x0005
end_define

begin_comment
comment|/* 0006-0007 reserved */
end_comment

begin_define
define|#
directive|define
name|RL_MAR0
value|0x0008
end_define

begin_comment
comment|/* Multicast hash table */
end_comment

begin_define
define|#
directive|define
name|RL_MAR1
value|0x0009
end_define

begin_define
define|#
directive|define
name|RL_MAR2
value|0x000A
end_define

begin_define
define|#
directive|define
name|RL_MAR3
value|0x000B
end_define

begin_define
define|#
directive|define
name|RL_MAR4
value|0x000C
end_define

begin_define
define|#
directive|define
name|RL_MAR5
value|0x000D
end_define

begin_define
define|#
directive|define
name|RL_MAR6
value|0x000E
end_define

begin_define
define|#
directive|define
name|RL_MAR7
value|0x000F
end_define

begin_define
define|#
directive|define
name|RL_TXSTAT0
value|0x0010
end_define

begin_comment
comment|/* status of TX descriptor 0 */
end_comment

begin_define
define|#
directive|define
name|RL_TXSTAT1
value|0x0014
end_define

begin_comment
comment|/* status of TX descriptor 1 */
end_comment

begin_define
define|#
directive|define
name|RL_TXSTAT2
value|0x0018
end_define

begin_comment
comment|/* status of TX descriptor 2 */
end_comment

begin_define
define|#
directive|define
name|RL_TXSTAT3
value|0x001C
end_define

begin_comment
comment|/* status of TX descriptor 3 */
end_comment

begin_define
define|#
directive|define
name|RL_TXADDR0
value|0x0020
end_define

begin_comment
comment|/* address of TX descriptor 0 */
end_comment

begin_define
define|#
directive|define
name|RL_TXADDR1
value|0x0024
end_define

begin_comment
comment|/* address of TX descriptor 1 */
end_comment

begin_define
define|#
directive|define
name|RL_TXADDR2
value|0x0028
end_define

begin_comment
comment|/* address of TX descriptor 2 */
end_comment

begin_define
define|#
directive|define
name|RL_TXADDR3
value|0x002C
end_define

begin_comment
comment|/* address of TX descriptor 3 */
end_comment

begin_define
define|#
directive|define
name|RL_RXADDR
value|0x0030
end_define

begin_comment
comment|/* RX ring start address */
end_comment

begin_define
define|#
directive|define
name|RL_RX_EARLY_BYTES
value|0x0034
end_define

begin_comment
comment|/* RX early byte count */
end_comment

begin_define
define|#
directive|define
name|RL_RX_EARLY_STAT
value|0x0036
end_define

begin_comment
comment|/* RX early status */
end_comment

begin_define
define|#
directive|define
name|RL_COMMAND
value|0x0037
end_define

begin_comment
comment|/* command register */
end_comment

begin_define
define|#
directive|define
name|RL_CURRXADDR
value|0x0038
end_define

begin_comment
comment|/* current address of packet read */
end_comment

begin_define
define|#
directive|define
name|RL_CURRXBUF
value|0x003A
end_define

begin_comment
comment|/* current RX buffer address */
end_comment

begin_define
define|#
directive|define
name|RL_IMR
value|0x003C
end_define

begin_comment
comment|/* interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|RL_ISR
value|0x003E
end_define

begin_comment
comment|/* interrupt status register */
end_comment

begin_define
define|#
directive|define
name|RL_TXCFG
value|0x0040
end_define

begin_comment
comment|/* transmit config */
end_comment

begin_define
define|#
directive|define
name|RL_RXCFG
value|0x0044
end_define

begin_comment
comment|/* receive config */
end_comment

begin_define
define|#
directive|define
name|RL_TIMERCNT
value|0x0048
end_define

begin_comment
comment|/* timer count register */
end_comment

begin_define
define|#
directive|define
name|RL_MISSEDPKT
value|0x004C
end_define

begin_comment
comment|/* missed packet counter */
end_comment

begin_define
define|#
directive|define
name|RL_EECMD
value|0x0050
end_define

begin_comment
comment|/* EEPROM command register */
end_comment

begin_define
define|#
directive|define
name|RL_CFG0
value|0x0051
end_define

begin_comment
comment|/* config register #0 */
end_comment

begin_define
define|#
directive|define
name|RL_CFG1
value|0x0052
end_define

begin_comment
comment|/* config register #1 */
end_comment

begin_comment
comment|/* 0053-0057 reserved */
end_comment

begin_define
define|#
directive|define
name|RL_MEDIASTAT
value|0x0058
end_define

begin_comment
comment|/* media status register (8139) */
end_comment

begin_comment
comment|/* 0059-005A reserved */
end_comment

begin_define
define|#
directive|define
name|RL_MII
value|0x005A
end_define

begin_comment
comment|/* 8129 chip only */
end_comment

begin_define
define|#
directive|define
name|RL_HALTCLK
value|0x005B
end_define

begin_define
define|#
directive|define
name|RL_MULTIINTR
value|0x005C
end_define

begin_comment
comment|/* multiple interrupt */
end_comment

begin_define
define|#
directive|define
name|RL_PCIREV
value|0x005E
end_define

begin_comment
comment|/* PCI revision value */
end_comment

begin_comment
comment|/* 005F reserved */
end_comment

begin_define
define|#
directive|define
name|RL_TXSTAT_ALL
value|0x0060
end_define

begin_comment
comment|/* TX status of all descriptors */
end_comment

begin_comment
comment|/* Direct PHY access registers only available on 8139 */
end_comment

begin_define
define|#
directive|define
name|RL_BMCR
value|0x0062
end_define

begin_comment
comment|/* PHY basic mode control */
end_comment

begin_define
define|#
directive|define
name|RL_BMSR
value|0x0064
end_define

begin_comment
comment|/* PHY basic mode status */
end_comment

begin_define
define|#
directive|define
name|RL_ANAR
value|0x0066
end_define

begin_comment
comment|/* PHY autoneg advert */
end_comment

begin_define
define|#
directive|define
name|RL_LPAR
value|0x0068
end_define

begin_comment
comment|/* PHY link partner ability */
end_comment

begin_define
define|#
directive|define
name|RL_ANER
value|0x006A
end_define

begin_comment
comment|/* PHY autoneg expansion */
end_comment

begin_define
define|#
directive|define
name|RL_DISCCNT
value|0x006C
end_define

begin_comment
comment|/* disconnect counter */
end_comment

begin_define
define|#
directive|define
name|RL_FALSECAR
value|0x006E
end_define

begin_comment
comment|/* false carrier counter */
end_comment

begin_define
define|#
directive|define
name|RL_NWAYTST
value|0x0070
end_define

begin_comment
comment|/* NWAY test register */
end_comment

begin_define
define|#
directive|define
name|RL_RX_ER
value|0x0072
end_define

begin_comment
comment|/* RX_ER counter */
end_comment

begin_define
define|#
directive|define
name|RL_CSCFG
value|0x0074
end_define

begin_comment
comment|/* CS configuration register */
end_comment

begin_comment
comment|/*  * TX config register bits  */
end_comment

begin_define
define|#
directive|define
name|RL_TXCFG_CLRABRT
value|0x00000001
end_define

begin_comment
comment|/* retransmit aborted pkt */
end_comment

begin_define
define|#
directive|define
name|RL_TXCFG_MAXDMA
value|0x00000700
end_define

begin_comment
comment|/* max DMA burst size */
end_comment

begin_define
define|#
directive|define
name|RL_TXCFG_CRCAPPEND
value|0x00010000
end_define

begin_comment
comment|/* CRC append (0 = yes) */
end_comment

begin_define
define|#
directive|define
name|RL_TXCFG_LOOPBKTST
value|0x00060000
end_define

begin_comment
comment|/* loopback test */
end_comment

begin_define
define|#
directive|define
name|RL_TXCFG_IFG
value|0x03000000
end_define

begin_comment
comment|/* interframe gap */
end_comment

begin_define
define|#
directive|define
name|RL_TXDMA_16BYTES
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RL_TXDMA_32BYTES
value|0x00000100
end_define

begin_define
define|#
directive|define
name|RL_TXDMA_64BYTES
value|0x00000200
end_define

begin_define
define|#
directive|define
name|RL_TXDMA_128BYTES
value|0x00000300
end_define

begin_define
define|#
directive|define
name|RL_TXDMA_256BYTES
value|0x00000400
end_define

begin_define
define|#
directive|define
name|RL_TXDMA_512BYTES
value|0x00000500
end_define

begin_define
define|#
directive|define
name|RL_TXDMA_1024BYTES
value|0x00000600
end_define

begin_define
define|#
directive|define
name|RL_TXDMA_2048BYTES
value|0x00000700
end_define

begin_comment
comment|/*  * Transmit descriptor status register bits.  */
end_comment

begin_define
define|#
directive|define
name|RL_TXSTAT_LENMASK
value|0x00001FFF
end_define

begin_define
define|#
directive|define
name|RL_TXSTAT_OWN
value|0x00002000
end_define

begin_define
define|#
directive|define
name|RL_TXSTAT_TX_UNDERRUN
value|0x00004000
end_define

begin_define
define|#
directive|define
name|RL_TXSTAT_TX_OK
value|0x00008000
end_define

begin_define
define|#
directive|define
name|RL_TXSTAT_EARLY_THRESH
value|0x003F0000
end_define

begin_define
define|#
directive|define
name|RL_TXSTAT_COLLCNT
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|RL_TXSTAT_CARR_HBEAT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|RL_TXSTAT_OUTOFWIN
value|0x20000000
end_define

begin_define
define|#
directive|define
name|RL_TXSTAT_TXABRT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|RL_TXSTAT_CARRLOSS
value|0x80000000
end_define

begin_comment
comment|/*  * Interrupt status register bits.  */
end_comment

begin_define
define|#
directive|define
name|RL_ISR_RX_OK
value|0x0001
end_define

begin_define
define|#
directive|define
name|RL_ISR_RX_ERR
value|0x0002
end_define

begin_define
define|#
directive|define
name|RL_ISR_TX_OK
value|0x0004
end_define

begin_define
define|#
directive|define
name|RL_ISR_TX_ERR
value|0x0008
end_define

begin_define
define|#
directive|define
name|RL_ISR_RX_OVERRUN
value|0x0010
end_define

begin_define
define|#
directive|define
name|RL_ISR_PKT_UNDERRUN
value|0x0020
end_define

begin_define
define|#
directive|define
name|RL_ISR_FIFO_OFLOW
value|0x0040
end_define

begin_comment
comment|/* 8139 only */
end_comment

begin_define
define|#
directive|define
name|RL_ISR_PCS_TIMEOUT
value|0x4000
end_define

begin_comment
comment|/* 8129 only */
end_comment

begin_define
define|#
directive|define
name|RL_ISR_SYSTEM_ERR
value|0x8000
end_define

begin_define
define|#
directive|define
name|RL_INTRS
define|\
value|(RL_ISR_TX_OK|RL_ISR_RX_OK|RL_ISR_RX_ERR|RL_ISR_TX_ERR|		\ 	RL_ISR_RX_OVERRUN|RL_ISR_PKT_UNDERRUN|RL_ISR_FIFO_OFLOW|	\ 	RL_ISR_PCS_TIMEOUT|RL_ISR_SYSTEM_ERR)
end_define

begin_comment
comment|/*  * Media status register. (8139 only)  */
end_comment

begin_define
define|#
directive|define
name|RL_MEDIASTAT_RXPAUSE
value|0x01
end_define

begin_define
define|#
directive|define
name|RL_MEDIASTAT_TXPAUSE
value|0x02
end_define

begin_define
define|#
directive|define
name|RL_MEDIASTAT_LINK
value|0x04
end_define

begin_define
define|#
directive|define
name|RL_MEDIASTAT_SPEED10
value|0x08
end_define

begin_define
define|#
directive|define
name|RL_MEDIASTAT_RXFLOWCTL
value|0x40
end_define

begin_comment
comment|/* duplex mode */
end_comment

begin_define
define|#
directive|define
name|RL_MEDIASTAT_TXFLOWCTL
value|0x80
end_define

begin_comment
comment|/* duplex mode */
end_comment

begin_comment
comment|/*  * Receive config register.  */
end_comment

begin_define
define|#
directive|define
name|RL_RXCFG_RX_ALLPHYS
value|0x00000001
end_define

begin_comment
comment|/* accept all nodes */
end_comment

begin_define
define|#
directive|define
name|RL_RXCFG_RX_INDIV
value|0x00000002
end_define

begin_comment
comment|/* match filter */
end_comment

begin_define
define|#
directive|define
name|RL_RXCFG_RX_MULTI
value|0x00000004
end_define

begin_comment
comment|/* accept all multicast */
end_comment

begin_define
define|#
directive|define
name|RL_RXCFG_RX_BROAD
value|0x00000008
end_define

begin_comment
comment|/* accept all broadcast */
end_comment

begin_define
define|#
directive|define
name|RL_RXCFG_RX_RUNT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RL_RXCFG_RX_ERRPKT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|RL_RXCFG_WRAP
value|0x00000080
end_define

begin_define
define|#
directive|define
name|RL_RXCFG_MAXDMA
value|0x00000700
end_define

begin_define
define|#
directive|define
name|RL_RXCFG_BUFSZ
value|0x00001800
end_define

begin_define
define|#
directive|define
name|RL_RXCFG_FIFOTHRESH
value|0x0000E000
end_define

begin_define
define|#
directive|define
name|RL_RXCFG_EARLYTHRESH
value|0x07000000
end_define

begin_define
define|#
directive|define
name|RL_RXDMA_16BYTES
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RL_RXDMA_32BYTES
value|0x00000100
end_define

begin_define
define|#
directive|define
name|RL_RXDMA_64BYTES
value|0x00000200
end_define

begin_define
define|#
directive|define
name|RL_RXDMA_128BYTES
value|0x00000300
end_define

begin_define
define|#
directive|define
name|RL_RXDMA_256BYTES
value|0x00000400
end_define

begin_define
define|#
directive|define
name|RL_RXDMA_512BYTES
value|0x00000500
end_define

begin_define
define|#
directive|define
name|RL_RXDMA_1024BYTES
value|0x00000600
end_define

begin_define
define|#
directive|define
name|RL_RXDMA_UNLIMITED
value|0x00000700
end_define

begin_define
define|#
directive|define
name|RL_RXBUF_8
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RL_RXBUF_16
value|0x00000800
end_define

begin_define
define|#
directive|define
name|RL_RXBUF_32
value|0x00001000
end_define

begin_define
define|#
directive|define
name|RL_RXBUF_64
value|0x00001800
end_define

begin_define
define|#
directive|define
name|RL_RXFIFO_16BYTES
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RL_RXFIFO_32BYTES
value|0x00002000
end_define

begin_define
define|#
directive|define
name|RL_RXFIFO_64BYTES
value|0x00004000
end_define

begin_define
define|#
directive|define
name|RL_RXFIFO_128BYTES
value|0x00006000
end_define

begin_define
define|#
directive|define
name|RL_RXFIFO_256BYTES
value|0x00008000
end_define

begin_define
define|#
directive|define
name|RL_RXFIFO_512BYTES
value|0x0000A000
end_define

begin_define
define|#
directive|define
name|RL_RXFIFO_1024BYTES
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|RL_RXFIFO_NOTHRESH
value|0x0000E000
end_define

begin_comment
comment|/*  * Bits in RX status header (included with RX'ed packet  * in ring buffer).  */
end_comment

begin_define
define|#
directive|define
name|RL_RXSTAT_RXOK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RL_RXSTAT_ALIGNERR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RL_RXSTAT_CRCERR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|RL_RXSTAT_GIANT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|RL_RXSTAT_RUNT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RL_RXSTAT_BADSYM
value|0x00000020
end_define

begin_define
define|#
directive|define
name|RL_RXSTAT_BROAD
value|0x00002000
end_define

begin_define
define|#
directive|define
name|RL_RXSTAT_INDIV
value|0x00004000
end_define

begin_define
define|#
directive|define
name|RL_RXSTAT_MULTI
value|0x00008000
end_define

begin_define
define|#
directive|define
name|RL_RXSTAT_LENMASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|RL_RXSTAT_UNFINISHED
value|0xFFF0
end_define

begin_comment
comment|/* DMA still in progress */
end_comment

begin_comment
comment|/*  * Command register.  */
end_comment

begin_define
define|#
directive|define
name|RL_CMD_EMPTY_RXBUF
value|0x0001
end_define

begin_define
define|#
directive|define
name|RL_CMD_TX_ENB
value|0x0004
end_define

begin_define
define|#
directive|define
name|RL_CMD_RX_ENB
value|0x0008
end_define

begin_define
define|#
directive|define
name|RL_CMD_RESET
value|0x0010
end_define

begin_comment
comment|/*  * EEPROM control register  */
end_comment

begin_define
define|#
directive|define
name|RL_EE_DATAOUT
value|0x01
end_define

begin_comment
comment|/* Data out */
end_comment

begin_define
define|#
directive|define
name|RL_EE_DATAIN
value|0x02
end_define

begin_comment
comment|/* Data in */
end_comment

begin_define
define|#
directive|define
name|RL_EE_CLK
value|0x04
end_define

begin_comment
comment|/* clock */
end_comment

begin_define
define|#
directive|define
name|RL_EE_SEL
value|0x08
end_define

begin_comment
comment|/* chip select */
end_comment

begin_define
define|#
directive|define
name|RL_EE_MODE
value|(0x40|0x80)
end_define

begin_define
define|#
directive|define
name|RL_EEMODE_OFF
value|0x00
end_define

begin_define
define|#
directive|define
name|RL_EEMODE_AUTOLOAD
value|0x40
end_define

begin_define
define|#
directive|define
name|RL_EEMODE_PROGRAM
value|0x80
end_define

begin_define
define|#
directive|define
name|RL_EEMODE_WRITECFG
value|(0x80|0x40)
end_define

begin_comment
comment|/* 9346 EEPROM commands */
end_comment

begin_define
define|#
directive|define
name|RL_EECMD_WRITE
value|0x140
end_define

begin_define
define|#
directive|define
name|RL_EECMD_READ
value|0x180
end_define

begin_define
define|#
directive|define
name|RL_EECMD_ERASE
value|0x1c0
end_define

begin_define
define|#
directive|define
name|RL_EE_ID
value|0x00
end_define

begin_define
define|#
directive|define
name|RL_EE_PCI_VID
value|0x01
end_define

begin_define
define|#
directive|define
name|RL_EE_PCI_DID
value|0x02
end_define

begin_comment
comment|/* Location of station address inside EEPROM */
end_comment

begin_define
define|#
directive|define
name|RL_EE_EADDR
value|0x07
end_define

begin_comment
comment|/*  * MII register (8129 only)  */
end_comment

begin_define
define|#
directive|define
name|RL_MII_CLK
value|0x01
end_define

begin_define
define|#
directive|define
name|RL_MII_DATAIN
value|0x02
end_define

begin_define
define|#
directive|define
name|RL_MII_DATAOUT
value|0x04
end_define

begin_define
define|#
directive|define
name|RL_MII_DIR
value|0x80
end_define

begin_comment
comment|/* 0 == input, 1 == output */
end_comment

begin_comment
comment|/*  * Config 0 register  */
end_comment

begin_define
define|#
directive|define
name|RL_CFG0_ROM0
value|0x01
end_define

begin_define
define|#
directive|define
name|RL_CFG0_ROM1
value|0x02
end_define

begin_define
define|#
directive|define
name|RL_CFG0_ROM2
value|0x04
end_define

begin_define
define|#
directive|define
name|RL_CFG0_PL0
value|0x08
end_define

begin_define
define|#
directive|define
name|RL_CFG0_PL1
value|0x10
end_define

begin_define
define|#
directive|define
name|RL_CFG0_10MBPS
value|0x20
end_define

begin_comment
comment|/* 10 Mbps internal mode */
end_comment

begin_define
define|#
directive|define
name|RL_CFG0_PCS
value|0x40
end_define

begin_define
define|#
directive|define
name|RL_CFG0_SCR
value|0x80
end_define

begin_comment
comment|/*  * Config 1 register  */
end_comment

begin_define
define|#
directive|define
name|RL_CFG1_PWRDWN
value|0x01
end_define

begin_define
define|#
directive|define
name|RL_CFG1_SLEEP
value|0x02
end_define

begin_define
define|#
directive|define
name|RL_CFG1_IOMAP
value|0x04
end_define

begin_define
define|#
directive|define
name|RL_CFG1_MEMMAP
value|0x08
end_define

begin_define
define|#
directive|define
name|RL_CFG1_RSVD
value|0x10
end_define

begin_define
define|#
directive|define
name|RL_CFG1_DRVLOAD
value|0x20
end_define

begin_define
define|#
directive|define
name|RL_CFG1_LED0
value|0x40
end_define

begin_define
define|#
directive|define
name|RL_CFG1_FULLDUPLEX
value|0x40
end_define

begin_comment
comment|/* 8129 only */
end_comment

begin_define
define|#
directive|define
name|RL_CFG1_LED1
value|0x80
end_define

begin_comment
comment|/*  * The RealTek doesn't use a fragment-based descriptor mechanism.  * Instead, there are only four register sets, each or which represents  * one 'descriptor.' Basically, each TX descriptor is just a contiguous  * packet buffer (32-bit aligned!) and we place the buffer addresses in  * the registers so the chip knows where they are.  *  * We can sort of kludge together the same kind of buffer management  * used in previous drivers, but we have to do buffer copies almost all  * the time, so it doesn't really buy us much.  *  * For reception, there's just one large buffer where the chip stores  * all received packets.  */
end_comment

begin_define
define|#
directive|define
name|RL_RX_BUF_SZ
value|RL_RXBUF_64
end_define

begin_define
define|#
directive|define
name|RL_RXBUFLEN
value|(1<< ((RL_RX_BUF_SZ>> 11) + 13))
end_define

begin_define
define|#
directive|define
name|RL_TX_LIST_CNT
value|4
end_define

begin_define
define|#
directive|define
name|RL_MIN_FRAMELEN
value|60
end_define

begin_define
define|#
directive|define
name|RL_TXTHRESH
parameter_list|(
name|x
parameter_list|)
value|((x)<< 11)
end_define

begin_define
define|#
directive|define
name|RL_TX_THRESH_INIT
value|96
end_define

begin_define
define|#
directive|define
name|RL_RX_FIFOTHRESH
value|RL_RXFIFO_256BYTES
end_define

begin_define
define|#
directive|define
name|RL_RX_MAXDMA
value|RL_RXDMA_UNLIMITED
end_define

begin_define
define|#
directive|define
name|RL_TX_MAXDMA
value|RL_TXDMA_2048BYTES
end_define

begin_define
define|#
directive|define
name|RL_RXCFG_CONFIG
value|(RL_RX_FIFOTHRESH|RL_RX_MAXDMA|RL_RX_BUF_SZ)
end_define

begin_define
define|#
directive|define
name|RL_TXCFG_CONFIG
value|(RL_TXCFG_IFG|RL_TX_MAXDMA)
end_define

begin_define
define|#
directive|define
name|RL_ETHER_ALIGN
value|2
end_define

begin_struct
struct|struct
name|rl_chain_data
block|{
name|u_int16_t
name|cur_rx
decl_stmt|;
name|caddr_t
name|rl_rx_buf
decl_stmt|;
name|caddr_t
name|rl_rx_buf_ptr
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|rl_tx_chain
index|[
name|RL_TX_LIST_CNT
index|]
decl_stmt|;
name|u_int8_t
name|last_tx
decl_stmt|;
name|u_int8_t
name|cur_tx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RL_INC
parameter_list|(
name|x
parameter_list|)
value|(x = (x + 1) % RL_TX_LIST_CNT)
end_define

begin_define
define|#
directive|define
name|RL_CUR_TXADDR
parameter_list|(
name|x
parameter_list|)
value|((x->rl_cdata.cur_tx * 4) + RL_TXADDR0)
end_define

begin_define
define|#
directive|define
name|RL_CUR_TXSTAT
parameter_list|(
name|x
parameter_list|)
value|((x->rl_cdata.cur_tx * 4) + RL_TXSTAT0)
end_define

begin_define
define|#
directive|define
name|RL_CUR_TXMBUF
parameter_list|(
name|x
parameter_list|)
value|(x->rl_cdata.rl_tx_chain[x->rl_cdata.cur_tx])
end_define

begin_define
define|#
directive|define
name|RL_LAST_TXADDR
parameter_list|(
name|x
parameter_list|)
value|((x->rl_cdata.last_tx * 4) + RL_TXADDR0)
end_define

begin_define
define|#
directive|define
name|RL_LAST_TXSTAT
parameter_list|(
name|x
parameter_list|)
value|((x->rl_cdata.last_tx * 4) + RL_TXSTAT0)
end_define

begin_define
define|#
directive|define
name|RL_LAST_TXMBUF
parameter_list|(
name|x
parameter_list|)
value|(x->rl_cdata.rl_tx_chain[x->rl_cdata.last_tx])
end_define

begin_struct
struct|struct
name|rl_type
block|{
name|u_int16_t
name|rl_vid
decl_stmt|;
name|u_int16_t
name|rl_did
decl_stmt|;
name|char
modifier|*
name|rl_name
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rl_mii_frame
block|{
name|u_int8_t
name|mii_stdelim
decl_stmt|;
name|u_int8_t
name|mii_opcode
decl_stmt|;
name|u_int8_t
name|mii_phyaddr
decl_stmt|;
name|u_int8_t
name|mii_regaddr
decl_stmt|;
name|u_int8_t
name|mii_turnaround
decl_stmt|;
name|u_int16_t
name|mii_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * MII constants  */
end_comment

begin_define
define|#
directive|define
name|RL_MII_STARTDELIM
value|0x01
end_define

begin_define
define|#
directive|define
name|RL_MII_READOP
value|0x02
end_define

begin_define
define|#
directive|define
name|RL_MII_WRITEOP
value|0x01
end_define

begin_define
define|#
directive|define
name|RL_MII_TURNAROUND
value|0x02
end_define

begin_define
define|#
directive|define
name|RL_8129
value|1
end_define

begin_define
define|#
directive|define
name|RL_8139
value|2
end_define

begin_struct
struct|struct
name|rl_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
comment|/* interface info */
name|bus_space_handle_t
name|rl_bhandle
decl_stmt|;
comment|/* bus space handle */
name|bus_space_tag_t
name|rl_btag
decl_stmt|;
comment|/* bus space tag */
name|struct
name|resource
modifier|*
name|rl_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|rl_irq
decl_stmt|;
name|void
modifier|*
name|rl_intrhand
decl_stmt|;
name|device_t
name|rl_miibus
decl_stmt|;
name|u_int8_t
name|rl_unit
decl_stmt|;
comment|/* interface number */
name|u_int8_t
name|rl_type
decl_stmt|;
name|u_int8_t
name|rl_stats_no_timeout
decl_stmt|;
name|int
name|rl_txthresh
decl_stmt|;
name|struct
name|rl_chain_data
name|rl_cdata
decl_stmt|;
name|struct
name|callout_handle
name|rl_stat_ch
decl_stmt|;
block|}
struct|;
end_struct

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
define|\
value|bus_space_write_4(sc->rl_btag, sc->rl_bhandle, reg, val)
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
define|\
value|bus_space_write_2(sc->rl_btag, sc->rl_bhandle, reg, val)
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
define|\
value|bus_space_write_1(sc->rl_btag, sc->rl_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_READ_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4(sc->rl_btag, sc->rl_bhandle, reg)
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
define|\
value|bus_space_read_2(sc->rl_btag, sc->rl_bhandle, reg)
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
define|\
value|bus_space_read_1(sc->rl_btag, sc->rl_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|RL_TIMEOUT
value|1000
end_define

begin_comment
comment|/*  * General constants that are fun to know.  *  * RealTek PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|RT_VENDORID
value|0x10EC
end_define

begin_comment
comment|/*  * RealTek chip device IDs.  */
end_comment

begin_define
define|#
directive|define
name|RT_DEVICEID_8129
value|0x8129
end_define

begin_define
define|#
directive|define
name|RT_DEVICEID_8139
value|0x8139
end_define

begin_comment
comment|/*  * Accton PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|ACCTON_VENDORID
value|0x1113
end_define

begin_comment
comment|/*  * Accton MPX 5030/5038 device ID.  */
end_comment

begin_define
define|#
directive|define
name|ACCTON_DEVICEID_5030
value|0x1211
end_define

begin_comment
comment|/*  * Delta Electronics Vendor ID.  */
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
name|DELTA_DEVICEID_8139
value|0x1360
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
name|ADDTRON_DEVICEID_8139
value|0x1360
end_define

begin_comment
comment|/*  * D-Link vendor ID.  */
end_comment

begin_define
define|#
directive|define
name|DLINK_VENDORID
value|0x1186
end_define

begin_comment
comment|/*  * D-Link DFE-530TX+ device ID  */
end_comment

begin_define
define|#
directive|define
name|DLINK_DEVICEID_530TXPLUS
value|0x1300
end_define

begin_comment
comment|/*  * PCI low memory base and low I/O base register, and  * other PCI registers.  */
end_comment

begin_define
define|#
directive|define
name|RL_PCI_VENDOR_ID
value|0x00
end_define

begin_define
define|#
directive|define
name|RL_PCI_DEVICE_ID
value|0x02
end_define

begin_define
define|#
directive|define
name|RL_PCI_COMMAND
value|0x04
end_define

begin_define
define|#
directive|define
name|RL_PCI_STATUS
value|0x06
end_define

begin_define
define|#
directive|define
name|RL_PCI_CLASSCODE
value|0x09
end_define

begin_define
define|#
directive|define
name|RL_PCI_LATENCY_TIMER
value|0x0D
end_define

begin_define
define|#
directive|define
name|RL_PCI_HEADER_TYPE
value|0x0E
end_define

begin_define
define|#
directive|define
name|RL_PCI_LOIO
value|0x10
end_define

begin_define
define|#
directive|define
name|RL_PCI_LOMEM
value|0x14
end_define

begin_define
define|#
directive|define
name|RL_PCI_BIOSROM
value|0x30
end_define

begin_define
define|#
directive|define
name|RL_PCI_INTLINE
value|0x3C
end_define

begin_define
define|#
directive|define
name|RL_PCI_INTPIN
value|0x3D
end_define

begin_define
define|#
directive|define
name|RL_PCI_MINGNT
value|0x3E
end_define

begin_define
define|#
directive|define
name|RL_PCI_MINLAT
value|0x0F
end_define

begin_define
define|#
directive|define
name|RL_PCI_RESETOPT
value|0x48
end_define

begin_define
define|#
directive|define
name|RL_PCI_EEPROM_DATA
value|0x4C
end_define

begin_define
define|#
directive|define
name|RL_PCI_CAPID
value|0x50
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|RL_PCI_NEXTPTR
value|0x51
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|RL_PCI_PWRMGMTCAP
value|0x52
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|RL_PCI_PWRMGMTCTRL
value|0x54
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|RL_PSTATE_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|RL_PSTATE_D0
value|0x0000
end_define

begin_define
define|#
directive|define
name|RL_PSTATE_D1
value|0x0002
end_define

begin_define
define|#
directive|define
name|RL_PSTATE_D2
value|0x0002
end_define

begin_define
define|#
directive|define
name|RL_PSTATE_D3
value|0x0003
end_define

begin_define
define|#
directive|define
name|RL_PME_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|RL_PME_STATUS
value|0x8000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha__
end_ifdef

begin_undef
undef|#
directive|undef
name|vtophys
end_undef

begin_define
define|#
directive|define
name|vtophys
parameter_list|(
name|va
parameter_list|)
value|alpha_XXX_dmamap((vm_offset_t)va)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

