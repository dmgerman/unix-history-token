begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * tclMatherr.c --  *  *	This function provides a default implementation of the  *	"matherr" function, for SYS-V systems where it's needed.  *  * Copyright (c) 1993-1994 The Regents of the University of California.  * Copyright (c) 1994 Sun Microsystems, Inc.  *  * See the file "license.terms" for information on usage and redistribution  * of this file, and for a DISCLAIMER OF ALL WARRANTIES.  *  * SCCS: @(#) tclMtherr.c 1.11 96/02/15 11:58:36  */
end_comment

begin_include
include|#
directive|include
file|"tclInt.h"
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|TCL_GENERIC_ONLY
end_ifndef

begin_include
include|#
directive|include
file|"tclPort.h"
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NO_ERRNO_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NO_ERRNO_H
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use errno from tclExpr.c. */
end_comment

begin_define
define|#
directive|define
name|EDOM
value|33
end_define

begin_define
define|#
directive|define
name|ERANGE
value|34
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The following variable is secretly shared with Tcl so we can  * tell if expression evaluation is in progress.  If not, matherr  * just emulates the default behavior, which includes printing  * a message.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tcl_MathInProgress
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The following definitions allow matherr to compile on systems  * that don't really support it.  The compiled procedure is bogus,  * but it will never be executed on these systems anyway.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NEED_MATHERR
end_ifndef

begin_struct
struct|struct
name|exception
block|{
name|int
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DOMAIN
value|0
end_define

begin_define
define|#
directive|define
name|SING
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/*  *----------------------------------------------------------------------  *  * matherr --  *  *	This procedure is invoked on Sys-V systems when certain  *	errors occur in mathematical functions.  Type "man matherr"  *	for more information on how this function works.  *  * Results:  *	Returns 1 to indicate that we've handled the error  *	locally.  *  * Side effects:  *	Sets errno based on what's in xPtr.  *  *----------------------------------------------------------------------  */
end_comment

begin_function
name|int
name|matherr
parameter_list|(
name|xPtr
parameter_list|)
name|struct
name|exception
modifier|*
name|xPtr
decl_stmt|;
comment|/* Describes error that occurred. */
block|{
if|if
condition|(
operator|!
name|tcl_MathInProgress
condition|)
block|{
return|return
literal|0
return|;
block|}
if|if
condition|(
operator|(
name|xPtr
operator|->
name|type
operator|==
name|DOMAIN
operator|)
operator|||
operator|(
name|xPtr
operator|->
name|type
operator|==
name|SING
operator|)
condition|)
block|{
name|errno
operator|=
name|EDOM
expr_stmt|;
block|}
else|else
block|{
name|errno
operator|=
name|ERANGE
expr_stmt|;
block|}
return|return
literal|1
return|;
block|}
end_function

end_unit

