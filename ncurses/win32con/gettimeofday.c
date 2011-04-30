begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 2008,2010 Free Software Foundation, Inc.                   *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|WINVER
value|0x0501
end_define

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: gettimeofday.c,v 1.2 2010/01/16 15:18:51 tom Exp $"
argument_list|)
end_macro

begin_define
define|#
directive|define
name|JAN1970
value|116444736000000000LL
end_define

begin_comment
comment|/* the value for 01/01/1970 00:00 */
end_comment

begin_function
name|int
name|gettimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
name|tv
parameter_list|,
name|void
modifier|*
name|tz
name|GCC_UNUSED
parameter_list|)
block|{
union|union
block|{
name|FILETIME
name|ft
decl_stmt|;
name|long
name|long
name|since1601
decl_stmt|;
comment|/* time since 1 Jan 1601 in 100ns units */
block|}
name|data
union|;
name|GetSystemTimeAsFileTime
argument_list|(
operator|&
name|data
operator|.
name|ft
argument_list|)
expr_stmt|;
name|tv
operator|->
name|tv_usec
operator|=
call|(
name|long
call|)
argument_list|(
operator|(
name|data
operator|.
name|since1601
operator|/
literal|10LL
operator|)
operator|%
literal|1000000LL
argument_list|)
expr_stmt|;
name|tv
operator|->
name|tv_sec
operator|=
call|(
name|long
call|)
argument_list|(
operator|(
name|data
operator|.
name|since1601
operator|-
name|JAN1970
operator|)
operator|/
literal|10000000LL
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

