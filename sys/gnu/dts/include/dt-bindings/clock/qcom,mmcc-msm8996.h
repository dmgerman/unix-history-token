begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2015, The Linux Foundation. All rights reserved.  *  * This software is licensed under the terms of the GNU General Public  * License version 2, as published by the Free Software Foundation, and  * may be copied, distributed, and modified under those terms.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_MSM_MMCC_8996_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_MSM_MMCC_8996_H
end_define

begin_define
define|#
directive|define
name|MMPLL0_EARLY
value|0
end_define

begin_define
define|#
directive|define
name|MMPLL0_PLL
value|1
end_define

begin_define
define|#
directive|define
name|MMPLL1_EARLY
value|2
end_define

begin_define
define|#
directive|define
name|MMPLL1_PLL
value|3
end_define

begin_define
define|#
directive|define
name|MMPLL2_EARLY
value|4
end_define

begin_define
define|#
directive|define
name|MMPLL2_PLL
value|5
end_define

begin_define
define|#
directive|define
name|MMPLL3_EARLY
value|6
end_define

begin_define
define|#
directive|define
name|MMPLL3_PLL
value|7
end_define

begin_define
define|#
directive|define
name|MMPLL4_EARLY
value|8
end_define

begin_define
define|#
directive|define
name|MMPLL4_PLL
value|9
end_define

begin_define
define|#
directive|define
name|MMPLL5_EARLY
value|10
end_define

begin_define
define|#
directive|define
name|MMPLL5_PLL
value|11
end_define

begin_define
define|#
directive|define
name|MMPLL8_EARLY
value|12
end_define

begin_define
define|#
directive|define
name|MMPLL8_PLL
value|13
end_define

begin_define
define|#
directive|define
name|MMPLL9_EARLY
value|14
end_define

begin_define
define|#
directive|define
name|MMPLL9_PLL
value|15
end_define

begin_define
define|#
directive|define
name|AHB_CLK_SRC
value|16
end_define

begin_define
define|#
directive|define
name|AXI_CLK_SRC
value|17
end_define

begin_define
define|#
directive|define
name|MAXI_CLK_SRC
value|18
end_define

begin_define
define|#
directive|define
name|DSA_CORE_CLK_SRC
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
name|RBBMTIMER_CLK_SRC
value|21
end_define

begin_define
define|#
directive|define
name|ISENSE_CLK_SRC
value|22
end_define

begin_define
define|#
directive|define
name|RBCPR_CLK_SRC
value|23
end_define

begin_define
define|#
directive|define
name|VIDEO_CORE_CLK_SRC
value|24
end_define

begin_define
define|#
directive|define
name|VIDEO_SUBCORE0_CLK_SRC
value|25
end_define

begin_define
define|#
directive|define
name|VIDEO_SUBCORE1_CLK_SRC
value|26
end_define

begin_define
define|#
directive|define
name|PCLK0_CLK_SRC
value|27
end_define

begin_define
define|#
directive|define
name|PCLK1_CLK_SRC
value|28
end_define

begin_define
define|#
directive|define
name|MDP_CLK_SRC
value|29
end_define

begin_define
define|#
directive|define
name|EXTPCLK_CLK_SRC
value|30
end_define

begin_define
define|#
directive|define
name|VSYNC_CLK_SRC
value|31
end_define

begin_define
define|#
directive|define
name|HDMI_CLK_SRC
value|32
end_define

begin_define
define|#
directive|define
name|BYTE0_CLK_SRC
value|33
end_define

begin_define
define|#
directive|define
name|BYTE1_CLK_SRC
value|34
end_define

begin_define
define|#
directive|define
name|ESC0_CLK_SRC
value|35
end_define

begin_define
define|#
directive|define
name|ESC1_CLK_SRC
value|36
end_define

begin_define
define|#
directive|define
name|CAMSS_GP0_CLK_SRC
value|37
end_define

begin_define
define|#
directive|define
name|CAMSS_GP1_CLK_SRC
value|38
end_define

begin_define
define|#
directive|define
name|MCLK0_CLK_SRC
value|39
end_define

begin_define
define|#
directive|define
name|MCLK1_CLK_SRC
value|40
end_define

begin_define
define|#
directive|define
name|MCLK2_CLK_SRC
value|41
end_define

begin_define
define|#
directive|define
name|MCLK3_CLK_SRC
value|42
end_define

begin_define
define|#
directive|define
name|CCI_CLK_SRC
value|43
end_define

begin_define
define|#
directive|define
name|CSI0PHYTIMER_CLK_SRC
value|44
end_define

begin_define
define|#
directive|define
name|CSI1PHYTIMER_CLK_SRC
value|45
end_define

begin_define
define|#
directive|define
name|CSI2PHYTIMER_CLK_SRC
value|46
end_define

begin_define
define|#
directive|define
name|CSIPHY0_3P_CLK_SRC
value|47
end_define

begin_define
define|#
directive|define
name|CSIPHY1_3P_CLK_SRC
value|48
end_define

begin_define
define|#
directive|define
name|CSIPHY2_3P_CLK_SRC
value|49
end_define

begin_define
define|#
directive|define
name|JPEG0_CLK_SRC
value|50
end_define

begin_define
define|#
directive|define
name|JPEG2_CLK_SRC
value|51
end_define

begin_define
define|#
directive|define
name|JPEG_DMA_CLK_SRC
value|52
end_define

begin_define
define|#
directive|define
name|VFE0_CLK_SRC
value|53
end_define

begin_define
define|#
directive|define
name|VFE1_CLK_SRC
value|54
end_define

begin_define
define|#
directive|define
name|CPP_CLK_SRC
value|55
end_define

begin_define
define|#
directive|define
name|CSI0_CLK_SRC
value|56
end_define

begin_define
define|#
directive|define
name|CSI1_CLK_SRC
value|57
end_define

begin_define
define|#
directive|define
name|CSI2_CLK_SRC
value|58
end_define

begin_define
define|#
directive|define
name|CSI3_CLK_SRC
value|59
end_define

begin_define
define|#
directive|define
name|FD_CORE_CLK_SRC
value|60
end_define

begin_define
define|#
directive|define
name|MMSS_CXO_CLK
value|61
end_define

begin_define
define|#
directive|define
name|MMSS_SLEEPCLK_CLK
value|62
end_define

begin_define
define|#
directive|define
name|MMSS_MMAGIC_AHB_CLK
value|63
end_define

begin_define
define|#
directive|define
name|MMSS_MMAGIC_CFG_AHB_CLK
value|64
end_define

begin_define
define|#
directive|define
name|MMSS_MISC_AHB_CLK
value|65
end_define

begin_define
define|#
directive|define
name|MMSS_MISC_CXO_CLK
value|66
end_define

begin_define
define|#
directive|define
name|MMSS_BTO_AHB_CLK
value|67
end_define

begin_define
define|#
directive|define
name|MMSS_MMAGIC_AXI_CLK
value|68
end_define

begin_define
define|#
directive|define
name|MMSS_S0_AXI_CLK
value|69
end_define

begin_define
define|#
directive|define
name|MMSS_MMAGIC_MAXI_CLK
value|70
end_define

begin_define
define|#
directive|define
name|DSA_CORE_CLK
value|71
end_define

begin_define
define|#
directive|define
name|DSA_NOC_CFG_AHB_CLK
value|72
end_define

begin_define
define|#
directive|define
name|MMAGIC_CAMSS_AXI_CLK
value|73
end_define

begin_define
define|#
directive|define
name|MMAGIC_CAMSS_NOC_CFG_AHB_CLK
value|74
end_define

begin_define
define|#
directive|define
name|THROTTLE_CAMSS_CXO_CLK
value|75
end_define

begin_define
define|#
directive|define
name|THROTTLE_CAMSS_AHB_CLK
value|76
end_define

begin_define
define|#
directive|define
name|THROTTLE_CAMSS_AXI_CLK
value|77
end_define

begin_define
define|#
directive|define
name|SMMU_VFE_AHB_CLK
value|78
end_define

begin_define
define|#
directive|define
name|SMMU_VFE_AXI_CLK
value|79
end_define

begin_define
define|#
directive|define
name|SMMU_CPP_AHB_CLK
value|80
end_define

begin_define
define|#
directive|define
name|SMMU_CPP_AXI_CLK
value|81
end_define

begin_define
define|#
directive|define
name|SMMU_JPEG_AHB_CLK
value|82
end_define

begin_define
define|#
directive|define
name|SMMU_JPEG_AXI_CLK
value|83
end_define

begin_define
define|#
directive|define
name|MMAGIC_MDSS_AXI_CLK
value|84
end_define

begin_define
define|#
directive|define
name|MMAGIC_MDSS_NOC_CFG_AHB_CLK
value|85
end_define

begin_define
define|#
directive|define
name|THROTTLE_MDSS_CXO_CLK
value|86
end_define

begin_define
define|#
directive|define
name|THROTTLE_MDSS_AHB_CLK
value|87
end_define

begin_define
define|#
directive|define
name|THROTTLE_MDSS_AXI_CLK
value|88
end_define

begin_define
define|#
directive|define
name|SMMU_ROT_AHB_CLK
value|89
end_define

begin_define
define|#
directive|define
name|SMMU_ROT_AXI_CLK
value|90
end_define

begin_define
define|#
directive|define
name|SMMU_MDP_AHB_CLK
value|91
end_define

begin_define
define|#
directive|define
name|SMMU_MDP_AXI_CLK
value|92
end_define

begin_define
define|#
directive|define
name|MMAGIC_VIDEO_AXI_CLK
value|93
end_define

begin_define
define|#
directive|define
name|MMAGIC_VIDEO_NOC_CFG_AHB_CLK
value|94
end_define

begin_define
define|#
directive|define
name|THROTTLE_VIDEO_CXO_CLK
value|95
end_define

begin_define
define|#
directive|define
name|THROTTLE_VIDEO_AHB_CLK
value|96
end_define

begin_define
define|#
directive|define
name|THROTTLE_VIDEO_AXI_CLK
value|97
end_define

begin_define
define|#
directive|define
name|SMMU_VIDEO_AHB_CLK
value|98
end_define

begin_define
define|#
directive|define
name|SMMU_VIDEO_AXI_CLK
value|99
end_define

begin_define
define|#
directive|define
name|MMAGIC_BIMC_AXI_CLK
value|100
end_define

begin_define
define|#
directive|define
name|MMAGIC_BIMC_NOC_CFG_AHB_CLK
value|101
end_define

begin_define
define|#
directive|define
name|GPU_GX_GFX3D_CLK
value|102
end_define

begin_define
define|#
directive|define
name|GPU_GX_RBBMTIMER_CLK
value|103
end_define

begin_define
define|#
directive|define
name|GPU_AHB_CLK
value|104
end_define

begin_define
define|#
directive|define
name|GPU_AON_ISENSE_CLK
value|105
end_define

begin_define
define|#
directive|define
name|VMEM_MAXI_CLK
value|106
end_define

begin_define
define|#
directive|define
name|VMEM_AHB_CLK
value|107
end_define

begin_define
define|#
directive|define
name|MMSS_RBCPR_CLK
value|108
end_define

begin_define
define|#
directive|define
name|MMSS_RBCPR_AHB_CLK
value|109
end_define

begin_define
define|#
directive|define
name|VIDEO_CORE_CLK
value|110
end_define

begin_define
define|#
directive|define
name|VIDEO_AXI_CLK
value|111
end_define

begin_define
define|#
directive|define
name|VIDEO_MAXI_CLK
value|112
end_define

begin_define
define|#
directive|define
name|VIDEO_AHB_CLK
value|113
end_define

begin_define
define|#
directive|define
name|VIDEO_SUBCORE0_CLK
value|114
end_define

begin_define
define|#
directive|define
name|VIDEO_SUBCORE1_CLK
value|115
end_define

begin_define
define|#
directive|define
name|MDSS_AHB_CLK
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
name|MDSS_AXI_CLK
value|118
end_define

begin_define
define|#
directive|define
name|MDSS_PCLK0_CLK
value|119
end_define

begin_define
define|#
directive|define
name|MDSS_PCLK1_CLK
value|120
end_define

begin_define
define|#
directive|define
name|MDSS_MDP_CLK
value|121
end_define

begin_define
define|#
directive|define
name|MDSS_EXTPCLK_CLK
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
name|MDSS_HDMI_CLK
value|124
end_define

begin_define
define|#
directive|define
name|MDSS_BYTE0_CLK
value|125
end_define

begin_define
define|#
directive|define
name|MDSS_BYTE1_CLK
value|126
end_define

begin_define
define|#
directive|define
name|MDSS_ESC0_CLK
value|127
end_define

begin_define
define|#
directive|define
name|MDSS_ESC1_CLK
value|128
end_define

begin_define
define|#
directive|define
name|CAMSS_TOP_AHB_CLK
value|129
end_define

begin_define
define|#
directive|define
name|CAMSS_AHB_CLK
value|130
end_define

begin_define
define|#
directive|define
name|CAMSS_MICRO_AHB_CLK
value|131
end_define

begin_define
define|#
directive|define
name|CAMSS_GP0_CLK
value|132
end_define

begin_define
define|#
directive|define
name|CAMSS_GP1_CLK
value|133
end_define

begin_define
define|#
directive|define
name|CAMSS_MCLK0_CLK
value|134
end_define

begin_define
define|#
directive|define
name|CAMSS_MCLK1_CLK
value|135
end_define

begin_define
define|#
directive|define
name|CAMSS_MCLK2_CLK
value|136
end_define

begin_define
define|#
directive|define
name|CAMSS_MCLK3_CLK
value|137
end_define

begin_define
define|#
directive|define
name|CAMSS_CCI_CLK
value|138
end_define

begin_define
define|#
directive|define
name|CAMSS_CCI_AHB_CLK
value|139
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI0PHYTIMER_CLK
value|140
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI1PHYTIMER_CLK
value|141
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI2PHYTIMER_CLK
value|142
end_define

begin_define
define|#
directive|define
name|CAMSS_CSIPHY0_3P_CLK
value|143
end_define

begin_define
define|#
directive|define
name|CAMSS_CSIPHY1_3P_CLK
value|144
end_define

begin_define
define|#
directive|define
name|CAMSS_CSIPHY2_3P_CLK
value|145
end_define

begin_define
define|#
directive|define
name|CAMSS_JPEG0_CLK
value|146
end_define

begin_define
define|#
directive|define
name|CAMSS_JPEG2_CLK
value|147
end_define

begin_define
define|#
directive|define
name|CAMSS_JPEG_DMA_CLK
value|148
end_define

begin_define
define|#
directive|define
name|CAMSS_JPEG_AHB_CLK
value|149
end_define

begin_define
define|#
directive|define
name|CAMSS_JPEG_AXI_CLK
value|150
end_define

begin_define
define|#
directive|define
name|CAMSS_VFE_AHB_CLK
value|151
end_define

begin_define
define|#
directive|define
name|CAMSS_VFE_AXI_CLK
value|152
end_define

begin_define
define|#
directive|define
name|CAMSS_VFE0_CLK
value|153
end_define

begin_define
define|#
directive|define
name|CAMSS_VFE0_STREAM_CLK
value|154
end_define

begin_define
define|#
directive|define
name|CAMSS_VFE0_AHB_CLK
value|155
end_define

begin_define
define|#
directive|define
name|CAMSS_VFE1_CLK
value|156
end_define

begin_define
define|#
directive|define
name|CAMSS_VFE1_STREAM_CLK
value|157
end_define

begin_define
define|#
directive|define
name|CAMSS_VFE1_AHB_CLK
value|158
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI_VFE0_CLK
value|159
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI_VFE1_CLK
value|160
end_define

begin_define
define|#
directive|define
name|CAMSS_CPP_VBIF_AHB_CLK
value|161
end_define

begin_define
define|#
directive|define
name|CAMSS_CPP_AXI_CLK
value|162
end_define

begin_define
define|#
directive|define
name|CAMSS_CPP_CLK
value|163
end_define

begin_define
define|#
directive|define
name|CAMSS_CPP_AHB_CLK
value|164
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI0_CLK
value|165
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI0_AHB_CLK
value|166
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI0PHY_CLK
value|167
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI0RDI_CLK
value|168
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI0PIX_CLK
value|169
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI1_CLK
value|170
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI1_AHB_CLK
value|171
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI1PHY_CLK
value|172
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI1RDI_CLK
value|173
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI1PIX_CLK
value|174
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI2_CLK
value|175
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI2_AHB_CLK
value|176
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI2PHY_CLK
value|177
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI2RDI_CLK
value|178
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI2PIX_CLK
value|179
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI3_CLK
value|180
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI3_AHB_CLK
value|181
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI3PHY_CLK
value|182
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI3RDI_CLK
value|183
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI3PIX_CLK
value|184
end_define

begin_define
define|#
directive|define
name|CAMSS_ISPIF_AHB_CLK
value|185
end_define

begin_define
define|#
directive|define
name|FD_CORE_CLK
value|186
end_define

begin_define
define|#
directive|define
name|FD_CORE_UAR_CLK
value|187
end_define

begin_define
define|#
directive|define
name|FD_AHB_CLK
value|188
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_CSI0_CLK
value|189
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_JPEG_DMA_CLK
value|190
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_CPP_CLK
value|191
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_PCLK0_CLK
value|192
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_AHB_CLK
value|193
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_GFX3D_CLK
value|194
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_PCLK1_CLK
value|195
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_JPEG2_CLK
value|196
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_DEBUG_CLK
value|197
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_VFE1_CLK
value|198
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_VFE0_CLK
value|199
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_VIDEO_CORE_CLK
value|200
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_AXI_CLK
value|201
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_MDP_CLK
value|202
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_JPEG0_CLK
value|203
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_RM_AXI_CLK
value|204
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_RM_MAXI_CLK
value|205
end_define

begin_define
define|#
directive|define
name|MMAGICAHB_BCR
value|0
end_define

begin_define
define|#
directive|define
name|MMAGIC_CFG_BCR
value|1
end_define

begin_define
define|#
directive|define
name|MISC_BCR
value|2
end_define

begin_define
define|#
directive|define
name|BTO_BCR
value|3
end_define

begin_define
define|#
directive|define
name|MMAGICAXI_BCR
value|4
end_define

begin_define
define|#
directive|define
name|MMAGICMAXI_BCR
value|5
end_define

begin_define
define|#
directive|define
name|DSA_BCR
value|6
end_define

begin_define
define|#
directive|define
name|MMAGIC_CAMSS_BCR
value|7
end_define

begin_define
define|#
directive|define
name|THROTTLE_CAMSS_BCR
value|8
end_define

begin_define
define|#
directive|define
name|SMMU_VFE_BCR
value|9
end_define

begin_define
define|#
directive|define
name|SMMU_CPP_BCR
value|10
end_define

begin_define
define|#
directive|define
name|SMMU_JPEG_BCR
value|11
end_define

begin_define
define|#
directive|define
name|MMAGIC_MDSS_BCR
value|12
end_define

begin_define
define|#
directive|define
name|THROTTLE_MDSS_BCR
value|13
end_define

begin_define
define|#
directive|define
name|SMMU_ROT_BCR
value|14
end_define

begin_define
define|#
directive|define
name|SMMU_MDP_BCR
value|15
end_define

begin_define
define|#
directive|define
name|MMAGIC_VIDEO_BCR
value|16
end_define

begin_define
define|#
directive|define
name|THROTTLE_VIDEO_BCR
value|17
end_define

begin_define
define|#
directive|define
name|SMMU_VIDEO_BCR
value|18
end_define

begin_define
define|#
directive|define
name|MMAGIC_BIMC_BCR
value|19
end_define

begin_define
define|#
directive|define
name|GPU_GX_BCR
value|20
end_define

begin_define
define|#
directive|define
name|GPU_BCR
value|21
end_define

begin_define
define|#
directive|define
name|GPU_AON_BCR
value|22
end_define

begin_define
define|#
directive|define
name|VMEM_BCR
value|23
end_define

begin_define
define|#
directive|define
name|MMSS_RBCPR_BCR
value|24
end_define

begin_define
define|#
directive|define
name|VIDEO_BCR
value|25
end_define

begin_define
define|#
directive|define
name|MDSS_BCR
value|26
end_define

begin_define
define|#
directive|define
name|CAMSS_TOP_BCR
value|27
end_define

begin_define
define|#
directive|define
name|CAMSS_AHB_BCR
value|28
end_define

begin_define
define|#
directive|define
name|CAMSS_MICRO_BCR
value|29
end_define

begin_define
define|#
directive|define
name|CAMSS_CCI_BCR
value|30
end_define

begin_define
define|#
directive|define
name|CAMSS_PHY0_BCR
value|31
end_define

begin_define
define|#
directive|define
name|CAMSS_PHY1_BCR
value|32
end_define

begin_define
define|#
directive|define
name|CAMSS_PHY2_BCR
value|33
end_define

begin_define
define|#
directive|define
name|CAMSS_CSIPHY0_3P_BCR
value|34
end_define

begin_define
define|#
directive|define
name|CAMSS_CSIPHY1_3P_BCR
value|35
end_define

begin_define
define|#
directive|define
name|CAMSS_CSIPHY2_3P_BCR
value|36
end_define

begin_define
define|#
directive|define
name|CAMSS_JPEG_BCR
value|37
end_define

begin_define
define|#
directive|define
name|CAMSS_VFE_BCR
value|38
end_define

begin_define
define|#
directive|define
name|CAMSS_VFE0_BCR
value|39
end_define

begin_define
define|#
directive|define
name|CAMSS_VFE1_BCR
value|40
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI_VFE0_BCR
value|41
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI_VFE1_BCR
value|42
end_define

begin_define
define|#
directive|define
name|CAMSS_CPP_TOP_BCR
value|43
end_define

begin_define
define|#
directive|define
name|CAMSS_CPP_BCR
value|44
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI0_BCR
value|45
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI0RDI_BCR
value|46
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI0PIX_BCR
value|47
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI1_BCR
value|48
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI1RDI_BCR
value|49
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI1PIX_BCR
value|50
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI2_BCR
value|51
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI2RDI_BCR
value|52
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI2PIX_BCR
value|53
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI3_BCR
value|54
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI3RDI_BCR
value|55
end_define

begin_define
define|#
directive|define
name|CAMSS_CSI3PIX_BCR
value|56
end_define

begin_define
define|#
directive|define
name|CAMSS_ISPIF_BCR
value|57
end_define

begin_define
define|#
directive|define
name|FD_BCR
value|58
end_define

begin_define
define|#
directive|define
name|MMSS_SPDM_RM_BCR
value|59
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

