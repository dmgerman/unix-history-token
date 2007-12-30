begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2006,2007 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  *     and: Thomas E. Dickey                        1996-on                 *  ****************************************************************************/
end_comment

begin_comment
comment|/*  *	lib_trace.c - Tracing/Debugging routines  *  * The _tracef() function is originally from pcurses (by Pavel Curtis) in 1982.   * pcurses allowed one to enable/disable tracing using traceon() and traceoff()  * functions.  ncurses provides a trace() function which allows one to  * selectively enable or disable several tracing features.  */
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

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_trace.c,v 1.65 2007/09/29 21:47:46 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT_VAR
argument_list|(
argument|unsigned
argument_list|)
end_macro

begin_expr_stmt
name|_nc_tracing
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* always define this */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_if
if|#
directive|if
name|USE_REENTRANT
end_if

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|const char *
argument_list|)
end_macro

begin_function
name|NCURSES_PUBLIC_VAR
function|(
name|_nc_tputs_trace
function|)
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|SP
condition|?
name|SP
operator|->
name|_tputs_trace
else|:
name|_nc_prescreen
operator|.
name|_tputs_trace
return|;
block|}
end_function

begin_function
name|NCURSES_EXPORT
function|(
name|long
function|)
name|NCURSES_PUBLIC_VAR
argument_list|(
argument|_nc_outchars
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
name|_outchars
else|:
name|_nc_prescreen
operator|.
name|_outchars
return|;
block|}
end_function

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_set_tputs_trace
argument_list|(
argument|const char *s
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|SP
condition|)
name|SP
operator|->
name|_tputs_trace
operator|=
name|s
expr_stmt|;
else|else
name|_nc_prescreen
operator|.
name|_tputs_trace
operator|=
name|s
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
name|_nc_count_outchars
argument_list|(
argument|long increment
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|SP
condition|)
name|SP
operator|->
name|_outchars
operator|+=
name|increment
expr_stmt|;
else|else
name|_nc_prescreen
operator|.
name|_outchars
operator|+=
name|increment
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
argument|const char *
argument_list|)
end_macro

begin_expr_stmt
name|_nc_tputs_trace
operator|=
literal|""
expr_stmt|;
end_expr_stmt

begin_macro
name|NCURSES_EXPORT_VAR
argument_list|(
argument|long
argument_list|)
end_macro

begin_expr_stmt
name|_nc_outchars
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TraceFP
value|_nc_globals.trace_fp
end_define

begin_define
define|#
directive|define
name|TracePath
value|_nc_globals.trace_fname
end_define

begin_define
define|#
directive|define
name|TraceLevel
value|_nc_globals.trace_level
end_define

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|trace
argument_list|(
argument|const unsigned int tracelevel
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
operator|(
name|TraceFP
operator|==
literal|0
operator|)
operator|&&
name|tracelevel
condition|)
block|{
specifier|const
name|char
modifier|*
name|mode
init|=
name|_nc_globals
operator|.
name|init_trace
condition|?
literal|"ab"
else|:
literal|"wb"
decl_stmt|;
if|if
condition|(
name|TracePath
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
block|{
if|if
condition|(
name|getcwd
argument_list|(
name|TracePath
argument_list|,
sizeof|sizeof
argument_list|(
name|TracePath
argument_list|)
operator|-
literal|12
argument_list|)
operator|==
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"curses: Can't get working directory"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
block|}
name|strcat
argument_list|(
name|TracePath
argument_list|,
literal|"/trace"
argument_list|)
expr_stmt|;
if|if
condition|(
name|_nc_is_dir_path
argument_list|(
name|TracePath
argument_list|)
condition|)
block|{
name|strcat
argument_list|(
name|TracePath
argument_list|,
literal|".log"
argument_list|)
expr_stmt|;
block|}
block|}
name|_nc_globals
operator|.
name|init_trace
operator|=
name|TRUE
expr_stmt|;
name|_nc_tracing
operator|=
name|tracelevel
expr_stmt|;
if|if
condition|(
name|_nc_access
argument_list|(
name|TracePath
argument_list|,
name|W_OK
argument_list|)
operator|<
literal|0
operator|||
operator|(
name|TraceFP
operator|=
name|fopen
argument_list|(
name|TracePath
argument_list|,
name|mode
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"curses: Can't open 'trace' file"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
block|}
comment|/* Try to set line-buffered mode, or (failing that) unbuffered, 	 * so that the trace-output gets flushed automatically at the 	 * end of each line.  This is useful in case the program dies.  	 */
if|#
directive|if
name|HAVE_SETVBUF
comment|/* ANSI */
operator|(
name|void
operator|)
name|setvbuf
argument_list|(
name|TraceFP
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|,
name|_IOLBF
argument_list|,
literal|0
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|HAVE_SETBUF
comment|/* POSIX */
operator|(
name|void
operator|)
name|setbuffer
argument_list|(
name|TraceFP
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|_tracef
argument_list|(
literal|"TRACING NCURSES version %s.%d (tracelevel=%#x)"
argument_list|,
name|NCURSES_VERSION
argument_list|,
name|NCURSES_VERSION_PATCH
argument_list|,
name|tracelevel
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|tracelevel
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|TraceFP
operator|!=
literal|0
condition|)
block|{
name|fclose
argument_list|(
name|TraceFP
argument_list|)
expr_stmt|;
name|TraceFP
operator|=
literal|0
expr_stmt|;
block|}
name|_nc_tracing
operator|=
name|tracelevel
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|_nc_tracing
operator|!=
name|tracelevel
condition|)
block|{
name|_nc_tracing
operator|=
name|tracelevel
expr_stmt|;
name|_tracef
argument_list|(
literal|"tracelevel=%#x"
argument_list|,
name|tracelevel
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_function
specifier|static
name|void
name|_nc_va_tracef
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
block|{
specifier|static
specifier|const
name|char
name|Called
index|[]
init|=
name|T_CALLED
argument_list|(
literal|""
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|char
name|Return
index|[]
init|=
name|T_RETURN
argument_list|(
literal|""
argument_list|)
decl_stmt|;
name|bool
name|before
init|=
name|FALSE
decl_stmt|;
name|bool
name|after
init|=
name|FALSE
decl_stmt|;
name|unsigned
name|doit
init|=
name|_nc_tracing
decl_stmt|;
name|int
name|save_err
init|=
name|errno
decl_stmt|;
if|if
condition|(
name|strlen
argument_list|(
name|fmt
argument_list|)
operator|>=
sizeof|sizeof
argument_list|(
name|Called
argument_list|)
operator|-
literal|1
condition|)
block|{
if|if
condition|(
operator|!
name|strncmp
argument_list|(
name|fmt
argument_list|,
name|Called
argument_list|,
sizeof|sizeof
argument_list|(
name|Called
argument_list|)
operator|-
literal|1
argument_list|)
condition|)
block|{
name|before
operator|=
name|TRUE
expr_stmt|;
name|TraceLevel
operator|++
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|strncmp
argument_list|(
name|fmt
argument_list|,
name|Return
argument_list|,
sizeof|sizeof
argument_list|(
name|Return
argument_list|)
operator|-
literal|1
argument_list|)
condition|)
block|{
name|after
operator|=
name|TRUE
expr_stmt|;
block|}
if|if
condition|(
name|before
operator|||
name|after
condition|)
block|{
if|if
condition|(
operator|(
name|TraceLevel
operator|<=
literal|1
operator|)
operator|||
operator|(
name|doit
operator|&
name|TRACE_ICALLS
operator|)
operator|!=
literal|0
condition|)
name|doit
operator|&=
operator|(
name|TRACE_CALLS
operator||
name|TRACE_CCALLS
operator|)
expr_stmt|;
else|else
name|doit
operator|=
literal|0
expr_stmt|;
block|}
block|}
if|if
condition|(
name|doit
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|TraceFP
operator|==
literal|0
condition|)
name|TraceFP
operator|=
name|stderr
expr_stmt|;
if|if
condition|(
name|before
operator|||
name|after
condition|)
block|{
name|int
name|n
decl_stmt|;
for|for
control|(
name|n
operator|=
literal|1
init|;
name|n
operator|<
name|TraceLevel
condition|;
name|n
operator|++
control|)
name|fputs
argument_list|(
literal|"+ "
argument_list|,
name|TraceFP
argument_list|)
expr_stmt|;
block|}
name|vfprintf
argument_list|(
name|TraceFP
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|fputc
argument_list|(
literal|'\n'
argument_list|,
name|TraceFP
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|TraceFP
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|after
operator|&&
name|TraceLevel
condition|)
name|TraceLevel
operator|--
expr_stmt|;
name|errno
operator|=
name|save_err
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
name|_tracef
argument_list|(
argument|const char *fmt
argument_list|,
argument|...
argument_list|)
end_macro

begin_block
block|{
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|_nc_va_tracef
argument_list|(
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Trace 'bool' return-values */
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|NCURSES_BOOL
argument_list|)
end_macro

begin_macro
name|_nc_retrace_bool
argument_list|(
argument|NCURSES_BOOL code
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_RETURN
argument_list|(
literal|"%s"
argument_list|)
operator|,
name|code
condition|?
literal|"TRUE"
else|:
literal|"FALSE"
operator|)
argument_list|)
expr_stmt|;
return|return
name|code
return|;
block|}
end_block

begin_comment
comment|/* Trace 'int' return-values */
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|_nc_retrace_int
argument_list|(
argument|int code
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_RETURN
argument_list|(
literal|"%d"
argument_list|)
operator|,
name|code
operator|)
argument_list|)
expr_stmt|;
return|return
name|code
return|;
block|}
end_block

begin_comment
comment|/* Trace 'unsigned' return-values */
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|unsigned
argument_list|)
end_macro

begin_macro
name|_nc_retrace_unsigned
argument_list|(
argument|unsigned code
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_RETURN
argument_list|(
literal|"%#x"
argument_list|)
operator|,
name|code
operator|)
argument_list|)
expr_stmt|;
return|return
name|code
return|;
block|}
end_block

begin_comment
comment|/* Trace 'char*' return-values */
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|char *
argument_list|)
end_macro

begin_macro
name|_nc_retrace_ptr
argument_list|(
argument|char *code
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_RETURN
argument_list|(
literal|"%s"
argument_list|)
operator|,
name|_nc_visbuf
argument_list|(
name|code
argument_list|)
operator|)
argument_list|)
expr_stmt|;
return|return
name|code
return|;
block|}
end_block

begin_comment
comment|/* Trace 'const char*' return-values */
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|const char *
argument_list|)
end_macro

begin_macro
name|_nc_retrace_cptr
argument_list|(
argument|const char *code
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_RETURN
argument_list|(
literal|"%s"
argument_list|)
operator|,
name|_nc_visbuf
argument_list|(
name|code
argument_list|)
operator|)
argument_list|)
expr_stmt|;
return|return
name|code
return|;
block|}
end_block

begin_comment
comment|/* Trace 'NCURSES_CONST void*' return-values */
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|NCURSES_CONST void *
argument_list|)
end_macro

begin_macro
name|_nc_retrace_cvoid_ptr
argument_list|(
argument|NCURSES_CONST void *code
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_RETURN
argument_list|(
literal|"%p"
argument_list|)
operator|,
name|code
operator|)
argument_list|)
expr_stmt|;
return|return
name|code
return|;
block|}
end_block

begin_comment
comment|/* Trace 'void*' return-values */
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void *
argument_list|)
end_macro

begin_macro
name|_nc_retrace_void_ptr
argument_list|(
argument|void *code
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_RETURN
argument_list|(
literal|"%p"
argument_list|)
operator|,
name|code
operator|)
argument_list|)
expr_stmt|;
return|return
name|code
return|;
block|}
end_block

begin_comment
comment|/* Trace 'SCREEN *' return-values */
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|SCREEN *
argument_list|)
end_macro

begin_macro
name|_nc_retrace_sp
argument_list|(
argument|SCREEN *code
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_RETURN
argument_list|(
literal|"%p"
argument_list|)
operator|,
name|code
operator|)
argument_list|)
expr_stmt|;
return|return
name|code
return|;
block|}
end_block

begin_comment
comment|/* Trace 'WINDOW *' return-values */
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|WINDOW *
argument_list|)
end_macro

begin_macro
name|_nc_retrace_win
argument_list|(
argument|WINDOW *code
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_RETURN
argument_list|(
literal|"%p"
argument_list|)
operator|,
name|code
operator|)
argument_list|)
expr_stmt|;
return|return
name|code
return|;
block|}
end_block

begin_if
if|#
directive|if
name|USE_REENTRANT
end_if

begin_comment
comment|/*  * Check if the given trace-mask is enabled.  *  * This function may be called from within one of the functions that fills  * in parameters for _tracef(), but in that case we do not want to lock the  * mutex, since it is already locked.  */
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|_nc_use_tracef
argument_list|(
argument|unsigned mask
argument_list|)
end_macro

begin_block
block|{
name|bool
name|result
init|=
name|FALSE
decl_stmt|;
name|_nc_lock_global
argument_list|(
name|tst_tracef
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|_nc_globals
operator|.
name|nested_tracef
operator|++
condition|)
block|{
if|if
condition|(
operator|(
name|result
operator|=
operator|(
name|_nc_tracing
operator|&
operator|(
name|mask
operator|)
operator|)
operator|)
operator|!=
literal|0
condition|)
block|{
comment|/* we will call _nc_locked_tracef(), no nesting so far */
name|_nc_lock_global
argument_list|(
name|tracef
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* we will not call _nc_locked_tracef() */
name|_nc_globals
operator|.
name|nested_tracef
operator|=
literal|0
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* we may call _nc_locked_tracef(), but with nested_tracef> 0 */
name|result
operator|=
operator|(
name|_nc_tracing
operator|&
operator|(
name|mask
operator|)
operator|)
expr_stmt|;
block|}
name|_nc_unlock_global
argument_list|(
name|tst_tracef
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_block

begin_comment
comment|/*  * We call this if _nc_use_tracef() returns true, which means we must unlock  * the tracef mutex.  */
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_locked_tracef
argument_list|(
argument|const char *fmt
argument_list|,
argument|...
argument_list|)
end_macro

begin_block
block|{
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|_nc_va_tracef
argument_list|(
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
if|if
condition|(
operator|--
operator|(
name|_nc_globals
operator|.
name|nested_tracef
operator|)
operator|==
literal|0
condition|)
name|_nc_unlock_global
argument_list|(
name|tracef
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_REENTRANT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TRACE */
end_comment

end_unit

