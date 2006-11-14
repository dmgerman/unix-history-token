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

begin_comment
comment|/*  * ASM macros for pushing and pulling trapframes from the stack  *  * These macros are used to handle the irqframe and trapframe structures  * defined above.  */
end_comment

begin_comment
comment|/*  * PUSHFRAME - macro to push a trap frame on the stack in the current mode  * Since the current mode is used, the SVC lr field is not defined.  *  * NOTE: r13 and r14 are stored separately as a work around for the  * SA110 rev 2 STM^ bug  */
end_comment

begin_define
define|#
directive|define
name|PUSHFRAME
define|\
value|str	lr, [sp, #-4]!;
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
value|\ 	mrs	r0, spsr_all;
comment|/* Put the SPSR on the stack */
value|\ 	str	r0, [sp, #-4]!;
end_define

begin_comment
comment|/*  * PULLFRAME - macro to pull a trap frame from the stack in the current mode  * Since the current mode is used, the SVC lr field is ignored.  */
end_comment

begin_define
define|#
directive|define
name|PULLFRAME
define|\
value|ldr     r0, [sp], #0x0004;
comment|/* Get the SPSR from stack */
value|\         msr     spsr_all, r0;						   \         ldmia   sp, {r0-r14}^;
comment|/* Restore registers (usr mode) */
value|\         mov     r0, r0;
comment|/* NOP for previous instruction */
value|\ 	add	sp, sp, #(4*17);
comment|/* Adjust the stack pointer */
value|\  	ldr	lr, [sp], #0x0004;
end_define

begin_comment
comment|/* Pull the return address */
end_comment

begin_comment
comment|/*  * PUSHFRAMEINSVC - macro to push a trap frame on the stack in SVC32 mode  * This should only be used if the processor is not currently in SVC32  * mode. The processor mode is switched to SVC mode and the trap frame is  * stored. The SVC lr field is used to store the previous value of  * lr in SVC mode.    *  * NOTE: r13 and r14 are stored separately as a work around for the  * SA110 rev 2 STM^ bug  */
end_comment

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
value|\ 	str	r0, [sp, #-4]!;
comment|/* Push return address */
value|\ 	str	lr, [sp, #-4]!;
comment|/* Push SVC lr */
value|\ 	str	r2, [sp, #-4]!;
comment|/* Push SVC sp */
value|\ 	msr     spsr_all, r3;
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
value|\ 	ldr	r5, =0xe0000004;
comment|/* Check if there's any RAS */
value|\ 	ldr	r3, [r5];						   \ 	cmp	r3, #0;
comment|/* Is the update needed ? */
value|\ 	beq	1f;							   \ 	ldr	lr, [r0, #16];						   \ 	ldr	r1, =0xe0000008;					   \ 	ldr	r4, [r1];
comment|/* Get the end of the RAS */
value|\ 	mov	r2, #0;
comment|/* Reset the magic addresses */
value|\ 	str	r2, [r5];						   \ 	str	r2, [r1];						   \ 	cmp	lr, r3;
comment|/* Were we in the RAS ? */
value|\ 	blt	1f;							   \ 	cmp	lr, r4;							   \ 	strlt	r3, [r0, #16];
comment|/* Yes, update the pc */
value|\ 	1:								   \ 	mrs	r0, spsr_all;
comment|/* Put the SPSR on the stack */
value|\ 	str	r0, [sp, #-4]!
end_define

begin_comment
comment|/*  * PULLFRAMEFROMSVCANDEXIT - macro to pull a trap frame from the stack  * in SVC32 mode and restore the saved processor mode and PC.  * This should be used when the SVC lr register needs to be restored on  * exit.  */
end_comment

begin_define
define|#
directive|define
name|PULLFRAMEFROMSVCANDEXIT
define|\
value|ldr     r0, [sp], #0x0004;
comment|/* Get the SPSR from stack */
value|\         msr     spsr_all, r0;
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

begin_define
define|#
directive|define
name|EMPTY
end_define

begin_define
define|#
directive|define
name|DO_AST
define|\
value|ldr	r0, [sp]
comment|/* Get the SPSR from stack */
value|;\ 	mrs	r4, cpsr
comment|/* save CPSR */
value|;\ 	orr	r1, r4, #(I32_bit)					;\ 	msr	cpsr_c, r1
comment|/* Disable interrupts */
value|;\ 	and	r0, r0, #(PSR_MODE)
comment|/* Returning to USR mode? */
value|;\ 	teq	r0, #(PSR_USR32_MODE)					;\ 	bne	2f
comment|/* Nope, get out now */
value|;\ 	bic	r4, r4, #(I32_bit)					;\ 1:	ldr	r5, .Lcurthread						;\ 	ldr	r5, [r5]						;\ 	ldr	r1, [r5, #(TD_FLAGS)]					;\ 	and	r1, r1, #(TDF_ASTPENDING|TDF_NEEDRESCHED)		;\ 	teq	r1, #0x00000000						;\ 	beq	2f
comment|/* Nope. Just bail */
value|;\ 	msr	cpsr_c, r4
comment|/* Restore interrupts */
value|;\ 	mov	r0, sp							;\ 	bl	_C_LABEL(ast)
comment|/* ast(frame) */
value|;\ 	orr	r0, r4, #(I32_bit)					;\ 	msr	cpsr_c, r0						;\ 	b	1b							;\ 2:
end_define

begin_define
define|#
directive|define
name|AST_LOCALS
value|;\ .Lcurthread:								;\ 	.word	_C_LABEL(__pcpu) + PC_CURTHREAD
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

