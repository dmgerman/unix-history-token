begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* radeon_drv.c -- ATI Radeon driver -*- linux-c -*-  * Created: Wed Feb 14 17:10:04 2001 by gareth@valinux.com  *  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Gareth Hughes<gareth@valinux.com>  *  * $FreeBSD$  */
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
file|"dev/drm/radeon.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drmP.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/radeon_drv.h"
end_include

begin_if
if|#
directive|if
name|__REALLY_HAVE_SG
end_if

begin_include
include|#
directive|include
file|"ati_pcigart.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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
value|"radeon"
end_define

begin_define
define|#
directive|define
name|DRIVER_DESC
value|"ATI Radeon"
end_define

begin_define
define|#
directive|define
name|DRIVER_DATE
value|"20010405"
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
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_comment
comment|/* List acquired from xc/xc/programs/Xserver/hw/xfree86/common/xf86PciInfo.h  * Please report to eanholt@gladstone.uoregon.edu if your chip isn't  * represented in the list or if the information is incorrect.  */
end_comment

begin_comment
comment|/* PCI cards are not supported with DRI under FreeBSD, and the 8500  * is not supported on any platform yet.  */
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
literal|0x1002
block|,
literal|0x4242
block|,
literal|0
block|,
literal|"ATI Radeon BB 8500 (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x4C57
block|,
literal|1
block|,
literal|"ATI Radeon LW Mobility 7 (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x4C59
block|,
literal|1
block|,
literal|"ATI Radeon LY Mobility 6 (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x4C5A
block|,
literal|1
block|,
literal|"ATI Radeon LZ Mobility 6 (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5144
block|,
literal|1
block|,
literal|"ATI Radeon QD (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5145
block|,
literal|1
block|,
literal|"ATI Radeon QE (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5146
block|,
literal|1
block|,
literal|"ATI Radeon QF (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5147
block|,
literal|1
block|,
literal|"ATI Radeon QG (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x514C
block|,
literal|0
block|,
literal|"ATI Radeon QL 8500 (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x514E
block|,
literal|0
block|,
literal|"ATI Radeon QN 8500 (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x514F
block|,
literal|0
block|,
literal|"ATI Radeon QO 8500 (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5157
block|,
literal|1
block|,
literal|"ATI Radeon QW 7500 (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5159
block|,
literal|1
block|,
literal|"ATI Radeon QY VE (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x515A
block|,
literal|1
block|,
literal|"ATI Radeon QZ VE (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x516C
block|,
literal|0
block|,
literal|"ATI Radeon Ql 8500 (AGP)"
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
name|DRIVER_IOCTLS
define|\
value|[DRM_IOCTL_NR(DRM_IOCTL_DMA)]               = { radeon_cp_buffers,  1, 0 }, \  [DRM_IOCTL_NR(DRM_IOCTL_RADEON_CP_INIT)]    = { radeon_cp_init,     1, 1 }, \  [DRM_IOCTL_NR(DRM_IOCTL_RADEON_CP_START)]   = { radeon_cp_start,    1, 1 }, \  [DRM_IOCTL_NR(DRM_IOCTL_RADEON_CP_STOP)]    = { radeon_cp_stop,     1, 1 }, \  [DRM_IOCTL_NR(DRM_IOCTL_RADEON_CP_RESET)]   = { radeon_cp_reset,    1, 1 }, \  [DRM_IOCTL_NR(DRM_IOCTL_RADEON_CP_IDLE)]    = { radeon_cp_idle,     1, 0 }, \  [DRM_IOCTL_NR(DRM_IOCTL_RADEON_RESET)]    = { radeon_engine_reset,  1, 0 }, \  [DRM_IOCTL_NR(DRM_IOCTL_RADEON_FULLSCREEN)] = { radeon_fullscreen,  1, 0 }, \  [DRM_IOCTL_NR(DRM_IOCTL_RADEON_SWAP)]       = { radeon_cp_swap,     1, 0 }, \  [DRM_IOCTL_NR(DRM_IOCTL_RADEON_CLEAR)]      = { radeon_cp_clear,    1, 0 }, \  [DRM_IOCTL_NR(DRM_IOCTL_RADEON_VERTEX)]     = { radeon_cp_vertex,   1, 0 }, \  [DRM_IOCTL_NR(DRM_IOCTL_RADEON_INDICES)]    = { radeon_cp_indices,  1, 0 }, \  [DRM_IOCTL_NR(DRM_IOCTL_RADEON_TEXTURE)]    = { radeon_cp_texture,  1, 0 }, \  [DRM_IOCTL_NR(DRM_IOCTL_RADEON_STIPPLE)]    = { radeon_cp_stipple,  1, 0 }, \  [DRM_IOCTL_NR(DRM_IOCTL_RADEON_INDIRECT)]   = { radeon_cp_indirect, 1, 1 },
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* GH: Count data sent to card via ring or vertex/indirect buffers.  */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"dev/drm/drm_agpsupport.h"
end_include

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
name|radeon_options
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
name|radeon_options
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
file|"dev/drm/drm_lock.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drm_memory.h"
end_include

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
file|"dev/drm/drm_proc.h"
end_include

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_if
if|#
directive|if
name|__REALLY_HAVE_SG
end_if

begin_include
include|#
directive|include
file|"dev/drm/drm_scatter.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|radeon
argument_list|,
name|pci
argument_list|,
name|radeon_driver
argument_list|,
name|radeon_devclass
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

