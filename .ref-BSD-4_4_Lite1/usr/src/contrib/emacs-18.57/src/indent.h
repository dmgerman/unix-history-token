begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for interface to indent.c    Copyright (C) 1985, 1986 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_struct
struct|struct
name|position
block|{
name|int
name|bufpos
decl_stmt|;
name|int
name|hpos
decl_stmt|;
name|int
name|vpos
decl_stmt|;
name|int
name|prevhpos
decl_stmt|;
name|int
name|contin
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|position
modifier|*
name|compute_motion
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|position
modifier|*
name|vmotion
parameter_list|()
function_decl|;
end_function_decl

end_unit

