begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * Define stubs for TLS internals so that programs and libraries can  * link. These functions will be replaced by functional versions at  * runtime from ld-elf.so.1.  */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_function_decl
specifier|extern
name|void
modifier|*
name|___tls_get_addr
parameter_list|(
name|void
modifier|*
name|ti
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__regparm__
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_pragma
pragma|#
directive|pragma
name|weak
name|___tls_get_addr
end_pragma

begin_macro
name|__attribute__
argument_list|(
argument|(__regparm__(
literal|1
argument|))
argument_list|)
end_macro

begin_function
name|void
modifier|*
name|___tls_get_addr
parameter_list|(
name|void
modifier|*
name|ti
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_pragma
pragma|#
directive|pragma
name|weak
name|__tls_get_addr
end_pragma

begin_function
name|void
modifier|*
name|__tls_get_addr
parameter_list|()
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_pragma
pragma|#
directive|pragma
name|weak
name|_rtld_allocate_tls
end_pragma

begin_function
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
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_pragma
pragma|#
directive|pragma
name|weak
name|_rtld_free_tls
end_pragma

begin_function
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
block|{ }
end_function

end_unit

