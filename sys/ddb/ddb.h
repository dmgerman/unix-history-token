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
name|__h_ddb_ddb
end_ifndef

begin_define
define|#
directive|define
name|__h_ddb_ddb
value|1
end_define

begin_include
include|#
directive|include
file|<machine/db_machdep.h>
end_include

begin_comment
comment|/* type definitions */
end_comment

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_comment
comment|/*  * Global variables...  */
end_comment

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

begin_comment
comment|/*  * Functions...  */
end_comment

begin_function_decl
specifier|extern
name|void
name|db_read_bytes
parameter_list|(
name|vm_offset_t
name|addr
parameter_list|,
specifier|register
name|int
name|size
parameter_list|,
specifier|register
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
specifier|extern
name|void
name|db_write_bytes
parameter_list|(
name|vm_offset_t
name|addr
parameter_list|,
specifier|register
name|int
name|size
parameter_list|,
specifier|register
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* machine-dependent */
end_comment

begin_struct_decl
struct_decl|struct
name|vm_map
struct_decl|;
end_struct_decl

begin_comment
comment|/* forward declaration */
end_comment

begin_function_decl
specifier|extern
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
specifier|extern
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
specifier|extern
name|struct
name|vm_map
modifier|*
name|db_map_addr
parameter_list|(
name|vm_offset_t
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
specifier|extern
name|int
name|db_expression
parameter_list|(
name|db_expr_t
modifier|*
name|valuep
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
name|db_cmd_fcn
parameter_list|(
name|db_expr_t
parameter_list|,
name|int
parameter_list|,
name|db_expr_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|db_cmd_fcn
name|db_listbreak_cmd
decl_stmt|,
name|db_listwatch_cmd
decl_stmt|,
name|db_show_regs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|db_cmd_fcn
name|db_print_cmd
decl_stmt|,
name|db_examine_cmd
decl_stmt|,
name|db_set_cmd
decl_stmt|,
name|db_search_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|db_cmd_fcn
name|db_write_cmd
decl_stmt|,
name|db_delete_cmd
decl_stmt|,
name|db_breakpoint_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|db_cmd_fcn
name|db_deletewatch_cmd
decl_stmt|,
name|db_watchpoint_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|db_cmd_fcn
name|db_single_step_cmd
decl_stmt|,
name|db_trace_until_call_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|db_cmd_fcn
name|db_trace_until_matching_cmd
decl_stmt|,
name|db_continue_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|db_cmd_fcn
name|db_stack_trace_cmd
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
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
specifier|extern
name|int
name|db_value_of_name
parameter_list|(
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
specifier|extern
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
specifier|extern
name|void
name|db_putchar
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|db_error
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
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
specifier|extern
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
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|db_check_interrupt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|db_print_loc_and_inst
parameter_list|(
name|db_addr_t
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|db_clear_watchpoints
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|db_set_watchpoints
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|db_restart_at_pc
parameter_list|(
name|boolean_t
name|watchpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|boolean_t
name|db_stop_at_pc
parameter_list|(
name|boolean_t
modifier|*
name|is_breakpoint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|db_skip_to_eol
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|db_single_step
parameter_list|(
name|db_regs_t
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|db_trap
parameter_list|(
name|int
name|type
parameter_list|,
name|int
name|code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cnpollc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|kdb_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|kdbprinttrap
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __h_ddb_ddb */
end_comment

end_unit

