begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 M. Warner Losh  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * This code is based on ugen.c and ulpt.c developed by Lennart Augustsson.  * This code includes software developed by the NetBSD Foundation, Inc. and  * its contributors.  */
end_comment

begin_comment
comment|/*  $FreeBSD$ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|FM_SET_FREQ
value|_IOWR('U', 200, int)
end_define

begin_define
define|#
directive|define
name|FM_GET_FREQ
value|_IOWR('U', 201, int)
end_define

begin_define
define|#
directive|define
name|FM_START
value|_IOWR('U', 202, int)
end_define

begin_define
define|#
directive|define
name|FM_STOP
value|_IOWR('U', 203, int)
end_define

begin_define
define|#
directive|define
name|FM_GET_STAT
value|_IOWR('U', 204, int)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FM_SET_FREQ
value|0x1
end_define

begin_define
define|#
directive|define
name|FM_GET_FREQ
value|0x2
end_define

begin_define
define|#
directive|define
name|FM_START
value|0x3
end_define

begin_define
define|#
directive|define
name|FM_STOP
value|0x4
end_define

begin_define
define|#
directive|define
name|FM_GET_STAT
value|0x5
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

