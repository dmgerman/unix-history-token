begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2002,2005 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  *     and: Thomas E. Dickey                        1996-on                 *  ****************************************************************************/
end_comment

begin_comment
comment|/*  *	comp_error.c -- Error message routines  *  */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_include
include|#
directive|include
file|<tic.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: comp_error.c,v 1.30 2005/11/26 15:28:47 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT_VAR
argument_list|(
argument|bool
argument_list|)
end_macro

begin_expr_stmt
name|_nc_suppress_warnings
operator|=
name|FALSE
expr_stmt|;
end_expr_stmt

begin_macro
name|NCURSES_EXPORT_VAR
argument_list|(
argument|int
argument_list|)
end_macro

begin_expr_stmt
name|_nc_curr_line
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* current line # in input */
end_comment

begin_macro
name|NCURSES_EXPORT_VAR
argument_list|(
argument|int
argument_list|)
end_macro

begin_expr_stmt
name|_nc_curr_col
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* current column # in input */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|sourcename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|termtype
decl_stmt|;
end_decl_stmt

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|const char *
argument_list|)
end_macro

begin_macro
name|_nc_get_source
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
return|return
name|sourcename
return|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_set_source
argument_list|(
argument|const char *const name
argument_list|)
end_macro

begin_block
block|{
name|sourcename
operator|=
name|name
expr_stmt|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_set_type
argument_list|(
argument|const char *const name
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|termtype
operator|==
literal|0
condition|)
name|termtype
operator|=
name|typeMalloc
argument_list|(
name|char
argument_list|,
name|MAX_NAME_SIZE
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|termtype
operator|!=
literal|0
condition|)
block|{
name|termtype
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|name
condition|)
name|strncat
argument_list|(
name|termtype
argument_list|,
name|name
argument_list|,
name|MAX_NAME_SIZE
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_get_type
argument_list|(
argument|char *name
argument_list|)
end_macro

begin_block
block|{
if|#
directive|if
name|NO_LEAKS
if|if
condition|(
name|name
operator|==
literal|0
operator|&&
name|termtype
operator|!=
literal|0
condition|)
block|{
name|FreeAndNull
argument_list|(
name|termtype
argument_list|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
if|if
condition|(
name|name
operator|!=
literal|0
condition|)
name|strcpy
argument_list|(
name|name
argument_list|,
name|termtype
operator|!=
literal|0
condition|?
name|termtype
else|:
literal|""
argument_list|)
expr_stmt|;
block|}
end_block

begin_function
specifier|static
name|NCURSES_INLINE
name|void
name|where_is_problem
parameter_list|(
name|void
parameter_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\"%s\""
argument_list|,
name|sourcename
argument_list|)
expr_stmt|;
if|if
condition|(
name|_nc_curr_line
operator|>=
literal|0
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|", line %d"
argument_list|,
name|_nc_curr_line
argument_list|)
expr_stmt|;
if|if
condition|(
name|_nc_curr_col
operator|>=
literal|0
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|", col %d"
argument_list|,
name|_nc_curr_col
argument_list|)
expr_stmt|;
if|if
condition|(
name|termtype
operator|!=
literal|0
operator|&&
name|termtype
index|[
literal|0
index|]
operator|!=
literal|'\0'
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|", terminal '%s'"
argument_list|,
name|termtype
argument_list|)
expr_stmt|;
name|fputc
argument_list|(
literal|':'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|fputc
argument_list|(
literal|' '
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_warning
argument_list|(
argument|const char *const fmt
argument_list|,
argument|...
argument_list|)
end_macro

begin_block
block|{
name|va_list
name|argp
decl_stmt|;
if|if
condition|(
name|_nc_suppress_warnings
condition|)
return|return;
name|where_is_problem
argument_list|()
expr_stmt|;
name|va_start
argument_list|(
name|argp
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|vfprintf
argument_list|(
name|stderr
argument_list|,
name|fmt
argument_list|,
name|argp
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|argp
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_err_abort
argument_list|(
argument|const char *const fmt
argument_list|,
argument|...
argument_list|)
end_macro

begin_block
block|{
name|va_list
name|argp
decl_stmt|;
name|where_is_problem
argument_list|()
expr_stmt|;
name|va_start
argument_list|(
name|argp
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|vfprintf
argument_list|(
name|stderr
argument_list|,
name|fmt
argument_list|,
name|argp
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|argp
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_syserr_abort
argument_list|(
argument|const char *const fmt
argument_list|,
argument|...
argument_list|)
end_macro

begin_block
block|{
name|va_list
name|argp
decl_stmt|;
name|where_is_problem
argument_list|()
expr_stmt|;
name|va_start
argument_list|(
name|argp
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|vfprintf
argument_list|(
name|stderr
argument_list|,
name|fmt
argument_list|,
name|argp
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|argp
argument_list|)
expr_stmt|;
comment|/* If we're debugging, try to show where the problem occurred - this      * will dump core.      */
if|#
directive|if
name|defined
argument_list|(
name|TRACE
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|NDEBUG
argument_list|)
name|abort
argument_list|()
expr_stmt|;
else|#
directive|else
comment|/* Dumping core in production code is not a good idea.      */
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_block

end_unit

