begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 1989, 1990, 1991, 1992 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_function_decl
name|void
name|process_commands
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|process_commands
parameter_list|(
name|string
modifier|&
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|lineno
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|accumulate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|move_punctuation
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|search_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|search_list
name|database_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|label_in_text
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|label_in_reference
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sort_adjacent_labels
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|string
name|pre_label
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|string
name|post_label
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|string
name|sep_label
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|do_bib
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|output_references
parameter_list|()
function_decl|;
end_function_decl

end_unit

