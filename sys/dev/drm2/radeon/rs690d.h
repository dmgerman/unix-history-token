begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008 Advanced Micro Devices, Inc.  * Copyright 2008 Red Hat Inc.  * Copyright 2009 Jerome Glisse.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors: Dave Airlie  *          Alex Deucher  *          Jerome Glisse  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RS690D_H__
end_ifndef

begin_define
define|#
directive|define
name|__RS690D_H__
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

begin_comment
comment|/* Registers */
end_comment

begin_define
define|#
directive|define
name|R_000078_MC_INDEX
value|0x000078
end_define

begin_define
define|#
directive|define
name|S_000078_MC_IND_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1FF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000078_MC_IND_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1FF)
end_define

begin_define
define|#
directive|define
name|C_000078_MC_IND_ADDR
value|0xFFFFFE00
end_define

begin_define
define|#
directive|define
name|S_000078_MC_IND_WR_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 9)
end_define

begin_define
define|#
directive|define
name|G_000078_MC_IND_WR_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 9)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000078_MC_IND_WR_EN
value|0xFFFFFDFF
end_define

begin_define
define|#
directive|define
name|R_00007C_MC_DATA
value|0x00007C
end_define

begin_define
define|#
directive|define
name|S_00007C_MC_DATA
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_00007C_MC_DATA
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_00007C_MC_DATA
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_0000F8_CONFIG_MEMSIZE
value|0x0000F8
end_define

begin_define
define|#
directive|define
name|S_0000F8_CONFIG_MEMSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0000F8_CONFIG_MEMSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_0000F8_CONFIG_MEMSIZE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_000134_HDP_FB_LOCATION
value|0x000134
end_define

begin_define
define|#
directive|define
name|S_000134_HDP_FB_START
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000134_HDP_FB_START
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|C_000134_HDP_FB_START
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|R_0007C0_CP_STAT
value|0x0007C0
end_define

begin_define
define|#
directive|define
name|S_0007C0_MRU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0007C0_MRU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_MRU_BUSY
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_0007C0_MWU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_0007C0_MWU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_MWU_BUSY
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|S_0007C0_RSIU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 2)
end_define

begin_define
define|#
directive|define
name|G_0007C0_RSIU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_RSIU_BUSY
value|0xFFFFFFFB
end_define

begin_define
define|#
directive|define
name|S_0007C0_RCIU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 3)
end_define

begin_define
define|#
directive|define
name|G_0007C0_RCIU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_RCIU_BUSY
value|0xFFFFFFF7
end_define

begin_define
define|#
directive|define
name|S_0007C0_CSF_PRIMARY_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 9)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CSF_PRIMARY_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 9)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CSF_PRIMARY_BUSY
value|0xFFFFFDFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_CSF_INDIRECT_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 10)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CSF_INDIRECT_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CSF_INDIRECT_BUSY
value|0xFFFFFBFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_CSQ_PRIMARY_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 11)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CSQ_PRIMARY_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CSQ_PRIMARY_BUSY
value|0xFFFFF7FF
end_define

begin_define
define|#
directive|define
name|S_0007C0_CSQ_INDIRECT_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 12)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CSQ_INDIRECT_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CSQ_INDIRECT_BUSY
value|0xFFFFEFFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_CSI_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 13)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CSI_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CSI_BUSY
value|0xFFFFDFFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_CSF_INDIRECT2_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 14)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CSF_INDIRECT2_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CSF_INDIRECT2_BUSY
value|0xFFFFBFFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_CSQ_INDIRECT2_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 15)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CSQ_INDIRECT2_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CSQ_INDIRECT2_BUSY
value|0xFFFF7FFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_GUIDMA_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 28)
end_define

begin_define
define|#
directive|define
name|G_0007C0_GUIDMA_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_GUIDMA_BUSY
value|0xEFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_VIDDMA_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 29)
end_define

begin_define
define|#
directive|define
name|G_0007C0_VIDDMA_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 29)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_VIDDMA_BUSY
value|0xDFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_CMDSTRM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 30)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CMDSTRM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 30)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CMDSTRM_BUSY
value|0xBFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_CP_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 31)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CP_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 31)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CP_BUSY
value|0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|R_000E40_RBBM_STATUS
value|0x000E40
end_define

begin_define
define|#
directive|define
name|S_000E40_CMDFIFO_AVAIL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7F)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000E40_CMDFIFO_AVAIL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7F)
end_define

begin_define
define|#
directive|define
name|C_000E40_CMDFIFO_AVAIL
value|0xFFFFFF80
end_define

begin_define
define|#
directive|define
name|S_000E40_HIRQ_ON_RBB
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 8)
end_define

begin_define
define|#
directive|define
name|G_000E40_HIRQ_ON_RBB
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_HIRQ_ON_RBB
value|0xFFFFFEFF
end_define

begin_define
define|#
directive|define
name|S_000E40_CPRQ_ON_RBB
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 9)
end_define

begin_define
define|#
directive|define
name|G_000E40_CPRQ_ON_RBB
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 9)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_CPRQ_ON_RBB
value|0xFFFFFDFF
end_define

begin_define
define|#
directive|define
name|S_000E40_CFRQ_ON_RBB
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 10)
end_define

begin_define
define|#
directive|define
name|G_000E40_CFRQ_ON_RBB
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_CFRQ_ON_RBB
value|0xFFFFFBFF
end_define

begin_define
define|#
directive|define
name|S_000E40_HIRQ_IN_RTBUF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 11)
end_define

begin_define
define|#
directive|define
name|G_000E40_HIRQ_IN_RTBUF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_HIRQ_IN_RTBUF
value|0xFFFFF7FF
end_define

begin_define
define|#
directive|define
name|S_000E40_CPRQ_IN_RTBUF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 12)
end_define

begin_define
define|#
directive|define
name|G_000E40_CPRQ_IN_RTBUF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_CPRQ_IN_RTBUF
value|0xFFFFEFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_CFRQ_IN_RTBUF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 13)
end_define

begin_define
define|#
directive|define
name|G_000E40_CFRQ_IN_RTBUF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_CFRQ_IN_RTBUF
value|0xFFFFDFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_CF_PIPE_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 14)
end_define

begin_define
define|#
directive|define
name|G_000E40_CF_PIPE_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_CF_PIPE_BUSY
value|0xFFFFBFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_ENG_EV_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 15)
end_define

begin_define
define|#
directive|define
name|G_000E40_ENG_EV_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_ENG_EV_BUSY
value|0xFFFF7FFF
end_define

begin_define
define|#
directive|define
name|S_000E40_CP_CMDSTRM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_000E40_CP_CMDSTRM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_CP_CMDSTRM_BUSY
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_E2_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 17)
end_define

begin_define
define|#
directive|define
name|G_000E40_E2_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 17)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_E2_BUSY
value|0xFFFDFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_RB2D_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 18)
end_define

begin_define
define|#
directive|define
name|G_000E40_RB2D_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 18)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_RB2D_BUSY
value|0xFFFBFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_RB3D_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 19)
end_define

begin_define
define|#
directive|define
name|G_000E40_RB3D_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_RB3D_BUSY
value|0xFFF7FFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_VAP_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 20)
end_define

begin_define
define|#
directive|define
name|G_000E40_VAP_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_VAP_BUSY
value|0xFFEFFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_RE_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 21)
end_define

begin_define
define|#
directive|define
name|G_000E40_RE_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_RE_BUSY
value|0xFFDFFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_TAM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 22)
end_define

begin_define
define|#
directive|define
name|G_000E40_TAM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 22)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_TAM_BUSY
value|0xFFBFFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_TDM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 23)
end_define

begin_define
define|#
directive|define
name|G_000E40_TDM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 23)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_TDM_BUSY
value|0xFF7FFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_PB_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|G_000E40_PB_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_PB_BUSY
value|0xFEFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_TIM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 25)
end_define

begin_define
define|#
directive|define
name|G_000E40_TIM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 25)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_TIM_BUSY
value|0xFDFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_GA_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 26)
end_define

begin_define
define|#
directive|define
name|G_000E40_GA_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 26)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_GA_BUSY
value|0xFBFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_CBA2D_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 27)
end_define

begin_define
define|#
directive|define
name|G_000E40_CBA2D_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 27)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_CBA2D_BUSY
value|0xF7FFFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_GUI_ACTIVE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 31)
end_define

begin_define
define|#
directive|define
name|G_000E40_GUI_ACTIVE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 31)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_GUI_ACTIVE
value|0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|R_006520_DC_LB_MEMORY_SPLIT
value|0x006520
end_define

begin_define
define|#
directive|define
name|S_006520_DC_LB_MEMORY_SPLIT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 0)
end_define

begin_define
define|#
directive|define
name|G_006520_DC_LB_MEMORY_SPLIT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_006520_DC_LB_MEMORY_SPLIT
value|0xFFFFFFFC
end_define

begin_define
define|#
directive|define
name|S_006520_DC_LB_MEMORY_SPLIT_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 2)
end_define

begin_define
define|#
directive|define
name|G_006520_DC_LB_MEMORY_SPLIT_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006520_DC_LB_MEMORY_SPLIT_MODE
value|0xFFFFFFFB
end_define

begin_define
define|#
directive|define
name|V_006520_DC_LB_MEMORY_SPLIT_D1HALF_D2HALF
value|0
end_define

begin_define
define|#
directive|define
name|V_006520_DC_LB_MEMORY_SPLIT_D1_3Q_D2_1Q
value|1
end_define

begin_define
define|#
directive|define
name|V_006520_DC_LB_MEMORY_SPLIT_D1_ONLY
value|2
end_define

begin_define
define|#
directive|define
name|V_006520_DC_LB_MEMORY_SPLIT_D1_1Q_D2_3Q
value|3
end_define

begin_define
define|#
directive|define
name|S_006520_DC_LB_DISP1_END_ADR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FF)<< 4)
end_define

begin_define
define|#
directive|define
name|G_006520_DC_LB_DISP1_END_ADR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x7FF)
end_define

begin_define
define|#
directive|define
name|C_006520_DC_LB_DISP1_END_ADR
value|0xFFFF800F
end_define

begin_define
define|#
directive|define
name|R_006548_D1MODE_PRIORITY_A_CNT
value|0x006548
end_define

begin_define
define|#
directive|define
name|S_006548_D1MODE_PRIORITY_MARK_A
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_006548_D1MODE_PRIORITY_MARK_A
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7FFF)
end_define

begin_define
define|#
directive|define
name|C_006548_D1MODE_PRIORITY_MARK_A
value|0xFFFF8000
end_define

begin_define
define|#
directive|define
name|S_006548_D1MODE_PRIORITY_A_OFF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_006548_D1MODE_PRIORITY_A_OFF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006548_D1MODE_PRIORITY_A_OFF
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|S_006548_D1MODE_PRIORITY_A_ALWAYS_ON
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 20)
end_define

begin_define
define|#
directive|define
name|G_006548_D1MODE_PRIORITY_A_ALWAYS_ON
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006548_D1MODE_PRIORITY_A_ALWAYS_ON
value|0xFFEFFFFF
end_define

begin_define
define|#
directive|define
name|S_006548_D1MODE_PRIORITY_A_FORCE_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|G_006548_D1MODE_PRIORITY_A_FORCE_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006548_D1MODE_PRIORITY_A_FORCE_MASK
value|0xFEFFFFFF
end_define

begin_define
define|#
directive|define
name|R_00654C_D1MODE_PRIORITY_B_CNT
value|0x00654C
end_define

begin_define
define|#
directive|define
name|S_00654C_D1MODE_PRIORITY_MARK_B
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_00654C_D1MODE_PRIORITY_MARK_B
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7FFF)
end_define

begin_define
define|#
directive|define
name|C_00654C_D1MODE_PRIORITY_MARK_B
value|0xFFFF8000
end_define

begin_define
define|#
directive|define
name|S_00654C_D1MODE_PRIORITY_B_OFF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_00654C_D1MODE_PRIORITY_B_OFF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00654C_D1MODE_PRIORITY_B_OFF
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|S_00654C_D1MODE_PRIORITY_B_ALWAYS_ON
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 20)
end_define

begin_define
define|#
directive|define
name|G_00654C_D1MODE_PRIORITY_B_ALWAYS_ON
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00654C_D1MODE_PRIORITY_B_ALWAYS_ON
value|0xFFEFFFFF
end_define

begin_define
define|#
directive|define
name|S_00654C_D1MODE_PRIORITY_B_FORCE_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|G_00654C_D1MODE_PRIORITY_B_FORCE_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00654C_D1MODE_PRIORITY_B_FORCE_MASK
value|0xFEFFFFFF
end_define

begin_define
define|#
directive|define
name|R_006C9C_DCP_CONTROL
value|0x006C9C
end_define

begin_define
define|#
directive|define
name|R_006D48_D2MODE_PRIORITY_A_CNT
value|0x006D48
end_define

begin_define
define|#
directive|define
name|S_006D48_D2MODE_PRIORITY_MARK_A
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_006D48_D2MODE_PRIORITY_MARK_A
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7FFF)
end_define

begin_define
define|#
directive|define
name|C_006D48_D2MODE_PRIORITY_MARK_A
value|0xFFFF8000
end_define

begin_define
define|#
directive|define
name|S_006D48_D2MODE_PRIORITY_A_OFF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_006D48_D2MODE_PRIORITY_A_OFF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006D48_D2MODE_PRIORITY_A_OFF
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|S_006D48_D2MODE_PRIORITY_A_ALWAYS_ON
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 20)
end_define

begin_define
define|#
directive|define
name|G_006D48_D2MODE_PRIORITY_A_ALWAYS_ON
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006D48_D2MODE_PRIORITY_A_ALWAYS_ON
value|0xFFEFFFFF
end_define

begin_define
define|#
directive|define
name|S_006D48_D2MODE_PRIORITY_A_FORCE_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|G_006D48_D2MODE_PRIORITY_A_FORCE_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006D48_D2MODE_PRIORITY_A_FORCE_MASK
value|0xFEFFFFFF
end_define

begin_define
define|#
directive|define
name|R_006D4C_D2MODE_PRIORITY_B_CNT
value|0x006D4C
end_define

begin_define
define|#
directive|define
name|S_006D4C_D2MODE_PRIORITY_MARK_B
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_006D4C_D2MODE_PRIORITY_MARK_B
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7FFF)
end_define

begin_define
define|#
directive|define
name|C_006D4C_D2MODE_PRIORITY_MARK_B
value|0xFFFF8000
end_define

begin_define
define|#
directive|define
name|S_006D4C_D2MODE_PRIORITY_B_OFF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_006D4C_D2MODE_PRIORITY_B_OFF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006D4C_D2MODE_PRIORITY_B_OFF
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|S_006D4C_D2MODE_PRIORITY_B_ALWAYS_ON
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 20)
end_define

begin_define
define|#
directive|define
name|G_006D4C_D2MODE_PRIORITY_B_ALWAYS_ON
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006D4C_D2MODE_PRIORITY_B_ALWAYS_ON
value|0xFFEFFFFF
end_define

begin_define
define|#
directive|define
name|S_006D4C_D2MODE_PRIORITY_B_FORCE_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|G_006D4C_D2MODE_PRIORITY_B_FORCE_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006D4C_D2MODE_PRIORITY_B_FORCE_MASK
value|0xFEFFFFFF
end_define

begin_define
define|#
directive|define
name|R_006D58_LB_MAX_REQ_OUTSTANDING
value|0x006D58
end_define

begin_define
define|#
directive|define
name|S_006D58_LB_D1_MAX_REQ_OUTSTANDING
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_006D58_LB_D1_MAX_REQ_OUTSTANDING
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_006D58_LB_D1_MAX_REQ_OUTSTANDING
value|0xFFFFFFF0
end_define

begin_define
define|#
directive|define
name|S_006D58_LB_D2_MAX_REQ_OUTSTANDING
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 16)
end_define

begin_define
define|#
directive|define
name|G_006D58_LB_D2_MAX_REQ_OUTSTANDING
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_006D58_LB_D2_MAX_REQ_OUTSTANDING
value|0xFFF0FFFF
end_define

begin_define
define|#
directive|define
name|R_000090_MC_SYSTEM_STATUS
value|0x000090
end_define

begin_define
define|#
directive|define
name|S_000090_MC_SYSTEM_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000090_MC_SYSTEM_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000090_MC_SYSTEM_IDLE
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_000090_MC_SEQUENCER_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_000090_MC_SEQUENCER_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000090_MC_SEQUENCER_IDLE
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|S_000090_MC_ARBITER_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 2)
end_define

begin_define
define|#
directive|define
name|G_000090_MC_ARBITER_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000090_MC_ARBITER_IDLE
value|0xFFFFFFFB
end_define

begin_define
define|#
directive|define
name|S_000090_MC_SELECT_PM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 3)
end_define

begin_define
define|#
directive|define
name|G_000090_MC_SELECT_PM
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000090_MC_SELECT_PM
value|0xFFFFFFF7
end_define

begin_define
define|#
directive|define
name|S_000090_RESERVED4
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 4)
end_define

begin_define
define|#
directive|define
name|G_000090_RESERVED4
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_000090_RESERVED4
value|0xFFFFFF0F
end_define

begin_define
define|#
directive|define
name|S_000090_RESERVED8
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 8)
end_define

begin_define
define|#
directive|define
name|G_000090_RESERVED8
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_000090_RESERVED8
value|0xFFFFF0FF
end_define

begin_define
define|#
directive|define
name|S_000090_RESERVED12
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 12)
end_define

begin_define
define|#
directive|define
name|G_000090_RESERVED12
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_000090_RESERVED12
value|0xFFFF0FFF
end_define

begin_define
define|#
directive|define
name|S_000090_MCA_INIT_EXECUTED
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_000090_MCA_INIT_EXECUTED
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000090_MCA_INIT_EXECUTED
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|S_000090_MCA_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 17)
end_define

begin_define
define|#
directive|define
name|G_000090_MCA_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 17)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000090_MCA_IDLE
value|0xFFFDFFFF
end_define

begin_define
define|#
directive|define
name|S_000090_MCA_SEQ_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 18)
end_define

begin_define
define|#
directive|define
name|G_000090_MCA_SEQ_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 18)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000090_MCA_SEQ_IDLE
value|0xFFFBFFFF
end_define

begin_define
define|#
directive|define
name|S_000090_MCA_ARB_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 19)
end_define

begin_define
define|#
directive|define
name|G_000090_MCA_ARB_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000090_MCA_ARB_IDLE
value|0xFFF7FFFF
end_define

begin_define
define|#
directive|define
name|S_000090_RESERVED20
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFF)<< 20)
end_define

begin_define
define|#
directive|define
name|G_000090_RESERVED20
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0xFFF)
end_define

begin_define
define|#
directive|define
name|C_000090_RESERVED20
value|0x000FFFFF
end_define

begin_define
define|#
directive|define
name|R_000100_MCCFG_FB_LOCATION
value|0x000100
end_define

begin_define
define|#
directive|define
name|S_000100_MC_FB_START
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000100_MC_FB_START
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|C_000100_MC_FB_START
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|S_000100_MC_FB_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 16)
end_define

begin_define
define|#
directive|define
name|G_000100_MC_FB_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|C_000100_MC_FB_TOP
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|R_000104_MC_INIT_MISC_LAT_TIMER
value|0x000104
end_define

begin_define
define|#
directive|define
name|S_000104_MC_CPR_INIT_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000104_MC_CPR_INIT_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_000104_MC_CPR_INIT_LAT
value|0xFFFFFFF0
end_define

begin_define
define|#
directive|define
name|S_000104_MC_VF_INIT_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 4)
end_define

begin_define
define|#
directive|define
name|G_000104_MC_VF_INIT_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_000104_MC_VF_INIT_LAT
value|0xFFFFFF0F
end_define

begin_define
define|#
directive|define
name|S_000104_MC_DISP0R_INIT_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 8)
end_define

begin_define
define|#
directive|define
name|G_000104_MC_DISP0R_INIT_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_000104_MC_DISP0R_INIT_LAT
value|0xFFFFF0FF
end_define

begin_define
define|#
directive|define
name|S_000104_MC_DISP1R_INIT_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 12)
end_define

begin_define
define|#
directive|define
name|G_000104_MC_DISP1R_INIT_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_000104_MC_DISP1R_INIT_LAT
value|0xFFFF0FFF
end_define

begin_define
define|#
directive|define
name|S_000104_MC_FIXED_INIT_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 16)
end_define

begin_define
define|#
directive|define
name|G_000104_MC_FIXED_INIT_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_000104_MC_FIXED_INIT_LAT
value|0xFFF0FFFF
end_define

begin_define
define|#
directive|define
name|S_000104_MC_E2R_INIT_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 20)
end_define

begin_define
define|#
directive|define
name|G_000104_MC_E2R_INIT_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_000104_MC_E2R_INIT_LAT
value|0xFF0FFFFF
end_define

begin_define
define|#
directive|define
name|S_000104_SAME_PAGE_PRIO
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 24)
end_define

begin_define
define|#
directive|define
name|G_000104_SAME_PAGE_PRIO
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_000104_SAME_PAGE_PRIO
value|0xF0FFFFFF
end_define

begin_define
define|#
directive|define
name|S_000104_MC_GLOBW_INIT_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 28)
end_define

begin_define
define|#
directive|define
name|G_000104_MC_GLOBW_INIT_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_000104_MC_GLOBW_INIT_LAT
value|0x0FFFFFFF
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

