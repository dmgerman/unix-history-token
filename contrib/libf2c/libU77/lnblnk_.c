begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1995, 1997 Free Software Foundation, Inc. This file is part of GNU Fortran libU77 library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with GNU Fortran; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* via f2c from Fortran */
end_comment

begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_function
name|integer
name|G77_lnblnk_0
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|ftnlen
name|str_len
parameter_list|)
block|{
name|integer
name|ret_val
decl_stmt|;
name|integer
name|i_len
parameter_list|()
function_decl|;
for|for
control|(
name|ret_val
operator|=
name|str_len
init|;
name|ret_val
operator|>=
literal|1
condition|;
operator|--
name|ret_val
control|)
block|{
if|if
condition|(
operator|*
operator|(
name|unsigned
name|char
operator|*
operator|)
operator|&
name|str
index|[
name|ret_val
operator|-
literal|1
index|]
operator|!=
literal|' '
condition|)
block|{
return|return
name|ret_val
return|;
block|}
block|}
return|return
name|ret_val
return|;
block|}
end_function

end_unit

