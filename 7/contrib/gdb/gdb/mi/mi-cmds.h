begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* MI Command Set for GDB, the GNU debugger.     Copyright 2000, 2003, 2004 Free Software Foundation, Inc.     Contributed by Cygnus Solutions (a Red Hat company).     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MI_CMDS_H
end_ifndef

begin_define
define|#
directive|define
name|MI_CMDS_H
end_define

begin_comment
comment|/* An MI command can return any of the following. */
end_comment

begin_enum
enum|enum
name|mi_cmd_result
block|{
comment|/* Report the command as ``done''.  Display both the ``NNN^done''        message and the completion prompt.  */
name|MI_CMD_DONE
init|=
literal|0
block|,
comment|/* The command is still running in the forground.  Main loop should        display the completion prompt. */
name|MI_CMD_FORGROUND
block|,
comment|/* An error condition was detected and an error message was        asprintf'd into the mi_error_message buffer.  The main loop will        display the error message and the completion prompt. */
name|MI_CMD_ERROR
block|,
comment|/* An error condition was detected and caught.  The error message is        in the global error message buffer. The main loop will display        the error message and the completion prompt. */
name|MI_CMD_CAUGHT_ERROR
block|,
comment|/* The MI command has already displayed its completion message.        Main loop will not display a completion message but will display        the completion prompt. */
name|MI_CMD_QUIET
block|}
enum|;
end_enum

begin_enum
enum|enum
name|print_values
block|{
name|PRINT_NO_VALUES
block|,
name|PRINT_ALL_VALUES
block|,
name|PRINT_SIMPLE_VALUES
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|mi_cmd_result
function_decl|(
name|mi_cmd_argv_ftype
function_decl|)
parameter_list|(
name|char
modifier|*
name|command
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|int
name|argc
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Older MI commands have this interface. Retained until all old    commands are flushed. */
end_comment

begin_typedef
typedef|typedef
name|enum
name|mi_cmd_result
function_decl|(
name|mi_cmd_args_ftype
function_decl|)
parameter_list|(
comment|/*ui */
name|char
modifier|*
name|args
parameter_list|,
name|int
name|from_tty
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Function implementing each command */
end_comment

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_break_insert
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_break_watch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_disassemble
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_data_evaluate_expression
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_data_list_register_names
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_data_list_register_values
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_data_list_changed_registers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_data_read_memory
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_data_write_memory
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_data_write_register_values
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_env_cd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_env_dir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_env_path
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_env_pwd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_args_ftype
name|mi_cmd_exec_continue
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_args_ftype
name|mi_cmd_exec_finish
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_args_ftype
name|mi_cmd_exec_next
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_args_ftype
name|mi_cmd_exec_next_instruction
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_args_ftype
name|mi_cmd_exec_return
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_args_ftype
name|mi_cmd_exec_run
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_args_ftype
name|mi_cmd_exec_step
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_args_ftype
name|mi_cmd_exec_step_instruction
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_args_ftype
name|mi_cmd_exec_until
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_args_ftype
name|mi_cmd_exec_interrupt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_file_list_exec_source_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_gdb_exit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_interpreter_exec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_stack_info_depth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_stack_list_args
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_stack_list_frames
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_stack_list_locals
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_stack_select_frame
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_symbol_list_lines
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_args_ftype
name|mi_cmd_target_download
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_args_ftype
name|mi_cmd_target_select
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_thread_list_ids
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_thread_select
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_var_assign
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_var_create
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_var_delete
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_var_evaluate_expression
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_var_info_expression
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_var_info_num_children
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_var_info_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_var_list_children
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_var_set_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_var_show_attributes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_var_show_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mi_cmd_argv_ftype
name|mi_cmd_var_update
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Description of a single command. */
end_comment

begin_struct
struct|struct
name|mi_cli
block|{
comment|/* Corresponding CLI command.  If ARGS_P is non-zero, the MI      command's argument list is appended to the CLI command.  */
specifier|const
name|char
modifier|*
name|cmd
decl_stmt|;
name|int
name|args_p
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mi_cmd
block|{
comment|/* official name of the command.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* The corresponding CLI command that can be used to implement this      MI command (if cli.lhs is non NULL).  */
name|struct
name|mi_cli
name|cli
decl_stmt|;
comment|/* If non-null, the function implementing the MI command.  */
name|mi_cmd_args_ftype
modifier|*
name|args_func
decl_stmt|;
comment|/* If non-null, the function implementing the MI command.  */
name|mi_cmd_argv_ftype
modifier|*
name|argv_func
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Lookup a command in the mi comand table */
end_comment

begin_function_decl
specifier|extern
name|struct
name|mi_cmd
modifier|*
name|mi_lookup
parameter_list|(
specifier|const
name|char
modifier|*
name|command
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Debug flag */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mi_debug_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Raw console output - FIXME: should this be a parameter? */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ui_file
modifier|*
name|raw_stdout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mi_error_message
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|mi_error_last_message
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mi_execute_command
parameter_list|(
name|char
modifier|*
name|cmd
parameter_list|,
name|int
name|from_tty
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

