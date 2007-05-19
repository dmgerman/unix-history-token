begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Implement the xstrndup function.    Copyright (C) 2005 Free Software Foundation, Inc.    Written by Kaveh R. Ghazi<ghazi@caip.rutgers.edu>.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/*  @deftypefn Replacement char* xstrndup (const char *@var{s}, size_t @var{n})  Returns a pointer to a copy of @var{s} with at most @var{n} characters without fail, using @code{xmalloc} to obtain memory.  The result is always NUL terminated.  @end deftypefn  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRING_H
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRINGS_H
end_ifdef

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_function
name|char
modifier|*
name|xstrndup
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
name|char
modifier|*
name|result
decl_stmt|;
name|size_t
name|len
init|=
name|strlen
argument_list|(
name|s
argument_list|)
decl_stmt|;
if|if
condition|(
name|n
operator|<
name|len
condition|)
name|len
operator|=
name|n
expr_stmt|;
name|result
operator|=
name|XNEWVEC
argument_list|(
name|char
argument_list|,
name|len
operator|+
literal|1
argument_list|)
expr_stmt|;
name|result
index|[
name|len
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|char
operator|*
operator|)
name|memcpy
argument_list|(
name|result
argument_list|,
name|s
argument_list|,
name|len
argument_list|)
return|;
block|}
end_function

end_unit

