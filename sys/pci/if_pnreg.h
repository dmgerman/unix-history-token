begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  *	$Id: if_pnreg.h,v 1.4.2.8 1999/05/28 18:53:35 wpaul Exp $  */
end_comment

begin_comment
comment|/*  * PNIC register definitions.  */
end_comment

begin_define
define|#
directive|define
name|PN_BUSCTL
value|0x00
end_define

begin_comment
comment|/* bus control */
end_comment

begin_define
define|#
directive|define
name|PN_TXSTART
value|0x08
end_define

begin_comment
comment|/* tx start demand */
end_comment

begin_define
define|#
directive|define
name|PN_RXSTART
value|0x10
end_define

begin_comment
comment|/* rx start demand */
end_comment

begin_define
define|#
directive|define
name|PN_RXADDR
value|0x18
end_define

begin_comment
comment|/* rx descriptor list start addr */
end_comment

begin_define
define|#
directive|define
name|PN_TXADDR
value|0x20
end_define

begin_comment
comment|/* tx descriptor list start addr */
end_comment

begin_define
define|#
directive|define
name|PN_ISR
value|0x28
end_define

begin_comment
comment|/* interrupt status register */
end_comment

begin_define
define|#
directive|define
name|PN_NETCFG
value|0x30
end_define

begin_comment
comment|/* network config register */
end_comment

begin_define
define|#
directive|define
name|PN_IMR
value|0x38
end_define

begin_comment
comment|/* interrupt mask */
end_comment

begin_define
define|#
directive|define
name|PN_FRAMESDISCARDED
value|0x40
end_define

begin_comment
comment|/* # of discarded frames */
end_comment

begin_define
define|#
directive|define
name|PN_SIO
value|0x48
end_define

begin_comment
comment|/* MII and ROM/EEPROM access */
end_comment

begin_define
define|#
directive|define
name|PN_GEN
value|0x60
end_define

begin_comment
comment|/* general purpose register */
end_comment

begin_define
define|#
directive|define
name|PN_ENDEC
value|0x78
end_define

begin_comment
comment|/* ENDEC general register */
end_comment

begin_define
define|#
directive|define
name|PN_SIOPWR
value|0x90
end_define

begin_comment
comment|/* serial eeprom power up */
end_comment

begin_define
define|#
directive|define
name|PN_SIOCTL
value|0x98
end_define

begin_comment
comment|/* EEPROM control register */
end_comment

begin_define
define|#
directive|define
name|PN_MII
value|0xA0
end_define

begin_comment
comment|/* MII access register */
end_comment

begin_define
define|#
directive|define
name|PN_NWAY
value|0xB8
end_define

begin_comment
comment|/* Internal NWAY register */
end_comment

begin_comment
comment|/*  * Bus control bits.  */
end_comment

begin_define
define|#
directive|define
name|PN_BUSCTL_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PN_BUSCTL_ARBITRATION
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PN_BUSCTL_SKIPLEN
value|0x0000007C
end_define

begin_define
define|#
directive|define
name|PN_BUSCTL_BUF_BIGENDIAN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|PN_BUSCTL_BURSTLEN
value|0x00003F00
end_define

begin_define
define|#
directive|define
name|PN_BUSCTL_CACHEALIGN
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|PN_BUSCTL_TXPOLL
value|0x000E0000
end_define

begin_define
define|#
directive|define
name|PN_BUSCTL_MUSTBEONE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|PN_SKIPLEN_1LONG
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PN_SKIPLEN_2LONG
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PN_SKIPLEN_3LONG
value|0x00000010
end_define

begin_define
define|#
directive|define
name|PN_SKIPLEN_4LONG
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PN_SKIPLEN_5LONG
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PN_CACHEALIGN_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PN_CACHEALIGN_8LONG
value|0x00004000
end_define

begin_define
define|#
directive|define
name|PN_CACHEALIGN_16LONG
value|0x00008000
end_define

begin_define
define|#
directive|define
name|PN_CACHEALIGN_32LONG
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|PN_BURSTLEN_USECA
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PN_BURSTLEN_1LONG
value|0x00000100
end_define

begin_define
define|#
directive|define
name|PN_BURSTLEN_2LONG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|PN_BURSTLEN_4LONG
value|0x00000400
end_define

begin_define
define|#
directive|define
name|PN_BURSTLEN_8LONG
value|0x00000800
end_define

begin_define
define|#
directive|define
name|PN_BURSTLEN_16LONG
value|0x00001000
end_define

begin_define
define|#
directive|define
name|PN_BURSTLEN_32LONG
value|0x00002000
end_define

begin_define
define|#
directive|define
name|PN_TXPOLL_OFF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PN_TXPOLL_200U
value|0x00020000
end_define

begin_define
define|#
directive|define
name|PN_TXPOLL_800U
value|0x00040000
end_define

begin_define
define|#
directive|define
name|PN_TXPOLL_1600U
value|0x00060000
end_define

begin_define
define|#
directive|define
name|PN_TXPOLL_12_8M
value|0x00080000
end_define

begin_define
define|#
directive|define
name|PN_TXPOLL_25_6M
value|0x000A0000
end_define

begin_define
define|#
directive|define
name|PN_TXPOLL_51_2M
value|0x000C0000
end_define

begin_define
define|#
directive|define
name|PN_TXPOLL_102_4M
value|0x000E0000
end_define

begin_define
define|#
directive|define
name|PN_BUSCTL_CONFIG
define|\
value|(PN_CACHEALIGN_8LONG|PN_BURSTLEN_8LONG)
end_define

begin_comment
comment|/*  * Interrupt status bits.  */
end_comment

begin_define
define|#
directive|define
name|PN_ISR_TX_OK
value|0x00000001
end_define

begin_comment
comment|/* packet tx ok */
end_comment

begin_define
define|#
directive|define
name|PN_ISR_TX_IDLE
value|0x00000002
end_define

begin_comment
comment|/* tx stopped */
end_comment

begin_define
define|#
directive|define
name|PN_ISR_TX_NOBUF
value|0x00000004
end_define

begin_comment
comment|/* no tx buffer available */
end_comment

begin_define
define|#
directive|define
name|PN_ISR_TX_JABTIMEO
value|0x00000008
end_define

begin_comment
comment|/* jabber timeout */
end_comment

begin_define
define|#
directive|define
name|PN_ISR_LINKPASS
value|0x00000010
end_define

begin_comment
comment|/* link test pass */
end_comment

begin_define
define|#
directive|define
name|PN_ISR_TX_UNDERRUN
value|0x00000020
end_define

begin_comment
comment|/* transmit underrun */
end_comment

begin_define
define|#
directive|define
name|PN_ISR_RX_OK
value|0x00000040
end_define

begin_comment
comment|/* packet rx ok */
end_comment

begin_define
define|#
directive|define
name|PN_ISR_RX_NOBUF
value|0x00000080
end_define

begin_comment
comment|/* rx buffer unavailable */
end_comment

begin_define
define|#
directive|define
name|PN_ISR_RX_IDLE
value|0x00000100
end_define

begin_comment
comment|/* rx stopped */
end_comment

begin_define
define|#
directive|define
name|PN_ISR_RX_WATCHDOG
value|0x00000200
end_define

begin_comment
comment|/* rx watchdog timeo */
end_comment

begin_define
define|#
directive|define
name|PN_ISR_TX_EARLY
value|0x00000400
end_define

begin_comment
comment|/* rx watchdog timeo */
end_comment

begin_define
define|#
directive|define
name|PN_ISR_LINKFAIL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|PN_ISR_BUS_ERR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|PN_ISR_ABNORMAL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|PN_ISR_NORMAL
value|0x00010000
end_define

begin_define
define|#
directive|define
name|PN_ISR_RX_STATE
value|0x000E0000
end_define

begin_define
define|#
directive|define
name|PN_ISR_TX_STATE
value|0x00700000
end_define

begin_define
define|#
directive|define
name|PN_ISR_BUSERRTYPE
value|0x03800000
end_define

begin_define
define|#
directive|define
name|PN_ISR_TXABORT
value|0x04000000
end_define

begin_comment
comment|/* tx abort */
end_comment

begin_define
define|#
directive|define
name|PN_RXSTATE_STOPPED
value|0x00000000
end_define

begin_comment
comment|/* 000 - Stopped */
end_comment

begin_define
define|#
directive|define
name|PN_RXSTATE_FETCH
value|0x00020000
end_define

begin_comment
comment|/* 001 - Fetching descriptor */
end_comment

begin_define
define|#
directive|define
name|PN_RXSTATE_ENDCHECK
value|0x00040000
end_define

begin_comment
comment|/* 010 - check for rx end */
end_comment

begin_define
define|#
directive|define
name|PN_RXSTATE_WAIT
value|0x00060000
end_define

begin_comment
comment|/* 011 - waiting for packet */
end_comment

begin_define
define|#
directive|define
name|PN_RXSTATE_SUSPEND
value|0x00080000
end_define

begin_comment
comment|/* 100 - suspend rx */
end_comment

begin_define
define|#
directive|define
name|PN_RXSTATE_CLOSE
value|0x000A0000
end_define

begin_comment
comment|/* 101 - close rx desc */
end_comment

begin_define
define|#
directive|define
name|PN_RXSTATE_FLUSH
value|0x000C0000
end_define

begin_comment
comment|/* 110 - flush from FIFO */
end_comment

begin_define
define|#
directive|define
name|PN_RXSTATE_DEQUEUE
value|0x000E0000
end_define

begin_comment
comment|/* 111 - dequeue from FIFO */
end_comment

begin_define
define|#
directive|define
name|PN_TXSTATE_RESET
value|0x00000000
end_define

begin_comment
comment|/* 000 - reset */
end_comment

begin_define
define|#
directive|define
name|PN_TXSTATE_FETCH
value|0x00100000
end_define

begin_comment
comment|/* 001 - fetching descriptor */
end_comment

begin_define
define|#
directive|define
name|PN_TXSTATE_WAITEND
value|0x00200000
end_define

begin_comment
comment|/* 010 - wait for tx end */
end_comment

begin_define
define|#
directive|define
name|PN_TXSTATE_READING
value|0x00300000
end_define

begin_comment
comment|/* 011 - read and enqueue */
end_comment

begin_define
define|#
directive|define
name|PN_TXSTATE_RSVD
value|0x00400000
end_define

begin_comment
comment|/* 100 - reserved */
end_comment

begin_define
define|#
directive|define
name|PN_TXSTATE_SETUP
value|0x00500000
end_define

begin_comment
comment|/* 101 - setup packet */
end_comment

begin_define
define|#
directive|define
name|PN_TXSTATE_SUSPEND
value|0x00600000
end_define

begin_comment
comment|/* 110 - suspend tx */
end_comment

begin_define
define|#
directive|define
name|PN_TXSTATE_CLOSE
value|0x00700000
end_define

begin_comment
comment|/* 111 - close tx desc */
end_comment

begin_define
define|#
directive|define
name|PN_BUSERR_PARITY
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PN_BUSERR_MASTABRT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|PN_BUSERR_TGTABRT
value|0x01000000
end_define

begin_define
define|#
directive|define
name|PN_BUSERR_RSVD1
value|0x01800000
end_define

begin_define
define|#
directive|define
name|PN_BUSERR_RSVD2
value|0x02000000
end_define

begin_comment
comment|/*  * Network config bits.  */
end_comment

begin_define
define|#
directive|define
name|PN_NETCFG_HASHPERF
value|0x00000001
end_define

begin_comment
comment|/* 0 == perf, 1 == hash */
end_comment

begin_define
define|#
directive|define
name|PN_NETCFG_RX_ON
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PN_NETCFG_HASHONLY
value|0x00000004
end_define

begin_comment
comment|/* 1 == allhash */
end_comment

begin_define
define|#
directive|define
name|PN_NETCFG_RX_PASSERR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PN_NETCFG_INVERSFILT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|PN_NETCFG_BACKOFF
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PN_NETCFG_RX_PROMISC
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PN_NETCFG_RX_ALLMULTI
value|0x00000080
end_define

begin_define
define|#
directive|define
name|PN_NETCFG_FLAKYOSC
value|0x00000100
end_define

begin_define
define|#
directive|define
name|PN_NETCFG_FULLDUPLEX
value|0x00000200
end_define

begin_define
define|#
directive|define
name|PN_NETCFG_OPERMODE
value|0x00000C00
end_define

begin_define
define|#
directive|define
name|PN_NETCFG_FORCECOLL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|PN_NETCFG_TX_ON
value|0x00002000
end_define

begin_define
define|#
directive|define
name|PN_NETCFG_TX_THRESH
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|PN_NETCFG_TX_BACKOFF
value|0x00020000
end_define

begin_define
define|#
directive|define
name|PN_NETCFG_MIIENB
value|0x00040000
end_define

begin_comment
comment|/* 1 == MII, 0 == internal */
end_comment

begin_define
define|#
directive|define
name|PN_NETCFG_HEARTBEAT
value|0x00080000
end_define

begin_comment
comment|/* 1 == disabled */
end_comment

begin_define
define|#
directive|define
name|PN_NETCFG_TX_IMMEDIATE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|PN_NETCFG_STORENFWD
value|0x00200000
end_define

begin_define
define|#
directive|define
name|PN_NETCFG_SPEEDSEL
value|0x00400000
end_define

begin_comment
comment|/* 1 == 10Mbps 0 == 100Mbps */
end_comment

begin_define
define|#
directive|define
name|PN_NETCFG_PCS
value|0x00800000
end_define

begin_comment
comment|/* 1 == 100baseTX */
end_comment

begin_define
define|#
directive|define
name|PN_NETCFG_SCRAMBLER
value|0x01000000
end_define

begin_define
define|#
directive|define
name|PN_NETCFG_NO_RXCRC
value|0x20000000
end_define

begin_define
define|#
directive|define
name|PN_NETCFG_EXT_ENDEC
value|0x40000000
end_define

begin_comment
comment|/* 1 == ext, 0 == int PHY */
end_comment

begin_define
define|#
directive|define
name|PN_OPMODE_NORM
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PN_OPMODE_INTLOOP
value|0x00000400
end_define

begin_define
define|#
directive|define
name|PN_OPMODE_EXTLOOP
value|0x00000800
end_define

begin_define
define|#
directive|define
name|PN_TXTHRESH_72BYTES
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PN_TXTHRESH_96BYTES
value|0x00004000
end_define

begin_define
define|#
directive|define
name|PN_TXTHRESH_128BYTES
value|0x00008000
end_define

begin_define
define|#
directive|define
name|PN_TXTHRESH_160BYTES
value|0x0000C000
end_define

begin_comment
comment|/*  * Interrupt mask bits.  */
end_comment

begin_define
define|#
directive|define
name|PN_IMR_TX_OK
value|0x00000001
end_define

begin_comment
comment|/* packet tx ok */
end_comment

begin_define
define|#
directive|define
name|PN_IMR_TX_IDLE
value|0x00000002
end_define

begin_comment
comment|/* tx stopped */
end_comment

begin_define
define|#
directive|define
name|PN_IMR_TX_NOBUF
value|0x00000004
end_define

begin_comment
comment|/* no tx buffer available */
end_comment

begin_define
define|#
directive|define
name|PN_IMR_TX_JABTIMEO
value|0x00000008
end_define

begin_comment
comment|/* jabber timeout */
end_comment

begin_define
define|#
directive|define
name|PN_IMR_LINKPASS
value|0x00000010
end_define

begin_comment
comment|/* link test pass */
end_comment

begin_define
define|#
directive|define
name|PN_IMR_TX_UNDERRUN
value|0x00000020
end_define

begin_comment
comment|/* transmit underrun */
end_comment

begin_define
define|#
directive|define
name|PN_IMR_RX_OK
value|0x00000040
end_define

begin_comment
comment|/* packet rx ok */
end_comment

begin_define
define|#
directive|define
name|PN_IMR_RX_NOBUF
value|0x00000080
end_define

begin_comment
comment|/* rx buffer unavailable */
end_comment

begin_define
define|#
directive|define
name|PN_IMR_RX_IDLE
value|0x00000100
end_define

begin_comment
comment|/* rx stopped */
end_comment

begin_define
define|#
directive|define
name|PN_IMR_RX_WATCHDOG
value|0x00000200
end_define

begin_comment
comment|/* rx watchdog timeo */
end_comment

begin_define
define|#
directive|define
name|PN_IMR_TX_EARLY
value|0x00000400
end_define

begin_comment
comment|/* rx watchdog timeo */
end_comment

begin_define
define|#
directive|define
name|PN_IMR_BUS_ERR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|PN_IMR_ABNORMAL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|PN_IMR_NORMAL
value|0x00010000
end_define

begin_define
define|#
directive|define
name|PN_ISR_TXABORT
value|0x04000000
end_define

begin_comment
comment|/* tx abort */
end_comment

begin_define
define|#
directive|define
name|PN_INTRS
define|\
value|(PN_IMR_RX_OK|PN_IMR_TX_OK|PN_IMR_RX_NOBUF|			\ 	PN_IMR_TX_NOBUF|PN_IMR_TX_UNDERRUN|PN_IMR_BUS_ERR|		\ 	PN_IMR_ABNORMAL|PN_IMR_NORMAL)
end_define

begin_comment
comment|/*  * Serial I/O (EEPROM/ROM) bits.  */
end_comment

begin_define
define|#
directive|define
name|PN_SIO_DATA
value|0x0000003F
end_define

begin_define
define|#
directive|define
name|PN_SIO_OPCODE
value|0x00000300
end_define

begin_define
define|#
directive|define
name|PN_SIO_BUSY
value|0x80000000
end_define

begin_comment
comment|/*  * SIOCTL/EEPROM bits  */
end_comment

begin_define
define|#
directive|define
name|PN_EE_READ
value|0x600
end_define

begin_comment
comment|/*  * General purpose register bits.  */
end_comment

begin_define
define|#
directive|define
name|PN_GEN_CTL
value|0x000000F0
end_define

begin_define
define|#
directive|define
name|PN_GEN_100TX_LINK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PN_GEN_BNC_ENB
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PN_GEN_100TX_LOOP
value|0x00000002
end_define

begin_comment
comment|/* 1 == normal, 0 == loop */
end_comment

begin_define
define|#
directive|define
name|PN_GEN_SPEEDSEL
value|0x00000001
end_define

begin_comment
comment|/* 1 == 100Mbps, 0 == 10Mbps */
end_comment

begin_define
define|#
directive|define
name|PN_GEN_MUSTBEONE
value|0x00000030
end_define

begin_comment
comment|/*  * General ENDEC bits.  */
end_comment

begin_define
define|#
directive|define
name|PN_ENDEC_JABBERDIS
value|0x000000001
end_define

begin_comment
comment|/* 1 == disable, 0 == enable */
end_comment

begin_comment
comment|/*  * MII bits.  */
end_comment

begin_define
define|#
directive|define
name|PN_MII_DATA
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|PN_MII_REGADDR
value|0x007C0000
end_define

begin_define
define|#
directive|define
name|PN_MII_PHYADDR
value|0x0F800000
end_define

begin_define
define|#
directive|define
name|PN_MII_OPCODE
value|0x30000000
end_define

begin_define
define|#
directive|define
name|PN_MII_RESERVED
value|0x00020000
end_define

begin_define
define|#
directive|define
name|PN_MII_BUSY
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PN_MII_READ
value|0x60020000
end_define

begin_comment
comment|/* read PHY command */
end_comment

begin_define
define|#
directive|define
name|PN_MII_WRITE
value|0x50020000
end_define

begin_comment
comment|/* write PHY command */
end_comment

begin_comment
comment|/*  * Internal PHY NWAY register bits.  */
end_comment

begin_define
define|#
directive|define
name|PN_NWAY_RESET
value|0x00000001
end_define

begin_comment
comment|/* reset */
end_comment

begin_define
define|#
directive|define
name|PN_NWAY_PDOWN
value|0x00000002
end_define

begin_comment
comment|/* power down */
end_comment

begin_define
define|#
directive|define
name|PN_NWAY_BYPASS
value|0x00000004
end_define

begin_comment
comment|/* bypass */
end_comment

begin_define
define|#
directive|define
name|PN_NWAY_AUILOWCUR
value|0x00000008
end_define

begin_comment
comment|/* AUI low current */
end_comment

begin_define
define|#
directive|define
name|PN_NWAY_TPEXTEND
value|0x00000010
end_define

begin_comment
comment|/* low squelch voltage */
end_comment

begin_define
define|#
directive|define
name|PN_NWAY_POLARITY
value|0x00000020
end_define

begin_comment
comment|/* 0 == on, 1 == off */
end_comment

begin_define
define|#
directive|define
name|PN_NWAY_TP
value|0x00000040
end_define

begin_comment
comment|/* 1 == tp, 0 == AUI */
end_comment

begin_define
define|#
directive|define
name|PN_NWAY_AUIVOLT
value|0x00000080
end_define

begin_comment
comment|/* 1 == full, 0 == half */
end_comment

begin_define
define|#
directive|define
name|PN_NWAY_DUPLEX
value|0x00000100
end_define

begin_comment
comment|/* 1 == full, 0 == half */
end_comment

begin_define
define|#
directive|define
name|PN_NWAY_LINKTEST
value|0x00000200
end_define

begin_comment
comment|/* 0 == on, 1 == off */
end_comment

begin_define
define|#
directive|define
name|PN_NWAY_AUTODETECT
value|0x00000400
end_define

begin_comment
comment|/* 1 == off, 0 == on */
end_comment

begin_define
define|#
directive|define
name|PN_NWAY_SPEEDSEL
value|0x00000800
end_define

begin_comment
comment|/* 0 == 10, 1 == 100 */
end_comment

begin_define
define|#
directive|define
name|PN_NWAY_NWAY_ENB
value|0x00001000
end_define

begin_comment
comment|/* 0 == off, 1 == on */
end_comment

begin_define
define|#
directive|define
name|PN_NWAY_CAP10HALF
value|0x00002000
end_define

begin_define
define|#
directive|define
name|PN_NWAY_CAP10FULL
value|0x00004000
end_define

begin_define
define|#
directive|define
name|PN_NWAY_CAP100FULL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|PN_NWAY_CAP100HALF
value|0x00010000
end_define

begin_define
define|#
directive|define
name|PN_NWAY_CAP100T4
value|0x00020000
end_define

begin_define
define|#
directive|define
name|PN_NWAY_AUTONEGRSTR
value|0x02000000
end_define

begin_define
define|#
directive|define
name|PN_NWAY_REMFAULT
value|0x04000000
end_define

begin_define
define|#
directive|define
name|PN_NWAY_LPAR10HALF
value|0x08000000
end_define

begin_define
define|#
directive|define
name|PN_NWAY_LPAR10FULL
value|0x10000000
end_define

begin_define
define|#
directive|define
name|PN_NWAY_LPAR100FULL
value|0x20000000
end_define

begin_define
define|#
directive|define
name|PN_NWAY_LPAR100HALF
value|0x40000000
end_define

begin_define
define|#
directive|define
name|PN_NWAY_LPAR100T4
value|0x80000000
end_define

begin_comment
comment|/*  * Nway register bits that must be set to turn on to initiate  * an autoneg session with all modes advertized and AUI disabled.  */
end_comment

begin_define
define|#
directive|define
name|PN_NWAY_AUTOENB
define|\
value|(PN_NWAY_AUILOWCUR|PN_NWAY_TPEXTEND|PN_NWAY_POLARITY|PN_NWAY_TP	\ 	 |PN_NWAY_NWAY_ENB|PN_NWAY_CAP10HALF|PN_NWAY_CAP10FULL|		\ 	 PN_NWAY_CAP100FULL|PN_NWAY_CAP100HALF|PN_NWAY_CAP100T4|	\ 	 PN_NWAY_AUTONEGRSTR)
end_define

begin_define
define|#
directive|define
name|PN_NWAY_MODE_10HD
define|\
value|(PN_NWAY_CAP10HALF|PN_NWAY_CAP10FULL|		\ 	 PN_NWAY_CAP100FULL|PN_NWAY_CAP100HALF|PN_NWAY_CAP100T4|	\ 	 PN_NWAY_AUILOWCUR|PN_NWAY_TPEXTEND|PN_NWAY_POLARITY|		\ 	 PN_NWAY_TP)
end_define

begin_define
define|#
directive|define
name|PN_NWAY_MODE_10FD
define|\
value|(PN_NWAY_CAP10HALF|PN_NWAY_CAP10FULL|		\ 	 PN_NWAY_CAP100FULL|PN_NWAY_CAP100HALF|PN_NWAY_CAP100T4|	\ 	 PN_NWAY_AUILOWCUR|PN_NWAY_TPEXTEND|PN_NWAY_POLARITY|		\ 	 PN_NWAY_TP|PN_NWAY_DUPLEX)
end_define

begin_define
define|#
directive|define
name|PN_NWAY_MODE_100HD
define|\
value|(PN_NWAY_CAP10HALF|PN_NWAY_CAP10FULL|		\ 	 PN_NWAY_CAP100FULL|PN_NWAY_CAP100HALF|PN_NWAY_CAP100T4|	\ 	 PN_NWAY_AUILOWCUR|PN_NWAY_TPEXTEND|PN_NWAY_POLARITY|		\ 	 PN_NWAY_TP|PN_NWAY_SPEEDSEL)
end_define

begin_define
define|#
directive|define
name|PN_NWAY_MODE_100FD
define|\
value|(PN_NWAY_CAP10HALF|PN_NWAY_CAP10FULL|		\ 	 PN_NWAY_CAP100FULL|PN_NWAY_CAP100HALF|PN_NWAY_CAP100T4|	\ 	 PN_NWAY_AUILOWCUR|PN_NWAY_TPEXTEND|PN_NWAY_POLARITY|		\ 	 PN_NWAY_TP|PN_NWAY_SPEEDSEL|PN_NWAY_DUPLEX)
end_define

begin_define
define|#
directive|define
name|PN_NWAY_MODE_100T4
value|PN_NWAY_MODE_100HD
end_define

begin_define
define|#
directive|define
name|PN_NWAY_LPAR
define|\
value|(PN_NWAY_LPAR10HALF|PN_NWAY_LPAR10FULL|PN_NWAY_LPAR100HALF|	\ 	 PN_NWAY_LPAR100FULL|PN_NWAY_LPAR100T4)
end_define

begin_comment
comment|/*  * Size of a setup frame.  */
end_comment

begin_define
define|#
directive|define
name|PN_SFRAME_LEN
value|192
end_define

begin_comment
comment|/*  * PNIC TX/RX list structure.  */
end_comment

begin_struct
struct|struct
name|pn_desc
block|{
name|u_int32_t
name|pn_status
decl_stmt|;
name|u_int32_t
name|pn_ctl
decl_stmt|;
name|u_int32_t
name|pn_ptr1
decl_stmt|;
name|u_int32_t
name|pn_ptr2
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|pn_data
value|pn_ptr1
end_define

begin_define
define|#
directive|define
name|pn_next
value|pn_ptr2
end_define

begin_define
define|#
directive|define
name|RX_RXSTAT_FIFOOFLOW
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PN_RXSTAT_CRCERR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PN_RXSTAT_DRIBBLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PN_RXSTAT_WATCHDOG
value|0x00000010
end_define

begin_define
define|#
directive|define
name|PN_RXSTAT_FRAMETYPE
value|0x00000020
end_define

begin_comment
comment|/* 0 == IEEE 802.3 */
end_comment

begin_define
define|#
directive|define
name|PN_RXSTAT_COLLSEEN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PN_RXSTAT_GIANT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|PN_RXSTAT_LASTFRAG
value|0x00000100
end_define

begin_define
define|#
directive|define
name|PN_RXSTAT_FIRSTFRAG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|PN_RXSTAT_MULTICAST
value|0x00000400
end_define

begin_define
define|#
directive|define
name|PN_RXSTAT_RUNT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|PN_RXSTAT_RXTYPE
value|0x00003000
end_define

begin_define
define|#
directive|define
name|PN_RXSTAT_RXERR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|PN_RXSTAT_RXLEN
value|0x7FFF0000
end_define

begin_define
define|#
directive|define
name|PN_RXSTAT_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PN_RXBYTES
parameter_list|(
name|x
parameter_list|)
value|((x& PN_RXSTAT_RXLEN)>> 16)
end_define

begin_define
define|#
directive|define
name|PN_RXSTAT
value|(PN_RXSTAT_FIRSTFRAG|PN_RXSTAT_LASTFRAG|PN_RXSTAT_OWN)
end_define

begin_define
define|#
directive|define
name|PN_RXCTL_BUFLEN1
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|PN_RXCTL_BUFLEN2
value|0x00FFF000
end_define

begin_define
define|#
directive|define
name|PN_RXCTL_RLINK
value|0x01000000
end_define

begin_define
define|#
directive|define
name|PN_RXCTL_RLAST
value|0x02000000
end_define

begin_define
define|#
directive|define
name|PN_TXSTAT_DEFER
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PN_TXSTAT_UNDERRUN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PN_TXSTAT_LINKFAIL
value|0x00000003
end_define

begin_define
define|#
directive|define
name|PN_TXSTAT_COLLCNT
value|0x00000078
end_define

begin_define
define|#
directive|define
name|PN_TXSTAT_SQE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|PN_TXSTAT_EXCESSCOLL
value|0x00000100
end_define

begin_define
define|#
directive|define
name|PN_TXSTAT_LATECOLL
value|0x00000200
end_define

begin_define
define|#
directive|define
name|PN_TXSTAT_NOCARRIER
value|0x00000400
end_define

begin_define
define|#
directive|define
name|PN_TXSTAT_CARRLOST
value|0x00000800
end_define

begin_define
define|#
directive|define
name|PN_TXSTAT_JABTIMEO
value|0x00004000
end_define

begin_define
define|#
directive|define
name|PN_TXSTAT_ERRSUM
value|0x00008000
end_define

begin_define
define|#
directive|define
name|PN_TXSTAT_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PN_TXCTL_BUFLEN1
value|0x000007FF
end_define

begin_define
define|#
directive|define
name|PN_TXCTL_BUFLEN2
value|0x003FF800
end_define

begin_define
define|#
directive|define
name|PN_TXCTL_FILTTYPE0
value|0x00400000
end_define

begin_define
define|#
directive|define
name|PN_TXCTL_PAD
value|0x00800000
end_define

begin_define
define|#
directive|define
name|PN_TXCTL_TLINK
value|0x01000000
end_define

begin_define
define|#
directive|define
name|PN_TXCTL_TLAST
value|0x02000000
end_define

begin_define
define|#
directive|define
name|PN_TXCTL_NOCRC
value|0x04000000
end_define

begin_define
define|#
directive|define
name|PN_TXCTL_SETUP
value|0x08000000
end_define

begin_define
define|#
directive|define
name|PN_TXCTL_FILTTYPE1
value|0x10000000
end_define

begin_define
define|#
directive|define
name|PN_TXCTL_FIRSTFRAG
value|0x20000000
end_define

begin_define
define|#
directive|define
name|PN_TXCTL_LASTFRAG
value|0x40000000
end_define

begin_define
define|#
directive|define
name|PN_TXCTL_FINT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PN_FILTER_PERFECT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PN_FILTER_HASHPERF
value|0x00400000
end_define

begin_define
define|#
directive|define
name|PN_FILTER_INVERSE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|PN_FILTER_HASHONLY
value|0x10400000
end_define

begin_define
define|#
directive|define
name|PN_MAXFRAGS
value|16
end_define

begin_define
define|#
directive|define
name|PN_RX_LIST_CNT
value|64
end_define

begin_define
define|#
directive|define
name|PN_TX_LIST_CNT
value|128
end_define

begin_define
define|#
directive|define
name|PN_MIN_FRAMELEN
value|60
end_define

begin_define
define|#
directive|define
name|PN_FRAMELEN
value|1536
end_define

begin_define
define|#
directive|define
name|PN_RXLEN
value|1536
end_define

begin_comment
comment|/*  * A tx 'super descriptor' is actually 16 regular descriptors  * back to back.  */
end_comment

begin_struct
struct|struct
name|pn_txdesc
block|{
name|struct
name|pn_desc
name|pn_frag
index|[
name|PN_MAXFRAGS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PN_TXNEXT
parameter_list|(
name|x
parameter_list|)
value|x->pn_ptr->pn_frag[x->pn_lastdesc].pn_next
end_define

begin_define
define|#
directive|define
name|PN_TXSTATUS
parameter_list|(
name|x
parameter_list|)
value|x->pn_ptr->pn_frag[x->pn_lastdesc].pn_status
end_define

begin_define
define|#
directive|define
name|PN_TXCTL
parameter_list|(
name|x
parameter_list|)
value|x->pn_ptr->pn_frag[x->pn_lastdesc].pn_ctl
end_define

begin_define
define|#
directive|define
name|PN_TXDATA
parameter_list|(
name|x
parameter_list|)
value|x->pn_ptr->pn_frag[x->pn_lastdesc].pn_data
end_define

begin_define
define|#
directive|define
name|PN_TXOWN
parameter_list|(
name|x
parameter_list|)
value|x->pn_ptr->pn_frag[0].pn_status
end_define

begin_struct
struct|struct
name|pn_list_data
block|{
name|struct
name|pn_desc
name|pn_rx_list
index|[
name|PN_RX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|pn_txdesc
name|pn_tx_list
index|[
name|PN_TX_LIST_CNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pn_chain
block|{
name|struct
name|pn_txdesc
modifier|*
name|pn_ptr
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|pn_mbuf
decl_stmt|;
name|struct
name|pn_chain
modifier|*
name|pn_nextdesc
decl_stmt|;
name|u_int8_t
name|pn_lastdesc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pn_chain_onefrag
block|{
name|struct
name|pn_desc
modifier|*
name|pn_ptr
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|pn_mbuf
decl_stmt|;
name|struct
name|pn_chain_onefrag
modifier|*
name|pn_nextdesc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pn_chain_data
block|{
name|struct
name|pn_desc
name|pn_sframe
decl_stmt|;
name|u_int32_t
name|pn_sbuf
index|[
name|PN_SFRAME_LEN
operator|/
sizeof|sizeof
argument_list|(
name|u_int32_t
argument_list|)
index|]
decl_stmt|;
name|struct
name|pn_chain_onefrag
name|pn_rx_chain
index|[
name|PN_RX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|pn_chain
name|pn_tx_chain
index|[
name|PN_TX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|pn_chain_onefrag
modifier|*
name|pn_rx_head
decl_stmt|;
name|struct
name|pn_chain
modifier|*
name|pn_tx_head
decl_stmt|;
name|struct
name|pn_chain
modifier|*
name|pn_tx_tail
decl_stmt|;
name|struct
name|pn_chain
modifier|*
name|pn_tx_free
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pn_type
block|{
name|u_int16_t
name|pn_vid
decl_stmt|;
name|u_int16_t
name|pn_did
decl_stmt|;
name|char
modifier|*
name|pn_name
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pn_mii_frame
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
name|PN_MII_STARTDELIM
value|0x01
end_define

begin_define
define|#
directive|define
name|PN_MII_READOP
value|0x02
end_define

begin_define
define|#
directive|define
name|PN_MII_WRITEOP
value|0x01
end_define

begin_define
define|#
directive|define
name|PN_MII_TURNAROUND
value|0x02
end_define

begin_define
define|#
directive|define
name|PN_FLAG_FORCEDELAY
value|1
end_define

begin_define
define|#
directive|define
name|PN_FLAG_SCHEDDELAY
value|2
end_define

begin_define
define|#
directive|define
name|PN_FLAG_DELAYTIMEO
value|3
end_define

begin_struct
struct|struct
name|pn_softc
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
name|pn_bhandle
decl_stmt|;
comment|/* bus space handle */
name|bus_space_tag_t
name|pn_btag
decl_stmt|;
comment|/* bus space tag */
name|struct
name|pn_type
modifier|*
name|pn_info
decl_stmt|;
comment|/* PNIC adapter info */
name|struct
name|pn_type
modifier|*
name|pn_pinfo
decl_stmt|;
comment|/* phy info */
name|u_int8_t
name|pn_unit
decl_stmt|;
comment|/* interface number */
name|u_int8_t
name|pn_type
decl_stmt|;
name|u_int8_t
name|pn_phy_addr
decl_stmt|;
comment|/* PHY address */
name|u_int8_t
name|pn_tx_pend
decl_stmt|;
comment|/* TX pending */
name|u_int8_t
name|pn_want_auto
decl_stmt|;
name|u_int8_t
name|pn_autoneg
decl_stmt|;
name|caddr_t
name|pn_ldata_ptr
decl_stmt|;
ifdef|#
directive|ifdef
name|PN_RX_BUG_WAR
define|#
directive|define
name|PN_168_REV
value|16
define|#
directive|define
name|PN_169_REV
value|32
define|#
directive|define
name|PN_169B_REV
value|33
name|u_int8_t
name|pn_rx_war
decl_stmt|;
name|u_int8_t
name|pn_cachesize
decl_stmt|;
name|struct
name|pn_chain_onefrag
modifier|*
name|pn_rx_bug_save
decl_stmt|;
name|unsigned
name|char
modifier|*
name|pn_rx_buf
decl_stmt|;
endif|#
directive|endif
name|struct
name|pn_list_data
modifier|*
name|pn_ldata
decl_stmt|;
name|struct
name|pn_chain_data
name|pn_cdata
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
value|bus_space_write_4(sc->pn_btag, sc->pn_bhandle, reg, val)
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
value|bus_space_write_2(sc->pn_btag, sc->pn_bhandle, reg, val)
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
value|bus_space_write_1(sc->pn_btag, sc->pn_bhandle, reg, val)
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
value|bus_space_read_4(sc->pn_btag, sc->pn_bhandle, reg)
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
value|bus_space_read_2(sc->pn_btag, sc->pn_bhandle, reg)
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
value|bus_space_read_1(sc->pn_btag, sc->pn_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|PN_TIMEOUT
value|1000
end_define

begin_comment
comment|/*  * General constants that are fun to know.  *  * Lite-On PNIC PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|PN_VENDORID
value|0x11AD
end_define

begin_comment
comment|/*  * Lite-On PNIC PCI device ID.  */
end_comment

begin_define
define|#
directive|define
name|PN_DEVICEID_PNIC
value|0x0002
end_define

begin_comment
comment|/*  * The 82c168 chip has the same PCI vendor/device ID as the  * 82c169, but a different revision. Assume that any revision  * between 0x10 an 0x1F is an 82c168.  */
end_comment

begin_define
define|#
directive|define
name|PN_REVMASK
value|0xF0
end_define

begin_define
define|#
directive|define
name|PN_REVID_82C168
value|0x10
end_define

begin_define
define|#
directive|define
name|PN_REVID_82C169
value|0x20
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
name|PN_PCI_VENDOR_ID
value|0x00
end_define

begin_define
define|#
directive|define
name|PN_PCI_DEVICE_ID
value|0x02
end_define

begin_define
define|#
directive|define
name|PN_PCI_COMMAND
value|0x04
end_define

begin_define
define|#
directive|define
name|PN_PCI_STATUS
value|0x06
end_define

begin_define
define|#
directive|define
name|PN_PCI_REVISION
value|0x08
end_define

begin_define
define|#
directive|define
name|PN_PCI_CLASSCODE
value|0x09
end_define

begin_define
define|#
directive|define
name|PN_PCI_CACHELEN
value|0x0C
end_define

begin_define
define|#
directive|define
name|PN_PCI_LATENCY_TIMER
value|0x0D
end_define

begin_define
define|#
directive|define
name|PN_PCI_HEADER_TYPE
value|0x0E
end_define

begin_define
define|#
directive|define
name|PN_PCI_LOIO
value|0x10
end_define

begin_define
define|#
directive|define
name|PN_PCI_LOMEM
value|0x14
end_define

begin_define
define|#
directive|define
name|PN_PCI_BIOSROM
value|0x30
end_define

begin_define
define|#
directive|define
name|PN_PCI_INTLINE
value|0x3C
end_define

begin_define
define|#
directive|define
name|PN_PCI_INTPIN
value|0x3D
end_define

begin_define
define|#
directive|define
name|PN_PCI_MINGNT
value|0x3E
end_define

begin_define
define|#
directive|define
name|PN_PCI_MINLAT
value|0x0F
end_define

begin_define
define|#
directive|define
name|PN_PCI_RESETOPT
value|0x48
end_define

begin_define
define|#
directive|define
name|PN_PCI_EEPROM_DATA
value|0x4C
end_define

begin_comment
comment|/* power management registers */
end_comment

begin_define
define|#
directive|define
name|PN_PCI_CAPID
value|0xDC
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|PN_PCI_NEXTPTR
value|0xDD
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|PN_PCI_PWRMGMTCAP
value|0xDE
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|PN_PCI_PWRMGMTCTRL
value|0xE0
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|PN_PSTATE_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|PN_PSTATE_D0
value|0x0000
end_define

begin_define
define|#
directive|define
name|PN_PSTATE_D1
value|0x0002
end_define

begin_define
define|#
directive|define
name|PN_PSTATE_D2
value|0x0002
end_define

begin_define
define|#
directive|define
name|PN_PSTATE_D3
value|0x0003
end_define

begin_define
define|#
directive|define
name|PN_PME_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|PN_PME_STATUS
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
name|PN_PHYADDR_MIN
value|0x00
end_define

begin_define
define|#
directive|define
name|PN_PHYADDR_MAX
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

