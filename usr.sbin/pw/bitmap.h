begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1996  *	David L. Nugent.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY DAVID L. NUGENT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL DAVID L. NUGENT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BITMAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_BITMAP_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_struct
struct|struct
name|bitmap
block|{
name|int
name|size
decl_stmt|;
name|unsigned
name|char
modifier|*
name|map
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|__BEGIN_DECLS
name|struct
name|bitmap
name|bm_alloc
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bm_dealloc
parameter_list|(
name|struct
name|bitmap
modifier|*
name|bm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bm_setbit
parameter_list|(
name|struct
name|bitmap
modifier|*
name|bm
parameter_list|,
name|int
name|pos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bm_clrbit
parameter_list|(
name|struct
name|bitmap
modifier|*
name|bm
parameter_list|,
name|int
name|pos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bm_isset
parameter_list|(
name|struct
name|bitmap
modifier|*
name|bm
parameter_list|,
name|int
name|pos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bm_firstunset
parameter_list|(
name|struct
name|bitmap
modifier|*
name|bm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bm_lastset
parameter_list|(
name|struct
name|bitmap
modifier|*
name|bm
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
comment|/* !_BITMAP_H */
end_comment

end_unit

