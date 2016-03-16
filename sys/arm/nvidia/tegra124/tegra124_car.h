begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Michal Meloun<mmel@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TEGRA124_CAR_
end_ifndef

begin_define
define|#
directive|define
name|_TEGRA124_CAR_
end_define

begin_include
include|#
directive|include
file|"clkdev_if.h"
end_include

begin_define
define|#
directive|define
name|RD4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|CLKDEV_READ_4((sc)->clkdev, reg, val)
end_define

begin_define
define|#
directive|define
name|WR4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|CLKDEV_WRITE_4((sc)->clkdev, reg, val)
end_define

begin_define
define|#
directive|define
name|MD4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|mask
parameter_list|,
name|set
parameter_list|)
value|CLKDEV_MODIFY_4((sc)->clkdev, reg, mask, set)
end_define

begin_define
define|#
directive|define
name|DEVICE_LOCK
parameter_list|(
name|sc
parameter_list|)
value|CLKDEV_DEVICE_LOCK((sc)->clkdev)
end_define

begin_define
define|#
directive|define
name|DEVICE_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|CLKDEV_DEVICE_UNLOCK((sc)->clkdev)
end_define

begin_define
define|#
directive|define
name|RST_DEVICES_L
value|0x004
end_define

begin_define
define|#
directive|define
name|RST_DEVICES_H
value|0x008
end_define

begin_define
define|#
directive|define
name|RST_DEVICES_U
value|0x00C
end_define

begin_define
define|#
directive|define
name|CLK_OUT_ENB_L
value|0x010
end_define

begin_define
define|#
directive|define
name|CLK_OUT_ENB_H
value|0x014
end_define

begin_define
define|#
directive|define
name|CLK_OUT_ENB_U
value|0x018
end_define

begin_define
define|#
directive|define
name|CCLK_BURST_POLICY
value|0x020
end_define

begin_define
define|#
directive|define
name|SUPER_CCLK_DIVIDER
value|0x024
end_define

begin_define
define|#
directive|define
name|SCLK_BURST_POLICY
value|0x028
end_define

begin_define
define|#
directive|define
name|SUPER_SCLK_DIVIDER
value|0x02c
end_define

begin_define
define|#
directive|define
name|CLK_SYSTEM_RATE
value|0x030
end_define

begin_define
define|#
directive|define
name|OSC_CTRL
value|0x050
end_define

begin_define
define|#
directive|define
name|OSC_CTRL_OSC_FREQ_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|OSC_CTRL_PLL_REF_DIV_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|PLLE_SS_CNTL
value|0x068
end_define

begin_define
define|#
directive|define
name|PLLE_SS_CNTL_SSCINCINTRV_MASK
value|(0x3f<< 24)
end_define

begin_define
define|#
directive|define
name|PLLE_SS_CNTL_SSCINCINTRV_VAL
value|(0x20<< 24)
end_define

begin_define
define|#
directive|define
name|PLLE_SS_CNTL_SSCINC_MASK
value|(0xff<< 16)
end_define

begin_define
define|#
directive|define
name|PLLE_SS_CNTL_SSCINC_VAL
value|(0x1<< 16)
end_define

begin_define
define|#
directive|define
name|PLLE_SS_CNTL_SSCINVERT
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|PLLE_SS_CNTL_SSCCENTER
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|PLLE_SS_CNTL_SSCBYP
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|PLLE_SS_CNTL_INTERP_RESET
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|PLLE_SS_CNTL_BYPASS_SS
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|PLLE_SS_CNTL_SSCMAX_MASK
value|0x1ff
end_define

begin_define
define|#
directive|define
name|PLLE_SS_CNTL_SSCMAX_VAL
value|0x25
end_define

begin_define
define|#
directive|define
name|PLLE_SS_CNTL_DISABLE
value|(PLLE_SS_CNTL_BYPASS_SS |    \ 						 PLLE_SS_CNTL_INTERP_RESET | \ 						 PLLE_SS_CNTL_SSCBYP)
end_define

begin_define
define|#
directive|define
name|PLLE_SS_CNTL_COEFFICIENTS_MASK
value|(PLLE_SS_CNTL_SSCMAX_MASK |  \ 						 PLLE_SS_CNTL_SSCINC_MASK |  \ 						 PLLE_SS_CNTL_SSCINCINTRV_MASK)
end_define

begin_define
define|#
directive|define
name|PLLE_SS_CNTL_COEFFICIENTS_VAL
value|(PLLE_SS_CNTL_SSCMAX_VAL |   \ 						 PLLE_SS_CNTL_SSCINC_VAL |   \ 						 PLLE_SS_CNTL_SSCINCINTRV_VAL)
end_define

begin_define
define|#
directive|define
name|PLLC_BASE
value|0x080
end_define

begin_define
define|#
directive|define
name|PLLC_OUT
value|0x084
end_define

begin_define
define|#
directive|define
name|PLLC_MISC2
value|0x088
end_define

begin_define
define|#
directive|define
name|PLLC_MISC
value|0x08c
end_define

begin_define
define|#
directive|define
name|PLLM_BASE
value|0x090
end_define

begin_define
define|#
directive|define
name|PLLM_OUT
value|0x094
end_define

begin_define
define|#
directive|define
name|PLLM_MISC
value|0x09c
end_define

begin_define
define|#
directive|define
name|PLLP_BASE
value|0x0a0
end_define

begin_define
define|#
directive|define
name|PLLP_MISC
value|0x0ac
end_define

begin_define
define|#
directive|define
name|PLLP_OUTA
value|0x0a4
end_define

begin_define
define|#
directive|define
name|PLLP_OUTB
value|0x0a8
end_define

begin_define
define|#
directive|define
name|PLLA_BASE
value|0x0b0
end_define

begin_define
define|#
directive|define
name|PLLA_OUT
value|0x0b4
end_define

begin_define
define|#
directive|define
name|PLLA_MISC
value|0x0bc
end_define

begin_define
define|#
directive|define
name|PLLU_BASE
value|0x0c0
end_define

begin_define
define|#
directive|define
name|PLLU_MISC
value|0x0cc
end_define

begin_define
define|#
directive|define
name|PLLD_BASE
value|0x0d0
end_define

begin_define
define|#
directive|define
name|PLLD_MISC
value|0x0dc
end_define

begin_define
define|#
directive|define
name|PLLX_BASE
value|0x0e0
end_define

begin_define
define|#
directive|define
name|PLLX_MISC
value|0x0e4
end_define

begin_define
define|#
directive|define
name|PLLE_BASE
value|0x0e8
end_define

begin_define
define|#
directive|define
name|PLLE_BASE_LOCK_OVERRIDE
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|PLLE_BASE_DIVCML_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|PLLE_BASE_DIVCML_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|PLLE_MISC
value|0x0ec
end_define

begin_define
define|#
directive|define
name|PLLE_MISC_SETUP_BASE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PLLE_MISC_SETUP_BASE_MASK
value|(0xffff<< PLLE_MISC_SETUP_BASE_SHIFT)
end_define

begin_define
define|#
directive|define
name|PLLE_MISC_READY
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|PLLE_MISC_IDDQ_SWCTL
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|PLLE_MISC_IDDQ_OVERRIDE_VALUE
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|PLLE_MISC_LOCK
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|PLLE_MISC_REF_ENABLE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|PLLE_MISC_LOCK_ENABLE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|PLLE_MISC_PTS
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|PLLE_MISC_VREG_BG_CTRL_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|PLLE_MISC_VREG_BG_CTRL_MASK
value|(3<< PLLE_MISC_VREG_BG_CTRL_SHIFT)
end_define

begin_define
define|#
directive|define
name|PLLE_MISC_VREG_CTRL_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|PLLE_MISC_VREG_CTRL_MASK
value|(2<< PLLE_MISC_VREG_CTRL_SHIFT)
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_I2S1
value|0x100
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_I2S2
value|0x104
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_SPDIF_OUT
value|0x108
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_SPDIF_IN
value|0x10c
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_PWM
value|0x110
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_SPI2
value|0x118
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_SPI3
value|0x11c
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_I2C1
value|0x124
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_I2C5
value|0x128
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_SPI1
value|0x134
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_DISP1
value|0x138
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_DISP2
value|0x13c
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_ISP
value|0x144
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_VI
value|0x148
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_SDMMC1
value|0x150
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_SDMMC2
value|0x154
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_SDMMC4
value|0x164
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_VFIR
value|0x168
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_HSI
value|0x174
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_UARTA
value|0x178
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_UARTB
value|0x17c
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_HOST1X
value|0x180
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_HDMI
value|0x18c
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_I2C2
value|0x198
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_EMC
value|0x19c
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_UARTC
value|0x1a0
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_VI_SENSOR
value|0x1a8
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_SPI4
value|0x1b4
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_I2C3
value|0x1b8
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_SDMMC3
value|0x1bc
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_UARTD
value|0x1c0
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_VDE
value|0x1c8
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_OWR
value|0x1cc
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_NOR
value|0x1d0
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_CSITE
value|0x1d4
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_I2S0
value|0x1d8
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_DTV
value|0x1dc
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_MSENC
value|0x1f0
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_TSEC
value|0x1f4
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_SPARE2
value|0x1f8
end_define

begin_define
define|#
directive|define
name|CLK_OUT_ENB_X
value|0x280
end_define

begin_define
define|#
directive|define
name|RST_DEVICES_X
value|0x28C
end_define

begin_define
define|#
directive|define
name|RST_DEVICES_V
value|0x358
end_define

begin_define
define|#
directive|define
name|RST_DEVICES_W
value|0x35C
end_define

begin_define
define|#
directive|define
name|CLK_OUT_ENB_V
value|0x360
end_define

begin_define
define|#
directive|define
name|CLK_OUT_ENB_W
value|0x364
end_define

begin_define
define|#
directive|define
name|CCLKG_BURST_POLICY
value|0x368
end_define

begin_define
define|#
directive|define
name|SUPER_CCLKG_DIVIDER
value|0x36C
end_define

begin_define
define|#
directive|define
name|CCLKLP_BURST_POLICY
value|0x370
end_define

begin_define
define|#
directive|define
name|SUPER_CCLKLP_DIVIDER
value|0x374
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_MSELECT
value|0x3b4
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_TSENSOR
value|0x3b8
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_I2S3
value|0x3bc
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_I2S4
value|0x3c0
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_I2C4
value|0x3c4
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_SPI5
value|0x3c8
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_SPI6
value|0x3cc
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_AUDIO
value|0x3d0
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_DAM0
value|0x3d8
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_DAM1
value|0x3dc
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_DAM2
value|0x3e0
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_HDA2CODEC_2X
value|0x3e4
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_ACTMON
value|0x3e8
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_EXTPERIPH1
value|0x3ec
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_EXTPERIPH2
value|0x3f0
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_EXTPERIPH3
value|0x3f4
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_I2C_SLOW
value|0x3fc
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_SYS
value|0x400
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_SOR0
value|0x414
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_SATA_OOB
value|0x420
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_SATA
value|0x424
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_HDA
value|0x428
end_define

begin_define
define|#
directive|define
name|UTMIP_PLL_CFG0
value|0x480
end_define

begin_define
define|#
directive|define
name|UTMIP_PLL_CFG1
value|0x484
end_define

begin_define
define|#
directive|define
name|UTMIP_PLL_CFG1_FORCE_PLLU_POWERUP
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|UTMIP_PLL_CFG1_FORCE_PLLU_POWERDOWN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|UTMIP_PLL_CFG1_FORCE_PLL_ENABLE_POWERUP
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|UTMIP_PLL_CFG1_FORCE_PLL_ENABLE_POWERDOWN
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|UTMIP_PLL_CFG1_FORCE_PLL_ACTIVE_POWERDOWN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|UTMIP_PLL_CFG1_ENABLE_DLY_COUNT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1f)<< 6)
end_define

begin_define
define|#
directive|define
name|UTMIP_PLL_CFG1_XTAL_FREQ_COUNT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xfff)<< 0)
end_define

begin_define
define|#
directive|define
name|UTMIP_PLL_CFG2
value|0x488
end_define

begin_define
define|#
directive|define
name|UTMIP_PLL_CFG2_ACTIVE_DLY_COUNT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3f)<< 18)
end_define

begin_define
define|#
directive|define
name|UTMIP_PLL_CFG2_STABLE_COUNT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffff)<< 6)
end_define

begin_define
define|#
directive|define
name|UTMIP_PLL_CFG2_FORCE_PD_SAMP_C_POWERDOWN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|UTMIP_PLL_CFG2_FORCE_PD_SAMP_B_POWERDOWN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|UTMIP_PLL_CFG2_FORCE_PD_SAMP_A_POWERDOWN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PLLE_AUX
value|0x48c
end_define

begin_define
define|#
directive|define
name|PLLE_AUX_PLLRE_SEL
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|PLLE_AUX_SEQ_START_STATE
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|PLLE_AUX_SEQ_ENABLE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|PLLE_AUX_SS_SWCTL
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|PLLE_AUX_ENABLE_SWCTL
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|PLLE_AUX_USE_LOCKDET
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|PLLE_AUX_PLLP_SEL
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SATA_PLL_CFG0
value|0x490
end_define

begin_define
define|#
directive|define
name|SATA_PLL_CFG0_SEQ_START_STATE
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|SATA_PLL_CFG0_SEQ_ENABLE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|SATA_PLL_CFG0_SEQ_PADPLL_PD_INPUT_VALUE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SATA_PLL_CFG0_SEQ_LANE_PD_INPUT_VALUE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SATA_PLL_CFG0_SEQ_RESET_INPUT_VALUE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SATA_PLL_CFG0_SEQ_IN_SWCTL
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SATA_PLL_CFG0_PADPLL_USE_LOCKDET
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SATA_PLL_CFG0_PADPLL_RESET_OVERRIDE_VALUE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SATA_PLL_CFG0_PADPLL_RESET_SWCTL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SATA_PLL_CFG1
value|0x494
end_define

begin_define
define|#
directive|define
name|PCIE_PLL_CFG0
value|0x498
end_define

begin_define
define|#
directive|define
name|PCIE_PLL_CFG0_SEQ_START_STATE
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|PCIE_PLL_CFG0_SEQ_ENABLE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|PLLD2_BASE
value|0x4b8
end_define

begin_define
define|#
directive|define
name|PLLD2_MISC
value|0x4bc
end_define

begin_define
define|#
directive|define
name|UTMIP_PLL_CFG3
value|0x4c0
end_define

begin_define
define|#
directive|define
name|PLLRE_BASE
value|0x4c4
end_define

begin_define
define|#
directive|define
name|PLLRE_MISC
value|0x4c8
end_define

begin_define
define|#
directive|define
name|PLLC2_BASE
value|0x4e8
end_define

begin_define
define|#
directive|define
name|PLLC2_MISC
value|0x4ec
end_define

begin_define
define|#
directive|define
name|PLLC3_BASE
value|0x4fc
end_define

begin_define
define|#
directive|define
name|PLLC3_MISC
value|0x500
end_define

begin_define
define|#
directive|define
name|PLLX_MISC2
value|0x514
end_define

begin_define
define|#
directive|define
name|PLLX_MISC2
value|0x514
end_define

begin_define
define|#
directive|define
name|PLLX_MISC3
value|0x518
end_define

begin_define
define|#
directive|define
name|PLLX_MISC3_DYNRAMP_STEPB_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|PLLX_MISC3_DYNRAMP_STEPB_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|PLLX_MISC3_DYNRAMP_STEPA_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|PLLX_MISC3_DYNRAMP_STEPA_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PLLX_MISC3_NDIV_NEW_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|PLLX_MISC3_NDIV_NEW_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PLLX_MISC3_EN_FSTLCK
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|PLLX_MISC3_LOCK_OVERRIDE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|PLLX_MISC3_PLL_FREQLOCK
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|PLLX_MISC3_DYNRAMP_DONE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|PLLX_MISC3_CLAMP_NDIV
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|PLLX_MISC3_EN_DYNRAMP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|XUSBIO_PLL_CFG0
value|0x51c
end_define

begin_define
define|#
directive|define
name|XUSBIO_PLL_CFG0_SEQ_START_STATE
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|XUSBIO_PLL_CFG0_SEQ_ENABLE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|XUSBIO_PLL_CFG0_PADPLL_USE_LOCKDET
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|XUSBIO_PLL_CFG0_CLK_ENABLE_SWCTL
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|XUSBIO_PLL_CFG0_PADPLL_RESET_SWCTL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PLLP_RESHIFT
value|0x528
end_define

begin_define
define|#
directive|define
name|UTMIPLL_HW_PWRDN_CFG0
value|0x52c
end_define

begin_define
define|#
directive|define
name|UTMIPLL_HW_PWRDN_CFG0_SEQ_START_STATE
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|UTMIPLL_HW_PWRDN_CFG0_SEQ_ENABLE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|UTMIPLL_HW_PWRDN_CFG0_USE_LOCKDET
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|UTMIPLL_HW_PWRDN_CFG0_SEQ_RESET_INPUT_VALUE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|UTMIPLL_HW_PWRDN_CFG0_SEQ_IN_SWCTL
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|UTMIPLL_HW_PWRDN_CFG0_CLK_ENABLE_SWCTL
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|UTMIPLL_HW_PWRDN_CFG0_IDDQ_OVERRIDE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|UTMIPLL_HW_PWRDN_CFG0_IDDQ_SWCTL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PLLDP_BASE
value|0x590
end_define

begin_define
define|#
directive|define
name|PLLDP_MISC
value|0x594
end_define

begin_define
define|#
directive|define
name|PLLC4_BASE
value|0x5a4
end_define

begin_define
define|#
directive|define
name|PLLC4_MISC
value|0x5a8
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_XUSB_CORE_HOST
value|0x600
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_XUSB_FALCON
value|0x604
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_XUSB_FS
value|0x608
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_XUSB_CORE_DEV
value|0x60c
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_XUSB_SS
value|0x610
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_CILAB
value|0x614
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_CILCD
value|0x618
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_CILE
value|0x61c
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_DSIA_LP
value|0x620
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_DSIB_LP
value|0x624
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_ENTROPY
value|0x628
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_DVFS_REF
value|0x62c
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_DVFS_SOC
value|0x630
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_TRACECLKIN
value|0x634
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_ADX
value|0x638
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_AMX
value|0x63c
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_EMC_LATENCY
value|0x640
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_SOC_THERM
value|0x644
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_VI_SENSOR2
value|0x658
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_I2C6
value|0x65c
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_EMC_DLL
value|0x664
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_HDMI_AUDIO
value|0x668
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_CLK72MHZ
value|0x66c
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_ADX1
value|0x670
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_AMX1
value|0x674
end_define

begin_define
define|#
directive|define
name|CLK_SOURCE_VIC
value|0x678
end_define

begin_define
define|#
directive|define
name|PLLP_OUTC
value|0x67c
end_define

begin_define
define|#
directive|define
name|PLLP_MISC1
value|0x680
end_define

begin_struct
struct|struct
name|tegra124_car_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|mem_res
decl_stmt|;
name|struct
name|mtx
name|mtx
decl_stmt|;
name|struct
name|clkdom
modifier|*
name|clkdom
decl_stmt|;
name|int
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tegra124_init_item
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|parent
decl_stmt|;
name|uint64_t
name|frequency
decl_stmt|;
name|int
name|enable
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|tegra124_init_plls
parameter_list|(
name|struct
name|tegra124_car_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tegra124_periph_clock
parameter_list|(
name|struct
name|tegra124_car_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tegra124_super_mux_clock
parameter_list|(
name|struct
name|tegra124_car_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tegra124_hwreset_by_idx
parameter_list|(
name|struct
name|tegra124_car_softc
modifier|*
name|sc
parameter_list|,
name|intptr_t
name|idx
parameter_list|,
name|bool
name|reset
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_TEGRA124_CAR_*/
end_comment

end_unit

