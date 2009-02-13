begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for complaint handling during symbol reading in GDB.     Copyright 1990, 1991, 1992, 1995, 1998, 2000, 2002 Free Software    Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|COMPLAINTS_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|COMPLAINTS_H
end_define

begin_comment
comment|/* Opaque object used to track the number of complaints of a    particular category.  */
end_comment

begin_struct_decl
struct_decl|struct
name|complaints
struct_decl|;
end_struct_decl

begin_comment
comment|/* Predefined categories.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|complaints
modifier|*
name|symfile_complaints
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Register a complaint.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|complaint
parameter_list|(
name|struct
name|complaints
modifier|*
modifier|*
name|complaints
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|ATTR_FORMAT
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|internal_complaint
parameter_list|(
name|struct
name|complaints
modifier|*
modifier|*
name|complaints
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|ATTR_FORMAT
parameter_list|(
name|printf
parameter_list|,
function_decl|4
operator|,
function_decl|5
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Clear out / initialize all complaint counters that have ever been    incremented.  If LESS_VERBOSE is 1, be less verbose about    successive complaints, since the messages are appearing all    together during a command that is reporting a contiguous block of    complaints (rather than being interleaved with other messages).  If    noisy is 1, we are in a noisy command, and our caller will print    enough context for the user to figure it out.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|clear_complaints
parameter_list|(
name|struct
name|complaints
modifier|*
modifier|*
name|complaints
parameter_list|,
name|int
name|less_verbose
parameter_list|,
name|int
name|noisy
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (COMPLAINTS_H) */
end_comment

end_unit

