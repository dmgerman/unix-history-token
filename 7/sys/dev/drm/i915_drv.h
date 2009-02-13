begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* i915_drv.h -- Private header for the I915 driver -*- linux-c -*-  */
end_comment

begin_comment
comment|/*  *   * Copyright 2003 Tungsten Graphics, Inc., Cedar Park, Texas.  * All Rights Reserved.  *   * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the  * "Software"), to deal in the Software without restriction, including  * without limitation the rights to use, copy, modify, merge, publish,  * distribute, sub license, and/or sell copies of the Software, and to  * permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *   * The above copyright notice and this permission notice (including the  * next paragraph) shall be included in all copies or substantial portions  * of the Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.  * IN NO EVENT SHALL TUNGSTEN GRAPHICS AND/OR ITS SUPPLIERS BE LIABLE FOR  * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE  * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  *   */
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
value|"20060119"
end_define

begin_comment
comment|/* Interface history:  *  * 1.1: Original.  * 1.2: Add Power Management  * 1.3: Add vblank support  * 1.4: Fix cmdbuffer path, add heap destroy  * 1.5: Add vblank pipe configuration  */
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
value|5
end_define

begin_define
define|#
directive|define
name|DRIVER_PATCHLEVEL
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
name|Start
decl_stmt|;
name|unsigned
name|long
name|End
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
name|DRMFILE
name|filp
decl_stmt|;
comment|/* 0: free, -1: heap, other: real files */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|drm_i915_private
block|{
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
name|unsigned
name|long
name|counter
decl_stmt|;
name|int
name|back_offset
decl_stmt|;
name|int
name|front_offset
decl_stmt|;
name|int
name|current_page
decl_stmt|;
name|int
name|page_flipping
decl_stmt|;
name|int
name|use_mi_batchbuffer_start
decl_stmt|;
name|wait_queue_head_t
name|irq_queue
decl_stmt|;
name|atomic_t
name|irq_received
decl_stmt|;
name|atomic_t
name|irq_emitted
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
block|}
name|drm_i915_private_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|drm_ioctl_desc_t
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
name|drm_device_t
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
name|void
name|i915_driver_lastclose
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
name|i915_driver_preclose
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
name|int
name|i915_driver_device_is_agp
parameter_list|(
name|drm_device_t
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

begin_comment
comment|/* i915_irq.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|i915_irq_emit
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i915_irq_wait
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i915_driver_vblank_wait
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
name|drm_device_t
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i915_driver_irq_postinstall
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
name|i915_driver_irq_uninstall
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
name|i915_vblank_pipe_set
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i915_vblank_pipe_get
parameter_list|(
name|DRM_IOCTL_ARGS
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
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i915_mem_free
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i915_mem_init_heap
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i915_mem_destroy_heap
parameter_list|(
name|DRM_IOCTL_ARGS
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
name|drm_device_t
modifier|*
name|dev
parameter_list|,
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
name|I915_VERBOSE
value|0
end_define

begin_define
define|#
directive|define
name|RING_LOCALS
value|unsigned int outring, ringmask, outcount; \ 			volatile char *virt;
end_define

begin_define
define|#
directive|define
name|BEGIN_LP_RING
parameter_list|(
name|n
parameter_list|)
value|do {				\ 	if (I915_VERBOSE)				\ 		DRM_DEBUG("BEGIN_LP_RING(%d) in %s\n",	\ 	                         (n), __FUNCTION__);           \ 	if (dev_priv->ring.space< (n)*4)                      \ 		i915_wait_ring(dev, (n)*4, __FUNCTION__);      \ 	outcount = 0;					\ 	outring = dev_priv->ring.tail;			\ 	ringmask = dev_priv->ring.tail_mask;		\ 	virt = dev_priv->ring.virtual_start;		\ } while (0)
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
value|do {						\ 	if (I915_VERBOSE) DRM_DEBUG("ADVANCE_LP_RING %x\n", outring);	\ 	dev_priv->ring.tail = outring;					\ 	dev_priv->ring.space -= outcount * 4;				\ 	I915_WRITE(LP_RING + RING_TAIL, outring);			\ } while(0)
end_define

begin_function_decl
specifier|extern
name|int
name|i915_wait_ring
parameter_list|(
name|drm_device_t
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
name|GFX_OP_USER_INTERRUPT
value|((0<<29)|(2<<23))
end_define

begin_define
define|#
directive|define
name|GFX_OP_BREAKPOINT_INTERRUPT
value|((0<<29)|(1<<23))
end_define

begin_define
define|#
directive|define
name|CMD_REPORT_HEAD
value|(7<<23)
end_define

begin_define
define|#
directive|define
name|CMD_STORE_DWORD_IDX
value|((0x21<<23) | 0x1)
end_define

begin_define
define|#
directive|define
name|CMD_OP_BATCH_BUFFER
value|((0x0<<29)|(0x30<<23)|0x1)
end_define

begin_define
define|#
directive|define
name|INST_PARSER_CLIENT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|INST_OP_FLUSH
value|0x02000000
end_define

begin_define
define|#
directive|define
name|INST_FLUSH_MAP_CACHE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BB1_START_ADDR_MASK
value|(~0x7)
end_define

begin_define
define|#
directive|define
name|BB1_PROTECTED
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|BB1_UNPROTECTED
value|(0<<0)
end_define

begin_define
define|#
directive|define
name|BB2_END_ADDR_MASK
value|(~0x7)
end_define

begin_define
define|#
directive|define
name|I915REG_HWSTAM
value|0x02098
end_define

begin_define
define|#
directive|define
name|I915REG_INT_IDENTITY_R
value|0x020a4
end_define

begin_define
define|#
directive|define
name|I915REG_INT_MASK_R
value|0x020a8
end_define

begin_define
define|#
directive|define
name|I915REG_INT_ENABLE_R
value|0x020a0
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
name|NOPID
value|0x2094
end_define

begin_define
define|#
directive|define
name|LP_RING
value|0x2030
end_define

begin_define
define|#
directive|define
name|HP_RING
value|0x2040
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
value|0x0xFFFFF000
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
name|MI_BATCH_BUFFER
value|((0x30<<23)|1)
end_define

begin_define
define|#
directive|define
name|MI_BATCH_BUFFER_START
value|(0x31<<23)
end_define

begin_define
define|#
directive|define
name|MI_BATCH_BUFFER_END
value|(0xA<<23)
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
name|MI_WAIT_FOR_EVENT
value|((0x3<<23))
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
name|MI_LOAD_SCAN_LINES_INCL
value|((0x12<<23))
end_define

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
name|CMD_OP_DESTBUFFER_INFO
value|((0x3<<29)|(0x1d<<24)|(0x8e<<16)|1)
end_define

begin_define
define|#
directive|define
name|READ_BREADCRUMB
parameter_list|(
name|dev_priv
parameter_list|)
value|(((u32*)(dev_priv->hw_status_page))[5])
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

