begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_KOBJ_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_SYS_KOBJ_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/kmem.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_define
define|#
directive|define
name|KM_NOWAIT
value|0x01
end_define

begin_define
define|#
directive|define
name|KM_TMP
value|0x02
end_define

begin_function_decl
name|void
name|kobj_free
parameter_list|(
name|void
modifier|*
name|address
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|kobj_alloc
parameter_list|(
name|size_t
name|size
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|kobj_zalloc
parameter_list|(
name|size_t
name|size
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|_buf
block|{
name|void
modifier|*
name|dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|_buf
modifier|*
name|kobj_open_file
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kobj_get_filesize
parameter_list|(
name|struct
name|_buf
modifier|*
name|file
parameter_list|,
name|uint64_t
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kobj_read_file
parameter_list|(
name|struct
name|_buf
modifier|*
name|file
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|unsigned
name|size
parameter_list|,
name|unsigned
name|off
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kobj_close_file
parameter_list|(
name|struct
name|_buf
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OPENSOLARIS_SYS_KOBJ_H_ */
end_comment

end_unit

