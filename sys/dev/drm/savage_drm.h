begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* savage_drm.h -- Public header for the savage driver  *  * Copyright 2004  Felix Kuehling  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sub license,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the  * next paragraph) shall be included in all copies or substantial portions  * of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NON-INFRINGEMENT. IN NO EVENT SHALL FELIX KUEHLING BE LIABLE FOR  * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF  * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION  * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  */
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
name|__SAVAGE_DRM_H__
end_ifndef

begin_define
define|#
directive|define
name|__SAVAGE_DRM_H__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__SAVAGE_SAREA_DEFINES__
end_ifndef

begin_define
define|#
directive|define
name|__SAVAGE_SAREA_DEFINES__
end_define

begin_comment
comment|/* 2 heaps (1 for card, 1 for agp), each divided into upto 128  * regions, subject to a minimum region size of (1<<16) == 64k.  *  * Clients may subdivide regions internally, but when sharing between  * clients, the region size is the minimum granularity.  */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_CARD_HEAP
value|0
end_define

begin_define
define|#
directive|define
name|SAVAGE_AGP_HEAP
value|1
end_define

begin_define
define|#
directive|define
name|SAVAGE_NR_TEX_HEAPS
value|2
end_define

begin_define
define|#
directive|define
name|SAVAGE_NR_TEX_REGIONS
value|16
end_define

begin_define
define|#
directive|define
name|SAVAGE_LOG_MIN_TEX_REGION_SIZE
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SAVAGE_SAREA_DEFINES__ */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_drm_savage_sarea
block|{
comment|/* LRU lists for texture memory in agp space and on the card. 	 */
name|drm_tex_region_t
name|texList
index|[
name|SAVAGE_NR_TEX_HEAPS
index|]
index|[
name|SAVAGE_NR_TEX_REGIONS
operator|+
literal|1
index|]
decl_stmt|;
name|unsigned
name|int
name|texAge
index|[
name|SAVAGE_NR_TEX_HEAPS
index|]
decl_stmt|;
comment|/* Mechanism to validate card state. 	 */
name|int
name|ctxOwner
decl_stmt|;
block|}
name|drm_savage_sarea_t
operator|,
typedef|*
name|drm_savage_sarea_ptr
typedef|;
end_typedef

begin_comment
comment|/* Savage-specific ioctls  */
end_comment

begin_define
define|#
directive|define
name|DRM_SAVAGE_BCI_INIT
value|0x00
end_define

begin_define
define|#
directive|define
name|DRM_SAVAGE_BCI_CMDBUF
value|0x01
end_define

begin_define
define|#
directive|define
name|DRM_SAVAGE_BCI_EVENT_EMIT
value|0x02
end_define

begin_define
define|#
directive|define
name|DRM_SAVAGE_BCI_EVENT_WAIT
value|0x03
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_SAVAGE_INIT
value|DRM_IOW( DRM_COMMAND_BASE + DRM_SAVAGE_BCI_INIT, drm_savage_init_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_SAVAGE_CMDBUF
value|DRM_IOW( DRM_COMMAND_BASE + DRM_SAVAGE_BCI_CMDBUF, drm_savage_cmdbuf_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_SAVAGE_EVENT_EMIT
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_SAVAGE_BCI_EVENT_EMIT, drm_savage_event_emit_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_SAVAGE_EVENT_WAIT
value|DRM_IOW( DRM_COMMAND_BASE + DRM_SAVAGE_BCI_EVENT_WAIT, drm_savage_event_wait_t)
end_define

begin_define
define|#
directive|define
name|SAVAGE_DMA_PCI
value|1
end_define

begin_define
define|#
directive|define
name|SAVAGE_DMA_AGP
value|3
end_define

begin_typedef
typedef|typedef
struct|struct
name|drm_savage_init
block|{
enum|enum
block|{
name|SAVAGE_INIT_BCI
init|=
literal|1
block|,
name|SAVAGE_CLEANUP_BCI
init|=
literal|2
block|}
name|func
enum|;
name|unsigned
name|int
name|sarea_priv_offset
decl_stmt|;
comment|/* some parameters */
name|unsigned
name|int
name|cob_size
decl_stmt|;
name|unsigned
name|int
name|bci_threshold_lo
decl_stmt|,
name|bci_threshold_hi
decl_stmt|;
name|unsigned
name|int
name|dma_type
decl_stmt|;
comment|/* frame buffer layout */
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
comment|/* local textures */
name|unsigned
name|int
name|texture_offset
decl_stmt|;
name|unsigned
name|int
name|texture_size
decl_stmt|;
comment|/* physical locations of non-permanent maps */
name|unsigned
name|long
name|status_offset
decl_stmt|;
name|unsigned
name|long
name|buffers_offset
decl_stmt|;
name|unsigned
name|long
name|agp_textures_offset
decl_stmt|;
name|unsigned
name|long
name|cmd_dma_offset
decl_stmt|;
block|}
name|drm_savage_init_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|drm_savage_cmd_header
name|drm_savage_cmd_header_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_savage_cmdbuf
block|{
comment|/* command buffer in client's address space */
name|drm_savage_cmd_header_t
name|__user
modifier|*
name|cmd_addr
decl_stmt|;
name|unsigned
name|int
name|size
decl_stmt|;
comment|/* size of the command buffer in 64bit units */
name|unsigned
name|int
name|dma_idx
decl_stmt|;
comment|/* DMA buffer index to use */
name|int
name|discard
decl_stmt|;
comment|/* discard DMA buffer when done */
comment|/* vertex buffer in client's address space */
name|unsigned
name|int
name|__user
modifier|*
name|vb_addr
decl_stmt|;
name|unsigned
name|int
name|vb_size
decl_stmt|;
comment|/* size of client vertex buffer in bytes */
name|unsigned
name|int
name|vb_stride
decl_stmt|;
comment|/* stride of vertices in 32bit words */
comment|/* boxes in client's address space */
name|drm_clip_rect_t
name|__user
modifier|*
name|box_addr
decl_stmt|;
name|unsigned
name|int
name|nbox
decl_stmt|;
comment|/* number of clipping boxes */
block|}
name|drm_savage_cmdbuf_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SAVAGE_WAIT_2D
value|0x1
end_define

begin_comment
comment|/* wait for 2D idle before updating event tag */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_WAIT_3D
value|0x2
end_define

begin_comment
comment|/* wait for 3D idle before updating event tag */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_WAIT_IRQ
value|0x4
end_define

begin_comment
comment|/* emit or wait for IRQ, not implemented yet */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|drm_savage_event
block|{
name|unsigned
name|int
name|count
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
block|}
name|drm_savage_event_emit_t
operator|,
name|drm_savage_event_wait_t
typedef|;
end_typedef

begin_comment
comment|/* Commands for the cmdbuf ioctl  */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_CMD_STATE
value|0
end_define

begin_comment
comment|/* a range of state registers */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_CMD_DMA_PRIM
value|1
end_define

begin_comment
comment|/* vertices from DMA buffer */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_CMD_VB_PRIM
value|2
end_define

begin_comment
comment|/* vertices from client vertex buffer */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_CMD_DMA_IDX
value|3
end_define

begin_comment
comment|/* indexed vertices from DMA buffer */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_CMD_VB_IDX
value|4
end_define

begin_comment
comment|/* indexed vertices client vertex buffer */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_CMD_CLEAR
value|5
end_define

begin_comment
comment|/* clear buffers */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_CMD_SWAP
value|6
end_define

begin_comment
comment|/* swap buffers */
end_comment

begin_comment
comment|/* Primitive types */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_PRIM_TRILIST
value|0
end_define

begin_comment
comment|/* triangle list */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_PRIM_TRISTRIP
value|1
end_define

begin_comment
comment|/* triangle strip */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_PRIM_TRIFAN
value|2
end_define

begin_comment
comment|/* triangle fan */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_PRIM_TRILIST_201
value|3
end_define

begin_comment
comment|/* reorder verts for correct flat 				    * shading on s3d */
end_comment

begin_comment
comment|/* Skip flags (vertex format)  */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_SKIP_Z
value|0x01
end_define

begin_define
define|#
directive|define
name|SAVAGE_SKIP_W
value|0x02
end_define

begin_define
define|#
directive|define
name|SAVAGE_SKIP_C0
value|0x04
end_define

begin_define
define|#
directive|define
name|SAVAGE_SKIP_C1
value|0x08
end_define

begin_define
define|#
directive|define
name|SAVAGE_SKIP_S0
value|0x10
end_define

begin_define
define|#
directive|define
name|SAVAGE_SKIP_T0
value|0x20
end_define

begin_define
define|#
directive|define
name|SAVAGE_SKIP_ST0
value|0x30
end_define

begin_define
define|#
directive|define
name|SAVAGE_SKIP_S1
value|0x40
end_define

begin_define
define|#
directive|define
name|SAVAGE_SKIP_T1
value|0x80
end_define

begin_define
define|#
directive|define
name|SAVAGE_SKIP_ST1
value|0xc0
end_define

begin_define
define|#
directive|define
name|SAVAGE_SKIP_ALL_S3D
value|0x3f
end_define

begin_define
define|#
directive|define
name|SAVAGE_SKIP_ALL_S4
value|0xff
end_define

begin_comment
comment|/* Buffer names for clear command  */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_FRONT
value|0x1
end_define

begin_define
define|#
directive|define
name|SAVAGE_BACK
value|0x2
end_define

begin_define
define|#
directive|define
name|SAVAGE_DEPTH
value|0x4
end_define

begin_comment
comment|/* 64-bit command header  */
end_comment

begin_union
union|union
name|drm_savage_cmd_header
block|{
struct|struct
block|{
name|unsigned
name|char
name|cmd
decl_stmt|;
comment|/* command */
name|unsigned
name|char
name|pad0
decl_stmt|;
name|unsigned
name|short
name|pad1
decl_stmt|;
name|unsigned
name|short
name|pad2
decl_stmt|;
name|unsigned
name|short
name|pad3
decl_stmt|;
block|}
name|cmd
struct|;
comment|/* generic */
struct|struct
block|{
name|unsigned
name|char
name|cmd
decl_stmt|;
name|unsigned
name|char
name|global
decl_stmt|;
comment|/* need idle engine? */
name|unsigned
name|short
name|count
decl_stmt|;
comment|/* number of consecutive registers */
name|unsigned
name|short
name|start
decl_stmt|;
comment|/* first register */
name|unsigned
name|short
name|pad3
decl_stmt|;
block|}
name|state
struct|;
comment|/* SAVAGE_CMD_STATE */
struct|struct
block|{
name|unsigned
name|char
name|cmd
decl_stmt|;
name|unsigned
name|char
name|prim
decl_stmt|;
comment|/* primitive type */
name|unsigned
name|short
name|skip
decl_stmt|;
comment|/* vertex format (skip flags) */
name|unsigned
name|short
name|count
decl_stmt|;
comment|/* number of vertices */
name|unsigned
name|short
name|start
decl_stmt|;
comment|/* first vertex in DMA/vertex buffer */
block|}
name|prim
struct|;
comment|/* SAVAGE_CMD_DMA_PRIM, SAVAGE_CMD_VB_PRIM */
struct|struct
block|{
name|unsigned
name|char
name|cmd
decl_stmt|;
name|unsigned
name|char
name|prim
decl_stmt|;
name|unsigned
name|short
name|skip
decl_stmt|;
name|unsigned
name|short
name|count
decl_stmt|;
comment|/* number of indices that follow */
name|unsigned
name|short
name|pad3
decl_stmt|;
block|}
name|idx
struct|;
comment|/* SAVAGE_CMD_DMA_IDX, SAVAGE_CMD_VB_IDX */
struct|struct
block|{
name|unsigned
name|char
name|cmd
decl_stmt|;
name|unsigned
name|char
name|pad0
decl_stmt|;
name|unsigned
name|short
name|pad1
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
block|}
name|clear0
struct|;
comment|/* SAVAGE_CMD_CLEAR */
struct|struct
block|{
name|unsigned
name|int
name|mask
decl_stmt|;
name|unsigned
name|int
name|value
decl_stmt|;
block|}
name|clear1
struct|;
comment|/* SAVAGE_CMD_CLEAR data */
block|}
union|;
end_union

begin_endif
endif|#
directive|endif
end_endif

end_unit

