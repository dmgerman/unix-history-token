begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sean Eric Fagan.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)ldexp.c	8.1 (Berkeley) 6/4/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_comment
comment|/*  * ldexp(value, exp): return value * (2 ** exp).  *  * Written by Sean Eric Fagan (sef@kithrup.COM)  * Sun Mar 11 20:27:09 PST 1990  */
end_comment

begin_comment
comment|/*  * We do the conversion in C to let gcc optimize it away, if possible.  */
end_comment

begin_function
name|double
name|ldexp
parameter_list|(
name|double
name|value
parameter_list|,
name|int
name|exp
parameter_list|)
block|{
name|double
name|temp
decl_stmt|,
name|texp
decl_stmt|,
name|temp2
decl_stmt|;
name|texp
operator|=
name|exp
expr_stmt|;
ifdef|#
directive|ifdef
name|__GNUC__
asm|__asm ("fscale "
block|:
literal|"=u"
operator|(
name|temp2
operator|)
operator|,
literal|"=t"
operator|(
name|temp
operator|)
operator|:
literal|"0"
operator|(
name|texp
operator|)
operator|,
literal|"1"
operator|(
name|value
operator|)
block|)
function|;
end_function

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|unknown asm
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_return
return|return
operator|(
name|temp
operator|)
return|;
end_return

unit|}
end_unit

