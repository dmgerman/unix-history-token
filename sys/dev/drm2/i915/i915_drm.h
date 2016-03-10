begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2003 Tungsten Graphics, Inc., Cedar Park, Texas.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the  * "Software"), to deal in the Software without restriction, including  * without limitation the rights to use, copy, modify, merge, publish,  * distribute, sub license, and/or sell copies of the Software, and to  * permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *  * The above copyright notice and this permission notice (including the  * next paragraph) shall be included in all copies or substantial portions  * of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.  * IN NO EVENT SHALL TUNGSTEN GRAPHICS AND/OR ITS SUPPLIERS BE LIABLE FOR  * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE  * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UAPI_I915_DRM_H_
end_ifndef

begin_define
define|#
directive|define
name|_UAPI_I915_DRM_H_
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

begin_include
include|#
directive|include
file|<dev/drm2/drm.h>
end_include

begin_comment
comment|/* Please note that modifications to all structs defined here are  * subject to backwards-compatibility constraints.  */
end_comment

begin_comment
comment|/* Each region is a minimum of 16k, and there are at most 255 of them.  */
end_comment

begin_define
define|#
directive|define
name|I915_NR_TEX_REGIONS
value|255
end_define

begin_comment
comment|/* table size 2k - maximum due to use 				 * of chars for next/prev indices */
end_comment

begin_define
define|#
directive|define
name|I915_LOG_MIN_TEX_REGION_SIZE
value|14
end_define

begin_typedef
typedef|typedef
struct|struct
name|_drm_i915_init
block|{
enum|enum
block|{
name|I915_INIT_DMA
init|=
literal|0x01
block|,
name|I915_CLEANUP_DMA
init|=
literal|0x02
block|,
name|I915_RESUME_DMA
init|=
literal|0x03
block|}
name|func
enum|;
name|unsigned
name|int
name|mmio_offset
decl_stmt|;
name|int
name|sarea_priv_offset
decl_stmt|;
name|unsigned
name|int
name|ring_start
decl_stmt|;
name|unsigned
name|int
name|ring_end
decl_stmt|;
name|unsigned
name|int
name|ring_size
decl_stmt|;
name|unsigned
name|int
name|front_offset
decl_stmt|;
name|unsigned
name|int
name|back_offset
decl_stmt|;
name|unsigned
name|int
name|depth_offset
decl_stmt|;
name|unsigned
name|int
name|w
decl_stmt|;
name|unsigned
name|int
name|h
decl_stmt|;
name|unsigned
name|int
name|pitch
decl_stmt|;
name|unsigned
name|int
name|pitch_bits
decl_stmt|;
name|unsigned
name|int
name|back_pitch
decl_stmt|;
name|unsigned
name|int
name|depth_pitch
decl_stmt|;
name|unsigned
name|int
name|cpp
decl_stmt|;
name|unsigned
name|int
name|chipset
decl_stmt|;
block|}
name|drm_i915_init_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_drm_i915_sarea
block|{
name|struct
name|drm_tex_region
name|texList
index|[
name|I915_NR_TEX_REGIONS
operator|+
literal|1
index|]
decl_stmt|;
name|int
name|last_upload
decl_stmt|;
comment|/* last time texture was uploaded */
name|int
name|last_enqueue
decl_stmt|;
comment|/* last time a buffer was enqueued */
name|int
name|last_dispatch
decl_stmt|;
comment|/* age of the most recently dispatched buffer */
name|int
name|ctxOwner
decl_stmt|;
comment|/* last context to upload state */
name|int
name|texAge
decl_stmt|;
name|int
name|pf_enabled
decl_stmt|;
comment|/* is pageflipping allowed? */
name|int
name|pf_active
decl_stmt|;
name|int
name|pf_current_page
decl_stmt|;
comment|/* which buffer is being displayed? */
name|int
name|perf_boxes
decl_stmt|;
comment|/* performance boxes to be displayed */
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* screen size in pixels */
name|drm_handle_t
name|front_handle
decl_stmt|;
name|int
name|front_offset
decl_stmt|;
name|int
name|front_size
decl_stmt|;
name|drm_handle_t
name|back_handle
decl_stmt|;
name|int
name|back_offset
decl_stmt|;
name|int
name|back_size
decl_stmt|;
name|drm_handle_t
name|depth_handle
decl_stmt|;
name|int
name|depth_offset
decl_stmt|;
name|int
name|depth_size
decl_stmt|;
name|drm_handle_t
name|tex_handle
decl_stmt|;
name|int
name|tex_offset
decl_stmt|;
name|int
name|tex_size
decl_stmt|;
name|int
name|log_tex_granularity
decl_stmt|;
name|int
name|pitch
decl_stmt|;
name|int
name|rotation
decl_stmt|;
comment|/* 0, 90, 180 or 270 */
name|int
name|rotated_offset
decl_stmt|;
name|int
name|rotated_size
decl_stmt|;
name|int
name|rotated_pitch
decl_stmt|;
name|int
name|virtualX
decl_stmt|,
name|virtualY
decl_stmt|;
name|unsigned
name|int
name|front_tiled
decl_stmt|;
name|unsigned
name|int
name|back_tiled
decl_stmt|;
name|unsigned
name|int
name|depth_tiled
decl_stmt|;
name|unsigned
name|int
name|rotated_tiled
decl_stmt|;
name|unsigned
name|int
name|rotated2_tiled
decl_stmt|;
name|int
name|pipeA_x
decl_stmt|;
name|int
name|pipeA_y
decl_stmt|;
name|int
name|pipeA_w
decl_stmt|;
name|int
name|pipeA_h
decl_stmt|;
name|int
name|pipeB_x
decl_stmt|;
name|int
name|pipeB_y
decl_stmt|;
name|int
name|pipeB_w
decl_stmt|;
name|int
name|pipeB_h
decl_stmt|;
comment|/* fill out some space for old userspace triple buffer */
name|drm_handle_t
name|unused_handle
decl_stmt|;
name|__u32
name|unused1
decl_stmt|,
name|unused2
decl_stmt|,
name|unused3
decl_stmt|;
comment|/* buffer object handles for static buffers. May change 	 * over the lifetime of the client. 	 */
name|__u32
name|front_bo_handle
decl_stmt|;
name|__u32
name|back_bo_handle
decl_stmt|;
name|__u32
name|unused_bo_handle
decl_stmt|;
name|__u32
name|depth_bo_handle
decl_stmt|;
block|}
name|drm_i915_sarea_t
typedef|;
end_typedef

begin_comment
comment|/* due to userspace building against these headers we need some compat here */
end_comment

begin_define
define|#
directive|define
name|planeA_x
value|pipeA_x
end_define

begin_define
define|#
directive|define
name|planeA_y
value|pipeA_y
end_define

begin_define
define|#
directive|define
name|planeA_w
value|pipeA_w
end_define

begin_define
define|#
directive|define
name|planeA_h
value|pipeA_h
end_define

begin_define
define|#
directive|define
name|planeB_x
value|pipeB_x
end_define

begin_define
define|#
directive|define
name|planeB_y
value|pipeB_y
end_define

begin_define
define|#
directive|define
name|planeB_w
value|pipeB_w
end_define

begin_define
define|#
directive|define
name|planeB_h
value|pipeB_h
end_define

begin_comment
comment|/* Flags for perf_boxes  */
end_comment

begin_define
define|#
directive|define
name|I915_BOX_RING_EMPTY
value|0x1
end_define

begin_define
define|#
directive|define
name|I915_BOX_FLIP
value|0x2
end_define

begin_define
define|#
directive|define
name|I915_BOX_WAIT
value|0x4
end_define

begin_define
define|#
directive|define
name|I915_BOX_TEXTURE_LOAD
value|0x8
end_define

begin_define
define|#
directive|define
name|I915_BOX_LOST_CONTEXT
value|0x10
end_define

begin_comment
comment|/* I915 specific ioctls  * The device specific ioctl range is 0x40 to 0x79.  */
end_comment

begin_define
define|#
directive|define
name|DRM_I915_INIT
value|0x00
end_define

begin_define
define|#
directive|define
name|DRM_I915_FLUSH
value|0x01
end_define

begin_define
define|#
directive|define
name|DRM_I915_FLIP
value|0x02
end_define

begin_define
define|#
directive|define
name|DRM_I915_BATCHBUFFER
value|0x03
end_define

begin_define
define|#
directive|define
name|DRM_I915_IRQ_EMIT
value|0x04
end_define

begin_define
define|#
directive|define
name|DRM_I915_IRQ_WAIT
value|0x05
end_define

begin_define
define|#
directive|define
name|DRM_I915_GETPARAM
value|0x06
end_define

begin_define
define|#
directive|define
name|DRM_I915_SETPARAM
value|0x07
end_define

begin_define
define|#
directive|define
name|DRM_I915_ALLOC
value|0x08
end_define

begin_define
define|#
directive|define
name|DRM_I915_FREE
value|0x09
end_define

begin_define
define|#
directive|define
name|DRM_I915_INIT_HEAP
value|0x0a
end_define

begin_define
define|#
directive|define
name|DRM_I915_CMDBUFFER
value|0x0b
end_define

begin_define
define|#
directive|define
name|DRM_I915_DESTROY_HEAP
value|0x0c
end_define

begin_define
define|#
directive|define
name|DRM_I915_SET_VBLANK_PIPE
value|0x0d
end_define

begin_define
define|#
directive|define
name|DRM_I915_GET_VBLANK_PIPE
value|0x0e
end_define

begin_define
define|#
directive|define
name|DRM_I915_VBLANK_SWAP
value|0x0f
end_define

begin_define
define|#
directive|define
name|DRM_I915_HWS_ADDR
value|0x11
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_INIT
value|0x13
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_EXECBUFFER
value|0x14
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_PIN
value|0x15
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_UNPIN
value|0x16
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_BUSY
value|0x17
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_THROTTLE
value|0x18
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_ENTERVT
value|0x19
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_LEAVEVT
value|0x1a
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_CREATE
value|0x1b
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_PREAD
value|0x1c
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_PWRITE
value|0x1d
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_MMAP
value|0x1e
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_SET_DOMAIN
value|0x1f
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_SW_FINISH
value|0x20
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_SET_TILING
value|0x21
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_GET_TILING
value|0x22
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_GET_APERTURE
value|0x23
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_MMAP_GTT
value|0x24
end_define

begin_define
define|#
directive|define
name|DRM_I915_GET_PIPE_FROM_CRTC_ID
value|0x25
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_MADVISE
value|0x26
end_define

begin_define
define|#
directive|define
name|DRM_I915_OVERLAY_PUT_IMAGE
value|0x27
end_define

begin_define
define|#
directive|define
name|DRM_I915_OVERLAY_ATTRS
value|0x28
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_EXECBUFFER2
value|0x29
end_define

begin_define
define|#
directive|define
name|DRM_I915_GET_SPRITE_COLORKEY
value|0x2a
end_define

begin_define
define|#
directive|define
name|DRM_I915_SET_SPRITE_COLORKEY
value|0x2b
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_WAIT
value|0x2c
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_CONTEXT_CREATE
value|0x2d
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_CONTEXT_DESTROY
value|0x2e
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_SET_CACHING
value|0x2f
end_define

begin_define
define|#
directive|define
name|DRM_I915_GEM_GET_CACHING
value|0x30
end_define

begin_define
define|#
directive|define
name|DRM_I915_REG_READ
value|0x31
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_INIT
value|DRM_IOW( DRM_COMMAND_BASE + DRM_I915_INIT, drm_i915_init_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_FLUSH
value|DRM_IO ( DRM_COMMAND_BASE + DRM_I915_FLUSH)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_FLIP
value|DRM_IO ( DRM_COMMAND_BASE + DRM_I915_FLIP)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_BATCHBUFFER
value|DRM_IOW( DRM_COMMAND_BASE + DRM_I915_BATCHBUFFER, drm_i915_batchbuffer_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_IRQ_EMIT
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_IRQ_EMIT, drm_i915_irq_emit_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_IRQ_WAIT
value|DRM_IOW( DRM_COMMAND_BASE + DRM_I915_IRQ_WAIT, drm_i915_irq_wait_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GETPARAM
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GETPARAM, drm_i915_getparam_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_SETPARAM
value|DRM_IOW( DRM_COMMAND_BASE + DRM_I915_SETPARAM, drm_i915_setparam_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_ALLOC
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_ALLOC, drm_i915_mem_alloc_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_FREE
value|DRM_IOW( DRM_COMMAND_BASE + DRM_I915_FREE, drm_i915_mem_free_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_INIT_HEAP
value|DRM_IOW( DRM_COMMAND_BASE + DRM_I915_INIT_HEAP, drm_i915_mem_init_heap_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_CMDBUFFER
value|DRM_IOW( DRM_COMMAND_BASE + DRM_I915_CMDBUFFER, drm_i915_cmdbuffer_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_DESTROY_HEAP
value|DRM_IOW( DRM_COMMAND_BASE + DRM_I915_DESTROY_HEAP, drm_i915_mem_destroy_heap_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_SET_VBLANK_PIPE
value|DRM_IOW( DRM_COMMAND_BASE + DRM_I915_SET_VBLANK_PIPE, drm_i915_vblank_pipe_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GET_VBLANK_PIPE
value|DRM_IOR( DRM_COMMAND_BASE + DRM_I915_GET_VBLANK_PIPE, drm_i915_vblank_pipe_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_VBLANK_SWAP
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_VBLANK_SWAP, drm_i915_vblank_swap_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_HWS_ADDR
value|DRM_IOW(DRM_COMMAND_BASE + DRM_I915_HWS_ADDR, struct drm_i915_gem_init)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_INIT
value|DRM_IOW(DRM_COMMAND_BASE + DRM_I915_GEM_INIT, struct drm_i915_gem_init)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_EXECBUFFER
value|DRM_IOW(DRM_COMMAND_BASE + DRM_I915_GEM_EXECBUFFER, struct drm_i915_gem_execbuffer)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_EXECBUFFER2
value|DRM_IOW(DRM_COMMAND_BASE + DRM_I915_GEM_EXECBUFFER2, struct drm_i915_gem_execbuffer2)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_PIN
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_PIN, struct drm_i915_gem_pin)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_UNPIN
value|DRM_IOW(DRM_COMMAND_BASE + DRM_I915_GEM_UNPIN, struct drm_i915_gem_unpin)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_BUSY
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_BUSY, struct drm_i915_gem_busy)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_SET_CACHING
value|DRM_IOW(DRM_COMMAND_BASE + DRM_I915_GEM_SET_CACHING, struct drm_i915_gem_caching)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_GET_CACHING
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_GET_CACHING, struct drm_i915_gem_caching)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_THROTTLE
value|DRM_IO ( DRM_COMMAND_BASE + DRM_I915_GEM_THROTTLE)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_ENTERVT
value|DRM_IO(DRM_COMMAND_BASE + DRM_I915_GEM_ENTERVT)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_LEAVEVT
value|DRM_IO(DRM_COMMAND_BASE + DRM_I915_GEM_LEAVEVT)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_CREATE
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_CREATE, struct drm_i915_gem_create)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_PREAD
value|DRM_IOW (DRM_COMMAND_BASE + DRM_I915_GEM_PREAD, struct drm_i915_gem_pread)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_PWRITE
value|DRM_IOW (DRM_COMMAND_BASE + DRM_I915_GEM_PWRITE, struct drm_i915_gem_pwrite)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_MMAP
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_MMAP, struct drm_i915_gem_mmap)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_MMAP_GTT
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_MMAP_GTT, struct drm_i915_gem_mmap_gtt)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_SET_DOMAIN
value|DRM_IOW (DRM_COMMAND_BASE + DRM_I915_GEM_SET_DOMAIN, struct drm_i915_gem_set_domain)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_SW_FINISH
value|DRM_IOW (DRM_COMMAND_BASE + DRM_I915_GEM_SW_FINISH, struct drm_i915_gem_sw_finish)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_SET_TILING
value|DRM_IOWR (DRM_COMMAND_BASE + DRM_I915_GEM_SET_TILING, struct drm_i915_gem_set_tiling)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_GET_TILING
value|DRM_IOWR (DRM_COMMAND_BASE + DRM_I915_GEM_GET_TILING, struct drm_i915_gem_get_tiling)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_GET_APERTURE
value|DRM_IOR  (DRM_COMMAND_BASE + DRM_I915_GEM_GET_APERTURE, struct drm_i915_gem_get_aperture)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GET_PIPE_FROM_CRTC_ID
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GET_PIPE_FROM_CRTC_ID, struct drm_i915_get_pipe_from_crtc_id)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_MADVISE
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_MADVISE, struct drm_i915_gem_madvise)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_OVERLAY_PUT_IMAGE
value|DRM_IOW(DRM_COMMAND_BASE + DRM_I915_OVERLAY_PUT_IMAGE, struct drm_intel_overlay_put_image)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_OVERLAY_ATTRS
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_OVERLAY_ATTRS, struct drm_intel_overlay_attrs)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_SET_SPRITE_COLORKEY
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_SET_SPRITE_COLORKEY, struct drm_intel_sprite_colorkey)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GET_SPRITE_COLORKEY
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_SET_SPRITE_COLORKEY, struct drm_intel_sprite_colorkey)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_WAIT
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_WAIT, struct drm_i915_gem_wait)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_CONTEXT_CREATE
value|DRM_IOWR (DRM_COMMAND_BASE + DRM_I915_GEM_CONTEXT_CREATE, struct drm_i915_gem_context_create)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_CONTEXT_DESTROY
value|DRM_IOW (DRM_COMMAND_BASE + DRM_I915_GEM_CONTEXT_DESTROY, struct drm_i915_gem_context_destroy)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_REG_READ
value|DRM_IOWR (DRM_COMMAND_BASE + DRM_I915_REG_READ, struct drm_i915_reg_read)
end_define

begin_comment
comment|/* Allow drivers to submit batchbuffers directly to hardware, relying  * on the security mechanisms provided by hardware.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|drm_i915_batchbuffer
block|{
name|int
name|start
decl_stmt|;
comment|/* agp offset */
name|int
name|used
decl_stmt|;
comment|/* nr bytes in use */
name|int
name|DR1
decl_stmt|;
comment|/* hw flags for GFX_OP_DRAWRECT_INFO */
name|int
name|DR4
decl_stmt|;
comment|/* window origin for GFX_OP_DRAWRECT_INFO */
name|int
name|num_cliprects
decl_stmt|;
comment|/* mulitpass with multiple cliprects? */
name|struct
name|drm_clip_rect
name|__user
modifier|*
name|cliprects
decl_stmt|;
comment|/* pointer to userspace cliprects */
block|}
name|drm_i915_batchbuffer_t
typedef|;
end_typedef

begin_comment
comment|/* As above, but pass a pointer to userspace buffer which can be  * validated by the kernel prior to sending to hardware.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_drm_i915_cmdbuffer
block|{
name|char
name|__user
modifier|*
name|buf
decl_stmt|;
comment|/* pointer to userspace command buffer */
name|int
name|sz
decl_stmt|;
comment|/* nr bytes in buf */
name|int
name|DR1
decl_stmt|;
comment|/* hw flags for GFX_OP_DRAWRECT_INFO */
name|int
name|DR4
decl_stmt|;
comment|/* window origin for GFX_OP_DRAWRECT_INFO */
name|int
name|num_cliprects
decl_stmt|;
comment|/* mulitpass with multiple cliprects? */
name|struct
name|drm_clip_rect
name|__user
modifier|*
name|cliprects
decl_stmt|;
comment|/* pointer to userspace cliprects */
block|}
name|drm_i915_cmdbuffer_t
typedef|;
end_typedef

begin_comment
comment|/* Userspace can request& wait on irq's:  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|drm_i915_irq_emit
block|{
name|int
name|__user
modifier|*
name|irq_seq
decl_stmt|;
block|}
name|drm_i915_irq_emit_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_i915_irq_wait
block|{
name|int
name|irq_seq
decl_stmt|;
block|}
name|drm_i915_irq_wait_t
typedef|;
end_typedef

begin_comment
comment|/* Ioctl to query kernel params:  */
end_comment

begin_define
define|#
directive|define
name|I915_PARAM_IRQ_ACTIVE
value|1
end_define

begin_define
define|#
directive|define
name|I915_PARAM_ALLOW_BATCHBUFFER
value|2
end_define

begin_define
define|#
directive|define
name|I915_PARAM_LAST_DISPATCH
value|3
end_define

begin_define
define|#
directive|define
name|I915_PARAM_CHIPSET_ID
value|4
end_define

begin_define
define|#
directive|define
name|I915_PARAM_HAS_GEM
value|5
end_define

begin_define
define|#
directive|define
name|I915_PARAM_NUM_FENCES_AVAIL
value|6
end_define

begin_define
define|#
directive|define
name|I915_PARAM_HAS_OVERLAY
value|7
end_define

begin_define
define|#
directive|define
name|I915_PARAM_HAS_PAGEFLIPPING
value|8
end_define

begin_define
define|#
directive|define
name|I915_PARAM_HAS_EXECBUF2
value|9
end_define

begin_define
define|#
directive|define
name|I915_PARAM_HAS_BSD
value|10
end_define

begin_define
define|#
directive|define
name|I915_PARAM_HAS_BLT
value|11
end_define

begin_define
define|#
directive|define
name|I915_PARAM_HAS_RELAXED_FENCING
value|12
end_define

begin_define
define|#
directive|define
name|I915_PARAM_HAS_COHERENT_RINGS
value|13
end_define

begin_define
define|#
directive|define
name|I915_PARAM_HAS_EXEC_CONSTANTS
value|14
end_define

begin_define
define|#
directive|define
name|I915_PARAM_HAS_RELAXED_DELTA
value|15
end_define

begin_define
define|#
directive|define
name|I915_PARAM_HAS_GEN7_SOL_RESET
value|16
end_define

begin_define
define|#
directive|define
name|I915_PARAM_HAS_LLC
value|17
end_define

begin_define
define|#
directive|define
name|I915_PARAM_HAS_ALIASING_PPGTT
value|18
end_define

begin_define
define|#
directive|define
name|I915_PARAM_HAS_WAIT_TIMEOUT
value|19
end_define

begin_define
define|#
directive|define
name|I915_PARAM_HAS_SEMAPHORES
value|20
end_define

begin_define
define|#
directive|define
name|I915_PARAM_HAS_PRIME_VMAP_FLUSH
value|21
end_define

begin_define
define|#
directive|define
name|I915_PARAM_RSVD_FOR_FUTURE_USE
value|22
end_define

begin_define
define|#
directive|define
name|I915_PARAM_HAS_SECURE_BATCHES
value|23
end_define

begin_define
define|#
directive|define
name|I915_PARAM_HAS_PINNED_BATCHES
value|24
end_define

begin_typedef
typedef|typedef
struct|struct
name|drm_i915_getparam
block|{
name|int
name|param
decl_stmt|;
name|int
name|__user
modifier|*
name|value
decl_stmt|;
block|}
name|drm_i915_getparam_t
typedef|;
end_typedef

begin_comment
comment|/* Ioctl to set kernel params:  */
end_comment

begin_define
define|#
directive|define
name|I915_SETPARAM_USE_MI_BATCHBUFFER_START
value|1
end_define

begin_define
define|#
directive|define
name|I915_SETPARAM_TEX_LRU_LOG_GRANULARITY
value|2
end_define

begin_define
define|#
directive|define
name|I915_SETPARAM_ALLOW_BATCHBUFFER
value|3
end_define

begin_define
define|#
directive|define
name|I915_SETPARAM_NUM_USED_FENCES
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
name|drm_i915_setparam
block|{
name|int
name|param
decl_stmt|;
name|int
name|value
decl_stmt|;
block|}
name|drm_i915_setparam_t
typedef|;
end_typedef

begin_comment
comment|/* A memory manager for regions of shared memory:  */
end_comment

begin_define
define|#
directive|define
name|I915_MEM_REGION_AGP
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|drm_i915_mem_alloc
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
name|__user
modifier|*
name|region_offset
decl_stmt|;
comment|/* offset from start of fb or agp */
block|}
name|drm_i915_mem_alloc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_i915_mem_free
block|{
name|int
name|region
decl_stmt|;
name|int
name|region_offset
decl_stmt|;
block|}
name|drm_i915_mem_free_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_i915_mem_init_heap
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
name|drm_i915_mem_init_heap_t
typedef|;
end_typedef

begin_comment
comment|/* Allow memory manager to be torn down and re-initialized (eg on  * rotate):  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|drm_i915_mem_destroy_heap
block|{
name|int
name|region
decl_stmt|;
block|}
name|drm_i915_mem_destroy_heap_t
typedef|;
end_typedef

begin_comment
comment|/* Allow X server to configure which pipes to monitor for vblank signals  */
end_comment

begin_define
define|#
directive|define
name|DRM_I915_VBLANK_PIPE_A
value|1
end_define

begin_define
define|#
directive|define
name|DRM_I915_VBLANK_PIPE_B
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|drm_i915_vblank_pipe
block|{
name|int
name|pipe
decl_stmt|;
block|}
name|drm_i915_vblank_pipe_t
typedef|;
end_typedef

begin_comment
comment|/* Schedule buffer swap at given vertical blank:  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|drm_i915_vblank_swap
block|{
name|drm_drawable_t
name|drawable
decl_stmt|;
name|enum
name|drm_vblank_seq_type
name|seqtype
decl_stmt|;
name|unsigned
name|int
name|sequence
decl_stmt|;
block|}
name|drm_i915_vblank_swap_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_i915_hws_addr
block|{
name|__u64
name|addr
decl_stmt|;
block|}
name|drm_i915_hws_addr_t
typedef|;
end_typedef

begin_struct
struct|struct
name|drm_i915_gem_init
block|{
comment|/** 	 * Beginning offset in the GTT to be managed by the DRM memory 	 * manager. 	 */
name|__u64
name|gtt_start
decl_stmt|;
comment|/** 	 * Ending offset in the GTT to be managed by the DRM memory 	 * manager. 	 */
name|__u64
name|gtt_end
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_create
block|{
comment|/** 	 * Requested size for the object. 	 * 	 * The (page-aligned) allocated size for the object will be returned. 	 */
name|__u64
name|size
decl_stmt|;
comment|/** 	 * Returned handle for the object. 	 * 	 * Object handles are nonzero. 	 */
name|__u32
name|handle
decl_stmt|;
name|__u32
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_pread
block|{
comment|/** Handle for the object being read. */
name|__u32
name|handle
decl_stmt|;
name|__u32
name|pad
decl_stmt|;
comment|/** Offset into the object to read from */
name|__u64
name|offset
decl_stmt|;
comment|/** Length of data to read */
name|__u64
name|size
decl_stmt|;
comment|/** 	 * Pointer to write the data into. 	 * 	 * This is a fixed-size type for 32/64 compatibility. 	 */
name|__u64
name|data_ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_pwrite
block|{
comment|/** Handle for the object being written to. */
name|__u32
name|handle
decl_stmt|;
name|__u32
name|pad
decl_stmt|;
comment|/** Offset into the object to write to */
name|__u64
name|offset
decl_stmt|;
comment|/** Length of data to write */
name|__u64
name|size
decl_stmt|;
comment|/** 	 * Pointer to read the data from. 	 * 	 * This is a fixed-size type for 32/64 compatibility. 	 */
name|__u64
name|data_ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_mmap
block|{
comment|/** Handle for the object being mapped. */
name|__u32
name|handle
decl_stmt|;
name|__u32
name|pad
decl_stmt|;
comment|/** Offset in the object to map. */
name|__u64
name|offset
decl_stmt|;
comment|/** 	 * Length of data to map. 	 * 	 * The value will be page-aligned. 	 */
name|__u64
name|size
decl_stmt|;
comment|/** 	 * Returned pointer the data was mapped at. 	 * 	 * This is a fixed-size type for 32/64 compatibility. 	 */
name|__u64
name|addr_ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_mmap_gtt
block|{
comment|/** Handle for the object being mapped. */
name|__u32
name|handle
decl_stmt|;
name|__u32
name|pad
decl_stmt|;
comment|/** 	 * Fake offset to use for subsequent mmap call 	 * 	 * This is a fixed-size type for 32/64 compatibility. 	 */
name|__u64
name|offset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_set_domain
block|{
comment|/** Handle for the object */
name|__u32
name|handle
decl_stmt|;
comment|/** New read domains */
name|__u32
name|read_domains
decl_stmt|;
comment|/** New write domain */
name|__u32
name|write_domain
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_sw_finish
block|{
comment|/** Handle for the object */
name|__u32
name|handle
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_relocation_entry
block|{
comment|/** 	 * Handle of the buffer being pointed to by this relocation entry. 	 * 	 * It's appealing to make this be an index into the mm_validate_entry 	 * list to refer to the buffer, but this allows the driver to create 	 * a relocation list for state buffers and not re-write it per 	 * exec using the buffer. 	 */
name|__u32
name|target_handle
decl_stmt|;
comment|/** 	 * Value to be added to the offset of the target buffer to make up 	 * the relocation entry. 	 */
name|__u32
name|delta
decl_stmt|;
comment|/** Offset in the buffer the relocation entry will be written into */
name|__u64
name|offset
decl_stmt|;
comment|/** 	 * Offset value of the target buffer that the relocation entry was last 	 * written as. 	 * 	 * If the buffer has the same offset as last time, we can skip syncing 	 * and writing the relocation.  This value is written back out by 	 * the execbuffer ioctl when the relocation is written. 	 */
name|__u64
name|presumed_offset
decl_stmt|;
comment|/** 	 * Target memory domains read by this operation. 	 */
name|__u32
name|read_domains
decl_stmt|;
comment|/** 	 * Target memory domains written by this operation. 	 * 	 * Note that only one domain may be written by the whole 	 * execbuffer operation, so that where there are conflicts, 	 * the application will get -EINVAL back. 	 */
name|__u32
name|write_domain
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** @{  * Intel memory domains  *  * Most of these just align with the various caches in  * the system and are used to flush and invalidate as  * objects end up cached in different domains.  */
end_comment

begin_comment
comment|/** CPU cache */
end_comment

begin_define
define|#
directive|define
name|I915_GEM_DOMAIN_CPU
value|0x00000001
end_define

begin_comment
comment|/** Render cache, used by 2D and 3D drawing */
end_comment

begin_define
define|#
directive|define
name|I915_GEM_DOMAIN_RENDER
value|0x00000002
end_define

begin_comment
comment|/** Sampler cache, used by texture engine */
end_comment

begin_define
define|#
directive|define
name|I915_GEM_DOMAIN_SAMPLER
value|0x00000004
end_define

begin_comment
comment|/** Command queue, used to load batch buffers */
end_comment

begin_define
define|#
directive|define
name|I915_GEM_DOMAIN_COMMAND
value|0x00000008
end_define

begin_comment
comment|/** Instruction cache, used by shader programs */
end_comment

begin_define
define|#
directive|define
name|I915_GEM_DOMAIN_INSTRUCTION
value|0x00000010
end_define

begin_comment
comment|/** Vertex address cache */
end_comment

begin_define
define|#
directive|define
name|I915_GEM_DOMAIN_VERTEX
value|0x00000020
end_define

begin_comment
comment|/** GTT domain - aperture and scanout */
end_comment

begin_define
define|#
directive|define
name|I915_GEM_DOMAIN_GTT
value|0x00000040
end_define

begin_comment
comment|/** @} */
end_comment

begin_struct
struct|struct
name|drm_i915_gem_exec_object
block|{
comment|/** 	 * User's handle for a buffer to be bound into the GTT for this 	 * operation. 	 */
name|__u32
name|handle
decl_stmt|;
comment|/** Number of relocations to be performed on this buffer */
name|__u32
name|relocation_count
decl_stmt|;
comment|/** 	 * Pointer to array of struct drm_i915_gem_relocation_entry containing 	 * the relocations to be performed in this buffer. 	 */
name|__u64
name|relocs_ptr
decl_stmt|;
comment|/** Required alignment in graphics aperture */
name|__u64
name|alignment
decl_stmt|;
comment|/** 	 * Returned value of the updated offset of the object, for future 	 * presumed_offset writes. 	 */
name|__u64
name|offset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_execbuffer
block|{
comment|/** 	 * List of buffers to be validated with their relocations to be 	 * performend on them. 	 * 	 * This is a pointer to an array of struct drm_i915_gem_validate_entry. 	 * 	 * These buffers must be listed in an order such that all relocations 	 * a buffer is performing refer to buffers that have already appeared 	 * in the validate list. 	 */
name|__u64
name|buffers_ptr
decl_stmt|;
name|__u32
name|buffer_count
decl_stmt|;
comment|/** Offset in the batchbuffer to start execution from. */
name|__u32
name|batch_start_offset
decl_stmt|;
comment|/** Bytes used in batchbuffer from batch_start_offset */
name|__u32
name|batch_len
decl_stmt|;
name|__u32
name|DR1
decl_stmt|;
name|__u32
name|DR4
decl_stmt|;
name|__u32
name|num_cliprects
decl_stmt|;
comment|/** This is a struct drm_clip_rect *cliprects */
name|__u64
name|cliprects_ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_exec_object2
block|{
comment|/** 	 * User's handle for a buffer to be bound into the GTT for this 	 * operation. 	 */
name|__u32
name|handle
decl_stmt|;
comment|/** Number of relocations to be performed on this buffer */
name|__u32
name|relocation_count
decl_stmt|;
comment|/** 	 * Pointer to array of struct drm_i915_gem_relocation_entry containing 	 * the relocations to be performed in this buffer. 	 */
name|__u64
name|relocs_ptr
decl_stmt|;
comment|/** Required alignment in graphics aperture */
name|__u64
name|alignment
decl_stmt|;
comment|/** 	 * Returned value of the updated offset of the object, for future 	 * presumed_offset writes. 	 */
name|__u64
name|offset
decl_stmt|;
define|#
directive|define
name|EXEC_OBJECT_NEEDS_FENCE
value|(1<<0)
name|__u64
name|flags
decl_stmt|;
name|__u64
name|rsvd1
decl_stmt|;
name|__u64
name|rsvd2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_execbuffer2
block|{
comment|/** 	 * List of gem_exec_object2 structs 	 */
name|__u64
name|buffers_ptr
decl_stmt|;
name|__u32
name|buffer_count
decl_stmt|;
comment|/** Offset in the batchbuffer to start execution from. */
name|__u32
name|batch_start_offset
decl_stmt|;
comment|/** Bytes used in batchbuffer from batch_start_offset */
name|__u32
name|batch_len
decl_stmt|;
name|__u32
name|DR1
decl_stmt|;
name|__u32
name|DR4
decl_stmt|;
name|__u32
name|num_cliprects
decl_stmt|;
comment|/** This is a struct drm_clip_rect *cliprects */
name|__u64
name|cliprects_ptr
decl_stmt|;
define|#
directive|define
name|I915_EXEC_RING_MASK
value|(7<<0)
define|#
directive|define
name|I915_EXEC_DEFAULT
value|(0<<0)
define|#
directive|define
name|I915_EXEC_RENDER
value|(1<<0)
define|#
directive|define
name|I915_EXEC_BSD
value|(2<<0)
define|#
directive|define
name|I915_EXEC_BLT
value|(3<<0)
comment|/* Used for switching the constants addressing mode on gen4+ RENDER ring.  * Gen6+ only supports relative addressing to dynamic state (default) and  * absolute addressing.  *  * These flags are ignored for the BSD and BLT rings.  */
define|#
directive|define
name|I915_EXEC_CONSTANTS_MASK
value|(3<<6)
define|#
directive|define
name|I915_EXEC_CONSTANTS_REL_GENERAL
value|(0<<6)
comment|/* default */
define|#
directive|define
name|I915_EXEC_CONSTANTS_ABSOLUTE
value|(1<<6)
define|#
directive|define
name|I915_EXEC_CONSTANTS_REL_SURFACE
value|(2<<6)
comment|/* gen4/5 only */
name|__u64
name|flags
decl_stmt|;
name|__u64
name|rsvd1
decl_stmt|;
comment|/* now used for context info */
name|__u64
name|rsvd2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** Resets the SO write offset registers for transform feedback on gen7. */
end_comment

begin_define
define|#
directive|define
name|I915_EXEC_GEN7_SOL_RESET
value|(1<<8)
end_define

begin_comment
comment|/** Request a privileged ("secure") batch buffer. Note only available for  * DRM_ROOT_ONLY | DRM_MASTER processes.  */
end_comment

begin_define
define|#
directive|define
name|I915_EXEC_SECURE
value|(1<<9)
end_define

begin_comment
comment|/** Inform the kernel that the batch is and will always be pinned. This  * negates the requirement for a workaround to be performed to avoid  * an incoherent CS (such as can be found on 830/845). If this flag is  * not passed, the kernel will endeavour to make sure the batch is  * coherent with the CS before execution. If this flag is passed,  * userspace assumes the responsibility for ensuring the same.  */
end_comment

begin_define
define|#
directive|define
name|I915_EXEC_IS_PINNED
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|I915_EXEC_CONTEXT_ID_MASK
value|(0xffffffff)
end_define

begin_define
define|#
directive|define
name|i915_execbuffer2_set_context_id
parameter_list|(
name|eb2
parameter_list|,
name|context
parameter_list|)
define|\
value|(eb2).rsvd1 = context& I915_EXEC_CONTEXT_ID_MASK
end_define

begin_define
define|#
directive|define
name|i915_execbuffer2_get_context_id
parameter_list|(
name|eb2
parameter_list|)
define|\
value|((eb2).rsvd1& I915_EXEC_CONTEXT_ID_MASK)
end_define

begin_struct
struct|struct
name|drm_i915_gem_pin
block|{
comment|/** Handle of the buffer to be pinned. */
name|__u32
name|handle
decl_stmt|;
name|__u32
name|pad
decl_stmt|;
comment|/** alignment required within the aperture */
name|__u64
name|alignment
decl_stmt|;
comment|/** Returned GTT offset of the buffer. */
name|__u64
name|offset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_unpin
block|{
comment|/** Handle of the buffer to be unpinned. */
name|__u32
name|handle
decl_stmt|;
name|__u32
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_busy
block|{
comment|/** Handle of the buffer to check for busy */
name|__u32
name|handle
decl_stmt|;
comment|/** Return busy status (1 if busy, 0 if idle). 	 * The high word is used to indicate on which rings the object 	 * currently resides: 	 *  16:31 - busy (r or r/w) rings (16 render, 17 bsd, 18 blt, etc) 	 */
name|__u32
name|busy
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|I915_CACHING_NONE
value|0
end_define

begin_define
define|#
directive|define
name|I915_CACHING_CACHED
value|1
end_define

begin_struct
struct|struct
name|drm_i915_gem_caching
block|{
comment|/** 	 * Handle of the buffer to set/get the caching level of. */
name|__u32
name|handle
decl_stmt|;
comment|/** 	 * Cacheing level to apply or return value 	 * 	 * bits0-15 are for generic caching control (i.e. the above defined 	 * values). bits16-31 are reserved for platform-specific variations 	 * (e.g. l3$ caching on gen7). */
name|__u32
name|caching
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|I915_TILING_NONE
value|0
end_define

begin_define
define|#
directive|define
name|I915_TILING_X
value|1
end_define

begin_define
define|#
directive|define
name|I915_TILING_Y
value|2
end_define

begin_define
define|#
directive|define
name|I915_BIT_6_SWIZZLE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|I915_BIT_6_SWIZZLE_9
value|1
end_define

begin_define
define|#
directive|define
name|I915_BIT_6_SWIZZLE_9_10
value|2
end_define

begin_define
define|#
directive|define
name|I915_BIT_6_SWIZZLE_9_11
value|3
end_define

begin_define
define|#
directive|define
name|I915_BIT_6_SWIZZLE_9_10_11
value|4
end_define

begin_comment
comment|/* Not seen by userland */
end_comment

begin_define
define|#
directive|define
name|I915_BIT_6_SWIZZLE_UNKNOWN
value|5
end_define

begin_comment
comment|/* Seen by userland. */
end_comment

begin_define
define|#
directive|define
name|I915_BIT_6_SWIZZLE_9_17
value|6
end_define

begin_define
define|#
directive|define
name|I915_BIT_6_SWIZZLE_9_10_17
value|7
end_define

begin_struct
struct|struct
name|drm_i915_gem_set_tiling
block|{
comment|/** Handle of the buffer to have its tiling state updated */
name|__u32
name|handle
decl_stmt|;
comment|/** 	 * Tiling mode for the object (I915_TILING_NONE, I915_TILING_X, 	 * I915_TILING_Y). 	 * 	 * This value is to be set on request, and will be updated by the 	 * kernel on successful return with the actual chosen tiling layout. 	 * 	 * The tiling mode may be demoted to I915_TILING_NONE when the system 	 * has bit 6 swizzling that can't be managed correctly by GEM. 	 * 	 * Buffer contents become undefined when changing tiling_mode. 	 */
name|__u32
name|tiling_mode
decl_stmt|;
comment|/** 	 * Stride in bytes for the object when in I915_TILING_X or 	 * I915_TILING_Y. 	 */
name|__u32
name|stride
decl_stmt|;
comment|/** 	 * Returned address bit 6 swizzling required for CPU access through 	 * mmap mapping. 	 */
name|__u32
name|swizzle_mode
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_get_tiling
block|{
comment|/** Handle of the buffer to get tiling state for. */
name|__u32
name|handle
decl_stmt|;
comment|/** 	 * Current tiling mode for the object (I915_TILING_NONE, I915_TILING_X, 	 * I915_TILING_Y). 	 */
name|__u32
name|tiling_mode
decl_stmt|;
comment|/** 	 * Returned address bit 6 swizzling required for CPU access through 	 * mmap mapping. 	 */
name|__u32
name|swizzle_mode
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_get_aperture
block|{
comment|/** Total size of the aperture used by i915_gem_execbuffer, in bytes */
name|__u64
name|aper_size
decl_stmt|;
comment|/** 	 * Available space in the aperture used by i915_gem_execbuffer, in 	 * bytes 	 */
name|__u64
name|aper_available_size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_get_pipe_from_crtc_id
block|{
comment|/** ID of CRTC being requested **/
name|__u32
name|crtc_id
decl_stmt|;
comment|/** pipe of requested CRTC **/
name|__u32
name|pipe
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|I915_MADV_WILLNEED
value|0
end_define

begin_define
define|#
directive|define
name|I915_MADV_DONTNEED
value|1
end_define

begin_define
define|#
directive|define
name|__I915_MADV_PURGED
value|2
end_define

begin_comment
comment|/* internal state */
end_comment

begin_struct
struct|struct
name|drm_i915_gem_madvise
block|{
comment|/** Handle of the buffer to change the backing store advice */
name|__u32
name|handle
decl_stmt|;
comment|/* Advice: either the buffer will be needed again in the near future, 	 *         or wont be and could be discarded under memory pressure. 	 */
name|__u32
name|madv
decl_stmt|;
comment|/** Whether the backing store still exists. */
name|__u32
name|retained
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|I915_OVERLAY_TYPE_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_YUV_PLANAR
value|0x01
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_YUV_PACKED
value|0x02
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_RGB
value|0x03
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_DEPTH_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_RGB24
value|0x1000
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_RGB16
value|0x2000
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_RGB15
value|0x3000
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_YUV422
value|0x0100
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_YUV411
value|0x0200
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_YUV420
value|0x0300
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_YUV410
value|0x0400
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_SWAP_MASK
value|0xff0000
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_NO_SWAP
value|0x000000
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_UV_SWAP
value|0x010000
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_Y_SWAP
value|0x020000
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_Y_AND_UV_SWAP
value|0x030000
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_FLAGS_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_ENABLE
value|0x01000000
end_define

begin_struct
struct|struct
name|drm_intel_overlay_put_image
block|{
comment|/* various flags and src format description */
name|__u32
name|flags
decl_stmt|;
comment|/* source picture description */
name|__u32
name|bo_handle
decl_stmt|;
comment|/* stride values and offsets are in bytes, buffer relative */
name|__u16
name|stride_Y
decl_stmt|;
comment|/* stride for packed formats */
name|__u16
name|stride_UV
decl_stmt|;
name|__u32
name|offset_Y
decl_stmt|;
comment|/* offset for packet formats */
name|__u32
name|offset_U
decl_stmt|;
name|__u32
name|offset_V
decl_stmt|;
comment|/* in pixels */
name|__u16
name|src_width
decl_stmt|;
name|__u16
name|src_height
decl_stmt|;
comment|/* to compensate the scaling factors for partially covered surfaces */
name|__u16
name|src_scan_width
decl_stmt|;
name|__u16
name|src_scan_height
decl_stmt|;
comment|/* output crtc description */
name|__u32
name|crtc_id
decl_stmt|;
name|__u16
name|dst_x
decl_stmt|;
name|__u16
name|dst_y
decl_stmt|;
name|__u16
name|dst_width
decl_stmt|;
name|__u16
name|dst_height
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|I915_OVERLAY_UPDATE_ATTRS
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_UPDATE_GAMMA
value|(1<<1)
end_define

begin_struct
struct|struct
name|drm_intel_overlay_attrs
block|{
name|__u32
name|flags
decl_stmt|;
name|__u32
name|color_key
decl_stmt|;
name|__s32
name|brightness
decl_stmt|;
name|__u32
name|contrast
decl_stmt|;
name|__u32
name|saturation
decl_stmt|;
name|__u32
name|gamma0
decl_stmt|;
name|__u32
name|gamma1
decl_stmt|;
name|__u32
name|gamma2
decl_stmt|;
name|__u32
name|gamma3
decl_stmt|;
name|__u32
name|gamma4
decl_stmt|;
name|__u32
name|gamma5
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Intel sprite handling  *  * Color keying works with a min/mask/max tuple.  Both source and destination  * color keying is allowed.  *  * Source keying:  * Sprite pixels within the min& max values, masked against the color channels  * specified in the mask field, will be transparent.  All other pixels will  * be displayed on top of the primary plane.  For RGB surfaces, only the min  * and mask fields will be used; ranged compares are not allowed.  *  * Destination keying:  * Primary plane pixels that match the min value, masked against the color  * channels specified in the mask field, will be replaced by corresponding  * pixels from the sprite plane.  *  * Note that source& destination keying are exclusive; only one can be  * active on a given plane.  */
end_comment

begin_define
define|#
directive|define
name|I915_SET_COLORKEY_NONE
value|(1<<0)
end_define

begin_comment
comment|/* disable color key matching */
end_comment

begin_define
define|#
directive|define
name|I915_SET_COLORKEY_DESTINATION
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|I915_SET_COLORKEY_SOURCE
value|(1<<2)
end_define

begin_struct
struct|struct
name|drm_intel_sprite_colorkey
block|{
name|__u32
name|plane_id
decl_stmt|;
name|__u32
name|min_value
decl_stmt|;
name|__u32
name|channel_mask
decl_stmt|;
name|__u32
name|max_value
decl_stmt|;
name|__u32
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_wait
block|{
comment|/** Handle of BO we shall wait on */
name|__u32
name|bo_handle
decl_stmt|;
name|__u32
name|flags
decl_stmt|;
comment|/** Number of nanoseconds to wait, Returns time remaining. */
name|__s64
name|timeout_ns
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_context_create
block|{
comment|/*  output: id of new context*/
name|__u32
name|ctx_id
decl_stmt|;
name|__u32
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_context_destroy
block|{
name|__u32
name|ctx_id
decl_stmt|;
name|__u32
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_reg_read
block|{
name|__u64
name|offset
decl_stmt|;
name|__u64
name|val
decl_stmt|;
comment|/* Return value */
block|}
struct|;
end_struct

begin_comment
comment|/* For use by IPS driver */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|long
name|i915_read_mch_val
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|i915_gpu_raise
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|i915_gpu_lower
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|i915_gpu_busy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|i915_gpu_turbo_disable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UAPI_I915_DRM_H_ */
end_comment

end_unit

