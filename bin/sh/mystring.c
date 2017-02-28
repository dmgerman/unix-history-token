begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)mystring.c	8.2 (Berkeley) 5/4/95";
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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

begin_comment
comment|/*  * String functions.  *  *	equal(s1, s2)		Return true if strings are equal.  *	number(s)		Convert a string of digits to an integer.  *	is_number(s)		Return true if s is a string of digits.  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"shell.h"
end_include

begin_include
include|#
directive|include
file|"syntax.h"
end_include

begin_include
include|#
directive|include
file|"error.h"
end_include

begin_include
include|#
directive|include
file|"mystring.h"
end_include

begin_decl_stmt
name|char
name|nullstr
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* zero length string */
end_comment

begin_comment
comment|/*  * equal - #defined in mystring.h  */
end_comment

begin_comment
comment|/*  * Convert a string of digits to an integer, printing an error message on  * failure.  */
end_comment

begin_function
name|int
name|number
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
block|{
if|if
condition|(
operator|!
name|is_number
argument_list|(
name|s
argument_list|)
condition|)
name|error
argument_list|(
literal|"Illegal number: %s"
argument_list|,
name|s
argument_list|)
expr_stmt|;
return|return
name|atoi
argument_list|(
name|s
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Check for a valid number.  This should be elsewhere.  */
end_comment

begin_function
name|int
name|is_number
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|q
decl_stmt|;
if|if
condition|(
operator|*
name|p
operator|==
literal|'\0'
condition|)
return|return
literal|0
return|;
while|while
condition|(
operator|*
name|p
operator|==
literal|'0'
condition|)
name|p
operator|++
expr_stmt|;
for|for
control|(
name|q
operator|=
name|p
init|;
operator|*
name|q
operator|!=
literal|'\0'
condition|;
name|q
operator|++
control|)
if|if
condition|(
operator|!
name|is_digit
argument_list|(
operator|*
name|q
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|q
operator|-
name|p
operator|>
literal|10
operator|||
operator|(
name|q
operator|-
name|p
operator|==
literal|10
operator|&&
name|memcmp
argument_list|(
name|p
argument_list|,
literal|"2147483647"
argument_list|,
literal|10
argument_list|)
operator|>
literal|0
operator|)
condition|)
return|return
literal|0
return|;
return|return
literal|1
return|;
block|}
end_function

end_unit

