begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 1989, 1990 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.uucp)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file LICENSE.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_struct
struct|struct
name|keyword
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|token
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|const
name|keyword
modifier|*
name|lookup_keyword
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

end_unit

