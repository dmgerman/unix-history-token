begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998,1999,2000 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  ****************************************************************************/
end_comment

begin_comment
comment|/*  *	lib_napms.c  *  *	The routine napms.  *  */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_if
if|#
directive|if
name|HAVE_NANOSLEEP
end_if

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_if
if|#
directive|if
name|HAVE_SYS_TIME_H
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* needed for MacOS X DP3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|USE_FUNC_POLL
end_elif

begin_if
if|#
directive|if
name|HAVE_SYS_TIME_H
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|HAVE_SELECT
end_elif

begin_if
if|#
directive|if
name|HAVE_SYS_TIME_H
operator|&&
name|HAVE_SYS_TIME_SELECT
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_SELECT_H
end_if

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_napms.c,v 1.9 2000/04/29 23:42:56 tom Exp $"
argument_list|)
end_macro

begin_function
name|int
name|napms
parameter_list|(
name|int
name|ms
parameter_list|)
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"napms(%d)"
argument_list|)
operator|,
name|ms
operator|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|HAVE_NANOSLEEP
block|{
name|struct
name|timespec
name|ts
decl_stmt|;
name|ts
operator|.
name|tv_sec
operator|=
name|ms
operator|/
literal|1000
expr_stmt|;
name|ts
operator|.
name|tv_nsec
operator|=
operator|(
name|ms
operator|%
literal|1000
operator|)
operator|*
literal|1000000
expr_stmt|;
name|nanosleep
argument_list|(
operator|&
name|ts
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
elif|#
directive|elif
name|USE_FUNC_POLL
block|{
name|struct
name|pollfd
name|fds
index|[
literal|1
index|]
decl_stmt|;
name|poll
argument_list|(
name|fds
argument_list|,
literal|0
argument_list|,
name|ms
argument_list|)
expr_stmt|;
block|}
elif|#
directive|elif
name|HAVE_SELECT
block|{
name|struct
name|timeval
name|tval
decl_stmt|;
name|tval
operator|.
name|tv_sec
operator|=
name|ms
operator|/
literal|1000
expr_stmt|;
name|tval
operator|.
name|tv_usec
operator|=
operator|(
name|ms
operator|%
literal|1000
operator|)
operator|*
literal|1000
expr_stmt|;
name|select
argument_list|(
literal|0
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
operator|&
name|tval
argument_list|)
expr_stmt|;
block|}
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

