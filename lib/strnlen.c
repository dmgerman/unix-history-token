begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Find the length of STRING, but scan at most MAXLEN characters.    Copyright (C) 2005, 2006, 2007 Free Software Foundation, Inc.    Written by Simon Josefsson.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/* Find the length of STRING, but scan at most MAXLEN characters.    If no '\0' terminator is found in that many characters, return MAXLEN.  */
end_comment

begin_function
name|size_t
name|strnlen
parameter_list|(
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|size_t
name|maxlen
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|end
init|=
name|memchr
argument_list|(
name|string
argument_list|,
literal|'\0'
argument_list|,
name|maxlen
argument_list|)
decl_stmt|;
return|return
name|end
condition|?
call|(
name|size_t
call|)
argument_list|(
name|end
operator|-
name|string
argument_list|)
else|:
name|maxlen
return|;
block|}
end_function

end_unit

