begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1996 Free Software Foundation, Inc. This file is part of GNU Fortran libU77 library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with GNU Fortran; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_function
name|double
name|G77_second_0
parameter_list|()
block|{
specifier|extern
name|double
name|G77_etime_0
parameter_list|()
function_decl|;
name|real
name|tarray
index|[
literal|2
index|]
decl_stmt|;
return|return
name|G77_etime_0
argument_list|(
name|tarray
argument_list|)
return|;
block|}
end_function

end_unit

