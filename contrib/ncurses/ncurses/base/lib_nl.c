begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998,1999,2000 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  ****************************************************************************/
end_comment

begin_comment
comment|/*  *	nl.c  *  *	Routines:  *		nl()  *		nonl()  *  */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_nl.c,v 1.6 2000/02/13 00:59:39 tom Exp $"
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|__EMX__
end_ifdef

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|nl
parameter_list|(
name|void
parameter_list|)
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"nl()"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|SP
operator|->
name|_nl
operator|=
name|TRUE
expr_stmt|;
ifdef|#
directive|ifdef
name|__EMX__
name|_nc_flush
argument_list|()
expr_stmt|;
name|_fsetmode
argument_list|(
name|NC_OUTPUT
argument_list|,
literal|"t"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|returnCode
argument_list|(
name|OK
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|nonl
parameter_list|(
name|void
parameter_list|)
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"nonl()"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|SP
operator|->
name|_nl
operator|=
name|FALSE
expr_stmt|;
ifdef|#
directive|ifdef
name|__EMX__
name|_nc_flush
argument_list|()
expr_stmt|;
name|_fsetmode
argument_list|(
name|NC_OUTPUT
argument_list|,
literal|"b"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|returnCode
argument_list|(
name|OK
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

