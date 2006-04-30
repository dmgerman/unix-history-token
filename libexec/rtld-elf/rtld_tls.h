begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * Semi-public interface from thread libraries to rtld for managing  * TLS.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RTLD_TLS_H_
end_ifndef

begin_define
define|#
directive|define
name|_RTLD_TLS_H_
end_define

begin_comment
comment|/*  * Allocate a TLS block for a new thread. The memory allocated will  * include 'tcbsize' bytes aligned to a 'tcbalign' boundary (in bytes)  * for the thread library's private purposes. The location of the TCB  * block is returned by this function. For architectures using  * 'Variant I' TLS, the thread local storage follows the TCB, and for  * 'Variant II', the thread local storage precedes it. For  * architectures using the 'Variant II' model (e.g. i386, amd64,  * sparc64), the TCB must begin with two pointer fields which are used  * by rtld for its TLS implementation. For the 'Variant I' model, the  * TCB must begin with a single pointer field for rtld's  * implementation.  *  * If the value of 'oldtls' is non-NULL, the new TLS block will be  * initialised using the values contained in 'oldtls' and 'oldtls'  * will be freed. This is typically used when initialising a thread  * library to migrate from using the initial bootstrap TLS block  * created by rtld to one which contains suitable thread library  * private data.  *  * The value returned from this function is suitable for installing  * directly into the thread pointer register.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|_rtld_allocate_tls
parameter_list|(
name|void
modifier|*
name|oldtls
parameter_list|,
name|size_t
name|tcbsize
parameter_list|,
name|size_t
name|tcbalign
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Free a TLS block allocated using _rtld_allocate_tls(). The tcbsize  * and tcbalign parameters must be the same as those used to allocate  * the block.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_rtld_free_tls
parameter_list|(
name|void
modifier|*
name|tcb
parameter_list|,
name|size_t
name|tcbsize
parameter_list|,
name|size_t
name|tcbalign
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

