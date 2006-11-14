begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* savage_drv.h -- Private header for the savage driver */
end_comment

begin_comment
comment|/*-  * Copyright 2004  Felix Kuehling  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sub license,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the  * next paragraph) shall be included in all copies or substantial portions  * of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NON-INFRINGEMENT. IN NO EVENT SHALL FELIX KUEHLING BE LIABLE FOR  * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF  * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION  * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  */
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
name|__SAVAGE_DRV_H__
end_ifndef

begin_define
define|#
directive|define
name|__SAVAGE_DRV_H__
end_define

begin_define
define|#
directive|define
name|DRIVER_AUTHOR
value|"Felix Kuehling"
end_define

begin_define
define|#
directive|define
name|DRIVER_NAME
value|"savage"
end_define

begin_define
define|#
directive|define
name|DRIVER_DESC
value|"Savage3D/MX/IX, Savage4, SuperSavage, Twister, ProSavage[DDR]"
end_define

begin_define
define|#
directive|define
name|DRIVER_DATE
value|"20050313"
end_define

begin_define
define|#
directive|define
name|DRIVER_MAJOR
value|2
end_define

begin_define
define|#
directive|define
name|DRIVER_MINOR
value|4
end_define

begin_define
define|#
directive|define
name|DRIVER_PATCHLEVEL
value|1
end_define

begin_comment
comment|/* Interface history:  *  * 1.x   The DRM driver from the VIA/S3 code drop, basically a dummy  * 2.0   The first real DRM  * 2.1   Scissors registers managed by the DRM, 3D operations clipped by  *       cliprects of the cmdbuf ioctl  * 2.2   Implemented SAVAGE_CMD_DMA_IDX and SAVAGE_CMD_VB_IDX  * 2.3   Event counters used by BCI_EVENT_EMIT/WAIT ioctls are now 32 bits  *       wide and thus very long lived (unlikely to ever wrap). The size  *       in the struct was 32 bits before, but only 16 bits were used  * 2.4   Implemented command DMA. Now drm_savage_init_t.cmd_dma_offset is  *       actually used  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|drm_savage_age
block|{
name|uint16_t
name|event
decl_stmt|;
name|unsigned
name|int
name|wrap
decl_stmt|;
block|}
name|drm_savage_age_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_savage_buf_priv
block|{
name|struct
name|drm_savage_buf_priv
modifier|*
name|next
decl_stmt|;
name|struct
name|drm_savage_buf_priv
modifier|*
name|prev
decl_stmt|;
name|drm_savage_age_t
name|age
decl_stmt|;
name|drm_buf_t
modifier|*
name|buf
decl_stmt|;
block|}
name|drm_savage_buf_priv_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_savage_dma_page
block|{
name|drm_savage_age_t
name|age
decl_stmt|;
name|unsigned
name|int
name|used
decl_stmt|,
name|flushed
decl_stmt|;
block|}
name|drm_savage_dma_page_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SAVAGE_DMA_PAGE_SIZE
value|1024
end_define

begin_comment
comment|/* in dwords */
end_comment

begin_comment
comment|/* Fake DMA buffer size in bytes. 4 pages. Allows a maximum command  * size of 16kbytes or 4k entries. Minimum requirement would be  * 10kbytes for 255 40-byte vertices in one drawing command. */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_FAKE_DMA_SIZE
value|(SAVAGE_DMA_PAGE_SIZE*4*4)
end_define

begin_comment
comment|/* interesting bits of hardware state that are saved in dev_priv */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
name|drm_savage_common_state
block|{
name|uint32_t
name|vbaddr
decl_stmt|;
block|}
name|common
struct|;
struct|struct
block|{
name|unsigned
name|char
name|pad
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|drm_savage_common_state
argument_list|)
index|]
decl_stmt|;
name|uint32_t
name|texctrl
decl_stmt|,
name|texaddr
decl_stmt|;
name|uint32_t
name|scstart
decl_stmt|,
name|new_scstart
decl_stmt|;
name|uint32_t
name|scend
decl_stmt|,
name|new_scend
decl_stmt|;
block|}
name|s3d
struct|;
struct|struct
block|{
name|unsigned
name|char
name|pad
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|drm_savage_common_state
argument_list|)
index|]
decl_stmt|;
name|uint32_t
name|texdescr
decl_stmt|,
name|texaddr0
decl_stmt|,
name|texaddr1
decl_stmt|;
name|uint32_t
name|drawctrl0
decl_stmt|,
name|new_drawctrl0
decl_stmt|;
name|uint32_t
name|drawctrl1
decl_stmt|,
name|new_drawctrl1
decl_stmt|;
block|}
name|s4
struct|;
block|}
name|drm_savage_state_t
typedef|;
end_typedef

begin_comment
comment|/* these chip tags should match the ones in the 2D driver in savage_regs.h. */
end_comment

begin_enum
enum|enum
name|savage_family
block|{
name|S3_UNKNOWN
init|=
literal|0
block|,
name|S3_SAVAGE3D
block|,
name|S3_SAVAGE_MX
block|,
name|S3_SAVAGE4
block|,
name|S3_PROSAVAGE
block|,
name|S3_TWISTER
block|,
name|S3_PROSAVAGEDDR
block|,
name|S3_SUPERSAVAGE
block|,
name|S3_SAVAGE2000
block|,
name|S3_LAST
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|drm_ioctl_desc_t
name|savage_ioctls
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|savage_max_ioctl
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|S3_SAVAGE3D_SERIES
parameter_list|(
name|chip
parameter_list|)
value|((chip>=S3_SAVAGE3D)&& (chip<=S3_SAVAGE_MX))
end_define

begin_define
define|#
directive|define
name|S3_SAVAGE4_SERIES
parameter_list|(
name|chip
parameter_list|)
value|((chip==S3_SAVAGE4)            \                                   || (chip==S3_PROSAVAGE)       \                                   || (chip==S3_TWISTER)         \                                   || (chip==S3_PROSAVAGEDDR))
end_define

begin_define
define|#
directive|define
name|S3_SAVAGE_MOBILE_SERIES
parameter_list|(
name|chip
parameter_list|)
value|((chip==S3_SAVAGE_MX) || (chip==S3_SUPERSAVAGE))
end_define

begin_define
define|#
directive|define
name|S3_SAVAGE_SERIES
parameter_list|(
name|chip
parameter_list|)
value|((chip>=S3_SAVAGE3D)&& (chip<=S3_SAVAGE2000))
end_define

begin_define
define|#
directive|define
name|S3_MOBILE_TWISTER_SERIES
parameter_list|(
name|chip
parameter_list|)
value|((chip==S3_TWISTER)    \                                           ||(chip==S3_PROSAVAGEDDR))
end_define

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_IS_AGP
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|drm_savage_private
block|{
name|drm_savage_sarea_t
modifier|*
name|sarea_priv
decl_stmt|;
name|drm_savage_buf_priv_t
name|head
decl_stmt|,
name|tail
decl_stmt|;
comment|/* who am I? */
name|enum
name|savage_family
name|chipset
decl_stmt|;
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
comment|/* bitmap descriptors for swap and clear */
name|unsigned
name|int
name|front_bd
decl_stmt|,
name|back_bd
decl_stmt|,
name|depth_bd
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
comment|/* memory regions in physical memory */
name|drm_local_map_t
modifier|*
name|sarea
decl_stmt|;
name|drm_local_map_t
modifier|*
name|mmio
decl_stmt|;
name|drm_local_map_t
modifier|*
name|fb
decl_stmt|;
name|drm_local_map_t
modifier|*
name|aperture
decl_stmt|;
name|drm_local_map_t
modifier|*
name|status
decl_stmt|;
name|drm_local_map_t
modifier|*
name|agp_textures
decl_stmt|;
name|drm_local_map_t
modifier|*
name|cmd_dma
decl_stmt|;
name|drm_local_map_t
name|fake_dma
decl_stmt|;
struct|struct
block|{
name|int
name|handle
decl_stmt|;
name|unsigned
name|long
name|base
decl_stmt|,
name|size
decl_stmt|;
block|}
name|mtrr
index|[
literal|3
index|]
struct|;
comment|/* BCI and status-related stuff */
specifier|volatile
name|uint32_t
modifier|*
name|status_ptr
decl_stmt|,
modifier|*
name|bci_ptr
decl_stmt|;
name|uint32_t
name|status_used_mask
decl_stmt|;
name|uint16_t
name|event_counter
decl_stmt|;
name|unsigned
name|int
name|event_wrap
decl_stmt|;
comment|/* Savage4 command DMA */
name|drm_savage_dma_page_t
modifier|*
name|dma_pages
decl_stmt|;
name|unsigned
name|int
name|nr_dma_pages
decl_stmt|,
name|first_dma_page
decl_stmt|,
name|current_dma_page
decl_stmt|;
name|drm_savage_age_t
name|last_dma_age
decl_stmt|;
comment|/* saved hw state for global/local check on S3D */
name|uint32_t
name|hw_draw_ctrl
decl_stmt|,
name|hw_zbuf_ctrl
decl_stmt|;
comment|/* and for scissors (global, so don't emit if not changed) */
name|uint32_t
name|hw_scissors_start
decl_stmt|,
name|hw_scissors_end
decl_stmt|;
name|drm_savage_state_t
name|state
decl_stmt|;
comment|/* after emitting a wait cmd Savage3D needs 63 nops before next DMA */
name|unsigned
name|int
name|waiting
decl_stmt|;
comment|/* config/hardware-dependent function pointers */
name|int
function_decl|(
modifier|*
name|wait_fifo
function_decl|)
parameter_list|(
name|struct
name|drm_savage_private
modifier|*
name|dev_priv
parameter_list|,
name|unsigned
name|int
name|n
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|wait_evnt
function_decl|)
parameter_list|(
name|struct
name|drm_savage_private
modifier|*
name|dev_priv
parameter_list|,
name|uint16_t
name|e
parameter_list|)
function_decl|;
comment|/* Err, there is a macro wait_event in include/linux/wait.h. 	 * Avoid unwanted macro expansion. */
name|void
function_decl|(
modifier|*
name|emit_clip_rect
function_decl|)
parameter_list|(
name|struct
name|drm_savage_private
modifier|*
name|dev_priv
parameter_list|,
specifier|const
name|drm_clip_rect_t
modifier|*
name|pbox
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|dma_flush
function_decl|)
parameter_list|(
name|struct
name|drm_savage_private
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
block|}
name|drm_savage_private_t
typedef|;
end_typedef

begin_comment
comment|/* ioctls */
end_comment

begin_function_decl
specifier|extern
name|int
name|savage_bci_cmdbuf
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|savage_bci_buffers
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* BCI functions */
end_comment

begin_function_decl
specifier|extern
name|uint16_t
name|savage_bci_emit_event
parameter_list|(
name|drm_savage_private_t
modifier|*
name|dev_priv
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|savage_freelist_put
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|drm_buf_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|savage_dma_reset
parameter_list|(
name|drm_savage_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|savage_dma_wait
parameter_list|(
name|drm_savage_private_t
modifier|*
name|dev_priv
parameter_list|,
name|unsigned
name|int
name|page
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
modifier|*
name|savage_dma_alloc
parameter_list|(
name|drm_savage_private_t
modifier|*
name|dev_priv
parameter_list|,
name|unsigned
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|savage_driver_load
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|unsigned
name|long
name|chipset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|savage_driver_firstopen
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|savage_driver_lastclose
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|savage_driver_unload
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|savage_do_cleanup_bci
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|savage_reclaim_buffers
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|DRMFILE
name|filp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* state functions */
end_comment

begin_function_decl
specifier|extern
name|void
name|savage_emit_clip_rect_s3d
parameter_list|(
name|drm_savage_private_t
modifier|*
name|dev_priv
parameter_list|,
specifier|const
name|drm_clip_rect_t
modifier|*
name|pbox
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|savage_emit_clip_rect_s4
parameter_list|(
name|drm_savage_private_t
modifier|*
name|dev_priv
parameter_list|,
specifier|const
name|drm_clip_rect_t
modifier|*
name|pbox
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SAVAGE_FB_SIZE_S3
value|0x01000000
end_define

begin_comment
comment|/*  16MB */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_FB_SIZE_S4
value|0x02000000
end_define

begin_comment
comment|/*  32MB */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_MMIO_SIZE
value|0x00080000
end_define

begin_comment
comment|/* 512kB */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_APERTURE_OFFSET
value|0x02000000
end_define

begin_comment
comment|/*  32MB */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_APERTURE_SIZE
value|0x05000000
end_define

begin_comment
comment|/* 5 tiled surfaces, 16MB each */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_BCI_OFFSET
value|0x00010000
end_define

begin_comment
comment|/* offset of the BCI region 						 * inside the MMIO region */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_BCI_FIFO_SIZE
value|32
end_define

begin_comment
comment|/* number of entries in on-chip 						 * BCI FIFO */
end_comment

begin_comment
comment|/*  * MMIO registers  */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_STATUS_WORD0
value|0x48C00
end_define

begin_define
define|#
directive|define
name|SAVAGE_STATUS_WORD1
value|0x48C04
end_define

begin_define
define|#
directive|define
name|SAVAGE_ALT_STATUS_WORD0
value|0x48C60
end_define

begin_define
define|#
directive|define
name|SAVAGE_FIFO_USED_MASK_S3D
value|0x0001ffff
end_define

begin_define
define|#
directive|define
name|SAVAGE_FIFO_USED_MASK_S4
value|0x001fffff
end_define

begin_comment
comment|/* Copied from savage_bci.h in the 2D driver with some renaming. */
end_comment

begin_comment
comment|/* Bitmap descriptors */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_BD_STRIDE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SAVAGE_BD_BPP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SAVAGE_BD_TILE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|SAVAGE_BD_BW_DISABLE
value|(1<<28)
end_define

begin_comment
comment|/* common: */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_BD_TILE_LINEAR
value|0
end_define

begin_comment
comment|/* savage4, MX, IX, 3D */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_BD_TILE_16BPP
value|2
end_define

begin_define
define|#
directive|define
name|SAVAGE_BD_TILE_32BPP
value|3
end_define

begin_comment
comment|/* twister, prosavage, DDR, supersavage, 2000 */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_BD_TILE_DEST
value|1
end_define

begin_define
define|#
directive|define
name|SAVAGE_BD_TILE_TEXTURE
value|2
end_define

begin_comment
comment|/* GBD - BCI enable */
end_comment

begin_comment
comment|/* savage4, MX, IX, 3D */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_GBD_BCI_ENABLE
value|8
end_define

begin_comment
comment|/* twister, prosavage, DDR, supersavage, 2000 */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_GBD_BCI_ENABLE_TWISTER
value|0
end_define

begin_define
define|#
directive|define
name|SAVAGE_GBD_BIG_ENDIAN
value|4
end_define

begin_define
define|#
directive|define
name|SAVAGE_GBD_LITTLE_ENDIAN
value|0
end_define

begin_define
define|#
directive|define
name|SAVAGE_GBD_64
value|1
end_define

begin_comment
comment|/*  Global Bitmap Descriptor */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_BCI_GLB_BD_LOW
value|0x8168
end_define

begin_define
define|#
directive|define
name|SAVAGE_BCI_GLB_BD_HIGH
value|0x816C
end_define

begin_comment
comment|/*  * BCI registers  */
end_comment

begin_comment
comment|/* Savage4/Twister/ProSavage 3D registers */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_DRAWLOCALCTRL_S4
value|0x1e
end_define

begin_define
define|#
directive|define
name|SAVAGE_TEXPALADDR_S4
value|0x1f
end_define

begin_define
define|#
directive|define
name|SAVAGE_TEXCTRL0_S4
value|0x20
end_define

begin_define
define|#
directive|define
name|SAVAGE_TEXCTRL1_S4
value|0x21
end_define

begin_define
define|#
directive|define
name|SAVAGE_TEXADDR0_S4
value|0x22
end_define

begin_define
define|#
directive|define
name|SAVAGE_TEXADDR1_S4
value|0x23
end_define

begin_define
define|#
directive|define
name|SAVAGE_TEXBLEND0_S4
value|0x24
end_define

begin_define
define|#
directive|define
name|SAVAGE_TEXBLEND1_S4
value|0x25
end_define

begin_define
define|#
directive|define
name|SAVAGE_TEXXPRCLR_S4
value|0x26
end_define

begin_comment
comment|/* never used */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_TEXDESCR_S4
value|0x27
end_define

begin_define
define|#
directive|define
name|SAVAGE_FOGTABLE_S4
value|0x28
end_define

begin_define
define|#
directive|define
name|SAVAGE_FOGCTRL_S4
value|0x30
end_define

begin_define
define|#
directive|define
name|SAVAGE_STENCILCTRL_S4
value|0x31
end_define

begin_define
define|#
directive|define
name|SAVAGE_ZBUFCTRL_S4
value|0x32
end_define

begin_define
define|#
directive|define
name|SAVAGE_ZBUFOFF_S4
value|0x33
end_define

begin_define
define|#
directive|define
name|SAVAGE_DESTCTRL_S4
value|0x34
end_define

begin_define
define|#
directive|define
name|SAVAGE_DRAWCTRL0_S4
value|0x35
end_define

begin_define
define|#
directive|define
name|SAVAGE_DRAWCTRL1_S4
value|0x36
end_define

begin_define
define|#
directive|define
name|SAVAGE_ZWATERMARK_S4
value|0x37
end_define

begin_define
define|#
directive|define
name|SAVAGE_DESTTEXRWWATERMARK_S4
value|0x38
end_define

begin_define
define|#
directive|define
name|SAVAGE_TEXBLENDCOLOR_S4
value|0x39
end_define

begin_comment
comment|/* Savage3D/MX/IX 3D registers */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_TEXPALADDR_S3D
value|0x18
end_define

begin_define
define|#
directive|define
name|SAVAGE_TEXXPRCLR_S3D
value|0x19
end_define

begin_comment
comment|/* never used */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_TEXADDR_S3D
value|0x1A
end_define

begin_define
define|#
directive|define
name|SAVAGE_TEXDESCR_S3D
value|0x1B
end_define

begin_define
define|#
directive|define
name|SAVAGE_TEXCTRL_S3D
value|0x1C
end_define

begin_define
define|#
directive|define
name|SAVAGE_FOGTABLE_S3D
value|0x20
end_define

begin_define
define|#
directive|define
name|SAVAGE_FOGCTRL_S3D
value|0x30
end_define

begin_define
define|#
directive|define
name|SAVAGE_DRAWCTRL_S3D
value|0x31
end_define

begin_define
define|#
directive|define
name|SAVAGE_ZBUFCTRL_S3D
value|0x32
end_define

begin_define
define|#
directive|define
name|SAVAGE_ZBUFOFF_S3D
value|0x33
end_define

begin_define
define|#
directive|define
name|SAVAGE_DESTCTRL_S3D
value|0x34
end_define

begin_define
define|#
directive|define
name|SAVAGE_SCSTART_S3D
value|0x35
end_define

begin_define
define|#
directive|define
name|SAVAGE_SCEND_S3D
value|0x36
end_define

begin_define
define|#
directive|define
name|SAVAGE_ZWATERMARK_S3D
value|0x37
end_define

begin_define
define|#
directive|define
name|SAVAGE_DESTTEXRWWATERMARK_S3D
value|0x38
end_define

begin_comment
comment|/* common stuff */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_VERTBUFADDR
value|0x3e
end_define

begin_define
define|#
directive|define
name|SAVAGE_BITPLANEWTMASK
value|0xd7
end_define

begin_define
define|#
directive|define
name|SAVAGE_DMABUFADDR
value|0x51
end_define

begin_comment
comment|/* texture enable bits (needed for tex addr checking) */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_TEXCTRL_TEXEN_MASK
value|0x00010000
end_define

begin_comment
comment|/* S3D */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_TEXDESCR_TEX0EN_MASK
value|0x02000000
end_define

begin_comment
comment|/* S4 */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_TEXDESCR_TEX1EN_MASK
value|0x04000000
end_define

begin_comment
comment|/* S4 */
end_comment

begin_comment
comment|/* Global fields in Savage4/Twister/ProSavage 3D registers:  *  * All texture registers and DrawLocalCtrl are local. All other  * registers are global. */
end_comment

begin_comment
comment|/* Global fields in Savage3D/MX/IX 3D registers:  *  * All texture registers are local. DrawCtrl and ZBufCtrl are  * partially local. All other registers are global.  *  * DrawCtrl global fields: cullMode, alphaTestCmpFunc, alphaTestEn, alphaRefVal  * ZBufCtrl global fields: zCmpFunc, zBufEn  */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_DRAWCTRL_S3D_GLOBAL
value|0x03f3c00c
end_define

begin_define
define|#
directive|define
name|SAVAGE_ZBUFCTRL_S3D_GLOBAL
value|0x00000027
end_define

begin_comment
comment|/* Masks for scissor bits (drawCtrl[01] on s4, scissorStart/End on s3d)  */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_SCISSOR_MASK_S4
value|0x00fff7ff
end_define

begin_define
define|#
directive|define
name|SAVAGE_SCISSOR_MASK_S3D
value|0x07ff07ff
end_define

begin_comment
comment|/*  * BCI commands  */
end_comment

begin_define
define|#
directive|define
name|BCI_CMD_NOP
value|0x40000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_RECT
value|0x48000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_RECT_XP
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_RECT_YP
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_SCANLINE
value|0x50000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_LINE
value|0x5C000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_LINE_LAST_PIXEL
value|0x58000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_BYTE_TEXT
value|0x63000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_NT_BYTE_TEXT
value|0x67000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_BIT_TEXT
value|0x6C000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_GET_ROP
parameter_list|(
name|cmd
parameter_list|)
value|(((cmd)>> 16)& 0xFF)
end_define

begin_define
define|#
directive|define
name|BCI_CMD_SET_ROP
parameter_list|(
name|cmd
parameter_list|,
name|rop
parameter_list|)
value|((cmd) |= ((rop& 0xFF)<< 16))
end_define

begin_define
define|#
directive|define
name|BCI_CMD_SEND_COLOR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_CLIP_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_CLIP_CURRENT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_CLIP_LR
value|0x00004000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_CLIP_NEW
value|0x00006000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DEST_GBD
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DEST_PBD
value|0x00000800
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DEST_PBD_NEW
value|0x00000C00
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DEST_SBD
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DEST_SBD_NEW
value|0x00001400
end_define

begin_define
define|#
directive|define
name|BCI_CMD_SRC_TRANSPARENT
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BCI_CMD_SRC_SOLID
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_SRC_GBD
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BCI_CMD_SRC_COLOR
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BCI_CMD_SRC_MONO
value|0x00000060
end_define

begin_define
define|#
directive|define
name|BCI_CMD_SRC_PBD_COLOR
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BCI_CMD_SRC_PBD_MONO
value|0x000000A0
end_define

begin_define
define|#
directive|define
name|BCI_CMD_SRC_PBD_COLOR_NEW
value|0x000000C0
end_define

begin_define
define|#
directive|define
name|BCI_CMD_SRC_PBD_MONO_NEW
value|0x000000E0
end_define

begin_define
define|#
directive|define
name|BCI_CMD_SRC_SBD_COLOR
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BCI_CMD_SRC_SBD_MONO
value|0x00000120
end_define

begin_define
define|#
directive|define
name|BCI_CMD_SRC_SBD_COLOR_NEW
value|0x00000140
end_define

begin_define
define|#
directive|define
name|BCI_CMD_SRC_SBD_MONO_NEW
value|0x00000160
end_define

begin_define
define|#
directive|define
name|BCI_CMD_PAT_TRANSPARENT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BCI_CMD_PAT_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_PAT_COLOR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BCI_CMD_PAT_MONO
value|0x00000003
end_define

begin_define
define|#
directive|define
name|BCI_CMD_PAT_PBD_COLOR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BCI_CMD_PAT_PBD_MONO
value|0x00000005
end_define

begin_define
define|#
directive|define
name|BCI_CMD_PAT_PBD_COLOR_NEW
value|0x00000006
end_define

begin_define
define|#
directive|define
name|BCI_CMD_PAT_PBD_MONO_NEW
value|0x00000007
end_define

begin_define
define|#
directive|define
name|BCI_CMD_PAT_SBD_COLOR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BCI_CMD_PAT_SBD_MONO
value|0x00000009
end_define

begin_define
define|#
directive|define
name|BCI_CMD_PAT_SBD_COLOR_NEW
value|0x0000000A
end_define

begin_define
define|#
directive|define
name|BCI_CMD_PAT_SBD_MONO_NEW
value|0x0000000B
end_define

begin_define
define|#
directive|define
name|BCI_BD_BW_DISABLE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|BCI_BD_TILE_MASK
value|0x03000000
end_define

begin_define
define|#
directive|define
name|BCI_BD_TILE_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BCI_BD_TILE_16
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BCI_BD_TILE_32
value|0x03000000
end_define

begin_define
define|#
directive|define
name|BCI_BD_GET_BPP
parameter_list|(
name|bd
parameter_list|)
value|(((bd)>> 16)& 0xFF)
end_define

begin_define
define|#
directive|define
name|BCI_BD_SET_BPP
parameter_list|(
name|bd
parameter_list|,
name|bpp
parameter_list|)
value|((bd) |= (((bpp)& 0xFF)<< 16))
end_define

begin_define
define|#
directive|define
name|BCI_BD_GET_STRIDE
parameter_list|(
name|bd
parameter_list|)
value|((bd)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|BCI_BD_SET_STRIDE
parameter_list|(
name|bd
parameter_list|,
name|st
parameter_list|)
value|((bd) |= ((st)& 0xFFFF))
end_define

begin_define
define|#
directive|define
name|BCI_CMD_SET_REGISTER
value|0x96000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_WAIT
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_WAIT_3D
value|0x00010000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_WAIT_2D
value|0x00020000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_UPDATE_EVENT_TAG
value|0x98000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DRAW_PRIM
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DRAW_INDEXED_PRIM
value|0x88000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DRAW_CONT
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DRAW_TRILIST
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DRAW_TRISTRIP
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DRAW_TRIFAN
value|0x04000000
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DRAW_SKIPFLAGS
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DRAW_NO_Z
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DRAW_NO_W
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DRAW_NO_CD
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DRAW_NO_CS
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DRAW_NO_U0
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DRAW_NO_V0
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DRAW_NO_UV0
value|0x00000030
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DRAW_NO_U1
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DRAW_NO_V1
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DRAW_NO_UV1
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|BCI_CMD_DMA
value|0xa8000000
end_define

begin_define
define|#
directive|define
name|BCI_W_H
parameter_list|(
name|w
parameter_list|,
name|h
parameter_list|)
value|((((h)<< 16) | (w))& 0x0FFF0FFF)
end_define

begin_define
define|#
directive|define
name|BCI_X_Y
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((((y)<< 16) | (x))& 0x0FFF0FFF)
end_define

begin_define
define|#
directive|define
name|BCI_X_W
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((((w)<< 16) | (x))& 0x0FFF0FFF)
end_define

begin_define
define|#
directive|define
name|BCI_CLIP_LR
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|((((r)<< 16) | (l))& 0x0FFF0FFF)
end_define

begin_define
define|#
directive|define
name|BCI_CLIP_TL
parameter_list|(
name|t
parameter_list|,
name|l
parameter_list|)
value|((((t)<< 16) | (l))& 0x0FFF0FFF)
end_define

begin_define
define|#
directive|define
name|BCI_CLIP_BR
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|)
value|((((b)<< 16) | (r))& 0x0FFF0FFF)
end_define

begin_define
define|#
directive|define
name|BCI_LINE_X_Y
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((y)<< 16) | ((x)& 0xFFFF))
end_define

begin_define
define|#
directive|define
name|BCI_LINE_STEPS
parameter_list|(
name|diag
parameter_list|,
name|axi
parameter_list|)
value|(((axi)<< 16) | ((diag)& 0xFFFF))
end_define

begin_define
define|#
directive|define
name|BCI_LINE_MISC
parameter_list|(
name|maj
parameter_list|,
name|ym
parameter_list|,
name|xp
parameter_list|,
name|yp
parameter_list|,
name|err
parameter_list|)
define|\
value|(((maj)& 0x1FFF) | \ 	((ym) ? 1<<13 : 0) | \ 	((xp) ? 1<<14 : 0) | \ 	((yp) ? 1<<15 : 0) | \ 	((err)<< 16))
end_define

begin_comment
comment|/*  * common commands  */
end_comment

begin_define
define|#
directive|define
name|BCI_SET_REGISTERS
parameter_list|(
name|first
parameter_list|,
name|n
parameter_list|)
define|\
value|BCI_WRITE(BCI_CMD_SET_REGISTER |		\ 		  ((uint32_t)(n)& 0xff)<< 16 |	\ 		  ((uint32_t)(first)& 0xffff))
end_define

begin_define
define|#
directive|define
name|DMA_SET_REGISTERS
parameter_list|(
name|first
parameter_list|,
name|n
parameter_list|)
define|\
value|DMA_WRITE(BCI_CMD_SET_REGISTER |		\ 		  ((uint32_t)(n)& 0xff)<< 16 |	\ 		  ((uint32_t)(first)& 0xffff))
end_define

begin_define
define|#
directive|define
name|BCI_DRAW_PRIMITIVE
parameter_list|(
name|n
parameter_list|,
name|type
parameter_list|,
name|skip
parameter_list|)
define|\
value|BCI_WRITE(BCI_CMD_DRAW_PRIM | (type) | (skip) | \ 		  ((n)<< 16))
end_define

begin_define
define|#
directive|define
name|DMA_DRAW_PRIMITIVE
parameter_list|(
name|n
parameter_list|,
name|type
parameter_list|,
name|skip
parameter_list|)
define|\
value|DMA_WRITE(BCI_CMD_DRAW_PRIM | (type) | (skip) | \ 		  ((n)<< 16))
end_define

begin_define
define|#
directive|define
name|BCI_DRAW_INDICES_S3D
parameter_list|(
name|n
parameter_list|,
name|type
parameter_list|,
name|i0
parameter_list|)
define|\
value|BCI_WRITE(BCI_CMD_DRAW_INDEXED_PRIM | (type) |  \ 		  ((n)<< 16) | (i0))
end_define

begin_define
define|#
directive|define
name|BCI_DRAW_INDICES_S4
parameter_list|(
name|n
parameter_list|,
name|type
parameter_list|,
name|skip
parameter_list|)
define|\
value|BCI_WRITE(BCI_CMD_DRAW_INDEXED_PRIM | (type) |  \                   (skip) | ((n)<< 16))
end_define

begin_define
define|#
directive|define
name|BCI_DMA
parameter_list|(
name|n
parameter_list|)
define|\
value|BCI_WRITE(BCI_CMD_DMA | (((n)>> 1) - 1))
end_define

begin_comment
comment|/*  * access to MMIO  */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_READ
parameter_list|(
name|reg
parameter_list|)
value|DRM_READ32(  dev_priv->mmio, (reg) )
end_define

begin_define
define|#
directive|define
name|SAVAGE_WRITE
parameter_list|(
name|reg
parameter_list|)
value|DRM_WRITE32( dev_priv->mmio, (reg) )
end_define

begin_comment
comment|/*  * access to the burst command interface (BCI)  */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_BCI_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|BCI_LOCALS
value|volatile uint32_t *bci_ptr;
end_define

begin_define
define|#
directive|define
name|BEGIN_BCI
parameter_list|(
name|n
parameter_list|)
value|do {			\ 	dev_priv->wait_fifo(dev_priv, (n));	\ 	bci_ptr = dev_priv->bci_ptr;		\ } while(0)
end_define

begin_define
define|#
directive|define
name|BCI_WRITE
parameter_list|(
name|val
parameter_list|)
value|*bci_ptr++ = (uint32_t)(val)
end_define

begin_comment
comment|/*  * command DMA support  */
end_comment

begin_define
define|#
directive|define
name|SAVAGE_DMA_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|DMA_LOCALS
value|uint32_t *dma_ptr;
end_define

begin_define
define|#
directive|define
name|BEGIN_DMA
parameter_list|(
name|n
parameter_list|)
value|do {						\ 	unsigned int cur = dev_priv->current_dma_page;			\ 	unsigned int rest = SAVAGE_DMA_PAGE_SIZE -			\ 		dev_priv->dma_pages[cur].used;				\ 	if ((n)> rest) {						\ 		dma_ptr = savage_dma_alloc(dev_priv, (n));		\ 	} else {
comment|/* fast path for small allocations */
value|\ 		dma_ptr = (uint32_t *)dev_priv->cmd_dma->handle +	\ 			cur * SAVAGE_DMA_PAGE_SIZE +			\ 			dev_priv->dma_pages[cur].used;			\ 		if (dev_priv->dma_pages[cur].used == 0)			\ 			savage_dma_wait(dev_priv, cur);			\ 		dev_priv->dma_pages[cur].used += (n);			\ 	}								\ } while(0)
end_define

begin_define
define|#
directive|define
name|DMA_WRITE
parameter_list|(
name|val
parameter_list|)
value|*dma_ptr++ = (uint32_t)(val)
end_define

begin_define
define|#
directive|define
name|DMA_COPY
parameter_list|(
name|src
parameter_list|,
name|n
parameter_list|)
value|do {					\ 	memcpy(dma_ptr, (src), (n)*4);				\ 	dma_ptr += n;						\ } while(0)
end_define

begin_if
if|#
directive|if
name|SAVAGE_DMA_DEBUG
end_if

begin_define
define|#
directive|define
name|DMA_COMMIT
parameter_list|()
value|do {						\ 	unsigned int cur = dev_priv->current_dma_page;			\ 	uint32_t *expected = (uint32_t *)dev_priv->cmd_dma->handle +	\ 			cur * SAVAGE_DMA_PAGE_SIZE +			\ 			dev_priv->dma_pages[cur].used;			\ 	if (dma_ptr != expected) {					\ 		DRM_ERROR("DMA allocation and use don't match: "	\ 			  "%p != %p\n", expected, dma_ptr);		\ 		savage_dma_reset(dev_priv);				\ 	}								\ } while(0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DMA_COMMIT
parameter_list|()
value|do {
comment|/* nothing */
value|} while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DMA_FLUSH
parameter_list|()
value|dev_priv->dma_flush(dev_priv)
end_define

begin_comment
comment|/* Buffer aging via event tag  */
end_comment

begin_define
define|#
directive|define
name|UPDATE_EVENT_COUNTER
parameter_list|( )
value|do {			\ 	if (dev_priv->status_ptr) {			\ 		uint16_t count;				\
comment|/* coordinate with Xserver */
value|\ 		count = dev_priv->status_ptr[1023];	\ 		if (count< dev_priv->event_counter)	\ 			dev_priv->event_wrap++;		\ 		dev_priv->event_counter = count;	\ 	}						\ } while(0)
end_define

begin_define
define|#
directive|define
name|SET_AGE
parameter_list|(
name|age
parameter_list|,
name|e
parameter_list|,
name|w
parameter_list|)
value|do {	\ 	(age)->event = e;		\ 	(age)->wrap = w;		\ } while(0)
end_define

begin_define
define|#
directive|define
name|TEST_AGE
parameter_list|(
name|age
parameter_list|,
name|e
parameter_list|,
name|w
parameter_list|)
define|\
value|( (age)->wrap< (w) || ( (age)->wrap == (w)&& (age)->event<= (e) ) )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SAVAGE_DRV_H__ */
end_comment

end_unit

