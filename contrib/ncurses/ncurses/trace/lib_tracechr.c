begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2001,2002 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  ****************************************************************************/
end_comment

begin_comment
comment|/*  *	lib_tracechr.c - Tracing/Debugging routines  */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_tracechr.c,v 1.8 2002/02/10 01:26:04 tom Exp $"
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|char *
argument_list|)
end_macro

begin_macro
name|_tracechar
argument_list|(
argument|int ch
argument_list|)
end_macro

begin_block
block|{
specifier|static
name|char
name|crep
index|[
literal|40
index|]
decl_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|crep
argument_list|,
literal|"'%.30s' = %#03o"
argument_list|,
operator|(
name|ch
operator|>
name|KEY_MIN
operator|)
condition|?
name|keyname
argument_list|(
name|ch
argument_list|)
else|:
name|unctrl
argument_list|(
name|ch
argument_list|)
argument_list|,
operator|(
name|unsigned
operator|)
name|ch
argument_list|)
expr_stmt|;
return|return
operator|(
name|crep
operator|)
return|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_macro
name|empty_module
argument_list|(
argument|_nc_lib_tracechr
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

