begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Emulate bcmp using memcmp    Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  NAME  	bcmp -- compare two memory regions  SYNOPSIS  	int bcmp (char *from, char *to, int count)  DESCRIPTION  	Compare two memory regions and return zero if they are identical, 	non-zero otherwise.  If count is zero, return zero.  NOTES  	No guarantee is made about the non-zero returned value.  In 	particular, the results may be signficantly different than 	strcmp(), where the return value is guaranteed to be less than, 	equal to, or greater than zero, according to lexicographical 	sorting of the compared regions.  BUGS  */
end_comment

begin_function
name|int
name|bcmp
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|,
name|count
parameter_list|)
name|char
modifier|*
name|from
decl_stmt|,
decl|*
name|to
decl_stmt|;
end_function

begin_decl_stmt
name|int
name|count
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|rtnval
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|count
operator|--
operator|>
literal|0
condition|)
block|{
if|if
condition|(
operator|*
name|from
operator|++
operator|!=
operator|*
name|to
operator|++
condition|)
block|{
name|rtnval
operator|=
literal|1
expr_stmt|;
break|break;
block|}
block|}
return|return
operator|(
name|rtnval
operator|)
return|;
block|}
end_block

end_unit

