begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * tclLoadOSF.c --  *  *	This procedure provides a version of the TclLoadFile that works  *	under OSF/1 1.0/1.1/1.2 and related systems, utilizing the old OSF/1  *	/sbin/loader and /usr/include/loader.h.  OSF/1 versions from 1.3 and  *	on use ELF, rtld, and dlopen()[/usr/include/ldfcn.h].  *  *	This is useful for:  *		OSF/1 1.0, 1.1, 1.2 (from OSF)  *			includes: MK4 and AD1 (from OSF RI)  *		OSF/1 1.3 (from OSF) using ROSE  *		HP OSF/1 1.0 ("Acorn") using COFF  *  *	This is likely to be useful for:  *		Paragon OSF/1 (from Intel)   *		HI-OSF/1 (from Hitachi)   *  *	This is NOT to be used on:  *		Digitial Alpha OSF/1 systems  *		OSF/1 1.3 or later (from OSF) using ELF  *			includes: MK6, MK7, AD2, AD3 (from OSF RI)  *  *	This approach to things was utter @&^#; thankfully,  * 	OSF/1 eventually supported dlopen().  *  *	John Robert LoVerso<loverso@freebsd.osf.org>  *  * Copyright (c) 1995 Sun Microsystems, Inc.  *  * See the file "license.terms" for information on usage and redistribution  * of this file, and for a DISCLAIMER OF ALL WARRANTIES.  *  * SCCS: @(#) tclLoadOSF.c 1.2 96/02/15 11:58:40  */
end_comment

begin_include
include|#
directive|include
file|"tclInt.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<loader.h>
end_include

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
name|ldr_module_t
name|lm
decl_stmt|;
name|char
modifier|*
name|pkg
decl_stmt|;
name|lm
operator|=
operator|(
name|Tcl_PackageInitProc
operator|*
operator|)
name|load
argument_list|(
name|fileName
argument_list|,
name|LDR_NOFLAGS
argument_list|)
expr_stmt|;
if|if
condition|(
name|lm
operator|==
name|LDR_NULL_MODULE
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
name|Tcl_PosixError
argument_list|(
name|interp
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
comment|/*      * My convention is to use a [OSF loader] package name the same as shlib,      * since the idiots never implemented ldr_lookup() and it is otherwise      * impossible to get a package name given a module.      *      * I build loadable modules with a makefile rule like       *		ld ... -export $@: -o $@ $(OBJS)      */
if|if
condition|(
operator|(
name|pkg
operator|=
name|strrchr
argument_list|(
name|fileName
argument_list|,
literal|'/'
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|pkg
operator|=
name|fileName
expr_stmt|;
else|else
name|pkg
operator|++
expr_stmt|;
operator|*
name|proc1Ptr
operator|=
name|ldr_lookup_package
argument_list|(
name|pkg
argument_list|,
name|sym1
argument_list|)
expr_stmt|;
operator|*
name|proc2Ptr
operator|=
name|ldr_lookup_package
argument_list|(
name|pkg
argument_list|,
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

