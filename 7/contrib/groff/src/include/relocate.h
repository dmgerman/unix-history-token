begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Provide relocation for macro and font files.    Copyright (C) 2005 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify it    under the terms of the GNU Library General Public License as published    by the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301,    USA.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|curr_prefix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|curr_prefix_len
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|set_current_prefix
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xdirname
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|searchpath
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|pathp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|relocatep
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|relocate
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

end_unit

