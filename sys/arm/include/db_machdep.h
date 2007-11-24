begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Mach Operating System  * Copyright (c) 1991,1990 Carnegie Mellon University  * All Rights Reserved.  *  * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  *  *	from: FreeBSD: src/sys/i386/include/db_machdep.h,v 1.16 1999/10/04  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_DB_MACHDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_DB_MACHDEP_H_
end_define

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/trap.h>
end_include

begin_include
include|#
directive|include
file|<machine/armreg.h>
end_include

begin_define
define|#
directive|define
name|T_BREAKPOINT
value|(1)
end_define

begin_typedef
typedef|typedef
name|vm_offset_t
name|db_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|db_expr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PC_REGS
parameter_list|()
value|((db_addr_t)kdb_thrctx->un_32.pcb32_pc)
end_define

begin_define
define|#
directive|define
name|BKPT_INST
value|(KERNEL_BREAKPOINT)
end_define

begin_define
define|#
directive|define
name|BKPT_SIZE
value|(INSN_SIZE)
end_define

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
name|BKPT_SKIP
value|do {							\ 	kdb_frame->tf_pc += BKPT_SIZE; \ } while (0)
end_define

begin_define
define|#
directive|define
name|SOFTWARE_SSTEP
value|1
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
value|(type == T_BREAKPOINT)
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
value|(0)
end_define

begin_define
define|#
directive|define
name|inst_trap_return
parameter_list|(
name|ins
parameter_list|)
value|(0)
end_define

begin_comment
comment|/* ldmxx reg, {..., pc} 					    01800000  stack mode 					    000f0000  register 					    0000ffff  register list */
end_comment

begin_comment
comment|/* mov pc, reg 					    0000000f  register */
end_comment

begin_define
define|#
directive|define
name|inst_return
parameter_list|(
name|ins
parameter_list|)
value|(((ins)& 0x0e108000) == 0x08108000 || \ 				 ((ins)& 0x0ff0fff0) == 0x01a0f000 ||	\ 				 ((ins)& 0x0ffffff0) == 0x012fff10)
end_define

begin_comment
comment|/* bx */
end_comment

begin_comment
comment|/* bl ... 					    00ffffff  offset>>2 */
end_comment

begin_define
define|#
directive|define
name|inst_call
parameter_list|(
name|ins
parameter_list|)
value|(((ins)& 0x0f000000) == 0x0b000000)
end_define

begin_comment
comment|/* b ... 					    00ffffff  offset>>2 */
end_comment

begin_comment
comment|/* ldr pc, [pc, reg, lsl #2] 					    0000000f  register */
end_comment

begin_define
define|#
directive|define
name|inst_branch
parameter_list|(
name|ins
parameter_list|)
value|(((ins)& 0x0f000000) == 0x0a000000 || \ 				 ((ins)& 0x0fdffff0) == 0x079ff100)
end_define

begin_define
define|#
directive|define
name|inst_load
parameter_list|(
name|ins
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|inst_store
parameter_list|(
name|ins
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|next_instr_address
parameter_list|(
name|pc
parameter_list|,
name|bd
parameter_list|)
value|((bd) ? (pc) : ((pc) + INSN_SIZE))
end_define

begin_define
define|#
directive|define
name|DB_SMALL_VALUE_MAX
value|(0x7fffffff)
end_define

begin_define
define|#
directive|define
name|DB_SMALL_VALUE_MIN
value|(-0x40001)
end_define

begin_define
define|#
directive|define
name|DB_ELFSIZE
value|32
end_define

begin_function_decl
name|int
name|db_validate_address
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|branch_taken
parameter_list|(
name|u_int
name|insn
parameter_list|,
name|u_int
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__ARMEB__
end_ifdef

begin_define
define|#
directive|define
name|BYTE_MSF
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_DB_MACHDEP_H_ */
end_comment

end_unit

