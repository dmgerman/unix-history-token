begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Portable version of bzero for systems without it.    Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  NAME  	bzero -- zero the contents of a specified memory region  SYNOPSIS  	void bzero (char *to, int count)  DESCRIPTION  	Zero COUNT bytes of memory pointed to by TO.  BUGS  	Significant speed enhancements may be made in some environments 	by zeroing more than a single byte at a time, or by unrolling the 	loop.  */
end_comment

begin_function
name|void
name|bzero
parameter_list|(
name|to
parameter_list|,
name|count
parameter_list|)
name|char
modifier|*
name|to
decl_stmt|;
name|int
name|count
decl_stmt|;
block|{
while|while
condition|(
name|count
operator|--
operator|>
literal|0
condition|)
block|{
operator|*
name|to
operator|++
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function

end_unit

