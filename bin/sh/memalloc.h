begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)memalloc.h	8.2 (Berkeley) 5/4/95  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_struct
struct|struct
name|stackmark
block|{
name|struct
name|stack_block
modifier|*
name|stackp
decl_stmt|;
name|char
modifier|*
name|stacknxt
decl_stmt|;
name|int
name|stacknleft
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|stacknxt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|stacknleft
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sstrend
decl_stmt|;
end_decl_stmt

begin_function_decl
name|pointer
name|ckmalloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pointer
name|ckrealloc
parameter_list|(
name|pointer
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ckfree
parameter_list|(
name|pointer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|savestr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pointer
name|stalloc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stunalloc
parameter_list|(
name|pointer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|stsavestr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setstackmark
parameter_list|(
name|struct
name|stackmark
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|popstackmark
parameter_list|(
name|struct
name|stackmark
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|growstackstr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|makestrspace
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|stputbin
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|,
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|stputs
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|stackblock
parameter_list|()
value|stacknxt
end_define

begin_define
define|#
directive|define
name|stackblocksize
parameter_list|()
value|stacknleft
end_define

begin_define
define|#
directive|define
name|grabstackblock
parameter_list|(
name|n
parameter_list|)
value|stalloc(n)
end_define

begin_define
define|#
directive|define
name|STARTSTACKSTR
parameter_list|(
name|p
parameter_list|)
value|p = stackblock()
end_define

begin_define
define|#
directive|define
name|STPUTC
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|)
value|do { if (p == sstrend) p = growstackstr(); *p++ = (c); } while(0)
end_define

begin_define
define|#
directive|define
name|CHECKSTRSPACE
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|{ if ((size_t)(sstrend - p)< n) p = makestrspace(n, p); }
end_define

begin_define
define|#
directive|define
name|USTPUTC
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|)
value|(*p++ = (c))
end_define

begin_comment
comment|/*  * STACKSTRNUL's use is where we want to be able to turn a stack  * (non-sentinel, character counting string) into a C string,  * and later pretend the NUL is not there.  * Note: Because of STACKSTRNUL's semantics, STACKSTRNUL cannot be used  * on a stack that will grabstackstr()ed.  */
end_comment

begin_define
define|#
directive|define
name|STACKSTRNUL
parameter_list|(
name|p
parameter_list|)
value|(p == sstrend ? (p = growstackstr(), *p = '\0') : (*p = '\0'))
end_define

begin_define
define|#
directive|define
name|STUNPUTC
parameter_list|(
name|p
parameter_list|)
value|(--p)
end_define

begin_define
define|#
directive|define
name|STTOPC
parameter_list|(
name|p
parameter_list|)
value|p[-1]
end_define

begin_define
define|#
directive|define
name|STADJUST
parameter_list|(
name|amount
parameter_list|,
name|p
parameter_list|)
value|(p += (amount))
end_define

begin_define
define|#
directive|define
name|grabstackstr
parameter_list|(
name|p
parameter_list|)
value|stalloc((char *)p - stackblock())
end_define

begin_define
define|#
directive|define
name|ungrabstackstr
parameter_list|(
name|s
parameter_list|,
name|p
parameter_list|)
value|stunalloc((s))
end_define

begin_define
define|#
directive|define
name|STPUTBIN
parameter_list|(
name|s
parameter_list|,
name|len
parameter_list|,
name|p
parameter_list|)
value|p = stputbin((s), (len), p)
end_define

begin_define
define|#
directive|define
name|STPUTS
parameter_list|(
name|s
parameter_list|,
name|p
parameter_list|)
value|p = stputs((s), p)
end_define

end_unit

