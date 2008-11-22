begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copy memory area and return pointer after last written byte.    Copyright (C) 2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Specification.  */
end_comment

begin_include
include|#
directive|include
file|"mempcpy.h"
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/* Copy N bytes of SRC to DEST, return pointer to bytes after the    last written byte.  */
end_comment

begin_function
name|void
modifier|*
name|mempcpy
parameter_list|(
name|void
modifier|*
name|dest
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
return|return
operator|(
name|char
operator|*
operator|)
name|memcpy
argument_list|(
name|dest
argument_list|,
name|src
argument_list|,
name|n
argument_list|)
operator|+
name|n
return|;
block|}
end_function

end_unit

