begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013, The Linux Foundation. All rights reserved.  *  * This software is licensed under the terms of the GNU General Public  * License version 2, as published by the Free Software Foundation, and  * may be copied, distributed, and modified under those terms.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_RESET_MSM_MMCC_8960_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_RESET_MSM_MMCC_8960_H
end_define

begin_define
define|#
directive|define
name|VPE_AXI_RESET
value|0
end_define

begin_define
define|#
directive|define
name|IJPEG_AXI_RESET
value|1
end_define

begin_define
define|#
directive|define
name|MPD_AXI_RESET
value|2
end_define

begin_define
define|#
directive|define
name|VFE_AXI_RESET
value|3
end_define

begin_define
define|#
directive|define
name|SP_AXI_RESET
value|4
end_define

begin_define
define|#
directive|define
name|VCODEC_AXI_RESET
value|5
end_define

begin_define
define|#
directive|define
name|ROT_AXI_RESET
value|6
end_define

begin_define
define|#
directive|define
name|VCODEC_AXI_A_RESET
value|7
end_define

begin_define
define|#
directive|define
name|VCODEC_AXI_B_RESET
value|8
end_define

begin_define
define|#
directive|define
name|FAB_S3_AXI_RESET
value|9
end_define

begin_define
define|#
directive|define
name|FAB_S2_AXI_RESET
value|10
end_define

begin_define
define|#
directive|define
name|FAB_S1_AXI_RESET
value|11
end_define

begin_define
define|#
directive|define
name|FAB_S0_AXI_RESET
value|12
end_define

begin_define
define|#
directive|define
name|SMMU_GFX3D_ABH_RESET
value|13
end_define

begin_define
define|#
directive|define
name|SMMU_VPE_AHB_RESET
value|14
end_define

begin_define
define|#
directive|define
name|SMMU_VFE_AHB_RESET
value|15
end_define

begin_define
define|#
directive|define
name|SMMU_ROT_AHB_RESET
value|16
end_define

begin_define
define|#
directive|define
name|SMMU_VCODEC_B_AHB_RESET
value|17
end_define

begin_define
define|#
directive|define
name|SMMU_VCODEC_A_AHB_RESET
value|18
end_define

begin_define
define|#
directive|define
name|SMMU_MDP1_AHB_RESET
value|19
end_define

begin_define
define|#
directive|define
name|SMMU_MDP0_AHB_RESET
value|20
end_define

begin_define
define|#
directive|define
name|SMMU_JPEGD_AHB_RESET
value|21
end_define

begin_define
define|#
directive|define
name|SMMU_IJPEG_AHB_RESET
value|22
end_define

begin_define
define|#
directive|define
name|SMMU_GFX2D0_AHB_RESET
value|23
end_define

begin_define
define|#
directive|define
name|SMMU_GFX2D1_AHB_RESET
value|24
end_define

begin_define
define|#
directive|define
name|APU_AHB_RESET
value|25
end_define

begin_define
define|#
directive|define
name|CSI_AHB_RESET
value|26
end_define

begin_define
define|#
directive|define
name|TV_ENC_AHB_RESET
value|27
end_define

begin_define
define|#
directive|define
name|VPE_AHB_RESET
value|28
end_define

begin_define
define|#
directive|define
name|FABRIC_AHB_RESET
value|29
end_define

begin_define
define|#
directive|define
name|GFX2D0_AHB_RESET
value|30
end_define

begin_define
define|#
directive|define
name|GFX2D1_AHB_RESET
value|31
end_define

begin_define
define|#
directive|define
name|GFX3D_AHB_RESET
value|32
end_define

begin_define
define|#
directive|define
name|HDMI_AHB_RESET
value|33
end_define

begin_define
define|#
directive|define
name|MSSS_IMEM_AHB_RESET
value|34
end_define

begin_define
define|#
directive|define
name|IJPEG_AHB_RESET
value|35
end_define

begin_define
define|#
directive|define
name|DSI_M_AHB_RESET
value|36
end_define

begin_define
define|#
directive|define
name|DSI_S_AHB_RESET
value|37
end_define

begin_define
define|#
directive|define
name|JPEGD_AHB_RESET
value|38
end_define

begin_define
define|#
directive|define
name|MDP_AHB_RESET
value|39
end_define

begin_define
define|#
directive|define
name|ROT_AHB_RESET
value|40
end_define

begin_define
define|#
directive|define
name|VCODEC_AHB_RESET
value|41
end_define

begin_define
define|#
directive|define
name|VFE_AHB_RESET
value|42
end_define

begin_define
define|#
directive|define
name|DSI2_M_AHB_RESET
value|43
end_define

begin_define
define|#
directive|define
name|DSI2_S_AHB_RESET
value|44
end_define

begin_define
define|#
directive|define
name|CSIPHY2_RESET
value|45
end_define

begin_define
define|#
directive|define
name|CSI_PIX1_RESET
value|46
end_define

begin_define
define|#
directive|define
name|CSIPHY0_RESET
value|47
end_define

begin_define
define|#
directive|define
name|CSIPHY1_RESET
value|48
end_define

begin_define
define|#
directive|define
name|DSI2_RESET
value|49
end_define

begin_define
define|#
directive|define
name|VFE_CSI_RESET
value|50
end_define

begin_define
define|#
directive|define
name|MDP_RESET
value|51
end_define

begin_define
define|#
directive|define
name|AMP_RESET
value|52
end_define

begin_define
define|#
directive|define
name|JPEGD_RESET
value|53
end_define

begin_define
define|#
directive|define
name|CSI1_RESET
value|54
end_define

begin_define
define|#
directive|define
name|VPE_RESET
value|55
end_define

begin_define
define|#
directive|define
name|MMSS_FABRIC_RESET
value|56
end_define

begin_define
define|#
directive|define
name|VFE_RESET
value|57
end_define

begin_define
define|#
directive|define
name|GFX2D0_RESET
value|58
end_define

begin_define
define|#
directive|define
name|GFX2D1_RESET
value|59
end_define

begin_define
define|#
directive|define
name|GFX3D_RESET
value|60
end_define

begin_define
define|#
directive|define
name|HDMI_RESET
value|61
end_define

begin_define
define|#
directive|define
name|MMSS_IMEM_RESET
value|62
end_define

begin_define
define|#
directive|define
name|IJPEG_RESET
value|63
end_define

begin_define
define|#
directive|define
name|CSI0_RESET
value|64
end_define

begin_define
define|#
directive|define
name|DSI_RESET
value|65
end_define

begin_define
define|#
directive|define
name|VCODEC_RESET
value|66
end_define

begin_define
define|#
directive|define
name|MDP_TV_RESET
value|67
end_define

begin_define
define|#
directive|define
name|MDP_VSYNC_RESET
value|68
end_define

begin_define
define|#
directive|define
name|ROT_RESET
value|69
end_define

begin_define
define|#
directive|define
name|TV_HDMI_RESET
value|70
end_define

begin_define
define|#
directive|define
name|TV_ENC_RESET
value|71
end_define

begin_define
define|#
directive|define
name|CSI2_RESET
value|72
end_define

begin_define
define|#
directive|define
name|CSI_RDI1_RESET
value|73
end_define

begin_define
define|#
directive|define
name|CSI_RDI2_RESET
value|74
end_define

begin_define
define|#
directive|define
name|GFX3D_AXI_RESET
value|75
end_define

begin_define
define|#
directive|define
name|VCAP_AXI_RESET
value|76
end_define

begin_define
define|#
directive|define
name|SMMU_VCAP_AHB_RESET
value|77
end_define

begin_define
define|#
directive|define
name|VCAP_AHB_RESET
value|78
end_define

begin_define
define|#
directive|define
name|CSI_RDI_RESET
value|79
end_define

begin_define
define|#
directive|define
name|CSI_PIX_RESET
value|80
end_define

begin_define
define|#
directive|define
name|VCAP_NPL_RESET
value|81
end_define

begin_define
define|#
directive|define
name|VCAP_RESET
value|82
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

