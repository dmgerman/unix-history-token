begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* exclude.h -- declarations for excluding file names     Copyright (C) 1992, 1993, 1994, 1997, 1999, 2001, 2002, 2003 Free    Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.    If not, write to the Free Software Foundation,    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Paul Eggert<eggert@twinsun.com>  */
end_comment

begin_comment
comment|/* Exclude options, which can be ORed with fnmatch options.  */
end_comment

begin_comment
comment|/* Patterns must match the start of file names, instead of matching    anywhere after a '/'.  */
end_comment

begin_define
define|#
directive|define
name|EXCLUDE_ANCHORED
value|(1<< 30)
end_define

begin_comment
comment|/* Include instead of exclude.  */
end_comment

begin_define
define|#
directive|define
name|EXCLUDE_INCLUDE
value|(1<< 29)
end_define

begin_comment
comment|/* '?', '*', '[', and '\\' are special in patterns.  Without this    option, these characters are ordinary and fnmatch is not used.  */
end_comment

begin_define
define|#
directive|define
name|EXCLUDE_WILDCARDS
value|(1<< 28)
end_define

begin_struct_decl
struct_decl|struct
name|exclude
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|exclude
modifier|*
name|new_exclude
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_exclude
parameter_list|(
name|struct
name|exclude
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_exclude
parameter_list|(
name|struct
name|exclude
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|add_exclude_file
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|exclude
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|struct
name|exclude
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|excluded_filename
parameter_list|(
name|struct
name|exclude
specifier|const
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

