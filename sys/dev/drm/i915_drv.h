begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* i915_drv.h -- Private header for the I915 driver -*- linux-c -*-  */
end_comment

begin_comment
comment|/*  *  * Copyright 2003 Tungsten Graphics, Inc., Cedar Park, Texas.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the  * "Software"), to deal in the Software without restriction, including  * without limitation the rights to use, copy, modify, merge, publish,  * distribute, sub license, and/or sell copies of the Software, and to  * permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *  * The above copyright notice and this permission notice (including the  * next paragraph) shall be included in all copies or substantial portions  * of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.  * IN NO EVENT SHALL TUNGSTEN GRAPHICS AND/OR ITS SUPPLIERS BE LIABLE FOR  * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE  * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  *  */
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
name|_I915_DRV_H_
end_ifndef

begin_define
define|#
directive|define
name|_I915_DRV_H_
end_define

begin_comment
comment|/* General customization:  */
end_comment

begin_define
define|#
directive|define
name|DRIVER_AUTHOR
value|"Tungsten Graphics, Inc."
end_define

begin_define
define|#
directive|define
name|DRIVER_NAME
value|"i915"
end_define

begin_define
define|#
directive|define
name|DRIVER_DESC
value|"Intel Graphics"
end_define

begin_define
define|#
directive|define
name|DRIVER_DATE
value|"20080730"
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

begin_define
define|#
directive|define
name|I915_HAVE_FENCE
end_define

begin_define
define|#
directive|define
name|I915_HAVE_BUFFER
end_define

begin_define
define|#
directive|define
name|I915_HAVE_GEM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Interface history:  *  * 1.1: Original.  * 1.2: Add Power Management  * 1.3: Add vblank support  * 1.4: Fix cmdbuffer path, add heap destroy  * 1.5: Add vblank pipe configuration  * 1.6: - New ioctl for scheduling buffer swaps on vertical blank  *      - Support vertical blank on secondary display pipe  * 1.8: New ioctl for ARB_Occlusion_Query  * 1.9: Usable page flipping and triple buffering  * 1.10: Plane/pipe disentangling  * 1.11: TTM superioctl  * 1.12: TTM relocation optimization  */
end_comment

begin_define
define|#
directive|define
name|DRIVER_MAJOR
value|1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|I915_HAVE_FENCE
argument_list|)
operator|&&
name|defined
argument_list|(
name|I915_HAVE_BUFFER
argument_list|)
end_if

begin_define
define|#
directive|define
name|DRIVER_MINOR
value|13
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DRIVER_MINOR
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DRIVER_PATCHLEVEL
value|0
end_define

begin_enum
enum|enum
name|pipe
block|{
name|PIPE_A
init|=
literal|0
block|,
name|PIPE_B
block|, }
enum|;
end_enum

begin_ifdef
ifdef|#
directive|ifdef
name|I915_HAVE_BUFFER
end_ifdef

begin_define
define|#
directive|define
name|I915_MAX_VALIDATE_BUFFERS
value|4096
end_define

begin_struct_decl
struct_decl|struct
name|drm_i915_validate_buffer
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WATCH_COHERENCY
value|0
end_define

begin_define
define|#
directive|define
name|WATCH_BUF
value|0
end_define

begin_define
define|#
directive|define
name|WATCH_EXEC
value|0
end_define

begin_define
define|#
directive|define
name|WATCH_LRU
value|0
end_define

begin_define
define|#
directive|define
name|WATCH_RELOC
value|0
end_define

begin_define
define|#
directive|define
name|WATCH_INACTIVE
value|0
end_define

begin_define
define|#
directive|define
name|WATCH_PWRITE
value|0
end_define

begin_typedef
typedef|typedef
struct|struct
name|_drm_i915_ring_buffer
block|{
name|int
name|tail_mask
decl_stmt|;
name|unsigned
name|long
name|Size
decl_stmt|;
name|u8
modifier|*
name|virtual_start
decl_stmt|;
name|int
name|head
decl_stmt|;
name|int
name|tail
decl_stmt|;
name|int
name|space
decl_stmt|;
name|drm_local_map_t
name|map
decl_stmt|;
name|struct
name|drm_gem_object
modifier|*
name|ring_obj
decl_stmt|;
block|}
name|drm_i915_ring_buffer_t
typedef|;
end_typedef

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

begin_typedef
typedef|typedef
struct|struct
name|_drm_i915_vbl_swap
block|{
name|struct
name|list_head
name|head
decl_stmt|;
name|drm_drawable_t
name|drw_id
decl_stmt|;
name|unsigned
name|int
name|plane
decl_stmt|;
name|unsigned
name|int
name|sequence
decl_stmt|;
name|int
name|flip
decl_stmt|;
block|}
name|drm_i915_vbl_swap_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_struct_decl
struct_decl|struct
name|opregion_header
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|opregion_acpi
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|opregion_swsci
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|opregion_asle
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|intel_opregion
block|{
name|struct
name|opregion_header
modifier|*
name|header
decl_stmt|;
name|struct
name|opregion_acpi
modifier|*
name|acpi
decl_stmt|;
name|struct
name|opregion_swsci
modifier|*
name|swsci
decl_stmt|;
name|struct
name|opregion_asle
modifier|*
name|asle
decl_stmt|;
name|int
name|enabled
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|drm_i915_private
block|{
name|struct
name|drm_device
modifier|*
name|dev
decl_stmt|;
name|drm_local_map_t
modifier|*
name|sarea
decl_stmt|;
name|drm_local_map_t
modifier|*
name|mmio_map
decl_stmt|;
name|drm_i915_sarea_t
modifier|*
name|sarea_priv
decl_stmt|;
name|drm_i915_ring_buffer_t
name|ring
decl_stmt|;
name|drm_dma_handle_t
modifier|*
name|status_page_dmah
decl_stmt|;
name|void
modifier|*
name|hw_status_page
decl_stmt|;
name|dma_addr_t
name|dma_status_page
decl_stmt|;
name|uint32_t
name|counter
decl_stmt|;
name|unsigned
name|int
name|status_gfx_addr
decl_stmt|;
name|drm_local_map_t
name|hws_map
decl_stmt|;
name|struct
name|drm_gem_object
modifier|*
name|hws_obj
decl_stmt|;
name|unsigned
name|int
name|cpp
decl_stmt|;
name|wait_queue_head_t
name|irq_queue
decl_stmt|;
name|atomic_t
name|irq_received
decl_stmt|;
name|int
name|tex_lru_log_granularity
decl_stmt|;
name|int
name|allow_batchbuffer
decl_stmt|;
name|struct
name|mem_block
modifier|*
name|agp_heap
decl_stmt|;
name|unsigned
name|int
name|sr01
decl_stmt|,
name|adpa
decl_stmt|,
name|ppcr
decl_stmt|,
name|dvob
decl_stmt|,
name|dvoc
decl_stmt|,
name|lvds
decl_stmt|;
name|int
name|vblank_pipe
decl_stmt|;
name|DRM_SPINTYPE
name|user_irq_lock
decl_stmt|;
name|int
name|user_irq_refcount
decl_stmt|;
name|int
name|fence_irq_on
decl_stmt|;
name|uint32_t
name|irq_mask_reg
decl_stmt|;
name|int
name|irq_enabled
decl_stmt|;
ifdef|#
directive|ifdef
name|I915_HAVE_FENCE
name|uint32_t
name|flush_sequence
decl_stmt|;
name|uint32_t
name|flush_flags
decl_stmt|;
name|uint32_t
name|flush_pending
decl_stmt|;
name|uint32_t
name|saved_flush_status
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|I915_HAVE_BUFFER
name|void
modifier|*
name|agp_iomap
decl_stmt|;
name|unsigned
name|int
name|max_validate_buffers
decl_stmt|;
name|struct
name|mutex
name|cmdbuf_mutex
decl_stmt|;
name|struct
name|drm_i915_validate_buffer
modifier|*
name|val_bufs
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|I915_HAVE_BUFFER
argument_list|)
comment|/* DRI2 sarea */
name|struct
name|drm_buffer_object
modifier|*
name|sarea_bo
decl_stmt|;
name|struct
name|drm_bo_kmap_obj
name|sarea_kmap
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__linux__
name|struct
name|intel_opregion
name|opregion
decl_stmt|;
endif|#
directive|endif
comment|/* Register state */
name|u8
name|saveLBB
decl_stmt|;
name|u32
name|saveDSPACNTR
decl_stmt|;
name|u32
name|saveDSPBCNTR
decl_stmt|;
name|u32
name|saveDSPARB
decl_stmt|;
name|u32
name|savePIPEACONF
decl_stmt|;
name|u32
name|savePIPEBCONF
decl_stmt|;
name|u32
name|savePIPEASRC
decl_stmt|;
name|u32
name|savePIPEBSRC
decl_stmt|;
name|u32
name|saveFPA0
decl_stmt|;
name|u32
name|saveFPA1
decl_stmt|;
name|u32
name|saveDPLL_A
decl_stmt|;
name|u32
name|saveDPLL_A_MD
decl_stmt|;
name|u32
name|saveHTOTAL_A
decl_stmt|;
name|u32
name|saveHBLANK_A
decl_stmt|;
name|u32
name|saveHSYNC_A
decl_stmt|;
name|u32
name|saveVTOTAL_A
decl_stmt|;
name|u32
name|saveVBLANK_A
decl_stmt|;
name|u32
name|saveVSYNC_A
decl_stmt|;
name|u32
name|saveBCLRPAT_A
decl_stmt|;
name|u32
name|savePIPEASTAT
decl_stmt|;
name|u32
name|saveDSPASTRIDE
decl_stmt|;
name|u32
name|saveDSPASIZE
decl_stmt|;
name|u32
name|saveDSPAPOS
decl_stmt|;
name|u32
name|saveDSPAADDR
decl_stmt|;
name|u32
name|saveDSPASURF
decl_stmt|;
name|u32
name|saveDSPATILEOFF
decl_stmt|;
name|u32
name|savePFIT_PGM_RATIOS
decl_stmt|;
name|u32
name|saveBLC_PWM_CTL
decl_stmt|;
name|u32
name|saveBLC_PWM_CTL2
decl_stmt|;
name|u32
name|saveFPB0
decl_stmt|;
name|u32
name|saveFPB1
decl_stmt|;
name|u32
name|saveDPLL_B
decl_stmt|;
name|u32
name|saveDPLL_B_MD
decl_stmt|;
name|u32
name|saveHTOTAL_B
decl_stmt|;
name|u32
name|saveHBLANK_B
decl_stmt|;
name|u32
name|saveHSYNC_B
decl_stmt|;
name|u32
name|saveVTOTAL_B
decl_stmt|;
name|u32
name|saveVBLANK_B
decl_stmt|;
name|u32
name|saveVSYNC_B
decl_stmt|;
name|u32
name|saveBCLRPAT_B
decl_stmt|;
name|u32
name|savePIPEBSTAT
decl_stmt|;
name|u32
name|saveDSPBSTRIDE
decl_stmt|;
name|u32
name|saveDSPBSIZE
decl_stmt|;
name|u32
name|saveDSPBPOS
decl_stmt|;
name|u32
name|saveDSPBADDR
decl_stmt|;
name|u32
name|saveDSPBSURF
decl_stmt|;
name|u32
name|saveDSPBTILEOFF
decl_stmt|;
name|u32
name|saveVGA0
decl_stmt|;
name|u32
name|saveVGA1
decl_stmt|;
name|u32
name|saveVGA_PD
decl_stmt|;
name|u32
name|saveVGACNTRL
decl_stmt|;
name|u32
name|saveADPA
decl_stmt|;
name|u32
name|saveLVDS
decl_stmt|;
name|u32
name|savePP_ON_DELAYS
decl_stmt|;
name|u32
name|savePP_OFF_DELAYS
decl_stmt|;
name|u32
name|saveDVOA
decl_stmt|;
name|u32
name|saveDVOB
decl_stmt|;
name|u32
name|saveDVOC
decl_stmt|;
name|u32
name|savePP_ON
decl_stmt|;
name|u32
name|savePP_OFF
decl_stmt|;
name|u32
name|savePP_CONTROL
decl_stmt|;
name|u32
name|savePP_DIVISOR
decl_stmt|;
name|u32
name|savePFIT_CONTROL
decl_stmt|;
name|u32
name|save_palette_a
index|[
literal|256
index|]
decl_stmt|;
name|u32
name|save_palette_b
index|[
literal|256
index|]
decl_stmt|;
name|u32
name|saveFBC_CFB_BASE
decl_stmt|;
name|u32
name|saveFBC_LL_BASE
decl_stmt|;
name|u32
name|saveFBC_CONTROL
decl_stmt|;
name|u32
name|saveFBC_CONTROL2
decl_stmt|;
name|u32
name|saveIER
decl_stmt|;
name|u32
name|saveIIR
decl_stmt|;
name|u32
name|saveIMR
decl_stmt|;
name|u32
name|saveCACHE_MODE_0
decl_stmt|;
name|u32
name|saveD_STATE
decl_stmt|;
name|u32
name|saveCG_2D_DIS
decl_stmt|;
name|u32
name|saveMI_ARB_STATE
decl_stmt|;
name|u32
name|saveSWF0
index|[
literal|16
index|]
decl_stmt|;
name|u32
name|saveSWF1
index|[
literal|16
index|]
decl_stmt|;
name|u32
name|saveSWF2
index|[
literal|3
index|]
decl_stmt|;
name|u8
name|saveMSR
decl_stmt|;
name|u8
name|saveSR
index|[
literal|8
index|]
decl_stmt|;
name|u8
name|saveGR
index|[
literal|25
index|]
decl_stmt|;
name|u8
name|saveAR_INDEX
decl_stmt|;
name|u8
name|saveAR
index|[
literal|21
index|]
decl_stmt|;
name|u8
name|saveDACMASK
decl_stmt|;
name|u8
name|saveDACDATA
index|[
literal|256
operator|*
literal|3
index|]
decl_stmt|;
comment|/* 256 3-byte colors */
name|u8
name|saveCR
index|[
literal|37
index|]
decl_stmt|;
struct|struct
block|{
ifdef|#
directive|ifdef
name|__linux__
name|struct
name|drm_mm
name|gtt_space
decl_stmt|;
endif|#
directive|endif
comment|/** 		 * List of objects currently involved in rendering from the 		 * ringbuffer. 		 * 		 * A reference is held on the buffer while on this list. 		 */
name|struct
name|list_head
name|active_list
decl_stmt|;
comment|/** 		 * List of objects which are not in the ringbuffer but which 		 * still have a write_domain which needs to be flushed before 		 * unbinding. 		 * 		 * A reference is held on the buffer while on this list. 		 */
name|struct
name|list_head
name|flushing_list
decl_stmt|;
comment|/** 		 * LRU list of objects which are not in the ringbuffer and 		 * are ready to unbind, but are still in the GTT. 		 * 		 * A reference is not held on the buffer while on this list, 		 * as merely being GTT-bound shouldn't prevent its being 		 * freed, and we'll pull it off the list in the free path. 		 */
name|struct
name|list_head
name|inactive_list
decl_stmt|;
comment|/** 		 * List of breadcrumbs associated with GPU requests currently 		 * outstanding. 		 */
name|struct
name|list_head
name|request_list
decl_stmt|;
ifdef|#
directive|ifdef
name|__linux__
comment|/** 		 * We leave the user IRQ off as much as possible, 		 * but this means that requests will finish and never 		 * be retired once the system goes idle. Set a timer to 		 * fire periodically while the ring is running. When it 		 * fires, go retire requests. 		 */
name|struct
name|delayed_work
name|retire_work
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|next_gem_seqno
decl_stmt|;
comment|/** 		 * Waiting sequence number, if any 		 */
name|uint32_t
name|waiting_gem_seqno
decl_stmt|;
comment|/** 		 * Last seq seen at irq time 		 */
name|uint32_t
name|irq_gem_seqno
decl_stmt|;
comment|/** 		 * Flag if the X Server, and thus DRM, is not currently in 		 * control of the device. 		 * 		 * This is set between LeaveVT and EnterVT.  It needs to be 		 * replaced with a semaphore.  It also needs to be 		 * transitioned away from for kernel modesetting. 		 */
name|int
name|suspended
decl_stmt|;
comment|/** 		 * Flag if the hardware appears to be wedged. 		 * 		 * This is set when attempts to idle the device timeout. 		 * It prevents command submission from occuring and makes 		 * every pending request fail 		 */
name|int
name|wedged
decl_stmt|;
comment|/** Bit 6 swizzling required for X tiling */
name|uint32_t
name|bit_6_swizzle_x
decl_stmt|;
comment|/** Bit 6 swizzling required for Y tiling */
name|uint32_t
name|bit_6_swizzle_y
decl_stmt|;
block|}
name|mm
struct|;
block|}
name|drm_i915_private_t
typedef|;
end_typedef

begin_struct
struct|struct
name|drm_i915_file_private
block|{
struct|struct
block|{
name|uint32_t
name|last_gem_seqno
decl_stmt|;
name|uint32_t
name|last_gem_throttle_seqno
decl_stmt|;
block|}
name|mm
struct|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|intel_chip_family
block|{
name|CHIP_I8XX
init|=
literal|0x01
block|,
name|CHIP_I9XX
init|=
literal|0x02
block|,
name|CHIP_I915
init|=
literal|0x04
block|,
name|CHIP_I965
init|=
literal|0x08
block|, }
enum|;
end_enum

begin_comment
comment|/** driver private structure attached to each drm_gem_object */
end_comment

begin_struct
struct|struct
name|drm_i915_gem_object
block|{
name|struct
name|drm_gem_object
modifier|*
name|obj
decl_stmt|;
comment|/** Current space allocated to this object in the GTT, if any. */
name|struct
name|drm_mm_node
modifier|*
name|gtt_space
decl_stmt|;
comment|/** This object's place on the active/flushing/inactive lists */
name|struct
name|list_head
name|list
decl_stmt|;
comment|/** 	 * This is set if the object is on the active or flushing lists 	 * (has pending rendering), and is not set if it's on inactive (ready 	 * to be unbound). 	 */
name|int
name|active
decl_stmt|;
comment|/** 	 * This is set if the object has been written to since last bound 	 * to the GTT 	 */
name|int
name|dirty
decl_stmt|;
comment|/** AGP memory structure for our GTT binding. */
name|DRM_AGP_MEM
modifier|*
name|agp_mem
decl_stmt|;
name|struct
name|page
modifier|*
modifier|*
name|page_list
decl_stmt|;
comment|/** 	 * Current offset of the object in GTT space. 	 * 	 * This is the same as gtt_space->start 	 */
name|uint32_t
name|gtt_offset
decl_stmt|;
comment|/** Boolean whether this object has a valid gtt offset. */
name|int
name|gtt_bound
decl_stmt|;
comment|/** How many users have pinned this object in GTT space */
name|int
name|pin_count
decl_stmt|;
comment|/** Breadcrumb of last rendering to the buffer. */
name|uint32_t
name|last_rendering_seqno
decl_stmt|;
comment|/** Current tiling mode for the object. */
name|uint32_t
name|tiling_mode
decl_stmt|;
comment|/** 	 * Flagging of which individual pages are valid in GEM_DOMAIN_CPU when 	 * GEM_DOMAIN_CPU is not in the object's read domain. 	 */
name|uint8_t
modifier|*
name|page_cpu_valid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Request queue structure.  *  * The request queue allows us to note sequence numbers that have been emitted  * and may be associated with active buffers to be retired.  *  * By keeping this list, we can avoid having to do questionable  * sequence-number comparisons on buffer last_rendering_seqnos, and associate  * an emission time with seqnos for tracking how far ahead of the GPU we are.  */
end_comment

begin_struct
struct|struct
name|drm_i915_gem_request
block|{
comment|/** GEM sequence number associated with this request. */
name|uint32_t
name|seqno
decl_stmt|;
comment|/** Time at which this request was emitted, in jiffies. */
name|unsigned
name|long
name|emitted_jiffies
decl_stmt|;
comment|/** Cache domains that were flushed at the start of the request. */
name|uint32_t
name|flush_domains
decl_stmt|;
name|struct
name|list_head
name|list
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|drm_ioctl_desc
name|i915_ioctls
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|i915_max_ioctl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* i915_dma.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|i915_kernel_lost_context
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
name|i915_driver_load
parameter_list|(
name|struct
name|drm_device
modifier|*
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
name|i915_driver_unload
parameter_list|(
name|struct
name|drm_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i915_driver_lastclose
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
name|i915_driver_open
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
name|i915_driver_preclose
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
name|i915_driver_postclose
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
name|i915_driver_device_is_agp
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
name|long
name|i915_compat_ioctl
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

begin_function_decl
specifier|extern
name|void
name|i915_emit_breadcrumb
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
name|i915_dispatch_flip
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|pipes
parameter_list|,
name|int
name|sync
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i915_emit_mi_flush
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|uint32_t
name|flush
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i915_driver_firstopen
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
name|i915_dispatch_batchbuffer
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|drm_i915_batchbuffer_t
modifier|*
name|batch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i915_quiescent
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
name|i915_init_hardware_status
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
name|i915_free_hardware_status
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|i915_emit_box
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_clip_rect
name|__user
modifier|*
name|boxes
parameter_list|,
name|int
name|i
parameter_list|,
name|int
name|DR1
parameter_list|,
name|int
name|DR4
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* i915_irq.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|i915_irq_emit
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
name|i915_irq_wait
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
name|irqreturn_t
name|i915_driver_irq_handler
parameter_list|(
name|DRM_IRQ_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i915_driver_irq_preinstall
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
name|i915_driver_irq_postinstall
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
name|i915_driver_irq_uninstall
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
name|i915_vblank_pipe_set
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
name|i915_vblank_pipe_get
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
name|i915_emit_irq
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
name|i915_wait_irq
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|irq_nr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i915_enable_vblank
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
name|i915_disable_vblank
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
name|u32
name|i915_get_vblank_counter
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
name|i915_vblank_swap
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
name|i915_user_irq_on
parameter_list|(
name|drm_i915_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i915_user_irq_off
parameter_list|(
name|drm_i915_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* i915_mem.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|i915_mem_alloc
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
name|i915_mem_free
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
name|i915_mem_init_heap
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
name|i915_mem_destroy_heap
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
name|i915_mem_takedown
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
name|i915_mem_release
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
name|struct
name|mem_block
modifier|*
name|heap
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* i915_suspend.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|i915_save_state
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
name|i915_restore_state
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|I915_HAVE_FENCE
end_ifdef

begin_comment
comment|/* i915_fence.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|i915_fence_handler
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
name|i915_invalidate_reported_sequence
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I915_HAVE_BUFFER
end_ifdef

begin_comment
comment|/* i915_buffer.c */
end_comment

begin_function_decl
specifier|extern
name|struct
name|drm_ttm_backend
modifier|*
name|i915_create_ttm_backend_entry
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
name|i915_fence_type
parameter_list|(
name|struct
name|drm_buffer_object
modifier|*
name|bo
parameter_list|,
name|uint32_t
modifier|*
name|fclass
parameter_list|,
name|uint32_t
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i915_invalidate_caches
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|uint64_t
name|buffer_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i915_init_mem_type
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|uint32_t
name|type
parameter_list|,
name|struct
name|drm_mem_type_manager
modifier|*
name|man
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|i915_evict_flags
parameter_list|(
name|struct
name|drm_buffer_object
modifier|*
name|bo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i915_move
parameter_list|(
name|struct
name|drm_buffer_object
modifier|*
name|bo
parameter_list|,
name|int
name|evict
parameter_list|,
name|int
name|no_wait
parameter_list|,
name|struct
name|drm_bo_mem_reg
modifier|*
name|new_mem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i915_flush_ttm
parameter_list|(
name|struct
name|drm_ttm
modifier|*
name|ttm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* i915_execbuf.c */
end_comment

begin_function_decl
name|int
name|i915_execbuffer
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

begin_comment
comment|/* i915_gem.c */
end_comment

begin_function_decl
name|int
name|i915_gem_init_ioctl
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
name|int
name|i915_gem_create_ioctl
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
name|int
name|i915_gem_pread_ioctl
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
name|int
name|i915_gem_pwrite_ioctl
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
name|int
name|i915_gem_mmap_ioctl
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
name|int
name|i915_gem_set_domain_ioctl
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
name|int
name|i915_gem_sw_finish_ioctl
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
name|int
name|i915_gem_execbuffer
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
name|int
name|i915_gem_pin_ioctl
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
name|int
name|i915_gem_unpin_ioctl
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
name|int
name|i915_gem_busy_ioctl
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
name|int
name|i915_gem_throttle_ioctl
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
name|int
name|i915_gem_entervt_ioctl
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
name|int
name|i915_gem_leavevt_ioctl
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
name|int
name|i915_gem_set_tiling
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
name|int
name|i915_gem_get_tiling
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
name|void
name|i915_gem_load
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|i915_gem_proc_init
parameter_list|(
name|struct
name|drm_minor
modifier|*
name|minor
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i915_gem_proc_cleanup
parameter_list|(
name|struct
name|drm_minor
modifier|*
name|minor
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|i915_gem_init_object
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i915_gem_free_object
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|i915_gem_object_pin
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|,
name|uint32_t
name|alignment
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i915_gem_object_unpin
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i915_gem_lastclose
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|i915_get_gem_seqno
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i915_gem_retire_requests
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i915_gem_retire_work_handler
parameter_list|(
name|struct
name|work_struct
modifier|*
name|work
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i915_gem_clflush_object
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* i915_gem_tiling.c */
end_comment

begin_function_decl
name|void
name|i915_gem_detect_bit_6_swizzle
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* i915_gem_debug.c */
end_comment

begin_if
if|#
directive|if
name|WATCH_INACTIVE
end_if

begin_function_decl
name|void
name|i915_verify_inactive
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|i915_verify_inactive
parameter_list|(
name|dev
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|i915_gem_object_check_coherency
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|,
name|int
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i915_gem_dump_object
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|,
name|int
name|len
parameter_list|,
specifier|const
name|char
modifier|*
name|where
parameter_list|,
name|uint32_t
name|mark
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i915_dump_lru
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|where
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_comment
comment|/* i915_opregion.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|intel_opregion_init
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
name|intel_opregion_free
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
name|opregion_asle_intr
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
name|opregion_enable_asle
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_if
if|#
directive|if
name|LINUX_VERSION_CODE
operator|<
name|KERNEL_VERSION
argument_list|(
literal|2
operator|,
literal|6
operator|,
literal|25
argument_list|)
end_if

begin_function_decl
specifier|extern
name|void
name|intel_init_chipset_flush_compat
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
name|intel_fini_chipset_flush_compat
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|I915_READ
parameter_list|(
name|reg
parameter_list|)
value|DRM_READ32(dev_priv->mmio_map, (reg))
end_define

begin_define
define|#
directive|define
name|I915_WRITE
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
value|DRM_WRITE32(dev_priv->mmio_map, (reg), (val))
end_define

begin_define
define|#
directive|define
name|I915_READ16
parameter_list|(
name|reg
parameter_list|)
value|DRM_READ16(dev_priv->mmio_map, (reg))
end_define

begin_define
define|#
directive|define
name|I915_WRITE16
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
value|DRM_WRITE16(dev_priv->mmio_map, (reg), (val))
end_define

begin_define
define|#
directive|define
name|I915_READ8
parameter_list|(
name|reg
parameter_list|)
value|DRM_READ8(dev_priv->mmio_map, (reg))
end_define

begin_define
define|#
directive|define
name|I915_WRITE8
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
value|DRM_WRITE8(dev_priv->mmio_map, (reg), (val))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_typedef
typedef|typedef
name|boolean_t
name|bool
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|I915_VERBOSE
value|0
end_define

begin_define
define|#
directive|define
name|I915_RING_VALIDATE
value|0
end_define

begin_define
define|#
directive|define
name|PRIMARY_RINGBUFFER_SIZE
value|(128*1024)
end_define

begin_define
define|#
directive|define
name|RING_LOCALS
value|unsigned int outring, ringmask, outcount; \ 			volatile char *virt;
end_define

begin_if
if|#
directive|if
name|I915_RING_VALIDATE
end_if

begin_function_decl
name|void
name|i915_ring_validate
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|I915_RING_DO_VALIDATE
parameter_list|(
name|dev
parameter_list|)
value|i915_ring_validate(dev, __FUNCTION__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|I915_RING_DO_VALIDATE
parameter_list|(
name|dev
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BEGIN_LP_RING
parameter_list|(
name|n
parameter_list|)
value|do {				\ 	if (I915_VERBOSE)				\ 		DRM_DEBUG("BEGIN_LP_RING(%d)\n",	\ 	                         (n));		        \ 	I915_RING_DO_VALIDATE(dev);			\ 	if (dev_priv->ring.space< (n)*4)                      \ 		i915_wait_ring(dev, (n)*4, __FUNCTION__);      \ 	outcount = 0;					\ 	outring = dev_priv->ring.tail;			\ 	ringmask = dev_priv->ring.tail_mask;		\ 	virt = dev_priv->ring.virtual_start;		\ } while (0)
end_define

begin_define
define|#
directive|define
name|OUT_RING
parameter_list|(
name|n
parameter_list|)
value|do {					\ 	if (I915_VERBOSE) DRM_DEBUG("   OUT_RING %x\n", (int)(n));	\ 	*(volatile unsigned int *)(virt + outring) = (n);		\ 	outcount++;						\ 	outring += 4;						\ 	outring&= ringmask;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|ADVANCE_LP_RING
parameter_list|()
value|do {						\ 	if (I915_VERBOSE) DRM_DEBUG("ADVANCE_LP_RING %x\n", outring);	\ 	I915_RING_DO_VALIDATE(dev);					\ 	dev_priv->ring.tail = outring;					\ 	dev_priv->ring.space -= outcount * 4;				\ 	I915_WRITE(PRB0_TAIL, outring);			\ } while(0)
end_define

begin_function_decl
specifier|extern
name|int
name|i915_wait_ring
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|n
parameter_list|,
specifier|const
name|char
modifier|*
name|caller
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|BREADCRUMB_BITS
value|31
end_define

begin_define
define|#
directive|define
name|BREADCRUMB_MASK
value|((1U<< BREADCRUMB_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|READ_BREADCRUMB
parameter_list|(
name|dev_priv
parameter_list|)
value|(((volatile u32*)(dev_priv->hw_status_page))[5])
end_define

begin_comment
comment|/**  * Reads a dword out of the status page, which is written to from the command  * queue by automatic updates, MI_REPORT_HEAD, MI_STORE_DATA_INDEX, or  * MI_STORE_DATA_IMM.  *  * The following dwords have a reserved meaning:  * 0: ISR copy, updated when an ISR bit not set in the HWSTAM changes.  * 4: ring 0 head pointer  * 5: ring 1 head pointer (915-class)  * 6: ring 2 head pointer (915-class)  *  * The area from dword 0x10 to 0x3ff is available for driver usage.  */
end_comment

begin_define
define|#
directive|define
name|READ_HWSP
parameter_list|(
name|dev_priv
parameter_list|,
name|reg
parameter_list|)
value|(((volatile u32*)(dev_priv->hw_status_page))[reg])
end_define

begin_define
define|#
directive|define
name|I915_GEM_HWS_INDEX
value|0x10
end_define

begin_comment
comment|/* MCH MMIO space */
end_comment

begin_comment
comment|/** 915-945 and GM965 MCH register controlling DRAM channel access */
end_comment

begin_define
define|#
directive|define
name|DCC
value|0x200
end_define

begin_define
define|#
directive|define
name|DCC_ADDRESSING_MODE_SINGLE_CHANNEL
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|DCC_ADDRESSING_MODE_DUAL_CHANNEL_ASYMMETRIC
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DCC_ADDRESSING_MODE_DUAL_CHANNEL_INTERLEAVED
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|DCC_ADDRESSING_MODE_MASK
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|DCC_CHANNEL_XOR_DISABLE
value|(1<< 10)
end_define

begin_comment
comment|/** 965 MCH register controlling DRAM channel configuration */
end_comment

begin_define
define|#
directive|define
name|CHDECMISC
value|0x111
end_define

begin_define
define|#
directive|define
name|CHDECMISC_FLEXMEMORY
value|(1<< 1)
end_define

begin_comment
comment|/*  * The Bridge device's PCI config space has information about the  * fb aperture size and the amount of pre-reserved memory.  */
end_comment

begin_define
define|#
directive|define
name|INTEL_GMCH_CTRL
value|0x52
end_define

begin_define
define|#
directive|define
name|INTEL_GMCH_ENABLED
value|0x4
end_define

begin_define
define|#
directive|define
name|INTEL_GMCH_MEM_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|INTEL_GMCH_MEM_64M
value|0x1
end_define

begin_define
define|#
directive|define
name|INTEL_GMCH_MEM_128M
value|0
end_define

begin_define
define|#
directive|define
name|INTEL_855_GMCH_GMS_MASK
value|(0x7<< 4)
end_define

begin_define
define|#
directive|define
name|INTEL_855_GMCH_GMS_DISABLED
value|(0x0<< 4)
end_define

begin_define
define|#
directive|define
name|INTEL_855_GMCH_GMS_STOLEN_1M
value|(0x1<< 4)
end_define

begin_define
define|#
directive|define
name|INTEL_855_GMCH_GMS_STOLEN_4M
value|(0x2<< 4)
end_define

begin_define
define|#
directive|define
name|INTEL_855_GMCH_GMS_STOLEN_8M
value|(0x3<< 4)
end_define

begin_define
define|#
directive|define
name|INTEL_855_GMCH_GMS_STOLEN_16M
value|(0x4<< 4)
end_define

begin_define
define|#
directive|define
name|INTEL_855_GMCH_GMS_STOLEN_32M
value|(0x5<< 4)
end_define

begin_define
define|#
directive|define
name|INTEL_915G_GMCH_GMS_STOLEN_48M
value|(0x6<< 4)
end_define

begin_define
define|#
directive|define
name|INTEL_915G_GMCH_GMS_STOLEN_64M
value|(0x7<< 4)
end_define

begin_comment
comment|/* PCI config space */
end_comment

begin_define
define|#
directive|define
name|HPLLCC
value|0xc0
end_define

begin_comment
comment|/* 855 only */
end_comment

begin_define
define|#
directive|define
name|GC_CLOCK_CONTROL_MASK
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|GC_CLOCK_133_200
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|GC_CLOCK_100_200
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|GC_CLOCK_100_133
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|GC_CLOCK_166_250
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|GCFGC
value|0xf0
end_define

begin_comment
comment|/* 915+ only */
end_comment

begin_define
define|#
directive|define
name|GC_LOW_FREQUENCY_ENABLE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|GC_DISPLAY_CLOCK_190_200_MHZ
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|GC_DISPLAY_CLOCK_333_MHZ
value|(4<< 4)
end_define

begin_define
define|#
directive|define
name|GC_DISPLAY_CLOCK_MASK
value|(7<< 4)
end_define

begin_define
define|#
directive|define
name|LBB
value|0xf4
end_define

begin_comment
comment|/* VGA stuff */
end_comment

begin_define
define|#
directive|define
name|VGA_ST01_MDA
value|0x3ba
end_define

begin_define
define|#
directive|define
name|VGA_ST01_CGA
value|0x3da
end_define

begin_define
define|#
directive|define
name|VGA_MSR_WRITE
value|0x3c2
end_define

begin_define
define|#
directive|define
name|VGA_MSR_READ
value|0x3cc
end_define

begin_define
define|#
directive|define
name|VGA_MSR_MEM_EN
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|VGA_MSR_CGA_MODE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|VGA_SR_INDEX
value|0x3c4
end_define

begin_define
define|#
directive|define
name|VGA_SR_DATA
value|0x3c5
end_define

begin_define
define|#
directive|define
name|VGA_AR_INDEX
value|0x3c0
end_define

begin_define
define|#
directive|define
name|VGA_AR_VID_EN
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|VGA_AR_DATA_WRITE
value|0x3c0
end_define

begin_define
define|#
directive|define
name|VGA_AR_DATA_READ
value|0x3c1
end_define

begin_define
define|#
directive|define
name|VGA_GR_INDEX
value|0x3ce
end_define

begin_define
define|#
directive|define
name|VGA_GR_DATA
value|0x3cf
end_define

begin_comment
comment|/* GR05 */
end_comment

begin_define
define|#
directive|define
name|VGA_GR_MEM_READ_MODE_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|VGA_GR_MEM_READ_MODE_PLANE
value|1
end_define

begin_comment
comment|/* GR06 */
end_comment

begin_define
define|#
directive|define
name|VGA_GR_MEM_MODE_MASK
value|0xc
end_define

begin_define
define|#
directive|define
name|VGA_GR_MEM_MODE_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|VGA_GR_MEM_A0000_AFFFF
value|0
end_define

begin_define
define|#
directive|define
name|VGA_GR_MEM_A0000_BFFFF
value|1
end_define

begin_define
define|#
directive|define
name|VGA_GR_MEM_B0000_B7FFF
value|2
end_define

begin_define
define|#
directive|define
name|VGA_GR_MEM_B0000_BFFFF
value|3
end_define

begin_define
define|#
directive|define
name|VGA_DACMASK
value|0x3c6
end_define

begin_define
define|#
directive|define
name|VGA_DACRX
value|0x3c7
end_define

begin_define
define|#
directive|define
name|VGA_DACWX
value|0x3c8
end_define

begin_define
define|#
directive|define
name|VGA_DACDATA
value|0x3c9
end_define

begin_define
define|#
directive|define
name|VGA_CR_INDEX_MDA
value|0x3b4
end_define

begin_define
define|#
directive|define
name|VGA_CR_DATA_MDA
value|0x3b5
end_define

begin_define
define|#
directive|define
name|VGA_CR_INDEX_CGA
value|0x3d4
end_define

begin_define
define|#
directive|define
name|VGA_CR_DATA_CGA
value|0x3d5
end_define

begin_comment
comment|/*  * Memory interface instructions used by the kernel  */
end_comment

begin_define
define|#
directive|define
name|MI_INSTR
parameter_list|(
name|opcode
parameter_list|,
name|flags
parameter_list|)
value|(((opcode)<< 23) | (flags))
end_define

begin_define
define|#
directive|define
name|MI_NOOP
value|MI_INSTR(0, 0)
end_define

begin_define
define|#
directive|define
name|MI_USER_INTERRUPT
value|MI_INSTR(0x02, 0)
end_define

begin_define
define|#
directive|define
name|MI_WAIT_FOR_EVENT
value|MI_INSTR(0x03, 0)
end_define

begin_define
define|#
directive|define
name|MI_WAIT_FOR_PLANE_B_FLIP
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|MI_WAIT_FOR_PLANE_A_FLIP
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|MI_WAIT_FOR_PLANE_A_SCANLINES
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|MI_FLUSH
value|MI_INSTR(0x04, 0)
end_define

begin_define
define|#
directive|define
name|MI_READ_FLUSH
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MI_EXE_FLUSH
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MI_NO_WRITE_FLUSH
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MI_SCENE_COUNT
value|(1<< 3)
end_define

begin_comment
comment|/* just increment scene count */
end_comment

begin_define
define|#
directive|define
name|MI_END_SCENE
value|(1<< 4)
end_define

begin_comment
comment|/* flush binner and incr scene count */
end_comment

begin_define
define|#
directive|define
name|MI_BATCH_BUFFER_END
value|MI_INSTR(0x0a, 0)
end_define

begin_define
define|#
directive|define
name|MI_REPORT_HEAD
value|MI_INSTR(0x07, 0)
end_define

begin_define
define|#
directive|define
name|MI_LOAD_SCAN_LINES_INCL
value|MI_INSTR(0x12, 0)
end_define

begin_define
define|#
directive|define
name|MI_STORE_DWORD_IMM
value|MI_INSTR(0x20, 1)
end_define

begin_define
define|#
directive|define
name|MI_MEM_VIRTUAL
value|(1<< 22)
end_define

begin_comment
comment|/* 965+ only */
end_comment

begin_define
define|#
directive|define
name|MI_STORE_DWORD_INDEX
value|MI_INSTR(0x21, 1)
end_define

begin_define
define|#
directive|define
name|MI_STORE_DWORD_INDEX_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|MI_LOAD_REGISTER_IMM
value|MI_INSTR(0x22, 1)
end_define

begin_define
define|#
directive|define
name|MI_BATCH_BUFFER
value|MI_INSTR(0x30, 1)
end_define

begin_define
define|#
directive|define
name|MI_BATCH_NON_SECURE
value|(1)
end_define

begin_define
define|#
directive|define
name|MI_BATCH_NON_SECURE_I965
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|MI_BATCH_BUFFER_START
value|MI_INSTR(0x31, 0)
end_define

begin_comment
comment|/*  * 3D instructions used by the kernel  */
end_comment

begin_define
define|#
directive|define
name|GFX_INSTR
parameter_list|(
name|opcode
parameter_list|,
name|flags
parameter_list|)
value|((0x3<< 29) | ((opcode)<< 24) | (flags))
end_define

begin_define
define|#
directive|define
name|GFX_OP_RASTER_RULES
value|((0x3<<29)|(0x7<<24))
end_define

begin_define
define|#
directive|define
name|GFX_OP_SCISSOR
value|((0x3<<29)|(0x1c<<24)|(0x10<<19))
end_define

begin_define
define|#
directive|define
name|SC_UPDATE_SCISSOR
value|(0x1<<1)
end_define

begin_define
define|#
directive|define
name|SC_ENABLE_MASK
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|SC_ENABLE
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|GFX_OP_LOAD_INDIRECT
value|((0x3<<29)|(0x1d<<24)|(0x7<<16))
end_define

begin_define
define|#
directive|define
name|GFX_OP_SCISSOR_INFO
value|((0x3<<29)|(0x1d<<24)|(0x81<<16)|(0x1))
end_define

begin_define
define|#
directive|define
name|SCI_YMIN_MASK
value|(0xffff<<16)
end_define

begin_define
define|#
directive|define
name|SCI_XMIN_MASK
value|(0xffff<<0)
end_define

begin_define
define|#
directive|define
name|SCI_YMAX_MASK
value|(0xffff<<16)
end_define

begin_define
define|#
directive|define
name|SCI_XMAX_MASK
value|(0xffff<<0)
end_define

begin_define
define|#
directive|define
name|GFX_OP_SCISSOR_ENABLE
value|((0x3<<29)|(0x1c<<24)|(0x10<<19))
end_define

begin_define
define|#
directive|define
name|GFX_OP_SCISSOR_RECT
value|((0x3<<29)|(0x1d<<24)|(0x81<<16)|1)
end_define

begin_define
define|#
directive|define
name|GFX_OP_COLOR_FACTOR
value|((0x3<<29)|(0x1d<<24)|(0x1<<16)|0x0)
end_define

begin_define
define|#
directive|define
name|GFX_OP_STIPPLE
value|((0x3<<29)|(0x1d<<24)|(0x83<<16))
end_define

begin_define
define|#
directive|define
name|GFX_OP_MAP_INFO
value|((0x3<<29)|(0x1d<<24)|0x4)
end_define

begin_define
define|#
directive|define
name|GFX_OP_DESTBUFFER_VARS
value|((0x3<<29)|(0x1d<<24)|(0x85<<16)|0x0)
end_define

begin_define
define|#
directive|define
name|GFX_OP_DESTBUFFER_INFO
value|((0x3<<29)|(0x1d<<24)|(0x8e<<16)|1)
end_define

begin_define
define|#
directive|define
name|GFX_OP_DRAWRECT_INFO
value|((0x3<<29)|(0x1d<<24)|(0x80<<16)|(0x3))
end_define

begin_define
define|#
directive|define
name|GFX_OP_DRAWRECT_INFO_I965
value|((0x7900<<16)|0x2)
end_define

begin_define
define|#
directive|define
name|SRC_COPY_BLT_CMD
value|((2<<29)|(0x43<<22)|4)
end_define

begin_define
define|#
directive|define
name|XY_SRC_COPY_BLT_CMD
value|((2<<29)|(0x53<<22)|6)
end_define

begin_define
define|#
directive|define
name|XY_MONO_SRC_COPY_IMM_BLT
value|((2<<29)|(0x71<<22)|5)
end_define

begin_define
define|#
directive|define
name|XY_SRC_COPY_BLT_WRITE_ALPHA
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|XY_SRC_COPY_BLT_WRITE_RGB
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|BLT_DEPTH_8
value|(0<<24)
end_define

begin_define
define|#
directive|define
name|BLT_DEPTH_16_565
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|BLT_DEPTH_16_1555
value|(2<<24)
end_define

begin_define
define|#
directive|define
name|BLT_DEPTH_32
value|(3<<24)
end_define

begin_define
define|#
directive|define
name|BLT_ROP_GXCOPY
value|(0xcc<<16)
end_define

begin_define
define|#
directive|define
name|XY_SRC_COPY_BLT_SRC_TILED
value|(1<<15)
end_define

begin_comment
comment|/* 965+ only */
end_comment

begin_define
define|#
directive|define
name|XY_SRC_COPY_BLT_DST_TILED
value|(1<<11)
end_define

begin_comment
comment|/* 965+ only */
end_comment

begin_define
define|#
directive|define
name|CMD_OP_DISPLAYBUFFER_INFO
value|((0x0<<29)|(0x14<<23)|2)
end_define

begin_define
define|#
directive|define
name|ASYNC_FLIP
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|DISPLAY_PLANE_A
value|(0<<20)
end_define

begin_define
define|#
directive|define
name|DISPLAY_PLANE_B
value|(1<<20)
end_define

begin_comment
comment|/*  * Instruction and interrupt control regs  */
end_comment

begin_define
define|#
directive|define
name|PRB0_TAIL
value|0x02030
end_define

begin_define
define|#
directive|define
name|PRB0_HEAD
value|0x02034
end_define

begin_define
define|#
directive|define
name|PRB0_START
value|0x02038
end_define

begin_define
define|#
directive|define
name|PRB0_CTL
value|0x0203c
end_define

begin_define
define|#
directive|define
name|TAIL_ADDR
value|0x001FFFF8
end_define

begin_define
define|#
directive|define
name|HEAD_WRAP_COUNT
value|0xFFE00000
end_define

begin_define
define|#
directive|define
name|HEAD_WRAP_ONE
value|0x00200000
end_define

begin_define
define|#
directive|define
name|HEAD_ADDR
value|0x001FFFFC
end_define

begin_define
define|#
directive|define
name|RING_NR_PAGES
value|0x001FF000
end_define

begin_define
define|#
directive|define
name|RING_REPORT_MASK
value|0x00000006
end_define

begin_define
define|#
directive|define
name|RING_REPORT_64K
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RING_REPORT_128K
value|0x00000004
end_define

begin_define
define|#
directive|define
name|RING_NO_REPORT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RING_VALID_MASK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RING_VALID
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RING_INVALID
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PRB1_TAIL
value|0x02040
end_define

begin_comment
comment|/* 915+ only */
end_comment

begin_define
define|#
directive|define
name|PRB1_HEAD
value|0x02044
end_define

begin_comment
comment|/* 915+ only */
end_comment

begin_define
define|#
directive|define
name|PRB1_START
value|0x02048
end_define

begin_comment
comment|/* 915+ only */
end_comment

begin_define
define|#
directive|define
name|PRB1_CTL
value|0x0204c
end_define

begin_comment
comment|/* 915+ only */
end_comment

begin_define
define|#
directive|define
name|ACTHD_I965
value|0x02074
end_define

begin_define
define|#
directive|define
name|HWS_PGA
value|0x02080
end_define

begin_define
define|#
directive|define
name|HWS_ADDRESS_MASK
value|0xfffff000
end_define

begin_define
define|#
directive|define
name|HWS_START_ADDRESS_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|IPEIR
value|0x02088
end_define

begin_define
define|#
directive|define
name|NOPID
value|0x02094
end_define

begin_define
define|#
directive|define
name|HWSTAM
value|0x02098
end_define

begin_define
define|#
directive|define
name|SCPD0
value|0x0209c
end_define

begin_comment
comment|/* 915+ only */
end_comment

begin_define
define|#
directive|define
name|IER
value|0x020a0
end_define

begin_define
define|#
directive|define
name|IIR
value|0x020a4
end_define

begin_define
define|#
directive|define
name|IMR
value|0x020a8
end_define

begin_define
define|#
directive|define
name|ISR
value|0x020ac
end_define

begin_define
define|#
directive|define
name|I915_PIPE_CONTROL_NOTIFY_INTERRUPT
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|I915_DISPLAY_PORT_INTERRUPT
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|I915_RENDER_COMMAND_PARSER_ERROR_INTERRUPT
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|I915_GMCH_THERMAL_SENSOR_EVENT_INTERRUPT
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|I915_HWB_OOM_INTERRUPT
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|I915_SYNC_STATUS_INTERRUPT
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|I915_DISPLAY_PLANE_A_FLIP_PENDING_INTERRUPT
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|I915_DISPLAY_PLANE_B_FLIP_PENDING_INTERRUPT
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_PLANE_FLIP_PENDING_INTERRUPT
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|I915_DISPLAY_PLANE_C_FLIP_PENDING_INTERRUPT
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|I915_DISPLAY_PIPE_A_VBLANK_INTERRUPT
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|I915_DISPLAY_PIPE_A_EVENT_INTERRUPT
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|I915_DISPLAY_PIPE_B_VBLANK_INTERRUPT
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|I915_DISPLAY_PIPE_B_EVENT_INTERRUPT
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|I915_DEBUG_INTERRUPT
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|I915_USER_INTERRUPT
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|I915_ASLE_INTERRUPT
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|EIR
value|0x020b0
end_define

begin_define
define|#
directive|define
name|EMR
value|0x020b4
end_define

begin_define
define|#
directive|define
name|ESR
value|0x020b8
end_define

begin_define
define|#
directive|define
name|INSTPM
value|0x020c0
end_define

begin_define
define|#
directive|define
name|ACTHD
value|0x020c8
end_define

begin_define
define|#
directive|define
name|FW_BLC
value|0x020d8
end_define

begin_define
define|#
directive|define
name|FW_BLC_SELF
value|0x020e0
end_define

begin_comment
comment|/* 915+ only */
end_comment

begin_define
define|#
directive|define
name|MI_ARB_STATE
value|0x020e4
end_define

begin_comment
comment|/* 915+ only */
end_comment

begin_define
define|#
directive|define
name|CACHE_MODE_0
value|0x02120
end_define

begin_comment
comment|/* 915+ only */
end_comment

begin_define
define|#
directive|define
name|CM0_MASK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CM0_IZ_OPT_DISABLE
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|CM0_ZR_OPT_DISABLE
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|CM0_DEPTH_EVICT_DISABLE
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|CM0_COLOR_EVICT_DISABLE
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|CM0_DEPTH_WRITE_DISABLE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|CM0_RC_OP_FLUSH_DISABLE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|GFX_FLSH_CNTL
value|0x02170
end_define

begin_comment
comment|/* 915+ only */
end_comment

begin_comment
comment|/*  * Framebuffer compression (915+ only)  */
end_comment

begin_define
define|#
directive|define
name|FBC_CFB_BASE
value|0x03200
end_define

begin_comment
comment|/* 4k page aligned */
end_comment

begin_define
define|#
directive|define
name|FBC_LL_BASE
value|0x03204
end_define

begin_comment
comment|/* 4k page aligned */
end_comment

begin_define
define|#
directive|define
name|FBC_CONTROL
value|0x03208
end_define

begin_define
define|#
directive|define
name|FBC_CTL_EN
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_PERIODIC
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_INTERVAL_SHIFT
value|(16)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_UNCOMPRESSIBLE
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_STRIDE_SHIFT
value|(5)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_FENCENO
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|FBC_COMMAND
value|0x0320c
end_define

begin_define
define|#
directive|define
name|FBC_CMD_COMPRESS
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|FBC_STATUS
value|0x03210
end_define

begin_define
define|#
directive|define
name|FBC_STAT_COMPRESSING
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|FBC_STAT_COMPRESSED
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|FBC_STAT_MODIFIED
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|FBC_STAT_CURRENT_LINE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|FBC_CONTROL2
value|0x03214
end_define

begin_define
define|#
directive|define
name|FBC_CTL_FENCE_DBL
value|(0<<4)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_IDLE_IMM
value|(0<<2)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_IDLE_FULL
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_IDLE_LINE
value|(2<<2)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_IDLE_DEBUG
value|(3<<2)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_CPU_FENCE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_PLANEA
value|(0<<0)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_PLANEB
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|FBC_FENCE_OFF
value|0x0321b
end_define

begin_define
define|#
directive|define
name|FBC_LL_SIZE
value|(1536)
end_define

begin_comment
comment|/*  * GPIO regs  */
end_comment

begin_define
define|#
directive|define
name|GPIOA
value|0x5010
end_define

begin_define
define|#
directive|define
name|GPIOB
value|0x5014
end_define

begin_define
define|#
directive|define
name|GPIOC
value|0x5018
end_define

begin_define
define|#
directive|define
name|GPIOD
value|0x501c
end_define

begin_define
define|#
directive|define
name|GPIOE
value|0x5020
end_define

begin_define
define|#
directive|define
name|GPIOF
value|0x5024
end_define

begin_define
define|#
directive|define
name|GPIOG
value|0x5028
end_define

begin_define
define|#
directive|define
name|GPIOH
value|0x502c
end_define

begin_define
define|#
directive|define
name|GPIO_CLOCK_DIR_MASK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|GPIO_CLOCK_DIR_IN
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|GPIO_CLOCK_DIR_OUT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|GPIO_CLOCK_VAL_MASK
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|GPIO_CLOCK_VAL_OUT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|GPIO_CLOCK_VAL_IN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|GPIO_CLOCK_PULLUP_DISABLE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|GPIO_DATA_DIR_MASK
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|GPIO_DATA_DIR_IN
value|(0<< 9)
end_define

begin_define
define|#
directive|define
name|GPIO_DATA_DIR_OUT
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|GPIO_DATA_VAL_MASK
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|GPIO_DATA_VAL_OUT
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|GPIO_DATA_VAL_IN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|GPIO_DATA_PULLUP_DISABLE
value|(1<< 13)
end_define

begin_comment
comment|/*  * Clock control& power management  */
end_comment

begin_define
define|#
directive|define
name|VGA0
value|0x6000
end_define

begin_define
define|#
directive|define
name|VGA1
value|0x6004
end_define

begin_define
define|#
directive|define
name|VGA_PD
value|0x6010
end_define

begin_define
define|#
directive|define
name|VGA0_PD_P2_DIV_4
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|VGA0_PD_P1_DIV_2
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|VGA0_PD_P1_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|VGA0_PD_P1_MASK
value|(0x1f<< 0)
end_define

begin_define
define|#
directive|define
name|VGA1_PD_P2_DIV_4
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|VGA1_PD_P1_DIV_2
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|VGA1_PD_P1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|VGA1_PD_P1_MASK
value|(0x1f<< 8)
end_define

begin_define
define|#
directive|define
name|DPLL_A
value|0x06014
end_define

begin_define
define|#
directive|define
name|DPLL_B
value|0x06018
end_define

begin_define
define|#
directive|define
name|DPLL_VCO_ENABLE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|DPLL_DVO_HIGH_SPEED
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|DPLL_SYNCLOCK_ENABLE
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|DPLL_VGA_MODE_DIS
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|DPLLB_MODE_DAC_SERIAL
value|(1<< 26)
end_define

begin_comment
comment|/* i915 */
end_comment

begin_define
define|#
directive|define
name|DPLLB_MODE_LVDS
value|(2<< 26)
end_define

begin_comment
comment|/* i915 */
end_comment

begin_define
define|#
directive|define
name|DPLL_MODE_MASK
value|(3<< 26)
end_define

begin_define
define|#
directive|define
name|DPLL_DAC_SERIAL_P2_CLOCK_DIV_10
value|(0<< 24)
end_define

begin_comment
comment|/* i915 */
end_comment

begin_define
define|#
directive|define
name|DPLL_DAC_SERIAL_P2_CLOCK_DIV_5
value|(1<< 24)
end_define

begin_comment
comment|/* i915 */
end_comment

begin_define
define|#
directive|define
name|DPLLB_LVDS_P2_CLOCK_DIV_14
value|(0<< 24)
end_define

begin_comment
comment|/* i915 */
end_comment

begin_define
define|#
directive|define
name|DPLLB_LVDS_P2_CLOCK_DIV_7
value|(1<< 24)
end_define

begin_comment
comment|/* i915 */
end_comment

begin_define
define|#
directive|define
name|DPLL_P2_CLOCK_DIV_MASK
value|0x03000000
end_define

begin_comment
comment|/* i915 */
end_comment

begin_define
define|#
directive|define
name|DPLL_FPA01_P1_POST_DIV_MASK
value|0x00ff0000
end_define

begin_comment
comment|/* i915 */
end_comment

begin_define
define|#
directive|define
name|I915_FIFO_UNDERRUN_STATUS
value|(1UL<<31)
end_define

begin_define
define|#
directive|define
name|I915_CRC_ERROR_ENABLE
value|(1UL<<29)
end_define

begin_define
define|#
directive|define
name|I915_CRC_DONE_ENABLE
value|(1UL<<28)
end_define

begin_define
define|#
directive|define
name|I915_GMBUS_EVENT_ENABLE
value|(1UL<<27)
end_define

begin_define
define|#
directive|define
name|I915_VSYNC_INTERRUPT_ENABLE
value|(1UL<<25)
end_define

begin_define
define|#
directive|define
name|I915_DISPLAY_LINE_COMPARE_ENABLE
value|(1UL<<24)
end_define

begin_define
define|#
directive|define
name|I915_DPST_EVENT_ENABLE
value|(1UL<<23)
end_define

begin_define
define|#
directive|define
name|I915_LEGACY_BLC_EVENT_ENABLE
value|(1UL<<22)
end_define

begin_define
define|#
directive|define
name|I915_ODD_FIELD_INTERRUPT_ENABLE
value|(1UL<<21)
end_define

begin_define
define|#
directive|define
name|I915_EVEN_FIELD_INTERRUPT_ENABLE
value|(1UL<<20)
end_define

begin_define
define|#
directive|define
name|I915_START_VBLANK_INTERRUPT_ENABLE
value|(1UL<<18)
end_define

begin_comment
comment|/* 965 or later */
end_comment

begin_define
define|#
directive|define
name|I915_VBLANK_INTERRUPT_ENABLE
value|(1UL<<17)
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_UPDATED_ENABLE
value|(1UL<<16)
end_define

begin_define
define|#
directive|define
name|I915_CRC_ERROR_INTERRUPT_STATUS
value|(1UL<<13)
end_define

begin_define
define|#
directive|define
name|I915_CRC_DONE_INTERRUPT_STATUS
value|(1UL<<12)
end_define

begin_define
define|#
directive|define
name|I915_GMBUS_INTERRUPT_STATUS
value|(1UL<<11)
end_define

begin_define
define|#
directive|define
name|I915_VSYNC_INTERRUPT_STATUS
value|(1UL<<9)
end_define

begin_define
define|#
directive|define
name|I915_DISPLAY_LINE_COMPARE_STATUS
value|(1UL<<8)
end_define

begin_define
define|#
directive|define
name|I915_DPST_EVENT_STATUS
value|(1UL<<7)
end_define

begin_define
define|#
directive|define
name|I915_LEGACY_BLC_EVENT_STATUS
value|(1UL<<6)
end_define

begin_define
define|#
directive|define
name|I915_ODD_FIELD_INTERRUPT_STATUS
value|(1UL<<5)
end_define

begin_define
define|#
directive|define
name|I915_EVEN_FIELD_INTERRUPT_STATUS
value|(1UL<<4)
end_define

begin_define
define|#
directive|define
name|I915_START_VBLANK_INTERRUPT_STATUS
value|(1UL<<2)
end_define

begin_comment
comment|/* 965 or later */
end_comment

begin_define
define|#
directive|define
name|I915_VBLANK_INTERRUPT_STATUS
value|(1UL<<1)
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_UPDATED_STATUS
value|(1UL<<0)
end_define

begin_define
define|#
directive|define
name|SRX_INDEX
value|0x3c4
end_define

begin_define
define|#
directive|define
name|SRX_DATA
value|0x3c5
end_define

begin_define
define|#
directive|define
name|SR01
value|1
end_define

begin_define
define|#
directive|define
name|SR01_SCREEN_OFF
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|PPCR
value|0x61204
end_define

begin_define
define|#
directive|define
name|PPCR_ON
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DVOB
value|0x61140
end_define

begin_define
define|#
directive|define
name|DVOB_ON
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|DVOC
value|0x61160
end_define

begin_define
define|#
directive|define
name|DVOC_ON
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|LVDS
value|0x61180
end_define

begin_define
define|#
directive|define
name|LVDS_ON
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|ADPA
value|0x61100
end_define

begin_define
define|#
directive|define
name|ADPA_DPMS_MASK
value|(~(3<<10))
end_define

begin_define
define|#
directive|define
name|ADPA_DPMS_ON
value|(0<<10)
end_define

begin_define
define|#
directive|define
name|ADPA_DPMS_SUSPEND
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|ADPA_DPMS_STANDBY
value|(2<<10)
end_define

begin_define
define|#
directive|define
name|ADPA_DPMS_OFF
value|(3<<10)
end_define

begin_define
define|#
directive|define
name|RING_TAIL
value|0x00
end_define

begin_define
define|#
directive|define
name|TAIL_ADDR
value|0x001FFFF8
end_define

begin_define
define|#
directive|define
name|RING_HEAD
value|0x04
end_define

begin_define
define|#
directive|define
name|HEAD_WRAP_COUNT
value|0xFFE00000
end_define

begin_define
define|#
directive|define
name|HEAD_WRAP_ONE
value|0x00200000
end_define

begin_define
define|#
directive|define
name|HEAD_ADDR
value|0x001FFFFC
end_define

begin_define
define|#
directive|define
name|RING_START
value|0x08
end_define

begin_define
define|#
directive|define
name|START_ADDR
value|0xFFFFF000
end_define

begin_define
define|#
directive|define
name|RING_LEN
value|0x0C
end_define

begin_define
define|#
directive|define
name|RING_NR_PAGES
value|0x001FF000
end_define

begin_define
define|#
directive|define
name|RING_REPORT_MASK
value|0x00000006
end_define

begin_define
define|#
directive|define
name|RING_REPORT_64K
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RING_REPORT_128K
value|0x00000004
end_define

begin_define
define|#
directive|define
name|RING_NO_REPORT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RING_VALID_MASK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RING_VALID
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RING_INVALID
value|0x00000000
end_define

begin_comment
comment|/* Scratch pad debug 0 reg:  */
end_comment

begin_define
define|#
directive|define
name|DPLL_FPA01_P1_POST_DIV_MASK_I830
value|0x001f0000
end_define

begin_comment
comment|/*  * The i830 generation, in LVDS mode, defines P1 as the bit number set within  * this field (only one bit may be set).  */
end_comment

begin_define
define|#
directive|define
name|DPLL_FPA01_P1_POST_DIV_MASK_I830_LVDS
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|DPLL_FPA01_P1_POST_DIV_SHIFT
value|16
end_define

begin_comment
comment|/* i830, required in DVO non-gang */
end_comment

begin_define
define|#
directive|define
name|PLL_P2_DIVIDE_BY_4
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|PLL_P1_DIVIDE_BY_TWO
value|(1<< 21)
end_define

begin_comment
comment|/* i830 */
end_comment

begin_define
define|#
directive|define
name|PLL_REF_INPUT_DREFCLK
value|(0<< 13)
end_define

begin_define
define|#
directive|define
name|PLL_REF_INPUT_TVCLKINA
value|(1<< 13)
end_define

begin_comment
comment|/* i830 */
end_comment

begin_define
define|#
directive|define
name|PLL_REF_INPUT_TVCLKINBC
value|(2<< 13)
end_define

begin_comment
comment|/* SDVO TVCLKIN */
end_comment

begin_define
define|#
directive|define
name|PLLB_REF_INPUT_SPREADSPECTRUMIN
value|(3<< 13)
end_define

begin_define
define|#
directive|define
name|PLL_REF_INPUT_MASK
value|(3<< 13)
end_define

begin_define
define|#
directive|define
name|PLL_LOAD_PULSE_PHASE_SHIFT
value|9
end_define

begin_comment
comment|/*  * Parallel to Serial Load Pulse phase selection.  * Selects the phase for the 10X DPLL clock for the PCIe  * digital display port. The range is 4 to 13; 10 or more  * is just a flip delay. The default is 6  */
end_comment

begin_define
define|#
directive|define
name|PLL_LOAD_PULSE_PHASE_MASK
value|(0xf<< PLL_LOAD_PULSE_PHASE_SHIFT)
end_define

begin_define
define|#
directive|define
name|DISPLAY_RATE_SELECT_FPA1
value|(1<< 8)
end_define

begin_comment
comment|/*  * SDVO multiplier for 945G/GM. Not used on 965.  */
end_comment

begin_define
define|#
directive|define
name|SDVO_MULTIPLIER_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|SDVO_MULTIPLIER_SHIFT_HIRES
value|4
end_define

begin_define
define|#
directive|define
name|SDVO_MULTIPLIER_SHIFT_VGA
value|0
end_define

begin_define
define|#
directive|define
name|DPLL_A_MD
value|0x0601c
end_define

begin_comment
comment|/* 965+ only */
end_comment

begin_comment
comment|/*  * UDI pixel divider, controlling how many pixels are stuffed into a packet.  *  * Value is pixels minus 1.  Must be set to 1 pixel for SDVO.  */
end_comment

begin_define
define|#
directive|define
name|DPLL_MD_UDI_DIVIDER_MASK
value|0x3f000000
end_define

begin_define
define|#
directive|define
name|DPLL_MD_UDI_DIVIDER_SHIFT
value|24
end_define

begin_comment
comment|/* UDI pixel divider for VGA, same as DPLL_MD_UDI_DIVIDER_MASK. */
end_comment

begin_define
define|#
directive|define
name|DPLL_MD_VGA_UDI_DIVIDER_MASK
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|DPLL_MD_VGA_UDI_DIVIDER_SHIFT
value|16
end_define

begin_comment
comment|/*  * SDVO/UDI pixel multiplier.  *  * SDVO requires that the bus clock rate be between 1 and 2 Ghz, and the bus  * clock rate is 10 times the DPLL clock.  At low resolution/refresh rate  * modes, the bus rate would be below the limits, so SDVO allows for stuffing  * dummy bytes in the datastream at an increased clock rate, with both sides of  * the link knowing how many bytes are fill.  *  * So, for a mode with a dotclock of 65Mhz, we would want to double the clock  * rate to 130Mhz to get a bus rate of 1.30Ghz.  The DPLL clock rate would be  * set to 130Mhz, and the SDVO multiplier set to 2x in this register and  * through an SDVO command.  *  * This register field has values of multiplication factor minus 1, with  * a maximum multiplier of 5 for SDVO.  */
end_comment

begin_define
define|#
directive|define
name|DPLL_MD_UDI_MULTIPLIER_MASK
value|0x00003f00
end_define

begin_define
define|#
directive|define
name|DPLL_MD_UDI_MULTIPLIER_SHIFT
value|8
end_define

begin_comment
comment|/*  * SDVO/UDI pixel multiplier for VGA, same as DPLL_MD_UDI_MULTIPLIER_MASK.  * This best be set to the default value (3) or the CRT won't work. No,  * I don't entirely understand what this does...  */
end_comment

begin_define
define|#
directive|define
name|DPLL_MD_VGA_UDI_MULTIPLIER_MASK
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|DPLL_MD_VGA_UDI_MULTIPLIER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DPLL_B_MD
value|0x06020
end_define

begin_comment
comment|/* 965+ only */
end_comment

begin_define
define|#
directive|define
name|FPA0
value|0x06040
end_define

begin_define
define|#
directive|define
name|FPA1
value|0x06044
end_define

begin_define
define|#
directive|define
name|FPB0
value|0x06048
end_define

begin_define
define|#
directive|define
name|FPB1
value|0x0604c
end_define

begin_define
define|#
directive|define
name|FP_N_DIV_MASK
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|FP_N_DIV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FP_M1_DIV_MASK
value|0x00003f00
end_define

begin_define
define|#
directive|define
name|FP_M1_DIV_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|FP_M2_DIV_MASK
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|FP_M2_DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DPLL_TEST
value|0x606c
end_define

begin_define
define|#
directive|define
name|DPLLB_TEST_SDVO_DIV_1
value|(0<< 22)
end_define

begin_define
define|#
directive|define
name|DPLLB_TEST_SDVO_DIV_2
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|DPLLB_TEST_SDVO_DIV_4
value|(2<< 22)
end_define

begin_define
define|#
directive|define
name|DPLLB_TEST_SDVO_DIV_MASK
value|(3<< 22)
end_define

begin_define
define|#
directive|define
name|DPLLB_TEST_N_BYPASS
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|DPLLB_TEST_M_BYPASS
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|DPLLB_INPUT_BUFFER_ENABLE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|DPLLA_TEST_N_BYPASS
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DPLLA_TEST_M_BYPASS
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DPLLA_INPUT_BUFFER_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|D_STATE
value|0x6104
end_define

begin_define
define|#
directive|define
name|CG_2D_DIS
value|0x6200
end_define

begin_define
define|#
directive|define
name|CG_3D_DIS
value|0x6204
end_define

begin_comment
comment|/*  * Palette regs  */
end_comment

begin_define
define|#
directive|define
name|PALETTE_A
value|0x0a000
end_define

begin_define
define|#
directive|define
name|PALETTE_B
value|0x0a800
end_define

begin_comment
comment|/*  * Overlay regs  */
end_comment

begin_define
define|#
directive|define
name|OVADD
value|0x30000
end_define

begin_define
define|#
directive|define
name|DOVSTA
value|0x30008
end_define

begin_define
define|#
directive|define
name|OC_BUF
value|(0x3<<20)
end_define

begin_define
define|#
directive|define
name|OGAMC5
value|0x30010
end_define

begin_define
define|#
directive|define
name|OGAMC4
value|0x30014
end_define

begin_define
define|#
directive|define
name|OGAMC3
value|0x30018
end_define

begin_define
define|#
directive|define
name|OGAMC2
value|0x3001c
end_define

begin_define
define|#
directive|define
name|OGAMC1
value|0x30020
end_define

begin_define
define|#
directive|define
name|OGAMC0
value|0x30024
end_define

begin_comment
comment|/*  * Display engine regs  */
end_comment

begin_comment
comment|/* Pipe A timing regs */
end_comment

begin_define
define|#
directive|define
name|HTOTAL_A
value|0x60000
end_define

begin_define
define|#
directive|define
name|HBLANK_A
value|0x60004
end_define

begin_define
define|#
directive|define
name|HSYNC_A
value|0x60008
end_define

begin_define
define|#
directive|define
name|VTOTAL_A
value|0x6000c
end_define

begin_define
define|#
directive|define
name|VBLANK_A
value|0x60010
end_define

begin_define
define|#
directive|define
name|VSYNC_A
value|0x60014
end_define

begin_define
define|#
directive|define
name|PIPEASRC
value|0x6001c
end_define

begin_define
define|#
directive|define
name|BCLRPAT_A
value|0x60020
end_define

begin_comment
comment|/* Pipe B timing regs */
end_comment

begin_define
define|#
directive|define
name|HTOTAL_B
value|0x61000
end_define

begin_define
define|#
directive|define
name|HBLANK_B
value|0x61004
end_define

begin_define
define|#
directive|define
name|HSYNC_B
value|0x61008
end_define

begin_define
define|#
directive|define
name|VTOTAL_B
value|0x6100c
end_define

begin_define
define|#
directive|define
name|VBLANK_B
value|0x61010
end_define

begin_define
define|#
directive|define
name|VSYNC_B
value|0x61014
end_define

begin_define
define|#
directive|define
name|PIPEBSRC
value|0x6101c
end_define

begin_define
define|#
directive|define
name|BCLRPAT_B
value|0x61020
end_define

begin_comment
comment|/* VGA port control */
end_comment

begin_define
define|#
directive|define
name|ADPA
value|0x61100
end_define

begin_define
define|#
directive|define
name|ADPA_DAC_ENABLE
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|ADPA_DAC_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|ADPA_PIPE_SELECT_MASK
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|ADPA_PIPE_A_SELECT
value|0
end_define

begin_define
define|#
directive|define
name|ADPA_PIPE_B_SELECT
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|ADPA_USE_VGA_HVPOLARITY
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|ADPA_SETS_HVPOLARITY
value|0
end_define

begin_define
define|#
directive|define
name|ADPA_VSYNC_CNTL_DISABLE
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|ADPA_VSYNC_CNTL_ENABLE
value|0
end_define

begin_define
define|#
directive|define
name|ADPA_HSYNC_CNTL_DISABLE
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|ADPA_HSYNC_CNTL_ENABLE
value|0
end_define

begin_define
define|#
directive|define
name|ADPA_VSYNC_ACTIVE_HIGH
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|ADPA_VSYNC_ACTIVE_LOW
value|0
end_define

begin_define
define|#
directive|define
name|ADPA_HSYNC_ACTIVE_HIGH
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|ADPA_HSYNC_ACTIVE_LOW
value|0
end_define

begin_define
define|#
directive|define
name|ADPA_DPMS_MASK
value|(~(3<<10))
end_define

begin_define
define|#
directive|define
name|ADPA_DPMS_ON
value|(0<<10)
end_define

begin_define
define|#
directive|define
name|ADPA_DPMS_SUSPEND
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|ADPA_DPMS_STANDBY
value|(2<<10)
end_define

begin_define
define|#
directive|define
name|ADPA_DPMS_OFF
value|(3<<10)
end_define

begin_comment
comment|/* Hotplug control (945+ only) */
end_comment

begin_define
define|#
directive|define
name|PORT_HOTPLUG_EN
value|0x61110
end_define

begin_define
define|#
directive|define
name|SDVOB_HOTPLUG_INT_EN
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|SDVOC_HOTPLUG_INT_EN
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|TV_HOTPLUG_INT_EN
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_INT_EN
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_FORCE_DETECT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|PORT_HOTPLUG_STAT
value|0x61114
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_INT_STATUS
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|TV_HOTPLUG_INT_STATUS
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_MONITOR_MASK
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_MONITOR_COLOR
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_MONITOR_MONO
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_MONITOR_NONE
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|SDVOC_HOTPLUG_INT_STATUS
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SDVOB_HOTPLUG_INT_STATUS
value|(1<< 6)
end_define

begin_comment
comment|/* SDVO port control */
end_comment

begin_define
define|#
directive|define
name|SDVOB
value|0x61140
end_define

begin_define
define|#
directive|define
name|SDVOC
value|0x61160
end_define

begin_define
define|#
directive|define
name|SDVO_ENABLE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|SDVO_PIPE_B_SELECT
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|SDVO_STALL_SELECT
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|SDVO_INTERRUPT_ENABLE
value|(1<< 26)
end_define

begin_comment
comment|/**  * 915G/GM SDVO pixel multiplier.  *  * Programmed value is multiplier - 1, up to 5x.  *  * \sa DPLL_MD_UDI_MULTIPLIER_MASK  */
end_comment

begin_define
define|#
directive|define
name|SDVO_PORT_MULTIPLY_MASK
value|(7<< 23)
end_define

begin_define
define|#
directive|define
name|SDVO_PORT_MULTIPLY_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|SDVO_PHASE_SELECT_MASK
value|(15<< 19)
end_define

begin_define
define|#
directive|define
name|SDVO_PHASE_SELECT_DEFAULT
value|(6<< 19)
end_define

begin_define
define|#
directive|define
name|SDVO_CLOCK_OUTPUT_INVERT
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|SDVOC_GANG_MODE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|SDVO_BORDER_ENABLE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SDVOB_PCIE_CONCURRENCY
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SDVO_DETECTED
value|(1<< 2)
end_define

begin_comment
comment|/* Bits to be preserved when writing */
end_comment

begin_define
define|#
directive|define
name|SDVOB_PRESERVE_MASK
value|((1<< 17) | (1<< 16) | (1<< 14) | (1<< 26))
end_define

begin_define
define|#
directive|define
name|SDVOC_PRESERVE_MASK
value|((1<< 17) | (1<< 26))
end_define

begin_comment
comment|/* DVO port control */
end_comment

begin_define
define|#
directive|define
name|DVOA
value|0x61120
end_define

begin_define
define|#
directive|define
name|DVOB
value|0x61140
end_define

begin_define
define|#
directive|define
name|DVOC
value|0x61160
end_define

begin_define
define|#
directive|define
name|DVO_ENABLE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|DVO_PIPE_B_SELECT
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|DVO_PIPE_STALL_UNUSED
value|(0<< 28)
end_define

begin_define
define|#
directive|define
name|DVO_PIPE_STALL
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|DVO_PIPE_STALL_TV
value|(2<< 28)
end_define

begin_define
define|#
directive|define
name|DVO_PIPE_STALL_MASK
value|(3<< 28)
end_define

begin_define
define|#
directive|define
name|DVO_USE_VGA_SYNC
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|DVO_DATA_ORDER_I740
value|(0<< 14)
end_define

begin_define
define|#
directive|define
name|DVO_DATA_ORDER_FP
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|DVO_VSYNC_DISABLE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|DVO_HSYNC_DISABLE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|DVO_VSYNC_TRISTATE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|DVO_HSYNC_TRISTATE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|DVO_BORDER_ENABLE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|DVO_DATA_ORDER_GBRG
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|DVO_DATA_ORDER_RGGB
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|DVO_DATA_ORDER_GBRG_ERRATA
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|DVO_DATA_ORDER_RGGB_ERRATA
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|DVO_VSYNC_ACTIVE_HIGH
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|DVO_HSYNC_ACTIVE_HIGH
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DVO_BLANK_ACTIVE_HIGH
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DVO_OUTPUT_CSTATE_PIXELS
value|(1<< 1)
end_define

begin_comment
comment|/* SDG only */
end_comment

begin_define
define|#
directive|define
name|DVO_OUTPUT_SOURCE_SIZE_PIXELS
value|(1<< 0)
end_define

begin_comment
comment|/* SDG only */
end_comment

begin_define
define|#
directive|define
name|DVO_PRESERVE_MASK
value|(0x7<<24)
end_define

begin_define
define|#
directive|define
name|DVOA_SRCDIM
value|0x61124
end_define

begin_define
define|#
directive|define
name|DVOB_SRCDIM
value|0x61144
end_define

begin_define
define|#
directive|define
name|DVOC_SRCDIM
value|0x61164
end_define

begin_define
define|#
directive|define
name|DVO_SRCDIM_HORIZONTAL_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|DVO_SRCDIM_VERTICAL_SHIFT
value|0
end_define

begin_comment
comment|/* LVDS port control */
end_comment

begin_define
define|#
directive|define
name|LVDS
value|0x61180
end_define

begin_comment
comment|/*  * Enables the LVDS port.  This bit must be set before DPLLs are enabled, as  * the DPLL semantics change when the LVDS is assigned to that pipe.  */
end_comment

begin_define
define|#
directive|define
name|LVDS_PORT_EN
value|(1<< 31)
end_define

begin_comment
comment|/* Selects pipe B for LVDS data.  Must be set on pre-965. */
end_comment

begin_define
define|#
directive|define
name|LVDS_PIPEB_SELECT
value|(1<< 30)
end_define

begin_comment
comment|/*  * Enables the A0-A2 data pairs and CLKA, containing 18 bits of color data per  * pixel.  */
end_comment

begin_define
define|#
directive|define
name|LVDS_A0A2_CLKA_POWER_MASK
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|LVDS_A0A2_CLKA_POWER_DOWN
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|LVDS_A0A2_CLKA_POWER_UP
value|(3<< 8)
end_define

begin_comment
comment|/*  * Controls the A3 data pair, which contains the additional LSBs for 24 bit  * mode.  Only enabled if LVDS_A0A2_CLKA_POWER_UP also indicates it should be  * on.  */
end_comment

begin_define
define|#
directive|define
name|LVDS_A3_POWER_MASK
value|(3<< 6)
end_define

begin_define
define|#
directive|define
name|LVDS_A3_POWER_DOWN
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|LVDS_A3_POWER_UP
value|(3<< 6)
end_define

begin_comment
comment|/*  * Controls the CLKB pair.  This should only be set when LVDS_B0B3_POWER_UP  * is set.  */
end_comment

begin_define
define|#
directive|define
name|LVDS_CLKB_POWER_MASK
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|LVDS_CLKB_POWER_DOWN
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|LVDS_CLKB_POWER_UP
value|(3<< 4)
end_define

begin_comment
comment|/*  * Controls the B0-B3 data pairs.  This must be set to match the DPLL p2  * setting for whether we are in dual-channel mode.  The B3 pair will  * additionally only be powered up when LVDS_A3_POWER_UP is set.  */
end_comment

begin_define
define|#
directive|define
name|LVDS_B0B3_POWER_MASK
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|LVDS_B0B3_POWER_DOWN
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|LVDS_B0B3_POWER_UP
value|(3<< 2)
end_define

begin_comment
comment|/* Panel power sequencing */
end_comment

begin_define
define|#
directive|define
name|PP_STATUS
value|0x61200
end_define

begin_define
define|#
directive|define
name|PP_ON
value|(1<< 31)
end_define

begin_comment
comment|/*  * Indicates that all dependencies of the panel are on:  *  * - PLL enabled  * - pipe enabled  * - LVDS/DVOB/DVOC on  */
end_comment

begin_define
define|#
directive|define
name|PP_READY
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|PP_SEQUENCE_NONE
value|(0<< 28)
end_define

begin_define
define|#
directive|define
name|PP_SEQUENCE_ON
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|PP_SEQUENCE_OFF
value|(2<< 28)
end_define

begin_define
define|#
directive|define
name|PP_SEQUENCE_MASK
value|0x30000000
end_define

begin_define
define|#
directive|define
name|PP_CONTROL
value|0x61204
end_define

begin_define
define|#
directive|define
name|POWER_TARGET_ON
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PP_ON_DELAYS
value|0x61208
end_define

begin_define
define|#
directive|define
name|PP_OFF_DELAYS
value|0x6120c
end_define

begin_define
define|#
directive|define
name|PP_DIVISOR
value|0x61210
end_define

begin_comment
comment|/* Panel fitting */
end_comment

begin_define
define|#
directive|define
name|PFIT_CONTROL
value|0x61230
end_define

begin_define
define|#
directive|define
name|PFIT_ENABLE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|PFIT_PIPE_MASK
value|(3<< 29)
end_define

begin_define
define|#
directive|define
name|PFIT_PIPE_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|VERT_INTERP_DISABLE
value|(0<< 10)
end_define

begin_define
define|#
directive|define
name|VERT_INTERP_BILINEAR
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|VERT_INTERP_MASK
value|(3<< 10)
end_define

begin_define
define|#
directive|define
name|VERT_AUTO_SCALE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|HORIZ_INTERP_DISABLE
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|HORIZ_INTERP_BILINEAR
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|HORIZ_INTERP_MASK
value|(3<< 6)
end_define

begin_define
define|#
directive|define
name|HORIZ_AUTO_SCALE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|PANEL_8TO6_DITHER_ENABLE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|PFIT_PGM_RATIOS
value|0x61234
end_define

begin_define
define|#
directive|define
name|PFIT_VERT_SCALE_MASK
value|0xfff00000
end_define

begin_define
define|#
directive|define
name|PFIT_HORIZ_SCALE_MASK
value|0x0000fff0
end_define

begin_define
define|#
directive|define
name|PFIT_AUTO_RATIOS
value|0x61238
end_define

begin_comment
comment|/* Backlight control */
end_comment

begin_define
define|#
directive|define
name|BLC_PWM_CTL
value|0x61254
end_define

begin_define
define|#
directive|define
name|BACKLIGHT_MODULATION_FREQ_SHIFT
value|(17)
end_define

begin_define
define|#
directive|define
name|BLC_PWM_CTL2
value|0x61250
end_define

begin_comment
comment|/* 965+ only */
end_comment

begin_comment
comment|/*  * This is the most significant 15 bits of the number of backlight cycles in a  * complete cycle of the modulated backlight control.  *  * The actual value is this field multiplied by two.  */
end_comment

begin_define
define|#
directive|define
name|BACKLIGHT_MODULATION_FREQ_MASK
value|(0x7fff<< 17)
end_define

begin_define
define|#
directive|define
name|BLM_LEGACY_MODE
value|(1<< 16)
end_define

begin_comment
comment|/*  * This is the number of cycles out of the backlight modulation cycle for which  * the backlight is on.  *  * This field must be no greater than the number of cycles in the complete  * backlight modulation cycle.  */
end_comment

begin_define
define|#
directive|define
name|BACKLIGHT_DUTY_CYCLE_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|BACKLIGHT_DUTY_CYCLE_MASK
value|(0xffff)
end_define

begin_comment
comment|/* TV port control */
end_comment

begin_define
define|#
directive|define
name|TV_CTL
value|0x68000
end_define

begin_comment
comment|/** Enables the TV encoder */
end_comment

begin_define
define|#
directive|define
name|TV_ENC_ENABLE
value|(1<< 31)
end_define

begin_comment
comment|/** Sources the TV encoder input from pipe B instead of A. */
end_comment

begin_define
define|#
directive|define
name|TV_ENC_PIPEB_SELECT
value|(1<< 30)
end_define

begin_comment
comment|/** Outputs composite video (DAC A only) */
end_comment

begin_define
define|#
directive|define
name|TV_ENC_OUTPUT_COMPOSITE
value|(0<< 28)
end_define

begin_comment
comment|/** Outputs SVideo video (DAC B/C) */
end_comment

begin_define
define|#
directive|define
name|TV_ENC_OUTPUT_SVIDEO
value|(1<< 28)
end_define

begin_comment
comment|/** Outputs Component video (DAC A/B/C) */
end_comment

begin_define
define|#
directive|define
name|TV_ENC_OUTPUT_COMPONENT
value|(2<< 28)
end_define

begin_comment
comment|/** Outputs Composite and SVideo (DAC A/B/C) */
end_comment

begin_define
define|#
directive|define
name|TV_ENC_OUTPUT_SVIDEO_COMPOSITE
value|(3<< 28)
end_define

begin_define
define|#
directive|define
name|TV_TRILEVEL_SYNC
value|(1<< 21)
end_define

begin_comment
comment|/** Enables slow sync generation (945GM only) */
end_comment

begin_define
define|#
directive|define
name|TV_SLOW_SYNC
value|(1<< 20)
end_define

begin_comment
comment|/** Selects 4x oversampling for 480i and 576p */
end_comment

begin_define
define|#
directive|define
name|TV_OVERSAMPLE_4X
value|(0<< 18)
end_define

begin_comment
comment|/** Selects 2x oversampling for 720p and 1080i */
end_comment

begin_define
define|#
directive|define
name|TV_OVERSAMPLE_2X
value|(1<< 18)
end_define

begin_comment
comment|/** Selects no oversampling for 1080p */
end_comment

begin_define
define|#
directive|define
name|TV_OVERSAMPLE_NONE
value|(2<< 18)
end_define

begin_comment
comment|/** Selects 8x oversampling */
end_comment

begin_define
define|#
directive|define
name|TV_OVERSAMPLE_8X
value|(3<< 18)
end_define

begin_comment
comment|/** Selects progressive mode rather than interlaced */
end_comment

begin_define
define|#
directive|define
name|TV_PROGRESSIVE
value|(1<< 17)
end_define

begin_comment
comment|/** Sets the colorburst to PAL mode.  Required for non-M PAL modes. */
end_comment

begin_define
define|#
directive|define
name|TV_PAL_BURST
value|(1<< 16)
end_define

begin_comment
comment|/** Field for setting delay of Y compared to C */
end_comment

begin_define
define|#
directive|define
name|TV_YC_SKEW_MASK
value|(7<< 12)
end_define

begin_comment
comment|/** Enables a fix for 480p/576p standard definition modes on the 915GM only */
end_comment

begin_define
define|#
directive|define
name|TV_ENC_SDP_FIX
value|(1<< 11)
end_define

begin_comment
comment|/**  * Enables a fix for the 915GM only.  *  * Not sure what it does.  */
end_comment

begin_define
define|#
directive|define
name|TV_ENC_C0_FIX
value|(1<< 10)
end_define

begin_comment
comment|/** Bits that must be preserved by software */
end_comment

begin_define
define|#
directive|define
name|TV_CTL_SAVE
value|((3<< 8) | (3<< 6))
end_define

begin_define
define|#
directive|define
name|TV_FUSE_STATE_MASK
value|(3<< 4)
end_define

begin_comment
comment|/** Read-only state that reports all features enabled */
end_comment

begin_define
define|#
directive|define
name|TV_FUSE_STATE_ENABLED
value|(0<< 4)
end_define

begin_comment
comment|/** Read-only state that reports that Macrovision is disabled in hardware*/
end_comment

begin_define
define|#
directive|define
name|TV_FUSE_STATE_NO_MACROVISION
value|(1<< 4)
end_define

begin_comment
comment|/** Read-only state that reports that TV-out is disabled in hardware. */
end_comment

begin_define
define|#
directive|define
name|TV_FUSE_STATE_DISABLED
value|(2<< 4)
end_define

begin_comment
comment|/** Normal operation */
end_comment

begin_define
define|#
directive|define
name|TV_TEST_MODE_NORMAL
value|(0<< 0)
end_define

begin_comment
comment|/** Encoder test pattern 1 - combo pattern */
end_comment

begin_define
define|#
directive|define
name|TV_TEST_MODE_PATTERN_1
value|(1<< 0)
end_define

begin_comment
comment|/** Encoder test pattern 2 - full screen vertical 75% color bars */
end_comment

begin_define
define|#
directive|define
name|TV_TEST_MODE_PATTERN_2
value|(2<< 0)
end_define

begin_comment
comment|/** Encoder test pattern 3 - full screen horizontal 75% color bars */
end_comment

begin_define
define|#
directive|define
name|TV_TEST_MODE_PATTERN_3
value|(3<< 0)
end_define

begin_comment
comment|/** Encoder test pattern 4 - random noise */
end_comment

begin_define
define|#
directive|define
name|TV_TEST_MODE_PATTERN_4
value|(4<< 0)
end_define

begin_comment
comment|/** Encoder test pattern 5 - linear color ramps */
end_comment

begin_define
define|#
directive|define
name|TV_TEST_MODE_PATTERN_5
value|(5<< 0)
end_define

begin_comment
comment|/**  * This test mode forces the DACs to 50% of full output.  *  * This is used for load detection in combination with TVDAC_SENSE_MASK  */
end_comment

begin_define
define|#
directive|define
name|TV_TEST_MODE_MONITOR_DETECT
value|(7<< 0)
end_define

begin_define
define|#
directive|define
name|TV_TEST_MODE_MASK
value|(7<< 0)
end_define

begin_define
define|#
directive|define
name|TV_DAC
value|0x68004
end_define

begin_comment
comment|/**  * Reports that DAC state change logic has reported change (RO).  *  * This gets cleared when TV_DAC_STATE_EN is cleared */
end_comment

begin_define
define|#
directive|define
name|TVDAC_STATE_CHG
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|TVDAC_SENSE_MASK
value|(7<< 28)
end_define

begin_comment
comment|/** Reports that DAC A voltage is above the detect threshold */
end_comment

begin_define
define|#
directive|define
name|TVDAC_A_SENSE
value|(1<< 30)
end_define

begin_comment
comment|/** Reports that DAC B voltage is above the detect threshold */
end_comment

begin_define
define|#
directive|define
name|TVDAC_B_SENSE
value|(1<< 29)
end_define

begin_comment
comment|/** Reports that DAC C voltage is above the detect threshold */
end_comment

begin_define
define|#
directive|define
name|TVDAC_C_SENSE
value|(1<< 28)
end_define

begin_comment
comment|/**  * Enables DAC state detection logic, for load-based TV detection.  *  * The PLL of the chosen pipe (in TV_CTL) must be running, and the encoder set  * to off, for load detection to work.  */
end_comment

begin_define
define|#
directive|define
name|TVDAC_STATE_CHG_EN
value|(1<< 27)
end_define

begin_comment
comment|/** Sets the DAC A sense value to high */
end_comment

begin_define
define|#
directive|define
name|TVDAC_A_SENSE_CTL
value|(1<< 26)
end_define

begin_comment
comment|/** Sets the DAC B sense value to high */
end_comment

begin_define
define|#
directive|define
name|TVDAC_B_SENSE_CTL
value|(1<< 25)
end_define

begin_comment
comment|/** Sets the DAC C sense value to high */
end_comment

begin_define
define|#
directive|define
name|TVDAC_C_SENSE_CTL
value|(1<< 24)
end_define

begin_comment
comment|/** Overrides the ENC_ENABLE and DAC voltage levels */
end_comment

begin_define
define|#
directive|define
name|DAC_CTL_OVERRIDE
value|(1<< 7)
end_define

begin_comment
comment|/** Sets the slew rate.  Must be preserved in software */
end_comment

begin_define
define|#
directive|define
name|ENC_TVDAC_SLEW_FAST
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|DAC_A_1_3_V
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|DAC_A_1_1_V
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|DAC_A_0_7_V
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|DAC_A_OFF
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|DAC_B_1_3_V
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|DAC_B_1_1_V
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DAC_B_0_7_V
value|(2<< 2)
end_define

begin_define
define|#
directive|define
name|DAC_B_OFF
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|DAC_C_1_3_V
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|DAC_C_1_1_V
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DAC_C_0_7_V
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|DAC_C_OFF
value|(3<< 0)
end_define

begin_comment
comment|/**  * CSC coefficients are stored in a floating point format with 9 bits of  * mantissa and 2 or 3 bits of exponent.  The exponent is represented as 2**-n,  * where 2-bit exponents are unsigned n, and 3-bit exponents are signed n with  * -1 (0x3) being the only legal negative value.  */
end_comment

begin_define
define|#
directive|define
name|TV_CSC_Y
value|0x68010
end_define

begin_define
define|#
directive|define
name|TV_RY_MASK
value|0x07ff0000
end_define

begin_define
define|#
directive|define
name|TV_RY_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TV_GY_MASK
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|TV_GY_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_CSC_Y2
value|0x68014
end_define

begin_define
define|#
directive|define
name|TV_BY_MASK
value|0x07ff0000
end_define

begin_define
define|#
directive|define
name|TV_BY_SHIFT
value|16
end_define

begin_comment
comment|/**  * Y attenuation for component video.  *  * Stored in 1.9 fixed point.  */
end_comment

begin_define
define|#
directive|define
name|TV_AY_MASK
value|0x000003ff
end_define

begin_define
define|#
directive|define
name|TV_AY_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_CSC_U
value|0x68018
end_define

begin_define
define|#
directive|define
name|TV_RU_MASK
value|0x07ff0000
end_define

begin_define
define|#
directive|define
name|TV_RU_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TV_GU_MASK
value|0x000007ff
end_define

begin_define
define|#
directive|define
name|TV_GU_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_CSC_U2
value|0x6801c
end_define

begin_define
define|#
directive|define
name|TV_BU_MASK
value|0x07ff0000
end_define

begin_define
define|#
directive|define
name|TV_BU_SHIFT
value|16
end_define

begin_comment
comment|/**  * U attenuation for component video.  *  * Stored in 1.9 fixed point.  */
end_comment

begin_define
define|#
directive|define
name|TV_AU_MASK
value|0x000003ff
end_define

begin_define
define|#
directive|define
name|TV_AU_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_CSC_V
value|0x68020
end_define

begin_define
define|#
directive|define
name|TV_RV_MASK
value|0x0fff0000
end_define

begin_define
define|#
directive|define
name|TV_RV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TV_GV_MASK
value|0x000007ff
end_define

begin_define
define|#
directive|define
name|TV_GV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_CSC_V2
value|0x68024
end_define

begin_define
define|#
directive|define
name|TV_BV_MASK
value|0x07ff0000
end_define

begin_define
define|#
directive|define
name|TV_BV_SHIFT
value|16
end_define

begin_comment
comment|/**  * V attenuation for component video.  *  * Stored in 1.9 fixed point.  */
end_comment

begin_define
define|#
directive|define
name|TV_AV_MASK
value|0x000007ff
end_define

begin_define
define|#
directive|define
name|TV_AV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_CLR_KNOBS
value|0x68028
end_define

begin_comment
comment|/** 2s-complement brightness adjustment */
end_comment

begin_define
define|#
directive|define
name|TV_BRIGHTNESS_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|TV_BRIGHTNESS_SHIFT
value|24
end_define

begin_comment
comment|/** Contrast adjustment, as a 2.6 unsigned floating point number */
end_comment

begin_define
define|#
directive|define
name|TV_CONTRAST_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|TV_CONTRAST_SHIFT
value|16
end_define

begin_comment
comment|/** Saturation adjustment, as a 2.6 unsigned floating point number */
end_comment

begin_define
define|#
directive|define
name|TV_SATURATION_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|TV_SATURATION_SHIFT
value|8
end_define

begin_comment
comment|/** Hue adjustment, as an integer phase angle in degrees */
end_comment

begin_define
define|#
directive|define
name|TV_HUE_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|TV_HUE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_CLR_LEVEL
value|0x6802c
end_define

begin_comment
comment|/** Controls the DAC level for black */
end_comment

begin_define
define|#
directive|define
name|TV_BLACK_LEVEL_MASK
value|0x01ff0000
end_define

begin_define
define|#
directive|define
name|TV_BLACK_LEVEL_SHIFT
value|16
end_define

begin_comment
comment|/** Controls the DAC level for blanking */
end_comment

begin_define
define|#
directive|define
name|TV_BLANK_LEVEL_MASK
value|0x000001ff
end_define

begin_define
define|#
directive|define
name|TV_BLANK_LEVEL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_H_CTL_1
value|0x68030
end_define

begin_comment
comment|/** Number of pixels in the hsync. */
end_comment

begin_define
define|#
directive|define
name|TV_HSYNC_END_MASK
value|0x1fff0000
end_define

begin_define
define|#
directive|define
name|TV_HSYNC_END_SHIFT
value|16
end_define

begin_comment
comment|/** Total number of pixels minus one in the line (display and blanking). */
end_comment

begin_define
define|#
directive|define
name|TV_HTOTAL_MASK
value|0x00001fff
end_define

begin_define
define|#
directive|define
name|TV_HTOTAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_H_CTL_2
value|0x68034
end_define

begin_comment
comment|/** Enables the colorburst (needed for non-component color) */
end_comment

begin_define
define|#
directive|define
name|TV_BURST_ENA
value|(1<< 31)
end_define

begin_comment
comment|/** Offset of the colorburst from the start of hsync, in pixels minus one. */
end_comment

begin_define
define|#
directive|define
name|TV_HBURST_START_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TV_HBURST_START_MASK
value|0x1fff0000
end_define

begin_comment
comment|/** Length of the colorburst */
end_comment

begin_define
define|#
directive|define
name|TV_HBURST_LEN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_HBURST_LEN_MASK
value|0x0001fff
end_define

begin_define
define|#
directive|define
name|TV_H_CTL_3
value|0x68038
end_define

begin_comment
comment|/** End of hblank, measured in pixels minus one from start of hsync */
end_comment

begin_define
define|#
directive|define
name|TV_HBLANK_END_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TV_HBLANK_END_MASK
value|0x1fff0000
end_define

begin_comment
comment|/** Start of hblank, measured in pixels minus one from start of hsync */
end_comment

begin_define
define|#
directive|define
name|TV_HBLANK_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_HBLANK_START_MASK
value|0x0001fff
end_define

begin_define
define|#
directive|define
name|TV_V_CTL_1
value|0x6803c
end_define

begin_comment
comment|/** XXX */
end_comment

begin_define
define|#
directive|define
name|TV_NBR_END_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TV_NBR_END_MASK
value|0x07ff0000
end_define

begin_comment
comment|/** XXX */
end_comment

begin_define
define|#
directive|define
name|TV_VI_END_F1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|TV_VI_END_F1_MASK
value|0x00003f00
end_define

begin_comment
comment|/** XXX */
end_comment

begin_define
define|#
directive|define
name|TV_VI_END_F2_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_VI_END_F2_MASK
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|TV_V_CTL_2
value|0x68040
end_define

begin_comment
comment|/** Length of vsync, in half lines */
end_comment

begin_define
define|#
directive|define
name|TV_VSYNC_LEN_MASK
value|0x07ff0000
end_define

begin_define
define|#
directive|define
name|TV_VSYNC_LEN_SHIFT
value|16
end_define

begin_comment
comment|/** Offset of the start of vsync in field 1, measured in one less than the  * number of half lines.  */
end_comment

begin_define
define|#
directive|define
name|TV_VSYNC_START_F1_MASK
value|0x00007f00
end_define

begin_define
define|#
directive|define
name|TV_VSYNC_START_F1_SHIFT
value|8
end_define

begin_comment
comment|/**  * Offset of the start of vsync in field 2, measured in one less than the  * number of half lines.  */
end_comment

begin_define
define|#
directive|define
name|TV_VSYNC_START_F2_MASK
value|0x0000007f
end_define

begin_define
define|#
directive|define
name|TV_VSYNC_START_F2_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_V_CTL_3
value|0x68044
end_define

begin_comment
comment|/** Enables generation of the equalization signal */
end_comment

begin_define
define|#
directive|define
name|TV_EQUAL_ENA
value|(1<< 31)
end_define

begin_comment
comment|/** Length of vsync, in half lines */
end_comment

begin_define
define|#
directive|define
name|TV_VEQ_LEN_MASK
value|0x007f0000
end_define

begin_define
define|#
directive|define
name|TV_VEQ_LEN_SHIFT
value|16
end_define

begin_comment
comment|/** Offset of the start of equalization in field 1, measured in one less than  * the number of half lines.  */
end_comment

begin_define
define|#
directive|define
name|TV_VEQ_START_F1_MASK
value|0x0007f00
end_define

begin_define
define|#
directive|define
name|TV_VEQ_START_F1_SHIFT
value|8
end_define

begin_comment
comment|/**  * Offset of the start of equalization in field 2, measured in one less than  * the number of half lines.  */
end_comment

begin_define
define|#
directive|define
name|TV_VEQ_START_F2_MASK
value|0x000007f
end_define

begin_define
define|#
directive|define
name|TV_VEQ_START_F2_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_V_CTL_4
value|0x68048
end_define

begin_comment
comment|/**  * Offset to start of vertical colorburst, measured in one less than the  * number of lines from vertical start.  */
end_comment

begin_define
define|#
directive|define
name|TV_VBURST_START_F1_MASK
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|TV_VBURST_START_F1_SHIFT
value|16
end_define

begin_comment
comment|/**  * Offset to the end of vertical colorburst, measured in one less than the  * number of lines from the start of NBR.  */
end_comment

begin_define
define|#
directive|define
name|TV_VBURST_END_F1_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|TV_VBURST_END_F1_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_V_CTL_5
value|0x6804c
end_define

begin_comment
comment|/**  * Offset to start of vertical colorburst, measured in one less than the  * number of lines from vertical start.  */
end_comment

begin_define
define|#
directive|define
name|TV_VBURST_START_F2_MASK
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|TV_VBURST_START_F2_SHIFT
value|16
end_define

begin_comment
comment|/**  * Offset to the end of vertical colorburst, measured in one less than the  * number of lines from the start of NBR.  */
end_comment

begin_define
define|#
directive|define
name|TV_VBURST_END_F2_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|TV_VBURST_END_F2_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_V_CTL_6
value|0x68050
end_define

begin_comment
comment|/**  * Offset to start of vertical colorburst, measured in one less than the  * number of lines from vertical start.  */
end_comment

begin_define
define|#
directive|define
name|TV_VBURST_START_F3_MASK
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|TV_VBURST_START_F3_SHIFT
value|16
end_define

begin_comment
comment|/**  * Offset to the end of vertical colorburst, measured in one less than the  * number of lines from the start of NBR.  */
end_comment

begin_define
define|#
directive|define
name|TV_VBURST_END_F3_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|TV_VBURST_END_F3_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_V_CTL_7
value|0x68054
end_define

begin_comment
comment|/**  * Offset to start of vertical colorburst, measured in one less than the  * number of lines from vertical start.  */
end_comment

begin_define
define|#
directive|define
name|TV_VBURST_START_F4_MASK
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|TV_VBURST_START_F4_SHIFT
value|16
end_define

begin_comment
comment|/**  * Offset to the end of vertical colorburst, measured in one less than the  * number of lines from the start of NBR.  */
end_comment

begin_define
define|#
directive|define
name|TV_VBURST_END_F4_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|TV_VBURST_END_F4_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_SC_CTL_1
value|0x68060
end_define

begin_comment
comment|/** Turns on the first subcarrier phase generation DDA */
end_comment

begin_define
define|#
directive|define
name|TV_SC_DDA1_EN
value|(1<< 31)
end_define

begin_comment
comment|/** Turns on the first subcarrier phase generation DDA */
end_comment

begin_define
define|#
directive|define
name|TV_SC_DDA2_EN
value|(1<< 30)
end_define

begin_comment
comment|/** Turns on the first subcarrier phase generation DDA */
end_comment

begin_define
define|#
directive|define
name|TV_SC_DDA3_EN
value|(1<< 29)
end_define

begin_comment
comment|/** Sets the subcarrier DDA to reset frequency every other field */
end_comment

begin_define
define|#
directive|define
name|TV_SC_RESET_EVERY_2
value|(0<< 24)
end_define

begin_comment
comment|/** Sets the subcarrier DDA to reset frequency every fourth field */
end_comment

begin_define
define|#
directive|define
name|TV_SC_RESET_EVERY_4
value|(1<< 24)
end_define

begin_comment
comment|/** Sets the subcarrier DDA to reset frequency every eighth field */
end_comment

begin_define
define|#
directive|define
name|TV_SC_RESET_EVERY_8
value|(2<< 24)
end_define

begin_comment
comment|/** Sets the subcarrier DDA to never reset the frequency */
end_comment

begin_define
define|#
directive|define
name|TV_SC_RESET_NEVER
value|(3<< 24)
end_define

begin_comment
comment|/** Sets the peak amplitude of the colorburst.*/
end_comment

begin_define
define|#
directive|define
name|TV_BURST_LEVEL_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|TV_BURST_LEVEL_SHIFT
value|16
end_define

begin_comment
comment|/** Sets the increment of the first subcarrier phase generation DDA */
end_comment

begin_define
define|#
directive|define
name|TV_SCDDA1_INC_MASK
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|TV_SCDDA1_INC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_SC_CTL_2
value|0x68064
end_define

begin_comment
comment|/** Sets the rollover for the second subcarrier phase generation DDA */
end_comment

begin_define
define|#
directive|define
name|TV_SCDDA2_SIZE_MASK
value|0x7fff0000
end_define

begin_define
define|#
directive|define
name|TV_SCDDA2_SIZE_SHIFT
value|16
end_define

begin_comment
comment|/** Sets the increent of the second subcarrier phase generation DDA */
end_comment

begin_define
define|#
directive|define
name|TV_SCDDA2_INC_MASK
value|0x00007fff
end_define

begin_define
define|#
directive|define
name|TV_SCDDA2_INC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_SC_CTL_3
value|0x68068
end_define

begin_comment
comment|/** Sets the rollover for the third subcarrier phase generation DDA */
end_comment

begin_define
define|#
directive|define
name|TV_SCDDA3_SIZE_MASK
value|0x7fff0000
end_define

begin_define
define|#
directive|define
name|TV_SCDDA3_SIZE_SHIFT
value|16
end_define

begin_comment
comment|/** Sets the increent of the third subcarrier phase generation DDA */
end_comment

begin_define
define|#
directive|define
name|TV_SCDDA3_INC_MASK
value|0x00007fff
end_define

begin_define
define|#
directive|define
name|TV_SCDDA3_INC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_WIN_POS
value|0x68070
end_define

begin_comment
comment|/** X coordinate of the display from the start of horizontal active */
end_comment

begin_define
define|#
directive|define
name|TV_XPOS_MASK
value|0x1fff0000
end_define

begin_define
define|#
directive|define
name|TV_XPOS_SHIFT
value|16
end_define

begin_comment
comment|/** Y coordinate of the display from the start of vertical active (NBR) */
end_comment

begin_define
define|#
directive|define
name|TV_YPOS_MASK
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|TV_YPOS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_WIN_SIZE
value|0x68074
end_define

begin_comment
comment|/** Horizontal size of the display window, measured in pixels*/
end_comment

begin_define
define|#
directive|define
name|TV_XSIZE_MASK
value|0x1fff0000
end_define

begin_define
define|#
directive|define
name|TV_XSIZE_SHIFT
value|16
end_define

begin_comment
comment|/**  * Vertical size of the display window, measured in pixels.  *  * Must be even for interlaced modes.  */
end_comment

begin_define
define|#
directive|define
name|TV_YSIZE_MASK
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|TV_YSIZE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_FILTER_CTL_1
value|0x68080
end_define

begin_comment
comment|/**  * Enables automatic scaling calculation.  *  * If set, the rest of the registers are ignored, and the calculated values can  * be read back from the register.  */
end_comment

begin_define
define|#
directive|define
name|TV_AUTO_SCALE
value|(1<< 31)
end_define

begin_comment
comment|/**  * Disables the vertical filter.  *  * This is required on modes more than 1024 pixels wide */
end_comment

begin_define
define|#
directive|define
name|TV_V_FILTER_BYPASS
value|(1<< 29)
end_define

begin_comment
comment|/** Enables adaptive vertical filtering */
end_comment

begin_define
define|#
directive|define
name|TV_VADAPT
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|TV_VADAPT_MODE_MASK
value|(3<< 26)
end_define

begin_comment
comment|/** Selects the least adaptive vertical filtering mode */
end_comment

begin_define
define|#
directive|define
name|TV_VADAPT_MODE_LEAST
value|(0<< 26)
end_define

begin_comment
comment|/** Selects the moderately adaptive vertical filtering mode */
end_comment

begin_define
define|#
directive|define
name|TV_VADAPT_MODE_MODERATE
value|(1<< 26)
end_define

begin_comment
comment|/** Selects the most adaptive vertical filtering mode */
end_comment

begin_define
define|#
directive|define
name|TV_VADAPT_MODE_MOST
value|(3<< 26)
end_define

begin_comment
comment|/**  * Sets the horizontal scaling factor.  *  * This should be the fractional part of the horizontal scaling factor divided  * by the oversampling rate.  TV_HSCALE should be less than 1, and set to:  *  * (src width - 1) / ((oversample * dest width) - 1)  */
end_comment

begin_define
define|#
directive|define
name|TV_HSCALE_FRAC_MASK
value|0x00003fff
end_define

begin_define
define|#
directive|define
name|TV_HSCALE_FRAC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_FILTER_CTL_2
value|0x68084
end_define

begin_comment
comment|/**  * Sets the integer part of the 3.15 fixed-point vertical scaling factor.  *  * TV_VSCALE should be (src height - 1) / ((interlace * dest height) - 1)  */
end_comment

begin_define
define|#
directive|define
name|TV_VSCALE_INT_MASK
value|0x00038000
end_define

begin_define
define|#
directive|define
name|TV_VSCALE_INT_SHIFT
value|15
end_define

begin_comment
comment|/**  * Sets the fractional part of the 3.15 fixed-point vertical scaling factor.  *  * \sa TV_VSCALE_INT_MASK  */
end_comment

begin_define
define|#
directive|define
name|TV_VSCALE_FRAC_MASK
value|0x00007fff
end_define

begin_define
define|#
directive|define
name|TV_VSCALE_FRAC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_FILTER_CTL_3
value|0x68088
end_define

begin_comment
comment|/**  * Sets the integer part of the 3.15 fixed-point vertical scaling factor.  *  * TV_VSCALE should be (src height - 1) / (1/4 * (dest height - 1))  *  * For progressive modes, TV_VSCALE_IP_INT should be set to zeroes.  */
end_comment

begin_define
define|#
directive|define
name|TV_VSCALE_IP_INT_MASK
value|0x00038000
end_define

begin_define
define|#
directive|define
name|TV_VSCALE_IP_INT_SHIFT
value|15
end_define

begin_comment
comment|/**  * Sets the fractional part of the 3.15 fixed-point vertical scaling factor.  *  * For progressive modes, TV_VSCALE_IP_INT should be set to zeroes.  *  * \sa TV_VSCALE_IP_INT_MASK  */
end_comment

begin_define
define|#
directive|define
name|TV_VSCALE_IP_FRAC_MASK
value|0x00007fff
end_define

begin_define
define|#
directive|define
name|TV_VSCALE_IP_FRAC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_CC_CONTROL
value|0x68090
end_define

begin_define
define|#
directive|define
name|TV_CC_ENABLE
value|(1<< 31)
end_define

begin_comment
comment|/**  * Specifies which field to send the CC data in.  *  * CC data is usually sent in field 0.  */
end_comment

begin_define
define|#
directive|define
name|TV_CC_FID_MASK
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|TV_CC_FID_SHIFT
value|27
end_define

begin_comment
comment|/** Sets the horizontal position of the CC data.  Usually 135. */
end_comment

begin_define
define|#
directive|define
name|TV_CC_HOFF_MASK
value|0x03ff0000
end_define

begin_define
define|#
directive|define
name|TV_CC_HOFF_SHIFT
value|16
end_define

begin_comment
comment|/** Sets the vertical position of the CC data.  Usually 21 */
end_comment

begin_define
define|#
directive|define
name|TV_CC_LINE_MASK
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|TV_CC_LINE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_CC_DATA
value|0x68094
end_define

begin_define
define|#
directive|define
name|TV_CC_RDY
value|(1<< 31)
end_define

begin_comment
comment|/** Second word of CC data to be transmitted. */
end_comment

begin_define
define|#
directive|define
name|TV_CC_DATA_2_MASK
value|0x007f0000
end_define

begin_define
define|#
directive|define
name|TV_CC_DATA_2_SHIFT
value|16
end_define

begin_comment
comment|/** First word of CC data to be transmitted. */
end_comment

begin_define
define|#
directive|define
name|TV_CC_DATA_1_MASK
value|0x0000007f
end_define

begin_define
define|#
directive|define
name|TV_CC_DATA_1_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_H_LUMA_0
value|0x68100
end_define

begin_define
define|#
directive|define
name|TV_H_LUMA_59
value|0x681ec
end_define

begin_define
define|#
directive|define
name|TV_H_CHROMA_0
value|0x68200
end_define

begin_define
define|#
directive|define
name|TV_H_CHROMA_59
value|0x682ec
end_define

begin_define
define|#
directive|define
name|TV_V_LUMA_0
value|0x68300
end_define

begin_define
define|#
directive|define
name|TV_V_LUMA_42
value|0x683a8
end_define

begin_define
define|#
directive|define
name|TV_V_CHROMA_0
value|0x68400
end_define

begin_define
define|#
directive|define
name|TV_V_CHROMA_42
value|0x684a8
end_define

begin_comment
comment|/* Display& cursor control */
end_comment

begin_comment
comment|/* Pipe A */
end_comment

begin_define
define|#
directive|define
name|PIPEADSL
value|0x70000
end_define

begin_define
define|#
directive|define
name|PIPEACONF
value|0x70008
end_define

begin_define
define|#
directive|define
name|PIPEACONF_ENABLE
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|PIPEACONF_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|PIPEACONF_DOUBLE_WIDE
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|I965_PIPECONF_ACTIVE
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|PIPEACONF_SINGLE_WIDE
value|0
end_define

begin_define
define|#
directive|define
name|PIPEACONF_PIPE_UNLOCKED
value|0
end_define

begin_define
define|#
directive|define
name|PIPEACONF_PIPE_LOCKED
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|PIPEACONF_PALETTE
value|0
end_define

begin_define
define|#
directive|define
name|PIPEACONF_GAMMA
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|PIPECONF_FORCE_BORDER
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|PIPECONF_PROGRESSIVE
value|(0<< 21)
end_define

begin_define
define|#
directive|define
name|PIPECONF_INTERLACE_W_FIELD_INDICATION
value|(6<< 21)
end_define

begin_define
define|#
directive|define
name|PIPECONF_INTERLACE_FIELD_0_ONLY
value|(7<< 21)
end_define

begin_define
define|#
directive|define
name|PIPEASTAT
value|0x70024
end_define

begin_define
define|#
directive|define
name|PIPE_FIFO_UNDERRUN_STATUS
value|(1UL<<31)
end_define

begin_define
define|#
directive|define
name|PIPE_CRC_ERROR_ENABLE
value|(1UL<<29)
end_define

begin_define
define|#
directive|define
name|PIPE_CRC_DONE_ENABLE
value|(1UL<<28)
end_define

begin_define
define|#
directive|define
name|PIPE_GMBUS_EVENT_ENABLE
value|(1UL<<27)
end_define

begin_define
define|#
directive|define
name|PIPE_HOTPLUG_INTERRUPT_ENABLE
value|(1UL<<26)
end_define

begin_define
define|#
directive|define
name|PIPE_VSYNC_INTERRUPT_ENABLE
value|(1UL<<25)
end_define

begin_define
define|#
directive|define
name|PIPE_DISPLAY_LINE_COMPARE_ENABLE
value|(1UL<<24)
end_define

begin_define
define|#
directive|define
name|PIPE_DPST_EVENT_ENABLE
value|(1UL<<23)
end_define

begin_define
define|#
directive|define
name|PIPE_LEGACY_BLC_EVENT_ENABLE
value|(1UL<<22)
end_define

begin_define
define|#
directive|define
name|PIPE_ODD_FIELD_INTERRUPT_ENABLE
value|(1UL<<21)
end_define

begin_define
define|#
directive|define
name|PIPE_EVEN_FIELD_INTERRUPT_ENABLE
value|(1UL<<20)
end_define

begin_define
define|#
directive|define
name|PIPE_HOTPLUG_TV_INTERRUPT_ENABLE
value|(1UL<<18)
end_define

begin_comment
comment|/* pre-965 */
end_comment

begin_define
define|#
directive|define
name|PIPE_START_VBLANK_INTERRUPT_ENABLE
value|(1UL<<18)
end_define

begin_comment
comment|/* 965 or later */
end_comment

begin_define
define|#
directive|define
name|PIPE_VBLANK_INTERRUPT_ENABLE
value|(1UL<<17)
end_define

begin_define
define|#
directive|define
name|PIPE_OVERLAY_UPDATED_ENABLE
value|(1UL<<16)
end_define

begin_define
define|#
directive|define
name|PIPE_CRC_ERROR_INTERRUPT_STATUS
value|(1UL<<13)
end_define

begin_define
define|#
directive|define
name|PIPE_CRC_DONE_INTERRUPT_STATUS
value|(1UL<<12)
end_define

begin_define
define|#
directive|define
name|PIPE_GMBUS_INTERRUPT_STATUS
value|(1UL<<11)
end_define

begin_define
define|#
directive|define
name|PIPE_HOTPLUG_INTERRUPT_STATUS
value|(1UL<<10)
end_define

begin_define
define|#
directive|define
name|PIPE_VSYNC_INTERRUPT_STATUS
value|(1UL<<9)
end_define

begin_define
define|#
directive|define
name|PIPE_DISPLAY_LINE_COMPARE_STATUS
value|(1UL<<8)
end_define

begin_define
define|#
directive|define
name|PIPE_DPST_EVENT_STATUS
value|(1UL<<7)
end_define

begin_define
define|#
directive|define
name|PIPE_LEGACY_BLC_EVENT_STATUS
value|(1UL<<6)
end_define

begin_define
define|#
directive|define
name|PIPE_ODD_FIELD_INTERRUPT_STATUS
value|(1UL<<5)
end_define

begin_define
define|#
directive|define
name|PIPE_EVEN_FIELD_INTERRUPT_STATUS
value|(1UL<<4)
end_define

begin_define
define|#
directive|define
name|PIPE_HOTPLUG_TV_INTERRUPT_STATUS
value|(1UL<<2)
end_define

begin_comment
comment|/* pre-965 */
end_comment

begin_define
define|#
directive|define
name|PIPE_START_VBLANK_INTERRUPT_STATUS
value|(1UL<<2)
end_define

begin_comment
comment|/* 965 or later */
end_comment

begin_define
define|#
directive|define
name|PIPE_VBLANK_INTERRUPT_STATUS
value|(1UL<<1)
end_define

begin_define
define|#
directive|define
name|PIPE_OVERLAY_UPDATED_STATUS
value|(1UL<<0)
end_define

begin_define
define|#
directive|define
name|DSPARB
value|0x70030
end_define

begin_define
define|#
directive|define
name|DSPARB_CSTART_MASK
value|(0x7f<< 7)
end_define

begin_define
define|#
directive|define
name|DSPARB_CSTART_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|DSPARB_BSTART_MASK
value|(0x7f)
end_define

begin_define
define|#
directive|define
name|DSPARB_BSTART_SHIFT
value|0
end_define

begin_comment
comment|/*  * The two pipe frame counter registers are not synchronized, so  * reading a stable value is somewhat tricky. The following code   * should work:  *  *  do {  *    high1 = ((INREG(PIPEAFRAMEHIGH)& PIPE_FRAME_HIGH_MASK)>>  *             PIPE_FRAME_HIGH_SHIFT;  *    low1 =  ((INREG(PIPEAFRAMEPIXEL)& PIPE_FRAME_LOW_MASK)>>  *             PIPE_FRAME_LOW_SHIFT);  *    high2 = ((INREG(PIPEAFRAMEHIGH)& PIPE_FRAME_HIGH_MASK)>>  *             PIPE_FRAME_HIGH_SHIFT);  *  } while (high1 != high2);  *  frame = (high1<< 8) | low1;  */
end_comment

begin_define
define|#
directive|define
name|PIPEAFRAMEHIGH
value|0x70040
end_define

begin_define
define|#
directive|define
name|PIPE_FRAME_HIGH_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|PIPE_FRAME_HIGH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PIPEAFRAMEPIXEL
value|0x70044
end_define

begin_define
define|#
directive|define
name|PIPE_FRAME_LOW_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|PIPE_FRAME_LOW_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|PIPE_PIXEL_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|PIPE_PIXEL_SHIFT
value|0
end_define

begin_comment
comment|/* Cursor A& B regs */
end_comment

begin_define
define|#
directive|define
name|CURACNTR
value|0x70080
end_define

begin_define
define|#
directive|define
name|CURSOR_MODE_DISABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|CURSOR_MODE_64_32B_AX
value|0x07
end_define

begin_define
define|#
directive|define
name|CURSOR_MODE_64_ARGB_AX
value|((1<< 5) | CURSOR_MODE_64_32B_AX)
end_define

begin_define
define|#
directive|define
name|MCURSOR_GAMMA_ENABLE
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|CURABASE
value|0x70084
end_define

begin_define
define|#
directive|define
name|CURAPOS
value|0x70088
end_define

begin_define
define|#
directive|define
name|CURSOR_POS_MASK
value|0x007FF
end_define

begin_define
define|#
directive|define
name|CURSOR_POS_SIGN
value|0x8000
end_define

begin_define
define|#
directive|define
name|CURSOR_X_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CURSOR_Y_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CURBCNTR
value|0x700c0
end_define

begin_define
define|#
directive|define
name|CURBBASE
value|0x700c4
end_define

begin_define
define|#
directive|define
name|CURBPOS
value|0x700c8
end_define

begin_comment
comment|/* Display A control */
end_comment

begin_define
define|#
directive|define
name|DSPACNTR
value|0x70180
end_define

begin_define
define|#
directive|define
name|DISPLAY_PLANE_ENABLE
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|DISPLAY_PLANE_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|DISPPLANE_GAMMA_ENABLE
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_GAMMA_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|DISPPLANE_PIXFORMAT_MASK
value|(0xf<<26)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_8BPP
value|(0x2<<26)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_15_16BPP
value|(0x4<<26)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_16BPP
value|(0x5<<26)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_32BPP_NO_ALPHA
value|(0x6<<26)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_32BPP
value|(0x7<<26)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_STEREO_ENABLE
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_STEREO_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|DISPPLANE_SEL_PIPE_MASK
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_SEL_PIPE_A
value|0
end_define

begin_define
define|#
directive|define
name|DISPPLANE_SEL_PIPE_B
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_SRC_KEY_ENABLE
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_SRC_KEY_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|DISPPLANE_LINE_DOUBLE
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_NO_LINE_DOUBLE
value|0
end_define

begin_define
define|#
directive|define
name|DISPPLANE_STEREO_POLARITY_FIRST
value|0
end_define

begin_define
define|#
directive|define
name|DISPPLANE_STEREO_POLARITY_SECOND
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|DSPAADDR
value|0x70184
end_define

begin_define
define|#
directive|define
name|DSPASTRIDE
value|0x70188
end_define

begin_define
define|#
directive|define
name|DSPAPOS
value|0x7018C
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|DSPASIZE
value|0x70190
end_define

begin_define
define|#
directive|define
name|DSPASURF
value|0x7019C
end_define

begin_comment
comment|/* 965+ only */
end_comment

begin_define
define|#
directive|define
name|DSPATILEOFF
value|0x701A4
end_define

begin_comment
comment|/* 965+ only */
end_comment

begin_comment
comment|/* VBIOS flags */
end_comment

begin_define
define|#
directive|define
name|SWF00
value|0x71410
end_define

begin_define
define|#
directive|define
name|SWF01
value|0x71414
end_define

begin_define
define|#
directive|define
name|SWF02
value|0x71418
end_define

begin_define
define|#
directive|define
name|SWF03
value|0x7141c
end_define

begin_define
define|#
directive|define
name|SWF04
value|0x71420
end_define

begin_define
define|#
directive|define
name|SWF05
value|0x71424
end_define

begin_define
define|#
directive|define
name|SWF06
value|0x71428
end_define

begin_define
define|#
directive|define
name|SWF10
value|0x70410
end_define

begin_define
define|#
directive|define
name|SWF11
value|0x70414
end_define

begin_define
define|#
directive|define
name|SWF14
value|0x71420
end_define

begin_define
define|#
directive|define
name|SWF30
value|0x72414
end_define

begin_define
define|#
directive|define
name|SWF31
value|0x72418
end_define

begin_define
define|#
directive|define
name|SWF32
value|0x7241c
end_define

begin_comment
comment|/* Pipe B */
end_comment

begin_define
define|#
directive|define
name|PIPEBDSL
value|0x71000
end_define

begin_define
define|#
directive|define
name|PIPEBCONF
value|0x71008
end_define

begin_define
define|#
directive|define
name|PIPEBSTAT
value|0x71024
end_define

begin_define
define|#
directive|define
name|PIPEBFRAMEHIGH
value|0x71040
end_define

begin_define
define|#
directive|define
name|PIPEBFRAMEPIXEL
value|0x71044
end_define

begin_comment
comment|/* Display B control */
end_comment

begin_define
define|#
directive|define
name|DSPBCNTR
value|0x71180
end_define

begin_define
define|#
directive|define
name|DISPPLANE_ALPHA_TRANS_ENABLE
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_ALPHA_TRANS_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|DISPPLANE_SPRITE_ABOVE_DISPLAY
value|0
end_define

begin_define
define|#
directive|define
name|DISPPLANE_SPRITE_ABOVE_OVERLAY
value|(1)
end_define

begin_define
define|#
directive|define
name|DSPBADDR
value|0x71184
end_define

begin_define
define|#
directive|define
name|DSPBSTRIDE
value|0x71188
end_define

begin_define
define|#
directive|define
name|DSPBPOS
value|0x7118C
end_define

begin_define
define|#
directive|define
name|DSPBSIZE
value|0x71190
end_define

begin_define
define|#
directive|define
name|DSPBSURF
value|0x7119C
end_define

begin_define
define|#
directive|define
name|DSPBTILEOFF
value|0x711A4
end_define

begin_comment
comment|/* VBIOS regs */
end_comment

begin_define
define|#
directive|define
name|VGACNTRL
value|0x71400
end_define

begin_define
define|#
directive|define
name|VGA_DISP_DISABLE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|VGA_2X_MODE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|VGA_PIPE_B_SELECT
value|(1<< 29)
end_define

begin_comment
comment|/* Chipset type macros */
end_comment

begin_define
define|#
directive|define
name|IS_I830
parameter_list|(
name|dev
parameter_list|)
value|((dev)->pci_device == 0x3577)
end_define

begin_define
define|#
directive|define
name|IS_845G
parameter_list|(
name|dev
parameter_list|)
value|((dev)->pci_device == 0x2562)
end_define

begin_define
define|#
directive|define
name|IS_I85X
parameter_list|(
name|dev
parameter_list|)
value|((dev)->pci_device == 0x3582)
end_define

begin_define
define|#
directive|define
name|IS_I855
parameter_list|(
name|dev
parameter_list|)
value|((dev)->pci_device == 0x3582)
end_define

begin_define
define|#
directive|define
name|IS_I865G
parameter_list|(
name|dev
parameter_list|)
value|((dev)->pci_device == 0x2572)
end_define

begin_define
define|#
directive|define
name|IS_I915G
parameter_list|(
name|dev
parameter_list|)
value|((dev)->pci_device == 0x2582 || (dev)->pci_device == 0x258a)
end_define

begin_define
define|#
directive|define
name|IS_I915GM
parameter_list|(
name|dev
parameter_list|)
value|((dev)->pci_device == 0x2592)
end_define

begin_define
define|#
directive|define
name|IS_I945G
parameter_list|(
name|dev
parameter_list|)
value|((dev)->pci_device == 0x2772)
end_define

begin_define
define|#
directive|define
name|IS_I945GM
parameter_list|(
name|dev
parameter_list|)
value|((dev)->pci_device == 0x27A2 ||\ 		        (dev)->pci_device == 0x27AE)
end_define

begin_define
define|#
directive|define
name|IS_I965G
parameter_list|(
name|dev
parameter_list|)
value|((dev)->pci_device == 0x2972 || \ 		       (dev)->pci_device == 0x2982 || \ 		       (dev)->pci_device == 0x2992 || \ 		       (dev)->pci_device == 0x29A2 || \ 		       (dev)->pci_device == 0x2A02 || \ 		       (dev)->pci_device == 0x2A12 || \ 		       (dev)->pci_device == 0x2A42 || \ 		       (dev)->pci_device == 0x2E02 || \ 		       (dev)->pci_device == 0x2E12 || \ 		       (dev)->pci_device == 0x2E22)
end_define

begin_define
define|#
directive|define
name|IS_I965GM
parameter_list|(
name|dev
parameter_list|)
value|((dev)->pci_device == 0x2A02)
end_define

begin_define
define|#
directive|define
name|IS_GM45
parameter_list|(
name|dev
parameter_list|)
value|((dev)->pci_device == 0x2A42)
end_define

begin_define
define|#
directive|define
name|IS_G4X
parameter_list|(
name|dev
parameter_list|)
value|((dev)->pci_device == 0x2E02 || \ 		     (dev)->pci_device == 0x2E12 || \ 		     (dev)->pci_device == 0x2E22)
end_define

begin_define
define|#
directive|define
name|IS_G33
parameter_list|(
name|dev
parameter_list|)
value|((dev)->pci_device == 0x29C2 ||	\ 			(dev)->pci_device == 0x29B2 ||	\ 			(dev)->pci_device == 0x29D2)
end_define

begin_define
define|#
directive|define
name|IS_I9XX
parameter_list|(
name|dev
parameter_list|)
value|(IS_I915G(dev) || IS_I915GM(dev) || IS_I945G(dev) || \ 		      IS_I945GM(dev) || IS_I965G(dev) || IS_G33(dev))
end_define

begin_define
define|#
directive|define
name|IS_MOBILE
parameter_list|(
name|dev
parameter_list|)
value|(IS_I830(dev) || IS_I85X(dev) || IS_I915GM(dev) || \ 			IS_I945GM(dev) || IS_I965GM(dev) || IS_GM45(dev))
end_define

begin_define
define|#
directive|define
name|I915_NEED_GFX_HWS
parameter_list|(
name|dev
parameter_list|)
value|(IS_G33(dev) || IS_GM45(dev) || IS_G4X(dev))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

