begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998-2003  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_comment
comment|/* RTL8139/RTL8139C+ only */
end_comment

begin_define
define|#
directive|define
name|RL_8139_CFG0
value|0x0051
end_define

begin_comment
comment|/* config register #0 */
end_comment

begin_define
define|#
directive|define
name|RL_8139_CFG1
value|0x0052
end_define

begin_comment
comment|/* config register #1 */
end_comment

begin_define
define|#
directive|define
name|RL_8139_CFG3
value|0x0059
end_define

begin_comment
comment|/* config register #3 */
end_comment

begin_define
define|#
directive|define
name|RL_8139_CFG4
value|0x005A
end_define

begin_comment
comment|/* config register #4 */
end_comment

begin_define
define|#
directive|define
name|RL_8139_CFG5
value|0x00D8
end_define

begin_comment
comment|/* config register #5 */
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

begin_define
define|#
directive|define
name|RL_CFG2
value|0x0053
end_define

begin_comment
comment|/* config register #2 */
end_comment

begin_define
define|#
directive|define
name|RL_CFG3
value|0x0054
end_define

begin_comment
comment|/* config register #3 */
end_comment

begin_define
define|#
directive|define
name|RL_CFG4
value|0x0055
end_define

begin_comment
comment|/* config register #4 */
end_comment

begin_define
define|#
directive|define
name|RL_CFG5
value|0x0056
end_define

begin_comment
comment|/* config register #5 */
end_comment

begin_comment
comment|/* 0057 reserved */
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
comment|/*  * When operating in special C+ mode, some of the registers in an  * 8139C+ chip have different definitions. These are also used for  * the 8169 gigE chip.  */
end_comment

begin_define
define|#
directive|define
name|RL_DUMPSTATS_LO
value|0x0010
end_define

begin_comment
comment|/* counter dump command register */
end_comment

begin_define
define|#
directive|define
name|RL_DUMPSTATS_HI
value|0x0014
end_define

begin_comment
comment|/* counter dump command register */
end_comment

begin_define
define|#
directive|define
name|RL_TXLIST_ADDR_LO
value|0x0020
end_define

begin_comment
comment|/* 64 bits, 256 byte alignment */
end_comment

begin_define
define|#
directive|define
name|RL_TXLIST_ADDR_HI
value|0x0024
end_define

begin_comment
comment|/* 64 bits, 256 byte alignment */
end_comment

begin_define
define|#
directive|define
name|RL_TXLIST_ADDR_HPRIO_LO
value|0x0028
end_define

begin_comment
comment|/* 64 bits, 256 byte alignment */
end_comment

begin_define
define|#
directive|define
name|RL_TXLIST_ADDR_HPRIO_HI
value|0x002C
end_define

begin_comment
comment|/* 64 bits, 256 byte alignment */
end_comment

begin_define
define|#
directive|define
name|RL_CFG2
value|0x0053
end_define

begin_define
define|#
directive|define
name|RL_TIMERINT
value|0x0054
end_define

begin_comment
comment|/* interrupt on timer expire */
end_comment

begin_define
define|#
directive|define
name|RL_TXSTART
value|0x00D9
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|RL_CPLUS_CMD
value|0x00E0
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|RL_RXLIST_ADDR_LO
value|0x00E4
end_define

begin_comment
comment|/* 64 bits, 256 byte alignment */
end_comment

begin_define
define|#
directive|define
name|RL_RXLIST_ADDR_HI
value|0x00E8
end_define

begin_comment
comment|/* 64 bits, 256 byte alignment */
end_comment

begin_define
define|#
directive|define
name|RL_EARLY_TX_THRESH
value|0x00EC
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_comment
comment|/*  * Registers specific to the 8169 gigE chip  */
end_comment

begin_define
define|#
directive|define
name|RL_GTXSTART
value|0x0038
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|RL_TIMERINT_8169
value|0x0058
end_define

begin_comment
comment|/* different offset than 8139 */
end_comment

begin_define
define|#
directive|define
name|RL_PHYAR
value|0x0060
end_define

begin_define
define|#
directive|define
name|RL_TBICSR
value|0x0064
end_define

begin_define
define|#
directive|define
name|RL_TBI_ANAR
value|0x0068
end_define

begin_define
define|#
directive|define
name|RL_TBI_LPAR
value|0x006A
end_define

begin_define
define|#
directive|define
name|RL_GMEDIASTAT
value|0x006C
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|RL_MACDBG
value|0x006D
end_define

begin_comment
comment|/* 8 bits, 8168C SPIN2 only */
end_comment

begin_define
define|#
directive|define
name|RL_GPIO
value|0x006E
end_define

begin_comment
comment|/* 8 bits, 8168C SPIN2 only */
end_comment

begin_define
define|#
directive|define
name|RL_PMCH
value|0x006F
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|RL_MAXRXPKTLEN
value|0x00DA
end_define

begin_comment
comment|/* 16 bits, chip multiplies by 8 */
end_comment

begin_define
define|#
directive|define
name|RL_INTRMOD
value|0x00E2
end_define

begin_comment
comment|/* 16 bits */
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
name|RL_TXCFG_QUEUE_EMPTY
value|0x00000800
end_define

begin_comment
comment|/* 8168E-VL or higher */
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
name|RL_TXCFG_IFG2
value|0x00080000
end_define

begin_comment
comment|/* 8169 only */
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
name|RL_TXCFG_HWREV
value|0x7CC00000
end_define

begin_define
define|#
directive|define
name|RL_LOOPTEST_OFF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RL_LOOPTEST_ON
value|0x00020000
end_define

begin_define
define|#
directive|define
name|RL_LOOPTEST_ON_CPLUS
value|0x00060000
end_define

begin_comment
comment|/* Known revision codes. */
end_comment

begin_define
define|#
directive|define
name|RL_HWREV_8169
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8169S
value|0x00800000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8110S
value|0x04000000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8169_8110SB
value|0x10000000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8169_8110SC
value|0x18000000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8401E
value|0x24000000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8102EL
value|0x24800000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8102EL_SPIN1
value|0x24C00000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8168D
value|0x28000000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8168DP
value|0x28800000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8168E
value|0x2C000000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8168E_VL
value|0x2C800000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8168B_SPIN1
value|0x30000000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8100E
value|0x30800000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8101E
value|0x34000000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8102E
value|0x34800000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8103E
value|0x34C00000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8168B_SPIN2
value|0x38000000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8168B_SPIN3
value|0x38400000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8168C
value|0x3C000000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8168C_SPIN2
value|0x3C400000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8168CP
value|0x3C800000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8105E
value|0x40800000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8105E_SPIN1
value|0x40C00000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8402
value|0x44000000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8168F
value|0x48000000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8411
value|0x48800000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8139
value|0x60000000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8139A
value|0x70000000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8139AG
value|0x70800000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8139B
value|0x78000000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8130
value|0x7C000000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8139C
value|0x74000000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8139D
value|0x74400000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8139CPLUS
value|0x74800000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8101
value|0x74C00000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8100
value|0x78800000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8169_8110SBL
value|0x7CC00000
end_define

begin_define
define|#
directive|define
name|RL_HWREV_8169_8110SCE
value|0x98000000
end_define

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
name|RL_ISR_LINKCHG
value|0x0020
end_define

begin_comment
comment|/* 8169 only */
end_comment

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
name|RL_ISR_TX_DESC_UNAVAIL
value|0x0080
end_define

begin_comment
comment|/* C+ only */
end_comment

begin_define
define|#
directive|define
name|RL_ISR_SWI
value|0x0100
end_define

begin_comment
comment|/* C+ only */
end_comment

begin_define
define|#
directive|define
name|RL_ISR_CABLE_LEN_CHGD
value|0x2000
end_define

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
name|RL_ISR_TIMEOUT_EXPIRED
value|0x4000
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|RE_TX_MODERATION
end_ifdef

begin_define
define|#
directive|define
name|RL_INTRS_CPLUS
define|\
value|(RL_ISR_RX_OK|RL_ISR_RX_ERR|RL_ISR_TX_ERR|			\ 	RL_ISR_RX_OVERRUN|RL_ISR_PKT_UNDERRUN|RL_ISR_FIFO_OFLOW|	\ 	RL_ISR_PCS_TIMEOUT|RL_ISR_SYSTEM_ERR|RL_ISR_TIMEOUT_EXPIRED)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RL_INTRS_CPLUS
define|\
value|(RL_ISR_RX_OK|RL_ISR_RX_ERR|RL_ISR_TX_ERR|RL_ISR_TX_OK|		\ 	RL_ISR_RX_OVERRUN|RL_ISR_PKT_UNDERRUN|RL_ISR_FIFO_OFLOW|	\ 	RL_ISR_PCS_TIMEOUT|RL_ISR_SYSTEM_ERR|RL_ISR_TIMEOUT_EXPIRED)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|RL_CMD_STOPREQ
value|0x0080
end_define

begin_comment
comment|/*  * Twister register values.  These are completely undocumented and derived  * from public sources.  */
end_comment

begin_define
define|#
directive|define
name|RL_CSCFG_LINK_OK
value|0x0400
end_define

begin_define
define|#
directive|define
name|RL_CSCFG_CHANGE
value|0x0800
end_define

begin_define
define|#
directive|define
name|RL_CSCFG_STATUS
value|0xf000
end_define

begin_define
define|#
directive|define
name|RL_CSCFG_ROW3
value|0x7000
end_define

begin_define
define|#
directive|define
name|RL_CSCFG_ROW2
value|0x3000
end_define

begin_define
define|#
directive|define
name|RL_CSCFG_ROW1
value|0x1000
end_define

begin_define
define|#
directive|define
name|RL_CSCFG_LINK_DOWN_OFF_CMD
value|0x03c0
end_define

begin_define
define|#
directive|define
name|RL_CSCFG_LINK_DOWN_CMD
value|0xf3c0
end_define

begin_define
define|#
directive|define
name|RL_NWAYTST_RESET
value|0
end_define

begin_define
define|#
directive|define
name|RL_NWAYTST_CBL_TEST
value|0x20
end_define

begin_define
define|#
directive|define
name|RL_PARA78
value|0x78
end_define

begin_define
define|#
directive|define
name|RL_PARA78_DEF
value|0x78fa8388
end_define

begin_define
define|#
directive|define
name|RL_PARA7C
value|0x7C
end_define

begin_define
define|#
directive|define
name|RL_PARA7C_DEF
value|0xcb38de43
end_define

begin_define
define|#
directive|define
name|RL_PARA7C_RETUNE
value|0xfb38de03
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
name|RL_9346_ADDR_LEN
value|6
end_define

begin_comment
comment|/* 93C46 1K: 128x16 */
end_comment

begin_define
define|#
directive|define
name|RL_9356_ADDR_LEN
value|8
end_define

begin_comment
comment|/* 93C56 2K: 256x16 */
end_comment

begin_define
define|#
directive|define
name|RL_9346_WRITE
value|0x5
end_define

begin_define
define|#
directive|define
name|RL_9346_READ
value|0x6
end_define

begin_define
define|#
directive|define
name|RL_9346_ERASE
value|0x7
end_define

begin_define
define|#
directive|define
name|RL_9346_EWEN
value|0x4
end_define

begin_define
define|#
directive|define
name|RL_9346_EWEN_ADDR
value|0x30
end_define

begin_define
define|#
directive|define
name|RL_9456_EWDS
value|0x4
end_define

begin_define
define|#
directive|define
name|RL_9346_EWDS_ADDR
value|0x00
end_define

begin_define
define|#
directive|define
name|RL_EECMD_WRITE
value|0x140
end_define

begin_define
define|#
directive|define
name|RL_EECMD_READ_6BIT
value|0x180
end_define

begin_define
define|#
directive|define
name|RL_EECMD_READ_8BIT
value|0x600
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
name|RL_CFG1_PME
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
name|RL_CFG1_VPDEN
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
name|RL_CFG1_LWACT
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
comment|/*  * Config 2 register  */
end_comment

begin_define
define|#
directive|define
name|RL_CFG2_PCI33MHZ
value|0x00
end_define

begin_define
define|#
directive|define
name|RL_CFG2_PCI66MHZ
value|0x01
end_define

begin_define
define|#
directive|define
name|RL_CFG2_PCI64BIT
value|0x08
end_define

begin_define
define|#
directive|define
name|RL_CFG2_AUXPWR
value|0x10
end_define

begin_define
define|#
directive|define
name|RL_CFG2_MSI
value|0x20
end_define

begin_comment
comment|/*  * Config 3 register  */
end_comment

begin_define
define|#
directive|define
name|RL_CFG3_GRANTSEL
value|0x80
end_define

begin_define
define|#
directive|define
name|RL_CFG3_WOL_MAGIC
value|0x20
end_define

begin_define
define|#
directive|define
name|RL_CFG3_WOL_LINK
value|0x10
end_define

begin_define
define|#
directive|define
name|RL_CFG3_JUMBO_EN0
value|0x04
end_define

begin_comment
comment|/* RTL8168C or later. */
end_comment

begin_define
define|#
directive|define
name|RL_CFG3_FAST_B2B
value|0x01
end_define

begin_comment
comment|/*  * Config 4 register  */
end_comment

begin_define
define|#
directive|define
name|RL_CFG4_LWPTN
value|0x04
end_define

begin_define
define|#
directive|define
name|RL_CFG4_LWPME
value|0x10
end_define

begin_define
define|#
directive|define
name|RL_CFG4_JUMBO_EN1
value|0x02
end_define

begin_comment
comment|/* RTL8168C or later. */
end_comment

begin_comment
comment|/*  * Config 5 register  */
end_comment

begin_define
define|#
directive|define
name|RL_CFG5_WOL_BCAST
value|0x40
end_define

begin_define
define|#
directive|define
name|RL_CFG5_WOL_MCAST
value|0x20
end_define

begin_define
define|#
directive|define
name|RL_CFG5_WOL_UCAST
value|0x10
end_define

begin_define
define|#
directive|define
name|RL_CFG5_WOL_LANWAKE
value|0x02
end_define

begin_define
define|#
directive|define
name|RL_CFG5_PME_STS
value|0x01
end_define

begin_comment
comment|/*  * 8139C+ register definitions  */
end_comment

begin_comment
comment|/* RL_DUMPSTATS_LO register */
end_comment

begin_define
define|#
directive|define
name|RL_DUMPSTATS_START
value|0x00000008
end_define

begin_comment
comment|/* Transmit start register */
end_comment

begin_define
define|#
directive|define
name|RL_TXSTART_SWI
value|0x01
end_define

begin_comment
comment|/* generate TX interrupt */
end_comment

begin_define
define|#
directive|define
name|RL_TXSTART_START
value|0x40
end_define

begin_comment
comment|/* start normal queue transmit */
end_comment

begin_define
define|#
directive|define
name|RL_TXSTART_HPRIO_START
value|0x80
end_define

begin_comment
comment|/* start hi prio queue transmit */
end_comment

begin_comment
comment|/*  * Config 2 register, 8139C+/8169/8169S/8110S only  */
end_comment

begin_define
define|#
directive|define
name|RL_CFG2_BUSFREQ
value|0x07
end_define

begin_define
define|#
directive|define
name|RL_CFG2_BUSWIDTH
value|0x08
end_define

begin_define
define|#
directive|define
name|RL_CFG2_AUXPWRSTS
value|0x10
end_define

begin_define
define|#
directive|define
name|RL_BUSFREQ_33MHZ
value|0x00
end_define

begin_define
define|#
directive|define
name|RL_BUSFREQ_66MHZ
value|0x01
end_define

begin_define
define|#
directive|define
name|RL_BUSWIDTH_32BITS
value|0x00
end_define

begin_define
define|#
directive|define
name|RL_BUSWIDTH_64BITS
value|0x08
end_define

begin_comment
comment|/* C+ mode command register */
end_comment

begin_define
define|#
directive|define
name|RL_CPLUSCMD_TXENB
value|0x0001
end_define

begin_comment
comment|/* enable C+ transmit mode */
end_comment

begin_define
define|#
directive|define
name|RL_CPLUSCMD_RXENB
value|0x0002
end_define

begin_comment
comment|/* enable C+ receive mode */
end_comment

begin_define
define|#
directive|define
name|RL_CPLUSCMD_PCI_MRW
value|0x0008
end_define

begin_comment
comment|/* enable PCI multi-read/write */
end_comment

begin_define
define|#
directive|define
name|RL_CPLUSCMD_PCI_DAC
value|0x0010
end_define

begin_comment
comment|/* PCI dual-address cycle only */
end_comment

begin_define
define|#
directive|define
name|RL_CPLUSCMD_RXCSUM_ENB
value|0x0020
end_define

begin_comment
comment|/* enable RX checksum offload */
end_comment

begin_define
define|#
directive|define
name|RL_CPLUSCMD_VLANSTRIP
value|0x0040
end_define

begin_comment
comment|/* enable VLAN tag stripping */
end_comment

begin_define
define|#
directive|define
name|RL_CPLUSCMD_MACSTAT_DIS
value|0x0080
end_define

begin_comment
comment|/* 8168B/C/CP */
end_comment

begin_define
define|#
directive|define
name|RL_CPLUSCMD_ASF
value|0x0100
end_define

begin_comment
comment|/* 8168C/CP */
end_comment

begin_define
define|#
directive|define
name|RL_CPLUSCMD_DBG_SEL
value|0x0200
end_define

begin_comment
comment|/* 8168C/CP */
end_comment

begin_define
define|#
directive|define
name|RL_CPLUSCMD_FORCE_TXFC
value|0x0400
end_define

begin_comment
comment|/* 8168C/CP */
end_comment

begin_define
define|#
directive|define
name|RL_CPLUSCMD_FORCE_RXFC
value|0x0800
end_define

begin_comment
comment|/* 8168C/CP */
end_comment

begin_define
define|#
directive|define
name|RL_CPLUSCMD_FORCE_HDPX
value|0x1000
end_define

begin_comment
comment|/* 8168C/CP */
end_comment

begin_define
define|#
directive|define
name|RL_CPLUSCMD_NORMAL_MODE
value|0x2000
end_define

begin_comment
comment|/* 8168C/CP */
end_comment

begin_define
define|#
directive|define
name|RL_CPLUSCMD_DBG_ENB
value|0x4000
end_define

begin_comment
comment|/* 8168C/CP */
end_comment

begin_define
define|#
directive|define
name|RL_CPLUSCMD_BIST_ENB
value|0x8000
end_define

begin_comment
comment|/* 8168C/CP */
end_comment

begin_comment
comment|/* C+ early transmit threshold */
end_comment

begin_define
define|#
directive|define
name|RL_EARLYTXTHRESH_CNT
value|0x003F
end_define

begin_comment
comment|/* byte count times 8 */
end_comment

begin_comment
comment|/* Timer interrupt register */
end_comment

begin_define
define|#
directive|define
name|RL_TIMERINT_8169_VAL
value|0x00001FFF
end_define

begin_define
define|#
directive|define
name|RL_TIMER_MIN
value|0
end_define

begin_define
define|#
directive|define
name|RL_TIMER_MAX
value|65
end_define

begin_comment
comment|/* 65.528us */
end_comment

begin_define
define|#
directive|define
name|RL_TIMER_DEFAULT
value|RL_TIMER_MAX
end_define

begin_define
define|#
directive|define
name|RL_TIMER_PCIE_CLK
value|125
end_define

begin_comment
comment|/* 125MHZ */
end_comment

begin_define
define|#
directive|define
name|RL_USECS
parameter_list|(
name|x
parameter_list|)
value|((x) * RL_TIMER_PCIE_CLK)
end_define

begin_comment
comment|/*  * Gigabit PHY access register (8169 only)  */
end_comment

begin_define
define|#
directive|define
name|RL_PHYAR_PHYDATA
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|RL_PHYAR_PHYREG
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|RL_PHYAR_BUSY
value|0x80000000
end_define

begin_comment
comment|/*  * Gigabit media status (8169 only)  */
end_comment

begin_define
define|#
directive|define
name|RL_GMEDIASTAT_FDX
value|0x01
end_define

begin_comment
comment|/* full duplex */
end_comment

begin_define
define|#
directive|define
name|RL_GMEDIASTAT_LINK
value|0x02
end_define

begin_comment
comment|/* link up */
end_comment

begin_define
define|#
directive|define
name|RL_GMEDIASTAT_10MBPS
value|0x04
end_define

begin_comment
comment|/* 10mps link */
end_comment

begin_define
define|#
directive|define
name|RL_GMEDIASTAT_100MBPS
value|0x08
end_define

begin_comment
comment|/* 100mbps link */
end_comment

begin_define
define|#
directive|define
name|RL_GMEDIASTAT_1000MBPS
value|0x10
end_define

begin_comment
comment|/* gigE link */
end_comment

begin_define
define|#
directive|define
name|RL_GMEDIASTAT_RXFLOW
value|0x20
end_define

begin_comment
comment|/* RX flow control on */
end_comment

begin_define
define|#
directive|define
name|RL_GMEDIASTAT_TXFLOW
value|0x40
end_define

begin_comment
comment|/* TX flow control on */
end_comment

begin_define
define|#
directive|define
name|RL_GMEDIASTAT_TBI
value|0x80
end_define

begin_comment
comment|/* TBI enabled */
end_comment

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
name|RL_TX_8139_BUF_ALIGN
value|4
end_define

begin_define
define|#
directive|define
name|RL_RX_8139_BUF_ALIGN
value|8
end_define

begin_define
define|#
directive|define
name|RL_RX_8139_BUF_RESERVE
value|sizeof(int64_t)
end_define

begin_define
define|#
directive|define
name|RL_RX_8139_BUF_GUARD_SZ
define|\
value|(ETHER_MAX_LEN + ETHER_VLAN_ENCAP_LEN + RL_RX_8139_BUF_RESERVE)
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
value|RL_RXFIFO_NOTHRESH
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

begin_comment
comment|/*  * re(4) hardware ip4csum-tx could be mangled with 28 bytes or less IP packets.  */
end_comment

begin_define
define|#
directive|define
name|RL_IP4CSUMTX_MINLEN
value|28
end_define

begin_define
define|#
directive|define
name|RL_IP4CSUMTX_PADLEN
value|(ETHER_HDR_LEN + RL_IP4CSUMTX_MINLEN)
end_define

begin_struct
struct|struct
name|rl_chain_data
block|{
name|uint16_t
name|cur_rx
decl_stmt|;
name|uint8_t
modifier|*
name|rl_rx_buf
decl_stmt|;
name|uint8_t
modifier|*
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
name|bus_dmamap_t
name|rl_tx_dmamap
index|[
name|RL_TX_LIST_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|rl_tx_tag
decl_stmt|;
name|bus_dma_tag_t
name|rl_rx_tag
decl_stmt|;
name|bus_dmamap_t
name|rl_rx_dmamap
decl_stmt|;
name|bus_addr_t
name|rl_rx_buf_paddr
decl_stmt|;
name|uint8_t
name|last_tx
decl_stmt|;
name|uint8_t
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
name|RL_CUR_DMAMAP
parameter_list|(
name|x
parameter_list|)
value|(x->rl_cdata.rl_tx_dmamap[x->rl_cdata.cur_tx])
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

begin_define
define|#
directive|define
name|RL_LAST_DMAMAP
parameter_list|(
name|x
parameter_list|)
value|(x->rl_cdata.rl_tx_dmamap[x->rl_cdata.last_tx])
end_define

begin_struct
struct|struct
name|rl_type
block|{
name|uint16_t
name|rl_vid
decl_stmt|;
name|uint16_t
name|rl_did
decl_stmt|;
name|int
name|rl_basetype
decl_stmt|;
specifier|const
name|char
modifier|*
name|rl_name
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rl_hwrev
block|{
name|uint32_t
name|rl_rev
decl_stmt|;
name|int
name|rl_type
decl_stmt|;
specifier|const
name|char
modifier|*
name|rl_desc
decl_stmt|;
name|int
name|rl_max_mtu
decl_stmt|;
block|}
struct|;
end_struct

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

begin_define
define|#
directive|define
name|RL_8139CPLUS
value|3
end_define

begin_define
define|#
directive|define
name|RL_8169
value|4
end_define

begin_define
define|#
directive|define
name|RL_ISCPLUS
parameter_list|(
name|x
parameter_list|)
value|((x)->rl_type == RL_8139CPLUS ||	\ 				 (x)->rl_type == RL_8169)
end_define

begin_comment
comment|/*  * The 8139C+ and 8160 gigE chips support descriptor-based TX  * and RX. In fact, they even support TCP large send. Descriptors  * must be allocated in contiguous blocks that are aligned on a  * 256-byte boundary. The rings can hold a maximum of 64 descriptors.  */
end_comment

begin_comment
comment|/*  * RX/TX descriptor definition. When large send mode is enabled, the  * lower 11 bits of the TX rl_cmd word are used to hold the MSS, and  * the checksum offload bits are disabled. The structure layout is  * the same for RX and TX descriptors  */
end_comment

begin_struct
struct|struct
name|rl_desc
block|{
name|uint32_t
name|rl_cmdstat
decl_stmt|;
name|uint32_t
name|rl_vlanctl
decl_stmt|;
name|uint32_t
name|rl_bufaddr_lo
decl_stmt|;
name|uint32_t
name|rl_bufaddr_hi
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RL_TDESC_CMD_FRAGLEN
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|RL_TDESC_CMD_TCPCSUM
value|0x00010000
end_define

begin_comment
comment|/* TCP checksum enable */
end_comment

begin_define
define|#
directive|define
name|RL_TDESC_CMD_UDPCSUM
value|0x00020000
end_define

begin_comment
comment|/* UDP checksum enable */
end_comment

begin_define
define|#
directive|define
name|RL_TDESC_CMD_IPCSUM
value|0x00040000
end_define

begin_comment
comment|/* IP header checksum enable */
end_comment

begin_define
define|#
directive|define
name|RL_TDESC_CMD_MSSVAL
value|0x07FF0000
end_define

begin_comment
comment|/* Large send MSS value */
end_comment

begin_define
define|#
directive|define
name|RL_TDESC_CMD_MSSVAL_SHIFT
value|16
end_define

begin_comment
comment|/* Large send MSS value shift */
end_comment

begin_define
define|#
directive|define
name|RL_TDESC_CMD_LGSEND
value|0x08000000
end_define

begin_comment
comment|/* TCP large send enb */
end_comment

begin_define
define|#
directive|define
name|RL_TDESC_CMD_EOF
value|0x10000000
end_define

begin_comment
comment|/* end of frame marker */
end_comment

begin_define
define|#
directive|define
name|RL_TDESC_CMD_SOF
value|0x20000000
end_define

begin_comment
comment|/* start of frame marker */
end_comment

begin_define
define|#
directive|define
name|RL_TDESC_CMD_EOR
value|0x40000000
end_define

begin_comment
comment|/* end of ring marker */
end_comment

begin_define
define|#
directive|define
name|RL_TDESC_CMD_OWN
value|0x80000000
end_define

begin_comment
comment|/* chip owns descriptor */
end_comment

begin_define
define|#
directive|define
name|RL_TDESC_VLANCTL_TAG
value|0x00020000
end_define

begin_comment
comment|/* Insert VLAN tag */
end_comment

begin_define
define|#
directive|define
name|RL_TDESC_VLANCTL_DATA
value|0x0000FFFF
end_define

begin_comment
comment|/* TAG data */
end_comment

begin_comment
comment|/* RTL8168C/RTL8168CP/RTL8111C/RTL8111CP */
end_comment

begin_define
define|#
directive|define
name|RL_TDESC_CMD_UDPCSUMV2
value|0x80000000
end_define

begin_define
define|#
directive|define
name|RL_TDESC_CMD_TCPCSUMV2
value|0x40000000
end_define

begin_define
define|#
directive|define
name|RL_TDESC_CMD_IPCSUMV2
value|0x20000000
end_define

begin_define
define|#
directive|define
name|RL_TDESC_CMD_MSSVALV2
value|0x1FFC0000
end_define

begin_define
define|#
directive|define
name|RL_TDESC_CMD_MSSVALV2_SHIFT
value|18
end_define

begin_comment
comment|/*  * Error bits are valid only on the last descriptor of a frame  * (i.e. RL_TDESC_CMD_EOF == 1)  */
end_comment

begin_define
define|#
directive|define
name|RL_TDESC_STAT_COLCNT
value|0x000F0000
end_define

begin_comment
comment|/* collision count */
end_comment

begin_define
define|#
directive|define
name|RL_TDESC_STAT_EXCESSCOL
value|0x00100000
end_define

begin_comment
comment|/* excessive collisions */
end_comment

begin_define
define|#
directive|define
name|RL_TDESC_STAT_LINKFAIL
value|0x00200000
end_define

begin_comment
comment|/* link faulure */
end_comment

begin_define
define|#
directive|define
name|RL_TDESC_STAT_OWINCOL
value|0x00400000
end_define

begin_comment
comment|/* out-of-window collision */
end_comment

begin_define
define|#
directive|define
name|RL_TDESC_STAT_TXERRSUM
value|0x00800000
end_define

begin_comment
comment|/* transmit error summary */
end_comment

begin_define
define|#
directive|define
name|RL_TDESC_STAT_UNDERRUN
value|0x02000000
end_define

begin_comment
comment|/* TX underrun occured */
end_comment

begin_define
define|#
directive|define
name|RL_TDESC_STAT_OWN
value|0x80000000
end_define

begin_comment
comment|/*  * RX descriptor cmd/vlan definitions  */
end_comment

begin_define
define|#
directive|define
name|RL_RDESC_CMD_EOR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|RL_RDESC_CMD_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|RL_RDESC_CMD_BUFLEN
value|0x00001FFF
end_define

begin_define
define|#
directive|define
name|RL_RDESC_STAT_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|RL_RDESC_STAT_EOR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|RL_RDESC_STAT_SOF
value|0x20000000
end_define

begin_define
define|#
directive|define
name|RL_RDESC_STAT_EOF
value|0x10000000
end_define

begin_define
define|#
directive|define
name|RL_RDESC_STAT_FRALIGN
value|0x08000000
end_define

begin_comment
comment|/* frame alignment error */
end_comment

begin_define
define|#
directive|define
name|RL_RDESC_STAT_MCAST
value|0x04000000
end_define

begin_comment
comment|/* multicast pkt received */
end_comment

begin_define
define|#
directive|define
name|RL_RDESC_STAT_UCAST
value|0x02000000
end_define

begin_comment
comment|/* unicast pkt received */
end_comment

begin_define
define|#
directive|define
name|RL_RDESC_STAT_BCAST
value|0x01000000
end_define

begin_comment
comment|/* broadcast pkt received */
end_comment

begin_define
define|#
directive|define
name|RL_RDESC_STAT_BUFOFLOW
value|0x00800000
end_define

begin_comment
comment|/* out of buffer space */
end_comment

begin_define
define|#
directive|define
name|RL_RDESC_STAT_FIFOOFLOW
value|0x00400000
end_define

begin_comment
comment|/* FIFO overrun */
end_comment

begin_define
define|#
directive|define
name|RL_RDESC_STAT_GIANT
value|0x00200000
end_define

begin_comment
comment|/* pkt> 4096 bytes */
end_comment

begin_define
define|#
directive|define
name|RL_RDESC_STAT_RXERRSUM
value|0x00100000
end_define

begin_comment
comment|/* RX error summary */
end_comment

begin_define
define|#
directive|define
name|RL_RDESC_STAT_RUNT
value|0x00080000
end_define

begin_comment
comment|/* runt packet received */
end_comment

begin_define
define|#
directive|define
name|RL_RDESC_STAT_CRCERR
value|0x00040000
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_define
define|#
directive|define
name|RL_RDESC_STAT_PROTOID
value|0x00030000
end_define

begin_comment
comment|/* Protocol type */
end_comment

begin_define
define|#
directive|define
name|RL_RDESC_STAT_UDP
value|0x00020000
end_define

begin_comment
comment|/* UDP, 8168C/CP, 8111C/CP */
end_comment

begin_define
define|#
directive|define
name|RL_RDESC_STAT_TCP
value|0x00010000
end_define

begin_comment
comment|/* TCP, 8168C/CP, 8111C/CP */
end_comment

begin_define
define|#
directive|define
name|RL_RDESC_STAT_IPSUMBAD
value|0x00008000
end_define

begin_comment
comment|/* IP header checksum bad */
end_comment

begin_define
define|#
directive|define
name|RL_RDESC_STAT_UDPSUMBAD
value|0x00004000
end_define

begin_comment
comment|/* UDP checksum bad */
end_comment

begin_define
define|#
directive|define
name|RL_RDESC_STAT_TCPSUMBAD
value|0x00002000
end_define

begin_comment
comment|/* TCP checksum bad */
end_comment

begin_define
define|#
directive|define
name|RL_RDESC_STAT_FRAGLEN
value|0x00001FFF
end_define

begin_comment
comment|/* RX'ed frame/frag len */
end_comment

begin_define
define|#
directive|define
name|RL_RDESC_STAT_GFRAGLEN
value|0x00003FFF
end_define

begin_comment
comment|/* RX'ed frame/frag len */
end_comment

begin_define
define|#
directive|define
name|RL_RDESC_STAT_ERRS
value|(RL_RDESC_STAT_GIANT|RL_RDESC_STAT_RUNT| \ 				 RL_RDESC_STAT_CRCERR)
end_define

begin_define
define|#
directive|define
name|RL_RDESC_VLANCTL_TAG
value|0x00010000
end_define

begin_comment
comment|/* VLAN tag available 						   (rl_vlandata valid)*/
end_comment

begin_define
define|#
directive|define
name|RL_RDESC_VLANCTL_DATA
value|0x0000FFFF
end_define

begin_comment
comment|/* TAG data */
end_comment

begin_comment
comment|/* RTL8168C/RTL8168CP/RTL8111C/RTL8111CP */
end_comment

begin_define
define|#
directive|define
name|RL_RDESC_IPV6
value|0x80000000
end_define

begin_define
define|#
directive|define
name|RL_RDESC_IPV4
value|0x40000000
end_define

begin_define
define|#
directive|define
name|RL_PROTOID_NONIP
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RL_PROTOID_TCPIP
value|0x00010000
end_define

begin_define
define|#
directive|define
name|RL_PROTOID_UDPIP
value|0x00020000
end_define

begin_define
define|#
directive|define
name|RL_PROTOID_IP
value|0x00030000
end_define

begin_define
define|#
directive|define
name|RL_TCPPKT
parameter_list|(
name|x
parameter_list|)
value|(((x)& RL_RDESC_STAT_PROTOID) == \ 				 RL_PROTOID_TCPIP)
end_define

begin_define
define|#
directive|define
name|RL_UDPPKT
parameter_list|(
name|x
parameter_list|)
value|(((x)& RL_RDESC_STAT_PROTOID) == \ 				 RL_PROTOID_UDPIP)
end_define

begin_comment
comment|/*  * Statistics counter structure (8139C+ and 8169 only)  */
end_comment

begin_struct
struct|struct
name|rl_stats
block|{
name|uint64_t
name|rl_tx_pkts
decl_stmt|;
name|uint64_t
name|rl_rx_pkts
decl_stmt|;
name|uint64_t
name|rl_tx_errs
decl_stmt|;
name|uint32_t
name|rl_rx_errs
decl_stmt|;
name|uint16_t
name|rl_missed_pkts
decl_stmt|;
name|uint16_t
name|rl_rx_framealign_errs
decl_stmt|;
name|uint32_t
name|rl_tx_onecoll
decl_stmt|;
name|uint32_t
name|rl_tx_multicolls
decl_stmt|;
name|uint64_t
name|rl_rx_ucasts
decl_stmt|;
name|uint64_t
name|rl_rx_bcasts
decl_stmt|;
name|uint32_t
name|rl_rx_mcasts
decl_stmt|;
name|uint16_t
name|rl_tx_aborts
decl_stmt|;
name|uint16_t
name|rl_rx_underruns
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Rx/Tx descriptor parameters (8139C+ and 8169 only)  *  * 8139C+  *  Number of descriptors supported : up to 64  *  Descriptor alignment : 256 bytes  *  Tx buffer : At least 4 bytes in length.  *  Rx buffer : At least 8 bytes in length and 8 bytes alignment required.  *  * 8169  *  Number of descriptors supported : up to 1024  *  Descriptor alignment : 256 bytes  *  Tx buffer : At least 4 bytes in length.  *  Rx buffer : At least 8 bytes in length and 8 bytes alignment required.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NO_STRICT_ALIGNMENT
end_ifndef

begin_define
define|#
directive|define
name|RE_FIXUP_RX
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RL_8169_TX_DESC_CNT
value|256
end_define

begin_define
define|#
directive|define
name|RL_8169_RX_DESC_CNT
value|256
end_define

begin_define
define|#
directive|define
name|RL_8139_TX_DESC_CNT
value|64
end_define

begin_define
define|#
directive|define
name|RL_8139_RX_DESC_CNT
value|64
end_define

begin_define
define|#
directive|define
name|RL_TX_DESC_CNT
value|RL_8169_TX_DESC_CNT
end_define

begin_define
define|#
directive|define
name|RL_RX_DESC_CNT
value|RL_8169_RX_DESC_CNT
end_define

begin_define
define|#
directive|define
name|RL_RX_JUMBO_DESC_CNT
value|RL_RX_DESC_CNT
end_define

begin_define
define|#
directive|define
name|RL_NTXSEGS
value|32
end_define

begin_define
define|#
directive|define
name|RL_RING_ALIGN
value|256
end_define

begin_define
define|#
directive|define
name|RL_DUMP_ALIGN
value|64
end_define

begin_define
define|#
directive|define
name|RL_IFQ_MAXLEN
value|512
end_define

begin_define
define|#
directive|define
name|RL_TX_DESC_NXT
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
value|((x + 1)& ((sc)->rl_ldata.rl_tx_desc_cnt - 1))
end_define

begin_define
define|#
directive|define
name|RL_TX_DESC_PRV
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
value|((x - 1)& ((sc)->rl_ldata.rl_tx_desc_cnt - 1))
end_define

begin_define
define|#
directive|define
name|RL_RX_DESC_NXT
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
value|((x + 1)& ((sc)->rl_ldata.rl_rx_desc_cnt - 1))
end_define

begin_define
define|#
directive|define
name|RL_OWN
parameter_list|(
name|x
parameter_list|)
value|(le32toh((x)->rl_cmdstat)& RL_RDESC_STAT_OWN)
end_define

begin_define
define|#
directive|define
name|RL_RXBYTES
parameter_list|(
name|x
parameter_list|)
value|(le32toh((x)->rl_cmdstat)& sc->rl_rxlenmask)
end_define

begin_define
define|#
directive|define
name|RL_PKTSZ
parameter_list|(
name|x
parameter_list|)
value|((x)
comment|/*>> 3*/
value|)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|RE_FIXUP_RX
end_ifdef

begin_define
define|#
directive|define
name|RE_ETHER_ALIGN
value|sizeof(uint64_t)
end_define

begin_define
define|#
directive|define
name|RE_RX_DESC_BUFLEN
value|(MCLBYTES - RE_ETHER_ALIGN)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RE_ETHER_ALIGN
value|0
end_define

begin_define
define|#
directive|define
name|RE_RX_DESC_BUFLEN
value|MCLBYTES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RL_MSI_MESSAGES
value|1
end_define

begin_define
define|#
directive|define
name|RL_ADDR_LO
parameter_list|(
name|y
parameter_list|)
value|((uint64_t) (y)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|RL_ADDR_HI
parameter_list|(
name|y
parameter_list|)
value|((uint64_t) (y)>> 32)
end_define

begin_comment
comment|/*  * The number of bits reserved for MSS in RealTek controllers is  * 11bits. This limits the maximum interface MTU size in TSO case  * as upper stack should not generate TCP segments with MSS greater  * than the limit.  */
end_comment

begin_define
define|#
directive|define
name|RL_TSO_MTU
value|(2047 - ETHER_HDR_LEN - ETHER_CRC_LEN)
end_define

begin_comment
comment|/* see comment in dev/re/if_re.c */
end_comment

begin_define
define|#
directive|define
name|RL_JUMBO_FRAMELEN
value|7440
end_define

begin_define
define|#
directive|define
name|RL_JUMBO_MTU
define|\
value|(RL_JUMBO_FRAMELEN-ETHER_VLAN_ENCAP_LEN-ETHER_HDR_LEN-ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|RL_JUMBO_MTU_6K
define|\
value|((6 * 1024) - ETHER_VLAN_ENCAP_LEN - ETHER_HDR_LEN - ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|RL_JUMBO_MTU_9K
define|\
value|((9 * 1024) - ETHER_VLAN_ENCAP_LEN - ETHER_HDR_LEN - ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|RL_MTU
define|\
value|(ETHER_MAX_LEN + ETHER_VLAN_ENCAP_LEN - ETHER_HDR_LEN - ETHER_CRC_LEN)
end_define

begin_struct
struct|struct
name|rl_txdesc
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
name|rl_rxdesc
block|{
name|struct
name|mbuf
modifier|*
name|rx_m
decl_stmt|;
name|bus_dmamap_t
name|rx_dmamap
decl_stmt|;
name|bus_size_t
name|rx_size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rl_list_data
block|{
name|struct
name|rl_txdesc
name|rl_tx_desc
index|[
name|RL_TX_DESC_CNT
index|]
decl_stmt|;
name|struct
name|rl_rxdesc
name|rl_rx_desc
index|[
name|RL_RX_DESC_CNT
index|]
decl_stmt|;
name|struct
name|rl_rxdesc
name|rl_jrx_desc
index|[
name|RL_RX_JUMBO_DESC_CNT
index|]
decl_stmt|;
name|int
name|rl_tx_desc_cnt
decl_stmt|;
name|int
name|rl_rx_desc_cnt
decl_stmt|;
name|int
name|rl_tx_prodidx
decl_stmt|;
name|int
name|rl_rx_prodidx
decl_stmt|;
name|int
name|rl_tx_considx
decl_stmt|;
name|int
name|rl_tx_free
decl_stmt|;
name|bus_dma_tag_t
name|rl_tx_mtag
decl_stmt|;
comment|/* mbuf TX mapping tag */
name|bus_dma_tag_t
name|rl_rx_mtag
decl_stmt|;
comment|/* mbuf RX mapping tag */
name|bus_dma_tag_t
name|rl_jrx_mtag
decl_stmt|;
comment|/* mbuf RX mapping tag */
name|bus_dmamap_t
name|rl_rx_sparemap
decl_stmt|;
name|bus_dmamap_t
name|rl_jrx_sparemap
decl_stmt|;
name|bus_dma_tag_t
name|rl_stag
decl_stmt|;
comment|/* stats mapping tag */
name|bus_dmamap_t
name|rl_smap
decl_stmt|;
comment|/* stats map */
name|struct
name|rl_stats
modifier|*
name|rl_stats
decl_stmt|;
name|bus_addr_t
name|rl_stats_addr
decl_stmt|;
name|bus_dma_tag_t
name|rl_rx_list_tag
decl_stmt|;
name|bus_dmamap_t
name|rl_rx_list_map
decl_stmt|;
name|struct
name|rl_desc
modifier|*
name|rl_rx_list
decl_stmt|;
name|bus_addr_t
name|rl_rx_list_addr
decl_stmt|;
name|bus_dma_tag_t
name|rl_tx_list_tag
decl_stmt|;
name|bus_dmamap_t
name|rl_tx_list_map
decl_stmt|;
name|struct
name|rl_desc
modifier|*
name|rl_tx_list
decl_stmt|;
name|bus_addr_t
name|rl_tx_list_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|rl_twist
block|{
name|DONE
block|,
name|CHK_LINK
block|,
name|FIND_ROW
block|,
name|SET_PARAM
block|,
name|RECHK_LONG
block|,
name|RETUNE
block|}
enum|;
end_enum

begin_struct
struct|struct
name|rl_softc
block|{
name|struct
name|ifnet
modifier|*
name|rl_ifp
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
name|device_t
name|rl_dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|rl_res
decl_stmt|;
name|int
name|rl_res_id
decl_stmt|;
name|int
name|rl_res_type
decl_stmt|;
name|struct
name|resource
modifier|*
name|rl_res_pba
decl_stmt|;
name|struct
name|resource
modifier|*
name|rl_irq
index|[
name|RL_MSI_MESSAGES
index|]
decl_stmt|;
name|void
modifier|*
name|rl_intrhand
index|[
name|RL_MSI_MESSAGES
index|]
decl_stmt|;
name|device_t
name|rl_miibus
decl_stmt|;
name|bus_dma_tag_t
name|rl_parent_tag
decl_stmt|;
name|uint8_t
name|rl_type
decl_stmt|;
specifier|const
name|struct
name|rl_hwrev
modifier|*
name|rl_hwrev
decl_stmt|;
name|int
name|rl_eecmd_read
decl_stmt|;
name|int
name|rl_eewidth
decl_stmt|;
name|int
name|rl_expcap
decl_stmt|;
name|int
name|rl_txthresh
decl_stmt|;
name|bus_size_t
name|rl_cfg0
decl_stmt|;
name|bus_size_t
name|rl_cfg1
decl_stmt|;
name|bus_size_t
name|rl_cfg2
decl_stmt|;
name|bus_size_t
name|rl_cfg3
decl_stmt|;
name|bus_size_t
name|rl_cfg4
decl_stmt|;
name|bus_size_t
name|rl_cfg5
decl_stmt|;
name|struct
name|rl_chain_data
name|rl_cdata
decl_stmt|;
name|struct
name|rl_list_data
name|rl_ldata
decl_stmt|;
name|struct
name|callout
name|rl_stat_callout
decl_stmt|;
name|int
name|rl_watchdog_timer
decl_stmt|;
name|struct
name|mtx
name|rl_mtx
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|rl_head
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|rl_tail
decl_stmt|;
name|uint32_t
name|rl_rxlenmask
decl_stmt|;
name|int
name|rl_testmode
decl_stmt|;
name|int
name|rl_if_flags
decl_stmt|;
name|int
name|rl_twister_enable
decl_stmt|;
name|enum
name|rl_twist
name|rl_twister
decl_stmt|;
name|int
name|rl_twist_row
decl_stmt|;
name|int
name|rl_twist_col
decl_stmt|;
name|int
name|suspended
decl_stmt|;
comment|/* 0 = normal  1 = suspended */
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
name|rl_inttask
decl_stmt|;
name|int
name|rl_txstart
decl_stmt|;
name|int
name|rl_int_rx_act
decl_stmt|;
name|int
name|rl_int_rx_mod
decl_stmt|;
name|uint32_t
name|rl_flags
decl_stmt|;
define|#
directive|define
name|RL_FLAG_MSI
value|0x00000001
define|#
directive|define
name|RL_FLAG_AUTOPAD
value|0x00000002
define|#
directive|define
name|RL_FLAG_PHYWAKE_PM
value|0x00000004
define|#
directive|define
name|RL_FLAG_PHYWAKE
value|0x00000008
define|#
directive|define
name|RL_FLAG_JUMBOV2
value|0x00000010
define|#
directive|define
name|RL_FLAG_PAR
value|0x00000020
define|#
directive|define
name|RL_FLAG_DESCV2
value|0x00000040
define|#
directive|define
name|RL_FLAG_MACSTAT
value|0x00000080
define|#
directive|define
name|RL_FLAG_FASTETHER
value|0x00000100
define|#
directive|define
name|RL_FLAG_CMDSTOP
value|0x00000200
define|#
directive|define
name|RL_FLAG_MACRESET
value|0x00000400
define|#
directive|define
name|RL_FLAG_MSIX
value|0x00000800
define|#
directive|define
name|RL_FLAG_WOLRXENB
value|0x00001000
define|#
directive|define
name|RL_FLAG_MACSLEEP
value|0x00002000
define|#
directive|define
name|RL_FLAG_WAIT_TXPOLL
value|0x00004000
define|#
directive|define
name|RL_FLAG_CMDSTOP_WAIT_TXQ
value|0x00008000
define|#
directive|define
name|RL_FLAG_WOL_MANLINK
value|0x00010000
define|#
directive|define
name|RL_FLAG_PCIE
value|0x40000000
define|#
directive|define
name|RL_FLAG_LINK
value|0x80000000
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RL_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->rl_mtx)
end_define

begin_define
define|#
directive|define
name|RL_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->rl_mtx)
end_define

begin_define
define|#
directive|define
name|RL_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->rl_mtx, MA_OWNED)
end_define

begin_comment
comment|/*  * register space access macros  */
end_comment

begin_define
define|#
directive|define
name|CSR_WRITE_STREAM_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_stream_4(sc->rl_btag, sc->rl_bhandle, reg, val)
end_define

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
name|CSR_BARRIER
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|length
parameter_list|,
name|flags
parameter_list|)
define|\
value|bus_space_barrier(sc->rl_btag, sc->rl_bhandle, reg, length, flags)
end_define

begin_define
define|#
directive|define
name|CSR_SETBIT_1
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|CSR_WRITE_1(sc, offset, CSR_READ_1(sc, offset) | (val))
end_define

begin_define
define|#
directive|define
name|CSR_CLRBIT_1
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|CSR_WRITE_1(sc, offset, CSR_READ_1(sc, offset)& ~(val))
end_define

begin_define
define|#
directive|define
name|CSR_SETBIT_2
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|CSR_WRITE_2(sc, offset, CSR_READ_2(sc, offset) | (val))
end_define

begin_define
define|#
directive|define
name|CSR_CLRBIT_2
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|CSR_WRITE_2(sc, offset, CSR_READ_2(sc, offset)& ~(val))
end_define

begin_define
define|#
directive|define
name|CSR_SETBIT_4
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|CSR_WRITE_4(sc, offset, CSR_READ_4(sc, offset) | (val))
end_define

begin_define
define|#
directive|define
name|CSR_CLRBIT_4
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|CSR_WRITE_4(sc, offset, CSR_READ_4(sc, offset)& ~(val))
end_define

begin_define
define|#
directive|define
name|RL_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|RL_PHY_TIMEOUT
value|2000
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
name|RT_DEVICEID_8139D
value|0x8039
end_define

begin_define
define|#
directive|define
name|RT_DEVICEID_8129
value|0x8129
end_define

begin_define
define|#
directive|define
name|RT_DEVICEID_8101E
value|0x8136
end_define

begin_define
define|#
directive|define
name|RT_DEVICEID_8138
value|0x8138
end_define

begin_define
define|#
directive|define
name|RT_DEVICEID_8139
value|0x8139
end_define

begin_define
define|#
directive|define
name|RT_DEVICEID_8169SC
value|0x8167
end_define

begin_define
define|#
directive|define
name|RT_DEVICEID_8168
value|0x8168
end_define

begin_define
define|#
directive|define
name|RT_DEVICEID_8169
value|0x8169
end_define

begin_define
define|#
directive|define
name|RT_DEVICEID_8100
value|0x8100
end_define

begin_define
define|#
directive|define
name|RT_REVID_8139CPLUS
value|0x20
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
comment|/*  * Nortel PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|NORTEL_VENDORID
value|0x126C
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
comment|/*  * D-Link DFE-5280T device ID  */
end_comment

begin_define
define|#
directive|define
name|DLINK_DEVICEID_528T
value|0x4300
end_define

begin_define
define|#
directive|define
name|DLINK_DEVICEID_530T_REVC
value|0x4302
end_define

begin_comment
comment|/*  * D-Link DFE-690TXD device ID  */
end_comment

begin_define
define|#
directive|define
name|DLINK_DEVICEID_690TXD
value|0x1340
end_define

begin_comment
comment|/*  * Corega K.K vendor ID  */
end_comment

begin_define
define|#
directive|define
name|COREGA_VENDORID
value|0x1259
end_define

begin_comment
comment|/*  * Corega FEther CB-TXD device ID  */
end_comment

begin_define
define|#
directive|define
name|COREGA_DEVICEID_FETHERCBTXD
value|0xa117
end_define

begin_comment
comment|/*  * Corega FEtherII CB-TXD device ID  */
end_comment

begin_define
define|#
directive|define
name|COREGA_DEVICEID_FETHERIICBTXD
value|0xa11e
end_define

begin_comment
comment|/*  * Corega CG-LAPCIGT device ID  */
end_comment

begin_define
define|#
directive|define
name|COREGA_DEVICEID_CGLAPCIGT
value|0xc107
end_define

begin_comment
comment|/*  * Linksys vendor ID  */
end_comment

begin_define
define|#
directive|define
name|LINKSYS_VENDORID
value|0x1737
end_define

begin_comment
comment|/*  * Linksys EG1032 device ID  */
end_comment

begin_define
define|#
directive|define
name|LINKSYS_DEVICEID_EG1032
value|0x1032
end_define

begin_comment
comment|/*  * Linksys EG1032 rev 3 sub-device ID  */
end_comment

begin_define
define|#
directive|define
name|LINKSYS_SUBDEVICE_EG1032_REV3
value|0x0024
end_define

begin_comment
comment|/*  * Peppercon vendor ID  */
end_comment

begin_define
define|#
directive|define
name|PEPPERCON_VENDORID
value|0x1743
end_define

begin_comment
comment|/*  * Peppercon ROL-F device ID  */
end_comment

begin_define
define|#
directive|define
name|PEPPERCON_DEVICEID_ROLF
value|0x8139
end_define

begin_comment
comment|/*  * Planex Communications, Inc. vendor ID  */
end_comment

begin_define
define|#
directive|define
name|PLANEX_VENDORID
value|0x14ea
end_define

begin_comment
comment|/*  * Planex FNW-3603-TX device ID  */
end_comment

begin_define
define|#
directive|define
name|PLANEX_DEVICEID_FNW3603TX
value|0xab06
end_define

begin_comment
comment|/*  * Planex FNW-3800-TX device ID  */
end_comment

begin_define
define|#
directive|define
name|PLANEX_DEVICEID_FNW3800TX
value|0xab07
end_define

begin_comment
comment|/*  * LevelOne vendor ID  */
end_comment

begin_define
define|#
directive|define
name|LEVEL1_VENDORID
value|0x018A
end_define

begin_comment
comment|/*  * LevelOne FPC-0106TX devide ID  */
end_comment

begin_define
define|#
directive|define
name|LEVEL1_DEVICEID_FPC0106TX
value|0x0106
end_define

begin_comment
comment|/*  * Compaq vendor ID  */
end_comment

begin_define
define|#
directive|define
name|CP_VENDORID
value|0x021B
end_define

begin_comment
comment|/*  * Edimax vendor ID  */
end_comment

begin_define
define|#
directive|define
name|EDIMAX_VENDORID
value|0x13D1
end_define

begin_comment
comment|/*  * Edimax EP-4103DL cardbus device ID  */
end_comment

begin_define
define|#
directive|define
name|EDIMAX_DEVICEID_EP4103DL
value|0xAB06
end_define

begin_comment
comment|/* US Robotics vendor ID */
end_comment

begin_define
define|#
directive|define
name|USR_VENDORID
value|0x16EC
end_define

begin_comment
comment|/* US Robotics 997902 device ID */
end_comment

begin_define
define|#
directive|define
name|USR_DEVICEID_997902
value|0x0116
end_define

end_unit

