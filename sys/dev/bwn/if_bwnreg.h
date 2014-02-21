begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2010 Weongyo Jeong<weongyo@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_BWNREG_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_BWNREG_H
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_COMPAQ
value|0x0e11
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_DELL
value|0x1028
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_HP
value|0x103c
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_ASUSTEK
value|0x1043
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_MOTOROLA
value|0x1057
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_APPLE
value|0x106b
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_BROADCOM
value|0x14e4
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_LINKSYS
value|0x1737
end_define

begin_define
define|#
directive|define
name|BWN_BFL_BTCOEXIST
value|0x0001
end_define

begin_define
define|#
directive|define
name|BWN_BFL_PACTRL
value|0x0002
end_define

begin_define
define|#
directive|define
name|BWN_BFL_RSSI
value|0x0008
end_define

begin_define
define|#
directive|define
name|BWN_BFL_CRYSTAL_NOSLOW
value|0x0020
end_define

begin_define
define|#
directive|define
name|BWN_BFL_FEM
value|0x0800
end_define

begin_define
define|#
directive|define
name|BWN_BFL_EXTLNA
value|0x1000
end_define

begin_define
define|#
directive|define
name|BWN_BFL_HGPA
value|0x2000
end_define

begin_comment
comment|/* had high gain PA */
end_comment

begin_define
define|#
directive|define
name|BWN_BFL_BTCMOD
value|0x4000
end_define

begin_define
define|#
directive|define
name|BWN_BFL_ALTIQ
value|0x8000
end_define

begin_define
define|#
directive|define
name|BWN_BFH_NOPA
value|0x0001
end_define

begin_define
define|#
directive|define
name|BWN_BFH_RSSIINV
value|0x0002
end_define

begin_define
define|#
directive|define
name|BWN_BFH_LDO_PAREF
value|0x0004
end_define

begin_define
define|#
directive|define
name|BWN_BFH_FEM_BT
value|0x0040
end_define

begin_define
define|#
directive|define
name|BWN_TGSLOW_SUPPORT_G
value|0x20000000
end_define

begin_define
define|#
directive|define
name|BWN_TGSLOW_PHYRESET
value|0x00080000
end_define

begin_define
define|#
directive|define
name|BWN_TGSLOW_PHYCLOCK_ENABLE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|BWN_TGSHIGH_HAVE_2GHZ
value|0x00010000
end_define

begin_define
define|#
directive|define
name|BWN_TGSHIGH_HAVE_5GHZ
value|0x00020000
end_define

begin_define
define|#
directive|define
name|BWN_PHYTYPE_A
value|0x00
end_define

begin_define
define|#
directive|define
name|BWN_PHYTYPE_B
value|0x01
end_define

begin_define
define|#
directive|define
name|BWN_PHYTYPE_G
value|0x02
end_define

begin_define
define|#
directive|define
name|BWN_PHYTYPE_N
value|0x04
end_define

begin_define
define|#
directive|define
name|BWN_PHYTYPE_LP
value|0x05
end_define

begin_define
define|#
directive|define
name|BWN_DMA0_REASON
value|0x20
end_define

begin_define
define|#
directive|define
name|BWN_DMA0_INTR_MASK
value|0x24
end_define

begin_define
define|#
directive|define
name|BWN_DMA1_REASON
value|0x28
end_define

begin_define
define|#
directive|define
name|BWN_DMA1_INTR_MASK
value|0x2c
end_define

begin_define
define|#
directive|define
name|BWN_DMA2_REASON
value|0x30
end_define

begin_define
define|#
directive|define
name|BWN_DMA2_INTR_MASK
value|0x34
end_define

begin_define
define|#
directive|define
name|BWN_DMA3_REASON
value|0x38
end_define

begin_define
define|#
directive|define
name|BWN_DMA3_INTR_MASK
value|0x3c
end_define

begin_define
define|#
directive|define
name|BWN_DMA4_REASON
value|0x40
end_define

begin_define
define|#
directive|define
name|BWN_DMA4_INTR_MASK
value|0x44
end_define

begin_define
define|#
directive|define
name|BWN_DMA5_INTR_MASK
value|0x4c
end_define

begin_define
define|#
directive|define
name|BWN_MACCTL
value|0x120
end_define

begin_define
define|#
directive|define
name|BWN_MACCTL_ON
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BWN_MACCTL_MCODE_RUN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BWN_MACCTL_MCODE_JMP0
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BWN_MACCTL_SHM_ON
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BWN_MACCTL_IHR_ON
value|0x00000400
end_define

begin_define
define|#
directive|define
name|BWN_MACCTL_GPOUT_MASK
value|0x0000c000
end_define

begin_define
define|#
directive|define
name|BWN_MACCTL_BIGENDIAN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|BWN_MACCTL_STA
value|0x00020000
end_define

begin_define
define|#
directive|define
name|BWN_MACCTL_HOSTAP
value|0x00040000
end_define

begin_define
define|#
directive|define
name|BWN_MACCTL_RADIO_LOCK
value|0x00080000
end_define

begin_define
define|#
directive|define
name|BWN_MACCTL_BEACON_PROMISC
value|0x00100000
end_define

begin_define
define|#
directive|define
name|BWN_MACCTL_PASS_BADPLCP
value|0x00200000
end_define

begin_define
define|#
directive|define
name|BWN_MACCTL_PASS_CTL
value|0x00400000
end_define

begin_define
define|#
directive|define
name|BWN_MACCTL_PASS_BADFCS
value|0x00800000
end_define

begin_define
define|#
directive|define
name|BWN_MACCTL_PROMISC
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BWN_MACCTL_HWPS
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BWN_MACCTL_AWAKE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|BWN_MACCTL_GMODE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BWN_MACCMD
value|0x124
end_define

begin_comment
comment|/* MAC command */
end_comment

begin_define
define|#
directive|define
name|BWN_MACCMD_BEACON0_VALID
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BWN_MACCMD_BEACON1_VALID
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BWN_MACCMD_DFQ_VALID
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BWN_MACCMD_BGNOISE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BWN_INTR_REASON
value|0x128
end_define

begin_define
define|#
directive|define
name|BWN_INTR_MASK
value|0x12c
end_define

begin_define
define|#
directive|define
name|BWN_RAM_CONTROL
value|0x130
end_define

begin_define
define|#
directive|define
name|BWN_RAM_DATA
value|0x134
end_define

begin_define
define|#
directive|define
name|BWN_PS_STATUS
value|0x140
end_define

begin_define
define|#
directive|define
name|BWN_RF_HWENABLED_HI
value|0x158
end_define

begin_define
define|#
directive|define
name|BWN_RF_HWENABLED_HI_MASK
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|BWN_SHM_CONTROL
value|0x160
end_define

begin_define
define|#
directive|define
name|BWN_SHM_DATA
value|0x164
end_define

begin_define
define|#
directive|define
name|BWN_SHM_DATA_UNALIGNED
value|0x166
end_define

begin_define
define|#
directive|define
name|BWN_XMITSTAT_0
value|0x170
end_define

begin_define
define|#
directive|define
name|BWN_XMITSTAT_1
value|0x174
end_define

begin_define
define|#
directive|define
name|BWN_REV3PLUS_TSF_LOW
value|0x180
end_define

begin_comment
comment|/* core rev>= 3 only */
end_comment

begin_define
define|#
directive|define
name|BWN_REV3PLUS_TSF_HIGH
value|0x184
end_define

begin_comment
comment|/* core rev>= 3 only */
end_comment

begin_define
define|#
directive|define
name|BWN_TSF_CFP_START
value|0x18c
end_define

begin_comment
comment|/* 32-bit DMA */
end_comment

begin_define
define|#
directive|define
name|BWN_DMA32_BASE0
value|0x200
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_BASE1
value|0x220
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_BASE2
value|0x240
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_BASE3
value|0x260
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_BASE4
value|0x280
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_BASE5
value|0x2a0
end_define

begin_comment
comment|/* 64-bit DMA */
end_comment

begin_define
define|#
directive|define
name|BWN_DMA64_BASE0
value|0x200
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_BASE1
value|0x240
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_BASE2
value|0x280
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_BASE3
value|0x2c0
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_BASE4
value|0x300
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_BASE5
value|0x340
end_define

begin_comment
comment|/* PIO on core rev< 11 */
end_comment

begin_define
define|#
directive|define
name|BWN_PIO_BASE0
value|0x300
end_define

begin_define
define|#
directive|define
name|BWN_PIO_BASE1
value|0x310
end_define

begin_define
define|#
directive|define
name|BWN_PIO_BASE2
value|0x320
end_define

begin_define
define|#
directive|define
name|BWN_PIO_BASE3
value|0x330
end_define

begin_define
define|#
directive|define
name|BWN_PIO_BASE4
value|0x340
end_define

begin_define
define|#
directive|define
name|BWN_PIO_BASE5
value|0x350
end_define

begin_define
define|#
directive|define
name|BWN_PIO_BASE6
value|0x360
end_define

begin_define
define|#
directive|define
name|BWN_PIO_BASE7
value|0x370
end_define

begin_comment
comment|/* PIO on core rev>= 11 */
end_comment

begin_define
define|#
directive|define
name|BWN_PIO11_BASE0
value|0x200
end_define

begin_define
define|#
directive|define
name|BWN_PIO11_BASE1
value|0x240
end_define

begin_define
define|#
directive|define
name|BWN_PIO11_BASE2
value|0x280
end_define

begin_define
define|#
directive|define
name|BWN_PIO11_BASE3
value|0x2c0
end_define

begin_define
define|#
directive|define
name|BWN_PIO11_BASE4
value|0x300
end_define

begin_define
define|#
directive|define
name|BWN_PIO11_BASE5
value|0x340
end_define

begin_define
define|#
directive|define
name|BWN_GPIOCTL
value|0x06c
end_define

begin_define
define|#
directive|define
name|BWN_PHYVER
value|0x3e0
end_define

begin_define
define|#
directive|define
name|BWN_PHYVER_ANALOG
value|0xf000
end_define

begin_define
define|#
directive|define
name|BWN_PHYVER_TYPE
value|0x0f00
end_define

begin_define
define|#
directive|define
name|BWN_PHYVER_VERSION
value|0x00ff
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RADIO
value|0x3e2
end_define

begin_define
define|#
directive|define
name|BWN_PHY0
value|0x3e6
end_define

begin_define
define|#
directive|define
name|BWN_CHANNEL
value|0x3f0
end_define

begin_define
define|#
directive|define
name|BWN_CHANNEL_EXT
value|0x3f4
end_define

begin_define
define|#
directive|define
name|BWN_RFCTL
value|0x3f6
end_define

begin_define
define|#
directive|define
name|BWN_RFCTL_ID
value|0x01
end_define

begin_define
define|#
directive|define
name|BWN_RFDATAHI
value|0x3f8
end_define

begin_define
define|#
directive|define
name|BWN_RFDATALO
value|0x3fa
end_define

begin_define
define|#
directive|define
name|BWN_PHYCTL
value|0x3fc
end_define

begin_define
define|#
directive|define
name|BWN_PHYDATA
value|0x3fe
end_define

begin_define
define|#
directive|define
name|BWN_MACFILTER_CONTROL
value|0x420
end_define

begin_define
define|#
directive|define
name|BWN_MACFILTER_DATA
value|0x422
end_define

begin_define
define|#
directive|define
name|BWN_RCMTA_COUNT
value|0x43c
end_define

begin_define
define|#
directive|define
name|BWN_RF_HWENABLED_LO
value|0x49a
end_define

begin_define
define|#
directive|define
name|BWN_RF_HWENABLED_LO_MASK
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|BWN_GPIO_CONTROL
value|0x49c
end_define

begin_define
define|#
directive|define
name|BWN_GPIO_MASK
value|0x49e
end_define

begin_define
define|#
directive|define
name|BWN_TSF_CFP_START_LOW
value|0x604
end_define

begin_define
define|#
directive|define
name|BWN_TSF_CFP_START_HIGH
value|0x606
end_define

begin_define
define|#
directive|define
name|BWN_TSF_CFP_PRETBTT
value|0x612
end_define

begin_define
define|#
directive|define
name|BWN_RNG
value|0x65a
end_define

begin_define
define|#
directive|define
name|BWN_IFSCTL
value|0x688
end_define

begin_comment
comment|/* Interframe space control */
end_comment

begin_define
define|#
directive|define
name|BWN_IFSCTL_USE_EDCF
value|0x0004
end_define

begin_define
define|#
directive|define
name|BWN_POWERUP_DELAY
value|0x6a8
end_define

begin_define
define|#
directive|define
name|BWN_BTCOEX_CTL
value|0x6b4
end_define

begin_define
define|#
directive|define
name|BWN_BTCOEX_TXCTL
value|0x6b8
end_define

begin_define
define|#
directive|define
name|BWN_UCODE
value|0x0
end_define

begin_define
define|#
directive|define
name|BWN_HW
value|0x3
end_define

begin_define
define|#
directive|define
name|BWN_RCMTA
value|0x4
end_define

begin_define
define|#
directive|define
name|BWN_TSSI_MAX
value|0x7f
end_define

begin_define
define|#
directive|define
name|BWN_SHARED
value|0x1
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_UCODE_REV
value|0x0000
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_UCODE_PATCH
value|0x0002
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_UCODE_DATE
value|0x0004
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_UCODE_TIME
value|0x0006
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_COREREV
value|0x0016
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_ACKCTS_PHYCTL
value|0x0022
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_RX_PADOFFSET
value|0x0034
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_UCODESTAT
value|0x0040
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_UCODESTAT_SUSPEND
value|3
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_UCODESTAT_SLEEP
value|4
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_FWCAPS
value|0x0042
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_SHORT_RETRY_FALLBACK
value|0x0044
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_LONG_RETRY_FALLBACK
value|0x0046
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_BEACON_PHYCTL
value|0x0054
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_KEY_TABLEP
value|0x0056
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_TSSI_CCK
value|0x0058
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_HFLO
value|0x005e
end_define

begin_comment
comment|/* low hostflag */
end_comment

begin_define
define|#
directive|define
name|BWN_SHARED_HFMI
value|0x0060
end_define

begin_comment
comment|/* middle hostflag */
end_comment

begin_define
define|#
directive|define
name|BWN_SHARED_HFHI
value|0x0062
end_define

begin_comment
comment|/* high hostflag */
end_comment

begin_define
define|#
directive|define
name|BWN_SHARED_RADIO_ATT
value|0x0064
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_TSSI_OFDM_G
value|0x0070
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_PROBE_RESP_MAXTIME
value|0x0074
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_SPU_WAKEUP
value|0x0094
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_PRETBTT
value|0x0096
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_CHAN
value|0x00a0
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_AUTOINC
value|0x0100
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_PROBE_RESP_PHYCTL
value|0x0188
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_EDCFQ
value|0x0240
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_KEYIDX_BLOCK
value|0x05d4
end_define

begin_define
define|#
directive|define
name|BWN_SHARED_PSM
value|0x05f4
end_define

begin_comment
comment|/* SHM_SCRATCH offsets */
end_comment

begin_define
define|#
directive|define
name|BWN_SCRATCH
value|0x2
end_define

begin_define
define|#
directive|define
name|BWN_SCRATCH_CONT_MIN
value|0x0003
end_define

begin_define
define|#
directive|define
name|BWN_SCRATCH_CONT_MAX
value|0x0004
end_define

begin_define
define|#
directive|define
name|BWN_SCRATCH_SHORT_RETRY
value|0x0006
end_define

begin_define
define|#
directive|define
name|BWN_SCRATCH_LONG_RETRY
value|0x0007
end_define

begin_comment
comment|/* Generic-Interrupt reasons. */
end_comment

begin_define
define|#
directive|define
name|BWN_INTR_MAC_SUSPENDED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BWN_INTR_BEACON
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BWN_INTR_TBTT_INDI
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BWN_INTR_ATIM_END
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BWN_INTR_PMQ
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BWN_INTR_MAC_TXERR
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BWN_INTR_PHY_TXERR
value|0x00000800
end_define

begin_define
define|#
directive|define
name|BWN_INTR_DMA
value|0x00008000
end_define

begin_define
define|#
directive|define
name|BWN_INTR_TXFIFO_FLUSH_OK
value|0x00010000
end_define

begin_define
define|#
directive|define
name|BWN_INTR_NOISESAMPLE_OK
value|0x00040000
end_define

begin_define
define|#
directive|define
name|BWN_INTR_UCODE_DEBUG
value|0x08000000
end_define

begin_define
define|#
directive|define
name|BWN_INTR_RFKILL
value|0x10000000
end_define

begin_define
define|#
directive|define
name|BWN_INTR_TX_OK
value|0x20000000
end_define

begin_define
define|#
directive|define
name|BWN_INTR_ALL
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|BWN_INTR_MASKTEMPLATE
define|\
value|(BWN_INTR_TBTT_INDI | BWN_INTR_ATIM_END | BWN_INTR_PMQ |	\ 	 BWN_INTR_MAC_TXERR | BWN_INTR_PHY_TXERR | BWN_INTR_DMA |	\ 	 BWN_INTR_TXFIFO_FLUSH_OK | BWN_INTR_NOISESAMPLE_OK |	\ 	 BWN_INTR_UCODE_DEBUG | BWN_INTR_RFKILL | BWN_INTR_TX_OK)
end_define

begin_define
define|#
directive|define
name|BWN_HF_UCODE_ANTDIV_HELPER
value|0x000000000001ull
end_define

begin_define
define|#
directive|define
name|BWN_HF_GPHY_SYM_WORKAROUND
value|0x000000000002ull
end_define

begin_define
define|#
directive|define
name|BWN_HF_4DB_CCK_POWERBOOST
value|0x000000000008ull
end_define

begin_define
define|#
directive|define
name|BWN_HF_BT_COEXIST
value|0x000000000010ull
end_define

begin_define
define|#
directive|define
name|BWN_HF_GPHY_DC_CANCELFILTER
value|0x000000000020ull
end_define

begin_define
define|#
directive|define
name|BWN_HF_PAGAINBOOST_OFDM_ON
value|0x000000000040ull
end_define

begin_define
define|#
directive|define
name|BWN_HF_JAPAN_CHAN14_OFF
value|0x000000000080ull
end_define

begin_define
define|#
directive|define
name|BWN_HF_EDCF
value|0x000000000100ull
end_define

begin_define
define|#
directive|define
name|BWN_HF_TSSI_RESET_PSM_WORKAROUN
value|0x000000000200ull
end_define

begin_define
define|#
directive|define
name|BWN_HF_SLOWCLOCK_REQ_OFF
value|0x000000000400ull
end_define

begin_define
define|#
directive|define
name|BWN_HF_ACI_WORKAROUND
value|0x000000000800ull
end_define

begin_define
define|#
directive|define
name|BWN_HF_2060_RADIO_WORKAROUND
value|0x000000001000ull
end_define

begin_define
define|#
directive|define
name|BWN_HF_FORCE_VCO_RECALC
value|0x000000040000ull
end_define

begin_define
define|#
directive|define
name|BWN_HF_PCI_SLOWCLOCK_WORKAROUND
value|0x000000080000ull
end_define

begin_define
define|#
directive|define
name|BWN_HF_4318_TSSI
value|0x000000200000ull
end_define

begin_define
define|#
directive|define
name|BWN_HF_HW_POWERCTL
value|0x000000800000ull
end_define

begin_define
define|#
directive|define
name|BWN_HF_BT_COEXISTALT
value|0x000001000000ull
end_define

begin_define
define|#
directive|define
name|BWN_HF_SKIP_CFP_UPDATE
value|0x000004000000ull
end_define

begin_define
define|#
directive|define
name|BWN_HF_PR45960W
value|0x080000000000ULL
end_define

begin_define
define|#
directive|define
name|BWN_TX_PHY_ENC_CCK
value|0x0000
end_define

begin_define
define|#
directive|define
name|BWN_TX_PHY_ENC_OFDM
value|0x0001
end_define

begin_define
define|#
directive|define
name|BWN_TX_PHY_SHORTPRMBL
value|0x0010
end_define

begin_define
define|#
directive|define
name|BWN_TX_PHY_ANT
value|0x03c0
end_define

begin_define
define|#
directive|define
name|BWN_TX_PHY_ANT0
value|0x0000
end_define

begin_define
define|#
directive|define
name|BWN_TX_PHY_ANT1
value|0x0040
end_define

begin_define
define|#
directive|define
name|BWN_TX_PHY_ANT01AUTO
value|0x00c0
end_define

begin_define
define|#
directive|define
name|BWN_TX_PHY_ANT2
value|0x0100
end_define

begin_define
define|#
directive|define
name|BWN_TX_PHY_ANT3
value|0x0200
end_define

begin_define
define|#
directive|define
name|BWN_TX_PHY_TXPWR
value|0xfc00
end_define

begin_define
define|#
directive|define
name|BWN_TX_MAC_ACK
value|0x00000001
end_define

begin_comment
comment|/* immediate ACK */
end_comment

begin_define
define|#
directive|define
name|BWN_TX_MAC_LONGFRAME
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BWN_TX_MAC_SEND_RTSCTS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BWN_TX_MAC_START_MSDU
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BWN_TX_MAC_HWSEQ
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BWN_TX_MAC_5GHZ
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BWN_TX_MAC_SEND_CTSTOSELF
value|0x00000800
end_define

begin_define
define|#
directive|define
name|BWN_TX_EFT_FB_CCK
value|0x00
end_define

begin_define
define|#
directive|define
name|BWN_TX_EFT_FB_OFDM
value|0x01
end_define

begin_define
define|#
directive|define
name|BWN_TX_EFT_RTS_CCK
value|0x00
end_define

begin_define
define|#
directive|define
name|BWN_TX_EFT_RTS_OFDM
value|0x04
end_define

begin_define
define|#
directive|define
name|BWN_TX_EFT_RTS_FBCCK
value|0x00
end_define

begin_define
define|#
directive|define
name|BWN_TX_EFT_RTS_FBOFDM
value|0x10
end_define

begin_define
define|#
directive|define
name|BWN_PIO_TXCTL
value|0x00
end_define

begin_define
define|#
directive|define
name|BWN_PIO_TXCTL_WRITELO
value|0x0001
end_define

begin_define
define|#
directive|define
name|BWN_PIO_TXCTL_WRITEHI
value|0x0002
end_define

begin_define
define|#
directive|define
name|BWN_PIO_TXCTL_EOF
value|0x0004
end_define

begin_define
define|#
directive|define
name|BWN_PIO_TXCTL_FRAMEREADY
value|0x0008
end_define

begin_define
define|#
directive|define
name|BWN_PIO_TXDATA
value|0x02
end_define

begin_define
define|#
directive|define
name|BWN_PIO_TXQBUFSIZE
value|0x04
end_define

begin_define
define|#
directive|define
name|BWN_PIO_RXCTL
value|0x00
end_define

begin_define
define|#
directive|define
name|BWN_PIO_RXCTL_FRAMEREADY
value|0x0001
end_define

begin_define
define|#
directive|define
name|BWN_PIO_RXCTL_DATAREADY
value|0x0002
end_define

begin_define
define|#
directive|define
name|BWN_PIO_RXDATA
value|0x02
end_define

begin_define
define|#
directive|define
name|BWN_PIO8_TXCTL
value|0x00
end_define

begin_define
define|#
directive|define
name|BWN_PIO8_TXCTL_0_7
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BWN_PIO8_TXCTL_8_15
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BWN_PIO8_TXCTL_16_23
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BWN_PIO8_TXCTL_24_31
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BWN_PIO8_TXCTL_EOF
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BWN_PIO8_TXCTL_FRAMEREADY
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BWN_PIO8_TXDATA
value|0x04
end_define

begin_define
define|#
directive|define
name|BWN_PIO8_RXCTL
value|0x00
end_define

begin_define
define|#
directive|define
name|BWN_PIO8_RXCTL_FRAMEREADY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BWN_PIO8_RXCTL_DATAREADY
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BWN_PIO8_RXDATA
value|0x04
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_TXCTL
value|0x00
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_TXENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_TXSUSPEND
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_TXADDREXT_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_TXADDREXT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_TXRING
value|0x04
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_TXINDEX
value|0x08
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_TXSTATUS
value|0x0c
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_TXSTATE
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_TXSTAT_DISABLED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_TXSTAT_IDLEWAIT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_TXSTAT_STOPPED
value|0x00003000
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_RXCTL
value|0x10
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_RXENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_RXFROFF_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_RXDIRECTFIFO
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_RXADDREXT_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_RXADDREXT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_RXRING
value|0x14
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_RXINDEX
value|0x18
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_RXSTATUS
value|0x1c
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_RXDPTR
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_RXSTATE
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|BWN_DMA32_RXSTAT_DISABLED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_TXCTL
value|0x00
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_TXENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_TXSUSPEND
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_TXADDREXT_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_TXADDREXT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_TXINDEX
value|0x04
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_TXRINGLO
value|0x08
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_TXRINGHI
value|0x0c
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_TXSTATUS
value|0x10
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_TXSTAT
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_TXSTAT_DISABLED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_TXSTAT_IDLEWAIT
value|0x20000000
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_TXSTAT_STOPPED
value|0x30000000
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_RXCTL
value|0x20
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_RXENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_RXFROFF_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_RXDIRECTFIFO
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_RXADDREXT_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_RXADDREXT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_RXINDEX
value|0x24
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_RXRINGLO
value|0x28
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_RXRINGHI
value|0x2c
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_RXSTATUS
value|0x30
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_RXSTATDPTR
value|0x00001fff
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_RXSTAT
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|BWN_DMA64_RXSTAT_DISABLED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BWN_DMA_RINGMEMSIZE
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|BWN_DMA0_RX_FRAMEOFFSET
value|30
end_define

begin_define
define|#
directive|define
name|BWN_TXRING_SLOTS
value|64
end_define

begin_define
define|#
directive|define
name|BWN_RXRING_SLOTS
value|64
end_define

begin_define
define|#
directive|define
name|BWN_DMA0_RX_BUFFERSIZE
value|IEEE80211_MAX_LEN
end_define

begin_define
define|#
directive|define
name|BWN_PHYROUTE_BASE
value|0x0000
end_define

begin_define
define|#
directive|define
name|BWN_PHYROUTE_OFDM_GPHY
value|0x0400
end_define

begin_define
define|#
directive|define
name|BWN_PHYROUTE_EXT_GPHY
value|0x0800
end_define

begin_define
define|#
directive|define
name|BWN_PHY_CCK
parameter_list|(
name|reg
parameter_list|)
value|((reg) | BWN_PHYROUTE_BASE)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_N_BMODE
parameter_list|(
name|reg
parameter_list|)
value|((reg) | BWN_PHYROUTE_N_BMODE)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_OFDM
parameter_list|(
name|reg
parameter_list|)
value|((reg) | BWN_PHYROUTE_OFDM_GPHY)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_EXTG
parameter_list|(
name|reg
parameter_list|)
value|((reg) | BWN_PHYROUTE_EXT_GPHY)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_VERSION_OFDM
value|BWN_PHY_OFDM(0x00)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_BBANDCFG
value|BWN_PHY_OFDM(0x01)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_BBANDCFG_RXANT
value|0x180
end_define

begin_define
define|#
directive|define
name|BWN_PHY_BBANDCFG_RXANT_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|BWN_PHY_PWRDOWN
value|BWN_PHY_OFDM(0x03)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_CRSTHRES1_R1
value|BWN_PHY_OFDM(0x06)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_CRSGAIN_CTL
value|BWN_PHY_OFDM(0x10)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_MINPWR_LEVEL
value|BWN_PHY_OFDM(0x16)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_OFDMSYNCTHRESH0
value|BWN_PHY_OFDM(0x17)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_IDLEAFTERPKTRXTO
value|BWN_PHY_OFDM(0x1a)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_LNAHPFCTL
value|BWN_PHY_OFDM(0x1c)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_DCOFFSETTRANSIENT
value|BWN_PHY_OFDM(0x1c)
end_define

begin_comment
comment|/* for LP */
end_comment

begin_define
define|#
directive|define
name|BWN_PHY_PREAMBLECONFIRMTO
value|BWN_PHY_OFDM(0x1e)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_CLIPTHRESH
value|BWN_PHY_OFDM(0x1f)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_LPFGAINCTL
value|BWN_PHY_OFDM(0x20)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_CLIPCTRTHRESH
value|BWN_PHY_OFDM(0x20)
end_define

begin_comment
comment|/* for LP */
end_comment

begin_define
define|#
directive|define
name|BWN_PHY_HIGAINDB
value|BWN_PHY_OFDM(0x23)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_LOWGAINDB
value|BWN_PHY_OFDM(0x24)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_VERYLOWGAINDB
value|BWN_PHY_OFDM(0x25)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_GAINMISMATCH
value|BWN_PHY_OFDM(0x26)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_ADIVRELATED
value|BWN_PHY_OFDM(0x27)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_GAINDIRECTMISMATCH
value|BWN_PHY_OFDM(0x27)
end_define

begin_comment
comment|/* for LP */
end_comment

begin_define
define|#
directive|define
name|BWN_PHY_CRS0
value|BWN_PHY_OFDM(0x29)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_CRS0_EN
value|0x4000
end_define

begin_define
define|#
directive|define
name|BWN_PHY_PWR_THRESH1
value|BWN_PHY_OFDM(0x29)
end_define

begin_comment
comment|/* for LP */
end_comment

begin_define
define|#
directive|define
name|BWN_PHY_ANTDWELL
value|BWN_PHY_OFDM(0x2b)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_ANTDWELL_AUTODIV1
value|0x0100
end_define

begin_define
define|#
directive|define
name|BWN_PHY_DSSS_CONFIRM_CNT
value|BWN_PHY_OFDM(0x2f)
end_define

begin_comment
comment|/* DSSS Confirm Cnt */
end_comment

begin_define
define|#
directive|define
name|BWN_PHY_PEAK_COUNT
value|BWN_PHY_OFDM(0x30)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_GAIN_MISMATCH_LIMIT
value|BWN_PHY_OFDM(0x31)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_CRS_ED_THRESH
value|BWN_PHY_OFDM(0x32)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_INPUT_PWRDB
value|BWN_PHY_OFDM(0x34)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_AFE_ADC_CTL_0
value|BWN_PHY_OFDM(0x36)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_AFE_ADC_CTL_1
value|BWN_PHY_OFDM(0x37)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_AFE_DAC_CTL
value|BWN_PHY_OFDM(0x39)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_AFE_CTL
value|BWN_PHY_OFDM(0x3a)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_AFE_CTL_OVR
value|BWN_PHY_OFDM(0x3b)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_AFE_CTL_OVRVAL
value|BWN_PHY_OFDM(0x3c)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_AFE_RSSI_CTL_0
value|BWN_PHY_OFDM(0x3d)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_AFE_RSSI_CTL_1
value|BWN_PHY_OFDM(0x3e)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_LP_PHY_CTL
value|BWN_PHY_OFDM(0x48)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_ENCORE
value|BWN_PHY_OFDM(0x49)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_ENCORE_EN
value|0x0200
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RESET_CTL
value|BWN_PHY_OFDM(0x4a)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RF_OVERRIDE_0
value|BWN_PHY_OFDM(0x4c)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RF_OVERRIDE_VAL_0
value|BWN_PHY_OFDM(0x4d)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_TR_LOOKUP_1
value|BWN_PHY_OFDM(0x4e)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_TR_LOOKUP_2
value|BWN_PHY_OFDM(0x4F)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_LMS
value|BWN_PHY_OFDM(0x55)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_TABLE_ADDR
value|BWN_PHY_OFDM(0x55)
end_define

begin_comment
comment|/* for LP */
end_comment

begin_define
define|#
directive|define
name|BWN_PHY_TABLEDATALO
value|BWN_PHY_OFDM(0x56)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_TABLEDATAHI
value|BWN_PHY_OFDM(0x57)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_OFDM61
value|BWN_PHY_OFDM(0x61)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_OFDM61_10
value|0x0010
end_define

begin_define
define|#
directive|define
name|BWN_PHY_ADC_COMPENSATION_CTL
value|BWN_PHY_OFDM(0x70)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_OTABLECTL
value|BWN_PHY_OFDM(0x72)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_OTABLENR_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|BWN_PHY_OTABLEI
value|BWN_PHY_OFDM(0x73)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_OTABLEQ
value|BWN_PHY_OFDM(0x74)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_HPWR_TSSICTL
value|BWN_PHY_OFDM(0x78)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_IQ_ENABLE_WAIT_TIME_ADDR
value|BWN_PHY_OFDM(0x81)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_IQ_NUM_SMPLS_ADDR
value|BWN_PHY_OFDM(0x82)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_IQ_ACC_HI_ADDR
value|BWN_PHY_OFDM(0x83)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_IQ_ACC_LO_ADDR
value|BWN_PHY_OFDM(0x84)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_IQ_I_PWR_ACC_HI_ADDR
value|BWN_PHY_OFDM(0x85)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_IQ_I_PWR_ACC_LO_ADDR
value|BWN_PHY_OFDM(0x86)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_IQ_Q_PWR_ACC_HI_ADDR
value|BWN_PHY_OFDM(0x87)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_IQ_Q_PWR_ACC_LO_ADDR
value|BWN_PHY_OFDM(0x88)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_ANTWRSETT
value|BWN_PHY_OFDM(0x8c)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_ANTWRSETT_ARXDIV
value|0x2000
end_define

begin_define
define|#
directive|define
name|BWN_PHY_OFDM9B
value|BWN_PHY_OFDM(0x9b)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_A_PHY_CTL_ADDR
value|BWN_PHY_OFDM(0x9c)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RX_COMP_COEFF_S
value|BWN_PHY_OFDM(0x9e)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_N1P1GAIN
value|BWN_PHY_OFDM(0xa0)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_SMPL_PLAY_COUNT
value|BWN_PHY_OFDM(0xa0)
end_define

begin_comment
comment|/* for LP */
end_comment

begin_define
define|#
directive|define
name|BWN_PHY_P1P2GAIN
value|BWN_PHY_OFDM(0xa1)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_SMPL_PLAY_BUFFER_CTL
value|BWN_PHY_OFDM(0xA1)
end_define

begin_comment
comment|/* for LP */
end_comment

begin_define
define|#
directive|define
name|BWN_PHY_N1N2GAIN
value|BWN_PHY_OFDM(0xa2)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_4WIRECTL
value|BWN_PHY_OFDM(0xa2)
end_define

begin_comment
comment|/* for LP */
end_comment

begin_define
define|#
directive|define
name|BWN_PHY_TX_PWR_CTL_CMD
value|BWN_PHY_OFDM(0xa4)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_TX_PWR_CTL_CMD_MODE
value|0xe000
end_define

begin_define
define|#
directive|define
name|BWN_PHY_TX_PWR_CTL_CMD_MODE_OFF
value|0x0000
end_define

begin_define
define|#
directive|define
name|BWN_PHY_TX_PWR_CTL_CMD_MODE_SW
value|0x8000
end_define

begin_define
define|#
directive|define
name|BWN_PHY_TX_PWR_CTL_CMD_MODE_HW
value|0xe000
end_define

begin_define
define|#
directive|define
name|BWN_PHY_CCKSHIFTBITS_WA
value|BWN_PHY_OFDM(0xa5)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_TX_PWR_CTL_NNUM
value|BWN_PHY_OFDM(0xa5)
end_define

begin_comment
comment|/* for LP */
end_comment

begin_define
define|#
directive|define
name|BWN_PHY_CCKSHIFTBITS
value|BWN_PHY_OFDM(0xa7)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_DIVSRCHIDX
value|BWN_PHY_OFDM(0xa8)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_DIVP1P2GAIN
value|BWN_PHY_OFDM(0xab)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_LP_RF_SIGNAL_LUT
value|BWN_PHY_OFDM(0xac)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_DIVSRCHGAINBACK
value|BWN_PHY_OFDM(0xad)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RX_RADIO_CTL
value|BWN_PHY_OFDM(0xae)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RF_OVERRIDE_2
value|BWN_PHY_OFDM(0xb0)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RF_OVERRIDE_2_VAL
value|BWN_PHY_OFDM(0xb1)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_PS_CTL_OVERRIDE_VAL0
value|BWN_PHY_OFDM(0xB2)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_PS_CTL_OVERRIDE_VAL1
value|BWN_PHY_OFDM(0xB3)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_PS_CTL_OVERRIDE_VAL2
value|BWN_PHY_OFDM(0xB4)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_TX_GAIN_CTL_OVERRIDE_VAL
value|BWN_PHY_OFDM(0xB5)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RX_GAIN_CTL_OVERRIDE_VAL
value|BWN_PHY_OFDM(0xB6)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_AFE_DDFS
value|BWN_PHY_OFDM(0xb7)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_AFE_DDFS_POINTER_INIT
value|BWN_PHY_OFDM(0xB8)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_AFE_DDFS_INCR_INIT
value|BWN_PHY_OFDM(0xB9)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_TR_LOOKUP_3
value|BWN_PHY_OFDM(0xbb)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_TR_LOOKUP_4
value|BWN_PHY_OFDM(0xbc)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_GPIO_OUTEN
value|BWN_PHY_OFDM(0xbe)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_GPIO_SELECT
value|BWN_PHY_OFDM(0xbf)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_CRSTHRES1
value|BWN_PHY_OFDM(0xc0)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_CRSTHRES2
value|BWN_PHY_OFDM(0xc1)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_4C3
value|BWN_PHY_OFDM(0xC3)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_4C4
value|BWN_PHY_OFDM(0xC4)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_4C5
value|BWN_PHY_OFDM(0xC5)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_TR_LOOKUP_5
value|BWN_PHY_OFDM(0xC7)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_TR_LOOKUP_6
value|BWN_PHY_OFDM(0xC8)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_TR_LOOKUP_7
value|BWN_PHY_OFDM(0xC9)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_TR_LOOKUP_8
value|BWN_PHY_OFDM(0xCA)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RF_PWR_OVERRIDE
value|BWN_PHY_OFDM(0xd3)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB
parameter_list|(
name|number
parameter_list|,
name|offset
parameter_list|)
define|\
value|(((number)<< BWN_PHY_OTABLENR_SHIFT) | (offset))
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_AGC1
value|BWN_OFDMTAB(0x00, 0)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_GAIN0
value|BWN_OFDMTAB(0x00, 0)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_GAINX
value|BWN_OFDMTAB(0x01, 0)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_GAIN1
value|BWN_OFDMTAB(0x01, 4)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_AGC3
value|BWN_OFDMTAB(0x02, 0)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_GAIN2
value|BWN_OFDMTAB(0x02, 3)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_LNAHPFGAIN1
value|BWN_OFDMTAB(0x03, 0)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_WRSSI
value|BWN_OFDMTAB(0x04, 0)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_NOISESCALE
value|BWN_OFDMTAB(0x05, 0)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_AGC2
value|BWN_OFDMTAB(0x06, 0)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_ROTOR
value|BWN_OFDMTAB(0x08, 0)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_ADVRETARD
value|BWN_OFDMTAB(0x09, 0)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_DAC
value|BWN_OFDMTAB(0x0c, 0)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_DC
value|BWN_OFDMTAB(0x0e, 7)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_PWRDYN2
value|BWN_OFDMTAB(0x0e, 12)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_UNKNOWN_0F
value|BWN_OFDMTAB(0x0f, 0)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_UNKNOWN_APHY
value|BWN_OFDMTAB(0x0f, 7)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_LPFGAIN
value|BWN_OFDMTAB(0x0f, 12)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_RSSI
value|BWN_OFDMTAB(0x10, 0)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_UNKNOWN_11
value|BWN_OFDMTAB(0x11, 4)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_AGC1_R1
value|BWN_OFDMTAB(0x13, 0)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_GAINX_R1
value|BWN_OFDMTAB(0x14, 0)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_MINSIGSQ
value|BWN_OFDMTAB(0x14, 0)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_AGC3_R1
value|BWN_OFDMTAB(0x15, 0)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_WRSSI_R1
value|BWN_OFDMTAB(0x15, 4)
end_define

begin_define
define|#
directive|define
name|BWN_OFDMTAB_DACRFPABB
value|BWN_OFDMTAB(0x16, 0)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_CCKBBANDCFG
value|BWN_PHY_CCK(0x01)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_PGACTL
value|BWN_PHY_CCK(0x15)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_PGACTL_LPF
value|0x1000
end_define

begin_define
define|#
directive|define
name|BWN_PHY_PGACTL_LOWBANDW
value|0x0040
end_define

begin_define
define|#
directive|define
name|BWN_PHY_PGACTL_UNKNOWN
value|0xefa0
end_define

begin_define
define|#
directive|define
name|BWN_PHY_TSSI
value|BWN_PHY_CCK(0x29)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_LO_LEAKAGE
value|BWN_PHY_CCK(0x2d)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_SYNCPEAKCNT
value|BWN_PHY_CCK(0x30)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_SYNCCTL
value|BWN_PHY_CCK(0x35)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_DACCTL
value|BWN_PHY_CCK(0x60)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_CLASSCTL
value|BWN_PHY_EXTG(0x02)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_GTABCTL
value|BWN_PHY_EXTG(0x03)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_GTABNR_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|BWN_PHY_GTABDATA
value|BWN_PHY_EXTG(0x04)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_LO_MASK
value|BWN_PHY_EXTG(0x0f)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_LO_CTL
value|BWN_PHY_EXTG(0x10)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RFOVER
value|BWN_PHY_EXTG(0x11)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RFOVERVAL
value|BWN_PHY_EXTG(0x12)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RFOVERVAL_EXTLNA
value|0x8000
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RFOVERVAL_LNA
value|0x7000
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RFOVERVAL_LNA_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RFOVERVAL_PGA
value|0x0f00
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RFOVERVAL_PGA_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RFOVERVAL_UNK
value|0x0010
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RFOVERVAL_TRSWRX
value|0x00e0
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RFOVERVAL_BW
value|0x0003
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RFOVERVAL_BW_LPF
value|0x0001
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RFOVERVAL_BW_LBW
value|0x0002
end_define

begin_define
define|#
directive|define
name|BWN_PHY_ANALOGOVER
value|BWN_PHY_EXTG(0x14)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_ANALOGOVERVAL
value|BWN_PHY_EXTG(0x15)
end_define

begin_define
define|#
directive|define
name|BWN_GTAB
parameter_list|(
name|number
parameter_list|,
name|offset
parameter_list|)
define|\
value|(((number)<< BWN_PHY_GTABNR_SHIFT) | (offset))
end_define

begin_define
define|#
directive|define
name|BWN_GTAB_ORIGTR
value|BWN_GTAB(0x2e, 0x298)
end_define

begin_define
define|#
directive|define
name|BWN_PHY_G_LOCTL
value|0x0810
end_define

begin_define
define|#
directive|define
name|BWN_PHY_RADIO_BITFIELD
value|0x0401
end_define

begin_define
define|#
directive|define
name|BWN_PHY_G_CRS
value|0x0429
end_define

begin_define
define|#
directive|define
name|BWN_PHY_NRSSI_CTRL
value|0x0803
end_define

begin_define
define|#
directive|define
name|BWN_PHY_NRSSI_DATA
value|0x0804
end_define

begin_define
define|#
directive|define
name|BWN_FWCAPS_HWCRYPTO
value|0x0001
end_define

begin_define
define|#
directive|define
name|BWN_FWCAPS_WME
value|0x0002
end_define

begin_define
define|#
directive|define
name|BWN_MACFILTER_SELF
value|0x0000
end_define

begin_define
define|#
directive|define
name|BWN_MACFILTER_BSSID
value|0x0003
end_define

begin_define
define|#
directive|define
name|BWN_SEC_KEYSIZE
value|16
end_define

begin_define
define|#
directive|define
name|BWN_SEC_ALGO_NONE
value|0
end_define

begin_define
define|#
directive|define
name|BWN_LED_BEHAVIOUR
value|0x7f
end_define

begin_define
define|#
directive|define
name|BWN_LED_ACTIVELOW
value|0x80
end_define

begin_define
define|#
directive|define
name|BWN_DEBUGINTR_REASON_REG
value|63
end_define

begin_define
define|#
directive|define
name|BWN_DEBUGINTR_PANIC
value|0
end_define

begin_define
define|#
directive|define
name|BWN_DEBUGINTR_DUMP_SHM
value|1
end_define

begin_define
define|#
directive|define
name|BWN_DEBUGINTR_DUMP_REGS
value|2
end_define

begin_define
define|#
directive|define
name|BWN_DEBUGINTR_MARKER
value|3
end_define

begin_define
define|#
directive|define
name|BWN_DEBUGINTR_ACK
value|0xffff
end_define

begin_define
define|#
directive|define
name|BWN_FWPANIC_REASON_REG
value|3
end_define

begin_define
define|#
directive|define
name|BWN_FWPANIC_DIE
value|0
end_define

begin_define
define|#
directive|define
name|BWN_FWPANIC_RESTART
value|1
end_define

begin_define
define|#
directive|define
name|BWN_WATCHDOG_REG
value|1
end_define

begin_define
define|#
directive|define
name|BWN_CCK_RATE_1MB
value|0x02
end_define

begin_define
define|#
directive|define
name|BWN_CCK_RATE_2MB
value|0x04
end_define

begin_define
define|#
directive|define
name|BWN_CCK_RATE_5MB
value|0x0b
end_define

begin_define
define|#
directive|define
name|BWN_CCK_RATE_11MB
value|0x16
end_define

begin_define
define|#
directive|define
name|BWN_OFDM_RATE_6MB
value|0x0c
end_define

begin_define
define|#
directive|define
name|BWN_OFDM_RATE_9MB
value|0x12
end_define

begin_define
define|#
directive|define
name|BWN_OFDM_RATE_12MB
value|0x18
end_define

begin_define
define|#
directive|define
name|BWN_OFDM_RATE_18MB
value|0x24
end_define

begin_define
define|#
directive|define
name|BWN_OFDM_RATE_24MB
value|0x30
end_define

begin_define
define|#
directive|define
name|BWN_OFDM_RATE_36MB
value|0x48
end_define

begin_define
define|#
directive|define
name|BWN_OFDM_RATE_48MB
value|0x60
end_define

begin_define
define|#
directive|define
name|BWN_OFDM_RATE_54MB
value|0x6c
end_define

begin_define
define|#
directive|define
name|BWN_RX_CHAN_PHYTYPE
value|0x0007
end_define

begin_define
define|#
directive|define
name|BWN_RX_PHYST0_GAINCTL
value|0x4000
end_define

begin_define
define|#
directive|define
name|BWN_RX_PHYST0_PLCPHCF
value|0x0200
end_define

begin_define
define|#
directive|define
name|BWN_RX_PHYST0_PLCPFV
value|0x0100
end_define

begin_define
define|#
directive|define
name|BWN_RX_PHYST0_SHORTPRMBL
value|0x0080
end_define

begin_define
define|#
directive|define
name|BWN_RX_PHYST0_OFDM
value|0x0001
end_define

begin_define
define|#
directive|define
name|BWN_RX_PHYST3_TRSTATE
value|0x0400
end_define

begin_define
define|#
directive|define
name|BWN_RX_MAC_KEYIDX
value|0x000007e0
end_define

begin_define
define|#
directive|define
name|BWN_RX_MAC_KEYIDX_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|BWN_RX_MAC_DECERR
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BWN_RX_MAC_DEC
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BWN_RX_MAC_PADDING
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BWN_RX_MAC_FCSERR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BWN_PS_ON
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|BWN_PS_OFF
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|BWN_PS_AWAKE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|BWN_PS_ASLEEP
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|BWN_TAB_NOISESCALE_SIZE
value|27
end_define

begin_comment
comment|/*  * SPROM GPIO  */
end_comment

begin_define
define|#
directive|define
name|BWN_LED_ACT_LOW
value|0x80
end_define

begin_define
define|#
directive|define
name|BWN_LED_ACT_MASK
value|0x7f
end_define

begin_define
define|#
directive|define
name|BWN_LED_ACT_OFF
value|0
end_define

begin_define
define|#
directive|define
name|BWN_LED_ACT_ON
value|1
end_define

begin_define
define|#
directive|define
name|BWN_LED_ACT_BLINK
value|2
end_define

begin_define
define|#
directive|define
name|BWN_LED_ACT_RF_ENABLED
value|3
end_define

begin_define
define|#
directive|define
name|BWN_LED_ACT_5GHZ
value|4
end_define

begin_define
define|#
directive|define
name|BWN_LED_ACT_2GHZ
value|5
end_define

begin_define
define|#
directive|define
name|BWN_LED_ACT_11G
value|6
end_define

begin_define
define|#
directive|define
name|BWN_LED_ACT_BLINK_SLOW
value|7
end_define

begin_define
define|#
directive|define
name|BWN_LED_ACT_BLINK_POLL
value|8
end_define

begin_define
define|#
directive|define
name|BWN_LED_ACT_UNKN
value|9
end_define

begin_define
define|#
directive|define
name|BWN_LED_ACT_ASSOC
value|10
end_define

begin_define
define|#
directive|define
name|BWN_LED_ACT_NULL
value|11
end_define

begin_define
define|#
directive|define
name|BWN_VENDOR_LED_ACT_COMPAQ
define|\
value|BWN_LED_ACT_RF_ENABLED,		\ 	BWN_LED_ACT_2GHZ,		\ 	BWN_LED_ACT_5GHZ,		\ 	BWN_LED_ACT_OFF
end_define

begin_define
define|#
directive|define
name|BWN_VENDOR_LED_ACT_ASUSTEK
define|\
value|BWN_LED_ACT_ASSOC,		\ 	BWN_LED_ACT_2GHZ,	\ 	BWN_LED_ACT_5GHZ,		\ 	BWN_LED_ACT_OFF
end_define

begin_define
define|#
directive|define
name|BWN_VENDOR_LED_ACT_DEFAULT
define|\
value|BWN_LED_ACT_BLINK,		\ 	BWN_LED_ACT_2GHZ,	\ 	BWN_LED_ACT_5GHZ,	\ 	BWN_LED_ACT_OFF
end_define

begin_define
define|#
directive|define
name|BWN_TAB_ROTOR
define|\
value|{									\ 	0xfeb93ffd, 0xfec63ffd, 0xfed23ffd, 0xfedf3ffd, 0xfeec3ffe,	\ 	0xfef83ffe, 0xff053ffe, 0xff113ffe, 0xff1e3ffe, 0xff2a3fff,	\ 	0xff373fff, 0xff443fff, 0xff503fff, 0xff5d3fff, 0xff693fff,	\ 	0xff763fff, 0xff824000, 0xff8f4000, 0xff9b4000, 0xffa84000,	\ 	0xffb54000, 0xffc14000, 0xffce4000, 0xffda4000, 0xffe74000,	\ 	0xfff34000, 0x00004000, 0x000d4000, 0x00194000, 0x00264000,	\ 	0x00324000, 0x003f4000, 0x004b4000, 0x00584000, 0x00654000,	\ 	0x00714000, 0x007e4000, 0x008a3fff, 0x00973fff, 0x00a33fff,	\ 	0x00b03fff, 0x00bc3fff, 0x00c93fff, 0x00d63fff, 0x00e23ffe,	\ 	0x00ef3ffe, 0x00fb3ffe, 0x01083ffe, 0x01143ffe, 0x01213ffd,	\ 	0x012e3ffd, 0x013a3ffd, 0x01473ffd				\ }
end_define

begin_define
define|#
directive|define
name|BWN_TAB_RETARD
define|\
value|{									\ 	0xdb93cb87, 0xd666cf64, 0xd1fdd358, 0xcda6d826, 0xca38dd9f,	\ 	0xc729e2b4, 0xc469e88e, 0xc26aee2b, 0xc0def46c, 0xc073fa62,	\ 	0xc01d00d5, 0xc0760743, 0xc1560d1e, 0xc2e51369, 0xc4ed18ff,	\ 	0xc7ac1ed7, 0xcb2823b2, 0xcefa28d9, 0xd2f62d3f, 0xd7bb3197,	\ 	0xdce53568, 0xe1fe3875, 0xe7d13b35, 0xed663d35, 0xf39b3ec4,	\ 	0xf98e3fa7, 0x00004000, 0x06723fa7, 0x0c653ec4, 0x129a3d35,	\ 	0x182f3b35, 0x1e023875, 0x231b3568, 0x28453197, 0x2d0a2d3f,	\ 	0x310628d9, 0x34d823b2, 0x38541ed7, 0x3b1318ff, 0x3d1b1369,	\ 	0x3eaa0d1e, 0x3f8a0743, 0x3fe300d5, 0x3f8dfa62, 0x3f22f46c,	\ 	0x3d96ee2b, 0x3b97e88e, 0x38d7e2b4, 0x35c8dd9f, 0x325ad826,	\ 	0x2e03d358, 0x299acf64, 0x246dcb87,				\ }
end_define

begin_define
define|#
directive|define
name|BWN_TAB_FINEFREQ_G
define|\
value|{									\ 	0x0089, 0x02e9, 0x0409, 0x04e9, 0x05a9, 0x0669, 0x0709, 0x0789,	\ 	0x0829, 0x08a9, 0x0929, 0x0989, 0x0a09, 0x0a69, 0x0ac9, 0x0b29,	\ 	0x0ba9, 0x0be9, 0x0c49, 0x0ca9, 0x0d09, 0x0d69, 0x0da9, 0x0e09,	\ 	0x0e69, 0x0ea9, 0x0f09, 0x0f49, 0x0fa9, 0x0fe9, 0x1029, 0x1089,	\ 	0x10c9, 0x1109, 0x1169, 0x11a9, 0x11e9, 0x1229, 0x1289, 0x12c9,	\ 	0x1309, 0x1349, 0x1389, 0x13c9, 0x1409, 0x1449, 0x14a9, 0x14e9,	\ 	0x1529, 0x1569, 0x15a9, 0x15e9, 0x1629, 0x1669, 0x16a9, 0x16e8,	\ 	0x1728, 0x1768, 0x17a8, 0x17e8, 0x1828, 0x1868, 0x18a8, 0x18e8,	\ 	0x1928, 0x1968, 0x19a8, 0x19e8, 0x1a28, 0x1a68, 0x1aa8, 0x1ae8,	\ 	0x1b28, 0x1b68, 0x1ba8, 0x1be8, 0x1c28, 0x1c68, 0x1ca8, 0x1ce8,	\ 	0x1d28, 0x1d68, 0x1dc8, 0x1e08, 0x1e48, 0x1e88, 0x1ec8, 0x1f08,	\ 	0x1f48, 0x1f88, 0x1fe8, 0x2028, 0x2068, 0x20a8, 0x2108, 0x2148,	\ 	0x2188, 0x21c8, 0x2228, 0x2268, 0x22c8, 0x2308, 0x2348, 0x23a8,	\ 	0x23e8, 0x2448, 0x24a8, 0x24e8, 0x2548, 0x25a8, 0x2608, 0x2668,	\ 	0x26c8, 0x2728, 0x2787, 0x27e7, 0x2847, 0x28c7, 0x2947, 0x29a7,	\ 	0x2a27, 0x2ac7, 0x2b47, 0x2be7, 0x2ca7, 0x2d67, 0x2e47, 0x2f67,	\ 	0x3247, 0x3526, 0x3646, 0x3726, 0x3806, 0x38a6, 0x3946, 0x39e6,	\ 	0x3a66, 0x3ae6, 0x3b66, 0x3bc6, 0x3c45, 0x3ca5, 0x3d05, 0x3d85,	\ 	0x3de5, 0x3e45, 0x3ea5, 0x3ee5, 0x3f45, 0x3fa5, 0x4005, 0x4045,	\ 	0x40a5, 0x40e5, 0x4145, 0x4185, 0x41e5, 0x4225, 0x4265, 0x42c5,	\ 	0x4305, 0x4345, 0x43a5, 0x43e5, 0x4424, 0x4464, 0x44c4, 0x4504,	\ 	0x4544, 0x4584, 0x45c4, 0x4604, 0x4644, 0x46a4, 0x46e4, 0x4724,	\ 	0x4764, 0x47a4, 0x47e4, 0x4824, 0x4864, 0x48a4, 0x48e4, 0x4924,	\ 	0x4964, 0x49a4, 0x49e4, 0x4a24, 0x4a64, 0x4aa4, 0x4ae4, 0x4b23,	\ 	0x4b63, 0x4ba3, 0x4be3, 0x4c23, 0x4c63, 0x4ca3, 0x4ce3, 0x4d23,	\ 	0x4d63, 0x4da3, 0x4de3, 0x4e23, 0x4e63, 0x4ea3, 0x4ee3, 0x4f23,	\ 	0x4f63, 0x4fc3, 0x5003, 0x5043, 0x5083, 0x50c3, 0x5103, 0x5143,	\ 	0x5183, 0x51e2, 0x5222, 0x5262, 0x52a2, 0x52e2, 0x5342, 0x5382,	\ 	0x53c2, 0x5402, 0x5462, 0x54a2, 0x5502, 0x5542, 0x55a2, 0x55e2,	\ 	0x5642, 0x5682, 0x56e2, 0x5722, 0x5782, 0x57e1, 0x5841, 0x58a1,	\ 	0x5901, 0x5961, 0x59c1, 0x5a21, 0x5aa1, 0x5b01, 0x5b81, 0x5be1,	\ 	0x5c61, 0x5d01, 0x5d80, 0x5e20, 0x5ee0, 0x5fa0, 0x6080, 0x61c0,	\ }
end_define

begin_define
define|#
directive|define
name|BWN_TAB_NOISE_G1
define|\
value|{									\ 	0x013c, 0x01f5, 0x031a, 0x0631, 0x0001, 0x0001, 0x0001, 0x0001,	\ }
end_define

begin_define
define|#
directive|define
name|BWN_TAB_NOISE_G2
define|\
value|{									\ 	0x5484, 0x3c40, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	\ }
end_define

begin_define
define|#
directive|define
name|BWN_TAB_NOISESCALE_G1
define|\
value|{									\ 	0x6c77, 0x5162, 0x3b40, 0x3335, 0x2f2d, 0x2a2a, 0x2527, 0x1f21,	\ 	0x1a1d, 0x1719, 0x1616, 0x1414, 0x1414, 0x1400, 0x1414, 0x1614,	\ 	0x1716, 0x1a19, 0x1f1d, 0x2521, 0x2a27, 0x2f2a, 0x332d, 0x3b35,	\ 	0x5140, 0x6c62, 0x0077,						\ }
end_define

begin_define
define|#
directive|define
name|BWN_TAB_NOISESCALE_G2
define|\
value|{									\ 	0xd8dd, 0xcbd4, 0xbcc0, 0xb6b7, 0xb2b0, 0xadad, 0xa7a9, 0x9fa1,	\ 	0x969b, 0x9195, 0x8f8f, 0x8a8a, 0x8a8a, 0x8a00, 0x8a8a, 0x8f8a,	\ 	0x918f, 0x9695, 0x9f9b, 0xa7a1, 0xada9, 0xb2ad, 0xb6b0, 0xbcb7,	\ 	0xcbc0, 0xd8d4, 0x00dd,						\ }
end_define

begin_define
define|#
directive|define
name|BWN_TAB_NOISESCALE_G3
define|\
value|{									\ 	0xa4a4, 0xa4a4, 0xa4a4, 0xa4a4, 0xa4a4, 0xa4a4, 0xa4a4, 0xa4a4,	\ 	0xa4a4, 0xa4a4, 0xa4a4, 0xa4a4, 0xa4a4, 0xa400, 0xa4a4, 0xa4a4,	\ 	0xa4a4, 0xa4a4, 0xa4a4, 0xa4a4, 0xa4a4, 0xa4a4, 0xa4a4, 0xa4a4,	\ 	0xa4a4, 0xa4a4, 0x00a4,						\ }
end_define

begin_define
define|#
directive|define
name|BWN_TAB_SIGMASQR2
define|\
value|{									\ 	0x00de, 0x00dc, 0x00da, 0x00d8, 0x00d6, 0x00d4, 0x00d2, 0x00cf,	\ 	0x00cd, 0x00ca, 0x00c7, 0x00c4, 0x00c1, 0x00be, 0x00be, 0x00be,	\ 	0x00be, 0x00be, 0x00be, 0x00be, 0x00be, 0x00be, 0x00be, 0x00be,	\ 	0x00be, 0x00be, 0x0000, 0x00be, 0x00be, 0x00be, 0x00be, 0x00be,	\ 	0x00be, 0x00be, 0x00be, 0x00be, 0x00be, 0x00be, 0x00be, 0x00be,	\ 	0x00c1, 0x00c4, 0x00c7, 0x00ca, 0x00cd, 0x00cf, 0x00d2, 0x00d4,	\ 	0x00d6, 0x00d8, 0x00da, 0x00dc, 0x00de,				\ }
end_define

begin_define
define|#
directive|define
name|BWN_PHY_G_TSSI2DBM_TABLE
define|\
value|{									\ 	77, 77, 77, 76, 76, 76, 75, 75, 74, 74, 73, 73, 73, 72, 72, 71,	\ 	71, 70, 70, 69, 68, 68, 67, 67, 66, 65, 65, 64, 63, 63, 62, 61,	\ 	60, 59, 58, 57, 56, 55, 54, 53, 52, 50, 49, 47, 45, 43, 40, 37,	\ 	33, 28, 22, 14, 5, -7, -20, -20, -20, -20, -20, -20, -20, -20,	\ 	-20, -20							\ }
end_define

begin_define
define|#
directive|define
name|BWN_PHY_G_RF_CHANNELS
define|\
value|{									\ 	12, 17, 22, 27, 32, 37, 42, 47, 52, 57, 62, 67, 72, 84,		\ }
end_define

begin_define
define|#
directive|define
name|BWN_BITREV_TABLE
define|\
value|{									\ 	0x00, 0x80, 0x40, 0xc0, 0x20, 0xa0, 0x60, 0xe0, 0x10, 0x90,	\ 	0x50, 0xd0, 0x30, 0xb0, 0x70, 0xf0, 0x08, 0x88, 0x48, 0xc8,	\ 	0x28, 0xa8, 0x68, 0xe8, 0x18, 0x98, 0x58, 0xd8, 0x38, 0xb8,	\ 	0x78, 0xf8, 0x04, 0x84, 0x44, 0xc4, 0x24, 0xa4, 0x64, 0xe4,	\ 	0x14, 0x94, 0x54, 0xd4, 0x34, 0xb4, 0x74, 0xf4, 0x0c, 0x8c,	\ 	0x4c, 0xcc, 0x2c, 0xac, 0x6c, 0xec, 0x1c, 0x9c, 0x5c, 0xdc,	\ 	0x3c, 0xbc, 0x7c, 0xfc, 0x02, 0x82, 0x42, 0xc2, 0x22, 0xa2,	\ 	0x62, 0xe2, 0x12, 0x92, 0x52, 0xd2, 0x32, 0xb2, 0x72, 0xf2,	\ 	0x0a, 0x8a, 0x4a, 0xca, 0x2a, 0xaa, 0x6a, 0xea, 0x1a, 0x9a,	\ 	0x5a, 0xda, 0x3a, 0xba, 0x7a, 0xfa, 0x06, 0x86, 0x46, 0xc6,	\ 	0x26, 0xa6, 0x66, 0xe6, 0x16, 0x96, 0x56, 0xd6, 0x36, 0xb6,	\ 	0x76, 0xf6, 0x0e, 0x8e, 0x4e, 0xce, 0x2e, 0xae, 0x6e, 0xee,	\ 	0x1e, 0x9e, 0x5e, 0xde, 0x3e, 0xbe, 0x7e, 0xfe, 0x01, 0x81,	\ 	0x41, 0xc1, 0x21, 0xa1, 0x61, 0xe1, 0x11, 0x91, 0x51, 0xd1,	\ 	0x31, 0xb1, 0x71, 0xf1, 0x09, 0x89, 0x49, 0xc9, 0x29, 0xa9,	\ 	0x69, 0xe9, 0x19, 0x99, 0x59, 0xd9, 0x39, 0xb9, 0x79, 0xf9,	\ 	0x05, 0x85, 0x45, 0xc5, 0x25, 0xa5, 0x65, 0xe5, 0x15, 0x95,	\ 	0x55, 0xd5, 0x35, 0xb5, 0x75, 0xf5, 0x0d, 0x8d, 0x4d, 0xcd,	\ 	0x2d, 0xad, 0x6d, 0xed, 0x1d, 0x9d, 0x5d, 0xdd, 0x3d, 0xbd,	\ 	0x7d, 0xfd, 0x03, 0x83, 0x43, 0xc3, 0x23, 0xa3, 0x63, 0xe3,	\ 	0x13, 0x93, 0x53, 0xd3, 0x33, 0xb3, 0x73, 0xf3, 0x0b, 0x8b,	\ 	0x4b, 0xcb, 0x2b, 0xab, 0x6b, 0xeb, 0x1b, 0x9b, 0x5b, 0xdb,	\ 	0x3b, 0xbb, 0x7b, 0xfb, 0x07, 0x87, 0x47, 0xc7, 0x27, 0xa7,	\ 	0x67, 0xe7, 0x17, 0x97, 0x57, 0xd7, 0x37, 0xb7, 0x77, 0xf7,	\ 	0x0f, 0x8f, 0x4f, 0xcf, 0x2f, 0xaf, 0x6f, 0xef, 0x1f, 0x9f,	\ 	0x5f, 0xdf, 0x3f, 0xbf, 0x7f, 0xff				\ }
end_define

begin_comment
comment|/*  * LP PHY  */
end_comment

begin_define
define|#
directive|define
name|BWN_TAB_TYPEMASK
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|BWN_TAB_GETTYPE
parameter_list|(
name|v
parameter_list|)
value|((v)& BWN_TAB_TYPEMASK)
end_define

begin_define
define|#
directive|define
name|BWN_TAB_GETOFFSET
parameter_list|(
name|v
parameter_list|)
value|((v)& ~BWN_TAB_TYPEMASK)
end_define

begin_define
define|#
directive|define
name|BWN_TAB_8BIT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|BWN_TAB_16BIT
value|0x20000000
end_define

begin_define
define|#
directive|define
name|BWN_TAB_32BIT
value|0x30000000
end_define

begin_define
define|#
directive|define
name|BWN_TAB_1
parameter_list|(
name|table
parameter_list|,
name|offset
parameter_list|)
define|\
value|(((table)<< 10) | (offset) | BWN_TAB_8BIT)
end_define

begin_define
define|#
directive|define
name|BWN_TAB_2
parameter_list|(
name|table
parameter_list|,
name|offset
parameter_list|)
define|\
value|(((table)<< 10) | (offset) | BWN_TAB_16BIT)
end_define

begin_define
define|#
directive|define
name|BWN_TAB_4
parameter_list|(
name|table
parameter_list|,
name|offset
parameter_list|)
define|\
value|(((table)<< 10) | (offset) | BWN_TAB_32BIT)
end_define

begin_define
define|#
directive|define
name|BWN_LP_RADIO
parameter_list|(
name|radio_reg
parameter_list|)
value|(radio_reg)
end_define

begin_define
define|#
directive|define
name|BWN_LP_NORTH
parameter_list|(
name|radio_reg
parameter_list|)
value|BWN_LP_RADIO(radio_reg)
end_define

begin_define
define|#
directive|define
name|BWN_LP_SOUTH
parameter_list|(
name|radio_reg
parameter_list|)
value|BWN_LP_RADIO((radio_reg) | 0x4000)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_COM1
value|BWN_LP_NORTH(0x000)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_COM2
value|BWN_LP_NORTH(0x002)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_COM4
value|BWN_LP_NORTH(0x004)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_PDNCTL0
value|BWN_LP_NORTH(0x010)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_PDNCTL1
value|BWN_LP_NORTH(0x011)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_PDNCTL3
value|BWN_LP_NORTH(0x013)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_PDNCTL4
value|BWN_LP_NORTH(0x014)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_LGENC
value|BWN_LP_NORTH(0x017)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_LGENATUNE0
value|BWN_LP_NORTH(0x01E)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_LGENATUNE2
value|BWN_LP_NORTH(0x020)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_LGENATUNE3
value|BWN_LP_NORTH(0x021)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_LGENACTL3
value|BWN_LP_NORTH(0x022)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_LGENACTL5
value|BWN_LP_NORTH(0x024)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_LGENACTL6
value|BWN_LP_NORTH(0x025)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_LGENACTL7
value|BWN_LP_NORTH(0x026)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_RXA_CTL1
value|BWN_LP_NORTH(0x028)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_RXBB_CTL0
value|BWN_LP_NORTH(0x02F)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_RXBB_GAIN1
value|BWN_LP_NORTH(0x033)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_RXBB_GAIN2
value|BWN_LP_NORTH(0x034)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_RXBB_CALIB2
value|BWN_LP_NORTH(0x03A)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_TXCTL3
value|BWN_LP_NORTH(0x048)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_TXCTL4
value|BWN_LP_NORTH(0x049)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_TXCTL5
value|BWN_LP_NORTH(0x04A)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_TXCTL6
value|BWN_LP_NORTH(0x04B)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_TXCTL_A
value|BWN_LP_NORTH(0x04F)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_TX_TUNE
value|BWN_LP_NORTH(0x052)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_TX_PAD
value|BWN_LP_NORTH(0x053)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_TX_PGA
value|BWN_LP_NORTH(0x054)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_TSSI_CTL0
value|BWN_LP_NORTH(0x057)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_N_CALIB_TS
value|BWN_LP_NORTH(0x05D)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_COM4
value|BWN_LP_SOUTH(0x004)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_PDS_CTL0
value|BWN_LP_SOUTH(0x010)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_BG_CTL1
value|BWN_LP_SOUTH(0x015)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_LGENG_CTL0
value|BWN_LP_SOUTH(0x017)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_LGENG_CTL1
value|BWN_LP_SOUTH(0x018)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_LGENG_CTL8
value|BWN_LP_SOUTH(0x01F)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_LGENG_CTL10
value|BWN_LP_SOUTH(0x021)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL0
value|BWN_LP_SOUTH(0x034)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL1
value|BWN_LP_SOUTH(0x035)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL2
value|BWN_LP_SOUTH(0x036)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL3
value|BWN_LP_SOUTH(0x037)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL5
value|BWN_LP_SOUTH(0x039)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL6
value|BWN_LP_SOUTH(0x03A)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL7
value|BWN_LP_SOUTH(0x03B)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL8
value|BWN_LP_SOUTH(0x03C)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL9
value|BWN_LP_SOUTH(0x03D)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL10
value|BWN_LP_SOUTH(0x03E)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL11
value|BWN_LP_SOUTH(0x03F)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL12
value|BWN_LP_SOUTH(0x040)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL13
value|BWN_LP_SOUTH(0x041)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL14
value|BWN_LP_SOUTH(0x042)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL18
value|BWN_LP_SOUTH(0x046)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL19
value|BWN_LP_SOUTH(0x047)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL21
value|BWN_LP_SOUTH(0x049)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL22
value|BWN_LP_SOUTH(0x04A)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL23
value|BWN_LP_SOUTH(0x04B)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL24
value|BWN_LP_SOUTH(0x04C)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL25
value|BWN_LP_SOUTH(0x04D)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL26
value|BWN_LP_SOUTH(0x04E)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL27
value|BWN_LP_SOUTH(0x04F)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL28
value|BWN_LP_SOUTH(0x050)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL29
value|BWN_LP_SOUTH(0x051)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL30
value|BWN_LP_SOUTH(0x052)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL31
value|BWN_LP_SOUTH(0x053)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL33
value|BWN_LP_SOUTH(0x055)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RFPLLCTL34
value|BWN_LP_SOUTH(0x056)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RXG_CNT8
value|BWN_LP_SOUTH(0x05F)
end_define

begin_define
define|#
directive|define
name|BWN_B2062_S_RXG_CNT16
value|BWN_LP_SOUTH(0x067)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_COM1
value|BWN_LP_RADIO(0x000)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_COM8
value|BWN_LP_RADIO(0x008)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_COM10
value|BWN_LP_RADIO(0x00A)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_COM15
value|BWN_LP_RADIO(0x00F)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_COM16
value|BWN_LP_RADIO(0x010)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_COM17
value|BWN_LP_RADIO(0x011)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_COM18
value|BWN_LP_RADIO(0x012)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_COM19
value|BWN_LP_RADIO(0x013)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_COM20
value|BWN_LP_RADIO(0x014)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_COM21
value|BWN_LP_RADIO(0x015)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_COM22
value|BWN_LP_RADIO(0x016)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_COM23
value|BWN_LP_RADIO(0x017)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_COM24
value|BWN_LP_RADIO(0x018)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_PLL_SP1
value|BWN_LP_RADIO(0x01A)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_PLL_SP2
value|BWN_LP_RADIO(0x01B)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_LOGEN_SP1
value|BWN_LP_RADIO(0x01C)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_LOGEN_SP2
value|BWN_LP_RADIO(0x01D)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_LOGEN_SP4
value|BWN_LP_RADIO(0x01F)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_LOGEN_SP5
value|BWN_LP_RADIO(0x020)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_G_RX_SP1
value|BWN_LP_RADIO(0x021)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_G_RX_SP2
value|BWN_LP_RADIO(0x022)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_G_RX_SP3
value|BWN_LP_RADIO(0x023)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_G_RX_SP7
value|BWN_LP_RADIO(0x027)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_G_RX_SP10
value|BWN_LP_RADIO(0x02A)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_A_RX_SP1
value|BWN_LP_RADIO(0x02C)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_A_RX_SP2
value|BWN_LP_RADIO(0x02D)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_A_RX_SP7
value|BWN_LP_RADIO(0x032)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_RX_BB_SP3
value|BWN_LP_RADIO(0x035)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_RX_BB_SP4
value|BWN_LP_RADIO(0x036)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_RX_BB_SP8
value|BWN_LP_RADIO(0x03A)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_TX_RF_SP3
value|BWN_LP_RADIO(0x03D)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_TX_RF_SP4
value|BWN_LP_RADIO(0x03E)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_TX_RF_SP6
value|BWN_LP_RADIO(0x040)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_TX_RF_SP9
value|BWN_LP_RADIO(0x043)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_PA_SP1
value|BWN_LP_RADIO(0x04C)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_PA_SP2
value|BWN_LP_RADIO(0x04D)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_PA_SP3
value|BWN_LP_RADIO(0x04E)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_PA_SP4
value|BWN_LP_RADIO(0x04F)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_PA_SP7
value|BWN_LP_RADIO(0x052)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_TX_BB_SP1
value|BWN_LP_RADIO(0x053)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_TX_BB_SP3
value|BWN_LP_RADIO(0x055)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_REG_SP1
value|BWN_LP_RADIO(0x056)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_BANDGAP_CTL1
value|BWN_LP_RADIO(0x057)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_RC_CALIB_CTL1
value|BWN_LP_RADIO(0x05A)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_RC_CALIB_CTL2
value|BWN_LP_RADIO(0x05B)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_RC_CALIB_CTL3
value|BWN_LP_RADIO(0x05C)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_RC_CALIB_CTL4
value|BWN_LP_RADIO(0x05D)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_RC_CALIB_CTL5
value|BWN_LP_RADIO(0x05E)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_RC_CALIB_CTL6
value|BWN_LP_RADIO(0x05F)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_JTAG_CALNRST
value|BWN_LP_RADIO(0x064)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_JTAG_CP2
value|BWN_LP_RADIO(0x068)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_JTAG_CP3
value|BWN_LP_RADIO(0x069)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_JTAG_LF1
value|BWN_LP_RADIO(0x06C)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_JTAG_LF2
value|BWN_LP_RADIO(0x06D)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_JTAG_LF3
value|BWN_LP_RADIO(0x06E)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_JTAG_LF4
value|BWN_LP_RADIO(0x06F)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_JTAG_SG1
value|BWN_LP_RADIO(0x070)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_JTAG_SG2
value|BWN_LP_RADIO(0x071)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_JTAG_SG3
value|BWN_LP_RADIO(0x072)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_JTAG_SG4
value|BWN_LP_RADIO(0x073)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_JTAG_VCO1
value|BWN_LP_RADIO(0x075)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_JTAG_VCO2
value|BWN_LP_RADIO(0x076)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_JTAG_VCO_CALIB3
value|BWN_LP_RADIO(0x079)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_JTAG_VCO_CALIB5
value|BWN_LP_RADIO(0x07B)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_JTAG_VCO_CALIB6
value|BWN_LP_RADIO(0x07C)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_JTAG_VCO_CALIB7
value|BWN_LP_RADIO(0x07D)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_JTAG_VCO_CALIB8
value|BWN_LP_RADIO(0x07E)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_JTAG_XTAL_12
value|BWN_LP_RADIO(0x081)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_LOGEN_RCCR1
value|BWN_LP_RADIO(0x0A1)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_LOGEN_VCOBUF1
value|BWN_LP_RADIO(0x0A2)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_LOGEN_MIXER2
value|BWN_LP_RADIO(0x0A4)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_LOGEN_BUF2
value|BWN_LP_RADIO(0x0A6)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_G_RX_MIX3
value|BWN_LP_RADIO(0x0C4)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_G_RX_MIX4
value|BWN_LP_RADIO(0x0C5)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_A_RX_1ST2
value|BWN_LP_RADIO(0x0CF)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_A_RX_1ST3
value|BWN_LP_RADIO(0x0D0)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_A_RX_2ND1
value|BWN_LP_RADIO(0x0D3)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_A_RX_2ND4
value|BWN_LP_RADIO(0x0D6)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_A_RX_2ND7
value|BWN_LP_RADIO(0x0D9)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_A_RX_PS6
value|BWN_LP_RADIO(0x0DF)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_A_RX_MIX4
value|BWN_LP_RADIO(0x0E3)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_A_RX_MIX5
value|BWN_LP_RADIO(0x0E4)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_A_RX_MIX6
value|BWN_LP_RADIO(0x0E5)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_RX_TIA_CTL1
value|BWN_LP_RADIO(0x0EC)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_RX_TIA_CTL3
value|BWN_LP_RADIO(0x0EE)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_RX_BB_CTL2
value|BWN_LP_RADIO(0x0F3)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_TX_RF_CTL2
value|BWN_LP_RADIO(0x100)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_TX_RF_CTL5
value|BWN_LP_RADIO(0x103)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_PA_CTL1
value|BWN_LP_RADIO(0x10B)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_PA_CTL11
value|BWN_LP_RADIO(0x115)
end_define

begin_define
define|#
directive|define
name|BWN_B2063_VREG_CTL1
value|BWN_LP_RADIO(0x11D)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_IF_BWNREG_H */
end_comment

end_unit

