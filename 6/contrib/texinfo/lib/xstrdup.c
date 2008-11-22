begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xstrdup.c -- copy a string with out of memory checking    Copyright (C) 1990, 1996, 1998, 2001, 2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_comment
comment|/* Specification.  */
end_comment

begin_include
include|#
directive|include
file|"xalloc.h"
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/* Return a newly allocated copy of STRING.  */
end_comment

begin_function
name|char
modifier|*
name|xstrdup
parameter_list|(
specifier|const
name|char
modifier|*
name|string
parameter_list|)
block|{
return|return
name|strcpy
argument_list|(
name|xmalloc
argument_list|(
name|strlen
argument_list|(
name|string
argument_list|)
operator|+
literal|1
argument_list|)
argument_list|,
name|string
argument_list|)
return|;
block|}
end_function

end_unit

