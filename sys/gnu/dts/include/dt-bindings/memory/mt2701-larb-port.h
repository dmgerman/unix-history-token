begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2015 MediaTek Inc.  * Author: Honghui Zhang<honghui.zhang@mediatek.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MT2701_LARB_PORT_H_
end_ifndef

begin_define
define|#
directive|define
name|_MT2701_LARB_PORT_H_
end_define

begin_comment
comment|/*  * Mediatek m4u generation 1 such as mt2701 has flat m4u port numbers,  * the first port's id for larb[N] would be the last port's id of larb[N - 1]  * plus one while larb[0]'s first port number is 0. The definition of  * MT2701_M4U_ID_LARBx is following HW register spec.  * But m4u generation 2 like mt8173 have different port number, it use fixed  * offset for each larb, the first port's id for larb[N] would be (N * 32).  */
end_comment

begin_define
define|#
directive|define
name|LARB0_PORT_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|LARB1_PORT_OFFSET
value|11
end_define

begin_define
define|#
directive|define
name|LARB2_PORT_OFFSET
value|21
end_define

begin_define
define|#
directive|define
name|LARB3_PORT_OFFSET
value|44
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_ID_LARB0
parameter_list|(
name|port
parameter_list|)
value|((port) + LARB0_PORT_OFFSET)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_ID_LARB1
parameter_list|(
name|port
parameter_list|)
value|((port) + LARB1_PORT_OFFSET)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_ID_LARB2
parameter_list|(
name|port
parameter_list|)
value|((port) + LARB2_PORT_OFFSET)
end_define

begin_comment
comment|/* Port define for larb0 */
end_comment

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_DISP_OVL_0
value|MT2701_M4U_ID_LARB0(0)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_DISP_RDMA1
value|MT2701_M4U_ID_LARB0(1)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_DISP_RDMA
value|MT2701_M4U_ID_LARB0(2)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_DISP_WDMA
value|MT2701_M4U_ID_LARB0(3)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_MM_CMDQ
value|MT2701_M4U_ID_LARB0(4)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_MDP_RDMA
value|MT2701_M4U_ID_LARB0(5)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_MDP_WDMA
value|MT2701_M4U_ID_LARB0(6)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_MDP_ROTO
value|MT2701_M4U_ID_LARB0(7)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_MDP_ROTCO
value|MT2701_M4U_ID_LARB0(8)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_MDP_ROTVO
value|MT2701_M4U_ID_LARB0(9)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_MDP_RDMA1
value|MT2701_M4U_ID_LARB0(10)
end_define

begin_comment
comment|/* Port define for larb1 */
end_comment

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VDEC_MC_EXT
value|MT2701_M4U_ID_LARB1(0)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VDEC_PP_EXT
value|MT2701_M4U_ID_LARB1(1)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VDEC_PPWRAP_EXT
value|MT2701_M4U_ID_LARB1(2)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VDEC_AVC_MV_EXT
value|MT2701_M4U_ID_LARB1(3)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VDEC_PRED_RD_EXT
value|MT2701_M4U_ID_LARB1(4)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VDEC_PRED_WR_EXT
value|MT2701_M4U_ID_LARB1(5)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VDEC_VLD_EXT
value|MT2701_M4U_ID_LARB1(6)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VDEC_VLD2_EXT
value|MT2701_M4U_ID_LARB1(7)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VDEC_TILE_EXT
value|MT2701_M4U_ID_LARB1(8)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VDEC_IMG_RESZ_EXT
value|MT2701_M4U_ID_LARB1(9)
end_define

begin_comment
comment|/* Port define for larb2 */
end_comment

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VENC_RCPU
value|MT2701_M4U_ID_LARB2(0)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VENC_REC_FRM
value|MT2701_M4U_ID_LARB2(1)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VENC_BSDMA
value|MT2701_M4U_ID_LARB2(2)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_JPGENC_RDMA
value|MT2701_M4U_ID_LARB2(3)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VENC_LT_RCPU
value|MT2701_M4U_ID_LARB2(4)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VENC_LT_REC_FRM
value|MT2701_M4U_ID_LARB2(5)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VENC_LT_BSDMA
value|MT2701_M4U_ID_LARB2(6)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_JPGDEC_BSDMA
value|MT2701_M4U_ID_LARB2(7)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VENC_SV_COMV
value|MT2701_M4U_ID_LARB2(8)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VENC_RD_COMV
value|MT2701_M4U_ID_LARB2(9)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_JPGENC_BSDMA
value|MT2701_M4U_ID_LARB2(10)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VENC_CUR_LUMA
value|MT2701_M4U_ID_LARB2(11)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VENC_CUR_CHROMA
value|MT2701_M4U_ID_LARB2(12)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VENC_REF_LUMA
value|MT2701_M4U_ID_LARB2(13)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VENC_REF_CHROMA
value|MT2701_M4U_ID_LARB2(14)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_IMG_RESZ
value|MT2701_M4U_ID_LARB2(15)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VENC_LT_SV_COMV
value|MT2701_M4U_ID_LARB2(16)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VENC_LT_RD_COMV
value|MT2701_M4U_ID_LARB2(17)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VENC_LT_CUR_LUMA
value|MT2701_M4U_ID_LARB2(18)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VENC_LT_CUR_CHROMA
value|MT2701_M4U_ID_LARB2(19)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VENC_LT_REF_LUMA
value|MT2701_M4U_ID_LARB2(20)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_VENC_LT_REF_CHROMA
value|MT2701_M4U_ID_LARB2(21)
end_define

begin_define
define|#
directive|define
name|MT2701_M4U_PORT_JPGDEC_WDMA
value|MT2701_M4U_ID_LARB2(22)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

