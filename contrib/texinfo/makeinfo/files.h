begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* files.h -- declarations for files.c.    $Id: files.h,v 1.2 2002/01/16 15:52:45 karl Exp $     Copyright (C) 1998, 2002 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.    */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FILES_H
end_ifndef

begin_define
define|#
directive|define
name|FILES_H
end_define

begin_comment
comment|/* A stack of file information records.  If a new file is read in with    "@input", we remember the old input file state on this stack. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|fstack
block|{
name|struct
name|fstack
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|filename
decl_stmt|;
name|char
modifier|*
name|text
decl_stmt|;
name|int
name|size
decl_stmt|;
name|int
name|offset
decl_stmt|;
name|int
name|line_number
decl_stmt|;
block|}
name|FSTACK
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|FSTACK
modifier|*
name|filestack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pushfile
argument_list|()
decl_stmt|,
name|popfile
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|flush_file_stack
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|find_and_load
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_name_from_input_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|expand_filename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|filename_part
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|pathname_part
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|normalize_filename
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !FILES_H */
end_comment

end_unit

