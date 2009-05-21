begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_PATHNAME_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_SYS_PATHNAME_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|pathname
block|{
name|char
modifier|*
name|pn_buf
decl_stmt|;
comment|/* underlying storage */
name|char
modifier|*
name|pn_path
decl_stmt|;
comment|/* remaining pathname */
name|size_t
name|pn_pathlen
decl_stmt|;
comment|/* remaining length */
name|size_t
name|pn_bufsize
decl_stmt|;
comment|/* total size of pn_buf */
block|}
name|pathname_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|pn_alloc
parameter_list|(
name|pnp
parameter_list|)
value|panic("pn_alloc() called")
end_define

begin_define
define|#
directive|define
name|pn_free
parameter_list|(
name|pnp
parameter_list|)
value|panic("pn_free() called")
end_define

begin_function_decl
name|int
name|lookupname
parameter_list|(
name|char
modifier|*
parameter_list|,
name|enum
name|uio_seg
parameter_list|,
name|enum
name|symfollow
parameter_list|,
name|vnode_t
modifier|*
modifier|*
parameter_list|,
name|vnode_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lookupnameat
parameter_list|(
name|char
modifier|*
parameter_list|,
name|enum
name|uio_seg
parameter_list|,
name|enum
name|symfollow
parameter_list|,
name|vnode_t
modifier|*
modifier|*
parameter_list|,
name|vnode_t
modifier|*
modifier|*
parameter_list|,
name|vnode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|traverse
parameter_list|(
name|vnode_t
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OPENSOLARIS_SYS_PATHNAME_H_ */
end_comment

end_unit

