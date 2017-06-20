begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2015 Linaro Limited  *  * This software is licensed under the terms of the GNU General Public  * License version 2, as published by the Free Software Foundation, and  * may be copied, distributed, and modified under those terms.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_MSM_RPMCC_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_MSM_RPMCC_H
end_define

begin_comment
comment|/* RPM clocks */
end_comment

begin_define
define|#
directive|define
name|RPM_PXO_CLK
value|0
end_define

begin_define
define|#
directive|define
name|RPM_PXO_A_CLK
value|1
end_define

begin_define
define|#
directive|define
name|RPM_CXO_CLK
value|2
end_define

begin_define
define|#
directive|define
name|RPM_CXO_A_CLK
value|3
end_define

begin_define
define|#
directive|define
name|RPM_APPS_FABRIC_CLK
value|4
end_define

begin_define
define|#
directive|define
name|RPM_APPS_FABRIC_A_CLK
value|5
end_define

begin_define
define|#
directive|define
name|RPM_CFPB_CLK
value|6
end_define

begin_define
define|#
directive|define
name|RPM_CFPB_A_CLK
value|7
end_define

begin_define
define|#
directive|define
name|RPM_QDSS_CLK
value|8
end_define

begin_define
define|#
directive|define
name|RPM_QDSS_A_CLK
value|9
end_define

begin_define
define|#
directive|define
name|RPM_DAYTONA_FABRIC_CLK
value|10
end_define

begin_define
define|#
directive|define
name|RPM_DAYTONA_FABRIC_A_CLK
value|11
end_define

begin_define
define|#
directive|define
name|RPM_EBI1_CLK
value|12
end_define

begin_define
define|#
directive|define
name|RPM_EBI1_A_CLK
value|13
end_define

begin_define
define|#
directive|define
name|RPM_MM_FABRIC_CLK
value|14
end_define

begin_define
define|#
directive|define
name|RPM_MM_FABRIC_A_CLK
value|15
end_define

begin_define
define|#
directive|define
name|RPM_MMFPB_CLK
value|16
end_define

begin_define
define|#
directive|define
name|RPM_MMFPB_A_CLK
value|17
end_define

begin_define
define|#
directive|define
name|RPM_SYS_FABRIC_CLK
value|18
end_define

begin_define
define|#
directive|define
name|RPM_SYS_FABRIC_A_CLK
value|19
end_define

begin_define
define|#
directive|define
name|RPM_SFPB_CLK
value|20
end_define

begin_define
define|#
directive|define
name|RPM_SFPB_A_CLK
value|21
end_define

begin_comment
comment|/* SMD RPM clocks */
end_comment

begin_define
define|#
directive|define
name|RPM_SMD_XO_CLK_SRC
value|0
end_define

begin_define
define|#
directive|define
name|RPM_SMD_XO_A_CLK_SRC
value|1
end_define

begin_define
define|#
directive|define
name|RPM_SMD_PCNOC_CLK
value|2
end_define

begin_define
define|#
directive|define
name|RPM_SMD_PCNOC_A_CLK
value|3
end_define

begin_define
define|#
directive|define
name|RPM_SMD_SNOC_CLK
value|4
end_define

begin_define
define|#
directive|define
name|RPM_SMD_SNOC_A_CLK
value|5
end_define

begin_define
define|#
directive|define
name|RPM_SMD_BIMC_CLK
value|6
end_define

begin_define
define|#
directive|define
name|RPM_SMD_BIMC_A_CLK
value|7
end_define

begin_define
define|#
directive|define
name|RPM_SMD_QDSS_CLK
value|8
end_define

begin_define
define|#
directive|define
name|RPM_SMD_QDSS_A_CLK
value|9
end_define

begin_define
define|#
directive|define
name|RPM_SMD_BB_CLK1
value|10
end_define

begin_define
define|#
directive|define
name|RPM_SMD_BB_CLK1_A
value|11
end_define

begin_define
define|#
directive|define
name|RPM_SMD_BB_CLK2
value|12
end_define

begin_define
define|#
directive|define
name|RPM_SMD_BB_CLK2_A
value|13
end_define

begin_define
define|#
directive|define
name|RPM_SMD_RF_CLK1
value|14
end_define

begin_define
define|#
directive|define
name|RPM_SMD_RF_CLK1_A
value|15
end_define

begin_define
define|#
directive|define
name|RPM_SMD_RF_CLK2
value|16
end_define

begin_define
define|#
directive|define
name|RPM_SMD_RF_CLK2_A
value|17
end_define

begin_define
define|#
directive|define
name|RPM_SMD_BB_CLK1_PIN
value|18
end_define

begin_define
define|#
directive|define
name|RPM_SMD_BB_CLK1_A_PIN
value|19
end_define

begin_define
define|#
directive|define
name|RPM_SMD_BB_CLK2_PIN
value|20
end_define

begin_define
define|#
directive|define
name|RPM_SMD_BB_CLK2_A_PIN
value|21
end_define

begin_define
define|#
directive|define
name|RPM_SMD_RF_CLK1_PIN
value|22
end_define

begin_define
define|#
directive|define
name|RPM_SMD_RF_CLK1_A_PIN
value|23
end_define

begin_define
define|#
directive|define
name|RPM_SMD_RF_CLK2_PIN
value|24
end_define

begin_define
define|#
directive|define
name|RPM_SMD_RF_CLK2_A_PIN
value|25
end_define

begin_define
define|#
directive|define
name|RPM_SMD_PNOC_CLK
value|26
end_define

begin_define
define|#
directive|define
name|RPM_SMD_PNOC_A_CLK
value|27
end_define

begin_define
define|#
directive|define
name|RPM_SMD_CNOC_CLK
value|28
end_define

begin_define
define|#
directive|define
name|RPM_SMD_CNOC_A_CLK
value|29
end_define

begin_define
define|#
directive|define
name|RPM_SMD_MMSSNOC_AHB_CLK
value|30
end_define

begin_define
define|#
directive|define
name|RPM_SMD_MMSSNOC_AHB_A_CLK
value|31
end_define

begin_define
define|#
directive|define
name|RPM_SMD_GFX3D_CLK_SRC
value|32
end_define

begin_define
define|#
directive|define
name|RPM_SMD_GFX3D_A_CLK_SRC
value|33
end_define

begin_define
define|#
directive|define
name|RPM_SMD_OCMEMGX_CLK
value|34
end_define

begin_define
define|#
directive|define
name|RPM_SMD_OCMEMGX_A_CLK
value|35
end_define

begin_define
define|#
directive|define
name|RPM_SMD_CXO_D0
value|36
end_define

begin_define
define|#
directive|define
name|RPM_SMD_CXO_D0_A
value|37
end_define

begin_define
define|#
directive|define
name|RPM_SMD_CXO_D1
value|38
end_define

begin_define
define|#
directive|define
name|RPM_SMD_CXO_D1_A
value|39
end_define

begin_define
define|#
directive|define
name|RPM_SMD_CXO_A0
value|40
end_define

begin_define
define|#
directive|define
name|RPM_SMD_CXO_A0_A
value|41
end_define

begin_define
define|#
directive|define
name|RPM_SMD_CXO_A1
value|42
end_define

begin_define
define|#
directive|define
name|RPM_SMD_CXO_A1_A
value|43
end_define

begin_define
define|#
directive|define
name|RPM_SMD_CXO_A2
value|44
end_define

begin_define
define|#
directive|define
name|RPM_SMD_CXO_A2_A
value|45
end_define

begin_define
define|#
directive|define
name|RPM_SMD_DIV_CLK1
value|46
end_define

begin_define
define|#
directive|define
name|RPM_SMD_DIV_A_CLK1
value|47
end_define

begin_define
define|#
directive|define
name|RPM_SMD_DIV_CLK2
value|48
end_define

begin_define
define|#
directive|define
name|RPM_SMD_DIV_A_CLK2
value|49
end_define

begin_define
define|#
directive|define
name|RPM_SMD_DIFF_CLK
value|50
end_define

begin_define
define|#
directive|define
name|RPM_SMD_DIFF_A_CLK
value|51
end_define

begin_define
define|#
directive|define
name|RPM_SMD_CXO_D0_PIN
value|52
end_define

begin_define
define|#
directive|define
name|RPM_SMD_CXO_D0_A_PIN
value|53
end_define

begin_define
define|#
directive|define
name|RPM_SMD_CXO_D1_PIN
value|54
end_define

begin_define
define|#
directive|define
name|RPM_SMD_CXO_D1_A_PIN
value|55
end_define

begin_define
define|#
directive|define
name|RPM_SMD_CXO_A0_PIN
value|56
end_define

begin_define
define|#
directive|define
name|RPM_SMD_CXO_A0_A_PIN
value|57
end_define

begin_define
define|#
directive|define
name|RPM_SMD_CXO_A1_PIN
value|58
end_define

begin_define
define|#
directive|define
name|RPM_SMD_CXO_A1_A_PIN
value|59
end_define

begin_define
define|#
directive|define
name|RPM_SMD_CXO_A2_PIN
value|60
end_define

begin_define
define|#
directive|define
name|RPM_SMD_CXO_A2_A_PIN
value|61
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

