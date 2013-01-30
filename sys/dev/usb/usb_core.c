begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * USB specifications and other documentation can be found at  * http://www.usb.org/developers/docs/ and  * http://www.usb.org/developers/devclass_docs/  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USB_GLOBAL_INCLUDE_FILE
end_ifdef

begin_include
include|#
directive|include
include|USB_GLOBAL_INCLUDE_FILE
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

begin_include
include|#
directive|include
file|<sys/stddef.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_include
include|#
directive|include
file|<sys/unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/priv.h>
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USB_GLOBAL_INCLUDE_FILE */
end_comment

begin_decl_stmt
specifier|const
name|struct
name|usb_string_lang
name|usb_string_lang_en
init|=
block|{
sizeof|sizeof
argument_list|(
name|usb_string_lang_en
argument_list|)
block|,
name|UDESC_STRING
block|,
block|{
literal|0x09
block|,
literal|0x04
block|}
comment|/* American English */
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|M_USB
argument_list|,
literal|"USB"
argument_list|,
literal|"USB"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|M_USBDEV
argument_list|,
literal|"USBdev"
argument_list|,
literal|"USB device"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|M_USBHC
argument_list|,
literal|"USBHC"
argument_list|,
literal|"USB host controller"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|usb
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

