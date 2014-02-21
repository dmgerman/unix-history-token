begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008 Advanced Micro Devices, Inc.  * Copyright 2008 Red Hat Inc.  * Copyright 2009 Jerome Glisse.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors: Dave Airlie  *          Alex Deucher  *          Jerome Glisse  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RS600D_H__
end_ifndef

begin_define
define|#
directive|define
name|__RS600D_H__
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
name|R_000040_GEN_INT_CNTL
value|0x000040
end_define

begin_define
define|#
directive|define
name|S_000040_SCRATCH_INT_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 18)
end_define

begin_define
define|#
directive|define
name|G_000040_SCRATCH_INT_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 18)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_SCRATCH_INT_MASK
value|0xFFFBFFFF
end_define

begin_define
define|#
directive|define
name|S_000040_GUI_IDLE_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 19)
end_define

begin_define
define|#
directive|define
name|G_000040_GUI_IDLE_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_GUI_IDLE_MASK
value|0xFFF7FFFF
end_define

begin_define
define|#
directive|define
name|S_000040_DMA_VIPH1_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 13)
end_define

begin_define
define|#
directive|define
name|G_000040_DMA_VIPH1_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_DMA_VIPH1_INT_EN
value|0xFFFFDFFF
end_define

begin_define
define|#
directive|define
name|S_000040_DMA_VIPH2_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 14)
end_define

begin_define
define|#
directive|define
name|G_000040_DMA_VIPH2_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_DMA_VIPH2_INT_EN
value|0xFFFFBFFF
end_define

begin_define
define|#
directive|define
name|S_000040_DMA_VIPH3_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 15)
end_define

begin_define
define|#
directive|define
name|G_000040_DMA_VIPH3_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_DMA_VIPH3_INT_EN
value|0xFFFF7FFF
end_define

begin_define
define|#
directive|define
name|S_000040_I2C_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 17)
end_define

begin_define
define|#
directive|define
name|G_000040_I2C_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 17)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_I2C_INT_EN
value|0xFFFDFFFF
end_define

begin_define
define|#
directive|define
name|S_000040_GUI_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 19)
end_define

begin_define
define|#
directive|define
name|G_000040_GUI_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_GUI_IDLE
value|0xFFF7FFFF
end_define

begin_define
define|#
directive|define
name|S_000040_VIPH_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|G_000040_VIPH_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_VIPH_INT_EN
value|0xFEFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000040_SW_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 25)
end_define

begin_define
define|#
directive|define
name|G_000040_SW_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 25)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_SW_INT_EN
value|0xFDFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000040_GEYSERVILLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 27)
end_define

begin_define
define|#
directive|define
name|G_000040_GEYSERVILLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 27)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_GEYSERVILLE
value|0xF7FFFFFF
end_define

begin_define
define|#
directive|define
name|S_000040_HDCP_AUTHORIZED_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 28)
end_define

begin_define
define|#
directive|define
name|G_000040_HDCP_AUTHORIZED_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_HDCP_AUTHORIZED_INT
value|0xEFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000040_DVI_I2C_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 29)
end_define

begin_define
define|#
directive|define
name|G_000040_DVI_I2C_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 29)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_DVI_I2C_INT
value|0xDFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000040_GUIDMA
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 30)
end_define

begin_define
define|#
directive|define
name|G_000040_GUIDMA
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 30)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_GUIDMA
value|0xBFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000040_VIDDMA
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 31)
end_define

begin_define
define|#
directive|define
name|G_000040_VIDDMA
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 31)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_VIDDMA
value|0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|R_000044_GEN_INT_STATUS
value|0x000044
end_define

begin_define
define|#
directive|define
name|S_000044_DISPLAY_INT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000044_DISPLAY_INT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_DISPLAY_INT_STAT
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_000044_VGA_INT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_000044_VGA_INT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_VGA_INT_STAT
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|S_000044_CAP0_INT_ACTIVE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 8)
end_define

begin_define
define|#
directive|define
name|G_000044_CAP0_INT_ACTIVE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_CAP0_INT_ACTIVE
value|0xFFFFFEFF
end_define

begin_define
define|#
directive|define
name|S_000044_DMA_VIPH0_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 12)
end_define

begin_define
define|#
directive|define
name|G_000044_DMA_VIPH0_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_DMA_VIPH0_INT
value|0xFFFFEFFF
end_define

begin_define
define|#
directive|define
name|S_000044_DMA_VIPH1_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 13)
end_define

begin_define
define|#
directive|define
name|G_000044_DMA_VIPH1_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_DMA_VIPH1_INT
value|0xFFFFDFFF
end_define

begin_define
define|#
directive|define
name|S_000044_DMA_VIPH2_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 14)
end_define

begin_define
define|#
directive|define
name|G_000044_DMA_VIPH2_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_DMA_VIPH2_INT
value|0xFFFFBFFF
end_define

begin_define
define|#
directive|define
name|S_000044_DMA_VIPH3_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 15)
end_define

begin_define
define|#
directive|define
name|G_000044_DMA_VIPH3_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_DMA_VIPH3_INT
value|0xFFFF7FFF
end_define

begin_define
define|#
directive|define
name|S_000044_MC_PROBE_FAULT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_000044_MC_PROBE_FAULT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_MC_PROBE_FAULT_STAT
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_I2C_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 17)
end_define

begin_define
define|#
directive|define
name|G_000044_I2C_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 17)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_I2C_INT
value|0xFFFDFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_SCRATCH_INT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 18)
end_define

begin_define
define|#
directive|define
name|G_000044_SCRATCH_INT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 18)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_SCRATCH_INT_STAT
value|0xFFFBFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_GUI_IDLE_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 19)
end_define

begin_define
define|#
directive|define
name|G_000044_GUI_IDLE_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_GUI_IDLE_STAT
value|0xFFF7FFFF
end_define

begin_define
define|#
directive|define
name|S_000044_ATI_OVERDRIVE_INT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 20)
end_define

begin_define
define|#
directive|define
name|G_000044_ATI_OVERDRIVE_INT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_ATI_OVERDRIVE_INT_STAT
value|0xFFEFFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_MC_PROTECTION_FAULT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 21)
end_define

begin_define
define|#
directive|define
name|G_000044_MC_PROTECTION_FAULT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_MC_PROTECTION_FAULT_STAT
value|0xFFDFFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_RBBM_READ_INT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 22)
end_define

begin_define
define|#
directive|define
name|G_000044_RBBM_READ_INT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 22)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_RBBM_READ_INT_STAT
value|0xFFBFFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_CB_CONTEXT_SWITCH_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 23)
end_define

begin_define
define|#
directive|define
name|G_000044_CB_CONTEXT_SWITCH_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 23)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_CB_CONTEXT_SWITCH_STAT
value|0xFF7FFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_VIPH_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|G_000044_VIPH_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_VIPH_INT
value|0xFEFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_SW_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 25)
end_define

begin_define
define|#
directive|define
name|G_000044_SW_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 25)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_SW_INT
value|0xFDFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_SW_INT_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 26)
end_define

begin_define
define|#
directive|define
name|G_000044_SW_INT_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 26)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_SW_INT_SET
value|0xFBFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_IDCT_INT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 27)
end_define

begin_define
define|#
directive|define
name|G_000044_IDCT_INT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 27)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_IDCT_INT_STAT
value|0xF7FFFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_GUIDMA_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 30)
end_define

begin_define
define|#
directive|define
name|G_000044_GUIDMA_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 30)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_GUIDMA_STAT
value|0xBFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_VIDDMA_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 31)
end_define

begin_define
define|#
directive|define
name|G_000044_VIDDMA_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 31)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_VIDDMA_STAT
value|0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|R_00004C_BUS_CNTL
value|0x00004C
end_define

begin_define
define|#
directive|define
name|S_00004C_BUS_MASTER_DIS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 14)
end_define

begin_define
define|#
directive|define
name|G_00004C_BUS_MASTER_DIS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00004C_BUS_MASTER_DIS
value|0xFFFFBFFF
end_define

begin_define
define|#
directive|define
name|S_00004C_BUS_MSI_REARM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 20)
end_define

begin_define
define|#
directive|define
name|G_00004C_BUS_MSI_REARM
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00004C_BUS_MSI_REARM
value|0xFFEFFFFF
end_define

begin_define
define|#
directive|define
name|R_000070_MC_IND_INDEX
value|0x000070
end_define

begin_define
define|#
directive|define
name|S_000070_MC_IND_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000070_MC_IND_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|C_000070_MC_IND_ADDR
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|S_000070_MC_IND_SEQ_RBS_0
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_000070_MC_IND_SEQ_RBS_0
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000070_MC_IND_SEQ_RBS_0
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|S_000070_MC_IND_SEQ_RBS_1
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 17)
end_define

begin_define
define|#
directive|define
name|G_000070_MC_IND_SEQ_RBS_1
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 17)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000070_MC_IND_SEQ_RBS_1
value|0xFFFDFFFF
end_define

begin_define
define|#
directive|define
name|S_000070_MC_IND_SEQ_RBS_2
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 18)
end_define

begin_define
define|#
directive|define
name|G_000070_MC_IND_SEQ_RBS_2
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 18)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000070_MC_IND_SEQ_RBS_2
value|0xFFFBFFFF
end_define

begin_define
define|#
directive|define
name|S_000070_MC_IND_SEQ_RBS_3
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 19)
end_define

begin_define
define|#
directive|define
name|G_000070_MC_IND_SEQ_RBS_3
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000070_MC_IND_SEQ_RBS_3
value|0xFFF7FFFF
end_define

begin_define
define|#
directive|define
name|S_000070_MC_IND_AIC_RBS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 20)
end_define

begin_define
define|#
directive|define
name|G_000070_MC_IND_AIC_RBS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000070_MC_IND_AIC_RBS
value|0xFFEFFFFF
end_define

begin_define
define|#
directive|define
name|S_000070_MC_IND_CITF_ARB0
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 21)
end_define

begin_define
define|#
directive|define
name|G_000070_MC_IND_CITF_ARB0
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000070_MC_IND_CITF_ARB0
value|0xFFDFFFFF
end_define

begin_define
define|#
directive|define
name|S_000070_MC_IND_CITF_ARB1
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 22)
end_define

begin_define
define|#
directive|define
name|G_000070_MC_IND_CITF_ARB1
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 22)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000070_MC_IND_CITF_ARB1
value|0xFFBFFFFF
end_define

begin_define
define|#
directive|define
name|S_000070_MC_IND_WR_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 23)
end_define

begin_define
define|#
directive|define
name|G_000070_MC_IND_WR_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 23)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000070_MC_IND_WR_EN
value|0xFF7FFFFF
end_define

begin_define
define|#
directive|define
name|S_000070_MC_IND_RD_INV
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|G_000070_MC_IND_RD_INV
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000070_MC_IND_RD_INV
value|0xFEFFFFFF
end_define

begin_define
define|#
directive|define
name|R_000074_MC_IND_DATA
value|0x000074
end_define

begin_define
define|#
directive|define
name|S_000074_MC_IND_DATA
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000074_MC_IND_DATA
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_000074_MC_IND_DATA
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_0000F0_RBBM_SOFT_RESET
value|0x0000F0
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_CP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_CP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_CP
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_HI
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_HI
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_HI
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_VAP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 2)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_VAP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_VAP
value|0xFFFFFFFB
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_RE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 3)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_RE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_RE
value|0xFFFFFFF7
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_PP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 4)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_PP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_PP
value|0xFFFFFFEF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_E2
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 5)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_E2
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_E2
value|0xFFFFFFDF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_RB
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 6)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_RB
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_RB
value|0xFFFFFFBF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_HDP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 7)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_HDP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 7)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_HDP
value|0xFFFFFF7F
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_MC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 8)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_MC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_MC
value|0xFFFFFEFF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_AIC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 9)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_AIC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 9)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_AIC
value|0xFFFFFDFF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_VIP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 10)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_VIP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_VIP
value|0xFFFFFBFF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_DISP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 11)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_DISP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_DISP
value|0xFFFFF7FF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_CG
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 12)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_CG
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_CG
value|0xFFFFEFFF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_GA
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 13)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_GA
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_GA
value|0xFFFFDFFF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_IDCT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 14)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_IDCT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_IDCT
value|0xFFFFBFFF
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
name|R_0060A4_D1CRTC_STATUS_FRAME_COUNT
value|0x0060A4
end_define

begin_define
define|#
directive|define
name|S_0060A4_D1CRTC_FRAME_COUNT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0060A4_D1CRTC_FRAME_COUNT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_0060A4_D1CRTC_FRAME_COUNT
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|R_006534_D1MODE_VBLANK_STATUS
value|0x006534
end_define

begin_define
define|#
directive|define
name|S_006534_D1MODE_VBLANK_OCCURRED
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_006534_D1MODE_VBLANK_OCCURRED
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006534_D1MODE_VBLANK_OCCURRED
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_006534_D1MODE_VBLANK_ACK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 4)
end_define

begin_define
define|#
directive|define
name|G_006534_D1MODE_VBLANK_ACK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006534_D1MODE_VBLANK_ACK
value|0xFFFFFFEF
end_define

begin_define
define|#
directive|define
name|S_006534_D1MODE_VBLANK_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 12)
end_define

begin_define
define|#
directive|define
name|G_006534_D1MODE_VBLANK_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006534_D1MODE_VBLANK_STAT
value|0xFFFFEFFF
end_define

begin_define
define|#
directive|define
name|S_006534_D1MODE_VBLANK_INTERRUPT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_006534_D1MODE_VBLANK_INTERRUPT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006534_D1MODE_VBLANK_INTERRUPT
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|R_006540_DxMODE_INT_MASK
value|0x006540
end_define

begin_define
define|#
directive|define
name|S_006540_D1MODE_VBLANK_INT_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_006540_D1MODE_VBLANK_INT_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006540_D1MODE_VBLANK_INT_MASK
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_006540_D1MODE_VLINE_INT_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 4)
end_define

begin_define
define|#
directive|define
name|G_006540_D1MODE_VLINE_INT_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006540_D1MODE_VLINE_INT_MASK
value|0xFFFFFFEF
end_define

begin_define
define|#
directive|define
name|S_006540_D2MODE_VBLANK_INT_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 8)
end_define

begin_define
define|#
directive|define
name|G_006540_D2MODE_VBLANK_INT_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006540_D2MODE_VBLANK_INT_MASK
value|0xFFFFFEFF
end_define

begin_define
define|#
directive|define
name|S_006540_D2MODE_VLINE_INT_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 12)
end_define

begin_define
define|#
directive|define
name|G_006540_D2MODE_VLINE_INT_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006540_D2MODE_VLINE_INT_MASK
value|0xFFFFEFFF
end_define

begin_define
define|#
directive|define
name|S_006540_D1MODE_VBLANK_CP_SEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 30)
end_define

begin_define
define|#
directive|define
name|G_006540_D1MODE_VBLANK_CP_SEL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 30)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006540_D1MODE_VBLANK_CP_SEL
value|0xBFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_006540_D2MODE_VBLANK_CP_SEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 31)
end_define

begin_define
define|#
directive|define
name|G_006540_D2MODE_VBLANK_CP_SEL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 31)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006540_D2MODE_VBLANK_CP_SEL
value|0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|R_0068A4_D2CRTC_STATUS_FRAME_COUNT
value|0x0068A4
end_define

begin_define
define|#
directive|define
name|S_0068A4_D2CRTC_FRAME_COUNT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0068A4_D2CRTC_FRAME_COUNT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_0068A4_D2CRTC_FRAME_COUNT
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|R_006D34_D2MODE_VBLANK_STATUS
value|0x006D34
end_define

begin_define
define|#
directive|define
name|S_006D34_D2MODE_VBLANK_OCCURRED
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_006D34_D2MODE_VBLANK_OCCURRED
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006D34_D2MODE_VBLANK_OCCURRED
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_006D34_D2MODE_VBLANK_ACK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 4)
end_define

begin_define
define|#
directive|define
name|G_006D34_D2MODE_VBLANK_ACK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006D34_D2MODE_VBLANK_ACK
value|0xFFFFFFEF
end_define

begin_define
define|#
directive|define
name|S_006D34_D2MODE_VBLANK_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 12)
end_define

begin_define
define|#
directive|define
name|G_006D34_D2MODE_VBLANK_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006D34_D2MODE_VBLANK_STAT
value|0xFFFFEFFF
end_define

begin_define
define|#
directive|define
name|S_006D34_D2MODE_VBLANK_INTERRUPT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_006D34_D2MODE_VBLANK_INTERRUPT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_006D34_D2MODE_VBLANK_INTERRUPT
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|R_007EDC_DISP_INTERRUPT_STATUS
value|0x007EDC
end_define

begin_define
define|#
directive|define
name|S_007EDC_LB_D1_VBLANK_INTERRUPT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 4)
end_define

begin_define
define|#
directive|define
name|G_007EDC_LB_D1_VBLANK_INTERRUPT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_007EDC_LB_D1_VBLANK_INTERRUPT
value|0xFFFFFFEF
end_define

begin_define
define|#
directive|define
name|S_007EDC_LB_D2_VBLANK_INTERRUPT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 5)
end_define

begin_define
define|#
directive|define
name|G_007EDC_LB_D2_VBLANK_INTERRUPT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_007EDC_LB_D2_VBLANK_INTERRUPT
value|0xFFFFFFDF
end_define

begin_define
define|#
directive|define
name|S_007EDC_DACA_AUTODETECT_INTERRUPT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_007EDC_DACA_AUTODETECT_INTERRUPT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_007EDC_DACA_AUTODETECT_INTERRUPT
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|S_007EDC_DACB_AUTODETECT_INTERRUPT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 17)
end_define

begin_define
define|#
directive|define
name|G_007EDC_DACB_AUTODETECT_INTERRUPT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 17)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_007EDC_DACB_AUTODETECT_INTERRUPT
value|0xFFFDFFFF
end_define

begin_define
define|#
directive|define
name|S_007EDC_DC_HOT_PLUG_DETECT1_INTERRUPT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 18)
end_define

begin_define
define|#
directive|define
name|G_007EDC_DC_HOT_PLUG_DETECT1_INTERRUPT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 18)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_007EDC_DC_HOT_PLUG_DETECT1_INTERRUPT
value|0xFFFBFFFF
end_define

begin_define
define|#
directive|define
name|S_007EDC_DC_HOT_PLUG_DETECT2_INTERRUPT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 19)
end_define

begin_define
define|#
directive|define
name|G_007EDC_DC_HOT_PLUG_DETECT2_INTERRUPT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_007EDC_DC_HOT_PLUG_DETECT2_INTERRUPT
value|0xFFF7FFFF
end_define

begin_define
define|#
directive|define
name|R_007828_DACA_AUTODETECT_CONTROL
value|0x007828
end_define

begin_define
define|#
directive|define
name|S_007828_DACA_AUTODETECT_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 0)
end_define

begin_define
define|#
directive|define
name|G_007828_DACA_AUTODETECT_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_007828_DACA_AUTODETECT_MODE
value|0xFFFFFFFC
end_define

begin_define
define|#
directive|define
name|S_007828_DACA_AUTODETECT_FRAME_TIME_COUNTER
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 8)
end_define

begin_define
define|#
directive|define
name|G_007828_DACA_AUTODETECT_FRAME_TIME_COUNTER
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|C_007828_DACA_AUTODETECT_FRAME_TIME_COUNTER
value|0xFFFF00FF
end_define

begin_define
define|#
directive|define
name|S_007828_DACA_AUTODETECT_CHECK_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 16)
end_define

begin_define
define|#
directive|define
name|G_007828_DACA_AUTODETECT_CHECK_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_007828_DACA_AUTODETECT_CHECK_MASK
value|0xFFFCFFFF
end_define

begin_define
define|#
directive|define
name|R_007838_DACA_AUTODETECT_INT_CONTROL
value|0x007838
end_define

begin_define
define|#
directive|define
name|S_007838_DACA_AUTODETECT_ACK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|C_007838_DACA_DACA_AUTODETECT_ACK
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_007838_DACA_AUTODETECT_INT_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_007838_DACA_AUTODETECT_INT_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_007838_DACA_AUTODETECT_INT_ENABLE
value|0xFFFCFFFF
end_define

begin_define
define|#
directive|define
name|R_007A28_DACB_AUTODETECT_CONTROL
value|0x007A28
end_define

begin_define
define|#
directive|define
name|S_007A28_DACB_AUTODETECT_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 0)
end_define

begin_define
define|#
directive|define
name|G_007A28_DACB_AUTODETECT_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_007A28_DACB_AUTODETECT_MODE
value|0xFFFFFFFC
end_define

begin_define
define|#
directive|define
name|S_007A28_DACB_AUTODETECT_FRAME_TIME_COUNTER
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff)<< 8)
end_define

begin_define
define|#
directive|define
name|G_007A28_DACB_AUTODETECT_FRAME_TIME_COUNTER
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|C_007A28_DACB_AUTODETECT_FRAME_TIME_COUNTER
value|0xFFFF00FF
end_define

begin_define
define|#
directive|define
name|S_007A28_DACB_AUTODETECT_CHECK_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 16)
end_define

begin_define
define|#
directive|define
name|G_007A28_DACB_AUTODETECT_CHECK_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_007A28_DACB_AUTODETECT_CHECK_MASK
value|0xFFFCFFFF
end_define

begin_define
define|#
directive|define
name|R_007A38_DACB_AUTODETECT_INT_CONTROL
value|0x007A38
end_define

begin_define
define|#
directive|define
name|S_007A38_DACB_AUTODETECT_ACK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|C_007A38_DACB_DACA_AUTODETECT_ACK
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_007A38_DACB_AUTODETECT_INT_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_007A38_DACB_AUTODETECT_INT_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_007A38_DACB_AUTODETECT_INT_ENABLE
value|0xFFFCFFFF
end_define

begin_define
define|#
directive|define
name|R_007D00_DC_HOT_PLUG_DETECT1_CONTROL
value|0x007D00
end_define

begin_define
define|#
directive|define
name|S_007D00_DC_HOT_PLUG_DETECT1_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_007D00_DC_HOT_PLUG_DETECT1_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_007D00_DC_HOT_PLUG_DETECT1_EN
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|R_007D04_DC_HOT_PLUG_DETECT1_INT_STATUS
value|0x007D04
end_define

begin_define
define|#
directive|define
name|S_007D04_DC_HOT_PLUG_DETECT1_INT_STATUS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_007D04_DC_HOT_PLUG_DETECT1_INT_STATUS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_007D04_DC_HOT_PLUG_DETECT1_INT_STATUS
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_007D04_DC_HOT_PLUG_DETECT1_SENSE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_007D04_DC_HOT_PLUG_DETECT1_SENSE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_007D04_DC_HOT_PLUG_DETECT1_SENSE
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|R_007D08_DC_HOT_PLUG_DETECT1_INT_CONTROL
value|0x007D08
end_define

begin_define
define|#
directive|define
name|S_007D08_DC_HOT_PLUG_DETECT1_INT_ACK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|C_007D08_DC_HOT_PLUG_DETECT1_INT_ACK
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_007D08_DC_HOT_PLUG_DETECT1_INT_POLARITY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 8)
end_define

begin_define
define|#
directive|define
name|G_007D08_DC_HOT_PLUG_DETECT1_INT_POLARITY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_007D08_DC_HOT_PLUG_DETECT1_INT_POLARITY
value|0xFFFFFEFF
end_define

begin_define
define|#
directive|define
name|S_007D08_DC_HOT_PLUG_DETECT1_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_007D08_DC_HOT_PLUG_DETECT1_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_007D08_DC_HOT_PLUG_DETECT1_INT_EN
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|R_007D10_DC_HOT_PLUG_DETECT2_CONTROL
value|0x007D10
end_define

begin_define
define|#
directive|define
name|S_007D10_DC_HOT_PLUG_DETECT2_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_007D10_DC_HOT_PLUG_DETECT2_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_007D10_DC_HOT_PLUG_DETECT2_EN
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|R_007D14_DC_HOT_PLUG_DETECT2_INT_STATUS
value|0x007D14
end_define

begin_define
define|#
directive|define
name|S_007D14_DC_HOT_PLUG_DETECT2_INT_STATUS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_007D14_DC_HOT_PLUG_DETECT2_INT_STATUS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_007D14_DC_HOT_PLUG_DETECT2_INT_STATUS
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_007D14_DC_HOT_PLUG_DETECT2_SENSE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_007D14_DC_HOT_PLUG_DETECT2_SENSE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_007D14_DC_HOT_PLUG_DETECT2_SENSE
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|R_007D18_DC_HOT_PLUG_DETECT2_INT_CONTROL
value|0x007D18
end_define

begin_define
define|#
directive|define
name|S_007D18_DC_HOT_PLUG_DETECT2_INT_ACK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|C_007D18_DC_HOT_PLUG_DETECT2_INT_ACK
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_007D18_DC_HOT_PLUG_DETECT2_INT_POLARITY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 8)
end_define

begin_define
define|#
directive|define
name|G_007D18_DC_HOT_PLUG_DETECT2_INT_POLARITY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_007D18_DC_HOT_PLUG_DETECT2_INT_POLARITY
value|0xFFFFFEFF
end_define

begin_define
define|#
directive|define
name|S_007D18_DC_HOT_PLUG_DETECT2_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_007D18_DC_HOT_PLUG_DETECT2_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_007D18_DC_HOT_PLUG_DETECT2_INT_EN
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|R_007404_HDMI0_STATUS
value|0x007404
end_define

begin_define
define|#
directive|define
name|S_007404_HDMI0_AZ_FORMAT_WTRIG
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 28)
end_define

begin_define
define|#
directive|define
name|G_007404_HDMI0_AZ_FORMAT_WTRIG
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_007404_HDMI0_AZ_FORMAT_WTRIG
value|0xEFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_007404_HDMI0_AZ_FORMAT_WTRIG_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 29)
end_define

begin_define
define|#
directive|define
name|G_007404_HDMI0_AZ_FORMAT_WTRIG_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 29)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_007404_HDMI0_AZ_FORMAT_WTRIG_INT
value|0xDFFFFFFF
end_define

begin_define
define|#
directive|define
name|R_007408_HDMI0_AUDIO_PACKET_CONTROL
value|0x007408
end_define

begin_define
define|#
directive|define
name|S_007408_HDMI0_AZ_FORMAT_WTRIG_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 28)
end_define

begin_define
define|#
directive|define
name|G_007408_HDMI0_AZ_FORMAT_WTRIG_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_007408_HDMI0_AZ_FORMAT_WTRIG_MASK
value|0xEFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_007408_HDMI0_AZ_FORMAT_WTRIG_ACK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 29)
end_define

begin_define
define|#
directive|define
name|G_007408_HDMI0_AZ_FORMAT_WTRIG_ACK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 29)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_007408_HDMI0_AZ_FORMAT_WTRIG_ACK
value|0xDFFFFFFF
end_define

begin_comment
comment|/* MC registers */
end_comment

begin_define
define|#
directive|define
name|R_000000_MC_STATUS
value|0x000000
end_define

begin_define
define|#
directive|define
name|S_000000_MC_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000000_MC_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000000_MC_IDLE
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|R_000004_MC_FB_LOCATION
value|0x000004
end_define

begin_define
define|#
directive|define
name|S_000004_MC_FB_START
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000004_MC_FB_START
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|C_000004_MC_FB_START
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|S_000004_MC_FB_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 16)
end_define

begin_define
define|#
directive|define
name|G_000004_MC_FB_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|C_000004_MC_FB_TOP
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|R_000005_MC_AGP_LOCATION
value|0x000005
end_define

begin_define
define|#
directive|define
name|S_000005_MC_AGP_START
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000005_MC_AGP_START
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|C_000005_MC_AGP_START
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|S_000005_MC_AGP_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 16)
end_define

begin_define
define|#
directive|define
name|G_000005_MC_AGP_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|C_000005_MC_AGP_TOP
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|R_000006_AGP_BASE
value|0x000006
end_define

begin_define
define|#
directive|define
name|S_000006_AGP_BASE_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000006_AGP_BASE_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_000006_AGP_BASE_ADDR
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_000007_AGP_BASE_2
value|0x000007
end_define

begin_define
define|#
directive|define
name|S_000007_AGP_BASE_ADDR_2
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000007_AGP_BASE_ADDR_2
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_000007_AGP_BASE_ADDR_2
value|0xFFFFFFF0
end_define

begin_define
define|#
directive|define
name|R_000009_MC_CNTL1
value|0x000009
end_define

begin_define
define|#
directive|define
name|S_000009_ENABLE_PAGE_TABLES
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 26)
end_define

begin_define
define|#
directive|define
name|G_000009_ENABLE_PAGE_TABLES
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 26)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000009_ENABLE_PAGE_TABLES
value|0xFBFFFFFF
end_define

begin_comment
comment|/* FIXME don't know the various field size need feedback from AMD */
end_comment

begin_define
define|#
directive|define
name|R_000100_MC_PT0_CNTL
value|0x000100
end_define

begin_define
define|#
directive|define
name|S_000100_ENABLE_PT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000100_ENABLE_PT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000100_ENABLE_PT
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_000100_EFFECTIVE_L2_CACHE_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 15)
end_define

begin_define
define|#
directive|define
name|G_000100_EFFECTIVE_L2_CACHE_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_000100_EFFECTIVE_L2_CACHE_SIZE
value|0xFFFC7FFF
end_define

begin_define
define|#
directive|define
name|S_000100_EFFECTIVE_L2_QUEUE_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 21)
end_define

begin_define
define|#
directive|define
name|G_000100_EFFECTIVE_L2_QUEUE_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_000100_EFFECTIVE_L2_QUEUE_SIZE
value|0xFF1FFFFF
end_define

begin_define
define|#
directive|define
name|S_000100_INVALIDATE_ALL_L1_TLBS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 28)
end_define

begin_define
define|#
directive|define
name|G_000100_INVALIDATE_ALL_L1_TLBS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000100_INVALIDATE_ALL_L1_TLBS
value|0xEFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000100_INVALIDATE_L2_CACHE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 29)
end_define

begin_define
define|#
directive|define
name|G_000100_INVALIDATE_L2_CACHE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 29)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000100_INVALIDATE_L2_CACHE
value|0xDFFFFFFF
end_define

begin_define
define|#
directive|define
name|R_000102_MC_PT0_CONTEXT0_CNTL
value|0x000102
end_define

begin_define
define|#
directive|define
name|S_000102_ENABLE_PAGE_TABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000102_ENABLE_PAGE_TABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000102_ENABLE_PAGE_TABLE
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_000102_PAGE_TABLE_DEPTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 1)
end_define

begin_define
define|#
directive|define
name|G_000102_PAGE_TABLE_DEPTH
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_000102_PAGE_TABLE_DEPTH
value|0xFFFFFFF9
end_define

begin_define
define|#
directive|define
name|V_000102_PAGE_TABLE_FLAT
value|0
end_define

begin_comment
comment|/* R600 documentation suggest that this should be a number of pages */
end_comment

begin_define
define|#
directive|define
name|R_000112_MC_PT0_SYSTEM_APERTURE_LOW_ADDR
value|0x000112
end_define

begin_define
define|#
directive|define
name|R_000114_MC_PT0_SYSTEM_APERTURE_HIGH_ADDR
value|0x000114
end_define

begin_define
define|#
directive|define
name|R_00011C_MC_PT0_CONTEXT0_DEFAULT_READ_ADDR
value|0x00011C
end_define

begin_define
define|#
directive|define
name|R_00012C_MC_PT0_CONTEXT0_FLAT_BASE_ADDR
value|0x00012C
end_define

begin_define
define|#
directive|define
name|R_00013C_MC_PT0_CONTEXT0_FLAT_START_ADDR
value|0x00013C
end_define

begin_define
define|#
directive|define
name|R_00014C_MC_PT0_CONTEXT0_FLAT_END_ADDR
value|0x00014C
end_define

begin_define
define|#
directive|define
name|R_00016C_MC_PT0_CLIENT0_CNTL
value|0x00016C
end_define

begin_define
define|#
directive|define
name|S_00016C_ENABLE_TRANSLATION_MODE_OVERRIDE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_00016C_ENABLE_TRANSLATION_MODE_OVERRIDE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00016C_ENABLE_TRANSLATION_MODE_OVERRIDE
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_00016C_TRANSLATION_MODE_OVERRIDE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_00016C_TRANSLATION_MODE_OVERRIDE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00016C_TRANSLATION_MODE_OVERRIDE
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|S_00016C_SYSTEM_ACCESS_MODE_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 8)
end_define

begin_define
define|#
directive|define
name|G_00016C_SYSTEM_ACCESS_MODE_MASK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_00016C_SYSTEM_ACCESS_MODE_MASK
value|0xFFFFFCFF
end_define

begin_define
define|#
directive|define
name|V_00016C_SYSTEM_ACCESS_MODE_PA_ONLY
value|0
end_define

begin_define
define|#
directive|define
name|V_00016C_SYSTEM_ACCESS_MODE_USE_SYS_MAP
value|1
end_define

begin_define
define|#
directive|define
name|V_00016C_SYSTEM_ACCESS_MODE_IN_SYS
value|2
end_define

begin_define
define|#
directive|define
name|V_00016C_SYSTEM_ACCESS_MODE_NOT_IN_SYS
value|3
end_define

begin_define
define|#
directive|define
name|S_00016C_SYSTEM_APERTURE_UNMAPPED_ACCESS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 10)
end_define

begin_define
define|#
directive|define
name|G_00016C_SYSTEM_APERTURE_UNMAPPED_ACCESS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00016C_SYSTEM_APERTURE_UNMAPPED_ACCESS
value|0xFFFFFBFF
end_define

begin_define
define|#
directive|define
name|V_00016C_SYSTEM_APERTURE_UNMAPPED_PASSTHROUGH
value|0
end_define

begin_define
define|#
directive|define
name|V_00016C_SYSTEM_APERTURE_UNMAPPED_DEFAULT_PAGE
value|1
end_define

begin_define
define|#
directive|define
name|S_00016C_EFFECTIVE_L1_CACHE_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 11)
end_define

begin_define
define|#
directive|define
name|G_00016C_EFFECTIVE_L1_CACHE_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_00016C_EFFECTIVE_L1_CACHE_SIZE
value|0xFFFFC7FF
end_define

begin_define
define|#
directive|define
name|S_00016C_ENABLE_FRAGMENT_PROCESSING
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 14)
end_define

begin_define
define|#
directive|define
name|G_00016C_ENABLE_FRAGMENT_PROCESSING
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00016C_ENABLE_FRAGMENT_PROCESSING
value|0xFFFFBFFF
end_define

begin_define
define|#
directive|define
name|S_00016C_EFFECTIVE_L1_QUEUE_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 15)
end_define

begin_define
define|#
directive|define
name|G_00016C_EFFECTIVE_L1_QUEUE_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_00016C_EFFECTIVE_L1_QUEUE_SIZE
value|0xFFFC7FFF
end_define

begin_define
define|#
directive|define
name|S_00016C_INVALIDATE_L1_TLB
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 20)
end_define

begin_define
define|#
directive|define
name|G_00016C_INVALIDATE_L1_TLB
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00016C_INVALIDATE_L1_TLB
value|0xFFEFFFFF
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

begin_comment
comment|/* PLL regs */
end_comment

begin_define
define|#
directive|define
name|GENERAL_PWRMGT
value|0x8
end_define

begin_define
define|#
directive|define
name|GLOBAL_PWRMGT_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MOBILE_SU
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DYN_PWRMGT_SCLK_LENGTH
value|0xc
end_define

begin_define
define|#
directive|define
name|NORMAL_POWER_SCLK_HILEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|NORMAL_POWER_SCLK_LOLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< 4)
end_define

begin_define
define|#
directive|define
name|REDUCED_POWER_SCLK_HILEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|REDUCED_POWER_SCLK_LOLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
end_define

begin_define
define|#
directive|define
name|POWER_D1_SCLK_HILEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|POWER_D1_SCLK_LOLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
end_define

begin_define
define|#
directive|define
name|STATIC_SCREEN_HILEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|STATIC_SCREEN_LOLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< 28)
end_define

begin_define
define|#
directive|define
name|DYN_SCLK_VOL_CNTL
value|0xe
end_define

begin_define
define|#
directive|define
name|IO_CG_VOLTAGE_DROP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|VOLTAGE_DROP_SYNC
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|VOLTAGE_DELAY_SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 3)
end_define

begin_define
define|#
directive|define
name|HDP_DYN_CNTL
value|0x10
end_define

begin_define
define|#
directive|define
name|HDP_FORCEON
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MC_HOST_DYN_CNTL
value|0x1e
end_define

begin_define
define|#
directive|define
name|MC_HOST_FORCEON
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DYN_BACKBIAS_CNTL
value|0x29
end_define

begin_define
define|#
directive|define
name|IO_CG_BACKBIAS_EN
value|(1<< 0)
end_define

begin_comment
comment|/* mmreg */
end_comment

begin_define
define|#
directive|define
name|DOUT_POWER_MANAGEMENT_CNTL
value|0x7ee0
end_define

begin_define
define|#
directive|define
name|PWRDN_WAIT_BUSY_OFF
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PWRDN_WAIT_PWRSEQ_OFF
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|PWRDN_WAIT_PPLL_OFF
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|PWRUP_WAIT_PPLL_ON
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|PWRUP_WAIT_MEM_INIT_DONE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|PM_ASSERT_RESET
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|PM_PWRDN_PPLL
value|(1<< 24)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

