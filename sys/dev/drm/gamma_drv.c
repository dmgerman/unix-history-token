begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* gamma.c -- 3dlabs GMX 2000 driver -*- linux-c -*-  * Created: Mon Jan  4 08:58:31 1999 by faith@precisioninsight.com  *  * Copyright 1999 Precision Insight, Inc., Cedar Park, Texas.  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Rickard E. (Rik) Faith<faith@valinux.com>  *    Gareth Hughes<gareth@valinux.com>  *  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_include
include|#
directive|include
file|<linux/config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __linux__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<opt_drm_linux.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_include
include|#
directive|include
file|"dev/drm/gamma.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drmP.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/gamma_drv.h"
end_include

begin_define
define|#
directive|define
name|DRIVER_AUTHOR
value|"VA Linux Systems Inc."
end_define

begin_define
define|#
directive|define
name|DRIVER_NAME
value|"gamma"
end_define

begin_define
define|#
directive|define
name|DRIVER_DESC
value|"3DLabs gamma"
end_define

begin_define
define|#
directive|define
name|DRIVER_DATE
value|"20010216"
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
value|0
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
value|[DRM_IOCTL_NR(DRM_IOCTL_DMA)]	     = { gamma_dma,	  1, 0 }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_comment
comment|/* List acquired from xc/xc/programs/Xserver/hw/xfree86/common/xf86PciInfo.h  * Please report to eanholt@gladstone.uoregon.edu if your chip isn't  * represented in the list or if the information is incorrect.  */
end_comment

begin_decl_stmt
name|drm_chipinfo_t
name|DRM
argument_list|(
name|devicelist
argument_list|)
decl|[]
init|=
block|{
block|{
literal|0x3d3d
block|,
literal|0x0008
block|,
literal|1
block|,
literal|"3DLabs Gamma"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_define
define|#
directive|define
name|__HAVE_COUNTERS
value|5
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
value|_DRM_STAT_DMA
end_define

begin_define
define|#
directive|define
name|__HAVE_COUNTER8
value|_DRM_STAT_PRIMARY
end_define

begin_define
define|#
directive|define
name|__HAVE_COUNTER9
value|_DRM_STAT_SPECIAL
end_define

begin_define
define|#
directive|define
name|__HAVE_COUNTER10
value|_DRM_STAT_MISSED
end_define

begin_include
include|#
directive|include
file|"dev/drm/drm_auth.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drm_bufs.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drm_context.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drm_dma.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drm_drawable.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drm_drv.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|MODULE
end_ifndef

begin_comment
comment|/* DRM(options) is called by the kernel to parse command-line options  * passed via the boot-loader (e.g., LILO).  It calls the insmod option  * routine, drm_parse_drm.  */
end_comment

begin_comment
comment|/* JH- We have to hand expand the string ourselves because of the cpp.  If  * anyone can think of a way that we can fit into the __setup macro without  * changing it, then please send the solution my way.  */
end_comment

begin_function
specifier|static
name|int
name|__init
name|gamma_options
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
block|{
name|DRM
function_decl|(
name|parse_options
function_decl|)
parameter_list|(
name|str
parameter_list|)
function_decl|;
return|return
literal|1
return|;
block|}
end_function

begin_expr_stmt
name|__setup
argument_list|(
name|DRIVER_NAME
literal|"="
argument_list|,
name|gamma_options
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __linux__ */
end_comment

begin_include
include|#
directive|include
file|"dev/drm/drm_fops.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drm_init.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drm_ioctl.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drm_lists.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drm_lock.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drm_memory.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_include
include|#
directive|include
file|"dev/drm/drm_proc.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __linux__ */
end_comment

begin_include
include|#
directive|include
file|"dev/drm/drm_vm.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_include
include|#
directive|include
file|"dev/drm/drm_stub.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __linux__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|"dev/drm/drm_sysctl.h"
end_include

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|gamma
argument_list|,
name|pci
argument_list|,
name|gamma_driver
argument_list|,
name|gamma_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

end_unit

