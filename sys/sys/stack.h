begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Antoine Brodin  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_STACK_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_STACK_H_
end_define

begin_define
define|#
directive|define
name|STACK_MAX
value|18
end_define

begin_comment
comment|/* Don't change, stack_ktr relies on this. */
end_comment

begin_struct_decl
struct_decl|struct
name|sbuf
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|stack
block|{
name|int
name|depth
decl_stmt|;
name|vm_offset_t
name|pcs
index|[
name|STACK_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* MI Routines. */
end_comment

begin_function_decl
name|struct
name|stack
modifier|*
name|stack_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stack_destroy
parameter_list|(
name|struct
name|stack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stack_put
parameter_list|(
name|struct
name|stack
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stack_copy
parameter_list|(
name|struct
name|stack
modifier|*
parameter_list|,
name|struct
name|stack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stack_zero
parameter_list|(
name|struct
name|stack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stack_print
parameter_list|(
name|struct
name|stack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stack_sbuf_print
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|,
name|struct
name|stack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|KTR
end_ifdef

begin_function_decl
name|void
name|stack_ktr
parameter_list|(
name|u_int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|stack
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CTRSTACK
parameter_list|(
name|m
parameter_list|,
name|st
parameter_list|,
name|depth
parameter_list|,
name|cheap
parameter_list|)
value|do {				\ 	if (KTR_COMPILE& (m))						\ 		stack_ktr((m), __FILE__, __LINE__, st, depth, cheap);	\ 	} while(0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CTRSTACK
parameter_list|(
name|m
parameter_list|,
name|st
parameter_list|,
name|depth
parameter_list|,
name|cheap
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MD Routine. */
end_comment

begin_function_decl
name|void
name|stack_save
parameter_list|(
name|struct
name|stack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

