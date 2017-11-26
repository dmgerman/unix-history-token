begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-NetBSD  *  * Copyright (c) 1999 Lennart Augustsson<augustss@netbsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * This file contains fallback-compatibility code for the old FreeBSD  * USB stack.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HID_COMPAT7
end_ifdef

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

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb.h>
end_include

begin_include
include|#
directive|include
file|"usbhid.h"
end_include

begin_include
include|#
directive|include
file|"usbvar.h"
end_include

begin_function
name|int
name|hid_set_immed_compat7
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|enable
parameter_list|)
block|{
return|return
operator|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|USB_SET_IMMED
argument_list|,
operator|&
name|enable
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|int
name|hid_get_report_id_compat7
parameter_list|(
name|int
name|fd
parameter_list|)
block|{
name|int
name|temp
init|=
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|USB_GET_REPORT_ID
argument_list|,
operator|&
name|temp
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
name|temp
operator|)
return|;
block|}
end_function

begin_function
name|report_desc_t
name|hid_get_report_desc_compat7
parameter_list|(
name|int
name|fd
parameter_list|)
block|{
name|struct
name|usb_ctl_report_desc
name|rep
decl_stmt|;
name|rep
operator|.
name|ucrd_size
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|USB_GET_REPORT_DESC
argument_list|,
operator|&
name|rep
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
return|return
operator|(
name|hid_use_report_desc
argument_list|(
name|rep
operator|.
name|ucrd_data
argument_list|,
operator|(
name|unsigned
name|int
operator|)
name|rep
operator|.
name|ucrd_size
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HID_COMPAT7 */
end_comment

end_unit

