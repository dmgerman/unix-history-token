begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 William Jolitz.  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)npx.c	7.2 (Berkeley) 5/12/91  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"opt_cpu.h"
end_include

begin_include
include|#
directive|include
file|"opt_debug_npx.h"
end_include

begin_include
include|#
directive|include
file|"opt_math_emulate.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NPX_DEBUG
end_ifdef

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SMP
end_ifndef

begin_include
include|#
directive|include
file|<machine/asmacros.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/cputypes.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/ipl.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SMP
end_ifndef

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<machine/specialreg.h>
end_include

begin_include
include|#
directive|include
file|<machine/segments.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SMP
end_ifndef

begin_include
include|#
directive|include
file|<i386/isa/icu.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/intr_machdep.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/isa.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * 387 and 287 Numeric Coprocessor Extension (NPX) Driver.  */
end_comment

begin_comment
comment|/* Configuration flags. */
end_comment

begin_define
define|#
directive|define
name|NPX_DISABLE_I586_OPTIMIZED_BCOPY
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|NPX_DISABLE_I586_OPTIMIZED_BZERO
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|NPX_DISABLE_I586_OPTIMIZED_COPYIO
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|NPX_PREFER_EMULATOR
value|(1<< 3)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|fldcw
parameter_list|(
name|addr
parameter_list|)
value|__asm("fldcw %0" : : "m" (*(addr)))
end_define

begin_define
define|#
directive|define
name|fnclex
parameter_list|()
value|__asm("fnclex")
end_define

begin_define
define|#
directive|define
name|fninit
parameter_list|()
value|__asm("fninit")
end_define

begin_define
define|#
directive|define
name|fnop
parameter_list|()
value|__asm("fnop")
end_define

begin_define
define|#
directive|define
name|fnsave
parameter_list|(
name|addr
parameter_list|)
value|__asm __volatile("fnsave %0" : "=m" (*(addr)))
end_define

begin_define
define|#
directive|define
name|fnstcw
parameter_list|(
name|addr
parameter_list|)
value|__asm __volatile("fnstcw %0" : "=m" (*(addr)))
end_define

begin_define
define|#
directive|define
name|fnstsw
parameter_list|(
name|addr
parameter_list|)
value|__asm __volatile("fnstsw %0" : "=m" (*(addr)))
end_define

begin_define
define|#
directive|define
name|fp_divide_by_0
parameter_list|()
value|__asm("fldz; fld1; fdiv %st,%st(1); fnop")
end_define

begin_define
define|#
directive|define
name|frstor
parameter_list|(
name|addr
parameter_list|)
value|__asm("frstor %0" : : "m" (*(addr)))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_ENABLE_SSE
end_ifdef

begin_define
define|#
directive|define
name|fxrstor
parameter_list|(
name|addr
parameter_list|)
value|__asm("fxrstor %0" : : "m" (*(addr)))
end_define

begin_define
define|#
directive|define
name|fxsave
parameter_list|(
name|addr
parameter_list|)
value|__asm __volatile("fxsave %0" : "=m" (*(addr)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|start_emulating
parameter_list|()
value|__asm("smsw %%ax; orb %0,%%al; lmsw %%ax" \ 				      : : "n" (CR0_TS) : "ax")
end_define

begin_define
define|#
directive|define
name|stop_emulating
parameter_list|()
value|__asm("clts")
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __GNUC__ */
end_comment

begin_decl_stmt
name|void
name|fldcw
name|__P
argument_list|(
operator|(
name|caddr_t
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fnclex
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fninit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fnop
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fnsave
name|__P
argument_list|(
operator|(
name|caddr_t
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fnstcw
name|__P
argument_list|(
operator|(
name|caddr_t
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fnstsw
name|__P
argument_list|(
operator|(
name|caddr_t
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fp_divide_by_0
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|frstor
name|__P
argument_list|(
operator|(
name|caddr_t
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_ENABLE_SSE
end_ifdef

begin_decl_stmt
name|void
name|fxsave
name|__P
argument_list|(
operator|(
name|caddr_t
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fxrstor
name|__P
argument_list|(
operator|(
name|caddr_t
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|start_emulating
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|stop_emulating
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_ENABLE_SSE
end_ifdef

begin_define
define|#
directive|define
name|GET_FPU_EXSW_PTR
parameter_list|(
name|pcb
parameter_list|)
define|\
value|(cpu_fxsr ? \&(pcb)->pcb_save.sv_xmm.sv_ex_sw : \&(pcb)->pcb_save.sv_87.sv_ex_sw)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CPU_ENABLE_SSE */
end_comment

begin_define
define|#
directive|define
name|GET_FPU_EXSW_PTR
parameter_list|(
name|pcb
parameter_list|)
define|\
value|(&(pcb)->pcb_save.sv_87.sv_ex_sw)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_ENABLE_SSE */
end_comment

begin_typedef
typedef|typedef
name|u_char
name|bool_t
typedef|;
end_typedef

begin_decl_stmt
specifier|static
name|int
name|npx_attach
name|__P
argument_list|(
operator|(
name|device_t
name|dev
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|npx_intr
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|npx_identify
name|__P
argument_list|(
operator|(
name|driver_t
operator|*
name|driver
operator|,
name|device_t
name|parent
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|npx_probe
name|__P
argument_list|(
operator|(
name|device_t
name|dev
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|npx_probe1
name|__P
argument_list|(
operator|(
name|device_t
name|dev
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|fpusave
name|__P
argument_list|(
operator|(
expr|union
name|savefpu
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|fpurstor
name|__P
argument_list|(
operator|(
expr|union
name|savefpu
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|I586_CPU
end_ifdef

begin_decl_stmt
specifier|static
name|long
name|timezero
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|funcname
operator|,
name|void
argument_list|(
argument|*func
argument_list|)
operator|(
name|void
operator|*
name|buf
operator|,
name|size_t
name|len
operator|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I586_CPU */
end_comment

begin_decl_stmt
name|int
name|hw_float
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX currently just alias for npx_exists */
end_comment

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_hw
argument_list|,
name|HW_FLOATINGPT
argument_list|,
name|floatingpoint
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|hw_float
argument_list|,
literal|0
argument_list|,
literal|"Floatingpoint instructions executed in hardware"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|SMP
end_ifndef

begin_decl_stmt
specifier|static
name|u_int
name|npx0_imask
init|=
name|SWI_CLOCK_MASK
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|gate_descriptor
name|npx_idt_probeintr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|npx_intrno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|volatile
name|u_int
name|npx_intrs_while_probing
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|volatile
name|u_int
name|npx_traps_while_probing
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|bool_t
name|npx_ex16
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool_t
name|npx_exists
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool_t
name|npx_irq13
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|npx_irq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* irq number */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SMP
end_ifndef

begin_comment
comment|/*  * Special interrupt handlers.  Someday intr0-intr15 will be used to count  * interrupts.  We'll still need a special exception 16 handler.  The busy  * latch stuff in probeintr() can be moved to npxprobe().  */
end_comment

begin_decl_stmt
name|inthand_t
name|probeintr
decl_stmt|;
end_decl_stmt

begin_asm
asm|__asm("								\n\ 	.text							\n\ 	.p2align 2,0x90						\n\ 	.type	" __XSTRING(CNAME(probeintr)) ",@function	\n\ " __XSTRING(CNAME(probeintr)) ":				\n\ 	ss							\n\ 	incl	" __XSTRING(CNAME(npx_intrs_while_probing)) "	\n\ 	pushl	%eax						\n\ 	movb	$0x20,%al	# EOI (asm in strings loses cpp features) \n\ 	outb	%al,$0xa0	# IO_ICU2			\n\ 	outb	%al,$0x20	# IO_ICU1			\n\ 	movb	$0,%al						\n\ 	outb	%al,$0xf0	# clear BUSY# latch		\n\ 	popl	%eax						\n\ 	iret							\n\ ");
end_asm

begin_decl_stmt
name|inthand_t
name|probetrap
decl_stmt|;
end_decl_stmt

begin_asm
asm|__asm("								\n\ 	.text							\n\ 	.p2align 2,0x90						\n\ 	.type	" __XSTRING(CNAME(probetrap)) ",@function	\n\ " __XSTRING(CNAME(probetrap)) ":				\n\ 	ss							\n\ 	incl	" __XSTRING(CNAME(npx_traps_while_probing)) "	\n\ 	fnclex							\n\ 	iret							\n\ ");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP */
end_comment

begin_comment
comment|/*  * Identify routine.  Create a connection point on our parent for probing.  */
end_comment

begin_function
specifier|static
name|void
name|npx_identify
parameter_list|(
name|driver
parameter_list|,
name|parent
parameter_list|)
name|driver_t
modifier|*
name|driver
decl_stmt|;
name|device_t
name|parent
decl_stmt|;
block|{
name|device_t
name|child
decl_stmt|;
name|child
operator|=
name|BUS_ADD_CHILD
argument_list|(
name|parent
argument_list|,
literal|0
argument_list|,
literal|"npx"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|child
operator|==
name|NULL
condition|)
name|panic
argument_list|(
literal|"npx_identify"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Probe routine.  Initialize cr0 to give correct behaviour for [f]wait  * whether the device exists or not (XXX should be elsewhere).  Set flags  * to tell npxattach() what to do.  Modify device struct if npx doesn't  * need to use interrupts.  Return 1 if device exists.  */
end_comment

begin_function
specifier|static
name|int
name|npx_probe
parameter_list|(
name|dev
parameter_list|)
name|device_t
name|dev
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|SMP
if|if
condition|(
name|resource_int_value
argument_list|(
literal|"npx"
argument_list|,
literal|0
argument_list|,
literal|"irq"
argument_list|,
operator|&
name|npx_irq
argument_list|)
operator|!=
literal|0
condition|)
name|npx_irq
operator|=
literal|13
expr_stmt|;
return|return
name|npx_probe1
argument_list|(
name|dev
argument_list|)
return|;
else|#
directive|else
comment|/* SMP */
name|int
name|result
decl_stmt|;
name|u_long
name|save_eflags
decl_stmt|;
name|u_char
name|save_icu1_mask
decl_stmt|;
name|u_char
name|save_icu2_mask
decl_stmt|;
name|struct
name|gate_descriptor
name|save_idt_npxintr
decl_stmt|;
name|struct
name|gate_descriptor
name|save_idt_npxtrap
decl_stmt|;
comment|/* 	 * This routine is now just a wrapper for npxprobe1(), to install 	 * special npx interrupt and trap handlers, to enable npx interrupts 	 * and to disable other interrupts.  Someday isa_configure() will 	 * install suitable handlers and run with interrupts enabled so we 	 * won't need to do so much here. 	 */
if|if
condition|(
name|resource_int_value
argument_list|(
literal|"npx"
argument_list|,
literal|0
argument_list|,
literal|"irq"
argument_list|,
operator|&
name|npx_irq
argument_list|)
operator|!=
literal|0
condition|)
name|npx_irq
operator|=
literal|13
expr_stmt|;
name|npx_intrno
operator|=
name|NRSVIDT
operator|+
name|npx_irq
expr_stmt|;
name|save_eflags
operator|=
name|read_eflags
argument_list|()
expr_stmt|;
name|disable_intr
argument_list|()
expr_stmt|;
name|save_icu1_mask
operator|=
name|inb
argument_list|(
name|IO_ICU1
operator|+
literal|1
argument_list|)
expr_stmt|;
name|save_icu2_mask
operator|=
name|inb
argument_list|(
name|IO_ICU2
operator|+
literal|1
argument_list|)
expr_stmt|;
name|save_idt_npxintr
operator|=
name|idt
index|[
name|npx_intrno
index|]
expr_stmt|;
name|save_idt_npxtrap
operator|=
name|idt
index|[
literal|16
index|]
expr_stmt|;
name|outb
argument_list|(
name|IO_ICU1
operator|+
literal|1
argument_list|,
operator|~
name|IRQ_SLAVE
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|IO_ICU2
operator|+
literal|1
argument_list|,
operator|~
operator|(
literal|1
operator|<<
operator|(
name|npx_irq
operator|-
literal|8
operator|)
operator|)
argument_list|)
expr_stmt|;
name|setidt
argument_list|(
literal|16
argument_list|,
name|probetrap
argument_list|,
name|SDT_SYS386TGT
argument_list|,
name|SEL_KPL
argument_list|,
name|GSEL
argument_list|(
name|GCODE_SEL
argument_list|,
name|SEL_KPL
argument_list|)
argument_list|)
expr_stmt|;
name|setidt
argument_list|(
name|npx_intrno
argument_list|,
name|probeintr
argument_list|,
name|SDT_SYS386IGT
argument_list|,
name|SEL_KPL
argument_list|,
name|GSEL
argument_list|(
name|GCODE_SEL
argument_list|,
name|SEL_KPL
argument_list|)
argument_list|)
expr_stmt|;
name|npx_idt_probeintr
operator|=
name|idt
index|[
name|npx_intrno
index|]
expr_stmt|;
name|enable_intr
argument_list|()
expr_stmt|;
name|result
operator|=
name|npx_probe1
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|disable_intr
argument_list|()
expr_stmt|;
name|outb
argument_list|(
name|IO_ICU1
operator|+
literal|1
argument_list|,
name|save_icu1_mask
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|IO_ICU2
operator|+
literal|1
argument_list|,
name|save_icu2_mask
argument_list|)
expr_stmt|;
name|idt
index|[
name|npx_intrno
index|]
operator|=
name|save_idt_npxintr
expr_stmt|;
name|idt
index|[
literal|16
index|]
operator|=
name|save_idt_npxtrap
expr_stmt|;
name|write_eflags
argument_list|(
name|save_eflags
argument_list|)
expr_stmt|;
return|return
operator|(
name|result
operator|)
return|;
endif|#
directive|endif
comment|/* SMP */
block|}
end_function

begin_function
specifier|static
name|int
name|npx_probe1
parameter_list|(
name|dev
parameter_list|)
name|device_t
name|dev
decl_stmt|;
block|{
ifndef|#
directive|ifndef
name|SMP
name|u_short
name|control
decl_stmt|;
name|u_short
name|status
decl_stmt|;
endif|#
directive|endif
comment|/* 	 * Partially reset the coprocessor, if any.  Some BIOS's don't reset 	 * it after a warm boot. 	 */
name|outb
argument_list|(
literal|0xf1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* full reset on some systems, NOP on others */
name|outb
argument_list|(
literal|0xf0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* clear BUSY# latch */
comment|/* 	 * Prepare to trap all ESC (i.e., NPX) instructions and all WAIT 	 * instructions.  We must set the CR0_MP bit and use the CR0_TS 	 * bit to control the trap, because setting the CR0_EM bit does 	 * not cause WAIT instructions to trap.  It's important to trap 	 * WAIT instructions - otherwise the "wait" variants of no-wait 	 * control instructions would degenerate to the "no-wait" variants 	 * after FP context switches but work correctly otherwise.  It's 	 * particularly important to trap WAITs when there is no NPX - 	 * otherwise the "wait" variants would always degenerate. 	 * 	 * Try setting CR0_NE to get correct error reporting on 486DX's. 	 * Setting it should fail or do nothing on lesser processors. 	 */
name|load_cr0
argument_list|(
name|rcr0
argument_list|()
operator||
name|CR0_MP
operator||
name|CR0_NE
argument_list|)
expr_stmt|;
comment|/* 	 * But don't trap while we're probing. 	 */
name|stop_emulating
argument_list|()
expr_stmt|;
comment|/* 	 * Finish resetting the coprocessor, if any.  If there is an error 	 * pending, then we may get a bogus IRQ13, but probeintr() will handle 	 * it OK.  Bogus halts have never been observed, but we enabled 	 * IRQ13 and cleared the BUSY# latch early to handle them anyway. 	 */
name|fninit
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|SMP
comment|/* 	 * Exception 16 MUST work for SMP. 	 */
name|npx_irq13
operator|=
literal|0
expr_stmt|;
name|npx_ex16
operator|=
name|hw_float
operator|=
name|npx_exists
operator|=
literal|1
expr_stmt|;
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"math processor"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
comment|/* !SMP */
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"math processor"
argument_list|)
expr_stmt|;
comment|/* 	 * Don't use fwait here because it might hang. 	 * Don't use fnop here because it usually hangs if there is no FPU. 	 */
name|DELAY
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
comment|/* wait for any IRQ13 */
ifdef|#
directive|ifdef
name|DIAGNOSTIC
if|if
condition|(
name|npx_intrs_while_probing
operator|!=
literal|0
condition|)
name|printf
argument_list|(
literal|"fninit caused %u bogus npx interrupt(s)\n"
argument_list|,
name|npx_intrs_while_probing
argument_list|)
expr_stmt|;
if|if
condition|(
name|npx_traps_while_probing
operator|!=
literal|0
condition|)
name|printf
argument_list|(
literal|"fninit caused %u bogus npx trap(s)\n"
argument_list|,
name|npx_traps_while_probing
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * Check for a status of mostly zero. 	 */
name|status
operator|=
literal|0x5a5a
expr_stmt|;
name|fnstsw
argument_list|(
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|status
operator|&
literal|0xb8ff
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* 		 * Good, now check for a proper control word. 		 */
name|control
operator|=
literal|0x5a5a
expr_stmt|;
name|fnstcw
argument_list|(
operator|&
name|control
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|control
operator|&
literal|0x1f3f
operator|)
operator|==
literal|0x033f
condition|)
block|{
name|hw_float
operator|=
name|npx_exists
operator|=
literal|1
expr_stmt|;
comment|/* 			 * We have an npx, now divide by 0 to see if exception 			 * 16 works. 			 */
name|control
operator|&=
operator|~
operator|(
literal|1
operator|<<
literal|2
operator|)
expr_stmt|;
comment|/* enable divide by 0 trap */
name|fldcw
argument_list|(
operator|&
name|control
argument_list|)
expr_stmt|;
name|npx_traps_while_probing
operator|=
name|npx_intrs_while_probing
operator|=
literal|0
expr_stmt|;
name|fp_divide_by_0
argument_list|()
expr_stmt|;
if|if
condition|(
name|npx_traps_while_probing
operator|!=
literal|0
condition|)
block|{
comment|/* 				 * Good, exception 16 works. 				 */
name|npx_ex16
operator|=
literal|1
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|npx_intrs_while_probing
operator|!=
literal|0
condition|)
block|{
name|int
name|rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|r
decl_stmt|;
name|void
modifier|*
name|intr
decl_stmt|;
comment|/* 				 * Bad, we are stuck with IRQ13. 				 */
name|npx_irq13
operator|=
literal|1
expr_stmt|;
comment|/* 				 * npxattach would be too late to set npx0_imask 				 */
name|npx0_imask
operator||=
operator|(
literal|1
operator|<<
name|npx_irq
operator|)
expr_stmt|;
comment|/* 				 * We allocate these resources permanently, 				 * so there is no need to keep track of them. 				 */
name|rid
operator|=
literal|0
expr_stmt|;
name|r
operator|=
name|bus_alloc_resource
argument_list|(
name|dev
argument_list|,
name|SYS_RES_IOPORT
argument_list|,
operator|&
name|rid
argument_list|,
name|IO_NPX
argument_list|,
name|IO_NPX
argument_list|,
name|IO_NPXSIZE
argument_list|,
name|RF_ACTIVE
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|==
literal|0
condition|)
name|panic
argument_list|(
literal|"npx: can't get ports"
argument_list|)
expr_stmt|;
name|rid
operator|=
literal|0
expr_stmt|;
name|r
operator|=
name|bus_alloc_resource
argument_list|(
name|dev
argument_list|,
name|SYS_RES_IRQ
argument_list|,
operator|&
name|rid
argument_list|,
name|npx_irq
argument_list|,
name|npx_irq
argument_list|,
literal|1
argument_list|,
name|RF_ACTIVE
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|==
literal|0
condition|)
name|panic
argument_list|(
literal|"npx: can't get IRQ"
argument_list|)
expr_stmt|;
name|BUS_SETUP_INTR
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|r
argument_list|,
name|INTR_TYPE_MISC
argument_list|,
name|npx_intr
argument_list|,
literal|0
argument_list|,
operator|&
name|intr
argument_list|)
expr_stmt|;
if|if
condition|(
name|intr
operator|==
literal|0
condition|)
name|panic
argument_list|(
literal|"npx: can't create intr"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* 			 * Worse, even IRQ13 is broken.  Use emulator. 			 */
block|}
block|}
comment|/* 	 * Probe failed, but we want to get to npxattach to initialize the 	 * emulator and say that it has been installed.  XXX handle devices 	 * that aren't really devices better. 	 */
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
comment|/* SMP */
block|}
end_function

begin_comment
comment|/*  * Attach routine - announce which it is, and wire into system  */
end_comment

begin_function
name|int
name|npx_attach
parameter_list|(
name|dev
parameter_list|)
name|device_t
name|dev
decl_stmt|;
block|{
name|int
name|flags
decl_stmt|;
if|if
condition|(
name|resource_int_value
argument_list|(
literal|"npx"
argument_list|,
literal|0
argument_list|,
literal|"flags"
argument_list|,
operator|&
name|flags
argument_list|)
operator|!=
literal|0
condition|)
name|flags
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|flags
condition|)
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"flags 0x%x "
argument_list|,
name|flags
argument_list|)
expr_stmt|;
if|if
condition|(
name|npx_irq13
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"using IRQ 13 interface\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|#
directive|if
name|defined
argument_list|(
name|MATH_EMULATE
argument_list|)
operator|||
name|defined
argument_list|(
name|GPL_MATH_EMULATE
argument_list|)
if|if
condition|(
name|npx_ex16
condition|)
block|{
if|if
condition|(
operator|!
operator|(
name|flags
operator|&
name|NPX_PREFER_EMULATOR
operator|)
condition|)
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"INT 16 interface\n"
argument_list|)
expr_stmt|;
else|else
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"FPU exists, but flags request "
literal|"emulator\n"
argument_list|)
expr_stmt|;
name|hw_float
operator|=
name|npx_exists
operator|=
literal|0
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|npx_exists
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"error reporting broken; using 387 emulator\n"
argument_list|)
expr_stmt|;
name|hw_float
operator|=
name|npx_exists
operator|=
literal|0
expr_stmt|;
block|}
else|else
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"387 emulator\n"
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|npx_ex16
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"INT 16 interface\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|NPX_PREFER_EMULATOR
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"emulator requested, but none compiled "
literal|"into kernel, using FPU\n"
argument_list|)
expr_stmt|;
block|}
block|}
else|else
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"no 387 emulator in kernel and no FPU!\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|npxinit
argument_list|(
name|__INITIAL_NPXCW__
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|I586_CPU
if|if
condition|(
name|cpu_class
operator|==
name|CPUCLASS_586
operator|&&
name|npx_ex16
operator|&&
name|npx_exists
operator|&&
name|timezero
argument_list|(
literal|"i586_bzero()"
argument_list|,
name|i586_bzero
argument_list|)
operator|<
name|timezero
argument_list|(
literal|"bzero()"
argument_list|,
name|bzero
argument_list|)
operator|*
literal|4
operator|/
literal|5
condition|)
block|{
if|if
condition|(
operator|!
operator|(
name|flags
operator|&
name|NPX_DISABLE_I586_OPTIMIZED_BCOPY
operator|)
condition|)
block|{
name|bcopy_vector
operator|=
name|i586_bcopy
expr_stmt|;
name|ovbcopy_vector
operator|=
name|i586_bcopy
expr_stmt|;
block|}
if|if
condition|(
operator|!
operator|(
name|flags
operator|&
name|NPX_DISABLE_I586_OPTIMIZED_BZERO
operator|)
condition|)
name|bzero
operator|=
name|i586_bzero
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|flags
operator|&
name|NPX_DISABLE_I586_OPTIMIZED_COPYIO
operator|)
condition|)
block|{
name|copyin_vector
operator|=
name|i586_copyin
expr_stmt|;
name|copyout_vector
operator|=
name|i586_copyout
expr_stmt|;
block|}
block|}
endif|#
directive|endif
return|return
operator|(
literal|0
operator|)
return|;
comment|/* XXX unused */
block|}
end_function

begin_comment
comment|/*  * Initialize floating point unit.  */
end_comment

begin_function
name|void
name|npxinit
parameter_list|(
name|control
parameter_list|)
name|u_short
name|control
decl_stmt|;
block|{
specifier|static
name|union
name|savefpu
name|dummy
decl_stmt|;
if|if
condition|(
operator|!
name|npx_exists
condition|)
return|return;
comment|/* 	 * fninit has the same h/w bugs as fnsave.  Use the detoxified 	 * fnsave to throw away any junk in the fpu.  npxsave() initializes 	 * the fpu and sets npxproc = NULL as important side effects. 	 */
name|npxsave
argument_list|(
operator|&
name|dummy
argument_list|)
expr_stmt|;
name|stop_emulating
argument_list|()
expr_stmt|;
name|fldcw
argument_list|(
operator|&
name|control
argument_list|)
expr_stmt|;
if|if
condition|(
name|curpcb
operator|!=
name|NULL
condition|)
name|fpusave
argument_list|(
operator|&
name|curpcb
operator|->
name|pcb_save
argument_list|)
expr_stmt|;
name|start_emulating
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Free coprocessor (if we have it).  */
end_comment

begin_function
name|void
name|npxexit
parameter_list|(
name|p
parameter_list|)
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
block|{
if|if
condition|(
name|p
operator|==
name|npxproc
condition|)
name|npxsave
argument_list|(
operator|&
name|curpcb
operator|->
name|pcb_save
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|NPX_DEBUG
if|if
condition|(
name|npx_exists
condition|)
block|{
name|u_int
name|masked_exceptions
decl_stmt|;
name|masked_exceptions
operator|=
name|curpcb
operator|->
name|pcb_save
operator|.
name|sv_87
operator|.
name|sv_env
operator|.
name|en_cw
operator|&
name|curpcb
operator|->
name|pcb_save
operator|.
name|sv_87
operator|.
name|sv_env
operator|.
name|en_sw
operator|&
literal|0x7f
expr_stmt|;
comment|/* 		 * Log exceptions that would have trapped with the old 		 * control word (overflow, divide by 0, and invalid operand). 		 */
if|if
condition|(
name|masked_exceptions
operator|&
literal|0x0d
condition|)
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"pid %d (%s) exited with masked floating point exceptions 0x%02x\n"
argument_list|,
name|p
operator|->
name|p_pid
argument_list|,
name|p
operator|->
name|p_comm
argument_list|,
name|masked_exceptions
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*   * The following mechanism is used to ensure that the FPE_... value  * that is passed as a trapcode to the signal handler of the user  * process does not have more than one bit set.  *   * Multiple bits may be set if the user process modifies the control  * word while a status word bit is already set.  While this is a sign  * of bad coding, we have no choise than to narrow them down to one  * bit, since we must not send a trapcode that is not exactly one of  * the FPE_ macros.  *  * The mechanism has a static table with 127 entries.  Each combination  * of the 7 FPU status word exception bits directly translates to a  * position in this table, where a single FPE_... value is stored.  * This FPE_... value stored there is considered the "most important"  * of the exception bits and will be sent as the signal code.  The  * precedence of the bits is based upon Intel Document "Numerical  * Applications", Chapter "Special Computational Situations".  *  * The macro to choose one of these values does these steps: 1) Throw  * away status word bits that cannot be masked.  2) Throw away the bits  * currently masked in the control word, assuming the user isn't  * interested in them anymore.  3) Reinsert status word bit 7 (stack  * fault) if it is set, which cannot be masked but must be presered.  * 4) Use the remaining bits to point into the trapcode table.  *  * The 6 maskable bits in order of their preference, as stated in the  * above referenced Intel manual:  * 1  Invalid operation (FP_X_INV)  * 1a   Stack underflow  * 1b   Stack overflow  * 1c   Operand of unsupported format  * 1d   SNaN operand.  * 2  QNaN operand (not an exception, irrelavant here)  * 3  Any other invalid-operation not mentioned above or zero divide  *      (FP_X_INV, FP_X_DZ)  * 4  Denormal operand (FP_X_DNML)  * 5  Numeric over/underflow (FP_X_OFL, FP_X_UFL)  * 6  Inexact result (FP_X_IMP)   */
end_comment

begin_decl_stmt
specifier|static
name|char
name|fpetable
index|[
literal|128
index|]
init|=
block|{
literal|0
block|,
name|FPE_FLTINV
block|,
comment|/*  1 - INV */
name|FPE_FLTUND
block|,
comment|/*  2 - DNML */
name|FPE_FLTINV
block|,
comment|/*  3 - INV | DNML */
name|FPE_FLTDIV
block|,
comment|/*  4 - DZ */
name|FPE_FLTINV
block|,
comment|/*  5 - INV | DZ */
name|FPE_FLTDIV
block|,
comment|/*  6 - DNML | DZ */
name|FPE_FLTINV
block|,
comment|/*  7 - INV | DNML | DZ */
name|FPE_FLTOVF
block|,
comment|/*  8 - OFL */
name|FPE_FLTINV
block|,
comment|/*  9 - INV | OFL */
name|FPE_FLTUND
block|,
comment|/*  A - DNML | OFL */
name|FPE_FLTINV
block|,
comment|/*  B - INV | DNML | OFL */
name|FPE_FLTDIV
block|,
comment|/*  C - DZ | OFL */
name|FPE_FLTINV
block|,
comment|/*  D - INV | DZ | OFL */
name|FPE_FLTDIV
block|,
comment|/*  E - DNML | DZ | OFL */
name|FPE_FLTINV
block|,
comment|/*  F - INV | DNML | DZ | OFL */
name|FPE_FLTUND
block|,
comment|/* 10 - UFL */
name|FPE_FLTINV
block|,
comment|/* 11 - INV | UFL */
name|FPE_FLTUND
block|,
comment|/* 12 - DNML | UFL */
name|FPE_FLTINV
block|,
comment|/* 13 - INV | DNML | UFL */
name|FPE_FLTDIV
block|,
comment|/* 14 - DZ | UFL */
name|FPE_FLTINV
block|,
comment|/* 15 - INV | DZ | UFL */
name|FPE_FLTDIV
block|,
comment|/* 16 - DNML | DZ | UFL */
name|FPE_FLTINV
block|,
comment|/* 17 - INV | DNML | DZ | UFL */
name|FPE_FLTOVF
block|,
comment|/* 18 - OFL | UFL */
name|FPE_FLTINV
block|,
comment|/* 19 - INV | OFL | UFL */
name|FPE_FLTUND
block|,
comment|/* 1A - DNML | OFL | UFL */
name|FPE_FLTINV
block|,
comment|/* 1B - INV | DNML | OFL | UFL */
name|FPE_FLTDIV
block|,
comment|/* 1C - DZ | OFL | UFL */
name|FPE_FLTINV
block|,
comment|/* 1D - INV | DZ | OFL | UFL */
name|FPE_FLTDIV
block|,
comment|/* 1E - DNML | DZ | OFL | UFL */
name|FPE_FLTINV
block|,
comment|/* 1F - INV | DNML | DZ | OFL | UFL */
name|FPE_FLTRES
block|,
comment|/* 20 - IMP */
name|FPE_FLTINV
block|,
comment|/* 21 - INV | IMP */
name|FPE_FLTUND
block|,
comment|/* 22 - DNML | IMP */
name|FPE_FLTINV
block|,
comment|/* 23 - INV | DNML | IMP */
name|FPE_FLTDIV
block|,
comment|/* 24 - DZ | IMP */
name|FPE_FLTINV
block|,
comment|/* 25 - INV | DZ | IMP */
name|FPE_FLTDIV
block|,
comment|/* 26 - DNML | DZ | IMP */
name|FPE_FLTINV
block|,
comment|/* 27 - INV | DNML | DZ | IMP */
name|FPE_FLTOVF
block|,
comment|/* 28 - OFL | IMP */
name|FPE_FLTINV
block|,
comment|/* 29 - INV | OFL | IMP */
name|FPE_FLTUND
block|,
comment|/* 2A - DNML | OFL | IMP */
name|FPE_FLTINV
block|,
comment|/* 2B - INV | DNML | OFL | IMP */
name|FPE_FLTDIV
block|,
comment|/* 2C - DZ | OFL | IMP */
name|FPE_FLTINV
block|,
comment|/* 2D - INV | DZ | OFL | IMP */
name|FPE_FLTDIV
block|,
comment|/* 2E - DNML | DZ | OFL | IMP */
name|FPE_FLTINV
block|,
comment|/* 2F - INV | DNML | DZ | OFL | IMP */
name|FPE_FLTUND
block|,
comment|/* 30 - UFL | IMP */
name|FPE_FLTINV
block|,
comment|/* 31 - INV | UFL | IMP */
name|FPE_FLTUND
block|,
comment|/* 32 - DNML | UFL | IMP */
name|FPE_FLTINV
block|,
comment|/* 33 - INV | DNML | UFL | IMP */
name|FPE_FLTDIV
block|,
comment|/* 34 - DZ | UFL | IMP */
name|FPE_FLTINV
block|,
comment|/* 35 - INV | DZ | UFL | IMP */
name|FPE_FLTDIV
block|,
comment|/* 36 - DNML | DZ | UFL | IMP */
name|FPE_FLTINV
block|,
comment|/* 37 - INV | DNML | DZ | UFL | IMP */
name|FPE_FLTOVF
block|,
comment|/* 38 - OFL | UFL | IMP */
name|FPE_FLTINV
block|,
comment|/* 39 - INV | OFL | UFL | IMP */
name|FPE_FLTUND
block|,
comment|/* 3A - DNML | OFL | UFL | IMP */
name|FPE_FLTINV
block|,
comment|/* 3B - INV | DNML | OFL | UFL | IMP */
name|FPE_FLTDIV
block|,
comment|/* 3C - DZ | OFL | UFL | IMP */
name|FPE_FLTINV
block|,
comment|/* 3D - INV | DZ | OFL | UFL | IMP */
name|FPE_FLTDIV
block|,
comment|/* 3E - DNML | DZ | OFL | UFL | IMP */
name|FPE_FLTINV
block|,
comment|/* 3F - INV | DNML | DZ | OFL | UFL | IMP */
name|FPE_FLTSUB
block|,
comment|/* 40 - STK */
name|FPE_FLTSUB
block|,
comment|/* 41 - INV | STK */
name|FPE_FLTUND
block|,
comment|/* 42 - DNML | STK */
name|FPE_FLTSUB
block|,
comment|/* 43 - INV | DNML | STK */
name|FPE_FLTDIV
block|,
comment|/* 44 - DZ | STK */
name|FPE_FLTSUB
block|,
comment|/* 45 - INV | DZ | STK */
name|FPE_FLTDIV
block|,
comment|/* 46 - DNML | DZ | STK */
name|FPE_FLTSUB
block|,
comment|/* 47 - INV | DNML | DZ | STK */
name|FPE_FLTOVF
block|,
comment|/* 48 - OFL | STK */
name|FPE_FLTSUB
block|,
comment|/* 49 - INV | OFL | STK */
name|FPE_FLTUND
block|,
comment|/* 4A - DNML | OFL | STK */
name|FPE_FLTSUB
block|,
comment|/* 4B - INV | DNML | OFL | STK */
name|FPE_FLTDIV
block|,
comment|/* 4C - DZ | OFL | STK */
name|FPE_FLTSUB
block|,
comment|/* 4D - INV | DZ | OFL | STK */
name|FPE_FLTDIV
block|,
comment|/* 4E - DNML | DZ | OFL | STK */
name|FPE_FLTSUB
block|,
comment|/* 4F - INV | DNML | DZ | OFL | STK */
name|FPE_FLTUND
block|,
comment|/* 50 - UFL | STK */
name|FPE_FLTSUB
block|,
comment|/* 51 - INV | UFL | STK */
name|FPE_FLTUND
block|,
comment|/* 52 - DNML | UFL | STK */
name|FPE_FLTSUB
block|,
comment|/* 53 - INV | DNML | UFL | STK */
name|FPE_FLTDIV
block|,
comment|/* 54 - DZ | UFL | STK */
name|FPE_FLTSUB
block|,
comment|/* 55 - INV | DZ | UFL | STK */
name|FPE_FLTDIV
block|,
comment|/* 56 - DNML | DZ | UFL | STK */
name|FPE_FLTSUB
block|,
comment|/* 57 - INV | DNML | DZ | UFL | STK */
name|FPE_FLTOVF
block|,
comment|/* 58 - OFL | UFL | STK */
name|FPE_FLTSUB
block|,
comment|/* 59 - INV | OFL | UFL | STK */
name|FPE_FLTUND
block|,
comment|/* 5A - DNML | OFL | UFL | STK */
name|FPE_FLTSUB
block|,
comment|/* 5B - INV | DNML | OFL | UFL | STK */
name|FPE_FLTDIV
block|,
comment|/* 5C - DZ | OFL | UFL | STK */
name|FPE_FLTSUB
block|,
comment|/* 5D - INV | DZ | OFL | UFL | STK */
name|FPE_FLTDIV
block|,
comment|/* 5E - DNML | DZ | OFL | UFL | STK */
name|FPE_FLTSUB
block|,
comment|/* 5F - INV | DNML | DZ | OFL | UFL | STK */
name|FPE_FLTRES
block|,
comment|/* 60 - IMP | STK */
name|FPE_FLTSUB
block|,
comment|/* 61 - INV | IMP | STK */
name|FPE_FLTUND
block|,
comment|/* 62 - DNML | IMP | STK */
name|FPE_FLTSUB
block|,
comment|/* 63 - INV | DNML | IMP | STK */
name|FPE_FLTDIV
block|,
comment|/* 64 - DZ | IMP | STK */
name|FPE_FLTSUB
block|,
comment|/* 65 - INV | DZ | IMP | STK */
name|FPE_FLTDIV
block|,
comment|/* 66 - DNML | DZ | IMP | STK */
name|FPE_FLTSUB
block|,
comment|/* 67 - INV | DNML | DZ | IMP | STK */
name|FPE_FLTOVF
block|,
comment|/* 68 - OFL | IMP | STK */
name|FPE_FLTSUB
block|,
comment|/* 69 - INV | OFL | IMP | STK */
name|FPE_FLTUND
block|,
comment|/* 6A - DNML | OFL | IMP | STK */
name|FPE_FLTSUB
block|,
comment|/* 6B - INV | DNML | OFL | IMP | STK */
name|FPE_FLTDIV
block|,
comment|/* 6C - DZ | OFL | IMP | STK */
name|FPE_FLTSUB
block|,
comment|/* 6D - INV | DZ | OFL | IMP | STK */
name|FPE_FLTDIV
block|,
comment|/* 6E - DNML | DZ | OFL | IMP | STK */
name|FPE_FLTSUB
block|,
comment|/* 6F - INV | DNML | DZ | OFL | IMP | STK */
name|FPE_FLTUND
block|,
comment|/* 70 - UFL | IMP | STK */
name|FPE_FLTSUB
block|,
comment|/* 71 - INV | UFL | IMP | STK */
name|FPE_FLTUND
block|,
comment|/* 72 - DNML | UFL | IMP | STK */
name|FPE_FLTSUB
block|,
comment|/* 73 - INV | DNML | UFL | IMP | STK */
name|FPE_FLTDIV
block|,
comment|/* 74 - DZ | UFL | IMP | STK */
name|FPE_FLTSUB
block|,
comment|/* 75 - INV | DZ | UFL | IMP | STK */
name|FPE_FLTDIV
block|,
comment|/* 76 - DNML | DZ | UFL | IMP | STK */
name|FPE_FLTSUB
block|,
comment|/* 77 - INV | DNML | DZ | UFL | IMP | STK */
name|FPE_FLTOVF
block|,
comment|/* 78 - OFL | UFL | IMP | STK */
name|FPE_FLTSUB
block|,
comment|/* 79 - INV | OFL | UFL | IMP | STK */
name|FPE_FLTUND
block|,
comment|/* 7A - DNML | OFL | UFL | IMP | STK */
name|FPE_FLTSUB
block|,
comment|/* 7B - INV | DNML | OFL | UFL | IMP | STK */
name|FPE_FLTDIV
block|,
comment|/* 7C - DZ | OFL | UFL | IMP | STK */
name|FPE_FLTSUB
block|,
comment|/* 7D - INV | DZ | OFL | UFL | IMP | STK */
name|FPE_FLTDIV
block|,
comment|/* 7E - DNML | DZ | OFL | UFL | IMP | STK */
name|FPE_FLTSUB
block|,
comment|/* 7F - INV | DNML | DZ | OFL | UFL | IMP | STK */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Preserve the FP status word, clear FP exceptions, then generate a SIGFPE.  *  * Clearing exceptions is necessary mainly to avoid IRQ13 bugs.  We now  * depend on longjmp() restoring a usable state.  Restoring the state  * or examining it might fail if we didn't clear exceptions.  *  * The error code chosen will be one of the FPE_... macros. It will be  * sent as the second argument to old BSD-style signal handlers and as  * "siginfo_t->si_code" (second argument) to SA_SIGINFO signal handlers.  *  * XXX the FP state is not preserved across signal handlers.  So signal  * handlers cannot afford to do FP unless they preserve the state or  * longjmp() out.  Both preserving the state and longjmp()ing may be  * destroyed by IRQ13 bugs.  Clearing FP exceptions is not an acceptable  * solution for signals other than SIGFPE.  */
end_comment

begin_function
name|void
name|npx_intr
parameter_list|(
name|dummy
parameter_list|)
name|void
modifier|*
name|dummy
decl_stmt|;
block|{
name|int
name|code
decl_stmt|;
name|u_short
name|control
decl_stmt|;
name|struct
name|intrframe
modifier|*
name|frame
decl_stmt|;
name|u_long
modifier|*
name|exstat
decl_stmt|;
if|if
condition|(
name|npxproc
operator|==
name|NULL
operator|||
operator|!
name|npx_exists
condition|)
block|{
name|printf
argument_list|(
literal|"npxintr: npxproc = %p, curproc = %p, npx_exists = %d\n"
argument_list|,
name|npxproc
argument_list|,
name|curproc
argument_list|,
name|npx_exists
argument_list|)
expr_stmt|;
name|panic
argument_list|(
literal|"npxintr from nowhere"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|npxproc
operator|!=
name|curproc
condition|)
block|{
name|printf
argument_list|(
literal|"npxintr: npxproc = %p, curproc = %p, npx_exists = %d\n"
argument_list|,
name|npxproc
argument_list|,
name|curproc
argument_list|,
name|npx_exists
argument_list|)
expr_stmt|;
name|panic
argument_list|(
literal|"npxintr from non-current process"
argument_list|)
expr_stmt|;
block|}
name|exstat
operator|=
name|GET_FPU_EXSW_PTR
argument_list|(
name|curpcb
argument_list|)
expr_stmt|;
name|outb
argument_list|(
literal|0xf0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|fnstsw
argument_list|(
name|exstat
argument_list|)
expr_stmt|;
name|fnstcw
argument_list|(
operator|&
name|control
argument_list|)
expr_stmt|;
name|fnclex
argument_list|()
expr_stmt|;
comment|/* 	 * Pass exception to process. 	 */
name|frame
operator|=
operator|(
expr|struct
name|intrframe
operator|*
operator|)
operator|&
name|dummy
expr_stmt|;
comment|/* XXX */
if|if
condition|(
operator|(
name|ISPL
argument_list|(
name|frame
operator|->
name|if_cs
argument_list|)
operator|==
name|SEL_UPL
operator|)
operator|||
operator|(
name|frame
operator|->
name|if_eflags
operator|&
name|PSL_VM
operator|)
condition|)
block|{
comment|/* 		 * Interrupt is essentially a trap, so we can afford to call 		 * the SIGFPE handler (if any) as soon as the interrupt 		 * returns. 		 * 		 * XXX little or nothing is gained from this, and plenty is 		 * lost - the interrupt frame has to contain the trap frame 		 * (this is otherwise only necessary for the rescheduling trap 		 * in doreti, and the frame for that could easily be set up 		 * just before it is used). 		 */
name|curproc
operator|->
name|p_md
operator|.
name|md_regs
operator|=
name|INTR_TO_TRAPFRAME
argument_list|(
name|frame
argument_list|)
expr_stmt|;
comment|/* 		 * Encode the appropriate code for detailed information on 		 * this exception. 		 */
name|code
operator|=
name|fpetable
index|[
operator|(
operator|*
name|exstat
operator|&
operator|~
name|control
operator|&
literal|0x3f
operator|)
operator||
operator|(
operator|*
name|exstat
operator|&
literal|0x40
operator|)
index|]
expr_stmt|;
name|trapsignal
argument_list|(
name|curproc
argument_list|,
name|SIGFPE
argument_list|,
name|code
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* 		 * Nested interrupt.  These losers occur when: 		 *	o an IRQ13 is bogusly generated at a bogus time, e.g.: 		 *		o immediately after an fnsave or frstor of an 		 *		  error state. 		 *		o a couple of 386 instructions after 		 *		  "fstpl _memvar" causes a stack overflow. 		 *	  These are especially nasty when combined with a 		 *	  trace trap. 		 *	o an IRQ13 occurs at the same time as another higher- 		 *	  priority interrupt. 		 * 		 * Treat them like a true async interrupt. 		 */
name|psignal
argument_list|(
name|curproc
argument_list|,
name|SIGFPE
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Implement device not available (DNA) exception  *  * It would be better to switch FP context here (if curproc != npxproc)  * and not necessarily for every context switch, but it is too hard to  * access foreign pcb's.  */
end_comment

begin_function
name|int
name|npxdna
parameter_list|()
block|{
name|u_long
modifier|*
name|exstat
decl_stmt|;
if|if
condition|(
operator|!
name|npx_exists
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|npxproc
operator|!=
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"npxdna: npxproc = %p, curproc = %p\n"
argument_list|,
name|npxproc
argument_list|,
name|curproc
argument_list|)
expr_stmt|;
name|panic
argument_list|(
literal|"npxdna"
argument_list|)
expr_stmt|;
block|}
name|stop_emulating
argument_list|()
expr_stmt|;
comment|/* 	 * Record new context early in case frstor causes an IRQ13. 	 */
name|npxproc
operator|=
name|curproc
expr_stmt|;
name|exstat
operator|=
name|GET_FPU_EXSW_PTR
argument_list|(
name|curpcb
argument_list|)
expr_stmt|;
operator|*
name|exstat
operator|=
literal|0
expr_stmt|;
comment|/* 	 * The following frstor may cause an IRQ13 when the state being 	 * restored has a pending error.  The error will appear to have been 	 * triggered by the current (npx) user instruction even when that 	 * instruction is a no-wait instruction that should not trigger an 	 * error (e.g., fnclex).  On at least one 486 system all of the 	 * no-wait instructions are broken the same as frstor, so our 	 * treatment does not amplify the breakage.  On at least one 	 * 386/Cyrix 387 system, fnclex works correctly while frstor and 	 * fnsave are broken, so our treatment breaks fnclex if it is the 	 * first FPU instruction after a context switch. 	 */
name|fpurstor
argument_list|(
operator|&
name|curpcb
operator|->
name|pcb_save
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Wrapper for fnsave instruction to handle h/w bugs.  If there is an error  * pending, then fnsave generates a bogus IRQ13 on some systems.  Force  * any IRQ13 to be handled immediately, and then ignore it.  This routine is  * often called at splhigh so it must not use many system services.  In  * particular, it's much easier to install a special handler than to  * guarantee that it's safe to use npxintr() and its supporting code.  */
end_comment

begin_function
name|void
name|npxsave
parameter_list|(
name|addr
parameter_list|)
name|union
name|savefpu
modifier|*
name|addr
decl_stmt|;
block|{
if|#
directive|if
name|defined
argument_list|(
name|SMP
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_ENABLE_SSE
argument_list|)
name|stop_emulating
argument_list|()
expr_stmt|;
name|fpusave
argument_list|(
name|addr
argument_list|)
expr_stmt|;
comment|/* fnop(); */
name|start_emulating
argument_list|()
expr_stmt|;
name|npxproc
operator|=
name|NULL
expr_stmt|;
else|#
directive|else
comment|/* SMP or CPU_ENABLE_SSE */
name|u_char
name|icu1_mask
decl_stmt|;
name|u_char
name|icu2_mask
decl_stmt|;
name|u_char
name|old_icu1_mask
decl_stmt|;
name|u_char
name|old_icu2_mask
decl_stmt|;
name|struct
name|gate_descriptor
name|save_idt_npxintr
decl_stmt|;
name|disable_intr
argument_list|()
expr_stmt|;
name|old_icu1_mask
operator|=
name|inb
argument_list|(
name|IO_ICU1
operator|+
literal|1
argument_list|)
expr_stmt|;
name|old_icu2_mask
operator|=
name|inb
argument_list|(
name|IO_ICU2
operator|+
literal|1
argument_list|)
expr_stmt|;
name|save_idt_npxintr
operator|=
name|idt
index|[
name|npx_intrno
index|]
expr_stmt|;
name|outb
argument_list|(
name|IO_ICU1
operator|+
literal|1
argument_list|,
name|old_icu1_mask
operator|&
operator|~
operator|(
name|IRQ_SLAVE
operator||
name|npx0_imask
operator|)
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|IO_ICU2
operator|+
literal|1
argument_list|,
name|old_icu2_mask
operator|&
operator|~
operator|(
name|npx0_imask
operator|>>
literal|8
operator|)
argument_list|)
expr_stmt|;
name|idt
index|[
name|npx_intrno
index|]
operator|=
name|npx_idt_probeintr
expr_stmt|;
name|enable_intr
argument_list|()
expr_stmt|;
name|stop_emulating
argument_list|()
expr_stmt|;
name|fnsave
argument_list|(
name|addr
argument_list|)
expr_stmt|;
name|fnop
argument_list|()
expr_stmt|;
name|start_emulating
argument_list|()
expr_stmt|;
name|npxproc
operator|=
name|NULL
expr_stmt|;
name|disable_intr
argument_list|()
expr_stmt|;
name|icu1_mask
operator|=
name|inb
argument_list|(
name|IO_ICU1
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|/* masks may have changed */
name|icu2_mask
operator|=
name|inb
argument_list|(
name|IO_ICU2
operator|+
literal|1
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|IO_ICU1
operator|+
literal|1
argument_list|,
operator|(
name|icu1_mask
operator|&
operator|~
name|npx0_imask
operator|)
operator||
operator|(
name|old_icu1_mask
operator|&
name|npx0_imask
operator|)
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|IO_ICU2
operator|+
literal|1
argument_list|,
operator|(
name|icu2_mask
operator|&
operator|~
operator|(
name|npx0_imask
operator|>>
literal|8
operator|)
operator|)
operator||
operator|(
name|old_icu2_mask
operator|&
operator|(
name|npx0_imask
operator|>>
literal|8
operator|)
operator|)
argument_list|)
expr_stmt|;
name|idt
index|[
name|npx_intrno
index|]
operator|=
name|save_idt_npxintr
expr_stmt|;
name|enable_intr
argument_list|()
expr_stmt|;
comment|/* back to usual state */
endif|#
directive|endif
comment|/* SMP */
block|}
end_function

begin_function
specifier|static
name|void
name|fpusave
parameter_list|(
name|addr
parameter_list|)
name|union
name|savefpu
modifier|*
name|addr
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|CPU_ENABLE_SSE
if|if
condition|(
name|cpu_fxsr
condition|)
name|fxsave
argument_list|(
name|addr
argument_list|)
expr_stmt|;
else|else
endif|#
directive|endif
name|fnsave
argument_list|(
name|addr
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|fpurstor
parameter_list|(
name|addr
parameter_list|)
name|union
name|savefpu
modifier|*
name|addr
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|CPU_ENABLE_SSE
if|if
condition|(
name|cpu_fxsr
condition|)
name|fxrstor
argument_list|(
name|addr
argument_list|)
expr_stmt|;
else|else
endif|#
directive|endif
name|frstor
argument_list|(
name|addr
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|I586_CPU
end_ifdef

begin_function_decl
specifier|static
name|long
name|timezero
parameter_list|(
name|funcname
parameter_list|,
name|func
parameter_list|)
specifier|const
name|char
modifier|*
name|funcname
decl_stmt|;
function_decl|void
parameter_list|(
function_decl|*func
end_function_decl

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|void
operator|*
name|buf
operator|,
name|size_t
name|len
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|void
modifier|*
name|buf
decl_stmt|;
define|#
directive|define
name|BUFSIZE
value|1000000
name|long
name|usec
decl_stmt|;
name|struct
name|timeval
name|finish
decl_stmt|,
name|start
decl_stmt|;
name|buf
operator|=
name|malloc
argument_list|(
name|BUFSIZE
argument_list|,
name|M_TEMP
argument_list|,
name|M_NOWAIT
argument_list|)
expr_stmt|;
if|if
condition|(
name|buf
operator|==
name|NULL
condition|)
return|return
operator|(
name|BUFSIZE
operator|)
return|;
name|microtime
argument_list|(
operator|&
name|start
argument_list|)
expr_stmt|;
call|(
modifier|*
name|func
call|)
argument_list|(
name|buf
argument_list|,
name|BUFSIZE
argument_list|)
expr_stmt|;
name|microtime
argument_list|(
operator|&
name|finish
argument_list|)
expr_stmt|;
name|usec
operator|=
literal|1000000
operator|*
operator|(
name|finish
operator|.
name|tv_sec
operator|-
name|start
operator|.
name|tv_sec
operator|)
operator|+
name|finish
operator|.
name|tv_usec
operator|-
name|start
operator|.
name|tv_usec
expr_stmt|;
if|if
condition|(
name|usec
operator|<=
literal|0
condition|)
name|usec
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|bootverbose
condition|)
name|printf
argument_list|(
literal|"%s bandwidth = %ld bytes/sec\n"
argument_list|,
name|funcname
argument_list|,
call|(
name|long
call|)
argument_list|(
name|BUFSIZE
operator|*
operator|(
name|int64_t
operator|)
literal|1000000
operator|/
name|usec
argument_list|)
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|buf
argument_list|,
name|M_TEMP
argument_list|)
expr_stmt|;
return|return
operator|(
name|usec
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I586_CPU */
end_comment

begin_decl_stmt
specifier|static
name|device_method_t
name|npx_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_identify
argument_list|,
name|npx_identify
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|npx_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|npx_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|bus_generic_detach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_shutdown
argument_list|,
name|bus_generic_shutdown
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_suspend
argument_list|,
name|bus_generic_suspend
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_resume
argument_list|,
name|bus_generic_resume
argument_list|)
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|npx_driver
init|=
block|{
literal|"npx"
block|,
name|npx_methods
block|,
literal|1
block|,
comment|/* no softc */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|npx_devclass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * We prefer to attach to the root nexus so that the usual case (exception 16)  * doesn't describe the processor as being `on isa'.  */
end_comment

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|npx
argument_list|,
name|nexus
argument_list|,
name|npx_driver
argument_list|,
name|npx_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

