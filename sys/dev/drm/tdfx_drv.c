begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tdfx_drv.c -- tdfx driver -*- linux-c -*-  * Created: Thu Oct  7 10:38:32 1999 by faith@precisioninsight.com  *  * Copyright 1999 Precision Insight, Inc., Cedar Park, Texas.  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Rickard E. (Rik) Faith<faith@valinux.com>  *    Daryll Strauss<daryll@valinux.com>  *    Gareth Hughes<gareth@valinux.com>  *  * $FreeBSD$  */
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
file|"dev/drm/tdfx.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drmP.h"
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
value|"tdfx"
end_define

begin_define
define|#
directive|define
name|DRIVER_DESC
value|"3dfx Banshee/Voodoo3+"
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

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_VENDOR_ID_3DFX
end_ifndef

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_3DFX
value|0x121A
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_DEVICE_ID_3DFX_VOODOO5
end_ifndef

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_3DFX_VOODOO5
value|0x0009
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_DEVICE_ID_3DFX_VOODOO4
end_ifndef

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_3DFX_VOODOO4
value|0x0007
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_DEVICE_ID_3DFX_VOODOO3_3000
end_ifndef

begin_comment
comment|/* Voodoo3 3000 */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_3DFX_VOODOO3_3000
value|0x0005
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_DEVICE_ID_3DFX_VOODOO3_2000
end_ifndef

begin_comment
comment|/* Voodoo3 3000 */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_3DFX_VOODOO3_2000
value|0x0004
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_DEVICE_ID_3DFX_BANSHEE
end_ifndef

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_3DFX_BANSHEE
value|0x0003
end_define

begin_endif
endif|#
directive|endif
end_endif

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
literal|0x121a
block|,
literal|0x0003
block|,
literal|1
block|,
literal|"3dfx Voodoo Banshee"
block|}
block|,
block|{
literal|0x121a
block|,
literal|0x0004
block|,
literal|1
block|,
literal|"3dfx Voodoo3 2000"
block|}
block|,
block|{
literal|0x121a
block|,
literal|0x0005
block|,
literal|1
block|,
literal|"3dfx Voodoo3 3000"
block|}
block|,
block|{
literal|0x121a
block|,
literal|0x0007
block|,
literal|1
block|,
literal|"3dfx Voodoo4"
block|}
block|,
block|{
literal|0x121a
block|,
literal|0x0009
block|,
literal|1
block|,
literal|"3dfx Voodoo5"
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

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_comment
comment|/* For now, we'll only support multihead on Linux */
end_comment

begin_comment
comment|/* Uncomment this, and fixup drm_count_cards */
end_comment

begin_decl_stmt
specifier|static
name|drm_pci_list_t
name|DRM
argument_list|(
name|idlist
argument_list|)
decl|[]
init|=
block|{
block|{
name|PCI_VENDOR_ID_3DFX
block|,
name|PCI_DEVICE_ID_3DFX_BANSHEE
block|}
block|,
block|{
name|PCI_VENDOR_ID_3DFX
block|,
name|PCI_DEVICE_ID_3DFX_VOODOO3_2000
block|}
block|,
block|{
name|PCI_VENDOR_ID_3DFX
block|,
name|PCI_DEVICE_ID_3DFX_VOODOO3_3000
block|}
block|,
block|{
name|PCI_VENDOR_ID_3DFX
block|,
name|PCI_DEVICE_ID_3DFX_VOODOO4
block|}
block|,
block|{
name|PCI_VENDOR_ID_3DFX
block|,
name|PCI_DEVICE_ID_3DFX_VOODOO5
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DRIVER_CARD_LIST
value|DRM(idlist)
end_define

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
name|tdfx_options
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
name|tdfx_options
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
name|tdfx
argument_list|,
name|pci
argument_list|,
name|tdfx_driver
argument_list|,
name|tdfx_devclass
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

