begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * tclLoadNone.c --  *  *	This procedure provides a version of the TclLoadFile for use  *	in systems that don't support dynamic loading; it just returns  *	an error.  *  * Copyright (c) 1995-1996 Sun Microsystems, Inc.  *  * See the file "license.terms" for information on usage and redistribution  * of this file, and for a DISCLAIMER OF ALL WARRANTIES.  *  * SCCS: @(#) tclLoadNone.c 1.5 96/02/15 11:43:01  */
end_comment

begin_include
include|#
directive|include
file|"tclInt.h"
end_include

begin_escape
end_escape

begin_comment
comment|/*  *----------------------------------------------------------------------  *  * TclLoadFile --  *  *	This procedure is called to carry out dynamic loading of binary  *	code;  it is intended for use only on systems that don't support  *	dynamic loading (it returns an error).  *  * Results:  *	The result is TCL_ERROR, and an error message is left in  *	interp->result.  *  * Side effects:  *	None.  *  *----------------------------------------------------------------------  */
end_comment

begin_function
name|int
name|TclLoadFile
parameter_list|(
name|interp
parameter_list|,
name|fileName
parameter_list|,
name|sym1
parameter_list|,
name|sym2
parameter_list|,
name|proc1Ptr
parameter_list|,
name|proc2Ptr
parameter_list|)
name|Tcl_Interp
modifier|*
name|interp
decl_stmt|;
comment|/* Used for error reporting. */
name|char
modifier|*
name|fileName
decl_stmt|;
comment|/* Name of the file containing the desired 				 * code. */
name|char
modifier|*
name|sym1
decl_stmt|,
decl|*
name|sym2
decl_stmt|;
end_function

begin_comment
comment|/* Names of two procedures to look up in 				 * the file's symbol table. */
end_comment

begin_decl_stmt
name|Tcl_PackageInitProc
modifier|*
modifier|*
name|proc1Ptr
decl_stmt|,
modifier|*
modifier|*
name|proc2Ptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Where to return the addresses corresponding 				 * to sym1 and sym2. */
end_comment

begin_block
block|{
name|interp
operator|->
name|result
operator|=
literal|"dynamic loading is not currently available on this system"
expr_stmt|;
return|return
name|TCL_ERROR
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  *----------------------------------------------------------------------  *  * TclGuessPackageName --  *  *	If the "load" command is invoked without providing a package  *	name, this procedure is invoked to try to figure it out.  *  * Results:  *	Always returns 0 to indicate that we couldn't figure out a  *	package name;  generic code will then try to guess the package  *	from the file name.  A return value of 1 would have meant that  *	we figured out the package name and put it in bufPtr.  *  * Side effects:  *	None.  *  *----------------------------------------------------------------------  */
end_comment

begin_function
name|int
name|TclGuessPackageName
parameter_list|(
name|fileName
parameter_list|,
name|bufPtr
parameter_list|)
name|char
modifier|*
name|fileName
decl_stmt|;
comment|/* Name of file containing package (already 				 * translated to local form if needed). */
name|Tcl_DString
modifier|*
name|bufPtr
decl_stmt|;
comment|/* Initialized empty dstring.  Append 				 * package name to this if possible. */
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

