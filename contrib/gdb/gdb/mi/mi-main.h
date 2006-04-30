begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* MI Internal Functions for GDB, the GNU debugger.     Copyright 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MI_MAIN_H
end_ifndef

begin_define
define|#
directive|define
name|MI_MAIN_H
end_define

begin_function_decl
specifier|extern
name|void
name|mi_setup_architecture_data
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mi_load_progress
parameter_list|(
specifier|const
name|char
modifier|*
name|section_name
parameter_list|,
name|unsigned
name|long
name|sent_so_far
parameter_list|,
name|unsigned
name|long
name|total_section
parameter_list|,
name|unsigned
name|long
name|total_sent
parameter_list|,
name|unsigned
name|long
name|grand_total
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

