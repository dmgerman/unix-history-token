begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sis_drv.h -- Private header for sis driver -*- linux-c -*- */
end_comment

begin_comment
comment|/*-  * Copyright 2005 Eric Anholt  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
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
name|__SIS_DRM_H__
end_ifndef

begin_define
define|#
directive|define
name|__SIS_DRM_H__
end_define

begin_comment
comment|/* SiS specific ioctls */
end_comment

begin_define
define|#
directive|define
name|NOT_USED_0_3
end_define

begin_define
define|#
directive|define
name|DRM_SIS_FB_ALLOC
value|0x04
end_define

begin_define
define|#
directive|define
name|DRM_SIS_FB_FREE
value|0x05
end_define

begin_define
define|#
directive|define
name|NOT_USED_6_12
end_define

begin_define
define|#
directive|define
name|DRM_SIS_AGP_INIT
value|0x13
end_define

begin_define
define|#
directive|define
name|DRM_SIS_AGP_ALLOC
value|0x14
end_define

begin_define
define|#
directive|define
name|DRM_SIS_AGP_FREE
value|0x15
end_define

begin_define
define|#
directive|define
name|DRM_SIS_FB_INIT
value|0x16
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_SIS_FB_ALLOC
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_SIS_FB_ALLOC, drm_sis_mem_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_SIS_FB_FREE
value|DRM_IOW( DRM_COMMAND_BASE + DRM_SIS_FB_FREE, drm_sis_mem_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_SIS_AGP_INIT
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_SIS_AGP_INIT, drm_sis_agp_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_SIS_AGP_ALLOC
value|DRM_IOWR(DRM_COMMAND_BASE + DRM_SIS_AGP_ALLOC, drm_sis_mem_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_SIS_AGP_FREE
value|DRM_IOW( DRM_COMMAND_BASE + DRM_SIS_AGP_FREE, drm_sis_mem_t)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_SIS_FB_INIT
value|DRM_IOW( DRM_COMMAND_BASE + DRM_SIS_FB_INIT, drm_sis_fb_t)
end_define

begin_comment
comment|/* #define DRM_IOCTL_SIS_FLIP		DRM_IOW( 0x48, drm_sis_flip_t) #define DRM_IOCTL_SIS_FLIP_INIT		DRM_IO(  0x49) #define DRM_IOCTL_SIS_FLIP_FINAL	DRM_IO(  0x50) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|context
decl_stmt|;
name|unsigned
name|int
name|offset
decl_stmt|;
name|unsigned
name|int
name|size
decl_stmt|;
name|unsigned
name|long
name|free
decl_stmt|;
block|}
name|drm_sis_mem_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|offset
decl_stmt|,
name|size
decl_stmt|;
block|}
name|drm_sis_agp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|offset
decl_stmt|,
name|size
decl_stmt|;
block|}
name|drm_sis_fb_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SIS_DRM_H__ */
end_comment

end_unit

