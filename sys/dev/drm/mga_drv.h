begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mga_drv.h -- Private header for the Matrox G200/G400 driver -*- linux-c -*-  * Created: Mon Dec 13 01:50:01 1999 by jhartmann@precisioninsight.com  *  * Copyright 1999 Precision Insight, Inc., Cedar Park, Texas.  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All rights reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Gareth Hughes<gareth@valinux.com>  */
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
name|__MGA_DRV_H__
end_ifndef

begin_define
define|#
directive|define
name|__MGA_DRV_H__
end_define

begin_comment
comment|/* General customization:  */
end_comment

begin_define
define|#
directive|define
name|DRIVER_AUTHOR
value|"Gareth Hughes, VA Linux Systems Inc."
end_define

begin_define
define|#
directive|define
name|DRIVER_NAME
value|"mga"
end_define

begin_define
define|#
directive|define
name|DRIVER_DESC
value|"Matrox G200/G400"
end_define

begin_define
define|#
directive|define
name|DRIVER_DATE
value|"20051102"
end_define

begin_define
define|#
directive|define
name|DRIVER_MAJOR
value|3
end_define

begin_define
define|#
directive|define
name|DRIVER_MINOR
value|2
end_define

begin_define
define|#
directive|define
name|DRIVER_PATCHLEVEL
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|drm_mga_primary_buffer
block|{
name|u8
modifier|*
name|start
decl_stmt|;
name|u8
modifier|*
name|end
decl_stmt|;
name|int
name|size
decl_stmt|;
name|u32
name|tail
decl_stmt|;
name|int
name|space
decl_stmt|;
specifier|volatile
name|long
name|wrapped
decl_stmt|;
specifier|volatile
name|u32
modifier|*
name|status
decl_stmt|;
name|u32
name|last_flush
decl_stmt|;
name|u32
name|last_wrap
decl_stmt|;
name|u32
name|high_mark
decl_stmt|;
block|}
name|drm_mga_primary_buffer_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_mga_freelist
block|{
name|struct
name|drm_mga_freelist
modifier|*
name|next
decl_stmt|;
name|struct
name|drm_mga_freelist
modifier|*
name|prev
decl_stmt|;
name|drm_mga_age_t
name|age
decl_stmt|;
name|drm_buf_t
modifier|*
name|buf
decl_stmt|;
block|}
name|drm_mga_freelist_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|drm_mga_freelist_t
modifier|*
name|list_entry
decl_stmt|;
name|int
name|discard
decl_stmt|;
name|int
name|dispatched
decl_stmt|;
block|}
name|drm_mga_buf_priv_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_mga_private
block|{
name|drm_mga_primary_buffer_t
name|prim
decl_stmt|;
name|drm_mga_sarea_t
modifier|*
name|sarea_priv
decl_stmt|;
name|drm_mga_freelist_t
modifier|*
name|head
decl_stmt|;
name|drm_mga_freelist_t
modifier|*
name|tail
decl_stmt|;
name|unsigned
name|int
name|warp_pipe
decl_stmt|;
name|unsigned
name|long
name|warp_pipe_phys
index|[
name|MGA_MAX_WARP_PIPES
index|]
decl_stmt|;
name|int
name|chipset
decl_stmt|;
name|int
name|usec_timeout
decl_stmt|;
comment|/** 	 * If set, the new DMA initialization sequence was used.  This is 	 * primarilly used to select how the driver should uninitialized its 	 * internal DMA structures. 	 */
name|int
name|used_new_dma_init
decl_stmt|;
comment|/** 	 * If AGP memory is used for DMA buffers, this will be the value 	 * \c MGA_PAGPXFER.  Otherwise, it will be zero (for a PCI transfer). 	 */
name|u32
name|dma_access
decl_stmt|;
comment|/** 	 * If AGP memory is used for DMA buffers, this will be the value 	 * \c MGA_WAGP_ENABLE.  Otherwise, it will be zero (for a PCI 	 * transfer). 	 */
name|u32
name|wagp_enable
decl_stmt|;
comment|/** 	 * \name MMIO region parameters. 	 *  	 * \sa drm_mga_private_t::mmio 	 */
comment|/*@{*/
name|u32
name|mmio_base
decl_stmt|;
comment|/**< Bus address of base of MMIO. */
name|u32
name|mmio_size
decl_stmt|;
comment|/**< Size of the MMIO region. */
comment|/*@}*/
name|u32
name|clear_cmd
decl_stmt|;
name|u32
name|maccess
decl_stmt|;
name|wait_queue_head_t
name|fence_queue
decl_stmt|;
name|atomic_t
name|last_fence_retired
decl_stmt|;
name|u32
name|next_fence_to_post
decl_stmt|;
name|unsigned
name|int
name|fb_cpp
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
name|unsigned
name|int
name|depth_cpp
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
name|texture_offset
decl_stmt|;
name|unsigned
name|int
name|texture_size
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
name|status
decl_stmt|;
name|drm_local_map_t
modifier|*
name|warp
decl_stmt|;
name|drm_local_map_t
modifier|*
name|primary
decl_stmt|;
name|drm_local_map_t
modifier|*
name|agp_textures
decl_stmt|;
name|unsigned
name|long
name|agp_handle
decl_stmt|;
name|unsigned
name|int
name|agp_size
decl_stmt|;
block|}
name|drm_mga_private_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|drm_ioctl_desc_t
name|mga_ioctls
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mga_max_ioctl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mga_dma.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|mga_dma_bootstrap
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mga_dma_init
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mga_dma_flush
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mga_dma_reset
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mga_dma_buffers
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mga_driver_load
parameter_list|(
name|drm_device_t
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
name|mga_driver_unload
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
name|mga_driver_lastclose
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
name|mga_driver_dma_quiescent
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
name|mga_do_wait_for_idle
parameter_list|(
name|drm_mga_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mga_do_dma_flush
parameter_list|(
name|drm_mga_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mga_do_dma_wrap_start
parameter_list|(
name|drm_mga_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mga_do_dma_wrap_end
parameter_list|(
name|drm_mga_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mga_freelist_put
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

begin_comment
comment|/* mga_warp.c */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|int
name|mga_warp_microcode_size
parameter_list|(
specifier|const
name|drm_mga_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mga_warp_install_microcode
parameter_list|(
name|drm_mga_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mga_warp_init
parameter_list|(
name|drm_mga_private_t
modifier|*
name|dev_priv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* mga_irq.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|mga_driver_fence_wait
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
name|int
name|mga_driver_vblank_wait
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
name|mga_driver_irq_handler
parameter_list|(
name|DRM_IRQ_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mga_driver_irq_preinstall
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
name|mga_driver_irq_postinstall
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
name|mga_driver_irq_uninstall
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
name|mga_compat_ioctl
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

begin_define
define|#
directive|define
name|mga_flush_write_combine
parameter_list|()
value|DRM_WRITEMEMORYBARRIER()
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__alpha__
argument_list|)
end_if

begin_define
define|#
directive|define
name|MGA_BASE
parameter_list|(
name|reg
parameter_list|)
value|((unsigned long)(dev_priv->mmio->handle))
end_define

begin_define
define|#
directive|define
name|MGA_ADDR
parameter_list|(
name|reg
parameter_list|)
value|(MGA_BASE(reg) + reg)
end_define

begin_define
define|#
directive|define
name|MGA_DEREF
parameter_list|(
name|reg
parameter_list|)
value|*(volatile u32 *)MGA_ADDR( reg )
end_define

begin_define
define|#
directive|define
name|MGA_DEREF8
parameter_list|(
name|reg
parameter_list|)
value|*(volatile u8 *)MGA_ADDR( reg )
end_define

begin_define
define|#
directive|define
name|MGA_READ
parameter_list|(
name|reg
parameter_list|)
value|(_MGA_READ((u32 *)MGA_ADDR(reg)))
end_define

begin_define
define|#
directive|define
name|MGA_READ8
parameter_list|(
name|reg
parameter_list|)
value|(_MGA_READ((u8 *)MGA_ADDR(reg)))
end_define

begin_define
define|#
directive|define
name|MGA_WRITE
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
value|do { DRM_WRITEMEMORYBARRIER(); MGA_DEREF( reg ) = val; } while (0)
end_define

begin_define
define|#
directive|define
name|MGA_WRITE8
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
value|do { DRM_WRITEMEMORYBARRIER(); MGA_DEREF8( reg ) = val; } while (0)
end_define

begin_function
specifier|static
specifier|inline
name|u32
name|_MGA_READ
parameter_list|(
name|u32
modifier|*
name|addr
parameter_list|)
block|{
name|DRM_MEMORYBARRIER
argument_list|()
expr_stmt|;
return|return
operator|*
operator|(
specifier|volatile
name|u32
operator|*
operator|)
name|addr
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MGA_READ8
parameter_list|(
name|reg
parameter_list|)
value|DRM_READ8(dev_priv->mmio, (reg))
end_define

begin_define
define|#
directive|define
name|MGA_READ
parameter_list|(
name|reg
parameter_list|)
value|DRM_READ32(dev_priv->mmio, (reg))
end_define

begin_define
define|#
directive|define
name|MGA_WRITE8
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
value|DRM_WRITE8(dev_priv->mmio, (reg), (val))
end_define

begin_define
define|#
directive|define
name|MGA_WRITE
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
value|DRM_WRITE32(dev_priv->mmio, (reg), (val))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DWGREG0
value|0x1c00
end_define

begin_define
define|#
directive|define
name|DWGREG0_END
value|0x1dff
end_define

begin_define
define|#
directive|define
name|DWGREG1
value|0x2c00
end_define

begin_define
define|#
directive|define
name|DWGREG1_END
value|0x2dff
end_define

begin_define
define|#
directive|define
name|ISREG0
parameter_list|(
name|r
parameter_list|)
value|(r>= DWGREG0&& r<= DWGREG0_END)
end_define

begin_define
define|#
directive|define
name|DMAREG0
parameter_list|(
name|r
parameter_list|)
value|(u8)((r - DWGREG0)>> 2)
end_define

begin_define
define|#
directive|define
name|DMAREG1
parameter_list|(
name|r
parameter_list|)
value|(u8)(((r - DWGREG1)>> 2) | 0x80)
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

begin_comment
comment|/* ================================================================  * Helper macross...  */
end_comment

begin_define
define|#
directive|define
name|MGA_EMIT_STATE
parameter_list|(
name|dev_priv
parameter_list|,
name|dirty
parameter_list|)
define|\
value|do {									\ 	if ( (dirty)& ~MGA_UPLOAD_CLIPRECTS ) {			\ 		if ( dev_priv->chipset>= MGA_CARD_TYPE_G400 ) {	\ 			mga_g400_emit_state( dev_priv );		\ 		} else {						\ 			mga_g200_emit_state( dev_priv );		\ 		}							\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|WRAP_TEST_WITH_RETURN
parameter_list|(
name|dev_priv
parameter_list|)
define|\
value|do {									\ 	if ( test_bit( 0,&dev_priv->prim.wrapped ) ) {			\ 		if ( mga_is_idle( dev_priv ) ) {			\ 			mga_do_dma_wrap_end( dev_priv );		\ 		} else if ( dev_priv->prim.space<			\ 			    dev_priv->prim.high_mark ) {		\ 			if ( MGA_DMA_DEBUG )				\ 				DRM_INFO( "%s: wrap...\n", __FUNCTION__ );	\ 			return DRM_ERR(EBUSY);			\ 		}							\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|WRAP_WAIT_WITH_RETURN
parameter_list|(
name|dev_priv
parameter_list|)
define|\
value|do {									\ 	if ( test_bit( 0,&dev_priv->prim.wrapped ) ) {			\ 		if ( mga_do_wait_for_idle( dev_priv )< 0 ) {		\ 			if ( MGA_DMA_DEBUG )				\ 				DRM_INFO( "%s: wrap...\n", __FUNCTION__ );	\ 			return DRM_ERR(EBUSY);			\ 		}							\ 		mga_do_dma_wrap_end( dev_priv );			\ 	}								\ } while (0)
end_define

begin_comment
comment|/* ================================================================  * Primary DMA command stream  */
end_comment

begin_define
define|#
directive|define
name|MGA_VERBOSE
value|0
end_define

begin_define
define|#
directive|define
name|DMA_LOCALS
value|unsigned int write; volatile u8 *prim;
end_define

begin_define
define|#
directive|define
name|DMA_BLOCK_SIZE
value|(5 * sizeof(u32))
end_define

begin_define
define|#
directive|define
name|BEGIN_DMA
parameter_list|(
name|n
parameter_list|)
define|\
value|do {									\ 	if ( MGA_VERBOSE ) {						\ 		DRM_INFO( "BEGIN_DMA( %d ) in %s\n",			\ 			  (n), __FUNCTION__ );				\ 		DRM_INFO( "   space=0x%x req=0x%Zx\n",			\ 			  dev_priv->prim.space, (n) * DMA_BLOCK_SIZE );	\ 	}								\ 	prim = dev_priv->prim.start;					\ 	write = dev_priv->prim.tail;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|BEGIN_DMA_WRAP
parameter_list|()
define|\
value|do {									\ 	if ( MGA_VERBOSE ) {						\ 		DRM_INFO( "BEGIN_DMA() in %s\n", __FUNCTION__ );		\ 		DRM_INFO( "   space=0x%x\n", dev_priv->prim.space );	\ 	}								\ 	prim = dev_priv->prim.start;					\ 	write = dev_priv->prim.tail;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|ADVANCE_DMA
parameter_list|()
define|\
value|do {									\ 	dev_priv->prim.tail = write;					\ 	if ( MGA_VERBOSE ) {						\ 		DRM_INFO( "ADVANCE_DMA() tail=0x%05x sp=0x%x\n",	\ 			  write, dev_priv->prim.space );		\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|FLUSH_DMA
parameter_list|()
define|\
value|do {									\ 	if ( 0 ) {							\ 		DRM_INFO( "%s:\n", __FUNCTION__ );				\ 		DRM_INFO( "   tail=0x%06x head=0x%06lx\n",		\ 			  dev_priv->prim.tail,				\ 			  MGA_READ( MGA_PRIMADDRESS ) -			\ 			  dev_priv->primary->offset );			\ 	}								\ 	if ( !test_bit( 0,&dev_priv->prim.wrapped ) ) {		\ 		if ( dev_priv->prim.space<				\ 		     dev_priv->prim.high_mark ) {			\ 			mga_do_dma_wrap_start( dev_priv );		\ 		} else {						\ 			mga_do_dma_flush( dev_priv );			\ 		}							\ 	}								\ } while (0)
end_define

begin_comment
comment|/* Never use this, always use DMA_BLOCK(...) for primary DMA output.  */
end_comment

begin_define
define|#
directive|define
name|DMA_WRITE
parameter_list|(
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|do {									\ 	if ( MGA_VERBOSE ) {						\ 		DRM_INFO( "   DMA_WRITE( 0x%08x ) at 0x%04Zx\n",	\ 			  (u32)(val), write + (offset) * sizeof(u32) );	\ 	}								\ 	*(volatile u32 *)(prim + write + (offset) * sizeof(u32)) = val;	\ } while (0)
end_define

begin_define
define|#
directive|define
name|DMA_BLOCK
parameter_list|(
name|reg0
parameter_list|,
name|val0
parameter_list|,
name|reg1
parameter_list|,
name|val1
parameter_list|,
name|reg2
parameter_list|,
name|val2
parameter_list|,
name|reg3
parameter_list|,
name|val3
parameter_list|)
define|\
value|do {									\ 	DMA_WRITE( 0, ((DMAREG( reg0 )<< 0) |				\ 		       (DMAREG( reg1 )<< 8) |				\ 		       (DMAREG( reg2 )<< 16) |				\ 		       (DMAREG( reg3 )<< 24)) );			\ 	DMA_WRITE( 1, val0 );						\ 	DMA_WRITE( 2, val1 );						\ 	DMA_WRITE( 3, val2 );						\ 	DMA_WRITE( 4, val3 );						\ 	write += DMA_BLOCK_SIZE;					\ } while (0)
end_define

begin_comment
comment|/* Buffer aging via primary DMA stream head pointer.  */
end_comment

begin_define
define|#
directive|define
name|SET_AGE
parameter_list|(
name|age
parameter_list|,
name|h
parameter_list|,
name|w
parameter_list|)
define|\
value|do {									\ 	(age)->head = h;						\ 	(age)->wrap = w;						\ } while (0)
end_define

begin_define
define|#
directive|define
name|TEST_AGE
parameter_list|(
name|age
parameter_list|,
name|h
parameter_list|,
name|w
parameter_list|)
value|( (age)->wrap< w ||		\ 					  ( (age)->wrap == w&&		\ 					    (age)->head< h ) )
end_define

begin_define
define|#
directive|define
name|AGE_BUFFER
parameter_list|(
name|buf_priv
parameter_list|)
define|\
value|do {									\ 	drm_mga_freelist_t *entry = (buf_priv)->list_entry;		\ 	if ( (buf_priv)->dispatched ) {					\ 		entry->age.head = (dev_priv->prim.tail +		\ 				   dev_priv->primary->offset);		\ 		entry->age.wrap = dev_priv->sarea_priv->last_wrap;	\ 	} else {							\ 		entry->age.head = 0;					\ 		entry->age.wrap = 0;					\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|MGA_ENGINE_IDLE_MASK
value|(MGA_SOFTRAPEN |		\ 					 MGA_DWGENGSTS |		\ 					 MGA_ENDPRDMASTS)
end_define

begin_define
define|#
directive|define
name|MGA_DMA_IDLE_MASK
value|(MGA_SOFTRAPEN |		\ 					 MGA_ENDPRDMASTS)
end_define

begin_define
define|#
directive|define
name|MGA_DMA_DEBUG
value|0
end_define

begin_comment
comment|/* A reduced set of the mga registers.  */
end_comment

begin_define
define|#
directive|define
name|MGA_CRTC_INDEX
value|0x1fd4
end_define

begin_define
define|#
directive|define
name|MGA_CRTC_DATA
value|0x1fd5
end_define

begin_comment
comment|/* CRTC11 */
end_comment

begin_define
define|#
directive|define
name|MGA_VINTCLR
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MGA_VINTEN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MGA_ALPHACTRL
value|0x2c7c
end_define

begin_define
define|#
directive|define
name|MGA_AR0
value|0x1c60
end_define

begin_define
define|#
directive|define
name|MGA_AR1
value|0x1c64
end_define

begin_define
define|#
directive|define
name|MGA_AR2
value|0x1c68
end_define

begin_define
define|#
directive|define
name|MGA_AR3
value|0x1c6c
end_define

begin_define
define|#
directive|define
name|MGA_AR4
value|0x1c70
end_define

begin_define
define|#
directive|define
name|MGA_AR5
value|0x1c74
end_define

begin_define
define|#
directive|define
name|MGA_AR6
value|0x1c78
end_define

begin_define
define|#
directive|define
name|MGA_CXBNDRY
value|0x1c80
end_define

begin_define
define|#
directive|define
name|MGA_CXLEFT
value|0x1ca0
end_define

begin_define
define|#
directive|define
name|MGA_CXRIGHT
value|0x1ca4
end_define

begin_define
define|#
directive|define
name|MGA_DMAPAD
value|0x1c54
end_define

begin_define
define|#
directive|define
name|MGA_DSTORG
value|0x2cb8
end_define

begin_define
define|#
directive|define
name|MGA_DWGCTL
value|0x1c00
end_define

begin_define
define|#
directive|define
name|MGA_OPCOD_MASK
value|(15<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_OPCOD_TRAP
value|(4<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_OPCOD_TEXTURE_TRAP
value|(6<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_OPCOD_BITBLT
value|(8<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_OPCOD_ILOAD
value|(9<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_ATYPE_MASK
value|(7<< 4)
end_define

begin_define
define|#
directive|define
name|MGA_ATYPE_RPL
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|MGA_ATYPE_RSTR
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MGA_ATYPE_ZI
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|MGA_ATYPE_BLK
value|(4<< 4)
end_define

begin_define
define|#
directive|define
name|MGA_ATYPE_I
value|(7<< 4)
end_define

begin_define
define|#
directive|define
name|MGA_LINEAR
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|MGA_ZMODE_MASK
value|(7<< 8)
end_define

begin_define
define|#
directive|define
name|MGA_ZMODE_NOZCMP
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|MGA_ZMODE_ZE
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|MGA_ZMODE_ZNE
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|MGA_ZMODE_ZLT
value|(4<< 8)
end_define

begin_define
define|#
directive|define
name|MGA_ZMODE_ZLTE
value|(5<< 8)
end_define

begin_define
define|#
directive|define
name|MGA_ZMODE_ZGT
value|(6<< 8)
end_define

begin_define
define|#
directive|define
name|MGA_ZMODE_ZGTE
value|(7<< 8)
end_define

begin_define
define|#
directive|define
name|MGA_SOLID
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|MGA_ARZERO
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|MGA_SGNZERO
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|MGA_SHIFTZERO
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|MGA_BOP_MASK
value|(15<< 16)
end_define

begin_define
define|#
directive|define
name|MGA_BOP_ZERO
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|MGA_BOP_DST
value|(10<< 16)
end_define

begin_define
define|#
directive|define
name|MGA_BOP_SRC
value|(12<< 16)
end_define

begin_define
define|#
directive|define
name|MGA_BOP_ONE
value|(15<< 16)
end_define

begin_define
define|#
directive|define
name|MGA_TRANS_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|MGA_TRANS_MASK
value|(15<< 20)
end_define

begin_define
define|#
directive|define
name|MGA_BLTMOD_MASK
value|(15<< 25)
end_define

begin_define
define|#
directive|define
name|MGA_BLTMOD_BMONOLEF
value|(0<< 25)
end_define

begin_define
define|#
directive|define
name|MGA_BLTMOD_BMONOWF
value|(4<< 25)
end_define

begin_define
define|#
directive|define
name|MGA_BLTMOD_PLAN
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|MGA_BLTMOD_BFCOL
value|(2<< 25)
end_define

begin_define
define|#
directive|define
name|MGA_BLTMOD_BU32BGR
value|(3<< 25)
end_define

begin_define
define|#
directive|define
name|MGA_BLTMOD_BU32RGB
value|(7<< 25)
end_define

begin_define
define|#
directive|define
name|MGA_BLTMOD_BU24BGR
value|(11<< 25)
end_define

begin_define
define|#
directive|define
name|MGA_BLTMOD_BU24RGB
value|(15<< 25)
end_define

begin_define
define|#
directive|define
name|MGA_PATTERN
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|MGA_TRANSC
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|MGA_CLIPDIS
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|MGA_DWGSYNC
value|0x2c4c
end_define

begin_define
define|#
directive|define
name|MGA_FCOL
value|0x1c24
end_define

begin_define
define|#
directive|define
name|MGA_FIFOSTATUS
value|0x1e10
end_define

begin_define
define|#
directive|define
name|MGA_FOGCOL
value|0x1cf4
end_define

begin_define
define|#
directive|define
name|MGA_FXBNDRY
value|0x1c84
end_define

begin_define
define|#
directive|define
name|MGA_FXLEFT
value|0x1ca8
end_define

begin_define
define|#
directive|define
name|MGA_FXRIGHT
value|0x1cac
end_define

begin_define
define|#
directive|define
name|MGA_ICLEAR
value|0x1e18
end_define

begin_define
define|#
directive|define
name|MGA_SOFTRAPICLR
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_VLINEICLR
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MGA_IEN
value|0x1e1c
end_define

begin_define
define|#
directive|define
name|MGA_SOFTRAPIEN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_VLINEIEN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MGA_LEN
value|0x1c5c
end_define

begin_define
define|#
directive|define
name|MGA_MACCESS
value|0x1c04
end_define

begin_define
define|#
directive|define
name|MGA_PITCH
value|0x1c8c
end_define

begin_define
define|#
directive|define
name|MGA_PLNWT
value|0x1c1c
end_define

begin_define
define|#
directive|define
name|MGA_PRIMADDRESS
value|0x1e58
end_define

begin_define
define|#
directive|define
name|MGA_DMA_GENERAL
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_DMA_BLIT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_DMA_VECTOR
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_DMA_VERTEX
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_PRIMEND
value|0x1e5c
end_define

begin_define
define|#
directive|define
name|MGA_PRIMNOSTART
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_PAGPXFER
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MGA_PRIMPTR
value|0x1e50
end_define

begin_define
define|#
directive|define
name|MGA_PRIMPTREN0
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_PRIMPTREN1
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MGA_RST
value|0x1e40
end_define

begin_define
define|#
directive|define
name|MGA_SOFTRESET
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_SOFTEXTRST
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MGA_SECADDRESS
value|0x2c40
end_define

begin_define
define|#
directive|define
name|MGA_SECEND
value|0x2c44
end_define

begin_define
define|#
directive|define
name|MGA_SETUPADDRESS
value|0x2cd0
end_define

begin_define
define|#
directive|define
name|MGA_SETUPEND
value|0x2cd4
end_define

begin_define
define|#
directive|define
name|MGA_SGN
value|0x1c58
end_define

begin_define
define|#
directive|define
name|MGA_SOFTRAP
value|0x2c48
end_define

begin_define
define|#
directive|define
name|MGA_SRCORG
value|0x2cb4
end_define

begin_define
define|#
directive|define
name|MGA_SRMMAP_MASK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_SRCMAP_FB
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_SRCMAP_SYSMEM
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_SRCACC_MASK
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MGA_SRCACC_PCI
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|MGA_SRCACC_AGP
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MGA_STATUS
value|0x1e14
end_define

begin_define
define|#
directive|define
name|MGA_SOFTRAPEN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_VSYNCPEN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MGA_VLINEPEN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MGA_DWGENGSTS
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|MGA_ENDPRDMASTS
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|MGA_STENCIL
value|0x2cc8
end_define

begin_define
define|#
directive|define
name|MGA_STENCILCTL
value|0x2ccc
end_define

begin_define
define|#
directive|define
name|MGA_TDUALSTAGE0
value|0x2cf8
end_define

begin_define
define|#
directive|define
name|MGA_TDUALSTAGE1
value|0x2cfc
end_define

begin_define
define|#
directive|define
name|MGA_TEXBORDERCOL
value|0x2c5c
end_define

begin_define
define|#
directive|define
name|MGA_TEXCTL
value|0x2c30
end_define

begin_define
define|#
directive|define
name|MGA_TEXCTL2
value|0x2c3c
end_define

begin_define
define|#
directive|define
name|MGA_DUALTEX
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|MGA_G400_TC2_MAGIC
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|MGA_MAP1_ENABLE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|MGA_TEXFILTER
value|0x2c58
end_define

begin_define
define|#
directive|define
name|MGA_TEXHEIGHT
value|0x2c2c
end_define

begin_define
define|#
directive|define
name|MGA_TEXORG
value|0x2c24
end_define

begin_define
define|#
directive|define
name|MGA_TEXORGMAP_MASK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_TEXORGMAP_FB
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_TEXORGMAP_SYSMEM
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_TEXORGACC_MASK
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MGA_TEXORGACC_PCI
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|MGA_TEXORGACC_AGP
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MGA_TEXORG1
value|0x2ca4
end_define

begin_define
define|#
directive|define
name|MGA_TEXORG2
value|0x2ca8
end_define

begin_define
define|#
directive|define
name|MGA_TEXORG3
value|0x2cac
end_define

begin_define
define|#
directive|define
name|MGA_TEXORG4
value|0x2cb0
end_define

begin_define
define|#
directive|define
name|MGA_TEXTRANS
value|0x2c34
end_define

begin_define
define|#
directive|define
name|MGA_TEXTRANSHIGH
value|0x2c38
end_define

begin_define
define|#
directive|define
name|MGA_TEXWIDTH
value|0x2c28
end_define

begin_define
define|#
directive|define
name|MGA_WACCEPTSEQ
value|0x1dd4
end_define

begin_define
define|#
directive|define
name|MGA_WCODEADDR
value|0x1e6c
end_define

begin_define
define|#
directive|define
name|MGA_WFLAG
value|0x1dc4
end_define

begin_define
define|#
directive|define
name|MGA_WFLAG1
value|0x1de0
end_define

begin_define
define|#
directive|define
name|MGA_WFLAGNB
value|0x1e64
end_define

begin_define
define|#
directive|define
name|MGA_WFLAGNB1
value|0x1e08
end_define

begin_define
define|#
directive|define
name|MGA_WGETMSB
value|0x1dc8
end_define

begin_define
define|#
directive|define
name|MGA_WIADDR
value|0x1dc0
end_define

begin_define
define|#
directive|define
name|MGA_WIADDR2
value|0x1dd8
end_define

begin_define
define|#
directive|define
name|MGA_WMODE_SUSPEND
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_WMODE_RESUME
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_WMODE_JUMP
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_WMODE_START
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_WAGP_ENABLE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MGA_WMISC
value|0x1e70
end_define

begin_define
define|#
directive|define
name|MGA_WUCODECACHE_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_WMASTER_ENABLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MGA_WCACHEFLUSH_ENABLE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|MGA_WVRTXSZ
value|0x1dcc
end_define

begin_define
define|#
directive|define
name|MGA_YBOT
value|0x1c9c
end_define

begin_define
define|#
directive|define
name|MGA_YDST
value|0x1c90
end_define

begin_define
define|#
directive|define
name|MGA_YDSTLEN
value|0x1c88
end_define

begin_define
define|#
directive|define
name|MGA_YDSTORG
value|0x1c94
end_define

begin_define
define|#
directive|define
name|MGA_YTOP
value|0x1c98
end_define

begin_define
define|#
directive|define
name|MGA_ZORG
value|0x1c0c
end_define

begin_comment
comment|/* This finishes the current batch of commands  */
end_comment

begin_define
define|#
directive|define
name|MGA_EXEC
value|0x0100
end_define

begin_comment
comment|/* AGP PLL encoding (for G200 only).  */
end_comment

begin_define
define|#
directive|define
name|MGA_AGP_PLL
value|0x1e4c
end_define

begin_define
define|#
directive|define
name|MGA_AGP2XPLL_DISABLE
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|MGA_AGP2XPLL_ENABLE
value|(1<< 0)
end_define

begin_comment
comment|/* Warp registers  */
end_comment

begin_define
define|#
directive|define
name|MGA_WR0
value|0x2d00
end_define

begin_define
define|#
directive|define
name|MGA_WR1
value|0x2d04
end_define

begin_define
define|#
directive|define
name|MGA_WR2
value|0x2d08
end_define

begin_define
define|#
directive|define
name|MGA_WR3
value|0x2d0c
end_define

begin_define
define|#
directive|define
name|MGA_WR4
value|0x2d10
end_define

begin_define
define|#
directive|define
name|MGA_WR5
value|0x2d14
end_define

begin_define
define|#
directive|define
name|MGA_WR6
value|0x2d18
end_define

begin_define
define|#
directive|define
name|MGA_WR7
value|0x2d1c
end_define

begin_define
define|#
directive|define
name|MGA_WR8
value|0x2d20
end_define

begin_define
define|#
directive|define
name|MGA_WR9
value|0x2d24
end_define

begin_define
define|#
directive|define
name|MGA_WR10
value|0x2d28
end_define

begin_define
define|#
directive|define
name|MGA_WR11
value|0x2d2c
end_define

begin_define
define|#
directive|define
name|MGA_WR12
value|0x2d30
end_define

begin_define
define|#
directive|define
name|MGA_WR13
value|0x2d34
end_define

begin_define
define|#
directive|define
name|MGA_WR14
value|0x2d38
end_define

begin_define
define|#
directive|define
name|MGA_WR15
value|0x2d3c
end_define

begin_define
define|#
directive|define
name|MGA_WR16
value|0x2d40
end_define

begin_define
define|#
directive|define
name|MGA_WR17
value|0x2d44
end_define

begin_define
define|#
directive|define
name|MGA_WR18
value|0x2d48
end_define

begin_define
define|#
directive|define
name|MGA_WR19
value|0x2d4c
end_define

begin_define
define|#
directive|define
name|MGA_WR20
value|0x2d50
end_define

begin_define
define|#
directive|define
name|MGA_WR21
value|0x2d54
end_define

begin_define
define|#
directive|define
name|MGA_WR22
value|0x2d58
end_define

begin_define
define|#
directive|define
name|MGA_WR23
value|0x2d5c
end_define

begin_define
define|#
directive|define
name|MGA_WR24
value|0x2d60
end_define

begin_define
define|#
directive|define
name|MGA_WR25
value|0x2d64
end_define

begin_define
define|#
directive|define
name|MGA_WR26
value|0x2d68
end_define

begin_define
define|#
directive|define
name|MGA_WR27
value|0x2d6c
end_define

begin_define
define|#
directive|define
name|MGA_WR28
value|0x2d70
end_define

begin_define
define|#
directive|define
name|MGA_WR29
value|0x2d74
end_define

begin_define
define|#
directive|define
name|MGA_WR30
value|0x2d78
end_define

begin_define
define|#
directive|define
name|MGA_WR31
value|0x2d7c
end_define

begin_define
define|#
directive|define
name|MGA_WR32
value|0x2d80
end_define

begin_define
define|#
directive|define
name|MGA_WR33
value|0x2d84
end_define

begin_define
define|#
directive|define
name|MGA_WR34
value|0x2d88
end_define

begin_define
define|#
directive|define
name|MGA_WR35
value|0x2d8c
end_define

begin_define
define|#
directive|define
name|MGA_WR36
value|0x2d90
end_define

begin_define
define|#
directive|define
name|MGA_WR37
value|0x2d94
end_define

begin_define
define|#
directive|define
name|MGA_WR38
value|0x2d98
end_define

begin_define
define|#
directive|define
name|MGA_WR39
value|0x2d9c
end_define

begin_define
define|#
directive|define
name|MGA_WR40
value|0x2da0
end_define

begin_define
define|#
directive|define
name|MGA_WR41
value|0x2da4
end_define

begin_define
define|#
directive|define
name|MGA_WR42
value|0x2da8
end_define

begin_define
define|#
directive|define
name|MGA_WR43
value|0x2dac
end_define

begin_define
define|#
directive|define
name|MGA_WR44
value|0x2db0
end_define

begin_define
define|#
directive|define
name|MGA_WR45
value|0x2db4
end_define

begin_define
define|#
directive|define
name|MGA_WR46
value|0x2db8
end_define

begin_define
define|#
directive|define
name|MGA_WR47
value|0x2dbc
end_define

begin_define
define|#
directive|define
name|MGA_WR48
value|0x2dc0
end_define

begin_define
define|#
directive|define
name|MGA_WR49
value|0x2dc4
end_define

begin_define
define|#
directive|define
name|MGA_WR50
value|0x2dc8
end_define

begin_define
define|#
directive|define
name|MGA_WR51
value|0x2dcc
end_define

begin_define
define|#
directive|define
name|MGA_WR52
value|0x2dd0
end_define

begin_define
define|#
directive|define
name|MGA_WR53
value|0x2dd4
end_define

begin_define
define|#
directive|define
name|MGA_WR54
value|0x2dd8
end_define

begin_define
define|#
directive|define
name|MGA_WR55
value|0x2ddc
end_define

begin_define
define|#
directive|define
name|MGA_WR56
value|0x2de0
end_define

begin_define
define|#
directive|define
name|MGA_WR57
value|0x2de4
end_define

begin_define
define|#
directive|define
name|MGA_WR58
value|0x2de8
end_define

begin_define
define|#
directive|define
name|MGA_WR59
value|0x2dec
end_define

begin_define
define|#
directive|define
name|MGA_WR60
value|0x2df0
end_define

begin_define
define|#
directive|define
name|MGA_WR61
value|0x2df4
end_define

begin_define
define|#
directive|define
name|MGA_WR62
value|0x2df8
end_define

begin_define
define|#
directive|define
name|MGA_WR63
value|0x2dfc
end_define

begin_define
define|#
directive|define
name|MGA_G400_WR_MAGIC
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|MGA_G400_WR56_MAGIC
value|0x46480000
end_define

begin_comment
comment|/* 12800.0f */
end_comment

begin_define
define|#
directive|define
name|MGA_ILOAD_ALIGN
value|64
end_define

begin_define
define|#
directive|define
name|MGA_ILOAD_MASK
value|(MGA_ILOAD_ALIGN - 1)
end_define

begin_define
define|#
directive|define
name|MGA_DWGCTL_FLUSH
value|(MGA_OPCOD_TEXTURE_TRAP |		\ 				 MGA_ATYPE_I |				\ 				 MGA_ZMODE_NOZCMP |			\ 				 MGA_ARZERO |				\ 				 MGA_SGNZERO |				\ 				 MGA_BOP_SRC |				\ 				 (15<< MGA_TRANS_SHIFT))
end_define

begin_define
define|#
directive|define
name|MGA_DWGCTL_CLEAR
value|(MGA_OPCOD_TRAP |			\ 				 MGA_ZMODE_NOZCMP |			\ 				 MGA_SOLID |				\ 				 MGA_ARZERO |				\ 				 MGA_SGNZERO |				\ 				 MGA_SHIFTZERO |			\ 				 MGA_BOP_SRC |				\ 				 (0<< MGA_TRANS_SHIFT) |		\ 				 MGA_BLTMOD_BMONOLEF |			\ 				 MGA_TRANSC |				\ 				 MGA_CLIPDIS)
end_define

begin_define
define|#
directive|define
name|MGA_DWGCTL_COPY
value|(MGA_OPCOD_BITBLT |			\ 				 MGA_ATYPE_RPL |			\ 				 MGA_SGNZERO |				\ 				 MGA_SHIFTZERO |			\ 				 MGA_BOP_SRC |				\ 				 (0<< MGA_TRANS_SHIFT) |		\ 				 MGA_BLTMOD_BFCOL |			\ 				 MGA_CLIPDIS)
end_define

begin_comment
comment|/* Simple idle test.  */
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|mga_is_idle
parameter_list|(
name|drm_mga_private_t
modifier|*
name|dev_priv
parameter_list|)
block|{
name|u32
name|status
init|=
name|MGA_READ
argument_list|(
name|MGA_STATUS
argument_list|)
operator|&
name|MGA_ENGINE_IDLE_MASK
decl_stmt|;
return|return
operator|(
name|status
operator|==
name|MGA_ENDPRDMASTS
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

