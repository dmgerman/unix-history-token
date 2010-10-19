begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sym_ids.h     Copyright 2000, 2001, 2002, 2004 Free Software Foundation, Inc.  This file is part of GNU Binutils.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|sym_ids_h
end_ifndef

begin_define
define|#
directive|define
name|sym_ids_h
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|INCL_GRAPH
init|=
literal|0
block|,
name|EXCL_GRAPH
block|,
name|INCL_ARCS
block|,
name|EXCL_ARCS
block|,
name|INCL_FLAT
block|,
name|EXCL_FLAT
block|,
name|INCL_TIME
block|,
name|EXCL_TIME
block|,
name|INCL_ANNO
block|,
name|EXCL_ANNO
block|,
name|INCL_EXEC
block|,
name|EXCL_EXEC
block|,
name|NUM_TABLES
block|}
name|Table_Id
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|Sym_Table
name|syms
index|[
name|NUM_TABLES
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|sym_id_add
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|Table_Id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sym_id_parse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|sym_id_arc_is_present
parameter_list|(
name|Sym_Table
modifier|*
parameter_list|,
name|Sym
modifier|*
parameter_list|,
name|Sym
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sym_ids_h */
end_comment

end_unit

