begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Macronix register definitions.  */
end_comment

begin_define
define|#
directive|define
name|MX_BUSCTL
value|0x00
end_define

begin_comment
comment|/* bus control */
end_comment

begin_define
define|#
directive|define
name|MX_TXSTART
value|0x08
end_define

begin_comment
comment|/* tx start demand */
end_comment

begin_define
define|#
directive|define
name|MX_RXSTART
value|0x10
end_define

begin_comment
comment|/* rx start demand */
end_comment

begin_define
define|#
directive|define
name|MX_RXADDR
value|0x18
end_define

begin_comment
comment|/* rx descriptor list start addr */
end_comment

begin_define
define|#
directive|define
name|MX_TXADDR
value|0x20
end_define

begin_comment
comment|/* tx descriptor list start addr */
end_comment

begin_define
define|#
directive|define
name|MX_ISR
value|0x28
end_define

begin_comment
comment|/* interrupt status register */
end_comment

begin_define
define|#
directive|define
name|MX_NETCFG
value|0x30
end_define

begin_comment
comment|/* network config register */
end_comment

begin_define
define|#
directive|define
name|MX_IMR
value|0x38
end_define

begin_comment
comment|/* interrupt mask */
end_comment

begin_define
define|#
directive|define
name|MX_FRAMESDISCARDED
value|0x40
end_define

begin_comment
comment|/* # of discarded frames */
end_comment

begin_define
define|#
directive|define
name|MX_SIO
value|0x48
end_define

begin_comment
comment|/* MII and ROM/EEPROM access */
end_comment

begin_define
define|#
directive|define
name|MX_RESERVED
value|0x50
end_define

begin_define
define|#
directive|define
name|MX_TIMER
value|0x58
end_define

begin_comment
comment|/* general timer */
end_comment

begin_define
define|#
directive|define
name|MX_10BTSTAT
value|0x60
end_define

begin_define
define|#
directive|define
name|MX_SIARESET
value|0x68
end_define

begin_define
define|#
directive|define
name|MX_10BTCTRL
value|0x70
end_define

begin_define
define|#
directive|define
name|MX_WATCHDOG
value|0x78
end_define

begin_define
define|#
directive|define
name|MX_MAGICPACKET
value|0x80
end_define

begin_define
define|#
directive|define
name|MX_NWAYSTAT
value|0xA0
end_define

begin_comment
comment|/*  * These are magic values that must be written into CSR16  * (MX_MAGICPACKET) in order to put the chip into proper  * operating mode. The magic numbers are documented in the  * Macronix 98715 application notes.  */
end_comment

begin_define
define|#
directive|define
name|MX_MAGIC_98713
value|0x0F370000
end_define

begin_define
define|#
directive|define
name|MX_MAGIC_98713A
value|0x0B3C0000
end_define

begin_define
define|#
directive|define
name|MX_MAGIC_98715
value|0x0B3C0000
end_define

begin_define
define|#
directive|define
name|MX_MAGIC_98725
value|0x0B3C0000
end_define

begin_define
define|#
directive|define
name|MX_REVISION_98713
value|0x00
end_define

begin_define
define|#
directive|define
name|MX_REVISION_98713A
value|0x10
end_define

begin_define
define|#
directive|define
name|MX_REVISION_98715
value|0x20
end_define

begin_define
define|#
directive|define
name|MX_REVISION_98725
value|0x30
end_define

begin_comment
comment|/*  * As far as the driver is concerned, there are two 'types' of  * chips to be concerned with. One is a 98713 with an external  * PHY on the MII. The other covers pretty much everything else,  * since all the other Macronix chips have built-in transceivers.  * This type setting governs what which mode selection routines  * we use (MII or built-in). It also govers which of the 'magic'  * numbers we write into CSR16.  */
end_comment

begin_define
define|#
directive|define
name|MX_TYPE_98713
value|0x1
end_define

begin_define
define|#
directive|define
name|MX_TYPE_98713A
value|0x2
end_define

begin_define
define|#
directive|define
name|MX_TYPE_987x5
value|0x3
end_define

begin_comment
comment|/*  * Bus control bits.  */
end_comment

begin_define
define|#
directive|define
name|MX_BUSCTL_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MX_BUSCTL_ARBITRATION
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MX_BUSCTL_SKIPLEN
value|0x0000007C
end_define

begin_define
define|#
directive|define
name|MX_BUSCTL_BUF_BIGENDIAN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|MX_BUSCTL_BURSTLEN
value|0x00003F00
end_define

begin_define
define|#
directive|define
name|MX_BUSCTL_CACHEALIGN
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|MX_BUSCTL_TXPOLL
value|0x000E0000
end_define

begin_define
define|#
directive|define
name|MX_BUSCTL_MUSTBEONE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|MX_SKIPLEN_1LONG
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MX_SKIPLEN_2LONG
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MX_SKIPLEN_3LONG
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MX_SKIPLEN_4LONG
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MX_SKIPLEN_5LONG
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MX_CACHEALIGN_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MX_CACHEALIGN_8LONG
value|0x00004000
end_define

begin_define
define|#
directive|define
name|MX_CACHEALIGN_16LONG
value|0x00008000
end_define

begin_define
define|#
directive|define
name|MX_CACHEALIGN_32LONG
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|MX_BURSTLEN_USECA
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MX_BURSTLEN_1LONG
value|0x00000100
end_define

begin_define
define|#
directive|define
name|MX_BURSTLEN_2LONG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|MX_BURSTLEN_4LONG
value|0x00000400
end_define

begin_define
define|#
directive|define
name|MX_BURSTLEN_8LONG
value|0x00000800
end_define

begin_define
define|#
directive|define
name|MX_BURSTLEN_16LONG
value|0x00001000
end_define

begin_define
define|#
directive|define
name|MX_BURSTLEN_32LONG
value|0x00002000
end_define

begin_define
define|#
directive|define
name|MX_TXPOLL_OFF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MX_TXPOLL_200U
value|0x00020000
end_define

begin_define
define|#
directive|define
name|MX_TXPOLL_800U
value|0x00040000
end_define

begin_define
define|#
directive|define
name|MX_TXPOLL_1600U
value|0x00060000
end_define

begin_define
define|#
directive|define
name|MX_BUSCTL_CONFIG
value|(MX_BUSCTL_ARBITRATION|MX_CACHEALIGN_8LONG| \ 					MX_BURSTLEN_8LONG)
end_define

begin_comment
comment|/*  * Interrupt status bits.  */
end_comment

begin_define
define|#
directive|define
name|MX_ISR_TX_OK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MX_ISR_TX_IDLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MX_ISR_TX_NOBUF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MX_ISR_TX_JABBERTIMEO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MX_ISR_LINKGOOD
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MX_ISR_TX_UNDERRUN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MX_ISR_RX_OK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MX_ISR_RX_NOBUF
value|0x00000080
end_define

begin_define
define|#
directive|define
name|MX_ISR_RX_READ
value|0x00000100
end_define

begin_define
define|#
directive|define
name|MX_ISR_RX_WATDOGTIMEO
value|0x00000200
end_define

begin_define
define|#
directive|define
name|MX_ISR_TX_EARLY
value|0x00000400
end_define

begin_define
define|#
directive|define
name|MX_ISR_TIMER_EXPIRED
value|0x00000800
end_define

begin_define
define|#
directive|define
name|MX_ISR_LINKFAIL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|MX_ISR_BUS_ERR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|MX_ISR_RX_EARLY
value|0x00004000
end_define

begin_define
define|#
directive|define
name|MX_ISR_ABNORMAL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|MX_ISR_NORMAL
value|0x00010000
end_define

begin_define
define|#
directive|define
name|MX_ISR_RX_STATE
value|0x000E0000
end_define

begin_define
define|#
directive|define
name|MX_ISR_TX_STATE
value|0x00700000
end_define

begin_define
define|#
directive|define
name|MX_ISR_BUSERRTYPE
value|0x03800000
end_define

begin_define
define|#
directive|define
name|MX_ISR_100MBPSLINK
value|0x08000000
end_define

begin_define
define|#
directive|define
name|MX_ISR_MAGICKPACK
value|0x10000000
end_define

begin_define
define|#
directive|define
name|MX_RXSTATE_STOPPED
value|0x00000000
end_define

begin_comment
comment|/* 000 - Stopped */
end_comment

begin_define
define|#
directive|define
name|MX_RXSTATE_FETCH
value|0x00020000
end_define

begin_comment
comment|/* 001 - Fetching descriptor */
end_comment

begin_define
define|#
directive|define
name|MX_RXSTATE_ENDCHECK
value|0x00040000
end_define

begin_comment
comment|/* 010 - check for rx end */
end_comment

begin_define
define|#
directive|define
name|MX_RXSTATE_WAIT
value|0x00060000
end_define

begin_comment
comment|/* 011 - waiting for packet */
end_comment

begin_define
define|#
directive|define
name|MX_RXSTATE_SUSPEND
value|0x00080000
end_define

begin_comment
comment|/* 100 - suspend rx */
end_comment

begin_define
define|#
directive|define
name|MX_RXSTATE_CLOSE
value|0x000A0000
end_define

begin_comment
comment|/* 101 - close tx desc */
end_comment

begin_define
define|#
directive|define
name|MX_RXSTATE_FLUSH
value|0x000C0000
end_define

begin_comment
comment|/* 110 - flush from FIFO */
end_comment

begin_define
define|#
directive|define
name|MX_RXSTATE_DEQUEUE
value|0x000E0000
end_define

begin_comment
comment|/* 111 - dequeue from FIFO */
end_comment

begin_define
define|#
directive|define
name|MX_TXSTATE_RESET
value|0x00000000
end_define

begin_comment
comment|/* 000 - reset */
end_comment

begin_define
define|#
directive|define
name|MX_TXSTATE_FETCH
value|0x00100000
end_define

begin_comment
comment|/* 001 - fetching descriptor */
end_comment

begin_define
define|#
directive|define
name|MX_TXSTATE_WAITEND
value|0x00200000
end_define

begin_comment
comment|/* 010 - wait for tx end */
end_comment

begin_define
define|#
directive|define
name|MX_TXSTATE_READING
value|0x00300000
end_define

begin_comment
comment|/* 011 - read and enqueue */
end_comment

begin_define
define|#
directive|define
name|MX_TXSTATE_RSVD
value|0x00400000
end_define

begin_comment
comment|/* 100 - reserved */
end_comment

begin_define
define|#
directive|define
name|MX_TXSTATE_SETUP
value|0x00500000
end_define

begin_comment
comment|/* 101 - setup packet */
end_comment

begin_define
define|#
directive|define
name|MX_TXSTATE_SUSPEND
value|0x00600000
end_define

begin_comment
comment|/* 110 - suspend tx */
end_comment

begin_define
define|#
directive|define
name|MX_TXSTATE_CLOSE
value|0x00700000
end_define

begin_comment
comment|/* 111 - close tx desc */
end_comment

begin_comment
comment|/*  * Network config bits.  */
end_comment

begin_define
define|#
directive|define
name|MX_NETCFG_RX_HASHPERF
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MX_NETCFG_RX_ON
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MX_NETCFG_RX_HASHONLY
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MX_NETCFG_RX_BADFRAMES
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MX_NETCFG_RX_INVFILT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MX_NETCFG_BACKOFFCNT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MX_NETCFG_RX_PROMISC
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MX_NETCFG_RX_ALLMULTI
value|0x00000080
end_define

begin_define
define|#
directive|define
name|MX_NETCFG_FULLDUPLEX
value|0x00000200
end_define

begin_define
define|#
directive|define
name|MX_NETCFG_LOOPBACK
value|0x00000C00
end_define

begin_define
define|#
directive|define
name|MX_NETCFG_FORCECOLL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|MX_NETCFG_TX_ON
value|0x00002000
end_define

begin_define
define|#
directive|define
name|MX_NETCFG_TX_THRESH
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|MX_NETCFG_TX_BACKOFF
value|0x00020000
end_define

begin_define
define|#
directive|define
name|MX_NETCFG_PORTSEL
value|0x00040000
end_define

begin_comment
comment|/* 0 == 10, 1 == 100 */
end_comment

begin_define
define|#
directive|define
name|MX_NETCFG_HEARTBEAT
value|0x00080000
end_define

begin_define
define|#
directive|define
name|MX_NETCFG_STORENFWD
value|0x00200000
end_define

begin_define
define|#
directive|define
name|MX_NETCFG_SPEEDSEL
value|0x00400000
end_define

begin_comment
comment|/* 1 == 10, 0 == 100 */
end_comment

begin_define
define|#
directive|define
name|MX_NETCFG_PCS
value|0x00800000
end_define

begin_define
define|#
directive|define
name|MX_NETCFG_SCRAMBLER
value|0x01000000
end_define

begin_define
define|#
directive|define
name|MX_NETCFG_NO_RXCRC
value|0x02000000
end_define

begin_define
define|#
directive|define
name|MX_OPMODE_NORM
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MX_OPMODE_INTLOOP
value|0x00000400
end_define

begin_define
define|#
directive|define
name|MX_OPMODE_EXTLOOP
value|0x00000800
end_define

begin_define
define|#
directive|define
name|MX_TXTHRESH_72BYTES
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MX_TXTHRESH_96BYTES
value|0x00004000
end_define

begin_define
define|#
directive|define
name|MX_TXTHRESH_128BYTES
value|0x00008000
end_define

begin_define
define|#
directive|define
name|MX_TXTHRESH_160BYTES
value|0x0000C000
end_define

begin_comment
comment|/*  * Interrupt mask bits.  */
end_comment

begin_define
define|#
directive|define
name|MX_IMR_TX_OK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MX_IMR_TX_IDLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MX_IMR_TX_NOBUF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MX_IMR_TX_JABBERTIMEO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MX_IMR_LINKGOOD
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MX_IMR_TX_UNDERRUN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MX_IMR_RX_OK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MX_IMR_RX_NOBUF
value|0x00000080
end_define

begin_define
define|#
directive|define
name|MX_IMR_RX_READ
value|0x00000100
end_define

begin_define
define|#
directive|define
name|MX_IMR_RX_WATDOGTIMEO
value|0x00000200
end_define

begin_define
define|#
directive|define
name|MX_IMR_TX_EARLY
value|0x00000400
end_define

begin_define
define|#
directive|define
name|MX_IMR_TIMER_EXPIRED
value|0x00000800
end_define

begin_define
define|#
directive|define
name|MX_IMR_LINKFAIL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|MX_IMR_BUS_ERR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|MX_IMR_RX_EARLY
value|0x00004000
end_define

begin_define
define|#
directive|define
name|MX_IMR_ABNORMAL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|MX_IMR_NORMAL
value|0x00010000
end_define

begin_define
define|#
directive|define
name|MX_IMR_100MBPSLINK
value|0x08000000
end_define

begin_define
define|#
directive|define
name|MX_IMR_MAGICKPACK
value|0x10000000
end_define

begin_define
define|#
directive|define
name|MX_INTRS
define|\
value|(MX_IMR_RX_OK|MX_IMR_TX_OK|MX_IMR_RX_NOBUF|MX_IMR_RX_WATDOGTIMEO|\ 	MX_IMR_TX_NOBUF|MX_IMR_TX_UNDERRUN|MX_IMR_BUS_ERR|		\ 	MX_IMR_ABNORMAL|MX_IMR_NORMAL
comment|/*|MX_IMR_TX_EARLY*/
value|)
end_define

begin_comment
comment|/*  * Serial I/O (EEPROM/ROM) bits.  */
end_comment

begin_define
define|#
directive|define
name|MX_SIO_EE_CS
value|0x00000001
end_define

begin_comment
comment|/* EEPROM chip select */
end_comment

begin_define
define|#
directive|define
name|MX_SIO_EE_CLK
value|0x00000002
end_define

begin_comment
comment|/* EEPROM clock */
end_comment

begin_define
define|#
directive|define
name|MX_SIO_EE_DATAIN
value|0x00000004
end_define

begin_comment
comment|/* EEPROM data output */
end_comment

begin_define
define|#
directive|define
name|MX_SIO_EE_DATAOUT
value|0x00000008
end_define

begin_comment
comment|/* EEPROM data input */
end_comment

begin_define
define|#
directive|define
name|MX_SIO_ROMDATA4
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MX_SIO_ROMDATA5
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MX_SIO_ROMDATA6
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MX_SIO_ROMDATA7
value|0x00000080
end_define

begin_define
define|#
directive|define
name|MX_SIO_EESEL
value|0x00000800
end_define

begin_define
define|#
directive|define
name|MX_SIO_ROMSEL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|MX_SIO_ROMCTL_WRITE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|MX_SIO_ROMCTL_READ
value|0x00004000
end_define

begin_define
define|#
directive|define
name|MX_SIO_MII_CLK
value|0x00010000
end_define

begin_comment
comment|/* MDIO clock */
end_comment

begin_define
define|#
directive|define
name|MX_SIO_MII_DATAOUT
value|0x00020000
end_define

begin_comment
comment|/* MDIO data out */
end_comment

begin_define
define|#
directive|define
name|MX_SIO_MII_DIR
value|0x00040000
end_define

begin_comment
comment|/* MDIO dir */
end_comment

begin_define
define|#
directive|define
name|MX_SIO_MII_DATAIN
value|0x00080000
end_define

begin_comment
comment|/* MDIO data in */
end_comment

begin_define
define|#
directive|define
name|MX_EECMD_WRITE
value|0x140
end_define

begin_define
define|#
directive|define
name|MX_EECMD_READ
value|0x180
end_define

begin_define
define|#
directive|define
name|MX_EECMD_ERASE
value|0x1c0
end_define

begin_define
define|#
directive|define
name|MX_EE_NODEADDR_OFFSET
value|0x70
end_define

begin_define
define|#
directive|define
name|MX_EE_NODEADDR
value|10
end_define

begin_comment
comment|/*  * General purpose timer register  */
end_comment

begin_define
define|#
directive|define
name|MX_TIMER_VALUE
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|MX_TIMER_CONTINUUS
value|0x00010000
end_define

begin_comment
comment|/*  * 10baseT status register  */
end_comment

begin_define
define|#
directive|define
name|MX_TSTAT_LS100
value|0x00000002
end_define

begin_comment
comment|/* link status of 100baseTX */
end_comment

begin_define
define|#
directive|define
name|MX_TSTAT_LS10
value|0x00000004
end_define

begin_comment
comment|/* link status of 10baseT */
end_comment

begin_define
define|#
directive|define
name|MX_TSTAT_AUTOPOLARITY
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MX_TSTAT_REMFAULT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|MX_TSTAT_ANEGSTAT
value|0x00007000
end_define

begin_define
define|#
directive|define
name|MX_TSTAT_LP_CAN_NWAY
value|0x00008000
end_define

begin_comment
comment|/* link partner supports NWAY */
end_comment

begin_define
define|#
directive|define
name|MX_TSTAT_LPCODEWORD
value|0xFFFF0000
end_define

begin_comment
comment|/* link partner's code word */
end_comment

begin_define
define|#
directive|define
name|MX_ASTAT_DISABLE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MX_ASTAT_TXDISABLE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|MX_ASTAT_ABDETECT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|MX_ASTAT_ACKDETECT
value|0x00003000
end_define

begin_define
define|#
directive|define
name|MX_ASTAT_CMPACKDETECT
value|0x00004000
end_define

begin_define
define|#
directive|define
name|MX_ASTAT_AUTONEGCMP
value|0x00005000
end_define

begin_define
define|#
directive|define
name|MX_ASTAT_LINKCHECK
value|0x00006000
end_define

begin_comment
comment|/*  * PHY reset register  */
end_comment

begin_define
define|#
directive|define
name|MX_SIA_RESET_NWAY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MX_SIA_RESET_100TX
value|0x00000002
end_define

begin_comment
comment|/*  * 10baseT control register  */
end_comment

begin_define
define|#
directive|define
name|MX_TCTL_LOOPBACK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MX_TCTL_POWERDOWN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MX_TCTL_HALFDUPLEX
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MX_TCTL_AUTONEGENBL
value|0x00000080
end_define

begin_define
define|#
directive|define
name|MX_TCTL_RX_SQUELCH
value|0x00000100
end_define

begin_define
define|#
directive|define
name|MX_TCTL_LINKTEST
value|0x00001000
end_define

begin_define
define|#
directive|define
name|MX_TCTL_100BTXHALF
value|0x00010000
end_define

begin_define
define|#
directive|define
name|MX_TCTL_100BTXFULL
value|0x00020000
end_define

begin_define
define|#
directive|define
name|MX_TCTL_100BT4
value|0x00040000
end_define

begin_comment
comment|/*  * Watchdog timer register  */
end_comment

begin_define
define|#
directive|define
name|MX_WDOG_JABBERDIS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MX_WDOG_HOSTUNJAB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MX_WDOG_JABBERCLK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MX_WDOG_RXWDOGDIS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MX_WDOG_RXWDOGCLK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MX_WDOG_MUSTBEZERO
value|0x00000100
end_define

begin_comment
comment|/*  * Magic packet register  */
end_comment

begin_define
define|#
directive|define
name|MX_MPACK_DISABLE
value|0x00400000
end_define

begin_comment
comment|/*  * NWAY status register.  */
end_comment

begin_define
define|#
directive|define
name|MX_NWAY_10BTHALF
value|0x08000000
end_define

begin_define
define|#
directive|define
name|MX_NWAY_10BTFULL
value|0x10000000
end_define

begin_define
define|#
directive|define
name|MX_NWAY_100BTHALF
value|0x20000000
end_define

begin_define
define|#
directive|define
name|MX_NWAY_100BTFULL
value|0x40000000
end_define

begin_define
define|#
directive|define
name|MX_NWAY_100BT4
value|0x80000000
end_define

begin_comment
comment|/*  * Size of a setup frame.  */
end_comment

begin_define
define|#
directive|define
name|MX_SFRAME_LEN
value|192
end_define

begin_comment
comment|/*  * Macronix TX/RX list structure.  */
end_comment

begin_struct
struct|struct
name|mx_desc
block|{
name|u_int32_t
name|mx_status
decl_stmt|;
name|u_int32_t
name|mx_ctl
decl_stmt|;
name|u_int32_t
name|mx_ptr1
decl_stmt|;
name|u_int32_t
name|mx_ptr2
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|mx_data
value|mx_ptr1
end_define

begin_define
define|#
directive|define
name|mx_next
value|mx_ptr2
end_define

begin_define
define|#
directive|define
name|MX_RXSTAT_FIFOOFLOW
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MX_RXSTAT_CRCERR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MX_RXSTAT_DRIBBLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MX_RXSTAT_WATCHDOG
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MX_RXSTAT_FRAMETYPE
value|0x00000020
end_define

begin_comment
comment|/* 0 == IEEE 802.3 */
end_comment

begin_define
define|#
directive|define
name|MX_RXSTAT_COLLSEEN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MX_RXSTAT_GIANT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|MX_RXSTAT_LASTFRAG
value|0x00000100
end_define

begin_define
define|#
directive|define
name|MX_RXSTAT_FIRSTFRAG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|MX_RXSTAT_MULTICAST
value|0x00000400
end_define

begin_define
define|#
directive|define
name|MX_RXSTAT_RUNT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|MX_RXSTAT_RXTYPE
value|0x00003000
end_define

begin_define
define|#
directive|define
name|MX_RXSTAT_RXERR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|MX_RXSTAT_RXLEN
value|0x3FFF0000
end_define

begin_define
define|#
directive|define
name|MX_RXSTAT_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MX_RXBYTES
parameter_list|(
name|x
parameter_list|)
value|((x& MX_RXSTAT_RXLEN)>> 16)
end_define

begin_define
define|#
directive|define
name|MX_RXSTAT
value|(MX_RXSTAT_FIRSTFRAG|MX_RXSTAT_LASTFRAG|MX_RXSTAT_OWN)
end_define

begin_define
define|#
directive|define
name|MX_RXCTL_BUFLEN1
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|MX_RXCTL_BUFLEN2
value|0x00FFF000
end_define

begin_define
define|#
directive|define
name|MX_RXCTL_RLINK
value|0x01000000
end_define

begin_define
define|#
directive|define
name|MX_RXCTL_RLAST
value|0x02000000
end_define

begin_define
define|#
directive|define
name|MX_TXSTAT_DEFER
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MX_TXSTAT_UNDERRUN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MX_TXSTAT_LINKFAIl
value|0x00000003
end_define

begin_define
define|#
directive|define
name|MX_TXSTAT_COLLCNT
value|0x00000078
end_define

begin_define
define|#
directive|define
name|MX_TXSTAT_SQE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|MX_TXSTAT_EXCESSCOLL
value|0x00000100
end_define

begin_define
define|#
directive|define
name|MX_TXSTAT_LATECOLL
value|0x00000200
end_define

begin_define
define|#
directive|define
name|MX_TXSTAT_NOCARRIER
value|0x00000400
end_define

begin_define
define|#
directive|define
name|MX_TXSTAT_CARRLOST
value|0x00000800
end_define

begin_define
define|#
directive|define
name|MX_TXSTAT_JABTIMEO
value|0x00004000
end_define

begin_define
define|#
directive|define
name|MX_TXSTAT_ERRSUM
value|0x00008000
end_define

begin_define
define|#
directive|define
name|MX_TXSTAT_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MX_TXCTL_BUFLEN1
value|0x000007FF
end_define

begin_define
define|#
directive|define
name|MX_TXCTL_BUFLEN2
value|0x003FF800
end_define

begin_define
define|#
directive|define
name|MX_TXCTL_FILTTYPE0
value|0x00400000
end_define

begin_define
define|#
directive|define
name|MX_TXCTL_PAD
value|0x00800000
end_define

begin_define
define|#
directive|define
name|MX_TXCTL_TLINK
value|0x01000000
end_define

begin_define
define|#
directive|define
name|MX_TXCTL_TLAST
value|0x02000000
end_define

begin_define
define|#
directive|define
name|MX_TXCTL_NOCRC
value|0x04000000
end_define

begin_define
define|#
directive|define
name|MX_TXCTL_SETUP
value|0x08000000
end_define

begin_define
define|#
directive|define
name|MX_TXCTL_FILTTYPE1
value|0x10000000
end_define

begin_define
define|#
directive|define
name|MX_TXCTL_FIRSTFRAG
value|0x20000000
end_define

begin_define
define|#
directive|define
name|MX_TXCTL_LASTFRAG
value|0x40000000
end_define

begin_define
define|#
directive|define
name|MX_TXCTL_FINT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MX_FILTER_PERFECT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MX_FILTER_HASHPERF
value|0x00400000
end_define

begin_define
define|#
directive|define
name|MX_FILTER_INVERSE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|MX_FILTER_HASHONLY
value|0x10400000
end_define

begin_define
define|#
directive|define
name|MX_MAXFRAGS
value|16
end_define

begin_define
define|#
directive|define
name|MX_RX_LIST_CNT
value|64
end_define

begin_define
define|#
directive|define
name|MX_TX_LIST_CNT
value|128
end_define

begin_define
define|#
directive|define
name|MX_MIN_FRAMELEN
value|60
end_define

begin_comment
comment|/*  * A tx 'super descriptor' is actually 16 regular descriptors  * back to back.  */
end_comment

begin_struct
struct|struct
name|mx_txdesc
block|{
name|struct
name|mx_desc
name|mx_frag
index|[
name|MX_MAXFRAGS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MX_TXNEXT
parameter_list|(
name|x
parameter_list|)
value|x->mx_ptr->mx_frag[x->mx_lastdesc].mx_next
end_define

begin_define
define|#
directive|define
name|MX_TXSTATUS
parameter_list|(
name|x
parameter_list|)
value|x->mx_ptr->mx_frag[x->mx_lastdesc].mx_status
end_define

begin_define
define|#
directive|define
name|MX_TXCTL
parameter_list|(
name|x
parameter_list|)
value|x->mx_ptr->mx_frag[x->mx_lastdesc].mx_ctl
end_define

begin_define
define|#
directive|define
name|MX_TXDATA
parameter_list|(
name|x
parameter_list|)
value|x->mx_ptr->mx_frag[x->mx_lastdesc].mx_data
end_define

begin_define
define|#
directive|define
name|MX_TXOWN
parameter_list|(
name|x
parameter_list|)
value|x->mx_ptr->mx_frag[0].mx_status
end_define

begin_struct
struct|struct
name|mx_list_data
block|{
name|struct
name|mx_desc
name|mx_rx_list
index|[
name|MX_RX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|mx_txdesc
name|mx_tx_list
index|[
name|MX_TX_LIST_CNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mx_chain
block|{
name|struct
name|mx_txdesc
modifier|*
name|mx_ptr
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|mx_mbuf
decl_stmt|;
name|struct
name|mx_chain
modifier|*
name|mx_nextdesc
decl_stmt|;
name|u_int8_t
name|mx_lastdesc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mx_chain_onefrag
block|{
name|struct
name|mx_desc
modifier|*
name|mx_ptr
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|mx_mbuf
decl_stmt|;
name|struct
name|mx_chain_onefrag
modifier|*
name|mx_nextdesc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mx_chain_data
block|{
name|struct
name|mx_desc
name|mx_sframe
decl_stmt|;
name|u_int32_t
name|mx_sbuf
index|[
name|MX_SFRAME_LEN
operator|/
sizeof|sizeof
argument_list|(
name|u_int32_t
argument_list|)
index|]
decl_stmt|;
name|u_int8_t
name|mx_pad
index|[
name|MX_MIN_FRAMELEN
index|]
decl_stmt|;
name|struct
name|mx_chain_onefrag
name|mx_rx_chain
index|[
name|MX_RX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|mx_chain
name|mx_tx_chain
index|[
name|MX_TX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|mx_chain_onefrag
modifier|*
name|mx_rx_head
decl_stmt|;
name|struct
name|mx_chain
modifier|*
name|mx_tx_head
decl_stmt|;
name|struct
name|mx_chain
modifier|*
name|mx_tx_tail
decl_stmt|;
name|struct
name|mx_chain
modifier|*
name|mx_tx_free
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mx_type
block|{
name|u_int16_t
name|mx_vid
decl_stmt|;
name|u_int16_t
name|mx_did
decl_stmt|;
name|char
modifier|*
name|mx_name
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mx_mii_frame
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
name|MX_MII_STARTDELIM
value|0x01
end_define

begin_define
define|#
directive|define
name|MX_MII_READOP
value|0x02
end_define

begin_define
define|#
directive|define
name|MX_MII_WRITEOP
value|0x01
end_define

begin_define
define|#
directive|define
name|MX_MII_TURNAROUND
value|0x02
end_define

begin_define
define|#
directive|define
name|MX_FLAG_FORCEDELAY
value|1
end_define

begin_define
define|#
directive|define
name|MX_FLAG_SCHEDDELAY
value|2
end_define

begin_define
define|#
directive|define
name|MX_FLAG_DELAYTIMEO
value|3
end_define

begin_struct
struct|struct
name|mx_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
comment|/* interface info */
name|struct
name|ifmedia
name|ifmedia
decl_stmt|;
comment|/* media info */
name|bus_space_handle_t
name|mx_bhandle
decl_stmt|;
comment|/* bus space handle */
name|bus_space_tag_t
name|mx_btag
decl_stmt|;
comment|/* bus space tag */
name|struct
name|mx_type
modifier|*
name|mx_info
decl_stmt|;
comment|/* Macronix adapter info */
name|struct
name|mx_type
modifier|*
name|mx_pinfo
decl_stmt|;
comment|/* phy info */
name|u_int8_t
name|mx_unit
decl_stmt|;
comment|/* interface number */
name|u_int8_t
name|mx_type
decl_stmt|;
name|u_int8_t
name|mx_phy_addr
decl_stmt|;
comment|/* PHY address */
name|u_int8_t
name|mx_tx_pend
decl_stmt|;
comment|/* TX pending */
name|u_int8_t
name|mx_want_auto
decl_stmt|;
name|u_int8_t
name|mx_autoneg
decl_stmt|;
name|u_int8_t
name|mx_cachesize
decl_stmt|;
name|caddr_t
name|mx_ldata_ptr
decl_stmt|;
name|struct
name|mx_list_data
modifier|*
name|mx_ldata
decl_stmt|;
name|struct
name|mx_chain_data
name|mx_cdata
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
value|bus_space_write_4(sc->mx_btag, sc->mx_bhandle, reg, val)
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
value|bus_space_write_2(sc->mx_btag, sc->mx_bhandle, reg, val)
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
value|bus_space_write_1(sc->mx_btag, sc->mx_bhandle, reg, val)
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
value|bus_space_read_4(sc->mx_btag, sc->mx_bhandle, reg)
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
value|bus_space_read_2(sc->mx_btag, sc->mx_bhandle, reg)
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
value|bus_space_read_1(sc->mx_btag, sc->mx_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|MX_TIMEOUT
value|1000
end_define

begin_comment
comment|/*  * General constants that are fun to know.  *  * Macronix PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|MX_VENDORID
value|0x10D9
end_define

begin_comment
comment|/*  * Macronix PMAC device IDs.  */
end_comment

begin_define
define|#
directive|define
name|MX_DEVICEID_98713
value|0x0512
end_define

begin_define
define|#
directive|define
name|MX_DEVICEID_987x5
value|0x0531
end_define

begin_comment
comment|/*  * Compex PCI vendor ID.  */
end_comment

begin_define
define|#
directive|define
name|CP_VENDORID
value|0x11F6
end_define

begin_comment
comment|/*  * Compex PMAC PCI device IDs.  */
end_comment

begin_define
define|#
directive|define
name|CP_DEVICEID_98713
value|0x9881
end_define

begin_comment
comment|/*   * Lite-On PNIC PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|PN_VENDORID
value|0x11AD
end_define

begin_comment
comment|/*      * Lite-On PNIC II device ID. Note: this is actually a Macronix 98715A  * with wake on lan/magic packet support.  */
end_comment

begin_define
define|#
directive|define
name|PN_DEVICEID_PNIC_II
value|0xc115
end_define

begin_comment
comment|/*  * Texas Instruments PHY identifiers  */
end_comment

begin_define
define|#
directive|define
name|TI_PHY_VENDORID
value|0x4000
end_define

begin_define
define|#
directive|define
name|TI_PHY_10BT
value|0x501F
end_define

begin_define
define|#
directive|define
name|TI_PHY_100VGPMI
value|0x502F
end_define

begin_comment
comment|/*  * These ID values are for the NS DP83840A 10/100 PHY  */
end_comment

begin_define
define|#
directive|define
name|NS_PHY_VENDORID
value|0x2000
end_define

begin_define
define|#
directive|define
name|NS_PHY_83840A
value|0x5C0F
end_define

begin_comment
comment|/*  * Level 1 10/100 PHY  */
end_comment

begin_define
define|#
directive|define
name|LEVEL1_PHY_VENDORID
value|0x7810
end_define

begin_define
define|#
directive|define
name|LEVEL1_PHY_LXT970
value|0x000F
end_define

begin_comment
comment|/*  * Intel 82555 10/100 PHY  */
end_comment

begin_define
define|#
directive|define
name|INTEL_PHY_VENDORID
value|0x0A28
end_define

begin_define
define|#
directive|define
name|INTEL_PHY_82555
value|0x015F
end_define

begin_comment
comment|/*  * SEEQ 80220 10/100 PHY  */
end_comment

begin_define
define|#
directive|define
name|SEEQ_PHY_VENDORID
value|0x0016
end_define

begin_define
define|#
directive|define
name|SEEQ_PHY_80220
value|0xF83F
end_define

begin_comment
comment|/*  * PCI low memory base and low I/O base register, and  * other PCI registers.  */
end_comment

begin_define
define|#
directive|define
name|MX_PCI_VENDOR_ID
value|0x00
end_define

begin_define
define|#
directive|define
name|MX_PCI_DEVICE_ID
value|0x02
end_define

begin_define
define|#
directive|define
name|MX_PCI_COMMAND
value|0x04
end_define

begin_define
define|#
directive|define
name|MX_PCI_STATUS
value|0x06
end_define

begin_define
define|#
directive|define
name|MX_PCI_REVID
value|0x08
end_define

begin_define
define|#
directive|define
name|MX_PCI_CLASSCODE
value|0x09
end_define

begin_define
define|#
directive|define
name|MX_PCI_CACHELEN
value|0x0C
end_define

begin_define
define|#
directive|define
name|MX_PCI_LATENCY_TIMER
value|0x0D
end_define

begin_define
define|#
directive|define
name|MX_PCI_HEADER_TYPE
value|0x0E
end_define

begin_define
define|#
directive|define
name|MX_PCI_LOIO
value|0x10
end_define

begin_define
define|#
directive|define
name|MX_PCI_LOMEM
value|0x14
end_define

begin_define
define|#
directive|define
name|MX_PCI_BIOSROM
value|0x30
end_define

begin_define
define|#
directive|define
name|MX_PCI_INTLINE
value|0x3C
end_define

begin_define
define|#
directive|define
name|MX_PCI_INTPIN
value|0x3D
end_define

begin_define
define|#
directive|define
name|MX_PCI_MINGNT
value|0x3E
end_define

begin_define
define|#
directive|define
name|MX_PCI_MINLAT
value|0x0F
end_define

begin_define
define|#
directive|define
name|MX_PCI_RESETOPT
value|0x48
end_define

begin_define
define|#
directive|define
name|MX_PCI_EEPROM_DATA
value|0x4C
end_define

begin_comment
comment|/* power management registers */
end_comment

begin_define
define|#
directive|define
name|MX_PCI_CAPID
value|0x44
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|MX_PCI_NEXTPTR
value|0x45
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|MX_PCI_PWRMGMTCAP
value|0x46
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|MX_PCI_PWRMGMTCTRL
value|0x48
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|MX_PSTATE_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|MX_PSTATE_D0
value|0x0000
end_define

begin_define
define|#
directive|define
name|MX_PSTATE_D1
value|0x0001
end_define

begin_define
define|#
directive|define
name|MX_PSTATE_D2
value|0x0002
end_define

begin_define
define|#
directive|define
name|MX_PSTATE_D3
value|0x0003
end_define

begin_define
define|#
directive|define
name|MX_PME_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|MX_PME_STATUS
value|0x8000
end_define

begin_define
define|#
directive|define
name|PHY_UNKNOWN
value|6
end_define

begin_define
define|#
directive|define
name|MX_PHYADDR_MIN
value|0x00
end_define

begin_define
define|#
directive|define
name|MX_PHYADDR_MAX
value|0x1F
end_define

begin_define
define|#
directive|define
name|PHY_BMCR
value|0x00
end_define

begin_define
define|#
directive|define
name|PHY_BMSR
value|0x01
end_define

begin_define
define|#
directive|define
name|PHY_VENID
value|0x02
end_define

begin_define
define|#
directive|define
name|PHY_DEVID
value|0x03
end_define

begin_define
define|#
directive|define
name|PHY_ANAR
value|0x04
end_define

begin_define
define|#
directive|define
name|PHY_LPAR
value|0x05
end_define

begin_define
define|#
directive|define
name|PHY_ANEXP
value|0x06
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_NEXTPAGE
value|0x8000
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_RSVD0
value|0x4000
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_TLRFLT
value|0x2000
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_RSVD1
value|0x1000
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_RSVD2
value|0x0800
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_RSVD3
value|0x0400
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_100BT4
value|0x0200
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_100BTXFULL
value|0x0100
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_100BTXHALF
value|0x0080
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_10BTFULL
value|0x0040
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_10BTHALF
value|0x0020
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_PROTO4
value|0x0010
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_PROTO3
value|0x0008
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_PROTO2
value|0x0004
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_PROTO1
value|0x0002
end_define

begin_define
define|#
directive|define
name|PHY_ANAR_PROTO0
value|0x0001
end_define

begin_comment
comment|/*  * These are the register definitions for the PHY (physical layer  * interface chip).  */
end_comment

begin_comment
comment|/*  * PHY BMCR Basic Mode Control Register  */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RESET
value|0x8000
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_LOOPBK
value|0x4000
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_SPEEDSEL
value|0x2000
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_AUTONEGENBL
value|0x1000
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD0
value|0x0800
end_define

begin_comment
comment|/* write as zero */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_ISOLATE
value|0x0400
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_AUTONEGRSTR
value|0x0200
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_DUPLEX
value|0x0100
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_COLLTEST
value|0x0080
end_define

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD1
value|0x0040
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD2
value|0x0020
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD3
value|0x0010
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD4
value|0x0008
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD5
value|0x0004
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD6
value|0x0002
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMCR_RSVD7
value|0x0001
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_comment
comment|/*  * RESET: 1 == software reset, 0 == normal operation  * Resets status and control registers to default values.  * Relatches all hardware config values.  *  * LOOPBK: 1 == loopback operation enabled, 0 == normal operation  *  * SPEEDSEL: 1 == 100Mb/s, 0 == 10Mb/s  * Link speed is selected byt his bit or if auto-negotiation if bit  * 12 (AUTONEGENBL) is set (in which case the value of this register  * is ignored).  *  * AUTONEGENBL: 1 == Autonegotiation enabled, 0 == Autonegotiation disabled  * Bits 8 and 13 are ignored when autoneg is set, otherwise bits 8 and 13  * determine speed and mode. Should be cleared and then set if PHY configured  * for no autoneg on startup.  *  * ISOLATE: 1 == isolate PHY from MII, 0 == normal operation  *  * AUTONEGRSTR: 1 == restart autonegotiation, 0 = normal operation  *  * DUPLEX: 1 == full duplex mode, 0 == half duplex mode  *  * COLLTEST: 1 == collision test enabled, 0 == normal operation  */
end_comment

begin_comment
comment|/*   * PHY, BMSR Basic Mode Status Register   */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_100BT4
value|0x8000
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_100BTXFULL
value|0x4000
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_100BTXHALF
value|0x2000
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_10BTFULL
value|0x1000
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_10BTHALF
value|0x0800
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_RSVD1
value|0x0400
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_RSVD2
value|0x0200
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_RSVD3
value|0x0100
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_RSVD4
value|0x0080
end_define

begin_comment
comment|/* write as zero, don't care */
end_comment

begin_define
define|#
directive|define
name|PHY_BMSR_MFPRESUP
value|0x0040
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_AUTONEGCOMP
value|0x0020
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_REMFAULT
value|0x0010
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_CANAUTONEG
value|0x0008
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_LINKSTAT
value|0x0004
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_JABBER
value|0x0002
end_define

begin_define
define|#
directive|define
name|PHY_BMSR_EXTENDED
value|0x0001
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
value|(pmap_kextract(((vm_offset_t) (va))) \ 					+ 1*1024*1024*1024)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

