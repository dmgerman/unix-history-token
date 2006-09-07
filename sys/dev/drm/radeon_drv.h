begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* radeon_drv.h -- Private header for radeon driver -*- linux-c -*-  *  * Copyright 1999 Precision Insight, Inc., Cedar Park, Texas.  * Copyright 2000 VA Linux Systems, Inc., Fremont, California.  * All rights reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Kevin E. Martin<martin@valinux.com>  *    Gareth Hughes<gareth@valinux.com>  */
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
name|__RADEON_DRV_H__
end_ifndef

begin_define
define|#
directive|define
name|__RADEON_DRV_H__
end_define

begin_comment
comment|/* General customization:  */
end_comment

begin_define
define|#
directive|define
name|DRIVER_AUTHOR
value|"Gareth Hughes, Keith Whitwell, others."
end_define

begin_define
define|#
directive|define
name|DRIVER_NAME
value|"radeon"
end_define

begin_define
define|#
directive|define
name|DRIVER_DESC
value|"ATI Radeon"
end_define

begin_define
define|#
directive|define
name|DRIVER_DATE
value|"20060524"
end_define

begin_comment
comment|/* Interface history:  *  * 1.1 - ??  * 1.2 - Add vertex2 ioctl (keith)  *     - Add stencil capability to clear ioctl (gareth, keith)  *     - Increase MAX_TEXTURE_LEVELS (brian)  * 1.3 - Add cmdbuf ioctl (keith)  *     - Add support for new radeon packets (keith)  *     - Add getparam ioctl (keith)  *     - Add flip-buffers ioctl, deprecate fullscreen foo (keith).  * 1.4 - Add scratch registers to get_param ioctl.  * 1.5 - Add r200 packets to cmdbuf ioctl  *     - Add r200 function to init ioctl  *     - Add 'scalar2' instruction to cmdbuf  * 1.6 - Add static GART memory manager  *       Add irq handler (won't be turned on unless X server knows to)  *       Add irq ioctls and irq_active getparam.  *       Add wait command for cmdbuf ioctl  *       Add GART offset query for getparam  * 1.7 - Add support for cube map registers: R200_PP_CUBIC_FACES_[0..5]  *       and R200_PP_CUBIC_OFFSET_F1_[0..5].  *       Added packets R200_EMIT_PP_CUBIC_FACES_[0..5] and  *       R200_EMIT_PP_CUBIC_OFFSETS_[0..5].  (brian)  * 1.8 - Remove need to call cleanup ioctls on last client exit (keith)  *       Add 'GET' queries for starting additional clients on different VT's.  * 1.9 - Add DRM_IOCTL_RADEON_CP_RESUME ioctl.  *       Add texture rectangle support for r100.  * 1.10- Add SETPARAM ioctl; first parameter to set is FB_LOCATION, which  *       clients use to tell the DRM where they think the framebuffer is  *       located in the card's address space  * 1.11- Add packet R200_EMIT_RB3D_BLENDCOLOR to support GL_EXT_blend_color  *       and GL_EXT_blend_[func|equation]_separate on r200  * 1.12- Add R300 CP microcode support - this just loads the CP on r300  *       (No 3D support yet - just microcode loading).  * 1.13- Add packet R200_EMIT_TCL_POINT_SPRITE_CNTL for ARB_point_parameters  *     - Add hyperz support, add hyperz flags to clear ioctl.  * 1.14- Add support for color tiling  *     - Add R100/R200 surface allocation/free support  * 1.15- Add support for texture micro tiling  *     - Add support for r100 cube maps  * 1.16- Add R200_EMIT_PP_TRI_PERF_CNTL packet to support brilinear  *       texture filtering on r200  * 1.17- Add initial support for R300 (3D).  * 1.18- Add support for GL_ATI_fragment_shader, new packets  *       R200_EMIT_PP_AFS_0/1, R200_EMIT_PP_TXCTLALL_0-5 (replaces  *       R200_EMIT_PP_TXFILTER_0-5, 2 more regs) and R200_EMIT_ATF_TFACTOR  *       (replaces R200_EMIT_TFACTOR_0 (8 consts instead of 6)  * 1.19- Add support for gart table in FB memory and PCIE r300  * 1.20- Add support for r300 texrect  * 1.21- Add support for card type getparam  * 1.22- Add support for texture cache flushes (R300_TX_CNTL)  * 1.23- Add new radeon memory map work from benh  * 1.24- Add general-purpose packet for manipulating scratch registers (r300)  * 1.25- Add support for r200 vertex programs (R200_EMIT_VAP_PVS_CNTL,  *       new packet type)  */
end_comment

begin_define
define|#
directive|define
name|DRIVER_MAJOR
value|1
end_define

begin_define
define|#
directive|define
name|DRIVER_MINOR
value|25
end_define

begin_define
define|#
directive|define
name|DRIVER_PATCHLEVEL
value|0
end_define

begin_comment
comment|/*  * Radeon chip families  */
end_comment

begin_enum
enum|enum
name|radeon_family
block|{
name|CHIP_R100
block|,
name|CHIP_RV100
block|,
name|CHIP_RS100
block|,
name|CHIP_RV200
block|,
name|CHIP_RS200
block|,
name|CHIP_R200
block|,
name|CHIP_RV250
block|,
name|CHIP_RS300
block|,
name|CHIP_RV280
block|,
name|CHIP_R300
block|,
name|CHIP_R350
block|,
name|CHIP_RV350
block|,
name|CHIP_RV380
block|,
name|CHIP_R420
block|,
name|CHIP_RV410
block|,
name|CHIP_RS400
block|,
name|CHIP_LAST
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|radeon_cp_microcode_version
block|{
name|UCODE_R100
block|,
name|UCODE_R200
block|,
name|UCODE_R300
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Chip flags  */
end_comment

begin_enum
enum|enum
name|radeon_chip_flags
block|{
name|CHIP_FAMILY_MASK
init|=
literal|0x0000ffffUL
block|,
name|CHIP_FLAGS_MASK
init|=
literal|0xffff0000UL
block|,
name|CHIP_IS_MOBILITY
init|=
literal|0x00010000UL
block|,
name|CHIP_IS_IGP
init|=
literal|0x00020000UL
block|,
name|CHIP_SINGLE_CRTC
init|=
literal|0x00040000UL
block|,
name|CHIP_IS_AGP
init|=
literal|0x00080000UL
block|,
name|CHIP_HAS_HIERZ
init|=
literal|0x00100000UL
block|,
name|CHIP_IS_PCIE
init|=
literal|0x00200000UL
block|,
name|CHIP_NEW_MEMMAP
init|=
literal|0x00400000UL
block|,
name|CHIP_IS_PCI
init|=
literal|0x00800000UL
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|GET_RING_HEAD
parameter_list|(
name|dev_priv
parameter_list|)
value|(dev_priv->writeback_works ? \         DRM_READ32(  (dev_priv)->ring_rptr, 0 ) : RADEON_READ(RADEON_CP_RB_RPTR))
end_define

begin_define
define|#
directive|define
name|SET_RING_HEAD
parameter_list|(
name|dev_priv
parameter_list|,
name|val
parameter_list|)
value|DRM_WRITE32( (dev_priv)->ring_rptr, 0, (val) )
end_define

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_freelist
block|{
name|unsigned
name|int
name|age
decl_stmt|;
name|drm_buf_t
modifier|*
name|buf
decl_stmt|;
name|struct
name|drm_radeon_freelist
modifier|*
name|next
decl_stmt|;
name|struct
name|drm_radeon_freelist
modifier|*
name|prev
decl_stmt|;
block|}
name|drm_radeon_freelist_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_ring_buffer
block|{
name|u32
modifier|*
name|start
decl_stmt|;
name|u32
modifier|*
name|end
decl_stmt|;
name|int
name|size
decl_stmt|;
name|int
name|size_l2qw
decl_stmt|;
name|u32
name|tail
decl_stmt|;
name|u32
name|tail_mask
decl_stmt|;
name|int
name|space
decl_stmt|;
name|int
name|high_mark
decl_stmt|;
block|}
name|drm_radeon_ring_buffer_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_depth_clear_t
block|{
name|u32
name|rb3d_cntl
decl_stmt|;
name|u32
name|rb3d_zstencilcntl
decl_stmt|;
name|u32
name|se_cntl
decl_stmt|;
block|}
name|drm_radeon_depth_clear_t
typedef|;
end_typedef

begin_struct
struct|struct
name|drm_radeon_driver_file_fields
block|{
name|int64_t
name|radeon_fb_delta
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mem_block
block|{
name|struct
name|mem_block
modifier|*
name|next
decl_stmt|;
name|struct
name|mem_block
modifier|*
name|prev
decl_stmt|;
name|int
name|start
decl_stmt|;
name|int
name|size
decl_stmt|;
name|DRMFILE
name|filp
decl_stmt|;
comment|/* 0: free, -1: heap, other: real files */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|radeon_surface
block|{
name|int
name|refcount
decl_stmt|;
name|u32
name|lower
decl_stmt|;
name|u32
name|upper
decl_stmt|;
name|u32
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|radeon_virt_surface
block|{
name|int
name|surface_index
decl_stmt|;
name|u32
name|lower
decl_stmt|;
name|u32
name|upper
decl_stmt|;
name|u32
name|flags
decl_stmt|;
name|DRMFILE
name|filp
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_private
block|{
name|drm_radeon_ring_buffer_t
name|ring
decl_stmt|;
name|drm_radeon_sarea_t
modifier|*
name|sarea_priv
decl_stmt|;
name|u32
name|fb_location
decl_stmt|;
name|u32
name|fb_size
decl_stmt|;
name|int
name|new_memmap
decl_stmt|;
name|int
name|gart_size
decl_stmt|;
name|u32
name|gart_vm_start
decl_stmt|;
name|unsigned
name|long
name|gart_buffers_offset
decl_stmt|;
name|int
name|cp_mode
decl_stmt|;
name|int
name|cp_running
decl_stmt|;
name|drm_radeon_freelist_t
modifier|*
name|head
decl_stmt|;
name|drm_radeon_freelist_t
modifier|*
name|tail
decl_stmt|;
name|int
name|last_buf
decl_stmt|;
specifier|volatile
name|u32
modifier|*
name|scratch
decl_stmt|;
name|int
name|writeback_works
decl_stmt|;
name|int
name|usec_timeout
decl_stmt|;
name|int
name|microcode_version
decl_stmt|;
struct|struct
block|{
name|u32
name|boxes
decl_stmt|;
name|int
name|freelist_timeouts
decl_stmt|;
name|int
name|freelist_loops
decl_stmt|;
name|int
name|requested_bufs
decl_stmt|;
name|int
name|last_frame_reads
decl_stmt|;
name|int
name|last_clear_reads
decl_stmt|;
name|int
name|clears
decl_stmt|;
name|int
name|texture_uploads
decl_stmt|;
block|}
name|stats
struct|;
name|int
name|do_boxes
decl_stmt|;
name|int
name|page_flipping
decl_stmt|;
name|int
name|current_page
decl_stmt|;
name|u32
name|color_fmt
decl_stmt|;
name|unsigned
name|int
name|front_offset
decl_stmt|;
name|unsigned
name|int
name|front_pitch
decl_stmt|;
name|unsigned
name|int
name|back_offset
decl_stmt|;
name|unsigned
name|int
name|back_pitch
decl_stmt|;
name|u32
name|depth_fmt
decl_stmt|;
name|unsigned
name|int
name|depth_offset
decl_stmt|;
name|unsigned
name|int
name|depth_pitch
decl_stmt|;
name|u32
name|front_pitch_offset
decl_stmt|;
name|u32
name|back_pitch_offset
decl_stmt|;
name|u32
name|depth_pitch_offset
decl_stmt|;
name|drm_radeon_depth_clear_t
name|depth_clear
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
name|gart_textures_offset
decl_stmt|;
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
name|cp_ring
decl_stmt|;
name|drm_local_map_t
modifier|*
name|ring_rptr
decl_stmt|;
name|drm_local_map_t
modifier|*
name|gart_textures
decl_stmt|;
name|struct
name|mem_block
modifier|*
name|gart_heap
decl_stmt|;
name|struct
name|mem_block
modifier|*
name|fb_heap
decl_stmt|;
comment|/* SW interrupt */
name|wait_queue_head_t
name|swi_queue
decl_stmt|;
name|atomic_t
name|swi_emitted
decl_stmt|;
name|struct
name|radeon_surface
name|surfaces
index|[
name|RADEON_MAX_SURFACES
index|]
decl_stmt|;
name|struct
name|radeon_virt_surface
name|virt_surfaces
index|[
literal|2
operator|*
name|RADEON_MAX_SURFACES
index|]
decl_stmt|;
name|unsigned
name|long
name|pcigart_offset
decl_stmt|;
name|drm_ati_pcigart_info
name|gart_info
decl_stmt|;
name|u32
name|scratch_ages
index|[
literal|5
index|]
decl_stmt|;
comment|/* starting from here on, data is preserved accross an open */
name|uint32_t
name|flags
decl_stmt|;
comment|/* see radeon_chip_flags */
block|}
name|drm_radeon_private_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_buf_priv
block|{
name|u32
name|age
decl_stmt|;
block|}
name|drm_radeon_buf_priv_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_kcmd_buffer
block|{
name|int
name|bufsz
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
name|int
name|nbox
decl_stmt|;
name|drm_clip_rect_t
name|__user
modifier|*
name|boxes
decl_stmt|;
block|}
name|drm_radeon_kcmd_buffer_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|radeon_no_wb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|drm_ioctl_desc_t
name|radeon_ioctls
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|radeon_max_ioctl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* radeon_cp.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|radeon_cp_init
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_cp_start
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_cp_stop
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_cp_reset
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_cp_idle
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_cp_resume
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_engine_reset
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_fullscreen
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_cp_buffers
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|radeon_freelist_reset
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|drm_buf_t
modifier|*
name|radeon_freelist_get
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
name|radeon_wait_ring
parameter_list|(
name|drm_radeon_private_t
modifier|*
name|dev_priv
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_do_cp_idle
parameter_list|(
name|drm_radeon_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_mem_alloc
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_mem_free
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_mem_init_heap
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|radeon_mem_takedown
parameter_list|(
name|struct
name|mem_block
modifier|*
modifier|*
name|heap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|radeon_mem_release
parameter_list|(
name|DRMFILE
name|filp
parameter_list|,
name|struct
name|mem_block
modifier|*
name|heap
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* radeon_irq.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|radeon_irq_emit
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_irq_wait
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|radeon_do_release
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
name|radeon_driver_vblank_wait
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
modifier|*
name|sequence
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|irqreturn_t
name|radeon_driver_irq_handler
parameter_list|(
name|DRM_IRQ_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|radeon_driver_irq_preinstall
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
name|radeon_driver_irq_postinstall
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
name|radeon_driver_irq_uninstall
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
name|radeon_driver_load
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|unsigned
name|long
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_driver_unload
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_driver_firstopen
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|radeon_driver_preclose
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

begin_function_decl
specifier|extern
name|void
name|radeon_driver_postclose
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|drm_file_t
modifier|*
name|filp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|radeon_driver_lastclose
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
name|radeon_driver_open
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|drm_file_t
modifier|*
name|filp_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|radeon_compat_ioctl
parameter_list|(
name|struct
name|file
modifier|*
name|filp
parameter_list|,
name|unsigned
name|int
name|cmd
parameter_list|,
name|unsigned
name|long
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r300_cmdbuf.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|r300_init_reg_flags
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|r300_do_cp_cmdbuf
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|DRMFILE
name|filp
parameter_list|,
name|drm_file_t
modifier|*
name|filp_priv
parameter_list|,
name|drm_radeon_kcmd_buffer_t
modifier|*
name|cmdbuf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Flags for stats.boxes  */
end_comment

begin_define
define|#
directive|define
name|RADEON_BOX_DMA_IDLE
value|0x1
end_define

begin_define
define|#
directive|define
name|RADEON_BOX_RING_FULL
value|0x2
end_define

begin_define
define|#
directive|define
name|RADEON_BOX_FLIP
value|0x4
end_define

begin_define
define|#
directive|define
name|RADEON_BOX_WAIT_IDLE
value|0x8
end_define

begin_define
define|#
directive|define
name|RADEON_BOX_TEXTURE_LOAD
value|0x10
end_define

begin_comment
comment|/* Register definitions, register access macros and drmAddMap constants  * for Radeon kernel driver.  */
end_comment

begin_define
define|#
directive|define
name|RADEON_AGP_COMMAND
value|0x0f60
end_define

begin_define
define|#
directive|define
name|RADEON_AGP_COMMAND_PCI_CONFIG
value|0x0060
end_define

begin_comment
comment|/* offset in PCI config */
end_comment

begin_define
define|#
directive|define
name|RADEON_AGP_ENABLE
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|RADEON_AUX_SCISSOR_CNTL
value|0x26f0
end_define

begin_define
define|#
directive|define
name|RADEON_EXCLUSIVE_SCISSOR_0
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_EXCLUSIVE_SCISSOR_1
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RADEON_EXCLUSIVE_SCISSOR_2
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_SCISSOR_0_ENABLE
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_SCISSOR_1_ENABLE
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|RADEON_SCISSOR_2_ENABLE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_BUS_CNTL
value|0x0030
end_define

begin_define
define|#
directive|define
name|RADEON_BUS_MASTER_DIS
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|RADEON_CLOCK_CNTL_DATA
value|0x000c
end_define

begin_define
define|#
directive|define
name|RADEON_PLL_WR_EN
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|RADEON_CLOCK_CNTL_INDEX
value|0x0008
end_define

begin_define
define|#
directive|define
name|RADEON_CONFIG_APER_SIZE
value|0x0108
end_define

begin_define
define|#
directive|define
name|RADEON_CONFIG_MEMSIZE
value|0x00f8
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_OFFSET
value|0x0224
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_OFFSET_CNTL
value|0x0228
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_TILE_EN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_OFFSET_FLIP_CNTL
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_OFFSET
value|0x0324
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_OFFSET_CNTL
value|0x0328
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_INDEX
value|0x0030
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_DATA
value|0x0034
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_CNTL
value|0x10
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_UNMAPPED_ACCESS_PASS_THRU
value|(0<<1)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_UNMAPPED_ACCESS_CLAMP_LO
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_UNMAPPED_ACCESS_DISCARD
value|(3<<1)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_MODE_32_128_CACHE
value|(0<<3)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_MODE_8_4_128_CACHE
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_CHK_RW_VALID_EN
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_INVALIDATE_TLB
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_DISCARD_RD_ADDR_LO
value|0x11
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_DISCARD_RD_ADDR_HI
value|0x12
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_BASE
value|0x13
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_START_LO
value|0x14
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_START_HI
value|0x15
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_END_LO
value|0x16
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_END_HI
value|0x17
end_define

begin_define
define|#
directive|define
name|RADEON_MPP_TB_CONFIG
value|0x01c0
end_define

begin_define
define|#
directive|define
name|RADEON_MEM_CNTL
value|0x0140
end_define

begin_define
define|#
directive|define
name|RADEON_MEM_SDRAM_MODE_REG
value|0x0158
end_define

begin_define
define|#
directive|define
name|RADEON_AGP_BASE
value|0x0170
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_COLOROFFSET
value|0x1c40
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_COLORPITCH
value|0x1c48
end_define

begin_define
define|#
directive|define
name|RADEON_DP_GUI_MASTER_CNTL
value|0x146c
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_SRC_PITCH_OFFSET_CNTL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_DST_PITCH_OFFSET_CNTL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_BRUSH_SOLID_COLOR
value|(13<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_BRUSH_NONE
value|(15<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_DST_16BPP
value|(4<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_DST_24BPP
value|(5<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_DST_32BPP
value|(6<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_DST_DATATYPE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_SRC_DATATYPE_COLOR
value|(3<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_DP_SRC_SOURCE_MEMORY
value|(2<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_DP_SRC_SOURCE_HOST_DATA
value|(3<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_CLR_CMP_CNTL_DIS
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_WR_MSK_DIS
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_S
value|0x00cc0000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_P
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|RADEON_DP_WRITE_MASK
value|0x16cc
end_define

begin_define
define|#
directive|define
name|RADEON_DST_PITCH_OFFSET
value|0x142c
end_define

begin_define
define|#
directive|define
name|RADEON_DST_PITCH_OFFSET_C
value|0x1c80
end_define

begin_define
define|#
directive|define
name|RADEON_DST_TILE_LINEAR
value|(0<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_DST_TILE_MACRO
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_DST_TILE_MICRO
value|(2<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_DST_TILE_BOTH
value|(3<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_SCRATCH_REG0
value|0x15e0
end_define

begin_define
define|#
directive|define
name|RADEON_SCRATCH_REG1
value|0x15e4
end_define

begin_define
define|#
directive|define
name|RADEON_SCRATCH_REG2
value|0x15e8
end_define

begin_define
define|#
directive|define
name|RADEON_SCRATCH_REG3
value|0x15ec
end_define

begin_define
define|#
directive|define
name|RADEON_SCRATCH_REG4
value|0x15f0
end_define

begin_define
define|#
directive|define
name|RADEON_SCRATCH_REG5
value|0x15f4
end_define

begin_define
define|#
directive|define
name|RADEON_SCRATCH_UMSK
value|0x0770
end_define

begin_define
define|#
directive|define
name|RADEON_SCRATCH_ADDR
value|0x0774
end_define

begin_define
define|#
directive|define
name|RADEON_SCRATCHOFF
parameter_list|(
name|x
parameter_list|)
value|(RADEON_SCRATCH_REG_OFFSET + 4*(x))
end_define

begin_define
define|#
directive|define
name|GET_SCRATCH
parameter_list|(
name|x
parameter_list|)
value|(dev_priv->writeback_works			\ 				? DRM_READ32( dev_priv->ring_rptr, RADEON_SCRATCHOFF(x) ) \ 				: RADEON_READ( RADEON_SCRATCH_REG0 + 4*(x) ) )
end_define

begin_define
define|#
directive|define
name|RADEON_GEN_INT_CNTL
value|0x0040
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_VBLANK_MASK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_GUI_IDLE_INT_ENABLE
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RADEON_SW_INT_ENABLE
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RADEON_GEN_INT_STATUS
value|0x0044
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_VBLANK_STAT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_VBLANK_STAT_ACK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_GUI_IDLE_INT_TEST_ACK
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RADEON_SW_INT_TEST
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RADEON_SW_INT_TEST_ACK
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RADEON_SW_INT_FIRE
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_PATH_CNTL
value|0x0130
end_define

begin_define
define|#
directive|define
name|RADEON_HDP_SOFT_RESET
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_HDP_WC_TIMEOUT_MASK
value|(7<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_HDP_WC_TIMEOUT_28BCLK
value|(7<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_ISYNC_CNTL
value|0x1724
end_define

begin_define
define|#
directive|define
name|RADEON_ISYNC_ANY2D_IDLE3D
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_ISYNC_ANY3D_IDLE2D
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_ISYNC_TRIG2D_IDLE3D
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_ISYNC_TRIG3D_IDLE2D
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RADEON_ISYNC_WAIT_IDLEGUI
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_ISYNC_CPSCRATCH_IDLEGUI
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_RBBM_GUICNTL
value|0x172c
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_DATA_SWAP_NONE
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_DATA_SWAP_16BIT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_DATA_SWAP_32BIT
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_DATA_SWAP_HDW
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_MC_AGP_LOCATION
value|0x014c
end_define

begin_define
define|#
directive|define
name|RADEON_MC_FB_LOCATION
value|0x0148
end_define

begin_define
define|#
directive|define
name|RADEON_MCLK_CNTL
value|0x0012
end_define

begin_define
define|#
directive|define
name|RADEON_FORCEON_MCLKA
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_FORCEON_MCLKB
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_FORCEON_YCLKA
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_FORCEON_YCLKB
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RADEON_FORCEON_MC
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_FORCEON_AIC
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_PP_BORDER_COLOR_0
value|0x1d40
end_define

begin_define
define|#
directive|define
name|RADEON_PP_BORDER_COLOR_1
value|0x1d44
end_define

begin_define
define|#
directive|define
name|RADEON_PP_BORDER_COLOR_2
value|0x1d48
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CNTL
value|0x1c38
end_define

begin_define
define|#
directive|define
name|RADEON_SCISSOR_ENABLE
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_PP_LUM_MATRIX
value|0x1d00
end_define

begin_define
define|#
directive|define
name|RADEON_PP_MISC
value|0x1c14
end_define

begin_define
define|#
directive|define
name|RADEON_PP_ROT_MATRIX_0
value|0x1d58
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TXFILTER_0
value|0x1c54
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TXOFFSET_0
value|0x1c5c
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TXFILTER_1
value|0x1c6c
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TXFILTER_2
value|0x1c84
end_define

begin_define
define|#
directive|define
name|RADEON_RB2D_DSTCACHE_CTLSTAT
value|0x342c
end_define

begin_define
define|#
directive|define
name|RADEON_RB2D_DC_FLUSH
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_RB2D_DC_FREE
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_RB2D_DC_FLUSH_ALL
value|0xf
end_define

begin_define
define|#
directive|define
name|RADEON_RB2D_DC_BUSY
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_CNTL
value|0x1c3c
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_BLEND_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_PLANE_MASK_ENABLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_DITHER_ENABLE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_ROUND_ENABLE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RADEON_SCALE_DITHER_ENABLE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_DITHER_INIT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_ROP_ENABLE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_ENABLE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|RADEON_Z_ENABLE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ZBLOCK16
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DEPTHOFFSET
value|0x1c24
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DEPTHCLEARVALUE
value|0x3230
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DEPTHPITCH
value|0x1c28
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_PLANEMASK
value|0x1d84
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_STENCILREFMASK
value|0x1d7c
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_ZCACHE_MODE
value|0x3250
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_ZCACHE_CTLSTAT
value|0x3254
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_ZC_FLUSH
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_ZC_FREE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_ZC_FLUSH_ALL
value|0x5
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_ZC_BUSY
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DSTCACHE_CTLSTAT
value|0x325c
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DC_FLUSH
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DC_FREE
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DC_FLUSH_ALL
value|0xf
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DC_BUSY
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_ZSTENCILCNTL
value|0x1c2c
end_define

begin_define
define|#
directive|define
name|RADEON_Z_TEST_MASK
value|(7<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_Z_TEST_ALWAYS
value|(7<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_Z_HIERARCHY_ENABLE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_TEST_ALWAYS
value|(7<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_S_FAIL_REPLACE
value|(2<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_ZPASS_REPLACE
value|(2<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_ZFAIL_REPLACE
value|(2<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_Z_COMPRESSION_ENABLE
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_FORCE_Z_DIRTY
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|RADEON_Z_WRITE_ENABLE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_Z_DECOMPRESSION_ENABLE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_RBBM_SOFT_RESET
value|0x00f0
end_define

begin_define
define|#
directive|define
name|RADEON_SOFT_RESET_CP
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_SOFT_RESET_HI
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_SOFT_RESET_SE
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RADEON_SOFT_RESET_RE
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_SOFT_RESET_PP
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_SOFT_RESET_E2
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|RADEON_SOFT_RESET_RB
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|RADEON_SOFT_RESET_HDP
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|RADEON_RBBM_STATUS
value|0x0e40
end_define

begin_define
define|#
directive|define
name|RADEON_RBBM_FIFOCNT_MASK
value|0x007f
end_define

begin_define
define|#
directive|define
name|RADEON_RBBM_ACTIVE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_RE_LINE_PATTERN
value|0x1cd0
end_define

begin_define
define|#
directive|define
name|RADEON_RE_MISC
value|0x26c4
end_define

begin_define
define|#
directive|define
name|RADEON_RE_TOP_LEFT
value|0x26c0
end_define

begin_define
define|#
directive|define
name|RADEON_RE_WIDTH_HEIGHT
value|0x1c44
end_define

begin_define
define|#
directive|define
name|RADEON_RE_STIPPLE_ADDR
value|0x1cc8
end_define

begin_define
define|#
directive|define
name|RADEON_RE_STIPPLE_DATA
value|0x1ccc
end_define

begin_define
define|#
directive|define
name|RADEON_SCISSOR_TL_0
value|0x1cd8
end_define

begin_define
define|#
directive|define
name|RADEON_SCISSOR_BR_0
value|0x1cdc
end_define

begin_define
define|#
directive|define
name|RADEON_SCISSOR_TL_1
value|0x1ce0
end_define

begin_define
define|#
directive|define
name|RADEON_SCISSOR_BR_1
value|0x1ce4
end_define

begin_define
define|#
directive|define
name|RADEON_SCISSOR_TL_2
value|0x1ce8
end_define

begin_define
define|#
directive|define
name|RADEON_SCISSOR_BR_2
value|0x1cec
end_define

begin_define
define|#
directive|define
name|RADEON_SE_COORD_FMT
value|0x1c50
end_define

begin_define
define|#
directive|define
name|RADEON_SE_CNTL
value|0x1c4c
end_define

begin_define
define|#
directive|define
name|RADEON_FFACE_CULL_CW
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_BFACE_SOLID
value|(3<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_FFACE_SOLID
value|(3<< 3)
end_define

begin_define
define|#
directive|define
name|RADEON_FLAT_SHADE_VTX_LAST
value|(3<< 6)
end_define

begin_define
define|#
directive|define
name|RADEON_DIFFUSE_SHADE_FLAT
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_DIFFUSE_SHADE_GOURAUD
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_SHADE_FLAT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_SHADE_GOURAUD
value|(2<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_SPECULAR_SHADE_FLAT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_SPECULAR_SHADE_GOURAUD
value|(2<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_FOG_SHADE_FLAT
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_FOG_SHADE_GOURAUD
value|(2<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_VPORT_XY_XFORM_ENABLE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_VPORT_Z_XFORM_ENABLE
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RADEON_VTX_PIX_CENTER_OGL
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_ROUND_MODE_TRUNC
value|(0<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_ROUND_PREC_8TH_PIX
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_SE_CNTL_STATUS
value|0x2140
end_define

begin_define
define|#
directive|define
name|RADEON_SE_LINE_WIDTH
value|0x1db8
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VPORT_XSCALE
value|0x1d98
end_define

begin_define
define|#
directive|define
name|RADEON_SE_ZBIAS_FACTOR
value|0x1db0
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_MATERIAL_EMMISSIVE_RED
value|0x2210
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_OUTPUT_VTX_FMT
value|0x2254
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_VECTOR_INDX_REG
value|0x2200
end_define

begin_define
define|#
directive|define
name|RADEON_VEC_INDX_OCTWORD_STRIDE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_VEC_INDX_DWORD_COUNT_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_VECTOR_DATA_REG
value|0x2204
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_SCALAR_INDX_REG
value|0x2208
end_define

begin_define
define|#
directive|define
name|RADEON_SCAL_INDX_DWORD_STRIDE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_SCALAR_DATA_REG
value|0x220C
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE_ACCESS_FLAGS
value|0x0bf8
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE_ACCESS_CLR
value|0x0bfc
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE_CNTL
value|0x0b00
end_define

begin_define
define|#
directive|define
name|RADEON_SURF_TRANSLATION_DIS
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_NONSURF_AP0_SWP_MASK
value|(3<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_NONSURF_AP0_SWP_LITTLE
value|(0<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_NONSURF_AP0_SWP_BIG16
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_NONSURF_AP0_SWP_BIG32
value|(2<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_NONSURF_AP1_SWP_MASK
value|(3<< 22)
end_define

begin_define
define|#
directive|define
name|RADEON_NONSURF_AP1_SWP_LITTLE
value|(0<< 22)
end_define

begin_define
define|#
directive|define
name|RADEON_NONSURF_AP1_SWP_BIG16
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|RADEON_NONSURF_AP1_SWP_BIG32
value|(2<< 22)
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE0_INFO
value|0x0b0c
end_define

begin_define
define|#
directive|define
name|RADEON_SURF_PITCHSEL_MASK
value|(0x1ff<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_SURF_TILE_MODE_MASK
value|(3<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_SURF_TILE_MODE_MACRO
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_SURF_TILE_MODE_MICRO
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_SURF_TILE_MODE_32BIT_Z
value|(2<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_SURF_TILE_MODE_16BIT_Z
value|(3<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE0_LOWER_BOUND
value|0x0b04
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE0_UPPER_BOUND
value|0x0b08
end_define

begin_define
define|#
directive|define
name|RADEON_SURF_ADDRESS_FIXED_MASK
value|(0x3ff<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE1_INFO
value|0x0b1c
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE1_LOWER_BOUND
value|0x0b14
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE1_UPPER_BOUND
value|0x0b18
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE2_INFO
value|0x0b2c
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE2_LOWER_BOUND
value|0x0b24
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE2_UPPER_BOUND
value|0x0b28
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE3_INFO
value|0x0b3c
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE3_LOWER_BOUND
value|0x0b34
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE3_UPPER_BOUND
value|0x0b38
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE4_INFO
value|0x0b4c
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE4_LOWER_BOUND
value|0x0b44
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE4_UPPER_BOUND
value|0x0b48
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE5_INFO
value|0x0b5c
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE5_LOWER_BOUND
value|0x0b54
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE5_UPPER_BOUND
value|0x0b58
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE6_INFO
value|0x0b6c
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE6_LOWER_BOUND
value|0x0b64
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE6_UPPER_BOUND
value|0x0b68
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE7_INFO
value|0x0b7c
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE7_LOWER_BOUND
value|0x0b74
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE7_UPPER_BOUND
value|0x0b78
end_define

begin_define
define|#
directive|define
name|RADEON_SW_SEMAPHORE
value|0x013c
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_UNTIL
value|0x1720
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_CRTC_PFLIP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_2D_IDLE
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_3D_IDLE
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_2D_IDLECLEAN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_3D_IDLECLEAN
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_HOST_IDLECLEAN
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_ZMASKOFFSET
value|0x3234
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_ZSTENCILCNTL
value|0x1c2c
end_define

begin_define
define|#
directive|define
name|RADEON_DEPTH_FORMAT_16BIT_INT_Z
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_DEPTH_FORMAT_24BIT_INT_Z
value|(2<< 0)
end_define

begin_comment
comment|/* CP registers */
end_comment

begin_define
define|#
directive|define
name|RADEON_CP_ME_RAM_ADDR
value|0x07d4
end_define

begin_define
define|#
directive|define
name|RADEON_CP_ME_RAM_RADDR
value|0x07d8
end_define

begin_define
define|#
directive|define
name|RADEON_CP_ME_RAM_DATAH
value|0x07dc
end_define

begin_define
define|#
directive|define
name|RADEON_CP_ME_RAM_DATAL
value|0x07e0
end_define

begin_define
define|#
directive|define
name|RADEON_CP_RB_BASE
value|0x0700
end_define

begin_define
define|#
directive|define
name|RADEON_CP_RB_CNTL
value|0x0704
end_define

begin_define
define|#
directive|define
name|RADEON_BUF_SWAP_32BIT
value|(2<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_RB_NO_UPDATE
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_CP_RB_RPTR_ADDR
value|0x070c
end_define

begin_define
define|#
directive|define
name|RADEON_CP_RB_RPTR
value|0x0710
end_define

begin_define
define|#
directive|define
name|RADEON_CP_RB_WPTR
value|0x0714
end_define

begin_define
define|#
directive|define
name|RADEON_CP_RB_WPTR_DELAY
value|0x0718
end_define

begin_define
define|#
directive|define
name|RADEON_PRE_WRITE_TIMER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_PRE_WRITE_LIMIT_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|RADEON_CP_IB_BASE
value|0x0738
end_define

begin_define
define|#
directive|define
name|RADEON_CP_CSQ_CNTL
value|0x0740
end_define

begin_define
define|#
directive|define
name|RADEON_CSQ_CNT_PRIMARY_MASK
value|(0xff<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_CSQ_PRIDIS_INDDIS
value|(0<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_CSQ_PRIPIO_INDDIS
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_CSQ_PRIBM_INDDIS
value|(2<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_CSQ_PRIPIO_INDBM
value|(3<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_CSQ_PRIBM_INDBM
value|(4<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_CSQ_PRIPIO_INDPIO
value|(15<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_AIC_CNTL
value|0x01d0
end_define

begin_define
define|#
directive|define
name|RADEON_PCIGART_TRANSLATE_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_AIC_STAT
value|0x01d4
end_define

begin_define
define|#
directive|define
name|RADEON_AIC_PT_BASE
value|0x01d8
end_define

begin_define
define|#
directive|define
name|RADEON_AIC_LO_ADDR
value|0x01dc
end_define

begin_define
define|#
directive|define
name|RADEON_AIC_HI_ADDR
value|0x01e0
end_define

begin_define
define|#
directive|define
name|RADEON_AIC_TLB_ADDR
value|0x01e4
end_define

begin_define
define|#
directive|define
name|RADEON_AIC_TLB_DATA
value|0x01e8
end_define

begin_comment
comment|/* CP command packets */
end_comment

begin_define
define|#
directive|define
name|RADEON_CP_PACKET0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RADEON_ONE_REG_WR
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET1
value|0x40000000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET2
value|0x80000000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_NOP
value|0x00001000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_NEXT_CHAR
value|0x00001900
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PLY_NEXTSCAN
value|0x00001D00
end_define

begin_define
define|#
directive|define
name|RADEON_CP_SET_SCISSORS
value|0x00001E00
end_define

begin_comment
comment|/* GEN_INDX_PRIM is unsupported starting with R300 */
end_comment

begin_define
define|#
directive|define
name|RADEON_3D_RNDR_GEN_INDX_PRIM
value|0x00002300
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_FOR_IDLE
value|0x00002600
end_define

begin_define
define|#
directive|define
name|RADEON_3D_DRAW_VBUF
value|0x00002800
end_define

begin_define
define|#
directive|define
name|RADEON_3D_DRAW_IMMD
value|0x00002900
end_define

begin_define
define|#
directive|define
name|RADEON_3D_DRAW_INDX
value|0x00002A00
end_define

begin_define
define|#
directive|define
name|RADEON_CP_LOAD_PALETTE
value|0x00002C00
end_define

begin_define
define|#
directive|define
name|RADEON_3D_LOAD_VBPNTR
value|0x00002F00
end_define

begin_define
define|#
directive|define
name|RADEON_MPEG_IDCT_MACROBLOCK
value|0x00003000
end_define

begin_define
define|#
directive|define
name|RADEON_MPEG_IDCT_MACROBLOCK_REV
value|0x00003100
end_define

begin_define
define|#
directive|define
name|RADEON_3D_CLEAR_ZMASK
value|0x00003200
end_define

begin_define
define|#
directive|define
name|RADEON_CP_INDX_BUFFER
value|0x00003300
end_define

begin_define
define|#
directive|define
name|RADEON_CP_3D_DRAW_VBUF_2
value|0x00003400
end_define

begin_define
define|#
directive|define
name|RADEON_CP_3D_DRAW_IMMD_2
value|0x00003500
end_define

begin_define
define|#
directive|define
name|RADEON_CP_3D_DRAW_INDX_2
value|0x00003600
end_define

begin_define
define|#
directive|define
name|RADEON_3D_CLEAR_HIZ
value|0x00003700
end_define

begin_define
define|#
directive|define
name|RADEON_CP_3D_CLEAR_CMASK
value|0x00003802
end_define

begin_define
define|#
directive|define
name|RADEON_CNTL_HOSTDATA_BLT
value|0x00009400
end_define

begin_define
define|#
directive|define
name|RADEON_CNTL_PAINT_MULTI
value|0x00009A00
end_define

begin_define
define|#
directive|define
name|RADEON_CNTL_BITBLT_MULTI
value|0x00009B00
end_define

begin_define
define|#
directive|define
name|RADEON_CNTL_SET_SCISSORS
value|0xC0001E00
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET_MASK
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET_COUNT_MASK
value|0x3fff0000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET0_REG_MASK
value|0x000007ff
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET1_REG0_MASK
value|0x000007ff
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET1_REG1_MASK
value|0x003ff800
end_define

begin_define
define|#
directive|define
name|RADEON_VTX_Z_PRESENT
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_VTX_PKCOLOR_PRESENT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RADEON_PRIM_TYPE_NONE
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_PRIM_TYPE_POINT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_PRIM_TYPE_LINE
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_PRIM_TYPE_LINE_STRIP
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_PRIM_TYPE_TRI_LIST
value|(4<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_PRIM_TYPE_TRI_FAN
value|(5<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_PRIM_TYPE_TRI_STRIP
value|(6<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_PRIM_TYPE_TRI_TYPE2
value|(7<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_PRIM_TYPE_RECT_LIST
value|(8<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_PRIM_TYPE_3VRT_POINT_LIST
value|(9<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_PRIM_TYPE_3VRT_LINE_LIST
value|(10<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_PRIM_TYPE_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|RADEON_PRIM_WALK_IND
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_PRIM_WALK_LIST
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_PRIM_WALK_RING
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ORDER_BGRA
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ORDER_RGBA
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|RADEON_MAOS_ENABLE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|RADEON_VTX_FMT_R128_MODE
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_VTX_FMT_RADEON_MODE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_NUM_VERTICES_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_FORMAT_CI8
value|2
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_FORMAT_ARGB1555
value|3
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_FORMAT_RGB565
value|4
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_FORMAT_ARGB8888
value|6
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_FORMAT_RGB332
value|7
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_FORMAT_RGB8
value|9
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_FORMAT_ARGB4444
value|15
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_I8
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_AI88
value|1
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_RGB332
value|2
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_ARGB1555
value|3
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_RGB565
value|4
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_ARGB4444
value|5
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_ARGB8888
value|6
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_RGBA8888
value|7
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_Y8
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_VYUY422
value|10
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_YVYU422
value|11
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_DXT1
value|12
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_DXT23
value|14
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_DXT45
value|15
end_define

begin_define
define|#
directive|define
name|R200_PP_TXCBLEND_0
value|0x2f00
end_define

begin_define
define|#
directive|define
name|R200_PP_TXCBLEND_1
value|0x2f10
end_define

begin_define
define|#
directive|define
name|R200_PP_TXCBLEND_2
value|0x2f20
end_define

begin_define
define|#
directive|define
name|R200_PP_TXCBLEND_3
value|0x2f30
end_define

begin_define
define|#
directive|define
name|R200_PP_TXCBLEND_4
value|0x2f40
end_define

begin_define
define|#
directive|define
name|R200_PP_TXCBLEND_5
value|0x2f50
end_define

begin_define
define|#
directive|define
name|R200_PP_TXCBLEND_6
value|0x2f60
end_define

begin_define
define|#
directive|define
name|R200_PP_TXCBLEND_7
value|0x2f70
end_define

begin_define
define|#
directive|define
name|R200_SE_TCL_LIGHT_MODEL_CTL_0
value|0x2268
end_define

begin_define
define|#
directive|define
name|R200_PP_TFACTOR_0
value|0x2ee0
end_define

begin_define
define|#
directive|define
name|R200_SE_VTX_FMT_0
value|0x2088
end_define

begin_define
define|#
directive|define
name|R200_SE_VAP_CNTL
value|0x2080
end_define

begin_define
define|#
directive|define
name|R200_SE_TCL_MATRIX_SEL_0
value|0x2230
end_define

begin_define
define|#
directive|define
name|R200_SE_TCL_TEX_PROC_CTL_2
value|0x22a8
end_define

begin_define
define|#
directive|define
name|R200_SE_TCL_UCP_VERT_BLEND_CTL
value|0x22c0
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFILTER_5
value|0x2ca0
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFILTER_4
value|0x2c80
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFILTER_3
value|0x2c60
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFILTER_2
value|0x2c40
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFILTER_1
value|0x2c20
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFILTER_0
value|0x2c00
end_define

begin_define
define|#
directive|define
name|R200_PP_TXOFFSET_5
value|0x2d78
end_define

begin_define
define|#
directive|define
name|R200_PP_TXOFFSET_4
value|0x2d60
end_define

begin_define
define|#
directive|define
name|R200_PP_TXOFFSET_3
value|0x2d48
end_define

begin_define
define|#
directive|define
name|R200_PP_TXOFFSET_2
value|0x2d30
end_define

begin_define
define|#
directive|define
name|R200_PP_TXOFFSET_1
value|0x2d18
end_define

begin_define
define|#
directive|define
name|R200_PP_TXOFFSET_0
value|0x2d00
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_FACES_0
value|0x2c18
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_FACES_1
value|0x2c38
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_FACES_2
value|0x2c58
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_FACES_3
value|0x2c78
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_FACES_4
value|0x2c98
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_FACES_5
value|0x2cb8
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F1_0
value|0x2d04
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F2_0
value|0x2d08
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F3_0
value|0x2d0c
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F4_0
value|0x2d10
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F5_0
value|0x2d14
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F1_1
value|0x2d1c
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F2_1
value|0x2d20
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F3_1
value|0x2d24
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F4_1
value|0x2d28
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F5_1
value|0x2d2c
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F1_2
value|0x2d34
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F2_2
value|0x2d38
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F3_2
value|0x2d3c
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F4_2
value|0x2d40
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F5_2
value|0x2d44
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F1_3
value|0x2d4c
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F2_3
value|0x2d50
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F3_3
value|0x2d54
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F4_3
value|0x2d58
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F5_3
value|0x2d5c
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F1_4
value|0x2d64
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F2_4
value|0x2d68
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F3_4
value|0x2d6c
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F4_4
value|0x2d70
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F5_4
value|0x2d74
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F1_5
value|0x2d7c
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F2_5
value|0x2d80
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F3_5
value|0x2d84
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F4_5
value|0x2d88
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F5_5
value|0x2d8c
end_define

begin_define
define|#
directive|define
name|R200_RE_AUX_SCISSOR_CNTL
value|0x26f0
end_define

begin_define
define|#
directive|define
name|R200_SE_VTE_CNTL
value|0x20b0
end_define

begin_define
define|#
directive|define
name|R200_SE_TCL_OUTPUT_VTX_COMP_SEL
value|0x2250
end_define

begin_define
define|#
directive|define
name|R200_PP_TAM_DEBUG3
value|0x2d9c
end_define

begin_define
define|#
directive|define
name|R200_PP_CNTL_X
value|0x2cc4
end_define

begin_define
define|#
directive|define
name|R200_SE_VAP_CNTL_STATUS
value|0x2140
end_define

begin_define
define|#
directive|define
name|R200_RE_SCISSOR_TL_0
value|0x1cd8
end_define

begin_define
define|#
directive|define
name|R200_RE_SCISSOR_TL_1
value|0x1ce0
end_define

begin_define
define|#
directive|define
name|R200_RE_SCISSOR_TL_2
value|0x1ce8
end_define

begin_define
define|#
directive|define
name|R200_RB3D_DEPTHXY_OFFSET
value|0x1d60
end_define

begin_define
define|#
directive|define
name|R200_RE_AUX_SCISSOR_CNTL
value|0x26f0
end_define

begin_define
define|#
directive|define
name|R200_SE_VTX_STATE_CNTL
value|0x2180
end_define

begin_define
define|#
directive|define
name|R200_RE_POINTSIZE
value|0x2648
end_define

begin_define
define|#
directive|define
name|R200_SE_TCL_INPUT_VTX_VECTOR_ADDR_0
value|0x2254
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TEX_SIZE_0
value|0x1d04
end_define

begin_comment
comment|/* NPOT */
end_comment

begin_define
define|#
directive|define
name|RADEON_PP_TEX_SIZE_1
value|0x1d0c
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TEX_SIZE_2
value|0x1d14
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_FACES_0
value|0x1d24
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_FACES_1
value|0x1d28
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_FACES_2
value|0x1d2c
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_OFFSET_T0_0
value|0x1dd0
end_define

begin_comment
comment|/* bits [31:5] */
end_comment

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_OFFSET_T1_0
value|0x1e00
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_OFFSET_T2_0
value|0x1e14
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_STATE_FLUSH
value|0x2284
end_define

begin_define
define|#
directive|define
name|SE_VAP_CNTL__TCL_ENA_MASK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SE_VAP_CNTL__FORCE_W_TO_ONE_MASK
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SE_VAP_CNTL__VF_MAX_VTX_NUM__SHIFT
value|0x00000012
end_define

begin_define
define|#
directive|define
name|SE_VTE_CNTL__VTX_XY_FMT_MASK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SE_VTE_CNTL__VTX_Z_FMT_MASK
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SE_VTX_FMT_0__VTX_Z0_PRESENT_MASK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SE_VTX_FMT_0__VTX_W0_PRESENT_MASK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SE_VTX_FMT_0__VTX_COLOR_0_FMT__SHIFT
value|0x0000000b
end_define

begin_define
define|#
directive|define
name|R200_3D_DRAW_IMMD_2
value|0xC0003500
end_define

begin_define
define|#
directive|define
name|R200_SE_VTX_FMT_1
value|0x208c
end_define

begin_define
define|#
directive|define
name|R200_RE_CNTL
value|0x1c50
end_define

begin_define
define|#
directive|define
name|R200_RB3D_BLENDCOLOR
value|0x3218
end_define

begin_define
define|#
directive|define
name|R200_SE_TCL_POINT_SPRITE_CNTL
value|0x22c4
end_define

begin_define
define|#
directive|define
name|R200_PP_TRI_PERF
value|0x2cf8
end_define

begin_define
define|#
directive|define
name|R200_PP_AFS_0
value|0x2f80
end_define

begin_define
define|#
directive|define
name|R200_PP_AFS_1
value|0x2f00
end_define

begin_comment
comment|/* same as txcblend_0 */
end_comment

begin_define
define|#
directive|define
name|R200_VAP_PVS_CNTL_1
value|0x22D0
end_define

begin_comment
comment|/* MPEG settings from VHA code */
end_comment

begin_define
define|#
directive|define
name|RADEON_VHA_SETTO16_1
value|0x2694
end_define

begin_define
define|#
directive|define
name|RADEON_VHA_SETTO16_2
value|0x2680
end_define

begin_define
define|#
directive|define
name|RADEON_VHA_SETTO0_1
value|0x1840
end_define

begin_define
define|#
directive|define
name|RADEON_VHA_FB_OFFSET
value|0x19e4
end_define

begin_define
define|#
directive|define
name|RADEON_VHA_SETTO1AND70S
value|0x19d8
end_define

begin_define
define|#
directive|define
name|RADEON_VHA_DST_PITCH
value|0x1408
end_define

begin_comment
comment|// set as reference header
end_comment

begin_define
define|#
directive|define
name|RADEON_VHA_BACKFRAME0_OFF_Y
value|0x1840
end_define

begin_define
define|#
directive|define
name|RADEON_VHA_BACKFRAME1_OFF_PITCH_Y
value|0x1844
end_define

begin_define
define|#
directive|define
name|RADEON_VHA_BACKFRAME0_OFF_U
value|0x1848
end_define

begin_define
define|#
directive|define
name|RADEON_VHA_BACKFRAME1_OFF_PITCH_U
value|0x184c
end_define

begin_define
define|#
directive|define
name|RADOEN_VHA_BACKFRAME0_OFF_V
value|0x1850
end_define

begin_define
define|#
directive|define
name|RADEON_VHA_BACKFRAME1_OFF_PITCH_V
value|0x1854
end_define

begin_define
define|#
directive|define
name|RADEON_VHA_FORWFRAME0_OFF_Y
value|0x1858
end_define

begin_define
define|#
directive|define
name|RADEON_VHA_FORWFRAME1_OFF_PITCH_Y
value|0x185c
end_define

begin_define
define|#
directive|define
name|RADEON_VHA_FORWFRAME0_OFF_U
value|0x1860
end_define

begin_define
define|#
directive|define
name|RADEON_VHA_FORWFRAME1_OFF_PITCH_U
value|0x1864
end_define

begin_define
define|#
directive|define
name|RADEON_VHA_FORWFRAME0_OFF_V
value|0x1868
end_define

begin_define
define|#
directive|define
name|RADEON_VHA_FORWFRAME0_OFF_PITCH_V
value|0x1880
end_define

begin_define
define|#
directive|define
name|RADEON_VHA_BACKFRAME0_OFF_Y_2
value|0x1884
end_define

begin_define
define|#
directive|define
name|RADEON_VHA_BACKFRAME1_OFF_PITCH_Y_2
value|0x1888
end_define

begin_define
define|#
directive|define
name|RADEON_VHA_BACKFRAME0_OFF_U_2
value|0x188c
end_define

begin_define
define|#
directive|define
name|RADEON_VHA_BACKFRAME1_OFF_PITCH_U_2
value|0x1890
end_define

begin_define
define|#
directive|define
name|RADEON_VHA_BACKFRAME0_OFF_V_2
value|0x1894
end_define

begin_define
define|#
directive|define
name|RADEON_VHA_BACKFRAME1_OFF_PITCH_V_2
value|0x1898
end_define

begin_comment
comment|/* Constants */
end_comment

begin_define
define|#
directive|define
name|RADEON_MAX_USEC_TIMEOUT
value|100000
end_define

begin_comment
comment|/* 100 ms */
end_comment

begin_define
define|#
directive|define
name|RADEON_LAST_FRAME_REG
value|RADEON_SCRATCH_REG0
end_define

begin_define
define|#
directive|define
name|RADEON_LAST_DISPATCH_REG
value|RADEON_SCRATCH_REG1
end_define

begin_define
define|#
directive|define
name|RADEON_LAST_CLEAR_REG
value|RADEON_SCRATCH_REG2
end_define

begin_define
define|#
directive|define
name|RADEON_LAST_SWI_REG
value|RADEON_SCRATCH_REG3
end_define

begin_define
define|#
directive|define
name|RADEON_LAST_DISPATCH
value|1
end_define

begin_define
define|#
directive|define
name|RADEON_MAX_VB_AGE
value|0x7fffffff
end_define

begin_define
define|#
directive|define
name|RADEON_MAX_VB_VERTS
value|(0xffff)
end_define

begin_define
define|#
directive|define
name|RADEON_RING_HIGH_MARK
value|128
end_define

begin_define
define|#
directive|define
name|RADEON_PCIGART_TABLE_SIZE
value|(32*1024)
end_define

begin_define
define|#
directive|define
name|RADEON_READ
parameter_list|(
name|reg
parameter_list|)
value|DRM_READ32(  dev_priv->mmio, (reg) )
end_define

begin_define
define|#
directive|define
name|RADEON_WRITE
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
value|DRM_WRITE32( dev_priv->mmio, (reg), (val) )
end_define

begin_define
define|#
directive|define
name|RADEON_READ8
parameter_list|(
name|reg
parameter_list|)
value|DRM_READ8(  dev_priv->mmio, (reg) )
end_define

begin_define
define|#
directive|define
name|RADEON_WRITE8
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
value|DRM_WRITE8( dev_priv->mmio, (reg), (val) )
end_define

begin_define
define|#
directive|define
name|RADEON_WRITE_PLL
parameter_list|(
name|addr
parameter_list|,
name|val
parameter_list|)
define|\
value|do {									\ 	RADEON_WRITE8( RADEON_CLOCK_CNTL_INDEX,				\ 		       ((addr)& 0x1f) | RADEON_PLL_WR_EN );		\ 	RADEON_WRITE( RADEON_CLOCK_CNTL_DATA, (val) );			\ } while (0)
end_define

begin_define
define|#
directive|define
name|RADEON_WRITE_PCIE
parameter_list|(
name|addr
parameter_list|,
name|val
parameter_list|)
define|\
value|do {									\ 	RADEON_WRITE8( RADEON_PCIE_INDEX,				\ 			((addr)& 0xff));				\ 	RADEON_WRITE( RADEON_PCIE_DATA, (val) );			\ } while (0)
end_define

begin_define
define|#
directive|define
name|CP_PACKET0
parameter_list|(
name|reg
parameter_list|,
name|n
parameter_list|)
define|\
value|(RADEON_CP_PACKET0 | ((n)<< 16) | ((reg)>> 2))
end_define

begin_define
define|#
directive|define
name|CP_PACKET0_TABLE
parameter_list|(
name|reg
parameter_list|,
name|n
parameter_list|)
define|\
value|(RADEON_CP_PACKET0 | RADEON_ONE_REG_WR | ((n)<< 16) | ((reg)>> 2))
end_define

begin_define
define|#
directive|define
name|CP_PACKET1
parameter_list|(
name|reg0
parameter_list|,
name|reg1
parameter_list|)
define|\
value|(RADEON_CP_PACKET1 | (((reg1)>> 2)<< 15) | ((reg0)>> 2))
end_define

begin_define
define|#
directive|define
name|CP_PACKET2
parameter_list|()
define|\
value|(RADEON_CP_PACKET2)
end_define

begin_define
define|#
directive|define
name|CP_PACKET3
parameter_list|(
name|pkt
parameter_list|,
name|n
parameter_list|)
define|\
value|(RADEON_CP_PACKET3 | (pkt) | ((n)<< 16))
end_define

begin_comment
comment|/* ================================================================  * Engine control helper macros  */
end_comment

begin_define
define|#
directive|define
name|RADEON_WAIT_UNTIL_2D_IDLE
parameter_list|()
value|do {				\ 	OUT_RING( CP_PACKET0( RADEON_WAIT_UNTIL, 0 ) );			\ 	OUT_RING( (RADEON_WAIT_2D_IDLECLEAN |				\ 		   RADEON_WAIT_HOST_IDLECLEAN) );			\ } while (0)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_UNTIL_3D_IDLE
parameter_list|()
value|do {				\ 	OUT_RING( CP_PACKET0( RADEON_WAIT_UNTIL, 0 ) );			\ 	OUT_RING( (RADEON_WAIT_3D_IDLECLEAN |				\ 		   RADEON_WAIT_HOST_IDLECLEAN) );			\ } while (0)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_UNTIL_IDLE
parameter_list|()
value|do {					\ 	OUT_RING( CP_PACKET0( RADEON_WAIT_UNTIL, 0 ) );			\ 	OUT_RING( (RADEON_WAIT_2D_IDLECLEAN |				\ 		   RADEON_WAIT_3D_IDLECLEAN |				\ 		   RADEON_WAIT_HOST_IDLECLEAN) );			\ } while (0)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_UNTIL_PAGE_FLIPPED
parameter_list|()
value|do {				\ 	OUT_RING( CP_PACKET0( RADEON_WAIT_UNTIL, 0 ) );			\ 	OUT_RING( RADEON_WAIT_CRTC_PFLIP );				\ } while (0)
end_define

begin_define
define|#
directive|define
name|RADEON_FLUSH_CACHE
parameter_list|()
value|do {					\ 	OUT_RING( CP_PACKET0( RADEON_RB3D_DSTCACHE_CTLSTAT, 0 ) );	\ 	OUT_RING( RADEON_RB3D_DC_FLUSH );				\ } while (0)
end_define

begin_define
define|#
directive|define
name|RADEON_PURGE_CACHE
parameter_list|()
value|do {					\ 	OUT_RING( CP_PACKET0( RADEON_RB3D_DSTCACHE_CTLSTAT, 0 ) );	\ 	OUT_RING( RADEON_RB3D_DC_FLUSH_ALL );				\ } while (0)
end_define

begin_define
define|#
directive|define
name|RADEON_FLUSH_ZCACHE
parameter_list|()
value|do {					\ 	OUT_RING( CP_PACKET0( RADEON_RB3D_ZCACHE_CTLSTAT, 0 ) );	\ 	OUT_RING( RADEON_RB3D_ZC_FLUSH );				\ } while (0)
end_define

begin_define
define|#
directive|define
name|RADEON_PURGE_ZCACHE
parameter_list|()
value|do {					\ 	OUT_RING( CP_PACKET0( RADEON_RB3D_ZCACHE_CTLSTAT, 0 ) );	\ 	OUT_RING( RADEON_RB3D_ZC_FLUSH_ALL );				\ } while (0)
end_define

begin_comment
comment|/* ================================================================  * Misc helper macros  */
end_comment

begin_comment
comment|/* Perfbox functionality only.  */
end_comment

begin_define
define|#
directive|define
name|RING_SPACE_TEST_WITH_RETURN
parameter_list|(
name|dev_priv
parameter_list|)
define|\
value|do {									\ 	if (!(dev_priv->stats.boxes& RADEON_BOX_DMA_IDLE)) {		\ 		u32 head = GET_RING_HEAD( dev_priv );			\ 		if (head == dev_priv->ring.tail)			\ 			dev_priv->stats.boxes |= RADEON_BOX_DMA_IDLE;	\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|VB_AGE_TEST_WITH_RETURN
parameter_list|(
name|dev_priv
parameter_list|)
define|\
value|do {									\ 	drm_radeon_sarea_t *sarea_priv = dev_priv->sarea_priv;		\ 	if ( sarea_priv->last_dispatch>= RADEON_MAX_VB_AGE ) {		\ 		int __ret = radeon_do_cp_idle( dev_priv );		\ 		if ( __ret ) return __ret;				\ 		sarea_priv->last_dispatch = 0;				\ 		radeon_freelist_reset( dev );				\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|RADEON_DISPATCH_AGE
parameter_list|(
name|age
parameter_list|)
value|do {					\ 	OUT_RING( CP_PACKET0( RADEON_LAST_DISPATCH_REG, 0 ) );		\ 	OUT_RING( age );						\ } while (0)
end_define

begin_define
define|#
directive|define
name|RADEON_FRAME_AGE
parameter_list|(
name|age
parameter_list|)
value|do {					\ 	OUT_RING( CP_PACKET0( RADEON_LAST_FRAME_REG, 0 ) );		\ 	OUT_RING( age );						\ } while (0)
end_define

begin_define
define|#
directive|define
name|RADEON_CLEAR_AGE
parameter_list|(
name|age
parameter_list|)
value|do {					\ 	OUT_RING( CP_PACKET0( RADEON_LAST_CLEAR_REG, 0 ) );		\ 	OUT_RING( age );						\ } while (0)
end_define

begin_comment
comment|/* ================================================================  * Ring control  */
end_comment

begin_define
define|#
directive|define
name|RADEON_VERBOSE
value|0
end_define

begin_define
define|#
directive|define
name|RING_LOCALS
value|int write, _nr; unsigned int mask; u32 *ring;
end_define

begin_define
define|#
directive|define
name|BEGIN_RING
parameter_list|(
name|n
parameter_list|)
value|do {						\ 	if ( RADEON_VERBOSE ) {						\ 		DRM_INFO( "BEGIN_RING( %d ) in %s\n",			\ 			   n, __FUNCTION__ );				\ 	}								\ 	if ( dev_priv->ring.space<= (n) * sizeof(u32) ) {		\ 		COMMIT_RING();						\ 		radeon_wait_ring( dev_priv, (n) * sizeof(u32) );	\ 	}								\ 	_nr = n; dev_priv->ring.space -= (n) * sizeof(u32);		\ 	ring = dev_priv->ring.start;					\ 	write = dev_priv->ring.tail;					\ 	mask = dev_priv->ring.tail_mask;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|ADVANCE_RING
parameter_list|()
value|do {						\ 	if ( RADEON_VERBOSE ) {						\ 		DRM_INFO( "ADVANCE_RING() wr=0x%06x tail=0x%06x\n",	\ 			  write, dev_priv->ring.tail );			\ 	}								\ 	if (((dev_priv->ring.tail + _nr)& mask) != write) {		\ 		DRM_ERROR( 						\ 			"ADVANCE_RING(): mismatch: nr: %x write: %x line: %d\n",	\ 			((dev_priv->ring.tail + _nr)& mask),		\ 			write, __LINE__);						\ 	} else								\ 		dev_priv->ring.tail = write;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|COMMIT_RING
parameter_list|()
value|do {						\
comment|/* Flush writes to ring */
value|\ 	DRM_MEMORYBARRIER();						\ 	GET_RING_HEAD( dev_priv );					\ 	RADEON_WRITE( RADEON_CP_RB_WPTR, dev_priv->ring.tail );		\
comment|/* read from PCI bus to ensure correct posting */
value|\ 	RADEON_READ( RADEON_CP_RB_RPTR );				\ } while (0)
end_define

begin_define
define|#
directive|define
name|OUT_RING
parameter_list|(
name|x
parameter_list|)
value|do {						\ 	if ( RADEON_VERBOSE ) {						\ 		DRM_INFO( "   OUT_RING( 0x%08x ) at 0x%x\n",		\ 			   (unsigned int)(x), write );			\ 	}								\ 	ring[write++] = (x);						\ 	write&= mask;							\ } while (0)
end_define

begin_define
define|#
directive|define
name|OUT_RING_REG
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
value|do {					\ 	OUT_RING( CP_PACKET0( reg, 0 ) );				\ 	OUT_RING( val );						\ } while (0)
end_define

begin_define
define|#
directive|define
name|OUT_RING_TABLE
parameter_list|(
name|tab
parameter_list|,
name|sz
parameter_list|)
value|do {				\ 	int _size = (sz);					\ 	int *_tab = (int *)(tab);				\ 								\ 	if (write + _size> mask) {				\ 		int _i = (mask+1) - write;			\ 		_size -= _i;					\ 		while (_i> 0) {				\ 			*(int *)(ring + write) = *_tab++;	\ 			write++;				\ 			_i--;					\ 		}						\ 		write = 0;					\ 		_tab += _i;					\ 	}							\ 	while (_size> 0) {					\ 		*(ring + write) = *_tab++;			\ 		write++;					\ 		_size--;					\ 	}							\ 	write&= mask;						\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __RADEON_DRV_H__ */
end_comment

end_unit

