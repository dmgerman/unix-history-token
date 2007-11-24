begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 2000,2003 Free Software Foundation, Inc.                   *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey                                                *  ****************************************************************************/
end_comment

begin_comment
comment|/* **	lib_mvcur.c **/
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: strings.c,v 1.5 2003/08/16 23:46:00 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/****************************************************************************  * Useful string functions (especially for mvcur)  ****************************************************************************/
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_STRSTR
end_if

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|char *
argument_list|)
end_macro

begin_macro
name|_nc_strstr
argument_list|(
argument|const char *haystack
argument_list|,
argument|const char *needle
argument_list|)
end_macro

begin_block
block|{
name|size_t
name|len1
init|=
name|strlen
argument_list|(
name|haystack
argument_list|)
decl_stmt|;
name|size_t
name|len2
init|=
name|strlen
argument_list|(
name|needle
argument_list|)
decl_stmt|;
name|char
modifier|*
name|result
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|(
name|len1
operator|!=
literal|0
operator|)
operator|&&
operator|(
name|len1
operator|--
operator|>=
name|len2
operator|)
condition|)
block|{
if|if
condition|(
operator|!
name|strncmp
argument_list|(
name|haystack
argument_list|,
name|needle
argument_list|,
name|len2
argument_list|)
condition|)
block|{
name|result
operator|=
name|haystack
expr_stmt|;
break|break;
block|}
name|haystack
operator|++
expr_stmt|;
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

begin_comment
comment|/*  * Initialize the descriptor so we can append to it.  Note that 'src' may  * be a null pointer (see _nc_str_null), so the corresponding strcat and  * strcpy calls have to allow for this.  */
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|string_desc *
argument_list|)
end_macro

begin_macro
name|_nc_str_init
argument_list|(
argument|string_desc * dst
argument_list|,
argument|char *src
argument_list|,
argument|size_t len
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|dst
operator|!=
literal|0
condition|)
block|{
name|dst
operator|->
name|s_head
operator|=
name|src
expr_stmt|;
name|dst
operator|->
name|s_tail
operator|=
name|src
expr_stmt|;
name|dst
operator|->
name|s_size
operator|=
name|len
operator|-
literal|1
expr_stmt|;
name|dst
operator|->
name|s_init
operator|=
name|dst
operator|->
name|s_size
expr_stmt|;
if|if
condition|(
name|src
operator|!=
literal|0
condition|)
operator|*
name|src
operator|=
literal|0
expr_stmt|;
block|}
return|return
name|dst
return|;
block|}
end_block

begin_comment
comment|/*  * Initialize the descriptor for only tracking the amount of memory used.  */
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|string_desc *
argument_list|)
end_macro

begin_macro
name|_nc_str_null
argument_list|(
argument|string_desc * dst
argument_list|,
argument|size_t len
argument_list|)
end_macro

begin_block
block|{
return|return
name|_nc_str_init
argument_list|(
name|dst
argument_list|,
literal|0
argument_list|,
name|len
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/*  * Copy a descriptor  */
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|string_desc *
argument_list|)
end_macro

begin_macro
name|_nc_str_copy
argument_list|(
argument|string_desc * dst
argument_list|,
argument|string_desc * src
argument_list|)
end_macro

begin_block
block|{
operator|*
name|dst
operator|=
operator|*
name|src
expr_stmt|;
return|return
name|dst
return|;
block|}
end_block

begin_comment
comment|/*  * Replaces strcat into a fixed buffer, returning false on failure.  */
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|bool
argument_list|)
end_macro

begin_macro
name|_nc_safe_strcat
argument_list|(
argument|string_desc * dst
argument_list|,
argument|const char *src
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|src
operator|!=
literal|0
condition|)
block|{
name|size_t
name|len
init|=
name|strlen
argument_list|(
name|src
argument_list|)
decl_stmt|;
if|if
condition|(
name|len
operator|<
name|dst
operator|->
name|s_size
condition|)
block|{
if|if
condition|(
name|dst
operator|->
name|s_tail
operator|!=
literal|0
condition|)
block|{
name|strcpy
argument_list|(
name|dst
operator|->
name|s_tail
argument_list|,
name|src
argument_list|)
expr_stmt|;
name|dst
operator|->
name|s_tail
operator|+=
name|len
expr_stmt|;
block|}
name|dst
operator|->
name|s_size
operator|-=
name|len
expr_stmt|;
return|return
name|TRUE
return|;
block|}
block|}
return|return
name|FALSE
return|;
block|}
end_block

begin_comment
comment|/*  * Replaces strcpy into a fixed buffer, returning false on failure.  */
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|bool
argument_list|)
end_macro

begin_macro
name|_nc_safe_strcpy
argument_list|(
argument|string_desc * dst
argument_list|,
argument|const char *src
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|src
operator|!=
literal|0
condition|)
block|{
name|size_t
name|len
init|=
name|strlen
argument_list|(
name|src
argument_list|)
decl_stmt|;
if|if
condition|(
name|len
operator|<
name|dst
operator|->
name|s_size
condition|)
block|{
if|if
condition|(
name|dst
operator|->
name|s_head
operator|!=
literal|0
condition|)
block|{
name|strcpy
argument_list|(
name|dst
operator|->
name|s_head
argument_list|,
name|src
argument_list|)
expr_stmt|;
name|dst
operator|->
name|s_tail
operator|=
name|dst
operator|->
name|s_head
operator|+
name|len
expr_stmt|;
block|}
name|dst
operator|->
name|s_size
operator|=
name|dst
operator|->
name|s_init
operator|-
name|len
expr_stmt|;
return|return
name|TRUE
return|;
block|}
block|}
return|return
name|FALSE
return|;
block|}
end_block

end_unit

