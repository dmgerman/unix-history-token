begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)cpu.h	7.3 (Berkeley) %G%  */
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

begin_include
include|#
directive|include
file|"machConst.h"
end_include

begin_comment
comment|/*  * Exported definitions unique to pmax/mips cpu support.  */
end_comment

begin_comment
comment|/*  * definitions of cpu-dependent requirements  * referenced in generic code  */
end_comment

begin_undef
undef|#
directive|undef
name|COPY_SIGCODE
end_undef

begin_comment
comment|/* copy sigcode above user stack in exec */
end_comment

begin_comment
comment|/*  * function vs. inline configuration;  * these are defined to get generic functions  * rather than inline or machine-dependent implementations  */
end_comment

begin_define
define|#
directive|define
name|NEED_MINMAX
end_define

begin_comment
comment|/* need {,i,l,ul}{min,max} functions */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_FFS
end_undef

begin_comment
comment|/* don't need ffs function */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_BCMP
end_undef

begin_comment
comment|/* don't need bcmp function */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_STRLEN
end_undef

begin_comment
comment|/* don't need strlen function */
end_comment

begin_define
define|#
directive|define
name|cpu_exec
parameter_list|(
name|p
parameter_list|)
value|(p->p_md.md_ss_addr = 0)
end_define

begin_comment
comment|/* init single step */
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
define|\
value|(p)->p_md.md_regs[SP] = ap
end_define

begin_comment
comment|/*  * Arguments to hardclock, softclock and gatherstats  * encapsulate the previous machine state in an opaque  * clockframe;  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|intrframe
block|{
name|int
name|pc
decl_stmt|;
name|int
name|ps
decl_stmt|;
block|}
name|clockframe
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CLKF_USERMODE
parameter_list|(
name|framep
parameter_list|)
value|((framep)->ps& MACH_SR_KU_PREV)
end_define

begin_define
define|#
directive|define
name|CLKF_BASEPRI
parameter_list|(
name|framep
parameter_list|)
define|\
value|(((framep)->ps& (MACH_INT_MASK | MACH_SR_INT_ENA_PREV)) == \ 	(MACH_INT_MASK | MACH_SR_INT_ENA_PREV))
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

begin_comment
comment|/*  * Preempt the current process if in interrupt from user mode,  * or after the current trap/syscall if in system mode.  */
end_comment

begin_define
define|#
directive|define
name|need_resched
parameter_list|()
value|{ want_resched = 1; aston(); }
end_define

begin_comment
comment|/*  * Give a profiling tick to the current process from the softclock  * interrupt.  */
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
define|\
value|addupc((framep)->pc,&p->p_stats->p_prof, 1);
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
value|(astpending = 1)
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
comment|/*  * CPU identification, from PRID register.  */
end_comment

begin_union
union|union
name|cpuprid
block|{
name|int
name|cpuprid
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int
name|pad1
range|:
literal|16
decl_stmt|;
comment|/* reserved */
name|u_int
name|cp_imp
range|:
literal|8
decl_stmt|;
comment|/* implementation identifier */
name|u_int
name|cp_majrev
range|:
literal|4
decl_stmt|;
comment|/* major revision identifier */
name|u_int
name|cp_minrev
range|:
literal|4
decl_stmt|;
comment|/* minor revision identifier */
else|#
directive|else
name|u_int
name|cp_minrev
range|:
literal|4
decl_stmt|;
comment|/* minor revision identifier */
name|u_int
name|cp_majrev
range|:
literal|4
decl_stmt|;
comment|/* major revision identifier */
name|u_int
name|cp_imp
range|:
literal|8
decl_stmt|;
comment|/* implementation identifier */
name|u_int
name|pad1
range|:
literal|16
decl_stmt|;
comment|/* reserved */
endif|#
directive|endif
block|}
name|cpu
struct|;
block|}
union|;
end_union

begin_comment
comment|/*  * MIPS CPU types (cp_imp).  */
end_comment

begin_define
define|#
directive|define
name|MIPS_R2000
value|0x02
end_define

begin_define
define|#
directive|define
name|MIPS_R3000
value|0x03
end_define

begin_define
define|#
directive|define
name|MIPS_R4000
value|0x04
end_define

begin_comment
comment|/*  * MIPS FPU types  */
end_comment

begin_define
define|#
directive|define
name|MIPS_R2010
value|0x03
end_define

begin_define
define|#
directive|define
name|MIPS_R3010
value|0x04
end_define

begin_define
define|#
directive|define
name|MIPS_R4010
value|0x05
end_define

begin_struct
struct|struct
name|intr_tab
block|{
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|()
function_decl|;
comment|/* pointer to interrupt routine */
name|int
name|unit
decl_stmt|;
comment|/* logical unit number */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|union
name|cpuprid
name|cpu
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|cpuprid
name|fpu
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|machDataCacheSize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|machInstCacheSize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|intr_tab
name|intr_tab
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Enable realtime clock (always enabled).  */
end_comment

begin_define
define|#
directive|define
name|enablertclock
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CPU_H_ */
end_comment

end_unit

