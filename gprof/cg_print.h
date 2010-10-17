begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* cg_print.h     Copyright 2000, 2001 Free Software Foundation, Inc.  This file is part of GNU Binutils.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|cg_print_h
end_ifndef

begin_define
define|#
directive|define
name|cg_print_h
end_define

begin_decl_stmt
specifier|extern
name|double
name|print_time
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Total of time being printed.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cg_print
name|PARAMS
argument_list|(
operator|(
name|Sym
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cg_print_index
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cg_print_file_ordering
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cg_print_function_ordering
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* cg_print_h */
end_comment

end_unit

