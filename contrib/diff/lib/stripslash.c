begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* stripslash.c -- remove redundant trailing slashes from a file name    Copyright (C) 1990, 2001, 2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"dirname.h"
end_include

begin_comment
comment|/* Remove trailing slashes from PATH.    Return nonzero if a trailing slash was removed.    This is useful when using filename completion from a shell that    adds a "/" after directory names (such as tcsh and bash), because    the Unix rename and rmdir system calls return an "Invalid argument" error    when given a path that ends in "/" (except for the root directory).  */
end_comment

begin_function
name|int
name|strip_trailing_slashes
parameter_list|(
name|char
modifier|*
name|path
parameter_list|)
block|{
name|char
modifier|*
name|base
init|=
name|base_name
argument_list|(
name|path
argument_list|)
decl_stmt|;
name|char
modifier|*
name|base_lim
init|=
name|base
operator|+
name|base_len
argument_list|(
name|base
argument_list|)
decl_stmt|;
name|int
name|had_slash
init|=
operator|*
name|base_lim
decl_stmt|;
operator|*
name|base_lim
operator|=
literal|'\0'
expr_stmt|;
return|return
name|had_slash
return|;
block|}
end_function

end_unit

