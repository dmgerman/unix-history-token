begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003 Tungsten Graphics, Inc., Cedar Park, Texas.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the  * "Software"), to deal in the Software without restriction, including  * without limitation the rights to use, copy, modify, merge, publish,  * distribute, sub license, and/or sell copies of the Software, and to  * permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *  * The above copyright notice and this permission notice (including the  * next paragraph) shall be included in all copies or substantial portions  * of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.  * IN NO EVENT SHALL TUNGSTEN GRAPHICS AND/OR ITS SUPPLIERS BE LIABLE FOR  * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE  * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  *  */
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
name|_I915_DRM_H_
end_ifndef

begin_define
define|#
directive|define
name|_I915_DRM_H_
end_define

begin_comment
comment|/* Please note that modifications to all structs defined here are  * subject to backwards-compatibility constraints.  */
end_comment

begin_include
include|#
directive|include
file|<dev/drm2/drm.h>
end_include

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
block|,
comment|/* Since this struct isn't versioned, just used a new 		 * 'func' code to indicate the presence of dri2 sarea 		 * info. */
name|I915_INIT_DMA2
init|=
literal|0x04
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
name|unsigned
name|int
name|sarea_handle
decl_stmt|;
block|}
name|drm_i915_init_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_i915_sarea
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
name|planeA_x
decl_stmt|;
name|int
name|planeA_y
decl_stmt|;
name|int
name|planeA_w
decl_stmt|;
name|int
name|planeA_h
decl_stmt|;
name|int
name|planeB_x
decl_stmt|;
name|int
name|planeB_y
decl_stmt|;
name|int
name|planeB_w
decl_stmt|;
name|int
name|planeB_h
decl_stmt|;
comment|/* Triple buffering */
name|drm_handle_t
name|third_handle
decl_stmt|;
name|int
name|third_offset
decl_stmt|;
name|int
name|third_size
decl_stmt|;
name|unsigned
name|int
name|third_tiled
decl_stmt|;
comment|/* buffer object handles for the static buffers.  May change 	 * over the lifetime of the client, though it doesn't in our current 	 * implementation. 	 */
name|unsigned
name|int
name|front_bo_handle
decl_stmt|;
name|unsigned
name|int
name|back_bo_handle
decl_stmt|;
name|unsigned
name|int
name|third_bo_handle
decl_stmt|;
name|unsigned
name|int
name|depth_bo_handle
decl_stmt|;
block|}
name|drm_i915_sarea_t
typedef|;
end_typedef

begin_comment
comment|/* Driver specific fence types and classes.  */
end_comment

begin_comment
comment|/* The only fence class we support */
end_comment

begin_define
define|#
directive|define
name|DRM_I915_FENCE_CLASS_ACCEL
value|0
end_define

begin_comment
comment|/* Fence type that guarantees read-write flush */
end_comment

begin_define
define|#
directive|define
name|DRM_I915_FENCE_TYPE_RW
value|2
end_define

begin_comment
comment|/* MI_FLUSH programmed just before the fence */
end_comment

begin_define
define|#
directive|define
name|DRM_I915_FENCE_FLAG_FLUSHED
value|0x01000000
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
name|DRM_I915_MMIO
value|0x10
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
name|DRM_I915_EXECBUFFER
value|0x12
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
value|DRM_IOW( DRM_COMMAND_BASE + DRM_I915_FLIP, drm_i915_flip_t)
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
name|DRM_IOCTL_I915_MMIO
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_MMIO, drm_i915_mmio)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_EXECBUFFER
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_EXECBUFFER, struct drm_i915_execbuffer)
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
value|DRM_IOW(DRM_COMMAND_BASE + DRM_IOCTL_I915_OVERLAY_PUT_IMAGE, struct drm_intel_overlay_put_image)
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
name|DRM_IOCTL_I915_GEM_CONTEXT_CREATE
value|DRM_IOWR (DRM_COMMAND_BASE + DRM_I915_GEM_CONTEXT_CREATE, struct drm_i915_gem_context_create)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_I915_GEM_CONTEXT_DESTROY
value|DRM_IOW (DRM_COMMAND_BASE + DRM_I915_GEM_CONTEXT_DESTROY, struct drm_i915_gem_context_destroy)
end_define

begin_comment
comment|/* Asynchronous page flipping:  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|drm_i915_flip
block|{
comment|/* 	 * This is really talking about planes, and we could rename it 	 * except for the fact that some of the duplicated i915_drm.h files 	 * out there check for HAVE_I915_FLIP and so might pick up this 	 * version. 	 */
name|int
name|pipes
decl_stmt|;
block|}
name|drm_i915_flip_t
typedef|;
end_typedef

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

begin_define
define|#
directive|define
name|I915_MMIO_READ
value|0
end_define

begin_define
define|#
directive|define
name|I915_MMIO_WRITE
value|1
end_define

begin_define
define|#
directive|define
name|I915_MMIO_MAY_READ
value|0x1
end_define

begin_define
define|#
directive|define
name|I915_MMIO_MAY_WRITE
value|0x2
end_define

begin_define
define|#
directive|define
name|MMIO_REGS_IA_PRIMATIVES_COUNT
value|0
end_define

begin_define
define|#
directive|define
name|MMIO_REGS_IA_VERTICES_COUNT
value|1
end_define

begin_define
define|#
directive|define
name|MMIO_REGS_VS_INVOCATION_COUNT
value|2
end_define

begin_define
define|#
directive|define
name|MMIO_REGS_GS_PRIMITIVES_COUNT
value|3
end_define

begin_define
define|#
directive|define
name|MMIO_REGS_GS_INVOCATION_COUNT
value|4
end_define

begin_define
define|#
directive|define
name|MMIO_REGS_CL_PRIMITIVES_COUNT
value|5
end_define

begin_define
define|#
directive|define
name|MMIO_REGS_CL_INVOCATION_COUNT
value|6
end_define

begin_define
define|#
directive|define
name|MMIO_REGS_PS_INVOCATION_COUNT
value|7
end_define

begin_define
define|#
directive|define
name|MMIO_REGS_PS_DEPTH_COUNT
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
name|drm_i915_mmio_entry
block|{
name|unsigned
name|int
name|flag
decl_stmt|;
name|unsigned
name|int
name|offset
decl_stmt|;
name|unsigned
name|int
name|size
decl_stmt|;
block|}
name|drm_i915_mmio_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_i915_mmio
block|{
name|unsigned
name|int
name|read_write
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|reg
range|:
literal|31
decl_stmt|;
name|void
name|__user
modifier|*
name|data
decl_stmt|;
block|}
name|drm_i915_mmio_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_i915_hws_addr
block|{
name|uint64_t
name|addr
decl_stmt|;
block|}
name|drm_i915_hws_addr_t
typedef|;
end_typedef

begin_comment
comment|/*  * Relocation header is 4 uint32_ts  * 0 - 32 bit reloc count  * 1 - 32-bit relocation type  * 2-3 - 64-bit user buffer handle ptr for another list of relocs.  */
end_comment

begin_define
define|#
directive|define
name|I915_RELOC_HEADER
value|4
end_define

begin_comment
comment|/*  * type 0 relocation has 4-uint32_t stride  * 0 - offset into buffer  * 1 - delta to add in  * 2 - buffer handle  * 3 - reserved (for optimisations later).  */
end_comment

begin_comment
comment|/*  * type 1 relocation has 4-uint32_t stride.  * Hangs off the first item in the op list.  * Performed after all valiations are done.  * Try to group relocs into the same relocatee together for  * performance reasons.  * 0 - offset into buffer  * 1 - delta to add in  * 2 - buffer index in op list.  * 3 - relocatee index in op list.  */
end_comment

begin_define
define|#
directive|define
name|I915_RELOC_TYPE_0
value|0
end_define

begin_define
define|#
directive|define
name|I915_RELOC0_STRIDE
value|4
end_define

begin_define
define|#
directive|define
name|I915_RELOC_TYPE_1
value|1
end_define

begin_define
define|#
directive|define
name|I915_RELOC1_STRIDE
value|4
end_define

begin_struct
struct|struct
name|drm_i915_op_arg
block|{
name|uint64_t
name|next
decl_stmt|;
name|uint64_t
name|reloc_ptr
decl_stmt|;
name|int
name|handled
decl_stmt|;
name|unsigned
name|int
name|pad64
decl_stmt|;
union|union
block|{
name|struct
name|drm_bo_op_req
name|req
decl_stmt|;
name|struct
name|drm_bo_arg_rep
name|rep
decl_stmt|;
block|}
name|d
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_execbuffer
block|{
name|uint64_t
name|ops_list
decl_stmt|;
name|uint32_t
name|num_buffers
decl_stmt|;
name|struct
name|drm_i915_batchbuffer
name|batch
decl_stmt|;
name|drm_context_t
name|context
decl_stmt|;
comment|/* for lockless use in the future */
name|struct
name|drm_fence_arg
name|fence_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_init
block|{
comment|/** 	 * Beginning offset in the GTT to be managed by the DRM memory 	 * manager. 	 */
name|uint64_t
name|gtt_start
decl_stmt|;
comment|/** 	 * Ending offset in the GTT to be managed by the DRM memory 	 * manager. 	 */
name|uint64_t
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
name|uint64_t
name|size
decl_stmt|;
comment|/** 	 * Returned handle for the object. 	 * 	 * Object handles are nonzero. 	 */
name|uint32_t
name|handle
decl_stmt|;
name|uint32_t
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
name|uint32_t
name|handle
decl_stmt|;
name|uint32_t
name|pad
decl_stmt|;
comment|/** Offset into the object to read from */
name|uint64_t
name|offset
decl_stmt|;
comment|/** Length of data to read */
name|uint64_t
name|size
decl_stmt|;
comment|/** Pointer to write the data into. */
name|uint64_t
name|data_ptr
decl_stmt|;
comment|/* void *, but pointers are not 32/64 compatible */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_pwrite
block|{
comment|/** Handle for the object being written to. */
name|uint32_t
name|handle
decl_stmt|;
name|uint32_t
name|pad
decl_stmt|;
comment|/** Offset into the object to write to */
name|uint64_t
name|offset
decl_stmt|;
comment|/** Length of data to write */
name|uint64_t
name|size
decl_stmt|;
comment|/** Pointer to read the data from. */
name|uint64_t
name|data_ptr
decl_stmt|;
comment|/* void *, but pointers are not 32/64 compatible */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_mmap
block|{
comment|/** Handle for the object being mapped. */
name|uint32_t
name|handle
decl_stmt|;
name|uint32_t
name|pad
decl_stmt|;
comment|/** Offset in the object to map. */
name|uint64_t
name|offset
decl_stmt|;
comment|/** 	 * Length of data to map. 	 * 	 * The value will be page-aligned. 	 */
name|uint64_t
name|size
decl_stmt|;
comment|/** Returned pointer the data was mapped at */
name|uint64_t
name|addr_ptr
decl_stmt|;
comment|/* void *, but pointers are not 32/64 compatible */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_mmap_gtt
block|{
comment|/** Handle for the object being mapped. */
name|uint32_t
name|handle
decl_stmt|;
name|uint32_t
name|pad
decl_stmt|;
comment|/** 	 * Fake offset to use for subsequent mmap call 	 * 	 * This is a fixed-size type for 32/64 compatibility. 	 */
name|uint64_t
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
name|uint32_t
name|handle
decl_stmt|;
comment|/** New read domains */
name|uint32_t
name|read_domains
decl_stmt|;
comment|/** New write domain */
name|uint32_t
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
name|uint32_t
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
name|uint32_t
name|target_handle
decl_stmt|;
comment|/** 	 * Value to be added to the offset of the target buffer to make up 	 * the relocation entry. 	 */
name|uint32_t
name|delta
decl_stmt|;
comment|/** Offset in the buffer the relocation entry will be written into */
name|uint64_t
name|offset
decl_stmt|;
comment|/** 	 * Offset value of the target buffer that the relocation entry was last 	 * written as. 	 * 	 * If the buffer has the same offset as last time, we can skip syncing 	 * and writing the relocation.  This value is written back out by 	 * the execbuffer ioctl when the relocation is written. 	 */
name|uint64_t
name|presumed_offset
decl_stmt|;
comment|/** 	 * Target memory domains read by this operation. 	 */
name|uint32_t
name|read_domains
decl_stmt|;
comment|/** 	 * Target memory domains written by this operation. 	 * 	 * Note that only one domain may be written by the whole 	 * execbuffer operation, so that where there are conflicts, 	 * the application will get -EINVAL back. 	 */
name|uint32_t
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
name|uint32_t
name|handle
decl_stmt|;
comment|/** Number of relocations to be performed on this buffer */
name|uint32_t
name|relocation_count
decl_stmt|;
comment|/** 	 * Pointer to array of struct drm_i915_gem_relocation_entry containing 	 * the relocations to be performed in this buffer. 	 */
name|uint64_t
name|relocs_ptr
decl_stmt|;
comment|/** Required alignment in graphics aperture */
name|uint64_t
name|alignment
decl_stmt|;
comment|/** 	 * Returned value of the updated offset of the object, for future 	 * presumed_offset writes. 	 */
name|uint64_t
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
name|uint64_t
name|buffers_ptr
decl_stmt|;
name|uint32_t
name|buffer_count
decl_stmt|;
comment|/** Offset in the batchbuffer to start execution from. */
name|uint32_t
name|batch_start_offset
decl_stmt|;
comment|/** Bytes used in batchbuffer from batch_start_offset */
name|uint32_t
name|batch_len
decl_stmt|;
name|uint32_t
name|DR1
decl_stmt|;
name|uint32_t
name|DR4
decl_stmt|;
name|uint32_t
name|num_cliprects
decl_stmt|;
name|uint64_t
name|cliprects_ptr
decl_stmt|;
comment|/* struct drm_clip_rect *cliprects */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_exec_object2
block|{
comment|/** 	 * User's handle for a buffer to be bound into the GTT for this 	 * operation. 	 */
name|uint32_t
name|handle
decl_stmt|;
comment|/** Number of relocations to be performed on this buffer */
name|uint32_t
name|relocation_count
decl_stmt|;
comment|/** 	 * Pointer to array of struct drm_i915_gem_relocation_entry containing 	 * the relocations to be performed in this buffer. 	 */
name|uint64_t
name|relocs_ptr
decl_stmt|;
comment|/** Required alignment in graphics aperture */
name|uint64_t
name|alignment
decl_stmt|;
comment|/** 	 * Returned value of the updated offset of the object, for future 	 * presumed_offset writes. 	 */
name|uint64_t
name|offset
decl_stmt|;
define|#
directive|define
name|EXEC_OBJECT_NEEDS_FENCE
value|(1<<0)
name|uint64_t
name|flags
decl_stmt|;
name|uint64_t
name|rsvd1
decl_stmt|;
comment|/* now used for context info */
name|uint64_t
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
name|uint64_t
name|buffers_ptr
decl_stmt|;
name|uint32_t
name|buffer_count
decl_stmt|;
comment|/** Offset in the batchbuffer to start execution from. */
name|uint32_t
name|batch_start_offset
decl_stmt|;
comment|/** Bytes used in batchbuffer from batch_start_offset */
name|uint32_t
name|batch_len
decl_stmt|;
name|uint32_t
name|DR1
decl_stmt|;
name|uint32_t
name|DR4
decl_stmt|;
name|uint32_t
name|num_cliprects
decl_stmt|;
comment|/** This is a struct drm_clip_rect *cliprects */
name|uint64_t
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
name|uint64_t
name|flags
decl_stmt|;
name|uint64_t
name|rsvd1
decl_stmt|;
name|uint64_t
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
name|uint32_t
name|handle
decl_stmt|;
name|uint32_t
name|pad
decl_stmt|;
comment|/** alignment required within the aperture */
name|uint64_t
name|alignment
decl_stmt|;
comment|/** Returned GTT offset of the buffer. */
name|uint64_t
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
name|uint32_t
name|handle
decl_stmt|;
name|uint32_t
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
name|uint32_t
name|handle
decl_stmt|;
comment|/** Return busy status (1 if busy, 0 if idle) */
name|uint32_t
name|busy
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
name|uint32_t
name|handle
decl_stmt|;
comment|/** 	 * Tiling mode for the object (I915_TILING_NONE, I915_TILING_X, 	 * I915_TILING_Y). 	 * 	 * This value is to be set on request, and will be updated by the 	 * kernel on successful return with the actual chosen tiling layout. 	 * 	 * The tiling mode may be demoted to I915_TILING_NONE when the system 	 * has bit 6 swizzling that can't be managed correctly by GEM. 	 * 	 * Buffer contents become undefined when changing tiling_mode. 	 */
name|uint32_t
name|tiling_mode
decl_stmt|;
comment|/** 	 * Stride in bytes for the object when in I915_TILING_X or 	 * I915_TILING_Y. 	 */
name|uint32_t
name|stride
decl_stmt|;
comment|/** 	 * Returned address bit 6 swizzling required for CPU access through 	 * mmap mapping. 	 */
name|uint32_t
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
name|uint32_t
name|handle
decl_stmt|;
comment|/** 	 * Current tiling mode for the object (I915_TILING_NONE, I915_TILING_X, 	 * I915_TILING_Y). 	 */
name|uint32_t
name|tiling_mode
decl_stmt|;
comment|/** 	 * Returned address bit 6 swizzling required for CPU access through 	 * mmap mapping. 	 */
name|uint32_t
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
name|uint64_t
name|aper_size
decl_stmt|;
comment|/** 	 * Available space in the aperture used by i915_gem_execbuffer, in 	 * bytes 	 */
name|uint64_t
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
name|uint32_t
name|crtc_id
decl_stmt|;
comment|/** pipe of requested CRTC **/
name|uint32_t
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
name|I915_MADV_PURGED_INTERNAL
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
name|uint32_t
name|handle
decl_stmt|;
comment|/* Advice: either the buffer will be needed again in the near future, 	 *         or wont be and could be discarded under memory pressure. 	 */
name|uint32_t
name|madv
decl_stmt|;
comment|/** Whether the backing store still exists. */
name|uint32_t
name|retained
decl_stmt|;
block|}
struct|;
end_struct

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
name|uint32_t
name|flags
decl_stmt|;
comment|/* source picture description */
name|uint32_t
name|bo_handle
decl_stmt|;
comment|/* stride values and offsets are in bytes, buffer relative */
name|uint16_t
name|stride_Y
decl_stmt|;
comment|/* stride for packed formats */
name|uint16_t
name|stride_UV
decl_stmt|;
name|uint32_t
name|offset_Y
decl_stmt|;
comment|/* offset for packet formats */
name|uint32_t
name|offset_U
decl_stmt|;
name|uint32_t
name|offset_V
decl_stmt|;
comment|/* in pixels */
name|uint16_t
name|src_width
decl_stmt|;
name|uint16_t
name|src_height
decl_stmt|;
comment|/* to compensate the scaling factors for partially covered surfaces */
name|uint16_t
name|src_scan_width
decl_stmt|;
name|uint16_t
name|src_scan_height
decl_stmt|;
comment|/* output crtc description */
name|uint32_t
name|crtc_id
decl_stmt|;
name|uint16_t
name|dst_x
decl_stmt|;
name|uint16_t
name|dst_y
decl_stmt|;
name|uint16_t
name|dst_width
decl_stmt|;
name|uint16_t
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
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|color_key
decl_stmt|;
name|int32_t
name|brightness
decl_stmt|;
name|uint32_t
name|contrast
decl_stmt|;
name|uint32_t
name|saturation
decl_stmt|;
name|uint32_t
name|gamma0
decl_stmt|;
name|uint32_t
name|gamma1
decl_stmt|;
name|uint32_t
name|gamma2
decl_stmt|;
name|uint32_t
name|gamma3
decl_stmt|;
name|uint32_t
name|gamma4
decl_stmt|;
name|uint32_t
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
name|uint32_t
name|plane_id
decl_stmt|;
name|uint32_t
name|min_value
decl_stmt|;
name|uint32_t
name|channel_mask
decl_stmt|;
name|uint32_t
name|max_value
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_context_create
block|{
comment|/*  output: id of new context*/
name|uint32_t
name|ctx_id
decl_stmt|;
name|uint32_t
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_i915_gem_context_destroy
block|{
name|uint32_t
name|ctx_id
decl_stmt|;
name|uint32_t
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I915_DRM_H_ */
end_comment

end_unit

