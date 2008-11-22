begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* r128_drm.h -- Public header for the r128 driver -*- linux-c -*-  * Created: Wed Apr  5 19:24:19 2000 by kevin@precisioninsight.com  */
end_comment

begin_comment
comment|/*-  * Copyright 2000 Precision Insight, Inc., Cedar Park, Texas.  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All rights reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Gareth Hughes<gareth@valinux.com>  *    Kevin E. Martin<martin@valinux.com>  */
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
name|__R128_DRM_H__
end_ifndef

begin_define
define|#
directive|define
name|__R128_DRM_H__
end_define

begin_comment
comment|/* WARNING: If you change any of these defines, make sure to change the  * defines in the X server file (r128_sarea.h)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__R128_SAREA_DEFINES__
end_ifndef

begin_define
define|#
directive|define
name|__R128_SAREA_DEFINES__
end_define

begin_comment
comment|/* What needs to be changed for the current vertex buffer?  */
end_comment

begin_define
define|#
directive|define
name|R128_UPLOAD_CONTEXT
value|0x001
end_define

begin_define
define|#
directive|define
name|R128_UPLOAD_SETUP
value|0x002
end_define

begin_define
define|#
directive|define
name|R128_UPLOAD_TEX0
value|0x004
end_define

begin_define
define|#
directive|define
name|R128_UPLOAD_TEX1
value|0x008
end_define

begin_define
define|#
directive|define
name|R128_UPLOAD_TEX0IMAGES
value|0x010
end_define

begin_define
define|#
directive|define
name|R128_UPLOAD_TEX1IMAGES
value|0x020
end_define

begin_define
define|#
directive|define
name|R128_UPLOAD_CORE
value|0x040
end_define

begin_define
define|#
directive|define
name|R128_UPLOAD_MASKS
value|0x080
end_define

begin_define
define|#
directive|define
name|R128_UPLOAD_WINDOW
value|0x100
end_define

begin_define
define|#
directive|define
name|R128_UPLOAD_CLIPRECTS
value|0x200
end_define

begin_comment
comment|/* handled client-side */
end_comment

begin_define
define|#
directive|define
name|R128_REQUIRE_QUIESCENCE
value|0x400
end_define

begin_define
define|#
directive|define
name|R128_UPLOAD_ALL
value|0x7ff
end_define

begin_define
define|#
directive|define
name|R128_FRONT
value|0x1
end_define

begin_define
define|#
directive|define
name|R128_BACK
value|0x2
end_define

begin_define
define|#
directive|define
name|R128_DEPTH
value|0x4
end_define

begin_comment
comment|/* Primitive types  */
end_comment

begin_define
define|#
directive|define
name|R128_POINTS
value|0x1
end_define

begin_define
define|#
directive|define
name|R128_LINES
value|0x2
end_define

begin_define
define|#
directive|define
name|R128_LINE_STRIP
value|0x3
end_define

begin_define
define|#
directive|define
name|R128_TRIANGLES
value|0x4
end_define

begin_define
define|#
directive|define
name|R128_TRIANGLE_FAN
value|0x5
end_define

begin_define
define|#
directive|define
name|R128_TRIANGLE_STRIP
value|0x6
end_define

begin_comment
comment|/* Vertex/indirect buffer size  */
end_comment

begin_define
define|#
directive|define
name|R128_BUFFER_SIZE
value|16384
end_define

begin_comment
comment|/* Byte offsets for indirect buffer data  */
end_comment

begin_define
define|#
directive|define
name|R128_INDEX_PRIM_OFFSET
value|20
end_define

begin_define
define|#
directive|define
name|R128_HOSTDATA_BLIT_OFFSET
value|32
end_define

begin_comment
comment|/* Keep these small for testing.  */
end_comment

begin_define
define|#
directive|define
name|R128_NR_SAREA_CLIPRECTS
value|12
end_define

begin_comment
comment|/* There are 2 heaps (local/AGP).  Each region within a heap is a  *  minimum of 64k, and there are at most 64 of them per heap.  */
end_comment

begin_define
define|#
directive|define
name|R128_LOCAL_TEX_HEAP
value|0
end_define

begin_define
define|#
directive|define
name|R128_AGP_TEX_HEAP
value|1
end_define

begin_define
define|#
directive|define
name|R128_NR_TEX_HEAPS
value|2
end_define

begin_define
define|#
directive|define
name|R128_NR_TEX_REGIONS
value|64
end_define

begin_define
define|#
directive|define
name|R128_LOG_TEX_GRANULARITY
value|16
end_define

begin_define
define|#
directive|define
name|R128_NR_CONTEXT_REGS
value|12
end_define

begin_define
define|#
directive|define
name|R128_MAX_TEXTURE_LEVELS
value|11
end_define

begin_define
define|#
directive|define
name|R128_MAX_TEXTURE_UNITS
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __R128_SAREA_DEFINES__ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Context state - can be written in one large chunk */
name|unsigned
name|int
name|dst_pitch_offset_c
decl_stmt|;
name|unsigned
name|int
name|dp_gui_master_cntl_c
decl_stmt|;
name|unsigned
name|int
name|sc_top_left_c
decl_stmt|;
name|unsigned
name|int
name|sc_bottom_right_c
decl_stmt|;
name|unsigned
name|int
name|z_offset_c
decl_stmt|;
name|unsigned
name|int
name|z_pitch_c
decl_stmt|;
name|unsigned
name|int
name|z_sten_cntl_c
decl_stmt|;
name|unsigned
name|int
name|tex_cntl_c
decl_stmt|;
name|unsigned
name|int
name|misc_3d_state_cntl_reg
decl_stmt|;
name|unsigned
name|int
name|texture_clr_cmp_clr_c
decl_stmt|;
name|unsigned
name|int
name|texture_clr_cmp_msk_c
decl_stmt|;
name|unsigned
name|int
name|fog_color_c
decl_stmt|;
comment|/* Texture state */
name|unsigned
name|int
name|tex_size_pitch_c
decl_stmt|;
name|unsigned
name|int
name|constant_color_c
decl_stmt|;
comment|/* Setup state */
name|unsigned
name|int
name|pm4_vc_fpu_setup
decl_stmt|;
name|unsigned
name|int
name|setup_cntl
decl_stmt|;
comment|/* Mask state */
name|unsigned
name|int
name|dp_write_mask
decl_stmt|;
name|unsigned
name|int
name|sten_ref_mask_c
decl_stmt|;
name|unsigned
name|int
name|plane_3d_mask_c
decl_stmt|;
comment|/* Window state */
name|unsigned
name|int
name|window_xy_offset
decl_stmt|;
comment|/* Core state */
name|unsigned
name|int
name|scale_3d_cntl
decl_stmt|;
block|}
name|drm_r128_context_regs_t
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
name|tex_cntl
decl_stmt|;
name|unsigned
name|int
name|tex_combine_cntl
decl_stmt|;
name|unsigned
name|int
name|tex_size_pitch
decl_stmt|;
name|unsigned
name|int
name|tex_offset
index|[
name|R128_MAX_TEXTURE_LEVELS
index|]
decl_stmt|;
name|unsigned
name|int
name|tex_border_color
decl_stmt|;
block|}
name|drm_r128_texture_regs_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_r128_sarea
block|{
comment|/* The channel for communication of state information to the kernel 	 * on firing a vertex buffer. 	 */
name|drm_r128_context_regs_t
name|context_state
decl_stmt|;
name|drm_r128_texture_regs_t
name|tex_state
index|[
name|R128_MAX_TEXTURE_UNITS
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
name|R128_NR_SAREA_CLIPRECTS
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
name|drm_tex_region_t
name|tex_list
index|[
name|R128_NR_TEX_HEAPS
index|]
index|[
name|R128_NR_TEX_REGIONS
operator|+
literal|1
index|]
decl_stmt|;
name|unsigned
name|int
name|tex_age
index|[
name|R128_NR_TEX_HEAPS
index|]
decl_stmt|;
name|int
name|ctx_owner
decl_stmt|;
name|int
name|pfAllowPageFlip
decl_stmt|;
comment|/* number of 3d windows (0,1,2 or more) */
name|int
name|pfCurrentPage
decl_stmt|;
comment|/* which buffer is being displayed? */
block|}
name|drm_r128_sarea_t
typedef|;
end_typedef

begin_comment
comment|/* WARNING: If you change any of these defines, make sure to change the  * defines in the Xserver file (xf86drmR128.h)  */
end_comment

begin_comment
comment|/* Rage 128 specific ioctls  * The device specific ioctl range is 0x40 to 0x79.  */
end_comment

begin_define
define|#
directive|define
name|DRM_R128_INIT
value|0x00
end_define

begin_define
define|#
directive|define
name|DRM_R128_CCE_START
value|0x01
end_define

begin_define
define|#
directive|define
name|DRM_R128_CCE_STOP
value|0x02
end_define

begin_define
define|#
directive|define
name|DRM_R128_CCE_RESET
value|0x03
end_define

begin_define
define|#
directive|define
name|DRM_R128_CCE_IDLE
value|0x04
end_define

begin_comment
comment|/* 0x05 not used */
end_comment

begin_define
define|#
directive|define
name|DRM_R128_RESET
value|0x06
end_define

begin_define
define|#
directive|define
name|DRM_R128_SWAP
value|0x07
end_define

begin_define
define|#
directive|define
name|DRM_R128_CLEAR
value|0x08
end_define

begin_define
define|#
directive|define
name|DRM_R128_VERTEX
value|0x09
end_define

begin_define
define|#
directive|define
name|DRM_R128_INDICES
value|0x0a
end_define

begin_define
define|#
directive|define
name|DRM_R128_BLIT
value|0x0b
end_define

begin_define
define|#
directive|define
name|DRM_R128_DEPTH
value|0x0c
end_define

begin_define
define|#
directive|define
name|DRM_R128_STIPPLE
value|0x0d
end_define

begin_comment
comment|/* 0x0e not used */
end_comment

begin_define
define|#
directive|define
name|DRM_R128_INDIRECT
value|0x0f
end_define

begin_define
define|#
directive|define
name|DRM_R128_FULLSCREEN
value|0x10
end_define

begin_define
define|#
directive|define
name|DRM_R128_CLEAR2
value|0x11
end_define

begin_define
define|#
directive|define
name|DRM_R128_GETPARAM
value|0x12
end_define

begin_define
define|#
directive|define
name|DRM_R128_FLIP
value|0x13
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_R128_INIT
value|DRM_IOW( DRM_COMMAND_BASE + DRM_R128_INIT, drm_r128_init_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_R128_CCE_START
value|DRM_IO(  DRM_COMMAND_BASE + DRM_R128_CCE_START)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_R128_CCE_STOP
value|DRM_IOW( DRM_COMMAND_BASE + DRM_R128_CCE_STOP, drm_r128_cce_stop_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_R128_CCE_RESET
value|DRM_IO(  DRM_COMMAND_BASE + DRM_R128_CCE_RESET)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_R128_CCE_IDLE
value|DRM_IO(  DRM_COMMAND_BASE + DRM_R128_CCE_IDLE)
end_define

begin_comment
comment|/* 0x05 not used */
end_comment

begin_define
define|#
directive|define
name|DRM_IOCTL_R128_RESET
value|DRM_IO(  DRM_COMMAND_BASE + DRM_R128_RESET)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_R128_SWAP
value|DRM_IO(  DRM_COMMAND_BASE + DRM_R128_SWAP)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_R128_CLEAR
value|DRM_IOW( DRM_COMMAND_BASE + DRM_R128_CLEAR, drm_r128_clear_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_R128_VERTEX
value|DRM_IOW( DRM_COMMAND_BASE + DRM_R128_VERTEX, drm_r128_vertex_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_R128_INDICES
value|DRM_IOW( DRM_COMMAND_BASE + DRM_R128_INDICES, drm_r128_indices_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_R128_BLIT
value|DRM_IOW( DRM_COMMAND_BASE + DRM_R128_BLIT, drm_r128_blit_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_R128_DEPTH
value|DRM_IOW( DRM_COMMAND_BASE + DRM_R128_DEPTH, drm_r128_depth_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_R128_STIPPLE
value|DRM_IOW( DRM_COMMAND_BASE + DRM_R128_STIPPLE, drm_r128_stipple_t)
end_define

begin_comment
comment|/* 0x0e not used */
end_comment

begin_define
define|#
directive|define
name|DRM_IOCTL_R128_INDIRECT
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_R128_INDIRECT, drm_r128_indirect_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_R128_FULLSCREEN
value|DRM_IOW( DRM_COMMAND_BASE + DRM_R128_FULLSCREEN, drm_r128_fullscreen_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_R128_CLEAR2
value|DRM_IOW( DRM_COMMAND_BASE + DRM_R128_CLEAR2, drm_r128_clear2_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_R128_GETPARAM
value|DRM_IOWR( DRM_COMMAND_BASE + DRM_R128_GETPARAM, drm_r128_getparam_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_R128_FLIP
value|DRM_IO(  DRM_COMMAND_BASE + DRM_R128_FLIP)
end_define

begin_typedef
typedef|typedef
struct|struct
name|drm_r128_init
block|{
enum|enum
block|{
name|R128_INIT_CCE
init|=
literal|0x01
block|,
name|R128_CLEANUP_CCE
init|=
literal|0x02
block|}
name|func
enum|;
if|#
directive|if
name|CONFIG_XFREE86_VERSION
operator|<
name|XFREE86_VERSION
argument_list|(
literal|4
operator|,
literal|1
operator|,
literal|0
operator|,
literal|0
argument_list|)
name|int
name|sarea_priv_offset
decl_stmt|;
else|#
directive|else
name|unsigned
name|long
name|sarea_priv_offset
decl_stmt|;
endif|#
directive|endif
name|int
name|is_pci
decl_stmt|;
name|int
name|cce_mode
decl_stmt|;
name|int
name|cce_secure
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
name|int
name|span_offset
decl_stmt|;
if|#
directive|if
name|CONFIG_XFREE86_VERSION
operator|<
name|XFREE86_VERSION
argument_list|(
literal|4
operator|,
literal|1
operator|,
literal|0
operator|,
literal|0
argument_list|)
name|unsigned
name|int
name|fb_offset
decl_stmt|;
name|unsigned
name|int
name|mmio_offset
decl_stmt|;
name|unsigned
name|int
name|ring_offset
decl_stmt|;
name|unsigned
name|int
name|ring_rptr_offset
decl_stmt|;
name|unsigned
name|int
name|buffers_offset
decl_stmt|;
name|unsigned
name|int
name|agp_textures_offset
decl_stmt|;
else|#
directive|else
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
endif|#
directive|endif
block|}
name|drm_r128_init_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_r128_cce_stop
block|{
name|int
name|flush
decl_stmt|;
name|int
name|idle
decl_stmt|;
block|}
name|drm_r128_cce_stop_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_r128_clear
block|{
name|unsigned
name|int
name|flags
decl_stmt|;
if|#
directive|if
name|CONFIG_XFREE86_VERSION
operator|<
name|XFREE86_VERSION
argument_list|(
literal|4
operator|,
literal|1
operator|,
literal|0
operator|,
literal|0
argument_list|)
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|w
decl_stmt|,
name|h
decl_stmt|;
endif|#
directive|endif
name|unsigned
name|int
name|clear_color
decl_stmt|;
name|unsigned
name|int
name|clear_depth
decl_stmt|;
if|#
directive|if
name|CONFIG_XFREE86_VERSION
operator|>=
name|XFREE86_VERSION
argument_list|(
literal|4
operator|,
literal|1
operator|,
literal|0
operator|,
literal|0
argument_list|)
name|unsigned
name|int
name|color_mask
decl_stmt|;
name|unsigned
name|int
name|depth_mask
decl_stmt|;
endif|#
directive|endif
block|}
name|drm_r128_clear_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_r128_vertex
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
name|drm_r128_vertex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_r128_indices
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
name|drm_r128_indices_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_r128_blit
block|{
name|int
name|idx
decl_stmt|;
name|int
name|pitch
decl_stmt|;
name|int
name|offset
decl_stmt|;
name|int
name|format
decl_stmt|;
name|unsigned
name|short
name|x
decl_stmt|,
name|y
decl_stmt|;
name|unsigned
name|short
name|width
decl_stmt|,
name|height
decl_stmt|;
block|}
name|drm_r128_blit_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_r128_depth
block|{
enum|enum
block|{
name|R128_WRITE_SPAN
init|=
literal|0x01
block|,
name|R128_WRITE_PIXELS
init|=
literal|0x02
block|,
name|R128_READ_SPAN
init|=
literal|0x03
block|,
name|R128_READ_PIXELS
init|=
literal|0x04
block|}
name|func
enum|;
name|int
name|n
decl_stmt|;
name|int
name|__user
modifier|*
name|x
decl_stmt|;
name|int
name|__user
modifier|*
name|y
decl_stmt|;
name|unsigned
name|int
name|__user
modifier|*
name|buffer
decl_stmt|;
name|unsigned
name|char
name|__user
modifier|*
name|mask
decl_stmt|;
block|}
name|drm_r128_depth_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_r128_stipple
block|{
name|unsigned
name|int
name|__user
modifier|*
name|mask
decl_stmt|;
block|}
name|drm_r128_stipple_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_r128_indirect
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
name|drm_r128_indirect_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_r128_fullscreen
block|{
enum|enum
block|{
name|R128_INIT_FULLSCREEN
init|=
literal|0x01
block|,
name|R128_CLEANUP_FULLSCREEN
init|=
literal|0x02
block|}
name|func
enum|;
block|}
name|drm_r128_fullscreen_t
typedef|;
end_typedef

begin_comment
comment|/* 2.3: An ioctl to get parameters that aren't available to the 3d  * client any other way.  */
end_comment

begin_define
define|#
directive|define
name|R128_PARAM_IRQ_NR
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|drm_r128_getparam
block|{
name|int
name|param
decl_stmt|;
name|void
name|__user
modifier|*
name|value
decl_stmt|;
block|}
name|drm_r128_getparam_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

