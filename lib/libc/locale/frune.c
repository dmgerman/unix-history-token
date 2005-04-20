begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Tim J. Robbins. All rights reserved.  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Paul Borman at Krystal Technologies.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* f*rune() are obsolete in FreeBSD 6 -- use ANSI functions instead. */
end_comment

begin_define
define|#
directive|define
name|OBSOLETE_IN_6
end_define

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
literal|"@(#)frune.c	8.1 (Berkeley) 6/4/93"
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
file|<sys/param.h>
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
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<rune.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_expr_stmt
name|__warn_references
argument_list|(
name|fgetrune
argument_list|,
literal|"warning: fgetrune() is deprecated. See fgetrune(3)."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|long
name|fgetrune
parameter_list|(
name|fp
parameter_list|)
name|FILE
modifier|*
name|fp
decl_stmt|;
block|{
name|wint_t
name|ch
decl_stmt|;
if|if
condition|(
operator|(
name|ch
operator|=
name|fgetwc
argument_list|(
name|fp
argument_list|)
operator|)
operator|==
name|WEOF
condition|)
return|return
operator|(
name|feof
argument_list|(
name|fp
argument_list|)
condition|?
name|EOF
else|:
name|_INVALID_RUNE
operator|)
return|;
return|return
operator|(
operator|(
name|long
operator|)
name|ch
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|__warn_references
argument_list|(
name|fungetrune
argument_list|,
literal|"warning: fungetrune() is deprecated. See fungetrune(3)."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|fungetrune
parameter_list|(
name|r
parameter_list|,
name|fp
parameter_list|)
name|rune_t
name|r
decl_stmt|;
name|FILE
modifier|*
name|fp
decl_stmt|;
block|{
return|return
operator|(
name|ungetwc
argument_list|(
operator|(
name|wint_t
operator|)
name|r
argument_list|,
name|fp
argument_list|)
operator|==
name|WEOF
condition|?
name|EOF
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|__warn_references
argument_list|(
name|fputrune
argument_list|,
literal|"warning: fputrune() is deprecated. See fputrune(3)."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|fputrune
parameter_list|(
name|r
parameter_list|,
name|fp
parameter_list|)
name|rune_t
name|r
decl_stmt|;
name|FILE
modifier|*
name|fp
decl_stmt|;
block|{
return|return
operator|(
name|fputwc
argument_list|(
operator|(
name|wchar_t
operator|)
name|r
argument_list|,
name|fp
argument_list|)
operator|==
name|WEOF
condition|?
name|EOF
else|:
literal|0
operator|)
return|;
block|}
end_function

end_unit

