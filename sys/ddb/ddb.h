begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993, Garrett A. Wollman.  * Copyright (c) 1993, University of Vermont and State Agricultural College.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: ddb.h,v 1.14 1997/02/22 09:28:35 peter Exp $  */
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

begin_typedef
typedef|typedef
name|void
name|db_cmdfcn_t
name|__P
typedef|((
name|db_expr_t
name|addr
typedef|,
name|boolean_t
name|have_addr
typedef|,
name|db_expr_t
name|count
typedef|,
name|char
modifier|*
name|modif
typedef|));
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
value|DB_SET(cmd_name, func_name, db_cmd_set)
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
value|DB_SET(cmd_name, func_name, db_show_cmd_set)
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
parameter_list|)
define|\
value|static db_cmdfcn_t	func_name;				\ 								\ static const struct command __CONCAT(func_name,_cmd) = {	\ 	__STRING(cmd_name),					\ 	func_name,						\ 	0,							\ 	0,							\ };								\ TEXT_SET(set, __CONCAT(func_name,_cmd));			\ 								\ static void							\ func_name(addr, have_addr, count, modif)			\ 	db_expr_t addr;						\ 	boolean_t have_addr;					\ 	db_expr_t count;					\ 	char *modif;
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|esym
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
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
name|int
name|db_radix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|db_max_width
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|db_tab_stop_width
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|vm_map
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|cnpollc
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|db_check_interrupt
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|db_clear_watchpoints
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_addr_t
name|db_disasm
name|__P
argument_list|(
operator|(
name|db_addr_t
name|loc
operator|,
name|boolean_t
name|altfmt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* instruction disassembler */
end_comment

begin_decl_stmt
name|void
name|db_error
name|__P
argument_list|(
operator|(
name|char
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|db_expression
name|__P
argument_list|(
operator|(
name|db_expr_t
operator|*
name|valuep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|db_get_variable
name|__P
argument_list|(
operator|(
name|db_expr_t
operator|*
name|valuep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|db_iprintf
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vm_map
modifier|*
name|db_map_addr
name|__P
argument_list|(
operator|(
name|vm_offset_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean_t
name|db_map_current
name|__P
argument_list|(
operator|(
expr|struct
name|vm_map
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean_t
name|db_map_equal
name|__P
argument_list|(
operator|(
expr|struct
name|vm_map
operator|*
operator|,
expr|struct
name|vm_map
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|db_print_loc_and_inst
name|__P
argument_list|(
operator|(
name|db_addr_t
name|loc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|db_printf
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|db_read_bytes
name|__P
argument_list|(
operator|(
name|vm_offset_t
name|addr
operator|,
name|int
name|size
operator|,
name|char
operator|*
name|data
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* machine-dependent */
end_comment

begin_decl_stmt
name|int
name|db_readline
name|__P
argument_list|(
operator|(
name|char
operator|*
name|lstart
operator|,
name|int
name|lsize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|db_restart_at_pc
name|__P
argument_list|(
operator|(
name|boolean_t
name|watchpt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|db_set_watchpoints
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|db_skip_to_eol
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean_t
name|db_stop_at_pc
name|__P
argument_list|(
operator|(
name|boolean_t
operator|*
name|is_breakpoint
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|db_strcpy
value|strcpy
end_define

begin_decl_stmt
name|void
name|db_trap
name|__P
argument_list|(
operator|(
name|int
name|type
operator|,
name|int
name|code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|db_value_of_name
name|__P
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|db_expr_t
operator|*
name|valuep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|db_write_bytes
name|__P
argument_list|(
operator|(
name|vm_offset_t
name|addr
operator|,
name|int
name|size
operator|,
name|char
operator|*
name|data
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* machine-dependent */
end_comment

begin_decl_stmt
name|void
name|kdb_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kdbprintf
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|db_show_regs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_cmdfcn_t
name|db_single_step_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_cmdfcn_t
name|db_stack_trace_cmd
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

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|db_cmdfcn_t	db_help_cmd; db_cmdfcn_t	db_show_all_threads; db_cmdfcn_t	db_show_one_thread; db_cmdfcn_t	ipc_port_print; db_cmdfcn_t	vm_page_print;
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Command table.  */
end_comment

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
name|command
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

