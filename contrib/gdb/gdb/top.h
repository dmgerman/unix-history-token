begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Top level stuff for GDB, the GNU debugger.    Copyright 1986, 1987, 1988, 1989, 1990, 1991, 1992, 1993, 1994, 1996,    1997, 1998, 1999, 2000 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TOP_H
end_ifndef

begin_define
define|#
directive|define
name|TOP_H
end_define

begin_comment
comment|/* From top.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|linesize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|instream
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|gdb_dirbuf
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inhibit_gdbinit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|epoch_interface
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|gdbinit
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|print_gdb_version
parameter_list|(
name|struct
name|ui_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|source_command
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cd_command
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|read_command_file
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_history
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|command_loop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|simplified_command_loop
parameter_list|(
name|char
modifier|*
function_decl|(
modifier|*
name|read_input_func
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|execute_command_func
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|quit_confirm
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|quit_force
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|quit_command
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|quit_cover
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|execute_command
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This function returns a pointer to the string that is used    by gdb for its command prompt. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|get_prompt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This function copies the specified string into the string that    is used by gdb for its command prompt. */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_prompt
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From random places.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|readnow_symbol_files
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Perform _initialize initialization */
end_comment

begin_function_decl
specifier|extern
name|void
name|gdb_init
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* For use by event-top.c */
end_comment

begin_comment
comment|/* Variables from top.c. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|source_line_number
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|source_file_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|source_error
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|source_pre_error
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|history_expansion_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|server_command
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|lim_at_start
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|show_commands
parameter_list|(
name|char
modifier|*
name|args
parameter_list|,
name|int
name|from_tty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_history
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|show_history
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_verbose
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|cmd_list_element
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_restore_instream_cleanup
parameter_list|(
name|void
modifier|*
name|stream
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

