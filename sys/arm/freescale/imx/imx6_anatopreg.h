begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ian Lepore<ian@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IMX6_ANATOPREG_H
end_ifndef

begin_define
define|#
directive|define
name|IMX6_ANATOPREG_H
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_ARM
value|0x000
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_ARM_SET
value|0x004
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_ARM_CLR
value|0x008
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_ARM_TOG
value|0x00C
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_ARM_DIV_MASK
value|0x7F
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_ARM_LOCK
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_ARM_BYPASS
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_ARM_CLK_SRC_MASK
value|(0x03<< 16)
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_USB1
value|0x010
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_USB1_SET
value|0x014
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_USB1_CLR
value|0x018
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_USB1_TOG
value|0x01C
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_USB_LOCK
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_USB_BYPASS
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_USB_ENABLE
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_USB_POWER
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_USB_EN_USB_CLKS
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_USB2
value|0x020
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_USB2_SET
value|0x024
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_USB2_CLR
value|0x028
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_USB2_TOG
value|0x02C
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_SYS
value|0x030
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_SYS_SET
value|0x034
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_SYS_CLR
value|0x038
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_SYS_TOG
value|0x03C
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_SYS_SS
value|0x040
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_SYS_NUM
value|0x050
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_SYS_DENOM
value|0x060
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_AUDIO
value|0x070
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_AUDIO_SET
value|0x074
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_AUDIO_CLR
value|0x078
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_AUDIO_TOG
value|0x07C
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_AUDIO_NUM
value|0x080
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_AUDIO_DENOM
value|0x090
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_VIDEO
value|0x0A0
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_VIDEO_SET
value|0x0A4
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_VIDEO_CLR
value|0x0A8
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_VIDEO_TOG
value|0x0AC
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_VIDEO_NUM
value|0x0B0
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_VIDEO_DENOM
value|0x0C0
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_MLB
value|0x0D0
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_MLB_SET
value|0x0D4
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_MLB_CLR
value|0x0D8
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_MLB_TOG
value|0x0DC
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_ENET
value|0x0E0
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_ENET_SET
value|0x0E4
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_ENET_CLR
value|0x0E8
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PLL_ENET_TOG
value|0x0EC
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PFD_480
value|0x0F0
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PFD_480_SET
value|0x0F4
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PFD_480_CLR
value|0x0F8
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PFD_480_TOG
value|0x0FC
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PFD_528
value|0x100
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PFD_528_SET
value|0x104
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PFD_528_CLR
value|0x108
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_PFD_528_TOG
value|0x10C
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_PMU_REG_CORE
value|0x140
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_PMU_REG2_TARG_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_PMU_REG2_TARG_MASK
define|\
value|(0x1f<< IMX6_ANALOG_PMU_REG2_TARG_SHIFT)
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_PMU_REG1_TARG_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_PMU_REG1_TARG_MASK
define|\
value|(0x1f<< IMX6_ANALOG_PMU_REG1_TARG_SHIFT)
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_PMU_REG0_TARG_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_PMU_REG0_TARG_MASK
define|\
value|(0x1f<< IMX6_ANALOG_PMU_REG0_TARG_SHIFT)
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_PMU_MISC0
value|0x150
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_PMU_MISC0_SET
value|0x154
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_PMU_MISC0_CLR
value|0x158
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_PMU_MISC0_TOG
value|0x15C
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_PMU_MISC0_SELFBIASOFF
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_PMU_MISC1
value|0x160
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_PMU_MISC1_SET
value|0x164
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_PMU_MISC1_CLR
value|0x168
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_PMU_MISC1_TOG
value|0x16C
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_PMU_MISC1_IRQ_TEMPSENSE
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_PMU_MISC2
value|0x170
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_PMU_MISC2_SET
value|0x174
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_PMU_MISC2_CLR
value|0x178
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_PMU_MISC2_TOG
value|0x17C
end_define

begin_comment
comment|/*  * Note that the ANALOG_CCM_MISCn registers are the same as the PMU_MISCn  * registers; some bits conceptually belong to the PMU and some to the CCM.  */
end_comment

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_MISC0
value|IMX6_ANALOG_PMU_MISC0
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_MISC0_SET
value|IMX6_ANALOG_PMU_MISC0_SET
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_MISC0_CLR
value|IMX6_ANALOG_PMU_MISC0_CLR
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_MISC0_TOG
value|IMX6_ANALOG_PMU_MISC0_TOG
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_MISC2
value|IMX6_ANALOG_PMU_MISC2
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_MISC2_SET
value|IMX6_ANALOG_PMU_MISC2_SET
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_MISC2_CLR
value|IMX6_ANALOG_PMU_MISC2_CLR
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_CCM_MISC2_TOG
value|IMX6_ANALOG_PMU_MISC2_TOG
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_TEMPMON_TEMPSENSE0
value|0x180
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_TEMPMON_TEMPSENSE0_SET
value|0x184
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_TEMPMON_TEMPSENSE0_CLR
value|0x188
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_TEMPMON_TEMPSENSE0_TOG
value|0x18C
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_TEMPMON_TEMPSENSE0_TOG
value|0x18C
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_TEMPMON_TEMPSENSE0_ALARM_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_TEMPMON_TEMPSENSE0_ALARM_MASK
define|\
value|(0xfff<< IMX6_ANALOG_TEMPMON_TEMPSENSE0_ALARM_SHIFT)
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_TEMPMON_TEMPSENSE0_TEMP_CNT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_TEMPMON_TEMPSENSE0_TEMP_CNT_MASK
define|\
value|(0xfff<< IMX6_ANALOG_TEMPMON_TEMPSENSE0_TEMP_CNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_TEMPMON_TEMPSENSE0_VALID
value|0x4
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_TEMPMON_TEMPSENSE0_MEASURE
value|0x2
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_TEMPMON_TEMPSENSE0_POWER_DOWN
value|0x1
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_TEMPMON_TEMPSENSE1
value|0x190
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_TEMPMON_TEMPSENSE1_SET
value|0x194
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_TEMPMON_TEMPSENSE1_CLR
value|0x198
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_TEMPMON_TEMPSENSE1_TOG
value|0x19C
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB1_VBUS_DETECT
value|0x1A0
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB1_VBUS_DETECT_SET
value|0x1A4
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB1_VBUS_DETECT_CLR
value|0x1A8
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB1_VBUS_DETECT_TOG
value|0x1AC
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB1_CHRG_DETECT
value|0x1B0
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB1_CHRG_DETECT_SET
value|0x1B4
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB1_CHRG_DETECT_CLR
value|0x1B8
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB1_CHRG_DETECT_TOG
value|0x1BC
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB_CHRG_DETECT_N_ENABLE
value|(1<< 20)
end_define

begin_comment
comment|/* EN_B */
end_comment

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB_CHRG_DETECT_N_CHK_CHRG
value|(1<< 19)
end_define

begin_comment
comment|/* CHK_CHRG_B */
end_comment

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB_CHRG_DETECT_CHK_CONTACT
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB1_VBUS_DETECT_STAT
value|0x1C0
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB1_CHRG_DETECT_STAT
value|0x1D0
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB1_MISC
value|0x1F0
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB1_MISC_SET
value|0x1F4
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB1_MISC_CLR
value|0x1F8
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB1_MISC_TOG
value|0x1FC
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB2_VBUS_DETECT
value|0x200
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB2_VBUS_DETECT_SET
value|0x204
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB2_VBUS_DETECT_CLR
value|0x208
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB2_VBUS_DETECT_TOG
value|0x20C
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB2_CHRG_DETECT
value|0x210
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB2_CHRG_DETECT_SET
value|0x214
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB2_CHRG_DETECT_CLR
value|0x218
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB2_CHRG_DETECT_TOG
value|0x21C
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB2_VBUS_DETECT_STAT
value|0x220
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB2_CHRG_DETECT_STAT
value|0x230
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB2_MISC
value|0x250
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB2_MISC_SET
value|0x254
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB2_MISC_CLR
value|0x258
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_USB2_MISC_TOG
value|0x25C
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_DIGPROG
value|0x260
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_DIGPROG_SL
value|0x280
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_DIGPROG_SOCTYPE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IMX6_ANALOG_DIGPROG_SOCTYPE_MASK
define|\
value|(0xff<< IMX6_ANALOG_DIGPROG_SOCTYPE_SHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

