begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* radeon_drm.h -- Public header for the radeon driver -*- linux-c -*-  *  * Copyright 2000 Precision Insight, Inc., Cedar Park, Texas.  * Copyright 2000 VA Linux Systems, Inc., Fremont, California.  * Copyright 2002 Tungsten Graphics, Inc., Cedar Park, Texas.  * All rights reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Kevin E. Martin<martin@valinux.com>  *    Gareth Hughes<gareth@valinux.com>  *    Keith Whitwell<keith@tungstengraphics.com>  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RADEON_DRM_H__
end_ifndef

begin_define
define|#
directive|define
name|__RADEON_DRM_H__
end_define

begin_comment
comment|/* WARNING: If you change any of these defines, make sure to change the  * defines in the X server file (radeon_sarea.h)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RADEON_SAREA_DEFINES__
end_ifndef

begin_define
define|#
directive|define
name|__RADEON_SAREA_DEFINES__
end_define

begin_comment
comment|/* Old style state flags, required for sarea interface (1.1 and 1.2  * clears) and 1.2 drm_vertex2 ioctl.  */
end_comment

begin_define
define|#
directive|define
name|RADEON_UPLOAD_CONTEXT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RADEON_UPLOAD_VERTFMT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RADEON_UPLOAD_LINE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|RADEON_UPLOAD_BUMPMAP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|RADEON_UPLOAD_MASKS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RADEON_UPLOAD_VIEWPORT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|RADEON_UPLOAD_SETUP
value|0x00000040
end_define

begin_define
define|#
directive|define
name|RADEON_UPLOAD_TCL
value|0x00000080
end_define

begin_define
define|#
directive|define
name|RADEON_UPLOAD_MISC
value|0x00000100
end_define

begin_define
define|#
directive|define
name|RADEON_UPLOAD_TEX0
value|0x00000200
end_define

begin_define
define|#
directive|define
name|RADEON_UPLOAD_TEX1
value|0x00000400
end_define

begin_define
define|#
directive|define
name|RADEON_UPLOAD_TEX2
value|0x00000800
end_define

begin_define
define|#
directive|define
name|RADEON_UPLOAD_TEX0IMAGES
value|0x00001000
end_define

begin_define
define|#
directive|define
name|RADEON_UPLOAD_TEX1IMAGES
value|0x00002000
end_define

begin_define
define|#
directive|define
name|RADEON_UPLOAD_TEX2IMAGES
value|0x00004000
end_define

begin_define
define|#
directive|define
name|RADEON_UPLOAD_CLIPRECTS
value|0x00008000
end_define

begin_comment
comment|/* handled client-side */
end_comment

begin_define
define|#
directive|define
name|RADEON_REQUIRE_QUIESCENCE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|RADEON_UPLOAD_ZBIAS
value|0x00020000
end_define

begin_comment
comment|/* version 1.2 and newer */
end_comment

begin_define
define|#
directive|define
name|RADEON_UPLOAD_ALL
value|0x003effff
end_define

begin_define
define|#
directive|define
name|RADEON_UPLOAD_CONTEXT_ALL
value|0x003e01ff
end_define

begin_comment
comment|/* New style per-packet identifiers for use in cmd_buffer ioctl with  * the RADEON_EMIT_PACKET command.  Comments relate new packets to old  * state bits and the packet size:  */
end_comment

begin_define
define|#
directive|define
name|RADEON_EMIT_PP_MISC
value|0
end_define

begin_comment
comment|/* context/7 */
end_comment

begin_define
define|#
directive|define
name|RADEON_EMIT_PP_CNTL
value|1
end_define

begin_comment
comment|/* context/3 */
end_comment

begin_define
define|#
directive|define
name|RADEON_EMIT_RB3D_COLORPITCH
value|2
end_define

begin_comment
comment|/* context/1 */
end_comment

begin_define
define|#
directive|define
name|RADEON_EMIT_RE_LINE_PATTERN
value|3
end_define

begin_comment
comment|/* line/2 */
end_comment

begin_define
define|#
directive|define
name|RADEON_EMIT_SE_LINE_WIDTH
value|4
end_define

begin_comment
comment|/* line/1 */
end_comment

begin_define
define|#
directive|define
name|RADEON_EMIT_PP_LUM_MATRIX
value|5
end_define

begin_comment
comment|/* bumpmap/1 */
end_comment

begin_define
define|#
directive|define
name|RADEON_EMIT_PP_ROT_MATRIX_0
value|6
end_define

begin_comment
comment|/* bumpmap/2 */
end_comment

begin_define
define|#
directive|define
name|RADEON_EMIT_RB3D_STENCILREFMASK
value|7
end_define

begin_comment
comment|/* masks/3 */
end_comment

begin_define
define|#
directive|define
name|RADEON_EMIT_SE_VPORT_XSCALE
value|8
end_define

begin_comment
comment|/* viewport/6 */
end_comment

begin_define
define|#
directive|define
name|RADEON_EMIT_SE_CNTL
value|9
end_define

begin_comment
comment|/* setup/2 */
end_comment

begin_define
define|#
directive|define
name|RADEON_EMIT_SE_CNTL_STATUS
value|10
end_define

begin_comment
comment|/* setup/1 */
end_comment

begin_define
define|#
directive|define
name|RADEON_EMIT_RE_MISC
value|11
end_define

begin_comment
comment|/* misc/1 */
end_comment

begin_define
define|#
directive|define
name|RADEON_EMIT_PP_TXFILTER_0
value|12
end_define

begin_comment
comment|/* tex0/6 */
end_comment

begin_define
define|#
directive|define
name|RADEON_EMIT_PP_BORDER_COLOR_0
value|13
end_define

begin_comment
comment|/* tex0/1 */
end_comment

begin_define
define|#
directive|define
name|RADEON_EMIT_PP_TXFILTER_1
value|14
end_define

begin_comment
comment|/* tex1/6 */
end_comment

begin_define
define|#
directive|define
name|RADEON_EMIT_PP_BORDER_COLOR_1
value|15
end_define

begin_comment
comment|/* tex1/1 */
end_comment

begin_define
define|#
directive|define
name|RADEON_EMIT_PP_TXFILTER_2
value|16
end_define

begin_comment
comment|/* tex2/6 */
end_comment

begin_define
define|#
directive|define
name|RADEON_EMIT_PP_BORDER_COLOR_2
value|17
end_define

begin_comment
comment|/* tex2/1 */
end_comment

begin_define
define|#
directive|define
name|RADEON_EMIT_SE_ZBIAS_FACTOR
value|18
end_define

begin_comment
comment|/* zbias/2 */
end_comment

begin_define
define|#
directive|define
name|RADEON_EMIT_SE_TCL_OUTPUT_VTX_FMT
value|19
end_define

begin_comment
comment|/* tcl/11 */
end_comment

begin_define
define|#
directive|define
name|RADEON_EMIT_SE_TCL_MATERIAL_EMMISSIVE_RED
value|20
end_define

begin_comment
comment|/* material/17 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_TXCBLEND_0
value|21
end_define

begin_comment
comment|/* tex0/4 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_TXCBLEND_1
value|22
end_define

begin_comment
comment|/* tex1/4 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_TXCBLEND_2
value|23
end_define

begin_comment
comment|/* tex2/4 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_TXCBLEND_3
value|24
end_define

begin_comment
comment|/* tex3/4 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_TXCBLEND_4
value|25
end_define

begin_comment
comment|/* tex4/4 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_TXCBLEND_5
value|26
end_define

begin_comment
comment|/* tex5/4 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_TXCBLEND_6
value|27
end_define

begin_comment
comment|/* /4 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_TXCBLEND_7
value|28
end_define

begin_comment
comment|/* /4 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_TCL_LIGHT_MODEL_CTL_0
value|29
end_define

begin_comment
comment|/* tcl/7 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_TFACTOR_0
value|30
end_define

begin_comment
comment|/* tf/7 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_VTX_FMT_0
value|31
end_define

begin_comment
comment|/* vtx/5 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_VAP_CTL
value|32
end_define

begin_comment
comment|/* vap/1 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_MATRIX_SELECT_0
value|33
end_define

begin_comment
comment|/* msl/5 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_TEX_PROC_CTL_2
value|34
end_define

begin_comment
comment|/* tcg/5 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_TCL_UCP_VERT_BLEND_CTL
value|35
end_define

begin_comment
comment|/* tcl/1 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_TXFILTER_0
value|36
end_define

begin_comment
comment|/* tex0/6 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_TXFILTER_1
value|37
end_define

begin_comment
comment|/* tex1/6 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_TXFILTER_2
value|38
end_define

begin_comment
comment|/* tex2/6 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_TXFILTER_3
value|39
end_define

begin_comment
comment|/* tex3/6 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_TXFILTER_4
value|40
end_define

begin_comment
comment|/* tex4/6 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_TXFILTER_5
value|41
end_define

begin_comment
comment|/* tex5/6 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_TXOFFSET_0
value|42
end_define

begin_comment
comment|/* tex0/1 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_TXOFFSET_1
value|43
end_define

begin_comment
comment|/* tex1/1 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_TXOFFSET_2
value|44
end_define

begin_comment
comment|/* tex2/1 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_TXOFFSET_3
value|45
end_define

begin_comment
comment|/* tex3/1 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_TXOFFSET_4
value|46
end_define

begin_comment
comment|/* tex4/1 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_TXOFFSET_5
value|47
end_define

begin_comment
comment|/* tex5/1 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_VTE_CNTL
value|48
end_define

begin_comment
comment|/* vte/1 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_OUTPUT_VTX_COMP_SEL
value|49
end_define

begin_comment
comment|/* vtx/1 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_TAM_DEBUG3
value|50
end_define

begin_comment
comment|/* tam/1 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_CNTL_X
value|51
end_define

begin_comment
comment|/* cst/1 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_RB3D_DEPTHXY_OFFSET
value|52
end_define

begin_comment
comment|/* cst/1 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_RE_AUX_SCISSOR_CNTL
value|53
end_define

begin_comment
comment|/* cst/1 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_RE_SCISSOR_TL_0
value|54
end_define

begin_comment
comment|/* cst/2 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_RE_SCISSOR_TL_1
value|55
end_define

begin_comment
comment|/* cst/2 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_RE_SCISSOR_TL_2
value|56
end_define

begin_comment
comment|/* cst/2 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_SE_VAP_CNTL_STATUS
value|57
end_define

begin_comment
comment|/* cst/1 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_SE_VTX_STATE_CNTL
value|58
end_define

begin_comment
comment|/* cst/1 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_RE_POINTSIZE
value|59
end_define

begin_comment
comment|/* cst/1 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_TCL_INPUT_VTX_VECTOR_ADDR_0
value|60
end_define

begin_comment
comment|/* cst/4 */
end_comment

begin_define
define|#
directive|define
name|R200_EMIT_PP_CUBIC_FACES_0
value|61
end_define

begin_define
define|#
directive|define
name|R200_EMIT_PP_CUBIC_OFFSETS_0
value|62
end_define

begin_define
define|#
directive|define
name|R200_EMIT_PP_CUBIC_FACES_1
value|63
end_define

begin_define
define|#
directive|define
name|R200_EMIT_PP_CUBIC_OFFSETS_1
value|64
end_define

begin_define
define|#
directive|define
name|R200_EMIT_PP_CUBIC_FACES_2
value|65
end_define

begin_define
define|#
directive|define
name|R200_EMIT_PP_CUBIC_OFFSETS_2
value|66
end_define

begin_define
define|#
directive|define
name|R200_EMIT_PP_CUBIC_FACES_3
value|67
end_define

begin_define
define|#
directive|define
name|R200_EMIT_PP_CUBIC_OFFSETS_3
value|68
end_define

begin_define
define|#
directive|define
name|R200_EMIT_PP_CUBIC_FACES_4
value|69
end_define

begin_define
define|#
directive|define
name|R200_EMIT_PP_CUBIC_OFFSETS_4
value|70
end_define

begin_define
define|#
directive|define
name|R200_EMIT_PP_CUBIC_FACES_5
value|71
end_define

begin_define
define|#
directive|define
name|R200_EMIT_PP_CUBIC_OFFSETS_5
value|72
end_define

begin_define
define|#
directive|define
name|RADEON_EMIT_PP_TEX_SIZE_0
value|73
end_define

begin_define
define|#
directive|define
name|RADEON_EMIT_PP_TEX_SIZE_1
value|74
end_define

begin_define
define|#
directive|define
name|RADEON_EMIT_PP_TEX_SIZE_2
value|75
end_define

begin_define
define|#
directive|define
name|RADEON_MAX_STATE_PACKETS
value|76
end_define

begin_comment
comment|/* Commands understood by cmd_buffer ioctl.  More can be added but  * obviously these can't be removed or changed:  */
end_comment

begin_define
define|#
directive|define
name|RADEON_CMD_PACKET
value|1
end_define

begin_comment
comment|/* emit one of the register packets above */
end_comment

begin_define
define|#
directive|define
name|RADEON_CMD_SCALARS
value|2
end_define

begin_comment
comment|/* emit scalar data */
end_comment

begin_define
define|#
directive|define
name|RADEON_CMD_VECTORS
value|3
end_define

begin_comment
comment|/* emit vector data */
end_comment

begin_define
define|#
directive|define
name|RADEON_CMD_DMA_DISCARD
value|4
end_define

begin_comment
comment|/* discard current dma buf */
end_comment

begin_define
define|#
directive|define
name|RADEON_CMD_PACKET3
value|5
end_define

begin_comment
comment|/* emit hw packet */
end_comment

begin_define
define|#
directive|define
name|RADEON_CMD_PACKET3_CLIP
value|6
end_define

begin_comment
comment|/* emit hw packet wrapped in cliprects */
end_comment

begin_define
define|#
directive|define
name|RADEON_CMD_SCALARS2
value|7
end_define

begin_comment
comment|/* r200 stopgap */
end_comment

begin_define
define|#
directive|define
name|RADEON_CMD_WAIT
value|8
end_define

begin_comment
comment|/* emit hw wait commands -- note: 				   *  doesn't make the cpu wait, just 				   *  the graphics hardware */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|int
name|i
decl_stmt|;
struct|struct
block|{
name|unsigned
name|char
name|cmd_type
decl_stmt|,
name|pad0
decl_stmt|,
name|pad1
decl_stmt|,
name|pad2
decl_stmt|;
block|}
name|header
struct|;
struct|struct
block|{
name|unsigned
name|char
name|cmd_type
decl_stmt|,
name|packet_id
decl_stmt|,
name|pad0
decl_stmt|,
name|pad1
decl_stmt|;
block|}
name|packet
struct|;
struct|struct
block|{
name|unsigned
name|char
name|cmd_type
decl_stmt|,
name|offset
decl_stmt|,
name|stride
decl_stmt|,
name|count
decl_stmt|;
block|}
name|scalars
struct|;
struct|struct
block|{
name|unsigned
name|char
name|cmd_type
decl_stmt|,
name|offset
decl_stmt|,
name|stride
decl_stmt|,
name|count
decl_stmt|;
block|}
name|vectors
struct|;
struct|struct
block|{
name|unsigned
name|char
name|cmd_type
decl_stmt|,
name|buf_idx
decl_stmt|,
name|pad0
decl_stmt|,
name|pad1
decl_stmt|;
block|}
name|dma
struct|;
struct|struct
block|{
name|unsigned
name|char
name|cmd_type
decl_stmt|,
name|flags
decl_stmt|,
name|pad0
decl_stmt|,
name|pad1
decl_stmt|;
block|}
name|wait
struct|;
block|}
name|drm_radeon_cmd_header_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RADEON_WAIT_2D
value|0x1
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_3D
value|0x2
end_define

begin_define
define|#
directive|define
name|RADEON_FRONT
value|0x1
end_define

begin_define
define|#
directive|define
name|RADEON_BACK
value|0x2
end_define

begin_define
define|#
directive|define
name|RADEON_DEPTH
value|0x4
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL
value|0x8
end_define

begin_comment
comment|/* Primitive types  */
end_comment

begin_define
define|#
directive|define
name|RADEON_POINTS
value|0x1
end_define

begin_define
define|#
directive|define
name|RADEON_LINES
value|0x2
end_define

begin_define
define|#
directive|define
name|RADEON_LINE_STRIP
value|0x3
end_define

begin_define
define|#
directive|define
name|RADEON_TRIANGLES
value|0x4
end_define

begin_define
define|#
directive|define
name|RADEON_TRIANGLE_FAN
value|0x5
end_define

begin_define
define|#
directive|define
name|RADEON_TRIANGLE_STRIP
value|0x6
end_define

begin_comment
comment|/* Vertex/indirect buffer size  */
end_comment

begin_define
define|#
directive|define
name|RADEON_BUFFER_SIZE
value|65536
end_define

begin_comment
comment|/* Byte offsets for indirect buffer data  */
end_comment

begin_define
define|#
directive|define
name|RADEON_INDEX_PRIM_OFFSET
value|20
end_define

begin_define
define|#
directive|define
name|RADEON_SCRATCH_REG_OFFSET
value|32
end_define

begin_define
define|#
directive|define
name|RADEON_NR_SAREA_CLIPRECTS
value|12
end_define

begin_comment
comment|/* There are 2 heaps (local/AGP).  Each region within a heap is a  * minimum of 64k, and there are at most 64 of them per heap.  */
end_comment

begin_define
define|#
directive|define
name|RADEON_LOCAL_TEX_HEAP
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_AGP_TEX_HEAP
value|1
end_define

begin_define
define|#
directive|define
name|RADEON_NR_TEX_HEAPS
value|2
end_define

begin_define
define|#
directive|define
name|RADEON_NR_TEX_REGIONS
value|64
end_define

begin_define
define|#
directive|define
name|RADEON_LOG_TEX_GRANULARITY
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_MAX_TEXTURE_LEVELS
value|12
end_define

begin_define
define|#
directive|define
name|RADEON_MAX_TEXTURE_UNITS
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __RADEON_SAREA_DEFINES__ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|red
decl_stmt|;
name|unsigned
name|int
name|green
decl_stmt|;
name|unsigned
name|int
name|blue
decl_stmt|;
name|unsigned
name|int
name|alpha
decl_stmt|;
block|}
name|radeon_color_regs_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Context state */
name|unsigned
name|int
name|pp_misc
decl_stmt|;
comment|/* 0x1c14 */
name|unsigned
name|int
name|pp_fog_color
decl_stmt|;
name|unsigned
name|int
name|re_solid_color
decl_stmt|;
name|unsigned
name|int
name|rb3d_blendcntl
decl_stmt|;
name|unsigned
name|int
name|rb3d_depthoffset
decl_stmt|;
name|unsigned
name|int
name|rb3d_depthpitch
decl_stmt|;
name|unsigned
name|int
name|rb3d_zstencilcntl
decl_stmt|;
name|unsigned
name|int
name|pp_cntl
decl_stmt|;
comment|/* 0x1c38 */
name|unsigned
name|int
name|rb3d_cntl
decl_stmt|;
name|unsigned
name|int
name|rb3d_coloroffset
decl_stmt|;
name|unsigned
name|int
name|re_width_height
decl_stmt|;
name|unsigned
name|int
name|rb3d_colorpitch
decl_stmt|;
name|unsigned
name|int
name|se_cntl
decl_stmt|;
comment|/* Vertex format state */
name|unsigned
name|int
name|se_coord_fmt
decl_stmt|;
comment|/* 0x1c50 */
comment|/* Line state */
name|unsigned
name|int
name|re_line_pattern
decl_stmt|;
comment|/* 0x1cd0 */
name|unsigned
name|int
name|re_line_state
decl_stmt|;
name|unsigned
name|int
name|se_line_width
decl_stmt|;
comment|/* 0x1db8 */
comment|/* Bumpmap state */
name|unsigned
name|int
name|pp_lum_matrix
decl_stmt|;
comment|/* 0x1d00 */
name|unsigned
name|int
name|pp_rot_matrix_0
decl_stmt|;
comment|/* 0x1d58 */
name|unsigned
name|int
name|pp_rot_matrix_1
decl_stmt|;
comment|/* Mask state */
name|unsigned
name|int
name|rb3d_stencilrefmask
decl_stmt|;
comment|/* 0x1d7c */
name|unsigned
name|int
name|rb3d_ropcntl
decl_stmt|;
name|unsigned
name|int
name|rb3d_planemask
decl_stmt|;
comment|/* Viewport state */
name|unsigned
name|int
name|se_vport_xscale
decl_stmt|;
comment|/* 0x1d98 */
name|unsigned
name|int
name|se_vport_xoffset
decl_stmt|;
name|unsigned
name|int
name|se_vport_yscale
decl_stmt|;
name|unsigned
name|int
name|se_vport_yoffset
decl_stmt|;
name|unsigned
name|int
name|se_vport_zscale
decl_stmt|;
name|unsigned
name|int
name|se_vport_zoffset
decl_stmt|;
comment|/* Setup state */
name|unsigned
name|int
name|se_cntl_status
decl_stmt|;
comment|/* 0x2140 */
comment|/* Misc state */
name|unsigned
name|int
name|re_top_left
decl_stmt|;
comment|/* 0x26c0 */
name|unsigned
name|int
name|re_misc
decl_stmt|;
block|}
name|drm_radeon_context_regs_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Zbias state */
name|unsigned
name|int
name|se_zbias_factor
decl_stmt|;
comment|/* 0x1dac */
name|unsigned
name|int
name|se_zbias_constant
decl_stmt|;
block|}
name|drm_radeon_context2_regs_t
typedef|;
end_typedef

begin_comment
comment|/* Setup registers for each texture unit  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|pp_txfilter
decl_stmt|;
name|unsigned
name|int
name|pp_txformat
decl_stmt|;
name|unsigned
name|int
name|pp_txoffset
decl_stmt|;
name|unsigned
name|int
name|pp_txcblend
decl_stmt|;
name|unsigned
name|int
name|pp_txablend
decl_stmt|;
name|unsigned
name|int
name|pp_tfactor
decl_stmt|;
name|unsigned
name|int
name|pp_border_color
decl_stmt|;
block|}
name|drm_radeon_texture_regs_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|start
decl_stmt|;
name|unsigned
name|int
name|finish
decl_stmt|;
name|unsigned
name|int
name|prim
range|:
literal|8
decl_stmt|;
name|unsigned
name|int
name|stateidx
range|:
literal|8
decl_stmt|;
name|unsigned
name|int
name|numverts
range|:
literal|16
decl_stmt|;
comment|/* overloaded as offset/64 for elt prims */
name|unsigned
name|int
name|vc_format
decl_stmt|;
comment|/* vertex format */
block|}
name|drm_radeon_prim_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|drm_radeon_context_regs_t
name|context
decl_stmt|;
name|drm_radeon_texture_regs_t
name|tex
index|[
name|RADEON_MAX_TEXTURE_UNITS
index|]
decl_stmt|;
name|drm_radeon_context2_regs_t
name|context2
decl_stmt|;
name|unsigned
name|int
name|dirty
decl_stmt|;
block|}
name|drm_radeon_state_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* The channel for communication of state information to the 	 * kernel on firing a vertex buffer with either of the 	 * obsoleted vertex/index ioctls. 	 */
name|drm_radeon_context_regs_t
name|context_state
decl_stmt|;
name|drm_radeon_texture_regs_t
name|tex_state
index|[
name|RADEON_MAX_TEXTURE_UNITS
index|]
decl_stmt|;
name|unsigned
name|int
name|dirty
decl_stmt|;
name|unsigned
name|int
name|vertsize
decl_stmt|;
name|unsigned
name|int
name|vc_format
decl_stmt|;
comment|/* The current cliprects, or a subset thereof. 	 */
name|drm_clip_rect_t
name|boxes
index|[
name|RADEON_NR_SAREA_CLIPRECTS
index|]
decl_stmt|;
name|unsigned
name|int
name|nbox
decl_stmt|;
comment|/* Counters for client-side throttling of rendering clients. 	 */
name|unsigned
name|int
name|last_frame
decl_stmt|;
name|unsigned
name|int
name|last_dispatch
decl_stmt|;
name|unsigned
name|int
name|last_clear
decl_stmt|;
name|drm_tex_region_t
name|tex_list
index|[
name|RADEON_NR_TEX_HEAPS
index|]
index|[
name|RADEON_NR_TEX_REGIONS
operator|+
literal|1
index|]
decl_stmt|;
name|unsigned
name|int
name|tex_age
index|[
name|RADEON_NR_TEX_HEAPS
index|]
decl_stmt|;
name|int
name|ctx_owner
decl_stmt|;
name|int
name|pfState
decl_stmt|;
comment|/* number of 3d windows (0,1,2ormore) */
name|int
name|pfCurrentPage
decl_stmt|;
comment|/* which buffer is being displayed? */
name|int
name|crtc2_base
decl_stmt|;
comment|/* CRTC2 frame offset */
block|}
name|drm_radeon_sarea_t
typedef|;
end_typedef

begin_comment
comment|/* WARNING: If you change any of these defines, make sure to change the  * defines in the Xserver file (xf86drmRadeon.h)  *  * KW: actually it's illegal to change any of this (backwards compatibility).  */
end_comment

begin_comment
comment|/* Radeon specific ioctls  * The device specific ioctl range is 0x40 to 0x79.  */
end_comment

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_CP_INIT
value|DRM_IOW( 0x40, drm_radeon_init_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_CP_START
value|DRM_IO(  0x41)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_CP_STOP
value|DRM_IOW( 0x42, drm_radeon_cp_stop_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_CP_RESET
value|DRM_IO(  0x43)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_CP_IDLE
value|DRM_IO(  0x44)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_RESET
value|DRM_IO(  0x45)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_FULLSCREEN
value|DRM_IOW( 0x46, drm_radeon_fullscreen_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_SWAP
value|DRM_IO(  0x47)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_CLEAR
value|DRM_IOW( 0x48, drm_radeon_clear_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_VERTEX
value|DRM_IOW( 0x49, drm_radeon_vertex_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_INDICES
value|DRM_IOW( 0x4a, drm_radeon_indices_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_STIPPLE
value|DRM_IOW( 0x4c, drm_radeon_stipple_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_INDIRECT
value|DRM_IOWR(0x4d, drm_radeon_indirect_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_TEXTURE
value|DRM_IOWR(0x4e, drm_radeon_texture_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_VERTEX2
value|DRM_IOW( 0x4f, drm_radeon_vertex2_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_CMDBUF
value|DRM_IOW( 0x50, drm_radeon_cmd_buffer_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_GETPARAM
value|DRM_IOWR(0x51, drm_radeon_getparam_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_FLIP
value|DRM_IO(  0x52)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_ALLOC
value|DRM_IOWR( 0x53, drm_radeon_mem_alloc_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_FREE
value|DRM_IOW( 0x54, drm_radeon_mem_free_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_INIT_HEAP
value|DRM_IOW( 0x55, drm_radeon_mem_init_heap_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_IRQ_EMIT
value|DRM_IOWR( 0x56, drm_radeon_irq_emit_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_IRQ_WAIT
value|DRM_IOW( 0x57, drm_radeon_irq_wait_t)
end_define

begin_comment
comment|/* added by Charl P. Botha - see radeon_cp.c for details */
end_comment

begin_define
define|#
directive|define
name|DRM_IOCTL_RADEON_CP_RESUME
value|DRM_IO(0x58)
end_define

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_init
block|{
enum|enum
block|{
name|RADEON_INIT_CP
init|=
literal|0x01
block|,
name|RADEON_CLEANUP_CP
init|=
literal|0x02
block|,
name|RADEON_INIT_R200_CP
init|=
literal|0x03
block|}
name|func
enum|;
name|unsigned
name|long
name|sarea_priv_offset
decl_stmt|;
name|int
name|is_pci
decl_stmt|;
name|int
name|cp_mode
decl_stmt|;
name|int
name|agp_size
decl_stmt|;
name|int
name|ring_size
decl_stmt|;
name|int
name|usec_timeout
decl_stmt|;
name|unsigned
name|int
name|fb_bpp
decl_stmt|;
name|unsigned
name|int
name|front_offset
decl_stmt|,
name|front_pitch
decl_stmt|;
name|unsigned
name|int
name|back_offset
decl_stmt|,
name|back_pitch
decl_stmt|;
name|unsigned
name|int
name|depth_bpp
decl_stmt|;
name|unsigned
name|int
name|depth_offset
decl_stmt|,
name|depth_pitch
decl_stmt|;
name|unsigned
name|long
name|fb_offset
decl_stmt|;
name|unsigned
name|long
name|mmio_offset
decl_stmt|;
name|unsigned
name|long
name|ring_offset
decl_stmt|;
name|unsigned
name|long
name|ring_rptr_offset
decl_stmt|;
name|unsigned
name|long
name|buffers_offset
decl_stmt|;
name|unsigned
name|long
name|agp_textures_offset
decl_stmt|;
block|}
name|drm_radeon_init_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_cp_stop
block|{
name|int
name|flush
decl_stmt|;
name|int
name|idle
decl_stmt|;
block|}
name|drm_radeon_cp_stop_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_fullscreen
block|{
enum|enum
block|{
name|RADEON_INIT_FULLSCREEN
init|=
literal|0x01
block|,
name|RADEON_CLEANUP_FULLSCREEN
init|=
literal|0x02
block|}
name|func
enum|;
block|}
name|drm_radeon_fullscreen_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CLEAR_X1
value|0
end_define

begin_define
define|#
directive|define
name|CLEAR_Y1
value|1
end_define

begin_define
define|#
directive|define
name|CLEAR_X2
value|2
end_define

begin_define
define|#
directive|define
name|CLEAR_Y2
value|3
end_define

begin_define
define|#
directive|define
name|CLEAR_DEPTH
value|4
end_define

begin_typedef
typedef|typedef
union|union
name|drm_radeon_clear_rect
block|{
name|float
name|f
index|[
literal|5
index|]
decl_stmt|;
name|unsigned
name|int
name|ui
index|[
literal|5
index|]
decl_stmt|;
block|}
name|drm_radeon_clear_rect_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_clear
block|{
name|unsigned
name|int
name|flags
decl_stmt|;
name|unsigned
name|int
name|clear_color
decl_stmt|;
name|unsigned
name|int
name|clear_depth
decl_stmt|;
name|unsigned
name|int
name|color_mask
decl_stmt|;
name|unsigned
name|int
name|depth_mask
decl_stmt|;
comment|/* misnamed field:  should be stencil */
name|drm_radeon_clear_rect_t
modifier|*
name|depth_boxes
decl_stmt|;
block|}
name|drm_radeon_clear_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_vertex
block|{
name|int
name|prim
decl_stmt|;
name|int
name|idx
decl_stmt|;
comment|/* Index of vertex buffer */
name|int
name|count
decl_stmt|;
comment|/* Number of vertices in buffer */
name|int
name|discard
decl_stmt|;
comment|/* Client finished with buffer? */
block|}
name|drm_radeon_vertex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_indices
block|{
name|int
name|prim
decl_stmt|;
name|int
name|idx
decl_stmt|;
name|int
name|start
decl_stmt|;
name|int
name|end
decl_stmt|;
name|int
name|discard
decl_stmt|;
comment|/* Client finished with buffer? */
block|}
name|drm_radeon_indices_t
typedef|;
end_typedef

begin_comment
comment|/* v1.2 - obsoletes drm_radeon_vertex and drm_radeon_indices  *      - allows multiple primitives and state changes in a single ioctl  *      - supports driver change to emit native primitives  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_vertex2
block|{
name|int
name|idx
decl_stmt|;
comment|/* Index of vertex buffer */
name|int
name|discard
decl_stmt|;
comment|/* Client finished with buffer? */
name|int
name|nr_states
decl_stmt|;
name|drm_radeon_state_t
modifier|*
name|state
decl_stmt|;
name|int
name|nr_prims
decl_stmt|;
name|drm_radeon_prim_t
modifier|*
name|prim
decl_stmt|;
block|}
name|drm_radeon_vertex2_t
typedef|;
end_typedef

begin_comment
comment|/* v1.3 - obsoletes drm_radeon_vertex2  *      - allows arbitarily large cliprect list   *      - allows updating of tcl packet, vector and scalar state  *      - allows memory-efficient description of state updates  *      - allows state to be emitted without a primitive   *           (for clears, ctx switches)  *      - allows more than one dma buffer to be referenced per ioctl  *      - supports tcl driver  *      - may be extended in future versions with new cmd types, packets  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_cmd_buffer
block|{
name|int
name|bufsz
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
name|int
name|nbox
decl_stmt|;
name|drm_clip_rect_t
modifier|*
name|boxes
decl_stmt|;
block|}
name|drm_radeon_cmd_buffer_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_tex_image
block|{
name|unsigned
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* Blit coordinates */
name|unsigned
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
specifier|const
name|void
modifier|*
name|data
decl_stmt|;
block|}
name|drm_radeon_tex_image_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_texture
block|{
name|int
name|offset
decl_stmt|;
name|int
name|pitch
decl_stmt|;
name|int
name|format
decl_stmt|;
name|int
name|width
decl_stmt|;
comment|/* Texture image coordinates */
name|int
name|height
decl_stmt|;
name|drm_radeon_tex_image_t
modifier|*
name|image
decl_stmt|;
block|}
name|drm_radeon_texture_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_stipple
block|{
name|unsigned
name|int
modifier|*
name|mask
decl_stmt|;
block|}
name|drm_radeon_stipple_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_indirect
block|{
name|int
name|idx
decl_stmt|;
name|int
name|start
decl_stmt|;
name|int
name|end
decl_stmt|;
name|int
name|discard
decl_stmt|;
block|}
name|drm_radeon_indirect_t
typedef|;
end_typedef

begin_comment
comment|/* 1.3: An ioctl to get parameters that aren't available to the 3d  * client any other way.    */
end_comment

begin_define
define|#
directive|define
name|RADEON_PARAM_AGP_BUFFER_OFFSET
value|1
end_define

begin_comment
comment|/* card offset of 1st agp buffer */
end_comment

begin_define
define|#
directive|define
name|RADEON_PARAM_LAST_FRAME
value|2
end_define

begin_define
define|#
directive|define
name|RADEON_PARAM_LAST_DISPATCH
value|3
end_define

begin_define
define|#
directive|define
name|RADEON_PARAM_LAST_CLEAR
value|4
end_define

begin_comment
comment|/* Added with DRM version 1.6. */
end_comment

begin_define
define|#
directive|define
name|RADEON_PARAM_IRQ_NR
value|5
end_define

begin_define
define|#
directive|define
name|RADEON_PARAM_AGP_BASE
value|6
end_define

begin_comment
comment|/* card offset of agp base */
end_comment

begin_comment
comment|/* Added with DRM version 1.8. */
end_comment

begin_define
define|#
directive|define
name|RADEON_PARAM_REGISTER_HANDLE
value|7
end_define

begin_comment
comment|/* for drmMap() */
end_comment

begin_define
define|#
directive|define
name|RADEON_PARAM_STATUS_HANDLE
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_PARAM_SAREA_HANDLE
value|9
end_define

begin_define
define|#
directive|define
name|RADEON_PARAM_AGP_TEX_HANDLE
value|10
end_define

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_getparam
block|{
name|int
name|param
decl_stmt|;
name|int
modifier|*
name|value
decl_stmt|;
block|}
name|drm_radeon_getparam_t
typedef|;
end_typedef

begin_comment
comment|/* 1.6: Set up a memory manager for regions of shared memory:  */
end_comment

begin_define
define|#
directive|define
name|RADEON_MEM_REGION_AGP
value|1
end_define

begin_define
define|#
directive|define
name|RADEON_MEM_REGION_FB
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_mem_alloc
block|{
name|int
name|region
decl_stmt|;
name|int
name|alignment
decl_stmt|;
name|int
name|size
decl_stmt|;
name|int
modifier|*
name|region_offset
decl_stmt|;
comment|/* offset from start of fb or agp */
block|}
name|drm_radeon_mem_alloc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_mem_free
block|{
name|int
name|region
decl_stmt|;
name|int
name|region_offset
decl_stmt|;
block|}
name|drm_radeon_mem_free_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_mem_init_heap
block|{
name|int
name|region
decl_stmt|;
name|int
name|size
decl_stmt|;
name|int
name|start
decl_stmt|;
block|}
name|drm_radeon_mem_init_heap_t
typedef|;
end_typedef

begin_comment
comment|/* 1.6: Userspace can request& wait on irq's:  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_irq_emit
block|{
name|int
modifier|*
name|irq_seq
decl_stmt|;
block|}
name|drm_radeon_irq_emit_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_irq_wait
block|{
name|int
name|irq_seq
decl_stmt|;
block|}
name|drm_radeon_irq_wait_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

