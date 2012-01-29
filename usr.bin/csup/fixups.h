begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006, Maxime Henrion<mux@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FIXUPS_H_
end_ifndef

begin_define
define|#
directive|define
name|_FIXUPS_H_
end_define

begin_include
include|#
directive|include
file|"queue.h"
end_include

begin_struct_decl
struct_decl|struct
name|coll
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fixups
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|fixup
block|{
name|struct
name|coll
modifier|*
name|f_coll
decl_stmt|;
name|char
modifier|*
name|f_name
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|fixup
argument_list|)
name|f_link
expr_stmt|;
comment|/* Not for consumers. */
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|fixups
modifier|*
name|fixups_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fixups_put
parameter_list|(
name|struct
name|fixups
modifier|*
parameter_list|,
name|struct
name|coll
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|fixup
modifier|*
name|fixups_get
parameter_list|(
name|struct
name|fixups
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fixups_close
parameter_list|(
name|struct
name|fixups
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fixups_free
parameter_list|(
name|struct
name|fixups
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FIXUPS_H_ */
end_comment

end_unit

