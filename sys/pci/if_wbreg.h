begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Winbond register definitions.  */
end_comment

begin_define
define|#
directive|define
name|WB_BUSCTL
value|0x00
end_define

begin_comment
comment|/* bus control */
end_comment

begin_define
define|#
directive|define
name|WB_TXSTART
value|0x04
end_define

begin_comment
comment|/* tx start demand */
end_comment

begin_define
define|#
directive|define
name|WB_RXSTART
value|0x08
end_define

begin_comment
comment|/* rx start demand */
end_comment

begin_define
define|#
directive|define
name|WB_RXADDR
value|0x0C
end_define

begin_comment
comment|/* rx descriptor list start addr */
end_comment

begin_define
define|#
directive|define
name|WB_TXADDR
value|0x10
end_define

begin_comment
comment|/* tx descriptor list start addr */
end_comment

begin_define
define|#
directive|define
name|WB_ISR
value|0x14
end_define

begin_comment
comment|/* interrupt status register */
end_comment

begin_define
define|#
directive|define
name|WB_NETCFG
value|0x18
end_define

begin_comment
comment|/* network config register */
end_comment

begin_define
define|#
directive|define
name|WB_IMR
value|0x1C
end_define

begin_comment
comment|/* interrupt mask */
end_comment

begin_define
define|#
directive|define
name|WB_FRAMESDISCARDED
value|0x20
end_define

begin_comment
comment|/* # of discarded frames */
end_comment

begin_define
define|#
directive|define
name|WB_SIO
value|0x24
end_define

begin_comment
comment|/* MII and ROM/EEPROM access */
end_comment

begin_define
define|#
directive|define
name|WB_BOOTROMADDR
value|0x28
end_define

begin_define
define|#
directive|define
name|WB_TIMER
value|0x2C
end_define

begin_comment
comment|/* general timer */
end_comment

begin_define
define|#
directive|define
name|WB_CURRXCTL
value|0x30
end_define

begin_comment
comment|/* current RX descriptor */
end_comment

begin_define
define|#
directive|define
name|WB_CURRXBUF
value|0x34
end_define

begin_comment
comment|/* current RX buffer */
end_comment

begin_define
define|#
directive|define
name|WB_MAR0
value|0x38
end_define

begin_comment
comment|/* multicast filter 0 */
end_comment

begin_define
define|#
directive|define
name|WB_MAR1
value|0x3C
end_define

begin_comment
comment|/* multicast filter 1 */
end_comment

begin_define
define|#
directive|define
name|WB_NODE0
value|0x40
end_define

begin_comment
comment|/* station address 0 */
end_comment

begin_define
define|#
directive|define
name|WB_NODE1
value|0x44
end_define

begin_comment
comment|/* station address 1 */
end_comment

begin_define
define|#
directive|define
name|WB_BOOTROMSIZE
value|0x48
end_define

begin_comment
comment|/* boot ROM size */
end_comment

begin_define
define|#
directive|define
name|WB_CURTXCTL
value|0x4C
end_define

begin_comment
comment|/* current TX descriptor */
end_comment

begin_define
define|#
directive|define
name|WB_CURTXBUF
value|0x50
end_define

begin_comment
comment|/* current TX buffer */
end_comment

begin_comment
comment|/*  * Bus control bits.  */
end_comment

begin_define
define|#
directive|define
name|WB_BUSCTL_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|WB_BUSCTL_ARBITRATION
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
name|WB_BUSCTL_BUF_BIGENDIAN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|WB_BUSCTL_BURSTLEN
value|0x00003F00
end_define

begin_define
define|#
directive|define
name|WB_BUSCTL_CACHEALIGN
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|WB_BUSCTL_DES_BIGENDIAN
value|0x00100000
end_define

begin_define
define|#
directive|define
name|WB_BUSCTL_WAIT
value|0x00200000
end_define

begin_define
define|#
directive|define
name|WB_BUSCTL_MUSTBEONE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|WB_SKIPLEN_1LONG
value|0x00000004
end_define

begin_define
define|#
directive|define
name|WB_SKIPLEN_2LONG
value|0x00000008
end_define

begin_define
define|#
directive|define
name|WB_SKIPLEN_3LONG
value|0x00000010
end_define

begin_define
define|#
directive|define
name|WB_SKIPLEN_4LONG
value|0x00000020
end_define

begin_define
define|#
directive|define
name|WB_SKIPLEN_5LONG
value|0x00000040
end_define

begin_define
define|#
directive|define
name|WB_CACHEALIGN_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|WB_CACHEALIGN_8LONG
value|0x00004000
end_define

begin_define
define|#
directive|define
name|WB_CACHEALIGN_16LONG
value|0x00008000
end_define

begin_define
define|#
directive|define
name|WB_CACHEALIGN_32LONG
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|WB_BURSTLEN_USECA
value|0x00000000
end_define

begin_define
define|#
directive|define
name|WB_BURSTLEN_1LONG
value|0x00000100
end_define

begin_define
define|#
directive|define
name|WB_BURSTLEN_2LONG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|WB_BURSTLEN_4LONG
value|0x00000400
end_define

begin_define
define|#
directive|define
name|WB_BURSTLEN_8LONG
value|0x00000800
end_define

begin_define
define|#
directive|define
name|WB_BURSTLEN_16LONG
value|0x00001000
end_define

begin_define
define|#
directive|define
name|WB_BURSTLEN_32LONG
value|0x00002000
end_define

begin_define
define|#
directive|define
name|WB_BUSCTL_CONFIG
value|(WB_CACHEALIGN_8LONG|WB_SKIPLEN_3LONG| \ 					WB_BURSTLEN_8LONG)
end_define

begin_comment
comment|/*  * Interrupt status bits.  */
end_comment

begin_define
define|#
directive|define
name|WB_ISR_TX_OK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|WB_ISR_TX_IDLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|WB_ISR_TX_NOBUF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|WB_ISR_RX_EARLY
value|0x00000008
end_define

begin_define
define|#
directive|define
name|WB_ISR_RX_ERR
value|0x00000010
end_define

begin_define
define|#
directive|define
name|WB_ISR_TX_UNDERRUN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|WB_ISR_RX_OK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|WB_ISR_RX_NOBUF
value|0x00000080
end_define

begin_define
define|#
directive|define
name|WB_ISR_RX_IDLE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|WB_ISR_TX_EARLY
value|0x00000400
end_define

begin_define
define|#
directive|define
name|WB_ISR_TIMER_EXPIRED
value|0x00000800
end_define

begin_define
define|#
directive|define
name|WB_ISR_BUS_ERR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|WB_ISR_ABNORMAL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|WB_ISR_NORMAL
value|0x00010000
end_define

begin_define
define|#
directive|define
name|WB_ISR_RX_STATE
value|0x000E0000
end_define

begin_define
define|#
directive|define
name|WB_ISR_TX_STATE
value|0x00700000
end_define

begin_define
define|#
directive|define
name|WB_ISR_BUSERRTYPE
value|0x03800000
end_define

begin_comment
comment|/*  * The RX_STATE and TX_STATE fields are not described anywhere in the  * Winbond datasheet, however it appears that the Winbond chip is an  * attempt at a DEC 'tulip' clone, hence the ISR register is identical  * to that of the tulip chip and we can steal the bit definitions from  * the tulip documentation.  */
end_comment

begin_define
define|#
directive|define
name|WB_RXSTATE_STOPPED
value|0x00000000
end_define

begin_comment
comment|/* 000 - Stopped */
end_comment

begin_define
define|#
directive|define
name|WB_RXSTATE_FETCH
value|0x00020000
end_define

begin_comment
comment|/* 001 - Fetching descriptor */
end_comment

begin_define
define|#
directive|define
name|WB_RXSTATE_ENDCHECK
value|0x00040000
end_define

begin_comment
comment|/* 010 - check for rx end */
end_comment

begin_define
define|#
directive|define
name|WB_RXSTATE_WAIT
value|0x00060000
end_define

begin_comment
comment|/* 011 - waiting for packet */
end_comment

begin_define
define|#
directive|define
name|WB_RXSTATE_SUSPEND
value|0x00080000
end_define

begin_comment
comment|/* 100 - suspend rx */
end_comment

begin_define
define|#
directive|define
name|WB_RXSTATE_CLOSE
value|0x000A0000
end_define

begin_comment
comment|/* 101 - close tx desc */
end_comment

begin_define
define|#
directive|define
name|WB_RXSTATE_FLUSH
value|0x000C0000
end_define

begin_comment
comment|/* 110 - flush from FIFO */
end_comment

begin_define
define|#
directive|define
name|WB_RXSTATE_DEQUEUE
value|0x000E0000
end_define

begin_comment
comment|/* 111 - dequeue from FIFO */
end_comment

begin_define
define|#
directive|define
name|WB_TXSTATE_RESET
value|0x00000000
end_define

begin_comment
comment|/* 000 - reset */
end_comment

begin_define
define|#
directive|define
name|WB_TXSTATE_FETCH
value|0x00100000
end_define

begin_comment
comment|/* 001 - fetching descriptor */
end_comment

begin_define
define|#
directive|define
name|WB_TXSTATE_WAITEND
value|0x00200000
end_define

begin_comment
comment|/* 010 - wait for tx end */
end_comment

begin_define
define|#
directive|define
name|WB_TXSTATE_READING
value|0x00300000
end_define

begin_comment
comment|/* 011 - read and enqueue */
end_comment

begin_define
define|#
directive|define
name|WB_TXSTATE_RSVD
value|0x00400000
end_define

begin_comment
comment|/* 100 - reserved */
end_comment

begin_define
define|#
directive|define
name|WB_TXSTATE_SETUP
value|0x00500000
end_define

begin_comment
comment|/* 101 - setup packet */
end_comment

begin_define
define|#
directive|define
name|WB_TXSTATE_SUSPEND
value|0x00600000
end_define

begin_comment
comment|/* 110 - suspend tx */
end_comment

begin_define
define|#
directive|define
name|WB_TXSTATE_CLOSE
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
name|WB_NETCFG_RX_ON
value|0x00000002
end_define

begin_define
define|#
directive|define
name|WB_NETCFG_RX_ALLPHYS
value|0x00000008
end_define

begin_define
define|#
directive|define
name|WB_NETCFG_RX_MULTI
value|0x00000010
end_define

begin_define
define|#
directive|define
name|WB_NETCFG_RX_BROAD
value|0x00000020
end_define

begin_define
define|#
directive|define
name|WB_NETCFG_RX_RUNT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|WB_NETCFG_RX_ERR
value|0x00000080
end_define

begin_define
define|#
directive|define
name|WB_NETCFG_FULLDUPLEX
value|0x00000200
end_define

begin_define
define|#
directive|define
name|WB_NETCFG_LOOPBACK
value|0x00000C00
end_define

begin_define
define|#
directive|define
name|WB_NETCFG_TX_ON
value|0x00002000
end_define

begin_define
define|#
directive|define
name|WB_NETCFG_TX_THRESH
value|0x001FC000
end_define

begin_define
define|#
directive|define
name|WB_NETCFG_RX_EARLYTHRSH
value|0x1FE00000
end_define

begin_define
define|#
directive|define
name|WB_NETCFG_100MBPS
value|0x20000000
end_define

begin_define
define|#
directive|define
name|WB_NETCFG_TX_EARLY_ON
value|0x40000000
end_define

begin_define
define|#
directive|define
name|WB_NETCFG_RX_EARLY_ON
value|0x80000000
end_define

begin_comment
comment|/*  * The tx threshold can be adjusted in increments of 32 bytes.  */
end_comment

begin_define
define|#
directive|define
name|WB_TXTHRESH
parameter_list|(
name|x
parameter_list|)
value|((x>> 5)<< 14)
end_define

begin_define
define|#
directive|define
name|WB_TXTHRESH_CHUNK
value|32
end_define

begin_define
define|#
directive|define
name|WB_TXTHRESH_INIT
value|0
end_define

begin_comment
comment|/*72*/
end_comment

begin_comment
comment|/*  * Interrupt mask bits.  */
end_comment

begin_define
define|#
directive|define
name|WB_IMR_TX_OK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|WB_IMR_TX_IDLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|WB_IMR_TX_NOBUF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|WB_IMR_RX_EARLY
value|0x00000008
end_define

begin_define
define|#
directive|define
name|WB_IMR_RX_ERR
value|0x00000010
end_define

begin_define
define|#
directive|define
name|WB_IMR_TX_UNDERRUN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|WB_IMR_RX_OK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|WB_IMR_RX_NOBUF
value|0x00000080
end_define

begin_define
define|#
directive|define
name|WB_IMR_RX_IDLE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|WB_IMR_TX_EARLY
value|0x00000400
end_define

begin_define
define|#
directive|define
name|WB_IMR_TIMER_EXPIRED
value|0x00000800
end_define

begin_define
define|#
directive|define
name|WB_IMR_BUS_ERR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|WB_IMR_ABNORMAL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|WB_IMR_NORMAL
value|0x00010000
end_define

begin_define
define|#
directive|define
name|WB_INTRS
define|\
value|(WB_IMR_RX_OK|WB_IMR_TX_OK|WB_IMR_RX_NOBUF|WB_IMR_RX_ERR|	\ 	WB_IMR_TX_NOBUF|WB_IMR_TX_UNDERRUN|WB_IMR_BUS_ERR|		\ 	WB_IMR_ABNORMAL|WB_IMR_NORMAL|WB_IMR_TX_EARLY)
end_define

begin_comment
comment|/*  * Serial I/O (EEPROM/ROM) bits.  */
end_comment

begin_define
define|#
directive|define
name|WB_SIO_EE_CS
value|0x00000001
end_define

begin_comment
comment|/* EEPROM chip select */
end_comment

begin_define
define|#
directive|define
name|WB_SIO_EE_CLK
value|0x00000002
end_define

begin_comment
comment|/* EEPROM clock */
end_comment

begin_define
define|#
directive|define
name|WB_SIO_EE_DATAIN
value|0x00000004
end_define

begin_comment
comment|/* EEPROM data output */
end_comment

begin_define
define|#
directive|define
name|WB_SIO_EE_DATAOUT
value|0x00000008
end_define

begin_comment
comment|/* EEPROM data input */
end_comment

begin_define
define|#
directive|define
name|WB_SIO_ROMDATA4
value|0x00000010
end_define

begin_define
define|#
directive|define
name|WB_SIO_ROMDATA5
value|0x00000020
end_define

begin_define
define|#
directive|define
name|WB_SIO_ROMDATA6
value|0x00000040
end_define

begin_define
define|#
directive|define
name|WB_SIO_ROMDATA7
value|0x00000080
end_define

begin_define
define|#
directive|define
name|WB_SIO_ROMCTL_WRITE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|WB_SIO_ROMCTL_READ
value|0x00000400
end_define

begin_define
define|#
directive|define
name|WB_SIO_EESEL
value|0x00000800
end_define

begin_define
define|#
directive|define
name|WB_SIO_MII_CLK
value|0x00010000
end_define

begin_comment
comment|/* MDIO clock */
end_comment

begin_define
define|#
directive|define
name|WB_SIO_MII_DATAIN
value|0x00020000
end_define

begin_comment
comment|/* MDIO data out */
end_comment

begin_define
define|#
directive|define
name|WB_SIO_MII_DIR
value|0x00040000
end_define

begin_comment
comment|/* MDIO dir */
end_comment

begin_define
define|#
directive|define
name|WB_SIO_MII_DATAOUT
value|0x00080000
end_define

begin_comment
comment|/* MDIO data in */
end_comment

begin_define
define|#
directive|define
name|WB_EECMD_WRITE
value|0x140
end_define

begin_define
define|#
directive|define
name|WB_EECMD_READ
value|0x180
end_define

begin_define
define|#
directive|define
name|WB_EECMD_ERASE
value|0x1c0
end_define

begin_comment
comment|/*  * Winbond TX/RX descriptor structure.  */
end_comment

begin_struct
struct|struct
name|wb_desc
block|{
name|u_int32_t
name|wb_status
decl_stmt|;
name|u_int32_t
name|wb_ctl
decl_stmt|;
name|u_int32_t
name|wb_ptr1
decl_stmt|;
name|u_int32_t
name|wb_ptr2
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|wb_data
value|wb_ptr1
end_define

begin_define
define|#
directive|define
name|wb_next
value|wb_ptr2
end_define

begin_define
define|#
directive|define
name|WB_RXSTAT_CRCERR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|WB_RXSTAT_DRIBBLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|WB_RXSTAT_MIIERR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|WB_RXSTAT_LATEEVENT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|WB_RXSTAT_GIANT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|WB_RXSTAT_LASTFRAG
value|0x00000100
end_define

begin_define
define|#
directive|define
name|WB_RXSTAT_FIRSTFRAG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|WB_RXSTAT_MULTICAST
value|0x00000400
end_define

begin_define
define|#
directive|define
name|WB_RXSTAT_RUNT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|WB_RXSTAT_RXTYPE
value|0x00003000
end_define

begin_define
define|#
directive|define
name|WB_RXSTAT_RXERR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|WB_RXSTAT_RXLEN
value|0x3FFF0000
end_define

begin_define
define|#
directive|define
name|WB_RXSTAT_RXCMP
value|0x40000000
end_define

begin_define
define|#
directive|define
name|WB_RXSTAT_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|WB_RXBYTES
parameter_list|(
name|x
parameter_list|)
value|((x& WB_RXSTAT_RXLEN)>> 16)
end_define

begin_define
define|#
directive|define
name|WB_RXSTAT
value|(WB_RXSTAT_FIRSTFRAG|WB_RXSTAT_LASTFRAG|WB_RXSTAT_OWN)
end_define

begin_define
define|#
directive|define
name|WB_RXCTL_BUFLEN1
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|WB_RXCTL_BUFLEN2
value|0x00FFF000
end_define

begin_define
define|#
directive|define
name|WB_RXCTL_RLINK
value|0x01000000
end_define

begin_define
define|#
directive|define
name|WB_RXCTL_RLAST
value|0x02000000
end_define

begin_define
define|#
directive|define
name|WB_TXSTAT_DEFER
value|0x00000001
end_define

begin_define
define|#
directive|define
name|WB_TXSTAT_UNDERRUN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|WB_TXSTAT_COLLCNT
value|0x00000078
end_define

begin_define
define|#
directive|define
name|WB_TXSTAT_SQE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|WB_TXSTAT_ABORT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|WB_TXSTAT_LATECOLL
value|0x00000200
end_define

begin_define
define|#
directive|define
name|WB_TXSTAT_NOCARRIER
value|0x00000400
end_define

begin_define
define|#
directive|define
name|WB_TXSTAT_CARRLOST
value|0x00000800
end_define

begin_define
define|#
directive|define
name|WB_TXSTAT_TXERR
value|0x00001000
end_define

begin_define
define|#
directive|define
name|WB_TXSTAT_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|WB_TXCTL_BUFLEN1
value|0x000007FF
end_define

begin_define
define|#
directive|define
name|WB_TXCTL_BUFLEN2
value|0x003FF800
end_define

begin_define
define|#
directive|define
name|WB_TXCTL_PAD
value|0x00800000
end_define

begin_define
define|#
directive|define
name|WB_TXCTL_TLINK
value|0x01000000
end_define

begin_define
define|#
directive|define
name|WB_TXCTL_TLAST
value|0x02000000
end_define

begin_define
define|#
directive|define
name|WB_TXCTL_NOCRC
value|0x08000000
end_define

begin_define
define|#
directive|define
name|WB_TXCTL_FIRSTFRAG
value|0x20000000
end_define

begin_define
define|#
directive|define
name|WB_TXCTL_LASTFRAG
value|0x40000000
end_define

begin_define
define|#
directive|define
name|WB_TXCTL_FINT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|WB_MAXFRAGS
value|16
end_define

begin_define
define|#
directive|define
name|WB_RX_LIST_CNT
value|64
end_define

begin_define
define|#
directive|define
name|WB_TX_LIST_CNT
value|128
end_define

begin_define
define|#
directive|define
name|WB_MIN_FRAMELEN
value|60
end_define

begin_define
define|#
directive|define
name|ETHER_ALIGN
value|2
end_define

begin_comment
comment|/*  * A transmit 'super descriptor' is actually WB_MAXFRAGS regular  * descriptors clumped together. The idea here is to emulate the  * multi-fragment descriptor layout found in devices such as the  * Texas Instruments ThunderLAN and 3Com boomerang and cylone chips.  * The advantage to using this scheme is that it avoids buffer copies.  * The disadvantage is that there's a certain amount of overhead due  * to the fact that each 'fragment' is 16 bytes long. In my tests,  * this limits top speed to about 10.5MB/sec. It should be more like  * 11.5MB/sec. However, the upshot is that you can achieve better  * results on slower machines: a Pentium 200 can pump out packets at  * same speed as a PII 400.  */
end_comment

begin_struct
struct|struct
name|wb_txdesc
block|{
name|struct
name|wb_desc
name|wb_frag
index|[
name|WB_MAXFRAGS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WB_TXNEXT
parameter_list|(
name|x
parameter_list|)
value|x->wb_ptr->wb_frag[x->wb_lastdesc].wb_next
end_define

begin_define
define|#
directive|define
name|WB_TXSTATUS
parameter_list|(
name|x
parameter_list|)
value|x->wb_ptr->wb_frag[x->wb_lastdesc].wb_status
end_define

begin_define
define|#
directive|define
name|WB_TXCTL
parameter_list|(
name|x
parameter_list|)
value|x->wb_ptr->wb_frag[x->wb_lastdesc].wb_ctl
end_define

begin_define
define|#
directive|define
name|WB_TXDATA
parameter_list|(
name|x
parameter_list|)
value|x->wb_ptr->wb_frag[x->wb_lastdesc].wb_data
end_define

begin_define
define|#
directive|define
name|WB_TXOWN
parameter_list|(
name|x
parameter_list|)
value|x->wb_ptr->wb_frag[0].wb_status
end_define

begin_define
define|#
directive|define
name|WB_UNSENT
value|0x1234
end_define

begin_define
define|#
directive|define
name|WB_BUFBYTES
value|(1024 * sizeof(u_int32_t))
end_define

begin_struct
struct|struct
name|wb_buf
block|{
name|u_int32_t
name|wb_data
index|[
literal|1024
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wb_list_data
block|{
name|struct
name|wb_buf
name|wb_rxbufs
index|[
name|WB_RX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|wb_desc
name|wb_rx_list
index|[
name|WB_RX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|wb_txdesc
name|wb_tx_list
index|[
name|WB_TX_LIST_CNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wb_chain
block|{
name|struct
name|wb_txdesc
modifier|*
name|wb_ptr
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|wb_mbuf
decl_stmt|;
name|struct
name|wb_chain
modifier|*
name|wb_nextdesc
decl_stmt|;
name|u_int8_t
name|wb_lastdesc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wb_chain_onefrag
block|{
name|struct
name|wb_desc
modifier|*
name|wb_ptr
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|wb_mbuf
decl_stmt|;
name|void
modifier|*
name|wb_buf
decl_stmt|;
name|struct
name|wb_chain_onefrag
modifier|*
name|wb_nextdesc
decl_stmt|;
name|u_int8_t
name|wb_rlast
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wb_chain_data
block|{
name|u_int8_t
name|wb_pad
index|[
name|WB_MIN_FRAMELEN
index|]
decl_stmt|;
name|struct
name|wb_chain_onefrag
name|wb_rx_chain
index|[
name|WB_RX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|wb_chain
name|wb_tx_chain
index|[
name|WB_TX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|wb_chain_onefrag
modifier|*
name|wb_rx_head
decl_stmt|;
name|struct
name|wb_chain
modifier|*
name|wb_tx_head
decl_stmt|;
name|struct
name|wb_chain
modifier|*
name|wb_tx_tail
decl_stmt|;
name|struct
name|wb_chain
modifier|*
name|wb_tx_free
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wb_type
block|{
name|u_int16_t
name|wb_vid
decl_stmt|;
name|u_int16_t
name|wb_did
decl_stmt|;
name|char
modifier|*
name|wb_name
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wb_mii_frame
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
name|WB_MII_STARTDELIM
value|0x01
end_define

begin_define
define|#
directive|define
name|WB_MII_READOP
value|0x02
end_define

begin_define
define|#
directive|define
name|WB_MII_WRITEOP
value|0x01
end_define

begin_define
define|#
directive|define
name|WB_MII_TURNAROUND
value|0x02
end_define

begin_struct
struct|struct
name|wb_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
comment|/* interface info */
name|device_t
name|wb_miibus
decl_stmt|;
name|bus_space_handle_t
name|wb_bhandle
decl_stmt|;
name|bus_space_tag_t
name|wb_btag
decl_stmt|;
name|struct
name|resource
modifier|*
name|wb_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|wb_irq
decl_stmt|;
name|void
modifier|*
name|wb_intrhand
decl_stmt|;
name|struct
name|wb_type
modifier|*
name|wb_info
decl_stmt|;
comment|/* Winbond adapter info */
name|u_int8_t
name|wb_unit
decl_stmt|;
comment|/* interface number */
name|u_int8_t
name|wb_type
decl_stmt|;
name|u_int16_t
name|wb_txthresh
decl_stmt|;
name|int
name|wb_cachesize
decl_stmt|;
name|caddr_t
name|wb_ldata_ptr
decl_stmt|;
name|struct
name|wb_list_data
modifier|*
name|wb_ldata
decl_stmt|;
name|struct
name|wb_chain_data
name|wb_cdata
decl_stmt|;
name|struct
name|callout_handle
name|wb_stat_ch
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
value|bus_space_write_4(sc->wb_btag, sc->wb_bhandle, reg, val)
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
value|bus_space_write_2(sc->wb_btag, sc->wb_bhandle, reg, val)
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
value|bus_space_write_1(sc->wb_btag, sc->wb_bhandle, reg, val)
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
value|bus_space_read_4(sc->wb_btag, sc->wb_bhandle, reg)
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
value|bus_space_read_2(sc->wb_btag, sc->wb_bhandle, reg)
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
value|bus_space_read_1(sc->wb_btag, sc->wb_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|WB_TIMEOUT
value|1000
end_define

begin_comment
comment|/*  * General constants that are fun to know.  *  * Winbond PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|WB_VENDORID
value|0x1050
end_define

begin_comment
comment|/*  * Winbond device IDs.  */
end_comment

begin_define
define|#
directive|define
name|WB_DEVICEID_840F
value|0x0840
end_define

begin_comment
comment|/*  * Compex vendor ID.  */
end_comment

begin_define
define|#
directive|define
name|CP_VENDORID
value|0x11F6
end_define

begin_comment
comment|/*  * Compex device IDs.  */
end_comment

begin_define
define|#
directive|define
name|CP_DEVICEID_RL100
value|0x2011
end_define

begin_comment
comment|/*  * PCI low memory base and low I/O base register, and  * other PCI registers.  */
end_comment

begin_define
define|#
directive|define
name|WB_PCI_VENDOR_ID
value|0x00
end_define

begin_define
define|#
directive|define
name|WB_PCI_DEVICE_ID
value|0x02
end_define

begin_define
define|#
directive|define
name|WB_PCI_COMMAND
value|0x04
end_define

begin_define
define|#
directive|define
name|WB_PCI_STATUS
value|0x06
end_define

begin_define
define|#
directive|define
name|WB_PCI_CLASSCODE
value|0x09
end_define

begin_define
define|#
directive|define
name|WB_PCI_CACHELEN
value|0x0C
end_define

begin_define
define|#
directive|define
name|WB_PCI_LATENCY_TIMER
value|0x0D
end_define

begin_define
define|#
directive|define
name|WB_PCI_HEADER_TYPE
value|0x0E
end_define

begin_define
define|#
directive|define
name|WB_PCI_LOIO
value|0x10
end_define

begin_define
define|#
directive|define
name|WB_PCI_LOMEM
value|0x14
end_define

begin_define
define|#
directive|define
name|WB_PCI_BIOSROM
value|0x30
end_define

begin_define
define|#
directive|define
name|WB_PCI_INTLINE
value|0x3C
end_define

begin_define
define|#
directive|define
name|WB_PCI_INTPIN
value|0x3D
end_define

begin_define
define|#
directive|define
name|WB_PCI_MINGNT
value|0x3E
end_define

begin_define
define|#
directive|define
name|WB_PCI_MINLAT
value|0x0F
end_define

begin_define
define|#
directive|define
name|WB_PCI_RESETOPT
value|0x48
end_define

begin_define
define|#
directive|define
name|WB_PCI_EEPROM_DATA
value|0x4C
end_define

begin_comment
comment|/* power management registers */
end_comment

begin_define
define|#
directive|define
name|WB_PCI_CAPID
value|0xDC
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|WB_PCI_NEXTPTR
value|0xDD
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|WB_PCI_PWRMGMTCAP
value|0xDE
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|WB_PCI_PWRMGMTCTRL
value|0xE0
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|WB_PSTATE_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|WB_PSTATE_D0
value|0x0000
end_define

begin_define
define|#
directive|define
name|WB_PSTATE_D1
value|0x0002
end_define

begin_define
define|#
directive|define
name|WB_PSTATE_D2
value|0x0002
end_define

begin_define
define|#
directive|define
name|WB_PSTATE_D3
value|0x0003
end_define

begin_define
define|#
directive|define
name|WB_PME_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|WB_PME_STATUS
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

