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
value|"20080613"
end_define

begin_comment
comment|/* Interface history:  *  * 1.1 - ??  * 1.2 - Add vertex2 ioctl (keith)  *     - Add stencil capability to clear ioctl (gareth, keith)  *     - Increase MAX_TEXTURE_LEVELS (brian)  * 1.3 - Add cmdbuf ioctl (keith)  *     - Add support for new radeon packets (keith)  *     - Add getparam ioctl (keith)  *     - Add flip-buffers ioctl, deprecate fullscreen foo (keith).  * 1.4 - Add scratch registers to get_param ioctl.  * 1.5 - Add r200 packets to cmdbuf ioctl  *     - Add r200 function to init ioctl  *     - Add 'scalar2' instruction to cmdbuf  * 1.6 - Add static GART memory manager  *       Add irq handler (won't be turned on unless X server knows to)  *       Add irq ioctls and irq_active getparam.  *       Add wait command for cmdbuf ioctl  *       Add GART offset query for getparam  * 1.7 - Add support for cube map registers: R200_PP_CUBIC_FACES_[0..5]  *       and R200_PP_CUBIC_OFFSET_F1_[0..5].  *       Added packets R200_EMIT_PP_CUBIC_FACES_[0..5] and  *       R200_EMIT_PP_CUBIC_OFFSETS_[0..5].  (brian)  * 1.8 - Remove need to call cleanup ioctls on last client exit (keith)  *       Add 'GET' queries for starting additional clients on different VT's.  * 1.9 - Add DRM_IOCTL_RADEON_CP_RESUME ioctl.  *       Add texture rectangle support for r100.  * 1.10- Add SETPARAM ioctl; first parameter to set is FB_LOCATION, which  *       clients use to tell the DRM where they think the framebuffer is  *       located in the card's address space  * 1.11- Add packet R200_EMIT_RB3D_BLENDCOLOR to support GL_EXT_blend_color  *       and GL_EXT_blend_[func|equation]_separate on r200  * 1.12- Add R300 CP microcode support - this just loads the CP on r300  *       (No 3D support yet - just microcode loading).  * 1.13- Add packet R200_EMIT_TCL_POINT_SPRITE_CNTL for ARB_point_parameters  *     - Add hyperz support, add hyperz flags to clear ioctl.  * 1.14- Add support for color tiling  *     - Add R100/R200 surface allocation/free support  * 1.15- Add support for texture micro tiling  *     - Add support for r100 cube maps  * 1.16- Add R200_EMIT_PP_TRI_PERF_CNTL packet to support brilinear  *       texture filtering on r200  * 1.17- Add initial support for R300 (3D).  * 1.18- Add support for GL_ATI_fragment_shader, new packets  *       R200_EMIT_PP_AFS_0/1, R200_EMIT_PP_TXCTLALL_0-5 (replaces  *       R200_EMIT_PP_TXFILTER_0-5, 2 more regs) and R200_EMIT_ATF_TFACTOR  *       (replaces R200_EMIT_TFACTOR_0 (8 consts instead of 6)  * 1.19- Add support for gart table in FB memory and PCIE r300  * 1.20- Add support for r300 texrect  * 1.21- Add support for card type getparam  * 1.22- Add support for texture cache flushes (R300_TX_CNTL)  * 1.23- Add new radeon memory map work from benh  * 1.24- Add general-purpose packet for manipulating scratch registers (r300)  * 1.25- Add support for r200 vertex programs (R200_EMIT_VAP_PVS_CNTL,  *       new packet type)  * 1.26- Add support for variable size PCI(E) gart aperture  * 1.27- Add support for IGP GART  * 1.28- Add support for VBL on CRTC2  * 1.29- R500 3D cmd buffer support  * 1.30- Add support for occlusion queries  * 1.31- Add support for num Z pipes from GET_PARAM  */
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
value|31
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
name|CHIP_R423
block|,
name|CHIP_RV410
block|,
name|CHIP_RS400
block|,
name|CHIP_RS480
block|,
name|CHIP_RS600
block|,
name|CHIP_RS690
block|,
name|CHIP_RS740
block|,
name|CHIP_RV515
block|,
name|CHIP_R520
block|,
name|CHIP_RV530
block|,
name|CHIP_RV560
block|,
name|CHIP_RV570
block|,
name|CHIP_R580
block|,
name|CHIP_R600
block|,
name|CHIP_RV610
block|,
name|CHIP_RV630
block|,
name|CHIP_RV670
block|,
name|CHIP_RV620
block|,
name|CHIP_RV635
block|,
name|CHIP_RS780
block|,
name|CHIP_RS880
block|,
name|CHIP_RV770
block|,
name|CHIP_RV730
block|,
name|CHIP_RV710
block|,
name|CHIP_RV740
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
name|RADEON_FAMILY_MASK
init|=
literal|0x0000ffffUL
block|,
name|RADEON_FLAGS_MASK
init|=
literal|0xffff0000UL
block|,
name|RADEON_IS_MOBILITY
init|=
literal|0x00010000UL
block|,
name|RADEON_IS_IGP
init|=
literal|0x00020000UL
block|,
name|RADEON_SINGLE_CRTC
init|=
literal|0x00040000UL
block|,
name|RADEON_IS_AGP
init|=
literal|0x00080000UL
block|,
name|RADEON_HAS_HIERZ
init|=
literal|0x00100000UL
block|,
name|RADEON_IS_PCIE
init|=
literal|0x00200000UL
block|,
name|RADEON_NEW_MEMMAP
init|=
literal|0x00400000UL
block|,
name|RADEON_IS_PCI
init|=
literal|0x00800000UL
block|,
name|RADEON_IS_IGPGART
init|=
literal|0x01000000UL
block|, }
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|drm_radeon_freelist
block|{
name|unsigned
name|int
name|age
decl_stmt|;
name|struct
name|drm_buf
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
name|int
name|rptr_update
decl_stmt|;
comment|/* Double Words */
name|int
name|rptr_update_l2qw
decl_stmt|;
comment|/* log2 Quad Words */
name|int
name|fetch_size
decl_stmt|;
comment|/* Double Words */
name|int
name|fetch_size_l2ow
decl_stmt|;
comment|/* log2 Oct Words */
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
name|struct
name|drm_file
modifier|*
name|file_priv
decl_stmt|;
comment|/* NULL: free, -1: heap, other: real files */
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
name|struct
name|drm_file
modifier|*
name|file_priv
decl_stmt|;
define|#
directive|define
name|PCIGART_FILE_PRIV
value|((void *) -1L)
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_radeon_kernel_chunk
block|{
name|uint32_t
name|chunk_id
decl_stmt|;
name|uint32_t
name|length_dw
decl_stmt|;
name|uint32_t
name|__user
modifier|*
name|chunk_data
decl_stmt|;
name|uint32_t
modifier|*
name|kdata
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_radeon_cs_parser
block|{
name|struct
name|drm_device
modifier|*
name|dev
decl_stmt|;
name|struct
name|drm_file
modifier|*
name|file_priv
decl_stmt|;
name|uint32_t
name|num_chunks
decl_stmt|;
name|struct
name|drm_radeon_kernel_chunk
modifier|*
name|chunks
decl_stmt|;
name|int
name|ib_index
decl_stmt|;
name|int
name|reloc_index
decl_stmt|;
name|uint32_t
name|card_offset
decl_stmt|;
name|void
modifier|*
name|ib
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* command submission struct */
end_comment

begin_struct
struct|struct
name|drm_radeon_cs_priv
block|{
name|struct
name|mtx
name|cs_mutex
decl_stmt|;
name|uint32_t
name|id_wcnt
decl_stmt|;
name|uint32_t
name|id_scnt
decl_stmt|;
name|uint32_t
name|id_last_wcnt
decl_stmt|;
name|uint32_t
name|id_last_scnt
decl_stmt|;
name|int
function_decl|(
modifier|*
name|parse
function_decl|)
parameter_list|(
name|struct
name|drm_radeon_cs_parser
modifier|*
name|parser
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|id_emit
function_decl|)
parameter_list|(
name|struct
name|drm_radeon_cs_parser
modifier|*
name|parser
parameter_list|,
name|uint32_t
modifier|*
name|id
parameter_list|)
function_decl|;
name|uint32_t
function_decl|(
modifier|*
name|id_last_get
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
comment|/* this ib handling callback are for hidding memory manager drm 	 * from memory manager less drm, free have to emit ib discard 	 * sequence into the ring */
name|int
function_decl|(
modifier|*
name|ib_get
function_decl|)
parameter_list|(
name|struct
name|drm_radeon_cs_parser
modifier|*
name|parser
parameter_list|)
function_decl|;
name|uint32_t
function_decl|(
modifier|*
name|ib_get_ptr
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|ib
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ib_free
function_decl|)
parameter_list|(
name|struct
name|drm_radeon_cs_parser
modifier|*
name|parser
parameter_list|,
name|int
name|error
parameter_list|)
function_decl|;
comment|/* do a relocation either MM or non-MM */
name|int
function_decl|(
modifier|*
name|relocate
function_decl|)
parameter_list|(
name|struct
name|drm_radeon_cs_parser
modifier|*
name|parser
parameter_list|,
name|uint32_t
modifier|*
name|reloc
parameter_list|,
name|uint64_t
modifier|*
name|offset
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RADEON_FLUSH_EMITED
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_PURGE_EMITED
value|(1<< 1)
end_define

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
name|int
name|vblank_crtc
decl_stmt|;
name|uint32_t
name|irq_enable_reg
decl_stmt|;
name|int
name|irq_enabled
decl_stmt|;
name|uint32_t
name|r500_disp_irq_reg
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
name|unsigned
name|int
name|pcigart_offset_set
decl_stmt|;
name|struct
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
name|unsigned
name|long
name|fb_aper_offset
decl_stmt|;
name|int
name|num_gb_pipes
decl_stmt|;
name|int
name|num_z_pipes
decl_stmt|;
name|int
name|track_flush
decl_stmt|;
name|drm_local_map_t
modifier|*
name|mmio
decl_stmt|;
comment|/* r6xx/r7xx pipe/shader config */
name|int
name|r600_max_pipes
decl_stmt|;
name|int
name|r600_max_tile_pipes
decl_stmt|;
name|int
name|r600_max_simds
decl_stmt|;
name|int
name|r600_max_backends
decl_stmt|;
name|int
name|r600_max_gprs
decl_stmt|;
name|int
name|r600_max_threads
decl_stmt|;
name|int
name|r600_max_stack_entries
decl_stmt|;
name|int
name|r600_max_hw_contexts
decl_stmt|;
name|int
name|r600_max_gs_threads
decl_stmt|;
name|int
name|r600_sx_max_export_size
decl_stmt|;
name|int
name|r600_sx_max_export_pos_size
decl_stmt|;
name|int
name|r600_sx_max_export_smx_size
decl_stmt|;
name|int
name|r600_sq_num_cf_insts
decl_stmt|;
name|int
name|r700_sx_num_of_sets
decl_stmt|;
name|int
name|r700_sc_prim_fifo_size
decl_stmt|;
name|int
name|r700_sc_hiz_tile_fifo_size
decl_stmt|;
name|int
name|r700_sc_earlyz_tile_fifo_fize
decl_stmt|;
comment|/* r6xx/r7xx drm blit vertex buffer */
name|struct
name|drm_buf
modifier|*
name|blit_vb
decl_stmt|;
comment|/* CS */
name|struct
name|drm_radeon_cs_priv
name|cs
decl_stmt|;
name|struct
name|drm_buf
modifier|*
name|cs_buf
decl_stmt|;
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
name|struct
name|drm_clip_rect
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
name|struct
name|drm_ioctl_desc
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

begin_function_decl
specifier|extern
name|u32
name|radeon_get_ring_head
parameter_list|(
name|drm_radeon_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|radeon_set_ring_head
parameter_list|(
name|drm_radeon_private_t
modifier|*
name|dev_priv
parameter_list|,
name|u32
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|GET_RING_HEAD
parameter_list|(
name|dev_priv
parameter_list|)
value|radeon_get_ring_head(dev_priv)
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
value|radeon_set_ring_head(dev_priv, val)
end_define

begin_comment
comment|/* Check whether the given hardware address is inside the framebuffer or the  * GART area.  */
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|radeon_check_offset
parameter_list|(
name|drm_radeon_private_t
modifier|*
name|dev_priv
parameter_list|,
name|u64
name|off
parameter_list|)
block|{
name|u64
name|fb_start
init|=
name|dev_priv
operator|->
name|fb_location
decl_stmt|;
name|u64
name|fb_end
init|=
name|fb_start
operator|+
name|dev_priv
operator|->
name|fb_size
operator|-
literal|1
decl_stmt|;
name|u64
name|gart_start
init|=
name|dev_priv
operator|->
name|gart_vm_start
decl_stmt|;
name|u64
name|gart_end
init|=
name|gart_start
operator|+
name|dev_priv
operator|->
name|gart_size
operator|-
literal|1
decl_stmt|;
return|return
operator|(
operator|(
name|off
operator|>=
name|fb_start
operator|&&
name|off
operator|<=
name|fb_end
operator|)
operator|||
operator|(
name|off
operator|>=
name|gart_start
operator|&&
name|off
operator|<=
name|gart_end
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* radeon_cp.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|radeon_cp_init
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_cp_start
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_cp_stop
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_cp_reset
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_cp_idle
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_cp_resume
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_engine_reset
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_fullscreen
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_cp_buffers
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u32
name|radeon_read_fb_location
parameter_list|(
name|drm_radeon_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|radeon_write_agp_location
parameter_list|(
name|drm_radeon_private_t
modifier|*
name|dev_priv
parameter_list|,
name|u32
name|agp_loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|radeon_write_agp_base
parameter_list|(
name|drm_radeon_private_t
modifier|*
name|dev_priv
parameter_list|,
name|u64
name|agp_base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u32
name|RADEON_READ_MM
parameter_list|(
name|drm_radeon_private_t
modifier|*
name|dev_priv
parameter_list|,
name|int
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|radeon_freelist_reset
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
name|struct
name|drm_buf
modifier|*
name|radeon_freelist_get
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
name|radeon_driver_preinit
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
name|radeon_presetup
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
name|radeon_driver_postcleanup
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
name|radeon_mem_alloc
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_mem_free
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_mem_init_heap
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
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
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|,
name|struct
name|mem_block
modifier|*
name|heap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|radeon_enable_bm
parameter_list|(
name|struct
name|drm_radeon_private
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u32
name|radeon_read_ring_rptr
parameter_list|(
name|drm_radeon_private_t
modifier|*
name|dev_priv
parameter_list|,
name|u32
name|off
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|radeon_write_ring_rptr
parameter_list|(
name|drm_radeon_private_t
modifier|*
name|dev_priv
parameter_list|,
name|u32
name|off
parameter_list|,
name|u32
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* radeon_irq.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|radeon_irq_set_state
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|u32
name|mask
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_irq_emit
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_irq_wait
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|radeon_do_release
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
name|u32
name|radeon_get_vblank_counter
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|crtc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|radeon_enable_vblank
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|crtc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|radeon_disable_vblank
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|crtc
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
name|radeon_driver_irq_postinstall
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
name|radeon_driver_irq_uninstall
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
name|radeon_enable_interrupt
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
name|radeon_vblank_crtc_get
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
name|radeon_vblank_crtc_set
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int64_t
name|value
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
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|radeon_driver_postclose
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|radeon_driver_lastclose
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
name|radeon_driver_open
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
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
name|r300_do_cp_cmdbuf
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|,
name|drm_radeon_kcmd_buffer_t
modifier|*
name|cmdbuf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r600_cp.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|r600_do_engine_reset
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
name|r600_do_cleanup_cp
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
name|r600_do_init_cp
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|drm_radeon_init_t
modifier|*
name|init
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|r600_do_resume_cp
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|r600_do_cp_idle
parameter_list|(
name|drm_radeon_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|r600_do_cp_start
parameter_list|(
name|drm_radeon_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|r600_do_cp_reset
parameter_list|(
name|drm_radeon_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|r600_do_cp_stop
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
name|r600_cp_dispatch_indirect
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_buf
modifier|*
name|buf
parameter_list|,
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|r600_page_table_init
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
name|r600_page_table_cleanup
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_ati_pcigart_info
modifier|*
name|gart_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|r600_cp_dispatch_swap
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
name|r600_cp_dispatch_texture
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|,
name|drm_radeon_texture_t
modifier|*
name|tex
parameter_list|,
name|drm_radeon_tex_image_t
modifier|*
name|image
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r600_blit.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|r600_prepare_blit_copy
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
name|r600_done_blit_copy
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
name|r600_blit_copy
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|uint64_t
name|src_gpu_addr
parameter_list|,
name|uint64_t
name|dst_gpu_addr
parameter_list|,
name|int
name|size_bytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|r600_blit_swap
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|uint64_t
name|src_gpu_addr
parameter_list|,
name|uint64_t
name|dst_gpu_addr
parameter_list|,
name|int
name|sx
parameter_list|,
name|int
name|sy
parameter_list|,
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|int
name|src_pitch
parameter_list|,
name|int
name|dst_pitch
parameter_list|,
name|int
name|cpp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* radeon_state.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|radeon_cp_discard_buffer
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_buf
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* radeon_cs.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|radeon_cs_ioctl
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|fpriv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|r600_cs_init
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
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
name|RADEON_MM_INDEX
value|0x0000
end_define

begin_define
define|#
directive|define
name|RADEON_MM_DATA
value|0x0004
end_define

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

begin_comment
comment|/*  * PCIE radeons (rv370/rv380, rv410, r423/r430/r480, r5xx)  * don't have an explicit bus mastering disable bit.  It's handled  * by the PCI D-states.  PMI_BM_DIS disables D-state bus master  * handling, not bus mastering itself.  */
end_comment

begin_define
define|#
directive|define
name|RADEON_BUS_CNTL
value|0x0030
end_define

begin_comment
comment|/* r1xx, r2xx, r300, r(v)350, r420/r481, rs400/rs480 */
end_comment

begin_define
define|#
directive|define
name|RADEON_BUS_MASTER_DIS
value|(1<< 6)
end_define

begin_comment
comment|/* rs600/rs690/rs740 */
end_comment

begin_define
define|#
directive|define
name|RS600_BUS_MASTER_DIS
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RS600_MSI_REARM
value|(1<< 20)
end_define

begin_comment
comment|/* see RS400_MSI_REARM in AIC_CNTL for rs480 */
end_comment

begin_define
define|#
directive|define
name|RADEON_BUS_CNTL1
value|0x0034
end_define

begin_define
define|#
directive|define
name|RADEON_PMI_BM_DIS
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_PMI_INT_DIS
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RV370_BUS_CNTL
value|0x004c
end_define

begin_define
define|#
directive|define
name|RV370_PMI_BM_DIS
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|RV370_PMI_INT_DIS
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|RADEON_MSI_REARM_EN
value|0x0160
end_define

begin_comment
comment|/* rv370/rv380, rv410, r423/r430/r480, r5xx */
end_comment

begin_define
define|#
directive|define
name|RV370_MSI_REARM_EN
value|(1<< 0)
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
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_UNMAPPED_ACCESS_CLAMP_LO
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_UNMAPPED_ACCESS_DISCARD
value|(3<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_MODE_32_128_CACHE
value|(0<< 3)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_MODE_8_4_128_CACHE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_CHK_RW_VALID_EN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_INVALIDATE_TLB
value|(1<< 8)
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
name|RS480_NB_MC_INDEX
value|0x168
end_define

begin_define
define|#
directive|define
name|RS480_NB_MC_IND_WR_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RS480_NB_MC_DATA
value|0x16c
end_define

begin_define
define|#
directive|define
name|RS690_MC_INDEX
value|0x78
end_define

begin_define
define|#
directive|define
name|RS690_MC_INDEX_MASK
value|0x1ff
end_define

begin_define
define|#
directive|define
name|RS690_MC_INDEX_WR_EN
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|RS690_MC_INDEX_WR_ACK
value|0x7f
end_define

begin_define
define|#
directive|define
name|RS690_MC_DATA
value|0x7c
end_define

begin_comment
comment|/* MC indirect registers */
end_comment

begin_define
define|#
directive|define
name|RS480_MC_MISC_CNTL
value|0x18
end_define

begin_define
define|#
directive|define
name|RS480_DISABLE_GTW
value|(1<< 1)
end_define

begin_comment
comment|/* switch between MCIND GART and MM GART registers. 0 = mmgart, 1 = mcind gart */
end_comment

begin_define
define|#
directive|define
name|RS480_GART_INDEX_REG_EN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RS690_BLOCK_GFX_D3_EN
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RS480_K8_FB_LOCATION
value|0x1e
end_define

begin_define
define|#
directive|define
name|RS480_GART_FEATURE_ID
value|0x2b
end_define

begin_define
define|#
directive|define
name|RS480_HANG_EN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|RS480_TLB_ENABLE
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RS480_P2P_ENABLE
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RS480_GTW_LAC_EN
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RS480_2LEVEL_GART
value|(0<< 30)
end_define

begin_define
define|#
directive|define
name|RS480_1LEVEL_GART
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RS480_PDC_EN
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RS480_GART_BASE
value|0x2c
end_define

begin_define
define|#
directive|define
name|RS480_GART_CACHE_CNTRL
value|0x2e
end_define

begin_define
define|#
directive|define
name|RS480_GART_CACHE_INVALIDATE
value|(1<< 0)
end_define

begin_comment
comment|/* wait for it to clear */
end_comment

begin_define
define|#
directive|define
name|RS480_AGP_ADDRESS_SPACE_SIZE
value|0x38
end_define

begin_define
define|#
directive|define
name|RS480_GART_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RS480_VA_SIZE_32MB
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|RS480_VA_SIZE_64MB
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RS480_VA_SIZE_128MB
value|(2<< 1)
end_define

begin_define
define|#
directive|define
name|RS480_VA_SIZE_256MB
value|(3<< 1)
end_define

begin_define
define|#
directive|define
name|RS480_VA_SIZE_512MB
value|(4<< 1)
end_define

begin_define
define|#
directive|define
name|RS480_VA_SIZE_1GB
value|(5<< 1)
end_define

begin_define
define|#
directive|define
name|RS480_VA_SIZE_2GB
value|(6<< 1)
end_define

begin_define
define|#
directive|define
name|RS480_AGP_MODE_CNTL
value|0x39
end_define

begin_define
define|#
directive|define
name|RS480_POST_GART_Q_SIZE
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RS480_NONGART_SNOOP
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RS480_AGP_RD_BUF_SIZE
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RS480_REQ_TYPE_SNOOP_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|RS480_REQ_TYPE_SNOOP_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|RS480_REQ_TYPE_SNOOP_DIS
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RS480_MC_MISC_UMA_CNTL
value|0x5f
end_define

begin_define
define|#
directive|define
name|RS480_MC_MCLK_CNTL
value|0x7a
end_define

begin_define
define|#
directive|define
name|RS480_MC_UMA_DUALCH_CNTL
value|0x86
end_define

begin_define
define|#
directive|define
name|RS690_MC_FB_LOCATION
value|0x100
end_define

begin_define
define|#
directive|define
name|RS690_MC_AGP_LOCATION
value|0x101
end_define

begin_define
define|#
directive|define
name|RS690_MC_AGP_BASE
value|0x102
end_define

begin_define
define|#
directive|define
name|RS690_MC_AGP_BASE_2
value|0x103
end_define

begin_define
define|#
directive|define
name|RS600_MC_INDEX
value|0x70
end_define

begin_define
define|#
directive|define
name|RS600_MC_ADDR_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|RS600_MC_IND_SEQ_RBS_0
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RS600_MC_IND_SEQ_RBS_1
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RS600_MC_IND_SEQ_RBS_2
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RS600_MC_IND_SEQ_RBS_3
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RS600_MC_IND_AIC_RBS
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RS600_MC_IND_CITF_ARB0
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RS600_MC_IND_CITF_ARB1
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|RS600_MC_IND_WR_EN
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RS600_MC_DATA
value|0x74
end_define

begin_define
define|#
directive|define
name|RS600_MC_STATUS
value|0x0
end_define

begin_define
define|#
directive|define
name|RS600_MC_IDLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RS600_MC_FB_LOCATION
value|0x4
end_define

begin_define
define|#
directive|define
name|RS600_MC_AGP_LOCATION
value|0x5
end_define

begin_define
define|#
directive|define
name|RS600_AGP_BASE
value|0x6
end_define

begin_define
define|#
directive|define
name|RS600_AGP_BASE_2
value|0x7
end_define

begin_define
define|#
directive|define
name|RS600_MC_CNTL1
value|0x9
end_define

begin_define
define|#
directive|define
name|RS600_ENABLE_PAGE_TABLES
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RS600_MC_PT0_CNTL
value|0x100
end_define

begin_define
define|#
directive|define
name|RS600_ENABLE_PT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RS600_EFFECTIVE_L2_CACHE_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 15)
end_define

begin_define
define|#
directive|define
name|RS600_EFFECTIVE_L2_QUEUE_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 21)
end_define

begin_define
define|#
directive|define
name|RS600_INVALIDATE_ALL_L1_TLBS
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|RS600_INVALIDATE_L2_CACHE
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|RS600_MC_PT0_CONTEXT0_CNTL
value|0x102
end_define

begin_define
define|#
directive|define
name|RS600_ENABLE_PAGE_TABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RS600_PAGE_TABLE_TYPE_FLAT
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|RS600_MC_PT0_SYSTEM_APERTURE_LOW_ADDR
value|0x112
end_define

begin_define
define|#
directive|define
name|RS600_MC_PT0_SYSTEM_APERTURE_HIGH_ADDR
value|0x114
end_define

begin_define
define|#
directive|define
name|RS600_MC_PT0_CONTEXT0_DEFAULT_READ_ADDR
value|0x11c
end_define

begin_define
define|#
directive|define
name|RS600_MC_PT0_CONTEXT0_FLAT_BASE_ADDR
value|0x12c
end_define

begin_define
define|#
directive|define
name|RS600_MC_PT0_CONTEXT0_FLAT_START_ADDR
value|0x13c
end_define

begin_define
define|#
directive|define
name|RS600_MC_PT0_CONTEXT0_FLAT_END_ADDR
value|0x14c
end_define

begin_define
define|#
directive|define
name|RS600_MC_PT0_CLIENT0_CNTL
value|0x16c
end_define

begin_define
define|#
directive|define
name|RS600_ENABLE_TRANSLATION_MODE_OVERRIDE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RS600_TRANSLATION_MODE_OVERRIDE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RS600_SYSTEM_ACCESS_MODE_MASK
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|RS600_SYSTEM_ACCESS_MODE_PA_ONLY
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|RS600_SYSTEM_ACCESS_MODE_USE_SYS_MAP
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RS600_SYSTEM_ACCESS_MODE_IN_SYS
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|RS600_SYSTEM_ACCESS_MODE_NOT_IN_SYS
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|RS600_SYSTEM_APERTURE_UNMAPPED_ACCESS_PASSTHROUGH
value|(0<< 10)
end_define

begin_define
define|#
directive|define
name|RS600_SYSTEM_APERTURE_UNMAPPED_ACCESS_DEFAULT_PAGE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RS600_EFFECTIVE_L1_CACHE_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 11)
end_define

begin_define
define|#
directive|define
name|RS600_ENABLE_FRAGMENT_PROCESSING
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RS600_EFFECTIVE_L1_QUEUE_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 15)
end_define

begin_define
define|#
directive|define
name|RS600_INVALIDATE_L1_TLB
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|R520_MC_IND_INDEX
value|0x70
end_define

begin_define
define|#
directive|define
name|R520_MC_IND_WR_EN
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|R520_MC_IND_DATA
value|0x74
end_define

begin_define
define|#
directive|define
name|RV515_MC_FB_LOCATION
value|0x01
end_define

begin_define
define|#
directive|define
name|RV515_MC_AGP_LOCATION
value|0x02
end_define

begin_define
define|#
directive|define
name|RV515_MC_AGP_BASE
value|0x03
end_define

begin_define
define|#
directive|define
name|RV515_MC_AGP_BASE_2
value|0x04
end_define

begin_define
define|#
directive|define
name|R520_MC_FB_LOCATION
value|0x04
end_define

begin_define
define|#
directive|define
name|R520_MC_AGP_LOCATION
value|0x05
end_define

begin_define
define|#
directive|define
name|R520_MC_AGP_BASE
value|0x06
end_define

begin_define
define|#
directive|define
name|R520_MC_AGP_BASE_2
value|0x07
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
name|RADEON_AGP_BASE_2
value|0x015c
end_define

begin_comment
comment|/* r200+ only */
end_comment

begin_define
define|#
directive|define
name|RS480_AGP_BASE_2
value|0x0164
end_define

begin_define
define|#
directive|define
name|RADEON_AGP_BASE
value|0x0170
end_define

begin_comment
comment|/* pipe config regs */
end_comment

begin_define
define|#
directive|define
name|R400_GB_PIPE_SELECT
value|0x402c
end_define

begin_define
define|#
directive|define
name|RV530_GB_PIPE_SELECT2
value|0x4124
end_define

begin_define
define|#
directive|define
name|R500_DYN_SCLK_PWMEM_PIPE
value|0x000d
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|R300_GB_TILE_CONFIG
value|0x4018
end_define

begin_define
define|#
directive|define
name|R300_ENABLE_TILING
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_PIPE_COUNT_RV350
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|R300_PIPE_COUNT_R300
value|(3<< 1)
end_define

begin_define
define|#
directive|define
name|R300_PIPE_COUNT_R420_3P
value|(6<< 1)
end_define

begin_define
define|#
directive|define
name|R300_PIPE_COUNT_R420
value|(7<< 1)
end_define

begin_define
define|#
directive|define
name|R300_TILE_SIZE_8
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|R300_TILE_SIZE_16
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|R300_TILE_SIZE_32
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|R300_SUBPIXEL_1_12
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|R300_SUBPIXEL_1_16
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|R300_DST_PIPE_CONFIG
value|0x170c
end_define

begin_define
define|#
directive|define
name|R300_PIPE_AUTO_CONFIG
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|R300_RB2D_DSTCACHE_MODE
value|0x3428
end_define

begin_define
define|#
directive|define
name|R300_DC_AUTOFLUSH_ENABLE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|R300_DC_DC_DISABLE_IGNORE_PE
value|(1<< 17)
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
name|RADEON_SRC_X_Y
value|0x1590
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
name|RADEON_SRC_PITCH_OFFSET
value|0x1428
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

begin_function_decl
specifier|extern
name|u32
name|radeon_get_scratch
parameter_list|(
name|drm_radeon_private_t
modifier|*
name|dev_priv
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|GET_SCRATCH
parameter_list|(
name|dev_priv
parameter_list|,
name|x
parameter_list|)
value|radeon_get_scratch(dev_priv, x)
end_define

begin_define
define|#
directive|define
name|R600_SCRATCH_REG0
value|0x8500
end_define

begin_define
define|#
directive|define
name|R600_SCRATCH_REG1
value|0x8504
end_define

begin_define
define|#
directive|define
name|R600_SCRATCH_REG2
value|0x8508
end_define

begin_define
define|#
directive|define
name|R600_SCRATCH_REG3
value|0x850c
end_define

begin_define
define|#
directive|define
name|R600_SCRATCH_REG4
value|0x8510
end_define

begin_define
define|#
directive|define
name|R600_SCRATCH_REG5
value|0x8514
end_define

begin_define
define|#
directive|define
name|R600_SCRATCH_REG6
value|0x8518
end_define

begin_define
define|#
directive|define
name|R600_SCRATCH_REG7
value|0x851c
end_define

begin_define
define|#
directive|define
name|R600_SCRATCH_UMSK
value|0x8540
end_define

begin_define
define|#
directive|define
name|R600_SCRATCH_ADDR
value|0x8544
end_define

begin_define
define|#
directive|define
name|R600_SCRATCHOFF
parameter_list|(
name|x
parameter_list|)
value|(R600_SCRATCH_REG_OFFSET + 4*(x))
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
name|RADEON_CRTC2_VBLANK_MASK
value|(1<< 9)
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
name|RADEON_CRTC2_VBLANK_STAT
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_VBLANK_STAT_ACK
value|(1<< 9)
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
name|R500_DISPLAY_INT_STATUS
value|(1<< 0)
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
name|R300_RB2D_DSTCACHE_CTLSTAT
value|0x342c
end_define

begin_comment
comment|/* use R300_DSTCACHE_CTLSTAT */
end_comment

begin_define
define|#
directive|define
name|R300_DSTCACHE_CTLSTAT
value|0x1714
end_define

begin_define
define|#
directive|define
name|R300_RB2D_DC_FLUSH
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|R300_RB2D_DC_FREE
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|R300_RB2D_DC_FLUSH_ALL
value|0xf
end_define

begin_define
define|#
directive|define
name|R300_RB2D_DC_BUSY
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
name|R300_ZB_ZCACHE_CTLSTAT
value|0x4f18
end_define

begin_define
define|#
directive|define
name|R300_ZC_FLUSH
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R300_ZC_FREE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|R300_ZC_BUSY
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
name|R300_RB3D_DSTCACHE_CTLSTAT
value|0x4e4c
end_define

begin_define
define|#
directive|define
name|R300_RB3D_DC_FLUSH
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|R300_RB3D_DC_FREE
value|(2<< 2)
end_define

begin_define
define|#
directive|define
name|R300_RB3D_DC_FINISH
value|(1<< 4)
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

begin_comment
comment|/*  *   6:0  Available slots in the FIFO  *   8    Host Interface active  *   9    CP request active  *   10   FIFO request active  *   11   Host Interface retry active  *   12   CP retry active  *   13   FIFO retry active  *   14   FIFO pipeline busy  *   15   Event engine busy  *   16   CP command stream busy  *   17   2D engine busy  *   18   2D portion of render backend busy  *   20   3D setup engine busy  *   26   GA engine busy  *   27   CBA 2D engine busy  *   31   2D engine busy or 3D engine busy or FIFO not empty or CP busy or  *           command stream queue not empty or Ring Buffer not empty  */
end_comment

begin_define
define|#
directive|define
name|RADEON_RBBM_STATUS
value|0x0e40
end_define

begin_comment
comment|/* Same as the previous RADEON_RBBM_STATUS; this is a mirror of that register.  */
end_comment

begin_comment
comment|/* #define RADEON_RBBM_STATUS		0x1740 */
end_comment

begin_comment
comment|/* bits 6:0 are dword slots available in the cmd fifo */
end_comment

begin_define
define|#
directive|define
name|RADEON_RBBM_FIFOCNT_MASK
value|0x007f
end_define

begin_define
define|#
directive|define
name|RADEON_HIRQ_ON_RBB
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_CPRQ_ON_RBB
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|RADEON_CFRQ_ON_RBB
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_HIRQ_IN_RTBUF
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|RADEON_CPRQ_IN_RTBUF
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_CFRQ_IN_RTBUF
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|RADEON_PIPE_BUSY
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_ENG_EV_BUSY
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_CP_CMDSTRM_BUSY
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_E2_BUSY
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_RB2D_BUSY
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_BUSY
value|(1<< 19)
end_define

begin_comment
comment|/* not used on r300 */
end_comment

begin_define
define|#
directive|define
name|RADEON_VAP_BUSY
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_RE_BUSY
value|(1<< 21)
end_define

begin_comment
comment|/* not used on r300 */
end_comment

begin_define
define|#
directive|define
name|RADEON_TAM_BUSY
value|(1<< 22)
end_define

begin_comment
comment|/* not used on r300 */
end_comment

begin_define
define|#
directive|define
name|RADEON_TDM_BUSY
value|(1<< 23)
end_define

begin_comment
comment|/* not used on r300 */
end_comment

begin_define
define|#
directive|define
name|RADEON_PB_BUSY
value|(1<< 24)
end_define

begin_comment
comment|/* not used on r300 */
end_comment

begin_define
define|#
directive|define
name|RADEON_TIM_BUSY
value|(1<< 25)
end_define

begin_comment
comment|/* not used on r300 */
end_comment

begin_define
define|#
directive|define
name|RADEON_GA_BUSY
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_CBA2D_BUSY
value|(1<< 27)
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
name|RADEON_RB_RPTR_WR_ENA
value|(1<< 31)
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
name|RS400_MSI_REARM
value|(1<< 3)
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
name|R600_IT_INDIRECT_BUFFER
value|0x00003200
end_define

begin_define
define|#
directive|define
name|R600_IT_ME_INITIALIZE
value|0x00004400
end_define

begin_define
define|#
directive|define
name|R600_ME_INITIALIZE_DEVICE_ID
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|R600_IT_EVENT_WRITE
value|0x00004600
end_define

begin_define
define|#
directive|define
name|R600_IT_SET_CONFIG_REG
value|0x00006800
end_define

begin_define
define|#
directive|define
name|R600_SET_CONFIG_REG_OFFSET
value|0x00008000
end_define

begin_define
define|#
directive|define
name|R600_SET_CONFIG_REG_END
value|0x0000ac00
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

begin_define
define|#
directive|define
name|RADEON_CRTC_CRNT_FRAME
value|0x0214
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_CRNT_FRAME
value|0x0314
end_define

begin_define
define|#
directive|define
name|R500_D1CRTC_STATUS
value|0x609c
end_define

begin_define
define|#
directive|define
name|R500_D2CRTC_STATUS
value|0x689c
end_define

begin_define
define|#
directive|define
name|R500_CRTC_V_BLANK
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|R500_D1CRTC_FRAME_COUNT
value|0x60a4
end_define

begin_define
define|#
directive|define
name|R500_D2CRTC_FRAME_COUNT
value|0x68a4
end_define

begin_define
define|#
directive|define
name|R500_D1MODE_V_COUNTER
value|0x6530
end_define

begin_define
define|#
directive|define
name|R500_D2MODE_V_COUNTER
value|0x6d30
end_define

begin_define
define|#
directive|define
name|R500_D1MODE_VBLANK_STATUS
value|0x6534
end_define

begin_define
define|#
directive|define
name|R500_D2MODE_VBLANK_STATUS
value|0x6d34
end_define

begin_define
define|#
directive|define
name|R500_VBLANK_OCCURED
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|R500_VBLANK_ACK
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|R500_VBLANK_STAT
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|R500_VBLANK_INT
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|R500_DxMODE_INT_MASK
value|0x6540
end_define

begin_define
define|#
directive|define
name|R500_D1MODE_INT_MASK
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|R500_D2MODE_INT_MASK
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|R500_DISP_INTERRUPT_STATUS
value|0x7edc
end_define

begin_define
define|#
directive|define
name|R500_D1_VBLANK_INTERRUPT
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|R500_D2_VBLANK_INTERRUPT
value|(1<< 5)
end_define

begin_comment
comment|/* R6xx/R7xx registers */
end_comment

begin_define
define|#
directive|define
name|R600_MC_VM_FB_LOCATION
value|0x2180
end_define

begin_define
define|#
directive|define
name|R600_MC_VM_AGP_TOP
value|0x2184
end_define

begin_define
define|#
directive|define
name|R600_MC_VM_AGP_BOT
value|0x2188
end_define

begin_define
define|#
directive|define
name|R600_MC_VM_AGP_BASE
value|0x218c
end_define

begin_define
define|#
directive|define
name|R600_MC_VM_SYSTEM_APERTURE_LOW_ADDR
value|0x2190
end_define

begin_define
define|#
directive|define
name|R600_MC_VM_SYSTEM_APERTURE_HIGH_ADDR
value|0x2194
end_define

begin_define
define|#
directive|define
name|R600_MC_VM_SYSTEM_APERTURE_DEFAULT_ADDR
value|0x2198
end_define

begin_define
define|#
directive|define
name|R700_MC_VM_FB_LOCATION
value|0x2024
end_define

begin_define
define|#
directive|define
name|R700_MC_VM_AGP_TOP
value|0x2028
end_define

begin_define
define|#
directive|define
name|R700_MC_VM_AGP_BOT
value|0x202c
end_define

begin_define
define|#
directive|define
name|R700_MC_VM_AGP_BASE
value|0x2030
end_define

begin_define
define|#
directive|define
name|R700_MC_VM_SYSTEM_APERTURE_LOW_ADDR
value|0x2034
end_define

begin_define
define|#
directive|define
name|R700_MC_VM_SYSTEM_APERTURE_HIGH_ADDR
value|0x2038
end_define

begin_define
define|#
directive|define
name|R700_MC_VM_SYSTEM_APERTURE_DEFAULT_ADDR
value|0x203c
end_define

begin_define
define|#
directive|define
name|R600_MCD_RD_A_CNTL
value|0x219c
end_define

begin_define
define|#
directive|define
name|R600_MCD_RD_B_CNTL
value|0x21a0
end_define

begin_define
define|#
directive|define
name|R600_MCD_WR_A_CNTL
value|0x21a4
end_define

begin_define
define|#
directive|define
name|R600_MCD_WR_B_CNTL
value|0x21a8
end_define

begin_define
define|#
directive|define
name|R600_MCD_RD_SYS_CNTL
value|0x2200
end_define

begin_define
define|#
directive|define
name|R600_MCD_WR_SYS_CNTL
value|0x2214
end_define

begin_define
define|#
directive|define
name|R600_MCD_RD_GFX_CNTL
value|0x21fc
end_define

begin_define
define|#
directive|define
name|R600_MCD_RD_HDP_CNTL
value|0x2204
end_define

begin_define
define|#
directive|define
name|R600_MCD_RD_PDMA_CNTL
value|0x2208
end_define

begin_define
define|#
directive|define
name|R600_MCD_RD_SEM_CNTL
value|0x220c
end_define

begin_define
define|#
directive|define
name|R600_MCD_WR_GFX_CNTL
value|0x2210
end_define

begin_define
define|#
directive|define
name|R600_MCD_WR_HDP_CNTL
value|0x2218
end_define

begin_define
define|#
directive|define
name|R600_MCD_WR_PDMA_CNTL
value|0x221c
end_define

begin_define
define|#
directive|define
name|R600_MCD_WR_SEM_CNTL
value|0x2220
end_define

begin_define
define|#
directive|define
name|R600_MCD_L1_TLB
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R600_MCD_L1_FRAG_PROC
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|R600_MCD_L1_STRICT_ORDERING
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|R600_MCD_SYSTEM_ACCESS_MODE_MASK
value|(3<< 6)
end_define

begin_define
define|#
directive|define
name|R600_MCD_SYSTEM_ACCESS_MODE_PA_ONLY
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|R600_MCD_SYSTEM_ACCESS_MODE_USE_SYS_MAP
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|R600_MCD_SYSTEM_ACCESS_MODE_IN_SYS
value|(2<< 6)
end_define

begin_define
define|#
directive|define
name|R600_MCD_SYSTEM_ACCESS_MODE_NOT_IN_SYS
value|(3<< 6)
end_define

begin_define
define|#
directive|define
name|R600_MCD_SYSTEM_APERTURE_UNMAPPED_ACCESS_PASS_THRU
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|R600_MCD_SYSTEM_APERTURE_UNMAPPED_ACCESS_DEFAULT_PAGE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|R600_MCD_SEMAPHORE_MODE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|R600_MCD_WAIT_L2_QUERY
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|R600_MCD_EFFECTIVE_L1_TLB_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
end_define

begin_define
define|#
directive|define
name|R600_MCD_EFFECTIVE_L1_QUEUE_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 15)
end_define

begin_define
define|#
directive|define
name|R700_MC_VM_MD_L1_TLB0_CNTL
value|0x2654
end_define

begin_define
define|#
directive|define
name|R700_MC_VM_MD_L1_TLB1_CNTL
value|0x2658
end_define

begin_define
define|#
directive|define
name|R700_MC_VM_MD_L1_TLB2_CNTL
value|0x265c
end_define

begin_define
define|#
directive|define
name|R700_MC_VM_MB_L1_TLB0_CNTL
value|0x2234
end_define

begin_define
define|#
directive|define
name|R700_MC_VM_MB_L1_TLB1_CNTL
value|0x2238
end_define

begin_define
define|#
directive|define
name|R700_MC_VM_MB_L1_TLB2_CNTL
value|0x223c
end_define

begin_define
define|#
directive|define
name|R700_MC_VM_MB_L1_TLB3_CNTL
value|0x2240
end_define

begin_define
define|#
directive|define
name|R700_ENABLE_L1_TLB
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R700_ENABLE_L1_FRAGMENT_PROCESSING
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|R700_SYSTEM_ACCESS_MODE_IN_SYS
value|(2<< 3)
end_define

begin_define
define|#
directive|define
name|R700_SYSTEM_APERTURE_UNMAPPED_ACCESS_PASS_THRU
value|(0<< 5)
end_define

begin_define
define|#
directive|define
name|R700_EFFECTIVE_L1_TLB_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 15)
end_define

begin_define
define|#
directive|define
name|R700_EFFECTIVE_L1_QUEUE_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 18)
end_define

begin_define
define|#
directive|define
name|R700_MC_ARB_RAMCFG
value|0x2760
end_define

begin_define
define|#
directive|define
name|R700_NOOFBANK_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R700_NOOFBANK_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|R700_NOOFRANK_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|R700_NOOFRANK_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|R700_NOOFROWS_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|R700_NOOFROWS_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|R700_NOOFCOLS_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|R700_NOOFCOLS_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|R700_CHANSIZE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|R700_CHANSIZE_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|R700_BURSTLENGTH_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|R700_BURSTLENGTH_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|R600_RAMCFG
value|0x2408
end_define

begin_define
define|#
directive|define
name|R600_NOOFBANK_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R600_NOOFBANK_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|R600_NOOFRANK_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|R600_NOOFRANK_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|R600_NOOFROWS_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|R600_NOOFROWS_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|R600_NOOFCOLS_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|R600_NOOFCOLS_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|R600_CHANSIZE_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|R600_CHANSIZE_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|R600_BURSTLENGTH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|R600_BURSTLENGTH_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|R600_VM_L2_CNTL
value|0x1400
end_define

begin_define
define|#
directive|define
name|R600_VM_L2_CACHE_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R600_VM_L2_FRAG_PROC
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|R600_VM_ENABLE_PTE_CACHE_LRU_W
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|R600_VM_L2_CNTL_QUEUE_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 13)
end_define

begin_define
define|#
directive|define
name|R700_VM_L2_CNTL_QUEUE_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 14)
end_define

begin_define
define|#
directive|define
name|R600_VM_L2_CNTL2
value|0x1404
end_define

begin_define
define|#
directive|define
name|R600_VM_L2_CNTL2_INVALIDATE_ALL_L1_TLBS
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R600_VM_L2_CNTL2_INVALIDATE_L2_CACHE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|R600_VM_L2_CNTL3
value|0x1408
end_define

begin_define
define|#
directive|define
name|R600_VM_L2_CNTL3_BANK_SELECT_0
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R600_VM_L2_CNTL3_BANK_SELECT_1
parameter_list|(
name|x
parameter_list|)
value|((x)<< 5)
end_define

begin_define
define|#
directive|define
name|R600_VM_L2_CNTL3_CACHE_UPDATE_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 10)
end_define

begin_define
define|#
directive|define
name|R700_VM_L2_CNTL3_BANK_SELECT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R700_VM_L2_CNTL3_CACHE_UPDATE_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 6)
end_define

begin_define
define|#
directive|define
name|R600_VM_L2_STATUS
value|0x140c
end_define

begin_define
define|#
directive|define
name|R600_VM_CONTEXT0_CNTL
value|0x1410
end_define

begin_define
define|#
directive|define
name|R600_VM_ENABLE_CONTEXT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R600_VM_PAGE_TABLE_DEPTH_FLAT
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|R600_VM_CONTEXT0_CNTL2
value|0x1430
end_define

begin_define
define|#
directive|define
name|R600_VM_CONTEXT0_REQUEST_RESPONSE
value|0x1470
end_define

begin_define
define|#
directive|define
name|R600_VM_CONTEXT0_INVALIDATION_LOW_ADDR
value|0x1490
end_define

begin_define
define|#
directive|define
name|R600_VM_CONTEXT0_INVALIDATION_HIGH_ADDR
value|0x14b0
end_define

begin_define
define|#
directive|define
name|R600_VM_CONTEXT0_PAGE_TABLE_BASE_ADDR
value|0x1574
end_define

begin_define
define|#
directive|define
name|R600_VM_CONTEXT0_PAGE_TABLE_START_ADDR
value|0x1594
end_define

begin_define
define|#
directive|define
name|R600_VM_CONTEXT0_PAGE_TABLE_END_ADDR
value|0x15b4
end_define

begin_define
define|#
directive|define
name|R700_VM_CONTEXT0_PAGE_TABLE_BASE_ADDR
value|0x153c
end_define

begin_define
define|#
directive|define
name|R700_VM_CONTEXT0_PAGE_TABLE_START_ADDR
value|0x155c
end_define

begin_define
define|#
directive|define
name|R700_VM_CONTEXT0_PAGE_TABLE_END_ADDR
value|0x157c
end_define

begin_define
define|#
directive|define
name|R600_HDP_HOST_PATH_CNTL
value|0x2c00
end_define

begin_define
define|#
directive|define
name|R600_GRBM_CNTL
value|0x8000
end_define

begin_define
define|#
directive|define
name|R600_GRBM_READ_TIMEOUT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R600_GRBM_STATUS
value|0x8010
end_define

begin_define
define|#
directive|define
name|R600_CMDFIFO_AVAIL_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|R700_CMDFIFO_AVAIL_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|R600_GUI_ACTIVE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|R600_GRBM_STATUS2
value|0x8014
end_define

begin_define
define|#
directive|define
name|R600_GRBM_SOFT_RESET
value|0x8020
end_define

begin_define
define|#
directive|define
name|R600_SOFT_RESET_CP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R600_WAIT_UNTIL
value|0x8040
end_define

begin_define
define|#
directive|define
name|R600_CP_SEM_WAIT_TIMER
value|0x85bc
end_define

begin_define
define|#
directive|define
name|R600_CP_ME_CNTL
value|0x86d8
end_define

begin_define
define|#
directive|define
name|R600_CP_ME_HALT
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|R600_CP_QUEUE_THRESHOLDS
value|0x8760
end_define

begin_define
define|#
directive|define
name|R600_ROQ_IB1_START
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R600_ROQ_IB2_START
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|R600_CP_MEQ_THRESHOLDS
value|0x8764
end_define

begin_define
define|#
directive|define
name|R700_STQ_SPLIT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R600_MEQ_END
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|R600_ROQ_END
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|R600_CP_PERFMON_CNTL
value|0x87fc
end_define

begin_define
define|#
directive|define
name|R600_CP_RB_BASE
value|0xc100
end_define

begin_define
define|#
directive|define
name|R600_CP_RB_CNTL
value|0xc104
end_define

begin_define
define|#
directive|define
name|R600_RB_BUFSZ
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R600_RB_BLKSZ
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|R600_RB_NO_UPDATE
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|R600_RB_RPTR_WR_ENA
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|R600_CP_RB_RPTR_WR
value|0xc108
end_define

begin_define
define|#
directive|define
name|R600_CP_RB_RPTR_ADDR
value|0xc10c
end_define

begin_define
define|#
directive|define
name|R600_CP_RB_RPTR_ADDR_HI
value|0xc110
end_define

begin_define
define|#
directive|define
name|R600_CP_RB_WPTR
value|0xc114
end_define

begin_define
define|#
directive|define
name|R600_CP_RB_WPTR_ADDR
value|0xc118
end_define

begin_define
define|#
directive|define
name|R600_CP_RB_WPTR_ADDR_HI
value|0xc11c
end_define

begin_define
define|#
directive|define
name|R600_CP_RB_RPTR
value|0x8700
end_define

begin_define
define|#
directive|define
name|R600_CP_RB_WPTR_DELAY
value|0x8704
end_define

begin_define
define|#
directive|define
name|R600_CP_PFP_UCODE_ADDR
value|0xc150
end_define

begin_define
define|#
directive|define
name|R600_CP_PFP_UCODE_DATA
value|0xc154
end_define

begin_define
define|#
directive|define
name|R600_CP_ME_RAM_RADDR
value|0xc158
end_define

begin_define
define|#
directive|define
name|R600_CP_ME_RAM_WADDR
value|0xc15c
end_define

begin_define
define|#
directive|define
name|R600_CP_ME_RAM_DATA
value|0xc160
end_define

begin_define
define|#
directive|define
name|R600_CP_DEBUG
value|0xc1fc
end_define

begin_define
define|#
directive|define
name|R600_PA_CL_ENHANCE
value|0x8a14
end_define

begin_define
define|#
directive|define
name|R600_CLIP_VTX_REORDER_ENA
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R600_NUM_CLIP_SEQ
parameter_list|(
name|x
parameter_list|)
value|((x)<< 1)
end_define

begin_define
define|#
directive|define
name|R600_PA_SC_LINE_STIPPLE_STATE
value|0x8b10
end_define

begin_define
define|#
directive|define
name|R600_PA_SC_MULTI_CHIP_CNTL
value|0x8b20
end_define

begin_define
define|#
directive|define
name|R700_PA_SC_FORCE_EOV_MAX_CNTS
value|0x8b24
end_define

begin_define
define|#
directive|define
name|R700_FORCE_EOV_MAX_CLK_CNT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R700_FORCE_EOV_MAX_REZ_CNT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|R600_PA_SC_AA_SAMPLE_LOCS_2S
value|0x8b40
end_define

begin_define
define|#
directive|define
name|R600_PA_SC_AA_SAMPLE_LOCS_4S
value|0x8b44
end_define

begin_define
define|#
directive|define
name|R600_PA_SC_AA_SAMPLE_LOCS_8S_WD0
value|0x8b48
end_define

begin_define
define|#
directive|define
name|R600_PA_SC_AA_SAMPLE_LOCS_8S_WD1
value|0x8b4c
end_define

begin_define
define|#
directive|define
name|R600_S0_X
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R600_S0_Y
parameter_list|(
name|x
parameter_list|)
value|((x)<< 4)
end_define

begin_define
define|#
directive|define
name|R600_S1_X
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|R600_S1_Y
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
end_define

begin_define
define|#
directive|define
name|R600_S2_X
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|R600_S2_Y
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
end_define

begin_define
define|#
directive|define
name|R600_S3_X
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|R600_S3_Y
parameter_list|(
name|x
parameter_list|)
value|((x)<< 28)
end_define

begin_define
define|#
directive|define
name|R600_S4_X
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R600_S4_Y
parameter_list|(
name|x
parameter_list|)
value|((x)<< 4)
end_define

begin_define
define|#
directive|define
name|R600_S5_X
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|R600_S5_Y
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
end_define

begin_define
define|#
directive|define
name|R600_S6_X
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|R600_S6_Y
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
end_define

begin_define
define|#
directive|define
name|R600_S7_X
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|R600_S7_Y
parameter_list|(
name|x
parameter_list|)
value|((x)<< 28)
end_define

begin_define
define|#
directive|define
name|R600_PA_SC_FIFO_SIZE
value|0x8bd0
end_define

begin_define
define|#
directive|define
name|R600_SC_PRIM_FIFO_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R600_SC_HIZ_TILE_FIFO_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|R600_SC_EARLYZ_TILE_FIFO_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|R700_PA_SC_FIFO_SIZE_R7XX
value|0x8bcc
end_define

begin_define
define|#
directive|define
name|R700_SC_PRIM_FIFO_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R700_SC_HIZ_TILE_FIFO_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
end_define

begin_define
define|#
directive|define
name|R700_SC_EARLYZ_TILE_FIFO_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
end_define

begin_define
define|#
directive|define
name|R600_PA_SC_ENHANCE
value|0x8bf0
end_define

begin_define
define|#
directive|define
name|R600_FORCE_EOV_MAX_CLK_CNT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R600_FORCE_EOV_MAX_TILE_CNT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
end_define

begin_define
define|#
directive|define
name|R600_PA_SC_CLIPRECT_RULE
value|0x2820c
end_define

begin_define
define|#
directive|define
name|R700_PA_SC_EDGERULE
value|0x28230
end_define

begin_define
define|#
directive|define
name|R600_PA_SC_LINE_STIPPLE
value|0x28a0c
end_define

begin_define
define|#
directive|define
name|R600_PA_SC_MODE_CNTL
value|0x28a4c
end_define

begin_define
define|#
directive|define
name|R600_PA_SC_AA_CONFIG
value|0x28c04
end_define

begin_define
define|#
directive|define
name|R600_SX_EXPORT_BUFFER_SIZES
value|0x900c
end_define

begin_define
define|#
directive|define
name|R600_COLOR_BUFFER_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R600_POSITION_BUFFER_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|R600_SMX_BUFFER_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|R600_SX_DEBUG_1
value|0x9054
end_define

begin_define
define|#
directive|define
name|R600_SMX_EVENT_RELEASE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R600_ENABLE_NEW_SMX_ADDRESS
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|R700_SX_DEBUG_1
value|0x9058
end_define

begin_define
define|#
directive|define
name|R700_ENABLE_NEW_SMX_ADDRESS
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|R600_SX_MISC
value|0x28350
end_define

begin_define
define|#
directive|define
name|R600_DB_DEBUG
value|0x9830
end_define

begin_define
define|#
directive|define
name|R600_PREZ_MUST_WAIT_FOR_POSTZ_DONE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|R600_DB_WATERMARKS
value|0x9838
end_define

begin_define
define|#
directive|define
name|R600_DEPTH_FREE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R600_DEPTH_FLUSH
parameter_list|(
name|x
parameter_list|)
value|((x)<< 5)
end_define

begin_define
define|#
directive|define
name|R600_DEPTH_PENDING_FREE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 15)
end_define

begin_define
define|#
directive|define
name|R600_DEPTH_CACHELINE_FREE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
end_define

begin_define
define|#
directive|define
name|R700_DB_DEBUG3
value|0x98b0
end_define

begin_define
define|#
directive|define
name|R700_DB_CLK_OFF_DELAY
parameter_list|(
name|x
parameter_list|)
value|((x)<< 11)
end_define

begin_define
define|#
directive|define
name|RV700_DB_DEBUG4
value|0x9b8c
end_define

begin_define
define|#
directive|define
name|RV700_DISABLE_TILE_COVERED_FOR_PS_ITER
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|R600_VGT_CACHE_INVALIDATION
value|0x88c4
end_define

begin_define
define|#
directive|define
name|R600_CACHE_INVALIDATION
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R600_VC_ONLY
value|0
end_define

begin_define
define|#
directive|define
name|R600_TC_ONLY
value|1
end_define

begin_define
define|#
directive|define
name|R600_VC_AND_TC
value|2
end_define

begin_define
define|#
directive|define
name|R700_AUTO_INVLD_EN
parameter_list|(
name|x
parameter_list|)
value|((x)<< 6)
end_define

begin_define
define|#
directive|define
name|R700_NO_AUTO
value|0
end_define

begin_define
define|#
directive|define
name|R700_ES_AUTO
value|1
end_define

begin_define
define|#
directive|define
name|R700_GS_AUTO
value|2
end_define

begin_define
define|#
directive|define
name|R700_ES_AND_GS_AUTO
value|3
end_define

begin_define
define|#
directive|define
name|R600_VGT_GS_PER_ES
value|0x88c8
end_define

begin_define
define|#
directive|define
name|R600_VGT_ES_PER_GS
value|0x88cc
end_define

begin_define
define|#
directive|define
name|R600_VGT_GS_PER_VS
value|0x88e8
end_define

begin_define
define|#
directive|define
name|R600_VGT_GS_VERTEX_REUSE
value|0x88d4
end_define

begin_define
define|#
directive|define
name|R600_VGT_NUM_INSTANCES
value|0x8974
end_define

begin_define
define|#
directive|define
name|R600_VGT_STRMOUT_EN
value|0x28ab0
end_define

begin_define
define|#
directive|define
name|R600_VGT_EVENT_INITIATOR
value|0x28a90
end_define

begin_define
define|#
directive|define
name|R600_CACHE_FLUSH_AND_INV_EVENT
value|(0x16<< 0)
end_define

begin_define
define|#
directive|define
name|R600_VGT_VERTEX_REUSE_BLOCK_CNTL
value|0x28c58
end_define

begin_define
define|#
directive|define
name|R600_VTX_REUSE_DEPTH_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|R600_VGT_OUT_DEALLOC_CNTL
value|0x28c5c
end_define

begin_define
define|#
directive|define
name|R600_DEALLOC_DIST_MASK
value|0x7f
end_define

begin_define
define|#
directive|define
name|R600_CB_COLOR0_BASE
value|0x28040
end_define

begin_define
define|#
directive|define
name|R600_CB_COLOR1_BASE
value|0x28044
end_define

begin_define
define|#
directive|define
name|R600_CB_COLOR2_BASE
value|0x28048
end_define

begin_define
define|#
directive|define
name|R600_CB_COLOR3_BASE
value|0x2804c
end_define

begin_define
define|#
directive|define
name|R600_CB_COLOR4_BASE
value|0x28050
end_define

begin_define
define|#
directive|define
name|R600_CB_COLOR5_BASE
value|0x28054
end_define

begin_define
define|#
directive|define
name|R600_CB_COLOR6_BASE
value|0x28058
end_define

begin_define
define|#
directive|define
name|R600_CB_COLOR7_BASE
value|0x2805c
end_define

begin_define
define|#
directive|define
name|R600_CB_COLOR7_FRAG
value|0x280fc
end_define

begin_define
define|#
directive|define
name|R600_TC_CNTL
value|0x9608
end_define

begin_define
define|#
directive|define
name|R600_TC_L2_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 5)
end_define

begin_define
define|#
directive|define
name|R600_L2_DISABLE_LATE_HIT
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|R600_ARB_POP
value|0x2418
end_define

begin_define
define|#
directive|define
name|R600_ENABLE_TC128
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|R600_ARB_GDEC_RD_CNTL
value|0x246c
end_define

begin_define
define|#
directive|define
name|R600_TA_CNTL_AUX
value|0x9508
end_define

begin_define
define|#
directive|define
name|R600_DISABLE_CUBE_WRAP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R600_DISABLE_CUBE_ANISO
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|R700_GETLOD_SELECT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 2)
end_define

begin_define
define|#
directive|define
name|R600_SYNC_GRADIENT
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|R600_SYNC_WALKER
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|R600_SYNC_ALIGNER
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|R600_BILINEAR_PRECISION_6_BIT
value|(0<< 31)
end_define

begin_define
define|#
directive|define
name|R600_BILINEAR_PRECISION_8_BIT
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|R700_TCP_CNTL
value|0x9610
end_define

begin_define
define|#
directive|define
name|R600_SMX_DC_CTL0
value|0xa020
end_define

begin_define
define|#
directive|define
name|R700_USE_HASH_FUNCTION
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R700_CACHE_DEPTH
parameter_list|(
name|x
parameter_list|)
value|((x)<< 1)
end_define

begin_define
define|#
directive|define
name|R700_FLUSH_ALL_ON_EVENT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|R700_STALL_ON_EVENT
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|R700_SMX_EVENT_CTL
value|0xa02c
end_define

begin_define
define|#
directive|define
name|R700_ES_FLUSH_CTL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R700_GS_FLUSH_CTL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 3)
end_define

begin_define
define|#
directive|define
name|R700_ACK_FLUSH_CTL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 6)
end_define

begin_define
define|#
directive|define
name|R700_SYNC_FLUSH_CTL
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|R600_SQ_CONFIG
value|0x8c00
end_define

begin_define
define|#
directive|define
name|R600_VC_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R600_EXPORT_SRC_C
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|R600_DX9_CONSTS
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|R600_ALU_INST_PREFER_VECTOR
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|R600_DX10_CLAMP
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|R600_CLAUSE_SEQ_PRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|R600_PS_PRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|R600_VS_PRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< 26)
end_define

begin_define
define|#
directive|define
name|R600_GS_PRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< 28)
end_define

begin_define
define|#
directive|define
name|R600_ES_PRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< 30)
end_define

begin_define
define|#
directive|define
name|R600_SQ_GPR_RESOURCE_MGMT_1
value|0x8c04
end_define

begin_define
define|#
directive|define
name|R600_NUM_PS_GPRS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R600_NUM_VS_GPRS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|R700_DYN_GPR_ENABLE
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|R600_NUM_CLAUSE_TEMP_GPRS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 28)
end_define

begin_define
define|#
directive|define
name|R600_SQ_GPR_RESOURCE_MGMT_2
value|0x8c08
end_define

begin_define
define|#
directive|define
name|R600_NUM_GS_GPRS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R600_NUM_ES_GPRS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|R600_SQ_THREAD_RESOURCE_MGMT
value|0x8c0c
end_define

begin_define
define|#
directive|define
name|R600_NUM_PS_THREADS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R600_NUM_VS_THREADS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|R600_NUM_GS_THREADS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|R600_NUM_ES_THREADS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|R600_SQ_STACK_RESOURCE_MGMT_1
value|0x8c10
end_define

begin_define
define|#
directive|define
name|R600_NUM_PS_STACK_ENTRIES
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R600_NUM_VS_STACK_ENTRIES
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|R600_SQ_STACK_RESOURCE_MGMT_2
value|0x8c14
end_define

begin_define
define|#
directive|define
name|R600_NUM_GS_STACK_ENTRIES
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R600_NUM_ES_STACK_ENTRIES
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|R600_SQ_MS_FIFO_SIZES
value|0x8cf0
end_define

begin_define
define|#
directive|define
name|R600_CACHE_FIFO_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R600_FETCH_FIFO_HIWATER
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|R600_DONE_FIFO_HIWATER
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|R600_ALU_UPDATE_FIFO_HIWATER
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|R700_SQ_DYN_GPR_SIZE_SIMD_AB_0
value|0x8db0
end_define

begin_define
define|#
directive|define
name|R700_SIMDA_RING0
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R700_SIMDA_RING1
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|R700_SIMDB_RING0
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|R700_SIMDB_RING1
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|R700_SQ_DYN_GPR_SIZE_SIMD_AB_1
value|0x8db4
end_define

begin_define
define|#
directive|define
name|R700_SQ_DYN_GPR_SIZE_SIMD_AB_2
value|0x8db8
end_define

begin_define
define|#
directive|define
name|R700_SQ_DYN_GPR_SIZE_SIMD_AB_3
value|0x8dbc
end_define

begin_define
define|#
directive|define
name|R700_SQ_DYN_GPR_SIZE_SIMD_AB_4
value|0x8dc0
end_define

begin_define
define|#
directive|define
name|R700_SQ_DYN_GPR_SIZE_SIMD_AB_5
value|0x8dc4
end_define

begin_define
define|#
directive|define
name|R700_SQ_DYN_GPR_SIZE_SIMD_AB_6
value|0x8dc8
end_define

begin_define
define|#
directive|define
name|R700_SQ_DYN_GPR_SIZE_SIMD_AB_7
value|0x8dcc
end_define

begin_define
define|#
directive|define
name|R600_SPI_PS_IN_CONTROL_0
value|0x286cc
end_define

begin_define
define|#
directive|define
name|R600_NUM_INTERP
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R600_POSITION_ENA
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|R600_POSITION_CENTROID
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|R600_POSITION_ADDR
parameter_list|(
name|x
parameter_list|)
value|((x)<< 10)
end_define

begin_define
define|#
directive|define
name|R600_PARAM_GEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< 15)
end_define

begin_define
define|#
directive|define
name|R600_PARAM_GEN_ADDR
parameter_list|(
name|x
parameter_list|)
value|((x)<< 19)
end_define

begin_define
define|#
directive|define
name|R600_BARYC_SAMPLE_CNTL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 26)
end_define

begin_define
define|#
directive|define
name|R600_PERSP_GRADIENT_ENA
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|R600_LINEAR_GRADIENT_ENA
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|R600_POSITION_SAMPLE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|R600_BARYC_AT_SAMPLE_ENA
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|R600_SPI_PS_IN_CONTROL_1
value|0x286d0
end_define

begin_define
define|#
directive|define
name|R600_GEN_INDEX_PIX
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R600_GEN_INDEX_PIX_ADDR
parameter_list|(
name|x
parameter_list|)
value|((x)<< 1)
end_define

begin_define
define|#
directive|define
name|R600_FRONT_FACE_ENA
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|R600_FRONT_FACE_CHAN
parameter_list|(
name|x
parameter_list|)
value|((x)<< 9)
end_define

begin_define
define|#
directive|define
name|R600_FRONT_FACE_ALL_BITS
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|R600_FRONT_FACE_ADDR
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
end_define

begin_define
define|#
directive|define
name|R600_FOG_ADDR
parameter_list|(
name|x
parameter_list|)
value|((x)<< 17)
end_define

begin_define
define|#
directive|define
name|R600_FIXED_PT_POSITION_ENA
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|R600_FIXED_PT_POSITION_ADDR
parameter_list|(
name|x
parameter_list|)
value|((x)<< 25)
end_define

begin_define
define|#
directive|define
name|R700_POSITION_ULC
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|R600_SPI_INPUT_Z
value|0x286d8
end_define

begin_define
define|#
directive|define
name|R600_SPI_CONFIG_CNTL
value|0x9100
end_define

begin_define
define|#
directive|define
name|R600_GPR_WRITE_PRIORITY
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R600_DISABLE_INTERP_1
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|R600_SPI_CONFIG_CNTL_1
value|0x913c
end_define

begin_define
define|#
directive|define
name|R600_VTX_DONE_DELAY
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R600_INTERP_ONE_PRIM_PER_ROW
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|R600_GB_TILING_CONFIG
value|0x98f0
end_define

begin_define
define|#
directive|define
name|R600_PIPE_TILING
parameter_list|(
name|x
parameter_list|)
value|((x)<< 1)
end_define

begin_define
define|#
directive|define
name|R600_BANK_TILING
parameter_list|(
name|x
parameter_list|)
value|((x)<< 4)
end_define

begin_define
define|#
directive|define
name|R600_GROUP_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 6)
end_define

begin_define
define|#
directive|define
name|R600_ROW_TILING
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|R600_BANK_SWAPS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 11)
end_define

begin_define
define|#
directive|define
name|R600_SAMPLE_SPLIT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 14)
end_define

begin_define
define|#
directive|define
name|R600_BACKEND_MAP
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|R600_DCP_TILING_CONFIG
value|0x6ca0
end_define

begin_define
define|#
directive|define
name|R600_HDP_TILING_CONFIG
value|0x2f3c
end_define

begin_define
define|#
directive|define
name|R600_CC_RB_BACKEND_DISABLE
value|0x98f4
end_define

begin_define
define|#
directive|define
name|R700_CC_SYS_RB_BACKEND_DISABLE
value|0x3f88
end_define

begin_define
define|#
directive|define
name|R600_BACKEND_DISABLE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|R600_CC_GC_SHADER_PIPE_CONFIG
value|0x8950
end_define

begin_define
define|#
directive|define
name|R600_GC_USER_SHADER_PIPE_CONFIG
value|0x8954
end_define

begin_define
define|#
directive|define
name|R600_INACTIVE_QD_PIPES
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|R600_INACTIVE_QD_PIPES_MASK
value|(0xff<< 8)
end_define

begin_define
define|#
directive|define
name|R600_INACTIVE_SIMDS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|R600_INACTIVE_SIMDS_MASK
value|(0xff<< 16)
end_define

begin_define
define|#
directive|define
name|R700_CGTS_SYS_TCC_DISABLE
value|0x3f90
end_define

begin_define
define|#
directive|define
name|R700_CGTS_USER_SYS_TCC_DISABLE
value|0x3f94
end_define

begin_define
define|#
directive|define
name|R700_CGTS_TCC_DISABLE
value|0x9148
end_define

begin_define
define|#
directive|define
name|R700_CGTS_USER_TCC_DISABLE
value|0x914c
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
name|R600_LAST_FRAME_REG
value|R600_SCRATCH_REG0
end_define

begin_define
define|#
directive|define
name|R600_LAST_DISPATCH_REG
value|R600_SCRATCH_REG1
end_define

begin_define
define|#
directive|define
name|R600_LAST_CLEAR_REG
value|R600_SCRATCH_REG2
end_define

begin_define
define|#
directive|define
name|R600_LAST_SWI_REG
value|R600_SCRATCH_REG3
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
define|\
value|do {									\ 	if (reg< 0x10000) {				                \ 		DRM_WRITE32(dev_priv->mmio, (reg), (val));		\ 	} else {                                                        \ 		DRM_WRITE32(dev_priv->mmio, RADEON_MM_INDEX, (reg));	\ 		DRM_WRITE32(dev_priv->mmio, RADEON_MM_DATA, (val));	\ 	}                                                               \ } while (0)
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
value|do {									\ 	RADEON_WRITE8(RADEON_CLOCK_CNTL_INDEX,				\ 		       ((addr)& 0x1f) | RADEON_PLL_WR_EN );		\ 	RADEON_WRITE(RADEON_CLOCK_CNTL_DATA, (val));			\ } while (0)
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
value|do {									\ 	RADEON_WRITE8(RADEON_PCIE_INDEX,				\ 			((addr)& 0xff));				\ 	RADEON_WRITE(RADEON_PCIE_DATA, (val));			\ } while (0)
end_define

begin_define
define|#
directive|define
name|R500_WRITE_MCIND
parameter_list|(
name|addr
parameter_list|,
name|val
parameter_list|)
define|\
value|do {								\ 	RADEON_WRITE(R520_MC_IND_INDEX, 0xff0000 | ((addr)& 0xff));	\ 	RADEON_WRITE(R520_MC_IND_DATA, (val));			\ 	RADEON_WRITE(R520_MC_IND_INDEX, 0);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|RS480_WRITE_MCIND
parameter_list|(
name|addr
parameter_list|,
name|val
parameter_list|)
define|\
value|do {									\ 	RADEON_WRITE(RS480_NB_MC_INDEX,				\ 			((addr)& 0xff) | RS480_NB_MC_IND_WR_EN);	\ 	RADEON_WRITE(RS480_NB_MC_DATA, (val));			\ 	RADEON_WRITE(RS480_NB_MC_INDEX, 0xff);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|RS690_WRITE_MCIND
parameter_list|(
name|addr
parameter_list|,
name|val
parameter_list|)
define|\
value|do {								\ 	RADEON_WRITE(RS690_MC_INDEX, RS690_MC_INDEX_WR_EN | ((addr)& RS690_MC_INDEX_MASK));	\ 	RADEON_WRITE(RS690_MC_DATA, val);			\ 	RADEON_WRITE(RS690_MC_INDEX, RS690_MC_INDEX_WR_ACK);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|RS600_WRITE_MCIND
parameter_list|(
name|addr
parameter_list|,
name|val
parameter_list|)
define|\
value|do {							        \ 	RADEON_WRITE(RS600_MC_INDEX, RS600_MC_IND_WR_EN | RS600_MC_IND_CITF_ARB0 | ((addr)& RS600_MC_ADDR_MASK)); \ 	RADEON_WRITE(RS600_MC_DATA, val);                       \ } while (0)
end_define

begin_define
define|#
directive|define
name|IGP_WRITE_MCIND
parameter_list|(
name|addr
parameter_list|,
name|val
parameter_list|)
define|\
value|do {									\ 	if (((dev_priv->flags& RADEON_FAMILY_MASK) == CHIP_RS690) ||   \ 	    ((dev_priv->flags& RADEON_FAMILY_MASK) == CHIP_RS740))      \ 		RS690_WRITE_MCIND(addr, val);				\ 	else if ((dev_priv->flags& RADEON_FAMILY_MASK) == CHIP_RS600)  \ 		RS600_WRITE_MCIND(addr, val);				\ 	else								\ 		RS480_WRITE_MCIND(addr, val);				\ } while (0)
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
value|do {				\ 	if ((dev_priv->flags& RADEON_FAMILY_MASK)>= CHIP_R600)        \ 		OUT_RING( CP_PACKET0( R600_WAIT_UNTIL, 0 ) );           \ 	else                                                            \ 		OUT_RING( CP_PACKET0( RADEON_WAIT_UNTIL, 0 ) );         \ 	OUT_RING( (RADEON_WAIT_2D_IDLECLEAN |				\ 		   RADEON_WAIT_HOST_IDLECLEAN) );			\ } while (0)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_UNTIL_3D_IDLE
parameter_list|()
value|do {				\ 	if ((dev_priv->flags& RADEON_FAMILY_MASK)>= CHIP_R600)        \ 		OUT_RING( CP_PACKET0( R600_WAIT_UNTIL, 0 ) );           \ 	else                                                            \ 		OUT_RING( CP_PACKET0( RADEON_WAIT_UNTIL, 0 ) );         \ 	OUT_RING( (RADEON_WAIT_3D_IDLECLEAN |				\ 		   RADEON_WAIT_HOST_IDLECLEAN) );			\ } while (0)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_UNTIL_IDLE
parameter_list|()
value|do {					\ 	if ((dev_priv->flags& RADEON_FAMILY_MASK)>= CHIP_R600)        \ 		OUT_RING( CP_PACKET0( R600_WAIT_UNTIL, 0 ) );           \ 	else                                                            \ 		OUT_RING( CP_PACKET0( RADEON_WAIT_UNTIL, 0 ) );         \ 	OUT_RING( (RADEON_WAIT_2D_IDLECLEAN |				\ 		   RADEON_WAIT_3D_IDLECLEAN |				\ 		   RADEON_WAIT_HOST_IDLECLEAN) );			\ } while (0)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_UNTIL_PAGE_FLIPPED
parameter_list|()
value|do {				\ 	if ((dev_priv->flags& RADEON_FAMILY_MASK)>= CHIP_R600)        \ 		OUT_RING( CP_PACKET0( R600_WAIT_UNTIL, 0 ) );           \ 	else                                                            \ 		OUT_RING( CP_PACKET0( RADEON_WAIT_UNTIL, 0 ) );         \ 	OUT_RING( RADEON_WAIT_CRTC_PFLIP );				\ } while (0)
end_define

begin_define
define|#
directive|define
name|RADEON_FLUSH_CACHE
parameter_list|()
value|do {					\ 	if ((dev_priv->flags& RADEON_FAMILY_MASK)<= CHIP_RV280) {	\ 		OUT_RING(CP_PACKET0(RADEON_RB3D_DSTCACHE_CTLSTAT, 0));	\ 		OUT_RING(RADEON_RB3D_DC_FLUSH);				\ 	} else {                                                        \ 		OUT_RING(CP_PACKET0(R300_RB3D_DSTCACHE_CTLSTAT, 0));	\ 		OUT_RING(R300_RB3D_DC_FLUSH);				\ 	}                                                               \ } while (0)
end_define

begin_define
define|#
directive|define
name|RADEON_PURGE_CACHE
parameter_list|()
value|do {					\ 	if ((dev_priv->flags& RADEON_FAMILY_MASK)<= CHIP_RV280) {	\ 		OUT_RING(CP_PACKET0(RADEON_RB3D_DSTCACHE_CTLSTAT, 0));	\ 		OUT_RING(RADEON_RB3D_DC_FLUSH | RADEON_RB3D_DC_FREE);	\ 	} else {                                                        \ 		OUT_RING(CP_PACKET0(R300_RB3D_DSTCACHE_CTLSTAT, 0));	\ 		OUT_RING(R300_RB3D_DC_FLUSH | R300_RB3D_DC_FREE);	\ 	}                                                               \ } while (0)
end_define

begin_define
define|#
directive|define
name|RADEON_FLUSH_ZCACHE
parameter_list|()
value|do {					\ 	if ((dev_priv->flags& RADEON_FAMILY_MASK)<= CHIP_RV280) {	\ 		OUT_RING(CP_PACKET0(RADEON_RB3D_ZCACHE_CTLSTAT, 0));	\ 		OUT_RING(RADEON_RB3D_ZC_FLUSH);				\ 	} else {                                                        \ 		OUT_RING(CP_PACKET0(R300_ZB_ZCACHE_CTLSTAT, 0));	\ 		OUT_RING(R300_ZC_FLUSH);				\ 	}                                                               \ } while (0)
end_define

begin_define
define|#
directive|define
name|RADEON_PURGE_ZCACHE
parameter_list|()
value|do {					\ 	if ((dev_priv->flags& RADEON_FAMILY_MASK)<= CHIP_RV280) {	\ 		OUT_RING(CP_PACKET0(RADEON_RB3D_ZCACHE_CTLSTAT, 0));	\ 		OUT_RING(RADEON_RB3D_ZC_FLUSH | RADEON_RB3D_ZC_FREE);			\ 	} else {                                                        \ 		OUT_RING(CP_PACKET0(R300_ZB_ZCACHE_CTLSTAT, 0));	\ 		OUT_RING(R300_ZC_FLUSH | R300_ZC_FREE);				\ 	}                                                               \ } while (0)
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
value|do {								\ 	drm_radeon_sarea_t *sarea_priv = dev_priv->sarea_priv;	\ 	if ( sarea_priv->last_dispatch>= RADEON_MAX_VB_AGE ) {		\ 		int __ret;						\ 		if ((dev_priv->flags& RADEON_FAMILY_MASK)>= CHIP_R600) \ 			__ret = r600_do_cp_idle(dev_priv);		\ 		else							\ 			__ret = radeon_do_cp_idle(dev_priv);		\ 		if ( __ret ) return __ret;				\ 		sarea_priv->last_dispatch = 0;				\ 		radeon_freelist_reset( dev );				\ 	}								\ } while (0)
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

begin_define
define|#
directive|define
name|R600_DISPATCH_AGE
parameter_list|(
name|age
parameter_list|)
value|do {					\ 	OUT_RING(CP_PACKET3(R600_IT_SET_CONFIG_REG, 1));		\ 	OUT_RING((R600_LAST_DISPATCH_REG - R600_SET_CONFIG_REG_OFFSET)>> 2);  \ 	OUT_RING(age);							\ } while (0)
end_define

begin_define
define|#
directive|define
name|R600_FRAME_AGE
parameter_list|(
name|age
parameter_list|)
value|do {					\ 	OUT_RING(CP_PACKET3(R600_IT_SET_CONFIG_REG, 1));		\ 	OUT_RING((R600_LAST_FRAME_REG - R600_SET_CONFIG_REG_OFFSET)>> 2);  \ 	OUT_RING(age);							\ } while (0)
end_define

begin_define
define|#
directive|define
name|R600_CLEAR_AGE
parameter_list|(
name|age
parameter_list|)
value|do {					\ 	OUT_RING(CP_PACKET3(R600_IT_SET_CONFIG_REG, 1));		\ 	OUT_RING((R600_LAST_CLEAR_REG - R600_SET_CONFIG_REG_OFFSET)>> 2);  \ 	OUT_RING(age);							\ } while (0)
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
value|int write, _nr, _align_nr; unsigned int mask; u32 *ring;
end_define

begin_define
define|#
directive|define
name|RADEON_RING_ALIGN
value|16
end_define

begin_define
define|#
directive|define
name|BEGIN_RING
parameter_list|(
name|n
parameter_list|)
value|do {						\ 	if ( RADEON_VERBOSE ) {						\ 		DRM_INFO( "BEGIN_RING( %d )\n", (n));			\ 	}								\ 	_align_nr = RADEON_RING_ALIGN - ((dev_priv->ring.tail + n)& (RADEON_RING_ALIGN - 1)); \ 	_align_nr += n;							\ 	if ( dev_priv->ring.space<= (_align_nr) * sizeof(u32) ) {	\ 		COMMIT_RING();						\ 		radeon_wait_ring( dev_priv, (_align_nr) * sizeof(u32) ); \ 	}								\ 	_nr = n; dev_priv->ring.space -= (n) * sizeof(u32);		\ 	ring = dev_priv->ring.start;					\ 	write = dev_priv->ring.tail;					\ 	mask = dev_priv->ring.tail_mask;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|ADVANCE_RING
parameter_list|()
value|do {						\ 	if ( RADEON_VERBOSE ) {						\ 		DRM_INFO( "ADVANCE_RING() wr=0x%06x tail=0x%06x\n",	\ 			  write, dev_priv->ring.tail );			\ 	}								\ 	if (((dev_priv->ring.tail + _nr)& mask) != write) {		\ 		DRM_ERROR(						\ 			"ADVANCE_RING(): mismatch: nr: %x write: %x line: %d\n",	\ 			((dev_priv->ring.tail + _nr)& mask),		\ 			write, __LINE__);				\ 	} else								\ 		dev_priv->ring.tail = write;				\ } while (0)
end_define

begin_function_decl
specifier|extern
name|void
name|radeon_commit_ring
parameter_list|(
name|drm_radeon_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|COMMIT_RING
parameter_list|()
value|do {						\ 		radeon_commit_ring(dev_priv);				\ 	} while(0)
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
value|do {					\ 	int _size = (sz);					\ 	int *_tab = (int *)(tab);				\ 								\ 	if (write + _size> mask) {				\ 		int _i = (mask+1) - write;			\ 		_size -= _i;					\ 		while (_i> 0 ) {				\ 			*(int *)(ring + write) = *_tab++;	\ 			write++;				\ 			_i--;					\ 		}						\ 		write = 0;					\ 		_tab += _i;					\ 	}							\ 	while (_size> 0) {					\ 		*(ring + write) = *_tab++;			\ 		write++;					\ 		_size--;					\ 	}							\ 	write&= mask;						\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __RADEON_DRV_H__ */
end_comment

end_unit

