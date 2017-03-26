begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Mach Operating System  * Copyright (c) 1991,1990 Carnegie Mellon University  * All Rights Reserved.  *  * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  *  * $FreeBSD$  */
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

begin_define
define|#
directive|define
name|PC_REGS
parameter_list|()
value|((db_addr_t)kdb_thrctx->pcb_rip)
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
name|BKPT_SKIP
define|\
value|do {						\ 	kdb_frame->tf_rip += 1;			\ 	kdb_thrctx->pcb_rip += 1;		\ } while(0)
end_define

begin_define
define|#
directive|define
name|FIXUP_PC_AFTER_BREAK
define|\
value|do {						\ 	kdb_frame->tf_rip -= 1;			\ 	kdb_thrctx->pcb_rip -= 1;		\ } while(0);
end_define

begin_define
define|#
directive|define
name|db_clear_single_step
value|kdb_cpu_clear_singlestep
end_define

begin_define
define|#
directive|define
name|db_set_single_step
value|kdb_cpu_set_singlestep
end_define

begin_comment
comment|/*  * The debug exception type is copied from %dr6 to 'code' and used to  * disambiguate single step traps.  Watchpoints have no special support.  * Our hardware breakpoints are not well integrated with ddb and are too  * different from watchpoints.  ddb treats them as unknown traps with  * unknown addresses and doesn't turn them off while it is running.  */
end_comment

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

begin_define
define|#
directive|define
name|IS_SSTEP_TRAP
parameter_list|(
name|type
parameter_list|,
name|code
parameter_list|)
value|((type) == T_TRCTRAP&& (code)& 0x4000)
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
name|i_calli
parameter_list|(
name|ins
parameter_list|)
value|(((ins)&0xff) == I_CALLI&& ((ins)&0x3800) == 0x1000)
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
name|i_rex
parameter_list|(
name|ins
parameter_list|)
value|(((ins)& 0xff) == 0x41 || ((ins)& 0xff) == 0x43)
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
value|(((ins)&0xff) == I_CALL || i_calli(ins) || \ 				 (i_calli((ins)>> 8)&& i_rex(ins)))
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_DB_MACHDEP_H_ */
end_comment

end_unit

