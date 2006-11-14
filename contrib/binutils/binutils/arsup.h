begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* arsup.h - archive support header file    Copyright 1992, 1993, 1994, 1996, 2003 Free Software Foundation, Inc.  This file is part of GNU Binutils.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_struct
struct|struct
name|list
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|list
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|maybequit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prompt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_clear
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_replace
parameter_list|(
name|struct
name|list
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_delete
parameter_list|(
name|struct
name|list
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_save
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_list
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_open
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_directory
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|list
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_addmod
parameter_list|(
name|struct
name|list
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_addlib
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|list
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_extract
parameter_list|(
name|struct
name|list
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd
modifier|*
name|open_inarch
parameter_list|(
specifier|const
name|char
modifier|*
name|archive_filename
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|yylex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yyparse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions from ar.c */
end_comment

begin_function_decl
name|void
name|extract_file
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|interactive
decl_stmt|;
end_decl_stmt

end_unit

