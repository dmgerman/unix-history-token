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
file|"opt_simos.h"
end_include

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
value|((db_addr_t)(regs)->tf_regs[FRAME_PC])
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SIMOS
end_ifdef

begin_define
define|#
directive|define
name|BKPT_INST
value|0x000000aa
end_define

begin_comment
comment|/* gentrap instruction */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BKPT_INST
value|0x00000080
end_define

begin_comment
comment|/* breakpoint instruction */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BKPT_SIZE
value|(4)
end_define

begin_comment
comment|/* size of breakpoint inst */
end_comment

begin_define
define|#
directive|define
name|BKPT_SET
parameter_list|(
name|inst
parameter_list|)
value|(BKPT_INST)
end_define

begin_define
define|#
directive|define
name|FIXUP_PC_AFTER_BREAK
define|\
value|(ddb_regs.tf_regs[FRAME_PC] -= BKPT_SIZE);
end_define

begin_define
define|#
directive|define
name|SOFTWARE_SSTEP
value|1
end_define

begin_comment
comment|/* no hardware support */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SIMOS
end_ifdef

begin_define
define|#
directive|define
name|IS_BREAKPOINT_TRAP
parameter_list|(
name|type
parameter_list|,
name|code
parameter_list|)
value|((type) == ALPHA_KENTRY_IF&& \ 					 (code) == ALPHA_IF_CODE_GENTRAP)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IS_BREAKPOINT_TRAP
parameter_list|(
name|type
parameter_list|,
name|code
parameter_list|)
value|((type) == ALPHA_KENTRY_IF&& \ 					 (code) == ALPHA_IF_CODE_BPT)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/*  * Functions needed for software single-stepping.  */
end_comment

begin_decl_stmt
name|boolean_t
name|db_inst_trap_return
name|__P
argument_list|(
operator|(
name|int
name|inst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean_t
name|db_inst_return
name|__P
argument_list|(
operator|(
name|int
name|inst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean_t
name|db_inst_call
name|__P
argument_list|(
operator|(
name|int
name|inst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean_t
name|db_inst_branch
name|__P
argument_list|(
operator|(
name|int
name|inst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean_t
name|db_inst_load
name|__P
argument_list|(
operator|(
name|int
name|inst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean_t
name|db_inst_store
name|__P
argument_list|(
operator|(
name|int
name|inst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean_t
name|db_inst_unconditional_flow_transfer
name|__P
argument_list|(
operator|(
name|int
name|inst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|db_addr_t
name|db_branch_taken
name|__P
argument_list|(
operator|(
name|int
name|inst
operator|,
name|db_addr_t
name|pc
operator|,
name|db_regs_t
operator|*
name|regs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|inst_trap_return
parameter_list|(
name|ins
parameter_list|)
value|db_inst_trap_return(ins)
end_define

begin_define
define|#
directive|define
name|inst_return
parameter_list|(
name|ins
parameter_list|)
value|db_inst_return(ins)
end_define

begin_define
define|#
directive|define
name|inst_call
parameter_list|(
name|ins
parameter_list|)
value|db_inst_call(ins)
end_define

begin_define
define|#
directive|define
name|inst_branch
parameter_list|(
name|ins
parameter_list|)
value|db_inst_branch(ins)
end_define

begin_define
define|#
directive|define
name|inst_load
parameter_list|(
name|ins
parameter_list|)
value|db_inst_load(ins)
end_define

begin_define
define|#
directive|define
name|inst_store
parameter_list|(
name|ins
parameter_list|)
value|db_inst_store(ins)
end_define

begin_define
define|#
directive|define
name|inst_unconditional_flow_transfer
parameter_list|(
name|ins
parameter_list|)
define|\
value|db_inst_unconditional_flow_transfer(ins)
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
define|\
value|db_branch_taken((ins), (pc), (regs))
end_define

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

begin_decl_stmt
name|u_long
name|db_register_value
name|__P
argument_list|(
operator|(
name|db_regs_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kdb_trap
name|__P
argument_list|(
operator|(
name|unsigned
name|long
operator|,
name|unsigned
name|long
operator|,
name|unsigned
name|long
operator|,
name|unsigned
name|long
operator|,
expr|struct
name|trapframe
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

