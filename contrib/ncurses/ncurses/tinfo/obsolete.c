begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 2013 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey                        2013                    *  ****************************************************************************/
end_comment

begin_comment
comment|/* **	Support for obsolete features. */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: obsolete.c,v 1.1 2013/01/26 22:07:51 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/*  * Obsolete entrypoint retained for binary compatbility.  */
end_comment

begin_function
name|NCURSES_EXPORT
function|(
name|void
function|)
name|NCURSES_SP_NAME
argument_list|(
argument|_nc_set_buffer
argument_list|)
parameter_list|(
name|NCURSES_SP_DCLx
name|FILE
modifier|*
name|ofp
parameter_list|,
name|int
name|buffered
parameter_list|)
block|{
if|#
directive|if
name|NCURSES_SP_FUNCS
operator|(
name|void
operator|)
name|SP_PARM
expr_stmt|;
endif|#
directive|endif
operator|(
name|void
operator|)
name|ofp
expr_stmt|;
operator|(
name|void
operator|)
name|buffered
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
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_set_buffer
argument_list|(
argument|FILE *ofp
argument_list|,
argument|int buffered
argument_list|)
end_macro

begin_block
block|{
name|NCURSES_SP_NAME
function_decl|(
name|_nc_set_buffer
function_decl|)
parameter_list|(
name|CURRENT_SCREEN
parameter_list|,
name|ofp
parameter_list|,
name|buffered
parameter_list|)
function_decl|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_STRDUP
end_if

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|char *
argument_list|)
end_macro

begin_macro
name|_nc_strdup
argument_list|(
argument|const char *s
argument_list|)
end_macro

begin_block
block|{
name|char
modifier|*
name|result
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|s
operator|!=
literal|0
condition|)
block|{
name|size_t
name|need
init|=
name|strlen
argument_list|(
name|s
argument_list|)
decl_stmt|;
name|result
operator|=
name|malloc
argument_list|(
name|need
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|!=
literal|0
condition|)
block|{
name|strcpy
argument_list|(
name|result
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|result
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|USE_MY_MEMMOVE
end_if

begin_define
define|#
directive|define
name|DST
value|((char *)s1)
end_define

begin_define
define|#
directive|define
name|SRC
value|((const char *)s2)
end_define

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void *
argument_list|)
end_macro

begin_macro
name|_nc_memmove
argument_list|(
argument|void *s1
argument_list|,
argument|const void *s2
argument_list|,
argument|size_t n
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|n
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
operator|(
name|DST
operator|+
name|n
operator|>
name|SRC
operator|)
operator|&&
operator|(
name|SRC
operator|+
name|n
operator|>
name|DST
operator|)
condition|)
block|{
specifier|static
name|char
modifier|*
name|bfr
decl_stmt|;
specifier|static
name|size_t
name|length
decl_stmt|;
specifier|register
name|size_t
name|j
decl_stmt|;
if|if
condition|(
name|length
operator|<
name|n
condition|)
block|{
name|length
operator|=
operator|(
name|n
operator|*
literal|3
operator|)
operator|/
literal|2
expr_stmt|;
name|bfr
operator|=
name|typeRealloc
argument_list|(
name|char
argument_list|,
name|length
argument_list|,
name|bfr
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|n
condition|;
name|j
operator|++
control|)
name|bfr
index|[
name|j
index|]
operator|=
name|SRC
index|[
name|j
index|]
expr_stmt|;
name|s2
operator|=
name|bfr
expr_stmt|;
block|}
while|while
condition|(
name|n
operator|--
operator|!=
literal|0
condition|)
name|DST
index|[
name|n
index|]
operator|=
name|SRC
index|[
name|n
index|]
expr_stmt|;
block|}
return|return
name|s1
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_MY_MEMMOVE */
end_comment

end_unit

