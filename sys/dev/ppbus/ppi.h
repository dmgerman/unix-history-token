begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Nicolas Souchu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PPI_H
end_ifndef

begin_define
define|#
directive|define
name|__PPI_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_define
define|#
directive|define
name|PPIGDATA
value|_IOR('P', 10, u_int8_t)
end_define

begin_define
define|#
directive|define
name|PPIGSTATUS
value|_IOR('P', 11, u_int8_t)
end_define

begin_define
define|#
directive|define
name|PPIGCTRL
value|_IOR('P', 12, u_int8_t)
end_define

begin_define
define|#
directive|define
name|PPIGEPPD
value|_IOR('P', 13, u_int8_t)
end_define

begin_define
define|#
directive|define
name|PPIGECR
value|_IOR('P', 14, u_int8_t)
end_define

begin_define
define|#
directive|define
name|PPIGFIFO
value|_IOR('P', 15, u_int8_t)
end_define

begin_define
define|#
directive|define
name|PPISDATA
value|_IOW('P', 16, u_int8_t)
end_define

begin_define
define|#
directive|define
name|PPISSTATUS
value|_IOW('P', 17, u_int8_t)
end_define

begin_define
define|#
directive|define
name|PPISCTRL
value|_IOW('P', 18, u_int8_t)
end_define

begin_define
define|#
directive|define
name|PPISEPPD
value|_IOW('P', 19, u_int8_t)
end_define

begin_define
define|#
directive|define
name|PPISECR
value|_IOW('P', 20, u_int8_t)
end_define

begin_define
define|#
directive|define
name|PPISFIFO
value|_IOW('P', 21, u_int8_t)
end_define

begin_define
define|#
directive|define
name|PPIGEPPA
value|_IOR('P', 22, u_int8_t)
end_define

begin_define
define|#
directive|define
name|PPISEPPA
value|_IOR('P', 23, u_int8_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

