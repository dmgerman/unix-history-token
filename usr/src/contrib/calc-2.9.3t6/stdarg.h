begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 David I. Bell  * Permission is granted to use, distribute, or modify this source,  * provided that this copyright notice remains intact.  */
end_comment

begin_include
include|#
directive|include
file|"args.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|STDARG_H
end_ifndef

begin_define
define|#
directive|define
name|STDARG_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|VARARGS
end_ifdef

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*VARARG*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STDARG
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*STDARG*/
end_comment

begin_comment
comment|/*  * SIMULATE_STDARG  *  * WARNING: This type of stdarg makes assumptions about the stack  * 	    that may not be true on your system.  You may want to  *	    define STDARG (if using ANSI C) or VARARGS.  */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|va_list
typedef|;
end_typedef

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|ap
parameter_list|,
name|parmn
parameter_list|)
value|(void)((ap) = (char*)(&(parmn) + 1))
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|ap
parameter_list|)
value|(void)((ap) = 0)
end_define

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|ap
parameter_list|,
name|type
parameter_list|)
define|\
value|(((type*)((ap) = ((ap) + sizeof(type))))[-1])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*STDARG*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*VARARG*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* END CODE */
end_comment

end_unit

