begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1999 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_include
include|#
directive|include
file|<term.h>
end_include

begin_comment
comment|/* keypad_xmit, keypad_local, meta_on, meta_off */
end_comment

begin_comment
comment|/* cursor_visible,cursor_normal,cursor_invisible */
end_comment

begin_include
include|#
directive|include
file|<tic.h>
end_include

begin_comment
comment|/* struct tinfo_fkeys */
end_comment

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: init_keytry.c,v 1.3 2000/03/12 02:55:50 Todd.C.Miller Exp $"
argument_list|)
end_macro

begin_comment
comment|/* **      _nc_init_keytry() ** **      Construct the try for the current terminal's keypad keys. ** */
end_comment

begin_if
if|#
directive|if
name|BROKEN_LINKER
end_if

begin_undef
undef|#
directive|undef
name|_nc_tinfo_fkeys
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LINT_PREPRO #if 0*/
end_comment

begin_include
include|#
directive|include
file|<init_keytry.h>
end_include

begin_comment
comment|/* LINT_PREPRO #endif*/
end_comment

begin_if
if|#
directive|if
name|BROKEN_LINKER
end_if

begin_function
name|struct
name|tinfo_fkeys
modifier|*
name|_nc_tinfo_fkeysf
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|_nc_tinfo_fkeys
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|_nc_init_keytry
parameter_list|(
name|void
parameter_list|)
block|{
name|size_t
name|n
decl_stmt|;
comment|/* The SP->_keytry value is initialized in newterm(), where the SP 	 * structure is created, because we can not tell where keypad() or 	 * mouse_activate() (which will call keyok()) are first called. 	 */
for|for
control|(
name|n
operator|=
literal|0
init|;
name|_nc_tinfo_fkeys
index|[
name|n
index|]
operator|.
name|code
condition|;
name|n
operator|++
control|)
if|if
condition|(
name|_nc_tinfo_fkeys
index|[
name|n
index|]
operator|.
name|offset
operator|<
name|STRCOUNT
condition|)
name|_nc_add_to_try
argument_list|(
argument|&(SP->_keytry)
argument_list|,
argument|CUR Strings[_nc_tinfo_fkeys[n].offset]
argument_list|,
argument|_nc_tinfo_fkeys[n].code
argument_list|)
empty_stmt|;
ifdef|#
directive|ifdef
name|TRACE
name|_nc_trace_tries
argument_list|(
name|SP
operator|->
name|_keytry
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

