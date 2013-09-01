begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008 Advanced Micro Devices, Inc.  * Copyright 2008 Red Hat Inc.  * Copyright 2009 Jerome Glisse.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors: Dave Airlie  *          Alex Deucher  *          Jerome Glisse  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RS400D_H__
end_ifndef

begin_define
define|#
directive|define
name|__RS400D_H__
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
name|R_000148_MC_FB_LOCATION
value|0x000148
end_define

begin_define
define|#
directive|define
name|S_000148_MC_FB_START
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000148_MC_FB_START
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|C_000148_MC_FB_START
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|S_000148_MC_FB_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 16)
end_define

begin_define
define|#
directive|define
name|G_000148_MC_FB_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|C_000148_MC_FB_TOP
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|R_00015C_NB_TOM
value|0x00015C
end_define

begin_define
define|#
directive|define
name|S_00015C_MC_FB_START
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_00015C_MC_FB_START
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|C_00015C_MC_FB_START
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|S_00015C_MC_FB_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 16)
end_define

begin_define
define|#
directive|define
name|G_00015C_MC_FB_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|C_00015C_MC_FB_TOP
value|0x0000FFFF
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

