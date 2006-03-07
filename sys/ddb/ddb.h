begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993, Garrett A. Wollman.  * Copyright (c) 1993, University of Vermont and State Agricultural College.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Necessary declarations for the `ddb' kernel debugger.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DDB_DDB_H_
end_ifndef

begin_define
define|#
directive|define
name|_DDB_DDB_H_
end_define

begin_include
include|#
directive|include
file|<machine/db_machdep.h>
end_include

begin_comment
comment|/* type definitions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DB_MAXARGS
end_ifndef

begin_define
define|#
directive|define
name|DB_MAXARGS
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DB_CALL
end_ifndef

begin_define
define|#
directive|define
name|DB_CALL
value|db_fncall_generic
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|DB_CALL
parameter_list|(
name|db_expr_t
parameter_list|,
name|db_expr_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|db_expr_t
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
name|db_cmdfcn_t
parameter_list|(
name|db_expr_t
name|addr
parameter_list|,
name|boolean_t
name|have_addr
parameter_list|,
name|db_expr_t
name|count
parameter_list|,
name|char
modifier|*
name|modif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|db_page_calloutfcn_t
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|DB_COMMAND
parameter_list|(
name|cmd_name
parameter_list|,
name|func_name
parameter_list|)
define|\
value|DB_FUNC(cmd_name, func_name, db_cmd_set, 0, NULL)
end_define

begin_define
define|#
directive|define
name|DB_SHOW_COMMAND
parameter_list|(
name|cmd_name
parameter_list|,
name|func_name
parameter_list|)
define|\
value|DB_FUNC(cmd_name, func_name, db_show_cmd_set, 0, NULL)
end_define

begin_define
define|#
directive|define
name|DB_SET
parameter_list|(
name|cmd_name
parameter_list|,
name|func_name
parameter_list|,
name|set
parameter_list|,
name|flag
parameter_list|,
name|more
parameter_list|)
define|\
value|static const struct command __CONCAT(cmd_name,_cmd) = {		\ 	__STRING(cmd_name),					\ 	func_name,						\ 	flag,							\ 	more							\ };								\ TEXT_SET(set, __CONCAT(cmd_name,_cmd))
end_define

begin_define
define|#
directive|define
name|DB_FUNC
parameter_list|(
name|cmd_name
parameter_list|,
name|func_name
parameter_list|,
name|set
parameter_list|,
name|flag
parameter_list|,
name|more
parameter_list|)
define|\
value|static db_cmdfcn_t	func_name;				\ 								\ DB_SET(cmd_name, func_name, set, flag, more);			\ 								\ static void							\ func_name(addr, have_addr, count, modif)			\ 	db_expr_t addr;						\ 	boolean_t have_addr;					\ 	db_expr_t count;					\ 	char *modif;
end_define

begin_decl_stmt
specifier|extern
name|db_expr_t
name|db_maxoff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|db_indent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|db_inst_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|db_load_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|db_store_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|db_expr_t
name|db_radix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|db_expr_t
name|db_max_width
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|db_expr_t
name|db_tab_stop_width
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|db_expr_t
name|db_lines_per_page
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vm_map
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|db_check_interrupt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_clear_watchpoints
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|db_addr_t
name|db_disasm
parameter_list|(
name|db_addr_t
name|loc
parameter_list|,
name|boolean_t
name|altfmt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* instruction disassembler */
end_comment

begin_function_decl
name|void
name|db_error
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|db_expression
parameter_list|(
name|db_expr_t
modifier|*
name|valuep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|db_get_variable
parameter_list|(
name|db_expr_t
modifier|*
name|valuep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_iprintf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|struct
name|vm_map
modifier|*
name|db_map_addr
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|db_map_current
parameter_list|(
name|struct
name|vm_map
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|db_map_equal
parameter_list|(
name|struct
name|vm_map
modifier|*
parameter_list|,
name|struct
name|vm_map
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|db_md_set_watchpoint
parameter_list|(
name|db_expr_t
name|addr
parameter_list|,
name|db_expr_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|db_md_clr_watchpoint
parameter_list|(
name|db_expr_t
name|addr
parameter_list|,
name|db_expr_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_md_list_watchpoints
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_print_loc_and_inst
parameter_list|(
name|db_addr_t
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_print_thread
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_printf
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|db_read_bytes
parameter_list|(
name|vm_offset_t
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* machine-dependent */
end_comment

begin_function_decl
name|int
name|db_readline
parameter_list|(
name|char
modifier|*
name|lstart
parameter_list|,
name|int
name|lsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_restart_at_pc
parameter_list|(
name|boolean_t
name|watchpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|db_set_variable
parameter_list|(
name|db_expr_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_set_watchpoints
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_setup_paging
parameter_list|(
name|db_page_calloutfcn_t
modifier|*
name|callout
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|maxlines
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_skip_to_eol
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|db_stop_at_pc
parameter_list|(
name|boolean_t
modifier|*
name|is_breakpoint
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|db_strcpy
value|strcpy
end_define

begin_function_decl
name|void
name|db_trace_self
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|db_trace_thread
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|db_value_of_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|db_expr_t
modifier|*
name|valuep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|db_write_bytes
parameter_list|(
name|vm_offset_t
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|db_cmdfcn_t
name|db_breakpoint_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_cmdfcn_t
name|db_continue_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_cmdfcn_t
name|db_delete_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_cmdfcn_t
name|db_deletehwatch_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_cmdfcn_t
name|db_deletewatch_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_cmdfcn_t
name|db_examine_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_cmdfcn_t
name|db_hwatchpoint_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_cmdfcn_t
name|db_listbreak_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_cmdfcn_t
name|db_print_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_cmdfcn_t
name|db_ps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_cmdfcn_t
name|db_search_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_cmdfcn_t
name|db_set_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_cmdfcn_t
name|db_set_thread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_cmdfcn_t
name|db_show_regs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_cmdfcn_t
name|db_show_threads
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_cmdfcn_t
name|db_single_step_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_cmdfcn_t
name|db_trace_until_call_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_cmdfcn_t
name|db_trace_until_matching_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_cmdfcn_t
name|db_watchpoint_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_cmdfcn_t
name|db_write_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_page_calloutfcn_t
name|db_simple_pager
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Command table.  */
end_comment

begin_struct_decl
struct_decl|struct
name|command
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|command_table
block|{
name|struct
name|command
modifier|*
name|table
decl_stmt|;
name|struct
name|command
modifier|*
modifier|*
name|aux_tablep
decl_stmt|;
name|struct
name|command
modifier|*
modifier|*
name|aux_tablep_end
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|command
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* command name */
name|db_cmdfcn_t
modifier|*
name|fcn
decl_stmt|;
comment|/* function to call */
name|int
name|flag
decl_stmt|;
comment|/* extra info: */
define|#
directive|define
name|CS_OWN
value|0x1
comment|/* non-standard syntax */
define|#
directive|define
name|CS_MORE
value|0x2
comment|/* standard syntax, but may have other words 				 * at end */
define|#
directive|define
name|CS_SET_DOT
value|0x100
comment|/* set dot after command */
name|struct
name|command_table
modifier|*
name|more
decl_stmt|;
comment|/* another level of command */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DDB_DDB_H_ */
end_comment

end_unit

