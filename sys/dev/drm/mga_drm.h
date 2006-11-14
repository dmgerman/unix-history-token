begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mga_drm.h -- Public header for the Matrox g200/g400 driver -*- linux-c -*-  * Created: Tue Jan 25 01:50:01 1999 by jhartmann@precisioninsight.com  *  * Copyright 1999 Precision Insight, Inc., Cedar Park, Texas.  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All rights reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Jeff Hartmann<jhartmann@valinux.com>  *    Keith Whitwell<keith@tungstengraphics.com>  *  * Rewritten by:  *    Gareth Hughes<gareth@valinux.com>  */
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
name|__MGA_DRM_H__
end_ifndef

begin_define
define|#
directive|define
name|__MGA_DRM_H__
end_define

begin_comment
comment|/* WARNING: If you change any of these defines, make sure to change the  * defines in the Xserver file (mga_sarea.h)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MGA_SAREA_DEFINES__
end_ifndef

begin_define
define|#
directive|define
name|__MGA_SAREA_DEFINES__
end_define

begin_comment
comment|/* WARP pipe flags  */
end_comment

begin_define
define|#
directive|define
name|MGA_F
value|0x1
end_define

begin_comment
comment|/* fog */
end_comment

begin_define
define|#
directive|define
name|MGA_A
value|0x2
end_define

begin_comment
comment|/* alpha */
end_comment

begin_define
define|#
directive|define
name|MGA_S
value|0x4
end_define

begin_comment
comment|/* specular */
end_comment

begin_define
define|#
directive|define
name|MGA_T2
value|0x8
end_define

begin_comment
comment|/* multitexture */
end_comment

begin_define
define|#
directive|define
name|MGA_WARP_TGZ
value|0
end_define

begin_define
define|#
directive|define
name|MGA_WARP_TGZF
value|(MGA_F)
end_define

begin_define
define|#
directive|define
name|MGA_WARP_TGZA
value|(MGA_A)
end_define

begin_define
define|#
directive|define
name|MGA_WARP_TGZAF
value|(MGA_F|MGA_A)
end_define

begin_define
define|#
directive|define
name|MGA_WARP_TGZS
value|(MGA_S)
end_define

begin_define
define|#
directive|define
name|MGA_WARP_TGZSF
value|(MGA_S|MGA_F)
end_define

begin_define
define|#
directive|define
name|MGA_WARP_TGZSA
value|(MGA_S|MGA_A)
end_define

begin_define
define|#
directive|define
name|MGA_WARP_TGZSAF
value|(MGA_S|MGA_F|MGA_A)
end_define

begin_define
define|#
directive|define
name|MGA_WARP_T2GZ
value|(MGA_T2)
end_define

begin_define
define|#
directive|define
name|MGA_WARP_T2GZF
value|(MGA_T2|MGA_F)
end_define

begin_define
define|#
directive|define
name|MGA_WARP_T2GZA
value|(MGA_T2|MGA_A)
end_define

begin_define
define|#
directive|define
name|MGA_WARP_T2GZAF
value|(MGA_T2|MGA_A|MGA_F)
end_define

begin_define
define|#
directive|define
name|MGA_WARP_T2GZS
value|(MGA_T2|MGA_S)
end_define

begin_define
define|#
directive|define
name|MGA_WARP_T2GZSF
value|(MGA_T2|MGA_S|MGA_F)
end_define

begin_define
define|#
directive|define
name|MGA_WARP_T2GZSA
value|(MGA_T2|MGA_S|MGA_A)
end_define

begin_define
define|#
directive|define
name|MGA_WARP_T2GZSAF
value|(MGA_T2|MGA_S|MGA_F|MGA_A)
end_define

begin_define
define|#
directive|define
name|MGA_MAX_G200_PIPES
value|8
end_define

begin_comment
comment|/* no multitex */
end_comment

begin_define
define|#
directive|define
name|MGA_MAX_G400_PIPES
value|16
end_define

begin_define
define|#
directive|define
name|MGA_MAX_WARP_PIPES
value|MGA_MAX_G400_PIPES
end_define

begin_define
define|#
directive|define
name|MGA_WARP_UCODE_SIZE
value|32768
end_define

begin_comment
comment|/* in bytes */
end_comment

begin_define
define|#
directive|define
name|MGA_CARD_TYPE_G200
value|1
end_define

begin_define
define|#
directive|define
name|MGA_CARD_TYPE_G400
value|2
end_define

begin_define
define|#
directive|define
name|MGA_CARD_TYPE_G450
value|3
end_define

begin_comment
comment|/* not currently used */
end_comment

begin_define
define|#
directive|define
name|MGA_CARD_TYPE_G550
value|4
end_define

begin_define
define|#
directive|define
name|MGA_FRONT
value|0x1
end_define

begin_define
define|#
directive|define
name|MGA_BACK
value|0x2
end_define

begin_define
define|#
directive|define
name|MGA_DEPTH
value|0x4
end_define

begin_comment
comment|/* What needs to be changed for the current vertex dma buffer?  */
end_comment

begin_define
define|#
directive|define
name|MGA_UPLOAD_CONTEXT
value|0x1
end_define

begin_define
define|#
directive|define
name|MGA_UPLOAD_TEX0
value|0x2
end_define

begin_define
define|#
directive|define
name|MGA_UPLOAD_TEX1
value|0x4
end_define

begin_define
define|#
directive|define
name|MGA_UPLOAD_PIPE
value|0x8
end_define

begin_define
define|#
directive|define
name|MGA_UPLOAD_TEX0IMAGE
value|0x10
end_define

begin_comment
comment|/* handled client-side */
end_comment

begin_define
define|#
directive|define
name|MGA_UPLOAD_TEX1IMAGE
value|0x20
end_define

begin_comment
comment|/* handled client-side */
end_comment

begin_define
define|#
directive|define
name|MGA_UPLOAD_2D
value|0x40
end_define

begin_define
define|#
directive|define
name|MGA_WAIT_AGE
value|0x80
end_define

begin_comment
comment|/* handled client-side */
end_comment

begin_define
define|#
directive|define
name|MGA_UPLOAD_CLIPRECTS
value|0x100
end_define

begin_comment
comment|/* handled client-side */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|MGA_DMA_FLUSH
value|0x200
end_define

begin_comment
comment|/* set when someone gets the lock 					   quiescent */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 32 buffers of 64k each, total 2 meg.  */
end_comment

begin_define
define|#
directive|define
name|MGA_BUFFER_SIZE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|MGA_NUM_BUFFERS
value|128
end_define

begin_comment
comment|/* Keep these small for testing.  */
end_comment

begin_define
define|#
directive|define
name|MGA_NR_SAREA_CLIPRECTS
value|8
end_define

begin_comment
comment|/* 2 heaps (1 for card, 1 for agp), each divided into upto 128  * regions, subject to a minimum region size of (1<<16) == 64k.  *  * Clients may subdivide regions internally, but when sharing between  * clients, the region size is the minimum granularity.  */
end_comment

begin_define
define|#
directive|define
name|MGA_CARD_HEAP
value|0
end_define

begin_define
define|#
directive|define
name|MGA_AGP_HEAP
value|1
end_define

begin_define
define|#
directive|define
name|MGA_NR_TEX_HEAPS
value|2
end_define

begin_define
define|#
directive|define
name|MGA_NR_TEX_REGIONS
value|16
end_define

begin_define
define|#
directive|define
name|MGA_LOG_MIN_TEX_REGION_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|DRM_MGA_IDLE_RETRY
value|2048
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MGA_SAREA_DEFINES__ */
end_comment

begin_comment
comment|/* Setup registers for 3D context  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|dstorg
decl_stmt|;
name|unsigned
name|int
name|maccess
decl_stmt|;
name|unsigned
name|int
name|plnwt
decl_stmt|;
name|unsigned
name|int
name|dwgctl
decl_stmt|;
name|unsigned
name|int
name|alphactrl
decl_stmt|;
name|unsigned
name|int
name|fogcolor
decl_stmt|;
name|unsigned
name|int
name|wflag
decl_stmt|;
name|unsigned
name|int
name|tdualstage0
decl_stmt|;
name|unsigned
name|int
name|tdualstage1
decl_stmt|;
name|unsigned
name|int
name|fcol
decl_stmt|;
name|unsigned
name|int
name|stencil
decl_stmt|;
name|unsigned
name|int
name|stencilctl
decl_stmt|;
block|}
name|drm_mga_context_regs_t
typedef|;
end_typedef

begin_comment
comment|/* Setup registers for 2D, X server  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|pitch
decl_stmt|;
block|}
name|drm_mga_server_regs_t
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
name|texctl
decl_stmt|;
name|unsigned
name|int
name|texctl2
decl_stmt|;
name|unsigned
name|int
name|texfilter
decl_stmt|;
name|unsigned
name|int
name|texbordercol
decl_stmt|;
name|unsigned
name|int
name|texorg
decl_stmt|;
name|unsigned
name|int
name|texwidth
decl_stmt|;
name|unsigned
name|int
name|texheight
decl_stmt|;
name|unsigned
name|int
name|texorg1
decl_stmt|;
name|unsigned
name|int
name|texorg2
decl_stmt|;
name|unsigned
name|int
name|texorg3
decl_stmt|;
name|unsigned
name|int
name|texorg4
decl_stmt|;
block|}
name|drm_mga_texture_regs_t
typedef|;
end_typedef

begin_comment
comment|/* General aging mechanism  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|head
decl_stmt|;
comment|/* Position of head pointer          */
name|unsigned
name|int
name|wrap
decl_stmt|;
comment|/* Primary DMA wrap count            */
block|}
name|drm_mga_age_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_drm_mga_sarea
block|{
comment|/* The channel for communication of state information to the kernel 	 * on firing a vertex dma buffer. 	 */
name|drm_mga_context_regs_t
name|context_state
decl_stmt|;
name|drm_mga_server_regs_t
name|server_state
decl_stmt|;
name|drm_mga_texture_regs_t
name|tex_state
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|int
name|warp_pipe
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
name|MGA_NR_SAREA_CLIPRECTS
index|]
decl_stmt|;
name|unsigned
name|int
name|nbox
decl_stmt|;
comment|/* Information about the most recently used 3d drawable.  The 	 * client fills in the req_* fields, the server fills in the 	 * exported_ fields and puts the cliprects into boxes, above. 	 * 	 * The client clears the exported_drawable field before 	 * clobbering the boxes data. 	 */
name|unsigned
name|int
name|req_drawable
decl_stmt|;
comment|/* the X drawable id */
name|unsigned
name|int
name|req_draw_buffer
decl_stmt|;
comment|/* MGA_FRONT or MGA_BACK */
name|unsigned
name|int
name|exported_drawable
decl_stmt|;
name|unsigned
name|int
name|exported_index
decl_stmt|;
name|unsigned
name|int
name|exported_stamp
decl_stmt|;
name|unsigned
name|int
name|exported_buffers
decl_stmt|;
name|unsigned
name|int
name|exported_nfront
decl_stmt|;
name|unsigned
name|int
name|exported_nback
decl_stmt|;
name|int
name|exported_back_x
decl_stmt|,
name|exported_front_x
decl_stmt|,
name|exported_w
decl_stmt|;
name|int
name|exported_back_y
decl_stmt|,
name|exported_front_y
decl_stmt|,
name|exported_h
decl_stmt|;
name|drm_clip_rect_t
name|exported_boxes
index|[
name|MGA_NR_SAREA_CLIPRECTS
index|]
decl_stmt|;
comment|/* Counters for aging textures and for client-side throttling. 	 */
name|unsigned
name|int
name|status
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|int
name|last_wrap
decl_stmt|;
name|drm_mga_age_t
name|last_frame
decl_stmt|;
name|unsigned
name|int
name|last_enqueue
decl_stmt|;
comment|/* last time a buffer was enqueued */
name|unsigned
name|int
name|last_dispatch
decl_stmt|;
comment|/* age of the most recently dispatched buffer */
name|unsigned
name|int
name|last_quiescent
decl_stmt|;
comment|/*  */
comment|/* LRU lists for texture memory in agp space and on the card. 	 */
name|drm_tex_region_t
name|texList
index|[
name|MGA_NR_TEX_HEAPS
index|]
index|[
name|MGA_NR_TEX_REGIONS
operator|+
literal|1
index|]
decl_stmt|;
name|unsigned
name|int
name|texAge
index|[
name|MGA_NR_TEX_HEAPS
index|]
decl_stmt|;
comment|/* Mechanism to validate card state. 	 */
name|int
name|ctxOwner
decl_stmt|;
block|}
name|drm_mga_sarea_t
typedef|;
end_typedef

begin_comment
comment|/* MGA specific ioctls  * The device specific ioctl range is 0x40 to 0x79.  */
end_comment

begin_define
define|#
directive|define
name|DRM_MGA_INIT
value|0x00
end_define

begin_define
define|#
directive|define
name|DRM_MGA_FLUSH
value|0x01
end_define

begin_define
define|#
directive|define
name|DRM_MGA_RESET
value|0x02
end_define

begin_define
define|#
directive|define
name|DRM_MGA_SWAP
value|0x03
end_define

begin_define
define|#
directive|define
name|DRM_MGA_CLEAR
value|0x04
end_define

begin_define
define|#
directive|define
name|DRM_MGA_VERTEX
value|0x05
end_define

begin_define
define|#
directive|define
name|DRM_MGA_INDICES
value|0x06
end_define

begin_define
define|#
directive|define
name|DRM_MGA_ILOAD
value|0x07
end_define

begin_define
define|#
directive|define
name|DRM_MGA_BLIT
value|0x08
end_define

begin_define
define|#
directive|define
name|DRM_MGA_GETPARAM
value|0x09
end_define

begin_comment
comment|/* 3.2:  * ioctls for operating on fences.  */
end_comment

begin_define
define|#
directive|define
name|DRM_MGA_SET_FENCE
value|0x0a
end_define

begin_define
define|#
directive|define
name|DRM_MGA_WAIT_FENCE
value|0x0b
end_define

begin_define
define|#
directive|define
name|DRM_MGA_DMA_BOOTSTRAP
value|0x0c
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MGA_INIT
value|DRM_IOW( DRM_COMMAND_BASE + DRM_MGA_INIT, drm_mga_init_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MGA_FLUSH
value|DRM_IOW( DRM_COMMAND_BASE + DRM_MGA_FLUSH, drm_lock_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MGA_RESET
value|DRM_IO(  DRM_COMMAND_BASE + DRM_MGA_RESET)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MGA_SWAP
value|DRM_IO(  DRM_COMMAND_BASE + DRM_MGA_SWAP)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MGA_CLEAR
value|DRM_IOW( DRM_COMMAND_BASE + DRM_MGA_CLEAR, drm_mga_clear_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MGA_VERTEX
value|DRM_IOW( DRM_COMMAND_BASE + DRM_MGA_VERTEX, drm_mga_vertex_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MGA_INDICES
value|DRM_IOW( DRM_COMMAND_BASE + DRM_MGA_INDICES, drm_mga_indices_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MGA_ILOAD
value|DRM_IOW( DRM_COMMAND_BASE + DRM_MGA_ILOAD, drm_mga_iload_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MGA_BLIT
value|DRM_IOW( DRM_COMMAND_BASE + DRM_MGA_BLIT, drm_mga_blit_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MGA_GETPARAM
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_MGA_GETPARAM, drm_mga_getparam_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MGA_SET_FENCE
value|DRM_IOW( DRM_COMMAND_BASE + DRM_MGA_SET_FENCE, uint32_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MGA_WAIT_FENCE
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_MGA_WAIT_FENCE, uint32_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MGA_DMA_BOOTSTRAP
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_MGA_DMA_BOOTSTRAP, drm_mga_dma_bootstrap_t)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_drm_mga_warp_index
block|{
name|int
name|installed
decl_stmt|;
name|unsigned
name|long
name|phys_addr
decl_stmt|;
name|int
name|size
decl_stmt|;
block|}
name|drm_mga_warp_index_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_mga_init
block|{
enum|enum
block|{
name|MGA_INIT_DMA
init|=
literal|0x01
block|,
name|MGA_CLEANUP_DMA
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
name|chipset
decl_stmt|;
name|int
name|sgram
decl_stmt|;
name|unsigned
name|int
name|maccess
decl_stmt|;
name|unsigned
name|int
name|fb_cpp
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
name|depth_cpp
decl_stmt|;
name|unsigned
name|int
name|depth_offset
decl_stmt|,
name|depth_pitch
decl_stmt|;
name|unsigned
name|int
name|texture_offset
index|[
name|MGA_NR_TEX_HEAPS
index|]
decl_stmt|;
name|unsigned
name|int
name|texture_size
index|[
name|MGA_NR_TEX_HEAPS
index|]
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
name|status_offset
decl_stmt|;
name|unsigned
name|long
name|warp_offset
decl_stmt|;
name|unsigned
name|long
name|primary_offset
decl_stmt|;
name|unsigned
name|long
name|buffers_offset
decl_stmt|;
block|}
name|drm_mga_init_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_mga_dma_bootstrap
block|{
comment|/** 	 * \name AGP texture region 	 *  	 * On return from the DRM_MGA_DMA_BOOTSTRAP ioctl, these fields will 	 * be filled in with the actual AGP texture settings. 	 *  	 * \warning 	 * If these fields are non-zero, but dma_mga_dma_bootstrap::agp_mode 	 * is zero, it means that PCI memory (most likely through the use of 	 * an IOMMU) is being used for "AGP" textures. 	 */
comment|/*@{*/
name|unsigned
name|long
name|texture_handle
decl_stmt|;
comment|/**< Handle used to map AGP textures. */
name|uint32_t
name|texture_size
decl_stmt|;
comment|/**< Size of the AGP texture region. */
comment|/*@}*/
comment|/** 	 * Requested size of the primary DMA region. 	 *  	 * On return from the DRM_MGA_DMA_BOOTSTRAP ioctl, this field will be 	 * filled in with the actual AGP mode.  If AGP was not available 	 */
name|uint32_t
name|primary_size
decl_stmt|;
comment|/** 	 * Requested number of secondary DMA buffers. 	 *  	 * On return from the DRM_MGA_DMA_BOOTSTRAP ioctl, this field will be 	 * filled in with the actual number of secondary DMA buffers 	 * allocated.  Particularly when PCI DMA is used, this may be 	 * (subtantially) less than the number requested. 	 */
name|uint32_t
name|secondary_bin_count
decl_stmt|;
comment|/** 	 * Requested size of each secondary DMA buffer. 	 *  	 * While the kernel \b is free to reduce 	 * dma_mga_dma_bootstrap::secondary_bin_count, it is \b not allowed 	 * to reduce dma_mga_dma_bootstrap::secondary_bin_size. 	 */
name|uint32_t
name|secondary_bin_size
decl_stmt|;
comment|/** 	 * Bit-wise mask of AGPSTAT2_* values.  Currently only \c AGPSTAT2_1X, 	 * \c AGPSTAT2_2X, and \c AGPSTAT2_4X are supported.  If this value is 	 * zero, it means that PCI DMA should be used, even if AGP is 	 * possible. 	 *  	 * On return from the DRM_MGA_DMA_BOOTSTRAP ioctl, this field will be 	 * filled in with the actual AGP mode.  If AGP was not available 	 * (i.e., PCI DMA was used), this value will be zero. 	 */
name|uint32_t
name|agp_mode
decl_stmt|;
comment|/** 	 * Desired AGP GART size, measured in megabytes. 	 */
name|uint8_t
name|agp_size
decl_stmt|;
block|}
name|drm_mga_dma_bootstrap_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_mga_clear
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
block|}
name|drm_mga_clear_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_mga_vertex
block|{
name|int
name|idx
decl_stmt|;
comment|/* buffer to queue */
name|int
name|used
decl_stmt|;
comment|/* bytes in use */
name|int
name|discard
decl_stmt|;
comment|/* client finished with buffer?  */
block|}
name|drm_mga_vertex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_mga_indices
block|{
name|int
name|idx
decl_stmt|;
comment|/* buffer to queue */
name|unsigned
name|int
name|start
decl_stmt|;
name|unsigned
name|int
name|end
decl_stmt|;
name|int
name|discard
decl_stmt|;
comment|/* client finished with buffer?  */
block|}
name|drm_mga_indices_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_mga_iload
block|{
name|int
name|idx
decl_stmt|;
name|unsigned
name|int
name|dstorg
decl_stmt|;
name|unsigned
name|int
name|length
decl_stmt|;
block|}
name|drm_mga_iload_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_drm_mga_blit
block|{
name|unsigned
name|int
name|planemask
decl_stmt|;
name|unsigned
name|int
name|srcorg
decl_stmt|;
name|unsigned
name|int
name|dstorg
decl_stmt|;
name|int
name|src_pitch
decl_stmt|,
name|dst_pitch
decl_stmt|;
name|int
name|delta_sx
decl_stmt|,
name|delta_sy
decl_stmt|;
name|int
name|delta_dx
decl_stmt|,
name|delta_dy
decl_stmt|;
name|int
name|height
decl_stmt|,
name|ydir
decl_stmt|;
comment|/* flip image vertically */
name|int
name|source_pitch
decl_stmt|,
name|dest_pitch
decl_stmt|;
block|}
name|drm_mga_blit_t
typedef|;
end_typedef

begin_comment
comment|/* 3.1: An ioctl to get parameters that aren't available to the 3d  * client any other way.  */
end_comment

begin_define
define|#
directive|define
name|MGA_PARAM_IRQ_NR
value|1
end_define

begin_comment
comment|/* 3.2: Query the actual card type.  The DDX only distinguishes between  * G200 chips and non-G200 chips, which it calls G400.  It turns out that  * there are some very sublte differences between the G4x0 chips and the G550  * chips.  Using this parameter query, a client-side driver can detect the  * difference between a G4x0 and a G550.  */
end_comment

begin_define
define|#
directive|define
name|MGA_PARAM_CARD_TYPE
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|drm_mga_getparam
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
name|drm_mga_getparam_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

