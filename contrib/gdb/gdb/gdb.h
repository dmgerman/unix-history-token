begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Library interface into GDB.    Copyright 1999, 2001    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GDB_H
end_ifndef

begin_define
define|#
directive|define
name|GDB_H
end_define

begin_struct_decl
struct_decl|struct
name|ui_out
struct_decl|;
end_struct_decl

begin_comment
comment|/* Return-code (RC) from a gdb library call.  (The abreviation RC is    taken from the sim/common directory.) */
end_comment

begin_enum
enum|enum
name|gdb_rc
block|{
comment|/* The operation failed.  The failure message can be fetched by      calling ``char *error_last_message(void)''. The value is      determined by the catch_errors() interface. */
comment|/* NOTE: Since ``defs.h:catch_errors()'' does not return an error /      internal / quit indication it is not possible to return that      here. */
name|GDB_RC_FAIL
init|=
literal|0
block|,
comment|/* No error occured but nothing happened. Due to the catch_errors()      interface, this must be non-zero. */
name|GDB_RC_NONE
init|=
literal|1
block|,
comment|/* The operation was successful. Due to the catch_errors()      interface, this must be non-zero. */
name|GDB_RC_OK
init|=
literal|2
block|}
enum|;
end_enum

begin_comment
comment|/* Print the specified breakpoint on GDB_STDOUT. (Eventually this    function will ``print'' the object on ``output''). */
end_comment

begin_function_decl
name|enum
name|gdb_rc
name|gdb_breakpoint_query
parameter_list|(
name|struct
name|ui_out
modifier|*
name|uiout
parameter_list|,
name|int
name|bnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create a breakpoint at ADDRESS (a GDB source and line). */
end_comment

begin_function_decl
name|enum
name|gdb_rc
name|gdb_breakpoint
parameter_list|(
name|char
modifier|*
name|address
parameter_list|,
name|char
modifier|*
name|condition
parameter_list|,
name|int
name|hardwareflag
parameter_list|,
name|int
name|tempflag
parameter_list|,
name|int
name|thread
parameter_list|,
name|int
name|ignore_count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Switch thread and print notification. */
end_comment

begin_function_decl
name|enum
name|gdb_rc
name|gdb_thread_select
parameter_list|(
name|struct
name|ui_out
modifier|*
name|uiout
parameter_list|,
name|char
modifier|*
name|tidstr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print a list of known thread ids. */
end_comment

begin_function_decl
name|enum
name|gdb_rc
name|gdb_list_thread_ids
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

end_unit

