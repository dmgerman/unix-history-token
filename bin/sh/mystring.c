begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * String functions.  *  *	equal(s1, s2)		Return true if strings are equal.  *	scopy(from, to)		Copy a string.  *	scopyn(from, to, n)	Like scopy, but checks for overflow.  *	number(s)		Convert a string of digits to an integer.  *	is_number(s)		Return true if s is a string of digits.  */
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
comment|/*  * scopy - #defined in mystring.h  */
end_comment

begin_comment
comment|/*  * scopyn - copy a string from "from" to "to", truncating the string  *		if necessary.  "To" is always nul terminated, even if  *		truncation is performed.  "Size" is the size of "to".  */
end_comment

begin_function
name|void
name|scopyn
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|,
name|size
parameter_list|)
name|char
specifier|const
modifier|*
name|from
decl_stmt|;
name|char
modifier|*
name|to
decl_stmt|;
name|int
name|size
decl_stmt|;
block|{
while|while
condition|(
operator|--
name|size
operator|>
literal|0
condition|)
block|{
if|if
condition|(
operator|(
operator|*
name|to
operator|++
operator|=
operator|*
name|from
operator|++
operator|)
operator|==
literal|'\0'
condition|)
return|return;
block|}
operator|*
name|to
operator|=
literal|'\0'
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * prefix -- see if pfx is a prefix of string.  */
end_comment

begin_function
name|int
name|prefix
parameter_list|(
name|pfx
parameter_list|,
name|string
parameter_list|)
name|char
specifier|const
modifier|*
name|pfx
decl_stmt|;
name|char
specifier|const
modifier|*
name|string
decl_stmt|;
block|{
while|while
condition|(
operator|*
name|pfx
condition|)
block|{
if|if
condition|(
operator|*
name|pfx
operator|++
operator|!=
operator|*
name|string
operator|++
condition|)
return|return
literal|0
return|;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/*  * Convert a string of digits to an integer, printing an error message on  * failure.  */
end_comment

begin_function
name|int
name|number
parameter_list|(
name|s
parameter_list|)
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
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
operator|(
name|char
operator|*
operator|)
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
name|p
parameter_list|)
specifier|const
name|char
modifier|*
name|p
decl_stmt|;
block|{
do|do
block|{
if|if
condition|(
operator|!
name|is_digit
argument_list|(
operator|*
name|p
argument_list|)
condition|)
return|return
literal|0
return|;
block|}
do|while
condition|(
operator|*
operator|++
name|p
operator|!=
literal|'\0'
condition|)
do|;
return|return
literal|1
return|;
block|}
end_function

end_unit

