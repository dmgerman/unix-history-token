begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 William Jolitz.  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)npx.c	7.2 (Berkeley) 5/12/91  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"opt_debug_npx.h"
end_include

begin_include
include|#
directive|include
file|"opt_isa.h"
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
file|<sys/lock.h>
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
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
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

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

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

begin_include
include|#
directive|include
file|<machine/ucontext.h>
end_include

begin_include
include|#
directive|include
file|<amd64/isa/intr_machdep.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEV_ISA
end_ifdef

begin_include
include|#
directive|include
file|<isa/isavar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * 387 and 287 Numeric Coprocessor Extension (NPX) Driver.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

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

begin_function_decl
name|void
name|fldcw
parameter_list|(
name|caddr_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fnclex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fninit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fnstcw
parameter_list|(
name|caddr_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fnstsw
parameter_list|(
name|caddr_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fxsave
parameter_list|(
name|caddr_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fxrstor
parameter_list|(
name|caddr_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|start_emulating
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stop_emulating
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|GET_FPU_CW
parameter_list|(
name|thread
parameter_list|)
value|((thread)->td_pcb->pcb_save.sv_env.en_cw)
end_define

begin_define
define|#
directive|define
name|GET_FPU_SW
parameter_list|(
name|thread
parameter_list|)
value|((thread)->td_pcb->pcb_save.sv_env.en_sw)
end_define

begin_typedef
typedef|typedef
name|u_char
name|bool_t
typedef|;
end_typedef

begin_function_decl
specifier|static
name|int
name|npx_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|npx_identify
parameter_list|(
name|driver_t
modifier|*
name|driver
parameter_list|,
name|device_t
name|parent
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|npx_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|hw_float
init|=
literal|1
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|static
name|struct
name|savefpu
name|npx_cleanstate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool_t
name|npx_cleanstate_ready
decl_stmt|;
end_decl_stmt

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
comment|/*  * Probe routine.  Initialize cr0 to give correct behaviour for [f]wait  * whether the device exists or not (XXX should be elsewhere).  * Modify device struct if npx doesn't need to use interrupts.  * Return 0 if device exists.  */
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
comment|/* 	 * Finish resetting the coprocessor. 	 */
name|fninit
argument_list|()
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
block|}
end_function

begin_comment
comment|/*  * Attach routine - announce which it is, and wire into system  */
end_comment

begin_function
specifier|static
name|int
name|npx_attach
parameter_list|(
name|dev
parameter_list|)
name|device_t
name|dev
decl_stmt|;
block|{
name|register_t
name|s
decl_stmt|;
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"INT 16 interface\n"
argument_list|)
expr_stmt|;
name|npxinit
argument_list|(
name|__INITIAL_NPXCW__
argument_list|)
expr_stmt|;
if|if
condition|(
name|npx_cleanstate_ready
operator|==
literal|0
condition|)
block|{
name|s
operator|=
name|intr_disable
argument_list|()
expr_stmt|;
name|stop_emulating
argument_list|()
expr_stmt|;
name|fxsave
argument_list|(
operator|&
name|npx_cleanstate
argument_list|)
expr_stmt|;
name|start_emulating
argument_list|()
expr_stmt|;
name|npx_cleanstate_ready
operator|=
literal|1
expr_stmt|;
name|intr_restore
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
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
name|struct
name|savefpu
name|dummy
decl_stmt|;
name|register_t
name|savecrit
decl_stmt|;
comment|/* 	 * fninit has the same h/w bugs as fnsave.  Use the detoxified 	 * fnsave to throw away any junk in the fpu.  npxsave() initializes 	 * the fpu and sets fpcurthread = NULL as important side effects. 	 */
name|savecrit
operator|=
name|intr_disable
argument_list|()
expr_stmt|;
name|npxsave
argument_list|(
operator|&
name|dummy
argument_list|)
expr_stmt|;
name|stop_emulating
argument_list|()
expr_stmt|;
comment|/* XXX npxsave() doesn't actually initialize the fpu in the SSE case. */
name|fninit
argument_list|()
expr_stmt|;
name|fldcw
argument_list|(
operator|&
name|control
argument_list|)
expr_stmt|;
name|start_emulating
argument_list|()
expr_stmt|;
name|intr_restore
argument_list|(
name|savecrit
argument_list|)
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
name|td
parameter_list|)
name|struct
name|thread
modifier|*
name|td
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|NPX_DEBUG
name|u_int
name|masked_exceptions
decl_stmt|;
endif|#
directive|endif
name|register_t
name|savecrit
decl_stmt|;
name|savecrit
operator|=
name|intr_disable
argument_list|()
expr_stmt|;
if|if
condition|(
name|curthread
operator|==
name|PCPU_GET
argument_list|(
name|fpcurthread
argument_list|)
condition|)
name|npxsave
argument_list|(
operator|&
name|PCPU_GET
argument_list|(
name|curpcb
argument_list|)
operator|->
name|pcb_save
argument_list|)
expr_stmt|;
name|intr_restore
argument_list|(
name|savecrit
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|NPX_DEBUG
name|masked_exceptions
operator|=
name|GET_FPU_CW
argument_list|(
name|td
argument_list|)
operator|&
name|GET_FPU_SW
argument_list|(
name|td
argument_list|)
operator|&
literal|0x7f
expr_stmt|;
comment|/* 	 * Log exceptions that would have trapped with the old 	 * control word (overflow, divide by 0, and invalid operand). 	 */
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
name|td
operator|->
name|td_proc
operator|->
name|p_pid
argument_list|,
name|td
operator|->
name|td_proc
operator|->
name|p_comm
argument_list|,
name|masked_exceptions
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
name|int
name|npxformat
parameter_list|()
block|{
return|return
operator|(
name|_MC_FPFMT_XMM
operator|)
return|;
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
name|int
name|npxtrap
parameter_list|()
block|{
name|register_t
name|savecrit
decl_stmt|;
name|u_short
name|control
decl_stmt|,
name|status
decl_stmt|;
name|savecrit
operator|=
name|intr_disable
argument_list|()
expr_stmt|;
comment|/* 	 * Interrupt handling (for another interrupt) may have pushed the 	 * state to memory.  Fetch the relevant parts of the state from 	 * wherever they are. 	 */
if|if
condition|(
name|PCPU_GET
argument_list|(
name|fpcurthread
argument_list|)
operator|!=
name|curthread
condition|)
block|{
name|control
operator|=
name|GET_FPU_CW
argument_list|(
name|curthread
argument_list|)
expr_stmt|;
name|status
operator|=
name|GET_FPU_SW
argument_list|(
name|curthread
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|fnstcw
argument_list|(
operator|&
name|control
argument_list|)
expr_stmt|;
name|fnstsw
argument_list|(
operator|&
name|status
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|PCPU_GET
argument_list|(
name|fpcurthread
argument_list|)
operator|==
name|curthread
condition|)
name|fnclex
argument_list|()
expr_stmt|;
name|intr_restore
argument_list|(
name|savecrit
argument_list|)
expr_stmt|;
return|return
operator|(
name|fpetable
index|[
name|status
operator|&
operator|(
operator|(
operator|~
name|control
operator|&
literal|0x3f
operator|)
operator||
literal|0x40
operator|)
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Implement device not available (DNA) exception  *  * It would be better to switch FP context here (if curthread != fpcurthread)  * and not necessarily for every context switch, but it is too hard to  * access foreign pcb's.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|err_count
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|npxdna
parameter_list|()
block|{
name|struct
name|pcb
modifier|*
name|pcb
decl_stmt|;
name|register_t
name|s
decl_stmt|;
name|u_short
name|control
decl_stmt|;
if|if
condition|(
name|PCPU_GET
argument_list|(
name|fpcurthread
argument_list|)
operator|==
name|curthread
condition|)
block|{
name|printf
argument_list|(
literal|"npxdna: fpcurthread == curthread %d times\n"
argument_list|,
operator|++
name|err_count
argument_list|)
expr_stmt|;
name|stop_emulating
argument_list|()
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|PCPU_GET
argument_list|(
name|fpcurthread
argument_list|)
operator|!=
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"npxdna: fpcurthread = %p (%d), curthread = %p (%d)\n"
argument_list|,
name|PCPU_GET
argument_list|(
name|fpcurthread
argument_list|)
argument_list|,
name|PCPU_GET
argument_list|(
name|fpcurthread
argument_list|)
operator|->
name|td_proc
operator|->
name|p_pid
argument_list|,
name|curthread
argument_list|,
name|curthread
operator|->
name|td_proc
operator|->
name|p_pid
argument_list|)
expr_stmt|;
name|panic
argument_list|(
literal|"npxdna"
argument_list|)
expr_stmt|;
block|}
name|s
operator|=
name|intr_disable
argument_list|()
expr_stmt|;
name|stop_emulating
argument_list|()
expr_stmt|;
comment|/* 	 * Record new context early in case frstor causes an IRQ13. 	 */
name|PCPU_SET
argument_list|(
name|fpcurthread
argument_list|,
name|curthread
argument_list|)
expr_stmt|;
name|pcb
operator|=
name|PCPU_GET
argument_list|(
name|curpcb
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|pcb
operator|->
name|pcb_flags
operator|&
name|PCB_NPXINITDONE
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* 		 * This is the first time this thread has used the FPU or 		 * the PCB doesn't contain a clean FPU state.  Explicitly 		 * initialize the FPU and load the default control word. 		 */
name|fninit
argument_list|()
expr_stmt|;
name|control
operator|=
name|__INITIAL_NPXCW__
expr_stmt|;
name|fldcw
argument_list|(
operator|&
name|control
argument_list|)
expr_stmt|;
name|pcb
operator|->
name|pcb_flags
operator||=
name|PCB_NPXINITDONE
expr_stmt|;
block|}
else|else
block|{
comment|/* 		 * The following frstor may cause a trap when the state 		 * being restored has a pending error.  The error will 		 * appear to have been triggered by the current (npx) user 		 * instruction even when that instruction is a no-wait 		 * instruction that should not trigger an error (e.g., 		 * instructions are broken the same as frstor, so our 		 * treatment does not amplify the breakage. 		 */
name|fxrstor
argument_list|(
operator|&
name|pcb
operator|->
name|pcb_save
argument_list|)
expr_stmt|;
block|}
name|intr_restore
argument_list|(
name|s
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
comment|/*  * Wrapper for fnsave instruction, partly to handle hardware bugs.  When npx  * exceptions are reported via IRQ13, spurious IRQ13's may be triggered by  * no-wait npx instructions.  See the Intel application note AP-578 for  * details.  This doesn't cause any additional complications here.  IRQ13's  * are inherently asynchronous unless the CPU is frozen to deliver them --  * one that started in userland may be delivered many instructions later,  * after the process has entered the kernel.  It may even be delivered after  * the fnsave here completes.  A spurious IRQ13 for the fnsave is handled in  * the same way as a very-late-arriving non-spurious IRQ13 from user mode:  * it is normally ignored at first because we set fpcurthread to NULL; it is  * normally retriggered in npxdna() after return to user mode.  *  * npxsave() must be called with interrupts disabled, so that it clears  * fpcurthread atomically with saving the state.  We require callers to do the  * disabling, since most callers need to disable interrupts anyway to call  * npxsave() atomically with checking fpcurthread.  *  * A previous version of npxsave() went to great lengths to excecute fnsave  * with interrupts enabled in case executing it froze the CPU.  This case  * can't happen, at least for Intel CPU/NPX's.  Spurious IRQ13's don't imply  * spurious freezes.  */
end_comment

begin_function
name|void
name|npxsave
parameter_list|(
name|addr
parameter_list|)
name|struct
name|savefpu
modifier|*
name|addr
decl_stmt|;
block|{
name|stop_emulating
argument_list|()
expr_stmt|;
name|fxsave
argument_list|(
name|addr
argument_list|)
expr_stmt|;
name|start_emulating
argument_list|()
expr_stmt|;
name|PCPU_SET
argument_list|(
name|fpcurthread
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * This should be called with interrupts disabled and only when the owning  * FPU thread is non-null.  */
end_comment

begin_function
name|void
name|npxdrop
parameter_list|()
block|{
name|struct
name|thread
modifier|*
name|td
decl_stmt|;
name|td
operator|=
name|PCPU_GET
argument_list|(
name|fpcurthread
argument_list|)
expr_stmt|;
name|PCPU_SET
argument_list|(
name|fpcurthread
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|td
operator|->
name|td_pcb
operator|->
name|pcb_flags
operator|&=
operator|~
name|PCB_NPXINITDONE
expr_stmt|;
name|start_emulating
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Get the state of the FPU without dropping ownership (if possible).  * It returns the FPU ownership status.  */
end_comment

begin_function
name|int
name|npxgetregs
parameter_list|(
name|td
parameter_list|,
name|addr
parameter_list|)
name|struct
name|thread
modifier|*
name|td
decl_stmt|;
name|struct
name|savefpu
modifier|*
name|addr
decl_stmt|;
block|{
name|register_t
name|s
decl_stmt|;
if|if
condition|(
operator|(
name|td
operator|->
name|td_pcb
operator|->
name|pcb_flags
operator|&
name|PCB_NPXINITDONE
operator|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|npx_cleanstate_ready
condition|)
name|bcopy
argument_list|(
operator|&
name|npx_cleanstate
argument_list|,
name|addr
argument_list|,
sizeof|sizeof
argument_list|(
name|npx_cleanstate
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|bzero
argument_list|(
name|addr
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|addr
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|_MC_FPOWNED_NONE
operator|)
return|;
block|}
name|s
operator|=
name|intr_disable
argument_list|()
expr_stmt|;
if|if
condition|(
name|td
operator|==
name|PCPU_GET
argument_list|(
name|fpcurthread
argument_list|)
condition|)
block|{
name|fxsave
argument_list|(
name|addr
argument_list|)
expr_stmt|;
name|intr_restore
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
name|_MC_FPOWNED_FPU
operator|)
return|;
block|}
else|else
block|{
name|intr_restore
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
operator|&
name|td
operator|->
name|td_pcb
operator|->
name|pcb_save
argument_list|,
name|addr
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|addr
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|_MC_FPOWNED_PCB
operator|)
return|;
block|}
block|}
end_function

begin_comment
comment|/*  * Set the state of the FPU.  */
end_comment

begin_function
name|void
name|npxsetregs
parameter_list|(
name|td
parameter_list|,
name|addr
parameter_list|)
name|struct
name|thread
modifier|*
name|td
decl_stmt|;
name|struct
name|savefpu
modifier|*
name|addr
decl_stmt|;
block|{
name|register_t
name|s
decl_stmt|;
name|s
operator|=
name|intr_disable
argument_list|()
expr_stmt|;
if|if
condition|(
name|td
operator|==
name|PCPU_GET
argument_list|(
name|fpcurthread
argument_list|)
condition|)
block|{
name|fxrstor
argument_list|(
name|addr
argument_list|)
expr_stmt|;
name|intr_restore
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|intr_restore
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
name|addr
argument_list|,
operator|&
name|td
operator|->
name|td_pcb
operator|->
name|pcb_save
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|addr
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|curthread
operator|->
name|td_pcb
operator|->
name|pcb_flags
operator||=
name|PCB_NPXINITDONE
expr_stmt|;
block|}
end_function

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

begin_ifdef
ifdef|#
directive|ifdef
name|DEV_ISA
end_ifdef

begin_comment
comment|/*  * This sucks up the legacy ISA support assignments from PNPBIOS/ACPI.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|isa_pnp_id
name|npxisa_ids
index|[]
init|=
block|{
block|{
literal|0x040cd041
block|,
literal|"Legacy ISA coprocessor support"
block|}
block|,
comment|/* PNP0C04 */
block|{
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|npxisa_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|int
name|result
decl_stmt|;
if|if
condition|(
operator|(
name|result
operator|=
name|ISA_PNP_PROBE
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|npxisa_ids
argument_list|)
operator|)
operator|<=
literal|0
condition|)
block|{
name|device_quiet
argument_list|(
name|dev
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|npxisa_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|npxisa_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|npxisa_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|npxisa_attach
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
name|npxisa_driver
init|=
block|{
literal|"npxisa"
block|,
name|npxisa_methods
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
name|npxisa_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|npxisa
argument_list|,
name|isa
argument_list|,
name|npxisa_driver
argument_list|,
name|npxisa_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|npxisa
argument_list|,
name|acpi
argument_list|,
name|npxisa_driver
argument_list|,
name|npxisa_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEV_ISA */
end_comment

end_unit

