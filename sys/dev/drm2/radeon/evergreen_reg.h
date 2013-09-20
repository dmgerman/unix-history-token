begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2010 Advanced Micro Devices, Inc.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors: Alex Deucher  */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|__EVERGREEN_REG_H__
end_ifndef

begin_define
define|#
directive|define
name|__EVERGREEN_REG_H__
end_define

begin_comment
comment|/* evergreen */
end_comment

begin_define
define|#
directive|define
name|EVERGREEN_VGA_MEMORY_BASE_ADDRESS
value|0x310
end_define

begin_define
define|#
directive|define
name|EVERGREEN_VGA_MEMORY_BASE_ADDRESS_HIGH
value|0x324
end_define

begin_define
define|#
directive|define
name|EVERGREEN_D3VGA_CONTROL
value|0x3e0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_D4VGA_CONTROL
value|0x3e4
end_define

begin_define
define|#
directive|define
name|EVERGREEN_D5VGA_CONTROL
value|0x3e8
end_define

begin_define
define|#
directive|define
name|EVERGREEN_D6VGA_CONTROL
value|0x3ec
end_define

begin_define
define|#
directive|define
name|EVERGREEN_P1PLL_SS_CNTL
value|0x414
end_define

begin_define
define|#
directive|define
name|EVERGREEN_P2PLL_SS_CNTL
value|0x454
end_define

begin_define
define|#
directive|define
name|EVERGREEN_PxPLL_SS_EN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_AUDIO_PLL1_MUL
value|0x5b0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_AUDIO_PLL1_DIV
value|0x5b4
end_define

begin_define
define|#
directive|define
name|EVERGREEN_AUDIO_PLL1_UNK
value|0x5bc
end_define

begin_define
define|#
directive|define
name|EVERGREEN_AUDIO_ENABLE
value|0x5e78
end_define

begin_define
define|#
directive|define
name|EVERGREEN_AUDIO_VENDOR_ID
value|0x5ec0
end_define

begin_comment
comment|/* GRPH blocks at 0x6800, 0x7400, 0x10000, 0x10c00, 0x11800, 0x12400 */
end_comment

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_ENABLE
value|0x6800
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_CONTROL
value|0x6804
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_DEPTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 0)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_DEPTH_8BPP
value|0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_DEPTH_16BPP
value|1
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_DEPTH_32BPP
value|2
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_NUM_BANKS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 2)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_2_BANK
value|0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_4_BANK
value|1
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_8_BANK
value|2
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_16_BANK
value|3
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_Z
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 4)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_BANK_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 6)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_BANK_WIDTH_1
value|0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_BANK_WIDTH_2
value|1
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_BANK_WIDTH_4
value|2
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_BANK_WIDTH_8
value|3
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_FORMAT
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
name|EVERGREEN_GRPH_FORMAT_INDEXED
value|0
end_define

begin_comment
comment|/* 16 BPP */
end_comment

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_FORMAT_ARGB1555
value|0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_FORMAT_ARGB565
value|1
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_FORMAT_ARGB4444
value|2
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_FORMAT_AI88
value|3
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_FORMAT_MONO16
value|4
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_FORMAT_BGRA5551
value|5
end_define

begin_comment
comment|/* 32 BPP */
end_comment

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_FORMAT_ARGB8888
value|0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_FORMAT_ARGB2101010
value|1
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_FORMAT_32BPP_DIG
value|2
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_FORMAT_8B_ARGB2101010
value|3
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_FORMAT_BGRA1010102
value|4
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_FORMAT_8B_BGRA1010102
value|5
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_FORMAT_RGB111110
value|6
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_FORMAT_BGR101111
value|7
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_BANK_HEIGHT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 11)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_BANK_HEIGHT_1
value|0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_BANK_HEIGHT_2
value|1
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_BANK_HEIGHT_4
value|2
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_BANK_HEIGHT_8
value|3
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_TILE_SPLIT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 13)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_TILE_SPLIT_64B
value|0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_TILE_SPLIT_128B
value|1
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_TILE_SPLIT_256B
value|2
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_TILE_SPLIT_512B
value|3
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_TILE_SPLIT_1KB
value|4
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_TILE_SPLIT_2KB
value|5
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_TILE_SPLIT_4KB
value|6
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_MACRO_TILE_ASPECT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 18)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_MACRO_TILE_ASPECT_1
value|0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_MACRO_TILE_ASPECT_2
value|1
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_MACRO_TILE_ASPECT_4
value|2
end_define

begin_define
define|#
directive|define
name|EVERGREEN_ADDR_SURF_MACRO_TILE_ASPECT_8
value|3
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_ARRAY_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 20)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_ARRAY_LINEAR_GENERAL
value|0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_ARRAY_LINEAR_ALIGNED
value|1
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_ARRAY_1D_TILED_THIN1
value|2
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_ARRAY_2D_TILED_THIN1
value|4
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_SWAP_CONTROL
value|0x680c
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_ENDIAN_SWAP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 0)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_ENDIAN_NONE
value|0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_ENDIAN_8IN16
value|1
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_ENDIAN_8IN32
value|2
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_ENDIAN_8IN64
value|3
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_RED_CROSSBAR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 4)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_RED_SEL_R
value|0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_RED_SEL_G
value|1
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_RED_SEL_B
value|2
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_RED_SEL_A
value|3
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_GREEN_CROSSBAR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 6)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_GREEN_SEL_G
value|0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_GREEN_SEL_B
value|1
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_GREEN_SEL_A
value|2
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_GREEN_SEL_R
value|3
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_BLUE_CROSSBAR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 8)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_BLUE_SEL_B
value|0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_BLUE_SEL_A
value|1
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_BLUE_SEL_R
value|2
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_BLUE_SEL_G
value|3
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_ALPHA_CROSSBAR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 10)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_ALPHA_SEL_A
value|0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_ALPHA_SEL_R
value|1
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_ALPHA_SEL_G
value|2
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_ALPHA_SEL_B
value|3
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_PRIMARY_SURFACE_ADDRESS
value|0x6810
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_SECONDARY_SURFACE_ADDRESS
value|0x6814
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_DFQ_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_SURFACE_ADDRESS_MASK
value|0xffffff00
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_PITCH
value|0x6818
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_PRIMARY_SURFACE_ADDRESS_HIGH
value|0x681c
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_SECONDARY_SURFACE_ADDRESS_HIGH
value|0x6820
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_SURFACE_OFFSET_X
value|0x6824
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_SURFACE_OFFSET_Y
value|0x6828
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_X_START
value|0x682c
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_Y_START
value|0x6830
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_X_END
value|0x6834
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_Y_END
value|0x6838
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_UPDATE
value|0x6844
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_SURFACE_UPDATE_PENDING
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_UPDATE_LOCK
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_FLIP_CONTROL
value|0x6848
end_define

begin_define
define|#
directive|define
name|EVERGREEN_GRPH_SURFACE_UPDATE_H_RETRACE_EN
value|(1<< 0)
end_define

begin_comment
comment|/* CUR blocks at 0x6998, 0x7598, 0x10198, 0x10d98, 0x11998, 0x12598 */
end_comment

begin_define
define|#
directive|define
name|EVERGREEN_CUR_CONTROL
value|0x6998
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CURSOR_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CURSOR_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 8)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CURSOR_MONO
value|0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CURSOR_24_1
value|1
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CURSOR_24_8_PRE_MULT
value|2
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CURSOR_24_8_UNPRE_MULT
value|3
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CURSOR_2X_MAGNIFY
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CURSOR_FORCE_MC_ON
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CURSOR_URGENT_CONTROL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 24)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CURSOR_URGENT_ALWAYS
value|0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CURSOR_URGENT_1_8
value|1
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CURSOR_URGENT_1_4
value|2
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CURSOR_URGENT_3_8
value|3
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CURSOR_URGENT_1_2
value|4
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CUR_SURFACE_ADDRESS
value|0x699c
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CUR_SURFACE_ADDRESS_MASK
value|0xfffff000
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CUR_SIZE
value|0x69a0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CUR_SURFACE_ADDRESS_HIGH
value|0x69a4
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CUR_POSITION
value|0x69a8
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CUR_HOT_SPOT
value|0x69ac
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CUR_COLOR1
value|0x69b0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CUR_COLOR2
value|0x69b4
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CUR_UPDATE
value|0x69b8
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CURSOR_UPDATE_PENDING
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CURSOR_UPDATE_TAKEN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CURSOR_UPDATE_LOCK
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CURSOR_DISABLE_MULTIPLE_UPDATE
value|(1<< 24)
end_define

begin_comment
comment|/* LUT blocks at 0x69e0, 0x75e0, 0x101e0, 0x10de0, 0x119e0, 0x125e0 */
end_comment

begin_define
define|#
directive|define
name|EVERGREEN_DC_LUT_RW_MODE
value|0x69e0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_DC_LUT_RW_INDEX
value|0x69e4
end_define

begin_define
define|#
directive|define
name|EVERGREEN_DC_LUT_SEQ_COLOR
value|0x69e8
end_define

begin_define
define|#
directive|define
name|EVERGREEN_DC_LUT_PWL_DATA
value|0x69ec
end_define

begin_define
define|#
directive|define
name|EVERGREEN_DC_LUT_30_COLOR
value|0x69f0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_DC_LUT_VGA_ACCESS_ENABLE
value|0x69f4
end_define

begin_define
define|#
directive|define
name|EVERGREEN_DC_LUT_WRITE_EN_MASK
value|0x69f8
end_define

begin_define
define|#
directive|define
name|EVERGREEN_DC_LUT_AUTOFILL
value|0x69fc
end_define

begin_define
define|#
directive|define
name|EVERGREEN_DC_LUT_CONTROL
value|0x6a00
end_define

begin_define
define|#
directive|define
name|EVERGREEN_DC_LUT_BLACK_OFFSET_BLUE
value|0x6a04
end_define

begin_define
define|#
directive|define
name|EVERGREEN_DC_LUT_BLACK_OFFSET_GREEN
value|0x6a08
end_define

begin_define
define|#
directive|define
name|EVERGREEN_DC_LUT_BLACK_OFFSET_RED
value|0x6a0c
end_define

begin_define
define|#
directive|define
name|EVERGREEN_DC_LUT_WHITE_OFFSET_BLUE
value|0x6a10
end_define

begin_define
define|#
directive|define
name|EVERGREEN_DC_LUT_WHITE_OFFSET_GREEN
value|0x6a14
end_define

begin_define
define|#
directive|define
name|EVERGREEN_DC_LUT_WHITE_OFFSET_RED
value|0x6a18
end_define

begin_define
define|#
directive|define
name|EVERGREEN_DATA_FORMAT
value|0x6b00
end_define

begin_define
define|#
directive|define
name|EVERGREEN_INTERLEAVE_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_DESKTOP_HEIGHT
value|0x6b04
end_define

begin_define
define|#
directive|define
name|EVERGREEN_VLINE_START_END
value|0x6b08
end_define

begin_define
define|#
directive|define
name|EVERGREEN_VLINE_STATUS
value|0x6bb8
end_define

begin_define
define|#
directive|define
name|EVERGREEN_VLINE_STAT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_VIEWPORT_START
value|0x6d70
end_define

begin_define
define|#
directive|define
name|EVERGREEN_VIEWPORT_SIZE
value|0x6d74
end_define

begin_comment
comment|/* display controller offsets used for crtc/cur/lut/grph/viewport/etc. */
end_comment

begin_define
define|#
directive|define
name|EVERGREEN_CRTC0_REGISTER_OFFSET
value|(0x6df0 - 0x6df0)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CRTC1_REGISTER_OFFSET
value|(0x79f0 - 0x6df0)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CRTC2_REGISTER_OFFSET
value|(0x105f0 - 0x6df0)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CRTC3_REGISTER_OFFSET
value|(0x111f0 - 0x6df0)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CRTC4_REGISTER_OFFSET
value|(0x11df0 - 0x6df0)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CRTC5_REGISTER_OFFSET
value|(0x129f0 - 0x6df0)
end_define

begin_comment
comment|/* CRTC blocks at 0x6df0, 0x79f0, 0x105f0, 0x111f0, 0x11df0, 0x129f0 */
end_comment

begin_define
define|#
directive|define
name|EVERGREEN_CRTC_V_BLANK_START_END
value|0x6e34
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CRTC_CONTROL
value|0x6e70
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CRTC_MASTER_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CRTC_DISP_READ_REQUEST_DISABLE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CRTC_BLANK_CONTROL
value|0x6e74
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CRTC_BLANK_DATA_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CRTC_STATUS
value|0x6e8c
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CRTC_V_BLANK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CRTC_STATUS_POSITION
value|0x6e90
end_define

begin_define
define|#
directive|define
name|EVERGREEN_MASTER_UPDATE_MODE
value|0x6ef8
end_define

begin_define
define|#
directive|define
name|EVERGREEN_CRTC_UPDATE_LOCK
value|0x6ed4
end_define

begin_define
define|#
directive|define
name|EVERGREEN_DC_GPIO_HPD_MASK
value|0x64b0
end_define

begin_define
define|#
directive|define
name|EVERGREEN_DC_GPIO_HPD_A
value|0x64b4
end_define

begin_define
define|#
directive|define
name|EVERGREEN_DC_GPIO_HPD_EN
value|0x64b8
end_define

begin_define
define|#
directive|define
name|EVERGREEN_DC_GPIO_HPD_Y
value|0x64bc
end_define

begin_comment
comment|/* HDMI blocks at 0x7030, 0x7c30, 0x10830, 0x11430, 0x12030, 0x12c30 */
end_comment

begin_define
define|#
directive|define
name|EVERGREEN_HDMI_BASE
value|0x7030
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

