begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* gamma_drv.h -- Private header for 3dlabs GMX 2000 driver -*- linux-c -*-  * Created: Mon Jan  4 10:05:05 1999 by faith@precisioninsight.com  *  * Copyright 1999 Precision Insight, Inc., Cedar Park, Texas.  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All rights reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Rickard E. (Rik) Faith<faith@valinux.com>  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GAMMA_DRV_H_
end_ifndef

begin_define
define|#
directive|define
name|_GAMMA_DRV_H_
end_define

begin_typedef
typedef|typedef
struct|struct
name|drm_gamma_private
block|{
name|drm_map_t
modifier|*
name|buffers
decl_stmt|;
name|drm_map_t
modifier|*
name|mmio0
decl_stmt|;
name|drm_map_t
modifier|*
name|mmio1
decl_stmt|;
name|drm_map_t
modifier|*
name|mmio2
decl_stmt|;
name|drm_map_t
modifier|*
name|mmio3
decl_stmt|;
block|}
name|drm_gamma_private_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LOCK_TEST_WITH_RETURN
parameter_list|(
name|dev
parameter_list|)
define|\
value|do {									\ 	if ( !_DRM_LOCK_IS_HELD( dev->lock.hw_lock->lock ) ||		\ 	     dev->lock.pid != DRM_OS_CURRENTPID ) {				\ 		DRM_ERROR( "%s called without lock held\n",		\ 			   __FUNCTION__ );				\ 		DRM_OS_RETURN( EINVAL );						\ 	}								\ } while (0)
end_define

begin_function_decl
specifier|extern
name|void
name|gamma_dma_ready
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
name|gamma_dma_quiescent_single
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
name|gamma_dma_quiescent_dual
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* gamma_dma.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|gamma_dma_schedule
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|int
name|locked
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gamma_dma
parameter_list|(
name|DRM_OS_IOCTL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gamma_find_devices
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gamma_found
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|GAMMA_OFF
parameter_list|(
name|reg
parameter_list|)
define|\
value|((reg< 0x1000)						   \ 	 ? reg							   \ 	 : ((reg< 0x10000)					   \ 	    ? (reg - 0x1000)					   \ 	    : ((reg< 0x11000)					   \ 	       ? (reg - 0x10000)				   \ 	       : (reg - 0x11000))))
end_define

begin_define
define|#
directive|define
name|GAMMA_BASE
parameter_list|(
name|reg
parameter_list|)
value|((unsigned long)				     \ 			  ((reg< 0x1000)    ? dev_priv->mmio0->handle :     \ 			   ((reg< 0x10000)  ? dev_priv->mmio1->handle :     \ 			    ((reg< 0x11000) ? dev_priv->mmio2->handle :     \ 					       dev_priv->mmio3->handle))))
end_define

begin_define
define|#
directive|define
name|GAMMA_ADDR
parameter_list|(
name|reg
parameter_list|)
value|(GAMMA_BASE(reg) + GAMMA_OFF(reg))
end_define

begin_define
define|#
directive|define
name|GAMMA_DEREF
parameter_list|(
name|reg
parameter_list|)
value|*(__volatile__ int *)GAMMA_ADDR(reg)
end_define

begin_define
define|#
directive|define
name|GAMMA_READ
parameter_list|(
name|reg
parameter_list|)
value|GAMMA_DEREF(reg)
end_define

begin_define
define|#
directive|define
name|GAMMA_WRITE
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
value|do { GAMMA_DEREF(reg) = val; } while (0)
end_define

begin_define
define|#
directive|define
name|GAMMA_BROADCASTMASK
value|0x9378
end_define

begin_define
define|#
directive|define
name|GAMMA_COMMANDINTENABLE
value|0x0c48
end_define

begin_define
define|#
directive|define
name|GAMMA_DMAADDRESS
value|0x0028
end_define

begin_define
define|#
directive|define
name|GAMMA_DMACOUNT
value|0x0030
end_define

begin_define
define|#
directive|define
name|GAMMA_FILTERMODE
value|0x8c00
end_define

begin_define
define|#
directive|define
name|GAMMA_GCOMMANDINTFLAGS
value|0x0c50
end_define

begin_define
define|#
directive|define
name|GAMMA_GCOMMANDMODE
value|0x0c40
end_define

begin_define
define|#
directive|define
name|GAMMA_GCOMMANDSTATUS
value|0x0c60
end_define

begin_define
define|#
directive|define
name|GAMMA_GDELAYTIMER
value|0x0c38
end_define

begin_define
define|#
directive|define
name|GAMMA_GDMACONTROL
value|0x0060
end_define

begin_define
define|#
directive|define
name|GAMMA_GINTENABLE
value|0x0808
end_define

begin_define
define|#
directive|define
name|GAMMA_GINTFLAGS
value|0x0810
end_define

begin_define
define|#
directive|define
name|GAMMA_INFIFOSPACE
value|0x0018
end_define

begin_define
define|#
directive|define
name|GAMMA_OUTFIFOWORDS
value|0x0020
end_define

begin_define
define|#
directive|define
name|GAMMA_OUTPUTFIFO
value|0x2000
end_define

begin_define
define|#
directive|define
name|GAMMA_SYNC
value|0x8c40
end_define

begin_define
define|#
directive|define
name|GAMMA_SYNC_TAG
value|0x0188
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

