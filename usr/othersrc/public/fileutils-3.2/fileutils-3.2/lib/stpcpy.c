begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* stpcpy.c -- copy a string and return pointer to end of new string     Copyright (C) 1989, 1990 Free Software Foundation.      This program is free software; you can redistribute it and/or modify     it under the terms of the GNU General Public License as published by     the Free Software Foundation; either version 2, or (at your option)     any later version.      This program is distributed in the hope that it will be useful,     but WITHOUT ANY WARRANTY; without even the implied warranty of     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     GNU General Public License for more details.      You should have received a copy of the GNU General Public License     along with this program; if not, write to the Free Software     Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_comment
comment|/* Copy SOURCE into DEST, stopping after copying the first '\0', and    return a pointer to the '\0' at the end of DEST;    in other words, return DEST + strlen (SOURCE). */
end_comment

begin_function
name|char
modifier|*
name|stpcpy
parameter_list|(
name|dest
parameter_list|,
name|source
parameter_list|)
name|char
modifier|*
name|dest
decl_stmt|;
name|char
modifier|*
name|source
decl_stmt|;
block|{
while|while
condition|(
operator|(
operator|*
name|dest
operator|++
operator|=
operator|*
name|source
operator|++
operator|)
operator|!=
literal|'\0'
condition|)
comment|/* Do nothing. */
empty_stmt|;
return|return
name|dest
operator|-
literal|1
return|;
block|}
end_function

end_unit

