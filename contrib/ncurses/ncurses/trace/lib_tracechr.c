begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  ****************************************************************************/
end_comment

begin_comment
comment|/*  *	lib_tracechr.c - Tracing/Debugging routines  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TRACE
end_ifndef

begin_define
define|#
directive|define
name|TRACE
end_define

begin_comment
comment|/* turn on internal defs for this module */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_function
name|char
modifier|*
name|_tracechar
parameter_list|(
specifier|const
name|unsigned
name|char
name|ch
parameter_list|)
block|{
specifier|static
name|char
name|crep
index|[
literal|20
index|]
decl_stmt|;
comment|/*       * We can show the actual character if it's either an ordinary printable      * or one of the high-half characters.      */
if|if
condition|(
name|isprint
argument_list|(
name|ch
argument_list|)
operator|||
operator|(
name|ch
operator|&
literal|0x80
operator|)
condition|)
block|{
name|crep
index|[
literal|0
index|]
operator|=
literal|'\''
expr_stmt|;
name|crep
index|[
literal|1
index|]
operator|=
name|ch
expr_stmt|;
comment|/* necessary; printf tries too hard on metachars */
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|crep
operator|+
literal|2
argument_list|,
literal|"' = 0x%02x"
argument_list|,
operator|(
name|unsigned
operator|)
name|ch
argument_list|)
expr_stmt|;
block|}
else|else
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|crep
argument_list|,
literal|"0x%02x"
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
end_function

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|_nc_lib_tracechr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|_nc_lib_tracechr
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

