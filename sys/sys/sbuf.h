begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Poul-Henning Kamp and Dag-Erling Coïdan Smørgrav  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *      $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SBUF_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SBUF_H_
end_define

begin_comment
comment|/*  * Structure definition  */
end_comment

begin_struct
struct|struct
name|sbuf
block|{
name|char
modifier|*
name|s_buf
decl_stmt|;
comment|/* storage buffer */
name|struct
name|sbuf
modifier|*
name|s_next
decl_stmt|;
comment|/* next in chain */
name|int
name|s_size
decl_stmt|;
comment|/* size of storage buffer */
name|int
name|s_len
decl_stmt|;
comment|/* current length of string */
define|#
directive|define
name|SBUF_AUTOEXTEND
value|0x00000001
comment|/* automatically extend buffer */
define|#
directive|define
name|SBUF_DYNAMIC
value|0x00010000
comment|/* s_buf must be freed */
define|#
directive|define
name|SBUF_FINISHED
value|0x00020000
comment|/* set by sbuf_finish() */
define|#
directive|define
name|SBUF_OVERFLOWED
value|0x00040000
comment|/* sbuf overflowed */
define|#
directive|define
name|SBUF_DYNSTRUCT
value|0x00080000
comment|/* sbuf must be freed */
name|int
name|s_flags
decl_stmt|;
comment|/* flags */
block|}
struct|;
end_struct

begin_function_decl
name|__BEGIN_DECLS
comment|/*  * API functions  */
name|struct
name|sbuf
modifier|*
name|sbuf_new
parameter_list|(
name|struct
name|sbuf
modifier|*
name|s
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|length
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbuf_clear
parameter_list|(
name|struct
name|sbuf
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbuf_setpos
parameter_list|(
name|struct
name|sbuf
modifier|*
name|s
parameter_list|,
name|int
name|pos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbuf_bcat
parameter_list|(
name|struct
name|sbuf
modifier|*
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbuf_bcpy
parameter_list|(
name|struct
name|sbuf
modifier|*
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbuf_cat
parameter_list|(
name|struct
name|sbuf
modifier|*
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbuf_cpy
parameter_list|(
name|struct
name|sbuf
modifier|*
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbuf_printf
parameter_list|(
name|struct
name|sbuf
modifier|*
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|sbuf_putc
parameter_list|(
name|struct
name|sbuf
modifier|*
name|s
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbuf_overflowed
parameter_list|(
name|struct
name|sbuf
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbuf_finish
parameter_list|(
name|struct
name|sbuf
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|sbuf_data
parameter_list|(
name|struct
name|sbuf
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbuf_len
parameter_list|(
name|struct
name|sbuf
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbuf_delete
parameter_list|(
name|struct
name|sbuf
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|int
name|sbuf_bcopyin
parameter_list|(
name|struct
name|sbuf
modifier|*
name|s
parameter_list|,
specifier|const
name|void
modifier|*
name|uaddr
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbuf_copyin
parameter_list|(
name|struct
name|sbuf
modifier|*
name|s
parameter_list|,
specifier|const
name|void
modifier|*
name|uaddr
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

