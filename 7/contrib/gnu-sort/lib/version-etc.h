begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Utility to help print --version output in a consistent format.    Copyright (C) 1999, 2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Jim Meyering. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VERSION_ETC_H
end_ifndef

begin_define
define|#
directive|define
name|VERSION_ETC_H
value|1
end_define

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|version_etc_copyright
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|version_etc_va
parameter_list|(
name|FILE
modifier|*
name|stream
parameter_list|,
specifier|const
name|char
modifier|*
name|command_name
parameter_list|,
specifier|const
name|char
modifier|*
name|package
parameter_list|,
specifier|const
name|char
modifier|*
name|version
parameter_list|,
name|va_list
name|authors
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|version_etc
parameter_list|(
name|FILE
modifier|*
name|stream
parameter_list|,
specifier|const
name|char
modifier|*
name|command_name
parameter_list|,
specifier|const
name|char
modifier|*
name|package
parameter_list|,
specifier|const
name|char
modifier|*
name|version
parameter_list|,
comment|/* const char *author1, ...*/
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VERSION_ETC_H */
end_comment

end_unit

