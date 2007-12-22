begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 2001-2003,2005 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/* **	lib_wunctrl.c ** **	The routine wunctrl(). ** */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_if
if|#
directive|if
name|USE_WIDEC_SUPPORT
end_if

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_wunctrl.c,v 1.8 2005/04/16 18:10:44 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|wchar_t *
argument_list|)
end_macro

begin_macro
name|wunctrl
argument_list|(
argument|cchar_t *wc
argument_list|)
end_macro

begin_block
block|{
specifier|static
name|wchar_t
name|str
index|[
literal|5
index|]
decl_stmt|,
modifier|*
name|sp
decl_stmt|;
if|if
condition|(
name|Charable
argument_list|(
operator|*
name|wc
argument_list|)
condition|)
block|{
specifier|const
name|char
modifier|*
name|p
init|=
name|unctrl
argument_list|(
operator|(
name|unsigned
operator|)
name|_nc_to_char
argument_list|(
operator|(
name|wint_t
operator|)
name|CharOf
argument_list|(
operator|*
name|wc
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
for|for
control|(
name|sp
operator|=
name|str
init|;
operator|*
name|p
condition|;
control|)
operator|*
name|sp
operator|++
operator|=
name|_nc_to_widechar
argument_list|(
operator|*
name|p
operator|++
argument_list|)
expr_stmt|;
return|return
name|str
return|;
block|}
else|else
return|return
name|wc
operator|->
name|chars
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

