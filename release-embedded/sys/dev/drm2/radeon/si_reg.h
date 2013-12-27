begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2010 Advanced Micro Devices, Inc.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors: Alex Deucher  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SI_REG_H__
end_ifndef

begin_define
define|#
directive|define
name|__SI_REG_H__
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
comment|/* SI */
end_comment

begin_define
define|#
directive|define
name|SI_DC_GPIO_HPD_MASK
value|0x65b0
end_define

begin_define
define|#
directive|define
name|SI_DC_GPIO_HPD_A
value|0x65b4
end_define

begin_define
define|#
directive|define
name|SI_DC_GPIO_HPD_EN
value|0x65b8
end_define

begin_define
define|#
directive|define
name|SI_DC_GPIO_HPD_Y
value|0x65bc
end_define

begin_define
define|#
directive|define
name|SI_GRPH_CONTROL
value|0x6804
end_define

begin_define
define|#
directive|define
name|SI_GRPH_DEPTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 0)
end_define

begin_define
define|#
directive|define
name|SI_GRPH_DEPTH_8BPP
value|0
end_define

begin_define
define|#
directive|define
name|SI_GRPH_DEPTH_16BPP
value|1
end_define

begin_define
define|#
directive|define
name|SI_GRPH_DEPTH_32BPP
value|2
end_define

begin_define
define|#
directive|define
name|SI_GRPH_NUM_BANKS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 2)
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_2_BANK
value|0
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_4_BANK
value|1
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_8_BANK
value|2
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_16_BANK
value|3
end_define

begin_define
define|#
directive|define
name|SI_GRPH_Z
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 4)
end_define

begin_define
define|#
directive|define
name|SI_GRPH_BANK_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 6)
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_BANK_WIDTH_1
value|0
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_BANK_WIDTH_2
value|1
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_BANK_WIDTH_4
value|2
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_BANK_WIDTH_8
value|3
end_define

begin_define
define|#
directive|define
name|SI_GRPH_FORMAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 8)
end_define

begin_comment
comment|/* 8 BPP */
end_comment

begin_define
define|#
directive|define
name|SI_GRPH_FORMAT_INDEXED
value|0
end_define

begin_comment
comment|/* 16 BPP */
end_comment

begin_define
define|#
directive|define
name|SI_GRPH_FORMAT_ARGB1555
value|0
end_define

begin_define
define|#
directive|define
name|SI_GRPH_FORMAT_ARGB565
value|1
end_define

begin_define
define|#
directive|define
name|SI_GRPH_FORMAT_ARGB4444
value|2
end_define

begin_define
define|#
directive|define
name|SI_GRPH_FORMAT_AI88
value|3
end_define

begin_define
define|#
directive|define
name|SI_GRPH_FORMAT_MONO16
value|4
end_define

begin_define
define|#
directive|define
name|SI_GRPH_FORMAT_BGRA5551
value|5
end_define

begin_comment
comment|/* 32 BPP */
end_comment

begin_define
define|#
directive|define
name|SI_GRPH_FORMAT_ARGB8888
value|0
end_define

begin_define
define|#
directive|define
name|SI_GRPH_FORMAT_ARGB2101010
value|1
end_define

begin_define
define|#
directive|define
name|SI_GRPH_FORMAT_32BPP_DIG
value|2
end_define

begin_define
define|#
directive|define
name|SI_GRPH_FORMAT_8B_ARGB2101010
value|3
end_define

begin_define
define|#
directive|define
name|SI_GRPH_FORMAT_BGRA1010102
value|4
end_define

begin_define
define|#
directive|define
name|SI_GRPH_FORMAT_8B_BGRA1010102
value|5
end_define

begin_define
define|#
directive|define
name|SI_GRPH_FORMAT_RGB111110
value|6
end_define

begin_define
define|#
directive|define
name|SI_GRPH_FORMAT_BGR101111
value|7
end_define

begin_define
define|#
directive|define
name|SI_GRPH_BANK_HEIGHT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 11)
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_BANK_HEIGHT_1
value|0
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_BANK_HEIGHT_2
value|1
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_BANK_HEIGHT_4
value|2
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_BANK_HEIGHT_8
value|3
end_define

begin_define
define|#
directive|define
name|SI_GRPH_TILE_SPLIT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 13)
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_TILE_SPLIT_64B
value|0
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_TILE_SPLIT_128B
value|1
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_TILE_SPLIT_256B
value|2
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_TILE_SPLIT_512B
value|3
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_TILE_SPLIT_1KB
value|4
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_TILE_SPLIT_2KB
value|5
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_TILE_SPLIT_4KB
value|6
end_define

begin_define
define|#
directive|define
name|SI_GRPH_MACRO_TILE_ASPECT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 18)
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_MACRO_TILE_ASPECT_1
value|0
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_MACRO_TILE_ASPECT_2
value|1
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_MACRO_TILE_ASPECT_4
value|2
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_MACRO_TILE_ASPECT_8
value|3
end_define

begin_define
define|#
directive|define
name|SI_GRPH_ARRAY_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 20)
end_define

begin_define
define|#
directive|define
name|SI_GRPH_ARRAY_LINEAR_GENERAL
value|0
end_define

begin_define
define|#
directive|define
name|SI_GRPH_ARRAY_LINEAR_ALIGNED
value|1
end_define

begin_define
define|#
directive|define
name|SI_GRPH_ARRAY_1D_TILED_THIN1
value|2
end_define

begin_define
define|#
directive|define
name|SI_GRPH_ARRAY_2D_TILED_THIN1
value|4
end_define

begin_define
define|#
directive|define
name|SI_GRPH_PIPE_CONFIG
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1f)<< 24)
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_P2
value|0
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_P4_8x16
value|4
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_P4_16x16
value|5
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_P4_16x32
value|6
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_P4_32x32
value|7
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_P8_16x16_8x16
value|8
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_P8_16x32_8x16
value|9
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_P8_32x32_8x16
value|10
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_P8_16x32_16x16
value|11
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_P8_32x32_16x16
value|12
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_P8_32x32_16x32
value|13
end_define

begin_define
define|#
directive|define
name|SI_ADDR_SURF_P8_32x64_32x32
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

