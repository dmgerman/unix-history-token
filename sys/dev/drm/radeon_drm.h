begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* radeon_drm.h -- Public header for the radeon driver -*- linux-c -*-  *  * Copyright 2000 Precision Insight, Inc., Cedar Park, Texas.  * Copyright 2000 VA Linux Systems, Inc., Fremont, California.  * All rights reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Kevin E. Martin<martin@valinux.com>  *    Gareth Hughes<gareth@valinux.com>  *  * $FreeBSD$  */
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
comment|/* What needs to be changed for the current vertex buffer?  */
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
name|RADEON_UPLOAD_ALL
value|0x0001ffff
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
name|RADEON_HOSTDATA_BLIT_OFFSET
value|32
end_define

begin_define
define|#
directive|define
name|RADEON_SCRATCH_REG_OFFSET
value|32
end_define

begin_comment
comment|/* Keep these small for testing  */
end_comment

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
value|11
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
ifdef|#
directive|ifdef
name|TCL_ENABLE
comment|/* TCL state */
name|radeon_color_regs_t
name|se_tcl_material_emmissive
decl_stmt|;
comment|/* 0x2210 */
name|radeon_color_regs_t
name|se_tcl_material_ambient
decl_stmt|;
name|radeon_color_regs_t
name|se_tcl_material_diffuse
decl_stmt|;
name|radeon_color_regs_t
name|se_tcl_material_specular
decl_stmt|;
name|unsigned
name|int
name|se_tcl_shininess
decl_stmt|;
name|unsigned
name|int
name|se_tcl_output_vtx_fmt
decl_stmt|;
name|unsigned
name|int
name|se_tcl_output_vtx_sel
decl_stmt|;
name|unsigned
name|int
name|se_tcl_matrix_select_0
decl_stmt|;
name|unsigned
name|int
name|se_tcl_matrix_select_1
decl_stmt|;
name|unsigned
name|int
name|se_tcl_ucp_vert_blend_ctl
decl_stmt|;
name|unsigned
name|int
name|se_tcl_texture_proc_ctl
decl_stmt|;
name|unsigned
name|int
name|se_tcl_light_model_ctl
decl_stmt|;
name|unsigned
name|int
name|se_tcl_per_light_ctl
index|[
literal|4
index|]
decl_stmt|;
endif|#
directive|endif
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
ifdef|#
directive|ifdef
name|CUBIC_ENABLE
name|unsigned
name|int
name|pp_cubic_faces
decl_stmt|;
name|unsigned
name|int
name|pp_cubic_offset
index|[
literal|5
index|]
decl_stmt|;
endif|#
directive|endif
block|}
name|drm_radeon_texture_regs_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|next
decl_stmt|,
name|prev
decl_stmt|;
name|unsigned
name|char
name|in_use
decl_stmt|;
name|int
name|age
decl_stmt|;
block|}
name|drm_radeon_tex_region_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* The channel for communication of state information to the kernel 	 * on firing a vertex buffer. 	 */
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
name|drm_radeon_tex_region_t
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
name|int
name|tex_age
index|[
name|RADEON_NR_TEX_HEAPS
index|]
decl_stmt|;
name|int
name|ctx_owner
decl_stmt|;
block|}
name|drm_radeon_sarea_t
typedef|;
end_typedef

begin_comment
comment|/* WARNING: If you change any of these defines, make sure to change the  * defines in the Xserver file (xf86drmRadeon.h)  */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

end_unit

