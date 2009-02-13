begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 2007 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/* **	lib_key_name.c ** **	The routine key_name(). ** */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_key_name.c,v 1.2 2007/06/12 21:01:13 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|NCURSES_CONST char *
argument_list|)
end_macro

begin_macro
name|key_name
argument_list|(
argument|wchar_t c
argument_list|)
end_macro

begin_block
block|{
name|cchar_t
name|my_cchar
decl_stmt|;
name|wchar_t
modifier|*
name|my_wchars
decl_stmt|;
name|size_t
name|len
decl_stmt|;
comment|/* FIXME: move to _nc_globals */
specifier|static
name|char
name|result
index|[
name|MB_LEN_MAX
operator|+
literal|1
index|]
decl_stmt|;
name|memset
argument_list|(
operator|&
name|my_cchar
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|my_cchar
argument_list|)
argument_list|)
expr_stmt|;
name|my_cchar
operator|.
name|chars
index|[
literal|0
index|]
operator|=
name|c
expr_stmt|;
name|my_cchar
operator|.
name|chars
index|[
literal|1
index|]
operator|=
literal|L'
expr|\0'
expr_stmt|;
name|my_wchars
operator|=
name|wunctrl
argument_list|(
operator|&
name|my_cchar
argument_list|)
expr_stmt|;
name|len
operator|=
name|wcstombs
argument_list|(
name|result
argument_list|,
name|my_wchars
argument_list|,
sizeof|sizeof
argument_list|(
name|result
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|isEILSEQ
argument_list|(
name|len
argument_list|)
operator|||
operator|(
name|len
operator|==
literal|0
operator|)
condition|)
block|{
return|return
literal|"UNKNOWN KEY"
return|;
block|}
name|result
index|[
name|len
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
name|result
return|;
block|}
end_block

end_unit

