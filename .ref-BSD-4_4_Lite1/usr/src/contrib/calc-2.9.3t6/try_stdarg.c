begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * try_stdarg - try<stdarg.h> to see if it really works with vsprintf()  *  * On some systems that have both<stdarg.h> and<varargs.h>, vsprintf()  * does not work well under one type of include file.  For example, some  * System V based systems (such as UMIPS) have bugs in the<stdarg.h>  * implementation.  *  * This program exit 1 is vsprintf() produces unexpected results  * while using the<stdarg.h> include file.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994 by Landon Curt Noll.  All Rights Reserved.  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby granted,  * provided that the above copyright, this permission notice and text  * this comment, and the disclaimer below appear in all of the following:  *  *	supporting documentation  *	source copies  *	source works derived from this source  *	binaries derived from this source or from derived source  *  * LANDON CURT NOLL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO  * EVENT SHALL LANDON CURT NOLL BE LIABLE FOR ANY SPECIAL, INDIRECT OR  * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF  * USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR  * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  *  * chongo was here	/\../\  */
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|char
name|buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
name|__STDC__
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|VA_ALIST
value|char *fmt, ...
end_define

begin_define
define|#
directive|define
name|VA_DCL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VA_ALIST
value|fmt
end_define

begin_define
define|#
directive|define
name|VA_DCL
value|char *fmt;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|try
parameter_list|(
name|VA_ALIST
parameter_list|)
function|VA_DCL
block|{
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|vsprintf
argument_list|(
name|buf
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|main
parameter_list|()
block|{
name|try
argument_list|(
literal|"@%d:%s:%d@"
argument_list|,
literal|1
argument_list|,
literal|"hi"
argument_list|,
literal|2
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|buf
argument_list|,
literal|"@1:hi:2@"
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

