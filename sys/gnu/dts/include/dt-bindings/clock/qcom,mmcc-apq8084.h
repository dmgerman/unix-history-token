begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014, The Linux Foundation. All rights reserved.  *  * This software is licensed under the terms of the GNU General Public  * License version 2, as published by the Free Software Foundation, and  * may be copied, distributed, and modified under those terms.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_APQ_MMCC_8084_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_APQ_MMCC_8084_H
end_define

begin_define
define|#
directive|define
name|MMSS_AHB_CLK_SRC
value|0
end_define

begin_define
define|#
directive|define
name|MMSS_AXI_CLK_SRC
value|1
end_define

begin_define
define|#
directive|define
name|MMPLL0
value|2
end_define

begin_define
define|#
directive|define
name|MMPLL0_VOTE
value|3
end_define

begin_define
define|#
directive|define
name|MMPLL1
value|4
end_define

begin_define
define|#
directive|define
name|MMPLL1_VOTE
value|5
end_define

begin_define
define|#
directive|define
name|MMPLL2
value|6
end_define

begin_define
define|#
directive|define
name|MMPLL3
value|7
end_define

begin_define
define|#
directive|define
name|MMPLL4
value|8
end_define

begin_define
define|#
directive|define
name|CSI0_CLK_SRC
value|9
end_define

begin_define
define|#
directive|define
name|CSI1_CLK_SRC
value|10
end_define

begin_define
define|#
directive|define
name|CSI2_CLK_SRC
value|11
end_define

begin_define
define|#
directive|define
name|CSI3_CLK_SRC
value|12
end_define

begin_define
define|#
directive|define
name|VCODEC0_CLK_SRC
value|13
end_define

begin_define
define|#
directive|define
name|VFE0_CLK_SRC
value|14
end_define

begin_define
define|#
directive|define
name|VFE1_CLK_SRC
value|15
end_define

begin_define
define|#
directive|define
name|MDP_CLK_SRC
value|16
end_define

begin_define
define|#
directive|define
name|PCLK0_CLK_SRC
value|17
end_define

begin_define
define|#
directive|define
name|PCLK1_CLK_SRC
value|18
end_define

begin_define
define|#
directive|define
name|OCMEMNOC_CLK_SRC
value|19
end_define

begin_define
define|#
directive|define
name|GFX3D_CLK_SRC
value|20
end_define

begin_define
define|#
directive|define
name|JPEG0_CLK_SRC
value|21
end_define

begin_define
define|#
directive|define
name|JPEG1_CLK_SRC
value|22
end_define

begin_define
define|#
directive|define
name|JPEG2_CLK_SRC
value|23
end_define

begin_define
define|#
directive|define
name|EDPPIXEL_CLK_SRC
value|24
end_define

begin_define
define|#
directive|define
name|EXTPCLK_CLK_SRC
value|25
end_define

begin_define
define|#
directive|define
name|VP_CLK_SRC
value|26
end_define

begin_define
define|#
directive|define
name|CCI_CLK_SRC
value|27
end_define

begin_define
define|#
directive|define
name|CAMSS_GP0_CLK_SRC
value|28
end_define

begin_define
define|#
directive|define
name|CAMSS_GP1_CLK_SRC
value|29
end_define

begin_define
define|#
directive|define
name|MCLK0_CLK_SRC
value|30
end_define

begin_define
define|#
directive|define
name|MCLK1_CLK_SRC
value|31
end_define

begin_define
define|#
directive|define
name|MCLK2_CLK_SRC
value|32
end_define

begin_define
define|#
directive|define
name|MCLK3_CLK_SRC
value|33
end_define

begin_define
define|#
directive|define
name|CSI0PHYTIMER_CLK_SRC
value|34
end_define

begin_define
define|#
directive|define
name|CSI1PHYTIMER_CLK_SRC
value|35
end_define

begin_define
define|#
directive|define
name|CSI2PHYTIMER_CLK_SRC
value|36
end_define

begin_define
define|#
directive|define
name|CPP_CLK_SRC
value|37
end_define

begin_define
define|#
directive|define
name|BYTE0_CLK_SRC
value|38
end_define

begin_define
define|#
directive|define
name|BYTE1_CLK_SRC
value|39
end_define

begin_define
define|#
directive|define
name|EDPAUX_CLK_SRC
value|40
end_define

begin_define
define|#
directive|define
name|EDPLINK_CLK_SRC
value|41
end_define

begin_define
define|#
directive|define
name|ESC0_CLK_SRC
value|42
end_define

begin_define
define|#
directive|define
name|ESC1_CLK_SRC
value|43
end_define

begin_define
define|#
directive|define
name|HDMI_CLK_SRC
value|44
end_define

begin_define
define|#
directive|define
name|VSYNC_CLK_SRC
value|45
end_define

begin_define
define|#
directive|define
name|RBCPR_CLK_SRC
value|46
end_define

begin_define
define|#
directive|define
name|RBBMTIMER_CLK_SRC
value|47
end_define

begin_define
define|#
directive|define
name|MAPLE_CLK_SRC
value|48
end_define

begin_define
define|#
directive|define
name|VDP_CLK_SRC
value|49
end_define

begin_define
define|#
directive|define
name|VPU_BUS_CLK_SRC
value|50
end_define

begin_define
define|#
directive|define
name|MMSS_CXO_CLK
value|51
end_define

begin_define
define|#
directive|define
name|MMSS_SLEEPCLK_CLK
value|52
end_define

begin_define
define|#
directive|define
name|AVSYNC_AHB_CLK
value|53
end_define

begin_define
define|#
directive|define
name|AVSYNC_EDPPIXEL_CLK
value|54
end_define

begin_define
define|#
directive|define
name|AVSYNC_EXTPCLK_CLK
value|55
end_define

begin_define
define|#
directive|define
name|AVSYNC_PCLK0_CLK
value|56
end_define

begin_define
define|#
directive|define
name|AVSYNC_PCLK1_CLK
value|57
end_define

begin_define
define|#
directive|define
name|AVSYNC_VP_CLK
value|58
end_define

begin_define
define|#
directive|define
name|CAMSS_AHB_CLK
value|59
end_define

begin_define
define|#
directive|define
name|CAMSS_CCI_CCI_AHB_CLK
value|60
end_define

begin_define
define|#
directive|define
name|CAMSS_CCI_CCI_CLK
value|61
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI0_AHB_CLK
value|62
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI0_CLK
value|63
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI0PHY_CLK
value|64
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI0PIX_CLK
value|65
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI0RDI_CLK
value|66
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI1_AHB_CLK
value|67
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI1_CLK
value|68
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI1PHY_CLK
value|69
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI1PIX_CLK
value|70
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI1RDI_CLK
value|71
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI2_AHB_CLK
value|72
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI2_CLK
value|73
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI2PHY_CLK
value|74
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI2PIX_CLK
value|75
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI2RDI_CLK
value|76
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI3_AHB_CLK
value|77
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI3_CLK
value|78
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI3PHY_CLK
value|79
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI3PIX_CLK
value|80
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI3RDI_CLK
value|81
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI_VFE0_CLK
value|82
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI_VFE1_CLK
value|83
end_define

begin_define
define|#
directive|define
name|CAMSS_GP0_CLK
value|84
end_define

begin_define
define|#
directive|define
name|CAMSS_GP1_CLK
value|85
end_define

begin_define
define|#
directive|define
name|CAMSS_ISPIF_AHB_CLK
value|86
end_define

begin_define
define|#
directive|define
name|CAMSS_JPEG_JPEG0_CLK
value|87
end_define

begin_define
define|#
directive|define
name|CAMSS_JPEG_JPEG1_CLK
value|88
end_define

begin_define
define|#
directive|define
name|CAMSS_JPEG_JPEG2_CLK
value|89
end_define

begin_define
define|#
directive|define
name|CAMSS_JPEG_JPEG_AHB_CLK
value|90
end_define

begin_define
define|#
directive|define
name|CAMSS_JPEG_JPEG_AXI_CLK
value|91
end_define

begin_define
define|#
directive|define
name|CAMSS_MCLK0_CLK
value|92
end_define

begin_define
define|#
directive|define
name|CAMSS_MCLK1_CLK
value|93
end_define

begin_define
define|#
directive|define
name|CAMSS_MCLK2_CLK
value|94
end_define

begin_define
define|#
directive|define
name|CAMSS_MCLK3_CLK
value|95
end_define

begin_define
define|#
directive|define
name|CAMSS_MICRO_AHB_CLK
value|96
end_define

begin_define
define|#
directive|define
name|CAMSS_PHY0_CSI0PHYTIMER_CLK
value|97
end_define

begin_define
define|#
directive|define
name|CAMSS_PHY1_CSI1PHYTIMER_CLK
value|98
end_define

begin_define
define|#
directive|define
name|CAMSS_PHY2_CSI2PHYTIMER_CLK
value|99
end_define

begin_define
define|#
directive|define
name|CAMSS_TOP_AHB_CLK
value|100
end_define

begin_define
define|#
directive|define
name|CAMSS_VFE_CPP_AHB_CLK
value|101
end_define

begin_define
define|#
directive|define
name|CAMSS_VFE_CPP_CLK
value|102
end_define

begin_define
define|#
directive|define
name|CAMSS_VFE_VFE0_CLK
value|103
end_define

begin_define
define|#
directive|define
name|CAMSS_VFE_VFE1_CLK
value|104
end_define

begin_define
define|#
directive|define
name|CAMSS_VFE_VFE_AHB_CLK
value|105
end_define

begin_define
define|#
directive|define
name|CAMSS_VFE_VFE_AXI_CLK
value|106
end_define

begin_define
define|#
directive|define
name|MDSS_AHB_CLK
value|107
end_define

begin_define
define|#
directive|define
name|MDSS_AXI_CLK
value|108
end_define

begin_define
define|#
directive|define
name|MDSS_BYTE0_CLK
value|109
end_define

begin_define
define|#
directive|define
name|MDSS_BYTE1_CLK
value|110
end_define

begin_define
define|#
directive|define
name|MDSS_EDPAUX_CLK
value|111
end_define

begin_define
define|#
directive|define
name|MDSS_EDPLINK_CLK
value|112
end_define

begin_define
define|#
directive|define
name|MDSS_EDPPIXEL_CLK
value|113
end_define

begin_define
define|#
directive|define
name|MDSS_ESC0_CLK
value|114
end_define

begin_define
define|#
directive|define
name|MDSS_ESC1_CLK
value|115
end_define

begin_define
define|#
directive|define
name|MDSS_EXTPCLK_CLK
value|116
end_define

begin_define
define|#
directive|define
name|MDSS_HDMI_AHB_CLK
value|117
end_define

begin_define
define|#
directive|define
name|MDSS_HDMI_CLK
value|118
end_define

begin_define
define|#
directive|define
name|MDSS_MDP_CLK
value|119
end_define

begin_define
define|#
directive|define
name|MDSS_MDP_LUT_CLK
value|120
end_define

begin_define
define|#
directive|define
name|MDSS_PCLK0_CLK
value|121
end_define

begin_define
define|#
directive|define
name|MDSS_PCLK1_CLK
value|122
end_define

begin_define
define|#
directive|define
name|MDSS_VSYNC_CLK
value|123
end_define

begin_define
define|#
directive|define
name|MMSS_RBCPR_AHB_CLK
value|124
end_define

begin_define
define|#
directive|define
name|MMSS_RBCPR_CLK
value|125
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_AHB_CLK
value|126
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_AXI_CLK
value|127
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_CSI0_CLK
value|128
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_GFX3D_CLK
value|129
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_JPEG0_CLK
value|130
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_JPEG1_CLK
value|131
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_JPEG2_CLK
value|132
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_MDP_CLK
value|133
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_PCLK0_CLK
value|134
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_PCLK1_CLK
value|135
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_VCODEC0_CLK
value|136
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_VFE0_CLK
value|137
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_VFE1_CLK
value|138
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_RM_AXI_CLK
value|139
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_RM_OCMEMNOC_CLK
value|140
end_define

begin_define
define|#
directive|define
name|MMSS_MISC_AHB_CLK
value|141
end_define

begin_define
define|#
directive|define
name|MMSS_MMSSNOC_AHB_CLK
value|142
end_define

begin_define
define|#
directive|define
name|MMSS_MMSSNOC_BTO_AHB_CLK
value|143
end_define

begin_define
define|#
directive|define
name|MMSS_MMSSNOC_AXI_CLK
value|144
end_define

begin_define
define|#
directive|define
name|MMSS_S0_AXI_CLK
value|145
end_define

begin_define
define|#
directive|define
name|OCMEMCX_AHB_CLK
value|146
end_define

begin_define
define|#
directive|define
name|OCMEMCX_OCMEMNOC_CLK
value|147
end_define

begin_define
define|#
directive|define
name|OXILI_OCMEMGX_CLK
value|148
end_define

begin_define
define|#
directive|define
name|OXILI_GFX3D_CLK
value|149
end_define

begin_define
define|#
directive|define
name|OXILI_RBBMTIMER_CLK
value|150
end_define

begin_define
define|#
directive|define
name|OXILICX_AHB_CLK
value|151
end_define

begin_define
define|#
directive|define
name|VENUS0_AHB_CLK
value|152
end_define

begin_define
define|#
directive|define
name|VENUS0_AXI_CLK
value|153
end_define

begin_define
define|#
directive|define
name|VENUS0_CORE0_VCODEC_CLK
value|154
end_define

begin_define
define|#
directive|define
name|VENUS0_CORE1_VCODEC_CLK
value|155
end_define

begin_define
define|#
directive|define
name|VENUS0_OCMEMNOC_CLK
value|156
end_define

begin_define
define|#
directive|define
name|VENUS0_VCODEC0_CLK
value|157
end_define

begin_define
define|#
directive|define
name|VPU_AHB_CLK
value|158
end_define

begin_define
define|#
directive|define
name|VPU_AXI_CLK
value|159
end_define

begin_define
define|#
directive|define
name|VPU_BUS_CLK
value|160
end_define

begin_define
define|#
directive|define
name|VPU_CXO_CLK
value|161
end_define

begin_define
define|#
directive|define
name|VPU_MAPLE_CLK
value|162
end_define

begin_define
define|#
directive|define
name|VPU_SLEEP_CLK
value|163
end_define

begin_define
define|#
directive|define
name|VPU_VDP_CLK
value|164
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

