begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* gamma.c -- 3dlabs GMX 2000 driver -*- linux-c -*-  * Created: Mon Jan  4 08:58:31 1999 by gareth@valinux.com  *  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Gareth Hughes<gareth@valinux.com>  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GAMMA_H__
end_ifndef

begin_define
define|#
directive|define
name|__GAMMA_H__
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
value|gamma_##x
end_define

begin_comment
comment|/* General customization:  */
end_comment

begin_define
define|#
directive|define
name|__HAVE_MTRR
value|1
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
name|__HAVE_OLD_DMA
value|1
end_define

begin_define
define|#
directive|define
name|__HAVE_PCI_DMA
value|1
end_define

begin_define
define|#
directive|define
name|__HAVE_MULTIPLE_DMA_QUEUES
value|1
end_define

begin_define
define|#
directive|define
name|__HAVE_DMA_WAITQUEUE
value|1
end_define

begin_define
define|#
directive|define
name|__HAVE_DMA_WAITLIST
value|1
end_define

begin_define
define|#
directive|define
name|__HAVE_DMA_FREELIST
value|1
end_define

begin_define
define|#
directive|define
name|__HAVE_DMA_FLUSH
value|1
end_define

begin_define
define|#
directive|define
name|__HAVE_DMA_SCHEDULE
value|1
end_define

begin_define
define|#
directive|define
name|__HAVE_DMA_READY
value|1
end_define

begin_define
define|#
directive|define
name|DRIVER_DMA_READY
parameter_list|()
value|do {						\ 	gamma_dma_ready(dev);						\ } while (0)
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
value|do {					\
comment|/* FIXME ! */
value|\ 	gamma_dma_quiescent_dual(dev);					\ 	return 0;							\ } while (0)
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
name|__HAVE_DMA_IRQ_BH
value|1
end_define

begin_define
define|#
directive|define
name|DRIVER_PREINSTALL
parameter_list|()
value|do {					\ 	drm_gamma_private_t *dev_priv =					\ 				(drm_gamma_private_t *)dev->dev_private;\ 	GAMMA_WRITE( GAMMA_GCOMMANDMODE,	0x00000000 );		\ 	GAMMA_WRITE( GAMMA_GDMACONTROL,		0x00000000 );		\ } while (0)
end_define

begin_define
define|#
directive|define
name|DRIVER_POSTINSTALL
parameter_list|()
value|do {					\ 	drm_gamma_private_t *dev_priv =					\ 				(drm_gamma_private_t *)dev->dev_private;\ 	GAMMA_WRITE( GAMMA_GINTENABLE,		0x00002001 );		\ 	GAMMA_WRITE( GAMMA_COMMANDINTENABLE,	0x00000008 );		\ 	GAMMA_WRITE( GAMMA_GDELAYTIMER,		0x00039090 );		\ } while (0)
end_define

begin_define
define|#
directive|define
name|DRIVER_UNINSTALL
parameter_list|()
value|do {						\ 	drm_gamma_private_t *dev_priv =					\ 				(drm_gamma_private_t *)dev->dev_private;\ 	GAMMA_WRITE( GAMMA_GDELAYTIMER,		0x00000000 );		\ 	GAMMA_WRITE( GAMMA_COMMANDINTENABLE,	0x00000000 );		\ 	GAMMA_WRITE( GAMMA_GINTENABLE,		0x00000000 );		\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GAMMA_H__ */
end_comment

end_unit

