begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************  Copyright (C) 2004-2005 Nicolai Haehnle et al.  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation on the rights to use, copy, modify, merge, publish, distribute, sub license, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:  The above copyright notice and this permission notice (including the next paragraph) shall be included in all copies or substantial portions of the Software.  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE AUTHOR(S) AND/OR THEIR SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  **************************************************************************/
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

begin_comment
comment|/* *INDENT-OFF* */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_R300_REG_H
end_ifndef

begin_define
define|#
directive|define
name|_R300_REG_H
end_define

begin_define
define|#
directive|define
name|R300_MC_INIT_MISC_LAT_TIMER
value|0x180
end_define

begin_define
define|#
directive|define
name|R300_MC_MISC__MC_CPR_INIT_LAT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_MC_MISC__MC_VF_INIT_LAT_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|R300_MC_MISC__MC_DISP0R_INIT_LAT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|R300_MC_MISC__MC_DISP1R_INIT_LAT_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|R300_MC_MISC__MC_FIXED_INIT_LAT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|R300_MC_MISC__MC_E2R_INIT_LAT_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|R300_MC_MISC__MC_SAME_PAGE_PRIO_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|R300_MC_MISC__MC_GLOBW_INIT_LAT_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|R300_MC_INIT_GFX_LAT_TIMER
value|0x154
end_define

begin_define
define|#
directive|define
name|R300_MC_MISC__MC_G3D0R_INIT_LAT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_MC_MISC__MC_G3D1R_INIT_LAT_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|R300_MC_MISC__MC_G3D2R_INIT_LAT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|R300_MC_MISC__MC_G3D3R_INIT_LAT_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|R300_MC_MISC__MC_TX0R_INIT_LAT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|R300_MC_MISC__MC_TX1R_INIT_LAT_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|R300_MC_MISC__MC_GLOBR_INIT_LAT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|R300_MC_MISC__MC_GLOBW_FULL_LAT_SHIFT
value|28
end_define

begin_comment
comment|/*  * This file contains registers and constants for the R300. They have been  * found mostly by examining command buffers captured using glxtest, as well  * as by extrapolating some known registers and constants from the R200.  * I am fairly certain that they are correct unless stated otherwise  * in comments.  */
end_comment

begin_define
define|#
directive|define
name|R300_SE_VPORT_XSCALE
value|0x1D98
end_define

begin_define
define|#
directive|define
name|R300_SE_VPORT_XOFFSET
value|0x1D9C
end_define

begin_define
define|#
directive|define
name|R300_SE_VPORT_YSCALE
value|0x1DA0
end_define

begin_define
define|#
directive|define
name|R300_SE_VPORT_YOFFSET
value|0x1DA4
end_define

begin_define
define|#
directive|define
name|R300_SE_VPORT_ZSCALE
value|0x1DA8
end_define

begin_define
define|#
directive|define
name|R300_SE_VPORT_ZOFFSET
value|0x1DAC
end_define

begin_comment
comment|/*  * Vertex Array Processing (VAP) Control  * Stolen from r200 code from Christoph Brill (It's a guess!)  */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_CNTL
value|0x2080
end_define

begin_comment
comment|/* This register is written directly and also starts data section  * in many 3d CP_PACKET3's  */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL
value|0x2084
end_define

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL__PRIM_TYPE__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL__PRIM_NONE
value|(0<<0)
end_define

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL__PRIM_POINTS
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL__PRIM_LINES
value|(2<<0)
end_define

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL__PRIM_LINE_STRIP
value|(3<<0)
end_define

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL__PRIM_TRIANGLES
value|(4<<0)
end_define

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL__PRIM_TRIANGLE_FAN
value|(5<<0)
end_define

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL__PRIM_TRIANGLE_STRIP
value|(6<<0)
end_define

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL__PRIM_LINE_LOOP
value|(12<<0)
end_define

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL__PRIM_QUADS
value|(13<<0)
end_define

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL__PRIM_QUAD_STRIP
value|(14<<0)
end_define

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL__PRIM_POLYGON
value|(15<<0)
end_define

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL__PRIM_WALK__SHIFT
value|4
end_define

begin_comment
comment|/* State based - direct writes to registers trigger vertex            generation */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL__PRIM_WALK_STATE_BASED
value|(0<<4)
end_define

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL__PRIM_WALK_INDICES
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL__PRIM_WALK_VERTEX_LIST
value|(2<<4)
end_define

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL__PRIM_WALK_VERTEX_EMBEDDED
value|(3<<4)
end_define

begin_comment
comment|/* I don't think I saw these three used.. */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL__COLOR_ORDER__SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL__TCL_OUTPUT_CTL_ENA__SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL__PROG_STREAM_ENA__SHIFT
value|10
end_define

begin_comment
comment|/* index size - when not set the indices are assumed to be 16 bit */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL__INDEX_SIZE_32bit
value|(1<<11)
end_define

begin_comment
comment|/* number of vertices */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_VF_CNTL__NUM_VERTICES__SHIFT
value|16
end_define

begin_comment
comment|/* BEGIN: Wild guesses */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_OUTPUT_VTX_FMT_0
value|0x2090
end_define

begin_define
define|#
directive|define
name|R300_VAP_OUTPUT_VTX_FMT_0__POS_PRESENT
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|R300_VAP_OUTPUT_VTX_FMT_0__COLOR_PRESENT
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|R300_VAP_OUTPUT_VTX_FMT_0__COLOR_1_PRESENT
value|(1<<2)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_OUTPUT_VTX_FMT_0__COLOR_2_PRESENT
value|(1<<3)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_OUTPUT_VTX_FMT_0__COLOR_3_PRESENT
value|(1<<4)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_OUTPUT_VTX_FMT_0__PT_SIZE_PRESENT
value|(1<<16)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_OUTPUT_VTX_FMT_1
value|0x2094
end_define

begin_comment
comment|/* each of the following is 3 bits wide, specifies number 	   of components */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_OUTPUT_VTX_FMT_1__TEX_0_COMP_CNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_VAP_OUTPUT_VTX_FMT_1__TEX_1_COMP_CNT_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|R300_VAP_OUTPUT_VTX_FMT_1__TEX_2_COMP_CNT_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|R300_VAP_OUTPUT_VTX_FMT_1__TEX_3_COMP_CNT_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|R300_VAP_OUTPUT_VTX_FMT_1__TEX_4_COMP_CNT_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|R300_VAP_OUTPUT_VTX_FMT_1__TEX_5_COMP_CNT_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|R300_VAP_OUTPUT_VTX_FMT_1__TEX_6_COMP_CNT_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|R300_VAP_OUTPUT_VTX_FMT_1__TEX_7_COMP_CNT_SHIFT
value|21
end_define

begin_comment
comment|/* END: Wild guesses */
end_comment

begin_define
define|#
directive|define
name|R300_SE_VTE_CNTL
value|0x20b0
end_define

begin_define
define|#
directive|define
name|R300_VPORT_X_SCALE_ENA
value|0x00000001
end_define

begin_define
define|#
directive|define
name|R300_VPORT_X_OFFSET_ENA
value|0x00000002
end_define

begin_define
define|#
directive|define
name|R300_VPORT_Y_SCALE_ENA
value|0x00000004
end_define

begin_define
define|#
directive|define
name|R300_VPORT_Y_OFFSET_ENA
value|0x00000008
end_define

begin_define
define|#
directive|define
name|R300_VPORT_Z_SCALE_ENA
value|0x00000010
end_define

begin_define
define|#
directive|define
name|R300_VPORT_Z_OFFSET_ENA
value|0x00000020
end_define

begin_define
define|#
directive|define
name|R300_VTX_XY_FMT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|R300_VTX_Z_FMT
value|0x00000200
end_define

begin_define
define|#
directive|define
name|R300_VTX_W0_FMT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|R300_VTX_W0_NORMALIZE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|R300_VTX_ST_DENORMALIZED
value|0x00001000
end_define

begin_comment
comment|/* BEGIN: Vertex data assembly - lots of uncertainties */
end_comment

begin_comment
comment|/* gap */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_CNTL_STATUS
value|0x2140
end_define

begin_define
define|#
directive|define
name|R300_VC_NO_SWAP
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VC_16BIT_SWAP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VC_32BIT_SWAP
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VAP_TCL_BYPASS
value|(1<< 8)
end_define

begin_comment
comment|/* gap */
end_comment

begin_comment
comment|/* Where do we get our vertex data?  *  * Vertex data either comes either from immediate mode registers or from  * vertex arrays.  * There appears to be no mixed mode (though we can force the pitch of  * vertex arrays to 0, effectively reusing the same element over and over  * again).  *  * Immediate mode is controlled by the INPUT_CNTL registers. I am not sure  * if these registers influence vertex array processing.  *  * Vertex arrays are controlled via the 3D_LOAD_VBPNTR packet3.  *  * In both cases, vertex attributes are then passed through INPUT_ROUTE.  *  * Beginning with INPUT_ROUTE_0_0 is a list of WORDs that route vertex data  * into the vertex processor's input registers.  * The first word routes the first input, the second word the second, etc.  * The corresponding input is routed into the register with the given index.  * The list is ended by a word with INPUT_ROUTE_END set.  *  * Always set COMPONENTS_4 in immediate mode.  */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_INPUT_ROUTE_0_0
value|0x2150
end_define

begin_define
define|#
directive|define
name|R300_INPUT_ROUTE_COMPONENTS_1
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|R300_INPUT_ROUTE_COMPONENTS_2
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_INPUT_ROUTE_COMPONENTS_3
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|R300_INPUT_ROUTE_COMPONENTS_4
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|R300_INPUT_ROUTE_COMPONENTS_RGBA
value|(4<< 0)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_INPUT_ROUTE_IDX_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|R300_VAP_INPUT_ROUTE_IDX_MASK
value|(31<< 8)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_INPUT_ROUTE_END
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|R300_INPUT_ROUTE_IMMEDIATE_MODE
value|(0<< 14)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_INPUT_ROUTE_FLOAT
value|(1<< 14)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_INPUT_ROUTE_UNSIGNED_BYTE
value|(2<< 14)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_INPUT_ROUTE_FLOAT_COLOR
value|(3<< 14)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_INPUT_ROUTE_0_1
value|0x2154
end_define

begin_define
define|#
directive|define
name|R300_VAP_INPUT_ROUTE_0_2
value|0x2158
end_define

begin_define
define|#
directive|define
name|R300_VAP_INPUT_ROUTE_0_3
value|0x215C
end_define

begin_define
define|#
directive|define
name|R300_VAP_INPUT_ROUTE_0_4
value|0x2160
end_define

begin_define
define|#
directive|define
name|R300_VAP_INPUT_ROUTE_0_5
value|0x2164
end_define

begin_define
define|#
directive|define
name|R300_VAP_INPUT_ROUTE_0_6
value|0x2168
end_define

begin_define
define|#
directive|define
name|R300_VAP_INPUT_ROUTE_0_7
value|0x216C
end_define

begin_comment
comment|/* gap */
end_comment

begin_comment
comment|/* Notes:  *  - always set up to produce at least two attributes:  *    if vertex program uses only position, fglrx will set normal, too  *  - INPUT_CNTL_0_COLOR and INPUT_CNTL_COLOR bits are always equal.  */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_INPUT_CNTL_0
value|0x2180
end_define

begin_define
define|#
directive|define
name|R300_INPUT_CNTL_0_COLOR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|R300_VAP_INPUT_CNTL_1
value|0x2184
end_define

begin_define
define|#
directive|define
name|R300_INPUT_CNTL_POS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|R300_INPUT_CNTL_NORMAL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|R300_INPUT_CNTL_COLOR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|R300_INPUT_CNTL_TC0
value|0x00000400
end_define

begin_define
define|#
directive|define
name|R300_INPUT_CNTL_TC1
value|0x00000800
end_define

begin_define
define|#
directive|define
name|R300_INPUT_CNTL_TC2
value|0x00001000
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_INPUT_CNTL_TC3
value|0x00002000
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_INPUT_CNTL_TC4
value|0x00004000
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_INPUT_CNTL_TC5
value|0x00008000
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_INPUT_CNTL_TC6
value|0x00010000
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_INPUT_CNTL_TC7
value|0x00020000
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_comment
comment|/* gap */
end_comment

begin_comment
comment|/* Words parallel to INPUT_ROUTE_0; All words that are active in INPUT_ROUTE_0  * are set to a swizzling bit pattern, other words are 0.  *  * In immediate mode, the pattern is always set to xyzw. In vertex array  * mode, the swizzling pattern is e.g. used to set zw components in texture  * coordinates with only tweo components.  */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_INPUT_ROUTE_1_0
value|0x21E0
end_define

begin_define
define|#
directive|define
name|R300_INPUT_ROUTE_SELECT_X
value|0
end_define

begin_define
define|#
directive|define
name|R300_INPUT_ROUTE_SELECT_Y
value|1
end_define

begin_define
define|#
directive|define
name|R300_INPUT_ROUTE_SELECT_Z
value|2
end_define

begin_define
define|#
directive|define
name|R300_INPUT_ROUTE_SELECT_W
value|3
end_define

begin_define
define|#
directive|define
name|R300_INPUT_ROUTE_SELECT_ZERO
value|4
end_define

begin_define
define|#
directive|define
name|R300_INPUT_ROUTE_SELECT_ONE
value|5
end_define

begin_define
define|#
directive|define
name|R300_INPUT_ROUTE_SELECT_MASK
value|7
end_define

begin_define
define|#
directive|define
name|R300_INPUT_ROUTE_X_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_INPUT_ROUTE_Y_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|R300_INPUT_ROUTE_Z_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|R300_INPUT_ROUTE_W_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|R300_INPUT_ROUTE_ENABLE
value|(15<< 12)
end_define

begin_define
define|#
directive|define
name|R300_VAP_INPUT_ROUTE_1_1
value|0x21E4
end_define

begin_define
define|#
directive|define
name|R300_VAP_INPUT_ROUTE_1_2
value|0x21E8
end_define

begin_define
define|#
directive|define
name|R300_VAP_INPUT_ROUTE_1_3
value|0x21EC
end_define

begin_define
define|#
directive|define
name|R300_VAP_INPUT_ROUTE_1_4
value|0x21F0
end_define

begin_define
define|#
directive|define
name|R300_VAP_INPUT_ROUTE_1_5
value|0x21F4
end_define

begin_define
define|#
directive|define
name|R300_VAP_INPUT_ROUTE_1_6
value|0x21F8
end_define

begin_define
define|#
directive|define
name|R300_VAP_INPUT_ROUTE_1_7
value|0x21FC
end_define

begin_comment
comment|/* END: Vertex data assembly */
end_comment

begin_comment
comment|/* gap */
end_comment

begin_comment
comment|/* BEGIN: Upload vertex program and data */
end_comment

begin_comment
comment|/*  * The programmable vertex shader unit has a memory bank of unknown size  * that can be written to in 16 byte units by writing the address into  * UPLOAD_ADDRESS, followed by data in UPLOAD_DATA (multiples of 4 DWORDs).  *  * Pointers into the memory bank are always in multiples of 16 bytes.  *  * The memory bank is divided into areas with fixed meaning.  *  * Starting at address UPLOAD_PROGRAM: Vertex program instructions.  * Native limits reported by drivers from ATI suggest size 256 (i.e. 4KB),  * whereas the difference between known addresses suggests size 512.  *  * Starting at address UPLOAD_PARAMETERS: Vertex program parameters.  * Native reported limits and the VPI layout suggest size 256, whereas  * difference between known addresses suggests size 512.  *  * At address UPLOAD_POINTSIZE is a vector (0, 0, ps, 0), where ps is the  * floating point pointsize. The exact purpose of this state is uncertain,  * as there is also the R300_RE_POINTSIZE register.  *  * Multiple vertex programs and parameter sets can be loaded at once,  * which could explain the size discrepancy.  */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_PVS_UPLOAD_ADDRESS
value|0x2200
end_define

begin_define
define|#
directive|define
name|R300_PVS_UPLOAD_PROGRAM
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R300_PVS_UPLOAD_PARAMETERS
value|0x00000200
end_define

begin_define
define|#
directive|define
name|R300_PVS_UPLOAD_POINTSIZE
value|0x00000406
end_define

begin_comment
comment|/* gap */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_PVS_UPLOAD_DATA
value|0x2208
end_define

begin_comment
comment|/* END: Upload vertex program and data */
end_comment

begin_comment
comment|/* gap */
end_comment

begin_comment
comment|/* I do not know the purpose of this register. However, I do know that  * it is set to 221C_CLEAR for clear operations and to 221C_NORMAL  * for normal rendering.  */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_UNKNOWN_221C
value|0x221C
end_define

begin_define
define|#
directive|define
name|R300_221C_NORMAL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R300_221C_CLEAR
value|0x0001C000
end_define

begin_comment
comment|/* These seem to be per-pixel and per-vertex X and Y clipping planes. The first  * plane is per-pixel and the second plane is per-vertex.  *  * This was determined by experimentation alone but I believe it is correct.  *  * These registers are called X_QUAD0_1_FL to X_QUAD0_4_FL by glxtest.  */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_CLIP_X_0
value|0x2220
end_define

begin_define
define|#
directive|define
name|R300_VAP_CLIP_X_1
value|0x2224
end_define

begin_define
define|#
directive|define
name|R300_VAP_CLIP_Y_0
value|0x2228
end_define

begin_define
define|#
directive|define
name|R300_VAP_CLIP_Y_1
value|0x2230
end_define

begin_comment
comment|/* gap */
end_comment

begin_comment
comment|/* Sometimes, END_OF_PKT and 0x2284=0 are the only commands sent between  * rendering commands and overwriting vertex program parameters.  * Therefore, I suspect writing zero to 0x2284 synchronizes the engine and  * avoids bugs caused by still running shaders reading bad data from memory.  */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_PVS_STATE_FLUSH_REG
value|0x2284
end_define

begin_comment
comment|/* Absolutely no clue what this register is about. */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_UNKNOWN_2288
value|0x2288
end_define

begin_define
define|#
directive|define
name|R300_2288_R300
value|0x00750000
end_define

begin_comment
comment|/* -- nh */
end_comment

begin_define
define|#
directive|define
name|R300_2288_RV350
value|0x0000FFFF
end_define

begin_comment
comment|/* -- Vladimir */
end_comment

begin_comment
comment|/* gap */
end_comment

begin_comment
comment|/* Addresses are relative to the vertex program instruction area of the  * memory bank. PROGRAM_END points to the last instruction of the active  * program  *  * The meaning of the two UNKNOWN fields is obviously not known. However,  * experiments so far have shown that both *must* point to an instruction  * inside the vertex program, otherwise the GPU locks up.  *  * fglrx usually sets CNTL_3_UNKNOWN to the end of the program and  * R300_PVS_CNTL_1_POS_END_SHIFT points to instruction where last write to  * position takes place.  *  * Most likely this is used to ignore rest of the program in cases  * where group of verts aren't visible. For some reason this "section"  * is sometimes accepted other instruction that have no relationship with  * position calculations.  */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_PVS_CNTL_1
value|0x22D0
end_define

begin_define
define|#
directive|define
name|R300_PVS_CNTL_1_PROGRAM_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_PVS_CNTL_1_POS_END_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|R300_PVS_CNTL_1_PROGRAM_END_SHIFT
value|20
end_define

begin_comment
comment|/* Addresses are relative the vertex program parameters area. */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_PVS_CNTL_2
value|0x22D4
end_define

begin_define
define|#
directive|define
name|R300_PVS_CNTL_2_PARAM_OFFSET_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_PVS_CNTL_2_PARAM_COUNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|R300_VAP_PVS_CNTL_3
value|0x22D8
end_define

begin_define
define|#
directive|define
name|R300_PVS_CNTL_3_PROGRAM_UNKNOWN_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|R300_PVS_CNTL_3_PROGRAM_UNKNOWN2_SHIFT
value|0
end_define

begin_comment
comment|/* The entire range from 0x2300 to 0x2AC inclusive seems to be used for  * immediate vertices  */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_VTX_COLOR_R
value|0x2464
end_define

begin_define
define|#
directive|define
name|R300_VAP_VTX_COLOR_G
value|0x2468
end_define

begin_define
define|#
directive|define
name|R300_VAP_VTX_COLOR_B
value|0x246C
end_define

begin_define
define|#
directive|define
name|R300_VAP_VTX_POS_0_X_1
value|0x2490
end_define

begin_comment
comment|/* used for glVertex2*() */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_VTX_POS_0_Y_1
value|0x2494
end_define

begin_define
define|#
directive|define
name|R300_VAP_VTX_COLOR_PKD
value|0x249C
end_define

begin_comment
comment|/* RGBA */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_VTX_POS_0_X_2
value|0x24A0
end_define

begin_comment
comment|/* used for glVertex3*() */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_VTX_POS_0_Y_2
value|0x24A4
end_define

begin_define
define|#
directive|define
name|R300_VAP_VTX_POS_0_Z_2
value|0x24A8
end_define

begin_comment
comment|/* write 0 to indicate end of packet? */
end_comment

begin_define
define|#
directive|define
name|R300_VAP_VTX_END_OF_PKT
value|0x24AC
end_define

begin_comment
comment|/* gap */
end_comment

begin_comment
comment|/* These are values from r300_reg/r300_reg.h - they are known to be correct  * and are here so we can use one register file instead of several  * - Vladimir  */
end_comment

begin_define
define|#
directive|define
name|R300_GB_VAP_RASTER_VTX_FMT_0
value|0x4000
end_define

begin_define
define|#
directive|define
name|R300_GB_VAP_RASTER_VTX_FMT_0__POS_PRESENT
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|R300_GB_VAP_RASTER_VTX_FMT_0__COLOR_0_PRESENT
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|R300_GB_VAP_RASTER_VTX_FMT_0__COLOR_1_PRESENT
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|R300_GB_VAP_RASTER_VTX_FMT_0__COLOR_2_PRESENT
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|R300_GB_VAP_RASTER_VTX_FMT_0__COLOR_3_PRESENT
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|R300_GB_VAP_RASTER_VTX_FMT_0__COLOR_SPACE
value|(0xf<<5)
end_define

begin_define
define|#
directive|define
name|R300_GB_VAP_RASTER_VTX_FMT_0__PT_SIZE_PRESENT
value|(0x1<<16)
end_define

begin_define
define|#
directive|define
name|R300_GB_VAP_RASTER_VTX_FMT_1
value|0x4004
end_define

begin_comment
comment|/* each of the following is 3 bits wide, specifies number 	   of components */
end_comment

begin_define
define|#
directive|define
name|R300_GB_VAP_RASTER_VTX_FMT_1__TEX_0_COMP_CNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_GB_VAP_RASTER_VTX_FMT_1__TEX_1_COMP_CNT_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|R300_GB_VAP_RASTER_VTX_FMT_1__TEX_2_COMP_CNT_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|R300_GB_VAP_RASTER_VTX_FMT_1__TEX_3_COMP_CNT_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|R300_GB_VAP_RASTER_VTX_FMT_1__TEX_4_COMP_CNT_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|R300_GB_VAP_RASTER_VTX_FMT_1__TEX_5_COMP_CNT_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|R300_GB_VAP_RASTER_VTX_FMT_1__TEX_6_COMP_CNT_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|R300_GB_VAP_RASTER_VTX_FMT_1__TEX_7_COMP_CNT_SHIFT
value|21
end_define

begin_comment
comment|/* UNK30 seems to enables point to quad transformation on textures  * (or something closely related to that).  * This bit is rather fatal at the time being due to lackings at pixel  * shader side  */
end_comment

begin_define
define|#
directive|define
name|R300_GB_ENABLE
value|0x4008
end_define

begin_define
define|#
directive|define
name|R300_GB_POINT_STUFF_ENABLE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|R300_GB_LINE_STUFF_ENABLE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|R300_GB_TRIANGLE_STUFF_ENABLE
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|R300_GB_STENCIL_AUTO_ENABLE
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|R300_GB_UNK31
value|(1<<31)
end_define

begin_comment
comment|/* each of the following is 2 bits wide */
end_comment

begin_define
define|#
directive|define
name|R300_GB_TEX_REPLICATE
value|0
end_define

begin_define
define|#
directive|define
name|R300_GB_TEX_ST
value|1
end_define

begin_define
define|#
directive|define
name|R300_GB_TEX_STR
value|2
end_define

begin_define
define|#
directive|define
name|R300_GB_TEX0_SOURCE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|R300_GB_TEX1_SOURCE_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|R300_GB_TEX2_SOURCE_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|R300_GB_TEX3_SOURCE_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|R300_GB_TEX4_SOURCE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|R300_GB_TEX5_SOURCE_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|R300_GB_TEX6_SOURCE_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|R300_GB_TEX7_SOURCE_SHIFT
value|30
end_define

begin_comment
comment|/* MSPOS - positions for multisample antialiasing (?) */
end_comment

begin_define
define|#
directive|define
name|R300_GB_MSPOS0
value|0x4010
end_define

begin_comment
comment|/* shifts - each of the fields is 4 bits */
end_comment

begin_define
define|#
directive|define
name|R300_GB_MSPOS0__MS_X0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_GB_MSPOS0__MS_Y0_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|R300_GB_MSPOS0__MS_X1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|R300_GB_MSPOS0__MS_Y1_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|R300_GB_MSPOS0__MS_X2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|R300_GB_MSPOS0__MS_Y2_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|R300_GB_MSPOS0__MSBD0_Y
value|24
end_define

begin_define
define|#
directive|define
name|R300_GB_MSPOS0__MSBD0_X
value|28
end_define

begin_define
define|#
directive|define
name|R300_GB_MSPOS1
value|0x4014
end_define

begin_define
define|#
directive|define
name|R300_GB_MSPOS1__MS_X3_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_GB_MSPOS1__MS_Y3_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|R300_GB_MSPOS1__MS_X4_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|R300_GB_MSPOS1__MS_Y4_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|R300_GB_MSPOS1__MS_X5_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|R300_GB_MSPOS1__MS_Y5_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|R300_GB_MSPOS1__MSBD1
value|24
end_define

begin_define
define|#
directive|define
name|R300_GB_TILE_CONFIG
value|0x4018
end_define

begin_define
define|#
directive|define
name|R300_GB_TILE_ENABLE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|R300_GB_TILE_PIPE_COUNT_RV300
value|0
end_define

begin_define
define|#
directive|define
name|R300_GB_TILE_PIPE_COUNT_R300
value|(3<<1)
end_define

begin_define
define|#
directive|define
name|R300_GB_TILE_PIPE_COUNT_R420
value|(7<<1)
end_define

begin_define
define|#
directive|define
name|R300_GB_TILE_PIPE_COUNT_RV410
value|(3<<1)
end_define

begin_define
define|#
directive|define
name|R300_GB_TILE_SIZE_8
value|0
end_define

begin_define
define|#
directive|define
name|R300_GB_TILE_SIZE_16
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|R300_GB_TILE_SIZE_32
value|(2<<4)
end_define

begin_define
define|#
directive|define
name|R300_GB_SUPER_SIZE_1
value|(0<<6)
end_define

begin_define
define|#
directive|define
name|R300_GB_SUPER_SIZE_2
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|R300_GB_SUPER_SIZE_4
value|(2<<6)
end_define

begin_define
define|#
directive|define
name|R300_GB_SUPER_SIZE_8
value|(3<<6)
end_define

begin_define
define|#
directive|define
name|R300_GB_SUPER_SIZE_16
value|(4<<6)
end_define

begin_define
define|#
directive|define
name|R300_GB_SUPER_SIZE_32
value|(5<<6)
end_define

begin_define
define|#
directive|define
name|R300_GB_SUPER_SIZE_64
value|(6<<6)
end_define

begin_define
define|#
directive|define
name|R300_GB_SUPER_SIZE_128
value|(7<<6)
end_define

begin_define
define|#
directive|define
name|R300_GB_SUPER_X_SHIFT
value|9
end_define

begin_comment
comment|/* 3 bits wide */
end_comment

begin_define
define|#
directive|define
name|R300_GB_SUPER_Y_SHIFT
value|12
end_define

begin_comment
comment|/* 3 bits wide */
end_comment

begin_define
define|#
directive|define
name|R300_GB_SUPER_TILE_A
value|0
end_define

begin_define
define|#
directive|define
name|R300_GB_SUPER_TILE_B
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|R300_GB_SUBPIXEL_1_12
value|0
end_define

begin_define
define|#
directive|define
name|R300_GB_SUBPIXEL_1_16
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|R300_GB_FIFO_SIZE
value|0x4024
end_define

begin_comment
comment|/* each of the following is 2 bits wide */
end_comment

begin_define
define|#
directive|define
name|R300_GB_FIFO_SIZE_32
value|0
end_define

begin_define
define|#
directive|define
name|R300_GB_FIFO_SIZE_64
value|1
end_define

begin_define
define|#
directive|define
name|R300_GB_FIFO_SIZE_128
value|2
end_define

begin_define
define|#
directive|define
name|R300_GB_FIFO_SIZE_256
value|3
end_define

begin_define
define|#
directive|define
name|R300_SC_IFIFO_SIZE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_SC_TZFIFO_SIZE_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|R300_SC_BFIFO_SIZE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|R300_US_OFIFO_SIZE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|R300_US_WFIFO_SIZE_SHIFT
value|14
end_define

begin_comment
comment|/* the following use the same constants as above, but meaning is 	   is times 2 (i.e. instead of 32 words it means 64 */
end_comment

begin_define
define|#
directive|define
name|R300_RS_TFIFO_SIZE_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|R300_RS_CFIFO_SIZE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|R300_US_RAM_SIZE_SHIFT
value|10
end_define

begin_comment
comment|/* watermarks, 3 bits wide */
end_comment

begin_define
define|#
directive|define
name|R300_RS_HIGHWATER_COL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|R300_RS_HIGHWATER_TEX_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|R300_OFIFO_HIGHWATER_SHIFT
value|22
end_define

begin_comment
comment|/* two bits only */
end_comment

begin_define
define|#
directive|define
name|R300_CUBE_FIFO_HIGHWATER_COL_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|R300_GB_SELECT
value|0x401C
end_define

begin_define
define|#
directive|define
name|R300_GB_FOG_SELECT_C0A
value|0
end_define

begin_define
define|#
directive|define
name|R300_GB_FOG_SELECT_C1A
value|1
end_define

begin_define
define|#
directive|define
name|R300_GB_FOG_SELECT_C2A
value|2
end_define

begin_define
define|#
directive|define
name|R300_GB_FOG_SELECT_C3A
value|3
end_define

begin_define
define|#
directive|define
name|R300_GB_FOG_SELECT_1_1_W
value|4
end_define

begin_define
define|#
directive|define
name|R300_GB_FOG_SELECT_Z
value|5
end_define

begin_define
define|#
directive|define
name|R300_GB_DEPTH_SELECT_Z
value|0
end_define

begin_define
define|#
directive|define
name|R300_GB_DEPTH_SELECT_1_1_W
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|R300_GB_W_SELECT_1_W
value|0
end_define

begin_define
define|#
directive|define
name|R300_GB_W_SELECT_1
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|R300_GB_AA_CONFIG
value|0x4020
end_define

begin_define
define|#
directive|define
name|R300_AA_DISABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|R300_AA_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|R300_AA_SUBSAMPLES_2
value|0
end_define

begin_define
define|#
directive|define
name|R300_AA_SUBSAMPLES_3
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|R300_AA_SUBSAMPLES_4
value|(2<<1)
end_define

begin_define
define|#
directive|define
name|R300_AA_SUBSAMPLES_6
value|(3<<1)
end_define

begin_comment
comment|/* gap */
end_comment

begin_comment
comment|/* Zero to flush caches. */
end_comment

begin_define
define|#
directive|define
name|R300_TX_INVALTAGS
value|0x4100
end_define

begin_define
define|#
directive|define
name|R300_TX_FLUSH
value|0x0
end_define

begin_comment
comment|/* The upper enable bits are guessed, based on fglrx reported limits. */
end_comment

begin_define
define|#
directive|define
name|R300_TX_ENABLE
value|0x4104
end_define

begin_define
define|#
directive|define
name|R300_TX_ENABLE_0
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_TX_ENABLE_1
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|R300_TX_ENABLE_2
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|R300_TX_ENABLE_3
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|R300_TX_ENABLE_4
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|R300_TX_ENABLE_5
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|R300_TX_ENABLE_6
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|R300_TX_ENABLE_7
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|R300_TX_ENABLE_8
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|R300_TX_ENABLE_9
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|R300_TX_ENABLE_10
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|R300_TX_ENABLE_11
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|R300_TX_ENABLE_12
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|R300_TX_ENABLE_13
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|R300_TX_ENABLE_14
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|R300_TX_ENABLE_15
value|(1<< 15)
end_define

begin_comment
comment|/* The pointsize is given in multiples of 6. The pointsize can be  * enormous: Clear() renders a single point that fills the entire  * framebuffer.  */
end_comment

begin_define
define|#
directive|define
name|R300_RE_POINTSIZE
value|0x421C
end_define

begin_define
define|#
directive|define
name|R300_POINTSIZE_Y_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_POINTSIZE_Y_MASK
value|(0xFFFF<< 0)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_POINTSIZE_X_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|R300_POINTSIZE_X_MASK
value|(0xFFFF<< 16)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_POINTSIZE_MAX
value|(R300_POINTSIZE_Y_MASK / 6)
end_define

begin_comment
comment|/* The line width is given in multiples of 6.  * In default mode lines are classified as vertical lines.  * HO: horizontal  * VE: vertical or horizontal  * HO& VE: no classification  */
end_comment

begin_define
define|#
directive|define
name|R300_RE_LINE_CNT
value|0x4234
end_define

begin_define
define|#
directive|define
name|R300_LINESIZE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_LINESIZE_MASK
value|(0xFFFF<< 0)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_LINESIZE_MAX
value|(R300_LINESIZE_MASK / 6)
end_define

begin_define
define|#
directive|define
name|R300_LINE_CNT_HO
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|R300_LINE_CNT_VE
value|(1<< 17)
end_define

begin_comment
comment|/* Some sort of scale or clamp value for texcoordless textures. */
end_comment

begin_define
define|#
directive|define
name|R300_RE_UNK4238
value|0x4238
end_define

begin_comment
comment|/* Something shade related */
end_comment

begin_define
define|#
directive|define
name|R300_RE_SHADE
value|0x4274
end_define

begin_define
define|#
directive|define
name|R300_RE_SHADE_MODEL
value|0x4278
end_define

begin_define
define|#
directive|define
name|R300_RE_SHADE_MODEL_SMOOTH
value|0x3aaaa
end_define

begin_define
define|#
directive|define
name|R300_RE_SHADE_MODEL_FLAT
value|0x39595
end_define

begin_comment
comment|/* Dangerous */
end_comment

begin_define
define|#
directive|define
name|R300_RE_POLYGON_MODE
value|0x4288
end_define

begin_define
define|#
directive|define
name|R300_PM_ENABLED
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PM_FRONT_POINT
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PM_BACK_POINT
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PM_FRONT_LINE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|R300_PM_FRONT_FILL
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|R300_PM_BACK_LINE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|R300_PM_BACK_FILL
value|(1<< 8)
end_define

begin_comment
comment|/* Fog parameters */
end_comment

begin_define
define|#
directive|define
name|R300_RE_FOG_SCALE
value|0x4294
end_define

begin_define
define|#
directive|define
name|R300_RE_FOG_START
value|0x4298
end_define

begin_comment
comment|/* Not sure why there are duplicate of factor and constant values.  * My best guess so far is that there are separate zbiases for test and write.  * Ordering might be wrong.  * Some of the tests indicate that fgl has a fallback implementation of zbias  * via pixel shaders.  */
end_comment

begin_define
define|#
directive|define
name|R300_RE_ZBIAS_CNTL
value|0x42A0
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_RE_ZBIAS_T_FACTOR
value|0x42A4
end_define

begin_define
define|#
directive|define
name|R300_RE_ZBIAS_T_CONSTANT
value|0x42A8
end_define

begin_define
define|#
directive|define
name|R300_RE_ZBIAS_W_FACTOR
value|0x42AC
end_define

begin_define
define|#
directive|define
name|R300_RE_ZBIAS_W_CONSTANT
value|0x42B0
end_define

begin_comment
comment|/* This register needs to be set to (1<<1) for RV350 to correctly  * perform depth test (see --vb-triangles in r300_demo)  * Don't know about other chips. - Vladimir  * This is set to 3 when GL_POLYGON_OFFSET_FILL is on.  * My guess is that there are two bits for each zbias primitive  * (FILL, LINE, POINT).  *  One to enable depth test and one for depth write.  * Yet this doesn't explain why depth writes work ...  */
end_comment

begin_define
define|#
directive|define
name|R300_RE_OCCLUSION_CNTL
value|0x42B4
end_define

begin_define
define|#
directive|define
name|R300_OCCLUSION_ON
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|R300_RE_CULL_CNTL
value|0x42B8
end_define

begin_define
define|#
directive|define
name|R300_CULL_FRONT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_CULL_BACK
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|R300_FRONT_FACE_CCW
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|R300_FRONT_FACE_CW
value|(1<< 2)
end_define

begin_comment
comment|/* BEGIN: Rasterization / Interpolators - many guesses */
end_comment

begin_comment
comment|/* 0_UNKNOWN_18 has always been set except for clear operations.  * TC_CNT is the number of incoming texture coordinate sets (i.e. it depends  * on the vertex program, *not* the fragment program)  */
end_comment

begin_define
define|#
directive|define
name|R300_RS_CNTL_0
value|0x4300
end_define

begin_define
define|#
directive|define
name|R300_RS_CNTL_TC_CNT_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|R300_RS_CNTL_TC_CNT_MASK
value|(7<< 2)
end_define

begin_comment
comment|/* number of color interpolators used */
end_comment

begin_define
define|#
directive|define
name|R300_RS_CNTL_CI_CNT_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|R300_RS_CNTL_0_UNKNOWN_18
value|(1<< 18)
end_define

begin_comment
comment|/* Guess: RS_CNTL_1 holds the index of the highest used RS_ROUTE_n 	   register. */
end_comment

begin_define
define|#
directive|define
name|R300_RS_CNTL_1
value|0x4304
end_define

begin_comment
comment|/* gap */
end_comment

begin_comment
comment|/* Only used for texture coordinates.  * Use the source field to route texture coordinate input from the  * vertex program to the desired interpolator. Note that the source  * field is relative to the outputs the vertex program *actually*  * writes. If a vertex program only writes texcoord[1], this will  * be source index 0.  * Set INTERP_USED on all interpolators that produce data used by  * the fragment program. INTERP_USED looks like a swizzling mask,  * but I haven't seen it used that way.  *  * Note: The _UNKNOWN constants are always set in their respective  * register. I don't know if this is necessary.  */
end_comment

begin_define
define|#
directive|define
name|R300_RS_INTERP_0
value|0x4310
end_define

begin_define
define|#
directive|define
name|R300_RS_INTERP_1
value|0x4314
end_define

begin_define
define|#
directive|define
name|R300_RS_INTERP_1_UNKNOWN
value|0x40
end_define

begin_define
define|#
directive|define
name|R300_RS_INTERP_2
value|0x4318
end_define

begin_define
define|#
directive|define
name|R300_RS_INTERP_2_UNKNOWN
value|0x80
end_define

begin_define
define|#
directive|define
name|R300_RS_INTERP_3
value|0x431C
end_define

begin_define
define|#
directive|define
name|R300_RS_INTERP_3_UNKNOWN
value|0xC0
end_define

begin_define
define|#
directive|define
name|R300_RS_INTERP_4
value|0x4320
end_define

begin_define
define|#
directive|define
name|R300_RS_INTERP_5
value|0x4324
end_define

begin_define
define|#
directive|define
name|R300_RS_INTERP_6
value|0x4328
end_define

begin_define
define|#
directive|define
name|R300_RS_INTERP_7
value|0x432C
end_define

begin_define
define|#
directive|define
name|R300_RS_INTERP_SRC_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|R300_RS_INTERP_SRC_MASK
value|(7<< 2)
end_define

begin_define
define|#
directive|define
name|R300_RS_INTERP_USED
value|0x00D10000
end_define

begin_comment
comment|/* These DWORDs control how vertex data is routed into fragment program  * registers, after interpolators.  */
end_comment

begin_define
define|#
directive|define
name|R300_RS_ROUTE_0
value|0x4330
end_define

begin_define
define|#
directive|define
name|R300_RS_ROUTE_1
value|0x4334
end_define

begin_define
define|#
directive|define
name|R300_RS_ROUTE_2
value|0x4338
end_define

begin_define
define|#
directive|define
name|R300_RS_ROUTE_3
value|0x433C
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_RS_ROUTE_4
value|0x4340
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_RS_ROUTE_5
value|0x4344
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_RS_ROUTE_6
value|0x4348
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_RS_ROUTE_7
value|0x434C
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_RS_ROUTE_SOURCE_INTERP_0
value|0
end_define

begin_define
define|#
directive|define
name|R300_RS_ROUTE_SOURCE_INTERP_1
value|1
end_define

begin_define
define|#
directive|define
name|R300_RS_ROUTE_SOURCE_INTERP_2
value|2
end_define

begin_define
define|#
directive|define
name|R300_RS_ROUTE_SOURCE_INTERP_3
value|3
end_define

begin_define
define|#
directive|define
name|R300_RS_ROUTE_SOURCE_INTERP_4
value|4
end_define

begin_define
define|#
directive|define
name|R300_RS_ROUTE_SOURCE_INTERP_5
value|5
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_RS_ROUTE_SOURCE_INTERP_6
value|6
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_RS_ROUTE_SOURCE_INTERP_7
value|7
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_RS_ROUTE_ENABLE
value|(1<< 3)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_RS_ROUTE_DEST_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|R300_RS_ROUTE_DEST_MASK
value|(31<< 6)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_comment
comment|/* Special handling for color: When the fragment program uses color,  * the ROUTE_0_COLOR bit is set and ROUTE_0_COLOR_DEST contains the  * color register index.  *  * Apparently you may set the R300_RS_ROUTE_0_COLOR bit, but not provide any  * R300_RS_ROUTE_0_COLOR_DEST value; this setup is used for clearing the state.  * See r300_ioctl.c:r300EmitClearState. I'm not sure if this setup is strictly  * correct or not. - Oliver.  */
end_comment

begin_define
define|#
directive|define
name|R300_RS_ROUTE_0_COLOR
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|R300_RS_ROUTE_0_COLOR_DEST_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|R300_RS_ROUTE_0_COLOR_DEST_MASK
value|(31<< 17)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_comment
comment|/* As above, but for secondary color */
end_comment

begin_define
define|#
directive|define
name|R300_RS_ROUTE_1_COLOR1
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|R300_RS_ROUTE_1_COLOR1_DEST_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|R300_RS_ROUTE_1_COLOR1_DEST_MASK
value|(31<< 17)
end_define

begin_define
define|#
directive|define
name|R300_RS_ROUTE_1_UNKNOWN11
value|(1<< 11)
end_define

begin_comment
comment|/* END: Rasterization / Interpolators - many guesses */
end_comment

begin_comment
comment|/* Hierarchical Z Enable */
end_comment

begin_define
define|#
directive|define
name|R300_SC_HYPERZ
value|0x43a4
end_define

begin_define
define|#
directive|define
name|R300_SC_HYPERZ_DISABLE
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|R300_SC_HYPERZ_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_SC_HYPERZ_MIN
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|R300_SC_HYPERZ_MAX
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|R300_SC_HYPERZ_ADJ_256
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|R300_SC_HYPERZ_ADJ_128
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|R300_SC_HYPERZ_ADJ_64
value|(2<< 2)
end_define

begin_define
define|#
directive|define
name|R300_SC_HYPERZ_ADJ_32
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|R300_SC_HYPERZ_ADJ_16
value|(4<< 2)
end_define

begin_define
define|#
directive|define
name|R300_SC_HYPERZ_ADJ_8
value|(5<< 2)
end_define

begin_define
define|#
directive|define
name|R300_SC_HYPERZ_ADJ_4
value|(6<< 2)
end_define

begin_define
define|#
directive|define
name|R300_SC_HYPERZ_ADJ_2
value|(7<< 2)
end_define

begin_define
define|#
directive|define
name|R300_SC_HYPERZ_HZ_Z0MIN_NO
value|(0<< 5)
end_define

begin_define
define|#
directive|define
name|R300_SC_HYPERZ_HZ_Z0MIN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|R300_SC_HYPERZ_HZ_Z0MAX_NO
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|R300_SC_HYPERZ_HZ_Z0MAX
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|R300_SC_EDGERULE
value|0x43a8
end_define

begin_comment
comment|/* BEGIN: Scissors and cliprects */
end_comment

begin_comment
comment|/* There are four clipping rectangles. Their corner coordinates are inclusive.  * Every pixel is assigned a number from 0 and 15 by setting bits 0-3 depending  * on whether the pixel is inside cliprects 0-3, respectively. For example,  * if a pixel is inside cliprects 0 and 1, but outside 2 and 3, it is assigned  * the number 3 (binary 0011).  * Iff the bit corresponding to the pixel's number in RE_CLIPRECT_CNTL is set,  * the pixel is rasterized.  *  * In addition to this, there is a scissors rectangle. Only pixels inside the  * scissors rectangle are drawn. (coordinates are inclusive)  *  * For some reason, the top-left corner of the framebuffer is at (1440, 1440)  * for the purpose of clipping and scissors.  */
end_comment

begin_define
define|#
directive|define
name|R300_RE_CLIPRECT_TL_0
value|0x43B0
end_define

begin_define
define|#
directive|define
name|R300_RE_CLIPRECT_BR_0
value|0x43B4
end_define

begin_define
define|#
directive|define
name|R300_RE_CLIPRECT_TL_1
value|0x43B8
end_define

begin_define
define|#
directive|define
name|R300_RE_CLIPRECT_BR_1
value|0x43BC
end_define

begin_define
define|#
directive|define
name|R300_RE_CLIPRECT_TL_2
value|0x43C0
end_define

begin_define
define|#
directive|define
name|R300_RE_CLIPRECT_BR_2
value|0x43C4
end_define

begin_define
define|#
directive|define
name|R300_RE_CLIPRECT_TL_3
value|0x43C8
end_define

begin_define
define|#
directive|define
name|R300_RE_CLIPRECT_BR_3
value|0x43CC
end_define

begin_define
define|#
directive|define
name|R300_CLIPRECT_OFFSET
value|1440
end_define

begin_define
define|#
directive|define
name|R300_CLIPRECT_MASK
value|0x1FFF
end_define

begin_define
define|#
directive|define
name|R300_CLIPRECT_X_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_CLIPRECT_X_MASK
value|(0x1FFF<< 0)
end_define

begin_define
define|#
directive|define
name|R300_CLIPRECT_Y_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|R300_CLIPRECT_Y_MASK
value|(0x1FFF<< 13)
end_define

begin_define
define|#
directive|define
name|R300_RE_CLIPRECT_CNTL
value|0x43D0
end_define

begin_define
define|#
directive|define
name|R300_CLIP_OUT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_CLIP_0
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|R300_CLIP_1
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|R300_CLIP_10
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|R300_CLIP_2
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|R300_CLIP_20
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|R300_CLIP_21
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|R300_CLIP_210
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|R300_CLIP_3
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|R300_CLIP_30
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|R300_CLIP_31
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|R300_CLIP_310
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|R300_CLIP_32
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|R300_CLIP_320
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|R300_CLIP_321
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|R300_CLIP_3210
value|(1<< 15)
end_define

begin_comment
comment|/* gap */
end_comment

begin_define
define|#
directive|define
name|R300_RE_SCISSORS_TL
value|0x43E0
end_define

begin_define
define|#
directive|define
name|R300_RE_SCISSORS_BR
value|0x43E4
end_define

begin_define
define|#
directive|define
name|R300_SCISSORS_OFFSET
value|1440
end_define

begin_define
define|#
directive|define
name|R300_SCISSORS_X_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_SCISSORS_X_MASK
value|(0x1FFF<< 0)
end_define

begin_define
define|#
directive|define
name|R300_SCISSORS_Y_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|R300_SCISSORS_Y_MASK
value|(0x1FFF<< 13)
end_define

begin_comment
comment|/* END: Scissors and cliprects */
end_comment

begin_comment
comment|/* BEGIN: Texture specification */
end_comment

begin_comment
comment|/*  * The texture specification dwords are grouped by meaning and not by texture  * unit. This means that e.g. the offset for texture image unit N is found in  * register TX_OFFSET_0 + (4*N)  */
end_comment

begin_define
define|#
directive|define
name|R300_TX_FILTER_0
value|0x4400
end_define

begin_define
define|#
directive|define
name|R300_TX_REPEAT
value|0
end_define

begin_define
define|#
directive|define
name|R300_TX_MIRRORED
value|1
end_define

begin_define
define|#
directive|define
name|R300_TX_CLAMP
value|4
end_define

begin_define
define|#
directive|define
name|R300_TX_CLAMP_TO_EDGE
value|2
end_define

begin_define
define|#
directive|define
name|R300_TX_CLAMP_TO_BORDER
value|6
end_define

begin_define
define|#
directive|define
name|R300_TX_WRAP_S_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_TX_WRAP_S_MASK
value|(7<< 0)
end_define

begin_define
define|#
directive|define
name|R300_TX_WRAP_T_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|R300_TX_WRAP_T_MASK
value|(7<< 3)
end_define

begin_define
define|#
directive|define
name|R300_TX_WRAP_Q_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|R300_TX_WRAP_Q_MASK
value|(7<< 6)
end_define

begin_define
define|#
directive|define
name|R300_TX_MAG_FILTER_NEAREST
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|R300_TX_MAG_FILTER_LINEAR
value|(2<< 9)
end_define

begin_define
define|#
directive|define
name|R300_TX_MAG_FILTER_MASK
value|(3<< 9)
end_define

begin_define
define|#
directive|define
name|R300_TX_MIN_FILTER_NEAREST
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|R300_TX_MIN_FILTER_LINEAR
value|(2<< 11)
end_define

begin_define
define|#
directive|define
name|R300_TX_MIN_FILTER_NEAREST_MIP_NEAREST
value|(5<<  11)
end_define

begin_define
define|#
directive|define
name|R300_TX_MIN_FILTER_NEAREST_MIP_LINEAR
value|(9<<  11)
end_define

begin_define
define|#
directive|define
name|R300_TX_MIN_FILTER_LINEAR_MIP_NEAREST
value|(6<<  11)
end_define

begin_define
define|#
directive|define
name|R300_TX_MIN_FILTER_LINEAR_MIP_LINEAR
value|(10<<  11)
end_define

begin_comment
comment|/* NOTE: NEAREST doesn't seem to exist.  * I'm not setting MAG_FILTER_MASK and (3<< 11) on for all  * anisotropy modes because that would void selected mag filter  */
end_comment

begin_define
define|#
directive|define
name|R300_TX_MIN_FILTER_ANISO_NEAREST
value|(0<< 13)
end_define

begin_define
define|#
directive|define
name|R300_TX_MIN_FILTER_ANISO_LINEAR
value|(0<< 13)
end_define

begin_define
define|#
directive|define
name|R300_TX_MIN_FILTER_ANISO_NEAREST_MIP_NEAREST
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|R300_TX_MIN_FILTER_ANISO_NEAREST_MIP_LINEAR
value|(2<< 13)
end_define

begin_define
define|#
directive|define
name|R300_TX_MIN_FILTER_MASK
value|( (15<< 11) | (3<< 13) )
end_define

begin_define
define|#
directive|define
name|R300_TX_MAX_ANISO_1_TO_1
value|(0<< 21)
end_define

begin_define
define|#
directive|define
name|R300_TX_MAX_ANISO_2_TO_1
value|(2<< 21)
end_define

begin_define
define|#
directive|define
name|R300_TX_MAX_ANISO_4_TO_1
value|(4<< 21)
end_define

begin_define
define|#
directive|define
name|R300_TX_MAX_ANISO_8_TO_1
value|(6<< 21)
end_define

begin_define
define|#
directive|define
name|R300_TX_MAX_ANISO_16_TO_1
value|(8<< 21)
end_define

begin_define
define|#
directive|define
name|R300_TX_MAX_ANISO_MASK
value|(14<< 21)
end_define

begin_define
define|#
directive|define
name|R300_TX_FILTER1_0
value|0x4440
end_define

begin_define
define|#
directive|define
name|R300_CHROMA_KEY_MODE_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|R300_CHROMA_KEY_FORCE
value|1
end_define

begin_define
define|#
directive|define
name|R300_CHROMA_KEY_BLEND
value|2
end_define

begin_define
define|#
directive|define
name|R300_MC_ROUND_NORMAL
value|(0<<2)
end_define

begin_define
define|#
directive|define
name|R300_MC_ROUND_MPEG4
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|R300_LOD_BIAS_MASK
value|0x1fff
end_define

begin_define
define|#
directive|define
name|R300_EDGE_ANISO_EDGE_DIAG
value|(0<<13)
end_define

begin_define
define|#
directive|define
name|R300_EDGE_ANISO_EDGE_ONLY
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|R300_MC_COORD_TRUNCATE_DISABLE
value|(0<<14)
end_define

begin_define
define|#
directive|define
name|R300_MC_COORD_TRUNCATE_MPEG
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|R300_TX_TRI_PERF_0_8
value|(0<<15)
end_define

begin_define
define|#
directive|define
name|R300_TX_TRI_PERF_1_8
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|R300_TX_TRI_PERF_1_4
value|(2<<15)
end_define

begin_define
define|#
directive|define
name|R300_TX_TRI_PERF_3_8
value|(3<<15)
end_define

begin_define
define|#
directive|define
name|R300_ANISO_THRESHOLD_MASK
value|(7<<17)
end_define

begin_define
define|#
directive|define
name|R300_TX_SIZE_0
value|0x4480
end_define

begin_define
define|#
directive|define
name|R300_TX_WIDTHMASK_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_TX_WIDTHMASK_MASK
value|(2047<< 0)
end_define

begin_define
define|#
directive|define
name|R300_TX_HEIGHTMASK_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|R300_TX_HEIGHTMASK_MASK
value|(2047<< 11)
end_define

begin_define
define|#
directive|define
name|R300_TX_UNK23
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|R300_TX_MAX_MIP_LEVEL_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|R300_TX_MAX_MIP_LEVEL_MASK
value|(0xf<< 26)
end_define

begin_define
define|#
directive|define
name|R300_TX_SIZE_PROJECTED
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|R300_TX_SIZE_TXPITCH_EN
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_0
value|0x44C0
end_define

begin_comment
comment|/* The interpretation of the format word by Wladimir van der Laan */
end_comment

begin_comment
comment|/* The X, Y, Z and W refer to the layout of the components. 	   They are given meanings as R, G, B and Alpha by the swizzle 	   specification */
end_comment

begin_define
define|#
directive|define
name|R300_TX_FORMAT_X8
value|0x0
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_X16
value|0x1
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_Y4X4
value|0x2
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_Y8X8
value|0x3
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_Y16X16
value|0x4
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_Z3Y3X2
value|0x5
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_Z5Y6X5
value|0x6
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_Z6Y5X5
value|0x7
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_Z11Y11X10
value|0x8
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_Z10Y11X11
value|0x9
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_W4Z4Y4X4
value|0xA
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_W1Z5Y5X5
value|0xB
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_W8Z8Y8X8
value|0xC
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_W2Z10Y10X10
value|0xD
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_W16Z16Y16X16
value|0xE
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_DXT1
value|0xF
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_DXT3
value|0x10
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_DXT5
value|0x11
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_D3DMFT_CxV8U8
value|0x12
end_define

begin_comment
comment|/* no swizzle */
end_comment

begin_define
define|#
directive|define
name|R300_TX_FORMAT_A8R8G8B8
value|0x13
end_define

begin_comment
comment|/* no swizzle */
end_comment

begin_define
define|#
directive|define
name|R300_TX_FORMAT_B8G8_B8G8
value|0x14
end_define

begin_comment
comment|/* no swizzle */
end_comment

begin_define
define|#
directive|define
name|R300_TX_FORMAT_G8R8_G8B8
value|0x15
end_define

begin_comment
comment|/* no swizzle */
end_comment

begin_comment
comment|/* 0x16 - some 16 bit green format.. ?? */
end_comment

begin_define
define|#
directive|define
name|R300_TX_FORMAT_UNK25
value|(1<< 25)
end_define

begin_comment
comment|/* no swizzle */
end_comment

begin_define
define|#
directive|define
name|R300_TX_FORMAT_CUBIC_MAP
value|(1<< 26)
end_define

begin_comment
comment|/* gap */
end_comment

begin_comment
comment|/* Floating point formats */
end_comment

begin_comment
comment|/* Note - hardware supports both 16 and 32 bit floating point */
end_comment

begin_define
define|#
directive|define
name|R300_TX_FORMAT_FL_I16
value|0x18
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_FL_I16A16
value|0x19
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_FL_R16G16B16A16
value|0x1A
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_FL_I32
value|0x1B
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_FL_I32A32
value|0x1C
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_FL_R32G32B32A32
value|0x1D
end_define

begin_comment
comment|/* alpha modes, convenience mostly */
end_comment

begin_comment
comment|/* if you have alpha, pick constant appropriate to the 	   number of channels (1 for I8, 2 for I8A8, 4 for R8G8B8A8, etc */
end_comment

begin_define
define|#
directive|define
name|R300_TX_FORMAT_ALPHA_1CH
value|0x000
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_ALPHA_2CH
value|0x200
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_ALPHA_4CH
value|0x600
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_ALPHA_NONE
value|0xA00
end_define

begin_comment
comment|/* Swizzling */
end_comment

begin_comment
comment|/* constants */
end_comment

begin_define
define|#
directive|define
name|R300_TX_FORMAT_X
value|0
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_Y
value|1
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_Z
value|2
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_W
value|3
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_ZERO
value|4
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_ONE
value|5
end_define

begin_comment
comment|/* 2.0*Z, everything above 1.0 is set to 0.0 */
end_comment

begin_define
define|#
directive|define
name|R300_TX_FORMAT_CUT_Z
value|6
end_define

begin_comment
comment|/* 2.0*W, everything above 1.0 is set to 0.0 */
end_comment

begin_define
define|#
directive|define
name|R300_TX_FORMAT_CUT_W
value|7
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_B_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_G_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_R_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_A_SHIFT
value|9
end_define

begin_comment
comment|/* Convenience macro to take care of layout and swizzling */
end_comment

begin_define
define|#
directive|define
name|R300_EASY_TX_FORMAT
parameter_list|(
name|B
parameter_list|,
name|G
parameter_list|,
name|R
parameter_list|,
name|A
parameter_list|,
name|FMT
parameter_list|)
value|(		\ 		((R300_TX_FORMAT_##B)<<R300_TX_FORMAT_B_SHIFT)		\ 		| ((R300_TX_FORMAT_##G)<<R300_TX_FORMAT_G_SHIFT)	\ 		| ((R300_TX_FORMAT_##R)<<R300_TX_FORMAT_R_SHIFT)	\ 		| ((R300_TX_FORMAT_##A)<<R300_TX_FORMAT_A_SHIFT)	\ 		| (R300_TX_FORMAT_##FMT)				\ 		)
end_define

begin_comment
comment|/* These can be ORed with result of R300_EASY_TX_FORMAT() 	   We don't really know what they do. Take values from a            constant color ? */
end_comment

begin_define
define|#
directive|define
name|R300_TX_FORMAT_CONST_X
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_CONST_Y
value|(2<<5)
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_CONST_Z
value|(4<<5)
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_CONST_W
value|(8<<5)
end_define

begin_define
define|#
directive|define
name|R300_TX_FORMAT_YUV_MODE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|R300_TX_PITCH_0
value|0x4500
end_define

begin_comment
comment|/* obvious missing in gap */
end_comment

begin_define
define|#
directive|define
name|R300_TX_OFFSET_0
value|0x4540
end_define

begin_comment
comment|/* BEGIN: Guess from R200 */
end_comment

begin_define
define|#
directive|define
name|R300_TXO_ENDIAN_NO_SWAP
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|R300_TXO_ENDIAN_BYTE_SWAP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_TXO_ENDIAN_WORD_SWAP
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|R300_TXO_ENDIAN_HALFDW_SWAP
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|R300_TXO_MACRO_TILE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|R300_TXO_MICRO_TILE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|R300_TXO_OFFSET_MASK
value|0xffffffe0
end_define

begin_define
define|#
directive|define
name|R300_TXO_OFFSET_SHIFT
value|5
end_define

begin_comment
comment|/* END: Guess from R200 */
end_comment

begin_comment
comment|/* 32 bit chroma key */
end_comment

begin_define
define|#
directive|define
name|R300_TX_CHROMA_KEY_0
value|0x4580
end_define

begin_comment
comment|/* ff00ff00 == { 0, 1.0, 0, 1.0 } */
end_comment

begin_define
define|#
directive|define
name|R300_TX_BORDER_COLOR_0
value|0x45C0
end_define

begin_comment
comment|/* END: Texture specification */
end_comment

begin_comment
comment|/* BEGIN: Fragment program instruction set */
end_comment

begin_comment
comment|/* Fragment programs are written directly into register space.  * There are separate instruction streams for texture instructions and ALU  * instructions.  * In order to synchronize these streams, the program is divided into up  * to 4 nodes. Each node begins with a number of TEX operations, followed  * by a number of ALU operations.  * The first node can have zero TEX ops, all subsequent nodes must have at  * least  * one TEX ops.  * All nodes must have at least one ALU op.  *  * The index of the last node is stored in PFS_CNTL_0: A value of 0 means  * 1 node, a value of 3 means 4 nodes.  * The total amount of instructions is defined in PFS_CNTL_2. The offsets are  * offsets into the respective instruction streams, while *_END points to the  * last instruction relative to this offset.  */
end_comment

begin_define
define|#
directive|define
name|R300_PFS_CNTL_0
value|0x4600
end_define

begin_define
define|#
directive|define
name|R300_PFS_CNTL_LAST_NODES_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_PFS_CNTL_LAST_NODES_MASK
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PFS_CNTL_FIRST_NODE_HAS_TEX
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|R300_PFS_CNTL_1
value|0x4604
end_define

begin_comment
comment|/* There is an unshifted value here which has so far always been equal to the  * index of the highest used temporary register.  */
end_comment

begin_define
define|#
directive|define
name|R300_PFS_CNTL_2
value|0x4608
end_define

begin_define
define|#
directive|define
name|R300_PFS_CNTL_ALU_OFFSET_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_PFS_CNTL_ALU_OFFSET_MASK
value|(63<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PFS_CNTL_ALU_END_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|R300_PFS_CNTL_ALU_END_MASK
value|(63<< 6)
end_define

begin_define
define|#
directive|define
name|R300_PFS_CNTL_TEX_OFFSET_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|R300_PFS_CNTL_TEX_OFFSET_MASK
value|(31<< 12)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_PFS_CNTL_TEX_END_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|R300_PFS_CNTL_TEX_END_MASK
value|(31<< 18)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_comment
comment|/* gap */
end_comment

begin_comment
comment|/* Nodes are stored backwards. The last active node is always stored in  * PFS_NODE_3.  * Example: In a 2-node program, NODE_0 and NODE_1 are set to 0. The  * first node is stored in NODE_2, the second node is stored in NODE_3.  *  * Offsets are relative to the master offset from PFS_CNTL_2.  */
end_comment

begin_define
define|#
directive|define
name|R300_PFS_NODE_0
value|0x4610
end_define

begin_define
define|#
directive|define
name|R300_PFS_NODE_1
value|0x4614
end_define

begin_define
define|#
directive|define
name|R300_PFS_NODE_2
value|0x4618
end_define

begin_define
define|#
directive|define
name|R300_PFS_NODE_3
value|0x461C
end_define

begin_define
define|#
directive|define
name|R300_PFS_NODE_ALU_OFFSET_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_PFS_NODE_ALU_OFFSET_MASK
value|(63<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PFS_NODE_ALU_END_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|R300_PFS_NODE_ALU_END_MASK
value|(63<< 6)
end_define

begin_define
define|#
directive|define
name|R300_PFS_NODE_TEX_OFFSET_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|R300_PFS_NODE_TEX_OFFSET_MASK
value|(31<< 12)
end_define

begin_define
define|#
directive|define
name|R300_PFS_NODE_TEX_END_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|R300_PFS_NODE_TEX_END_MASK
value|(31<< 17)
end_define

begin_define
define|#
directive|define
name|R300_PFS_NODE_OUTPUT_COLOR
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|R300_PFS_NODE_OUTPUT_DEPTH
value|(1<< 23)
end_define

begin_comment
comment|/* TEX  * As far as I can tell, texture instructions cannot write into output  * registers directly. A subsequent ALU instruction is always necessary,  * even if it's just MAD o0, r0, 1, 0  */
end_comment

begin_define
define|#
directive|define
name|R300_PFS_TEXI_0
value|0x4620
end_define

begin_define
define|#
directive|define
name|R300_FPITX_SRC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_FPITX_SRC_MASK
value|(31<< 0)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_FPITX_SRC_CONST
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|R300_FPITX_DST_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|R300_FPITX_DST_MASK
value|(31<< 6)
end_define

begin_define
define|#
directive|define
name|R300_FPITX_IMAGE_SHIFT
value|11
end_define

begin_comment
comment|/* GUESS based on layout and native limits */
end_comment

begin_define
define|#
directive|define
name|R300_FPITX_IMAGE_MASK
value|(15<< 11)
end_define

begin_comment
comment|/* Unsure if these are opcodes, or some kind of bitfield, but this is how  * they were set when I checked  */
end_comment

begin_define
define|#
directive|define
name|R300_FPITX_OPCODE_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|R300_FPITX_OP_TEX
value|1
end_define

begin_define
define|#
directive|define
name|R300_FPITX_OP_KIL
value|2
end_define

begin_define
define|#
directive|define
name|R300_FPITX_OP_TXP
value|3
end_define

begin_define
define|#
directive|define
name|R300_FPITX_OP_TXB
value|4
end_define

begin_define
define|#
directive|define
name|R300_FPITX_OPCODE_MASK
value|(7<< 15)
end_define

begin_comment
comment|/* ALU  * The ALU instructions register blocks are enumerated according to the order  * in which fglrx. I assume there is space for 64 instructions, since  * each block has space for a maximum of 64 DWORDs, and this matches reported  * native limits.  *  * The basic functional block seems to be one MAD for each color and alpha,  * and an adder that adds all components after the MUL.  *  - ADD, MUL, MAD etc.: use MAD with appropriate neutral operands  *  - DP4: Use OUTC_DP4, OUTA_DP4  *  - DP3: Use OUTC_DP3, OUTA_DP4, appropriate alpha operands  *  - DPH: Use OUTC_DP4, OUTA_DP4, appropriate alpha operands  *  - CMPH: If ARG2> 0.5, return ARG0, else return ARG1  *  - CMP: If ARG2< 0, return ARG1, else return ARG0  *  - FLR: use FRC+MAD  *  - XPD: use MAD+MAD  *  - SGE, SLT: use MAD+CMP  *  - RSQ: use ABS modifier for argument  *  - Use OUTC_REPL_ALPHA to write results of an alpha-only operation  *    (e.g. RCP) into color register  *  - apparently, there's no quick DST operation  *  - fglrx set FPI2_UNKNOWN_31 on a "MAD fragment.color, tmp0, tmp1, tmp2"  *  - fglrx set FPI2_UNKNOWN_31 on a "MAX r2, r1, c0"  *  - fglrx once set FPI0_UNKNOWN_31 on a "FRC r1, r1"  *  * Operand selection  * First stage selects three sources from the available registers and  * constant parameters. This is defined in INSTR1 (color) and INSTR3 (alpha).  * fglrx sorts the three source fields: Registers before constants,  * lower indices before higher indices; I do not know whether this is  * necessary.  *  * fglrx fills unused sources with "read constant 0"  * According to specs, you cannot select more than two different constants.  *  * Second stage selects the operands from the sources. This is defined in  * INSTR0 (color) and INSTR2 (alpha). You can also select the special constants  * zero and one.  * Swizzling and negation happens in this stage, as well.  *  * Important: Color and alpha seem to be mostly separate, i.e. their sources  * selection appears to be fully independent (the register storage is probably  * physically split into a color and an alpha section).  * However (because of the apparent physical split), there is some interaction  * WRT swizzling. If, for example, you want to load an R component into an  * Alpha operand, this R component is taken from a *color* source, not from  * an alpha source. The corresponding register doesn't even have to appear in  * the alpha sources list. (I hope this all makes sense to you)  *  * Destination selection  * The destination register index is in FPI1 (color) and FPI3 (alpha)  * together with enable bits.  * There are separate enable bits for writing into temporary registers  * (DSTC_REG_* /DSTA_REG) and and program output registers (DSTC_OUTPUT_*  * /DSTA_OUTPUT). You can write to both at once, or not write at all (the  * same index must be used for both).  *  * Note: There is a special form for LRP  *  - Argument order is the same as in ARB_fragment_program.  *  - Operation is MAD  *  - ARG1 is set to ARGC_SRC1C_LRP/ARGC_SRC1A_LRP  *  - Set FPI0/FPI2_SPECIAL_LRP  * Arbitrary LRP (including support for swizzling) requires vanilla MAD+MAD  */
end_comment

begin_define
define|#
directive|define
name|R300_PFS_INSTR1_0
value|0x46C0
end_define

begin_define
define|#
directive|define
name|R300_FPI1_SRC0C_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_FPI1_SRC0C_MASK
value|(31<< 0)
end_define

begin_define
define|#
directive|define
name|R300_FPI1_SRC0C_CONST
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|R300_FPI1_SRC1C_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|R300_FPI1_SRC1C_MASK
value|(31<< 6)
end_define

begin_define
define|#
directive|define
name|R300_FPI1_SRC1C_CONST
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|R300_FPI1_SRC2C_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|R300_FPI1_SRC2C_MASK
value|(31<< 12)
end_define

begin_define
define|#
directive|define
name|R300_FPI1_SRC2C_CONST
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|R300_FPI1_SRC_MASK
value|0x0003ffff
end_define

begin_define
define|#
directive|define
name|R300_FPI1_DSTC_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|R300_FPI1_DSTC_MASK
value|(31<< 18)
end_define

begin_define
define|#
directive|define
name|R300_FPI1_DSTC_REG_MASK_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|R300_FPI1_DSTC_REG_X
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|R300_FPI1_DSTC_REG_Y
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|R300_FPI1_DSTC_REG_Z
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|R300_FPI1_DSTC_OUTPUT_MASK_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|R300_FPI1_DSTC_OUTPUT_X
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|R300_FPI1_DSTC_OUTPUT_Y
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|R300_FPI1_DSTC_OUTPUT_Z
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|R300_PFS_INSTR3_0
value|0x47C0
end_define

begin_define
define|#
directive|define
name|R300_FPI3_SRC0A_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_FPI3_SRC0A_MASK
value|(31<< 0)
end_define

begin_define
define|#
directive|define
name|R300_FPI3_SRC0A_CONST
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|R300_FPI3_SRC1A_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|R300_FPI3_SRC1A_MASK
value|(31<< 6)
end_define

begin_define
define|#
directive|define
name|R300_FPI3_SRC1A_CONST
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|R300_FPI3_SRC2A_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|R300_FPI3_SRC2A_MASK
value|(31<< 12)
end_define

begin_define
define|#
directive|define
name|R300_FPI3_SRC2A_CONST
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|R300_FPI3_SRC_MASK
value|0x0003ffff
end_define

begin_define
define|#
directive|define
name|R300_FPI3_DSTA_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|R300_FPI3_DSTA_MASK
value|(31<< 18)
end_define

begin_define
define|#
directive|define
name|R300_FPI3_DSTA_REG
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|R300_FPI3_DSTA_OUTPUT
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|R300_FPI3_DSTA_DEPTH
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|R300_PFS_INSTR0_0
value|0x48C0
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC0C_XYZ
value|0
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC0C_XXX
value|1
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC0C_YYY
value|2
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC0C_ZZZ
value|3
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC1C_XYZ
value|4
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC1C_XXX
value|5
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC1C_YYY
value|6
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC1C_ZZZ
value|7
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC2C_XYZ
value|8
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC2C_XXX
value|9
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC2C_YYY
value|10
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC2C_ZZZ
value|11
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC0A
value|12
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC1A
value|13
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC2A
value|14
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC1C_LRP
value|15
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_ZERO
value|20
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_ONE
value|21
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_HALF
value|22
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC0C_YZX
value|23
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC1C_YZX
value|24
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC2C_YZX
value|25
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC0C_ZXY
value|26
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC1C_ZXY
value|27
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC2C_ZXY
value|28
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC0CA_WZY
value|29
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC1CA_WZY
value|30
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARGC_SRC2CA_WZY
value|31
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARG0C_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARG0C_MASK
value|(31<< 0)
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARG0C_NEG
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARG0C_ABS
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARG1C_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARG1C_MASK
value|(31<< 7)
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARG1C_NEG
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARG1C_ABS
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARG2C_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARG2C_MASK
value|(31<< 14)
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARG2C_NEG
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|R300_FPI0_ARG2C_ABS
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|R300_FPI0_SPECIAL_LRP
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|R300_FPI0_OUTC_MAD
value|(0<< 23)
end_define

begin_define
define|#
directive|define
name|R300_FPI0_OUTC_DP3
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|R300_FPI0_OUTC_DP4
value|(2<< 23)
end_define

begin_define
define|#
directive|define
name|R300_FPI0_OUTC_MIN
value|(4<< 23)
end_define

begin_define
define|#
directive|define
name|R300_FPI0_OUTC_MAX
value|(5<< 23)
end_define

begin_define
define|#
directive|define
name|R300_FPI0_OUTC_CMPH
value|(7<< 23)
end_define

begin_define
define|#
directive|define
name|R300_FPI0_OUTC_CMP
value|(8<< 23)
end_define

begin_define
define|#
directive|define
name|R300_FPI0_OUTC_FRC
value|(9<< 23)
end_define

begin_define
define|#
directive|define
name|R300_FPI0_OUTC_REPL_ALPHA
value|(10<< 23)
end_define

begin_define
define|#
directive|define
name|R300_FPI0_OUTC_SAT
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|R300_FPI0_INSERT_NOP
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|R300_PFS_INSTR2_0
value|0x49C0
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARGA_SRC0C_X
value|0
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARGA_SRC0C_Y
value|1
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARGA_SRC0C_Z
value|2
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARGA_SRC1C_X
value|3
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARGA_SRC1C_Y
value|4
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARGA_SRC1C_Z
value|5
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARGA_SRC2C_X
value|6
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARGA_SRC2C_Y
value|7
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARGA_SRC2C_Z
value|8
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARGA_SRC0A
value|9
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARGA_SRC1A
value|10
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARGA_SRC2A
value|11
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARGA_SRC1A_LRP
value|15
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARGA_ZERO
value|16
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARGA_ONE
value|17
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_FPI2_ARGA_HALF
value|18
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARG0A_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARG0A_MASK
value|(31<< 0)
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARG0A_NEG
value|(1<< 5)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_FPI2_ARG0A_ABS
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARG1A_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARG1A_MASK
value|(31<< 7)
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARG1A_NEG
value|(1<< 12)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_FPI2_ARG1A_ABS
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARG2A_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARG2A_MASK
value|(31<< 14)
end_define

begin_define
define|#
directive|define
name|R300_FPI2_ARG2A_NEG
value|(1<< 19)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_FPI2_ARG2A_ABS
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|R300_FPI2_SPECIAL_LRP
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|R300_FPI2_OUTA_MAD
value|(0<< 23)
end_define

begin_define
define|#
directive|define
name|R300_FPI2_OUTA_DP4
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|R300_FPI2_OUTA_MIN
value|(2<< 23)
end_define

begin_define
define|#
directive|define
name|R300_FPI2_OUTA_MAX
value|(3<< 23)
end_define

begin_define
define|#
directive|define
name|R300_FPI2_OUTA_CMP
value|(6<< 23)
end_define

begin_define
define|#
directive|define
name|R300_FPI2_OUTA_FRC
value|(7<< 23)
end_define

begin_define
define|#
directive|define
name|R300_FPI2_OUTA_EX2
value|(8<< 23)
end_define

begin_define
define|#
directive|define
name|R300_FPI2_OUTA_LG2
value|(9<< 23)
end_define

begin_define
define|#
directive|define
name|R300_FPI2_OUTA_RCP
value|(10<< 23)
end_define

begin_define
define|#
directive|define
name|R300_FPI2_OUTA_RSQ
value|(11<< 23)
end_define

begin_define
define|#
directive|define
name|R300_FPI2_OUTA_SAT
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|R300_FPI2_UNKNOWN_31
value|(1U<< 31)
end_define

begin_comment
comment|/* END: Fragment program instruction set */
end_comment

begin_comment
comment|/* Fog state and color */
end_comment

begin_define
define|#
directive|define
name|R300_RE_FOG_STATE
value|0x4BC0
end_define

begin_define
define|#
directive|define
name|R300_FOG_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_FOG_MODE_LINEAR
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|R300_FOG_MODE_EXP
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|R300_FOG_MODE_EXP2
value|(2<< 1)
end_define

begin_define
define|#
directive|define
name|R300_FOG_MODE_MASK
value|(3<< 1)
end_define

begin_define
define|#
directive|define
name|R300_FOG_COLOR_R
value|0x4BC8
end_define

begin_define
define|#
directive|define
name|R300_FOG_COLOR_G
value|0x4BCC
end_define

begin_define
define|#
directive|define
name|R300_FOG_COLOR_B
value|0x4BD0
end_define

begin_define
define|#
directive|define
name|R300_PP_ALPHA_TEST
value|0x4BD4
end_define

begin_define
define|#
directive|define
name|R300_REF_ALPHA_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R300_ALPHA_TEST_FAIL
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|R300_ALPHA_TEST_LESS
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|R300_ALPHA_TEST_LEQUAL
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|R300_ALPHA_TEST_EQUAL
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|R300_ALPHA_TEST_GEQUAL
value|(6<< 8)
end_define

begin_define
define|#
directive|define
name|R300_ALPHA_TEST_GREATER
value|(4<< 8)
end_define

begin_define
define|#
directive|define
name|R300_ALPHA_TEST_NEQUAL
value|(5<< 8)
end_define

begin_define
define|#
directive|define
name|R300_ALPHA_TEST_PASS
value|(7<< 8)
end_define

begin_define
define|#
directive|define
name|R300_ALPHA_TEST_OP_MASK
value|(7<< 8)
end_define

begin_define
define|#
directive|define
name|R300_ALPHA_TEST_ENABLE
value|(1<< 11)
end_define

begin_comment
comment|/* gap */
end_comment

begin_comment
comment|/* Fragment program parameters in 7.16 floating point */
end_comment

begin_define
define|#
directive|define
name|R300_PFS_PARAM_0_X
value|0x4C00
end_define

begin_define
define|#
directive|define
name|R300_PFS_PARAM_0_Y
value|0x4C04
end_define

begin_define
define|#
directive|define
name|R300_PFS_PARAM_0_Z
value|0x4C08
end_define

begin_define
define|#
directive|define
name|R300_PFS_PARAM_0_W
value|0x4C0C
end_define

begin_comment
comment|/* GUESS: PARAM_31 is last, based on native limits reported by fglrx */
end_comment

begin_define
define|#
directive|define
name|R300_PFS_PARAM_31_X
value|0x4DF0
end_define

begin_define
define|#
directive|define
name|R300_PFS_PARAM_31_Y
value|0x4DF4
end_define

begin_define
define|#
directive|define
name|R300_PFS_PARAM_31_Z
value|0x4DF8
end_define

begin_define
define|#
directive|define
name|R300_PFS_PARAM_31_W
value|0x4DFC
end_define

begin_comment
comment|/* Notes:  * - AFAIK fglrx always sets BLEND_UNKNOWN when blending is used in  *   the application  * - AFAIK fglrx always sets BLEND_NO_SEPARATE when CBLEND and ABLEND  *    are set to the same  *   function (both registers are always set up completely in any case)  * - Most blend flags are simply copied from R200 and not tested yet  */
end_comment

begin_define
define|#
directive|define
name|R300_RB3D_CBLEND
value|0x4E04
end_define

begin_define
define|#
directive|define
name|R300_RB3D_ABLEND
value|0x4E08
end_define

begin_comment
comment|/* the following only appear in CBLEND */
end_comment

begin_define
define|#
directive|define
name|R300_BLEND_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_BLEND_UNKNOWN
value|(3<< 1)
end_define

begin_define
define|#
directive|define
name|R300_BLEND_NO_SEPARATE
value|(1<< 3)
end_define

begin_comment
comment|/* the following are shared between CBLEND and ABLEND */
end_comment

begin_define
define|#
directive|define
name|R300_FCN_MASK
value|(3<< 12)
end_define

begin_define
define|#
directive|define
name|R300_COMB_FCN_ADD_CLAMP
value|(0<< 12)
end_define

begin_define
define|#
directive|define
name|R300_COMB_FCN_ADD_NOCLAMP
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|R300_COMB_FCN_SUB_CLAMP
value|(2<< 12)
end_define

begin_define
define|#
directive|define
name|R300_COMB_FCN_SUB_NOCLAMP
value|(3<< 12)
end_define

begin_define
define|#
directive|define
name|R300_COMB_FCN_MIN
value|(4<< 12)
end_define

begin_define
define|#
directive|define
name|R300_COMB_FCN_MAX
value|(5<< 12)
end_define

begin_define
define|#
directive|define
name|R300_COMB_FCN_RSUB_CLAMP
value|(6<< 12)
end_define

begin_define
define|#
directive|define
name|R300_COMB_FCN_RSUB_NOCLAMP
value|(7<< 12)
end_define

begin_define
define|#
directive|define
name|R300_BLEND_GL_ZERO
value|(32)
end_define

begin_define
define|#
directive|define
name|R300_BLEND_GL_ONE
value|(33)
end_define

begin_define
define|#
directive|define
name|R300_BLEND_GL_SRC_COLOR
value|(34)
end_define

begin_define
define|#
directive|define
name|R300_BLEND_GL_ONE_MINUS_SRC_COLOR
value|(35)
end_define

begin_define
define|#
directive|define
name|R300_BLEND_GL_DST_COLOR
value|(36)
end_define

begin_define
define|#
directive|define
name|R300_BLEND_GL_ONE_MINUS_DST_COLOR
value|(37)
end_define

begin_define
define|#
directive|define
name|R300_BLEND_GL_SRC_ALPHA
value|(38)
end_define

begin_define
define|#
directive|define
name|R300_BLEND_GL_ONE_MINUS_SRC_ALPHA
value|(39)
end_define

begin_define
define|#
directive|define
name|R300_BLEND_GL_DST_ALPHA
value|(40)
end_define

begin_define
define|#
directive|define
name|R300_BLEND_GL_ONE_MINUS_DST_ALPHA
value|(41)
end_define

begin_define
define|#
directive|define
name|R300_BLEND_GL_SRC_ALPHA_SATURATE
value|(42)
end_define

begin_define
define|#
directive|define
name|R300_BLEND_GL_CONST_COLOR
value|(43)
end_define

begin_define
define|#
directive|define
name|R300_BLEND_GL_ONE_MINUS_CONST_COLOR
value|(44)
end_define

begin_define
define|#
directive|define
name|R300_BLEND_GL_CONST_ALPHA
value|(45)
end_define

begin_define
define|#
directive|define
name|R300_BLEND_GL_ONE_MINUS_CONST_ALPHA
value|(46)
end_define

begin_define
define|#
directive|define
name|R300_BLEND_MASK
value|(63)
end_define

begin_define
define|#
directive|define
name|R300_SRC_BLEND_SHIFT
value|(16)
end_define

begin_define
define|#
directive|define
name|R300_DST_BLEND_SHIFT
value|(24)
end_define

begin_define
define|#
directive|define
name|R300_RB3D_BLEND_COLOR
value|0x4E10
end_define

begin_define
define|#
directive|define
name|R300_RB3D_COLORMASK
value|0x4E0C
end_define

begin_define
define|#
directive|define
name|R300_COLORMASK0_B
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|R300_COLORMASK0_G
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|R300_COLORMASK0_R
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|R300_COLORMASK0_A
value|(1<<3)
end_define

begin_comment
comment|/* gap */
end_comment

begin_define
define|#
directive|define
name|R300_RB3D_COLOROFFSET0
value|0x4E28
end_define

begin_define
define|#
directive|define
name|R300_COLOROFFSET_MASK
value|0xFFFFFFF0
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_RB3D_COLOROFFSET1
value|0x4E2C
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_RB3D_COLOROFFSET2
value|0x4E30
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_RB3D_COLOROFFSET3
value|0x4E34
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_comment
comment|/* gap */
end_comment

begin_comment
comment|/* Bit 16: Larger tiles  * Bit 17: 4x2 tiles  * Bit 18: Extremely weird tile like, but some pixels duplicated?  */
end_comment

begin_define
define|#
directive|define
name|R300_RB3D_COLORPITCH0
value|0x4E38
end_define

begin_define
define|#
directive|define
name|R300_COLORPITCH_MASK
value|0x00001FF8
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_COLOR_TILE_ENABLE
value|(1<< 16)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_COLOR_MICROTILE_ENABLE
value|(1<< 17)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_COLOR_ENDIAN_NO_SWAP
value|(0<< 18)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_COLOR_ENDIAN_WORD_SWAP
value|(1<< 18)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_COLOR_ENDIAN_DWORD_SWAP
value|(2<< 18)
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_COLOR_FORMAT_RGB565
value|(2<< 22)
end_define

begin_define
define|#
directive|define
name|R300_COLOR_FORMAT_ARGB8888
value|(3<< 22)
end_define

begin_define
define|#
directive|define
name|R300_RB3D_COLORPITCH1
value|0x4E3C
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_RB3D_COLORPITCH2
value|0x4E40
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_RB3D_COLORPITCH3
value|0x4E44
end_define

begin_comment
comment|/* GUESS */
end_comment

begin_define
define|#
directive|define
name|R300_RB3D_AARESOLVE_CTL
value|0x4E88
end_define

begin_comment
comment|/* gap */
end_comment

begin_comment
comment|/* Guess by Vladimir.  * Set to 0A before 3D operations, set to 02 afterwards.  */
end_comment

begin_comment
comment|/*#define R300_RB3D_DSTCACHE_CTLSTAT          0x4E4C*/
end_comment

begin_define
define|#
directive|define
name|R300_RB3D_DSTCACHE_UNKNOWN_02
value|0x00000002
end_define

begin_define
define|#
directive|define
name|R300_RB3D_DSTCACHE_UNKNOWN_0A
value|0x0000000A
end_define

begin_comment
comment|/* gap */
end_comment

begin_comment
comment|/* There seems to be no "write only" setting, so use Z-test = ALWAYS  * for this.  * Bit (1<<8) is the "test" bit. so plain write is 6  - vd  */
end_comment

begin_define
define|#
directive|define
name|R300_ZB_CNTL
value|0x4F00
end_define

begin_define
define|#
directive|define
name|R300_STENCIL_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_Z_ENABLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|R300_Z_WRITE_ENABLE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|R300_Z_SIGNED_COMPARE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|R300_STENCIL_FRONT_BACK
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|R300_ZB_ZSTENCILCNTL
value|0x4f04
end_define

begin_comment
comment|/* functions */
end_comment

begin_define
define|#
directive|define
name|R300_ZS_NEVER
value|0
end_define

begin_define
define|#
directive|define
name|R300_ZS_LESS
value|1
end_define

begin_define
define|#
directive|define
name|R300_ZS_LEQUAL
value|2
end_define

begin_define
define|#
directive|define
name|R300_ZS_EQUAL
value|3
end_define

begin_define
define|#
directive|define
name|R300_ZS_GEQUAL
value|4
end_define

begin_define
define|#
directive|define
name|R300_ZS_GREATER
value|5
end_define

begin_define
define|#
directive|define
name|R300_ZS_NOTEQUAL
value|6
end_define

begin_define
define|#
directive|define
name|R300_ZS_ALWAYS
value|7
end_define

begin_define
define|#
directive|define
name|R300_ZS_MASK
value|7
end_define

begin_comment
comment|/* operations */
end_comment

begin_define
define|#
directive|define
name|R300_ZS_KEEP
value|0
end_define

begin_define
define|#
directive|define
name|R300_ZS_ZERO
value|1
end_define

begin_define
define|#
directive|define
name|R300_ZS_REPLACE
value|2
end_define

begin_define
define|#
directive|define
name|R300_ZS_INCR
value|3
end_define

begin_define
define|#
directive|define
name|R300_ZS_DECR
value|4
end_define

begin_define
define|#
directive|define
name|R300_ZS_INVERT
value|5
end_define

begin_define
define|#
directive|define
name|R300_ZS_INCR_WRAP
value|6
end_define

begin_define
define|#
directive|define
name|R300_ZS_DECR_WRAP
value|7
end_define

begin_define
define|#
directive|define
name|R300_Z_FUNC_SHIFT
value|0
end_define

begin_comment
comment|/* front and back refer to operations done for front 	   and back faces, i.e. separate stencil function support */
end_comment

begin_define
define|#
directive|define
name|R300_S_FRONT_FUNC_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|R300_S_FRONT_SFAIL_OP_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|R300_S_FRONT_ZPASS_OP_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|R300_S_FRONT_ZFAIL_OP_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|R300_S_BACK_FUNC_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|R300_S_BACK_SFAIL_OP_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|R300_S_BACK_ZPASS_OP_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|R300_S_BACK_ZFAIL_OP_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|R300_ZB_STENCILREFMASK
value|0x4f08
end_define

begin_define
define|#
directive|define
name|R300_STENCILREF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R300_STENCILREF_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R300_STENCILMASK_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|R300_STENCILMASK_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|R300_STENCILWRITEMASK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|R300_STENCILWRITEMASK_MASK
value|0x00ff0000
end_define

begin_comment
comment|/* gap */
end_comment

begin_define
define|#
directive|define
name|R300_ZB_FORMAT
value|0x4f10
end_define

begin_define
define|#
directive|define
name|R300_DEPTHFORMAT_16BIT_INT_Z
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|R300_DEPTHFORMAT_16BIT_13E3
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_DEPTHFORMAT_24BIT_INT_Z_8BIT_STENCIL
value|(2<< 0)
end_define

begin_comment
comment|/* reserved up to (15<< 0) */
end_comment

begin_define
define|#
directive|define
name|R300_INVERT_13E3_LEADING_ONES
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|R300_INVERT_13E3_LEADING_ZEROS
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|R300_ZB_ZTOP
value|0x4F14
end_define

begin_define
define|#
directive|define
name|R300_ZTOP_DISABLE
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|R300_ZTOP_ENABLE
value|(1<< 0)
end_define

begin_comment
comment|/* gap */
end_comment

begin_define
define|#
directive|define
name|R300_ZB_ZCACHE_CTLSTAT
value|0x4f18
end_define

begin_define
define|#
directive|define
name|R300_ZB_ZCACHE_CTLSTAT_ZC_FLUSH_NO_EFFECT
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|R300_ZB_ZCACHE_CTLSTAT_ZC_FLUSH_FLUSH_AND_FREE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_ZB_ZCACHE_CTLSTAT_ZC_FREE_NO_EFFECT
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|R300_ZB_ZCACHE_CTLSTAT_ZC_FREE_FREE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|R300_ZB_ZCACHE_CTLSTAT_ZC_BUSY_IDLE
value|(0<< 31)
end_define

begin_define
define|#
directive|define
name|R300_ZB_ZCACHE_CTLSTAT_ZC_BUSY_BUSY
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|R300_ZB_BW_CNTL
value|0x4f1c
end_define

begin_define
define|#
directive|define
name|R300_HIZ_DISABLE
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|R300_HIZ_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_HIZ_MIN
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|R300_HIZ_MAX
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|R300_FAST_FILL_DISABLE
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|R300_FAST_FILL_ENABLE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|R300_RD_COMP_DISABLE
value|(0<< 3)
end_define

begin_define
define|#
directive|define
name|R300_RD_COMP_ENABLE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|R300_WR_COMP_DISABLE
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|R300_WR_COMP_ENABLE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|R300_ZB_CB_CLEAR_RMW
value|(0<< 5)
end_define

begin_define
define|#
directive|define
name|R300_ZB_CB_CLEAR_CACHE_LINEAR
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|R300_FORCE_COMPRESSED_STENCIL_VALUE_DISABLE
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|R300_FORCE_COMPRESSED_STENCIL_VALUE_ENABLE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|R500_ZEQUAL_OPTIMIZE_ENABLE
value|(0<< 7)
end_define

begin_define
define|#
directive|define
name|R500_ZEQUAL_OPTIMIZE_DISABLE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|R500_SEQUAL_OPTIMIZE_ENABLE
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|R500_SEQUAL_OPTIMIZE_DISABLE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|R500_BMASK_ENABLE
value|(0<< 10)
end_define

begin_define
define|#
directive|define
name|R500_BMASK_DISABLE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|R500_HIZ_EQUAL_REJECT_DISABLE
value|(0<< 11)
end_define

begin_define
define|#
directive|define
name|R500_HIZ_EQUAL_REJECT_ENABLE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|R500_HIZ_FP_EXP_BITS_DISABLE
value|(0<< 12)
end_define

begin_define
define|#
directive|define
name|R500_HIZ_FP_EXP_BITS_1
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|R500_HIZ_FP_EXP_BITS_2
value|(2<< 12)
end_define

begin_define
define|#
directive|define
name|R500_HIZ_FP_EXP_BITS_3
value|(3<< 12)
end_define

begin_define
define|#
directive|define
name|R500_HIZ_FP_EXP_BITS_4
value|(4<< 12)
end_define

begin_define
define|#
directive|define
name|R500_HIZ_FP_EXP_BITS_5
value|(5<< 12)
end_define

begin_define
define|#
directive|define
name|R500_HIZ_FP_INVERT_LEADING_ONES
value|(0<< 15)
end_define

begin_define
define|#
directive|define
name|R500_HIZ_FP_INVERT_LEADING_ZEROS
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|R500_TILE_OVERWRITE_RECOMPRESSION_ENABLE
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|R500_TILE_OVERWRITE_RECOMPRESSION_DISABLE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|R500_CONTIGUOUS_6XAA_SAMPLES_ENABLE
value|(0<< 17)
end_define

begin_define
define|#
directive|define
name|R500_CONTIGUOUS_6XAA_SAMPLES_DISABLE
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|R500_PEQ_PACKING_DISABLE
value|(0<< 18)
end_define

begin_define
define|#
directive|define
name|R500_PEQ_PACKING_ENABLE
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|R500_COVERED_PTR_MASKING_DISABLE
value|(0<< 18)
end_define

begin_define
define|#
directive|define
name|R500_COVERED_PTR_MASKING_ENABLE
value|(1<< 18)
end_define

begin_comment
comment|/* gap */
end_comment

begin_comment
comment|/* Z Buffer Address Offset.  * Bits 31 to 5 are used for aligned Z buffer address offset for macro tiles.  */
end_comment

begin_define
define|#
directive|define
name|R300_ZB_DEPTHOFFSET
value|0x4f20
end_define

begin_comment
comment|/* Z Buffer Pitch and Endian Control */
end_comment

begin_define
define|#
directive|define
name|R300_ZB_DEPTHPITCH
value|0x4f24
end_define

begin_define
define|#
directive|define
name|R300_DEPTHPITCH_MASK
value|0x00003FFC
end_define

begin_define
define|#
directive|define
name|R300_DEPTHMACROTILE_DISABLE
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|R300_DEPTHMACROTILE_ENABLE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|R300_DEPTHMICROTILE_LINEAR
value|(0<< 17)
end_define

begin_define
define|#
directive|define
name|R300_DEPTHMICROTILE_TILED
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|R300_DEPTHMICROTILE_TILED_SQUARE
value|(2<< 17)
end_define

begin_define
define|#
directive|define
name|R300_DEPTHENDIAN_NO_SWAP
value|(0<< 18)
end_define

begin_define
define|#
directive|define
name|R300_DEPTHENDIAN_WORD_SWAP
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|R300_DEPTHENDIAN_DWORD_SWAP
value|(2<< 18)
end_define

begin_define
define|#
directive|define
name|R300_DEPTHENDIAN_HALF_DWORD_SWAP
value|(3<< 18)
end_define

begin_comment
comment|/* Z Buffer Clear Value */
end_comment

begin_define
define|#
directive|define
name|R300_ZB_DEPTHCLEARVALUE
value|0x4f28
end_define

begin_define
define|#
directive|define
name|R300_ZB_ZMASK_OFFSET
value|0x4f30
end_define

begin_define
define|#
directive|define
name|R300_ZB_ZMASK_PITCH
value|0x4f34
end_define

begin_define
define|#
directive|define
name|R300_ZB_ZMASK_WRINDEX
value|0x4f38
end_define

begin_define
define|#
directive|define
name|R300_ZB_ZMASK_DWORD
value|0x4f3c
end_define

begin_define
define|#
directive|define
name|R300_ZB_ZMASK_RDINDEX
value|0x4f40
end_define

begin_comment
comment|/* Hierarchical Z Memory Offset */
end_comment

begin_define
define|#
directive|define
name|R300_ZB_HIZ_OFFSET
value|0x4f44
end_define

begin_comment
comment|/* Hierarchical Z Write Index */
end_comment

begin_define
define|#
directive|define
name|R300_ZB_HIZ_WRINDEX
value|0x4f48
end_define

begin_comment
comment|/* Hierarchical Z Data */
end_comment

begin_define
define|#
directive|define
name|R300_ZB_HIZ_DWORD
value|0x4f4c
end_define

begin_comment
comment|/* Hierarchical Z Read Index */
end_comment

begin_define
define|#
directive|define
name|R300_ZB_HIZ_RDINDEX
value|0x4f50
end_define

begin_comment
comment|/* Hierarchical Z Pitch */
end_comment

begin_define
define|#
directive|define
name|R300_ZB_HIZ_PITCH
value|0x4f54
end_define

begin_comment
comment|/* Z Buffer Z Pass Counter Data */
end_comment

begin_define
define|#
directive|define
name|R300_ZB_ZPASS_DATA
value|0x4f58
end_define

begin_comment
comment|/* Z Buffer Z Pass Counter Address */
end_comment

begin_define
define|#
directive|define
name|R300_ZB_ZPASS_ADDR
value|0x4f5c
end_define

begin_comment
comment|/* Depth buffer X and Y coordinate offset */
end_comment

begin_define
define|#
directive|define
name|R300_ZB_DEPTHXY_OFFSET
value|0x4f60
end_define

begin_define
define|#
directive|define
name|R300_DEPTHX_OFFSET_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|R300_DEPTHX_OFFSET_MASK
value|0x000007FE
end_define

begin_define
define|#
directive|define
name|R300_DEPTHY_OFFSET_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|R300_DEPTHY_OFFSET_MASK
value|0x07FE0000
end_define

begin_comment
comment|/* Sets the fifo sizes */
end_comment

begin_define
define|#
directive|define
name|R500_ZB_FIFO_SIZE
value|0x4fd0
end_define

begin_define
define|#
directive|define
name|R500_OP_FIFO_SIZE_FULL
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|R500_OP_FIFO_SIZE_HALF
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R500_OP_FIFO_SIZE_QUATER
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|R500_OP_FIFO_SIZE_EIGTHS
value|(4<< 0)
end_define

begin_comment
comment|/* Stencil Reference Value and Mask for backfacing quads */
end_comment

begin_comment
comment|/* R300_ZB_STENCILREFMASK handles front face */
end_comment

begin_define
define|#
directive|define
name|R500_ZB_STENCILREFMASK_BF
value|0x4fd4
end_define

begin_define
define|#
directive|define
name|R500_STENCILREF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R500_STENCILREF_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R500_STENCILMASK_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|R500_STENCILMASK_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|R500_STENCILWRITEMASK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|R500_STENCILWRITEMASK_MASK
value|0x00ff0000
end_define

begin_comment
comment|/* BEGIN: Vertex program instruction set */
end_comment

begin_comment
comment|/* Every instruction is four dwords long:  *  DWORD 0: output and opcode  *  DWORD 1: first argument  *  DWORD 2: second argument  *  DWORD 3: third argument  *  * Notes:  *  - ABS r, a is implemented as MAX r, a, -a  *  - MOV is implemented as ADD to zero  *  - XPD is implemented as MUL + MAD  *  - FLR is implemented as FRC + ADD  *  - apparently, fglrx tries to schedule instructions so that there is at  *    least one instruction between the write to a temporary and the first  *    read from said temporary; however, violations of this scheduling are  *    allowed  *  - register indices seem to be unrelated with OpenGL aliasing to  *    conventional state  *  - only one attribute and one parameter can be loaded at a time; however,  *    the same attribute/parameter can be used for more than one argument  *  - the second software argument for POW is the third hardware argument  *    (no idea why)  *  - MAD with only temporaries as input seems to use VPI_OUT_SELECT_MAD_2  *  * There is some magic surrounding LIT:  *   The single argument is replicated across all three inputs, but swizzled:  *     First argument: xyzy  *     Second argument: xyzx  *     Third argument: xyzw  *   Whenever the result is used later in the fragment program, fglrx forces  *   x and w to be 1.0 in the input selection; I don't know whether this is  *   strictly necessary  */
end_comment

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_DOT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_MUL
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_ADD
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_MAD
value|(4<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_DST
value|(5<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_FRC
value|(6<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_MAX
value|(7<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_MIN
value|(8<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_SGE
value|(9<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_SLT
value|(10<< 0)
end_define

begin_comment
comment|/* Used in GL_POINT_DISTANCE_ATTENUATION_ARB, vector(scalar, vector) */
end_comment

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_UNK12
value|(12<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_ARL
value|(13<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_EXP
value|(65<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_LOG
value|(66<< 0)
end_define

begin_comment
comment|/* Used in fog computations, scalar(scalar) */
end_comment

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_UNK67
value|(67<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_LIT
value|(68<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_POW
value|(69<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_RCP
value|(70<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_RSQ
value|(72<< 0)
end_define

begin_comment
comment|/* Used in GL_POINT_DISTANCE_ATTENUATION_ARB, scalar(scalar) */
end_comment

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_UNK73
value|(73<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_EX2
value|(75<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_LG2
value|(76<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_MAD_2
value|(128<< 0)
end_define

begin_comment
comment|/* all temps, vector(scalar, vector, vector) */
end_comment

begin_define
define|#
directive|define
name|R300_VPI_OUT_OP_UNK129
value|(129<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_REG_CLASS_TEMPORARY
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_REG_CLASS_ADDR
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_REG_CLASS_RESULT
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_REG_CLASS_MASK
value|(31<< 8)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_REG_INDEX_SHIFT
value|13
end_define

begin_comment
comment|/* GUESS based on fglrx native limits */
end_comment

begin_define
define|#
directive|define
name|R300_VPI_OUT_REG_INDEX_MASK
value|(31<< 13)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_WRITE_X
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_WRITE_Y
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_WRITE_Z
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|R300_VPI_OUT_WRITE_W
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|R300_VPI_IN_REG_CLASS_TEMPORARY
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_IN_REG_CLASS_ATTRIBUTE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_IN_REG_CLASS_PARAMETER
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_IN_REG_CLASS_NONE
value|(9<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_IN_REG_CLASS_MASK
value|(31<< 0)
end_define

begin_define
define|#
directive|define
name|R300_VPI_IN_REG_INDEX_SHIFT
value|5
end_define

begin_comment
comment|/* GUESS based on fglrx native limits */
end_comment

begin_define
define|#
directive|define
name|R300_VPI_IN_REG_INDEX_MASK
value|(255<< 5)
end_define

begin_comment
comment|/* The R300 can select components from the input register arbitrarily.  * Use the following constants, shifted by the component shift you  * want to select  */
end_comment

begin_define
define|#
directive|define
name|R300_VPI_IN_SELECT_X
value|0
end_define

begin_define
define|#
directive|define
name|R300_VPI_IN_SELECT_Y
value|1
end_define

begin_define
define|#
directive|define
name|R300_VPI_IN_SELECT_Z
value|2
end_define

begin_define
define|#
directive|define
name|R300_VPI_IN_SELECT_W
value|3
end_define

begin_define
define|#
directive|define
name|R300_VPI_IN_SELECT_ZERO
value|4
end_define

begin_define
define|#
directive|define
name|R300_VPI_IN_SELECT_ONE
value|5
end_define

begin_define
define|#
directive|define
name|R300_VPI_IN_SELECT_MASK
value|7
end_define

begin_define
define|#
directive|define
name|R300_VPI_IN_X_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|R300_VPI_IN_Y_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|R300_VPI_IN_Z_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|R300_VPI_IN_W_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|R300_VPI_IN_NEG_X
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|R300_VPI_IN_NEG_Y
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|R300_VPI_IN_NEG_Z
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|R300_VPI_IN_NEG_W
value|(1<< 28)
end_define

begin_comment
comment|/* END: Vertex program instruction set */
end_comment

begin_comment
comment|/* BEGIN: Packet 3 commands */
end_comment

begin_comment
comment|/* A primitive emission dword. */
end_comment

begin_define
define|#
directive|define
name|R300_PRIM_TYPE_NONE
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PRIM_TYPE_POINT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PRIM_TYPE_LINE
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PRIM_TYPE_LINE_STRIP
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PRIM_TYPE_TRI_LIST
value|(4<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PRIM_TYPE_TRI_FAN
value|(5<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PRIM_TYPE_TRI_STRIP
value|(6<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PRIM_TYPE_TRI_TYPE2
value|(7<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PRIM_TYPE_RECT_LIST
value|(8<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PRIM_TYPE_3VRT_POINT_LIST
value|(9<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PRIM_TYPE_3VRT_LINE_LIST
value|(10<< 0)
end_define

begin_comment
comment|/* GUESS (based on r200) */
end_comment

begin_define
define|#
directive|define
name|R300_PRIM_TYPE_POINT_SPRITES
value|(11<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PRIM_TYPE_LINE_LOOP
value|(12<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PRIM_TYPE_QUADS
value|(13<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PRIM_TYPE_QUAD_STRIP
value|(14<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PRIM_TYPE_POLYGON
value|(15<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PRIM_TYPE_MASK
value|0xF
end_define

begin_define
define|#
directive|define
name|R300_PRIM_WALK_IND
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|R300_PRIM_WALK_LIST
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|R300_PRIM_WALK_RING
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|R300_PRIM_WALK_MASK
value|(3<< 4)
end_define

begin_comment
comment|/* GUESS (based on r200) */
end_comment

begin_define
define|#
directive|define
name|R300_PRIM_COLOR_ORDER_BGRA
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|R300_PRIM_COLOR_ORDER_RGBA
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|R300_PRIM_NUM_VERTICES_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|R300_PRIM_NUM_VERTICES_MASK
value|0xffff
end_define

begin_comment
comment|/* Draw a primitive from vertex data in arrays loaded via 3D_LOAD_VBPNTR.  * Two parameter dwords:  * 0. The first parameter appears to be always 0  * 1. The second parameter is a standard primitive emission dword.  */
end_comment

begin_define
define|#
directive|define
name|R300_PACKET3_3D_DRAW_VBUF
value|0x00002800
end_define

begin_comment
comment|/* Specify the full set of vertex arrays as (address, stride).  * The first parameter is the number of vertex arrays specified.  * The rest of the command is a variable length list of blocks, where  * each block is three dwords long and specifies two arrays.  * The first dword of a block is split into two words, the lower significant  * word refers to the first array, the more significant word to the second  * array in the block.  * The low byte of each word contains the size of an array entry in dwords,  * the high byte contains the stride of the array.  * The second dword of a block contains the pointer to the first array,  * the third dword of a block contains the pointer to the second array.  * Note that if the total number of arrays is odd, the third dword of  * the last block is omitted.  */
end_comment

begin_define
define|#
directive|define
name|R300_PACKET3_3D_LOAD_VBPNTR
value|0x00002F00
end_define

begin_define
define|#
directive|define
name|R300_PACKET3_INDX_BUFFER
value|0x00003300
end_define

begin_define
define|#
directive|define
name|R300_EB_UNK1_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|R300_EB_UNK1
value|(0x80<<24)
end_define

begin_define
define|#
directive|define
name|R300_EB_UNK2
value|0x0810
end_define

begin_define
define|#
directive|define
name|R300_PACKET3_3D_DRAW_VBUF_2
value|0x00003400
end_define

begin_define
define|#
directive|define
name|R300_PACKET3_3D_DRAW_INDX_2
value|0x00003600
end_define

begin_comment
comment|/* END: Packet 3 commands */
end_comment

begin_comment
comment|/* Color formats for 2d packets  */
end_comment

begin_define
define|#
directive|define
name|R300_CP_COLOR_FORMAT_CI8
value|2
end_define

begin_define
define|#
directive|define
name|R300_CP_COLOR_FORMAT_ARGB1555
value|3
end_define

begin_define
define|#
directive|define
name|R300_CP_COLOR_FORMAT_RGB565
value|4
end_define

begin_define
define|#
directive|define
name|R300_CP_COLOR_FORMAT_ARGB8888
value|6
end_define

begin_define
define|#
directive|define
name|R300_CP_COLOR_FORMAT_RGB332
value|7
end_define

begin_define
define|#
directive|define
name|R300_CP_COLOR_FORMAT_RGB8
value|9
end_define

begin_define
define|#
directive|define
name|R300_CP_COLOR_FORMAT_ARGB4444
value|15
end_define

begin_comment
comment|/*  * CP type-3 packets  */
end_comment

begin_define
define|#
directive|define
name|R300_CP_CMD_BITBLT_MULTI
value|0xC0009B00
end_define

begin_define
define|#
directive|define
name|R500_VAP_INDEX_OFFSET
value|0x208c
end_define

begin_define
define|#
directive|define
name|R500_GA_US_VECTOR_INDEX
value|0x4250
end_define

begin_define
define|#
directive|define
name|R500_GA_US_VECTOR_DATA
value|0x4254
end_define

begin_define
define|#
directive|define
name|R500_RS_IP_0
value|0x4074
end_define

begin_define
define|#
directive|define
name|R500_RS_INST_0
value|0x4320
end_define

begin_define
define|#
directive|define
name|R500_US_CONFIG
value|0x4600
end_define

begin_define
define|#
directive|define
name|R500_US_FC_CTRL
value|0x4624
end_define

begin_define
define|#
directive|define
name|R500_US_CODE_ADDR
value|0x4630
end_define

begin_define
define|#
directive|define
name|R500_RB3D_COLOR_CLEAR_VALUE_AR
value|0x46c0
end_define

begin_define
define|#
directive|define
name|R500_RB3D_CONSTANT_COLOR_AR
value|0x4ef8
end_define

begin_define
define|#
directive|define
name|R300_SU_REG_DEST
value|0x42c8
end_define

begin_define
define|#
directive|define
name|RV530_FG_ZBREG_DEST
value|0x4be8
end_define

begin_define
define|#
directive|define
name|R300_ZB_ZPASS_DATA
value|0x4f58
end_define

begin_define
define|#
directive|define
name|R300_ZB_ZPASS_ADDR
value|0x4f5c
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _R300_REG_H */
end_comment

begin_comment
comment|/* *INDENT-ON* */
end_comment

end_unit

