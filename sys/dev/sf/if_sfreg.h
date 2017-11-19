begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-4-Clause  *  * Copyright (c) 1997, 1998, 1999  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Registers for the Adaptec AIC-6915 Starfire. The Starfire has a 512K  * register space. These registers can be accessed in the following way:  * - PCI config registers are always accessible through PCI config space  * - Full 512K space mapped into memory using PCI memory mapped access  * - 256-byte I/O space mapped through PCI I/O access  * - Full 512K space mapped through indirect I/O using PCI I/O access  * It's possible to use either memory mapped mode or I/O mode to access  * the registers, but memory mapped is usually the easiest. All registers  * are 32 bits wide and must be accessed using 32-bit operations.  */
end_comment

begin_comment
comment|/*  * Adaptec PCI vendor ID.  */
end_comment

begin_define
define|#
directive|define
name|AD_VENDORID
value|0x9004
end_define

begin_comment
comment|/*  * AIC-6915 PCI device ID.  */
end_comment

begin_define
define|#
directive|define
name|AD_DEVICEID_STARFIRE
value|0x6915
end_define

begin_comment
comment|/*  * AIC-6915 subsystem IDs. Adaptec uses the subsystem ID to identify  * the exact kind of NIC on which the ASIC is mounted. Currently there  * are six different variations. Note: the Adaptec manual lists code 0x28  * for two different NICs: the 62044 and the 69011/TX. This is a typo:  * the code for the 62044 is really 0x18.  *  * Note that there also appears to be an 0x19 code for a newer rev  * 62044 card.  */
end_comment

begin_define
define|#
directive|define
name|AD_SUBSYSID_62011_REV0
value|0x0008
end_define

begin_comment
comment|/* single port 10/100baseTX 64-bit */
end_comment

begin_define
define|#
directive|define
name|AD_SUBSYSID_62011_REV1
value|0x0009
end_define

begin_comment
comment|/* single port 10/100baseTX 64-bit */
end_comment

begin_define
define|#
directive|define
name|AD_SUBSYSID_62022
value|0x0010
end_define

begin_comment
comment|/* dual port 10/100baseTX 64-bit */
end_comment

begin_define
define|#
directive|define
name|AD_SUBSYSID_62044_REV0
value|0x0018
end_define

begin_comment
comment|/* quad port 10/100baseTX 64-bit */
end_comment

begin_define
define|#
directive|define
name|AD_SUBSYSID_62044_REV1
value|0x0019
end_define

begin_comment
comment|/* quad port 10/100baseTX 64-bit */
end_comment

begin_define
define|#
directive|define
name|AD_SUBSYSID_62020
value|0x0020
end_define

begin_comment
comment|/* single port 10/100baseFX 64-bit */
end_comment

begin_define
define|#
directive|define
name|AD_SUBSYSID_69011
value|0x0028
end_define

begin_comment
comment|/* single port 10/100baseTX 32-bit */
end_comment

begin_comment
comment|/*  * Starfire internal register space map. The entire register space  * is available using PCI memory mapped mode. The SF_RMAP_INTREG  * space is available using PCI I/O mode. The entire space can be  * accessed using indirect I/O using the indirect I/O addr and  * indirect I/O data registers located within the SF_RMAP_INTREG space.  */
end_comment

begin_define
define|#
directive|define
name|SF_RMAP_ROMADDR_BASE
value|0x00000
end_define

begin_comment
comment|/* Expansion ROM space */
end_comment

begin_define
define|#
directive|define
name|SF_RMAP_ROMADDR_MAX
value|0x3FFFF
end_define

begin_define
define|#
directive|define
name|SF_RMAP_EXGPIO_BASE
value|0x40000
end_define

begin_comment
comment|/* External general purpose regs */
end_comment

begin_define
define|#
directive|define
name|SF_RMAP_EXGPIO_MAX
value|0x3FFFF
end_define

begin_define
define|#
directive|define
name|SF_RMAP_INTREG_BASE
value|0x50000
end_define

begin_comment
comment|/* Internal functional registers */
end_comment

begin_define
define|#
directive|define
name|SF_RMAP_INTREG_MAX
value|0x500FF
end_define

begin_define
define|#
directive|define
name|SF_RMAP_GENREG_BASE
value|0x50100
end_define

begin_comment
comment|/* General purpose registers */
end_comment

begin_define
define|#
directive|define
name|SF_RMAP_GENREG_MAX
value|0x5FFFF
end_define

begin_define
define|#
directive|define
name|SF_RMAP_FIFO_BASE
value|0x60000
end_define

begin_define
define|#
directive|define
name|SF_RMAP_FIFO_MAX
value|0x6FFFF
end_define

begin_define
define|#
directive|define
name|SF_RMAP_STS_BASE
value|0x70000
end_define

begin_define
define|#
directive|define
name|SF_RMAP_STS_MAX
value|0x70083
end_define

begin_define
define|#
directive|define
name|SF_RMAP_RSVD_BASE
value|0x70084
end_define

begin_define
define|#
directive|define
name|SF_RMAP_RSVD_MAX
value|0x7FFFF
end_define

begin_comment
comment|/*  * PCI config header registers, 0x0000 to 0x003F  */
end_comment

begin_define
define|#
directive|define
name|SF_PCI_VENDOR_ID
value|0x0000
end_define

begin_define
define|#
directive|define
name|SF_PCI_DEVICE_ID
value|0x0002
end_define

begin_define
define|#
directive|define
name|SF_PCI_COMMAND
value|0x0004
end_define

begin_define
define|#
directive|define
name|SF_PCI_STATUS
value|0x0006
end_define

begin_define
define|#
directive|define
name|SF_PCI_REVID
value|0x0008
end_define

begin_define
define|#
directive|define
name|SF_PCI_CLASSCODE
value|0x0009
end_define

begin_define
define|#
directive|define
name|SF_PCI_CACHELEN
value|0x000C
end_define

begin_define
define|#
directive|define
name|SF_PCI_LATENCY_TIMER
value|0x000D
end_define

begin_define
define|#
directive|define
name|SF_PCI_HEADER_TYPE
value|0x000E
end_define

begin_define
define|#
directive|define
name|SF_PCI_LOMEM
value|0x0010
end_define

begin_define
define|#
directive|define
name|SF_PCI_LOIO
value|0x0014
end_define

begin_define
define|#
directive|define
name|SF_PCI_SUBVEN_ID
value|0x002C
end_define

begin_define
define|#
directive|define
name|SF_PCI_SYBSYS_ID
value|0x002E
end_define

begin_define
define|#
directive|define
name|SF_PCI_BIOSROM
value|0x0030
end_define

begin_define
define|#
directive|define
name|SF_PCI_INTLINE
value|0x003C
end_define

begin_define
define|#
directive|define
name|SF_PCI_INTPIN
value|0x003D
end_define

begin_define
define|#
directive|define
name|SF_PCI_MINGNT
value|0x003E
end_define

begin_define
define|#
directive|define
name|SF_PCI_MINLAT
value|0x003F
end_define

begin_comment
comment|/*  * PCI registers, 0x0040 to 0x006F  */
end_comment

begin_define
define|#
directive|define
name|SF_PCI_DEVCFG
value|0x0040
end_define

begin_define
define|#
directive|define
name|SF_BACCTL
value|0x0044
end_define

begin_define
define|#
directive|define
name|SF_PCI_MON1
value|0x0048
end_define

begin_define
define|#
directive|define
name|SF_PCI_MON2
value|0x004C
end_define

begin_define
define|#
directive|define
name|SF_PCI_CAPID
value|0x0050
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|SF_PCI_NEXTPTR
value|0x0051
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|SF_PCI_PWRMGMTCAP
value|0x0052
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|SF_PCI_PWRMGMTCTRL
value|0x0054
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|SF_PCI_PME_EVENT
value|0x0058
end_define

begin_define
define|#
directive|define
name|SF_PCI_EECTL
value|0x0060
end_define

begin_define
define|#
directive|define
name|SF_PCI_COMPLIANCE
value|0x0064
end_define

begin_define
define|#
directive|define
name|SF_INDIRECTIO_ADDR
value|0x0068
end_define

begin_define
define|#
directive|define
name|SF_INDIRECTIO_DATA
value|0x006C
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_FORCE64
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_SYSTEM64
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_RSVD0
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_INCR_INB
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_ABTONPERR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_STPONPERR
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_MR_ENB
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_FIFOTHR
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_STPONCA
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_PCIMEN
value|0x00002000
end_define

begin_comment
comment|/* enable PCI bus master */
end_comment

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_LATSTP
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_BYTE_ENB
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_EECSWIDTH
value|0x00070000
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_STPMWCA
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_REGCSWIDTH
value|0x00700000
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_INTR_ENB
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_DPR_ENB
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_RSVD1
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_RSVD2
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_STA_ENB
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_RTA_ENB
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_RMA_ENB
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_SSE_ENB
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SF_PCIDEVCFG_DPE_ENB
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SF_BACCTL_BACDMA_ENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SF_BACCTL_PREFER_RXDMA
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SF_BACCTL_PREFER_TXDMA
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SF_BACCTL_SINGLE_DMA
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SF_BACCTL_SWAPMODE_DATA
value|0x00000030
end_define

begin_define
define|#
directive|define
name|SF_BACCTL_SWAPMODE_DESC
value|0x000000C0
end_define

begin_define
define|#
directive|define
name|SF_SWAPMODE_LE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SF_SWAPMODE_BE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SF_PSTATE_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|SF_PSTATE_D0
value|0x0000
end_define

begin_define
define|#
directive|define
name|SF_PSTATE_D1
value|0x0001
end_define

begin_define
define|#
directive|define
name|SF_PSTATE_D2
value|0x0002
end_define

begin_define
define|#
directive|define
name|SF_PSTATE_D3
value|0x0003
end_define

begin_define
define|#
directive|define
name|SF_PME_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|SF_PME_STATUS
value|0x8000
end_define

begin_comment
comment|/*  * Ethernet registers 0x0070 to 0x00FF  */
end_comment

begin_define
define|#
directive|define
name|SF_GEN_ETH_CTL
value|0x0070
end_define

begin_define
define|#
directive|define
name|SF_TIMER_CTL
value|0x0074
end_define

begin_define
define|#
directive|define
name|SF_CURTIME
value|0x0078
end_define

begin_define
define|#
directive|define
name|SF_ISR
value|0x0080
end_define

begin_define
define|#
directive|define
name|SF_ISR_SHADOW
value|0x0084
end_define

begin_define
define|#
directive|define
name|SF_IMR
value|0x0088
end_define

begin_define
define|#
directive|define
name|SF_GPIO
value|0x008C
end_define

begin_define
define|#
directive|define
name|SF_TXDQ_CTL
value|0x0090
end_define

begin_define
define|#
directive|define
name|SF_TXDQ_ADDR_HIPRIO
value|0x0094
end_define

begin_define
define|#
directive|define
name|SF_TXDQ_ADDR_LOPRIO
value|0x0098
end_define

begin_define
define|#
directive|define
name|SF_TXDQ_ADDR_HI
value|0x009C
end_define

begin_define
define|#
directive|define
name|SF_TXDQ_PRODIDX
value|0x00A0
end_define

begin_define
define|#
directive|define
name|SF_TXDQ_CONSIDX
value|0x00A4
end_define

begin_define
define|#
directive|define
name|SF_TXDMA_STS1
value|0x00A8
end_define

begin_define
define|#
directive|define
name|SF_TXDMA_STS2
value|0x00AC
end_define

begin_define
define|#
directive|define
name|SF_TX_FRAMCTL
value|0x00B0
end_define

begin_define
define|#
directive|define
name|SF_CQ_ADDR_HI
value|0x00B4
end_define

begin_define
define|#
directive|define
name|SF_TXCQ_CTL
value|0x00B8
end_define

begin_define
define|#
directive|define
name|SF_RXCQ_CTL_1
value|0x00BC
end_define

begin_define
define|#
directive|define
name|SF_RXCQ_CTL_2
value|0x00C0
end_define

begin_define
define|#
directive|define
name|SF_CQ_CONSIDX
value|0x00C4
end_define

begin_define
define|#
directive|define
name|SF_CQ_PRODIDX
value|0x00C8
end_define

begin_define
define|#
directive|define
name|SF_CQ_RXQ2
value|0x00CC
end_define

begin_define
define|#
directive|define
name|SF_RXDMA_CTL
value|0x00D0
end_define

begin_define
define|#
directive|define
name|SF_RXDQ_CTL_1
value|0x00D4
end_define

begin_define
define|#
directive|define
name|SF_RXDQ_CTL_2
value|0x00D8
end_define

begin_define
define|#
directive|define
name|SF_RXDQ_ADDR_HI
value|0x00DC
end_define

begin_define
define|#
directive|define
name|SF_RXDQ_ADDR_Q1
value|0x00E0
end_define

begin_define
define|#
directive|define
name|SF_RXDQ_ADDR_Q2
value|0x00E4
end_define

begin_define
define|#
directive|define
name|SF_RXDQ_PTR_Q1
value|0x00E8
end_define

begin_define
define|#
directive|define
name|SF_RXDQ_PTR_Q2
value|0x00EC
end_define

begin_define
define|#
directive|define
name|SF_RXDMA_STS
value|0x00F0
end_define

begin_define
define|#
directive|define
name|SF_RXFILT
value|0x00F4
end_define

begin_define
define|#
directive|define
name|SF_RX_FRAMETEST_OUT
value|0x00F8
end_define

begin_comment
comment|/* Ethernet control register */
end_comment

begin_define
define|#
directive|define
name|SF_ETHCTL_RX_ENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SF_ETHCTL_TX_ENB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SF_ETHCTL_RXDMA_ENB
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SF_ETHCTL_TXDMA_ENB
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SF_ETHCTL_RXGFP_ENB
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SF_ETHCTL_TXGFP_ENB
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SF_ETHCTL_SOFTINTR
value|0x00000800
end_define

begin_comment
comment|/* Timer control register */
end_comment

begin_define
define|#
directive|define
name|SF_TIMER_IMASK_INTERVAL
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|SF_TIMER_IMASK_MODE
value|0x00000060
end_define

begin_define
define|#
directive|define
name|SF_TIMER_SMALLFRAME_BYP
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SF_TIMER_SMALLRX_FRAME
value|0x00000600
end_define

begin_define
define|#
directive|define
name|SF_TIMER_TIMES_TEN
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SF_TIMER_RXHIPRIO_BYP
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SF_TIMER_TX_DMADONE_DLY
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SF_TIMER_TX_QDONE_DLY
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SF_TIMER_TX_FRDONE_DLY
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SF_TIMER_GENTIMER
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|SF_TIMER_ONESHOT
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SF_TIMER_GENTIMER_RES
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SF_TIMER_TIMEST_RES
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SF_TIMER_RXQ2DONE_DLY
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SF_TIMER_EARLYRX2_DLY
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SF_TIMER_RXQ1DONE_DLY
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SF_TIMER_EARLYRX1_DLY
value|0x80000000
end_define

begin_comment
comment|/* Timer resolution is 0.8us * 128. */
end_comment

begin_define
define|#
directive|define
name|SF_IM_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SF_IM_MAX
value|0x1F
end_define

begin_comment
comment|/* 3.276ms */
end_comment

begin_define
define|#
directive|define
name|SF_IM_DEFAULT
value|1
end_define

begin_comment
comment|/* 102.4us */
end_comment

begin_comment
comment|/* Interrupt status register */
end_comment

begin_define
define|#
directive|define
name|SF_ISR_PCIINT_ASSERTED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SF_ISR_GFP_TX
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SF_ISR_GFP_RX
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SF_ISR_TX_BADID_HIPRIO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SF_ISR_TX_BADID_LOPRIO
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SF_ISR_NO_TX_CSUM
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SF_ISR_RXDQ2_NOBUFS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SF_ISR_RXGFP_NORESP
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SF_ISR_RXDQ1_DMADONE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SF_ISR_RXDQ2_DMADONE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SF_ISR_RXDQ1_EARLY
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SF_ISR_RXDQ2_EARLY
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SF_ISR_TX_QUEUEDONE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SF_ISR_TX_DMADONE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SF_ISR_TX_TXDONE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SF_ISR_NORMALINTR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SF_ISR_RXDQ1_NOBUFS
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SF_ISR_RXCQ2_NOBUFS
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SF_ISR_TX_LOFIFO
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SF_ISR_DMAERR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SF_ISR_PCIINT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SF_ISR_TXCQ_NOBUFS
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SF_ISR_RXCQ1_NOBUFS
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SF_ISR_SOFTINTR
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SF_ISR_GENTIMER
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SF_ISR_ABNORMALINTR
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SF_ISR_RSVD0
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SF_ISR_STATSOFLOW
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SF_ISR_GPIO
value|0xF0000000
end_define

begin_comment
comment|/*  * Shadow interrupt status register. Unlike the normal IRQ register,  * reading bits here does not automatically cause them to reset.  */
end_comment

begin_define
define|#
directive|define
name|SF_SISR_PCIINT_ASSERTED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SF_SISR_GFP_TX
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SF_SISR_GFP_RX
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SF_SISR_TX_BADID_HIPRIO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SF_SISR_TX_BADID_LOPRIO
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SF_SISR_NO_TX_CSUM
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SF_SISR_RXDQ2_NOBUFS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SF_SISR_RXGFP_NORESP
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SF_SISR_RXDQ1_DMADONE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SF_SISR_RXDQ2_DMADONE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SF_SISR_RXDQ1_EARLY
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SF_SISR_RXDQ2_EARLY
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SF_SISR_TX_QUEUEDONE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SF_SISR_TX_DMADONE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SF_SISR_TX_TXDONE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SF_SISR_NORMALINTR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SF_SISR_RXDQ1_NOBUFS
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SF_SISR_RXCQ2_NOBUFS
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SF_SISR_TX_LOFIFO
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SF_SISR_DMAERR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SF_SISR_PCIINT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SF_SISR_TXCQ_NOBUFS
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SF_SISR_RXCQ1_NOBUFS
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SF_SISR_SOFTINTR
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SF_SISR_GENTIMER
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SF_SISR_ABNORMALINTR
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SF_SISR_RSVD0
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SF_SISR_STATSOFLOW
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SF_SISR_GPIO
value|0xF0000000
end_define

begin_comment
comment|/* Interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|SF_IMR_PCIINT_ASSERTED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SF_IMR_GFP_TX
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SF_IMR_GFP_RX
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SF_IMR_TX_BADID_HIPRIO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SF_IMR_TX_BADID_LOPRIO
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SF_IMR_NO_TX_CSUM
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SF_IMR_RXDQ2_NOBUFS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SF_IMR_RXGFP_NORESP
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SF_IMR_RXDQ1_DMADONE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SF_IMR_RXDQ2_DMADONE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SF_IMR_RXDQ1_EARLY
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SF_IMR_RXDQ2_EARLY
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SF_IMR_TX_QUEUEDONE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SF_IMR_TX_DMADONE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SF_IMR_TX_TXDONE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SF_IMR_NORMALINTR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SF_IMR_RXDQ1_NOBUFS
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SF_IMR_RXCQ2_NOBUFS
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SF_IMR_TX_LOFIFO
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SF_IMR_DMAERR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SF_IMR_PCIINT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SF_IMR_TXCQ_NOBUFS
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SF_IMR_RXCQ1_NOBUFS
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SF_IMR_SOFTINTR
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SF_IMR_GENTIMER
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SF_IMR_ABNORMALINTR
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SF_IMR_RSVD0
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SF_IMR_STATSOFLOW
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SF_IMR_GPIO
value|0xF0000000
end_define

begin_define
define|#
directive|define
name|SF_INTRS
define|\
value|(SF_IMR_RXDQ2_NOBUFS|SF_IMR_RXDQ1_DMADONE|SF_IMR_RXDQ2_DMADONE|	\ 	 SF_IMR_TX_DMADONE|SF_IMR_RXDQ1_NOBUFS|				\ 	 SF_IMR_NORMALINTR|SF_IMR_ABNORMALINTR|SF_IMR_TXCQ_NOBUFS|	\ 	 SF_IMR_RXCQ1_NOBUFS|SF_IMR_RXCQ2_NOBUFS|SF_IMR_STATSOFLOW|	\ 	 SF_IMR_TX_LOFIFO|SF_IMR_DMAERR|SF_IMR_RXGFP_NORESP|		\ 	 SF_IMR_NO_TX_CSUM)
end_define

begin_comment
comment|/* TX descriptor queue control registers */
end_comment

begin_define
define|#
directive|define
name|SF_TXDQCTL_DESCTYPE
value|0x00000007
end_define

begin_define
define|#
directive|define
name|SF_TXDQCTL_NODMACMP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SF_TXDQCTL_MINSPACE
value|0x00000070
end_define

begin_define
define|#
directive|define
name|SF_TXDQCTL_64BITADDR
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SF_TXDQCTL_BURSTLEN
value|0x00003F00
end_define

begin_define
define|#
directive|define
name|SF_TXDQCTL_SKIPLEN
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|SF_TXDQCTL_HIPRIOTHRESH
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|SF_TXDMA_HIPRIO_THRESH
value|2
end_define

begin_define
define|#
directive|define
name|SF_TXDDMA_BURST
value|(128 / 32)
end_define

begin_define
define|#
directive|define
name|SF_TXBUFDESC_TYPE0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SF_TXBUFDESC_TYPE1
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SF_TXBUFDESC_TYPE2
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SF_TXBUFDESC_TYPE3
value|0x00000003
end_define

begin_define
define|#
directive|define
name|SF_TXBUFDESC_TYPE4
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SF_TXMINSPACE_UNLIMIT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SF_TXMINSPACE_32BYTES
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SF_TXMINSPACE_64BYTES
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SF_TXMINSPACE_128BYTES
value|0x00000030
end_define

begin_define
define|#
directive|define
name|SF_TXMINSPACE_256BYTES
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SF_TXSKIPLEN_0BYTES
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SF_TXSKIPLEN_8BYTES
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SF_TXSKIPLEN_16BYTES
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SF_TXSKIPLEN_24BYTES
value|0x00030000
end_define

begin_define
define|#
directive|define
name|SF_TXSKIPLEN_32BYTES
value|0x00040000
end_define

begin_comment
comment|/* TX frame control register */
end_comment

begin_define
define|#
directive|define
name|SF_TXFRMCTL_TXTHRESH
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|SF_TXFRMCTL_CPLAFTERTX
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SF_TXFRMCRL_DEBUG
value|0x0000FE00
end_define

begin_define
define|#
directive|define
name|SF_TXFRMCTL_STATUS
value|0x01FF0000
end_define

begin_define
define|#
directive|define
name|SF_TXFRMCTL_MAC_TXIF
value|0xFE000000
end_define

begin_comment
comment|/* TX completion queue control register */
end_comment

begin_define
define|#
directive|define
name|SF_TXCQ_THRESH
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|SF_TXCQ_COMMON
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SF_TXCQ_SIZE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SF_TXCQ_WRITEENB
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SF_TXCQ_USE_64BIT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SF_TXCQ_ADDR
value|0xFFFFFF00
end_define

begin_comment
comment|/* RX completion queue control register */
end_comment

begin_define
define|#
directive|define
name|SF_RXCQ_THRESH
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|SF_RXCQ_TYPE
value|0x00000030
end_define

begin_define
define|#
directive|define
name|SF_RXCQ_WRITEENB
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SF_RXCQ_USE_64BIT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SF_RXCQ_ADDR
value|0xFFFFFF00
end_define

begin_define
define|#
directive|define
name|SF_RXCQTYPE_0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SF_RXCQTYPE_1
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SF_RXCQTYPE_2
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SF_RXCQTYPE_3
value|0x00000030
end_define

begin_comment
comment|/* TX descriptor queue producer index register */
end_comment

begin_define
define|#
directive|define
name|SF_TXDQ_PRODIDX_LOPRIO
value|0x000007FF
end_define

begin_define
define|#
directive|define
name|SF_TXDQ_PRODIDX_HIPRIO
value|0x07FF0000
end_define

begin_comment
comment|/* TX descriptor queue consumer index register */
end_comment

begin_define
define|#
directive|define
name|SF_TXDQ_CONSIDX_LOPRIO
value|0x000007FF
end_define

begin_define
define|#
directive|define
name|SF_TXDQ_CONSIDX_HIPRIO
value|0x07FF0000
end_define

begin_comment
comment|/* Completion queue consumer index register */
end_comment

begin_define
define|#
directive|define
name|SF_CQ_CONSIDX_RXQ1
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|SF_CQ_CONSIDX_RXTHRMODE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SF_CQ_CONSIDX_TXQ
value|0x03FF0000
end_define

begin_define
define|#
directive|define
name|SF_CQ_CONSIDX_TXTHRMODE
value|0x80000000
end_define

begin_comment
comment|/* Completion queue producer index register */
end_comment

begin_define
define|#
directive|define
name|SF_CQ_PRODIDX_RXQ1
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|SF_CQ_PRODIDX_TXQ
value|0x03FF0000
end_define

begin_comment
comment|/* RX completion queue 2 consumer/producer index register */
end_comment

begin_define
define|#
directive|define
name|SF_CQ_RXQ2_CONSIDX
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|SF_CQ_RXQ2_RXTHRMODE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SF_CQ_RXQ2_PRODIDX
value|0x03FF0000
end_define

begin_define
define|#
directive|define
name|SF_CQ_RXTHRMODE_INT_ON
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SF_CQ_RXTHRMODE_INT_OFF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SF_CQ_TXTHRMODE_INT_ON
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SF_CQ_TXTHRMODE_INT_OFF
value|0x00000000
end_define

begin_comment
comment|/* RX DMA control register */
end_comment

begin_define
define|#
directive|define
name|SF_RXDMA_BURSTSIZE
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|SF_RXDMA_FPTESTMODE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SF_RXDMA_HIPRIOTHRESH
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|SF_RXDMA_RXEARLYTHRESH
value|0x0001F000
end_define

begin_define
define|#
directive|define
name|SF_RXDMA_DMACRC
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SF_RXDMA_USEBKUPQUEUE
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SF_RXDMA_QUEUEMODE
value|0x00700000
end_define

begin_define
define|#
directive|define
name|SF_RXDMA_RXCQ2_ON
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SF_RXDMA_CSUMMODE
value|0x03000000
end_define

begin_define
define|#
directive|define
name|SF_RXDMA_DMAPAUSEPKTS
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SF_RXDMA_DMACTLPKTS
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SF_RXDMA_DMACRXERRPKTS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SF_RXDMA_DMABADPKTS
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SF_RXDMA_DMARUNTS
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SF_RXDMA_REPORTBADPKTS
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SF_RXDMA_HIGHPRIO_THRESH
value|6
end_define

begin_define
define|#
directive|define
name|SF_RXDMA_BURST
value|(64 / 32)
end_define

begin_define
define|#
directive|define
name|SF_RXDQMODE_Q1ONLY
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SF_RXDQMODE_Q2_ON_FP
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SF_RXDQMODE_Q2_ON_SHORT
value|0x00300000
end_define

begin_define
define|#
directive|define
name|SF_RXDQMODE_Q2_ON_PRIO
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SF_RXDQMODE_SPLITHDR
value|0x00500000
end_define

begin_define
define|#
directive|define
name|SF_RXCSUMMODE_IGNORE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SF_RXCSUMMODE_REJECT_BAD_TCP
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SF_RXCSUMMODE_REJECT_BAD_TCPUDP
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SF_RXCSUMMODE_RSVD
value|0x03000000
end_define

begin_comment
comment|/* RX descriptor queue control registers */
end_comment

begin_define
define|#
directive|define
name|SF_RXDQCTL_MINDESCTHR
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|SF_RXDQCTL_Q1_WE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SF_RXDQCTL_DESCSPACE
value|0x00000700
end_define

begin_define
define|#
directive|define
name|SF_RXDQCTL_64BITDADDR
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SF_RXDQCTL_64BITBADDR
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SF_RXDQCTL_VARIABLE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SF_RXDQCTL_ENTRIES
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SF_RXDQCTL_PREFETCH
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SF_RXDQCTL_BUFLEN
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|SF_DESCSPACE_4BYTES
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SF_DESCSPACE_8BYTES
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SF_DESCSPACE_16BYTES
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SF_DESCSPACE_32BYTES
value|0x00000300
end_define

begin_define
define|#
directive|define
name|SF_DESCSPACE_64BYTES
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SF_DESCSPACE_128_BYTES
value|0x00000500
end_define

begin_comment
comment|/* RX buffer consumer/producer index registers */
end_comment

begin_define
define|#
directive|define
name|SF_RXDQ_PRODIDX
value|0x000007FF
end_define

begin_define
define|#
directive|define
name|SF_RXDQ_CONSIDX
value|0x07FF0000
end_define

begin_comment
comment|/* RX filter control register */
end_comment

begin_define
define|#
directive|define
name|SF_RXFILT_PROMISC
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SF_RXFILT_ALLMULTI
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SF_RXFILT_BROAD
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SF_RXFILT_HASHPRIO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SF_RXFILT_HASHMODE
value|0x00000030
end_define

begin_define
define|#
directive|define
name|SF_RXFILT_PERFMODE
value|0x000000C0
end_define

begin_define
define|#
directive|define
name|SF_RXFILT_VLANMODE
value|0x00000300
end_define

begin_define
define|#
directive|define
name|SF_RXFILT_WAKEMODE
value|0x00000C00
end_define

begin_define
define|#
directive|define
name|SF_RXFILT_MULTI_NOBROAD
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SF_RXFILT_MIN_VLANPRIO
value|0x0000E000
end_define

begin_define
define|#
directive|define
name|SF_RXFILT_PEFECTPRIO
value|0xFFFF0000
end_define

begin_comment
comment|/* Hash filtering mode */
end_comment

begin_define
define|#
directive|define
name|SF_HASHMODE_OFF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SF_HASHMODE_WITHVLAN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SF_HASHMODE_ANYVLAN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SF_HASHMODE_ANY
value|0x00000030
end_define

begin_comment
comment|/* Perfect filtering mode */
end_comment

begin_define
define|#
directive|define
name|SF_PERFMODE_OFF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SF_PERFMODE_NORMAL
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SF_PERFMODE_INVERSE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SF_PERFMODE_VLAN
value|0x000000C0
end_define

begin_comment
comment|/* VLAN mode */
end_comment

begin_define
define|#
directive|define
name|SF_VLANMODE_OFF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SF_VLANMODE_NOSTRIP
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SF_VLANMODE_STRIP
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SF_VLANMODE_RSVD
value|0x00000300
end_define

begin_comment
comment|/* Wakeup mode */
end_comment

begin_define
define|#
directive|define
name|SF_WAKEMODE_OFF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SF_WAKEMODE_FILTER
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SF_WAKEMODE_FP
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SF_WAKEMODE_HIPRIO
value|0x00000C00
end_define

begin_comment
comment|/*  * Extra PCI registers 0x0100 to 0x0FFF  */
end_comment

begin_define
define|#
directive|define
name|SF_PCI_TARGSTAT
value|0x0100
end_define

begin_define
define|#
directive|define
name|SF_PCI_MASTSTAT1
value|0x0104
end_define

begin_define
define|#
directive|define
name|SF_PCI_MASTSTAT2
value|0x0108
end_define

begin_define
define|#
directive|define
name|SF_PCI_DMAHOSTADDR_LO
value|0x010C
end_define

begin_define
define|#
directive|define
name|SF_BAC_DMADIAG0
value|0x0110
end_define

begin_define
define|#
directive|define
name|SF_BAC_DMADIAG1
value|0x0114
end_define

begin_define
define|#
directive|define
name|SF_BAC_DMADIAG2
value|0x0118
end_define

begin_define
define|#
directive|define
name|SF_BAC_DMADIAG3
value|0x011C
end_define

begin_define
define|#
directive|define
name|SF_PAR0
value|0x0120
end_define

begin_define
define|#
directive|define
name|SF_PAR1
value|0x0124
end_define

begin_define
define|#
directive|define
name|SF_PCICB_FUNCEVENT
value|0x0130
end_define

begin_define
define|#
directive|define
name|SF_PCICB_FUNCEVENT_MASK
value|0x0134
end_define

begin_define
define|#
directive|define
name|SF_PCICB_FUNCSTATE
value|0x0138
end_define

begin_define
define|#
directive|define
name|SF_PCICB_FUNCFORCE
value|0x013C
end_define

begin_comment
comment|/*  * Serial EEPROM registers 0x1000 to 0x1FFF  * Presumeably the EEPROM is mapped into this 8K window.  */
end_comment

begin_define
define|#
directive|define
name|SF_EEADDR_BASE
value|0x1000
end_define

begin_define
define|#
directive|define
name|SF_EEADDR_MAX
value|0x1FFF
end_define

begin_define
define|#
directive|define
name|SF_EE_NODEADDR
value|14
end_define

begin_comment
comment|/*  * MII registers registers 0x2000 to 0x3FFF  * There are 32 sets of 32 registers, one set for each possible  * PHY address. Each 32 bit register is split into a 16-bit data  * port and a couple of status bits.  */
end_comment

begin_define
define|#
directive|define
name|SF_MIIADDR_BASE
value|0x2000
end_define

begin_define
define|#
directive|define
name|SF_MIIADDR_MAX
value|0x3FFF
end_define

begin_define
define|#
directive|define
name|SF_MII_BLOCKS
value|32
end_define

begin_define
define|#
directive|define
name|SF_MII_DATAVALID
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SF_MII_BUSY
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SF_MII_DATAPORT
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|SF_PHY_REG
parameter_list|(
name|phy
parameter_list|,
name|reg
parameter_list|)
define|\
value|(SF_MIIADDR_BASE + ((phy) * SF_MII_BLOCKS * sizeof(uint32_t)) +	\ 	((reg) * sizeof(uint32_t)))
end_define

begin_comment
comment|/*  * Ethernet extra registers 0x4000 to 0x4FFF  */
end_comment

begin_define
define|#
directive|define
name|SF_TESTMODE
value|0x4000
end_define

begin_define
define|#
directive|define
name|SF_RX_FRAMEPROC_CTL
value|0x4004
end_define

begin_define
define|#
directive|define
name|SF_TX_FRAMEPROC_CTL
value|0x4008
end_define

begin_comment
comment|/*  * MAC registers 0x5000 to 0x5FFF  */
end_comment

begin_define
define|#
directive|define
name|SF_MACCFG_1
value|0x5000
end_define

begin_define
define|#
directive|define
name|SF_MACCFG_2
value|0x5004
end_define

begin_define
define|#
directive|define
name|SF_BKTOBKIPG
value|0x5008
end_define

begin_define
define|#
directive|define
name|SF_NONBKTOBKIPG
value|0x500C
end_define

begin_define
define|#
directive|define
name|SF_COLRETRY
value|0x5010
end_define

begin_define
define|#
directive|define
name|SF_MAXLEN
value|0x5014
end_define

begin_define
define|#
directive|define
name|SF_TXNIBBLECNT
value|0x5018
end_define

begin_define
define|#
directive|define
name|SF_TXBYTECNT
value|0x501C
end_define

begin_define
define|#
directive|define
name|SF_RETXCNT
value|0x5020
end_define

begin_define
define|#
directive|define
name|SF_RANDNUM
value|0x5024
end_define

begin_define
define|#
directive|define
name|SF_RANDNUM_MASK
value|0x5028
end_define

begin_define
define|#
directive|define
name|SF_TOTALTXCNT
value|0x5034
end_define

begin_define
define|#
directive|define
name|SF_RXBYTECNT
value|0x5040
end_define

begin_define
define|#
directive|define
name|SF_TXPAUSETIMER
value|0x5060
end_define

begin_define
define|#
directive|define
name|SF_VLANTYPE
value|0x5064
end_define

begin_define
define|#
directive|define
name|SF_MIISTATUS
value|0x5070
end_define

begin_define
define|#
directive|define
name|SF_MACCFG1_HUGEFRAMES
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SF_MACCFG1_FULLDUPLEX
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SF_MACCFG1_AUTOPAD
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SF_MACCFG1_HDJAM
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SF_MACCFG1_DELAYCRC
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SF_MACCFG1_NOBACKOFF
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SF_MACCFG1_LENGTHCHECK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SF_MACCFG1_PUREPREAMBLE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SF_MACCFG1_PASSALLRX
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SF_MACCFG1_PREAM_DETCNT
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SF_MACCFG1_RX_FLOWENB
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SF_MACCFG1_TX_FLOWENB
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SF_MACCFG1_TESTMODE
value|0x00003000
end_define

begin_define
define|#
directive|define
name|SF_MACCFG1_MIILOOPBK
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SF_MACCFG1_SOFTRESET
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SF_MACCFG2_AUTOVLANPAD
value|0x00000020
end_define

begin_comment
comment|/*  * There are the recommended IPG nibble counter settings  * specified in the Adaptec manual for full duplex and  * half duplex operation.  */
end_comment

begin_define
define|#
directive|define
name|SF_IPGT_FDX
value|0x15
end_define

begin_define
define|#
directive|define
name|SF_IPGT_HDX
value|0x11
end_define

begin_comment
comment|/*  * RX filter registers 0x6000 to 0x6FFF  */
end_comment

begin_define
define|#
directive|define
name|SF_RXFILT_PERFECT_BASE
value|0x6000
end_define

begin_define
define|#
directive|define
name|SF_RXFILT_PERFECT_MAX
value|0x60FF
end_define

begin_define
define|#
directive|define
name|SF_RXFILT_PERFECT_SKIP
value|0x0010
end_define

begin_define
define|#
directive|define
name|SF_RXFILT_PERFECT_CNT
value|0x0010
end_define

begin_define
define|#
directive|define
name|SF_RXFILT_HASH_BASE
value|0x6100
end_define

begin_define
define|#
directive|define
name|SF_RXFILT_HASH_MAX
value|0x62FF
end_define

begin_define
define|#
directive|define
name|SF_RXFILT_HASH_SKIP
value|0x0010
end_define

begin_define
define|#
directive|define
name|SF_RXFILT_HASH_CNT
value|0x001F
end_define

begin_define
define|#
directive|define
name|SF_RXFILT_HASH_ADDROFF
value|0x0000
end_define

begin_define
define|#
directive|define
name|SF_RXFILT_HASH_PRIOOFF
value|0x0004
end_define

begin_define
define|#
directive|define
name|SF_RXFILT_HASH_VLANOFF
value|0x0008
end_define

begin_comment
comment|/*  * Statistics registers 0x7000 to 0x7FFF  */
end_comment

begin_define
define|#
directive|define
name|SF_STATS_BASE
value|0x7000
end_define

begin_define
define|#
directive|define
name|SF_STATS_END
value|0x7FFF
end_define

begin_define
define|#
directive|define
name|SF_STATS_TX_FRAMES
value|0x0000
end_define

begin_define
define|#
directive|define
name|SF_STATS_TX_SINGLE_COL
value|0x0004
end_define

begin_define
define|#
directive|define
name|SF_STATS_TX_MULTI_COL
value|0x0008
end_define

begin_define
define|#
directive|define
name|SF_STATS_TX_CRC_ERRS
value|0x000C
end_define

begin_define
define|#
directive|define
name|SF_STATS_TX_BYTES
value|0x0010
end_define

begin_define
define|#
directive|define
name|SF_STATS_TX_DEFERRED
value|0x0014
end_define

begin_define
define|#
directive|define
name|SF_STATS_TX_LATE_COL
value|0x0018
end_define

begin_define
define|#
directive|define
name|SF_STATS_TX_PAUSE
value|0x001C
end_define

begin_define
define|#
directive|define
name|SF_STATS_TX_CTL_FRAME
value|0x0020
end_define

begin_define
define|#
directive|define
name|SF_STATS_TX_EXCESS_COL
value|0x0024
end_define

begin_define
define|#
directive|define
name|SF_STATS_TX_EXCESS_DEF
value|0x0028
end_define

begin_define
define|#
directive|define
name|SF_STATS_TX_MULTI
value|0x002C
end_define

begin_define
define|#
directive|define
name|SF_STATS_TX_BCAST
value|0x0030
end_define

begin_define
define|#
directive|define
name|SF_STATS_TX_FRAME_LOST
value|0x0034
end_define

begin_define
define|#
directive|define
name|SF_STATS_RX_FRAMES
value|0x0038
end_define

begin_define
define|#
directive|define
name|SF_STATS_RX_CRC_ERRS
value|0x003C
end_define

begin_define
define|#
directive|define
name|SF_STATS_RX_ALIGN_ERRS
value|0x0040
end_define

begin_define
define|#
directive|define
name|SF_STATS_RX_BYTES
value|0x0044
end_define

begin_define
define|#
directive|define
name|SF_STATS_RX_PAUSE
value|0x0048
end_define

begin_define
define|#
directive|define
name|SF_STATS_RX_CTL_FRAME
value|0x004C
end_define

begin_define
define|#
directive|define
name|SF_STATS_RX_UNSUP_FRAME
value|0x0050
end_define

begin_define
define|#
directive|define
name|SF_STATS_RX_GIANTS
value|0x0054
end_define

begin_define
define|#
directive|define
name|SF_STATS_RX_RUNTS
value|0x0058
end_define

begin_define
define|#
directive|define
name|SF_STATS_RX_JABBER
value|0x005C
end_define

begin_define
define|#
directive|define
name|SF_STATS_RX_FRAGMENTS
value|0x0060
end_define

begin_define
define|#
directive|define
name|SF_STATS_RX_64
value|0x0064
end_define

begin_define
define|#
directive|define
name|SF_STATS_RX_65_127
value|0x0068
end_define

begin_define
define|#
directive|define
name|SF_STATS_RX_128_255
value|0x006C
end_define

begin_define
define|#
directive|define
name|SF_STATS_RX_256_511
value|0x0070
end_define

begin_define
define|#
directive|define
name|SF_STATS_RX_512_1023
value|0x0074
end_define

begin_define
define|#
directive|define
name|SF_STATS_RX_1024_1518
value|0x0078
end_define

begin_define
define|#
directive|define
name|SF_STATS_RX_FRAME_LOST
value|0x007C
end_define

begin_define
define|#
directive|define
name|SF_STATS_TX_UNDERRUN
value|0x0080
end_define

begin_comment
comment|/*  * TX frame processor instruction space 0x8000 to 0x9FFF  */
end_comment

begin_define
define|#
directive|define
name|SF_TXGFP_MEM_BASE
value|0x8000
end_define

begin_define
define|#
directive|define
name|SF_TXGFP_MEM_END
value|0x8FFF
end_define

begin_comment
comment|/* Number of bytes of an GFP instruction. */
end_comment

begin_define
define|#
directive|define
name|SF_GFP_INST_BYTES
value|6
end_define

begin_comment
comment|/*  * RX frame processor instruction space 0xA000 to 0xBFFF  */
end_comment

begin_define
define|#
directive|define
name|SF_RXGFP_MEM_BASE
value|0xA000
end_define

begin_define
define|#
directive|define
name|SF_RXGFP_MEM_END
value|0xBFFF
end_define

begin_comment
comment|/*  * Ethernet FIFO access space 0xC000 to 0xDFFF  */
end_comment

begin_comment
comment|/*  * Reserved 0xE000 to 0xFFFF  */
end_comment

begin_comment
comment|/*  * Descriptor data structures.  */
end_comment

begin_comment
comment|/*  * RX buffer descriptor type 0, 32-bit addressing.  */
end_comment

begin_struct
struct|struct
name|sf_rx_bufdesc_type0
block|{
name|uint32_t
name|sf_addrlo
decl_stmt|;
define|#
directive|define
name|SF_RX_DESC_VALID
value|0x00000001
define|#
directive|define
name|SF_RX_DESC_END
value|0x00000002
block|}
struct|;
end_struct

begin_comment
comment|/*  * RX buffer descriptor type 1, 64-bit addressing.  */
end_comment

begin_struct
struct|struct
name|sf_rx_bufdesc_type1
block|{
name|uint64_t
name|sf_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * RX completion descriptor, type 0 (short).  */
end_comment

begin_struct
struct|struct
name|sf_rx_cmpdesc_type0
block|{
name|uint32_t
name|sf_rx_status1
decl_stmt|;
define|#
directive|define
name|SF_RX_CMPDESC_LEN
value|0x0000ffff
define|#
directive|define
name|SF_RX_CMPDESC_EIDX
value|0x07ff0000
define|#
directive|define
name|SF_RX_CMPDESC_STAT1
value|0x38000000
define|#
directive|define
name|SF_RX_CMPDESC_ID
value|0x40000000
block|}
struct|;
end_struct

begin_comment
comment|/*  * RX completion descriptor, type 1 (basic). Includes vlan ID  * if this is a vlan-addressed packet, plus extended status.  */
end_comment

begin_struct
struct|struct
name|sf_rx_cmpdesc_type1
block|{
name|uint32_t
name|sf_rx_status1
decl_stmt|;
name|uint32_t
name|sf_rx_status2
decl_stmt|;
define|#
directive|define
name|SF_RX_CMPDESC_VLAN
value|0x0000ffff
define|#
directive|define
name|SF_RX_CMPDESC_STAT2
value|0xffff0000
block|}
struct|;
end_struct

begin_comment
comment|/*  * RX completion descriptor, type 2 (checksum). Includes partial TCP/IP  * checksum instead of vlan tag, plus extended status.  */
end_comment

begin_struct
struct|struct
name|sf_rx_cmpdesc_type2
block|{
name|uint32_t
name|sf_rx_status1
decl_stmt|;
name|uint32_t
name|sf_rx_status2
decl_stmt|;
define|#
directive|define
name|SF_RX_CMPDESC_CSUM2
value|0x0000ffff
block|}
struct|;
end_struct

begin_comment
comment|/*  * RX completion descriptor type 3 (full). Includes timestamp, partial  * TCP/IP checksum, vlan tag plus priority, two extended status fields.  */
end_comment

begin_struct
struct|struct
name|sf_rx_cmpdesc_type3
block|{
name|uint32_t
name|sf_rx_status1
decl_stmt|;
name|uint32_t
name|sf_rx_status2
decl_stmt|;
name|uint32_t
name|sf_rx_status3
decl_stmt|;
define|#
directive|define
name|SF_RX_CMPDESC_CSUM3
value|0xffff0000
define|#
directive|define
name|SF_RX_CMPDESC_VLANPRI
value|0x0000ffff
name|uint32_t
name|sf_rx_timestamp
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SF_RXSTAT1_QUEUE
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT1_FIFOFULL
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT1_OK
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT2_FRAMETYPE_MASK
value|0x00070000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT2_FRAMETYPE_UNKN
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT2_FRAMETYPE_IPV4
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT2_FRAMETYPE_IPV6
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT2_FRAMETYPE_IPX
value|0x00030000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT2_FRAMETYPE_ICMP
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT2_FRAMETYPE_UNSPRT
value|0x00050000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT2_UDP
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT2_TCP
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT2_FRAG
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT2_PCSUM_OK
value|0x00400000
end_define

begin_comment
comment|/* partial checksum ok */
end_comment

begin_define
define|#
directive|define
name|SF_RXSTAT2_CSUM_BAD
value|0x00800000
end_define

begin_comment
comment|/* TCP/IP checksum bad */
end_comment

begin_define
define|#
directive|define
name|SF_RXSTAT2_CSUM_OK
value|0x01000000
end_define

begin_comment
comment|/* TCP/IP checksum ok */
end_comment

begin_define
define|#
directive|define
name|SF_RXSTAT2_VLAN
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT2_BADRXCODE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT2_DRIBBLE
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT2_ISL_CRCERR
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT2_CRCERR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT2_HASH
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT2_PERFECT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT2_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT3_ISL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT3_PAUSE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT3_CONTROL
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT3_HEADER
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT3_TRAILER
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SF_RXSTAT3_START_IDX_MASK
value|0x000007FF
end_define

begin_struct
struct|struct
name|sf_frag
block|{
name|uint32_t
name|sf_addr
decl_stmt|;
name|uint16_t
name|sf_fraglen
decl_stmt|;
name|uint16_t
name|sf_pktlen
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sf_frag_msdos
block|{
name|uint16_t
name|sf_pktlen
decl_stmt|;
name|uint16_t
name|sf_fraglen
decl_stmt|;
name|uint32_t
name|sf_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * TX frame descriptor type 0, 32-bit addressing. One descriptor can  * be used to map multiple packet fragments. Note that the number of  * fragments can be variable depending on how the descriptor spacing  * is specified in the TX descriptor queue control register.  * We always use a spacing of 128 bytes, and a skipfield length of 8  * bytes: this means 16 bytes for the descriptor, including the skipfield,  * with 121 bytes left for fragment maps. Each fragment requires 8 bytes,  * which allows for 14 fragments per descriptor. The total size of the  * transmit buffer queue is limited to 16384 bytes, so with a spacing of  * 128 bytes per descriptor, we have room for 128 descriptors in the queue.  */
end_comment

begin_struct
struct|struct
name|sf_tx_bufdesc_type0
block|{
name|uint32_t
name|sf_tx_ctrl
decl_stmt|;
define|#
directive|define
name|SF_TX_DESC_CRCEN
value|0x01000000
define|#
directive|define
name|SF_TX_DESC_CALTCP
value|0x02000000
define|#
directive|define
name|SF_TX_DESC_END
value|0x04000000
define|#
directive|define
name|SF_TX_DESC_INTR
value|0x08000000
define|#
directive|define
name|SF_TX_DESC_ID
value|0xb0000000
name|uint32_t
name|sf_tx_frag
decl_stmt|;
comment|/* 	 * Depending on descriptor spacing/skip field length it 	 * can have fixed number of struct sf_frag. 	 * struct sf_frag		sf_frags[14]; 	 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * TX buffer descriptor type 1, 32-bit addressing. Each descriptor  * maps a single fragment.  */
end_comment

begin_struct
struct|struct
name|sf_tx_bufdesc_type1
block|{
name|uint32_t
name|sf_tx_ctrl
decl_stmt|;
define|#
directive|define
name|SF_TX_DESC_FRAGLEN
value|0x0000ffff
define|#
directive|define
name|SF_TX_DESC_FRAGCNT
value|0x00ff0000
name|uint32_t
name|sf_addrlo
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * TX buffer descriptor type 2, 64-bit addressing. Each descriptor  * maps a single fragment.  */
end_comment

begin_struct
struct|struct
name|sf_tx_bufdesc_type2
block|{
name|uint32_t
name|sf_tx_ctrl
decl_stmt|;
name|uint32_t
name|sf_tx_reserved
decl_stmt|;
name|uint64_t
name|sf_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* TX buffer descriptor type 3 is not defined. */
end_comment

begin_comment
comment|/*  * TX frame descriptor type 4, 32-bit addressing. This is a special  * case of the type 0 descriptor, identical except that the fragment  * address and length fields are ordered differently. This is done  * to optimize copies in MS-DOS and OS/2 drivers.  */
end_comment

begin_struct
struct|struct
name|sf_tx_bufdesc_type4
block|{
name|uint32_t
name|sf_tx_ctrl
decl_stmt|;
name|uint32_t
name|sf_tx_frag
decl_stmt|;
comment|/* 	 * Depending on descriptor spacing/skip field length it 	 * can have fixed number of struct sf_frag_msdos. 	 * 	 * struct sf_frag_msdos		sf_frags[14]; 	 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Transmit completion queue descriptor formats.  */
end_comment

begin_comment
comment|/*  * Transmit DMA completion descriptor, type 0.  */
end_comment

begin_define
define|#
directive|define
name|SF_TXCMPTYPE_DMA
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SF_TXCMPTYPE_TX
value|0xa0000000
end_define

begin_struct
struct|struct
name|sf_tx_cmpdesc_type0
block|{
name|uint32_t
name|sf_tx_status1
decl_stmt|;
define|#
directive|define
name|SF_TX_CMPDESC_IDX
value|0x00007fff
define|#
directive|define
name|SF_TX_CMPDESC_HIPRI
value|0x00008000
define|#
directive|define
name|SF_TX_CMPDESC_STAT
value|0x1fff0000
define|#
directive|define
name|SF_TX_CMPDESC_TYPE
value|0xe0000000
block|}
struct|;
end_struct

begin_comment
comment|/*  * Transmit completion descriptor, type 1.  */
end_comment

begin_struct
struct|struct
name|sf_tx_cmpdesc_type1
block|{
name|uint32_t
name|sf_tx_status1
decl_stmt|;
name|uint32_t
name|sf_tx_status2
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SF_TXSTAT_CRCERR
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SF_TXSTAT_LENCHECKERR
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SF_TXSTAT_LENRANGEERR
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SF_TXSTAT_TX_OK
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SF_TXSTAT_TX_DEFERED
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SF_TXSTAT_EXCESS_DEFER
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SF_TXSTAT_EXCESS_COLL
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SF_TXSTAT_LATE_COLL
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SF_TXSTAT_TOOBIG
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SF_TXSTAT_TX_UNDERRUN
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SF_TXSTAT_CTLFRAME_OK
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SF_TXSTAT_PAUSEFRAME_OK
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SF_TXSTAT_PAUSED
value|0x10000000
end_define

begin_comment
comment|/* Statistics counters. */
end_comment

begin_struct
struct|struct
name|sf_stats
block|{
name|uint64_t
name|sf_tx_frames
decl_stmt|;
name|uint32_t
name|sf_tx_single_colls
decl_stmt|;
name|uint32_t
name|sf_tx_multi_colls
decl_stmt|;
name|uint32_t
name|sf_tx_crcerrs
decl_stmt|;
name|uint64_t
name|sf_tx_bytes
decl_stmt|;
name|uint32_t
name|sf_tx_deferred
decl_stmt|;
name|uint32_t
name|sf_tx_late_colls
decl_stmt|;
name|uint32_t
name|sf_tx_pause_frames
decl_stmt|;
name|uint32_t
name|sf_tx_control_frames
decl_stmt|;
name|uint32_t
name|sf_tx_excess_colls
decl_stmt|;
name|uint32_t
name|sf_tx_excess_defer
decl_stmt|;
name|uint32_t
name|sf_tx_mcast_frames
decl_stmt|;
name|uint32_t
name|sf_tx_bcast_frames
decl_stmt|;
name|uint32_t
name|sf_tx_frames_lost
decl_stmt|;
name|uint64_t
name|sf_rx_frames
decl_stmt|;
name|uint32_t
name|sf_rx_crcerrs
decl_stmt|;
name|uint32_t
name|sf_rx_alignerrs
decl_stmt|;
name|uint64_t
name|sf_rx_bytes
decl_stmt|;
name|uint32_t
name|sf_rx_pause_frames
decl_stmt|;
name|uint32_t
name|sf_rx_control_frames
decl_stmt|;
name|uint32_t
name|sf_rx_unsup_control_frames
decl_stmt|;
name|uint32_t
name|sf_rx_giants
decl_stmt|;
name|uint32_t
name|sf_rx_runts
decl_stmt|;
name|uint32_t
name|sf_rx_jabbererrs
decl_stmt|;
name|uint32_t
name|sf_rx_fragments
decl_stmt|;
name|uint64_t
name|sf_rx_pkts_64
decl_stmt|;
name|uint64_t
name|sf_rx_pkts_65_127
decl_stmt|;
name|uint64_t
name|sf_rx_pkts_128_255
decl_stmt|;
name|uint64_t
name|sf_rx_pkts_256_511
decl_stmt|;
name|uint64_t
name|sf_rx_pkts_512_1023
decl_stmt|;
name|uint64_t
name|sf_rx_pkts_1024_1518
decl_stmt|;
name|uint32_t
name|sf_rx_frames_lost
decl_stmt|;
name|uint32_t
name|sf_tx_underruns
decl_stmt|;
name|uint32_t
name|sf_tx_gfp_stall
decl_stmt|;
name|uint32_t
name|sf_rx_gfp_stall
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
value|bus_write_4((sc)->sf_res, reg, val)
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
value|bus_read_4((sc)->sf_res, reg)
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
value|bus_read_1((sc)->sf_res, reg)
end_define

begin_struct
struct|struct
name|sf_type
block|{
name|uint16_t
name|sf_vid
decl_stmt|;
name|uint16_t
name|sf_did
decl_stmt|;
name|char
modifier|*
name|sf_name
decl_stmt|;
name|uint16_t
name|sf_sdid
decl_stmt|;
name|char
modifier|*
name|sf_sname
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Use Tx descriptor type 2 : 64bit buffer descriptor */
end_comment

begin_define
define|#
directive|define
name|sf_tx_rdesc
value|sf_tx_bufdesc_type2
end_define

begin_comment
comment|/* Use Rx descriptor type 1 : 64bit buffer descriptor */
end_comment

begin_define
define|#
directive|define
name|sf_rx_rdesc
value|sf_rx_bufdesc_type1
end_define

begin_comment
comment|/* Use Tx completion type 0 */
end_comment

begin_define
define|#
directive|define
name|sf_tx_rcdesc
value|sf_tx_cmpdesc_type0
end_define

begin_comment
comment|/* Use Rx completion type 2  : checksum */
end_comment

begin_define
define|#
directive|define
name|sf_rx_rcdesc
value|sf_rx_cmpdesc_type2
end_define

begin_define
define|#
directive|define
name|SF_TX_DLIST_CNT
value|256
end_define

begin_define
define|#
directive|define
name|SF_RX_DLIST_CNT
value|256
end_define

begin_define
define|#
directive|define
name|SF_TX_CLIST_CNT
value|1024
end_define

begin_define
define|#
directive|define
name|SF_RX_CLIST_CNT
value|1024
end_define

begin_define
define|#
directive|define
name|SF_TX_DLIST_SIZE
value|(sizeof(struct sf_tx_rdesc) * SF_TX_DLIST_CNT)
end_define

begin_define
define|#
directive|define
name|SF_TX_CLIST_SIZE
value|(sizeof(struct sf_tx_rcdesc) * SF_TX_CLIST_CNT)
end_define

begin_define
define|#
directive|define
name|SF_RX_DLIST_SIZE
value|(sizeof(struct sf_rx_rdesc) * SF_RX_DLIST_CNT)
end_define

begin_define
define|#
directive|define
name|SF_RX_CLIST_SIZE
value|(sizeof(struct sf_rx_rcdesc) * SF_RX_CLIST_CNT)
end_define

begin_define
define|#
directive|define
name|SF_RING_ALIGN
value|256
end_define

begin_define
define|#
directive|define
name|SF_RX_ALIGN
value|sizeof(uint32_t)
end_define

begin_define
define|#
directive|define
name|SF_MAXTXSEGS
value|16
end_define

begin_define
define|#
directive|define
name|SF_ADDR_LO
parameter_list|(
name|x
parameter_list|)
value|((uint64_t)(x)& 0xffffffff)
end_define

begin_define
define|#
directive|define
name|SF_ADDR_HI
parameter_list|(
name|x
parameter_list|)
value|((uint64_t)(x)>> 32)
end_define

begin_define
define|#
directive|define
name|SF_TX_DLIST_ADDR
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|((sc)->sf_rdata.sf_tx_ring_paddr + sizeof(struct sf_tx_rdesc) * (i))
end_define

begin_define
define|#
directive|define
name|SF_TX_CLIST_ADDR
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|((sc)->sf_rdata.sf_tx_cring_paddr + sizeof(struct sf_tx_crdesc) * (i))
end_define

begin_define
define|#
directive|define
name|SF_RX_DLIST_ADDR
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|((sc)->sf_rdata.sf_rx_ring_paddr + sizeof(struct sf_rx_rdesc) * (i))
end_define

begin_define
define|#
directive|define
name|SF_RX_CLIST_ADDR
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|((sc)->sf_rdata.sf_rx_cring_paddr + sizeof(struct sf_rx_rcdesc) * (i))
end_define

begin_define
define|#
directive|define
name|SF_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = ((x) + 1) % y
end_define

begin_define
define|#
directive|define
name|SF_MAX_FRAMELEN
value|1536
end_define

begin_define
define|#
directive|define
name|SF_TX_THRESHOLD_UNIT
value|16
end_define

begin_define
define|#
directive|define
name|SF_MAX_TX_THRESHOLD
value|(SF_MAX_FRAMELEN / SF_TX_THRESHOLD_UNIT)
end_define

begin_define
define|#
directive|define
name|SF_MIN_TX_THRESHOLD
value|(128 / SF_TX_THRESHOLD_UNIT)
end_define

begin_struct
struct|struct
name|sf_txdesc
block|{
name|struct
name|mbuf
modifier|*
name|tx_m
decl_stmt|;
name|int
name|ndesc
decl_stmt|;
name|bus_dmamap_t
name|tx_dmamap
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sf_rxdesc
block|{
name|struct
name|mbuf
modifier|*
name|rx_m
decl_stmt|;
name|bus_dmamap_t
name|rx_dmamap
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sf_chain_data
block|{
name|bus_dma_tag_t
name|sf_parent_tag
decl_stmt|;
name|bus_dma_tag_t
name|sf_tx_tag
decl_stmt|;
name|struct
name|sf_txdesc
name|sf_txdesc
index|[
name|SF_TX_DLIST_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|sf_rx_tag
decl_stmt|;
name|struct
name|sf_rxdesc
name|sf_rxdesc
index|[
name|SF_RX_DLIST_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|sf_tx_ring_tag
decl_stmt|;
name|bus_dma_tag_t
name|sf_rx_ring_tag
decl_stmt|;
name|bus_dma_tag_t
name|sf_tx_cring_tag
decl_stmt|;
name|bus_dma_tag_t
name|sf_rx_cring_tag
decl_stmt|;
name|bus_dmamap_t
name|sf_tx_ring_map
decl_stmt|;
name|bus_dmamap_t
name|sf_rx_ring_map
decl_stmt|;
name|bus_dmamap_t
name|sf_rx_sparemap
decl_stmt|;
name|bus_dmamap_t
name|sf_tx_cring_map
decl_stmt|;
name|bus_dmamap_t
name|sf_rx_cring_map
decl_stmt|;
name|int
name|sf_tx_prod
decl_stmt|;
name|int
name|sf_tx_cnt
decl_stmt|;
name|int
name|sf_txc_cons
decl_stmt|;
name|int
name|sf_rxc_cons
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sf_ring_data
block|{
name|struct
name|sf_tx_rdesc
modifier|*
name|sf_tx_ring
decl_stmt|;
name|bus_addr_t
name|sf_tx_ring_paddr
decl_stmt|;
name|struct
name|sf_tx_rcdesc
modifier|*
name|sf_tx_cring
decl_stmt|;
name|bus_addr_t
name|sf_tx_cring_paddr
decl_stmt|;
name|struct
name|sf_rx_rdesc
modifier|*
name|sf_rx_ring
decl_stmt|;
name|bus_addr_t
name|sf_rx_ring_paddr
decl_stmt|;
name|struct
name|sf_rx_rcdesc
modifier|*
name|sf_rx_cring
decl_stmt|;
name|bus_addr_t
name|sf_rx_cring_paddr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sf_softc
block|{
name|struct
name|ifnet
modifier|*
name|sf_ifp
decl_stmt|;
comment|/* interface info */
name|device_t
name|sf_dev
decl_stmt|;
comment|/* device info */
name|void
modifier|*
name|sf_intrhand
decl_stmt|;
comment|/* interrupt handler cookie */
name|struct
name|resource
modifier|*
name|sf_irq
decl_stmt|;
comment|/* irq resource descriptor */
name|struct
name|resource
modifier|*
name|sf_res
decl_stmt|;
comment|/* mem/ioport resource */
name|int
name|sf_restype
decl_stmt|;
name|int
name|sf_rid
decl_stmt|;
name|struct
name|sf_type
modifier|*
name|sf_info
decl_stmt|;
comment|/* Starfire adapter info */
name|device_t
name|sf_miibus
decl_stmt|;
name|struct
name|sf_chain_data
name|sf_cdata
decl_stmt|;
name|struct
name|sf_ring_data
name|sf_rdata
decl_stmt|;
name|int
name|sf_if_flags
decl_stmt|;
name|struct
name|callout
name|sf_co
decl_stmt|;
name|int
name|sf_watchdog_timer
decl_stmt|;
name|int
name|sf_link
decl_stmt|;
name|int
name|sf_suspended
decl_stmt|;
name|int
name|sf_detach
decl_stmt|;
name|uint32_t
name|sf_txthresh
decl_stmt|;
name|int
name|sf_int_mod
decl_stmt|;
name|struct
name|sf_stats
name|sf_statistics
decl_stmt|;
name|struct
name|mtx
name|sf_mtx
decl_stmt|;
ifdef|#
directive|ifdef
name|DEVICE_POLLING
name|int
name|rxcycles
decl_stmt|;
endif|#
directive|endif
comment|/* DEVICE_POLLING */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SF_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sf_mtx)
end_define

begin_define
define|#
directive|define
name|SF_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sf_mtx)
end_define

begin_define
define|#
directive|define
name|SF_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->sf_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|SF_TIMEOUT
value|1000
end_define

end_unit

