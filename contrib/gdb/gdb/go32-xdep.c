begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Host-dependent code for dos running GO32 for GDB, the GNU debugger.    Copyright 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|int
name|sigsetmask
parameter_list|(
name|mask
parameter_list|)
name|int
name|mask
decl_stmt|;
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|strlwr
parameter_list|(
name|str
parameter_list|)
name|char
modifier|*
name|str
decl_stmt|;
block|{
for|for
control|(
init|;
operator|*
name|str
condition|;
name|str
operator|++
control|)
operator|*
name|str
operator|=
name|tolower
argument_list|(
operator|*
name|str
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

