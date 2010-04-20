begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Bruce M. Simpson.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * TODO: sprom  * TODO: implement dma translation bits (if needed for system bus)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SIBA_SIBAREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_SIBA_SIBAREG_H_
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_BCM4401
value|0x4401
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_BCM4401B0
value|0x4402
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_BCM4401B1
value|0x170c
end_define

begin_define
define|#
directive|define
name|SIBA_PCIR_BAR
value|PCIR_BAR(0)
end_define

begin_define
define|#
directive|define
name|SIBA_CCID_BCM4710
value|0x4710
end_define

begin_define
define|#
directive|define
name|SIBA_CCID_BCM4704
value|0x4704
end_define

begin_define
define|#
directive|define
name|SIBA_CCID_SENTRY5
value|0x5365
end_define

begin_comment
comment|/*  * ChipCommon registers.  */
end_comment

begin_define
define|#
directive|define
name|SIBA_CC_CHIPID
value|0x0000
end_define

begin_define
define|#
directive|define
name|SIBA_CC_IDMASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|SIBA_CC_ID
parameter_list|(
name|id
parameter_list|)
value|(id& SIBA_CC_IDMASK)
end_define

begin_define
define|#
directive|define
name|SIBA_CC_REVMASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|SIBA_CC_REVSHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SIBA_CC_REV
parameter_list|(
name|id
parameter_list|)
define|\
value|((id& SIBA_CC_REVMASK)>> SIBA_CC_REVSHIFT)
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PKGMASK
value|0x00F00000
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PKGSHIFT
value|20
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PKG
parameter_list|(
name|id
parameter_list|)
define|\
value|((id& SIBA_CC_PKGMASK)>> SIBA_CC_PKGSHIFT)
end_define

begin_define
define|#
directive|define
name|SIBA_CC_NCORESMASK
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|SIBA_CC_NCORESSHIFT
value|24
end_define

begin_define
define|#
directive|define
name|SIBA_CC_NCORES
parameter_list|(
name|id
parameter_list|)
define|\
value|((id& SIBA_CC_NCORESMASK)>> SIBA_CC_NCORESSHIFT)
end_define

begin_define
define|#
directive|define
name|SIBA_CC_CAPS
value|0x0004
end_define

begin_define
define|#
directive|define
name|SIBA_CC_CAPS_PWCTL
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SIBA_CC_CAPS_PMU
value|0x10000000
end_define

begin_comment
comment|/* PMU (rev>= 20) */
end_comment

begin_define
define|#
directive|define
name|SIBA_CC_CHIPCTL
value|0x0028
end_define

begin_comment
comment|/* rev>= 11 */
end_comment

begin_define
define|#
directive|define
name|SIBA_CC_CHIPSTAT
value|0x002C
end_define

begin_comment
comment|/* rev>= 11 */
end_comment

begin_define
define|#
directive|define
name|SIBA_CC_BCAST_ADDR
value|0x0050
end_define

begin_comment
comment|/* Broadcast Address */
end_comment

begin_define
define|#
directive|define
name|SIBA_CC_BCAST_DATA
value|0x0054
end_define

begin_comment
comment|/* Broadcast Data */
end_comment

begin_define
define|#
directive|define
name|SIBA_CC_PLLONDELAY
value|0x00B0
end_define

begin_comment
comment|/* Rev>= 4 only */
end_comment

begin_define
define|#
directive|define
name|SIBA_CC_FREFSELDELAY
value|0x00B4
end_define

begin_comment
comment|/* Rev>= 4 only */
end_comment

begin_define
define|#
directive|define
name|SIBA_CC_CLKSLOW
value|0x00b8
end_define

begin_comment
comment|/* 6<= Rev<= 9 only */
end_comment

begin_define
define|#
directive|define
name|SIBA_CC_CLKSLOW_SRC
value|0x00000007
end_define

begin_define
define|#
directive|define
name|SIBA_CC_CLKSLOW_SRC_CRYSTAL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SIBA_CC_CLKSLOW_FSLOW
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SIBA_CC_CLKSLOW_IPLL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SIBA_CC_CLKSLOW_ENXTAL
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SIBA_CC_CLKSYSCTL
value|0x00C0
end_define

begin_comment
comment|/* Rev>= 3 only */
end_comment

begin_define
define|#
directive|define
name|SIBA_CC_CLKCTLSTATUS
value|0x01e0
end_define

begin_define
define|#
directive|define
name|SIBA_CC_CLKCTLSTATUS_HT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SIBA_CC_UART0
value|0x0300
end_define

begin_comment
comment|/* offset of UART0 */
end_comment

begin_define
define|#
directive|define
name|SIBA_CC_UART1
value|0x0400
end_define

begin_comment
comment|/* offset of UART1 */
end_comment

begin_define
define|#
directive|define
name|SIBA_CC_PMUCTL
value|0x0600
end_define

begin_comment
comment|/* PMU control */
end_comment

begin_define
define|#
directive|define
name|SIBA_CC_PMUCTL_ILP
value|0xffff0000
end_define

begin_comment
comment|/* mask */
end_comment

begin_define
define|#
directive|define
name|SIBA_CC_PMUCTL_NOILP
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMUCTL_XF
value|0x0000007c
end_define

begin_comment
comment|/* crystal freq */
end_comment

begin_define
define|#
directive|define
name|SIBA_CC_PMUCTL_XF_VAL
parameter_list|(
name|id
parameter_list|)
value|((id& 0x0000007c)>> 2)
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMUCAPS
value|0x0604
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMUCAPS_REV
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_MINRES
value|0x0618
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_MAXRES
value|0x061c
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_TABSEL
value|0x0620
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_DEPMSK
value|0x0624
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_UPDNTM
value|0x0628
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PLLCTL_ADDR
value|0x0660
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PLLCTL_DATA
value|0x0664
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU0_PLL0
value|0
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU0_PLL0_PDIV_MSK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU0_PLL0_PDIV_FREQ
value|25000
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU0_PLL1
value|1
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU0_PLL1_IMSK
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU0_PLL1_FMSK
value|0x0fffff00
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU0_PLL1_STOPMOD
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU0_PLL2
value|2
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU0_PLL2_IMSKHI
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU1_PLL0
value|0
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU1_PLL0_P1DIV
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU1_PLL0_P2DIV
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU1_PLL2
value|2
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU1_PLL2_NDIVMODE
value|0x000e0000
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU1_PLL2_NDIVINT
value|0x1ff00000
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU1_PLL3
value|3
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU1_PLL3_NDIVFRAC
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU1_PLL5
value|5
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU1_PLL5_CLKDRV
value|0xffffff00
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU0_DEFAULT_XTALFREQ
value|20000
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU1_DEFAULT_FREQ
value|15360
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU1_PLLTAB_ENTRY
define|\
value|{									\ 	{ 12000,  1, 3, 22,  0x9, 0xffffef },				\ 	{ 13000,  2, 1,  6,  0xb, 0x483483 },				\ 	{ 14400,  3, 1, 10,  0xa, 0x1c71c7 },				\ 	{ 15360,  4, 1,  5,  0xb, 0x755555 },				\ 	{ 16200,  5, 1, 10,  0x5, 0x6e9e06 },				\ 	{ 16800,  6, 1, 10,  0x5, 0x3cf3cf },				\ 	{ 19200,  7, 1,  9,  0x5, 0x17b425 },				\ 	{ 19800,  8, 1, 11,  0x4, 0xa57eb },				\ 	{ 20000,  9, 1, 11,  0x4, 0 },					\ 	{ 24000, 10, 3, 11,  0xa, 0 },					\ 	{ 25000, 11, 5, 16,  0xb, 0 },					\ 	{ 26000, 12, 1,  2, 0x10, 0xec4ec4 },				\ 	{ 30000, 13, 3,  8,  0xb, 0 },					\ 	{ 38400, 14, 1,  5,  0x4, 0x955555 },				\ 	{ 40000, 15, 1,  2,  0xb, 0 }					\ }
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU0_PLLTAB_ENTRY
define|\
value|{									\ 	{ 12000,  1, 73, 349525, }, { 13000,  2, 67, 725937, },		\ 	{ 14400,  3, 61, 116508, }, { 15360,  4, 57, 305834, },		\ 	{ 16200,  5, 54, 336579, }, { 16800,  6, 52, 399457, },		\ 	{ 19200,  7, 45, 873813, }, { 19800,  8, 44, 466033, },		\ 	{ 20000,  9, 44, 0,      }, { 25000, 10, 70, 419430, },		\ 	{ 26000, 11, 67, 725937, }, { 30000, 12, 58, 699050, },		\ 	{ 38400, 13, 45, 873813, }, { 40000, 14, 45, 0,      },		\ }
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4325_BURST
value|1
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4325_CLBURST
value|3
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4325_LN
value|10
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4325_CRYSTAL
value|13
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4325_RX_PWR
value|15
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4325_TX_PWR
value|16
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4325_LOGEN_PWR
value|18
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4325_AFE_PWR
value|19
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4325_BBPLL_PWR
value|20
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4325_HT
value|21
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4328_EXT_SWITCH_PWM
value|0
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4328_BB_SWITCH_PWM
value|1
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4328_BB_SWITCH_BURST
value|2
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4328_BB_EXT_SWITCH_BURST
value|3
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4328_ILP_REQUEST
value|4
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4328_RADSWITCH_PWM
value|5
end_define

begin_comment
comment|/* radio switch */
end_comment

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4328_RADSWITCH_BURST
value|6
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4328_ROM_SWITCH
value|7
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4328_PA_REF
value|8
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4328_RADIO
value|9
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4328_AFE
value|10
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4328_PLL
value|11
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4328_BG_FILTBYP
value|12
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4328_TX_FILTBYP
value|13
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4328_RX_FILTBYP
value|14
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4328_CRYSTAL_PU
value|15
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4328_CRYSTAL_EN
value|16
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4328_BB_PLL_FILTBYP
value|17
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4328_RF_PLL_FILTBYP
value|18
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4328_BB_PLL_PU
value|19
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_5354_BB_PLL_PU
value|19
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4325_RES_UPDOWN
define|\
value|{									\ 	{ SIBA_CC_PMU_4325_CRYSTAL, 0x1501 }				\ }
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4325_RES_DEPEND
define|\
value|{									\ 	{ SIBA_CC_PMU_4325_HT, SIBA_CC_PMU_DEP_ADD,			\ 	  ((1<< SIBA_CC_PMU_4325_RX_PWR) |				\ 	   (1<< SIBA_CC_PMU_4325_TX_PWR) |				\ 	   (1<< SIBA_CC_PMU_4325_LOGEN_PWR) |				\ 	   (1<< SIBA_CC_PMU_4325_AFE_PWR)) }				\ }
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4328_RES_UPDOWN
define|\
value|{									\ 	{ SIBA_CC_PMU_4328_EXT_SWITCH_PWM, 0x0101 },			\ 	{ SIBA_CC_PMU_4328_BB_SWITCH_PWM, 0x1f01 },			\ 	{ SIBA_CC_PMU_4328_BB_SWITCH_BURST, 0x010f },			\ 	{ SIBA_CC_PMU_4328_BB_EXT_SWITCH_BURST, 0x0101 },		\ 	{ SIBA_CC_PMU_4328_ILP_REQUEST, 0x0202 },			\ 	{ SIBA_CC_PMU_4328_RADSWITCH_PWM, 0x0f01 },			\ 	{ SIBA_CC_PMU_4328_RADSWITCH_BURST, 0x0f01 },			\ 	{ SIBA_CC_PMU_4328_ROM_SWITCH, 0x0101 },			\ 	{ SIBA_CC_PMU_4328_PA_REF, 0x0f01 },				\ 	{ SIBA_CC_PMU_4328_RADIO, 0x0f01 },				\ 	{ SIBA_CC_PMU_4328_AFE, 0x0f01 },				\ 	{ SIBA_CC_PMU_4328_PLL, 0x0f01 },				\ 	{ SIBA_CC_PMU_4328_BG_FILTBYP, 0x0101 },			\ 	{ SIBA_CC_PMU_4328_TX_FILTBYP, 0x0101 },			\ 	{ SIBA_CC_PMU_4328_RX_FILTBYP, 0x0101 },			\ 	{ SIBA_CC_PMU_4328_CRYSTAL_PU, 0x0101 },			\ 	{ SIBA_CC_PMU_4328_CRYSTAL_EN, 0xa001 },			\ 	{ SIBA_CC_PMU_4328_BB_PLL_FILTBYP, 0x0101 },			\ 	{ SIBA_CC_PMU_4328_RF_PLL_FILTBYP, 0x0101 },			\ 	{ SIBA_CC_PMU_4328_BB_PLL_PU, 0x0701 },				\ }
end_define

begin_define
define|#
directive|define
name|SIBA_CC_PMU_4328_RES_DEPEND
define|\
value|{									\ 	{ SIBA_CC_PMU_4328_ILP_REQUEST, SIBA_CC_PMU_DEP_SET,		\ 	  ((1<< SIBA_CC_PMU_4328_EXT_SWITCH_PWM) |			\ 	   (1<< SIBA_CC_PMU_4328_BB_SWITCH_PWM)) },			\ }
end_define

begin_define
define|#
directive|define
name|SIBA_CC_CHST_4325_PMUTOP_2B
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SIBA_BAR0
value|0x80
end_define

begin_define
define|#
directive|define
name|SIBA_IRQMASK
value|0x94
end_define

begin_define
define|#
directive|define
name|SIBA_GPIO_IN
value|0xb0
end_define

begin_define
define|#
directive|define
name|SIBA_GPIO_OUT
value|0xb4
end_define

begin_define
define|#
directive|define
name|SIBA_GPIO_OUT_EN
value|0xb8
end_define

begin_define
define|#
directive|define
name|SIBA_GPIO_CRYSTAL
value|0x40
end_define

begin_define
define|#
directive|define
name|SIBA_GPIO_PLL
value|0x80
end_define

begin_define
define|#
directive|define
name|SIBA_REGWIN
parameter_list|(
name|x
parameter_list|)
define|\
value|(SIBA_ENUM_START + ((x) * SIBA_CORE_LEN))
end_define

begin_define
define|#
directive|define
name|SIBA_CORE_LEN
value|0x00001000
end_define

begin_comment
comment|/* Size of cfg per core */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG_END
value|0x00010000
end_define

begin_comment
comment|/* Upper bound of cfg space */
end_comment

begin_define
define|#
directive|define
name|SIBA_MAX_CORES
value|(SIBA_CFG_END/SIBA_CORE_LEN)
end_define

begin_comment
comment|/* #max cores */
end_comment

begin_define
define|#
directive|define
name|SIBA_ENUM_START
value|0x18000000U
end_define

begin_define
define|#
directive|define
name|SIBA_ENUM_END
value|0x18010000U
end_define

begin_define
define|#
directive|define
name|SIBA_DMA_TRANSLATION_MASK
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|SIBA_PCI_DMA
value|0x40000000U
end_define

begin_define
define|#
directive|define
name|SIBA_TPS
value|0x0f18
end_define

begin_define
define|#
directive|define
name|SIBA_TPS_BPFLAG
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|SIBA_IAS
value|0x0f90
end_define

begin_comment
comment|/* Initiator Agent State */
end_comment

begin_define
define|#
directive|define
name|SIBA_IAS_INBAND_ERR
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SIBA_IAS_TIMEOUT
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SIBA_INTR_MASK
value|0x0f94
end_define

begin_define
define|#
directive|define
name|SIBA_TGSLOW
value|0x0f98
end_define

begin_define
define|#
directive|define
name|SIBA_TGSLOW_RESET
value|0x00000001
end_define

begin_comment
comment|/* target state low */
end_comment

begin_define
define|#
directive|define
name|SIBA_TGSLOW_REJECT_22
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SIBA_TGSLOW_REJECT_23
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SIBA_TGSLOW_CLOCK
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SIBA_TGSLOW_FGC
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SIBA_TGSHIGH
value|0x0f9c
end_define

begin_define
define|#
directive|define
name|SIBA_TGSHIGH_SERR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SIBA_TGSHIGH_BUSY
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SIBA_TGSHIGH_DMA64
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SIBA_IMCFGLO
value|0x0fa8
end_define

begin_define
define|#
directive|define
name|SIBA_IMCFGLO_SERTO
value|0x00000007
end_define

begin_define
define|#
directive|define
name|SIBA_IMCFGLO_REQTO
value|0x00000070
end_define

begin_define
define|#
directive|define
name|SIBA_IDLOW
value|0x0ff8
end_define

begin_define
define|#
directive|define
name|SIBA_IDLOW_SSBREV
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|SIBA_IDLOW_SSBREV_22
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SIBA_IDLOW_SSBREV_23
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SIBA_IDLOW_SSBREV_24
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SIBA_IDLOW_SSBREV_25
value|0x50000000
end_define

begin_define
define|#
directive|define
name|SIBA_IDLOW_SSBREV_26
value|0x60000000
end_define

begin_define
define|#
directive|define
name|SIBA_IDLOW_SSBREV_27
value|0x70000000
end_define

begin_define
define|#
directive|define
name|SIBA_IDHIGH
value|0x0ffc
end_define

begin_define
define|#
directive|define
name|SIBA_IDHIGH_CORECODEMASK
value|0x00008FF0
end_define

begin_comment
comment|/* Core Code */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDHIGH_CORECODE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|SIBA_IDHIGH_CORECODE
parameter_list|(
name|id
parameter_list|)
define|\
value|((id& SIBA_IDHIGH_CORECODEMASK)>> SIBA_IDHIGH_CORECODE_SHIFT)
end_define

begin_comment
comment|/* Revision Code (low part) */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDHIGH_REVLO
value|0x0000000f
end_define

begin_comment
comment|/* Revision Code (high part) */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDHIGH_REVHI
value|0x00007000
end_define

begin_define
define|#
directive|define
name|SIBA_IDHIGH_REVHI_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SIBA_IDHIGH_REV
parameter_list|(
name|id
parameter_list|)
define|\
value|((id& SIBA_IDHIGH_REVLO) | ((id& SIBA_IDHIGH_REVHI)>>	\ 	    SIBA_IDHIGH_REVHI_SHIFT))
end_define

begin_define
define|#
directive|define
name|SIBA_IDHIGH_VENDORMASK
value|0xFFFF0000
end_define

begin_comment
comment|/* Vendor Code */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDHIGH_VENDOR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SIBA_IDHIGH_VENDOR
parameter_list|(
name|id
parameter_list|)
define|\
value|((id& SIBA_IDHIGH_VENDORMASK)>> SIBA_IDHIGH_VENDOR_SHIFT)
end_define

begin_define
define|#
directive|define
name|SIBA_SPROMSIZE_R123
value|64
end_define

begin_define
define|#
directive|define
name|SIBA_SPROMSIZE_R4
value|220
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM_BASE
value|0x1000
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM_REV_CRC
value|0xff00
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_MAC_80211BG
value|0x1048
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_MAC_ETH
value|0x104e
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_MAC_80211A
value|0x1054
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_ETHPHY
value|0x105a
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_ETHPHY_MII_ETH0
value|0x001f
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_ETHPHY_MII_ETH1
value|0x03e0
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_ETHPHY_MDIO_ETH0
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_ETHPHY_MDIO_ETH1
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_BOARDINFO
value|0x105c
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_BOARDINFO_BREV
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_BOARDINFO_CCODE
value|0x0f00
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_BOARDINFO_ANTBG
value|0x3000
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_BOARDINFO_ANTA
value|0xc000
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_PA0B0
value|0x105e
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_PA0B1
value|0x1060
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_PA0B2
value|0x1062
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_GPIOA
value|0x1064
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_GPIOA_P0
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_GPIOA_P1
value|0xff00
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_GPIOB
value|0x1066
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_GPIOB_P2
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_GPIOB_P3
value|0xff00
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_MAXPWR
value|0x1068
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_MAXPWR_BG
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_MAXPWR_A
value|0xff00
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_PA1B0
value|0x106a
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_PA1B1
value|0x106c
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_PA1B2
value|0x106e
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_TSSI
value|0x1070
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_TSSI_BG
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_TSSI_A
value|0xff00
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_BFLOW
value|0x1072
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_AGAIN
value|0x1074
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_AGAIN_BG
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM1_AGAIN_A
value|0xff00
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM2_BFHIGH
value|0x1038
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM3_MAC_80211BG
value|0x104a
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_MAC_80211BG
value|0x104c
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_ETHPHY
value|0x105a
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_ETHPHY_ET0A
value|0x001f
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_ETHPHY_ET1A
value|0x03e0
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_CCODE
value|0x1052
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_ANTAVAIL
value|0x105d
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_ANTAVAIL_A
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_ANTAVAIL_BG
value|0xff00
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_BFLOW
value|0x1044
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_AGAIN01
value|0x105e
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_AGAIN0
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_AGAIN1
value|0xff00
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_AGAIN23
value|0x1060
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_AGAIN2
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_AGAIN3
value|0xff00
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_BFHIGH
value|0x1046
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_MAXP_BG
value|0x1080
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_MAXP_BG_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_TSSI_BG
value|0xff00
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_MAXP_A
value|0x108a
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_MAXP_A_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_TSSI_A
value|0xff00
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_GPIOA
value|0x1056
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_GPIOA_P0
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_GPIOA_P1
value|0xff00
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_GPIOB
value|0x1058
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_GPIOB_P2
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM4_GPIOB_P3
value|0xff00
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM5_BFLOW
value|0x104a
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM5_BFHIGH
value|0x104c
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM5_MAC_80211BG
value|0x1052
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM5_CCODE
value|0x1044
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM5_GPIOA
value|0x1076
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM5_GPIOA_P0
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM5_GPIOA_P1
value|0xff00
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM5_GPIOB
value|0x1078
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM5_GPIOB_P2
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM5_GPIOB_P3
value|0xff00
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_BFLOW
value|0x1084
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_BFHIGH
value|0x1086
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_CCODE
value|0x1092
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_ANTAVAIL
value|0x109c
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_ANTAVAIL_A
value|0xff00
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_ANTAVAIL_BG
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_AGAIN01
value|0x109e
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_AGAIN0
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_AGAIN1
value|0xff00
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_AGAIN23
value|0x10a0
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_AGAIN2
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_AGAIN3
value|0xff00
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_GPIOA
value|0x1096
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_GPIOA_P0
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_GPIOA_P1
value|0xff00
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_GPIOB
value|0x1098
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_GPIOB_P2
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_GPIOB_P3
value|0xff00
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_MAXP_BG
value|0x10c0
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_MAXP_BG_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_TSSI_BG
value|0xff00
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_MAXP_A
value|0x10c8
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_MAXP_A_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SIBA_SPROM8_TSSI_A
value|0xff00
end_define

begin_define
define|#
directive|define
name|SIBA_BOARDVENDOR_DELL
value|0x1028
end_define

begin_define
define|#
directive|define
name|SIBA_BOARDVENDOR_BCM
value|0x14e4
end_define

begin_define
define|#
directive|define
name|SIBA_BOARD_BCM4309G
value|0x0421
end_define

begin_define
define|#
directive|define
name|SIBA_BOARD_MP4318
value|0x044a
end_define

begin_define
define|#
directive|define
name|SIBA_BOARD_BU4306
value|0x0416
end_define

begin_define
define|#
directive|define
name|SIBA_BOARD_BU4309
value|0x040a
end_define

begin_define
define|#
directive|define
name|SIBA_PCICORE_BCAST_ADDR
value|SIBA_CC_BCAST_ADDR
end_define

begin_define
define|#
directive|define
name|SIBA_PCICORE_BCAST_DATA
value|SIBA_CC_BCAST_DATA
end_define

begin_define
define|#
directive|define
name|SIBA_PCICORE_SBTOPCI0
value|0x0100
end_define

begin_define
define|#
directive|define
name|SIBA_PCICORE_SBTOPCI1
value|0x0104
end_define

begin_define
define|#
directive|define
name|SIBA_PCICORE_SBTOPCI2
value|0x0108
end_define

begin_define
define|#
directive|define
name|SIBA_PCICORE_MDIO_CTL
value|0x0128
end_define

begin_define
define|#
directive|define
name|SIBA_PCICORE_MDIO_DATA
value|0x012c
end_define

begin_define
define|#
directive|define
name|SIBA_PCICORE_SBTOPCI_PREF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SIBA_PCICORE_SBTOPCI_BURST
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SIBA_PCICORE_SBTOPCI_MRM
value|0x00000020
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SIBA_SIBAREG_H_ */
end_comment

end_unit

