begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * tclPort.h --  *  *	This header file handles porting issues that occur because  *	of differences between systems.  It reads in platform specific  *	portability files.  *  * Copyright (c) 1994-1995 Sun Microsystems, Inc.  *  * See the file "license.terms" for information on usage and redistribution  * of this file, and for a DISCLAIMER OF ALL WARRANTIES.  *  * SCCS: @(#) tclPort.h 1.15 96/02/07 17:24:21  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TCLPORT
end_ifndef

begin_define
define|#
directive|define
name|_TCLPORT
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__WIN32__
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_include
include|#
directive|include
file|"../win/tclWinPort.h"
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MAC_TCL
argument_list|)
end_if

begin_include
include|#
directive|include
file|"tclMacPort.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"../unix/tclUnixPort.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TCLPORT */
end_comment

end_unit

