begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mach64_drv.h -- Private header for mach64 driver -*- linux-c -*-  * Created: Fri Nov 24 22:07:58 2000 by gareth@valinux.com  */
end_comment

begin_comment
comment|/*-  * Copyright 2000 Gareth Hughes  * Copyright 2002 Frank C. Earl  * Copyright 2002-2003 Leif Delgass  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT OWNER(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER  * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Gareth Hughes<gareth@valinux.com>  *    Frank C. Earl<fearl@airmail.net>  *    Leif Delgass<ldelgass@retinalburn.net>  *    JosÃ© Fonseca<j_r_fonseca@yahoo.co.uk>  */
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
name|__MACH64_DRV_H__
end_ifndef

begin_define
define|#
directive|define
name|__MACH64_DRV_H__
end_define

begin_comment
comment|/* General customization:  */
end_comment

begin_define
define|#
directive|define
name|DRIVER_AUTHOR
value|"Gareth Hughes, Leif Delgass, JosÃ© Fonseca"
end_define

begin_define
define|#
directive|define
name|DRIVER_NAME
value|"mach64"
end_define

begin_define
define|#
directive|define
name|DRIVER_DESC
value|"DRM module for the ATI Rage Pro"
end_define

begin_define
define|#
directive|define
name|DRIVER_DATE
value|"20060718"
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
value|0
end_define

begin_define
define|#
directive|define
name|DRIVER_PATCHLEVEL
value|0
end_define

begin_comment
comment|/* FIXME: remove these when not needed */
end_comment

begin_comment
comment|/* Development driver options */
end_comment

begin_define
define|#
directive|define
name|MACH64_EXTRA_CHECKING
value|0
end_define

begin_comment
comment|/* Extra sanity checks for DMA/freelist management */
end_comment

begin_define
define|#
directive|define
name|MACH64_VERBOSE
value|0
end_define

begin_comment
comment|/* Verbose debugging output */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|drm_mach64_freelist
block|{
name|struct
name|list_head
name|list
decl_stmt|;
comment|/* List pointers for free_list, placeholders, or pending list */
name|struct
name|drm_buf
modifier|*
name|buf
decl_stmt|;
comment|/* Pointer to the buffer */
name|int
name|discard
decl_stmt|;
comment|/* This flag is set when we're done (re)using a buffer */
name|u32
name|ring_ofs
decl_stmt|;
comment|/* dword offset in ring of last descriptor for this buffer */
block|}
name|drm_mach64_freelist_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_mach64_descriptor_ring
block|{
name|void
modifier|*
name|start
decl_stmt|;
comment|/* write pointer (cpu address) to start of descriptor ring */
name|u32
name|start_addr
decl_stmt|;
comment|/* bus address of beginning of descriptor ring */
name|int
name|size
decl_stmt|;
comment|/* size of ring in bytes */
name|u32
name|head_addr
decl_stmt|;
comment|/* bus address of descriptor ring head */
name|u32
name|head
decl_stmt|;
comment|/* dword offset of descriptor ring head */
name|u32
name|tail
decl_stmt|;
comment|/* dword offset of descriptor ring tail */
name|u32
name|tail_mask
decl_stmt|;
comment|/* mask used to wrap ring */
name|int
name|space
decl_stmt|;
comment|/* number of free bytes in ring */
block|}
name|drm_mach64_descriptor_ring_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_mach64_private
block|{
name|drm_mach64_sarea_t
modifier|*
name|sarea_priv
decl_stmt|;
name|int
name|is_pci
decl_stmt|;
name|drm_mach64_dma_mode_t
name|driver_mode
decl_stmt|;
comment|/* Async DMA, sync DMA, or MMIO */
name|int
name|usec_timeout
decl_stmt|;
comment|/* Timeout for the wait functions */
name|drm_mach64_descriptor_ring_t
name|ring
decl_stmt|;
comment|/* DMA descriptor table (ring buffer) */
name|int
name|ring_running
decl_stmt|;
comment|/* Is bus mastering is enabled */
name|struct
name|list_head
name|free_list
decl_stmt|;
comment|/* Free-list head */
name|struct
name|list_head
name|placeholders
decl_stmt|;
comment|/* Placeholder list for buffers held by clients */
name|struct
name|list_head
name|pending
decl_stmt|;
comment|/* Buffers pending completion */
name|u32
name|frame_ofs
index|[
name|MACH64_MAX_QUEUED_FRAMES
index|]
decl_stmt|;
comment|/* dword ring offsets of most recent frame swaps */
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
name|atomic_t
name|vbl_received
decl_stmt|;
comment|/**< Number of vblanks received. */
name|u32
name|front_offset_pitch
decl_stmt|;
name|u32
name|back_offset_pitch
decl_stmt|;
name|u32
name|depth_offset_pitch
decl_stmt|;
name|drm_local_map_t
modifier|*
name|sarea
decl_stmt|;
name|drm_local_map_t
modifier|*
name|fb
decl_stmt|;
name|drm_local_map_t
modifier|*
name|mmio
decl_stmt|;
name|drm_local_map_t
modifier|*
name|ring_map
decl_stmt|;
name|drm_local_map_t
modifier|*
name|dev_buffers
decl_stmt|;
comment|/* this is a pointer to a structure in dev */
name|drm_local_map_t
modifier|*
name|agp_textures
decl_stmt|;
block|}
name|drm_mach64_private_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|struct
name|drm_ioctl_desc
name|mach64_ioctls
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mach64_max_ioctl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mach64_dma.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|mach64_dma_init
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
name|mach64_dma_idle
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
name|mach64_dma_flush
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
name|mach64_engine_reset
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
name|mach64_dma_buffers
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
name|mach64_driver_lastclose
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
name|mach64_init_freelist
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
name|mach64_destroy_freelist
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
name|mach64_freelist_get
parameter_list|(
name|drm_mach64_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mach64_freelist_put
parameter_list|(
name|drm_mach64_private_t
modifier|*
name|dev_priv
parameter_list|,
name|struct
name|drm_buf
modifier|*
name|copy_buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mach64_do_wait_for_fifo
parameter_list|(
name|drm_mach64_private_t
modifier|*
name|dev_priv
parameter_list|,
name|int
name|entries
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mach64_do_wait_for_idle
parameter_list|(
name|drm_mach64_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mach64_wait_ring
parameter_list|(
name|drm_mach64_private_t
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
name|mach64_do_dispatch_pseudo_dma
parameter_list|(
name|drm_mach64_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mach64_do_release_used_buffers
parameter_list|(
name|drm_mach64_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mach64_dump_engine_info
parameter_list|(
name|drm_mach64_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mach64_dump_ring_info
parameter_list|(
name|drm_mach64_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mach64_do_engine_reset
parameter_list|(
name|drm_mach64_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mach64_add_buf_to_ring
parameter_list|(
name|drm_mach64_private_t
modifier|*
name|dev_priv
parameter_list|,
name|drm_mach64_freelist_t
modifier|*
name|_entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mach64_add_hostdata_buf_to_ring
parameter_list|(
name|drm_mach64_private_t
modifier|*
name|dev_priv
parameter_list|,
name|drm_mach64_freelist_t
modifier|*
name|_entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mach64_do_dma_idle
parameter_list|(
name|drm_mach64_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mach64_do_dma_flush
parameter_list|(
name|drm_mach64_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mach64_do_cleanup_dma
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* mach64_state.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|mach64_dma_clear
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
name|mach64_dma_swap
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
name|mach64_dma_vertex
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
name|mach64_dma_blit
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
name|mach64_get_param
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
name|mach64_driver_load
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
name|u32
name|mach64_get_vblank_counter
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
name|mach64_enable_vblank
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
name|mach64_disable_vblank
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
name|mach64_driver_irq_handler
parameter_list|(
name|DRM_IRQ_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mach64_driver_irq_preinstall
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
name|mach64_driver_irq_postinstall
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
name|mach64_driver_irq_uninstall
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ================================================================  * Registers  */
end_comment

begin_define
define|#
directive|define
name|MACH64_AGP_BASE
value|0x0148
end_define

begin_define
define|#
directive|define
name|MACH64_AGP_CNTL
value|0x014c
end_define

begin_define
define|#
directive|define
name|MACH64_ALPHA_TST_CNTL
value|0x0550
end_define

begin_define
define|#
directive|define
name|MACH64_DSP_CONFIG
value|0x0420
end_define

begin_define
define|#
directive|define
name|MACH64_DSP_ON_OFF
value|0x0424
end_define

begin_define
define|#
directive|define
name|MACH64_EXT_MEM_CNTL
value|0x04ac
end_define

begin_define
define|#
directive|define
name|MACH64_GEN_TEST_CNTL
value|0x04d0
end_define

begin_define
define|#
directive|define
name|MACH64_HW_DEBUG
value|0x047c
end_define

begin_define
define|#
directive|define
name|MACH64_MEM_ADDR_CONFIG
value|0x0434
end_define

begin_define
define|#
directive|define
name|MACH64_MEM_BUF_CNTL
value|0x042c
end_define

begin_define
define|#
directive|define
name|MACH64_MEM_CNTL
value|0x04b0
end_define

begin_define
define|#
directive|define
name|MACH64_BM_ADDR
value|0x0648
end_define

begin_define
define|#
directive|define
name|MACH64_BM_COMMAND
value|0x0188
end_define

begin_define
define|#
directive|define
name|MACH64_BM_DATA
value|0x0648
end_define

begin_define
define|#
directive|define
name|MACH64_BM_FRAME_BUF_OFFSET
value|0x0180
end_define

begin_define
define|#
directive|define
name|MACH64_BM_GUI_TABLE
value|0x01b8
end_define

begin_define
define|#
directive|define
name|MACH64_BM_GUI_TABLE_CMD
value|0x064c
end_define

begin_define
define|#
directive|define
name|MACH64_CIRCULAR_BUF_SIZE_16KB
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|MACH64_CIRCULAR_BUF_SIZE_32KB
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MACH64_CIRCULAR_BUF_SIZE_64KB
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|MACH64_CIRCULAR_BUF_SIZE_128KB
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|MACH64_LAST_DESCRIPTOR
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|MACH64_BM_HOSTDATA
value|0x0644
end_define

begin_define
define|#
directive|define
name|MACH64_BM_STATUS
value|0x018c
end_define

begin_define
define|#
directive|define
name|MACH64_BM_SYSTEM_MEM_ADDR
value|0x0184
end_define

begin_define
define|#
directive|define
name|MACH64_BM_SYSTEM_TABLE
value|0x01bc
end_define

begin_define
define|#
directive|define
name|MACH64_BUS_CNTL
value|0x04a0
end_define

begin_define
define|#
directive|define
name|MACH64_BUS_MSTR_RESET
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MACH64_BUS_APER_REG_DIS
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MACH64_BUS_FLUSH_BUF
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MACH64_BUS_MASTER_DIS
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|MACH64_BUS_EXT_REG_EN
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|MACH64_CLR_CMP_CLR
value|0x0700
end_define

begin_define
define|#
directive|define
name|MACH64_CLR_CMP_CNTL
value|0x0708
end_define

begin_define
define|#
directive|define
name|MACH64_CLR_CMP_MASK
value|0x0704
end_define

begin_define
define|#
directive|define
name|MACH64_CONFIG_CHIP_ID
value|0x04e0
end_define

begin_define
define|#
directive|define
name|MACH64_CONFIG_CNTL
value|0x04dc
end_define

begin_define
define|#
directive|define
name|MACH64_CONFIG_STAT0
value|0x04e4
end_define

begin_define
define|#
directive|define
name|MACH64_CONFIG_STAT1
value|0x0494
end_define

begin_define
define|#
directive|define
name|MACH64_CONFIG_STAT2
value|0x0498
end_define

begin_define
define|#
directive|define
name|MACH64_CONTEXT_LOAD_CNTL
value|0x072c
end_define

begin_define
define|#
directive|define
name|MACH64_CONTEXT_MASK
value|0x0720
end_define

begin_define
define|#
directive|define
name|MACH64_COMPOSITE_SHADOW_ID
value|0x0798
end_define

begin_define
define|#
directive|define
name|MACH64_CRC_SIG
value|0x04e8
end_define

begin_define
define|#
directive|define
name|MACH64_CUSTOM_MACRO_CNTL
value|0x04d4
end_define

begin_define
define|#
directive|define
name|MACH64_DP_BKGD_CLR
value|0x06c0
end_define

begin_define
define|#
directive|define
name|MACH64_DP_FOG_CLR
value|0x06c4
end_define

begin_define
define|#
directive|define
name|MACH64_DP_FGRD_BKGD_CLR
value|0x06e0
end_define

begin_define
define|#
directive|define
name|MACH64_DP_FRGD_CLR
value|0x06c4
end_define

begin_define
define|#
directive|define
name|MACH64_DP_FGRD_CLR_MIX
value|0x06dc
end_define

begin_define
define|#
directive|define
name|MACH64_DP_MIX
value|0x06d4
end_define

begin_define
define|#
directive|define
name|BKGD_MIX_NOT_D
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|BKGD_MIX_ZERO
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|BKGD_MIX_ONE
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|MACH64_BKGD_MIX_D
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|BKGD_MIX_NOT_S
value|(4<< 0)
end_define

begin_define
define|#
directive|define
name|BKGD_MIX_D_XOR_S
value|(5<< 0)
end_define

begin_define
define|#
directive|define
name|BKGD_MIX_NOT_D_XOR_S
value|(6<< 0)
end_define

begin_define
define|#
directive|define
name|MACH64_BKGD_MIX_S
value|(7<< 0)
end_define

begin_define
define|#
directive|define
name|BKGD_MIX_NOT_D_OR_NOT_S
value|(8<< 0)
end_define

begin_define
define|#
directive|define
name|BKGD_MIX_D_OR_NOT_S
value|(9<< 0)
end_define

begin_define
define|#
directive|define
name|BKGD_MIX_NOT_D_OR_S
value|(10<< 0)
end_define

begin_define
define|#
directive|define
name|BKGD_MIX_D_OR_S
value|(11<< 0)
end_define

begin_define
define|#
directive|define
name|BKGD_MIX_D_AND_S
value|(12<< 0)
end_define

begin_define
define|#
directive|define
name|BKGD_MIX_NOT_D_AND_S
value|(13<< 0)
end_define

begin_define
define|#
directive|define
name|BKGD_MIX_D_AND_NOT_S
value|(14<< 0)
end_define

begin_define
define|#
directive|define
name|BKGD_MIX_NOT_D_AND_NOT_S
value|(15<< 0)
end_define

begin_define
define|#
directive|define
name|BKGD_MIX_D_PLUS_S_DIV2
value|(23<< 0)
end_define

begin_define
define|#
directive|define
name|FRGD_MIX_NOT_D
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|FRGD_MIX_ZERO
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|FRGD_MIX_ONE
value|(2<< 16)
end_define

begin_define
define|#
directive|define
name|FRGD_MIX_D
value|(3<< 16)
end_define

begin_define
define|#
directive|define
name|FRGD_MIX_NOT_S
value|(4<< 16)
end_define

begin_define
define|#
directive|define
name|FRGD_MIX_D_XOR_S
value|(5<< 16)
end_define

begin_define
define|#
directive|define
name|FRGD_MIX_NOT_D_XOR_S
value|(6<< 16)
end_define

begin_define
define|#
directive|define
name|MACH64_FRGD_MIX_S
value|(7<< 16)
end_define

begin_define
define|#
directive|define
name|FRGD_MIX_NOT_D_OR_NOT_S
value|(8<< 16)
end_define

begin_define
define|#
directive|define
name|FRGD_MIX_D_OR_NOT_S
value|(9<< 16)
end_define

begin_define
define|#
directive|define
name|FRGD_MIX_NOT_D_OR_S
value|(10<< 16)
end_define

begin_define
define|#
directive|define
name|FRGD_MIX_D_OR_S
value|(11<< 16)
end_define

begin_define
define|#
directive|define
name|FRGD_MIX_D_AND_S
value|(12<< 16)
end_define

begin_define
define|#
directive|define
name|FRGD_MIX_NOT_D_AND_S
value|(13<< 16)
end_define

begin_define
define|#
directive|define
name|FRGD_MIX_D_AND_NOT_S
value|(14<< 16)
end_define

begin_define
define|#
directive|define
name|FRGD_MIX_NOT_D_AND_NOT_S
value|(15<< 16)
end_define

begin_define
define|#
directive|define
name|FRGD_MIX_D_PLUS_S_DIV2
value|(23<< 16)
end_define

begin_define
define|#
directive|define
name|MACH64_DP_PIX_WIDTH
value|0x06d0
end_define

begin_define
define|#
directive|define
name|MACH64_HOST_TRIPLE_ENABLE
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|MACH64_BYTE_ORDER_MSB_TO_LSB
value|(0<< 24)
end_define

begin_define
define|#
directive|define
name|MACH64_BYTE_ORDER_LSB_TO_MSB
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|MACH64_DP_SRC
value|0x06d8
end_define

begin_define
define|#
directive|define
name|MACH64_BKGD_SRC_BKGD_CLR
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|MACH64_BKGD_SRC_FRGD_CLR
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MACH64_BKGD_SRC_HOST
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|MACH64_BKGD_SRC_BLIT
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|MACH64_BKGD_SRC_PATTERN
value|(4<< 0)
end_define

begin_define
define|#
directive|define
name|MACH64_BKGD_SRC_3D
value|(5<< 0)
end_define

begin_define
define|#
directive|define
name|MACH64_FRGD_SRC_BKGD_CLR
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|MACH64_FRGD_SRC_FRGD_CLR
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|MACH64_FRGD_SRC_HOST
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|MACH64_FRGD_SRC_BLIT
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|MACH64_FRGD_SRC_PATTERN
value|(4<< 8)
end_define

begin_define
define|#
directive|define
name|MACH64_FRGD_SRC_3D
value|(5<< 8)
end_define

begin_define
define|#
directive|define
name|MACH64_MONO_SRC_ONE
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|MACH64_MONO_SRC_PATTERN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|MACH64_MONO_SRC_HOST
value|(2<< 16)
end_define

begin_define
define|#
directive|define
name|MACH64_MONO_SRC_BLIT
value|(3<< 16)
end_define

begin_define
define|#
directive|define
name|MACH64_DP_WRITE_MASK
value|0x06c8
end_define

begin_define
define|#
directive|define
name|MACH64_DST_CNTL
value|0x0530
end_define

begin_define
define|#
directive|define
name|MACH64_DST_X_RIGHT_TO_LEFT
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|MACH64_DST_X_LEFT_TO_RIGHT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MACH64_DST_Y_BOTTOM_TO_TOP
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|MACH64_DST_Y_TOP_TO_BOTTOM
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MACH64_DST_X_MAJOR
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|MACH64_DST_Y_MAJOR
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MACH64_DST_X_TILE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|MACH64_DST_Y_TILE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MACH64_DST_LAST_PEL
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MACH64_DST_POLYGON_ENABLE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|MACH64_DST_24_ROTATION_ENABLE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|MACH64_DST_HEIGHT_WIDTH
value|0x0518
end_define

begin_define
define|#
directive|define
name|MACH64_DST_OFF_PITCH
value|0x0500
end_define

begin_define
define|#
directive|define
name|MACH64_DST_WIDTH_HEIGHT
value|0x06ec
end_define

begin_define
define|#
directive|define
name|MACH64_DST_X_Y
value|0x06e8
end_define

begin_define
define|#
directive|define
name|MACH64_DST_Y_X
value|0x050c
end_define

begin_define
define|#
directive|define
name|MACH64_FIFO_STAT
value|0x0710
end_define

begin_define
define|#
directive|define
name|MACH64_FIFO_SLOT_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|MACH64_FIFO_ERR
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|MACH64_GEN_TEST_CNTL
value|0x04d0
end_define

begin_define
define|#
directive|define
name|MACH64_GUI_ENGINE_ENABLE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|MACH64_GUI_CMDFIFO_DEBUG
value|0x0170
end_define

begin_define
define|#
directive|define
name|MACH64_GUI_CMDFIFO_DATA
value|0x0174
end_define

begin_define
define|#
directive|define
name|MACH64_GUI_CNTL
value|0x0178
end_define

begin_define
define|#
directive|define
name|MACH64_CMDFIFO_SIZE_MASK
value|0x00000003ul
end_define

begin_define
define|#
directive|define
name|MACH64_CMDFIFO_SIZE_192
value|0x00000000ul
end_define

begin_define
define|#
directive|define
name|MACH64_CMDFIFO_SIZE_128
value|0x00000001ul
end_define

begin_define
define|#
directive|define
name|MACH64_CMDFIFO_SIZE_64
value|0x00000002ul
end_define

begin_define
define|#
directive|define
name|MACH64_GUI_STAT
value|0x0738
end_define

begin_define
define|#
directive|define
name|MACH64_GUI_ACTIVE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MACH64_GUI_TRAJ_CNTL
value|0x0730
end_define

begin_define
define|#
directive|define
name|MACH64_HOST_CNTL
value|0x0640
end_define

begin_define
define|#
directive|define
name|MACH64_HOST_DATA0
value|0x0600
end_define

begin_define
define|#
directive|define
name|MACH64_ONE_OVER_AREA
value|0x029c
end_define

begin_define
define|#
directive|define
name|MACH64_ONE_OVER_AREA_UC
value|0x0300
end_define

begin_define
define|#
directive|define
name|MACH64_PAT_REG0
value|0x0680
end_define

begin_define
define|#
directive|define
name|MACH64_PAT_REG1
value|0x0684
end_define

begin_define
define|#
directive|define
name|MACH64_SC_LEFT
value|0x06a0
end_define

begin_define
define|#
directive|define
name|MACH64_SC_RIGHT
value|0x06a4
end_define

begin_define
define|#
directive|define
name|MACH64_SC_LEFT_RIGHT
value|0x06a8
end_define

begin_define
define|#
directive|define
name|MACH64_SC_TOP
value|0x06ac
end_define

begin_define
define|#
directive|define
name|MACH64_SC_BOTTOM
value|0x06b0
end_define

begin_define
define|#
directive|define
name|MACH64_SC_TOP_BOTTOM
value|0x06b4
end_define

begin_define
define|#
directive|define
name|MACH64_SCALE_3D_CNTL
value|0x05fc
end_define

begin_define
define|#
directive|define
name|MACH64_SCRATCH_REG0
value|0x0480
end_define

begin_define
define|#
directive|define
name|MACH64_SCRATCH_REG1
value|0x0484
end_define

begin_define
define|#
directive|define
name|MACH64_SECONDARY_TEX_OFF
value|0x0778
end_define

begin_define
define|#
directive|define
name|MACH64_SETUP_CNTL
value|0x0304
end_define

begin_define
define|#
directive|define
name|MACH64_SRC_CNTL
value|0x05b4
end_define

begin_define
define|#
directive|define
name|MACH64_SRC_BM_ENABLE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|MACH64_SRC_BM_SYNC
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|MACH64_SRC_BM_OP_FRAME_TO_SYSTEM
value|(0<< 10)
end_define

begin_define
define|#
directive|define
name|MACH64_SRC_BM_OP_SYSTEM_TO_FRAME
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|MACH64_SRC_BM_OP_REG_TO_SYSTEM
value|(2<< 10)
end_define

begin_define
define|#
directive|define
name|MACH64_SRC_BM_OP_SYSTEM_TO_REG
value|(3<< 10)
end_define

begin_define
define|#
directive|define
name|MACH64_SRC_HEIGHT1
value|0x0594
end_define

begin_define
define|#
directive|define
name|MACH64_SRC_HEIGHT2
value|0x05ac
end_define

begin_define
define|#
directive|define
name|MACH64_SRC_HEIGHT1_WIDTH1
value|0x0598
end_define

begin_define
define|#
directive|define
name|MACH64_SRC_HEIGHT2_WIDTH2
value|0x05b0
end_define

begin_define
define|#
directive|define
name|MACH64_SRC_OFF_PITCH
value|0x0580
end_define

begin_define
define|#
directive|define
name|MACH64_SRC_WIDTH1
value|0x0590
end_define

begin_define
define|#
directive|define
name|MACH64_SRC_Y_X
value|0x058c
end_define

begin_define
define|#
directive|define
name|MACH64_TEX_0_OFF
value|0x05c0
end_define

begin_define
define|#
directive|define
name|MACH64_TEX_CNTL
value|0x0774
end_define

begin_define
define|#
directive|define
name|MACH64_TEX_SIZE_PITCH
value|0x0770
end_define

begin_define
define|#
directive|define
name|MACH64_TIMER_CONFIG
value|0x0428
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_1_ARGB
value|0x0254
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_1_S
value|0x0240
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_1_SECONDARY_S
value|0x0328
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_1_SECONDARY_T
value|0x032c
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_1_SECONDARY_W
value|0x0330
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_1_SPEC_ARGB
value|0x024c
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_1_T
value|0x0244
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_1_W
value|0x0248
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_1_X_Y
value|0x0258
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_1_Z
value|0x0250
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_2_ARGB
value|0x0274
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_2_S
value|0x0260
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_2_SECONDARY_S
value|0x0334
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_2_SECONDARY_T
value|0x0338
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_2_SECONDARY_W
value|0x033c
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_2_SPEC_ARGB
value|0x026c
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_2_T
value|0x0264
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_2_W
value|0x0268
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_2_X_Y
value|0x0278
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_2_Z
value|0x0270
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_3_ARGB
value|0x0294
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_3_S
value|0x0280
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_3_SECONDARY_S
value|0x02a0
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_3_SECONDARY_T
value|0x02a4
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_3_SECONDARY_W
value|0x02a8
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_3_SPEC_ARGB
value|0x028c
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_3_T
value|0x0284
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_3_W
value|0x0288
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_3_X_Y
value|0x0298
end_define

begin_define
define|#
directive|define
name|MACH64_VERTEX_3_Z
value|0x0290
end_define

begin_define
define|#
directive|define
name|MACH64_Z_CNTL
value|0x054c
end_define

begin_define
define|#
directive|define
name|MACH64_Z_OFF_PITCH
value|0x0548
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_VLINE_CRNT_VLINE
value|0x0410
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_VLINE_MASK
value|0x000007ff
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_CRNT_VLINE_MASK
value|0x07ff0000
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_OFF_PITCH
value|0x0414
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_INT_CNTL
value|0x0418
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_VBLANK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_VBLANK_INT_EN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_VBLANK_INT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_VLINE_INT_EN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_VLINE_INT
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_VLINE_SYNC
value|(1<< 5)
end_define

begin_comment
comment|/* 0=even, 1=odd */
end_comment

begin_define
define|#
directive|define
name|MACH64_CRTC_FRAME
value|(1<< 6)
end_define

begin_comment
comment|/* 0=even, 1=odd */
end_comment

begin_define
define|#
directive|define
name|MACH64_CRTC_SNAPSHOT_INT_EN
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_SNAPSHOT_INT
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_I2C_INT_EN
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_I2C_INT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC2_VBLANK
value|(1<< 11)
end_define

begin_comment
comment|/* LT Pro */
end_comment

begin_define
define|#
directive|define
name|MACH64_CRTC2_VBLANK_INT_EN
value|(1<< 12)
end_define

begin_comment
comment|/* LT Pro */
end_comment

begin_define
define|#
directive|define
name|MACH64_CRTC2_VBLANK_INT
value|(1<< 13)
end_define

begin_comment
comment|/* LT Pro */
end_comment

begin_define
define|#
directive|define
name|MACH64_CRTC2_VLINE_INT_EN
value|(1<< 14)
end_define

begin_comment
comment|/* LT Pro */
end_comment

begin_define
define|#
directive|define
name|MACH64_CRTC2_VLINE_INT
value|(1<< 15)
end_define

begin_comment
comment|/* LT Pro */
end_comment

begin_define
define|#
directive|define
name|MACH64_CRTC_CAPBUF0_INT_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_CAPBUF0_INT
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_CAPBUF1_INT_EN
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_CAPBUF1_INT
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_OVERLAY_EOF_INT_EN
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_OVERLAY_EOF_INT
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_ONESHOT_CAP_INT_EN
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_ONESHOT_CAP_INT
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_BUSMASTER_EOL_INT_EN
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_BUSMASTER_EOL_INT
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_GP_INT_EN
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_GP_INT
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC2_VLINE_SYNC
value|(1<< 28)
end_define

begin_comment
comment|/* LT Pro */
end_comment

begin_comment
comment|/* 0=even, 1=odd */
end_comment

begin_define
define|#
directive|define
name|MACH64_CRTC_SNAPSHOT2_INT_EN
value|(1<< 29)
end_define

begin_comment
comment|/* LT Pro */
end_comment

begin_define
define|#
directive|define
name|MACH64_CRTC_SNAPSHOT2_INT
value|(1<< 30)
end_define

begin_comment
comment|/* LT Pro */
end_comment

begin_define
define|#
directive|define
name|MACH64_CRTC_VBLANK2_INT
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_INT_ENS
define|\
value|(						\ 			MACH64_CRTC_VBLANK_INT_EN |		\ 			MACH64_CRTC_VLINE_INT_EN |		\ 			MACH64_CRTC_SNAPSHOT_INT_EN |		\ 			MACH64_CRTC_I2C_INT_EN |		\ 			MACH64_CRTC2_VBLANK_INT_EN |		\ 			MACH64_CRTC2_VLINE_INT_EN |		\ 			MACH64_CRTC_CAPBUF0_INT_EN |		\ 			MACH64_CRTC_CAPBUF1_INT_EN |		\ 			MACH64_CRTC_OVERLAY_EOF_INT_EN |	\ 			MACH64_CRTC_ONESHOT_CAP_INT_EN |	\ 			MACH64_CRTC_BUSMASTER_EOL_INT_EN |	\ 			MACH64_CRTC_GP_INT_EN |			\ 			MACH64_CRTC_SNAPSHOT2_INT_EN |		\ 			0					\ 		)
end_define

begin_define
define|#
directive|define
name|MACH64_CRTC_INT_ACKS
define|\
value|(					\ 			MACH64_CRTC_VBLANK_INT |	\ 			MACH64_CRTC_VLINE_INT |		\ 			MACH64_CRTC_SNAPSHOT_INT |	\ 			MACH64_CRTC_I2C_INT |		\ 			MACH64_CRTC2_VBLANK_INT |	\ 			MACH64_CRTC2_VLINE_INT |	\ 			MACH64_CRTC_CAPBUF0_INT |	\ 			MACH64_CRTC_CAPBUF1_INT |	\ 			MACH64_CRTC_OVERLAY_EOF_INT |	\ 			MACH64_CRTC_ONESHOT_CAP_INT |	\ 			MACH64_CRTC_BUSMASTER_EOL_INT |	\ 			MACH64_CRTC_GP_INT |		\ 			MACH64_CRTC_SNAPSHOT2_INT |	\ 			MACH64_CRTC_VBLANK2_INT |	\ 			0				\ 		)
end_define

begin_define
define|#
directive|define
name|MACH64_DATATYPE_CI8
value|2
end_define

begin_define
define|#
directive|define
name|MACH64_DATATYPE_ARGB1555
value|3
end_define

begin_define
define|#
directive|define
name|MACH64_DATATYPE_RGB565
value|4
end_define

begin_define
define|#
directive|define
name|MACH64_DATATYPE_ARGB8888
value|6
end_define

begin_define
define|#
directive|define
name|MACH64_DATATYPE_RGB332
value|7
end_define

begin_define
define|#
directive|define
name|MACH64_DATATYPE_Y8
value|8
end_define

begin_define
define|#
directive|define
name|MACH64_DATATYPE_RGB8
value|9
end_define

begin_define
define|#
directive|define
name|MACH64_DATATYPE_VYUY422
value|11
end_define

begin_define
define|#
directive|define
name|MACH64_DATATYPE_YVYU422
value|12
end_define

begin_define
define|#
directive|define
name|MACH64_DATATYPE_AYUV444
value|14
end_define

begin_define
define|#
directive|define
name|MACH64_DATATYPE_ARGB4444
value|15
end_define

begin_define
define|#
directive|define
name|MACH64_READ
parameter_list|(
name|reg
parameter_list|)
value|DRM_READ32(dev_priv->mmio, (reg) )
end_define

begin_define
define|#
directive|define
name|MACH64_WRITE
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
value|DRM_WRITE32(dev_priv->mmio, (reg), (val) )
end_define

begin_define
define|#
directive|define
name|DWMREG0
value|0x0400
end_define

begin_define
define|#
directive|define
name|DWMREG0_END
value|0x07ff
end_define

begin_define
define|#
directive|define
name|DWMREG1
value|0x0000
end_define

begin_define
define|#
directive|define
name|DWMREG1_END
value|0x03ff
end_define

begin_define
define|#
directive|define
name|ISREG0
parameter_list|(
name|r
parameter_list|)
value|(((r)>= DWMREG0)&& ((r)<= DWMREG0_END))
end_define

begin_define
define|#
directive|define
name|DMAREG0
parameter_list|(
name|r
parameter_list|)
value|(((r) - DWMREG0)>> 2)
end_define

begin_define
define|#
directive|define
name|DMAREG1
parameter_list|(
name|r
parameter_list|)
value|((((r) - DWMREG1)>> 2 ) | 0x0100)
end_define

begin_define
define|#
directive|define
name|DMAREG
parameter_list|(
name|r
parameter_list|)
value|(ISREG0(r) ? DMAREG0(r) : DMAREG1(r))
end_define

begin_define
define|#
directive|define
name|MMREG0
value|0x0000
end_define

begin_define
define|#
directive|define
name|MMREG0_END
value|0x00ff
end_define

begin_define
define|#
directive|define
name|ISMMREG0
parameter_list|(
name|r
parameter_list|)
value|(((r)>= MMREG0)&& ((r)<= MMREG0_END))
end_define

begin_define
define|#
directive|define
name|MMSELECT0
parameter_list|(
name|r
parameter_list|)
value|(((r)<< 2) + DWMREG0)
end_define

begin_define
define|#
directive|define
name|MMSELECT1
parameter_list|(
name|r
parameter_list|)
value|(((((r)& 0xff)<< 2) + DWMREG1))
end_define

begin_define
define|#
directive|define
name|MMSELECT
parameter_list|(
name|r
parameter_list|)
value|(ISMMREG0(r) ? MMSELECT0(r) : MMSELECT1(r))
end_define

begin_comment
comment|/* ================================================================  * DMA constants  */
end_comment

begin_comment
comment|/* DMA descriptor field indices:  * The descriptor fields are loaded into the read-only  * BM_* system bus master registers during a bus-master operation  */
end_comment

begin_define
define|#
directive|define
name|MACH64_DMA_FRAME_BUF_OFFSET
value|0
end_define

begin_comment
comment|/* BM_FRAME_BUF_OFFSET */
end_comment

begin_define
define|#
directive|define
name|MACH64_DMA_SYS_MEM_ADDR
value|1
end_define

begin_comment
comment|/* BM_SYSTEM_MEM_ADDR */
end_comment

begin_define
define|#
directive|define
name|MACH64_DMA_COMMAND
value|2
end_define

begin_comment
comment|/* BM_COMMAND */
end_comment

begin_define
define|#
directive|define
name|MACH64_DMA_RESERVED
value|3
end_define

begin_comment
comment|/* BM_STATUS */
end_comment

begin_comment
comment|/* BM_COMMAND descriptor field flags */
end_comment

begin_define
define|#
directive|define
name|MACH64_DMA_HOLD_OFFSET
value|(1<<30)
end_define

begin_comment
comment|/* Don't increment DMA_FRAME_BUF_OFFSET */
end_comment

begin_define
define|#
directive|define
name|MACH64_DMA_EOL
value|(1<<31)
end_define

begin_comment
comment|/* End of descriptor list flag */
end_comment

begin_define
define|#
directive|define
name|MACH64_DMA_CHUNKSIZE
value|0x1000
end_define

begin_comment
comment|/* 4kB per DMA descriptor */
end_comment

begin_define
define|#
directive|define
name|MACH64_APERTURE_OFFSET
value|0x7ff800
end_define

begin_comment
comment|/* frame-buffer offset for gui-masters */
end_comment

begin_comment
comment|/* ================================================================  * Ring operations  *  * Since the Mach64 bus master engine requires polling, these functions end  * up being called frequently, hence being inline.  */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|mach64_ring_start
parameter_list|(
name|drm_mach64_private_t
modifier|*
name|dev_priv
parameter_list|)
block|{
name|drm_mach64_descriptor_ring_t
modifier|*
name|ring
init|=
operator|&
name|dev_priv
operator|->
name|ring
decl_stmt|;
name|DRM_DEBUG
argument_list|(
literal|"head_addr: 0x%08x head: %d tail: %d space: %d\n"
argument_list|,
name|ring
operator|->
name|head_addr
argument_list|,
name|ring
operator|->
name|head
argument_list|,
name|ring
operator|->
name|tail
argument_list|,
name|ring
operator|->
name|space
argument_list|)
expr_stmt|;
if|if
condition|(
name|mach64_do_wait_for_idle
argument_list|(
name|dev_priv
argument_list|)
operator|<
literal|0
condition|)
block|{
name|mach64_do_engine_reset
argument_list|(
name|dev_priv
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|dev_priv
operator|->
name|driver_mode
operator|!=
name|MACH64_MODE_MMIO
condition|)
block|{
comment|/* enable bus mastering and block 1 registers */
name|MACH64_WRITE
argument_list|(
name|MACH64_BUS_CNTL
argument_list|,
operator|(
name|MACH64_READ
argument_list|(
name|MACH64_BUS_CNTL
argument_list|)
operator|&
operator|~
name|MACH64_BUS_MASTER_DIS
operator|)
operator||
name|MACH64_BUS_EXT_REG_EN
argument_list|)
expr_stmt|;
name|mach64_do_wait_for_idle
argument_list|(
name|dev_priv
argument_list|)
expr_stmt|;
block|}
comment|/* reset descriptor table ring head */
name|MACH64_WRITE
argument_list|(
name|MACH64_BM_GUI_TABLE_CMD
argument_list|,
name|ring
operator|->
name|head_addr
operator||
name|MACH64_CIRCULAR_BUF_SIZE_16KB
argument_list|)
expr_stmt|;
name|dev_priv
operator|->
name|ring_running
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|mach64_ring_resume
parameter_list|(
name|drm_mach64_private_t
modifier|*
name|dev_priv
parameter_list|,
name|drm_mach64_descriptor_ring_t
modifier|*
name|ring
parameter_list|)
block|{
name|DRM_DEBUG
argument_list|(
literal|"head_addr: 0x%08x head: %d tail: %d space: %d\n"
argument_list|,
name|ring
operator|->
name|head_addr
argument_list|,
name|ring
operator|->
name|head
argument_list|,
name|ring
operator|->
name|tail
argument_list|,
name|ring
operator|->
name|space
argument_list|)
expr_stmt|;
comment|/* reset descriptor table ring head */
name|MACH64_WRITE
argument_list|(
name|MACH64_BM_GUI_TABLE_CMD
argument_list|,
name|ring
operator|->
name|head_addr
operator||
name|MACH64_CIRCULAR_BUF_SIZE_16KB
argument_list|)
expr_stmt|;
if|if
condition|(
name|dev_priv
operator|->
name|driver_mode
operator|==
name|MACH64_MODE_MMIO
condition|)
block|{
name|mach64_do_dispatch_pseudo_dma
argument_list|(
name|dev_priv
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* enable GUI bus mastering, and sync the bus master to the GUI */
name|MACH64_WRITE
argument_list|(
name|MACH64_SRC_CNTL
argument_list|,
name|MACH64_SRC_BM_ENABLE
operator||
name|MACH64_SRC_BM_SYNC
operator||
name|MACH64_SRC_BM_OP_SYSTEM_TO_REG
argument_list|)
expr_stmt|;
comment|/* kick off the transfer */
name|MACH64_WRITE
argument_list|(
name|MACH64_DST_HEIGHT_WIDTH
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|dev_priv
operator|->
name|driver_mode
operator|==
name|MACH64_MODE_DMA_SYNC
condition|)
block|{
if|if
condition|(
operator|(
name|mach64_do_wait_for_idle
argument_list|(
name|dev_priv
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
name|DRM_ERROR
argument_list|(
literal|"idle failed, resetting engine\n"
argument_list|)
expr_stmt|;
name|mach64_dump_engine_info
argument_list|(
name|dev_priv
argument_list|)
expr_stmt|;
name|mach64_do_engine_reset
argument_list|(
name|dev_priv
argument_list|)
expr_stmt|;
return|return;
block|}
name|mach64_do_release_used_buffers
argument_list|(
name|dev_priv
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_comment
comment|/**  * Poll the ring head and make sure the bus master is alive.  *   * Mach64's bus master engine will stop if there are no more entries to process.  * This function polls the engine for the last processed entry and calls   * mach64_ring_resume if there is an unprocessed entry.  *   * Note also that, since we update the ring tail while the bus master engine is   * in operation, it is possible that the last tail update was too late to be   * processed, and the bus master engine stops at the previous tail position.   * Therefore it is important to call this function frequently.   */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|mach64_ring_tick
parameter_list|(
name|drm_mach64_private_t
modifier|*
name|dev_priv
parameter_list|,
name|drm_mach64_descriptor_ring_t
modifier|*
name|ring
parameter_list|)
block|{
name|DRM_DEBUG
argument_list|(
literal|"head_addr: 0x%08x head: %d tail: %d space: %d\n"
argument_list|,
name|ring
operator|->
name|head_addr
argument_list|,
name|ring
operator|->
name|head
argument_list|,
name|ring
operator|->
name|tail
argument_list|,
name|ring
operator|->
name|space
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|dev_priv
operator|->
name|ring_running
condition|)
block|{
name|mach64_ring_start
argument_list|(
name|dev_priv
argument_list|)
expr_stmt|;
if|if
condition|(
name|ring
operator|->
name|head
operator|!=
name|ring
operator|->
name|tail
condition|)
block|{
name|mach64_ring_resume
argument_list|(
name|dev_priv
argument_list|,
name|ring
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* GUI_ACTIVE must be read before BM_GUI_TABLE to 		 * correctly determine the ring head 		 */
name|int
name|gui_active
init|=
name|MACH64_READ
argument_list|(
name|MACH64_GUI_STAT
argument_list|)
operator|&
name|MACH64_GUI_ACTIVE
decl_stmt|;
name|ring
operator|->
name|head_addr
operator|=
name|MACH64_READ
argument_list|(
name|MACH64_BM_GUI_TABLE
argument_list|)
operator|&
literal|0xfffffff0
expr_stmt|;
if|if
condition|(
name|gui_active
condition|)
block|{
comment|/* If not idle, BM_GUI_TABLE points one descriptor 			 * past the current head 			 */
if|if
condition|(
name|ring
operator|->
name|head_addr
operator|==
name|ring
operator|->
name|start_addr
condition|)
block|{
name|ring
operator|->
name|head_addr
operator|+=
name|ring
operator|->
name|size
expr_stmt|;
block|}
name|ring
operator|->
name|head_addr
operator|-=
literal|4
operator|*
sizeof|sizeof
argument_list|(
name|u32
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|ring
operator|->
name|head_addr
operator|<
name|ring
operator|->
name|start_addr
operator|||
name|ring
operator|->
name|head_addr
operator|>=
name|ring
operator|->
name|start_addr
operator|+
name|ring
operator|->
name|size
condition|)
block|{
name|DRM_ERROR
argument_list|(
literal|"bad ring head address: 0x%08x\n"
argument_list|,
name|ring
operator|->
name|head_addr
argument_list|)
expr_stmt|;
name|mach64_dump_ring_info
argument_list|(
name|dev_priv
argument_list|)
expr_stmt|;
name|mach64_do_engine_reset
argument_list|(
name|dev_priv
argument_list|)
expr_stmt|;
return|return;
block|}
name|ring
operator|->
name|head
operator|=
operator|(
name|ring
operator|->
name|head_addr
operator|-
name|ring
operator|->
name|start_addr
operator|)
operator|/
sizeof|sizeof
argument_list|(
name|u32
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|gui_active
operator|&&
name|ring
operator|->
name|head
operator|!=
name|ring
operator|->
name|tail
condition|)
block|{
name|mach64_ring_resume
argument_list|(
name|dev_priv
argument_list|,
name|ring
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|mach64_ring_stop
parameter_list|(
name|drm_mach64_private_t
modifier|*
name|dev_priv
parameter_list|)
block|{
name|DRM_DEBUG
argument_list|(
literal|"head_addr: 0x%08x head: %d tail: %d space: %d\n"
argument_list|,
name|dev_priv
operator|->
name|ring
operator|.
name|head_addr
argument_list|,
name|dev_priv
operator|->
name|ring
operator|.
name|head
argument_list|,
name|dev_priv
operator|->
name|ring
operator|.
name|tail
argument_list|,
name|dev_priv
operator|->
name|ring
operator|.
name|space
argument_list|)
expr_stmt|;
comment|/* restore previous SRC_CNTL to disable busmastering */
name|mach64_do_wait_for_fifo
argument_list|(
name|dev_priv
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|MACH64_WRITE
argument_list|(
name|MACH64_SRC_CNTL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* disable busmastering but keep the block 1 registers enabled */
name|mach64_do_wait_for_idle
argument_list|(
name|dev_priv
argument_list|)
expr_stmt|;
name|MACH64_WRITE
argument_list|(
name|MACH64_BUS_CNTL
argument_list|,
name|MACH64_READ
argument_list|(
name|MACH64_BUS_CNTL
argument_list|)
operator||
name|MACH64_BUS_MASTER_DIS
operator||
name|MACH64_BUS_EXT_REG_EN
argument_list|)
expr_stmt|;
name|dev_priv
operator|->
name|ring_running
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|mach64_update_ring_snapshot
parameter_list|(
name|drm_mach64_private_t
modifier|*
name|dev_priv
parameter_list|)
block|{
name|drm_mach64_descriptor_ring_t
modifier|*
name|ring
init|=
operator|&
name|dev_priv
operator|->
name|ring
decl_stmt|;
name|DRM_DEBUG
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|mach64_ring_tick
argument_list|(
name|dev_priv
argument_list|,
name|ring
argument_list|)
expr_stmt|;
name|ring
operator|->
name|space
operator|=
operator|(
name|ring
operator|->
name|head
operator|-
name|ring
operator|->
name|tail
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|u32
argument_list|)
expr_stmt|;
if|if
condition|(
name|ring
operator|->
name|space
operator|<=
literal|0
condition|)
block|{
name|ring
operator|->
name|space
operator|+=
name|ring
operator|->
name|size
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* ================================================================  * DMA macros  *   * Mach64's ring buffer doesn't take register writes directly. These   * have to be written indirectly in DMA buffers. These macros simplify   * the task of setting up a buffer, writing commands to it, and   * queuing the buffer in the ring.   */
end_comment

begin_define
define|#
directive|define
name|DMALOCALS
define|\
value|drm_mach64_freelist_t *_entry = NULL;	\ 	struct drm_buf *_buf = NULL;		\ 	u32 *_buf_wptr; int _outcount
end_define

begin_define
define|#
directive|define
name|GETBUFPTR
parameter_list|(
name|__buf
parameter_list|)
define|\
value|((dev_priv->is_pci) ?							\ 	((u32 *)(__buf)->address) :					\ 	((u32 *)((char *)dev_priv->dev_buffers->handle + (__buf)->offset)))
end_define

begin_define
define|#
directive|define
name|GETBUFADDR
parameter_list|(
name|__buf
parameter_list|)
value|((u32)(__buf)->bus_address)
end_define

begin_define
define|#
directive|define
name|GETRINGOFFSET
parameter_list|()
value|(_entry->ring_ofs)
end_define

begin_function
specifier|static
name|__inline__
name|int
name|mach64_find_pending_buf_entry
parameter_list|(
name|drm_mach64_private_t
modifier|*
name|dev_priv
parameter_list|,
name|drm_mach64_freelist_t
modifier|*
modifier|*
name|entry
parameter_list|,
name|struct
name|drm_buf
modifier|*
name|buf
parameter_list|)
block|{
name|struct
name|list_head
modifier|*
name|ptr
decl_stmt|;
if|#
directive|if
name|MACH64_EXTRA_CHECKING
if|if
condition|(
name|list_empty
argument_list|(
operator|&
name|dev_priv
operator|->
name|pending
argument_list|)
condition|)
block|{
name|DRM_ERROR
argument_list|(
literal|"Empty pending list in \n"
argument_list|)
expr_stmt|;
return|return
operator|-
name|EINVAL
return|;
block|}
endif|#
directive|endif
name|ptr
operator|=
name|dev_priv
operator|->
name|pending
operator|.
name|prev
expr_stmt|;
operator|*
name|entry
operator|=
name|list_entry
argument_list|(
name|ptr
argument_list|,
name|drm_mach64_freelist_t
argument_list|,
name|list
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
operator|*
name|entry
operator|)
operator|->
name|buf
operator|!=
name|buf
condition|)
block|{
if|if
condition|(
name|ptr
operator|==
operator|&
name|dev_priv
operator|->
name|pending
condition|)
block|{
return|return
operator|-
name|EFAULT
return|;
block|}
name|ptr
operator|=
name|ptr
operator|->
name|prev
expr_stmt|;
operator|*
name|entry
operator|=
name|list_entry
argument_list|(
name|ptr
argument_list|,
name|drm_mach64_freelist_t
argument_list|,
name|list
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_define
define|#
directive|define
name|DMASETPTR
parameter_list|(
name|_p
parameter_list|)
define|\
value|do {						\ 	_buf = (_p);				\ 	_outcount = 0;				\ 	_buf_wptr = GETBUFPTR( _buf );		\ } while(0)
end_define

begin_comment
comment|/* FIXME: use a private set of smaller buffers for state emits, clears, and swaps? */
end_comment

begin_define
define|#
directive|define
name|DMAGETPTR
parameter_list|(
name|file_priv
parameter_list|,
name|dev_priv
parameter_list|,
name|n
parameter_list|)
define|\
value|do {									\ 	if ( MACH64_VERBOSE ) {						\ 		DRM_INFO( "DMAGETPTR( %d )\n", (n) );			\ 	}								\ 	_buf = mach64_freelist_get( dev_priv );				\ 	if (_buf == NULL) {						\ 		DRM_ERROR("couldn't get buffer in DMAGETPTR\n");	\ 		return -EAGAIN;					\ 	}								\ 	if (_buf->pending) {						\ 	        DRM_ERROR("pending buf in DMAGETPTR\n");		\ 		return -EFAULT;					\ 	}								\ 	_buf->file_priv = file_priv;					\ 	_outcount = 0;							\ 									\         _buf_wptr = GETBUFPTR( _buf );					\ } while (0)
end_define

begin_define
define|#
directive|define
name|DMAOUTREG
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|do {								\ 	if ( MACH64_VERBOSE ) {					\ 		DRM_INFO( "   DMAOUTREG( 0x%x = 0x%08x )\n",	\ 			  reg, val );				\ 	}							\ 	_buf_wptr[_outcount++] = cpu_to_le32(DMAREG(reg));	\ 	_buf_wptr[_outcount++] = cpu_to_le32((val));		\ 	_buf->used += 8;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|DMAADVANCE
parameter_list|(
name|dev_priv
parameter_list|,
name|_discard
parameter_list|)
define|\
value|do {								\ 		struct list_head *ptr;					\ 		int ret;						\ 									\ 		if ( MACH64_VERBOSE ) {					\ 			DRM_INFO( "DMAADVANCE() in \n" );		\ 		}							\ 									\ 		if (_buf->used<= 0) {					\ 			DRM_ERROR( "DMAADVANCE(): sending empty buf %d\n", \ 				   _buf->idx );				\ 			return -EFAULT;					\ 		}							\ 		if (_buf->pending) {					\
comment|/* This is a resued buffer, so we need to find it in the pending list */
value|\ 			if ((ret = mach64_find_pending_buf_entry(dev_priv,&_entry, _buf))) { \ 				DRM_ERROR( "DMAADVANCE(): couldn't find pending buf %d\n", _buf->idx );	\ 				return ret;				\ 			}						\ 			if (_entry->discard) {				\ 				DRM_ERROR( "DMAADVANCE(): sending discarded pending buf %d\n", _buf->idx ); \ 				return -EFAULT;				\ 			}						\ 		} else {						\ 			if (list_empty(&dev_priv->placeholders)) {	\ 				DRM_ERROR( "DMAADVANCE(): empty placeholder list\n"); \ 				return -EFAULT;				\ 			}						\ 			ptr = dev_priv->placeholders.next;		\ 			list_del(ptr);					\ 			_entry = list_entry(ptr, drm_mach64_freelist_t, list); \ 			_buf->pending = 1;				\ 			_entry->buf = _buf;				\ 			list_add_tail(ptr,&dev_priv->pending);		\ 		}							\ 		_entry->discard = (_discard);				\ 		if ((ret = mach64_add_buf_to_ring( dev_priv, _entry ))) \ 			return ret;					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|DMADISCARDBUF
parameter_list|()
define|\
value|do {								\ 		if (_entry == NULL) {					\ 			int ret;					\ 			if ((ret = mach64_find_pending_buf_entry(dev_priv,&_entry, _buf))) { \ 				DRM_ERROR( "couldn't find pending buf %d\n", \ 					   _buf->idx );			\ 				return ret;				\ 			}						\ 		}							\ 		_entry->discard = 1;					\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|DMAADVANCEHOSTDATA
parameter_list|(
name|dev_priv
parameter_list|)
define|\
value|do {								\ 		struct list_head *ptr;					\ 		int ret;						\ 									\ 		if ( MACH64_VERBOSE ) {					\ 			DRM_INFO( "DMAADVANCEHOSTDATA() in \n" );	\ 		}							\ 									\ 		if (_buf->used<= 0) {					\ 			DRM_ERROR( "DMAADVANCEHOSTDATA(): sending empty buf %d\n", _buf->idx );	\ 			return -EFAULT;					\ 		}							\ 		if (list_empty(&dev_priv->placeholders)) {		\ 			DRM_ERROR( "empty placeholder list in DMAADVANCEHOSTDATA()\n" ); \ 			return -EFAULT;					\ 		}							\ 									\ 		ptr = dev_priv->placeholders.next;			\ 		list_del(ptr);						\ 		_entry = list_entry(ptr, drm_mach64_freelist_t, list);	\ 		_entry->buf = _buf;					\ 		_entry->buf->pending = 1;				\ 		list_add_tail(ptr,&dev_priv->pending);			\ 		_entry->discard = 1;					\ 		if ((ret = mach64_add_hostdata_buf_to_ring( dev_priv, _entry ))) \ 			return ret;					\ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MACH64_DRV_H__ */
end_comment

end_unit

