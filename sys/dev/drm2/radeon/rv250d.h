begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008 Advanced Micro Devices, Inc.  * Copyright 2008 Red Hat Inc.  * Copyright 2009 Jerome Glisse.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors: Dave Airlie  *          Alex Deucher  *          Jerome Glisse  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RV250D_H__
end_ifndef

begin_define
define|#
directive|define
name|__RV250D_H__
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

begin_define
define|#
directive|define
name|R_00000D_SCLK_CNTL_M6
value|0x00000D
end_define

begin_define
define|#
directive|define
name|S_00000D_SCLK_SRC_SEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 0)
end_define

begin_define
define|#
directive|define
name|G_00000D_SCLK_SRC_SEL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_00000D_SCLK_SRC_SEL
value|0xFFFFFFF8
end_define

begin_define
define|#
directive|define
name|S_00000D_CP_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 3)
end_define

begin_define
define|#
directive|define
name|G_00000D_CP_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_CP_MAX_DYN_STOP_LAT
value|0xFFFFFFF7
end_define

begin_define
define|#
directive|define
name|S_00000D_HDP_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 4)
end_define

begin_define
define|#
directive|define
name|G_00000D_HDP_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_HDP_MAX_DYN_STOP_LAT
value|0xFFFFFFEF
end_define

begin_define
define|#
directive|define
name|S_00000D_TV_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 5)
end_define

begin_define
define|#
directive|define
name|G_00000D_TV_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_TV_MAX_DYN_STOP_LAT
value|0xFFFFFFDF
end_define

begin_define
define|#
directive|define
name|S_00000D_E2_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 6)
end_define

begin_define
define|#
directive|define
name|G_00000D_E2_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_E2_MAX_DYN_STOP_LAT
value|0xFFFFFFBF
end_define

begin_define
define|#
directive|define
name|S_00000D_SE_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 7)
end_define

begin_define
define|#
directive|define
name|G_00000D_SE_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 7)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_SE_MAX_DYN_STOP_LAT
value|0xFFFFFF7F
end_define

begin_define
define|#
directive|define
name|S_00000D_IDCT_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 8)
end_define

begin_define
define|#
directive|define
name|G_00000D_IDCT_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_IDCT_MAX_DYN_STOP_LAT
value|0xFFFFFEFF
end_define

begin_define
define|#
directive|define
name|S_00000D_VIP_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 9)
end_define

begin_define
define|#
directive|define
name|G_00000D_VIP_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 9)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_VIP_MAX_DYN_STOP_LAT
value|0xFFFFFDFF
end_define

begin_define
define|#
directive|define
name|S_00000D_RE_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 10)
end_define

begin_define
define|#
directive|define
name|G_00000D_RE_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_RE_MAX_DYN_STOP_LAT
value|0xFFFFFBFF
end_define

begin_define
define|#
directive|define
name|S_00000D_PB_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 11)
end_define

begin_define
define|#
directive|define
name|G_00000D_PB_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_PB_MAX_DYN_STOP_LAT
value|0xFFFFF7FF
end_define

begin_define
define|#
directive|define
name|S_00000D_TAM_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 12)
end_define

begin_define
define|#
directive|define
name|G_00000D_TAM_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_TAM_MAX_DYN_STOP_LAT
value|0xFFFFEFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_TDM_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 13)
end_define

begin_define
define|#
directive|define
name|G_00000D_TDM_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_TDM_MAX_DYN_STOP_LAT
value|0xFFFFDFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_RB_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 14)
end_define

begin_define
define|#
directive|define
name|G_00000D_RB_MAX_DYN_STOP_LAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_RB_MAX_DYN_STOP_LAT
value|0xFFFFBFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_DISP2
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 15)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_DISP2
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_DISP2
value|0xFFFF7FFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_CP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_CP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_CP
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_HDP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 17)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_HDP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 17)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_HDP
value|0xFFFDFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_DISP1
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 18)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_DISP1
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 18)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_DISP1
value|0xFFFBFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 19)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_TOP
value|0xFFF7FFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_E2
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 20)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_E2
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_E2
value|0xFFEFFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_SE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 21)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_SE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_SE
value|0xFFDFFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_IDCT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 22)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_IDCT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 22)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_IDCT
value|0xFFBFFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_VIP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 23)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_VIP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 23)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_VIP
value|0xFF7FFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_RE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_RE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_RE
value|0xFEFFFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_PB
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 25)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_PB
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 25)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_PB
value|0xFDFFFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_TAM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 26)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_TAM
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 26)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_TAM
value|0xFBFFFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_TDM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 27)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_TDM
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 27)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_TDM
value|0xF7FFFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_RB
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 28)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_RB
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_RB
value|0xEFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_TV_SCLK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 29)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_TV_SCLK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 29)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_TV_SCLK
value|0xDFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_SUBPIC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 30)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_SUBPIC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 30)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_SUBPIC
value|0xBFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_OV0
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 31)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_OV0
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 31)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_OV0
value|0x7FFFFFFF
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

