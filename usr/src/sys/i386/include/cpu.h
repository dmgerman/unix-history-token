begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * %sccs.include.redist.c%  *  *	@(#)cpu.h	8.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Definitions unique to i386 cpu support.  */
end_comment

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/segments.h>
end_include

begin_comment
comment|/*  * definitions of cpu-dependent requirements  * referenced in generic code  */
end_comment

begin_undef
undef|#
directive|undef
name|COPY_SIGCODE
end_undef

begin_comment
comment|/* don't copy sigcode above user stack in exec */
end_comment

begin_define
define|#
directive|define
name|cpu_exec
parameter_list|(
name|p
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|cpu_swapin
parameter_list|(
name|p
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|cpu_setstack
parameter_list|(
name|p
parameter_list|,
name|ap
parameter_list|)
value|(p)->p_md.md_regs[SP] = ap
end_define

begin_define
define|#
directive|define
name|cpu_set_init_frame
parameter_list|(
name|p
parameter_list|,
name|fp
parameter_list|)
value|(p)->p_md.md_regs = fp
end_define

begin_comment
comment|/*  * Arguments to hardclock, softclock and gatherstats  * encapsulate the previous machine state in an opaque  * clockframe; for now, use generic intrframe.  */
end_comment

begin_struct
struct|struct
name|clockframe
block|{
name|struct
name|intrframe
name|cf_if
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CLKF_USERMODE
parameter_list|(
name|framep
parameter_list|)
value|(ISPL((framep)->cf_if.if_cs) == SEL_UPL)
end_define

begin_define
define|#
directive|define
name|CLKF_BASEPRI
parameter_list|(
name|framep
parameter_list|)
value|((framep)->cf_if.if_ppl == 0)
end_define

begin_define
define|#
directive|define
name|CLKF_PC
parameter_list|(
name|framep
parameter_list|)
value|((framep)->cf_if.if_eip)
end_define

begin_define
define|#
directive|define
name|resettodr
parameter_list|()
end_define

begin_comment
comment|/* no todr to set */
end_comment

begin_comment
comment|/*  * Preempt the current process if in interrupt from user mode,  * or after the current trap/syscall if in system mode.  */
end_comment

begin_define
define|#
directive|define
name|need_resched
parameter_list|()
value|{ want_resched++; aston(); }
end_define

begin_comment
comment|/*  * Give a profiling tick to the current process from the softclock  * interrupt.  On tahoe, request an ast to send us through trap(),  * marking the proc as needing a profiling tick.  */
end_comment

begin_define
define|#
directive|define
name|profile_tick
parameter_list|(
name|p
parameter_list|,
name|framep
parameter_list|)
value|{ (p)->p_flag |= P_OWEUPC; aston(); }
end_define

begin_comment
comment|/*  * Notify the current process (p) that it has a signal pending,  * process as soon as possible.  */
end_comment

begin_define
define|#
directive|define
name|signotify
parameter_list|(
name|p
parameter_list|)
value|aston()
end_define

begin_define
define|#
directive|define
name|aston
parameter_list|()
value|(astpending++)
end_define

begin_decl_stmt
name|int
name|astpending
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* need to trap before returning to user mode */
end_comment

begin_decl_stmt
name|int
name|want_resched
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* resched() was called */
end_comment

begin_comment
comment|/*  * Kinds of processor  */
end_comment

begin_define
define|#
directive|define
name|CPU_386SX
value|0
end_define

begin_define
define|#
directive|define
name|CPU_386
value|1
end_define

begin_define
define|#
directive|define
name|CPU_486SX
value|2
end_define

begin_define
define|#
directive|define
name|CPU_486
value|3
end_define

begin_define
define|#
directive|define
name|CPU_586
value|4
end_define

begin_comment
comment|/*  * CTL_MACHDEP definitions.  */
end_comment

begin_define
define|#
directive|define
name|CPU_CONSDEV
value|1
end_define

begin_comment
comment|/* dev_t: console terminal device */
end_comment

begin_define
define|#
directive|define
name|CPU_MAXID
value|2
end_define

begin_comment
comment|/* number of valid machdep ids */
end_comment

begin_define
define|#
directive|define
name|CTL_MACHDEP_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "console_device", CTLTYPE_STRUCT }, \ }
end_define

end_unit

