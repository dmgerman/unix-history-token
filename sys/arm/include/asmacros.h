begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: frame.h,v 1.6 2003/10/05 19:44:58 matt Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1994-1997 Mark Brinicombe.  * Copyright (c) 1994 Brini.  * All rights reserved.  *  * This code is derived from software written for Brini by Mark Brinicombe  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Brini.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BRINI ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL BRINI OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ASMACROS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ASMACROS_H_
end_define

begin_include
include|#
directive|include
file|<machine/asm.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|LOCORE
end_ifdef

begin_include
include|#
directive|include
file|"opt_global.h"
end_include

begin_comment
comment|/*  * ASM macros for pushing and pulling trapframes from the stack  *  * These macros are used to handle the irqframe and trapframe structures  * defined above.  */
end_comment

begin_comment
comment|/*  * PUSHFRAME - macro to push a trap frame on the stack in the current mode  * Since the current mode is used, the SVC lr field is not defined.  *  * NOTE: r13 and r14 are stored separately as a work around for the  * SA110 rev 2 STM^ bug  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ARM_TP_ADDRESS
end_ifdef

begin_define
define|#
directive|define
name|PUSHFRAME
define|\
value|sub	sp, sp, #4;
comment|/* Align the stack */
value|\ 	str	lr, [sp, #-4]!;
comment|/* Push the return address */
value|\ 	sub	sp, sp, #(4*17);
comment|/* Adjust the stack pointer */
value|\ 	stmia	sp, {r0-r12};
comment|/* Push the user mode registers */
value|\ 	add	r0, sp, #(4*13);
comment|/* Adjust the stack pointer */
value|\ 	stmia	r0, {r13-r14}^;
comment|/* Push the user mode registers */
value|\         mov     r0, r0;
comment|/* NOP for previous instruction */
value|\ 	mrs	r0, spsr;
comment|/* Put the SPSR on the stack */
value|\ 	str	r0, [sp, #-4]!;						   \ 	ldr	r0, =ARM_RAS_START;					   \ 	mov	r1, #0;							   \ 	str	r1, [r0];						   \ 	mov	r1, #0xffffffff;					   \ 	str	r1, [r0, #4];
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PUSHFRAME
define|\
value|sub	sp, sp, #4;
comment|/* Align the stack */
value|\ 	str	lr, [sp, #-4]!;
comment|/* Push the return address */
value|\ 	sub	sp, sp, #(4*17);
comment|/* Adjust the stack pointer */
value|\ 	stmia	sp, {r0-r12};
comment|/* Push the user mode registers */
value|\ 	add	r0, sp, #(4*13);
comment|/* Adjust the stack pointer */
value|\ 	stmia	r0, {r13-r14}^;
comment|/* Push the user mode registers */
value|\         mov     r0, r0;
comment|/* NOP for previous instruction */
value|\ 	mrs	r0, spsr;
comment|/* Put the SPSR on the stack */
value|\ 	str	r0, [sp, #-4]!;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * PULLFRAME - macro to pull a trap frame from the stack in the current mode  * Since the current mode is used, the SVC lr field is ignored.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ARM_TP_ADDRESS
end_ifdef

begin_define
define|#
directive|define
name|PULLFRAME
define|\
value|ldr     r0, [sp], #0x0004;
comment|/* Get the SPSR from stack */
value|\         msr     spsr_fsxc, r0;						   \         ldmia   sp, {r0-r14}^;
comment|/* Restore registers (usr mode) */
value|\         mov     r0, r0;
comment|/* NOP for previous instruction */
value|\ 	add	sp, sp, #(4*17);
comment|/* Adjust the stack pointer */
value|\  	ldr	lr, [sp], #0x0004;
comment|/* Pull the return address */
value|\ 	add	sp, sp, #4
end_define

begin_comment
comment|/* Align the stack */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PULLFRAME
define|\
value|ldr     r0, [sp], #0x0004;
comment|/* Get the SPSR from stack */
value|\         msr     spsr_fsxc, r0;						   \ 	clrex;								   \         ldmia   sp, {r0-r14}^;
comment|/* Restore registers (usr mode) */
value|\         mov     r0, r0;
comment|/* NOP for previous instruction */
value|\ 	add	sp, sp, #(4*17);
comment|/* Adjust the stack pointer */
value|\  	ldr	lr, [sp], #0x0004;
comment|/* Pull the return address */
value|\ 	add	sp, sp, #4
end_define

begin_comment
comment|/* Align the stack */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * PUSHFRAMEINSVC - macro to push a trap frame on the stack in SVC32 mode  * This should only be used if the processor is not currently in SVC32  * mode. The processor mode is switched to SVC mode and the trap frame is  * stored. The SVC lr field is used to store the previous value of  * lr in SVC mode.  *  * NOTE: r13 and r14 are stored separately as a work around for the  * SA110 rev 2 STM^ bug  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ARM_TP_ADDRESS
end_ifdef

begin_define
define|#
directive|define
name|PUSHFRAMEINSVC
define|\
value|stmdb	sp, {r0-r3};
comment|/* Save 4 registers */
value|\ 	mov	r0, lr;
comment|/* Save xxx32 r14 */
value|\ 	mov	r1, sp;
comment|/* Save xxx32 sp */
value|\ 	mrs	r3, spsr;
comment|/* Save xxx32 spsr */
value|\ 	mrs     r2, cpsr;
comment|/* Get the CPSR */
value|\ 	bic     r2, r2, #(PSR_MODE);
comment|/* Fix for SVC mode */
value|\ 	orr     r2, r2, #(PSR_SVC32_MODE);				   \ 	msr     cpsr_c, r2;
comment|/* Punch into SVC mode */
value|\ 	mov	r2, sp;
comment|/* Save	SVC sp */
value|\ 	bic	sp, sp, #7;
comment|/* Align sp to an 8-byte addrress */
value|\ 	sub	sp, sp, #4;
comment|/* Pad trapframe to keep alignment */
value|\ 	str	r0, [sp, #-4]!;
comment|/* Push return address */
value|\ 	str	lr, [sp, #-4]!;
comment|/* Push SVC lr */
value|\ 	str	r2, [sp, #-4]!;
comment|/* Push SVC sp */
value|\ 	msr     spsr_fsxc, r3;
comment|/* Restore correct spsr */
value|\ 	ldmdb	r1, {r0-r3};
comment|/* Restore 4 regs from xxx mode */
value|\ 	sub	sp, sp, #(4*15);
comment|/* Adjust the stack pointer */
value|\ 	stmia	sp, {r0-r12};
comment|/* Push the user mode registers */
value|\ 	add	r0, sp, #(4*13);
comment|/* Adjust the stack pointer */
value|\ 	stmia	r0, {r13-r14}^;
comment|/* Push the user mode registers */
value|\         mov     r0, r0;
comment|/* NOP for previous instruction */
value|\ 	ldr	r5, =ARM_RAS_START;
comment|/* Check if there's any RAS */
value|\ 	ldr     r4, [r5, #4];
comment|/* reset it to point at the     */
value|\ 	cmp     r4, #0xffffffff;
comment|/* end of memory if necessary;  */
value|\ 	movne   r1, #0xffffffff;
comment|/* leave value in r4 for later  */
value|\ 	strne   r1, [r5, #4];
comment|/* comparision against PC.      */
value|\ 	ldr     r3, [r5];
comment|/* Retrieve global RAS_START    */
value|\ 	cmp     r3, #0;
comment|/* and reset it if non-zero.    */
value|\ 	movne   r1, #0;
comment|/* If non-zero RAS_START and    */
value|\ 	strne   r1, [r5];
comment|/* PC was lower than RAS_END,   */
value|\ 	ldrne   r1, [r0, #16];
comment|/* adjust the saved PC so that  */
value|\ 	cmpne   r4, r1;
comment|/* execution later resumes at   */
value|\ 	strhi   r3, [r0, #16];
comment|/* the RAS_START location.      */
value|\ 	mrs     r0, spsr;                                              \ 	str     r0, [sp, #-4]!
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PUSHFRAMEINSVC
define|\
value|stmdb	sp, {r0-r3};
comment|/* Save 4 registers */
value|\ 	mov	r0, lr;
comment|/* Save xxx32 r14 */
value|\ 	mov	r1, sp;
comment|/* Save xxx32 sp */
value|\ 	mrs	r3, spsr;
comment|/* Save xxx32 spsr */
value|\ 	mrs     r2, cpsr;
comment|/* Get the CPSR */
value|\ 	bic     r2, r2, #(PSR_MODE);
comment|/* Fix for SVC mode */
value|\ 	orr     r2, r2, #(PSR_SVC32_MODE);				   \ 	msr     cpsr_c, r2;
comment|/* Punch into SVC mode */
value|\ 	mov	r2, sp;
comment|/* Save	SVC sp */
value|\ 	bic	sp, sp, #7;
comment|/* Align sp to an 8-byte addrress */
value|\ 	sub	sp, sp, #4;
comment|/* Pad trapframe to keep alignment */
value|\ 	str	r0, [sp, #-4]!;
comment|/* Push return address */
value|\ 	str	lr, [sp, #-4]!;
comment|/* Push SVC lr */
value|\ 	str	r2, [sp, #-4]!;
comment|/* Push SVC sp */
value|\ 	msr     spsr_fsxc, r3;
comment|/* Restore correct spsr */
value|\ 	ldmdb	r1, {r0-r3};
comment|/* Restore 4 regs from xxx mode */
value|\ 	sub	sp, sp, #(4*15);
comment|/* Adjust the stack pointer */
value|\ 	stmia	sp, {r0-r12};
comment|/* Push the user mode registers */
value|\ 	add	r0, sp, #(4*13);
comment|/* Adjust the stack pointer */
value|\ 	stmia	r0, {r13-r14}^;
comment|/* Push the user mode registers */
value|\         mov     r0, r0;
comment|/* NOP for previous instruction */
value|\ 	mrs	r0, spsr;
comment|/* Put the SPSR on the stack */
value|\ 	str	r0, [sp, #-4]!
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * PULLFRAMEFROMSVCANDEXIT - macro to pull a trap frame from the stack  * in SVC32 mode and restore the saved processor mode and PC.  * This should be used when the SVC lr register needs to be restored on  * exit.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ARM_TP_ADDRESS
end_ifdef

begin_define
define|#
directive|define
name|PULLFRAMEFROMSVCANDEXIT
define|\
value|ldr     r0, [sp], #0x0004;
comment|/* Get the SPSR from stack */
value|\         msr     spsr_fsxc, r0;
comment|/* restore SPSR */
value|\         ldmia   sp, {r0-r14}^;
comment|/* Restore registers (usr mode) */
value|\         mov     r0, r0;
comment|/* NOP for previous instruction */
value|\ 	add	sp, sp, #(4*15);
comment|/* Adjust the stack pointer */
value|\ 	ldmia	sp, {sp, lr, pc}^
end_define

begin_comment
comment|/* Restore lr and exit */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PULLFRAMEFROMSVCANDEXIT
define|\
value|ldr     r0, [sp], #0x0004;
comment|/* Get the SPSR from stack */
value|\         msr     spsr_fsxc, r0;
comment|/* restore SPSR */
value|\ 	clrex;								   \         ldmia   sp, {r0-r14}^;
comment|/* Restore registers (usr mode) */
value|\         mov     r0, r0;
comment|/* NOP for previous instruction */
value|\ 	add	sp, sp, #(4*15);
comment|/* Adjust the stack pointer */
value|\ 	ldmia	sp, {sp, lr, pc}^
end_define

begin_comment
comment|/* Restore lr and exit */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_EABI__
argument_list|)
end_if

begin_comment
comment|/*  * Unwind hints so we can unwind past functions that use  * PULLFRAMEFROMSVCANDEXIT. They are run in reverse order.  * As the last thing we do is restore the stack pointer  * we can ignore the padding at the end of struct trapframe.  */
end_comment

begin_define
define|#
directive|define
name|UNWINDSVCFRAME
define|\
value|.save {r13-r15};
comment|/* Restore sp, lr, pc */
value|\ 	.pad #(2*4);
comment|/* Skip user sp and lr */
value|\ 	.save {r0-r12};
comment|/* Restore r0-r12 */
value|\ 	.pad #(4)
end_define

begin_comment
comment|/* Skip spsr */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UNWINDSVCFRAME
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DATA
parameter_list|(
name|name
parameter_list|)
define|\
value|.data ; \ 	_ALIGN_DATA ; \ 	.globl	name ; \ 	.type	name, %object ; \ name:
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_ARM_ARCH_6
end_ifdef

begin_define
define|#
directive|define
name|AST_LOCALS
end_define

begin_define
define|#
directive|define
name|GET_CURTHREAD_PTR
parameter_list|(
name|tmp
parameter_list|)
define|\
value|mrc p15, 0, tmp, c13, c0, 4; \ 	add	tmp, tmp, #(PC_CURTHREAD)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AST_LOCALS
value|;\ .Lcurthread:								;\ 	.word	_C_LABEL(__pcpu) + PC_CURTHREAD
end_define

begin_define
define|#
directive|define
name|GET_CURTHREAD_PTR
parameter_list|(
name|tmp
parameter_list|)
define|\
value|ldr	tmp, .Lcurthread
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DO_AST
define|\
value|ldr	r0, [sp]
comment|/* Get the SPSR from stack */
value|;\ 	mrs	r4, cpsr
comment|/* save CPSR */
value|;\ 	orr	r1, r4, #(I32_bit|F32_bit)				;\ 	msr	cpsr_c, r1
comment|/* Disable interrupts */
value|;\ 	and	r0, r0, #(PSR_MODE)
comment|/* Returning to USR mode? */
value|;\ 	teq	r0, #(PSR_USR32_MODE)					;\ 	bne	2f
comment|/* Nope, get out now */
value|;\ 	bic	r4, r4, #(I32_bit|F32_bit)				;\ 1:	GET_CURTHREAD_PTR(r5)						;\ 	ldr	r5, [r5]						;\ 	ldr	r1, [r5, #(TD_FLAGS)]					;\ 	and	r1, r1, #(TDF_ASTPENDING|TDF_NEEDRESCHED)		;\ 	teq	r1, #0x00000000						;\ 	beq	2f
comment|/* Nope. Just bail */
value|;\ 	msr	cpsr_c, r4
comment|/* Restore interrupts */
value|;\ 	mov	r0, sp							;\ 	bl	_C_LABEL(ast)
comment|/* ast(frame) */
value|;\ 	orr	r0, r4, #(I32_bit|F32_bit)				;\ 	msr	cpsr_c, r0						;\ 	b	1b							;\ 2:
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ASMACROS_H_ */
end_comment

end_unit

