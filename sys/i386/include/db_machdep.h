begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Mach Operating System  * Copyright (c) 1991,1990 Carnegie Mellon University  * All Rights Reserved.  *  * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  *  * $FreeBSD$  */
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
file|<machine/psl.h>
end_include

begin_include
include|#
directive|include
file|<machine/trap.h>
end_include

begin_define
define|#
directive|define
name|i386_saved_state
value|trapframe
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
name|int
name|db_expr_t
typedef|;
end_typedef

begin_comment
comment|/* expression - signed */
end_comment

begin_typedef
typedef|typedef
name|struct
name|i386_saved_state
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
value|((db_addr_t)(regs)->tf_eip)
end_define

begin_define
define|#
directive|define
name|BKPT_INST
value|0xcc
end_define

begin_comment
comment|/* breakpoint instruction */
end_comment

begin_define
define|#
directive|define
name|BKPT_SIZE
value|(1)
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
value|ddb_regs.tf_eip -= 1;
end_define

begin_define
define|#
directive|define
name|db_clear_single_step
parameter_list|(
name|regs
parameter_list|)
value|((regs)->tf_eflags&= ~PSL_T)
end_define

begin_define
define|#
directive|define
name|db_set_single_step
parameter_list|(
name|regs
parameter_list|)
value|((regs)->tf_eflags |=  PSL_T)
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
value|((type) == T_BPTFLT)
end_define

begin_comment
comment|/*  * Watchpoints are not supported.  The debug exception type is in %dr6  * and not yet in the args to this macro.  */
end_comment

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
name|I_CALL
value|0xe8
end_define

begin_define
define|#
directive|define
name|I_CALLI
value|0xff
end_define

begin_define
define|#
directive|define
name|I_RET
value|0xc3
end_define

begin_define
define|#
directive|define
name|I_IRET
value|0xcf
end_define

begin_define
define|#
directive|define
name|inst_trap_return
parameter_list|(
name|ins
parameter_list|)
value|(((ins)&0xff) == I_IRET)
end_define

begin_define
define|#
directive|define
name|inst_return
parameter_list|(
name|ins
parameter_list|)
value|(((ins)&0xff) == I_RET)
end_define

begin_define
define|#
directive|define
name|inst_call
parameter_list|(
name|ins
parameter_list|)
value|(((ins)&0xff) == I_CALL || \ 				 (((ins)&0xff) == I_CALLI&& \ 				  ((ins)&0x3800) == 0x1000))
end_define

begin_define
define|#
directive|define
name|inst_load
parameter_list|(
name|ins
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|inst_store
parameter_list|(
name|ins
parameter_list|)
value|0
end_define

begin_comment
comment|/*  * There no interesting addresses below _kstack = 0xefbfe000.  There  * are small absolute values for GUPROF, but we don't want to see them.  * Treat "negative" addresses below _kstack as non-small to allow for  * future reductions of _kstack and to avoid sign extension problems.  *  * There is one interesting symbol above -db_maxoff = 0xffff0000,  * namely _APTD = 0xfffff000.  Accepting this would mess up the  * printing of small negative offsets.  The next largest symbol is  * _APTmap = 0xffc00000.  Accepting this is OK (unless db_maxoff is  * set to>= 0x400000 - (max stack offset)).  */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_DB_MACHDEP_H_ */
end_comment

end_unit

