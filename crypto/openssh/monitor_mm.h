begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: monitor_mm.h,v 1.2 2002/03/26 03:24:01 stevesk Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright 2002 Niels Provos<provos@citi.umich.edu>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MM_H_
end_ifndef

begin_define
define|#
directive|define
name|_MM_H_
end_define

begin_include
include|#
directive|include
file|"openbsd-compat/sys-tree.h"
end_include

begin_struct
struct|struct
name|mm_share
block|{
name|RB_ENTRY
argument_list|(
argument|mm_share
argument_list|)
name|next
expr_stmt|;
name|void
modifier|*
name|address
decl_stmt|;
name|size_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mm_master
block|{
name|RB_HEAD
argument_list|(
argument|mmtree
argument_list|,
argument|mm_share
argument_list|)
name|rb_free
expr_stmt|;
name|struct
name|mmtree
name|rb_allocated
decl_stmt|;
name|void
modifier|*
name|address
decl_stmt|;
name|size_t
name|size
decl_stmt|;
name|struct
name|mm_master
modifier|*
name|mmalloc
decl_stmt|;
comment|/* Used to completely share */
name|int
name|write
decl_stmt|;
comment|/* used to writing to other party */
name|int
name|read
decl_stmt|;
comment|/* used for reading from other party */
block|}
struct|;
end_struct

begin_macro
name|RB_PROTOTYPE
argument_list|(
argument|mmtree
argument_list|,
argument|mm_share
argument_list|,
argument|next
argument_list|,
argument|mm_compare
argument_list|)
end_macro

begin_define
define|#
directive|define
name|MM_MINSIZE
value|128
end_define

begin_define
define|#
directive|define
name|MM_ADDRESS_END
parameter_list|(
name|x
parameter_list|)
value|(void *)((u_char *)(x)->address + (x)->size)
end_define

begin_function_decl
name|struct
name|mm_master
modifier|*
name|mm_create
parameter_list|(
name|struct
name|mm_master
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mm_destroy
parameter_list|(
name|struct
name|mm_master
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mm_share_sync
parameter_list|(
name|struct
name|mm_master
modifier|*
modifier|*
parameter_list|,
name|struct
name|mm_master
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|mm_malloc
parameter_list|(
name|struct
name|mm_master
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|mm_xmalloc
parameter_list|(
name|struct
name|mm_master
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mm_free
parameter_list|(
name|struct
name|mm_master
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mm_memvalid
parameter_list|(
name|struct
name|mm_master
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MM_H_ */
end_comment

end_unit

