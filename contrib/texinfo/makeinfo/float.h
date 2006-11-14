begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* float.h -- declarations for the float environment.    $Id: float.h,v 1.5 2004/04/11 17:56:47 karl Exp $     Copyright (C) 2003, 2004 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Alper Ersoy<dirt@gtk.org>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FLOAT_H
end_ifndef

begin_define
define|#
directive|define
name|FLOAT_H
end_define

begin_typedef
typedef|typedef
struct|struct
name|float_elt
block|{
name|struct
name|float_elt
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|id
decl_stmt|;
name|char
modifier|*
name|type
decl_stmt|;
name|char
modifier|*
name|title
decl_stmt|;
name|char
modifier|*
name|shorttitle
decl_stmt|;
name|char
modifier|*
name|position
decl_stmt|;
name|char
modifier|*
name|number
decl_stmt|;
name|char
modifier|*
name|section
decl_stmt|;
name|char
modifier|*
name|section_name
decl_stmt|;
name|short
name|title_used
decl_stmt|;
name|int
name|defining_line
decl_stmt|;
block|}
name|FLOAT_ELT
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|add_new_float
parameter_list|(
name|char
modifier|*
name|id
parameter_list|,
name|char
modifier|*
name|title
parameter_list|,
name|char
modifier|*
name|shorttitle
parameter_list|,
name|char
modifier|*
name|type
parameter_list|,
name|char
modifier|*
name|position
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|current_float_set_title_used
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Information retrieval about the current float env.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|current_float_id
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|current_float_title
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|current_float_shorttitle
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|current_float_type
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|current_float_position
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|current_float_number
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|get_float_ref
parameter_list|(
name|char
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|count_floats_of_type_in_chapter
parameter_list|(
name|char
modifier|*
name|type
parameter_list|,
name|char
modifier|*
name|chapter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|current_float_used_title
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not FLOAT_H */
end_comment

end_unit

