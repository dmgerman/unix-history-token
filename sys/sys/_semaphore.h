begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Alfred Perlstein<alfred@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SEMAPHORE_H_
end_ifndef

begin_define
define|#
directive|define
name|__SEMAPHORE_H_
end_define

begin_typedef
typedef|typedef
name|intptr_t
name|semid_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|timespec
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|SEM_VALUE_MAX
value|__INT_MAX
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
name|__BEGIN_DECLS
name|int
name|ksem_close
parameter_list|(
name|semid_t
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksem_post
parameter_list|(
name|semid_t
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksem_wait
parameter_list|(
name|semid_t
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksem_trywait
parameter_list|(
name|semid_t
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksem_timedwait
parameter_list|(
name|semid_t
name|id
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
name|abstime
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksem_init
parameter_list|(
name|semid_t
modifier|*
name|idp
parameter_list|,
name|unsigned
name|int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksem_open
parameter_list|(
name|semid_t
modifier|*
name|idp
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|oflag
parameter_list|,
name|mode_t
name|mode
parameter_list|,
name|unsigned
name|int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksem_unlink
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksem_getvalue
parameter_list|(
name|semid_t
name|id
parameter_list|,
name|int
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksem_destroy
parameter_list|(
name|semid_t
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SEMAPHORE_H_ */
end_comment

end_unit

