begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)pcb.h	7.3 (Berkeley) %G%  *  * from: $Header: pcb.h,v 1.6 92/11/26 02:04:39 torek Exp $  */
end_comment

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_define
define|#
directive|define
name|PCB_MAXWIN
value|32
end_define

begin_comment
comment|/* architectural limit */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PCB_MAXWIN
value|8
end_define

begin_comment
comment|/* worried about u area sizes ... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * SPARC Process Control Block.  *  * pcb_uw is positive if there are any user windows that are  * are currently in the CPU windows rather than on the user  * stack.  Whenever we are running in the kernel with traps  * enabled, we decrement pcb_uw for each ``push'' of a CPU  * register window into the stack, and we increment it for  * each ``pull'' from the stack into the CPU.  (If traps are  * disabled, or if we are in user mode, pcb_uw is junk.)  *  * To ease computing pcb_uw on traps from user mode, we keep track  * of the log base 2 of the single bit that is set in %wim.  *  * If an overflow occurs while the associated user stack pages  * are invalid (paged out), we have to store the registers  * in a page that is locked in core while the process runs,  * i.e., right here in the pcb.  We also need the stack pointer  * for the last such window (but only the last, as the others  * are in each window) and the count of windows saved.  We  * cheat by having a whole window structure for that one %sp.  * Thus, to save window pcb_rw[i] to memory, we write it at  * pcb_rw[i + 1].rw_in[6].  *  * pcb_nsaved has three `kinds' of values.  If 0, it means no  * registers are in the PCB (though if pcb_uw is positive,  * there may be the next time you look).  If positive, it means  * there are no user registers in the CPU, but there are some  * saved in pcb_rw[].  As a special case, traps that needed  * assistance to pull user registers from the stack also store  * the registers in pcb_rw[], and set pcb_nsaved to -1.  This  * special state is normally short-term: it can only last until the  * trap returns, and it can never persist across entry to user code.  */
end_comment

begin_struct
struct|struct
name|pcb
block|{
name|int
name|pcb_sp
decl_stmt|;
comment|/* sp (%o6) when swtch() was called */
name|int
name|pcb_pc
decl_stmt|;
comment|/* pc (%o7) when swtch() was called */
name|int
name|pcb_psr
decl_stmt|;
comment|/* %psr when swtch() was called */
name|caddr_t
name|pcb_onfault
decl_stmt|;
comment|/* for copyin/out */
name|int
name|pcb_uw
decl_stmt|;
comment|/* user windows inside CPU */
name|int
name|pcb_wim
decl_stmt|;
comment|/* log2(%wim) */
name|int
name|pcb_nsaved
decl_stmt|;
comment|/* number of windows saved in pcb */
ifdef|#
directive|ifdef
name|notdef
name|int
name|pcb_winof
decl_stmt|;
comment|/* number of window overflow traps */
name|int
name|pcb_winuf
decl_stmt|;
comment|/* number of window underflow traps */
endif|#
directive|endif
name|int
name|pcb_pad
decl_stmt|;
comment|/* pad to doubleword boundary */
comment|/* the following MUST be aligned on a doubleword boundary */
name|struct
name|rwindow
name|pcb_rw
index|[
name|PCB_MAXWIN
index|]
decl_stmt|;
comment|/* saved windows */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The pcb is augmented with machine-dependent additional data for  * core dumps.  Note that the trapframe here is a copy of the one  * from the top of the kernel stack (included here so that the kernel  * stack itself need not be dumped).  */
end_comment

begin_struct
struct|struct
name|md_coredump
block|{
name|struct
name|trapframe
name|md_tf
decl_stmt|;
name|struct
name|fpstate
name|md_fpstate
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|pcb
modifier|*
name|cpcb
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

