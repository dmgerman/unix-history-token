begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* r128.h -- ATI Rage 128 DRM template customization -*- linux-c -*-  * Created: Wed Feb 14 16:07:10 2001 by gareth@valinux.com  *  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Gareth Hughes<gareth@valinux.com>  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__R128_H__
end_ifndef

begin_define
define|#
directive|define
name|__R128_H__
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
value|r128_##x
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
value|0
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
name|__HAVE_SG
value|1
end_define

begin_define
define|#
directive|define
name|__HAVE_PCI_DMA
value|1
end_define

begin_comment
comment|/* Driver customization:  */
end_comment

begin_define
define|#
directive|define
name|DRIVER_PRERELEASE
parameter_list|()
value|do {					\ 	if ( dev->dev_private ) {					\ 		drm_r128_private_t *dev_priv = dev->dev_private;	\ 		if ( dev_priv->page_flipping ) {			\ 			r128_do_cleanup_pageflip( dev );		\ 		}							\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|DRIVER_PRETAKEDOWN
parameter_list|()
value|do {					\ 	if ( dev->dev_private ) r128_do_cleanup_cce( dev );		\ } while (0)
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

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* GH: Remove this for now... */
end_comment

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
value|do {					\ 	drm_r128_private_t *dev_priv = dev->dev_private;		\ 	return r128_do_cce_idle( dev_priv );				\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Buffer customization:  */
end_comment

begin_define
define|#
directive|define
name|DRIVER_BUF_PRIV_T
value|drm_r128_buf_priv_t
end_define

begin_define
define|#
directive|define
name|DRIVER_AGP_BUFFERS_MAP
parameter_list|(
name|dev
parameter_list|)
define|\
value|((drm_r128_private_t *)((dev)->dev_private))->buffers
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

