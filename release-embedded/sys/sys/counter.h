begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Gleb Smirnoff<glebius@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SYS_COUNTER_H__
end_ifndef

begin_define
define|#
directive|define
name|__SYS_COUNTER_H__
end_define

begin_typedef
typedef|typedef
name|uint64_t
modifier|*
name|counter_u64_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<machine/counter.h>
end_include

begin_function_decl
name|counter_u64_t
name|counter_u64_alloc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|counter_u64_free
parameter_list|(
name|counter_u64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|counter_u64_zero
parameter_list|(
name|counter_u64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|counter_u64_fetch
parameter_list|(
name|counter_u64_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|COUNTER_ARRAY_ALLOC
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|,
name|wait
parameter_list|)
value|do {			\ 	for (int i = 0; i< (n); i++)				\ 		(a)[i] = counter_u64_alloc(wait);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|COUNTER_ARRAY_FREE
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|do {			\ 	for (int i = 0; i< (n); i++)				\ 		counter_u64_free((a)[i]);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|COUNTER_ARRAY_COPY
parameter_list|(
name|a
parameter_list|,
name|dstp
parameter_list|,
name|n
parameter_list|)
value|do {			\ 	for (int i = 0; i< (n); i++)				\ 		((uint64_t *)(dstp))[i] = counter_u64_fetch((a)[i]);\ } while (0)
end_define

begin_define
define|#
directive|define
name|COUNTER_ARRAY_ZERO
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|do {			\ 	for (int i = 0; i< (n); i++)				\ 		counter_u64_zero((a)[i]);			\ } while (0)
end_define

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
comment|/* ! __SYS_COUNTER_H__ */
end_comment

end_unit

