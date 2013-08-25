begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008 Advanced Micro Devices, Inc.  * Copyright 2008 Red Hat Inc.  * Copyright 2009 Jerome Glisse.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors: Dave Airlie  *          Alex Deucher  *          Jerome Glisse  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__R600_REG_H__
end_ifndef

begin_define
define|#
directive|define
name|__R600_REG_H__
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|R600_PCIE_PORT_INDEX
value|0x0038
end_define

begin_define
define|#
directive|define
name|R600_PCIE_PORT_DATA
value|0x003c
end_define

begin_define
define|#
directive|define
name|R600_MC_VM_FB_LOCATION
value|0x2180
end_define

begin_define
define|#
directive|define
name|R600_MC_FB_BASE_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|R600_MC_FB_BASE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R600_MC_FB_TOP_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|R600_MC_FB_TOP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|R600_MC_VM_AGP_TOP
value|0x2184
end_define

begin_define
define|#
directive|define
name|R600_MC_AGP_TOP_MASK
value|0x0003FFFF
end_define

begin_define
define|#
directive|define
name|R600_MC_AGP_TOP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R600_MC_VM_AGP_BOT
value|0x2188
end_define

begin_define
define|#
directive|define
name|R600_MC_AGP_BOT_MASK
value|0x0003FFFF
end_define

begin_define
define|#
directive|define
name|R600_MC_AGP_BOT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R600_MC_VM_AGP_BASE
value|0x218c
end_define

begin_define
define|#
directive|define
name|R600_MC_VM_SYSTEM_APERTURE_LOW_ADDR
value|0x2190
end_define

begin_define
define|#
directive|define
name|R600_LOGICAL_PAGE_NUMBER_MASK
value|0x000FFFFF
end_define

begin_define
define|#
directive|define
name|R600_LOGICAL_PAGE_NUMBER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R600_MC_VM_SYSTEM_APERTURE_HIGH_ADDR
value|0x2194
end_define

begin_define
define|#
directive|define
name|R600_MC_VM_SYSTEM_APERTURE_DEFAULT_ADDR
value|0x2198
end_define

begin_define
define|#
directive|define
name|R700_MC_VM_FB_LOCATION
value|0x2024
end_define

begin_define
define|#
directive|define
name|R700_MC_FB_BASE_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|R700_MC_FB_BASE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R700_MC_FB_TOP_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|R700_MC_FB_TOP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|R700_MC_VM_AGP_TOP
value|0x2028
end_define

begin_define
define|#
directive|define
name|R700_MC_AGP_TOP_MASK
value|0x0003FFFF
end_define

begin_define
define|#
directive|define
name|R700_MC_AGP_TOP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R700_MC_VM_AGP_BOT
value|0x202c
end_define

begin_define
define|#
directive|define
name|R700_MC_AGP_BOT_MASK
value|0x0003FFFF
end_define

begin_define
define|#
directive|define
name|R700_MC_AGP_BOT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R700_MC_VM_AGP_BASE
value|0x2030
end_define

begin_define
define|#
directive|define
name|R700_MC_VM_SYSTEM_APERTURE_LOW_ADDR
value|0x2034
end_define

begin_define
define|#
directive|define
name|R700_LOGICAL_PAGE_NUMBER_MASK
value|0x000FFFFF
end_define

begin_define
define|#
directive|define
name|R700_LOGICAL_PAGE_NUMBER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R700_MC_VM_SYSTEM_APERTURE_HIGH_ADDR
value|0x2038
end_define

begin_define
define|#
directive|define
name|R700_MC_VM_SYSTEM_APERTURE_DEFAULT_ADDR
value|0x203c
end_define

begin_define
define|#
directive|define
name|R600_RAMCFG
value|0x2408
end_define

begin_define
define|#
directive|define
name|R600_CHANSIZE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|R600_CHANSIZE_OVERRIDE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|R600_GENERAL_PWRMGT
value|0x618
end_define

begin_define
define|#
directive|define
name|R600_OPEN_DRAIN_PADS
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|R600_LOWER_GPIO_ENABLE
value|0x710
end_define

begin_define
define|#
directive|define
name|R600_CTXSW_VID_LOWER_GPIO_CNTL
value|0x718
end_define

begin_define
define|#
directive|define
name|R600_HIGH_VID_LOWER_GPIO_CNTL
value|0x71c
end_define

begin_define
define|#
directive|define
name|R600_MEDIUM_VID_LOWER_GPIO_CNTL
value|0x720
end_define

begin_define
define|#
directive|define
name|R600_LOW_VID_LOWER_GPIO_CNTL
value|0x724
end_define

begin_define
define|#
directive|define
name|R600_D1GRPH_SWAP_CONTROL
value|0x610C
end_define

begin_define
define|#
directive|define
name|R600_D1GRPH_SWAP_ENDIAN_NONE
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|R600_D1GRPH_SWAP_ENDIAN_16BIT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R600_D1GRPH_SWAP_ENDIAN_32BIT
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|R600_D1GRPH_SWAP_ENDIAN_64BIT
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|R600_HDP_NONSURFACE_BASE
value|0x2c04
end_define

begin_define
define|#
directive|define
name|R600_BUS_CNTL
value|0x5420
end_define

begin_define
define|#
directive|define
name|R600_BIOS_ROM_DIS
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|R600_CONFIG_CNTL
value|0x5424
end_define

begin_define
define|#
directive|define
name|R600_CONFIG_MEMSIZE
value|0x5428
end_define

begin_define
define|#
directive|define
name|R600_CONFIG_F0_BASE
value|0x542C
end_define

begin_define
define|#
directive|define
name|R600_CONFIG_APER_SIZE
value|0x5430
end_define

begin_define
define|#
directive|define
name|R600_BIF_FB_EN
value|0x5490
end_define

begin_define
define|#
directive|define
name|R600_FB_READ_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R600_FB_WRITE_EN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|R600_CITF_CNTL
value|0x200c
end_define

begin_define
define|#
directive|define
name|R600_BLACKOUT_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|R700_MC_CITF_CNTL
value|0x25c0
end_define

begin_define
define|#
directive|define
name|R600_ROM_CNTL
value|0x1600
end_define

begin_define
define|#
directive|define
name|R600_SCK_OVERWRITE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|R600_SCK_PRESCALE_CRYSTAL_CLK_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|R600_SCK_PRESCALE_CRYSTAL_CLK_MASK
value|(0xf<< 28)
end_define

begin_define
define|#
directive|define
name|R600_CG_SPLL_FUNC_CNTL
value|0x600
end_define

begin_define
define|#
directive|define
name|R600_SPLL_BYPASS_EN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|R600_CG_SPLL_STATUS
value|0x60c
end_define

begin_define
define|#
directive|define
name|R600_SPLL_CHG_STATUS
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|R600_BIOS_0_SCRATCH
value|0x1724
end_define

begin_define
define|#
directive|define
name|R600_BIOS_1_SCRATCH
value|0x1728
end_define

begin_define
define|#
directive|define
name|R600_BIOS_2_SCRATCH
value|0x172c
end_define

begin_define
define|#
directive|define
name|R600_BIOS_3_SCRATCH
value|0x1730
end_define

begin_define
define|#
directive|define
name|R600_BIOS_4_SCRATCH
value|0x1734
end_define

begin_define
define|#
directive|define
name|R600_BIOS_5_SCRATCH
value|0x1738
end_define

begin_define
define|#
directive|define
name|R600_BIOS_6_SCRATCH
value|0x173c
end_define

begin_define
define|#
directive|define
name|R600_BIOS_7_SCRATCH
value|0x1740
end_define

begin_comment
comment|/* Audio, these regs were reverse enginered,  * so the chance is high that the naming is wrong  * R6xx+ ??? */
end_comment

begin_comment
comment|/* Audio clocks */
end_comment

begin_define
define|#
directive|define
name|R600_AUDIO_PLL1_MUL
value|0x0514
end_define

begin_define
define|#
directive|define
name|R600_AUDIO_PLL1_DIV
value|0x0518
end_define

begin_define
define|#
directive|define
name|R600_AUDIO_PLL2_MUL
value|0x0524
end_define

begin_define
define|#
directive|define
name|R600_AUDIO_PLL2_DIV
value|0x0528
end_define

begin_define
define|#
directive|define
name|R600_AUDIO_CLK_SRCSEL
value|0x0534
end_define

begin_comment
comment|/* Audio general */
end_comment

begin_define
define|#
directive|define
name|R600_AUDIO_ENABLE
value|0x7300
end_define

begin_define
define|#
directive|define
name|R600_AUDIO_TIMING
value|0x7344
end_define

begin_comment
comment|/* Audio params */
end_comment

begin_define
define|#
directive|define
name|R600_AUDIO_VENDOR_ID
value|0x7380
end_define

begin_define
define|#
directive|define
name|R600_AUDIO_REVISION_ID
value|0x7384
end_define

begin_define
define|#
directive|define
name|R600_AUDIO_ROOT_NODE_COUNT
value|0x7388
end_define

begin_define
define|#
directive|define
name|R600_AUDIO_NID1_NODE_COUNT
value|0x738c
end_define

begin_define
define|#
directive|define
name|R600_AUDIO_NID1_TYPE
value|0x7390
end_define

begin_define
define|#
directive|define
name|R600_AUDIO_SUPPORTED_SIZE_RATE
value|0x7394
end_define

begin_define
define|#
directive|define
name|R600_AUDIO_SUPPORTED_CODEC
value|0x7398
end_define

begin_define
define|#
directive|define
name|R600_AUDIO_SUPPORTED_POWER_STATES
value|0x739c
end_define

begin_define
define|#
directive|define
name|R600_AUDIO_NID2_CAPS
value|0x73a0
end_define

begin_define
define|#
directive|define
name|R600_AUDIO_NID3_CAPS
value|0x73a4
end_define

begin_define
define|#
directive|define
name|R600_AUDIO_NID3_PIN_CAPS
value|0x73a8
end_define

begin_comment
comment|/* Audio conn list */
end_comment

begin_define
define|#
directive|define
name|R600_AUDIO_CONN_LIST_LEN
value|0x73ac
end_define

begin_define
define|#
directive|define
name|R600_AUDIO_CONN_LIST
value|0x73b0
end_define

begin_comment
comment|/* Audio verbs */
end_comment

begin_define
define|#
directive|define
name|R600_AUDIO_RATE_BPS_CHANNEL
value|0x73c0
end_define

begin_define
define|#
directive|define
name|R600_AUDIO_PLAYING
value|0x73c4
end_define

begin_define
define|#
directive|define
name|R600_AUDIO_IMPLEMENTATION_ID
value|0x73c8
end_define

begin_define
define|#
directive|define
name|R600_AUDIO_CONFIG_DEFAULT
value|0x73cc
end_define

begin_define
define|#
directive|define
name|R600_AUDIO_PIN_SENSE
value|0x73d0
end_define

begin_define
define|#
directive|define
name|R600_AUDIO_PIN_WIDGET_CNTL
value|0x73d4
end_define

begin_define
define|#
directive|define
name|R600_AUDIO_STATUS_BITS
value|0x73d8
end_define

begin_define
define|#
directive|define
name|DCE2_HDMI_OFFSET0
value|(0x7400 - 0x7400)
end_define

begin_define
define|#
directive|define
name|DCE2_HDMI_OFFSET1
value|(0x7700 - 0x7400)
end_define

begin_comment
comment|/* DCE3.2 second instance starts at 0x7800 */
end_comment

begin_define
define|#
directive|define
name|DCE3_HDMI_OFFSET0
value|(0x7400 - 0x7400)
end_define

begin_define
define|#
directive|define
name|DCE3_HDMI_OFFSET1
value|(0x7800 - 0x7400)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

