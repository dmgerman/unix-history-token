begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2013 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_GLOBAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_BSD_GLOBAL_H_
end_define

begin_include
include|#
directive|include
file|<bsd_kernel.h>
end_include

begin_define
define|#
directive|define
name|USB_DEBUG_VAR
value|usb_debug
end_define

begin_include
include|#
directive|include
file|<dev/usb/usb_freebsd_loader.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_endian.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usbdi.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_core.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_debug.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_process.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_busdma.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_dynamic.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_transfer.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_device.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_hub.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_controller.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usbdi_util.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_cdc.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_dev.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_mbuf.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_msctest.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_pci.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_pf.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_request.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_util.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_compat_linux.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usbhid.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_ioctl.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_generic.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/quirk/usb_quirk.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/template/usb_template.h>
end_include

begin_decl_stmt
specifier|extern
name|struct
name|usb_process
name|usb_process
index|[
name|USB_PROC_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSD_GLOBAL_H_ */
end_comment

end_unit

