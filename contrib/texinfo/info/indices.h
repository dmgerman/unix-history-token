begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* indices.h -- Functions defined in indices.c.    $Id: indices.h,v 1.2 1997/07/06 20:50:29 karl Exp $     This file is part of GNU Info, a program for reading online documentation    stored in Info format.     Copyright (C) 1993, 97 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INFO_INDICES_H
end_ifndef

begin_define
define|#
directive|define
name|INFO_INDICES_H
end_define

begin_comment
comment|/* User-visible variable controls the output of info-index-next. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|show_index_match
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|REFERENCE
modifier|*
modifier|*
name|info_indices_of_window
argument_list|()
decl_stmt|,
modifier|*
modifier|*
name|info_indices_of_file_buffer
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|info_apropos
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* For every menu item in DIR, search the indices of that file for STRING. */
end_comment

begin_function_decl
name|REFERENCE
modifier|*
modifier|*
name|apropos_in_all_indices
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* User visible functions declared in indices.c. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|info_index_search
argument_list|()
decl_stmt|,
name|info_next_index_match
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|do_info_index_search
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|index_intry_exists
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not INFO_INDICES_H */
end_comment

end_unit

