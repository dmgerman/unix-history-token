begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* vfprintf.c -- this was provided for minix.  It may not    work on any other system. */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_VPRINTF
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_DOPRINT
end_ifndef

begin_error
error|#
directive|error
error|need vfprintf() or doprint()
end_error

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LIB_H
end_ifdef

begin_include
include|#
directive|include
file|<lib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDARG_H
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDIO_H
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|vfprintf
parameter_list|(
name|file
parameter_list|,
name|format
parameter_list|,
name|argp
parameter_list|)
name|FILE
modifier|*
name|file
decl_stmt|;
name|_CONST
name|char
modifier|*
name|format
decl_stmt|;
name|va_list
name|argp
decl_stmt|;
block|{
name|_doprintf
argument_list|(
name|file
argument_list|,
name|format
argument_list|,
name|argp
argument_list|)
expr_stmt|;
if|if
condition|(
name|testflag
argument_list|(
name|file
argument_list|,
name|PERPRINTF
argument_list|)
condition|)
name|fflush
argument_list|(
name|file
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_DOPRINT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_VFPRINTF */
end_comment

end_unit

