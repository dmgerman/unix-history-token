begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* r128_drv.h -- Private header for r128 driver -*- linux-c -*-  * Created: Mon Dec 13 09:51:11 1999 by faith@precisioninsight.com  *  * Copyright 1999 Precision Insight, Inc., Cedar Park, Texas.  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All rights reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Rickard E. (Rik) Faith<faith@valinux.com>  *    Kevin E. Martin<martin@valinux.com>  *    Gareth Hughes<gareth@valinux.com>  *    Michel Dänzer<daenzerm@student.ethz.ch>  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__R128_DRV_H__
end_ifndef

begin_define
define|#
directive|define
name|__R128_DRV_H__
end_define

begin_define
define|#
directive|define
name|GET_RING_HEAD
parameter_list|(
name|ring
parameter_list|)
value|DRM_READ32(  (ring)->ring_rptr, 0 )
end_define

begin_comment
comment|/* (ring)->head */
end_comment

begin_define
define|#
directive|define
name|SET_RING_HEAD
parameter_list|(
name|ring
parameter_list|,
name|val
parameter_list|)
value|DRM_WRITE32( (ring)->ring_rptr, 0, (val) )
end_define

begin_comment
comment|/* (ring)->head */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|drm_r128_freelist
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
name|drm_r128_freelist
modifier|*
name|next
decl_stmt|;
name|struct
name|drm_r128_freelist
modifier|*
name|prev
decl_stmt|;
block|}
name|drm_r128_freelist_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_r128_ring_buffer
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
specifier|volatile
name|u32
modifier|*
name|head
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
name|drm_local_map_t
modifier|*
name|ring_rptr
decl_stmt|;
block|}
name|drm_r128_ring_buffer_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_r128_private
block|{
name|drm_r128_ring_buffer_t
name|ring
decl_stmt|;
name|drm_r128_sarea_t
modifier|*
name|sarea_priv
decl_stmt|;
name|int
name|cce_mode
decl_stmt|;
name|int
name|cce_fifo_size
decl_stmt|;
name|int
name|cce_running
decl_stmt|;
name|drm_r128_freelist_t
modifier|*
name|head
decl_stmt|;
name|drm_r128_freelist_t
modifier|*
name|tail
decl_stmt|;
name|int
name|usec_timeout
decl_stmt|;
name|int
name|is_pci
decl_stmt|;
name|unsigned
name|long
name|phys_pci_gart
decl_stmt|;
name|dma_addr_t
name|bus_pci_gart
decl_stmt|;
name|unsigned
name|long
name|cce_buffers_offset
decl_stmt|;
name|atomic_t
name|idle_count
decl_stmt|;
name|int
name|page_flipping
decl_stmt|;
name|int
name|current_page
decl_stmt|;
name|u32
name|crtc_offset
decl_stmt|;
name|u32
name|crtc_offset_cntl
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
name|unsigned
name|int
name|span_offset
decl_stmt|;
name|u32
name|front_pitch_offset_c
decl_stmt|;
name|u32
name|back_pitch_offset_c
decl_stmt|;
name|u32
name|depth_pitch_offset_c
decl_stmt|;
name|u32
name|span_pitch_offset_c
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
name|cce_ring
decl_stmt|;
name|drm_local_map_t
modifier|*
name|ring_rptr
decl_stmt|;
name|drm_local_map_t
modifier|*
name|buffers
decl_stmt|;
name|drm_local_map_t
modifier|*
name|agp_textures
decl_stmt|;
block|}
name|drm_r128_private_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_r128_buf_priv
block|{
name|u32
name|age
decl_stmt|;
name|int
name|prim
decl_stmt|;
name|int
name|discard
decl_stmt|;
name|int
name|dispatched
decl_stmt|;
name|drm_r128_freelist_t
modifier|*
name|list_entry
decl_stmt|;
block|}
name|drm_r128_buf_priv_t
typedef|;
end_typedef

begin_comment
comment|/* r128_cce.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|r128_cce_init
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|r128_cce_start
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|r128_cce_stop
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|r128_cce_reset
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|r128_cce_idle
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|r128_engine_reset
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|r128_fullscreen
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|r128_cce_buffers
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|r128_getparam
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|r128_freelist_reset
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
name|r128_freelist_get
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
name|r128_wait_ring
parameter_list|(
name|drm_r128_private_t
modifier|*
name|dev_priv
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline__
name|void
name|r128_update_ring_snapshot
parameter_list|(
name|drm_r128_ring_buffer_t
modifier|*
name|ring
parameter_list|)
block|{
name|ring
operator|->
name|space
operator|=
operator|(
name|GET_RING_HEAD
argument_list|(
name|ring
argument_list|)
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
name|ring
operator|->
name|space
operator|+=
name|ring
operator|->
name|size
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|extern
name|int
name|r128_do_cce_idle
parameter_list|(
name|drm_r128_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|r128_do_cleanup_cce
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
name|r128_do_cleanup_pageflip
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r128_state.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|r128_cce_clear
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|r128_cce_swap
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|r128_cce_flip
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|r128_cce_vertex
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|r128_cce_indices
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|r128_cce_blit
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|r128_cce_depth
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|r128_cce_stipple
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|r128_cce_indirect
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Register definitions, register access macros and drmAddMap constants  * for Rage 128 kernel driver.  */
end_comment

begin_define
define|#
directive|define
name|R128_AUX_SC_CNTL
value|0x1660
end_define

begin_define
define|#
directive|define
name|R128_AUX1_SC_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R128_AUX1_SC_MODE_OR
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|R128_AUX1_SC_MODE_NAND
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|R128_AUX2_SC_EN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|R128_AUX2_SC_MODE_OR
value|(0<< 3)
end_define

begin_define
define|#
directive|define
name|R128_AUX2_SC_MODE_NAND
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|R128_AUX3_SC_EN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|R128_AUX3_SC_MODE_OR
value|(0<< 5)
end_define

begin_define
define|#
directive|define
name|R128_AUX3_SC_MODE_NAND
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|R128_AUX1_SC_LEFT
value|0x1664
end_define

begin_define
define|#
directive|define
name|R128_AUX1_SC_RIGHT
value|0x1668
end_define

begin_define
define|#
directive|define
name|R128_AUX1_SC_TOP
value|0x166c
end_define

begin_define
define|#
directive|define
name|R128_AUX1_SC_BOTTOM
value|0x1670
end_define

begin_define
define|#
directive|define
name|R128_AUX2_SC_LEFT
value|0x1674
end_define

begin_define
define|#
directive|define
name|R128_AUX2_SC_RIGHT
value|0x1678
end_define

begin_define
define|#
directive|define
name|R128_AUX2_SC_TOP
value|0x167c
end_define

begin_define
define|#
directive|define
name|R128_AUX2_SC_BOTTOM
value|0x1680
end_define

begin_define
define|#
directive|define
name|R128_AUX3_SC_LEFT
value|0x1684
end_define

begin_define
define|#
directive|define
name|R128_AUX3_SC_RIGHT
value|0x1688
end_define

begin_define
define|#
directive|define
name|R128_AUX3_SC_TOP
value|0x168c
end_define

begin_define
define|#
directive|define
name|R128_AUX3_SC_BOTTOM
value|0x1690
end_define

begin_define
define|#
directive|define
name|R128_BRUSH_DATA0
value|0x1480
end_define

begin_define
define|#
directive|define
name|R128_BUS_CNTL
value|0x0030
end_define

begin_define
define|#
directive|define
name|R128_BUS_MASTER_DIS
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|R128_CLOCK_CNTL_INDEX
value|0x0008
end_define

begin_define
define|#
directive|define
name|R128_CLOCK_CNTL_DATA
value|0x000c
end_define

begin_define
define|#
directive|define
name|R128_PLL_WR_EN
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|R128_CONSTANT_COLOR_C
value|0x1d34
end_define

begin_define
define|#
directive|define
name|R128_CRTC_OFFSET
value|0x0224
end_define

begin_define
define|#
directive|define
name|R128_CRTC_OFFSET_CNTL
value|0x0228
end_define

begin_define
define|#
directive|define
name|R128_CRTC_OFFSET_FLIP_CNTL
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|R128_DP_GUI_MASTER_CNTL
value|0x146c
end_define

begin_define
define|#
directive|define
name|R128_GMC_SRC_PITCH_OFFSET_CNTL
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|R128_GMC_DST_PITCH_OFFSET_CNTL
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|R128_GMC_BRUSH_SOLID_COLOR
value|(13<<  4)
end_define

begin_define
define|#
directive|define
name|R128_GMC_BRUSH_NONE
value|(15<<  4)
end_define

begin_define
define|#
directive|define
name|R128_GMC_DST_16BPP
value|(4<<  8)
end_define

begin_define
define|#
directive|define
name|R128_GMC_DST_24BPP
value|(5<<  8)
end_define

begin_define
define|#
directive|define
name|R128_GMC_DST_32BPP
value|(6<<  8)
end_define

begin_define
define|#
directive|define
name|R128_GMC_DST_DATATYPE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|R128_GMC_SRC_DATATYPE_COLOR
value|(3<< 12)
end_define

begin_define
define|#
directive|define
name|R128_DP_SRC_SOURCE_MEMORY
value|(2<< 24)
end_define

begin_define
define|#
directive|define
name|R128_DP_SRC_SOURCE_HOST_DATA
value|(3<< 24)
end_define

begin_define
define|#
directive|define
name|R128_GMC_CLR_CMP_CNTL_DIS
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|R128_GMC_AUX_CLIP_DIS
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|R128_GMC_WR_MSK_DIS
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|R128_ROP3_S
value|0x00cc0000
end_define

begin_define
define|#
directive|define
name|R128_ROP3_P
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|R128_DP_WRITE_MASK
value|0x16cc
end_define

begin_define
define|#
directive|define
name|R128_DST_PITCH_OFFSET_C
value|0x1c80
end_define

begin_define
define|#
directive|define
name|R128_DST_TILE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|R128_GEN_INT_CNTL
value|0x0040
end_define

begin_define
define|#
directive|define
name|R128_CRTC_VBLANK_INT_EN
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|R128_GEN_INT_STATUS
value|0x0044
end_define

begin_define
define|#
directive|define
name|R128_CRTC_VBLANK_INT
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|R128_CRTC_VBLANK_INT_AK
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|R128_GEN_RESET_CNTL
value|0x00f0
end_define

begin_define
define|#
directive|define
name|R128_SOFT_RESET_GUI
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|R128_GUI_SCRATCH_REG0
value|0x15e0
end_define

begin_define
define|#
directive|define
name|R128_GUI_SCRATCH_REG1
value|0x15e4
end_define

begin_define
define|#
directive|define
name|R128_GUI_SCRATCH_REG2
value|0x15e8
end_define

begin_define
define|#
directive|define
name|R128_GUI_SCRATCH_REG3
value|0x15ec
end_define

begin_define
define|#
directive|define
name|R128_GUI_SCRATCH_REG4
value|0x15f0
end_define

begin_define
define|#
directive|define
name|R128_GUI_SCRATCH_REG5
value|0x15f4
end_define

begin_define
define|#
directive|define
name|R128_GUI_STAT
value|0x1740
end_define

begin_define
define|#
directive|define
name|R128_GUI_FIFOCNT_MASK
value|0x0fff
end_define

begin_define
define|#
directive|define
name|R128_GUI_ACTIVE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|R128_MCLK_CNTL
value|0x000f
end_define

begin_define
define|#
directive|define
name|R128_FORCE_GCP
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|R128_FORCE_PIPE3D_CP
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|R128_FORCE_RCP
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|R128_PC_GUI_CTLSTAT
value|0x1748
end_define

begin_define
define|#
directive|define
name|R128_PC_NGUI_CTLSTAT
value|0x0184
end_define

begin_define
define|#
directive|define
name|R128_PC_FLUSH_GUI
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|R128_PC_RI_GUI
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|R128_PC_FLUSH_ALL
value|0x00ff
end_define

begin_define
define|#
directive|define
name|R128_PC_BUSY
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|R128_PCI_GART_PAGE
value|0x017c
end_define

begin_define
define|#
directive|define
name|R128_PRIM_TEX_CNTL_C
value|0x1cb0
end_define

begin_define
define|#
directive|define
name|R128_SCALE_3D_CNTL
value|0x1a00
end_define

begin_define
define|#
directive|define
name|R128_SEC_TEX_CNTL_C
value|0x1d00
end_define

begin_define
define|#
directive|define
name|R128_SEC_TEXTURE_BORDER_COLOR_C
value|0x1d3c
end_define

begin_define
define|#
directive|define
name|R128_SETUP_CNTL
value|0x1bc4
end_define

begin_define
define|#
directive|define
name|R128_STEN_REF_MASK_C
value|0x1d40
end_define

begin_define
define|#
directive|define
name|R128_TEX_CNTL_C
value|0x1c9c
end_define

begin_define
define|#
directive|define
name|R128_TEX_CACHE_FLUSH
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|R128_WAIT_UNTIL
value|0x1720
end_define

begin_define
define|#
directive|define
name|R128_EVENT_CRTC_OFFSET
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R128_WINDOW_XY_OFFSET
value|0x1bcc
end_define

begin_comment
comment|/* CCE registers  */
end_comment

begin_define
define|#
directive|define
name|R128_PM4_BUFFER_OFFSET
value|0x0700
end_define

begin_define
define|#
directive|define
name|R128_PM4_BUFFER_CNTL
value|0x0704
end_define

begin_define
define|#
directive|define
name|R128_PM4_MASK
value|(15<< 28)
end_define

begin_define
define|#
directive|define
name|R128_PM4_NONPM4
value|(0<< 28)
end_define

begin_define
define|#
directive|define
name|R128_PM4_192PIO
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|R128_PM4_192BM
value|(2<< 28)
end_define

begin_define
define|#
directive|define
name|R128_PM4_128PIO_64INDBM
value|(3<< 28)
end_define

begin_define
define|#
directive|define
name|R128_PM4_128BM_64INDBM
value|(4<< 28)
end_define

begin_define
define|#
directive|define
name|R128_PM4_64PIO_128INDBM
value|(5<< 28)
end_define

begin_define
define|#
directive|define
name|R128_PM4_64BM_128INDBM
value|(6<< 28)
end_define

begin_define
define|#
directive|define
name|R128_PM4_64PIO_64VCBM_64INDBM
value|(7<< 28)
end_define

begin_define
define|#
directive|define
name|R128_PM4_64BM_64VCBM_64INDBM
value|(8<< 28)
end_define

begin_define
define|#
directive|define
name|R128_PM4_64PIO_64VCPIO_64INDPIO
value|(15<< 28)
end_define

begin_define
define|#
directive|define
name|R128_PM4_BUFFER_WM_CNTL
value|0x0708
end_define

begin_define
define|#
directive|define
name|R128_WMA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R128_WMB_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|R128_WMC_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|R128_WB_WM_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|R128_PM4_BUFFER_DL_RPTR_ADDR
value|0x070c
end_define

begin_define
define|#
directive|define
name|R128_PM4_BUFFER_DL_RPTR
value|0x0710
end_define

begin_define
define|#
directive|define
name|R128_PM4_BUFFER_DL_WPTR
value|0x0714
end_define

begin_define
define|#
directive|define
name|R128_PM4_BUFFER_DL_DONE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|R128_PM4_VC_FPU_SETUP
value|0x071c
end_define

begin_define
define|#
directive|define
name|R128_PM4_IW_INDOFF
value|0x0738
end_define

begin_define
define|#
directive|define
name|R128_PM4_IW_INDSIZE
value|0x073c
end_define

begin_define
define|#
directive|define
name|R128_PM4_STAT
value|0x07b8
end_define

begin_define
define|#
directive|define
name|R128_PM4_FIFOCNT_MASK
value|0x0fff
end_define

begin_define
define|#
directive|define
name|R128_PM4_BUSY
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|R128_PM4_GUI_ACTIVE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|R128_PM4_MICROCODE_ADDR
value|0x07d4
end_define

begin_define
define|#
directive|define
name|R128_PM4_MICROCODE_RADDR
value|0x07d8
end_define

begin_define
define|#
directive|define
name|R128_PM4_MICROCODE_DATAH
value|0x07dc
end_define

begin_define
define|#
directive|define
name|R128_PM4_MICROCODE_DATAL
value|0x07e0
end_define

begin_define
define|#
directive|define
name|R128_PM4_BUFFER_ADDR
value|0x07f0
end_define

begin_define
define|#
directive|define
name|R128_PM4_MICRO_CNTL
value|0x07fc
end_define

begin_define
define|#
directive|define
name|R128_PM4_MICRO_FREERUN
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|R128_PM4_FIFO_DATA_EVEN
value|0x1000
end_define

begin_define
define|#
directive|define
name|R128_PM4_FIFO_DATA_ODD
value|0x1004
end_define

begin_comment
comment|/* CCE command packets  */
end_comment

begin_define
define|#
directive|define
name|R128_CCE_PACKET0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R128_CCE_PACKET1
value|0x40000000
end_define

begin_define
define|#
directive|define
name|R128_CCE_PACKET2
value|0x80000000
end_define

begin_define
define|#
directive|define
name|R128_CCE_PACKET3
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|R128_CNTL_HOSTDATA_BLT
value|0x00009400
end_define

begin_define
define|#
directive|define
name|R128_CNTL_PAINT_MULTI
value|0x00009A00
end_define

begin_define
define|#
directive|define
name|R128_CNTL_BITBLT_MULTI
value|0x00009B00
end_define

begin_define
define|#
directive|define
name|R128_3D_RNDR_GEN_INDX_PRIM
value|0x00002300
end_define

begin_define
define|#
directive|define
name|R128_CCE_PACKET_MASK
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|R128_CCE_PACKET_COUNT_MASK
value|0x3fff0000
end_define

begin_define
define|#
directive|define
name|R128_CCE_PACKET0_REG_MASK
value|0x000007ff
end_define

begin_define
define|#
directive|define
name|R128_CCE_PACKET1_REG0_MASK
value|0x000007ff
end_define

begin_define
define|#
directive|define
name|R128_CCE_PACKET1_REG1_MASK
value|0x003ff800
end_define

begin_define
define|#
directive|define
name|R128_CCE_VC_CNTL_PRIM_TYPE_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R128_CCE_VC_CNTL_PRIM_TYPE_POINT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|R128_CCE_VC_CNTL_PRIM_TYPE_LINE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|R128_CCE_VC_CNTL_PRIM_TYPE_POLY_LINE
value|0x00000003
end_define

begin_define
define|#
directive|define
name|R128_CCE_VC_CNTL_PRIM_TYPE_TRI_LIST
value|0x00000004
end_define

begin_define
define|#
directive|define
name|R128_CCE_VC_CNTL_PRIM_TYPE_TRI_FAN
value|0x00000005
end_define

begin_define
define|#
directive|define
name|R128_CCE_VC_CNTL_PRIM_TYPE_TRI_STRIP
value|0x00000006
end_define

begin_define
define|#
directive|define
name|R128_CCE_VC_CNTL_PRIM_TYPE_TRI_TYPE2
value|0x00000007
end_define

begin_define
define|#
directive|define
name|R128_CCE_VC_CNTL_PRIM_WALK_IND
value|0x00000010
end_define

begin_define
define|#
directive|define
name|R128_CCE_VC_CNTL_PRIM_WALK_LIST
value|0x00000020
end_define

begin_define
define|#
directive|define
name|R128_CCE_VC_CNTL_PRIM_WALK_RING
value|0x00000030
end_define

begin_define
define|#
directive|define
name|R128_CCE_VC_CNTL_NUM_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|R128_DATATYPE_VQ
value|0
end_define

begin_define
define|#
directive|define
name|R128_DATATYPE_CI4
value|1
end_define

begin_define
define|#
directive|define
name|R128_DATATYPE_CI8
value|2
end_define

begin_define
define|#
directive|define
name|R128_DATATYPE_ARGB1555
value|3
end_define

begin_define
define|#
directive|define
name|R128_DATATYPE_RGB565
value|4
end_define

begin_define
define|#
directive|define
name|R128_DATATYPE_RGB888
value|5
end_define

begin_define
define|#
directive|define
name|R128_DATATYPE_ARGB8888
value|6
end_define

begin_define
define|#
directive|define
name|R128_DATATYPE_RGB332
value|7
end_define

begin_define
define|#
directive|define
name|R128_DATATYPE_Y8
value|8
end_define

begin_define
define|#
directive|define
name|R128_DATATYPE_RGB8
value|9
end_define

begin_define
define|#
directive|define
name|R128_DATATYPE_CI16
value|10
end_define

begin_define
define|#
directive|define
name|R128_DATATYPE_YVYU422
value|11
end_define

begin_define
define|#
directive|define
name|R128_DATATYPE_VYUY422
value|12
end_define

begin_define
define|#
directive|define
name|R128_DATATYPE_AYUV444
value|14
end_define

begin_define
define|#
directive|define
name|R128_DATATYPE_ARGB4444
value|15
end_define

begin_comment
comment|/* Constants */
end_comment

begin_define
define|#
directive|define
name|R128_AGP_OFFSET
value|0x02000000
end_define

begin_define
define|#
directive|define
name|R128_WATERMARK_L
value|16
end_define

begin_define
define|#
directive|define
name|R128_WATERMARK_M
value|8
end_define

begin_define
define|#
directive|define
name|R128_WATERMARK_N
value|8
end_define

begin_define
define|#
directive|define
name|R128_WATERMARK_K
value|128
end_define

begin_define
define|#
directive|define
name|R128_MAX_USEC_TIMEOUT
value|100000
end_define

begin_comment
comment|/* 100 ms */
end_comment

begin_define
define|#
directive|define
name|R128_LAST_FRAME_REG
value|R128_GUI_SCRATCH_REG0
end_define

begin_define
define|#
directive|define
name|R128_LAST_DISPATCH_REG
value|R128_GUI_SCRATCH_REG1
end_define

begin_define
define|#
directive|define
name|R128_MAX_VB_AGE
value|0x7fffffff
end_define

begin_define
define|#
directive|define
name|R128_MAX_VB_VERTS
value|(0xffff)
end_define

begin_define
define|#
directive|define
name|R128_RING_HIGH_MARK
value|128
end_define

begin_define
define|#
directive|define
name|R128_PERFORMANCE_BOXES
value|0
end_define

begin_define
define|#
directive|define
name|R128_READ
parameter_list|(
name|reg
parameter_list|)
value|DRM_READ32(  dev_priv->mmio, (reg) )
end_define

begin_define
define|#
directive|define
name|R128_WRITE
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
name|R128_READ8
parameter_list|(
name|reg
parameter_list|)
value|DRM_READ8(   dev_priv->mmio, (reg) )
end_define

begin_define
define|#
directive|define
name|R128_WRITE8
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
value|DRM_WRITE8(  dev_priv->mmio, (reg), (val) )
end_define

begin_define
define|#
directive|define
name|R128_WRITE_PLL
parameter_list|(
name|addr
parameter_list|,
name|val
parameter_list|)
define|\
value|do {									\ 	R128_WRITE8(R128_CLOCK_CNTL_INDEX,				\ 		    ((addr)& 0x1f) | R128_PLL_WR_EN);			\ 	R128_WRITE(R128_CLOCK_CNTL_DATA, (val));			\ } while (0)
end_define

begin_function_decl
specifier|extern
name|int
name|R128_READ_PLL
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|int
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CCE_PACKET0
parameter_list|(
name|reg
parameter_list|,
name|n
parameter_list|)
value|(R128_CCE_PACKET0 |		\ 					 ((n)<< 16) | ((reg)>> 2))
end_define

begin_define
define|#
directive|define
name|CCE_PACKET1
parameter_list|(
name|reg0
parameter_list|,
name|reg1
parameter_list|)
value|(R128_CCE_PACKET1 |		\ 					 (((reg1)>> 2)<< 11) | ((reg0)>> 2))
end_define

begin_define
define|#
directive|define
name|CCE_PACKET2
parameter_list|()
value|(R128_CCE_PACKET2)
end_define

begin_define
define|#
directive|define
name|CCE_PACKET3
parameter_list|(
name|pkt
parameter_list|,
name|n
parameter_list|)
value|(R128_CCE_PACKET3 |		\ 					 (pkt) | ((n)<< 16))
end_define

begin_comment
comment|/* ================================================================  * Misc helper macros  */
end_comment

begin_define
define|#
directive|define
name|RING_SPACE_TEST_WITH_RETURN
parameter_list|(
name|dev_priv
parameter_list|)
define|\
value|do {									\ 	drm_r128_ring_buffer_t *ring =&dev_priv->ring; int i;		\ 	if ( ring->space< ring->high_mark ) {				\ 		for ( i = 0 ; i< dev_priv->usec_timeout ; i++ ) {	\ 			r128_update_ring_snapshot( ring );		\ 			if ( ring->space>= ring->high_mark )		\ 				goto __ring_space_done;			\ 			DRM_UDELAY(1);				\ 		}							\ 		DRM_ERROR( "ring space check failed!\n" );		\ 		return DRM_ERR(EBUSY);				\ 	}								\  __ring_space_done:							\ 	;								\ } while (0)
end_define

begin_define
define|#
directive|define
name|VB_AGE_TEST_WITH_RETURN
parameter_list|(
name|dev_priv
parameter_list|)
define|\
value|do {									\ 	drm_r128_sarea_t *sarea_priv = dev_priv->sarea_priv;		\ 	if ( sarea_priv->last_dispatch>= R128_MAX_VB_AGE ) {		\ 		int __ret = r128_do_cce_idle( dev_priv );		\ 		if ( __ret ) return __ret;				\ 		sarea_priv->last_dispatch = 0;				\ 		r128_freelist_reset( dev );				\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|R128_WAIT_UNTIL_PAGE_FLIPPED
parameter_list|()
value|do {				\ 	OUT_RING( CCE_PACKET0( R128_WAIT_UNTIL, 0 ) );			\ 	OUT_RING( R128_EVENT_CRTC_OFFSET );				\ } while (0)
end_define

begin_comment
comment|/* ================================================================  * Ring control  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__powerpc__
argument_list|)
end_if

begin_define
define|#
directive|define
name|r128_flush_write_combine
parameter_list|()
value|(void) GET_RING_HEAD(&dev_priv->ring )
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|r128_flush_write_combine
parameter_list|()
value|DRM_WRITEMEMORYBARRIER()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|R128_VERBOSE
value|0
end_define

begin_define
define|#
directive|define
name|RING_LOCALS
define|\
value|int write; unsigned int tail_mask; volatile u32 *ring;
end_define

begin_define
define|#
directive|define
name|BEGIN_RING
parameter_list|(
name|n
parameter_list|)
value|do {						\ 	if ( R128_VERBOSE ) {						\ 		DRM_INFO( "BEGIN_RING( %d ) in %s\n",			\ 			   (n), __FUNCTION__ );				\ 	}								\ 	if ( dev_priv->ring.space<= (n) * sizeof(u32) ) {		\ 		r128_wait_ring( dev_priv, (n) * sizeof(u32) );		\ 	}								\ 	dev_priv->ring.space -= (n) * sizeof(u32);			\ 	ring = dev_priv->ring.start;					\ 	write = dev_priv->ring.tail;					\ 	tail_mask = dev_priv->ring.tail_mask;				\ } while (0)
end_define

begin_comment
comment|/* You can set this to zero if you want.  If the card locks up, you'll  * need to keep this set.  It works around a bug in early revs of the  * Rage 128 chipset, where the CCE would read 32 dwords past the end of  * the ring buffer before wrapping around.  */
end_comment

begin_define
define|#
directive|define
name|R128_BROKEN_CCE
value|1
end_define

begin_define
define|#
directive|define
name|ADVANCE_RING
parameter_list|()
value|do {						\ 	if ( R128_VERBOSE ) {						\ 		DRM_INFO( "ADVANCE_RING() wr=0x%06x tail=0x%06x\n",	\ 			  write, dev_priv->ring.tail );			\ 	}								\ 	if ( R128_BROKEN_CCE&& write< 32 ) {				\ 		memcpy( dev_priv->ring.end,				\ 			dev_priv->ring.start,				\ 			write * sizeof(u32) );				\ 	}								\ 	r128_flush_write_combine();					\ 	dev_priv->ring.tail = write;					\ 	R128_WRITE( R128_PM4_BUFFER_DL_WPTR, write );			\ } while (0)
end_define

begin_define
define|#
directive|define
name|OUT_RING
parameter_list|(
name|x
parameter_list|)
value|do {						\ 	if ( R128_VERBOSE ) {						\ 		DRM_INFO( "   OUT_RING( 0x%08x ) at 0x%x\n",		\ 			   (unsigned int)(x), write );			\ 	}								\ 	ring[write++] = cpu_to_le32( x );				\ 	write&= tail_mask;						\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __R128_DRV_H__ */
end_comment

end_unit

