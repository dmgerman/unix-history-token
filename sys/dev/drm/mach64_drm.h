begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mach64_drm.h -- Public header for the mach64 driver -*- linux-c -*-  * Created: Thu Nov 30 20:04:32 2000 by gareth@valinux.com  */
end_comment

begin_comment
comment|/*-  * Copyright 2000 Gareth Hughes  * Copyright 2002 Frank C. Earl  * Copyright 2002-2003 Leif Delgass  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT OWNER(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER  * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Gareth Hughes<gareth@valinux.com>  *    Frank C. Earl<fearl@airmail.net>  *    Leif Delgass<ldelgass@retinalburn.net>  */
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
name|__MACH64_DRM_H__
end_ifndef

begin_define
define|#
directive|define
name|__MACH64_DRM_H__
end_define

begin_comment
comment|/* WARNING: If you change any of these defines, make sure to change the  * defines in the Xserver file (mach64_sarea.h)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MACH64_SAREA_DEFINES__
end_ifndef

begin_define
define|#
directive|define
name|__MACH64_SAREA_DEFINES__
end_define

begin_comment
comment|/* What needs to be changed for the current vertex buffer?  * GH: We're going to be pedantic about this.  We want the card to do as  * little as possible, so let's avoid having it fetch a whole bunch of  * register values that don't change all that often, if at all.  */
end_comment

begin_define
define|#
directive|define
name|MACH64_UPLOAD_DST_OFF_PITCH
value|0x0001
end_define

begin_define
define|#
directive|define
name|MACH64_UPLOAD_Z_OFF_PITCH
value|0x0002
end_define

begin_define
define|#
directive|define
name|MACH64_UPLOAD_Z_ALPHA_CNTL
value|0x0004
end_define

begin_define
define|#
directive|define
name|MACH64_UPLOAD_SCALE_3D_CNTL
value|0x0008
end_define

begin_define
define|#
directive|define
name|MACH64_UPLOAD_DP_FOG_CLR
value|0x0010
end_define

begin_define
define|#
directive|define
name|MACH64_UPLOAD_DP_WRITE_MASK
value|0x0020
end_define

begin_define
define|#
directive|define
name|MACH64_UPLOAD_DP_PIX_WIDTH
value|0x0040
end_define

begin_define
define|#
directive|define
name|MACH64_UPLOAD_SETUP_CNTL
value|0x0080
end_define

begin_define
define|#
directive|define
name|MACH64_UPLOAD_MISC
value|0x0100
end_define

begin_define
define|#
directive|define
name|MACH64_UPLOAD_TEXTURE
value|0x0200
end_define

begin_define
define|#
directive|define
name|MACH64_UPLOAD_TEX0IMAGE
value|0x0400
end_define

begin_define
define|#
directive|define
name|MACH64_UPLOAD_TEX1IMAGE
value|0x0800
end_define

begin_define
define|#
directive|define
name|MACH64_UPLOAD_CLIPRECTS
value|0x1000
end_define

begin_comment
comment|/* handled client-side */
end_comment

begin_define
define|#
directive|define
name|MACH64_UPLOAD_CONTEXT
value|0x00ff
end_define

begin_define
define|#
directive|define
name|MACH64_UPLOAD_ALL
value|0x1fff
end_define

begin_comment
comment|/* DMA buffer size  */
end_comment

begin_define
define|#
directive|define
name|MACH64_BUFFER_SIZE
value|16384
end_define

begin_comment
comment|/* Max number of swaps allowed on the ring  * before the client must wait  */
end_comment

begin_define
define|#
directive|define
name|MACH64_MAX_QUEUED_FRAMES
value|3U
end_define

begin_comment
comment|/* Byte offsets for host blit buffer data  */
end_comment

begin_define
define|#
directive|define
name|MACH64_HOSTDATA_BLIT_OFFSET
value|104
end_define

begin_comment
comment|/* Keep these small for testing.  */
end_comment

begin_define
define|#
directive|define
name|MACH64_NR_SAREA_CLIPRECTS
value|8
end_define

begin_define
define|#
directive|define
name|MACH64_CARD_HEAP
value|0
end_define

begin_define
define|#
directive|define
name|MACH64_AGP_HEAP
value|1
end_define

begin_define
define|#
directive|define
name|MACH64_NR_TEX_HEAPS
value|2
end_define

begin_define
define|#
directive|define
name|MACH64_NR_TEX_REGIONS
value|64
end_define

begin_define
define|#
directive|define
name|MACH64_LOG_TEX_GRANULARITY
value|16
end_define

begin_define
define|#
directive|define
name|MACH64_TEX_MAXLEVELS
value|1
end_define

begin_define
define|#
directive|define
name|MACH64_NR_CONTEXT_REGS
value|15
end_define

begin_define
define|#
directive|define
name|MACH64_NR_TEXTURE_REGS
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MACH64_SAREA_DEFINES__ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|dst_off_pitch
decl_stmt|;
name|unsigned
name|int
name|z_off_pitch
decl_stmt|;
name|unsigned
name|int
name|z_cntl
decl_stmt|;
name|unsigned
name|int
name|alpha_tst_cntl
decl_stmt|;
name|unsigned
name|int
name|scale_3d_cntl
decl_stmt|;
name|unsigned
name|int
name|sc_left_right
decl_stmt|;
name|unsigned
name|int
name|sc_top_bottom
decl_stmt|;
name|unsigned
name|int
name|dp_fog_clr
decl_stmt|;
name|unsigned
name|int
name|dp_write_mask
decl_stmt|;
name|unsigned
name|int
name|dp_pix_width
decl_stmt|;
name|unsigned
name|int
name|dp_mix
decl_stmt|;
name|unsigned
name|int
name|dp_src
decl_stmt|;
name|unsigned
name|int
name|clr_cmp_cntl
decl_stmt|;
name|unsigned
name|int
name|gui_traj_cntl
decl_stmt|;
name|unsigned
name|int
name|setup_cntl
decl_stmt|;
name|unsigned
name|int
name|tex_size_pitch
decl_stmt|;
name|unsigned
name|int
name|tex_cntl
decl_stmt|;
name|unsigned
name|int
name|secondary_tex_off
decl_stmt|;
name|unsigned
name|int
name|tex_offset
decl_stmt|;
block|}
name|drm_mach64_context_regs_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_mach64_sarea
block|{
comment|/* The channel for communication of state information to the kernel 	 * on firing a vertex dma buffer. 	 */
name|drm_mach64_context_regs_t
name|context_state
decl_stmt|;
name|unsigned
name|int
name|dirty
decl_stmt|;
name|unsigned
name|int
name|vertsize
decl_stmt|;
comment|/* The current cliprects, or a subset thereof. 	 */
name|drm_clip_rect_t
name|boxes
index|[
name|MACH64_NR_SAREA_CLIPRECTS
index|]
decl_stmt|;
name|unsigned
name|int
name|nbox
decl_stmt|;
comment|/* Counters for client-side throttling of rendering clients. 	 */
name|unsigned
name|int
name|frames_queued
decl_stmt|;
comment|/* Texture memory LRU. 	 */
name|drm_tex_region_t
name|tex_list
index|[
name|MACH64_NR_TEX_HEAPS
index|]
index|[
name|MACH64_NR_TEX_REGIONS
operator|+
literal|1
index|]
decl_stmt|;
name|unsigned
name|int
name|tex_age
index|[
name|MACH64_NR_TEX_HEAPS
index|]
decl_stmt|;
name|int
name|ctx_owner
decl_stmt|;
block|}
name|drm_mach64_sarea_t
typedef|;
end_typedef

begin_comment
comment|/* WARNING: If you change any of these defines, make sure to change the  * defines in the Xserver file (mach64_common.h)  */
end_comment

begin_comment
comment|/* Mach64 specific ioctls  * The device specific ioctl range is 0x40 to 0x79.  */
end_comment

begin_define
define|#
directive|define
name|DRM_MACH64_INIT
value|0x00
end_define

begin_define
define|#
directive|define
name|DRM_MACH64_IDLE
value|0x01
end_define

begin_define
define|#
directive|define
name|DRM_MACH64_RESET
value|0x02
end_define

begin_define
define|#
directive|define
name|DRM_MACH64_SWAP
value|0x03
end_define

begin_define
define|#
directive|define
name|DRM_MACH64_CLEAR
value|0x04
end_define

begin_define
define|#
directive|define
name|DRM_MACH64_VERTEX
value|0x05
end_define

begin_define
define|#
directive|define
name|DRM_MACH64_BLIT
value|0x06
end_define

begin_define
define|#
directive|define
name|DRM_MACH64_FLUSH
value|0x07
end_define

begin_define
define|#
directive|define
name|DRM_MACH64_GETPARAM
value|0x08
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MACH64_INIT
value|DRM_IOW( DRM_COMMAND_BASE + DRM_MACH64_INIT, drm_mach64_init_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MACH64_IDLE
value|DRM_IO(  DRM_COMMAND_BASE + DRM_MACH64_IDLE )
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MACH64_RESET
value|DRM_IO(  DRM_COMMAND_BASE + DRM_MACH64_RESET )
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MACH64_SWAP
value|DRM_IO(  DRM_COMMAND_BASE + DRM_MACH64_SWAP )
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MACH64_CLEAR
value|DRM_IOW( DRM_COMMAND_BASE + DRM_MACH64_CLEAR, drm_mach64_clear_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MACH64_VERTEX
value|DRM_IOW( DRM_COMMAND_BASE + DRM_MACH64_VERTEX, drm_mach64_vertex_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MACH64_BLIT
value|DRM_IOW( DRM_COMMAND_BASE + DRM_MACH64_BLIT, drm_mach64_blit_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MACH64_FLUSH
value|DRM_IO(  DRM_COMMAND_BASE + DRM_MACH64_FLUSH )
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MACH64_GETPARAM
value|DRM_IOWR( DRM_COMMAND_BASE + DRM_MACH64_GETPARAM, drm_mach64_getparam_t)
end_define

begin_comment
comment|/* Buffer flags for clears  */
end_comment

begin_define
define|#
directive|define
name|MACH64_FRONT
value|0x1
end_define

begin_define
define|#
directive|define
name|MACH64_BACK
value|0x2
end_define

begin_define
define|#
directive|define
name|MACH64_DEPTH
value|0x4
end_define

begin_comment
comment|/* Primitive types for vertex buffers  */
end_comment

begin_define
define|#
directive|define
name|MACH64_PRIM_POINTS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MACH64_PRIM_LINES
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MACH64_PRIM_LINE_LOOP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MACH64_PRIM_LINE_STRIP
value|0x00000003
end_define

begin_define
define|#
directive|define
name|MACH64_PRIM_TRIANGLES
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MACH64_PRIM_TRIANGLE_STRIP
value|0x00000005
end_define

begin_define
define|#
directive|define
name|MACH64_PRIM_TRIANGLE_FAN
value|0x00000006
end_define

begin_define
define|#
directive|define
name|MACH64_PRIM_QUADS
value|0x00000007
end_define

begin_define
define|#
directive|define
name|MACH64_PRIM_QUAD_STRIP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MACH64_PRIM_POLYGON
value|0x00000009
end_define

begin_typedef
typedef|typedef
enum|enum
name|_drm_mach64_dma_mode_t
block|{
name|MACH64_MODE_DMA_ASYNC
block|,
name|MACH64_MODE_DMA_SYNC
block|,
name|MACH64_MODE_MMIO
block|}
name|drm_mach64_dma_mode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_mach64_init
block|{
enum|enum
block|{
name|DRM_MACH64_INIT_DMA
init|=
literal|0x01
block|,
name|DRM_MACH64_CLEANUP_DMA
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
name|drm_mach64_dma_mode_t
name|dma_mode
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
name|buffers_offset
decl_stmt|;
name|unsigned
name|long
name|agp_textures_offset
decl_stmt|;
block|}
name|drm_mach64_init_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_mach64_clear
block|{
name|unsigned
name|int
name|flags
decl_stmt|;
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|w
decl_stmt|,
name|h
decl_stmt|;
name|unsigned
name|int
name|clear_color
decl_stmt|;
name|unsigned
name|int
name|clear_depth
decl_stmt|;
block|}
name|drm_mach64_clear_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_mach64_vertex
block|{
name|int
name|prim
decl_stmt|;
name|void
modifier|*
name|buf
decl_stmt|;
comment|/* Address of vertex buffer */
name|unsigned
name|long
name|used
decl_stmt|;
comment|/* Number of bytes in buffer */
name|int
name|discard
decl_stmt|;
comment|/* Client finished with buffer? */
block|}
name|drm_mach64_vertex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_mach64_blit
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
name|drm_mach64_blit_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_mach64_getparam
block|{
enum|enum
block|{
name|MACH64_PARAM_FRAMES_QUEUED
init|=
literal|0x01
block|,
name|MACH64_PARAM_IRQ_NR
init|=
literal|0x02
block|}
name|param
enum|;
name|void
modifier|*
name|value
decl_stmt|;
block|}
name|drm_mach64_getparam_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

