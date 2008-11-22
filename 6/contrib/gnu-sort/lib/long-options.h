begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* long-options.h -- declaration for --help- and --version-handling function.    Copyright (C) 1993, 1994, 1998, 1999, 2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Jim Meyering.  */
end_comment

begin_function_decl
name|void
name|parse_long_options
parameter_list|(
name|int
name|_argc
parameter_list|,
name|char
modifier|*
modifier|*
name|_argv
parameter_list|,
specifier|const
name|char
modifier|*
name|_command_name
parameter_list|,
specifier|const
name|char
modifier|*
name|_package
parameter_list|,
specifier|const
name|char
modifier|*
name|_version
parameter_list|,
name|void
function_decl|(
modifier|*
name|_usage
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|,
comment|/* const char *author1, ...*/
modifier|...
parameter_list|)
function_decl|;
end_function_decl

end_unit

