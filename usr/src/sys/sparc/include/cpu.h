begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)cpu.h	8.4 (Berkeley) %G%  *  * from: $Header: cpu.h,v 1.12 93/05/25 10:36:34 torek Exp $ (LBL)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_CPU_H_
end_define

begin_comment
comment|/*  * CTL_MACHDEP definitinos.  */
end_comment

begin_define
define|#
directive|define
name|CPU_MAXID
value|1
end_define

begin_comment
comment|/* no valid machdep ids */
end_comment

begin_define
define|#
directive|define
name|CTL_MACHDEP_NAMES
value|{ \ 	{ 0, 0 }, \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Exported definitions unique to SPARC cpu support.  */
end_comment

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_include
include|#
directive|include
file|<sparc/sparc/intreg.h>
end_include

begin_comment
comment|/*  * definitions of cpu-dependent requirements  * referenced in generic code  */
end_comment

begin_define
define|#
directive|define
name|COPY_SIGCODE
end_define

begin_comment
comment|/* copy sigcode above user stack in exec */
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
name|cpu_wait
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
value|((p)->p_md.md_tf->tf_out[6] = (ap) - 64)
end_define

begin_comment
comment|/*  * See syscall() for an explanation of the following.  Note that the  * locore bootstrap code follows the syscall stack protocol.  The  * framep argument is unused.  */
end_comment

begin_define
define|#
directive|define
name|cpu_set_init_frame
parameter_list|(
name|p
parameter_list|,
name|fp
parameter_list|)
define|\
value|(p)->p_md.md_tf = (struct trapframe *) \ 	    ((caddr_t)(p)->p_addr + UPAGES * NBPG - sizeof(struct trapframe))
end_define

begin_comment
comment|/*  * Arguments to hardclock, softclock and gatherstats encapsulate the  * previous machine state in an opaque clockframe.  The ipl is here  * as well for strayintr (see locore.s:interrupt and intr.c:strayintr).  * Note that CLKF_INTR is valid only if CLKF_USERMODE is false.  */
end_comment

begin_struct
struct|struct
name|clockframe
block|{
name|u_int
name|psr
decl_stmt|;
comment|/* psr before interrupt, excluding PSR_ET */
name|u_int
name|pc
decl_stmt|;
comment|/* pc at interrupt */
name|u_int
name|npc
decl_stmt|;
comment|/* npc at interrupt */
name|u_int
name|ipl
decl_stmt|;
comment|/* actual interrupt priority level */
name|u_int
name|fp
decl_stmt|;
comment|/* %fp at interrupt */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|eintstack
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CLKF_USERMODE
parameter_list|(
name|framep
parameter_list|)
value|(((framep)->psr& PSR_PS) == 0)
end_define

begin_define
define|#
directive|define
name|CLKF_BASEPRI
parameter_list|(
name|framep
parameter_list|)
value|(((framep)->psr& PSR_PIL) == 0)
end_define

begin_define
define|#
directive|define
name|CLKF_PC
parameter_list|(
name|framep
parameter_list|)
value|((framep)->pc)
end_define

begin_define
define|#
directive|define
name|CLKF_INTR
parameter_list|(
name|framep
parameter_list|)
value|((framep)->fp< (u_int)eintstack)
end_define

begin_comment
comment|/*  * Software interrupt request `register'.  */
end_comment

begin_union
union|union
name|sir
block|{
name|int
name|sir_any
decl_stmt|;
name|char
name|sir_which
index|[
literal|4
index|]
decl_stmt|;
block|}
name|sir
union|;
end_union

begin_define
define|#
directive|define
name|SIR_NET
value|0
end_define

begin_define
define|#
directive|define
name|SIR_CLOCK
value|1
end_define

begin_define
define|#
directive|define
name|setsoftint
parameter_list|()
value|ienab_bis(IE_L1)
end_define

begin_define
define|#
directive|define
name|setsoftnet
parameter_list|()
value|(sir.sir_which[SIR_NET] = 1, setsoftint())
end_define

begin_define
define|#
directive|define
name|setsoftclock
parameter_list|()
value|(sir.sir_which[SIR_CLOCK] = 1, setsoftint())
end_define

begin_decl_stmt
name|int
name|want_ast
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Preempt the current process if in interrupt from user mode,  * or after the current trap/syscall if in system mode.  */
end_comment

begin_decl_stmt
name|int
name|want_resched
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* resched() was called */
end_comment

begin_define
define|#
directive|define
name|need_resched
parameter_list|()
value|(want_resched = 1, want_ast = 1)
end_define

begin_comment
comment|/*  * Give a profiling tick to the current process when the user profiling  * buffer pages are invalid.  On the sparc, request an ast to send us   * through trap(), marking the proc as needing a profiling tick.  */
end_comment

begin_define
define|#
directive|define
name|need_proftick
parameter_list|(
name|p
parameter_list|)
value|((p)->p_flag |= P_OWEUPC, want_ast = 1)
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
value|(want_ast = 1)
end_define

begin_comment
comment|/*  * Only one process may own the FPU state.  *  * XXX this must be per-cpu (eventually)  */
end_comment

begin_decl_stmt
name|struct
name|proc
modifier|*
name|fpproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* FPU owner */
end_comment

begin_decl_stmt
name|int
name|foundfpu
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true => we have an FPU */
end_comment

begin_comment
comment|/*  * Interrupt handler chains.  Interrupt handlers should return 0 for  * ``not me'' or 1 (``I took care of it'').  intr_establish() inserts a  * handler into the list.  The handler is called with its (single)  * argument, or with a pointer to a clockframe if ih_arg is NULL.  */
end_comment

begin_struct
struct|struct
name|intrhand
block|{
name|int
argument_list|(
argument|*ih_fun
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
modifier|*
name|ih_arg
decl_stmt|;
name|struct
name|intrhand
modifier|*
name|ih_next
decl_stmt|;
block|}
modifier|*
name|intrhand
index|[
literal|15
index|]
struct|;
end_struct

begin_decl_stmt
name|void
name|intr_establish
name|__P
argument_list|(
operator|(
name|int
name|level
operator|,
expr|struct
name|intrhand
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * intr_fasttrap() is a lot like intr_establish, but is used for ``fast''  * interrupt vectors (vectors that are not shared and are handled in the  * trap window).  Such functions must be written in assembly.  */
end_comment

begin_decl_stmt
name|void
name|intr_fasttrap
name|__P
argument_list|(
operator|(
name|int
name|level
operator|,
name|void
argument_list|(
operator|*
name|vec
argument_list|)
argument_list|(
name|void
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CPU_H_ */
end_comment

end_unit

