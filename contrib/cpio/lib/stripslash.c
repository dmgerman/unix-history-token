begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* stripslash.c -- remove redundant trailing slashes from a file name     Copyright (C) 1990, 2001, 2003-2006 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|"dirname.h"
end_include

begin_comment
comment|/* Remove trailing slashes from FILE.  Return true if a trailing slash    was removed.  This is useful when using file name completion from a    shell that adds a "/" after directory names (such as tcsh and    bash), because on symlinks to directories, several system calls    have different semantics according to whether a trailing slash is    present.  */
end_comment

begin_function
name|bool
name|strip_trailing_slashes
parameter_list|(
name|char
modifier|*
name|file
parameter_list|)
block|{
name|char
modifier|*
name|base
init|=
name|last_component
argument_list|(
name|file
argument_list|)
decl_stmt|;
name|char
modifier|*
name|base_lim
decl_stmt|;
name|bool
name|had_slash
decl_stmt|;
comment|/* last_component returns "" for file system roots, but we need to turn      `///' into `/'.  */
if|if
condition|(
operator|!
operator|*
name|base
condition|)
name|base
operator|=
name|file
expr_stmt|;
name|base_lim
operator|=
name|base
operator|+
name|base_len
argument_list|(
name|base
argument_list|)
expr_stmt|;
name|had_slash
operator|=
operator|(
operator|*
name|base_lim
operator|!=
literal|'\0'
operator|)
expr_stmt|;
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

