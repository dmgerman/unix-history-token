begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* r128_drv.c -- ATI Rage 128 driver -*- linux-c -*-  * Created: Mon Dec 13 09:47:27 1999 by faith@precisioninsight.com  *  * Copyright 1999 Precision Insight, Inc., Cedar Park, Texas.  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Rickard E. (Rik) Faith<faith@valinux.com>  *    Gareth Hughes<gareth@valinux.com>  *  * $FreeBSD$  */
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
file|"dev/drm/drm.h"
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
file|"dev/drm/ati_pcigart.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* List acquired from http://www.yourvote.com/pci/pcihdr.h and xc/xc/programs/Xserver/hw/xfree86/common/xf86PciInfo.h  * Please report to eta@lclark.edu inaccuracies or if a chip you have works that is marked unsupported here.  */
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
name|__REALLY_HAVE_SG
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
name|__REALLY_HAVE_SG
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
name|__REALLY_HAVE_SG
block|,
literal|"ATI Rage 128 Pro PP (PCI)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5052
block|,
name|__REALLY_HAVE_SG
block|,
literal|"ATI Rage 128 Pro PR (PCI)"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5245
block|,
name|__REALLY_HAVE_SG
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
name|__REALLY_HAVE_SG
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

begin_include
include|#
directive|include
file|"dev/drm/drm_fops.h"
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
file|"dev/drm/drm_pci.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drm_sysctl.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drm_vm.h"
end_include

begin_if
if|#
directive|if
name|__HAVE_SG
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

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_elif

begin_expr_stmt
name|CFDRIVER_DECL
argument_list|(
name|r128
argument_list|,
name|DV_TTY
argument_list|,
name|NULL
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

