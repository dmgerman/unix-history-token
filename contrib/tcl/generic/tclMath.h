begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * tclMath.h --  *  *	This file is necessary because of Metrowerks CodeWarrior Pro 1  *	on the Macintosh. With 8-byte doubles turned on, the definitions of  *	sin, cos, acos, etc., are screwed up.  They are fine as long as  *	they are used as function calls, but if the function pointers  *	are passed around and used, they will crash hard on the 68K.  *  * Copyright (c) 1997 Sun Microsystems, Inc.  *  * See the file "license.terms" for information on usage and redistribution  * of this file, and for a DISCLAIMER OF ALL WARRANTIES.  *  * SCCS: @(#) tclMath.h 1.2 97/07/23 17:39:14  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TCLMATH
end_ifndef

begin_define
define|#
directive|define
name|_TCLMATH
end_define

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
file|"tclMacMath.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TCLMATH */
end_comment

end_unit

