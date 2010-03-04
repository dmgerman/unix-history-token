begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 1998-2003 VIA Technologies, Inc. All Rights Reserved.  * Copyright 2001-2003 S3 Graphics, Inc. All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sub license,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the  * next paragraph) shall be included in all copies or substantial portions  * of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL  * VIA, S3 GRAPHICS, AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
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
name|_VIA_DRM_H_
end_ifndef

begin_define
define|#
directive|define
name|_VIA_DRM_H_
end_define

begin_comment
comment|/* WARNING: These defines must be the same as what the Xserver uses.  * if you change them, you must change the defines in the Xserver.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VIA_DEFINES_
end_ifndef

begin_define
define|#
directive|define
name|_VIA_DEFINES_
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__KERNEL__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_include
include|#
directive|include
file|"via_drmclient.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VIA_NR_SAREA_CLIPRECTS
value|8
end_define

begin_define
define|#
directive|define
name|VIA_NR_XVMC_PORTS
value|10
end_define

begin_define
define|#
directive|define
name|VIA_NR_XVMC_LOCKS
value|5
end_define

begin_define
define|#
directive|define
name|VIA_MAX_CACHELINE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|XVMCLOCKPTR
parameter_list|(
name|saPriv
parameter_list|,
name|lockNo
parameter_list|)
define|\
value|((volatile struct drm_hw_lock *)(((((unsigned long) (saPriv)->XvMCLockArea) + \ 				      (VIA_MAX_CACHELINE_SIZE - 1))&	\ 				     ~(VIA_MAX_CACHELINE_SIZE - 1)) +	\ 				    VIA_MAX_CACHELINE_SIZE*(lockNo)))
end_define

begin_comment
comment|/* Each region is a minimum of 64k, and there are at most 64 of them.  */
end_comment

begin_define
define|#
directive|define
name|VIA_NR_TEX_REGIONS
value|64
end_define

begin_define
define|#
directive|define
name|VIA_LOG_MIN_TEX_REGION_SIZE
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VIA_UPLOAD_TEX0IMAGE
value|0x1
end_define

begin_comment
comment|/* handled clientside */
end_comment

begin_define
define|#
directive|define
name|VIA_UPLOAD_TEX1IMAGE
value|0x2
end_define

begin_comment
comment|/* handled clientside */
end_comment

begin_define
define|#
directive|define
name|VIA_UPLOAD_CTX
value|0x4
end_define

begin_define
define|#
directive|define
name|VIA_UPLOAD_BUFFERS
value|0x8
end_define

begin_define
define|#
directive|define
name|VIA_UPLOAD_TEX0
value|0x10
end_define

begin_define
define|#
directive|define
name|VIA_UPLOAD_TEX1
value|0x20
end_define

begin_define
define|#
directive|define
name|VIA_UPLOAD_CLIPRECTS
value|0x40
end_define

begin_define
define|#
directive|define
name|VIA_UPLOAD_ALL
value|0xff
end_define

begin_comment
comment|/* VIA specific ioctls */
end_comment

begin_define
define|#
directive|define
name|DRM_VIA_ALLOCMEM
value|0x00
end_define

begin_define
define|#
directive|define
name|DRM_VIA_FREEMEM
value|0x01
end_define

begin_define
define|#
directive|define
name|DRM_VIA_AGP_INIT
value|0x02
end_define

begin_define
define|#
directive|define
name|DRM_VIA_FB_INIT
value|0x03
end_define

begin_define
define|#
directive|define
name|DRM_VIA_MAP_INIT
value|0x04
end_define

begin_define
define|#
directive|define
name|DRM_VIA_DEC_FUTEX
value|0x05
end_define

begin_define
define|#
directive|define
name|NOT_USED
end_define

begin_define
define|#
directive|define
name|DRM_VIA_DMA_INIT
value|0x07
end_define

begin_define
define|#
directive|define
name|DRM_VIA_CMDBUFFER
value|0x08
end_define

begin_define
define|#
directive|define
name|DRM_VIA_FLUSH
value|0x09
end_define

begin_define
define|#
directive|define
name|DRM_VIA_PCICMD
value|0x0a
end_define

begin_define
define|#
directive|define
name|DRM_VIA_CMDBUF_SIZE
value|0x0b
end_define

begin_define
define|#
directive|define
name|NOT_USED
end_define

begin_define
define|#
directive|define
name|DRM_VIA_WAIT_IRQ
value|0x0d
end_define

begin_define
define|#
directive|define
name|DRM_VIA_DMA_BLIT
value|0x0e
end_define

begin_define
define|#
directive|define
name|DRM_VIA_BLIT_SYNC
value|0x0f
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_VIA_ALLOCMEM
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_VIA_ALLOCMEM, drm_via_mem_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_VIA_FREEMEM
value|DRM_IOW( DRM_COMMAND_BASE + DRM_VIA_FREEMEM, drm_via_mem_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_VIA_AGP_INIT
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_VIA_AGP_INIT, drm_via_agp_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_VIA_FB_INIT
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_VIA_FB_INIT, drm_via_fb_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_VIA_MAP_INIT
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_VIA_MAP_INIT, drm_via_init_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_VIA_DEC_FUTEX
value|DRM_IOW( DRM_COMMAND_BASE + DRM_VIA_DEC_FUTEX, drm_via_futex_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_VIA_DMA_INIT
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_VIA_DMA_INIT, drm_via_dma_init_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_VIA_CMDBUFFER
value|DRM_IOW( DRM_COMMAND_BASE + DRM_VIA_CMDBUFFER, drm_via_cmdbuffer_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_VIA_FLUSH
value|DRM_IO(  DRM_COMMAND_BASE + DRM_VIA_FLUSH)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_VIA_PCICMD
value|DRM_IOW( DRM_COMMAND_BASE + DRM_VIA_PCICMD, drm_via_cmdbuffer_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_VIA_CMDBUF_SIZE
value|DRM_IOWR( DRM_COMMAND_BASE + DRM_VIA_CMDBUF_SIZE, \ 					    drm_via_cmdbuf_size_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_VIA_WAIT_IRQ
value|DRM_IOWR( DRM_COMMAND_BASE + DRM_VIA_WAIT_IRQ, drm_via_irqwait_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_VIA_DMA_BLIT
value|DRM_IOW(DRM_COMMAND_BASE + DRM_VIA_DMA_BLIT, drm_via_dmablit_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_VIA_BLIT_SYNC
value|DRM_IOW(DRM_COMMAND_BASE + DRM_VIA_BLIT_SYNC, drm_via_blitsync_t)
end_define

begin_comment
comment|/* Indices into buf.Setup where various bits of state are mirrored per  * context and per buffer.  These can be fired at the card as a unit,  * or in a piecewise fashion as required.  */
end_comment

begin_define
define|#
directive|define
name|VIA_TEX_SETUP_SIZE
value|8
end_define

begin_comment
comment|/* Flags for clear ioctl  */
end_comment

begin_define
define|#
directive|define
name|VIA_FRONT
value|0x1
end_define

begin_define
define|#
directive|define
name|VIA_BACK
value|0x2
end_define

begin_define
define|#
directive|define
name|VIA_DEPTH
value|0x4
end_define

begin_define
define|#
directive|define
name|VIA_STENCIL
value|0x8
end_define

begin_define
define|#
directive|define
name|VIA_MEM_VIDEO
value|0
end_define

begin_comment
comment|/* matches drm constant */
end_comment

begin_define
define|#
directive|define
name|VIA_MEM_AGP
value|1
end_define

begin_comment
comment|/* matches drm constant */
end_comment

begin_define
define|#
directive|define
name|VIA_MEM_SYSTEM
value|2
end_define

begin_define
define|#
directive|define
name|VIA_MEM_MIXED
value|3
end_define

begin_define
define|#
directive|define
name|VIA_MEM_UNKNOWN
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u32
name|offset
decl_stmt|;
name|u32
name|size
decl_stmt|;
block|}
name|drm_via_agp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u32
name|offset
decl_stmt|;
name|u32
name|size
decl_stmt|;
block|}
name|drm_via_fb_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u32
name|context
decl_stmt|;
name|u32
name|type
decl_stmt|;
name|u32
name|size
decl_stmt|;
name|unsigned
name|long
name|index
decl_stmt|;
name|unsigned
name|long
name|offset
decl_stmt|;
block|}
name|drm_via_mem_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_drm_via_init
block|{
enum|enum
block|{
name|VIA_INIT_MAP
init|=
literal|0x01
block|,
name|VIA_CLEANUP_MAP
init|=
literal|0x02
block|}
name|func
enum|;
name|unsigned
name|long
name|sarea_priv_offset
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
name|agpAddr
decl_stmt|;
block|}
name|drm_via_init_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_drm_via_futex
block|{
enum|enum
block|{
name|VIA_FUTEX_WAIT
init|=
literal|0x00
block|,
name|VIA_FUTEX_WAKE
init|=
literal|0X01
block|}
name|func
enum|;
name|u32
name|ms
decl_stmt|;
name|u32
name|lock
decl_stmt|;
name|u32
name|val
decl_stmt|;
block|}
name|drm_via_futex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_drm_via_dma_init
block|{
enum|enum
block|{
name|VIA_INIT_DMA
init|=
literal|0x01
block|,
name|VIA_CLEANUP_DMA
init|=
literal|0x02
block|,
name|VIA_DMA_INITIALIZED
init|=
literal|0x03
block|}
name|func
enum|;
name|unsigned
name|long
name|offset
decl_stmt|;
name|unsigned
name|long
name|size
decl_stmt|;
name|unsigned
name|long
name|reg_pause_addr
decl_stmt|;
block|}
name|drm_via_dma_init_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_drm_via_cmdbuffer
block|{
name|char
name|__user
modifier|*
name|buf
decl_stmt|;
name|unsigned
name|long
name|size
decl_stmt|;
block|}
name|drm_via_cmdbuffer_t
typedef|;
end_typedef

begin_comment
comment|/* Warning: If you change the SAREA structure you must change the Xserver  * structure as well */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_drm_via_tex_region
block|{
name|unsigned
name|char
name|next
decl_stmt|,
name|prev
decl_stmt|;
comment|/* indices to form a circular LRU  */
name|unsigned
name|char
name|inUse
decl_stmt|;
comment|/* owned by a client, or free? */
name|int
name|age
decl_stmt|;
comment|/* tracked by clients to update local LRU's */
block|}
name|drm_via_tex_region_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_drm_via_sarea
block|{
name|unsigned
name|int
name|dirty
decl_stmt|;
name|unsigned
name|int
name|nbox
decl_stmt|;
name|struct
name|drm_clip_rect
name|boxes
index|[
name|VIA_NR_SAREA_CLIPRECTS
index|]
decl_stmt|;
name|drm_via_tex_region_t
name|texList
index|[
name|VIA_NR_TEX_REGIONS
operator|+
literal|1
index|]
decl_stmt|;
name|int
name|texAge
decl_stmt|;
comment|/* last time texture was uploaded */
name|int
name|ctxOwner
decl_stmt|;
comment|/* last context to upload state */
name|int
name|vertexPrim
decl_stmt|;
comment|/* 	 * Below is for XvMC. 	 * We want the lock integers alone on, and aligned to, a cache line. 	 * Therefore this somewhat strange construct. 	 */
name|char
name|XvMCLockArea
index|[
name|VIA_MAX_CACHELINE_SIZE
operator|*
operator|(
name|VIA_NR_XVMC_LOCKS
operator|+
literal|1
operator|)
index|]
decl_stmt|;
name|unsigned
name|int
name|XvMCDisplaying
index|[
name|VIA_NR_XVMC_PORTS
index|]
decl_stmt|;
name|unsigned
name|int
name|XvMCSubPicOn
index|[
name|VIA_NR_XVMC_PORTS
index|]
decl_stmt|;
name|unsigned
name|int
name|XvMCCtxNoGrabbed
decl_stmt|;
comment|/* Last context to hold decoder */
comment|/* Used by the 3d driver only at this point, for pageflipping: 	 */
name|unsigned
name|int
name|pfCurrentOffset
decl_stmt|;
block|}
name|drm_via_sarea_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_drm_via_cmdbuf_size
block|{
enum|enum
block|{
name|VIA_CMDBUF_SPACE
init|=
literal|0x01
block|,
name|VIA_CMDBUF_LAG
init|=
literal|0x02
block|}
name|func
enum|;
name|int
name|wait
decl_stmt|;
name|u32
name|size
decl_stmt|;
block|}
name|drm_via_cmdbuf_size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|VIA_IRQ_ABSOLUTE
init|=
literal|0x0
block|,
name|VIA_IRQ_RELATIVE
init|=
literal|0x1
block|,
name|VIA_IRQ_SIGNAL
init|=
literal|0x10000000
block|,
name|VIA_IRQ_FORCE_SEQUENCE
init|=
literal|0x20000000
block|}
name|via_irq_seq_type_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VIA_IRQ_FLAGS_MASK
value|0xF0000000
end_define

begin_enum
enum|enum
name|drm_via_irqs
block|{
name|drm_via_irq_hqv0
init|=
literal|0
block|,
name|drm_via_irq_hqv1
block|,
name|drm_via_irq_dma0_dd
block|,
name|drm_via_irq_dma0_td
block|,
name|drm_via_irq_dma1_dd
block|,
name|drm_via_irq_dma1_td
block|,
name|drm_via_irq_num
block|}
enum|;
end_enum

begin_struct
struct|struct
name|drm_via_wait_irq_request
block|{
name|unsigned
name|irq
decl_stmt|;
name|via_irq_seq_type_t
name|type
decl_stmt|;
name|u32
name|sequence
decl_stmt|;
name|u32
name|signal
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
union|union
name|drm_via_irqwait
block|{
name|struct
name|drm_via_wait_irq_request
name|request
decl_stmt|;
name|struct
name|drm_wait_vblank_reply
name|reply
decl_stmt|;
block|}
name|drm_via_irqwait_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_via_blitsync
block|{
name|u32
name|sync_handle
decl_stmt|;
name|unsigned
name|engine
decl_stmt|;
block|}
name|drm_via_blitsync_t
typedef|;
end_typedef

begin_comment
comment|/* - * Below,"flags" is currently unused but will be used for possible future  * extensions like kernel space bounce buffers for bad alignments and  * blit engine busy-wait polling for better latency in the absence of  * interrupts.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|drm_via_dmablit
block|{
name|u32
name|num_lines
decl_stmt|;
name|u32
name|line_length
decl_stmt|;
name|u32
name|fb_addr
decl_stmt|;
name|u32
name|fb_stride
decl_stmt|;
name|unsigned
name|char
modifier|*
name|mem_addr
decl_stmt|;
name|u32
name|mem_stride
decl_stmt|;
name|u32
name|flags
decl_stmt|;
name|int
name|to_fb
decl_stmt|;
name|drm_via_blitsync_t
name|sync
decl_stmt|;
block|}
name|drm_via_dmablit_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VIA_DRM_H_ */
end_comment

end_unit

