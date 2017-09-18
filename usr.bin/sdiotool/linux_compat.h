begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016-2017 Ilya Bakulin  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_COMPAT_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_COMPAT_H_
end_define

begin_comment
comment|/* Linux compatibility shims */
end_comment

begin_define
define|#
directive|define
name|uint
value|unsigned int
end_define

begin_define
define|#
directive|define
name|u32
value|uint32_t
end_define

begin_define
define|#
directive|define
name|u8
value|uint8_t
end_define

begin_define
define|#
directive|define
name|u16
value|uint16_t
end_define

begin_define
define|#
directive|define
name|s32
value|int32_t
end_define

begin_define
define|#
directive|define
name|bool
value|int8_t
end_define

begin_define
define|#
directive|define
name|true
value|1
end_define

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_define
define|#
directive|define
name|usleep_range
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|usleep(a)
end_define

begin_define
define|#
directive|define
name|ENOMEDIUM
value|-1
end_define

begin_define
define|#
directive|define
name|EINVAL
value|-2
end_define

begin_define
define|#
directive|define
name|WARN_ON
parameter_list|(
name|cond
parameter_list|)
value|({                                        \       bool __ret = (cond);                                      \       if (__ret) {                                              \ 	      printf("WARNING %s failed at %s:%d\n",		\ 		     #cond, __FILE__, __LINE__);	        \       }                                                         \       (__ret);                                                  \ })
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

