begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* MI Command Set - MI output generating routines for GDB.    Copyright 2000 Free Software Foundation, Inc.    Contributed by Cygnus Solutions (a Red Hat company).     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MI_OUT_H
end_ifndef

begin_define
define|#
directive|define
name|MI_OUT_H
value|1
end_define

begin_struct_decl
struct_decl|struct
name|ui_out
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ui_file
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|struct
name|ui_out
modifier|*
name|mi_out_new
parameter_list|(
name|int
name|mi_version
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mi_out_put
parameter_list|(
name|struct
name|ui_out
modifier|*
name|uiout
parameter_list|,
name|struct
name|ui_file
modifier|*
name|stream
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mi_out_rewind
parameter_list|(
name|struct
name|ui_out
modifier|*
name|uiout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mi_out_buffered
parameter_list|(
name|struct
name|ui_out
modifier|*
name|uiout
parameter_list|,
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the version number of the current MI.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|mi_version
parameter_list|(
name|struct
name|ui_out
modifier|*
name|uiout
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MI_OUT_H */
end_comment

end_unit

