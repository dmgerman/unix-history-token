begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* r128_drv.c -- ATI Rage 128 driver -*- linux-c -*-  * Created: Mon Dec 13 09:47:27 1999 by faith@precisioninsight.com  *  * Copyright 1999 Precision Insight, Inc., Cedar Park, Texas.  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Rickard E. (Rik) Faith<faith@valinux.com>  *    Gareth Hughes<gareth@valinux.com>  *  * $FreeBSD$  */
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
file|"dev/drm/r128.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drmP.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/r128_drm.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/r128_drv.h"
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
value|"20010405"
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
value|2
end_define

begin_define
define|#
directive|define
name|DRIVER_PATCHLEVEL
value|0
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
comment|/* PCI cards are not supported with DRI under FreeBSD. */
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
literal|0x4c45
block|,
literal|0
block|,
literal|"ATI Rage 128 Mobility LE (PCI)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x4c46
block|,
literal|1
block|,
literal|"ATI Rage 128 Mobility LF (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x4d46
block|,
literal|1
block|,
literal|"ATI Rage 128 Mobility MF (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x4d4c
block|,
literal|1
block|,
literal|"ATI Rage 128 Mobility ML (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5044
block|,
literal|0
block|,
literal|"ATI Rage 128 Pro PD (PCI)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5046
block|,
literal|1
block|,
literal|"ATI Rage 128 Pro PF (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5050
block|,
literal|0
block|,
literal|"ATI Rage 128 Pro PP (PCI)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5052
block|,
literal|0
block|,
literal|"ATI Rage 128 Pro PR (PCI)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5245
block|,
literal|0
block|,
literal|"ATI Rage 128 RE (PCI)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5246
block|,
literal|1
block|,
literal|"ATI Rage 128 RF (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5247
block|,
literal|1
block|,
literal|"ATI Rage 128 RG (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x524b
block|,
literal|0
block|,
literal|"ATI Rage 128 RK (PCI)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x524c
block|,
literal|1
block|,
literal|"ATI Rage 128 RL (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x534d
block|,
literal|1
block|,
literal|"ATI Rage 128 SM (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5446
block|,
literal|1
block|,
literal|"ATI Rage 128 Pro Ultra TF (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x544C
block|,
literal|1
block|,
literal|"ATI Rage 128 Pro Ultra TL (AGP)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5452
block|,
literal|1
block|,
literal|"ATI Rage 128 Pro Ultra TR (AGP)"
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
value|[DRM_IOCTL_NR(DRM_IOCTL_DMA)]             = { r128_cce_buffers,  1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_INIT)]       = { r128_cce_init,     1, 1 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_CCE_START)]  = { r128_cce_start,    1, 1 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_CCE_STOP)]   = { r128_cce_stop,     1, 1 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_CCE_RESET)]  = { r128_cce_reset,    1, 1 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_CCE_IDLE)]   = { r128_cce_idle,     1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_RESET)]      = { r128_engine_reset, 1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_FULLSCREEN)] = { r128_fullscreen,   1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_SWAP)]       = { r128_cce_swap,     1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_CLEAR)]      = { r128_cce_clear,    1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_VERTEX)]     = { r128_cce_vertex,   1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_INDICES)]    = { r128_cce_indices,  1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_BLIT)]       = { r128_cce_blit,     1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_DEPTH)]      = { r128_cce_depth,    1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_STIPPLE)]    = { r128_cce_stipple,  1, 0 }, \    [DRM_IOCTL_NR(DRM_IOCTL_R128_INDIRECT)]   = { r128_cce_indirect, 1, 1 },
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
name|r128_options
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
name|r128_options
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

begin_include
include|#
directive|include
file|"dev/drm/drm_vm.h"
end_include

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
name|r128
argument_list|,
name|pci
argument_list|,
name|r128_driver
argument_list|,
name|r128_devclass
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

