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
value|"r128"
end_define

begin_define
define|#
directive|define
name|DRIVER_DESC
value|"ATI Rage 128"
end_define

begin_define
define|#
directive|define
name|DRIVER_DATE
value|"20030725"
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
value|5
end_define

begin_define
define|#
directive|define
name|DRIVER_PATCHLEVEL
value|0
end_define

begin_comment
comment|/* Interface history:  *  * ??  - ??  * 2.4 - Add support for ycbcr textures (no new ioctls)  * 2.5 - Add FLIP ioctl, disable FULLSCREEN.  */
end_comment

begin_define
define|#
directive|define
name|DRIVER_IOCTLS
define|\
value|[DRM_IOCTL_NR(DRM_IOCTL_DMA)]             = { r128_cce_buffers,  1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_INIT)]       = { r128_cce_init,     1, 1 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_CCE_START)]  = { r128_cce_start,    1, 1 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_CCE_STOP)]   = { r128_cce_stop,     1, 1 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_CCE_RESET)]  = { r128_cce_reset,    1, 1 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_CCE_IDLE)]   = { r128_cce_idle,     1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_RESET)]      = { r128_engine_reset, 1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_FULLSCREEN)] = { r128_fullscreen,   1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_SWAP)]       = { r128_cce_swap,     1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_FLIP)]       = { r128_cce_flip,     1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_CLEAR)]      = { r128_cce_clear,    1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_VERTEX)]     = { r128_cce_vertex,   1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_INDICES)]    = { r128_cce_indices,  1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_BLIT)]       = { r128_cce_blit,     1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_DEPTH)]      = { r128_cce_depth,    1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_STIPPLE)]    = { r128_cce_stipple,  1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_INDIRECT)]   = { r128_cce_indirect, 1, 1 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_GETPARAM)]   = { r128_getparam, 1, 0 },
end_define

begin_define
define|#
directive|define
name|DRIVER_PCI_IDS
define|\
value|{0x1002, 0x4c45, 0, "ATI Rage 128 Mobility LE (PCI)"},		\ 	{0x1002, 0x4c46, 0, "ATI Rage 128 Mobility LF (AGP)"},		\ 	{0x1002, 0x4d46, 0, "ATI Rage 128 Mobility MF (AGP)"},		\ 	{0x1002, 0x4d4c, 0, "ATI Rage 128 Mobility ML (AGP)"},		\ 	{0x1002, 0x5041, 0, "ATI Rage 128 Pro PA (PCI)"},		\ 	{0x1002, 0x5042, 0, "ATI Rage 128 Pro PB (AGP)"},		\ 	{0x1002, 0x5043, 0, "ATI Rage 128 Pro PC (AGP)"},		\ 	{0x1002, 0x5044, 0, "ATI Rage 128 Pro PD (PCI)"},		\ 	{0x1002, 0x5045, 0, "ATI Rage 128 Pro PE (AGP)"},		\ 	{0x1002, 0x5046, 0, "ATI Rage 128 Pro PF (AGP)"},		\ 	{0x1002, 0x5047, 0, "ATI Rage 128 Pro PG (PCI)"},		\ 	{0x1002, 0x5048, 0, "ATI Rage 128 Pro PH (AGP)"},		\ 	{0x1002, 0x5049, 0, "ATI Rage 128 Pro PI (AGP)"},		\ 	{0x1002, 0x504A, 0, "ATI Rage 128 Pro PJ (PCI)"},		\ 	{0x1002, 0x504B, 0, "ATI Rage 128 Pro PK (AGP)"},		\ 	{0x1002, 0x504C, 0, "ATI Rage 128 Pro PL (AGP)"},		\ 	{0x1002, 0x504D, 0, "ATI Rage 128 Pro PM (PCI)"},		\ 	{0x1002, 0x504E, 0, "ATI Rage 128 Pro PN (AGP)"},		\ 	{0x1002, 0x504F, 0, "ATI Rage 128 Pro PO (AGP)"},		\ 	{0x1002, 0x5050, 0, "ATI Rage 128 Pro PP (PCI)"},		\ 	{0x1002, 0x5051, 0, "ATI Rage 128 Pro PQ (AGP)"},		\ 	{0x1002, 0x5052, 0, "ATI Rage 128 Pro PR (PCI)"},		\ 	{0x1002, 0x5053, 0, "ATI Rage 128 Pro PS (PCI)"},		\ 	{0x1002, 0x5054, 0, "ATI Rage 128 Pro PT (AGP)"},		\ 	{0x1002, 0x5055, 0, "ATI Rage 128 Pro PU (AGP)"},		\ 	{0x1002, 0x5056, 0, "ATI Rage 128 Pro PV (PCI)"},		\ 	{0x1002, 0x5057, 0, "ATI Rage 128 Pro PW (AGP)"},		\ 	{0x1002, 0x5058, 0, "ATI Rage 128 Pro PX (AGP)"},		\ 	{0x1002, 0x5245, 0, "ATI Rage 128 RE (PCI)"},			\ 	{0x1002, 0x5246, 0, "ATI Rage 128 RF (AGP)"},			\ 	{0x1002, 0x5247, 0, "ATI Rage 128 RG (AGP)"},			\ 	{0x1002, 0x524b, 0, "ATI Rage 128 RK (PCI)"},			\ 	{0x1002, 0x524c, 0, "ATI Rage 128 RL (AGP)"},			\ 	{0x1002, 0x534d, 0, "ATI Rage 128 SM (AGP)"},			\ 	{0x1002, 0x5446, 0, "ATI Rage 128 Pro Ultra TF (AGP)"},		\ 	{0x1002, 0x544C, 0, "ATI Rage 128 Pro Ultra TL (AGP)"},		\ 	{0x1002, 0x5452, 0, "ATI Rage 128 Pro Ultra TR (AGP)"},		\ 	{0, 0, 0, NULL}
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
value|do {					\ 	r128_do_cleanup_cce( dev );					\ } while (0)
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
name|__HAVE_IRQ
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

