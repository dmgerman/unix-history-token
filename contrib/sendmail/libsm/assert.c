begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  */
end_comment

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_macro
name|SM_RCSID
argument_list|(
literal|"@(#)$Id: assert.c,v 1.25 2001/09/11 04:04:47 gshapiro Exp $"
argument_list|)
end_macro

begin_comment
comment|/* **  Abnormal program termination and assertion checking. **  For documentation, see assert.html. */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sm/assert.h>
end_include

begin_include
include|#
directive|include
file|<sm/exc.h>
end_include

begin_include
include|#
directive|include
file|<sm/io.h>
end_include

begin_include
include|#
directive|include
file|<sm/varargs.h>
end_include

begin_comment
comment|/* **  Debug categories that are used to guard expensive assertion checks. */
end_comment

begin_decl_stmt
name|SM_DEBUG_T
name|SmExpensiveAssert
init|=
name|SM_DEBUG_INITIALIZER
argument_list|(
literal|"sm_check_assert"
argument_list|,
literal|"@(#)$Debug: sm_check_assert - check assertions $"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SM_DEBUG_T
name|SmExpensiveRequire
init|=
name|SM_DEBUG_INITIALIZER
argument_list|(
literal|"sm_check_require"
argument_list|,
literal|"@(#)$Debug: sm_check_require - check function preconditions $"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SM_DEBUG_T
name|SmExpensiveEnsure
init|=
name|SM_DEBUG_INITIALIZER
argument_list|(
literal|"sm_check_ensure"
argument_list|,
literal|"@(#)$Debug: sm_check_ensure - check function postconditions $"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  Debug category: send self SIGSTOP on fatal error, **  so that you can run a debugger on the stopped process. */
end_comment

begin_decl_stmt
name|SM_DEBUG_T
name|SmAbortStop
init|=
name|SM_DEBUG_INITIALIZER
argument_list|(
literal|"sm_abort_stop"
argument_list|,
literal|"@(#)$Debug: sm_abort_stop - stop process on fatal error $"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  SM_ABORT_DEFAULTHANDLER -- Default procedure for abnormal program **				termination. ** **	The goal is to display an error message without disturbing the **	process state too much, then dump core. ** **	Parameters: **		filename -- filename (can be NULL). **		lineno -- line number. **		msg -- message. ** **	Returns: **		doesn't return. */
end_comment

begin_decl_stmt
specifier|static
name|void
name|sm_abort_defaulthandler
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|filename
operator|,
name|int
name|lineno
operator|,
specifier|const
name|char
operator|*
name|msg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|sm_abort_defaulthandler
parameter_list|(
name|filename
parameter_list|,
name|lineno
parameter_list|,
name|msg
parameter_list|)
specifier|const
name|char
modifier|*
name|filename
decl_stmt|;
name|int
name|lineno
decl_stmt|;
specifier|const
name|char
modifier|*
name|msg
decl_stmt|;
block|{
if|if
condition|(
name|filename
operator|!=
name|NULL
condition|)
name|sm_io_fprintf
argument_list|(
name|smioerr
argument_list|,
name|SM_TIME_DEFAULT
argument_list|,
literal|"%s:%d: %s\n"
argument_list|,
name|filename
argument_list|,
name|lineno
argument_list|,
name|msg
argument_list|)
expr_stmt|;
else|else
name|sm_io_fprintf
argument_list|(
name|smioerr
argument_list|,
name|SM_TIME_DEFAULT
argument_list|,
literal|"%s\n"
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|sm_io_flush
argument_list|(
name|smioerr
argument_list|,
name|SM_TIME_DEFAULT
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SIGSTOP
if|if
condition|(
name|sm_debug_active
argument_list|(
operator|&
name|SmAbortStop
argument_list|,
literal|1
argument_list|)
condition|)
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGSTOP
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SIGSTOP */
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* **  This is the action to be taken to cause abnormal program termination. */
end_comment

begin_decl_stmt
specifier|static
name|SM_ABORT_HANDLER_T
name|SmAbortHandler
init|=
name|sm_abort_defaulthandler
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  SM_ABORT_SETHANDLER -- Set handler for SM_ABORT() ** **	This allows you to set a handler function for causing abnormal **	program termination; it is called when a logic bug is detected. ** **	Parameters: **		f -- handler. ** **	Returns: **		none. */
end_comment

begin_function
name|void
name|sm_abort_sethandler
parameter_list|(
name|f
parameter_list|)
name|SM_ABORT_HANDLER_T
name|f
decl_stmt|;
block|{
if|if
condition|(
name|f
operator|==
name|NULL
condition|)
name|SmAbortHandler
operator|=
name|sm_abort_defaulthandler
expr_stmt|;
else|else
name|SmAbortHandler
operator|=
name|f
expr_stmt|;
block|}
end_function

begin_comment
comment|/* **  SM_ABORT -- Call it when you have detected a logic bug. ** **	Parameters: **		fmt -- format string. **		... -- arguments. ** **	Returns: **		doesn't. */
end_comment

begin_function
name|void
if|#
directive|if
name|SM_VA_STD
name|sm_abort
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
comment|/* SM_VA_STD */
function|sm_abort
parameter_list|(
name|fmt
parameter_list|,
name|va_alist
parameter_list|)
name|char
modifier|*
name|fmt
decl_stmt|;
function|va_dcl
endif|#
directive|endif
comment|/* SM_VA_STD */
block|{
name|char
name|msg
index|[
literal|128
index|]
decl_stmt|;
name|SM_VA_LOCAL_DECL
name|SM_VA_START
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
decl_stmt|;
name|sm_vsnprintf
argument_list|(
name|msg
argument_list|,
sizeof|sizeof
name|msg
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|SM_VA_END
argument_list|(
name|ap
argument_list|)
expr_stmt|;
name|sm_abort_at
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|,
name|msg
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* **  SM_ABORT_AT -- Initiate abnormal program termination. ** **	This is the low level function that is called to initiate abnormal **	program termination.  It prints an error message and terminates the **	program.  It is called by sm_abort and by the assertion macros. **	If filename != NULL then filename and lineno specify the line of source **	code at which the bug was detected. ** **	Parameters: **		filename -- filename (can be NULL). **		lineno -- line number. **		msg -- message. ** **	Returns: **		doesn't. */
end_comment

begin_function
name|void
name|sm_abort_at
parameter_list|(
name|filename
parameter_list|,
name|lineno
parameter_list|,
name|msg
parameter_list|)
specifier|const
name|char
modifier|*
name|filename
decl_stmt|;
name|int
name|lineno
decl_stmt|;
specifier|const
name|char
modifier|*
name|msg
decl_stmt|;
block|{
name|SM_TRY
function_decl|(
modifier|*
name|SmAbortHandler
function_decl|)
parameter_list|(
name|filename
parameter_list|,
name|lineno
parameter_list|,
name|msg
parameter_list|)
function_decl|;
name|SM_EXCEPT
argument_list|(
argument|exc
argument_list|,
literal|"*"
argument_list|)
name|sm_io_fprintf
argument_list|(
name|smioerr
argument_list|,
name|SM_TIME_DEFAULT
argument_list|,
literal|"exception raised by abort handler:\n"
argument_list|)
expr_stmt|;
name|sm_exc_print
argument_list|(
name|exc
argument_list|,
name|smioerr
argument_list|)
expr_stmt|;
name|sm_io_flush
argument_list|(
name|smioerr
argument_list|,
name|SM_TIME_DEFAULT
argument_list|)
expr_stmt|;
name|SM_END_TRY
comment|/* 	**  SmAbortHandler isn't supposed to return. 	**  Since it has, let's make sure that the program is terminated. 	*/
name|abort
parameter_list|()
function_decl|;
block|}
end_function

end_unit

