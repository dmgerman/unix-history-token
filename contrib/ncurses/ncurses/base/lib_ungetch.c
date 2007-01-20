begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2001,2002 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  ****************************************************************************/
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
literal|"$Id: lib_ungetch.c,v 1.8 2002/08/24 22:08:48 tom Exp $"
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
argument|void
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
name|_tracechar
argument_list|(
name|SP
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
name|ungetch
argument_list|(
argument|int ch
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"ungetch(%s)"
argument_list|)
operator|,
name|_tracechar
argument_list|(
name|ch
argument_list|)
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|tail
operator|==
operator|-
literal|1
condition|)
name|returnCode
argument_list|(
name|ERR
argument_list|)
expr_stmt|;
if|if
condition|(
name|head
operator|==
operator|-
literal|1
condition|)
block|{
name|head
operator|=
literal|0
expr_stmt|;
name|t_inc
argument_list|()
name|peek
operator|=
name|tail
expr_stmt|;
comment|/* no raw keys */
block|}
else|else
name|h_dec
argument_list|()
expr_stmt|;
name|SP
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
name|_tracechar
argument_list|(
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
name|_nc_tracing
operator|&
name|TRACE_IEVENT
condition|)
name|_nc_fifo_dump
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|returnCode
argument_list|(
name|OK
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

