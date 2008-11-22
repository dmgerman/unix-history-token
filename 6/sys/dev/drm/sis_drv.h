begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sis_drv.h -- Private header for sis driver -*- linux-c -*- */
end_comment

begin_comment
comment|/*-  * Copyright 1999 Precision Insight, Inc., Cedar Park, Texas.  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All rights reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  */
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
name|_SIS_DRV_H_
end_ifndef

begin_define
define|#
directive|define
name|_SIS_DRV_H_
end_define

begin_comment
comment|/* General customization:  */
end_comment

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

begin_include
include|#
directive|include
file|"dev/drm/sis_ds.h"
end_include

begin_typedef
typedef|typedef
struct|struct
name|drm_sis_private
block|{
name|memHeap_t
modifier|*
name|AGPHeap
decl_stmt|;
name|memHeap_t
modifier|*
name|FBHeap
decl_stmt|;
block|}
name|drm_sis_private_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|sis_init_context
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
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
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|int
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|drm_ioctl_desc_t
name|sis_ioctls
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sis_max_ioctl
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

