begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * panic.c --  *  *	Source code for the "panic" library procedure for Tcl;  *	individual applications will probably override this with  *	an application-specific panic procedure.  *  * Copyright (c) 1988-1993 The Regents of the University of California.  * Copyright (c) 1994 Sun Microsystems, Inc.  *  * See the file "license.terms" for information on usage and redistribution  * of this file, and for a DISCLAIMER OF ALL WARRANTIES.  *  * SCCS: @(#) panic.c 1.11 96/02/15 11:50:29  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NO_STDLIB_H
end_ifdef

begin_include
include|#
directive|include
file|"../compat/stdlib.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"tcl.h"
end_include

begin_comment
comment|/*  * The panicProc variable contains a pointer to an application  * specific panic procedure.  */
end_comment

begin_macro
name|void
argument_list|(
argument|*panicProc
argument_list|)
end_macro

begin_expr_stmt
name|_ANSI_ARGS_
argument_list|(
name|TCL_VARARGS
argument_list|(
name|char
operator|*
argument_list|,
name|format
argument_list|)
argument_list|)
operator|=
name|NULL
expr_stmt|;
end_expr_stmt

begin_escape
end_escape

begin_comment
comment|/*  *----------------------------------------------------------------------  *  * Tcl_SetPanicProc --  *  *	Replace the default panic behavior with the specified functiion.  *  * Results:  *	None.  *  * Side effects:  *	Sets the panicProc variable.  *  *----------------------------------------------------------------------  */
end_comment

begin_function_decl
name|void
name|Tcl_SetPanicProc
parameter_list|(
name|proc
parameter_list|)
function_decl|void
parameter_list|(
function_decl|*proc
end_function_decl

begin_expr_stmt
unit|)
name|_ANSI_ARGS_
argument_list|(
name|TCL_VARARGS
argument_list|(
name|char
operator|*
argument_list|,
name|format
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|panicProc
operator|=
name|proc
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  *----------------------------------------------------------------------  *  * panic --  *  *	Print an error message and kill the process.  *  * Results:  *	None.  *  * Side effects:  *	The process dies, entering the debugger if possible.  *  *----------------------------------------------------------------------  */
end_comment

begin_comment
comment|/* VARARGS ARGSUSED */
end_comment

begin_function
name|void
name|panic
parameter_list|(
name|format
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,
name|arg7
parameter_list|,
name|arg8
parameter_list|)
name|char
modifier|*
name|format
decl_stmt|;
comment|/* Format string, suitable for passing to 				 * fprintf. */
name|char
modifier|*
name|arg1
decl_stmt|,
decl|*
name|arg2
decl_stmt|,
modifier|*
name|arg3
decl_stmt|;
end_function

begin_comment
comment|/* Additional arguments (variable in number) 				 * to pass to fprintf. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|arg4
decl_stmt|,
modifier|*
name|arg5
decl_stmt|,
modifier|*
name|arg6
decl_stmt|,
modifier|*
name|arg7
decl_stmt|,
modifier|*
name|arg8
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|panicProc
operator|!=
name|NULL
condition|)
block|{
call|(
name|void
call|)
argument_list|(
operator|*
name|panicProc
argument_list|)
argument_list|(
name|format
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|,
name|arg3
argument_list|,
name|arg4
argument_list|,
name|arg5
argument_list|,
name|arg6
argument_list|,
name|arg7
argument_list|,
name|arg8
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|format
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|,
name|arg3
argument_list|,
name|arg4
argument_list|,
name|arg5
argument_list|,
name|arg6
argument_list|,
name|arg7
argument_list|,
name|arg8
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
block|}
end_block

end_unit

