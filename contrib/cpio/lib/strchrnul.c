begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Searching in a string.    Copyright (C) 2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Specification.  */
end_comment

begin_include
include|#
directive|include
file|"strchrnul.h"
end_include

begin_comment
comment|/* Find the first occurrence of C in S or the final NUL byte.  */
end_comment

begin_function
name|char
modifier|*
name|strchrnul
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|c_in
parameter_list|)
block|{
name|char
name|c
init|=
name|c_in
decl_stmt|;
while|while
condition|(
operator|*
name|s
operator|&&
operator|(
operator|*
name|s
operator|!=
name|c
operator|)
condition|)
name|s
operator|++
expr_stmt|;
return|return
operator|(
name|char
operator|*
operator|)
name|s
return|;
block|}
end_function

end_unit

