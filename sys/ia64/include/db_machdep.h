begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: db_machdep.h,v 1.6 1997/09/06 02:02:25 thorpej Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALPHA_DB_MACHDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALPHA_DB_MACHDEP_H_
end_define

begin_comment
comment|/*  * Machine-dependent defines for new kernel debugger.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_define
define|#
directive|define
name|DB_NO_AOUT
end_define

begin_struct_decl
struct_decl|struct
name|ia64_bundle
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|vm_offset_t
name|db_addr_t
typedef|;
end_typedef

begin_comment
comment|/* address - unsigned */
end_comment

begin_typedef
typedef|typedef
name|long
name|db_expr_t
typedef|;
end_typedef

begin_comment
comment|/* expression - signed */
end_comment

begin_typedef
typedef|typedef
name|struct
name|trapframe
name|db_regs_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|db_regs_t
name|ddb_regs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* register state */
end_comment

begin_define
define|#
directive|define
name|DDB_REGS
value|(&ddb_regs)
end_define

begin_define
define|#
directive|define
name|PC_REGS
parameter_list|(
name|regs
parameter_list|)
value|((db_addr_t)(regs)->tf_cr_iip \ 			 + (((regs)->tf_cr_ipsr>> 41)& 3))
end_define

begin_define
define|#
directive|define
name|BKPT_WRITE
parameter_list|(
name|addr
parameter_list|,
name|storage
parameter_list|)
value|db_write_breakpoint(addr, storage)
end_define

begin_define
define|#
directive|define
name|BKPT_CLEAR
parameter_list|(
name|addr
parameter_list|,
name|storage
parameter_list|)
value|db_clear_breakpoint(addr, storage)
end_define

begin_define
define|#
directive|define
name|BKPT_INST_TYPE
value|u_int64_t
end_define

begin_define
define|#
directive|define
name|BKPT_SKIP
value|db_skip_breakpoint()
end_define

begin_define
define|#
directive|define
name|db_clear_single_step
parameter_list|(
name|regs
parameter_list|)
value|ddb_regs.tf_cr_ipsr&= ~IA64_PSR_SS
end_define

begin_define
define|#
directive|define
name|db_set_single_step
parameter_list|(
name|regs
parameter_list|)
value|ddb_regs.tf_cr_ipsr |= IA64_PSR_SS
end_define

begin_define
define|#
directive|define
name|IS_BREAKPOINT_TRAP
parameter_list|(
name|type
parameter_list|,
name|code
parameter_list|)
value|(type == IA64_VEC_BREAK)
end_define

begin_define
define|#
directive|define
name|IS_WATCHPOINT_TRAP
parameter_list|(
name|type
parameter_list|,
name|code
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|inst_trap_return
parameter_list|(
name|ins
parameter_list|)
value|(ins& 0)
end_define

begin_define
define|#
directive|define
name|inst_return
parameter_list|(
name|ins
parameter_list|)
value|(ins& 0)
end_define

begin_define
define|#
directive|define
name|inst_call
parameter_list|(
name|ins
parameter_list|)
value|(ins& 0)
end_define

begin_define
define|#
directive|define
name|inst_branch
parameter_list|(
name|ins
parameter_list|)
value|(ins& 0)
end_define

begin_define
define|#
directive|define
name|inst_load
parameter_list|(
name|ins
parameter_list|)
value|(ins& 0)
end_define

begin_define
define|#
directive|define
name|inst_store
parameter_list|(
name|ins
parameter_list|)
value|(ins& 0)
end_define

begin_define
define|#
directive|define
name|inst_unconditional_flow_transfer
parameter_list|(
name|ins
parameter_list|)
value|(ins& 0)
end_define

begin_define
define|#
directive|define
name|branch_taken
parameter_list|(
name|ins
parameter_list|,
name|pc
parameter_list|,
name|regs
parameter_list|)
value|pc
end_define

begin_comment
comment|/*  * Functions needed for software single-stepping.  */
end_comment

begin_comment
comment|/* No delay slots on Alpha. */
end_comment

begin_define
define|#
directive|define
name|next_instr_address
parameter_list|(
name|v
parameter_list|,
name|b
parameter_list|)
value|((db_addr_t) ((b) ? (v) : ((v) + 4)))
end_define

begin_function_decl
name|u_long
name|db_register_value
parameter_list|(
name|db_regs_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kdb_trap
parameter_list|(
name|int
name|vector
parameter_list|,
name|struct
name|trapframe
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
modifier|*
name|db_rse_current_frame
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
modifier|*
name|db_rse_previous_frame
parameter_list|(
name|u_int64_t
modifier|*
name|bsp
parameter_list|,
name|int
name|sof
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
modifier|*
name|db_rse_register_address
parameter_list|(
name|u_int64_t
modifier|*
name|bsp
parameter_list|,
name|int
name|regno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_read_bundle
parameter_list|(
name|db_addr_t
name|addr
parameter_list|,
name|struct
name|ia64_bundle
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_write_bundle
parameter_list|(
name|db_addr_t
name|addr
parameter_list|,
name|struct
name|ia64_bundle
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_write_breakpoint
parameter_list|(
name|db_addr_t
name|addr
parameter_list|,
name|u_int64_t
modifier|*
name|storage
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_clear_breakpoint
parameter_list|(
name|db_addr_t
name|addr
parameter_list|,
name|u_int64_t
modifier|*
name|storage
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_skip_breakpoint
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Pretty arbitrary  */
end_comment

begin_define
define|#
directive|define
name|DB_SMALL_VALUE_MAX
value|0x7fffffff
end_define

begin_define
define|#
directive|define
name|DB_SMALL_VALUE_MIN
value|(-0x400001)
end_define

begin_comment
comment|/*  * We define some of our own commands.  */
end_comment

begin_define
define|#
directive|define
name|DB_MACHINE_COMMANDS
end_define

begin_comment
comment|/*  * We use Elf64 symbols in DDB.  */
end_comment

begin_define
define|#
directive|define
name|DB_ELFSIZE
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ALPHA_DB_MACHDEP_H_ */
end_comment

end_unit

