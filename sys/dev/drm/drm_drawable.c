begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* drm_drawable.h -- IOCTLs for drawables -*- linux-c -*-  * Created: Tue Feb  2 08:37:54 1999 by faith@valinux.com  */
end_comment

begin_comment
comment|/*-  * Copyright 1999 Precision Insight, Inc., Cedar Park, Texas.  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Rickard E. (Rik) Faith<faith@valinux.com>  *    Gareth Hughes<gareth@valinux.com>  *  */
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

begin_include
include|#
directive|include
file|"dev/drm/drmP.h"
end_include

begin_function
name|int
name|drm_adddraw
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
block|{
name|drm_draw_t
name|draw
decl_stmt|;
name|draw
operator|.
name|handle
operator|=
literal|0
expr_stmt|;
comment|/* NOOP */
name|DRM_DEBUG
argument_list|(
literal|"%d\n"
argument_list|,
name|draw
operator|.
name|handle
argument_list|)
expr_stmt|;
name|DRM_COPY_TO_USER_IOCTL
argument_list|(
operator|(
name|drm_draw_t
operator|*
operator|)
name|data
argument_list|,
name|draw
argument_list|,
sizeof|sizeof
argument_list|(
name|draw
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|drm_rmdraw
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
block|{
return|return
literal|0
return|;
comment|/* NOOP */
block|}
end_function

end_unit

