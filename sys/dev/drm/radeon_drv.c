begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* radeon_drv.c -- ATI Radeon driver -*- linux-c -*-  * Created: Wed Feb 14 17:10:04 2001 by gareth@valinux.com  *  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Gareth Hughes<gareth@valinux.com>  *  * $FreeBSD$  */
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
file|"dev/drm/drm.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/radeon_drm.h"
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
file|"dev/drm/ati_pcigart.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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
literal|1
block|,
literal|"ATI Radeon BB R200 AIW 8500DV"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x4336
block|,
literal|1
block|,
literal|"ATI Radeon Mobility U1"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x4964
block|,
literal|1
block|,
literal|"ATI Radeon Id R250 9000"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x4965
block|,
literal|1
block|,
literal|"ATI Radeon Ie R250 9000"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x4966
block|,
literal|1
block|,
literal|"ATI Radeon If R250 9000"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x4967
block|,
literal|1
block|,
literal|"ATI Radeon Ig R250 9000"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x4C57
block|,
literal|1
block|,
literal|"ATI Radeon LW Mobility 7500 M7"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x4C58
block|,
literal|1
block|,
literal|"ATI Radeon LX RV200 Mobility FireGL 7800 M7"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x4C59
block|,
literal|1
block|,
literal|"ATI Radeon LY Mobility M6"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x4C5A
block|,
literal|1
block|,
literal|"ATI Radeon LZ Mobility M6"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x4C64
block|,
literal|1
block|,
literal|"ATI Radeon Ld R250 Mobility 9000 M9"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x4C65
block|,
literal|1
block|,
literal|"ATI Radeon Le R250 Mobility 9000 M9"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x4C66
block|,
literal|1
block|,
literal|"ATI Radeon Lf R250 Mobility 9000 M9"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x4C67
block|,
literal|1
block|,
literal|"ATI Radeon Lg R250 Mobility 9000 M9"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5144
block|,
literal|1
block|,
literal|"ATI Radeon QD R100"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5145
block|,
literal|1
block|,
literal|"ATI Radeon QE R100"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5146
block|,
literal|1
block|,
literal|"ATI Radeon QF R100"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5147
block|,
literal|1
block|,
literal|"ATI Radeon QG R100"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5148
block|,
literal|1
block|,
literal|"ATI Radeon QH FireGL 8x00"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5149
block|,
literal|1
block|,
literal|"ATI Radeon QI R200"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x514A
block|,
literal|1
block|,
literal|"ATI Radeon QJ R200"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x514B
block|,
literal|1
block|,
literal|"ATI Radeon QK R200"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x514C
block|,
literal|1
block|,
literal|"ATI Radeon QL R200 8500 LE"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x514D
block|,
literal|1
block|,
literal|"ATI Radeon QM R200 9100"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x514E
block|,
literal|1
block|,
literal|"ATI Radeon QN R200 8500 LE"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x514F
block|,
literal|1
block|,
literal|"ATI Radeon QO R200 8500 LE"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5157
block|,
literal|1
block|,
literal|"ATI Radeon QW RV200 7500"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5158
block|,
literal|1
block|,
literal|"ATI Radeon QX RV200 7500"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5159
block|,
literal|1
block|,
literal|"ATI Radeon QY RV100 VE"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x515A
block|,
literal|1
block|,
literal|"ATI Radeon QZ RV100 VE"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5168
block|,
literal|1
block|,
literal|"ATI Radeon Qh R200"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x5169
block|,
literal|1
block|,
literal|"ATI Radeon Qi R200"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x516A
block|,
literal|1
block|,
literal|"ATI Radeon Qj R200"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x516B
block|,
literal|1
block|,
literal|"ATI Radeon Qk R200"
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x516C
block|,
literal|1
block|,
literal|"ATI Radeon Ql R200"
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
file|"dev/drm/drm_vm.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drm_sysctl.h"
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
name|DRIVER_NAME
argument_list|,
name|pci
argument_list|,
name|DRM
argument_list|(
name|driver
argument_list|)
argument_list|,
name|DRM
argument_list|(
name|devclass
argument_list|)
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
name|radeon
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

