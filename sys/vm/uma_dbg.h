begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002, 2003, 2004, 2005 Jeffrey Roberson<jeff@FreeBSD.org>  * Copyright (c) 2004, 2005 Bosko Milekic<bmilekic@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*   *  * This file includes definitions, structures, prototypes, and inlines used  * when debugging users of the UMA interface.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VM_UMA_DBG_H
end_ifndef

begin_define
define|#
directive|define
name|VM_UMA_DBG_H
end_define

begin_function_decl
name|int
name|trash_ctor
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|,
name|int
name|size
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trash_dtor
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|,
name|int
name|size
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|trash_init
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trash_fini
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* For use only by malloc */
end_comment

begin_function_decl
name|int
name|mtrash_ctor
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|,
name|int
name|size
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mtrash_dtor
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|,
name|int
name|size
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mtrash_init
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mtrash_fini
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uma_dbg_free
parameter_list|(
name|uma_zone_t
name|zone
parameter_list|,
name|uma_slab_t
name|slab
parameter_list|,
name|void
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uma_dbg_alloc
parameter_list|(
name|uma_zone_t
name|zone
parameter_list|,
name|uma_slab_t
name|slab
parameter_list|,
name|void
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VM_UMA_DBG_H */
end_comment

end_unit

