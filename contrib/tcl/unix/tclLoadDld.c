begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * tclLoadDld.c --  *  *	This procedure provides a version of the TclLoadFile that  *	works with the "dld_link" and "dld_get_func" library procedures  *	for dynamic loading.  It has been tested on Linux 1.1.95 and  *	dld-3.2.7.  This file probably isn't needed anymore, since it  *	makes more sense to use "dl_open" etc.  *  * Copyright (c) 1995 Sun Microsystems, Inc.  *  * See the file "license.terms" for information on usage and redistribution  * of this file, and for a DISCLAIMER OF ALL WARRANTIES.  *  * SCCS: @(#) tclLoadDld.c 1.4 96/02/15 11:58:46  */
end_comment

begin_include
include|#
directive|include
file|"tclInt.h"
end_include

begin_include
include|#
directive|include
file|"dld.h"
end_include

begin_comment
comment|/*  * In some systems, like SunOS 4.1.3, the RTLD_NOW flag isn't defined  * and this argument to dlopen must always be 1.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RTLD_NOW
end_ifndef

begin_define
define|#
directive|define
name|RTLD_NOW
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/*  *----------------------------------------------------------------------  *  * TclLoadFile --  *  *	Dynamically loads a binary code file into memory and returns  *	the addresses of two procedures within that file, if they  *	are defined.  *  * Results:  *	A standard Tcl completion code.  If an error occurs, an error  *	message is left in interp->result.  *proc1Ptr and *proc2Ptr  *	are filled in with the addresses of the symbols given by  *	*sym1 and *sym2, or NULL if those symbols can't be found.  *  * Side effects:  *	New code suddenly appears in memory.  *  *----------------------------------------------------------------------  */
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
specifier|static
name|int
name|firstTime
init|=
literal|1
decl_stmt|;
name|int
name|returnCode
decl_stmt|;
comment|/*      *  The dld package needs to know the pathname to the tcl binary.      *  If that's not know, return an error.      */
if|if
condition|(
name|firstTime
condition|)
block|{
if|if
condition|(
name|tclExecutableName
operator|==
name|NULL
condition|)
block|{
name|interp
operator|->
name|result
operator|=
literal|"don't know name of application binary file, so can't initialize dynamic loader"
expr_stmt|;
return|return
name|TCL_ERROR
return|;
block|}
name|returnCode
operator|=
name|dld_init
argument_list|(
name|tclExecutableName
argument_list|)
expr_stmt|;
if|if
condition|(
name|returnCode
operator|!=
literal|0
condition|)
block|{
name|Tcl_AppendResult
argument_list|(
name|interp
argument_list|,
literal|"initialization failed for dynamic loader: "
argument_list|,
name|dld_strerror
argument_list|(
name|returnCode
argument_list|)
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
return|return
name|TCL_ERROR
return|;
block|}
name|firstTime
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|returnCode
operator|=
name|dld_link
argument_list|(
name|fileName
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
name|Tcl_AppendResult
argument_list|(
name|interp
argument_list|,
literal|"couldn't load file \""
argument_list|,
name|fileName
argument_list|,
literal|"\": "
argument_list|,
name|dld_strerror
argument_list|(
name|returnCode
argument_list|)
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
return|return
name|TCL_ERROR
return|;
block|}
operator|*
name|proc1Ptr
operator|=
operator|(
name|Tcl_PackageInitProc
operator|*
operator|)
name|dld_get_func
argument_list|(
name|sym1
argument_list|)
expr_stmt|;
operator|*
name|proc2Ptr
operator|=
operator|(
name|Tcl_PackageInitProc
operator|*
operator|)
name|dld_get_func
argument_list|(
name|sym2
argument_list|)
expr_stmt|;
return|return
name|TCL_OK
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

