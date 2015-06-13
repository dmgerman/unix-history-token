begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Andrew Turner under  * sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_IODEV_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_IODEV_H_
end_define

begin_define
define|#
directive|define
name|iodev_read_1
parameter_list|(
name|a
parameter_list|)
define|\
value|({									\ 	uint8_t val;							\ 	__asm __volatile("ldrb	%w0, [%1]" : "=&r" (val) : "r"(a));	\ 	val;								\ })
end_define

begin_define
define|#
directive|define
name|iodev_read_2
parameter_list|(
name|a
parameter_list|)
define|\
value|({									\ 	uint16_t val;							\ 	__asm __volatile("ldrh	%w0, [%1]" : "=&r" (val) : "r"(a));	\ 	val;								\ })
end_define

begin_define
define|#
directive|define
name|iodev_read_4
parameter_list|(
name|a
parameter_list|)
define|\
value|({									\ 	uint32_t val;							\ 	__asm __volatile("ldr	%w0, [%1]" : "=&r" (val) : "r"(a));	\ 	val;								\ })
end_define

begin_define
define|#
directive|define
name|iodev_write_1
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
define|\
value|__asm __volatile("strb	%w0, [%1]" :: "r" (v), "r"(a))
end_define

begin_define
define|#
directive|define
name|iodev_write_2
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
define|\
value|__asm __volatile("strh	%w0, [%1]" :: "r" (v), "r"(a))
end_define

begin_define
define|#
directive|define
name|iodev_write_4
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
define|\
value|__asm __volatile("str	%w0, [%1]" :: "r" (v), "r"(a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_IODEV_H_ */
end_comment

end_unit

