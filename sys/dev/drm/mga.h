begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mga.h -- Matrox G200/G400 DRM template customization -*- linux-c -*-  * Created: Thu Jan 11 21:29:32 2001 by gareth@valinux.com  *  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Gareth Hughes<gareth@valinux.com>  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MGA_H__
end_ifndef

begin_define
define|#
directive|define
name|__MGA_H__
end_define

begin_comment
comment|/* This remains constant for all DRM template files.  */
end_comment

begin_define
define|#
directive|define
name|DRM
parameter_list|(
name|x
parameter_list|)
value|mga_##x
end_define

begin_comment
comment|/* General customization:  */
end_comment

begin_define
define|#
directive|define
name|__HAVE_AGP
value|1
end_define

begin_define
define|#
directive|define
name|__MUST_HAVE_AGP
value|1
end_define

begin_define
define|#
directive|define
name|__HAVE_MTRR
value|1
end_define

begin_define
define|#
directive|define
name|__HAVE_CTX_BITMAP
value|1
end_define

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
value|"20021029"
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
value|1
end_define

begin_define
define|#
directive|define
name|DRIVER_PATCHLEVEL
value|0
end_define

begin_define
define|#
directive|define
name|DRIVER_IOCTLS
define|\
value|[DRM_IOCTL_NR(DRM_IOCTL_DMA)]	      = { mga_dma_buffers, 1, 0 }, \ 	[DRM_IOCTL_NR(DRM_IOCTL_MGA_INIT)]    = { mga_dma_init,    1, 1 }, \ 	[DRM_IOCTL_NR(DRM_IOCTL_MGA_FLUSH)]   = { mga_dma_flush,   1, 0 }, \ 	[DRM_IOCTL_NR(DRM_IOCTL_MGA_RESET)]   = { mga_dma_reset,   1, 0 }, \ 	[DRM_IOCTL_NR(DRM_IOCTL_MGA_SWAP)]    = { mga_dma_swap,    1, 0 }, \ 	[DRM_IOCTL_NR(DRM_IOCTL_MGA_CLEAR)]   = { mga_dma_clear,   1, 0 }, \ 	[DRM_IOCTL_NR(DRM_IOCTL_MGA_VERTEX)]  = { mga_dma_vertex,  1, 0 }, \ 	[DRM_IOCTL_NR(DRM_IOCTL_MGA_INDICES)] = { mga_dma_indices, 1, 0 }, \ 	[DRM_IOCTL_NR(DRM_IOCTL_MGA_ILOAD)]   = { mga_dma_iload,   1, 0 }, \ 	[DRM_IOCTL_NR(DRM_IOCTL_MGA_BLIT)]    = { mga_dma_blit,    1, 0 }, \ 	[DRM_IOCTL_NR(DRM_IOCTL_MGA_GETPARAM)]= { mga_getparam,    1, 0 },
end_define

begin_define
define|#
directive|define
name|__HAVE_COUNTERS
value|3
end_define

begin_define
define|#
directive|define
name|__HAVE_COUNTER6
value|_DRM_STAT_IRQ
end_define

begin_define
define|#
directive|define
name|__HAVE_COUNTER7
value|_DRM_STAT_PRIMARY
end_define

begin_define
define|#
directive|define
name|__HAVE_COUNTER8
value|_DRM_STAT_SECONDARY
end_define

begin_comment
comment|/* Driver customization:  */
end_comment

begin_define
define|#
directive|define
name|DRIVER_PRETAKEDOWN
parameter_list|()
value|do {					\ 	mga_do_cleanup_dma( dev );					\ } while (0)
end_define

begin_comment
comment|/* DMA customization:  */
end_comment

begin_define
define|#
directive|define
name|__HAVE_DMA
value|1
end_define

begin_define
define|#
directive|define
name|__HAVE_DMA_IRQ
value|1
end_define

begin_define
define|#
directive|define
name|__HAVE_VBL_IRQ
value|1
end_define

begin_define
define|#
directive|define
name|__HAVE_SHARED_IRQ
value|1
end_define

begin_define
define|#
directive|define
name|__HAVE_DMA_QUIESCENT
value|1
end_define

begin_define
define|#
directive|define
name|DRIVER_DMA_QUIESCENT
parameter_list|()
value|do {					\ 	drm_mga_private_t *dev_priv = dev->dev_private;			\ 	return mga_do_wait_for_idle( dev_priv );			\ } while (0)
end_define

begin_comment
comment|/* Buffer customization:  */
end_comment

begin_define
define|#
directive|define
name|DRIVER_BUF_PRIV_T
value|drm_mga_buf_priv_t
end_define

begin_define
define|#
directive|define
name|DRIVER_AGP_BUFFERS_MAP
parameter_list|(
name|dev
parameter_list|)
define|\
value|((drm_mga_private_t *)((dev)->dev_private))->buffers
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

