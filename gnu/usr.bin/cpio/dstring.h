begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dstring.h - Dynamic string handling include file.  Requires strings.h.    Copyright (C) 1990, 1991, 1992 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A dynamic string consists of record that records the size of an    allocated string and the pointer to that string.  The actual string    is a normal zero byte terminated string that can be used with the    usual string functions.  The major difference is that the    dynamic_string routines know how to get more space if it is needed    by allocating new space and copying the current string.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|ds_length
decl_stmt|;
comment|/* Actual amount of storage allocated.  */
name|char
modifier|*
name|ds_string
decl_stmt|;
comment|/* String.  */
block|}
name|dynamic_string
typedef|;
end_typedef

begin_comment
comment|/* Macros that look similar to the original string functions.    WARNING:  These macros work only on pointers to dynamic string records.    If used with a real record, an "&" must be used to get the pointer.  */
end_comment

begin_define
define|#
directive|define
name|ds_strlen
parameter_list|(
name|s
parameter_list|)
value|strlen ((s)->ds_string)
end_define

begin_define
define|#
directive|define
name|ds_strcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|strcmp ((s1)->ds_string, (s2)->ds_string)
end_define

begin_define
define|#
directive|define
name|ds_strncmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|strncmp ((s1)->ds_string, (s2)->ds_string, n)
end_define

begin_define
define|#
directive|define
name|ds_index
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|index ((s)->ds_string, c)
end_define

begin_define
define|#
directive|define
name|ds_rindex
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|rindex ((s)->ds_string, c)
end_define

begin_function_decl
name|void
name|ds_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ds_resize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ds_fgetname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ds_fgets
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ds_fgetstr
parameter_list|()
function_decl|;
end_function_decl

end_unit

