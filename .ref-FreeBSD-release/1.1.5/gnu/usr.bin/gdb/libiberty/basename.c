begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Return the basename of a pathname.    Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  NAME  	basename -- return pointer to last component of a pathname  SYNOPSIS  	char *basename (char *name)  DESCRIPTION  	Given a pointer to a string containing a typical pathname 	(/usr/src/cmd/ls/ls.c for example), returns a pointer to the 	last component of the pathname ("ls.c" in this case).  BUGS  	Presumes a UNIX style path with UNIX style separators. */
end_comment

begin_function
name|char
modifier|*
name|basename
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
name|char
modifier|*
name|base
init|=
name|name
decl_stmt|;
while|while
condition|(
operator|*
name|name
condition|)
block|{
if|if
condition|(
operator|*
name|name
operator|++
operator|==
literal|'/'
condition|)
block|{
name|base
operator|=
name|name
expr_stmt|;
block|}
block|}
return|return
operator|(
name|base
operator|)
return|;
block|}
end_function

end_unit

