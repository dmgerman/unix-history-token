begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: awireg.h,v 1.3 2000/03/22 11:22:22 onoe Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1999 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Bill Sommerfeld  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * The firmware typically loaded onto Am79C930-based 802.11 interfaces  * uses a 32k or larger shared memory buffer to communicate with the  * host.  *  * Depending on the exact configuration of the device, this buffer may  * either be mapped into PCMCIA memory space, or accessible a byte at  * a type through PCMCIA I/O space.  *  * This header defines offsets into this shared memory.  */
end_comment

begin_comment
comment|/*  * LAST_TXD block.  5 32-bit words.  *  * There are five different output queues; this defines pointers to  * the last completed descriptor for each one.  */
end_comment

begin_define
define|#
directive|define
name|AWI_LAST_TXD
value|0x3ec
end_define

begin_comment
comment|/* last completed Tx Descr */
end_comment

begin_define
define|#
directive|define
name|AWI_LAST_BCAST_TXD
value|AWI_LAST_TXD+0
end_define

begin_define
define|#
directive|define
name|AWI_LAST_MGT_TXD
value|AWI_LAST_TXD+4
end_define

begin_define
define|#
directive|define
name|AWI_LAST_DATA_TXD
value|AWI_LAST_TXD+8
end_define

begin_define
define|#
directive|define
name|AWI_LAST_PS_POLL_TXD
value|AWI_LAST_TXD+12
end_define

begin_define
define|#
directive|define
name|AWI_LAST_CF_POLL_TXD
value|AWI_LAST_TXD+16
end_define

begin_comment
comment|/*  * Banner block; null-terminated string.  *  * The doc says it contains  * "PCnetMobile:v2.00 mmddyy APIx.x\0"  */
end_comment

begin_define
define|#
directive|define
name|AWI_BANNER
value|0x480
end_define

begin_comment
comment|/* Version string */
end_comment

begin_define
define|#
directive|define
name|AWI_BANNER_LEN
value|0x20
end_define

begin_comment
comment|/*  * Command block protocol:  * write command byte to a zero value.  * write command status to a zero value.  * write arguments to AWI_COMMAND_PARAMS  * write command byte to a non-zero value.  * wait for command status to be non-zero.  * write command byte to a zero value.  * write command status to a zero value.  */
end_comment

begin_define
define|#
directive|define
name|AWI_CMD
value|0x4a0
end_define

begin_comment
comment|/* Command opcode byte */
end_comment

begin_define
define|#
directive|define
name|AWI_CMD_IDLE
value|0x0
end_define

begin_define
define|#
directive|define
name|AWI_CMD_NOP
value|0x1
end_define

begin_define
define|#
directive|define
name|AWI_CMD_SET_MIB
value|0x2
end_define

begin_define
define|#
directive|define
name|AWI_CMD_GET_MIB
value|0x9
end_define

begin_define
define|#
directive|define
name|AWI_CA_MIB_TYPE
value|0x0
end_define

begin_define
define|#
directive|define
name|AWI_CA_MIB_SIZE
value|0x1
end_define

begin_define
define|#
directive|define
name|AWI_CA_MIB_INDEX
value|0x2
end_define

begin_define
define|#
directive|define
name|AWI_CA_MIB_DATA
value|0x4
end_define

begin_define
define|#
directive|define
name|AWI_MIB_LOCAL
value|0x0
end_define

begin_define
define|#
directive|define
name|AWI_MIB_ADDR
value|0x2
end_define

begin_define
define|#
directive|define
name|AWI_MIB_MAC
value|0x3
end_define

begin_define
define|#
directive|define
name|AWI_MIB_STAT
value|0x4
end_define

begin_define
define|#
directive|define
name|AWI_MIB_MGT
value|0x5
end_define

begin_define
define|#
directive|define
name|AWI_MIB_DRVR
value|0x6
end_define

begin_define
define|#
directive|define
name|AWI_MIB_PHY
value|0x7
end_define

begin_define
define|#
directive|define
name|AWI_CMD_INIT_TX
value|0x3
end_define

begin_define
define|#
directive|define
name|AWI_CA_TX_LEN
value|0x14
end_define

begin_define
define|#
directive|define
name|AWI_CA_TX_DATA
value|0x0
end_define

begin_define
define|#
directive|define
name|AWI_CA_TX_MGT
value|0x4
end_define

begin_define
define|#
directive|define
name|AWI_CA_TX_BCAST
value|0x8
end_define

begin_define
define|#
directive|define
name|AWI_CA_TX_PS
value|0xc
end_define

begin_define
define|#
directive|define
name|AWI_CA_TX_CF
value|0x10
end_define

begin_define
define|#
directive|define
name|AWI_CMD_FLUSH_TX
value|0x4
end_define

begin_define
define|#
directive|define
name|AWI_CA_FTX_LEN
value|0x5
end_define

begin_define
define|#
directive|define
name|AWI_CA_FTX_DATA
value|0x0
end_define

begin_define
define|#
directive|define
name|AWI_CA_FTX_MGT
value|0x1
end_define

begin_define
define|#
directive|define
name|AWI_CA_FTX_BCAST
value|0x2
end_define

begin_define
define|#
directive|define
name|AWI_CA_FTX_PS
value|0x3
end_define

begin_define
define|#
directive|define
name|AWI_CA_FTX_CF
value|0x4
end_define

begin_define
define|#
directive|define
name|AWI_CMD_INIT_RX
value|0x5
end_define

begin_define
define|#
directive|define
name|AWI_CA_IRX_LEN
value|0x8
end_define

begin_define
define|#
directive|define
name|AWI_CA_IRX_DATA_DESC
value|0x0
end_define

begin_comment
comment|/* return */
end_comment

begin_define
define|#
directive|define
name|AWI_CA_IRX_PS_DESC
value|0x4
end_define

begin_comment
comment|/* return */
end_comment

begin_define
define|#
directive|define
name|AWI_CMD_KILL_RX
value|0x6
end_define

begin_define
define|#
directive|define
name|AWI_CMD_SLEEP
value|0x7
end_define

begin_define
define|#
directive|define
name|AWI_CA_SLEEP_LEN
value|0x8
end_define

begin_define
define|#
directive|define
name|AWI_CA_WAKEUP
value|0x0
end_define

begin_comment
comment|/* uint64 */
end_comment

begin_define
define|#
directive|define
name|AWI_CMD_WAKE
value|0x8
end_define

begin_define
define|#
directive|define
name|AWI_CMD_SCAN
value|0xa
end_define

begin_define
define|#
directive|define
name|AWI_CA_SCAN_LEN
value|0x6
end_define

begin_define
define|#
directive|define
name|AWI_CA_SCAN_DURATION
value|0x0
end_define

begin_define
define|#
directive|define
name|AWI_CA_SCAN_SET
value|0x2
end_define

begin_define
define|#
directive|define
name|AWI_CA_SCAN_PATTERN
value|0x3
end_define

begin_define
define|#
directive|define
name|AWI_CA_SCAN_IDX
value|0x4
end_define

begin_define
define|#
directive|define
name|AWI_CA_SCAN_SUSP
value|0x5
end_define

begin_define
define|#
directive|define
name|AWI_CMD_SYNC
value|0xb
end_define

begin_define
define|#
directive|define
name|AWI_CA_SYNC_LEN
value|0x14
end_define

begin_define
define|#
directive|define
name|AWI_CA_SYNC_SET
value|0x0
end_define

begin_define
define|#
directive|define
name|AWI_CA_SYNC_PATTERN
value|0x1
end_define

begin_define
define|#
directive|define
name|AWI_CA_SYNC_IDX
value|0x2
end_define

begin_define
define|#
directive|define
name|AWI_CA_SYNC_STARTBSS
value|0x3
end_define

begin_define
define|#
directive|define
name|AWI_CA_SYNC_DWELL
value|0x4
end_define

begin_define
define|#
directive|define
name|AWI_CA_SYNC_MBZ
value|0x6
end_define

begin_define
define|#
directive|define
name|AWI_CA_SYNC_TIMESTAMP
value|0x8
end_define

begin_define
define|#
directive|define
name|AWI_CA_SYNC_REFTIME
value|0x10
end_define

begin_define
define|#
directive|define
name|AWI_CMD_RESUME
value|0xc
end_define

begin_define
define|#
directive|define
name|AWI_CMD_STATUS
value|0x4a1
end_define

begin_comment
comment|/* Command status */
end_comment

begin_define
define|#
directive|define
name|AWI_STAT_IDLE
value|0x0
end_define

begin_define
define|#
directive|define
name|AWI_STAT_OK
value|0x1
end_define

begin_define
define|#
directive|define
name|AWI_STAT_BADCMD
value|0x2
end_define

begin_define
define|#
directive|define
name|AWI_STAT_BADPARM
value|0x3
end_define

begin_define
define|#
directive|define
name|AWI_STAT_NOTIMP
value|0x4
end_define

begin_define
define|#
directive|define
name|AWI_STAT_BADRES
value|0x5
end_define

begin_define
define|#
directive|define
name|AWI_STAT_BADMODE
value|0x6
end_define

begin_define
define|#
directive|define
name|AWI_ERROR_OFFSET
value|0x4a2
end_define

begin_comment
comment|/* Offset to erroneous parameter */
end_comment

begin_define
define|#
directive|define
name|AWI_CMD_PARAMS
value|0x4a4
end_define

begin_comment
comment|/* Command parameters */
end_comment

begin_define
define|#
directive|define
name|AWI_CSB
value|0x4f0
end_define

begin_comment
comment|/* Control/Status block */
end_comment

begin_define
define|#
directive|define
name|AWI_SELFTEST
value|0x4f0
end_define

begin_define
define|#
directive|define
name|AWI_SELFTEST_INIT
value|0x00
end_define

begin_comment
comment|/* initial */
end_comment

begin_define
define|#
directive|define
name|AWI_SELFTEST_FIRMCKSUM
value|0x01
end_define

begin_comment
comment|/* firmware cksum running */
end_comment

begin_define
define|#
directive|define
name|AWI_SELFTEST_HARDWARE
value|0x02
end_define

begin_comment
comment|/* hardware tests running */
end_comment

begin_define
define|#
directive|define
name|AWI_SELFTEST_MIB
value|0x03
end_define

begin_comment
comment|/* mib initializing */
end_comment

begin_define
define|#
directive|define
name|AWI_SELFTEST_MIB_FAIL
value|0xfa
end_define

begin_define
define|#
directive|define
name|AWI_SELFTEST_RADIO_FAIL
value|0xfb
end_define

begin_define
define|#
directive|define
name|AWI_SELFTEST_MAC_FAIL
value|0xfc
end_define

begin_define
define|#
directive|define
name|AWI_SELFTEST_FLASH_FAIL
value|0xfd
end_define

begin_define
define|#
directive|define
name|AWI_SELFTEST_RAM_FAIL
value|0xfe
end_define

begin_define
define|#
directive|define
name|AWI_SELFTEST_PASSED
value|0xff
end_define

begin_define
define|#
directive|define
name|AWI_STA_STATE
value|0x4f1
end_define

begin_define
define|#
directive|define
name|AWI_STA_AP
value|0x20
end_define

begin_comment
comment|/* acting as AP */
end_comment

begin_define
define|#
directive|define
name|AWI_STA_NOPSP
value|0x10
end_define

begin_comment
comment|/* Power Saving disabled */
end_comment

begin_define
define|#
directive|define
name|AWI_STA_DOZE
value|0x08
end_define

begin_comment
comment|/* about to go to sleep */
end_comment

begin_define
define|#
directive|define
name|AWI_STA_PSP
value|0x04
end_define

begin_comment
comment|/* enable PSP */
end_comment

begin_define
define|#
directive|define
name|AWI_STA_RXEN
value|0x02
end_define

begin_comment
comment|/* enable RX */
end_comment

begin_define
define|#
directive|define
name|AWI_STA_TXEN
value|0x01
end_define

begin_comment
comment|/* enable TX */
end_comment

begin_define
define|#
directive|define
name|AWI_INTSTAT
value|0x4f3
end_define

begin_define
define|#
directive|define
name|AWI_INTMASK
value|0x4f4
end_define

begin_comment
comment|/* Bits in AWI_INTSTAT/AWI_INTMASK */
end_comment

begin_define
define|#
directive|define
name|AWI_INT_GROGGY
value|0x80
end_define

begin_comment
comment|/* about to wake up */
end_comment

begin_define
define|#
directive|define
name|AWI_INT_CFP_ENDING
value|0x40
end_define

begin_comment
comment|/* cont. free period ending */
end_comment

begin_define
define|#
directive|define
name|AWI_INT_DTIM
value|0x20
end_define

begin_comment
comment|/* beacon outgoing */
end_comment

begin_define
define|#
directive|define
name|AWI_INT_CFP_START
value|0x10
end_define

begin_comment
comment|/* cont. free period starting */
end_comment

begin_define
define|#
directive|define
name|AWI_INT_SCAN_CMPLT
value|0x08
end_define

begin_comment
comment|/* scan complete */
end_comment

begin_define
define|#
directive|define
name|AWI_INT_TX
value|0x04
end_define

begin_comment
comment|/* tx done */
end_comment

begin_define
define|#
directive|define
name|AWI_INT_RX
value|0x02
end_define

begin_comment
comment|/* rx done */
end_comment

begin_define
define|#
directive|define
name|AWI_INT_CMD
value|0x01
end_define

begin_comment
comment|/* cmd done */
end_comment

begin_comment
comment|/*  * The following are used to implement a locking protocol between host  * and MAC to protect the interrupt status and mask fields.  *  * driver: read lockout_host byte; if zero, set lockout_mac to non-zero,  *	then reread lockout_host byte; if still zero, host has lock.  *	if non-zero, clear lockout_mac, loop.  */
end_comment

begin_define
define|#
directive|define
name|AWI_LOCKOUT_MAC
value|0x4f5
end_define

begin_define
define|#
directive|define
name|AWI_LOCKOUT_HOST
value|0x4f6
end_define

begin_define
define|#
directive|define
name|AWI_INTSTAT2
value|0x4f7
end_define

begin_define
define|#
directive|define
name|AWI_INTMASK2
value|0x4fd
end_define

begin_comment
comment|/* Bits in AWI_INTSTAT2/INTMASK2 */
end_comment

begin_define
define|#
directive|define
name|AWI_INT2_RXMGT
value|0x80
end_define

begin_comment
comment|/* mgt/ps recieved */
end_comment

begin_define
define|#
directive|define
name|AWI_INT2_RXDATA
value|0x40
end_define

begin_comment
comment|/* data received */
end_comment

begin_define
define|#
directive|define
name|AWI_INT2_TXMGT
value|0x10
end_define

begin_comment
comment|/* mgt tx done */
end_comment

begin_define
define|#
directive|define
name|AWI_INT2_TXCF
value|0x08
end_define

begin_comment
comment|/* CF tx done */
end_comment

begin_define
define|#
directive|define
name|AWI_INT2_TXPS
value|0x04
end_define

begin_comment
comment|/* PS tx done */
end_comment

begin_define
define|#
directive|define
name|AWI_INT2_TXBCAST
value|0x02
end_define

begin_comment
comment|/* Broadcast tx done */
end_comment

begin_define
define|#
directive|define
name|AWI_INT2_TXDATA
value|0x01
end_define

begin_comment
comment|/* data tx done */
end_comment

begin_define
define|#
directive|define
name|AWI_DIS_PWRDN
value|0x4fc
end_define

begin_comment
comment|/* disable powerdown if set */
end_comment

begin_define
define|#
directive|define
name|AWI_DRIVERSTATE
value|0x4fe
end_define

begin_comment
comment|/* driver state */
end_comment

begin_define
define|#
directive|define
name|AWI_DRV_STATEMASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|AWI_DRV_RESET
value|0x0
end_define

begin_define
define|#
directive|define
name|AWI_DRV_INFSY
value|0x1
end_define

begin_comment
comment|/* inf synced */
end_comment

begin_define
define|#
directive|define
name|AWI_DRV_ADHSC
value|0x2
end_define

begin_comment
comment|/* adhoc scan */
end_comment

begin_define
define|#
directive|define
name|AWI_DRV_ADHSY
value|0x3
end_define

begin_comment
comment|/* adhoc synced */
end_comment

begin_define
define|#
directive|define
name|AWI_DRV_INFSC
value|0x4
end_define

begin_comment
comment|/* inf scanning */
end_comment

begin_define
define|#
directive|define
name|AWI_DRV_INFAUTH
value|0x5
end_define

begin_comment
comment|/* inf authed */
end_comment

begin_define
define|#
directive|define
name|AWI_DRV_INFASSOC
value|0x6
end_define

begin_comment
comment|/* inf associated */
end_comment

begin_define
define|#
directive|define
name|AWI_DRV_INFTOSS
value|0x7
end_define

begin_comment
comment|/* inf handoff */
end_comment

begin_define
define|#
directive|define
name|AWI_DRV_APNONE
value|0x8
end_define

begin_comment
comment|/* AP activity: no assoc */
end_comment

begin_define
define|#
directive|define
name|AWI_DRV_APQUIET
value|0xc
end_define

begin_comment
comment|/* AP:>=one assoc, no traffic */
end_comment

begin_define
define|#
directive|define
name|AWI_DRV_APLO
value|0xd
end_define

begin_comment
comment|/* AP:>=one assoc, light tfc */
end_comment

begin_define
define|#
directive|define
name|AWI_DRV_APMED
value|0xe
end_define

begin_comment
comment|/* AP:>=one assoc, mod tfc */
end_comment

begin_define
define|#
directive|define
name|AWI_DRV_APHIGH
value|0xf
end_define

begin_comment
comment|/* AP:>=one assoc, heavy tfc */
end_comment

begin_define
define|#
directive|define
name|AWI_DRV_AUTORXLED
value|0x10
end_define

begin_define
define|#
directive|define
name|AWI_DRV_AUTOTXLED
value|0x20
end_define

begin_define
define|#
directive|define
name|AWI_DRV_RXLED
value|0x40
end_define

begin_define
define|#
directive|define
name|AWI_DRV_TXLED
value|0x80
end_define

begin_define
define|#
directive|define
name|AWI_VBM
value|0x500
end_define

begin_comment
comment|/* Virtual Bit Map */
end_comment

begin_define
define|#
directive|define
name|AWI_BUFFERS
value|0x600
end_define

begin_comment
comment|/* Buffers */
end_comment

begin_define
define|#
directive|define
name|AWI_BUFFERS_END
value|0x6000
end_define

begin_comment
comment|/*  * Receive descriptors; there are a linked list of these chained  * through the "NEXT" fields, starting from XXX  */
end_comment

begin_define
define|#
directive|define
name|AWI_RXD_SIZE
value|0x18
end_define

begin_define
define|#
directive|define
name|AWI_RXD_NEXT
value|0x4
end_define

begin_define
define|#
directive|define
name|AWI_RXD_NEXT_LAST
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AWI_RXD_HOST_DESC_STATE
value|0x9
end_define

begin_define
define|#
directive|define
name|AWI_RXD_ST_OWN
value|0x80
end_define

begin_comment
comment|/* host owns this */
end_comment

begin_define
define|#
directive|define
name|AWI_RXD_ST_CONSUMED
value|0x40
end_define

begin_comment
comment|/* host is done */
end_comment

begin_define
define|#
directive|define
name|AWI_RXD_ST_LF
value|0x20
end_define

begin_comment
comment|/* last frag */
end_comment

begin_define
define|#
directive|define
name|AWI_RXD_ST_CRC
value|0x08
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_define
define|#
directive|define
name|AWI_RXD_ST_OFLO
value|0x02
end_define

begin_comment
comment|/* possible buffer overrun */
end_comment

begin_define
define|#
directive|define
name|AWI_RXD_ST_RXERROR
value|0x01
end_define

begin_comment
comment|/* this frame is borked; discard me */
end_comment

begin_define
define|#
directive|define
name|AWI_RXD_RSSI
value|0xa
end_define

begin_comment
comment|/* 1 byte: radio strength indicator */
end_comment

begin_define
define|#
directive|define
name|AWI_RXD_INDEX
value|0xb
end_define

begin_comment
comment|/* 1 byte: FH hop index or DS channel */
end_comment

begin_define
define|#
directive|define
name|AWI_RXD_LOCALTIME
value|0xc
end_define

begin_comment
comment|/* 4 bytes: local time of RX */
end_comment

begin_define
define|#
directive|define
name|AWI_RXD_START_FRAME
value|0x10
end_define

begin_comment
comment|/* 4 bytes: ptr to first received byte */
end_comment

begin_define
define|#
directive|define
name|AWI_RXD_LEN
value|0x14
end_define

begin_comment
comment|/* 2 bytes: rx len in bytes */
end_comment

begin_define
define|#
directive|define
name|AWI_RXD_RATE
value|0x16
end_define

begin_comment
comment|/* 1 byte: rx rate in 1e5 bps */
end_comment

begin_comment
comment|/*  * Transmit descriptors.  */
end_comment

begin_define
define|#
directive|define
name|AWI_TXD_SIZE
value|0x18
end_define

begin_define
define|#
directive|define
name|AWI_TXD_START
value|0x00
end_define

begin_comment
comment|/* pointer to start of frame */
end_comment

begin_define
define|#
directive|define
name|AWI_TXD_NEXT
value|0x04
end_define

begin_comment
comment|/* pointer to next TXD */
end_comment

begin_define
define|#
directive|define
name|AWI_TXD_LENGTH
value|0x08
end_define

begin_comment
comment|/* length of frame */
end_comment

begin_define
define|#
directive|define
name|AWI_TXD_STATE
value|0x0a
end_define

begin_comment
comment|/* state */
end_comment

begin_define
define|#
directive|define
name|AWI_TXD_ST_OWN
value|0x80
end_define

begin_comment
comment|/* MAC owns this  */
end_comment

begin_define
define|#
directive|define
name|AWI_TXD_ST_DONE
value|0x40
end_define

begin_comment
comment|/* MAC is done */
end_comment

begin_define
define|#
directive|define
name|AWI_TXD_ST_REJ
value|0x20
end_define

begin_comment
comment|/* MAC doesn't like */
end_comment

begin_define
define|#
directive|define
name|AWI_TXD_ST_MSDU
value|0x10
end_define

begin_comment
comment|/* MSDU timeout */
end_comment

begin_define
define|#
directive|define
name|AWI_TXD_ST_ABRT
value|0x08
end_define

begin_comment
comment|/* TX aborted */
end_comment

begin_define
define|#
directive|define
name|AWI_TXD_ST_RETURNED
value|0x04
end_define

begin_comment
comment|/* TX returned */
end_comment

begin_define
define|#
directive|define
name|AWI_TXD_ST_RETRY
value|0x02
end_define

begin_comment
comment|/* TX retries exceeded */
end_comment

begin_define
define|#
directive|define
name|AWI_TXD_ST_ERROR
value|0x01
end_define

begin_comment
comment|/* TX error */
end_comment

begin_define
define|#
directive|define
name|AWI_TXD_RATE
value|0x0b
end_define

begin_comment
comment|/* rate */
end_comment

begin_define
define|#
directive|define
name|AWI_RATE_1MBIT
value|10
end_define

begin_define
define|#
directive|define
name|AWI_RATE_2MBIT
value|20
end_define

begin_define
define|#
directive|define
name|AWI_TXD_NDA
value|0x0c
end_define

begin_comment
comment|/* num DIFS attempts */
end_comment

begin_define
define|#
directive|define
name|AWI_TXD_NDF
value|0x0d
end_define

begin_comment
comment|/* num DIFS failures */
end_comment

begin_define
define|#
directive|define
name|AWI_TXD_NSA
value|0x0e
end_define

begin_comment
comment|/* num SIFS attempts */
end_comment

begin_define
define|#
directive|define
name|AWI_TXD_NSF
value|0x0f
end_define

begin_comment
comment|/* num SIFS failures */
end_comment

begin_define
define|#
directive|define
name|AWI_TXD_NRA
value|0x14
end_define

begin_comment
comment|/* num RTS attempts */
end_comment

begin_define
define|#
directive|define
name|AWI_TXD_NDTA
value|0x15
end_define

begin_comment
comment|/* num data attempts */
end_comment

begin_define
define|#
directive|define
name|AWI_TXD_CTL
value|0x16
end_define

begin_comment
comment|/* control */
end_comment

begin_define
define|#
directive|define
name|AWI_TXD_CTL_PSN
value|0x80
end_define

begin_comment
comment|/* preserve sequence in MAC frame */
end_comment

begin_define
define|#
directive|define
name|AWI_TXD_CTL_BURST
value|0x02
end_define

begin_comment
comment|/* host is doing 802.11 fragmt. */
end_comment

begin_define
define|#
directive|define
name|AWI_TXD_CTL_FRAGS
value|0x01
end_define

begin_comment
comment|/* override normal fragmentation */
end_comment

begin_comment
comment|/*  * MIB structures.  */
end_comment

begin_define
define|#
directive|define
name|AWI_ESS_ID_SIZE
value|(IEEE80211_NWID_LEN+2)
end_define

begin_struct
struct|struct
name|awi_mib_local
block|{
name|u_int8_t
name|Fragmentation_Dis
decl_stmt|;
name|u_int8_t
name|Add_PLCP_Dis
decl_stmt|;
name|u_int8_t
name|MAC_Hdr_Prsv
decl_stmt|;
name|u_int8_t
name|Rx_Mgmt_Que_En
decl_stmt|;
name|u_int8_t
name|Re_Assembly_Dis
decl_stmt|;
name|u_int8_t
name|Strip_PLCP_Dis
decl_stmt|;
name|u_int8_t
name|Rx_Error_Dis
decl_stmt|;
name|u_int8_t
name|Power_Saving_Mode_Dis
decl_stmt|;
name|u_int8_t
name|Accept_All_Multicast_Dis
decl_stmt|;
name|u_int8_t
name|Check_Seq_Cntl_Dis
decl_stmt|;
name|u_int8_t
name|Flush_CFP_Queue_On_CF_End
decl_stmt|;
name|u_int8_t
name|Network_Mode
decl_stmt|;
name|u_int8_t
name|PWD_Lvl
decl_stmt|;
name|u_int8_t
name|CFP_Mode
decl_stmt|;
name|u_int8_t
name|Tx_Buffer_Offset
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|Tx_Buffer_Size
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|Rx_Buffer_Offset
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|Rx_Buffer_Size
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|Acting_as_AP
decl_stmt|;
name|u_int8_t
name|Fill_CFP
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|awi_mib_mac
block|{
name|u_int8_t
name|_Reserved1
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|_Reserved2
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aRTS_Threshold
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aCW_max
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aCW_min
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aPromiscuous_Enable
decl_stmt|;
name|u_int8_t
name|_Reserved3
decl_stmt|;
name|u_int8_t
name|_Reserved4
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|aShort_Retry_Limit
decl_stmt|;
name|u_int8_t
name|aLong_Retry_Limit
decl_stmt|;
name|u_int8_t
name|aMax_Frame_Length
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aFragmentation_Threshold
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aProbe_Delay
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aMin_Probe_Response_Time
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aMax_Probe_Response_Time
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aMax_Transmit_MSDU_Lifetime
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|aMax_Receive_MSDU_Lifetime
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|aStation_Basic_Rate
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aDesired_ESS_ID
index|[
name|AWI_ESS_ID_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|awi_mib_stat
block|{
name|u_int8_t
name|aTransmitted_MPDU_Count
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|aTransmitted_MSDU_Count
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|aOctets_Transmitted_Cnt
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|aMulticast_Transmitted_Frame_Count
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aBroadcast_Transmitted_Frame_Count
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aFailed_Count
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|aRetry_Count
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|aMultiple_Retry_Count
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|aFrame_Duplicate_Count
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|aRTS_Success_Count
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|aRTS_Failure_Count
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|aACK_Failure_Count
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|aReceived_Frame_Count
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|aOctets_Received_Count
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|aMulticast_Received_Count
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aBroadcast_Received_Count
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aFCS_Error_Count
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|aError_Count
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|aWEP_Undecryptable_Count
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|awi_mib_mgt
block|{
name|u_int8_t
name|aPower_Mgt_Mode
decl_stmt|;
name|u_int8_t
name|aScan_Mode
decl_stmt|;
define|#
directive|define
name|AWI_SCAN_PASSIVE
value|0x00
define|#
directive|define
name|AWI_SCAN_ACTIVE
value|0x01
define|#
directive|define
name|AWI_SCAN_BACKGROUND
value|0x02
name|u_int8_t
name|aScan_State
decl_stmt|;
name|u_int8_t
name|aDTIM_Period
decl_stmt|;
name|u_int8_t
name|aATIM_Window
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|Wep_Required
decl_stmt|;
name|u_int8_t
name|_Reserved1
decl_stmt|;
name|u_int8_t
name|aBeacon_Period
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aPassive_Scan_Duration
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aListen_Interval
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aMedium_Occupancy_Limit
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aMax_MPDU_Time
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aCFP_Max_Duration
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aCFP_Rate
decl_stmt|;
name|u_int8_t
name|Do_Not_Receive_DTIMs
decl_stmt|;
name|u_int8_t
name|aStation_ID
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aCurrent_BSS_ID
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|aCurrent_ESS_ID
index|[
name|AWI_ESS_ID_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AWI_GROUP_ADDR_SIZE
value|4
end_define

begin_struct
struct|struct
name|awi_mib_addr
block|{
name|u_int8_t
name|aMAC_Address
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|aGroup_Addresses
index|[
name|AWI_GROUP_ADDR_SIZE
index|]
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|aTransmit_Enable_Status
decl_stmt|;
name|u_int8_t
name|_Reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AWI_PWR_LEVEL_SIZE
value|4
end_define

begin_struct
struct|struct
name|awi_mib_phy
block|{
name|u_int8_t
name|aSlot_Time
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aSIFS
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aMPDU_Maximum
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aHop_Time
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|aSuprt_Data_Rates
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|aCurrent_Reg_Domain
decl_stmt|;
define|#
directive|define
name|AWI_REG_DOMAIN_US
value|0x10
define|#
directive|define
name|AWI_REG_DOMAIN_CA
value|0x20
define|#
directive|define
name|AWI_REG_DOMAIN_EU
value|0x30
define|#
directive|define
name|AWI_REG_DOMAIN_ES
value|0x31
define|#
directive|define
name|AWI_REG_DOMAIN_FR
value|0x32
define|#
directive|define
name|AWI_REG_DOMAIN_JP
value|0x40
name|u_int8_t
name|aPreamble_Lngth
decl_stmt|;
name|u_int8_t
name|aPLCP_Hdr_Lngth
decl_stmt|;
name|u_int8_t
name|Pwr_Up_Time
index|[
name|AWI_PWR_LEVEL_SIZE
index|]
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|IEEE_PHY_Type
decl_stmt|;
define|#
directive|define
name|AWI_PHY_TYPE_FH
value|1
define|#
directive|define
name|AWI_PHY_TYPE_DS
value|2
define|#
directive|define
name|AWI_PHY_TYPE_IR
value|3
name|u_int8_t
name|RCR_33A_Bits
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

