begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2003,2005 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  ****************************************************************************/
end_comment

begin_comment
comment|/*  *	lib_napms.c  *  *	The routine napms.  *  *	(This file was originally written by Eric Raymond; however except for  *	comments, none of the original code remains - T.Dickey).  */
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

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_napms.c,v 1.15 2005/04/03 13:58:14 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|napms
argument_list|(
argument|int ms
argument_list|)
end_macro

begin_block
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
name|request
decl_stmt|,
name|remaining
decl_stmt|;
name|request
operator|.
name|tv_sec
operator|=
name|ms
operator|/
literal|1000
expr_stmt|;
name|request
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
while|while
condition|(
name|nanosleep
argument_list|(
operator|&
name|request
argument_list|,
operator|&
name|remaining
argument_list|)
operator|==
operator|-
literal|1
operator|&&
name|errno
operator|==
name|EINTR
condition|)
block|{
name|request
operator|=
name|remaining
expr_stmt|;
block|}
block|}
else|#
directive|else
name|_nc_timed_wait
argument_list|(
literal|0
argument_list|,
name|ms
argument_list|,
operator|(
name|int
operator|*
operator|)
literal|0
name|EVENTLIST_2nd
argument_list|(
literal|0
argument_list|)
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
end_block

end_unit

