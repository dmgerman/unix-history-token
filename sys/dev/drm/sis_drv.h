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
value|"SIS, Tungsten Graphics"
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
value|"SIS 300/630/540 and XGI V3XE/V5/V8"
end_define

begin_define
define|#
directive|define
name|DRIVER_DATE
value|"20070626"
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
value|3
end_define

begin_define
define|#
directive|define
name|DRIVER_PATCHLEVEL
value|0
end_define

begin_enum
enum|enum
name|sis_family
block|{
name|SIS_OTHER
init|=
literal|0
block|,
name|SIS_CHIP_315
init|=
literal|1
block|, }
enum|;
end_enum

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIS_HAVE_CORE_MM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SIS_HAVE_CORE_MM
end_ifdef

begin_include
include|#
directive|include
file|"dev/drm/drm_sman.h"
end_include

begin_define
define|#
directive|define
name|SIS_BASE
value|(dev_priv->mmio)
end_define

begin_define
define|#
directive|define
name|SIS_READ
parameter_list|(
name|reg
parameter_list|)
value|DRM_READ32(SIS_BASE, reg);
end_define

begin_define
define|#
directive|define
name|SIS_WRITE
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
value|DRM_WRITE32(SIS_BASE, reg, val);
end_define

begin_typedef
typedef|typedef
struct|struct
name|drm_sis_private
block|{
name|drm_local_map_t
modifier|*
name|mmio
decl_stmt|;
name|unsigned
name|int
name|idle_fault
decl_stmt|;
name|struct
name|drm_sman
name|sman
decl_stmt|;
name|unsigned
name|int
name|chipset
decl_stmt|;
name|int
name|vram_initialized
decl_stmt|;
name|int
name|agp_initialized
decl_stmt|;
name|unsigned
name|long
name|vram_offset
decl_stmt|;
name|unsigned
name|long
name|agp_offset
decl_stmt|;
block|}
name|drm_sis_private_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|sis_idle
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sis_reclaim_buffers_locked
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sis_lastclose
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

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
name|struct
name|drm_device
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
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|drm_ioctl_desc
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

