begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2015-2016 MediaTek Inc.  * Author: Yong Wu<yong.wu@mediatek.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DTS_IOMMU_PORT_MT8173_H
end_ifndef

begin_define
define|#
directive|define
name|__DTS_IOMMU_PORT_MT8173_H
end_define

begin_define
define|#
directive|define
name|MTK_M4U_ID
parameter_list|(
name|larb
parameter_list|,
name|port
parameter_list|)
value|(((larb)<< 5) | (port))
end_define

begin_define
define|#
directive|define
name|M4U_LARB0_ID
value|0
end_define

begin_define
define|#
directive|define
name|M4U_LARB1_ID
value|1
end_define

begin_define
define|#
directive|define
name|M4U_LARB2_ID
value|2
end_define

begin_define
define|#
directive|define
name|M4U_LARB3_ID
value|3
end_define

begin_define
define|#
directive|define
name|M4U_LARB4_ID
value|4
end_define

begin_define
define|#
directive|define
name|M4U_LARB5_ID
value|5
end_define

begin_comment
comment|/* larb0 */
end_comment

begin_define
define|#
directive|define
name|M4U_PORT_DISP_OVL0
value|MTK_M4U_ID(M4U_LARB0_ID, 0)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_DISP_RDMA0
value|MTK_M4U_ID(M4U_LARB0_ID, 1)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_DISP_WDMA0
value|MTK_M4U_ID(M4U_LARB0_ID, 2)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_DISP_OD_R
value|MTK_M4U_ID(M4U_LARB0_ID, 3)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_DISP_OD_W
value|MTK_M4U_ID(M4U_LARB0_ID, 4)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_MDP_RDMA0
value|MTK_M4U_ID(M4U_LARB0_ID, 5)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_MDP_WDMA
value|MTK_M4U_ID(M4U_LARB0_ID, 6)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_MDP_WROT0
value|MTK_M4U_ID(M4U_LARB0_ID, 7)
end_define

begin_comment
comment|/* larb1 */
end_comment

begin_define
define|#
directive|define
name|M4U_PORT_HW_VDEC_MC_EXT
value|MTK_M4U_ID(M4U_LARB1_ID, 0)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_HW_VDEC_PP_EXT
value|MTK_M4U_ID(M4U_LARB1_ID, 1)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_HW_VDEC_UFO_EXT
value|MTK_M4U_ID(M4U_LARB1_ID, 2)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_HW_VDEC_VLD_EXT
value|MTK_M4U_ID(M4U_LARB1_ID, 3)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_HW_VDEC_VLD2_EXT
value|MTK_M4U_ID(M4U_LARB1_ID, 4)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_HW_VDEC_AVC_MV_EXT
value|MTK_M4U_ID(M4U_LARB1_ID, 5)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_HW_VDEC_PRED_RD_EXT
value|MTK_M4U_ID(M4U_LARB1_ID, 6)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_HW_VDEC_PRED_WR_EXT
value|MTK_M4U_ID(M4U_LARB1_ID, 7)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_HW_VDEC_PPWRAP_EXT
value|MTK_M4U_ID(M4U_LARB1_ID, 8)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_HW_VDEC_TILE
value|MTK_M4U_ID(M4U_LARB1_ID, 9)
end_define

begin_comment
comment|/* larb2 */
end_comment

begin_define
define|#
directive|define
name|M4U_PORT_IMGO
value|MTK_M4U_ID(M4U_LARB2_ID, 0)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_RRZO
value|MTK_M4U_ID(M4U_LARB2_ID, 1)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_AAO
value|MTK_M4U_ID(M4U_LARB2_ID, 2)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_LCSO
value|MTK_M4U_ID(M4U_LARB2_ID, 3)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_ESFKO
value|MTK_M4U_ID(M4U_LARB2_ID, 4)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_IMGO_D
value|MTK_M4U_ID(M4U_LARB2_ID, 5)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_LSCI
value|MTK_M4U_ID(M4U_LARB2_ID, 6)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_LSCI_D
value|MTK_M4U_ID(M4U_LARB2_ID, 7)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_BPCI
value|MTK_M4U_ID(M4U_LARB2_ID, 8)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_BPCI_D
value|MTK_M4U_ID(M4U_LARB2_ID, 9)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_UFDI
value|MTK_M4U_ID(M4U_LARB2_ID, 10)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_IMGI
value|MTK_M4U_ID(M4U_LARB2_ID, 11)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_IMG2O
value|MTK_M4U_ID(M4U_LARB2_ID, 12)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_IMG3O
value|MTK_M4U_ID(M4U_LARB2_ID, 13)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_VIPI
value|MTK_M4U_ID(M4U_LARB2_ID, 14)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_VIP2I
value|MTK_M4U_ID(M4U_LARB2_ID, 15)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_VIP3I
value|MTK_M4U_ID(M4U_LARB2_ID, 16)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_LCEI
value|MTK_M4U_ID(M4U_LARB2_ID, 17)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_RB
value|MTK_M4U_ID(M4U_LARB2_ID, 18)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_RP
value|MTK_M4U_ID(M4U_LARB2_ID, 19)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_WR
value|MTK_M4U_ID(M4U_LARB2_ID, 20)
end_define

begin_comment
comment|/* larb3 */
end_comment

begin_define
define|#
directive|define
name|M4U_PORT_VENC_RCPU
value|MTK_M4U_ID(M4U_LARB3_ID, 0)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_VENC_REC
value|MTK_M4U_ID(M4U_LARB3_ID, 1)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_VENC_BSDMA
value|MTK_M4U_ID(M4U_LARB3_ID, 2)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_VENC_SV_COMV
value|MTK_M4U_ID(M4U_LARB3_ID, 3)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_VENC_RD_COMV
value|MTK_M4U_ID(M4U_LARB3_ID, 4)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_JPGENC_RDMA
value|MTK_M4U_ID(M4U_LARB3_ID, 5)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_JPGENC_BSDMA
value|MTK_M4U_ID(M4U_LARB3_ID, 6)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_JPGDEC_WDMA
value|MTK_M4U_ID(M4U_LARB3_ID, 7)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_JPGDEC_BSDMA
value|MTK_M4U_ID(M4U_LARB3_ID, 8)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_VENC_CUR_LUMA
value|MTK_M4U_ID(M4U_LARB3_ID, 9)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_VENC_CUR_CHROMA
value|MTK_M4U_ID(M4U_LARB3_ID, 10)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_VENC_REF_LUMA
value|MTK_M4U_ID(M4U_LARB3_ID, 11)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_VENC_REF_CHROMA
value|MTK_M4U_ID(M4U_LARB3_ID, 12)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_VENC_NBM_RDMA
value|MTK_M4U_ID(M4U_LARB3_ID, 13)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_VENC_NBM_WDMA
value|MTK_M4U_ID(M4U_LARB3_ID, 14)
end_define

begin_comment
comment|/* larb4 */
end_comment

begin_define
define|#
directive|define
name|M4U_PORT_DISP_OVL1
value|MTK_M4U_ID(M4U_LARB4_ID, 0)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_DISP_RDMA1
value|MTK_M4U_ID(M4U_LARB4_ID, 1)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_DISP_RDMA2
value|MTK_M4U_ID(M4U_LARB4_ID, 2)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_DISP_WDMA1
value|MTK_M4U_ID(M4U_LARB4_ID, 3)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_MDP_RDMA1
value|MTK_M4U_ID(M4U_LARB4_ID, 4)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_MDP_WROT1
value|MTK_M4U_ID(M4U_LARB4_ID, 5)
end_define

begin_comment
comment|/* larb5 */
end_comment

begin_define
define|#
directive|define
name|M4U_PORT_VENC_RCPU_SET2
value|MTK_M4U_ID(M4U_LARB5_ID, 0)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_VENC_REC_FRM_SET2
value|MTK_M4U_ID(M4U_LARB5_ID, 1)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_VENC_REF_LUMA_SET2
value|MTK_M4U_ID(M4U_LARB5_ID, 2)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_VENC_REC_CHROMA_SET2
value|MTK_M4U_ID(M4U_LARB5_ID, 3)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_VENC_BSDMA_SET2
value|MTK_M4U_ID(M4U_LARB5_ID, 4)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_VENC_CUR_LUMA_SET2
value|MTK_M4U_ID(M4U_LARB5_ID, 5)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_VENC_CUR_CHROMA_SET2
value|MTK_M4U_ID(M4U_LARB5_ID, 6)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_VENC_RD_COMA_SET2
value|MTK_M4U_ID(M4U_LARB5_ID, 7)
end_define

begin_define
define|#
directive|define
name|M4U_PORT_VENC_SV_COMA_SET2
value|MTK_M4U_ID(M4U_LARB5_ID, 8)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

