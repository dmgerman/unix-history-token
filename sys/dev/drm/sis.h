begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sis_drv.h -- Private header for sis driver -*- linux-c -*-  *  * Copyright 1999 Precision Insight, Inc., Cedar Park, Texas.  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All rights reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *   * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *   * $FreeBSD$  */
end_comment

begin_comment
comment|/* $XFree86: xc/programs/Xserver/hw/xfree86/os-support/linux/drm/kernel/sis.h,v 1.3 2002/10/30 12:52:38 alanh Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SIS_H__
end_ifndef

begin_define
define|#
directive|define
name|__SIS_H__
end_define

begin_comment
comment|/* This remains constant for all DRM template files.  * Name it sisdrv_##x as there's a conflict with sis_free/malloc in the kernel  * that's used for fb devices   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_define
define|#
directive|define
name|DRM
parameter_list|(
name|x
parameter_list|)
value|sisdrv_##x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DRM
parameter_list|(
name|x
parameter_list|)
value|sis_##x
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|DRIVER_AUTHOR
value|"SIS"
end_define

begin_define
define|#
directive|define
name|DRIVER_NAME
value|"sis"
end_define

begin_define
define|#
directive|define
name|DRIVER_DESC
value|"SIS 300/630/540"
end_define

begin_define
define|#
directive|define
name|DRIVER_DATE
value|"20030826"
end_define

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
value|[DRM_IOCTL_NR(DRM_IOCTL_SIS_FB_ALLOC)]  = { sis_fb_alloc,	1, 0 }, \ 	[DRM_IOCTL_NR(DRM_IOCTL_SIS_FB_FREE)]   = { sis_fb_free,	1, 0 }, \ 	[DRM_IOCTL_NR(DRM_IOCTL_SIS_AGP_INIT)]  = { sis_ioctl_agp_init,	1, 1 }, \ 	[DRM_IOCTL_NR(DRM_IOCTL_SIS_AGP_ALLOC)] = { sis_ioctl_agp_alloc, 1, 0 }, \ 	[DRM_IOCTL_NR(DRM_IOCTL_SIS_AGP_FREE)]	= { sis_ioctl_agp_free,	1, 0 }, \ 	[DRM_IOCTL_NR(DRM_IOCTL_SIS_FB_INIT)]	= { sis_fb_init,	1, 1 }
end_define

begin_define
define|#
directive|define
name|__HAVE_COUNTERS
value|5
end_define

begin_comment
comment|/* Buffer customization:  */
end_comment

begin_define
define|#
directive|define
name|DRIVER_AGP_BUFFERS_MAP
parameter_list|(
name|dev
parameter_list|)
define|\
value|((drm_sis_private_t *)((dev)->dev_private))->buffers
end_define

begin_function_decl
specifier|extern
name|int
name|sis_init_context
parameter_list|(
name|int
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sis_final_context
parameter_list|(
name|int
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DRIVER_CTX_CTOR
value|sis_init_context
end_define

begin_define
define|#
directive|define
name|DRIVER_CTX_DTOR
value|sis_final_context
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

