begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: memmove.c,v 1.2 1999/02/27 19:55:57 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey<dickey@clark.net> 1998                        *  ****************************************************************************/
end_comment

begin_if
if|#
directive|if
name|USE_MY_MEMMOVE
end_if

begin_define
define|#
directive|define
name|DST
value|((char *)s1)
end_define

begin_define
define|#
directive|define
name|SRC
value|((const char *)s2)
end_define

begin_function
name|void
modifier|*
name|_nc_memmove
parameter_list|(
name|void
modifier|*
name|s1
parameter_list|,
specifier|const
name|void
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
if|if
condition|(
name|n
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
operator|(
name|DST
operator|+
name|n
operator|>
name|SRC
operator|)
operator|&&
operator|(
name|SRC
operator|+
name|n
operator|>
name|DST
operator|)
condition|)
block|{
specifier|static
name|char
modifier|*
name|bfr
decl_stmt|;
specifier|static
name|size_t
name|length
decl_stmt|;
specifier|register
name|size_t
name|j
decl_stmt|;
if|if
condition|(
name|length
operator|<
name|n
condition|)
block|{
name|length
operator|=
operator|(
name|n
operator|*
literal|3
operator|)
operator|/
literal|2
expr_stmt|;
name|bfr
operator|=
name|typeRealloc
argument_list|(
name|char
argument_list|,
name|length
argument_list|,
name|bfr
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|n
condition|;
name|j
operator|++
control|)
name|bfr
index|[
name|j
index|]
operator|=
name|SRC
index|[
name|j
index|]
expr_stmt|;
name|SRC
operator|=
name|bfr
expr_stmt|;
block|}
while|while
condition|(
name|n
operator|--
operator|!=
literal|0
condition|)
name|DST
index|[
name|n
index|]
operator|=
name|SRC
index|[
name|n
index|]
expr_stmt|;
block|}
return|return
name|s1
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|_nc_memmove
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* quiet's gcc warning */
end_comment

begin_function
name|void
name|_nc_memmove
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* nonempty for strict ANSI compilers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_MY_MEMMOVE */
end_comment

end_unit

