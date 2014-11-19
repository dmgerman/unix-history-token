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

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_DECL
end_ifdef

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_debug_ddb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

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
file|<sys/queue.h>
end_include

begin_comment
comment|/* LIST_* */
end_comment

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_comment
comment|/* SYSINIT */
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
name|DB_MAXLINE
end_ifndef

begin_define
define|#
directive|define
name|DB_MAXLINE
value|120
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DB_MAXSCRIPTS
end_ifndef

begin_define
define|#
directive|define
name|DB_MAXSCRIPTS
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DB_MAXSCRIPTNAME
end_ifndef

begin_define
define|#
directive|define
name|DB_MAXSCRIPTNAME
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DB_MAXSCRIPTLEN
end_ifndef

begin_define
define|#
directive|define
name|DB_MAXSCRIPTLEN
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DB_MAXSCRIPTRECURSION
end_ifndef

begin_define
define|#
directive|define
name|DB_MAXSCRIPTRECURSION
value|3
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

begin_comment
comment|/*  * Extern variables to set the address and size of the symtab and strtab.  * Most users should use db_fetch_symtab in order to set them from the  * boot loader provided values.  */
end_comment

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|ksymtab
decl_stmt|,
name|kstrtab
decl_stmt|,
name|ksymtab_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * There are three "command tables":  * - One for simple commands; a list of these is displayed  *   by typing 'help' at the debugger prompt.  * - One for sub-commands of 'show'; to see this type 'show'  *   without any arguments.  * - The last one for sub-commands of 'show all'; type 'show all'  *   without any argument to get a list.  */
end_comment

begin_struct_decl
struct_decl|struct
name|command
struct_decl|;
end_struct_decl

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|command_table
argument_list|,
name|command
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|command_table
name|db_cmd_table
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|command_table
name|db_show_table
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|command_table
name|db_show_all_table
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Type signature for a function implementing a ddb command.  */
end_comment

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

begin_comment
comment|/*  * Command table entry.  */
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
name|command_table
modifier|*
name|more
decl_stmt|;
comment|/* another level of command */
name|LIST_ENTRY
argument_list|(
argument|command
argument_list|)
name|next
expr_stmt|;
comment|/* next entry in the command table */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Arrange for the specified ddb command to be defined and  * bound to the specified function.  Commands can be defined  * in modules in which case they will be available only when  * the module is loaded.  */
end_comment

begin_define
define|#
directive|define
name|_DB_SET
parameter_list|(
name|_suffix
parameter_list|,
name|_name
parameter_list|,
name|_func
parameter_list|,
name|list
parameter_list|,
name|_flag
parameter_list|,
name|_more
parameter_list|)
define|\
value|static struct command __CONCAT(_name,_suffix) = {		\ 	.name	= __STRING(_name),				\ 	.fcn	= _func,					\ 	.flag	= _flag,					\ 	.more	= _more						\ };								\ static void __CONCAT(__CONCAT(_name,_suffix),_add)(void *arg __unused) \     { db_command_register(&list,&__CONCAT(_name,_suffix)); }	\ SYSINIT(__CONCAT(_name,_suffix), SI_SUB_KLD, SI_ORDER_ANY,	\     __CONCAT(__CONCAT(_name,_suffix),_add), NULL);		\ static void __CONCAT(__CONCAT(_name,_suffix),_del)(void *arg __unused) \     { db_command_unregister(&list,&__CONCAT(_name,_suffix)); }	\ SYSUNINIT(__CONCAT(_name,_suffix), SI_SUB_KLD, SI_ORDER_ANY,	\     __CONCAT(__CONCAT(_name,_suffix),_del), NULL);
end_define

begin_comment
comment|/*  * Like _DB_SET but also create the function declaration which  * must be followed immediately by the body; e.g.  *   _DB_FUNC(_cmd, panic, db_panic, db_cmd_table, 0, NULL)  *   {  *	...panic implementation...  *   }  *  * This macro is mostly used to define commands placed in one of  * the ddb command tables; see DB_COMMAND, etc. below.  */
end_comment

begin_define
define|#
directive|define
name|_DB_FUNC
parameter_list|(
name|_suffix
parameter_list|,
name|_name
parameter_list|,
name|_func
parameter_list|,
name|list
parameter_list|,
name|_flag
parameter_list|,
name|_more
parameter_list|)
define|\
value|static db_cmdfcn_t _func;					\ _DB_SET(_suffix, _name, _func, list, _flag, _more);		\ static void							\ _func(db_expr_t addr, boolean_t have_addr, db_expr_t count, char *modif)
end_define

begin_comment
comment|/* common idom provided for backwards compatibility */
end_comment

begin_define
define|#
directive|define
name|DB_FUNC
parameter_list|(
name|_name
parameter_list|,
name|_func
parameter_list|,
name|list
parameter_list|,
name|_flag
parameter_list|,
name|_more
parameter_list|)
define|\
value|_DB_FUNC(_cmd, _name, _func, list, _flag, _more)
end_define

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
value|_DB_FUNC(_cmd, cmd_name, func_name, db_cmd_table, 0, NULL)
end_define

begin_define
define|#
directive|define
name|DB_ALIAS
parameter_list|(
name|alias_name
parameter_list|,
name|func_name
parameter_list|)
define|\
value|_DB_SET(_cmd, alias_name, func_name, db_cmd_table, 0, NULL)
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
value|_DB_FUNC(_show, cmd_name, func_name, db_show_table, 0, NULL)
end_define

begin_define
define|#
directive|define
name|DB_SHOW_ALIAS
parameter_list|(
name|alias_name
parameter_list|,
name|func_name
parameter_list|)
define|\
value|_DB_SET(_show, alias_name, func_name, db_show_table, 0, NULL)
end_define

begin_define
define|#
directive|define
name|DB_SHOW_ALL_COMMAND
parameter_list|(
name|cmd_name
parameter_list|,
name|func_name
parameter_list|)
define|\
value|_DB_FUNC(_show_all, cmd_name, func_name, db_show_all_table, 0, NULL)
end_define

begin_define
define|#
directive|define
name|DB_SHOW_ALL_ALIAS
parameter_list|(
name|alias_name
parameter_list|,
name|func_name
parameter_list|)
define|\
value|_DB_SET(_show_all, alias_name, func_name, db_show_all_table, 0, NULL)
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
specifier|volatile
name|int
name|db_pager_quit
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
name|proc
modifier|*
name|db_lookup_proc
parameter_list|(
name|db_expr_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|thread
modifier|*
name|db_lookup_thread
parameter_list|(
name|db_expr_t
name|addr
parameter_list|,
name|boolean_t
name|check_pid
parameter_list|)
function_decl|;
end_function_decl

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
name|int
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
name|db_value_of_name_pcpu
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
name|db_value_of_name_vnet
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

begin_function_decl
name|void
name|db_command_register
parameter_list|(
name|struct
name|command_table
modifier|*
parameter_list|,
name|struct
name|command
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_command_unregister
parameter_list|(
name|struct
name|command_table
modifier|*
parameter_list|,
name|struct
name|command
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|db_fetch_ksymtab
parameter_list|(
name|vm_offset_t
name|ksym_start
parameter_list|,
name|vm_offset_t
name|ksym_end
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
name|db_capture_cmd
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
name|db_findstack_cmd
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
name|db_scripts_cmd
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
name|db_run_cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_cmdfcn_t
name|db_script_cmd
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
name|db_textdump_cmd
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
name|db_unscript_cmd
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

begin_comment
comment|/*  * Interface between DDB and the DDB output capture facility.  */
end_comment

begin_struct_decl
struct_decl|struct
name|dumperinfo
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|db_capture_dump
parameter_list|(
name|struct
name|dumperinfo
modifier|*
name|di
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_capture_enterpager
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_capture_exitpager
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_capture_write
parameter_list|(
name|char
modifier|*
name|buffer
parameter_list|,
name|u_int
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_capture_writech
parameter_list|(
name|char
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Interface between DDB  and the script facility.  */
end_comment

begin_function_decl
name|void
name|db_script_kdbenter
parameter_list|(
specifier|const
name|char
modifier|*
name|eventname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* KDB enter event. */
end_comment

begin_comment
comment|/*  * Interface between DDB and the textdump facility.  *  * Text dump blocks are of a fixed size; textdump_block_buffer is a  * statically allocated buffer that code interacting with textdumps can use  * to prepare and hold a pending block in when calling writenextblock().  */
end_comment

begin_define
define|#
directive|define
name|TEXTDUMP_BLOCKSIZE
value|512
end_define

begin_decl_stmt
specifier|extern
name|char
name|textdump_block_buffer
index|[
name|TEXTDUMP_BLOCKSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|textdump_mkustar
parameter_list|(
name|char
modifier|*
name|block_buffer
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|u_int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|textdump_restoreoff
parameter_list|(
name|off_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|textdump_saveoff
parameter_list|(
name|off_t
modifier|*
name|offsetp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|textdump_writenextblock
parameter_list|(
name|struct
name|dumperinfo
modifier|*
name|di
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Interface between the kernel and textdumps.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|textdump_pending
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Call textdump_dumpsys() instead. */
end_comment

begin_function_decl
name|void
name|textdump_dumpsys
parameter_list|(
name|struct
name|dumperinfo
modifier|*
name|di
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DDB_DDB_H_ */
end_comment

end_unit

