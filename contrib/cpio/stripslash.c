begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* stripslash.c -- remove trailing slashes from a string    Copyright (C) 1990 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STDC_HEADERS
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_STRING_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Remove trailing slashes from PATH.    This is useful when using filename completion from a shell that    adds a "/" after directory names (such as tcsh and bash), because    the Unix rename and rmdir system calls return an "Invalid argument" error    when given a path that ends in "/" (except for the root directory).  */
end_comment

begin_function
name|void
name|strip_trailing_slashes
parameter_list|(
name|path
parameter_list|)
name|char
modifier|*
name|path
decl_stmt|;
block|{
name|int
name|last
decl_stmt|;
name|last
operator|=
name|strlen
argument_list|(
name|path
argument_list|)
operator|-
literal|1
expr_stmt|;
while|while
condition|(
name|last
operator|>
literal|0
operator|&&
name|path
index|[
name|last
index|]
operator|==
literal|'/'
condition|)
name|path
index|[
name|last
operator|--
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
end_function

end_unit

