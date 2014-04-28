begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1999-2009,2011 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey                        1999-on                 *  *     and: Juergen Pfeifer                         2009                    *  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: keybound.c,v 1.11 2011/10/22 16:47:05 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/*  * Returns the count'th string definition which is associated with the  * given keycode.  The result is malloc'd, must be freed by the caller.  */
end_comment

begin_function
name|NCURSES_EXPORT
function|(
name|char
modifier|*
function|)
name|NCURSES_SP_NAME
argument_list|(
argument|keybound
argument_list|)
parameter_list|(
name|NCURSES_SP_DCLx
name|int
name|code
parameter_list|,
name|int
name|count
parameter_list|)
block|{
name|char
modifier|*
name|result
init|=
literal|0
decl_stmt|;
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"keybound(%p, %d,%d)"
argument_list|)
operator|,
operator|(
name|void
operator|*
operator|)
name|SP_PARM
operator|,
name|code
operator|,
name|count
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|SP_PARM
operator|!=
literal|0
operator|&&
name|code
operator|>=
literal|0
condition|)
block|{
name|result
operator|=
name|_nc_expand_try
argument_list|(
name|SP_PARM
operator|->
name|_keytry
argument_list|,
operator|(
name|unsigned
operator|)
name|code
argument_list|,
operator|&
name|count
argument_list|,
operator|(
name|size_t
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
name|returnPtr
argument_list|(
name|result
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
name|NCURSES_SP_FUNCS
end_if

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|char *
argument_list|)
end_macro

begin_macro
name|keybound
argument_list|(
argument|int code
argument_list|,
argument|int count
argument_list|)
end_macro

begin_block
block|{
return|return
name|NCURSES_SP_NAME
argument_list|(
name|keybound
argument_list|)
argument_list|(
name|CURRENT_SCREEN
argument_list|,
name|code
argument_list|,
name|count
argument_list|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

