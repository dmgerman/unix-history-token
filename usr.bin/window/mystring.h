begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Edward Wang at The University of California, Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)string.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|STR_DEBUG
end_define

begin_function_decl
name|char
modifier|*
name|str_cpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|str_ncpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|str_cat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|str_itoa
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|str_cmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strcmp(a, b)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|STR_DEBUG
end_ifdef

begin_struct
struct|struct
name|mystring
block|{
name|struct
name|mystring
modifier|*
name|s_forw
decl_stmt|;
name|struct
name|mystring
modifier|*
name|s_back
decl_stmt|;
name|char
name|s_data
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|mystring
name|str_head
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|str_offset
value|((unsigned)str_head.s_data - (unsigned)&str_head)
end_define

begin_define
define|#
directive|define
name|str_stos
parameter_list|(
name|s
parameter_list|)
value|((struct mystring *)((unsigned)(s) - str_offset))
end_define

begin_function_decl
name|char
modifier|*
name|str_alloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|str_free
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|str_free
parameter_list|(
name|s
parameter_list|)
value|free(s)
end_define

begin_define
define|#
directive|define
name|str_alloc
parameter_list|(
name|s
parameter_list|)
value|malloc(s)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

