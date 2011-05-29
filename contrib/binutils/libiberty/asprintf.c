begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Like sprintf but provides a pointer to malloc'd storage, which must    be freed by the caller.    Copyright (C) 1997, 2003 Free Software Foundation, Inc.    Contributed by Cygnus Solutions.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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
file|"ansidecl.h"
end_include

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_comment
comment|/*  @deftypefn Extension int asprintf (char **@var{resptr}, const char *@var{format}, ...)  Like @code{sprintf}, but instead of passing a pointer to a buffer, you pass a pointer to a pointer.  This function will compute the size of the buffer needed, allocate memory with @code{malloc}, and store a pointer to the allocated memory in @code{*@var{resptr}}.  The value returned is the same as @code{sprintf} would return.  If memory could not be allocated, minus one is returned and @code{NULL} is stored in @code{*@var{resptr}}.  @end deftypefn  */
end_comment

begin_function
name|int
name|asprintf
parameter_list|(
name|char
modifier|*
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|int
name|status
decl_stmt|;
name|VA_OPEN
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|VA_FIXEDARG
argument_list|(
name|ap
argument_list|,
name|char
operator|*
operator|*
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|VA_FIXEDARG
argument_list|(
name|ap
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|status
operator|=
name|vasprintf
argument_list|(
name|buf
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|VA_CLOSE
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|status
return|;
block|}
end_function

end_unit

