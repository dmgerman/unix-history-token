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
name|size_t
name|s_size
decl_stmt|;
comment|/* size of storage buffer */
name|size_t
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
name|int
name|s_flags
decl_stmt|;
comment|/* flags */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Predicates  */
end_comment

begin_define
define|#
directive|define
name|SBUF_ISDYNAMIC
parameter_list|(
name|s
parameter_list|)
value|((s)->s_flags& SBUF_DYNAMIC)
end_define

begin_define
define|#
directive|define
name|SBUF_ISFINISHED
parameter_list|(
name|s
parameter_list|)
value|((s)->s_flags& SBUF_FINISHED)
end_define

begin_define
define|#
directive|define
name|SBUF_HASOVERFLOWED
parameter_list|(
name|s
parameter_list|)
value|((s)->s_flags& SBUF_OVERFLOWED)
end_define

begin_define
define|#
directive|define
name|SBUF_HASROOM
parameter_list|(
name|s
parameter_list|)
value|((s)->s_len< (s)->s_size - 1)
end_define

begin_comment
comment|/*  * Other macros  */
end_comment

begin_define
define|#
directive|define
name|SBUF_SETFLAG
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|)
value|do { (s)->s_flags |= (f); } while (0)
end_define

begin_comment
comment|/*  * API functions  */
end_comment

begin_function_decl
name|int
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
name|size_t
name|length
parameter_list|,
name|int
name|flags
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
name|size_t
name|pos
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
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

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
name|size_t
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

