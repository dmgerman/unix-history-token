begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2011,2012 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  *     and: Thomas E. Dickey                        1996-on                 *  *     and: Juergen Pfeifer                         2009                    *  ****************************************************************************/
end_comment

begin_comment
comment|/* **	lib_ungetch.c ** **	The routine ungetch(). ** */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_ungetch.c,v 1.16 2012/08/04 17:38:53 tom Exp $"
argument_list|)
end_macro

begin_include
include|#
directive|include
file|<fifo_defs.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_fifo_dump
argument_list|(
argument|SCREEN *sp
argument_list|)
end_macro

begin_block
block|{
name|int
name|i
decl_stmt|;
name|T
argument_list|(
operator|(
literal|"head = %d, tail = %d, peek = %d"
operator|,
name|head
operator|,
name|tail
operator|,
name|peek
operator|)
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
name|i
operator|++
control|)
name|T
argument_list|(
operator|(
literal|"char %d = %s"
operator|,
name|i
operator|,
name|_nc_tracechar
argument_list|(
name|sp
argument_list|,
name|sp
operator|->
name|_fifo
index|[
name|i
index|]
argument_list|)
operator|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TRACE */
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|safe_ungetch
argument_list|(
argument|SCREEN *sp
argument_list|,
argument|int ch
argument_list|)
end_macro

begin_block
block|{
name|int
name|rc
init|=
name|ERR
decl_stmt|;
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"ungetch(%p,%s)"
argument_list|)
operator|,
operator|(
name|void
operator|*
operator|)
name|sp
operator|,
name|_nc_tracechar
argument_list|(
name|sp
argument_list|,
name|ch
argument_list|)
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|sp
operator|!=
literal|0
operator|&&
name|tail
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
name|head
operator|<
literal|0
condition|)
block|{
name|head
operator|=
literal|0
expr_stmt|;
name|t_inc
argument_list|()
expr_stmt|;
name|peek
operator|=
name|tail
expr_stmt|;
comment|/* no raw keys */
block|}
else|else
block|{
name|h_dec
argument_list|()
expr_stmt|;
block|}
name|sp
operator|->
name|_fifo
index|[
name|head
index|]
operator|=
name|ch
expr_stmt|;
name|T
argument_list|(
operator|(
literal|"ungetch %s ok"
operator|,
name|_nc_tracechar
argument_list|(
name|sp
argument_list|,
name|ch
argument_list|)
operator|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|TRACE
if|if
condition|(
name|USE_TRACEF
argument_list|(
name|TRACE_IEVENT
argument_list|)
condition|)
block|{
name|_nc_fifo_dump
argument_list|(
name|sp
argument_list|)
expr_stmt|;
name|_nc_unlock_global
argument_list|(
name|tracef
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|rc
operator|=
name|OK
expr_stmt|;
block|}
name|returnCode
argument_list|(
name|rc
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|ungetch
argument_list|(
argument|int ch
argument_list|)
end_macro

begin_block
block|{
return|return
name|safe_ungetch
argument_list|(
name|CURRENT_SCREEN
argument_list|,
name|ch
argument_list|)
return|;
block|}
end_block

end_unit

