begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998, 1999, 2000  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Registers and data structures for the XaQti Corporation XMAC II  * Gigabit Ethernet MAC. Datasheet is available from http://www.xaqti.com.  * The XMAC can be programmed for 16-bit or 32-bit register access modes.  * The SysKonnect gigabit ethernet adapters use 16-bit mode, so that's  * how the registers are laid out here.  */
end_comment

begin_define
define|#
directive|define
name|XM_DEVICEID
value|0x00E0AE20
end_define

begin_define
define|#
directive|define
name|XM_XAQTI_OUI
value|0x00E0AE
end_define

begin_define
define|#
directive|define
name|XM_XMAC_REV
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x000000E0)>> 5)
end_define

begin_define
define|#
directive|define
name|XM_XMAC_REV_B2
value|0x0
end_define

begin_define
define|#
directive|define
name|XM_XMAC_REV_C1
value|0x1
end_define

begin_define
define|#
directive|define
name|XM_MMUCMD
value|0x0000
end_define

begin_define
define|#
directive|define
name|XM_POFF
value|0x0008
end_define

begin_define
define|#
directive|define
name|XM_BURST
value|0x000C
end_define

begin_define
define|#
directive|define
name|XM_VLAN_TAGLEV1
value|0x0010
end_define

begin_define
define|#
directive|define
name|XM_VLAN_TAGLEV2
value|0x0014
end_define

begin_define
define|#
directive|define
name|XM_TXCMD
value|0x0020
end_define

begin_define
define|#
directive|define
name|XM_TX_RETRYLIMIT
value|0x0024
end_define

begin_define
define|#
directive|define
name|XM_TX_SLOTTIME
value|0x0028
end_define

begin_define
define|#
directive|define
name|XM_TX_IPG
value|0x003C
end_define

begin_define
define|#
directive|define
name|XM_RXCMD
value|0x0030
end_define

begin_define
define|#
directive|define
name|XM_PHY_ADDR
value|0x0034
end_define

begin_define
define|#
directive|define
name|XM_PHY_DATA
value|0x0038
end_define

begin_define
define|#
directive|define
name|XM_GPIO
value|0x0040
end_define

begin_define
define|#
directive|define
name|XM_IMR
value|0x0044
end_define

begin_define
define|#
directive|define
name|XM_ISR
value|0x0048
end_define

begin_define
define|#
directive|define
name|XM_HWCFG
value|0x004C
end_define

begin_define
define|#
directive|define
name|XM_TX_LOWAT
value|0x0060
end_define

begin_define
define|#
directive|define
name|XM_TX_HIWAT
value|0x0062
end_define

begin_define
define|#
directive|define
name|XM_TX_REQTHRESH_LO
value|0x0064
end_define

begin_define
define|#
directive|define
name|XM_TX_REQTHRESH_HI
value|0x0066
end_define

begin_define
define|#
directive|define
name|XM_TX_REQTHRESH
value|XM_TX_REQTHRESH_LO
end_define

begin_define
define|#
directive|define
name|XM_PAUSEDST0
value|0x0068
end_define

begin_define
define|#
directive|define
name|XM_PAUSEDST1
value|0x006A
end_define

begin_define
define|#
directive|define
name|XM_PAUSEDST2
value|0x006C
end_define

begin_define
define|#
directive|define
name|XM_CTLPARM_LO
value|0x0070
end_define

begin_define
define|#
directive|define
name|XM_CTLPARM_HI
value|0x0072
end_define

begin_define
define|#
directive|define
name|XM_CTLPARM
value|XM_CTLPARM_LO
end_define

begin_define
define|#
directive|define
name|XM_OPCODE_PAUSE_TIMER
value|0x0074
end_define

begin_define
define|#
directive|define
name|XM_TXSTAT_LIFO
value|0x0078
end_define

begin_comment
comment|/*  * Perfect filter registers. The XMAC has a table of 16 perfect  * filter entries, spaced 8 bytes apart. This is in addition to  * the station address registers, which appear below.  */
end_comment

begin_define
define|#
directive|define
name|XM_RXFILT_BASE
value|0x0080
end_define

begin_define
define|#
directive|define
name|XM_RXFILT_END
value|0x0107
end_define

begin_define
define|#
directive|define
name|XM_RXFILT_MAX
value|16
end_define

begin_define
define|#
directive|define
name|XM_RXFILT_ENTRY
parameter_list|(
name|ent
parameter_list|)
value|(XM_RXFILT_BASE + ((ent * 8)))
end_define

begin_comment
comment|/* Primary station address. */
end_comment

begin_define
define|#
directive|define
name|XM_PAR0
value|0x0108
end_define

begin_define
define|#
directive|define
name|XM_PAR1
value|0x010A
end_define

begin_define
define|#
directive|define
name|XM_PAR2
value|0x010C
end_define

begin_comment
comment|/* 64-bit multicast hash table registers */
end_comment

begin_define
define|#
directive|define
name|XM_MAR0
value|0x0110
end_define

begin_define
define|#
directive|define
name|XM_MAR1
value|0x0112
end_define

begin_define
define|#
directive|define
name|XM_MAR2
value|0x0114
end_define

begin_define
define|#
directive|define
name|XM_MAR3
value|0x0116
end_define

begin_define
define|#
directive|define
name|XM_RX_LOWAT
value|0x0118
end_define

begin_define
define|#
directive|define
name|XM_RX_HIWAT
value|0x011A
end_define

begin_define
define|#
directive|define
name|XM_RX_REQTHRESH_LO
value|0x011C
end_define

begin_define
define|#
directive|define
name|XM_RX_REQTHRESH_HI
value|0x011E
end_define

begin_define
define|#
directive|define
name|XM_RX_REQTHRESH
value|XM_RX_REQTHRESH_LO
end_define

begin_define
define|#
directive|define
name|XM_DEVID_LO
value|0x0120
end_define

begin_define
define|#
directive|define
name|XM_DEVID_HI
value|0x0122
end_define

begin_define
define|#
directive|define
name|XM_DEVID
value|XM_DEVID_LO
end_define

begin_define
define|#
directive|define
name|XM_MODE_LO
value|0x0124
end_define

begin_define
define|#
directive|define
name|XM_MODE_HI
value|0x0126
end_define

begin_define
define|#
directive|define
name|XM_MODE
value|XM_MODE_LO
end_define

begin_define
define|#
directive|define
name|XM_LASTSRC0
value|0x0128
end_define

begin_define
define|#
directive|define
name|XM_LASTSRC1
value|0x012A
end_define

begin_define
define|#
directive|define
name|XM_LASTSRC2
value|0x012C
end_define

begin_define
define|#
directive|define
name|XM_TSTAMP_READ
value|0x0130
end_define

begin_define
define|#
directive|define
name|XM_TSTAMP_LOAD
value|0x0134
end_define

begin_define
define|#
directive|define
name|XM_STATS_CMD
value|0x0200
end_define

begin_define
define|#
directive|define
name|XM_RXCNT_EVENT_LO
value|0x0204
end_define

begin_define
define|#
directive|define
name|XM_RXCNT_EVENT_HI
value|0x0206
end_define

begin_define
define|#
directive|define
name|XM_RXCNT_EVENT
value|XM_RXCNT_EVENT_LO
end_define

begin_define
define|#
directive|define
name|XM_TXCNT_EVENT_LO
value|0x0208
end_define

begin_define
define|#
directive|define
name|XM_TXCNT_EVENT_HI
value|0x020A
end_define

begin_define
define|#
directive|define
name|XM_TXCNT_EVENT
value|XM_TXCNT_EVENT_LO
end_define

begin_define
define|#
directive|define
name|XM_RXCNT_EVMASK_LO
value|0x020C
end_define

begin_define
define|#
directive|define
name|XM_RXCNT_EVMASK_HI
value|0x020E
end_define

begin_define
define|#
directive|define
name|XM_RXCNT_EVMASK
value|XM_RXCNT_EVMASK_LO
end_define

begin_define
define|#
directive|define
name|XM_TXCNT_EVMASK_LO
value|0x0210
end_define

begin_define
define|#
directive|define
name|XM_TXCNT_EVMASK_HI
value|0x0212
end_define

begin_define
define|#
directive|define
name|XM_TXCNT_EVMASK
value|XM_TXCNT_EVMASK_LO
end_define

begin_comment
comment|/* Statistics command register */
end_comment

begin_define
define|#
directive|define
name|XM_STATCMD_CLR_TX
value|0x0001
end_define

begin_define
define|#
directive|define
name|XM_STATCMD_CLR_RX
value|0x0002
end_define

begin_define
define|#
directive|define
name|XM_STATCMD_COPY_TX
value|0x0004
end_define

begin_define
define|#
directive|define
name|XM_STATCMD_COPY_RX
value|0x0008
end_define

begin_define
define|#
directive|define
name|XM_STATCMD_SNAP_TX
value|0x0010
end_define

begin_define
define|#
directive|define
name|XM_STATCMD_SNAP_RX
value|0x0020
end_define

begin_comment
comment|/* TX statistics registers */
end_comment

begin_define
define|#
directive|define
name|XM_TXSTATS_PKTSOK
value|0x280
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_BYTESOK_HI
value|0x284
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_BYTESOK_LO
value|0x288
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_BCASTSOK
value|0x28C
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_MCASTSOK
value|0x290
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_UCASTSOK
value|0x294
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_GIANTS
value|0x298
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_BURSTCNT
value|0x29C
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_PAUSEPKTS
value|0x2A0
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_MACCTLPKTS
value|0x2A4
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_SINGLECOLS
value|0x2A8
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_MULTICOLS
value|0x2AC
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_EXCESSCOLS
value|0x2B0
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_LATECOLS
value|0x2B4
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_DEFER
value|0x2B8
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_EXCESSDEFER
value|0x2BC
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_UNDERRUN
value|0x2C0
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_CARRIERSENSE
value|0x2C4
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_UTILIZATION
value|0x2C8
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_64
value|0x2D0
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_65_127
value|0x2D4
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_128_255
value|0x2D8
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_256_511
value|0x2DC
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_512_1023
value|0x2E0
end_define

begin_define
define|#
directive|define
name|XM_TXSTATS_1024_MAX
value|0x2E4
end_define

begin_comment
comment|/* RX statistics registers */
end_comment

begin_define
define|#
directive|define
name|XM_RXSTATS_PKTSOK
value|0x300
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_BYTESOK_HI
value|0x304
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_BYTESOK_LO
value|0x308
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_BCASTSOK
value|0x30C
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_MCASTSOK
value|0x310
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_UCASTSOK
value|0x314
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_PAUSEPKTS
value|0x318
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_MACCTLPKTS
value|0x31C
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_BADPAUSEPKTS
value|0x320
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_BADMACCTLPKTS
value|0x324
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_BURSTCNT
value|0x328
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_MISSEDPKTS
value|0x32C
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_FRAMEERRS
value|0x330
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_OVERRUN
value|0x334
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_JABBER
value|0x338
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_CARRLOSS
value|0x33C
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_INRNGLENERR
value|0x340
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_SYMERR
value|0x344
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_SHORTEVENT
value|0x348
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_RUNTS
value|0x34C
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_GIANTS
value|0x350
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_CRCERRS
value|0x354
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_CEXTERRS
value|0x35C
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_UTILIZATION
value|0x360
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_64
value|0x368
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_65_127
value|0x36C
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_128_255
value|0x370
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_256_511
value|0x374
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_512_1023
value|0x378
end_define

begin_define
define|#
directive|define
name|XM_RXSTATS_1024_MAX
value|0x37C
end_define

begin_define
define|#
directive|define
name|XM_MMUCMD_TX_ENB
value|0x0001
end_define

begin_define
define|#
directive|define
name|XM_MMUCMD_RX_ENB
value|0x0002
end_define

begin_define
define|#
directive|define
name|XM_MMUCMD_GMIILOOP
value|0x0004
end_define

begin_define
define|#
directive|define
name|XM_MMUCMD_RATECTL
value|0x0008
end_define

begin_define
define|#
directive|define
name|XM_MMUCMD_GMIIFDX
value|0x0010
end_define

begin_define
define|#
directive|define
name|XM_MMUCMD_NO_MGMT_PRMB
value|0x0020
end_define

begin_define
define|#
directive|define
name|XM_MMUCMD_SIMCOL
value|0x0040
end_define

begin_define
define|#
directive|define
name|XM_MMUCMD_FORCETX
value|0x0080
end_define

begin_define
define|#
directive|define
name|XM_MMUCMD_LOOPENB
value|0x0200
end_define

begin_define
define|#
directive|define
name|XM_MMUCMD_IGNPAUSE
value|0x0400
end_define

begin_define
define|#
directive|define
name|XM_MMUCMD_PHYBUSY
value|0x0800
end_define

begin_define
define|#
directive|define
name|XM_MMUCMD_PHYDATARDY
value|0x1000
end_define

begin_define
define|#
directive|define
name|XM_TXCMD_AUTOPAD
value|0x0001
end_define

begin_define
define|#
directive|define
name|XM_TXCMD_NOCRC
value|0x0002
end_define

begin_define
define|#
directive|define
name|XM_TXCMD_NOPREAMBLE
value|0x0004
end_define

begin_define
define|#
directive|define
name|XM_TXCMD_NOGIGAMODE
value|0x0008
end_define

begin_define
define|#
directive|define
name|XM_TXCMD_SAMPLELINE
value|0x0010
end_define

begin_define
define|#
directive|define
name|XM_TXCMD_ENCBYPASS
value|0x0020
end_define

begin_define
define|#
directive|define
name|XM_TXCMD_XMITBK2BK
value|0x0040
end_define

begin_define
define|#
directive|define
name|XM_TXCMD_FAIRSHARE
value|0x0080
end_define

begin_define
define|#
directive|define
name|XM_RXCMD_DISABLE_CEXT
value|0x0001
end_define

begin_define
define|#
directive|define
name|XM_RXCMD_STRIPPAD
value|0x0002
end_define

begin_define
define|#
directive|define
name|XM_RXCMD_SAMPLELINE
value|0x0004
end_define

begin_define
define|#
directive|define
name|XM_RXCMD_SELFRX
value|0x0008
end_define

begin_define
define|#
directive|define
name|XM_RXCMD_STRIPFCS
value|0x0010
end_define

begin_define
define|#
directive|define
name|XM_RXCMD_TRANSPARENT
value|0x0020
end_define

begin_define
define|#
directive|define
name|XM_RXCMD_IPGCAPTURE
value|0x0040
end_define

begin_define
define|#
directive|define
name|XM_RXCMD_BIGPKTOK
value|0x0080
end_define

begin_define
define|#
directive|define
name|XM_RXCMD_LENERROK
value|0x0100
end_define

begin_define
define|#
directive|define
name|XM_GPIO_GP0_SET
value|0x0001
end_define

begin_define
define|#
directive|define
name|XM_GPIO_RESETSTATS
value|0x0004
end_define

begin_define
define|#
directive|define
name|XM_GPIO_RESETMAC
value|0x0008
end_define

begin_define
define|#
directive|define
name|XM_GPIO_FORCEINT
value|0x0020
end_define

begin_define
define|#
directive|define
name|XM_GPIO_ANEGINPROG
value|0x0040
end_define

begin_define
define|#
directive|define
name|XM_IMR_RX_EOF
value|0x0001
end_define

begin_define
define|#
directive|define
name|XM_IMR_TX_EOF
value|0x0002
end_define

begin_define
define|#
directive|define
name|XM_IMR_TX_UNDERRUN
value|0x0004
end_define

begin_define
define|#
directive|define
name|XM_IMR_RX_OVERRUN
value|0x0008
end_define

begin_define
define|#
directive|define
name|XM_IMR_TX_STATS_OFLOW
value|0x0010
end_define

begin_define
define|#
directive|define
name|XM_IMR_RX_STATS_OFLOW
value|0x0020
end_define

begin_define
define|#
directive|define
name|XM_IMR_TSTAMP_OFLOW
value|0x0040
end_define

begin_define
define|#
directive|define
name|XM_IMR_AUTONEG_DONE
value|0x0080
end_define

begin_define
define|#
directive|define
name|XM_IMR_NEXTPAGE_RDY
value|0x0100
end_define

begin_define
define|#
directive|define
name|XM_IMR_PAGE_RECEIVED
value|0x0200
end_define

begin_define
define|#
directive|define
name|XM_IMR_LP_REQCFG
value|0x0400
end_define

begin_define
define|#
directive|define
name|XM_IMR_GP0_SET
value|0x0800
end_define

begin_define
define|#
directive|define
name|XM_IMR_FORCEINTR
value|0x1000
end_define

begin_define
define|#
directive|define
name|XM_IMR_TX_ABORT
value|0x2000
end_define

begin_define
define|#
directive|define
name|XM_IMR_LINKEVENT
value|0x4000
end_define

begin_define
define|#
directive|define
name|XM_INTRS
define|\
value|(~(XM_IMR_GP0_SET|XM_IMR_AUTONEG_DONE|XM_IMR_TX_UNDERRUN))
end_define

begin_define
define|#
directive|define
name|XM_ISR_RX_EOF
value|0x0001
end_define

begin_define
define|#
directive|define
name|XM_ISR_TX_EOF
value|0x0002
end_define

begin_define
define|#
directive|define
name|XM_ISR_TX_UNDERRUN
value|0x0004
end_define

begin_define
define|#
directive|define
name|XM_ISR_RX_OVERRUN
value|0x0008
end_define

begin_define
define|#
directive|define
name|XM_ISR_TX_STATS_OFLOW
value|0x0010
end_define

begin_define
define|#
directive|define
name|XM_ISR_RX_STATS_OFLOW
value|0x0020
end_define

begin_define
define|#
directive|define
name|XM_ISR_TSTAMP_OFLOW
value|0x0040
end_define

begin_define
define|#
directive|define
name|XM_ISR_AUTONEG_DONE
value|0x0080
end_define

begin_define
define|#
directive|define
name|XM_ISR_NEXTPAGE_RDY
value|0x0100
end_define

begin_define
define|#
directive|define
name|XM_ISR_PAGE_RECEIVED
value|0x0200
end_define

begin_define
define|#
directive|define
name|XM_ISR_LP_REQCFG
value|0x0400
end_define

begin_define
define|#
directive|define
name|XM_ISR_GP0_SET
value|0x0800
end_define

begin_define
define|#
directive|define
name|XM_ISR_FORCEINTR
value|0x1000
end_define

begin_define
define|#
directive|define
name|XM_ISR_TX_ABORT
value|0x2000
end_define

begin_define
define|#
directive|define
name|XM_ISR_LINKEVENT
value|0x4000
end_define

begin_define
define|#
directive|define
name|XM_HWCFG_GENEOP
value|0x0008
end_define

begin_define
define|#
directive|define
name|XM_HWCFG_SIGSTATCKH
value|0x0004
end_define

begin_define
define|#
directive|define
name|XM_HWCFG_GMIIMODE
value|0x0001
end_define

begin_define
define|#
directive|define
name|XM_MODE_FLUSH_RXFIFO
value|0x00000001
end_define

begin_define
define|#
directive|define
name|XM_MODE_FLUSH_TXFIFO
value|0x00000002
end_define

begin_define
define|#
directive|define
name|XM_MODE_BIGENDIAN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|XM_MODE_RX_PROMISC
value|0x00000008
end_define

begin_define
define|#
directive|define
name|XM_MODE_RX_NOBROAD
value|0x00000010
end_define

begin_define
define|#
directive|define
name|XM_MODE_RX_NOMULTI
value|0x00000020
end_define

begin_define
define|#
directive|define
name|XM_MODE_RX_NOUNI
value|0x00000040
end_define

begin_define
define|#
directive|define
name|XM_MODE_RX_BADFRAMES
value|0x00000080
end_define

begin_define
define|#
directive|define
name|XM_MODE_RX_CRCERRS
value|0x00000100
end_define

begin_define
define|#
directive|define
name|XM_MODE_RX_GIANTS
value|0x00000200
end_define

begin_define
define|#
directive|define
name|XM_MODE_RX_INRANGELEN
value|0x00000400
end_define

begin_define
define|#
directive|define
name|XM_MODE_RX_RUNTS
value|0x00000800
end_define

begin_define
define|#
directive|define
name|XM_MODE_RX_MACCTL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|XM_MODE_RX_USE_PERFECT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|XM_MODE_RX_USE_STATION
value|0x00004000
end_define

begin_define
define|#
directive|define
name|XM_MODE_RX_USE_HASH
value|0x00008000
end_define

begin_define
define|#
directive|define
name|XM_MODE_RX_ADDRPAIR
value|0x00010000
end_define

begin_define
define|#
directive|define
name|XM_MODE_PAUSEONHI
value|0x00020000
end_define

begin_define
define|#
directive|define
name|XM_MODE_PAUSEONLO
value|0x00040000
end_define

begin_define
define|#
directive|define
name|XM_MODE_TIMESTAMP
value|0x00080000
end_define

begin_define
define|#
directive|define
name|XM_MODE_SENDPAUSE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|XM_MODE_SENDCONTINUOUS
value|0x00200000
end_define

begin_define
define|#
directive|define
name|XM_MODE_LE_STATUSWORD
value|0x00400000
end_define

begin_define
define|#
directive|define
name|XM_MODE_AUTOFIFOPAUSE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|XM_MODE_EXPAUSEGEN
value|0x02000000
end_define

begin_define
define|#
directive|define
name|XM_MODE_RX_INVERSE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|XM_RXSTAT_MACCTL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|XM_RXSTAT_ERRFRAME
value|0x00000002
end_define

begin_define
define|#
directive|define
name|XM_RXSTAT_CRCERR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|XM_RXSTAT_GIANT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|XM_RXSTAT_RUNT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|XM_RXSTAT_FRAMEERR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|XM_RXSTAT_INRANGEERR
value|0x00000040
end_define

begin_define
define|#
directive|define
name|XM_RXSTAT_CARRIERERR
value|0x00000080
end_define

begin_define
define|#
directive|define
name|XM_RXSTAT_COLLERR
value|0x00000100
end_define

begin_define
define|#
directive|define
name|XM_RXSTAT_802_3
value|0x00000200
end_define

begin_define
define|#
directive|define
name|XM_RXSTAT_CARREXTERR
value|0x00000400
end_define

begin_define
define|#
directive|define
name|XM_RXSTAT_BURSTMODE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|XM_RXSTAT_UNICAST
value|0x00002000
end_define

begin_define
define|#
directive|define
name|XM_RXSTAT_MULTICAST
value|0x00004000
end_define

begin_define
define|#
directive|define
name|XM_RXSTAT_BROADCAST
value|0x00008000
end_define

begin_define
define|#
directive|define
name|XM_RXSTAT_VLAN_LEV1
value|0x00010000
end_define

begin_define
define|#
directive|define
name|XM_RXSTAT_VLAN_LEV2
value|0x00020000
end_define

begin_define
define|#
directive|define
name|XM_RXSTAT_LEN
value|0xFFFC0000
end_define

begin_comment
comment|/*  * XMAC PHY registers, indirectly accessed through  * XM_PHY_ADDR and XM_PHY_REG.  */
end_comment

begin_define
define|#
directive|define
name|XM_PHY_BMCR
value|0x0000
end_define

begin_comment
comment|/* control */
end_comment

begin_define
define|#
directive|define
name|XM_PHY_BMSR
value|0x0001
end_define

begin_comment
comment|/* status */
end_comment

begin_define
define|#
directive|define
name|XM_PHY_VENID
value|0x0002
end_define

begin_comment
comment|/* vendor id */
end_comment

begin_define
define|#
directive|define
name|XM_PHY_DEVID
value|0x0003
end_define

begin_comment
comment|/* device id */
end_comment

begin_define
define|#
directive|define
name|XM_PHY_ANAR
value|0x0004
end_define

begin_comment
comment|/* autoneg advertisenemt */
end_comment

begin_define
define|#
directive|define
name|XM_PHY_LPAR
value|0x0005
end_define

begin_comment
comment|/* link partner ability */
end_comment

begin_define
define|#
directive|define
name|XM_PHY_ANEXP
value|0x0006
end_define

begin_comment
comment|/* autoneg expansion */
end_comment

begin_define
define|#
directive|define
name|XM_PHY_NEXTP
value|0x0007
end_define

begin_comment
comment|/* nextpage */
end_comment

begin_define
define|#
directive|define
name|XM_PHY_LPNEXTP
value|0x0008
end_define

begin_comment
comment|/* link partner's nextpage */
end_comment

begin_define
define|#
directive|define
name|XM_PHY_EXTSTS
value|0x000F
end_define

begin_comment
comment|/* extented status */
end_comment

begin_define
define|#
directive|define
name|XM_PHY_RESAB
value|0x0010
end_define

begin_comment
comment|/* resolved ability */
end_comment

begin_define
define|#
directive|define
name|XM_BMCR_DUPLEX
value|0x0100
end_define

begin_define
define|#
directive|define
name|XM_BMCR_RENEGOTIATE
value|0x0200
end_define

begin_define
define|#
directive|define
name|XM_BMCR_AUTONEGENBL
value|0x1000
end_define

begin_define
define|#
directive|define
name|XM_BMCR_LOOPBACK
value|0x4000
end_define

begin_define
define|#
directive|define
name|XM_BMCR_RESET
value|0x8000
end_define

begin_define
define|#
directive|define
name|XM_BMSR_EXTCAP
value|0x0001
end_define

begin_define
define|#
directive|define
name|XM_BMSR_LINKSTAT
value|0x0004
end_define

begin_define
define|#
directive|define
name|XM_BMSR_AUTONEGABLE
value|0x0008
end_define

begin_define
define|#
directive|define
name|XM_BMSR_REMFAULT
value|0x0010
end_define

begin_define
define|#
directive|define
name|XM_BMSR_AUTONEGDONE
value|0x0020
end_define

begin_define
define|#
directive|define
name|XM_BMSR_EXTSTAT
value|0x0100
end_define

begin_define
define|#
directive|define
name|XM_VENID_XAQTI
value|0xD14C
end_define

begin_define
define|#
directive|define
name|XM_DEVID_XMAC
value|0x0002
end_define

begin_define
define|#
directive|define
name|XM_ANAR_FULLDUPLEX
value|0x0020
end_define

begin_define
define|#
directive|define
name|XM_ANAR_HALFDUPLEX
value|0x0040
end_define

begin_define
define|#
directive|define
name|XM_ANAR_PAUSEBITS
value|0x0180
end_define

begin_define
define|#
directive|define
name|XM_ANAR_REMFAULTBITS
value|0x1800
end_define

begin_define
define|#
directive|define
name|XM_ANAR_ACK
value|0x4000
end_define

begin_define
define|#
directive|define
name|XM_ANAR_NEXTPAGE
value|0x8000
end_define

begin_define
define|#
directive|define
name|XM_LPAR_FULLDUPLEX
value|0x0020
end_define

begin_define
define|#
directive|define
name|XM_LPAR_HALFDUPLEX
value|0x0040
end_define

begin_define
define|#
directive|define
name|XM_LPAR_PAUSEBITS
value|0x0180
end_define

begin_define
define|#
directive|define
name|XM_LPAR_REMFAULTBITS
value|0x1800
end_define

begin_define
define|#
directive|define
name|XM_LPAR_ACK
value|0x4000
end_define

begin_define
define|#
directive|define
name|XM_LPAR_NEXTPAGE
value|0x8000
end_define

begin_define
define|#
directive|define
name|XM_PAUSE_NOPAUSE
value|0x0000
end_define

begin_define
define|#
directive|define
name|XM_PAUSE_SYMPAUSE
value|0x0080
end_define

begin_define
define|#
directive|define
name|XM_PAUSE_ASYMPAUSE
value|0x0100
end_define

begin_define
define|#
directive|define
name|XM_PAUSE_BOTH
value|0x0180
end_define

begin_define
define|#
directive|define
name|XM_REMFAULT_LINKOK
value|0x0000
end_define

begin_define
define|#
directive|define
name|XM_REMFAULT_LINKFAIL
value|0x0800
end_define

begin_define
define|#
directive|define
name|XM_REMFAULT_OFFLINE
value|0x1000
end_define

begin_define
define|#
directive|define
name|XM_REMFAULT_ANEGERR
value|0x1800
end_define

begin_define
define|#
directive|define
name|XM_ANEXP_GOTPAGE
value|0x0002
end_define

begin_define
define|#
directive|define
name|XM_ANEXP_NEXTPAGE_SELF
value|0x0004
end_define

begin_define
define|#
directive|define
name|XM_ANEXP_NEXTPAGE_LP
value|0x0008
end_define

begin_define
define|#
directive|define
name|XM_NEXTP_MESSAGE
value|0x07FF
end_define

begin_define
define|#
directive|define
name|XM_NEXTP_TOGGLE
value|0x0800
end_define

begin_define
define|#
directive|define
name|XM_NEXTP_ACK2
value|0x1000
end_define

begin_define
define|#
directive|define
name|XM_NEXTP_MPAGE
value|0x2000
end_define

begin_define
define|#
directive|define
name|XM_NEXTP_ACK1
value|0x4000
end_define

begin_define
define|#
directive|define
name|XM_NEXTP_NPAGE
value|0x8000
end_define

begin_define
define|#
directive|define
name|XM_LPNEXTP_MESSAGE
value|0x07FF
end_define

begin_define
define|#
directive|define
name|XM_LPNEXTP_TOGGLE
value|0x0800
end_define

begin_define
define|#
directive|define
name|XM_LPNEXTP_ACK2
value|0x1000
end_define

begin_define
define|#
directive|define
name|XM_LPNEXTP_MPAGE
value|0x2000
end_define

begin_define
define|#
directive|define
name|XM_LPNEXTP_ACK1
value|0x4000
end_define

begin_define
define|#
directive|define
name|XM_LPNEXTP_NPAGE
value|0x8000
end_define

begin_define
define|#
directive|define
name|XM_EXTSTS_HALFDUPLEX
value|0x4000
end_define

begin_define
define|#
directive|define
name|XM_EXTSTS_FULLDUPLEX
value|0x8000
end_define

begin_define
define|#
directive|define
name|XM_RESAB_PAUSEMISMATCH
value|0x0008
end_define

begin_define
define|#
directive|define
name|XM_RESAB_ABLMISMATCH
value|0x0010
end_define

begin_define
define|#
directive|define
name|XM_RESAB_FDMODESEL
value|0x0020
end_define

begin_define
define|#
directive|define
name|XM_RESAB_HDMODESEL
value|0x0040
end_define

begin_define
define|#
directive|define
name|XM_RESAB_PAUSEBITS
value|0x0180
end_define

end_unit

