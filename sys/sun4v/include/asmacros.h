begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * Copyright (c) 2006 Kip Macy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_comment
comment|/*  *  %g7 points to per-cpu data.  */
end_comment

begin_define
define|#
directive|define
name|PCPU_REG
value|%g7
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LOCORE
end_ifdef

begin_comment
comment|/*  * Atomically decrement an integer in memory.  */
end_comment

begin_define
define|#
directive|define
name|ATOMIC_DEC_INT
parameter_list|(
name|r1
parameter_list|,
name|r2
parameter_list|,
name|r3
parameter_list|)
define|\
value|lduw	[r1], r2 ; \ 9:	sub	r2, 1, r3 ; \ 	casa	[r1] ASI_N, r2, r3 ; \ 	cmp	r2, r3 ; \ 	bne,pn	%icc, 9b ; \ 	 mov	r3, r2
end_define

begin_comment
comment|/*  * Atomically increment an integer in memory.  */
end_comment

begin_define
define|#
directive|define
name|ATOMIC_INC_INT
parameter_list|(
name|r1
parameter_list|,
name|r2
parameter_list|,
name|r3
parameter_list|)
define|\
value|lduw	[r1], r2 ; \ 9:	add	r2, 1, r3 ; \ 	casa	[r1] ASI_N, r2, r3 ; \ 	cmp	r2, r3 ; \ 	bne,pn	%icc, 9b ; \ 	 mov	r3, r2
end_define

begin_comment
comment|/*  * Atomically increment an u_long in memory.  */
end_comment

begin_define
define|#
directive|define
name|ATOMIC_INC_ULONG
parameter_list|(
name|r1
parameter_list|,
name|r2
parameter_list|,
name|r3
parameter_list|)
define|\
value|ldx	[r1], r2 ; \ 9:	add	r2, 1, r3 ; \ 	casxa	[r1] ASI_N, r2, r3 ; \ 	cmp	r2, r3 ; \ 	bne,pn	%icc, 9b ; \ 	 mov	r3, r2
end_define

begin_comment
comment|/*  * Atomically clear a number of bits of an integer in memory.  */
end_comment

begin_define
define|#
directive|define
name|ATOMIC_CLEAR_INT
parameter_list|(
name|r1
parameter_list|,
name|r2
parameter_list|,
name|r3
parameter_list|,
name|bits
parameter_list|)
define|\
value|lduw	[r1], r2 ; \ 9:	andn	r2, bits, r3 ; \ 	casa	[r1] ASI_N, r2, r3 ; \ 	cmp	r2, r3 ; \ 	bne,pn	%icc, 9b ; \ 	 mov	r3, r2
end_define

begin_define
define|#
directive|define
name|PCPU
parameter_list|(
name|member
parameter_list|)
value|PCPU_REG + PC_ ## member
end_define

begin_define
define|#
directive|define
name|PCPU_ADDR
parameter_list|(
name|member
parameter_list|,
name|reg
parameter_list|)
define|\
value|add	PCPU_REG, PC_ ## member, reg
end_define

begin_define
define|#
directive|define
name|DEBUGGER
parameter_list|()
define|\
value|ta	%xcc, 1
end_define

begin_define
define|#
directive|define
name|PANIC
parameter_list|(
name|msg
parameter_list|,
name|r1
parameter_list|)
define|\
value|.sect	.rodata ; \ 9:	.asciz	msg ; \ 	.previous ; \ 	SET(9b, r1, %o0) ; \ 	call	panic ; \ 	 nop
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_define
define|#
directive|define
name|KASSERT
parameter_list|(
name|r1
parameter_list|,
name|msg
parameter_list|)
define|\
value|brnz	r1, 8f ; \ 	 nop ; \ 	PANIC(msg, r1) ; \ 8:
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KASSERT
parameter_list|(
name|r1
parameter_list|,
name|msg
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PUTS
parameter_list|(
name|msg
parameter_list|,
name|r1
parameter_list|)
define|\
value|.sect	.rodata ; \ 9:	.asciz	msg ; \ 	.previous ; \ 	SET(9b, r1, %o0) ; \ 	call	printf ; \ 	 nop
end_define

begin_define
define|#
directive|define
name|_ALIGN_DATA
value|.align 8
end_define

begin_define
define|#
directive|define
name|DATA
parameter_list|(
name|name
parameter_list|)
define|\
value|.data ; \ 	_ALIGN_DATA ; \ 	.globl	name ; \ 	.type	name, @object ; \ name:
end_define

begin_define
define|#
directive|define
name|EMPTY
end_define

begin_define
define|#
directive|define
name|GET_MMFSA_SCRATCH
parameter_list|(
name|reg
parameter_list|)
define|\
value|ldxa [%g0 + %g0]ASI_SCRATCHPAD, reg;
end_define

begin_define
define|#
directive|define
name|GET_PCPU_PHYS_SCRATCH
parameter_list|(
name|tmp
parameter_list|)
define|\
value|sethi %uhi(VM_MIN_DIRECT_ADDRESS), tmp;         \         mov  SCRATCH_REG_PCPU, PCPU_REG;                \         sllx tmp, 32, tmp;                              \         ldxa [%g0 + PCPU_REG]ASI_SCRATCHPAD, PCPU_REG;  \         andn PCPU_REG, tmp, PCPU_REG
end_define

begin_define
define|#
directive|define
name|GET_PCPU_SCRATCH
define|\
value|mov  SCRATCH_REG_PCPU, PCPU_REG;    \         ldxa [%g0 + PCPU_REG]ASI_SCRATCHPAD, PCPU_REG;
end_define

begin_define
define|#
directive|define
name|GET_PCPU_SCRATCH_SLOW
parameter_list|(
name|reg
parameter_list|)
define|\
value|mov  SCRATCH_REG_PCPU, reg;    \         ldxa [reg]ASI_SCRATCHPAD, PCPU_REG;
end_define

begin_define
define|#
directive|define
name|GET_HASH_SCRATCH_USER
parameter_list|(
name|reg
parameter_list|)
define|\
value|mov SCRATCH_REG_HASH_USER, reg;    \ 	ldxa [%g0 + reg]ASI_SCRATCHPAD, reg;
end_define

begin_define
define|#
directive|define
name|GET_HASH_SCRATCH_KERNEL
parameter_list|(
name|reg
parameter_list|)
define|\
value|mov SCRATCH_REG_HASH_KERNEL, reg;  \ 	ldxa [%g0 + reg]ASI_SCRATCHPAD, reg;
end_define

begin_define
define|#
directive|define
name|GET_HASH_PHYS_SCRATCH_USER
parameter_list|(
name|tmp
parameter_list|,
name|reg
parameter_list|)
define|\
value|sethi %uhi(VM_MIN_DIRECT_ADDRESS), tmp; \         mov SCRATCH_REG_HASH_USER, reg;         \ 	sllx tmp, 32, tmp;                      \ 	ldxa [%g0 + reg]ASI_SCRATCHPAD, reg;    \ 	andn reg, tmp, reg;
end_define

begin_define
define|#
directive|define
name|GET_HASH_PHYS_SCRATCH_KERNEL
parameter_list|(
name|tmp
parameter_list|,
name|reg
parameter_list|)
define|\
value|sethi %uhi(VM_MIN_DIRECT_ADDRESS), tmp;   \         mov SCRATCH_REG_HASH_KERNEL, reg;         \ 	sllx tmp, 32, tmp;                        \ 	ldxa [%g0 + reg]ASI_SCRATCHPAD, reg;      \ 	andn reg, tmp, reg;
end_define

begin_define
define|#
directive|define
name|GET_TSB_SCRATCH_USER
parameter_list|(
name|reg
parameter_list|)
define|\
value|mov SCRATCH_REG_TSB_USER, reg;    \ 	ldxa [%g0 + reg]ASI_SCRATCHPAD, reg;
end_define

begin_define
define|#
directive|define
name|GET_TSB_SCRATCH_KERNEL
parameter_list|(
name|reg
parameter_list|)
define|\
value|mov SCRATCH_REG_TSB_KERNEL, reg;         \ 	ldxa [%g0 + reg]ASI_SCRATCHPAD, reg;
end_define

begin_define
define|#
directive|define
name|SET_SCRATCH
parameter_list|(
name|offsetreg
parameter_list|,
name|reg
parameter_list|)
value|stxa reg, [%g0 + offsetreg]ASI_SCRATCHPAD
end_define

begin_define
define|#
directive|define
name|GET_PCB_PHYS
parameter_list|(
name|tmp
parameter_list|,
name|reg
parameter_list|)
define|\
value|mov PC_CURPCB, reg;                       \         GET_PCPU_PHYS_SCRATCH(tmp);               \         ldxa [PCPU_REG + reg]ASI_REAL, reg;       \         sub reg, tmp, reg;
end_define

begin_define
define|#
directive|define
name|GET_PCB
parameter_list|(
name|reg
parameter_list|)
define|\
value|GET_PCPU_SCRATCH;   \         ldx [PCPU_REG + PC_CURPCB], reg;
end_define

begin_define
define|#
directive|define
name|SET_MMU_CONTEXT
parameter_list|(
name|typereg
parameter_list|,
name|reg
parameter_list|)
value|stxa reg, [typereg]ASI_MMU_CONTEXTID
end_define

begin_define
define|#
directive|define
name|GET_MMU_CONTEXT
parameter_list|(
name|typereg
parameter_list|,
name|reg
parameter_list|)
value|ldxa [typereg]ASI_MMU_CONTEXTID, reg
end_define

begin_define
define|#
directive|define
name|SAVE_GLOBALS
parameter_list|(
name|TF
parameter_list|)
define|\
value|stx	%g1, [TF + TF_G1]; \ 	stx	%g2, [TF + TF_G2]; \ 	stx	%g3, [TF + TF_G3]; \ 	stx	%g4, [TF + TF_G4]; \ 	stx	%g5, [TF + TF_G5]; \ 	stx	%g6, [TF + TF_G6];
end_define

begin_define
define|#
directive|define
name|RESTORE_GLOBALS_USER
parameter_list|(
name|TF
parameter_list|)
define|\
value|ldx	[TF + TF_G1], %g1; \ 	ldx	[TF + TF_G2], %g2; \ 	ldx	[TF + TF_G3], %g3; \ 	ldx	[TF + TF_G4], %g4; \ 	ldx	[TF + TF_G5], %g5; \ 	ldx	[TF + TF_G6], %g6; \ 	ldx	[TF + TF_G7], %g7;
end_define

begin_define
define|#
directive|define
name|RESTORE_GLOBALS_KERNEL
parameter_list|(
name|TF
parameter_list|)
define|\
value|mov  SCRATCH_REG_PCPU, %g7; \ 	ldx	[TF + TF_G1], %g1; \ 	ldx	[TF + TF_G2], %g2; \ 	ldx	[TF + TF_G3], %g3; \ 	ldx	[TF + TF_G4], %g4; \ 	ldx	[TF + TF_G5], %g5; \ 	ldx	[TF + TF_G6], %g6; \ 	ldxa [%g0 + %g7]ASI_SCRATCHPAD, %g7;
end_define

begin_define
define|#
directive|define
name|SAVE_OUTS
parameter_list|(
name|TF
parameter_list|)
define|\
value|stx	%i0, [TF + TF_O0]; \ 	stx	%i1, [TF + TF_O1]; \ 	stx	%i2, [TF + TF_O2]; \ 	stx	%i3, [TF + TF_O3]; \ 	stx	%i4, [TF + TF_O4]; \ 	stx	%i5, [TF + TF_O5]; \ 	stx	%i6, [TF + TF_O6]; \ 	stx	%i7, [TF + TF_O7];
end_define

begin_define
define|#
directive|define
name|RESTORE_OUTS
parameter_list|(
name|TF
parameter_list|)
define|\
value|ldx	[TF + TF_O0], %i0; \ 	ldx	[TF + TF_O1], %i1; \ 	ldx	[TF + TF_O2], %i2; \ 	ldx	[TF + TF_O3], %i3; \ 	ldx	[TF + TF_O4], %i4; \ 	ldx	[TF + TF_O5], %i5; \ 	ldx	[TF + TF_O6], %i6; \ 	ldx	[TF + TF_O7], %i7;
end_define

begin_define
define|#
directive|define
name|SAVE_WINDOW
parameter_list|(
name|SBP
parameter_list|)
define|\
value|stx	%l0, [SBP + (0*8)]; \ 	stx	%l1, [SBP + (1*8)]; \ 	stx	%l2, [SBP + (2*8)]; \ 	stx	%l3, [SBP + (3*8)]; \ 	stx	%l4, [SBP + (4*8)]; \ 	stx	%l5, [SBP + (5*8)]; \ 	stx	%l6, [SBP + (6*8)]; \ 	stx	%l7, [SBP + (7*8)]; \ 	stx	%i0, [SBP + (8*8)]; \ 	stx	%i1, [SBP + (9*8)]; \ 	stx	%i2, [SBP + (10*8)]; \ 	stx	%i3, [SBP + (11*8)]; \ 	stx	%i4, [SBP + (12*8)]; \ 	stx	%i5, [SBP + (13*8)]; \ 	stx	%i6, [SBP + (14*8)]; \ 	stx	%i7, [SBP + (15*8)];
end_define

begin_define
define|#
directive|define
name|SAVE_WINDOW_ASI
parameter_list|(
name|SBP
parameter_list|)
define|\
value|stxa	%l0, [SBP + (0*8)]%asi; \ 	stxa	%l1, [SBP + (1*8)]%asi; \ 	stxa	%l2, [SBP + (2*8)]%asi; \ 	stxa	%l3, [SBP + (3*8)]%asi; \ 	stxa	%l4, [SBP + (4*8)]%asi; \ 	stxa	%l5, [SBP + (5*8)]%asi; \ 	stxa	%l6, [SBP + (6*8)]%asi; \ 	stxa	%l7, [SBP + (7*8)]%asi; \ 	stxa	%i0, [SBP + (8*8)]%asi; \ 	stxa	%i1, [SBP + (9*8)]%asi; \ 	stxa	%i2, [SBP + (10*8)]%asi; \ 	stxa	%i3, [SBP + (11*8)]%asi; \ 	stxa	%i4, [SBP + (12*8)]%asi; \ 	stxa	%i5, [SBP + (13*8)]%asi; \ 	stxa	%i6, [SBP + (14*8)]%asi; \ 	stxa	%i7, [SBP + (15*8)]%asi;
end_define

begin_define
define|#
directive|define
name|SAVE_LOCALS_ASI
parameter_list|(
name|SBP
parameter_list|)
define|\
value|stxa	%l0, [SBP + (0*8)]%asi; \ 	stxa	%l1, [SBP + (1*8)]%asi; \ 	stxa	%l2, [SBP + (2*8)]%asi; \ 	stxa	%l3, [SBP + (3*8)]%asi; \ 	stxa	%l4, [SBP + (4*8)]%asi; \ 	stxa	%l5, [SBP + (5*8)]%asi; \ 	stxa	%l6, [SBP + (6*8)]%asi; \ 	stxa	%l7, [SBP + (7*8)]%asi;
end_define

begin_define
define|#
directive|define
name|RESTORE_LOCALS_ASI
parameter_list|(
name|SBP
parameter_list|)
define|\
value|ldxa	[SBP + (0*8)]%asi, %l0;	\ 	ldxa	[SBP + (1*8)]%asi, %l1;	\ 	ldxa	[SBP + (2*8)]%asi, %l2;	\ 	ldxa	[SBP + (3*8)]%asi, %l3;	\ 	ldxa	[SBP + (4*8)]%asi, %l4;	\ 	ldxa	[SBP + (5*8)]%asi, %l5;	\ 	ldxa	[SBP + (6*8)]%asi, %l6;	\ 	ldxa	[SBP + (7*8)]%asi, %l7;
end_define

begin_define
define|#
directive|define
name|SAVE_OUTS_ASI
parameter_list|(
name|SBP
parameter_list|)
define|\
value|stxa	%o0, [SBP + (0*8)]%asi; \ 	stxa	%o1, [SBP + (1*8)]%asi; \ 	stxa	%o2, [SBP + (2*8)]%asi; \ 	stxa	%o3, [SBP + (3*8)]%asi; \ 	stxa	%o4, [SBP + (4*8)]%asi; \ 	stxa	%o5, [SBP + (5*8)]%asi; \ 	stxa	%o6, [SBP + (6*8)]%asi; \ 	stxa	%o7, [SBP + (7*8)]%asi;
end_define

begin_define
define|#
directive|define
name|RESTORE_OUTS_ASI
parameter_list|(
name|SBP
parameter_list|)
define|\
value|ldxa	[SBP + (0*8)]%asi, %o0;	\ 	ldxa	[SBP + (1*8)]%asi, %o1;	\ 	ldxa	[SBP + (2*8)]%asi, %o2;	\ 	ldxa	[SBP + (3*8)]%asi, %o3;	\ 	ldxa	[SBP + (4*8)]%asi, %o4;	\ 	ldxa	[SBP + (5*8)]%asi, %o5;	\ 	ldxa	[SBP + (6*8)]%asi, %o6;	\ 	ldxa	[SBP + (7*8)]%asi, %o7;
end_define

begin_define
define|#
directive|define
name|TTRACE_ADD_SAFE
parameter_list|(
name|SBP
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|)
define|\
value|SAVE_OUTS_ASI(SBP);  \         mov arg0, %o0; \         mov arg1, %o1; \         mov arg2, %o2; \         mov arg3, %o3; \         mov arg4, %o4; \         RESTORE_OUTS_ASI(SBP);
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

