begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Dmitry Chagin  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_VDSO_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_VDSO_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_struct
struct|struct
name|linux_vdso_sym
block|{
name|SLIST_ENTRY
argument_list|(
argument|linux_vdso_sym
argument_list|)
name|sym
expr_stmt|;
name|uint32_t
name|size
decl_stmt|;
name|uintptr_t
modifier|*
name|ptr
decl_stmt|;
name|char
name|symname
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|vm_object_t
name|__elfN
function_decl|(
name|linux_shared_page_init
function_decl|)
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__elfN
function_decl|(
name|linux_shared_page_fini
function_decl|)
parameter_list|(
name|vm_object_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__elfN
function_decl|(
name|linux_vdso_fixup
function_decl|)
parameter_list|(
name|struct
name|sysentvec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__elfN
function_decl|(
name|linux_vdso_reloc
function_decl|)
parameter_list|(
name|struct
name|sysentvec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__elfN
function_decl|(
name|linux_vdso_sym_init
function_decl|)
parameter_list|(
name|struct
name|linux_vdso_sym
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LINUX_VDSO_SYM_INTPTR
parameter_list|(
name|name
parameter_list|)
define|\
value|uintptr_t name;							\ LINUX_VDSO_SYM_DEFINE(name)
end_define

begin_define
define|#
directive|define
name|LINUX_VDSO_SYM_CHAR
parameter_list|(
name|name
parameter_list|)
define|\
value|const char * name;						\ LINUX_VDSO_SYM_DEFINE(name)
end_define

begin_define
define|#
directive|define
name|LINUX_VDSO_SYM_DEFINE
parameter_list|(
name|name
parameter_list|)
define|\
value|static struct linux_vdso_sym name ## sym = {			\ 	.symname	= #name,				\ 	.size		= sizeof(#name),			\ 	.ptr		= (uintptr_t *)&name			\ };								\ SYSINIT(__elfN(name ## _sym_init), SI_SUB_EXEC,			\     SI_ORDER_FIRST, __elfN(linux_vdso_sym_init),&name ## sym);	\ struct __hack
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_VDSO_H_ */
end_comment

end_unit

