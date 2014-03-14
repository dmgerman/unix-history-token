begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2010 Advanced Micro Devices, Inc.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors: Alex Deucher  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NI_REG_H__
end_ifndef

begin_define
define|#
directive|define
name|__NI_REG_H__
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
comment|/* northern islands - DCE5 */
end_comment

begin_define
define|#
directive|define
name|NI_INPUT_GAMMA_CONTROL
value|0x6840
end_define

begin_define
define|#
directive|define
name|NI_GRPH_INPUT_GAMMA_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 0)
end_define

begin_define
define|#
directive|define
name|NI_INPUT_GAMMA_USE_LUT
value|0
end_define

begin_define
define|#
directive|define
name|NI_INPUT_GAMMA_BYPASS
value|1
end_define

begin_define
define|#
directive|define
name|NI_INPUT_GAMMA_SRGB_24
value|2
end_define

begin_define
define|#
directive|define
name|NI_INPUT_GAMMA_XVYCC_222
value|3
end_define

begin_define
define|#
directive|define
name|NI_OVL_INPUT_GAMMA_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 4)
end_define

begin_define
define|#
directive|define
name|NI_PRESCALE_GRPH_CONTROL
value|0x68b4
end_define

begin_define
define|#
directive|define
name|NI_GRPH_PRESCALE_BYPASS
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|NI_PRESCALE_OVL_CONTROL
value|0x68c4
end_define

begin_define
define|#
directive|define
name|NI_OVL_PRESCALE_BYPASS
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|NI_INPUT_CSC_CONTROL
value|0x68d4
end_define

begin_define
define|#
directive|define
name|NI_INPUT_CSC_GRPH_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 0)
end_define

begin_define
define|#
directive|define
name|NI_INPUT_CSC_BYPASS
value|0
end_define

begin_define
define|#
directive|define
name|NI_INPUT_CSC_PROG_COEFF
value|1
end_define

begin_define
define|#
directive|define
name|NI_INPUT_CSC_PROG_SHARED_MATRIXA
value|2
end_define

begin_define
define|#
directive|define
name|NI_INPUT_CSC_OVL_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 4)
end_define

begin_define
define|#
directive|define
name|NI_OUTPUT_CSC_CONTROL
value|0x68f0
end_define

begin_define
define|#
directive|define
name|NI_OUTPUT_CSC_GRPH_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 0)
end_define

begin_define
define|#
directive|define
name|NI_OUTPUT_CSC_BYPASS
value|0
end_define

begin_define
define|#
directive|define
name|NI_OUTPUT_CSC_TV_RGB
value|1
end_define

begin_define
define|#
directive|define
name|NI_OUTPUT_CSC_YCBCR_601
value|2
end_define

begin_define
define|#
directive|define
name|NI_OUTPUT_CSC_YCBCR_709
value|3
end_define

begin_define
define|#
directive|define
name|NI_OUTPUT_CSC_PROG_COEFF
value|4
end_define

begin_define
define|#
directive|define
name|NI_OUTPUT_CSC_PROG_SHARED_MATRIXB
value|5
end_define

begin_define
define|#
directive|define
name|NI_OUTPUT_CSC_OVL_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 4)
end_define

begin_define
define|#
directive|define
name|NI_DEGAMMA_CONTROL
value|0x6960
end_define

begin_define
define|#
directive|define
name|NI_GRPH_DEGAMMA_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 0)
end_define

begin_define
define|#
directive|define
name|NI_DEGAMMA_BYPASS
value|0
end_define

begin_define
define|#
directive|define
name|NI_DEGAMMA_SRGB_24
value|1
end_define

begin_define
define|#
directive|define
name|NI_DEGAMMA_XVYCC_222
value|2
end_define

begin_define
define|#
directive|define
name|NI_OVL_DEGAMMA_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 4)
end_define

begin_define
define|#
directive|define
name|NI_ICON_DEGAMMA_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 8)
end_define

begin_define
define|#
directive|define
name|NI_CURSOR_DEGAMMA_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 12)
end_define

begin_define
define|#
directive|define
name|NI_GAMUT_REMAP_CONTROL
value|0x6964
end_define

begin_define
define|#
directive|define
name|NI_GRPH_GAMUT_REMAP_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 0)
end_define

begin_define
define|#
directive|define
name|NI_GAMUT_REMAP_BYPASS
value|0
end_define

begin_define
define|#
directive|define
name|NI_GAMUT_REMAP_PROG_COEFF
value|1
end_define

begin_define
define|#
directive|define
name|NI_GAMUT_REMAP_PROG_SHARED_MATRIXA
value|2
end_define

begin_define
define|#
directive|define
name|NI_GAMUT_REMAP_PROG_SHARED_MATRIXB
value|3
end_define

begin_define
define|#
directive|define
name|NI_OVL_GAMUT_REMAP_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 4)
end_define

begin_define
define|#
directive|define
name|NI_REGAMMA_CONTROL
value|0x6a80
end_define

begin_define
define|#
directive|define
name|NI_GRPH_REGAMMA_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 0)
end_define

begin_define
define|#
directive|define
name|NI_REGAMMA_BYPASS
value|0
end_define

begin_define
define|#
directive|define
name|NI_REGAMMA_SRGB_24
value|1
end_define

begin_define
define|#
directive|define
name|NI_REGAMMA_XVYCC_222
value|2
end_define

begin_define
define|#
directive|define
name|NI_REGAMMA_PROG_A
value|3
end_define

begin_define
define|#
directive|define
name|NI_REGAMMA_PROG_B
value|4
end_define

begin_define
define|#
directive|define
name|NI_OVL_REGAMMA_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 4)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

