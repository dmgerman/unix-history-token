begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mga_drv.c -- Matrox G200/G400 driver -*- linux-c -*-  * Created: Mon Dec 13 01:56:22 1999 by jhartmann@precisioninsight.com  *  * Copyright 1999 Precision Insight, Inc., Cedar Park, Texas.  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Rickard E. (Rik) Faith<faith@valinux.com>  *    Gareth Hughes<gareth@valinux.com>  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"dev/drm/mga.h"
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
file|"dev/drm/mga_drm.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/mga_drv.h"
end_include

begin_comment
comment|/* List acquired from http://www.yourvote.com/pci/pcihdr.h and xc/xc/programs/Xserver/hw/xfree86/common/xf86PciInfo.h  * Please report to anholt@teleport.com inaccuracies or if a chip you have works that is marked unsupported here.  */
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
literal|0x102b
block|,
literal|0x0520
block|,
literal|0
block|,
literal|"Matrox G200 (PCI)"
block|}
block|,
block|{
literal|0x102b
block|,
literal|0x0521
block|,
literal|1
block|,
literal|"Matrox G200 (AGP)"
block|}
block|,
block|{
literal|0x102b
block|,
literal|0x0525
block|,
literal|1
block|,
literal|"Matrox G400/G450 (AGP)"
block|}
block|,
block|{
literal|0x102b
block|,
literal|0x2527
block|,
literal|1
block|,
literal|"Matrox G550 (AGP)"
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
file|"dev/drm/drm_vm.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drm_sysctl.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|mga
argument_list|,
name|pci
argument_list|,
name|mga_driver
argument_list|,
name|mga_devclass
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
name|mga
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

end_unit

