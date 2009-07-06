begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: asm.h,v 1.29 2000/12/14 21:29:51 jeffs Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)machAsmDefs.h	8.1 (Berkeley) 6/10/93  *	JNPR: asm.h,v 1.10 2007/08/09 11:23:32 katta  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * machAsmDefs.h --  *  *	Macros used when writing assembler programs.  *  *	Copyright (C) 1989 Digital Equipment Corporation.  *	Permission to use, copy, modify, and distribute this software and  *	its documentation for any purpose and without fee is hereby granted,  *	provided that the above copyright notice appears in all copies.  *	Digital Equipment Corporation makes no representations about the  *	suitability of this software for any purpose.  It is provided "as is"  *	without express or implied warranty.  *  * from: Header: /sprite/src/kernel/mach/ds3100.md/RCS/machAsmDefs.h,  *	v 1.2 89/08/15 18:28:24 rab Exp  SPRITE (DECWRL)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ASM_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ASM_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_REG_DEFS
end_ifndef

begin_include
include|#
directive|include
file|<machine/regdef.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_include
include|#
directive|include
file|<machine/cdefs.h>
end_include

begin_undef
undef|#
directive|undef
name|__FBSDID
end_undef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|STRIP_FBSDID
argument_list|)
end_if

begin_define
define|#
directive|define
name|__FBSDID
parameter_list|(
name|s
parameter_list|)
value|.ident s
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__FBSDID
parameter_list|(
name|s
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Define -pg profile entry code.  * Must always be noreorder, must never use a macro instruction  * Final addiu to t9 must always equal the size of this _KERN_MCOUNT  */
end_comment

begin_define
define|#
directive|define
name|_KERN_MCOUNT
define|\
value|.set	push;			\ 	.set	noreorder;		\ 	.set	noat;			\ 	subu	sp,sp,16;		\ 	sw	t9,12(sp);		\ 	move	AT,ra;			\ 	lui	t9,%hi(_mcount);	\ 	addiu	t9,t9,%lo(_mcount);	\ 	jalr	t9;			\ 	nop;				\ 	lw	t9,4(sp);		\ 	addiu	sp,sp,8;		\ 	addiu	t9,t9,40;		\ 	.set	pop;
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GPROF
end_ifdef

begin_define
define|#
directive|define
name|MCOUNT
value|_KERN_MCOUNT
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MCOUNT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_C_LABEL
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_comment
comment|/*   *  Endian-independent assembly-code aliases for unaligned memory accesses.  */
end_comment

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|LWLO
value|lwl
end_define

begin_define
define|#
directive|define
name|LWHI
value|lwr
end_define

begin_define
define|#
directive|define
name|SWLO
value|swl
end_define

begin_define
define|#
directive|define
name|SWHI
value|swr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|LWLO
value|lwr
end_define

begin_define
define|#
directive|define
name|LWHI
value|lwl
end_define

begin_define
define|#
directive|define
name|SWLO
value|swr
end_define

begin_define
define|#
directive|define
name|SWHI
value|swl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_AENT
end_ifdef

begin_define
define|#
directive|define
name|AENT
parameter_list|(
name|x
parameter_list|)
define|\
value|.aent	x, 0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AENT
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * WARN_REFERENCES: create a warning if the specified symbol is referenced  */
end_comment

begin_define
define|#
directive|define
name|WARN_REFERENCES
parameter_list|(
name|_sym
parameter_list|,
name|_msg
parameter_list|)
define|\
value|.section .gnu.warning. ## _sym ; .ascii _msg ; .text
end_define

begin_comment
comment|/*  * These are temp registers whose names can be used in either the old  * or new ABI, although they map to different physical registers.  In  * the old ABI, they map to t4-t7, and in the new ABI, they map to a4-a7.  *  * Because they overlap with the last 4 arg regs in the new ABI, ta0-ta3  * should be used only when we need more than t0-t3.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

begin_define
define|#
directive|define
name|ta0
value|$8
end_define

begin_define
define|#
directive|define
name|ta1
value|$9
end_define

begin_define
define|#
directive|define
name|ta2
value|$10
end_define

begin_define
define|#
directive|define
name|ta3
value|$11
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ta0
value|$12
end_define

begin_define
define|#
directive|define
name|ta1
value|$13
end_define

begin_define
define|#
directive|define
name|ta2
value|$14
end_define

begin_define
define|#
directive|define
name|ta3
value|$15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __mips_n32 || __mips_n64 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__ELF__
end_ifdef

begin_define
define|#
directive|define
name|_C_LABEL
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_C_LABEL
parameter_list|(
name|x
parameter_list|)
value|_ ## x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * WEAK_ALIAS: create a weak alias.  */
end_comment

begin_define
define|#
directive|define
name|WEAK_ALIAS
parameter_list|(
name|alias
parameter_list|,
name|sym
parameter_list|)
define|\
value|.weak alias;							\ 	alias = sym
end_define

begin_comment
comment|/*  * STRONG_ALIAS: create a strong alias.  */
end_comment

begin_define
define|#
directive|define
name|STRONG_ALIAS
parameter_list|(
name|alias
parameter_list|,
name|sym
parameter_list|)
define|\
value|.globl alias;							\ 	alias = sym
end_define

begin_define
define|#
directive|define
name|GLOBAL
parameter_list|(
name|sym
parameter_list|)
define|\
value|.globl sym; sym:
end_define

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|sym
parameter_list|)
define|\
value|.text; .globl sym; .ent sym; sym:
end_define

begin_define
define|#
directive|define
name|ASM_ENTRY
parameter_list|(
name|sym
parameter_list|)
define|\
value|.text; .globl sym; .type sym,@function; sym:
end_define

begin_comment
comment|/*  * LEAF  *	A leaf routine does  *	- call no other function,  *	- never use any register that callee-saved (S0-S8), and  *	- not use any local stack storage.  */
end_comment

begin_define
define|#
directive|define
name|LEAF
parameter_list|(
name|x
parameter_list|)
define|\
value|.globl	_C_LABEL(x);	\ 	.ent	_C_LABEL(x), 0;	\ _C_LABEL(x): ;			\ 	.frame sp, 0, ra;	\ 	MCOUNT
end_define

begin_comment
comment|/*  * LEAF_NOPROFILE  *	No profilable leaf routine.  */
end_comment

begin_define
define|#
directive|define
name|LEAF_NOPROFILE
parameter_list|(
name|x
parameter_list|)
define|\
value|.globl	_C_LABEL(x);	\ 	.ent	_C_LABEL(x), 0;	\ _C_LABEL(x): ;			\ 	.frame	sp, 0, ra
end_define

begin_comment
comment|/*  * XLEAF  *	declare alternate entry to leaf routine  */
end_comment

begin_define
define|#
directive|define
name|XLEAF
parameter_list|(
name|x
parameter_list|)
define|\
value|.globl	_C_LABEL(x);	\ 	AENT (_C_LABEL(x));	\ _C_LABEL(x):
end_define

begin_comment
comment|/*  * NESTED  *	A function calls other functions and needs  *	therefore stack space to save/restore registers.  */
end_comment

begin_define
define|#
directive|define
name|NESTED
parameter_list|(
name|x
parameter_list|,
name|fsize
parameter_list|,
name|retpc
parameter_list|)
define|\
value|.globl	_C_LABEL(x);		\ 	.ent	_C_LABEL(x), 0;		\ _C_LABEL(x): ;				\ 	.frame	sp, fsize, retpc;	\ 	MCOUNT
end_define

begin_comment
comment|/*  * NESTED_NOPROFILE(x)  *	No profilable nested routine.  */
end_comment

begin_define
define|#
directive|define
name|NESTED_NOPROFILE
parameter_list|(
name|x
parameter_list|,
name|fsize
parameter_list|,
name|retpc
parameter_list|)
define|\
value|.globl	_C_LABEL(x);			\ 	.ent	_C_LABEL(x), 0;			\ _C_LABEL(x): ;					\ 	.frame	sp, fsize, retpc
end_define

begin_comment
comment|/*  * XNESTED  *	declare alternate entry point to nested routine.  */
end_comment

begin_define
define|#
directive|define
name|XNESTED
parameter_list|(
name|x
parameter_list|)
define|\
value|.globl	_C_LABEL(x);	\ 	AENT (_C_LABEL(x));	\ _C_LABEL(x):
end_define

begin_comment
comment|/*  * END  *	Mark end of a procedure.  */
end_comment

begin_define
define|#
directive|define
name|END
parameter_list|(
name|x
parameter_list|)
define|\
value|.end _C_LABEL(x)
end_define

begin_comment
comment|/*  * IMPORT -- import external symbol  */
end_comment

begin_define
define|#
directive|define
name|IMPORT
parameter_list|(
name|sym
parameter_list|,
name|size
parameter_list|)
define|\
value|.extern _C_LABEL(sym),size
end_define

begin_comment
comment|/*  * EXPORT -- export definition of symbol  */
end_comment

begin_define
define|#
directive|define
name|EXPORT
parameter_list|(
name|x
parameter_list|)
define|\
value|.globl	_C_LABEL(x);	\ _C_LABEL(x):
end_define

begin_comment
comment|/*  * VECTOR  *	exception vector entrypoint  *	XXX: regmask should be used to generate .mask  */
end_comment

begin_define
define|#
directive|define
name|VECTOR
parameter_list|(
name|x
parameter_list|,
name|regmask
parameter_list|)
define|\
value|.ent	_C_LABEL(x),0;	\ 	EXPORT(x);		\  #define	VECTOR_END(x)		\ 	EXPORT(x ## End);	\ 	END(x)
end_define

begin_define
define|#
directive|define
name|KSEG0TEXT_START
end_define

begin_define
define|#
directive|define
name|KSEG0TEXT_END
end_define

begin_define
define|#
directive|define
name|KSEG0TEXT
value|.text
end_define

begin_comment
comment|/*  * Macros to panic and printf from assembly language.  */
end_comment

begin_define
define|#
directive|define
name|PANIC
parameter_list|(
name|msg
parameter_list|)
define|\
value|PTR_LA	a0, 9f;			\ 	jal	_C_LABEL(panic);	\ 	nop;				\ 	MSG(msg)
end_define

begin_define
define|#
directive|define
name|PANIC_KSEG0
parameter_list|(
name|msg
parameter_list|,
name|reg
parameter_list|)
value|PANIC(msg)
end_define

begin_define
define|#
directive|define
name|PRINTF
parameter_list|(
name|msg
parameter_list|)
define|\
value|PTR_LA	a0, 9f;			\ 	jal	_C_LABEL(printf);	\ 	nop;				\ 	MSG(msg)
end_define

begin_define
define|#
directive|define
name|MSG
parameter_list|(
name|msg
parameter_list|)
define|\
value|.rdata;				\ 9:	.asciiz	msg;			\ 	.text
end_define

begin_define
define|#
directive|define
name|ASMSTR
parameter_list|(
name|str
parameter_list|)
define|\
value|.asciiz str;			\ 	.align	3
end_define

begin_comment
comment|/*  * Call ast if required  */
end_comment

begin_define
define|#
directive|define
name|DO_AST
define|\
value|44:				                     \ 	PTR_LA	s0, _C_LABEL(disableintr)           ;\ 	jalr	s0                                  ;\ 	nop                                         ;\ 	move	a0, v0                              ;\ 	GET_CPU_PCPU(s1)                            ;\ 	lw	s3, PC_CURPCB(s1)                   ;\ 	lw	s1, PC_CURTHREAD(s1)                ;\ 	lw	s2, TD_FLAGS(s1)                    ;\ 	li	s0, TDF_ASTPENDING | TDF_NEEDRESCHED;\ 	and	s2, s0                              ;\ 	PTR_LA	s0, _C_LABEL(restoreintr)           ;\ 	jalr	s0                                  ;\ 	nop                                         ;\ 	beq	s2, zero, 4f                        ;\ 	nop                                         ;\ 	PTR_LA	s0, _C_LABEL(ast)                   ;\ 	jalr	s0                                  ;\ 	PTR_ADDU a0, s3, U_PCB_REGS                 ;\ 	j 44b			                    ;\         nop                                         ;\ 4:
end_define

begin_comment
comment|/*  * XXX retain dialects XXX  */
end_comment

begin_define
define|#
directive|define
name|ALEAF
parameter_list|(
name|x
parameter_list|)
value|XLEAF(x)
end_define

begin_define
define|#
directive|define
name|NLEAF
parameter_list|(
name|x
parameter_list|)
value|LEAF_NOPROFILE(x)
end_define

begin_define
define|#
directive|define
name|NON_LEAF
parameter_list|(
name|x
parameter_list|,
name|fsize
parameter_list|,
name|retpc
parameter_list|)
value|NESTED(x, fsize, retpc)
end_define

begin_define
define|#
directive|define
name|NNON_LEAF
parameter_list|(
name|x
parameter_list|,
name|fsize
parameter_list|,
name|retpc
parameter_list|)
value|NESTED_NOPROFILE(x, fsize, retpc)
end_define

begin_comment
comment|/*  *  standard callframe {  *  	register_t cf_args[4];		arg0 - arg3  *  	register_t cf_sp;		frame pointer  *  	register_t cf_ra;		return address  *  };  */
end_comment

begin_define
define|#
directive|define
name|CALLFRAME_SIZ
value|(4 * (4 + 2))
end_define

begin_define
define|#
directive|define
name|CALLFRAME_SP
value|(4 * 4)
end_define

begin_define
define|#
directive|define
name|CALLFRAME_RA
value|(4 * 5)
end_define

begin_define
define|#
directive|define
name|START_FRAME
value|CALLFRAME_SIZ
end_define

begin_comment
comment|/*  * While it would be nice to be compatible with the SGI  * REG_L and REG_S macros, because they do not take parameters, it  * is impossible to use them with the _MIPS_SIM_ABIX32 model.  *  * These macros hide the use of mips3 instructions from the  * assembler to prevent the assembler from generating 64-bit style  * ABI calls.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MIPS_BSD_API
argument_list|)
operator|||
name|_MIPS_BSD_API
operator|==
name|_MIPS_BSD_API_LP32
end_if

begin_comment
comment|/* #if !defined(__mips_n64) */
end_comment

begin_define
define|#
directive|define
name|REG_L
value|lw
end_define

begin_define
define|#
directive|define
name|REG_S
value|sw
end_define

begin_define
define|#
directive|define
name|REG_LI
value|li
end_define

begin_define
define|#
directive|define
name|REG_PROLOGUE
value|.set push
end_define

begin_define
define|#
directive|define
name|REG_EPILOGUE
value|.set pop
end_define

begin_define
define|#
directive|define
name|SZREG
value|4
end_define

begin_define
define|#
directive|define
name|PTR_LA
value|la
end_define

begin_define
define|#
directive|define
name|PTR_ADDU
value|addu
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REG_L
value|ld
end_define

begin_define
define|#
directive|define
name|REG_S
value|sd
end_define

begin_define
define|#
directive|define
name|REG_LI
value|dli
end_define

begin_define
define|#
directive|define
name|REG_PROLOGUE
value|.set push ; .set mips3
end_define

begin_define
define|#
directive|define
name|REG_EPILOGUE
value|.set pop
end_define

begin_define
define|#
directive|define
name|SZREG
value|8
end_define

begin_define
define|#
directive|define
name|PTR_LA
value|dla
end_define

begin_define
define|#
directive|define
name|PTR_ADDU
value|daddu
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_BSD_API */
end_comment

begin_define
define|#
directive|define
name|mfc0_macro
parameter_list|(
name|data
parameter_list|,
name|spr
parameter_list|)
define|\
value|__asm __volatile ("mfc0 %0, $%1"				\ 			: "=r" (data)
comment|/* outputs */
value|\ 			: "i" (spr));
end_define

begin_comment
comment|/* inputs */
end_comment

begin_define
define|#
directive|define
name|mtc0_macro
parameter_list|(
name|data
parameter_list|,
name|spr
parameter_list|)
define|\
value|__asm __volatile ("mtc0 %0, $%1"				\ 			:
comment|/* outputs */
value|\ 			: "r" (data), "i" (spr));
end_define

begin_comment
comment|/* inputs */
end_comment

begin_define
define|#
directive|define
name|cfc0_macro
parameter_list|(
name|data
parameter_list|,
name|spr
parameter_list|)
define|\
value|__asm __volatile ("cfc0 %0, $%1"				\ 			: "=r" (data)
comment|/* outputs */
value|\ 			: "i" (spr));
end_define

begin_comment
comment|/* inputs */
end_comment

begin_define
define|#
directive|define
name|ctc0_macro
parameter_list|(
name|data
parameter_list|,
name|spr
parameter_list|)
define|\
value|__asm __volatile ("ctc0 %0, $%1"				\ 			:
comment|/* outputs */
value|\ 			: "r" (data), "i" (spr));
end_define

begin_comment
comment|/* inputs */
end_comment

begin_define
define|#
directive|define
name|lbu_macro
parameter_list|(
name|data
parameter_list|,
name|addr
parameter_list|)
define|\
value|__asm __volatile ("lbu %0, 0x0(%1)"				\ 			: "=r" (data)
comment|/* outputs */
value|\ 			: "r" (addr));
end_define

begin_comment
comment|/* inputs */
end_comment

begin_define
define|#
directive|define
name|lb_macro
parameter_list|(
name|data
parameter_list|,
name|addr
parameter_list|)
define|\
value|__asm __volatile ("lb %0, 0x0(%1)"				\ 			: "=r" (data)
comment|/* outputs */
value|\ 			: "r" (addr));
end_define

begin_comment
comment|/* inputs */
end_comment

begin_define
define|#
directive|define
name|lwl_macro
parameter_list|(
name|data
parameter_list|,
name|addr
parameter_list|)
define|\
value|__asm __volatile ("lwl %0, 0x0(%1)"				\ 			: "=r" (data)
comment|/* outputs */
value|\ 			: "r" (addr));
end_define

begin_comment
comment|/* inputs */
end_comment

begin_define
define|#
directive|define
name|lwr_macro
parameter_list|(
name|data
parameter_list|,
name|addr
parameter_list|)
define|\
value|__asm __volatile ("lwr %0, 0x0(%1)"				\ 			: "=r" (data)
comment|/* outputs */
value|\ 			: "r" (addr));
end_define

begin_comment
comment|/* inputs */
end_comment

begin_define
define|#
directive|define
name|ldl_macro
parameter_list|(
name|data
parameter_list|,
name|addr
parameter_list|)
define|\
value|__asm __volatile ("ldl %0, 0x0(%1)"				\ 			: "=r" (data)
comment|/* outputs */
value|\ 			: "r" (addr));
end_define

begin_comment
comment|/* inputs */
end_comment

begin_define
define|#
directive|define
name|ldr_macro
parameter_list|(
name|data
parameter_list|,
name|addr
parameter_list|)
define|\
value|__asm __volatile ("ldr %0, 0x0(%1)"				\ 			: "=r" (data)
comment|/* outputs */
value|\ 			: "r" (addr));
end_define

begin_comment
comment|/* inputs */
end_comment

begin_define
define|#
directive|define
name|sb_macro
parameter_list|(
name|data
parameter_list|,
name|addr
parameter_list|)
define|\
value|__asm __volatile ("sb %0, 0x0(%1)"				\ 			:
comment|/* outputs */
value|\ 			: "r" (data), "r" (addr));
end_define

begin_comment
comment|/* inputs */
end_comment

begin_define
define|#
directive|define
name|swl_macro
parameter_list|(
name|data
parameter_list|,
name|addr
parameter_list|)
define|\
value|__asm __volatile ("swl %0, 0x0(%1)"				\ 			:
comment|/* outputs */
value|\ 			: "r" (data), "r" (addr));
end_define

begin_comment
comment|/* inputs */
end_comment

begin_define
define|#
directive|define
name|swr_macro
parameter_list|(
name|data
parameter_list|,
name|addr
parameter_list|)
define|\
value|__asm __volatile ("swr %0, 0x0(%1)"				\ 			:
comment|/* outputs */
value|\ 			: "r" (data), "r" (addr));
end_define

begin_comment
comment|/* inputs */
end_comment

begin_define
define|#
directive|define
name|sdl_macro
parameter_list|(
name|data
parameter_list|,
name|addr
parameter_list|)
define|\
value|__asm __volatile ("sdl %0, 0x0(%1)"				\ 			:
comment|/* outputs */
value|\ 			: "r" (data), "r" (addr));
end_define

begin_comment
comment|/* inputs */
end_comment

begin_define
define|#
directive|define
name|sdr_macro
parameter_list|(
name|data
parameter_list|,
name|addr
parameter_list|)
define|\
value|__asm __volatile ("sdr %0, 0x0(%1)"				\ 			:
comment|/* outputs */
value|\ 			: "r" (data), "r" (addr));
end_define

begin_comment
comment|/* inputs */
end_comment

begin_define
define|#
directive|define
name|mfgr_macro
parameter_list|(
name|data
parameter_list|,
name|gr
parameter_list|)
define|\
value|__asm __volatile ("move %0, $%1"				\ 			: "=r" (data)
comment|/* outputs */
value|\ 			: "i" (gr));
end_define

begin_comment
comment|/* inputs */
end_comment

begin_define
define|#
directive|define
name|dmfc0_macro
parameter_list|(
name|data
parameter_list|,
name|spr
parameter_list|)
define|\
value|__asm __volatile ("dmfc0 %0, $%1"				\ 			: "=r" (data)
comment|/* outputs */
value|\ 			: "i" (spr));
end_define

begin_comment
comment|/* inputs */
end_comment

begin_define
define|#
directive|define
name|dmtc0_macro
parameter_list|(
name|data
parameter_list|,
name|spr
parameter_list|,
name|sel
parameter_list|)
define|\
value|__asm __volatile ("dmtc0	%0, $%1, %2"			\ 			:
comment|/* no  outputs */
value|\ 			: "r" (data), "i" (spr), "i" (sel));
end_define

begin_comment
comment|/* inputs */
end_comment

begin_comment
comment|/*  * The DYNAMIC_STATUS_MASK option adds an additional masking operation  * when updating the hardware interrupt mask in the status register.  *  * This is useful for platforms that need to at run-time mask  * interrupts based on motherboard configuration or to handle  * slowly clearing interrupts.  *  * XXX this is only currently implemented for mips3.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MIPS_DYNAMIC_STATUS_MASK
end_ifdef

begin_define
define|#
directive|define
name|DYNAMIC_STATUS_MASK
parameter_list|(
name|sr
parameter_list|,
name|scratch
parameter_list|)
define|\
value|lw	scratch, mips_dynamic_status_mask;	\ 	and	sr, sr, scratch
end_define

begin_define
define|#
directive|define
name|DYNAMIC_STATUS_MASK_TOUSER
parameter_list|(
name|sr
parameter_list|,
name|scratch1
parameter_list|)
define|\
value|ori	sr, (MIPS_INT_MASK | MIPS_SR_INT_IE);	\ 	DYNAMIC_STATUS_MASK(sr,scratch1)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DYNAMIC_STATUS_MASK
parameter_list|(
name|sr
parameter_list|,
name|scratch
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DYNAMIC_STATUS_MASK_TOUSER
parameter_list|(
name|sr
parameter_list|,
name|scratch1
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_comment
comment|/* 	 * FREEBSD_DEVELOPERS_FIXME 	 * In multiprocessor case, store/retrieve the pcpu structure 	 * address for current CPU in scratch register for fast access. 	 */
end_comment

begin_error
error|#
directive|error
literal|"Write GET_CPU_PCPU for SMP"
end_error

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GET_CPU_PCPU
parameter_list|(
name|reg
parameter_list|)
define|\
value|lw	reg, _C_LABEL(pcpup);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Description of the setjmp buffer  *  * word  0	magic number	(dependant on creator)  *       1	RA  *       2	S0  *       3	S1  *       4	S2  *       5	S3  *       6	S4  *       7	S5  *       8	S6  *       9	S7  *       10	SP  *       11	S8  *       12	signal mask	(dependant on magic)  *       13	(con't)  *       14	(con't)  *       15	(con't)  *  * The magic number number identifies the jmp_buf and  * how the buffer was created as well as providing  * a sanity check  *  */
end_comment

begin_define
define|#
directive|define
name|_JB_MAGIC__SETJMP
value|0xBADFACED
end_define

begin_define
define|#
directive|define
name|_JB_MAGIC_SETJMP
value|0xFACEDBAD
end_define

begin_comment
comment|/* Valid for all jmp_buf's */
end_comment

begin_define
define|#
directive|define
name|_JB_MAGIC
value|0
end_define

begin_define
define|#
directive|define
name|_JB_REG_RA
value|1
end_define

begin_define
define|#
directive|define
name|_JB_REG_S0
value|2
end_define

begin_define
define|#
directive|define
name|_JB_REG_S1
value|3
end_define

begin_define
define|#
directive|define
name|_JB_REG_S2
value|4
end_define

begin_define
define|#
directive|define
name|_JB_REG_S3
value|5
end_define

begin_define
define|#
directive|define
name|_JB_REG_S4
value|6
end_define

begin_define
define|#
directive|define
name|_JB_REG_S5
value|7
end_define

begin_define
define|#
directive|define
name|_JB_REG_S6
value|8
end_define

begin_define
define|#
directive|define
name|_JB_REG_S7
value|9
end_define

begin_define
define|#
directive|define
name|_JB_REG_SP
value|10
end_define

begin_define
define|#
directive|define
name|_JB_REG_S8
value|11
end_define

begin_comment
comment|/* Only valid with the _JB_MAGIC_SETJMP magic */
end_comment

begin_define
define|#
directive|define
name|_JB_SIGMASK
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ASM_H_ */
end_comment

end_unit

