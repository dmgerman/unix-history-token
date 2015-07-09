begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Nuxi, https://nuxi.nl/  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CLOUDABI64_SYSCALLDEFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_CLOUDABI64_SYSCALLDEFS_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<compat/cloudabi/cloudabi_syscalldefs.h>
end_include

begin_typedef
typedef|typedef
name|uint64_t
name|cloudabi64_size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|cloudabi64_uintptr_t
typedef|;
end_typedef

begin_comment
comment|/* Import machine-dependent CloudABI definitions for 64-bit systems. */
end_comment

begin_define
define|#
directive|define
name|IDENT
parameter_list|(
name|ident
parameter_list|)
value|cloudabi64_##ident
end_define

begin_define
define|#
directive|define
name|PTR
parameter_list|(
name|type
parameter_list|)
value|cloudabi64_uintptr_t
end_define

begin_include
include|#
directive|include
file|<contrib/cloudabi/syscalldefs_md.h>
end_include

begin_undef
undef|#
directive|undef
name|IDENT
end_undef

begin_undef
undef|#
directive|undef
name|PTR
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

