begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013, The Linux Foundation. All rights reserved.  *  * This software is licensed under the terms of the GNU General Public  * License version 2, as published by the Free Software Foundation, and  * may be copied, distributed, and modified under those terms.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_MSM_MMCC_8960_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_MSM_MMCC_8960_H
end_define

begin_define
define|#
directive|define
name|MMSS_AHB_SRC
value|0
end_define

begin_define
define|#
directive|define
name|FAB_AHB_CLK
value|1
end_define

begin_define
define|#
directive|define
name|APU_AHB_CLK
value|2
end_define

begin_define
define|#
directive|define
name|TV_ENC_AHB_CLK
value|3
end_define

begin_define
define|#
directive|define
name|AMP_AHB_CLK
value|4
end_define

begin_define
define|#
directive|define
name|DSI2_S_AHB_CLK
value|5
end_define

begin_define
define|#
directive|define
name|JPEGD_AHB_CLK
value|6
end_define

begin_define
define|#
directive|define
name|GFX2D0_AHB_CLK
value|7
end_define

begin_define
define|#
directive|define
name|DSI_S_AHB_CLK
value|8
end_define

begin_define
define|#
directive|define
name|DSI2_M_AHB_CLK
value|9
end_define

begin_define
define|#
directive|define
name|VPE_AHB_CLK
value|10
end_define

begin_define
define|#
directive|define
name|SMMU_AHB_CLK
value|11
end_define

begin_define
define|#
directive|define
name|HDMI_M_AHB_CLK
value|12
end_define

begin_define
define|#
directive|define
name|VFE_AHB_CLK
value|13
end_define

begin_define
define|#
directive|define
name|ROT_AHB_CLK
value|14
end_define

begin_define
define|#
directive|define
name|VCODEC_AHB_CLK
value|15
end_define

begin_define
define|#
directive|define
name|MDP_AHB_CLK
value|16
end_define

begin_define
define|#
directive|define
name|DSI_M_AHB_CLK
value|17
end_define

begin_define
define|#
directive|define
name|CSI_AHB_CLK
value|18
end_define

begin_define
define|#
directive|define
name|MMSS_IMEM_AHB_CLK
value|19
end_define

begin_define
define|#
directive|define
name|IJPEG_AHB_CLK
value|20
end_define

begin_define
define|#
directive|define
name|HDMI_S_AHB_CLK
value|21
end_define

begin_define
define|#
directive|define
name|GFX3D_AHB_CLK
value|22
end_define

begin_define
define|#
directive|define
name|GFX2D1_AHB_CLK
value|23
end_define

begin_define
define|#
directive|define
name|MMSS_FPB_CLK
value|24
end_define

begin_define
define|#
directive|define
name|MMSS_AXI_SRC
value|25
end_define

begin_define
define|#
directive|define
name|MMSS_FAB_CORE
value|26
end_define

begin_define
define|#
directive|define
name|FAB_MSP_AXI_CLK
value|27
end_define

begin_define
define|#
directive|define
name|JPEGD_AXI_CLK
value|28
end_define

begin_define
define|#
directive|define
name|GMEM_AXI_CLK
value|29
end_define

begin_define
define|#
directive|define
name|MDP_AXI_CLK
value|30
end_define

begin_define
define|#
directive|define
name|MMSS_IMEM_AXI_CLK
value|31
end_define

begin_define
define|#
directive|define
name|IJPEG_AXI_CLK
value|32
end_define

begin_define
define|#
directive|define
name|GFX3D_AXI_CLK
value|33
end_define

begin_define
define|#
directive|define
name|VCODEC_AXI_CLK
value|34
end_define

begin_define
define|#
directive|define
name|VFE_AXI_CLK
value|35
end_define

begin_define
define|#
directive|define
name|VPE_AXI_CLK
value|36
end_define

begin_define
define|#
directive|define
name|ROT_AXI_CLK
value|37
end_define

begin_define
define|#
directive|define
name|VCODEC_AXI_A_CLK
value|38
end_define

begin_define
define|#
directive|define
name|VCODEC_AXI_B_CLK
value|39
end_define

begin_define
define|#
directive|define
name|MM_AXI_S3_FCLK
value|40
end_define

begin_define
define|#
directive|define
name|MM_AXI_S2_FCLK
value|41
end_define

begin_define
define|#
directive|define
name|MM_AXI_S1_FCLK
value|42
end_define

begin_define
define|#
directive|define
name|MM_AXI_S0_FCLK
value|43
end_define

begin_define
define|#
directive|define
name|MM_AXI_S2_CLK
value|44
end_define

begin_define
define|#
directive|define
name|MM_AXI_S1_CLK
value|45
end_define

begin_define
define|#
directive|define
name|MM_AXI_S0_CLK
value|46
end_define

begin_define
define|#
directive|define
name|CSI0_SRC
value|47
end_define

begin_define
define|#
directive|define
name|CSI0_CLK
value|48
end_define

begin_define
define|#
directive|define
name|CSI0_PHY_CLK
value|49
end_define

begin_define
define|#
directive|define
name|CSI1_SRC
value|50
end_define

begin_define
define|#
directive|define
name|CSI1_CLK
value|51
end_define

begin_define
define|#
directive|define
name|CSI1_PHY_CLK
value|52
end_define

begin_define
define|#
directive|define
name|CSI2_SRC
value|53
end_define

begin_define
define|#
directive|define
name|CSI2_CLK
value|54
end_define

begin_define
define|#
directive|define
name|CSI2_PHY_CLK
value|55
end_define

begin_define
define|#
directive|define
name|DSI_SRC
value|56
end_define

begin_define
define|#
directive|define
name|DSI_CLK
value|57
end_define

begin_define
define|#
directive|define
name|CSI_PIX_CLK
value|58
end_define

begin_define
define|#
directive|define
name|CSI_RDI_CLK
value|59
end_define

begin_define
define|#
directive|define
name|MDP_VSYNC_CLK
value|60
end_define

begin_define
define|#
directive|define
name|HDMI_DIV_CLK
value|61
end_define

begin_define
define|#
directive|define
name|HDMI_APP_CLK
value|62
end_define

begin_define
define|#
directive|define
name|CSI_PIX1_CLK
value|63
end_define

begin_define
define|#
directive|define
name|CSI_RDI2_CLK
value|64
end_define

begin_define
define|#
directive|define
name|CSI_RDI1_CLK
value|65
end_define

begin_define
define|#
directive|define
name|GFX2D0_SRC
value|66
end_define

begin_define
define|#
directive|define
name|GFX2D0_CLK
value|67
end_define

begin_define
define|#
directive|define
name|GFX2D1_SRC
value|68
end_define

begin_define
define|#
directive|define
name|GFX2D1_CLK
value|69
end_define

begin_define
define|#
directive|define
name|GFX3D_SRC
value|70
end_define

begin_define
define|#
directive|define
name|GFX3D_CLK
value|71
end_define

begin_define
define|#
directive|define
name|IJPEG_SRC
value|72
end_define

begin_define
define|#
directive|define
name|IJPEG_CLK
value|73
end_define

begin_define
define|#
directive|define
name|JPEGD_SRC
value|74
end_define

begin_define
define|#
directive|define
name|JPEGD_CLK
value|75
end_define

begin_define
define|#
directive|define
name|MDP_SRC
value|76
end_define

begin_define
define|#
directive|define
name|MDP_CLK
value|77
end_define

begin_define
define|#
directive|define
name|MDP_LUT_CLK
value|78
end_define

begin_define
define|#
directive|define
name|DSI2_PIXEL_SRC
value|79
end_define

begin_define
define|#
directive|define
name|DSI2_PIXEL_CLK
value|80
end_define

begin_define
define|#
directive|define
name|DSI2_SRC
value|81
end_define

begin_define
define|#
directive|define
name|DSI2_CLK
value|82
end_define

begin_define
define|#
directive|define
name|DSI1_BYTE_SRC
value|83
end_define

begin_define
define|#
directive|define
name|DSI1_BYTE_CLK
value|84
end_define

begin_define
define|#
directive|define
name|DSI2_BYTE_SRC
value|85
end_define

begin_define
define|#
directive|define
name|DSI2_BYTE_CLK
value|86
end_define

begin_define
define|#
directive|define
name|DSI1_ESC_SRC
value|87
end_define

begin_define
define|#
directive|define
name|DSI1_ESC_CLK
value|88
end_define

begin_define
define|#
directive|define
name|DSI2_ESC_SRC
value|89
end_define

begin_define
define|#
directive|define
name|DSI2_ESC_CLK
value|90
end_define

begin_define
define|#
directive|define
name|ROT_SRC
value|91
end_define

begin_define
define|#
directive|define
name|ROT_CLK
value|92
end_define

begin_define
define|#
directive|define
name|TV_ENC_CLK
value|93
end_define

begin_define
define|#
directive|define
name|TV_DAC_CLK
value|94
end_define

begin_define
define|#
directive|define
name|HDMI_TV_CLK
value|95
end_define

begin_define
define|#
directive|define
name|MDP_TV_CLK
value|96
end_define

begin_define
define|#
directive|define
name|TV_SRC
value|97
end_define

begin_define
define|#
directive|define
name|VCODEC_SRC
value|98
end_define

begin_define
define|#
directive|define
name|VCODEC_CLK
value|99
end_define

begin_define
define|#
directive|define
name|VFE_SRC
value|100
end_define

begin_define
define|#
directive|define
name|VFE_CLK
value|101
end_define

begin_define
define|#
directive|define
name|VFE_CSI_CLK
value|102
end_define

begin_define
define|#
directive|define
name|VPE_SRC
value|103
end_define

begin_define
define|#
directive|define
name|VPE_CLK
value|104
end_define

begin_define
define|#
directive|define
name|DSI_PIXEL_SRC
value|105
end_define

begin_define
define|#
directive|define
name|DSI_PIXEL_CLK
value|106
end_define

begin_define
define|#
directive|define
name|CAMCLK0_SRC
value|107
end_define

begin_define
define|#
directive|define
name|CAMCLK0_CLK
value|108
end_define

begin_define
define|#
directive|define
name|CAMCLK1_SRC
value|109
end_define

begin_define
define|#
directive|define
name|CAMCLK1_CLK
value|110
end_define

begin_define
define|#
directive|define
name|CAMCLK2_SRC
value|111
end_define

begin_define
define|#
directive|define
name|CAMCLK2_CLK
value|112
end_define

begin_define
define|#
directive|define
name|CSIPHYTIMER_SRC
value|113
end_define

begin_define
define|#
directive|define
name|CSIPHY2_TIMER_CLK
value|114
end_define

begin_define
define|#
directive|define
name|CSIPHY1_TIMER_CLK
value|115
end_define

begin_define
define|#
directive|define
name|CSIPHY0_TIMER_CLK
value|116
end_define

begin_define
define|#
directive|define
name|PLL1
value|117
end_define

begin_define
define|#
directive|define
name|PLL2
value|118
end_define

begin_define
define|#
directive|define
name|RGB_TV_CLK
value|119
end_define

begin_define
define|#
directive|define
name|NPL_TV_CLK
value|120
end_define

begin_define
define|#
directive|define
name|VCAP_AHB_CLK
value|121
end_define

begin_define
define|#
directive|define
name|VCAP_AXI_CLK
value|122
end_define

begin_define
define|#
directive|define
name|VCAP_SRC
value|123
end_define

begin_define
define|#
directive|define
name|VCAP_CLK
value|124
end_define

begin_define
define|#
directive|define
name|VCAP_NPL_CLK
value|125
end_define

begin_define
define|#
directive|define
name|PLL15
value|126
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

