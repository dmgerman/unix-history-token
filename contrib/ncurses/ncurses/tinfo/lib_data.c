begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2005,2007 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  *     and: Thomas E. Dickey                        1996-on                 *  ****************************************************************************/
end_comment

begin_comment
comment|/* **	lib_data.c ** **	Common data that may/may not be allocated, but is referenced globally ** */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_data.c,v 1.34 2007/10/20 21:49:10 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/*  * OS/2's native linker complains if we don't initialize public data when  * constructing a dll (reported by J.J.G.Ripoll).  */
end_comment

begin_if
if|#
directive|if
name|USE_REENTRANT
end_if

begin_function
name|NCURSES_EXPORT
function|(
name|WINDOW
modifier|*
function|)
name|NCURSES_PUBLIC_VAR
argument_list|(
argument|stdscr
argument_list|)
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|SP
condition|?
name|SP
operator|->
name|_stdscr
else|:
literal|0
return|;
block|}
end_function

begin_function
name|NCURSES_EXPORT
function|(
name|WINDOW
modifier|*
function|)
name|NCURSES_PUBLIC_VAR
argument_list|(
argument|curscr
argument_list|)
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|SP
condition|?
name|SP
operator|->
name|_curscr
else|:
literal|0
return|;
block|}
end_function

begin_function
name|NCURSES_EXPORT
function|(
name|WINDOW
modifier|*
function|)
name|NCURSES_PUBLIC_VAR
argument_list|(
argument|newscr
argument_list|)
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|SP
condition|?
name|SP
operator|->
name|_newscr
else|:
literal|0
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_macro
name|NCURSES_EXPORT_VAR
argument_list|(
argument|WINDOW *
argument_list|)
end_macro

begin_expr_stmt
name|stdscr
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_macro
name|NCURSES_EXPORT_VAR
argument_list|(
argument|WINDOW *
argument_list|)
end_macro

begin_expr_stmt
name|curscr
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_macro
name|NCURSES_EXPORT_VAR
argument_list|(
argument|WINDOW *
argument_list|)
end_macro

begin_expr_stmt
name|newscr
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|NCURSES_EXPORT_VAR
argument_list|(
argument|SCREEN *
argument_list|)
end_macro

begin_expr_stmt
name|_nc_screen_chain
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * The variable 'SP' will be defined as a function on systems that cannot link  * data-only modules, since it is used in a lot of places within ncurses and we  * cannot guarantee that any application will use any particular function.  We  * put the WINDOW variables in this module, because it appears that any  * application that uses them will also use 'SP'.  *  * This module intentionally does not reference other ncurses modules, to avoid  * module coupling that increases the size of the executable.  */
end_comment

begin_if
if|#
directive|if
name|BROKEN_LINKER
end_if

begin_decl_stmt
specifier|static
name|SCREEN
modifier|*
name|my_screen
decl_stmt|;
end_decl_stmt

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|SCREEN *
argument_list|)
end_macro

begin_macro
name|_nc_screen
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
return|return
name|my_screen
return|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|_nc_alloc_screen
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
return|return
operator|(
operator|(
name|my_screen
operator|=
name|typeCalloc
argument_list|(
name|SCREEN
argument_list|,
literal|1
argument_list|)
operator|)
operator|!=
literal|0
operator|)
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
name|_nc_set_screen
argument_list|(
argument|SCREEN *sp
argument_list|)
end_macro

begin_block
block|{
name|my_screen
operator|=
name|sp
expr_stmt|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_macro
name|NCURSES_EXPORT_VAR
argument_list|(
argument|SCREEN *
argument_list|)
end_macro

begin_expr_stmt
name|SP
operator|=
name|NULL
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Some linkers require initialized data... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* *INDENT-OFF* */
end_comment

begin_define
define|#
directive|define
name|CHARS_0s
value|{ '\0' }
end_define

begin_define
define|#
directive|define
name|TGETENT_0
value|{ 0L, FALSE, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|TGETENT_0s
value|{ TGETENT_0, TGETENT_0, TGETENT_0, TGETENT_0 }
end_define

begin_macro
name|NCURSES_EXPORT_VAR
argument_list|(
argument|NCURSES_GLOBALS
argument_list|)
end_macro

begin_expr_stmt
name|_nc_globals
operator|=
block|{
literal|0
block|,
comment|/* have_sigwinch */
literal|0
block|,
comment|/* cleanup_nested */
name|FALSE
block|,
comment|/* init_signals */
name|FALSE
block|,
comment|/* init_screen */
name|NULL
block|,
comment|/* comp_sourcename */
name|NULL
block|,
comment|/* comp_termtype */
name|FALSE
block|,
comment|/* have_tic_directory */
name|FALSE
block|,
comment|/* keep_tic_directory */
name|TERMINFO
block|,
comment|/* tic_directory */
name|NULL
block|,
comment|/* dbi_list */
literal|0
block|,
comment|/* dbi_size */
name|NULL
block|,
comment|/* first_name */
name|NULL
block|,
comment|/* keyname_table */
name|NULL
block|,
comment|/* safeprint_buf */
literal|0
block|,
comment|/* safeprint_used */
name|TGETENT_0s
block|,
comment|/* tgetent_cache */
literal|0
block|,
comment|/* tgetent_index */
literal|0
block|,
comment|/* tgetent_sequence */
if|#
directive|if
name|USE_HOME_TERMINFO
name|NULL
block|,
comment|/* home_terminfo */
endif|#
directive|endif
if|#
directive|if
operator|!
name|USE_SAFE_SPRINTF
literal|0
block|,
comment|/* safeprint_cols */
literal|0
block|,
comment|/* safeprint_rows */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TRACE
name|FALSE
block|,
comment|/* init_trace */
name|CHARS_0s
block|,
comment|/* trace_fname */
literal|0
block|,
comment|/* trace_level */
name|NULL
block|,
comment|/* trace_fp */
name|NULL
block|,
comment|/* tracearg_buf */
literal|0
block|,
comment|/* tracearg_used */
name|NULL
block|,
comment|/* tracebuf_ptr */
literal|0
block|,
comment|/* tracebuf_used */
name|CHARS_0s
block|,
comment|/* tracechr_buf */
name|NULL
block|,
comment|/* tracedmp_buf */
literal|0
block|,
comment|/* tracedmp_used */
name|CHARS_0s
block|,
comment|/* tracemse_buf */
name|NULL
block|,
comment|/* tracetry_buf */
literal|0
block|,
comment|/* tracetry_used */
ifndef|#
directive|ifndef
name|USE_TERMLIB
block|{
name|CHARS_0s
block|,
name|CHARS_0s
block|}
block|,
comment|/* traceatr_color_buf */
literal|0
block|,
comment|/* traceatr_color_sel */
operator|-
literal|1
block|,
comment|/* traceatr_color_last */
endif|#
directive|endif
comment|/* USE_TERMLIB */
endif|#
directive|endif
comment|/* TRACE */
ifdef|#
directive|ifdef
name|USE_PTHREADS
name|PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
block|,
comment|/* mutex_set_SP */
name|PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
block|,
comment|/* mutex_use_screen */
name|PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
block|,
comment|/* mutex_use_window */
name|PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
block|,
comment|/* mutex_windowlist */
name|PTHREAD_MUTEX_INITIALIZER
block|,
comment|/* mutex_tst_tracef */
name|PTHREAD_MUTEX_INITIALIZER
block|,
comment|/* mutex_tracef */
literal|0
block|,
comment|/* nested_tracef */
endif|#
directive|endif
block|}
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|STACK_FRAME_0
value|{ { 0 }, 0 }
end_define

begin_define
define|#
directive|define
name|STACK_FRAME_0s
value|{ STACK_FRAME_0 }
end_define

begin_define
define|#
directive|define
name|NUM_VARS_0s
value|{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
end_define

begin_define
define|#
directive|define
name|RIPOFF_0
value|{ 0,0 }
end_define

begin_define
define|#
directive|define
name|RIPOFF_0s
value|{ RIPOFF_0 }
end_define

begin_macro
name|NCURSES_EXPORT_VAR
argument_list|(
argument|NCURSES_PRESCREEN
argument_list|)
end_macro

begin_expr_stmt
name|_nc_prescreen
operator|=
block|{
name|TRUE
block|,
comment|/* use_env */
name|FALSE
block|,
comment|/* filter_mode */
name|A_NORMAL
block|,
comment|/* previous_attr */
name|RIPOFF_0s
block|,
comment|/* ripoff */
name|NULL
block|,
comment|/* rsp */
block|{
comment|/* tparm_state */
ifdef|#
directive|ifdef
name|TRACE
name|NULL
block|,
comment|/* tname */
endif|#
directive|endif
name|NULL
block|,
comment|/* tparam_base */
name|STACK_FRAME_0s
block|,
comment|/* stack */
literal|0
block|,
comment|/* stack_ptr */
name|NULL
block|,
comment|/* out_buff */
literal|0
block|,
comment|/* out_size */
literal|0
block|,
comment|/* out_used */
name|NULL
block|,
comment|/* fmt_buff */
literal|0
block|,
comment|/* fmt_size */
name|NUM_VARS_0s
block|,
comment|/* dynamic_var */
name|NUM_VARS_0s
block|,
comment|/* static_vars */
block|}
block|,
name|NULL
block|,
comment|/* saved_tty */
if|#
directive|if
name|BROKEN_LINKER
operator|||
name|USE_REENTRANT
name|NULL
block|,
comment|/* real_acs_map */
literal|0
block|,
comment|/* LINES */
literal|0
block|,
comment|/* COLS */
ifdef|#
directive|ifdef
name|TRACE
literal|0L
block|,
comment|/* _outchars */
name|NULL
block|,
comment|/* _tputs_trace */
endif|#
directive|endif
endif|#
directive|endif
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* *INDENT-ON* */
end_comment

end_unit

