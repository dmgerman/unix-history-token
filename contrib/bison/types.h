begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Define data type for representing bison's grammar input as it is parsed,    Copyright (C) 1984, 1989 Free Software Foundation, Inc.  This file is part of Bison, the GNU Compiler Compiler.  Bison is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  Bison is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with Bison; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|shorts
block|{
name|struct
name|shorts
modifier|*
name|next
decl_stmt|;
name|short
name|value
decl_stmt|;
block|}
name|shorts
typedef|;
end_typedef

end_unit

