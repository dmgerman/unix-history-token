begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998, 1999  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * COMET register definitions.  */
end_comment

begin_define
define|#
directive|define
name|AL_BUSCTL
value|0x00
end_define

begin_comment
comment|/* bus control */
end_comment

begin_define
define|#
directive|define
name|AL_TXSTART
value|0x08
end_define

begin_comment
comment|/* tx start demand */
end_comment

begin_define
define|#
directive|define
name|AL_RXSTART
value|0x10
end_define

begin_comment
comment|/* rx start demand */
end_comment

begin_define
define|#
directive|define
name|AL_RXADDR
value|0x18
end_define

begin_comment
comment|/* rx descriptor list start addr */
end_comment

begin_define
define|#
directive|define
name|AL_TXADDR
value|0x20
end_define

begin_comment
comment|/* tx descriptor list start addr */
end_comment

begin_define
define|#
directive|define
name|AL_ISR
value|0x28
end_define

begin_comment
comment|/* interrupt status register */
end_comment

begin_define
define|#
directive|define
name|AL_NETCFG
value|0x30
end_define

begin_comment
comment|/* network config register */
end_comment

begin_define
define|#
directive|define
name|AL_IMR
value|0x38
end_define

begin_comment
comment|/* interrupt mask */
end_comment

begin_define
define|#
directive|define
name|AL_FRAMESDISCARDED
value|0x40
end_define

begin_comment
comment|/* # of discarded frames */
end_comment

begin_define
define|#
directive|define
name|AL_SIO
value|0x48
end_define

begin_comment
comment|/* MII and ROM/EEPROM access */
end_comment

begin_define
define|#
directive|define
name|AL_RESERVED
value|0x50
end_define

begin_define
define|#
directive|define
name|AL_GENTIMER
value|0x58
end_define

begin_comment
comment|/* general timer */
end_comment

begin_define
define|#
directive|define
name|AL_GENPORT
value|0x60
end_define

begin_comment
comment|/* general purpose port */
end_comment

begin_define
define|#
directive|define
name|AL_WAKEUP_CTL
value|0x68
end_define

begin_comment
comment|/* wake-up control/status register */
end_comment

begin_define
define|#
directive|define
name|AL_WAKEUP_PAT
value|0x70
end_define

begin_comment
comment|/* wake-up pattern data register */
end_comment

begin_define
define|#
directive|define
name|AL_WATCHDOG
value|0x78
end_define

begin_comment
comment|/* watchdog timer */
end_comment

begin_define
define|#
directive|define
name|AL_ISR2
value|0x80
end_define

begin_comment
comment|/* ISR assist register */
end_comment

begin_define
define|#
directive|define
name|AL_IMR2
value|0x84
end_define

begin_comment
comment|/* IRM assist register */
end_comment

begin_define
define|#
directive|define
name|AL_COMMAND
value|0x88
end_define

begin_comment
comment|/* command register */
end_comment

begin_define
define|#
directive|define
name|AL_PCIPERF
value|0x8C
end_define

begin_comment
comment|/* pci perf counter */
end_comment

begin_define
define|#
directive|define
name|AL_PWRMGMT
value|0x90
end_define

begin_comment
comment|/* pwr management command/status */
end_comment

begin_define
define|#
directive|define
name|AL_TXBURST
value|0x9C
end_define

begin_comment
comment|/* tx burst counter/timeout */
end_comment

begin_define
define|#
directive|define
name|AL_FLASHPROM
value|0xA0
end_define

begin_comment
comment|/* flash(boot) PROM port */
end_comment

begin_define
define|#
directive|define
name|AL_PAR0
value|0xA4
end_define

begin_comment
comment|/* station address */
end_comment

begin_define
define|#
directive|define
name|AL_PAR1
value|0xA8
end_define

begin_comment
comment|/* station address */
end_comment

begin_define
define|#
directive|define
name|AL_MAR0
value|0xAC
end_define

begin_comment
comment|/* multicast hash filter */
end_comment

begin_define
define|#
directive|define
name|AL_MAR1
value|0xB0
end_define

begin_comment
comment|/* multicast hash filter */
end_comment

begin_define
define|#
directive|define
name|AL_BMCR
value|0xB4
end_define

begin_comment
comment|/* built in PHY control */
end_comment

begin_define
define|#
directive|define
name|AL_BMSR
value|0xB8
end_define

begin_comment
comment|/* built in PHY status */
end_comment

begin_define
define|#
directive|define
name|AL_VENID
value|0xBC
end_define

begin_comment
comment|/* built in PHY ID0 */
end_comment

begin_define
define|#
directive|define
name|AL_DEVID
value|0xC0
end_define

begin_comment
comment|/* built in PHY ID1 */
end_comment

begin_define
define|#
directive|define
name|AL_ANAR
value|0xC4
end_define

begin_comment
comment|/* built in PHY autoneg advert */
end_comment

begin_define
define|#
directive|define
name|AL_LPAR
value|0xC8
end_define

begin_comment
comment|/* bnilt in PHY link part. ability */
end_comment

begin_define
define|#
directive|define
name|AL_ANER
value|0xCC
end_define

begin_comment
comment|/* built in PHY autoneg expansion */
end_comment

begin_define
define|#
directive|define
name|AL_PHY_MODECTL
value|0xD0
end_define

begin_comment
comment|/* mode control */
end_comment

begin_define
define|#
directive|define
name|AL_PHY_CONFIG
value|0xD4
end_define

begin_comment
comment|/* config info and inter status */
end_comment

begin_define
define|#
directive|define
name|AL_PHY_INTEN
value|0xD8
end_define

begin_comment
comment|/* interrupto enable */
end_comment

begin_define
define|#
directive|define
name|AL_PHY_MODECTL_100TX
value|0xDC
end_define

begin_comment
comment|/* 100baseTX control/status */
end_comment

begin_comment
comment|/*  * Bus control bits.  */
end_comment

begin_define
define|#
directive|define
name|AL_BUSCTL_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AL_BUSCTL_ARBITRATION
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AL_BUSCTL_SKIPLEN
value|0x0000007C
end_define

begin_define
define|#
directive|define
name|AL_BUSCTL_BIGENDIAN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AL_BUSCTL_BURSTLEN
value|0x00003F00
end_define

begin_define
define|#
directive|define
name|AL_BUSCTL_CACHEALIGN
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|AL_BUSCTL_XMITPOLL
value|0x00060000
end_define

begin_define
define|#
directive|define
name|AL_BUSCTL_BUF_BIGENDIAN
value|0x00100000
end_define

begin_define
define|#
directive|define
name|AL_BUSCTL_READMULTI
value|0x00200000
end_define

begin_define
define|#
directive|define
name|AL_BUSCTL_READLINE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AL_BUSCTL_WRITEINVAL
value|0x01000000
end_define

begin_define
define|#
directive|define
name|AL_SKIPLEN_1LONG
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AL_SKIPLEN_2LONG
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AL_SKIPLEN_3LONG
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AL_SKIPLEN_4LONG
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AL_SKIPLEN_5LONG
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AL_BURSTLEN_UNLIMIT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|AL_BURSTLEN_1LONG
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AL_BURSTLEN_2LONG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|AL_BURSTLEN_4LONG
value|0x00000400
end_define

begin_define
define|#
directive|define
name|AL_BURSTLEN_8LONG
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AL_BURSTLEN_16LONG
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AL_BURSTLEN_32LONG
value|0x00002000
end_define

begin_define
define|#
directive|define
name|AL_CACHEALIGN_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|AL_CACHEALIGN_8LONG
value|0x00004000
end_define

begin_define
define|#
directive|define
name|AL_CACHEALIGN_16LONG
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AL_CACHEALIGN_32LONG
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|AL_TXPOLL_OFF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|AL_TXPOLL_200U
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AX_TXPOLL_800U
value|0x00040000
end_define

begin_define
define|#
directive|define
name|AL_TXPOLL_1600U
value|0x00060000
end_define

begin_comment
comment|/*  * Interrupt status bits.  */
end_comment

begin_define
define|#
directive|define
name|AL_ISR_TX_OK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AL_ISR_TX_IDLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AL_ISR_TX_NOBUF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AL_ISR_TX_JABBERTIMEO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AL_ISR_TX_UNDERRUN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AL_ISR_RX_OK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AL_ISR_RX_NOBUF
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AL_ISR_RX_IDLE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AL_ISR_RX_WATDOGTIMEO
value|0x00000200
end_define

begin_define
define|#
directive|define
name|AL_ISR_TIMER_EXPIRED
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AL_ISR_BUS_ERR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|AL_ISR_ABNORMAL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AL_ISR_NORMAL
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AL_ISR_RX_STATE
value|0x000E0000
end_define

begin_define
define|#
directive|define
name|AL_ISR_TX_STATE
value|0x00700000
end_define

begin_define
define|#
directive|define
name|AL_ISR_BUSERRTYPE
value|0x03800000
end_define

begin_define
define|#
directive|define
name|AL_RXSTATE_STOPPED
value|0x00000000
end_define

begin_comment
comment|/* 000 - Stopped */
end_comment

begin_define
define|#
directive|define
name|AL_RXSTATE_FETCH
value|0x00020000
end_define

begin_comment
comment|/* 001 - Fetching descriptor */
end_comment

begin_define
define|#
directive|define
name|AL_RXSTATE_ENDCHECK
value|0x00040000
end_define

begin_comment
comment|/* 010 - check for rx end */
end_comment

begin_define
define|#
directive|define
name|AL_RXSTATE_WAIT
value|0x00060000
end_define

begin_comment
comment|/* 011 - waiting for packet */
end_comment

begin_define
define|#
directive|define
name|AL_RXSTATE_SUSPEND
value|0x00080000
end_define

begin_comment
comment|/* 100 - suspend rx */
end_comment

begin_define
define|#
directive|define
name|AL_RXSTATE_CLOSE
value|0x000A0000
end_define

begin_comment
comment|/* 101 - close tx desc */
end_comment

begin_define
define|#
directive|define
name|AL_RXSTATE_FLUSH
value|0x000C0000
end_define

begin_comment
comment|/* 110 - flush from FIFO */
end_comment

begin_define
define|#
directive|define
name|AL_RXSTATE_DEQUEUE
value|0x000E0000
end_define

begin_comment
comment|/* 111 - dequeue from FIFO */
end_comment

begin_define
define|#
directive|define
name|AL_TXSTATE_RESET
value|0x00000000
end_define

begin_comment
comment|/* 000 - reset */
end_comment

begin_define
define|#
directive|define
name|AL_TXSTATE_FETCH
value|0x00100000
end_define

begin_comment
comment|/* 001 - fetching descriptor */
end_comment

begin_define
define|#
directive|define
name|AL_TXSTATE_WAITEND
value|0x00200000
end_define

begin_comment
comment|/* 010 - wait for tx end */
end_comment

begin_define
define|#
directive|define
name|AL_TXSTATE_READING
value|0x00300000
end_define

begin_comment
comment|/* 011 - read and enqueue */
end_comment

begin_define
define|#
directive|define
name|AL_TXSTATE_RSVD
value|0x00400000
end_define

begin_comment
comment|/* 100 - reserved */
end_comment

begin_define
define|#
directive|define
name|AL_TXSTATE_SETUP
value|0x00500000
end_define

begin_comment
comment|/* 101 - setup packet */
end_comment

begin_define
define|#
directive|define
name|AL_TXSTATE_SUSPEND
value|0x00600000
end_define

begin_comment
comment|/* 110 - suspend tx */
end_comment

begin_define
define|#
directive|define
name|AL_TXSTATE_CLOSE
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
name|AL_NETCFG_RX_ON
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AL_NETCFG_RX_BADFRAMES
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AL_NETCFG_RX_BACKOFF
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AL_NETCFG_RX_PROMISC
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AL_NETCFG_RX_ALLMULTI
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AL_NETCFG_OPMODE
value|0x00000C00
end_define

begin_define
define|#
directive|define
name|AL_NETCFG_FORCECOLL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AL_NETCFG_TX_ON
value|0x00002000
end_define

begin_define
define|#
directive|define
name|AL_NETCFG_TX_THRESH
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|AL_NETCFG_HEARTBEAT
value|0x00080000
end_define

begin_comment
comment|/* 0 == ON, 1 == OFF */
end_comment

begin_define
define|#
directive|define
name|AL_NETCFG_STORENFWD
value|0x00200000
end_define

begin_define
define|#
directive|define
name|AL_OPMODE_NORM
value|0x00000000
end_define

begin_define
define|#
directive|define
name|AL_OPMODE_INTLOOP
value|0x00000400
end_define

begin_define
define|#
directive|define
name|AL_OPMODE_EXTLOOP
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AL_TXTHRESH_72BYTES
value|0x00000000
end_define

begin_define
define|#
directive|define
name|AL_TXTHRESH_96BYTES
value|0x00004000
end_define

begin_define
define|#
directive|define
name|AL_TXTHRESH_128BYTES
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AL_TXTHRESH_160BYTES
value|0x0000C000
end_define

begin_comment
comment|/*  * Interrupt mask bits.  */
end_comment

begin_define
define|#
directive|define
name|AL_IMR_TX_OK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AL_IMR_TX_IDLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AL_IMR_TX_NOBUF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AL_IMR_TX_JABBERTIMEO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AL_IMR_TX_UNDERRUN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AL_IMR_RX_OK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AL_IMR_RX_NOBUF
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AL_IMR_RX_IDLE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AL_IMR_RX_WATDOGTIMEO
value|0x00000200
end_define

begin_define
define|#
directive|define
name|AL_IMR_TIMER_EXPIRED
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AL_IMR_BUS_ERR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|AL_IMR_ABNORMAL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AL_IMR_NORMAL
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AL_INTRS
define|\
value|(AL_IMR_RX_OK|AL_IMR_TX_OK|AL_IMR_RX_NOBUF|AL_IMR_RX_WATDOGTIMEO|\ 	AL_IMR_TX_NOBUF|AL_IMR_TX_UNDERRUN|AL_IMR_BUS_ERR|		\ 	AL_IMR_ABNORMAL|AL_IMR_NORMAL|AL_IMR_TX_IDLE|AL_IMR_RX_IDLE)
end_define

begin_comment
comment|/*  * Missed packer register.  */
end_comment

begin_define
define|#
directive|define
name|AL_MISSEDPKT_CNT
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|AL_MISSEDPKT_OFLOW
value|0x00010000
end_define

begin_comment
comment|/*  * Serial I/O (EEPROM/ROM) bits.  */
end_comment

begin_define
define|#
directive|define
name|AL_SIO_EE_CS
value|0x00000001
end_define

begin_comment
comment|/* EEPROM chip select */
end_comment

begin_define
define|#
directive|define
name|AL_SIO_EE_CLK
value|0x00000002
end_define

begin_comment
comment|/* EEPROM clock */
end_comment

begin_define
define|#
directive|define
name|AL_SIO_EE_DATAIN
value|0x00000004
end_define

begin_comment
comment|/* EEPROM data output */
end_comment

begin_define
define|#
directive|define
name|AL_SIO_EE_DATAOUT
value|0x00000008
end_define

begin_comment
comment|/* EEPROM data input */
end_comment

begin_define
define|#
directive|define
name|AL_SIO_EESEL
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AL_SIO_ROMCTL_WRITE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|AL_SIO_ROMCTL_READ
value|0x00004000
end_define

begin_define
define|#
directive|define
name|AL_SIO_MII_CLK
value|0x00010000
end_define

begin_comment
comment|/* MDIO clock */
end_comment

begin_define
define|#
directive|define
name|AL_SIO_MII_DATAOUT
value|0x00020000
end_define

begin_comment
comment|/* MDIO data out */
end_comment

begin_define
define|#
directive|define
name|AL_SIO_MII_DIR
value|0x00040000
end_define

begin_comment
comment|/* MDIO dir */
end_comment

begin_define
define|#
directive|define
name|AL_SIO_MII_DATAIN
value|0x00080000
end_define

begin_comment
comment|/* MDIO data in */
end_comment

begin_define
define|#
directive|define
name|AL_EECMD_WRITE
value|0x140
end_define

begin_define
define|#
directive|define
name|AL_EECMD_READ
value|0x180
end_define

begin_define
define|#
directive|define
name|AL_EECMD_ERASE
value|0x1c0
end_define

begin_define
define|#
directive|define
name|AL_EE_NODEADDR_OFFSET
value|0x70
end_define

begin_define
define|#
directive|define
name|AL_EE_NODEADDR
value|4
end_define

begin_comment
comment|/*  * General purpose timer register  */
end_comment

begin_define
define|#
directive|define
name|AL_TIMER_VALUE
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|AL_TIMER_CONTINUOUS
value|0x00010000
end_define

begin_comment
comment|/*  * Wakeup control/status register.  */
end_comment

begin_define
define|#
directive|define
name|AL_WU_LINKSTS
value|0x00000001
end_define

begin_comment
comment|/* link status changed */
end_comment

begin_define
define|#
directive|define
name|AL_WU_MAGICPKT
value|0x00000002
end_define

begin_comment
comment|/* magic packet received */
end_comment

begin_define
define|#
directive|define
name|AL_WU_WUPKT
value|0x00000004
end_define

begin_comment
comment|/* wake up pkt received */
end_comment

begin_define
define|#
directive|define
name|AL_WU_LINKSTS_ENB
value|0x00000100
end_define

begin_comment
comment|/* enable linksts event */
end_comment

begin_define
define|#
directive|define
name|AL_WU_MAGICPKT_ENB
value|0x00000200
end_define

begin_comment
comment|/* enable magicpkt event */
end_comment

begin_define
define|#
directive|define
name|AL_WU_WUPKT_ENB
value|0x00000400
end_define

begin_comment
comment|/* enable wakeup pkt event */
end_comment

begin_define
define|#
directive|define
name|AL_WU_LINKON_ENB
value|0x00010000
end_define

begin_comment
comment|/* enable link on detect  */
end_comment

begin_define
define|#
directive|define
name|AL_WU_LINKOFF_ENB
value|0x00020000
end_define

begin_comment
comment|/* enable link off detect */
end_comment

begin_define
define|#
directive|define
name|AL_WU_WKUPMATCH_PAT5
value|0x02000000
end_define

begin_comment
comment|/* enable wkup pat 5 match */
end_comment

begin_define
define|#
directive|define
name|AL_WU_WKUPMATCH_PAT4
value|0x04000000
end_define

begin_comment
comment|/* enable wkup pat 4 match */
end_comment

begin_define
define|#
directive|define
name|AL_WU_WKUPMATCH_PAT3
value|0x08000000
end_define

begin_comment
comment|/* enable wkup pat 3 match */
end_comment

begin_define
define|#
directive|define
name|AL_WU_WKUPMATCH_PAT2
value|0x10000000
end_define

begin_comment
comment|/* enable wkup pat 2 match */
end_comment

begin_define
define|#
directive|define
name|AL_WU_WKUPMATCH_PAT1
value|0x20000000
end_define

begin_comment
comment|/* enable wkup pat 1 match */
end_comment

begin_define
define|#
directive|define
name|AL_WU_CRCTYPE
value|0x40000000
end_define

begin_comment
comment|/* crc: 0=0000, 1=ffff */
end_comment

begin_comment
comment|/*  * Wakeup pattern structure.  */
end_comment

begin_struct
struct|struct
name|al_wu_pattern
block|{
name|u_int32_t
name|al_wu_bits
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_wakeup
block|{
name|struct
name|al_wu_pattern
name|al_wu_pat
decl_stmt|;
name|u_int16_t
name|al_wu_crc1
decl_stmt|;
name|u_int16_t
name|al_wu_offset1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_wakup_record
block|{
name|struct
name|al_wakeup
name|al_wakeup
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Watchdog timer register.  */
end_comment

begin_define
define|#
directive|define
name|AL_WDOG_JABDISABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AL_WDOG_NONJABBER
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AL_WDOG_JABCLK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AL_WDOG_RXWDOG_DIS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AL_WDOG_RXWDOG_REL
value|0x00000020
end_define

begin_comment
comment|/*  * Assistant status register.  */
end_comment

begin_define
define|#
directive|define
name|AL_ISR2_ABNORMAL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AL_ISR2_NORMAL
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AL_ISR2_RX_STATE
value|0x000E0000
end_define

begin_define
define|#
directive|define
name|AL_ISR2_TX_STATE
value|0x00700000
end_define

begin_define
define|#
directive|define
name|AL_ISR2_BUSERRTYPE
value|0x03800000
end_define

begin_define
define|#
directive|define
name|AL_ISR2_PAUSE
value|0x04000000
end_define

begin_comment
comment|/* PAUSE frame received */
end_comment

begin_define
define|#
directive|define
name|AL_ISR2_TX_DEFER
value|0x10000000
end_define

begin_define
define|#
directive|define
name|AL_ISR2_XCVR_INT
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AL_ISR2_RX_EARLY
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AL_ISR2_TX_EARLY
value|0x80000000
end_define

begin_comment
comment|/*  * Assistant mask register.  */
end_comment

begin_define
define|#
directive|define
name|AL_IMR2_ABNORMAL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AL_IMR2_NORMAL
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AL_IMR2_PAUSE
value|0x04000000
end_define

begin_comment
comment|/* PAUSE frame received */
end_comment

begin_define
define|#
directive|define
name|AL_IMR2_TX_DEFER
value|0x10000000
end_define

begin_define
define|#
directive|define
name|AL_IMR2_XCVR_INT
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AL_IMR2_RX_EARLY
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AL_IMR2_TX_EARLY
value|0x80000000
end_define

begin_comment
comment|/*  * Command register, some bits loaded from EEPROM.  */
end_comment

begin_define
define|#
directive|define
name|AL_CMD_TXURUN_REC
value|0x00000001
end_define

begin_comment
comment|/* enable TX underflow recovery */
end_comment

begin_define
define|#
directive|define
name|AL_CMD_SOFTWARE_INT
value|0x00000002
end_define

begin_comment
comment|/* software interrupt */
end_comment

begin_define
define|#
directive|define
name|AL_CMD_DRT
value|0x0000000C
end_define

begin_comment
comment|/* drain receive threshold */
end_comment

begin_define
define|#
directive|define
name|AL_CMD_RXTHRESH_ENB
value|0x00000010
end_define

begin_comment
comment|/* rx threshold enable */
end_comment

begin_define
define|#
directive|define
name|AL_CMD_PAUSE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AL_CMD_RST_WU_PTR
value|0x00000040
end_define

begin_comment
comment|/* reset wakeup pattern reg. */
end_comment

begin_comment
comment|/* Values below loaded from EEPROM. */
end_comment

begin_define
define|#
directive|define
name|AL_CMD_WOL_ENB
value|0x00040000
end_define

begin_comment
comment|/* WOL enable */
end_comment

begin_define
define|#
directive|define
name|AL_CMD_PM_ENB
value|0x00080000
end_define

begin_comment
comment|/* pwr mgmt enable */
end_comment

begin_define
define|#
directive|define
name|AL_CMD_RX_FIFO
value|0x00300000
end_define

begin_define
define|#
directive|define
name|AL_CMD_LED_MODE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|AL_CMD_CURRENT_MODE
value|0x70000000
end_define

begin_define
define|#
directive|define
name|AL_CMD_D3COLD
value|0x80000000
end_define

begin_comment
comment|/*  * PCI performance counter.  */
end_comment

begin_define
define|#
directive|define
name|AL_PCI_DW_CNT
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|AL_PCI_CLK
value|0xFFFF0000
end_define

begin_comment
comment|/*  * Power management command and status.  */
end_comment

begin_define
define|#
directive|define
name|AL_PWRM_PWR_STATE
value|0x00000003
end_define

begin_define
define|#
directive|define
name|AL_PWRM_PME_EN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AL_PWRM_DSEL
value|0x00001E00
end_define

begin_define
define|#
directive|define
name|AL_PWRM_DSCALE
value|0x00006000
end_define

begin_define
define|#
directive|define
name|AL_PWRM_PME_STAT
value|0x00008000
end_define

begin_comment
comment|/*  * TX burst count / timeout register.  */
end_comment

begin_define
define|#
directive|define
name|AL_TXB_TIMEO
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|AL_TXB_BURSTCNT
value|0x0000F000
end_define

begin_comment
comment|/*  * Flash PROM register.  */
end_comment

begin_define
define|#
directive|define
name|AL_PROM_DATA
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|AL_PROM_ADDR
value|0x01FFFFF0
end_define

begin_define
define|#
directive|define
name|AL_PROM_WR_ENB
value|0x04000000
end_define

begin_define
define|#
directive|define
name|AL_PROM_BRA16_ON
value|0x80000000
end_define

begin_comment
comment|/*  * COMET TX/RX list structure.  */
end_comment

begin_struct
struct|struct
name|al_desc
block|{
specifier|volatile
name|u_int32_t
name|al_status
decl_stmt|;
specifier|volatile
name|u_int32_t
name|al_ctl
decl_stmt|;
specifier|volatile
name|u_int32_t
name|al_ptr1
decl_stmt|;
specifier|volatile
name|u_int32_t
name|al_ptr2
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|al_data
value|al_ptr1
end_define

begin_define
define|#
directive|define
name|al_next
value|al_ptr2
end_define

begin_define
define|#
directive|define
name|AL_RXSTAT_FIFOOFLOW
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AL_RXSTAT_CRCERR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AL_RXSTAT_DRIBBLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AL_RXSTAT_WATCHDOG
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AL_RXSTAT_FRAMETYPE
value|0x00000020
end_define

begin_comment
comment|/* 0 == IEEE 802.3 */
end_comment

begin_define
define|#
directive|define
name|AL_RXSTAT_COLLSEEN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AL_RXSTAT_GIANT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AL_RXSTAT_LASTFRAG
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AL_RXSTAT_FIRSTFRAG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|AL_RXSTAT_MULTICAST
value|0x00000400
end_define

begin_define
define|#
directive|define
name|AL_RXSTAT_RUNT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AL_RXSTAT_RXTYPE
value|0x00003000
end_define

begin_define
define|#
directive|define
name|AL_RXSTAT_RXERR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AL_RXSTAT_RXLEN
value|0x3FFF0000
end_define

begin_define
define|#
directive|define
name|AL_RXSTAT_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AL_RXBYTES
parameter_list|(
name|x
parameter_list|)
value|((x& AL_RXSTAT_RXLEN)>> 16)
end_define

begin_define
define|#
directive|define
name|AL_RXSTAT
value|(AL_RXSTAT_FIRSTFRAG|AL_RXSTAT_LASTFRAG|AL_RXSTAT_OWN)
end_define

begin_define
define|#
directive|define
name|AL_RXCTL_BUFLEN1
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|AL_RXCTL_BUFLEN2
value|0x00FFF000
end_define

begin_define
define|#
directive|define
name|AL_RXCTL_RLAST
value|0x02000000
end_define

begin_define
define|#
directive|define
name|AL_TXSTAT_DEFER
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AL_TXSTAT_UNDERRUN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AL_TXSTAT_LINKFAIL
value|0x00000003
end_define

begin_define
define|#
directive|define
name|AL_TXSTAT_COLLCNT
value|0x00000078
end_define

begin_define
define|#
directive|define
name|AL_TXSTAT_SQE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AL_TXSTAT_EXCESSCOLL
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AL_TXSTAT_LATECOLL
value|0x00000200
end_define

begin_define
define|#
directive|define
name|AL_TXSTAT_NOCARRIER
value|0x00000400
end_define

begin_define
define|#
directive|define
name|AL_TXSTAT_CARRLOST
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AL_TXSTAT_JABTIMEO
value|0x00004000
end_define

begin_define
define|#
directive|define
name|AL_TXSTAT_ERRSUM
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AL_TXSTAT_OWN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AL_TXCTL_BUFLEN1
value|0x000007FF
end_define

begin_define
define|#
directive|define
name|AL_TXCTL_BUFLEN2
value|0x003FF800
end_define

begin_define
define|#
directive|define
name|AL_TXCTL_PAD
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AL_TXCTL_TLINK
value|0x01000000
end_define

begin_define
define|#
directive|define
name|AL_TXCTL_TLAST
value|0x02000000
end_define

begin_define
define|#
directive|define
name|AL_TXCTL_NOCRC
value|0x04000000
end_define

begin_define
define|#
directive|define
name|AL_TXCTL_FIRSTFRAG
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AL_TXCTL_LASTFRAG
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AL_TXCTL_FINT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AL_MAXFRAGS
value|16
end_define

begin_define
define|#
directive|define
name|AL_RX_LIST_CNT
value|64
end_define

begin_define
define|#
directive|define
name|AL_TX_LIST_CNT
value|128
end_define

begin_define
define|#
directive|define
name|AL_MIN_FRAMELEN
value|60
end_define

begin_comment
comment|/*  * A tx 'super descriptor' is actually 16 regular descriptors  * back to back.  */
end_comment

begin_struct
struct|struct
name|al_txdesc
block|{
specifier|volatile
name|struct
name|al_desc
name|al_frag
index|[
name|AL_MAXFRAGS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AL_TXNEXT
parameter_list|(
name|x
parameter_list|)
value|x->al_ptr->al_frag[x->al_lastdesc].al_next
end_define

begin_define
define|#
directive|define
name|AL_TXSTATUS
parameter_list|(
name|x
parameter_list|)
value|x->al_ptr->al_frag[x->al_lastdesc].al_status
end_define

begin_define
define|#
directive|define
name|AL_TXCTL
parameter_list|(
name|x
parameter_list|)
value|x->al_ptr->al_frag[x->al_lastdesc].al_ctl
end_define

begin_define
define|#
directive|define
name|AL_TXDATA
parameter_list|(
name|x
parameter_list|)
value|x->al_ptr->al_frag[x->al_lastdesc].al_data
end_define

begin_define
define|#
directive|define
name|AL_TXOWN
parameter_list|(
name|x
parameter_list|)
value|x->al_ptr->al_frag[0].al_status
end_define

begin_define
define|#
directive|define
name|AL_UNSENT
value|0x12341234
end_define

begin_struct
struct|struct
name|al_list_data
block|{
specifier|volatile
name|struct
name|al_desc
name|al_rx_list
index|[
name|AL_RX_LIST_CNT
index|]
decl_stmt|;
specifier|volatile
name|struct
name|al_txdesc
name|al_tx_list
index|[
name|AL_TX_LIST_CNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_chain
block|{
specifier|volatile
name|struct
name|al_txdesc
modifier|*
name|al_ptr
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|al_mbuf
decl_stmt|;
name|struct
name|al_chain
modifier|*
name|al_nextdesc
decl_stmt|;
name|u_int8_t
name|al_lastdesc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_chain_onefrag
block|{
specifier|volatile
name|struct
name|al_desc
modifier|*
name|al_ptr
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|al_mbuf
decl_stmt|;
name|struct
name|al_chain_onefrag
modifier|*
name|al_nextdesc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_chain_data
block|{
name|struct
name|al_chain_onefrag
name|al_rx_chain
index|[
name|AL_RX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|al_chain
name|al_tx_chain
index|[
name|AL_TX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|al_chain_onefrag
modifier|*
name|al_rx_head
decl_stmt|;
name|struct
name|al_chain
modifier|*
name|al_tx_head
decl_stmt|;
name|struct
name|al_chain
modifier|*
name|al_tx_tail
decl_stmt|;
name|struct
name|al_chain
modifier|*
name|al_tx_free
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_type
block|{
name|u_int16_t
name|al_vid
decl_stmt|;
name|u_int16_t
name|al_did
decl_stmt|;
name|char
modifier|*
name|al_name
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_mii_frame
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
name|AL_MII_STARTDELIM
value|0x01
end_define

begin_define
define|#
directive|define
name|AL_MII_READOP
value|0x02
end_define

begin_define
define|#
directive|define
name|AL_MII_WRITEOP
value|0x01
end_define

begin_define
define|#
directive|define
name|AL_MII_TURNAROUND
value|0x02
end_define

begin_define
define|#
directive|define
name|AL_FLAG_FORCEDELAY
value|1
end_define

begin_define
define|#
directive|define
name|AL_FLAG_SCHEDDELAY
value|2
end_define

begin_define
define|#
directive|define
name|AL_FLAG_DELAYTIMEO
value|3
end_define

begin_struct
struct|struct
name|al_softc
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
name|al_bhandle
decl_stmt|;
comment|/* bus space handle */
name|bus_space_tag_t
name|al_btag
decl_stmt|;
comment|/* bus space tag */
name|struct
name|al_type
modifier|*
name|al_info
decl_stmt|;
comment|/* COMET adapter info */
name|struct
name|al_type
modifier|*
name|al_pinfo
decl_stmt|;
comment|/* phy info */
name|u_int8_t
name|al_unit
decl_stmt|;
comment|/* interface number */
name|u_int8_t
name|al_type
decl_stmt|;
name|u_int8_t
name|al_phy_addr
decl_stmt|;
comment|/* PHY address */
name|u_int8_t
name|al_tx_pend
decl_stmt|;
comment|/* TX pending */
name|u_int8_t
name|al_want_auto
decl_stmt|;
name|u_int8_t
name|al_autoneg
decl_stmt|;
name|caddr_t
name|al_ldata_ptr
decl_stmt|;
name|struct
name|al_list_data
modifier|*
name|al_ldata
decl_stmt|;
name|struct
name|al_chain_data
name|al_cdata
decl_stmt|;
name|u_int8_t
name|al_cachesize
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
value|bus_space_write_4(sc->al_btag, sc->al_bhandle, reg, val)
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
value|bus_space_write_2(sc->al_btag, sc->al_bbhandle, reg, val)
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
value|bus_space_write_1(sc->al_btag, sc->al_bhandle, reg, val)
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
value|bus_space_read_4(sc->al_btag, sc->al_bhandle, reg)
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
value|bus_space_read_2(sc->al_btag, sc->al_bhandle, reg)
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
value|bus_space_read_1(sc->al_btag, sc->al_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|AL_TIMEOUT
value|1000
end_define

begin_comment
comment|/*  * General constants that are fun to know.  *  * ADMtek PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|AL_VENDORID
value|0x1317
end_define

begin_comment
comment|/*  * AL981 device IDs.  */
end_comment

begin_define
define|#
directive|define
name|AL_DEVICEID_AL981
value|0x0981
end_define

begin_comment
comment|/*  * AN985 device ID.  */
end_comment

begin_define
define|#
directive|define
name|AL_DEVICEID_AN985
value|0x0985
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
name|AL_PCI_VENDOR_ID
value|0x00
end_define

begin_define
define|#
directive|define
name|AL_PCI_DEVICE_ID
value|0x02
end_define

begin_define
define|#
directive|define
name|AL_PCI_COMMAND
value|0x04
end_define

begin_define
define|#
directive|define
name|AL_PCI_STATUS
value|0x06
end_define

begin_define
define|#
directive|define
name|AL_PCI_REVID
value|0x08
end_define

begin_define
define|#
directive|define
name|AL_PCI_CLASSCODE
value|0x09
end_define

begin_define
define|#
directive|define
name|AL_PCI_CACHELEN
value|0x0C
end_define

begin_define
define|#
directive|define
name|AL_PCI_LATENCY_TIMER
value|0x0D
end_define

begin_define
define|#
directive|define
name|AL_PCI_HEADER_TYPE
value|0x0E
end_define

begin_define
define|#
directive|define
name|AL_PCI_LOIO
value|0x10
end_define

begin_define
define|#
directive|define
name|AL_PCI_LOMEM
value|0x14
end_define

begin_define
define|#
directive|define
name|AL_PCI_BIOSROM
value|0x30
end_define

begin_define
define|#
directive|define
name|AL_PCI_INTLINE
value|0x3C
end_define

begin_define
define|#
directive|define
name|AL_PCI_INTPIN
value|0x3D
end_define

begin_define
define|#
directive|define
name|AL_PCI_MINGNT
value|0x3E
end_define

begin_define
define|#
directive|define
name|AL_PCI_MINLAT
value|0x0F
end_define

begin_define
define|#
directive|define
name|AL_PCI_RESETOPT
value|0x48
end_define

begin_define
define|#
directive|define
name|AL_PCI_EEPROM_DATA
value|0x4C
end_define

begin_comment
comment|/* power management registers */
end_comment

begin_define
define|#
directive|define
name|AL_PCI_CAPID
value|0x44
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|AL_PCI_NEXTPTR
value|0x45
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|AL_PCI_PWRMGMTCAP
value|0x46
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|AL_PCI_PWRMGMTCTRL
value|0x48
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|AL_PSTATE_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|AL_PSTATE_D0
value|0x0000
end_define

begin_define
define|#
directive|define
name|AL_PSTATE_D1
value|0x0001
end_define

begin_define
define|#
directive|define
name|AL_PSTATE_D2
value|0x0002
end_define

begin_define
define|#
directive|define
name|AL_PSTATE_D3
value|0x0003
end_define

begin_define
define|#
directive|define
name|AL_PME_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|AL_PME_STATUS
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
name|AL_PHYADDR_MIN
value|0x00
end_define

begin_define
define|#
directive|define
name|AL_PHYADDR_MAL
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

