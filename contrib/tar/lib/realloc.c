begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Work around bug on some systems where realloc (NULL, 0) fails.    Copyright (C) 1997 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* written by Jim Meyering */
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

begin_undef
undef|#
directive|undef
name|realloc
end_undef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Change the size of an allocated block of memory P to N bytes,    with error checking.  If N is zero, change it to 1.  If P is NULL,    use malloc.  */
end_comment

begin_function
name|char
modifier|*
name|rpl_realloc
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
name|char
modifier|*
name|p
decl_stmt|;
name|size_t
name|n
decl_stmt|;
block|{
if|if
condition|(
name|n
operator|==
literal|0
condition|)
name|n
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|p
operator|==
literal|0
condition|)
return|return
name|malloc
argument_list|(
name|n
argument_list|)
return|;
return|return
name|realloc
argument_list|(
name|p
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

end_unit

