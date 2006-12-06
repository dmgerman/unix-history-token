begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998, 1999  *	Bill Paul<wpaul@ee.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * 21143 and clone common register definitions.  */
end_comment

begin_define
define|#
directive|define
name|DC_BUSCTL
value|0x00
end_define

begin_comment
comment|/* bus control */
end_comment

begin_define
define|#
directive|define
name|DC_TXSTART
value|0x08
end_define

begin_comment
comment|/* tx start demand */
end_comment

begin_define
define|#
directive|define
name|DC_RXSTART
value|0x10
end_define

begin_comment
comment|/* rx start demand */
end_comment

begin_define
define|#
directive|define
name|DC_RXADDR
value|0x18
end_define

begin_comment
comment|/* rx descriptor list start addr */
end_comment

begin_define
define|#
directive|define
name|DC_TXADDR
value|0x20
end_define

begin_comment
comment|/* tx descriptor list start addr */
end_comment

begin_define
define|#
directive|define
name|DC_ISR
value|0x28
end_define

begin_comment
comment|/* interrupt status register */
end_comment

begin_define
define|#
directive|define
name|DC_NETCFG
value|0x30
end_define

begin_comment
comment|/* network config register */
end_comment

begin_define
define|#
directive|define
name|DC_IMR
value|0x38
end_define

begin_comment
comment|/* interrupt mask */
end_comment

begin_define
define|#
directive|define
name|DC_FRAMESDISCARDED
value|0x40
end_define

begin_comment
comment|/* # of discarded frames */
end_comment

begin_define
define|#
directive|define
name|DC_SIO
value|0x48
end_define

begin_comment
comment|/* MII and ROM/EEPROM access */
end_comment

begin_define
define|#
directive|define
name|DC_ROM
value|0x50
end_define

begin_comment
comment|/* ROM programming address */
end_comment

begin_define
define|#
directive|define
name|DC_TIMER
value|0x58
end_define

begin_comment
comment|/* general timer */
end_comment

begin_define
define|#
directive|define
name|DC_10BTSTAT
value|0x60
end_define

begin_comment
comment|/* SIA status */
end_comment

begin_define
define|#
directive|define
name|DC_SIARESET
value|0x68
end_define

begin_comment
comment|/* SIA connectivity */
end_comment

begin_define
define|#
directive|define
name|DC_10BTCTRL
value|0x70
end_define

begin_comment
comment|/* SIA transmit and receive */
end_comment

begin_define
define|#
directive|define
name|DC_WATCHDOG
value|0x78
end_define

begin_comment
comment|/* SIA and general purpose port */
end_comment

begin_define
define|#
directive|define
name|DC_SIAGP
value|0x78
end_define

begin_comment
comment|/* SIA and general purpose port (X3201) */
end_comment

begin_comment
comment|/*  * There are two general 'types' of MX chips that we need to be  * concerned with. One is the original 98713, which has its internal  * NWAY support controlled via the MDIO bits in the serial I/O  * register. The other is everything else (from the 98713A on up),  * which has its internal NWAY controlled via CSR13, CSR14 and CSR15,  * just like the 21143. This type setting also governs which of the  * 'magic' numbers we write to CSR16. The PNIC II falls into the  * 98713A/98715/98715A/98725 category.  */
end_comment

begin_define
define|#
directive|define
name|DC_TYPE_98713
value|0x1
end_define

begin_define
define|#
directive|define
name|DC_TYPE_98713A
value|0x2
end_define

begin_define
define|#
directive|define
name|DC_TYPE_987x5
value|0x3
end_define

begin_comment
comment|/* Other type of supported chips. */
end_comment

begin_define
define|#
directive|define
name|DC_TYPE_21143
value|0x4
end_define

begin_comment
comment|/* Intel 21143 */
end_comment

begin_define
define|#
directive|define
name|DC_TYPE_ASIX
value|0x5
end_define

begin_comment
comment|/* ASIX AX88140A/AX88141 */
end_comment

begin_define
define|#
directive|define
name|DC_TYPE_AL981
value|0x6
end_define

begin_comment
comment|/* ADMtek AL981 Comet */
end_comment

begin_define
define|#
directive|define
name|DC_TYPE_AN985
value|0x7
end_define

begin_comment
comment|/* ADMtek AN985 Centaur */
end_comment

begin_define
define|#
directive|define
name|DC_TYPE_DM9102
value|0x8
end_define

begin_comment
comment|/* Davicom DM9102 */
end_comment

begin_define
define|#
directive|define
name|DC_TYPE_PNICII
value|0x9
end_define

begin_comment
comment|/* 82c115 PNIC II */
end_comment

begin_define
define|#
directive|define
name|DC_TYPE_PNIC
value|0xA
end_define

begin_comment
comment|/* 82c168/82c169 PNIC I */
end_comment

begin_define
define|#
directive|define
name|DC_TYPE_XIRCOM
value|0xB
end_define

begin_comment
comment|/* Xircom X3201 */
end_comment

begin_define
define|#
directive|define
name|DC_TYPE_CONEXANT
value|0xC
end_define

begin_comment
comment|/* Conexant LANfinity RS7112 */
end_comment

begin_define
define|#
directive|define
name|DC_IS_MACRONIX
parameter_list|(
name|x
parameter_list|)
define|\
value|(x->dc_type == DC_TYPE_98713 ||		\ 	 x->dc_type == DC_TYPE_98713A ||	\ 	 x->dc_type == DC_TYPE_987x5)
end_define

begin_define
define|#
directive|define
name|DC_IS_ADMTEK
parameter_list|(
name|x
parameter_list|)
define|\
value|(x->dc_type == DC_TYPE_AL981 ||		\ 	 x->dc_type == DC_TYPE_AN985)
end_define

begin_define
define|#
directive|define
name|DC_IS_INTEL
parameter_list|(
name|x
parameter_list|)
value|(x->dc_type == DC_TYPE_21143)
end_define

begin_define
define|#
directive|define
name|DC_IS_ASIX
parameter_list|(
name|x
parameter_list|)
value|(x->dc_type == DC_TYPE_ASIX)
end_define

begin_define
define|#
directive|define
name|DC_IS_COMET
parameter_list|(
name|x
parameter_list|)
value|(x->dc_type == DC_TYPE_AL981)
end_define

begin_define
define|#
directive|define
name|DC_IS_CENTAUR
parameter_list|(
name|x
parameter_list|)
value|(x->dc_type == DC_TYPE_AN985)
end_define

begin_define
define|#
directive|define
name|DC_IS_DAVICOM
parameter_list|(
name|x
parameter_list|)
value|(x->dc_type == DC_TYPE_DM9102)
end_define

begin_define
define|#
directive|define
name|DC_IS_PNICII
parameter_list|(
name|x
parameter_list|)
value|(x->dc_type == DC_TYPE_PNICII)
end_define

begin_define
define|#
directive|define
name|DC_IS_PNIC
parameter_list|(
name|x
parameter_list|)
value|(x->dc_type == DC_TYPE_PNIC)
end_define

begin_define
define|#
directive|define
name|DC_IS_XIRCOM
parameter_list|(
name|x
parameter_list|)
value|(x->dc_type == DC_TYPE_XIRCOM)
end_define

begin_define
define|#
directive|define
name|DC_IS_CONEXANT
parameter_list|(
name|x
parameter_list|)
value|(x->dc_type == DC_TYPE_CONEXANT)
end_define

begin_comment
comment|/* MII/symbol mode port types */
end_comment

begin_define
define|#
directive|define
name|DC_PMODE_MII
value|0x1
end_define

begin_define
define|#
directive|define
name|DC_PMODE_SYM
value|0x2
end_define

begin_define
define|#
directive|define
name|DC_PMODE_SIA
value|0x3
end_define

begin_comment
comment|/*  * Bus control bits.  */
end_comment

begin_define
define|#
directive|define
name|DC_BUSCTL_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DC_BUSCTL_ARBITRATION
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DC_BUSCTL_SKIPLEN
value|0x0000007C
end_define

begin_define
define|#
directive|define
name|DC_BUSCTL_BUF_BIGENDIAN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DC_BUSCTL_BURSTLEN
value|0x00003F00
end_define

begin_define
define|#
directive|define
name|DC_BUSCTL_CACHEALIGN
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|DC_BUSCTL_TXPOLL
value|0x000E0000
end_define

begin_define
define|#
directive|define
name|DC_BUSCTL_DBO
value|0x00100000
end_define

begin_define
define|#
directive|define
name|DC_BUSCTL_MRME
value|0x00200000
end_define

begin_define
define|#
directive|define
name|DC_BUSCTL_MRLE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|DC_BUSCTL_MWIE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|DC_BUSCTL_ONNOW_ENB
value|0x04000000
end_define

begin_define
define|#
directive|define
name|DC_SKIPLEN_1LONG
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DC_SKIPLEN_2LONG
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DC_SKIPLEN_3LONG
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DC_SKIPLEN_4LONG
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DC_SKIPLEN_5LONG
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DC_CACHEALIGN_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DC_CACHEALIGN_8LONG
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DC_CACHEALIGN_16LONG
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DC_CACHEALIGN_32LONG
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|DC_BURSTLEN_USECA
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DC_BURSTLEN_1LONG
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DC_BURSTLEN_2LONG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DC_BURSTLEN_4LONG
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DC_BURSTLEN_8LONG
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DC_BURSTLEN_16LONG
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DC_BURSTLEN_32LONG
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DC_TXPOLL_OFF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DC_TXPOLL_1
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DC_TXPOLL_2
value|0x00040000
end_define

begin_define
define|#
directive|define
name|DC_TXPOLL_3
value|0x00060000
end_define

begin_define
define|#
directive|define
name|DC_TXPOLL_4
value|0x00080000
end_define

begin_define
define|#
directive|define
name|DC_TXPOLL_5
value|0x000A0000
end_define

begin_define
define|#
directive|define
name|DC_TXPOLL_6
value|0x000C0000
end_define

begin_define
define|#
directive|define
name|DC_TXPOLL_7
value|0x000E0000
end_define

begin_comment
comment|/*  * Interrupt status bits.  */
end_comment

begin_define
define|#
directive|define
name|DC_ISR_TX_OK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DC_ISR_TX_IDLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DC_ISR_TX_NOBUF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DC_ISR_TX_JABBERTIMEO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DC_ISR_LINKGOOD
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DC_ISR_TX_UNDERRUN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DC_ISR_RX_OK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DC_ISR_RX_NOBUF
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DC_ISR_RX_READ
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DC_ISR_RX_WATDOGTIMEO
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DC_ISR_TX_EARLY
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DC_ISR_TIMER_EXPIRED
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DC_ISR_LINKFAIL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DC_ISR_BUS_ERR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DC_ISR_RX_EARLY
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DC_ISR_ABNORMAL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DC_ISR_NORMAL
value|0x00010000
end_define

begin_define
define|#
directive|define
name|DC_ISR_RX_STATE
value|0x000E0000
end_define

begin_define
define|#
directive|define
name|DC_ISR_TX_STATE
value|0x00700000
end_define

begin_define
define|#
directive|define
name|DC_ISR_BUSERRTYPE
value|0x03800000
end_define

begin_define
define|#
directive|define
name|DC_ISR_100MBPSLINK
value|0x08000000
end_define

begin_define
define|#
directive|define
name|DC_ISR_MAGICKPACK
value|0x10000000
end_define

begin_define
define|#
directive|define
name|DC_RXSTATE_STOPPED
value|0x00000000
end_define

begin_comment
comment|/* 000 - Stopped */
end_comment

begin_define
define|#
directive|define
name|DC_RXSTATE_FETCH
value|0x00020000
end_define

begin_comment
comment|/* 001 - Fetching descriptor */
end_comment

begin_define
define|#
directive|define
name|DC_RXSTATE_ENDCHECK
value|0x00040000
end_define

begin_comment
comment|/* 010 - check for rx end */
end_comment

begin_define
define|#
directive|define
name|DC_RXSTATE_WAIT
value|0x00060000
end_define

begin_comment
comment|/* 011 - waiting for packet */
end_comment

begin_define
define|#
directive|define
name|DC_RXSTATE_SUSPEND
value|0x00080000
end_define

begin_comment
comment|/* 100 - suspend rx */
end_comment

begin_define
define|#
directive|define
name|DC_RXSTATE_CLOSE
value|0x000A0000
end_define

begin_comment
comment|/* 101 - close tx desc */
end_comment

begin_define
define|#
directive|define
name|DC_RXSTATE_FLUSH
value|0x000C0000
end_define

begin_comment
comment|/* 110 - flush from FIFO */
end_comment

begin_define
define|#
directive|define
name|DC_RXSTATE_DEQUEUE
value|0x000E0000
end_define

begin_comment
comment|/* 111 - dequeue from FIFO */
end_comment

begin_define
define|#
directive|define
name|DC_TXSTATE_RESET
value|0x00000000
end_define

begin_comment
comment|/* 000 - reset */
end_comment

begin_define
define|#
directive|define
name|DC_TXSTATE_FETCH
value|0x00100000
end_define

begin_comment
comment|/* 001 - fetching descriptor */
end_comment

begin_define
define|#
directive|define
name|DC_TXSTATE_WAITEND
value|0x00200000
end_define

begin_comment
comment|/* 010 - wait for tx end */
end_comment

begin_define
define|#
directive|define
name|DC_TXSTATE_READING
value|0x00300000
end_define

begin_comment
comment|/* 011 - read and enqueue */
end_comment

begin_define
define|#
directive|define
name|DC_TXSTATE_RSVD
value|0x00400000
end_define

begin_comment
comment|/* 100 - reserved */
end_comment

begin_define
define|#
directive|define
name|DC_TXSTATE_SETUP
value|0x00500000
end_define

begin_comment
comment|/* 101 - setup packet */
end_comment

begin_define
define|#
directive|define
name|DC_TXSTATE_SUSPEND
value|0x00600000
end_define

begin_comment
comment|/* 110 - suspend tx */
end_comment

begin_define
define|#
directive|define
name|DC_TXSTATE_CLOSE
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
name|DC_NETCFG_RX_HASHPERF
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DC_NETCFG_RX_ON
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DC_NETCFG_RX_HASHONLY
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DC_NETCFG_RX_BADFRAMES
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DC_NETCFG_RX_INVFILT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DC_NETCFG_BACKOFFCNT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DC_NETCFG_RX_PROMISC
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DC_NETCFG_RX_ALLMULTI
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DC_NETCFG_FULLDUPLEX
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DC_NETCFG_LOOPBACK
value|0x00000C00
end_define

begin_define
define|#
directive|define
name|DC_NETCFG_FORCECOLL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DC_NETCFG_TX_ON
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DC_NETCFG_TX_THRESH
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|DC_NETCFG_TX_BACKOFF
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DC_NETCFG_PORTSEL
value|0x00040000
end_define

begin_comment
comment|/* 0 == 10, 1 == 100 */
end_comment

begin_define
define|#
directive|define
name|DC_NETCFG_HEARTBEAT
value|0x00080000
end_define

begin_define
define|#
directive|define
name|DC_NETCFG_STORENFWD
value|0x00200000
end_define

begin_define
define|#
directive|define
name|DC_NETCFG_SPEEDSEL
value|0x00400000
end_define

begin_comment
comment|/* 1 == 10, 0 == 100 */
end_comment

begin_define
define|#
directive|define
name|DC_NETCFG_PCS
value|0x00800000
end_define

begin_define
define|#
directive|define
name|DC_NETCFG_SCRAMBLER
value|0x01000000
end_define

begin_define
define|#
directive|define
name|DC_NETCFG_NO_RXCRC
value|0x02000000
end_define

begin_define
define|#
directive|define
name|DC_NETCFG_RX_ALL
value|0x40000000
end_define

begin_define
define|#
directive|define
name|DC_NETCFG_CAPEFFECT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|DC_OPMODE_NORM
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DC_OPMODE_INTLOOP
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DC_OPMODE_EXTLOOP
value|0x00000800
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|DC_TXTHRESH_72BYTES
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DC_TXTHRESH_96BYTES
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DC_TXTHRESH_128BYTES
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DC_TXTHRESH_160BYTES
value|0x0000C000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DC_TXTHRESH_MIN
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DC_TXTHRESH_INC
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DC_TXTHRESH_MAX
value|0x0000C000
end_define

begin_comment
comment|/*  * Interrupt mask bits.  */
end_comment

begin_define
define|#
directive|define
name|DC_IMR_TX_OK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DC_IMR_TX_IDLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DC_IMR_TX_NOBUF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DC_IMR_TX_JABBERTIMEO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DC_IMR_LINKGOOD
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DC_IMR_TX_UNDERRUN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DC_IMR_RX_OK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DC_IMR_RX_NOBUF
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DC_IMR_RX_READ
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DC_IMR_RX_WATDOGTIMEO
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DC_IMR_TX_EARLY
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DC_IMR_TIMER_EXPIRED
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DC_IMR_LINKFAIL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DC_IMR_BUS_ERR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DC_IMR_RX_EARLY
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DC_IMR_ABNORMAL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DC_IMR_NORMAL
value|0x00010000
end_define

begin_define
define|#
directive|define
name|DC_IMR_100MBPSLINK
value|0x08000000
end_define

begin_define
define|#
directive|define
name|DC_IMR_MAGICKPACK
value|0x10000000
end_define

begin_define
define|#
directive|define
name|DC_INTRS
define|\
value|(DC_IMR_RX_OK|DC_IMR_TX_OK|DC_IMR_RX_NOBUF|DC_IMR_RX_WATDOGTIMEO|\ 	DC_IMR_TX_NOBUF|DC_IMR_TX_UNDERRUN|DC_IMR_BUS_ERR|		\ 	DC_IMR_ABNORMAL|DC_IMR_NORMAL
comment|/*|DC_IMR_TX_EARLY*/
value|)
end_define

begin_comment
comment|/*  * Serial I/O (EEPROM/ROM) bits.  */
end_comment

begin_define
define|#
directive|define
name|DC_SIO_EE_CS
value|0x00000001
end_define

begin_comment
comment|/* EEPROM chip select */
end_comment

begin_define
define|#
directive|define
name|DC_SIO_EE_CLK
value|0x00000002
end_define

begin_comment
comment|/* EEPROM clock */
end_comment

begin_define
define|#
directive|define
name|DC_SIO_EE_DATAIN
value|0x00000004
end_define

begin_comment
comment|/* EEPROM data output */
end_comment

begin_define
define|#
directive|define
name|DC_SIO_EE_DATAOUT
value|0x00000008
end_define

begin_comment
comment|/* EEPROM data input */
end_comment

begin_define
define|#
directive|define
name|DC_SIO_ROMDATA4
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DC_SIO_ROMDATA5
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DC_SIO_ROMDATA6
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DC_SIO_ROMDATA7
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DC_SIO_EESEL
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DC_SIO_ROMSEL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DC_SIO_ROMCTL_WRITE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DC_SIO_ROMCTL_READ
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DC_SIO_MII_CLK
value|0x00010000
end_define

begin_comment
comment|/* MDIO clock */
end_comment

begin_define
define|#
directive|define
name|DC_SIO_MII_DATAOUT
value|0x00020000
end_define

begin_comment
comment|/* MDIO data out */
end_comment

begin_define
define|#
directive|define
name|DC_SIO_MII_DIR
value|0x00040000
end_define

begin_comment
comment|/* MDIO dir */
end_comment

begin_define
define|#
directive|define
name|DC_SIO_MII_DATAIN
value|0x00080000
end_define

begin_comment
comment|/* MDIO data in */
end_comment

begin_define
define|#
directive|define
name|DC_EECMD_WRITE
value|0x140
end_define

begin_define
define|#
directive|define
name|DC_EECMD_READ
value|0x180
end_define

begin_define
define|#
directive|define
name|DC_EECMD_ERASE
value|0x1c0
end_define

begin_define
define|#
directive|define
name|DC_EE_NODEADDR_OFFSET
value|0x70
end_define

begin_define
define|#
directive|define
name|DC_EE_NODEADDR
value|10
end_define

begin_comment
comment|/*  * General purpose timer register  */
end_comment

begin_define
define|#
directive|define
name|DC_TIMER_VALUE
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|DC_TIMER_CONTINUOUS
value|0x00010000
end_define

begin_comment
comment|/*  * 10baseT status register  */
end_comment

begin_define
define|#
directive|define
name|DC_TSTAT_MIIACT
value|0x00000001
end_define

begin_comment
comment|/* MII port activity */
end_comment

begin_define
define|#
directive|define
name|DC_TSTAT_LS100
value|0x00000002
end_define

begin_comment
comment|/* link status of 100baseTX */
end_comment

begin_define
define|#
directive|define
name|DC_TSTAT_LS10
value|0x00000004
end_define

begin_comment
comment|/* link status of 10baseT */
end_comment

begin_define
define|#
directive|define
name|DC_TSTAT_AUTOPOLARITY
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DC_TSTAT_AUIACT
value|0x00000100
end_define

begin_comment
comment|/* AUI activity */
end_comment

begin_define
define|#
directive|define
name|DC_TSTAT_10BTACT
value|0x00000200
end_define

begin_comment
comment|/* 10baseT activity */
end_comment

begin_define
define|#
directive|define
name|DC_TSTAT_NSN
value|0x00000400
end_define

begin_comment
comment|/* non-stable FLPs detected */
end_comment

begin_define
define|#
directive|define
name|DC_TSTAT_REMFAULT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DC_TSTAT_ANEGSTAT
value|0x00007000
end_define

begin_define
define|#
directive|define
name|DC_TSTAT_LP_CAN_NWAY
value|0x00008000
end_define

begin_comment
comment|/* link partner supports NWAY */
end_comment

begin_define
define|#
directive|define
name|DC_TSTAT_LPCODEWORD
value|0xFFFF0000
end_define

begin_comment
comment|/* link partner's code word */
end_comment

begin_define
define|#
directive|define
name|DC_ASTAT_DISABLE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DC_ASTAT_TXDISABLE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DC_ASTAT_ABDETECT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DC_ASTAT_ACKDETECT
value|0x00003000
end_define

begin_define
define|#
directive|define
name|DC_ASTAT_CMPACKDETECT
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DC_ASTAT_AUTONEGCMP
value|0x00005000
end_define

begin_define
define|#
directive|define
name|DC_ASTAT_LINKCHECK
value|0x00006000
end_define

begin_comment
comment|/*  * PHY reset register  */
end_comment

begin_define
define|#
directive|define
name|DC_SIA_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DC_SIA_AUI
value|0x00000008
end_define

begin_comment
comment|/* AUI or 10baseT */
end_comment

begin_comment
comment|/*  * 10baseT control register  */
end_comment

begin_define
define|#
directive|define
name|DC_TCTL_ENCODER_ENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DC_TCTL_LOOPBACK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DC_TCTL_DRIVER_ENB
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DC_TCTL_LNKPULSE_ENB
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DC_TCTL_HALFDUPLEX
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DC_TCTL_AUTONEGENBL
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DC_TCTL_RX_SQUELCH
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DC_TCTL_COLL_SQUELCH
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DC_TCTL_COLL_DETECT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DC_TCTL_SQE_ENB
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DC_TCTL_LINKTEST
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DC_TCTL_AUTOPOLARITY
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DC_TCTL_SET_POL_PLUS
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DC_TCTL_AUTOSENSE
value|0x00008000
end_define

begin_comment
comment|/* 10bt/AUI autosense */
end_comment

begin_define
define|#
directive|define
name|DC_TCTL_100BTXHALF
value|0x00010000
end_define

begin_define
define|#
directive|define
name|DC_TCTL_100BTXFULL
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DC_TCTL_100BT4
value|0x00040000
end_define

begin_comment
comment|/*  * Watchdog timer register  */
end_comment

begin_define
define|#
directive|define
name|DC_WDOG_JABBERDIS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DC_WDOG_HOSTUNJAB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DC_WDOG_JABBERCLK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DC_WDOG_RXWDOGDIS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DC_WDOG_RXWDOGCLK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DC_WDOG_MUSTBEZERO
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DC_WDOG_AUIBNC
value|0x00100000
end_define

begin_define
define|#
directive|define
name|DC_WDOG_ACTIVITY
value|0x00200000
end_define

begin_define
define|#
directive|define
name|DC_WDOG_RX_MATCH
value|0x00400000
end_define

begin_define
define|#
directive|define
name|DC_WDOG_LINK
value|0x00800000
end_define

begin_define
define|#
directive|define
name|DC_WDOG_CTLWREN
value|0x08000000
end_define

begin_comment
comment|/*  * SIA and General Purpose Port register (X3201)  */
end_comment

begin_define
define|#
directive|define
name|DC_SIAGP_RXMATCH
value|0x40000000
end_define

begin_define
define|#
directive|define
name|DC_SIAGP_INT1
value|0x20000000
end_define

begin_define
define|#
directive|define
name|DC_SIAGP_INT0
value|0x10000000
end_define

begin_define
define|#
directive|define
name|DC_SIAGP_WRITE_EN
value|0x08000000
end_define

begin_define
define|#
directive|define
name|DC_SIAGP_RXMATCH_EN
value|0x04000000
end_define

begin_define
define|#
directive|define
name|DC_SIAGP_INT1_EN
value|0x02000000
end_define

begin_define
define|#
directive|define
name|DC_SIAGP_INT0_EN
value|0x01000000
end_define

begin_define
define|#
directive|define
name|DC_SIAGP_LED3
value|0x00800000
end_define

begin_define
define|#
directive|define
name|DC_SIAGP_LED2
value|0x00400000
end_define

begin_define
define|#
directive|define
name|DC_SIAGP_LED1
value|0x00200000
end_define

begin_define
define|#
directive|define
name|DC_SIAGP_LED0
value|0x00100000
end_define

begin_define
define|#
directive|define
name|DC_SIAGP_MD_GP3_OUTPUT
value|0x00080000
end_define

begin_define
define|#
directive|define
name|DC_SIAGP_MD_GP2_OUTPUT
value|0x00040000
end_define

begin_define
define|#
directive|define
name|DC_SIAGP_MD_GP1_OUTPUT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DC_SIAGP_MD_GP0_OUTPUT
value|0x00010000
end_define

begin_comment
comment|/*  * Size of a setup frame.  */
end_comment

begin_define
define|#
directive|define
name|DC_SFRAME_LEN
value|192
end_define

begin_comment
comment|/*  * 21x4x TX/RX list structure.  */
end_comment

begin_struct
struct|struct
name|dc_desc
block|{
name|u_int32_t
name|dc_status
decl_stmt|;
name|u_int32_t
name|dc_ctl
decl_stmt|;
name|u_int32_t
name|dc_ptr1
decl_stmt|;
name|u_int32_t
name|dc_ptr2
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|dc_data
value|dc_ptr1
end_define

begin_define
define|#
directive|define
name|dc_next
value|dc_ptr2
end_define

begin_define
define|#
directive|define
name|DC_RXSTAT_FIFOOFLOW
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DC_RXSTAT_CRCERR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DC_RXSTAT_DRIBBLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DC_RXSTAT_MIIERE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DC_RXSTAT_WATCHDOG
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DC_RXSTAT_FRAMETYPE
value|0x00000020
end_define

begin_comment
comment|/* 0 == IEEE 802.3 */
end_comment

begin_define
define|#
directive|define
name|DC_RXSTAT_COLLSEEN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DC_RXSTAT_GIANT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DC_RXSTAT_LASTFRAG
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DC_RXSTAT_FIRSTFRAG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DC_RXSTAT_MULTICAST
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DC_RXSTAT_RUNT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DC_RXSTAT_RXTYPE
value|0x00003000
end_define

begin_define
define|#
directive|define
name|DC_RXSTAT_DE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DC_RXSTAT_RXERR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DC_RXSTAT_RXLEN
value|0x3FFF0000
end_define

begin_define
define|#
directive|define
name|DC_RXSTAT_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|DC_RXBYTES
parameter_list|(
name|x
parameter_list|)
value|((x& DC_RXSTAT_RXLEN)>> 16)
end_define

begin_define
define|#
directive|define
name|DC_RXSTAT
value|(DC_RXSTAT_FIRSTFRAG|DC_RXSTAT_LASTFRAG|DC_RXSTAT_OWN)
end_define

begin_define
define|#
directive|define
name|DC_RXCTL_BUFLEN1
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|DC_RXCTL_BUFLEN2
value|0x00FFF000
end_define

begin_define
define|#
directive|define
name|DC_RXCTL_RLINK
value|0x01000000
end_define

begin_define
define|#
directive|define
name|DC_RXCTL_RLAST
value|0x02000000
end_define

begin_define
define|#
directive|define
name|DC_TXSTAT_DEFER
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DC_TXSTAT_UNDERRUN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DC_TXSTAT_LINKFAIL
value|0x00000003
end_define

begin_define
define|#
directive|define
name|DC_TXSTAT_COLLCNT
value|0x00000078
end_define

begin_define
define|#
directive|define
name|DC_TXSTAT_SQE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DC_TXSTAT_EXCESSCOLL
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DC_TXSTAT_LATECOLL
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DC_TXSTAT_NOCARRIER
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DC_TXSTAT_CARRLOST
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DC_TXSTAT_JABTIMEO
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DC_TXSTAT_ERRSUM
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DC_TXSTAT_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|DC_TXCTL_BUFLEN1
value|0x000007FF
end_define

begin_define
define|#
directive|define
name|DC_TXCTL_BUFLEN2
value|0x003FF800
end_define

begin_define
define|#
directive|define
name|DC_TXCTL_FILTTYPE0
value|0x00400000
end_define

begin_define
define|#
directive|define
name|DC_TXCTL_PAD
value|0x00800000
end_define

begin_define
define|#
directive|define
name|DC_TXCTL_TLINK
value|0x01000000
end_define

begin_define
define|#
directive|define
name|DC_TXCTL_TLAST
value|0x02000000
end_define

begin_define
define|#
directive|define
name|DC_TXCTL_NOCRC
value|0x04000000
end_define

begin_define
define|#
directive|define
name|DC_TXCTL_SETUP
value|0x08000000
end_define

begin_define
define|#
directive|define
name|DC_TXCTL_FILTTYPE1
value|0x10000000
end_define

begin_define
define|#
directive|define
name|DC_TXCTL_FIRSTFRAG
value|0x20000000
end_define

begin_define
define|#
directive|define
name|DC_TXCTL_LASTFRAG
value|0x40000000
end_define

begin_define
define|#
directive|define
name|DC_TXCTL_FINT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|DC_FILTER_PERFECT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DC_FILTER_HASHPERF
value|0x00400000
end_define

begin_define
define|#
directive|define
name|DC_FILTER_INVERSE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|DC_FILTER_HASHONLY
value|0x10400000
end_define

begin_define
define|#
directive|define
name|DC_MAXFRAGS
value|16
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEVICE_POLLING
end_ifdef

begin_define
define|#
directive|define
name|DC_RX_LIST_CNT
value|192
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DC_RX_LIST_CNT
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DC_TX_LIST_CNT
value|256
end_define

begin_define
define|#
directive|define
name|DC_MIN_FRAMELEN
value|60
end_define

begin_define
define|#
directive|define
name|DC_RXLEN
value|1536
end_define

begin_define
define|#
directive|define
name|DC_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = (x + 1) % y
end_define

begin_comment
comment|/* Macros to easily get the DMA address of a descriptor. */
end_comment

begin_define
define|#
directive|define
name|DC_RXDESC
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
value|(sc->dc_laddr +				\     (uintptr_t)(sc->dc_ldata->dc_rx_list + i) - (uintptr_t)sc->dc_ldata)
end_define

begin_define
define|#
directive|define
name|DC_TXDESC
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
value|(sc->dc_laddr +				\     (uintptr_t)(sc->dc_ldata->dc_tx_list + i) - (uintptr_t)sc->dc_ldata)
end_define

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|DC_SP_MAC
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DC_SP_MAC
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|dc_list_data
block|{
name|struct
name|dc_desc
name|dc_rx_list
index|[
name|DC_RX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|dc_desc
name|dc_tx_list
index|[
name|DC_TX_LIST_CNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dc_chain_data
block|{
name|struct
name|mbuf
modifier|*
name|dc_rx_chain
index|[
name|DC_RX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|dc_tx_chain
index|[
name|DC_TX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|dc_tx_mapping
decl_stmt|;
name|bus_dmamap_t
name|dc_rx_map
index|[
name|DC_RX_LIST_CNT
index|]
decl_stmt|;
name|bus_dmamap_t
name|dc_tx_map
index|[
name|DC_TX_LIST_CNT
index|]
decl_stmt|;
name|u_int32_t
modifier|*
name|dc_sbuf
decl_stmt|;
name|u_int8_t
name|dc_pad
index|[
name|DC_MIN_FRAMELEN
index|]
decl_stmt|;
name|int
name|dc_tx_err
decl_stmt|;
name|int
name|dc_tx_first
decl_stmt|;
name|int
name|dc_tx_prod
decl_stmt|;
name|int
name|dc_tx_cons
decl_stmt|;
name|int
name|dc_tx_cnt
decl_stmt|;
name|int
name|dc_rx_err
decl_stmt|;
name|int
name|dc_rx_cur
decl_stmt|;
name|int
name|dc_rx_prod
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dc_mediainfo
block|{
name|int
name|dc_media
decl_stmt|;
name|u_int8_t
modifier|*
name|dc_gp_ptr
decl_stmt|;
name|u_int8_t
name|dc_gp_len
decl_stmt|;
name|u_int8_t
modifier|*
name|dc_reset_ptr
decl_stmt|;
name|u_int8_t
name|dc_reset_len
decl_stmt|;
name|struct
name|dc_mediainfo
modifier|*
name|dc_next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dc_type
block|{
name|u_int32_t
name|dc_devid
decl_stmt|;
name|u_int8_t
name|dc_minrev
decl_stmt|;
name|char
modifier|*
name|dc_name
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dc_mii_frame
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
name|DC_MII_STARTDELIM
value|0x01
end_define

begin_define
define|#
directive|define
name|DC_MII_READOP
value|0x02
end_define

begin_define
define|#
directive|define
name|DC_MII_WRITEOP
value|0x01
end_define

begin_define
define|#
directive|define
name|DC_MII_TURNAROUND
value|0x02
end_define

begin_comment
comment|/*  * Registers specific to clone devices.  * This mainly relates to RX filter programming: not all 21x4x clones  * use the standard DEC filter programming mechanism.  */
end_comment

begin_comment
comment|/*  * ADMtek specific registers and constants for the AL981 and AN985.  * The AN985 doesn't use the magic PHY registers.  */
end_comment

begin_define
define|#
directive|define
name|DC_AL_CR
value|0x88
end_define

begin_comment
comment|/* command register */
end_comment

begin_define
define|#
directive|define
name|DC_AL_PAR0
value|0xA4
end_define

begin_comment
comment|/* station address */
end_comment

begin_define
define|#
directive|define
name|DC_AL_PAR1
value|0xA8
end_define

begin_comment
comment|/* station address */
end_comment

begin_define
define|#
directive|define
name|DC_AL_MAR0
value|0xAC
end_define

begin_comment
comment|/* multicast hash filter */
end_comment

begin_define
define|#
directive|define
name|DC_AL_MAR1
value|0xB0
end_define

begin_comment
comment|/* multicast hash filter */
end_comment

begin_define
define|#
directive|define
name|DC_AL_BMCR
value|0xB4
end_define

begin_comment
comment|/* built in PHY control */
end_comment

begin_define
define|#
directive|define
name|DC_AL_BMSR
value|0xB8
end_define

begin_comment
comment|/* built in PHY status */
end_comment

begin_define
define|#
directive|define
name|DC_AL_VENID
value|0xBC
end_define

begin_comment
comment|/* built in PHY ID0 */
end_comment

begin_define
define|#
directive|define
name|DC_AL_DEVID
value|0xC0
end_define

begin_comment
comment|/* built in PHY ID1 */
end_comment

begin_define
define|#
directive|define
name|DC_AL_ANAR
value|0xC4
end_define

begin_comment
comment|/* built in PHY autoneg advert */
end_comment

begin_define
define|#
directive|define
name|DC_AL_LPAR
value|0xC8
end_define

begin_comment
comment|/* bnilt in PHY link part. ability */
end_comment

begin_define
define|#
directive|define
name|DC_AL_ANER
value|0xCC
end_define

begin_comment
comment|/* built in PHY autoneg expansion */
end_comment

begin_define
define|#
directive|define
name|DC_AL_CR_ATUR
value|0x00000001
end_define

begin_comment
comment|/* automatic TX underrun recovery */
end_comment

begin_define
define|#
directive|define
name|DC_ADMTEK_PHYADDR
value|0x1
end_define

begin_define
define|#
directive|define
name|DC_AL_EE_NODEADDR
value|4
end_define

begin_comment
comment|/* End of ADMtek specific registers */
end_comment

begin_comment
comment|/*  * ASIX specific registers.  */
end_comment

begin_define
define|#
directive|define
name|DC_AX_FILTIDX
value|0x68
end_define

begin_comment
comment|/* RX filter index */
end_comment

begin_define
define|#
directive|define
name|DC_AX_FILTDATA
value|0x70
end_define

begin_comment
comment|/* RX filter data */
end_comment

begin_comment
comment|/*  * Special ASIX-specific bits in the ASIX NETCFG register (CSR6).  */
end_comment

begin_define
define|#
directive|define
name|DC_AX_NETCFG_RX_BROAD
value|0x00000100
end_define

begin_comment
comment|/*  * RX Filter Index Register values  */
end_comment

begin_define
define|#
directive|define
name|DC_AX_FILTIDX_PAR0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DC_AX_FILTIDX_PAR1
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DC_AX_FILTIDX_MAR0
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DC_AX_FILTIDX_MAR1
value|0x00000003
end_define

begin_comment
comment|/* End of ASIX specific registers */
end_comment

begin_comment
comment|/*  * Macronix specific registers. The Macronix chips have a special  * register for reading the NWAY status, which we don't use, plus  * a magic packet register, which we need to tweak a bit per the  * Macronix application notes.  */
end_comment

begin_define
define|#
directive|define
name|DC_MX_MAGICPACKET
value|0x80
end_define

begin_define
define|#
directive|define
name|DC_MX_NWAYSTAT
value|0xA0
end_define

begin_comment
comment|/*  * Magic packet register  */
end_comment

begin_define
define|#
directive|define
name|DC_MX_MPACK_DISABLE
value|0x00400000
end_define

begin_comment
comment|/*  * NWAY status register.  */
end_comment

begin_define
define|#
directive|define
name|DC_MX_NWAY_10BTHALF
value|0x08000000
end_define

begin_define
define|#
directive|define
name|DC_MX_NWAY_10BTFULL
value|0x10000000
end_define

begin_define
define|#
directive|define
name|DC_MX_NWAY_100BTHALF
value|0x20000000
end_define

begin_define
define|#
directive|define
name|DC_MX_NWAY_100BTFULL
value|0x40000000
end_define

begin_define
define|#
directive|define
name|DC_MX_NWAY_100BT4
value|0x80000000
end_define

begin_comment
comment|/*  * These are magic values that must be written into CSR16  * (DC_MX_MAGICPACKET) in order to put the chip into proper  * operating mode. The magic numbers are documented in the  * Macronix 98715 application notes.  */
end_comment

begin_define
define|#
directive|define
name|DC_MX_MAGIC_98713
value|0x0F370000
end_define

begin_define
define|#
directive|define
name|DC_MX_MAGIC_98713A
value|0x0B3C0000
end_define

begin_define
define|#
directive|define
name|DC_MX_MAGIC_98715
value|0x0B3C0000
end_define

begin_define
define|#
directive|define
name|DC_MX_MAGIC_98725
value|0x0B3C0000
end_define

begin_comment
comment|/* End of Macronix specific registers */
end_comment

begin_comment
comment|/*  * PNIC 82c168/82c169 specific registers.  * The PNIC has its own special NWAY support, which doesn't work,  * and shortcut ways of reading the EEPROM and MII bus.  */
end_comment

begin_define
define|#
directive|define
name|DC_PN_GPIO
value|0x60
end_define

begin_comment
comment|/* general purpose pins control */
end_comment

begin_define
define|#
directive|define
name|DC_PN_PWRUP_CFG
value|0x90
end_define

begin_comment
comment|/* config register, set by EEPROM */
end_comment

begin_define
define|#
directive|define
name|DC_PN_SIOCTL
value|0x98
end_define

begin_comment
comment|/* serial EEPROM control register */
end_comment

begin_define
define|#
directive|define
name|DC_PN_MII
value|0xA0
end_define

begin_comment
comment|/* MII access register */
end_comment

begin_define
define|#
directive|define
name|DC_PN_NWAY
value|0xB8
end_define

begin_comment
comment|/* Internal NWAY register */
end_comment

begin_comment
comment|/* Serial I/O EEPROM register */
end_comment

begin_define
define|#
directive|define
name|DC_PN_SIOCTL_DATA
value|0x0000003F
end_define

begin_define
define|#
directive|define
name|DC_PN_SIOCTL_OPCODE
value|0x00000300
end_define

begin_define
define|#
directive|define
name|DC_PN_SIOCTL_BUSY
value|0x80000000
end_define

begin_define
define|#
directive|define
name|DC_PN_EEOPCODE_ERASE
value|0x00000300
end_define

begin_define
define|#
directive|define
name|DC_PN_EEOPCODE_READ
value|0x00000600
end_define

begin_define
define|#
directive|define
name|DC_PN_EEOPCODE_WRITE
value|0x00000100
end_define

begin_comment
comment|/*  * The first two general purpose pins control speed selection and  * 100Mbps loopback on the 82c168 chip. The control bits should always  * be set (to make the data pins outputs) and the speed selction and  * loopback bits set accordingly when changing media. Physically, this  * will set the state of a relay mounted on the card.  */
end_comment

begin_define
define|#
directive|define
name|DC_PN_GPIO_DATA0
value|0x000000001
end_define

begin_define
define|#
directive|define
name|DC_PN_GPIO_DATA1
value|0x000000002
end_define

begin_define
define|#
directive|define
name|DC_PN_GPIO_DATA2
value|0x000000004
end_define

begin_define
define|#
directive|define
name|DC_PN_GPIO_DATA3
value|0x000000008
end_define

begin_define
define|#
directive|define
name|DC_PN_GPIO_CTL0
value|0x000000010
end_define

begin_define
define|#
directive|define
name|DC_PN_GPIO_CTL1
value|0x000000020
end_define

begin_define
define|#
directive|define
name|DC_PN_GPIO_CTL2
value|0x000000040
end_define

begin_define
define|#
directive|define
name|DC_PN_GPIO_CTL3
value|0x000000080
end_define

begin_define
define|#
directive|define
name|DC_PN_GPIO_SPEEDSEL
value|DC_PN_GPIO_DATA0
end_define

begin_comment
comment|/* 1 == 100Mbps, 0 == 10Mbps */
end_comment

begin_define
define|#
directive|define
name|DC_PN_GPIO_100TX_LOOP
value|DC_PN_GPIO_DATA1
end_define

begin_comment
comment|/* 1 == normal, 0 == loop */
end_comment

begin_define
define|#
directive|define
name|DC_PN_GPIO_BNC_ENB
value|DC_PN_GPIO_DATA2
end_define

begin_define
define|#
directive|define
name|DC_PN_GPIO_100TX_LNK
value|DC_PN_GPIO_DATA3
end_define

begin_define
define|#
directive|define
name|DC_PN_GPIO_SETBIT
parameter_list|(
name|sc
parameter_list|,
name|r
parameter_list|)
define|\
value|DC_SETBIT(sc, DC_PN_GPIO, ((r) | (r<< 4)))
end_define

begin_define
define|#
directive|define
name|DC_PN_GPIO_CLRBIT
parameter_list|(
name|sc
parameter_list|,
name|r
parameter_list|)
define|\
value|{						\ 		DC_SETBIT(sc, DC_PN_GPIO, ((r)<< 4));	\ 		DC_CLRBIT(sc, DC_PN_GPIO, (r));		\ 	}
end_define

begin_comment
comment|/* shortcut MII access register */
end_comment

begin_define
define|#
directive|define
name|DC_PN_MII_DATA
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|DC_PN_MII_RESERVER
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DC_PN_MII_REGADDR
value|0x007C0000
end_define

begin_define
define|#
directive|define
name|DC_PN_MII_PHYADDR
value|0x0F800000
end_define

begin_define
define|#
directive|define
name|DC_PN_MII_OPCODE
value|0x30000000
end_define

begin_define
define|#
directive|define
name|DC_PN_MII_BUSY
value|0x80000000
end_define

begin_define
define|#
directive|define
name|DC_PN_MIIOPCODE_READ
value|0x60020000
end_define

begin_define
define|#
directive|define
name|DC_PN_MIIOPCODE_WRITE
value|0x50020000
end_define

begin_comment
comment|/* Internal NWAY bits */
end_comment

begin_define
define|#
directive|define
name|DC_PN_NWAY_RESET
value|0x00000001
end_define

begin_comment
comment|/* reset */
end_comment

begin_define
define|#
directive|define
name|DC_PN_NWAY_PDOWN
value|0x00000002
end_define

begin_comment
comment|/* power down */
end_comment

begin_define
define|#
directive|define
name|DC_PN_NWAY_BYPASS
value|0x00000004
end_define

begin_comment
comment|/* bypass */
end_comment

begin_define
define|#
directive|define
name|DC_PN_NWAY_AUILOWCUR
value|0x00000008
end_define

begin_comment
comment|/* AUI low current */
end_comment

begin_define
define|#
directive|define
name|DC_PN_NWAY_TPEXTEND
value|0x00000010
end_define

begin_comment
comment|/* low squelch voltage */
end_comment

begin_define
define|#
directive|define
name|DC_PN_NWAY_POLARITY
value|0x00000020
end_define

begin_comment
comment|/* 0 == on, 1 == off */
end_comment

begin_define
define|#
directive|define
name|DC_PN_NWAY_TP
value|0x00000040
end_define

begin_comment
comment|/* 1 == tp, 0 == AUI */
end_comment

begin_define
define|#
directive|define
name|DC_PN_NWAY_AUIVOLT
value|0x00000080
end_define

begin_comment
comment|/* 1 == full, 0 == half */
end_comment

begin_define
define|#
directive|define
name|DC_PN_NWAY_DUPLEX
value|0x00000100
end_define

begin_comment
comment|/* LED, 1 == full, 0 == half */
end_comment

begin_define
define|#
directive|define
name|DC_PN_NWAY_LINKTEST
value|0x00000200
end_define

begin_comment
comment|/* 0 == on, 1 == off */
end_comment

begin_define
define|#
directive|define
name|DC_PN_NWAY_AUTODETECT
value|0x00000400
end_define

begin_comment
comment|/* 1 == off, 0 == on */
end_comment

begin_define
define|#
directive|define
name|DC_PN_NWAY_SPEEDSEL
value|0x00000800
end_define

begin_comment
comment|/* LED, 0 = 10, 1 == 100 */
end_comment

begin_define
define|#
directive|define
name|DC_PN_NWAY_NWAY_ENB
value|0x00001000
end_define

begin_comment
comment|/* 0 == off, 1 == on */
end_comment

begin_define
define|#
directive|define
name|DC_PN_NWAY_CAP10HDX
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DC_PN_NWAY_CAP10FDX
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DC_PN_NWAY_CAP100FDX
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DC_PN_NWAY_CAP100HDX
value|0x00010000
end_define

begin_define
define|#
directive|define
name|DC_PN_NWAY_CAP100T4
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DC_PN_NWAY_ANEGRESTART
value|0x02000000
end_define

begin_comment
comment|/* resets when aneg done */
end_comment

begin_define
define|#
directive|define
name|DC_PN_NWAY_REMFAULT
value|0x04000000
end_define

begin_define
define|#
directive|define
name|DC_PN_NWAY_LPAR10HDX
value|0x08000000
end_define

begin_define
define|#
directive|define
name|DC_PN_NWAY_LPAR10FDX
value|0x10000000
end_define

begin_define
define|#
directive|define
name|DC_PN_NWAY_LPAR100FDX
value|0x20000000
end_define

begin_define
define|#
directive|define
name|DC_PN_NWAY_LPAR100HDX
value|0x40000000
end_define

begin_define
define|#
directive|define
name|DC_PN_NWAY_LPAR100T4
value|0x80000000
end_define

begin_comment
comment|/* End of PNIC specific registers */
end_comment

begin_comment
comment|/*  * CONEXANT specific registers.  */
end_comment

begin_define
define|#
directive|define
name|DC_CONEXANT_PHYADDR
value|0x1
end_define

begin_define
define|#
directive|define
name|DC_CONEXANT_EE_NODEADDR
value|0x19A
end_define

begin_comment
comment|/* End of CONEXANT specific registers */
end_comment

begin_struct
struct|struct
name|dc_softc
block|{
name|struct
name|ifnet
modifier|*
name|dc_ifp
decl_stmt|;
comment|/* interface info */
name|device_t
name|dc_dev
decl_stmt|;
comment|/* device info */
name|bus_space_handle_t
name|dc_bhandle
decl_stmt|;
comment|/* bus space handle */
name|bus_space_tag_t
name|dc_btag
decl_stmt|;
comment|/* bus space tag */
name|bus_dma_tag_t
name|dc_ltag
decl_stmt|;
comment|/* tag for descriptor ring */
name|bus_dmamap_t
name|dc_lmap
decl_stmt|;
comment|/* map for descriptor ring */
name|u_int32_t
name|dc_laddr
decl_stmt|;
comment|/* DMA address of dc_ldata */
name|bus_dma_tag_t
name|dc_mtag
decl_stmt|;
comment|/* tag for mbufs */
name|bus_dmamap_t
name|dc_sparemap
decl_stmt|;
name|bus_dma_tag_t
name|dc_stag
decl_stmt|;
comment|/* tag for the setup frame */
name|bus_dmamap_t
name|dc_smap
decl_stmt|;
comment|/* map for the setup frame */
name|u_int32_t
name|dc_saddr
decl_stmt|;
comment|/* DMA address of setup frame */
name|void
modifier|*
name|dc_intrhand
decl_stmt|;
name|struct
name|resource
modifier|*
name|dc_irq
decl_stmt|;
name|struct
name|resource
modifier|*
name|dc_res
decl_stmt|;
name|struct
name|dc_type
modifier|*
name|dc_info
decl_stmt|;
comment|/* adapter info */
name|device_t
name|dc_miibus
decl_stmt|;
name|u_int8_t
name|dc_type
decl_stmt|;
name|u_int8_t
name|dc_pmode
decl_stmt|;
name|u_int8_t
name|dc_link
decl_stmt|;
name|u_int8_t
name|dc_cachesize
decl_stmt|;
name|int
name|dc_romwidth
decl_stmt|;
name|int
name|dc_pnic_rx_bug_save
decl_stmt|;
name|unsigned
name|char
modifier|*
name|dc_pnic_rx_buf
decl_stmt|;
name|int
name|dc_if_flags
decl_stmt|;
name|int
name|dc_if_media
decl_stmt|;
name|u_int32_t
name|dc_flags
decl_stmt|;
name|u_int32_t
name|dc_txthresh
decl_stmt|;
name|u_int8_t
modifier|*
name|dc_srom
decl_stmt|;
name|struct
name|dc_mediainfo
modifier|*
name|dc_mi
decl_stmt|;
name|struct
name|dc_list_data
modifier|*
name|dc_ldata
decl_stmt|;
name|struct
name|dc_chain_data
name|dc_cdata
decl_stmt|;
name|struct
name|callout
name|dc_stat_ch
decl_stmt|;
name|struct
name|callout
name|dc_wdog_ch
decl_stmt|;
name|int
name|dc_wdog_timer
decl_stmt|;
name|struct
name|mtx
name|dc_mtx
decl_stmt|;
ifdef|#
directive|ifdef
name|DEVICE_POLLING
name|int
name|rxcycles
decl_stmt|;
comment|/* ... when polling */
endif|#
directive|endif
name|int
name|suspended
decl_stmt|;
comment|/* 0 = normal  1 = suspended */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DC_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->dc_mtx)
end_define

begin_define
define|#
directive|define
name|DC_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->dc_mtx)
end_define

begin_define
define|#
directive|define
name|DC_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->dc_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|DC_TX_POLL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DC_TX_COALESCE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DC_TX_ADMTEK_WAR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DC_TX_USE_TX_INTR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DC_RX_FILTER_TULIP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DC_TX_INTR_FIRSTFRAG
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DC_PNIC_RX_BUG_WAR
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DC_TX_FIXED_RING
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DC_TX_STORENFWD
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DC_REDUCED_MII_POLL
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DC_TX_INTR_ALWAYS
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DC_21143_NWAY
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DC_128BIT_HASH
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DC_64BIT_HASH
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DC_TULIP_LEDS
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DC_TX_ONE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DC_TX_ALIGN
value|0x00010000
end_define

begin_comment
comment|/* align mbuf on tx */
end_comment

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
value|bus_space_write_4(sc->dc_btag, sc->dc_bhandle, reg, val)
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
value|bus_space_read_4(sc->dc_btag, sc->dc_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|DC_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|ETHER_ALIGN
value|2
end_define

begin_comment
comment|/*  * General constants that are fun to know.  */
end_comment

begin_comment
comment|/*  * DEC PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|DC_VENDORID_DEC
value|0x1011
end_define

begin_comment
comment|/*  * DEC/Intel 21143 PCI device ID  */
end_comment

begin_define
define|#
directive|define
name|DC_DEVICEID_21143
value|0x0019
end_define

begin_comment
comment|/*  * Macronix PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|DC_VENDORID_MX
value|0x10D9
end_define

begin_comment
comment|/*  * Macronix PMAC device IDs.  */
end_comment

begin_define
define|#
directive|define
name|DC_DEVICEID_98713
value|0x0512
end_define

begin_define
define|#
directive|define
name|DC_DEVICEID_987x5
value|0x0531
end_define

begin_define
define|#
directive|define
name|DC_DEVICEID_98727
value|0x0532
end_define

begin_define
define|#
directive|define
name|DC_DEVICEID_98732
value|0x0532
end_define

begin_comment
comment|/* Macronix PCI revision codes. */
end_comment

begin_define
define|#
directive|define
name|DC_REVISION_98713
value|0x00
end_define

begin_define
define|#
directive|define
name|DC_REVISION_98713A
value|0x10
end_define

begin_define
define|#
directive|define
name|DC_REVISION_98715
value|0x20
end_define

begin_define
define|#
directive|define
name|DC_REVISION_98715AEC_C
value|0x25
end_define

begin_define
define|#
directive|define
name|DC_REVISION_98725
value|0x30
end_define

begin_comment
comment|/*  * Compex PCI vendor ID.  */
end_comment

begin_define
define|#
directive|define
name|DC_VENDORID_CP
value|0x11F6
end_define

begin_comment
comment|/*  * Compex PMAC PCI device IDs.  */
end_comment

begin_define
define|#
directive|define
name|DC_DEVICEID_98713_CP
value|0x9881
end_define

begin_comment
comment|/*  * Lite-On PNIC PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|DC_VENDORID_LO
value|0x11AD
end_define

begin_comment
comment|/*  * 82c168/82c169 PNIC device IDs. Both chips have the same device  * ID but different revisions. Revision 0x10 is the 82c168, and  * 0x20 is the 82c169.  */
end_comment

begin_define
define|#
directive|define
name|DC_DEVICEID_82C168
value|0x0002
end_define

begin_define
define|#
directive|define
name|DC_REVISION_82C168
value|0x10
end_define

begin_define
define|#
directive|define
name|DC_REVISION_82C169
value|0x20
end_define

begin_comment
comment|/*   * Lite-On PNIC II device ID. Note: this is actually a Macronix 98715A  * with wake on lan/magic packet support.  */
end_comment

begin_define
define|#
directive|define
name|DC_DEVICEID_82C115
value|0xc115
end_define

begin_comment
comment|/*  * Davicom vendor ID.  */
end_comment

begin_define
define|#
directive|define
name|DC_VENDORID_DAVICOM
value|0x1282
end_define

begin_comment
comment|/*  * Davicom device IDs.  */
end_comment

begin_define
define|#
directive|define
name|DC_DEVICEID_DM9009
value|0x9009
end_define

begin_define
define|#
directive|define
name|DC_DEVICEID_DM9100
value|0x9100
end_define

begin_define
define|#
directive|define
name|DC_DEVICEID_DM9102
value|0x9102
end_define

begin_comment
comment|/*  * The DM9102A has the same PCI device ID as the DM9102,  * but a higher revision code.  */
end_comment

begin_define
define|#
directive|define
name|DC_REVISION_DM9102
value|0x10
end_define

begin_define
define|#
directive|define
name|DC_REVISION_DM9102A
value|0x30
end_define

begin_comment
comment|/*  * ADMtek vendor ID.  */
end_comment

begin_define
define|#
directive|define
name|DC_VENDORID_ADMTEK
value|0x1317
end_define

begin_comment
comment|/*  * ADMtek device IDs.  */
end_comment

begin_define
define|#
directive|define
name|DC_DEVICEID_AL981
value|0x0981
end_define

begin_define
define|#
directive|define
name|DC_DEVICEID_AN985
value|0x0985
end_define

begin_define
define|#
directive|define
name|DC_DEVICEID_FA511
value|0x1985
end_define

begin_define
define|#
directive|define
name|DC_DEVICEID_ADM9511
value|0x9511
end_define

begin_define
define|#
directive|define
name|DC_DEVICEID_ADM9513
value|0x9513
end_define

begin_comment
comment|/*  * 3COM PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|DC_VENDORID_3COM
value|0x10b7
end_define

begin_comment
comment|/*  * 3COM OfficeConnect 10/100B (3CSOHO100B-TX)  */
end_comment

begin_define
define|#
directive|define
name|DC_DEVICEID_3CSOHOB
value|0x9300
end_define

begin_comment
comment|/*  * ASIX vendor ID.  */
end_comment

begin_define
define|#
directive|define
name|DC_VENDORID_ASIX
value|0x125B
end_define

begin_comment
comment|/*  * ASIX device IDs.  */
end_comment

begin_define
define|#
directive|define
name|DC_DEVICEID_AX88140A
value|0x1400
end_define

begin_comment
comment|/*  * The ASIX AX88140 and ASIX AX88141 have the same vendor and  * device IDs but different revision values.  */
end_comment

begin_define
define|#
directive|define
name|DC_REVISION_88140
value|0x00
end_define

begin_define
define|#
directive|define
name|DC_REVISION_88141
value|0x10
end_define

begin_comment
comment|/*  * Accton vendor ID.  */
end_comment

begin_define
define|#
directive|define
name|DC_VENDORID_ACCTON
value|0x1113
end_define

begin_comment
comment|/*  * Accton device IDs.  */
end_comment

begin_define
define|#
directive|define
name|DC_DEVICEID_EN1217
value|0x1217
end_define

begin_define
define|#
directive|define
name|DC_DEVICEID_EN2242
value|0x1216
end_define

begin_comment
comment|/*  * Xircom vendor ID  */
end_comment

begin_define
define|#
directive|define
name|DC_VENDORID_XIRCOM
value|0x115d
end_define

begin_comment
comment|/*  * Xircom device IDs.  */
end_comment

begin_define
define|#
directive|define
name|DC_DEVICEID_X3201
value|0x0003
end_define

begin_comment
comment|/*  * D-Link vendor ID  */
end_comment

begin_define
define|#
directive|define
name|DC_VENDORID_DLINK
value|0x1186
end_define

begin_comment
comment|/*  * D-Link device IDs.  */
end_comment

begin_define
define|#
directive|define
name|DC_DEVICEID_DRP32TXD
value|0x1561
end_define

begin_comment
comment|/*  * Abocom vendor ID  */
end_comment

begin_define
define|#
directive|define
name|DC_VENDORID_ABOCOM
value|0x13d1
end_define

begin_comment
comment|/*  * Abocom device IDs.  */
end_comment

begin_define
define|#
directive|define
name|DC_DEVICEID_FE2500
value|0xAB02
end_define

begin_define
define|#
directive|define
name|DC_DEVICEID_FE2500MX
value|0xab08
end_define

begin_comment
comment|/*  * Conexant vendor ID.  */
end_comment

begin_define
define|#
directive|define
name|DC_VENDORID_CONEXANT
value|0x14f1
end_define

begin_comment
comment|/*  * Conexant device IDs.  */
end_comment

begin_define
define|#
directive|define
name|DC_DEVICEID_RS7112
value|0x1803
end_define

begin_comment
comment|/*  * Planex vendor ID  */
end_comment

begin_define
define|#
directive|define
name|DC_VENDORID_PLANEX
value|0x14ea
end_define

begin_comment
comment|/*  * Planex device IDs.  */
end_comment

begin_define
define|#
directive|define
name|DC_DEVICEID_FNW3602T
value|0xab08
end_define

begin_comment
comment|/*  * Not sure who this vendor should be, so we'll go with HAWKING until  * I can locate the right one.  */
end_comment

begin_define
define|#
directive|define
name|DC_VENDORID_HAWKING
value|0x17b3
end_define

begin_comment
comment|/*  * Sure looks like an abocom device ID, but it found on my hawking PN672TX  * card.  Use that for now, and upgrade later.  */
end_comment

begin_define
define|#
directive|define
name|DC_DEVICEID_HAWKING_PN672TX
value|0xab08
end_define

begin_comment
comment|/*  * Microsoft device ID.  */
end_comment

begin_define
define|#
directive|define
name|DC_VENDORID_MICROSOFT
value|0x1414
end_define

begin_comment
comment|/*  * Supported Microsoft PCI and cardbus NICs. These are really  * ADMtek parts in disguise.  */
end_comment

begin_define
define|#
directive|define
name|DC_DEVICEID_MSMN120
value|0x0001
end_define

begin_define
define|#
directive|define
name|DC_DEVICEID_MSMN130
value|0x0002
end_define

begin_comment
comment|/*  * Linksys vendor ID.  */
end_comment

begin_define
define|#
directive|define
name|DC_VENDORID_LINKSYS
value|0x1737
end_define

begin_comment
comment|/*  * Linksys device IDs.  */
end_comment

begin_define
define|#
directive|define
name|DC_DEVICEID_PCMPC200_AB08
value|0xab08
end_define

begin_define
define|#
directive|define
name|DC_DEVICEID_PCMPC200_AB09
value|0xab09
end_define

begin_define
define|#
directive|define
name|DC_DEVID
parameter_list|(
name|vendor
parameter_list|,
name|device
parameter_list|)
value|((device)<< 16 | (vendor))
end_define

begin_comment
comment|/*  * PCI low memory base and low I/O base register, and  * other PCI registers.  */
end_comment

begin_define
define|#
directive|define
name|DC_PCI_CFBIO
value|PCIR_BAR(0)
end_define

begin_comment
comment|/* Base I/O address */
end_comment

begin_define
define|#
directive|define
name|DC_PCI_CFBMA
value|PCIR_BAR(1)
end_define

begin_comment
comment|/* Base memory address */
end_comment

begin_define
define|#
directive|define
name|DC_PCI_CFDD
value|0x40
end_define

begin_comment
comment|/* Device and driver area */
end_comment

begin_define
define|#
directive|define
name|DC_PCI_CWUA0
value|0x44
end_define

begin_comment
comment|/* Wake-Up LAN addr 0 */
end_comment

begin_define
define|#
directive|define
name|DC_PCI_CWUA1
value|0x48
end_define

begin_comment
comment|/* Wake-Up LAN addr 1 */
end_comment

begin_define
define|#
directive|define
name|DC_PCI_SOP0
value|0x4C
end_define

begin_comment
comment|/* SecureON passwd 0 */
end_comment

begin_define
define|#
directive|define
name|DC_PCI_SOP1
value|0x50
end_define

begin_comment
comment|/* SecureON passwd 1 */
end_comment

begin_define
define|#
directive|define
name|DC_PCI_CWUC
value|0x54
end_define

begin_comment
comment|/* Configuration Wake-Up cmd */
end_comment

begin_define
define|#
directive|define
name|DC_21143_PB_REV
value|0x00000030
end_define

begin_define
define|#
directive|define
name|DC_21143_TB_REV
value|0x00000030
end_define

begin_define
define|#
directive|define
name|DC_21143_PC_REV
value|0x00000030
end_define

begin_define
define|#
directive|define
name|DC_21143_TC_REV
value|0x00000030
end_define

begin_define
define|#
directive|define
name|DC_21143_PD_REV
value|0x00000041
end_define

begin_define
define|#
directive|define
name|DC_21143_TD_REV
value|0x00000041
end_define

begin_comment
comment|/* Configuration and driver area */
end_comment

begin_define
define|#
directive|define
name|DC_CFDD_DRVUSE
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|DC_CFDD_SNOOZE_MODE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|DC_CFDD_SLEEP_MODE
value|0x80000000
end_define

begin_comment
comment|/* Configuration wake-up command register */
end_comment

begin_define
define|#
directive|define
name|DC_CWUC_MUST_BE_ZERO
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DC_CWUC_SECUREON_ENB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DC_CWUC_FORCE_WUL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DC_CWUC_BNC_ABILITY
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DC_CWUC_AUI_ABILITY
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DC_CWUC_TP10_ABILITY
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DC_CWUC_MII_ABILITY
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DC_CWUC_SYM_ABILITY
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DC_CWUC_LOCK
value|0x00000100
end_define

begin_comment
comment|/*  * SROM nonsense.  */
end_comment

begin_define
define|#
directive|define
name|DC_IB_CTLRCNT
value|0x13
end_define

begin_define
define|#
directive|define
name|DC_IB_LEAF0_CNUM
value|0x1A
end_define

begin_define
define|#
directive|define
name|DC_IB_LEAF0_OFFSET
value|0x1B
end_define

begin_struct
struct|struct
name|dc_info_leaf
block|{
name|u_int16_t
name|dc_conntype
decl_stmt|;
name|u_int8_t
name|dc_blkcnt
decl_stmt|;
name|u_int8_t
name|dc_rsvd
decl_stmt|;
name|u_int16_t
name|dc_infoblk
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DC_CTYPE_10BT
value|0x0000
end_define

begin_define
define|#
directive|define
name|DC_CTYPE_10BT_NWAY
value|0x0100
end_define

begin_define
define|#
directive|define
name|DC_CTYPE_10BT_FDX
value|0x0204
end_define

begin_define
define|#
directive|define
name|DC_CTYPE_10B2
value|0x0001
end_define

begin_define
define|#
directive|define
name|DC_CTYPE_10B5
value|0x0002
end_define

begin_define
define|#
directive|define
name|DC_CTYPE_100BT
value|0x0003
end_define

begin_define
define|#
directive|define
name|DC_CTYPE_100BT_FDX
value|0x0205
end_define

begin_define
define|#
directive|define
name|DC_CTYPE_100T4
value|0x0006
end_define

begin_define
define|#
directive|define
name|DC_CTYPE_100FX
value|0x0007
end_define

begin_define
define|#
directive|define
name|DC_CTYPE_100FX_FDX
value|0x0208
end_define

begin_define
define|#
directive|define
name|DC_CTYPE_MII_10BT
value|0x0009
end_define

begin_define
define|#
directive|define
name|DC_CTYPE_MII_10BT_FDX
value|0x020A
end_define

begin_define
define|#
directive|define
name|DC_CTYPE_MII_100BT
value|0x000D
end_define

begin_define
define|#
directive|define
name|DC_CTYPE_MII_100BT_FDX
value|0x020E
end_define

begin_define
define|#
directive|define
name|DC_CTYPE_MII_100T4
value|0x000F
end_define

begin_define
define|#
directive|define
name|DC_CTYPE_MII_100FX
value|0x0010
end_define

begin_define
define|#
directive|define
name|DC_CTYPE_MII_100FX_FDX
value|0x0211
end_define

begin_define
define|#
directive|define
name|DC_CTYPE_DYN_PUP_AUTOSENSE
value|0x0800
end_define

begin_define
define|#
directive|define
name|DC_CTYPE_PUP_AUTOSENSE
value|0x8800
end_define

begin_define
define|#
directive|define
name|DC_CTYPE_NOMEDIA
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|DC_EBLOCK_SIA
value|0x0002
end_define

begin_define
define|#
directive|define
name|DC_EBLOCK_MII
value|0x0003
end_define

begin_define
define|#
directive|define
name|DC_EBLOCK_SYM
value|0x0004
end_define

begin_define
define|#
directive|define
name|DC_EBLOCK_RESET
value|0x0005
end_define

begin_define
define|#
directive|define
name|DC_EBLOCK_PHY_SHUTDOWN
value|0x0006
end_define

begin_struct
struct|struct
name|dc_leaf_hdr
block|{
name|u_int16_t
name|dc_mtype
decl_stmt|;
name|u_int8_t
name|dc_mcnt
decl_stmt|;
name|u_int8_t
name|dc_rsvd
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dc_eblock_hdr
block|{
name|u_int8_t
name|dc_len
decl_stmt|;
name|u_int8_t
name|dc_type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dc_eblock_sia
block|{
name|struct
name|dc_eblock_hdr
name|dc_sia_hdr
decl_stmt|;
name|u_int8_t
name|dc_sia_code
decl_stmt|;
union|union
block|{
struct|struct
name|dc_sia_ext
block|{
comment|/* if (dc_sia_code& DC_SIA_CODE_EXT) */
name|u_int8_t
name|dc_sia_mediaspec
index|[
literal|6
index|]
decl_stmt|;
comment|/* CSR13, CSR14, CSR15 */
name|u_int8_t
name|dc_sia_gpio_ctl
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|dc_sia_gpio_dat
index|[
literal|2
index|]
decl_stmt|;
block|}
name|dc_sia_ext
struct|;
struct|struct
name|dc_sia_noext
block|{
name|u_int8_t
name|dc_sia_gpio_ctl
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|dc_sia_gpio_dat
index|[
literal|2
index|]
decl_stmt|;
block|}
name|dc_sia_noext
struct|;
block|}
name|dc_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DC_SIA_CODE_10BT
value|0x00
end_define

begin_define
define|#
directive|define
name|DC_SIA_CODE_10B2
value|0x01
end_define

begin_define
define|#
directive|define
name|DC_SIA_CODE_10B5
value|0x02
end_define

begin_define
define|#
directive|define
name|DC_SIA_CODE_10BT_FDX
value|0x04
end_define

begin_define
define|#
directive|define
name|DC_SIA_CODE_EXT
value|0x40
end_define

begin_comment
comment|/*  * Note that the first word in the gpr and reset  * sequences is always a control word.  */
end_comment

begin_struct
struct|struct
name|dc_eblock_mii
block|{
name|struct
name|dc_eblock_hdr
name|dc_mii_hdr
decl_stmt|;
name|u_int8_t
name|dc_mii_phynum
decl_stmt|;
name|u_int8_t
name|dc_gpr_len
decl_stmt|;
comment|/*	u_int16_t		dc_gpr_dat[n]; */
comment|/*	u_int8_t		dc_reset_len; */
comment|/*	u_int16_t		dc_reset_dat[n]; */
comment|/* There are other fields after these, but we don't  * care about them since they can be determined by looking  * at the PHY.  */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dc_eblock_sym
block|{
name|struct
name|dc_eblock_hdr
name|dc_sym_hdr
decl_stmt|;
name|u_int8_t
name|dc_sym_code
decl_stmt|;
name|u_int8_t
name|dc_sym_gpio_ctl
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|dc_sym_gpio_dat
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|dc_sym_cmd
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DC_SYM_CODE_100BT
value|0x03
end_define

begin_define
define|#
directive|define
name|DC_SYM_CODE_100BT_FDX
value|0x05
end_define

begin_define
define|#
directive|define
name|DC_SYM_CODE_100T4
value|0x06
end_define

begin_define
define|#
directive|define
name|DC_SYM_CODE_100FX
value|0x07
end_define

begin_define
define|#
directive|define
name|DC_SYM_CODE_100FX_FDX
value|0x08
end_define

begin_struct
struct|struct
name|dc_eblock_reset
block|{
name|struct
name|dc_eblock_hdr
name|dc_reset_hdr
decl_stmt|;
name|u_int8_t
name|dc_reset_len
decl_stmt|;
comment|/*	u_int16_t		dc_reset_dat[n]; */
block|}
struct|;
end_struct

end_unit

