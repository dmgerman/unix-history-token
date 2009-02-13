begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000-2001 by Coleman Kane<cokane@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Gardner Buchanan.  * 4. The name of Gardner Buchanan may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *   $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<machine/../linux/linux.h>
end_include

begin_include
include|#
directive|include
file|<machine/../linux/linux_proto.h>
end_include

begin_include
include|#
directive|include
file|<compat/linux/linux_ioctl.h>
end_include

begin_comment
comment|/*  * This code was donated by Vladimir N. Silynaev to allow for defining  * ioctls within modules  */
end_comment

begin_define
define|#
directive|define
name|LINUX_IOCTL_SET
parameter_list|(
name|n
parameter_list|,
name|low
parameter_list|,
name|high
parameter_list|)
define|\
value|static linux_ioctl_function_t linux_ioctl_##n; \ static struct linux_ioctl_handler n##_handler = {linux_ioctl_##n, low, high}; \ SYSINIT(n##register, SI_SUB_KLD, SI_ORDER_MIDDLE,\ linux_ioctl_register_handler,&n##_handler); \ SYSUNINIT(n##unregister, SI_SUB_KLD, SI_ORDER_MIDDLE,\ linux_ioctl_unregister_handler,&n##_handler);
end_define

begin_comment
comment|/* Values for /dev/3dfx */
end_comment

begin_comment
comment|/* Query IOCTLs */
end_comment

begin_define
define|#
directive|define
name|LINUX_IOCTL_TDFX_QUERY_BOARDS
value|0x3302
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_TDFX_QUERY_FETCH
value|0x3303
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_TDFX_QUERY_UPDATE
value|0x3304
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_TDFX_MIN
value|0x3300
end_define

begin_define
define|#
directive|define
name|LINUX_IOCTL_TDFX_MAX
value|0x330f
end_define

end_unit

