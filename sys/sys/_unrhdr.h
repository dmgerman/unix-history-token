begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Poul-Henning Kamp  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_UNRHDR_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_UNRHDR_H
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_struct_decl
struct_decl|struct
name|mtx
struct_decl|;
end_struct_decl

begin_comment
comment|/* Header element for a unr number space. */
end_comment

begin_struct
struct|struct
name|unrhdr
block|{
name|TAILQ_HEAD
argument_list|(
argument|unrhd
argument_list|,
argument|unr
argument_list|)
name|head
expr_stmt|;
name|u_int
name|low
decl_stmt|;
comment|/* Lowest item */
name|u_int
name|high
decl_stmt|;
comment|/* Highest item */
name|u_int
name|busy
decl_stmt|;
comment|/* Count of allocated items */
name|u_int
name|alloc
decl_stmt|;
comment|/* Count of memory allocations */
name|u_int
name|first
decl_stmt|;
comment|/* items in allocated from start */
name|u_int
name|last
decl_stmt|;
comment|/* items free at end */
name|struct
name|mtx
modifier|*
name|mtx
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument|unrfr
argument_list|,
argument|unr
argument_list|)
name|ppfree
expr_stmt|;
comment|/* Items to be freed after mtx 					   lock dropped */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

