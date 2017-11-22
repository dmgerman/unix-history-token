begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landon@landonf.org>  * Copyright (c) 2010 Broadcom Corporation  * All rights reserved.  *  * This file is derived from the sbchipc.h header contributed by Broadcom   * to to the Linux staging repository, as well as later revisions of sbchipc.h  * distributed with the Asus RT-N16 firmware source code release.  *   * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_CORES_PMU_BHND_PMUREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_CORES_PMU_BHND_PMUREG_H_
end_define

begin_define
define|#
directive|define
name|BHND_PMU_GET_FLAG
parameter_list|(
name|_value
parameter_list|,
name|_flag
parameter_list|)
define|\
value|(((_value)& _flag) != 0)
end_define

begin_define
define|#
directive|define
name|BHND_PMU_GET_BITS
parameter_list|(
name|_value
parameter_list|,
name|_field
parameter_list|)
define|\
value|(((_value)& _field ## _MASK)>> _field ## _SHIFT)
end_define

begin_define
define|#
directive|define
name|BHND_PMU_SET_BITS
parameter_list|(
name|_value
parameter_list|,
name|_field
parameter_list|)
define|\
value|(((_value)<< _field ## _SHIFT)& _field ## _MASK)
end_define

begin_define
define|#
directive|define
name|BHND_PMU_ILP_CLOCK
value|32000
end_define

begin_comment
comment|/**< default ILP freq */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_ALP_CLOCK
value|20000000
end_define

begin_comment
comment|/**< default ALP freq */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_HT_CLOCK
value|80000000
end_define

begin_comment
comment|/**< default HT freq */
end_comment

begin_comment
comment|/**  * Common per-core clock control/status register available on PMU-equipped  * devices.  */
end_comment

begin_define
define|#
directive|define
name|BHND_CLK_CTL_ST
value|0x1e0
end_define

begin_comment
comment|/**< clock control and status */
end_comment

begin_comment
comment|/*  * BHND_CLK_CTL_ST register   *   * Clock Mode		Name	Description  * High Throughput	(HT)	Full bandwidth, low latency. Generally supplied  * 				from PLL.  * Active Low Power	(ALP)	Register access, low speed DMA.  * Idle Low Power	(ILP)	No interconnect activity, or if long latency  * 				is permitted.  */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_FORCEALP
value|0x00000001
end_define

begin_comment
comment|/**< force ALP request */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_FORCEHT
value|0x00000002
end_define

begin_comment
comment|/**< force HT request */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_FORCEILP
value|0x00000004
end_define

begin_comment
comment|/**< force ILP request */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_FORCE_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|BHND_CCS_ALPAREQ
value|0x00000008
end_define

begin_comment
comment|/**< ALP Avail Request */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_HTAREQ
value|0x00000010
end_define

begin_comment
comment|/**< HT Avail Request */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_AREQ_MASK
value|0x00000018
end_define

begin_define
define|#
directive|define
name|BHND_CCS_FORCEHWREQOFF
value|0x00000020
end_define

begin_comment
comment|/**< Force HW Clock Request Off */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_ERSRC_REQ_MASK
value|0x00000700
end_define

begin_comment
comment|/**< external resource requests */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_ERSRC_REQ_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BHND_CCS_ERSRC_MAX
value|2
end_define

begin_comment
comment|/**< maximum ERSRC value (corresponding to bits 0-2) */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_ALPAVAIL
value|0x00010000
end_define

begin_comment
comment|/**< ALP is available */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_HTAVAIL
value|0x00020000
end_define

begin_comment
comment|/**< HT is available */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_AVAIL_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|BHND_CCS_BP_ON_APL
value|0x00040000
end_define

begin_comment
comment|/**< RO: Backplane is running on ALP clock */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_BP_ON_HT
value|0x00080000
end_define

begin_comment
comment|/**< RO: Backplane is running on HT clock */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_ERSRC_STS_MASK
value|0x07000000
end_define

begin_comment
comment|/**< external resource status */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS_ERSRC_STS_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|BHND_CCS0_HTAVAIL
value|0x00010000
end_define

begin_comment
comment|/**< HT avail in chipc and pcmcia on 4328a0 */
end_comment

begin_define
define|#
directive|define
name|BHND_CCS0_ALPAVAIL
value|0x00020000
end_define

begin_comment
comment|/**< ALP avail in chipc and pcmcia on 4328a0 */
end_comment

begin_comment
comment|/* PMU registers */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_CTRL
value|0x600
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CTRL_ILP_DIV_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CTRL_ILP_DIV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CTRL_PLL_PLLCTL_UPD
value|0x00000400
end_define

begin_comment
comment|/* rev 2 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_CTRL_NOILP_ON_WAIT
value|0x00000200
end_define

begin_comment
comment|/* rev 1 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_CTRL_HT_REQ_EN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CTRL_ALP_REQ_EN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CTRL_XTALFREQ_MASK
value|0x0000007c
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CTRL_XTALFREQ_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CTRL_ILP_DIV_EN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CTRL_LPO_SEL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CAP
value|0x604
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CAP_REV_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CAP_REV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CAP_RC_MASK
value|0x00001f00
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CAP_RC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CAP_RC_MAX
define|\
value|(BHND_PMU_CAP_RC_MASK>> BHND_PMU_CAP_RC_SHIFT)
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CAP_TC_MASK
value|0x0001e000
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CAP_TC_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CAP_PC_MASK
value|0x001e0000
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CAP_PC_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CAP_VC_MASK
value|0x01e00000
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CAP_VC_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CAP_CC_MASK
value|0x1e000000
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CAP_CC_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CAP5_PC_MASK
value|0x003e0000
end_define

begin_comment
comment|/* PMU corerev>= 5 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_CAP5_PC_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CAP5_VC_MASK
value|0x07c00000
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CAP5_VC_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CAP5_CC_MASK
value|0xf8000000
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CAP5_CC_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|BHND_PMU_ST
value|0x608
end_define

begin_define
define|#
directive|define
name|BHND_PMU_ST_EXTLPOAVAIL
value|0x0100
end_define

begin_define
define|#
directive|define
name|BHND_PMU_ST_WDRESET
value|0x0080
end_define

begin_define
define|#
directive|define
name|BHND_PMU_ST_INTPEND
value|0x0040
end_define

begin_define
define|#
directive|define
name|BHND_PMU_ST_SBCLKST
value|0x0030
end_define

begin_define
define|#
directive|define
name|BHND_PMU_ST_SBCLKST_ILP
value|0x0010
end_define

begin_define
define|#
directive|define
name|BHND_PMU_ST_SBCLKST_ALP
value|0x0020
end_define

begin_define
define|#
directive|define
name|BHND_PMU_ST_SBCLKST_HT
value|0x0030
end_define

begin_define
define|#
directive|define
name|BHND_PMU_ST_ALPAVAIL
value|0x0008
end_define

begin_define
define|#
directive|define
name|BHND_PMU_ST_HTAVAIL
value|0x0004
end_define

begin_define
define|#
directive|define
name|BHND_PMU_ST_RESINIT
value|0x0003
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES_STATE
value|0x60c
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES_PENDING
value|0x610
end_define

begin_define
define|#
directive|define
name|BHND_PMU_TIMER
value|0x614
end_define

begin_define
define|#
directive|define
name|BHND_PMU_MIN_RES_MASK
value|0x618
end_define

begin_define
define|#
directive|define
name|BHND_PMU_MAX_RES_MASK
value|0x61c
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES_TABLE_SEL
value|0x620
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES_DEP_MASK
value|0x624
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES_UPDN_TIMER
value|0x628
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES_UPDN_UPTME_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES_UPDN_UPTME_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES_TIMER
value|0x62C
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CLKSTRETCH
value|0x630
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CSTRETCH_HT
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CSTRETCH_ALP
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|BHND_PMU_WATCHDOG
value|0x634
end_define

begin_define
define|#
directive|define
name|BHND_PMU_GPIOSEL
value|0x638
end_define

begin_comment
comment|/* pmu rev>= 1 ? */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_GPIOEN
value|0x63C
end_define

begin_comment
comment|/* pmu rev>= 1 ? */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES_REQ_TIMER_SEL
value|0x640
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES_REQ_TIMER
value|0x644
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RRQT_TIME_MASK
value|0x03ff
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RRQT_INTEN
value|0x0400
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RRQT_REQ_ACTIVE
value|0x0800
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RRQT_ALP_REQ
value|0x1000
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RRQT_HT_REQ
value|0x2000
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES_REQ_MASK
value|0x648
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CHIP_CONTROL_ADDR
value|0x650
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CHIP_CONTROL_DATA
value|0x654
end_define

begin_define
define|#
directive|define
name|BHND_PMU_REG_CONTROL_ADDR
value|0x658
end_define

begin_define
define|#
directive|define
name|BHND_PMU_REG_CONTROL_DATA
value|0x65C
end_define

begin_define
define|#
directive|define
name|BHND_PMU_PLL_CONTROL_ADDR
value|0x660
end_define

begin_define
define|#
directive|define
name|BHND_PMU_PLL_CONTROL_DATA
value|0x664
end_define

begin_define
define|#
directive|define
name|BHND_PMU_STRAPOPT
value|0x668
end_define

begin_comment
comment|/* chipc rev>= 28 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_XTALFREQ
value|0x66C
end_define

begin_comment
comment|/* pmu rev>= 10 */
end_comment

begin_comment
comment|/* PMU resource bit position */
end_comment

begin_define
define|#
directive|define
name|BHND_PMURES_BIT
parameter_list|(
name|bit
parameter_list|)
value|(1<< (bit))
end_define

begin_comment
comment|/* PMU resource number limit */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RESNUM_MAX
value|30
end_define

begin_comment
comment|/* PMU chip control0 register */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_CHIPCTL0
value|0
end_define

begin_comment
comment|/* PMU chip control1 register */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_CHIPCTL1
value|1
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CC1_RXC_DLL_BYPASS
value|0x00010000
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CC1_IF_TYPE_MASK
value|0x00000030
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CC1_IF_TYPE_RMII
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CC1_IF_TYPE_MII
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CC1_IF_TYPE_RGMII
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CC1_SW_TYPE_MASK
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CC1_SW_TYPE_EPHY
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CC1_SW_TYPE_EPHYMII
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CC1_SW_TYPE_EPHYRMII
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CC1_SW_TYPE_RGMII
value|0x000000c0
end_define

begin_comment
comment|/* PMU corerev and chip specific PLL controls.  * PMU<rev>_PLL<num>_XX where<rev> is PMU corerev and<num> is an arbitrary number  * to differentiate different PLLs controlled by the same PMU rev.  */
end_comment

begin_comment
comment|/* pllcontrol registers */
end_comment

begin_comment
comment|/* PDIV, div_phy, div_arm, div_adc, dith_sel, ioff, kpd_scale, lsb_sel, mash_sel, lf_c& lf_r */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PLLCTL0
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PC0_PDIV_MASK
value|1
end_define

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PC0_PDIV_FREQ
value|25000
end_define

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PC0_DIV_ARM_MASK
value|0x00000038
end_define

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PC0_DIV_ARM_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PC0_DIV_ARM_BASE
value|8
end_define

begin_comment
comment|/* PC0_DIV_ARM for PLLOUT_ARM */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PC0_DIV_ARM_110MHZ
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PC0_DIV_ARM_97_7MHZ
value|1
end_define

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PC0_DIV_ARM_88MHZ
value|2
end_define

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PC0_DIV_ARM_80MHZ
value|3
end_define

begin_comment
comment|/* Default */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PC0_DIV_ARM_73_3MHZ
value|4
end_define

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PC0_DIV_ARM_67_7MHZ
value|5
end_define

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PC0_DIV_ARM_62_9MHZ
value|6
end_define

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PC0_DIV_ARM_58_6MHZ
value|7
end_define

begin_comment
comment|/* Wildcard base, stop_mod, en_lf_tp, en_cal& lf_r2 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PLLCTL1
value|1
end_define

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PC1_WILD_INT_MASK
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PC1_WILD_INT_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PC1_WILD_FRAC_MASK
value|0x0fffff00
end_define

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PC1_WILD_FRAC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PC1_STOP_MOD
value|0x00000040
end_define

begin_comment
comment|/* Wildcard base, vco_calvar, vco_swc, vco_var_selref, vso_ical& vco_sel_avdd */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PLLCTL2
value|2
end_define

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PC2_WILD_INT_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|BHND_PMU0_PLL0_PC2_WILD_INT_SHIFT
value|4
end_define

begin_comment
comment|/* pllcontrol registers */
end_comment

begin_comment
comment|/* ndiv_pwrdn, pwrdn_ch<x>, refcomp_pwrdn, dly_ch<x>, p1div, p2div, _bypass_sdmod */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PLLCTL0
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC0_P1DIV_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC0_P1DIV_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC0_P2DIV_MASK
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC0_P2DIV_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC0_BYPASS_SDMOD_MASK
value|0x10000000
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC0_BYPASS_SDMOD_SHIFT
value|28
end_define

begin_comment
comment|/* m<x>div */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PLLCTL1
value|1
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC1_M1DIV_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC1_M1DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC1_M2DIV_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC1_M2DIV_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC1_M3DIV_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC1_M3DIV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC1_M4DIV_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC1_M4DIV_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|BHND_PMU_DOT11MAC_880MHZ_CLK_DIVISOR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BHND_PMU_DOT11MAC_880MHZ_CLK_DIVISOR_MASK
value|(0xFF<< BHND_PMU_DOT11MAC_880MHZ_CLK_DIVISOR_SHIFT)
end_define

begin_define
define|#
directive|define
name|BHND_PMU_DOT11MAC_880MHZ_CLK_DIVISOR_VAL
value|(0xE<< BHND_PMU_DOT11MAC_880MHZ_CLK_DIVISOR_SHIFT)
end_define

begin_comment
comment|/* m<x>div, ndiv_dither_mfb, ndiv_mode, ndiv_int */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PLLCTL2
value|2
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC2_M5DIV_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC2_M5DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC2_M6DIV_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC2_M6DIV_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC2_NDIV_MODE_MASK
value|0x000e0000
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC2_NDIV_MODE_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC2_NDIV_MODE_INT
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC2_NDIV_MODE_MASH
value|1
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC2_NDIV_MODE_MFB
value|2
end_define

begin_comment
comment|/* recommended for 4319 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC2_NDIV_INT_MASK
value|0x1ff00000
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC2_NDIV_INT_SHIFT
value|20
end_define

begin_comment
comment|/* ndiv_frac */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PLLCTL3
value|3
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC3_NDIV_FRAC_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC3_NDIV_FRAC_SHIFT
value|0
end_define

begin_comment
comment|/* pll_ctrl */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PLLCTL4
value|4
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC4_KVCO_XS_MASK
value|0x38000000
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC4_KVCO_XS_SHIFT
value|27
end_define

begin_comment
comment|/* pll_ctrl, vco_rng, clkdrive_ch<x> */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PLLCTL5
value|5
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC5_CLK_DRV_MASK
value|0xffffff00
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC5_CLK_DRV_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC5_PLL_CTRL_37_32_MASK
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC5_PLL_CTRL_37_32_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC5_VCO_RNG_MASK
value|0x000000C0
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_PC5_VCO_RNG_SHIFT
value|6
end_define

begin_comment
comment|/* PMU rev 2 control words */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU2_PHY_PLL_PLLCTL
value|4
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_SI_PLL_PLLCTL
value|10
end_define

begin_comment
comment|/* PMU rev 2 */
end_comment

begin_comment
comment|/* pllcontrol registers */
end_comment

begin_comment
comment|/* ndiv_pwrdn, pwrdn_ch<x>, refcomp_pwrdn, dly_ch<x>, p1div, p2div, _bypass_sdmod */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PLLCTL0
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC0_P1DIV_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC0_P1DIV_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC0_P2DIV_MASK
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC0_P2DIV_SHIFT
value|24
end_define

begin_comment
comment|/* m<x>div */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PLLCTL1
value|1
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC1_M1DIV_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC1_M1DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC1_M2DIV_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC1_M2DIV_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC1_M3DIV_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC1_M3DIV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC1_M4DIV_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC1_M4DIV_SHIFT
value|24
end_define

begin_comment
comment|/* m<x>div, ndiv_dither_mfb, ndiv_mode, ndiv_int */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PLLCTL2
value|2
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC2_M5DIV_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC2_M5DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC2_M6DIV_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC2_M6DIV_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC2_NDIV_MODE_MASK
value|0x000e0000
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC2_NDIV_MODE_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC2_NDIV_INT_MASK
value|0x1ff00000
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC2_NDIV_INT_SHIFT
value|20
end_define

begin_comment
comment|/* ndiv_frac */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PLLCTL3
value|3
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC3_NDIV_FRAC_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC3_NDIV_FRAC_SHIFT
value|0
end_define

begin_comment
comment|/* pll_ctrl */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PLLCTL4
value|4
end_define

begin_comment
comment|/* pll_ctrl, vco_rng, clkdrive_ch<x> */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PLLCTL5
value|5
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC5_CLKDRIVE_CH1_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC5_CLKDRIVE_CH1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC5_CLKDRIVE_CH2_MASK
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC5_CLKDRIVE_CH2_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC5_CLKDRIVE_CH3_MASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC5_CLKDRIVE_CH3_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC5_CLKDRIVE_CH4_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC5_CLKDRIVE_CH4_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC5_CLKDRIVE_CH5_MASK
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC5_CLKDRIVE_CH5_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC5_CLKDRIVE_CH6_MASK
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|BHND_PMU2_PLL_PC5_CLKDRIVE_CH6_SHIFT
value|28
end_define

begin_comment
comment|/* PMU rev 5 (& 6) */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU5_PLL_P1P2_OFF
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_PLL_P1_MASK
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_PLL_P1_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_PLL_P2_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_PLL_P2_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_PLL_M14_OFF
value|1
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_PLL_MDIV_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_PLL_MDIV_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_PLL_NM5_OFF
value|2
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_PLL_NDIV_MASK
value|0xfff00000
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_PLL_NDIV_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_PLL_NDIV_MODE_MASK
value|0x000e0000
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_PLL_NDIV_MODE_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_PLL_FMAB_OFF
value|3
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_PLL_MRAT_MASK
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_PLL_MRAT_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_PLL_ABRAT_MASK
value|0x08000000
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_PLL_ABRAT_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_PLL_FDIV_MASK
value|0x07ffffff
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_PLL_PLLCTL_OFF
value|4
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_PLL_PCHI_OFF
value|5
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_PLL_PCHI_MASK
value|0x0000003f
end_define

begin_comment
comment|/* pmu XtalFreqRatio */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_XTALFREQ_REG_ILPCTR_MASK
value|0x00001FFF
end_define

begin_define
define|#
directive|define
name|BHND_PMU_XTALFREQ_REG_ILPCTR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU_XTALFREQ_REG_MEASURE_MASK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BHND_PMU_XTALFREQ_REG_MEASURE_SHIFT
value|31
end_define

begin_comment
comment|/* Divider allocation in 4716/47162/5356/5357 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU5_MAINPLL_CPU
value|1
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_MAINPLL_MEM
value|2
end_define

begin_define
define|#
directive|define
name|BHND_PMU5_MAINPLL_SI
value|3
end_define

begin_comment
comment|/* PMU rev 6 (BCM4706/Northstar) */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU4706_MAINPLL_PLL0
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU6_4706_PROCPLL_OFF
value|4
end_define

begin_comment
comment|/* The CPU PLL */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU6_4706_PROC_P1DIV_MASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|BHND_PMU6_4706_PROC_P1DIV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BHND_PMU6_4706_PROC_P2DIV_MASK
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|BHND_PMU6_4706_PROC_P2DIV_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|BHND_PMU6_4706_PROC_NDIV_INT_MASK
value|0x00000ff8
end_define

begin_define
define|#
directive|define
name|BHND_PMU6_4706_PROC_NDIV_INT_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|BHND_PMU6_4706_PROC_NDIV_MODE_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|BHND_PMU6_4706_PROC_NDIV_MODE_SHIFT
value|0
end_define

begin_comment
comment|/* Divider allocation in 4706 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU6_MAINPLL_CPU
value|1
end_define

begin_define
define|#
directive|define
name|BHND_PMU6_MAINPLL_MEM
value|2
end_define

begin_define
define|#
directive|define
name|BHND_PMU6_MAINPLL_SI
value|3
end_define

begin_comment
comment|/* PMU7 (?) */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU7_PLL_PLLCTL7
value|7
end_define

begin_define
define|#
directive|define
name|BHND_PMU7_PLL_PLLCTL8
value|8
end_define

begin_define
define|#
directive|define
name|BHND_PMU7_PLL_PLLCTL11
value|11
end_define

begin_comment
comment|/* PLL usage in 4716/47162 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU4716_MAINPLL_PLL0
value|12
end_define

begin_comment
comment|/* PLL usage in 5356/5357 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU5356_MAINPLL_PLL0
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU5357_MAINPLL_PLL0
value|0
end_define

begin_comment
comment|/* 4716/47162 PMU resources */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4716_PROC_PLL_ON
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4716_PROC_HT_AVAIL
value|0x00000080
end_define

begin_comment
comment|/* 4716/4717/4718 chip-specific CHIPCTRL PMU register bits */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_CCTRL471X_I2S_PINS_ENABLE
value|0x0080
end_define

begin_comment
comment|/* I2S pins off by default, shared with pflash */
end_comment

begin_comment
comment|/* 5354 PMU resources */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES5354_EXT_SWITCHER_PWM
value|0
end_define

begin_comment
comment|/* 0x00001 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES5354_BB_SWITCHER_PWM
value|1
end_define

begin_comment
comment|/* 0x00002 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES5354_BB_SWITCHER_BURST
value|2
end_define

begin_comment
comment|/* 0x00004 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES5354_BB_EXT_SWITCHER_BURST
value|3
end_define

begin_comment
comment|/* 0x00008 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES5354_ILP_REQUEST
value|4
end_define

begin_comment
comment|/* 0x00010 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES5354_RADIO_SWITCHER_PWM
value|5
end_define

begin_comment
comment|/* 0x00020 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES5354_RADIO_SWITCHER_BURST
value|6
end_define

begin_comment
comment|/* 0x00040 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES5354_ROM_SWITCH
value|7
end_define

begin_comment
comment|/* 0x00080 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES5354_PA_REF_LDO
value|8
end_define

begin_comment
comment|/* 0x00100 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES5354_RADIO_LDO
value|9
end_define

begin_comment
comment|/* 0x00200 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES5354_AFE_LDO
value|10
end_define

begin_comment
comment|/* 0x00400 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES5354_PLL_LDO
value|11
end_define

begin_comment
comment|/* 0x00800 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES5354_BG_FILTBYP
value|12
end_define

begin_comment
comment|/* 0x01000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES5354_TX_FILTBYP
value|13
end_define

begin_comment
comment|/* 0x02000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES5354_RX_FILTBYP
value|14
end_define

begin_comment
comment|/* 0x04000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES5354_XTAL_PU
value|15
end_define

begin_comment
comment|/* 0x08000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES5354_XTAL_EN
value|16
end_define

begin_comment
comment|/* 0x10000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES5354_BB_PLL_FILTBYP
value|17
end_define

begin_comment
comment|/* 0x20000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES5354_RF_PLL_FILTBYP
value|18
end_define

begin_comment
comment|/* 0x40000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES5354_BB_PLL_PU
value|19
end_define

begin_comment
comment|/* 0x80000 */
end_comment

begin_comment
comment|/* 5357 chip-specific CHIPCTRL register bits */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_CCTRL5357_EXTPA
value|(1<<14)
end_define

begin_comment
comment|/* extPA in CHIPCTRL1, bit 14 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_CCTRL5357_ANT_MUX_2o3
value|(1<<15)
end_define

begin_comment
comment|/* 2o3 in CHIPCTRL1, bit 15 */
end_comment

begin_comment
comment|/* 4328 PMU resources */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4328_EXT_SWITCHER_PWM
value|0
end_define

begin_comment
comment|/* 0x00001 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4328_BB_SWITCHER_PWM
value|1
end_define

begin_comment
comment|/* 0x00002 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4328_BB_SWITCHER_BURST
value|2
end_define

begin_comment
comment|/* 0x00004 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4328_BB_EXT_SWITCHER_BURST
value|3
end_define

begin_comment
comment|/* 0x00008 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4328_ILP_REQUEST
value|4
end_define

begin_comment
comment|/* 0x00010 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4328_RADIO_SWITCHER_PWM
value|5
end_define

begin_comment
comment|/* 0x00020 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4328_RADIO_SWITCHER_BURST
value|6
end_define

begin_comment
comment|/* 0x00040 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4328_ROM_SWITCH
value|7
end_define

begin_comment
comment|/* 0x00080 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4328_PA_REF_LDO
value|8
end_define

begin_comment
comment|/* 0x00100 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4328_RADIO_LDO
value|9
end_define

begin_comment
comment|/* 0x00200 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4328_AFE_LDO
value|10
end_define

begin_comment
comment|/* 0x00400 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4328_PLL_LDO
value|11
end_define

begin_comment
comment|/* 0x00800 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4328_BG_FILTBYP
value|12
end_define

begin_comment
comment|/* 0x01000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4328_TX_FILTBYP
value|13
end_define

begin_comment
comment|/* 0x02000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4328_RX_FILTBYP
value|14
end_define

begin_comment
comment|/* 0x04000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4328_XTAL_PU
value|15
end_define

begin_comment
comment|/* 0x08000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4328_XTAL_EN
value|16
end_define

begin_comment
comment|/* 0x10000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4328_BB_PLL_FILTBYP
value|17
end_define

begin_comment
comment|/* 0x20000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4328_RF_PLL_FILTBYP
value|18
end_define

begin_comment
comment|/* 0x40000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4328_BB_PLL_PU
value|19
end_define

begin_comment
comment|/* 0x80000 */
end_comment

begin_comment
comment|/* 4325 A0/A1 PMU resources */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325_BUCK_BOOST_BURST
value|0
end_define

begin_comment
comment|/* 0x00000001 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325_CBUCK_BURST
value|1
end_define

begin_comment
comment|/* 0x00000002 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325_CBUCK_PWM
value|2
end_define

begin_comment
comment|/* 0x00000004 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325_CLDO_CBUCK_BURST
value|3
end_define

begin_comment
comment|/* 0x00000008 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325_CLDO_CBUCK_PWM
value|4
end_define

begin_comment
comment|/* 0x00000010 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325_BUCK_BOOST_PWM
value|5
end_define

begin_comment
comment|/* 0x00000020 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325_ILP_REQUEST
value|6
end_define

begin_comment
comment|/* 0x00000040 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325_ABUCK_BURST
value|7
end_define

begin_comment
comment|/* 0x00000080 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325_ABUCK_PWM
value|8
end_define

begin_comment
comment|/* 0x00000100 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325_LNLDO1_PU
value|9
end_define

begin_comment
comment|/* 0x00000200 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325_OTP_PU
value|10
end_define

begin_comment
comment|/* 0x00000400 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325_LNLDO3_PU
value|11
end_define

begin_comment
comment|/* 0x00000800 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325_LNLDO4_PU
value|12
end_define

begin_comment
comment|/* 0x00001000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325_XTAL_PU
value|13
end_define

begin_comment
comment|/* 0x00002000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325_ALP_AVAIL
value|14
end_define

begin_comment
comment|/* 0x00004000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325_RX_PWRSW_PU
value|15
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325_TX_PWRSW_PU
value|16
end_define

begin_comment
comment|/* 0x00010000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325_RFPLL_PWRSW_PU
value|17
end_define

begin_comment
comment|/* 0x00020000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325_LOGEN_PWRSW_PU
value|18
end_define

begin_comment
comment|/* 0x00040000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325_AFE_PWRSW_PU
value|19
end_define

begin_comment
comment|/* 0x00080000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325_BBPLL_PWRSW_PU
value|20
end_define

begin_comment
comment|/* 0x00100000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325_HT_AVAIL
value|21
end_define

begin_comment
comment|/* 0x00200000 */
end_comment

begin_comment
comment|/* 4325 B0/C0 PMU resources */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325B0_CBUCK_LPOM
value|1
end_define

begin_comment
comment|/* 0x00000002 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325B0_CBUCK_BURST
value|2
end_define

begin_comment
comment|/* 0x00000004 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325B0_CBUCK_PWM
value|3
end_define

begin_comment
comment|/* 0x00000008 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325B0_CLDO_PU
value|4
end_define

begin_comment
comment|/* 0x00000010 */
end_comment

begin_comment
comment|/* 4325 C1 PMU resources */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4325C1_LNLDO2_PU
value|12
end_define

begin_comment
comment|/* 0x00001000 */
end_comment

begin_comment
comment|/* 4325 PMU resources */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4329_RESERVED0
value|0
end_define

begin_comment
comment|/* 0x00000001 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4329_CBUCK_LPOM
value|1
end_define

begin_comment
comment|/* 0x00000002 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4329_CBUCK_BURST
value|2
end_define

begin_comment
comment|/* 0x00000004 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4329_CBUCK_PWM
value|3
end_define

begin_comment
comment|/* 0x00000008 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4329_CLDO_PU
value|4
end_define

begin_comment
comment|/* 0x00000010 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4329_PALDO_PU
value|5
end_define

begin_comment
comment|/* 0x00000020 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4329_ILP_REQUEST
value|6
end_define

begin_comment
comment|/* 0x00000040 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4329_RESERVED7
value|7
end_define

begin_comment
comment|/* 0x00000080 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4329_RESERVED8
value|8
end_define

begin_comment
comment|/* 0x00000100 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4329_LNLDO1_PU
value|9
end_define

begin_comment
comment|/* 0x00000200 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4329_OTP_PU
value|10
end_define

begin_comment
comment|/* 0x00000400 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4329_RESERVED11
value|11
end_define

begin_comment
comment|/* 0x00000800 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4329_LNLDO2_PU
value|12
end_define

begin_comment
comment|/* 0x00001000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4329_XTAL_PU
value|13
end_define

begin_comment
comment|/* 0x00002000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4329_ALP_AVAIL
value|14
end_define

begin_comment
comment|/* 0x00004000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4329_RX_PWRSW_PU
value|15
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4329_TX_PWRSW_PU
value|16
end_define

begin_comment
comment|/* 0x00010000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4329_RFPLL_PWRSW_PU
value|17
end_define

begin_comment
comment|/* 0x00020000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4329_LOGEN_PWRSW_PU
value|18
end_define

begin_comment
comment|/* 0x00040000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4329_AFE_PWRSW_PU
value|19
end_define

begin_comment
comment|/* 0x00080000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4329_BBPLL_PWRSW_PU
value|20
end_define

begin_comment
comment|/* 0x00100000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4329_HT_AVAIL
value|21
end_define

begin_comment
comment|/* 0x00200000 */
end_comment

begin_comment
comment|/* 4312 PMU resources (all PMU chips with little memory constraint) */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4312_SWITCHER_BURST
value|0
end_define

begin_comment
comment|/* 0x00000001 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4312_SWITCHER_PWM
value|1
end_define

begin_comment
comment|/* 0x00000002 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4312_PA_REF_LDO
value|2
end_define

begin_comment
comment|/* 0x00000004 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4312_CORE_LDO_BURST
value|3
end_define

begin_comment
comment|/* 0x00000008 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4312_CORE_LDO_PWM
value|4
end_define

begin_comment
comment|/* 0x00000010 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4312_RADIO_LDO
value|5
end_define

begin_comment
comment|/* 0x00000020 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4312_ILP_REQUEST
value|6
end_define

begin_comment
comment|/* 0x00000040 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4312_BG_FILTBYP
value|7
end_define

begin_comment
comment|/* 0x00000080 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4312_TX_FILTBYP
value|8
end_define

begin_comment
comment|/* 0x00000100 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4312_RX_FILTBYP
value|9
end_define

begin_comment
comment|/* 0x00000200 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4312_XTAL_PU
value|10
end_define

begin_comment
comment|/* 0x00000400 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4312_ALP_AVAIL
value|11
end_define

begin_comment
comment|/* 0x00000800 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4312_BB_PLL_FILTBYP
value|12
end_define

begin_comment
comment|/* 0x00001000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4312_RF_PLL_FILTBYP
value|13
end_define

begin_comment
comment|/* 0x00002000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4312_HT_AVAIL
value|14
end_define

begin_comment
comment|/* 0x00004000 */
end_comment

begin_comment
comment|/* 4322 PMU resources */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4322_RF_LDO
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4322_ILP_REQUEST
value|1
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4322_XTAL_PU
value|2
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4322_ALP_AVAIL
value|3
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4322_SI_PLL_ON
value|4
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4322_HT_SI_AVAIL
value|5
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4322_PHY_PLL_ON
value|6
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4322_HT_PHY_AVAIL
value|7
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4322_OTP_PU
value|8
end_define

begin_comment
comment|/* 43224 chip-specific CHIPCTRL register bits */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_CCTRL43224_GPIO_TOGGLE
value|0x8000
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CCTRL43224A0_12MA_LED_DRIVE
value|0x00F000F0
end_define

begin_comment
comment|/* 12 mA drive strength */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_CCTRL43224B0_12MA_LED_DRIVE
value|0xF0
end_define

begin_comment
comment|/* 12 mA drive strength for later 43224s */
end_comment

begin_comment
comment|/* 43236 PMU resources */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES43236_REGULATOR
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES43236_ILP_REQUEST
value|1
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES43236_XTAL_PU
value|2
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES43236_ALP_AVAIL
value|3
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES43236_SI_PLL_ON
value|4
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES43236_HT_SI_AVAIL
value|5
end_define

begin_comment
comment|/* 43236 chip-specific CHIPCTRL register bits */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_CCTRL43236_BT_COEXIST
value|(1<<0)
end_define

begin_comment
comment|/* 0 disable */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_CCTRL43236_SECI
value|(1<<1)
end_define

begin_comment
comment|/* 0 SECI is disabled (JATG functional) */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_CCTRL43236_EXT_LNA
value|(1<<2)
end_define

begin_comment
comment|/* 0 disable */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_CCTRL43236_ANT_MUX_2o3
value|(1<<3)
end_define

begin_comment
comment|/* 2o3 mux, chipcontrol bit 3 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_CCTRL43236_GSIO
value|(1<<4)
end_define

begin_comment
comment|/* 0 disable */
end_comment

begin_comment
comment|/* 4331 PMU resources */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4331_REGULATOR
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4331_ILP_REQUEST
value|1
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4331_XTAL_PU
value|2
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4331_ALP_AVAIL
value|3
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4331_SI_PLL_ON
value|4
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4331_HT_SI_AVAIL
value|5
end_define

begin_comment
comment|/* 4315 PMU resources */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4315_CBUCK_LPOM
value|1
end_define

begin_comment
comment|/* 0x00000002 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4315_CBUCK_BURST
value|2
end_define

begin_comment
comment|/* 0x00000004 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4315_CBUCK_PWM
value|3
end_define

begin_comment
comment|/* 0x00000008 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4315_CLDO_PU
value|4
end_define

begin_comment
comment|/* 0x00000010 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4315_PALDO_PU
value|5
end_define

begin_comment
comment|/* 0x00000020 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4315_ILP_REQUEST
value|6
end_define

begin_comment
comment|/* 0x00000040 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4315_LNLDO1_PU
value|9
end_define

begin_comment
comment|/* 0x00000200 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4315_OTP_PU
value|10
end_define

begin_comment
comment|/* 0x00000400 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4315_LNLDO2_PU
value|12
end_define

begin_comment
comment|/* 0x00001000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4315_XTAL_PU
value|13
end_define

begin_comment
comment|/* 0x00002000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4315_ALP_AVAIL
value|14
end_define

begin_comment
comment|/* 0x00004000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4315_RX_PWRSW_PU
value|15
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4315_TX_PWRSW_PU
value|16
end_define

begin_comment
comment|/* 0x00010000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4315_RFPLL_PWRSW_PU
value|17
end_define

begin_comment
comment|/* 0x00020000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4315_LOGEN_PWRSW_PU
value|18
end_define

begin_comment
comment|/* 0x00040000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4315_AFE_PWRSW_PU
value|19
end_define

begin_comment
comment|/* 0x00080000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4315_BBPLL_PWRSW_PU
value|20
end_define

begin_comment
comment|/* 0x00100000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4315_HT_AVAIL
value|21
end_define

begin_comment
comment|/* 0x00200000 */
end_comment

begin_comment
comment|/* 4319 PMU resources */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4319_CBUCK_LPOM
value|1
end_define

begin_comment
comment|/* 0x00000002 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4319_CBUCK_BURST
value|2
end_define

begin_comment
comment|/* 0x00000004 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4319_CBUCK_PWM
value|3
end_define

begin_comment
comment|/* 0x00000008 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4319_CLDO_PU
value|4
end_define

begin_comment
comment|/* 0x00000010 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4319_PALDO_PU
value|5
end_define

begin_comment
comment|/* 0x00000020 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4319_ILP_REQUEST
value|6
end_define

begin_comment
comment|/* 0x00000040 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4319_LNLDO1_PU
value|9
end_define

begin_comment
comment|/* 0x00000200 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4319_OTP_PU
value|10
end_define

begin_comment
comment|/* 0x00000400 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4319_LNLDO2_PU
value|12
end_define

begin_comment
comment|/* 0x00001000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4319_XTAL_PU
value|13
end_define

begin_comment
comment|/* 0x00002000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4319_ALP_AVAIL
value|14
end_define

begin_comment
comment|/* 0x00004000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4319_RX_PWRSW_PU
value|15
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4319_TX_PWRSW_PU
value|16
end_define

begin_comment
comment|/* 0x00010000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4319_RFPLL_PWRSW_PU
value|17
end_define

begin_comment
comment|/* 0x00020000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4319_LOGEN_PWRSW_PU
value|18
end_define

begin_comment
comment|/* 0x00040000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4319_AFE_PWRSW_PU
value|19
end_define

begin_comment
comment|/* 0x00080000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4319_BBPLL_PWRSW_PU
value|20
end_define

begin_comment
comment|/* 0x00100000 */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4319_HT_AVAIL
value|21
end_define

begin_comment
comment|/* 0x00200000 */
end_comment

begin_comment
comment|/* 4319 chip-specific CHIPCTL register bits */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_CHIPCTL0
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_CHIPCTL1
value|1
end_define

begin_define
define|#
directive|define
name|BHND_PMU1_PLL0_CHIPCTL2
value|2
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CCTRL4319USB_XTAL_SEL_MASK
value|0x00180000
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CCTRL4319USB_XTAL_SEL_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CCTRL4319USB_48MHZ_PLL_SEL
value|1
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CCTRL4319USB_24MHZ_PLL_SEL
value|2
end_define

begin_comment
comment|/* 4336 PMU resources  */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_CBUCK_LPOM
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_CBUCK_BURST
value|1
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_CBUCK_LP_PWM
value|2
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_CBUCK_PWM
value|3
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_CLDO_PU
value|4
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_DIS_INT_RESET_PD
value|5
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_ILP_REQUEST
value|6
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_LNLDO_PU
value|7
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_LDO3P3_PU
value|8
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_OTP_PU
value|9
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_XTAL_PU
value|10
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_ALP_AVAIL
value|11
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_RADIO_PU
value|12
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_BG_PU
value|13
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_VREG1p4_PU_PU
value|14
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_AFE_PWRSW_PU
value|15
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_RX_PWRSW_PU
value|16
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_TX_PWRSW_PU
value|17
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_BB_PWRSW_PU
value|18
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_SYNTH_PWRSW_PU
value|19
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_MISC_PWRSW_PU
value|20
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_LOGEN_PWRSW_PU
value|21
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_BBPLL_PWRSW_PU
value|22
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_MACPHY_CLKAVAIL
value|23
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_HT_AVAIL
value|24
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4336_RSVD
value|25
end_define

begin_comment
comment|/* 4330 resources */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_CBUCK_LPOM
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_CBUCK_BURST
value|1
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_CBUCK_LP_PWM
value|2
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_CBUCK_PWM
value|3
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_CLDO_PU
value|4
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_DIS_INT_RESET_PD
value|5
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_ILP_REQUEST
value|6
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_LNLDO_PU
value|7
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_LDO3P3_PU
value|8
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_OTP_PU
value|9
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_XTAL_PU
value|10
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_ALP_AVAIL
value|11
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_RADIO_PU
value|12
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_BG_PU
value|13
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_VREG1p4_PU_PU
value|14
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_AFE_PWRSW_PU
value|15
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_RX_PWRSW_PU
value|16
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_TX_PWRSW_PU
value|17
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_BB_PWRSW_PU
value|18
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_SYNTH_PWRSW_PU
value|19
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_MISC_PWRSW_PU
value|20
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_LOGEN_PWRSW_PU
value|21
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_BBPLL_PWRSW_PU
value|22
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_MACPHY_CLKAVAIL
value|23
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_HT_AVAIL
value|24
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_5gRX_PWRSW_PU
value|25
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_5gTX_PWRSW_PU
value|26
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4330_5g_LOGEN_PWRSW_PU
value|27
end_define

begin_comment
comment|/* 4313 resources */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES4313_BB_PU_RSRC
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4313_ILP_REQ_RSRC
value|1
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4313_XTAL_PU_RSRC
value|2
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4313_ALP_AVAIL_RSRC
value|3
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4313_RADIO_PU_RSRC
value|4
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4313_BG_PU_RSRC
value|5
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4313_VREG1P4_PU_RSRC
value|6
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4313_AFE_PWRSW_RSRC
value|7
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4313_RX_PWRSW_RSRC
value|8
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4313_TX_PWRSW_RSRC
value|9
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4313_BB_PWRSW_RSRC
value|10
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4313_SYNTH_PWRSW_RSRC
value|11
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4313_MISC_PWRSW_RSRC
value|12
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4313_BB_PLL_PWRSW_RSRC
value|13
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4313_HT_AVAIL_RSRC
value|14
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES4313_MACPHY_CLK_AVAIL_RSRC
value|15
end_define

begin_comment
comment|/* 4313 chip-specific CHIPCTRL register bits */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_CCTRL4313_12MA_LED_DRIVE
value|0x00000007
end_define

begin_comment
comment|/* 12 mA drive strengh for later 4313 */
end_comment

begin_comment
comment|/* 43228 resources */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_RES43228_NOT_USED
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES43228_ILP_REQUEST
value|1
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES43228_XTAL_PU
value|2
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES43228_ALP_AVAIL
value|3
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES43228_PLL_EN
value|4
end_define

begin_define
define|#
directive|define
name|BHND_PMU_RES43228_HT_PHY_AVAIL
value|5
end_define

begin_comment
comment|/* * Maximum delay for the PMU state transition in us. * This is an upper bound intended for spinwaits etc. */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_MAX_TRANSITION_DLY
value|15000
end_define

begin_comment
comment|/* PMU resource up transition time in ILP cycles */
end_comment

begin_define
define|#
directive|define
name|BHND_PMURES_UP_TRANSITION
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_CORES_PMU_BHND_PMUREG_H_ */
end_comment

end_unit

