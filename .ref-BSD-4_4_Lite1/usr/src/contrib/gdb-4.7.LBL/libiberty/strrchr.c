begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Portable version of strrchr().    Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  NAME  	strrchr -- return pointer to last occurance of a character  SYNOPSIS  	char *strrchr (const char *s, int c)  DESCRIPTION  	Returns a pointer to the last occurance of character C in 	string S, or a NULL pointer if no occurance is found. 	 BUGS  	Behavior when character is the null character is implementation 	dependent.  */
end_comment

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_function
name|char
modifier|*
name|strrchr
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
specifier|register
name|CONST
name|char
modifier|*
name|s
decl_stmt|;
name|int
name|c
decl_stmt|;
block|{
name|char
modifier|*
name|rtnval
init|=
literal|0
decl_stmt|;
do|do
block|{
if|if
condition|(
operator|*
name|s
operator|==
name|c
condition|)
name|rtnval
operator|=
name|s
expr_stmt|;
block|}
do|while
condition|(
operator|*
name|s
operator|++
condition|)
do|;
return|return
operator|(
name|rtnval
operator|)
return|;
block|}
end_function

end_unit

