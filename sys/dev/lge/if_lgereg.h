begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Wind River Systems  * Copyright (c) 1997, 1998, 1999, 2000, 2001  *	Bill Paul<wpaul@bsdi.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|LGE_MODE1
value|0x00
end_define

begin_comment
comment|/* CSR00 */
end_comment

begin_define
define|#
directive|define
name|LGE_MODE2
value|0x04
end_define

begin_comment
comment|/* CSR01 */
end_comment

begin_define
define|#
directive|define
name|LGE_PPTXBUF_IDX
value|0x08
end_define

begin_comment
comment|/* CSR02 */
end_comment

begin_define
define|#
directive|define
name|LGE_PRODID
value|0x0C
end_define

begin_comment
comment|/* CSR03 */
end_comment

begin_define
define|#
directive|define
name|LGE_PPTXBUF_ADDR_LO
value|0x10
end_define

begin_comment
comment|/* CSR04 */
end_comment

begin_define
define|#
directive|define
name|LGE_PPTXBUF_ADDR_HI
value|0x14
end_define

begin_comment
comment|/* CSR05 */
end_comment

begin_define
define|#
directive|define
name|LGE_RSVD0
value|0x18
end_define

begin_comment
comment|/* CSR06 */
end_comment

begin_define
define|#
directive|define
name|LGE_PPRXBUF_IDX
value|0x1C
end_define

begin_comment
comment|/* CSR07 */
end_comment

begin_define
define|#
directive|define
name|LGE_PPRXBUF_ADDR_LO
value|0x20
end_define

begin_comment
comment|/* CSR08 */
end_comment

begin_define
define|#
directive|define
name|LGE_PPRXBUF_ADDR_HI
value|0x24
end_define

begin_comment
comment|/* CSR09 */
end_comment

begin_define
define|#
directive|define
name|LGE_EECTL
value|0x28
end_define

begin_comment
comment|/* CSR10 */
end_comment

begin_define
define|#
directive|define
name|LGE_CHIPSTS
value|0x2C
end_define

begin_comment
comment|/* CSR11 */
end_comment

begin_define
define|#
directive|define
name|LGE_TXDESC_ADDR_LO
value|0x30
end_define

begin_comment
comment|/* CSR12 */
end_comment

begin_define
define|#
directive|define
name|LGE_TXDESC_ADDR_HI
value|0x34
end_define

begin_comment
comment|/* CSR13 */
end_comment

begin_define
define|#
directive|define
name|LGE_RXDESC_ADDR_LO
value|0x38
end_define

begin_comment
comment|/* CSR14 */
end_comment

begin_define
define|#
directive|define
name|LGE_RXDESC_ADDR_HI
value|0x3C
end_define

begin_comment
comment|/* CSR15 */
end_comment

begin_define
define|#
directive|define
name|LGE_PPTXCTL
value|0x40
end_define

begin_comment
comment|/* CSR16 */
end_comment

begin_define
define|#
directive|define
name|LGE_PPRXCTL
value|0x44
end_define

begin_comment
comment|/* CSR17 */
end_comment

begin_define
define|#
directive|define
name|LGE_INTR_PERIOD
value|0x48
end_define

begin_comment
comment|/* CSR18 */
end_comment

begin_define
define|#
directive|define
name|LGE_TXFIFO_PKTCNT
value|0x4C
end_define

begin_comment
comment|/* CSR19 */
end_comment

begin_define
define|#
directive|define
name|LGE_TXFIFO_LOWAT
value|0x50
end_define

begin_comment
comment|/* CSR20 */
end_comment

begin_define
define|#
directive|define
name|LGE_TXFIFO_FREEDWORDS
value|0x54
end_define

begin_comment
comment|/* CSR21 */
end_comment

begin_define
define|#
directive|define
name|LGE_TXFIFO_WRITE
value|0x58
end_define

begin_comment
comment|/* CSR22 */
end_comment

begin_define
define|#
directive|define
name|LGE_RSVD1
value|0x5C
end_define

begin_comment
comment|/* CSR23 */
end_comment

begin_define
define|#
directive|define
name|LGE_RXFIFO_READ
value|0x60
end_define

begin_comment
comment|/* CSR24 */
end_comment

begin_define
define|#
directive|define
name|LGE_RSVD2
value|0x64
end_define

begin_comment
comment|/* CSR25 */
end_comment

begin_define
define|#
directive|define
name|LGE_RXFIFO_DWORDCNT
value|0x68
end_define

begin_comment
comment|/* CSR26 */
end_comment

begin_define
define|#
directive|define
name|LGE_RXFIFO_HIWAT
value|0x6C
end_define

begin_comment
comment|/* CSR27 */
end_comment

begin_define
define|#
directive|define
name|LGE_RXFIFO_PKTCNT
value|0x70
end_define

begin_comment
comment|/* CSR28 */
end_comment

begin_define
define|#
directive|define
name|LGE_CMD
value|0x74
end_define

begin_comment
comment|/* CSR29 */
end_comment

begin_define
define|#
directive|define
name|LGE_IMR
value|0x78
end_define

begin_comment
comment|/* CSR30 */
end_comment

begin_define
define|#
directive|define
name|LGE_RSVD3
value|0x7C
end_define

begin_comment
comment|/* CSR31 */
end_comment

begin_define
define|#
directive|define
name|LGE_ISR
value|0x80
end_define

begin_comment
comment|/* CSR32 */
end_comment

begin_define
define|#
directive|define
name|LGE_RSVD4
value|0x84
end_define

begin_comment
comment|/* CSR33 */
end_comment

begin_define
define|#
directive|define
name|LGE_MAR0
value|0x88
end_define

begin_comment
comment|/* CSR34 */
end_comment

begin_define
define|#
directive|define
name|LGE_MAR1
value|0x8C
end_define

begin_comment
comment|/* CSR35 */
end_comment

begin_define
define|#
directive|define
name|LGE_LEDCFG0
value|0x90
end_define

begin_comment
comment|/* CSR36 */
end_comment

begin_define
define|#
directive|define
name|LGE_LEDCFG1
value|0x84
end_define

begin_comment
comment|/* CSR37 */
end_comment

begin_define
define|#
directive|define
name|LGE_LEDCFG2
value|0x98
end_define

begin_comment
comment|/* CSR38 */
end_comment

begin_define
define|#
directive|define
name|LGE_LEDCFG3
value|0x9C
end_define

begin_comment
comment|/* CSR39 */
end_comment

begin_define
define|#
directive|define
name|LGE_RSVD5
value|0xA0
end_define

begin_comment
comment|/* CSR40 */
end_comment

begin_define
define|#
directive|define
name|LGE_EEDATA
value|0xA4
end_define

begin_comment
comment|/* CSR41 */
end_comment

begin_define
define|#
directive|define
name|LGE_PAR0
value|0xA8
end_define

begin_comment
comment|/* CSR42 */
end_comment

begin_define
define|#
directive|define
name|LGE_PAR1
value|0xAC
end_define

begin_comment
comment|/* CSR43 */
end_comment

begin_define
define|#
directive|define
name|LGE_GMIICTL
value|0xB0
end_define

begin_comment
comment|/* CSR44 */
end_comment

begin_define
define|#
directive|define
name|LGE_GMIIMODE
value|0xB4
end_define

begin_comment
comment|/* CSR45 */
end_comment

begin_define
define|#
directive|define
name|LGE_STATSIDX
value|0xB8
end_define

begin_comment
comment|/* CSR46 */
end_comment

begin_define
define|#
directive|define
name|LGE_STATSVAL
value|0xBC
end_define

begin_comment
comment|/* CSR47 */
end_comment

begin_define
define|#
directive|define
name|LGE_VLANCTL
value|0xC0
end_define

begin_comment
comment|/* CSR48 */
end_comment

begin_define
define|#
directive|define
name|LGE_RSVD6
value|0xC4
end_define

begin_comment
comment|/* CSR49 */
end_comment

begin_define
define|#
directive|define
name|LGE_RSVD7
value|0xC8
end_define

begin_comment
comment|/* CSR50 */
end_comment

begin_define
define|#
directive|define
name|LGE_CMDSTS
value|0xCC
end_define

begin_comment
comment|/* CSR51 */
end_comment

begin_define
define|#
directive|define
name|LGE_FLOWCTL_WAT
value|0xD0
end_define

begin_comment
comment|/* CSR52 */
end_comment

begin_define
define|#
directive|define
name|LGE_RSVD8
value|0xD4
end_define

begin_comment
comment|/* CSR53 */
end_comment

begin_define
define|#
directive|define
name|LGE_RSVD9
value|0xD8
end_define

begin_comment
comment|/* CSR54 */
end_comment

begin_define
define|#
directive|define
name|LGE_RSVD10
value|0xDC
end_define

begin_comment
comment|/* CSR55 */
end_comment

begin_define
define|#
directive|define
name|LGE_RSVD11
value|0xE0
end_define

begin_comment
comment|/* CSR56 */
end_comment

begin_define
define|#
directive|define
name|LGE_RSVD12
value|0xE4
end_define

begin_comment
comment|/* CSR57 */
end_comment

begin_define
define|#
directive|define
name|LGE_TIMER0_CNT
value|0xE8
end_define

begin_comment
comment|/* CSR58 */
end_comment

begin_define
define|#
directive|define
name|LGE_TIMER0_INT
value|0xEC
end_define

begin_comment
comment|/* CSR59 */
end_comment

begin_define
define|#
directive|define
name|LGE_TIMER1_CNT
value|0xF0
end_define

begin_comment
comment|/* CSR60 */
end_comment

begin_define
define|#
directive|define
name|LGE_TIMER1_INT
value|0xF4
end_define

begin_comment
comment|/* CSR61 */
end_comment

begin_define
define|#
directive|define
name|LGE_DBG_CMD
value|0xF8
end_define

begin_comment
comment|/* CSR62 */
end_comment

begin_define
define|#
directive|define
name|LGE_DBG_DATA
value|0xFC
end_define

begin_comment
comment|/* CSR63 */
end_comment

begin_comment
comment|/* Mode register 1 */
end_comment

begin_define
define|#
directive|define
name|LGE_MODE1_SETRST_CTL0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_SOFTRST
value|0x00000002
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_DEBTOD
value|0x00000004
end_define

begin_comment
comment|/* Not documented? */
end_comment

begin_define
define|#
directive|define
name|LGE_MODE1_TX_FLOWCTL
value|0x00000008
end_define

begin_comment
comment|/* Not documented? */
end_comment

begin_define
define|#
directive|define
name|LGE_MODE1_RXTXRIO
value|0x00000010
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_GMIIPOLL
value|0x00000020
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_TXPAD
value|0x00000040
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_RMVPAD
value|0x00000080
end_define

begin_comment
comment|/* Not documented? */
end_comment

begin_define
define|#
directive|define
name|LGE_MODE1_SETRST_CTL1
value|0x00000100
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_TX_ENB
value|0x00000200
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_RX_ENB
value|0x00000400
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_RX_MCAST
value|0x00000800
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_RX_BCAST
value|0x00001000
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_RX_PROMISC
value|0x00002000
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_RX_UCAST
value|0x00004000
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_RX_GIANTS
value|0x00008000
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_SETRST_CTL2
value|0x00010000
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_RX_CRC
value|0x00020000
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_RX_ERRPKTS
value|0x00040000
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_TX_CRC
value|0x00080000
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_DEMDEN
value|0x00100000
end_define

begin_comment
comment|/* Not documented? */
end_comment

begin_define
define|#
directive|define
name|LGE_MODE1_MPACK_ENB
value|0x00200000
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_MPACK_BCAST
value|0x00400000
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_RX_FLOWCTL
value|0x00800000
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_SETRST_CTL3
value|0x01000000
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_VLAN_RX
value|0x02000000
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_VLAN_TX
value|0x04000000
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_VLAN_STRIP
value|0x08000000
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_VLAN_INSERT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_GPIO_CTL0
value|0x20000000
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_GPIO_CTL1
value|0x40000000
end_define

begin_define
define|#
directive|define
name|LGE_MODE1_RX_LENCHK
value|0x80000000
end_define

begin_comment
comment|/* Mode register 2 */
end_comment

begin_define
define|#
directive|define
name|LGE_MODE2_LOOPBACK
value|0x000000E0
end_define

begin_define
define|#
directive|define
name|LGE_MODE2_RX_IPCSUM
value|0x00001000
end_define

begin_define
define|#
directive|define
name|LGE_MODE2_RX_TCPCSUM
value|0x00002000
end_define

begin_define
define|#
directive|define
name|LGE_MODE2_RX_UDPCSUM
value|0x00004000
end_define

begin_define
define|#
directive|define
name|LGE_MODE2_RX_ERRCSUM
value|0x00008000
end_define

begin_comment
comment|/* EEPROM register */
end_comment

begin_define
define|#
directive|define
name|LGE_EECTL_HAVE_EEPROM
value|0x00000001
end_define

begin_define
define|#
directive|define
name|LGE_EECTL_CMD_READ
value|0x00000002
end_define

begin_define
define|#
directive|define
name|LGE_EECTL_CMD_WRITE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|LGE_EECTL_CSUMERR
value|0x00000010
end_define

begin_define
define|#
directive|define
name|LGE_EECTL_MULTIACCESS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|LGE_EECTL_SINGLEACCESS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|LGE_EECTL_ADDR
value|0x00001F00
end_define

begin_define
define|#
directive|define
name|LGE_EECTL_ROM_TIMING
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|LGE_EECTL_HAVE_FLASH
value|0x00100000
end_define

begin_define
define|#
directive|define
name|LGE_EECTL_WRITEFLASH
value|0x00200000
end_define

begin_define
define|#
directive|define
name|LGE_EE_NODEADDR_0
value|0x12
end_define

begin_define
define|#
directive|define
name|LGE_EE_NODEADDR_1
value|0x13
end_define

begin_define
define|#
directive|define
name|LGE_EE_NODEADDR_2
value|0x10
end_define

begin_comment
comment|/* Chip status register */
end_comment

begin_define
define|#
directive|define
name|LGE_CHIPSTS_HAVETXSPC
value|0x00000001
end_define

begin_comment
comment|/* have room in TX FIFO for pkt */
end_comment

begin_define
define|#
directive|define
name|LGE_CHIPSTS_HAVERXPKT
value|0x00000002
end_define

begin_comment
comment|/* RX FIFO holds complete pkt */
end_comment

begin_define
define|#
directive|define
name|LGE_CHIPSTS_FLOWCTL_STS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|LGE_CHIPSTS_GPIO_STS0
value|0x00000008
end_define

begin_define
define|#
directive|define
name|LGE_CHIPSTS_GPIO_STS1
value|0x00000010
end_define

begin_define
define|#
directive|define
name|LGE_CHIPSTS_TXIDLE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|LGE_CHIPSTS_RXIDLE
value|0x00000040
end_define

begin_comment
comment|/* TX PacketPropulsion control register */
end_comment

begin_define
define|#
directive|define
name|LGE_PPTXCTL_BUFLEN
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|LGE_PPTXCTL_BUFID
value|0x003F0000
end_define

begin_define
define|#
directive|define
name|LGE_PPTXCTL_WANTINTR
value|0x01000000
end_define

begin_comment
comment|/* RX PacketPropulsion control register */
end_comment

begin_define
define|#
directive|define
name|LGE_PPRXCTL_BUFLEN
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|LGE_PPRXCTL_BUFID
value|0x003F0000
end_define

begin_define
define|#
directive|define
name|LGE_PPRXCTL_WANTINTR
value|0x10000000
end_define

begin_comment
comment|/* Command register */
end_comment

begin_define
define|#
directive|define
name|LGE_CMD_SETRST_CTL0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|LGE_CMD_STARTTX
value|0x00000002
end_define

begin_define
define|#
directive|define
name|LGE_CMD_SKIP_RXPKT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|LGE_CMD_DEL_INTREQ
value|0x00000008
end_define

begin_define
define|#
directive|define
name|LGE_CMD_PER_INTREQ
value|0x00000010
end_define

begin_define
define|#
directive|define
name|LGE_CMD_TIMER0
value|0x00000020
end_define

begin_define
define|#
directive|define
name|LGE_CMD_TIMER1
value|0x00000040
end_define

begin_comment
comment|/* Interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|LGE_IMR_SETRST_CTL0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|LGE_IMR_TXCMDFIFO_EMPTY
value|0x00000002
end_define

begin_define
define|#
directive|define
name|LGE_IMR_TXFIFO_WAT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|LGE_IMR_TXDMA_DONE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|LGE_IMR_DELAYEDINTR
value|0x00000040
end_define

begin_define
define|#
directive|define
name|LGE_IMR_INTR_ENB
value|0x00000080
end_define

begin_define
define|#
directive|define
name|LGE_IMR_SETRST_CTL1
value|0x00000100
end_define

begin_define
define|#
directive|define
name|LGE_IMR_RXCMDFIFO_EMPTY
value|0x00000200
end_define

begin_define
define|#
directive|define
name|LGE_IMR_RXFIFO_WAT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|LGE_IMR_RX_DONE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|LGE_IMR_RXDMA_DONE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|LGE_IMR_PHY_INTR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|LGE_IMR_MAGICPKT
value|0x00004000
end_define

begin_define
define|#
directive|define
name|LGE_IMR_SETRST_CTL2
value|0x00010000
end_define

begin_define
define|#
directive|define
name|LGE_IMR_GPIO0
value|0x00020000
end_define

begin_define
define|#
directive|define
name|LGE_IMR_GPIO1
value|0x00040000
end_define

begin_define
define|#
directive|define
name|LGE_IMR_TIMER0
value|0x00080000
end_define

begin_define
define|#
directive|define
name|LGE_IMR_TIMER1
value|0x00100000
end_define

begin_define
define|#
directive|define
name|LGE_INTRS
define|\
value|(LGE_IMR_TXCMDFIFO_EMPTY|LGE_IMR_TXDMA_DONE|LGE_IMR_RX_DONE| \ 	 LGE_IMR_RXCMDFIFO_EMPTY|LGE_IMR_RXDMA_DONE|LGE_IMR_PHY_INTR)
end_define

begin_comment
comment|/* Interrupt status register */
end_comment

begin_define
define|#
directive|define
name|LGE_ISR_TXCMDFIFO_EMPTY
value|0x00000002
end_define

begin_define
define|#
directive|define
name|LGE_ISR_TXFIFO_WAT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|LGE_ISR_TXDMA_DONE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|LGE_ISR_DELAYEDINTR
value|0x00000040
end_define

begin_define
define|#
directive|define
name|LGE_ISR_INTR_ENB
value|0x00000080
end_define

begin_define
define|#
directive|define
name|LGE_ISR_RXCMDFIFO_EMPTY
value|0x00000200
end_define

begin_define
define|#
directive|define
name|LGE_ISR_RXFIFO_WAT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|LGE_ISR_RX_DONE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|LGE_ISR_RXDMA_DONE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|LGE_ISR_PHY_INTR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|LGE_ISR_MAGICPKT
value|0x00004000
end_define

begin_define
define|#
directive|define
name|LGE_ISR_GPIO0
value|0x00020000
end_define

begin_define
define|#
directive|define
name|LGE_ISR_GPIO1
value|0x00040000
end_define

begin_define
define|#
directive|define
name|LGE_ISR_TIMER0
value|0x00080000
end_define

begin_define
define|#
directive|define
name|LGE_ISR_TIMER1
value|0x00100000
end_define

begin_define
define|#
directive|define
name|LGE_ISR_RXDMADONE_CNT
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|LGE_RX_DMACNT
parameter_list|(
name|x
parameter_list|)
value|((x& LGE_ISR_RXDMADONE_CNT)>> 24)
end_define

begin_comment
comment|/* LED0 config register */
end_comment

begin_define
define|#
directive|define
name|LGE_LED0CFG_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|LGE_LED0CFG_INPUT_POL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|LGE_LED0CFG_PULSE_EXP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|LGE_LED0CFG_10MBPS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|LGE_LED0CFG_100MBPS
value|0x00000100
end_define

begin_define
define|#
directive|define
name|LGE_LED0CFG_1000MBPS
value|0x00000200
end_define

begin_define
define|#
directive|define
name|LGE_LED0CFG_FDX
value|0x00000400
end_define

begin_define
define|#
directive|define
name|LGE_LED0CFG_ANEG
value|0x00000800
end_define

begin_define
define|#
directive|define
name|LGE_LED0CFG_LINKSTS
value|0x00001000
end_define

begin_define
define|#
directive|define
name|LGE_LED0CFG_RXMATCH
value|0x00002000
end_define

begin_define
define|#
directive|define
name|LGE_LED0CFG_TX
value|0x00004000
end_define

begin_define
define|#
directive|define
name|LGE_LED0CFG_RX
value|0x00008000
end_define

begin_define
define|#
directive|define
name|LGE_LED0CFG_JABBER
value|0x00010000
end_define

begin_define
define|#
directive|define
name|LGE_LED0CFG_COLLISION
value|0x00020000
end_define

begin_define
define|#
directive|define
name|LGE_LED0CFG_CARRIER
value|0x00040000
end_define

begin_define
define|#
directive|define
name|LGE_LED0CFG_LEDOUT
value|0x10000000
end_define

begin_comment
comment|/* LED1 config register */
end_comment

begin_define
define|#
directive|define
name|LGE_LED1CFG_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|LGE_LED1CFG_INPUT_POL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|LGE_LED1CFG_PULSE_EXP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|LGE_LED1CFG_10MBPS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|LGE_LED1CFG_100MBPS
value|0x00000100
end_define

begin_define
define|#
directive|define
name|LGE_LED1CFG_1000MBPS
value|0x00000200
end_define

begin_define
define|#
directive|define
name|LGE_LED1CFG_FDX
value|0x00000400
end_define

begin_define
define|#
directive|define
name|LGE_LED1CFG_ANEG
value|0x00000800
end_define

begin_define
define|#
directive|define
name|LGE_LED1CFG_LINKSTS
value|0x00001000
end_define

begin_define
define|#
directive|define
name|LGE_LED1CFG_RXMATCH
value|0x00002000
end_define

begin_define
define|#
directive|define
name|LGE_LED1CFG_TX
value|0x00004000
end_define

begin_define
define|#
directive|define
name|LGE_LED1CFG_RX
value|0x00008000
end_define

begin_define
define|#
directive|define
name|LGE_LED1CFG_JABBER
value|0x00010000
end_define

begin_define
define|#
directive|define
name|LGE_LED1CFG_COLLISION
value|0x00020000
end_define

begin_define
define|#
directive|define
name|LGE_LED1CFG_CARRIER
value|0x00040000
end_define

begin_define
define|#
directive|define
name|LGE_LED1CFG_LEDOUT
value|0x10000000
end_define

begin_comment
comment|/* LED2 config register */
end_comment

begin_define
define|#
directive|define
name|LGE_LED2CFG_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|LGE_LED2CFG_INPUT_POL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|LGE_LED2CFG_PULSE_EXP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|LGE_LED2CFG_10MBPS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|LGE_LED2CFG_100MBPS
value|0x00000100
end_define

begin_define
define|#
directive|define
name|LGE_LED2CFG_1000MBPS
value|0x00000200
end_define

begin_define
define|#
directive|define
name|LGE_LED2CFG_FDX
value|0x00000400
end_define

begin_define
define|#
directive|define
name|LGE_LED2CFG_ANEG
value|0x00000800
end_define

begin_define
define|#
directive|define
name|LGE_LED2CFG_LINKSTS
value|0x00001000
end_define

begin_define
define|#
directive|define
name|LGE_LED2CFG_RXMATCH
value|0x00002000
end_define

begin_define
define|#
directive|define
name|LGE_LED2CFG_TX
value|0x00004000
end_define

begin_define
define|#
directive|define
name|LGE_LED2CFG_RX
value|0x00008000
end_define

begin_define
define|#
directive|define
name|LGE_LED2CFG_JABBER
value|0x00010000
end_define

begin_define
define|#
directive|define
name|LGE_LED2CFG_COLLISION
value|0x00020000
end_define

begin_define
define|#
directive|define
name|LGE_LED2CFG_CARRIER
value|0x00040000
end_define

begin_define
define|#
directive|define
name|LGE_LED2CFG_LEDOUT
value|0x10000000
end_define

begin_comment
comment|/* GMII PHY access register */
end_comment

begin_define
define|#
directive|define
name|LGE_GMIICTL_PHYREG
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|LGE_GMIICTL_CMD
value|0x00000080
end_define

begin_define
define|#
directive|define
name|LGE_GMIICTL_PHYADDR
value|0x00001F00
end_define

begin_define
define|#
directive|define
name|LGE_GMIICTL_CMDBUSY
value|0x00008000
end_define

begin_define
define|#
directive|define
name|LGE_GMIICTL_DATA
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|LGE_GMIICMD_READ
value|0x00000000
end_define

begin_define
define|#
directive|define
name|LGE_GMIICMD_WRITE
value|0x00000080
end_define

begin_comment
comment|/* GMII PHY mode register */
end_comment

begin_define
define|#
directive|define
name|LGE_GMIIMODE_SPEED
value|0x00000003
end_define

begin_define
define|#
directive|define
name|LGE_GMIIMODE_FDX
value|0x00000004
end_define

begin_define
define|#
directive|define
name|LGE_GMIIMODE_PROTSEL
value|0x00000100
end_define

begin_comment
comment|/* 0 == GMII, 1 == TBI */
end_comment

begin_define
define|#
directive|define
name|LGE_GMIIMODE_PCSENH
value|0x00000200
end_define

begin_define
define|#
directive|define
name|LGE_SPEED_10
value|0x00000000
end_define

begin_define
define|#
directive|define
name|LGE_SPEED_100
value|0x00000001
end_define

begin_define
define|#
directive|define
name|LGE_SPEED_1000
value|0x00000002
end_define

begin_comment
comment|/* VLAN tag control register */
end_comment

begin_define
define|#
directive|define
name|LGE_VLANCTL_VLID
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|LGE_VLANCTL_USERPRIO
value|0x0000E000
end_define

begin_define
define|#
directive|define
name|LGE_VLANCTL_TCI_IDX
value|0x000D0000
end_define

begin_define
define|#
directive|define
name|LGE_VLANCTL_TBLCMD
value|0x00200000
end_define

begin_comment
comment|/* Command status register */
end_comment

begin_define
define|#
directive|define
name|LGE_CMDSTS_TXDMADONE
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|LGE_CMDSTS_RXDMADONE
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|LGE_CMDSTS_TXCMDFREE
value|0x003F0000
end_define

begin_define
define|#
directive|define
name|LGE_CMDSTS_RXCMDFREE
value|0x3F000000
end_define

begin_define
define|#
directive|define
name|LGE_TXDMADONE_8BIT
value|LGE_CMDSTS
end_define

begin_define
define|#
directive|define
name|LGE_RXDMADONE_8BIT
value|(LGE_CMDSTS + 1)
end_define

begin_define
define|#
directive|define
name|LGE_TXCMDFREE_8BIT
value|(LGE_CMDSTS + 2)
end_define

begin_define
define|#
directive|define
name|LGE_RXCMDFREE_8BIT
value|(LGE_CMDSTS + 3)
end_define

begin_define
define|#
directive|define
name|LGE_MAXCMDS
value|31
end_define

begin_comment
comment|/* Index for statistics counters. */
end_comment

begin_define
define|#
directive|define
name|LGE_STATS_TX_PKTS_OK
value|0x00
end_define

begin_define
define|#
directive|define
name|LGE_STATS_SINGLE_COLL_PKTS
value|0x01
end_define

begin_define
define|#
directive|define
name|LGE_STATS_MULTI_COLL_PKTS
value|0x02
end_define

begin_define
define|#
directive|define
name|LGE_STATS_RX_PKTS_OK
value|0x03
end_define

begin_define
define|#
directive|define
name|LGE_STATS_FCS_ERRS
value|0x04
end_define

begin_define
define|#
directive|define
name|LGE_STATS_ALIGN_ERRS
value|0x05
end_define

begin_define
define|#
directive|define
name|LGE_STATS_DROPPED_PKTS
value|0x06
end_define

begin_define
define|#
directive|define
name|LGE_STATS_RX_ERR_PKTS
value|0x07
end_define

begin_define
define|#
directive|define
name|LGE_STATS_TX_ERR_PKTS
value|0x08
end_define

begin_define
define|#
directive|define
name|LGE_STATS_LATE_COLLS
value|0x09
end_define

begin_define
define|#
directive|define
name|LGE_STATS_RX_RUNTS
value|0x0A
end_define

begin_define
define|#
directive|define
name|LGE_STATS_RX_GIANTS
value|0x0B
end_define

begin_define
define|#
directive|define
name|LGE_STATS_VLAN_PKTS_ACCEPT
value|0x0C
end_define

begin_define
define|#
directive|define
name|LGE_STATS_VLAN_PKTS_REJECT
value|0x0D
end_define

begin_define
define|#
directive|define
name|LGE_STATS_IP_CSUM_ERR
value|0x0E
end_define

begin_define
define|#
directive|define
name|LGE_STATS_UDP_CSUM_ERR
value|0x0F
end_define

begin_define
define|#
directive|define
name|LGE_STATS_RANGELEN_ERRS
value|0x10
end_define

begin_define
define|#
directive|define
name|LGE_STATS_TCP_CSUM_ERR
value|0x11
end_define

begin_define
define|#
directive|define
name|LGE_STATS_RSVD0
value|0x12
end_define

begin_define
define|#
directive|define
name|LGE_STATS_TX_EXCESS_COLLS
value|0x13
end_define

begin_define
define|#
directive|define
name|LGE_STATS_RX_UCASTS
value|0x14
end_define

begin_define
define|#
directive|define
name|LGE_STATS_RX_MCASTS
value|0x15
end_define

begin_define
define|#
directive|define
name|LGE_STATS_RX_BCASTS
value|0x16
end_define

begin_define
define|#
directive|define
name|LGE_STATS_RX_PAUSE_PKTS
value|0x17
end_define

begin_define
define|#
directive|define
name|LGE_STATS_TX_PAUSE_PKTS
value|0x18
end_define

begin_define
define|#
directive|define
name|LGE_STATS_TX_PKTS_DEFERRED
value|0x19
end_define

begin_define
define|#
directive|define
name|LGE_STATS_TX_EXCESS_DEFER
value|0x1A
end_define

begin_define
define|#
directive|define
name|LGE_STATS_CARRIER_SENSE_ERR
value|0x1B
end_define

begin_comment
comment|/*  * RX and TX DMA descriptor structures for scatter/gather.  * Each descriptor can have up to 31 fragments in it, however for  * RX we only need one fragment, and for transmit we only allocate  * 10 in order to reduce the amount of space we need for the  * descriptor lists.  * Note: descriptor structures must be 64-bit aligned.  */
end_comment

begin_struct
struct|struct
name|lge_rx_desc
block|{
comment|/* Hardware descriptor section */
name|u_int32_t
name|lge_ctl
decl_stmt|;
name|u_int32_t
name|lge_sts
decl_stmt|;
name|u_int32_t
name|lge_fragptr_lo
decl_stmt|;
name|u_int32_t
name|lge_fragptr_hi
decl_stmt|;
name|u_int16_t
name|lge_fraglen
decl_stmt|;
name|u_int16_t
name|lge_rsvd0
decl_stmt|;
name|u_int32_t
name|lge_rsvd1
decl_stmt|;
comment|/* Driver software section */
union|union
block|{
name|struct
name|mbuf
modifier|*
name|lge_mbuf
decl_stmt|;
name|u_int64_t
name|lge_dummy
decl_stmt|;
block|}
name|lge_u
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lge_frag
block|{
name|u_int32_t
name|lge_rsvd0
decl_stmt|;
name|u_int32_t
name|lge_fragptr_lo
decl_stmt|;
name|u_int32_t
name|lge_fragptr_hi
decl_stmt|;
name|u_int16_t
name|lge_fraglen
decl_stmt|;
name|u_int16_t
name|lge_rsvd1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lge_tx_desc
block|{
comment|/* Hardware descriptor section */
name|u_int32_t
name|lge_ctl
decl_stmt|;
name|struct
name|lge_frag
name|lge_frags
index|[
literal|10
index|]
decl_stmt|;
name|u_int32_t
name|lge_rsvd0
decl_stmt|;
union|union
block|{
name|struct
name|mbuf
modifier|*
name|lge_mbuf
decl_stmt|;
name|u_int64_t
name|lge_dummy
decl_stmt|;
block|}
name|lge_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|lge_mbuf
value|lge_u.lge_mbuf
end_define

begin_define
define|#
directive|define
name|LGE_RXCTL_BUFLEN
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|LGE_RXCTL_FRAGCNT
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|LGE_RXCTL_LENERR
value|0x00400000
end_define

begin_define
define|#
directive|define
name|LGE_RXCTL_UCAST
value|0x00800000
end_define

begin_define
define|#
directive|define
name|LGR_RXCTL_BCAST
value|0x01000000
end_define

begin_define
define|#
directive|define
name|LGE_RXCTL_MCAST
value|0x02000000
end_define

begin_define
define|#
directive|define
name|LGE_RXCTL_GIANT
value|0x04000000
end_define

begin_define
define|#
directive|define
name|LGE_RXCTL_OFLOW
value|0x08000000
end_define

begin_define
define|#
directive|define
name|LGE_RXCTL_CRCERR
value|0x10000000
end_define

begin_define
define|#
directive|define
name|LGE_RXCTL_RUNT
value|0x20000000
end_define

begin_define
define|#
directive|define
name|LGE_RXCTL_ALGNERR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|LGE_RXCTL_WANTINTR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|LGE_RXCTL_ERRMASK
define|\
value|(LGE_RXCTL_LENERR|LGE_RXCTL_OFLOW|	\ 	 LGE_RXCTL_CRCERR|LGE_RXCTL_RUNT|	\ 	 LGE_RXCTL_ALGNERR)
end_define

begin_define
define|#
directive|define
name|LGE_RXSTS_VLTBIDX
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|LGE_RXSTS_VLTBLHIT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|LGE_RXSTS_IPCSUMERR
value|0x00000100
end_define

begin_define
define|#
directive|define
name|LGE_RXSTS_TCPCSUMERR
value|0x00000200
end_define

begin_define
define|#
directive|define
name|LGE_RXSTS_UDPCSUMERR
value|0x00000400
end_define

begin_define
define|#
directive|define
name|LGE_RXSTS_ISIP
value|0x00000800
end_define

begin_define
define|#
directive|define
name|LGE_RXSTS_ISTCP
value|0x00001000
end_define

begin_define
define|#
directive|define
name|LGE_RXSTS_ISUDP
value|0x00002000
end_define

begin_define
define|#
directive|define
name|LGE_TXCTL_BUFLEN
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|LGE_TXCTL_FRAGCNT
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|LGE_TXCTL_VLTBIDX
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|LGE_TXCTL_VLIS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|LGE_TXCTL_WANTINTR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|LGE_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = (x + 1) % y
end_define

begin_define
define|#
directive|define
name|LGE_FRAGCNT_1
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|LGE_FRAGCNT_10
value|(10<<16)
end_define

begin_define
define|#
directive|define
name|LGE_FRAGCNT
parameter_list|(
name|x
parameter_list|)
value|(x<<16)
end_define

begin_define
define|#
directive|define
name|LGE_RXBYTES
parameter_list|(
name|x
parameter_list|)
value|(x->lge_ctl& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|LGE_RXTAIL
parameter_list|(
name|x
parameter_list|)
define|\
value|(x->lge_ldata->lge_rx_list[x->lge_cdata.lge_rx_prod])
end_define

begin_define
define|#
directive|define
name|LGE_RX_LIST_CNT
value|64
end_define

begin_define
define|#
directive|define
name|LGE_TX_LIST_CNT
value|128
end_define

begin_struct
struct|struct
name|lge_list_data
block|{
name|struct
name|lge_rx_desc
name|lge_rx_list
index|[
name|LGE_RX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|lge_tx_desc
name|lge_tx_list
index|[
name|LGE_TX_LIST_CNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Level 1 PCI vendor ID.  */
end_comment

begin_define
define|#
directive|define
name|LGE_VENDORID
value|0x1394
end_define

begin_comment
comment|/*  * LXT 1001 PCI device IDs  */
end_comment

begin_define
define|#
directive|define
name|LGE_DEVICEID
value|0x0001
end_define

begin_struct
struct|struct
name|lge_type
block|{
name|u_int16_t
name|lge_vid
decl_stmt|;
name|u_int16_t
name|lge_did
decl_stmt|;
name|char
modifier|*
name|lge_name
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lge_mii_frame
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
name|LGE_MII_STARTDELIM
value|0x01
end_define

begin_define
define|#
directive|define
name|LGE_MII_READOP
value|0x02
end_define

begin_define
define|#
directive|define
name|LGE_MII_WRITEOP
value|0x01
end_define

begin_define
define|#
directive|define
name|LGE_MII_TURNAROUND
value|0x02
end_define

begin_define
define|#
directive|define
name|LGE_JUMBO_FRAMELEN
value|9018
end_define

begin_define
define|#
directive|define
name|LGE_JUMBO_MTU
value|(LGE_JUMBO_FRAMELEN-ETHER_HDR_LEN-ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|LGE_JSLOTS
value|384
end_define

begin_define
define|#
directive|define
name|LGE_JRAWLEN
value|(LGE_JUMBO_FRAMELEN + ETHER_ALIGN + sizeof(u_int64_t))
end_define

begin_define
define|#
directive|define
name|LGE_JLEN
value|(LGE_JRAWLEN + (sizeof(u_int64_t) - \ 	(LGE_JRAWLEN % sizeof(u_int64_t))))
end_define

begin_define
define|#
directive|define
name|LGE_MCLBYTES
value|(LGE_JLEN - sizeof(u_int64_t))
end_define

begin_define
define|#
directive|define
name|LGE_JPAGESZ
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|LGE_RESID
value|(LGE_JPAGESZ - (LGE_JLEN * LGE_JSLOTS) % LGE_JPAGESZ)
end_define

begin_define
define|#
directive|define
name|LGE_JMEM
value|((LGE_JLEN * LGE_JSLOTS) + LGE_RESID)
end_define

begin_struct
struct|struct
name|lge_jslot
block|{
name|caddr_t
name|lge_buf
decl_stmt|;
name|int
name|lge_inuse
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lge_jpool_entry
block|{
name|int
name|slot
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|lge_jpool_entry
argument_list|)
name|jpool_entries
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lge_ring_data
block|{
name|int
name|lge_rx_prod
decl_stmt|;
name|int
name|lge_rx_cons
decl_stmt|;
name|int
name|lge_tx_prod
decl_stmt|;
name|int
name|lge_tx_cons
decl_stmt|;
comment|/* Stick the jumbo mem management stuff here too. */
name|struct
name|lge_jslot
name|lge_jslots
index|[
name|LGE_JSLOTS
index|]
decl_stmt|;
name|void
modifier|*
name|lge_jumbo_buf
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lge_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
comment|/* interface info */
name|bus_space_handle_t
name|lge_bhandle
decl_stmt|;
name|bus_space_tag_t
name|lge_btag
decl_stmt|;
name|struct
name|resource
modifier|*
name|lge_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|lge_irq
decl_stmt|;
name|void
modifier|*
name|lge_intrhand
decl_stmt|;
name|device_t
name|lge_miibus
decl_stmt|;
name|u_int8_t
name|lge_unit
decl_stmt|;
name|u_int8_t
name|lge_type
decl_stmt|;
name|u_int8_t
name|lge_link
decl_stmt|;
name|u_int8_t
name|lge_pcs
decl_stmt|;
name|int
name|lge_if_flags
decl_stmt|;
name|struct
name|lge_list_data
modifier|*
name|lge_ldata
decl_stmt|;
name|struct
name|lge_ring_data
name|lge_cdata
decl_stmt|;
name|struct
name|callout_handle
name|lge_stat_ch
decl_stmt|;
name|SLIST_HEAD
argument_list|(
argument|__lge_jfreehead
argument_list|,
argument|lge_jpool_entry
argument_list|)
name|lge_jfree_listhead
expr_stmt|;
name|SLIST_HEAD
argument_list|(
argument|__lge_jinusehead
argument_list|,
argument|lge_jpool_entry
argument_list|)
name|lge_jinuse_listhead
expr_stmt|;
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
value|bus_space_write_4(sc->lge_btag, sc->lge_bhandle, reg, val)
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
value|bus_space_read_2(sc->lge_btag, sc->lge_bhandle, reg)
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
value|bus_space_write_2(sc->lge_btag, sc->lge_bhandle, reg, val)
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
value|bus_space_read_4(sc->lge_btag, sc->lge_bhandle, reg)
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
value|bus_space_write_1(sc->lge_btag, sc->lge_bhandle, reg, val)
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
value|bus_space_read_1(sc->lge_btag, sc->lge_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|LGE_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|ETHER_ALIGN
value|2
end_define

begin_define
define|#
directive|define
name|LGE_RXLEN
value|1536
end_define

begin_define
define|#
directive|define
name|LGE_MIN_FRAMELEN
value|60
end_define

begin_comment
comment|/*  * PCI low memory base and low I/O base register, and  * other PCI registers.  */
end_comment

begin_define
define|#
directive|define
name|LGE_PCI_VENDOR_ID
value|0x00
end_define

begin_define
define|#
directive|define
name|LGE_PCI_DEVICE_ID
value|0x02
end_define

begin_define
define|#
directive|define
name|LGE_PCI_COMMAND
value|0x04
end_define

begin_define
define|#
directive|define
name|LGE_PCI_STATUS
value|0x06
end_define

begin_define
define|#
directive|define
name|LGE_PCI_REVID
value|0x08
end_define

begin_define
define|#
directive|define
name|LGE_PCI_CLASSCODE
value|0x09
end_define

begin_define
define|#
directive|define
name|LGE_PCI_CACHELEN
value|0x0C
end_define

begin_define
define|#
directive|define
name|LGE_PCI_LATENCY_TIMER
value|0x0D
end_define

begin_define
define|#
directive|define
name|LGE_PCI_HEADER_TYPE
value|0x0E
end_define

begin_define
define|#
directive|define
name|LGE_PCI_LOIO
value|0x10
end_define

begin_define
define|#
directive|define
name|LGE_PCI_LOMEM
value|0x14
end_define

begin_define
define|#
directive|define
name|LGE_PCI_BIOSROM
value|0x30
end_define

begin_define
define|#
directive|define
name|LGE_PCI_INTLINE
value|0x3C
end_define

begin_define
define|#
directive|define
name|LGE_PCI_INTPIN
value|0x3D
end_define

begin_define
define|#
directive|define
name|LGE_PCI_MINGNT
value|0x3E
end_define

begin_define
define|#
directive|define
name|LGE_PCI_MINLAT
value|0x0F
end_define

begin_define
define|#
directive|define
name|LGE_PCI_RESETOPT
value|0x48
end_define

begin_define
define|#
directive|define
name|LGE_PCI_EEPROM_DATA
value|0x4C
end_define

begin_comment
comment|/* power management registers */
end_comment

begin_define
define|#
directive|define
name|LGE_PCI_CAPID
value|0x50
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|LGE_PCI_NEXTPTR
value|0x51
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|LGE_PCI_PWRMGMTCAP
value|0x52
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|LGE_PCI_PWRMGMTCTRL
value|0x54
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|LGE_PSTATE_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|LGE_PSTATE_D0
value|0x0000
end_define

begin_define
define|#
directive|define
name|LGE_PSTATE_D1
value|0x0001
end_define

begin_define
define|#
directive|define
name|LGE_PSTATE_D2
value|0x0002
end_define

begin_define
define|#
directive|define
name|LGE_PSTATE_D3
value|0x0003
end_define

begin_define
define|#
directive|define
name|LGE_PME_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|LGE_PME_STATUS
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

