begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: atomicio.h,v 1.11 2010/09/22 22:58:51 djm Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2006 Damien Miller.  All rights reserved.  * Copyright (c) 1995,1999 Theo de Raadt.  All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATOMICIO_H
end_ifndef

begin_define
define|#
directive|define
name|_ATOMICIO_H
end_define

begin_comment
comment|/*  * Ensure all of data on socket comes through. f==read || f==vwrite  */
end_comment

begin_function_decl
name|size_t
name|atomicio6
parameter_list|(
name|ssize_t
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
parameter_list|,
name|int
name|fd
parameter_list|,
name|void
modifier|*
name|_s
parameter_list|,
name|size_t
name|n
parameter_list|,
name|int
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|atomicio
parameter_list|(
name|ssize_t
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|vwrite
value|(ssize_t (*)(int, void *, size_t))write
end_define

begin_comment
comment|/*  * ensure all of data on socket comes through. f==readv || f==writev  */
end_comment

begin_function_decl
name|size_t
name|atomiciov6
parameter_list|(
name|ssize_t
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|iovec
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|int
name|fd
parameter_list|,
specifier|const
name|struct
name|iovec
modifier|*
name|_iov
parameter_list|,
name|int
name|iovcnt
parameter_list|,
name|int
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|atomiciov
parameter_list|(
name|ssize_t
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|iovec
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|iovec
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
comment|/* _ATOMICIO_H */
end_comment

end_unit

