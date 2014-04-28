begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2000,2012 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey<dickey@clark.net> 1998                        *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * Wrapper for malloc/realloc.  Standard implementations allow realloc with  * a null pointer, but older libraries may not (e.g., SunOS).  *  * Also if realloc fails, we discard the old memory to avoid leaks.  */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: doalloc.c,v 1.11 2012/11/03 19:27:41 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void *
argument_list|)
end_macro

begin_macro
name|_nc_doalloc
argument_list|(
argument|void *oldp
argument_list|,
argument|size_t amount
argument_list|)
end_macro

begin_block
block|{
name|void
modifier|*
name|newp
decl_stmt|;
if|if
condition|(
name|oldp
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
operator|(
name|newp
operator|=
name|realloc
argument_list|(
name|oldp
argument_list|,
name|amount
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|free
argument_list|(
name|oldp
argument_list|)
expr_stmt|;
name|errno
operator|=
name|ENOMEM
expr_stmt|;
comment|/* just in case 'free' reset */
block|}
block|}
else|else
block|{
name|newp
operator|=
name|malloc
argument_list|(
name|amount
argument_list|)
expr_stmt|;
block|}
return|return
name|newp
return|;
block|}
end_block

end_unit

