begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-FreeBSD  *  * Copyright (c) 2013 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBUSB_GLOBAL_LINUX_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBUSB_GLOBAL_LINUX_H_
end_define

begin_define
define|#
directive|define
name|_XOPEN_SOURCE
end_define

begin_define
define|#
directive|define
name|_BSD_SOURCE
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_define
define|#
directive|define
name|_POSIX_SOURCE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_POSIX_C_SOURCE
value|200809
end_define

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/poll.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_endian.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_freebsd.h>
end_include

begin_include
include|#
directive|include
file|<compat/linux/linux_ioctl.h>
end_include

begin_define
define|#
directive|define
name|IOUSB
parameter_list|(
name|a
parameter_list|)
value|FBSD_L##a
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__aligned
end_ifndef

begin_define
define|#
directive|define
name|__aligned
parameter_list|(
name|x
parameter_list|)
value|__attribute__((__aligned__(x)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__packed
end_ifndef

begin_define
define|#
directive|define
name|__packed
value|__attribute__((__packed__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|strlcpy
end_ifndef

begin_define
define|#
directive|define
name|strlcpy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|len
parameter_list|)
value|do {			\     strncpy(d,s,len);				\     ((char *)d)[(len) - 1] = 0;			\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBUSB_GLOBAL_LINUX_H_ */
end_comment

end_unit

