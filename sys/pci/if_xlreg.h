begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|XL_EE_READ
value|0x0080
end_define

begin_comment
comment|/* read, 5 bit address */
end_comment

begin_define
define|#
directive|define
name|XL_EE_WRITE
value|0x0040
end_define

begin_comment
comment|/* write, 5 bit address */
end_comment

begin_define
define|#
directive|define
name|XL_EE_ERASE
value|0x00c0
end_define

begin_comment
comment|/* erase, 5 bit address */
end_comment

begin_define
define|#
directive|define
name|XL_EE_EWEN
value|0x0030
end_define

begin_comment
comment|/* erase, no data needed */
end_comment

begin_define
define|#
directive|define
name|XL_EE_8BIT_READ
value|0x0200
end_define

begin_comment
comment|/* read, 8 bit address */
end_comment

begin_define
define|#
directive|define
name|XL_EE_BUSY
value|0x8000
end_define

begin_define
define|#
directive|define
name|XL_EE_EADDR0
value|0x00
end_define

begin_comment
comment|/* station address, first word */
end_comment

begin_define
define|#
directive|define
name|XL_EE_EADDR1
value|0x01
end_define

begin_comment
comment|/* station address, next word, */
end_comment

begin_define
define|#
directive|define
name|XL_EE_EADDR2
value|0x02
end_define

begin_comment
comment|/* station address, last word */
end_comment

begin_define
define|#
directive|define
name|XL_EE_PRODID
value|0x03
end_define

begin_comment
comment|/* product ID code */
end_comment

begin_define
define|#
directive|define
name|XL_EE_MDATA_DATE
value|0x04
end_define

begin_comment
comment|/* manufacturing data, date */
end_comment

begin_define
define|#
directive|define
name|XL_EE_MDATA_DIV
value|0x05
end_define

begin_comment
comment|/* manufacturing data, division */
end_comment

begin_define
define|#
directive|define
name|XL_EE_MDATA_PCODE
value|0x06
end_define

begin_comment
comment|/* manufacturing data, product code */
end_comment

begin_define
define|#
directive|define
name|XL_EE_MFG_ID
value|0x07
end_define

begin_define
define|#
directive|define
name|XL_EE_PCI_PARM
value|0x08
end_define

begin_define
define|#
directive|define
name|XL_EE_ROM_ONFO
value|0x09
end_define

begin_define
define|#
directive|define
name|XL_EE_OEM_ADR0
value|0x0A
end_define

begin_define
define|#
directive|define
name|XL_EE_OEM_ADR1
value|0x0B
end_define

begin_define
define|#
directive|define
name|XL_EE_OEM_ADR2
value|0x0C
end_define

begin_define
define|#
directive|define
name|XL_EE_SOFTINFO1
value|0x0D
end_define

begin_define
define|#
directive|define
name|XL_EE_COMPAT
value|0x0E
end_define

begin_define
define|#
directive|define
name|XL_EE_SOFTINFO2
value|0x0F
end_define

begin_define
define|#
directive|define
name|XL_EE_CAPS
value|0x10
end_define

begin_comment
comment|/* capabilities word */
end_comment

begin_define
define|#
directive|define
name|XL_EE_RSVD0
value|0x11
end_define

begin_define
define|#
directive|define
name|XL_EE_ICFG_0
value|0x12
end_define

begin_define
define|#
directive|define
name|XL_EE_ICFG_1
value|0x13
end_define

begin_define
define|#
directive|define
name|XL_EE_RSVD1
value|0x14
end_define

begin_define
define|#
directive|define
name|XL_EE_SOFTINFO3
value|0x15
end_define

begin_define
define|#
directive|define
name|XL_EE_RSVD_2
value|0x16
end_define

begin_comment
comment|/*  * Bits in the capabilities word  */
end_comment

begin_define
define|#
directive|define
name|XL_CAPS_PNP
value|0x0001
end_define

begin_define
define|#
directive|define
name|XL_CAPS_FULL_DUPLEX
value|0x0002
end_define

begin_define
define|#
directive|define
name|XL_CAPS_LARGE_PKTS
value|0x0004
end_define

begin_define
define|#
directive|define
name|XL_CAPS_SLAVE_DMA
value|0x0008
end_define

begin_define
define|#
directive|define
name|XL_CAPS_SECOND_DMA
value|0x0010
end_define

begin_define
define|#
directive|define
name|XL_CAPS_FULL_BM
value|0x0020
end_define

begin_define
define|#
directive|define
name|XL_CAPS_FRAG_BM
value|0x0040
end_define

begin_define
define|#
directive|define
name|XL_CAPS_CRC_PASSTHRU
value|0x0080
end_define

begin_define
define|#
directive|define
name|XL_CAPS_TXDONE
value|0x0100
end_define

begin_define
define|#
directive|define
name|XL_CAPS_NO_TXLENGTH
value|0x0200
end_define

begin_define
define|#
directive|define
name|XL_CAPS_RX_REPEAT
value|0x0400
end_define

begin_define
define|#
directive|define
name|XL_CAPS_SNOOPING
value|0x0800
end_define

begin_define
define|#
directive|define
name|XL_CAPS_100MBPS
value|0x1000
end_define

begin_define
define|#
directive|define
name|XL_CAPS_PWRMGMT
value|0x2000
end_define

begin_define
define|#
directive|define
name|XL_PACKET_SIZE
value|1540
end_define

begin_define
define|#
directive|define
name|XL_MAX_FRAMELEN
value|(ETHER_MAX_LEN + ETHER_VLAN_ENCAP_LEN)
end_define

begin_comment
comment|/*  * Register layouts.  */
end_comment

begin_define
define|#
directive|define
name|XL_COMMAND
value|0x0E
end_define

begin_define
define|#
directive|define
name|XL_STATUS
value|0x0E
end_define

begin_define
define|#
directive|define
name|XL_TX_STATUS
value|0x1B
end_define

begin_define
define|#
directive|define
name|XL_TX_FREE
value|0x1C
end_define

begin_define
define|#
directive|define
name|XL_DMACTL
value|0x20
end_define

begin_define
define|#
directive|define
name|XL_DOWNLIST_PTR
value|0x24
end_define

begin_define
define|#
directive|define
name|XL_DOWN_POLL
value|0x2D
end_define

begin_comment
comment|/* 3c90xB only */
end_comment

begin_define
define|#
directive|define
name|XL_TX_FREETHRESH
value|0x2F
end_define

begin_define
define|#
directive|define
name|XL_UPLIST_PTR
value|0x38
end_define

begin_define
define|#
directive|define
name|XL_UPLIST_STATUS
value|0x30
end_define

begin_define
define|#
directive|define
name|XL_UP_POLL
value|0x3D
end_define

begin_comment
comment|/* 3c90xB only */
end_comment

begin_define
define|#
directive|define
name|XL_PKTSTAT_UP_STALLED
value|0x00002000
end_define

begin_define
define|#
directive|define
name|XL_PKTSTAT_UP_ERROR
value|0x00004000
end_define

begin_define
define|#
directive|define
name|XL_PKTSTAT_UP_CMPLT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|XL_DMACTL_DN_CMPLT_REQ
value|0x00000002
end_define

begin_define
define|#
directive|define
name|XL_DMACTL_DOWN_STALLED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|XL_DMACTL_UP_CMPLT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|XL_DMACTL_DOWN_CMPLT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|XL_DMACTL_UP_RX_EARLY
value|0x00000020
end_define

begin_define
define|#
directive|define
name|XL_DMACTL_ARM_COUNTDOWN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|XL_DMACTL_DOWN_INPROG
value|0x00000080
end_define

begin_define
define|#
directive|define
name|XL_DMACTL_COUNTER_SPEED
value|0x00000100
end_define

begin_define
define|#
directive|define
name|XL_DMACTL_DOWNDOWN_MODE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|XL_DMACTL_TARGET_ABORT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|XL_DMACTL_MASTER_ABORT
value|0x80000000
end_define

begin_comment
comment|/*  * Command codes. Some command codes require that we wait for  * the CMD_BUSY flag to clear. Those codes are marked as 'mustwait.'  */
end_comment

begin_define
define|#
directive|define
name|XL_CMD_RESET
value|0x0000
end_define

begin_comment
comment|/* mustwait */
end_comment

begin_define
define|#
directive|define
name|XL_CMD_WINSEL
value|0x0800
end_define

begin_define
define|#
directive|define
name|XL_CMD_COAX_START
value|0x1000
end_define

begin_define
define|#
directive|define
name|XL_CMD_RX_DISABLE
value|0x1800
end_define

begin_define
define|#
directive|define
name|XL_CMD_RX_ENABLE
value|0x2000
end_define

begin_define
define|#
directive|define
name|XL_CMD_RX_RESET
value|0x2800
end_define

begin_comment
comment|/* mustwait */
end_comment

begin_define
define|#
directive|define
name|XL_CMD_UP_STALL
value|0x3000
end_define

begin_comment
comment|/* mustwait */
end_comment

begin_define
define|#
directive|define
name|XL_CMD_UP_UNSTALL
value|0x3001
end_define

begin_define
define|#
directive|define
name|XL_CMD_DOWN_STALL
value|0x3002
end_define

begin_comment
comment|/* mustwait */
end_comment

begin_define
define|#
directive|define
name|XL_CMD_DOWN_UNSTALL
value|0x3003
end_define

begin_define
define|#
directive|define
name|XL_CMD_RX_DISCARD
value|0x4000
end_define

begin_define
define|#
directive|define
name|XL_CMD_TX_ENABLE
value|0x4800
end_define

begin_define
define|#
directive|define
name|XL_CMD_TX_DISABLE
value|0x5000
end_define

begin_define
define|#
directive|define
name|XL_CMD_TX_RESET
value|0x5800
end_define

begin_comment
comment|/* mustwait */
end_comment

begin_define
define|#
directive|define
name|XL_CMD_INTR_FAKE
value|0x6000
end_define

begin_define
define|#
directive|define
name|XL_CMD_INTR_ACK
value|0x6800
end_define

begin_define
define|#
directive|define
name|XL_CMD_INTR_ENB
value|0x7000
end_define

begin_define
define|#
directive|define
name|XL_CMD_STAT_ENB
value|0x7800
end_define

begin_define
define|#
directive|define
name|XL_CMD_RX_SET_FILT
value|0x8000
end_define

begin_define
define|#
directive|define
name|XL_CMD_RX_SET_THRESH
value|0x8800
end_define

begin_define
define|#
directive|define
name|XL_CMD_TX_SET_THRESH
value|0x9000
end_define

begin_define
define|#
directive|define
name|XL_CMD_TX_SET_START
value|0x9800
end_define

begin_define
define|#
directive|define
name|XL_CMD_DMA_UP
value|0xA000
end_define

begin_define
define|#
directive|define
name|XL_CMD_DMA_STOP
value|0xA001
end_define

begin_define
define|#
directive|define
name|XL_CMD_STATS_ENABLE
value|0xA800
end_define

begin_define
define|#
directive|define
name|XL_CMD_STATS_DISABLE
value|0xB000
end_define

begin_define
define|#
directive|define
name|XL_CMD_COAX_STOP
value|0xB800
end_define

begin_define
define|#
directive|define
name|XL_CMD_SET_TX_RECLAIM
value|0xC000
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_define
define|#
directive|define
name|XL_CMD_RX_SET_HASH
value|0xC800
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_define
define|#
directive|define
name|XL_HASH_SET
value|0x0400
end_define

begin_define
define|#
directive|define
name|XL_HASHFILT_SIZE
value|256
end_define

begin_comment
comment|/*  * status codes  * Note that bits 15 to 13 indicate the currently visible register window  * which may be anything from 0 to 7.  */
end_comment

begin_define
define|#
directive|define
name|XL_STAT_INTLATCH
value|0x0001
end_define

begin_comment
comment|/* 0 */
end_comment

begin_define
define|#
directive|define
name|XL_STAT_ADFAIL
value|0x0002
end_define

begin_comment
comment|/* 1 */
end_comment

begin_define
define|#
directive|define
name|XL_STAT_TX_COMPLETE
value|0x0004
end_define

begin_comment
comment|/* 2 */
end_comment

begin_define
define|#
directive|define
name|XL_STAT_TX_AVAIL
value|0x0008
end_define

begin_comment
comment|/* 3 first generation */
end_comment

begin_define
define|#
directive|define
name|XL_STAT_RX_COMPLETE
value|0x0010
end_define

begin_comment
comment|/* 4 */
end_comment

begin_define
define|#
directive|define
name|XL_STAT_RX_EARLY
value|0x0020
end_define

begin_comment
comment|/* 5 */
end_comment

begin_define
define|#
directive|define
name|XL_STAT_INTREQ
value|0x0040
end_define

begin_comment
comment|/* 6 */
end_comment

begin_define
define|#
directive|define
name|XL_STAT_STATSOFLOW
value|0x0080
end_define

begin_comment
comment|/* 7 */
end_comment

begin_define
define|#
directive|define
name|XL_STAT_DMADONE
value|0x0100
end_define

begin_comment
comment|/* 8 first generation */
end_comment

begin_define
define|#
directive|define
name|XL_STAT_LINKSTAT
value|0x0100
end_define

begin_comment
comment|/* 8 3c509B */
end_comment

begin_define
define|#
directive|define
name|XL_STAT_DOWN_COMPLETE
value|0x0200
end_define

begin_comment
comment|/* 9 */
end_comment

begin_define
define|#
directive|define
name|XL_STAT_UP_COMPLETE
value|0x0400
end_define

begin_comment
comment|/* 10 */
end_comment

begin_define
define|#
directive|define
name|XL_STAT_DMABUSY
value|0x0800
end_define

begin_comment
comment|/* 11 first generation */
end_comment

begin_define
define|#
directive|define
name|XL_STAT_CMDBUSY
value|0x1000
end_define

begin_comment
comment|/* 12 */
end_comment

begin_comment
comment|/*  * Interrupts we normally want enabled.  */
end_comment

begin_define
define|#
directive|define
name|XL_INTRS
define|\
value|(XL_STAT_UP_COMPLETE|XL_STAT_STATSOFLOW|XL_STAT_ADFAIL|	\ 	 XL_STAT_DOWN_COMPLETE|XL_STAT_TX_COMPLETE|XL_STAT_INTLATCH)
end_define

begin_comment
comment|/*  * Window 0 registers  */
end_comment

begin_define
define|#
directive|define
name|XL_W0_EE_DATA
value|0x0C
end_define

begin_define
define|#
directive|define
name|XL_W0_EE_CMD
value|0x0A
end_define

begin_define
define|#
directive|define
name|XL_W0_RSRC_CFG
value|0x08
end_define

begin_define
define|#
directive|define
name|XL_W0_ADDR_CFG
value|0x06
end_define

begin_define
define|#
directive|define
name|XL_W0_CFG_CTRL
value|0x04
end_define

begin_define
define|#
directive|define
name|XL_W0_PROD_ID
value|0x02
end_define

begin_define
define|#
directive|define
name|XL_W0_MFG_ID
value|0x00
end_define

begin_comment
comment|/*  * Window 1  */
end_comment

begin_define
define|#
directive|define
name|XL_W1_TX_FIFO
value|0x10
end_define

begin_define
define|#
directive|define
name|XL_W1_FREE_TX
value|0x0C
end_define

begin_define
define|#
directive|define
name|XL_W1_TX_STATUS
value|0x0B
end_define

begin_define
define|#
directive|define
name|XL_W1_TX_TIMER
value|0x0A
end_define

begin_define
define|#
directive|define
name|XL_W1_RX_STATUS
value|0x08
end_define

begin_define
define|#
directive|define
name|XL_W1_RX_FIFO
value|0x00
end_define

begin_comment
comment|/*  * RX status codes  */
end_comment

begin_define
define|#
directive|define
name|XL_RXSTATUS_OVERRUN
value|0x01
end_define

begin_define
define|#
directive|define
name|XL_RXSTATUS_RUNT
value|0x02
end_define

begin_define
define|#
directive|define
name|XL_RXSTATUS_ALIGN
value|0x04
end_define

begin_define
define|#
directive|define
name|XL_RXSTATUS_CRC
value|0x08
end_define

begin_define
define|#
directive|define
name|XL_RXSTATUS_OVERSIZE
value|0x10
end_define

begin_define
define|#
directive|define
name|XL_RXSTATUS_DRIBBLE
value|0x20
end_define

begin_comment
comment|/*  * TX status codes  */
end_comment

begin_define
define|#
directive|define
name|XL_TXSTATUS_RECLAIM
value|0x02
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_define
define|#
directive|define
name|XL_TXSTATUS_OVERFLOW
value|0x04
end_define

begin_define
define|#
directive|define
name|XL_TXSTATUS_MAXCOLS
value|0x08
end_define

begin_define
define|#
directive|define
name|XL_TXSTATUS_UNDERRUN
value|0x10
end_define

begin_define
define|#
directive|define
name|XL_TXSTATUS_JABBER
value|0x20
end_define

begin_define
define|#
directive|define
name|XL_TXSTATUS_INTREQ
value|0x40
end_define

begin_define
define|#
directive|define
name|XL_TXSTATUS_COMPLETE
value|0x80
end_define

begin_comment
comment|/*  * Window 2  */
end_comment

begin_define
define|#
directive|define
name|XL_W2_RESET_OPTIONS
value|0x0C
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_define
define|#
directive|define
name|XL_W2_STATION_MASK_HI
value|0x0A
end_define

begin_define
define|#
directive|define
name|XL_W2_STATION_MASK_MID
value|0x08
end_define

begin_define
define|#
directive|define
name|XL_W2_STATION_MASK_LO
value|0x06
end_define

begin_define
define|#
directive|define
name|XL_W2_STATION_ADDR_HI
value|0x04
end_define

begin_define
define|#
directive|define
name|XL_W2_STATION_ADDR_MID
value|0x02
end_define

begin_define
define|#
directive|define
name|XL_W2_STATION_ADDR_LO
value|0x00
end_define

begin_define
define|#
directive|define
name|XL_RESETOPT_FEATUREMASK
value|(0x0001 | 0x0002 | 0x004)
end_define

begin_define
define|#
directive|define
name|XL_RESETOPT_D3RESETDIS
value|0x0008
end_define

begin_define
define|#
directive|define
name|XL_RESETOPT_DISADVFD
value|0x0010
end_define

begin_define
define|#
directive|define
name|XL_RESETOPT_DISADV100
value|0x0020
end_define

begin_define
define|#
directive|define
name|XL_RESETOPT_DISAUTONEG
value|0x0040
end_define

begin_define
define|#
directive|define
name|XL_RESETOPT_DEBUGMODE
value|0x0080
end_define

begin_define
define|#
directive|define
name|XL_RESETOPT_FASTAUTO
value|0x0100
end_define

begin_define
define|#
directive|define
name|XL_RESETOPT_FASTEE
value|0x0200
end_define

begin_define
define|#
directive|define
name|XL_RESETOPT_FORCEDCONF
value|0x0400
end_define

begin_define
define|#
directive|define
name|XL_RESETOPT_TESTPDTPDR
value|0x0800
end_define

begin_define
define|#
directive|define
name|XL_RESETOPT_TEST100TX
value|0x1000
end_define

begin_define
define|#
directive|define
name|XL_RESETOPT_TEST100RX
value|0x2000
end_define

begin_define
define|#
directive|define
name|XL_RESETOPT_INVERT_LED
value|0x0010
end_define

begin_define
define|#
directive|define
name|XL_RESETOPT_INVERT_MII
value|0x4000
end_define

begin_comment
comment|/*  * Window 3 (fifo management)  */
end_comment

begin_define
define|#
directive|define
name|XL_W3_INTERNAL_CFG
value|0x00
end_define

begin_define
define|#
directive|define
name|XL_W3_MAXPKTSIZE
value|0x04
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_define
define|#
directive|define
name|XL_W3_RESET_OPT
value|0x08
end_define

begin_define
define|#
directive|define
name|XL_W3_FREE_TX
value|0x0C
end_define

begin_define
define|#
directive|define
name|XL_W3_FREE_RX
value|0x0A
end_define

begin_define
define|#
directive|define
name|XL_W3_MAC_CTRL
value|0x06
end_define

begin_define
define|#
directive|define
name|XL_ICFG_CONNECTOR_MASK
value|0x00F00000
end_define

begin_define
define|#
directive|define
name|XL_ICFG_CONNECTOR_BITS
value|20
end_define

begin_define
define|#
directive|define
name|XL_ICFG_RAMSIZE_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|XL_ICFG_RAMWIDTH
value|0x00000008
end_define

begin_define
define|#
directive|define
name|XL_ICFG_ROMSIZE_MASK
value|(0x00000040 | 0x00000080)
end_define

begin_define
define|#
directive|define
name|XL_ICFG_DISABLE_BASSD
value|0x00000100
end_define

begin_define
define|#
directive|define
name|XL_ICFG_RAMLOC
value|0x00000200
end_define

begin_define
define|#
directive|define
name|XL_ICFG_RAMPART
value|(0x00010000 | 0x00020000)
end_define

begin_define
define|#
directive|define
name|XL_ICFG_XCVRSEL
value|(0x00100000 | 0x00200000 | 0x00400000)
end_define

begin_define
define|#
directive|define
name|XL_ICFG_AUTOSEL
value|0x01000000
end_define

begin_define
define|#
directive|define
name|XL_XCVR_10BT
value|0x00
end_define

begin_define
define|#
directive|define
name|XL_XCVR_AUI
value|0x01
end_define

begin_define
define|#
directive|define
name|XL_XCVR_RSVD_0
value|0x02
end_define

begin_define
define|#
directive|define
name|XL_XCVR_COAX
value|0x03
end_define

begin_define
define|#
directive|define
name|XL_XCVR_100BTX
value|0x04
end_define

begin_define
define|#
directive|define
name|XL_XCVR_100BFX
value|0x05
end_define

begin_define
define|#
directive|define
name|XL_XCVR_MII
value|0x06
end_define

begin_define
define|#
directive|define
name|XL_XCVR_RSVD_1
value|0x07
end_define

begin_define
define|#
directive|define
name|XL_XCVR_AUTO
value|0x08
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_define
define|#
directive|define
name|XL_MACCTRL_DEFER_EXT_END
value|0x0001
end_define

begin_define
define|#
directive|define
name|XL_MACCTRL_DEFER_0
value|0x0002
end_define

begin_define
define|#
directive|define
name|XL_MACCTRL_DEFER_1
value|0x0004
end_define

begin_define
define|#
directive|define
name|XL_MACCTRL_DEFER_2
value|0x0008
end_define

begin_define
define|#
directive|define
name|XL_MACCTRL_DEFER_3
value|0x0010
end_define

begin_define
define|#
directive|define
name|XL_MACCTRL_DUPLEX
value|0x0020
end_define

begin_define
define|#
directive|define
name|XL_MACCTRL_ALLOW_LARGE_PACK
value|0x0040
end_define

begin_define
define|#
directive|define
name|XL_MACCTRL_EXTEND_AFTER_COL
value|0x0080
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_define
define|#
directive|define
name|XL_MACCTRL_FLOW_CONTROL_ENB
value|0x0100
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_define
define|#
directive|define
name|XL_MACCTRL_VLT_END
value|0x0200
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_comment
comment|/*  * The 'reset options' register contains power-on reset values  * loaded from the EEPROM. This includes the supported media  * types on the card. It is also known as the media options register.  */
end_comment

begin_define
define|#
directive|define
name|XL_W3_MEDIA_OPT
value|0x08
end_define

begin_define
define|#
directive|define
name|XL_MEDIAOPT_BT4
value|0x0001
end_define

begin_comment
comment|/* MII */
end_comment

begin_define
define|#
directive|define
name|XL_MEDIAOPT_BTX
value|0x0002
end_define

begin_comment
comment|/* on-chip */
end_comment

begin_define
define|#
directive|define
name|XL_MEDIAOPT_BFX
value|0x0004
end_define

begin_comment
comment|/* on-chip */
end_comment

begin_define
define|#
directive|define
name|XL_MEDIAOPT_BT
value|0x0008
end_define

begin_comment
comment|/* on-chip */
end_comment

begin_define
define|#
directive|define
name|XL_MEDIAOPT_BNC
value|0x0010
end_define

begin_comment
comment|/* on-chip */
end_comment

begin_define
define|#
directive|define
name|XL_MEDIAOPT_AUI
value|0x0020
end_define

begin_comment
comment|/* on-chip */
end_comment

begin_define
define|#
directive|define
name|XL_MEDIAOPT_MII
value|0x0040
end_define

begin_comment
comment|/* MII */
end_comment

begin_define
define|#
directive|define
name|XL_MEDIAOPT_VCO
value|0x0100
end_define

begin_comment
comment|/* 1st gen chip only */
end_comment

begin_define
define|#
directive|define
name|XL_MEDIAOPT_10FL
value|0x0100
end_define

begin_comment
comment|/* 3x905B only, on-chip */
end_comment

begin_define
define|#
directive|define
name|XL_MEDIAOPT_MASK
value|0x01FF
end_define

begin_comment
comment|/*  * Window 4 (diagnostics)  */
end_comment

begin_define
define|#
directive|define
name|XL_W4_UPPERBYTESOK
value|0x0D
end_define

begin_define
define|#
directive|define
name|XL_W4_BADSSD
value|0x0C
end_define

begin_define
define|#
directive|define
name|XL_W4_MEDIA_STATUS
value|0x0A
end_define

begin_define
define|#
directive|define
name|XL_W4_PHY_MGMT
value|0x08
end_define

begin_define
define|#
directive|define
name|XL_W4_NET_DIAG
value|0x06
end_define

begin_define
define|#
directive|define
name|XL_W4_FIFO_DIAG
value|0x04
end_define

begin_define
define|#
directive|define
name|XL_W4_VCO_DIAG
value|0x02
end_define

begin_define
define|#
directive|define
name|XL_W4_CTRLR_STAT
value|0x08
end_define

begin_define
define|#
directive|define
name|XL_W4_TX_DIAG
value|0x00
end_define

begin_define
define|#
directive|define
name|XL_MII_CLK
value|0x01
end_define

begin_define
define|#
directive|define
name|XL_MII_DATA
value|0x02
end_define

begin_define
define|#
directive|define
name|XL_MII_DIR
value|0x04
end_define

begin_define
define|#
directive|define
name|XL_MEDIA_SQE
value|0x0008
end_define

begin_define
define|#
directive|define
name|XL_MEDIA_10TP
value|0x00C0
end_define

begin_define
define|#
directive|define
name|XL_MEDIA_LNK
value|0x0080
end_define

begin_define
define|#
directive|define
name|XL_MEDIA_LNKBEAT
value|0x0800
end_define

begin_define
define|#
directive|define
name|XL_MEDIASTAT_CRCSTRIP
value|0x0004
end_define

begin_define
define|#
directive|define
name|XL_MEDIASTAT_SQEENB
value|0x0008
end_define

begin_define
define|#
directive|define
name|XL_MEDIASTAT_COLDET
value|0x0010
end_define

begin_define
define|#
directive|define
name|XL_MEDIASTAT_CARRIER
value|0x0020
end_define

begin_define
define|#
directive|define
name|XL_MEDIASTAT_JABGUARD
value|0x0040
end_define

begin_define
define|#
directive|define
name|XL_MEDIASTAT_LINKBEAT
value|0x0080
end_define

begin_define
define|#
directive|define
name|XL_MEDIASTAT_JABDETECT
value|0x0200
end_define

begin_define
define|#
directive|define
name|XL_MEDIASTAT_POLREVERS
value|0x0400
end_define

begin_define
define|#
directive|define
name|XL_MEDIASTAT_LINKDETECT
value|0x0800
end_define

begin_define
define|#
directive|define
name|XL_MEDIASTAT_TXINPROG
value|0x1000
end_define

begin_define
define|#
directive|define
name|XL_MEDIASTAT_DCENB
value|0x4000
end_define

begin_define
define|#
directive|define
name|XL_MEDIASTAT_AUIDIS
value|0x8000
end_define

begin_define
define|#
directive|define
name|XL_NETDIAG_TEST_LOWVOLT
value|0x0001
end_define

begin_define
define|#
directive|define
name|XL_NETDIAG_ASIC_REVMASK
define|\
value|(0x0002 | 0x0004 | 0x0008 | 0x0010 | 0x0020)
end_define

begin_define
define|#
directive|define
name|XL_NETDIAG_UPPER_BYTES_ENABLE
value|0x0040
end_define

begin_define
define|#
directive|define
name|XL_NETDIAG_STATS_ENABLED
value|0x0080
end_define

begin_define
define|#
directive|define
name|XL_NETDIAG_TX_FATALERR
value|0x0100
end_define

begin_define
define|#
directive|define
name|XL_NETDIAG_TRANSMITTING
value|0x0200
end_define

begin_define
define|#
directive|define
name|XL_NETDIAG_RX_ENABLED
value|0x0400
end_define

begin_define
define|#
directive|define
name|XL_NETDIAG_TX_ENABLED
value|0x0800
end_define

begin_define
define|#
directive|define
name|XL_NETDIAG_FIFO_LOOPBACK
value|0x1000
end_define

begin_define
define|#
directive|define
name|XL_NETDIAG_MAC_LOOPBACK
value|0x2000
end_define

begin_define
define|#
directive|define
name|XL_NETDIAG_ENDEC_LOOPBACK
value|0x4000
end_define

begin_define
define|#
directive|define
name|XL_NETDIAG_EXTERNAL_LOOP
value|0x8000
end_define

begin_comment
comment|/*  * Window 5  */
end_comment

begin_define
define|#
directive|define
name|XL_W5_STAT_ENB
value|0x0C
end_define

begin_define
define|#
directive|define
name|XL_W5_INTR_ENB
value|0x0A
end_define

begin_define
define|#
directive|define
name|XL_W5_RECLAIM_THRESH
value|0x09
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_define
define|#
directive|define
name|XL_W5_RX_FILTER
value|0x08
end_define

begin_define
define|#
directive|define
name|XL_W5_RX_EARLYTHRESH
value|0x06
end_define

begin_define
define|#
directive|define
name|XL_W5_TX_AVAILTHRESH
value|0x02
end_define

begin_define
define|#
directive|define
name|XL_W5_TX_STARTTHRESH
value|0x00
end_define

begin_comment
comment|/*  * RX filter bits  */
end_comment

begin_define
define|#
directive|define
name|XL_RXFILTER_INDIVIDUAL
value|0x01
end_define

begin_define
define|#
directive|define
name|XL_RXFILTER_ALLMULTI
value|0x02
end_define

begin_define
define|#
directive|define
name|XL_RXFILTER_BROADCAST
value|0x04
end_define

begin_define
define|#
directive|define
name|XL_RXFILTER_ALLFRAMES
value|0x08
end_define

begin_define
define|#
directive|define
name|XL_RXFILTER_MULTIHASH
value|0x10
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_comment
comment|/*  * Window 6 (stats)  */
end_comment

begin_define
define|#
directive|define
name|XL_W6_TX_BYTES_OK
value|0x0C
end_define

begin_define
define|#
directive|define
name|XL_W6_RX_BYTES_OK
value|0x0A
end_define

begin_define
define|#
directive|define
name|XL_W6_UPPER_FRAMES_OK
value|0x09
end_define

begin_define
define|#
directive|define
name|XL_W6_DEFERRED
value|0x08
end_define

begin_define
define|#
directive|define
name|XL_W6_RX_OK
value|0x07
end_define

begin_define
define|#
directive|define
name|XL_W6_TX_OK
value|0x06
end_define

begin_define
define|#
directive|define
name|XL_W6_RX_OVERRUN
value|0x05
end_define

begin_define
define|#
directive|define
name|XL_W6_COL_LATE
value|0x04
end_define

begin_define
define|#
directive|define
name|XL_W6_COL_SINGLE
value|0x03
end_define

begin_define
define|#
directive|define
name|XL_W6_COL_MULTIPLE
value|0x02
end_define

begin_define
define|#
directive|define
name|XL_W6_SQE_ERRORS
value|0x01
end_define

begin_define
define|#
directive|define
name|XL_W6_CARRIER_LOST
value|0x00
end_define

begin_comment
comment|/*  * Window 7 (bus master control)  */
end_comment

begin_define
define|#
directive|define
name|XL_W7_BM_ADDR
value|0x00
end_define

begin_define
define|#
directive|define
name|XL_W7_BM_LEN
value|0x06
end_define

begin_define
define|#
directive|define
name|XL_W7_BM_STATUS
value|0x0B
end_define

begin_define
define|#
directive|define
name|XL_W7_BM_TIMEr
value|0x0A
end_define

begin_comment
comment|/*  * bus master control registers  */
end_comment

begin_define
define|#
directive|define
name|XL_BM_PKTSTAT
value|0x20
end_define

begin_define
define|#
directive|define
name|XL_BM_DOWNLISTPTR
value|0x24
end_define

begin_define
define|#
directive|define
name|XL_BM_FRAGADDR
value|0x28
end_define

begin_define
define|#
directive|define
name|XL_BM_FRAGLEN
value|0x2C
end_define

begin_define
define|#
directive|define
name|XL_BM_TXFREETHRESH
value|0x2F
end_define

begin_define
define|#
directive|define
name|XL_BM_UPPKTSTAT
value|0x30
end_define

begin_define
define|#
directive|define
name|XL_BM_UPLISTPTR
value|0x38
end_define

begin_define
define|#
directive|define
name|XL_LAST_FRAG
value|0x80000000
end_define

begin_define
define|#
directive|define
name|XL_MAXFRAGS
value|63
end_define

begin_define
define|#
directive|define
name|XL_RX_LIST_CNT
value|128
end_define

begin_define
define|#
directive|define
name|XL_TX_LIST_CNT
value|256
end_define

begin_define
define|#
directive|define
name|XL_RX_LIST_SZ
define|\
value|(XL_RX_LIST_CNT * sizeof(struct xl_list_onefrag))
end_define

begin_define
define|#
directive|define
name|XL_TX_LIST_SZ
define|\
value|(XL_TX_LIST_CNT * sizeof(struct xl_list))
end_define

begin_define
define|#
directive|define
name|XL_MIN_FRAMELEN
value|60
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
name|XL_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = (x + 1) % y
end_define

begin_comment
comment|/*  * Boomerang/Cyclone TX/RX list structure.  * For the TX lists, bits 0 to 12 of the status word indicate  * length.  * This looks suspiciously like the ThunderLAN, doesn't it.  */
end_comment

begin_struct
struct|struct
name|xl_frag
block|{
name|u_int32_t
name|xl_addr
decl_stmt|;
comment|/* 63 addr/len pairs */
name|u_int32_t
name|xl_len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xl_list
block|{
name|u_int32_t
name|xl_next
decl_stmt|;
comment|/* final entry has 0 nextptr */
name|u_int32_t
name|xl_status
decl_stmt|;
name|struct
name|xl_frag
name|xl_frag
index|[
name|XL_MAXFRAGS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xl_list_onefrag
block|{
name|u_int32_t
name|xl_next
decl_stmt|;
comment|/* final entry has 0 nextptr */
name|u_int32_t
name|xl_status
decl_stmt|;
name|struct
name|xl_frag
name|xl_frag
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xl_list_data
block|{
name|struct
name|xl_list_onefrag
modifier|*
name|xl_rx_list
decl_stmt|;
name|struct
name|xl_list
modifier|*
name|xl_tx_list
decl_stmt|;
name|u_int32_t
name|xl_rx_dmaaddr
decl_stmt|;
name|bus_dma_tag_t
name|xl_rx_tag
decl_stmt|;
name|bus_dmamap_t
name|xl_rx_dmamap
decl_stmt|;
name|u_int32_t
name|xl_tx_dmaaddr
decl_stmt|;
name|bus_dma_tag_t
name|xl_tx_tag
decl_stmt|;
name|bus_dmamap_t
name|xl_tx_dmamap
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xl_chain
block|{
name|struct
name|xl_list
modifier|*
name|xl_ptr
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|xl_mbuf
decl_stmt|;
name|struct
name|xl_chain
modifier|*
name|xl_next
decl_stmt|;
name|struct
name|xl_chain
modifier|*
name|xl_prev
decl_stmt|;
name|u_int32_t
name|xl_phys
decl_stmt|;
name|bus_dmamap_t
name|xl_map
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xl_chain_onefrag
block|{
name|struct
name|xl_list_onefrag
modifier|*
name|xl_ptr
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|xl_mbuf
decl_stmt|;
name|struct
name|xl_chain_onefrag
modifier|*
name|xl_next
decl_stmt|;
name|bus_dmamap_t
name|xl_map
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xl_chain_data
block|{
name|struct
name|xl_chain_onefrag
name|xl_rx_chain
index|[
name|XL_RX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|xl_chain
name|xl_tx_chain
index|[
name|XL_TX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|xl_chain_onefrag
modifier|*
name|xl_rx_head
decl_stmt|;
comment|/* 3c90x "boomerang" queuing stuff */
name|struct
name|xl_chain
modifier|*
name|xl_tx_head
decl_stmt|;
name|struct
name|xl_chain
modifier|*
name|xl_tx_tail
decl_stmt|;
name|struct
name|xl_chain
modifier|*
name|xl_tx_free
decl_stmt|;
comment|/* 3c90xB "cyclone/hurricane/tornado" stuff */
name|int
name|xl_tx_prod
decl_stmt|;
name|int
name|xl_tx_cons
decl_stmt|;
name|int
name|xl_tx_cnt
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|XL_RXSTAT_LENMASK
value|0x00001FFF
end_define

begin_define
define|#
directive|define
name|XL_RXSTAT_UP_ERROR
value|0x00004000
end_define

begin_define
define|#
directive|define
name|XL_RXSTAT_UP_CMPLT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|XL_RXSTAT_UP_OVERRUN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|XL_RXSTAT_RUNT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|XL_RXSTAT_ALIGN
value|0x00040000
end_define

begin_define
define|#
directive|define
name|XL_RXSTAT_CRC
value|0x00080000
end_define

begin_define
define|#
directive|define
name|XL_RXSTAT_OVERSIZE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|XL_RXSTAT_DRIBBLE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|XL_RXSTAT_UP_OFLOW
value|0x01000000
end_define

begin_define
define|#
directive|define
name|XL_RXSTAT_IPCKERR
value|0x02000000
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_define
define|#
directive|define
name|XL_RXSTAT_TCPCKERR
value|0x04000000
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_define
define|#
directive|define
name|XL_RXSTAT_UDPCKERR
value|0x08000000
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_define
define|#
directive|define
name|XL_RXSTAT_BUFEN
value|0x10000000
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_define
define|#
directive|define
name|XL_RXSTAT_IPCKOK
value|0x20000000
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_define
define|#
directive|define
name|XL_RXSTAT_TCPCOK
value|0x40000000
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_define
define|#
directive|define
name|XL_RXSTAT_UDPCKOK
value|0x80000000
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_define
define|#
directive|define
name|XL_TXSTAT_LENMASK
value|0x00001FFF
end_define

begin_define
define|#
directive|define
name|XL_TXSTAT_CRCDIS
value|0x00002000
end_define

begin_define
define|#
directive|define
name|XL_TXSTAT_TX_INTR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|XL_TXSTAT_DL_COMPLETE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|XL_TXSTAT_IPCKSUM
value|0x02000000
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_define
define|#
directive|define
name|XL_TXSTAT_TCPCKSUM
value|0x04000000
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_define
define|#
directive|define
name|XL_TXSTAT_UDPCKSUM
value|0x08000000
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_define
define|#
directive|define
name|XL_TXSTAT_RND_DEFEAT
value|0x10000000
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_define
define|#
directive|define
name|XL_TXSTAT_EMPTY
value|0x20000000
end_define

begin_comment
comment|/* 3c905B only */
end_comment

begin_define
define|#
directive|define
name|XL_TXSTAT_DL_INTR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|XL_CAPABILITY_BM
value|0x20
end_define

begin_struct
struct|struct
name|xl_type
block|{
name|u_int16_t
name|xl_vid
decl_stmt|;
name|u_int16_t
name|xl_did
decl_stmt|;
name|char
modifier|*
name|xl_name
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xl_mii_frame
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
name|XL_MII_STARTDELIM
value|0x01
end_define

begin_define
define|#
directive|define
name|XL_MII_READOP
value|0x02
end_define

begin_define
define|#
directive|define
name|XL_MII_WRITEOP
value|0x01
end_define

begin_define
define|#
directive|define
name|XL_MII_TURNAROUND
value|0x02
end_define

begin_comment
comment|/*  * The 3C905B adapters implement a few features that we want to  * take advantage of, namely the multicast hash filter. With older  * chips, you only have the option of turning on reception of all  * multicast frames, which is kind of lame.  *  * We also use this to decide on a transmit strategy. For the 3c90xB  * cards, we can use polled descriptor mode, which reduces CPU overhead.  */
end_comment

begin_define
define|#
directive|define
name|XL_TYPE_905B
value|1
end_define

begin_define
define|#
directive|define
name|XL_TYPE_90X
value|2
end_define

begin_define
define|#
directive|define
name|XL_FLAG_FUNCREG
value|0x0001
end_define

begin_define
define|#
directive|define
name|XL_FLAG_PHYOK
value|0x0002
end_define

begin_define
define|#
directive|define
name|XL_FLAG_EEPROM_OFFSET_30
value|0x0004
end_define

begin_define
define|#
directive|define
name|XL_FLAG_WEIRDRESET
value|0x0008
end_define

begin_define
define|#
directive|define
name|XL_FLAG_8BITROM
value|0x0010
end_define

begin_define
define|#
directive|define
name|XL_FLAG_INVERT_LED_PWR
value|0x0020
end_define

begin_define
define|#
directive|define
name|XL_FLAG_INVERT_MII_PWR
value|0x0040
end_define

begin_define
define|#
directive|define
name|XL_FLAG_NO_XCVR_PWR
value|0x0080
end_define

begin_define
define|#
directive|define
name|XL_FLAG_USE_MMIO
value|0x0100
end_define

begin_define
define|#
directive|define
name|XL_FLAG_NO_MMIO
value|0x0200
end_define

begin_define
define|#
directive|define
name|XL_NO_XCVR_PWR_MAGICBITS
value|0x0900
end_define

begin_struct
struct|struct
name|xl_softc
block|{
name|struct
name|ifnet
modifier|*
name|xl_ifp
decl_stmt|;
comment|/* interface info */
name|device_t
name|xl_dev
decl_stmt|;
comment|/* device info */
name|struct
name|ifmedia
name|ifmedia
decl_stmt|;
comment|/* media info */
name|bus_space_handle_t
name|xl_bhandle
decl_stmt|;
name|bus_space_tag_t
name|xl_btag
decl_stmt|;
name|void
modifier|*
name|xl_intrhand
decl_stmt|;
name|struct
name|resource
modifier|*
name|xl_irq
decl_stmt|;
name|struct
name|resource
modifier|*
name|xl_res
decl_stmt|;
name|device_t
name|xl_miibus
decl_stmt|;
name|struct
name|xl_type
modifier|*
name|xl_info
decl_stmt|;
comment|/* 3Com adapter info */
name|bus_dma_tag_t
name|xl_mtag
decl_stmt|;
name|bus_dmamap_t
name|xl_tmpmap
decl_stmt|;
comment|/* spare DMA map */
name|u_int8_t
name|xl_unit
decl_stmt|;
comment|/* interface number */
name|u_int8_t
name|xl_type
decl_stmt|;
name|u_int32_t
name|xl_xcvr
decl_stmt|;
name|u_int16_t
name|xl_media
decl_stmt|;
name|u_int16_t
name|xl_caps
decl_stmt|;
name|u_int8_t
name|xl_stats_no_timeout
decl_stmt|;
name|u_int16_t
name|xl_tx_thresh
decl_stmt|;
name|int
name|xl_if_flags
decl_stmt|;
name|struct
name|xl_list_data
name|xl_ldata
decl_stmt|;
name|struct
name|xl_chain_data
name|xl_cdata
decl_stmt|;
name|struct
name|callout
name|xl_stat_callout
decl_stmt|;
name|int
name|xl_wdog_timer
decl_stmt|;
name|int
name|xl_flags
decl_stmt|;
name|struct
name|resource
modifier|*
name|xl_fres
decl_stmt|;
name|bus_space_handle_t
name|xl_fhandle
decl_stmt|;
name|bus_space_tag_t
name|xl_ftag
decl_stmt|;
name|struct
name|mtx
name|xl_mtx
decl_stmt|;
name|struct
name|task
name|xl_task
decl_stmt|;
ifdef|#
directive|ifdef
name|DEVICE_POLLING
name|int
name|rxcycles
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|XL_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->xl_mtx)
end_define

begin_define
define|#
directive|define
name|XL_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->xl_mtx)
end_define

begin_define
define|#
directive|define
name|XL_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->xl_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|xl_rx_goodframes
parameter_list|(
name|x
parameter_list|)
define|\
value|((x.xl_upper_frames_ok& 0x03)<< 8) | x.xl_rx_frames_ok
end_define

begin_define
define|#
directive|define
name|xl_tx_goodframes
parameter_list|(
name|x
parameter_list|)
define|\
value|((x.xl_upper_frames_ok& 0x30)<< 4) | x.xl_tx_frames_ok
end_define

begin_struct
struct|struct
name|xl_stats
block|{
name|u_int8_t
name|xl_carrier_lost
decl_stmt|;
name|u_int8_t
name|xl_sqe_errs
decl_stmt|;
name|u_int8_t
name|xl_tx_multi_collision
decl_stmt|;
name|u_int8_t
name|xl_tx_single_collision
decl_stmt|;
name|u_int8_t
name|xl_tx_late_collision
decl_stmt|;
name|u_int8_t
name|xl_rx_overrun
decl_stmt|;
name|u_int8_t
name|xl_tx_frames_ok
decl_stmt|;
name|u_int8_t
name|xl_rx_frames_ok
decl_stmt|;
name|u_int8_t
name|xl_tx_deferred
decl_stmt|;
name|u_int8_t
name|xl_upper_frames_ok
decl_stmt|;
name|u_int16_t
name|xl_rx_bytes_ok
decl_stmt|;
name|u_int16_t
name|xl_tx_bytes_ok
decl_stmt|;
name|u_int16_t
name|status
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
value|bus_space_write_4(sc->xl_btag, sc->xl_bhandle, reg, val)
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
value|bus_space_write_2(sc->xl_btag, sc->xl_bhandle, reg, val)
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
value|bus_space_write_1(sc->xl_btag, sc->xl_bhandle, reg, val)
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
value|bus_space_read_4(sc->xl_btag, sc->xl_bhandle, reg)
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
value|bus_space_read_2(sc->xl_btag, sc->xl_bhandle, reg)
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
value|bus_space_read_1(sc->xl_btag, sc->xl_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|XL_SEL_WIN
parameter_list|(
name|x
parameter_list|)
define|\
value|CSR_WRITE_2(sc, XL_COMMAND, XL_CMD_WINSEL | x)
end_define

begin_define
define|#
directive|define
name|XL_TIMEOUT
value|1000
end_define

begin_comment
comment|/*  * General constants that are fun to know.  *  * 3Com PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|TC_VENDORID
value|0x10B7
end_define

begin_comment
comment|/*  * 3Com chip device IDs.  */
end_comment

begin_define
define|#
directive|define
name|TC_DEVICEID_BOOMERANG_10BT
value|0x9000
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_BOOMERANG_10BT_COMBO
value|0x9001
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_BOOMERANG_10_100BT
value|0x9050
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_BOOMERANG_100BT4
value|0x9051
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_KRAKATOA_10BT
value|0x9004
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_KRAKATOA_10BT_COMBO
value|0x9005
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_KRAKATOA_10BT_TPC
value|0x9006
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_CYCLONE_10FL
value|0x900A
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_HURRICANE_10_100BT
value|0x9055
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_CYCLONE_10_100BT4
value|0x9056
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_CYCLONE_10_100_COMBO
value|0x9058
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_CYCLONE_10_100FX
value|0x905A
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_TORNADO_10_100BT
value|0x9200
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_TORNADO_10_100BT_920B
value|0x9201
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_TORNADO_10_100BT_920B_WNM
value|0x9202
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_HURRICANE_10_100BT_SERV
value|0x9800
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_TORNADO_10_100BT_SERV
value|0x9805
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_HURRICANE_SOHO100TX
value|0x7646
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_TORNADO_HOMECONNECT
value|0x4500
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_HURRICANE_555
value|0x5055
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_HURRICANE_556
value|0x6055
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_HURRICANE_556B
value|0x6056
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_HURRICANE_575A
value|0x5057
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_HURRICANE_575B
value|0x5157
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_HURRICANE_575C
value|0x5257
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_HURRICANE_656
value|0x6560
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_HURRICANE_656B
value|0x6562
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_TORNADO_656C
value|0x6564
end_define

begin_comment
comment|/*  * PCI low memory base and low I/O base register, and  * other PCI registers. Note: some are only available on  * the 3c905B, in particular those that related to power management.  */
end_comment

begin_define
define|#
directive|define
name|XL_PCI_VENDOR_ID
value|0x00
end_define

begin_define
define|#
directive|define
name|XL_PCI_DEVICE_ID
value|0x02
end_define

begin_define
define|#
directive|define
name|XL_PCI_COMMAND
value|0x04
end_define

begin_define
define|#
directive|define
name|XL_PCI_STATUS
value|0x06
end_define

begin_define
define|#
directive|define
name|XL_PCI_CLASSCODE
value|0x09
end_define

begin_define
define|#
directive|define
name|XL_PCI_LATENCY_TIMER
value|0x0D
end_define

begin_define
define|#
directive|define
name|XL_PCI_HEADER_TYPE
value|0x0E
end_define

begin_define
define|#
directive|define
name|XL_PCI_LOIO
value|0x10
end_define

begin_define
define|#
directive|define
name|XL_PCI_LOMEM
value|0x14
end_define

begin_define
define|#
directive|define
name|XL_PCI_FUNCMEM
value|0x18
end_define

begin_define
define|#
directive|define
name|XL_PCI_BIOSROM
value|0x30
end_define

begin_define
define|#
directive|define
name|XL_PCI_INTLINE
value|0x3C
end_define

begin_define
define|#
directive|define
name|XL_PCI_INTPIN
value|0x3D
end_define

begin_define
define|#
directive|define
name|XL_PCI_MINGNT
value|0x3E
end_define

begin_define
define|#
directive|define
name|XL_PCI_MINLAT
value|0x0F
end_define

begin_define
define|#
directive|define
name|XL_PCI_RESETOPT
value|0x48
end_define

begin_define
define|#
directive|define
name|XL_PCI_EEPROM_DATA
value|0x4C
end_define

begin_comment
comment|/* 3c905B-only registers */
end_comment

begin_define
define|#
directive|define
name|XL_PCI_CAPID
value|0xDC
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|XL_PCI_NEXTPTR
value|0xDD
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|XL_PCI_PWRMGMTCAP
value|0xDE
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|XL_PCI_PWRMGMTCTRL
value|0xE0
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|XL_PSTATE_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|XL_PSTATE_D0
value|0x0000
end_define

begin_define
define|#
directive|define
name|XL_PSTATE_D1
value|0x0002
end_define

begin_define
define|#
directive|define
name|XL_PSTATE_D2
value|0x0002
end_define

begin_define
define|#
directive|define
name|XL_PSTATE_D3
value|0x0003
end_define

begin_define
define|#
directive|define
name|XL_PME_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|XL_PME_STATUS
value|0x8000
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IFM_10_FL
end_ifndef

begin_define
define|#
directive|define
name|IFM_10_FL
value|13
end_define

begin_comment
comment|/* 10baseFL - Fiber */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

