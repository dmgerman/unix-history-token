begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996, by Steve Passe  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the developer may NOT be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: smptests.h,v 1.24 1997/08/29 07:23:37 smp Exp smp $  */
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
comment|/*  * Put FAST_INTR() ISRs at an APIC priority above the regular INTs.  * Allow the mp_lock() routines to handle FAST interrupts while spinning.  */
end_comment

begin_define
define|#
directive|define
name|FAST_HI
end_define

begin_comment
comment|/*  * Regular INTerrupts without the giant lock, NOT READY YET!!!  * #define INTR_SIMPLELOCK  */
end_comment

begin_comment
comment|/*  * Ignore the ipending bits when exiting FAST_INTR() routines.  *  ***  * according to Bruce:  *  * setsoft*() may set ipending.  setsofttty() is actually used in the  * FAST_INTR handler in some serial drivers.  This is necessary to get  * output completions and other urgent events handled as soon as possible.  * The flag(s) could be set in a variable other than ipending, but they  * needs to be checked against cpl to decide whether the software interrupt  * handler can/should run.  *  *  (FAST_INTR used to just return  * in all cases until rev.1.7 of vector.s.  This worked OK provided there  * were no user-mode CPU hogs.  CPU hogs caused an average latency of 1/2  * clock tick for output completions...)  ***  *  * So I need to restore cpl handling someday, but AFTER  *  I finish making spl/cpl MP-safe.  */
end_comment

begin_define
define|#
directive|define
name|FAST_WITHOUTCPL
end_define

begin_comment
comment|/*  * Use a simplelock to serialize FAST_INTR()s.  * sio.c, and probably other FAST_INTR() drivers, never expected several CPUs  * to be inside them at once.  Things such as global vars prevent more  * than 1 thread of execution from existing at once, so we serialize  * the access of FAST_INTR()s via a simple lock.  * One optimization on this would be a simple lock per DRIVER, but I'm  * not sure how to organize that yet...  */
end_comment

begin_define
define|#
directive|define
name|FAST_SIMPLELOCK
end_define

begin_comment
comment|/*  * Portions of the old TEST_LOPRIO code, back from the grave!  */
end_comment

begin_define
define|#
directive|define
name|GRAB_LOPRIO
end_define

begin_comment
comment|/*  * Send CPUSTOP IPI for stop/restart of other CPUs on DDB break.  *  */
end_comment

begin_define
define|#
directive|define
name|CPUSTOP_ON_DDBBREAK
end_define

begin_define
define|#
directive|define
name|VERBOSE_CPUSTOP_ON_DDBBREAK
end_define

begin_comment
comment|/*  * Bracket code/comments relevant to the current 'giant lock' model.  * Everything is now the 'giant lock' model, but we will use this as  * we start to "push down" the lock.  */
end_comment

begin_define
define|#
directive|define
name|GIANT_LOCK
end_define

begin_comment
comment|/*  * Deal with broken smp_idleloop().  */
end_comment

begin_define
define|#
directive|define
name|IGNORE_IDLEPROCS
end_define

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

