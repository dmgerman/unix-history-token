begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * tclAsync.c --  *  *	This file provides low-level support needed to invoke signal  *	handlers in a safe way.  The code here doesn't actually handle  *	signals, though.  This code is based on proposals made by  *	Mark Diekhans and Don Libes.  *  * Copyright (c) 1993 The Regents of the University of California.  * Copyright (c) 1994 Sun Microsystems, Inc.  *  * See the file "license.terms" for information on usage and redistribution  * of this file, and for a DISCLAIMER OF ALL WARRANTIES.  *  * SCCS: @(#) tclAsync.c 1.6 96/02/15 11:46:15  */
end_comment

begin_include
include|#
directive|include
file|"tclInt.h"
end_include

begin_comment
comment|/*  * One of the following structures exists for each asynchronous  * handler:  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AsyncHandler
block|{
name|int
name|ready
decl_stmt|;
comment|/* Non-zero means this handler should 					 * be invoked in the next call to 					 * Tcl_AsyncInvoke. */
name|struct
name|AsyncHandler
modifier|*
name|nextPtr
decl_stmt|;
comment|/* Next in list of all handlers for 					 * the process. */
name|Tcl_AsyncProc
modifier|*
name|proc
decl_stmt|;
comment|/* Procedure to call when handler 					 * is invoked. */
name|ClientData
name|clientData
decl_stmt|;
comment|/* Value to pass to handler when it 					 * is invoked. */
block|}
name|AsyncHandler
typedef|;
end_typedef

begin_comment
comment|/*  * The variables below maintain a list of all existing handlers.  */
end_comment

begin_decl_stmt
specifier|static
name|AsyncHandler
modifier|*
name|firstHandler
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* First handler defined for process, 					 * or NULL if none. */
end_comment

begin_decl_stmt
specifier|static
name|AsyncHandler
modifier|*
name|lastHandler
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last handler or NULL. */
end_comment

begin_comment
comment|/*  * The variable below is set to 1 whenever a handler becomes ready and  * it is cleared to zero whenever Tcl_AsyncInvoke is called.  It can be  * checked elsewhere in the application by calling Tcl_AsyncReady to see  * if Tcl_AsyncInvoke should be invoked.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|asyncReady
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The variable below indicates whether Tcl_AsyncInvoke is currently  * working.  If so then we won't set asyncReady again until  * Tcl_AsyncInvoke returns.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|asyncActive
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*  *----------------------------------------------------------------------  *  * Tcl_AsyncCreate --  *  *	This procedure creates the data structures for an asynchronous  *	handler, so that no memory has to be allocated when the handler  *	is activated.  *  * Results:  *	The return value is a token for the handler, which can be used  *	to activate it later on.  *  * Side effects:  *	Information about the handler is recorded.  *  *----------------------------------------------------------------------  */
end_comment

begin_function
name|Tcl_AsyncHandler
name|Tcl_AsyncCreate
parameter_list|(
name|proc
parameter_list|,
name|clientData
parameter_list|)
name|Tcl_AsyncProc
modifier|*
name|proc
decl_stmt|;
comment|/* Procedure to call when handler 					 * is invoked. */
name|ClientData
name|clientData
decl_stmt|;
comment|/* Argument to pass to handler. */
block|{
name|AsyncHandler
modifier|*
name|asyncPtr
decl_stmt|;
name|asyncPtr
operator|=
operator|(
name|AsyncHandler
operator|*
operator|)
name|ckalloc
argument_list|(
sizeof|sizeof
argument_list|(
name|AsyncHandler
argument_list|)
argument_list|)
expr_stmt|;
name|asyncPtr
operator|->
name|ready
operator|=
literal|0
expr_stmt|;
name|asyncPtr
operator|->
name|nextPtr
operator|=
name|NULL
expr_stmt|;
name|asyncPtr
operator|->
name|proc
operator|=
name|proc
expr_stmt|;
name|asyncPtr
operator|->
name|clientData
operator|=
name|clientData
expr_stmt|;
if|if
condition|(
name|firstHandler
operator|==
name|NULL
condition|)
block|{
name|firstHandler
operator|=
name|asyncPtr
expr_stmt|;
block|}
else|else
block|{
name|lastHandler
operator|->
name|nextPtr
operator|=
name|asyncPtr
expr_stmt|;
block|}
name|lastHandler
operator|=
name|asyncPtr
expr_stmt|;
return|return
operator|(
name|Tcl_AsyncHandler
operator|)
name|asyncPtr
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  *----------------------------------------------------------------------  *  * Tcl_AsyncMark --  *  *	This procedure is called to request that an asynchronous handler  *	be invoked as soon as possible.  It's typically called from  *	an interrupt handler, where it isn't safe to do anything that  *	depends on or modifies application state.  *  * Results:  *	None.  *  * Side effects:  *	The handler gets marked for invocation later.  *  *----------------------------------------------------------------------  */
end_comment

begin_function
name|void
name|Tcl_AsyncMark
parameter_list|(
name|async
parameter_list|)
name|Tcl_AsyncHandler
name|async
decl_stmt|;
comment|/* Token for handler. */
block|{
operator|(
operator|(
name|AsyncHandler
operator|*
operator|)
name|async
operator|)
operator|->
name|ready
operator|=
literal|1
expr_stmt|;
if|if
condition|(
operator|!
name|asyncActive
condition|)
block|{
name|asyncReady
operator|=
literal|1
expr_stmt|;
block|}
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  *----------------------------------------------------------------------  *  * Tcl_AsyncInvoke --  *  *	This procedure is called at a "safe" time at background level  *	to invoke any active asynchronous handlers.  *  * Results:  *	The return value is a normal Tcl result, which is intended to  *	replace the code argument as the current completion code for  *	interp.  *  * Side effects:  *	Depends on the handlers that are active.  *  *----------------------------------------------------------------------  */
end_comment

begin_function
name|int
name|Tcl_AsyncInvoke
parameter_list|(
name|interp
parameter_list|,
name|code
parameter_list|)
name|Tcl_Interp
modifier|*
name|interp
decl_stmt|;
comment|/* If invoked from Tcl_Eval just after 					 * completing a command, points to 					 * interpreter.  Otherwise it is 					 * NULL. */
name|int
name|code
decl_stmt|;
comment|/* If interp is non-NULL, this gives 					 * completion code from command that 					 * just completed. */
block|{
name|AsyncHandler
modifier|*
name|asyncPtr
decl_stmt|;
if|if
condition|(
name|asyncReady
operator|==
literal|0
condition|)
block|{
return|return
name|code
return|;
block|}
name|asyncReady
operator|=
literal|0
expr_stmt|;
name|asyncActive
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|interp
operator|==
name|NULL
condition|)
block|{
name|code
operator|=
literal|0
expr_stmt|;
block|}
comment|/*      * Make one or more passes over the list of handlers, invoking      * at most one handler in each pass.  After invoking a handler,      * go back to the start of the list again so that (a) if a new      * higher-priority handler gets marked while executing a lower      * priority handler, we execute the higher-priority handler      * next, and (b) if a handler gets deleted during the execution      * of a handler, then the list structure may change so it isn't      * safe to continue down the list anyway.      */
while|while
condition|(
literal|1
condition|)
block|{
for|for
control|(
name|asyncPtr
operator|=
name|firstHandler
init|;
name|asyncPtr
operator|!=
name|NULL
condition|;
name|asyncPtr
operator|=
name|asyncPtr
operator|->
name|nextPtr
control|)
block|{
if|if
condition|(
name|asyncPtr
operator|->
name|ready
condition|)
block|{
break|break;
block|}
block|}
if|if
condition|(
name|asyncPtr
operator|==
name|NULL
condition|)
block|{
break|break;
block|}
name|asyncPtr
operator|->
name|ready
operator|=
literal|0
expr_stmt|;
name|code
operator|=
call|(
modifier|*
name|asyncPtr
operator|->
name|proc
call|)
argument_list|(
name|asyncPtr
operator|->
name|clientData
argument_list|,
name|interp
argument_list|,
name|code
argument_list|)
expr_stmt|;
block|}
name|asyncActive
operator|=
literal|0
expr_stmt|;
return|return
name|code
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  *----------------------------------------------------------------------  *  * Tcl_AsyncDelete --  *  *	Frees up all the state for an asynchronous handler.  The handler  *	should never be used again.  *  * Results:  *	None.  *  * Side effects:  *	The state associated with the handler is deleted.  *  *----------------------------------------------------------------------  */
end_comment

begin_function
name|void
name|Tcl_AsyncDelete
parameter_list|(
name|async
parameter_list|)
name|Tcl_AsyncHandler
name|async
decl_stmt|;
comment|/* Token for handler to delete. */
block|{
name|AsyncHandler
modifier|*
name|asyncPtr
init|=
operator|(
name|AsyncHandler
operator|*
operator|)
name|async
decl_stmt|;
name|AsyncHandler
modifier|*
name|prevPtr
decl_stmt|;
if|if
condition|(
name|firstHandler
operator|==
name|asyncPtr
condition|)
block|{
name|firstHandler
operator|=
name|asyncPtr
operator|->
name|nextPtr
expr_stmt|;
if|if
condition|(
name|firstHandler
operator|==
name|NULL
condition|)
block|{
name|lastHandler
operator|=
name|NULL
expr_stmt|;
block|}
block|}
else|else
block|{
name|prevPtr
operator|=
name|firstHandler
expr_stmt|;
while|while
condition|(
name|prevPtr
operator|->
name|nextPtr
operator|!=
name|asyncPtr
condition|)
block|{
name|prevPtr
operator|=
name|prevPtr
operator|->
name|nextPtr
expr_stmt|;
block|}
name|prevPtr
operator|->
name|nextPtr
operator|=
name|asyncPtr
operator|->
name|nextPtr
expr_stmt|;
if|if
condition|(
name|lastHandler
operator|==
name|asyncPtr
condition|)
block|{
name|lastHandler
operator|=
name|prevPtr
expr_stmt|;
block|}
block|}
name|ckfree
argument_list|(
operator|(
name|char
operator|*
operator|)
name|asyncPtr
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  *----------------------------------------------------------------------  *  * Tcl_AsyncReady --  *  *	This procedure can be used to tell whether Tcl_AsyncInvoke  *	needs to be called.  This procedure is the external interface  *	for checking the internal asyncReady variable.  *  * Results:  * 	The return value is 1 whenever a handler is ready and is 0  *	when no handlers are ready.  *  * Side effects:  *	None.  *  *----------------------------------------------------------------------  */
end_comment

begin_function
name|int
name|Tcl_AsyncReady
parameter_list|()
block|{
return|return
name|asyncReady
return|;
block|}
end_function

end_unit

