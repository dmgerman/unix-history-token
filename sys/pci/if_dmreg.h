begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998, 1999  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Davicom register definitions.  */
end_comment

begin_define
define|#
directive|define
name|DM_BUSCTL
value|0x00
end_define

begin_comment
comment|/* bus control */
end_comment

begin_define
define|#
directive|define
name|DM_TXSTART
value|0x08
end_define

begin_comment
comment|/* tx start demand */
end_comment

begin_define
define|#
directive|define
name|DM_RXSTART
value|0x10
end_define

begin_comment
comment|/* rx start demand */
end_comment

begin_define
define|#
directive|define
name|DM_RXADDR
value|0x18
end_define

begin_comment
comment|/* rx descriptor list start addr */
end_comment

begin_define
define|#
directive|define
name|DM_TXADDR
value|0x20
end_define

begin_comment
comment|/* tx descriptor list start addr */
end_comment

begin_define
define|#
directive|define
name|DM_ISR
value|0x28
end_define

begin_comment
comment|/* interrupt status register */
end_comment

begin_define
define|#
directive|define
name|DM_NETCFG
value|0x30
end_define

begin_comment
comment|/* network config register */
end_comment

begin_define
define|#
directive|define
name|DM_IMR
value|0x38
end_define

begin_comment
comment|/* interrupt mask */
end_comment

begin_define
define|#
directive|define
name|DM_FRAMESDISCARDED
value|0x40
end_define

begin_comment
comment|/* # of discarded frames */
end_comment

begin_define
define|#
directive|define
name|DM_SIO
value|0x48
end_define

begin_comment
comment|/* MII and ROM/EEPROM access */
end_comment

begin_define
define|#
directive|define
name|DM_RESERVED
value|0x50
end_define

begin_define
define|#
directive|define
name|DM_GENTIMER
value|0x58
end_define

begin_comment
comment|/* general timer */
end_comment

begin_define
define|#
directive|define
name|DM_GENPORT
value|0x60
end_define

begin_comment
comment|/* general purpose port */
end_comment

begin_comment
comment|/*  * Bus control bits.  */
end_comment

begin_define
define|#
directive|define
name|DM_BUSCTL_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DM_BUSCTL_ARBITRATION
value|0x00000002
end_define

begin_define
define|#
directive|define
name|WB_BUSCTL_SKIPLEN
value|0x0000007C
end_define

begin_define
define|#
directive|define
name|DM_BUSCTL_BIGENDIAN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DM_BUSCTL_BURSTLEN
value|0x00003F00
end_define

begin_define
define|#
directive|define
name|DM_BUSCTL_CACHEALIGN
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|DM_BUSCTL_BUF_BIGENDIAN
value|0x00100000
end_define

begin_define
define|#
directive|define
name|DM_BUSCTL_READMULTI
value|0x00200000
end_define

begin_define
define|#
directive|define
name|DM_SKIPLEN_1LONG
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DM_SKIPLEN_2LONG
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DM_SKIPLEN_3LONG
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DM_SKIPLEN_4LONG
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DM_SKIPLEN_5LONG
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DM_CACHEALIGN_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DM_CACHEALIGN_8LONG
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DM_CACHEALIGN_16LONG
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DM_CACHEALIGN_32LONG
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|DM_BURSTLEN_UNLIMIT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DM_BURSTLEN_1LONG
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DM_BURSTLEN_2LONG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DM_BURSTLEN_4LONG
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DM_BURSTLEN_8LONG
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DM_BURSTLEN_16LONG
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DM_BURSTLEN_32LONG
value|0x00002000
end_define

begin_comment
comment|/*  * Interrupt status bits.  */
end_comment

begin_define
define|#
directive|define
name|DM_ISR_TX_OK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DM_ISR_TX_IDLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DM_ISR_TX_NOBUF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DM_ISR_TX_JABBERTIMEO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DM_ISR_TX_UNDERRUN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DM_ISR_RX_OK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DM_ISR_RX_NOBUF
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DM_ISR_RX_IDLE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DM_ISR_RX_WATDOGTIMEO
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DM_ISR_TX_EARLY
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DM_ISR_TIMER_EXPIRED
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DM_ISR_BUS_ERR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DM_ISR_ABNORMAL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DM_ISR_NORMAL
value|0x00010000
end_define

begin_define
define|#
directive|define
name|DM_ISR_RX_STATE
value|0x000E0000
end_define

begin_define
define|#
directive|define
name|DM_ISR_TX_STATE
value|0x00700000
end_define

begin_define
define|#
directive|define
name|DM_ISR_BUSERRTYPE
value|0x03800000
end_define

begin_define
define|#
directive|define
name|DM_RXSTATE_STOPPED
value|0x00000000
end_define

begin_comment
comment|/* 000 - Stopped */
end_comment

begin_define
define|#
directive|define
name|DM_RXSTATE_FETCH
value|0x00020000
end_define

begin_comment
comment|/* 001 - Fetching descriptor */
end_comment

begin_define
define|#
directive|define
name|DM_RXSTATE_ENDCHECK
value|0x00040000
end_define

begin_comment
comment|/* 010 - check for rx end */
end_comment

begin_define
define|#
directive|define
name|DM_RXSTATE_WAIT
value|0x00060000
end_define

begin_comment
comment|/* 011 - waiting for packet */
end_comment

begin_define
define|#
directive|define
name|DM_RXSTATE_SUSPEND
value|0x00080000
end_define

begin_comment
comment|/* 100 - suspend rx */
end_comment

begin_define
define|#
directive|define
name|DM_RXSTATE_CLOSE
value|0x000A0000
end_define

begin_comment
comment|/* 101 - close tx desc */
end_comment

begin_define
define|#
directive|define
name|DM_RXSTATE_FLUSH
value|0x000C0000
end_define

begin_comment
comment|/* 110 - flush from FIFO */
end_comment

begin_define
define|#
directive|define
name|DM_RXSTATE_DEQUEUE
value|0x000E0000
end_define

begin_comment
comment|/* 111 - dequeue from FIFO */
end_comment

begin_define
define|#
directive|define
name|DM_TXSTATE_RESET
value|0x00000000
end_define

begin_comment
comment|/* 000 - reset */
end_comment

begin_define
define|#
directive|define
name|DM_TXSTATE_FETCH
value|0x00100000
end_define

begin_comment
comment|/* 001 - fetching descriptor */
end_comment

begin_define
define|#
directive|define
name|DM_TXSTATE_WAITEND
value|0x00200000
end_define

begin_comment
comment|/* 010 - wait for tx end */
end_comment

begin_define
define|#
directive|define
name|DM_TXSTATE_READING
value|0x00300000
end_define

begin_comment
comment|/* 011 - read and enqueue */
end_comment

begin_define
define|#
directive|define
name|DM_TXSTATE_RSVD
value|0x00400000
end_define

begin_comment
comment|/* 100 - reserved */
end_comment

begin_define
define|#
directive|define
name|DM_TXSTATE_SETUP
value|0x00500000
end_define

begin_comment
comment|/* 101 - setup packet */
end_comment

begin_define
define|#
directive|define
name|DM_TXSTATE_SUSPEND
value|0x00600000
end_define

begin_comment
comment|/* 110 - suspend tx */
end_comment

begin_define
define|#
directive|define
name|DM_TXSTATE_CLOSE
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
name|DM_NETCFG_LINKSTAT_PCS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DM_NETCFG_RX_ON
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DM_NETCFG_RX_BADFRAMES
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DM_NETCFG_RX_PROMISC
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DM_NETCFG_RX_ALLMULTI
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DM_NETCFG_RX_BROAD
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DM_NETCFG_FULLDUPLEX
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DM_NETCFG_LOOPBACK
value|0x00000C00
end_define

begin_define
define|#
directive|define
name|DM_NETCFG_FORCECOLL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DM_NETCFG_TX_ON
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DM_NETCFG_TX_THRESH
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|DM_NETCFG_PORTSEL
value|0x00040000
end_define

begin_comment
comment|/* 0 == SRL, 1 == MII/SYM */
end_comment

begin_define
define|#
directive|define
name|DM_NETCFG_HEARTBEAT
value|0x00080000
end_define

begin_comment
comment|/* 0 == ON, 1 == OFF */
end_comment

begin_define
define|#
directive|define
name|DM_NETCFG_STORENFWD
value|0x00200000
end_define

begin_define
define|#
directive|define
name|DM_NETCFG_SPEEDSEL
value|0x00400000
end_define

begin_comment
comment|/* 1 == 10, 0 == 100 */
end_comment

begin_define
define|#
directive|define
name|DM_NETCFG_PCS
value|0x00800000
end_define

begin_define
define|#
directive|define
name|DM_NETCFG_SCRAMBLER
value|0x01000000
end_define

begin_define
define|#
directive|define
name|DM_NETCFG_RX_ALL
value|0x40000000
end_define

begin_define
define|#
directive|define
name|DM_OPMODE_NORM
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DM_OPMODE_INTLOOP
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DM_OPMODE_EXTLOOP
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DM_TXTHRESH_72BYTES
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DM_TXTHRESH_96BYTES
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DM_TXTHRESH_128BYTES
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DM_TXTHRESH_160BYTES
value|0x0000C000
end_define

begin_comment
comment|/*  * Interrupt mask bits.  */
end_comment

begin_define
define|#
directive|define
name|DM_IMR_TX_OK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DM_IMR_TX_IDLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DM_IMR_TX_NOBUF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DM_IMR_TX_JABBERTIMEO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DM_IMR_TX_UNDERRUN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DM_IMR_RX_OK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DM_IMR_RX_NOBUF
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DM_IMR_RX_IDLE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DM_IMR_RX_WATDOGTIMEO
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DM_IMR_TX_EARLY
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DM_IMR_TIMER_EXPIRED
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DM_IMR_BUS_ERR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DM_IMR_RX_EARLY
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DM_IMR_ABNORMAL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DM_IMR_NORMAL
value|0x00010000
end_define

begin_define
define|#
directive|define
name|DM_INTRS
define|\
value|(DM_IMR_RX_OK|DM_IMR_TX_OK|DM_IMR_RX_NOBUF|DM_IMR_RX_WATDOGTIMEO|\ 	DM_IMR_TX_NOBUF|DM_IMR_TX_UNDERRUN|DM_IMR_BUS_ERR|		\ 	DM_IMR_ABNORMAL|DM_IMR_NORMAL|
comment|/*DM_IMR_TX_EARLY*/
value|\ 	DM_IMR_TX_IDLE|DM_IMR_RX_IDLE)
end_define

begin_comment
comment|/*  * Serial I/O (EEPROM/ROM) bits.  */
end_comment

begin_define
define|#
directive|define
name|DM_SIO_EE_CS
value|0x00000001
end_define

begin_comment
comment|/* EEPROM chip select */
end_comment

begin_define
define|#
directive|define
name|DM_SIO_EE_CLK
value|0x00000002
end_define

begin_comment
comment|/* EEPROM clock */
end_comment

begin_define
define|#
directive|define
name|DM_SIO_EE_DATAIN
value|0x00000004
end_define

begin_comment
comment|/* EEPROM data output */
end_comment

begin_define
define|#
directive|define
name|DM_SIO_EE_DATAOUT
value|0x00000008
end_define

begin_comment
comment|/* EEPROM data input */
end_comment

begin_define
define|#
directive|define
name|DM_SIO_EESEL
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DM_SIO_ROMSEL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DM_SIO_ROMCTL_WRITE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DM_SIO_ROMCTL_READ
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DM_SIO_MII_CLK
value|0x00010000
end_define

begin_comment
comment|/* MDIO clock */
end_comment

begin_define
define|#
directive|define
name|DM_SIO_MII_DATAOUT
value|0x00020000
end_define

begin_comment
comment|/* MDIO data out */
end_comment

begin_define
define|#
directive|define
name|DM_SIO_MII_DIR
value|0x00040000
end_define

begin_comment
comment|/* MDIO dir */
end_comment

begin_define
define|#
directive|define
name|DM_SIO_MII_DATAIN
value|0x00080000
end_define

begin_comment
comment|/* MDIO data in */
end_comment

begin_define
define|#
directive|define
name|DM_EECMD_WRITE
value|0x140
end_define

begin_define
define|#
directive|define
name|DM_EECMD_READ
value|0x180
end_define

begin_define
define|#
directive|define
name|DM_EECMD_ERASE
value|0x1c0
end_define

begin_define
define|#
directive|define
name|DM_EE_NODEADDR_OFFSET
value|0x70
end_define

begin_define
define|#
directive|define
name|DM_EE_NODEADDR
value|10
end_define

begin_comment
comment|/*  * General purpose timer register  */
end_comment

begin_define
define|#
directive|define
name|DM_TIMER_VALUE
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|DM_TIMER_CONTINUOUS
value|0x00010000
end_define

begin_comment
comment|/*  * Size of a setup frame.         */
end_comment

begin_define
define|#
directive|define
name|DM_SFRAME_LEN
value|192
end_define

begin_comment
comment|/*  * Davicom TX/RX list structure.  */
end_comment

begin_struct
struct|struct
name|dm_desc
block|{
name|u_int32_t
name|dm_status
decl_stmt|;
name|u_int32_t
name|dm_ctl
decl_stmt|;
name|u_int32_t
name|dm_ptr1
decl_stmt|;
name|u_int32_t
name|dm_ptr2
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|dm_mbuf
decl_stmt|;
name|struct
name|dm_desc
modifier|*
name|dm_nextdesc
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|dm_data
value|dm_ptr1
end_define

begin_define
define|#
directive|define
name|dm_next
value|dm_ptr2
end_define

begin_define
define|#
directive|define
name|DM_RXSTAT_FIFOOFLOW
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DM_RXSTAT_CRCERR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DM_RXSTAT_DRIBBLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DM_RXSTAT_WATCHDOG
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DM_RXSTAT_FRAMETYPE
value|0x00000020
end_define

begin_comment
comment|/* 0 == IEEE 802.3 */
end_comment

begin_define
define|#
directive|define
name|DM_RXSTAT_COLLSEEN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DM_RXSTAT_GIANT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DM_RXSTAT_LASTFRAG
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DM_RXSTAT_FIRSTFRAG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DM_RXSTAT_MULTICAST
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DM_RXSTAT_RUNT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DM_RXSTAT_RXTYPE
value|0x00003000
end_define

begin_define
define|#
directive|define
name|DM_RXSTAT_RXERR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DM_RXSTAT_RXLEN
value|0x3FFF0000
end_define

begin_define
define|#
directive|define
name|DM_RXSTAT_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|DM_RXBYTES
parameter_list|(
name|x
parameter_list|)
value|((x& DM_RXSTAT_RXLEN)>> 16)
end_define

begin_define
define|#
directive|define
name|DM_RXSTAT
value|(DM_RXSTAT_FIRSTFRAG|DM_RXSTAT_LASTFRAG|DM_RXSTAT_OWN)
end_define

begin_define
define|#
directive|define
name|DM_RXCTL_BUFLEN1
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|DM_RXCTL_BUFLEN2
value|0x00FFF000
end_define

begin_define
define|#
directive|define
name|DM_RXCTL_RLINK
value|0x01000000
end_define

begin_define
define|#
directive|define
name|DM_RXCTL_RLAST
value|0x02000000
end_define

begin_define
define|#
directive|define
name|DM_TXSTAT_DEFER
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DM_TXSTAT_UNDERRUN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DM_TXSTAT_LINKFAIL
value|0x00000003
end_define

begin_define
define|#
directive|define
name|DM_TXSTAT_COLLCNT
value|0x00000078
end_define

begin_define
define|#
directive|define
name|DM_TXSTAT_SQE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DM_TXSTAT_EXCESSCOLL
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DM_TXSTAT_LATECOLL
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DM_TXSTAT_NOCARRIER
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DM_TXSTAT_CARRLOST
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DM_TXSTAT_JABTIMEO
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DM_TXSTAT_ERRSUM
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DM_TXSTAT_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|DM_TXCTL_BUFLEN1
value|0x000007FF
end_define

begin_define
define|#
directive|define
name|DM_TXCTL_BUFLEN2
value|0x003FF800
end_define

begin_define
define|#
directive|define
name|DM_TXCTL_FILTTYPE0
value|0x00400000
end_define

begin_define
define|#
directive|define
name|DM_TXCTL_PAD
value|0x00800000
end_define

begin_define
define|#
directive|define
name|DM_TXCTL_TLINK
value|0x01000000
end_define

begin_define
define|#
directive|define
name|DM_TXCTL_TLAST
value|0x02000000
end_define

begin_define
define|#
directive|define
name|DM_TXCTL_NOCRC
value|0x04000000
end_define

begin_define
define|#
directive|define
name|DM_TXCTL_SETUP
value|0x08000000
end_define

begin_define
define|#
directive|define
name|DM_TXCTL_FILTTYPE1
value|0x10000000
end_define

begin_define
define|#
directive|define
name|DM_TXCTL_FIRSTFRAG
value|0x20000000
end_define

begin_define
define|#
directive|define
name|DM_TXCTL_LASTFRAG
value|0x40000000
end_define

begin_define
define|#
directive|define
name|DM_TXCTL_FINT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|DM_FILTER_PERFECT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DM_FILTER_HASHPERF
value|0x00400000
end_define

begin_define
define|#
directive|define
name|DM_FILTER_INVERSE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|DM_FILTER_HASHONLY
value|0x10400000
end_define

begin_define
define|#
directive|define
name|DM_MAXFRAGS
value|16
end_define

begin_define
define|#
directive|define
name|DM_RX_LIST_CNT
value|64
end_define

begin_define
define|#
directive|define
name|DM_TX_LIST_CNT
value|128
end_define

begin_define
define|#
directive|define
name|DM_MIN_FRAMELEN
value|60
end_define

begin_define
define|#
directive|define
name|DM_RXLEN
value|1536
end_define

begin_define
define|#
directive|define
name|DM_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = (x + 1) % y
end_define

begin_struct
struct|struct
name|dm_list_data
block|{
name|struct
name|dm_desc
name|dm_rx_list
index|[
name|DM_RX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|dm_desc
name|dm_tx_list
index|[
name|DM_TX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|dm_desc
name|dm_sframe
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dm_chain_data
block|{
name|u_int32_t
name|dm_sbuf
index|[
name|DM_SFRAME_LEN
operator|/
sizeof|sizeof
argument_list|(
name|u_int32_t
argument_list|)
index|]
decl_stmt|;
name|u_int8_t
name|dm_pad
index|[
name|DM_MIN_FRAMELEN
index|]
decl_stmt|;
name|int
name|dm_tx_prod
decl_stmt|;
name|int
name|dm_tx_cons
decl_stmt|;
name|int
name|dm_tx_cnt
decl_stmt|;
name|int
name|dm_rx_prod
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dm_type
block|{
name|u_int16_t
name|dm_vid
decl_stmt|;
name|u_int16_t
name|dm_did
decl_stmt|;
name|char
modifier|*
name|dm_name
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dm_mii_frame
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
name|DM_MII_STARTDELIM
value|0x01
end_define

begin_define
define|#
directive|define
name|DM_MII_READOP
value|0x02
end_define

begin_define
define|#
directive|define
name|DM_MII_WRITEOP
value|0x01
end_define

begin_define
define|#
directive|define
name|DM_MII_TURNAROUND
value|0x02
end_define

begin_struct
struct|struct
name|dm_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
comment|/* interface info */
name|bus_space_handle_t
name|dm_bhandle
decl_stmt|;
comment|/* bus space handle */
name|bus_space_tag_t
name|dm_btag
decl_stmt|;
comment|/* bus space tag */
name|void
modifier|*
name|dm_intrhand
decl_stmt|;
name|struct
name|resource
modifier|*
name|dm_irq
decl_stmt|;
name|struct
name|resource
modifier|*
name|dm_res
decl_stmt|;
name|device_t
name|dm_miibus
decl_stmt|;
name|u_int8_t
name|dm_unit
decl_stmt|;
comment|/* interface number */
name|int
name|dm_cachesize
decl_stmt|;
name|struct
name|dm_list_data
modifier|*
name|dm_ldata
decl_stmt|;
name|struct
name|dm_chain_data
name|dm_cdata
decl_stmt|;
name|struct
name|callout_handle
name|dm_stat_ch
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
value|bus_space_write_4(sc->dm_btag, sc->dm_bhandle, reg, val)
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
value|bus_space_write_2(sc->dm_btag, sc->dm_bbhandle, reg, val)
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
value|bus_space_write_1(sc->dm_btag, sc->dm_bhandle, reg, val)
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
value|bus_space_read_4(sc->dm_btag, sc->dm_bhandle, reg)
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
value|bus_space_read_2(sc->dm_btag, sc->dm_bhandle, reg)
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
value|bus_space_read_1(sc->dm_btag, sc->dm_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|DM_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|ETHER_ALIGN
value|2
end_define

begin_comment
comment|/*  * General constants that are fun to know.  *  * Davicom PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|DM_VENDORID
value|0x1282
end_define

begin_comment
comment|/*  * Davicom DM9102 device ID.  */
end_comment

begin_define
define|#
directive|define
name|DM_DEVICEID_DM9102
value|0x9102
end_define

begin_define
define|#
directive|define
name|DM_DEVICEID_DM9100
value|0x9100
end_define

begin_comment
comment|/*  * PCI low memory base and low I/O base register, and  * other PCI registers.  */
end_comment

begin_define
define|#
directive|define
name|DM_PCI_VENDOR_ID
value|0x00
end_define

begin_define
define|#
directive|define
name|DM_PCI_DEVICE_ID
value|0x02
end_define

begin_define
define|#
directive|define
name|DM_PCI_COMMAND
value|0x04
end_define

begin_define
define|#
directive|define
name|DM_PCI_STATUS
value|0x06
end_define

begin_define
define|#
directive|define
name|DM_PCI_REVID
value|0x08
end_define

begin_define
define|#
directive|define
name|DM_PCI_CLASSCODE
value|0x09
end_define

begin_define
define|#
directive|define
name|DM_PCI_CACHELEN
value|0x0C
end_define

begin_define
define|#
directive|define
name|DM_PCI_LATENCY_TIMER
value|0x0D
end_define

begin_define
define|#
directive|define
name|DM_PCI_HEADER_TYPE
value|0x0E
end_define

begin_define
define|#
directive|define
name|DM_PCI_LOIO
value|0x10
end_define

begin_define
define|#
directive|define
name|DM_PCI_LOMEM
value|0x14
end_define

begin_define
define|#
directive|define
name|DM_PCI_BIOSROM
value|0x30
end_define

begin_define
define|#
directive|define
name|DM_PCI_INTLINE
value|0x3C
end_define

begin_define
define|#
directive|define
name|DM_PCI_INTPIN
value|0x3D
end_define

begin_define
define|#
directive|define
name|DM_PCI_MINGNT
value|0x3E
end_define

begin_define
define|#
directive|define
name|DM_PCI_MINLAT
value|0x0F
end_define

begin_define
define|#
directive|define
name|DM_PCI_RESETOPT
value|0x48
end_define

begin_define
define|#
directive|define
name|DM_PCI_EEPROM_DATA
value|0x4C
end_define

begin_comment
comment|/* power management registers */
end_comment

begin_define
define|#
directive|define
name|DM_PCI_CAPID
value|0x50
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|DM_PCI_NEXTPTR
value|0x51
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|DM_PCI_PWRMGMTCAP
value|0x52
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|DM_PCI_PWRMGMTCTRL
value|0x54
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|DM_PSTATE_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|DM_PSTATE_D0
value|0x0000
end_define

begin_define
define|#
directive|define
name|DM_PSTATE_D1
value|0x0001
end_define

begin_define
define|#
directive|define
name|DM_PSTATE_D2
value|0x0002
end_define

begin_define
define|#
directive|define
name|DM_PSTATE_D3
value|0x0003
end_define

begin_define
define|#
directive|define
name|DM_PME_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|DM_PME_STATUS
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

