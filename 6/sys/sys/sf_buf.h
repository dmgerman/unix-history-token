begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2004 Alan L. Cox<alc@cs.rice.edu>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SF_BUF_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SF_BUF_H_
end_define

begin_include
include|#
directive|include
file|<machine/sf_buf.h>
end_include

begin_comment
comment|/*  * Options to sf_buf_alloc() are specified through its flags argument.  This  * argument's value should be the result of a bitwise or'ing of one or more  * of the following values.  */
end_comment

begin_define
define|#
directive|define
name|SFB_CATCH
value|1
end_define

begin_comment
comment|/* Check signals if the allocation 					   sleeps. */
end_comment

begin_define
define|#
directive|define
name|SFB_CPUPRIVATE
value|2
end_define

begin_comment
comment|/* Create a CPU private mapping. */
end_comment

begin_define
define|#
directive|define
name|SFB_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|SFB_NOWAIT
value|4
end_define

begin_comment
comment|/* Return NULL if all bufs are used. */
end_comment

begin_struct_decl
struct_decl|struct
name|vm_page
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|nsfbufs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of sendfile(2) bufs alloced */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nsfbufspeak
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Peak of nsfbufsused */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nsfbufsused
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of sendfile(2) bufs in use */
end_comment

begin_function_decl
name|struct
name|sf_buf
modifier|*
name|sf_buf_alloc
parameter_list|(
name|struct
name|vm_page
modifier|*
name|m
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sf_buf_free
parameter_list|(
name|struct
name|sf_buf
modifier|*
name|sf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sf_buf_mext
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|void
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SF_BUF_H_ */
end_comment

end_unit

