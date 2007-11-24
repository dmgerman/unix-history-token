begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003 Tungsten Graphics, Inc., Cedar Park, Texas.  * All Rights Reserved.  *   * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the  * "Software"), to deal in the Software without restriction, including  * without limitation the rights to use, copy, modify, merge, publish,  * distribute, sub license, and/or sell copies of the Software, and to  * permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *   * The above copyright notice and this permission notice (including the  * next paragraph) shall be included in all copies or substantial portions  * of the Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.  * IN NO EVENT SHALL TUNGSTEN GRAPHICS AND/OR ITS SUPPLIERS BE LIABLE FOR  * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE  * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  *   */
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
file|"dev/drm/drm.h"
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
name|drm_tex_region_t
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
block|}
name|drm_i915_sarea_t
typedef|;
end_typedef

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

begin_comment
comment|/* Allow drivers to submit batchbuffers directly to hardware, relying  * on the security mechanisms provided by hardware.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_drm_i915_batchbuffer
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
name|drm_clip_rect_t
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
name|drm_clip_rect_t
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I915_DRM_H_ */
end_comment

end_unit

