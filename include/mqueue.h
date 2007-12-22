begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 David Xu<davidxu@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MQUEUE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MQUEUE_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/mqueue.h>
end_include

begin_struct_decl
struct_decl|struct
name|sigevent
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|timespec
struct_decl|;
end_struct_decl

begin_function_decl
name|__BEGIN_DECLS
name|int
name|mq_close
parameter_list|(
name|mqd_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mq_getattr
parameter_list|(
name|mqd_t
parameter_list|,
name|struct
name|mq_attr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mq_notify
parameter_list|(
name|mqd_t
parameter_list|,
specifier|const
name|struct
name|sigevent
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mqd_t
name|mq_open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|mq_receive
parameter_list|(
name|mqd_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|unsigned
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mq_send
parameter_list|(
name|mqd_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mq_setattr
parameter_list|(
name|mqd_t
parameter_list|,
specifier|const
name|struct
name|mq_attr
modifier|*
name|__restrict
parameter_list|,
name|struct
name|mq_attr
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|mq_timedreceive
parameter_list|(
name|mqd_t
parameter_list|,
name|char
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|,
name|unsigned
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mq_timedsend
parameter_list|(
name|mqd_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|unsigned
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mq_unlink
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__mq_oshandle
parameter_list|(
name|mqd_t
name|mqd
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

end_unit

