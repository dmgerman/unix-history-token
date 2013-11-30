begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Jakub Wojciech Klama<jceel@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_LPC_IF_LPEREG_H
end_ifndef

begin_define
define|#
directive|define
name|_ARM_LPC_IF_LPEREG_H
end_define

begin_define
define|#
directive|define
name|LPE_MAC1
value|0x000
end_define

begin_define
define|#
directive|define
name|LPE_MAC1_RXENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPE_MAC1_PASSALL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPE_MAC1_RXFLOWCTRL
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPE_MAC1_TXFLOWCTRL
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPE_MAC1_LOOPBACK
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LPE_MAC1_RESETTX
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|LPE_MAC1_RESETMCSTX
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|LPE_MAC1_RESETRX
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|LPE_MAC1_RESETMCSRX
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|LPE_MAC1_SIMRESET
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|LPE_MAC1_SOFTRESET
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|LPE_MAC2
value|0x004
end_define

begin_define
define|#
directive|define
name|LPE_MAC2_FULLDUPLEX
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPE_MAC2_FRAMELENCHECK
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPE_MAC2_HUGEFRAME
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPE_MAC2_DELAYEDCRC
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPE_MAC2_CRCENABLE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LPE_MAC2_PADCRCENABLE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|LPE_MAC2_VLANPADENABLE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|LPE_MAC2_AUTOPADENABLE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|LPE_MAC2_PUREPREAMBLE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|LPE_MAC2_LONGPREAMBLE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|LPE_MAC2_NOBACKOFF
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|LPE_MAC2_BACKPRESSURE
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|LPE_MAC2_EXCESSDEFER
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|LPE_IPGT
value|0x008
end_define

begin_define
define|#
directive|define
name|LPE_IPGR
value|0x00c
end_define

begin_define
define|#
directive|define
name|LPE_CLRT
value|0x010
end_define

begin_define
define|#
directive|define
name|LPE_MAXF
value|0x014
end_define

begin_define
define|#
directive|define
name|LPE_SUPP
value|0x018
end_define

begin_define
define|#
directive|define
name|LPE_SUPP_SPEED
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|LPE_TEST
value|0x01c
end_define

begin_define
define|#
directive|define
name|LPE_MCFG
value|0x020
end_define

begin_define
define|#
directive|define
name|LPE_MCFG_SCANINCR
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPE_MCFG_SUPPREAMBLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPE_MCFG_CLKSEL
parameter_list|(
name|_n
parameter_list|)
value|((_n& 0x7)<< 2)
end_define

begin_define
define|#
directive|define
name|LPC_MCFG_RESETMII
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|LPE_MCMD
value|0x024
end_define

begin_define
define|#
directive|define
name|LPE_MCMD_READ
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPE_MCMD_WRITE
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|LPE_MCMD_SCAN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPE_MADR
value|0x028
end_define

begin_define
define|#
directive|define
name|LPE_MADR_REGMASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|LPE_MADR_REGSHIFT
value|0
end_define

begin_define
define|#
directive|define
name|LPE_MADR_PHYMASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|LPE_MADR_PHYSHIFT
value|8
end_define

begin_define
define|#
directive|define
name|LPE_MWTD
value|0x02c
end_define

begin_define
define|#
directive|define
name|LPE_MWTD_DATAMASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|LPE_MRDD
value|0x030
end_define

begin_define
define|#
directive|define
name|LPE_MRDD_DATAMASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|LPE_MIND
value|0x034
end_define

begin_define
define|#
directive|define
name|LPE_MIND_BUSY
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPE_MIND_SCANNING
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPE_MIND_INVALID
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPE_MIND_MIIFAIL
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPE_SA0
value|0x040
end_define

begin_define
define|#
directive|define
name|LPE_SA1
value|0x044
end_define

begin_define
define|#
directive|define
name|LPE_SA2
value|0x048
end_define

begin_define
define|#
directive|define
name|LPE_COMMAND
value|0x100
end_define

begin_define
define|#
directive|define
name|LPE_COMMAND_RXENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPE_COMMAND_TXENABLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPE_COMMAND_REGRESET
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPE_COMMAND_TXRESET
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LPE_COMMAND_RXRESET
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|LPE_COMMAND_PASSRUNTFRAME
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|LPE_COMMAND_PASSRXFILTER
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|LPE_COMMAND_TXFLOWCTL
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|LPE_COMMAND_RMII
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|LPE_COMMAND_FULLDUPLEX
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|LPE_STATUS
value|0x104
end_define

begin_define
define|#
directive|define
name|LPE_STATUS_RXACTIVE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPE_STATUS_TXACTIVE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPE_RXDESC
value|0x108
end_define

begin_define
define|#
directive|define
name|LPE_RXSTATUS
value|0x10c
end_define

begin_define
define|#
directive|define
name|LPE_RXDESC_NUMBER
value|0x110
end_define

begin_define
define|#
directive|define
name|LPE_RXDESC_PROD
value|0x114
end_define

begin_define
define|#
directive|define
name|LPE_RXDESC_CONS
value|0x118
end_define

begin_define
define|#
directive|define
name|LPE_TXDESC
value|0x11c
end_define

begin_define
define|#
directive|define
name|LPE_TXSTATUS
value|0x120
end_define

begin_define
define|#
directive|define
name|LPE_TXDESC_NUMBER
value|0x124
end_define

begin_define
define|#
directive|define
name|LPE_TXDESC_PROD
value|0x128
end_define

begin_define
define|#
directive|define
name|LPE_TXDESC_CONS
value|0x12c
end_define

begin_define
define|#
directive|define
name|LPE_TSV0
value|0x158
end_define

begin_define
define|#
directive|define
name|LPE_TSV1
value|0x15c
end_define

begin_define
define|#
directive|define
name|LPE_RSV
value|0x160
end_define

begin_define
define|#
directive|define
name|LPE_FLOWCONTROL_COUNTER
value|0x170
end_define

begin_define
define|#
directive|define
name|LPE_FLOWCONTROL_STATUS
value|0x174
end_define

begin_define
define|#
directive|define
name|LPE_RXFILTER_CTRL
value|0x200
end_define

begin_define
define|#
directive|define
name|LPE_RXFILTER_UNICAST
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPE_RXFILTER_BROADCAST
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPE_RXFILTER_MULTICAST
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPE_RXFILTER_UNIHASH
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPE_RXFILTER_MULTIHASH
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LPE_RXFILTER_PERFECT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|LPE_RXFILTER_WOL
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|LPE_RXFILTER_FILTWOL
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|LPE_RXFILTER_WOL_STATUS
value|0x204
end_define

begin_define
define|#
directive|define
name|LPE_RXFILTER_WOL_CLEAR
value|0x208
end_define

begin_define
define|#
directive|define
name|LPE_HASHFILTER_L
value|0x210
end_define

begin_define
define|#
directive|define
name|LPE_HASHFILTER_H
value|0x214
end_define

begin_define
define|#
directive|define
name|LPE_INTSTATUS
value|0xfe0
end_define

begin_define
define|#
directive|define
name|LPE_INTENABLE
value|0xfe4
end_define

begin_define
define|#
directive|define
name|LPE_INTCLEAR
value|0xfe8
end_define

begin_define
define|#
directive|define
name|LPE_INTSET
value|0xfec
end_define

begin_define
define|#
directive|define
name|LPE_INT_RXOVERRUN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPE_INT_RXERROR
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPE_INT_RXFINISH
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPE_INT_RXDONE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPE_INT_TXUNDERRUN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LPE_INT_TXERROR
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|LPE_INT_TXFINISH
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|LPE_INT_TXDONE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|LPE_INT_SOFTINT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|LPE_INTWAKEUPINT
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|LPE_POWERDOWN
value|0xff4
end_define

begin_define
define|#
directive|define
name|LPE_DESC_ALIGN
value|8
end_define

begin_define
define|#
directive|define
name|LPE_TXDESC_NUM
value|128
end_define

begin_define
define|#
directive|define
name|LPE_RXDESC_NUM
value|128
end_define

begin_define
define|#
directive|define
name|LPE_TXDESC_SIZE
value|(LPE_TXDESC_NUM * sizeof(struct lpe_hwdesc))
end_define

begin_define
define|#
directive|define
name|LPE_RXDESC_SIZE
value|(LPE_RXDESC_NUM * sizeof(struct lpe_hwdesc))
end_define

begin_define
define|#
directive|define
name|LPE_TXSTATUS_SIZE
value|(LPE_TXDESC_NUM * sizeof(struct lpe_hwstatus))
end_define

begin_define
define|#
directive|define
name|LPE_RXSTATUS_SIZE
value|(LPE_RXDESC_NUM * sizeof(struct lpe_hwstatus))
end_define

begin_define
define|#
directive|define
name|LPE_MAXFRAGS
value|8
end_define

begin_struct
struct|struct
name|lpe_hwdesc
block|{
name|uint32_t
name|lhr_data
decl_stmt|;
name|uint32_t
name|lhr_control
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lpe_hwstatus
block|{
name|uint32_t
name|lhs_info
decl_stmt|;
name|uint32_t
name|lhs_crc
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LPE_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = ((x) == ((y)-1)) ? 0 : (x)+1
end_define

begin_comment
comment|/* These are valid for both Rx and Tx descriptors */
end_comment

begin_define
define|#
directive|define
name|LPE_HWDESC_SIZE_MASK
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_INTERRUPT
value|(1U<< 31)
end_define

begin_comment
comment|/* These are valid for Tx descriptors */
end_comment

begin_define
define|#
directive|define
name|LPE_HWDESC_LAST
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_CRC
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_PAD
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_HUGE
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_OVERRIDE
value|(1<< 26)
end_define

begin_comment
comment|/* These are valid for Tx status descriptors */
end_comment

begin_define
define|#
directive|define
name|LPE_HWDESC_COLLISIONS
parameter_list|(
name|_n
parameter_list|)
value|(((_n)>> 21)& 0x7)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_DEFER
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_EXCDEFER
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_EXCCOLL
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_LATECOLL
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_UNDERRUN
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_TXNODESCR
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_ERROR
value|(1U<< 31)
end_define

begin_comment
comment|/* These are valid for Rx status descriptors */
end_comment

begin_define
define|#
directive|define
name|LPE_HWDESC_CONTROL
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_VLAN
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_FAILFILTER
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_MULTICAST
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_BROADCAST
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_CRCERROR
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_SYMBOLERROR
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_LENGTHERROR
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_RANGEERROR
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_ALIGNERROR
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_OVERRUN
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_RXNODESCR
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_LASTFLAG
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|LPE_HWDESC_ERROR
value|(1U<< 31)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_LPC_IF_LPEREG_H */
end_comment

end_unit

