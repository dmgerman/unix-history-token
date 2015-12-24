begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Patrick Kelsey  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TCP_FASTOPEN_H_
end_ifndef

begin_define
define|#
directive|define
name|_TCP_FASTOPEN_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|TCP_FASTOPEN_COOKIE_LEN
value|8
end_define

begin_comment
comment|/* tied to SipHash24 64-bit output */
end_comment

begin_macro
name|VNET_DECLARE
argument_list|(
argument|unsigned int
argument_list|,
argument|tcp_fastopen_enabled
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|V_tcp_fastopen_enabled
value|VNET(tcp_fastopen_enabled)
end_define

begin_function_decl
name|void
name|tcp_fastopen_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_fastopen_destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
modifier|*
name|tcp_fastopen_alloc_counter
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_fastopen_decrement_counter
parameter_list|(
name|unsigned
name|int
modifier|*
name|counter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcp_fastopen_check_cookie
parameter_list|(
name|struct
name|in_conninfo
modifier|*
name|inc
parameter_list|,
name|uint8_t
modifier|*
name|cookie
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|,
name|uint64_t
modifier|*
name|latest_cookie
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TCP_FASTOPEN_H_ */
end_comment

end_unit

