begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996, by Steve Passe  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the developer may NOT be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SMPTESTS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SMPTESTS_H_
end_define

begin_comment
comment|/*  * Various 'tests in progress' and configuration parameters.  */
end_comment

begin_comment
comment|/*  * Tor's clock improvements.  *  *  When the giant kernel lock disappears, a different strategy should  *  probably be used, thus this patch can only be considered a temporary  *  measure.  *  *  This patch causes (NCPU-1)*(128+100) extra IPIs per second.  *  During profiling, the number is (NCPU-1)*(1024+100) extra IPIs/s  *  in addition to extra IPIs due to forwarding ASTs to other CPUs.  *  *  Having a shared AST flag in an SMP configuration is wrong, and I've  *  just kludged around it, based upon the kernel lock blocking other  *  processors from entering the kernel while handling an AST for one  *  processor. When the giant kernel lock disappers, this kludge breaks.  *  *  -- Tor  */
end_comment

begin_define
define|#
directive|define
name|BETTER_CLOCK
end_define

begin_comment
comment|/*  * Control the "giant lock" pushdown by logical steps.  */
end_comment

begin_define
define|#
directive|define
name|PUSHDOWN_LEVEL_1
end_define

begin_define
define|#
directive|define
name|PUSHDOWN_LEVEL_2
end_define

begin_define
define|#
directive|define
name|PUSHDOWN_LEVEL_3_NOT
end_define

begin_define
define|#
directive|define
name|PUSHDOWN_LEVEL_4_NOT
end_define

begin_comment
comment|/*  * Debug version of simple_lock.  This will store the CPU id of the  * holding CPU along with the lock.  When a CPU fails to get the lock  * it compares its own id to the holder id.  If they are the same it  * panic()s, as simple locks are binary, and this would cause a deadlock.  *  */
end_comment

begin_define
define|#
directive|define
name|SL_DEBUG
end_define

begin_comment
comment|/*  * Put FAST_INTR() ISRs at an APIC priority above the regular INTs.  * Allow the mp_lock() routines to handle FAST interrupts while spinning.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PUSHDOWN_LEVEL_1
end_ifdef

begin_define
define|#
directive|define
name|FAST_HI
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * These defines enable critical region locking of areas that were  * protected via cli/sti in the UP kernel.  *  * MPINTRLOCK protects all the generic areas.  * COMLOCK protects the sio/cy drivers.  * CLOCKLOCK protects clock hardware and data  * known to be incomplete:  *	joystick lkm  *	?  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PUSHDOWN_LEVEL_1
end_ifdef

begin_define
define|#
directive|define
name|USE_MPINTRLOCK
end_define

begin_define
define|#
directive|define
name|USE_COMLOCK
end_define

begin_define
define|#
directive|define
name|USE_CLOCKLOCK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * INTR_SIMPLELOCK has been removed, as the interrupt mechanism will likely  * not use this sort of optimization if we move to interrupt threads.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PUSHDOWN_LEVEL_4
end_ifdef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * CPL_AND_CML has been removed.  Interrupt threads will eventually not  * use either mechanism so there is no point trying to optimize it.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PUSHDOWN_LEVEL_3
end_ifdef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * SPL_DEBUG_POSTCODE/INTR_SPL/SPL_DEBUG - removed  *  * These functions were too expensive for the standard case but, more   * importantly, we should be able to come up with a much cleaner way  * to handle the cpl.  Having to do any locking at all is a mistake  * for something that is modified as often as cpl is.  */
end_comment

begin_comment
comment|/*  * FAST_WITHOUTCPL - now made the default (define removed).  Text below   * contains the current discussion.  I am confident we can find a solution  * that does not require us to process softints from a hard int, which can  * kill serial performance due to the lack of true hardware ipl's.  *  ****  *  * Ignore the ipending bits when exiting FAST_INTR() routines.  *  * according to Bruce:  *  * setsoft*() may set ipending.  setsofttty() is actually used in the  * FAST_INTR handler in some serial drivers.  This is necessary to get  * output completions and other urgent events handled as soon as possible.  * The flag(s) could be set in a variable other than ipending, but they  * needs to be checked against cpl to decide whether the software interrupt  * handler can/should run.  *  *  (FAST_INTR used to just return  * in all cases until rev.1.7 of vector.s.  This worked OK provided there  * were no user-mode CPU hogs.  CPU hogs caused an average latency of 1/2  * clock tick for output completions...)  ***  *  * So I need to restore cpl handling someday, but AFTER  *  I finish making spl/cpl MP-safe.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PUSHDOWN_LEVEL_1
end_ifdef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * FAST_SIMPLELOCK no longer exists, because it doesn't help us.  The cpu  * is likely to already hold the MP lock and recursive MP locks are now  * very cheap, so we do not need this optimization.  Eventually *ALL*   * interrupts will run in their own thread, so there is no sense complicating  * matters now.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PUSHDOWN_LEVEL_1
end_ifdef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Portions of the old TEST_LOPRIO code, back from the grave!  */
end_comment

begin_define
define|#
directive|define
name|GRAB_LOPRIO
end_define

begin_comment
comment|/*  * Send CPUSTOP IPI for stop/restart of other CPUs on DDB break.  * #define VERBOSE_CPUSTOP_ON_DDBBREAK  */
end_comment

begin_define
define|#
directive|define
name|CPUSTOP_ON_DDBBREAK
end_define

begin_comment
comment|/*  * Bracket code/comments relevant to the current 'giant lock' model.  * Everything is now the 'giant lock' model, but we will use this as  * we start to "push down" the lock.  */
end_comment

begin_define
define|#
directive|define
name|GIANT_LOCK
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|APIC_IO
end_ifdef

begin_comment
comment|/*  * Enable extra counters for some selected locations in the interrupt handlers.  * Look in apic_vector.s, apic_ipl.s and ipl.s for APIC_ITRACE or   * APIC_INTR_DIAGNOSTIC.  */
end_comment

begin_undef
undef|#
directive|undef
name|APIC_INTR_DIAGNOSTIC
end_undef

begin_comment
comment|/*  * Add extra tracking of a specific interrupt. Look in apic_vector.s,   * apic_ipl.s and ipl.s for APIC_ITRACE and log_intr_event.  * APIC_INTR_DIAGNOSTIC must be defined for this to work.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|APIC_INTR_DIAGNOSTIC
end_ifdef

begin_define
define|#
directive|define
name|APIC_INTR_DIAGNOSTIC_IRQ
value|17
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Don't assume that slow interrupt handler X is called from vector  * X + ICU_OFFSET.  */
end_comment

begin_define
define|#
directive|define
name|APIC_INTR_REORDER
end_define

begin_comment
comment|/*  * Redirect clock interrupts to a higher priority (fast intr) vector,  * while still using the slow interrupt handler. Only effective when   * APIC_INTR_REORDER is defined.  */
end_comment

begin_define
define|#
directive|define
name|APIC_INTR_HIGHPRI_CLOCK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APIC_IO */
end_comment

begin_comment
comment|/*  * Misc. counters.  * #define COUNT_XINVLTLB_HITS  */
end_comment

begin_comment
comment|/**  * Hack to "fake-out" kernel into thinking it is running on a 'default config'.  *  * value == default type #define TEST_DEFAULT_CONFIG	6  */
end_comment

begin_comment
comment|/*  * Simple test code for IPI interaction, save for future...  * #define TEST_TEST1 #define IPI_TARGET_TEST1	1  */
end_comment

begin_comment
comment|/*  * Address of POST hardware port.  * Defining this enables POSTCODE macros.  * #define POST_ADDR		0x80  */
end_comment

begin_comment
comment|/*  * POST hardware macros.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|POST_ADDR
end_ifdef

begin_define
define|#
directive|define
name|ASMPOSTCODE_INC
define|\
value|pushl	%eax ;				\ 	movl	_current_postcode, %eax ;	\ 	incl	%eax ;				\ 	andl	$0xff, %eax ;			\ 	movl	%eax, _current_postcode ;	\ 	outb	%al, $POST_ADDR ;		\ 	popl	%eax
end_define

begin_comment
comment|/*  * Overwrite the current_postcode value.  */
end_comment

begin_define
define|#
directive|define
name|ASMPOSTCODE
parameter_list|(
name|X
parameter_list|)
define|\
value|pushl	%eax ;				\ 	movl	$X, %eax ;			\ 	movl	%eax, _current_postcode ;	\ 	outb	%al, $POST_ADDR ;		\ 	popl	%eax
end_define

begin_comment
comment|/*  * Overwrite the current_postcode low nibble.  */
end_comment

begin_define
define|#
directive|define
name|ASMPOSTCODE_LO
parameter_list|(
name|X
parameter_list|)
define|\
value|pushl	%eax ;				\ 	movl	_current_postcode, %eax ;	\ 	andl	$0xf0, %eax ;			\ 	orl	$X, %eax ;			\ 	movl	%eax, _current_postcode ;	\ 	outb	%al, $POST_ADDR ;		\ 	popl	%eax
end_define

begin_comment
comment|/*  * Overwrite the current_postcode high nibble.  */
end_comment

begin_define
define|#
directive|define
name|ASMPOSTCODE_HI
parameter_list|(
name|X
parameter_list|)
define|\
value|pushl	%eax ;				\ 	movl	_current_postcode, %eax ;	\ 	andl	$0x0f, %eax ;			\ 	orl	$(X<<4), %eax ;			\ 	movl	%eax, _current_postcode ;	\ 	outb	%al, $POST_ADDR ;		\ 	popl	%eax
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASMPOSTCODE_INC
end_define

begin_define
define|#
directive|define
name|ASMPOSTCODE
parameter_list|(
name|X
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ASMPOSTCODE_LO
parameter_list|(
name|X
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ASMPOSTCODE_HI
parameter_list|(
name|X
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POST_ADDR */
end_comment

begin_comment
comment|/*  * These are all temps for debugging...  * #define GUARD_INTS  */
end_comment

begin_comment
comment|/*  * This macro traps unexpected INTs to a specific CPU, eg. GUARD_CPU.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GUARD_INTS
end_ifdef

begin_define
define|#
directive|define
name|GUARD_CPU
value|1
end_define

begin_define
define|#
directive|define
name|MAYBE_PANIC
parameter_list|(
name|irq_num
parameter_list|)
define|\
value|cmpl	$GUARD_CPU, _cpuid ;	\ 	jne	9f ;			\ 	cmpl	$1, _ok_test1 ;		\ 	jne	9f ;			\ 	pushl	lapic_isr3 ;		\ 	pushl	lapic_isr2 ;		\ 	pushl	lapic_isr1 ;		\ 	pushl	lapic_isr0 ;		\ 	pushl	lapic_irr3 ;		\ 	pushl	lapic_irr2 ;		\ 	pushl	lapic_irr1 ;		\ 	pushl	lapic_irr0 ;		\ 	pushl	$irq_num ;		\ 	pushl	_cpuid ;		\ 	pushl	$panic_msg ;		\ 	call	_printf ;		\ 	addl	$44, %esp ;		\ 9:
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAYBE_PANIC
parameter_list|(
name|irq_num
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GUARD_INTS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_SMPTESTS_H_ */
end_comment

end_unit

