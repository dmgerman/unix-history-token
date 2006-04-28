begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Michael Bushkov<bushman@rsu.ru>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CACHED_DEBUG_H__
end_ifndef

begin_define
define|#
directive|define
name|__CACHED_DEBUG_H__
end_define

begin_define
define|#
directive|define
name|TRACE_WANTED
value|32
end_define

begin_comment
comment|/* #ifndef NDEBUG */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|TRACE_IN
parameter_list|(
name|x
parameter_list|)
value|__trace_in(#x, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|TRACE_POINT
parameter_list|()
value|__trace_point(__FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|TRACE_MSG
parameter_list|(
name|x
parameter_list|)
value|__trace_msg(x, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|TRACE_PTR
parameter_list|(
name|p
parameter_list|)
value|__trace_ptr(#p, p, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|TRACE_INT
parameter_list|(
name|i
parameter_list|)
value|__trace_int(#i, i, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|TRACE_STR
parameter_list|(
name|s
parameter_list|)
value|__trace_str(#s, s, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|TRACE_OUT
parameter_list|(
name|x
parameter_list|)
value|__trace_out(#x, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|TRACE_ON
parameter_list|()
value|__trace_on()
end_define

begin_define
define|#
directive|define
name|TRACE_OFF
parameter_list|()
value|__trace_off()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TRACE_IN
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_POINT
parameter_list|()
end_define

begin_define
define|#
directive|define
name|TRACE_MSG
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_PTR
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_INT
parameter_list|(
name|i
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_STR
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_OUT
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_ON
parameter_list|()
end_define

begin_define
define|#
directive|define
name|TRACE_OFF
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|__trace_in
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__trace_point
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__trace_msg
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__trace_ptr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__trace_int
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__trace_str
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__trace_out
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__trace_on
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__trace_off
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

