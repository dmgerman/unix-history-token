begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* An abstract string datatype.    Copyright (C) 1998, 1999 Free Software Foundation, Inc.    Contributed by Mark Mitchell (mark@markmitchell.com).  This file is part of GNU CC.     GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dyn_string
block|{
name|int
name|allocated
decl_stmt|;
comment|/* The amount of space allocated for the string.  */
name|int
name|length
decl_stmt|;
comment|/* The actual length of the string.  */
name|char
modifier|*
name|s
decl_stmt|;
comment|/* The string itself, NUL-terminated.  */
block|}
typedef|*
name|dyn_string_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|dyn_string_t
name|dyn_string_new
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dyn_string_delete
name|PROTO
argument_list|(
operator|(
name|dyn_string_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dyn_string_t
name|dyn_string_append
name|PROTO
argument_list|(
operator|(
name|dyn_string_t
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dyn_string_t
name|dyn_string_resize
name|PROTO
argument_list|(
operator|(
name|dyn_string_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

