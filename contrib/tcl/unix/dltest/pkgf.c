begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * pkgf.c --  *  *	This file contains a simple Tcl package "pkgf" that is intended  *	for testing the Tcl dynamic loading facilities.  Its Init  *	procedure returns an error in order to test how this is handled.  *  * Copyright (c) 1995 Sun Microsystems, Inc.  *  * See the file "license.terms" for information on usage and redistribution  * of this file, and for a DISCLAIMER OF ALL WARRANTIES.  *  * SCCS: @(#) pkgf.c 1.2 96/02/15 12:30:32  */
end_comment

begin_include
include|#
directive|include
file|"tcl.h"
end_include

begin_comment
comment|/*  * Prototypes for procedures defined later in this file:  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|Pkgd_SubCmd
name|_ANSI_ARGS_
argument_list|(
operator|(
name|ClientData
name|clientData
operator|,
name|Tcl_Interp
operator|*
name|interp
operator|,
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|Pkgd_UnsafeCmd
name|_ANSI_ARGS_
argument_list|(
operator|(
name|ClientData
name|clientData
operator|,
name|Tcl_Interp
operator|*
name|interp
operator|,
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*  *----------------------------------------------------------------------  *  * Pkgf_Init --  *  *	This is a package initialization procedure, which is called  *	by Tcl when this package is to be added to an interpreter.  *  * Results:  *	Returns TCL_ERROR and leaves an error message in interp->result.  *  * Side effects:  *	None.  *  *----------------------------------------------------------------------  */
end_comment

begin_function
name|int
name|Pkgf_Init
parameter_list|(
name|interp
parameter_list|)
name|Tcl_Interp
modifier|*
name|interp
decl_stmt|;
comment|/* Interpreter in which the package is 				 * to be made available. */
block|{
return|return
name|Tcl_Eval
argument_list|(
name|interp
argument_list|,
literal|"if 44 {open non_existent}"
argument_list|)
return|;
block|}
end_function

end_unit

