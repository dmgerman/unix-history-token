begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1993-2001 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * Id: debug.c,v 1.6 2001/06/09 17:09:24 darrenr Exp  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"ipt.h"
end_include

begin_include
include|#
directive|include
file|"opts.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function
name|void
name|debug
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
function|void	debug
parameter_list|(
name|fmt
parameter_list|,
name|va_alist
parameter_list|)
name|char
modifier|*
name|fmt
decl_stmt|;
function|va_dcl
endif|#
directive|endif
block|{
name|va_list
name|pvar
decl_stmt|;
name|va_start
argument_list|(
name|pvar
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
if|if
condition|(
name|opts
operator|&
name|OPT_DEBUG
condition|)
name|vprintf
argument_list|(
name|fmt
argument_list|,
name|pvar
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|pvar
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

