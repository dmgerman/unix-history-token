begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * tclAppInit.c --  *  *	Provides a default version of the main program and Tcl_AppInit  *	procedure for Tcl applications (without Tk).  *  * Copyright (c) 1993 The Regents of the University of California.  * Copyright (c) 1994-1995 Sun Microsystems, Inc.  *  * See the file "license.terms" for information on usage and redistribution  * of this file, and for a DISCLAIMER OF ALL WARRANTIES.  *  * SCCS: @(#) tclAppInit.c 1.17 96/03/26 12:45:29  */
end_comment

begin_include
include|#
directive|include
file|"tcl.h"
end_include

begin_comment
comment|/*  * The following variable is a special hack that is needed in order for  * Sun shared libraries to be used for Tcl.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|matherr
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
modifier|*
name|tclDummyMathPtr
init|=
operator|(
name|int
operator|*
operator|)
name|matherr
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|TCL_TEST
end_ifdef

begin_decl_stmt
name|EXTERN
name|int
name|Tcltest_Init
name|_ANSI_ARGS_
argument_list|(
operator|(
name|Tcl_Interp
operator|*
name|interp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TCL_TEST */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  *----------------------------------------------------------------------  *  * main --  *  *	This is the main program for the application.  *  * Results:  *	None: Tcl_Main never returns here, so this procedure never  *	returns either.  *  * Side effects:  *	Whatever the application does.  *  *----------------------------------------------------------------------  */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
comment|/* Number of command-line arguments. */
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
comment|/* Values of command-line arguments. */
block|{
name|Tcl_Main
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|Tcl_AppInit
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
comment|/* Needed only to prevent compiler warning. */
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  *----------------------------------------------------------------------  *  * Tcl_AppInit --  *  *	This procedure performs application-specific initialization.  *	Most applications, especially those that incorporate additional  *	packages, will have their own version of this procedure.  *  * Results:  *	Returns a standard Tcl completion code, and leaves an error  *	message in interp->result if an error occurs.  *  * Side effects:  *	Depends on the startup script.  *  *----------------------------------------------------------------------  */
end_comment

begin_function
name|int
name|Tcl_AppInit
parameter_list|(
name|interp
parameter_list|)
name|Tcl_Interp
modifier|*
name|interp
decl_stmt|;
comment|/* Interpreter for application. */
block|{
if|if
condition|(
name|Tcl_Init
argument_list|(
name|interp
argument_list|)
operator|==
name|TCL_ERROR
condition|)
block|{
return|return
name|TCL_ERROR
return|;
block|}
ifdef|#
directive|ifdef
name|TCL_TEST
if|if
condition|(
name|Tcltest_Init
argument_list|(
name|interp
argument_list|)
operator|==
name|TCL_ERROR
condition|)
block|{
return|return
name|TCL_ERROR
return|;
block|}
name|Tcl_StaticPackage
argument_list|(
name|interp
argument_list|,
literal|"Tcltest"
argument_list|,
name|Tcltest_Init
argument_list|,
operator|(
name|Tcl_PackageInitProc
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* TCL_TEST */
comment|/*      * Call the init procedures for included packages.  Each call should      * look like this:      *      * if (Mod_Init(interp) == TCL_ERROR) {      *     return TCL_ERROR;      * }      *      * where "Mod" is the name of the module.      */
comment|/*      * Call Tcl_CreateCommand for application-specific commands, if      * they weren't already created by the init procedures called above.      */
comment|/*      * Specify a user-specific startup file to invoke if the application      * is run interactively.  Typically the startup file is "~/.apprc"      * where "app" is the name of the application.  If this line is deleted      * then no user-specific startup file will be run under any conditions.      */
name|Tcl_SetVar
argument_list|(
name|interp
argument_list|,
literal|"tcl_rcFileName"
argument_list|,
literal|"~/.tclshrc"
argument_list|,
name|TCL_GLOBAL_ONLY
argument_list|)
expr_stmt|;
return|return
name|TCL_OK
return|;
block|}
end_function

end_unit

